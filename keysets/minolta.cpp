//
// minolta.cpp
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

#include "minolta.h"

#include "protocols/lircprotocol.h"


MinoltaCamera1::MinoltaCamera1(
  unsigned int index)
  : PIRKeysetMetaData(
      "RC-3 Keyset",
      Minolta_Make,
      Camera_Panels,
      index)
{
}


void MinoltaCamera1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  LIRCProtocol *lp = new LIRCProtocol(
    guiObject, index,
    527, 436,
    527, 1331,
    9052, false);

  threadableProtocol = lp;

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  lp->setHeaderPair(3872, 1708);
  lp->setTrailerPulse(527);

  addKey("one_sec", OpenShutter_Key, 0x2C538280, 32);
  addKey("two_sec", DelayedOpenShutter_Key, 0x2C538200, 32);
}
