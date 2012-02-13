#include "thomsonprotocol.h"

#include "pirrx51hardware.h"

#include "pirexception.h"

// Some global communications stuff:
#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// This Thomson protocol is a very simple one:
// A "zero" is encoded with a 500 usec pulse, 2000 usec space.
// A "one" is encoded with a 500 usec pulse, and 4500 usec space.
// There is no header.
// Commands end with a trailing 500 usec pulse.
// When repeating, the full pulse train is re-sent.
// Each command runs for 80000 usec total.
// The carrier frequency should be 33 kHz, but I'm not so sure...

ThomsonProtocol::ThomsonProtocol(
  QObject *guiObject,
  unsigned int index)
  : SpaceProtocol(
      guiObject, index,
      500, 2000,
      500, 4500,
      0, 0,
      500,
      80000, true),
    keypressCount(0)
{
}


void ThomsonProtocol::startSendingCommand(
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
          ++keypressCount;
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

  ++keypressCount;
  QMutexLocker cifLocker(&commandIFMutex);
  commandInFlight = false;
}


int ThomsonProtocol::generateStandardCommand(
  const PIRKeyBits &pkb,
  PIRRX51Hardware &rx51device)
{
  int duration = 0;

  // First, four bits of address:
  duration += pushBits(preData, rx51device);

  // Next, the toggle bit:
  if (keypressCount % 2)
  {
    rx51device.addPair(onePulse, oneSpace);
    duration += (onePulse + oneSpace);
  }
  else
  {
    rx51device.addPair(zeroPulse, zeroSpace);
    duration += (zeroPulse + zeroSpace);
  }

  // Next, seven bits of command:
  duration += pushBits(pkb.firstCode, rx51device);

  // Finally add the "trail":
  rx51device.addSingle(trailerPulse);
  duration += trailerPulse;

  return duration;
}
