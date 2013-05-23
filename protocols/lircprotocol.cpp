//
// lircprotocol.cpp
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

#include "lircprotocol.h"

#include "pirinfraredled.h"

#include "pirexception.h"
#include <string>
//#include <iostream>

// Some global communications stuff:
#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

LIRCProtocol::LIRCProtocol(
  QObject *guiObject,
  unsigned int index,
  unsigned int zPulse,
  unsigned int zSpace,
  unsigned int oPulse,
  unsigned int oSpace,
  unsigned int gSpace,
  bool iclflag)
  : SpaceProtocol(
      guiObject, index,
      zPulse, zSpace,
      oPulse, oSpace,
      0, 0,
      0,
      gSpace, iclflag),
    hasHeaderPair(false),
    hasTrailerPulse(false),
    hasRepeatPair(false),
    repeatNeedsHeader(false),
    fullHeadlessRepeat(false)
{
}

void LIRCProtocol::setHeaderPair(
  unsigned int pulse,
  unsigned int space)
{
  headerPulse = pulse;
  headerSpace = space;
  hasHeaderPair = true;
}

void LIRCProtocol::setTrailerPulse(
  unsigned int pulse)
{
  trailerPulse = pulse;
  hasTrailerPulse = true;
}

void LIRCProtocol::setRepeatPair(
  unsigned int pulse,
  unsigned int space)
{
  repeatPulse = pulse;
  repeatSpace = space;
  hasRepeatPair = true;
}

void LIRCProtocol::setRepeatNeedsHeader(
  bool flag)
{
  repeatNeedsHeader = flag;
}

void LIRCProtocol::setFullHeadlessRepeat(
  bool flag)
{
  fullHeadlessRepeat = flag;
}

void LIRCProtocol::startSendingCommand(
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
      // If we are currently repeating, and have a special "repeat signal",
      // use that signal.  Otherwise, generate a normal command string.
      if (hasRepeatPair && repeatCount)
      {
        commandDuration = generateRepeatCommand(led);
      }
      else if (fullHeadlessRepeat && repeatCount)
      {
        commandDuration = generateHeadlessCommand((*i).second, led);
      }
      else
      {
        commandDuration = generateStandardCommand((*i).second, led);
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


int LIRCProtocol::generateStandardCommand(
  const PIRKeyBits &pkb,
  PIRInfraredLED &led)
{
  int duration = 0;

  // First, the "header" pulse (if any):
  if (hasHeaderPair)
  {
    led.addPair(headerPulse, headerSpace);
    duration += (headerPulse + headerSpace);
  }

  // For LIRC, just dump the bits straight into the device, one by one:
  duration += pushBits(preData, led);
  duration += pushBits(pkb.firstCode, led);
  duration += pushBits(postData, led);

  // Finally add the "trail":
  if (hasTrailerPulse)
  {
    led.addSingle(trailerPulse);
    duration += trailerPulse;
  }

  return duration;
}


int LIRCProtocol::generateHeadlessCommand(
  const PIRKeyBits &pkb,
  PIRInfraredLED &led)
{
  int duration = 0;

  // First, the "pre" data:
  duration += pushBits(preData, led);

  // Next, add the actual command:
  duration += pushBits(pkb.firstCode, led);

  // Next, add the "post" data:
  duration += pushBits(postData, led);

  // Finally add the "trail":
  if (hasTrailerPulse)
  {
    led.addSingle(trailerPulse);
    duration += trailerPulse;
  }

  return duration;
}


int LIRCProtocol::generateRepeatCommand(
  PIRInfraredLED &led)
{
  int duration = 0;

  // Do we need the header?
  if (repeatNeedsHeader)
  {
    // Do we even have a header?
    if (hasHeaderPair)
    {
      // Ok, then add the header to the repeat:
      led.addPair(headerPulse, headerSpace);
      duration += (headerPulse + headerSpace);
    }
  }

  // Add the repeat pulse:
  led.addPair(repeatPulse, repeatSpace);
  duration += (repeatPulse + repeatSpace);

  // Finally add the trailer:
  if (hasTrailerPulse)
  {
    led.addSingle(trailerPulse);
    duration += trailerPulse;
  }

  return duration;
}
