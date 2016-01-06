//
// bush.cpp
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

#include "bush.h"
#include "protocols/rc5protocol.h"
#include <QComboBox>


BushTV1::BushTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Bush_Make,
      TV_Panels,
      index)
{
}


void BushTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  addKey("menu-off", Exit_Key, 0x0013, 13);
  addKey("zoom", Zoom_Key, 0x003E, 13);

  addKey("0", Zero_Key, 0x1000, 13);
  addKey("1", One_Key, 0x1001, 13);
  addKey("2", Two_Key, 0x1002, 13);
  addKey("3", Three_Key, 0x1003, 13);
  addKey("4", Four_Key, 0x1004, 13);
  addKey("5", Five_Key, 0x1005, 13);
  addKey("6", Six_Key, 0x1006, 13);
  addKey("7", Seven_Key, 0x1007, 13);
  addKey("8", Eight_Key, 0x1008, 13);
  addKey("9", Nine_Key, 0x1009, 13);
  addKey("off", Power_Key, 0x100C, 13);
  addKey("mute", Mute_Key, 0x100D, 13);
  addKey("norm", Unmapped_Key, 0x100E, 13);
  addKey("osd", Info_Key, 0x100F, 13);
  addKey("vol+", VolumeUp_Key, 0x1010, 13);
  addKey("vol-", VolumeDown_Key, 0x1011, 13);
  addKey("chan+", ChannelUp_Key, 0x1020, 13);
  addKey("chan-", ChannelDown_Key, 0x1021, 13);
  addKey("last", PrevChannel_Key, 0x1024, 13);
  addKey("clockon", Sleep_Key, 0x102A, 13);
  addKey("yellow", Yellow_Key, 0x1032, 13);
  addKey("blue", Blue_Key, 0x1034, 13);
  addKey("white", Unmapped_Key, 0x1035, 13);
  addKey("green", Green_Key, 0x1036, 13);
  addKey("red", Red_Key, 0x1037, 13);
  addKey("av", AuxInput_Key, 0x1038, 13);
  addKey("menu", Menu_Key, 0x103B, 13);
  addKey("text", Teletext_Key, 0x103C, 13);
  addKey("tv", Input_Key, 0x103F, 13);
}


void BushTV1::populateInputList(
  QComboBox *cb) const
{
  cb->clear();

  cb->addItem("TV", QVariant(Input_Key));
  cb->addItem("Aux", QVariant(AuxInput_Key));
}


BushTV2::BushTV2(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 2",
      Bush_Make,
      TV_Panels,
      index)
{
}


