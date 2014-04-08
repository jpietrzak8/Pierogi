//
// cambridge.cpp
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

#include "cambridge.h"
#include "protocols/necprotocol.h"
#include "protocols/necxprotocol.h"
#include "protocols/rc5protocol.h"
#include <QComboBox>


CambridgeCD1::CambridgeCD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "CD Keyset 1",
      Cambridge_Make,
      index)
{
}


void CambridgeCD1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x4D84, 16);

  addKey("RANDOM", Random_Key, 0x00, 8);
  addKey("REPEAT", Repeat_Key, 0x01, 8);
  addKey("REMAIN", Unmapped_Key, 0x02, 8);
  addKey("PROG", Program_Key, 0x03, 8);
  addKey("INTRO", Unmapped_Key, 0x04, 8);
  addKey("SPACE", Unmapped_Key, 0x05, 8);
  addKey("A<>B", RepeatAB_Key, 0x06, 8);
  addKey("1", One_Key, 0x09, 8);
  addKey("<<", Rewind_Key, 0x0A, 8);
  addKey("PAUSE", Pause_Key, 0x0B, 8);
  addKey("4", Four_Key, 0x0D, 8);
  addKey("|<<", Previous_Key, 0x0E, 8);
  addKey("STOP", Stop_Key, 0x0F, 8);

  addKey("OPEN/CLOSE", Eject_Key, 0x10, 8);
  addKey("7", Seven_Key, 0x11, 8);
  addKey("10", Zero_Key, 0x12, 8);
  addKey("PLAY", Play_Key, 0x13, 8);
  addKey("8", Eight_Key, 0x15, 8);
  addKey("+10", DoubleDigit_Key, 0x16, 8);
  addKey("9", Nine_Key, 0x17, 8);
  addKey("5", Five_Key, 0x19, 8);
  addKey(">>|", Next_Key, 0x1A, 8);
  addKey("6", Six_Key, 0x1B, 8);
  addKey("2", Two_Key, 0x1D, 8);
  addKey(">>", FastForward_Key, 0x1E, 8);
  addKey("3", Three_Key, 0x1F, 8);
}


CambridgeAudio1::CambridgeAudio1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 1",
      Cambridge_Make,
      index)
{
}


void CambridgeAudio1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECXProtocol(guiObject, index, true);

  setPreData(0xA0A0, 16);

  addKey("1", One_Key, 0x01, 8);
  addKey("5", Five_Key, 0x02, 8);
  addKey("9", Nine_Key, 0x03, 8);
  addKey("rew", Rewind_Key, 0x04, 8);
  addKey("prev", Previous_Key, 0x05, 8);
  addKey("intro", Unmapped_Key, 0x06, 8);
  addKey("eject", Eject_Key, 0x07, 8);
  addKey("2", Two_Key, 0x09, 8);
  addKey("6", Six_Key, 0x0A, 8);
  addKey("0", Zero_Key, 0x0B, 8);
  addKey("fwd", FastForward_Key, 0x0C, 8);
  addKey("next", Next_Key, 0x0D, 8);
  addKey("rnd", Random_Key, 0x0E, 8);
  addKey("remain", Unmapped_Key, 0x0F, 8);

  addKey("3", Three_Key, 0x11, 8);
  addKey("7", Seven_Key, 0x12, 8);
  addKey("onetwodash", DoubleDigit_Key, 0x13, 8);
  addKey("play", Play_Key, 0x15, 8);
  addKey("repeat", Repeat_Key, 0x16, 8);
  addKey("ab", RepeatAB_Key, 0x17, 8);
  addKey("4", Four_Key, 0x19, 8);
  addKey("8", Eight_Key, 0x1A, 8);
  addKey("prog", Program_Key, 0x1B, 8);
  addKey("stop", Stop_Key, 0x1C, 8);
  addKey("pause", Pause_Key, 0x1D, 8);
  addKey("skip", NextDisc_Key, 0x1E, 8);

  addKey("light", Info_Key, 0x47, 8);
}


CambridgeAudio2::CambridgeAudio2(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 2",
      Cambridge_Make,
      index)
{
}


