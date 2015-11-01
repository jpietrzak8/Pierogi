//
// sanyo.cpp
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

#include "sanyo.h"

#include "protocols/necprotocol.h"
#include <QComboBox>

SanyoVCR1::SanyoVCR1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD/VCR Keyset 1",
      Sanyo_Make,
      MediaControl_Panels | MediaRecord_Panels,
      index)
{
  addControlledDevice(Sanyo_Make, "DVW-5000", VCR_Device);
  addControlledDevice(Sanyo_Make, "DVW-5000", DVD_Device);
}


void SanyoVCR1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

//  setPreData(0x8C73, 16);
  setPreData(0x31, 8);

  addKey("Ch Up", ChannelUp_Key, 0x01, 8);
  addKey("Ch Down", ChannelDown_Key, 0x02, 8);
  addKey("Audio", Audio_Key, 0x03, 8);
  addKey("1", One_Key, 0x04, 8);
  addKey("2", Two_Key, 0x05, 8);
  addKey("3", Three_Key, 0x06, 8);
  addKey("4", Four_Key, 0x07, 8);
  addKey("TV/VCR", Input_Key, 0x08, 8);
  addKey("x2", PlayX2_Key, 0x0B, 8);
  addKey("5", Five_Key, 0x0C, 8);
  addKey("6", Six_Key, 0x0D, 8);
  addKey("7", Seven_Key, 0x0E, 8);
  addKey("8", Eight_Key, 0x0F, 8);
  addKey("Stop", Stop_Key, 0x10, 8);
  addKey("Pause", Pause_Key, 0x11, 8);
  addKey("Rew", Rewind_Key, 0x12, 8);
  addKey("FF", FastForward_Key, 0x13, 8);
  addKey("Play", Play_Key, 0x14, 8);
  addKey("Rec", Record_Key, 0x15, 8);
  addKey("Index", IndexSearch_Key, 0x19, 8);
  addKey("Slow", Slow_Key, 0x1A, 8);
  addKey("+100", PlusOneHundred_Key, 0x1B, 8);
  addKey("9", Nine_Key, 0x1C, 8);
  addKey("0", Zero_Key, 0x1D, 8);
  addKey("Input", Unmapped_Key, 0x1E, 8);  // need a subclass for this?
  addKey("ATR", AutoTracking_Key, 0x1F, 8);
  addKey("Memory", Memory_Key, 0x43, 8); // "->0<-"
  addKey("Reset", Reset_Key, 0x44, 8);
  addKey("PROG", Program_Key, 0x46, 8);
  addKey("Cancel", Clear_Key, 0x4A, 8);
  addKey("Ok", Select_Key, 0x4B, 8);
  addKey("Display", Info_Key, 0x4C, 8);
  addKey("VPS", RecordPDC_Key, 0x4F, 8); // "vps/pdc", "dpc"
  addKey("Monitor", Unmapped_Key, 0x51, 8);
  addKey("Clock", Clock_Key, 0x56, 8);
  addKey("Power", Power_Key, 0x5B, 8);
  addKey("SP/LP", VHSSpeed_Key, 0x5E, 8);
  addKey("ShowView", Unmapped_Key, 0x8C, 8); // vhsplus+, etc.
  addKey("Right", Right_Key, 0x94, 8);
  addKey("Left", Left_Key, 0x95, 8);
  addKey("Down", Down_Key, 0x96, 8);
  addKey("Up", Up_Key, 0x97, 8);
  addKey("Preset", Unmapped_Key, 0x9E, 8);
  addKey("Menu", Menu_Key, 0xCA, 8);
  addKey("BLANK", Unmapped_Key, 0xD0, 8);
}


SanyoDVD1::SanyoDVD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Sanyo_Make,
      MediaControl_Panels,
      index)
{
  addControlledDevice(Sanyo_Make, "DVD-SL25", DVD_Device);
}


void SanyoDVD1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

