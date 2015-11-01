//
// starhub.cpp
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

#include "starhub.h"
#include "protocols/nokia32protocol.h"

StarhubSTB1::StarhubSTB1(
  unsigned int index)
  : PIRKeysetMetaData(
      "STB Keyset 1",
      Starhub_Make,
      TV_Panels | MediaControl_Panels | MediaRecord_Panels,
      index)
{
}


void StarhubSTB1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new Nokia32Protocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x2190, 16);
  setPostData(0x26, 7);

  addKey("0", Zero_Key, 0x00, 8);
  addKey("1", One_Key, 0x01, 8);
  addKey("2", Two_Key, 0x02, 8);
  addKey("3", Three_Key, 0x03, 8);
  addKey("4", Four_Key, 0x04, 8);
  addKey("5", Five_Key, 0x05, 8);
  addKey("6", Six_Key, 0x06, 8);
  addKey("7", Seven_Key, 0x07, 8);
  addKey("8", Eight_Key, 0x08, 8);
  addKey("9", Nine_Key, 0x09, 8);
  addKey("power", Power_Key, 0x0C, 8);
  addKey("mute", Mute_Key, 0x0D, 8);
  addKey("info", Info_Key, 0x0F, 8);

  addKey("volume_up", VolumeUp_Key, 0x10, 8);
  addKey("volume_down", VolumeDown_Key, 0x11, 8);

  addKey("channel_up", ChannelUp_Key, 0x20, 8);
  addKey("channel_down", ChannelDown_Key, 0x21, 8);
  addKey("FWD", FastForward_Key, 0x28, 8);
  addKey("Rew", Rewind_Key, 0x29, 8);
  addKey("Play", Play_Key, 0x2C, 8);

  addKey("Pause", Pause_Key, 0x30, 8);
  addKey("Stop", Stop_Key, 0x31, 8);
  addKey("REC", Record_Key, 0x37, 8);

//  addKey("tv", Input_Key, 0x43, 8);
  addKey("F.Fwd", Next_Key, 0x4C, 8);
  addKey("F.Rew", Previous_Key, 0x4D, 8);
  addKey("audio", Audio_Key, 0x4E, 8);

  addKey("menu", Menu_Key, 0x54, 8);
  addKey("up", Up_Key, 0x58, 8);
  addKey("down", Down_Key, 0x59, 8);
  addKey("left", Left_Key, 0x5A, 8);
  addKey("right", Right_Key, 0x5B, 8);
  addKey("ok", Select_Key, 0x5C, 8);

  addKey("mosaic", PIP_Key, 0x66, 8);
  addKey("red", Red_Key, 0x6D, 8);
  addKey("green", Green_Key, 0x6E, 8);
  addKey("yellow", Yellow_Key, 0x6F, 8);

  addKey("blue", Blue_Key, 0x70, 8);

  addKey("help", Unmapped_Key, 0x81, 8); // "interactive"
  addKey("Prev", PrevChannel_Key, 0x83, 8); // "back"
  addKey("favorite", Favorites_Key, 0x84, 8);

  addKey("guide", Guide_Key, 0xCC, 8);

  addKey("Enter", Enter_Key, 0xDB, 8); // "option"

  addKey("back", Exit_Key, 0xE0, 8);

  addKey("messaging", Unmapped_Key, 0xF3, 8);
  addKey("games", Unmapped_Key, 0xF5, 8);
  addKey("star", Unmapped_Key, 0xF6, 8);
  addKey("pound", Unmapped_Key, 0xF7, 8);
  addKey("TV/Vid", Input_Key, 0xF8, 8); // "SmartTv"
  addKey("ppv-vod", Unmapped_Key, 0xFD, 8);
}


StarhubSTB1a::StarhubSTB1a(
  unsigned int index)
  : StarhubSTB1(index)
{
  setKeysetName("STB Keyset 1a");
}


void StarhubSTB1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  StarhubSTB1::populateProtocol(guiObject);

  addKey("Last_ch", PrevChannel_Key, 0x43, 8);
}
