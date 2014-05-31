//
// grundig.cpp
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

#include "grundig.h"
#include "protocols/rc5protocol.h"
#include "protocols/necxprotocol.h"
#include "protocols/necprotocol.h"
#include "protocols/protonprotocol.h"
#include <QComboBox>


// This one is iffy, might be another brand:
GrundigSat1::GrundigSat1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Satellite Keyset 1",
      Grundig_Make,
      TV_Panels,
      index)
{
}


void GrundigSat1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

  addKey("Mute", Mute_Key, 0x0286, 13);
  addKey("Guide", Guide_Key, 0x028F, 13);
  addKey("Up", Up_Key, 0x0290, 13);
  addKey("Down", Down_Key, 0x0291, 13);
  addKey("Serv", Unmapped_Key, 0x0292, 13);
  addKey("Exit", Exit_Key, 0x0293, 13);
  addKey("Left", Left_Key, 0x0295, 13);
  addKey("Right", Right_Key, 0x0296, 13);
  addKey("OK", Select_Key, 0x0297, 13);
  addKey("Prefer", Unmapped_Key, 0x02A1, 13);
  addKey("Perso", Unmapped_Key, 0x02AA, 13);
  addKey("A", Unmapped_Key, 0x02AB, 13);
  addKey("B", Unmapped_Key, 0x02AC, 13);
  addKey("C", Unmapped_Key, 0x02AD, 13);
  addKey("D", Unmapped_Key, 0x02AE, 13);
  addKey("E", Unmapped_Key, 0x02AF, 13);

  addKey("1", One_Key, 0x1281, 13);
  addKey("2", Two_Key, 0x1282, 13);
  addKey("3", Three_Key, 0x1283, 13);
  addKey("4", Four_Key, 0x1284, 13);
  addKey("5", Five_Key, 0x1285, 13);
  addKey("6", Six_Key, 0x1286, 13);
  addKey("7", Seven_Key, 0x1287, 13);
  addKey("8", Eight_Key, 0x1288, 13);
  addKey("9", Nine_Key, 0x1289, 13);
  addKey("0", Zero_Key, 0x1280, 13);
  addKey("Standby", Power_Key, 0x128C, 13);
  addKey("Info", Info_Key, 0x128F, 13);
  addKey("TV/Sat", Input_Key, 0x12A8, 13);
  addKey("Plus", Unmapped_Key, 0x12AF, 13);
}


GrundigSat2::GrundigSat2(
  unsigned int index)
  : PIRKeysetMetaData(
      "Satellite Keyset 2",
      Grundig_Make,
      TV_Panels,
      index)
{
  addControlledDevice(Grundig_Make, "STR 7100", Sat_Device);
}


void GrundigSat2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

  addKey("POWER", Power_Key, 0x017B, 13);
  addKey("Audio", Audio_Key, 0x00D3, 13);
  addKey(">|", StepForward_Key, 0x008B, 13);
  addKey("|<", StepBack_Key, 0x00BB, 13);
  addKey("1", One_Key, 0x00EB, 13);
  addKey("2", Two_Key, 0x016B, 13);
  addKey("3", Three_Key, 0x006B, 13);
  addKey("4", Four_Key, 0x01AB, 13);
  addKey("5", Five_Key, 0x00AB, 13);
  addKey("6", Six_Key, 0x012B, 13);
  addKey("7", Seven_Key, 0x002B, 13);
  addKey("8", Eight_Key, 0x01CB, 13);
  addKey("9", Nine_Key, 0x00CB, 13);
  addKey("0", Zero_Key, 0x01EB, 13);
  addKey("i", Info_Key, 0x0093, 13);  // "OSD"
  addKey("MUTE", Mute_Key, 0x00FB, 13);
  addKey("P+", ChannelUp_Key, 0x0153, 13);
  addKey("P-", ChannelDown_Key, 0x0053, 13);
  addKey("-", VolumeDown_Key, 0x00DB, 13);
  addKey("+", VolumeUp_Key, 0x01DB, 13);
  addKey("OK", Select_Key, 0x01FB, 13);
  addKey("AUX", AuxInput_Key, 0x003B, 13); // "DiscMenu"
  addKey("TXT", Teletext_Key, 0x01E3, 13);
  addKey("RED", Red_Key, 0x0143, 13);
  addKey("GREEN", Green_Key, 0x0103, 13);
  addKey("YELLOW", Yellow_Key, 0x0043, 13);
  addKey("BLUE", Blue_Key, 0x0113, 13);
  addKey("COL-", ColorDown_Key, 0x009B, 13);
  addKey("COL+", ColorUp_Key, 0x019B, 13);
  addKey("BRIGHT-", BrightnessDown_Key, 0x005B, 13);
  addKey("BRIGHT+", BrightnessUp_Key, 0x015B, 13);
  addKey("TV-G", Unmapped_Key, 0x01BB, 13);
}


