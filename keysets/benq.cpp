//
// benq.cpp
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

#include "benq.h"
#include "protocols/necprotocol.h"
#include <QComboBox>


BenQTV1::BenQTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      BenQ_Make,
      TV_Panels,
      index)
{
}


void BenQTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x60, 8);

  addKey("power", Power_Key, 0x00, 8);
  addKey("input", Input_Key, 0x45, 8);
  addKey("backlight", Unmapped_Key, 0x54, 8);
  addKey("information", Info_Key, 0x52, 8);
  addKey("sleeptimer", Sleep_Key, 0x58, 8);
  addKey("sound", SoundMode_Key, 0x59, 8);
  addKey("usersituation", Unmapped_Key, 0x55, 8);
  addKey("audiomode", Audio_Key, 0x53, 8);
  addKey("teletext_display", TeletextAndTV_Key, 0x4F, 8);
  addKey("tt_index", TeletextIndex_Key, 0x4C, 8);
  addKey("tt_info", Unmapped_Key, 0x4E, 8);
  addKey("tt_subpage", TeletextReveal_Key, 0x4D, 8);
  addKey("teletext", Teletext_Key, 0x12, 8);
  addKey("PIP", PIP_Key, 0x10, 8);
  addKey("up", Up_Key, 0x44, 8);
  addKey("down", Down_Key, 0x1D, 8);
  addKey("left", Left_Key, 0x1C, 8);
  addKey("right", Right_Key, 0x48, 8);
  addKey("OK", Select_Key, 0x51, 8);
  addKey("freeze", Pause_Key, 0x11, 8);
  addKey("aspectratio", AspectRatio_Key, 0x13, 8);
  addKey("vol+", VolumeUp_Key, 0x19, 8);
  addKey("vol-", VolumeDown_Key, 0x15, 8);
  addKey("chan+", ChannelUp_Key, 0x5C, 8);
  addKey("chan-", ChannelDown_Key, 0x14, 8);
  addKey("menu", Menu_Key, 0x43, 8);
  addKey("mute", Mute_Key, 0x42, 8);
  addKey("zap", Unmapped_Key, 0x0F, 8);
  addKey("dualdigit", DoubleDigit_Key, 0x0D, 8);
  addKey("1", One_Key, 0x04, 8);
  addKey("2", Two_Key, 0x05, 8);
  addKey("3", Three_Key, 0x5F, 8);
  addKey("4", Four_Key, 0x07, 8);
  addKey("5", Five_Key, 0x08, 8);
  addKey("6", Six_Key, 0x09, 8);
  addKey("7", Seven_Key, 0x0A, 8);
  addKey("8", Eight_Key, 0x0B, 8);
  addKey("9", Nine_Key, 0x0C, 8);
  addKey("0", Zero_Key, 0x03, 8);
}


BenQProjector1::BenQProjector1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Projector Keyset 1",
      BenQ_Make,
      MediaControl_Panels,
      index)
{
}


void BenQProjector1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, false);

  setPreData(0x3000, 16);

  addKey("power", Power_Key, 0x02, 8);
  addKey("play/pause", Play_Key, 0x03, 8); // "Freeze"
  addKey("play/pause", Pause_Key, 0x03, 8);
  addKey("source", Input_Key, 0x04, 8);
  addKey("pageup", PageUp_Key, 0x05, 8);
  addKey("pagedown", PageDown_Key, 0x06, 8);
  addKey("blank", Mute_Key, 0x07, 8);
  addKey("auto", Unmapped_Key, 0x08, 8);
  addKey("keystone-larger", Green_Key, 0x09, 8); // "KeyStoneUp"
  addKey("keystone-smaller", Red_Key, 0x0A, 8); // "KeyStoneDown"
  addKey("up", Up_Key, 0x0B, 8);
  addKey("down", Down_Key, 0x0C, 8);
  addKey("left", Left_Key, 0x0D, 8);
  addKey("right", Right_Key, 0x0E, 8);
  addKey("menu", Menu_Key, 0x0F, 8);
  addKey("Select/Ok", Select_Key, 0x0F, 8);
  addKey("preset", PictureMode_Key, 0x10, 8); // "Mode"
  addKey("keystone-auto", Keystone_Key, 0x11, 8);
}


BenQProjector1a::BenQProjector1a(
  unsigned int index)
  : BenQProjector1(index)
{
  setKeysetName("Projector Keyset 1a");
}