//  setPreData(0x3C23, 16);
  setPreData(0xC43C, 16);

  addKey("On", Power_Key, 0x00, 8);
  addKey("OpenClose", Eject_Key, 0x01, 8);
  addKey("Setup", Menu_Key, 0x02, 8);
  addKey("OnScreen", Unmapped_Key, 0x03, 8);
  addKey("SubtitleChange", Unmapped_Key, 0x05, 8);
  addKey("TopMenu", DiscTitle_Key, 0x06, 8);
  addKey("Menu", DiscMenu_Key, 0x07, 8);
  addKey("Angle", Angle_Key, 0x08, 8);
  addKey("AngleReplay", Unmapped_Key, 0x09, 8);
  addKey("Audio", Audio_Key, 0x0A, 8);
  addKey("Up", Up_Key, 0x0B, 8);
  addKey("Down", Down_Key, 0x0C, 8);
  addKey("Left", Left_Key, 0x0D, 8);
  addKey("Right", Right_Key, 0x0E, 8);
  addKey("Enter", Select_Key, 0x0F, 8);
  addKey("Return", Exit_Key, 0x10, 8);
  addKey("1", One_Key, 0x11, 8);
  addKey("2", Two_Key, 0x12, 8);
  addKey("3", Three_Key, 0x13, 8);
  addKey("4", Four_Key, 0x14, 8);
  addKey("5", Five_Key, 0x15, 8);
  addKey("6", Six_Key, 0x16, 8);
  addKey("7", Seven_Key, 0x17, 8);
  addKey("8", Eight_Key, 0x18, 8);
  addKey("9", Nine_Key, 0x19, 8);
  addKey("0", Zero_Key, 0x1A, 8);
  addKey("Clear", Clear_Key, 0x1C, 8);
  addKey("Stop", Stop_Key, 0x1E, 8);
  addKey("Play", Play_Key, 0x1F, 8);
  addKey("PauseStep", Pause_Key, 0x20, 8);
  addKey("Next", Next_Key, 0x21, 8);
  addKey("Prev", Previous_Key, 0x22, 8);
  addKey("Fwd", FastForward_Key, 0x23, 8);
  addKey("Rev", Rewind_Key, 0x26, 8);
  addKey("FwdSlow", StepForward_Key, 0x29, 8);
  addKey("RevSlow", StepBack_Key, 0x2C, 8);
  addKey("LastMemo", Unmapped_Key, 0x2F, 8);
  addKey("Repeat", Repeat_Key, 0x35, 8);
  addKey("ABRepeat", RepeatAB_Key, 0x36, 8);
  addKey("SearchMode", Unmapped_Key, 0x38, 8);
  addKey("ProgramRandom", Random_Key, 0x39, 8);
  addKey("PictureMode", PictureMode_Key, 0x3A, 8);
  addKey("Zoom", Zoom_Key, 0x3B, 8);
  addKey("SubtitleOnOff", Captions_Key, 0x4A, 8);
}


SanyoTV1::SanyoTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Sanyo_Make,
      TV_Panels,
      index)
{
}


void SanyoTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x38, 8);

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
  addKey("Channel Up", ChannelUp_Key, 0x0A, 8);
  addKey("Channel Down", ChannelDown_Key, 0x0B, 8);
  addKey("Display", Info_Key, 0x0C, 8);
  addKey("Sleep", Sleep_Key, 0x0D, 8);
  addKey("Volume Up", VolumeUp_Key, 0x0E, 8);
  addKey("Volume Down", VolumeDown_Key, 0x0F, 8);
  addKey("Closed Captions", Captions_Key, 0x11, 8);
  addKey("Power", Power_Key, 0x12, 8);
  addKey("Input", Input_Key, 0x13, 8); // "TV/AV"
  addKey("Surround Toggle", Surround_Key, 0x14, 8);
  addKey("Enter", Enter_Key, 0x15, 8); // odd
  addKey("DASH", Dash_Key, 0x15, 8);
  addKey("Menu", Menu_Key, 0x17, 8); // "setup"
  addKey("Mute", Mute_Key, 0x18, 8);
  addKey("Recall", PrevChannel_Key, 0x19, 8);
  addKey("audio", Audio_Key, 0x1A, 8); // My Sanyo has this mapping
