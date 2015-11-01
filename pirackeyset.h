//
// pirackeyset.h
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

#ifndef PIRACKEYSET_H
#define PIRACKEYSET_H

#include "pirkeysetmetadata.h"

// A special meta data subclass for stateful air conditioner remotes:

#include "pirstatepairs.h"
#include "piracstateinfo.h"

class PIRACKeyset: public PIRKeysetMetaData
{
public:
  PIRACKeyset(
    const char *keysetName,
    PIRMakeName make,
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject) = 0;

  virtual void populateSettingsList(
    PIRACSettings &acSettings) const = 0;

  virtual void getTurboModePairs(
    PIRStatePairs &turboModePairs) const;

  virtual void getSwingPairs(
    PIRStatePairs &swingPairs) const;

  virtual void getTemperaturePairs(
    PIRStatePairs &temperaturePairs) const;

  virtual void getFanPairs(
    PIRStatePairs &fanPairs) const;

  virtual void getOperatingModePairs(
    PIRStatePairs &modePairs) const;

  virtual void getAirCleanPairs(
    PIRStatePairs &aircleanPairs) const;

/*
  virtual void getPowerPairs(
    PIRStatePairs &powerPairs) const;
*/

  virtual void getTimerOptionPairs(
    PIRStatePairs &timerOptionPairs) const;

  void resetPairs(
    PIRStatePairs &pairs) const;

  void resetSettings(
    PIRACSettings &acSettings) const;
};

#endif // PIRACKEYSET_H
