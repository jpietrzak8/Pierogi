//
// westinghouse.cpp
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

#include "westinghouse.h"
#include "protocols/necprotocol.h"
#include "protocols/sircprotocol.h"
#include <QComboBox>


WestinghouseTV1::WestinghouseTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Westinghouse_Make,
      TV_Panels,
      index)
{
}


void WestinghouseTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, false);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

//  setPreData(0x807F, 16);
  setPreData(0x01, 8);

  addKey("INPUT", Input_Key, 0x00, 8);
  addKey("KEY_POWER", Power_Key, 0x01, 8);
  addKey("KEY_VOLUMEUP", VolumeUp_Key, 0x04, 8);
  addKey("KEY_VOLUMEDOWN", VolumeDown_Key, 0x05, 8);
  addKey("DVI", HDMIInput_Key, 0x06, 8);
  addKey("ASPECT_RATIO", AspectRatio_Key, 0x07, 8);
  addKey("KEY_BACK", PrevChannel_Key, 0x08, 8);
  addKey("VGA", PCInput_Key, 0x09, 8);
  addKey("YPbPr", ComponentInput_Key, 0x0A, 8);
  addKey("AV", CompositeInput_Key, 0x0B, 8);
  addKey("S-Video", SVideoInput_Key, 0x0C, 8);
  addKey("KEY_MUTE", Mute_Key, 0x10, 8);
  addKey("KEY_1", One_Key, 0x11, 8);
  addKey("KEY_2", Two_Key, 0x12, 8);
  addKey("KEY_3", Three_Key, 0x13, 8);
  addKey("KEY_4", Four_Key, 0x14, 8);
  addKey("KEY_5", Five_Key, 0x15, 8);
  addKey("KEY_6", Six_Key, 0x16, 8);
  addKey("KEY_7", Seven_Key, 0x17, 8);
  addKey("KEY_8", Eight_Key, 0x18, 8);
  addKey("KEY_9", Nine_Key, 0x19, 8);
  addKey("KEY_0", Zero_Key, 0x1A, 8);
  addKey("KEY_INFO", Info_Key, 0x1B, 8);
  addKey("FREEZE", Pause_Key, 0x1C, 8);
  addKey("KEY_UP", Up_Key, 0x40, 8);
  addKey("KEY_LEFT", Left_Key, 0x41, 8);
  addKey("KEY_ENTER", Enter_Key, 0x42, 8);
  addKey("KEY_RIGHT", Right_Key, 0x43, 8);
  addKey("KEY_DOWN", Down_Key, 0x44, 8);
  addKey("KEY_MENU", Menu_Key, 0x46, 8);
}


void WestinghouseTV1::populateInputList(
  QComboBox *cb) const
{
  cb->clear();

  cb->addItem("Input", QVariant(Input_Key));
  cb->addItem("AV", QVariant(CompositeInput_Key));
  cb->addItem("S-Video", QVariant(SVideoInput_Key));
  cb->addItem("YPbPr", QVariant(ComponentInput_Key));
  cb->addItem("DVI", QVariant(HDMIInput_Key));
  cb->addItem("VGA", QVariant(PCInput_Key));
}


WestinghouseTV2::WestinghouseTV2(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 2",
      Westinghouse_Make,
      TV_Panels,
      index)
{
  addControlledDevice(Westinghouse_Make, "LVM-42W2", TV_Device);
}


