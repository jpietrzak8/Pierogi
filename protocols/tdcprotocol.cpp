//
// tdcprotocol.cpp
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

#include "tdcprotocol.h"

#include "pirinfraredled.h"

#include <QString>

#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;


// There are apparently two forms of TDC protocol; I'm just focussing on one
// for now.  As with the Philips protocols, this one is "shift encoded".
// The unit biphase pulse length is 315 usec; each command contains 18 bits,
// and is followed by an 89000 usec space.  The entire pulse train is
// re-sent when repeating.  The carrier frequency is 38 kHz (the Pierogi
// default value).

// I'm going to count both the "device" and "subdevice" bits as pre-data.
// (Both are 5 bits in length.)  This may need to be changed...

TDCProtocol::TDCProtocol(
  QObject *guiObject,
  unsigned int index,
  unsigned int deviceBits,
  unsigned int subdeviceBits)
  : PIRProtocol(guiObject, index, 89000, false),
    biphaseUnit(315),
    buffer(0)
{
  // Bit of a hack to get the device and subdevice data in:
  setPreData(deviceBits, 5);
  setPostData(subdeviceBits, 5);
}


void TDCProtocol::startSendingCommand(
  unsigned int threadableID,
  PIRKeyName command)
{
  // Check that this command is meant for us:
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

  // Construct the object that communicates with the device driver:
  PIRInfraredLED led(carrierFrequency, dutyCycle);

  connect(
    &led,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  int repeatCount = 0;
  int commandDuration = 0;
  while (repeatCount < MAX_REPEAT_COUNT)
  {
    // Construct the actual command string.
    // The string always starts with a constant "1" bit:
    commandDuration += pushBit(true, led);

    // Next, the device bits:
    commandDuration += pushBits(preData, led);

    // Then, the subdevice bits:
    commandDuration += pushBits(postData, led);

    // Finally, the command bits:
    commandDuration += pushBits((*i).second.firstCode, led);

    // Clear out the buffer, if needed:
    if (buffer)
    {
      led.addSingle(buffer);
      commandDuration += buffer;

      buffer = 0;
      bufferContainsSpace = false;
      bufferContainsPulse = false;
    }

    // Send the command:
    if (!led.sendCommandToDevice())
    {
      break;
    }

    // Sleep for the required amount of time.
    sleepUntilRepeat(commandDuration);

    // Check whether we've been told to stop:
    if (checkRepeatFlag())
    {
      // We shall stop:
      break;
    }

    ++repeatCount;
  }

  QMutexLocker cifLocker(&commandIFMutex);
  commandInFlight = false;
}


int TDCProtocol::pushBits(
  const CommandSequence &bits,
  PIRInfraredLED &led)
{
  int duration = 0;

  CommandSequence::const_iterator i = bits.begin();

  while (i != bits.end())
  {
    duration += pushBit(*i, led);
    ++i;
  }

  return duration;
}


int TDCProtocol::pushBit(
  bool bitValue,
  PIRInfraredLED &led)
{
  unsigned int duration = 0;
  // TDC encodes a "0" by using a space followed by a pulse,
  // and a "1" by using a pulse followed by a space.

  if (bitValue)
  {
    // We've got a "1".  First add a pulse, then a space.
    if (bufferContainsPulse)
    {
      // Merge our pulse with the previous one, and send them to the device:
      led.addSingle(buffer + biphaseUnit);
      duration += (buffer + biphaseUnit);
      buffer = 0;
      bufferContainsPulse = false;
    }
    else
    {
      if (bufferContainsSpace)
      {
        // Flush out the buffer:
        led.addSingle(buffer);
        duration += buffer;
        buffer = 0;
        bufferContainsSpace = false;
      }

      // Add a pulse:
      led.addSingle(biphaseUnit);
      duration += biphaseUnit;
    }

    // Put a space into the buffer to wait:
    buffer = biphaseUnit;
    bufferContainsSpace = true;
  }
  else
  {
    // We've got a "0".  First add a space, then a pulse.
    if (bufferContainsSpace)
    {
      // Merge our space with the previous space, and send them to
      // the device.
      led.addSingle(buffer + biphaseUnit);
      duration += (buffer + biphaseUnit);
      buffer = 0;
      bufferContainsSpace = false;
    }
    else
    {
      if (bufferContainsPulse)
      {
        // Flush the buffer:
        led.addSingle(buffer);
        duration += buffer;
        buffer = 0;
        bufferContainsPulse = false;
      }
      // Add a space:
      led.addSingle(biphaseUnit);
      duration += biphaseUnit;
    }

    // Put a pulse into the buffer to wait.
    buffer = biphaseUnit;
    bufferContainsPulse = true;
  }

  return duration;
}
