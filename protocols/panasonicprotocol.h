//
// panasonicprotocol.h
//
// Copyright 2014 - 2015 by John Pietrzak (jpietrzak8@gmail.com)
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
// along with Pierogi; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//

#ifndef PANASONICPROTOCOL_H
#define PANASONICPROTOCOL_H

#include "spaceprotocol.h"

class PIRInfraredLED;

//
// This Panasonic protocol is similar to the "Kaseikyo" protocol, yet
// different.
//

class PanasonicProtocol: public SpaceProtocol
{
  Q_OBJECT

public:
  PanasonicProtocol(
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
    const CommandSequence &device,
    const CommandSequence &subdevice,
    const CommandSequence &command,
    CommandSequence &checksum);
};

#endif // PANASONICPROTOCOL_H
