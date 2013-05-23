//
// sharp.cpp
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

#include "sharp.h"
#include "protocols/sharpprotocol.h"
#include "protocols/necprotocol.h"

SharpTV1::SharpTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Sharp_Make,
      index)
{
}


void SharpTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new SharpProtocol(guiObject, index, true);

  addSharpKey("1", One_Key, 0x01, 0x01);
  addSharpKey("2", Two_Key, 0x01, 0x02);
  addSharpKey("3", Three_Key, 0x01, 0x03);
  addSharpKey("4", Four_Key, 0x01, 0x04);
  addSharpKey("5", Five_Key, 0x01, 0x05);
  addSharpKey("6", Six_Key, 0x01, 0x06);
  addSharpKey("7", Seven_Key, 0x01, 0x07);
  addSharpKey("8", Eight_Key, 0x01, 0x08);
  addSharpKey("9", Nine_Key, 0x01, 0x09);
  addSharpKey("0", Zero_Key, 0x01, 0x0A);
  addSharpKey("100", PlusOneHundred_Key, 0x01, 0x0B);
  addSharpKey("stereo", Unmapped_Key, 0x01, 0x0C); // "VpsPds"
  addSharpKey("40+", Unmapped_Key, 0x01, 0x0F); // odd!

  addSharpKey("NR", NoiseReduction_Key, 0x01, 0x10);
  addSharpKey("CH_UP", ChannelUp_Key, 0x01, 0x11);
  addSharpKey("CH_DOWN", ChannelDown_Key, 0x01, 0x12);
  addSharpKey("TV/VIDEO", Input_Key, 0x01, 0x13);
  addSharpKey("VOL_UP", VolumeUp_Key, 0x01, 0x14);
  addSharpKey("VOL_DOWN", VolumeDown_Key, 0x01, 0x15);
  addSharpKey("POWER", Power_Key, 0x01, 0x16);
  addSharpKey("MUTE", Mute_Key, 0x01, 0x17); // "VOLUME_KILL"
  addSharpKey("SOUND_MODE", Audio_Key, 0x01, 0x18); // I/II/I+II
  addSharpKey("program_timer", Timer_Key, 0x01, 0x19); // "on_timer"
  addSharpKey("TIMER", Sleep_Key, 0x01, 0x1A);
  addSharpKey("INFO", Info_Key, 0x01, 0x1B); // "disp_del" "TEXT"
  addSharpKey("TIME", TeletextTime_Key, 0x01, 0x1C);
  addSharpKey("PROG", Program_Key, 0x01, 0x1D);

  addSharpKey("PICTURE_NORMALIZE", Unmapped_Key, 0x01, 0x21);
  addSharpKey("CONTRAST_UP", ContrastUp_Key, 0x01, 0x22);
  addSharpKey("CONTRAST_DOWN", ContrastDown_Key, 0x01, 0x23);
  addSharpKey("COLOR_UP", ColorUp_Key, 0x01, 0x24);
  addSharpKey("COLOR_DOWN", ColorDown_Key, 0x01, 0x25);
  addSharpKey("SOUND_NORMALIZE", Unmapped_Key, 0x01, 0x26);
  addSharpKey("BRIGHTNESS_UP", BrightnessUp_Key, 0x01, 0x28);
  addSharpKey("BRIGHTNESS_DOWN", BrightnessDown_Key, 0x01, 0x29);
  addSharpKey("CH_SWAP", PrevChannel_Key, 0x01, 0x27); // "FLASHBACK", "ret"
  addSharpKey("MONO", Unmapped_Key, 0x01, 0x2C);
  addSharpKey("BROWSE", Unmapped_Key, 0x01, 0x2F);
  addSharpKey("10+", Unmapped_Key, 0x01, 0x2F);

  addSharpKey("20+", Unmapped_Key, 0x01, 0x30);
  addSharpKey("30+", Unmapped_Key, 0x01, 0x31);
  addSharpKey("PICTURE", Unmapped_Key, 0x01, 0x32);
  addSharpKey("HOLD", TeletextHold_Key, 0x01, 0x33);
  addSharpKey("TELETEXT", Teletext_Key, 0x01, 0x34);