void CambridgeAudio2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECXProtocol(guiObject, index, true);

  setPreData(0xC0C0, 16);

  addKey("SPK_SETUP", Unmapped_Key, 0x01, 8);
  addKey("PLII_NEO6", Unmapped_Key, 0x02, 8);
  addKey("VOLUME_UP", VolumeUp_Key, 0x03, 8);
  addKey("VOLUME_UP", Up_Key, 0x03, 8);
  addKey("DISPLAY", Info_Key, 0x04, 8);
  addKey("LEFT", Left_Key, 0x06, 8);
  addKey("TEST_TONE", Unmapped_Key, 0x07, 8);
  addKey("DSP_MODE", Unmapped_Key, 0x09, 8);
  addKey("BASS_TRIBLE", Unmapped_Key, 0x0A, 8);
  addKey("POWER", Power_Key, 0x0C, 8);
  addKey("CH_SELECT", Unmapped_Key, 0x0D, 8);
  addKey("STEREO_MONO", Audio_Key, 0x0E, 8);
  addKey("6.1_DIRECT", Unmapped_Key, 0x0F, 8);

  addKey("I-O", Unmapped_Key, 0x11, 8);
  addKey("SUB_ON_OFF", Unmapped_Key, 0x12, 8);
  addKey("DYNAMIC", Unmapped_Key, 0x13, 8);
  addKey("MUTE", Mute_Key, 0x14, 8);
  addKey("RIGHT", Right_Key, 0x15, 8);
  addKey("PTY", Unmapped_Key, 0x16, 8);
  addKey("DDEX_DTSES", Unmapped_Key, 0x17, 8);
  addKey("STEREO", Unmapped_Key, 0x1A, 8);
  addKey("APS", Unmapped_Key, 0x1B, 8);
  addKey("TUNER_AM_FM", TunerInput_Key, 0x1C, 8);
  addKey("STORE", Memory_Key, 0x1D, 8);
  addKey("MODE", Mode_Key, 0x1E, 8);
  addKey("VOLUME_DOWN", VolumeDown_Key, 0x1F, 8);
  addKey("VOLUME_DOWN", Down_Key, 0x1F, 8);
  addKey("LFE_TRIM", Unmapped_Key, 0x20, 8);
  addKey("ENTER", Select_Key, 0x21, 8);

  addKey("DVD", DVDInput_Key, 0x22, 8);
  addKey("VIDEO1", CompositeInput_Key, 0x23, 8);
  addKey("VIDEO2", Composite2Input_Key, 0x24, 8);
  addKey("VIDEO3", SVideoInput_Key, 0x25, 8); // bit of a hack
  addKey("TAPE_MD_CDR", TapeInput_Key, 0x26, 8);
  addKey("CD_AUX", AuxInput_Key, 0x27, 8);

  addKey("INPUT_MODE", Unmapped_Key, 0x60, 8);
  addKey("DELAY", Unmapped_Key, 0xA0, 8);
}


void CambridgeAudio2::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("AM / FM Toggle", QVariant(TunerInput_Key));
  cb->addItem("DVD", QVariant(DVDInput_Key));
  cb->addItem("Video 1", QVariant(CompositeInput_Key));
  cb->addItem("Video 2", QVariant(Composite2Input_Key));
  cb->addItem("Video 3", QVariant(SVideoInput_Key));
  cb->addItem("Tape / MD / CDR", QVariant(TapeInput_Key));
  cb->addItem("CD / Aux", QVariant(AuxInput_Key));
}


CambridgeAudio3::CambridgeAudio3(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 3",
      Cambridge_Make,
      index)
{
}


void CambridgeAudio3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

  addKey("Tape_Mon", TapeInput_Key, 0x1400, 13);
  addKey("DVD", DVDInput_Key, 0x1401, 13);
  addKey("AV_MD", MDInput_Key, 0x1402, 13);
  addKey("Tuner_DAB", TunerInput_Key, 0x1403, 13);
  addKey("Aux_Phono", AuxInput_Key, 0x1404, 13);
  addKey("CD", CDInput_Key, 0x1405, 13);
  addKey("Standby", Power_Key, 0x140C, 13);
  addKey("Mute", Mute_Key, 0x140D, 13);
  addKey("Power_On", PowerOn_Key, 0x140E, 13);
  addKey("Power_Off", PowerOff_Key, 0x140F, 13);
  addKey("Vol_Up", VolumeUp_Key, 0x1410, 13);
  addKey("Vol_Down", VolumeDown_Key, 0x1411, 13);
  addKey("Brightness", Unmapped_Key, 0x1412, 13); // dimmer?
  addKey("Source_Up", Unmapped_Key, 0x1413, 13);
  addKey("Source_Down", Unmapped_Key, 0x1414, 13);
  addKey("Clip_Off", Unmapped_Key, 0x1415, 13);
  addKey("Clip_On", Unmapped_Key, 0x1416, 13);
  addKey("Mute_On", Unmapped_Key, 0x1432, 13);
  addKey("Mute_Off", Unmapped_Key, 0x1433, 13);
}


