//
// technics.cpp
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

#include "technics.h"
#include "protocols/kaseikyoprotocol.h"
#include "protocols/panasonicoldprotocol.h"
#include <QComboBox>


TechnicsAudio1::TechnicsAudio1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 1",
      Technics_Make,
      MediaControl_Panels,
      index)
{
}


void TechnicsAudio1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new KaseikyoProtocol(guiObject, index);

  setPreData(0x2002, 16);

  addKaseikyoKey("stop", Stop_Key, 0x0AA, 0x00);
  addKaseikyoKey("open/close", Eject_Key, 0x0AA, 0x01);
  addKaseikyoKey("search_bwd", Rewind_Key, 0x0AA, 0x02); // "Rewind"
  addKaseikyoKey("search_fwd", FastForward_Key, 0x0AA, 0x03); // "FastForward"
  addKaseikyoKey("pause", Pause_Key, 0x0AA, 0x06);
  addKaseikyoKey("play", Play_Key, 0x0AA, 0x0A);

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

  addKaseikyoKey("level+", VolumeUp_Key, 0x0AA, 0x20); // "VOL_UP"
  addKaseikyoKey("level-", VolumeDown_Key, 0x0AA, 0x21); // "VOL_DOWN"

  addKaseikyoKey("POWER", Power_Key, 0x0AA, 0x3D);

  addKaseikyoKey("M.SCAN", Scan_Key, 0x0AA, 0x46);
  addKaseikyoKey("repeat", Repeat_Key, 0x0AA, 0x47);
  addKaseikyoKey("a-b_repeat", RepeatAB_Key, 0x0AA, 0x48);
  addKaseikyoKey("skip_bwd", Previous_Key, 0x0AA, 0x49); // "PrevTrack"
  addKaseikyoKey("skip_fwd", Next_Key, 0x0AA, 0x4A); // "NextTrack"
  addKaseikyoKey("random", Random_Key, 0x0AA, 0x4D);
  addKaseikyoKey("side_a-b", Unmapped_Key, 0x0AA, 0x53);
  addKaseikyoKey("tape_length", Unmapped_Key, 0x0AA, 0x54);
  addKaseikyoKey("time_mode", Unmapped_Key, 0x0AA, 0x55);

  addKaseikyoKey("peak_search", Unmapped_Key, 0x0AA, 0x70);
  addKaseikyoKey("auto_cue", Unmapped_Key, 0x0AA, 0x74);

  addKaseikyoKey("clear", Clear_Key, 0x0AA, 0x80);
  addKaseikyoKey("recall", Unmapped_Key, 0x0AA, 0x81); // prev channel?
  addKaseikyoKey("+10", DoubleDigit_Key, 0x0AA, 0x84);
  addKaseikyoKey("10", Unmapped_Key, 0x0AA, 0x85);
  addKaseikyoKey("program", Program_Key, 0x0AA, 0x8A);
  addKaseikyoKey("auto_cue", Unmapped_Key, 0x0AA, 0x8B);
  addKaseikyoKey("Peak_Search", Unmapped_Key, 0x0AA, 0x8F);

  addKaseikyoKey("Time_Fade", Unmapped_Key, 0x0AA, 0x94);

  addKaseikyoKey("disc", NextDisc_Key, 0x0AA, 0xA4);
  addKaseikyoKey("Tape_Length", Unmapped_Key, 0x0AA, 0xAB);
  addKaseikyoKey("Side_A/B", Unmapped_Key, 0x0AA, 0xAC);

  addKaseikyoKey("on-winamp", PowerOn_Key, 0x0AA, 0xEB); // might be wrong
  addKaseikyoKey("spiral", Unmapped_Key, 0x0AA, 0xED);
  addKaseikyoKey("off-winamp", PowerOff_Key, 0xAA, 0x01); // Might be wrong
}


TechnicsAudio1a::TechnicsAudio1a(
  unsigned int index)
  : TechnicsAudio1(index)
{
  setKeysetName("Audio Keyset 1a");
}


