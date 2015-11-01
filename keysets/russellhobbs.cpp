//
// russellhobbs.cpp
//
// Copyright 2014 - 2015 by John Pietrzak (jpietrzak8@gmail.com)
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
// along with Pierogi; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//

#include "russellhobbs.h"
#include "protocols/airtechprotocol.h"

RussellHobbsFan1::RussellHobbsFan1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Fan Keyset 1",
      RussellHobbs_Make,
      ACFan_Panels,
      index)
{
}


void RussellHobbsFan1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new AirtechProtocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x6C, 7);
  
  addKey("power", Power_Key, 0x01, 5);
  addKey("speed", Fan_Key, 0x02, 5);
  addKey("wind effect", Mode_Key, 0x04, 5);
  addKey("timer", Timer_Key, 0x08, 5);
  addKey("oscillate", Oscillate_Key, 0x10, 5);
}
