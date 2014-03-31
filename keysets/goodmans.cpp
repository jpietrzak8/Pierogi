//
// goodmans.cpp
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

#include "goodmans.h"
#include "protocols/rc5protocol.h"
#include "protocols/necprotocol.h"

GoodmansSTB1::GoodmansSTB1(
  unsigned int index)
  : PIRKeysetMetaData(
      "STB Keyset 1",
      Goodmans_Make,
      index)
{
}


void GoodmansSTB1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

  addKey("Power", Power_Key, 0x120C, 13);
  addKey("TV/DTV", Input_Key, 0x120E, 13);
  addKey("MUTE", Mute_Key, 0x120D, 13);
  addKey("1", One_Key, 0x1201, 13);
  addKey("2", Two_Key, 0x1202, 13);
  addKey("3", Three_Key, 0x1203, 13);
  addKey("4", Four_Key, 0x1204, 13);
  addKey("5", Five_Key, 0x1205, 13);
  addKey("6", Six_Key, 0x1206, 13);
  addKey("7", Seven_Key, 0x1207, 13);
  addKey("8", Eight_Key, 0x1208, 13);
  addKey("9", Nine_Key, 0x1209, 13);
  addKey("WIDE", AspectRatio_Key, 0x121E, 13);
  addKey("0", Zero_Key, 0x1200, 13);
  addKey("GUIDE", Guide_Key, 0x1222, 13);
  addKey("P-", ChannelDown_Key, 0x1221, 13);
  addKey("P+", ChannelUp_Key, 0x1220, 13);
  addKey("V-", VolumeDown_Key, 0x1211, 13);
  addKey("V+", VolumeUp_Key, 0x1210, 13);
  addKey("i", Info_Key, 0x123F, 13); // is this right?
  addKey("MENU", Menu_Key, 0x1235, 13);
  addKey("RED", Red_Key, 0x1237, 13);
  addKey("UP", Up_Key, 0x1212, 13);
  addKey("BLUE", Blue_Key, 0x1234, 13);
  addKey("LEFT", Left_Key, 0x1215, 13);
  addKey("SELECT", Select_Key, 0x1214, 13);
  addKey("RIGHT", Right_Key, 0x1216, 13);
  addKey("GREEN", Green_Key, 0x1236, 13);
  addKey("DOWN", Down_Key, 0x1213, 13);
  addKey("YELLOW", Yellow_Key, 0x1232, 13);
  addKey("EXIT", Exit_Key, 0x120A, 13);
  addKey("TEXT", Teletext_Key, 0x123C, 13);
  addKey("SUBTITLE", Captions_Key, 0x1226, 13);
}


GoodmansVCR1::GoodmansVCR1(
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      Goodmans_Make,
      index)
{
}


void GoodmansVCR1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, false);

  setPreData(0x7B80, 16);

  addKey("VCR_ON", Power_Key, 0x13, 8);
  addKey("EJECT", Eject_Key, 0x4E, 8);
  addKey("TIMER_REC", RecordTimed_Key, 0x0D, 8);
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
  addKey("-/--", DoubleDigit_Key, 0x0F, 8);
  addKey("TV/VCR", Input_Key, 0x12, 8);
  addKey("CHANNEL+", ChannelUp_Key, 0x0A, 8);
  addKey("CHANNEL-", ChannelDown_Key, 0x0B, 8);
  addKey("SPEED_SP/LP", VHSSpeed_Key, 0x1E, 8);
  addKey("CALL", Call_Key, 0x5F, 8);
  addKey("REC/QTR", Record_Key, 0x15, 8);
  addKey("PAUSE", Pause_Key, 0x1A, 8);
  addKey("Play/Slow/Up", Play_Key, 0x16, 8);
  addKey("Play/Slow/Up", Slow_Key, 0x16, 8);
  addKey("Play/Slow/Up", Up_Key, 0x16, 8);
  addKey("Stop/Down", Stop_Key, 0x17, 8);
  addKey("Stop/Down", Down_Key, 0x17, 8);
  addKey("Rew/Left", Rewind_Key, 0x19, 8);
  addKey("Rew/Left", Left_Key, 0x19, 8);
  addKey("FF/Right", FastForward_Key, 0x18, 8);
  addKey("FF/Right", FastForward_Key, 0x18, 8);
  addKey("VIDEO_PLUS+_PROGRAM", Unmapped_Key, 0x1D, 8); // obsolete
  addKey("ENTER", Select_Key, 0x45, 8);
  addKey("MENU", Menu_Key, 0x50, 8);
  addKey("CANCEL", Exit_Key, 0x4A, 8);
  addKey("INDEX", IndexSearch_Key, 0x14, 8);
  addKey("ATR", AutoTracking_Key, 0x52, 8);
  addKey("CLOCK/COUNTER", Unmapped_Key, 0x51, 8);
  addKey("COUNTER_MEMORY", Unmapped_Key, 0x4B, 8);
  addKey("COUNTER_RESET", Reset_Key, 0x4C, 8);
  addKey("AUDIO_SELECT", Audio_Key, 0x0E, 8);
}


