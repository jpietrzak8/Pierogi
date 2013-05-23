//
// acer.cpp
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

#include "acer.h"
#include "protocols/necprotocol.h"

AcerTV1::AcerTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Acer_Make,
      index)
{
}

void AcerTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x6361, 16);

  addKey("pip", PIP_Key, 0x00, 8);
  addKey("on", Power_Key, 0x01, 8);
  addKey("chup", ChannelUp_Key, 0x02, 8);
  addKey("chdown", ChannelDown_Key, 0x03, 8);
  addKey("volup", VolumeUp_Key, 0x04, 8);
  addKey("voldown", VolumeDown_Key, 0x05, 8);
  addKey("display", Info_Key, 0x06, 8);
  addKey("wide", AspectRatio_Key, 0x07, 8);
  addKey("active", PIPPause_Key, 0x09, 8);
  addKey("size", TeletextSize_Key, 0x0B, 8);
  addKey("tv", Unmapped_Key, 0x0C, 8);
  addKey("position", PIPMove_Key, 0x0D, 8);
  addKey("swap", PIPSwap_Key, 0x0E, 8);
  addKey("index", Unmapped_Key, 0x0F, 8);

  addKey("sizemode", PIPSize_Key, 0x10, 8);
  addKey("one", One_Key, 0x11, 8);
  addKey("two", Two_Key, 0x12, 8);
  addKey("three", Three_Key, 0x13, 8);
  addKey("four", Four_Key, 0x14, 8);
  addKey("five", Five_Key, 0x15, 8);
  addKey("six", Six_Key, 0x16, 8);
  addKey("seven", Seven_Key, 0x17, 8);
  addKey("eight", Eight_Key, 0x18, 8);
  addKey("nine", Nine_Key, 0x19, 8);
  addKey("zero", Zero_Key, 0x1A, 8);
  addKey("recall", PrevChannel_Key, 0x1C, 8);
  addKey("mute", Mute_Key, 0x1E, 8);
  addKey("menu", Menu_Key, 0x1F, 8);

  addKey("sleep", Sleep_Key, 0x20, 8);
  addKey("srs", Surround_Key, 0x21, 8);
  addKey("av", Unmapped_Key, 0x22, 8);
  addKey("scart", ScartInput_Key, 0x23, 8);
  addKey("pc", PCInput_Key, 0x24, 8);
  addKey("enter", Enter_Key, 0x25, 8);
  addKey("zoom", Zoom_Key, 0x26, 8);
  addKey("mpx", Unmapped_Key, 0x27, 8);
  addKey("mix", TeletextMix_Key, 0x28, 8);
  addKey("subpage", Unmapped_Key, 0x29, 8); // Teletext something

  addKey("red", Red_Key, 0x3A, 8);
  addKey("green", Green_Key, 0x3B, 8);
  addKey("yellow", Yellow_Key, 0x3C, 8);
  addKey("blue", Blue_Key, 0x3D, 8);

  addKey("up", Up_Key, 0x40, 8);
  addKey("left", Left_Key, 0x41, 8);
  addKey("ok", Select_Key, 0x42, 8);
  addKey("right", Right_Key, 0x43, 8);
  addKey("down", Down_Key, 0x44, 8);
  addKey("hold", TeletextHold_Key, 0x46, 8);
  addKey("subtitle", Captions_Key, 0x49, 8);
  addKey("teletext", Teletext_Key, 0x4A, 8);
  addKey("reveal", TeletextReveal_Key, 0x4B, 8);

  addKey("ebutton", Unmapped_Key, 0x65, 8);
}


AcerPC1::AcerPC1(
  unsigned int index)
  : PIRKeysetMetaData(
      "PC Keyset 1",
      Acer_Make,
      index)
{
  addControlledDevice(Acer_Make, "Aspire 9500", Computer_Device);
  addControlledDevice(Acer_Make, "Aspire 9800", Computer_Device);
}


void AcerPC1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x2510, 16);

  addKey("arcade", Unmapped_Key, 0x00, 8);
  addKey("up", Up_Key, 0x01, 8);
  addKey("menu", Menu_Key, 0x02, 8);
  addKey("rewind", Rewind_Key, 0x06, 8);
  addKey("down", Down_Key, 0x07, 8);
  addKey("fastforward", FastForward_Key, 0x08, 8);
  addKey("channelup", ChannelUp_Key, 0x09, 8);
  addKey("stop", Stop_Key, 0x0A, 8);
  addKey("volumeup", VolumeUp_Key, 0x0B, 8);
  addKey("channeldown", ChannelDown_Key, 0x0C, 8);
  addKey("volumedown", VolumeDown_Key, 0x0D, 8);

  addKey("red", Red_Key, 0x10, 8);
  addKey("green", Green_Key, 0x11, 8);
  addKey("yellow", Yellow_Key, 0x12, 8);
  addKey("blue", Blue_Key, 0x13, 8);
  addKey("1", One_Key, 0x14, 8);
  addKey("2", Two_Key, 0x15, 8);
  addKey("3", Three_Key, 0x16, 8);
  addKey("teletext", Teletext_Key, 0x17, 8);
  addKey("4", Four_Key, 0x18, 8);
  addKey("5", Five_Key, 0x19, 8);
  addKey("6", Six_Key, 0x1A, 8);
  addKey("fullscreen", AspectRatio_Key, 0x1B, 8); // need a better key here
  addKey("7", Seven_Key, 0x1C, 8);
  addKey("8", Eight_Key, 0x1D, 8);
  addKey("9", Nine_Key, 0x1E, 8);
  addKey("capture", Unmapped_Key, 0x1F, 8);

  addKey("last", PrevChannel_Key, 0x40, 8);
  addKey("0", Zero_Key, 0x41, 8);
  addKey("mute", Mute_Key, 0x43, 8);
  addKey("back", Exit_Key, 0x44, 8);
  addKey("info", Info_Key, 0x45, 8);
  addKey("language", Audio_Key, 0x46, 8);
  addKey("subtitle", Captions_Key, 0x47, 8);
  addKey("scan", Scan_Key, 0x48, 8);
  addKey("sap", Unmapped_Key, 0x49, 8);
  addKey("angle", Angle_Key, 0x4A, 8);
  addKey("record", Record_Key, 0x4B, 8);
  addKey("livetv", LiveTV_Key, 0x4C, 8);
  addKey("power", Power_Key, 0x4D, 8);

  addKey("left", Left_Key, 0x50, 8);
  addKey("select", Select_Key, 0x51, 8);
  addKey("right", Right_Key, 0x52, 8);
  addKey("previous", Previous_Key, 0x53, 8);
  addKey("next", Next_Key, 0x54, 8);
  addKey("pause", Pause_Key, 0x55, 8);
  addKey("play", Play_Key, 0x56, 8);
  addKey("tvav", Input_Key, 0x5D, 8);
}
