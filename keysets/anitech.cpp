//
// anitech.cpp
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

#include "anitech.h"
#include "protocols/rc5protocol.h"

AnitechTV1::AnitechTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Anitech_Make,
      TV_Panels,
      index)
{
  addControlledDevice(Anitech_Make, "M 3740", TV_Device);
}


void AnitechTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

  addKey("SLEEP", Sleep_Key, 0x1026, 13);
  addKey("POWER", Power_Key, 0x100C, 13);
  addKey("MUTE", Mute_Key, 0x100D, 13);
  addKey("DISPLAY", Info_Key, 0x100F, 13);
  addKey("CH_UP", ChannelUp_Key, 0x1020, 13);
  addKey("CH_DOWN", ChannelDown_Key, 0x1021, 13);
  addKey("VOL_UP", VolumeUp_Key, 0x1010, 13);
  addKey("VOL_DOWN", VolumeDown_Key, 0x1011, 13);
}


AnitechVCR1::AnitechVCR1(
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      Anitech_Make,
      MediaControl_Panels,
      index)
{
}


void AnitechVCR1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

  addKey("POWER", Power_Key, 0x114C, 13);
  addKey("M", Unmapped_Key, 0x117B, 13);
  addKey("KEY", Unmapped_Key, 0x017F, 13);
  addKey("1", One_Key, 0x1141, 13);
  addKey("2", Two_Key, 0x1142, 13);
  addKey("+", Right_Key, 0x1160, 13); // bit of a hack
  addKey("3", Three_Key, 0x1143, 13);
  addKey("4", Four_Key, 0x1144, 13);
  addKey("5", Five_Key, 0x1145, 13);
  addKey("6", Six_Key, 0x1146, 13);
  addKey("-", Left_Key, 0x1161, 13);  // another hack
  addKey("7", Seven_Key, 0x1147, 13);
  addKey("8", Eight_Key, 0x1148, 13);
  addKey("9", Nine_Key, 0x1149, 13);
  addKey("-/--", DoubleDigit_Key, 0x114A, 13);
  addKey("0", Zero_Key, 0x1140, 13);
  addKey("X", Unmapped_Key, 0x1171, 13);
  addKey("CLOCK", Clock_Key, 0x115D, 13);
  addKey("REC", Record_Key, 0x1177, 13);
  addKey("TREC", RecordTimed_Key, 0x1167, 13);
  addKey("REV_PLAY", Unmapped_Key, 0x116F, 13);
  addKey("REWIND", Rewind_Key, 0x116C, 13);
  addKey("PLAY", Play_Key, 0x1175, 13);
  addKey("FWD", FastForward_Key, 0x116E, 13);
  addKey("SLOW", Slow_Key, 0x114E, 13);
  addKey("N", Unmapped_Key, 0x116A, 13);
  addKey("STOP", Stop_Key, 0x1176, 13);
  addKey("PAUSE", Pause_Key, 0x1169, 13);
}
