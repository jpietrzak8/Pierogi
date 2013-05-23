//
// aiwa.cpp
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

#include "aiwa.h"
#include "protocols/aiwaprotocol.h"
#include "protocols/lircprotocol.h"
#include "protocols/necprotocol.h"

AiwaVCR1::AiwaVCR1(
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      Aiwa_Make,
      index)
{
  addControlledDevice(Aiwa_Make, "HV-CX100KER", VCR_Device);
}


void AiwaVCR1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new AiwaProtocol(guiObject, index);

  setPreData(0x007F, 13);

  addKey("POWER", Power_Key, 0x00, 8);
  addKey("1", One_Key, 0x01, 8);
  addKey("2", Two_Key, 0x02, 8);
  addKey("3", Three_Key, 0x03, 8);
  addKey("4", Four_Key, 0x04, 8);
  addKey("5", Five_Key, 0x05, 8);
  addKey("6", Six_Key, 0x06, 8);
  addKey("7", Seven_Key, 0x07, 8);
  addKey("8", Eight_Key, 0x08, 8);
  addKey("9", Nine_Key, 0x09, 8);
  addKey("0", Zero_Key, 0x0A, 8);
  addKey("CH", Unmapped_Key, 0x0C, 8);
  addKey("TV/VCR", Unmapped_Key, 0x0D, 8);
  addKey("INPUT", Input_Key, 0x0E, 8);
  addKey("SLOW", Slow_Key, 0x0F, 8);

  addKey("COUNTDISPLAY", Info_Key, 0x10, 8);
  addKey("FORWARD", FastForward_Key, 0x11, 8);
  addKey("REWIND", Rewind_Key, 0x12, 8);
  addKey("Audio_MONI", Unmapped_Key, 0x13, 8);
  addKey("REC", Record_Key, 0x14, 8);
  addKey("PLAY", Play_Key, 0x15, 8);
  addKey("PAUSE", Pause_Key, 0x17, 8);
  addKey("Index_SkipForward", Next_Key, 0x18, 8);
  addKey("Index_SkipBack", Previous_Key, 0x19, 8);
//  addKey("ONETOUCH", Unmapped_Key, 0x19, 8); // need sub-keyset for this
  addKey("STOP", Stop_Key, 0x1A, 8);
  addKey("TIMER/PRG", Timer_Key, 0x1C, 8);
  addKey("T-REC", RecordTimed_Key, 0x1E, 8);
  addKey("CLEAR", Clear_Key, 0x1F, 8); // "CANCEL"

  addKey("CHAN_UP", ChannelUp_Key, 0x40, 8);
  addKey("CHAN_DOWN", ChannelDown_Key, 0x41, 8);
  addKey("Audio_DUB", Unmapped_Key, 0x42, 8);
  addKey("SAT", Unmapped_Key, 0x44, 8);
  addKey("Zero_Return", Unmapped_Key, 0x45, 8);
  addKey("TRACK+", TrackingPlus_Key, 0x46, 8);
  addKey("TRACK-", TrackingMinus_Key, 0x47, 8);
  addKey("EJECT", Eject_Key, 0x48, 8);
  addKey("AD-Skip", Advance_Key, 0x49, 8);
  addKey("SUPER_CLEAR", Unmapped_Key, 0x4B, 8);
  addKey("RESET", Reset_Key, 0x4C, 8); // "Counter_Reset"
  addKey("INDEXSRCH", IndexSearch_Key, 0x4D, 8);
  addKey("SP/LP", VHSSpeed_Key, 0x50, 8);
  addKey("MEMORY", Memory_Key, 0x51, 8);
  addKey("AUTO", Unmapped_Key, 0x53, 8);
  addKey("CLOCK", Clock_Key, 0x56, 8);
  addKey("A-TR", AutoTracking_Key, 0x5C, 8);
  addKey("Tape_Remain", Unmapped_Key, 0x5E, 8);
  addKey("REPEAT", Repeat_Key, 0x5F, 8);

  addKey("Fwd(Jog)", StepForward_Key, 0x65, 8);
  addKey("Rev(Jog)", StepBack_Key, 0x74, 8);

  addKey("MENU", Menu_Key, 0x81, 8);
  addKey("VPS/PDC", RecordPDC_Key, 0x82, 8);
