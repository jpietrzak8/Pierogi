//
// nokia32protocol.cpp
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

#include "nokia32protocol.h"

#include "pirinfraredled.h"

#include <QString>

// Some global communications stuff:
#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// The Nokia 32 protocol has a 2-bit space encoding system, and appears to
// work like this:
// A "zero" is encoded with a 164 usec pulse, 276 usec space.
// A "one" is encoded with a 164 usec pulse, 445 usec space.
// A "two" is encoded with a 164 usec pulse, 614 usec space.
// A "three" is encoded with a 164 usec pulse, 783 usec space.
// The header is a 412 usec pulse, 276 usec space.
// Commands end with a trailing 164 usec pulse.
// The entire pulse train is re-sent when repeating.
// There is a 100000 usec gap between commands. (? not sure here)
// The carrier frequency is presumably 36 kHz.
// The duty cycle is presumably 1/3.

Nokia32Protocol::Nokia32Protocol(
  QObject *guiObject,
  unsigned int index)
  : PIRProtocol(guiObject, index, 100000, false),
    zeroPulse(164),
    zeroSpace(276),
    onePulse(164),
    oneSpace(445),
    twoPulse(164),
    twoSpace(614),
    threePulse(164),
    threeSpace(783),
    headerPulse(412),
    headerSpace(276),
    trailerPulse(164),
    keypressCount(0)
{
}


void Nokia32Protocol::startSendingCommand(
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


int Nokia32Protocol::generateStandardCommand(
  const PIRKeyBits &pkb,
  PIRInfraredLED &led)
{
  int duration = 0;

  // First, the "header" pulse:
  led.addPair(headerPulse, headerSpace);
  duration += (headerPulse + headerSpace);

  // The layout of the Nokia 32 protocol is as follows:
  // 1) an 8-bit "device code"
  // 2) an 8-bit "sub-device code"
  // 3) one toggle bit
  // 4) seven more bits somehow associated with the device
  // 5) an 8-bit command code.
  // All are sent in MSB order.

  // It's a bit of a hack, but I'll store the first 16 bits of address in the
  // preData, the next 7 bits of address in the postData, and the 8 bits
  // of command in the firstCode:

  duration += pushBits(preData, led);
  duration += pushToggleAndBits(postData, led);
  duration += pushBits(pkb.firstCode, led);

  // Finally add the "trail":
  led.addSingle(trailerPulse);
  duration += trailerPulse;

  return duration;
}


int Nokia32Protocol::pushBits(
  const CommandSequence &bits,
  PIRInfraredLED &led)
{
  int duration = 0;
  bool firstBit;
  bool secondBit;

  CommandSequence::const_iterator i = bits.begin();
  while (i != bits.end())
  {
    firstBit = *i;
    ++i;
    if (i == bits.end()) break;
    secondBit = *i;

    duration += pushDoubleBit(firstBit, secondBit, led);

    ++i;
  }

  return duration;
}


int Nokia32Protocol::pushToggleAndBits(
  const CommandSequence &bits,
  PIRInfraredLED &led)
{
  int duration = 0;
  bool firstBit;
  bool secondBit;

  // The first bit is the toggle bit:
  if (keypressCount % 2)
  {
    firstBit = 1;
  }
  else
  {
    firstBit = 0;
  }

  CommandSequence::const_iterator i = bits.begin();
  if (i == bits.end()) return 0;

  secondBit = *i;

  duration += pushDoubleBit(firstBit, secondBit, led);

  ++i;

  while (i != bits.end())
  {
    firstBit = *i;
    ++i;
    if (i == bits.end()) break;
    secondBit = *i;

    duration += pushDoubleBit(firstBit, secondBit, led);

    ++i;
  }

  return duration;
}


int Nokia32Protocol::pushDoubleBit(
  bool firstBit,
  bool secondBit,
  PIRInfraredLED &led)
{
  int duration = 0;

  if (firstBit == 0)
  {
    if (secondBit == 0)
    {
      // Send the pulse for "Zero":
      led.addPair(zeroPulse, zeroSpace);
      duration += (zeroPulse + zeroSpace);
    }
    else
    {
      // Send the pulse for "One":
      led.addPair(onePulse, oneSpace);
      duration += (onePulse + oneSpace);
    }
  }
  else
  {
    if (secondBit == 0)
    {
      // Send the pulse for "Two":
      led.addPair(twoPulse, twoSpace);
      duration += (twoPulse + twoSpace);
    }
    else
    {
      // Send the pulse for "Three":
      led.addPair(threePulse, threeSpace);
      duration += (threePulse + threeSpace);
    }
  }

  return duration;
}
