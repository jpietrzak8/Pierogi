//
// genius.cpp
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

#include "genius.h"
#include "protocols/lircprotocol.h"


GeniusSpeakers1::GeniusSpeakers1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Speaker Keyset 1",
      Genius_Make,
      index)
{
}


void GeniusSpeakers1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  LIRCProtocol *lp = new LIRCProtocol(
    guiObject, index,
    359, 1327,
    1202, 484,
    53977, true);

  threadableProtocol = lp;

  lp->setTrailerPulse(359);

  setPreData(0x6, 3);

  addKey("POWER", Power_Key, 0x50, 8);
  addKey("MUTE", Mute_Key, 0x48, 8);
  addKey("VOL_DOWN", VolumeDown_Key, 0x88, 8);
  addKey("VOL_UP", VolumeUp_Key, 0x90, 8);
}
