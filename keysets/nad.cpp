//
// nad.cpp
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

#include "nad.h"
#include "protocols/necprotocol.h"
#include "protocols/necxprotocol.h"
#include "protocols/sircprotocol.h"
#include <QComboBox>


NADAudio1::NADAudio1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Receiver Component 1",
      NAD_Make,
      Receiver_Panels | MediaRecord_Panels,
      index)
{
}


void NADAudio1::populateProtocol(
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

  setPreData(0x7C87, 16);

  addKey("CD-Play", Play_Key, 0x01, 8);
  addKey("CD-Stop", Stop_Key, 0x02, 8);
  addKey("CD-Previous", Previous_Key, 0x05, 8);
  addKey("CD-Next", Next_Key, 0x06, 8);
  addKey("disp-info", Info_Key, 0x08, 8);
  addKey("rpt", Repeat_Key, 0x0A, 8);

  addKey("CD-Disc", NextDisc_Key, 0x17, 8);
  addKey("SLEEP", Sleep_Key, 0x20, 8);
  addKey("Tuner-Bank", Unmapped_Key, 0x24, 8);
  addKey("Power-On", PowerOn_Key, 0x25, 8);
  addKey("RCVR_LEVEL", Unmapped_Key, 0x2B, 8);
  addKey("EXT._5.1", Unmapped_Key, 0x2E, 8);
  addKey("RCVR_DYN.R", NoiseReduction_Key, 0x2F, 8);

  addKey("VIDEO_4", CompositeInput_Key, 0x30, 8);
  addKey("VIDEO_5", Composite2Input_Key, 0x31, 8);
  addKey("RCVR_TUNE_MODE", Mode_Key, 0x33, 8);
  addKey("CD-Pause", Pause_Key, 0x4A, 8);

  addKey("TapeA-Stop", Unmapped_Key, 0x52, 8);
  addKey("TapeA-Play", Unmapped_Key, 0x53, 8);
  addKey("TapeA-Rev", Unmapped_Key, 0x54, 8);
  addKey("TapeA-Record", Unmapped_Key, 0x55, 8);
  addKey("TapeA-FastForward", Unmapped_Key, 0x56, 8);
  addKey("TapeA-Rewind", Unmapped_Key, 0x57, 8);

  addKey("Standby", Power_Key, 0x80, 8);  // "RCVR_POWER"
  addKey("Input-TunerFM", FM_Key, 0x81, 8);
  addKey("Input-TunerAM", AM_Key, 0x82, 8);
  addKey("Input-CD", CDInput_Key, 0x85, 8);
  addKey("VolumeUp", VolumeUp_Key, 0x88, 8);
  addKey("Input-Disc", PhonoInput_Key, 0x89, 8);
  addKey("RCVR_1", One_Key, 0x8A, 8);
  addKey("RCVR_5", Five_Key, 0x8B, 8);
  addKey("VolumeDown", VolumeDown_Key, 0x8C, 8);
  addKey("Input-Tape1", TapeInput_Key, 0x8D, 8);
  addKey("RCVR_2", Two_Key, 0x8E, 8);
  addKey("RCVR_6", Six_Key, 0x8F, 8);

  addKey("Input-Tape2", MDInput_Key, 0x91, 8); // hack
  addKey("RCVR_3", Three_Key, 0x92, 8);
  addKey("RCVR_7", Seven_Key, 0x93, 8);
  addKey("Mute", Mute_Key, 0x94, 8); // "RCVR_MUTE_ENTER"
  addKey("RCVR_4", Four_Key, 0x96, 8);
  addKey("RCVR_8", Eight_Key, 0x97, 8);
  addKey("RCVR_9", Nine_Key, 0x98, 8);
  addKey("TapeB-Record", Unmapped_Key, 0x9A, 8);
  addKey("Input-Aux", AuxInput_Key, 0x9B, 8);
  addKey("TapeB-Play", Unmapped_Key, 0x9C, 8);
  addKey("TapeB-FastForward", Unmapped_Key, 0x9D, 8);
  addKey("TapeB-Rewind", Unmapped_Key, 0x9E, 8);
  addKey("TapeB-Stop", Unmapped_Key, 0x9F, 8);

  addKey("Input-Video2", SatInput_Key, 0xC0, 8); // "SAT"
  addKey("Input-Video3", VCRInput_Key, 0xC1, 8); // "VCR"
  addKey("Input-Video1", DVDInput_Key, 0xC2, 8); // "DVD", "LD"
  addKey("RCVR_0", Zero_Key, 0xC7, 8);
  addKey("Power-Off", PowerOff_Key, 0xC8, 8);
  addKey("RCVR_SURR.", Surround_Key, 0xCC, 8);
  addKey("RCVR_TEST", Unmapped_Key, 0xCD, 8);
  addKey("Speakers-A", Unmapped_Key, 0xCE, 8);
  addKey("Speakers-B", Unmapped_Key, 0xCF, 8);

  addKey("Tuner-PresetLeft", ChannelDown_Key, 0xD1, 8);
  addKey("Tuner-PresetRight", ChannelUp_Key, 0xD2, 8);
  addKey("FM/AM", ToggleBand_Key, 0xDD, 8); // "tuner"
  addKey("FM/AM", TunerInput_Key, 0xDD, 8); // "tuner"
  addKey("TapeB-Rev", Unmapped_Key, 0xDE, 8);
}


