//
// onkyo.cpp
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
// along with Pierogi; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//

#include "onkyo.h"
#include "protocols/necprotocol.h"
#include "protocols/kaseikyoprotocol.h"
#include <QComboBox>


OnkyoAudio1::OnkyoAudio1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 1",
      Onkyo_Make,
      MediaControl_Panels,
      index)
{
}


void OnkyoAudio1::populateProtocol(
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

  setPreData(0xD2, 8);

  addKey("PLAY", Play_Key, 0x49, 8);
  addKey("STOP", Stop_Key, 0x4A, 8);
  addKey("PAUSE", Pause_Key, 0x4B, 8);
  addKey("5", Five_Key, 0x4C, 8);
  addKey("6", Six_Key, 0x4D, 8);
  addKey("7", Seven_Key, 0x4E, 8);
  addKey("8", Eight_Key, 0x4F, 8);

  addKey("9", Nine_Key, 0x50, 8);
  addKey("0", Zero_Key, 0x51, 8);
  addKey("MEMORY", Memory_Key, 0x52, 8);
  addKey("CLEAR", Clear_Key, 0x53, 8);
  addKey("REPEAT", Repeat_Key, 0x54, 8);
  addKey("INDEX", Unmapped_Key, 0x55, 8);
  addKey("DISPLAY", Info_Key, 0x56, 8); // "REMAIN"
  addKey("A-B", RepeatAB_Key, 0x57, 8);
  addKey("1", One_Key, 0x58, 8);
  addKey("2", Two_Key, 0x59, 8);
  addKey("3", Three_Key, 0x5A, 8);
  addKey("4", Four_Key, 0x5B, 8);
  addKey("PREV", Previous_Key, 0x5C, 8);
  addKey("NEXT", Next_Key, 0x5D, 8);
  addKey("REW", Rewind_Key, 0x5E, 8);
  addKey("FFW", FastForward_Key, 0x5F, 8);
}


OnkyoAudio2::OnkyoAudio2(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 2",
      Onkyo_Make,
      MediaControl_Panels,
      index)
{
}


void OnkyoAudio2::populateProtocol(
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

  setPreData(0x0DD2, 16);

  addKey("Autospace", Unmapped_Key, 0x1B, 8);
  addKey("Pause-Record", Pause_Key, 0x18, 8);
  addKey("Rewind", Rewind_Key, 0x1A, 8);
  addKey("FastFwd", FastForward_Key, 0x19, 8);
  addKey("PlayReverse", Unmapped_Key, 0x16, 8);
  addKey("PlayForward", Play_Key, 0x15, 8);
  addKey("SkipForward", Next_Key, 0x1D, 8);
  addKey("Stop", Stop_Key, 0x13, 8);
  addKey("Reset", Reset_Key, 0x5D, 8);
}


OnkyoAudio2a::OnkyoAudio2a(
  unsigned int index)
  : OnkyoAudio2(index)
{
  setKeysetName("Audio Keyset 2a");
}


