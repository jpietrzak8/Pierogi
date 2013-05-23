//
// toshiba.cpp
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

#include "toshiba.h"
#include "protocols/necprotocol.h"

ToshibaTV1::ToshibaTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Toshiba_Make,
      index)
{
  addControlledDevice(Toshiba_Make, "21S03D", TV_Device);
}


void ToshibaTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

//  setPreData(0x02FD, 16);
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
  addKey("100", PlusOneHundred_Key, 0x0A, 8);
  addKey("-/--", DoubleDigit_Key, 0x0B, 8);
  addKey("reset", Reset_Key, 0x0C, 8);
  addKey("tv/video", Unmapped_Key, 0x0F, 8); // "input"
  addKey("MUTE", Mute_Key, 0x10, 8);
  addKey("picturepref", PictureMode_Key, 0x11, 8); // "Contrast", "PP"
  addKey("POWER", Power_Key, 0x12, 8);
  addKey("mts", Audio_Key, 0x13, 8); // "audio_stereo_2channel"
  addKey("SCART", Input_Key, 0x14, 8); // "AV", "inputs", "source"
  addKey("sleep", Sleep_Key, 0x15, 8);
  addKey("CALL", Call_Key, 0x16, 8);
  addKey("ent", Enter_Key, 0x17, 8);  // "ch_rtn"
  addKey("fav+", Unmapped_Key, 0x19, 8);
  addKey("V+", VolumeUp_Key, 0x1A, 8);
  addKey("V+", Right_Key, 0x1A, 8);
  addKey("P+", ChannelUp_Key, 0x1B, 8);
  addKey("P+", Up_Key, 0x1B, 8);
  addKey("recall", PrevChannel_Key, 0x1C, 8);
  addKey("fav-", Unmapped_Key, 0x1D, 8);
  addKey("V-", VolumeDown_Key, 0x1E, 8);
  addKey("V-", Left_Key, 0x1E, 8);
  addKey("P-", ChannelDown_Key, 0x1F, 8);
  addKey("P-", Down_Key, 0x1F, 8);
  addKey("OK", Select_Key, 0x21, 8);
  addKey("POP_DIR", Unmapped_Key, 0x26, 8);
  addKey("a/d", Unmapped_Key, 0x44, 8);
  addKey("RED", Red_Key, 0x48, 8);
  addKey("GREEN", Green_Key, 0x49, 8);
  addKey("YELLOW", Yellow_Key, 0x4A, 8);
  addKey("pip_ch_up", PIPChannelUp_Key, 0x4A, 8); // Yellow
  addKey("BLUE", Blue_Key, 0x4B, 8);
  addKey("pip_ch_down", PIPChannelDown_Key, 0x4B, 8); // Blue
  addKey("still", PIPPause_Key, 0x4C, 8);
  addKey("locate", PIPMove_Key, 0x4E, 8);
  addKey("source", PIPSource_Key, 0x4F, 8);
  addKey("pip", PIP_Key, 0x51, 8);
  addKey("swap", PIPSwap_Key, 0x53, 8); // Reduce
  addKey("PIC_SIZE", AspectRatio_Key, 0x54, 8); // "16:9"
  addKey("Tone", Unmapped_Key, 0x55, 8);
  addKey("cap/text", Captions_Key, 0x57, 8); // Image
  addKey("exit", Exit_Key, 0x58, 8);
  addKey("SIZE", AspectRatio_Key, 0x59, 8); // "WIDE"
  addKey("DOULBY", NoiseReduction_Key, 0x5A, 8);
  addKey("MENU", Menu_Key, 0x5B, 8);
  addKey("1/2", Unmapped_Key, 0x63, 8); // "cap1/cap2"
  addKey("CLOCK", Timer_Key, 0x71, 8);  // "TIMER"
  addKey("TV", Unmapped_Key, 0x72, 8);
  addKey("SEARCH", Unmapped_Key, 0x8F, 8);
  addKey("favorite", Favorites_Key, 0x90, 8);
  addKey("multi", Unmapped_Key, 0x91, 8);
  addKey("info", Info_Key, 0x93, 8);
}


ToshibaTV1a::ToshibaTV1a(
  unsigned int index)
  : ToshibaTV1(index)
{
  setKeysetName("TV Keyset 1a");

  addControlledDevice(Toshiba_Make, "27A51", TV_Device);
}


void ToshibaTV1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  ToshibaTV1::populateProtocol(guiObject);

  addKey("menu/enter", Menu_Key, 0x80, 8);
  addKey("menu/enter", Select_Key, 0x80, 8);
}


