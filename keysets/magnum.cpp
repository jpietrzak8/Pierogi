//
// magnum.cpp
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

#include "magnum.h"
#include "protocols/rc5protocol.h"
#include <QComboBox>


MagnumTV1::MagnumTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Magnum_Make,
      index)
{
}


void MagnumTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

  addKey("OK", Select_Key, 0x0057, 13);
  addKey("TOP10", Favorites_Key, 0x0058, 13);
  addKey("CONTRAST+", ContrastUp_Key, 0x0070, 13);
  addKey("CONTRAST-", ContrastDown_Key, 0x0071, 13);

  addKey("AV", CableInput_Key, 0x1040, 13);
  addKey("1", One_Key, 0x1041, 13);
  addKey("2", Two_Key, 0x1042, 13);
  addKey("3", Three_Key, 0x1043, 13);
  addKey("4", Four_Key, 0x1044, 13);
  addKey("5", Five_Key, 0x1045, 13);
  addKey("6", Six_Key, 0x1046, 13);
  addKey("7", Seven_Key, 0x1047, 13);
  addKey("8", Eight_Key, 0x1048, 13);
  addKey("9", Nine_Key, 0x1049, 13);
  addKey("POWER", Power_Key, 0x104D, 13);

  addKey("TV", Input_Key, 0x1051, 13);
  addKey("EYE", Unmapped_Key, 0x1052, 13);
  addKey("MUTE", Mute_Key, 0x1053, 13);
  addKey("RED", Red_Key, 0x1054, 13);
  addKey("GREEN", Green_Key, 0x1055, 13);
  addKey("YELLOW", Yellow_Key, 0x1056, 13);
  addKey("BLUE", Blue_Key, 0x1057, 13);

  addKey("P+", ChannelUp_Key, 0x1060, 13);
  addKey("P+", Up_Key, 0x1060, 13);
  addKey("P-", ChannelDown_Key, 0x1061, 13);
  addKey("P-", Down_Key, 0x1061, 13);
  addKey("BRIGHTNESS-", BrightnessDown_Key, 0x1065, 13);
  addKey("BRIGHTNESS+", BrightnessUp_Key, 0x1066, 13);
  addKey("HELP", Guide_Key, 0x1069, 13);

  addKey("LEFT", Left_Key, 0x1075, 13);
  addKey("LEFT", VolumeDown_Key, 0x1075, 13); // just guessing here
  addKey("RIGHT", Right_Key, 0x1076, 13);
  addKey("RIGHT", VolumeUp_Key, 0x1076, 13);  // more guesswork
  addKey("MENU", Menu_Key, 0x1077, 13);
}


void MagnumTV1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("TV", QVariant(Input_Key));
  cb->addItem("AV", QVariant(CableInput_Key));
}
