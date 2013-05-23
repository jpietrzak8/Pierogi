//
// pirdeviceinfo.h
//
// Copyright 2012, 2013 by John Pietrzak  (jpietrzak8@gmail.com)
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

#ifndef PIRDEVICEINFO_H
#define PIRDEVICEINFO_H

#include "pirmakenames.h"
#include "pirdevicetypenames.h"

#include <map>

class DeviceInfo
{
public:
  DeviceInfo(
    PIRMakeName ma,
    const char *mo,
    PIRDeviceTypeName t)
  : make(ma),
    model(mo),
    type(t)
  {}

  PIRMakeName make;
  const char *model;
  PIRDeviceTypeName type;
};

bool operator< (
  const DeviceInfo &a,
  const DeviceInfo &b);

typedef std::map<DeviceInfo, unsigned int> PIRDeviceCollection;

typedef std::pair<DeviceInfo, unsigned int> PIRDCPair;

#endif // PIRDEVICEINFO_H