//  addKey("NEXT", Next_Key, 0x83, 8);
  addKey("MENURIGHT", Right_Key, 0x83, 8);
  addKey("MENULEFT", Left_Key, 0x84, 8);
  addKey("OTPB", OneTouchPlayBack_Key, 0x89, 8);
  addKey("MENUUP", Up_Key, 0x8D, 8);
  addKey("MENUDOWN", Down_Key, 0x8E, 8);

  addKey("Showview_DeLuxe", Unmapped_Key, 0x98, 8);
  addKey("Add_T", Unmapped_Key, 0x99, 8);
  addKey("D/WLY", Unmapped_Key, 0x9A, 8);
  addKey("Set_Ch.No", Unmapped_Key, 0x9D, 8);
  addKey("Set_Auto", Unmapped_Key, 0x9E, 8);
  addKey("OK", Select_Key, 0x9F, 8);

  addKey("GUIDE", Guide_Key, 0xB0, 8);
  addKey("Audio_MIX", Unmapped_Key, 0xB5, 8);
  addKey("TheatreMode_BBE", Unmapped_Key, 0xB9, 8);
  addKey("TheatreMode_Q.Surround", Unmapped_Key, 0xBA,8);
  addKey("TheatreMode_Midnight", Unmapped_Key, 0xBB, 8);
}


AiwaVCR2::AiwaVCR2(
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 2",
      Aiwa_Make,
      index)
{
}


void AiwaVCR2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x6E, 8);

  addKey("eject", Eject_Key, 0x00, 8);
  addKey("stop", Stop_Key, 0x01, 8);
  addKey("rew", Rewind_Key, 0x02, 8);
  addKey("ff", FastForward_Key, 0x03, 8);
  addKey("0", Zero_Key, 0x04, 8);
  addKey("1", One_Key, 0x05, 8);
  addKey("2", Two_Key, 0x06, 8);
  addKey("3", Three_Key, 0x07, 8);
  addKey("play", Play_Key, 0x08, 8);
  addKey("rec/otr", Record_Key, 0x09, 8);
  addKey("pause", Pause_Key, 0x0B, 8);
  addKey("4", Four_Key, 0x0C, 8);
  addKey("5", Five_Key, 0x0D, 8);
  addKey("6", Six_Key, 0x0E, 8);
  addKey("7", Seven_Key, 0x0F, 8);

  addKey("power", Power_Key, 0x14, 8);
  addKey("tv/vcr", Input_Key, 0x15, 8);
  addKey("menu/i", Menu_Key, 0x16, 8);
  addKey("8", Eight_Key, 0x1C, 8);
  addKey("9", Nine_Key, 0x1D, 8);
  addKey("clear", Clear_Key, 0x1F, 8);

  addKey("child-lock", Unmapped_Key, 0x3F, 8);
  addKey("viss", IndexSearch_Key, 0x41, 8);
  addKey("showview", Unmapped_Key, 0x47, 8);
  addKey("speed", VHSSpeed_Key, 0x48, 8);
  addKey("av", Unmapped_Key, 0x56, 8);
  addKey("a-tr", AutoTracking_Key, 0x5F, 8);

  addKey("up", Up_Key, 0x82, 8);
  addKey("left", Left_Key, 0x83, 8);
  addKey("down", Down_Key, 0x89, 8);
  addKey("ok/clk/cnt", Select_Key, 0x8E, 8);
  addKey("right", Right_Key, 0x90, 8);

  addKey("fav.program", Unmapped_Key, 0xB3, 8);
  addKey("rec-end-search", Next_Key, 0xB5, 8); // might be wrong
  addKey("otpb", OneTouchPlayBack_Key, 0xBF, 8);
  addKey("ad-skip", Advance_Key, 0xDD, 8);
}


AiwaVCR3::AiwaVCR3(
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 3",
      Aiwa_Make,
      index)
{
}