void TechnicsAudio1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  TechnicsAudio1::populateProtocol(guiObject);

  addKaseikyoKey("generalvol+", VolumeUp_Key, 0x0AA, 0x46);
  addKaseikyoKey("winampvol+", Unmapped_Key, 0x0AA, 0x47);
  addKaseikyoKey("winampvol-", Unmapped_Key, 0x0AA, 0x55);
  addKaseikyoKey("generalvol-", VolumeDown_Key, 0x0AA, 0x81);
}


TechnicsAudio2::TechnicsAudio2(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 2",
      Technics_Make,
      Receiver_Panels,
      index)
{
}


void TechnicsAudio2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new KaseikyoProtocol(guiObject, index);

  setPreData(0x1001, 16);

  addKaseikyoKey("VOL-UP", VolumeUp_Key, 0x005, 0x20);
  addKaseikyoKey("VOL-DOWN", VolumeDown_Key, 0x005, 0x21);
  addKaseikyoKey("BALANCE-L", BalanceLeft_Key, 0x005, 0x26);
  addKaseikyoKey("BALANCE-R", BalanceRight_Key, 0x005, 0x27);
  addKaseikyoKey("MUTING", Mute_Key, 0x005, 0x32);
  addKaseikyoKey("CD", CDInput_Key, 0x005, 0x94);

  addKaseikyoKey("AUTO/MONO", FMMode_Key, 0x045, 0x33);
  addKaseikyoKey("TUNER/BAND", TunerInput_Key, 0x045, 0xA4);

  addKaseikyoKey("DECKSTOP", Unmapped_Key, 0x085, 0x00);
  addKaseikyoKey("DECK<<", Unmapped_Key, 0x085, 0x02);
  addKaseikyoKey("DECK>>", Unmapped_Key, 0x085, 0x03);
  addKaseikyoKey("REC_PAUSE", Unmapped_Key, 0x085, 0x08);
  addKaseikyoKey("DECK<", Unmapped_Key, 0x085, 0x0B);
  addKaseikyoKey("DECK>", Unmapped_Key, 0x085, 0x0A);
  addKaseikyoKey("DECK1/2", Unmapped_Key, 0x085, 0x95);

  addKaseikyoKey("CDSTOP", Stop_Key, 0x0A5, 0x00);
  addKaseikyoKey("CD||", Pause_Key, 0x0A5, 0x06);
  addKaseikyoKey("CD->", Play_Key, 0x0A5, 0x0A);
  addKaseikyoKey("CD|<<", Previous_Key, 0x0A5, 0x49);
  addKaseikyoKey("CD>>|", Next_Key, 0x0A5, 0x4A);
  addKaseikyoKey("PROGRAM", Program_Key, 0x0A5, 0x8A);
  addKaseikyoKey("CANCEL", Clear_Key, 0x0A5, 0xA3);

  addKaseikyoKey("EQSPACE", Unmapped_Key, 0x105, 0x83);
  addKaseikyoKey("FLAT", Unmapped_Key, 0x105, 0x8F);

  addKaseikyoKey("1", One_Key, 0x1C5, 0x10);
  addKaseikyoKey("2", Two_Key, 0x1C5, 0x11);
  addKaseikyoKey("3", Three_Key, 0x1C5, 0x12);
  addKaseikyoKey("4", Four_Key, 0x1C5, 0x13);
  addKaseikyoKey("5", Five_Key, 0x1C5, 0x14);
  addKaseikyoKey("6", Six_Key, 0x1C5, 0x15);
  addKaseikyoKey("7", Seven_Key, 0x1C5, 0x16);
  addKaseikyoKey("8", Eight_Key, 0x1C5, 0x17);
  addKaseikyoKey("9", Nine_Key, 0x1C5, 0x18);
  addKaseikyoKey("0", Zero_Key, 0x1C5, 0x19);
  addKaseikyoKey(">10", DoubleDigit_Key, 0x1C5, 0x84);
  addKaseikyoKey("SLEEP", Sleep_Key, 0x1C5, 0x96);
  addKaseikyoKey("POWER", Power_Key, 0x1C5, 0x3D);
}


