//
// sircprotocol.cpp
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

#include "sircprotocol.h"

#include "pirinfraredled.h"

#include <QString>

// Some global communications stuff:
#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// The SIRC protocol should have the following attributes:
// A "zero" is encoded with a 600 usec pulse, 600 usec space.
// A "one" is encoded with a 1200 usec pulse, and 600 usec space.
// The header is a 2400 usec pulse, 600 usec space.
// There is no trailing pulse.
// When repeating a command, the entire train is re-broadcast every 45000 usec.
// The carrier frequency is 40 kHz, duty cycle is 1/3.

SIRCProtocol::SIRCProtocol(
  QObject *guiObject,
  unsigned int index)
  : SpaceProtocol(
      guiObject, index,
      600, 600,
      1200, 600,
      2400, 600,
      0,
      45000, true)
{
  setCarrierFrequency(40000);
//  setDutyCycle(33);
}


void SIRCProtocol::startSendingCommand(
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
    if (repeatCount >= 3)
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


int SIRCProtocol::generateStandardCommand(
  const PIRKeyBits &pkb,
  PIRInfraredLED &led)
{
  int duration = 0;

  // First, the "header" pulse:
  led.addPair(headerPulse, headerSpace);
  duration += (headerPulse + headerSpace);

  // Next, push the data.
  // These bits are sent in reverse order, and moreover, the codes are sent
  // in reverse order as well:
  duration += pushReverseBits(pkb.thirdCode, led);
  duration += pushReverseBits(pkb.secondCode, led);
  duration += pushReverseBits(pkb.firstCode, led);

  return duration;
}
