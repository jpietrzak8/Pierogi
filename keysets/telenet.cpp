//
// telenet.cpp
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

#include "telenet.h"
#include "protocols/xmpprotocol.h"


TelenetSTB1::TelenetSTB1(
  unsigned int index)
  : PIRKeysetMetaData(
      "STB Keyset 1",
      Telenet_Make,
      index)
{
}


void TelenetSTB1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new XMPProtocol(
    guiObject, index, 0x1, 0x1, 0x44, 0x2A, false);

  addXMPKey("del", Unmapped_Key, 0x00, 0x00);
  addXMPKey("2", Two_Key, 0x01, 0x00);
  addXMPKey("3", Three_Key, 0x02, 0x00);
  addXMPKey("4", Four_Key, 0x03, 0x00);
  addXMPKey("5", Five_Key, 0x04, 0x00);
  addXMPKey("6", Six_Key, 0x05, 0x00);
  addXMPKey("7", Seven_Key, 0x06, 0x00);
  addXMPKey("8", Eight_Key, 0x07, 0x00);
  addXMPKey("9", Nine_Key, 0x08, 0x00);
  addXMPKey("mute", Mute_Key, 0x09, 0x00);
  addXMPKey("right", Right_Key, 0x0B, 0x00);
  addXMPKey("1", One_Key, 0x0F, 0x00);

  addXMPKey("kiosk", Unmapped_Key, 0x20, 0x00);
  addXMPKey("comm", Unmapped_Key, 0x21, 0x00);
  addXMPKey("smiley", Unmapped_Key, 0x22, 0x00);
  addXMPKey("chup", ChannelUp_Key, 0x23, 0x00);
  addXMPKey("tvgids", Unmapped_Key, 0x24, 0x00);
  addXMPKey("chdown", ChannelDown_Key, 0x25, 0x00);
  addXMPKey("tvtheek", Unmapped_Key, 0x26, 0x00);
  addXMPKey("voldown", VolumeDown_Key, 0x28, 0x00);

  addXMPKey("yellow", Yellow_Key, 0x30, 0x00);
  addXMPKey("blue", Blue_Key, 0x31, 0x00);
  addXMPKey("screen", Unmapped_Key, 0x32, 0x00);
  addXMPKey("previous", Previous_Key, 0x33, 0x00);
  addXMPKey("next", Next_Key, 0x34, 0x00);
  addXMPKey("help", Unmapped_Key, 0x35, 0x00);
  addXMPKey("pause", Pause_Key, 0x36, 0x00);
  addXMPKey("play", Play_Key, 0x37, 0x00);
  addXMPKey("stop", Stop_Key, 0x38, 0x00);

  addXMPKey("back", PrevChannel_Key, 0x40, 0x00);
  addXMPKey("exit", Exit_Key, 0x41, 0x00);
  addXMPKey("red", Red_Key, 0x42, 0x00);
  addXMPKey("green", Green_Key, 0x43, 0x00);
  addXMPKey("power", Power_Key, 0x44, 0x00);
  addXMPKey("left", Left_Key, 0x45, 0x00);

  addXMPKey("volup", VolumeUp_Key, 0x50, 0x00);
  addXMPKey("0", Zero_Key, 0x51, 0x00);
  addXMPKey("up", Up_Key, 0x52, 0x00);
  addXMPKey("down", Down_Key, 0x53, 0x00);
  addXMPKey("ok", Select_Key, 0x54, 0x00);
}
