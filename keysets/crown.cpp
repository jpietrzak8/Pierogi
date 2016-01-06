//
// crown.cpp
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

#include "crown.h"
#include "protocols/necprotocol.h"
#include "protocols/rc5protocol.h"
#include <QComboBox>

CrownTV1::CrownTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Crown_Make,
      TV_Panels,
      index)
{
}


void CrownTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  addKey("POWER", Power_Key, 0x100C, 13);
  addKey("mute", Mute_Key, 0x100D, 13);
  addKey("1", One_Key, 0x1001, 13);
  addKey("2", Two_Key, 0x1002, 13);
  addKey("3", Three_Key, 0x1003, 13);
  addKey("4", Four_Key, 0x1004, 13);
  addKey("5", Five_Key, 0x1005, 13);
  addKey("6", Six_Key, 0x1006, 13);
  addKey("7", Seven_Key, 0x1007, 13);
  addKey("8", Eight_Key, 0x1008, 13);
  addKey("9", Nine_Key, 0x1009, 13);
  addKey("0", Zero_Key, 0x1000, 13);
  addKey("AV", AuxInput_Key, 0x1038, 13);
  addKey("-/--", DoubleDigit_Key, 0x100A, 13);
  addKey("TX", Unmapped_Key, 0x103C, 13); // teletext?
  addKey("TV", Input_Key, 0x103F, 13); // ?
  addKey("ProgUp", ChannelUp_Key, 0x1020, 13);
  addKey("ProgDown", ChannelDown_Key, 0x1021, 13);
  addKey("VolUp", VolumeUp_Key, 0x1010, 13);
  addKey("VolDown", VolumeDown_Key, 0x1011, 13);
  addKey("Sel", Unmapped_Key, 0x103B, 13);
  addKey(">|<", PrevChannel_Key, 0x100E, 13); // Dunno about this one
  addKey("INFO", Info_Key, 0x100F, 13);
  addKey("TIMER", Sleep_Key, 0x1026, 13);
  addKey("SYST", Unmapped_Key, 0x103D, 13);
  addKey("STORE", Unmapped_Key, 0x1027, 13);
  addKey("MENU", Menu_Key, 0x100B, 13);
  addKey("P100", PlusOneHundred_Key, 0x1035, 13);
  addKey("red", Red_Key, 0x1037, 13);
  addKey("green", Green_Key, 0x1036, 13);
  addKey("yellow", Yellow_Key, 0x1032, 13);
  addKey("blue", Blue_Key, 0x1034, 13);
  addKey("CLOCK", Unmapped_Key, 0x102A, 13);
  addKey("UPDATE", Unmapped_Key, 0x102E, 13);
  addKey("MIX", Unmapped_Key, 0x102E, 13);
  addKey("DOUBLE", Unmapped_Key, 0x102B, 13);
  addKey("REVEAL", Unmapped_Key, 0x102C, 13);
  addKey("HOLD", Unmapped_Key, 0x1029, 13);
  addKey("STEREO", Unmapped_Key, 0x102F, 13);
  addKey("MONO", Unmapped_Key, 0x1023, 13);
  addKey("PS", Unmapped_Key, 0x1024, 13);
}


void CrownTV1::populateInputList(
  QComboBox *cb) const
{
  cb->clear();

  cb->addItem("TV", QVariant(Input_Key));
  cb->addItem("AV", QVariant(AuxInput_Key));
}


CrownAudio1::CrownAudio1(
  unsigned int index)
  : PIRKeysetMetaData(
      "CD Keyset 1",
      Crown_Make,
      MediaControl_Panels,
      index)
{
}


void CrownAudio1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x14CA, 16);

  addKey("1", One_Key, 0x09, 8);
  addKey("2", Two_Key, 0x1D, 8);
  addKey("3", Three_Key, 0x1F, 8);
  addKey("4", Four_Key, 0x0D, 8);
  addKey("5", Five_Key, 0x19, 8);
  addKey("6", Six_Key, 0x1B, 8);
  addKey("7", Seven_Key, 0x11, 8);
  addKey("8", Eight_Key, 0x15, 8);
  addKey("9", Nine_Key, 0x17, 8);
  addKey("10", Zero_Key, 0x12, 8);
  addKey("+10", DoubleDigit_Key, 0x16, 8);
  addKey("STOP", Stop_Key, 0x0F, 8);
  addKey("REWIND", Rewind_Key, 0x0E, 8);
  addKey("FFWD", FastForward_Key, 0x1A, 8);
  addKey("PAUSE", Pause_Key, 0x0B, 8);
  addKey("PLAY", Play_Key, 0x13, 8);
}
