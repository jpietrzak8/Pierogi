//
// manta.cpp
//
// Copyright 2014 - 2015 by John Pietrzak (jpietrzak8@gmail.com)
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

#include "manta.h"
#include "protocols/necprotocol.h"

MantaDVB1::MantaDVB1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVB Keyset 1",
      Manta_Make,
      TV_Panels | MediaControl_Panels | MediaRecord_Panels,
      index)
{
}


void MantaDVB1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x01, 8);

  addKey("power", Power_Key, 0x00, 8);
  addKey("ttx", Teletext_Key, 0x01, 8);
  addKey("exit", Exit_Key, 0x03, 8);
  addKey("pgup", PageUp_Key, 0x04, 8);
  addKey("info", Info_Key, 0x05, 8);
  addKey("ok", Select_Key, 0x06, 8);
  addKey("goto", Unmapped_Key, 0x07, 8);
  addKey("pgdn", PageDown_Key, 0x08, 8);
  addKey("subtitle", Captions_Key, 0x09, 8);
  addKey("fastforward", FastForward_Key, 0x0A, 8);
  addKey("epg", Guide_Key, 0x0B, 8);
  addKey("mute", Mute_Key, 0x0C, 8);
  addKey("fav", Favorites_Key, 0x0D, 8);
  addKey("menu", Menu_Key, 0x0F, 8);

  addKey("vol-", VolumeDown_Key, 0x10, 8);
  addKey("previous", Previous_Key, 0x14, 8);
  addKey("next", Next_Key, 0x18, 8);
  addKey("ch-", ChannelDown_Key, 0x1C, 8);

  addKey("right", Right_Key, 0x40, 8);
  addKey("0", Zero_Key, 0x41, 8);
  addKey("list", Unmapped_Key, 0x42, 8);
  addKey("recall", PrevChannel_Key, 0x43, 8);
  addKey("up", Up_Key, 0x44, 8);
  addKey("9", Nine_Key, 0x45, 8);
  addKey("6", Six_Key, 0x46, 8);
  addKey("3", Three_Key, 0x47, 8);
  addKey("down", Down_Key, 0x48, 8);
  addKey("8", Eight_Key, 0x49, 8);
  addKey("5", Five_Key, 0x4A, 8);
  addKey("2", Two_Key, 0x4B, 8);
  addKey("left", Left_Key, 0x4C, 8);
  addKey("7", Seven_Key, 0x4D, 8);
  addKey("4", Four_Key, 0x4E, 8);
  addKey("1", One_Key, 0x4F, 8);

  addKey("play", Play_Key, 0x50, 8);
  addKey("rec", Record_Key, 0x51, 8);
  addKey("red(zoom)", Red_Key, 0x52, 8);
  addKey("pause", Pause_Key, 0x54, 8);
  addKey("timeshift", Unmapped_Key, 0x55, 8);
  addKey("green(aspect)", Green_Key, 0x56, 8);
  addKey("vol+", VolumeUp_Key, 0x57, 8);
  addKey("stop", Stop_Key, 0x58, 8);
  addKey("tv/radio", Input_Key, 0x59, 8);
  addKey("ch+", ChannelUp_Key, 0x5B, 8);
  addKey("yellow(v-format)", Yellow_Key, 0x5A, 8);
  addKey("lang", Audio_Key, 0x5C, 8);
  addKey("repeat", Repeat_Key, 0x5D, 8);
  addKey("blue(timer)", Blue_Key, 0x5E, 8);
  addKey("rewind", Rewind_Key, 0x5F, 8);
}


MantaDVB2::MantaDVB2(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVB Keyset 2",
      Manta_Make,
      TV_Panels | MediaControl_Panels | MediaRecord_Panels,
      index)
{
}


