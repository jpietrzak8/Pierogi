//
// airtechprotocol.cpp
//
// Copyright 2014 - 2015 by John Pietrzak (jpietrzak8@gmail.com)
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
// along with Pierogi; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//

#include "airtechprotocol.h"

#include "pirinfraredled.h"

#include <QString>

// Some global communications stuff:
#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// This protocol is one that to-date I've only seen on an Airtech fan.  It
// appears to be fairly simple.
// A "zero" is encoded with a 422 usec pulse, 1270 usec space.
// A "one" is encoded with a 1270 usec pulse, 422 usec space.
// There is no header.
// There is no trailer.
// When repeating, entire command train is re-sent.
// Each command runs for 26440 usec.
// The carrier frequency is 38 kHz.

AirtechProtocol::AirtechProtocol(
  QObject *guiObject,
  unsigned int index)
  : SpaceProtocol(
      guiObject, index,
      422, 1270,
      1270, 422,
      0, 0,
      0,
      26440, true)
{
}


void AirtechProtocol::startSendingCommand(
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
    commandDuration = generateCommand((*i).second, led);

    // Now, tell the device to send the whole command:
    if (!led.sendCommandToDevice())
    {
      // Something didn't work right, get out:
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


int AirtechProtocol::generateCommand(
  const PIRKeyBits &pkb,
  PIRInfraredLED &led)
{
  int duration = 0;

  // In the Airtech protocol, we have seven bits of device data, and five
  // bits of command data.  They are simply sent together in MSB format.
  duration += pushBits(preData, led);
  duration += pushBits(pkb.firstCode, led);

  return duration;
}
