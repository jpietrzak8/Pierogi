//
// kenwood.cpp
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

#include "kenwood.h"
#include "protocols/necprotocol.h"
#include <QComboBox>


KenwoodAudio1::KenwoodAudio1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 1",
      Kenwood_Make,
      Receiver_Panels | MediaRecord_Panels,
      index)
{
}


void KenwoodAudio1::populateProtocol(
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

  setPreData(0xB8, 8);

  addKey("REW", Rewind_Key, 0x06, 8); // "CD_REW"
  addKey("FWD", FastForward_Key, 0x07, 8); // "CD_FFWD"
  addKey("DISC", NextDisc_Key, 0x08, 8);
  addKey("VOL_CENTRE_DOWN", CenterVolumeDown_Key, 0x0A, 8);
  addKey("VOL_CENTRE_UP", CenterVolumeUp_Key, 0x0B, 8);
  addKey("10", DoubleDigit_Key, 0x0D, 8);

  addKey("ENTER", Enter_Key, 0x1D, 8);

  addKey("SQ2", Unmapped_Key, 0x4D, 8); // "DELAY_SURROUND"

  addKey("SOURCEDIRECT", Unmapped_Key, 0x54, 8);
  addKey("FUNCTION", Unmapped_Key, 0x57, 8);
  addKey("RED", Red_Key, 0x56, 8); // "TEST_TONE"

  addKey("0", Zero_Key, 0x80, 8);
  addKey("1", One_Key, 0x81, 8);
  addKey("2", Two_Key, 0x82, 8);
  addKey("3", Three_Key, 0x83, 8);
  addKey("4", Four_Key, 0x84, 8);
  addKey("5", Five_Key, 0x85, 8);
  addKey("6", Six_Key, 0x86, 8);
  addKey("7", Seven_Key, 0x87, 8);
  addKey("8", Eight_Key, 0x88, 8);
  addKey("9", Nine_Key, 0x89, 8);
  addKey("TUNER_DOWN", ChannelDown_Key, 0x8C, 8);
  addKey("TUNER_AM", AM_Key, 0x8E, 8);
  addKey("TUNER_BAND", FM_Key, 0x8F, 8); // "Tuner_FM"

  addKey("PHONO", PhonoInput_Key, 0x90, 8);
  addKey("SELECT_TUNER", TunerInput_Key, 0x91, 8);
  addKey("SELECT_CD", CDInput_Key, 0x92, 8);
  addKey("SELECT_VIDEO_2", AuxInput_Key, 0x93, 8); // "AUX"
  addKey("SELECT_TAPE_A", TapeInput_Key, 0x94, 8);
  addKey("SELECT_TAPE_B", MDInput_Key, 0x95, 8); // Hacky
  addKey("SELECT_VIDEO_1", CompositeInput_Key, 0x96, 8);
  addKey("TUNER_UP", ChannelUp_Key, 0x99, 8);
  addKey("VOL-", VolumeDown_Key, 0x9A, 8);
  addKey("VOL+", VolumeUp_Key, 0x9B, 8);
  addKey("MUTE", Mute_Key, 0x9C, 8);
  addKey("POWER", Power_Key, 0x9D, 8);
  addKey("TUNER_DIRECT", Unmapped_Key, 0x9E, 8);
  addKey("TUNER_A/B", Unmapped_Key, 0x9F, 8);

  addKey("Phono-STOP", Unmapped_Key, 0xC0, 8);
  addKey("Phono-PLAY", Unmapped_Key, 0xC1, 8);
  addKey("M.CALL", Call_Key, 0xC5, 8);
  addKey("VOL_REAR_DOWN", RearVolumeDown_Key, 0xC6, 8);
  addKey("VOL_REAR_UP", RearVolumeUp_Key, 0xC7, 8);
  addKey("CD_STOP", Stop_Key, 0xC9, 8);
  addKey("CD_PLAY/PAUSE", Play_Key, 0xCB, 8);
  addKey("CD_PLAY/PAUSE", Pause_Key, 0xCB, 8);
  addKey("CD_SEARCH_REW", Previous_Key, 0xCE, 8); // "CD_SKIPBACK"
  addKey("CD_SEARCH_FWD", Next_Key, 0xCF, 8); // "CD_SKIPFORWARD"

  addKey("TAPE_A_REV_PLAY", Unmapped_Key, 0xD0, 8);
  addKey("TAPE_A_FWD_PLAY", Unmapped_Key, 0xD1, 8);
  addKey("TAPE_A_REWIND", Unmapped_Key, 0xD2, 8);
  addKey("TAPE_A_FFWD", Unmapped_Key, 0xD3, 8);
  addKey("TAPE_A_PAUSE", Unmapped_Key, 0xD4, 8);
  addKey("TAPE_A_STOP", Unmapped_Key, 0xD5, 8);
  addKey("TAPE_A_RECORD", Unmapped_Key, 0xD6, 8);
  addKey("STEREO", Audio_Key, 0xD7, 8);
  addKey("TAPE_B_REV_PLAY", Unmapped_Key, 0xD8, 8);
  addKey("TAPE_A_FWD_PLAY", Unmapped_Key, 0xD9, 8);
  addKey("TAPE_A_REWIND", Unmapped_Key, 0xDA, 8);
  addKey("TAPE_A_FFWD", Unmapped_Key, 0xDB, 8);
  addKey("TAPE_A_PAUSE", Unmapped_Key, 0xDC, 8);
  addKey("TAPE_A_STOP", Unmapped_Key, 0xDD, 8);
  addKey("TAPE_A_RECORD", Unmapped_Key, 0xDE, 8);
  addKey("SURROUND", Surround_Key, 0xDF, 8);
}