void TechnicsAudio2::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("CD", QVariant(CDInput_Key));
  cb->addItem("Tuner / Band", QVariant(TunerInput_Key));
}


TechnicsAudio3::TechnicsAudio3(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 3",
      Technics_Make,
      Receiver_Panels,
      index)
{
}


void TechnicsAudio3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new KaseikyoProtocol(guiObject, index);

  setPreData(0x2002, 16);

  addKaseikyoKey("vol_up", VolumeUp_Key, 0x00A, 0x20);
  addKaseikyoKey("vol_down", VolumeDown_Key, 0x00A, 0x21);
  addKaseikyoKey("balance_left", BalanceLeft_Key, 0x00A, 0x26);
  addKaseikyoKey("balance_right", BalanceRight_Key, 0x00A, 0x27);
  addKaseikyoKey("SURROUND-UP", RearVolumeUp_Key, 0x00A, 0x2C);
  addKaseikyoKey("SURROUND-DOWN", RearVolumeDown_Key, 0x00A, 0x2D);
  addKaseikyoKey("muting", Mute_Key, 0x00A, 0x32);
  addKaseikyoKey("VCR/VDP", VCRInput_Key, 0x00A, 0x86);
  addKaseikyoKey("phono", PhonoInput_Key, 0x00A, 0x90);
  addKaseikyoKey("Amp.Tuner", TunerInput_Key, 0x00A, 0x92);
  addKaseikyoKey("cd", CDInput_Key, 0x00A, 0x94);
  addKaseikyoKey("tape", TapeInput_Key, 0x00A, 0x96);
  addKaseikyoKey("TAPE2", MDInput_Key, 0x00A, 0x97);
  addKaseikyoKey("ext", Unmapped_Key, 0x00A, 0x99); // "DCC"
  addKaseikyoKey("AUX", AuxInput_Key, 0x00A, 0x9A);
  addKaseikyoKey("vdp", Unmapped_Key, 0x00A, 0xA2); // separate keyset?
  addKaseikyoKey("PRO-LOGIC", Unmapped_Key, 0x00A, 0xB4);
  addKaseikyoKey("chselect", Unmapped_Key, 0x00A, 0xBB);
  addKaseikyoKey("delay_time", Unmapped_Key, 0x00A, 0xC8);
  addKaseikyoKey("CENTER-UP", CenterVolumeUp_Key, 0x00A, 0xCE);
  addKaseikyoKey("CENTER-DOWN", CenterVolumeDown_Key, 0x00A, 0xCF);
  addKaseikyoKey("TEST", Unmapped_Key, 0x00A, 0xF6);

  addKaseikyoKey("auto/mono", FMMode_Key, 0x04A, 0x33);
  addKaseikyoKey("Tuner.Preset.up", ChannelUp_Key, 0x04A, 0x34);
  addKaseikyoKey("Tuner.Preset.down", ChannelDown_Key, 0x04A, 0x35);
  addKaseikyoKey("tuner/band", ToggleBand_Key, 0x04A, 0xA4);

  addKaseikyoKey("tape_stop", Unmapped_Key, 0x08A, 0x00);
  addKaseikyoKey("tape_open/close", Unmapped_Key, 0x08A, 0x01);
  addKaseikyoKey("tape_rew", Unmapped_Key, 0x08A, 0x02);
  addKaseikyoKey("tape_fwd", Unmapped_Key, 0x08A, 0x03);
  addKaseikyoKey("rec_pause", Unmapped_Key, 0x08A, 0x08);
  addKaseikyoKey("tape_play_fwd", Unmapped_Key, 0x08A, 0x0A);
  addKaseikyoKey("tape_play_back", Unmapped_Key, 0x08A, 0x0B);
  addKaseikyoKey("tape", PCInput_Key, 0x08A, 0x95); // hack

  addKaseikyoKey("cd_stop", Stop_Key, 0x0AA, 0x00);
  addKaseikyoKey("cd_open/close", Eject_Key, 0x0AA, 0x01);
  addKaseikyoKey("cd_pause", Pause_Key, 0x0AA, 0x06);
  addKaseikyoKey("cd_play", Play_Key, 0x0AA, 0x0A);
  addKaseikyoKey("program", Program_Key, 0x0AA, 0x2A);
  addKaseikyoKey("repeat", Repeat_Key, 0x0AA, 0x47);
  addKaseikyoKey("cd_back", Previous_Key, 0x0AA, 0x49);
  addKaseikyoKey("cd_fwd", Next_Key, 0x0AA, 0x4A);
  addKaseikyoKey("disc", NextDisc_Key, 0x0AA, 0xA4);
  addKaseikyoKey("cancel", Clear_Key, 0x0AA, 0xA5);

  addKaseikyoKey("3dai", Unmapped_Key, 0x10A, 0x31);
  addKaseikyoKey("eq", Unmapped_Key, 0x10A, 0x83);
  addKaseikyoKey("EQ-SPACE", Unmapped_Key, 0x10A, 0x8F);

  addKaseikyoKey("supersurround", Unmapped_Key, 0x12A, 0xC0);
  addKaseikyoKey("simulatedsurround", Unmapped_Key, 0x12A, 0xEC);

  addKaseikyoKey("1", One_Key, 0x1CA, 0x10);
  addKaseikyoKey("2", Two_Key, 0x1CA, 0x11);
  addKaseikyoKey("3", Three_Key, 0x1CA, 0x12);
  addKaseikyoKey("4", Four_Key, 0x1CA, 0x13);
  addKaseikyoKey("5", Five_Key, 0x1CA, 0x14);
  addKaseikyoKey("6", Six_Key, 0x1CA, 0x15);
  addKaseikyoKey("7", Seven_Key, 0x1CA, 0x16);
  addKaseikyoKey("8", Eight_Key, 0x1CA, 0x17);
  addKaseikyoKey("9", Nine_Key, 0x1CA, 0x18);
  addKaseikyoKey("0", Zero_Key, 0x1CA, 0x19);
  addKaseikyoKey("power", Power_Key, 0x1CA, 0x3D);
  addKaseikyoKey(">10", DoubleDigit_Key, 0x1CA, 0x84);
  addKaseikyoKey("sleep", Sleep_Key, 0x1CA, 0x96);
  addKaseikyoKey("aveffect", Unmapped_Key, 0x1CA, 0xE0);
  addKaseikyoKey("down", Down_Key, 0x1CA, 0xF2);
  addKaseikyoKey("up", Up_Key, 0x1CA, 0xF3);
  addKaseikyoKey("right", Right_Key, 0x1CA, 0xFC);
  addKaseikyoKey("left", Left_Key, 0x1CA, 0xFD);
}