GrundigSat3::GrundigSat3(
  unsigned int index)
  : PIRKeysetMetaData(
      "Satellite Keyset 3",
      Grundig_Make,
      TV_Panels,
      index)
{
}


void GrundigSat3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x80, 8);

  addKey("menu", Menu_Key, 0x12, 8);
  addKey("Ch-", ChannelDown_Key, 0x16, 8);
  addKey("3", Three_Key, 0x40, 8);
  addKey("2", Two_Key, 0x41, 8);
  addKey("1", One_Key, 0x42, 8);
  addKey("6", Six_Key, 0x44, 8);
  addKey("5", Five_Key, 0x45, 8);
  addKey("4", Four_Key, 0x46, 8);
  addKey("0", Zero_Key, 0x47, 8);
  addKey("9", Nine_Key, 0x48, 8);
  addKey("8", Eight_Key, 0x49, 8);
  addKey("7", Seven_Key, 0x4A, 8);
  addKey("mute", Mute_Key, 0x4C, 8);
  addKey("up", Up_Key, 0x4E, 8);
  addKey("sub", Captions_Key, 0x73, 8);
  addKey("OK", Select_Key, 0x75, 8);
  addKey("Yellow", Yellow_Key, 0x78, 8);
  addKey("text", Teletext_Key, 0x7B, 8);
  addKey("Vol-", VolumeDown_Key, 0x7D, 8);
  addKey("exit", Exit_Key, 0x7E, 8);
  addKey("AD", Unmapped_Key, 0x7F, 8);
  addKey("power", Power_Key, 0xB2, 8);
  addKey("TV/DTV", TunerInput_Key, 0xB7, 8);
  addKey("Guide", Guide_Key, 0xB8, 8);
  addKey("Info", Info_Key, 0xB9, 8);
  addKey("Green", Green_Key, 0xBA, 8);
  addKey("Red", Red_Key, 0xBB, 8);
  addKey("down", Down_Key, 0xBE, 8);
  addKey("right", Right_Key, 0xC4, 8);
  addKey("left", Left_Key, 0xC8, 8);
  addKey("Blue", Blue_Key, 0xCC, 8);
  addKey("wide", AspectRatio_Key, 0xCF, 8);
  addKey("back", PrevChannel_Key, 0xD2, 8);
  addKey("Vol+", VolumeUp_Key, 0xD4, 8);
  addKey("Ch List", Unmapped_Key, 0xD5, 8);
  addKey("Ch+", ChannelUp_Key, 0xD6, 8);
  addKey("Swap", Unmapped_Key, 0xD8, 8);
}


GrundigAmp1::GrundigAmp1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Amp Keyset 1",
      Grundig_Make,
      Receiver_Panels,
      index)
{
  addControlledDevice(Grundig_Make, "FineArts Amplifier V1", Audio_Device);
}


