//
// multichoice.cpp
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

#include "multichoice.h"
#include "protocols/rc5protocol.h"
#include "protocols/xmpprotocol.h"
#include <QComboBox>


MultichoiceSTB1::MultichoiceSTB1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Decoder Keyset 1",
      Multichoice_Make,
      TV_Panels,
      index)
{
}


void MultichoiceSTB1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

  addKey("0", Zero_Key, 0x1600, 13);
  addKey("1", One_Key, 0x1601, 13);
  addKey("2", Two_Key, 0x1602, 13);
  addKey("3", Three_Key, 0x1603, 13);
  addKey("4", Four_Key, 0x1604, 13);
  addKey("5", Five_Key, 0x1605, 13);
  addKey("6", Six_Key, 0x1606, 13);
  addKey("7", Seven_Key, 0x1607, 13);
  addKey("8", Eight_Key, 0x1608, 13);
  addKey("9", Nine_Key, 0x1609, 13);
  addKey("power", Power_Key, 0x160C, 13);
  addKey("Mute", Mute_Key, 0x160D, 13);

  addKey("volup", VolumeUp_Key, 0x1610, 13);
  addKey("voldown", VolumeDown_Key, 0x1611, 13);
  addKey("up", Up_Key, 0x1612, 13);
  addKey("down", Down_Key, 0x1613, 13);

  addKey("menu", Menu_Key, 0x161C, 13);
  addKey("left", Left_Key, 0x161D, 13);
  addKey("right", Right_Key, 0x161E, 13);

  addKey("progup", ChannelUp_Key, 0x1620, 13);
  addKey("progdn", ChannelDown_Key, 0x1621, 13);
  addKey("ok", Select_Key, 0x1622, 13);
//  addKey("teletext", Unmapped_Key, 0x1624, 13);
  addKey("Subtitle", Captions_Key, 0x1624, 13);
  addKey("radio", TunerInput_Key, 0x1625, 13);
  addKey("FFWD", FastForward_Key, 0x1625, 13);
  addKey("yellow", Yellow_Key, 0x162A, 13);
  addKey("Record", Record_Key, 0x162A, 13);
  addKey("green", Green_Key, 0x162B, 13);
  addKey("Stop", Stop_Key, 0x162B, 13);
  addKey("red", Red_Key, 0x162C, 13);
  addKey("SP/LP", VHSSpeed_Key, 0x162C, 13);
  addKey("information", Info_Key, 0x162D, 13);
  addKey("Stop", Stop_Key, 0x162D, 13);
  addKey("blue", Blue_Key, 0x162E, 13);
  addKey("Play", Play_Key, 0x162E, 13);
  addKey("tv", Input_Key, 0x162F, 13);

  addKey("exit", Exit_Key, 0x1631, 13);
  addKey("Last/Prev Ch", PrevChannel_Key, 0x1631, 13);
  addKey("tvguide", Guide_Key, 0x1635, 13);
}


void MultichoiceSTB1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("TV", QVariant(Input_Key));
  cb->addItem("Radio", QVariant(TunerInput_Key));
}


MultichoiceSTB2::MultichoiceSTB2(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Decoder Keyset 2",
      Multichoice_Make,
      TV_Panels,
      index)
{
}


