//
// lircprotocol.h
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

#ifndef LIRCPROTOCOL_H
#define LIRCPROTOCOL_H

#include "spaceprotocol.h"

class PIRInfraredLED;

//
// LIRC does not itself have an actual protocol; what it does do is attempt
// to capture IR pulses in more-or-less the most general method possible.
// I'm attempting to push all my keysets into using code paths specific to
// their actual protocols, but I still don't know all the protocols myself.
// Where I don't have that information, I'll use LIRC's system.  The following
// pretty much follows LIRC's system for space-based encoding patterns.
//

class LIRCProtocol: public SpaceProtocol
{
  Q_OBJECT

public:
  LIRCProtocol(
    QObject *guiObject,
    unsigned int index,
    unsigned int zPulse,
    unsigned int zSpace,
    unsigned int oPulse,
    unsigned int oSpace,
    unsigned int gapSpace,
    bool iclflag);

  void setHeaderPair(
    unsigned int pulse,
    unsigned int space);

  void setTrailerPulse(
    unsigned int pulse);

  void setRepeatPair(
    unsigned int pulse,
    unsigned int space);

  void setRepeatNeedsHeader(
    bool flag);

  void setFullHeadlessRepeat(
    bool flag);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);

private:
  bool hasHeaderPair;

  bool hasTrailerPulse;

  unsigned int repeatPulse;
  unsigned int repeatSpace;
  bool hasRepeatPair;
  bool repeatNeedsHeader; // Put the header ahead of the repeat pulse
  bool fullHeadlessRepeat; // Repeat full command but without header

  int generateStandardCommand(
    const PIRKeyBits &bits,
    PIRInfraredLED &led);

  int generateHeadlessCommand(
    const PIRKeyBits &bits,
    PIRInfraredLED &led);

  int generateRepeatCommand(
    PIRInfraredLED &led);
};

#endif // LIRCPROTOCOL_H