void OnkyoAudio2a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  OnkyoAudio2::populateProtocol(guiObject);

  addKey("TAPE_FWD", FastForward_Key, 0x80, 8);
  addKey("TAPE_REW", Rewind_Key, 0x81, 8);
  addKey("TAPE_VOLUME_UP", VolumeUp_Key, 0x82, 8);
  addKey("TAPE_VOLUME_DOWN", VolumeDown_Key, 0x83, 8);
  addKey("TAPE_REPEAT", Repeat_Key, 0x86, 8);
  addKey("TAPE_A_B", RepeatAB_Key, 0x87, 8);
  addKey("TAPE_CLEAR", Clear_Key, 0x88, 8);
  addKey("TAPE_MEMORY", Memory_Key, 0x89, 8);
  addKey("TAPE_EJECT", Eject_Key, 0x8B, 8);
  addKey("TAPE_TRACK_8", Eight_Key, 0x8C, 8);
  addKey("TAPE_TRACK_9", Nine_Key, 0x8D, 8);
  addKey("TAPE_TRACK_0", Zero_Key, 0x8E, 8);
  addKey("TAPE_TRACK_PLUS_10", DoubleDigit_Key, 0x8F, 8);

  addKey("TAPE_TRACK_1", One_Key, 0x90, 8);
  addKey("TAPE_TRACK_2", Two_Key, 0x91, 8);
  addKey("TAPE_TRACK_3", Three_Key, 0x92, 8);
  addKey("TAPE_TRACK_4", Four_Key, 0x93, 8);
  addKey("TAPE_TRACK_5", Five_Key, 0x98, 8);
  addKey("TAPE_TRACK_6", Six_Key, 0x99, 8);
  addKey("TAPE_TRACK_7", Seven_Key, 0x9A, 8);
  addKey("TAPE_PLAY", Play_Key, 0x9B, 8);
  addKey("TAPE_STOP", Stop_Key, 0x9C, 8);
  addKey("TAPE_NEXT_TRACK", Next_Key, 0x9D, 8);
  addKey("TAPE_PREV_TRACK", Previous_Key, 0x9E, 8);
  addKey("TAPE_PAUSE", Pause_Key, 0x9F, 8);

  addKey("TAPE_SHUFFLE", Random_Key, 0xC6, 8);
  addKey("TAPE_AUTO_SPACE", Unmapped_Key, 0xCC, 8);

  addKey("TAPE_PEAK_SEARCH", Unmapped_Key, 0xDD, 8);
}


OnkyoAudio3::OnkyoAudio3(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 3",
      Onkyo_Make,
      Receiver_Panels | MediaRecord_Panels,
      index)
{
}


