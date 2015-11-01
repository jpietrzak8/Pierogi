//
// rc5protocol.h
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

#ifndef RC5PROTOCOL_H
#define RC5PROTOCOL_H

#include "pirprotocol.h"

class PIRInfraredLED;

//
// The RC5 protocol is not as widespread as the NEC protocol, but still
// somewhat popular.  Philips, the inventor, uses it extensively.
//

class RC5Protocol: public PIRProtocol
{
  Q_OBJECT

public:
  // For standard RC5, the control portion will be passed in as
  // a seven-bit value:
  RC5Protocol(
    QObject *guiObject,
    unsigned int index,
    unsigned int sevenBitControl);

  // For extended RC5, each key must contain the entire 13 bits.
  RC5Protocol(
    QObject *guiObject,
    unsigned int index);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);

protected:
  unsigned int biphaseUnit;

private:
  int pushControlBits(
    PIRInfraredLED &led);

  int pushKeyCommandBits(
    const PIRKeyBits &pkb,
    PIRInfraredLED &led);

  int pushNonStandardRC5(
    const PIRKeyBits &bits,
    PIRInfraredLED &led);

  int pushBit(
    bool bitValue,
    PIRInfraredLED &led);

  unsigned int buffer;
  int keypressCount;

  // Only one of the following can be true, but both can be false:
  bool bufferContainsSpace;
  bool bufferContainsPulse;
};

#endif // RC5PROTOCOL_H
