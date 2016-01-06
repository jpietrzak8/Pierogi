//
// nec.cpp
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

#include "nec.h"
#include "protocols/necprotocol.h"
#include "protocols/necxprotocol.h"
#include <QComboBox>


NECTV1::NECTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      NEC_Make,
      TV_Panels,
      index)
{
}


void NECTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x18, 8);

  addKey("prog_+", ChannelUp_Key, 0x00, 8);
  addKey("prog_-", ChannelDown_Key, 0x01, 8);
  addKey("TV_+_VOL", VolumeUp_Key, 0x02, 8);
  addKey("TV_-_VOL", VolumeDown_Key, 0x03, 8);
  addKey("-A-", Unmapped_Key, 0x04, 8);
  addKey("-B-", Unmapped_Key, 0x05, 8);
  addKey("-C-", Unmapped_Key, 0x06, 8);
  addKey("-D-", Unmapped_Key, 0x07, 8);
  addKey("power", Power_Key, 0x08, 8);
  addKey("TV_MUTE", Mute_Key, 0x09, 8);
  addKey("TV_TV/VIDEO", Input_Key, 0x0A, 8);
  addKey("Mode", PictureMode_Key, 0x0B, 8);
  addKey("Hue_+", ColorUp_Key, 0x0C, 8);
  addKey("Hue_-", ColorDown_Key, 0x0D, 8);
  addKey("Norm", Unmapped_Key, 0x0E, 8);
//  addKey("TV_CH_CALL", Unmapped_Key, 0x0F, 8);
  addKey("Ok", Select_Key, 0x0F, 8);

  addKey("1", One_Key, 0x10, 8);
  addKey("2", Two_Key, 0x11, 8);
  addKey("3", Three_Key, 0x12, 8);
  addKey("4", Four_Key, 0x13, 8);
  addKey("5", Five_Key, 0x14, 8);
  addKey("6", Six_Key, 0x15, 8);
  addKey("7", Seven_Key, 0x16, 8);
  addKey("8", Eight_Key, 0x17, 8);
  addKey("9", Nine_Key, 0x18, 8);
  addKey("-/--", DoubleDigit_Key, 0x19, 8);
  addKey("0", Zero_Key, 0x1A, 8);
  addKey("shift_-A-", Unmapped_Key, 0x1C, 8);
  addKey("TV_OFF_TIMER", Sleep_Key, 0x1E, 8);
  addKey("TV_ON_TIMER", Timer_Key, 0x1F, 8);

  addKey("Bass_+", BassUp_Key, 0x42, 8);
  addKey("Bass_-", BassDown_Key, 0x43, 8);
  addKey("Treble_+", TrebleUp_Key, 0x44, 8);
  addKey("Treble_-", TrebleDown_Key, 0x45, 8);
  addKey("contr_+", ContrastUp_Key, 0x46, 8);
  addKey("contr_-", ContrastDown_Key, 0x47, 8);
  addKey("Mode_+", Unmapped_Key, 0x48, 8);
  addKey("Mode_-", Unmapped_Key, 0x49, 8);
  addKey("Bright_+", BrightnessUp_Key, 0x4A, 8);
  addKey("Bright_-", BrightnessDown_Key, 0x4B, 8);

  addKey("shift_Menu", Unmapped_Key, 0x5B, 8);
  addKey("shift_|>", Unmapped_Key, 0x5D, 8);
  addKey("menu", Menu_Key, 0x5E, 8);
  addKey("|>", Unmapped_Key, 0x5F, 8);

  addKey("shift_Mode", Unmapped_Key, 0xC3, 8);
}


NECVCR1::NECVCR1(
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      NEC_Make,
      MediaControl_Panels | MediaRecord_Panels,
      index)
{
}


