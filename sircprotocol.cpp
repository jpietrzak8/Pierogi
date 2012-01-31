#include "sircprotocol.h"

#include "pirexception.h"
#include <string>
//#include <iostream>

// Some global communications stuff:
#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// The SIRC protocol should have the following attributes:
// A "zero" is encoded with a 600 usec pulse, 600 usec space.
// A "one" is encoded with a 1200 usec pulse, and 600 usec space.
// The header is a 2400 usec pulse, 600 usec space.
// There is no trailing pulse.
// When repeating a command, the entire train is re-broadcast every 45000 usec.
// The carrier frequency is 40 kHz, duty cycle is 1/3.

SIRCProtocol::SIRCProtocol(
  QObject *guiObject,
  unsigned int index)
  : PIRProtocol(guiObject, index, 45000, true),
    zeroPulse(600),
    zeroSpace(600),
    onePulse(1200),
    oneSpace(600),
    headerPulse(2400),
    headerSpace(600)
{
  setCarrierFrequency(40000);
  setDutyCycle(33);
}


void SIRCProtocol::startSendingCommand(
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
      commandDuration = generateStandardCommand((*i).second, rx51device);

      // Now, tell the device to send the whole command:
      rx51device.sendCommandToDevice();

      // sleep until the next repetition of command:
      sleepUntilRepeat(commandDuration);

      // Check whether we've reached the minimum required number of repetitons:
//      if (repeatCount >= minimumRepetitions)
      if (repeatCount >= 3)
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


int SIRCProtocol::generateStandardCommand(
  const CommandSequence &bits,
  PIRRX51Hardware &rx51device)
{
  int duration = 0;

  // First, the "header" pulse:
  rx51device.addPair(headerPulse, headerSpace);
  duration += (headerPulse + headerSpace);

  // Next, push the data.  Each key _must_ contain all 12, 15, or 20 bits.
  // These bits are sent in reverse order.
  duration += pushReverseBits(bits, rx51device);

  return duration;
}


int SIRCProtocol::pushReverseBits(
  const CommandSequence &bits,
  PIRRX51Hardware &rx51device)
{
  int duration = 0;
  CommandSequence::const_reverse_iterator i = bits.rbegin();
  while (i != bits.rend())
  {
    if (*i)
    {
      // Send the pulse for "One":
      rx51device.addPair(onePulse, oneSpace);
      duration += (onePulse + oneSpace);
    }
    else
    {
      // Send the pulse for "Zero":
      rx51device.addPair(zeroPulse, zeroSpace);
      duration += (zeroPulse + zeroSpace);
    }
    ++i;
  }

  return duration;
}

