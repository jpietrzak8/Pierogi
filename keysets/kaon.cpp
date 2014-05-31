//
// kaon.cpp
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

#include "kaon.h"
#include "protocols/necprotocol.h"
#include <QComboBox>


KaonSat1::KaonSat1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Sat Keyset 1",
      Kaon_Make,
      TV_Panels,
      index)
{
}


void KaonSat1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x0820, 16);

  addKey("POWER", Power_Key, 0x00, 8);
  addKey("PSIZE", AspectRatio_Key, 0x01, 8);
  addKey("VOLUP", VolumeUp_Key, 0x02, 8);
  addKey("VOLDOWN", VolumeDown_Key, 0x03, 8);
  addKey("MUTE", Mute_Key, 0x04, 8);
  addKey("TV/RADIO", TunerInput_Key, 0x05, 8);
  addKey("CHUP", ChannelUp_Key, 0x06, 8);
  addKey("CHDOWN", ChannelDown_Key, 0x07, 8);
  addKey("TV/STB", Input_Key, 0x08, 8);
  addKey("ACOUNT", Unmapped_Key, 0x09, 8); // "VFormat"
  addKey("ALR", Unmapped_Key, 0x0A, 8);
  addKey("ALANG", Audio_Key, 0x0B, 8);
  addKey("RECALL", PrevChannel_Key, 0x0C, 8);
  addKey("EPG", Guide_Key, 0x0D, 8);
  addKey("TEXT", Teletext_Key, 0x0E, 8);

  addKey("EXIT", Exit_Key, 0x10, 8);
  addKey("MENU", Menu_Key, 0x11, 8);
  addKey("UP", Up_Key, 0x12, 8);
  addKey("DOWN", Down_Key, 0x13, 8);
  addKey("LEFT", Left_Key, 0x14, 8);
  addKey("OK", Select_Key, 0x15, 8);
  addKey("RIGHT", Right_Key, 0x16, 8);
  addKey("RED", Red_Key, 0x18, 8);
  addKey("GREEN", Green_Key, 0x19, 8);
  addKey("YELLOW", Yellow_Key, 0x1A, 8);
  addKey("BLUE", Blue_Key, 0x1B, 8);
  addKey("1", One_Key, 0x1C, 8);
  addKey("2", Two_Key, 0x1D, 8);
  addKey("3", Three_Key, 0x1E, 8);
  addKey("SLEEP", Sleep_Key, 0x1F, 8);

  addKey("4", Four_Key, 0x40, 8);
  addKey("5", Five_Key, 0x41, 8);
  addKey("6", Six_Key, 0x42, 8);
  addKey("FAV", Favorites_Key, 0x43, 8);
  addKey("7", Seven_Key, 0x44, 8);
  addKey("8", Eight_Key, 0x45, 8);
  addKey("9", Nine_Key, 0x46, 8);
  addKey("0", Zero_Key, 0x47, 8);
}


void KaonSat1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("TV - Radio", QVariant(TunerInput_Key));
  cb->addItem("TV - STB", QVariant(Input_Key));
}