void BenQProjector1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  BenQProjector1::populateProtocol(guiObject);

  addKey("CONTRAST", ContrastUp_Key, 0x11, 8);
  addKey("ENTER", Select_Key, 0x15, 8);
  addKey("BRIGHTNESS", BrightnessUp_Key, 0x16, 8);
  addKey("S-VIDEO", SVideoInput_Key, 0x1F, 8);
  addKey("D-SUB", PCInput_Key, 0x41, 8);
  addKey("COMP2", Composite2Input_Key, 0x50, 8);
  addKey("COMP1", CompositeInput_Key, 0x51, 8);
  addKey("VIDEO", AuxInput_Key, 0x52, 8);
  addKey("HDMI", HDMIInput_Key, 0x58, 8);
  addKey("ANA", Unmapped_Key, 0x70, 8);
  addKey("4:3", Unmapped_Key, 0x71, 8);
  addKey("LB", Unmapped_Key, 0x72, 8);
  addKey("WIDE", Unmapped_Key, 0x73, 8);
  addKey("REAL", Unmapped_Key, 0x74, 8);
  addKey("MEM 1", Unmapped_Key, 0x75, 8);
  addKey("MEM 2", Unmapped_Key, 0x76, 8);
  addKey("MEM 3", Unmapped_Key, 0x77, 8);
  addKey("DEFAULT", Unmapped_Key, 0x78, 8);
  addKey("COLOR", ColorUp_Key, 0x79, 8);
  addKey("TINT", Unmapped_Key, 0x7A, 8);
  addKey("EXIT", Exit_Key, 0x85, 8);
}


void BenQProjector1a::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("Input Toggle", QVariant(Input_Key));
  cb->addItem("S-Video", QVariant(SVideoInput_Key));
  cb->addItem("D-Sub", QVariant(PCInput_Key));
  cb->addItem("Composite 1", QVariant(CompositeInput_Key));
  cb->addItem("Composite 2", QVariant(Composite2Input_Key));
  cb->addItem("Video", QVariant(AuxInput_Key));
  cb->addItem("HDMI", QVariant(HDMIInput_Key));
}


BenQProjector2::BenQProjector2(
  unsigned int index)
  : PIRKeysetMetaData(
      "Projector Keyset 2",
      BenQ_Make,
      MediaControl_Panels,
      index)
{
}


void BenQProjector2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x30, 8);

  addKey("Source", Input_Key, 0x08, 8);
  addKey("Exit", Exit_Key, 0x0A, 8);
  addKey("Analog RGB", ComponentInput_Key, 0x0B, 8);
  addKey("Composite Video", CompositeInput_Key, 0x0D, 8);
  addKey("Mute", Mute_Key, 0x12, 8);
  addKey("Power", Power_Key, 0x18, 8);
  addKey("Menu", Menu_Key, 0x20, 8);
  addKey("Volume Down", VolumeDown_Key, 0x22, 8);
  addKey("Lamp Info", Info_Key, 0x27, 8);
  addKey("Zoom In", ChannelUp_Key, 0x2C, 8);
  addKey("Zoom Out", ChannelDown_Key, 0x2D, 8);
  addKey("Blank", Stop_Key, 0xD5, 8);
  addKey("Volume Up", VolumeUp_Key, 0xE5, 8);
  addKey("Analog YPbPr", Component2Input_Key, 0xEB, 8);
  addKey("S-Video", SVideoInput_Key, 0xEC, 8);
  addKey("Ratio", Unmapped_Key, 0xF0, 8);
  addKey("Pause", Pause_Key, 0xF1, 8);
  addKey("Right Arrow", Right_Key, 0xFD, 8);
  addKey("Left Arrow", Left_Key, 0xFF, 8);
}


void BenQProjector2::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("Input Toggle", QVariant(Input_Key));
  cb->addItem("Composite Video", QVariant(CompositeInput_Key));
  cb->addItem("S-Video", QVariant(SVideoInput_Key));
  cb->addItem("Analog RGB", QVariant(ComponentInput_Key));
  cb->addItem("Analog YPbPr", QVariant(Component2Input_Key));
}


BenQProjector3::BenQProjector3(
  unsigned int index)
  : PIRKeysetMetaData(
      "Projector Keyset 3",
      BenQ_Make,
      MediaControl_Panels,
      index)
{
}


