//
// dreambox.cpp
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

#include "dreambox.h"
#include "protocols/xmpprotocol.h"
#include "protocols/necprotocol.h"
#include <QComboBox>


DreamboxSat1::DreamboxSat1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Dreambox Keyset 1",
      Dreambox_Make,
      index)
{
}


void DreamboxSat1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new XMPProtocol(
    guiObject, index, 0x0, 0x0, 0x44, 0x1A, false);

  addXMPKey("0", Zero_Key, 0x00, 0x00);
  addXMPKey("1", One_Key, 0x01, 0x00);
  addXMPKey("2", Two_Key, 0x02, 0x00);
  addXMPKey("3", Three_Key, 0x03, 0x00);
  addXMPKey("4", Four_Key, 0x04, 0x00);
  addXMPKey("5", Five_Key, 0x05, 0x00);
  addXMPKey("6", Six_Key, 0x06, 0x00);
  addXMPKey("7", Seven_Key, 0x07, 0x00);
  addXMPKey("8", Eight_Key, 0x08, 0x00);
  addXMPKey("9", Nine_Key, 0x09, 0x00);
  addXMPKey("vol+", VolumeUp_Key, 0x0A, 0x00);
  addXMPKey("vol-", VolumeDown_Key, 0x0B, 0x00);
  addXMPKey("tv_stop", Input_Key, 0x0C, 0x00);
  addXMPKey("tv_stop", Stop_Key, 0x0C, 0x00);
  addXMPKey("bouquet+", ChannelUp_Key, 0x0D, 0x00);
  addXMPKey("bouquet-", ChannelDown_Key, 0x0E, 0x00);
  addXMPKey("power", Power_Key, 0x0F, 0x00);
  addXMPKey("dream (menu)", Menu_Key, 0x20, 0x00);
  addXMPKey("arrow up", Up_Key, 0x21, 0x00);
  addXMPKey("arrow down", Down_Key, 0x22, 0x00);
  addXMPKey("arrow left", Left_Key, 0x23, 0x00);
  addXMPKey("arrow right", Right_Key, 0x24, 0x00);
  addXMPKey("ok", Select_Key, 0x25, 0x00);
  addXMPKey("audio", SoundMode_Key, 0x26, 0x00);
  addXMPKey("video", PictureMode_Key, 0x27, 0x00);
  addXMPKey("info", Info_Key, 0x28, 0x00);
  addXMPKey("SHIFT-RED", Rewind_Key, 0x30, 0x00);
  addXMPKey("SHIFT-GREEN", Play_Key, 0x31, 0x00);
  addXMPKey("SHIFT-YELLOW", Pause_Key, 0x32, 0x00);
  addXMPKey("SHIFT-BLUE", FastForward_Key, 0x33, 0x00);
  addXMPKey("SHIFT-MUTE", Unmapped_Key, 0x34, 0x00);
  addXMPKey("SHIFT-RADIO", Record_Key, 0x35, 0x00);
  addXMPKey("red", Red_Key, 0x40, 0x00);
  addXMPKey("green", Green_Key, 0x41, 0x00);
  addXMPKey("yellow", Yellow_Key, 0x42, 0x00);
  addXMPKey("blue", Blue_Key, 0x43, 0x00);
  addXMPKey("mute", Mute_Key, 0x44, 0x00);
  addXMPKey("text", Teletext_Key, 0x45, 0x00);
  addXMPKey("forward >", Next_Key, 0x50, 0x00);
  addXMPKey("back <", Previous_Key, 0x51, 0x00);
  addXMPKey("lame! (esc)", Exit_Key, 0x52, 0x00);
  addXMPKey("radio", TunerInput_Key, 0x53, 0x00);
  addXMPKey("help", Guide_Key, 0x54, 0x00);
  addXMPKey("discrete_off", PowerOff_Key, 0xB4, 0x00);
  addXMPKey("discrete_on", PowerOn_Key, 0xE8, 0x00);
}


void DreamboxSat1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("TV (pause/play)", QVariant(Input_Key));
  cb->addItem("Radio", QVariant(TunerInput_Key));
}


DreamboxSat1a::DreamboxSat1a(
  unsigned int index)
  : DreamboxSat1(index)
{
  setKeysetName("Dreambox Keyset 1a");
}