void CambridgeAudio3::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("CD", QVariant(CDInput_Key));
  cb->addItem("DVD", QVariant(DVDInput_Key));
  cb->addItem("Tuner / DAB", QVariant(TunerInput_Key));
  cb->addItem("Tape Monitor", QVariant(TapeInput_Key));
  cb->addItem("AV / MD", QVariant(MDInput_Key));
  cb->addItem("Aux / Phono", QVariant(AuxInput_Key));
}


CambridgeDVD1::CambridgeDVD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Cambridge_Make,
      index)
{
  addControlledDevice(Cambridge_Make, "DVD53", DVD_Device);
  addControlledDevice(Cambridge_Make, "DVD55", DVD_Device);
  addControlledDevice(Cambridge_Make, "DVD57", DVD_Device);
  addControlledDevice(Cambridge_Make, "DVD59B", DVD_Device);
}


void CambridgeDVD1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x07, 8);

  addKey("STANDBY", Power_Key, 0x01, 8);
  addKey("SF", Unmapped_Key, 0x04, 8);
  addKey("0", Zero_Key, 0x05, 8);
  addKey("EQ", Unmapped_Key, 0x06, 8);
  addKey("PAL/NTSC", Unmapped_Key, 0x07, 8);
  addKey("<<", Rewind_Key, 0x08, 8);
  addKey("1", One_Key, 0x09, 8);
  addKey(">>", FastForward_Key, 0x0A, 8);
  addKey("|<<", Previous_Key, 0x0B, 8);
  addKey("PSM", Unmapped_Key, 0x0C, 8);
  addKey("5", Five_Key, 0x0D, 8);
  addKey("REPEAT", Repeat_Key, 0x0E, 8);
  addKey("A-B", RepeatAB_Key, 0x0F, 8);

  addKey("SLOW", Slow_Key, 0x10, 8);
  addKey("9", Nine_Key, 0x11, 8);
  addKey("MODE", Mode_Key, 0x12, 8);
  addKey("MUTE", Mute_Key, 0x13, 8);
  addKey("PLAY", Play_Key, 0x14, 8);
  addKey("AUDIO", Audio_Key, 0x15, 8);
  addKey("PAUSE", Pause_Key, 0x16, 8);
  addKey("STOP", Stop_Key, 0x17, 8);
  addKey("TITLE", DiscTitle_Key, 0x19, 8);
  addKey("SETUP", Menu_Key, 0x1D, 8);

  addKey("EJECT", Eject_Key, 0x43, 8);
  addKey("OSD", Info_Key, 0x46, 8);
  addKey("2", Two_Key, 0x48, 8);
  addKey("3", Three_Key, 0x49, 8);
  addKey(">>|", Next_Key, 0x4A, 8);
  addKey("4", Four_Key, 0x4B, 8);
  addKey("6", Six_Key, 0x4C, 8);
  addKey("7", Seven_Key, 0x4D, 8);
  addKey("CLEAR", Clear_Key, 0x4E, 8);
  addKey("8", Eight_Key, 0x4F, 8);

  addKey("10+", DoubleDigit_Key, 0x51, 8);
  addKey("VOL-", VolumeDown_Key, 0x52, 8);
  addKey("GOTO", Unmapped_Key, 0x53, 8);
  addKey("SUBTITLE", Captions_Key, 0x54, 8);
  addKey("ANGLE", Angle_Key, 0x55, 8);
  addKey("VOL+", VolumeUp_Key, 0x56, 8);
  addKey("ZOOM", Zoom_Key, 0x57, 8);
  addKey("left", Left_Key, 0x58, 8);
  addKey("up", Up_Key, 0x59, 8);
  addKey("MENU", DiscMenu_Key,0x5B, 8);
  addKey("down", Down_Key, 0x5C, 8);
  addKey("SELECT", Select_Key, 0x5D, 8);
  addKey("right", Right_Key, 0x5E, 8);
  addKey("RETURN", Exit_Key, 0x5F, 8);
}