void WestinghouseTV2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new SIRCProtocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  addSIRC12Key("1", One_Key, 0x01, 0x00);
  addSIRC12Key("2", Two_Key, 0x01, 0x01);
  addSIRC12Key("3", Three_Key, 0x01, 0x02);
  addSIRC12Key("4", Four_Key, 0x01, 0x03);
  addSIRC12Key("5", Five_Key, 0x01, 0x04);
  addSIRC12Key("6", Six_Key, 0x01, 0x05);
  addSIRC12Key("7", Seven_Key, 0x01, 0x06);
  addSIRC12Key("8", Eight_Key, 0x01, 0x07);
  addSIRC12Key("9", Nine_Key, 0x01, 0x08);
  addSIRC12Key("0", Zero_Key, 0x01, 0x09);
  addSIRC12Key(".", Unmapped_Key, 0x01, 0x0A);
  addSIRC12Key("EnterNumPad", Enter_Key, 0x01, 0x0B);
  addSIRC12Key("CC", Captions_Key, 0x01, 0x0C);
  addSIRC12Key("EPG", Guide_Key, 0x01, 0x0E);
  addSIRC12Key("Ch+", ChannelUp_Key, 0x01, 0x10);
  addSIRC12Key("Ch-", ChannelDown_Key, 0x01, 0x11);
  addSIRC12Key("Vol+", VolumeUp_Key, 0x01, 0x12);
  addSIRC12Key("Vol-", VolumeDown_Key, 0x01, 0x13);
  addSIRC12Key("Mute", Mute_Key, 0x01, 0x14);
  addSIRC12Key("Power", Power_Key, 0x01, 0x15);
  addSIRC12Key("Backlight", Unmapped_Key, 0x01, 0x18);
  addSIRC12Key("Zoom", Zoom_Key, 0x01, 0x1C);
  addSIRC12Key("TV", Unmapped_Key, 0x01, 0x24);
  addSIRC12Key("Input", Input_Key, 0x01, 0x25);
  addSIRC12Key("Right", Right_Key, 0x01, 0x33);
  addSIRC12Key("Left", Left_Key, 0x01, 0x34);
  addSIRC12Key("Sleep", Sleep_Key, 0x01, 0x36);
  addSIRC12Key("Retry", Unmapped_Key, 0x01, 0x3B);
  addSIRC12Key("Info", Info_Key, 0x01, 0x3A);
  addSIRC12Key("Video", CompositeInput_Key, 0x01, 0x40);
  addSIRC12Key("HDMI", HDMIInput_Key, 0x01, 0x42);
  addSIRC12Key("PC", PCInput_Key, 0x01, 0x43);
  addSIRC12Key("DVI", HDMI2Input_Key, 0x01, 0x44);
  addSIRC12Key("YPbPr1", ComponentInput_Key, 0x01, 0x48);
  addSIRC12Key("YPbPr2", Component2Input_Key, 0x01, 0x49);
  addSIRC12Key("SVideo", SVideoInput_Key, 0x01, 0x4D);
  addSIRC12Key("PIP", PIP_Key, 0x01, 0x5B);
  addSIRC12Key("PIPSwap", PIPSwap_Key, 0x01, 0x5F);
  addSIRC12Key("Menu", Menu_Key, 0x01, 0x60);
  addSIRC12Key("EnterNavigation", Select_Key, 0x01, 0x65);
  addSIRC12Key("A", Unmapped_Key, 0x01, 0x6A);
  addSIRC12Key("B", Unmapped_Key, 0x01, 0x6B);
  addSIRC12Key("C", Unmapped_Key, 0x01, 0x6C);
  addSIRC12Key("Up", Up_Key, 0x01, 0x74);
  addSIRC12Key("Down", Down_Key, 0x01, 0x75);
}


void WestinghouseTV2::populateInputList(
  QComboBox *cb) const
{
  cb->clear();

  cb->addItem("Input", QVariant(Input_Key));
  cb->addItem("Video", QVariant(CompositeInput_Key));
  cb->addItem("SVideo", QVariant(SVideoInput_Key));
  cb->addItem("YPbPr 1", QVariant(ComponentInput_Key));
  cb->addItem("YPbPr 2", QVariant(Component2Input_Key));
  cb->addItem("HDMI", QVariant(HDMIInput_Key));
  cb->addItem("DVI", QVariant(HDMI2Input_Key));
  cb->addItem("PC", QVariant(PCInput_Key));
}
