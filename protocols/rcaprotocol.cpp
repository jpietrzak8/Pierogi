#include "rcaprotocol.h"

#include "pirrx51hardware.h"
#include "pirexception.h"

// Some global communications stuff:
#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// I've found no official data on the RCA protocol yet, but from available
// notes and guesswork I'm using the following:
// A "zero" is encoded with a 500 usec pulse, 1000 usec space.
// A "one" is encoded with a 500 usec pulse, and 2000 usec space.
// The header is a 4000 usec pulse, 4000 usec space.
// Commands end with a trailing 500 usec pulse.
// When holding down a button, the entire command is repeated.
// Commands are repeated every 64000 usec.

// Each RCA word consists of 4 bits of address data and 8 bits of command data.
// The address is sent first, in order of most significant bit to least,
// followed by the command, also MSB to LSB.  Then, the same data is sent
// again, but with all the bits inverted.  (This is a bit different from
// how the NEC protocol does things.)

RCAProtocol::RCAProtocol(
  QObject *guiObject,
  unsigned int index)
  : SpaceProtocol(
      guiObject, index,
      500, 1000,
      500, 2000,
      4000, 4000,
      500,
      64000, true)
{
}


void RCAProtocol::startSendingCommand(
  unsigned int threadableID,
  PIRKeyName command)
{
  // Exceptions here are problematic; I'll try to weed them out by putting the
  // whole thing in a try/catch block:
  try
  {
    // First, check if we are meant to be the recipient of this command:
    if (threadableID != id) return;

    // An object that helps keep track of the number of commands:
//    PIRCommandCounter commandCounter;

    // Ok, we're going to lock down this method and make sure
    // only one guy at a time passes this point:
//    QMutexLocker commandLocker(&commandMutex);

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


int RCAProtocol::generateStandardCommand(
  const PIRKeyBits &pkb,
  PIRRX51Hardware &rx51device)
{
  int duration = 0;

  // First, the "header" pulse:
  rx51device.addPair(headerPulse, headerSpace);
  duration += (headerPulse + headerSpace);

  // Now, set up the address and command bits:
  duration += pushBits(preData, rx51device);
  duration += pushBits(pkb.firstCode, rx51device);
  duration += pushInvertedBits(preData, rx51device);
  duration += pushInvertedBits(pkb.firstCode, rx51device);

  // Finally add the "trail":
  rx51device.addSingle(trailerPulse);
  duration += trailerPulse;

  return duration;
}