void NECVCR1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x19, 8);

  addKey("CHANNEL_UP", ChannelUp_Key, 0x00, 8);
  addKey("CHANNEL_UP", Up_Key, 0x00, 8);
  addKey("CHANNEL_DOWN", ChannelDown_Key, 0x01, 8);
  addKey("CHANNEL_DOWN", Down_Key, 0x01, 8);
  addKey("StillAdv", StepForward_Key, 0x03, 8);
  addKey("SLOW", Slow_Key, 0x03, 8);
  addKey("STOP", Stop_Key, 0x04, 8);
  addKey("PLAY", Play_Key, 0x05, 8);
  addKey("Rec", Record_Key, 0x06, 8);
  addKey("OPERATE", Power_Key, 0x08, 8);
  addKey("RESET", Reset_Key, 0x09, 8);
  addKey("TV/VCR", Input_Key, 0x0A, 8);
  addKey("COUNT._MEM.", Unmapped_Key, 0x0B, 8);
  addKey("FFWD", FastForward_Key, 0x0C, 8);
  addKey("REWIND", Rewind_Key, 0x0D, 8);
  addKey("PAUSE", Pause_Key, 0x0E, 8);
  addKey("Eject", Eject_Key, 0x0F, 8);

  addKey("1", One_Key, 0x10, 8);
  addKey("2", Two_Key, 0x11, 8);
  addKey("3", Three_Key, 0x12, 8);
  addKey("4", Four_Key, 0x13, 8);
  addKey("5", Five_Key, 0x14, 8);
  addKey("6", Six_Key, 0x15, 8);
  addKey("7", Seven_Key, 0x16, 8);
  addKey("8", Eight_Key, 0x17, 8);
  addKey("9", Nine_Key, 0x18, 8);
  addKey("0", Zero_Key, 0x1A, 8);
  addKey("+_SET/+_SHIFT", Right_Key, 0x1E, 8);

  addKey("TIMER_MODE", Unmapped_Key, 0x82, 8);
  addKey("TIMER_REC", RecordTimed_Key, 0x83, 8);
  addKey("ON_SCREEN", Menu_Key, 0x84, 8);
  addKey("-_SET/-_SHIFT", Left_Key, 0x88, 8);
  addKey("TIMER/COUNTER", Unmapped_Key, 0x8A, 8);

  addKey("DIGITAL_MEM.", Unmapped_Key, 0x90, 8);
  addKey("VPS", Unmapped_Key, 0x9A, 8);
  addKey("STROBE", Unmapped_Key, 0x9A, 8);
  addKey("DIGITAL_NR", NoiseReduction_Key, 0x9C, 8);
}


NECVCR2::NECVCR2(
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 2",
      NEC_Make,
      MediaControl_Panels | MediaRecord_Panels,
      index)
{
}


void NECVCR2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x6E, 8);

  addKey("PLAY", Play_Key, 0x08, 8);
  addKey("STOP", Stop_Key, 0x01, 8);
  addKey("||_P/STILL", Pause_Key, 0x0B, 8);
  addKey(">>_FF", FastForward_Key, 0x03, 8);
  addKey("<<_REW", Rewind_Key, 0x02, 8);
  addKey("O_REC/QSR", Record_Key, 0x09, 8);
  addKey("OPERATE", Power_Key, 0x14, 8);
  addKey("0_PGM_RK", Zero_Key, 0x04, 8);
  addKey("1_CHARACTER", One_Key, 0x05, 8);
  addKey("2_CHARACTER", Two_Key, 0x06, 8);
  addKey("3_CHARACTER", Three_Key, 0x07, 8);
  addKey("4_CURSOR", Four_Key, 0x0C, 8);
  addKey("5_CURSOR", Five_Key, 0x0D, 8);
  addKey("6_CURSOR", Six_Key, 0x0E, 8);
  addKey("7_SIZE", Seven_Key, 0x0F, 8);
  addKey("8_SIZE", Eight_Key, 0x1C, 8);
  addKey("9_SIZE", Nine_Key, 0x1D, 8);
  addKey("+_PGM_RK", Unmapped_Key, 0x18, 8);
  addKey("-_PGM_RK", Unmapped_Key, 0x19, 8);
  addKey("EJECT", Eject_Key, 0x00, 8);
  addKey("CHILD_LOCK", Unmapped_Key, 0x3F, 8);
  addKey("DISPLAY", Info_Key, 0x1E, 8);
  addKey("CLEAR", Clear_Key, 0x1F, 8);
  addKey("MENU", Menu_Key, 0x16, 8);
  addKey("A.TRK", AutoTracking_Key, 0x5F, 8);
  addKey("TU/SC/AV", Unmapped_Key, 0x56, 8);
  addKey("RESET", Reset_Key, 0x4D, 8);
  addKey("CL/CT_EM", Unmapped_Key, 0x4C, 8);
  addKey("+_MFT/SLOW", Unmapped_Key, 0x1A, 8);
  addKey("-_MFT/SLOW", Unmapped_Key, 0x1B, 8);
  addKey("||>_F/ADV", StepForward_Key, 0x10, 8);
  addKey("SP/LP", VHSSpeed_Key, 0x48, 8);
  addKey("TV/VCR", Input_Key, 0x15, 8);
  addKey("A.DUB", Unmapped_Key, 0xC2, 8);
  addKey("VISS", IndexSearch_Key, 0x41, 8);
  addKey("MARK", IndexMark_Key, 0x50, 8);
  addKey("ERASE", IndexErase_Key, 0x42, 8);
  addKey("G-CODE", Unmapped_Key, 0x47, 8);
}


