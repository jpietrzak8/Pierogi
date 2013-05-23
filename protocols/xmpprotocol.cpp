//
// xmpprotocol.cpp
//
// Copyright 2012, 2013 by John Pietrzak (jpietrzak8@gmail.com)
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

#include "xmpprotocol.h"

#include "pirinfraredled.h"

#include "pirexception.h"

// Some global communications stuff:
#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// The XMP protocol is a real beast, packed full of checksums, toggle bits,
// large command codes and fancy repeat mechanisms.
// Each pulse/space pair represents four bits, as so:
// A "zero" is encoded with a 210 usec pulse, 760 usec space.
// Each value after that adds an additional 136 usec to the space, so
// a "one" has a 1*136 + 760 = 896 usec space,
// a "two" has a 2*136 + 760 = 1032 usec space,
// ...
// and a "fifteen" has a 15*136 + 760 = 2800 usec space.
// There is no header pulse.
// There is a 210 usec pulse, 13800 usec space in the middle...
// Commands end with a trailing 210 usec pulse.
// The first "frame" has a 4-bit "toggle" value of 0; repeat frames following
// this one are identical, except for the "toggle" value changed to 8.
// There is a gap of 80000 usec between each frame.
// An optional "final" frame can also exist, with a toggle value of 9, and
// separated from the previous frame by only 13800 usec.
// The carrier frequency should be 38 kHz.

XMPProtocol::XMPProtocol(
  QObject *guiObject,
  unsigned int index,
  unsigned int sd1,
  unsigned int sd2,
  unsigned int oem,
  unsigned int d,
  bool hasFF)
  : PIRProtocol(
      guiObject, index,
      80000, true),
    subDeviceOne(sd1),
    subDeviceTwo(sd2),
    oemCode(oem),
    deviceCode(d),
    hasFinalFrame(hasFF)
{
}


void XMPProtocol::startSendingCommand(
  unsigned int threadableID,
  PIRKeyName command)
{
  // Exceptions here are problematic; I'll try to weed them out by putting the
  // whole thing in a try/catch block:
  try
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
      return;
//      std::string s = "Tried to send a non-existent command.\n";
//      throw PIRException(s);
    }

    // construct the device:
    PIRInfraredLED led(carrierFrequency, dutyCycle);

    int repeatCount = 0;
    int commandDuration = 0;
    while (repeatCount < MAX_REPEAT_COUNT)
    {
      if (repeatCount)
      {
        commandDuration = generateRepeatCommand(i->second, led);
      }
      else
      {
        commandDuration = generateStandardCommand(i->second, led);
      }

      // Now, tell the device to send the whole command:
      led.sendCommandToDevice();

      // sleep until the next repetition of command:
      sleepUntilRepeat(commandDuration);

      // Check whether we've reached the minimum required number of repetitons:
      if (repeatCount >= minimumRepetitions)
      {
        // Check whether we've been asked to stop:
        if (checkRepeatFlag())
        {
          // Do we need to send out a final frame?
          if (hasFinalFrame)
          {
            commandDuration = generateFinalCommand(i->second, led);
            led.sendCommandToDevice();
            sleepUntilRepeat(commandDuration);
          }

          break;
/*
          QMutexLocker cifLocker(&commandIFMutex);
          commandInFlight = false;
          return;
*/
        }
      }

      ++repeatCount;
    }

    QMutexLocker cifLocker(&commandIFMutex);
    commandInFlight = false;
  }
  catch (PIRException e)
  {
    // inform the gui:
    emit commandFailed(e.getError().c_str());
  }
}


