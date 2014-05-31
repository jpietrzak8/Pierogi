//
// zenith.cpp
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

#include "zenith.h"
#include "protocols/necprotocol.h"
#include <QComboBox>


// Based on LIRC Zenith_C32V37 config file
ZenithTV1::ZenithTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Zenith_Make,
      TV_Panels,
      index)
{
  addControlledDevice(Zenith_Make, "C32V37", TV_Device);
}


void ZenithTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x04, 8);

  addKey("CH_UP", ChannelUp_Key, 0x00, 8);
  addKey("CH_DOWN", ChannelDown_Key, 0x01, 8);
  addKey("VOL_UP", VolumeUp_Key, 0x02, 8);
  addKey("VOL_DOWN", VolumeDown_Key, 0x03, 8);
  addKey("right", Right_Key, 0x06, 8);
  addKey("left", Left_Key, 0x07, 8);
  addKey("power", Power_Key, 0x08, 8);
  addKey("mute", Mute_Key, 0x09, 8);
  addKey("audio", Audio_Key, 0x0A, 8);
  addKey("tv/video", Input_Key, 0x0B, 8);
  addKey("timer", Sleep_Key, 0x0E, 8);
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
  addKey("flashbk", PrevChannel_Key, 0x1A, 8);
  addKey("surf", Unmapped_Key, 0x1E, 8);
  addKey("cc", Captions_Key, 0x39, 8);
  addKey("up", Up_Key, 0x40, 8);
  addKey("down", Down_Key, 0x41, 8);
  addKey("menu", Menu_Key, 0x43, 8);
  addKey("dash", Dash_Key, 0x4C, 8);
  addKey("video", PictureMode_Key, 0x4D, 8);
  addKey("front", Unmapped_Key, 0x51, 8);
  addKey("exit", Exit_Key, 0x5B, 8);
  addKey("pip", PIP_Key, 0x60, 8);
  addKey("pcin", PCInput_Key, 0x61, 8);
  addKey("swap", PIPSwap_Key, 0x63, 8);
  addKey("freeze", PIPPause_Key, 0x65, 8);
  addKey("pipch+", PIPChannelUp_Key, 0x71, 8);
  addKey("pipch-", PIPChannelDown_Key, 0x72, 8);
  addKey("ratio", AspectRatio_Key, 0x79, 8);
  addKey("signal", Unmapped_Key, 0x96, 8);
  addKey("comp/dvi", ComponentInput_Key, 0x98, 8);
  addKey("info", Info_Key, 0xAA, 8);
}


void ZenithTV1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("TV / Video", QVariant(Input_Key));
  cb->addItem("PC", QVariant(PCInput_Key));
  cb->addItem("Comp / DVI", QVariant(ComponentInput_Key));
}


ZenithConverterBox1::ZenithConverterBox1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Digital Converter Box 1",
      Zenith_Make,
      TV_Panels,
      index)
{
  addControlledDevice(Zenith_Make, "AKB36157102", Other_Device);
}


void ZenithConverterBox1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x10, 8);

  addKey("CHUP", ChannelUp_Key, 0x00, 8);
  addKey("CHDOWN", ChannelDown_Key, 0x01, 8);
  addKey("VOLUP", VolumeUp_Key, 0x02, 8);
  addKey("VOLDOWN", VolumeDown_Key, 0x03, 8);
  addKey("UP", Up_Key, 0x04, 8);
  addKey("DOWN", Down_Key, 0x05, 8);
  addKey("RIGHT", Right_Key, 0x06, 8);
  addKey("LEFT", Left_Key, 0x07, 8);
  addKey("POWER", Power_Key, 0x08, 8);
  addKey("MUTE", Mute_Key, 0x09, 8);
  addKey("SAP", Audio_Key, 0x0A, 8);
  addKey("SLEEP", Sleep_Key, 0x0E, 8);
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
  addKey("RECALL", PrevChannel_Key, 0x1A, 8);
  addKey("FAV", Favorites_Key, 0x1E, 8);
  addKey("CCD", Captions_Key, 0x39, 8);
  addKey("MENU", Menu_Key, 0x43, 8);
  addKey("OK", Select_Key, 0x44, 8);
  addKey("-", Dash_Key, 0x4C, 8);
  addKey("EXIT", Exit_Key, 0x5B, 8);
  addKey("ZOOM", Zoom_Key, 0x79, 8);
  addKey("SIGNAL", Unmapped_Key, 0x96, 8);
  addKey("GUIDE", Guide_Key, 0xA9, 8);
  addKey("DISPLAY", Info_Key, 0xAA, 8);
  addKey("CHUP2", Unmapped_Key, 0x20, 8);
  addKey("CHDOWN2", Unmapped_Key, 0x21, 8);
  addKey("OK2", Unmapped_Key, 0x78, 8);
  addKey("MENU2", Unmapped_Key, 0x7E, 8);
  addKey("POWER_OFF", PowerOff_Key, 0x5C, 8);
  addKey("FACTORY_MENU", Unmapped_Key, 0xEA, 8);
  addKey("FACTORY_RESET", Unmapped_Key, 0xEB, 8);
}
