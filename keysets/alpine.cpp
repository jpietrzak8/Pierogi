//
// alpine.cpp
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

#include "alpine.h"
#include "protocols/necprotocol.h"

AlpineAudio1::AlpineAudio1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Car Stereo Keyset 1",
      Alpine_Make,
      index)
{
}


void AlpineAudio1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, false);

  setPreData(0x7289, 16);

  addKey("cd_chg", NextDisc_Key, 0x03, 8);
  addKey("PWR", Power_Key, 0x06, 8);
  addKey("Play/Pause", Pause_Key, 0x07, 8);
  addKey("Play/Pause", Play_Key, 0x07, 8);
  addKey("A_Proc", Unmapped_Key, 0x09, 8); // for an "external audio processor"
  addKey("Source", Input_Key, 0x0A, 8);
  addKey("Band_Prog", ToggleBand_Key, 0x0D, 8); // ?
  addKey("Band_Prog", Program_Key, 0x0D, 8); // ?
  addKey("Up", Up_Key, 0x0E, 8);
  addKey("Up", ChannelUp_Key, 0x0E, 8);
  addKey("Down", Down_Key, 0x0F, 8);
  addKey("Down", ChannelDown_Key, 0x0F, 8);

  addKey("Next_Track", Next_Key, 0x12, 8);
  addKey("RIGHT", Right_Key, 0x12, 8);
  addKey("Back_Track", Previous_Key, 0x13, 8);
  addKey("LEFT", Left_Key, 0x13, 8);
  addKey("Vol_Up", VolumeUp_Key, 0x14, 8);
  addKey("Vol_Down", VolumeDown_Key, 0x15, 8);
  addKey("Mute", Mute_Key, 0x19, 8);

  addKey("TILT_DOWN", Unmapped_Key, 0x4B, 8);
  addKey("TILT_UP", Unmapped_Key, 0x4C, 8);
}
