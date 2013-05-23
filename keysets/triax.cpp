//
// triax.cpp
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

#include "triax.h"
#include "protocols/rc5protocol.h"
#include "protocols/necprotocol.h"

TriaxSTB1::TriaxSTB1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Satellite Receiver 1",
      Triax_Make,
      index)
{
  addControlledDevice(Triax_Make, "DVB 40S", Other_Device);
}


void TriaxSTB1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

  addKey("Power", Power_Key, 0x128C, 13);
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
  addKey("Mute", Mute_Key, 0x0286, 13);
  addKey("Help", Unmapped_Key, 0x128F, 13);
  addKey("Left", Left_Key, 0x0295, 13);
  addKey("Right", Right_Key, 0x0296, 13);
  addKey("Up", Up_Key, 0x0290, 13);
  addKey("Down", Down_Key, 0x0291, 13);
  addKey("Guide", Guide_Key, 0x028F, 13);
  addKey("Menu", Menu_Key, 0x02AA, 13);
  addKey("TV/Sat", Input_Key, 0x12A8, 13);
  addKey("Plus", Unmapped_Key, 0x12AF, 13);
}


TriaxSTB2::TriaxSTB2(
  unsigned int index)
  : PIRKeysetMetaData(
      "Satellite Receiver 2",
      Triax_Make,
      index)
{
}


void TriaxSTB2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0xDF00, 16);

  addKey("f2", Unmapped_Key, 0x00, 8);
  addKey("3", Three_Key, 0x01, 8);
  addKey("channel up", ChannelUp_Key, 0x02, 8);
  addKey("menu", Menu_Key, 0x03, 8);
  addKey("2", Two_Key, 0x05, 8);
  addKey("satellite", Input_Key, 0x06, 8);
  addKey("1", One_Key, 0x09, 8);
  addKey("select", Select_Key, 0x0A, 8);
  addKey("vol down", VolumeDown_Key, 0x0B, 8);
  addKey("power", Power_Key, 0x0C, 8);
  addKey("vol up", VolumeUp_Key, 0x0D, 8);
  addKey("f1", Unmapped_Key, 0x0E, 8);
  addKey("f0", Unmapped_Key, 0x0F, 8);
  addKey("info", Info_Key, 0x10, 8);
  addKey("blue", Blue_Key, 0x10, 8);
  addKey("audio", Audio_Key, 0x14, 8);
  addKey("yellow", Yellow_Key, 0x14, 8);
  addKey("sleep", Sleep_Key, 0x18, 8);
  addKey("green", Green_Key, 0x18, 8);
  addKey("tv/radio", TunerInput_Key, 0x1A, 8);
  addKey("mosaic", PIP_Key, 0x1C, 8);
  addKey("red", Red_Key, 0x1C, 8);
  addKey("channel down", ChannelDown_Key, 0x1E, 8);
  addKey("right arrow", Right_Key, 0x40, 8);
  addKey("0", Zero_Key, 0x41, 8);
  addKey("9", Nine_Key, 0x42, 8);
  addKey("6", Six_Key, 0x43, 8);
  addKey("up arrow", Up_Key, 0x44, 8);
  addKey("teletext", Teletext_Key, 0x45, 8);
  addKey("8", Eight_Key, 0x46, 8);
  addKey("5", Five_Key, 0x47, 8);
  addKey("down arrow", Down_Key, 0x48, 8);
  addKey("exit", Exit_Key, 0x49, 8);
  addKey("7", Seven_Key, 0x4A, 8);
  addKey("4", Four_Key, 0x4B, 8);
  addKey("left arrow", Left_Key, 0x4C, 8);
  addKey("zoom", Zoom_Key, 0x50, 8);
  addKey("mute", Mute_Key, 0x55, 8);
  addKey("prev track", Previous_Key, 0x57, 8);
  addKey("last (prev ch)", PrevChannel_Key, 0x59, 8);
  addKey("next track", Next_Key, 0x5B, 8);
  addKey("fav", Favorites_Key, 0x5C, 8);
  addKey("program guide", Guide_Key, 0x5D, 8);
}


TriaxSTB2a::TriaxSTB2a(
  unsigned int index)
  : TriaxSTB2(index)
{
  setKeysetName("Satellite Receiver 2a");
}


void TriaxSTB2a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  TriaxSTB2::populateProtocol(guiObject);

  setPreData(0x6681, 16);
}


TriaxSTB3::TriaxSTB3(
  unsigned int index)
  : PIRKeysetMetaData(
      "Satellite Receiver 3",
      Triax_Make,
      index)
{
}


void TriaxSTB3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x7F00, 16);

  addKey("Power", Power_Key, 0x00, 8);
  addKey("3", Three_Key, 0x01, 8);
  addKey("2", Two_Key, 0x02, 8);
  addKey("1", One_Key, 0x03, 8);