NECVCR3::NECVCR3(
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 3",
      NEC_Make,
      MediaControl_Panels | MediaRecord_Panels,
      index)
{
}


void NECVCR3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x31, 8);

  addKey("CHANNEL_UP", ChannelUp_Key, 0x01, 8);
  addKey("CHANNEL_DOWN", ChannelDown_Key, 0x02, 8);
  addKey("Audio", Audio_Key, 0x03, 8);
  addKey("1", One_Key, 0x04, 8);
  addKey("2", Two_Key, 0x05, 8);
  addKey("3", Three_Key, 0x06, 8);
  addKey("4", Four_Key, 0x07, 8);
  addKey("VTR_V", Unmapped_Key, 0x08, 8);
  addKey("5", Five_Key, 0x0C, 8);
  addKey("6", Six_Key, 0x0D, 8);
  addKey("7", Seven_Key, 0x0E, 8);
  addKey("8", Eight_Key, 0x0F, 8);

  addKey("STOP", Stop_Key, 0x10, 8);
  addKey("PAUSE/STILL", Pause_Key, 0x11, 8);
  addKey("<<_REW", Rewind_Key, 0x12, 8);
  addKey("FF_>>", FastForward_Key, 0x13, 8);
  addKey("PLAY", Play_Key, 0x14, 8);
  addKey("RECORD", Record_Key, 0x15, 8);
  addKey("INDEX", IndexSearch_Key, 0x19, 8);
  addKey("SLOW", Slow_Key, 0x1A, 8);
  addKey("9", Nine_Key, 0x1C, 8);
  addKey("0/AV", Zero_Key, 0x1D, 8);
  addKey("0/AV", Input_Key, 0x1D, 8);
  addKey("SC", Unmapped_Key, 0x1E, 8);
  addKey("ATR", AutoTracking_Key, 0x1F, 8);

  addKey("MEMORY", Unmapped_Key, 0x43, 8);
  addKey("RESET", Reset_Key, 0x44, 8);
  addKey("REMAIN", Unmapped_Key, 0x45, 8);
  addKey("CHECK", Unmapped_Key, 0x46, 8);
  addKey("PLUS", Right_Key, 0x47, 8);
  addKey("MINUS", Left_Key, 0x48, 8);
  addKey("CL", Unmapped_Key, 0x4A, 8);
  addKey("OK", Select_Key, 0x4B, 8);

  addKey("KEY", Unmapped_Key, 0x50, 8); // "LOCK"
  addKey("TV_MONITOR", Unmapped_Key, 0x51, 8);
  addKey("MARK", IndexMark_Key, 0x54, 8);
  addKey("ERASE", IndexErase_Key, 0x55, 8);
  addKey("OPERATE", Power_Key, 0x5B, 8);
  addKey("SP/LP", VHSSpeed_Key, 0x5E, 8);
}


NECDVD1::NECDVD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      NEC_Make,
      MediaControl_Panels,
      index)
{
}


