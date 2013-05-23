//
// silvercrest.cpp
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

#include "silvercrest.h"
#include "protocols/necprotocol.h"

SilverCrestDVD1::SilverCrestDVD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      SilverCrest_Make,
      index)
{
}


void SilverCrestDVD1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x20, 8);

  addKey("mute", Mute_Key, 0x51, 8);
  addKey("power", Power_Key, 0x0E, 8);
  addKey("ok", Select_Key, 0x5C, 8);
  addKey("up", Up_Key, 0x44, 8);
  addKey("down", Down_Key, 0x1D, 8);
  addKey("left", Left_Key, 0x1C, 8);
  addKey("right", Right_Key, 0x48,8);
  addKey("menu", Menu_Key, 0x42, 8);
  addKey("exit", Exit_Key, 0x40, 8);
  addKey("vol+", VolumeUp_Key, 0x4E, 8);
  addKey("vol-", VolumeDown_Key, 0x4F, 8);
  addKey("ch-", ChannelDown_Key, 0x43, 8);
  addKey("ch+", ChannelUp_Key, 0x1E, 8);
  addKey("text1", Unmapped_Key, 0x02, 8);
  addKey("text2", Unmapped_Key, 0x1B, 8);
  addKey("text3", Unmapped_Key, 0x18, 8);
  addKey("text4", Unmapped_Key, 0x5D, 8);
  addKey("red", Red_Key, 0x0A, 8);
  addKey("yellow", Yellow_Key, 0x47, 8);
  addKey("blue", Blue_Key, 0x16, 8);
  addKey("green", Green_Key, 0x12, 8);
  addKey("rew", Rewind_Key, 0x19, 8);
  addKey("play", Play_Key, 0x55, 8);
  addKey("forw", FastForward_Key, 0x59, 8);
  addKey("record", Record_Key, 0x54, 8);
  addKey("stop", Stop_Key, 0x14, 8);
  addKey("pause", Pause_Key, 0x15, 8);
  addKey("1", One_Key, 0x13, 8);
  addKey("2", Two_Key, 0x10, 8);
  addKey("3", Three_Key, 0x11, 8);
  addKey("4", Four_Key, 0x0F, 8);
  addKey("5", Five_Key, 0x0C, 8);
  addKey("6", Six_Key, 0x0D, 8);
  addKey("7", Seven_Key, 0x0B, 8);
  addKey("8", Eight_Key, 0x08, 8);
  addKey("9", Nine_Key, 0x09, 8);
  addKey("0", Zero_Key, 0x49, 8);
  addKey("av", Input_Key, 0x17, 8);
  addKey("back", PrevChannel_Key, 0x4D, 8);
}


SilverCrestDVD2::SilverCrestDVD2(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 2",
      SilverCrest_Make,
      index)
{
}


void SilverCrestDVD2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0xF700, 16);

  addKey("open/close", Eject_Key, 0x00, 8);
  addKey("3", Three_Key, 0x01, 8);
  addKey("digest", Unmapped_Key, 0x02, 8);
  addKey("menu", DiscMenu_Key, 0x03, 8);
  addKey("dimmer", Unmapped_Key, 0x04, 8);
  addKey("2", Two_Key, 0x05, 8);
  addKey("enter", Enter_Key, 0x06, 8);
  addKey("display/info", Info_Key, 0x07, 8);
  addKey("sleep", Sleep_Key, 0x08, 8);
  addKey("1", One_Key, 0x09, 8);
  addKey("setup", Menu_Key, 0x0A, 8);
  addKey("program/guide", Guide_Key, 0x0B, 8);
  addKey("power", Power_Key, 0x0C, 8);
  addKey("audio", Audio_Key, 0x0D, 8);
  addKey("PAL/NTSC", Unmapped_Key, 0x0E, 8);
  addKey("title", DiscTitle_Key, 0x0F, 8);
  addKey("video out", Unmapped_Key, 0x10, 8);
  addKey("shuffle", Random_Key, 0x14, 8);
  addKey("3D", Unmapped_Key, 0x18, 8);
  addKey("card", Unmapped_Key, 0x1C, 8);
  addKey("right arrow", Right_Key, 0x40, 8);
  addKey("+10", DoubleDigit_Key, 0x41, 8);
  addKey("9", Nine_Key, 0x42, 8);
  addKey("6", Six_Key, 0x43, 8);
  addKey("up arrow", Up_Key, 0x44, 8);
  addKey("0", Zero_Key, 0x45, 8);
  addKey("8", Eight_Key, 0x46, 8);
  addKey("5", Five_Key, 0x47, 8);
  addKey("down arrow", Down_Key, 0x48, 8);
  addKey("clear", Clear_Key, 0x49, 8);
  addKey("7", Seven_Key, 0x4A, 8);
  addKey("4", Four_Key, 0x4B, 8);
  addKey("left arrow", Left_Key, 0x4C, 8);
  addKey("search", Unmapped_Key, 0x4D, 8);
  addKey("subtitle", Captions_Key, 0x4E, 8);
  addKey("angle", Angle_Key, 0x4F, 8);
  addKey("zoom", Zoom_Key, 0x50, 8);
  addKey("slow", Slow_Key, 0x51, 8);
  addKey("f.fwd/next track", Next_Key, 0x52, 8);
  addKey("mark", Unmapped_Key, 0x54, 8);
  addKey("repeat", Repeat_Key, 0x55, 8);
  addKey("f.rew/prev track", Previous_Key, 0x56, 8);
  addKey("play", Play_Key, 0x57, 8);
  addKey("mute", Mute_Key, 0x58, 8);
  addKey("A-B", RepeatAB_Key, 0x59, 8);
  addKey("fast fwd", FastForward_Key, 0x5A, 8);
  addKey("pause", Pause_Key, 0x5B, 8);
  addKey("vol up", VolumeUp_Key, 0x5C, 8);
  addKey("vol down", VolumeDown_Key, 0x5D, 8);
  addKey("rewind", Rewind_Key, 0x5E, 8);
  addKey("stop", Stop_Key, 0x5F, 8);
}


