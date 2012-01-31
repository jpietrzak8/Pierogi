#include "jvcprotocol.h"

#include "pirexception.h"
#include <string>
//#include <iostream>

// Some global communications stuff:
#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// The JVC protocol should have the following attributes:
// A "zero" is encoded with a 526 usec pulse, 52626 usec space.
// A "one" is encoded with a 526 usec pulse, and 3*526 (1578) usec space.
// The header is a 8400 usec pulse, 4200 usec space.
// Commands end with a trailing 526 usec pulse.
// Commands are repeated by re-sending entire command without the header.
// Repeats are broadcast every 60000 usec.
// The carrier frequency is 38 kHz, duty cycle is 1/3.

JVCProtocol::JVCProtocol(
  QObject *guiObject,
  unsigned int index)
  : PIRProtocol(guiObject, index, 60000, true),
    zeroPulse(526),
    zeroSpace(526),
    onePulse(526),
    oneSpace(1578),
    headerPulse(8400),
    headerSpace(4200),
    trailerPulse(526)
{
  setCarrierFrequency(38000);
  setDutyCycle(33);
}


void JVCProtocol::startSendingCommand(
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
      // If we are currently repeating, and have a special "repeat signal",
      // use that signal.  Otherwise, generate a normal command string.
      if (repeatCount)
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


// JVC data is sent in reverse order, i.e., the least signficant bit is
// sent first.
int JVCProtocol::generateStandardCommand(
  const CommandSequence &bits,
  PIRRX51Hardware &rx51device)
{
  int duration = 0;

  // First, the "header" pulse:
  rx51device.addPair(headerPulse, headerSpace);
  duration += (headerPulse + headerSpace);

  // Now, push the actual data:
  duration += pushReverseBits(preData, rx51device);
  duration += pushReverseBits(bits, rx51device);

  // Finally add the "trail":
  rx51device.addSingle(trailerPulse);
  duration += trailerPulse;

  return duration;
}


int JVCProtocol::generateHeadlessCommand(
  const CommandSequence &bits,
  PIRRX51Hardware &rx51device)
{
  int duration = 0;

  // Push the actual data:
  duration += pushReverseBits(preData, rx51device);
  duration += pushReverseBits(bits, rx51device);

  // Finally add the "trail":
  rx51device.addSingle(trailerPulse);
  duration += trailerPulse;

  return duration;
}


int JVCProtocol::pushReverseBits(
  const CommandSequence &bits,
  PIRRX51Hardware &rx51device)
{
  int duration = 0;
  CommandSequence::const_reverse_iterator i = bits.rbegin();
  while (i != bits.rend())
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