ToshibaTV1b::ToshibaTV1b(
  unsigned int index)
  : ToshibaTV1(index)
{
  setKeysetName("TV Keyset 1b");
}


void ToshibaTV1b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  ToshibaTV1::populateProtocol(guiObject);

  addKey("right", Right_Key, 0x19, 8); // "fav+"
  addKey("left", Left_Key, 0x1D, 8); // "fav-"
  addKey("menu/enter", Menu_Key, 0x80, 8);
  addKey("menu/enter", Select_Key, 0x80, 8);
  addKey("up", Up_Key, 0x82, 8); // "set+"
  addKey("down", Down_Key, 0x83, 8); // "set-"
}


ToshibaTV1c::ToshibaTV1c(
  unsigned int index)
  : ToshibaTV1f(index)
{
  setKeysetName("TV Keyset 1c");
}


void ToshibaTV1c::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  ToshibaTV1f::populateProtocol(guiObject);

  addKey("textzoom", TeletextSize_Key, 0x0D, 8); // "Enlarge"
  addKey("texttime", TeletextTime_Key, 0x15, 8);
  addKey("TXT/MIX", Teletext_Key, 0x17, 8); // "teletext"
  addKey("textindex", TeletextIndex_Key, 0x2B, 8);
  addKey("textpages", Unmapped_Key, 0x2C, 8);
  addKey("texthold", TeletextHold_Key, 0x53, 8);
  addKey("textanswer", TeletextReveal_Key, 0x54, 8);
  addKey("pipswap", PIPSwap_Key, 0x58, 8);
}


ToshibaTV1d::ToshibaTV1d(
  unsigned int index)
  : ToshibaTV1f(index)
{
  setKeysetName("TV Keyset 1d");
}


void ToshibaTV1d::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  ToshibaTV1f::populateProtocol(guiObject);

  addKey("subtitle", Captions_Key, 0x0C, 8);
  addKey("page+", PageDown_Key, 0x0D,8);
  addKey("24+", Unmapped_Key, 0x15, 8);
  addKey("Up", Up_Key, 0x19, 8);
  addKey("Down", Down_Key, 0x1D, 8);
  addKey("Right", Right_Key, 0x40, 8);
  addKey("Left", Left_Key, 0x42, 8);
  addKey("guide", Guide_Key, 0x45, 8);
  addKey("tv/fav/radio", Favorites_Key, 0x47, 8); // might be wrong
  addKey("page-", PageUp_Key, 0x53, 8);
  addKey("24-", Unmapped_Key, 0x54, 8);
}


ToshibaTV1e::ToshibaTV1e(
  unsigned int index)
  : ToshibaTV1(index)
{
  setKeysetName("TV Keyset 1e");
}


void ToshibaTV1e::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  ToshibaTV1::populateProtocol(guiObject);

  addKey("SKIPPREV", Previous_Key, 0x11, 8);
  addKey("FFWD", FastForward_Key, 0x2A, 8);
  addKey("STOP", Stop_Key, 0x40, 8);
  addKey("frev", Rewind_Key, 0x4B, 8);
  addKey("PLAY", Play_Key, 0x51, 8);
  addKey("SKIPNEXT", Next_Key, 0x53, 8);
}


ToshibaTV1f::ToshibaTV1f(
  unsigned int index)
  : ToshibaTV1(index)
{
  setKeysetName("TV Keyset 1f");

  addControlledDevice(Toshiba_Make, "Regza AV50*", TV_Device);
}


void ToshibaTV1f::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  ToshibaTV1::populateProtocol(guiObject);

  addKey("info", Info_Key, 0x16, 8);
  addKey("stillpicture", Pause_Key, 0x22, 8);
  addKey("exit", Exit_Key, 0x43, 8);
  addKey("back", PrevChannel_Key, 0x52, 8); // "Double_Arrow", "swap"
}


ToshibaTV1g::ToshibaTV1g(
  unsigned int index)
  : ToshibaTV1(index)
{
  setKeysetName("TV Keyset 1g");
}


void ToshibaTV1g::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  ToshibaTV1::populateProtocol(guiObject);

  addKey("menu", Menu_Key, 0x80, 8);
  addKey("set+", Right_Key, 0x82, 8);
  addKey("set-", Left_Key, 0x83, 8);
  addKey("enter", Select_Key, 0x89, 8);
}


ToshibaTV1h::ToshibaTV1h(
  unsigned int index)
  : ToshibaTV1b(index)
{
  setKeysetName("TV Keyset 1h");
}


