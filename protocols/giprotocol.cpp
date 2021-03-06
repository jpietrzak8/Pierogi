//
// giprotocol.cpp
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

#include "giprotocol.h"

#include "pirinfraredled.h"

#include <QString>

// Some global communications stuff:
#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// This G.I./Motorola protocol appears to have the following specifications:
// A "zero" is encoded with a 500 usec pulse, 2250 usec space.
// A "one" is encoded with a 500 usec pulse, and 4500 usec space.
// The header is a 9000 usec pulse, 4500 usec space.
// Commands end with a trailing 500 usec pulse.
// A repeat block is a 9000 usec pulse, 2250 usec space, then a trailing pulse.
// Each command runs for 100000 usec before another can be executed.
// The carrier frequency is 38 kHz.

GIProtocol::GIProtocol(
  QObject *guiObject,
  unsigned int index)
  : SpaceProtocol(
      guiObject, index,
      500, 2250,
      500, 4500,
      9000, 4500,
      500,
      100000, true),
    repeatPulse(9000),
    repeatSpace(2250)
{
}


void GIProtocol::startSendingCommand(
  unsigned int threadableID,
  PIRKeyName command)
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
    emit errorMessage("Key not defined in this keyset.");
    return;
  }

  // construct the device:
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
    // If we are currently repeating, send a repeat block.
    if (repeatCount)
    {
      commandDuration = generateRepeatCommand(led);
    }
    else
    {
      commandDuration = generateStandardCommand((*i).second, led);
    }

    // Now, tell the device to send the whole command:
    if (!led.sendCommandToDevice())
    {
      break;
    }

    // sleep until the next repetition of command:
    sleepUntilRepeat(commandDuration);

    // Check whether we've reached the minimum required number of repetitons:
    if (repeatCount >= minimumRepetitions)
    {
      // Check whether we've been asked to stop:
      if (checkRepeatFlag())
      {
        break;
      }
    }

    ++repeatCount;
  }

  QMutexLocker cifLocker(&commandIFMutex);
  commandInFlight = false;
}


int GIProtocol::generateStandardCommand(
  const PIRKeyBits &pkb,
  PIRInfraredLED &led)
{
  int duration = 0;

  // First, the "header" pulse:
  led.addPair(headerPulse, headerSpace);
  duration += (headerPulse + headerSpace);

  // The GI protocol consists of a 4-bit device code and an 8-bit command.
  // These are sent in reverse order.  Finally, a checksum is added at the
  // end.  I am lacking enough information to calculate the checksum right
  // now, so I'm going to dump all 16 bits into the "firstCode" in MSB
  // order, and reverse them here:

  duration += pushReverseBits(pkb.firstCode, led);

  // Finally add the "trail":
  led.addSingle(trailerPulse);
  duration += trailerPulse;

  return duration;
}


int GIProtocol::generateRepeatCommand(
  PIRInfraredLED &led)
{
  int duration = 0;

  // Add the repeat pulse:
  led.addPair(repeatPulse, repeatSpace);
  duration += (repeatPulse + repeatSpace);

  // Add the trailer:
  led.addSingle(trailerPulse);
  duration += trailerPulse;

  return duration;
}

