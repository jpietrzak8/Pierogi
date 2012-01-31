#include "sharpprotocol.h"

#include "pirexception.h"
#include <string>
//#include <iostream>

// Some global communications stuff:
#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// Sharp's protocol should have the following attributes:
// A "zero" is encoded with a 320 usec pulse, 680 usec space.
// A "one" is encoded with a 320 usec pulse, and 1680 usec space.
// There is no header pulse.
// The pulse train ends with a trailing 320 usec pulse.
// For repeating, the entire train is re-sent, except that the command
// section (and the last two bits) are inverted in each odd repeat.
// There is a 40000 usec delay between the end of one command and the start
// of the next.
// The command should be repeated at least once.
// The carrier frequency is 38 kHz, duty cycle is 1/3.

SharpProtocol::SharpProtocol(
  QObject *guiObject,
  unsigned int index,
  bool expBit)
  : PIRProtocol(guiObject, index, 40000, false),
    zeroPulse(320),
    zeroSpace(680),
    onePulse(320),
    oneSpace(1680),
    trailerPulse(320),
    expansionBit(expBit)
{
  setCarrierFrequency(38000);
  setDutyCycle(33);
}


void SharpProtocol::startSendingCommand(
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
      std::string s = "Tried to send a non-existent command.\n";
      throw PIRException(s);
    }

    // construct the device:
    PIRRX51Hardware rx51device(carrierFrequency, dutyCycle);

    int repeatCount = 0;
    int commandDuration = 0;
    while (repeatCount < MAX_REPEAT_COUNT)
    {
      // Every other repeat count, we invert everything but the address:
      if (repeatCount % 2)
      {
        commandDuration = generateToggledCommand((*i).second, rx51device);
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
//      if (repeatCount >= minimumRepetitions)
      if (repeatCount >= 1)
      {
        // Check whether we've been asked to stop:
        if (checkRepeatFlag())
        {
          QMutexLocker cifLocker(&commandIFMutex);
          commandInFlight = false;
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

  QMutexLocker cifLocker(&commandIFMutex);
  commandInFlight = false;
}


int SharpProtocol::generateStandardCommand(
  const CommandSequence &bits,
  PIRRX51Hardware &rx51device)
{
  int duration = 0;

  // Right now, I've got both the 5-bit address and the 8-bit command
  // smushed together into the command sequence.  Need to pick each of
  // these out and reverse their bits:

  // First, push the address:

  CommandSequence::const_reverse_iterator addressStart = bits.rbegin();
  // Move past the command's 8 bits:
  addressStart += 8;
  duration += pushBits(addressStart, bits.rend(), rx51device);

  // Next, push the command:
  CommandSequence::const_reverse_iterator commandEnd = bits.rbegin();
  // Again, move past the commands's 8 bits:
  commandEnd += 8;
  duration += pushBits(bits.rbegin(), commandEnd, rx51device);

  // Next, there is an "expansion" bit and a "check" bit.  Not entirely sure
  // what these two do.  The check bit is fixed at "1".
  if (expansionBit)
  {
    rx51device.addPair(onePulse, oneSpace);
    duration += (onePulse + oneSpace);
  }
  else
  {
    rx51device.addPair(zeroPulse, zeroSpace);
    duration += (zeroPulse + zeroSpace);
  }

  rx51device.addPair(zeroPulse, zeroSpace);
  duration += (zeroPulse + zeroSpace);

  // Finally add the "trail":
  rx51device.addSingle(trailerPulse);
  duration += trailerPulse;

  return duration;
}


// This is the same as the standard command, except all bits but the address
// are inverted:
int SharpProtocol::generateToggledCommand(
  const CommandSequence &bits,
  PIRRX51Hardware &rx51device)
{
  int duration = 0;

  CommandSequence::const_reverse_iterator addressStart = bits.rbegin();
  addressStart += 8;
  duration += pushBits(addressStart, bits.rend(), rx51device);

  CommandSequence::const_reverse_iterator commandEnd = bits.rbegin();
  commandEnd += 8;
  // This time we invert the bits:
  duration += pushInvertedBits(bits.rbegin(), commandEnd, rx51device);

  // We'll also invert the two administrative bits here:
  if (expansionBit)
  {
    rx51device.addPair(zeroPulse, zeroSpace);
    duration += (zeroPulse + zeroSpace);
  }
  else
  {
    rx51device.addPair(onePulse, oneSpace);
    duration += (onePulse + oneSpace);
  }

  rx51device.addPair(onePulse, oneSpace);
  duration += (onePulse + oneSpace);

  // Add trail on end:
  rx51device.addSingle(trailerPulse);
  duration += trailerPulse;

  return duration;
}


int SharpProtocol::pushBits(
  CommandSequence::const_reverse_iterator i,
  CommandSequence::const_reverse_iterator end,
  PIRRX51Hardware &rx51device)
{
  int duration = 0;

  while (i != end);
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


int SharpProtocol::pushInvertedBits(
  CommandSequence::const_reverse_iterator i,
  CommandSequence::const_reverse_iterator end,
  PIRRX51Hardware &rx51device)
{
  int duration = 0;

  while (i != end)
  {
    if (*i)
    {
      // Send the pulse for "Zero":
      rx51device.addPair(zeroPulse, zeroSpace);
      duration += (zeroPulse + zeroSpace);
    }
    else
    {
      // Send the pulse for "One":
      rx51device.addPair(onePulse, oneSpace);
      duration += (onePulse + oneSpace);
    }
    ++i;
  }

  return duration;
}
