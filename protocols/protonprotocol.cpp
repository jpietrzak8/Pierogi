#include "protonprotocol.h"

#include "pirrx51hardware.h"

#include "pirexception.h"

// Some global communications stuff:
#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// The proton protocol seems fairly similar to the NEC protocol, although
// somewhat simplified.
// A "zero" is encoded with a 500 usec pulse, 500 usec space.
// A "one" is encoded with a 500 usec pulse, and 3*500 (1500) usec space.
// The header is a 8000 usec pulse, 4000 usec space.
// Commands end with a trailing 500 usec pulse.
// When repeating, the entire pulse-train is retransmitted.
// The duration of each full frame is 63000 usec.
// The normal carrier frequency is 38 kHz.

ProtonProtocol::ProtonProtocol(
  QObject *guiObject,
  unsigned int index)
  : SpaceProtocol(
      guiObject, index,
      500, 500,
      500, 1500,
      8000, 4000,
      500,
      63000, true)
{
}


void ProtonProtocol::startSendingCommand(
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
      commandDuration = generateStandardCommand((*i).second, rx51device);

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


int ProtonProtocol::generateStandardCommand(
  const PIRKeyBits &pkb,
  PIRRX51Hardware &rx51device)
{
  int duration = 0;

  // First, the "header" pulse:
  rx51device.addPair(headerPulse, headerSpace);
  duration += (headerPulse + headerSpace);

  // The Proton protocol contains an 8 bit address and an 8 bit command,
  // in LSB order.  Between these two is a gap made up of a 500 usec pulse
  // and a 4000 usec space.
  // - "preData" should contain the address.
  // - "firstCode" should contain the command.

  duration += pushReverseBits(preData, rx51device);

  rx51device.addPair(500, 4000);
  duration += 4500;

  duration += pushReverseBits(pkb.firstCode, rx51device);

  // Finally add the "trail":
  rx51device.addSingle(trailerPulse);
  duration += trailerPulse;

  return duration;
}

