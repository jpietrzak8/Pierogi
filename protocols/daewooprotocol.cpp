#include "daewooprotocol.h"

#include "pirrx51hardware.h"

#include "pirexception.h"

// Some global communications stuff:
#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// Daewoo is using a protocol similar to NEC, but with the distinction that
// it does not send inverted copies of the address and command, and it places
// a 550 usec pulse / 2000 usec space between the address and the command.
// Here are the fine details:
// A "zero" is encoded with a 550 usec pulse, 450 usec space.
// A "one" is encoded with a 550 usec pulse, and 1450 usec space.
// The header is a 8000 usec pulse, 4000 usec space.
// There is a mid-way marker of 550 usec pulse, 2000 usec space.
// The pulse train ends with a trailing 550 usec pulse.
// The entire train is resent for repeats.
// Each command runs for 60000 usec before another can be executed.
// The carrier frequency is 38 kHz.

DaewooProtocol::DaewooProtocol(
  QObject *guiObject,
  unsigned int index)
  : SpaceProtocol(
      guiObject, index,
      550, 450,
      550, 1450,
      8000, 4000,
      550,
      60000, true),
    midPulse(550),
    midSpace(2000)
{
}


void DaewooProtocol::startSendingCommand(
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


int DaewooProtocol::generateStandardCommand(
  const PIRKeyBits &pkb,
  PIRRX51Hardware &rx51device)
{
  int duration = 0;

  // First, the "header" pulse:
  rx51device.addPair(headerPulse, headerSpace);
  duration += (headerPulse + headerSpace);

  // The address data:
  duration += pushReverseBits(preData, rx51device);

  // The Daewoo mid-train marker:
  rx51device.addPair(midPulse, midSpace);
  duration += (midPulse + midSpace);

  // The command data:
  duration += pushReverseBits(pkb.firstCode, rx51device);

  // Finally add the "trail":
  rx51device.addSingle(trailerPulse);
  duration += trailerPulse;

  return duration;
}