void GrundigAmp1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

  addKey("number_10", Zero_Key, 0x1C00, 13);
  addKey("number_1", One_Key, 0x1C01, 13);
  addKey("number_2", Two_Key, 0x1C02, 13);
  addKey("number_3", Three_Key, 0x1C03, 13);
  addKey("number_4", Four_Key, 0x1C04, 13);
  addKey("number_5", Five_Key, 0x1C05, 13);
  addKey("number_6", Six_Key, 0x1C06, 13);
  addKey("number_7", Seven_Key, 0x1C07, 13);
  addKey("number_8", Eight_Key, 0x1C08, 13);
  addKey("number_9", Nine_Key, 0x1C09, 13);
  addKey("mute", Mute_Key, 0x1C0D, 13);
  addKey("volume_+", VolumeUp_Key, 0x1C10, 13);
  addKey("volume_-", VolumeDown_Key, 0x1C11, 13);
  addKey("standby", Power_Key, 0x1C3D, 13);

  addKey("tuner_up", ChannelUp_Key, 0x1C60, 13);
  addKey("tuner_down", ChannelDown_Key, 0x1C61, 13);
  addKey("tuner", TunerInput_Key, 0x1C7F, 13);

  addKey("tape_play_back", Unmapped_Key, 0x1CAF, 13);
  addKey("tape_pause", Unmapped_Key, 0x1CB0, 13);
  addKey("tape_fastrewind", Unmapped_Key, 0x1CB2, 13);
  addKey("tape_fastforward", Unmapped_Key, 0x1CB4, 13);
  addKey("tape_play_forward", Unmapped_Key, 0x1CB5, 13);
  addKey("tape_stop", Unmapped_Key, 0x1CB6, 13);
  addKey("tape_record", Unmapped_Key, 0x1CB7, 13);
  addKey("tape", TapeInput_Key, 0x1CBF, 13);

  addKey("cd_fastforward", FastForward_Key, 0x1D20, 13);
  addKey("cd_fastrewind", Rewind_Key, 0x1D21, 13);
  addKey("cd_pause", Pause_Key, 0x1D30, 13);
  addKey("cd_play", Play_Key, 0x1D35, 13);
  addKey("cd_stop", Stop_Key, 0x1D36, 13);
  addKey("cd", CDInput_Key, 0x1D3F, 13);

  addKey("phono", PhonoInput_Key, 0x1D7F, 13);

  addKey("dsr_up", Unmapped_Key, 0x1DA0, 13);
  addKey("dsr_down", Unmapped_Key, 0x1DA1, 13);
  addKey("dsr_aux", SatInput_Key, 0x1DBF, 13);

  addKey("dcc_play_back", Unmapped_Key, 0x1DEF, 13);
  addKey("dcc_pause", Unmapped_Key, 0x1DF0, 13);
  addKey("dcc_fastrewind", Unmapped_Key, 0x1DF2, 13);
  addKey("dcc_fastforward", Unmapped_Key, 0x1DF4, 13);
  addKey("dcc_play_forward", Unmapped_Key, 0x1DF5, 13);
  addKey("dcc_stop", Unmapped_Key, 0x1DF6, 13);
  addKey("dcc_record", Unmapped_Key, 0x1DF7, 13);
  addKey("dcc", MDInput_Key, 0x1DFF, 13); // Bit of a hack
}


void GrundigAmp1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("Tuner", QVariant(TunerInput_Key));
  cb->addItem("Tape", QVariant(TapeInput_Key));
  cb->addItem("CD", QVariant(CDInput_Key));
  cb->addItem("Phono", QVariant(PhonoInput_Key));
  cb->addItem("Digital Satellite Radio", QVariant(SatInput_Key));
  cb->addItem("Digital Compact Cassette", QVariant(MDInput_Key));
}


GrundigAudio1::GrundigAudio1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio(CD) Keyset 1",
      Grundig_Make,
      MediaControl_Panels,
      index)
{
  addControlledDevice(Grundig_Make, "CD 8400", Audio_Device);
}


