//
// adb.cpp
//
// Copyright 2012 - 2014 by John Pietrzak (jpietrzak8@gmail.com)
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

#include "adb.h"
#include "protocols/mceprotocol.h"
#include "protocols/necprotocol.h"
#include "protocols/nokia32protocol.h"
#include "protocols/aiwaprotocol.h"
#include <QComboBox>

ADBSTB1::ADBSTB1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Receiver Keyset 1",
      ADB_Make,
      TV_Panels,
      index)
{
  addControlledDevice(ADB_Make, "I-CAN 2840C", Other_Device);
}


void ADBSTB1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new MCEProtocol(guiObject, index, 0x8059);

  setPreData(0x24, 7);

  addKey("num_0", Zero_Key, 0x00, 8);
  addKey("num_1", One_Key, 0x01, 8);
  addKey("num_2", Two_Key, 0x02, 8);
  addKey("num_3", Three_Key, 0x03, 8);
  addKey("num_4", Four_Key, 0x04, 8);
  addKey("num_5", Five_Key, 0x05, 8);
  addKey("num_6", Six_Key, 0x06, 8);
  addKey("num_7", Seven_Key, 0x07, 8);
  addKey("num_8", Eight_Key, 0x08, 8);
  addKey("num_9", Nine_Key, 0x09, 8);
  addKey("exit", Exit_Key, 0x0A, 8);
  addKey("Power", Power_Key, 0x0C, 8);
  addKey("CH+", ChannelUp_Key, 0x20, 8);
  addKey("CH-", ChannelDown_Key, 0x21, 8);
  addKey("Menu", Menu_Key, 0x54, 8);
  addKey("Last_ch", PrevChannel_Key, 0x55, 8);
  addKey("up_arrow", Up_Key, 0x58, 8);
  addKey("down_arrow", Down_Key, 0x59, 8);
  addKey("left_arrow", Left_Key, 0x5A, 8);
  addKey("right_arrow", Right_Key, 0x5B, 8);
  addKey("Select", Select_Key, 0x5C, 8);
  addKey("Info", Info_Key, 0xCB, 8);
  addKey("Guide", Guide_Key, 0xCC, 8);
  addKey("Interactive Menu", Unmapped_Key, 0xFB, 8);
}


ADBSTB2::ADBSTB2(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Receiver Keyset 2",
      ADB_Make,
      TV_Panels | MediaControl_Panels | MediaRecord_Panels,
      index)
{
  addControlledDevice(ADB_Make, "5720 CDX", Other_Device);
}


void ADBSTB2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x0E86, 16);

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
  addKey("exit", Exit_Key, 0x0A, 8);
  addKey("up arrow", Up_Key, 0x0B, 8);
  addKey("down arrow", Down_Key, 0x0C, 8);
  addKey("vol up", VolumeUp_Key, 0x0D, 8);
  addKey("vol down", VolumeDown_Key, 0x0E, 8);
  addKey("mute", Mute_Key, 0x0F, 8);
  addKey("channel up", ChannelUp_Key, 0x10, 8);
  addKey("menu", Menu_Key, 0x11, 8);
  addKey("power", Power_Key, 0x12, 8);
  addKey("program guide", Guide_Key, 0x13, 8);
  addKey("return", Exit_Key, 0x14, 8);
  addKey("select", Select_Key, 0x15, 8);
  addKey("red", Red_Key, 0x16, 8);
  addKey("green", Green_Key, 0x17, 8);
  addKey("yellow", Yellow_Key, 0x18, 8);
  addKey("blue", Blue_Key, 0x19, 8);
  addKey("channel down", ChannelDown_Key, 0x1A, 8);
  addKey("left arrow", Left_Key, 0x1B, 8);
  addKey("right arrow", Right_Key, 0x1C, 8);
  addKey("rewind", Rewind_Key, 0x1D, 8);
  addKey("My TV", Unmapped_Key, 0x1E, 8);
  addKey("record", Record_Key, 0x21, 8);
  addKey("play", Play_Key, 0x23, 8);
  addKey("pause", Pause_Key, 0x23, 8);
  addKey("stop", Stop_Key, 0x24, 8);
  addKey("fast fwd", FastForward_Key, 0x26, 8);
  addKey("Teletext", Teletext_Key, 0x27, 8);
  addKey("Settings", Unmapped_Key, 0x29, 8);
  addKey("On Demand", Unmapped_Key, 0x2A, 8);
  addKey("info", Info_Key, 0x2D, 8);
}


