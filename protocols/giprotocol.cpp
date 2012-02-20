#include "giprotocol.h"

#include "pirrx51hardware.h"

#include "pirexception.h"

// Some global communications stuff:
#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// This G.I./Motorola protocol appears to have the following specifications:
// A "zero" is encoded with a 500 usec pulse, 2250 usec space.
// A "one" is encoded with a 500 usec pulse, and 4500 usec space.
// The header is a 9000 usec pulse, 4500 usec space.
// Commands end with a trailing 500 usec pulse.
// A repeat block is a 9000 usec pulse, 2250 usec space, then a trailing pulse.
// Each command runs for 100000 usec before another can be executed.
// The carrier frequency is 38 kHz.

GIProtocol::GIProtocol(
  QObject *guiObject,
  unsigned int index)
  : SpaceProtocol(
      guiObject, index,
      500, 2250,
      500, 4500,
      9000, 4500,
      500,
      100000, true),
    repeatPulse(9000),
    repeatSpace(2250)
{
}


void GIProtocol::startSendingCommand(
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
      // If we are currently repeating, send a repeat block.
      if (repeatCount)
      {
        commandDuration = generateRepeatCommand(rx51device);
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


int GIProtocol::generateStandardCommand(
  const PIRKeyBits &pkb,
  PIRRX51Hardware &rx51device)
{
  int duration = 0;

  // First, the "header" pulse:
  rx51device.addPair(headerPulse, headerSpace);
  duration += (headerPulse + headerSpace);

  // The GI protocol consists of a 4-bit device code and an 8-bit command.
  // These are sent in reverse order.  Finally, a checksum is added at the
  // end.  I am lacking enough information to calculate the checksum right
  // now, so I'm going to dump all 16 bits into the "firstCode" in MSB
  // order, and reverse them here:

  duration += pushReverseBits(pkb.firstCode, rx51device);

  // Finally add the "trail":
  rx51device.addSingle(trailerPulse);
  duration += trailerPulse;

  return duration;
}


int GIProtocol::generateRepeatCommand(
  PIRRX51Hardware &rx51device)
{
  int duration = 0;

  // Add the repeat pulse:
  rx51device.addPair(repeatPulse, repeatSpace);
  duration += (repeatPulse + repeatSpace);

  // Add the trailer:
  rx51device.addSingle(trailerPulse);
  duration += trailerPulse;

  return duration;
}

