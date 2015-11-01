//
// gadmei.cpp
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

#include "gadmei.h"
#include "protocols/necprotocol.h"
#include <QComboBox>


GadmeiTuner1::GadmeiTuner1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Tuner Keyset 1",
      Gadmei_Make,
      TV_Panels,
      index)
{
}


void GadmeiTuner1::populateProtocol(
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

  setPreData(0xBD02, 16);

  addKey("1", One_Key, 0x00, 8);
  addKey("2", Two_Key, 0x01, 8);
  addKey("3", Three_Key, 0x02, 8);
  addKey("4", Four_Key, 0x03, 8);
  addKey("5", Five_Key, 0x04, 8);
  addKey("6", Six_Key, 0x05, 8);
  addKey("7", Seven_Key, 0x06, 8);
  addKey("8", Eight_Key, 0x07, 8);
  addKey("9", Nine_Key, 0x08, 8);
  addKey("0", Zero_Key, 0x09, 8);
  addKey("-/--", DoubleDigit_Key, 0x0A, 8);
  addKey("display", Info_Key, 0x0B, 8);
  addKey("mute", Mute_Key, 0x0C, 8);
  addKey("speaker", Unmapped_Key, 0x0D, 8);
  addKey("calander", Unmapped_Key, 0x0E, 8);
  addKey("game", Unmapped_Key, 0x0F, 8);
  addKey("vol up", VolumeUp_Key, 0x10, 8);
  addKey("vol down", VolumeDown_Key, 0x11, 8);
  addKey("channel up", ChannelUp_Key, 0x12, 8);
  addKey("channel down", ChannelDown_Key, 0x13, 8);
  addKey("power", Power_Key, 0x14, 8);
  addKey("menu", Menu_Key, 0x15, 8);
  addKey("AV", Input_Key, 0x17, 8);
  addKey("timer", Sleep_Key, 0x18, 8);
  addKey("mode", Mode_Key, 0x1A, 8);
  addKey("recall", Unmapped_Key, 0x1C, 8);
  addKey("FM", TunerInput_Key, 0x1E, 8);
  addKey("NICAM", Unmapped_Key, 0x1F, 8);
  addKey("+", Unmapped_Key, 0x40, 8);
  addKey("PIP", PIP_Key, 0x41, 8);
  addKey("-", Unmapped_Key, 0x42, 8);
  addKey("still", PIPPause_Key, 0x45, 8);
  addKey("view", Unmapped_Key, 0x46, 8);
  addKey("OSD", Unmapped_Key, 0x49, 8);
  addKey("resolution", AspectRatio_Key, 0x4A, 8);
}


void GadmeiTuner1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("AV", QVariant(Input_Key));
  cb->addItem("FM", QVariant(TunerInput_Key));
}
