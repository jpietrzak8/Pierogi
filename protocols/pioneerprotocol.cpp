#include "pioneerprotocol.h"

#include "pirrx51hardware.h"

#include "pirexception.h"
#include <string>
//#include <iostream>

// Some global communications stuff:
#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// Pioneer's protocol seems almost the same as standard NEC protocol, but
// a few details are slightly different.  (Can't seem to find exact details.)
// A "zero" is encoded with a 530 usec pulse, 530 usec space.
// A "one" is encoded with a 530 usec pulse, and 3*530 (1590) usec space.
// The header is a 8500 usec pulse, 4250 usec space.
// Commands end with a trailing 530 usec pulse.
// Commands are repeated by re-sending the entire pulse train.
// Each command is separated by 25000 usec.
// The carrier frequency is probably 40 kHz, duty cycle probably 50%.

PioneerProtocol::PioneerProtocol(
  QObject *guiObject,
  unsigned int index)
  : SpaceProtocol(
      guiObject, index,
      530, 530,
      530, 1590,
      8500, 4250,
      530,
      25000, false)
{
  setCarrierFrequency(40000);
  setDutyCycle(50);
}


void PioneerProtocol::startSendingCommand(
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
      // If we are on an odd repetition, and we have a secondary keycode,
      // we'll generate the secondary command for this key.  Otherwise,
      // we always generate a standard command.
      if ((repeatCount % 2) && (!(i->second.thirdCode.empty())))
      {
        commandDuration = generateSecondaryCommand(i->second, rx51device);
      }
      else
      {
        commandDuration = generateStandardCommand(i->second, rx51device);
      }

      // Now, tell the device to send the whole command:
      rx51device.sendCommandToDevice();

      // sleep until the next repetition of command:
      sleepUntilRepeat(commandDuration);

      // Check whether we've reached the minimum required number of repetitons:
//      if (repeatCount >= minimumRepetitions)
//      if (repeatCount >= 3)
//      {
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
//      }

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


int PioneerProtocol::generateStandardCommand(
  const PIRKeyBits &pkb,
  PIRRX51Hardware &rx51device)
{
  int duration = 0;

  // First, the "header" pulse:
  rx51device.addPair(headerPulse, headerSpace);
  duration += (headerPulse + headerSpace);

  // Now, the data, following standard NEC rules.  (Note that we are not
  // using the "preData" value here, most Pioneer devices require more than
  // one address value.  Therefore, I'm requiring all keys to explicitly
  // load the address value into the "firstCode" member.)
  duration += pushReverseBits(pkb.firstCode, rx51device);
  duration += pushInvertedReverseBits(pkb.firstCode, rx51device);
  duration += pushReverseBits(pkb.secondCode, rx51device);
  duration += pushInvertedReverseBits(pkb.secondCode, rx51device);

  // Finally add the "trail":
  rx51device.addSingle(trailerPulse);
  duration += trailerPulse;

  return duration;
}


int PioneerProtocol::generateSecondaryCommand(
  const PIRKeyBits &pkb,
  PIRRX51Hardware &rx51device)
{
  int duration = 0;

  // First, the "header" pulse:
  rx51device.addPair(headerPulse, headerSpace);
  duration += (headerPulse + headerSpace);

  // Now, the data, following standard NEC rules.  (The secondary command
  // uses the third and fourth key codes.)
  duration += pushReverseBits(pkb.thirdCode, rx51device);
  duration += pushInvertedReverseBits(pkb.thirdCode, rx51device);
  duration += pushReverseBits(pkb.fourthCode, rx51device);
  duration += pushInvertedReverseBits(pkb.fourthCode, rx51device);

  // Finally add the "trail":
  rx51device.addSingle(trailerPulse);
  duration += trailerPulse;

  return duration;
}
