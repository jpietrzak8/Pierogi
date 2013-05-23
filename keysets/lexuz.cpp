//
// lexuz.cpp
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

#include "lexuz.h"
#include "protocols/necprotocol.h"


LexuzDVB1::LexuzDVB1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVB Keyset 1",
      Lexuz_Make,
      index)
{
}


void LexuzDVB1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0xF902, 0x16);

  addKey("CH+", ChannelUp_Key, 0x00, 8);
  addKey("up_arrow", Up_Key, 0x00, 8);
  addKey("CH-", ChannelDown_Key, 0x01, 8);
  addKey("down_arrow", Down_Key, 0x01, 8);
  addKey("left_arrow", Left_Key, 0x02, 8);
  addKey("right_arrow", Right_Key, 0x03, 8);
  addKey("Menu", Menu_Key, 0x04, 8);
  addKey("sat", SatInput_Key, 0x05, 8);
  addKey("Info", Info_Key, 0x06, 8);
  addKey("Guide", Guide_Key, 0x08, 8);
  addKey("Power", Power_Key, 0x0A, 8);
  addKey("Mute", Mute_Key, 0x0C, 8);
  addKey("num_0", Zero_Key, 0x10, 8);
  addKey("num_1", One_Key, 0x11, 8);
  addKey("num_2", Two_Key, 0x12, 8);
  addKey("num_3", Three_Key, 0x13, 8);
  addKey("num_4", Four_Key, 0x14, 8);
  addKey("num_5", Five_Key, 0x15, 8);
  addKey("num_6", Six_Key, 0x16, 8);
  addKey("num_7", Seven_Key, 0x17, 8);
  addKey("num_8", Eight_Key, 0x18, 8);
  addKey("num_9", Nine_Key, 0x19, 8);
  addKey("TV/Radio", Input_Key, 0x1A, 8);
  addKey("exit", Exit_Key, 0x1C, 8);
  addKey("sleep", Sleep_Key, 0x1E, 8);
  addKey("Select", Select_Key, 0x1F, 8);
  addKey("Enter", Enter_Key, 0x1F, 8);
  addKey("favourite", Favorites_Key, 0x41, 8);
  addKey("Page-", PageDown_Key, 0x43, 8);
  addKey("Page+", PageUp_Key, 0x44, 8);
  addKey("blue", Blue_Key, 0x48, 8);
  addKey("yellow", Yellow_Key, 0x49, 8);
  addKey("green", Green_Key, 0x4A, 8);
  addKey("red", Red_Key, 0x4B, 8);
}
