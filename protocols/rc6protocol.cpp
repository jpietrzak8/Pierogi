//
// rc6protocol.cpp
//
// Copyright 2012 - 2015 by John Pietrzak (jpietrzak8@gmail.com)
//
// This file is part of Pierogi.
//
// Pierogi is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// Pierogi is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//

#include "rc6protocol.h"

#include "pirinfraredled.h"

#include <QString>

#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// These defines might need to be turned into variables, for odd devices.
#define HEADER_PULSE 2666
#define HEADER_SPACE 889
#define TRAILER_PULSE 889
#define TRAILER_SPACE 889

// I'm requiring standard RC6 initialization to include the 8-bit control
// section:
RC6Protocol::RC6Protocol(
  QObject *guiObject,
  unsigned int index,
  unsigned int eightBitControl)
  : PIRProtocol(guiObject, index, 108000, true),
    biphaseUnit(444),
    buffer(0),
    keypressCount(0)
{
  setCarrierFrequency(36000);
  setPreData(eightBitControl, 8);
}


void RC6Protocol::startSendingCommand(
  unsigned int threadableID,
  PIRKeyName command)
{
  // Is this command meant for us?
  if (threadableID != id) return;

  clearRepeatFlag();

  KeycodeCollection::const_iterator i = keycodes.find(command);

  // Sanity check:
  if (i == keycodes.end())
  {
    QMutexLocker cifLocker(&commandIFMutex);
    commandInFlight = false;
    emit errorMessage("Key not defined in this keyset.");
    return;
  }

  PIRInfraredLED led(carrierFrequency, dutyCycle);

  connect(
    &led,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  int repeatCount = 0;
  int duration = 0;
  while (repeatCount < MAX_REPEAT_COUNT)
  {
    // First, construct the "Header" segment of the pulse train.  For now,
    // I'm only supporting the "consumer electronics mode" of RC6; this code
    // must be changed if we want to support more than that!
    //
    // The header involves:
    // a) a "lead" of 2666 us pulse, 889 us space;
    // b) a "start bit", value 1 (so 444 us pulse, 444 us space)
    // c) three control bits, always set to 0 (so 444 us space,
    //    444 us pulse each)
    // d) the double-sized "trailer" bit, toggled on each keypress (so
    //    either 889 pulse 889 space, or 889 space 889 pulse)

    led.addSingle(HEADER_PULSE); // lead pulse
    duration += HEADER_PULSE;
    led.addSingle(HEADER_SPACE); // lead space
    duration += HEADER_SPACE;
    led.addSingle(biphaseUnit); // start bit pulse
    duration += biphaseUnit;

    // start bit space + control bit 1 space:
    led.addSingle(2 * biphaseUnit);
    duration += 2 * biphaseUnit;
    led.addSingle(biphaseUnit); // bit 1 pulse;
    duration += biphaseUnit;
    led.addSingle(biphaseUnit); // bit 2 space;
    duration += biphaseUnit;
    led.addSingle(biphaseUnit); // bit 2 pulse;
    duration += biphaseUnit;
    led.addSingle(biphaseUnit); // bit 3 space;
    duration += biphaseUnit;

    // Next, need to check whether we should toggle or not:
    if (keypressCount % 2)
    {
      // bit 3 pulse plus long trailer bit pulse:
      led.addSingle(3 * biphaseUnit);
      duration += 3 * biphaseUnit;

      // load the trailer bit space onto the buffer:
      buffer = 2 * biphaseUnit;
      bufferContainsSpace = true;
      bufferContainsPulse = false;
    }
    else
    {
      led.addSingle(biphaseUnit); // bit three pulse
      duration += biphaseUnit;
      led.addSingle(2 * biphaseUnit); // trailer bit space
      duration += 2 * biphaseUnit;

      // load the trailer bit pulse onto the buffer:
      buffer = 2 * biphaseUnit;
      bufferContainsPulse = true;
      bufferContainsSpace = false;
    }

    // Now, we can start the normal buffering process:

    // push any pre-data onto the device:
    duration += pushBits(preData, led);

    // push the actual command:
    duration += pushBits((*i).second.firstCode, led);

    // Flush out the buffer, if necessary:
    if (buffer)
    {
      led.addSingle(buffer);
      duration += buffer;
      buffer = 0;
    }

    // Actually send out the command:
    if (!led.sendCommandToDevice())
    {
      break;
    }

    // Sleep for an amount of time.  (RC6 demands an addtional 6 unit space
    // at the end of any command...)
    sleepUntilRepeat(duration + 6 * biphaseUnit);

    // Have we been told to stop yet?
    if (checkRepeatFlag())
    {
      break;
    }
  }

  ++keypressCount;
  QMutexLocker cifLocker(&commandIFMutex);
  commandInFlight = false;
}


int RC6Protocol::pushBits(
  const CommandSequence &bits,
  PIRInfraredLED &led)
{
  int bitsDuration = 0;

  CommandSequence::const_iterator i = bits.begin();
  bool bitValue;

  while (i != bits.end())
  {
    bitValue = *i;

    // In RC6, a "0" is represented by a space followed by a pulse,
    // and a "1" is represented by a pulse followed by a space.
    if (bitValue)
    {
      // This is a 1, so add a pulse, then a space.
      // First, the pulse:
      if (bufferContainsPulse)
      {
        led.addSingle(buffer + biphaseUnit);
        bitsDuration += (buffer + biphaseUnit);
        buffer = 0;
        bufferContainsPulse = false;
      }
      else
      {
        if (bufferContainsSpace)
        {
          // Flush the buffer:
          led.addSingle(buffer);
          bitsDuration += buffer;
          buffer = 0;
          bufferContainsSpace = false;
        }
        // Now, add the pulse:
        led.addSingle(biphaseUnit);
        bitsDuration += biphaseUnit;
      }

      // Next, push a space onto the buffer:
      buffer = biphaseUnit;
      bufferContainsSpace = true;
    }
    else
    {
      // This is a 0, so add a space, then a pulse.
      if (bufferContainsSpace)
      {
        // Merge this space and the previous one, and send to device:
        led.addSingle(buffer + biphaseUnit);
        bitsDuration += (buffer + biphaseUnit);
        buffer = 0;
        bufferContainsSpace = false;
      }
      else
      {
        if (bufferContainsPulse)
        {
          // Flush out the buffer:
          led.addSingle(buffer);
          bitsDuration += buffer;
          buffer = 0;
          bufferContainsPulse = false;
        }

        // push a space onto the device:
        led.addSingle(biphaseUnit);
        bitsDuration += biphaseUnit;
      }

      // Put a pulse into the buffer to wait:
      buffer = biphaseUnit;
      bufferContainsPulse = true;
    }

    ++i;
  }

  return bitsDuration;
}
