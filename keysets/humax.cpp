//
// humax.cpp
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

#include "humax.h"
#include "protocols/necprotocol.h"
#include <QComboBox>


HumaxReceiver1::HumaxReceiver1(
  unsigned int index)
  : PIRKeysetMetaData(
      "STB Keyset 1",
      Humax_Make,
      index)
{
}


void HumaxReceiver1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x1000, 16);

  addKey("power", Power_Key, 0x00, 8);
  addKey("tvsat", Input_Key, 0x02, 8); // "SOURCE"
  addKey("1", One_Key, 0x03, 8);
  addKey("2", Two_Key, 0x04, 8);
  addKey("3", Three_Key, 0x05, 8);
  addKey("4", Four_Key, 0x06, 8);
  addKey("5", Five_Key, 0x07, 8);
  addKey("6", Six_Key, 0x08, 8);
  addKey("7", Seven_Key, 0x09, 8);
  addKey("8", Eight_Key, 0x0A, 8);
  addKey("9", Nine_Key, 0x0B, 8);
  addKey("0", Zero_Key, 0x0C, 8);
  addKey("tone", TunerInput_Key, 0x0D, 8); // "ton" "TV/RADIO"
  addKey("menu", Menu_Key, 0x0E, 8);
  addKey("p-", ChannelDown_Key, 0x0F, 8);

  addKey("p+", ChannelUp_Key, 0x10, 8);
  addKey("up", Up_Key, 0x11, 8);
  addKey("left", Left_Key, 0x12, 8);
  addKey("ok", Select_Key, 0x13, 8);
  addKey("right", Right_Key, 0x14, 8);
  addKey("down", Down_Key, 0x15, 8);
  addKey("exit", Exit_Key, 0x16, 8); // "gray"
  addKey("?", Unmapped_Key, 0x17, 8);
  addKey("mute", Mute_Key, 0x18, 8);
  addKey("time", Unmapped_Key, 0x19, 8); // "white"
  addKey("yellow", Yellow_Key, 0x1A, 8);
  addKey("epg", Guide_Key, 0x1B, 8);
  addKey("red", Red_Key, 0x1C, 8);
  addKey("green", Green_Key, 0x1D, 8);
  addKey("blue", Blue_Key, 0x1E, 8);
  addKey("vol+", VolumeUp_Key, 0x1F, 8);

  addKey("vol-", VolumeDown_Key, 0x40, 8);
  addKey("rcl", PrevChannel_Key, 0x41, 8); // might be wrong
  addKey("INFO", Info_Key, 0x43, 8);
  addKey("LIST", HDDInput_Key, 0x4D, 8);

  addKey("PLAY", Play_Key, 0x60, 8);
  addKey("REC", Record_Key, 0x61, 8);
  addKey("PAUSE", Pause_Key, 0x62, 8);
  addKey("STOP", Stop_Key, 0x63, 8);
  addKey("FFWD", FastForward_Key, 0x64, 8);
  addKey("REW", Rewind_Key, 0x65, 8);
}


void HumaxReceiver1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("TV-Sat", QVariant(Input_Key));
  cb->addItem("TV-Radio", QVariant(TunerInput_Key));
}


// Ugly!  Humax has two different keysets using the same device code. :(
HumaxReceiver2::HumaxReceiver2(
  unsigned int index)
  : PIRKeysetMetaData(
      "STB Keyset 2",
      Humax_Make,
      index)
{
}


void HumaxReceiver2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x1000, 16);

  addKey("power", Power_Key, 0x00, 8);
  addKey("tv", Input_Key, 0x02, 8);
  addKey("radio", TunerInput_Key, 0x03, 8);
  addKey("1", One_Key, 0x04, 8);
  addKey("2", Two_Key, 0x05, 8);
  addKey("3", Three_Key, 0x06, 8);
  addKey("display", Info_Key, 0x07, 8);
  addKey("4", Four_Key, 0x08, 8);
  addKey("5", Five_Key, 0x09, 8);
  addKey("6", Six_Key, 0x0A, 8);
  addKey("audio", Audio_Key, 0x0B, 8);
  addKey("7", Seven_Key, 0x0C, 8);
  addKey("8", Eight_Key, 0x0D, 8);
  addKey("9", Nine_Key, 0x0E, 8);
  addKey("mute", Mute_Key, 0x0F, 8);

  addKey("uhf", Unmapped_Key, 0x10, 8);
  addKey("0", Zero_Key, 0x11, 8);
  addKey("teletext", Teletext_Key, 0x12, 8);
  addKey("ok", Select_Key, 0x13, 8);
  addKey("reserved", Unmapped_Key, 0x14, 8);
  addKey("down", Down_Key, 0x15, 8);
  addKey("gray", Unmapped_Key, 0x16, 8);
  addKey("ch+", ChannelUp_Key, 0x17, 8);
  addKey("menu", Menu_Key, 0x18, 8);
  addKey("up", Up_Key, 0x19, 8);
  addKey("epg", Guide_Key, 0x1A, 8);
  addKey("ch-", ChannelDown_Key, 0x1B, 8);
  addKey("left", Left_Key, 0x1C, 8);
  addKey("ok", Select_Key, 0x1D, 8);
  addKey("right", Right_Key, 0x1E, 8);
  addKey("v+", VolumeUp_Key, 0x1F, 8);

  addKey("v-", VolumeDown_Key, 0x40, 8);
  addKey("down", Down_Key, 0x41, 8);
}


