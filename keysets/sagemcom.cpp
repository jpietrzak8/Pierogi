//
// sagemcom.cpp
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

#include "sagemcom.h"
#include "protocols/mceprotocol.h"
#include "protocols/nokia32protocol.h"
#include <QComboBox>


SagemcomSTB1::SagemcomSTB1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Digital Receiver Keyset 1",
      Sagemcom_Make,
      TV_Panels,
      index)
{
  addControlledDevice(Sagemcom_Make, "DSTIH78", Other_Device);
}


void SagemcomSTB1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new MCEProtocol(guiObject, index, 0x8070);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x26, 7);

  addKey("num_0", Zero_Key, 0x00, 8);
  addKey("num_1", One_Key, 0x01, 8);
  addKey("num_2", Two_Key, 0x02, 8);
  addKey("num_3", Three_Key, 0x03, 8);
  addKey("num_4", Four_Key, 0x04, 8);
  addKey("num_5", Five_Key, 0x05, 8);
  addKey("num_6", Six_Key, 0x06, 8);
  addKey("num_7", Seven_Key, 0x07, 8);
  addKey("num_8", Eight_Key, 0x08, 8);
  addKey("num_9", Nine_Key, 0x09, 8);
  addKey("Power", Power_Key, 0x0C, 8);
  addKey("Mute", Mute_Key, 0x0D, 8);
  addKey("Info", Info_Key, 0x0F, 8);

  addKey("VOL+", VolumeUp_Key, 0x10, 8);
  addKey("VOL-", VolumeDown_Key, 0x11, 8);
  addKey("CH+", ChannelUp_Key, 0x1E, 8);
  addKey("CH-", ChannelDown_Key, 0x1F, 8);
 
  addKey("Menu", Menu_Key, 0x54, 8);
  addKey("up_arrow", Up_Key, 0x58, 8);
  addKey("down_arrow", Down_Key, 0x59, 8);
  addKey("left_arrow", Left_Key, 0x5A, 8);
  addKey("right_arrow", Right_Key, 0x5B, 8);
  addKey("Select", Select_Key, 0x5C, 8);

  addKey("Red", Red_Key, 0x6D, 8);
  addKey("Green", Green_Key, 0x6E, 8);
  addKey("Yellow", Yellow_Key, 0x6F, 8);
  addKey("Blue", Blue_Key, 0x70, 8);

  addKey("Exit", Exit_Key, 0x83, 8);
  addKey("GVT", Guide_Key, 0xA2, 8); // Not sure what GVT is...
  addKey("Last_ch", PrevChannel_Key, 0xA9, 8);
  addKey("Guide", DiscMenu_Key, 0xCC, 8); // This should be the guide...
  addKey("@", Unmapped_Key, 0xFB, 8);
}


SagemcomSTB2::SagemcomSTB2(
  unsigned int index)
  : PIRKeysetMetaData(
      "Digital Receiver Keyset 2",
      Sagemcom_Make,
      TV_Panels | MediaControl_Panels | MediaRecord_Panels,
      index)
{
}


void SagemcomSTB2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new Nokia32Protocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x2670, 16);
  setPostData(0x26, 7);

  addKey("num_0", Zero_Key, 0x00, 8);
  addKey("num_1", One_Key, 0x01, 8);
  addKey("num_2", Two_Key, 0x02, 8);
  addKey("num_3", Three_Key, 0x03, 8);
  addKey("num_4", Four_Key, 0x04, 8);
  addKey("num_5", Five_Key, 0x05, 8);
  addKey("num_6", Six_Key, 0x06, 8);
  addKey("num_7", Seven_Key, 0x07, 8);
  addKey("num_8", Eight_Key, 0x08, 8);
  addKey("num_9", Nine_Key, 0x09, 8);
  addKey("Power", Power_Key, 0x0C, 8);
  addKey("Mute", Mute_Key, 0x0E, 8);
  addKey("Info", Info_Key, 0x0F, 8);
  addKey("VOL+", VolumeUp_Key, 0x10, 8);
  addKey("VOL-", VolumeDown_Key, 0x11, 8);
  addKey("CH+", ChannelUp_Key, 0x20, 8);
  addKey("CH-", ChannelDown_Key, 0x21, 8);
  addKey("ffwd", FastForward_Key, 0x28, 8);
  addKey("rewind", Rewind_Key, 0x29, 8);
  addKey("Play", Play_Key, 0x2C, 8);
  addKey("Pause", Pause_Key, 0x2C, 8);
  addKey("Stop", Stop_Key, 0x31, 8);
  addKey("Record", Record_Key, 0x37, 8);
  addKey("Teletext", Teletext_Key, 0x3C, 8);
  addKey("TV/Radio", TunerInput_Key, 0x43, 8);
  addKey("Menu", Menu_Key, 0x54, 8);
  addKey("up_arrow", Up_Key, 0x58, 8);
  addKey("down_arrow", Down_Key, 0x59, 8);
  addKey("left_arrow", Left_Key, 0x5A, 8);
  addKey("right_arrow", Right_Key, 0x5B, 8);
  addKey("Select", Select_Key, 0x5C, 8);
  addKey("Red", Red_Key, 0x6D, 8);
  addKey("Green", Green_Key, 0x6E, 8);
  addKey("Yellow", Yellow_Key, 0x6F, 8);
  addKey("Blue", Blue_Key, 0x70, 8);
  addKey("Search", Unmapped_Key, 0x81, 8);
  addKey("Last_ch", PrevChannel_Key, 0x83, 8);
  addKey("TV", Input_Key, 0xA6, 8);
  addKey("TV/Video", AuxInput_Key, 0xA7, 8);
  addKey("Guide", Guide_Key, 0xCC, 8);
  addKey("Option", Unmapped_Key, 0xDB, 8);
  addKey("exit", Exit_Key, 0xEE, 8);
  addKey("Recordings", Unmapped_Key, 0xF0, 8);
  addKey("Select Video", Unmapped_Key, 0xFD, 8);
}


void SagemcomSTB2::populateInputList(
  QComboBox *cb) const
{
  cb->clear();

  cb->addItem("TV", QVariant(Input_Key));
  cb->addItem("TV / Radio", QVariant(TunerInput_Key));
  cb->addItem("TV / Video", QVariant(AuxInput_Key));
}
