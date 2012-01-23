#include "pirprotocol.h"

#include <QMutex>
#include <QMetaType>

#include <time.h>
#include <sstream>
#include <errno.h>
#include "pirexception.h"

// A flag for communicating with the main thread:
extern bool stopRepeatingFlag;
extern QMutex stopRepeatingMutex;

// Total of all running commands
extern bool commandInFlight;
extern QMutex commandIFMutex;

// From what I understand (mostly from reading LIRC config files), NEC
// protocol based remotes mostly use a frequency of 38000 units and a
// duty cycle of 50%.  They'll be set to these defaults here, and overridden
// as needed by child classes.

PIRProtocol::PIRProtocol(
  QObject *guiObject,
  unsigned int index,
  unsigned int gSpace,
  bool iclflag)
  : carrierFrequency(38000),
    dutyCycle(50),
    isConstantLength(iclflag),
    gap(gSpace),
    minimumRepetitions(0),
    id(index)
{
  qRegisterMetaType<PIRKeyName>("PIRKeyName");

  QObject::connect(
    guiObject,
    SIGNAL(buttonPressed(unsigned int, PIRKeyName)),
    this,
    SLOT(startSendingCommand(unsigned int, PIRKeyName)),
    Qt::QueuedConnection);

  QObject::connect(
    this,
    SIGNAL(commandFailed(const char *)),
    guiObject,
    SLOT(receivedExternalWarning(const char *)),
    Qt::QueuedConnection);
}


void PIRProtocol::addKey(
  PIRKeyName key,
  unsigned long command,
  unsigned int bits)
{
  // First, if key already exists, clear it out:
  KeycodeCollection::iterator i = keycodes.find(key);
  if (i != keycodes.end())
  {
    i->second.clear();
  }

  appendToBitSeq(keycodes[key], command, bits);
}


void PIRProtocol::setCarrierFrequency(
  unsigned int freq)
{
  carrierFrequency = freq;
}


void PIRProtocol::setDutyCycle(
  unsigned int dc)
{
  dutyCycle = dc;
}


void PIRProtocol::setMinimumRepetitions(
  unsigned int minrep)
{
  minimumRepetitions = minrep;
}


void PIRProtocol::setPreData(
  unsigned long data,
  unsigned int bits)
{
  // If the container is not empty, first clear it out:
  if (!preData.empty())
  {
    preData.clear();
  }

  appendToBitSeq(preData, data, bits);
}


void PIRProtocol::setPostData(
  unsigned long data,
  unsigned int bits)
{
  // If the container is not empty, first clear it out:
  if (!postData.empty())
  {
    postData.clear();
  }

  appendToBitSeq(postData, data, bits);
}


bool PIRProtocol::isCommandSupported(
  PIRKeyName command)
{
  return (keycodes.find(command) != keycodes.end());
}


void PIRProtocol::appendToBitSeq(
  CommandSequence &sequence,
  unsigned int bits,
  int significantBits)
{
  if (significantBits == 0)
  {
    // This is bad, but just return silently for now...
    return;
  }

  // For each bit in the char, append a 1 or a 0 into the sequence.
  // Starting with the largest bit, move forward one bit at a time:
  unsigned int currentBit = 1 << (significantBits - 1);

  do
  {
    if (bits & currentBit)
    {
      sequence.push_back(1);
    }
    else
    {
      sequence.push_back(0);
    }

    currentBit = currentBit >> 1;
  }
  while (currentBit > 0);
}


void PIRProtocol::clearRepeatFlag()
{
  QMutexLocker locker(&stopRepeatingMutex);
  stopRepeatingFlag = false;
}


bool PIRProtocol::checkRepeatFlag()
{
  QMutexLocker locker(&stopRepeatingMutex);
  return stopRepeatingFlag;
}


// Note that the following routine blindly sleeps for the amount of time
// specified by the LIRC config file.  The extra overhead of processing
// each command will mean that repeated commands will overshoot the config
// time by some amount.  We could improve accuracy by waiting a little less
// than the specified time, if we could get a good handle on how long the
// overhead is delaying the command...
#define PIEROGI_OVERHEAD_HACK 13260

void PIRProtocol::sleepUntilRepeat(
  int commandDuration)
{
  int microseconds;

  // If the LIRC config file specifies the flag "CONST_LENGTH", that means
  // the "gap" value is the exact amount of time to wait between kicking off
  // each command.  If not, then the "gap" needs to be added on to the total
  // time of the previous command to see how long to sleep.

  if (isConstantLength)
  {
    microseconds = (gap - commandDuration) - PIEROGI_OVERHEAD_HACK;
  }
  else
  {
    microseconds = gap - PIEROGI_OVERHEAD_HACK;
  }

  // Don't even bother sleeping if there's only a few microseconds:
  if (microseconds < 1000)
  {
    return;
  }

  timespec sleeptime;
  sleeptime.tv_sec = 0;
  sleeptime.tv_nsec = microseconds * 1000;

  timespec remainingtime;

  if (nanosleep(&sleeptime, &remainingtime) == -1)
  {
    std::stringstream ss;
    ss << "Problem while sleeping.\n";
    ss << "Trying to sleep for: " << microseconds << "\n";
    ss << "Nanosleep returned error: " << strerror(errno) << "\n";
    throw PIRException(ss.str());
  }
}
