//
// piracstateinfo.h
//
// Copyright 2015 by John Pietrzak  (jpietrzak8@gmail.com)
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

#ifndef PIRACSTATEINFO_H
#define PIRACSTATEINFO_H

// Some convenient enum values:

enum PIRACSettingNames
{
  OperatingMode_AC,
  Temperature_AC,
  FanSpeed_AC,
  Turbo_AC,
  Swing_AC,
  AirClean_AC
};

typedef QList<PIRACSettingNames> PIRACSettings;

// A very simple class for passing state info around:

class PIRACStateInfo
{
public:
  PIRACStateInfo();

  // Standard state info:
  int temperature;
  int fan;
  int mode;
  int swing;
  int turbo;
  int airclean;

  // Timer state info:
  int timerOption;
  int timerHours;
};


// --------------- Inline methods:

inline PIRACStateInfo::PIRACStateInfo()
  : temperature(0),
    fan(0),
    mode(0),
    swing(0),
    turbo(0),
    airclean(0),
    timerOption(0),
    timerHours(0)
{
}

#endif // PIRACSTATEINFO_H
