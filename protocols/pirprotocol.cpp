//
// pirprotocol.cpp
//
// Copyright 2012, 2013 by John Pietrzak (jpietrzak8@gmail.com)
//
// This file is part of Pierogi.
//
// Pierogi is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// Pierogi is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//

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

// Check if a command is running:
//extern bool commandInFlight;
//extern QMutex commandIFMutex;

// From what I understand (mostly from reading LIRC config files), NEC
// protocol based remotes mostly use a frequency of 38000 units and a
// duty cycle of 33%.  They'll be set to these defaults here, and overridden
// as needed by child classes.

PIRProtocol::PIRProtocol(
  QObject *guiObject,
  unsigned int index,
  unsigned int gSpace,
  bool iclflag)
  : carrierFrequency(38000),
    dutyCycle(33),
    isConstantLength(iclflag),
    gap(gSpace),
    minimumRepetitions(0),
    id(index)
{
  qRegisterMetaType<PIRKeyName>("PIRKeyName");
  qRegisterMetaType<PIRACStateInfo>("PIRACStateInfo");

  QObject::connect(
    guiObject,
    SIGNAL(buttonPressed(unsigned int, PIRKeyName)),
    this,
    SLOT(startSendingCommand(unsigned int, PIRKeyName)),
    Qt::QueuedConnection);

  QObject::connect(
    guiObject,
    SIGNAL(buttonPressed(PIRACStateInfo, unsigned int, PIRKeyName)),
    this,
    SLOT(startSendingStateInfo(PIRACStateInfo, unsigned int, PIRKeyName)),
    Qt::QueuedConnection);

  QObject::connect(
    this,
    SIGNAL(commandFailed(const char *)),
    guiObject,
    SLOT(receivedExternalWarning(const char *)),
    Qt::QueuedConnection);
}


unsigned int PIRProtocol::getCarrierFrequency() const
{
  return carrierFrequency;
}


void PIRProtocol::setCarrierFrequency(
  unsigned int cf)
{
  carrierFrequency = cf;
}


unsigned int PIRProtocol::getDutyCycle() const
{
  return dutyCycle;
}


void PIRProtocol::setDutyCycle(
  unsigned int dc)
{
  dutyCycle = dc;
}


void PIRProtocol::addKey(
  PIRKeyName key,
  unsigned long command,
  unsigned int size)
{
  // First, if key already exists, clear it out:
  PIRKeyBits *pkb = 0;
  KeycodeCollection::iterator i = keycodes.find(key);
  if (i != keycodes.end())
  {
    pkb = &(i->second);
    pkb->firstCode.clear();
  }
  else
  {
    pkb = &(keycodes[key]);
  }

  appendToBitSeq(pkb->firstCode, command, size);
}


void PIRProtocol::addSIRCKey(
  PIRKeyName key,
  unsigned int addressData,
  unsigned int size,
  unsigned int commandData)
{
  // First, if key already exists, clear it out:
  PIRKeyBits *pkb = 0;
  KeycodeCollection::iterator i = keycodes.find(key);
  if (i != keycodes.end())
  {
    pkb = &(i->second);
    pkb->firstCode.clear();
    pkb->secondCode.clear();
    pkb->thirdCode.clear();
  }
  else
  {
    pkb = &(keycodes[key]);
  }

  // First, append the address data:
  appendToBitSeq(pkb->firstCode, addressData, size);

  // Next, the command data.  The size is always 7 bits:
  appendToBitSeq(pkb->secondCode, commandData, 7);
}


void PIRProtocol::addSIRC20Key(
  PIRKeyName key,
  unsigned int secondaryAddressData,
  unsigned int primaryAddressData,
  unsigned int commandData)
{
  // First, if key already exists, clear it out:
  PIRKeyBits *pkb = 0;
  KeycodeCollection::iterator i = keycodes.find(key);
  if (i != keycodes.end())
  {
    pkb = &(i->second);
    pkb->firstCode.clear();
    pkb->secondCode.clear();
    pkb->thirdCode.clear();
  }
  else
  {
    pkb = &(keycodes[key]);
  }

  // First, append the secondary address data:
  appendToBitSeq(pkb->firstCode, secondaryAddressData, 8);

  // Next, the primary address data:
  appendToBitSeq(pkb->secondCode, primaryAddressData, 5);

  // Next, the command data.  The size is always 7 bits:
  appendToBitSeq(pkb->thirdCode, commandData, 7);
}


void PIRProtocol::addSharpKey(
  PIRKeyName key,
  unsigned int addressData,
  unsigned int commandData)
{
  // First, if key already exists, clear it out:
  PIRKeyBits *pkb = 0;
  KeycodeCollection::iterator i = keycodes.find(key);
  if (i != keycodes.end())
  {
    pkb = &(i->second);
    pkb->firstCode.clear();
    pkb->secondCode.clear();
  }
  else
  {
    pkb = &(keycodes[key]);
  }

  // Sharp commands are all 5 bit address, 8 bit command:
  appendToBitSeq(pkb->firstCode, addressData, 5);
  appendToBitSeq(pkb->secondCode, commandData, 8);
}


void PIRProtocol::addNECKey(
  PIRKeyName key,
  unsigned int addressData,
  unsigned int commandData)
{
  PIRKeyBits *pkb = 0;
  KeycodeCollection::iterator i = keycodes.find(key);
  if (i != keycodes.end())
  {
    pkb = &(i->second);
    pkb->firstCode.clear();
    pkb->secondCode.clear();
    pkb->thirdCode.clear();
    pkb->fourthCode.clear();
  }
  else
  {
    pkb = &(keycodes[key]);
  }

  // NEC commands should always be 8 bits address, 8 bits command:
  appendToBitSeq(pkb->firstCode, addressData, 8);
  appendToBitSeq(pkb->secondCode, commandData, 8);
}


