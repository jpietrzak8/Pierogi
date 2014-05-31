//
// astro.cpp
//
// Copyright 2014 by John Pietrzak (jpietrzak8@gmail.com)
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

#include "astro.h"
#include "protocols/nokia32protocol.h"
#include "protocols/rc6protocol.h"
#include <QComboBox>


AstroSTB1::AstroSTB1(
  unsigned int index)
  : PIRKeysetMetaData(
      "STB Keyset 1",
      Astro_Make,
      TV_Panels,
      index)
{
}


void AstroSTB1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new Nokia32Protocol(guiObject, index);

  setPreData(0x2250, 16);
  setPostData(0x27, 7);

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
  addKey("KEY_POWER", Power_Key, 0x0C, 8);
  addKey("KEY_MUTE", Mute_Key, 0x0D, 8);
  addKey("KEY_INFO", Info_Key, 0x0F, 8);

  addKey("KEY_VOLUMEUP", VolumeUp_Key, 0x10, 8);
  addKey("KEY_VOLUMEDOWN", VolumeDown_Key, 0x11, 8);

  addKey("KEY_CHANNELUP", ChannelUp_Key, 0x20, 8);
  addKey("KEY_CHANNELDOWN", ChannelDown_Key, 0x21, 8);

  addKey("KEY_TEXT", Teletext_Key, 0x3C, 8);

  addKey("KEY_SUBTITLE", Captions_Key, 0x4B, 8);
  addKey("KEY_AUDIO", Audio_Key, 0x4E, 8);

  addKey("KEY_MENU", Menu_Key, 0x54, 8);
  addKey("KEY_UP", Up_Key, 0x58, 8);
  addKey("KEY_DOWN", Down_Key, 0x59, 8);
  addKey("KEY_LEFT", Left_Key, 0x5A, 8);
  addKey("KEY_RIGHT", Right_Key, 0x5B, 8);
  addKey("KEY_OK", Select_Key, 0x5C, 8);

  addKey("KEY_RED", Red_Key, 0x6D, 8);
  addKey("KEY_GREEN", Green_Key, 0x6E, 8);
  addKey("KEY_YELLOW", Yellow_Key, 0x6F, 8);
  addKey("KEY_BLUE", Blue_Key, 0x70, 8);

  addKey("KEY_HELP", Unmapped_Key, 0x81, 8);
  addKey("KEY_EXIT", Exit_Key, 0x83, 8);
  addKey("KEY_FAVORITES", Favorites_Key, 0x84, 8);

  addKey("KEY_BACK", PrevChannel_Key, 0xA9, 8); //?
  addKey("KEY_SHOP", Unmapped_Key, 0xAA, 8);

  addKey("KEY_EPG", Guide_Key, 0xCC, 8);

  addKey("KEY_MAIL", Unmapped_Key, 0xF3, 8);
  addKey("KEY_KPASTERISK", Unmapped_Key, 0xF6, 8);
}


AstroSTB2::AstroSTB2(
  unsigned int index)
  : PIRKeysetMetaData(
      "STB Keyset 2",
      Astro_Make,
      TV_Panels,
      index)
{
}


void AstroSTB2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new RC6Protocol(guiObject, index, 0xA7);

  addKey("Mute", Mute_Key, 0x0D, 8);
  addKey("Byond", Unmapped_Key, 0x83, 8);
  addKey("TV", AntennaInput_Key, 0xCC, 8);
  addKey("Radio", Antenna2Input_Key, 0xF2, 8);
  addKey("Home", Unmapped_Key, 0x54, 8);
  addKey("VolumeUp", VolumeUp_Key, 0x10, 8);
  addKey("VolumeDown", VolumeDown_Key, 0x11, 8);
  addKey("ChannelUp", ChannelUp_Key, 0x20, 8);
  addKey("ChannelDown", ChannelDown_Key, 0x21, 8);
  addKey("Up", Up_Key, 0x58, 8);
  addKey("Down", Down_Key, 0x59, 8);
  addKey("Left", Left_Key, 0x5A, 8);
  addKey("Right", Right_Key, 0x5B, 8);
  addKey("OK", Select_Key, 0x5C, 8);
  addKey("Back", PrevChannel_Key, 0xA9, 8);
  addKey("Red", Red_Key, 0x6D, 8);
  addKey("Green", Green_Key, 0x6E, 8);
  addKey("KEY_YELLOW", Yellow_Key, 0x6F, 8);
  addKey("KEY_BLUE", Blue_Key, 0x70, 8);
  addKey("KEY_BOOKMARKS", Unmapped_Key, 0x84, 8);
  addKey("KEY_INFO", Info_Key, 0x0F, 8);
  addKey("KEY_FORWARD", FastForward_Key, 0x28, 8);
  addKey("KEY_REWIND", Rewind_Key, 0x29, 8);
  addKey("KEY_RECORD", Record_Key, 0x37, 8);
  addKey("KEY_PAUSE", Pause_Key, 0x30, 8);
  addKey("KEY_PLAY", Play_Key, 0x2C, 8);
  addKey("KEY_STOP", Stop_Key, 0x31, 8);
  addKey("1", One_Key, 0x01, 8);
  addKey("2", Two_Key, 0x02, 8);
  addKey("3", Three_Key, 0x03, 8);
  addKey("4", Four_Key, 0x04, 8);
  addKey("5", Five_Key, 0x05, 8);
  addKey("6", Six_Key, 0x06, 8);
  addKey("7", Seven_Key, 0x07, 8);
  addKey("8", Eight_Key, 0x08, 8);
  addKey("9", Nine_Key, 0x09, 8);
  addKey("0", Zero_Key, 0x00, 8);
}


void AstroSTB2::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("TV", QVariant(AntennaInput_Key));
  cb->addItem("Radio", QVariant(Antenna2Input_Key));
}
