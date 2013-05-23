//
// frontech.cpp
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

#include "frontech.h"
#include "protocols/protonprotocol.h"
#include "protocols/necxprotocol.h"

FrontechTV1::FrontechTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Frontech_Make,
      index)
{
}


void FrontechTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already popuated.
    return;
  }

  threadableProtocol = new ProtonProtocol(guiObject, index);

  setPreData(0x02, 8);

  addKey("CH+", ChannelUp_Key, 0x01, 8);
  addKey("CH-", ChannelDown_Key, 0x02, 8);
  addKey("Volume +", VolumeUp_Key, 0x03, 8);
  addKey("Volume -", VolumeDown_Key, 0x04, 8);
  addKey("Brightness +", BrightnessUp_Key, 0x05, 8);
  addKey("Brightness -", BrightnessDown_Key, 0x06, 8);
  addKey("Color -", ColorDown_Key, 0x07, 8);
  addKey("Color +", ColorUp_Key, 0x08, 8);
  addKey("Mute", Mute_Key, 0x09, 8);
  addKey("Last/Prev Ch", PrevChannel_Key, 0x0A, 8);
  addKey("Sleep", Sleep_Key, 0x0C, 8);
  addKey("TV/Video", Input_Key, 0x0D, 8);
  addKey("Power", Power_Key, 0x0E, 8);
  addKey("Info/Display", Info_Key, 0x0F, 8);
  addKey("1", One_Key, 0x10, 8);
  addKey("2", Two_Key, 0x11, 8);
  addKey("3", Three_Key, 0x12, 8);
  addKey("4", Four_Key, 0x13, 8);
  addKey("5", Five_Key, 0x14, 8);
  addKey("6", Six_Key, 0x15, 8);
  addKey("7", Seven_Key, 0x16, 8);
  addKey("8", Eight_Key, 0x17, 8);
  addKey("9", Nine_Key, 0x18, 8);
  addKey("0", Zero_Key, 0x19, 8);
  addKey("-/--", DoubleDigit_Key, 0x1A, 8);
  addKey("Menu", Menu_Key, 0x58, 8);
  addKey("Select", Select_Key, 0x58, 8);
  addKey("Arrow_Right", Right_Key, 0x59, 8);
  addKey("Arrow_Left", Left_Key, 0x5A, 8);
}


FrontechTV2::FrontechTV2(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 2",
      Frontech_Make,
      index)
{
}


void FrontechTV2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECXProtocol(guiObject, index, false);

  setPreData(0x0E0E, 16);

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
  addKey("CH+", ChannelUp_Key, 0x10, 8);
  addKey("CH-", ChannelDown_Key, 0x11, 8);
  addKey("Volume +", VolumeUp_Key, 0x12, 8);
  addKey("Volume -", VolumeDown_Key, 0x13, 8);
  addKey("Power", Power_Key, 0x14, 8);
  addKey("Mute", Mute_Key, 0x15, 8);
  addKey("TV/Video", Input_Key, 0x16, 8);
  addKey("Sleep", Sleep_Key, 0x18, 8);
  addKey("Info/Display", Info_Key, 0x19, 8);
  addKey("Last/Prev Ch", PrevChannel_Key, 0x1A, 8);
  addKey("Arrow_Right", Right_Key, 0x1C, 8);
  addKey("Arrow_Left", Left_Key, 0x1D, 8);
  addKey("Menu", Menu_Key, 0x1E, 8);
  addKey("EXIT", Exit_Key, 0x1E, 8);
}
