//
// jvcprotocol.h
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

#ifndef JVCPROTOCOL_H
#define JVCPROTOCOL_H

#include "spaceprotocol.h"

class PIRInfraredLED;

//
// JVC has its own protocol, similar in some ways to the popular NEC protocol.
// The main differences are that the address and command segments are not
// sent with an inverted copy, and that repeats are implemented by sending
// the body without a header, rather than a header without a body.
//

class JVCProtocol: public SpaceProtocol
{
public:
  JVCProtocol(
    QObject *guiObject,
    unsigned int index);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);

private:
  int generateStandardCommand(
    const PIRKeyBits &pkb,
    PIRInfraredLED &led);

  int generateHeadlessCommand(
    const PIRKeyBits &pkb,
    PIRInfraredLED &led);
};

#endif // JVCPROTOCOL_H
