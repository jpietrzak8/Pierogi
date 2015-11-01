//
// bangandolufsenprotocol.cpp
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
// along with this program; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//

#include "bangandolufsenprotocol.h"

#include "pirinfraredled.h"

#include <QString>

// Some global communications stuff:
#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// The Bang and Olufsen protocol is kinda bizarre.  The main feature is that
// it uses a sort-of "trinary" base for numbers: it has values for "0", "1",
// and "same as the last bit sent".  Specifically, you cannot sent two
// successive 0 or 1 bits; wherever that might happen, the succeding bits
// must be a "same as last bit" digit.
//
// A "zero" is encoded with a 200 usec pulse, 3125 usec space.
// A "one" is encoded with a 200 usec pulse, 9375 usec space.
// A "same as last bit" is encoded with a 200 usec pulse, 6250 usec space.
// The header is two "one" bits followed by a 200 usec pulse, 15625 usec space.
// Commands end with a trailing 200 usec pulse.
// Commands are repeated by re-sending the entire train (although most
// commands do _not_ repeat, or only repeat once!).
// There is a 12500 usec pause between commands (very short!).
// The carrier frequency is 455 kHz!  And B&O hardware is very sensitive
// to this frequency...

BangAndOlufsenProtocol::BangAndOlufsenProtocol(
  QObject *guiObject,
  unsigned int index)
  : SpaceProtocol(
      guiObject, index,
      200, 3125,
      200, 9375,
      200, 15625,
      200,
      12500, false),
    sameAsPreviousPulse(200),
    sameAsPreviousSpace(6250),
    previousBit(BandONo_Bit)
{
  setCarrierFrequency(455000);
}


void BangAndOlufsenProtocol::startSendingCommand(
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


int BangAndOlufsenProtocol::generateCommand(
  const PIRKeyBits &pkb,
  PIRInfraredLED &led)
{
  int duration = 0;

  // Start with the two "one" pulses:
  led.addPair(onePulse, oneSpace);
  duration += onePulse + oneSpace;
  led.addPair(onePulse, oneSpace);
  duration += onePulse + oneSpace;

  // Next, the "header" pulse:
  led.addPair(headerPulse, headerSpace);
  duration += (headerPulse + headerSpace);

  // Ok, the B&O device management system is pretty insane.  They code for
  // dozens of devices, and frequently combine commands of different devices
  // together... it's going to be some effort to get through all of this.
  // To start with, I'll stick with one device code at a time.
  // Device codes can be either 9 or 12 bits long, but I'm going to ignore
  // the 12 bit versions for now, as they are only used for the second
  // tape deck (so far as I can tell).  The first bit of the device code
  // is for the "link", which I don't understand, so I'll leave that as 0
  // for now as well.  So, 8 bits for device.  And, then 8 bits for 
  // command.  The data is sent in MSB order, with no duplication or checksum.

  // Push the "0" for link:
  led.addPair(zeroPulse, zeroSpace);
  duration += (headerPulse + headerSpace);
  previousBit = BandOZero_Bit;

  // Push the device code:
  duration += pushBandOBits(preData, led);

  // Push the command code:
  duration += pushBandOBits(pkb.firstCode, led);

  // Finally add the "trail":
  led.addSingle(trailerPulse);
  duration += trailerPulse;

  return duration;
}


int BangAndOlufsenProtocol::pushBandOBits(
  const CommandSequence &bits,
  PIRInfraredLED &led)
{
  int duration = 0;

  CommandSequence::const_iterator i = bits.begin();

  while (i != bits.end())
  {
    if (*i)
    {
      // Have we previously sent a 1?
      if (previousBit == BandOOne_Bit)
      {
        // Send a "same as previous" bit:
        led.addPair(sameAsPreviousPulse, sameAsPreviousSpace);
        duration += (sameAsPreviousPulse + sameAsPreviousSpace);
      }
      else
      {
        // Send a "1" bit:
        led.addPair(onePulse, oneSpace);
        duration += (onePulse + oneSpace);
        previousBit = BandOOne_Bit;
      }
    }
    else
    {
      if (previousBit == BandOZero_Bit)
      {
        // Send a "same as previous" bit:
        led.addPair(sameAsPreviousPulse, sameAsPreviousSpace);
        duration += (sameAsPreviousPulse + sameAsPreviousSpace);
      }
      else
      {
        led.addPair(zeroPulse, zeroSpace);
        duration += (zeroPulse + zeroSpace);
        previousBit = BandOZero_Bit;
      }
    }
  }

  return duration;
}
