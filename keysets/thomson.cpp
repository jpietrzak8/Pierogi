//
// thomson.cpp
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

#include "thomson.h"
#include "protocols/xmpprotocol.h"
#include "protocols/thomsonprotocol.h"
#include "protocols/necprotocol.h"
#include "protocols/rcaprotocol.h"
#include <QComboBox>


ThomsonConverter1::ThomsonConverter1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Converter Keyset 1",
      Thomson_Make,
      TV_Panels,
      index)
{
}


void ThomsonConverter1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new XMPProtocol(
    guiObject, index, 0x1, 0x0, 0x44, 0x3E, false);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  addXMPKey("KEY_1", One_Key, 0x01, 0x00);
  addXMPKey("KEY_2", Two_Key, 0x02, 0x00);
  addXMPKey("KEY_3", Three_Key, 0x03, 0x00);
  addXMPKey("KEY_4", Four_Key, 0x04, 0x00);
  addXMPKey("KEY_5", Five_Key, 0x05, 0x00);
  addXMPKey("KEY_6", Six_Key, 0x06, 0x00);
  addXMPKey("KEY_7", Seven_Key, 0x07, 0x00);
  addXMPKey("KEY_8", Eight_Key, 0x08, 0x00);
  addXMPKey("KEY_9", Nine_Key, 0x09, 0x00);
  addXMPKey("KEY_0", Zero_Key, 0x00, 0x00);
  addXMPKey("KEY_CHANNELDOWN", ChannelDown_Key, 0x0E, 0x00);
  addXMPKey("KEY_CHANNELUP", ChannelUp_Key, 0x0D, 0x00);
  addXMPKey("KEY_MUTE", Mute_Key, 0x0C, 0x00);
  addXMPKey("KEY_VOLUMEDOWN", VolumeDown_Key, 0x0B, 0x00);
  addXMPKey("KEY_VOLUMEUP", VolumeUp_Key, 0x0A, 0x00);
  addXMPKey("KEY_LANGUAGE", Audio_Key, 0x82, 0x00);
  addXMPKey("KEY_INFO", Info_Key, 0x26, 0x00);
  addXMPKey("KEY_ENTER", Enter_Key, 0x25, 0x00);
  addXMPKey("KEY_LAST", PrevChannel_Key, 0x51, 0x00);
}


ThomsonTV1::ThomsonTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV/DVR Keyset 1",
      Thomson_Make,
      TV_Panels | MediaControl_Panels | MediaRecord_Panels,
      index)
{
}


void ThomsonTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new ThomsonProtocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x3, 4);

  addKey("1", One_Key, 0x00, 7);
  addKey("4", Four_Key, 0x01, 7);
  addKey("7", Seven_Key, 0x02, 7);
  addKey("REPLAY", Replay_Key, 0x03, 7);
  addKey("WIDE", AspectRatio_Key, 0x04, 7);
  addKey("MUTE", Mute_Key, 0x05, 7);
  addKey("SUBTITLES", Captions_Key, 0x06, 7);
  addKey("2", Two_Key, 0x08, 7);
  addKey("5", Five_Key, 0x09, 7);
  addKey("8", Eight_Key, 0x0A, 7);
  addKey("UP", Up_Key, 0x0B, 7);
  addKey("OK", Select_Key, 0x0C, 7);
  addKey("DOWN", Down_Key, 0x0D, 7);
  addKey("0", Zero_Key, 0x0E, 7);
//  addKey("0/--", DoubleDigit_Key, 0x0E, 7);

  addKey("3", Three_Key, 0x10, 7);
  addKey("6", Six_Key, 0x11, 7);
  addKey("9", Nine_Key, 0x12, 7);
  addKey("GUIDE", Guide_Key, 0x15, 7);
  addKey("Blue", Blue_Key, 0x15, 7);
  addKey("LIVE", LiveTV_Key, 0x16, 7);
  addKey("AV", Input_Key, 0x18, 7);
  addKey("tvtouche", Unmapped_Key, 0x1C, 7);
  addKey("POWER", Power_Key, 0x1D, 7);
  addKey("TEXT", Teletext_Key, 0x1E, 7); // "Magenta"

  addKey("REV", Rewind_Key, 0x20, 7);
  addKey("PLAY", Play_Key, 0x21, 7);
  addKey("FWD", FastForward_Key, 0x23, 7);
  addKey("-/--", DoubleDigit_Key, 0x24, 7); // "nn", "tventer"
  addKey("CHNEXT", ChannelUp_Key, 0x25, 7); // "PR+"
  addKey("CHPREV", ChannelDown_Key, 0x27, 7); // "PR-"
  addKey("RETURN", PrevChannel_Key, 0x28, 7);
  addKey("VOLUP", VolumeUp_Key, 0x29, 7);
  addKey("VOLDOWN", VolumeDown_Key, 0x2A, 7);
  addKey("Videotext_Halt", TeletextHold_Key, 0x2B, 7); // "OPT"
  addKey("REC", Record_Key, 0x2C, 7);
  addKey("STOP", Stop_Key, 0x2D, 7);
  addKey("PAUSE", Pause_Key, 0x2E, 7);

  addKey("MENU", Menu_Key, 0x31, 7);
  addKey("LEFT", Left_Key, 0x36, 7);
  addKey("RIGHT", Right_Key, 0x37, 7);
  addKey("INFO", Info_Key, 0x38, 7);
  addKey("Yellow", Yellow_Key, 0x38, 7);
  addKey("Red", Red_Key, 0x39, 7); // "PRESETS", "tv_lock"
  addKey("Green", Green_Key, 0x3B, 7); // "LIST", "tv_timer"
  addKey("EXIT", Exit_Key, 0x3E, 7);

  addKey("Videotext_Info", Unmapped_Key, 0x7F, 7);
}