void PIRProtocol::addPanOldKey(
  PIRKeyName key,
  unsigned int addressData,
  unsigned int commandData)
{
  PIRKeyBits *pkb = 0;
  KeycodeCollection::iterator i = keycodes.find(key);
  if (i != keycodes.end())
  {
    pkb = &(i->second);
    pkb->firstCode.clear();
    pkb->secondCode.clear();
    pkb->thirdCode.clear();
    pkb->fourthCode.clear();
  }
  else
  {
    pkb = &(keycodes[key]);
  }

  // The "Old Panasonic" commands have 5 bits address, 6 bits command:
  appendToBitSeq(pkb->firstCode, addressData, 5);
  appendToBitSeq(pkb->secondCode, commandData, 6);
}


// Most Pioneer keys use the NEC key format, but some are pairs of
// NEC keys sent together:
void PIRProtocol::addPioneerKey(
  PIRKeyName key,
  unsigned int firstAddress,
  unsigned int firstCommand,
  unsigned int secondAddress,
  unsigned int secondCommand)
{
  PIRKeyBits *pkb = 0;
  KeycodeCollection::iterator i = keycodes.find(key);
  if (i != keycodes.end())
  {
    pkb = &(i->second);
    pkb->firstCode.clear();
    pkb->secondCode.clear();
    pkb->thirdCode.clear();
    pkb->fourthCode.clear();
  }
  else
  {
    pkb = &(keycodes[key]);
  }

  // All four codes should be 8 bits in length:
  appendToBitSeq(pkb->firstCode, firstAddress, 8);
  appendToBitSeq(pkb->secondCode, firstCommand, 8);
  appendToBitSeq(pkb->thirdCode, secondAddress, 8);
  appendToBitSeq(pkb->fourthCode, secondCommand, 8);
}


/*
void PIRProtocol::addRCAKey(
  PIRKeyName key,
  unsigned int addressData,
  unsigned int commandData)
{
  PIRKeyBits *pkb = 0;
  KeycodeCollection::iterator i = keycodes.find(key);
  if (i != keycodes.end())
  {
    pkb = &(i->second);
    pkb->firstcode.clear();
    pkb->secondCode.clear();
  }
  else
  {
    pkb = &(keycodes[key]);
  }

  // Address is 4 bits, command is 8 bits:
  appendToBitSeq(pkb->firstCode, addressData, 4);
  appendToBitSeq(pkb->secondCode, commandData, 8);
}
*/


void PIRProtocol::addKaseikyoKey(
  PIRKeyName key,
  unsigned int addressData,
  unsigned int commandData)
{
  PIRKeyBits *pkb = 0;
  KeycodeCollection::iterator i = keycodes.find(key);
  if (i != keycodes.end())
  {
    pkb = &(i->second);
    pkb->firstCode.clear();
    pkb->secondCode.clear();
  }
  else
  {
    pkb = &(keycodes[key]);
  }

  appendToBitSeq(pkb->firstCode, addressData, 12);
  appendToBitSeq(pkb->secondCode, commandData, 8);
}


void PIRProtocol::addDishKey(
  PIRKeyName key,
  unsigned int firstCommand,
  unsigned int secondCommand)
{
  PIRKeyBits *pkb = 0;
  KeycodeCollection::iterator i = keycodes.find(key);
  if (i != keycodes.end())
  {
    pkb = &(i->second);
    pkb->firstCode.clear();
    pkb->secondCode.clear();
  }
  else
  {
    pkb = &(keycodes[key]);
  }

  appendToBitSeq(pkb->firstCode, firstCommand, 6);
  appendToBitSeq(pkb->secondCode, secondCommand, 5);
}


void PIRProtocol::addXMPKey(
  PIRKeyName key,
  unsigned int firstCommand,
  unsigned int secondCommand)
{
  PIRKeyBits *pkb = 0;
  KeycodeCollection::iterator i = keycodes.find(key);
  if (i != keycodes.end())
  {
    pkb = &(i->second);
    pkb->firstCode.clear();
    pkb->secondCode.clear();
  }
  else
  {
    pkb = &(keycodes[key]);
  }

  appendToBitSeq(pkb->firstCode, firstCommand, 8);
  appendToBitSeq(pkb->secondCode, secondCommand, 8);
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


void PIRProtocol::startSendingStateInfo(
  PIRACStateInfo state,
  unsigned int threadableID,
  PIRKeyName command)
{
  // This method can be ignored by most non-air-conditioner protocols.
}


bool PIRProtocol::isCommandSupported(
  PIRKeyName command)
{
  return (keycodes.find(command) != keycodes.end());
}


void PIRProtocol::appendToBitSeq(
  CommandSequence &sequence,
  unsigned int bits,
  int size)
{
  if (size == 0)
  {
    // This is bad, but just return silently for now...
    return;
  }

  // For each bit in the char, append a 1 or a 0 into the sequence.
  // Starting with the largest bit, move forward one bit at a time:
  unsigned int currentBit = 1 << (size - 1);

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

/*
  // Don't even bother sleeping if there's only a few microseconds:
  if (microseconds < 1000)
  {
    return;
  }
*/
  // For now, I'm going to enforce a minimum sleep of 10 ms, so that we
  // don't get runaway commands:
  if (microseconds < 10000)
  {
    microseconds = 10000;
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


void PIRProtocol::setGapSize(
  int gapSize,
  bool iclFlag)
{
  gap = gapSize;
  isConstantLength = iclFlag;
}
