//
// hp.cpp
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

#include "hp.h"
#include "protocols/mceprotocol.h"


HPRemote1::HPRemote1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Remote Keyset 1",
      HP_Make,
      MediaControl_Panels,
      index)
{
}


void HPRemote1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new MCEProtocol(guiObject, index, 0x8011);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x04, 7);

  addKey("KEY_POWER", Power_Key, 0x0C, 8);
  addKey("KEY_MEDIA", Unmapped_Key, 0x0D, 8);
  addKey("KEY_MUTE", Mute_Key, 0x0E, 8);
  addKey("KEY_INFO", Info_Key, 0x0F, 8);

  addKey("KEY_VOLUMEUP", VolumeUp_Key, 0x10, 8);
  addKey("KEY_VOLUMEDOWN", VolumeDown_Key, 0x11, 8);
  addKey("KEY_PAGEUP", PageUp_Key, 0x12, 8);
  addKey("KEY_PAGEDOWN", PageDown_Key, 0x13, 8);
  addKey("KEY_FASTFORWARD", FastForward_Key, 0x14, 8);
  addKey("KEY_REWIND", Rewind_Key, 0x15, 8);
  addKey("KEY_PLAYPAUSE", Play_Key, 0x16, 8);
  addKey("KEY_PLAYPAUSE", Pause_Key, 0x16, 8);
  addKey("KEY_STOP", Stop_Key, 0x19, 8);
  addKey("KEY_NEXTSONG", Next_Key, 0x1A, 8);
  addKey("KEY_PREVIOUSSONG", Previous_Key, 0x1B, 8);
  addKey("KEY_UP", Up_Key, 0x1E, 8);
  addKey("KEY_DOWN", Down_Key, 0x1F, 8);

  addKey("KEY_LEFT", Left_Key, 0x20, 8);
  addKey("KEY_RIGHT", Right_Key, 0x21, 8);
  addKey("KEY_OK", Select_Key, 0x22, 8);
  addKey("KEY_ENTER", Enter_Key, 0x23, 8);
  addKey("KEY_DVD", DiscMenu_Key, 0x24, 8);

  addKey("KEY_REPEAT", Repeat_Key, 0x4A, 8);
  addKey("KEY_SWITCHVIDEOMODE", Input_Key, 0x4F, 8);
}