//  addSharpKey("SINGLE_DOUBLE", DoubleDigit_Key, 0x01, 0x35);
  addSharpKey("PROGRAM", Program_Key, 0x01, 0x36);
  addSharpKey("TOP_BOTTOM_FULL", TeletextSize_Key, 0x01, 0x37);
  addSharpKey("REVEAL", TeletextReveal_Key, 0x01, 0x38);
  addSharpKey("message", Unmapped_Key, 0x01, 0x3B);
  addSharpKey("./..", DoubleDigit_Key, 0x01, 0x3C);
  addSharpKey("p/c", Unmapped_Key, 0x01, 0x3D);

  addSharpKey("pr", Unmapped_Key, 0x01, 0x41);
  addSharpKey("COLOR_RED", Red_Key, 0x01, 0x48);
  addSharpKey("COLOR_GREEN", Green_Key, 0x01, 0x49);
  addSharpKey("COLOR_YELLOW", Yellow_Key, 0x01, 0x4A);
  addSharpKey("COLOR_BLUE", Blue_Key, 0x01, 0x4B);
  addSharpKey("INDEX", TeletextIndex_Key, 0x01, 0x4C);
  addSharpKey("MENU", Menu_Key, 0x01, 0x4D);
  addSharpKey("LOCK", Unmapped_Key, 0x01, 0x51);
  addSharpKey("RESET", Reset_Key, 0x01, 0x52);
  addSharpKey("FUNCTIONS", Unmapped_Key, 0x01, 0x5F);

  addSharpKey("PICTURE", PictureMode_Key, 0x01, 0x60);
  addSharpKey("SOUND", SoundMode_Key, 0x01, 0x61);
  addSharpKey("TREBLE_UP", TrebleUp_Key, 0x01, 0x62);
  addSharpKey("TREBLE_DOWN", TrebleDown_Key, 0x01, 0x63);
  addSharpKey("BASS_UP", BassUp_Key, 0x01, 0x64);
  addSharpKey("BASS_DOWN", BassDown_Key, 0x01, 0x65);
  addSharpKey("WOOFER_UP", Unmapped_Key, 0x01, 0x66);
  addSharpKey("WOOFER_DOWN", Unmapped_Key, 0x01, 0x67);
  addSharpKey("BALANCE_LEFT", BalanceLeft_Key, 0x01, 0x6B);
  addSharpKey("BALANCE_RIGHT", BalanceRight_Key, 0x01, 0x6C);
  addSharpKey("SURROUND", Surround_Key, 0x01, 0x6E);

  addSharpKey("calendar", Unmapped_Key, 0x01, 0x76);
  addSharpKey("language", Audio_Key, 0x01, 0x78);
  addSharpKey("BT_END", Unmapped_Key, 0x01, 0xF5);
  addSharpKey("AV_MODE", Unmapped_Key, 0x01, 0xF8);

  addSharpKey("AV-", Unmapped_Key, 0x11, 0x73); // reverse-direction input 
  addSharpKey("DTV", Unmapped_Key, 0x11, 0xA0);
  addSharpKey("DTV_MENU", Unmapped_Key, 0x11, 0xA1);
  addSharpKey("LIST", Unmapped_Key, 0x11, 0xA2);
  addSharpKey("RADIO", Unmapped_Key, 0x11, 0xA4);
  addSharpKey("ESG", Unmapped_Key, 0x11, 0xA7);
  addSharpKey("WIDE_MODES", AspectRatio_Key, 0x11, 0xC8);
  addSharpKey("TRUD", Unmapped_Key, 0x11, 0xDD);
  addSharpKey("ACTION", Unmapped_Key, 0x11, 0xF9);

  addSharpKey("BACKLIGHT", Unmapped_Key, 0x1E, 0x8B); // "OPC"
  addSharpKey("ROTATE", Unmapped_Key, 0x1E, 0x8C);
  addSharpKey("SUBTITLE", Captions_Key, 0x1E, 0x9F);
  addSharpKey("SUBPAGE", Unmapped_Key, 0x1E, 0xCD);
}


SharpTV1a::SharpTV1a(
  unsigned int index)
  : SharpTV1(index)
{
  setKeysetName("TV Keyset 1a");
}


