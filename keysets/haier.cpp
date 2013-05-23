//
// haier.cpp
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

#include "haier.h"
#include "protocols/aiwaprotocol.h"

HaierTV1::HaierTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Haier_Make,
      index)
{
  addControlledDevice(Haier_Make, "TN201AUV", TV_Device);
}


void HaierTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new AiwaProtocol(guiObject, index);

  setPreData(0x011C, 13);

  addKey("1", One_Key, 0x00, 8);
  addKey("2", Two_Key, 0x01, 8);
  addKey("3", Three_Key, 0x02, 8);
  addKey("4", Four_Key, 0x03, 8);
  addKey("5", Five_Key, 0x04, 8);
  addKey("6", Six_Key, 0x05, 8);
  addKey("7", Seven_Key, 0x06, 8);
  addKey("8", Eight_Key, 0x07, 8);
  addKey("9", Nine_Key, 0x08, 8);
  addKey("0", Zero_Key, 0x09, 8);
  addKey("menu", Menu_Key, 0x0D, 8);
  addKey("last (prev ch)", PrevChannel_Key, 0x0E, 8);
  addKey("tv/av", Input_Key, 0x0F, 8);

  addKey("vol up", VolumeUp_Key, 0x10, 8); // "right arrow"
  addKey("vol up", Right_Key, 0x10, 8); // "right arrow"
  addKey("osd control?", Unmapped_Key, 0x11, 8);
  addKey("power", Power_Key, 0x12, 8);
  addKey("channel up", ChannelUp_Key, 0x13, 8); // "up arrow"
  addKey("channel up", Up_Key, 0x13, 8); // "up arrow"
  addKey("vol down", VolumeDown_Key, 0x14, 8); // "left arrow"
  addKey("vol down", Left_Key, 0x14, 8); // "left arrow"
  addKey("unknown-blanks screen", Unmapped_Key, 0x15, 8);
  addKey("mute", Mute_Key, 0x16, 8);
  addKey("channel down", ChannelDown_Key, 0x17, 8); // "down arrow"
  addKey("channel down", Down_Key, 0x17, 8); // "down arrow"
  addKey("display", Info_Key, 0x18, 8);
  addKey("if control", Unmapped_Key, 0x19, 8);
  addKey("crt geometry", AspectRatio_Key, 0x1A, 8);
  addKey("rating", Unmapped_Key, 0x1B, 8); // "v-chip"
  addKey("rgb control", Unmapped_Key, 0x1C, 8);
  addKey("picture control", Unmapped_Key, 0x1D, 8);
  addKey("factory reset", Unmapped_Key, 0x1E, 8);
  addKey("test pattern", Unmapped_Key, 0x1F, 8);
}