void KenwoodAudio1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("Tuner", QVariant(TunerInput_Key));
  cb->addItem("CD", QVariant(CDInput_Key));
  cb->addItem("Video 1", QVariant(CompositeInput_Key));
  cb->addItem("Video 2 (Aux)", QVariant(AuxInput_Key));
  cb->addItem("Tape A", QVariant(TapeInput_Key));
  cb->addItem("Tape B", QVariant(MDInput_Key));
  cb->addItem("Phono", QVariant(PhonoInput_Key));
}


/*
KenwoodAudio2::KenwoodAudio2(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 2",
      Kenwood_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x0000, 16);

  addKey("POWER", Power_Key, 0x9D, 8);
  addKey("REW", Rewind_Key, 0xDA, 8);
  addKey("FWD", FastForward_Key, 0xDB, 8);
}
*/


KenwoodComponent1::KenwoodComponent1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Component Keyset 1",
      Kenwood_Make,
      Receiver_Panels | MediaRecord_Panels,
      index)
{
}


void KenwoodComponent1::populateProtocol(
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

  setPreData(0x00B8, 16);

  addKey("discskip", NextDisc_Key, 0x08, 8);
  addKey("CENTER_DOWN", CenterVolumeDown_Key, 0x0A, 8);
  addKey("CENTER_UP", CenterVolumeUp_Key, 0x0B, 8);
  addKey("+10", DoubleDigit_Key, 0x0D, 8);
  addKey("TIME", Unmapped_Key, 0x0E, 8); // "pty/time"
  addKey("EFFECT", Unmapped_Key, 0x0F, 8); // "GE_EFFECT", "EQ.ON/OFF"

  addKey("LD", Unmapped_Key, 0x16, 8);

  addKey("DELAY/ASFC-", Unmapped_Key, 0x4C, 8);
  addKey("DELAY/ASFC+", Unmapped_Key, 0x4D, 8);

  addKey("CENTER_MODE", Unmapped_Key, 0x55, 8);
  addKey("TEST_TONE", Unmapped_Key, 0x56, 8);
  addKey("RDS_DISP", Info_Key, 0x58, 8);
  addKey("Loudness", Unmapped_Key, 0x5F, 8);

  addKey("0", Zero_Key, 0x80, 8);
  addKey("1", One_Key, 0x81, 8);
  addKey("2", Two_Key, 0x82, 8);
  addKey("3", Three_Key, 0x83, 8);
  addKey("4", Four_Key, 0x84, 8);
  addKey("5", Five_Key, 0x85, 8);
  addKey("6", Six_Key, 0x86, 8);
  addKey("7", Seven_Key, 0x87, 8);
  addKey("8", Eight_Key, 0x88, 8);
  addKey("9", Nine_Key, 0x89, 8);
  addKey("BAND", ToggleBand_Key, 0x8F, 8);

  addKey("Phono-play", Unmapped_Key, 0x90, 8);
  addKey("TUNER", TunerInput_Key, 0x91, 8);
  addKey("CD", CDInput_Key, 0x92, 8);
  addKey("AUX", AuxInput_Key, 0x93, 8);
  addKey("tape/a_<>", Unmapped_Key, 0x94, 8);
  addKey("TAPE", TapeInput_Key, 0x95, 8); // "tape/b_<>"
  addKey("VIDEO", CompositeInput_Key, 0x96, 8);
  addKey("Sleep", Sleep_Key, 0x97, 8);
  addKey("VOLUME_DOWN", VolumeDown_Key, 0x9A, 8); // "DOWN"
  addKey("VOLUME_DOWN", Down_Key, 0x9A, 8); // "DOWN"
  addKey("VOLUME_UP", VolumeUp_Key, 0x9B, 8); // "UP"
  addKey("VOLUME_UP", Up_Key, 0x9B, 8); // "UP"
  addKey("MUTE", Mute_Key, 0x9C, 8);
  addKey("Power", Power_Key, 0x9D, 8);

  addKey("Phono-stop", Unmapped_Key, 0xC0, 8);
  addKey("PMODE_CD", Unmapped_Key, 0xC4, 8); // "Auto/Mono"
  addKey("GE-m-call", Unmapped_Key, 0xC5, 8);
  addKey("REAR_LEVEL-", RearVolumeDown_Key, 0xC6, 8); // "SURROUND_DOWN"
  addKey("REAR_LEVEL+", RearVolumeUp_Key, 0xC7, 8); // "SURROUND_UP"
  addKey("CHECK", Unmapped_Key, 0xC8, 8);
  addKey("STOP_CD", Stop_Key, 0xC9, 8);
  addKey("CLEAR", Clear_Key, 0xCA, 8);
  addKey("PLAY/PAUSE_CD", Play_Key, 0xCB, 8);
  addKey("PLAY/PAUSE_CD", Pause_Key, 0xCB, 8);
  addKey("repeat", Repeat_Key, 0xCC, 8);
  addKey("EDIT", Unmapped_Key, 0xCD, 8);
  addKey("SKIP_REV", Previous_Key, 0xCE, 8);
  addKey("SKIP_FWD", Next_Key, 0xCF, 8);

  addKey("Tape-A-play-left", Unmapped_Key, 0xD0, 8);
  addKey("Tape-A-play-right", Unmapped_Key, 0xD1, 8);
  addKey("Tape-A-rew", Unmapped_Key, 0xD2, 8);
  addKey("Tape-A-ffwd", Unmapped_Key, 0xD3, 8);
  addKey("Tape-A-stop", Unmapped_Key, 0xD5, 8);
  addKey("GE-off", Unmapped_Key, 0xD7, 8); // "STEREO"
  addKey("PLAY_REV", Unmapped_Key, 0xD8, 8); // tape b
  addKey("PLAY_FWD", Unmapped_Key, 0xD9, 8); // tape b
  addKey("Tape-B-rew", Unmapped_Key, 0xDA, 8);
  addKey("Tape-B-ffwd", Unmapped_Key, 0xDB, 8);
  addKey("Tape-B-pause", Unmapped_Key, 0xDC, 8);
  addKey("STOP", Unmapped_Key, 0xDD, 8);
  addKey("Tape-B-record", Unmapped_Key, 0xDE, 8);
  addKey("Presence", Unmapped_Key, 0xDF, 8); // "LISTEN_MODE"
}


