//
// hyundai.cpp
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

#include "hyundai.h"
#include "protocols/necprotocol.h"


HyundaiDVD1::HyundaiDVD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Hyundai_Make,
      index)
{
}


void HyundaiDVD1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0xFB00, 16);

  addKey("STANDBY", Power_Key, 0x0C, 8);
  addKey("OPEN/CLOSE", Eject_Key, 0x0D, 8);
  addKey("1", One_Key, 0x00, 8);
  addKey("2", Two_Key, 0x01, 8);
  addKey("3", Three_Key, 0x02, 8);
  addKey("4", Four_Key, 0x03, 8);
  addKey("5", Five_Key, 0x04, 8);
  addKey("6", Six_Key, 0x05, 8);
  addKey("7", Seven_Key, 0x06, 8);
  addKey("8", Eight_Key, 0x07, 8);
  addKey("9", Nine_Key, 0x08, 8);
  addKey("0/10", Zero_Key, 0x0B, 8);
  addKey("10+", DoubleDigit_Key, 0x0A, 8);
  addKey("GOTO", Unmapped_Key, 0x09, 8);
  addKey("PROG", Program_Key, 0x1E, 8);
  addKey("V-MODE", PictureMode_Key, 0x1F, 8);
  addKey("A-MODE", SoundMode_Key, 0x1C, 8);
  addKey("SETUP", Menu_Key, 0x1D, 8);
  addKey("TITLE", DiscTitle_Key, 0x14, 8);
  addKey("MENU", DiscMenu_Key, 0x15, 8);
  addKey("AUDIO", Audio_Key, 0x16, 8);
  addKey("SUBTITLE", Captions_Key, 0x17, 8);
  addKey("ANGLE", Angle_Key, 0x18, 8);
  addKey("UP", Up_Key, 0x10, 8);
  addKey("DOWN", Down_Key, 0x11, 8);
  addKey("RIGHT", Right_Key, 0x13, 8);
  addKey("LEFT", Left_Key, 0x12, 8);
  addKey("ENTER", Select_Key, 0x0E, 8);
  addKey("STEP", StepForward_Key, 0x19, 8);
  addKey("REPEAT", Repeat_Key, 0x1A, 8);
  addKey("A-B", RepeatAB_Key, 0x1B, 8);
  addKey(">>", FastForward_Key, 0x40, 8);
  addKey("<<", Rewind_Key, 0x41, 8);
  addKey(">>|", Next_Key, 0x42, 8);
  addKey("|<<", Previous_Key, 0x43, 8);
  addKey("PLAY/PAUSE", Play_Key, 0x44, 8);
  addKey("PLAY/PAUSE", Pause_Key, 0x44, 8);
  addKey("STOP", Stop_Key, 0x45, 8);
  addKey("VOLUME+", VolumeUp_Key, 0x48, 8);
  addKey("VOLUME-", VolumeDown_Key, 0x4C, 8);
  addKey("KEY+", Unmapped_Key, 0x49, 8);
  addKey("KEY-", Unmapped_Key, 0x4D, 8);
  addKey("VIRTUAL", Unmapped_Key, 0x4A, 8);
  addKey("OSD", Info_Key, 0x4B, 8);
  addKey("SLOW", Slow_Key, 0x4E, 8);
  addKey("ZOOM", Zoom_Key, 0x4F, 8);
  addKey("MUTE", Mute_Key, 0x50, 8);
  addKey("L/R/ST", Unmapped_Key, 0x51, 8);
  addKey("EQ", Unmapped_Key, 0x52, 8);
  addKey("S_EFFECT", Unmapped_Key, 0x53, 8);
}


HyundaiAudio1::HyundaiAudio1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 1",
      Hyundai_Make,
      index)
{
}


