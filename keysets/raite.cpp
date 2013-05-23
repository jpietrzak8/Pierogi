//
// raite.cpp
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

#include "raite.h"
#include "protocols/necprotocol.h"

RaiteDVD1::RaiteDVD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Raite_Make,
      index)
{
  addControlledDevice(Raite_Make, "DVD-703", DVD_Device);
}


void RaiteDVD1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

//  setPreData(0x04FB, 16);
  setPreData(0x20, 8);

  addKey("vocal-assist", Unmapped_Key, 0x01, 8);
  addKey("setup", Menu_Key, 0x02, 8);
  addKey("mute", Mute_Key, 0x03, 8);
  addKey("menu", DiscMenu_Key, 0x06, 8); // "Menu/Return"
  addKey("8", Eight_Key, 0x08, 8);
  addKey("9", Nine_Key, 0x09, 8);
  addKey("resume", Unmapped_Key, 0x0A, 8);
  addKey("7", Seven_Key, 0x0B, 8);
  addKey("5", Five_Key, 0x0C, 8);
  addKey("6", Six_Key, 0x0D, 8);
  addKey("power", Power_Key, 0x0E, 8);
  addKey("4", Four_Key, 0x0F, 8);
  addKey("2", Two_Key, 0x10, 8);
  addKey("3", Three_Key, 0x11, 8);
  addKey("sub-title", Captions_Key, 0x12, 8);
  addKey("1", One_Key, 0x13, 8);
  addKey("1/all", Repeat_Key, 0x14, 8);
  addKey("-v", VolumeDown_Key, 0x15, 8); // also might be wrong
  addKey("language", Audio_Key, 0x16, 8);
  addKey("a-b", RepeatAB_Key, 0x17, 8);
  addKey("ff", FastForward_Key, 0x18, 8);
  addKey("back", Previous_Key, 0x19, 8);
  addKey("open/close", Eject_Key, 0x1A, 8);
  addKey("rew", Rewind_Key, 0x1B, 8);
  addKey("down", Down_Key, 0x1D, 8);
  addKey("left", Left_Key, 0x1C, 8);
  addKey("zoom", Zoom_Key, 0x1E, 8);
  addKey("slow", Slow_Key, 0x1F, 8);
  addKey("title", DiscTitle_Key, 0x40, 8);
  addKey("program", Program_Key, 0x41, 8);
  addKey("up", Up_Key, 0x44, 8);
  addKey("right", Right_Key, 0x48, 8);
  addKey("0", Zero_Key, 0x49, 8);
  addKey("pbc", Unmapped_Key, 0x4C, 8);
  addKey("+10", DoubleDigit_Key, 0x4D, 8);
  addKey("t/c_search", Unmapped_Key, 0x50, 8);
  addKey("stop", Stop_Key, 0x51, 8);
  addKey("angle", Angle_Key, 0x54, 8);
  addKey("+v", VolumeUp_Key, 0x55, 8); // might be wrong
  addKey("display", Info_Key, 0x58, 8);
  addKey("forward", Next_Key, 0x59, 8);
  addKey("play", Play_Key, 0x5C, 8);
  addKey("pause", Pause_Key, 0x5D, 8);
}