void GrundigAudio1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

  addKey("0", Zero_Key, 0x1D00, 13);
  addKey("1", One_Key, 0x1D01, 13);
  addKey("2", Two_Key, 0x1D02, 13);
  addKey("3", Three_Key, 0x1D03, 13);
  addKey("4", Four_Key, 0x1D04, 13);
  addKey("5", Five_Key, 0x1D05, 13);
  addKey("6", Six_Key, 0x1D06, 13);
  addKey("7", Seven_Key, 0x1D07, 13);
  addKey("8", Eight_Key, 0x1D08, 13);
  addKey("9", Nine_Key, 0x1D09, 13);
  addKey("10+", DoubleDigit_Key, 0x1D0A, 13); // hack
  addKey("20+", PlusOneHundred_Key, 0x1D0B, 13); // also hack

  addKey("repeat", Repeat_Key, 0x1D1D, 13);

  addKey("track+", Next_Key, 0x1D20, 13);
  addKey("track-", Previous_Key, 0x1D21, 13);
  addKey("index+", Unmapped_Key, 0x1D22, 13);
  addKey("index-", Unmapped_Key, 0x1D23, 13);
  addKey("store", Memory_Key, 0x1D29, 13);
  addKey("scan", Scan_Key, 0x1D2B, 13);

  addKey("pause", Pause_Key, 0x1D30, 13);
  addKey("skip-", Replay_Key, 0x1D32, 13);
  addKey("skip+", Advance_Key, 0x1D34, 13);
  addKey("play", Play_Key, 0x1D35, 13);
  addKey("stop", Stop_Key, 0x1D36, 13);
}


GrundigAudio2::GrundigAudio2(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 2",
      Grundig_Make,
      Receiver_Panels,
      index)
{
  addControlledDevice(Grundig_Make, "CDM 700", Audio_Device);
  addControlledDevice(Grundig_Make, "UMS-9V", Audio_Device);
}


void GrundigAudio2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECXProtocol(guiObject, index, true);

  setPreData(0xA2A2, 16);

  addKey("1", One_Key, 0x01, 8);
  addKey("5", Five_Key, 0x02, 8);
  addKey("9", Nine_Key, 0x03, 8);
  addKey("tuning_down", ChannelDown_Key, 0x04, 8);
  addKey("display", Info_Key, 0x05, 8); // "MODE_remain
  addKey("on/off", Power_Key, 0x06, 8);
  addKey("tuner", TunerInput_Key, 0x07, 8);
  addKey("2", Two_Key, 0x09, 8);
  addKey("6", Six_Key, 0x0A, 8);
  addKey("0", Zero_Key, 0x0B, 8);
  addKey("tuning_up", ChannelUp_Key, 0x0C, 8);
  addKey("random", Random_Key, 0x0D, 8);
  addKey("band", ToggleBand_Key, 0x0E, 8);
  addKey("cd", CDInput_Key, 0x0F, 8);

  addKey("3", Three_Key, 0x11, 8);
  addKey("7", Seven_Key, 0x12, 8);
  addKey("play/pause", Play_Key, 0x13, 8);
  addKey("play/pause", Pause_Key, 0x13, 8);
  addKey("time_program", Program_Key, 0x14, 8); // "MEMORY_clock"
  addKey("intro", Unmapped_Key, 0x15, 8);
  addKey("SLEEP", Sleep_Key, 0x17, 8);
  addKey("4", Four_Key, 0x19, 8);
  addKey("8", Eight_Key, 0x1A, 8);
  addKey("stop", Stop_Key, 0x1B, 8);
  addKey("repeat/scan", Repeat_Key, 0x1C, 8);
  addKey("repeat/scan", Scan_Key, 0x1C, 8);
  addKey("BASS", EnhancedBass_Key, 0x1D, 8);
  addKey("tape", TapeInput_Key, 0x1E, 8);
  addKey("TIMER", Timer_Key, 0x1F, 8);

  addKey("volume_up", VolumeUp_Key, 0x20, 8);
  addKey("volume_down", VolumeDown_Key, 0x60, 8);
  addKey("mute", Mute_Key, 0xA0, 8);
  addKey("+10", DoubleDigit_Key, 0xE0, 8);
}


