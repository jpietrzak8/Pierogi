//
// tdcprotocol.h
//
// Copyright 2012 - 2015 by John Pietrzak (jpietrzak8@gmail.com)
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

#ifndef TDCPROTOCOL_H
#define TDCPROTOCOL_H

#include "pirprotocol.h"

class PIRInfraredLED;

class TDCProtocol: public PIRProtocol
{
  Q_OBJECT

public:
  TDCProtocol(
    QObject *guiObject,
    unsigned int index,
    unsigned int deviceBits,
    unsigned int subdeviceBits);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);


private:
  int pushBits(
    const CommandSequence &bits,
    PIRInfraredLED &led);

  int pushBit(
    bool bitValue,
    PIRInfraredLED &led);

  unsigned int biphaseUnit;
  unsigned int buffer;
  bool bufferContainsSpace;
  bool bufferContainsPulse;
};

#endif // TDCPROTOCOL_H