void OnkyoAudio3::populateProtocol(
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

  setPreData(0x6DD2, 16);

  addKey("tuner_:_preset_>", NextPreset_Key, 0x00, 8);
  addKey("tuner_:_preset_>", ChannelUp_Key, 0x00, 8);
  addKey("tuner_:_preset_<", PrevPreset_Key, 0x01, 8);
  addKey("tuner_:_preset_<", ChannelDown_Key, 0x01, 8);
  addKey("volume_up", VolumeUp_Key, 0x02, 8);
  addKey("volume_down", VolumeDown_Key, 0x03, 8);
  addKey("power", Power_Key, 0x04, 8);
  addKey("audio_muting", Mute_Key, 0x05, 8);
  addKey("input_selector_:_aux", AuxInput_Key, 0x06, 8);
  addKey("input_selector_:_tape_2", MDInput_Key, 0x07, 8); // hack
  addKey("input_selector_:_tape_1", TapeInput_Key, 0x08, 8);
  addKey("input_selector_:_cd", CDInput_Key, 0x09, 8);
  addKey("input_selector_:_phono", PhonoInput_Key, 0x0A, 8);
  addKey("input_selector_:_tuner", TunerInput_Key, 0x0B, 8);
  addKey("input_selector_:_video_2", Composite2Input_Key, 0x0D, 8);
  addKey("input_selector_:_video_1", CompositeInput_Key, 0x0E, 8);
  addKey("v1", Unmapped_Key, 0x0F, 8); // another video?

  addKey("deck_B_:#", Unmapped_Key, 0x13, 8);
  addKey("deck_B_:>", Unmapped_Key, 0x15, 8);
  addKey("deck_B_:<", Unmapped_Key, 0x16, 8);
  addKey("deck_B_:O/||", Unmapped_Key, 0x18, 8);
  addKey("deck_B_:>>", Unmapped_Key, 0x19, 8);
  addKey("deck_B_:<<", Unmapped_Key, 0x1A, 8);
  addKey("cd_:>", Play_Key, 0x1B, 8);
  addKey("cd_:#", Stop_Key, 0x1C, 8);
  addKey("cd_:>>", FastForward_Key, 0x1D, 8);
  addKey("cd_:<<", Rewind_Key, 0x1E, 8);
  addKey("cd_:||", Pause_Key, 0x1F, 8);

  addKey("REAR_LEVEL-UP", RearVolumeUp_Key, 0x42, 8);
  addKey("REAR_LEVEL-DOWN", RearVolumeDown_Key, 0x43, 8);
  addKey("source_direct", Unmapped_Key, 0x44, 8); // "INPUT_SEL_DIRECT"
  addKey("FM", FM_Key, 0x46, 8);
  addKey("AM", AM_Key, 0x47, 8);
  addKey("tuner_:_class", Unmapped_Key, 0x4A, 8); // set a preset?
  addKey("SURROUND_FUNCTION-MODE", Surround_Key, 0x4C, 8); // "surrmode"
  addKey("stop", Unmapped_Key, 0x4D, 8); // "deck_A_:#"
  addKey("play", Unmapped_Key, 0x4E, 8); // "deck_A_:>"
  addKey("deck_A_:<", Unmapped_Key, 0x4F, 8);

  addKey("deck_A_:O/||", Unmapped_Key, 0x50, 8);
  addKey("ffw", Unmapped_Key, 0x51, 8); // "deck_A_:>>"
  addKey("rew", Unmapped_Key, 0x52, 8); // "deck_A_:<<"
  addKey("SURROUND_FUNCTION-DELAY_TIME", Unmapped_Key, 0x53, 8);
  addKey("speakers_A", Unmapped_Key, 0x59, 8); // "SPEAKERS_MAIN"
  addKey("speakers_B", Unmapped_Key, 0x5A, 8); // "SPEAKERS_REMOTE"
  addKey("CD-eject", Eject_Key, 0x5C, 8);
  addKey("SLEEP", Sleep_Key, 0x5D, 8);

  addKey("CENTER_LEVEL-UP", CenterVolumeUp_Key, 0x80, 8);
  addKey("CENTER_LEVEL-DOWN", CenterVolumeDown_Key, 0x81, 8);
  addKey("up", Up_Key, 0x82, 8);
  addKey("down", Down_Key, 0x83, 8);
  addKey("left", Left_Key, 0x84, 8);
  addKey("right", Right_Key, 0x85, 8);

  addKey("chapter_back", Unmapped_Key, 0x93, 8);
  addKey("chapter_forward", Unmapped_Key, 0x94, 8);
  addKey("enter", Select_Key, 0x97, 8);
  addKey("SURROUND_FUNCTION-TEST", Unmapped_Key, 0x9A, 8);
  addKey("actrl", Unmapped_Key, 0x9B, 8);
  addKey("v4", Unmapped_Key, 0x9F, 8); // yet another video input

  addKey("SIMUL_SOURCE_VOL-UP", Unmapped_Key, 0xC2, 8);
  addKey("SIMUL_SOURCE_VOL-DOWN", Unmapped_Key, 0xC3, 8);
  addKey("SIMUL_SOURCE", Unmapped_Key, 0xCC, 8);
}


void OnkyoAudio3::populateInputList(
  QComboBox *cb) const
{
  cb->clear();

  cb->addItem("Aux", QVariant(AuxInput_Key));
  cb->addItem("CD", QVariant(CDInput_Key));
  cb->addItem("Tuner", QVariant(TunerInput_Key));
  cb->addItem("Tape 1", QVariant(TapeInput_Key));
  cb->addItem("Tape 2", QVariant(MDInput_Key));
  cb->addItem("Phono", QVariant(PhonoInput_Key));
  cb->addItem("Video 1", QVariant(CompositeInput_Key));
  cb->addItem("Video 2", QVariant(Composite2Input_Key));
}


OnkyoAudio4::OnkyoAudio4(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 4",
      Onkyo_Make,
      MediaControl_Panels,
      index)
{
}


