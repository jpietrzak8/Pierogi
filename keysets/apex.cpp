//
// apex.cpp
//
// Copyright 2013 by John Pietrzak (jpietrzak8@gmail.com)
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
// along with Pierogi; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//

#include "apex.h"
#include "protocols/necprotocol.h"


ApexTV1::ApexTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Apex_Make,
      index)
{
}


void ApexTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x40, 8);

  addKey("0", Zero_Key, 0x00, 8);
  addKey("1", One_Key, 0x01, 8);
  addKey("2", Two_Key, 0x02, 8);
  addKey("3", Three_Key, 0x03, 8);
  addKey("4", Four_Key, 0x04, 8);
  addKey("5", Five_Key, 0x05, 8);
  addKey("6", Six_Key, 0x06, 8);
  addKey("7", Seven_Key, 0x07, 8);
  addKey("8", Eight_Key, 0x08, 8);
  addKey("9", Nine_Key, 0x09, 8);
  addKey("100+", PlusOneHundred_Key, 0x0B, 8);
  addKey("ENTER", Select_Key, 0x0A, 8);
  addKey("SLEEP", Sleep_Key, 0x0D, 8);
  addKey("timer", Timer_Key, 0x0E, 8);

  addKey("mute", Mute_Key, 0x10, 8);
  addKey("picture", PictureMode_Key, 0x11, 8);
  addKey("power", Power_Key, 0x12, 8);
  addKey("STEREO", Unmapped_Key, 0x13, 8);
  addKey("video", Input_Key, 0x14, 8);
  addKey("display", Info_Key, 0x16, 8);
  addKey("cc", Captions_Key, 0x17, 8);
  addKey("up", Up_Key, 0x19, 8);
  addKey("vol+", VolumeUp_Key, 0x1A, 8);
  addKey("ch+", ChannelUp_Key, 0x1B, 8);
  addKey("down", Down_Key, 0x1D, 8);
  addKey("vol-", VolumeDown_Key, 0x1E, 8);
  addKey("ch-", ChannelDown_Key, 0x1F, 8);

  addKey("recall", PrevChannel_Key, 0x40, 8);
  addKey("scan", Scan_Key, 0x41, 8);
  addKey("left", Left_Key, 0x46, 8);
  addKey("right", Right_Key, 0x47, 8);
  addKey("SOUND", SoundMode_Key, 0x5A, 8);
  addKey("menu", Menu_Key, 0x5B, 8);
}


ApexSTB1::ApexSTB1(
  unsigned int index)
  : PIRKeysetMetaData(
      "HDTV Converter Keyset 1",
      Apex_Make,
      index)
{
}


void ApexSTB1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0xFB0C, 16);

  addKey("0", Zero_Key, 0x04, 8);
  addKey("1", One_Key, 0x05, 8);
  addKey("2", Two_Key, 0x06, 8);
  addKey("3", Three_Key, 0x07, 8);
  addKey("4", Four_Key, 0x08, 8);
  addKey("5", Five_Key, 0x09, 8);
  addKey("6", Six_Key, 0x0A, 8);
  addKey("7", Seven_Key, 0x0B, 8);
  addKey("8", Eight_Key, 0x0C, 8);
  addKey("9", Nine_Key, 0x0D, 8);
  addKey("-", Dash_Key, 0x36, 8);
  addKey("Power", Power_Key, 0x15, 8);
  addKey("Menu", Menu_Key, 0x70, 8);
  addKey("Exit", Exit_Key, 0x0F, 8);
  addKey("Up", Up_Key, 0x02, 8);
  addKey("Down", Down_Key, 0x03, 8);
  addKey("OK", Select_Key, 0x18, 8);
  addKey("Recall", PrevChannel_Key, 0x16, 8);
  addKey("Display", Info_Key, 0x13, 8);
  addKey("FAV+", Unmapped_Key, 0x19, 8);
  addKey("FAV-", Unmapped_Key, 0x10, 8);
  addKey("FAV", Favorites_Key, 0x11, 8);
  addKey("Signal", Unmapped_Key, 0x17, 8);
  addKey("Guide", Guide_Key, 0x12, 8);
  addKey("Zoom", Zoom_Key, 0x14, 8);
  addKey("MTS", Audio_Key, 0x64, 8);
  addKey("CCD", Captions_Key, 0x61, 8);
}


