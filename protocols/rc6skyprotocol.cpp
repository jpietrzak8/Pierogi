#include "rc6skyprotocol.h"

#include "pirinfraredled.h"

#include "pirexception.h"

#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// These defines might need to be turned into variables, for odd devices.
#define HEADER_PULSE 2666
#define HEADER_SPACE 888
#define TRAILER_BIPHASE 888

// This version of Mode 6 RC6 is used in Sky and Sky+ receivers.  It seems to
// be pretty close to vanilla RC6.
// The biphase unit of time is 444 usec.
// The RC6 header block starts with the normal 2666 usec pulse, 888 usec space.
// The next bit is fixed as a "1", as usual.
// The next three bits are 110, marking this as a mode 6 protocol.
// The trailer bit has an 888 usec biphase.  It is normally a toggle bit, but
// for Sky, it appears to be fixed at "0".
// Next comes 8 bits of address, 4 bits I don't know about (subdevice?),
// and finally 8 bits of command.
// A space of (at least) 2666 usec must follow any command.
// The carrier frequency is 36 kHZ, duty cycle between 25 and 50 %.

RC6SkyProtocol::RC6SkyProtocol(
  QObject *guiObject,
  unsigned int index)
  : PIRProtocol(guiObject, index, 2666, false),
    biphaseUnit(444),
    buffer(0),
    keypressCount(0)
{
  setCarrierFrequency(36000);
}


void RC6SkyProtocol::startSendingCommand(
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
      QMutexLocker cifLocker(&commandIFMutex);
      commandInFlight = false;
      return;
//      std::string s = "Tried to send a non-existent command.\n";
//      throw PIRException(s);
    }

    PIRInfraredLED led(carrierFrequency, dutyCycle);

    int repeatCount = 0;
    int duration = 0;
    while (repeatCount < MAX_REPEAT_COUNT)
    {
      bufferContainsSpace = false;
      bufferContainsPulse = false;
      // First, construct the "Header" segment of the pulse train.
      //
      // The header involves:
      // a) a "lead" of 2666 us pulse, 888 us space;
      // b) a "start bit", value 1 (so 444 us pulse, 444 us space)
      // c) three control bits, set to "110" (i.e., mode "6")
      // d) the double-sized "trailer" bit, set based on the keypress count:
      // d2) I'm trying out setting the toggle bit to always be 0.

      led.addSingle(HEADER_PULSE); // lead pulse
      duration += HEADER_PULSE;
      led.addSingle(HEADER_SPACE); // lead space
      duration += HEADER_SPACE;
      led.addSingle(biphaseUnit); // start bit pulse
      duration += biphaseUnit;
      led.addSingle(biphaseUnit); // start bit space
      duration += biphaseUnit;
      led.addSingle(biphaseUnit); // bit 1 pulse;
      duration += biphaseUnit;
      led.addSingle(biphaseUnit); // bit 1 space;
      duration += biphaseUnit;
      led.addSingle(biphaseUnit); // bit 2 pulse;
      duration += biphaseUnit;
      led.addSingle(2 * biphaseUnit); // bit 2 space + bit 3 space;
      duration += 2 * biphaseUnit;
      led.addSingle(biphaseUnit); // bit 3 pulse;
      duration += biphaseUnit;
      led.addSingle(2 * biphaseUnit); // trailer space
      duration += 2 * biphaseUnit;
      buffer = 2 * biphaseUnit; // trailer pulse goes into the buffer
      bufferContainsPulse = true;

      // Now, we can start the normal buffering process:

      // push the address data:
      duration += pushBits(preData, led);

      // push the command data:
      duration += pushBits((*i).second.firstCode, led);

      // Flush out the buffer, if necessary:
      if (buffer)
      {
        led.addSingle(buffer);
        duration += buffer;
        buffer = 0;
      }

      // Actually send out the command:
      led.sendCommandToDevice();

      // Sleep for an amount of time.  (RC6 demands an addtional 6 unit space
      // at the end of any command...)
      sleepUntilRepeat(duration + 6 * biphaseUnit);

      // Have we been told to stop yet?
      if (checkRepeatFlag())
      {
        // Yes, we can now quit repeating:
        break;
/*
        ++keypressCount;
        QMutexLocker ciflocker(&commandIFMutex);
        commandInFlight = false;
        return;
*/
      }
    }

    ++keypressCount;
    QMutexLocker cifLocker(&commandIFMutex);
    commandInFlight = false;
  }
  catch (PIRException e)
  {
    emit commandFailed(e.getError().c_str());
  }
}


int RC6SkyProtocol::pushBits(
  const CommandSequence &bits,
  PIRInfraredLED &led)
{
  int duration = 0;

  CommandSequence::const_iterator i = bits.begin();

  while (i != bits.end())
  {
    if (*i)
    {
      duration += pushOne(led);
    }
    else
    {
      duration += pushZero(led);
    }

    ++i;
  }

  return duration;
}


// This should be part of a general RC6 parent maybe?
int RC6SkyProtocol::pushZero(
  PIRInfraredLED &led)
{
  // Need to add a space, then a pulse.
  int duration = 0;

  if (bufferContainsSpace)
  {
    // Merge this space and the previous one, and send to device:
    led.addSingle(buffer + biphaseUnit);
    duration += (buffer + biphaseUnit);
    buffer = 0;
     bufferContainsSpace = false;
  }
  else
  {
    if (bufferContainsPulse)
    {
      // Flush out the buffer:
      led.addSingle(buffer);
      duration += buffer;
      buffer = 0;
      bufferContainsPulse = false;
    }

    // push a space onto the device:
    led.addSingle(biphaseUnit);
    duration += biphaseUnit;
  }

  // Put a pulse into the buffer to wait:
  buffer = biphaseUnit;
  bufferContainsPulse = true;

  return duration;
}


int RC6SkyProtocol::pushOne(
  PIRInfraredLED &led)
{
  // Need to add a pulse, then a space.
  int duration = 0;

  // First, the pulse:
  if (bufferContainsPulse)
  {
    led.addSingle(buffer + biphaseUnit);
    duration += (buffer + biphaseUnit);
    buffer = 0;
    bufferContainsPulse = false;
  }
  else
  {
    if (bufferContainsSpace)
    {
      // Flush the buffer:
      led.addSingle(buffer);
      duration += buffer;
      buffer = 0;
      bufferContainsSpace = false;
    }
    // Now, add the pulse:
    led.addSingle(biphaseUnit);
    duration += biphaseUnit;
  }

  // Next, push a space onto the buffer:
  buffer = biphaseUnit;
  bufferContainsSpace = true;

  return duration;
}
