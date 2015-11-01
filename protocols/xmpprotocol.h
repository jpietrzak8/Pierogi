//
// xmpprotocol.h
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

#ifndef XMPPROTOCOL_H
#define XMPPROTOCOL_H

#include "pirprotocol.h"

class PIRInfraredLED;

//
// The XMP protocol is a large, fairly complex protocol, but seems to be
// gaining popularity in a variety of modern devices.
//

class XMPProtocol: public PIRProtocol
{
  Q_OBJECT

public:
  XMPProtocol(
    QObject *guiObject,
    unsigned int index,
    unsigned int sd1,
    unsigned int sd2,
    unsigned int oem,
    unsigned int d,
    bool hasFF);

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

  int generateFinalCommand(
    const PIRKeyBits &bits,
    PIRInfraredLED &led);

  unsigned int calculateChecksumOne();

  unsigned int calculateChecksumTwo(
    unsigned int toggle,
    const CommandSequence &firstCode,
    const CommandSequence &secondCode);

  int pushHalfByte(
    unsigned int halfByte,
    PIRInfraredLED &led);

  int pushFullByte(
    unsigned int fullByte,
    PIRInfraredLED &led);

  int pushBits(
    const CommandSequence &bits,
    PIRInfraredLED &led);

  unsigned int subDeviceOne;
  unsigned int subDeviceTwo;
  unsigned int oemCode;
  unsigned int deviceCode;
  bool hasFinalFrame;
};

#endif // XMPPROTOCOL_H
