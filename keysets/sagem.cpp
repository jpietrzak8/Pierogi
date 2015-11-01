//
// sagem.cpp
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

#include "sagem.h"
#include "protocols/necprotocol.h"

SagemTVBox1::SagemTVBox1(
  unsigned int index)
  : PIRKeysetMetaData(
      "STB Keyset 1",
      Sagem_Make,
      TV_Panels,
      index)
{
}


void SagemTVBox1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

//  setPreData(0xE17A, 16);
  setPreData(0x5E87, 16);

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
  addKey("EXIT", Exit_Key, 0x0A, 8); // "Key"
  addKey("Up", Up_Key, 0x0B, 8);
  addKey("Down", Down_Key, 0x0C, 8);
  addKey("Vol+", VolumeUp_Key, 0x0D, 8);
  addKey("Vol-", VolumeDown_Key, 0x0E, 8);
  addKey("Mute", Mute_Key, 0x0F, 8);
  addKey("P+", ChannelUp_Key, 0x10, 8);
  addKey("MENU", Menu_Key, 0x11, 8); // "Q"
  addKey("Power", Power_Key, 0x12, 8);
  addKey("Head", Unmapped_Key, 0x13, 8); // "FREEZE", "satdtt"
  addKey("BACK", PrevChannel_Key, 0x14, 8); // "R"
  addKey("OK", Select_Key, 0x15, 8);
  addKey("Red_A", Red_Key, 0x16, 8);
  addKey("Green_B", Green_Key, 0x17, 8);
  addKey("Yellow_C", Yellow_Key, 0x18, 8);
  addKey("Blue_D", Blue_Key, 0x19, 8);
  addKey("P-", ChannelDown_Key, 0x1A, 8);
  addKey("Left", Left_Key, 0x1B, 8);
  addKey("Right", Right_Key, 0x1C, 8);
  addKey("Text", Teletext_Key, 0x1D, 8); // "TELETEXT"
  addKey("INFO", Info_Key, 0x1E, 8); // "Menu"
  addKey("SUBTITLE", Captions_Key, 0x1F, 8); // "swap"
  addKey("Interface", Audio_Key, 0x20, 8); // "AUDIO"
  addKey("Tone", SoundMode_Key, 0x21, 8); // "SOUND"
  addKey("INPUT", Input_Key, 0x24, 8); // "i"
  addKey("EPG", Guide_Key, 0x25, 8); // "Navigator"
  addKey("RightArr", Unmapped_Key, 0x26, 8); // "LIST", "hd"
  addKey("LeftArr", Unmapped_Key, 0x28, 8);
}


SagemTVBox1a::SagemTVBox1a(
  unsigned int index)
  : SagemTVBox1(index)
{
  setKeysetName("STB Keyset 1a");
}


void SagemTVBox1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  SagemTVBox1::populateProtocol(guiObject);

  addKey("tria2", Unmapped_Key, 0x0F, 8);
  addKey("epg", Guide_Key, 0x11, 8);
  addKey("v-", VolumeDown_Key, 0x16, 8);
  addKey("mute", Mute_Key, 0x17, 8);
  addKey("p-", ChannelDown_Key, 0x18, 8);
  addKey("menu", Menu_Key, 0x19, 8);
  addKey("v+", VolumeUp_Key, 0x1D, 8);
  addKey("teletext6", Unmapped_Key, 0x20, 8);
  addKey("note", Unmapped_Key, 0x21, 8);
  addKey("ext", Unmapped_Key, 0x24, 8);
  addKey("p+", ChannelUp_Key, 0x25, 8);
}
