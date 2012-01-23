#include "rc5protocol.h"

#include "pirexception.h"

#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

RC5Protocol::RC5Protocol(
  QObject *guiObject,
  unsigned int index,
  unsigned int bPulse,
  unsigned int bSpace,
  unsigned int lPulse,
  unsigned int gSpace,
  bool iclflag)
  : PIRProtocol(guiObject, index, gSpace, iclflag),
    biphasePulse(bPulse),
    biphaseSpace(bSpace),
    leadPulse(lPulse),
    buffer(0),
    keypressCount(0)
{
}


void RC5Protocol::setHeaderPair(
  unsigned int pulse,
  unsigned int space)
{
  headerPulse = pulse;
  headerSpace = space;
  hasHeaderPair = true;
}


void RC5Protocol::setToggleBit(
  unsigned int bit)
{
  toggleBit = bit;
}


void RC5Protocol::startSendingCommand(
  unsigned int threadableID,
  PIRKeyName command)
{
  // Dumping entire method inside of try/catch, to deal with cross-thread
  // exception handling:
  try
  {
    // Check if this command is meant for us:
    if (threadableID != id) return;

    clearRepeatFlag();

    KeycodeCollection::const_iterator i = keycodes.find(command);

    // Sanity check, make sure command exists first:
    if (i == keycodes.end())
    {
      std::string s = "Tried to send a non-existent command.\n";
      throw PIRException(s);
    }

    // Construct the object that communicates with the device driver:
    PIRRX51Hardware rx51device(carrierFrequency, dutyCycle);

    int repeatCount = 0;
    while (repeatCount < MAX_REPEAT_COUNT)
    {
      int commandDuration = 0;

      // Now, throw together an RC5 protocol command string:
      buffer = 0;
      bufferContainsPulse = false;
      bufferContainsSpace = false;
  
      // Start off the first pulse with the lead, if any:
      if (leadPulse)
      {
        buffer = leadPulse;
        bufferContainsPulse = true;
      }

      // Encode the bits:
      commandDuration += pushBits((*i).second, rx51device);

      // Clear out the buffer, if necessary:
      if (buffer)
      {
        rx51device.addSingle(buffer);
        commandDuration += buffer;
        buffer = 0;
        bufferContainsSpace = false;
        bufferContainsPulse = false;
      }

      // Now, tell the device to send the whole command:
      rx51device.sendCommandToDevice();

      // Sleep for an amount of time.  (Need to make this interruptable!)
      sleepUntilRepeat(commandDuration);

      // Have we satisfied the minimum number of repetitions?
      if (repeatCount >= minimumRepetitions)
      {
        // Have we been told to stop yet?
        if (checkRepeatFlag())
        {
          // Ok, then we can quit now:
          ++keypressCount;
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
    emit commandFailed(e.getError().c_str());
  }

  ++keypressCount;
  QMutexLocker cifLocker(&commandIFMutex);
  commandInFlight = false;
}


int RC5Protocol::pushBits(
  const CommandSequence &bits,
  PIRRX51Hardware &rx51device)
{
  int bitsDuration = 0;

  // Rather than encoding a 0 or 1 through the timing of a pulse, RC5 encodes
  // a bit by swapping the order of pulses and spaces.  (This is called
  // "biphase".)

  CommandSequence::const_iterator i = bits.begin();
  int bitCount = 1;
  bool bitValue;

  while (i != bits.end())
  {
    bitValue = *i;

    if (bitCount == toggleBit)  // are we on a toggled bit?
    {
      if (keypressCount % 2)  // is it time to toggle?
      {
        bitValue = !bitValue;  // then flip the bit
      }
    }

    if (bitValue)
    {
      // We've got a "1".  First add a space, then a pulse.
      if (bufferContainsSpace)
      {
        // Merge our space with the previous space, and send them to
        // the device.
        rx51device.addSingle(buffer + biphaseSpace);
        bitsDuration += (buffer + biphaseSpace);
        buffer = 0;
        bufferContainsSpace = false;
      }
      else
      {
        if (bufferContainsPulse)
        {
          // Flush the buffer:
          rx51device.addSingle(buffer);
          bitsDuration += buffer;
          buffer = 0;
          bufferContainsPulse = false;
        }
        // Add a space:
        rx51device.addSingle(biphaseSpace);
        bitsDuration += biphaseSpace;
      }

      // Put a pulse into the buffer to wait.
      buffer = biphasePulse;
      bufferContainsPulse = true;
    }
    else
    {
      // We've got a "0".  First add a pulse, then a space.
      if (bufferContainsPulse)
      {
        // Merge our pulse with the previous one, and send them to the device:
        rx51device.addSingle(buffer + biphasePulse);
        bitsDuration += (buffer + biphasePulse);
        buffer = 0;
        bufferContainsPulse = false;
      }
      else
      {
        if (bufferContainsSpace)
        {
          // Flush out the buffer:
          rx51device.addSingle(buffer);
          bitsDuration += buffer;
          buffer = 0;
          bufferContainsSpace = false;
        }

        // Add a pulse:
        rx51device.addSingle(biphasePulse);
        bitsDuration += biphasePulse;
      }

      // Put a space into the buffer to wait:
      buffer = biphaseSpace;
      bufferContainsSpace = true;
    }

    ++i;
    ++bitCount;
  }

  return bitsDuration;
}