void NECDVD1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECXProtocol(guiObject, index, true);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x2D2D, 16);

  addKey("Power", Power_Key, 0x30, 8);
  addKey("Eject", Eject_Key, 0x36, 8);
  addKey("Menu", Menu_Key, 0x4B, 8);
  addKey("Title", DiscTitle_Key, 0x45, 8);
  addKey("Setup", Menu_Key, 0x56, 8);
  addKey("Return", Exit_Key, 0x45, 8);
  addKey("Left", Left_Key, 0x59, 8);
  addKey("Up", Up_Key, 0x47, 8);
  addKey("Right", Right_Key, 0x5A, 8);
  addKey("Down", Down_Key, 0x48, 8);
  addKey("Select", Select_Key, 0x58, 8);
  addKey("Display", Info_Key, 0x3A, 8);
  addKey("Zoom", Zoom_Key, 0x64, 8);
  addKey("Freeze_Back", StepBack_Key, 0x60, 8);
  addKey("Freeze", StepForward_Key, 0x37, 8);
  addKey("Pause", Pause_Key, 0x38, 8);
  addKey("Rewind", Rewind_Key, 0x35, 8);
  addKey("Play", Play_Key, 0x31, 8);
  addKey("Fast_Forward", FastForward_Key, 0x34, 8);
  addKey("Stop", Stop_Key, 0x39, 8);
  addKey("1", One_Key, 0x3B, 8);
  addKey("2", Two_Key, 0x3C, 8);
  addKey("3", Three_Key, 0x3D, 8);
  addKey("4", Four_Key, 0x3E, 8);
  addKey("5", Five_Key, 0x3F, 8);
  addKey("6", Six_Key, 0x40, 8);
  addKey("7", Seven_Key, 0x41, 8);
  addKey("8", Eight_Key, 0x42, 8);
  addKey("9", Nine_Key, 0x43, 8);
  addKey("0", Zero_Key, 0x44, 8);
  addKey("Program", Program_Key, 0x57, 8);
  addKey("Clear", Clear_Key, 0x46, 8);
  addKey("Audio", Audio_Key, 0x4F, 8);
  addKey("Subtitle", Captions_Key, 0x50, 8);
  addKey("Angle", Angle_Key, 0x4C, 8);
  addKey("Random", Random_Key, 0x51, 8);
  addKey("Marker", IndexMark_Key, 0x61, 8);
  addKey("Search", IndexSearch_Key, 0x62, 8);
  addKey("Repeat", Repeat_Key, 0x53, 8);
  addKey("A-B", RepeatAB_Key, 0x55, 8);
}


NECProjector1::NECProjector1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Projector Keyset 1",
      NEC_Make,
      MediaControl_Panels,
      index)
{
}


void NECProjector1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x18, 8);

  addKey("R", Unmapped_Key, 0x00, 8);
  addKey("G", Unmapped_Key, 0x01, 8);
  addKey("B", Unmapped_Key, 0x02, 8);
  addKey("OPERATE", Power_Key, 0x06, 8);
  addKey("DISPLAY", Unmapped_Key, 0x07, 8);
  addKey("POWER_ON", PowerOn_Key, 0x08, 8);
  addKey("POWER_ON", Power_Key, 0x08, 8);
  addKey("END", Unmapped_Key, 0x09, 8);
  addKey("POINT", Unmapped_Key, 0x0A, 8);
  addKey("TEST", Unmapped_Key, 0x0B, 8);
  addKey("KELVIN", Unmapped_Key, 0x0D, 8);
  addKey("COARSE/FINE", Unmapped_Key, 0x0F, 8);

  addKey("STORE", Unmapped_Key, 0x12, 8);
  addKey("HELP", Unmapped_Key, 0x13, 8);
  addKey("POWER_OFF", PowerOff_Key, 0x14, 8);
  addKey("STATIC", Unmapped_Key, 0x15, 8);
  addKey("ENTER", Select_Key, 0x17, 8);
  addKey("1", One_Key, 0x18, 8);
  addKey("2", Two_Key, 0x19, 8);
  addKey("3", Three_Key, 0x1A, 8);
  addKey("4", Four_Key, 0x1B, 8);
  addKey("5", Five_Key, 0x1C, 8);
  addKey("6", Six_Key, 0x1D, 8);
  addKey("7", Seven_Key, 0x1E, 8);
  addKey("8", Eight_Key, 0x1F, 8);

  addKey("9", Nine_Key, 0x40, 8);
  addKey("10", Zero_Key, 0x41, 8);
  addKey("ADJUST", Unmapped_Key, 0x42, 8);
  addKey("NORMAL", Unmapped_Key, 0x43, 8);
  addKey("SOUND_FUNC", SoundMode_Key, 0x44, 8);
  addKey("SOUND_MUTE", Mute_Key, 0x45, 8);
  addKey("PIC_FUNC", PictureMode_Key, 0x46, 8);
  addKey("PIC_MUTE", PictureMute_Key, 0x47, 8);
  addKey("POSITION", Unmapped_Key, 0x4B, 8);
  addKey("INPUT_LIST", Unmapped_Key, 0x4D, 8);
  addKey("FOCUS", Focus_Key, 0x4E, 8);
  addKey("INFO", Info_Key, 0x4F, 8);

  addKey("TILT", Unmapped_Key, 0x50, 8);
  addKey("BOW", Unmapped_Key, 0x52, 8);
  addKey("AMPLIT", Unmapped_Key, 0x54, 8);
  addKey("LINEAR", Unmapped_Key, 0x56, 8);
  addKey("KEYSTN", Keystone_Key, 0x58, 8);
  addKey("PINCUS", Unmapped_Key, 0x5A, 8);
  addKey("NORMAL", Unmapped_Key, 0x5B, 8);
  addKey("UP", Up_Key, 0x5C, 8);
  addKey("DOWN", Down_Key, 0x5D, 8);
  addKey("RIGHT", Right_Key, 0x5E, 8);
  addKey("LEFT", Left_Key, 0x5F, 8);
}