void KenwoodComponent1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("Tuner", QVariant(TunerInput_Key));
  cb->addItem("CD", QVariant(CDInput_Key));
  cb->addItem("Aux", QVariant(AuxInput_Key));
  cb->addItem("Video", QVariant(CompositeInput_Key));
  cb->addItem("Tape", QVariant(TapeInput_Key));
}


KenwoodComponent2::KenwoodComponent2(
  unsigned int index)
  : PIRKeysetMetaData(
      "Component Keyset 2",
      Kenwood_Make,
      MediaControl_Panels,
      index)
{
}


void KenwoodComponent2::populateProtocol(
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

  setPreData(0x01B8, 16);

  addKey("DOLBY_SURROUND", Surround_Key, 0x00, 8);
  addKey("PCALL_DOWN", ChannelDown_Key, 0x06, 8); // tuner
  addKey("PCALL_UP", ChannelUp_Key, 0x07, 8); // tuner
  addKey("DOLBY_3_STEREO", Unmapped_Key, 0x0E, 8);

  addKey("HITMASTER", Unmapped_Key, 0x1B, 8);

  addKey("N.B.", NoiseReduction_Key, 0x4B, 8); // "noise_blanking"
  addKey("SPACE", Unmapped_Key, 0x4F, 8);

  addKey("Down", Down_Key, 0x54, 8);
  addKey("Up", Up_Key, 0x55, 8);
  addKey("sound_cont", Unmapped_Key, 0x57, 8);
  addKey("enter", Enter_Key, 0x5A, 8); // "MEMO"

  addKey("p.call_I<<", ChannelDown_Key, 0x91, 8); // "LEFT"
  addKey("p.call_I<<", Left_Key, 0x91, 8); // "LEFT"
  addKey("p.call_I>>", ChannelUp_Key, 0x92, 8); // "RIGHT"
  addKey("p.call_I>>", Right_Key, 0x92, 8); // "RIGHT"
  addKey("disc1", Unmapped_Key, 0x93, 8);
  addKey("disc2", Unmapped_Key, 0x94, 8);
  addKey("disc3", Unmapped_Key, 0x95, 8);
  addKey("LINE", Unmapped_Key, 0x9B, 8);
  addKey("PTY", Unmapped_Key, 0x9C, 8);

  addKey("INPUT", Input_Key, 0xCC, 8);
  addKey("dual_sound", Unmapped_Key, 0xCE, 8);

  addKey("MD/DAT", MDInput_Key, 0xD2, 8);
  addKey("random", Random_Key, 0xD4, 8);
  addKey("FWD_MD", Unmapped_Key, 0xD8, 8); // play?
  addKey("STOP_MD", Stop_Key, 0xD9, 8);
  addKey("REW_MD", Rewind_Key, 0xDC, 8);
  addKey("FWD_MD", Unmapped_Key, 0xDD, 8); // fast forward?
}