ADBSTB3::ADBSTB3(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Receiver Keyset 3",
      ADB_Make,
      TV_Panels | MediaControl_Panels | MediaRecord_Panels,
      index)
{
  addControlledDevice(ADB_Make, "7820sx", Other_Device);
}


void ADBSTB3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new MCEProtocol(guiObject, index, 0x8051);

  setPreData(0x11, 7);

  addKey("vod", Unmapped_Key, 0x01, 8);
  addKey("5", Five_Key, 0x20, 8);
  addKey("power", Power_Key, 0x21, 8);
  addKey("9", Nine_Key, 0x22, 8);
  addKey("select", Select_Key, 0x23, 8);
  addKey("down arrow", Down_Key, 0x24, 8);
  addKey("4", Four_Key, 0x28, 8);
  addKey("2", Two_Key, 0x29, 8);
  addKey("8", Eight_Key, 0x2A, 8);
  addKey("up arrow", Up_Key, 0x2B, 8);
  addKey("menu", Menu_Key, 0x2C, 8);
  addKey("green", Green_Key, 0x2D, 8);
  addKey("program guide", Guide_Key, 0x2E, 8);
  addKey("1", One_Key, 0x30, 8);
  addKey("7", Seven_Key, 0x32, 8);
  addKey("0", Zero_Key, 0x33, 8);
  addKey("left arrow", Left_Key, 0x34, 8);
  addKey("channel up", ChannelUp_Key, 0x35, 8);
  addKey("channel down", ChannelDown_Key, 0x37, 8);
  addKey("6", Six_Key, 0x38, 8);
  addKey("3", Three_Key, 0x39, 8);
  addKey("last (prev ch)", PrevChannel_Key, 0x3A, 8);
  addKey("right arrow", Right_Key, 0x3B, 8);
  addKey("display", Info_Key, 0x3C, 8);
  addKey("yellow", Yellow_Key, 0x3D, 8);
  addKey("red", Red_Key, 0x3E, 8);
  addKey("blue", Blue_Key, 0x3F, 8);
  addKey("record", Record_Key, 0x44, 8);
  addKey("play", Play_Key, 0x45, 8);
  addKey("pause", Pause_Key, 0x46, 8);
  addKey("stop", Stop_Key, 0x47, 8);
  addKey("rewind", Rewind_Key, 0x48, 8);
  addKey("fast fwd", FastForward_Key, 0x49, 8);
}


ADBSTB4::ADBSTB4(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Receiver Keyset 4",
      ADB_Make,
      TV_Panels,
      index)
{
  addControlledDevice(ADB_Make, "I-CAN 3000", Other_Device);
}


void ADBSTB4::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new Nokia32Protocol(guiObject, index);

  setPreData(0x2190, 16);
  setPostData(0x26, 7);

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
  addKey("Power", Power_Key, 0x0C, 8);
  addKey("Mute", Mute_Key, 0x0D, 8);
  addKey("Info", Info_Key, 0x0F, 8);
  addKey("VOL+", VolumeUp_Key, 0x10, 8);
  addKey("VOL-", VolumeDown_Key, 0x11, 8);
  addKey("CH+", ChannelUp_Key, 0x20, 8);
  addKey("CH-", ChannelDown_Key, 0x21, 8);
  addKey("Last_ch", PrevChannel_Key, 0x43, 8);
  addKey("up_arrow", Up_Key, 0x58, 8);
  addKey("down_arrow", Down_Key, 0x59, 8);
  addKey("left_arrow", Left_Key, 0x5A, 8);
  addKey("right_arrow", Right_Key, 0x5B, 8);
  addKey("Select", Select_Key, 0x5C, 8);
  addKey("Guide", Guide_Key, 0xCC, 8);
  addKey("Enter", Enter_Key, 0xDB, 8);
  addKey("exit", Exit_Key, 0xE0, 8);
}


ADBSTB5::ADBSTB5(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Receiver Keyset 5",
      ADB_Make,
      TV_Panels,
      index)
{
}


void ADBSTB5::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new AiwaProtocol(guiObject, index);

  setPreData(0x0008, 13);

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
  addKey("Menu", Menu_Key, 0x0A, 8);