GoodmansDVD1::GoodmansDVD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Goodmans_Make,
      index)
{
}


void GoodmansDVD1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x00, 8);

  addKey("PLAY", Play_Key, 0x47, 8);
  addKey("STOP", Stop_Key, 0x04, 8);
  addKey("PAUSE", Pause_Key, 0x05, 8);
  addKey("FFWD", FastForward_Key, 0x4B, 8);
  addKey("REV", Rewind_Key, 0x4A, 8);
  addKey("REVPLAY", Unmapped_Key, 0x08, 8);
  addKey("SLOW", Slow_Key, 0x09, 8);
  addKey("SKIP_F", Next_Key, 0x4F, 8);
  addKey("SKIP_R", Previous_Key, 0x4E, 8);
  addKey("PAL_NTSC", Unmapped_Key, 0x0C, 8);
  addKey("CLEAR", Clear_Key, 0x0D, 8);
  addKey("RETURN", Exit_Key, 0x53, 8);
  addKey("ZOOM", Zoom_Key, 0x10, 8);
  addKey("TITLE", DiscTitle_Key, 0x11, 8);
  addKey("SELECT", Select_Key, 0x57, 8);
  addKey("DOWN", Down_Key, 0x14, 8);
  addKey("MENU", DiscMenu_Key, 0x15, 8);
  addKey("LEFT", Left_Key, 0x19, 8);
  addKey("RIGHT", Right_Key, 0x5B, 8);
  addKey("ENTER", Enter_Key, 0x18, 8);
  addKey("UP", Up_Key, 0x1C, 8);
  addKey("DISPLAY", Info_Key, 0x5F, 8);
  addKey("SETUP", Menu_Key, 0x1D, 8);
  addKey("GOTO", Unmapped_Key, 0x5D, 8);
  addKey("PROG", Program_Key, 0x5C, 8);
  addKey("0", Zero_Key, 0x1E, 8);
  addKey("SUB_TITLE", Captions_Key, 0x1F, 8);
  addKey("9", Nine_Key, 0x55, 8);
  addKey("8", Eight_Key, 0x54, 8);
  addKey("7", Seven_Key, 0x16, 8);
  addKey("6", Six_Key, 0x49, 8);
  addKey("5", Five_Key, 0x48, 8);
  addKey("4", Four_Key, 0x0A, 8);
  addKey("3", Three_Key, 0x51, 8);
  addKey("2", Two_Key, 0x50, 8);
  addKey("1", One_Key, 0x12, 8);
  addKey("SUB_TITLE1", Unmapped_Key, 0x17, 8);
  addKey("AUDIO", Audio_Key, 0x0B, 8);
  addKey("L_R", Unmapped_Key, 0x13, 8);
  addKey("REPEAT", Repeat_Key, 0x1A, 8);
  addKey("A_B", RepeatAB_Key, 0x58, 8);
  addKey("EJECT", Eject_Key, 0x59, 8);
  addKey("ANGLE", Angle_Key, 0x1B, 8);
}


GoodmansAudio1::GoodmansAudio1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 1",
      Goodmans_Make,
      index)
{
  addControlledDevice(Goodmans_Make, "MD-305", Audio_Device);
}


void GoodmansAudio1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x6C87, 16);

  addKey("power", Power_Key, 0x0A, 8);
  addKey("tape", TapeInput_Key, 0x4B, 8);
  addKey("cd", CDInput_Key, 0x48, 8);
  addKey("tuner", TunerInput_Key, 0x4A, 8);
  addKey("aux", AuxInput_Key, 0x4D, 8);
  addKey("play", Play_Key, 0x12, 8);
  addKey("random", Random_Key, 0x13, 8);
  addKey("stop", Stop_Key, 0x11, 8);
  addKey("rew", Rewind_Key, 0x15, 8);
  addKey("repeat", Repeat_Key, 0x16, 8);
  addKey("ffwd", FastForward_Key, 0x14, 8);
  addKey("space", Unmapped_Key, 0x17, 8);
  addKey("display", Info_Key, 0x1A, 8);
  addKey("mute", Mute_Key, 0x1D, 8);
  addKey("vol-", VolumeDown_Key, 0x1F, 8);
  addKey("vol+", VolumeUp_Key, 0x1E, 8);
  addKey("tun+", ChannelUp_Key, 0x94, 8);
  addKey("tun-", ChannelDown_Key, 0x95, 8);
  addKey("mode", FMMode_Key, 0x4F, 8); // might be wrong
  addKey("band", FM_Key, 0x43, 8);
  addKey("program", Program_Key, 0x19, 8);
  addKey("intro", Unmapped_Key, 0x18, 8);
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
}
