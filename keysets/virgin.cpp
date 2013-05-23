//
// virgin.cpp
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

#include "virgin.h"
#include "protocols/rc5protocol.h"


VirginSTB1::VirginSTB1(
  unsigned int index)
  : PIRKeysetMetaData(
      "STB Keyset 1",
      Virgin_Make,
      index)
{
  addControlledDevice(Virgin_Make, "V BoxHD (Cisco 4585)", Sat_Device);
  addControlledDevice(Virgin_Make, "Virgin Media Tivo (Cisco)", Sat_Device);
}


void VirginSTB1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

  addKey("menu", Menu_Key, 0x028F, 13);
  addKey("up arrow", Up_Key, 0x0290, 13);
  addKey("down arrow", Down_Key, 0x0291, 13);
  addKey("program guide", Guide_Key, 0x0292, 13);
  addKey("exit", Exit_Key, 0x0293, 13);
  addKey("left arrow", Left_Key, 0x0295, 13);
  addKey("right arrow", Right_Key, 0x0296, 13);
  addKey("select", Select_Key, 0x0297, 13);

  addKey("teletext", Teletext_Key, 0x02AA, 13);
  addKey("red", Red_Key, 0x02AB, 13);
  addKey("green", Green_Key, 0x02AC, 13);
  addKey("yellow", Yellow_Key, 0x02AD, 13);
  addKey("blue", Blue_Key, 0x02AE, 13);

  addKey("0", Zero_Key, 0x1280, 13);
  addKey("1", One_Key, 0x1281, 13);
  addKey("2", Two_Key, 0x1282, 13);
  addKey("3", Three_Key, 0x1283, 13);
  addKey("4", Four_Key, 0x1284, 13);
  addKey("5", Five_Key, 0x1285, 13);
  addKey("6", Six_Key, 0x1286, 13);
  addKey("7", Seven_Key, 0x1287, 13);
  addKey("8", Eight_Key, 0x1288, 13);
  addKey("9", Nine_Key, 0x1289, 13);
  addKey("power", Power_Key, 0x128C, 13);

  addKey("pause", Pause_Key, 0x1293, 13);
  addKey("Enter", Enter_Key, 0x1294, 13);
  addKey("myshows", Unmapped_Key, 0x1295, 13);
  addKey("thumbsup", Unmapped_Key, 0x1296, 13);
  addKey("thumbsdown", Unmapped_Key, 0x1297, 13);
  addKey("slow", Slow_Key, 0x1298, 13);
  addKey("clear", Clear_Key, 0x1299, 13);
  addKey("subtitle", Captions_Key, 0x129A, 13);
  addKey("last_ch", PrevChannel_Key, 0x129B, 13);

  addKey("channel up", ChannelUp_Key, 0x12A0, 13);
  addKey("channel down", ChannelDown_Key, 0x12A1, 13);
  addKey("zoom", Zoom_Key, 0x12A2, 13);
  addKey("skip-", Previous_Key, 0x12AA, 13);
  addKey("skip+", Next_Key, 0x12AB, 13);
  addKey("display", Info_Key, 0x12AF, 13);
  addKey("play", Play_Key, 0x12B0, 13);
  addKey("rewind", Rewind_Key, 0x12B2, 13);
  addKey("fast fwd", FastForward_Key, 0x12B4, 13);
  addKey("stop", Stop_Key, 0x12B6, 13);
  addKey("record", Record_Key, 0x12B7, 13);
}
