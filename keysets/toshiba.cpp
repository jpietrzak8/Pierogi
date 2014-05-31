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
// along with Pierogi; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//

#include "toshiba.h"
#include "protocols/necprotocol.h"
#include <QComboBox>


ToshibaTV1::ToshibaTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Toshiba_Make,
      TV_Panels | MediaControl_Panels,
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
      MediaControl_Panels | MediaRecord_Panels,
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
  addKey("Timer", Timer_Key, 0x4F, 8);
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


void ToshibaVCR1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("Input", QVariant(Input_Key));
  cb->addItem("TV / VCR", QVariant(Input_Key));
  cb->addItem("DVD", QVariant(DVDInput_Key));
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
    // Keyset already populated.
    return;
  }

  ToshibaVCR1::populateProtocol(guiObject);

  addKey("Track Up", TrackingPlus_Key, 0x1B, 8);
  addKey("Track Down", TrackingMinus_Key, 0x1F, 8);
  addKey("display/info", Info_Key, 0x83, 8);
}


ToshibaVCR1b::ToshibaVCR1b(
  unsigned int index)
  : ToshibaVCR1(index)
{
  setKeysetName("VCR Keyset 1b");
}


void ToshibaVCR1b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  ToshibaVCR1::populateProtocol(guiObject);

  // This shoudl probably be an entirely different keyset...
  addKey("display", Info_Key, 0x0B, 8);
  addKey("pip move", PIPMove_Key, 0x0D, 8);
  addKey("right arrow", Right_Key, 0x13, 8);
  addKey("down arrow", Down_Key, 0x14, 8);
  addKey("up arrow", Up_Key, 0x15, 8);
  addKey("left arrow", Left_Key, 0x19, 8);
  addKey("pip on/off", PIP_Key, 0x4F, 8);
  addKey("surround", Surround_Key, 0x53, 8);
  addKey("menu", Menu_Key, 0x8C, 8);
  addKey("last (prev ch)", PrevChannel_Key, 0x8D, 8);
  addKey("select", Select_Key, 0x8F, 8);
  addKey("mute", Mute_Key, 0x9E, 8);
  addKey("exit", Exit_Key, 0xEF, 8);
  addKey("pip swap", PIPSwap_Key, 0xF5, 8);
}


ToshibaDisc1::ToshibaDisc1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Disc Keyset 1",
      Toshiba_Make,
      MediaControl_Panels,
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
  addKey("Quick", Unmapped_Key, 0x0B, 8);
  addKey("slow/dir-fwd", StepForward_Key, 0x0D, 8);
  addKey("slow/dir-rev", StepBack_Key, 0x0E, 8);
  addKey("power", Power_Key, 0x12, 8);
  addKey("ff", FastForward_Key, 0x13, 8);
  addKey("stop", Stop_Key, 0x14, 8);
  addKey("play", Play_Key, 0x15, 8);
  addKey("display", Info_Key, 0x16, 8); // "NAVI"
  addKey("rew", Rewind_Key, 0x19, 8);
  addKey("setup", Menu_Key, 0x20, 8);
  addKey("menu/enter", Select_Key, 0x21, 8); // "ok", "enter"
  addKey("exit", Exit_Key, 0x22, 8);
  addKey("skip-", Previous_Key, 0x23, 8);
  addKey("skip+", Next_Key, 0x24, 8);
  addKey("enter", Enter_Key, 0x25, 8);
  addKey("+10", DoubleDigit_Key, 0x25, 8);
  addKey("100", PlusOneHundred_Key, 0x25, 8);
  addKey("T", IndexSearch_Key, 0x26, 8); // "Index", "viss"
  addKey("audio", Audio_Key, 0x27, 8);
  addKey("SUBTITLE", Captions_Key, 0x28, 8);
  addKey("KEY_ANGLE", Angle_Key, 0x29, 8);
  addKey("MEMORY", Program_Key, 0x2A, 8);
  addKey("REPEAT", Repeat_Key, 0x2B, 8);
  addKey("A-B_RPT", RepeatAB_Key, 0x2C, 8);
  addKey("last play", Unmapped_Key, 0x2D, 8);
  addKey("RANDOM", Random_Key, 0x2E, 8);
  addKey("zoom", Zoom_Key, 0x40, 8);
  addKey("FL_DIMMER", Unmapped_Key, 0x41, 8); // "FlDim"
  addKey("3D", Unmapped_Key, 0x43, 8); // "EAM"
  addKey("disc", NextDisc_Key, 0x4A, 8); // "DISC SELECT"
  addKey("vol+", VolumeUp_Key, 0x4D, 8);
  addKey("right", Right_Key, 0x4D, 8); // "vol+"
  addKey("ColorStream", Unmapped_Key, 0x4E, 8);
  addKey("vol-", VolumeDown_Key, 0x51, 8);
  addKey("left", Left_Key, 0x51, 8); // "vol-"
  addKey("ch+", ChannelUp_Key, 0x80, 8);
  addKey("up", Up_Key, 0x80, 8); // "ch+"
  addKey("ch-", ChannelDown_Key, 0x81, 8);
  addKey("down", Down_Key, 0x81, 8); // "ch-"
  addKey("menu", DiscMenu_Key, 0x84, 8);
  addKey("dvd", DVDInput_Key, 0xCC, 8);
  addKey("vcr", VCRInput_Key, 0xCD, 8);
  addKey("FlSelect", Unmapped_Key, 0xD7, 8);
  addKey("top_menu", DiscTitle_Key, 0xDE, 8); // "title"
  addKey("EPM", Unmapped_Key, 0xEE, 8);
  addKey("clear", Clear_Key, 0xEF, 8);
  addKey("Zoom -", Unmapped_Key, 0xF0, 8);
  addKey("Zoom +", Unmapped_Key, 0xF1, 8);
  addKey("open/close 2", Unmapped_Key, 0xF3, 8);
  addKey("eject", Eject_Key, 0xF5, 8);
}


