//
// sony.cpp
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

#include "sony.h"
#include "protocols/sircprotocol.h"
#include "protocols/aiwaprotocol.h"
#include <QComboBox>


SonyTV1::SonyTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Sony_Make,
      TV_Panels | MediaControl_Panels | MediaRecord_Panels,
      index)
{
  addControlledDevice(Sony_Make, "KV-M1420D", TV_Device);
  addControlledDevice(Sony_Make, "KV-20FV10", TV_Device);
  addControlledDevice(Sony_Make, "KV-2167MT", TV_Device);
  addControlledDevice(Sony_Make, "KV-2184MT", TV_Device);
  addControlledDevice(Sony_Make, "KV-27FX210", TV_Device);
  addControlledDevice(Sony_Make, "KV-32FS210", TV_Device);
  addControlledDevice(Sony_Make, "KV-36FS210", TV_Device);
  addControlledDevice(Sony_Make, "KV-36FS13", TV_Device);
  addControlledDevice(Sony_Make, "KDL-23B4030", TV_Device);
  addControlledDevice(Sony_Make, "KDL-40EX403", TV_Device);
  addControlledDevice(Sony_Make, "KDL-40EX520", TV_Device);
  addControlledDevice(Sony_Make, "KDL-40X2000", TV_Device);
  addControlledDevice(Sony_Make, "KDL-52X2000", TV_Device);
  addControlledDevice(Sony_Make, "KDL-46X2000", TV_Device);
  addControlledDevice(Sony_Make, "KP-46WT520", TV_Device);
}


void SonyTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new SIRCProtocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  addSIRC12Key("1", One_Key, 0x01, 0x00);
  addSIRC12Key("2", Two_Key, 0x01, 0x01);
  addSIRC12Key("3", Three_Key, 0x01, 0x02);
  addSIRC12Key("4", Four_Key, 0x01, 0x03);
  addSIRC12Key("5", Five_Key, 0x01, 0x04);
  addSIRC12Key("6", Six_Key, 0x01, 0x05);
  addSIRC12Key("7", Seven_Key, 0x01, 0x06);
  addSIRC12Key("8", Eight_Key, 0x01, 0x07);
  addSIRC12Key("9", Nine_Key, 0x01, 0x08);
  addSIRC12Key("0", Zero_Key, 0x01, 0x09);
  addSIRC12Key("enter", Enter_Key, 0x01, 0x0B);
  addSIRC12Key("1-", Unmapped_Key, 0x01, 0x0C);
  addSIRC12Key("2-", Unmapped_Key, 0x01, 0x0D);
  addSIRC12Key("C", Clear_Key, 0x01, 0x0E); // "C00"
  addSIRC12Key("CHANNEL/PAGE+", ChannelUp_Key, 0x01, 0x10);
  addSIRC12Key("CHANNEL/PAGE-", ChannelDown_Key, 0x01, 0x11);
  addSIRC12Key("VOLUME+", VolumeUp_Key, 0x01, 0x12);
  addSIRC12Key("VOLUME-", VolumeDown_Key, 0x01, 0x13);
  addSIRC12Key("MUTE", Mute_Key, 0x01, 0x14);
  addSIRC12Key("POWER", Power_Key, 0x01, 0x15);
  addSIRC12Key("normalise", Reset_Key, 0x01, 0x16); // "reset"
  addSIRC12Key("a/b", Audio_Key, 0x01, 0x17); // "mts", "sap", "language"
  addSIRC12Key("picture_up", ContrastUp_Key, 0x01, 0x18); // "Contrast Up"
  addSIRC12Key("picture_down", ContrastDown_Key, 0x1, 0x19); // "Contrast Down"
  addSIRC12Key("-/--", DoubleDigit_Key, 0x01, 0x1D);
  addSIRC12Key("tv/video", Input_Key, 0x01, 0x25);
  addSIRC12Key("bucket", Unmapped_Key, 0x01, 0x28);
  addSIRC12Key("stereo", Surround_Key, 0x01, 0x29);
  addSIRC12Key("ANT", AntennaInput_Key, 0x01, 0x2A);
  addSIRC12Key("time", Clock_Key, 0x01, 0x2B);
  addSIRC12Key("timer/block", Timer_Key, 0x01, 0x30);
  addSIRC12Key("right", Right_Key, 0x01, 0x33);
  addSIRC12Key("left", Left_Key, 0x01, 0x34);
  addSIRC12Key("sleep", Sleep_Key, 0x01, 0x36);
  addSIRC12Key("TV-RETURN", Unmapped_Key, 0x01, 0x38); // "analog"
  addSIRC12Key("?/INFO", Info_Key, 0x01, 0x3A); // Teletext Index
  addSIRC12Key("prev_ch", PrevChannel_Key, 0x01, 0x3B); // "jump"
  addSIRC12Key("off/repeat", Repeat_Key, 0x01, 0x3C);
  addSIRC12Key("TELETXT", Teletext_Key, 0x01, 0x3F);
  addSIRC12Key("favourite", Unmapped_Key, 0x01, 0x4A); // separate keyset?
  addSIRC12Key("cable", CableInput_Key, 0x01, 0x4E);
  addSIRC12Key("Sat", SatInput_Key, 0x01, 0x51);
  addSIRC12Key("pip_ch+", PIPChannelUp_Key, 0x01, 0x58);
  addSIRC12Key("pip_ch-", PIPChannelDown_Key, 0x01, 0x59);
  addSIRC12Key("piptv_video", PIPSource_Key, 0x01, 0x5A);
  addSIRC12Key("PIP", PIP_Key, 0x01, 0x5B);
  addSIRC12Key("pipfreeze", PIPPause_Key, 0x01, 0x5C);
  addSIRC12Key("PIP_POSITION", PIPMove_Key, 0x01, 0x5E);
  addSIRC12Key("PIP_SWAP", PIPSwap_Key, 0x01, 0x5F);
  addSIRC12Key("MENU", Menu_Key, 0x01, 0x60);
  addSIRC12Key("Settup_V", Unmapped_Key, 0x01, 0x61); // alternate pic mode
  addSIRC12Key("Settup_A", Unmapped_Key, 0x01, 0x62); // alternate sound mode
  addSIRC12Key("EXIT", Exit_Key, 0x01, 0x63);
  addSIRC12Key("picturemode", PictureMode_Key, 0x01, 0x64);
  addSIRC12Key("OK", Select_Key, 0x01, 0x65); // "return", "select", "enter"
  addSIRC12Key("output", Unmapped_Key, 0x01, 0x66);
  addSIRC12Key("PIP_SOURCE", Unmapped_Key, 0x01, 0x67); // separate keyset?
  addSIRC12Key("asterisk", Unmapped_Key, 0x01, 0x68); // "TV System"
  addSIRC12Key("auto_program", Unmapped_Key, 0x01, 0x6B);
  addSIRC12Key("setup", Program_Key, 0x01, 0x6C);
  addSIRC12Key("tune_down", Unmapped_Key, 0x01, 0x6F); // "search -"
  addSIRC12Key("tune_up", Unmapped_Key, 0x01, 0x6E); // "search +"
  addSIRC12Key("up", Up_Key, 0x01, 0x74);
  addSIRC12Key("down", Down_Key, 0x01, 0x75);
  addSIRC12Key("diamond", Unmapped_Key, 0x01, 0x78); // "add"
  addSIRC12Key("erase", Unmapped_Key, 0x01, 0x79);
  addSIRC12Key("select", Unmapped_Key, 0x01, 0x7C); // PictureMode_Key?

  addSIRC12Key("vt_inf", TeletextIndex_Key, 0x03, 0x48); // "Teletext Home"
  addSIRC12Key("expand", TeletextSize_Key, 0x03, 0x49);
  addSIRC12Key("Teletext Hold", TeletextHold_Key, 0x03, 0x4A); // "shrink"
  addSIRC12Key("subtitles", Unmapped_Key, 0x03, 0x4B); // Teletext subtitles
  addSIRC12Key("LEFT/-/RED", Red_Key, 0x03, 0x4C);
  addSIRC12Key("UP/GREEN", Green_Key, 0x03, 0x4D);
  addSIRC12Key("RIGHT/+/YELLOW", Yellow_Key, 0x03, 0x4E);
  addSIRC12Key("DOWN/BLUE", Blue_Key, 0x03, 0x4F);

  addSIRC15Key("SYNC_MENU", CECMenu_Key, 0x1A, 0x58);
  addSIRC15Key("SCENE", Unmapped_Key, 0x1A, 0x78);
  addSIRC15Key("INTERNET_VIDEO", Unmapped_Key, 0x1A, 0x79);
  addSIRC15Key("I-MANUAL", Unmapped_Key, 0x1A, 0x7B);

  addSIRC15Key("DIGITAL_ANALOG", Unmapped_Key, 0x77, 0x0D);
  addSIRC15Key("DIGITAL", Unmapped_Key, 0x77, 0x52);
  addSIRC15Key("theatre", Unmapped_Key, 0x77, 0x60); // "Home Theater"
  addSIRC15Key("FAVORITES", Favorites_Key, 0x77, 0x76);

  addSIRC15Key("STOP", Stop_Key, 0x97, 0x18);
  addSIRC15Key("PAUSE", Pause_Key, 0x97, 0x19);
  addSIRC15Key("PLAY", Play_Key, 0x97, 0x1A);
  addSIRC15Key("FBACKWARD", Rewind_Key, 0x97, 0x1B);
  addSIRC15Key("FFORWARD", FastForward_Key, 0x97, 0x1C);
  addSIRC15Key("DOT", Unmapped_Key, 0x97, 0x1D);
  addSIRC15Key("RETURN", Back_Key, 0x97, 0x23);
  addSIRC15Key("TOOLS", ToolsMenu_Key, 0x97, 0x36); // "OPTIONS"
  addSIRC15Key("PREVIOUS", Previous_Key, 0x97, 0x3C);
  addSIRC15Key("NEXT", Next_Key, 0x97, 0x3D);
  addSIRC15Key("REPLAY", Replay_Key, 0x97, 0x79);
  addSIRC15Key("ADVANCE", Advance_Key, 0x97, 0x78);
  addSIRC15Key("SOUND", Unmapped_Key, 0x97, 0x7B);

  addSIRC15Key("Surround_Mode", Unmapped_Key, 0xA4, 0x1F); // "Music"
  addSIRC15Key("16:9", AspectRatio_Key, 0xA4, 0x3D); // "WIDE"
  addSIRC15Key("EPG", Guide_Key, 0xA4, 0x5B);
  addSIRC15Key("PIP_Audio", Unmapped_Key, 0xA4, 0x7C);
}


void SonyTV1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("TV / Video", QVariant(Input_Key));
  cb->addItem("ANT", QVariant(AntennaInput_Key));
  cb->addItem("Cable", QVariant(CableInput_Key));
  cb->addItem("Sat", QVariant(SatInput_Key));
}


SonyTV1a::SonyTV1a(
  unsigned int index)
  : SonyTV1(index)
{
  setKeysetName("TV Keyset 1a");

  addControlledDevice(Sony_Make, "KDW-25", TV_Device);
}


void SonyTV1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  SonyTV1::populateProtocol(guiObject);

  addSIRC12Key("LEFT/-/RED", Left_Key, 0x03, 0x4C);
  addSIRC12Key("UP/GREEN", Up_Key, 0x03, 0x4D);
  addSIRC12Key("RIGHT/+/YELLOW", Right_Key, 0x03, 0x4E);
  addSIRC12Key("DOWN/BLUE", Down_Key, 0x03, 0x4F);
}