SilverCrestDVD3::SilverCrestDVD3(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 3",
      SilverCrest_Make,
      index)
{
}


void SilverCrestDVD3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x3F40, 16);

  addKey("Slow Fwd", SlowPlus_Key, 0x04, 8);
  addKey("video out", Unmapped_Key, 0x05, 8);
  addKey("mute", Mute_Key, 0x06, 8);
  addKey("search", Unmapped_Key, 0x08, 8);
  addKey("Mode", Mode_Key, 0x09, 8);
  addKey("zoom", Zoom_Key, 0x0A, 8);
  addKey("audio", Audio_Key, 0x0B, 8);
  addKey("8", Eight_Key, 0x0C, 8);
  addKey("dimmer", Unmapped_Key, 0x0D, 8);
  addKey("5", Five_Key, 0x0F, 8);
  addKey("clear", Clear_Key, 0x10, 8);
  addKey("USB/Card", USBInput_Key, 0x11, 8);
  addKey("power", Power_Key, 0x12, 8);
  addKey("9", Nine_Key, 0x13, 8);
  addKey("4", Four_Key, 0x14, 8);
  addKey("fast fwd", FastForward_Key, 0x15, 8);
  addKey("stop", Stop_Key, 0x16, 8);
  addKey("1", One_Key, 0x17, 8);
  addKey("mark", Unmapped_Key, 0x18, 8);
  addKey("return", Unmapped_Key, 0x18, 8);
  addKey("setup", Menu_Key, 0x19, 8);
  addKey("Skip+ Next Trk", Next_Key, 0x1A, 8);
  addKey("title", DiscTitle_Key, 0x1B, 8);
  addKey("open/close", Eject_Key, 0x1C, 8);
  addKey("right arrow", Right_Key, 0x1D, 8);
  addKey("down arrow", Down_Key, 0x1E, 8);
  addKey("vol -", VolumeDown_Key, 0x46, 8);
  addKey("Page -", PageDown_Key, 0x47, 8);
  addKey("subtitle", Captions_Key, 0x48, 8);
  addKey("angle", Angle_Key, 0x49, 8);
  addKey("vol +", VolumeUp_Key, 0x4A, 8);
  addKey("Page +", PageUp_Key, 0x4B, 8);
  addKey("6", Six_Key, 0x4C, 8);
  addKey("7", Seven_Key, 0x4D, 8);
  addKey("A-B", RepeatAB_Key, 0x4E, 8);
  addKey("repeate", Repeat_Key, 0x4F, 8);
  addKey("0", Zero_Key, 0x50, 8);
  addKey("PRG", Unmapped_Key, 0x51, 8);
  addKey("Slow Rew", SlowMinus_Key, 0x52, 8);
  addKey("pause", Pause_Key, 0x53, 8);
  addKey("2", Two_Key, 0x54, 8);
  addKey("3", Three_Key, 0x55, 8);
  addKey("play", Play_Key, 0x56, 8);
  addKey("rewind", Rewind_Key, 0x57, 8);
  addKey("menu", Menu_Key, 0x58, 8);
  addKey("Display", Info_Key, 0x59, 8);
  addKey("Skip- Pev Trk", Previous_Key, 0x5A, 8);
  addKey("ok", Select_Key, 0x5B, 8);
  addKey("up arrow", Up_Key, 0x5E, 8);
  addKey("left arrow", Left_Key, 0x5F, 8);
}
