//
// pirprotocol.h
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

#ifndef PIRPROTOCOL_H
#define PIRPROTOCOL_H

// The generic remote controller.

#include <QObject>
#include "pirkeynames.h"
#include "piracstateinfo.h"

#include <map>
#include <deque>

// We'll define a maximum number of repetitions, regardless of how long the
// user presses the button.  (This is just in case we miss the point at which
// he stops pressing it...)  500 should be plenty.
#define MAX_REPEAT_COUNT 500

typedef std::deque<bool> CommandSequence;

// As I've learned more about IR protocols, the concept of what a specific
// key is gets more and more complex.  To deal with this, I'm going to allow
// a key to have more than one command sequence associated with it.  (I need
// up to three codes for Sony keys, and as many as four to define an
// individual Pioneer key.)
class PIRKeyBits
{
public:
  CommandSequence firstCode;
  CommandSequence secondCode;
  CommandSequence thirdCode;
  CommandSequence fourthCode;
};

// I'll go ahead and use associative arrays to build up lists of keycodes.
typedef std::map<int, PIRKeyBits> KeycodeCollection;


// Right now, the only reason for this object to inherit from QObject is
// so it can participate in Qt-style threading.  Note that it has no
// event loop, and no access to the GUI, so don't go trying to communicate
// with the user here...
class PIRProtocol: public QObject
{
  Q_OBJECT

public:
  PIRProtocol(
    QObject *guiObject,
    unsigned int index,
    unsigned int gSpace,
    bool iclflag);

  unsigned int getCarrierFrequency() const;

  void setCarrierFrequency(
    unsigned int cf);

  unsigned int getDutyCycle() const;

  void setDutyCycle(
    unsigned int dc);

  void addKey(
    PIRKeyName key,
    unsigned long data,
    unsigned int size);

  // A special addKey used for Sony's SIRC protocol:
  void addSIRCKey(
    PIRKeyName key,
    unsigned int addressData,
    unsigned int size,
    unsigned int commandData);

  void addSIRC20Key(
    PIRKeyName key,
    unsigned int secondaryAddressData,
    unsigned int primaryAddressData,
    unsigned int commandData);

  void addSharpKey(
    PIRKeyName key,
    unsigned int addressData,
    unsigned int commandData);

  void addNECKey(
    PIRKeyName key,
    unsigned int addressData,
    unsigned int commandData);

  void addPanOldKey(
    PIRKeyName key,
    unsigned int addressData,
    unsigned int commandData);

  void addPioneerKey(
    PIRKeyName key,
    unsigned int firstAddress,
    unsigned int firstCommand,
    unsigned int secondAddress,
    unsigned int secondCommand);

/*
  void addRCAKey(
    PIRKeyName key,
    unsigned int addressData,
    unsigned int commandData);
*/

  void addKaseikyoKey(
    PIRKeyName key,
    unsigned int addressData,
    unsigned int commandData);

  void addDishKey(
    PIRKeyName key,
    unsigned int firstCommand,
    unsigned int secondCommand);

  void addXMPKey(
    PIRKeyName key,
    unsigned int firstCommand,
    unsigned int secondCommand);

  void setMinimumRepetitions(
    unsigned int minrep);

  void setPreData(
    unsigned long data,
    unsigned int bits);

  void setPostData(
    unsigned long data,
    unsigned int bits);

public slots:
  virtual void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command) = 0;

  // This slot can be ignored by most non-ac protocols:
  virtual void startSendingStateInfo(
    PIRACStateInfo state,
    unsigned int threadableID,
    PIRKeyName command);

signals:
  void commandFailed(
    const char *errString);

protected:
  bool isCommandSupported(
    PIRKeyName command);

  void clearRepeatFlag();
  bool checkRepeatFlag();

  unsigned int carrierFrequency;
  unsigned int dutyCycle;

  void appendToBitSeq(
    CommandSequence &bits,
    unsigned int code,
    int size);

  KeycodeCollection keycodes;

  // A sleep function for all protocols:
  void sleepUntilRepeat(
    int commandDuration);

  // The "gap" parameter from LIRC.  If the commands are "variable-length",
  // this indicates the amount of time between the last pulse of one
  // command and the first pulse of the next.  If "constant-length", it is
  // the time between the _first_ pulse of one command and the first pulse
  // of the next.

  void setGapSize(
    int gapSize,
    bool iclFlag);

  bool isConstantLength;
  int gap;

  // More administrative data wrapped around the actual command:
  CommandSequence preData;
  CommandSequence postData;

  // Some remotes require a minimum number of repetitions:
  // Note: thinking about removing this -- don't know if it is needed
  int minimumRepetitions;

  unsigned int id;
};

#endif // PIRPROTOCOL_H