void AiwaVCR3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, false);

  setPreData(0x7B80, 16);

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
  addKey("ch+", ChannelUp_Key, 0x0A, 8);
  addKey("ch-", ChannelDown_Key, 0x0B, 8);
  addKey("t-rec", RecordTimed_Key, 0x0D, 8);
  addKey("audio", Audio_Key, 0x0E, 8);
  addKey("-/--", DoubleDigit_Key, 0x0F, 8);
  addKey("tv/vcr", Input_Key, 0x12, 8);
  addKey("power", Power_Key, 0x13, 8);
  addKey("index", Unmapped_Key, 0x14, 8);
  addKey("rec", Record_Key, 0x15, 8);
  addKey("play", Play_Key, 0x16, 8);
  addKey("stop", Stop_Key, 0x17, 8);
  addKey("ff", FastForward_Key, 0x18, 8);
  addKey("rew", Rewind_Key, 0x19, 8);
  addKey("pause", Pause_Key, 0x1A, 8);
  addKey("otpb", OneTouchPlayBack_Key, 0x1B, 8);
  addKey("vidplus", Unmapped_Key, 0x1D, 8);
  addKey("speed", VHSSpeed_Key, 0x1E, 8);
  addKey("slow", Slow_Key, 0x1F, 8);
  addKey("up", Up_Key, 0x41, 8);
  addKey("down", Down_Key, 0x42, 8);
  addKey("select", Select_Key, 0x45, 8);
  addKey("left", Left_Key, 0x49, 8);
  addKey("cancel", Clear_Key, 0x4A, 8);
  addKey("zero", Unmapped_Key, 0x4B, 8);
  addKey("reset", Reset_Key, 0x4C, 8);
  addKey("right", Right_Key, 0x4D, 8);
  addKey("eject", Eject_Key, 0x4E, 8);
  addKey("menu", Menu_Key, 0x50, 8);
  addKey("counter", Unmapped_Key, 0x51, 8);
  addKey("tracking", AutoTracking_Key, 0x52, 8);
  addKey("ad-skip", Advance_Key, 0x5C, 8);
  addKey("call", Call_Key, 0x5F, 8);
}


AiwaAudio1::AiwaAudio1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 1",
      Aiwa_Make,
      index)
{
  addControlledDevice(Aiwa_Make, "LCX-100", Audio_Device);
  addControlledDevice(Aiwa_Make, "RC-TD3", Audio_Device);
}


void AiwaAudio1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new AiwaProtocol(guiObject, index);

  setPreData(0x0070, 13);

  addKey("power", Power_Key, 0x00, 8);
  addKey("tape", TapeInput_Key, 0x0C, 8);
  addKey("tuner", TunerInput_Key, 0x0D, 8);
  addKey("cd", CDInput_Key, 0x0E, 8);

  addKey("volume_up", VolumeUp_Key, 0x11, 8);
  addKey("volume_down", VolumeDown_Key, 0x12, 8);
  addKey("tuner_band", AM_Key, 0x13, 8);  // This is a hack
  addKey("tuner_band", FM_Key, 0x13, 8);  // This too
  addKey("tape_play", Unmapped_Key, 0x14, 8);
  addKey("tape_stop", Unmapped_Key, 0x15, 8);
  addKey("tape_next", Unmapped_Key, 0x16, 8);
  addKey("tape_prev", Unmapped_Key, 0x17, 8);
  addKey("tape_rec", Unmapped_Key, 0x18, 8);
  addKey("tape_pause", Unmapped_Key, 0x19, 8);
  addKey("geq", Unmapped_Key, 0x1F, 8); // "mode", "CD_MODE"

  addKey("sleep", Sleep_Key, 0x40, 8);
  addKey("tuner_mode", FMMode_Key, 0x4E, 8); // "FM_MODE"
  addKey("REPEAT", Repeat_Key, 0x51, 8);
  addKey("set", Memory_Key, 0x52, 8); // "MEMORY"
  addKey("CANCEL", Clear_Key, 0x53, 8);
  addKey("timer", Timer_Key, 0x5A, 8);
  addKey("aux", AuxInput_Key, 0x5D, 8); // "DAT_AUX"

  addKey("DISPLAY", Info_Key, 0x80, 8);
  addKey("random", Random_Key, 0x8F, 8);
  addKey("1", One_Key, 0x91, 8);
  addKey("2", Two_Key, 0x92, 8);
  addKey("3", Three_Key, 0x93, 8);
  addKey("4", Four_Key, 0x94, 8);
  addKey("5", Five_Key, 0x95, 8);
  addKey("6", Six_Key, 0x96, 8);
  addKey("7", Seven_Key, 0x97, 8);
  addKey("8", Eight_Key, 0x98, 8);
  addKey("9", Nine_Key, 0x99, 8);
  addKey("0", Zero_Key, 0x9A, 8);
  addKey("+10", DoubleDigit_Key, 0x9B, 8);

  addKey("play", Play_Key, 0xC4, 8); // "ENTER", "UP"
  addKey("play", Up_Key, 0xC4, 8); // "ENTER", "UP"
  addKey("stop", Stop_Key, 0xC5, 8); // "DOWN"
  addKey("stop", Down_Key, 0xC5, 8); // "DOWN"
  addKey("forward", FastForward_Key, 0xC6, 8); // "RIGHT", "next"
  addKey("forward", Right_Key, 0xC6, 8); // "RIGHT", "next"
  addKey("SKIP-SEARCH-TUNING-RIGHT", ChannelUp_Key, 0xC6, 8);
  addKey("back", Rewind_Key, 0xC7, 8); // "LEFT", "prev"
  addKey("back", Left_Key, 0xC7, 8); // "LEFT", "prev"
  addKey("SKIP-SEARCH-TUNING-LEFT", ChannelDown_Key, 0xC7, 8);
  addKey("PAUSE", Pause_Key, 0xC9, 8);
  addKey("dimmer", Unmapped_Key, 0xCD, 8);
  addKey("tray", Eject_Key, 0xCF, 8);
}


