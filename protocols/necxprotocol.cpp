#include "necxprotocol.h"

#include "pirinfraredled.h"

#include "pirexception.h"

// Some global communications stuff:
#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// The NECX protocol is a slight variation of the NEC protocol.  It features
// a slightly different header and a slightly different repeat mechanism.
// Most of them seem to use the "extended" address form, so for now I'll
// just use that as the default.
// Otherwise it is nearly identical:
// A "zero" is encoded with a 560 usec pulse, 560 usec space.
// A "one" is encoded with a 560 usec pulse, and 3*560 (1680) usec space.
// The header is a 4500 usec pulse, 4500 usec space.
// Commands end with a trailing 560 usec pulse.
// A repeat block (if used) is a 4500 usec pulse, 4500 usec space, then a 1
// (560 usec pulse, 1680 usec space), then the trailing pulse.
// Each command runs for 110000 usec before another can be executed.
// The carrier frequency is 38 kHz.

NECXProtocol::NECXProtocol(
  QObject *guiObject,
  unsigned int index,
  bool srtRep)
  : SpaceProtocol(
      guiObject, index,
      560, 560,
      560, 1680,
      4500, 4500,
      560,
      110000, true),
    isShortRepeat(srtRep)
{
}


void NECXProtocol::startSendingCommand(
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
      // If we are currently repeating, and have a special "repeat signal",
      // use that signal.  Otherwise, generate a normal command string.
      if (isShortRepeat && repeatCount)
      {
        commandDuration = generateRepeatCommand(led);
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


int NECXProtocol::generateStandardCommand(
  const PIRKeyBits &pkb,
  PIRInfraredLED &led)
{
  int duration = 0;

  // First, the "header" pulse:
  led.addPair(headerPulse, headerSpace);
  duration += (headerPulse + headerSpace);

  // In NECX, the address is 16 bits, and is only sent once.  The command
  // portion is 8 bits, and an inverted copy is sent.
  // - "preData" should contain 16-bit value
  // - "bits" should contain 8-bit value
  duration += pushReverseBits(preData, led);
  duration += pushReverseBits(pkb.firstCode, led);
  duration += pushInvertedReverseBits(pkb.firstCode, led);

  // Finally add the "trail":
  led.addSingle(trailerPulse);
  duration += trailerPulse;

  return duration;
}


int NECXProtocol::generateRepeatCommand(
  PIRInfraredLED &led)
{
  int duration = 0;

  // Start with the header:
  led.addPair(headerPulse, headerSpace);
  duration += (headerPulse + headerSpace);

  // Add a "1":
  led.addPair(onePulse, oneSpace);
  duration += (onePulse + oneSpace);

  // Add the trailer:
  led.addSingle(trailerPulse);
  duration += trailerPulse;

  return duration;
}
