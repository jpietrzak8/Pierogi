//
// spaceprotocol.h
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

#ifndef SPACEPROTOCOL_H
#define SPACEPROTOCOL_H

#include "pirprotocol.h"

class PIRInfraredLED;

// This class supports the generic (LIRC-based) space encoded IR protocol.
// It is intended to support all other space-based protocols through
// inheritance, and as such contains a variety of commonly useful methods and
// attributes.

class SpaceProtocol: public PIRProtocol
{
public:
  SpaceProtocol(
    QObject *guiObject,
    unsigned int index,
    unsigned int zerop,
    unsigned int zeros,
    unsigned int onep,
    unsigned int ones,
    unsigned int headerp,
    unsigned int headers,
    unsigned int trailerp,
    unsigned int gaps,
    bool iclflag);

protected:
  int pushBits(
    const CommandSequence &bits,
    PIRInfraredLED &led);

  int pushReverseBits(
    const CommandSequence &bits,
    PIRInfraredLED &led);

  int pushInvertedBits(
    const CommandSequence &bits,
    PIRInfraredLED &led);

  int pushInvertedReverseBits(
    const CommandSequence &bits,
    PIRInfraredLED &led);

  unsigned int zeroPulse;
  unsigned int zeroSpace;
  unsigned int onePulse;
  unsigned int oneSpace;

  unsigned int headerPulse;
  unsigned int headerSpace;

  unsigned int trailerPulse;
};

#endif // SPACEPROTOCOL_H
