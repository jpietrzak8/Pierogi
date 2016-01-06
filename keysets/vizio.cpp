//
// vizio.cpp
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

#include "vizio.h"
#include "protocols/necprotocol.h"
#include <QComboBox>


VizioTV1::VizioTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Vizio_Make,
      TV_Panels,
      index)
{
}


void VizioTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x04, 8);

  addKey("CH_UP", ChannelUp_Key, 0x00, 8);
  addKey("CH_DWN", ChannelDown_Key, 0x01, 8);
  addKey("VOL_UP", VolumeUp_Key, 0x02, 8);
  addKey("VOL_DWN", VolumeDown_Key, 0x03, 8);
  addKey("POWER", Power_Key, 0x08, 8);
  addKey("MUTE", Mute_Key, 0x09, 8);
  addKey("mts", Unmapped_Key, 0x0A, 8);
  addKey("audio", Audio_Key, 0x0B, 8);
  addKey("sleep", Sleep_Key, 0x0E, 8);

  addKey("ZERO", Zero_Key, 0x10, 8);
  addKey("ONE", One_Key, 0x11, 8);
  addKey("TWO", Two_Key, 0x12, 8);
  addKey("THREE", Three_Key, 0x13, 8);
  addKey("FOUR", Four_Key, 0x14, 8);
  addKey("FIVE", Five_Key, 0x15, 8);
  addKey("SIX", Six_Key, 0x16, 8);
  addKey("SEVEN", Seven_Key, 0x17, 8);
  addKey("EIGHT", Eight_Key, 0x18, 8);
  addKey("NINE", Nine_Key, 0x19, 8);
  addKey("LAST", PrevChannel_Key, 0x1A, 8);
  addKey("info", Info_Key, 0x1B, 8);
  addKey("Guide", Guide_Key, 0x1C, 8);

  addKey("INPUT", Input_Key, 0x2F, 8);
  addKey("cc", Captions_Key, 0x39, 8);
  addKey("zoom+", Unmapped_Key, 0x40, 8);
  addKey("zoom-", Unmapped_Key, 0x41, 8);
  addKey("MENU", Menu_Key, 0x43, 8);
  addKey("ok", Select_Key, 0x44, 8);
  addKey("UP", Up_Key, 0x45, 8);
  addKey("DOWN", Down_Key, 0x46, 8);
  addKey("LEFT", Left_Key, 0x47, 8);
  addKey("RIGHT", Right_Key, 0x48, 8);
  addKey("exit", Exit_Key, 0x49, 8);
  addKey("AV", AuxInput_Key, 0x51, 8);
  addKey("COMP", ComponentInput_Key, 0x5A, 8);

  addKey("pip", PIP_Key, 0x60, 8);
  addKey("pipsize", PIPSize_Key, 0x61, 8);
  addKey("pipinput", PIPSource_Key, 0x62, 8);
  addKey("pipch-", PIPChannelDown_Key, 0x63, 8);
  addKey("pipch+", PIPChannelUp_Key, 0x64, 8);
  addKey("freeze", PIPPause_Key, 0x65, 8);
  addKey("swap", PIPSwap_Key, 0x66, 8);
  addKey("mode", Mode_Key, 0x67, 8);
  addKey("wide", AspectRatio_Key, 0x77, 8);
  addKey("RGB", Component2Input_Key, 0x98, 8);
  addKey("HDMI", HDMIInput_Key, 0xC6, 8);
  addKey("TV", AntennaInput_Key, 0xD6, 8);

  addKey("DASH", Unmapped_Key, 0xFF, 8); // "enter"
}


void VizioTV1::populateInputList(
  QComboBox *cb) const
{
  cb->clear();

  cb->addItem("Input", QVariant(Input_Key));
  cb->addItem("TV", QVariant(AntennaInput_Key));
  cb->addItem("AV", QVariant(AuxInput_Key));
  cb->addItem("Comp", QVariant(ComponentInput_Key));
  cb->addItem("RGB", QVariant(Component2Input_Key));
  cb->addItem("HDMI", QVariant(HDMIInput_Key));
}