void MultichoiceSTB2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new XMPProtocol(
    guiObject, index, 0x1, 0x1, 0x44, 0x47, false);

  addXMPKey("0", Zero_Key, 0x00, 0x00);
  addXMPKey("1", One_Key, 0x01, 0x00);
  addXMPKey("2", Two_Key, 0x02, 0x00);
  addXMPKey("3", Three_Key, 0x03, 0x00);
  addXMPKey("4", Four_Key, 0x04, 0x00);
  addXMPKey("5", Five_Key, 0x05, 0x00);
  addXMPKey("6", Six_Key, 0x06, 0x00);
  addXMPKey("7", Seven_Key, 0x07, 0x00);
  addXMPKey("8", Eight_Key, 0x08, 0x00);
  addXMPKey("9", Nine_Key, 0x09, 0x00);
  addXMPKey("Mute", Mute_Key, 0x0C, 0x00);
  addXMPKey("Power", Power_Key, 0x0F, 0x00);
  addXMPKey("Menu", Menu_Key, 0x25, 0x00);
  addXMPKey("TV Guide", Guide_Key, 0x27, 0x00);
  addXMPKey("Stop", Stop_Key, 0x30, 0x00);
  addXMPKey("Rewind", Rewind_Key, 0x31, 0x00);
  addXMPKey("Play/Pause", Play_Key, 0x32, 0x00);
  addXMPKey("Play/Pause", Pause_Key, 0x32, 0x00);
  addXMPKey("Fast Forward", FastForward_Key, 0x33, 0x00);
  addXMPKey("Record", Record_Key, 0x34, 0x00);
  addXMPKey("Fastext Red", Red_Key, 0x40, 0x00);
  addXMPKey("Fastext Blue", Blue_Key, 0x41, 0x00);
  addXMPKey("Fastext White", Unmapped_Key, 0x42, 0x00);
  addXMPKey("Fastext Yellow", Yellow_Key, 0x43, 0x00);
  addXMPKey("Fastext Green", Green_Key, 0x44, 0x00);
  addXMPKey("TV", Unmapped_Key, 0x50, 0x00);
  addXMPKey("Alt", Unmapped_Key, 0x51, 0x00);
  addXMPKey("Language", Audio_Key, 0x52, 0x00);
  addXMPKey("Help", Unmapped_Key, 0x53, 0x00);
  addXMPKey("<Shift> TV (Audio)", Unmapped_Key, 0x58, 0x00);
  addXMPKey("<Shift> Alt (Subtitle)", Captions_Key, 0x59, 0x00);
  addXMPKey("<Shift> TV Guide (iTV)", Unmapped_Key, 0x5A, 0x00);
  addXMPKey("<Shift> Language (PG)", Unmapped_Key, 0x5B, 0x00);
  addXMPKey("<Shift> Mute", Unmapped_Key, 0x5C, 0x00);
  addXMPKey("<Shift> Info", Unmapped_Key, 0x5D, 0x00);
  addXMPKey("<Shift> Exit (Input)", Input_Key, 0x5E, 0x00);
  addXMPKey("<Shift> Up", Unmapped_Key, 0x5F, 0x00);
  addXMPKey("<Shift> Left", Unmapped_Key, 0x60, 0x00);
  addXMPKey("<Shift> OK", Unmapped_Key, 0x61, 0x00);
  addXMPKey("<Shift> Right", Unmapped_Key, 0x62, 0x00);
  addXMPKey("<Shift> Down", Unmapped_Key, 0x63, 0x00);
  addXMPKey("<Shift> Stop", Unmapped_Key, 0x64, 0x00);
  addXMPKey("<Shift> Record", Unmapped_Key, 0x65, 0x00);
  addXMPKey("<Shift> Program Down", Unmapped_Key, 0x66, 0x00);
  addXMPKey("<Shift> Program Up", Unmapped_Key, 0x67, 0x00);
  addXMPKey("<Shift> Menu", Unmapped_Key, 0x6F, 0x00);
  addXMPKey("<Shift> Help", Unmapped_Key, 0x70, 0x00);
  addXMPKey("<Shift> Red", Unmapped_Key, 0x71, 0x00);
  addXMPKey("<Shift> Blue", Unmapped_Key, 0x72, 0x00);
  addXMPKey("<Shift> White", Unmapped_Key, 0x73, 0x00);
  addXMPKey("<Shift> Yellow", Unmapped_Key, 0x74, 0x00);
  addXMPKey("<Shift> Green", Unmapped_Key, 0x75, 0x00);
  addXMPKey("Volume Up", VolumeUp_Key, 0x83, 0x00);
  addXMPKey("Volume Down", VolumeDown_Key, 0x84, 0x00);
  addXMPKey("Program Down", ChannelDown_Key, 0x85, 0x00);
  addXMPKey("Program Up", ChannelUp_Key, 0x86, 0x00);
  addXMPKey("Down", Down_Key, 0x87, 0x00);
  addXMPKey("Right", Right_Key, 0x88, 0x00);
  addXMPKey("OK", Select_Key, 0x8B, 0x00);
  addXMPKey("Left", Left_Key, 0x8C, 0x00);
  addXMPKey("Up", Up_Key, 0x8D, 0x00);
  addXMPKey("Exit", Exit_Key, 0x8E, 0x00);
  addXMPKey("Info", Info_Key, 0x8F, 0x00);
}
