//
// hauppauge.cpp
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

#include "hauppauge.h"
#include "protocols/rc5protocol.h"

HauppaugePCTV1::HauppaugePCTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "PCTV Keyset 1",
      Hauppauge_Make,
      TV_Panels | MediaControl_Panels | MediaRecord_Panels,
      index)
{
  addControlledDevice(Hauppauge_Make, "PVR 350", Computer_Device);
}


void HauppaugePCTV1::populateProtocol(
  QObject *guiObject)
{

  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index, 0x5E);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  addKey("0", Zero_Key, 0x00, 6);
  addKey("1", One_Key, 0x01, 6);
  addKey("2", Two_Key, 0x02, 6);
  addKey("3", Three_Key, 0x03, 6);
  addKey("4", Four_Key, 0x04, 6);
  addKey("5", Five_Key, 0x05, 6);
  addKey("6", Six_Key, 0x06, 6);
  addKey("7", Seven_Key, 0x07, 6);
  addKey("8", Eight_Key, 0x08, 6);
  addKey("9", Nine_Key, 0x09, 6);
  addKey("Asterix", Unmapped_Key, 0x0A, 6);
  addKey("Red", Red_Key, 0x0B, 6);
  addKey("Radio", Unmapped_Key, 0x0C, 6);
  addKey("Menu/i", Menu_Key, 0x0D, 6);
  addKey("sub/cc", Captions_Key, 0x0E, 6); // "Recordings"
  addKey("Mute", Mute_Key, 0x0F, 6);
  addKey("Vol+", VolumeUp_Key, 0x10, 6);
  addKey("Vol-", VolumeDown_Key, 0x11, 6);
  addKey("Prev.Ch", PrevChannel_Key, 0x12, 6);
  addKey("Up", Up_Key, 0x14, 6);
  addKey("Down", Down_Key, 0x15, 6);
  addKey("Left", Left_Key, 0x16, 6);
  addKey("Right", Right_Key, 0x17, 6);
  addKey("Videos", Unmapped_Key, 0x18, 6);
  addKey("Music", Unmapped_Key, 0x19, 6);
  addKey("Pictures", Unmapped_Key, 0x1A, 6);
  addKey("Guide", Guide_Key, 0x1B, 6);
  addKey("TV", Unmapped_Key, 0x1C, 6);
  addKey("SkipForward", Next_Key, 0x1E, 6);
  addKey("Back/Exit", Exit_Key, 0x1F, 6);
  addKey("Ch+", ChannelUp_Key, 0x20, 6);
  addKey("Ch-", ChannelDown_Key, 0x21, 6);
  addKey("Replay/SkipBackward", Previous_Key, 0x24, 6);
  addKey("Ok", Select_Key, 0x25, 6);
  addKey("minimize", Unmapped_Key, 0x26, 6);
  addKey("Blue", Blue_Key, 0x29, 6);
  addKey("Green", Green_Key, 0x2E, 6);
  addKey("Pause", Pause_Key, 0x30, 6);
  addKey("Rewind", Rewind_Key, 0x32, 6);
  addKey("Forward", FastForward_Key, 0x34, 6);
  addKey("Play", Play_Key, 0x35, 6);
  addKey("Stop", Stop_Key, 0x36, 6);
  addKey("Record", Record_Key, 0x37, 6);
  addKey("Yellow", Yellow_Key, 0x38, 6);
  addKey("Go", Unmapped_Key, 0x3B, 6);
  addKey("Power", Power_Key, 0x3D, 6);
}


HauppaugePCTV1a::HauppaugePCTV1a(
  unsigned int index)
  : HauppaugePCTV1(index)
{
  setKeysetName("PCTV Keyset 1a");

  addControlledDevice(Hauppauge_Make, "WinTV-HVR-950Q", Computer_Device);
}


void HauppaugePCTV1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  HauppaugePCTV1::populateProtocol(guiObject);

  setPreData(0x5D, 7);
}


HauppaugePCTV1b::HauppaugePCTV1b(
  unsigned int index)
  : HauppaugePCTV1(index)
{
  setKeysetName("PCTV Keyset 1b");

  addControlledDevice(Hauppauge_Make, "MVP", Computer_Device);
}


