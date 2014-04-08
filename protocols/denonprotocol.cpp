//
// denonprotocol.cpp
//
// Copyright 2014 by John Pietrzak (jpietrzak8@gmail.com)
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

#include "denonprotocol.h"

#include "pirinfraredled.h"

#include "pirexception.h"

// Some global communications stuff:
#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// I've pieced together this info for the Denon protocol:
// A zero lasts 1 msec (320 usec pulse, 1000-320 (680) usec space).
// A one lasts 2 msec (320 usec pulse, 2000-320 (1680) usec space).
// There is no header.
// Commands end with a trailing 320 usec pulse.
// Repeat blocks are formed by re-sending the entire command, but inverting
// the control portion of the command on each even-numbered block.
// There is a 40 msec (40000 usec) space between commands.
// The carrier frequency is 38 KHz.
// Data is sent LSB first.


DenonProtocol::DenonProtocol(
  QObject *guiObject,
  unsigned int index)
  : SpaceProtocol(
      guiObject, index,
      320, 680,
      320, 1680,
      0, 0,
      320,
      40000, false)
{
}


void DenonProtocol::startSendingCommand(
  unsigned int threadableID,
  PIRKeyName command)
{
  // Exceptions here are problematic; I'll try to weed them out by putting the
  // whole thing in a try/catch block:
  try
  {
    // First, check if we are meant to be the recipient of this command:
    if (threadableID != id) return;

    clearRepeatFlag();

    KeycodeCollection::const_iterator i = keycodes.find(command);

    // Do we even have this key defined?
    if (i == keycodes.end())
    {
      QMutexLocker cifLocker(&commandIFMutex);
      commandInFlight = false;
      return;
//      std::string s = "Tried to send a non-existent command.\n";
//      throw PIRException(s);
    }

    // construct the device:
    PIRInfraredLED led(carrierFrequency, dutyCycle);

    int repeatCount = 0;
    int commandDuration = 0;
    while (repeatCount < MAX_REPEAT_COUNT)
    {
      // If the repeat count is an even number, generate a normal block.
      // Otherwise, generate a repeat block.
      if (repeatCount % 2)
      {
        commandDuration = generateCommand((*i).second, led);
      }
      else
      {
        commandDuration = generateRepeatCommand((*i).second, led);
      }

      // Now, tell the device to send the whole command:
      led.sendCommandToDevice();

      // sleep until the next repetition of command:
      sleepUntilRepeat(commandDuration);

      // Check whether we've reached the minimum required number of repetitons:
      if (repeatCount >= minimumRepetitions)
      {
        // Check whether we've been asked to stop:
        if (checkRepeatFlag())
        {
          break;
/*
          QMutexLocker cifLocker(&commandIFMutex);
          commandInFlight = false;
          return;
*/
        }
      }

      ++repeatCount;
    }

    QMutexLocker cifLocker(&commandIFMutex);
    commandInFlight = false;
  }
  catch (PIRException e)
  {
    // inform the gui:
    emit commandFailed(e.getError().c_str());
  }
}


int DenonProtocol::generateCommand(
  const PIRKeyBits &pkb,
  PIRInfraredLED &led)
{
  int duration = 0;

  // The address should be 5 bits long, and the control data 8 bits.
  // Both are sent in LSB order.
  duration += pushReverseBits(pkb.firstCode, led);
  duration += pushReverseBits(pkb.secondCode, led);

  // Next, two Zero bits are sent:
  led.addPair(zeroPulse, zeroSpace);
  duration += zeroPulse + zeroSpace;

  led.addPair(zeroPulse, zeroSpace);
  duration += zeroPulse + zeroSpace;

  // Finally add the "trail":
  led.addSingle(trailerPulse);
  duration += trailerPulse;

  return duration;
}


int DenonProtocol::generateRepeatCommand(
  const PIRKeyBits &pkb,
  PIRInfraredLED &led)
{
  int duration = 0;

  // The address should be 5 bits long, and the control data 8 bits.
  // For the repeat, the control data is inverted.
  // Both are sent in LSB order.
  duration += pushReverseBits(pkb.firstCode, led);
  duration += pushInvertedReverseBits(pkb.secondCode, led);

  // Next, two One bits are sent (the inverse of the normal command):
  led.addPair(onePulse, oneSpace);
  duration += onePulse + oneSpace;

  led.addPair(onePulse, oneSpace);
  duration += onePulse + oneSpace;

  // Finally add the "trail":
  led.addSingle(trailerPulse);
  duration += trailerPulse;

  return duration;
}
