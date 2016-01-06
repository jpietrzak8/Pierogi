//
// philips.cpp
//
// Copyright 2012 - 2015 by John Pietrzak (jpietrzak8@gmail.com)
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

#include "philips.h"
#include "protocols/rc5protocol.h"
#include "protocols/rc6protocol.h"
#include "protocols/necprotocol.h"
#include <QComboBox>


PhilipsTV1::PhilipsTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Philips_Make,
      TV_Panels | MediaControl_Panels | MediaRecord_Panels,
      index)
{
  addControlledDevice(Philips_Make, "HV92", TV_Device);
  addControlledDevice(Philips_Make, "15PF4121", TV_Device);
}


void PhilipsTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  addKey("UP", Up_Key, 0x0010, 13);
  addKey("DOWN", Down_Key, 0x0011, 13);
  addKey("MENU", Menu_Key, 0x0012, 13);
  addKey("exit", Exit_Key, 0x0013, 13);
  addKey("LEFT", Left_Key, 0x0015, 13);
  addKey("RIGHT", Right_Key, 0x0016, 13);
//  addKey("TELETEXT", Teletext_Key, 0x0017, 13);
  addKey("PICTURE_SETTINGS", PictureMode_Key, 0x002B, 13);
  addKey("SOUND_SETTINGS", SoundMode_Key, 0x002C, 13);
  addKey("GAME", Unmapped_Key, 0x002E, 13);
  addKey("fav", Favorites_Key, 0x0039, 13);
  addKey("SCREEN_WIDTH", AspectRatio_Key, 0x003E, 13); // "format"
  addKey("RED", Red_Key, 0x00C8, 13);
  addKey("YELLOW", Yellow_Key, 0x00F1, 13); // "radio"
  addKey(".", Unmapped_Key, 0x00F8, 13);
  addKey("Cinema", Unmapped_Key, 0x00F9, 13);
  addKey("GREEN", Green_Key, 0x00FB, 13);

  addKey("0", Zero_Key, 0x1000, 13);
  addKey("1", One_Key, 0x1001, 13);
  addKey("2", Two_Key, 0x1002, 13);
  addKey("3", Three_Key, 0x1003, 13);
  addKey("4", Four_Key, 0x1004, 13);
  addKey("5", Five_Key, 0x1005, 13);
  addKey("6", Six_Key, 0x1006, 13);
  addKey("7", Seven_Key, 0x1007, 13);
  addKey("8", Eight_Key, 0x1008, 13);
  addKey("9", Nine_Key, 0x1009, 13);
  addKey("1-", DoubleDigit_Key, 0x100A, 13); // -/--
  addKey("100", PlusOneHundred_Key, 0x100A, 13);
  addKey("TV-Dash", Dash_Key, 0x100A, 13);
  addKey("CP", Unmapped_Key, 0x100B, 13); // "C/P"
  addKey("ON/OFF", Power_Key, 0x100C, 13);
  addKey("MUTE", Mute_Key, 0x100D, 13);
  addKey("pp", PrevChannel_Key, 0x100E, 13); // "GREEN"
  addKey("INFO", Info_Key, 0x100F, 13); // "+", "OSD"

  addKey("VOL+", VolumeUp_Key, 0x1010, 13);
  addKey("VOL-", VolumeDown_Key, 0x1011, 13);
  addKey("BRIGHTNESS_UP", BrightnessUp_Key, 0x1012, 13);
  addKey("BRIGHTNESS_DOWN", BrightnessDown_Key, 0x1013, 13);
  addKey("CONTRAST_UP", ContrastUp_Key, 0x1014, 13);
  addKey("CONTRAST_DOWN", ContrastDown_Key, 0x1015, 13);
  addKey("BASS_UP", BassUp_Key, 0x1016, 13);
  addKey("BASS_DOWN", BassDown_Key, 0x1017, 13);
  addKey("TREBLE_UP", TrebleUp_Key, 0x1018, 13);
  addKey("TREBLE_DOWN", TrebleDown_Key, 0x1019, 13);
  addKey("BALANCE_RIGHT", BalanceRight_Key, 0x101A, 13);
  addKey("BALANCE_LEFT", BalanceLeft_Key, 0x101B, 13);
  addKey("TT_OUT", Unmapped_Key, 0x101D, 13);
  addKey("TT_PLAY", TeletextReveal_Key, 0x101E, 13);

  addKey("P+", ChannelUp_Key, 0x1020, 13);
  addKey("P-", ChannelDown_Key, 0x1021, 13);
  addKey("SURF", Unmapped_Key, 0x1022, 13);
  addKey("I/II", Audio_Key, 0x1023, 13); // "TEXT_REVEAL", "Stereo"
  addKey("EXPAND", Surround_Key, 0x1024, 13); // "STEREO", "spatial"
  addKey("TIMER", Sleep_Key, 0x1026, 13); // "POWER-OFF", "sleep"
  addKey("PLAY", Play_Key, 0x1028, 13);
//  addKey("CENTER", Unmapped_Key, 0x1029, 13); // "TEXT_STOP_SEQUENCE", etc.
  addKey("TT_STOP", TeletextHold_Key, 0x1029, 13);
  addKey("TEXT_CLOCK", TeletextTime_Key, 0x102A, 13); // "time", "TT_TIME"
  addKey("TEXT_ENLARGE", TeletextSize_Key, 0x102B, 13); // "Reduce_Teletext"
  addKey("TT_INFO", Unmapped_Key, 0x102C, 13); // "TELETEXT_ADDINFO"
  addKey("TT_X", TeletextOff_Key, 0x102D, 13); // "TELETEXT_OFF"
  addKey("TT_MIX", Unmapped_Key, 0x102E, 13);
  addKey("BACK", Unmapped_Key, 0x102F, 13);

  addKey("vcr_rewind", Rewind_Key, 0x1032, 13);
  addKey("REVERSE", Unmapped_Key, 0x1033, 13);
  addKey("vcr_fastforward", FastForward_Key, 0x1034, 13);
  addKey("FORWARD", Unmapped_Key, 0x1035, 13);
  addKey("STOP", Stop_Key, 0x1036, 13);
  addKey("RECORD", Record_Key, 0x1037, 13);
  addKey("AV", Input_Key, 0x1038, 13); // "EXT", "SOURCE"
  addKey("TELETEXT", Teletext_Key, 0x103C, 13);
  addKey("TEXT_TV", TeletextAndTV_Key, 0x103C, 13); // "TELETEXT"
//  addKey("TT_TV", TeletextAndTV_Key, 0x103F, 13);

  addKey("MY_AUDIO", Unmapped_Key, 0x10D2, 13);
  addKey("PAY-TV_UP", Unmapped_Key, 0x10DC, 13);
  addKey("PAY-TV_DOWN", Unmapped_Key, 0x10DD, 13);
  addKey("RADIO_UP", Unmapped_Key, 0x10DE, 13);
  addKey("RADIO_DOWN", Unmapped_Key, 0x10DF, 13);
  addKey("ambilight_power", Unmapped_Key, 0x10E3, 13);
  addKey("ambilight_mode", Unmapped_Key, 0x10E4, 13);
  addKey("BLUE", Blue_Key, 0x10F9, 13);

  // The media keys are not well described!  -- config file 5373
  addKey("FAST_BACK", Unmapped_Key, 0x116F, 13);
  addKey("PLAY_3", Unmapped_Key, 0x1168, 13);
  addKey("FAST_FORWARD", Unmapped_Key, 0x1175, 13);
  addKey("DOWN", Unmapped_Key, 0x1176, 13);
  addKey("SKIP", Unmapped_Key, 0x1177, 13);
}


PhilipsTV1a::PhilipsTV1a(
  unsigned int index)
  : PhilipsTV1(index)
{
  setKeysetName("TV Keyset 1a");

  addControlledDevice(Philips_Make, "17PT1563", TV_Device);
}


void PhilipsTV1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  PhilipsTV1::populateProtocol(guiObject);

  addKey("TIMER", Sleep_Key, 0x002D, 13);
}


PhilipsTV1b::PhilipsTV1b(
  unsigned int index)
  : PhilipsTV1(index)
{
  setKeysetName("TV Keyset 1b");

  addControlledDevice(Philips_Make, "29PT5507", TV_Device);
}


void PhilipsTV1b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  PhilipsTV1::populateProtocol(guiObject);

  addKey("radio", Unmapped_Key, 0x00F1, 13);
  addKey("sound", Unmapped_Key, 0x1014, 13);
  addKey("screen", Unmapped_Key, 0x1015, 13);
  addKey("rec", Record_Key, 0x002B, 13);
  addKey("rewind", Rewind_Key, 0x002C, 13);
  addKey("stop", Stop_Key, 0x002D, 13);
  addKey("play", Play_Key, 0x002E, 13);
}