void TechnicsAudio3::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("Tuner", QVariant(TunerInput_Key));
  cb->addItem("CD", QVariant(CDInput_Key));
  cb->addItem("Phono", QVariant(PhonoInput_Key));
  cb->addItem("Tape", QVariant(TapeInput_Key));
  cb->addItem("Tape 2", QVariant(MDInput_Key));
  cb->addItem("Tape 3", QVariant(PCInput_Key));
  cb->addItem("Aux", QVariant(AuxInput_Key));
  cb->addItem("VCR / VDP", QVariant(VCRInput_Key));
}


TechnicsAudio3a::TechnicsAudio3a(
  unsigned int index)
  : TechnicsAudio3(index)
{
  setKeysetName("Audio Keyset 3a");
}


void TechnicsAudio3a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  TechnicsAudio3::populateProtocol(guiObject);

  addKaseikyoKey("tape", Unmapped_Key, 0x01A, 0x95);

  addKaseikyoKey("stop", Stop_Key, 0x1CA, 0x00);
  addKaseikyoKey("pauze", Pause_Key, 0x1CA, 0x06);
  addKaseikyoKey("play", Play_Key, 0x1CA, 0x0A);
  addKaseikyoKey("vorige", Previous_Key, 0x1CA, 0x49);
  addKaseikyoKey("volgende", Next_Key, 0x1CA, 0x4A);
}


