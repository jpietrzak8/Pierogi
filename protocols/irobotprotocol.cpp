#include "irobotprotocol.h"

#include "pirinfraredled.h"

#include "pirexception.h"

// Some global communications stuff:
#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// The iRobot (Roomba) protocol seems to be extremely simple.
// A "zero" is encoded with a 1000 usec pulse, 3000 usec space.
// A "one" is encoded with a 3000 usec pulse, 1000 usec space.
// So, it looks a little like a shift encoded protocol, even though it
// is space-encoded.
// There is no header and no trailer.
// Each command may run for 100000 usec (sources differ), but it looks like
// commands are not repeated at all...
// The carrier frequency is the usual 38 kHz.

IRobotProtocol::IRobotProtocol(
  QObject *guiObject,
  unsigned int index)
  : SpaceProtocol(
      guiObject, index,
      1000, 3000,
      3000, 1000,
      0, 0,
      0,
      100000, true)
{
}


void IRobotProtocol::startSendingCommand(
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
      // It looks like we only generate the command once, and remain
      // silent for the rest of the time the button is held down.  So, no
      // repeats.
      if (!repeatCount)
      {
        commandDuration = generateCommand((*i).second, led);

        // Tell the device to send the command:
        led.sendCommandToDevice();
      }

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


int IRobotProtocol::generateCommand(
  const PIRKeyBits &pkb,
  PIRInfraredLED &led)
{
  int duration = 0;

  // The protocol seems to involve 8 command bits, a 16000 usec pause, and
  // the same 8 bits repeated again.  So, we need to tack a 16000 usec
  // space on at the end of the first 8 bits, and just drop the last space
  // definition at the end of the second 8 bits:

  // The first 7 bits:
  int index = 0;
  CommandSequence::const_iterator i = pkb.firstCode.begin();
  while ((index < 7) && (i != pkb.firstCode.end()))
  {
    if (*i)
    {
      led.addPair(onePulse, oneSpace);
      duration += onePulse + oneSpace;
    }
    else
    {
      led.addPair(zeroPulse, zeroSpace);
      duration += zeroPulse + zeroSpace;
    }

    ++index;
    ++i;
  }

  // Eighth bit with extra space at the end:
  if (i != pkb.firstCode.end())
  {
    if (*i)
    {
      led.addPair(onePulse, oneSpace + 16000);
      duration += onePulse + oneSpace + 16000;
    }
    else
    {
      led.addPair(zeroPulse, zeroSpace + 16000);
      duration += zeroPulse + zeroSpace + 16000;
    }
  }

  // The following seven bits:
  index = 0;
  i = pkb.firstCode.begin();
  while ((index < 7) && (i != pkb.firstCode.end()))
  {
    if (*i)
    {
      led.addPair(onePulse, oneSpace);
      duration += onePulse + oneSpace;
    }
    else
    {
      led.addPair(zeroPulse, zeroSpace);
      duration += zeroPulse + zeroSpace;
    }

    ++index;
    ++i;
  }

  // The last half-bit:
  if (i != pkb.firstCode.end())
  {
    if (*i)
    {
      led.addSingle(onePulse);
      duration += onePulse;
    }
    else
    {
      led.addSingle(zeroPulse);
      duration += zeroPulse;
    }
  }

  return duration;
}