SonyTV1b::SonyTV1b(
  unsigned int index)
  : SonyTV1a(index)
{
  setKeysetName("TV Keyset 1b");
}


void SonyTV1b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  SonyTV1a::populateProtocol(guiObject);

  addSIRC12Key("clear", Unmapped_Key, 0x01, 0x34); // "Clock Clear"
  addSIRC12Key("level_plus", Unmapped_Key, 0x01, 0x74);
  addSIRC12Key("level_minus", Unmapped_Key, 0x01, 0x75);
  addSIRC12Key("am/pm", Unmapped_Key, 0x01, 0x33);
}


// Not sure about these codes:
SonyTV1c::SonyTV1c(
  unsigned int index)
  : SonyTV1(index)
{
  setKeysetName("TV Keyset 1c");
}


void SonyTV1c::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  SonyTV1::populateProtocol(guiObject);

  addSIRC12Key(">>", FastForward_Key, 0x01, 0x58);
  addSIRC12Key("<<", Rewind_Key, 0x01, 0x59);
  addSIRC12Key("rec", Record_Key, 0x01, 0x5A);
  addSIRC12Key("pause", Pause_Key, 0x01, 0x5C);
  addSIRC12Key("stop", Stop_Key, 0x01, 0x5E);
  addSIRC12Key("play", Play_Key, 0x01, 0x5F);

  addSIRC15Key("BLUE", Blue_Key, 0x97, 0x24);
  addSIRC15Key("RED", Red_Key, 0x97, 0x25);
  addSIRC15Key("GREEN", Green_Key, 0x97, 0x26);
  addSIRC15Key("YELLOW", Yellow_Key, 0x97, 0x27);
  addSIRC15Key("SUBTITLES", Captions_Key, 0x97, 0x28);
}


SonyTV2::SonyTV2(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 2",
      Sony_Make,
      TV_Panels,
      index)
{
}


void SonyTV2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new AiwaProtocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x0119, 13);

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
  addKey("sleep", Sleep_Key, 0x0A, 8);
  addKey("tv/av", Input_Key, 0x0E, 8);
  addKey("back", PrevChannel_Key, 0x0F, 8);

  addKey("display", Info_Key, 0x10, 8);
  addKey("cc", Captions_Key, 0x11, 8);
  addKey("input 1", Unmapped_Key, 0x12, 8);
  addKey("pip on/off", PIP_Key, 0x13, 8);
  addKey("pip move", PIPMove_Key, 0x14, 8);
  addKey("mute", Mute_Key, 0x15, 8);
  addKey("pip swap", PIPSwap_Key, 0x16, 8);
  addKey("menu", Menu_Key, 0x17, 8);
  addKey("ch-", ChannelDown_Key, 0x1A, 8);
  addKey("ch-", Down_Key, 0x1A, 8);
  addKey("ch+", ChannelUp_Key, 0x1B, 8);
  addKey("ch+", Up_Key, 0x1B, 8);
  addKey("power", Power_Key, 0x1C, 8);
  addKey("freeze", PIPPause_Key, 0x1D, 8);
  addKey("vol-", VolumeDown_Key, 0x1E, 8);
  addKey("vol-", Left_Key, 0x1E, 8);
  addKey("vol+", VolumeUp_Key, 0x1F, 8);
  addKey("vol+", Right_Key, 0x1F, 8);
}


// These controls don't quite match other SIRC data.  (some do, some don't)
// This all taken from LIRC "AMPIR" config file.
SonyAmp1::SonyAmp1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Amp Keyset 1",
      Sony_Make,
      MediaControl_Panels,
      index)
{
}


void SonyAmp1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new SIRCProtocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  addSIRC12Key("1", One_Key, 0x0C, 0x00);
  addSIRC12Key("2", Two_Key, 0x0C, 0x01);
  addSIRC12Key("3", Three_Key, 0x0C, 0x02);
  addSIRC12Key("4", Four_Key, 0x0C, 0x03);
  addSIRC12Key("5", Five_Key, 0x0C, 0x04);
  addSIRC12Key("6", Six_Key, 0x0C, 0x05);
  addSIRC12Key("7", Seven_Key, 0x0C, 0x06);
  addSIRC12Key("8", Eight_Key, 0x0C, 0x07);
  addSIRC12Key("9", Nine_Key, 0x0C, 0x08);
  addSIRC12Key("0", Zero_Key, 0x0C, 0x09);
  addSIRC12Key("ENTER", Enter_Key, 0x0C, 0x0B);
  addSIRC12Key("DIGITAL", Unmapped_Key, 0x0C, 0x0C);
  addSIRC12Key("VIDEO3", ComponentInput_Key, 0x0C, 0x0A);
  addSIRC12Key("VIDEO4", Component2Input_Key, 0x0C, 0x0B);
  addSIRC12Key("VOL+", VolumeUp_Key, 0x0C, 0x12);
  addSIRC12Key("VOL-", VolumeDown_Key, 0x0C, 0x13);
  addSIRC12Key("MUTE", Mute_Key, 0x0C, 0x14);
  addSIRC12Key("POWER", Power_Key, 0x0C, 0x15);
  addSIRC12Key("LD", LDInput_Key, 0x0C, 0x19);
  addSIRC12Key("TV", AntennaInput_Key, 0x0C, 0x18);
  addSIRC12Key("VIDEO2", Composite2Input_Key, 0x0C, 0x1E);
  addSIRC12Key("PHONO", PhonoInput_Key, 0x0C, 0x20);
  addSIRC12Key("TUNER", TunerInput_Key, 0x0C, 0x21);
  addSIRC12Key("VIDEO1", CompositeInput_Key, 0x0C, 0x22);
  addSIRC12Key("TAPE", TapeInput_Key, 0x0C, 0x23);
  addSIRC12Key("CD", CDInput_Key, 0x0C, 0x25);
  addSIRC12Key("DAT", ScartInput_Key, 0x0C, 0x46); // hack
  addSIRC12Key("SLEEP", Sleep_Key, 0x0C, 0x60);
  addSIRC12Key("MD", MDInput_Key, 0x0C, 0x69);
  addSIRC12Key("TV2", Antenna2Input_Key, 0x0C, 0x6A);
  addSIRC12Key("5.1CH", Unmapped_Key, 0x0C, 0x72);
  addSIRC12Key("DVD", DVDInput_Key, 0x0C, 0x7D);
}


void SonyAmp1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("Tuner", QVariant(TunerInput_Key));
  cb->addItem("CD", QVariant(CDInput_Key));
  cb->addItem("Tape", QVariant(TapeInput_Key));
  cb->addItem("Phono", QVariant(PhonoInput_Key));
  cb->addItem("MD", QVariant(MDInput_Key));
  cb->addItem("DAT", QVariant(ScartInput_Key));
  cb->addItem("TV", QVariant(AntennaInput_Key));
  cb->addItem("TV2", QVariant(Antenna2Input_Key));
  cb->addItem("DVD", QVariant(DVDInput_Key));
  cb->addItem("LD", QVariant(LDInput_Key));
  cb->addItem("Video 1", CompositeInput_Key);
  cb->addItem("Video 2", Composite2Input_Key);
  cb->addItem("Video 3", ComponentInput_Key);
  cb->addItem("Video 4", Component2Input_Key);
}


// These taken from LIRC config file "RM-AV2100T".
SonyAmp2::SonyAmp2(
  unsigned int index)
  : PIRKeysetMetaData(
      "Amp Keyset 2",
      Sony_Make,
      MediaControl_Panels,
      index)
{
}


void SonyAmp2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new SIRCProtocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  addSIRC12Key("up", Up_Key, 0x0C, 0x78);
  addSIRC12Key("down", Down_Key, 0x0C, 0x79);
  addSIRC12Key("left", Left_Key, 0x0C, 0x7A);
  addSIRC12Key("right", Right_Key, 0x0C, 0x7B);

  addSIRC12Key("program_+", ChannelUp_Key, 0x0D, 0x10);
  addSIRC12Key("program_-", ChannelDown_Key, 0x0D, 0x11);
  addSIRC12Key("shift", Unmapped_Key, 0x0D, 0x55);

  addSIRC12Key("1", One_Key, 0x10, 0x00);
  addSIRC12Key("2", Two_Key, 0x10, 0x01);
  addSIRC12Key("3", Three_Key, 0x10, 0x02);
  addSIRC12Key("4", Four_Key, 0x10, 0x03);
  addSIRC12Key("5", Five_Key, 0x10, 0x04);
  addSIRC12Key("6", Six_Key, 0x10, 0x05);
  addSIRC12Key("7", Seven_Key, 0x10, 0x06);
  addSIRC12Key("8", Eight_Key, 0x10, 0x07);
  addSIRC12Key("9", Nine_Key, 0x10, 0x08);
  addSIRC12Key("0", Zero_Key, 0x10, 0x09);
  addSIRC12Key("enter", Enter_Key, 0x10, 0x0C);
  addSIRC12Key("vol_+", VolumeUp_Key, 0x10, 0x12);
  addSIRC12Key("vol_-", VolumeDown_Key, 0x10, 0x13);
  addSIRC12Key("mute", Mute_Key, 0x10, 0x14);
  addSIRC12Key("power", Power_Key, 0x10, 0x15);
  addSIRC12Key("aux/vdp", AuxInput_Key, 0x10, 0x1D);
  addSIRC12Key("video2", Composite2Input_Key, 0x10, 0x1E);
  addSIRC12Key("phono", PhonoInput_Key, 0x10, 0x20);
  addSIRC12Key("tuner", TunerInput_Key, 0x10, 0x21);
  addSIRC12Key("video1", CompositeInput_Key, 0x10, 0x22);
  addSIRC12Key("tape", TapeInput_Key, 0x10, 0x23);
  addSIRC12Key("cd", CDInput_Key, 0x10, 0x25);
  addSIRC12Key("power_on", PowerOn_Key, 0x10, 0x2E);
  addSIRC12Key("video3", ComponentInput_Key, 0x10, 0x42);
  addSIRC12Key("tv", CableInput_Key, 0x10, 0x6A);
  addSIRC12Key("dvd", DVDInput_Key, 0x10, 0x7D);

  addSIRC15Key("md/dat", MDInput_Key, 0x10, 0x69);
}


void SonyAmp2::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("Tuner", QVariant(TunerInput_Key));
  cb->addItem("CD", QVariant(CDInput_Key));
  cb->addItem("Tape", QVariant(TapeInput_Key));
  cb->addItem("Phono", QVariant(PhonoInput_Key));
  cb->addItem("Aux / VDP", QVariant(AuxInput_Key));
  cb->addItem("TV", QVariant(CableInput_Key));
  cb->addItem("Video 1", QVariant(CompositeInput_Key));
  cb->addItem("Video 2", QVariant(Composite2Input_Key));
  cb->addItem("Video 3", QVariant(ComponentInput_Key));
  cb->addItem("DVD", QVariant(DVDInput_Key));
  cb->addItem("MD / DAT", QVariant(MDInput_Key));
}


SonyAudio1::SonyAudio1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 1",
      Sony_Make,
      Receiver_Panels | MediaRecord_Panels,
      index)
{
}


