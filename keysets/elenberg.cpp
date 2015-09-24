//
// elenberg.cpp
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

#include "elenberg.h"
#include "protocols/lircprotocol.h"


Elenberg::Elenberg(
  unsigned int index)
  : PIRKeysetMetaData(
      "ELENBERG 35009168 (CAMERON RC-35/ AKIRA 1402)",
      Elenberg_Make,
      MediaControl_Panels,
      index)
{
}


void Elenberg::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  LIRCProtocol *lp = new LIRCProtocol(
    guiObject, index,
    500, 2500,
    500, 1500,
    100000, true);

  threadableProtocol = lp;

  lp->setHeaderPair(3000, 3000);

  addKey("POWER", Power_Key, 0x3F7D1, 18);
  addKey("MUTE", Mute_Key, 0x3F7AD, 18);
  addKey("MENU", Menu_Key, 0x3F7A9, 18);
  addKey("CH+", ChannelUp_Key, 0x3F7B9, 18);
  addKey("CH-", ChannelDown_Key, 0x3F7BD, 18);
  addKey("Volume +", VolumeUp_Key, 0x3F7B1, 18);
  addKey("Volume -", VolumeDown_Key, 0x3F7B5, 18);
  addKey("Sleep", Sleep_Key, 0x3F781, 18);
  addKey("TV/Video", Input_Key, 0x3F7D5, 18);
  
  addKey("CH+", Up_Key, 0x3F7B9, 18);
  addKey("CH-", Down_Key, 0x3F7BD, 18);
  addKey("Volume +", Right_Key, 0x3F7B1, 18);
  addKey("Volume -", Left_Key, 0x3F7B5, 18);
  addKey("Picture", PictureMode_Key, 0x3F7CD, 18);
  addKey("Info", Info_Key, 0x3F789, 18);
  addKey("Swap", Captions_Key, 0x3F7A1, 18);
  addKey("Select", Select_Key, 0x3F7A9, 18);
  addKey("Zoom", Zoom_Key, 0x3F78D, 18);
  addKey("Sound", SoundMode_Key, 0x3F7C1, 18);
  addKey("I/II", Audio_Key, 0x3F7C9, 18);
  
  addKey("Ptimer", Red_Key, 0x3F785, 18);
  addKey("tv", Green_Key, 0x3F791, 18);
  addKey("qviev", Yellow_Key, 0x3F7C5, 18);
  
  addKey("1", One_Key, 0x3F7F9, 18);
  addKey("2", Two_Key, 0x3F7F5, 18);
  addKey("3", Three_Key, 0x3F7F1, 18);
  addKey("4", Four_Key, 0x3F7ED, 18);
  addKey("5", Five_Key, 0x3F7E9, 18);
  addKey("6", Six_Key, 0x3F7E5, 18);
  addKey("7", Seven_Key,0x3F7E1, 18);
  addKey("8", Eight_Key, 0x3F7DD, 18);
  addKey("9", Nine_Key, 0x3F7D9, 18);
  addKey("0", Zero_Key, 0x3F7FD, 18);
}