PhilipsTV1c::PhilipsTV1c(
  unsigned int index)
  : PhilipsTV1(index)
{
  setKeysetName("TV Keyset 1c");
}


void PhilipsTV1c::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  PhilipsTV1::populateProtocol(guiObject);

  addKey("spatial", Surround_Key, 0x1024, 13);
  addKey("stereo", Audio_Key, 0x1023, 13);
  addKey("dbb", Unmapped_Key, 0x1016, 13); // dynamic bass boost?
}


PhilipsTV1d::PhilipsTV1d(
  unsigned int index)
  : PhilipsTV1(index)
{
  setKeysetName("TV Keyset 1d");

  addControlledDevice(Philips_Make, "47PFL7603D", TV_Device);
  addControlledDevice(Philips_Make, "14PT1562/00", TV_Device);
  addControlledDevice(Philips_Make, "32PW9528/12", TV_Device);
}


void PhilipsTV1d::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  PhilipsTV1::populateProtocol(guiObject);

  addKey("NOTE_BUTTON", Unmapped_Key, 0x1014, 13); // "Tune"
  addKey("RADIO_BUTTON", Unmapped_Key, 0x00F1, 13);
  addKey("RED", Red_Key, 0x002B, 13);
  addKey("GREEN", Green_Key, 0x002C, 13);
  addKey("YELLOW", Yellow_Key, 0x002D, 13);
  addKey("BLUE", Blue_Key, 0x002E, 13);
  addKey("prev", PrevChannel_Key, 0x1022, 13);
  addKey("red-", Unmapped_Key, 0x000E, 13); // "CURSOR -"
  addKey("blue+", Unmapped_Key, 0x000D, 13); // "CURSOR +"
  addKey("pip", PIP_Key, 0x0018, 13);
  addKey("pip_move", PIPMove_Key, 0x0019, 13);
  addKey("pip_source", PIPSource_Key, 0x001F, 13);
  addKey("pip_still", PIPPause_Key, 0x0025, 13);
  addKey("pip_switch", PIPSwap_Key, 0x001A, 13);
  addKey("pip_prog+", PIPChannelUp_Key, 0x0026, 13);
  addKey("pip_prog-", PIPChannelDown_Key, 0x0027, 13);
  addKey("tvtxt_index", TeletextIndex_Key, 0x002F, 13);
}


PhilipsTV1e::PhilipsTV1e(
  unsigned int index)
  : PhilipsTV1(index)
{
  setKeysetName("TV Keyset 1e");

  addControlledDevice(Philips_Make, "28PT4455", TV_Device);
  addControlledDevice(Philips_Make, "21PT2265", TV_Device);
}


void PhilipsTV1e::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  PhilipsTV1::populateProtocol(guiObject);

  addKey("smart_audio", SoundMode_Key, 0x10CB, 13);
  addKey("smart_video", PictureMode_Key, 0x10CA, 13);
  addKey("teletext/ok", Select_Key, 0x103C, 13);
  addKey("red", Red_Key, 0x002B, 13);
  addKey("green", Green_Key, 0x002C, 13);
  addKey("yellow", Yellow_Key, 0x002D, 13);
  addKey("blue", Blue_Key, 0x002E, 13);
  addKey("teletext_menu", Unmapped_Key, 0x002F, 13);
}


PhilipsTV1f::PhilipsTV1f(
  unsigned int index)
  : PhilipsTV1(index)
{
  setKeysetName("TV Keyset 1f");

  addControlledDevice(Philips_Make, "25PT5302", TV_Device);
}


void PhilipsTV1f::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  PhilipsTV1::populateProtocol(guiObject);

  addKey("SETUP", Menu_Key, 0x003A, 13);
  addKey("VOL-", VolumeDown_Key, 0x0011, 13);
  addKey("VOL+", VolumeUp_Key, 0x0010, 13);
  addKey("P<P", PrevChannel_Key, 0x1022, 13); // Might be wrong
  addKey("RED", Red_Key, 0x002B, 13);
  addKey("GREEN", Green_Key, 0x002C, 13);
  addKey("YELLOW", Yellow_Key, 0x002D, 13);
  addKey("BLUE", Blue_Key, 0x002E, 13);
  addKey("GRAY", Unmapped_Key, 0x002F, 13);
  addKey("SMARTVIDEO", PictureMode_Key, 0x10CA, 13);
  addKey("SMARTAUDIO", SoundMode_Key, 0x10CB, 13);
  addKey("+", Unmapped_Key, 0x0032, 13);
  addKey("-", Unmapped_Key, 0x0033, 13);
}


PhilipsTV2::PhilipsTV2(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 2",
      Philips_Make,
      TV_Panels | MediaControl_Panels | MediaRecord_Panels,
      index)
{
  addControlledDevice(Philips_Make, "28PW8506/12R", TV_Device);
  addControlledDevice(Philips_Make, "26PFL5604H", TV_Device);
  addControlledDevice(Philips_Make, "32PFL5403D", TV_Device);
}


void PhilipsTV2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new RC6Protocol(guiObject, index, 0x00);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

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
  addKey("Previous_channel", PrevChannel_Key, 0x0A, 8); // "PP", "AB"
  addKey("Power", Power_Key, 0x0C, 8);
  addKey("Mute", Mute_Key, 0x0D, 8);
  addKey("INFO", Info_Key, 0x0F, 8); // "i+"

  addKey("Vol+", VolumeUp_Key, 0x10, 8);
  addKey("Vol-", VolumeDown_Key, 0x11, 8);

  addKey("P+", ChannelUp_Key, 0x20, 8);
  addKey("P-", ChannelDown_Key, 0x21, 8);
  addKey(">>", FastForward_Key, 0x28, 8);
  addKey("<<", Rewind_Key, 0x2B, 8);
  addKey("Play", Play_Key, 0x2C, 8);

  addKey("Stop", Stop_Key, 0x31, 8); // "MHEG_Cancel"
  addKey("Record", Record_Key, 0x37, 8);
  addKey("SOURCE", Input_Key, 0x38, 8); // "inputselect", "external"
  addKey("TELETEXT", Teletext_Key, 0x3C, 8);

  addKey("OPTIONS", AppsMenu_Key, 0x40, 8); // Probably wrong here!
  addKey("InstallMenu", ToolsMenu_Key, 0x45, 8);
  addKey("SUBTITLE", Captions_Key, 0x4B, 8);
  addKey("1st/2nd_language", Audio_Key, 0x4E, 8); // "monostereo"

  addKey("Home", Menu_Key, 0x54, 8); // "Menu"
  addKey("up", Up_Key, 0x58, 8);
  addKey("down", Down_Key, 0x59, 8);
  addKey("left", Left_Key, 0x5A, 8);
  addKey("right", Right_Key, 0x5B, 8);
  addKey("OK", Select_Key, 0x5C, 8);
  addKey("Dual_Screen", PIP_Key, 0x5D, 8); // "splitdisplay"

  addKey("freeze", Pause_Key, 0x67, 8); // "pause"
  addKey("red", Red_Key, 0x6D, 8);
  addKey("green", Green_Key, 0x6E, 8);
  addKey("yellow", Yellow_Key, 0x6F, 8);
  addKey("blue", Blue_Key, 0x70, 8);
  addKey("SurroundSound", Surround_Key, 0x71, 8);  // "soundselect"
  addKey("Time", Sleep_Key, 0x7F, 8); // "clock", "timer_programming"

  addKey("ActiveControl", Unmapped_Key, 0x96, 8);
  addKey("TV", Unmapped_Key, 0x9F, 8);

  addKey("Guide", Guide_Key, 0xCC, 8); // "nextview", "EPG"

  addKey("zoom", Zoom_Key, 0xE7, 8);
  addKey("PICTURE", PictureMode_Key, 0xF3, 8); // "smartdisplay"
  addKey("SOUND", SoundMode_Key, 0xF4, 8); // "smartsound"
  addKey("FORMAT", AspectRatio_Key, 0xF5, 8); // "Picture_Format", "displaymode"
}


PhilipsTV2a::PhilipsTV2a(
  unsigned int index)
  : PhilipsTV2(index)
{
  setKeysetName("TV Keyset 2a");

  addControlledDevice(Philips_Make, "29PT8607/12", TV_Device);
}


