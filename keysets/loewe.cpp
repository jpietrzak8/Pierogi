//
// loewe.cpp
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

#include "loewe.h"
#include "protocols/rc5protocol.h"
#include "protocols/necprotocol.h"
#include "protocols/rc6protocol.h"
#include <QComboBox>

LoeweTV1::LoeweTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Loewe_Make,
      TV_Panels,
      index)
{
}


void LoeweTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index, 0x40);

  addKey("Up", Up_Key, 0x20, 6);
  addKey("Up", ChannelUp_Key, 0x20, 6);
  addKey("Down", Down_Key, 0x21, 6);
  addKey("Down", ChannelDown_Key, 0x21, 6);
  addKey("Left", Left_Key, 0x11, 6);
  addKey("Right", Right_Key, 0x10, 6);
  addKey("Ok", Select_Key, 0x26, 6);
  addKey("Red", Red_Key, 0x1B, 6);
  addKey("Green", Green_Key, 0x1A, 6);
  addKey("Yellow", Yellow_Key, 0x2B, 6);
  addKey("Blue", Blue_Key, 0x28, 6);
  addKey("1", One_Key, 0x01, 6);
  addKey("2", Two_Key, 0x02, 6);
  addKey("3", Three_Key, 0x03, 6);
  addKey("4", Four_Key, 0x04, 6);
  addKey("5", Five_Key, 0x05, 6);
  addKey("6", Six_Key, 0x06, 6);
  addKey("7", Seven_Key, 0x07, 6);
  addKey("8", Eight_Key, 0x08, 6);
  addKey("9", Nine_Key, 0x09, 6);
  addKey("0", Zero_Key, 0x00, 6);
  addKey("T", Unmapped_Key, 0x3C, 6);
  addKey("M", Unmapped_Key, 0x0B, 6);
  addKey("E", Unmapped_Key, 0x3F, 6);
  addKey("I", Unmapped_Key, 0x27, 6);
  addKey("Power", Power_Key, 0x0C, 6);
  addKey("Mute", Mute_Key, 0x0D, 6);
  addKey("Video", PictureMode_Key, 0x23, 6);
  addKey("Audio", SoundMode_Key, 0x35, 6);
  addKey("PiP", PIP_Key, 0x0A, 6);
  addKey("V=", Unmapped_Key, 0x31, 6);
  addKey("Timer", Sleep_Key, 0x0F, 6);
}


LoeweVCR1::LoeweVCR1(
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      Loewe_Make,
      MediaControl_Panels | MediaRecord_Panels,
      index)
{
  addControlledDevice(Loewe_Make, "ViewVision 3600H", VCR_Device);
  addControlledDevice(Loewe_Make, "ViewVision 8500H", VCR_Device);
}


void LoeweVCR1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x6E, 8);

  addKey("POWER", Power_Key, 0x14, 8);
  addKey("SHOW", Unmapped_Key, 0x47, 8);
  addKey("1", One_Key, 0x05, 8);
  addKey("2", Two_Key, 0x06, 8);
  addKey("3", Three_Key, 0x07, 8);
  addKey("4", Four_Key, 0x0C, 8);
  addKey("5", Five_Key, 0x0D, 8);
  addKey("6", Six_Key, 0x0E, 8);
  addKey("7", Seven_Key, 0x0F, 8);
  addKey("8", Eight_Key, 0x1C, 8);
  addKey("9", Nine_Key, 0x1D, 8);
  addKey("0", Zero_Key, 0x04, 8);
  addKey("AV", CompositeInput_Key, 0x56, 8); // need to fix this
  addKey("MENU", Menu_Key, 0x16, 8);
  addKey("UP", Up_Key, 0x18, 8);
  addKey("UP", ChannelUp_Key, 0x18, 8);
  addKey("DOWN", Down_Key, 0x19, 8);
  addKey("DOWN", ChannelDown_Key, 0x19, 8);
  addKey("RIGHT", Right_Key, 0x90, 8);
  addKey("LEFT", Left_Key, 0x83, 8);
  addKey("OK", Select_Key, 0x8E, 8);
  addKey("STILL", Pause_Key, 0x0B, 8);
  addKey("REC", Record_Key, 0x09, 8);
  addKey("STOP", Stop_Key, 0x01, 8);
  addKey("REW", Rewind_Key, 0x02, 8);
  addKey("PLAY", Play_Key, 0x08, 8);
  addKey("FF", FastForward_Key, 0x03, 8);
  addKey("A/T", AutoTracking_Key, 0x5F, 8);
  addKey("TV", Input_Key, 0x15, 8);
  addKey("LP", VHSSpeed_Key, 0x48, 8);
  addKey("REST", Clock_Key, 0x4C, 8);
  addKey("VISS", IndexSearch_Key, 0x41, 8);
  addKey("MARK", IndexMark_Key, 0x50, 8);
  addKey("ERASE", IndexErase_Key, 0x42, 8);
  addKey("0000", Reset_Key, 0x4D, 8);
}


void LoeweVCR1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("TV", QVariant(Input_Key));
  cb->addItem("AV", QVariant(CompositeInput_Key));
}


LoeweDVD1::LoeweDVD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Loewe_Make,
      MediaControl_Panels,
      index)
{
}


void LoeweDVD1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new RC6Protocol(guiObject, index, 0x04);

  addKey("Up", Up_Key, 0x58, 8);
  addKey("Down", Down_Key, 0x59, 8);
  addKey("Left", Left_Key, 0x5A, 8);
  addKey("Right", Right_Key, 0x5B, 8);
  addKey("Ok", Select_Key, 0x5C, 8);
  addKey("Red", Red_Key, 0x21, 8);
  addKey("Green", Green_Key, 0x31, 8);
  addKey("Yellow", Yellow_Key, 0x2C, 8);
  addKey("Blue", Blue_Key, 0x20, 8);
  addKey("T", Unmapped_Key, 0x30, 8);
  addKey("M", Unmapped_Key, 0xD1, 8);
  addKey("E", Unmapped_Key, 0x83, 8);
  addKey("I", Unmapped_Key, 0x22, 8);
  addKey("1", One_Key, 0x01, 8);
  addKey("2", Two_Key, 0x02, 8);
  addKey("3", Three_Key, 0x03, 8);
  addKey("4", Four_Key, 0x04, 8);
  addKey("5", Five_Key, 0x05, 8);
  addKey("6", Six_Key, 0x06, 8);
  addKey("7", Seven_Key, 0x07, 8);
  addKey("8", Eight_Key, 0x08, 8);
  addKey("9", Nine_Key, 0x09, 8);
  addKey("0", Zero_Key, 0x00, 8);
  addKey("Power", Power_Key, 0x0C, 8);
  addKey("Video", PictureMode_Key, 0x4B, 8);
  addKey("Audio", SoundMode_Key, 0x4E, 8);
  addKey("Mute", Mute_Key, 0x0F, 8);
  addKey("Timer", Sleep_Key, 0xC8, 8);
  addKey("V=", Unmapped_Key, 0x1D, 8);
  addKey("PiP", PIP_Key, 0x85, 8);
}