//  addKey("audio", SoundMode_Key, 0x1A, 8); // Other Sanyos have this one?
//  addKey("CC", Captions_Key, 0x1B, 8); // ?
  addKey("reset", Reset_Key, 0x1C, 8); // picture adjustment
  addKey("select", Select_Key, 0x1D, 8);
  addKey("right arrow", Right_Key, 0x1E, 8);
  addKey("left arrow", Left_Key, 0x1F, 8);
  addKey("V-guide menu", Guide_Key, 0x4C, 8);
  addKey("up arrow", Up_Key, 0x4E, 8);
  addKey("down arrow", Down_Key, 0x4F, 8);
  addKey("exit", Exit_Key, 0x53, 8);
//  addKey("enter", Select_Key, 0x54, 8);
  addKey("tuner", ADTunerSwap_Key, 0x55, 8); // "Tuner Toggle (analog-digital)"
//  addKey("+100", PlusOneHundred_Key, 0x55, 8);
  addKey("pix shape", AspectRatio_Key, 0x57, 8);
  addKey("pip up", Unmapped_Key, 0x59, 8);
  addKey("pip down", Unmapped_Key, 0x5A, 8);
  addKey("PIP", PIP_Key, 0x5B, 8);
  addKey("Swap", PIPSwap_Key, 0x5D, 8);
  addKey("freeze", PIPPause_Key, 0x5E, 8);
  addKey("DISCRETE OFF", PowerOff_Key, 0x76, 8);
  addKey("Volume Cycle (Max/Min/Normal)", Unmapped_Key, 0x80, 8);
  addKey("puts 'A' on the screen", Unmapped_Key, 0x81, 8);
  addKey("puts 'P' on the screen", Unmapped_Key, 0x82, 8);
  addKey("Scan Velocity Cycle (Hi/Lo/Off)", Unmapped_Key, 0x87, 8);
  addKey("Color Cycle", ColorUp_Key, 0x88, 8);
  addKey("Tint Cycle", Unmapped_Key, 0x89, 8);
  addKey("Contrast Cycle", ContrastUp_Key, 0x8A, 8);
  addKey("Brightness Cycle", BrightnessUp_Key, 0x8B, 8);
  addKey("Sharpness Cycle", Unmapped_Key, 0x8C, 8);
  addKey("bass", BassUp_Key, 0x8E, 8);
  addKey("Treble", TrebleUp_Key, 0x8F, 8);
  addKey("Service Menu", ServiceMenu_Key, 0x91, 8);
  addKey("Crude Info", Unmapped_Key, 0x96, 8);
  addKey("Video 1", ComponentInput_Key, 0x97, 8);
  addKey("Color Enhancer Cycle (Normal/Warm/Cool)", Unmapped_Key, 0x98, 8);
  addKey("Video 3", MDInput_Key, 0x99, 8); // hack
  addKey("Video 2", Component2Input_Key, 0x9C, 8);
  addKey("HDMI 1", HDMIInput_Key, 0x9D, 8); // "Speaker Toggle"
  addKey("HDMI 2", HDMI2Input_Key, 0x9E, 8);
  addKey("puts 'R32 B26' on the screen.  MENU cancels.", Unmapped_Key, 0x9F, 8);
  addKey("Reset?", FactoryReset_Key, 0xC0, 8);
  addKey("Clear?", Unmapped_Key, 0xC1, 8); // System Info
  addKey("DISPLAY PARAMETERS", Unmapped_Key, 0xC2, 8);
  addKey("Self Test", Unmapped_Key, 0xC3, 8);