void PhilipsTV2a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  PhilipsTV2::populateProtocol(guiObject);

  addKey("tv-display", Info_Key, 0x3C, 8);
  addKey("tv-teletext_submode_(J:12)", Unmapped_Key, 0x5D, 8);
  addKey("tv-recording", Record_Key, 0x6D, 8);
  addKey("tv-speed-", Unmapped_Key, 0x6E, 8);
  addKey("tv-stop", Stop_Key, 0x6F, 8);
  addKey("tv-play", Play_Key, 0x70, 8);
  addKey("tv-speed+", Unmapped_Key, 0x71, 8);
  addKey("tv-solarization", Unmapped_Key, 0xCC, 8);
}


PhilipsTV2b::PhilipsTV2b(
  unsigned int index)
  : PhilipsTV2(index)
{
  setKeysetName("TV Keyset 2b");

  addControlledDevice(Philips_Make, "32PFL7532D", TV_Device);
}


void PhilipsTV2b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  PhilipsTV2::populateProtocol(guiObject);

  addKey("KEY_PLAY", Play_Key, 0xC1, 8);
  addKey("KEY_FAVORITES", Favorites_Key, 0xD2, 8);
}


PhilipsTV3::PhilipsTV3(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV (settop-box) keyset 3",
      Philips_Make,
      TV_Panels,
      index)
{
  addControlledDevice(Philips_Make, "DTX6372", TV_Device);
}


void PhilipsTV3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new RC6Protocol(guiObject, index, 0x28);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

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

  addKey("power", Power_Key, 0x0C, 8);
  addKey("mute", Mute_Key, 0x0D, 8);
  addKey("info", Info_Key, 0x0F, 8);

  addKey("vol+", VolumeUp_Key, 0x10, 8);
  addKey("vol-", VolumeDown_Key, 0x11, 8);

  addKey("p+", ChannelUp_Key, 0x20, 8);
  addKey("p-", ChannelDown_Key, 0x21, 8);

  addKey("text", Teletext_Key, 0x3C, 8);

  addKey("tv/dtv", Input_Key, 0x43, 8);
  addKey("subtitle", Captions_Key, 0x4B, 8);
  addKey("menu", Menu_Key, 0x54, 8);
  addKey("up", Up_Key, 0x58, 8);
  addKey("down", Down_Key, 0x59, 8);
  addKey("left", Left_Key, 0x5A, 8);
  addKey("right", Right_Key, 0x5B, 8);
  addKey("select", Select_Key, 0x5C, 8);

  addKey("red", Red_Key, 0x6D, 8);
  addKey("green", Green_Key, 0x6E, 8);
  addKey("yellow", Yellow_Key, 0x6F, 8);
  addKey("blue", Blue_Key, 0x70, 8);
  addKey("exit", Exit_Key, 0x83, 8);

  addKey("guide", Guide_Key, 0xCC, 8);
  addKey("wide", AspectRatio_Key, 0xD8, 8);
}


PhilipsDVD1::PhilipsDVD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Philips_Make,
      MediaControl_Panels,
      index)
{
  addControlledDevice(Philips_Make, "DVD712", DVD_Device);
  addControlledDevice(Philips_Make, "DVD722", DVD_Device);
  addControlledDevice(Philips_Make, "DVD-724", DVD_Device);
  addControlledDevice(Philips_Make, "DVP 3005", DVD_Device);
}


void PhilipsDVD1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new RC6Protocol(guiObject, index, 0x04);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

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
  addKey("Standby", Power_Key, 0x0C, 8);
  addKey("Mute", Mute_Key, 0x0D, 8);
  addKey("Display", Info_Key, 0x0F, 8);

  addKey("dim", Unmapped_Key, 0x13, 8);
  addKey("Shuffle", Random_Key, 0x1C, 8);
  addKey("Repeat", Repeat_Key, 0x1D, 8);

  addKey("Skip_Right", Next_Key, 0x20, 8); // "next"
  addKey("Skip_Left", Previous_Key, 0x21, 8); // "prev"
  addKey("Forward", FastForward_Key, 0x28, 8);
  addKey("Rewind", Rewind_Key, 0x29, 8);
  addKey("Scan", Scan_Key, 0x2A, 8);
  addKey("Play", Play_Key, 0x2C, 8);

  addKey("Still", Pause_Key, 0x30, 8); // "pause"
  addKey("Stop", Stop_Key, 0x31, 8);
  addKey("Repeat_AB", RepeatAB_Key, 0x3B, 8);

  addKey("open-close", Eject_Key, 0x42, 8);
  addKey("Subtitle", Captions_Key, 0x4B, 8);
  addKey("Audio", Audio_Key, 0x4E, 8);

  addKey("sound-mode", SoundMode_Key, 0x50, 8);
  addKey("Menu", DiscMenu_Key, 0x54, 8);
  addKey("Up", Up_Key, 0x58, 8);
  addKey("Down", Down_Key, 0x59, 8);
  addKey("Left", Left_Key, 0x5A, 8);
  addKey("Right", Right_Key, 0x5B, 8);
  addKey("OK", Select_Key, 0x5C, 8);

  addKey("Title", DiscTitle_Key, 0x71, 8);
  addKey("System_Menu", Menu_Key, 0x82, 8); // "setup"
  addKey("Return", Exit_Key, 0x83, 8);
  addKey("Angle", Angle_Key, 0x85, 8);
  addKey("Preview", Unmapped_Key, 0xB5, 8);
  addKey("T-C", Unmapped_Key, 0xC8, 8);
  addKey("Secret", Unmapped_Key, 0xEB, 8);
  addKey("Zoom", Zoom_Key, 0xF7, 8);
  addKey("fts", Unmapped_Key, 0xFB, 8);
}


PhilipsDVD1a::PhilipsDVD1a(
  unsigned int index)
  : PhilipsDVD1(index)
{
  setKeysetName("DVD Keyset 1a");

  addControlledDevice(Philips_Make, "DVP-5982", DVD_Device);
}


void PhilipsDVD1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  PhilipsDVD1::populateProtocol(guiObject);

  addKey("Play_Pause", Pause_Key, 0x2C, 8);
  addKey("USB", Unmapped_Key, 0x7E, 8);
  addKey("Power", Power_Key, 0xC7, 8);
}


PhilipsDVD1b::PhilipsDVD1b(
  unsigned int index)
  : PhilipsDVD1(index)
{
  setKeysetName("DVD Keyset 1b");

  addControlledDevice(Philips_Make, "DVP-642", DVD_Device);
}


void PhilipsDVD1b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  PhilipsDVD1::populateProtocol(guiObject);

  addKey("Forward", FastForward_Key, 0x20, 8);
  addKey("Reverse", Rewind_Key, 0x21, 8);
  addKey("Title", DiscTitle_Key, 0x83, 8);
}


PhilipsDVD1c::PhilipsDVD1c(
  unsigned int index)
  : PhilipsDVD1(index)
{
  setKeysetName("DVD Keyset 1c");

  addControlledDevice(Philips_Make, "HTS3544", DVD_Device);
  addControlledDevice(Philips_Make, "DVP5982", DVD_Device);
  addControlledDevice(Philips_Make, "DVP5160", DVD_Device);
}


void PhilipsDVD1c::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  PhilipsDVD1::populateProtocol(guiObject);

  addKey("play-pause", Pause_Key, 0x2C, 8);
  addKey("disc-usb", Unmapped_Key, 0x3F, 8);
  addKey("USB", Unmapped_Key, 0x7E, 8);
  addKey("title", DiscTitle_Key, 0x83, 8);
  addKey("power", Power_Key, 0xC7, 8);
  addKey("menu", DiscMenu_Key, 0xD1, 8);
  addKey("program", Program_Key, 0xFB, 8);
}


PhilipsDVD1d::PhilipsDVD1d(
  unsigned int index)
  : PhilipsDVD1(index)
{
  setKeysetName("DVD Keyset 1d");

  addControlledDevice(Philips_Make, "DVD 963SA", DVD_Device);
}


void PhilipsDVD1d::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  PhilipsDVD1::populateProtocol(guiObject);

  addKey("ff-right", FastForward_Key, 0x20, 8);
  addKey("ff-left", Rewind_Key, 0x21, 8);
  addKey("display", Info_Key, 0x48, 8);
}


PhilipsDVD2::PhilipsDVD2(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD/BD Keyset 2",
      Philips_Make,
      MediaControl_Panels,
      index)
{
}