void SonyAudio1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new SIRCProtocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  addSIRC12Key("tv_video", Input_Key, 0x01, 0x25);

  addSIRC12Key("DSG", Unmapped_Key, 0x0C, 0x31);

  addSIRC12Key("MEMORY", Program_Key, 0x0D, 0x0E);
  addSIRC12Key("TUNER-BAND", TunerInput_Key, 0x0D, 0x0F);
  addSIRC12Key("TUNING_MODE", Unmapped_Key, 0x0D, 0x17);
  addSIRC12Key("STEREO-MONO", FMMode_Key, 0x0D, 0x21);

  addSIRC12Key("DIR_MODE", Unmapped_Key, 0x0E, 0x14);
  addSIRC12Key("REC", Record_Key, 0x0E, 0x1E);
  addSIRC12Key("TAPE", TapeInput_Key, 0x0E, 0x34);

  addSIRC12Key("tuner", ChannelUp_Key, 0x10, 0x0F); // "Tune Up"
  addSIRC12Key("VOL+", VolumeUp_Key, 0x10, 0x12);
  addSIRC12Key("VOL-", VolumeDown_Key, 0x10, 0x13);
  addSIRC12Key("ON-OFF", Power_Key, 0x10, 0x15);
  addSIRC12Key("effect_on_off", Unmapped_Key, 0x10, 0x1F);
  addSIRC12Key("tape", TapeInput_Key, 0x10, 0x23);
  addSIRC12Key("cd", CDInput_Key, 0x10, 0x25);
  addSIRC12Key("DISPLAY", Info_Key, 0x10, 0x4B);
  addSIRC12Key("dimmer", Unmapped_Key, 0x10, 0x4D);
  addSIRC12Key("karaoke_mpx", Unmapped_Key, 0x10, 0x5F);
  addSIRC12Key("SLEEP", Sleep_Key, 0x10, 0x60);
  addSIRC12Key("TIMER_SELECT", Unmapped_Key, 0x10, 0x62); // "clock_select"
  addSIRC12Key("TIMER_SET", Timer_Key, 0x10, 0x65);
  addSIRC12Key("md", MDInput_Key, 0x10, 0x69);
  addSIRC12Key("game", Unmapped_Key, 0x10, 0x7C);

  addSIRC12Key("CD_REPEAT", Repeat_Key, 0x11, 0x2C);
  addSIRC12Key("CD", Unmapped_Key, 0x11, 0x32);
  addSIRC12Key("PLAY_MODE", Unmapped_Key, 0x11, 0x6C);

  addSIRC15Key("cinema_effect", Unmapped_Key, 0x90, 0x08);
  addSIRC15Key("game_mixing", Unmapped_Key, 0x90, 0x33);
  addSIRC15Key("spectrum", Unmapped_Key, 0x90, 0x34);
  addSIRC15Key("p_file", Unmapped_Key, 0x90, 0x39);
  addSIRC15Key("surround_speaker_mode", Surround_Key, 0x90, 0x5F);
  addSIRC15Key("music_eq", Unmapped_Key, 0x90, 0x60);
  addSIRC15Key("movie_eq", Unmapped_Key, 0x90, 0x61);
  addSIRC15Key("game_eq", Unmapped_Key, 0x90, 0x62);

  addSIRC20Key("return", Exit_Key, 0x31, 0x1A, 0x0E);
  addSIRC20Key("prev_r", Unmapped_Key, 0x31, 0x1A, 0x36);
  addSIRC20Key("next_r", Unmapped_Key, 0x31, 0x1A, 0x37);
  addSIRC20Key("special_menu", Menu_Key, 0x31, 0x1A, 0x53);
  addSIRC20Key("on_screen", Unmapped_Key, 0x31, 0x1A, 0x55);
  addSIRC20Key("sharp", Unmapped_Key, 0x31, 0x1A, 0x6B);
  addSIRC20Key("flat", Unmapped_Key, 0x31, 0x1A, 0x6C);
  addSIRC20Key("album-", Unmapped_Key, 0x31, 0x1A, 0x6E);
  addSIRC20Key("album+", Unmapped_Key, 0x31, 0x1A, 0x6F);

  addSIRC20Key("1", One_Key, 0x39, 0x1A, 0x00);
  addSIRC20Key("2", Two_Key, 0x39, 0x1A, 0x01);
  addSIRC20Key("3", Three_Key, 0x39, 0x1A, 0x02);
  addSIRC20Key("4", Four_Key, 0x39, 0x1A, 0x03);
  addSIRC20Key("5", Five_Key, 0x39, 0x1A, 0x04);
  addSIRC20Key("6", Six_Key, 0x39, 0x1A, 0x05);
  addSIRC20Key("7", Seven_Key, 0x39, 0x1A, 0x06);
  addSIRC20Key("8", Eight_Key, 0x39, 0x1A, 0x07);
  addSIRC20Key("9", Nine_Key, 0x39, 0x1A, 0x08);
  addSIRC20Key("0", Zero_Key, 0x39, 0x1A, 0x09);
  addSIRC20Key("KEY_ENTER", Enter_Key, 0x39, 0x1A, 0x0C);
  addSIRC20Key("gt_10", DoubleDigit_Key, 0x39, 0x1A, 0x0D);
  addSIRC20Key("clear", Clear_Key, 0x39, 0x1A, 0x0F);
  addSIRC20Key("repeat", Repeat_Key, 0x39, 0x1A, 0x2C);
  addSIRC20Key("KEY_PREV_SONG", Previous_Key, 0x39, 0x1A, 0x30);
  addSIRC20Key("KEY_NEXT_SONG", Next_Key, 0x39, 0x1A, 0x31);
  addSIRC20Key("KEY_PREV", Rewind_Key, 0x39, 0x1A, 0x33); // "Rewind"
  addSIRC20Key("KEY_NEXT", FastForward_Key, 0x39, 0x1A, 0x34); // "Fast Forward"
  addSIRC20Key("KEY_STOP", Stop_Key, 0x39, 0x1A, 0x38);
  addSIRC20Key("KEY_PAUSE", Pause_Key, 0x39, 0x1A, 0x39);
  addSIRC20Key("d_skip", NextDisc_Key, 0x39, 0x1A, 0x3E);
  addSIRC20Key("up", Up_Key, 0x39, 0x1A, 0x78);
  addSIRC20Key("down", Down_Key, 0x39, 0x1A, 0x79);
  addSIRC20Key("left", Left_Key, 0x39, 0x1A, 0x7A);
  addSIRC20Key("right", Right_Key, 0x39, 0x1A, 0x7B);
  addSIRC20Key("Select", Select_Key, 0x39, 0x1A, 0x7C);
}


void SonyAudio1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("TV / Video", QVariant(Input_Key));
  cb->addItem("Tuner Band", QVariant(TunerInput_Key));
  cb->addItem("CD", QVariant(CDInput_Key));
  cb->addItem("Tape", QVariant(TapeInput_Key));
  cb->addItem("MD", QVariant(MDInput_Key));
}


SonyAudio1a::SonyAudio1a(
  unsigned int index)
  : SonyAudio1(index)
{
  setKeysetName("Audio Keyset 1a");
}


void SonyAudio1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  SonyAudio1::populateProtocol(guiObject);

//  addSIRC20Key("select", Select_Key, 0x39, 0x1A, 0x32); // Doesn't make sense
  addSIRC20Key("play", Play_Key, 0x39, 0x1A, 0x32);
  addSIRC20Key("play_mode", Unmapped_Key, 0x39, 0x1A, 0x26);
  addSIRC20Key("enter", Select_Key, 0x39, 0x1A, 0x7C);
}


SonyDAT1::SonyDAT1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DAT Keyset 1",
      Sony_Make,
      MediaControl_Panels | MediaRecord_Panels,
      index)
{
}


void SonyDAT1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new SIRCProtocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPostData(0x07, 5);

  addSIRC12Key("1", One_Key, 0x1C, 0x00);
  addSIRC12Key("2", Two_Key, 0x1C, 0x01);
  addSIRC12Key("3", Three_Key, 0x1C, 0x02);
  addSIRC12Key("4", Four_Key, 0x1C, 0x03); 
  addSIRC12Key("5", Five_Key, 0x1C, 0x04);
  addSIRC12Key("6", Six_Key, 0x1C, 0x05);
  addSIRC12Key("7", Seven_Key, 0x1C, 0x06);
  addSIRC12Key("8", Eight_Key, 0x1C, 0x07);
  addSIRC12Key("9", Nine_Key, 0x1C, 0x08);
  addSIRC12Key("0", Zero_Key, 0x1C, 0x14);
  addSIRC12Key("PLAY", Play_Key, 0x1C, 0x3A);
  addSIRC12Key("PAUSE", Pause_Key, 0x1C, 0x39);
  addSIRC12Key("STOP", Stop_Key, 0x1C, 0x38);
  addSIRC12Key("<<", Rewind_Key, 0x1C, 0x3B);
  addSIRC12Key(">>", FastForward_Key, 0x1C, 0x3C);
  addSIRC12Key("|<<", Previous_Key, 0x1C, 0x68);
  addSIRC12Key(">>|", Next_Key, 0x1C, 0x69);
  addSIRC12Key("RECORD", Record_Key, 0x1C, 0x3E);
  addSIRC12Key("Open/Close", Eject_Key, 0x1C, 0x20);

  // The following commands are dubious:
  addSIRC12Key("VOL+", VolumeUp_Key, 0x1C, 0x12);
  addSIRC12Key("VOL-", VolumeDown_Key, 0x1C, 0x13);
  addSIRC12Key("POWER_ON", PowerOn_Key, 0x1C, 0x2E);
  addSIRC12Key("POWER_OFF", PowerOff_Key, 0x1C, 0x2F);
  addSIRC12Key("MUTE", Mute_Key, 0x1C, 0x14); // Makes no sense...
  addSIRC12Key("POWER", Power_Key, 0x1C, 0x15);
  addSIRC12Key("ENTER", Enter_Key, 0x1C, 0x0B);
}


SonyDVD1::SonyDVD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Sony_Make,
      MediaControl_Panels,
      index)
{
  addControlledDevice(Sony_Make, "DVP-CX985V", DVD_Device);
  addControlledDevice(Sony_Make, "DVP-NS608P", DVD_Device);
}