void ToshibaTV1h::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  ToshibaTV1b::populateProtocol(guiObject);

  addKey("last (prev ch)", PrevChannel_Key, 0x17, 8);
  addKey("program guide", Guide_Key, 0x1C, 8);
  addKey("pip on/off", PIP_Key, 0x54, 8);
}


ToshibaTV1i::ToshibaTV1i(
  unsigned int index)
  : ToshibaTV1h(index)
{
  setKeysetName("TV Keyset 1i");

  addControlledDevice(Toshiba_Make, "MW-27H62", TV_Device);
}


void ToshibaTV1i::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  ToshibaTV1h::populateProtocol(guiObject);

  addKey("Menu", Menu_Key, 0x0E, 8);
  addKey("DvdMenu", DiscMenu_Key, 0x19, 8);
  addKey("ChapterNext", Next_Key, 0x57, 8);
}


ToshibaVCR1::ToshibaVCR1(
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      Toshiba_Make,
      index)
{
}


void ToshibaVCR1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x44, 8);

  addKey("1", One_Key, 0x01, 8);
  addKey("2", Two_Key, 0x02, 8);
  addKey("3", Three_Key, 0x03, 8);
  addKey("4", Four_Key, 0x04, 8);
  addKey("5", Five_Key, 0x05, 8);
  addKey("6", Six_Key, 0x06, 8);
  addKey("7", Seven_Key, 0x07, 8);
  addKey("8", Eight_Key, 0x08, 8);
  addKey("9", Nine_Key, 0x09, 0);
  addKey("0", Zero_Key, 0x0A, 8);
  addKey("100", PlusOneHundred_Key, 0x0B, 8);
  addKey("slow/dir_fwd", StepForward_Key, 0x0D, 8);
  addKey("pause", Pause_Key, 0x10, 8);
  addKey("tv/vcr", Input_Key, 0x11, 8);
  addKey("power", Power_Key, 0x12, 8);
  addKey("ff", FastForward_Key, 0x13, 8);
  addKey("stop", Stop_Key, 0x14, 8);
  addKey("play", Play_Key, 0x15, 8);
  addKey("record", Record_Key, 0x18, 8);
  addKey("rew", Rewind_Key, 0x19, 8);
  addKey("ch+", ChannelUp_Key, 0x1B, 8);
  addKey("ch-", ChannelDown_Key, 0x1F, 8);
  addKey("InputDVD", DVDInput_Key, 0x20, 8);
  addKey("DirectionRight", Right_Key, 0x4D, 8);
  addKey("Select/Ok", Select_Key, 0x4E, 8);
  addKey("DirectionLeft", Left_Key, 0x51, 8);
  addKey("Audio", Audio_Key, 0x53, 8);
  addKey("Program", Program_Key, 0x5C, 8);
  addKey("SP/SLP", VHSSpeed_Key, 0x5D, 8);
  addKey("input", Input_Key, 0x5F, 8);
  addKey("DirectionUp", Up_Key, 0x80, 8);
  addKey("DirectionDown", Down_Key, 0x81, 8);
  addKey("recall", PrevChannel_Key, 0x83, 8);
  addKey("Subtitle", Captions_Key, 0x87, 8);
  addKey("Angle", Angle_Key, 0x96, 8);
  addKey("Greater100", PlusOneHundred_Key, 0x9B, 8);
  addKey("skip", Next_Key, 0x9E, 8);
  addKey("previous", Previous_Key, 0x9F, 8);
  addKey("TopMenu", DiscTitle_Key, 0xDF, 8);
  addKey("Cancel", Clear_Key, 0xEF, 8);
  addKey("eject", Eject_Key, 0xF5, 8);
}


ToshibaVCR1a::ToshibaVCR1a(
  unsigned int index)
  : ToshibaVCR1(index)
{
  setKeysetName("VCR Keyset 1a");
}


void ToshibaVCR1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  ToshibaVCR1::populateProtocol(guiObject);

  addKey("ch+", ChannelUp_Key, 0x1E, 8);
//  addKey("ch-", ChannelDown_Key, 0x1F, 8); // Already in parent
}


ToshibaDisc1::ToshibaDisc1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Disc Keyset 1",
      Toshiba_Make,
      index)
{
}


void ToshibaDisc1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

