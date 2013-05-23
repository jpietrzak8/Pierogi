//
// homecast.cpp
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

#include "homecast.h"
#include "protocols/necprotocol.h"


HomecastReceiver1::HomecastReceiver1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Sat Keyset 1",
      Homecast_Make,
      index)
{
}


void HomecastReceiver1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x2020, 16);

  addKey("Red", Red_Key, 0x01, 8);
  addKey("Green", Green_Key, 0x02, 8);
  addKey("Yellow", Yellow_Key, 0x03, 8);
  addKey("Blue", Blue_Key, 0x04, 8);
  addKey("Menu", Menu_Key, 0x05, 8);
  addKey("Epg", Guide_Key, 0x06, 8);
  addKey("Info", Info_Key, 0x07, 8);
  addKey("Volume+", VolumeUp_Key, 0x0B, 8);
  addKey("Program-", ChannelDown_Key, 0x0C, 8);
  addKey("Volume-", VolumeDown_Key, 0x0D, 8);
  addKey("Mute", Mute_Key, 0x0E, 8);
  addKey("Program+", ChannelUp_Key, 0x0F, 8);

  addKey("Down", Down_Key, 0x10, 8);
  addKey("Up", Up_Key, 0x11, 8);
  addKey("Back", Exit_Key, 0x12, 8);
  addKey("Ok", Select_Key, 0x13, 8);
  addKey("Right", Right_Key, 0x14, 8);
  addKey("Left", Left_Key, 0x15, 8);
  addKey("9", Nine_Key, 0x18, 8);
  addKey("8", Eight_Key, 0x19, 8);
  addKey("Power", Power_Key, 0x1A, 8);
  addKey("TvRad", TunerInput_Key, 0x1C, 8);
  addKey("TvStb", Input_Key, 0x1D, 8);
  addKey("7", Seven_Key, 0x1E, 8);

  addKey("1", One_Key, 0x41, 8);
  addKey("2", Two_Key, 0x42, 8);
  addKey("3", Three_Key, 0x43, 8);
  addKey("6", Six_Key, 0x44, 8);
  addKey("5", Five_Key, 0x45, 8);
  addKey("4", Four_Key, 0x46, 8);
  addKey("Func", Unmapped_Key, 0x49, 8);
  addKey("0", Zero_Key, 0x4E, 8);
}


HomecastReceiver2::HomecastReceiver2(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVB-T Keyset 1",
      Homecast_Make,
      index)
{
}


void HomecastReceiver2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x4040, 16);

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
  addKey("power", Power_Key, 0x0A, 8);
  addKey("up", Up_Key, 0x0B, 8);
  addKey("mute", Mute_Key, 0x0C, 8);
  addKey("ok", Select_Key, 0x0D, 8);
  addKey("down", Down_Key, 0x0E, 8);
  addKey("tv", Unmapped_Key, 0x0F, 8);

  addKey("left", Left_Key, 0x10, 8);
  addKey("right", Right_Key, 0x11, 8);
  addKey("i", Info_Key, 0x12, 8);
  addKey("vol+", VolumeUp_Key, 0x15, 8);
  addKey("red", Red_Key, 0x16, 8);
  addKey("green", Green_Key, 0x17, 8);
  addKey("yellow", Yellow_Key, 0x18, 8);
  addKey("blue", Blue_Key, 0x19, 8);
  addKey("app", Unmapped_Key, 0x1A, 8);
  addKey("vol-", VolumeDown_Key, 0x1C, 8);
  addKey("exit", Exit_Key, 0x1D, 8);
  addKey("ch-", ChannelDown_Key, 0x1E, 8);
  addKey("ch+", ChannelUp_Key, 0x1F, 8);

  addKey("list", Unmapped_Key, 0x40, 8);
  addKey("opt", Unmapped_Key, 0x41, 8);
  addKey("epg", Guide_Key, 0x42, 8);
  addKey("sub", Captions_Key, 0x43, 8);
  addKey("reload", Unmapped_Key, 0x45, 8);
  addKey("menu", Menu_Key, 0x46, 8);
  addKey("text", Teletext_Key, 0x47, 8);
}