void SonyDVD1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new SIRCProtocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  addSIRC20Key("1", One_Key, 0x49, 0x1A, 0x00);
  addSIRC20Key("2", Two_Key, 0x49, 0x1A, 0x01);
  addSIRC20Key("3", Three_Key, 0x49, 0x1A, 0x02);
  addSIRC20Key("4", Four_Key, 0x49, 0x1A, 0x03);
  addSIRC20Key("5", Five_Key, 0x49, 0x1A, 0x04);
  addSIRC20Key("6", Six_Key, 0x49, 0x1A, 0x05);
  addSIRC20Key("7", Seven_Key, 0x49, 0x1A, 0x06);
  addSIRC20Key("8", Eight_Key, 0x49, 0x1A, 0x07);
  addSIRC20Key("9", Nine_Key, 0x49, 0x1A, 0x08);
  addSIRC20Key("0", Zero_Key, 0x49, 0x1A, 0x09);
  addSIRC20Key("select", Select_Key, 0x49, 0x1A, 0x0B); //"Enter"
  addSIRC20Key("Disc Explorer", Unmapped_Key, 0x49, 0x1A, 0x0C);
  addSIRC20Key("Ent", Enter_Key, 0x49, 0x1A, 0x0D); // "Set"
  addSIRC20Key("return", Exit_Key, 0x49, 0x1A, 0x0E);
  addSIRC20Key("CLEAR", Clear_Key, 0x49, 0x1A, 0x0F);
  addSIRC20Key("-/--", DoubleDigit_Key, 0x49, 0x1A, 0x0F);

  addSIRC20Key("Input", Input_Key, 0x49, 0x1A, 0x12);
  addSIRC20Key("prog+", ChannelUp_Key, 0x49, 0x1A, 0x13);
  addSIRC20Key("prog-", ChannelDown_Key, 0x49, 0x1A, 0x14);
  addSIRC20Key("power", Power_Key, 0x49, 0x1A, 0x15);
  addSIRC20Key("open/close", Eject_Key, 0x49, 0x1A, 0x16);
  addSIRC20Key("rec", Record_Key, 0x49, 0x1A, 0x19);
  addSIRC20Key("top_menu", DiscTitle_Key, 0x49, 0x1A, 0x1A); // "Title"
  addSIRC20Key("dvd_menu", DiscMenu_Key, 0x49, 0x1A, 0x1B);
  addSIRC20Key("program", Program_Key, 0x49, 0x1A, 0x1F);
  addSIRC20Key("step/search -", StepBack_Key, 0x49, 0x1A, 0x20);
  addSIRC20Key("step/search +", StepForward_Key, 0x49, 0x1A, 0x21);
  addSIRC20Key("scan/slow -", SlowMinus_Key, 0x49, 0x1A, 0x22);
  addSIRC20Key("scan/slow +", SlowPlus_Key, 0x49, 0x1A, 0x23);
  addSIRC20Key("INDEX-", Unmapped_Key, 0x49, 0x1A, 0x26);
  addSIRC20Key("INDEX+", Unmapped_Key, 0x49, 0x1A, 0x27);
  addSIRC20Key("TIME", Unmapped_Key, 0x49, 0x1A, 0x28);
  addSIRC20Key("JOG_STOP", Unmapped_Key, 0x49, 0x1A, 0x29); // "Pause"
  addSIRC20Key("a-b", RepeatAB_Key, 0x49, 0x1A, 0x2A);
  addSIRC20Key("repeat", Repeat_Key, 0x49, 0x1A, 0x2C);
  addSIRC20Key("POWER_ON", PowerOn_Key, 0x49, 0x1A, 0x2E);
  addSIRC20Key("POWER_OFF", PowerOff_Key, 0x49, 0x1A, 0x2F);

  addSIRC20Key("prev", Previous_Key, 0x49, 0x1A, 0x30);
  addSIRC20Key("next", Next_Key, 0x49, 0x1A, 0x31);
  addSIRC20Key("play", Play_Key, 0x49, 0x1A, 0x32);
  addSIRC20Key("rew", Rewind_Key, 0x49, 0x1A, 0x33);
  addSIRC20Key("ffwd", FastForward_Key, 0x49, 0x1A, 0x34);
  addSIRC20Key("shuffle", Random_Key, 0x49, 0x1A, 0x35);
  addSIRC20Key("X2_BACK", Unmapped_Key, 0x49, 0x1A, 0x36);
  addSIRC20Key("X2_FORWARD", Unmapped_Key, 0x49, 0x1A, 0x37);
  addSIRC20Key("stop", Stop_Key, 0x49, 0x1A, 0x38);
  addSIRC20Key("pause", Pause_Key, 0x49, 0x1A, 0x39);
//  addSIRC20Key("STEP_BACK", Unmapped_Key, 0x49, 0x1A, 0x3A); // "Jog Rev"
//  addSIRC20Key("STEP_FORWARD", Unmapped_Key, 0x49, 0x1A, 0x3B); // "Jog Fwd"
  addSIRC20Key("RecStop", RecordStop_Key, 0x49, 0x1A, 0x3D);
  addSIRC20Key("RecPause", RecordPause_Key, 0x49, 0x1A, 0x3E);

  addSIRC20Key("DNR", NoiseReduction_Key, 0x49, 0x1A, 0x48);
  addSIRC20Key("SEARCH_MODE", Unmapped_Key, 0x49, 0x1A, 0x4B);
  addSIRC20Key("Picture_Navi", Unmapped_Key, 0x49, 0x1A, 0x50);
  addSIRC20Key("TV_DVD", Unmapped_Key, 0x49, 0x1A, 0x51);
  addSIRC20Key("menu", Menu_Key, 0x49, 0x1A, 0x53); // "setup"
  addSIRC20Key("Display", Info_Key, 0x49, 0x1A, 0x54);
  addSIRC20Key("surround", Surround_Key, 0x49, 0x1A, 0x5A);
  addSIRC20Key("PICTUREMODE", PictureMode_Key, 0x49, 0x1A, 0x5B);
  addSIRC20Key("Replay", Replay_Key, 0x49, 0x1A, 0x5C);
  addSIRC20Key("SA-CD_MULTI/2CH", Unmapped_Key, 0x49, 0x1A, 0x5E);
  addSIRC20Key("SA-CD/CD", Unmapped_Key, 0x49, 0x1A, 0x5F);

//  addSIRC20Key("SLOW_BACK", SlowMinus_Key, 0x49, 0x1A, 0x60);
//  addSIRC20Key("SLOW_FORWARD", SlowPlus_Key, 0x49, 0x1A, 0x61);
  addSIRC20Key("SUBTITLE_ON_OFF", Captions_Key, 0x49, 0x1A, 0x62);
  addSIRC20Key("Subtitle Change", Unmapped_Key, 0x49, 0x1A, 0x63);
  addSIRC20Key("Language", Audio_Key, 0x49, 0x1A, 0x64); // "Audio"
  addSIRC20Key("ANGLE_CHANGE", Angle_Key, 0x49, 0x1A, 0x65); // "Angle"
  addSIRC20Key("up", Up_Key, 0x49, 0x1A, 0x79);
  addSIRC20Key("down", Down_Key, 0x49, 0x1A, 0x7A);
  addSIRC20Key("left", Left_Key, 0x49, 0x1A, 0x7B);
  addSIRC20Key("right", Right_Key, 0x49, 0x1A, 0x7C);
}


/*
SonyDVD1b::SonyDVD1b(
  unsigned int index)
  : SonyDVD1(index)
{
  setKeysetName("DVD Keyset 1b");
}


void SonyDVD1b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  SonyDVD1::populateProtocol(guiObject);

  addSIRC20Key("SLOW-", SlowMinus_Key, 0x49, 0x1A, 0x72);
  addSIRC20Key("SLOW+", SlowPlus_Key, 0x49, 0x1A, 0x73);
}
*/


SonyDVD1a::SonyDVD1a(
  unsigned int index)
  : SonyDVD1(index)
{
  setKeysetName("DVD Keyset 1a");
}


void SonyDVD1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  SonyDVD1::populateProtocol(guiObject);

  addSIRC20Key("up", Up_Key, 0x49, 0x1A, 0x39);
  addSIRC20Key("down", Down_Key, 0x49, 0x1A, 0x38);
  addSIRC20Key("left", Left_Key, 0x49, 0x1A, 0x33);
  addSIRC20Key("right", Right_Key, 0x49, 0x1A, 0x34);
  addSIRC20Key("ok", Select_Key, 0x49, 0x1A, 0x32);
}


SonyDVD1b::SonyDVD1b(
  unsigned int index)
  : SonyDVD1(index)
{
  setKeysetName("DVD Keyset 1b");
}


void SonyDVD1b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  SonyDVD1::populateProtocol(guiObject);

  addSIRC20Key("Advance", Advance_Key, 0x62, 0x1A, 0x14);
  addSIRC20Key("Guide", Guide_Key, 0x62, 0x1A, 0x16);
  addSIRC20Key("Options", Unmapped_Key, 0x62, 0x1A, 0x17); // "Tools"
  addSIRC20Key("Dot", Unmapped_Key, 0x62, 0x1A, 0x1D);
  addSIRC20Key("file", Unmapped_Key, 0x62, 0x1A, 0x20);
  addSIRC20Key("sort", Unmapped_Key, 0x62, 0x1A, 0x21);
  addSIRC20Key("edit", Unmapped_Key, 0x62, 0x1A, 0x22);
  addSIRC20Key("ALBUM-MINUS", Unmapped_Key, 0x62, 0x1A, 0x29);
  addSIRC20Key("ALBUM-PLUS", Unmapped_Key, 0x62, 0x1A, 0x2A);
  addSIRC20Key("F1", Unmapped_Key, 0x62, 0x1A, 0x2E); // "HDD"
  addSIRC20Key("F2", Unmapped_Key, 0x62, 0x1A, 0x2F); // "DVD"
  addSIRC20Key("picture memory", Unmapped_Key, 0x62, 0x1A, 0x3C);
  addSIRC20Key("disc skip -", PrevDisc_Key, 0x62, 0x1A, 0x3D);
  addSIRC20Key("DiscSkip", NextDisc_Key, 0x62, 0x1A, 0x3E); // "disc skip +"
  addSIRC20Key("folder", Unmapped_Key, 0x62, 0x1A, 0x40);
  addSIRC20Key("Favorites", Favorites_Key, 0x62, 0x1A, 0x5E);
  addSIRC20Key("Purple", Blue_Key, 0x62, 0x1A, 0x66);
  addSIRC20Key("Red", Red_Key, 0x62, 0x1A, 0x67);
  addSIRC20Key("Green", Green_Key, 0x62, 0x1A, 0x68);
  addSIRC20Key("Yellow", Yellow_Key, 0x62, 0x1A, 0x69);
  addSIRC20Key("ZOOM", Zoom_Key, 0x62, 0x1A, 0x79);
}


SonyDVD2::SonyDVD2(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 2",
      Sony_Make,
      MediaControl_Panels,
      index)
{
  addControlledDevice(Sony_Make, "RDR-GX360", DVD_Device);
}


