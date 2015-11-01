//
// wiwa.cpp
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

#include "wiwa.h"
#include "protocols/paceprotocol.h"

WiwaSTB1::WiwaSTB1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Receiver Keyset 1",
      Wiwa_Make,
      TV_Panels | MediaControl_Panels | MediaRecord_Panels,
      index)
{
}


void WiwaSTB1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new PaceProtocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x0, 3);

  addKey("0", Zero_Key, 0x00, 6);
  addKey("1", One_Key, 0x01, 6);
  addKey("2", Two_Key, 0x02, 6);
  addKey("3", Three_Key, 0x03, 6);
  addKey("Skip +", Next_Key, 0x03, 6); // might be bad
  addKey("4", Four_Key, 0x04, 6);
  addKey("Sleep", Sleep_Key, 0x04, 6); // might be bad
  addKey("5", Five_Key, 0x05, 6);
  addKey("6", Six_Key, 0x06, 6);
  addKey("Rewind", Rewind_Key, 0x06, 6); // might be bad
  addKey("7", Seven_Key, 0x07, 6);
  addKey("8", Eight_Key, 0x08, 6);
  addKey("9", Nine_Key, 0x09, 6);
  addKey("100+", PlusOneHundred_Key, 0x0A, 6);
  addKey("Format 16:9", AspectRatio_Key, 0x0B, 6);
  addKey("FAV", Favorites_Key, 0x0B, 6);
  addKey("Pause", Pause_Key, 0x0B, 6);
  addKey("Play", Play_Key, 0x0F, 6);
  addKey("FFWD", FastForward_Key, 0x0F, 6);
  addKey("Yellow", Yellow_Key, 0x0F, 6);
  addKey("Audio", Audio_Key, 0x0F, 6);
  addKey("Power", Power_Key, 0x10, 6);
  addKey("CH+", ChannelUp_Key, 0x11, 6);
  addKey("Arrow_Right", Right_Key, 0x11, 6);
  addKey("OK/Select", Select_Key, 0x13, 6);
  addKey("Record", Record_Key, 0x13, 6);
  addKey("Arrow_Down", Down_Key, 0x14, 6);
  addKey("EXIT", Exit_Key, 0x15, 6);
  addKey("Menu", Menu_Key, 0x15, 6);
  addKey("CH-", ChannelDown_Key, 0x16, 6);
  addKey("Arrow_Left", Left_Key, 0x16, 6);
  addKey("Green", Green_Key, 0x17, 6);
  addKey("Volume +", VolumeUp_Key, 0x18, 6);
  addKey("Input/Source", Input_Key, 0x19, 6);
  addKey("Arrow_Up", Up_Key, 0x1A, 6);
  addKey("Guide", Guide_Key, 0x1A, 6);
  addKey("Last/Prev Ch", PrevChannel_Key, 0x1A, 6);
  addKey("Volume -", VolumeDown_Key, 0x1B, 6);
  addKey("Mute", Mute_Key, 0x1E, 6);
  addKey("Info/Display", Info_Key, 0x1F, 6);
  addKey("Stop", Stop_Key, 0x1F, 6);
  addKey("Slow", Slow_Key, 0x1F, 6);
}