int XMPProtocol::generateStandardCommand(
  const PIRKeyBits &pkb,
  PIRInfraredLED &led)
{
  int duration = 0;

  // XMP frames have the following structure:
  // 1) The first 4 bits of the "sub-device" code
  // 2) A four-bit checksum value
  // 3) The second 4 bits of the "sub-device" code
  // 4) The four-bit value 0xF
  // 5) An eight-bit OEM code (normally 0x44)
  // 6) An eight-bit device code
  // 7) a 210 usec pulse, 13800 usec space divider
  // 8) The first 4 bits of the "sub-device" code (again)
  // 9) Another four-bit checksum value
  // 10) The four-bit toggle value
  // 11) The second 4 bits of the "sub-device" code (again)
  // 12) A pair of 8-bit command codes (often one of them will be 0)
  // All of this is sent in MSB order.
  // The checksums are constructed by adding up all the half-bytes in
  // their side of the frame to 15, taking the complement, and modding the
  // result with 16.

  duration += pushHalfByte(subDeviceOne, led);
  duration += pushHalfByte(calculateChecksumOne(), led);
  duration += pushHalfByte(subDeviceTwo, led);
  duration += pushHalfByte(0xF, led);
  duration += pushFullByte(oemCode, led);
  duration += pushFullByte(deviceCode, led);

  led.addPair(210, 13800);
  duration += 14010;

  duration += pushHalfByte(subDeviceOne, led);
  duration += pushHalfByte(
    calculateChecksumTwo(0x0, pkb.firstCode, pkb.secondCode),
    led);
  duration += pushHalfByte(0x0, led);
  duration += pushHalfByte(subDeviceTwo, led);
  duration += pushBits(pkb.firstCode, led);
  duration += pushBits(pkb.secondCode, led);

  // Finally add the "trail":
  led.addSingle(210);
  duration += 210;

  return duration;
}


int XMPProtocol::generateRepeatCommand(
  const PIRKeyBits &pkb,
  PIRInfraredLED &led)
{
  int duration = 0;

  // an XMP repeat frame is identical to the start frame, except that
  // the "toggle" value is now 8.

  duration += pushHalfByte(subDeviceOne, led);
  duration += pushHalfByte(calculateChecksumOne(), led);
  duration += pushHalfByte(subDeviceTwo, led);
  duration += pushHalfByte(0xF, led);
  duration += pushFullByte(oemCode, led);
  duration += pushFullByte(deviceCode, led);

  led.addPair(210, 13800);
  duration += 14010;

  duration += pushHalfByte(subDeviceOne, led);
  duration += pushHalfByte(
    calculateChecksumTwo(0x8, pkb.firstCode, pkb.secondCode),
    led);
  duration += pushHalfByte(0x8, led);
  duration += pushHalfByte(subDeviceTwo, led);
  duration += pushBits(pkb.firstCode, led);
  duration += pushBits(pkb.secondCode, led);

  // Finally add the "trail":
  led.addSingle(210);
  duration += 210;

  return duration;
}


int XMPProtocol::generateFinalCommand(
  const PIRKeyBits &pkb,
  PIRInfraredLED &led)
{
  int duration = 0;

  // an XMP final frame is basically a pair of repeat frames, but the
  // gap between them is only 13800 usec, and the "toggle" value of the
  // second frame is 9.

  duration += pushHalfByte(subDeviceOne, led);
  duration += pushHalfByte(calculateChecksumOne(), led);
  duration += pushHalfByte(subDeviceTwo, led);
  duration += pushHalfByte(0xF, led);
  duration += pushFullByte(oemCode, led);
  duration += pushFullByte(deviceCode, led);

  led.addPair(210, 13800);
  duration += 14010;

  duration += pushHalfByte(subDeviceOne, led);
  duration += pushHalfByte(
    calculateChecksumTwo(0x8, pkb.firstCode, pkb.secondCode),
    led);
  duration += pushHalfByte(0x8, led);
  duration += pushHalfByte(subDeviceTwo, led);
  duration += pushBits(pkb.firstCode, led);
  duration += pushBits(pkb.secondCode, led);

  led.addPair(210, 13800);
  duration += 14010;

  duration += pushHalfByte(subDeviceOne, led);
  duration += pushHalfByte(calculateChecksumOne(), led);
  duration += pushHalfByte(subDeviceTwo, led);
  duration += pushHalfByte(0xF, led);
  duration += pushFullByte(oemCode, led);
  duration += pushFullByte(deviceCode, led);

  led.addPair(210, 13800);
  duration += 14010;

  duration += pushHalfByte(subDeviceOne, led);
  duration += pushHalfByte(
    calculateChecksumTwo(0x9, pkb.firstCode, pkb.secondCode),
    led);
  duration += pushHalfByte(0x9, led);
  duration += pushHalfByte(subDeviceTwo, led);
  duration += pushBits(pkb.firstCode, led);
  duration += pushBits(pkb.secondCode, led);

  // Finally add the "trail":
  led.addSingle(210);
  duration += 210;

  return duration;
}