void SonyDVD2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new SIRCProtocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  addSIRC20Key("Title List", Unmapped_Key, 0x0B, 0x1A, 0x10);
  addSIRC20Key("Original playlist", Unmapped_Key, 0x0B, 0x1A, 0x11);
  addSIRC20Key("Thumbnail", Unmapped_Key, 0x0B, 0x1A, 0x12);
  addSIRC20Key("Chapter Mark", Unmapped_Key, 0x0B, 0x1A, 0x13);
  addSIRC20Key("Instant Advance", Advance_Key, 0x0B, 0x1A, 0x14);
  addSIRC20Key("Tools", ToolsMenu_Key, 0x0B, 0x1A, 0x17);
  addSIRC20Key("Cursor Mode", Unmapped_Key, 0x0B, 0x1A, 0x18);
  addSIRC20Key("Zoom -", Unmapped_Key, 0x0B, 0x1A, 0x19);
  addSIRC20Key("Mark Erase", Unmapped_Key, 0x0B, 0x1A, 0x1A);
  addSIRC20Key("Timer", Timer_Key, 0x0B, 0x1A, 0x1C);
  addSIRC20Key("Timer List", Unmapped_Key, 0x0B, 0x1A, 0x37);
  addSIRC20Key("Synchro Rec", Unmapped_Key, 0x0B, 0x1A, 0x77);
  addSIRC20Key("Zoom", Zoom_Key, 0x0B, 0x1A, 0x79); // "Zoom +"

  addSIRC20Key("1", One_Key, 0xFA, 0x1A, 0x00);
  addSIRC20Key("2", Two_Key, 0xFA, 0x1A, 0x01);
  addSIRC20Key("3", Three_Key, 0xFA, 0x1A, 0x02);
  addSIRC20Key("4", Four_Key, 0xFA, 0x1A, 0x03);
  addSIRC20Key("5", Five_Key, 0xFA, 0x1A, 0x04);
  addSIRC20Key("6", Six_Key, 0xFA, 0x1A, 0x05);
  addSIRC20Key("7", Seven_Key, 0xFA, 0x1A, 0x06);
  addSIRC20Key("8", Eight_Key, 0xFA, 0x1A, 0x07);
  addSIRC20Key("9", Nine_Key, 0xFA, 0x1A, 0x08);
  addSIRC20Key("0", Zero_Key, 0xFA, 0x1A, 0x09);
  addSIRC20Key("Select", Select_Key, 0xFA, 0x1A, 0x0B);
  addSIRC20Key("Set", Unmapped_Key, 0xFA, 0x1A, 0x0D);
  addSIRC20Key("Return", Exit_Key, 0xFA, 0x1A, 0x0E);
  addSIRC20Key("Clear", Clear_Key, 0xFA, 0x1A, 0x0F);
  addSIRC20Key("Input Select", Input_Key, 0xFA, 0x1A, 0x12);
  addSIRC20Key("Channel +", ChannelUp_Key, 0xFA, 0x1A, 0x13);
  addSIRC20Key("Channel -", ChannelDown_Key, 0xFA, 0x1A, 0x14);
  addSIRC20Key("Power", Power_Key, 0xFA, 0x1A, 0x15);
  addSIRC20Key("Eject", Eject_Key, 0xFA, 0x1A, 0x16);
  addSIRC20Key("Record", Record_Key, 0xFA, 0x1A, 0x19);
  addSIRC20Key("Top Menu", DiscTitle_Key, 0xFA, 0x1A, 0x1A);
  addSIRC20Key("menu", DiscMenu_Key, 0xFA, 0x1A, 0x1B);
  addSIRC20Key("Rec Mode", Unmapped_Key, 0xFA, 0x1A, 0x1E);
  addSIRC20Key("Step Reverse", StepBack_Key, 0xFA, 0x1A, 0x20);
  addSIRC20Key("Step Fwd", StepForward_Key, 0xFA, 0x1A, 0x21);
  addSIRC20Key("Slow Forward", SlowPlus_Key, 0xFA, 0x1A, 0x23);
  addSIRC20Key("Time/Text", Unmapped_Key, 0xFA, 0x1A, 0x28);
  addSIRC20Key("Power On", PowerOn_Key, 0xFA, 0x1A, 0x2E);
  addSIRC20Key("Power Off", PowerOff_Key, 0xFA, 0x1A, 0x2F);
  addSIRC20Key("Track - (prev)", Previous_Key, 0xFA, 0x1A, 0x30);
  addSIRC20Key("Track + (next)", Next_Key, 0xFA, 0x1A, 0x31);
  addSIRC20Key("Play", Play_Key, 0xFA, 0x1A, 0x32);
  addSIRC20Key("rewind", Rewind_Key, 0xFA, 0x1A, 0x33);
  addSIRC20Key("Fast Forward", FastForward_Key, 0xFA, 0x1A, 0x34);
  addSIRC20Key("stop", Stop_Key, 0xFA, 0x1A, 0x38);
  addSIRC20Key("Pause", Pause_Key, 0xFA, 0x1A, 0x39);
  addSIRC20Key("Record Stop", RecordStop_Key, 0xFA, 0x1A, 0x3D);
  addSIRC20Key("Record Pause", RecordPause_Key, 0xFA, 0x1A, 0x3E);
  addSIRC20Key("System Menu", Menu_Key, 0xFA, 0x1A, 0x53);
  addSIRC20Key("Display", Info_Key, 0xFA, 0x1A, 0x54);
  addSIRC20Key("Surround", Surround_Key, 0xFA, 0x1A, 0x5A);
  addSIRC20Key("Instant Replay", Replay_Key, 0xFA, 0x1A, 0x5C);
  addSIRC20Key("Subtitle", Captions_Key, 0xFA, 0x1A, 0x63);
  addSIRC20Key("Audio", Audio_Key, 0xFA, 0x1A, 0x64);
  addSIRC20Key("angle", Angle_Key, 0xFA, 0x1A, 0x65);
  addSIRC20Key("Up", Up_Key, 0xFA, 0x1A, 0x79);
  addSIRC20Key("Down", Down_Key, 0xFA, 0x1A, 0x7A);
  addSIRC20Key("Left", Left_Key, 0xFA, 0x1A, 0x7B);
  addSIRC20Key("Right", Right_Key, 0xFA, 0x1A, 0x7C);
}


SonyDVD2a::SonyDVD2a(
  unsigned int index)
  : SonyDVD2(index)
{
  setKeysetName("DVD Keyset 2a");

  addControlledDevice(Sony_Make, "RDR-GX257", DVD_Device);
}


void SonyDVD2a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  SonyDVD2::populateProtocol(guiObject);

  addSIRC20Key("top menu / title List", DiscTitle_Key, 0x0B, 0x1A, 0x10);
  addSIRC20Key("marker", Unmapped_Key, 0x0B, 0x1A, 0x34);
  addSIRC20Key("search", Unmapped_Key, 0x0B, 0x1A, 0x35);

  addSIRC20Key("discrete off", PowerOff_Key, 0xFA, 0x1A, 0x29);
  addSIRC20Key("play mode", Unmapped_Key, 0xFA, 0x1A, 0x31);
}


SonyVCR1::SonyVCR1(
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      Sony_Make,
      MediaControl_Panels | MediaRecord_Panels,
      index)
{
}


void SonyVCR1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new SIRCProtocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  addSIRC12Key("VOL_UP", VolumeUp_Key, 0x01, 0x12);
  addSIRC12Key("VOL_DOWN", VolumeDown_Key, 0x01, 0x13);

  addSIRC12Key("red", Red_Key, 0x03, 0x4C);
  addSIRC12Key("green", Green_Key, 0x03, 0x4D);
  addSIRC12Key("Yellow", Yellow_Key, 0x03, 0x4E);
  addSIRC12Key("blue", Blue_Key, 0x03, 0x4F);

  addSIRC12Key("1", One_Key, 0x0B, 0x00);
  addSIRC12Key("2", Two_Key, 0x0B, 0x01);
  addSIRC12Key("3", Three_Key, 0x0B, 0x02);
  addSIRC12Key("4", Four_Key, 0x0B, 0x03);
  addSIRC12Key("5", Five_Key, 0x0B, 0x04);
  addSIRC12Key("6", Six_Key, 0x0B, 0x05);
  addSIRC12Key("7", Seven_Key, 0x0B, 0x06);
  addSIRC12Key("8", Eight_Key, 0x0B, 0x07);
  addSIRC12Key("9", Nine_Key, 0x0B, 0x08);
  addSIRC12Key("0", Zero_Key, 0x0B, 0x09);
//  addSIRC12Key("jump", PrevChannel_Key, 0x0B, 0x0A); // might be wrong
  addSIRC12Key("-/--", DoubleDigit_Key, 0x0B, 0x0A);
  addSIRC12Key("ENT", Enter_Key, 0x0B, 0x0B); // "Enter"

  addSIRC12Key("prog-next", ChannelUp_Key, 0x0B, 0x10);
  addSIRC12Key("prog-prev", ChannelDown_Key, 0x0B, 0x11);
  addSIRC12Key("pwon", Power_Key, 0x0B, 0x15);
  addSIRC12Key("stop", Stop_Key, 0x0B, 0x18);
  addSIRC12Key("pause", Pause_Key, 0x0B, 0x19);
  addSIRC12Key("play", Play_Key, 0x0B, 0x1A);
  addSIRC12Key("<<", Rewind_Key, 0x0B, 0x1B);
  addSIRC12Key(">>", FastForward_Key, 0x0B, 0x1C);
  addSIRC12Key("rec", Record_Key, 0x0B, 0x1D);
  addSIRC12Key("ant/sw", AntennaInput_Key, 0x0B, 0x2A);  // "tv/vcr"
  addSIRC12Key("power_on", PowerOn_Key, 0x0B, 0x2E);
  addSIRC12Key("Power Off", PowerOff_Key, 0x0B, 0x2F);
  addSIRC12Key("menu", Menu_Key, 0x0B, 0x4D);
  addSIRC12Key("input", Input_Key, 0x0B, 0x4F);
  addSIRC12Key("display", Info_Key, 0x0B, 0x5A);

  // Odd cursor keys, overlap with media controls:
  addSIRC12Key("down", Down_Key, 0x0B, 0x18);
  addSIRC12Key("up", Up_Key, 0x0B, 0x19);
  addSIRC12Key("ok", Select_Key, 0x0B, 0x1A);
  addSIRC12Key("left", Left_Key, 0x0B, 0x1B);
  addSIRC12Key("right", Right_Key, 0x0B, 0x1C);
}


void SonyVCR1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("Input", QVariant(Input_Key));
  cb->addItem("TV / VCR", QVariant(AntennaInput_Key));
}


SonyVCR1a::SonyVCR1a(
  unsigned int index)
  : SonyVCR1(index)
{
  setKeysetName("VCR Keyset 1a");
}


void SonyVCR1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  SonyVCR1::populateProtocol(guiObject);

  // These are the expected cursor keys:
  addSIRC12Key("up", Up_Key, 0x0B, 0x42);
  addSIRC12Key("down", Down_Key, 0x0B, 0x43);
  addSIRC12Key("left", Left_Key, 0x0B, 0x62);
  addSIRC12Key("right", Right_Key, 0x0B, 0x61);
  addSIRC12Key("execute", Select_Key, 0x0B, 0x51); //"OK"

//  addKey("SLEEP", Sleep_Key, 0x0B, 0x4F); // odd
}


// Extra codes off of hifi-remote website:
SonyVCR1b::SonyVCR1b(
  unsigned int index)
  : SonyVCR1a(index)
{
  setKeysetName("VCR Keyset 1b");
}


void SonyVCR1b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  SonyVCR1a::populateProtocol(guiObject);

  addSIRC12Key("Volume Up", VolumeUp_Key, 0x0B, 0x12);
  addSIRC12Key("Volume Down", VolumeDown_Key, 0x0B, 0x13);
  addSIRC12Key("Eject", Eject_Key, 0x0B, 0x16);
  addSIRC12Key("Record Pause", RecordPause_Key, 0x0B, 0x1E);
  addSIRC12Key("Record Mute", RecordMute_Key, 0x0B, 0x1F);
  addSIRC12Key("Auto Tracking", AutoTracking_Key, 0x0B, 0x27);
  addSIRC12Key("Frame Reverse", StepBack_Key, 0x0B, 0x30);
  addSIRC12Key("Frame Advance", StepForward_Key, 0x0B, 0x31);
  addSIRC12Key("Mute", Mute_Key, 0x0B, 0x35);
  addSIRC12Key("Sleep", Sleep_Key, 0x0B, 0x36);
  addSIRC12Key("Slow +", SlowPlus_Key, 0x0B, 0x3D);
  addSIRC12Key("Slow -", SlowMinus_Key, 0x0B, 0x3E);
  addSIRC12Key("Tracking Up", TrackingPlus_Key, 0x0B, 0x44);
  addSIRC12Key("Tracking Down", TrackingMinus_Key, 0x0B, 0x45);
  addSIRC12Key("SP/EP", VHSSpeed_Key, 0x0B, 0x58);
}


SonyReceiver1::SonyReceiver1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Receiver Keyset 1",
      Sony_Make,
      Receiver_Panels,
      index)
{
}