void MantaDVB2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x01, 8);

  addKey("Power", Power_Key, 0x01, 8);
  addKey("Mute", Mute_Key, 0x02, 8);
  addKey("Fav", Favorites_Key, 0x03, 8);
  addKey("Audio", Audio_Key, 0x05, 8);
  addKey("Teletext", Teletext_Key, 0x06, 8);
  addKey("Subtitle", Captions_Key, 0x07, 8);
  addKey("Guide", Guide_Key, 0x08, 8);
  addKey("TV/Radio", Input_Key, 0x09, 8);
  addKey("Menu", Menu_Key, 0x0A, 8);
  addKey("exit", Exit_Key, 0x0B, 8);
  addKey("Info", Info_Key, 0x0C, 8);
  addKey("Recall", PrevChannel_Key, 0x0D, 8);
  addKey("Select", Select_Key, 0x0F, 8);
  addKey("Ch+", ChannelUp_Key, 0x10, 8);
  addKey("up_arrow", Up_Key, 0x10, 8);
  addKey("Ch-", ChannelDown_Key, 0x11, 8);
  addKey("down_arrow", Down_Key, 0x11, 8);
  addKey("Last_ch", Unmapped_Key, 0x11, 8); // This makes no sense
  addKey("right_arrow", Right_Key, 0x12, 8);
  addKey("left_arrow", Left_Key, 0x13, 8);
  addKey("Play", Play_Key, 0x14, 8);
  addKey("Repeat", Repeat_Key, 0x15, 8);
  addKey("Blue", Blue_Key, 0x16, 8);
  addKey("Schedule", Unmapped_Key, 0x16, 8);
  addKey("Pause", Pause_Key, 0x17, 8);
  addKey("Time Shift", Unmapped_Key, 0x17, 8);
  addKey("Stop", Stop_Key, 0x18, 8);
  addKey("rewind", Rewind_Key, 0x1C, 8);
  addKey("ffwd", FastForward_Key, 0x1D, 8);
  addKey("Skip-", Replay_Key, 0x1E, 8);
  addKey("Skip+", Advance_Key, 0x1F, 8);
  addKey("num_0", Zero_Key, 0x40, 8);
  addKey("num_1", One_Key, 0x41, 8);
  addKey("num_2", Two_Key, 0x42, 8);
  addKey("num_3", Three_Key, 0x43, 8);
  addKey("num_4", Four_Key, 0x44, 8);
  addKey("num_5", Five_Key, 0x45, 8);
  addKey("num_6", Six_Key, 0x46, 8);
  addKey("num_7", Seven_Key, 0x47, 8);
  addKey("num_8", Eight_Key, 0x48, 8);
  addKey("num_9", Nine_Key, 0x49, 8);
  addKey("Go To", Unmapped_Key, 0x4A, 8);
  addKey("Red", Red_Key, 0x51, 8);
  addKey("Green", Green_Key, 0x52, 8);
  addKey("Yellow", Yellow_Key, 0x53, 8);
  addKey("Aspect", AspectRatio_Key, 0x53, 8);
  addKey("Record", Record_Key, 0x58, 8);
}


MantaDVD1::MantaDVD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Manta_Make,
      MediaControl_Panels,
      index)
{
}


void MantaDVD1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x00, 8);

  addKey("return", Unmapped_Key, 0x00, 8);
  addKey("repeat", Repeat_Key, 0x01, 8);
  addKey("vol-", VolumeDown_Key, 0x02, 8);
  addKey("vol+", VolumeUp_Key, 0x03, 8);
  addKey("pbc", Unmapped_Key, 0x05, 8);
  addKey("up", Up_Key, 0x06, 8);
  addKey("enter", Select_Key, 0x07, 8);
  addKey("time", Unmapped_Key, 0x08, 8);
  addKey("1", One_Key, 0x09, 8);
  addKey("<<", Rewind_Key, 0x0A, 8);
  addKey("4", Four_Key, 0x0D, 8);
  addKey("|<<", Previous_Key, 0x0E, 8);
  addKey("n/p", Unmapped_Key, 0x0F, 8);

  addKey("open", Eject_Key, 0x10, 8);
  addKey("7", Seven_Key, 0x11, 8);
  addKey("0", Zero_Key, 0x12, 8);
  addKey("pause", Pause_Key, 0x13, 8);
  addKey("power", Power_Key, 0x14, 8);
  addKey("8", Eight_Key, 0x15, 8);
  addKey("9", Nine_Key, 0x17, 8);
  addKey("a-b", RepeatAB_Key, 0x18, 8);
  addKey("5", Five_Key, 0x19, 8);
  addKey(">>|", Next_Key, 0x1A, 8);
  addKey("6", Six_Key, 0x1B, 8);
  addKey("2", Two_Key, 0x1D, 8);
  addKey(">>", FastForward_Key, 0x1E, 8);
  addKey("3", Three_Key, 0x1F, 8);

  addKey("right", Right_Key, 0x40, 8);
  addKey("r/l", Unmapped_Key, 0x42, 8);
  addKey("view", Unmapped_Key, 0x43, 8);
  addKey("down", Down_Key, 0x44, 8);
  addKey("setup", Menu_Key, 0x45, 8);
  addKey("left", Left_Key, 0x47, 8);
  addKey("subtitle", Captions_Key, 0x48, 8);
  addKey("angle", Angle_Key, 0x49, 8);
  addKey("audio", Audio_Key, 0x4A, 8);
  addKey("prog", Unmapped_Key, 0x4B, 8);

  addKey("title", DiscTitle_Key, 0x50, 8);
  addKey("play", Play_Key, 0x51, 8);
  addKey("osd", Info_Key, 0x52, 8);
  addKey("mute", Mute_Key, 0x53, 8);
  addKey("slow", Slow_Key, 0x55, 8);
  addKey("zoom", Zoom_Key, 0x56, 8);
  addKey("10+", DoubleDigit_Key, 0x59, 8);
  addKey("menu", DiscMenu_Key, 0x5E, 8);
  addKey("stop", Stop_Key, 0x5F, 8);
}


