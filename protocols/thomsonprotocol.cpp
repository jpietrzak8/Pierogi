//
// thomsonprotocol.cpp
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

#include "thomsonprotocol.h"

#include "pirinfraredled.h"

#include <QString>

// Some global communications stuff:
#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// This Thomson protocol is a very simple one:
// A "zero" is encoded with a 500 usec pulse, 2000 usec space.
// A "one" is encoded with a 500 usec pulse, and 4500 usec space.
// There is no header.
// Commands end with a trailing 500 usec pulse.
// When repeating, the full pulse train is re-sent.
// Each command runs for 80000 usec total.
// The carrier frequency should be 33 kHz, but I'm not so sure...

ThomsonProtocol::ThomsonProtocol(
  QObject *guiObject,
  unsigned int index)
  : SpaceProtocol(
      guiObject, index,
      500, 2000,
      500, 4500,
      0, 0,
      500,
      80000, true),
    keypressCount(0)
{
}


void ThomsonProtocol::startSendingCommand(
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
    commandDuration = generateStandardCommand((*i).second, led);

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

  ++keypressCount;
  QMutexLocker cifLocker(&commandIFMutex);
  commandInFlight = false;
}


int ThomsonProtocol::generateStandardCommand(
  const PIRKeyBits &pkb,
  PIRInfraredLED &led)
{
  int duration = 0;

  // First, four bits of address:
  duration += pushBits(preData, led);

  // Next, the toggle bit:
  if (keypressCount % 2)
  {
    led.addPair(onePulse, oneSpace);
    duration += (onePulse + oneSpace);
  }
  else
  {
    led.addPair(zeroPulse, zeroSpace);
    duration += (zeroPulse + zeroSpace);
  }

  // Next, seven bits of command:
  duration += pushBits(pkb.firstCode, led);

  // Finally add the "trail":
  led.addSingle(trailerPulse);
  duration += trailerPulse;

  return duration;
}
