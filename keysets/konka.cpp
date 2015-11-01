//
// konka.cpp
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

#include "konka.h"
#include "protocols/aiwaprotocol.h"

KonkaTV1::KonkaTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Konka_Make,
      TV_Panels,
      index)
{
}


void KonkaTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new AiwaProtocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x0119, 13);

  addKey("Reset", Reset_Key, 0x00, 8);
  addKey("Power", Power_Key, 0x01, 8);
  addKey("Ch+", ChannelUp_Key, 0x02, 8);
  addKey("Ch+", Up_Key, 0x02, 8);
  addKey("Ch-", ChannelDown_Key, 0x03, 8);
  addKey("Ch-", Down_Key, 0x03, 8);
  addKey("Vol+", VolumeUp_Key, 0x04, 8);
  addKey("Vol+", Right_Key, 0x04, 8);
  addKey("Vol-", VolumeDown_Key, 0x05, 8);
  addKey("Vol-", Left_Key, 0x05, 8);
  addKey("MTS", Unmapped_Key, 0x06, 8); // mts obsolete, do we need it?
  addKey("V-Chip", Unmapped_Key, 0x07, 8);
  addKey("Mute", Mute_Key, 0x0A, 8);
  addKey("Display", Info_Key, 0x0B, 8);
  addKey("ChRecall", PrevChannel_Key, 0x0C, 8);
  addKey("Sleep", Sleep_Key, 0x0D, 8);
  addKey("TV/AV", Input_Key, 0x0E, 8);

  addKey("0", Zero_Key, 0x10, 8);
  addKey("1", One_Key, 0x11, 8);
  addKey("2", Two_Key, 0x12, 8);
  addKey("3", Three_Key, 0x13, 8);
  addKey("4", Four_Key, 0x14, 8);
  addKey("5", Five_Key, 0x15, 8);
  addKey("6", Six_Key, 0x16, 8);
  addKey("7", Seven_Key, 0x17, 8);
  addKey("8", Eight_Key, 0x18, 8);
  addKey("9", Nine_Key, 0x19, 8);
  addKey("Menu", Menu_Key, 0x1D, 8);
  addKey("Caption", Captions_Key, 0x1E, 8);
}


KonkaTV2::KonkaTV2(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 2",
      Konka_Make,
      TV_Panels,
      index)
{
}


void KonkaTV2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new AiwaProtocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x0119, 13); // Same as TV1, but keys completely different!

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
  addKey("-", Dash_Key, 0x0A, 8);
  addKey("novideo", Unmapped_Key, 0x0B, 8);
  addKey("tv/av", Input_Key, 0x0D, 8);
  addKey("back", PrevChannel_Key, 0x0E, 8);

  addKey("menu", Menu_Key, 0x10, 8);
  addKey("analog", Unmapped_Key, 0x13, 8);
  addKey("game", Unmapped_Key, 0x14, 8);
  addKey("mute", Mute_Key, 0x15, 8);
  addKey("vstatus", Unmapped_Key, 0x16, 8);
  addKey("ch-", ChannelDown_Key, 0x1A, 8);
  addKey("ch-", Down_Key, 0x1A, 8);
  addKey("ch+", ChannelUp_Key, 0x1B, 8);
  addKey("ch+", Up_Key, 0x1B, 8);
  addKey("power", Power_Key, 0x1C, 8);
  addKey("timing", Unmapped_Key, 0x1D, 8);
  addKey("vol-", VolumeDown_Key, 0x1E, 8);
  addKey("vol-", Left_Key, 0x1E, 8);
  addKey("vol+", VolumeUp_Key, 0x1F, 8);
  addKey("vol+", Right_Key, 0x1F, 8);
}