//  addKey("Black screen (recoverable with 0x9F then MENU)", Unmapped_Key, 0x9E, 8);
}


void SanyoTV1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("Input Toggle", QVariant(Input_Key));
  cb->addItem("A/D Tuner Toggle", QVariant(ADTunerSwap_Key));
  cb->addItem("Video 1", QVariant(ComponentInput_Key));
  cb->addItem("Video 2", QVariant(Component2Input_Key));
  cb->addItem("Video 3", QVariant(MDInput_Key));
  cb->addItem("HDMI 1", QVariant(HDMIInput_Key));
  cb->addItem("HDMI 2", QVariant(HDMI2Input_Key));
}


SanyoTV1b::SanyoTV1b(
  unsigned int index)
  : SanyoTV1(index)
{
  setKeysetName("TV Keyset 1b");
}


void SanyoTV1b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  SanyoTV1::populateProtocol(guiObject);

  addKey("image", PictureMode_Key, 0x11, 8);
  addKey("TV", Unmapped_Key, 0x14, 8); // "tv/video"?
  addKey("Enter", Select_Key, 0x1A, 8); // "F/OK"
}


SanyoTV1d::SanyoTV1d(
  unsigned int index)
  : SanyoTV1(index)
{
  setKeysetName("TV Keyset 1d");

  addControlledDevice(Sanyo_Make, "CTP-6791P", TV_Device);
}


void SanyoTV1d::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  SanyoTV1::populateProtocol(guiObject);

  addKey("audio_mode", SoundMode_Key, 0x1C, 8); // "auto"
  addKey("Digicon", PictureMode_Key, 0x1D, 8);
  addKey("Menu +", Right_Key, 0x1E, 8);
  addKey("Menu -", Left_Key, 0x1F, 8);
}


SanyoTV2::SanyoTV2(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 2",
      Sanyo_Make,
      TV_Panels,
      index)
{
  addControlledDevice(Sanyo_Make, "28LN4-C", TV_Device);
  addControlledDevice(Sanyo_Make, "28CN7F", TV_Device);
  addControlledDevice(Sanyo_Make, "C21EF44", TV_Device);
  addControlledDevice(Sanyo_Make, "C25EG64", TV_Device);
  addControlledDevice(Sanyo_Make, "C28EH64", TV_Device);
//  addControlledDevice(Sanyo_Make, "CED3011PV", TV_Device);
//  addControlledDevice(Sanyo_Make, "CEM6011PV", TV_Device);
//  addControlledDevice(Sanyo_Make, "DP32746", TV_Device);
}


// Note: Same device ID as keyset 1, but very different commands!!!
void SanyoTV2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x38, 8);

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
  addKey("-/--", DoubleDigit_Key, 0x0A, 8);
  addKey("CS", Unmapped_Key, 0x0B, 8); // 2-
  addKey("P+", ChannelUp_Key, 0x0C, 8);
  addKey("UP", Up_Key, 0x0C, 8);
  addKey("P-", ChannelDown_Key, 0x0D, 8);
  addKey("DOWN", Down_Key, 0x0D, 8);
  addKey("contrast_>", ContrastUp_Key, 0x0E, 8);
  addKey("contrast_<", ContrastDown_Key, 0x0F, 8);
  addKey("prg_scan", Scan_Key, 0x10, 8);
  addKey("NORMAL", Unmapped_Key, 0x11, 8); // "SYMBOL_2"
  addKey("tuning_>", ChannelUp_Key, 0x12, 8);
  addKey("tuning_<", ChannelDown_Key, 0x13, 8);
  addKey("tv/av", Input_Key, 0x14, 8);
  addKey("MUTE", Mute_Key, 0x15, 8);
  addKey("VOL+", VolumeUp_Key, 0x16, 8);
  addKey("RIGHT", Right_Key, 0x16, 8);
  addKey("VOL-", VolumeDown_Key, 0x17, 8);
  addKey("LEFT", Left_Key, 0x17, 8);
  addKey("OSD", Info_Key, 0x18, 8); // "SYMBOL_1", "status"
  addKey("RECALL/TEXT_REVEAL", TeletextReveal_Key, 0x18, 8);
  addKey("clear_screen", Unmapped_Key, 0x18, 8);
  addKey("CLOCK", Sleep_Key, 0x19, 8); // "SLEEP/ON-TIMER/TEXT_CANCEL"