void SonyReceiver1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new SIRCProtocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  addSIRC15Key("1", One_Key, 0x30, 0x00);
  addSIRC15Key("2", Two_Key, 0x30, 0x01);
  addSIRC15Key("3", Three_Key, 0x30, 0x02);
  addSIRC15Key("4", Four_Key, 0x30, 0x03);
  addSIRC15Key("5", Five_Key, 0x30, 0x04);
  addSIRC15Key("6", Six_Key, 0x30, 0x05);
  addSIRC15Key("7", Seven_Key, 0x30, 0x06);
  addSIRC15Key("8", Eight_Key, 0x30, 0x07);
  addSIRC15Key("9", Nine_Key, 0x30, 0x08);
  addSIRC15Key("0", Zero_Key, 0x30, 0x09);
  addSIRC15Key("SELECT", Select_Key, 0x30, 0x0C);
  addSIRC15Key("VOLUME_UP", VolumeUp_Key, 0x30, 0x12);
  addSIRC15Key("VOLUME_DOWN", VolumeDown_Key, 0x30, 0x13);
  addSIRC15Key("MUTING", Mute_Key, 0x30, 0x14);
  addSIRC15Key("POWER", Power_Key, 0x30, 0x15);
  addSIRC15Key("VIDEO2", Composite2Input_Key, 0x30, 0x1E);
  addSIRC15Key("TUNER", TunerInput_Key, 0x30, 0x21);
  addSIRC15Key("VIDEO1", CompositeInput_Key, 0x30, 0x22);
  addSIRC15Key("SA_CD", CDInput_Key, 0x30, 0x25);
  addSIRC15Key("VIDEO3", ComponentInput_Key, 0x30, 0x42);
  addSIRC15Key("DISPLAY", Info_Key, 0x30, 0x4B);
  addSIRC15Key("SLEEP", Sleep_Key, 0x30, 0x60);
  addSIRC15Key("TV", AntennaInput_Key, 0x30, 0x6A);
  addSIRC15Key("DVD", DVDInput_Key, 0x30, 0x7D);

  addSIRC15Key("SAT", SatInput_Key, 0xB0, 0x03);
  addSIRC15Key("2CH", Unmapped_Key, 0xB0, 0x09);
  addSIRC15Key("AFD", Unmapped_Key, 0xB0, 0x0A);
  addSIRC15Key("MOVIE", Unmapped_Key, 0xB0, 0x0B);
  addSIRC15Key("DVD_MENU", DiscMenu_Key, 0xB0, 0x2D); // Not sure about this
  addSIRC15Key("MUSIC", Unmapped_Key, 0xB0, 0x49);
  addSIRC15Key("AMP_MENU", Menu_Key, 0xB0, 0x77);
  addSIRC15Key("UP", Up_Key, 0xB0, 0x78);
  addSIRC15Key("DOWN", Down_Key, 0xB0, 0x79);
  addSIRC15Key("LEFT", Left_Key, 0xB0, 0x7A);
  addSIRC15Key("RIGHT", Right_Key, 0xB0, 0x7B);
}


void SonyReceiver1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("Tuner", QVariant(TunerInput_Key));
  cb->addItem("SACD", QVariant(CDInput_Key));
  cb->addItem("TV", QVariant(AntennaInput_Key));
  cb->addItem("SAT", QVariant(SatInput_Key));
  cb->addItem("Video 1", QVariant(CompositeInput_Key));
  cb->addItem("Video 2", QVariant(Composite2Input_Key));
  cb->addItem("Video 3", QVariant(ComponentInput_Key));
  cb->addItem("DVD", QVariant(DVDInput_Key));
}


SonyCD1::SonyCD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "CD Keyset 1",
      Sony_Make,
      MediaControl_Panels,
      index)
{
}


void SonyCD1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new SIRCProtocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  addSIRC12Key("1", One_Key, 0x11, 0x00);
  addSIRC12Key("2", Two_Key, 0x11, 0x01);
  addSIRC12Key("3", Three_Key, 0x11, 0x02);
  addSIRC12Key("4", Four_Key, 0x11, 0x03);
  addSIRC12Key("5", Five_Key, 0x11, 0x04);
  addSIRC12Key("6", Six_Key, 0x11, 0x05);
  addSIRC12Key("7", Seven_Key, 0x11, 0x06);
  addSIRC12Key("8", Eight_Key, 0x11, 0x07);
  addSIRC12Key("9", Nine_Key, 0x11, 0x08);
  addSIRC12Key("ENTER", Enter_Key, 0x11, 0x0B);
  addSIRC12Key("check", Unmapped_Key, 0x11, 0x0D);
  addSIRC12Key("clear", Clear_Key, 0x11, 0x0F);

  addSIRC12Key("vol+", VolumeUp_Key, 0x11, 0x12);
  addSIRC12Key("vol-", VolumeDown_Key, 0x11, 0x13);
  addSIRC12Key("mute", Mute_Key, 0x11, 0x14);
  addSIRC12Key("power", Power_Key, 0x11, 0x15);
  addSIRC12Key("eject", Eject_Key, 0x11, 0x16);
  addSIRC12Key("C.INDEX", Unmapped_Key, 0x11, 0x18);
  addSIRC12Key("FILE", Memory_Key, 0x11, 0x19);
  addSIRC12Key("BANK", Call_Key, 0x11, 0x1A); // "file recall"
  addSIRC12Key("continue", Unmapped_Key, 0x11, 0x1D);
  addSIRC12Key("single", Unmapped_Key, 0x11, 0x1E);
  addSIRC12Key("pgm", Program_Key, 0x11, 0x1F);

  addSIRC12Key("10", Zero_Key, 0x11, 0x20); // "0"
  addSIRC12Key(">10", DoubleDigit_Key, 0x11, 0x27);
  addSIRC12Key("DISPLAY", Info_Key, 0x11, 0x28); // "time"
  addSIRC12Key("a-b", RepeatAB_Key, 0x11, 0x2A);
  addSIRC12Key("repeat", Repeat_Key, 0x11, 0x2C);
  addSIRC12Key("POWER_ON", PowerOn_Key, 0x11, 0x2E);
  addSIRC12Key("POWER_OFF", PowerOff_Key, 0x11, 0x2F);

  addSIRC12Key("|<<", Previous_Key, 0x11, 0x30);
  addSIRC12Key(">>|", Next_Key, 0x11, 0x31);
  addSIRC12Key("play", Play_Key, 0x11, 0x32);
  addSIRC12Key("<<", Rewind_Key, 0x11, 0x33);
  addSIRC12Key(">>", FastForward_Key, 0x11, 0x34);
  addSIRC12Key("shuffle", Random_Key, 0x11, 0x35);
  addSIRC12Key("cd_ind_dec", Unmapped_Key, 0x11, 0x36);
  addSIRC12Key("cd_ind_inc", Unmapped_Key, 0x11, 0x37);
  addSIRC12Key("stop", Stop_Key, 0x11, 0x38);
  addSIRC12Key("PAUSE", Pause_Key, 0x11, 0x39);
  addSIRC12Key("SLOW--", SlowMinus_Key, 0x11, 0x3A);
  addSIRC12Key("SLOW++", SlowPlus_Key, 0x11, 0x3B);
  addSIRC12Key("musicscan", Unmapped_Key, 0x11, 0x3C); // "intro"
  addSIRC12Key("prevDisc", PrevDisc_Key, 0x11, 0x3D);
  addSIRC12Key("disc_skip", NextDisc_Key, 0x11, 0x3E);

  addSIRC12Key("disc_1", Unmapped_Key, 0x11, 0x40);
  addSIRC12Key("disc_2", Unmapped_Key, 0x11, 0x41);
  addSIRC12Key("disc_3", Unmapped_Key, 0x11, 0x42);
  addSIRC12Key("disc_4", Unmapped_Key, 0x11, 0x43);
  addSIRC12Key("disc_5", Unmapped_Key, 0x11, 0x44);
  addSIRC12Key("DISC", Unmapped_Key, 0x11, 0x4A);
  addSIRC12Key("AUTO_SPACE", Unmapped_Key, 0x11, 0x4E);

  addSIRC12Key("fader", Unmapped_Key, 0x11, 0x5F); // "mute"

  addSIRC12Key("LEVEL_FILE", Unmapped_Key, 0x11, 0x68);
}


SonyCD1a::SonyCD1a(
  unsigned int index)
  : SonyCD1(index)
{
  setKeysetName("CD Keyset 1a");
}


void SonyCD1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  SonyCD1::populateProtocol(guiObject);

  addSIRC12Key("a-b", RepeatAB_Key, 0x11, 0x2D);
}


SonyCD1b::SonyCD1b(
  unsigned int index)
  : SonyCD1(index)
{
  setKeysetName("CD Keyset 1b");
}


void SonyCD1b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  SonyCD1::populateProtocol(guiObject);

  addSIRC12Key("display", Info_Key, 0x11, 0x56);
}


SonyProjector1::SonyProjector1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Projector Keyset 1",
      Sony_Make,
      MediaControl_Panels,
      index)
{
  addControlledDevice(Sony_Make, "RM-1271", Other_Device);
  addControlledDevice(Sony_Make, "VPL-SC50", Other_Device);
  addControlledDevice(Sony_Make, "VPL-HS10", Other_Device);
  addControlledDevice(Sony_Make, "VPL-HS20", Other_Device);
  addControlledDevice(Sony_Make, "VH11HT", Other_Device);
}