ThomsonVCR1::ThomsonVCR1(
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      Thomson_Make,
      MediaControl_Panels | MediaRecord_Panels,
      index)
{
}


void ThomsonVCR1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new ThomsonProtocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x0, 4);

  addKey("1", One_Key, 0x00, 7);
  addKey("4", Four_Key, 0x01, 7);
  addKey("7", Seven_Key, 0x02, 7);
  addKey("vcr_mode", Mode_Key, 0x04, 7);
  addKey("SP/LP", VHSSpeed_Key, 0x05, 7); // "vcr_again" -- odd
  addKey("2", Two_Key, 0x08, 7);
  addKey("5", Five_Key, 0x09, 7);
  addKey("8", Eight_Key, 0x0A, 7);
  addKey("0", Zero_Key, 0x0E, 7);

  addKey("3", Three_Key, 0x10, 7);
  addKey("6", Six_Key, 0x11, 7);
  addKey("9", Nine_Key, 0x12, 7);
  addKey("GUIDE", Guide_Key, 0x15, 7);
  addKey("Blue", Blue_Key, 0x15, 7);
  addKey("AV", Input_Key, 0x18, 7);
  addKey("POWER", Power_Key, 0x1D, 7);
  addKey("Magenta", Teletext_Key, 0x1E, 7); // "TEXT"
  addKey("Rew", Rewind_Key, 0x1F, 7);

  addKey("Play", Play_Key, 0x20, 7);
  addKey("F_FWD", FastForward_Key, 0x21, 7);
  addKey("Pause", Pause_Key, 0x22, 7);
  addKey("Rec", Record_Key, 0x23, 7);
  addKey("Stop", Stop_Key, 0x24, 7);
  addKey("vcr_open", Eject_Key, 0x26, 7);
  addKey("vcr_return", PrevChannel_Key, 0x28, 7);
  addKey("CHANNRL+", ChannelUp_Key, 0x29, 7);
  addKey("CHANNEL-", ChannelDown_Key, 0x2A, 7);

  addKey("MENU", Menu_Key, 0x31, 7);
  addKey("OK", Select_Key, 0x33, 7);
  addKey("UP", Up_Key, 0x34, 7);
  addKey("DOWN", Down_Key, 0x35, 7);
  addKey("LEFT", Left_Key, 0x36, 7);
  addKey("RIGHT", Right_Key, 0x37, 7);
  addKey("INFO", Info_Key, 0x38, 7);
  addKey("YELLOW", Yellow_Key, 0x38, 7);
  addKey("RED", Red_Key, 0x39, 7); // "vcr_Lock"
  addKey("GREEN", Green_Key, 0x3B, 7);
  addKey("vcr_timer", Timer_Key, 0x3B, 7);
  addKey("INDEX_MARK", IndexSearch_Key, 0x3C, 7);
  addKey("Reset_counter", Reset_Key, 0x3D, 7);
  addKey("EXIT", Exit_Key, 0x3E, 7); // "vcr_clear" -- need child keyset?
}


ThomsonVCR1a::ThomsonVCR1a(
  unsigned int index)
  : ThomsonVCR1(index)
{
  setKeysetName("VCR Keyset 1a");
}


void ThomsonVCR1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  ThomsonVCR1::populateProtocol(guiObject);

  setPreData(0xA, 4);
}


ThomsonDVD1::ThomsonDVD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Thomson_Make,
      MediaControl_Panels,
      index)
{
}


