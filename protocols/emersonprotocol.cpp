//
// emersonprotocol.cpp
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

#include "emersonprotocol.h"

#include "pirinfraredled.h"

#include <QString>

// Some global communications stuff:
#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// The Emerson protocol is a fairly simple one, with the caveat that
// sometimes a single remote control can use multiple device codes.
// As such, I've added boolean to state whether multiple device codes
// have been defined for a given keyset.
// The basic properties are:
// A "zero" is encoded with a 870 usec pulse, 870 usec space.
// A "one" is encoded with a 870 usec pulse, and 3*870 (2610) usec space.
// The header is a 3480 usec pulse, 3480 usec space.
// Commands end with a trailing 870 usec pulse.
// When repeating, the entire command-train is re-sent;
// Each command runs for 104660 usec before another can be executed.
// The carrier frequency is apparently 36.7 kHz.

EmersonProtocol::EmersonProtocol(
  QObject *guiObject,
  unsigned int index,
  bool multiDevice)
  : SpaceProtocol(
      guiObject, index,
      870, 870,
      870, 2610,
      3480, 3480,
      870,
      110000, true),
    hasMultipleDevCodes(multiDevice)
{
}


void EmersonProtocol::startSendingCommand(
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
    // If there are multiple device codes, need to construct the
    // command slightly differently:
    if (hasMultipleDevCodes)
    {
      commandDuration = generateMultiDevCommand((*i).second, led);
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


int EmersonProtocol::generateStandardCommand(
  const PIRKeyBits &pkb,
  PIRInfraredLED &led)
{
  int duration = 0;

  // First, the "header" pulse:
  led.addPair(headerPulse, headerSpace);
  duration += (headerPulse + headerSpace);

  // In the Emerson protocol, the device and the command are both 6 bits.
  // The device and command are sent reversed, and then sent inverted.
  // - "preData" contains 6-bit device code.
  // - "pkb.firstCode" contains 6-bit command code.
  duration += pushReverseBits(preData, led);
  duration += pushReverseBits(pkb.firstCode, led);
  duration += pushInvertedReverseBits(preData, led);
  duration += pushInvertedReverseBits(pkb.firstCode, led);

  // Finally add the "trail":
  led.addSingle(trailerPulse);
  duration += trailerPulse;

  return duration;
}


int EmersonProtocol::generateMultiDevCommand(
  const PIRKeyBits &pkb,
  PIRInfraredLED &led)
{
  int duration = 0;

  // Start with the header:
  led.addPair(headerPulse, headerSpace);
  duration += (headerPulse + headerSpace);

  // In this version, since the device code varies, the pkb container is
  // used to contain both the device and command codes.
  // - "pkb.firstCode" contains 6-bit device code.
  // - "pkb.secondCode" contains 6-bit command code.
  duration += pushReverseBits(pkb.firstCode, led);
  duration += pushReverseBits(pkb.secondCode, led);
  duration += pushInvertedReverseBits(pkb.firstCode, led);
  duration += pushInvertedReverseBits(pkb.secondCode, led);

  // Add the trailer:
  led.addSingle(trailerPulse);
  duration += trailerPulse;

  return duration;
}