void ToshibaDisc1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("DVD", QVariant(DVDInput_Key));
  cb->addItem("VCR", QVariant(VCRInput_Key));
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

  addKey("KEY_DVD", Unmapped_Key, 0x22, 8);
  addKey("KEY_SLOW", Slow_Key, 0x26, 8);
  addKey("KEY_FAVORITES", Favorites_Key, 0xDE, 8);
  addKey("KEY_EJECTCD", Eject_Key, 0xDF, 8);
}


ToshibaDisc1b::ToshibaDisc1b(
  unsigned int index)
  : ToshibaDisc1(index)
{
  setKeysetName("DVD/VCR Keyset 1b");
}


void ToshibaDisc1b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  ToshibaDisc1::populateProtocol(guiObject);

  addKey("sp/slp", VHSSpeed_Key, 0x2C, 8);
  addKey("record tape", Record_Key, 0xE8, 8);
}


ToshibaDisc1c::ToshibaDisc1c(
  unsigned int index)
  : ToshibaDisc1a(index)
{
  setKeysetName("DVD/Tivo Keyset 1c");
}


void ToshibaDisc1c::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  ToshibaDisc1::populateProtocol(guiObject);

  addKey("instant replay", Replay_Key, 0x0B, 8);
  addKey("last (prev ch)", PrevChannel_Key, 0x22, 8);
  addKey("Page Down in now playing", PageDown_Key, 0xA8, 8);
  addKey("Page Up in now playing", PageUp_Key, 0xA9, 8);
  addKey("guide options", Unmapped_Key, 0xB2, 8);
  addKey("guide", Guide_Key, 0xB3, 8);
  addKey("dvd switch", Input_Key, 0xB4, 8);
  addKey("TiVo switch", HDDInput_Key, 0xB8, 8);
  addKey("live tv", LiveTV_Key, 0xB9, 8);
  addKey("record", Record_Key, 0xBA, 8);
  addKey("prev ch", PrevChannel_Key, 0xBB, 8);
  addKey("record tape", Unmapped_Key, 0xE8, 8);
  addKey("thumbs down", Unmapped_Key, 0xF0, 8);
  addKey("thumbs up", Unmapped_Key, 0xF1, 8);
}


ToshibaDisc2::ToshibaDisc2(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 2",
      Toshiba_Make,
      MediaControl_Panels,
      index)
{
}


