//
// samsungacprotocol.h
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

#ifndef SAMSUNGACPROTOCOL_H
#define SAMSUNGACPROTOCOL_H

#include "spaceprotocol.h"

class PIRInfraredLED;

class SamsungACProtocol: public SpaceProtocol
{
public:
  SamsungACProtocol(
    QObject *guiObject,
    unsigned int index);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);

  void startSendingStateInfo(
    PIRACStateInfo state,
    unsigned int threadableID,
    PIRKeyName command);

private:
  void generateCommand(
    PIRInfraredLED &led);

  void calculateChecksum(
    CommandSequence &checksum);

  void generateTimerCommand(
    PIRInfraredLED &led);

  void calculateTimerChecksum(
    CommandSequence &checksum);

  // Standard state info:
  CommandSequence swing;
  CommandSequence turbo;
  CommandSequence temperature;
  CommandSequence fan;
  CommandSequence mode;
  CommandSequence airclean;
  CommandSequence power;

  // Timer state info (and some kluges):
  CommandSequence timerOption;
  CommandSequence timerHours;
  CommandSequence timerMinutes;
  CommandSequence timerHeader;
  CommandSequence emptyTimer;
  CommandSequence timerFooter;
  CommandSequence fourBitZero;
  int timerCommandType;
};

#endif //SAMSUNGACPROTOCOL_H
