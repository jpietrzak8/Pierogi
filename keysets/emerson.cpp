//
// emerson.cpp
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

#include "emerson.h"

#include "protocols/necprotocol.h"
#include "protocols/necxprotocol.h"
#include "protocols/emersonprotocol.h"
#include "protocols/f12protocol.h"

EmersonTV1::EmersonTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Emerson_Make,
      index)
{
}


void EmersonTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, false);

  setPreData(0x0586, 16);

  addKey("1", One_Key, 0x00, 8);
  addKey("2", Two_Key, 0x01, 8);
  addKey("3", Three_Key, 0x02, 8);
  addKey("4", Four_Key, 0x03, 8);
  addKey("5", Five_Key, 0x04, 8);
  addKey("6", Six_Key, 0x05, 8);
  addKey("7", Seven_Key, 0x06, 8);
  addKey("8", Eight_Key, 0x07, 8);
  addKey("9", Nine_Key, 0x08, 8);
  addKey("0", Zero_Key, 0x09, 8);
  addKey("CHUp", ChannelUp_Key, 0x0A, 8);
  addKey("CHDown", ChannelDown_Key, 0x0B, 8);
  addKey("VolUp", VolumeUp_Key, 0x0C, 8);
  addKey("VolDown", VolumeDown_Key, 0x0D, 8);
  addKey("Mute", Mute_Key, 0x0E, 8);
  addKey("Power", Power_Key, 0x0F, 8);
  addKey("QuickView", PrevChannel_Key, 0x10, 8);
  addKey("Sleep", Sleep_Key, 0x13, 8);
  addKey("Menu", Menu_Key, 0x14, 8);
  addKey("SetUp", Up_Key, 0x15, 8);
  addKey("SetDown", Down_Key, 0x16, 8);
  addKey("Call", Info_Key, 0x17, 8); // dubious
  addKey("Enter", Select_Key, 0x18, 8);
  addKey("Reset", Reset_Key, 0x19, 8);
  addKey("Caption", Captions_Key, 0x1C, 8);
  addKey("CapChan", Unmapped_Key, 0x1D, 8);
}


EmersonTV2::EmersonTV2(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 2",
      Emerson_Make,
      index)
{
}


void EmersonTV2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECXProtocol(guiObject, index, false);

  setPreData(0x1616, 16);

  addKey("1", One_Key, 0x00, 8);
  addKey("2", Two_Key, 0x01, 8);
  addKey("3", Three_Key, 0x02, 8);
  addKey("4", Four_Key, 0x03, 8);
  addKey("5", Five_Key, 0x04, 8);
  addKey("6", Six_Key, 0x05, 8);
  addKey("7", Seven_Key, 0x06, 8);
  addKey("8", Eight_Key, 0x07, 8);
  addKey("9", Nine_Key, 0x08, 8);
  addKey("0", Zero_Key, 0x09, 8);
  addKey("channel_plus", ChannelUp_Key, 0x0A, 8);
  addKey("channel_minus", ChannelDown_Key, 0x0B, 8);
  addKey("volume_plus", VolumeUp_Key, 0x0C, 8);
  addKey("volume_minus", VolumeDown_Key, 0x0D, 8);
  addKey("mute", Mute_Key, 0x0E, 8);
  addKey("power", Power_Key, 0x0F, 8);
  addKey("quick_view", PrevChannel_Key, 0x10, 8); // "last (prev ch)"
  addKey("sleep", Sleep_Key, 0x13, 8);
  addKey("add", Unmapped_Key, 0x14, 8);
  addKey("delete", Unmapped_Key, 0x15, 8);
  addKey("select", Select_Key, 0x16, 8);
  addKey("call", Info_Key, 0x17, 8); // "display"
  addKey("Timer Select", Unmapped_Key, 0x18, 8);
  addKey("auto", Unmapped_Key, 0x19, 8);
  addKey("channel_set", Unmapped_Key, 0x1A, 8);
  addKey("closed_caption", Captions_Key, 0x1C, 8); // "TV/CAP/TEXT"
  addKey("cc_channel", Unmapped_Key, 0x1D, 8);
  addKey("Closed Caption", Unmapped_Key, 0x1E, 8); // what is this?
  addKey("Discrete On", PowerOn_Key, 0x7E, 8);
}


EmersonTV3::EmersonTV3(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV/VCR Keyset 3",
      Emerson_Make,
      index)
{
}