void BenQProjector3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x30, 8);

  addKey("power", Power_Key, 0x02, 8);
  addKey("play/pause", Play_Key, 0x03, 8); // "Freeze"
  addKey("play/pause", Pause_Key, 0x03, 8);
  addKey("source", Input_Key, 0x04, 8);
  addKey("pageup", PageUp_Key, 0x05, 8);
  addKey("pagedown", PageDown_Key, 0x06, 8);
  addKey("blank", Mute_Key, 0x07, 8);
  addKey("auto", Unmapped_Key, 0x08, 8);
  addKey("keystone-larger", Green_Key, 0x09, 8); // "KeyStoneUp"
  addKey("keystone-smaller", Red_Key, 0x0A, 8); // "KeyStoneDown"
  addKey("up", Up_Key, 0x0B, 8);
  addKey("down", Down_Key, 0x0C, 8);
  addKey("left", Left_Key, 0x0D, 8);
  addKey("right", Right_Key, 0x0E, 8);
  addKey("menu", Menu_Key, 0x0F, 8);
  addKey("Select/Ok", Select_Key, 0x0F, 8);
  addKey("preset", PictureMode_Key, 0x10, 8); // "Mode"
  addKey("keystone-auto", Keystone_Key, 0x11, 8);
}


BenQProjector4::BenQProjector4(
  unsigned int index)
  : PIRKeysetMetaData(
      "Projector Keyset 4",
      BenQ_Make,
      MediaControl_Panels,
      index)
{
}


void BenQProjector4::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x30, 8);

  addKey("left arrow", Left_Key, 0x00, 8);
  addKey("right arrow", Right_Key, 0x02, 8);
  addKey("tv/vcr", Input_Key, 0x08, 8);
  addKey("up arrow", Up_Key, 0x0A, 8);
  addKey("RGB input", ComponentInput_Key, 0x0B, 8);
  addKey("composite input", CompositeInput_Key, 0x0D, 8);
  addKey("pip on/off", PIP_Key, 0x10, 8);
  addKey("s-video input", SVideoInput_Key, 0x13, 8);
  addKey("Y/Pb/Pr input", Component2Input_Key, 0x14, 8);
  addKey("power", Power_Key, 0x18, 8);
  addKey("pip move", PIPMove_Key, 0x1A, 8);
  addKey("down arrow", Down_Key, 0x20, 8);
  addKey("pip freeze", Pause_Key, 0x28, 8);
  addKey("mute", Mute_Key, 0x2A, 8);
  addKey("channel down", ChannelDown_Key, 0x40, 8);
  addKey("channel up", ChannelUp_Key, 0x45, 8);
}


void BenQProjector4::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("TV / VCR", QVariant(Input_Key));
  cb->addItem("Composite", QVariant(CompositeInput_Key));
  cb->addItem("S-Video", QVariant(SVideoInput_Key));
  cb->addItem("RGB", QVariant(ComponentInput_Key));
  cb->addItem("Y/Pb/Pr", QVariant(Component2Input_Key));
}


BenQProjector5::BenQProjector5(
  unsigned int index)
  : PIRKeysetMetaData(
      "Projector Keyset 5",
      BenQ_Make,
      MediaControl_Panels,
      index)
{
}


void BenQProjector5::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x8D, 8);

  addKey("power", Power_Key, 0x00, 8);
  addKey("Composite", CompositeInput_Key, 0x02, 8);
  addKey("Component", ComponentInput_Key, 0x0A, 8);
  addKey("menu", Menu_Key, 0x19, 8);
  addKey("left arrow", Left_Key, 0x1C, 8);
  addKey("down arrow", Down_Key, 0x1D, 8);
  addKey("S-video", SVideoInput_Key, 0x1F, 8);
  addKey("RGB HD", Unmapped_Key, 0x40, 8);
  addKey("ANA", Unmapped_Key, 0x42, 8);
  addKey("Wide", Unmapped_Key, 0x43, 8);
  addKey("up arrow", Up_Key, 0x44, 8);
  addKey("off", Unmapped_Key, 0x45, 8); // Discrete off key?
  addKey("4:3", Unmapped_Key, 0x46, 8);
  addKey("right arrow", Right_Key, 0x48, 8);
  addKey("PIP", PIP_Key, 0x4D, 8);
  addKey("CP HD", Unmapped_Key, 0x50, 8);
  addKey("enter", Select_Key, 0x51, 8);
  addKey("LB", Unmapped_Key, 0x52, 8);
  addKey("PC(DVI)", PCInput_Key, 0x58, 8);
  addKey("exit", Exit_Key, 0x5C, 8);
}


void BenQProjector5::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("Composite", QVariant(CompositeInput_Key));
  cb->addItem("S-Video", QVariant(SVideoInput_Key));
  cb->addItem("Component", QVariant(ComponentInput_Key));
  cb->addItem("PC (DVI)", QVariant(PCInput_Key));
}
