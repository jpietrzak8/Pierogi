//
// wharfedale.cpp
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

#include "wharfedale.h"
#include "protocols/rc5protocol.h"


WharfedaleTV1::WharfedaleTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Wharfedale_Make,
      index)
{
}


void WharfedaleTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

  addKey("0", Zero_Key, 0x1400, 13);
  addKey("1", One_Key, 0x1401, 13);
  addKey("2", Two_Key, 0x1402, 13);
  addKey("3", Three_Key, 0x1403, 13);
  addKey("4", Four_Key, 0x1404, 13);
  addKey("5", Five_Key, 0x1405, 13);
  addKey("6", Six_Key, 0x1406, 13);
  addKey("7", Seven_Key, 0x1407, 13);
  addKey("8", Eight_Key, 0x1408, 13);
  addKey("9", Nine_Key, 0x1409, 13);
  addKey("exit", Exit_Key, 0x140A, 13);
  addKey("power", Power_Key, 0x140C, 13);
  addKey("mute", Mute_Key, 0x140D, 13);
  addKey("tv/radio", TunerInput_Key, 0x140E, 13);

  addKey("vol up", VolumeUp_Key, 0x1410, 13);
  addKey("vol down", VolumeDown_Key, 0x1411, 13);
  addKey("up arrow", Up_Key, 0x1412, 13);
  addKey("down arrow", Down_Key, 0x1413, 13);
  addKey("select", Select_Key, 0x1414, 13);
  addKey("left arrow", Left_Key, 0x1415, 13);
  addKey("right arrow", Right_Key, 0x1416, 13);
  addKey("pip", PIP_Key, 0x1417, 13);
  addKey("pipch-", PIPChannelDown_Key, 0x1418, 13);
  addKey("pipch+", PIPChannelUp_Key, 0x1419, 13);
  addKey("pip swap", PIPSwap_Key, 0x141A, 13);
  addKey("aspect", AspectRatio_Key, 0x141E, 13);

  addKey("channel up", ChannelUp_Key, 0x1420, 13);
  addKey("channel down", ChannelDown_Key, 0x1421, 13);
  addKey("program guide", Guide_Key, 0x1422, 13);
  addKey("subtitle", Captions_Key, 0x1426, 13);
  addKey("library", Unmapped_Key, 0x1427, 13);
  addKey("last (prev ch)", PrevChannel_Key, 0x1429, 13);
  addKey("record", Record_Key, 0x142A, 13);
  addKey("rewind", Rewind_Key, 0x142B, 13);
  addKey("fast fwd", FastForward_Key, 0x142C, 13);
  addKey("timers", Unmapped_Key, 0x142D, 13);
  addKey("play", Play_Key, 0x142E, 13);
  addKey("stop", Stop_Key, 0x142F, 13);

  addKey("pause", Pause_Key, 0x1430, 13);
  addKey("teletext", Teletext_Key, 0x1431, 13);
  addKey("yellow", Yellow_Key, 0x1432, 13);
  addKey("blue", Blue_Key, 0x1434, 13);
  addKey("menu", Menu_Key, 0x1435, 13);
  addKey("green", Green_Key, 0x1436, 13);
  addKey("red", Red_Key, 0x1437, 13);
  addKey("favourite", Unmapped_Key, 0x143C, 13);
  addKey("display", Info_Key, 0x143F, 13);
}


WharfedaleTV2::WharfedaleTV2(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 2",
      Wharfedale_Make,
      index)
{
}


void WharfedaleTV2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

  addKey("power", Power_Key, 0x100C, 13);
  addKey("mute", Mute_Key, 0x100D, 13);
  addKey("volume down", VolumeDown_Key, 0x1010, 13);
  addKey("menu", Menu_Key, 0x1011, 13);
  addKey("volume up", VolumeUp_Key, 0x1012, 13);
}
