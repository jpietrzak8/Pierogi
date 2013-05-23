//
// pirdevicetypenames.cpp
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

#include "pirdevicetypenames.h"

#include <QComboBox>

PIRDeviceTypeMgr::PIRDeviceTypeMgr()
{
  devices[Any_Device] = "Any";
  devices[TV_Device] = "TV";
  devices[Sat_Device] = "Sat Receiver";
  devices[VCR_Device] = "VCR";
  devices[DVD_Device] = "DVD";
  devices[Audio_Device] = "Audio";
  devices[Computer_Device] = "Computer";
  devices[Other_Device] = "Other";
}

const char *PIRDeviceTypeMgr::getDeviceString(
  PIRDeviceTypeName n)
{
  return devices[n];
}

void PIRDeviceTypeMgr::populateComboBox(
  QComboBox *cb)
{
  PIRDeviceStringCollection::const_iterator i = devices.begin();
  while (i != devices.end())
  {
    cb->insertItem(i->first, QString(i->second));
    ++i;
  }
}
