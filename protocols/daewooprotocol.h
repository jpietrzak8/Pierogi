//
// daewooprotocol.h
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

#ifndef DAEWOOPROTOCOL_H
#define DAEWOOPROTOCOL_H

#include "spaceprotocol.h"

class PIRInfraredLED;

//
// Daewoo is using something that looks like a simplified NEC protocol,
// lacking the inverted copy of the data that NEC sends, and with the addition
// of a marker bit sent inbetween the address and the command.
//

class DaewooProtocol: public SpaceProtocol
{
  Q_OBJECT

public:
  DaewooProtocol(
    QObject *guiObject,
    unsigned int index);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);

private:
  unsigned int midPulse;
  unsigned int midSpace;

  int generateStandardCommand(
    const PIRKeyBits &bits,
    PIRInfraredLED &led);
};

#endif // DAEWOOPROTOCOL_H
