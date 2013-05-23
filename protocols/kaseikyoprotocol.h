//
// kaseikyoprotocol.h
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

#ifndef KASEIKYOPROTOCOL_H
#define KASEIKYOPROTOCOL_H

#include "spaceprotocol.h"

class PIRInfraredLED;

//
// The Kaseikyo protocol is a more complex protocol than NEC or RC5 (although
// not nearly reaching the level of RC6).  I don't have enough information on
// it yet to understand all of its workings.
//

class KaseikyoProtocol: public SpaceProtocol
{
public:
  KaseikyoProtocol(
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

  void generateChecksum(
    const CommandSequence &bits,
    CommandSequence &checksum);

  void generateLittleChecksum(
    const CommandSequence &firstBits,
    const CommandSequence &secondBits,
    CommandSequence &littleChecksum);
};

#endif // KASEIKYOPROTOCOL_H
