//
// nokia32protocol.h
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

#ifndef NOKIA32PROTOCOL_H
#define NOKIA32PROTOCOL_H

#include "spaceprotocol.h"

class PIRInfraredLED;

//
// The Nokia32 protocol is a somewhat unusual 32-bit protocol.  It encodes
// pairs of bits rather than individual bits.
//

class Nokia32Protocol: public PIRProtocol
{
public:
  Nokia32Protocol(
    QObject *guiObject,
    unsigned int index);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);

private:
  int generateStandardCommand(
    const PIRKeyBits &bits,
    PIRInfraredLED &led);

  int pushBits(
    const CommandSequence &bits,
    PIRInfraredLED &led);

  int pushToggleAndBits(
    const CommandSequence &bits,
    PIRInfraredLED &led);

  int pushDoubleBit(
    bool firstBit,
    bool secondBit,
    PIRInfraredLED &led);

  unsigned int zeroPulse;
  unsigned int zeroSpace;
  unsigned int onePulse;
  unsigned int oneSpace;
  unsigned int twoPulse;
  unsigned int twoSpace;
  unsigned int threePulse;
  unsigned int threeSpace;

  unsigned int headerPulse;
  unsigned int headerSpace;

  unsigned int trailerPulse;

  unsigned int keypressCount;
};

#endif // NOKIA32PROTOCOL_H