void ThomsonDVD1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new ThomsonProtocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x4, 4);

  addKey("1", One_Key, 0x00, 7);
  addKey("4", Four_Key, 0x01, 7);
  addKey("7", Seven_Key, 0x02, 7);
  addKey("dvd_mode", Mode_Key, 0x05, 7);
  addKey("2", Two_Key, 0x08, 7);
  addKey("5", Five_Key, 0x09, 7);
  addKey("8", Eight_Key, 0x0A, 7);
  addKey("0", Zero_Key, 0x0E, 7);

  addKey("3", Three_Key, 0x10, 7);
  addKey("6", Six_Key, 0x11, 7);
  addKey("9", Nine_Key, 0x12, 7);
  addKey("YELLOW", Yellow_Key, 0x14, 7);
  addKey("dvd_info", Info_Key, 0x14, 7);
  addKey("BLUE", Blue_Key, 0x15, 7);
  addKey("dvd_title", DiscTitle_Key, 0x15, 7);
  addKey("MARKER", Unmapped_Key, 0x16, 7);
  addKey("VIOLET", Unmapped_Key, 0x17, 7);
  addKey("dvd_cam", Angle_Key, 0x17, 7);
  addKey("PAUSE", Pause_Key, 0x18, 7);
  addKey("MENU", Menu_Key, 0x19, 7);
  addKey("dvd_av", Input_Key, 0x1A, 7);
  addKey("GREEN", Green_Key, 0x1B, 7);
  addKey("dvd_timer", Timer_Key, 0x1B, 7);
  addKey("OFF", Power_Key, 0x1D, 7);
  addKey("REW", Rewind_Key, 0x1F, 7);

  addKey("PLAY", Play_Key, 0x20, 7);
  addKey("FFW", FastForward_Key, 0x21, 7);
  addKey("ZOOM", Zoom_Key, 0x23, 7);
  addKey("STOP", Stop_Key, 0x24, 7);
  addKey("EJECT", Eject_Key, 0x26, 7);
  addKey("CH+", ChannelUp_Key, 0x27, 7);
  addKey("CH-", ChannelDown_Key, 0x28, 7);
  addKey("RETURN", PrevChannel_Key, 0x29, 7);
  addKey("EXIT", Exit_Key, 0x29, 7);
  addKey("PROG/RANDOM", Program_Key, 0x2A, 7);
  addKey("PROG/RANDOM", Random_Key, 0x2A, 7);
  addKey("REPLAY", Replay_Key, 0x2C, 7); // "dvd_again"

  addKey("SURROUND", Surround_Key, 0x32, 7);
  addKey("OK", Select_Key, 0x33, 7);
  addKey("UP", Up_Key, 0x34, 7);
  addKey("DOWN", Down_Key, 0x35, 7);
  addKey("LEFT", Left_Key, 0x36, 7);
  addKey("RIGHT", Right_Key, 0x37, 7);
  addKey("RED", Red_Key, 0x39, 7); // "lock"
  addKey("THREE_CIRCLE", Unmapped_Key, 0x3C, 7);
  addKey("CLEAR", Clear_Key, 0x3D, 7); // "SOURCE"
  addKey("dvd_record", Record_Key, 0x3E, 7);
}


ThomsonSat1::ThomsonSat1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Sat Keyset 1",
      Thomson_Make,
      TV_Panels | MediaControl_Panels | MediaRecord_Panels,
      index)
{
}


void ThomsonSat1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new ThomsonProtocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0xC, 4);

  addKey("1", One_Key, 0x00, 7);
  addKey("4", Four_Key, 0x01, 7);
  addKey("7", Seven_Key, 0x02, 7);
  addKey("mute", Mute_Key, 0x05, 7);
  addKey("2", Two_Key, 0x08, 7);
  addKey("5", Five_Key, 0x09, 7);
  addKey("8", Eight_Key, 0x0A, 7);
  addKey("red", Red_Key, 0x0D, 7);
  addKey("0", Zero_Key, 0x0E, 7);

  addKey("3", Three_Key, 0x10, 7);
  addKey("6", Six_Key, 0x11, 7);
  addKey("9", Nine_Key, 0x12, 7);
  addKey("radio", TunerInput_Key, 0x18, 7);
  addKey("menu", Menu_Key, 0x19, 7);
  addKey("green", Green_Key, 0x1A, 7);
  addKey("blue", Blue_Key, 0x1C, 7);
  addKey("pwr", Power_Key, 0x1D, 7);
  addKey("text", Teletext_Key, 0x1E, 7); // "purple"
  addKey("rev", Rewind_Key, 0x1F, 7);

  addKey("play", Play_Key, 0x20, 7);
  addKey("fwd", FastForward_Key, 0x21, 7);
  addKey("pause", Pause_Key, 0x22, 7);
  addKey("rec", Record_Key, 0x23, 7);
  addKey("stop", Stop_Key, 0x24, 7);
  addKey("ch_up", ChannelUp_Key, 0x25, 7);
  addKey("ch_down", ChannelDown_Key, 0x27, 7);
  addKey("back", PrevChannel_Key, 0x28, 7);
  addKey("vol_down", VolumeDown_Key, 0x2A, 7);
  addKey("vol_up", VolumeUp_Key, 0x2B, 7);
  addKey("again", Repeat_Key, 0x2C, 7);
  addKey("advance", Advance_Key, 0x2D, 7);
  addKey("av", Input_Key, 0x2E, 7);
  addKey("live", LiveTV_Key, 0x2F, 7);

  addKey("yellow", Yellow_Key, 0x32, 7);
  addKey("ok", Select_Key, 0x33, 7);
  addKey("up", Up_Key, 0x34, 7);
  addKey("down", Down_Key, 0x35, 7);
  addKey("left", Left_Key, 0x36, 7);
  addKey("right", Right_Key, 0x37, 7);
  addKey("exit", Exit_Key, 0x3D, 7);
}