void HauppaugePCTV1b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  HauppaugePCTV1::populateProtocol(guiObject);

  setPreData(0x43, 7);

  addKey("KEY_FN_1", Unmapped_Key, 0x0C, 6);
  addKey("KEY_FN_2", Unmapped_Key, 0x3C, 6);
}


HauppaugePCTV1c::HauppaugePCTV1c(
  unsigned int index)
  : HauppaugePCTV1(index)
{
  setKeysetName("PCTV Keyset 1c");

  addControlledDevice(Hauppauge_Make, "PVR 250", Computer_Device);
//  addControlledDevice(Hauppauge_Make, "PVR 350", Computer_Device);
}


void HauppaugePCTV1c::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  HauppaugePCTV1::populateProtocol(guiObject);

  setPreData(0x5F, 7);

  addKey("blank", Unmapped_Key, 0x0C, 6);
  addKey("full", AspectRatio_Key, 0x3C, 6);  // full screen?
}


HauppaugePCTV2::HauppaugePCTV2(
  unsigned int index)
  : PIRKeysetMetaData(
      "PCTV Keyset 2",
      Hauppauge_Make,
      TV_Panels | MediaControl_Panels | MediaRecord_Panels,
      index)
{
  addControlledDevice(Hauppauge_Make, "PVR-250", Computer_Device);
}


// Based on LIRC Sony_RM-V302-DVD010 config file
void HauppaugePCTV2::populateProtocol(
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

  addKey("POWER", Power_Key, 0x150C, 13);
  addKey("1", One_Key, 0x1525, 13);
  addKey("2", Two_Key, 0x1526, 13);
  addKey("3", Three_Key, 0x1527, 13);
  addKey("4", Four_Key, 0x1519, 13);
  addKey("5", Five_Key, 0x153D, 13);
  addKey("6", Six_Key, 0x1516, 13);
  addKey("7", Seven_Key, 0x1517, 13);
  addKey("8", Eight_Key, 0x1518, 13);
  addKey("9", Nine_Key, 0x152B, 13);
  addKey("0", Zero_Key, 0x151D, 13);
  addKey("VOL+", VolumeUp_Key, 0x1810, 13);
  addKey("VOL-", VolumeDown_Key, 0x1811, 13);
  addKey("CH+", ChannelUp_Key, 0x1534, 13);
  addKey("CH-", ChannelDown_Key, 0x1533, 13);
  addKey("TV/VIDEO", Input_Key, 0x1500, 13);
  addKey("DISPLAY", Info_Key, 0x1532, 13);
  addKey("SLEEP", Sleep_Key, 0x1510, 13);
  addKey("MUTE", Mute_Key, 0x180D, 13);
  addKey("RECALL", PrevChannel_Key, 0x1501, 13);
  addKey("UP", Up_Key, 0x1502, 13);
  addKey("DOWN", Down_Key, 0x1508, 13);
  addKey("LEFT", Left_Key, 0x1504, 13);
  addKey("RIGHT", Right_Key, 0x1506, 13);
  addKey("MENU", Menu_Key, 0x1503, 13);
  addKey("OK", Enter_Key, 0x1505, 13);
  addKey("OK", Select_Key, 0x1505, 13);
  addKey("SEEK-", Rewind_Key, 0x1535, 13);
  addKey("PLAY", Play_Key, 0x1530, 13);
  addKey("SEEK+", FastForward_Key, 0x1536, 13);
  addKey("PAUSE", Pause_Key, 0x153C, 13);
  addKey("STOP", Stop_Key, 0x1520, 13);
}


/*
// Translation of DSR-0095 config file
HauppaugePCTV3::HauppaugePCTV3(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "PCTV Keyset 3",
      Hauppauge_Make,
      index)
{
  RC5Protocol *rp = new RC5Protocol(
    guiObject,
    index,
    900, 900,
    900,
    114000, true);

  threadableProtocol = rp;

  rp->setToggleBit(2);

  rp->setPreData(0x17, 5);

  addKey("home", Unmapped_Key, 0x7B, 8);
  addKey("choice", Unmapped_Key, 0x5B, 8);
  addKey("stop", Stop_Key, 0x77, 8);
}
*/