void SharpTV1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  SharpTV1::populateProtocol(guiObject);

  addSharpKey("Key", Unmapped_Key, 0x01, 0x0D);
  addSharpKey("Time", Sleep_Key, 0x01, 0x0E);
  addSharpKey("Replay", Replay_Key, 0x01, 0x10);
  addSharpKey("TapeSpeed", VHSSpeed_Key, 0x01, 0x1F);
  addSharpKey("FF", FastForward_Key, 0x01, 0x21);
  addSharpKey("Play", Play_Key, 0x01, 0x22);
  addSharpKey("REW", Rewind_Key, 0x01, 0x23);
  addSharpKey("Pause", Pause_Key, 0x01, 0x25);
  addSharpKey("Stop", Stop_Key, 0x01, 0x27);
  addSharpKey("REC", Record_Key, 0x01, 0x28);
  addSharpKey("Slow", Slow_Key, 0x01, 0x29);
  addSharpKey("DPSS+", SlowPlus_Key, 0x01, 0x2F);
  addSharpKey("DPSS+", Next_Key, 0x01, 0x2F);

  addSharpKey("DPSS-", SlowMinus_Key, 0x01, 0x30);
  addSharpKey("DPSS-", Previous_Key, 0x01, 0x30);
  addSharpKey("Input", Input_Key, 0x01, 0x34);
  addSharpKey("ZeroBack", Unmapped_Key, 0x01, 0x83);
  addSharpKey("SkipSearch", Advance_Key, 0x01, 0x90);
}


SharpTV1b::SharpTV1b(
  unsigned int index)
  : SharpTV1(index)
{
  setKeysetName("TV Keyset 1b");
}


void SharpTV1b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  SharpTV1::populateProtocol(guiObject);

  addSharpKey("FINE_TUNING", Unmapped_Key, 0x01, 0x0E);
  addSharpKey("chScan", Scan_Key, 0x01, 0x1C);
  addSharpKey("setup", Menu_Key, 0x01, 0x20);
  addSharpKey("fback_clr", Unmapped_Key, 0x01, 0x2F);
  addSharpKey("BLUE_BACK", Unmapped_Key, 0x01, 0x3B);
  addSharpKey("SKIP", Unmapped_Key, 0x01, 0x47);
  addSharpKey("video", Input_Key, 0x01, 0x49);
  addSharpKey("plus", Up_Key, 0x01, 0x4F); // "UP"
  addSharpKey("minus", Down_Key, 0x01, 0x50); // "DOWN"
  addSharpKey("TIMER", Timer_Key, 0x01, 0x53);
  addSharpKey("SYSTEM_SOUND", SoundMode_Key, 0x01, 0x6F);
  addSharpKey("SYSTEM_COLOUR", PictureMode_Key, 0x01, 0x71);
}


SharpTV1c::SharpTV1c(
  unsigned int index)
  : SharpTV1(index)
{
  setKeysetName("TV Keyset 1c");
}


void SharpTV1c::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  SharpTV1::populateProtocol(guiObject);

  addSharpKey("save_ch", Unmapped_Key, 0x01, 0x41);
  addSharpKey("del_ch", Unmapped_Key, 0x01, 0x3D);
}


SharpTV1d::SharpTV1d(
  unsigned int index)
  : SharpTV1(index)
{
  setKeysetName("TV Keyset 1d");
}


void SharpTV1d::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  SharpTV1::populateProtocol(guiObject);

  addSharpKey("P-MODE", PictureMode_Key, 0x01, 0x4D);
  addSharpKey("S-MODE", SoundMode_Key, 0x01, 0x26);
}


SharpTV1e::SharpTV1e(
  unsigned int index)
  : SharpTV1(index)
{
  setKeysetName("TV Keyset 1e");
}


void SharpTV1e::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  SharpTV1::populateProtocol(guiObject);

  addSharpKey("DOWN", Down_Key, 0x01, 0x20);
  addSharpKey("OK", Select_Key, 0x01, 0x52);
  addSharpKey("UP", Up_Key, 0x01, 0x57);
  addSharpKey("LEFT", Left_Key, 0x01, 0xD7);
  addSharpKey("RIGHT", Right_Key, 0x01, 0xD8);
  addSharpKey("RETURN", Exit_Key, 0x01, 0xE4);

  addSharpKey("MENU", Menu_Key, 0x11, 0xC6);
}


SharpVCR1::SharpVCR1(
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      Sharp_Make,
      index)
{
}


