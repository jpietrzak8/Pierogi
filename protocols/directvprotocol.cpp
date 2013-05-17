#include "directvprotocol.h"

#include "pirinfraredled.h"

#include "pirexception.h"
#include <string>

// Some global communications stuff:
#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// Directv is using a protocol that is novel to me: each pulse and space
// encodes an entire bit in an of themselves.
// Here are the details I've got:
// For a 0 bit, a duration of 600 usecs is used.
// For a 1 bit, the duration is 1200 usecs.
// The header is a 6000 usec pulse, 1200 usec space.
// Commands end with a trailing 600 usec pulse.
// Commands are repeated by re-sending the entire pulse train, except that
// the header pulse is cut in half to 3000 usec.
// There are two different sizes of gap between commands: 9000 usec and
// 30000 usec.
// There are three different carrier frequencies: 38 kHz, 40 kHz, and 57 kHz.

DirectvProtocol::DirectvProtocol(
  QObject *guiObject,
  unsigned int index)
  : PIRProtocol(guiObject, index, 9000, false)
{
}


void DirectvProtocol::setProtocolParms(
  DirectvGapSize gap,
  DirectvFreq freq)
{
  if (gap == ShortGap_Directv)
  {
    setGapSize(9000, false);
  }
  else
  {
    setGapSize(30000, false);
  }

  switch (freq)
  {
  case LowFreq_Directv:
    setCarrierFrequency(38000);
    break;

  case MediumFreq_Directv:
    setCarrierFrequency(40000);
    break;

  case HighFreq_Directv: default:
    setCarrierFrequency(57000);
    break;
  }
}


void DirectvProtocol::startSendingCommand(
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
      // When repeating, we use a short-pulse header.  Otherwise, we use
      // a long-pulse header.
      if (repeatCount)
      {
        led.addPair(3000, 1200);
        commandDuration += 4200;
      }
      else
      {
        led.addPair(6000, 1200);
        commandDuration += 7200;
      }

      // Now, generate the rest of the command:
      commandDuration += generateStandardCommand((*i).second, led);

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


int DirectvProtocol::generateStandardCommand(
  const PIRKeyBits &pkb,
  PIRInfraredLED &led)
{
  int duration = 0;

  // DirecTV's protocol appears to consist of four bits of address data,
  // eight bits of command data, and four bits of checksum data.
  // The checksum is calculated off of the command, as so: Add up:
  // 7 * the first two bits of the command, plus
  // 5 * the second two bits of the command, plus
  // 3 * the third two bits of the command, plus
  // 1 * the last two bits of the command,
  // then just take the last four bits of this value.

  // - "preData" will contain the address
  // - "firstCode" will contain the command
  duration += pushDTVBits(preData, led);
  duration += pushDTVBits(pkb.firstCode, led);

  CommandSequence checksumBits;
  generateChecksum(pkb.firstCode, checksumBits);
  duration += pushDTVBits(checksumBits, led);

  // Finally add the "trail":
  led.addSingle(600);
  duration += 600;

  return duration;
}


int DirectvProtocol::pushDTVBits(
  const CommandSequence &bits,
  PIRInfraredLED &led)
{
  int duration = 0;
  CommandSequence::const_iterator i = bits.begin();
  while (i != bits.end())
  {
    if (*i)
    {
      // Send the value for "One":
      led.addSingle(1200);
      duration += 1200;
    }
    else
    {
      // Send the value for "Zero":
      led.addSingle(600);
      duration += 600;
    }
    ++i;
  }

  return duration;
}


void DirectvProtocol::generateChecksum(
  const CommandSequence &bits,
  CommandSequence &checksumBits)
{
  // We'll generate a 4-bit value based on the 8 bits of the command:

  int checksumVal = 0;

  CommandSequence::const_iterator i = bits.begin();

  if (i == bits.end()) return;

  if (*i) checksumVal += 14;

  ++i;

  if (i == bits.end()) return;

  if (*i) checksumVal += 7;

  ++i;

  if (i == bits.end()) return;

  if (*i) checksumVal += 10;

  ++i;

  if (i == bits.end()) return;

  if (*i) checksumVal += 5;

  ++i;

  if (i == bits.end()) return;

  if (*i) checksumVal += 6;

  ++i;

  if (i == bits.end()) return;

  if (*i) checksumVal += 3;

  ++i;

  if (i == bits.end()) return;

  if (*i) checksumVal += 2;

  ++i;

  if (i == bits.end()) return;

  if (*i) checksumVal += 1;

  // Push the last four bits into the command sequence:
  if (checksumVal & 0x8)  
  {
    checksumBits.push_back(1);
  }
  else
  {
    checksumBits.push_back(0);
  }

  if (checksumVal & 0x4)
  {
    checksumBits.push_back(1);
  }
  else
  {
    checksumBits.push_back(0);
  }

  if (checksumVal & 0x2)
  {
    checksumBits.push_back(1);
  }
  else
  {
    checksumBits.push_back(0);
  }

  if (checksumVal & 0x1)
  {
    checksumBits.push_back(1);
  }
  else
  {
    checksumBits.push_back(0);
  }
}