MantaDVD2::MantaDVD2(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 2",
      Manta_Make,
      MediaControl_Panels,
      index)
{
}


void MantaDVD2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x00, 8);

  addKey("0", Zero_Key, 0x00, 8);
  addKey("up", Up_Key, 0x01, 8);
  addKey("ab", RepeatAB_Key, 0x02, 8);
  addKey("title", DiscTitle_Key, 0x03, 8);
  addKey("light", Unmapped_Key, 0x04, 8);
  addKey("stop", Stop_Key, 0x07, 8);
  addKey("10+", DoubleDigit_Key, 0x08, 8);
  addKey("down", Down_Key, 0x09, 8);
  addKey("menu", DiscMenu_Key, 0x0A, 8);
  addKey("setup", Menu_Key, 0x0B, 8);
  addKey("step", StepForward_Key, 0x0D, 8);
  addKey("fwd", FastForward_Key, 0x0E, 8);
  addKey("rev", Rewind_Key, 0x0F, 8);

  addKey("angle", Angle_Key, 0x10, 8);
  addKey("right", Right_Key, 0x11, 8);
  addKey("standby", Power_Key, 0x12, 8);
  addKey("slow", Slow_Key, 0x13, 8);
  addKey("next", Next_Key, 0x14, 8);
  addKey("mute", Mute_Key, 0x15, 8);
  addKey("eject", Eject_Key, 0x16, 8);
  addKey("play", Play_Key, 0x17, 8);
  addKey("time", Unmapped_Key, 0x18, 8);
  addKey("left", Left_Key, 0x19, 8);
  addKey("pbc", Unmapped_Key, 0x1A, 8);
  addKey("repeat", Repeat_Key, 0x1B, 8);
  addKey("prev", Previous_Key, 0x1C, 8);
  addKey("lr", Unmapped_Key, 0x1D, 8);
  addKey("vol-", VolumeDown_Key, 0x1E, 8);
  addKey("vol+", VolumeUp_Key, 0x1F, 8);

  addKey("enter", Select_Key, 0x40, 8);
  addKey("1", One_Key, 0x41, 8);
  addKey("4", Four_Key, 0x42, 8);
  addKey("7", Seven_Key, 0x43, 8);
  addKey("3", Three_Key, 0x45, 8);
  addKey("6", Six_Key, 0x46, 8);
  addKey("9", Nine_Key, 0x47, 8);
  addKey("zoom", Zoom_Key, 0x48, 8);
  addKey("np", Unmapped_Key, 0x49, 8);
  addKey("sub", Captions_Key, 0x4A, 8);
  addKey("lang", Audio_Key, 0x4B, 8);
  addKey("2", Two_Key, 0x4D, 8);
  addKey("5", Five_Key, 0x4E, 8);
  addKey("8", Eight_Key, 0x4F, 8);

  addKey("prog", Unmapped_Key, 0x51, 8);
  addKey("display", Info_Key, 0x53, 8);
}