void EmersonTV3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x6880, 16);

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
  addKey("channel up", ChannelUp_Key, 0x0A, 8);
  addKey("channel down", ChannelDown_Key, 0x0B, 8);
  addKey("vol up", VolumeUp_Key, 0x0C, 8);
  addKey("vol down", VolumeDown_Key, 0x0D, 8);
  addKey("record", Record_Key, 0x0E, 8);
  addKey("play", Play_Key, 0x0F, 8);
  addKey("stop", Stop_Key, 0x10, 8);
  addKey("fast fwd", FastForward_Key, 0x11, 8);
  addKey("rewind", Rewind_Key, 0x12, 8);
  addKey("pause", Pause_Key, 0x13, 8);
  addKey("clock/program", Timer_Key, 0x14, 8);
  addKey("enter", Enter_Key, 0x15, 8);
  addKey("clear", Clear_Key, 0x16, 8);
  addKey("timer record", RecordTimed_Key, 0x17, 8);
  addKey("tape speed", VHSSpeed_Key, 0x18, 8);
  addKey("counter memory", Unmapped_Key, 0x1B, 8);
  addKey("counter reset", Reset_Key, 0x1C, 8);
  addKey("repeat", Repeat_Key, 0x1E, 8);
  addKey("program confirm", Unmapped_Key, 0x1F, 8);
  addKey("mute", Mute_Key, 0x40, 8);
  addKey("sleep", Sleep_Key, 0x41, 8);
  addKey("call", Info_Key, 0x42, 8); // dubious
  addKey("quick view", PrevChannel_Key, 0x45, 8);
  addKey("ch add", Unmapped_Key, 0x47, 8);
  addKey("ch delete", Unmapped_Key, 0x48, 8);
  addKey("power", Power_Key, 0x49, 8);
  addKey("picture select", PictureMode_Key, 0x50, 8);
  addKey("tracking up", TrackingPlus_Key, 0x55, 8);
  addKey("tracking down", TrackingMinus_Key, 0x56, 8);
  addKey("tracking auto", AutoTracking_Key, 0x57, 8);
  addKey("ch set auto", Unmapped_Key, 0x58, 8);
  addKey("ch set", Unmapped_Key, 0x59, 8);
  addKey("picture reset", Unmapped_Key, 0x5A, 8);
}


EmersonTV4::EmersonTV4(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV/VCR Keyset 4",
      Emerson_Make,
      index)
{
}


void EmersonTV4::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new EmersonProtocol(guiObject, index, false);

  setPreData(0x28, 6);

  addKey("right arrow", Right_Key, 0x04, 6);
  addKey("fast fwd", FastForward_Key, 0x04, 6);
  addKey("sleep", Sleep_Key, 0x05, 6);
  addKey("display", Info_Key, 0x06, 6);
  addKey("channel down", ChannelDown_Key, 0x08, 6);
  addKey("up arrow", Up_Key, 0x0A, 6);
  addKey("play", Play_Key, 0x0A, 6);
  addKey("pause", Pause_Key, 0x0B, 6);
  addKey("left arrow", Left_Key, 0x0C, 6);
  addKey("rewind", Rewind_Key, 0x0C, 6);
  addKey("pip move", PIPMove_Key, 0x0E, 6);
  addKey("channel up", ChannelUp_Key, 0x10, 6);
  addKey("menu", Menu_Key, 0x15, 6);
  addKey("record", Record_Key, 0x1A, 6);
  addKey("down arrow", Down_Key, 0x1C, 6);
  addKey("stop", Stop_Key, 0x1C, 6);
  addKey("num 1", One_Key, 0x1F, 6);
  addKey("power", Power_Key, 0x20, 6);
  addKey("num 2", Two_Key, 0x21, 6);
  addKey("num 3", Three_Key, 0x22, 6);
  addKey("num 4", Four_Key, 0x23, 6);
  addKey("num 5", Five_Key, 0x24, 6);
  addKey("num 6", Six_Key, 0x25, 6);
  addKey("num 7", Seven_Key, 0x26, 6);
  addKey("num 8", Eight_Key, 0x27, 6);
  addKey("num 9", Nine_Key, 0x28, 6);
  addKey("num 0", Zero_Key, 0x29, 6);
  addKey("vol up", VolumeUp_Key, 0x30, 6);
  addKey("vol down", VolumeDown_Key, 0x31, 6);
  addKey("mute", Mute_Key, 0x33, 6);
  addKey("exit", Exit_Key, 0x3D, 6);

  // Device 2C:
  // addEmersonKey("auto repeat", Unmapped_Key, 0x2C, 0x18);
  // addEmersonKey("speed", VHSSpeed_Key, 0x2C, 0x3B);
}