void DreamboxSat1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  DreamboxSat1::populateProtocol(guiObject);

  addXMPKey("mute", Mute_Key, 0x0C, 0x00);
  addXMPKey("tv", Input_Key, 0x44, 0x00);
  addXMPKey("help", Guide_Key, 0x52, 0x00);
  addXMPKey("LAME", Exit_Key, 0x54, 0x00);
  addXMPKey("rewind", Rewind_Key, 0x55, 0x00);
  addXMPKey("play", Play_Key, 0x56, 0x00);
  addXMPKey("forward", FastForward_Key, 0x57, 0x00);
  addXMPKey("pause", Pause_Key, 0x58, 0x00);
  addXMPKey("stop", Stop_Key, 0x59, 0x00);
}


DreamboxSat1b::DreamboxSat1b(
  unsigned int index)
  : DreamboxSat1(index)
{
  setKeysetName("Dreambox Keyset 1b");
}


void DreamboxSat1b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  DreamboxSat1::populateProtocol(guiObject);

  addXMPKey("mute", Mute_Key, 0x0C, 0x00);
  addXMPKey("rewind", Rewind_Key, 0x40, 0x00);
  addXMPKey("play", Play_Key, 0x41, 0x00);
  addXMPKey("pause", Pause_Key, 0x42, 0x00);
  addXMPKey("forward", FastForward_Key, 0x43, 0x00);
  addXMPKey("tv", Input_Key, 0x44, 0x00);
  addXMPKey("PgUp", PageUp_Key, 0x50, 0x00);
  addXMPKey("PgDn", PageDown_Key, 0x51, 0x00);
  addXMPKey("record", Record_Key, 0x53, 0x00);
  addXMPKey("exit", Exit_Key, 0x54, 0x00);
}


DreamboxSat1c::DreamboxSat1c(
  unsigned int index)
  : DreamboxSat1(index)
{
  setKeysetName("Dreambox Keyset 1c");
}


void DreamboxSat1c::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  DreamboxSat1::populateProtocol(guiObject);

  addKey("rewind", Rewind_Key, 0x40, 0x00);
  addKey("play", Play_Key, 0x41, 0x00);
  addKey("pause", Pause_Key, 0x42, 0x00);
  addKey("forward", FastForward_Key, 0x43, 0x00);
  addKey("record", Record_Key, 0x53, 0x00);
  addKey("PowerOff", PowerOff_Key, 0x60, 0x00);
  addKey("PowerOn", PowerOn_Key, 0x61, 0x00);
}


DreamboxSat2::DreamboxSat2(
  unsigned int index)
  : PIRKeysetMetaData(
      "Dreambox Keyset 2",
      Dreambox_Make,
      index)
{
}


