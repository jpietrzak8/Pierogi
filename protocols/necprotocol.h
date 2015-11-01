//
// necprotocol.h
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

#ifndef NECPROTOCOL_H
#define NECPROTOCOL_H

#include "spaceprotocol.h"

class PIRInfraredLED;

//
// The "NEC" Protocol is, more or less, followed by the majority of
// remotes defined in the LIRC config files, which means it is probably
// followed by most of the remotes out there.
//

//
// There exist two well-defined NEC protocols: "standard" and "extended".  The
// extended form sacrifices some redundancy to increase the size of the
// address data.
//
// Also, NEC has two types of repeat -- a "short repeat", sending only the
// header value, and a full repetition of the command pulse train.
//

class NECProtocol: public SpaceProtocol
{
  Q_OBJECT

public:
  NECProtocol(
    QObject *guiObject,
    unsigned int index,
    bool extNEC,
    bool srtRep);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);

private:
  unsigned int repeatPulse;
  unsigned int repeatSpace;

  bool isExtendedNEC;
  bool isShortRepeat;

  int generateStandardCommand(
    const PIRKeyBits &bits,
    PIRInfraredLED &led);

  int generateRepeatCommand(
    PIRInfraredLED &led);
};

#endif // NECPROTOCOL_H