//  addKey("Last/Prev Ch", PrevChannel_Key, 0x04, 8);
  addKey("EXIT", Exit_Key, 0x04, 8);
  addKey("6", Six_Key, 0x05, 8);
  addKey("5", Five_Key, 0x06, 8);
  addKey("4", Four_Key, 0x07, 8);
  addKey("OK/Select", Select_Key, 0x08, 8);
  addKey("9", Nine_Key, 0x09, 8);
  addKey("8", Eight_Key, 0x0A, 8);
  addKey("7", Seven_Key, 0x0B, 8);
  addKey("Arrow_Right", Right_Key, 0x0D, 8);
  addKey("0", Zero_Key, 0x0E, 8);
  addKey("Red", Red_Key, 0x0F, 8);
  addKey("Play", Play_Key, 0x0F, 8);
  addKey("Info", Info_Key, 0x10, 8);
  addKey("Stop", Stop_Key, 0x10, 8);
  addKey("Arrow_Left", Left_Key, 0x11, 8);
  addKey("Guide", Guide_Key, 0x12, 8);
  addKey("TV/Sat", Input_Key, 0x13, 8);
  addKey("Blue", Blue_Key, 0x13, 8);
  addKey("Mute", Mute_Key, 0x14, 8);
  addKey("Last/Prev Ch", PrevChannel_Key, 0x15, 8);
  addKey("PIP On/Off", PIP_Key, 0x16, 8);
  addKey("Yellow", Yellow_Key, 0x16, 8);
  addKey("Menu", Menu_Key, 0x19, 8);
  addKey("CH+", ChannelUp_Key, 0x1A, 8);
  addKey("Arrow_Up", Up_Key, 0x1A, 8);
  addKey("CH-", ChannelDown_Key, 0x1B, 8);
  addKey("Arrow_Down", Down_Key, 0x1B, 8);
  addKey("Subtitle", Captions_Key, 0x42, 8);
  addKey("Volume -", VolumeDown_Key, 0x44, 8);
  addKey("Volume +", VolumeUp_Key, 0x48, 8);
  addKey("Green", Green_Key, 0x49, 8);
}


TriaxSTB3a::TriaxSTB3a(
  unsigned int index)
  : TriaxSTB3(index)
{
  setKeysetName("Satellite Receiver 3a");
}


void TriaxSTB3a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  TriaxSTB3::populateProtocol(guiObject);

//  addKey("Stop", Stop_Key, 0x08, 8);
  addKey("FFWD", FastForward_Key, 0x0D, 8);
  addKey("Blue", Blue_Key, 0x10, 8);
//  addKey("Rewind", Rewind_Key, 0x11, 8);
  addKey("Replay", Replay_Key, 0x13, 8);
  addKey("Last/Prev Ch", PrevChannel_Key, 0x16, 8);
  addKey("Pause", Pause_Key, 0x1A, 8);
  addKey("Record", Record_Key, 0x43, 8);
  addKey("Rewind", Rewind_Key, 0x45, 8);
}


TriaxSTB4::TriaxSTB4(
  unsigned int index)
  : PIRKeysetMetaData(
      "Satellite Receiver 4",
      Triax_Make,
      index)
{
}


void TriaxSTB4::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x7F00, 16);

  addKey("Mute", Mute_Key, 0x00, 8);
  addKey("Rewind", Rewind_Key, 0x01, 8);
  addKey("Red", Red_Key, 0x01, 8);
  addKey("CH+", ChannelUp_Key, 0x02, 8);
  addKey("Arrow_Up", Up_Key, 0x02, 8);
//  addKey("Last/Prev Ch", PrevChannel_Key, 0x03, 8);
  addKey("EXIT", Exit_Key, 0x03, 8);
  addKey("Input/Source", Input_Key, 0x04, 8);
  addKey("Green", Green_Key, 0x04, 8);
  addKey("Volume +", VolumeUp_Key, 0x05, 8);
  addKey("Arrow_Right", Right_Key, 0x05, 8);
  addKey("Skip +", Next_Key, 0x05, 8);
  addKey("Ok/Select", Select_Key, 0x06, 8);
  addKey("Volume -", VolumeDown_Key, 0x07, 8);
  addKey("Arrow_Left", Left_Key, 0x07, 8);
  addKey("Skip -", Previous_Key, 0x07, 8);
  addKey("Last/Prev Ch", PrevChannel_Key, 0x08, 8);
  addKey("Pause", Pause_Key, 0x09, 8);
  addKey("Blue", Blue_Key, 0x09, 8);
  addKey("CH-", ChannelDown_Key, 0x0A, 8);
  addKey("Arrow_Down", Down_Key, 0x0A, 8);
  addKey("Yellow", Yellow_Key, 0x0D, 8);
  addKey("0", Zero_Key, 0x0E, 8);
  addKey("9", Nine_Key, 0x0F, 8);
  addKey("8", Eight_Key, 0x10, 8);
  addKey("7", Seven_Key, 0x11, 8);
  addKey("6", Six_Key, 0x12, 8);
  addKey("5", Five_Key, 0x13, 8);
  addKey("4", Four_Key, 0x14, 8);
  addKey("3", Three_Key, 0x15, 8);
  addKey("2", Two_Key, 0x16, 8);
  addKey("1", One_Key, 0x17, 8);
  addKey("Power", Power_Key, 0x18, 8);
  addKey("Play", Play_Key, 0x1A, 8);
  addKey("Info/Display", Info_Key, 0x1B, 8);
  addKey("Stop", Stop_Key, 0x1B, 8);
  addKey("Format 16:9", AspectRatio_Key, 0x1C, 8);
  addKey("FAV", Favorites_Key, 0x1C, 8);
  addKey("Menu", Menu_Key, 0x1D, 8);
  addKey("Guide", Guide_Key, 0x1E, 8);
}
