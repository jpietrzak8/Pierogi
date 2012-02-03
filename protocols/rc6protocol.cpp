#include "rc6protocol.h"

#include "pirexception.h"

#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// These defines might need to be turned into variables, for odd devices.
#define HEADER_PULSE 2666
#define HEADER_SPACE 889
#define TRAILER_PULSE 889
#define TRAILER_SPACE 889

// I'm requiring standard RC6 initialization to include the 8-bit control
// section:
RC6Protocol::RC6Protocol(
  QObject *guiObject,
  unsigned int index,
  unsigned int eightBitControl)
  : PIRProtocol(guiObject, index, 108000, true),
    biphaseUnit(444),
    buffer(0),
    keypressCount(0)
{
  setCarrierFrequency(36000);
  setPreData(eightBitControl, 8);
}


void RC6Protocol::startSendingCommand(
  unsigned int threadableID,
  PIRKeyName command)
{
  try
  {
    // Is this command meant for us?
    if (threadableID != id) return;

    clearRepeatFlag();

    KeycodeCollection::const_iterator i = keycodes.find(command);

    // Sanity check:
    if (i == keycodes.end())
    {
      std::string s = "Tried to send a non-existent command.\n";
      throw PIRException(s);
    }

    PIRRX51Hardware rx51device(carrierFrequency, dutyCycle);

    int repeatCount = 0;
    int duration = 0;
    while (repeatCount < MAX_REPEAT_COUNT)
    {
      // First, construct the "Header" segment of the pulse train.  For now,
      // I'm only supporting the "consumer electronics mode" of RC6; this code
      // must be changed if we want to support more than that!
      //
      // The header involves:
      // a) a "lead" of 2666 us pulse, 889 us space;
      // b) a "start bit", value 1 (so 444 us pulse, 444 us space)
      // c) three control bits, always set to 0 (so 444 us space,
      //    444 us pulse each)
      // d) the double-sized "trailer" bit, toggled on each keypress (so
      //    either 889 pulse 889 space, or 889 space 889 pulse)

      rx51device.addSingle(HEADER_PULSE); // lead pulse
      duration += HEADER_PULSE;
      rx51device.addSingle(HEADER_SPACE); // lead space
      duration += HEADER_SPACE;
      rx51device.addSingle(biphaseUnit); // start bit pulse
      duration += biphaseUnit;

      // start bit space + control bit 1 space:
      rx51device.addSingle(2 * biphaseUnit);
      duration += 2 * biphaseUnit;
      rx51device.addSingle(biphaseUnit); // bit 1 pulse;
      duration += biphaseUnit;
      rx51device.addSingle(biphaseUnit); // bit 2 space;
      duration += biphaseUnit;
      rx51device.addSingle(biphaseUnit); // bit 2 pulse;
      duration += biphaseUnit;
      rx51device.addSingle(biphaseUnit); // bit 3 space;
      duration += biphaseUnit;

      // Next, need to check whether we should toggle or not:
      if (keypressCount % 2)
      {
        // bit 3 pulse plus long trailer bit pulse:
        rx51device.addSingle(3 * biphaseUnit);
        duration += 3 * biphaseUnit;

        // load the trailer bit space onto the buffer:
        buffer = 2 * biphaseUnit;
        bufferContainsSpace = true;
        bufferContainsPulse = false;
      }
      else
      {
        rx51device.addSingle(biphaseUnit); // bit three pulse
        duration += biphaseUnit;
        rx51device.addSingle(2 * biphaseUnit); // trailer bit space
        duration += 2 * biphaseUnit;

        // load the trailer bit pulse onto the buffer:
        buffer = 2 * biphaseUnit;
        bufferContainsPulse = true;
        bufferContainsSpace = false;
      }

      // Now, we can start the normal buffering process:

      // push any pre-data onto the device:
      duration += pushBits(preData, rx51device);

      // push the actual command:
      duration += pushBits((*i).second.firstCode, rx51device);

      // Flush out the buffer, if necessary:
      if (buffer)
      {
        rx51device.addSingle(buffer);
        duration += buffer;
        buffer = 0;
      }

      // Actually send out the command:
      rx51device.sendCommandToDevice();

      // Sleep for an amount of time.  (RC6 demands an addtional 6 unit space
      // at the end of any command...)
      sleepUntilRepeat(duration + 6 * biphaseUnit);

      // Have we been told to stop yet?
      if (checkRepeatFlag())
      {
        // Yes, we can now quit repeating:
        ++keypressCount;
        QMutexLocker ciflocker(&commandIFMutex);
        commandInFlight = false;
        return;
      }
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


int RC6Protocol::pushBits(
  const CommandSequence &bits,
  PIRRX51Hardware &rx51device)
{
  int bitsDuration = 0;

  CommandSequence::const_iterator i = bits.begin();
  bool bitValue;

  while (i != bits.end())
  {
    bitValue = *i;

    // In RC6, a "0" is represented by a space followed by a pulse,
    // and a "1" is represented by a pulse followed by a space.
    if (bitValue)
    {
      // This is a 1, so add a pulse, then a space.
      // First, the pulse:
      if (bufferContainsPulse)
      {
        rx51device.addSingle(buffer + biphaseUnit);
        bitsDuration += (buffer + biphaseUnit);
        buffer = 0;
        bufferContainsPulse = false;
      }
      else
      {
        if (bufferContainsSpace)
        {
          // Flush the buffer:
          rx51device.addSingle(buffer);
          bitsDuration += buffer;
          buffer = 0;
          bufferContainsSpace = false;
        }
        // Now, add the pulse:
        rx51device.addSingle(biphaseUnit);
        bitsDuration += biphaseUnit;
      }

      // Next, push a space onto the buffer:
      buffer = biphaseUnit;
      bufferContainsSpace = true;
    }
    else
    {
      // This is a 0, so add a space, then a pulse.
      if (bufferContainsSpace)
      {
        // Merge this space and the previous one, and send to device:
        rx51device.addSingle(buffer + biphaseUnit);
        bitsDuration += (buffer + biphaseUnit);
        buffer = 0;
        bufferContainsSpace = false;
      }
      else
      {
        if (bufferContainsPulse)
        {
          // Flush out the buffer:
          rx51device.addSingle(buffer);
          bitsDuration += buffer;
          buffer = 0;
          bufferContainsPulse = false;
        }

        // push a space onto the device:
        rx51device.addSingle(biphaseUnit);
        bitsDuration += biphaseUnit;
      }

      // Put a pulse into the buffer to wait:
      buffer = biphaseUnit;
      bufferContainsPulse = true;
    }

    ++i;
  }

  return bitsDuration;
}