//  addKey("Guide", Guide_Key, 0x0B, 8);
  addKey("Power", Power_Key, 0x0C, 8);
  addKey("Format 16:9", AspectRatio_Key, 0x0D, 8);
  addKey("Info/Display", Info_Key, 0x0D, 8);
//  addKey("Stop", Stop_Key, 0x0D, 8);
  addKey("CH+", ChannelUp_Key, 0x0E, 8);
  addKey("CH-", ChannelDown_Key, 0xF, 8);
  addKey("Volume +", VolumeUp_Key, 0x10, 8);
  addKey("Volume -", VolumeDown_Key, 0x11, 8);
  addKey("Arrow_Right", Right_Key, 0x12, 8);
//  addKey("FFWD", FastForward_Key, 0x13, 8);
  addKey("Guide", Guide_Key, 0x13, 8);
  addKey("EXIT", Exit_Key, 0x14, 8);
  addKey("Arrow_Left", Left_Key, 0x15, 8);
  addKey("OK/Select", Select_Key, 0x16, 8);
  addKey("Subtitle", Captions_Key, 0x18, 8);
  addKey("TV/RAD", TunerInput_Key, 0x19, 8);
  addKey("Mute", Mute_Key, 0x1A, 8);
  addKey("Input/Source", Input_Key, 0x1B, 8);
  addKey("Arrow_Down", Down_Key, 0x1C, 8);
  addKey("Arrow_Up", Up_Key, 0x1D, 8);
//  addKey("Play", Play_Key, 0x1E, 8);
//  addKey("Audio", Audio_Key, 0x1F, 8);
  addKey("Back", PrevChannel_Key, 0x1F, 8);
  addKey("Red", Red_Key, 0x20, 8);
  addKey("Green", Green_Key, 0x21, 8);
  addKey("Yellow", Yellow_Key, 0x22, 8);
  addKey("Blue", Blue_Key, 0x23, 8);
}


void ADBSTB5::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("Input Toggle", QVariant(Input_Key));
  cb->addItem("TV / Radio Toggle", QVariant(TunerInput_Key));
}


ADBSTB6::ADBSTB6(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Receiver Keyset 6",
      ADB_Make,
      TV_Panels,
      index)
{
}


void ADBSTB6::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x3C84, 16);

  addKey("5", Five_Key, 0x20, 8);
  addKey("power", Power_Key, 0x21, 8);
  addKey("9", Nine_Key, 0x22, 8);
  addKey("yes", Select_Key, 0x23, 8);
  addKey("down", Down_Key, 0x24, 8);
  addKey("mute", Mute_Key, 0x25, 8);
  addKey("vol+", VolumeUp_Key, 0x26, 8);
  addKey("vol-", VolumeDown_Key, 0x27, 8);
  addKey("4", Four_Key, 0x28, 8);
  addKey("2", Two_Key, 0x29, 8);
  addKey("8", Eight_Key, 0x2A, 8);
  addKey("up", Up_Key, 0x2B, 8);
  addKey("? (question)", Unmapped_Key, 0x2C, 8);
  addKey("green", Green_Key, 0x2D, 8);
  addKey("guide", Guide_Key, 0x2E, 8);
  addKey("10", Zero_Key, 0x2F, 8);
  addKey("1", One_Key, 0x30, 8);
  addKey("exit", Exit_Key, 0x31, 8);
  addKey("7", Seven_Key, 0x32, 8);
  addKey("0", Zero_Key, 0x33, 8);
  addKey("left", Left_Key, 0x34, 8);
  addKey("channel+", ChannelUp_Key, 0x35, 8);
  addKey("mosaic", PIP_Key, 0x36, 8);
  addKey("channel-", ChannelDown_Key, 0x37, 8);
  addKey("6", Six_Key, 0x38, 8);
  addKey("3", Three_Key, 0x39, 8);
  addKey("return", Enter_Key, 0x3A, 8);
  addKey("right", Right_Key, 0x3B, 8);
  addKey("+ (plus)", Unmapped_Key, 0x3C, 8);
  addKey("yellow", Yellow_Key, 0x3D, 8);
  addKey("orange", Red_Key, 0x3E, 8);
  addKey("blue", Blue_Key, 0x3F, 8);
  addKey("info", Info_Key, 0x40, 8);
  addKey("A", Unmapped_Key, 0x41, 8);
  addKey("B", Unmapped_Key, 0x42, 8);
  addKey("envelope", Unmapped_Key, 0x43, 8);
}