void DreamboxSat2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new XMPProtocol(
    guiObject, index, 0x3, 0x1, 0x44, 0x1A, false);

  addXMPKey("0", Zero_Key, 0x00, 0x00);
  addXMPKey("1", One_Key, 0x01, 0x00);
  addXMPKey("2", Two_Key, 0x02, 0x00);
  addXMPKey("3", Three_Key, 0x03, 0x00);
  addXMPKey("4", Four_Key, 0x04, 0x00);
  addXMPKey("5", Five_Key, 0x05, 0x00);
  addXMPKey("6", Six_Key, 0x06, 0x00);
  addXMPKey("7", Seven_Key, 0x07, 0x00);
  addXMPKey("8", Eight_Key, 0x08, 0x00);
  addXMPKey("9", Nine_Key, 0x09, 0x00);
  addXMPKey("vol+", VolumeUp_Key, 0x0A, 0x00);
  addXMPKey("vol-", VolumeDown_Key, 0x0B, 0x00);
  addXMPKey("tv_stop", Input_Key, 0x0C, 0x00);
  addXMPKey("bouquet+", ChannelUp_Key, 0x0D, 0x00);
  addXMPKey("bouquet-", ChannelDown_Key, 0x0E, 0x00);
  addXMPKey("power", Power_Key, 0x0F, 0x00);
  addXMPKey("dream (menu)", Menu_Key, 0x20, 0x00);
  addXMPKey("arrow up", Up_Key, 0x21, 0x00);
  addXMPKey("arrow down", Down_Key, 0x22, 0x00);
  addXMPKey("arrow left", Left_Key, 0x23, 0x00);
  addXMPKey("arrow right", Right_Key, 0x24, 0x00);
  addXMPKey("ok", Select_Key, 0x25, 0x00);
  addXMPKey("audio", SoundMode_Key, 0x26, 0x00);
  addXMPKey("video", PictureMode_Key, 0x27, 0x00);
  addXMPKey("info", Info_Key, 0x28, 0x00);
  addXMPKey("rewind", Rewind_Key, 0x30, 0x00);
  addXMPKey("play", Play_Key, 0x31, 0x00);
  addXMPKey("pause", Pause_Key, 0x31, 0x00);
  addXMPKey("forward", FastForward_Key, 0x33, 0x00);
  addXMPKey("stop", Stop_Key, 0x34, 0x00);
  addXMPKey("record", Record_Key, 0x35, 0x00);
  addXMPKey("red", Red_Key, 0x40, 0x00);
  addXMPKey("green", Green_Key, 0x41, 0x00);
  addXMPKey("yellow", Yellow_Key, 0x42, 0x00);
  addXMPKey("blue", Blue_Key, 0x43, 0x00);
  addXMPKey("mute", Mute_Key, 0x44, 0x00);
  addXMPKey("text", Teletext_Key, 0x45, 0x00);
  addXMPKey("PgUp", PageUp_Key, 0x50, 0x00);
  addXMPKey("PgDn", PageDown_Key, 0x51, 0x00);
  addXMPKey("exit", Exit_Key, 0x52, 0x00);
  addXMPKey("radio", TunerInput_Key, 0x53, 0x00);
  addXMPKey("help", Guide_Key, 0x54, 0x00);
//  addXMPKey("discrete_off", PowerOff_Key, 0xB4, 0x00);
//  addXMPKey("discrete_on", PowerOn_Key, 0xE8, 0x00);
}


void DreamboxSat2::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("TV (play/pause)", QVariant(Input_Key));
  cb->addItem("Radio", QVariant(TunerInput_Key));
}


DreamboxSat3::DreamboxSat3(
  unsigned int index)
  : PIRKeysetMetaData(
      "Dreambox Keyset 3",
      Dreambox_Make,
      index)
{
}


void DreamboxSat3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x32, 8);

  addKey("Power", Power_Key, 0x00, 8);
  addKey("num_1", One_Key, 0x01, 8);
  addKey("num_2", Two_Key, 0x02, 8);
  addKey("num_3", Three_Key, 0x03, 8);
  addKey("num_4", Four_Key, 0x04, 8);
  addKey("num_5", Five_Key, 0x05, 8);
  addKey("num_6", Six_Key, 0x06, 8);
  addKey("num_7", Seven_Key, 0x07, 8);
  addKey("num_8", Eight_Key, 0x08, 8);
  addKey("num_9", Nine_Key, 0x09, 8);
  addKey("Skip-", Previous_Key, 0x0A, 8);
  addKey("num_0", Zero_Key, 0x0B, 8);
  addKey("Skip+", Next_Key, 0x0C, 8);
  addKey("Audio", SoundMode_Key, 0x0E, 8);
  addKey("Info", Info_Key, 0x10, 8);
  addKey("up_arrow", Up_Key, 0x11, 8);
  addKey("Menu", Menu_Key, 0x12, 8);
  addKey("left_arrow", Left_Key, 0x13, 8);
  addKey("Select", Select_Key, 0x14, 8);
  addKey("right_arrow", Right_Key, 0x15, 8);
  addKey("down_arrow", Down_Key, 0x17, 8);
  addKey("PVR", HDDInput_Key, 0x18, 8);
  addKey("Vol+", VolumeUp_Key, 0x19, 8);
  addKey("Mute", Mute_Key, 0x1A, 8);
  addKey("Page-", PageDown_Key, 0x1B, 8);
  addKey("Vol-", VolumeDown_Key, 0x1C, 8);
  addKey("exit", Exit_Key, 0x1D, 8);
  addKey("Page+", PageUp_Key, 0x1E, 8);
  addKey("Red", Red_Key, 0x1F, 8);
  addKey("Green", Green_Key, 0x20, 8);
  addKey("Yellow", Yellow_Key, 0x21, 8);
  addKey("Blue", Blue_Key, 0x22, 8);
  addKey("rewind", Rewind_Key, 0x23, 8);
  addKey("Play", Play_Key, 0x24, 8);
  addKey("Pause", Pause_Key, 0x24, 8);
  addKey("Stop", Stop_Key, 0x25, 8);
  addKey("ffwd", FastForward_Key, 0x26, 8);
  addKey("TV", Input_Key, 0x27, 8);
  addKey("Radio", TunerInput_Key, 0x28, 8);
  addKey("Teletext", Teletext_Key, 0x29, 8);
  addKey("Record", Record_Key, 0x2A, 8);
}


