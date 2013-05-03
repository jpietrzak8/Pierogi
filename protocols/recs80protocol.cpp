#include "recs80protocol.h"

#include "pirrx51hardware.h"

#include "pirexception.h"

// Globals used for communications between threads:
#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// The info I have on the RECS80 protocol looks awfully strange; but, it's
// all that I've been able to find so far.  Here it is:
//
// (version "0045" of RECS80):
// A "zero" is encoded with a 158 usec pulse, and a 31 * 158 (4898) usec space.
// A "one" is encoded with a 158 usec pulse, and a 47 * 158 (7426) usec space.
// The header is a "one".
// Commands end with a trailing 158 usec pulse, followed by a 45000 usec space.
// The entire command sequence is resent while repeating.
// The carrier frequency is 38 kHz.


RECS80Protocol::RECS80Protocol(
  QObject *guiObject,
  unsigned int index)
  : SpaceProtocol(
      guiObject, index,
      158, 4898,
      158, 7426,
      158, 7426,
      158,
      45000, true),
    keypressCount(0)
{
}


void RECS80Protocol::startSendingCommand(
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
      commandDuration = generateCommand((*i).second, rx51device);

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


int RECS80Protocol::generateCommand(
  const PIRKeyBits &pkb,
  PIRRX51Hardware &rx51device)
{
  int duration = 0;

  // First, the "header" pulse:
  rx51device.addPair(headerPulse, headerSpace);
  duration += (headerPulse + headerSpace);

  // Next, a toggle bit:
  if (keypressCount % 2)
  {
    rx51device.addPair(zeroPulse, zeroSpace);
    duration += (zeroPulse + zeroSpace);
  }
  else
  {
    rx51device.addPair(onePulse, oneSpace);
    duration += (onePulse + oneSpace);
  }

  // Next, the device code and command code.  The device code is three
  // bits long; the command code is six bits long.  Both are sent inverted.
  duration += pushBits(preData, rx51device);
  duration += pushBits(pkb.firstCode, rx51device);

  // Finally, add the trailing pulse:
  rx51device.addSingle(trailerPulse);
  duration += trailerPulse;

  return duration;
}
