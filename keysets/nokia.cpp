//
// nokia.cpp
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

#include "nokia.h"
#include "protocols/lircprotocol.h"

NokiaGenericVCR::NokiaGenericVCR(
  unsigned int index)
  : PIRKeysetMetaData(
      "Generic VCR",
      Nokia_Make,
      index)
{
}


void NokiaGenericVCR::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  LIRCProtocol *lp = new LIRCProtocol(
    guiObject,
    index,
    272, 737,
    272, 1711,
    42100, false);

  threadableProtocol = lp;

  lp->setTrailerPulse(272);

//  lp->setMinimumRepetitions(3);

  setPreData(0x6, 3);

  addKey("Power", Power_Key, 0x1A2, 12);
  addKey("1", One_Key, 0x202, 12);
  addKey("2", Two_Key, 0x102, 12);
  addKey("3", Three_Key, 0x302, 12);
  addKey("4", Four_Key, 0x082, 12);
  addKey("5", Five_Key, 0x282, 12);
  addKey("6", Six_Key, 0x182, 12);
  addKey("7", Seven_Key, 0x382, 12);
  addKey("8", Eight_Key, 0x042, 12);
  addKey("9", Nine_Key, 0x242, 12);
  addKey("0", Zero_Key, 0x142, 12);
  addKey("Timer", Timer_Key, 0x262, 12);
  addKey("Clear", Clear_Key, 0x012, 12);
  addKey("P+", ChannelUp_Key, 0x222, 12);
  addKey("P-", ChannelDown_Key, 0x122, 12);
  addKey("Up", Up_Key, 0x112, 12);
  addKey("Down", Down_Key, 0x392, 12);
  addKey("Left", Left_Key, 0x312, 12);
  addKey("Right", Right_Key, 0x212, 12);
  addKey("Ok", Enter_Key, 0x166, 12);
  addKey("Ok", Select_Key, 0x166, 12);
  addKey("Red", Red_Key, 0x252, 12);
  addKey("Green", Green_Key, 0x292, 12);
  addKey("Yellow", Yellow_Key, 0x032, 12);
  addKey("Blue", Blue_Key, 0x3D2, 12);
  addKey("Rec", Record_Key, 0x052, 12);
  addKey("Clock", Clock_Key, 0x1C2, 12);
  addKey("Prog", Program_Key, 0x066, 12);
  addKey("PIP", PIP_Key, 0x0C6, 12);
}
