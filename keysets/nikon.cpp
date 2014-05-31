//
// nikon.cpp
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

#include "nikon.h"
#include "protocols/lircprotocol.h"


NikonDSLR1::NikonDSLR1(
  unsigned int index)
  : PIRKeysetMetaData(
      "ML-L3 Remote Keyset",
      Nikon_Make,
      Camera_Panels,
      index)
{
  addControlledDevice(Nikon_Make, "D70s DSLR Camera", Other_Device);
}


void NikonDSLR1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  LIRCProtocol *lp = new LIRCProtocol(
    guiObject, index,
    500, 1500,
    500, 3500,
    100000, true);

  threadableProtocol = lp;
  lp->setHeaderPair(2100, 27800);
  lp->setTrailerPulse(500);

  addKey("shutter", OpenShutter_Key, 0x1, 2);
}