void PhilipsDVD2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new RC6Protocol(guiObject, index, 0x46);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

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
  addKey("info", Info_Key, 0x0F, 8);

  addKey("repeat", Repeat_Key, 0x1D, 8);

  addKey("next", Next_Key, 0x20, 8);
  addKey("prev", Previous_Key, 0x21, 8);
  addKey("fwd", FastForward_Key, 0x28, 8);
  addKey("bwd", Rewind_Key, 0x29, 8);
  addKey("play", Play_Key, 0x2C, 8);
  addKey("pause", Pause_Key, 0x30, 8);
  addKey("stop", Stop_Key, 0x31, 8);

  addKey("eject", Eject_Key, 0x42, 8);
  addKey("subtitle", Captions_Key, 0x4B, 8);
  addKey("audio", Audio_Key, 0x4E, 8);

  addKey("up", Up_Key, 0x58, 8);
  addKey("down", Down_Key, 0x59, 8);
  addKey("left", Left_Key, 0x5A, 8);
  addKey("right", Right_Key, 0x5B, 8);
  addKey("ok", Select_Key, 0x5C, 8);
  addKey("bonus", Unmapped_Key, 0x5D, 8);

  addKey("red", Red_Key, 0x6D, 8);
  addKey("green", Green_Key, 0x6E, 8);
  addKey("yellow", Yellow_Key, 0x6F, 8);
  addKey("blue", Blue_Key, 0x70, 8);

  addKey("back", Exit_Key, 0x83, 8);
  addKey("home", Menu_Key, 0x92, 8);
  addKey("menu", DiscMenu_Key, 0x9A, 8);
  addKey("topmenu", DiscTitle_Key, 0x9C, 8);
  addKey("hdmi", HDMIInput_Key, 0xC6, 8);
  addKey("power", Power_Key, 0xC7, 8);
  addKey("options", Unmapped_Key, 0xC9, 8);
}


PhilipsDVD3::PhilipsDVD3(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 3",
      Philips_Make,
      MediaControl_Panels,
      index)
{
  addControlledDevice(Philips_Make, "DVDR3570H", DVD_Device);
}


void PhilipsDVD3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new RC6Protocol(guiObject, index, 0x32);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

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
  addKey("Power", Power_Key, 0x0C, 8);
  addKey("Info", Info_Key, 0x0F, 8);

  addKey("Ch-", ChannelDown_Key, 0x10, 8);
  addKey("Ch+", ChannelUp_Key, 0x11, 8);
  addKey("shuffle", Random_Key, 0x1C, 8);
  addKey("repeat", Repeat_Key, 0x1D, 8);

  addKey("Next", Next_Key, 0x20, 8);
  addKey("Prev", Previous_Key, 0x21, 8);
  addKey("Ffw", FastForward_Key, 0x28, 8);
  addKey("Rew", Rewind_Key, 0x29, 8);
  addKey("Play", Play_Key, 0x2C, 8);
  addKey("Play", Pause_Key, 0x2C, 8);
  addKey("Stop", Stop_Key, 0x31, 8);
  addKey("Rec", Record_Key, 0x37, 8);

  addKey("Scart", ScartInput_Key, 0x43, 8);
  addKey("Subtitle", Captions_Key, 0x4B, 8);
  addKey("Audio", Audio_Key, 0x4E, 8);

  addKey("Menu", Menu_Key, 0x54, 8);
  addKey("Up", Up_Key, 0x58, 8);
  addKey("Down", Down_Key, 0x59, 8);
  addKey("Left", Left_Key, 0x5A, 8);
  addKey("Right", Right_Key, 0x5B, 8);
  addKey("OK", Select_Key, 0x5C, 8);
  addKey("inputnext", Input_Key, 0x5E, 8);

  addKey("Last_ch", PrevChannel_Key, 0x6A, 8);
  addKey("Red", Red_Key, 0x6D, 8);
  addKey("Green", Green_Key, 0x6E, 8);
  addKey("Yellow", Yellow_Key, 0x6F, 8);
  addKey("Blue", Blue_Key, 0x70, 8);
  addKey("USB", Unmapped_Key, 0x7E, 8);

  addKey("Options", Unmapped_Key, 0x82, 8);
  addKey("Back", Exit_Key, 0x83, 8); // "Exit"
  addKey("angle", Angle_Key, 0x85, 8);
  addKey("inoputtuner", TunerInput_Key, 0x8A, 8);

//  addKey("HDDList", Unmapped_Key, 0x90, 8);
//  addKey("Home", Unmapped_Key, 0x92, 8);
  addKey("InputDVD", DVDInput_Key, 0x90, 8);
  addKey("InputHDD", HDDInput_Key, 0x92, 8);

  addKey("TVGuide", Guide_Key, 0xC2, 8);
//  addKey("Cam", Unmapped_Key, 0xC3, 8);
  addKey("inputusb", USBInput_Key, 0xC3, 8);
  addKey("t/c", Unmapped_Key, 0xC8, 8); // title/chapter
  addKey("Select", Unmapped_Key, 0xC9, 8); // "menuselect"

  addKey("Disc", DiscMenu_Key, 0xD1, 8);
  addKey("zoom", Zoom_Key, 0xD3, 8);
  addKey("LiveTV", LiveTV_Key, 0xEE, 8);
  addKey("Edit", Unmapped_Key, 0xF1, 8);
  addKey("timer", Timer_Key, 0xFE, 8);
}


void PhilipsDVD3::populateInputList(
  QComboBox *cb) const
{
  cb->clear();

  cb->addItem("Input Toggle", QVariant(Input_Key));
  cb->addItem("SCART", QVariant(ScartInput_Key));
  cb->addItem("Tuner", QVariant(TunerInput_Key));
  cb->addItem("DVD", QVariant(DVDInput_Key));
  cb->addItem("HDD", QVariant(HDDInput_Key));
  cb->addItem("USB", QVariant(USBInput_Key));
}


PhilipsDVD3a::PhilipsDVD3a(
  unsigned int index)
  : PhilipsDVD3(index)
{
  setKeysetName("DVD Keyset 3a");

  addControlledDevice(Philips_Make, "DVDR-3455H", DVD_Device);
}


void PhilipsDVD3a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  PhilipsDVD3::populateProtocol(guiObject);

  addKey("CH+", ChannelUp_Key, 0x1E, 8);
  addKey("CH-", ChannelDown_Key, 0x1F, 8);
  addKey("Audio", Audio_Key, 0xD2, 8);
  addKey("Record", Record_Key, 0xF3, 8);
}


PhilipsDVD4::PhilipsDVD4(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 4",
      Philips_Make,
      MediaControl_Panels,
      index)
{
  addControlledDevice(Philips_Make, "DVDR 1000", DVD_Device);
}


void PhilipsDVD4::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new RC6Protocol(guiObject, index, 0x30);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

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

  addKey("Power", Power_Key, 0x0C, 8);
  addKey("SYSTEM", Info_Key, 0x0F, 8);

  addKey("DIM", Unmapped_Key, 0x13, 8);
  addKey("REPEAT", Repeat_Key, 0x1D, 8);
  addKey("PROGPLUS", ChannelUp_Key, 0x1E, 8);
  addKey("PROGMINUS", ChannelDown_Key, 0x1F, 8);

  addKey("NEXT", Next_Key, 0x20, 8);
  addKey("PREVIOUS", Previous_Key, 0x21, 8);
  addKey("SLOW", Slow_Key, 0x22, 8);
  addKey("FORWARD", FastForward_Key, 0x28, 8);
  addKey("REWIND", Rewind_Key, 0x29, 8);
  addKey("SCAN", Scan_Key, 0x2A, 8);
  addKey("PLAY", Play_Key, 0x2C, 8);
  addKey("PAUSE", Pause_Key, 0x30, 8);
  addKey("STOP", Stop_Key, 0x31, 8);
  addKey("RECORD", Record_Key, 0x37, 8);
  addKey("REPEATAB", RepeatAB_Key, 0x3B, 8);

  addKey("CLEAR", Clear_Key, 0x41, 8);
  addKey("TVDVD", Input_Key, 0x43, 8);
  addKey("SUBTITLE", Captions_Key, 0x4B, 8);
  addKey("AUDIO", Audio_Key, 0x4E, 8);

  addKey("DISC", Unmapped_Key, 0x54, 8);
  addKey("UP", Up_Key, 0x58, 8);
  addKey("DOWN", Down_Key, 0x59, 8);
  addKey("LEFT", Left_Key, 0x5A, 8);
  addKey("RIGHT", Right_Key, 0x5B, 8);

  addKey("ANGLE", Angle_Key, 0x85, 8);

  addKey("TC", Unmapped_Key, 0xC8, 8);
  addKey("EDIT", Unmapped_Key, 0xCF, 8);

  addKey("TUNER", TunerInput_Key, 0xEE, 8);

  addKey("ZOOM", Zoom_Key, 0xF7, 8);
  addKey("SELECT", Select_Key, 0xFA, 8);
  addKey("TIMER", Timer_Key, 0xFE, 8);
}


