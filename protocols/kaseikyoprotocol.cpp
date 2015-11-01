//
// kaseikyoprotocol.cpp
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

#include "kaseikyoprotocol.h"

#include "pirinfraredled.h"

#include <QString>

// Some global communications stuff:
#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// Getting good data on the Kaseikyo protocol(s) is difficult.  The following
// is my current understanding:
// A "zero" is encoded with a 432 usec pulse, 432 usec space.
// A "one" is encoded with a 432 usec pulse, and 3*432 (1296) usec space.
// The header has a 3456 usec pulse, and a 1728 usec space.
// Commands end with a trailing 432 usec pulse.
// When repeating, the entire pulse train is re-sent.
// There is a 74736 usec gap between repeated commands.
// The carrier frequency is 37 kHz.

KaseikyoProtocol::KaseikyoProtocol(
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


void KaseikyoProtocol::startSendingCommand(
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


int KaseikyoProtocol::generateStandardCommand(
  const PIRKeyBits &pkb,
  PIRInfraredLED &led)
{
  int duration = 0;

  // First, the header pulse:
  led.addPair(headerPulse, headerSpace);
  duration += (headerPulse + headerSpace);

  // While I don't yet fully understand the contents of the protocol, the
  // data is obviously split into a first half (supposedly containing
  // manufacturer ID codes) and a second half (containing address and command
  // data).  The first half is 16 bits long plus a 4 bit checksum, and the
  // second half is 24 bits long plus a 4 bit checksum.  Of that second half,
  // the first 12 bits are probably the address, and the last 12 bits are split
  // into 8 bits of command followed by 4 bits that turn out to be the last
  // four bits of the command xored with the middle 4 bits of the address.
  // (At least for Panasonic.)  Very strange.
  // For now, I'm going with this game plan:
  // -- The "preData" will contain the 16 bits of manufacturer data as a
  // single value.
  // -- The "firstCode" will contain the 12 address bits.
  // -- The "secondCode" will contain the 8 command bits.
  // -- I'll generate the three checksums below.

  CommandSequence checksum;

  // The "manufacturer codes":
  duration += pushReverseBits(preData, led);

  generateChecksum(preData, checksum);
  duration += pushReverseBits(checksum, led);

  // The command portion:
  // First, the address and command:
  duration += pushReverseBits(pkb.firstCode, led);
  duration += pushReverseBits(pkb.secondCode, led);

  // Next, the odd little checksum:
  CommandSequence littleChecksum;
  generateLittleChecksum(pkb.firstCode, pkb.secondCode, littleChecksum);
  duration += pushReverseBits(littleChecksum, led);
  
  // Finally, the last checksum:
  checksum.clear();
  generateChecksum(pkb.firstCode, checksum);
  generateChecksum(pkb.secondCode, checksum);
  generateChecksum(littleChecksum, checksum);
  duration += pushReverseBits(checksum, led);

  // Add the trailer pulse:
  led.addSingle(trailerPulse);
  duration += trailerPulse;

  return duration;
}


void KaseikyoProtocol::generateChecksum(
  const CommandSequence &bits,
  CommandSequence &checksum)
{
  bool bit1;
  bool bit2;
  bool bit3;
  bool bit4;

  CommandSequence::const_iterator i = bits.begin();

  // Set up the first four bits:
  if (i == bits.end()) return; // this shouldn't happen...
  bit1 = *i;
  ++i;

  if (i == bits.end()) return;
  bit2 = *i;
  ++i;

  if (i == bits.end()) return;
  bit3 = *i;
  ++i;

  if (i == bits.end()) return;
  bit4 = *i;
  ++i;

  while (i != bits.end())
  {
    bit1 = bit1 ^ *i;
    ++i;  

    if (i != bits.end())
    {
      bit2 = bit2 ^ *i;
      ++i;

      if (i != bits.end())
      {
        bit3 = bit3 ^ *i;
        ++i;

        if (i != bits.end())
        {
          bit4 = bit4 ^ *i;
          ++i;
        }
      }
    }
  }

  // Now, either insert these bits into the checksum, or xor them with the
  // bits already in the checksum.
  if (checksum.empty())
  {
    checksum.push_back(bit1);
    checksum.push_back(bit2);
    checksum.push_back(bit3);
    checksum.push_back(bit4);
  }
  else
  {
    CommandSequence::iterator j = checksum.begin();
    if (j != checksum.end())
    {
      *j = *j ^ bit1;
      ++j;
    }

    if (j != checksum.end())
    {
      *j = *j ^ bit2;
      ++j;
    }

    if (j != checksum.end())
    {
      *j = *j ^ bit3;
      ++j;
    }

    if (j != checksum.end())
    {
      *j = *j ^ bit4;
    }
  }
}


void KaseikyoProtocol::generateLittleChecksum(
  const CommandSequence &firstBits,
  const CommandSequence &secondBits,
  CommandSequence &littleChecksum)
{
  CommandSequence::const_iterator i = firstBits.begin();
  CommandSequence::const_iterator j = secondBits.begin();

  // Advance both iterators by 4 bits:
  int index = 0;
  while ((index < 4) && (i != firstBits.end()) && (j != secondBits.end()))
  {
    ++i;
    ++j;
    ++index;
  }

  // Xor the next four bits and store them:
  index = 0;
  while ((index < 4) && (i != firstBits.end()) && (j != secondBits.end()))
  {
    littleChecksum.push_back(*i ^ *j);
    ++i;
    ++j;
    ++index;
  }
}