void NADAudio1::populateInputList(
  QComboBox *cb) const
{
  cb->clear();

  cb->addItem("Tuner", QVariant(TunerInput_Key));
  cb->addItem("FM", QVariant(FM_Key));
  cb->addItem("AM", QVariant(AM_Key));
  cb->addItem("CD", QVariant(CDInput_Key));
  cb->addItem("Disc", QVariant(PhonoInput_Key));
  cb->addItem("Tape 1", QVariant(TapeInput_Key));
  cb->addItem("Tape 2", QVariant(MDInput_Key));
  cb->addItem("Video 1 (DVD / LD)", QVariant(DVDInput_Key));
  cb->addItem("Video 2 (Sat)", QVariant(SatInput_Key));
  cb->addItem("Video 3 (VCR)", QVariant(VCRInput_Key));
  cb->addItem("Video 4", QVariant(CompositeInput_Key));
  cb->addItem("Video 5", QVariant(Composite2Input_Key));
}


NADTuner1::NADTuner1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Tuner Component 1",
      NAD_Make,
      Receiver_Panels,
      index)
{
}


void NADTuner1::populateProtocol(
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

  setPreData(0x7C87, 16);

  addKey("Tuner-Bank", Unmapped_Key, 0x24, 8);
  addKey("tuner-disp-info", Info_Key, 0x26, 8); // "RCVR_DISPLAY"

  addKey("tuner-1", One_Key, 0x8A, 8);
  addKey("tuner-2", Two_Key, 0x8E, 8);
  addKey("tuner-3", Three_Key, 0x92, 8);
  addKey("tuner-4", Four_Key, 0x96, 8);
  addKey("tuner-5", Five_Key, 0x8B, 8);
  addKey("tuner-6", Six_Key, 0x8F, 8);
  addKey("tuner-7", Seven_Key, 0x93, 8);
  addKey("tuner-8", Eight_Key, 0x97, 8);
  addKey("tuner-9", Nine_Key, 0x98, 8);
  addKey("tuner-0", Zero_Key, 0xC7, 8);
  addKey("tuner-10", Unmapped_Key, 0xF2, 8);
  addKey("tuner-+10", DoubleDigit_Key, 0xF3, 8);

  addKey("tuner-enter", Select_Key, 0xC5, 8);
  addKey("tuner-enter", Enter_Key, 0xC5, 8);
  addKey("Tuner-PresetRight", ChannelUp_Key, 0xD2, 8);
  addKey("Tuner-PresetRight", Up_Key, 0xD2, 8);
  addKey("Tuner-PresetLeft", ChannelDown_Key, 0xD1, 8);
  addKey("Tuner-PresetLeft", Down_Key, 0xD1, 8);
  addKey("tuner-tune-left", Left_Key, 0xD3, 8);
  addKey("tuner-tune-right", Right_Key, 0xD4, 8);

  addKey("tuner-fm-mute", Unmapped_Key, 0x37, 8);
  addKey("tuner-blend", Unmapped_Key, 0x35, 8);
  addKey("tuner-am-fm-dab", TunerInput_Key, 0xDD, 8);

  addKey("Standby", Power_Key, 0x80, 8);  // "RCVR_POWER"
  addKey("VolumeUp", VolumeUp_Key, 0x88, 8);
  addKey("VolumeDown", VolumeDown_Key, 0x8C, 8);
  addKey("Mute", Mute_Key, 0x94, 8); // "RCVR_MUTE_ENTER"
}


