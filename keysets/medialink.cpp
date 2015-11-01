//
// medialink.cpp
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

#include "medialink.h"
#include "protocols/necprotocol.h"
#include <QComboBox>


MedialinkSTB1::MedialinkSTB1(
  unsigned int index)
  : PIRKeysetMetaData(
      "HD Receiver Keyset 1",
      Medialink_Make,
      TV_Panels | MediaControl_Panels | MediaRecord_Panels,
      index)
{
}


void MedialinkSTB1::populateProtocol(
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

  setPreData(0x00BE, 16);

  addKey("CH+", ChannelUp_Key, 0x00, 8);
  addKey("CH-", ChannelDown_Key, 0x01, 8);
  addKey("Skip-", Previous_Key, 0x04, 8);
  addKey("Page+", PageUp_Key, 0x07, 8);
  addKey("PVR", HDDInput_Key, 0x08, 8);
  addKey("Favourite", Favorites_Key, 0x09, 8);
  addKey("Power", Power_Key, 0x0A, 8);
  addKey("Green", Green_Key, 0x0D, 8);
  addKey("Yellow", Yellow_Key, 0x0E, 8);
  addKey("Blue", Blue_Key, 0x0F, 8);
  addKey("num_0", Zero_Key, 0x10, 8);
  addKey("num_1", One_Key, 0x11, 8);
  addKey("num_2", Two_Key, 0x12, 8);
  addKey("num_3", Three_Key, 0x13, 8);
  addKey("num_4", Four_Key, 0x14, 8);
  addKey("num_5", Five_Key, 0x15, 8);
  addKey("num_6", Six_Key, 0x16, 8);
  addKey("num_7", Seven_Key, 0x17, 8);
  addKey("num_8", Eight_Key, 0x18, 8);
  addKey("num_9", Nine_Key, 0x19, 8);
  addKey("Menu", Menu_Key, 0x1A, 8);
  addKey("Sleep", Sleep_Key, 0x1B, 8);
  addKey("exit", Exit_Key, 0x1C, 8);
  addKey("Info", Info_Key, 0x1D, 8);
  addKey("Last_ch", PrevChannel_Key, 0x1E, 8);
  addKey("Select", Select_Key, 0x1F, 8);
  addKey("V-Format", Unmapped_Key, 0x40, 8);
  addKey("PVR Right key", Unmapped_Key, 0x42, 8);
  addKey("Guide", Guide_Key, 0x43, 8);
  addKey("Time", Unmapped_Key, 0x44, 8);
  addKey("rewind", Rewind_Key, 0x45, 8);
  addKey("Pause", Pause_Key, 0x46, 8);
  addKey("Subtitle", Captions_Key, 0x47, 8);
  addKey("ffwd", FastForward_Key, 0x48, 8);
  addKey("Audio", Audio_Key, 0x49, 8);
  addKey("Stop", Stop_Key, 0x4A, 8);
  addKey("Play", Play_Key, 0x4B, 8);
  addKey("Option", Unmapped_Key, 0x4C, 8);
  addKey("Red", Red_Key, 0x4D, 8);
  addKey("up_arrow", Up_Key, 0x4E, 8);
  addKey("down_arrow", Down_Key, 0x4F, 8);
  addKey("Teletext", Unmapped_Key, 0x51, 8);
  addKey("Page-", PageDown_Key, 0x52, 8);
  addKey("left_arrow", Left_Key, 0x53, 8);
  addKey("right_arrow", Right_Key, 0x54, 8);
  addKey("TV/Radio", Input_Key, 0x55, 8);
  addKey("TV/Radio", TunerInput_Key, 0x55, 8);
  addKey("Record", Record_Key, 0x56, 8);
  addKey("PVR Left Key", Unmapped_Key, 0x57, 8);
  addKey("PVR Middle", Unmapped_Key, 0x58, 8);
  addKey("Skip+", Next_Key, 0x5E, 8);
}


void MedialinkSTB1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("TV / Radio", QVariant(TunerInput_Key));
  cb->addItem("PVR", QVariant(HDDInput_Key));
}