AiwaAudio1a::AiwaAudio1a(
  unsigned int index)
  : AiwaAudio1(index)
{
  setKeysetName("Audio Keyset 1a");

  addControlledDevice(Aiwa_Make, "XR-M201", Audio_Device);
  addControlledDevice(Aiwa_Make, "CA-DW635", Audio_Device);
}


// Don't know why only the numbers are different for this one:
void AiwaAudio1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  AiwaAudio1::populateProtocol(guiObject);

  addKey("1", One_Key, 0x01, 8);
  addKey("2", Two_Key, 0x02, 8);
  addKey("3", Three_Key, 0x03, 8);
  addKey("4", Four_Key, 0x04, 8);
  addKey("5", Five_Key, 0x05, 8);
  addKey("6", Six_Key, 0x06, 8);
  addKey("7", Seven_Key, 0x07, 8);
  addKey("8", Eight_Key, 0x08, 8);
  addKey("9", Nine_Key, 0x09, 8);
  addKey("0", Zero_Key, 0x0A, 8);
  addKey("+10", DoubleDigit_Key, 0x0B, 8);

  addKey("EQ", Unmapped_Key, 0xCA, 8);
}


AiwaAudio2::AiwaAudio2(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 2",
      Aiwa_Make,
      index)
{
  addControlledDevice(Aiwa_Make, "NSX-S22", Audio_Device);
  addControlledDevice(Aiwa_Make, "NSX-532", Audio_Device);
  addControlledDevice(Aiwa_Make, "NSX-AV320", Audio_Device);
  addControlledDevice(Aiwa_Make, "XR-M35", Audio_Device);
  addControlledDevice(Aiwa_Make, "LCX50", Audio_Device);
  addControlledDevice(Aiwa_Make, "NSX-V929", Audio_Device);
  addControlledDevice(Aiwa_Make, "NSX-V30", Audio_Device);
  addControlledDevice(Aiwa_Make, "NSX-V25", Audio_Device);
  addControlledDevice(Aiwa_Make, "NSX-320", Audio_Device);
  addControlledDevice(Aiwa_Make, "NSX-330", Audio_Device);
  addControlledDevice(Aiwa_Make, "NSX-500", Audio_Device);
  addControlledDevice(Aiwa_Make, "NSX-540", Audio_Device);
  addControlledDevice(Aiwa_Make, "NSX-DR5", Audio_Device);
}