EmersonTV5::EmersonTV5(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 5",
      Emerson_Make,
      index)
{
}


void EmersonTV5::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0xE084, 16);

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
  addKey("Still", Pause_Key, 0x1A, 8);
  addKey("-", Dash_Key, 0x1B, 8);
  addKey("PowerToggle", Power_Key, 0x20, 8);
  addKey("Sleep", Sleep_Key, 0x22, 8);
  addKey("InputNext", Input_Key, 0x40, 8);
  addKey("ChannelUp", ChannelUp_Key, 0x50, 8);
  addKey("ChannelDown", ChannelDown_Key, 0x51, 8);
  addKey("ChannelPrev", PrevChannel_Key, 0x57, 8);
  addKey("VolumeUp", VolumeUp_Key, 0x60, 8);
  addKey("VolumeDown", VolumeDown_Key, 0x61, 8);
  addKey("Mute", Mute_Key, 0x64, 8);
  addKey("Audio", Audio_Key, 0x65, 8);
  addKey("Setup", Menu_Key, 0x70, 8);
  addKey("DirectionUp", Up_Key, 0x73, 8);
  addKey("DirectionDown", Down_Key, 0x74, 8);
  addKey("DirectionRight", Right_Key, 0x75, 8);
  addKey("DirectionLeft", Left_Key, 0x76, 8);
  addKey("Select/Ok", Select_Key, 0x77, 8);
  addKey("Return", Exit_Key, 0x78, 8);
  addKey("Aspect", AspectRatio_Key, 0x90, 8);
  addKey("Info", Info_Key, 0x9B, 8);
}


EmersonSTB1::EmersonSTB1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Cable Box Keyset 1",
      Emerson_Make,
      index)
{
}


void EmersonSTB1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x00, 8);

  addKey("fc scan", Unmapped_Key, 0x00, 8);
  addKey("fc memo", Unmapped_Key, 0x01, 8);
  addKey("tv/catv", Input_Key, 0x02, 8);
  addKey("rcl (previous channel)", PrevChannel_Key, 0x04, 8);
  addKey("+100", PlusOneHundred_Key, 0x05, 8);
  addKey("0", Zero_Key, 0x06, 8);
  addKey("channel down", ChannelDown_Key, 0x07, 8);
  addKey("7", Seven_Key, 0x08, 8);
  addKey("8", Eight_Key, 0x09, 8);
  addKey("9", Nine_Key, 0x0A, 8);
  addKey("channel up", ChannelUp_Key, 0x0B, 8);
  addKey("4", Four_Key, 0x0C, 8);
  addKey("5", Five_Key, 0x0D, 8);
  addKey("6", Six_Key, 0x0E, 8);
  addKey("vol down", VolumeDown_Key, 0x0F, 8);
  addKey("1", One_Key, 0x10, 8);
  addKey("2", Two_Key, 0x11, 8);
  addKey("3", Three_Key, 0x12, 8);
  addKey("vol up", VolumeUp_Key, 0x13, 8);
  addKey("pc", Unmapped_Key, 0x14, 8);
  addKey("pc memo", Unmapped_Key, 0x15, 8);
  addKey("pc scan", Unmapped_Key, 0x16, 8);
  addKey("mute", Mute_Key, 0x17, 8);
  addKey("sleep", Sleep_Key, 0x18, 8);
  addKey("mts", Audio_Key, 0x19, 8);
  addKey("power", Power_Key, 0x1F, 8);
}


EmersonDVD1::EmersonDVD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Emerson_Make,
      index)
{
}


