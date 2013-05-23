//
// f12protocol.h
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

#ifndef F12PROTOCOL_H
#define F12PROTOCOL_H

#include "spaceprotocol.h"

class PIRInfraredLED;

//
// The "F12" protocol is a bit complex, with different modes for "single-shot"
// and "repeatable" commands, and having multiple inter-command gaps when
// repeating.
//

class F12Protocol: public SpaceProtocol
{
public:
  F12Protocol(
    QObject *guiObject,
    unsigned int index);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);

private:
  int generateSingleShotCommand(
    const PIRKeyBits &bits,
    PIRInfraredLED &led);

  int generateRepeatableCommand(
    const PIRKeyBits &bits,
    PIRInfraredLED &led);

  bool isSingleShot(
    const CommandSequence &bits);

  void f12SleepUntilRepeat(
    int gap);
};

#endif // F12PROTOCOL_H