void HumaxReceiver2::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("TV-Sat", QVariant(Input_Key));
  cb->addItem("TV-Radio", QVariant(TunerInput_Key));
}


HumaxReceiver3::HumaxReceiver3(
  unsigned int index)
  : PIRKeysetMetaData(
      "STB Keyset 3",
      Humax_Make,
      index)
{
}


void HumaxReceiver3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x1702, 16);

  addKey("power", Power_Key, 0x00, 8);
  addKey("source", Input_Key, 0x02, 8);
  addKey("1", One_Key, 0x03, 8);
  addKey("2", Two_Key, 0x04, 8);
  addKey("3", Three_Key, 0x05, 8);
  addKey("4", Four_Key, 0x06, 8);
  addKey("5", Five_Key, 0x07, 8);
  addKey("6", Six_Key, 0x08, 8);
  addKey("7", Seven_Key, 0x09, 8);
  addKey("8", Eight_Key, 0x0A, 8);
  addKey("9", Nine_Key, 0x0B, 8);
  addKey("0", Zero_Key, 0x0C, 8);
  addKey("tv/radio", TunerInput_Key, 0x0D, 8);
  addKey("menu", Menu_Key, 0x0E, 8);

  addKey("up", Up_Key, 0x11, 8);
  addKey("left", Left_Key, 0x12, 8);
  addKey("ok", Select_Key, 0x13, 8);
  addKey("right", Right_Key, 0x14, 8);
  addKey("down", Down_Key, 0x15, 8);
  addKey("back", Exit_Key, 0x16, 8);
  addKey("mute", Mute_Key, 0x18, 8);
  addKey("yellow", Yellow_Key, 0x1A, 8);
  addKey("epg", Guide_Key, 0x1B, 8);
  addKey("red", Red_Key, 0x1C, 8);
  addKey("green", Green_Key, 0x1D, 8);
  addKey("blue", Blue_Key, 0x1E, 8);
  addKey("vol+", VolumeUp_Key, 0x1F, 8);

  addKey("vol-", VolumeDown_Key, 0x40, 8);
  addKey("last", PrevChannel_Key, 0x41, 8);
  addKey("info", Info_Key, 0x43, 8);
  addKey("pip", PIP_Key, 0x46, 8);
  addKey("movepip", PIPMove_Key, 0x48, 8);
  addKey("swappip", PIPSwap_Key, 0x47, 8);
  addKey("p+", ChannelUp_Key, 0x49, 8);
  addKey("p-", ChannelDown_Key, 0x4A, 8);
  addKey("list", HDDInput_Key, 0x4D, 8);
  addKey("sleep", Sleep_Key, 0x4E, 8);
  addKey("directory", Unmapped_Key, 0x4F, 8);

  addKey("play", Play_Key, 0x60, 8);
  addKey("slow", Slow_Key, 0x62, 8);
  addKey("rec", Record_Key, 0x61, 8);
  addKey("stop", Stop_Key, 0x63, 8);
  addKey("ffwd", FastForward_Key, 0x64, 8);
  addKey("rewind", Rewind_Key, 0x65, 8);
  addKey("instreplay", Replay_Key, 0x66, 8);
  addKey("goto", Unmapped_Key, 0x67, 8);
  addKey("pause", Pause_Key, 0x68, 8);
  addKey("pipch", PIPChannelUp_Key, 0x69, 8);
  addKey("setbookmark", Unmapped_Key, 0x6A, 8);
  addKey("listbookmarks", Unmapped_Key, 0x6B, 8);
}


void HumaxReceiver3::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("Source", QVariant(Input_Key));
  cb->addItem("List", QVariant(HDDInput_Key));
  cb->addItem("TV-Radio", QVariant(TunerInput_Key));
}
