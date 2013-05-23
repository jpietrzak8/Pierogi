//
// starsat.cpp
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

#include "starsat.h"
#include "protocols/necprotocol.h"


StarsatSat1::StarsatSat1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Sat Keyset 1",
      Starsat_Make,
      index)
{
}


void StarsatSat1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
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
  addKey("Power", Power_Key, 0x0A, 8);
  addKey("UP", Up_Key, 0x0B, 8);
  addKey("Mute", Mute_Key, 0x0C, 8);
  addKey("OK", Select_Key, 0x0D, 8);
  addKey("Down", Down_Key, 0x0E, 8);
  addKey("TV/SAT", Input_Key, 0x0F, 8);

  addKey("Left", Left_Key, 0x10, 8);
  addKey("Right", Right_Key, 0x11, 8);
  addKey("Time", Unmapped_Key, 0x12, 8);
  addKey("Audio", Audio_Key, 0x13, 8);
  addKey("Text", Teletext_Key, 0x14, 8);
  addKey("VOL+", VolumeUp_Key, 0x15, 8);
  addKey("Read", Red_Key, 0x16, 8);
  addKey("Sabz", Green_Key, 0x17, 8);
  addKey("Yellowe", Yellow_Key, 0x18, 8);
  addKey("Bule", Blue_Key, 0x19, 8);
  addKey("EPG", Guide_Key, 0x1A, 8);
  addKey("LAN", Unmapped_Key, 0x1B, 8);
  addKey("VOL-", VolumeDown_Key, 0x1C, 8);
  addKey("Media", Unmapped_Key, 0x1D, 8);
  addKey("CH-", ChannelDown_Key, 0x1E, 8);
  addKey("CH+", ChannelUp_Key, 0x1F, 8);

  addKey("MENU", Menu_Key, 0x40, 8);
  addKey("Exit", Exit_Key, 0x41, 8);
  addKey("i", Info_Key, 0x42, 8);
  addKey("RCL", PrevChannel_Key, 0x43, 8);
  addKey("A-Z", Unmapped_Key, 0x44, 8);
  addKey("Sat", Unmapped_Key, 0x45, 8);
  addKey("FUNC", Unmapped_Key, 0x46, 8);
  addKey("FAV", Favorites_Key, 0x47, 8);
//  addKey(">^", Unmapped_Key, 0x0B, 8);
}