NADDVD1::NADDVD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      NAD_Make,
      MediaControl_Panels,
      index)
{
}

void NADDVD1::populateProtocol(
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

  addKey("OPEN/CLOSE", Eject_Key, 0x36, 8);
  addKey("STOP", Stop_Key, 0x39, 8);
  addKey("PLAY", Play_Key, 0x31, 8);
  addKey("PAUSE/STEP", Pause_Key, 0x38, 8);
  addKey("SKIP-", Previous_Key, 0x35, 8);
  addKey("SKIP+", Next_Key, 0x34, 8);
  addKey("SCAN-", Rewind_Key, 0x32, 8);
  addKey("SCAN+", FastForward_Key, 0x33, 8);
  addKey("REPEAT", Repeat_Key, 0x53, 8);
  addKey("PROGRAM", Program_Key, 0x57, 8);
  addKey("AUDIO", Audio_Key, 0x4F, 8);
  addKey("SUBTITLE", Captions_Key, 0x50, 8);
  addKey("CLEAR", Clear_Key, 0x46, 8);
  addKey("ZOOM", Zoom_Key, 0x64, 8);
  addKey("DVD_POWER", Power_Key, 0x30, 8);
  addKey("DVD_1", One_Key, 0x3B, 8);
  addKey("DVD_2", Two_Key, 0x3C, 8);
  addKey("DVD_3", Three_Key, 0x3D, 8);
  addKey("DVD_4", Four_Key, 0x3E, 8);
  addKey("DVD_5", Five_Key, 0x3F, 8);
  addKey("DVD_6", Six_Key, 0x40, 8);
  addKey("DVD_7", Seven_Key, 0x41, 8);
  addKey("DVD_8", Eight_Key, 0x42, 8);
  addKey("DVD_9", Nine_Key, 0x43, 8);
  addKey("DVD_0", Zero_Key, 0x44, 8);
  addKey("DVD_VOLUME+", VolumeUp_Key, 0x47, 8);
  addKey("DVD_VOLUME+", Up_Key, 0x47, 8);
  addKey("DVD_VOLUME-", VolumeDown_Key, 0x48, 8);
  addKey("DVD_VOLUME-", Down_Key, 0x48, 8);
  addKey("DVD_TUNE_DOWN", Left_Key, 0x59, 8);
  addKey("DVD_TUNE_UP", Right_Key, 0x5A, 8);
  addKey("DVD_MUTE_ENTER", Select_Key, 0x58, 8);
  addKey("DVD_MUTE_ENTER", Mute_Key, 0x58, 8);
  addKey("DVD_SET_UP", Menu_Key, 0x56, 8);
  addKey("DVD_NEXT_DISC", NextDisc_Key, 0x49, 8);
  addKey("DVD_TITLE", DiscTitle_Key, 0x4A, 8);
  addKey("DVD_MENU", DiscMenu_Key, 0x4B, 8);
  addKey("DVD_DISPLAY", Info_Key, 0x3A, 8);
  addKey("DVD_RETURN", Exit_Key, 0x45, 8);
}


NADCD1::NADCD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "CD Component 1",
      NAD_Make,
      MediaControl_Panels,
      index)
{
}


void NADCD1::populateProtocol(
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

  addSIRC12Key("PLAY", Play_Key, 0x11, 0x32);
  addSIRC12Key("STOP", Stop_Key, 0x11, 0x38);
  addSIRC12Key("PAUSE", Pause_Key, 0x11, 0x39);
  addSIRC12Key("SKIP_LEFT", Previous_Key, 0x11, 0x30);
  addSIRC12Key("SKIP_RIGHT", Next_Key, 0x11, 0x31);
  addSIRC12Key("SCAN_LEFT", Rewind_Key, 0x11, 0x3A);
  addSIRC12Key("SCAN_RIGHT", FastForward_Key, 0x11, 0x3B);
}