void OnkyoAudio4::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x2CD2, 16);

  addKey("CD_FWD", FastForward_Key, 0x00, 8);
  addKey("CD_REW", Rewind_Key, 0x01, 8);
  addKey("CD_VOLUME_UP", VolumeUp_Key, 0x02, 8);
  addKey("CD_VOLUME_DOWN", VolumeDown_Key, 0x03, 8);
  addKey("NEXT_SELECTION", Unmapped_Key, 0x05, 8);
  addKey("CD_REPEAT", Repeat_Key, 0x06, 8);
  addKey("CD_A_B", RepeatAB_Key, 0x07, 8);
  addKey("CD_CLEAR", Clear_Key, 0x08, 8);
  addKey("CD_MEMORY", Memory_Key, 0x09, 8);
  addKey("CD_ELAPSED", Info_Key, 0x0A, 8); // "DISPLAY"
  addKey("CD_EJECT", Eject_Key, 0x0B, 8);
  addKey("CD_TRACK_8", Eight_Key, 0x0C, 8);
  addKey("CD_TRACK_9", Nine_Key, 0x0D, 8);
  addKey("CD_TRACK_0", Zero_Key, 0x0E, 8);
  addKey("CD_TRACK_PLUS_10", DoubleDigit_Key, 0x0F, 8);

  addKey("CD_TRACK_1", One_Key, 0x10, 8);
  addKey("CD_TRACK_2", Two_Key, 0x11, 8);
  addKey("CD_TRACK_3", Three_Key, 0x12, 8);
  addKey("CD_TRACK_4", Four_Key, 0x13, 8);
  addKey("CD_TRACK_5", Five_Key, 0x18, 8);
  addKey("CD_TRACK_6", Six_Key, 0x19, 8);
  addKey("CD_TRACK_7", Seven_Key, 0x1A, 8);
  addKey("CD_PLAY", Play_Key, 0x1B, 8);
  addKey("CD_STOP", Stop_Key, 0x1C, 8);
  addKey("CD_NEXT_TRACK", Next_Key, 0x1D, 8);
  addKey("CD_PREV_TRACK", Previous_Key, 0x1E, 8);
  addKey("CD_PAUSE", Pause_Key, 0x1F, 8);

  addKey("EDIT_NEXT", Unmapped_Key, 0x42, 8);
  addKey("EDIT_PREVIOUS", Unmapped_Key, 0x43, 8);
  addKey("INDEX", Unmapped_Key, 0x44, 8);
  addKey("CD_SHUFFLE", Random_Key, 0x46, 8);
  addKey("CD_AUTO_SPACE", Unmapped_Key, 0x4C, 8);
  addKey("CD_TIME_EDIT", Unmapped_Key, 0x4D, 8);

  addKey("CD_PEAK_SEARCH", Unmapped_Key, 0x5D, 8);
  addKey("CD_FADE", Unmapped_Key, 0x5E, 8);
}


OnkyoAudio5::OnkyoAudio5(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 5",
      Onkyo_Make,
      MediaControl_Panels,
      index)
{
}


void OnkyoAudio5::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated
    return;
  }

  threadableProtocol = new KaseikyoProtocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x2002, 16);

  addKaseikyoKey("Stop", Stop_Key, 0x0AA, 0x00);
  addKaseikyoKey("Play/Pause", Play_Key, 0x0AA, 0x0A);
  addKaseikyoKey("Play/Pause", Pause_Key, 0x0AA, 0x0A);

  addKaseikyoKey("1", One_Key, 0x0AA, 0x10);
  addKaseikyoKey("2", Two_Key, 0x0AA, 0x11);
  addKaseikyoKey("3", Three_Key, 0x0AA, 0x12);
  addKaseikyoKey("4", Four_Key, 0x0AA, 0x13);
  addKaseikyoKey("5", Five_Key, 0x0AA, 0x14);
  addKaseikyoKey("6", Six_Key, 0x0AA, 0x15);
  addKaseikyoKey("7", Seven_Key, 0x0AA, 0x16);
  addKaseikyoKey("8", Eight_Key, 0x0AA, 0x17);
  addKaseikyoKey("9", Nine_Key, 0x0AA, 0x18);
  addKaseikyoKey("0", Zero_Key, 0x0AA, 0x19);

  addKaseikyoKey("Output+", VolumeUp_Key, 0x0AA, 0x20);
  addKaseikyoKey("Output-", VolumeDown_Key, 0x0AA, 0x21);

  addKaseikyoKey("M.Scan", Unmapped_Key, 0x0AA, 0x46);
  addKaseikyoKey("RepeatAll", Repeat_Key, 0x0AA, 0x47);
  addKaseikyoKey("RepeatA-B", RepeatAB_Key, 0x0AA, 0x48);
  addKaseikyoKey("Skip/Search_Back", Rewind_Key, 0x0AA, 0x49);
  addKaseikyoKey("Skip/Search_Forward", FastForward_Key, 0x0AA, 0x4A);

  addKaseikyoKey("Clear", Clear_Key, 0x0AA, 0x80);
  addKaseikyoKey("Recall", Unmapped_Key, 0x0AA, 0x81);
  addKaseikyoKey(">10", DoubleDigit_Key, 0x0AA, 0x84);
  addKaseikyoKey("10", Unmapped_Key, 0x0AA, 0x85);
  addKaseikyoKey("Memory", Memory_Key, 0x0AA, 0x8A);
}