//  addKey("ok", Select_Key, 0x1A, 8);
  addKey("colour_>", ColorUp_Key, 0x1A, 8);
  addKey("colour_<", ColorDown_Key, 0x1B, 8);
  addKey("POWER", Power_Key, 0x1C, 8);
  addKey("P--P", PrevChannel_Key, 0x1D, 8); // "ALTERNATE"
  addKey("bright_>", BrightnessUp_Key, 0x1E, 8);
  addKey("bright_<", BrightnessDown_Key, 0x1F, 8);
  addKey("A-B", Unmapped_Key, 0x40, 8); //?
  addKey("WIDE", Unmapped_Key, 0x43, 8);
  addKey("TXT/TV", Teletext_Key, 0x46, 8); // teletext
  addKey("Red", Red_Key, 0x49, 8); // surround
  addKey("Green", Green_Key, 0x4A, 8);
  addKey("Yellow", Yellow_Key, 0x4B, 8); // bass
  addKey("Blue", Blue_Key, 0x4C, 8); // time
  addKey("TEXT_HOLD", TeletextHold_Key, 0x4E, 8); // "SHRINK"
  addKey("TEXT_INDEX-PAGE", TeletextIndex_Key, 0x51, 8);
  addKey("MENU", Menu_Key, 0x51, 8);
  addKey("TEXT_SIZE", TeletextSize_Key, 0x56, 8); // "EXPAND"
  addKey("AV1", CompositeInput_Key, 0xD8, 8);
}


void SanyoTV2::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("Input Toggle", QVariant(Input_Key));
  cb->addItem("AV 1", QVariant(CompositeInput_Key));
}


SanyoProjector1::SanyoProjector1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Projector Keyset 1",
      Sanyo_Make,
      MediaControl_Panels,
      index)
{
  addControlledDevice(Sanyo_Make, "PLV-70", Other_Device);
}


