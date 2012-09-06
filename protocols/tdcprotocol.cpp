#include "tdcprotocol.h"

#include "pirrx51hardware.h"

#include "pirexception.h"

#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;


// There are apparently two forms of TDC protocol; I'm just focussing on one
// for now.  As with the Philips protocols, this one is "shift encoded".
// The unit biphase pulse length is 315 usec; each command contains 18 bits,
// and is followed by an 89000 usec space.  The entire pulse train is
// re-sent when repeating.  The carrier frequency is 38 kHz (the Pierogi
// default value).

// I'm going to count both the "device" and "subdevice" bits as pre-data.
// (Both are 5 bits in length.)  This may need to be changed...

TDCProtocol::TDCProtocol(
  QObject *guiObject,
  unsigned int index,
  unsigned int deviceBits,
  unsigned int subdeviceBits)
  : PIRProtocol(guiObject, index, 89000, false),
    biphaseUnit(315),
    buffer(0)
{
  // Bit of a hack to get the device and subdevice data in:
  setPreData(deviceBits, 5);
  setPostData(subdeviceBits, 5);
}


void TDCProtocol::startSendingCommand(
  unsigned int threadableID,
  PIRKeyName command)
{
  // Catch any exceptions here before they go up any further:
  try
  {
    // Check that this command is meant for us:
    if (threadableID != id) return;

    clearRepeatFlag();

    KeycodeCollection::const_iterator i = keycodes.find(command);

    // Sanity check:
    if (i == keycodes.end())
    {
      QMutexLocker cifLocker(&commandIFMutex);
      commandInFlight = false;
      return;
//      std::string s = "Tried to send a non-existent command.\n";
//      throw PIRException(s);
    }

    // Construct the object that communicates with the device driver:
    PIRRX51Hardware rx51device(carrierFrequency, dutyCycle);

    int repeatCount = 0;
    int commandDuration = 0;
    while (repeatCount < MAX_REPEAT_COUNT)
    {
      // Construct the actual command string.
      // The string always starts with a constant "1" bit:
      commandDuration += pushBit(true, rx51device);

      // Next, the device bits:
      commandDuration += pushBits(preData, rx51device);

      // Then, the subdevice bits:
      commandDuration += pushBits(postData, rx51device);

      // Finally, the command bits:
      commandDuration += pushBits((*i).second.firstCode, rx51device);

      // Clear out the buffer, if needed:
      if (buffer)
      {
        rx51device.addSingle(buffer);
        commandDuration += buffer;

        buffer = 0;
        bufferContainsSpace = false;
        bufferContainsPulse = false;
      }

      // Send the command:
      rx51device.sendCommandToDevice();

      // Sleep for the required amount of time.
      sleepUntilRepeat(commandDuration);

      // Check whether we've been told to stop:
      if (checkRepeatFlag())
      {
        // We shall stop:
        break;
/*
        QMutexLocker cifLocker(&commandIFMutex);
        commandInFlight = false;
        return;
*/
      }

      ++repeatCount;
    }

    QMutexLocker cifLocker(&commandIFMutex);
    commandInFlight = false;
  }
  catch (PIRException e)
  {
    emit commandFailed(e.getError().c_str());
  }
}


int TDCProtocol::pushBits(
  const CommandSequence &bits,
  PIRRX51Hardware &rx51device)
{
  int duration = 0;

  CommandSequence::const_iterator i = bits.begin();

  while (i != bits.end())
  {
    duration += pushBit(*i, rx51device);
    ++i;
  }

  return duration;
}


int TDCProtocol::pushBit(
  bool bitValue,
  PIRRX51Hardware &device)
{
  unsigned int duration = 0;
  // TDC encodes a "0" by using a space followed by a pulse,
  // and a "1" by using a pulse followed by a space.

  if (bitValue)
  {
    // We've got a "1".  First add a pulse, then a space.
    if (bufferContainsPulse)
    {
      // Merge our pulse with the previous one, and send them to the device:
      device.addSingle(buffer + biphaseUnit);
      duration += (buffer + biphaseUnit);
      buffer = 0;
      bufferContainsPulse = false;
    }
    else
    {
      if (bufferContainsSpace)
      {
        // Flush out the buffer:
        device.addSingle(buffer);
        duration += buffer;
        buffer = 0;
        bufferContainsSpace = false;
      }

      // Add a pulse:
      device.addSingle(biphaseUnit);
      duration += biphaseUnit;
    }

    // Put a space into the buffer to wait:
    buffer = biphaseUnit;
    bufferContainsSpace = true;
  }
  else
  {
    // We've got a "0".  First add a space, then a pulse.
    if (bufferContainsSpace)
    {
      // Merge our space with the previous space, and send them to
      // the device.
      device.addSingle(buffer + biphaseUnit);
      duration += (buffer + biphaseUnit);
      buffer = 0;
      bufferContainsSpace = false;
    }
    else
    {
      if (bufferContainsPulse)
      {
        // Flush the buffer:
        device.addSingle(buffer);
        duration += buffer;
        buffer = 0;
        bufferContainsPulse = false;
      }
      // Add a space:
      device.addSingle(biphaseUnit);
      duration += biphaseUnit;
    }

    // Put a pulse into the buffer to wait.
    buffer = biphaseUnit;
    bufferContainsPulse = true;
  }

  return duration;
}
