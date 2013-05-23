//
// fortec.cpp
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

#include "fortec.h"
#include "protocols/necprotocol.h"


FortecReceiver1::FortecReceiver1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Sat Keyset 1",
      Fortec_Make,
      index)
{
}


void FortecReceiver1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x20, 8);

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
  addKey("ChanUp", ChannelUp_Key, 0x0A, 8);
  addKey("ChanDown", ChannelDown_Key, 0x0B, 8);
  addKey("Mute", Mute_Key, 0x0E, 8);
  addKey("Power", Power_Key, 0x0F, 8);

  addKey("Sat", SatInput_Key, 0x10, 8);
  addKey("Exit", Exit_Key, 0x11, 8);
  addKey("Last", PrevChannel_Key, 0x12, 8);
  addKey("Menu", Menu_Key, 0x13, 8);
  addKey("Info", Info_Key, 0x14, 8);
  addKey("Pause", Pause_Key, 0x15, 8);
  addKey("PageUP", PageUp_Key, 0x16, 8);
  addKey("Guide", Guide_Key, 0x17, 8);
  addKey("OK", Select_Key, 0x19, 8);
  addKey("PageDOWN", PageDown_Key, 0x1A, 8);
  addKey("TV/Radio", Input_Key, 0x1B, 8);
  addKey("Fav", Favorites_Key, 0x1D, 8);
  addKey("Signal", Unmapped_Key, 0x1E, 8);
  addKey("Audio", Audio_Key, 0x1F, 8);

  addKey("F1", Unmapped_Key, 0x57, 8);
  addKey("F2", Unmapped_Key, 0x58, 8);
  addKey("F3", Unmapped_Key, 0x59, 8);
}


FortecReceiver2::FortecReceiver2(
  unsigned int index)
  : PIRKeysetMetaData(
      "Sat Keyset 2",
      Fortec_Make,
      index)
{
}


void FortecReceiver2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0xFD01, 16);

  addKey("channel up", ChannelUp_Key, 0x00, 8); // "up arrow"
  addKey("channel up", Up_Key, 0x00, 8); // "up arrow"
  addKey("channel down", ChannelDown_Key, 0x01, 8); // "down arrow"
  addKey("channel down", Down_Key, 0x01, 8); // "down arrow"
  addKey("vol_up", VolumeUp_Key, 0x02, 8); // "right arrow"
  addKey("vol_up", Right_Key, 0x02, 8); // "right arrow"
  addKey("vol_down", VolumeDown_Key, 0x03, 8); // "left arrow"
  addKey("vol_down", Left_Key, 0x03, 8); // "left arrow"
  addKey("tv_dbs", Input_Key, 0x04, 8);
  addKey("menu", Menu_Key, 0x05, 8);
  addKey("tv_radio", TunerInput_Key, 0x06, 8);
  addKey("power_scan", Scan_Key, 0x08, 8);
  addKey("green", Green_Key, 0x09, 8); // "zoom"
  addKey("green", Zoom_Key, 0x09, 8); // "zoom"
  addKey("power", Power_Key, 0x0A, 8);
  addKey("recall", PrevChannel_Key, 0x0B, 8);
  addKey("mute", Mute_Key, 0x0C, 8);
  addKey("scroll_down", PageDown_Key, 0x0D, 8);
  addKey("audio", Audio_Key, 0x0E, 8);
  addKey("multi", Unmapped_Key, 0x0F, 8);

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
  addKey("sat", Unmapped_Key, 0x1A, 8);
  addKey("sig", Unmapped_Key, 0x1B, 8);
  addKey("pic", Unmapped_Key, 0x1C, 8);
  addKey("display", Info_Key, 0x1D, 8); // "info"
  addKey("red", Red_Key, 0x1E, 8); // "pause"
//  addKey("red", Pause_Key, 0x1E, 8); // "pause"
  addKey("select", Select_Key, 0x1F, 8); // "ok"

  addKey("rewind", Rewind_Key, 0x22, 8);
  addKey("play", Play_Key, 0x23, 8);
  addKey("stop", Stop_Key, 0x24, 8);
  addKey("fast_forward", FastForward_Key, 0x25, 8);
  addKey("pause", Pause_Key, 0x28, 8);

  addKey("fav", Favorites_Key, 0x40, 8);
  addKey("yellow", Yellow_Key, 0x41, 8); // "calendar"
  addKey("edit", Unmapped_Key, 0x42, 8);
  addKey("timer", Timer_Key, 0x43, 8);
  addKey("program guide", Guide_Key, 0x45, 8);
  addKey("record", Record_Key, 0x46, 8);
  addKey("find", Unmapped_Key, 0x47, 8);
  addKey("exit", Exit_Key, 0x48, 8);
  addKey("scroll_up", PageUp_Key, 0x49, 8);

  addKey("back", Replay_Key, 0x50, 8);
  addKey("fwd", Advance_Key, 0x51, 8);
}