//  setPreData(0xA25D, 16);
  setPreData(0x45, 8);

  addKey("pause", Pause_Key, 0x00, 8);
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
  addKey("slow/dir-fwd", StepForward_Key, 0x0D, 8);
  addKey("slow/dir-rev", StepBack_Key, 0x0E, 8);
  addKey("power", Power_Key, 0x12, 8);
  addKey("ff", FastForward_Key, 0x13, 8);
  addKey("stop", Stop_Key, 0x14, 8);
  addKey("play", Play_Key, 0x15, 8);
  addKey("display", Info_Key, 0x16, 8);
  addKey("rew", Rewind_Key, 0x19, 8);
  addKey("menu/enter", Menu_Key, 0x21, 8); // "ok", "enter"
  addKey("menu/enter", Select_Key, 0x21, 8); // "ok", "enter"
  addKey("exit", Exit_Key, 0x22, 8);
  addKey("skip-", Previous_Key, 0x23, 8);
  addKey("skip+", Next_Key, 0x24, 8);
  addKey("+10", DoubleDigit_Key, 0x25, 8);
  addKey("100", PlusOneHundred_Key, 0x25, 8);
  addKey("T", Unmapped_Key, 0x26, 8); // "Index", direct access to title by number
  addKey("SUBTITLE", Captions_Key, 0x28, 8);
  addKey("KEY_ANGLE", Angle_Key, 0x29, 8);
  addKey("MEMORY", Program_Key, 0x2A, 8);
  addKey("REPEAT", Repeat_Key, 0x2B, 8);
  addKey("A-B_RPT", RepeatAB_Key, 0x2C, 8);
  addKey("RANDOM", Random_Key, 0x2E, 8);
  addKey("FL_DIMMER", Unmapped_Key, 0x41, 8); // "FlDim"
  addKey("3D", Unmapped_Key, 0x43, 8);
  addKey("disc", NextDisc_Key, 0x4A, 8); // "DISC SELECT"
  addKey("vol+", VolumeUp_Key, 0x4D, 8);
  addKey("right", Right_Key, 0x4D, 8); // "vol+"
  addKey("vol-", VolumeDown_Key, 0x51, 8);
  addKey("left", Left_Key, 0x51, 8); // "vol-"
  addKey("ch+", ChannelUp_Key, 0x80, 8);
  addKey("up", Up_Key, 0x80, 8); // "ch+"
  addKey("ch-", ChannelDown_Key, 0x81, 8);
  addKey("down", Down_Key, 0x81, 8); // "ch-"
  addKey("menu", DiscMenu_Key, 0x84, 8);
  addKey("FlSelect", Unmapped_Key, 0xD7, 8);
  addKey("top_menu", DiscTitle_Key, 0xDE, 8); // "title"
  addKey("clear", Clear_Key, 0xEF, 8);
  addKey("eject", Eject_Key, 0xF5, 8);
}


ToshibaDisc1a::ToshibaDisc1a(
  unsigned int index)
  : ToshibaDisc1(index)
{
  setKeysetName("Disc Keyset 1a");
}


void ToshibaDisc1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  ToshibaDisc1::populateProtocol(guiObject);

  addKey("setup", Menu_Key, 0x20, 8);
  addKey("audio", Audio_Key, 0x27, 8);
  addKey("action", Unmapped_Key, 0x84, 8);
}



ToshibaDisc1b::ToshibaDisc1b(
  unsigned int index)
  : ToshibaDisc1(index)
{
  setKeysetName("Disc Keyset 1b");
}


void ToshibaDisc1b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  ToshibaDisc1::populateProtocol(guiObject);

  addKey("enter", Select_Key, 0x84, 8);
  addKey("mark", Unmapped_Key, 0x21, 8);
}


ToshibaDisc1c::ToshibaDisc1c(
  unsigned int index)
  : ToshibaDisc1a(index)
{
  setKeysetName("Disc Keyset 1c");
}


void ToshibaDisc1c::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  ToshibaDisc1a::populateProtocol(guiObject);

  addKey("KEY_DVD", Unmapped_Key, 0x22, 8);
  addKey("KEY_SLOW", Slow_Key, 0x26, 8);
  addKey("KEY_FAVORITES", Favorites_Key, 0xDE, 8);
  addKey("KEY_EJECTCD", Eject_Key, 0xDF, 8);
}


ToshibaDisc1d::ToshibaDisc1d(
  unsigned int index)
  : ToshibaDisc1a(index)
{
  setKeysetName("Disc Keyset 1d");
}


void ToshibaDisc1d::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  ToshibaDisc1a::populateProtocol(guiObject);

  addKey("recall", PrevChannel_Key, 0x16, 8);
}
