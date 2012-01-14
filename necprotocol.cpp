#include "necprotocol.h"

#include "pirexception.h"
#include <string>
//#include <iostream>

NECProtocol::NECProtocol(
  QObject *guiObject,
  unsigned int index,
  unsigned int zPulse,
  unsigned int zSpace,
  unsigned int oPulse,
  unsigned int oSpace,
  unsigned int gSpace,
  bool iclflag)
  : PIRProtocol(guiObject, index, gSpace, iclflag),
    zeroPulse(zPulse),
    zeroSpace(zSpace),
    onePulse(oPulse),
    oneSpace(oSpace),
    hasTrailerPulse(false),
    hasHeaderPair(false),
    hasRepeatPair(false),
    repeatNeedsHeader(false),
    fullHeadlessRepeat(false)
{
}

void NECProtocol::setHeaderPair(
  unsigned int pulse,
  unsigned int space)
{
  headerPulse = pulse;
  headerSpace = space;
  hasHeaderPair = true;
}

void NECProtocol::setTrailerPulse(
  unsigned int pulse)
{
  trailerPulse = pulse;
  hasTrailerPulse = true;
}

void NECProtocol::setRepeatPair(
  unsigned int pulse,
  unsigned int space)
{
  repeatPulse = pulse;
  repeatSpace = space;
  hasRepeatPair = true;
}

void NECProtocol::setRepeatNeedsHeader(
  bool flag)
{
  repeatNeedsHeader = flag;
}

void NECProtocol::setFullHeadlessRepeat(
  bool flag)
{
  fullHeadlessRepeat = flag;
}

void NECProtocol::setPreData(
  unsigned long data,
  unsigned int bits)
{
  appendToBitSeq(preData, data, bits);
}

void NECProtocol::setPostData(
  unsigned long data,
  unsigned int bits)
{
  appendToBitSeq(postData, data, bits);
}

void NECProtocol::startSendingCommand(
  unsigned int threadableID,
  PIRKeyName command)
{
  // Exceptions here are problematic; I'll try to weed them out by putting the
  // whole thing in a try/catch block:
  try
  {
    clearRepeatFlag();

    // Check if we are meant to be the recipient of this command:
    if (threadableID != id) return;

    KeycodeCollection::const_iterator i = keycodes.find(command);

    // Do we even have this key defined?
    if (i == keycodes.end())
    {
      std::string s = "Tried to send a non-existent command.\n";
      throw PIRException(s);
    }

    // construct the device:
    PIRRX51Hardware rx51device(carrierFrequency, dutyCycle);

    int repeatCount = 0;
    while (repeatCount < MAX_REPEAT_COUNT)
    {
      int commandDuration;

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
          return;
        }
      }

      ++repeatCount;
    }
  }
  catch (PIRException e)
  {
    // inform the gui:
    emit commandFailed(e.getError().c_str());
  }
}


int NECProtocol::generateStandardCommand(
  const CommandSequence &bits,
  PIRRX51Hardware &rx51device)
{
  int duration = 0;

  // First, the "header" pulse (if any):
  if (hasHeaderPair)
  {
    rx51device.addPair(headerPulse, headerSpace);
    duration += (headerPulse + headerSpace);
  }

  // Next, the "pre" data:
  duration += pushBits(preData, rx51device);

  // Next, add the actual command:
  duration += pushBits(bits, rx51device);

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


int NECProtocol::generateHeadlessCommand(
  const CommandSequence &bits,
  PIRRX51Hardware &rx51device)
{
  int duration = 0;

  // First, the "pre" data:
  duration += pushBits(preData, rx51device);

  // Next, add the actual command:
  duration += pushBits(bits, rx51device);

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


int NECProtocol::generateRepeatCommand(
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


int NECProtocol::pushBits(
  const CommandSequence &bits,
  PIRRX51Hardware &rx51device)
{
  int duration = 0;
  CommandSequence::const_iterator i = bits.begin();
  while (i != bits.end())
  {
    if (*i)
    {
      // Send the pulse for "One":
      rx51device.addPair(onePulse, oneSpace);
      duration += (onePulse + oneSpace);
    }
    else
    {
      // Send the pulse for "Zero":
      rx51device.addPair(zeroPulse, zeroSpace);
      duration += (zeroPulse + zeroSpace);
    }
    ++i;
  }

  return duration;
}