void DreamboxSat3::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("TV", QVariant(Input_Key));
  cb->addItem("Radio", QVariant(TunerInput_Key));
  cb->addItem("PVR", QVariant(HDDInput_Key));
}


DreamboxSat4::DreamboxSat4(
  unsigned int index)
  : PIRKeysetMetaData(
      "Dreambox Keyset 4",
      Dreambox_Make,
      index)
{
}


void DreamboxSat4::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x0000, 16);

  addKey("channel up", ChannelUp_Key, 0x00, 8);
  addKey("up arrow", Up_Key, 0x00, 8);
  addKey("channel down", ChannelDown_Key, 0x01, 8);
  addKey("down arrow", Down_Key, 0x01, 8);
  addKey("right arrow", Right_Key, 0x02, 8);
  addKey("left arrow", Left_Key, 0x03, 8);
  addKey("menu", Menu_Key, 0x05, 8);
  addKey("exit", Exit_Key, 0x07, 8);
  addKey("power", Power_Key, 0x0A, 8);
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
  addKey("last (prev ch)", PrevChannel_Key, 0x1B, 8);
  addKey("program guide", Guide_Key, 0x1E, 8);
  addKey("select", Select_Key, 0x1F, 8);
  addKey("display", Info_Key, 0x40, 8);
}


DreamboxSat5::DreamboxSat5(
  unsigned int index)
  : PIRKeysetMetaData(
      "Dreambox Keyset 5",
      Dreambox_Make,
      index)
{
}


void DreamboxSat5::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x10, 8);

  addKey("9", Nine_Key, 0x02, 8);
  addKey("8", Eight_Key, 0x03, 8);
  addKey("last (prev ch)", PrevChannel_Key, 0x06, 8);
  addKey("0", Zero_Key, 0x07, 8);
  addKey("menu", Menu_Key, 0x0A, 8);
  addKey("channel up", ChannelUp_Key, 0x0B, 8);
  addKey("up arrow", Up_Key, 0x0B, 8);
  addKey("right arrow", Right_Key, 0x0E, 8);
  addKey("select", Select_Key, 0x0F, 8);
  addKey("exit", Exit_Key, 0x12, 8);
  addKey("channel down", ChannelDown_Key, 0x13, 8);
  addKey("down arrow", Down_Key, 0x13, 8);
  addKey("favourite", Favorites_Key, 0x16, 8);
  addKey("subtitle", Captions_Key, 0x17, 8);
  addKey("blue", Blue_Key, 0x1A, 8);
  addKey("yellow", Yellow_Key, 0x1B, 8);
  addKey("power", Power_Key, 0x40, 8);
  addKey("6", Six_Key, 0x41, 8);
  addKey("7", Seven_Key, 0x42, 8);
  addKey("2", Two_Key, 0x44, 8);
  addKey("5", Five_Key, 0x45, 8);
  addKey("tv/radio", Input_Key, 0x46, 8);
  addKey("1", One_Key, 0x48, 8);
  addKey("display", Info_Key, 0x4A, 8);
  addKey("3", Three_Key, 0x4C, 8);
  addKey("4", Four_Key, 0x4D, 8);
  addKey("left arrow", Left_Key, 0x4E, 8);
  addKey("program guide", Guide_Key, 0x52, 8);
  addKey("teletext", Teletext_Key, 0x54, 8);
  addKey("audio", SoundMode_Key, 0x56, 8);
  addKey("green", Green_Key, 0x58, 8);
  addKey("red", Red_Key, 0x5A, 8);
}