NECProjector2::NECProjector2(
  unsigned int index)
  : PIRKeysetMetaData(
      "Projector Keyset 2",
      NEC_Make,
      MediaControl_Panels,
      index)
{
}


void NECProjector2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0xE918, 16);

  addKey("VIDEO", VideoInput_Key, 0x03, 8);
  addKey("RGB", ComponentInput_Key, 0x04, 8); // "computer_1"
  addKey("RGB_2", Component2Input_Key, 0x05, 8); // "computer_2"
  addKey("auto_adj", Unmapped_Key, 0x06, 8);
  addKey("SELECT_PICTURE", Unmapped_Key, 0x07, 8);
  addKey("POWER_ON", Power_Key, 0x08, 8);
  addKey("POWER_ON", PowerOn_Key, 0x08, 8);
  addKey("ZOOM+", Unmapped_Key, 0x09, 8);
  addKey("ZOOM-", Unmapped_Key, 0x0A, 8);
  addKey("FOCUS+", Unmapped_Key, 0x0B, 8);
  addKey("FOCUS-", Unmapped_Key, 0x0C, 8);
  addKey("picture", PictureMode_Key, 0x0D, 8);

  addKey("aspect", AspectRatio_Key, 0x10, 8);
  addKey("MUTE_OFF", Unmapped_Key, 0x11, 8);
  addKey("POWER_OFF", PowerOff_Key, 0x14, 8);
  addKey("Lamp_Mode", Unmapped_Key, 0x16, 8);
  addKey("enter", Select_Key, 0x17, 8);

  addKey("exit", Exit_Key, 0x25, 8);
  addKey("page_up", PageUp_Key, 0x2A, 8);
  addKey("page_down", PageDown_Key, 0x2B, 8);
  addKey("l_click", Unmapped_Key, 0x2C, 8);
  addKey("r_click", Unmapped_Key, 0x2D, 8);

  addKey("MENU", Menu_Key, 0x46, 8);
  addKey("PIC-MUTE", PictureMute_Key, 0x47, 8);
  addKey("VOLUME+", VolumeUp_Key, 0x48, 8);
  addKey("VOLUME-", VolumeDown_Key, 0x49, 8);
  addKey("FREEZE", Pause_Key, 0x4C, 8);
  addKey("help", Unmapped_Key, 0x4E, 8);

  addKey("DISPLAY_+", Unmapped_Key, 0x5C, 8);
  addKey("DISPLAY_-", Unmapped_Key, 0x5D, 8);

  addKey("2X/4X", Unmapped_Key, 0x87, 8);
  addKey("MAGNIFY_REDUCE+", Unmapped_Key, 0x89, 8);
  addKey("MAGNIFY_REDUCE-", Unmapped_Key, 0x8A, 8);
