//
// rc5protocol.cpp
//
// Copyright 2012, 2013 by John Pietrzak (jpietrzak8@gmail.com)
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

#include "rc5protocol.h"

#include "pirinfraredled.h"

#include "pirexception.h"

#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

RC5Protocol::RC5Protocol(
  QObject *guiObject,
  unsigned int index,
  unsigned int sevenBitControl)
  : PIRProtocol(guiObject, index, 114000, true),
    biphaseUnit(889),
    buffer(0),
    keypressCount(0)
{
  setCarrierFrequency(36000);
  setPreData(sevenBitControl, 7);
}


RC5Protocol::RC5Protocol(
  QObject *guiObject,
  unsigned int index)
  : PIRProtocol(guiObject, index, 114000, true),
    biphaseUnit(889),
    buffer(0),
    keypressCount(0)
{
  setCarrierFrequency(36000);
}


void RC5Protocol::startSendingCommand(
  unsigned int threadableID,
  PIRKeyName command)
{
  // Dumping entire method inside of try/catch, to deal with cross-thread
  // exception handling:
  try
  {
    // Check if this command is meant for us:
    if (threadableID != id) return;

    clearRepeatFlag();

    KeycodeCollection::const_iterator i = keycodes.find(command);

    // Sanity check, make sure command exists first:
    if (i == keycodes.end())
    {
      QMutexLocker cifLocker(&commandIFMutex);
      commandInFlight = false;
      return;
//      std::string s = "Tried to send a non-existent command.\n";
//      throw PIRException(s);
    }

    // Construct the object that communicates with the device driver:
    PIRInfraredLED led(carrierFrequency, dutyCycle);

    int repeatCount = 0;
    int commandDuration = 0;
    while (repeatCount < MAX_REPEAT_COUNT)
    {
      // Now, throw together an RC5 protocol command string.

      if (!preData.empty())
      {
        // For standard RC5, the "pre-data" contains the control portion,
        // and the key contains only the 6-bit command portion.

        // First, construct the control portion:
        commandDuration += pushControlBits(led);

        // Next, the key-command portion:
        commandDuration += pushKeyCommandBits((*i).second, led);
      }
      else
      {
        // For non-standard RC5, the entire 13 bits are stuffed into the
        // key portion, as all of them can vary:
        commandDuration += pushNonStandardRC5((*i).second, led);
      }

      // Clear out the buffer, if necessary:
      if (buffer)
      {
        led.addSingle(buffer);
        commandDuration += buffer;

        // probably unnecessary cleanup of buffer:
        buffer = 0;
        bufferContainsSpace = false;
        bufferContainsPulse = false;
      }

      // Now, tell the device to send the whole command:
      led.sendCommandToDevice();

      // Sleep for an amount of time.
      sleepUntilRepeat(commandDuration);

      // Have we been told to stop yet?
      if (checkRepeatFlag())
      {
        break;
/*
        // Ok, then we can quit now:
        ++keypressCount;
        QMutexLocker cifLocker(&commandIFMutex);
        commandInFlight = false;
        return;
*/
      }

      ++repeatCount;
    }

    ++keypressCount;
    QMutexLocker cifLocker(&commandIFMutex);
    commandInFlight = false;
  }
  catch (PIRException e)
  {
    emit commandFailed(e.getError().c_str());
  }
}


int RC5Protocol::pushControlBits(
  PIRInfraredLED &led)
{
  int duration = 0;

  // Start off by pushing the lead pulse onto the buffer:
  buffer = biphaseUnit;
  bufferContainsPulse = true;
  bufferContainsSpace = false;

  CommandSequence::const_iterator i = preData.begin();

  // Push the first bit:
  if (i != preData.end())
  {
    duration += pushBit(*i, led);
    ++i;
  }

  // Toggle the second bit, if it is time to do so:
  if (i != preData.end())
  {
    if (keypressCount % 2)
    {
      duration += pushBit(!(*i), led);
    }
    else
    {
      duration += pushBit(*i, led);
    }

    ++i;
  }

  // Simply push the rest of the bits:
  while (i != preData.end())
  {
    duration += pushBit(*i, led);
    ++i;
  }

  return duration;
}


int RC5Protocol::pushKeyCommandBits(
  const PIRKeyBits &pkb,
  PIRInfraredLED &led)
{
  int duration = 0;

  // Just push all the bits:
  CommandSequence::const_iterator i = pkb.firstCode.begin();
  while (i != pkb.firstCode.end())
  {
    duration += pushBit(*i, led);
    ++i;
  }

  return duration;
}


int RC5Protocol::pushNonStandardRC5(
  const PIRKeyBits &pkb,
  PIRInfraredLED &led)
{
  int duration = 0;

  // Start off by pushing the lead pulse onto the buffer:
  buffer = biphaseUnit;
  bufferContainsPulse = true;
  bufferContainsSpace = false;

  CommandSequence::const_iterator i = pkb.firstCode.begin();

  // Push the first bit:
  if (i != pkb.firstCode.end())
  {
    duration += pushBit(*i, led);
    ++i;
  }

  // Toggle the second bit, if it is time to do so:
  if (i != pkb.firstCode.end())
  {
    if (keypressCount % 2)
    {
      duration += pushBit(!(*i), led);
    }
    else
    {
      duration += pushBit(*i, led);
    }

    ++i;
  }

  // Simply push the rest of the bits:
  while (i != pkb.firstCode.end())
  {
    duration += pushBit(*i, led);
    ++i;
  }

  return duration;
}


int RC5Protocol::pushBit(
  bool bitValue,
  PIRInfraredLED &led)
{
  unsigned int duration = 0;
  // RC5 encodes a "0" by using a pulse followed by a space,
  // and a "1" by using a space followed by a pulse.

  if (bitValue)
  {
    // We've got a "1".  First add a space, then a pulse.
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
  else
  {
    // We've got a "0".  First add a pulse, then a space.
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

  return duration;
}