void PhilipsDVD4::populateInputList(
  QComboBox *cb) const
{
  cb->clear();

  cb->addItem("TV / DVD", QVariant(Input_Key));
  cb->addItem("Tuner", QVariant(TunerInput_Key));
}


PhilipsVCR1::PhilipsVCR1(
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      Philips_Make,
      MediaControl_Panels | MediaRecord_Panels,
      index)
{
}


void PhilipsVCR1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  addKey("Standby", Power_Key, 0x114C, 13);
  addKey("External", Input_Key, 0x1178, 13);
  addKey("Forward", FastForward_Key, 0x1174, 13);
  addKey("Record", Record_Key, 0x1177, 13);
  addKey("Rewind", Rewind_Key, 0x1172, 13);
  addKey("Stop", Stop_Key, 0x1176, 13);
  addKey("Play", Play_Key, 0x1175, 13);
  addKey("Timer", Timer_Key, 0x115D, 13);
  addKey("OSD", Info_Key, 0x114F, 13);
  addKey("Menu", Menu_Key, 0x0152, 13);
  addKey("OK", Select_Key, 0x0157, 13);
  addKey("Left", Left_Key, 0x0155, 13);
  addKey("Right", Right_Key, 0x0156, 13);
  addKey("Up", Up_Key, 0x0150, 13);
  addKey("Down", Down_Key, 0x0151, 13);
  addKey("Program+", ChannelUp_Key, 0x1160, 13);
  addKey("Program-", ChannelDown_Key, 0x1161, 13);
  addKey("Audio", Audio_Key, 0x1163, 13);
  addKey("Still", Pause_Key, 0x1169, 13); // "PAUSE"
  addKey("1", One_Key, 0x1141, 13);
  addKey("2", Two_Key, 0x1142, 13);
  addKey("3", Three_Key, 0x1143, 13);
  addKey("4", Four_Key, 0x1144, 13);
  addKey("5", Five_Key, 0x1145, 13);
  addKey("6", Six_Key, 0x1146, 13);
  addKey("7", Seven_Key, 0x1147, 13);
  addKey("8", Eight_Key, 0x1148, 13);
  addKey("9", Nine_Key, 0x1149, 13);
  addKey("0", Zero_Key, 0x1140, 13);
  addKey("-/--", DoubleDigit_Key, 0x114A, 13);
  addKey("100", PlusOneHundred_Key, 0x114A, 13);
  addKey("VCR-Dash", Dash_Key, 0x114A, 13);
  addKey("Index", IndexSearch_Key, 0x0170, 13);
  addKey("reset", Reset_Key, 0x1171, 13); // "clear"
  addKey("play<", Unmapped_Key, 0x116F, 13);
  addKey("x>", PlayX2_Key, 0x116A, 13); // "X2_PLAY"
  addKey("speed", VHSSpeed_Key, 0x117A, 13); // "SP/LP"
  addKey("Childlock", Unmapped_Key, 0x017F, 13);
  addKey("System", Unmapped_Key, 0x094A, 13);
  addKey("vol_dn", VolumeDown_Key, 0x1011, 13);
  addKey("vol_up", VolumeUp_Key, 0x1010, 13);
  addKey("F_ADV", StepForward_Key, 0x016B, 13);
  addKey("G_CODE", Unmapped_Key, 0x0145, 13);
  addKey("GO_TO", Unmapped_Key, 0x1173, 13);
  addKey("SLOW", Slow_Key, 0x1168, 13);
  addKey("memory", Program_Key, 0x117B, 13);
  addKey("VCR_TV", Unmapped_Key, 0x117E, 13);
  addKey("track_up", TrackingPlus_Key, 0x014D, 13);
  addKey("track_down", TrackingMinus_Key, 0x14E, 13);
}


PhilipsVCR1a::PhilipsVCR1a(
  unsigned int index)
  : PhilipsVCR1(index)
{
  setKeysetName("VCR Keyset 1a");

  addControlledDevice(Philips_Make, "VP27/55", VCR_Device);
}


void PhilipsVCR1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  PhilipsVCR1::populateProtocol(guiObject);

  addKey("menu", Menu_Key, 0x115D, 13);
  addKey("eject", Eject_Key, 0x116D, 13);
  addKey("sleep_wake", Sleep_Key, 0x1026, 13);
  addKey("alt_ch", PrevChannel_Key, 0x1022, 13);
  addKey("chan_prev", ChannelDown_Key, 0x1020, 13);
  addKey("chan_next", ChannelUp_Key, 0x1021, 13);
  addKey("mute", Mute_Key, 0x100D, 13);
  addKey("TV-POWER", Unmapped_Key, 0x100C, 13);
}


PhilipsVCR1b::PhilipsVCR1b(
  unsigned int index)
  : PhilipsVCR1(index)
{
  setKeysetName("VCR Keyset 1b");
}


void PhilipsVCR1b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  PhilipsVCR1::populateProtocol(guiObject);

  addKey("Cassette_Eject", Eject_Key, 0x017E, 13);
  addKey("Select", Select_Key, 0x114B, 13);
  addKey("Rewind", Rewind_Key, 0x1165, 13);
  addKey("Forward", FastForward_Key, 0x1166, 13);
  addKey("Previous", Previous_Key, 0x0171, 13);
  addKey("Next", Next_Key, 0x0170, 13);
  addKey("Monitor", Unmapped_Key, 0x017A, 13);
  addKey("Tuner", TunerInput_Key, 0x017D, 13);
  addKey("Tracking", AutoTracking_Key, 0x114E, 13);
}


PhilipsVCR1c::PhilipsVCR1c(
  unsigned int index)
  : PhilipsVCR1(index)
{
  setKeysetName("VCR Keyset 1c");
}


void PhilipsVCR1c::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  PhilipsVCR1::populateProtocol(guiObject);

  addKey("TIMER_REVIEW", Unmapped_Key, 0x0168, 13);
  addKey("DATE_UP", Unmapped_Key, 0x125C, 13);
  addKey("DATE_DOWN", Unmapped_Key, 0x125D, 13);
  addKey("PROG_UP", Unmapped_Key, 0x1260, 13);
  addKey("PROG_DOWN", Unmapped_Key, 0x1261, 13);
  addKey("START_UP", Unmapped_Key, 0x125E, 13);
  addKey("START_DOWN", Unmapped_Key, 0x125F, 13);
  addKey("END_UP", Unmapped_Key, 0x1263, 13);
  addKey("END_DOWN", Unmapped_Key, 0x1264, 13);
  addKey("Tracking", AutoTracking_Key, 0x114E, 13);
  addKey("FF", FastForward_Key, 0x1166, 13);
  addKey("Previous", Previous_Key, 0x0171, 13);
  addKey("Next", Next_Key, 0x0170, 13);
  addKey("SET_CLOCK", Unmapped_Key, 0x1164, 13);
  addKey("VPS", RecordPDC_Key, 0x114B, 13);
  addKey("Cassette", Eject_Key, 0x017E, 13);
  addKey("DECODER", Unmapped_Key, 0x0169, 13);
  addKey("Tuner", TunerInput_Key, 0x017D, 13);
  addKey("Monitor", Unmapped_Key, 0x017A, 13);
  addKey("SYSTEM", Unmapped_Key, 0x014A, 13);
  addKey("REC_MODE", Unmapped_Key, 0x115E, 13);
  addKey("SHOWVIEW", Unmapped_Key, 0x0145, 13); // vhsplus+, etc.
  addKey("DW", Unmapped_Key, 0x0144, 13); // "D/W"
  addKey("SPEED-", SlowMinus_Key, 0x1165, 13);
  addKey("SPEED+", SlowPlus_Key, 0x1166, 13);
}


PhilipsSat1::PhilipsSat1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Sat Keyset 1",
      Philips_Make,
      TV_Panels | MediaControl_Panels | MediaRecord_Panels,
      index)
{
}


