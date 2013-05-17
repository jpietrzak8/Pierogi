#include "kathreinprotocol.h"

#include "pirinfraredled.h"

#include "pirexception.h"

// Some global communications stuff:
#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// The Kathrein protocol is similar to the NEC protocol:
// A "zero" is encoded with a 560 usec pulse, 560 usec space.
// A "one" is encoded with a 560 usec pulse, and 3*560 (1680) usec space.
// The header is a 9000 usec pulse, 4500 usec space.
// Commands end with a trailing 560 usec pulse.
// The repeat block is unique -- it has the normal header and trailer, and
// includes the command code, but no address, and no complement.
// Each command runs for 110000 usec before another can be executed.
// The normal carrier frequency is 38 kHz.

KathreinProtocol::KathreinProtocol(
  QObject *guiObject,
  unsigned int index)
  : SpaceProtocol(
      guiObject, index,
      560, 560,
      560, 1680,
      9000, 4500,
      560,
      110000, true)
{
}


void KathreinProtocol::startSendingCommand(
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
    PIRInfraredLED led(carrierFrequency, dutyCycle);

    int repeatCount = 0;
    int commandDuration = 0;
    while (repeatCount < MAX_REPEAT_COUNT)
    {
      if (repeatCount)
      {
        commandDuration = generateRepeatCommand((*i).second, led);
      }
      else
      {
        commandDuration = generateStandardCommand((*i).second, led);
      }

      // Now, tell the device to send the whole command:
      led.sendCommandToDevice();

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


int KathreinProtocol::generateStandardCommand(
  const PIRKeyBits &pkb,
  PIRInfraredLED &led)
{
  int duration = 0;

  // First, the "header" pulse:
  led.addPair(headerPulse, headerSpace);
  duration += (headerPulse + headerSpace);

  // Kathrein protocol has four bits of address and eight bits of command.
  // As in NEC protocol, the address and command are complemented.
  // - "preData" should contain the 4-bit address
  // - "firstCode" should contain the 8-bit command
  duration += pushReverseBits(preData, led);
  duration += pushInvertedReverseBits(preData, led);
  duration += pushReverseBits(pkb.firstCode, led);
  duration += pushInvertedReverseBits(pkb.firstCode, led);

  // Finally add the "trail":
  led.addSingle(trailerPulse);
  duration += trailerPulse;

  return duration;
}


int KathreinProtocol::generateRepeatCommand(
  const PIRKeyBits &pkb,
  PIRInfraredLED &led)
{
  int duration = 0;

  // First, the "header" pulse:
  led.addPair(headerPulse, headerSpace);
  duration += (headerPulse + headerSpace);

  // The Kathrein repeat block contains the 8-bit command and nothing else:
  duration += pushReverseBits(pkb.firstCode, led);

  // Finally add the "trail":
  led.addSingle(trailerPulse);
  duration += trailerPulse;

  return duration;
}
