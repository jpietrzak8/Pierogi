//
// canalsatprotocol.cpp
//
// Copyright 2013 by John Pietrzak (jpietrzak8@gmail.com)
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

#include "canalsatprotocol.h"

#include "pirinfraredled.h"

#include "pirexception.h"

#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// There are a couple of different types of "CanalSat" protocol.  For the
// VIP1853 remote, here's what I've got:
// Biphase-encoded binary, with a duration of 320 usec per phase.
// Zero is OffOn, One is OnOff.
// The header is 320 usec on, 320 usec off (a One).
// Repeat performed by resending full command train; but first command sets
// toggle bit to 0, and each repeat frame sets toggle bit to 1.
// There's a gap of 85000 usec between commands.
// Carrier frequency is 56 kHz.

CanalSatProtocol::CanalSatProtocol(
  QObject *guiObject,
  unsigned int index)
  : PIRProtocol(guiObject, index, 85000, false),
    biphaseUnit(320),
    buffer(0)
{
  setCarrierFrequency(56000);
}


void CanalSatProtocol::startSendingCommand(
  unsigned int threadableID,
  PIRKeyName command)
{
  try
  {
    if (threadableID != id) return;

    clearRepeatFlag();

    KeycodeCollection::const_iterator i = keycodes.find(command);

    // Sanity check, make sure command exists first:
    if (i == keycodes.end())
    {
      QMutexLocker cifLocker(&commandIFMutex);
      commandInFlight = false;
      return;  // should send an error message here!!!
    }

    // Create object to communicate with device driver:
    PIRInfraredLED led(carrierFrequency, dutyCycle);

    int repeatCount = 0;
    int commandDuration = 0;
    while (repeatCount < MAX_REPEAT_COUNT)
    {
      // Construct the CanalSat command string.

      commandDuration += pushBits((*i).second, repeatCount, led);

      // Clear out the buffer, if necessary:
      if (buffer)
      {
        led.addSingle(buffer);
        commandDuration += buffer;

        buffer = 0;
        bufferContainsSpace = false;
        bufferContainsPulse = false;
      }

      // Send the command:
      led.sendCommandToDevice();

      // Sleep for the prescribed amount of time:
      sleepUntilRepeat(commandDuration);

      // Have we been told to stop?
      if (checkRepeatFlag())
      {
        break;
      }

      ++repeatCount;
    }

    QMutexLocker cifLocker(&commandIFMutex);
    commandInFlight = false;
  }
  catch (PIRException e)
  {
    emit commandFailed(e.getError().c_str());
  }
  catch (...)
  {
    emit commandFailed("Generic Error Message");
  }
}


int CanalSatProtocol::pushBits(
  const PIRKeyBits &pkb,
  int repeatCount,
  PIRInfraredLED &led)
{
  int duration = 0;

  // The info I have on the version of CanalSat protocol used by the VIP1853
  // remote is this:
  // Command starts with a 1.
  // Thirteen bits of device data are sent (7 device, 6 subdevice).
  // Next, a toggle bit, set to 1 if this is a repeat frame.
  // Next value is 0.
  // Then, 6 bits of command data are sent.
  // Finally, inverse of first bit of command data is sent.

  // First push the initial "1":
  buffer = 0;
  bufferContainsPulse = false;
  bufferContainsSpace = false;
  duration += pushBit(1, led);

  CommandSequence::const_iterator i = preData.begin();

  // Push the device bits:
  while (i != preData.end())
  {
    duration += pushBit(*i, led);
    ++i;
  }

  // Push the toggle bit:
  if (repeatCount)
  {
    duration += pushBit(1, led);
  }
  else
  {
    duration += pushBit(0, led);
  }

  // Push a constant "zero" bit:
  duration += pushBit(0, led);

  // Push the command bits:
  bool finalBit = 0;
  i = pkb.firstCode.begin();
  while (i != pkb.firstCode.end())
  {
    duration += pushBit(*i, led);
    finalBit = *i;
    ++i;
  }

  // Push the inverse of the final command bit:
  duration += pushBit(!finalBit, led);

  return duration;
}


int CanalSatProtocol::pushBit(
  bool bitValue,
  PIRInfraredLED &led)
{
  unsigned int duration = 0;

  if (bitValue)
  {
    // This is a "1", so first pulse, then space:
    if (bufferContainsPulse)
    {
      // Merge our pulse with preceding pulse, and add it to device:
      led.addSingle(buffer + biphaseUnit);
      duration += (buffer + biphaseUnit);
      buffer = 0;
      bufferContainsPulse = false;
    }
    else
    {
      // Flush out the buffer:
      if (bufferContainsSpace)
      {
        led.addSingle(buffer);
        duration += buffer;
        buffer = 0;
        bufferContainsSpace = false;
      }

      // Push our pulse into the device:
      led.addSingle(biphaseUnit);
      duration += biphaseUnit;
    }

    // Finally, push our space into the buffer:
    buffer = biphaseUnit;
    bufferContainsSpace = true;
  }
  else
  {
    // This is a "0", so first space, then pulse.
    if (bufferContainsSpace)
    {
      // Merge our space with the preceding space, and add it to device:
      led.addSingle(buffer + biphaseUnit);
      duration += (buffer + biphaseUnit);
      buffer = 0;
      bufferContainsSpace = false;
    }
    else
    {
      // Flush out the buffer:
      if (bufferContainsPulse)
      {
        led.addSingle(buffer);
        duration += buffer;
        buffer = 0;
        bufferContainsPulse = false;
      }

      // Add a space:
      led.addSingle(biphaseUnit);
      duration += biphaseUnit;
    }

    // Finally, push a pulse into the buffer:
    buffer = biphaseUnit;
    bufferContainsPulse = true;
  }

  return duration;
}
