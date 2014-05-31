//
// comag.cpp
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

#include "comag.h"
#include "protocols/necprotocol.h"

ComagSTB1::ComagSTB1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Receiver Keyset 1",
      Comag_Make,
      TV_Panels,
      index)
{
}


void ComagSTB1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x6E00, 16);

  addKey("record", Record_Key, 0x00, 8);
  addKey("3", Three_Key, 0x01, 8);
  addKey("play", Play_Key, 0x02, 8);
  addKey("pause", Pause_Key, 0x02, 8);
  addKey("menu", Menu_Key, 0x03, 8);
  addKey("pip", PIP_Key, 0x04, 8);
  addKey("2", Two_Key, 0x05, 8);
  addKey("info", Info_Key, 0x06, 8);
  addKey("media", Unmapped_Key, 0x07, 8);
  addKey("pip swap", PIPSwap_Key, 0x08, 8);
  addKey("1", One_Key, 0x09, 8);
  addKey("select", Select_Key, 0x0A, 8);
  addKey("rewind", Rewind_Key, 0x0B, 8);
  addKey("power", Power_Key, 0x0C, 8);
  addKey("forward", FastForward_Key, 0x0D, 8);
  addKey("option", Unmapped_Key, 0x0E, 8);
  addKey("blue", Blue_Key, 0x10, 8);
  addKey("satelitte", Unmapped_Key, 0x10, 8);
  addKey("timer", Timer_Key, 0x11, 8);
  addKey("yellow", Yellow_Key, 0x14, 8);
  addKey("audio", Audio_Key, 0x14, 8);
  addKey("green", Green_Key, 0x18, 8);
  addKey("sleep", Sleep_Key, 0x18, 8);
  addKey("tv/radio", Unmapped_Key, 0x1A, 8);
  addKey("red", Red_Key, 0x1C, 8);
  addKey("mosaic", Unmapped_Key, 0x1C, 8);
  addKey("stop", Stop_Key, 0x1E, 8);
  addKey("right arrow", Right_Key, 0x40, 8);
  addKey("0", Zero_Key, 0x41, 8);
  addKey("9", Nine_Key, 0x42, 8);
  addKey("6", Six_Key, 0x43, 8);
  addKey("up arrow", Up_Key, 0x44, 8);
  addKey("teletext", Teletext_Key, 0x45, 8);
  addKey("8", Eight_Key, 0x46, 8);
  addKey("5", Five_Key, 0x47, 8);
  addKey("down arrow", Down_Key, 0x48, 8);
  addKey("exit", Exit_Key, 0x49, 8);
  addKey("7", Seven_Key, 0x4A, 8);
  addKey("4", Four_Key, 0x4B, 8);
  addKey("left arrow", Left_Key, 0x4C, 8);
  addKey("channel up", ChannelUp_Key, 0x4D, 8);
  addKey("timeshift", Unmapped_Key, 0x4F, 8);
  addKey("zoom", Zoom_Key, 0x50, 8);
  addKey("channel down", ChannelDown_Key, 0x51, 8);
  addKey("videoformat", Unmapped_Key, 0x54, 8);
  addKey("pgdn", PageDown_Key, 0x57, 8);
  addKey("last (prev ch)", PrevChannel_Key, 0x59, 8);
  addKey("pgup", PageUp_Key, 0x5B, 8);
  addKey("favouite", Favorites_Key, 0x5C, 8);
  addKey("program guide", Guide_Key, 0x5D, 8);
}


ComagSTB2::ComagSTB2(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Receiver Keyset 2",
      Comag_Make,
      TV_Panels,
      index)
{
}


void ComagSTB2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x00, 8);

  addKey("9", Nine_Key, 0x00, 8);
  addKey("8", Eight_Key, 0x01, 8);
  addKey("7", Seven_Key, 0x02, 8);
  addKey("yellow", Yellow_Key, 0x03, 8);
  addKey("6", Six_Key, 0x04, 8);
  addKey("5", Five_Key, 0x05, 8);
  addKey("4", Four_Key, 0x06, 8);
  addKey("menu", Menu_Key, 0x07, 8);
  addKey("3", Three_Key, 0x08, 8);
  addKey("2", Two_Key, 0x09, 8);
  addKey("1", One_Key, 0x0A, 8);
  addKey("program guide", Guide_Key, 0x0B, 8);
  addKey("channel up", ChannelUp_Key, 0x0D, 8);
  addKey("channel down", ChannelDown_Key, 0x0E, 8);
  addKey("tv/radio", Unmapped_Key, 0x0F, 8);
  addKey("teletext", Teletext_Key, 0x10, 8);
  addKey("last (prev ch)", PrevChannel_Key, 0x11, 8);
  addKey("mute", Mute_Key, 0x12, 8);
  addKey("up arrow", Up_Key, 0x13, 8);
  addKey("vol up", VolumeUp_Key, 0x14, 8);
  addKey("vol down", VolumeDown_Key, 0x15, 8);
  addKey("blue", Blue_Key, 0x16, 8);
  addKey("red", Red_Key, 0x17, 8);
  addKey("movie", Unmapped_Key, 0x19, 8);
  addKey("slowback", SlowMinus_Key, 0x1A, 8);
  addKey("fast fwd", FastForward_Key, 0x1B, 8);
  addKey("record", Record_Key, 0x1C, 8);
  addKey("stop", Stop_Key, 0x1D, 8);
  addKey("power", Power_Key, 0x1E, 8);
  addKey("slowforward", SlowPlus_Key, 0x1F, 8);
  addKey("audio", Audio_Key, 0x40, 8);
  addKey("down arrow", Down_Key, 0x41, 8);
  addKey("0", Zero_Key, 0x43, 8);
  addKey("left arrow", Left_Key, 0x44, 8);
  addKey("exit", Exit_Key, 0x47, 8);
  addKey("play", Play_Key, 0x49, 8);
  addKey("skip+", Next_Key, 0x4A, 8);
  addKey("subtitle", Captions_Key, 0x4B, 8);
  addKey("skip-", Previous_Key, 0x4D, 8);
  addKey("green", Green_Key, 0x4E, 8);
  addKey("select", Select_Key, 0x50, 8);
  addKey("find", Unmapped_Key, 0x51, 8);
  addKey("rewind", Rewind_Key, 0x54, 8);
  addKey("right arrow", Right_Key, 0x57, 8);
  addKey("pause", Pause_Key, 0x5A, 8);
  addKey("favourite", Favorites_Key, 0x5B, 8);
  addKey("display", Info_Key, 0x5E, 8);
}