void PhilipsSat1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  addKey("Standby", Power_Key, 0x120C, 13);
  addKey("External", Unmapped_Key, 0x1238, 13);
  addKey("Menu", Menu_Key, 0x0212, 13); // "blue_on"
  addKey("blue_off", Exit_Key, 0x0213, 13);
  addKey("OK", Select_Key, 0x0217, 13); // "blue_ok"
  addKey("Left", Left_Key, 0x0215, 13);
  addKey("Right", Right_Key, 0x0216, 13);
  addKey("Up", Up_Key, 0x0210, 13);
  addKey("Down", Down_Key, 0x0211, 13);
  addKey("Program+", ChannelUp_Key, 0x1220, 13);
  addKey("Program-", ChannelDown_Key, 0x1221, 13);
  addKey("Audio", Audio_Key, 0x1223, 13); // I-II
  addKey("1", One_Key, 0x1201, 13);
  addKey("2", Two_Key, 0x1202, 13);
  addKey("3", Three_Key, 0x1203, 13);
  addKey("4", Four_Key, 0x1204, 13);
  addKey("5", Five_Key, 0x1205, 13);
  addKey("6", Six_Key, 0x1206, 13);
  addKey("7", Seven_Key, 0x1207, 13);
  addKey("8", Eight_Key, 0x1208, 13);
  addKey("9", Nine_Key, 0x1209, 13);
  addKey("0", Zero_Key, 0x1200, 13);
  addKey("OSD", Info_Key, 0x120F, 13);
  addKey("Program<", PrevChannel_Key, 0x1222, 13); // "P<P"
  addKey("A/B", Unmapped_Key, 0x122C, 13);
  addKey("Music_notes", Unmapped_Key, 0x0205, 13);
  addKey("TV_ON", Unmapped_Key, 0x1001, 13);
  addKey("TV_OFF", Unmapped_Key, 0x100C, 13);
  addKey("Vol_+", VolumeUp_Key, 0x1010, 13);
  addKey("Vol_-", VolumeDown_Key, 0x1011, 13);
  addKey("Mute", Mute_Key, 0x0206, 13);
  addKey("Screensize", AspectRatio_Key, 0x003E, 13);
  addKey("TV/SAT", Input_Key, 0x1228, 13);
  addKey("Play", Play_Key, 0x1175, 13);
  addKey("Stop", Stop_Key, 0x1176, 13);
  addKey("ffw", FastForward_Key, 0x1174, 13);
  addKey("fbw", Rewind_Key, 0x1172, 13);
  addKey("TV_MUTE", Unmapped_Key, 0x100D, 13);
  addKey("TV_P-", Unmapped_Key, 0x1021, 13);
  addKey("TV_P+", Unmapped_Key, 0x1020, 13);
  addKey("Install", Unmapped_Key, 0x023A, 13);
  addKey("Clock", Clock_Key, 0x122A, 13);
  addKey("Clock_dotted", Unmapped_Key, 0x1226, 13);
}


PhilipsSat2::PhilipsSat2(
  unsigned int index)
  : PIRKeysetMetaData(
      "Sat Keyset 2",
      Philips_Make,
      TV_Panels,
      index)
{
  addControlledDevice(Philips_Make, "DSX-5500", Sat_Device);
}


void PhilipsSat2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new RC6Protocol(guiObject, index, 0x27);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

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
  addKey("power", Power_Key, 0x0C, 8);
  addKey("ch+", ChannelUp_Key, 0x20, 8);
  addKey("ch-", ChannelDown_Key, 0x21, 8);
  addKey("source", Unmapped_Key, 0x43, 8); // ?
  addKey("menu", Menu_Key, 0x54, 8);
  addKey("exit", Exit_Key, 0x55, 8);
  addKey("up", Up_Key, 0x58, 8);
  addKey("down", Down_Key, 0x59, 8);
  addKey("left", Left_Key, 0x5A, 8);
  addKey("right", Right_Key, 0x5B, 8);
  addKey("OK", Select_Key, 0x5C, 8);
  addKey("red", Red_Key, 0x6D, 8);
  addKey("green", Green_Key, 0x6E, 8);
  addKey("yellow", Yellow_Key, 0x6F, 8);
  addKey("blue", Blue_Key, 0x70, 8);
  addKey("white", Unmapped_Key, 0x71, 8);
  addKey("back", PrevChannel_Key, 0x83, 8); // Might be wrong
  addKey("pause", Pause_Key, 0x84, 8);
  addKey("brackets", Unmapped_Key, 0xAF, 8);
  addKey("info", Info_Key, 0xCB, 8);
  addKey("guide", Guide_Key, 0xCC, 8);
  addKey("surf", Unmapped_Key, 0xCD, 8);
  addKey("i", Unmapped_Key, 0xFD, 8);
}


PhilipsSat2a::PhilipsSat2a(
  unsigned int index)
  : PhilipsSat2(index)
{
  setKeysetName("Sat Keyset 2a");

  addControlledDevice(Philips_Make, "DSX 6010/62A", Sat_Device);
}


void PhilipsSat2a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  PhilipsSat2::populateProtocol(guiObject);

  addKey("ch+", ChannelUp_Key, 0x58, 8);
  addKey("ch-", ChannelDown_Key, 0x59, 8);
  addKey("language", Audio_Key, 0x49, 8);
  addKey("txt", Captions_Key, 0x4B, 8);
  addKey("favorites", Favorites_Key, 0x84, 8);
  addKey("themes", Unmapped_Key, 0xCD, 8);
  addKey("opts", Unmapped_Key, 0xBD, 8);
  addKey("pp", PrevChannel_Key, 0x0A, 8);
  addKey("page+", PageUp_Key, 0xCE, 8);
  addKey("page-", PageDown_Key, 0xCF, 8);
}


PhilipsSat3::PhilipsSat3(
  unsigned int index)
  : PIRKeysetMetaData(
      "Sat Keyset 3",
      Philips_Make,
      TV_Panels,
      index)
{
  addControlledDevice(Philips_Make, "DST5816/33", Sat_Device);
}


void PhilipsSat3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  addKey("SOUNDOFF", Mute_Key, 0x0286, 13); // "mute"
  addKey("EPG", Guide_Key, 0x028F, 13); // "prog"
  addKey("UP", Up_Key, 0x0290, 13);
  addKey("DOWN", Down_Key, 0x0291, 13);
  addKey("SERV", Unmapped_Key, 0x0292, 13);
  addKey("BACK", Unmapped_Key, 0x0293, 13); // "av"
  addKey("LEFT", Left_Key, 0x0295, 13);
  addKey("RIGHT", Right_Key, 0x0296, 13);
  addKey("OK", Select_Key, 0x0297, 13);
  addKey("FRONT", Unmapped_Key, 0x02A1, 13); // "twoje"
  addKey("MENU", Menu_Key, 0x02AA, 13); // "perso"
  addKey("A", Unmapped_Key, 0x02AB, 13);
  addKey("B", Unmapped_Key, 0x02AC, 13);
  addKey("C", Unmapped_Key, 0x02AD, 13);
  addKey("D", Unmapped_Key, 0x02AE, 13);
  addKey("E", Unmapped_Key, 0x02AF, 13);

  addKey("0", Zero_Key, 0x1280, 13);
  addKey("1", One_Key, 0x1281, 13);
  addKey("2", Two_Key, 0x1282, 13);
  addKey("3", Three_Key, 0x1283, 13);
  addKey("4", Four_Key, 0x1284, 13);
  addKey("5", Five_Key, 0x1285, 13);
  addKey("6", Six_Key, 0x1286, 13);
  addKey("7", Seven_Key, 0x1287, 13);
  addKey("8", Eight_Key, 0x1288, 13);
  addKey("9", Nine_Key, 0x1289, 13);
  addKey("STANDBY", Power_Key, 0x128C, 13);
  addKey("INFO", Info_Key, 0x128F, 13); // "pilot"
  addKey("TV/SAT", Input_Key, 0x12A8, 13);
  addKey("+", Unmapped_Key, 0x12AF, 13);
}


PhilipsAudio1::PhilipsAudio1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 1",
      Philips_Make,
      Receiver_Panels | MediaRecord_Panels,
      index)
{
  addControlledDevice(Philips_Make, "FW 530C", Audio_Device);
  addControlledDevice(Philips_Make, "FW-P78", Audio_Device);
  addControlledDevice(Philips_Make, "FWP73P", Audio_Device);
  addControlledDevice(Philips_Make, "FWP78C", Audio_Device);
  addControlledDevice(Philips_Make, "PVD0384", Audio_Device);
  addControlledDevice(Philips_Make, "AZ2407", Audio_Device);
  addControlledDevice(Philips_Make, "MZ7", Audio_Device);
  addControlledDevice(Philips_Make, "AS680C", Audio_Device);
}


