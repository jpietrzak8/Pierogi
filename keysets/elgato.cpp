//
// elgato.cpp
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

#include "elgato.h"
#include "protocols/necprotocol.h"

ElgatoEyeTV1::ElgatoEyeTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "EyeTV Keyset 1",
      Elgato_Make,
      TV_Panels | MediaControl_Panels | MediaRecord_Panels,
      index)
{
}


void ElgatoEyeTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x45, 8);

  addKey("KEY_POWER", Power_Key, 0x01, 8);
  addKey("KEY_MUTE", Mute_Key, 0x02, 8);
  addKey("KEY_1", One_Key, 0x03, 8);
  addKey("KEY_2", Two_Key, 0x04, 8);
  addKey("KEY_3", Three_Key, 0x05, 8);
  addKey("KEY_4", Four_Key, 0x06, 8);
  addKey("KEY_5", Five_Key, 0x07, 8);
  addKey("KEY_6", Six_Key, 0x08, 8);
  addKey("KEY_7", Seven_Key, 0x09, 8);
  addKey("KEY_8", Eight_Key, 0x0A, 8);
  addKey("KEY_9", Nine_Key, 0x0B, 8);
  addKey("KEY_LAST", PrevChannel_Key, 0x0C, 8);
  addKey("KEY_0", Zero_Key, 0x0D, 8);
  addKey("KEY_ENTER", Enter_Key, 0x0E, 8);
  addKey("KEY_RED", Red_Key, 0x0F, 8);
  addKey("KEY_CHANNELUP", ChannelUp_Key, 0x10, 8);
  addKey("KEY_CHANNELUP", Up_Key, 0x10, 8);
  addKey("KEY_GREEN", Green_Key, 0x11, 8);
  addKey("KEY_VOLUMEDOWN", VolumeDown_Key, 0x12, 8);
  addKey("KEY_VOLUMEDOWN", Left_Key, 0x12, 8);
  addKey("KEY_OK", Select_Key, 0x13, 8);
  addKey("KEY_VOLUMEUP", VolumeUp_Key, 0x14, 8);
  addKey("KEY_VOLUMEUP", Right_Key, 0x14, 8);
  addKey("KEY_YELLOW", Yellow_Key, 0x15, 8);
  addKey("KEY_CHANNELDOWN", ChannelDown_Key, 0x16, 8);
  addKey("KEY_CHANNELDOWN", Down_Key, 0x16, 8);
  addKey("KEY_BLUE", Blue_Key, 0x17, 8);
  addKey("Replay", Replay_Key, 0x18, 8);
  addKey("Play/Pause", Play_Key, 0x19, 8);
  addKey("Play/Pause", Pause_Key, 0x19, 8);
  addKey("Advance", Advance_Key, 0x1A, 8);
  addKey("Rewind", Rewind_Key, 0x1B, 8);
  addKey("L", LiveTV_Key, 0x1C, 8);
  addKey("FastForward", FastForward_Key, 0x1D, 8);

  // Dual function keys:
  addKey("Stop", Stop_Key, 0x1E, 8);
  addKey("Reveal", TeletextReveal_Key, 0x1E, 8);

  addKey("Menu", Menu_Key, 0x1F, 8);
  addKey("Txt", Teletext_Key, 0x1F, 8);

  addKey("Record", Record_Key, 0x40, 8);
  addKey("Size", TeletextSize_Key, 0x40, 8);

  addKey("Screen", AspectRatio_Key, 0x41, 8);
  addKey("Hold", TeletextHold_Key, 0x41, 8);

  addKey("Select", Input_Key, 0x42, 8);
  addKey("Select", TeletextSelect_Key, 0x42, 8);
}