OnkyoDVD1::OnkyoDVD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Onkyo_Make,
      MediaControl_Panels,
      index)
{
}


void OnkyoDVD1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x6CD2, 16);

  addKey("mdfastforward", Unmapped_Key, 0x00, 8);
  addKey("mdrewind", Unmapped_Key, 0x01, 8);
  addKey("MULTI-CH-INPUT", Unmapped_Key, 0x04, 8);
  addKey("md/tape", TapeInput_Key, 0x09, 8);
  addKey("mdplay", Unmapped_Key, 0x0A, 8);
  addKey("mdstop", Unmapped_Key, 0x0B, 8);
  addKey("mdnexttrack", Unmapped_Key, 0x0C, 8);
  addKey("mdprevtrack", Unmapped_Key, 0x0D, 8);
  addKey("mdpause", Unmapped_Key, 0x0E, 8);

  addKey("CH-LEVEL+", VolumeUp_Key, 0x42, 8); // "level+"
  addKey("CH-LEVEL-", VolumeDown_Key, 0x43, 8); // "level-"
  addKey("CH-SEL", Unmapped_Key, 0x44, 8);
  addKey("standby", Power_Key, 0x47, 8);
  addKey("stereo", Surround_Key, 0x4C, 8);

  addKey("setup", Menu_Key, 0x53, 8);
//  addKey("return", Exit_Key, 0x54, 8); // child class?
  addKey("display", Info_Key, 0x55, 8);

  addKey("DVD", DVDInput_Key, 0x8C, 8);
  addKey("DVD_PLAY", Play_Key, 0x8D, 8);
  addKey("DVD_STOP", Stop_Key, 0x8E, 8);
  addKey("DVD_CHAPTER+", Next_Key, 0x8F, 8);
  addKey("DVD_CHAPTER-", Previous_Key, 0x90, 8);
  addKey("DVD_FF", FastForward_Key, 0x91, 8);
  addKey("DVD_REW", Rewind_Key, 0x92, 8);
  addKey("dvdpause", Pause_Key, 0x93, 8);
  addKey("setup", Menu_Key, 0x97, 8);
  addKey("topmenu", DiscTitle_Key, 0x98, 8);
  addKey("menu", DiscMenu_Key, 0x99, 8);
  addKey("up", Up_Key, 0x9A, 8);
  addKey("down", Down_Key, 0x9B, 8);
  addKey("left", Left_Key, 0x9C, 8);
  addKey("right", Right_Key, 0x9D, 8);
  addKey("enter", Select_Key, 0x9E, 8);
  addKey("return", Exit_Key, 0x9F, 8);

  addKey("latenight", Unmapped_Key, 0xD7, 8);
  addKey("open", Eject_Key, 0xD8, 8);
  addKey("audio", Audio_Key, 0xD9, 8);
  addKey("spsetup", Unmapped_Key, 0xDB, 8);
  addKey("swmode", Unmapped_Key, 0xDE, 8);
  addKey("distance", Unmapped_Key, 0xDF, 8);
}