void SharpVCR1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new SharpProtocol(guiObject, index, true);

  addSharpKey("1", One_Key, 0x03, 0x01);
  addSharpKey("2", Two_Key, 0x03, 0x02);
  addSharpKey("3", Three_Key, 0x03, 0x03);
  addSharpKey("4", Four_Key, 0x03, 0x04);
  addSharpKey("5", Five_Key, 0x03, 0x05);
  addSharpKey("6", Six_Key, 0x03, 0x06);
  addSharpKey("7", Seven_Key, 0x03, 0x07);
  addSharpKey("8", Eight_Key, 0x03, 0x08);
  addSharpKey("9", Nine_Key, 0x03, 0x09);
  addSharpKey("0", Zero_Key, 0x03, 0x0A);
  addSharpKey("./..", DoubleDigit_Key, 0x03, 0x0B);
  addSharpKey("Display", Info_Key, 0x03, 0x0C); // "vps"
  addSharpKey("Key", Unmapped_Key, 0x03, 0x0D);  // "C-LOCK", "tamper_proof"
  addSharpKey("TIME", Unmapped_Key, 0x03, 0x0E);
  addSharpKey("REC_TIME", Unmapped_Key, 0x03, 0x0F); // "TIME-0"
  addSharpKey("repeat", Repeat_Key, 0x03, 0x10);
  addSharpKey("ChnUp", ChannelUp_Key, 0x03, 0x11);
  addSharpKey("ChnDn", ChannelDown_Key, 0x03, 0x12);
  addSharpKey("TV/VCR", Unmapped_Key, 0x03, 0x13);
  addSharpKey("Power", Power_Key, 0x03, 0x16);
  addSharpKey("MUTE", Mute_Key, 0x03, 0x17);
  addSharpKey("AudioOut", Surround_Key, 0x03, 0x18);
  addSharpKey("TimerOn/Off", Unmapped_Key, 0x03, 0x19);
  addSharpKey("osp", Unmapped_Key, 0x03, 0x1C);
  addSharpKey("PROG", Program_Key, 0x03, 0x1D);
  addSharpKey("TapeSpeed", VHSSpeed_Key, 0x03, 0x1F);
  addSharpKey("Clear", Clear_Key, 0x03, 0x20);
  addSharpKey("FF", FastForward_Key, 0x03, 0x21);
  addSharpKey("Play", Play_Key, 0x03, 0x22);
  addSharpKey("Rew", Rewind_Key, 0x03, 0x23);
  addSharpKey("F.ADV", StepForward_Key, 0x03, 0x24);
  addSharpKey("Pause", Pause_Key, 0x03, 0x25);
  addSharpKey("Stop", Stop_Key, 0x03, 0x27);
  addSharpKey("Rec", Record_Key, 0x03, 0x28);
  addSharpKey("Slow", Slow_Key, 0x03, 0x29);
  addSharpKey("CLOCK", Clock_Key, 0x03, 0x2C);
  addSharpKey("DPSS+", SlowPlus_Key, 0x03, 0x2F); // "slow+"
  addSharpKey("DPSS+", Next_Key, 0x03, 0x2F);
  addSharpKey("DPSS-", SlowMinus_Key, 0x03, 0x30); // "slow-"
  addSharpKey("DPSS-", Previous_Key, 0x03, 0x30); // "slow-"
  addSharpKey("x2", PlayX2_Key, 0x03, 0x31);
  addSharpKey("EJECT", Eject_Key, 0x03, 0x33);
  addSharpKey("InputSelect", Input_Key, 0x03, 0x34); // "simul"
  addSharpKey("SEARCH", IndexSearch_Key, 0x03, 0x37);
  addSharpKey("ZeroBack", Unmapped_Key, 0x03, 0x83);  // "MEMORY"
  addSharpKey("cancel", Unmapped_Key, 0x03, 0x84);  // could be exit key
  addSharpKey("TRACKING_UP", TrackingPlus_Key, 0x03, 0x85);
  addSharpKey("TRACKING_DOWN", TrackingMinus_Key, 0x03, 0x86);
  addSharpKey("100", PlusOneHundred_Key, 0x03, 0x88);
  addSharpKey("ModeOsd", Unmapped_Key, 0x03, 0x8D);
  addSharpKey("SkipSearch", Unmapped_Key, 0x03, 0x90);
  addSharpKey("Menu", Menu_Key, 0x03, 0x98);
  addSharpKey("Up", Up_Key, 0x03, 0x99);
  addSharpKey("Set", Select_Key, 0x03, 0x9A);
  addSharpKey("Right", Right_Key, 0x03, 0x9B);
  addSharpKey("Dn", Down_Key, 0x03, 0x9C);
  addSharpKey("Left", Left_Key, 0x03, 0x9D);
  addSharpKey("SHUTTLE+1", Unmapped_Key, 0x03, 0xA0);
  addSharpKey("SHUTTLE+2", Unmapped_Key, 0x03, 0xA2);
  addSharpKey("SHUTTLE+3", Unmapped_Key, 0x03, 0xA4);
  addSharpKey("SHUTTLE+4", Unmapped_Key, 0x03, 0xA6);
  addSharpKey("SHUTTLE+5", Unmapped_Key, 0x03, 0xA8);
  addSharpKey("SHUTTLE-1", Unmapped_Key, 0x03, 0xA9);
  addSharpKey("SHUTTLE+6", Unmapped_Key, 0x03, 0xAA);
  addSharpKey("SHUTTLE-2", Unmapped_Key, 0x03, 0xAB);
  addSharpKey("SHUTTLE0", Unmapped_Key, 0x03, 0xAE);
  addSharpKey("SV/V+/Timer", Timer_Key, 0x03, 0xC0);
}