void GrundigAudio2::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("Tuner", QVariant(TunerInput_Key));
  cb->addItem("CD", QVariant(CDInput_Key));
  cb->addItem("Tape", QVariant(TapeInput_Key));
}


GrundigVCR1::GrundigVCR1(
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      Grundig_Make,
      MediaControl_Panels | MediaRecord_Panels,
      index)
{
  addControlledDevice(Grundig_Make, "GV 437", VCR_Device);
}


void GrundigVCR1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

  addKey("SYSTEM", Menu_Key, 0x014A, 13);
  addKey("OK", Select_Key, 0x0157, 13);
  addKey("next", Next_Key, 0x0170, 13);
  addKey("previous", Previous_Key, 0x0171, 13);
  addKey("MONITOR", Unmapped_Key, 0x017A, 13);
  addKey("tuner", TunerInput_Key, 0x017D, 13);
  addKey("cass", Eject_Key, 0x017E, 13); // might be wrong

  addKey("0", Zero_Key, 0x1140, 13);
  addKey("1", One_Key, 0x1141, 13);
  addKey("2", Two_Key, 0x1142, 13);
  addKey("3", Three_Key, 0x1143, 13);
  addKey("4", Four_Key, 0x1144, 13);
  addKey("5", Five_Key, 0x1145, 13);
  addKey("6", Six_Key, 0x1146, 13);
  addKey("7", Seven_Key, 0x1147, 13);
  addKey("8", Eight_Key, 0x1148, 13);
  addKey("9", Nine_Key, 0x1149, 13);
  addKey("SELECT", Enter_Key, 0x114B, 13); // "selvps"
  addKey("standby", Power_Key, 0x114C, 13); // "OFF"
  addKey("tracking", AutoTracking_Key, 0x114E, 13);

  addKey("TIMER", Timer_Key, 0x115D, 13);

  // Just guessing at what + and - mean here:
  addKey("+", ChannelUp_Key, 0x1160, 13);
  addKey("-", ChannelDown_Key, 0x1161, 13);
  addKey("REW", Rewind_Key, 0x1165, 13);
  addKey("FF", FastForward_Key, 0x1166, 13);

  addKey("CLEAR", Clear_Key, 0x1171, 13);
  addKey("PLAY", Play_Key, 0x1175, 13);
  addKey("pausestop", Pause_Key, 0x1176, 13); // "STOP"
  addKey("pausestop", Stop_Key, 0x1176, 13); // "STOP"
  addKey("RECORD", Record_Key, 0x1177, 13);
  addKey("SP/LP", VHSSpeed_Key, 0x117A, 13);
}


GrundigVCR1a::GrundigVCR1a(
  unsigned int index)
  : GrundigVCR1(index)
{
  setKeysetName("VCR Keyset 1a");
}


void GrundigVCR1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  GrundigVCR1::populateProtocol(guiObject);

  addKey("INDEX", IndexSearch_Key, 0x0170, 13);
  addKey("PAUSE", Pause_Key, 0x1169, 13);
}


GrundigTV1::GrundigTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Grundig_Make,
      TV_Panels,
      index)
{
  addControlledDevice(Grundig_Make, "ST 55-908", TV_Device);
}


void GrundigTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

  addKey("leer", Unmapped_Key, 0x0000, 13);
  addKey("POWER", Power_Key, 0x017F, 13);
  addKey("1", One_Key, 0x00EF, 13);
  addKey("2", Two_Key, 0x016F, 13);
  addKey("3", Three_Key, 0x006F, 13);
  addKey("4", Four_Key, 0x01AF, 13);
  addKey("5", Five_Key, 0x00AF, 13);
  addKey("6", Six_Key, 0x012F, 13);
  addKey("7", Seven_Key, 0x002F, 13);
  addKey("8", Eight_Key, 0x1CF, 13);
  addKey("9", Nine_Key, 0x00CF, 13);
  addKey("0", Zero_Key, 0x01EF, 13);
  addKey("AUX2", Unmapped_Key, 0x014F, 13);
  addKey("BR+", BrightnessUp_Key, 0x015F, 13);
  addKey("BR-", BrightnessDown_Key, 0x005F, 13);
  addKey("COLOR+", ColorUp_Key, 0x019F, 13);
  addKey("COLOR-", ColorDown_Key, 0x009F, 13);
  addKey("AUX", AuxInput_Key, 0x003F, 13);
  addKey("I", Info_Key, 0x0097, 13); // "Info"
  addKey("TXT", Teletext_Key, 0x01E7, 13);
  addKey("P+", ChannelUp_Key, 0x0157, 13);
  addKey("P+", Up_Key, 0x0157, 13);
  addKey("VOL-", VolumeDown_Key, 0x00DF, 13);
  addKey("VOL-", Left_Key, 0x00DF, 13);
  addKey("OK", Select_Key, 0x01FF, 13);
  addKey("VOL+", VolumeUp_Key, 0x01DF, 13);
  addKey("VOL+", Right_Key, 0x01DF, 13);
  addKey("P-", ChannelDown_Key, 0x0057, 13);
  addKey("P-", Down_Key, 0x0057, 13);
  addKey("MUTE", Mute_Key, 0x00FF, 13);
  addKey("BLUE", Blue_Key, 0x0117, 13);
  addKey("YELLOW", Yellow_Key, 0x0047, 13);
  addKey("GREEN", Green_Key, 0x0107, 13);
  addKey("RED", Red_Key, 0x0147, 13);
}


GrundigTV2::GrundigTV2(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 2",
      Grundig_Make,
      TV_Panels,
      index)
{
}


void GrundigTV2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

  addKey("P+", ChannelUp_Key, 0x0010, 13);
  addKey("P+", Up_Key, 0x0010, 13);
  addKey("P-", ChannelDown_Key, 0x0011, 13);
  addKey("P-", Down_Key, 0x0011, 13);
  addKey("info", Info_Key, 0x0012, 13);
  addKey("<-", VolumeDown_Key, 0x0015, 13);
  addKey("<-", Left_Key, 0x0015, 13);
  addKey("+>", VolumeUp_Key, 0x0016, 13);
  addKey("+>", Right_Key, 0x0016, 13);
  addKey("OK", Select_Key, 0x0017, 13);

  addKey("NEXT", Next_Key, 0x0170, 13);
  addKey("PREV", Previous_Key, 0x0171, 13);

  addKey("0AV", Zero_Key, 0x1000, 13); // also AV?
  addKey("1", One_Key, 0x1001, 13);
  addKey("2", Two_Key, 0x1002, 13);
  addKey("3", Three_Key, 0x1003, 13);
  addKey("4", Four_Key, 0x1004, 13);
  addKey("5", Five_Key, 0x1005, 13);
  addKey("6", Six_Key, 0x1006, 13);
  addKey("7", Seven_Key, 0x1007, 13);
  addKey("8", Eight_Key, 0x1008, 13);
  addKey("9", Nine_Key, 0x1009, 13);
  addKey("power", Power_Key, 0x100C, 13);
  addKey("mute", Mute_Key, 0x100D, 13);

  addKey("br+", BrightnessUp_Key, 0x1012, 13);
  addKey("br-", BrightnessDown_Key, 0x1013, 13);
  addKey("col+", ColorUp_Key, 0x1014, 13);
  addKey("col-", ColorDown_Key, 0x1015, 13);

  addKey("PC/CL", Unmapped_Key, 0x1031, 13);

  addKey("TXT", Teletext_Key, 0x115D, 13);
  addKey("<<", Rewind_Key, 0x1165, 13);
  addKey(">>", FastForward_Key, 0x1166, 13);
  addKey("||", Pause_Key, 0x1169, 13);
  addKey(">", Play_Key, 0x1175, 13);
  addKey("stop", Stop_Key, 0x1176, 13);
  addKey("REC", Record_Key, 0x1177, 13);
}