void EmersonDVD1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x2287, 16);

  addKey("timer prog", Timer_Key, 0x32, 8);
  addKey("channel up", ChannelUp_Key, 0x34, 8);
  addKey("channel down", ChannelDown_Key, 0x35, 8);
  addKey("cm skip", Unmapped_Key, 0x37, 8);
  addKey("rapid play", Unmapped_Key, 0x38, 8);
  addKey("rec mode", Unmapped_Key, 0x39, 8);
  addKey("record", Record_Key, 0x3F, 8);

  addKey("KEY_POWER", Power_Key, 0x41, 8);
  addKey("KEY_AB", RepeatAB_Key, 0x43, 8);
  addKey("KEY_OPENCLOSE", Eject_Key, 0x44, 8);
  addKey("KEY_1", One_Key, 0x45, 8);
  addKey("KEY_2", Two_Key, 0x46, 8);
  addKey("KEY_3", Three_Key, 0x47, 8);
  addKey("KEY_4", Four_Key, 0x48, 8);
  addKey("KEY_5", Five_Key, 0x49, 8);
  addKey("KEY_6", Six_Key, 0x4A, 8);
  addKey("KEY_7", Seven_Key, 0x4B, 8);
  addKey("KEY_8", Eight_Key, 0x4C, 8);
  addKey("KEY_9", Nine_Key, 0x4D, 8);
  addKey("KEY_0", Zero_Key, 0x4E, 8);

  addKey("KEY_REPEAT", Repeat_Key, 0x50, 8);
  addKey("KEY_PLUSTEN", DoubleDigit_Key, 0x51, 8);
  addKey("KEY_REWIND", Rewind_Key, 0x52, 8);
  addKey("KEY_FASTFORWARD", FastForward_Key, 0x53, 8);
  addKey("KEY_DISPLAY", Info_Key, 0x55, 8);
  addKey("KEY_SEARCHMODE", Unmapped_Key, 0x57, 8);
  addKey("KEY_CLEAR", Clear_Key, 0x58, 8);
  addKey("KEY_PAUSE", Pause_Key, 0x5B, 8);
  addKey("KEY_MODE", Mode_Key, 0x5C, 8);
  addKey("KEY_PREVIOUS", Previous_Key, 0x5D, 8);
  addKey("KEY_PLAY", Play_Key, 0x5E, 8);
  addKey("KEY_NEXT", Next_Key, 0x5F, 8);

  addKey("KEY_STOP", Stop_Key, 0x60, 8);
  addKey("KEY_TOPMENU", DiscTitle_Key, 0x70, 8);
  addKey("KEY_MENU", DiscMenu_Key, 0x71, 8);
  addKey("KEY_ENTER", Select_Key, 0x72, 8);
  addKey("KEY_RETURN", Exit_Key, 0x73, 8);
  addKey("KEY_SETUP", Menu_Key, 0x74, 8);
  addKey("KEY_LEFTARROW", Left_Key, 0x75, 8);
  addKey("KEY_RIGHTARROW", Right_Key, 0x76, 8);
  addKey("KEY_UPARROW", Up_Key, 0x77, 8);
  addKey("KEY_DOWNARROW", Down_Key, 0x78, 8);
  addKey("KEY_ANGLE", Angle_Key, 0x79, 8);
  addKey("KEY_SUBTITLE", Captions_Key, 0x7A, 8);
  addKey("KEY_AUDIO", Audio_Key, 0x7B, 8);

  addKey("zoom", Zoom_Key, 0x81, 8);
}


EmersonAudio1::EmersonAudio1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 1",
      Emerson_Make,
      index)
{
}


void EmersonAudio1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new F12Protocol(guiObject, index);

  setPreData(0x5, 3);

  addKey("Volume Up", VolumeUp_Key, 0x04, 8);
  addKey("Pro Logic", NoiseReduction_Key, 0x05, 8);
  addKey("Volume Down", VolumeDown_Key, 0x08, 8);
  addKey("3 Channel", Unmapped_Key, 0x09, 8);
  addKey("Music", Unmapped_Key, 0x11, 8);
  addKey("Test Tone", Unmapped_Key, 0x21, 8);
  addKey("Power", Power_Key, 0x41, 8);
}


EmersonAudio2::EmersonAudio2(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 2",
      Emerson_Make,
      index)
{
}


void EmersonAudio2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new F12Protocol(guiObject, index);

  setPreData(0x3, 3);

  addKey("mute", Mute_Key, 0x05, 8);
  addKey("power", Power_Key, 0x09, 8);
  addKey("stop/clear", Stop_Key, 0x11, 8);
  addKey("play/pause", Play_Key, 0x21, 8);
  addKey("play/pause", Pause_Key, 0x21, 8);

  addKey("volume_up", VolumeUp_Key, 0x20, 8);
  addKey("volume_down", VolumeDown_Key, 0x40, 8);
}


EmersonAudio3::EmersonAudio3(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 3",
      Emerson_Make,
      index)
{
}


void EmersonAudio3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new F12Protocol(guiObject, index);

  setPreData(0x3, 3);

  addKey("vol up", VolumeUp_Key, 0x04, 8);
  addKey("mute", Mute_Key, 0x05, 8);
  addKey("vol down", VolumeDown_Key, 0x08, 8);
  addKey("power", Power_Key, 0x09, 8);
  addKey("stop", Stop_Key, 0x10, 8);
  addKey("play/pause", Play_Key, 0x11, 8);
  addKey("play/pause", Pause_Key, 0x11, 8);
  addKey("skip back", Previous_Key, 0x20, 8);
  addKey("skip fwd", Next_Key, 0x40, 8);
}