ApexDVD1::ApexDVD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Apex_Make,
      index)
{
}


void ApexDVD1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x04, 8);

  addKey("DVD_DIGEST", DiscMenu_Key, 0x00, 8); // "menu"
  addKey("PROGRAM", Program_Key, 0x01, 8);
  addKey("REPEAT", Repeat_Key, 0x02, 8);
  addKey("CLEAR", Clear_Key, 0x03, 8);
  addKey("GOTO", Unmapped_Key, 0x04, 8);
  addKey("RESUME", Play_Key, 0x05, 8);
  addKey("STEP", StepForward_Key, 0x06, 8);
  addKey("PAUSE", Pause_Key, 0x07, 8);
  addKey("VOL+", VolumeUp_Key, 0x08, 8);
  addKey("SHUFFLE", Random_Key, 0x09, 8);
  addKey("VOL-", VolumeDown_Key, 0x0A, 8);
  addKey("AUDIO", Audio_Key, 0x0B, 8);
  addKey("POWER", Power_Key, 0x0C, 8);
  addKey("EJECT", Eject_Key, 0x0D, 8);
  addKey("2", Two_Key, 0x0E, 8);
  addKey("3", Three_Key, 0x0F, 8);

  addKey("REWIND", Rewind_Key, 0x10, 8);
  addKey("1", One_Key, 0x11, 8);
  addKey("5", Five_Key, 0x12, 8);
  addKey("6", Six_Key, 0x13, 8);
  addKey("FAST_FORWARD", FastForward_Key, 0x14, 8);
  addKey("4", Four_Key, 0x15, 8);
  addKey("8", Eight_Key, 0x16, 8);
  addKey("9", Nine_Key, 0x17, 8);
  addKey("BEGINNING", Unmapped_Key, 0x18, 8);
  addKey("7", Seven_Key, 0x19, 8);
  addKey("0", Zero_Key, 0x1A, 8);
  addKey("SETUP", Menu_Key, 0x1B, 8);
  addKey("ENTER", Select_Key, 0x1D, 8);
  addKey("STOP", Stop_Key, 0x1F, 8);

  addKey("SURROUND", Surround_Key, 0x40, 8);
  addKey("TITLE", DiscTitle_Key, 0x41, 8);
  addKey("ECHO+", Unmapped_Key, 0x44, 8);
  addKey("ECHO-", Unmapped_Key, 0x45, 8);
  addKey("KEY+", Unmapped_Key, 0x48, 8);
  addKey("KEY-", Unmapped_Key, 0x49, 8);
  addKey("SLOW", Slow_Key, 0x4A, 8);
  addKey("P/N", Unmapped_Key, 0x4C, 8);
  addKey("MUTE", Mute_Key, 0x4D, 8);
  addKey("DISPLAY", Info_Key, 0x4E, 8);

  addKey("ANGLE", Angle_Key, 0x50, 8);
  addKey("SUB-T", Captions_Key, 0x51, 8);
  addKey("PBC_OFF", Unmapped_Key, 0x52, 8); // "tvmode"
  addKey("UP", Up_Key, 0x54, 8);
  addKey("+10", DoubleDigit_Key, 0x55, 8);
  addKey("VOCALASSIST", Unmapped_Key, 0x56, 8);
  addKey("A-B", RepeatAB_Key, 0x58, 8);
  addKey("LEFT", Left_Key, 0x59, 8);
  addKey("ZOOM", Zoom_Key, 0x5A, 8);
  addKey("RIGHT", Right_Key, 0x5C, 8);
  addKey("DOWN", Down_Key, 0x5D, 8);
}


