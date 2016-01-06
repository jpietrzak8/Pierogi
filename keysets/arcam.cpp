//
// arcam.cpp
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

#include "arcam.h"
#include "protocols/rc5protocol.h"
#include <QComboBox>


ArcamReceiver1::ArcamReceiver1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Receiver Keyset 1",
      Arcam_Make,
      Receiver_Panels,
      index)
{
}


void ArcamReceiver1::populateProtocol(
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

  addKey("right", Right_Key, 0x0410, 13);
  addKey("left", Left_Key, 0x0411, 13);
  addKey("down", Down_Key, 0x0415, 13);
  addKey("up", Up_Key, 0x0416, 13);
  addKey("ok", Select_Key, 0x0417, 13);
  addKey("test", Unmapped_Key, 0x0418, 13);

  addKey("sat", SatInput_Key, 0x1400, 13);
  addKey("5-1", Surround_Key, 0x1402, 13); // ?
  addKey("dvd", DVDInput_Key, 0x1404, 13);
  addKey("tape", TapeInput_Key, 0x1405, 13);
  addKey("vcr", VCRInput_Key, 0x1406, 13);
  addKey("cd", CDInput_Key, 0x1407, 13);
  addKey("aux", AuxInput_Key, 0x1408, 13);
  addKey("power", Power_Key, 0x140C, 13);
  addKey("mute", Mute_Key, 0x140D, 13); // "silent"

  addKey("volup", VolumeUp_Key, 0x1410, 13);
  addKey("voldown", VolumeDown_Key, 0x1411, 13);
  addKey("mode", Mode_Key, 0x1420, 13);
  addKey("trim", Unmapped_Key, 0x1425, 13);
  addKey("sleep", Sleep_Key, 0x142A, 13);

  addKey("am", AM_Key, 0x1434, 13);
  addKey("fm", FM_Key, 0x1435, 13);
  addKey("tmode", FMMode_Key, 0x1436, 13); // ?
  addKey("info", Info_Key, 0x1437, 13);
  addKey("p+", ChannelUp_Key, 0x1438, 13);
  addKey("p-", ChannelDown_Key, 0x1439, 13);
  addKey("dyn", Unmapped_Key, 0x143E, 13);
}


void ArcamReceiver1::populateInputList(
  QComboBox *cb) const
{
  cb->clear();

  cb->addItem("Satellite", QVariant(SatInput_Key));
  cb->addItem("DVD", QVariant(DVDInput_Key));
  cb->addItem("Tape", QVariant(TapeInput_Key));
  cb->addItem("VCR", QVariant(VCRInput_Key));
  cb->addItem("CD", QVariant(CDInput_Key));
  cb->addItem("Aux", QVariant(AuxInput_Key));
}