void AiwaAudio2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new AiwaProtocol(guiObject, index);

  setPreData(0x006E, 13);

  addKey("power", Power_Key, 0x00, 8);
  addKey("1", One_Key, 0x01, 8);
  addKey("2", Two_Key, 0x02, 8);
  addKey("3", Three_Key, 0x03, 8);
  addKey("4", Four_Key, 0x04, 8);
  addKey("5", Five_Key, 0x05, 8);
  addKey("6", Six_Key, 0x06, 8);
  addKey("7", Seven_Key, 0x07, 8);
  addKey("8", Eight_Key, 0x08, 8);
  addKey("9", Nine_Key, 0x09, 8);
  addKey("0", Zero_Key, 0x0A, 8);
  addKey("plus10", DoubleDigit_Key, 0x0B, 8);
  addKey("shift7", Timer_Key, 0x0C, 8); // "timer"
  addKey("shift8", Sleep_Key, 0x0E, 8); // "sleep"

  addKey("shift9", Unmapped_Key, 0x11, 8); // "clock"
  addKey("shift0", FMMode_Key, 0x12, 8); // "mono tuner"
  addKey("EJECT", Eject_Key, 0x13, 8); // "OPEN"
  addKey("KARAOKE_ENTER", Unmapped_Key, 0x14, 8);
  addKey("shift3", Random_Key, 0x15, 8); // "random/repeat"
  addKey("REPEAT", Repeat_Key, 0x16, 8);
  addKey("shift1", Unmapped_Key, 0x17, 8); // "edit/check"
  addKey("shift2", Program_Key, 0x19, 8); // "prgm"
  addKey("TAPE", TapeInput_Key, 0x1B, 8); // "Deck"
  addKey("shiftplus10", Unmapped_Key, 0x1C, 8); // "band"
  addKey("VIDEO", AuxInput_Key, 0x1D, 8); // "aux"
  addKey("function", Unmapped_Key, 0x1E, 8);
  addKey("CD", CDInput_Key, 0x1F, 8);

  addKey("play", Play_Key, 0x40, 8); // "direction"
  addKey("stop", Stop_Key, 0x41, 8); // "clear"
  addKey("stop", Clear_Key, 0x41, 8); // "clear"
  addKey("next", FastForward_Key, 0x42, 8); // "FF", "up"
  addKey("next", Up_Key, 0x42, 8); // "FF", "up"
  addKey("prev", Rewind_Key, 0x43, 8); // "REW", "down"
  addKey("prev", Down_Key, 0x43, 8); // "REW", "down"
  addKey("pause", Pause_Key, 0x44, 8); // "SET"
  addKey("record", Record_Key, 0x45, 8);
  addKey("Rec_Mute", RecordMute_Key, 0x46, 8);
  addKey("shift6", EnhancedBass_Key, 0x47, 8); // "t-bass"
  addKey("bbe", Unmapped_Key, 0x48, 8);
  addKey("shift4", Unmapped_Key, 0x49, 8); // "geq" "eq" equalizer?
  addKey("DSP", Surround_Key, 0x4A, 8); // "qsurround"
  addKey("Mute", Mute_Key, 0x4C, 8);
  addKey("volup", VolumeUp_Key, 0x4D, 8);
  addKey("voldown", VolumeDown_Key, 0x4E, 8);

  addKey("vocal_fader", Unmapped_Key, 0x50, 8); // "KARAOKE"
  addKey("cd1", DiscOne_Key, 0x51, 8); // "DDP_1"
  addKey("cd2", DiscTwo_Key, 0x52, 8); // "DDP_2"
  addKey("cd3", DiscThree_Key, 0x53, 8); // "DDP_3"
  addKey("DISCSKIP", NextDisc_Key, 0x56, 8);
  addKey("Treble", Unmapped_Key, 0x57, 8);
  addKey("MANUAL", Unmapped_Key, 0x58, 8);
  addKey("phrase_repeat", RepeatAB_Key, 0x5A, 8);
  addKey("DOLBY", NoiseReduction_Key, 0x6A, 8);
  addKey("md", MDInput_Key, 0x70, 8);
  addKey("Enter", Enter_Key, 0x73, 8);
}


AiwaAudio2a::AiwaAudio2a(
  unsigned int index)
  : AiwaAudio2(index)
{
  setKeysetName("Audio Keyset 2a");
}


void AiwaAudio2a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  AiwaAudio2::populateProtocol(guiObject);

  addKey("Rec", Record_Key, 0x5F, 8);
  addKey("ChUp", ChannelUp_Key, 0x86, 8);
  addKey("ChDown", ChannelDown_Key, 0x85, 8);
}