void HyundaiAudio1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0xFF00, 16);

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
  addKey("Power", Power_Key, 0x0C, 8);
  addKey("Eject", Eject_Key, 0x0D, 8);
  addKey("Mute", Mute_Key, 0x1E, 8);
  addKey("Audio", Audio_Key, 0x1F, 8);
  addKey("Subtitle", Captions_Key, 0x1C, 8);
  addKey("Angle", Angle_Key, 0x1D, 8);
  addKey("-/--", DoubleDigit_Key, 0x09, 8);
  addKey("goto", Unmapped_Key, 0x0B, 8);
  addKey("Title", DiscTitle_Key, 0x14, 8);
  addKey("Menu", DiscMenu_Key, 0x15, 8);
  addKey("Prog", Program_Key, 0x16, 8);
  addKey("Scan", Scan_Key, 0x17, 8);
  addKey("Display", Info_Key, 0x18, 8);
  addKey("Enter", Select_Key, 0x0E, 8);
  addKey("Left", Left_Key, 0x12, 8);
  addKey("Right", Right_Key, 0x13, 8);
  addKey("Up", Up_Key, 0x10, 8);
  addKey("Down", Down_Key, 0x11, 8);
  addKey("Setup", Menu_Key, 0x19, 8);
  addKey("Pause", Pause_Key, 0x1A, 8);
  addKey("Band", TunerInput_Key, 0x1B, 8);
  addKey("Play", Play_Key, 0x44, 8);
  addKey("Stop", Stop_Key, 0x45, 8);
  addKey(">>", FastForward_Key, 0x40, 8);
  addKey("<<", Rewind_Key, 0x41, 8);
  addKey(">>!", Next_Key, 0x42, 8);
  addKey("!<<", Previous_Key, 0x43, 8);
  addKey("+vol", VolumeUp_Key, 0x48, 8);
  addKey("-vol", VolumeDown_Key, 0x4C, 8);
  addKey("Zoom", Zoom_Key, 0x49, 8);
  addKey("Repeat", Repeat_Key, 0x4D, 8);
  addKey("Slow", Slow_Key, 0x4A, 8);
  addKey("A-B", RepeatAB_Key, 0x4E, 8);
  addKey("Function", Unmapped_Key, 0x4B, 8);
  addKey("Step", StepForward_Key, 0x4F, 8);
}


HyundaiTV1::HyundaiTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV/Monitor Keyset 1",
      Hyundai_Make,
      index)
{
}


void HyundaiTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, false);

  setPreData(0x03AA, 16);

  addKey("POWER", Power_Key, 0x10, 8);
  addKey("SOURCE", Input_Key, 0x0E, 8);
  addKey("1", One_Key, 0x01, 8);
  addKey("2", Two_Key, 0x02, 8);
  addKey("3", Three_Key, 0x03, 8);
  addKey("4", Four_Key, 0x04, 8);
  addKey("5", Five_Key, 0x05, 8);
  addKey("6", Six_Key, 0x06, 8);
  addKey("7", Seven_Key, 0x07, 8);
  addKey("8", Eight_Key, 0x08, 8);
  addKey("9", Nine_Key, 0x09, 8);
  addKey("0", Zero_Key, 0x00, 8);
  addKey("DISPLAY", Info_Key, 0x14, 8);
  addKey("PREVIOUS_CH", PrevChannel_Key, 0x0A, 8);
  addKey("MUTE", Mute_Key, 0x0F, 8);
  addKey("EXIT", Exit_Key, 0x1F, 8);
  addKey("CH_UP", ChannelUp_Key, 0x1C, 8);
  addKey("CH_UP", Up_Key, 0x1C, 8);
  addKey("CH_DOWN", ChannelDown_Key, 0x1D, 8);
  addKey("CH_DOWN", Down_Key, 0x1D, 8);
  addKey("VOL_UP", VolumeUp_Key, 0x20, 8);
  addKey("VOL_UP", Right_Key, 0x20, 8);
  addKey("VOL_DOWN", VolumeDown_Key, 0x21, 8);
  addKey("VOL_DOWN", Left_Key, 0x21, 8);
  addKey("MENU", Menu_Key, 0x12, 8);
  addKey("AUTO/CC", Captions_Key, 0x13, 8);
  addKey("CH_SEARCH", Scan_Key, 0x1E, 8);
}
