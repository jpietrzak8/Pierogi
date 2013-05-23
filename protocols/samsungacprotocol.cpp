//
// samsungacprotocol.cpp
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

#include "samsungacprotocol.h"

#include "pirinfraredled.h"

#include "pirexception.h"

// Some global communications stuff:
#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// Due to the maintenance of state information in the remote control,
// these air conditioner protocols are quite a headache.  I'm starting with
// the Samsung AC protocol; looks to be a pulse train containing 56(?) bits
// of information.  I'll try to pin this down.
//
// A "zero" is encoded with a 500 usec pulse, 560 usec space.
// A "one" is encoded with a 500 usec pulse, 1570 usec space.
// The header is a 3000 usec pulse, 9000 usec space.
// I'm told that Samsung AC controls _do not repeat_.  So, 0 time between
// commands.
// The carrier frequency is 38 kHz.

SamsungACProtocol::SamsungACProtocol(
  QObject *guiObject,
  unsigned int index)
  : SpaceProtocol(
      guiObject, index,
      500, 560,
      500, 1570,
      3000, 9000,
      500,
      0, false)
{
  // The header for a timer command is 0xF:
  appendToBitSeq(timerHeader, 0xF, 4);

  // An empty timer is 8 bits of 0:
  appendToBitSeq(emptyTimer, 0x0, 8);

  // For anything less than 24 hours, the final twelve bits are 0, and I'm
  // going to just go with that for now:
  appendToBitSeq(timerFooter, 0x0, 12);

  // Need to pad the command with 4 bits of 0 at one point:
  appendToBitSeq(fourBitZero, 0x0, 4);
}


void SamsungACProtocol::startSendingStateInfo(
  PIRACStateInfo state,
  unsigned int threadableID,
  PIRKeyName command)
{
  if (command == ACSetTimer_Key)
  {
    // Store the info used for the timer command:

    // Determine what type of command to send (for now, just use timerOption):
    timerCommandType = state.timerOption;

    // 4 bits of timer options:
    timerOption.clear();
    appendToBitSeq(timerOption, state.timerOption, 4);

    // 6 bits of hour data:
    timerHours.clear();
    appendToBitSeq(timerHours, state.timerHours, 6);

    // 2 bits of minute data (I'm just setting it to 0 for now):
    timerMinutes.clear();
    timerMinutes.push_back(0);
    timerMinutes.push_back(0);
  }
  else
  {
    // Store the info used for all other commands:

    // 8 bits of swing:
    swing.clear();
    appendToBitSeq(swing, state.swing, 8);

    // 8 bits of turbo:
    turbo.clear();
    appendToBitSeq(turbo, state.turbo, 8);

    // 8 bits of temperature:
    temperature.clear();
    appendToBitSeq(temperature, state.temperature, 8);

    // 4 bits of fan:
    fan.clear();
    appendToBitSeq(fan, state.fan, 4);

    // 4 bits of mode:
    mode.clear();
    appendToBitSeq(mode, state.mode, 4);

    // 4 bits of airclean:
    airclean.clear();
    appendToBitSeq(airclean, state.airclean, 4);

    // 4 bits of power:
    power.clear();
    appendToBitSeq(power, state.power, 4);
  }

  startSendingCommand(threadableID, command);
}


// Note: it seems that Samsung AC remotes do not repeat commands!  I'd love
// to find verification of this, I've only one source for it...
void SamsungACProtocol::startSendingCommand(
  unsigned int threadableID,
  PIRKeyName command)
{
  // Exceptions here are problematic; I'll try to weed them out by putting the
  // whole thing in a try/catch block:
  try
  {
    // First, check if we are meant to be the recipient of this command:
    if (threadableID != id) return;

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

    if (command == ACSetTimer_Key)
    {
      generateTimerCommand(led);
    }
    else
    {
      generateCommand(led);
    }

    // Now, tell the device to send the whole command:
    led.sendCommandToDevice();

    QMutexLocker cifLocker(&commandIFMutex);
    commandInFlight = false;
  }
  catch (PIRException e)
  {
    // inform the gui:
    emit commandFailed(e.getError().c_str());
  }
}