SharpReceiver1::SharpReceiver1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Receiver Keyset 1",
      Sharp_Make,
      index)
{
}


void SharpReceiver1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new SharpProtocol(guiObject, index, true);

  addSharpKey("PRESET+", ChannelUp_Key, 0x12, 0x11);
  addSharpKey("PRESET-", ChannelDown_Key, 0x12, 0x12);
  addSharpKey("VOL+", VolumeUp_Key, 0x12, 0x14);
  addSharpKey("VOL-", VolumeDown_Key, 0x12, 0x15);
  addSharpKey("POWER", Power_Key, 0x12, 0x16);
  addSharpKey("TUNER", TunerInput_Key, 0x12, 0x19);
  addSharpKey("TAPE", TapeInput_Key, 0x12, 0x1A);
  addSharpKey("CD", CDInput_Key, 0x12, 0x1B);
  addSharpKey("PHONO", PhonoInput_Key, 0x12, 0x1D);
  addSharpKey("X-BASS", EnhancedBass_Key, 0x12, 0x2E);
  addSharpKey("FM", Unmapped_Key, 0x12, 0x32);
  addSharpKey("LW", Unmapped_Key, 0x12, 0x33);
  addSharpKey("MW", Unmapped_Key, 0x12, 0x34);
  addSharpKey("SW", Unmapped_Key, 0x12, 0xCA);

  addSharpKey("1", One_Key, 0x14, 0x01);
  addSharpKey("2", Two_Key, 0x14, 0x02);
  addSharpKey("3", Three_Key, 0x14, 0x03);
  addSharpKey("4", Four_Key, 0x14, 0x04);
  addSharpKey("5", Five_Key, 0x14, 0x05);
  addSharpKey("6", Six_Key, 0x14, 0x06);
  addSharpKey("7", Seven_Key, 0x14, 0x07);
  addSharpKey("8", Eight_Key, 0x14, 0x08);
  addSharpKey("9", Nine_Key, 0x14, 0x09);
  addSharpKey("0", Zero_Key, 0x14, 0x0A);
  addSharpKey("CALL", Call_Key, 0x14, 0x11);
  addSharpKey("CLEAR", Clear_Key, 0x14, 0x12);
  addSharpKey("MEMORY", Program_Key, 0x14, 0x13);
  addSharpKey("CUE", FastForward_Key, 0x14, 0x19);
  addSharpKey("REVIEW", Rewind_Key, 0x14, 0x1A);
  addSharpKey("TIME_DISPLAY", Info_Key, 0x14, 0x1B);
  addSharpKey("RANDOM", Random_Key, 0x14, 0x1E);
  addSharpKey("APSS+", Unmapped_Key, 0x14, 0x21);
  addSharpKey("PLAY", Play_Key, 0x14, 0x22);
  addSharpKey("APSS-", Unmapped_Key, 0x14, 0x23);
  addSharpKey("PAUSE", Pause_Key, 0x14, 0x25);
  addSharpKey("STOP", Stop_Key, 0x14, 0x27);
  addSharpKey("REPEAT", Repeat_Key, 0x14, 0x36);
  addSharpKey("+10", DoubleDigit_Key, 0x14, 0x38);
}


SharpAC1::SharpAC1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Air Conditioner 1",
      Sharp_Make,
      index)
{
}


void SharpAC1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0xF508, 16);

  addKey("Fan Faster", FanFaster_Key, 0x01, 8);
  addKey("Energy Save", EnergySave_Key, 0x02, 8);
  addKey("Fan Slower", FanSlower_Key, 0x04, 8);
  addKey("Timer", Timer_Key, 0x06, 8);
  addKey("Fan", Fan_Key, 0x07, 8);
  addKey("Cool", Cool_Key, 0x09, 8);
  addKey("Temp/Timer-", TempDown_Key, 0x0D, 8);
  addKey("Temp/Timer+", TempUp_Key, 0x0E, 8);
  addKey("Auto/Cool", Mode_Key, 0x0F, 8);
  addKey("power", Power_Key, 0x11, 8);
}