AiwaAudio2b::AiwaAudio2b(
  unsigned int index)
  : AiwaAudio2(index)
{
  setKeysetName("Audio Keyset 2b");
}


void AiwaAudio2b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  AiwaAudio2::populateProtocol(guiObject);

  addKey("UP", Up_Key, 0x40, 8);
  addKey("DOWN", Down_Key, 0x41, 8);
  addKey("RIGHT", Right_Key, 0x42, 8);
  addKey("LEFT", Left_Key, 0x43, 8);
}


AiwaAudio2c::AiwaAudio2c(
  unsigned int index)
  : AiwaAudio2(index)
{
  setKeysetName("Audio Keyset 2c");

  addControlledDevice(Aiwa_Make, "XR-MD201", Audio_Device);
}


void AiwaAudio2c::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  AiwaAudio2::populateProtocol(guiObject);

  addKey("display", Info_Key, 0x14, 8);
  addKey("rec", Record_Key, 0x71, 8);
  addKey("drec", Unmapped_Key, 0x72, 8);
  addKey("md_mark", Unmapped_Key, 0x73, 8);
  addKey("mode", Mode_Key, 0x76, 8);
  addKey("tit_inp", Unmapped_Key, 0x77, 8);
}


// Might not be audio here:
AiwaAudio3::AiwaAudio3(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 3",
      Aiwa_Make,
      index)
{
}


void AiwaAudio3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new AiwaProtocol(guiObject, index);

  setPreData(0x007B, 13);

  addKey("Power", Power_Key, 0x00, 8);
  addKey("1", One_Key, 0x01, 8);
  addKey("2", Two_Key, 0x02, 8);
  addKey("3", Three_Key, 0x03, 8);
  addKey("4", Four_Key, 0x04, 8);
  addKey("5", Five_Key, 0x05, 8);
  addKey("6", Six_Key, 0x06, 8);
  addKey("7", Seven_Key, 0x07, 8);
  addKey("8", Eight_Key, 0x08, 8);
  addKey("9", Nine_Key, 0x09, 8);
  addKey("0", Zero_Key, 0x0A, 8);

  addKey("Yellow", Yellow_Key, 0x13, 8);
  addKey("Right", Right_Key, 0x18, 8);
  addKey("Left", Left_Key, 0x19, 8);
  addKey("Ok", Select_Key, 0x1B, 8);

  addKey("Up", Up_Key, 0x40, 8);
  addKey("Down", Down_Key, 0x41, 8);
  addKey("Volume-", VolumeDown_Key, 0x43, 8);
  addKey("Mute", Mute_Key, 0x4A, 8);
  addKey("Blue", Blue_Key, 0x4B, 8);
  addKey("RED", Red_Key, 0x4E, 8);
  addKey("Volume+", VolumeUp_Key, 0x4F, 8);

  addKey("Back", Exit_Key, 0x90, 8);
  addKey("Menu", Menu_Key, 0xC4, 8);
  addKey("Green", Green_Key, 0xDC, 8);
}


AiwaAudio4::AiwaAudio4(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 4",
      Aiwa_Make,
      index)
{
}


