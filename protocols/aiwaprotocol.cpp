#include "aiwaprotocol.h"

#include "pirrx51hardware.h"

#include "pirexception.h"
#include <string>

// Some global communications stuff:
#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// My information on the Aiwa protocol is that it has the following attributes:
// A "zero" is encoded with a 550 usec pulse, 550 usec space.
// A "one" is encoded with a 550 usec pulse, 1650 (3 * 550) usec space.
// The header has a 8800 usec pulse, 4400 usec space.
// There is a 550 usec trailing pulse.
// Repeat blocks are 8800 usec pulse, 4400 usec space, then trailing pulse.
// Each command lasts for 108000 usec.
// Carrier frequency is 38 kHz; I'm using 50% for the duty cycle, for now.

AiwaProtocol::AiwaProtocol(
  QObject *guiObject,
  unsigned int index)
  : SpaceProtocol(
      guiObject, index,
      550, 550,
      550, 1650,
      8800, 4400,
      550,
      108000, true),
    repeatPulse(8800),
    repeatSpace(2250)
{
  setCarrierFrequency(38000);
//  setDutyCycle(50);
}


void AiwaProtocol::startSendingCommand(
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
      // If we are currently repeating, send the repeat block:
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


int AiwaProtocol::generateStandardCommand(
  const PIRKeyBits &pkb,
  PIRRX51Hardware &rx51device)
{
  int duration = 0;

  // First, the "header" pulse:
  rx51device.addPair(headerPulse, headerSpace);
  duration += (headerPulse + headerSpace);

  // From the information I've got, the "address" portion of the Aiwa protocol
  // might be split into 8-bit device and 5-bit subdevice subsections, but
  // for now, I'm just lumping both into a single 13-bit address value.
  // The command is an 8-bit value.
  // As with NEC, the address is sent LSB first, then inverted LSB first,
  // then the command is sent LSB first, then inverted LSB first.
  duration += pushReverseBits(preData, rx51device);
  duration += pushInvertedReverseBits(preData, rx51device);
  duration += pushReverseBits(pkb.firstCode, rx51device);
  duration += pushInvertedReverseBits(pkb.firstCode, rx51device);

  // Finally add the "trail":
  rx51device.addSingle(trailerPulse);
  duration += trailerPulse;

  return duration;
}


int AiwaProtocol::generateRepeatCommand(
  PIRRX51Hardware &rx51device)
{
  int duration = 0;

  // Add the repeat pulse:
  rx51device.addPair(repeatPulse, repeatSpace);
  duration += (repeatPulse + repeatSpace);

  // Finally add the trailer:
  rx51device.addSingle(trailerPulse);
  duration += trailerPulse;

  return duration;
}