void KenwoodComponent2::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("Input", QVariant(Input_Key));
  cb->addItem("MD / DAT", QVariant(MDInput_Key));
}


KenwoodComponent3::KenwoodComponent3(
  unsigned int index)
  : PIRKeysetMetaData(
      "Component Keyset 3",
      Kenwood_Make,
      Receiver_Panels | MediaRecord_Panels,
      index)
{
}


void KenwoodComponent3::populateProtocol(
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

  setPreData(0x02B8, 16);

  addKey("SKIP_REV", Previous_Key, 0x00, 8); // "PREV", "Left"
  addKey("SKIP_FWD", Next_Key, 0x01, 8); // "NEXT", "Right"
  addKey("tuning<<", ChannelDown_Key, 0x02, 8); // "SEARCH_REV"
  addKey("tuning<<", Rewind_Key, 0x02, 8); // "SEARCH_REV"
  addKey("tuning>>", ChannelUp_Key, 0x03, 8); // "SEARCH_FWD"
  addKey("tuning>>", FastForward_Key, 0x03, 8); // "SEARCH_FWD"
  addKey("stop", Stop_Key, 0x04, 8);
  addKey("</>", TapeInput_Key, 0x05, 8); // "TAPE"
  addKey("tuner/band", TunerInput_Key, 0x06, 8); // "TUNER"
  addKey("cd_play_pause", Play_Key, 0x07, 8); // "CD"
  addKey("cd_play_pause", Pause_Key, 0x07, 8);
  addKey("A/B", RepeatAB_Key, 0x08, 8); // "A_B"
  addKey("CD/TUNER/TAPE", Input_Key, 0x09, 8);

  addKey("low_stop", Unmapped_Key, 0x18, 8);
  addKey("low_play", Unmapped_Key, 0x19, 8);
  addKey("low_prev", Unmapped_Key, 0x1A, 8);
  addKey("low_next", Unmapped_Key, 0x1B, 8);
  addKey("long_play", Unmapped_Key, 0x1C, 8);
  addKey("Dimmer", Unmapped_Key, 0x1D, 8);
  addKey("llc", Unmapped_Key, 0x1F, 8);

  addKey("+100", PlusOneHundred_Key, 0x4F, 8);

  addKey("SRS_3D", Surround_Key, 0x55, 8);
  addKey("ex.bass", EnhancedBass_Key, 0x57, 8);

  addKey("TA_NEWS_INFO", Unmapped_Key, 0xC0, 8);

  addKey("rev.mode", Unmapped_Key, 0xD0, 8);
  addKey("tape_eq", Unmapped_Key, 0xD1, 8);
}


void KenwoodComponent3::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("CD / Tuner / Tape", QVariant(Input_Key));
  cb->addItem("Tape", QVariant(TapeInput_Key));
  cb->addItem("Tuner / Band", QVariant(TunerInput_Key));
}

