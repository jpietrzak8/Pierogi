//
// sharpprotocol.h
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

#ifndef SHARPPROTOCOL_H
#define SHARPPROTOCOL_H

#include "spaceprotocol.h"

class PIRInfraredLED;

//
// Sharp has its own protocol.  It is "space-encoded", like the popular NEC
// protocol (i.e., a 1 takes longer to transmit than a 0), but differs in
// several ways.  Most notably, the entire command section of the pulse
// train is inverted for each odd-numbered repetition.  Also, there is no
// header pulse.
//

class SharpProtocol: public SpaceProtocol
{
  Q_OBJECT

public:
  SharpProtocol(
    QObject *guiObject,
    unsigned int index,
    bool expBit);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);

private:
  // An "expansion bit".  Not sure what this is, but Sharp seems to leave it
  // at 1, and Denon usually sets it to 0.
  bool expansionBit;

  int generateStandardCommand(
    const PIRKeyBits &pkb,
    PIRInfraredLED &led);

  int generateToggledCommand(
    const PIRKeyBits &pkb,
    PIRInfraredLED &led);
};

#endif // SHARPPROTOCOL_H
