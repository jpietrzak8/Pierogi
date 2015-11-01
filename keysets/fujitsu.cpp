//
// fujitsu.cpp
//
// Copyright 2015 by John Pietrzak (jpietrzak8@gmail.com)
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

/*
 * I'll get back to fujitsu AC later...
 *
#include "fujitsu.h"
#include "protocols/fujitsuacprotocol.h"

FujitsuAC1::FujitsuAC1(
  unsigned int index)
  : PIRACKeyset(
      "Air Conditioner 1",
      Fujitsu_Make,
      index)
{
}


void FujitsuAC1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new FujitsuACProtocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));
}


void FujitsuAC1::populateSettingsList(
  PIRACSettings &acSettings) const
{
  resetSettings(acSettings);

  acSettings.push_back(OperationMode_AC);
  acSettings.push_back(Temperature_AC);
  acSettings.push_back(FanSpeed_AC);
  acSettings.push_back(Swing_AC);
}


void FujitsuAC1::getOperationModeList(
  PIRStatePairs &modePairs) const
{
  resetPairs(modePairs);

  modePairs.push_back(new PIRStatePair(
    "Auto", 0x0));

  modePairs.push_back(new PIRStatePair(
    "Cool", 0x1));

  modePairs.push_back(new PIRStatePair(
    "Dry", 0x2));

  modePairs.push_back(new PIRStatePair(
    "Fan", 0x3));
}


void FujitsuAC1::getSwingPairs(
  PIRStatePairs &swingPairs) const
{
  resetPairs(swingPairs);

  swingPairs.push_back(new PIRStatePair(
    "Off", 0x0));

  swingPairs.push_back(new PIRStatePair(
    "Up/Down", 0x1));

  swingPairs.push_back(new PIRStatePair(
    "Left/Right", 0x2));

  swingPairs.push_back(new PIRStatePair(
    "U/D/L/R", 0x3));
}


void FujitsuAC1::getTemperaturePairs(
  PIRStatePairs &temperaturePairs) const
{
  resetPairs (temperaturePairs);

  temperaturePairs.push_back(new PIRStatePair("18 C", 0x2));
  temperaturePairs.push_back(new PIRStatePair("19 C", 0x3));
  temperaturePairs.push_back(new PIRStatePair("20 C", 0x4));
  temperaturePairs.push_back(new PIRStatePair("21 C", 0x5));
  temperaturePairs.push_back(new PIRStatePair("22 C", 0x6));
  temperaturePairs.push_back(new PIRStatePair("23 C", 0x7));
  temperaturePairs.push_back(new PIRStatePair("24 C", 0x8));
  temperaturePairs.push_back(new PIRStatePair("25 C", 0x9));
  temperaturePairs.push_back(new PIRStatePair("26 C", 0xA));
  temperaturePairs.push_back(new PIRStatePair("27 C", 0xB));
  temperaturePairs.push_back(new PIRStatePair("28 C", 0xC));
  temperaturePairs.push_back(new PIRStatePair("29 C", 0xD));
  temperaturePairs.push_back(new PIRStatePair("30 C", 0xE));
}


void FujitsuAC1::getFanPairs(
  PIRStatePairs &fanPairs) const
{
  resetPairs(fanPairs);

  fanPairs.push_back(new PIRStatePair("Auto", 0x0));
  fanPairs.push_back(new PIRStatePair("High", 0x1));
  fanPairs.push_back(new PIRStatePair("Medium", 0x2));
  fanPairs.push_back(new PIRStatePair("Low", 0x3));
  fanPairs.push_back(new PIRStatePair("Quiet", 0x4));
}


void FujitsuAC1::getTimerOptionPairs(
  PIRStatePairs &timerOptionPairs) const
{
  resetPairs(timerOptionPairs);

  timerOptionPairs.push_back(new PIRStatePair("Turn Timer Off", 0x0));
  timerOptionPairs.push_back(new PIRStatePair("Sleep Mode", 0x1));
  timerOptionPairs.push_back(new PIRStatePair("Set Off Time", 0x2));
  timerOptionPairs.push_back(new PIRStatePair("Set On Time", 0x3));
  timerOptionPairs.push_back(new PIRStatePair("Turn Timer On", 0x4));
}
*/