/*
"rds_display/text_display", 0x1DC012ED
"setup", 0x1DC09867
"PLAY_PAUSE", 0x1DC0609F
"PLAY_BACK", 0x1DC0906F // "Flip"
"dvd6ch", 0x1DC001FE
"InputSel", 0x1DC06A95
"menu", 0x1D20B946
"select", 0x1D2039C6
"back", 0x1D20FB04
*/

/*
KenwoodAudio5::KenwoodAudio5(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 5",
      Kenwood_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x49B4, 16);

  addKey("VOLUME_DOWN_SW", VolumeDown_Key, 0x12, 8);
  addKey("VOLUME_UP_SW", VolumeUp_Key, 0x13, 8);
  addKey("POWER_SW", Power_Key, 0x18, 8);
}
*/


KenwoodCD1::KenwoodCD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "CD Keyset 1",
      Kenwood_Make,
      MediaControl_Panels,
      index)
{
}


void KenwoodCD1::populateProtocol(
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

  setPreData(0xB6, 8);

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
  addKey("+10", DoubleDigit_Key, 0x0A, 8);

  addKey("OPEN_CLOSE", Eject_Key, 0x10, 8);
  addKey("stop", Stop_Key, 0x11, 8);
  addKey("play", Play_Key, 0x13, 8); // "PAUSE"
  addKey("play", Pause_Key, 0x13, 8); // "PAUSE"
  addKey("back", Rewind_Key, 0x14, 8); // "REWIND"
  addKey("forward", FastForward_Key, 0x15, 8);
  addKey("last", Previous_Key, 0x16, 8);
  addKey("next", Next_Key, 0x17, 8);
  addKey("TIME_DISPLAY", Unmapped_Key, 0x18, 8);
  addKey("REPEAT", Repeat_Key, 0x19, 8);
  addKey("clear", Clear_Key, 0x1A, 8);
  addKey("check", Unmapped_Key, 0x1B, 8);
  addKey("INDEX_BACK", Unmapped_Key, 0x1C, 8);
  addKey("INDEX_FWD", Unmapped_Key, 0x1D, 8);
  addKey("EDIT_2", Unmapped_Key, 0x1E, 8);
  addKey("p.mode", Unmapped_Key, 0x1F, 8);

  addKey("bboost", EnhancedBass_Key, 0xC1, 8);

  addKey("space", Unmapped_Key, 0x42, 8);
  addKey("REPEAT_A-B", RepeatAB_Key, 0x43, 8);
  addKey("TRACK", Unmapped_Key, 0x44, 8);
  addKey("PGM", Program_Key, 0x45, 8);
  addKey("TIME", Unmapped_Key, 0x46, 8);
  addKey("down", Down_Key, 0x48, 8); // "VOL_DOWN"
  addKey("down", VolumeDown_Key, 0x48, 8); // "VOL_DOWN"
  addKey("up", Up_Key, 0x49, 8); // "VOL_UP"
  addKey("up", VolumeUp_Key, 0x49, 8); // "VOL_UP"
  addKey("edit", Unmapped_Key, 0x4A, 8);
  addKey("DISPLAY_MODE", Info_Key, 0x4C, 8);
  addKey("DISC_SKIP", NextDisc_Key, 0x4D, 8);
  addKey("random", Random_Key, 0x4F, 8);

  addKey("P", Unmapped_Key, 0x50, 8);
  addKey("DISC_1", Unmapped_Key, 0x51, 8);
  addKey("DISC_2", Unmapped_Key, 0x52, 8);
  addKey("DISC_3", Unmapped_Key, 0x53, 8);
  addKey("DISC_4", Unmapped_Key, 0x54, 8);
  addKey("DISC_5", Unmapped_Key, 0x55, 8);
  addKey("DISC_6", Unmapped_Key, 0x56, 8);

  addKey("10", Unmapped_Key, 0x80, 8);
  addKey("11", Unmapped_Key, 0x81, 8);
  addKey("12", Unmapped_Key, 0x82, 8);
  addKey("13", Unmapped_Key, 0x83, 8);
  addKey("14", Unmapped_Key, 0x84, 8);
  addKey("15", Unmapped_Key, 0x85, 8);
  addKey("16", Unmapped_Key, 0x86, 8);
  addKey("17", Unmapped_Key, 0x87, 8);
  addKey("18", Unmapped_Key, 0x88, 8);
  addKey("19", Unmapped_Key, 0x89, 8);
  addKey("20/0", Unmapped_Key, 0x8A, 8);
  addKey("peak_search", Unmapped_Key, 0x8D, 8);
  addKey("DISC_FILE", Unmapped_Key, 0x8F, 8);
  addKey("ERASE", Unmapped_Key, 0x90, 8);
  addKey("power", Power_Key, 0x91, 8);
}


