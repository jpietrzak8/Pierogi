//
// sircprotocol.h
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

#ifndef SIRCPROTOCOL_H
#define SIRCPROTOCOL_H

#include "spaceprotocol.h"

class PIRInfraredLED;

//
// The SIRC protocol is Sony's system for transmitting information via
// infrared light.  As with the very popular "NEC" protocol, binary data is
// encoded by varying the amount of time each bit is held: a zero is held for
// a short span of time, a one lasts a little bit longer.
//
// Currently, there seem to be three types of SIRC commands; 12 bit, 15 bit,
// and 20 bit.  In each type, it appears the last seven bits specify the
// command, and the rest specify the device being addressed.  (The bits are
// passed in reverse order in the actual IR stream.)
//
// The marvelous thing about the Sony Infrared Remote Control protocol is just
// how simple and easy it is; just a header pulse, the command, the address,
// and a trailer pulse.  The terrible thing about the protocol is that Sony
// has given up on following their own rules.  Sony devices today regularly
// support commands from a variety of addresses, making the whole concept of
// the "address" kind of meaningless. :(  I can see why the LIRC guys would
// give up and just encode the raw IR bits, rather than wade into this mess...
//

class SIRCProtocol: public SpaceProtocol
{
  Q_OBJECT

public:
  SIRCProtocol(
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
};

#endif // SIRCPROTOCOL_H
