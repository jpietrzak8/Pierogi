//
// canalsatprotocol.h
//
// Copyright 2013 by John Pietrzak (jpietrzak8@gmail.com)
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

#ifndef CANALSATPROTOCOL_H
#define CANALSATPROTOCOL_H

#include "pirprotocol.h"

class PIRInfraredLED;

//
// The CanalSat protocol is very similar to the RC5 protocol, but has a few
// differences.  (Most interestingly, the toggle bit is used to identify
// repeat frames, rather than to indicate separate key presses.)
//

class CanalSatProtocol: public PIRProtocol
{
public:
  CanalSatProtocol(
    QObject *guiObject,
    unsigned int index);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);

protected:
  unsigned int biphaseUnit;

private:
  int pushBits(
    const PIRKeyBits &pkb,
    int repeatCount,
    PIRInfraredLED &led);

  int pushBit(
    bool bitValue,
    PIRInfraredLED &led);

  unsigned int buffer;

  // Only one of the following can be true, but both can be false:
  bool bufferContainsSpace;
  bool bufferContainsPulse;
};

#endif // CANALSATPROTOCOL_H