GrundigTV3::GrundigTV3(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV/VDR Keyset 3",
      Grundig_Make,
      TV_Panels | MediaControl_Panels | MediaRecord_Panels,
      index)
{
}


void GrundigTV3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

  addKey("USR4", Unmapped_Key, 0x0205, 13);
  addKey("INFO", Info_Key, 0x0206, 13);
  addKey("BACK", Exit_Key, 0x020F, 13);
  addKey("UP", Up_Key, 0x0210, 13);
  addKey("DOWN", Down_Key, 0x0211, 13);
  addKey("LEFT", Left_Key, 0x0215, 13);
  addKey("RIGHT", Right_Key, 0x0216, 13);
  addKey("OK", Select_Key, 0x0217, 13);

  addKey("RED", Red_Key, 0x022B, 13);
  addKey("GREEN", Green_Key, 0x022C, 13);
  addKey("YEL", Yellow_Key, 0x022D, 13);
  addKey("BLU", Blue_Key, 0x022E, 13);
  addKey("USR2", Unmapped_Key, 0x0235, 13);
  addKey("USR1", Unmapped_Key, 0x023E, 13);

  addKey("0", Zero_Key, 0x1200, 13);
  addKey("1", One_Key, 0x1201, 13);
  addKey("2", Two_Key, 0x1202, 13);
  addKey("3", Three_Key, 0x1203, 13);
  addKey("4", Four_Key, 0x1204, 13);
  addKey("5", Five_Key, 0x1205, 13);
  addKey("6", Six_Key, 0x1206, 13);
  addKey("7", Seven_Key, 0x1207, 13);
  addKey("8", Eight_Key, 0x1208, 13);
  addKey("9", Nine_Key, 0x1209, 13);

  addKey("MUTE", Mute_Key, 0x120D, 13);
  addKey("REC", Record_Key, 0x120E, 13);
  addKey("VOL+", VolumeUp_Key, 0x1210, 13);
  addKey("VOL-", VolumeDown_Key, 0x1211, 13);
  addKey("NEXT", Next_Key, 0x121E, 13);
  addKey("PREV", Previous_Key, 0x121F, 13);
  addKey("CHANNEL+", ChannelUp_Key, 0x1220, 13);
  addKey("CHANNEL-", ChannelDown_Key, 0x1221, 13);
  addKey("CEC", Unmapped_Key, 0x1222, 13);
  addKey("USR3", Unmapped_Key, 0x1223, 13);
  addKey("REW", Rewind_Key, 0x122C, 13);
  addKey("FF", FastForward_Key, 0x122E, 13);

  addKey("PAUSE", Pause_Key, 0x1230, 13);
  addKey("PLAY", Play_Key, 0x1235, 13);
  addKey("STOP", Stop_Key, 0x1236, 13);
  addKey("MENU", Menu_Key, 0x123C, 13);
}


GrundigTV4::GrundigTV4(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 4",
      Grundig_Make,
      TV_Panels,
      index)
{
}


void GrundigTV4::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new ProtonProtocol(guiObject, index);

  setPreData(0x1B, 8);

  addKey("vol-", VolumeDown_Key, 0x00, 8);
  addKey("vol+", VolumeUp_Key, 0x04, 8);
  addKey("exp", Unmapped_Key, 0x05, 8);
  addKey("tune", Unmapped_Key, 0x07, 8);
  addKey("mute", Mute_Key, 0x08, 8);
  addKey("text/mix", TeletextMix_Key, 0x09, 8);
  addKey("hold", TeletextHold_Key, 0x0A, 8);
  addKey("menu", Menu_Key, 0x0C, 8);
  addKey("0", Zero_Key, 0x0D, 8);
  addKey("tv", Input_Key, 0x0E, 8); // not sure
  addKey("7", Seven_Key, 0x10, 8);
  addKey("8", Eight_Key, 0x11, 8);
  addKey("9", Nine_Key, 0x12, 8);
  addKey("ch-", ChannelDown_Key, 0x13, 8);
  addKey("4", Four_Key, 0x14, 8);
  addKey("5", Five_Key, 0x15, 8);
  addKey("6", Six_Key, 0x16, 8);
  addKey("ch+", ChannelUp_Key, 0x17, 8);
  addKey("1", One_Key, 0x18, 8);
  addKey("2", Two_Key, 0x19, 8);
  addKey("3", Three_Key, 0x1A, 8);
  addKey("info", Info_Key, 0x1C, 8);
  addKey("store", Unmapped_Key, 0x1D, 8);
  addKey("power", Power_Key, 0x1F, 8);
}