void SonyProjector1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new SIRCProtocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  addSIRC15Key("Switcher 1", Unmapped_Key, 0x54, 0x0A);
  addSIRC15Key("Switcher 2", Unmapped_Key, 0x54, 0x0B);
  addSIRC15Key("Switcher 3", Unmapped_Key, 0x54, 0x0C);
  addSIRC15Key("Switcher 4", Unmapped_Key, 0x54, 0x0D);
  addSIRC15Key("Switcher 5", Unmapped_Key, 0x54, 0x0E);
  addSIRC15Key("Switcher 6", Unmapped_Key, 0x54, 0x0F);
  addSIRC15Key("Switcher 7", Unmapped_Key, 0x54, 0x10);
  addSIRC15Key("Switcher 8", Unmapped_Key, 0x54, 0x11);
  addSIRC15Key("vol up", VolumeUp_Key, 0x54, 0x12);
  addSIRC15Key("vol down", VolumeDown_Key, 0x54, 0x13);
  addSIRC15Key("mute", Mute_Key, 0x54, 0x14);
  addSIRC15Key("power", Power_Key, 0x54, 0x15);
  addSIRC15Key("Contrast+", ContrastUp_Key, 0x54, 0x18);
  addSIRC15Key("Contrast-", ContrastDown_Key, 0x54, 0x19);
  addSIRC15Key("Color+", ColorUp_Key, 0x54, 0x1A);
  addSIRC15Key("Color-", ColorDown_Key, 0x54, 0x1B);
  addSIRC15Key("Brightness+", BrightnessUp_Key, 0x54, 0x1E);
  addSIRC15Key("Brightness-", BrightnessDown_Key, 0x54, 0x1F);
  addSIRC15Key("Hue+", Unmapped_Key, 0x54, 0x20);
  addSIRC15Key("Hue-", Unmapped_Key, 0x54, 0x21);
  addSIRC15Key("Sharpness+", Unmapped_Key, 0x54, 0x22);
  addSIRC15Key("Sharpness-", Unmapped_Key, 0x54, 0x23);
  addSIRC15Key("Pic Mute", Unmapped_Key, 0x54, 0x24);
  addSIRC15Key("Status ON", Unmapped_Key, 0x54, 0x25);
  addSIRC15Key("Status OFF", Unmapped_Key, 0x54, 0x26);
  addSIRC15Key("Secam", Unmapped_Key, 0x54, 0x27);
  addSIRC15Key("Clear Blue", Unmapped_Key, 0x54, 0x28);
  addSIRC15Key("menu", Menu_Key, 0x54, 0x29);
  addSIRC15Key("video 1 input", CompositeInput_Key, 0x54, 0x2A);
  addSIRC15Key("Input A", AuxInput_Key, 0x54, 0x2B);
  addSIRC15Key("video 2 input", Composite2Input_Key, 0x54, 0x2C);
  addSIRC15Key("power on", PowerOn_Key, 0x54, 0x2E);
  addSIRC15Key("power off", PowerOff_Key, 0x54, 0x2F);
  addSIRC15Key("Position +", Unmapped_Key, 0x54, 0x31);
  addSIRC15Key("Position -", Unmapped_Key, 0x54, 0x32);
  addSIRC15Key("right arrow", Right_Key, 0x54, 0x33);
  addSIRC15Key("left arrow", Left_Key, 0x54, 0x34);
  addSIRC15Key("up arrow", Up_Key, 0x54, 0x35);
  addSIRC15Key("down arrow", Down_Key, 0x54, 0x36);
  addSIRC15Key("Adjust Red", Unmapped_Key, 0x54, 0x41);
  addSIRC15Key("Adjust Green", Unmapped_Key, 0x54, 0x42);
  addSIRC15Key("Adjust Blue", Unmapped_Key, 0x54, 0x43);
  addSIRC15Key("Cutoff Red", Unmapped_Key, 0x54, 0x44);
  addSIRC15Key("Cutoff Green", Unmapped_Key, 0x54, 0x45);
  addSIRC15Key("Cutoff Blue", Unmapped_Key, 0x54, 0x46);
  addSIRC15Key("H Size", Unmapped_Key, 0x54, 0x47);
  addSIRC15Key("Shift", Unmapped_Key, 0x54, 0x48);
  addSIRC15Key("Center Red", Unmapped_Key, 0x54, 0x49);
  addSIRC15Key("Center Green", Unmapped_Key, 0x54, 0x4A);
  addSIRC15Key("Center Blue", Unmapped_Key, 0x54, 0x4B);
  addSIRC15Key("Size", Unmapped_Key, 0x54, 0x4C);
  addSIRC15Key("Linearity", Unmapped_Key, 0x54, 0x4D);
  addSIRC15Key("Skew", Unmapped_Key, 0x54, 0x4E);
  addSIRC15Key("Bow", Unmapped_Key, 0x54, 0x4F);
  addSIRC15Key("Keystone", Unmapped_Key, 0x54, 0x50);
  addSIRC15Key("Pin Cushion", Unmapped_Key, 0x54, 0x51);
  addSIRC15Key("Gain", Unmapped_Key, 0x54, 0x52);
  addSIRC15Key("Bias", Unmapped_Key, 0x54, 0x53);
  addSIRC15Key("Zone", Unmapped_Key, 0x54, 0x56);
  addSIRC15Key("tv/vcr", Input_Key, 0x54, 0x57);
  addSIRC15Key("Blanking", Unmapped_Key, 0x54, 0x58);
  addSIRC15Key("select", Select_Key, 0x54, 0x5A);
  addSIRC15Key("Enter", Unmapped_Key, 0x54, 0x5E);
  addSIRC15Key("Svideo 1", SVideoInput_Key, 0x54, 0x5F);
  addSIRC15Key("Index Second / 0 (All)", Unmapped_Key, 0x54, 0x60);
  addSIRC15Key("Index 1", Unmapped_Key, 0x54, 0x61);
  addSIRC15Key("Index 2", Unmapped_Key, 0x54, 0x62);
  addSIRC15Key("Index 3", Unmapped_Key, 0x54, 0x63);
  addSIRC15Key("Index 4", Unmapped_Key, 0x54, 0x64);
  addSIRC15Key("Index 5", Unmapped_Key, 0x54, 0x65);
  addSIRC15Key("Index 6", Unmapped_Key, 0x54, 0x66);
  addSIRC15Key("Index 7", Unmapped_Key, 0x54, 0x67);
  addSIRC15Key("Index 8", Unmapped_Key, 0x54, 0x68);
  addSIRC15Key("Index 9", Unmapped_Key, 0x54, 0x69);
  addSIRC15Key("Svideo 2", SVideo2Input_Key, 0x54, 0x6F);
  addSIRC15Key("Component Input", ComponentInput_Key, 0x54, 0x70);
  addSIRC15Key("Focus+", Unmapped_Key, 0x54, 0x74);
  addSIRC15Key("Focus-", Unmapped_Key, 0x54, 0x75);
  addSIRC15Key("Zoom+", Unmapped_Key, 0x54, 0x77);
  addSIRC15Key("Zoom-", Unmapped_Key, 0x54, 0x78);
  addSIRC15Key("reset", Reset_Key, 0x54, 0x7B);
  addSIRC15Key("Right and Left Arrows", Unmapped_Key, 0x54, 0x7C);
  addSIRC15Key("Normal", Unmapped_Key, 0x54, 0x7D);
  addSIRC15Key("Test", Unmapped_Key, 0x54, 0x7E);

  addSIRC20Key("ms slide", Unmapped_Key, 0x2A, 0x1A, 0x3C);
  addSIRC20Key("side shot +", Unmapped_Key, 0x2A, 0x1A, 0x3E); //"Keystone+"
  addSIRC20Key("side shot -", Unmapped_Key, 0x2A, 0x1A, 0x3F); //"Keystone-"
  addSIRC20Key("dynamic", One_Key, 0x2A, 0x1A, 0x51);
  addSIRC20Key("standard", Two_Key, 0x2A, 0x1A, 0x52);
  addSIRC20Key("cinema", Three_Key, 0x2A, 0x1A, 0x53);
  addSIRC20Key("user 1", Four_Key, 0x2A, 0x1A, 0x54);
  addSIRC20Key("user 2", Five_Key, 0x2A, 0x1A, 0x55);
  addSIRC20Key("user 3", Six_Key, 0x2A, 0x1A, 0x56);
  addSIRC20Key("apa", Unmapped_Key, 0x2A, 0x1A, 0x60);
  addSIRC20Key("wide mode", AspectRatio_Key, 0x2A, 0x1A, 0x6E);
  addSIRC20Key("lens", Unmapped_Key, 0x2A, 0x1A, 0x78);
}


void SonyProjector1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("TV / VCR", QVariant(Input_Key));
  cb->addItem("Video 1", QVariant(CompositeInput_Key));
  cb->addItem("Video 2", QVariant(Composite2Input_Key));
  cb->addItem("SVideo 1", QVariant(SVideoInput_Key));
  cb->addItem("SVideo 2", QVariant(SVideo2Input_Key));
  cb->addItem("Component", QVariant(ComponentInput_Key));
  cb->addItem("A", QVariant(AuxInput_Key));
}


SonyProjector1a::SonyProjector1a(
  unsigned int index)
  : SonyProjector1(index)
{
  setKeysetName("Projector Keyset 1a");

  addControlledDevice(Sony_Make, "VPL-VH11HT", Other_Device);
}


void SonyProjector1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  SonyProjector1::populateProtocol(guiObject);

  addSIRC15Key("input toggle", Input_Key, 0x54, 0x2C);
  addSIRC15Key("shift-left", Unmapped_Key, 0x54, 0x2F);
}


SonyPlaystation1::SonyPlaystation1(
  unsigned int index)
  : SonyDVD1(index)
{
  setKeysetName("Playstation Keyset 1");
}


void SonyPlaystation1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  SonyDVD1::populateProtocol(guiObject);

  addSIRC20Key("Select", PSSelect_Key, 0xDA, 0x1A, 0x50);
  addSIRC20Key("L3", PSL3_Key, 0xDA, 0x1A, 0x51);
  addSIRC20Key("R3", PSR3_Key, 0xDA, 0x1A, 0x52);
  addSIRC20Key("Start", PSStart_Key, 0xDA, 0x1A, 0x53);
  addSIRC20Key("Up", PSUp_Key, 0xDA, 0x1A, 0x54);
  addSIRC20Key("Right", PSRight_Key, 0xDA, 0x1A, 0x55);
  addSIRC20Key("Down", PSDown_Key, 0xDA, 0x1A, 0x56);
  addSIRC20Key("Left", PSLeft_Key, 0xDA, 0x1A, 0x57);
  addSIRC20Key("L2", PSL2_Key, 0xDA, 0x1A, 0x58);
  addSIRC20Key("R2", PSR2_Key, 0xDA, 0x1A, 0x59);
  addSIRC20Key("L1", PSL1_Key, 0xDA, 0x1A, 0x5A);
  addSIRC20Key("R1", PSR1_Key, 0xDA, 0x1A, 0x5B);
  addSIRC20Key("Triangle", PSTriangle_Key, 0xDA, 0x1A, 0x5C);
  addSIRC20Key("Circle", PSCircle_Key, 0xDA, 0x1A, 0x5D);
  addSIRC20Key("Cross", PSCross_Key, 0xDA, 0x1A, 0x5E);
  addSIRC20Key("Square", PSSquare_Key, 0xDA, 0x1A, 0x5F);
}


SonyHT1::SonyHT1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Home Theater Keyset 1",
      Sony_Make,
      Receiver_Panels,
      index)
{
}


