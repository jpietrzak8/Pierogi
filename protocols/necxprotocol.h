//
// necxprotocol.h
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

#ifndef NECXPROTOCOL_H
#define NECXPROTOCOL_H

#include "spaceprotocol.h"

class PIRInfraredLED;

//
// The "NECX" protocol is a slight variation on the popular NEC protocol.
// It includes the "short repeat" feature of NEC, but implements it in a
// slightly different way.
//

class NECXProtocol: public SpaceProtocol
{
  Q_OBJECT

public:
  NECXProtocol(
    QObject *guiObject,
    unsigned int index,
    bool srtRep);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);

private:
  bool isShortRepeat;

  int generateStandardCommand(
    const PIRKeyBits &bits,
    PIRInfraredLED &led);

  int generateRepeatCommand(
    PIRInfraredLED &led);
};

#endif // NECXPROTOCOL_H