void ThomsonSat1::populateInputList(
  QComboBox *cb) const
{
  cb->clear();

  cb->addItem("Radio", QVariant(TunerInput_Key));
  cb->addItem("AV", QVariant(Input_Key));
}


ThomsonAudio1::ThomsonAudio1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 1",
      Thomson_Make,
      Receiver_Panels,
      index)
{
}


void ThomsonAudio1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, false);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0xFF80, 16);

  addKey("source", Input_Key, 0x80, 8);
  addKey("play", Play_Key, 0x84, 8);
  addKey("stop", Stop_Key, 0x88, 8);
  addKey("trackNext", Next_Key, 0x8C, 8);
  addKey("volDown", VolumeDown_Key, 0x8D, 8);
  addKey("trackBack", Previous_Key, 0x90, 8);
  addKey("volUp", VolumeUp_Key, 0x91, 8);
  addKey("soundEffect", Unmapped_Key, 0x93, 8);
  addKey("band", ToggleBand_Key, 0x94, 8);
  addKey("mode", Mode_Key, 0x95, 8);
  addKey("select", Select_Key, 0x99, 8); // ?
  addKey("presUp", ChannelUp_Key, 0x9C, 8);
  addKey("presUp", NextPreset_Key, 0x9C, 8);
  addKey("presDown", ChannelDown_Key, 0x9D, 8);
  addKey("presDown", PrevPreset_Key, 0x9D, 8);
}


ThomsonAudio2::ThomsonAudio2(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 2",
      Thomson_Make,
      Receiver_Panels,
      index)
{
}


void ThomsonAudio2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new RCAProtocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0xC, 4);

  addKey("Sleep", Sleep_Key, 0x07, 8);
  addKey("Menu", Menu_Key, 0x12, 8);
  addKey("Tune +", ChannelUp_Key, 0x20, 8);
  addKey("Tune -", ChannelDown_Key, 0x22, 8);
  addKey("Power", Power_Key, 0x2A, 8);
  addKey("CH+", Unmapped_Key, 0x2C, 8); // hoping "Tune +" instead
  addKey("CH-", Unmapped_Key, 0x2D, 8);
  addKey("Volume -", VolumeDown_Key, 0x2E, 8);
  addKey("Arrow_Down", Down_Key, 0x2E, 8);
  addKey("Volume +", VolumeUp_Key, 0x2F, 8);
  addKey("Arrow_Up", Up_Key, 0x2F, 8);
  addKey("0", Zero_Key, 0x30, 8);
  addKey("1", One_Key, 0x31, 8);
  addKey("2", Two_Key, 0x32, 8);
  addKey("3", Three_Key, 0x33, 8);
  addKey("4", Four_Key, 0x34, 8);
  addKey("5", Five_Key, 0x35, 8);
  addKey("6", Six_Key, 0x36, 8);
  addKey("7", Seven_Key, 0x37, 8);
  addKey("8", Eight_Key, 0x38, 8);
  addKey("9", Nine_Key, 0x39, 8);
  addKey("Info/Display", Info_Key, 0x3A, 8);
  addKey("Mute", Mute_Key, 0x3F, 8);
  addKey("OK/Select", Select_Key, 0x4F, 8);  // ?
  addKey("Last/Prev Ch", PrevChannel_Key, 0x56, 8); // ?
  addKey("Surround", SoundMode_Key, 0x5B, 8);
  addKey("Arrow_Left", Left_Key, 0x64, 8);
  addKey("Arrow_Right", Right_Key, 0x65, 8);
}
