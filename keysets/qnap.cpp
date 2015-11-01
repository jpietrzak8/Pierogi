//
// qnap.cpp
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

#include "qnap.h"
#include "protocols/necprotocol.h"


QNAPPlayer1::QNAPPlayer1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Media Player Keyset 1",
      QNAP_Make,
      MediaControl_Panels,
      index)
{
  addControlledDevice(QNAP_Make, "NMP-1000", Other_Device);
  addControlledDevice(QNAP_Make, "NMP-1000P", Other_Device);
}


void QNAPPlayer1::populateProtocol(
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

  setPreData(0x4523, 16);

  addKey("Mute", Mute_Key, 0x02, 8);
  addKey("Audio", Audio_Key, 0x03, 8);
  addKey("Menu", DiscMenu_Key, 0x04, 8);
  addKey("Zoom", Zoom_Key, 0x06, 8);
  addKey("Title", DiscTitle_Key, 0x07, 8);
  addKey("Angle", Angle_Key, 0x08, 8);
  addKey("Slow", Slow_Key, 0x09, 8);
  addKey("Seek", Unmapped_Key, 0x0B, 8);
  addKey("rewind", Rewind_Key, 0x0C, 8);
  addKey("Stop", Stop_Key, 0x0D, 8);
  addKey("ffwd", FastForward_Key, 0x0E, 8);
  addKey("Home", Guide_Key, 0x0F, 8);
  addKey("Option", Unmapped_Key, 0x11, 8);
  addKey("Resume", Exit_Key, 0x12, 8);
  addKey("up_arrow", Up_Key, 0x13, 8);
  addKey("left_arrow", Left_Key, 0x14, 8);
  addKey("right_arrow", Right_Key, 0x16, 8);
  addKey("down_arrow", Down_Key, 0x17, 8);
  addKey("Skip-", Previous_Key, 0x18, 8);
  addKey("Skip+", Next_Key, 0x19, 8);
  addKey("VOL+", VolumeUp_Key, 0x1B, 8);
  addKey("num_1", One_Key, 0x1C, 8);
  addKey("num_2", Two_Key, 0x1D, 8);
  addKey("num_3", Three_Key, 0x1E, 8);
  addKey("Info", Info_Key, 0x1F, 8);
  addKey("Power", Power_Key, 0x20, 8);
  addKey("num_5", Five_Key, 0x21, 8);
  addKey("Subtitle", Captions_Key, 0x25, 8);
  addKey("num_9", Nine_Key, 0x26, 8);
  addKey("Pause", Pause_Key, 0x2A, 8);
  addKey("Settings", Menu_Key, 0x30, 8);
  addKey("Select", Select_Key, 0x35, 8);
  addKey("Play", Play_Key, 0x35, 8);
  addKey("VOL-", VolumeDown_Key, 0x3A, 8);
  addKey("num_4", Four_Key, 0x40, 8);
  addKey("num_6", Six_Key, 0x42, 8);
  addKey("TV", Input_Key, 0x43, 8);
  addKey("num_7", Seven_Key, 0x44, 8);
  addKey("num_8", Eight_Key, 0x45, 8);
  addKey("num_0", Zero_Key, 0x47, 8);
}
