//
// panasonicoldprotocol.cpp
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

#include "panasonicoldprotocol.h"

#include "pirinfraredled.h"

#include "pirexception.h"

#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// The "Panasonic Old" protocol appears to have the following features:
// A "zero" is encoded with an 833 usec pulse, 833 usec space.
// A "one" is encoded with an 833 usec pulse, and 3*833 (2499) usec space.
// The header is a 3332 usec pulse, 3332 usec space.
// Commands end with a trailing 833 usec pulse.
// When repeating, the entire command is re-sent.
// Each command runs for approximately 105000 usec (need to check this)
// The carrier frequency might be 57.6 kHz.

PanasonicOldProtocol::PanasonicOldProtocol(
  QObject *guiObject,
  unsigned int index)
  : SpaceProtocol(
      guiObject, index,
      833, 833,
      833, 2499,
      3332, 3332,
      833,
      105000, true)
{
  setCarrierFrequency(57600);
}


void PanasonicOldProtocol::startSendingCommand(
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
      commandDuration = generateStandardCommand((*i).second, led);

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


int PanasonicOldProtocol::generateStandardCommand(
  const PIRKeyBits &pkb,
  PIRInfraredLED &led)
{
  int duration = 0;

  // First, the header pulse:
  led.addPair(headerPulse, headerSpace);
  duration += (headerPulse + headerSpace);

  // This protocol uses 5 bits of address and 6 bits of command.  As with
  // many protocols used for audio components, one remote can handle
  // multiple addresses, so both address and command are stored as variable
  // data.
  //
  // It is laid out as follows:
  // 1) the five bits of address data, LSB order
  // 2) the six bits of command data, LSB order
  // 3) repeat of the five bits of address data, inverted
  // 4) repeat of the six bits of command data, inverted

  duration += pushReverseBits(pkb.firstCode, led);
  duration += pushReverseBits(pkb.secondCode, led);
  duration += pushInvertedReverseBits(pkb.firstCode, led);
  duration += pushInvertedReverseBits(pkb.secondCode, led);

  // Add the trailer pulse:
  led.addSingle(trailerPulse);
  duration += trailerPulse;

  return duration;
}