GrundigDVD1::GrundigDVD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Grundig_Make,
      MediaControl_Panels,
      index)
{
  addControlledDevice(Grundig_Make, "GDV 130", DVD_Device);
}


void GrundigDVD1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x10, 8);

  addKey("POWER", Power_Key, 0x00, 8);
  addKey("FF_SF", FastForward_Key, 0x01, 8);
  addKey("OPEN_CLOSE", Eject_Key, 0x02, 8);
  addKey("ARROW_LEFT", Left_Key, 0x03, 8);
  addKey("STEP", StepForward_Key, 0x04, 8);
  addKey("PREV", Previous_Key, 0x05, 8);
  addKey("DISPLAY", Info_Key, 0x06, 8);
  addKey("NEXT", Next_Key, 0x07, 8);
  addKey("1", One_Key, 0x08, 8);
  addKey("2", Two_Key, 0x09, 8);
  addKey("3", Three_Key, 0x0A, 8);
  addKey("ARROW_UP", Up_Key, 0x0B, 8);
  addKey("FR_SR", Rewind_Key, 0x0C, 8);
  addKey("SETUP", Menu_Key, 0x0D, 8);
  addKey("TITLE", DiscTitle_Key, 0x0E, 8);
  addKey("MENU", DiscMenu_Key, 0x0F, 8);

  addKey("4", Four_Key, 0x10, 8);
  addKey("5", Five_Key, 0x11, 8);
  addKey("6", Six_Key, 0x12, 8);
  addKey("SELECT", Select_Key, 0x13, 8);
  addKey("DIGEST", Unmapped_Key, 0x14, 8);
  addKey("ANGLE", Angle_Key, 0x15, 8);
  addKey("SUBTITLE", Captions_Key, 0x16, 8);
  addKey("AUDIO", Audio_Key, 0x17, 8);
  addKey("7", Seven_Key, 0x18, 8);
  addKey("8", Eight_Key, 0x19, 8);
  addKey("9", Nine_Key, 0x1A, 8);
  addKey("ARROW_RIGHT", Right_Key, 0x1B, 8);
  addKey("PROGRAM", Program_Key, 0x1C, 8);
  addKey("VOLUME_UP", VolumeUp_Key, 0x1D, 8);
  addKey("ZOOM", Zoom_Key, 0x1E, 8);
  addKey("3D_SOUND", Surround_Key, 0x1F, 8);

  addKey("CLEAR", Clear_Key, 0x40, 8);
  addKey("0", Zero_Key, 0x41, 8);
  addKey("PCB", Unmapped_Key, 0x42, 8);
  addKey("ARROW_DOWN", Down_Key, 0x43, 8);
  addKey("SHUFFLE", Random_Key, 0x44, 8);
  addKey("VOLUME_DOWN", VolumeDown_Key, 0x45, 8);
  addKey("REPEAT", Repeat_Key, 0x46, 8);
  addKey("A-B", RepeatAB_Key, 0x47, 8);
  addKey("STOP/RETURN", Stop_Key, 0x48, 8);
  addKey("STOP/RETURN", Exit_Key, 0x48, 8);
  addKey("PLAY/PAUSE", Play_Key, 0x49, 8);
  addKey("PLAY/PAUSE", Pause_Key, 0x49, 8);
  addKey("MARKER", Unmapped_Key, 0x4A, 8);
}
