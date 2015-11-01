//
// aoc.cpp
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

#include "aoc.h"
#include "protocols/necprotocol.h"


AOCTV1::AOCTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      AOC_Make,
      TV_Panels,
      index)
{
}


void AOCTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0xBD00, 16);

  addKey("POWER", Power_Key, 0x01, 8);
  addKey("MUTE", Mute_Key, 0x04, 8);
  addKey("TVVIDEO", Input_Key, 0x05, 8);
  addKey("MENU", Menu_Key, 0x0A, 8);
  addKey("RIGHT", Right_Key, 0x0C, 8);

  addKey("LEFT", Left_Key, 0x10, 8);
  addKey("PIP", PIP_Key, 0x12, 8);
  addKey("SLEEP", Sleep_Key, 0x13, 8);
  addKey("WIDE", AspectRatio_Key, 0x14, 8);
  addKey("1", One_Key, 0x15, 8);
  addKey("2", Two_Key, 0x16, 8);
  addKey("3", Three_Key, 0x17, 8);
  addKey("UP", Up_Key, 0x18, 8);
  addKey("4", Four_Key, 0x19, 8);
  addKey("5", Five_Key, 0x1A, 8);
  addKey("6", Six_Key, 0x1B, 8);
  addKey("DOWN", Down_Key, 0x1C, 8);
  addKey("7", Seven_Key,0x1D, 8);
  addKey("8", Eight_Key, 0x1E, 8);
  addKey("9", Nine_Key, 0x1F, 8);

  addKey("INFO", Info_Key, 0x40, 8);
  addKey("0", Zero_Key, 0x41, 8);
  addKey("PRECH", PrevChannel_Key, 0x44, 8);
  addKey("PLUSMINUS", Unmapped_Key, 0x4B, 8);
  addKey("PC", PCInput_Key, 0x45, 8);
}
