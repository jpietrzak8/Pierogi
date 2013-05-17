#include "necprotocol.h"

#include "pirinfraredled.h"

#include "pirexception.h"

// Some global communications stuff:
#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// Debugging:
#include <iostream>

// The official NEC protocol, as I understand it, has the following attributes:
// A "zero" is encoded with a 560 usec pulse, 560 usec space.
// A "one" is encoded with a 560 usec pulse, and 3*560 (1680) usec space.
// The header is a 9000 usec pulse, 4500 usec space.
// Commands end with a trailing 560 usec pulse.
// A repeat block (if used) is a 9000 usec pulse, 2250 usec space, then
// trailing pulse.
// Each command runs for 110000 usec before another can be executed.
// The normal carrier frequency is 38 kHz.

NECProtocol::NECProtocol(
  QObject *guiObject,
  unsigned int index,
  bool extNEC,
  bool srtRep)
  : SpaceProtocol(
      guiObject, index,
      560, 560,
      560, 1680,
      9000, 4500,
      560,
      110000, true),
    repeatPulse(9000),
    repeatSpace(2250),
    isExtendedNEC(extNEC),
    isShortRepeat(srtRep)
{
  setMinimumRepetitions(1);
}


void NECProtocol::startSendingCommand(
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


int NECProtocol::generateStandardCommand(
  const PIRKeyBits &pkb,
  PIRInfraredLED &led)
{
  int duration = 0;

  // First, the "header" pulse:
  led.addPair(headerPulse, headerSpace);
  duration += (headerPulse + headerSpace);

  // Now, check the encoding format:
  if (isExtendedNEC)
  {
    // In extended NEC, the address has been extended to 16 bits, and is only
    // sent once.  The command portion stays the same.
    // - "preData" should contain 16-bit value
    // - "bits" should contain 8-bit value
    duration += pushReverseBits(preData, led);
    duration += pushReverseBits(pkb.firstCode, led);
    duration += pushInvertedReverseBits(pkb.firstCode, led);
  }
  else
  {
    // Standard NEC is made up of an eight-bit "address" and an eight-bit
    // "command".  First the address bits are sent (in reverse order), then
    // the address bits are inverted and sent again (in reverse order).
    // Next, we do the same to the command bits.
    // - "preData" should contain 8-bit value
    // - "bits" should contain 8-bit value
    duration += pushReverseBits(preData, led);
    duration += pushInvertedReverseBits(preData, led);
    duration += pushReverseBits(pkb.firstCode, led);
    duration += pushInvertedReverseBits(pkb.firstCode, led);
  }

  // Finally add the "trail":
  led.addSingle(trailerPulse);
  duration += trailerPulse;

  return duration;
}


int NECProtocol::generateRepeatCommand(
  PIRInfraredLED &led)
{
  int duration = 0;

  // Add the repeat pulse:
  led.addPair(repeatPulse, repeatSpace);
  duration += (repeatPulse + repeatSpace);

  // Add the trailer:
  led.addSingle(trailerPulse);
  duration += trailerPulse;

  return duration;
}