void OnkyoDVD1::populateInputList(
  QComboBox *cb) const
{
  cb->clear();

  cb->addItem("DVD", QVariant(DVDInput_Key));
  cb->addItem("MD / Tape", QVariant(TapeInput_Key));
}


OnkyoDVD2::OnkyoDVD2(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 2",
      Onkyo_Make,
      MediaControl_Panels,
      index)
{
}


void OnkyoDVD2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x2BD2, 16);

  addKey("Power", Power_Key, 0x04, 8);
  addKey("OpenClose", Eject_Key, 0x05, 8);
  addKey("Display", Info_Key, 0x06, 8);
  addKey("Angle", Angle_Key, 0x07, 8);
  addKey("Enter", Select_Key, 0x08, 8);
  addKey("Return", Exit_Key, 0x09, 8);
  addKey("Random", Random_Key, 0x0A, 8);
  addKey("SlowForward", StepForward_Key, 0x0B, 8);
  addKey("FastForward", FastForward_Key, 0x0C, 8);
  addKey("FastReverse", Rewind_Key, 0x0D, 8);
  addKey("1", One_Key, 0x0E, 8);
  addKey("2", Two_Key, 0x0F, 8);

  addKey("3", Three_Key, 0x10, 8);
  addKey("4", Four_Key, 0x11, 8);
  addKey("5", Five_Key, 0x12, 8);
  addKey("6", Six_Key, 0x13, 8);
  addKey("7", Seven_Key, 0x14, 8);
  addKey("8", Eight_Key, 0x15, 8);
  addKey("9", Nine_Key, 0x16, 8);
  addKey("0", Zero_Key, 0x17, 8);
  addKey("+10", DoubleDigit_Key, 0x18, 8);
  addKey("Search", Unmapped_Key, 0x19, 8);
  addKey("Play", Play_Key, 0x1B, 8);
  addKey("Stop", Stop_Key, 0x1C, 8);
  addKey("Next", Next_Key, 0x1D, 8);
  addKey("Previous", Previous_Key, 0x1E, 8);
  addKey("Pause", Pause_Key, 0x1F, 8);

  addKey("Repeat", Repeat_Key, 0x44, 8);
  addKey("A-B", RepeatAB_Key, 0x45, 8);
  addKey("Dimmer", Unmapped_Key, 0x46, 8);
  addKey("Zoom", Zoom_Key, 0x48, 8);
  addKey("Memory", Memory_Key, 0x4A, 8);
  addKey("Clear", Clear_Key, 0x4B, 8);
  addKey("Setup", Menu_Key, 0x4D, 8);
  addKey("TopMenu", DiscTitle_Key, 0x4E, 8);
  addKey("Menu", DiscMenu_Key, 0x4F, 8);

  addKey("Up", Up_Key, 0x50, 8);
  addKey("Down", Down_Key, 0x51, 8);
  addKey("Left", Left_Key, 0x52, 8);
  addKey("Right", Right_Key, 0x53, 8);
  addKey("Subtitle", Unmapped_Key, 0x54, 8);
  addKey("Audio", Audio_Key, 0x55, 8);
  addKey("SubtitleOnOff", Captions_Key, 0x56, 8);

  addKey("SlowReverse", StepBack_Key, 0x8F, 8);
  addKey("NextSelection", Unmapped_Key, 0x90, 8);
  addKey("CDPlay", CDInput_Key, 0xD2, 8); // dubious
  addKey("Disc+", NextDisc_Key, 0xD3, 8);
  addKey("Disc-", PrevDisc_Key, 0xD4, 8);
  addKey("Disc1", Unmapped_Key, 0xD5, 8);
  addKey("Disc2", Unmapped_Key, 0xD6, 8);
  addKey("Disc3", Unmapped_Key, 0xD7, 8);
  addKey("Disc4", Unmapped_Key, 0xD8, 8);
  addKey("Disc5", Unmapped_Key, 0xD9, 8);
  addKey("Disc6", Unmapped_Key, 0xDA, 8);
}