void AiwaAudio4::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new AiwaProtocol(guiObject, index);

  setPreData(0x00F6, 13);

  addKey("1", One_Key, 0x01, 8);
  addKey("2", Two_Key, 0x02, 8);
  addKey("3", Three_Key, 0x03, 8);
  addKey("4", Four_Key, 0x04, 8);
  addKey("5", Five_Key, 0x05, 8);
  addKey("6", Six_Key, 0x06, 8);
  addKey("7", Seven_Key, 0x07, 8);
  addKey("8", Eight_Key, 0x08, 8);
  addKey("9", Nine_Key, 0x09, 8);
  addKey("10", Zero_Key, 0x0A, 8); // best I can do for now
  addKey("greater_20", DoubleDigit_Key, 0x0B, 8);
  addKey("open_close", Eject_Key, 0x0C, 8);
  addKey("program", Program_Key, 0x0D, 8);
  addKey("delete", Unmapped_Key, 0x0E, 8);
  addKey("check", Unmapped_Key, 0x0F, 8);

  addKey("search_forw", FastForward_Key, 0x11, 8);
  addKey("search_back", Rewind_Key, 0x12, 8);
  addKey("random", Random_Key, 0x13, 8);
  addKey("play", Play_Key, 0x15, 8);
  addKey("pause", Pause_Key, 0x17, 8);
  addKey("skip_forw", Advance_Key, 0x18, 8);
  addKey("skip_back", Replay_Key, 0x19, 8);
  addKey("stop", Stop_Key, 0x1A, 8);
  addKey("repeat_1_all", Repeat_Key, 0x1B, 8);
  addKey("repeat_a_b", RepeatAB_Key, 0x1C, 8);
  addKey("index_forw", Next_Key, 0x1D, 8);
  addKey("index_back", Previous_Key, 0x1E, 8);
  addKey("time", Unmapped_Key, 0x1F, 8);

  addKey("ac", Unmapped_Key, 0x2E, 8);

  addKey("blank", Unmapped_Key, 0x40, 8);
  addKey("11", Unmapped_Key, 0x41, 8);
  addKey("12", Unmapped_Key, 0x42, 8);
  addKey("13", Unmapped_Key, 0x43, 8);
  addKey("14", Unmapped_Key, 0x44, 8);
  addKey("15", Unmapped_Key, 0x45, 8);
  addKey("16", Unmapped_Key, 0x46, 8);
  addKey("17", Unmapped_Key, 0x47, 8);
  addKey("18", Unmapped_Key, 0x48, 8);
  addKey("19", Unmapped_Key, 0x49, 8);
  addKey("20", Unmapped_Key, 0x4A, 8);
}


AiwaAudio5::AiwaAudio5(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 5",
      Aiwa_Make,
      index)
{
}


void AiwaAudio5::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new AiwaProtocol(guiObject, index);

  setPreData(0x0076, 13);

  addKey("1", One_Key, 0x01, 8);
  addKey("2", Two_Key, 0x02, 8);
  addKey("3", Three_Key, 0x03, 8);
  addKey("4", Four_Key, 0x04, 8);
  addKey("5", Five_Key, 0x05, 8);
  addKey("6", Six_Key, 0x06, 8);
  addKey("7", Seven_Key, 0x07, 8);
  addKey("8", Eight_Key, 0x08, 8);
  addKey("9", Nine_Key, 0x09, 8);
  addKey("0", Zero_Key, 0x0A, 8);
  addKey("+10", DoubleDigit_Key, 0x0B, 8);
  addKey("open", Eject_Key, 0x0C, 8);
  addKey("Prog", Program_Key, 0x0D, 8); // "on"
  addKey("cont", Unmapped_Key, 0x0F, 8);
  addKey("random", Random_Key, 0x13, 8);
  addKey("Play", Play_Key, 0x15, 8);
  addKey("Forward", FastForward_Key, 0x18, 8);
  addKey("Rewind", Rewind_Key, 0x19, 8);
  addKey("Stop", Stop_Key, 0x1A, 8);
  addKey("Rep/Rand", Repeat_Key, 0x1B, 8);
  addKey("display", Info_Key, 0x1F, 8);
}


AiwaAudio6::AiwaAudio6(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 6",
      Aiwa_Make,
      index)
{
  addControlledDevice(Aiwa_Make, "CX-770", Audio_Device);
  addControlledDevice(Aiwa_Make, "Series 70", Audio_Device);
}


void AiwaAudio6::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new AiwaProtocol(guiObject, index);

  setPreData(0x0048, 13);

  addKey("fm", FM_Key, 0x00, 8);
  addKey("am", AM_Key, 0x01, 8); // "MW"
  addKey("LW", LW_Key, 0x02, 8);
  addKey("t_up", ChannelUp_Key, 0x03, 8);
  addKey("power", Power_Key, 0x04, 8);
  addKey("t_down", ChannelDown_Key, 0x05, 8);
  addKey("v_up", VolumeUp_Key, 0x07, 8);
  addKey("v_down", VolumeDown_Key, 0x08, 8);
  addKey("muting", Mute_Key, 0x09, 8);
  addKey("cdp_program", Program_Key, 0x0A, 8);
  addKey("cdp_play", Play_Key, 0x0B, 8);
  addKey("cdp_memory", Memory_Key, 0x0C, 8);
  addKey("cdp_stop", Stop_Key, 0x0D, 8);
  addKey("cdp_fskip", FastForward_Key, 0x0E, 8);
  addKey("cdp_bskip", Rewind_Key, 0x0F, 8);
  addKey("VcrAux", AuxInput_Key, 0x10, 8);
  addKey("phono", PhonoInput_Key, 0x11, 8);
  addKey("tape", TapeInput_Key, 0x12, 8);
}


