//
// generalelectric.cpp
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

#include "generalelectric.h"

#include "protocols/necprotocol.h"
#include "protocols/protonprotocol.h"


GeneralElectricAC1::GeneralElectricAC1(
  unsigned int index)
  : PIRKeysetMetaData(
      "AC Keyset 1",
      GeneralElectric_Make,
      ACFan_Panels,
      index)
{
}


void GeneralElectricAC1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x6681, 16);

  addKey("Power", Power_Key, 0x81, 8);
  addKey("Energy Saver", EnergySave_Key, 0x82, 8);
  addKey("Circulaire", Oscillate_Key, 0x83, 8);
  addKey("Temp+", TempUp_Key, 0x85, 8);
  addKey("Temp-", TempDown_Key, 0x8A, 8);
  addKey("Fan Speed", Fan_Key, 0x99, 8);
  addKey("Mode", Mode_Key, 0x9B, 8);
  addKey("Timer", Timer_Key, 0x9F, 8);
}


GeneralElectricAC2::GeneralElectricAC2(
  unsigned int index)
  : PIRKeysetMetaData(
      "AC Keyset 2",
      GeneralElectric_Make,
      ACFan_Panels,
      index)
{
}


void GeneralElectricAC2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new ProtonProtocol(guiObject, index);

  setPreData(0xD7, 8);

  addKey("delay -", Unmapped_Key, 0x00, 8);
  addKey("delay +", Unmapped_Key, 0x01, 8);
  addKey("delay", Unmapped_Key, 0x02, 8);
  addKey("mode", Mode_Key, 0x03, 8);
  addKey("fan -", FanSlower_Key, 0x04, 8);
  addKey("fan +", FanFaster_Key, 0x05, 8);
  addKey("temp +", TempUp_Key, 0x08, 8);
  addKey("temp -", TempDown_Key, 0x09, 8);
  addKey("fan auto", Fan_Key, 0x0A, 8);
  addKey("power", Power_Key, 0x0B, 8);
}



// Found this GE air conditioner LIRC file while browsing the net, need to
// study it:

/*
# this config file was automatically generated
# using lirc-0.9.0-pre1(emulation) on Sat Mar  2 14:09:22 2013
#
# contributed by Peter Li
#
# brand: GE
# model no. of remote control: 
# devices being controlled by this remote: All the GE wall mount air 
# conditioners look like they have very similar controls, so I would guess this 
# will work for all.  It will probably also work for the Heat/Cool wall models,
# other than the missing heat button, but I haven't tried that.
#

begin remote

    name  GE_AirConditioner
    bits           48
    flags SPACE_ENC
    eps            30
    aeps          100
    
    header       3388  1678
    one           430  1257
    zero          430   412
    ptrail        428
    gap          40991
    toggle_bit_mask 0x0
    
    begin codes
        on_stop                  0x555AF308598F
        cool                     0x555AF3081D8F
        fan                      0x555AF3085D8B
        tempup                   0x555AF308D987
        tempdown                 0x555AF308198B
        timeron                  0x555AF308D58B
        timeroff                 0x555AF308958F
        hi                       0x555AF308DD83
        mid                      0x555AF3083D8D
        low                      0x555AF308BD85
        sleep                    0x555AF3085583
    end codes
    
end remote
*/
