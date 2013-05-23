//
// rc6skyprotocol.h
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

#ifndef RC6SKYPROTOCOL_H
#define RC6SKYPROTOCOL_H

#include "pirprotocol.h"

class PIRInfraredLED;

//
// The Sky protocol is a fairly close implementation of RC6 mode 6.
//

class RC6SkyProtocol: public PIRProtocol
{
public:
  RC6SkyProtocol(
    QObject *guiObject,
    unsigned int index);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);

private:
  int pushBits(
    const CommandSequence &bits,
    PIRInfraredLED &led);

  int pushZero(
    PIRInfraredLED &led);

  int pushOne(
    PIRInfraredLED &led);

  unsigned int biphaseUnit;

  unsigned int buffer;
  int keypressCount;

  bool bufferContainsSpace;
  bool bufferContainsPulse;
};

#endif // RC6SKYPROTOCOL_H 