ApexDVD1a::ApexDVD1a(
  unsigned int index)
  : ApexDVD1(index)
{
  setKeysetName("DVD Keyset 1a");
}


void ApexDVD1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  ApexDVD1::populateProtocol(guiObject);

  addKey("program", Program_Key, 0x56, 8);
  addKey("kodak", Unmapped_Key, 0x01, 8);
  addKey("prev", Previous_Key, 0x18, 8);
  addKey("next", Next_Key, 0x1C, 8);
}

ApexDVD2::ApexDVD2(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 2",
      Apex_Make,
      index)
{
}


void ApexDVD2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0xEE00, 16);

  addKey("program", Program_Key, 0x01, 8);
  addKey("shuffle", Random_Key, 0x03, 8);
  addKey("resume", Unmapped_Key, 0x05, 8);
  addKey("stop", Stop_Key, 0x06, 8);
  addKey("left", Left_Key, 0x07, 8);
  addKey("play", Play_Key, 0x09, 8);
  addKey("down", Down_Key, 0x0B, 8);
  addKey("right", Right_Key, 0x0D, 8);
  addKey("up", Up_Key, 0x0F, 8);

  addKey("goto", Unmapped_Key, 0x10, 8);
  addKey("display", Info_Key, 0x11, 8);
  addKey("dvd_digest", Unmapped_Key, 0x12, 8);
  addKey("pbc_off", Unmapped_Key, 0x13, 8);
  addKey("repeat", Repeat_Key, 0x14, 8);
  addKey("a-b_rpt", RepeatAB_Key, 0x15, 8);
  addKey("step", StepForward_Key, 0x16, 8);
  addKey("slow", Slow_Key, 0x17, 8);
  addKey("openclose", Eject_Key, 0x18, 8);
  addKey("setup", Menu_Key, 0x1B, 8);

  addKey("angle", Angle_Key, 0x40, 8);
  addKey("sub-t", Captions_Key, 0x41, 8);
  addKey("audio", Audio_Key, 0x42, 8);
  addKey("title", DiscTitle_Key, 0x43, 8);
  addKey("P/N", Unmapped_Key, 0x44, 8);
  addKey("3", Three_Key, 0x45, 8);
  addKey("2", Two_Key, 0x46, 8);
  addKey("1", One_Key, 0x47, 8);
  addKey("zoom", Zoom_Key, 0x48, 8);
  addKey("6", Six_Key, 0x49, 8);
  addKey("5", Five_Key, 0x4A, 8);
  addKey("4", Four_Key, 0x4B, 8);
  addKey("vol+", VolumeUp_Key, 0x4C, 8);
  addKey("9", Nine_Key, 0x4D, 8);
  addKey("8", Eight_Key, 0x4E, 8);
  addKey("7", Seven_Key, 0x4F, 8);

  addKey("vol-", VolumeDown_Key, 0x50, 8);
  addKey("mute", Mute_Key, 0x51, 8);
  addKey("+10", DoubleDigit_Key, 0x52, 8);
  addKey("0", Zero_Key, 0x53, 8);
  addKey("fwd", FastForward_Key, 0x54, 8);
  addKey("rev", Rewind_Key, 0x55, 8);
  addKey("skipforward", Next_Key, 0x56, 8);
  addKey("skipback", Previous_Key, 0x57, 8);
  addKey("pause", Pause_Key, 0x58, 8);
  addKey("power", Power_Key, 0x5A, 8);
}


ApexDVD2a::ApexDVD2a(
  unsigned int index)
  : ApexDVD2(index)
{
  setKeysetName("DVD Keyset 2a");
}


