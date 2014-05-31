//
// dse.cpp
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

#include "dse.h"
#include "protocols/necprotocol.h"


DSEDVD1::DSEDVD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      DSE_Make,
      MediaControl_Panels,
      index)
{
}


void DSEDVD1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x00, 8);

  addKey("Power", Power_Key, 0x0C, 8);
  addKey("Open/Close", Eject_Key, 0x0D, 8);
  addKey("Subtitle", Captions_Key, 0x1E, 8);
  addKey("Angle", Angle_Key, 0x1F, 8);
  addKey("Language", Audio_Key, 0x1C, 8);
  addKey("Resume", Unmapped_Key, 0x1D, 8);
  addKey("Setup", Menu_Key, 0x14, 8);
  addKey("Time", Unmapped_Key, 0x09, 8);
  addKey("Title", DiscTitle_Key, 0x15, 8);
  addKey("Menu", DiscMenu_Key, 0x16, 8);
  addKey("A-B", RepeatAB_Key, 0x17, 8);
  addKey("1", One_Key, 0x00, 8);
  addKey("2", Two_Key, 0x01, 8);
  addKey("3", Three_Key, 0x02, 8);
  addKey("4", Four_Key, 0x03, 8);
  addKey("5", Five_Key, 0x04, 8);
  addKey("6", Six_Key, 0x05, 8);
  addKey("7", Seven_Key, 0x06, 8);
  addKey("8", Eight_Key, 0x07, 8);
  addKey("9", Nine_Key, 0x08, 8);
  addKey("0", Zero_Key, 0x0A, 8);
  addKey("10+", DoubleDigit_Key, 0x0B, 8);
  addKey("<<", Rewind_Key, 0x40, 8);
  addKey(">>", FastForward_Key, 0x41, 8);
  addKey(">||", Play_Key, 0x44, 8);
  addKey(">||", Pause_Key, 0x44, 8);
  addKey("|<<", Previous_Key, 0x42, 8);
  addKey("Stop", Stop_Key, 0x45, 8);
  addKey(">>|", Next_Key, 0x43, 8);
  addKey("Return", Exit_Key, 0x19, 8);
  addKey("PBC", Unmapped_Key, 0x1A, 8);
  addKey("Zoom", Zoom_Key, 0x1B, 8);
  addKey("Repeat", Repeat_Key, 0x18, 8);
  addKey("LeftArrow", Left_Key, 0x12, 8);
  addKey("RightArrow", Right_Key, 0x13, 8);
  addKey("UpArrow", Up_Key, 0x10, 8);
  addKey("DownArrow", Down_Key, 0x11, 8);
  addKey("Enter", Select_Key, 0x0E, 8);
  addKey("OSD", Info_Key, 0x48, 8);
  addKey("Step", StepForward_Key, 0x49, 8);
  addKey("3D(*)", Unmapped_Key, 0x4A, 8);
  addKey("Vol+", VolumeUp_Key, 0x4B, 8);
  addKey("Vol-", VolumeDown_Key, 0x4F, 8);
  addKey("View", Unmapped_Key, 0x4C, 8);
  addKey("Slow", Slow_Key, 0x4D, 8);
  addKey("Mute", Mute_Key, 0x4E, 8);
  addKey("N/P", Unmapped_Key, 0x50, 8);
  addKey("RAN", Unmapped_Key, 0x51, 8);
  addKey("R/L", Unmapped_Key, 0x52, 8);
  addKey("Prog", Program_Key, 0x53, 8);
}


DSESat1::DSESat1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Sat Keyset 1",
      DSE_Make,
      TV_Panels,
      index)
{
}


void DSESat1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x00, 8);

  addKey("Ch_Up", ChannelUp_Key, 0x00, 8);
  addKey("Ch_Up", Up_Key, 0x00, 8);
  addKey("Ch_Down", ChannelDown_Key, 0x01, 8);
  addKey("Ch_Down", Down_Key, 0x01, 8);
  addKey("Vol+", VolumeUp_Key, 0x02, 8);
  addKey("Vol+", Right_Key, 0x02, 8);
  addKey("Vol-", VolumeDown_Key, 0x03, 8);
  addKey("Vol-", Left_Key, 0x03, 8);
  addKey("Audio", Audio_Key, 0x04, 8);
  addKey("Menu", Menu_Key, 0x05, 8);
  addKey("UHF", Unmapped_Key, 0x06, 8);
  addKey("Page Up", PageUp_Key, 0x07, 8);
  addKey("Mute", Mute_Key, 0x08, 8);
  addKey("Fav", Favorites_Key, 0x09, 8);
  addKey("Power", Power_Key, 0x0A, 8);
  addKey("Blue/System", Blue_Key, 0x0B, 8); 
  addKey("TV/R", Input_Key, 0x0C, 8);
  addKey("Yellow/F2", Yellow_Key, 0x0E, 8);
  addKey("Pause", Pause_Key, 0x0F, 8);

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
  addKey("Info", Info_Key, 0x1A, 8);
  addKey("EPG", Guide_Key, 0x1B, 8);
  addKey("Exit", Exit_Key, 0x1C, 8);
  addKey("Page Down", PageDown_Key, 0x1D, 8);
  addKey("Green/F3", Green_Key, 0x1E, 8);
  addKey("OK", Select_Key, 0x1F, 8);

  addKey("Red/F1", Red_Key, 0x40, 8);
}