void ToshibaDisc2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0xBC45, 16);

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
  addKey("+10", DoubleDigit_Key, 0x0D, 8);
  addKey("title search", Unmapped_Key, 0x0E, 8);
  addKey("Input Select", Input_Key, 0x0F, 8);
  addKey("eject", Eject_Key, 0x11, 8);
  addKey("power", Power_Key, 0x12, 8);
  addKey("play", Play_Key, 0x13, 8);
  addKey("record", Record_Key, 0x15, 8);
  addKey("stop", Stop_Key, 0x16, 8);
  addKey("pause", Pause_Key, 0x17, 8);
  addKey("dvd", DVDInput_Key, 0x18, 8);
  addKey("hdd", HDDInput_Key, 0x19, 8);
  addKey("timeslip", Unmapped_Key, 0x1A, 8);
  addKey("satellite link", Unmapped_Key, 0x1D, 8);
  addKey("channel up", ChannelUp_Key, 0x1E, 8);
  addKey("channel down", ChannelDown_Key, 0x1F, 8);
  addKey("record menu", Unmapped_Key, 0x40, 8);
  addKey("edit menu", Unmapped_Key, 0x41, 8);
  addKey("Content Menu", Unmapped_Key, 0x42, 8);
  addKey("select", Select_Key, 0x44, 8);
  addKey("quick menu", Menu_Key, 0x45, 8); // Is this right?
  addKey("easy nav / virtual remote", Unmapped_Key, 0x46, 8);
  addKey("library", Unmapped_Key, 0x47, 8);
  addKey("star key", Unmapped_Key, 0x4A, 8);
  addKey("circle key", Unmapped_Key, 0x4B, 8);
  addKey("set-up", Unmapped_Key, 0x52, 8);
  addKey("clear", Clear_Key, 0x53, 8);
  addKey("Instant Replay", Replay_Key, 0x55, 8);
  addKey("Dubbing Direct", Unmapped_Key, 0x56, 8);
  addKey("Delete", Unmapped_Key, 0x57, 8);
  addKey("display", Info_Key, 0x5A, 8);
  addKey("instant skip", Advance_Key, 0x5B, 8);
  addKey("remain", Unmapped_Key, 0x5C, 8);
  addKey("zoom", Zoom_Key, 0x5E, 8);
  addKey("TVGOS TV Guide", Unmapped_Key, 0x6A, 8);
  addKey("TVGOS Menu", Unmapped_Key, 0x6B, 8);
  addKey("TVGOS Info", Unmapped_Key, 0x6C, 8);
  addKey("skip +", Next_Key, 0x80, 8);
  addKey("skip -", Previous_Key, 0x84, 8);
  addKey("slow+", SlowPlus_Key, 0x88, 8);
  addKey("slow-", SlowMinus_Key, 0x8C, 8);
  addKey("rewind", Rewind_Key, 0x98, 8);
  addKey("fast fwd", FastForward_Key, 0x9A, 8);
  addKey("frame adjust +", StepForward_Key, 0x9D, 8);
  addKey("frame adjust -", StepBack_Key, 0x9E, 8);
  addKey("extend", Unmapped_Key, 0xA3, 8);
  addKey("record mode", Unmapped_Key, 0xA7, 8);
  addKey("vcr +", Unmapped_Key, 0xA9, 8);
  addKey("play 1.3x/0.8x", Unmapped_Key, 0xAA, 8);
  addKey("hdmi / progressive", Unmapped_Key, 0xB0, 8);
  addKey("fl select", Unmapped_Key, 0xB1, 8);
  addKey("sat moni", Unmapped_Key, 0xB2, 8);
  addKey("tv/dvr", Unmapped_Key, 0xB3, 8);
  addKey("sat cont", Unmapped_Key, 0xB7, 8);
  addKey("up arrow", Up_Key, 0xC0, 8);
  addKey("right arrow", Right_Key, 0xC4, 8);
  addKey("down arrow", Down_Key, 0xC8, 8);
  addKey("left arrow", Left_Key, 0xCC, 8);
  addKey("top menu", DiscTitle_Key, 0xD0, 8);
  addKey("Menu", DiscMenu_Key, 0xD1, 8);
  addKey("return", Exit_Key, 0xD2, 8);
  addKey("audio", Audio_Key, 0xD3, 8);
  addKey("angle", Angle_Key, 0xD4, 8);
  addKey("subtitle", Captions_Key, 0xD5, 8);
  addKey("Picture in Picture", PIP_Key, 0xD7, 8);
  addKey("dimmer", Unmapped_Key, 0xD8, 8);
  addKey("chapter divide", Unmapped_Key, 0xD9, 8);
  addKey("timebar", Unmapped_Key, 0xDA, 8);
  addKey("repeat", Repeat_Key, 0xDC, 8);
}


void ToshibaDisc2::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("Input", QVariant(Input_Key));
  cb->addItem("DVD", QVariant(DVDInput_Key));
  cb->addItem("HDD", QVariant(HDDInput_Key));
}


