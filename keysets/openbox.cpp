//
// openbox.cpp
//
// Copyright 2012 - 2015 by John Pietrzak (jpietrzak8@gmail.com)
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

#include "openbox.h"

#include "protocols/necprotocol.h"
#include <QComboBox>

OpenBoxSTB1::OpenBoxSTB1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Satellite Receiver 1",
      OpenBox_Make,
      TV_Panels | MediaControl_Panels | MediaRecord_Panels,
      index)
{
}


void OpenBoxSTB1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x3F80, 16);

//  addKey("play", Play_Key, 0x00, 8);
  addKey("Last_ch", PrevChannel_Key, 0x00, 8);
  addKey("Record", Record_Key, 0x02, 8);
  addKey("Page-", PageDown_Key, 0x03, 8);
  addKey("ffwd", FastForward_Key, 0x04, 8);
  addKey("Sleep", Sleep_Key, 0x05, 8);
  addKey("Stop", Stop_Key, 0x06, 8);
  addKey("Pause", Pause_Key, 0x07, 8);
  addKey("Play", Play_Key, 0x08, 8);
  addKey("TV/Radio", TunerInput_Key, 0x09, 8);
  addKey("rewind", Rewind_Key, 0x0A, 8);
  addKey("left arrow", Left_Key, 0x0B, 8);
  addKey("Vol-", VolumeDown_Key, 0x0B, 8);
  addKey("up arrow", Up_Key, 0x0C, 8);
  addKey("CH+", ChannelUp_Key, 0x0C, 8);
  addKey("right arrow", Right_Key, 0x0D, 8);
  addKey("Vol+", VolumeUp_Key, 0x0D, 8);
  addKey("down arrow", Down_Key, 0x0E, 8);
  addKey("CH-", ChannelDown_Key, 0x0E, 8);
  addKey("SlowBack", SlowMinus_Key, 0x0F, 8);
  addKey("exit", Exit_Key, 0x10, 8);
  addKey("select", Select_Key, 0x11, 8);
  addKey("menu", Menu_Key, 0x12, 8);
  addKey("DVRInfo", Unmapped_Key, 0x13, 8);
  addKey("Mute", Mute_Key, 0x14, 8);
  addKey("info", Info_Key, 0x15, 8);
  addKey("1", One_Key, 0x16, 8);
  addKey("2", Two_Key, 0x17, 8);
  addKey("3", Three_Key, 0x18, 8);
  addKey("4", Four_Key, 0x19, 8);
  addKey("5", Five_Key, 0x1A, 8);
  addKey("6", Six_Key, 0x1B, 8);
  addKey("7", Seven_Key, 0x1C, 8);
  addKey("8", Eight_Key, 0x1D, 8);
  addKey("9", Nine_Key, 0x1E, 8);
  addKey("0", Zero_Key, 0x1F, 8);
  addKey("Frame Adv", StepForward_Key, 0x40, 8);
  addKey("Yellow", Yellow_Key, 0x41, 8); // L3
//  addKey("sleep", Sleep_Key, 0x42, 8):
  addKey("Red", Red_Key, 0x42, 8); // L1
  addKey("TV/Sat", Input_Key, 0x43, 8);
  addKey("power", Power_Key, 0x44, 8);
  addKey("M/P", Unmapped_Key, 0x46, 8);
  addKey("Favourite", Favorites_Key, 0x47, 8);
  addKey("V-Format", Unmapped_Key, 0x49, 8);
  addKey("program guide", Guide_Key, 0x4A, 8);
  addKey("SubTitle", Captions_Key, 0x4B, 8);
  addKey("Teletext", Teletext_Key, 0x4C, 8);
  addKey("Blue", Unmapped_Key, 0x4D, 8); // L4
  addKey("Green", Unmapped_Key, 0x4E, 8); // L2
//  addKey("enter", Enter_Key, 0x4F, 8);
  addKey("zoom", Zoom_Key, 0x4F, 8);
  addKey("Audio", Audio_Key, 0x50, 8);
  addKey("Page+", PageUp_Key, 0x51, 8);
  addKey("Find", Unmapped_Key, 0x52, 8);
}


void OpenBoxSTB1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("TV / Sat", QVariant(Input_Key));
  cb->addItem("TV / Radio", QVariant(TunerInput_Key));
}


OpenBoxSTB2::OpenBoxSTB2(
  unsigned int index)
  : PIRKeysetMetaData(
      "Satellite Receiver 2",
      OpenBox_Make,
      TV_Panels | MediaControl_Panels | MediaRecord_Panels,
      index)
{
}


void OpenBoxSTB2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x00, 8);

  addKey("channel up", ChannelUp_Key, 0x38, 8);
  addKey("fav", Favorites_Key, 0x39, 8);
  addKey("info/display", Info_Key, 0x3C, 8);
  addKey("Menu Up", Up_Key, 0x3D, 8);
  addKey("channel down", ChannelDown_Key, 0x3E, 8);
  addKey("guide", Guide_Key, 0x3F, 8);
  addKey("ok/select", Select_Key, 0x68, 8);
  addKey("Meun Right", Right_Key, 0x69, 8);
  addKey("Menu Down", Down_Key, 0x6E, 8);
  addKey("Menu left", Left_Key, 0x89, 8);
  addKey("back", Exit_Key, 0x8F, 8);
  addKey("power", Power_Key, 0xAA, 8);
  addKey("menu", Menu_Key, 0xBC, 8);
}