TechnicsReceiver1::TechnicsReceiver1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Receiver Keyset 1",
      Technics_Make,
      Receiver_Panels,
      index)
{
}


void TechnicsReceiver1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new KaseikyoProtocol(guiObject, index);

  setPreData(0x2002, 16);

  addKaseikyoKey("Vol up", VolumeUp_Key, 0x000, 0x20);
  addKaseikyoKey("Vol down", VolumeDown_Key, 0x000, 0x21);
  addKaseikyoKey("Side up", RearVolumeUp_Key, 0x000, 0x2C); // "Surround +"
  addKaseikyoKey("Side down", RearVolumeDown_Key, 0x000, 0x2D); // "Surround -"
  addKaseikyoKey("Stereo", Surround_Key, 0x000, 0x30); // "Surround on/off"
  addKaseikyoKey("SFC", Unmapped_Key, 0x000, 0x31);
  addKaseikyoKey("Mute", Mute_Key, 0x000, 0x32);
  addKaseikyoKey("Tuner Select", TunerInput_Key, 0x000, 0x92);
  addKaseikyoKey("CD Select", CDInput_Key, 0x000, 0x94);
  addKaseikyoKey("CD5 Select", Unmapped_Key, 0x000, 0x96);
  addKaseikyoKey("TV Select", Antenna2Input_Key, 0x000, 0x9C);
  addKaseikyoKey("VCR1", VCRInput_Key, 0x000, 0x9E);
  addKaseikyoKey("VCR2", CableInput_Key, 0x000, 0x9F); // Hack
  addKaseikyoKey("DVD Select", DVDInput_Key, 0x000, 0xA3);
  addKaseikyoKey("Surround", Unmapped_Key, 0x000, 0xB2); // ?
  addKaseikyoKey("Center up", CenterVolumeUp_Key, 0x000, 0xCE);
  addKaseikyoKey("Center down", CenterVolumeDown_Key, 0x000, 0xCF);

  addKaseikyoKey("1", One_Key, 0x004, 0x10);
  addKaseikyoKey("2", Two_Key, 0x004, 0x11);
  addKaseikyoKey("3", Three_Key, 0x004, 0x12);
  addKaseikyoKey("4", Four_Key, 0x004, 0x13);
  addKaseikyoKey("5", Five_Key, 0x004, 0x14);
  addKaseikyoKey("6", Six_Key, 0x004, 0x15);
  addKaseikyoKey("7", Seven_Key, 0x004, 0x16);
  addKaseikyoKey("8", Eight_Key, 0x004, 0x17);
  addKaseikyoKey("9", Nine_Key, 0x004, 0x18);
  addKaseikyoKey("0", Zero_Key, 0x004, 0x19);
  addKaseikyoKey("Channel up", ChannelUp_Key, 0x004, 0x34);
  addKaseikyoKey("Channel down", ChannelDown_Key, 0x004, 0x35);
  addKaseikyoKey("power", Power_Key, 0x004, 0x3D);
  addKaseikyoKey(">=10", DoubleDigit_Key, 0x004, 0x84);
  addKaseikyoKey("FM Tune +", ChannelUp_Key, 0x004, 0x86);
  addKaseikyoKey("FM Tune -", ChannelDown_Key, 0x004, 0x87);
  addKaseikyoKey("Direct tuning", AntennaInput_Key, 0x004, 0x88);
  addKaseikyoKey("Band", ToggleBand_Key, 0x004, 0xA4);

  addKaseikyoKey("D/L+", Unmapped_Key, 0x014, 0xBC);
  addKaseikyoKey("D/L-", Unmapped_Key, 0x014, 0xBD);
  addKaseikyoKey("Level", Unmapped_Key, 0x014, 0xBE);
  addKaseikyoKey("Delay", Unmapped_Key, 0x014, 0xBF);
  addKaseikyoKey("Test", Unmapped_Key, 0x014, 0xF6);
}


