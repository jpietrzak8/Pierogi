#include "paceprotocol.h"

#include "pirrx51hardware.h"

#include "pirexception.h"

// Some global communications stuff:
#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// The Pace protocol is fairly simple.  (Not sure I've got good data, though)
// A "zero" is encoded with a 630 usec pulse, 7*630 (4410) usec space.
// A "one" is encoded with a 630 usec pulse, 11*630 (6930) usec space.
// Different opinions exist on what is the header; I'm going to go with
//   a 630 usec pulse, 6930 usec space one.  Hope it works.
// Commands end with a trailing 630 usec pulse.
// Full pulse train is re-sent when repeating.
// Each command runs for 120000 usec.
// The carrier frequency is 38 kHz.

PaceProtocol::PaceProtocol(
  QObject *guiObject,
  unsigned int index)
  : SpaceProtocol(
      guiObject, index,
      630, 4410,
      630, 6930,
      630, 6930,
      500,
      120000, true),
    keypressCount(0)
{
}


void PaceProtocol::startSendingCommand(
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
          ++keypressCount;
          QMutexLocker cifLocker(&commandIFMutex);
          commandInFlight = false;
          return;
*/
        }
      }

      ++repeatCount;
    }

    ++keypressCount;
    QMutexLocker cifLocker(&commandIFMutex);
    commandInFlight = false;
  }
  catch (PIRException e)
  {
    // inform the gui:
    emit commandFailed(e.getError().c_str());
  }
}


// Pace seems to be going with a header pulse/space, a toggle bit, and nine
// more bits of data.  Information is sketchy, however.  I'll be going with
// three bits of pre-data (address?), and six bits of command...

int PaceProtocol::generateStandardCommand(
  const PIRKeyBits &pkb,
  PIRRX51Hardware &rx51device)
{
  int duration = 0;

  // First, the "header" pulse:
  rx51device.addPair(headerPulse, headerSpace);
  duration += (headerPulse + headerSpace);

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

  // Next, three bits of pre-data:
  duration += pushBits(preData, rx51device);

  // Next, six bits of data:
  duration += pushBits(pkb.firstCode, rx51device);

  // Finally add the "trail":
  rx51device.addSingle(trailerPulse);
  duration += trailerPulse;

  return duration;
}
