//
// digitalstream.cpp
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

#include "digitalstream.h"
#include "protocols/necprotocol.h"


DigitalStreamReceiver::DigitalStreamReceiver(
  unsigned int index)
  : PIRKeysetMetaData(
      "Receiver Keyset 1",
      DigitalStream_Make,
      index)
{
  addControlledDevice(DigitalStream_Make, "DTX9900", Other_Device);
}


void DigitalStreamReceiver::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

//  setPreData(0x482C, 16);
  setPreData(0x3412, 16);

  addKey("Power", Power_Key, 0x00, 8);
  addKey("Ok", Select_Key, 0x01, 8);
  addKey("Up", Up_Key, 0x02, 8);
  addKey("Down", Down_Key, 0x03, 8);
  addKey("Left", Left_Key, 0x04, 8);
  addKey("Right", Right_Key, 0x05, 8);
  addKey("Vol+", VolumeUp_Key, 0x06, 8);
  addKey("Vol-", VolumeDown_Key, 0x07, 8);
  addKey("Channel+", ChannelUp_Key, 0x08, 8);
  addKey("Channel-", ChannelDown_Key, 0x09, 8);

  addKey("0", Zero_Key, 0x10, 8);
  addKey("1", One_Key, 0x11, 8);
  addKey("2", Two_Key, 0x12, 8);
  addKey("3", Three_Key, 0x13, 8);
  addKey("4", Four_Key, 0x14, 8);
  addKey("5", Five_Key, 0x15, 8);
  addKey("6", Six_Key, 0x16, 8);
  addKey("7", Seven_Key, 0x17, 8);
  addKey("8", Eight_Key, 0x18, 8);
  addKey("9", Nine_Key, 0x19, 8);
  addKey("-", Dash_Key, 0x1A, 8);
  addKey("Menu", Menu_Key, 0x1B, 8);
  addKey("Back", Exit_Key, 0x1D, 8);
  addKey("EPG", Guide_Key, 0x1E, 8);
  addKey("FAV", Favorites_Key, 0x1F, 8);

  addKey("Prev", PrevChannel_Key, 0x20, 8);
  addKey("Mute", Mute_Key, 0x22, 8);
  addKey("Audio", Audio_Key, 0x23, 8);
  addKey("Zoom", Zoom_Key, 0x24, 8);
  addKey("CC", Captions_Key, 0x25, 8);
  addKey("Info", Info_Key, 0x28, 8);  // "A/D"
  addKey("Meter", Unmapped_Key, 0x2C, 8);
}