void SonyHT1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated:
    return;
  }

  threadableProtocol = new SIRCProtocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  addSIRC15Key("Memory", Memory_Key, 0x50, 0x0E);
  addSIRC15Key("Band", ToggleBand_Key, 0x50, 0x0F);
  addSIRC15Key("Volume Up", VolumeUp_Key, 0x50, 0x12);
  addSIRC15Key("Volume Down", VolumeDown_Key, 0x50, 0x13);
  addSIRC15Key("Mute", Mute_Key, 0x50, 0x14);
  addSIRC15Key("Power", Power_Key, 0x50, 0x15);
  addSIRC15Key("Video 2", SatInput_Key, 0x50, 0x1E); // Sat key
  addSIRC15Key("Auto Format Direct", Unmapped_Key, 0x50, 0x1F);
  addSIRC15Key("Tuner", TunerInput_Key, 0x50, 0x21);
  addSIRC15Key("Video 1", CableInput_Key, 0x50, 0x22);
  addSIRC15Key("Power On", PowerOn_Key, 0x50, 0x2E);
  addSIRC15Key("Power Off", PowerOff_Key, 0x50, 0x2F);
  addSIRC15Key("Time", Unmapped_Key, 0x50, 0x4B);
  addSIRC15Key("Dimmer", Unmapped_Key, 0x50, 0x4D);
  addSIRC15Key("Sleep", Sleep_Key, 0x50, 0x60);
  addSIRC15Key("Amp Menu", Unmapped_Key, 0x50, 0x70); // is this right?
  addSIRC15Key("Display", Info_Key, 0x50, 0x74);
  addSIRC15Key("DVD", DVDInput_Key, 0x50, 0x7D);

  addSIRC15Key("Stop", Stop_Key, 0xD0, 0x00);
  addSIRC15Key("Pause", Pause_Key, 0xD0, 0x01);
  addSIRC15Key("Play", Play_Key, 0xD0, 0x02);
  addSIRC15Key("DVD Setup", Unmapped_Key, 0xD0, 0x07);
  addSIRC15Key("Night Mode", Unmapped_Key, 0xD0, 0x20);
  addSIRC15Key("Tune +", ChannelUp_Key, 0xD0, 0x2B);
  addSIRC15Key("Tune -", ChannelDown_Key, 0xD0, 0x2C);
  addSIRC15Key("Stereo/Mono, FM Mode", FMMode_Key, 0xD0, 0x2D);
  addSIRC15Key("Tuner Menu", Menu_Key, 0xD0, 0x2E);
  addSIRC15Key("Input Select", Input_Key, 0xD0, 0x30);
  addSIRC15Key("Bass Boost", EnhancedBass_Key, 0xD0, 0x4D);
  addSIRC15Key("Function", Unmapped_Key, 0xD0, 0x69);
  addSIRC15Key("Sound Field +", Unmapped_Key, 0xD0, 0x6E);
  addSIRC15Key("Sound Field -", Unmapped_Key, 0xD0, 0x6F);
  addSIRC15Key("Amp Menu", Unmapped_Key, 0xD0, 0x77);

  addSIRC20Key("1", One_Key, 0x10, 0x10, 0x00);
  addSIRC20Key("2", Two_Key, 0x10, 0x10, 0x01);
  addSIRC20Key("3", Three_Key, 0x10, 0x10, 0x02);
  addSIRC20Key("4", Four_Key, 0x10, 0x10, 0x03);
  addSIRC20Key("5", Five_Key, 0x10, 0x10, 0x04);
  addSIRC20Key("6", Six_Key, 0x10, 0x10, 0x05);
  addSIRC20Key("7", Seven_Key, 0x10, 0x10, 0x06);
  addSIRC20Key("8", Eight_Key, 0x10, 0x10, 0x07);
  addSIRC20Key("9", Nine_Key, 0x10, 0x10, 0x08);
  addSIRC20Key("0", Zero_Key, 0x10, 0x10, 0x09);
  addSIRC20Key("Enter", Enter_Key, 0x10, 0x10, 0x0C);
  addSIRC20Key(">10", DoubleDigit_Key, 0x10, 0x10, 0x0D);
  addSIRC20Key("Clear", Clear_Key, 0x10, 0x10, 0x0F);
  addSIRC20Key("Subtitle", Captions_Key, 0x10, 0x10, 0x11);
  addSIRC20Key("Audio", Audio_Key, 0x10, 0x10, 0x12);
  addSIRC20Key("Angle", Angle_Key, 0x10, 0x10, 0x13);
  addSIRC20Key("DVD Display", Unmapped_Key, 0x10, 0x10, 0x18);
  addSIRC20Key("DVD Top Menu", DiscMenu_Key, 0x10, 0x10, 0x19);
  addSIRC20Key("DVD Menu", Unmapped_Key, 0x10, 0x10, 0x1A);
  addSIRC20Key("Search Reverse", Unmapped_Key, 0x10, 0x10, 0x22);
  addSIRC20Key("Search Forward", Unmapped_Key, 0x10, 0x10, 0x23);
  addSIRC20Key("Play Mode", Unmapped_Key, 0x10, 0x10, 0x26);
  addSIRC20Key("Shuffle", Random_Key, 0x10, 0x10, 0x2A);
  addSIRC20Key("Program", Program_Key, 0x10, 0x10, 0x2B);
  addSIRC20Key("Repeat", Repeat_Key, 0x10, 0x10, 0x2C);
  addSIRC20Key("Repeat", Unmapped_Key, 0x10, 0x10, 0x2D); //??
  addSIRC20Key("Previous/Preset Down", Previous_Key, 0x10, 0x10, 0x30);
  addSIRC20Key("Previous/Preset Down", PrevPreset_Key, 0x10, 0x10, 0x30);
  addSIRC20Key("Next/Preset Up", Next_Key, 0x10, 0x10, 0x31);
  addSIRC20Key("Next/Preset Up", NextPreset_Key, 0x10, 0x10, 0x31);
  addSIRC20Key("Play", Play_Key, 0x10, 0x10, 0x32);
  addSIRC20Key("Rewind/Tuning Down", Rewind_Key, 0x10, 0x10, 0x33);
  addSIRC20Key("Fast Forward/Tuning Up", FastForward_Key, 0x10, 0x10, 0x34);
  addSIRC20Key("Stop", Stop_Key, 0x10, 0x10, 0x38);
  addSIRC20Key("Pause", Pause_Key, 0x10, 0x10, 0x39);
  addSIRC20Key("Repeat A-B", RepeatAB_Key, 0x10, 0x10, 0x3B);
  addSIRC20Key("Open/Close", Eject_Key, 0x10, 0x10, 0x3C);
  addSIRC20Key("Disc Skip", NextDisc_Key, 0x10, 0x10, 0x3E);
  addSIRC20Key("Name", Unmapped_Key, 0x10, 0x10, 0x5B);
  addSIRC20Key("Up", Up_Key, 0x10, 0x10, 0x78);
  addSIRC20Key("Down", Down_Key, 0x10, 0x10, 0x79);
  addSIRC20Key("Left", Left_Key, 0x10, 0x10, 0x7A);
  addSIRC20Key("Right", Right_Key, 0x10, 0x10, 0x7B);
  addSIRC20Key("Select", Select_Key, 0x10, 0x10, 0x7C);
  addSIRC20Key("Return", Exit_Key, 0x10, 0x10, 0x7D);
}


void SonyHT1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("Tuner", QVariant(TunerInput_Key));
  cb->addItem("DVD", QVariant(DVDInput_Key));
  cb->addItem("Video 1", QVariant(CableInput_Key));
  cb->addItem("Video 2", QVariant(CableInput_Key));
}


SonyCarStereo1::SonyCarStereo1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Car Stereo 1",
      Sony_Make,
      Receiver_Panels,
      index)
{
}


void SonyCarStereo1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new SIRCProtocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  addSIRC15Key("1", One_Key, 0x84, 0x00);
  addSIRC15Key("2", Two_Key, 0x84, 0x01);
  addSIRC15Key("3", Three_Key, 0x84, 0x02);
  addSIRC15Key("4", Four_Key, 0x84, 0x03);
  addSIRC15Key("5", Five_Key, 0x84, 0x04);
  addSIRC15Key("6", Six_Key, 0x84, 0x05);
  addSIRC15Key("7", Seven_Key, 0x84, 0x06);
  addSIRC15Key("8", Eight_Key, 0x84, 0x07);
  addSIRC15Key("9", Nine_Key, 0x84, 0x08);
  addSIRC15Key("10", DoubleDigit_Key, 0x84, 0x09);
  addSIRC15Key("Menu", Menu_Key, 0x84, 0x0A);
  addSIRC15Key("Off", Power_Key, 0x84, 0x0D);
  addSIRC15Key("FM/AM", ToggleBand_Key, 0x84, 0x0F);
  addSIRC15Key("FM/AM", TunerInput_Key, 0x84, 0x0F);
  addSIRC15Key("Sel", Select_Key, 0x84, 0x11);
  addSIRC15Key("Volume +", VolumeUp_Key, 0x84, 0x12);
  addSIRC15Key("Volume +", Up_Key, 0x84, 0x12);
  addSIRC15Key("Volume -", VolumeDown_Key, 0x84, 0x13);
  addSIRC15Key("Volume -", Down_Key, 0x84, 0x13);
  addSIRC15Key("Att (Mute)", Mute_Key, 0x84, 0x14);
  addSIRC15Key("Seek -, Previous", Previous_Key, 0x84, 0x1B);
  addSIRC15Key("Seek -, Previous", Left_Key, 0x84, 0x1B);
  addSIRC15Key("Seek +, Next", Next_Key, 0x84, 0x1C);
  addSIRC15Key("Seek +, Next", Right_Key, 0x84, 0x1C);
  addSIRC15Key("Preset - long", Unmapped_Key, 0x84, 0x1D);
  addSIRC15Key("Preset + long", Unmapped_Key, 0x84, 0x1E);
  addSIRC15Key("Sound", Unmapped_Key, 0x84, 0x20);
  addSIRC15Key("Local/Mono", Unmapped_Key, 0x84, 0x21);
  addSIRC15Key("TA On/Off", Unmapped_Key, 0x84, 0x22);
  addSIRC15Key("Scroll", Unmapped_Key, 0x84, 0x23);
  addSIRC15Key("List, PTY", Unmapped_Key, 0x84, 0x27);
  addSIRC15Key("Display", Info_Key, 0x84, 0x28);
  addSIRC15Key("OPEN-CLOSE", Eject_Key, 0x84, 0x2B);
  addSIRC15Key("MBP", Unmapped_Key, 0x84, 0x2C);
//  addSIRC15Key("Preset - short", Unmapped_Key, 0x84, 0x30);
  addSIRC15Key("FF", FastForward_Key, 0x84, 0x30);
//  addSIRC15Key("Preset + short", Unmapped_Key, 0x84, 0x31);
  addSIRC15Key("REW", Rewind_Key, 0x84, 0x31);
  addSIRC15Key("Disc -", PrevDisc_Key, 0x84, 0x32);
  addSIRC15Key("Disc +", NextDisc_Key, 0x84, 0x33);
  addSIRC15Key("Seek +", Unmapped_Key, 0x84, 0x34);
  addSIRC15Key("Seek -", Unmapped_Key, 0x84, 0x35);
  addSIRC15Key("Tape, Reverse", TapeInput_Key, 0x84, 0x37);
  addSIRC15Key("more than 3 sec hold flag", Unmapped_Key, 0x84, 0x44); // Tape
  addSIRC15Key("less than 3 sec hold flag", Unmapped_Key, 0x84, 0x45);
  addSIRC15Key("Source, Tuner-CD-Tape", Input_Key, 0x84, 0x46);
  addSIRC15Key("CD", CDInput_Key, 0x84, 0x48);
  addSIRC15Key("AF/TA", RDS_Key, 0x84, 0x4A);
  addSIRC15Key("FM1/FM2", Unmapped_Key, 0x84, 0x4B);
  addSIRC15Key("AM MW/SW", Unmapped_Key, 0x84, 0x4C);
  addSIRC15Key("Illumination Color", Unmapped_Key, 0x84, 0x70);
  addSIRC15Key("Loudness", Unmapped_Key, 0x84, 0x71);
  addSIRC15Key("TA-vol", Unmapped_Key, 0x84, 0x72);
  addSIRC15Key("D. Bass", EnhancedBass_Key, 0x84, 0x73); // "DSO"
  addSIRC15Key("Beep", Unmapped_Key, 0x84, 0x75);
  addSIRC15Key("CT on/off", Unmapped_Key, 0x84, 0x76);
}


void SonyCarStereo1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("Source", QVariant(Input_Key));
  cb->addItem("Radio Tuner Toggle", QVariant(TunerInput_Key));
  cb->addItem("CD", QVariant(CDInput_Key));
  cb->addItem("Tape", QVariant(TapeInput_Key));
}


SonyCarStereo1a::SonyCarStereo1a(
  unsigned int index)
  : SonyCarStereo1(index)
{
  setKeysetName("Car Stereo 1a");
}


void SonyCarStereo1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  SonyCarStereo1::populateProtocol(guiObject);

  addSIRC15Key("Mode, FM1-FM2-LW-MW-SW", ToggleBand_Key, 0x84, 0x47);
  addSIRC15Key("Mode, FM1-FM2-LW-MW-SW", TunerInput_Key, 0x84, 0x47);
  addSIRC15Key("Enter", Select_Key, 0x84, 0x5C);
}
