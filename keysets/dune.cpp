//
// dune.cpp
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

#include "dune.h"
#include "protocols/necprotocol.h"

DuneSTB1::DuneSTB1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Media Player Keyset 1",
      Dune_Make,
      MediaControl_Panels | MediaRecord_Panels,
      index)
{
}


void DuneSTB1::populateProtocol(
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

  setPreData(0xFD00, 16);

  addKey("Eject", Eject_Key, 0x08, 8);
  addKey("Mute", Mute_Key, 0x62, 8);
  addKey("Mode", Unmapped_Key, 0xA2, 8);
  addKey("Power", Power_Key, 0xC2, 8);
  addKey("A (red)", Red_Key, 0x02, 8);
  addKey("B (green)", Green_Key, 0xF8, 8);
  addKey("C (yellow)", Yellow_Key, 0x00, 8);
  addKey("D (blue)", Blue_Key, 0x82, 8);
  addKey("Numeric 0", Zero_Key, 0x50, 8);
  addKey("Numeric 1", One_Key, 0xD0, 8);
  addKey("Numeric 2", Two_Key, 0x30, 8);
  addKey("Numeric 3", Three_Key, 0xB0, 8);
  addKey("Numeric 4", Four_Key, 0x70, 8);
  addKey("Numeric 5", Five_Key, 0xF0, 8);
  addKey("Numeric 6", Six_Key, 0x80, 8);
  addKey("Numeric 7", Seven_Key, 0x88, 8);
  addKey("Numeric 8", Eight_Key, 0x48, 8);
  addKey("Numeric 9", Nine_Key, 0xC8, 8);
  addKey("Clear", Clear_Key, 0xA0, 8);
  addKey("Select", Select_Key, 0x42, 8);
  addKey("Volume up", VolumeUp_Key, 0x4A, 8);
  addKey("Volume down", VolumeDown_Key,0xCA, 8);
  addKey("Page up", PageUp_Key, 0xD2, 8);
  addKey("Page down", PageDown_Key, 0x32, 8);
  addKey("Search", Unmapped_Key, 0x60, 8);
  addKey("Zoom", Zoom_Key, 0x40, 8);
  addKey("Setup", Unmapped_Key, 0x72, 8);
  addKey("Up", Up_Key, 0xA8, 8);
  addKey("Down", Down_Key, 0x68, 8);
  addKey("Left", Left_Key, 0xE8, 8);
  addKey("Right", Right_Key, 0x18, 8);
  addKey("Enter", Enter_Key, 0x28, 8);
  addKey("Return", Exit_Key, 0x20, 8);
  addKey("Info", Info_Key, 0x0A, 8);
  addKey("Pop up menu", Menu_Key, 0xE0, 8);
  addKey("Top menu", Guide_Key, 0x8A, 8);
  addKey("Play", Play_Key, 0x12, 8);
  addKey("Pause", Pause_Key, 0x78, 8);
  addKey("Play/Pause", Unmapped_Key, 0x6A, 8);
  addKey("Previous", Previous_Key, 0x92, 8);
  addKey("Next", Next_Key, 0xB8, 8);
  addKey("Stop", Stop_Key, 0x98, 8);
  addKey("Slow", Slow_Key, 0x58, 8);
  addKey("Rewind", Rewind_Key, 0x38, 8);
  addKey("Forward", FastForward_Key, 0xD8, 8);
  addKey("Subtitle", Captions_Key, 0x2A, 8);
  addKey("Angle/Rotate", Angle_Key, 0xB2, 8);
  addKey("Audio", Audio_Key, 0x22, 8);
  addKey("Repeat", Repeat_Key, 0xF2, 8);
  addKey("REC", Record_Key, 0x06, 8);
  addKey("Shuffle/PIP", Random_Key, 0xE2, 8);
  addKey("Shuffle/PIP", PIP_Key, 0xE2, 8);
  addKey("Dune", DiscMenu_Key, 0x86, 8);
  addKey("URL", Unmapped_Key, 0x46, 8);
  addKey("Discrete power on", PowerOn_Key, 0xFA, 8);
  addKey("Discrete power off", PowerOff_Key, 0x7A, 8);
}