KenwoodDVD1::KenwoodDVD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Kenwood_Make,
      MediaControl_Panels,
      index)
{
  addControlledDevice(Kenwood_Make, "DVF-9010", Audio_Device);
}


void KenwoodDVD1::populateProtocol(
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

  setPreData(0x0CB6, 16);

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
  addKey("PLUS_TEN", DoubleDigit_Key, 0x0A, 8);

  addKey("(0)OpenClose", Eject_Key, 0x10, 8);
  addKey("Stop", Stop_Key, 0x11, 8);
  addKey("PAUSE", Pause_Key, 0x12, 8);
  addKey("Play", Play_Key, 0x13, 8);
  addKey("REVERSE", Rewind_Key, 0x14, 8);
  addKey("FORWARD", FastForward_Key, 0x15, 8);
  addKey("SkipDown", Previous_Key, 0x16, 8);
  addKey("SkipUp", Next_Key, 0x17, 8); // ?

  addKey("Repeat", Repeat_Key, 0x19, 8);
  addKey("C", Unmapped_Key, 0x1A, 8);
  addKey("P.Mode", PictureMode_Key, 0x1F, 8);

  addKey("ABRepeat", RepeatAB_Key, 0x43, 8);
  addKey("(1)Memory", Memory_Key, 0x4B, 8);

  addKey("OnScreen", Unmapped_Key, 0x5F, 8);

  addKey("Display", Info_Key, 0x8C, 8);
  addKey("DVD_POWER", Power_Key, 0x91, 8);
  addKey("(7)TextDisp", Unmapped_Key, 0x96, 8);
  addKey("(8)AllInfo", Unmapped_Key, 0x97, 8);
  addKey("(9)TitleSearch", Unmapped_Key, 0x98, 8);

  addKey("Setup", Menu_Key, 0xC0, 8);
  addKey("(3)Title", DiscTitle_Key, 0xC1, 8);
  addKey("Menu", DiscMenu_Key, 0xC2, 8);
  addKey("(4)Angle", Angle_Key, 0xC3, 8);
  addKey("Return", Exit_Key, 0xC4, 8);
  addKey("(6)Subtitle", Captions_Key, 0xC5, 8);
  addKey("(5)Audio", Audio_Key, 0xC9, 8);

  addKey("Enter", Select_Key, 0xD3, 8);
  addKey("Up", Up_Key, 0xD6, 8);
  addKey("Down", Down_Key, 0xD7, 8);
  addKey("Left", Left_Key, 0xD8, 8);
  addKey("Right", Right_Key, 0xD9, 8);
  addKey("(2)VirtualSurr", Surround_Key, 0xDF, 8);
}


KenwoodTV1::KenwoodTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Kenwood_Make,
      TV_Panels,
      index)
{
}


void KenwoodTV1::populateProtocol(
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

  setPreData(0x04, 8);

  addKey("TV-CH_UP", ChannelUp_Key, 0x00, 8);
  addKey("TV-CH_DOWN", ChannelDown_Key, 0x01, 8);
  addKey("TV-VOL_UP", VolumeUp_Key, 0x02, 8);
  addKey("TV-VOL_DOWN", VolumeDown_Key, 0x03, 8);

  addKey("Power_TV", Power_Key, 0x08, 8);
  addKey("TV/VIDEO", Input_Key, 0x09, 8);
  addKey("ANT/AUX", AntennaInput_Key, 0x0B, 8);

  addKey("0", Zero_Key, 0x10, 8);
  addKey("1", One_Key, 0x11, 8);
  addKey("2", Two_Key, 0x12, 8);
  addKey("3", Three_Key, 0x13, 8);
  addKey("4", Four_Key, 0x14, 8);
  addKey("5", Five_Key, 0x15, 8);
  addKey("6", Six_Key, 0x16, 8);
  addKey("7", Seven_Key, 0x17, 8);
  addKey("8", Eight_Key, 0x18, 8);
  addKey("9", Nine_Key, 0x19, 8);

  addKey("TIMER", Sleep_Key, 0x1A, 8);
  addKey("RECALL", PrevChannel_Key, 0x1B, 8);
}


void KenwoodTV1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("TV / Video", QVariant(Input_Key));
  cb->addItem("Ant / Aux", QVariant(AntennaInput_Key));
}
