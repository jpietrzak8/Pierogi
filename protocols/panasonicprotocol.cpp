//
// panasonic.cpp
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

#include "panasonicprotocol.h"

#include "pirinfraredled.h"

#include <QString>

// Some global communications stuff:
#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// This Panasonic protocol is closely related to the Kaseikyo protocol, but
// has a few subtle differences.  Here is the overall structure of each
// command train:
// A "zero" is encoded with a 432 usec pulse, 432 usec space.
// A "one" is encoded with a 432 usec pulse, and 3*432 (1296) usec space.
// The header has a 3456 usec pulse, and a 1728 usec space.
// Commands end with a trailing 432 usec pulse.
// When repeating, the entire pulse train is re-sent.
// There is a 74736 usec gap between repeated commands.
// The carrier frequency is 37 kHz.

PanasonicProtocol::PanasonicProtocol(
  QObject *guiObject,
  unsigned int index)
  : SpaceProtocol(
      guiObject, index,
      432, 432,
      432, 1296,
      3456, 1728,
      432,
      74736, false)
{
  setCarrierFrequency(37000);
}


void PanasonicProtocol::startSendingCommand(
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

  QMutexLocker cifLocker(&commandIFMutex);
  commandInFlight = false;
}


int PanasonicProtocol::generateStandardCommand(
  const PIRKeyBits &pkb,
  PIRInfraredLED &led)
{
  int duration = 0;

  // First, the header pulse:
  led.addPair(headerPulse, headerSpace);
  duration += (headerPulse + headerSpace);

  // Similar to the "Kaseikyo" protocol, this protocol is 48 bits long.
  // In this case, the first 16 bits are a fixed value (defining the
  // manufacturer?).  Next comes eight bits for the "device", eight more
  // bits for the "subdevice", and then eight bits for the "command".
  // Finally, the last eight bits are a checksum generated by x-oring the
  // device, subdevice, and command bytes.

  // The 16 manufacturer code bits:
  duration += pushReverseBits(preData, led);

  // The eight device bits:
  duration += pushReverseBits(pkb.firstCode, led);

  // The eight subdevice bits:
  duration += pushReverseBits(pkb.secondCode, led);

  // The eight command bits:
  duration += pushReverseBits(pkb.thirdCode, led);

  // Finally, the checksum:
  CommandSequence checksum;
  generateChecksum(pkb.firstCode, pkb.secondCode, pkb.thirdCode, checksum);
  duration += pushReverseBits(checksum, led);

  // Add the trailer pulse:
  led.addSingle(trailerPulse);
  duration += trailerPulse;

  return duration;
}


void PanasonicProtocol::generateChecksum(
  const CommandSequence &device,
  const CommandSequence &subdevice,
  const CommandSequence &command,
  CommandSequence &checksum)
{
  checksum.clear(); // probably unnecessary sanity check.

  CommandSequence::const_iterator diter = device.begin();
  CommandSequence::const_iterator siter = subdevice.begin();
  CommandSequence::const_iterator citer = command.begin();

  while (diter !=device.end()
      && siter != subdevice.end()
      && citer != command.end())
  {
    checksum.push_back(*diter ^ *siter ^ *citer);
    ++diter;
    ++siter;
    ++citer;
  }
}
