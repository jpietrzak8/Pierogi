//
// dell.cpp
//
// Copyright 2012-2015 by John Pietrzak (jpietrzak8@gmail.com)
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

#include "dell.h"
#include "protocols/mceprotocol.h"
#include "protocols/necprotocol.h"


DellRemote1::DellRemote1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Remote Keyset 1",
      Dell_Make,
      MediaControl_Panels,
      index)
{
}


void DellRemote1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new MCEProtocol(guiObject, index, 0x801C);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x2B, 7);

  addKey("vol_off", Mute_Key, 0x0D, 8);

  addKey("vol+", VolumeUp_Key, 0x10, 8);
  addKey("vol-", VolumeDown_Key, 0x11, 8);

  addKey("next", Next_Key, 0x20, 8);
  addKey("prev", Previous_Key, 0x21, 8);
  addKey("play_pause", Play_Key, 0x2C, 8);
  addKey("play_pause", Pause_Key, 0x2C, 8);
  addKey("forward", FastForward_Key, 0x2E, 8);
  addKey("rewind", Rewind_Key, 0x2F, 8);
  addKey("stop", Stop_Key, 0x31, 8);

  addKey("cross_up", Up_Key, 0x58, 8);
  addKey("cross_down", Down_Key, 0x59, 8);
  addKey("cross_left", Left_Key, 0x5A, 8);
  addKey("cross_right", Right_Key, 0x5B, 8);
  addKey("cross_enter", Select_Key, 0x5C, 8);

  addKey("up", PageUp_Key, 0xCE, 8);
  addKey("down", PageDown_Key, 0xCF, 8);

  addKey("back", Exit_Key, 0xA4, 8);
}


DellProjector1::DellProjector1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Projector Keyset 1",
      Dell_Make,
      MediaControl_Panels,
      index)
{
}


void DellProjector1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, false);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x504F, 16);

  addKey("power", Power_Key, 0x02, 8);
  addKey("videomode", PictureMode_Key, 0x03, 8);
  addKey("source", Input_Key, 0x04, 8);
  addKey("pageup", PageUp_Key, 0x05, 8);
  addKey("pagedown", PageDown_Key, 0x06, 8);
  addKey("vol+", VolumeUp_Key, 0x08, 8);
  addKey("bigtop", Unmapped_Key, 0x09, 8);
  addKey("vol-", VolumeDown_Key, 0x0B, 8);
  addKey("blank screen", Unmapped_Key, 0x0C, 8);
  addKey("bigbottom", Unmapped_Key, 0x0D, 8);
  addKey("mute", Mute_Key, 0x0F, 8);
  addKey("menu", Menu_Key, 0x11, 8);
  addKey("up", Up_Key, 0x13, 8);
  addKey("down", Down_Key, 0x14, 8);
  addKey("plus", Right_Key, 0x15, 8); // hack
  addKey("minus", Left_Key, 0x16, 8); // also hack
  addKey("enter", Select_Key, 0x17, 8);
  addKey("auto adjust", Unmapped_Key, 0x18, 8);
}
