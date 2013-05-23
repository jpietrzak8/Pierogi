//
// philco.cpp
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

#include "philco.h"
#include "protocols/necprotocol.h"

PhilcoTV::PhilcoTV(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Philco_Make,
      index)
{
}


void PhilcoTV::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x50, 8);

  addKey("EIGHT", Eight_Key, 0x04, 8);
  addKey("NINE", Nine_Key, 0x05, 8);
  addKey("XPRESS", Unmapped_Key, 0x06, 8);
  addKey("GUIDE", Guide_Key, 0x07, 8);
  addKey("SAP", Audio_Key, 0x08, 8);
  addKey("TVAV", Input_Key, 0x09, 8);
  addKey("LASTCH", PrevChannel_Key, 0x0A, 8);
  addKey("MUTE", Mute_Key, 0x0B, 8);
  addKey("ZERO", Zero_Key, 0x0C, 8);
  addKey("ONE", One_Key, 0x0D, 8);
  addKey("TWO", Two_Key, 0x0E, 8);
  addKey("THREE", Three_Key, 0x0F, 8);

  addKey("DISPLAY", Info_Key, 0x10, 8);
  addKey("TIMER", Sleep_Key, 0x11, 8);
  addKey("VOL+", VolumeUp_Key, 0x12, 8);
  addKey("PREF", Unmapped_Key, 0x13, 8);
  addKey("VOL-", VolumeDown_Key, 0x15, 8);
  addKey("POWER", Power_Key, 0x17, 8);
  addKey("CHANNEL-", ChannelDown_Key, 0x18, 8);
  addKey("CHANNEL+", ChannelUp_Key, 0x19, 8);
  addKey("FOUR", Four_Key, 0x1C, 8);
  addKey("FIVE", Five_Key, 0x1D, 8);
  addKey("SIX", Six_Key, 0x1E, 8);
  addKey("SEVEN", Seven_Key, 0x1F, 8);

  addKey("MAGIC", Unmapped_Key, 0x5B, 8);
  addKey("MENU", Menu_Key, 0x5E, 8);
}