void BushTV2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  addKey("SMART_CONTROL_PICTURE", PictureMode_Key, 0x1002, 13);
  addKey("MIX", TeletextAndTV_Key, 0x1004, 13);
  addKey("P100", Unmapped_Key, 0x1006, 13); // Plus 100?
  addKey("DOUB", TeletextSize_Key, 0x1007, 13);
  addKey("SUB", Unmapped_Key, 0x100A, 13);
  addKey("SMART_CONTROL_SOUND", SoundMode_Key, 0x100B, 13);
  addKey("HOLD", TeletextHold_Key, 0x100C, 13);
  addKey("REV", TeletextReveal_Key, 0x100E, 13);
  addKey("UPDATE", Unmapped_Key, 0x100F, 13);

  addKey("0", Zero_Key, 0x1010, 13);
  addKey("1", One_Key, 0x1011, 13);
  addKey("2", Two_Key, 0x1012, 13);
  addKey("3", Three_Key, 0x1013, 13);
  addKey("4", Four_Key, 0x1014, 13);
  addKey("5", Five_Key, 0x1015, 13);
  addKey("6", Six_Key, 0x1016, 13);
  addKey("7", Seven_Key, 0x1017, 13);
  addKey("8", Eight_Key, 0x1018, 13);
  addKey("9", Nine_Key, 0x1019, 13);
  addKey("-/--", DoubleDigit_Key, 0x101A, 13);
  addKey("PR_DOWN", ChannelDown_Key, 0x101B, 13);
  addKey("PR_DOWN", Down_Key, 0x101B, 13);
  addKey("PR_UP", ChannelUp_Key, 0x101C, 13);
  addKey("PR_UP", Up_Key, 0x101C, 13);

  addKey("POWER", Power_Key, 0x1020, 13);
  addKey("PP", Unmapped_Key, 0x1021, 13);
  addKey("16:9", AspectRatio_Key, 0x1023, 13);
  addKey("VOL_UP", VolumeUp_Key, 0x1024, 13);
  addKey("VOL_UP", Right_Key, 0x1024, 13);
  addKey("VOL_LOW", VolumeDown_Key, 0x1025, 13);
  addKey("VOL_LOW", Left_Key, 0x1025, 13);
  addKey("RED", Red_Key, 0x1026, 13);
  addKey("SWAP", PrevChannel_Key, 0x1027, 13);
  addKey("OK", Select_Key, 0x1028, 13);
  addKey("MENU", Menu_Key, 0x1029, 13);
  addKey("AV", Input_Key, 0x102A, 13);
  addKey("MUTE", Mute_Key, 0x102B, 13);
  addKey("GREEN", Green_Key, 0x102C, 13);
  addKey("YELLOW", Yellow_Key, 0x102E, 13);
  addKey("I", Info_Key, 0x102F, 13); // "PURPLE", might be wrong

  addKey("TXT", Teletext_Key, 0x1031, 13);
  addKey("BLUE", Blue_Key, 0x1033, 13);
}


BushSTB1::BushSTB1(
  unsigned int index)
  : PIRKeysetMetaData(
      "STB Keyset 1",
      Bush_Make,
      TV_Panels,
      index)
{
}


void BushSTB1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  addKey("power", Power_Key, 0x120C, 13);
  addKey("mute", Mute_Key, 0x120D, 13);
  addKey("tvdtv", Input_Key, 0x120E, 13);
  addKey("menu", Menu_Key, 0x1235, 13);
  addKey("up", Up_Key, 0x1212, 13);
  addKey("left", Left_Key, 0x1215, 13);
  addKey("select", Select_Key, 0x1214, 13);
  addKey("right", Right_Key, 0x1216, 13);
  addKey("down", Down_Key, 0x1213, 13);
  addKey("num1", One_Key, 0x1201, 13);
  addKey("num2", Two_Key, 0x1202, 13);
  addKey("num3", Three_Key, 0x1203, 13);
  addKey("num4", Four_Key, 0x1204, 13);
  addKey("num5", Five_Key, 0x1205, 13);
  addKey("num6", Six_Key, 0x1206, 13);
  addKey("num7", Seven_Key, 0x1207, 13);
  addKey("num8", Eight_Key, 0x1208, 13);
  addKey("num9", Nine_Key, 0x1209, 13);
  addKey("num0", Zero_Key, 0x1200, 13);
  addKey("guide", Guide_Key, 0x1222, 13);
  addKey("volup", VolumeUp_Key, 0x1210, 13);
  addKey("progup", ChannelUp_Key, 0x1220, 13);
  addKey("voldwn", VolumeDown_Key, 0x1211, 13);
  addKey("progdwn", ChannelDown_Key, 0x1221, 13);
  addKey("red", Red_Key, 0x1237, 13);
  addKey("green", Green_Key, 0x1236, 13);
  addKey("yellow", Yellow_Key, 0x1232, 13);
  addKey("blue", Blue_Key, 0x1234, 13);
  addKey("wide", AspectRatio_Key, 0x121E, 13);
  addKey("info", Info_Key, 0x123F, 13);
  addKey("exit", Exit_Key, 0x120A, 13);
  addKey("text", Teletext_Key, 0x123C, 13);
}
