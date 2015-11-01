//
// sharpprotocol.cpp
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

#include "sharpprotocol.h"

#include "pirinfraredled.h"

#include <QString>

// Some global communications stuff:
#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// Sharp's protocol should have the following attributes:
// A "zero" is encoded with a 320 usec pulse, 680 usec space.
// A "one" is encoded with a 320 usec pulse, and 1680 usec space.
// There is no header pulse.
// The pulse train ends with a trailing 320 usec pulse.
// For repeating, the entire train is re-sent, except that the command
// section (and the last two bits) are inverted in each odd repeat.
// There is a 40000 usec delay between the end of one command and the start
// of the next.
// The command should be repeated at least once.
// The carrier frequency is 38 kHz, duty cycle is 1/3.

SharpProtocol::SharpProtocol(
  QObject *guiObject,
  unsigned int index,
  bool expBit)
  : SpaceProtocol(
      guiObject, index,
      320, 680,
      320, 1680,
      0, 0,
      320,
      40000, false),
    expansionBit(expBit)
{
  setCarrierFrequency(38000);
//  setDutyCycle(33);
}


void SharpProtocol::startSendingCommand(
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
    // Every other repeat count, we invert everything but the address:
    if (repeatCount % 2)
    {
      commandDuration = generateToggledCommand((*i).second, led);
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

    if (repeatCount >= 1)
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


int SharpProtocol::generateStandardCommand(
  const PIRKeyBits &pkb,
  PIRInfraredLED &led)
{
  int duration = 0;

  // First, push the address:
  duration += pushReverseBits(pkb.firstCode, led);

  // Next, push the command:
  duration += pushReverseBits(pkb.secondCode, led);

  // Next, there is an "expansion" bit and a "check" bit.  Not entirely sure
  // what these two do.  The check bit is fixed at "0".
  if (expansionBit)
  {
    led.addPair(onePulse, oneSpace);
    duration += (onePulse + oneSpace);
  }
  else
  {
    led.addPair(zeroPulse, zeroSpace);
    duration += (zeroPulse + zeroSpace);
  }

  led.addPair(zeroPulse, zeroSpace);
  duration += (zeroPulse + zeroSpace);

  // Finally add the "trail":
  led.addSingle(trailerPulse);
  duration += trailerPulse;

  return duration;
}


// This is the same as the standard command, except all bits but the address
// are inverted:
int SharpProtocol::generateToggledCommand(
  const PIRKeyBits &pkb,
  PIRInfraredLED &led)
{
  int duration = 0;

  pushReverseBits(pkb.firstCode, led);

  // This time we invert the command bits:
  pushInvertedReverseBits(pkb.secondCode, led);

  // We'll also invert the two administrative bits here:
  if (expansionBit)
  {
    led.addPair(zeroPulse, zeroSpace);
    duration += (zeroPulse + zeroSpace);
  }
  else
  {
    led.addPair(onePulse, oneSpace);
    duration += (onePulse + oneSpace);
  }

  led.addPair(onePulse, oneSpace);
  duration += (onePulse + oneSpace);

  // Add trail on end:
  led.addSingle(trailerPulse);
  duration += trailerPulse;

  return duration;
}
