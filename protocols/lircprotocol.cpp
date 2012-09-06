#include "lircprotocol.h"

#include "pirrx51hardware.h"

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
    PIRRX51Hardware rx51device(carrierFrequency, dutyCycle);

    int repeatCount = 0;
    int commandDuration = 0;
    while (repeatCount < MAX_REPEAT_COUNT)
    {
      // If we are currently repeating, and have a special "repeat signal",
      // use that signal.  Otherwise, generate a normal command string.
      if (hasRepeatPair && repeatCount)
      {
        commandDuration = generateRepeatCommand(rx51device);
      }
      else if (fullHeadlessRepeat && repeatCount)
      {
        commandDuration = generateHeadlessCommand((*i).second, rx51device);
      }
      else
      {
        commandDuration = generateStandardCommand((*i).second, rx51device);
      }

      // Now, tell the device to send the whole command:
      rx51device.sendCommandToDevice();

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
  PIRRX51Hardware &rx51device)
{
  int duration = 0;

  // First, the "header" pulse (if any):
  if (hasHeaderPair)
  {
    rx51device.addPair(headerPulse, headerSpace);
    duration += (headerPulse + headerSpace);
  }

  // For LIRC, just dump the bits straight into the device, one by one:
  duration += pushBits(preData, rx51device);
  duration += pushBits(pkb.firstCode, rx51device);
  duration += pushBits(postData, rx51device);

  // Finally add the "trail":
  if (hasTrailerPulse)
  {
    rx51device.addSingle(trailerPulse);
    duration += trailerPulse;
  }

  return duration;
}


int LIRCProtocol::generateHeadlessCommand(
  const PIRKeyBits &pkb,
  PIRRX51Hardware &rx51device)
{
  int duration = 0;

  // First, the "pre" data:
  duration += pushBits(preData, rx51device);

  // Next, add the actual command:
  duration += pushBits(pkb.firstCode, rx51device);

  // Next, add the "post" data:
  duration += pushBits(postData, rx51device);

  // Finally add the "trail":
  if (hasTrailerPulse)
  {
    rx51device.addSingle(trailerPulse);
    duration += trailerPulse;
  }

  return duration;
}


int LIRCProtocol::generateRepeatCommand(
  PIRRX51Hardware &rx51device)
{
  int duration = 0;

  // Do we need the header?
  if (repeatNeedsHeader)
  {
    // Do we even have a header?
    if (hasHeaderPair)
    {
      // Ok, then add the header to the repeat:
      rx51device.addPair(headerPulse, headerSpace);
      duration += (headerPulse + headerSpace);
    }
  }

  // Add the repeat pulse:
  rx51device.addPair(repeatPulse, repeatSpace);
  duration += (repeatPulse + repeatSpace);

  // Finally add the trailer:
  if (hasTrailerPulse)
  {
    rx51device.addSingle(trailerPulse);
    duration += trailerPulse;
  }

  return duration;
}