//  addKey("FREEZE", Pause_Key, 0x91, 8);

  addKey("up", Up_Key, 0xB8, 8);
  addKey("down", Down_Key, 0xBC, 8);
  addKey("left", Left_Key, 0xBE, 8);
  addKey("right", Right_Key, 0xBA, 8);

  addKey("S-VIDEO", SVideoInput_Key, 0xC6, 8);
}


void NECProjector2::populateInputList(
  QComboBox *cb) const
{
  cb->clear();

  cb->addItem("Video", QVariant(VideoInput_Key));
  cb->addItem("RGB", QVariant(ComponentInput_Key));
  cb->addItem("RGB 2", QVariant(Component2Input_Key));
  cb->addItem("S-Video", QVariant(SVideoInput_Key));
}


NECProjector3::NECProjector3(
  unsigned int index)
  : PIRKeysetMetaData(
      "Projector Keyset 3",
      NEC_Make,
      MediaControl_Panels,
      index)
{
}


void NECProjector3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already published.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0xF718, 16);

  // These commands are almost the same as keyset 2, but have a few
  // differences:
  addKey("R", Unmapped_Key, 0x00, 8);
  addKey("G", Unmapped_Key, 0x01, 8);
  addKey("B", Unmapped_Key, 0x02, 8);
  addKey("OPERATE", Menu_Key, 0x06, 8);
  addKey("DISPLAY", Unmapped_Key, 0x07, 8);
  addKey("POWER_ON", Power_Key, 0x08, 8);
  addKey("POWER_ON", PowerOn_Key, 0x08, 8);
  addKey("END", Unmapped_Key, 0x09, 8);
  addKey("POINT", Unmapped_Key, 0x0A, 8);
  addKey("TEST", Unmapped_Key, 0x0B, 8);
  addKey("KELVIN", Unmapped_Key, 0x0D, 8);

  addKey("STORE", Unmapped_Key, 0x12, 8);
  addKey("HELP", Unmapped_Key, 0x13, 8);
  addKey("POWER_OFF", PowerOff_Key, 0x14, 8);
  addKey("STATIC", Unmapped_Key, 0x15, 8);
  addKey("ENTER", Select_Key, 0x17, 8);
  addKey("1", One_Key, 0x18, 8);
  addKey("2", Two_Key, 0x19, 8);
  addKey("3", Three_Key, 0x1A, 8);
  addKey("4", Four_Key, 0x1B, 8);
  addKey("5", Five_Key, 0x1C, 8);
  addKey("6", Six_Key, 0x1D, 8);
  addKey("7", Seven_Key, 0x1E, 8);
  addKey("8", Eight_Key, 0x1F, 8);

  addKey("9", Nine_Key, 0x40, 8);
  addKey("10", DoubleDigit_Key, 0x41, 8);
  addKey("ADJUST", Unmapped_Key, 0x42, 8);
  addKey("NORMAL", Unmapped_Key, 0x43, 8);
  addKey("SOUND_FUNC", SoundMode_Key, 0x44, 8);
  addKey("SOUND_MUTE", Mute_Key, 0x45, 8);
  addKey("PIC_FUNC", PictureMode_Key, 0x46, 8);
  addKey("PIC_MUTE", PictureMute_Key, 0x47, 8);
  addKey("POSITION", Unmapped_Key, 0x4B, 8);
  addKey("INPUT_LIST", Unmapped_Key, 0x4D, 8);
  addKey("FOCUS", Unmapped_Key, 0x4E, 8);
  addKey("INFO", Info_Key, 0x4F, 8);

  addKey("TILT", Unmapped_Key, 0x50, 8);
  addKey("PHASE", Unmapped_Key, 0x51, 8);
  addKey("BOW", Unmapped_Key, 0x52, 8);
  addKey("AMPLIT", Unmapped_Key, 0x54, 8);
  addKey("LINEAR", Unmapped_Key, 0x56, 8);
  addKey("KEYSTN", Unmapped_Key, 0x58, 8);
  addKey("PINCUS", Unmapped_Key, 0x5A, 8);
  addKey("NORMAL", Unmapped_Key, 0x5B, 8);
  addKey("UP", Up_Key, 0x5C, 8);
  addKey("DOWN", Down_Key, 0x5D, 8);
  addKey("RIGHT", Right_Key, 0x5E, 8);
  addKey("LEFT", Left_Key, 0x5F, 8);
}
