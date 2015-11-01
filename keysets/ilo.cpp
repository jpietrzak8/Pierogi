//
// ilo.cpp
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

#include "ilo.h"
#include "protocols/necprotocol.h"
#include <QComboBox>

ILOTV1::ILOTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      ILO_Make,
      TV_Panels,
      index)
{
}


void ILOTV1::populateProtocol(
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

  setPreData(0x42, 8);

  addKey("TV Input", Input_Key, 0x00, 8);
  addKey("power", Power_Key, 0x01, 8);
  addKey("mute", Mute_Key, 0x02, 8);
  addKey("MTS", Audio_Key, 0x03, 8);
  addKey("enter", Enter_Key, 0x05, 8);
  addKey("exit", Exit_Key, 0x06, 8);
  addKey("AV Input", CompositeInput_Key, 0x07, 8);
  addKey("SVideo Input", SVideoInput_Key, 0x08, 8);
  addKey("Component Video Input", ComponentInput_Key, 0x09, 8);
  addKey("DVI Input", PCInput_Key, 0x0A, 8);
  addKey("channel up", ChannelUp_Key, 0x0B, 8);
  addKey("up arrow", Up_Key, 0x0B, 8);
  addKey("vol down", VolumeDown_Key, 0x0C, 8);
  addKey("left arrow", Left_Key, 0x0C, 8);
  addKey("menu", Menu_Key, 0x0D, 8);
  addKey("select", Select_Key, 0x0D, 8);
  addKey("vol up", VolumeUp_Key, 0x0E, 8);
  addKey("right arrow", Right_Key, 0x0E, 8);
  addKey("channel down", ChannelDown_Key, 0x0F, 8);
  addKey("down arrow", Down_Key, 0x0F, 8);
  addKey("pip on/off", PIP_Key, 0x10, 8);
  addKey("ARC", Unmapped_Key, 0x11, 8);
  addKey("APC", Unmapped_Key, 0x12, 8);
  addKey("PIP Size", PIPSize_Key, 0x13, 8);
  addKey("1", One_Key, 0x14, 8);
  addKey("2", Two_Key, 0x15, 8);
  addKey("3", Three_Key, 0x16, 8);
  addKey("pip move", PIPMove_Key, 0x17, 8);
  addKey("4", Four_Key, 0x18, 8);
  addKey("5", Five_Key, 0x19, 8);
  addKey("6", Six_Key, 0x1A, 8);
  addKey("subwoofer", WooferUp_Key, 0x1B, 8);
  addKey("Treble", TrebleUp_Key, 0x1C, 8);
  addKey("7", Seven_Key, 0x1D, 8);
  addKey("8", Eight_Key, 0x1E, 8);
  addKey("9", Nine_Key, 0x1F, 8);
  addKey("sleep", Sleep_Key, 0x40, 8);
  addKey("0", Zero_Key, 0x41, 8);
  addKey("+100", PlusOneHundred_Key, 0x42, 8);
  addKey("Reset", Reset_Key, 0x43, 8);
  addKey("Add", Unmapped_Key, 0x44, 8);
  addKey("Closed Caption", Captions_Key, 0x45, 8);
  addKey("Erase", Unmapped_Key, 0x46, 8);
  addKey("PIP TV", Unmapped_Key, 0x47, 8);
  addKey("PIP AV", Unmapped_Key, 0x48, 8);
  addKey("PIP SV", Unmapped_Key, 0x49, 8);
  addKey("PIP CV", Unmapped_Key, 0x4A, 8);
  addKey("Bass", BassUp_Key, 0x4B, 8);
  addKey("V-Chip", Unmapped_Key, 0x4C, 8);
  addKey("Audio", Unmapped_Key, 0x4D, 8);
  addKey("pip swap", PIPSwap_Key, 0x4E, 8);
}


void ILOTV1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("TV", QVariant(Input_Key));
  cb->addItem("AV", QVariant(CompositeInput_Key));
  cb->addItem("SVideo", QVariant(SVideoInput_Key));
  cb->addItem("Component", QVariant(ComponentInput_Key));
  cb->addItem("DVI", QVariant(PCInput_Key));
}


ILOTV2::ILOTV2(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 2",
      ILO_Make,
      TV_Panels,
      index)
{
}


