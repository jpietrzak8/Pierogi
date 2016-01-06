//
// epson.cpp
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

#include "epson.h"
#include "protocols/necprotocol.h"
#include <QComboBox>

EpsonProjector1::EpsonProjector1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Projector Keyset 1",
      Epson_Make,
      MediaControl_Panels,
      index)
{
}


void EpsonProjector1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, false);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x5583, 16);

  addKey("Keystone down", Unmapped_Key, 0x21, 8);
  addKey("Keystone up", Unmapped_Key, 0x22, 8);
  addKey("Tone", Unmapped_Key, 0x2A, 8); // "Skin Tone"
  addKey("Bright", Unmapped_Key, 0x2B, 8);
  addKey("Contrast", Unmapped_Key, 0x2C, 8);
  addKey("Color temp.", Unmapped_Key, 0x2D, 8);

  addKey("Eject", Eject_Key, 0x50, 8);
  addKey("Repeat", Repeat_Key, 0x53, 8);
  addKey("Return", Unmapped_Key, 0x55, 8);
  addKey("Stop", Stop_Key, 0x59, 8);
  addKey("Rewind", Rewind_Key, 0x5A, 8);
  addKey("Pause", Pause_Key, 0x5B, 8);
  addKey("FastForward", FastForward_Key, 0x5C, 8);
  addKey("ChapterPrev", Previous_Key, 0x5D, 8);
  addKey("Play", Play_Key, 0x5E, 8);
  addKey("ChapterNext", Next_Key, 0x5F, 8);

  addKey("Menu", DiscMenu_Key, 0x62, 8);
  addKey("Audio", Audio_Key, 0x69, 8);
  addKey("Subtitle", Captions_Key, 0x6A, 8);
  addKey("Angle", Angle_Key, 0x6B, 8);
  addKey("Program", Unmapped_Key, 0x6D, 8);
  addKey("Sound", Unmapped_Key, 0x6E, 8);
  addKey("Zoom", Zoom_Key, 0x6F, 8);

  addKey("Video", AuxInput_Key, 0x70, 8);
  addKey("Input A", ComponentInput_Key, 0x71, 8); // "Component"
  addKey("D/Scart", ScartInput_Key, 0x72, 8);
  addKey("HDMI", HDMIInput_Key, 0x73, 8);
  addKey("USB Display", USBInput_Key, 0x74, 8);
  addKey("Slideshow", Unmapped_Key, 0x76, 8);

  addKey("Gamma", Unmapped_Key, 0x7E, 8);

  addKey("Surround", Surround_Key, 0x81, 8);
  addKey("ESC", Exit_Key, 0x84, 8); // "exit", "Right mouse button"
  addKey("SELECT", Select_Key, 0x85, 8); // "enter", "Left mouse button"
  addKey("Page Up", PageUp_Key, 0x86, 8);
  addKey("Page Down", PageDown_Key, 0x87, 8);
  addKey("Zoom In", Unmapped_Key, 0x88, 8);
  addKey("Zoom Out", Unmapped_Key, 0x89, 8);
  addKey("ASPECT", AspectRatio_Key, 0x8A, 8);
  addKey("MEMORY", Memory_Key, 0x8B, 8);
  addKey("Search", Unmapped_Key, 0x8C, 8); // "InputNext"
  addKey("COLOR-MODE", PictureMode_Key, 0x8F, 8);

  addKey("POWER", Power_Key, 0x90, 8);
  addKey("Power on", PowerOn_Key, 0x90, 8);
  addKey("Power on", Green_Key, 0x90, 8); // This is a hack
  addKey("Power off", PowerOff_Key, 0x91, 8);
  addKey("Power off", Red_Key, 0x91, 8); // also hack
  addKey("PAUSE", Pause_Key, 0x92, 8);
  addKey("MUTE", Mute_Key, 0x93, 8); // "Blank"
  addKey("Computer", Unmapped_Key, 0x94, 8);
  addKey("Help", Info_Key, 0x95, 8);
  addKey("Pattern", Unmapped_Key, 0x96, 8);
  addKey("Sleep", Sleep_Key, 0x97, 8);
  addKey("Volume +", VolumeUp_Key, 0x98, 8);
  addKey("Volume -", VolumeDown_Key, 0x99, 8);
  addKey("MENU", Menu_Key, 0x9A, 8);
  addKey("Blank 9", Unmapped_Key, 0x9B, 8); // Dunno
  addKey("VIDEO", SVideoInput_Key, 0x9C, 8);
  addKey("INPUT-A-B", Input_Key, 0x9D, 8);
  addKey("AUTO", Unmapped_Key, 0x9E, 8); // Auto also at 0xAF
  addKey("Blank 3", Unmapped_Key, 0x9F, 8); // Dunno

  addKey("0", Zero_Key, 0xA0, 8);
  addKey("1", One_Key, 0xA1, 8);
  addKey("2", Two_Key, 0xA2, 8);
  addKey("3", Three_Key, 0xA3, 8);
  addKey("4", Four_Key, 0xA4, 8);
  addKey("5", Five_Key, 0xA5, 8);
  addKey("6", Six_Key, 0xA6, 8);
  addKey("7", Seven_Key, 0xA7, 8);
  addKey("8", Eight_Key, 0xA8, 8);
  addKey("9", Nine_Key, 0xA9, 8);

  addKey("UP", Up_Key, 0xB0, 8);
  addKey("RIGHT", Right_Key, 0xB1, 8);
  addKey("DOWN", Down_Key, 0xB2, 8);
  addKey("LEFT", Left_Key, 0xB3, 8);
}