void TechnicsReceiver1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("Tuner", QVariant(TunerInput_Key));
  cb->addItem("Tuner (alt)", QVariant(AntennaInput_Key));
  cb->addItem("CD", QVariant(CDInput_Key));
  cb->addItem("TV", QVariant(Antenna2Input_Key));
  cb->addItem("DVD", QVariant(DVDInput_Key));
  cb->addItem("VCR", QVariant(VCRInput_Key));
  cb->addItem("VCR 2", QVariant(CableInput_Key));
}


TechnicsReceiver1a::TechnicsReceiver1a(
  unsigned int index)
  : TechnicsReceiver1(index)
{
  setKeysetName("Receiver Keyset 1a");
}


void TechnicsReceiver1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  TechnicsReceiver1::populateProtocol(guiObject);

  addKaseikyoKey("power", Power_Key, 0x000, 0x3D);
  addKaseikyoKey("Discrete On", PowerOn_Key, 0x000, 0x3E);
  addKaseikyoKey("Discrete Off", PowerOff_Key, 0x000, 0x3F);
  addKaseikyoKey("Dolby Test", Unmapped_Key, 0x000, 0xF6);
}


TechnicsCD1::TechnicsCD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "CD Keyset 1",
      Technics_Make,
      MediaControl_Panels,
      index)
{
}


void TechnicsCD1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new PanasonicOldProtocol(guiObject, index);

  addPanOldKey("stop", Stop_Key, 0x0C, 0x00);
  addPanOldKey("SKIP-", Previous_Key, 0x0C, 0x02);
  addPanOldKey("SKIP+", Next_Key, 0x0C, 0x03);
  addPanOldKey("display", Info_Key, 0x0C, 0x04);
  addPanOldKey("rewind", Rewind_Key, 0x0C, 0x04);
  addPanOldKey("fast fwd", FastForward_Key, 0x0C, 0x05);
  addPanOldKey("pause", Pause_Key, 0x0C, 0x06);
  addPanOldKey("repeat", Repeat_Key, 0x0C, 0x07);
  addPanOldKey("tv/vcr", Input_Key, 0x0C, 0x08);
  addPanOldKey("recall", PrevChannel_Key, 0x0C, 0x09);
  addPanOldKey("play", Play_Key, 0x0C, 0x0A);
  addPanOldKey("Clear", Unmapped_Key, 0x0C, 0x0B);
  addPanOldKey("left arrow", Left_Key, 0x0C, 0x0C);
  addPanOldKey("right arrow", Right_Key, 0x0C, 0x0D);
  addPanOldKey("EJECT", Eject_Key, 0x0C, 0x0E);
  addPanOldKey("1", One_Key, 0x0C, 0x10);
  addPanOldKey("2", Two_Key, 0x0C, 0x11);
  addPanOldKey("3", Three_Key, 0x0C, 0x12);
  addPanOldKey("4", Four_Key, 0x0C, 0x13);
  addPanOldKey("5", Five_Key, 0x0C, 0x14);
  addPanOldKey("6", Six_Key, 0x0C, 0x15);
  addPanOldKey("7", Seven_Key, 0x0C, 0x16);
  addPanOldKey("8", Eight_Key, 0x0C, 0x17);
  addPanOldKey("9", Nine_Key, 0x0C, 0x18);
  addPanOldKey("0", Zero_Key, 0x0C, 0x19);
  addPanOldKey(">10", DoubleDigit_Key, 0x0C, 0x1A);
  addPanOldKey("program guide", Guide_Key, 0x0C, 0x1D);
  addPanOldKey("RANDOM", Random_Key, 0x0C, 0x1F);
  addPanOldKey("power", Power_Key, 0x0C, 0x20);
  addPanOldKey("vol up", VolumeUp_Key, 0x0C, 0x24);
  addPanOldKey("vol down", VolumeDown_Key, 0x0C, 0x25);
  addPanOldKey("mute", Mute_Key, 0x0C, 0x25); // odd
  addPanOldKey("disc select", NextDisc_Key, 0x0C, 0x26);
  addPanOldKey("time mode", Unmapped_Key, 0x0C, 0x29);
  addPanOldKey("menu", Menu_Key, 0x0C, 0x2A);
}