void ILOTV2::populateProtocol(
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

  setPreData(0x9D60, 16);

  addKey("Menu", Menu_Key, 0x00, 8);
  addKey("PIC.SIZE", AspectRatio_Key, 0x02, 8);
  addKey("L3", Unmapped_Key, 0x02, 8);
  addKey("Mute", Mute_Key, 0x03, 8);
  addKey("EPG", Guide_Key, 0x04, 8);
  addKey("Input", Input_Key, 0x05, 8);
  addKey("0", Zero_Key, 0x06, 8);
  addKey("Standby", Power_Key, 0x07, 8);
  addKey("5", Five_Key, 0x08, 8);
  addKey("6", Six_Key, 0x09, 8);
  addKey("S.Mode", SoundMode_Key, 0x0A, 8);
  addKey("4", Four_Key, 0x0B, 8);
  addKey("DTV", Unmapped_Key, 0x0C, 8);
  addKey("pip", PIP_Key, 0x0C, 8);
  addKey("VOL+", VolumeUp_Key, 0x0D, 8);
  addKey("VOL-", VolumeDown_Key, 0x0E, 8);
  addKey("Exit", Exit_Key, 0x0F, 8);
  addKey("2", Two_Key, 0x10, 8);
  addKey("3", Three_Key, 0x11, 8);
  addKey("Display", Info_Key, 0x12, 8);
  addKey("CCD", Captions_Key, 0x13, 8);
  addKey("L1", Unmapped_Key, 0x13, 8);
  addKey("Add/Erase", Unmapped_Key, 0x14, 8);
  addKey("M2", Unmapped_Key, 0x14, 8);
  addKey("Freeze", Pause_Key, 0x15, 8);
  addKey("L2", Unmapped_Key, 0x15, 8);
  addKey("System", Unmapped_Key, 0x16, 8);
  addKey("Recall", PrevChannel_Key, 0x17, 8);
  addKey("Enter", Select_Key, 0x18, 8);
  addKey("Enter", Enter_Key, 0x18, 8);
  addKey("Down", Down_Key, 0x19, 8);
  addKey("Sleep", Sleep_Key, 0x1A, 8);
  addKey("Left", Left_Key, 0x1B, 8);
  addKey("Up", Up_Key, 0x1C, 8);
  addKey("V-Chip", Unmapped_Key, 0x1D, 8);
  addKey("Right", Right_Key, 0x1E, 8);
  addKey("CH-", ChannelDown_Key, 0x1F, 8);
  addKey("P.Mode", PictureMode_Key, 0x40, 8);
  addKey("L4", Unmapped_Key, 0x40, 8);
  addKey("Green", Green_Key, 0x44, 8);
  addKey("1", One_Key, 0x45, 8);
  addKey("7", Seven_Key, 0x47, 8);
  addKey("Yellow", Yellow_Key, 0x48, 8);
  addKey("Dot", Dash_Key, 0x49, 8);
  addKey("8", Eight_Key, 0x4B, 8);
  addKey("9", Nine_Key, 0x4F, 8);
  addKey("CH+", ChannelUp_Key, 0x51, 8);
  addKey("MTS", Audio_Key, 0x52, 8);
  addKey("Favorite", Favorites_Key, 0x53, 8);
  addKey("Red", Red_Key, 0x54, 8);
  addKey("Blue", Blue_Key, 0x58, 8);
}


ILOTV3::ILOTV3(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 3",
      ILO_Make,
      TV_Panels,
      index)
{
}


void ILOTV3::populateProtocol(
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

  setPreData(0xD900, 16);

  addKey("Picture Mode", PictureMode_Key, 0x03, 8);
  addKey("View Mode", AspectRatio_Key, 0x04, 8); // ?
  addKey("Mute", Mute_Key, 0x06, 8);
  addKey("OK", Select_Key, 0x08, 8);
  addKey("1", One_Key, 0x09, 8);
  addKey("4", Four_Key, 0x0D, 8);
  addKey("7", Seven_Key, 0x11, 8);
  addKey("0", Zero_Key, 0x12, 8);
  addKey("8", Eight_Key, 0x15, 8);
  addKey("dot", Dash_Key, 0x16, 8);
  addKey("9", Nine_Key, 0x17, 8);
  addKey("5", Five_Key, 0x19, 8);
  addKey("6", Six_Key, 0x1B, 8);
  addKey("Power", Power_Key, 0x1C, 8);
  addKey("2", Two_Key, 0x1D, 8);
  addKey("3", Three_Key, 0x1F, 8);
  addKey("Flashback", PrevChannel_Key, 0x40, 8);
  addKey("TV", Input_Key, 0x42, 8);
  addKey("TV", AntennaInput_Key, 0x42, 8);
  addKey("Video", AuxInput_Key, 0x43, 8);
  addKey("MTS/SAP", Audio_Key, 0x46, 8);
  addKey("Volume Down", VolumeDown_Key, 0x47, 8);
  addKey("Volume Up", VolumeUp_Key, 0x48, 8);
  addKey("Sound Mode", SoundMode_Key, 0x49, 8);
  addKey("TV Menu", Menu_Key, 0x4A, 8);
  addKey("CC", Captions_Key, 0x4C, 8);
  addKey("OSD", Info_Key, 0x4E, 8);
  addKey("Channel Up", ChannelUp_Key, 0x4F, 8);
  addKey("Favorite", Favorites_Key, 0x50, 8);
  addKey("Channel Down", ChannelDown_Key, 0x52, 8);
  addKey("Menu Up", Up_Key, 0x5C, 8);
  addKey("Menu Down", Down_Key, 0x5D, 8);
  addKey("Menu Left", Left_Key, 0x5E, 8);
  addKey("Menu Right", Right_Key, 0x5F, 8);
}


void ILOTV3::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("TV", QVariant(Input_Key));
  cb->addItem("Video", QVariant(AuxInput_Key));
}
