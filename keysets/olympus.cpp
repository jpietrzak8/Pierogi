//
// olympus.cpp
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

#include "olympus.h"
#include "protocols/necprotocol.h"

OlympusCamera1::OlympusCamera1(
  unsigned int index)
  : PIRKeysetMetaData(
      "RM-2 Remote Keyset",
      Olympus_Make,
      Camera_Panels,
      index)
{
  addControlledDevice(Olympus_Make, "410 Digital", Other_Device);
}


void OlympusCamera1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x3B86, 16);

  addKey("CAPTURE", OpenShutter_Key, 0x01, 8);
}
