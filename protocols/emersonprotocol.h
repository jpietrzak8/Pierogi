//
// emersonprotocol.h
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

#ifndef EMERSONPROTOCOL_H
#define EMERSONPROTOCOL_H

#include "spaceprotocol.h"

class PIRInfraredLED;

//
// The Emerson protocol is a fairly simple space-based protocol, except
// for the fact that some remote controls use multiple device codes.
//

class EmersonProtocol: public SpaceProtocol
{
public:
  EmersonProtocol(
    QObject *guiObject,
    unsigned int index,
    bool multiDevice);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);

private:
  bool hasMultipleDevCodes;

  int generateStandardCommand(
    const PIRKeyBits &bits,
    PIRInfraredLED &led);

  int generateMultiDevCommand(
    const PIRKeyBits &bits,
    PIRInfraredLED &led);
};

#endif // EMERSONPROTOCOL_H
