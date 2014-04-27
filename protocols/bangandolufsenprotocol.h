//
// bangandolufsenprotocol.h
//
// Copyright 2014 by John Pietrzak (jpietrzak8@gmail.com)
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

#ifndef BANGANDOLUFSENPROTOCOL_H
#define BANGANDOLUFSENPROTOCOL_H

#include "spaceprotocol.h"

class PIRInfraredLED;

//
// The Bang & Olufsen protocol is a unique protocol dreamed up by the
// B&O folks themselves.  It has a number of intriguing features, as well
// as a number of annoying ones...
//

enum BandOBit
{
  BandONo_Bit,
  BandOZero_Bit,
  BandOOne_Bit
};

class BangAndOlufsenProtocol: public SpaceProtocol
{
  Q_OBJECT

public:
  BangAndOlufsenProtocol(
    QObject *guiObject,
    unsigned int index);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);

private:
  int generateCommand(
    const PIRKeyBits &pkb,
    PIRInfraredLED &led);

  int pushBandOBits(
    const CommandSequence &bits,
    PIRInfraredLED &led);

  unsigned int sameAsPreviousPulse;
  unsigned int sameAsPreviousSpace;

  BandOBit previousBit;
};

#endif // BANGANDOLUFSENPROTOCOL_H