void SanyoProjector1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  // Need to set the protocol to use 16-bit predata, for child keysets:
  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0xCF30, 16);

  addKey("Power", Power_Key, 0x00, 8); //"ONOFF0"
  addKey("D.Zoom +", Unmapped_Key, 0x01, 8);
  addKey("D.ZOOM -", Unmapped_Key, 0x02, 8);
  addKey("Input", Input_Key, 0x05, 8);
  addKey("VOLUME +", VolumeUp_Key, 0x09, 8);
  addKey("VOLUME -", VolumeDown_Key, 0x0A, 8);
  addKey("MUTE", Mute_Key, 0x0B, 8);
  addKey("Image (Adj.)", PictureMode_Key, 0x0C, 8);
  addKey("Image (z1)", Unmapped_Key, 0x0E, 8); // put into different keyset?
  addKey("SELECT", Select_Key, 0x0F, 8);
  addKey("INFORMATION", Info_Key, 0x16, 8);
  addKey("AUTO SET", Unmapped_Key, 0x17, 8);
  addKey("LAMP CONTROL", Unmapped_Key, 0x18, 8); // "(Lamp Mode)"
  addKey("MENU", Menu_Key, 0x1C, 8);
  addKey("RIGHT", Right_Key, 0x1D, 8);
  addKey("LEFT", Left_Key, 0x1E, 8);
  addKey("Standard (Image)", Unmapped_Key, 0x1F, 8);
  addKey("HDMI", HDMIInput_Key, 0x37, 8);
  addKey("COMPUTER 1", PCInput_Key, 0x38, 8);
  addKey("COMPUTER 2", LDInput_Key, 0x39, 8); // hack
  addKey("Input 3", PhonoInput_Key, 0x3A, 8); // hack
  addKey("AUTO", Unmapped_Key, 0x3C, 8); // "My-P (My Picture)"
  addKey("COMPOSITE", CompositeInput_Key, 0x3D, 8); // "VIDEO"
  addKey("S-VIDEO", SVideoInput_Key, 0x3E, 8); // "S-VIDEO"
  addKey("Lens Shift", Unmapped_Key, 0x40, 8);
  addKey("FREEZE", Pause_Key, 0x43, 8);
  addKey("Zoom -", Unmapped_Key, 0x46, 8);
  addKey("Zoom +", Unmapped_Key, 0x47, 8);
  addKey("Focus +", Unmapped_Key, 0x4A, 8);
  addKey("Focus -", Unmapped_Key, 0x4B, 8);
  addKey("IMAGE_1", One_Key, 0x50, 8);
  addKey("IMAGE_2", Two_Key, 0x51, 8);
  addKey("IMAGE_3", Three_Key, 0x56, 8);
  addKey("IMAGE_4", Four_Key, 0x57, 8);
  addKey("P-Im (Image, Preset)", Unmapped_Key, 0x58, 8);
  addKey("KEYSTONE", Unmapped_Key, 0x5B, 8);
  addKey("SCREEN", AspectRatio_Key, 0x82, 8); // "ASPECT"
  addKey("COMPONENT", ComponentInput_Key, 0x83, 8);
  addKey("AUTO_PC_ADJ", Unmapped_Key, 0x89, 8);
  addKey("P-TIMER", Unmapped_Key, 0x8A, 8);
  addKey("NOSHOW", Unmapped_Key, 0x8B, 8); // "AV MUTE"
  addKey("UP", Up_Key, 0x8C, 8);
  addKey("DOWN", Down_Key, 0x8D, 8);
  addKey("KEYSTONE_UP", Unmapped_Key, 0x8E, 8);
  addKey("KEYSTONE_DOWN", Unmapped_Key, 0x8F, 8);
  addKey("Power On", Green_Key, 0xA0, 8);
  addKey("Power Off", Red_Key, 0xA1, 8);
}


void SanyoProjector1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("Input", QVariant(Input_Key));
  cb->addItem("HDMI", QVariant(HDMIInput_Key));
  cb->addItem("Computer 1", QVariant(PCInput_Key));
  cb->addItem("Computer 2", QVariant(LDInput_Key));
  cb->addItem("Input 3", QVariant(PhonoInput_Key));
  cb->addItem("Composite", QVariant(CompositeInput_Key));
  cb->addItem("S-Video", QVariant(SVideoInput_Key));
}


SanyoProjector1a::SanyoProjector1a(
  unsigned int index)
  : SanyoProjector1(index)
{
  addControlledDevice(Sanyo_Make, "PLV-Z1", Other_Device);

  setKeysetName("Projector Keyset 1a");
}


void SanyoProjector1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  SanyoProjector1::populateProtocol(guiObject);

  setPreData(0xCE30, 16);
}


SanyoProjector1b::SanyoProjector1b(
  unsigned int index)
  : SanyoProjector1(index)
{
  addControlledDevice(Sanyo_Make, "PLV-Z2", Other_Device);

  setKeysetName("Projector Keyset 1b");
}


void SanyoProjector1b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  SanyoProjector1::populateProtocol(guiObject);

  setPreData(0x0033, 16);
}


SanyoProjector1c::SanyoProjector1c(
  unsigned int index)
  : SanyoProjector1(index)
{
  addControlledDevice(Sanyo_Make, "PLV-Z2 (code 2)", Other_Device);

  setKeysetName("Projector Keyset 1c");
}


void  SanyoProjector1c::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  SanyoProjector1::populateProtocol(guiObject);

  setPreData(0x1133, 16);
}