unsigned int XMPProtocol::calculateChecksumOne()
{
  // Start with the value 0xF:
  unsigned int total = 0xF;

  // Add the other half-bytes in the first part of the frame:
  total += subDeviceOne;
  total += subDeviceTwo;
  total += 0xF;
  total += oemCode >> 4;
  total += oemCode & 0x0F;
  total += deviceCode >> 4;
  total += deviceCode & 0x0F;

  // Next, invert:
  total = -total;

  // Finally, mod 0x10:
  total = total % 0x10;

  return total;
}


unsigned int XMPProtocol::calculateChecksumTwo(
  unsigned int toggle,
  const CommandSequence &firstCode,
  const CommandSequence &secondCode)
{
  // Start with the value 0xF:
  unsigned int total = 0xF;

  // Add the other half-bytes in the second part of the frame:
  total += subDeviceOne;
  total += toggle;
  total += subDeviceTwo;

  unsigned int codeValue = 0;
  CommandSequence::const_iterator i = firstCode.begin();

  while (i != firstCode.end())
  {
    // Shift codeValue over and add the bit:
    codeValue = codeValue << 1;
    codeValue += *i;
    ++i;
  }

  total += codeValue >> 4;
  total += codeValue & 0xF;

  codeValue = 0;
  i = secondCode.begin();

  while (i != secondCode.end())
  {
    codeValue = codeValue << 1;
    codeValue += *i;
    ++i;
  }

  total += codeValue >> 4;
  total += codeValue & 0xF;

  // Next, invert:
  total = -total;

  // Finally, mod 0x10:
  total = total % 0x10;

  return total;
}


int XMPProtocol::pushHalfByte(
  unsigned int halfByte,
  PIRInfraredLED &led)
{
  unsigned int space = 760 + (136 * halfByte);
  led.addPair(210, space);

  return (210 + space);
}


int XMPProtocol::pushFullByte(
  unsigned int fullByte,
  PIRInfraredLED &led)
{
  unsigned int firstSpace = 760 + (136 * (fullByte >> 4));
  unsigned int secondSpace = 760 + (136 * (fullByte & 0xF));

  led.addPair(210, firstSpace);
  led.addPair(210, secondSpace);

  return (420 + firstSpace + secondSpace);
}


int XMPProtocol::pushBits(
  const CommandSequence &bits,
  PIRInfraredLED &led)
{
  unsigned int duration = 0;

  // We can only sent 4-bit values in XMP, so need to collect bits up into
  // bundles of 4:

  unsigned int bitsValue = 0;
  int count = 0;
  CommandSequence::const_iterator i = bits.begin();

  while (i != bits.end())
  {
    if (count < 4)
    {
      bitsValue = bitsValue << 1;
      bitsValue += *i;
      ++count;
    }
    else
    {
      led.addPair(210, 760 + (136 * bitsValue));
      duration += 970 + (136 * bitsValue);

      count = 1;
      bitsValue = *i;
    }

    ++i;
  }

  if (count == 4)
  {
    led.addPair(210, 760 + (136 * bitsValue));
    duration += 970 + (136 * bitsValue);
  }

  return duration;
}
