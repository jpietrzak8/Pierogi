//
// kathrein.cpp
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

#include "kathrein.h"
#include "protocols/kathreinprotocol.h"
#include "protocols/nokia32protocol.h"
#include "protocols/mceprotocol.h"


KathreinSat1::KathreinSat1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Sat Keyset 1",
      Kathrein_Make,
      index)
{
}


void KathreinSat1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new KathreinProtocol(guiObject, index);

  setPreData(0x0, 4);

  addKey("ab", Unmapped_Key, 0x23, 8);
  addKey("f", Unmapped_Key, 0x9B, 8);
  addKey("off", PowerOff_Key, 0x25, 8);
  addKey("l", Unmapped_Key, 0x57, 8);
  addKey("mid", Unmapped_Key, 0x59, 8);
  addKey("i", Unmapped_Key, 0x19, 8);
  addKey("clock", Unmapped_Key, 0x21, 8);
  addKey("tv", Input_Key, 0x1F, 8);
  addKey("up", Up_Key, 0x2F, 8);
  addKey("dwn", Down_Key, 0x31, 8);
  addKey("ok", Select_Key, 0x1D, 8);
  addKey("vol-", VolumeDown_Key, 0x2D, 8);
  addKey("vol+", VolumeUp_Key, 0x2B, 8);
  addKey("mute", Mute_Key, 0x27, 8);
  addKey("stero", Audio_Key, 0x85, 8);
  addKey("r", Unmapped_Key, 0x1B, 8);
  addKey("0", Zero_Key, 0x01, 8);
  addKey("1", One_Key, 0x03, 8);
  addKey("2", Two_Key, 0x05, 8);
  addKey("3", Three_Key, 0x07, 8);
  addKey("4", Four_Key, 0x09, 8);
  addKey("5", Five_Key, 0x0B, 8);
  addKey("6", Six_Key, 0x0D, 8);
  addKey("7", Seven_Key, 0x0F, 8);
  addKey("8", Eight_Key, 0x11, 8);
  addKey("9", Nine_Key, 0x13, 8);
}


KathreinSat2::KathreinSat2(
  unsigned int index)
  : PIRKeysetMetaData(
      "Sat Keyset 2",
      Kathrein_Make,
      index)
{
}


void KathreinSat2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated
    return;
  }

  threadableProtocol = new Nokia32Protocol(guiObject, index);

  setPreData(0x2290, 16);
  setPostData(0x00, 7);

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
  addKey("power", Power_Key, 0x0C, 8);
  addKey("mute", Mute_Key, 0x0D, 8);
  addKey("+10{-/--}", DoubleDigit_Key, 0x0F, 8);

  addKey("vol+", VolumeUp_Key, 0x10, 8);
  addKey("vol-", VolumeDown_Key, 0x11, 8);
  addKey("ch+", ChannelUp_Key, 0x1E, 8);
  addKey("ch-", ChannelDown_Key, 0x1F, 8);

  addKey("FFWD", FastForward_Key, 0x20, 8);
  addKey("REW", Rewind_Key, 0x21, 8);
  addKey("pause", Pause_Key, 0x31, 8);
  addKey("B/STOP", Stop_Key, 0x31, 8);
  addKey("A", Record_Key, 0x37, 8); // "Record"
  addKey("PLAY", Play_Key, 0x38, 8);
  addKey("PAUSE", Pause_Key, 0x39, 8);
  addKey("rewind", Teletext_Key, 0x3C, 8); // "Teletext"

  addKey("C", Menu_Key, 0x54, 8); // "Menu"
  addKey("exit", Exit_Key, 0x55, 8);
  addKey("up", Up_Key, 0x58, 8);
  addKey("down", Down_Key, 0x59, 8);
  addKey("left", Left_Key, 0x5A, 8);
  addKey("right", Right_Key, 0x5B, 8);
  addKey("select", Select_Key, 0x5C, 8);

  addKey("ffwd", Red_Key, 0x6D, 8); // "Red"
  addKey("stop", Green_Key, 0x6E, 8); // "Green"
  addKey("record", Yellow_Key, 0x6F, 8); // "Yellow"
  addKey("auto", Blue_Key, 0x70, 8); // "Blue"

  addKey("menu", Guide_Key, 0xCC, 8); // "Guide"
}


KathreinSat3::KathreinSat3(
  unsigned int index)
  : PIRKeysetMetaData(
      "Sat Keyset 3",
      Kathrein_Make,
      index)
{
}


void KathreinSat3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new MCEProtocol(guiObject, index, 0x8046);

  setPreData(0x00, 7);

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
  addKey("Power", Power_Key, 0x0C, 8);
  addKey("Mute", Mute_Key, 0x0D, 8);
  addKey("Info", Info_Key, 0x0F, 8);

  addKey("VOL+", VolumeUp_Key, 0x10, 8);
  addKey("VOL-", VolumeDown_Key, 0x11, 8);
  addKey("CH+", ChannelUp_Key, 0x1E, 8);
  addKey("CH-", ChannelDown_Key, 0x1F, 8);

  addKey("ffwd", FastForward_Key, 0x20, 8);
  addKey("rewind", Rewind_Key, 0x21, 8);
  addKey("Stop", Stop_Key, 0x31, 8);
  addKey("Record", Record_Key, 0x37, 8);
  addKey("Play", Play_Key, 0x38, 8);
  addKey("Pause", Pause_Key, 0x39, 8);
  addKey("Teletext", Teletext_Key, 0x3C, 8);
  addKey("Archive", Unmapped_Key, 0x46, 8);

  addKey("Menu", Menu_Key, 0x54, 8);
  addKey("Last_ch", PrevChannel_Key, 0x55, 8);
  addKey("Exit", Exit_Key, 0x55, 8);
  addKey("up_arrow", Up_Key, 0x58, 8);
  addKey("down_arrow", Down_Key, 0x59, 8);
  addKey("left_arrow", Left_Key, 0x5A, 8);
  addKey("right_arrow", Right_Key, 0x5B, 8);
  addKey("Select", Select_Key, 0x5C, 8);

  addKey("Red", Red_Key, 0x6D, 8);
  addKey("Green", Green_Key, 0x6E, 8);
  addKey("Yellow", Yellow_Key, 0x6F, 8);
  addKey("Blue", Blue_Key, 0x70, 8);
  addKey("Help", Unmapped_Key, 0x81, 8);
  addKey("Guide", Guide_Key, 0xCC, 8);
  addKey("Media", Unmapped_Key, 0xD5, 8);
}
