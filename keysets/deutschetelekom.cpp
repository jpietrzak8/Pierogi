//
// deutschetelekom.cpp
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

#include "deutschetelekom.h"
#include "protocols/tdcprotocol.h"

DeutscheTelekomSTB1::DeutscheTelekomSTB1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Receiver Keyset 1",
      DeutscheTelekom_Make,
      TV_Panels,
      index)
{
  addControlledDevice(DeutscheTelekom_Make, "MR100", Other_Device);
}


void DeutscheTelekomSTB1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new TDCProtocol(guiObject, index, 0x06, 0x0A);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  addKey("1", One_Key, 0x02, 7);
  addKey("2", Two_Key, 0x05, 7);
  addKey("3", Three_Key, 0x06, 7);
  addKey("4", Four_Key, 0x09, 7);
  addKey("5", Five_Key, 0x0A, 7);
  addKey("6", Six_Key, 0x0D, 7);
  addKey("7", Seven_Key, 0x0E, 7);
  addKey("8", Eight_Key, 0x11, 7);
  addKey("9", Nine_Key, 0x12, 7);
  addKey("0", Zero_Key, 0x15, 7);
  addKey("power", Power_Key, 0x16, 7);
  addKey("up arrow", Up_Key, 0x19, 7);
  addKey("down arrow", Down_Key, 0x1A, 7);
  addKey("left arrow", Left_Key, 0x1D, 7);
  addKey("select", Select_Key, 0x1E, 7);
  addKey("right arrow", Right_Key, 0x21, 7);
  addKey("clear", Clear_Key, 0x22, 7);
  addKey("vol up", VolumeUp_Key, 0x26, 7);
  addKey("channel up", ChannelUp_Key, 0x29, 7);
  addKey("vol down", VolumeDown_Key, 0x2A, 7);
  addKey("channel down", ChannelDown_Key, 0x2D, 7);
  addKey("display", Info_Key, 0x2E, 7);
  addKey("last (prev ch)", PrevChannel_Key, 0x31, 7);
  addKey("recording", Unmapped_Key, 0x32, 7); // what is this?
  addKey("stop", Stop_Key, 0x35, 7);
  addKey("play", Play_Key, 0x36, 7);
  addKey("pause", Pause_Key, 0x36, 7);
  addKey("record", Record_Key, 0x39, 7);
  addKey("return", Unmapped_Key, 0x3A, 7);
  addKey("exit", Exit_Key, 0x3D, 7);
  addKey("program guide", Guide_Key, 0x3E, 7);
  addKey("videoondemand", Unmapped_Key, 0x41, 7);
  addKey("skip-", Previous_Key, 0x42, 7);
  addKey("rewind", Rewind_Key, 0x45, 7);
  addKey("fast fwd", FastForward_Key, 0x46, 7);
  addKey("skip+", Next_Key, 0x49, 7);
  addKey("red", Red_Key, 0x4A, 7);
  addKey("green", Green_Key, 0x4D, 7);
  addKey("yellow", Yellow_Key, 0x4E, 7);
  addKey("blue", Blue_Key, 0x51, 7);
  addKey("mute", Mute_Key, 0x52, 7);
  addKey("teletext", Teletext_Key, 0x55, 7);
  addKey("options", Unmapped_Key, 0x56, 7);
  addKey("radio", Input_Key, 0x59, 7);
  addKey("menu", Menu_Key, 0x5A, 7);
}