TechnicsDVD1::TechnicsDVD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Technics_Make,
      MediaControl_Panels,
      index)
{
}


void TechnicsDVD1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new KaseikyoProtocol(guiObject, index);

  setPreData(0x2002, 16);

  addKaseikyoKey("tv/av", Unmapped_Key, 0x008, 0x05);
  addKaseikyoKey("tvvol+", Unmapped_Key, 0x008, 0x20);
  addKaseikyoKey("tvvol-", Unmapped_Key, 0x008, 0x21);

  addKaseikyoKey("vol+", VolumeUp_Key, 0x00A, 0x20);
  addKaseikyoKey("vol-", VolumeDown_Key, 0x00A, 0x21);
  addKaseikyoKey("muting", Mute_Key, 0x00A, 0x32);
  addKaseikyoKey("dvd", DVDInput_Key, 0x00A, 0xA3);
  addKaseikyoKey("surround", Surround_Key, 0x00A, 0xB2);

  addKaseikyoKey("stop", Stop_Key, 0x00B, 0x00);
  addKaseikyoKey("play", Play_Key, 0x00B, 0x0A);

  addKaseikyoKey("1", One_Key, 0x00B, 0x10);
  addKaseikyoKey("2", Two_Key, 0x00B, 0x11);
  addKaseikyoKey("3", Three_Key, 0x00B, 0x12);
  addKaseikyoKey("4", Four_Key, 0x00B, 0x13);
  addKaseikyoKey("5", Five_Key, 0x00B, 0x14);
  addKaseikyoKey("6", Six_Key, 0x00B, 0x15);
  addKaseikyoKey("7", Seven_Key, 0x00B, 0x16);
  addKaseikyoKey("8", Eight_Key, 0x00B, 0x17);
  addKaseikyoKey("9", Nine_Key, 0x00B, 0x18);
  addKaseikyoKey("0", Zero_Key, 0x00B, 0x19);

  addKaseikyoKey("power", Power_Key, 0x00B, 0x3D);

  addKaseikyoKey("rewind", Rewind_Key, 0x00B, 0x49);  // previous?
  addKaseikyoKey("forward", FastForward_Key, 0x00B, 0x4A); // Next?

  addKaseikyoKey("menu", DiscMenu_Key, 0x00B, 0x80);
  addKaseikyoKey("select", Select_Key, 0x00B, 0x82);
  addKaseikyoKey("up", Up_Key, 0x00B, 0x85);
  addKaseikyoKey("down", Down_Key, 0x00B, 0x86);
  addKaseikyoKey("left", Left_Key, 0x00B, 0x87);
  addKaseikyoKey("right", Right_Key, 0x00B, 0x88);
  addKaseikyoKey("10", DoubleDigit_Key, 0x00B, 0x89);

  addKaseikyoKey("display", Info_Key, 0x00B, 0x92);
  addKaseikyoKey("title", DiscTitle_Key, 0x00B, 0x9B);

  addKaseikyoKey("disc/deck", Unmapped_Key, 0x08A, 0x95);
  addKaseikyoKey("processor", Unmapped_Key, 0x12A, 0x3D);
  addKaseikyoKey("stereo", Unmapped_Key, 0x14A, 0x30);
  addKaseikyoKey("+", Unmapped_Key, 0x14A, 0xBC);
  addKaseikyoKey("-", Unmapped_Key, 0x14A, 0xBD);
  addKaseikyoKey("level", Unmapped_Key, 0x14A, 0xBE);
  addKaseikyoKey("delay", Unmapped_Key, 0x14A, 0xBF);
  addKaseikyoKey("test", Unmapped_Key, 0x14A, 0xF6);
}