void PhilipsAudio1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  addKey("incredible_surround", Surround_Key, 0x0400, 13); // "inc_s"
  addKey("Rear+", RearVolumeUp_Key, 0x0401, 13);
  addKey("Rear-", RearVolumeDown_Key, 0x0402, 13);
  addKey("Dynamic Bass Boost", EnhancedBass_Key, 0x0406, 13); // "dbb"
  addKey("Digital Sound Control", Unmapped_Key, 0x040F, 13); // "dsc"

  addKey("TestTone", Unmapped_Key, 0x0418, 13);
  addKey("Center+", CenterVolumeUp_Key, 0x0426, 13);
  addKey("Center-", CenterVolumeDown_Key, 0x0427, 13);
  addKey("vec", Unmapped_Key, 0x042B, 13);
  addKey("osm", Unmapped_Key, 0x042C, 13);

  addKey("tuner_program", Program_Key, 0x047A, 13); // Create Preset

  addKey("mute", Mute_Key, 0x140D, 13);
  addKey("Vol+", VolumeUp_Key, 0x1410, 13);
  addKey("Vol-", VolumeDown_Key, 0x1411, 13);
  addKey("BASS_UP", BassUp_Key, 0x1416, 13);
  addKey("BASS_DOWN", BassDown_Key, 0x1417, 13);
  addKey("TREBLE_UP", TrebleUp_Key, 0x1418, 13);
  addKey("TREBLE_DOWN", TrebleDown_Key, 0x1419, 13);
  addKey("BALANCE_RIGHT", BalanceRight_Key, 0x141A, 13); // "BalR"
  addKey("BALANCE_LEFT", BalanceLeft_Key, 0x141B, 13); // "BalL"
  addKey("DPL", Unmapped_Key, 0x1425, 13);
  addKey("SleepTimer", Sleep_Key, 0x1426, 13);
  addKey("TIMER", Timer_Key, 0x142A, 13);
  addKey("FLAT", Unmapped_Key, 0x1434, 13);
  addKey("LOUDNESS", Unmapped_Key, 0x1432, 13);

  addKey("tuner_power", Power_Key, 0x144C, 13);
  addKey("tuner_power", ToggleBand_Key, 0x144C, 13);
  addKey("TUNER_DISPLAY", Info_Key, 0x144F, 13);
  addKey("tuner_ff", ChannelUp_Key, 0x145E, 13); // "tuningR"
  addKey("tuner_rew", ChannelDown_Key, 0x145F, 13); // "tuningL"
  addKey("tuner_next", Next_Key, 0x1460, 13); // "presetUp"
  addKey("tuner_previous", Previous_Key, 0x1461, 13); // "presetDown"
  addKey("tuner", TunerInput_Key, 0x147F, 13);

  addKey("tape_power", Unmapped_Key, 0x148C, 13);
  addKey("tape_next", Unmapped_Key, 0x14A0, 13);
  addKey("tape_previous", Unmapped_Key, 0x14A1, 13);
  addKey("Side", Unmapped_Key, 0x14AF, 13);  // "TAPE_SIDE"
  addKey("tape_pause", Unmapped_Key, 0x14B0, 13);
  addKey("tape_rew", Unmapped_Key, 0x14B2, 13);
  addKey("tape_ff", Unmapped_Key, 0x14B3, 13);
  addKey("tape_play", Unmapped_Key, 0x14B5, 13);
  addKey("tape_stop", Unmapped_Key, 0x14B6, 13);
  addKey("tape", TapeInput_Key, 0x14BF, 13); // "tape1-2"

  addKey("TIME", Unmapped_Key, 0x150B, 13); // "CD_DISPLAY"
  addKey("cd_power", Unmapped_Key, 0x150C, 13);
  addKey("cd_shuffle", Random_Key, 0x151C, 13);
  addKey("cd_repeat", Repeat_Key, 0x151D, 13);
  addKey("cd_next", Unmapped_Key, 0x1520, 13);
  addKey("cd_previous", Unmapped_Key, 0x1521, 13);
  addKey("cd_program", Unmapped_Key, 0x1524, 13);
  addKey("SCAN", Scan_Key, 0x152B, 13);
  addKey("OPEN/CLOSE", Eject_Key, 0x152D, 13);
  addKey("cd_pause", Pause_Key, 0x1530, 13);
  addKey("cd_rew", Rewind_Key, 0x1532, 13);
  addKey("cd_ff", FastForward_Key, 0x1534, 13);
  addKey("cd_play", Play_Key, 0x1535, 13);
  addKey("cd_stop", Stop_Key, 0x1536, 13);
  addKey("cd_1", One_Key, 0x1537, 13);
  addKey("cd_2", Two_Key, 0x1538, 13);
  addKey("cd_3", Three_Key, 0x1539, 13);
  addKey("cd", CDInput_Key, 0x153F, 13);

  addKey("aux_power", Unmapped_Key, 0x154C, 13); // "power", "standby"
  addKey("aux", AuxInput_Key, 0x157F, 13);

  addKey("CDR", MDInput_Key, 0x16BF, 13); // hack
  addKey("CDR_POWER", Unmapped_Key, 0x100C, 13);
  addKey("CDR_REPEAT", Unmapped_Key, 0x169D, 13);
  addKey("CDR_SHUFFLE", Unmapped_Key, 0x169C, 13);
  addKey("CDR_PROGRAM", Unmapped_Key, 0x16A4, 13);
  addKey("CDR_DISPLAY", Unmapped_Key, 0x168B, 13);
  addKey("CDR_PAUSE", Unmapped_Key, 0x16B0, 13);
  addKey("CDR_PLAY", Unmapped_Key, 0x16B5, 13);
  addKey("CDR_NEXT", Unmapped_Key, 0x16A0, 13);
  addKey("CDR_PREV", Unmapped_Key, 0x16A1, 13);
  addKey("CDR_STOP", Unmapped_Key, 0x16B6, 13);
  addKey("CDR_FWD", Unmapped_Key, 0x16B4, 13);
  addKey("CDR_BWD", Unmapped_Key, 0x16B2, 13);
}


void PhilipsAudio1::populateInputList(
  QComboBox *cb) const
{
  cb->clear();

  cb->addItem("Tuner", QVariant(TunerInput_Key));
  cb->addItem("CD", QVariant(CDInput_Key));
  cb->addItem("Tape", QVariant(TapeInput_Key));
  cb->addItem("Aux", QVariant(AuxInput_Key));
  cb->addItem("CDR", QVariant(MDInput_Key));
}


PhilipsAudio1a::PhilipsAudio1a(
  unsigned int index)
  : PhilipsAudio1(index)
{
  setKeysetName("Audio Keyset 1a");

  addControlledDevice(Philips_Make, "C 380", Audio_Device);
}


void PhilipsAudio1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  PhilipsAudio1::populateProtocol(guiObject);

  addKey("VOL-", VolumeDown_Key, 0x1511, 13);
  addKey("VOL+", VolumeUp_Key, 0x1510, 13);
}


PhilipsAudio1b::PhilipsAudio1b(
  unsigned int index)
  : PhilipsAudio1(index)
{
  setKeysetName("Audio Keyset 1b");

  addControlledDevice(Philips_Make, "FW 362", Audio_Device);
}


void PhilipsAudio1b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  PhilipsAudio1::populateProtocol(guiObject);

  addKey("tv_power", Unmapped_Key, 0x100C, 13);
  addKey("tv_vcr", VCRInput_Key, 0x103F, 13);
  addKey("tape1", SVideoInput_Key, 0x14AC, 13); // hack
  addKey("tape2", SVideo2Input_Key, 0x14AE, 13); // hack
  addKey("play", Play_Key, 0x1175, 13);
  addKey("pause", Pause_Key, 0x1170, 13);
  addKey("stop", Stop_Key, 0x1176, 13);
  addKey("skip_forw", Next_Key, 0x1020, 13);
  addKey("skip_back", Previous_Key, 0x1021, 13);
  addKey("forw", FastForward_Key, 0x1010, 13);
  addKey("back", Rewind_Key, 0x1011, 13);
  addKey("disc_up", NextDisc_Key, 0x151E, 13);
}


void PhilipsAudio1b::populateInputList(
  QComboBox *cb) const
{
  PhilipsAudio1::populateInputList(cb);

  cb->addItem("TV / VCR)", QVariant(VCRInput_Key));
  cb->addItem("Tape 1", QVariant(SVideoInput_Key));
  cb->addItem("Tape 2", QVariant(SVideo2Input_Key));
}


PhilipsAudio2::PhilipsAudio2(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 2",
      Philips_Make,
      Receiver_Panels | MediaRecord_Panels,
      index)
{
  addControlledDevice(Philips_Make, "FW2104", Audio_Device);
}


void PhilipsAudio2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, false);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