void SamsungACProtocol::generateCommand(
  PIRInfraredLED &led)
{
  // First, the "header" pulse:
  led.addPair(headerPulse, headerSpace);

  // Next, the "address" information (12 bits):
  pushReverseBits(preData, led);

  // Now, the fun part.  We'll need to construct a massive command, containing
  // all the state information for the air conditioner.

  // First, calculate and push the checksum (4 bits):
  CommandSequence checksum;
  calculateChecksum(checksum);
  pushReverseBits(checksum, led);

  // Next, push the swing mode (8 bits):
  pushReverseBits(swing, led);

  // Next, the turbo mode (8 bits):
  pushReverseBits(turbo, led);

  // Next, the temperature (8 bits):
  pushReverseBits(temperature, led);

  // Next, the fan (4 bits):
  pushReverseBits(fan, led);

  // Next, the mode (4 bits):
  pushReverseBits(mode, led);

  // Next, "air clean" (4 bits):
  pushReverseBits(airclean, led);

  // Next, power (4 bits):
  pushReverseBits(power, led);

  // Finally add the "trail":
  led.addSingle(trailerPulse);
}


void SamsungACProtocol::calculateChecksum(
  CommandSequence &checksum)
{
  // To calculate the checksum, sum all the bits, do a mod 16, and subtract
  // from 16:
  int sum = 0;

  CommandSequence::const_iterator i = swing.begin();
  while (i != swing.end())
  {
    if (*i) ++sum;
    ++i;
  }

  i = turbo.begin();
  while (i != turbo.end())
  {
    if (*i) ++sum;
    ++i;
  }

  i = temperature.begin();
  while (i != temperature.end())
  {
    if (*i) ++sum;
    ++i;
  }

  i = fan.begin();
  while (i != fan.end())
  {
    if (*i) ++sum;
    ++i;
  }

  i = mode.begin();
  while (i != mode.end())
  {
    if (*i) ++sum;
    ++i;
  }

  i = airclean.begin();
  while (i != airclean.end())
  {
    if (*i) ++sum;
    ++i;
  }

  i = power.begin();
  while (i != power.end())
  {
    if (*i) ++sum;
    ++i;
  }

  int modsum = 16 - (sum % 16);

  // Append these four bits:
  appendToBitSeq(checksum, modsum, 4);
}


void SamsungACProtocol::generateTimerCommand(
  PIRInfraredLED &led)
{
  // First, the "header" pulse:
  led.addPair(headerPulse, headerSpace);

  // Next, the "address" information (12 bits):
  pushReverseBits(preData, led);

  // The checksum (4 bits):
  CommandSequence checksum;
  calculateTimerChecksum(checksum);
  pushReverseBits(checksum, led);

  // Push an 0xF to indicate this is a timer command.
  pushBits(timerHeader, led);

  // if this is an off timer, push the time, otherwise 0:
  if (timerCommandType == 0x4)
  {
    pushReverseBits(timerMinutes, led);
    pushReverseBits(timerHours, led);
  }
  else
  {
    pushBits(emptyTimer, led);
  }

  // if this is an on timer, push the time, otherwise 0:
  if (timerCommandType == 0x2)
  {
    pushReverseBits(timerMinutes, led);
    pushReverseBits(timerHours, led);
  }
  else
  {
    pushBits(emptyTimer, led);
  }

  // This is a hack to add in 4 bits of 0:
  pushBits(fourBitZero, led);

  // Push the timer command type:
  pushReverseBits(timerOption, led);

  // Finish off the command:
  pushBits(timerFooter, led);

  // Add the "trail":
  led.addSingle(trailerPulse);
}


void SamsungACProtocol::calculateTimerChecksum(
  CommandSequence &checksum)
{
  // As with the normal checksum, sum all the bits, do a mod 16, and subtract
  // from 16:

  // All timer commands start with an 0xF header; however, the first bit of
  // that header doesn't count.  So start with three bits:
  int sum = 3;

  CommandSequence::const_iterator i = timerOption.begin();
  while (i != timerOption.end())
  {
    if (*i) ++sum;
    ++i;
  }

  i = timerHours.begin();
  while (i != timerHours.end())
  {
    if (*i) ++sum;
    ++i;
  }

  i = timerMinutes.begin();
  while (i != timerMinutes.begin())
  {
    if (*i) ++sum;
    ++i;
  }

  int modsum = 16 - (sum % 16);

  appendToBitSeq(checksum, modsum, 4);
}
