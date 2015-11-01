//
// dishprotocol.cpp
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

#include "dishprotocol.h"

#include "pirinfraredled.h"

#include <QString>

// Some global communications stuff:
#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// Dish Network, or now just "Dish", has a unique protocol.  It uses "space"
// encoding, but otherwise is unlike just about anything else out there.
// Here's what I've got on it:
// A "zero" is encoded with a 400 usec pulse, 2800 usec space.
// A "one" is encoded with a 400 usec pulse, 1600 usec space.
// The header is a 400 usec pulse, 6000 usec space.
// Commands end with a trailing 400 usec pulse.
// Commands are repeated without the header (or, if you like, you can consider
// the trailing pulse to be the header for the next repetition).
// There is a 6000 usec gap between repetitions.
// The carrier frequency is apparently 57600 kHz, or thereabouts.
// The duty cycle is 1/3.

DishProtocol::DishProtocol(
  QObject *guiObject,
  unsigned int index)
  : SpaceProtocol(
      guiObject, index,
      400, 2800,
      400, 1600,
      400, 6000,
      400,
      6000, false)
{
  setCarrierFrequency(57600);
//  setDutyCycle(33);
}


void DishProtocol::startSendingCommand(
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
    // If this is not a repetition, we need to add the initial header:
    if (repeatCount == 0)
    {
      led.addPair(headerPulse, headerSpace);
      commandDuration += (headerPulse + headerSpace);
    }

    // generate the rest of the command:
    commandDuration += generateStandardCommand(i->second, led);

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


int DishProtocol::generateStandardCommand(
  const PIRKeyBits &pkb,
  PIRInfraredLED &led)
{
  int duration = 0;

  // In the Dish protocol, the pulse train consists of 6 bits of command
  // data followed by 10 bits of, uhm, other stuff.  I know that at least the
  // first four bits of these ten can be used for pairing purposes.  It looks
  // like the last five bits can be used as additional command data.  For
  // now, I'm going to split this into 5 "address" and 5 "more command" bits.
  //
  // The command data is sent MSB-first (I know that at least the first
  // 6 bits are, I'll represent the last 5 that way as well).
  // The pairing data is sent LSB-first, god knows why.
  // - "firstCode" should contain 6-bit value
  // - "preData" should contain 5 bits of pairing data
  // - "secondCode" should contain the last 5 bits.
  duration += pushBits(pkb.firstCode, led);
  duration += pushReverseBits(postData, led);
  duration += pushBits(pkb.secondCode, led);

  // Finally add the "trail":
  led.addSingle(trailerPulse);
  duration += trailerPulse;

  return duration;
}

