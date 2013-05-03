#include "mitsubishiprotocol.h"

#include "pirrx51hardware.h"

#include "pirexception.h"

// Some global communications stuff:
#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// The "Mitsubishi protocol" is very simple (and perhaps very old), and seems
// to consist of the following:
// A "zero" is encoded with a 300 usec pulse, 3*300 (900) usec space.
// A "one" is encoded with a 300 usec pulse, 7*300 (2100) usec space.
// There is no header.
// Commands end with a trailing 300 usec pulse.
// When repeating, the entire command is re-sent.
// There is an 80*300 (24000) usec gap between commands.
// The carrier frequency is 32 kHz.

MitsubishiProtocol::MitsubishiProtocol(
  QObject *guiObject,
  unsigned int index)
  : SpaceProtocol(
      guiObject, index,
      300, 900,
      300, 2100,
      0, 0,
      300,
      24000, false)
{
}


void MitsubishiProtocol::startSendingCommand(
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

    QMutexLocker cifLocker(&commandIFMutex);
    commandInFlight = false;
  }
  catch (PIRException e)
  {
    // inform the gui:
    emit commandFailed(e.getError().c_str());
  }
}


int MitsubishiProtocol::generateCommand(
  const PIRKeyBits &pkb,
  PIRRX51Hardware &rx51device)
{
  int duration = 0;

  // For this protocol, the device code and command code are both 8 bits,
  // and sent in LSB order:
  duration += pushReverseBits(preData, rx51device);
  duration += pushReverseBits(pkb.firstCode, rx51device);

  // Finally add the "trail" bit:
  rx51device.addSingle(trailerPulse);
  duration += trailerPulse;

  return duration;
}
