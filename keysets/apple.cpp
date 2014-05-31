//
// apple.cpp
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

#include "apple.h"
#include "protocols/lircprotocol.h"

// Based on LIRC Apple_A1156 config file
AppleWhiteRemote::AppleWhiteRemote(
  unsigned int index)
  : PIRKeysetMetaData(
      "White Remote",
      Apple_Make,
      MediaControl_Panels,
      index)
{
  addControlledDevice(Apple_Make, "Mac Mini", Computer_Device);
}


void AppleWhiteRemote::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  // Set up the threadable object:
  LIRCProtocol *lp = new LIRCProtocol(
    guiObject, index,
    560, 560,
    560, 1680,
    110000, true);

  threadableProtocol = lp;

  lp->setHeaderPair(9000, 4500);
  lp->setTrailerPulse(560);
  lp->setRepeatPair(9000, 2250);

  setPreData(0x77e1, 16);
  setPostData(0xc5, 8);

// Menu oriented:
  addKey("menu", Menu_Key, 0x40, 8);
  addKey("+", Up_Key, 0xD0, 8);
  addKey("-", Down_Key, 0xB0, 8);
  addKey("|<<", Left_Key, 0x10, 8);
  addKey(">>|", Right_Key, 0xE0, 8);
  addKey(">||", Select_Key, 0x20, 8);

// Media oriented:
  addKey("+", VolumeUp_Key, 0xD0, 8);
  addKey("-", VolumeDown_Key, 0xB0, 8);
  addKey("|<<", Rewind_Key, 0x10, 8);
  addKey(">>|", FastForward_Key, 0xE0, 8);
  addKey(">||", Play_Key, 0x20, 8);
  addKey(">||", Pause_Key, 0x20, 8);
  addKey("|<<", Previous_Key, 0x10, 8);
  addKey(">>|", Next_Key, 0xE0, 8);
}
