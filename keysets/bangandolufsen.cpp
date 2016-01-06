//
// bangandolufsen.cpp
//
// Copyright 2014 -2015 by John Pietrzak (jpietrzak8@gmail.com)
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

#include "bangandolufsen.h"
#include "protocols/bangandolufsenprotocol.h"

#include <QComboBox>

BangAndOlufsenTV1::BangAndOlufsenTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      BangAndOlufsen_Make,
      TV_Panels,
      index)
{
}


void BangAndOlufsenTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new BangAndOlufsenProtocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x00, 8); // TVs are device "00"

  addKey("0", Zero_Key, 0x00, 8);
  addKey("1", One_Key, 0x01, 8);
  addKey("2", Two_Key, 0x02, 8);
  addKey("3", Three_Key, 0x03, 8);
  addKey("4", Four_Key, 0x04, 8);
  addKey("5", Five_Key, 0x05, 8);
  addKey("6", Six_Key, 0x06, 8);
  addKey("7", Seven_Key, 0x07, 8);
  addKey("8", Eight_Key, 0x08, 8);
  addKey("9", Nine_Key, 0x09, 8);
  addKey("CLEAR", Clear_Key, 0x0A, 8);
  addKey("STORE", Unmapped_Key, 0x0B, 8);
  addKey("POWER", Power_Key, 0x0C, 8);
  addKey("MUTE", Mute_Key, 0x0D, 8);
  addKey("RESET, INDEX", Unmapped_Key, 0x0E, 8);
  addKey("STEP (R), Up", ChannelUp_Key, 0x1E, 8);
  addKey("STEP (L), Down", ChannelDown_Key, 0x1F, 8);
  addKey("GO TO, TUNE, COUNTER, SETUP, TRACK, PAGE", Unmapped_Key, 0x20, 8);
  addKey("CLOCK", Unmapped_Key, 0x28, 8);
  addKey("FORMAT", Unmapped_Key, 0x2A, 8);
  addKey("<<, Left", Rewind_Key, 0x32, 8);
  addKey("RETURN, SUBCODE", Unmapped_Key, 0x33, 8);
  addKey(">>, Right", FastForward_Key, 0x34, 8);
  addKey("PLAY, LAMP, REVEAL", Play_Key, 0x35, 8);
  addKey("GO", Unmapped_Key, 0x35, 8);
  addKey("STOP", Stop_Key, 0x36, 8);
  addKey("RECORD, UPDATE", Record_Key, 0x37, 8);
  addKey("SELECT", Select_Key, 0x3F, 8);
  addKey("SPEAKER, SOUND", Unmapped_Key, 0x44, 8);
  addKey("PICTURE", PictureMode_Key, 0x45, 8);
  addKey("TURN, SOUND, MONO", SoundMode_Key, 0x46, 8);
  addKey("LOUDNSS", Unmapped_Key, 0x48, 8);
  addKey("BASS", BassUp_Key, 0x4D, 8);
  addKey("TREBLE", TrebleUp_Key, 0x4E, 8);
  addKey("BALANCE", BalanceRight_Key, 0x4F, 8);
  addKey("LIST", Unmapped_Key, 0x58, 8);
  addKey("MENU", Menu_Key, 0x5C, 8);
  addKey("Vol Up", VolumeUp_Key, 0x60, 8);
  addKey("Vol Dn", VolumeDown_Key, 0x64, 8);
  addKey("EXIT", Exit_Key, 0x7F, 8);
  addKey("TV", AntennaInput_Key, 0x80, 8);
  addKey("RADIO", TunerInput_Key, 0x81, 8);
  addKey("AUX2", ScartInput_Key, 0x82, 8); // hack!
  addKey("AUX", AuxInput_Key, 0x83, 8);
  addKey("V.TAPE", VCRInput_Key, 0x85, 8);
  addKey("DVD, CDV", DVDInput_Key, 0x86, 8);
  addKey("CAMCORD", LDInput_Key, 0x87, 8); // hack!
  addKey("TEXT", Unmapped_Key, 0x88, 8);
  addKey("SP.DEMO", Unmapped_Key, 0x89, 8);
  addKey("SATELLITE", SatInput_Key, 0x8A, 8);
  addKey("PC", PCInput_Key, 0x8B, 8);
  addKey("DOORCAM", DigitalCoaxInput_Key, 0x8D, 8); // hack!
  addKey("TAPE1", TapeInput_Key, 0x91, 8);
  addKey("CD", CDInput_Key, 0x92, 8);
  addKey("PHONO", PhonoInput_Key, 0x93, 8);
  addKey("TAPE2", LineInput_Key, 0x94, 8); // hack!
  addKey("CD2", MDInput_Key, 0x97, 8); // hack!
  addKey("LIGHT", Unmapped_Key, 0x9B, 8);
}


void BangAndOlufsenTV1::populateInputList(
  QComboBox *cb) const
{
  cb->clear();

  cb->addItem("TV", QVariant(AntennaInput_Key));
  cb->addItem("Satellite", QVariant(SatInput_Key));
  cb->addItem("Radio", QVariant(TunerInput_Key));
  cb->addItem("PC", QVariant(PCInput_Key));
  cb->addItem("DVD", QVariant(DVDInput_Key));
  cb->addItem("Videotape", QVariant(VCRInput_Key));
  cb->addItem("Camcorder", QVariant(LDInput_Key));
  cb->addItem("CD", QVariant(CDInput_Key));
  cb->addItem("CD 2", QVariant(MDInput_Key));
  cb->addItem("Tape Deck", QVariant(TapeInput_Key));
  cb->addItem("Tape Deck 2", QVariant(LineInput_Key));
  cb->addItem("Phonograph", QVariant(PhonoInput_Key));
  cb->addItem("Aux", QVariant(AuxInput_Key));
  cb->addItem("Aux 2", QVariant(ScartInput_Key));
  cb->addItem("Door Camera", QVariant(DigitalCoaxInput_Key));
}