void ApexDVD2a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  ApexDVD2::populateProtocol(guiObject);

  addKey("setup", Menu_Key, 0x43, 8);
  addKey("display", Info_Key, 0x48, 8);
  addKey("title", DiscTitle_Key, 0x4C, 8);
  addKey("menu", DiscMenu_Key, 0x50, 8);
  addKey("program", Program_Key, 0x55, 8);
  addKey("goto", Unmapped_Key, 0x54, 8);
  addKey("play", Play_Key, 0x58, 8);
  addKey("pause/step", Pause_Key, 0x05, 8);
  addKey("pause/step", StepForward_Key, 0x05, 8);
  addKey("nav/speed", Unmapped_Key, 0x1B, 8);
  addKey("video", Unmapped_Key, 0x09, 8);
  addKey("enter", Select_Key, 0x17, 8);
  addKey("cancel", Clear_Key, 0x16, 8);
  addKey("return", Exit_Key, 0x14, 8);
  addKey("random", Random_Key, 0x15, 8);
  addKey("p/n", Unmapped_Key, 0x13, 8);
  addKey("a-b", RepeatAB_Key, 0x10, 8);
  addKey("repeat", Repeat_Key, 0x11, 8);
  addKey("i/p", Unmapped_Key, 0x03, 8);
  addKey("pbc", Unmapped_Key, 0x01, 8);
}


ApexDVD3::ApexDVD3(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 3",
      Apex_Make,
      index)
{
}


void ApexDVD3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x01, 8);

  addKey("standby", Power_Key, 0x05, 8);
  addKey("eject", Eject_Key, 0x19, 8);
  addKey("subtitle", Captions_Key, 0x18, 8);
  addKey("audio", Audio_Key, 0x4C, 8);
  addKey("angle", Angle_Key, 0x45, 8);
  addKey("shuffle", Random_Key, 0x15, 8);
  addKey("a-b", RepeatAB_Key, 0x10, 8);
  addKey("repeat", Repeat_Key, 0x14, 8);
  addKey("p/n", Unmapped_Key, 0x11, 8);
  addKey("zoom", Zoom_Key, 0x57, 8);
  addKey("slow", Slow_Key, 0x42, 8);
  addKey("step", StepForward_Key, 0x56, 8);
  addKey("resume", Play_Key, 0x59, 8);
  addKey("display", Info_Key, 0x55, 8);
  addKey("menu", DiscMenu_Key, 0x46, 8);
  addKey("title", DiscTitle_Key, 0x4A, 8);
  addKey("aff", Unmapped_Key, 0x1C, 8);
  addKey("kodak.te", Unmapped_Key, 0x06, 8);
  addKey("i/p", Unmapped_Key, 0x4B, 8);
  addKey("enter", Select_Key, 0x13, 8);
  addKey("up", Up_Key, 0x50, 8);
  addKey("down", Down_Key, 0x12, 8);
  addKey("left", Left_Key, 0x16, 8);
  addKey("right", Right_Key, 0x17, 8);
  addKey("pause", Pause_Key, 0x5B, 8);
  addKey("stop", Stop_Key, 0x04, 8);
  addKey("skip.rev", Previous_Key, 0x43, 8);
  addKey("skip.fwd", Next_Key, 0x4F, 8);
  addKey("rev", Rewind_Key, 0x07, 8);
  addKey("fwd", FastForward_Key, 0x44, 8);
  addKey("setup", Menu_Key, 0x4E, 8);
  addKey("program", Program_Key, 0x00, 8);
  addKey("goto", Unmapped_Key, 0x0C, 8);
  addKey("vol+", VolumeUp_Key, 0x51, 8);
  addKey("vol-", VolumeDown_Key, 0x52, 8);
  addKey("mute", Mute_Key, 0x4D, 8);
  addKey("clear", Clear_Key, 0x48, 8);
  addKey("1", One_Key, 0x01, 8);
  addKey("2", Two_Key, 0x09, 8);
  addKey("3", Three_Key, 0x0D, 8);
  addKey("4", Four_Key, 0x02, 8);
  addKey("5", Five_Key, 0x0A, 8);
  addKey("6", Six_Key, 0x0E, 8);
  addKey("7", Seven_Key, 0x03, 8);
  addKey("8", Eight_Key, 0x0B, 8);
  addKey("9", Nine_Key, 0x0F, 8);
  addKey("0", Zero_Key, 0x41, 8);
  addKey("+10", DoubleDigit_Key, 0x49, 8);
}