AiwaCarStereo1::AiwaCarStereo1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Car Stereo Keyset 1",
      Aiwa_Make,
      index)
{
}


void AiwaCarStereo1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x1386, 16);

  addKey("off", Power_Key, 0x00, 8);
  addKey("vol+", VolumeUp_Key, 0x0F, 8);
  addKey("vol-", VolumeDown_Key, 0x10, 8);
  addKey("disc_tune+", ChannelUp_Key, 0x11, 8);
  addKey("disc_tune-", ChannelDown_Key, 0x12, 8);
  addKey("radio_band", TunerInput_Key, 0x13, 8);
  addKey("tape", TapeInput_Key, 0x14, 8);
  addKey("ff_next", FastForward_Key, 0x16, 8);
  addKey("rew_prev", Rewind_Key, 0x17, 8);
  addKey("playpause", Play_Key, 0x1B, 8);
  addKey("playpause", Pause_Key, 0x1B, 8);
  addKey("preset_scan", Scan_Key, 0x1F, 8);
}


AiwaDVD1::AiwaDVD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Aiwa_Make,
      index)
{
}


void AiwaDVD1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  LIRCProtocol *lp = new LIRCProtocol(
    guiObject,
    index,
    500, 622,
    1629, 622,
    99349, false);

  threadableProtocol = lp;

  lp->setHeaderPair(1623, 615);
  lp->setRepeatPair(8967, 4467);

  addKey("KEY_POWER", Power_Key, 0x201, 10);
  addKey("KEY_SUBTITLE", Captions_Key, 0x32C, 10);
  addKey("KEY_RED", Red_Key, 0x2F1, 10);
  addKey("KEY_GREEN", Green_Key, 0x390, 10);
  addKey("KEY_YELLOW", Yellow_Key, 0x370, 10);
  addKey("KEY_BLUE", Blue_Key, 0x3AC, 10);
  addKey("KEY_EPG", Guide_Key, 0x360, 10);
  addKey("KEY_INFO", Info_Key, 0x211, 10);
  addKey("KEY_OK", Select_Key, 0x28D, 10);
  addKey("KEY_BACK", Exit_Key, 0x348, 10);
  addKey("KEY_MENU", Menu_Key, 0x30C, 10);
  addKey("KEY_UP", Up_Key, 0x24D, 10);
  addKey("KEY_DOWN", Down_Key, 0x34C, 10);
  addKey("KEY_LEFT", Left_Key, 0x3CC, 10);
  addKey("KEY_RIGHT", Right_Key, 0x2CD, 10);
  addKey("KEY_REWIND", Rewind_Key, 0x2D9, 10);
  addKey("KEY_PLAYPAUSE", Play_Key, 0x350, 10);
  addKey("KEY_PLAYPAUSE", Pause_Key, 0x350, 10);
  addKey("KEY_FORWARD", FastForward_Key, 0x358, 10);
  addKey("KEY_STOP", Stop_Key, 0x2B1, 10);
  addKey("KEY_RECORD", Record_Key, 0x3EC, 10);
  addKey("KEY_CHANNELUP", ChannelUp_Key, 0x231, 10);
  addKey("KEY_CHANNELDOWN", ChannelDown_Key, 0x330, 10);
  addKey("KEY_1", One_Key, 0x300, 10);
  addKey("KEY_2", Two_Key, 0x281, 10);
  addKey("KEY_3", Three_Key, 0x380, 10);
  addKey("KEY_4", Four_Key, 0x241, 10);
  addKey("KEY_5", Five_Key, 0x340, 10);
  addKey("KEY_6", Six_Key, 0x2C1, 10);
  addKey("KEY_7", Seven_Key, 0x3C0, 10);
  addKey("KEY_8", Eight_Key, 0x221, 10);
  addKey("KEY_9", Nine_Key, 0x320, 10);
  addKey("KEY_0", Zero_Key, 0x2A1, 10);
  addKey("KEY_MEDIA", Unmapped_Key, 0x348, 10);
}