ToshibaProjector1::ToshibaProjector1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Projector Keyset 1",
      Toshiba_Make,
      MediaControl_Panels,
      index)
{
}


void ToshibaProjector1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x0AE7, 16);

  addKey("video", AuxInput_Key, 0x0B, 8);
  addKey("RGB", ComponentInput_Key, 0x0D, 8);
  addKey("power", Power_Key, 0x12, 8);
  addKey("enter", Select_Key, 0x13, 8);
  addKey("menu", Menu_Key, 0x1B, 8);
  addKey("call", Unmapped_Key, 0x1C, 8);
  addKey("up arrow", Up_Key, 0x40, 8);
  addKey("down arrow", Down_Key, 0x41, 8);
  addKey("channel down", ChannelDown_Key, 0x42, 8);
  addKey("channel up", ChannelUp_Key, 0x43, 8);
  addKey("resize", AspectRatio_Key, 0x44, 8);
  addKey("freeze", Pause_Key, 0x45, 8);
}


void ToshibaProjector1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("Video", QVariant(AuxInput_Key));
  cb->addItem("RGB", QVariant(ComponentInput_Key));
}


ToshibaSTB1::ToshibaSTB1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Satellite Receiver 1",
      Toshiba_Make,
      TV_Panels,
      index)
{
}


void ToshibaSTB1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x42, 8);

  addKey("num 1 / G (Galaxy/G-Star)", One_Key, 0x81, 8);
  addKey("num 2 / T (Telstar)", Two_Key, 0x82, 8);
  addKey("num 3 / F (Satcom)", Three_Key, 0x83, 8);
  addKey("num 4 / E (Anik)", Four_Key, 0x84, 8);
  addKey("num 5 / W (ASC)", Five_Key, 0x85, 8);
  addKey("num 6 / C (Satcom/Galaxy) ", Six_Key, 0x86, 8);
  addKey("num 7 / S (Spacenet/SBS)", Seven_Key, 0x87, 8);
  addKey("num 8 / M (Morelos)", Eight_Key, 0x88, 8);
  addKey("num 9 / K (Satcom)", Nine_Key, 0x89, 8);
  addKey("num 0 / O (Other)", Zero_Key, 0x8A, 8);
  addKey("audio program", Audio_Key, 0x8C, 8);
  addKey("sat/tv", Input_Key, 0x8E, 8);
  addKey("enter", Select_Key, 0x90, 8);
  addKey("cancel", Exit_Key, 0x91, 8);
  addKey("power", Power_Key, 0x92, 8);
  addKey("mute", Mute_Key, 0x93, 8);
  addKey("vol up", VolumeUp_Key, 0x96, 8);
  addKey("vol down", VolumeDown_Key, 0x97, 8);
  addKey("west / v", Red_Key, 0x98, 8); // hack
  addKey("east / ^", Green_Key, 0x99, 8); // also hack
  addKey("channel up", ChannelUp_Key, 0x9B, 8);
  addKey("channel down", ChannelDown_Key, 0x9F, 8);
  addKey("mode", Mode_Key, 0xC0, 8);
  addKey("down arrow", Down_Key, 0xC1, 8);
  addKey("up arrow", Up_Key, 0xC2, 8);
  addKey("store", Unmapped_Key, 0xC3, 8);
  addKey("right arrow", Right_Key, 0xCA, 8);
  addKey("left arrow", Left_Key, 0xCB, 8);
  addKey("view (clear screen)", Unmapped_Key, 0xCC, 8);
  addKey("help", Guide_Key, 0xCD, 8);
  addKey("setup", Menu_Key, 0xCE, 8);
  addKey("next program", Next_Key, 0xCF, 8);
  addKey("text", Unmapped_Key, 0xD0, 8);
  addKey("message (stop asterisk)", Unmapped_Key, 0xD2, 8);
  addKey("function", Unmapped_Key, 0xD4, 8);
  addKey("c band", Unmapped_Key, 0xD5, 8);
  addKey("ku band", Unmapped_Key, 0xD6, 8);
  addKey("favorite program", Favorites_Key, 0xD7, 8);
  addKey("category list", Unmapped_Key, 0xD8, 8);
  addKey("external input", AuxInput_Key, 0xD9, 8);
}


void ToshibaSTB1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("Sat / TV", QVariant(Input_Key));
  cb->addItem("External Input", QVariant(AuxInput_Key));
}