//  setPreData(0x61CA, 16);
  setPreData(0x5386, 16);

  addKey("POWER", Power_Key, 0x01, 8);
  addKey("TAPE", TapeInput_Key, 0x02, 8);
  addKey("CD", CDInput_Key, 0x03, 8);
  addKey("TUNER", TunerInput_Key, 0x04, 8);
  addKey("MUTE", Mute_Key, 0x06, 8);
  addKey("VOL_UP", VolumeUp_Key, 0x07, 8);
  addKey("VOL_DOWN", VolumeDown_Key, 0x08, 8);
  addKey("TUN_UP", ChannelUp_Key, 0x09, 8);
  addKey("TUN_DOWN", ChannelDown_Key, 0x0A, 8);
  addKey("SNOOZE", Unmapped_Key, 0x0B, 8);
  addKey("SLEEP", Sleep_Key, 0x0C, 8);
  addKey("TIMER", Timer_Key, 0x0D, 8);
  addKey("AUX", AuxInput_Key, 0x05, 8);
  addKey("REP_A_B", RepeatAB_Key, 0x13, 8);
  addKey("MEMORY", Program_Key, 0x14, 8);
  addKey("CANCEL", Clear_Key, 0x15, 8);
  addKey("0", Zero_Key, 0x16, 8);
  addKey("1", One_Key, 0x17, 8);
  addKey("2", Two_Key, 0x18, 8);
  addKey("3", Three_Key, 0x19, 8);
  addKey("4", Four_Key, 0x1A, 8);
  addKey("5", Five_Key, 0x1B, 8);
  addKey("6", Six_Key, 0x1C, 8);
  addKey("7", Seven_Key, 0x1D, 8);
  addKey("8", Eight_Key, 0x1E, 8);
  addKey("9", Nine_Key, 0x1F, 8);
  addKey("EJECT", Eject_Key, 0x40, 8);
  addKey("CD_PLAY", Play_Key, 0x41, 8);
  addKey("CD_STOP", Stop_Key, 0x42, 8);
  addKey("CD_FW", FastForward_Key, 0x43, 8);
  addKey("CD_REW", Rewind_Key, 0x44, 8);
  addKey("TIME", Unmapped_Key, 0x45, 8);
  addKey("REP_ALL_PRG", Repeat_Key, 0x46, 8);
  addKey("INTRO", Unmapped_Key, 0x47, 8);
  addKey("EDIT", Unmapped_Key, 0x48, 8);
  addKey("WARP", Unmapped_Key, 0x49, 8);
  addKey("SPACE", Unmapped_Key, 0x4A, 8);
  addKey("CHAIN", Unmapped_Key, 0x4B, 8);
  addKey("TAPE1_REW", Unmapped_Key, 0x5B, 8);
  addKey("TAPE1_BACKPLAY", Unmapped_Key, 0x59, 8);
  addKey("TAPE1_STOP", Unmapped_Key, 0x5C, 8);
  addKey("TAPE1_PLAY", Unmapped_Key, 0x58, 8);
  addKey("TAPE1_FW", Unmapped_Key, 0x5A, 8);
  addKey("TAPE2_REW", Unmapped_Key, 0x54, 8);
  addKey("TAPE2_BACKPLAY", Unmapped_Key, 0x52, 8);
  addKey("TAPE2_STOP", Unmapped_Key, 0x55, 8);
  addKey("TAPE2_PLAY", Unmapped_Key, 0x51, 8);
  addKey("TAPE2_FW", Unmapped_Key, 0x50, 8);
//  addKey("PAUSE_RECORD", RecordPause_Key, 0x50, 8);
}


void PhilipsAudio2::populateInputList(
  QComboBox *cb) const
{
  cb->clear();

  cb->addItem("Tape", QVariant(TapeInput_Key));
  cb->addItem("CD", QVariant(CDInput_Key));
  cb->addItem("Tuner", QVariant(TunerInput_Key));
  cb->addItem("Aux", QVariant(AuxInput_Key));
}


// This CD control is different enough from Audio1 that I figured I should
// give it an entirely new keyset:
PhilipsAudio3::PhilipsAudio3(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 3",
      Philips_Make,
      MediaControl_Panels,
      index)
{
  addControlledDevice(Philips_Make, "CD723", Audio_Device);
}


void PhilipsAudio3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  addKey("fade", Unmapped_Key, 0x0538, 13);
  addKey("0", Zero_Key, 0x1500, 13);
  addKey("1", One_Key, 0x1501, 13);
  addKey("2", Two_Key, 0x1502, 13);
  addKey("3", Three_Key, 0x1503, 13);
  addKey("4", Four_Key, 0x1504, 13);
  addKey("5", Five_Key, 0x1505, 13);
  addKey("6", Six_Key, 0x1506, 13);
  addKey("7", Seven_Key, 0x1507, 13);
  addKey("8", Eight_Key, 0x1508, 13);
  addKey("9", Nine_Key, 0x1509, 13);
  addKey("time", Unmapped_Key, 0x150B, 13);
  addKey("standby", Power_Key, 0x150C, 13);
  addKey("volume+", VolumeUp_Key, 0x1510, 13);
  addKey("volume-", VolumeDown_Key, 0x1511, 13);
  addKey("shuffle", Random_Key, 0x151C, 13);
  addKey("repeat", Repeat_Key, 0x151D, 13);
  addKey("next", Next_Key, 0x1520, 13);
  addKey("previous", Previous_Key, 0x1521, 13);
  addKey("program", Program_Key, 0x1524, 13);
  addKey("highlight", Unmapped_Key, 0x152B, 13); // "SCAN", "INDEX"
  addKey("pause", Pause_Key, 0x1530, 13);
  addKey("rewind", Rewind_Key, 0x1532, 13);
  addKey("wind", FastForward_Key, 0x1534, 13);
  addKey("play", Play_Key, 0x1535, 13);
  addKey("stop", Stop_Key, 0x1536, 13);
  addKey("OPEN/CLOSE", Eject_Key, 0x152D, 13);
  addKey("DISC", Unmapped_Key, 0x151E, 13);
}


PhilipsAudio4::PhilipsAudio4(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 4",
      Philips_Make,
      MediaControl_Panels,
      index)
{
}


void PhilipsAudio4::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  addKey("EJECT", Eject_Key, 0x16AD, 13);
  addKey("INPUT", Input_Key, 0x16B8, 13);
  addKey("DISPLAY", Info_Key, 0x168B, 13);
  addKey("REPEAT", Repeat_Key, 0x169D, 13);
  addKey("1", One_Key, 0x1681, 13);
  addKey("2", Two_Key, 0x1682, 13);
  addKey("3", Three_Key, 0x1683, 13);
  addKey("4", Four_Key, 0x1684, 13);
  addKey("5", Five_Key, 0x1685, 13);
  addKey("6", Six_Key, 0x1686, 13);
  addKey("7", Seven_Key, 0x1687, 13);
  addKey("8", Eight_Key, 0x1688, 13);
  addKey("9", Nine_Key, 0x1689, 13);
  addKey("0", Zero_Key, 0x1680, 13);
  addKey("PAUSE", Pause_Key, 0x16B0, 13);
  addKey("STOP", Stop_Key, 0x16B6, 13);
  addKey("PREV", Previous_Key, 0x16A1, 13);
  addKey("PLAY", Play_Key, 0x16B5, 13);
  addKey("NEXT", Next_Key, 0x16A0, 13);
  addKey("REW", Rewind_Key, 0x16B2, 13);
  addKey("FAST", Unmapped_Key, 0x16AF, 13);
  addKey("FORW", FastForward_Key, 0x16B4, 13);
  addKey("TRACK_INCR", Unmapped_Key, 0x06B2, 13);
  addKey("PROGRAM", Program_Key, 0x16A4, 13);
  addKey("FINE_TUNE", Unmapped_Key, 0x06B4, 13);
  addKey("CD_SYNC", Unmapped_Key, 0x16A8, 13);
  addKey("REC", Record_Key, 0x16B7, 13);
}


PhilipsAudio5::PhilipsAudio5(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 5",
      Philips_Make,
      MediaControl_Panels,
      index)
{
}


void PhilipsAudio5::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  addKey("surround", Surround_Key, 0x0000, 13); // Dubious
  addKey("mute", Mute_Key, 0x000D, 13);
  addKey("vol up", VolumeUp_Key, 0x0010, 13);
  addKey("vol down", VolumeDown_Key, 0x0011, 13);
  addKey("select", Select_Key, 0x0017, 13);
  addKey("sleep", Sleep_Key, 0x0026, 13);

  addKey("power", Power_Key, 0x044C, 13);
  addKey("display", Info_Key, 0x044F, 13);
  addKey("up arrow", Up_Key, 0x045E, 13);
  addKey("fast fwd", FastForward_Key, 0x045E, 13);
  addKey("down arrow", Down_Key, 0x045F, 13);
  addKey("rewind", Rewind_Key, 0x045F, 13);
  addKey("channel up", ChannelUp_Key, 0x0460, 13);
  addKey("left arrow", Left_Key, 0x0460, 13);
  addKey("channel down", ChannelDown_Key, 0x0461, 13);
  addKey("right arrow", Right_Key, 0x0461, 13);
  addKey("menu", Menu_Key, 0x0469, 13);
}