NADCD2::NADCD2(
  unsigned int index)
  : PIRKeysetMetaData(
      "CD Component 2",
      NAD_Make,
      MediaControl_Panels,
      index)
{
}


void NADCD2::populateProtocol(
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

  setPreData(0x7C87, 16);

  addKey("PlayPause", Play_Key, 0x01, 8);
//  addKey("PlayPause", Pause_Key, 0x01, 8);
  addKey("Stop", Stop_Key, 0x02, 8);
  addKey("Random", Random_Key, 0x03, 8);
  addKey("ScanBack", Rewind_Key, 0x04, 8);
  addKey("SkipBack", Previous_Key, 0x05, 8);
  addKey("SkipForward", Next_Key, 0x06, 8);
  addKey("ScanForward", FastForward_Key, 0x07, 8);
  addKey("cd-disp-info", Info_Key, 0x08, 8); // "Time"
  addKey("Repeat", Repeat_Key, 0x0A, 8);
  addKey("Program", Program_Key, 0x0B, 8);
  addKey("1", One_Key, 0x0C, 8);
  addKey("2", Two_Key, 0x0D, 8);
  addKey("3", Three_Key, 0x0E, 8);
  addKey("4", Four_Key, 0x0F, 8);

  addKey("5", Five_Key, 0x10, 8);
  addKey("6", Six_Key, 0x11, 8);
  addKey("7", Seven_Key, 0x12, 8);
  addKey("8", Eight_Key, 0x13, 8);
  addKey("9", Nine_Key, 0x15, 8);
  addKey("0", Zero_Key, 0x16, 8);

  addKey("cd-eject", Eject_Key, 0x48, 8);
  addKey("cd-pause", Pause_Key, 0x4A, 8);
  addKey("10", Unmapped_Key, 0x4C, 8);
  addKey("Add10", DoubleDigit_Key, 0x4D, 8);

  addKey("Standby", Power_Key, 0x80, 8);  // "RCVR_POWER"
  addKey("VolumeUp", VolumeUp_Key, 0x88, 8);
  addKey("VolumeDown", VolumeDown_Key, 0x8C, 8);
  addKey("Mute", Mute_Key, 0x94, 8); // "RCVR_MUTE_ENTER"
}


NADTape1::NADTape1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Tape Component 1",
      NAD_Make,
      MediaControl_Panels | MediaRecord_Panels,
      index)
{
}


void NADTape1::populateProtocol(
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

  setPreData(0x7C87, 16);

  addKey("TapeA-Stop", Stop_Key, 0x52, 8);
  addKey("TapeA-Play", Play_Key, 0x53, 8);
  addKey("TapeA-Rev", StepBack_Key, 0x54, 8);
  addKey("TapeA-Record", Record_Key, 0x55, 8);
  addKey("TapeA-FastForward", FastForward_Key, 0x56, 8);
  addKey("TapeA-Rewind", Rewind_Key, 0x57, 8);

  addKey("TapeB-Play", Unmapped_Key, 0x9C, 8);
  addKey("TapeB-Rev", Unmapped_Key, 0xDE, 8);
  addKey("TapeB-Stop", Unmapped_Key, 0x9F, 8);
  addKey("TapeB-Record", Unmapped_Key, 0x9A, 8);
  addKey("TapeB-FastForward", Unmapped_Key, 0x9D, 8);
  addKey("TapeB-Rewind", Unmapped_Key, 0x9E, 8);

  addKey("Standby", Power_Key, 0x80, 8);  // "RCVR_POWER"
  addKey("VolumeUp", VolumeUp_Key, 0x88, 8);
  addKey("VolumeDown", VolumeDown_Key, 0x8C, 8);
  addKey("Mute", Mute_Key, 0x94, 8); // "RCVR_MUTE_ENTER"
}
