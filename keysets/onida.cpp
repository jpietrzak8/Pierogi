//
// onida.cpp
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

#include "onida.h"
#include "protocols/necprotocol.h"
#include "protocols/jvcprotocol.h"


OnidaTV1::OnidaTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Onida_Make,
      TV_Panels,
      index)
{
}


void OnidaTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new JVCProtocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x03, 8);

  addKey("sleep-timer", Sleep_Key, 0x03, 8);
  addKey("display", Info_Key, 0x04, 8);

  addKey("tv-video", Input_Key, 0x13, 8);
  addKey("power", Power_Key, 0x17, 8);
  addKey("chdn", ChannelDown_Key, 0x18, 8);
  addKey("chup", ChannelUp_Key, 0x19, 8);
  addKey("mute", Mute_Key, 0x1C, 8);
  addKey("volup", VolumeUp_Key, 0x1E, 8);
  addKey("voldn", VolumeDown_Key, 0x1F, 8);

  addKey("0", Zero_Key, 0x20, 8);
  addKey("1", One_Key, 0x21, 8);
  addKey("2", Two_Key, 0x22, 8);
  addKey("3", Three_Key, 0x23, 8);
  addKey("4", Four_Key, 0x24, 8);
  addKey("5", Five_Key, 0x25, 8);
  addKey("6", Six_Key, 0x26, 8);
  addKey("7", Seven_Key, 0x27, 8);
  addKey("8", Eight_Key, 0x28, 8);
  addKey("9", Nine_Key, 0x29, 8);

  addKey("surround", Surround_Key, 0x42, 8);
  addKey("picsnd-up", Up_Key, 0x5A, 8);
  addKey("picsnd-dn", Down_Key, 0x5B, 8);
  addKey("vsm", Unmapped_Key, 0x79, 8);
  addKey("menu", Menu_Key, 0x7A, 8);
  addKey("picture-sound", ToolsMenu_Key, 0x7B, 8);
  addKey("ssm", Unmapped_Key, 0x90, 8);
  addKey("color-system", Unmapped_Key, 0x92, 8);
  addKey("digits", DoubleDigit_Key, 0x9D, 8);
}


OnidaDVD1::OnidaDVD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Onida_Make,
      MediaControl_Panels,
      index)
{
}


void OnidaDVD1::populateProtocol(
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

  setPreData(0x00, 8);

  addKey("EJECT", Eject_Key, 0x02, 8);
  addKey("SUBTITLE", Captions_Key, 0x04, 8);
  addKey("AUDIO", Audio_Key, 0x05, 8);
  addKey("ANGLE", Angle_Key, 0x06, 8);
  addKey("3", Three_Key, 0x08, 8);
  addKey("2", Two_Key, 0x09, 8);
  addKey("1", One_Key, 0x0A, 8);
  addKey("ENTER", Select_Key, 0x0B, 8);
  addKey("9", Nine_Key, 0x0C, 8);
  addKey("8", Eight_Key, 0x0D, 8);
  addKey("7", Seven_Key, 0x0E, 8);
  addKey("TITLE", DiscTitle_Key, 0x0F, 8);

  addKey("6", Six_Key, 0x10, 8);
  addKey("5", Five_Key, 0x11, 8);
  addKey("4", Four_Key, 0x12, 8);
  addKey("DOWN", Down_Key, 0x13, 8);
  addKey("RETURN", Exit_Key, 0x14, 8);
  addKey("CLEAR", Clear_Key, 0x15, 8);
  addKey("0", Zero_Key, 0x16, 8);
  addKey("MENU", DiscMenu_Key, 0x17, 8);
  addKey("SHUFFLE", Random_Key, 0x18, 8);
  addKey("PROG", Program_Key, 0x19, 8);
  addKey("GOTO", Unmapped_Key, 0x1A, 8);
  addKey("PLAY", Play_Key, 0x1B, 8);
  addKey("RIGHT", Right_Key, 0x1C, 8);
  addKey("UP", Up_Key, 0x1D, 8);
  addKey("LEFT", Left_Key, 0x1E, 8);
  addKey("NEXT", Next_Key, 0x1F, 8);

  addKey("FFWD", FastForward_Key, 0x40, 8);
  addKey("REPEAT", Repeat_Key, 0x42, 8);
  addKey("A-B", RepeatAB_Key, 0x43, 8);
  addKey("PROSCAN", Unmapped_Key, 0x46, 8);
  addKey("OSD", Info_Key, 0x47, 8);
  addKey("SETUP", Menu_Key, 0x48, 8);
  addKey("PAL/NTSC", Unmapped_Key, 0x49, 8);
  addKey("PREV", Previous_Key, 0x4C, 8);
  addKey("STOP", Stop_Key, 0x4D, 8);
  addKey("VOL-", VolumeDown_Key, 0x4E, 8);

  addKey("PAUSE", Pause_Key, 0x50, 8);
  addKey("RWND", Rewind_Key, 0x54, 8);
  addKey("VOL+", VolumeUp_Key, 0x55, 8);
  addKey("ZOOM", Zoom_Key, 0x58, 8);
  addKey("ONOFF", Power_Key, 0x59, 8);
  addKey("MUTE", Mute_Key, 0x5C, 8);
  addKey("FRAME", Unmapped_Key, 0x5D, 8);
}
