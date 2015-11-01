//
// kathreinprotocol.h
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

#ifndef KATHREINPROTOCOL_H
#define KATHREINPROTOCOL_H

#include "spaceprotocol.h"

class PIRInfraredLED;

//
// The Kathrein 24-bit protocol shares some features with the NEC protocol
// (space encoded, LSB order, sends complement of device and command codes),
// but has only a 4-bit address code, and uses a unique repeat mechanism.
//

class KathreinProtocol: public SpaceProtocol
{
  Q_OBJECT

public:
  KathreinProtocol(
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

  int generateRepeatCommand(
    const PIRKeyBits &bits,
    PIRInfraredLED &led);
};

#endif // KATHREINPROTOCOL_H