void EpsonProjector1::populateInputList(
  QComboBox *cb) const
{
  cb->clear();

  cb->addItem("Video", QVariant(AuxInput_Key));
  cb->addItem("Input A / Component", QVariant(ComponentInput_Key));
  cb->addItem("D / SCART", QVariant(ScartInput_Key));
  cb->addItem("HDMI", QVariant(HDMIInput_Key));
  cb->addItem("USB Display", QVariant(USBInput_Key));
  cb->addItem("Video 2", QVariant(SVideoInput_Key));
  cb->addItem("Input A-B", QVariant(Input_Key));
}


EpsonProjector1a::EpsonProjector1a(
  unsigned int index)
  : EpsonProjector1(index)
{
  setKeysetName("Projector Keyset 1a");
}


void EpsonProjector1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  EpsonProjector1::populateProtocol(guiObject);

  addKey("1", One_Key, 0x51, 8);  // Dunno about this one
  addKey("DirectionUp", Up_Key, 0x61, 8);
  addKey("DirectionLeft", Left_Key, 0x63, 8);
  addKey("DirectionRight", Right_Key, 0x64, 8);
  addKey("Setup", Menu_Key, 0x65, 8);
  addKey("DirectionDown", Down_Key, 0x66, 8);
  addKey("VisualStep", Unmapped_Key, 0x9A, 8);
}


// The following is probably from a bad config file:
/*
EpsonProjector1::EpsonProjector1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Projector Keyset 1",
      Epson_Make,
      index)
{
}


void EpsonProjector1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, false);

  setPreData(0x5583, 16);

  addKey("esc", Exit_Key, 0x84, 8);
  addKey("enter", Select_Key, 0x85, 8);
  addKey("pageup", PageUp_Key, 0x86, 8);
  addKey("pagedown", PageDown_Key, 0x87, 8);
  addKey("zoom+", ChannelUp_Key, 0x88, 8);
  addKey("zoom-", ChannelDown_Key, 0x89, 8);
  addKey("3", Three_Key, 0x8A, 8);
  addKey("0", Zero_Key, 0x8C, 8);
  addKey("6", Six_Key, 0x8F, 8);

  addKey("power", Power_Key, 0x90, 8);
  addKey("9", Nine_Key, 0x92, 8);
  addKey("8", Eight_Key, 0x93, 8);
  addKey("4", Four_Key, 0x94, 8);
  addKey("5", Five_Key, 0x95, 8);
  addKey("2", Two_Key, 0x96, 8);
  addKey("1", One_Key, 0x97, 8);
  addKey("vol+", VolumeUp_Key, 0x98, 8);
  addKey("vol-", VolumeDown_Key, 0x99, 8);
  addKey("menu", Menu_Key, 0x9A, 8);
  addKey("7", Seven_Key, 0x9B, 8);
  addKey("?", Guide_Key, 0x9F, 8);

  addKey("up", Up_Key, 0xB0, 8);
  addKey("right", Right_Key, 0xB1, 8);
  addKey("down", Down_Key, 0xB2, 8);
  addKey("left", Left_Key, 0xB3, 8);
}
*/
