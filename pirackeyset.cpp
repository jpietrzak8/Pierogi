//
// pirackeyset.cpp
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

#include "pirackeyset.h"

PIRACKeyset::PIRACKeyset(
  const char *keysetName,
  PIRMakeName make,
  unsigned int index)
  : PIRKeysetMetaData(keysetName, make, StatefulAC_Panels, index)
{
}


void PIRACKeyset::getTurboModePairs(
  PIRStatePairs &turboModePairs) const
{
  resetPairs(turboModePairs);
}


void PIRACKeyset::getSwingPairs(
  PIRStatePairs &swingPairs) const
{
  resetPairs(swingPairs);
}


void PIRACKeyset::getTemperaturePairs(
  PIRStatePairs &temperaturePairs) const
{
  resetPairs(temperaturePairs);
}


void PIRACKeyset::getFanPairs(
  PIRStatePairs &fanPairs) const
{
  resetPairs(fanPairs);
}


void PIRACKeyset::getOperatingModePairs(
  PIRStatePairs &modePairs) const
{
  resetPairs(modePairs);
}


void PIRACKeyset::getAirCleanPairs(
  PIRStatePairs &aircleanPairs) const
{
  resetPairs(aircleanPairs);
}


/*
void PIRACKeyset::getPowerPairs(
  PIRStatePairs &powerPairs) const
{
  resetPairs(powerPairs);
}
*/


void PIRACKeyset::getTimerOptionPairs(
  PIRStatePairs &timerOptionPairs) const
{
  resetPairs(timerOptionPairs);
}


void PIRACKeyset::resetPairs(
  PIRStatePairs &pairs) const
{
  PIRStatePairs::iterator i = pairs.begin();

  while (i != pairs.end())
  {
    delete (*i);
    ++i;
  }

  pairs.clear();
}


void PIRACKeyset::resetSettings(
  PIRACSettings &acSettings) const
{
  acSettings.clear();
}
