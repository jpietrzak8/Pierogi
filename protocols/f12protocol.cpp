//
// f12protocol.cpp
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

#include "f12protocol.h"

#include "pirinfraredled.h"

#include <time.h>
#include <errno.h>

// Some global communications stuff:
#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// The "F12" protocol is a bit complicated, as it has both "single-shot"
// and "repeat" modes, depending on the contents of the command.
// Moreover, in the "repeat" mode, there are two different pauses
// between commands.
// The basic properties are:
// A "zero" is encoded with a 422 usec pulse, 3*422 (1266) usec space.
// A "one" is encoded with a 3*422 (1266) usec pulse, 422 usec space.
// There is no header pulse or trailer pulse.
// If in "single-shot" mode, the command train is repeated once with
// an 80*422 (33760) usec gap between them.
// If in "repeat" mode, the command train is repeated with alternating
// gaps of 33760 and 208*422 (87776) usec.
// The carrier frequency is apparently 38 kHz, duty cycle 1/3.

F12Protocol::F12Protocol(
  QObject *guiObject,
  unsigned int index)
  : SpaceProtocol(
      guiObject, index,
      422, 1266,
      1266, 422,
      0, 0,
      0,
      0, false)
{
}


void F12Protocol::startSendingCommand(
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

  int commandDuration = 0;

  if (isSingleShot((*i).second.firstCode))
  {
    commandDuration = generateSingleShotCommand((*i).second, led);
    if (led.sendCommandToDevice())
    {
      f12SleepUntilRepeat(33760);
      led.sendCommandToDevice();
    }
  }
  else
  {
    int repeatCount = 0;

    commandDuration = generateRepeatableCommand((*i).second, led);

    while (repeatCount < MAX_REPEAT_COUNT)
    {
      if (!led.sendCommandToDevice())
      {
        break;
      }

      if (repeatCount % 2)
      {
        f12SleepUntilRepeat(33760);
      }
      else
      {
        f12SleepUntilRepeat(87776);
      }

      // Check whether we've reached the minimum number of repetitons:
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
  }

  QMutexLocker cifLocker(&commandIFMutex);
  commandInFlight = false;
}


int F12Protocol::generateSingleShotCommand(
  const PIRKeyBits &pkb,
  PIRInfraredLED &led)
{
  int duration = 0;

  // In the F12 protocol, the device code has 3 bits, and the command has 8
  // (sort of).  In reality, bits 4, 5, and 6 are "mode" bits, but it seems
  // 5 and 6 get pushed into the two least significant bits of the command
  // by the sources I've got (the command being sent in LSB mode).  This
  // method is only for "single shot" commands, so bit 4 is always going to
  // be "0".
  // 
  // - "preData" contains 3-bit device code.
  // - "pkb.firstCode" contains 8-bit command code.
  duration += pushReverseBits(preData, led);
  led.addPair(zeroPulse, zeroSpace);
  duration += (zeroPulse + zeroSpace);
  duration += pushReverseBits(pkb.firstCode, led);

  return duration;
}


int F12Protocol::generateRepeatableCommand(
  const PIRKeyBits &pkb,
  PIRInfraredLED &led)
{
  int duration = 0;

  // In the F12 protocol, the device code has 3 bits, and the command has 8
  // (sort of).  In reality, bits 4, 5, and 6 are "mode" bits, but it seems
  // 5 and 6 get pushed into the two least significant bits of the command
  // by the sources I've got (the command being sent in LSB mode).  This
  // method is only for "repeatable" commands, so bit 4 is always going to
  // be "1".
  // 
  // - "preData" contains 3-bit device code.
  // - "pkb.firstCode" contains 8-bit command code.
  duration += pushReverseBits(preData, led);
  led.addPair(onePulse, oneSpace);
  duration += (onePulse + oneSpace);
  duration += pushReverseBits(pkb.firstCode, led);

  return duration;
}


bool F12Protocol::isSingleShot(
  const CommandSequence &bits)
{
  CommandSequence::const_reverse_iterator i = bits.rbegin();
  if (i == bits.rend())
  {
    // Throw exception here?
    return false;
  }

  if (*i)
  {
    // This is a single-shot command.
    return true;
  }

  ++i;

  if (i == bits.rend())
  {
    // Throw exception here?
    return false;
  }

  if (*i)
  {
    // This is a single-shot command.
    return true;
  }

  // At this point, it could only be a repeatable command.
  return false;
}


// I've pulled the following out of the root protocol class, to allow
// for the odd inter-command pause of the f12 protocol.  There should
// probably be a better way to do this...

// Note that the following routine blindly sleeps for the amount of time
// specified by the LIRC config file.  The extra overhead of processing
// each command will mean that repeated commands will overshoot the config
// time by some amount.  We could improve accuracy by waiting a little less
// than the specified time, if we could get a good handle on how long the
// overhead is delaying the command...
#define PIEROGI_OVERHEAD_HACK 13260

bool F12Protocol::f12SleepUntilRepeat(
  int gap)
{
  int microseconds = gap - PIEROGI_OVERHEAD_HACK;

/*
  // Don't even bother sleeping if there's only a few microseconds:
  if (microseconds < 1000)
  {
    return;
  }
*/
  // For now, I'm going to enforce a minimum sleep of 10 ms, so that we
  // don't get runaway commands:
  if (microseconds < 10000)
  {
    microseconds = 10000;
  }

  timespec sleeptime;
  sleeptime.tv_sec = 0;
  sleeptime.tv_nsec = microseconds * 1000;

  timespec remainingtime;

  if (nanosleep(&sleeptime, &remainingtime) == -1)
  {
    QString errStr = "Problem while sleeping.\n";
    errStr += "Trying to sleep for: ";
    errStr += QString::number(microseconds);
    errStr += "\n Nanosleep returned error: ";
    errStr += strerror(errno);
    emit errorMessage(errStr);
    return false;
  }

  return true;
}
