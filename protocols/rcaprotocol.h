//
// rcaprotocol.h
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

#ifndef RCAPROTOCOL_H
#define RCAPROTOCOL_H

#include "spaceprotocol.h"

class PIRInfraredLED;

//
// Although it is hard to find solid data on the RCA protocol, it seems
// fairly simple; it is really not that much different than the standard NEC
// protocol.  It differs in having only 4 bits of address, a different-sized
// header, it lays out the bits MSB first rather than LSB first, and it lays
// out both the address and the command before inverting both the address
// and command.
//

class RCAProtocol: public SpaceProtocol
{
public:
  RCAProtocol(
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
};

#endif // RCAPROTOCOL_H
