//
// technisat.cpp
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

#include "technisat.h"
#include "protocols/paceprotocol.h"
#include "protocols/rc5protocol.h"
#include <QComboBox>


TechnisatSTB1::TechnisatSTB1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Satellite Receiver 1",
      Technisat_Make,
      TV_Panels,
      index)
{
  addControlledDevice(Technisat_Make, "ST 3004 S", Other_Device);
}


void TechnisatSTB1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new PaceProtocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x4, 3);

  addKey("POWER", Power_Key, 0x01, 6);
  addKey("TV/R", TunerInput_Key, 0x02, 6); // "radio"
  addKey("dek", Unmapped_Key, 0x04, 6);
  addKey("tab", Unmapped_Key, 0x05, 6);
  addKey("MUTE", Mute_Key, 0x06, 6);
  addKey("CH_UP", ChannelUp_Key, 0x07, 6);
  addKey("CH_DOWN", ChannelDown_Key, 0x08, 6);
  addKey("sat", SatInput_Key, 0x09, 6);
  addKey("lnb", Unmapped_Key, 0x0E, 6);
  addKey("0", Zero_Key, 0x0F, 6);

  addKey("1", One_Key, 0x10, 6);
  addKey("2", Two_Key, 0x11, 6);
  addKey("3", Three_Key, 0x12, 6);
  addKey("4", Four_Key, 0x13, 6);
  addKey("5", Five_Key, 0x14, 6);
  addKey("6", Six_Key, 0x15, 6);
  addKey("7", Seven_Key, 0x16, 6);
  addKey("8", Eight_Key, 0x17, 6);
  addKey("9", Nine_Key, 0x18, 6);
  addKey("deem", Unmapped_Key, 0x1E, 6);

  addKey("delete", Unmapped_Key, 0x21, 6);
  addKey("A/B", Audio_Key, 0x24, 6);
  addKey("save", Unmapped_Key, 0x26, 6);
  addKey("BACK", Exit_Key, 0x27, 6);
  addKey("audio_plus", Unmapped_Key, 0x28, 6);
  addKey("audio_minus", Unmapped_Key, 0x29, 6);
  addKey("MENU", Menu_Key, 0x2B, 6);
  addKey("video_plus", Unmapped_Key, 0x2C, 6);
  addKey("video_minus", Unmapped_Key, 0x2D, 6);
  addKey("VOL_UP", VolumeUp_Key, 0x2E, 6);
  addKey("VOL_DOWN", VolumeDown_Key, 0x2F, 6);

  addKey("ARROW_UP", Up_Key, 0x32, 6);
  addKey("ARROW_DOWN", Down_Key, 0x33, 6);
  addKey("ARROW_LEFT", Left_Key, 0x34, 6);
  addKey("ARROW_RIGHT", Right_Key, 0x35, 6);
  addKey("OK", Select_Key, 0x36, 6);
  addKey("LIST", Unmapped_Key, 0x37, 6);
}


void TechnisatSTB1::populateInputList(
  QComboBox *cb) const
{
  cb->clear();

  cb->addItem("TV / R", QVariant(TunerInput_Key));
  cb->addItem("SAT", QVariant(SatInput_Key));
}


TechnisatSTB1a::TechnisatSTB1a(
  unsigned int index)
  : TechnisatSTB1(index)
{
  setKeysetName("Satellite Receiver 1a");

  addControlledDevice(Technisat_Make, "ST 3002 S", Other_Device);
}


void TechnisatSTB1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  TechnisatSTB1::populateProtocol(guiObject);

  setPreData(0x1, 3);
}


TechnisatSTB2::TechnisatSTB2(
  unsigned int index)
  : PIRKeysetMetaData(
      "Satellite Receiver 2",
      Technisat_Make,
      TV_Panels,
      index)
{
  addControlledDevice(Technisat_Make, "TechniBox CAM1", Other_Device);
}


void TechnisatSTB2::populateProtocol(
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

  addKey("TV/SAT", SatInput_Key, 0x0200, 13);
  addKey("INFO", Info_Key, 0x020F, 13);
  addKey("MENU", Menu_Key, 0x0212, 13);
  addKey("TV/RADIO", TunerInput_Key, 0x0213, 13);
  addKey("OK", Select_Key, 0x0217, 13);

  addKey("RED", Red_Key, 0x022B, 13);
  addKey("GREEN", Green_Key, 0x022C, 13);
  addKey("YELLOW", Yellow_Key, 0x022D, 13);
  addKey("BLUE", Blue_Key, 0x022E, 13);

  addKey("0", Zero_Key, 0x1200, 13);
  addKey("1", One_Key, 0x1201, 13);
  addKey("2", Two_Key, 0x1202, 13);
  addKey("3", Three_Key, 0x1203, 13);
  addKey("4", Four_Key, 0x1204, 13);
  addKey("5", Five_Key, 0x1205, 13);
  addKey("6", Six_Key, 0x1206, 13);
  addKey("7", Seven_Key, 0x1207, 13);
  addKey("8", Eight_Key, 0x1208, 13);
  addKey("9", Nine_Key, 0x1209, 13);
  addKey("-/--", DoubleDigit_Key, 0x120A, 13); // "OPTION"
  addKey("POWER", Power_Key, 0x120C, 13);
  addKey("MUTE", Mute_Key, 0x120D, 13);

  addKey("RIGHT", Right_Key, 0x1210, 13);
  addKey("RIGHT", VolumeUp_Key, 0x1210, 13);
  addKey("LEFT", Left_Key, 0x1211, 13);
  addKey("LEFT", VolumeDown_Key, 0x1211, 13);
  addKey("UP", Up_Key, 0x1220, 13);
  addKey("UP", ChannelUp_Key, 0x1220, 13);
  addKey("DOWN", Down_Key, 0x1221, 13);
  addKey("DOWN", ChannelDown_Key, 0x1221, 13);
  addKey("BACK", Exit_Key, 0x1222, 13);
  addKey("A/B", Audio_Key, 0x1223, 13);
  addKey("STOP", Unmapped_Key, 0x1229, 13);
  addKey("EPG", Guide_Key, 0x122F, 13); // "SFI"
  addKey("EXT", Input_Key, 0x1238, 13);  // ??
  addKey("VT", Teletext_Key, 0x123C, 13); // "TXT"
}


void TechnisatSTB2::populateInputList(
  QComboBox *cb) const
{
  cb->clear();

  cb->addItem("TV / SAT", QVariant(SatInput_Key));
  cb->addItem("TV / Radio", QVariant(TunerInput_Key));
}


TechnisatSTB2a::TechnisatSTB2a(
  unsigned int index)
  : TechnisatSTB2(index)
{
  setKeysetName("Satellite Receiver 2a");
}


void TechnisatSTB2a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  TechnisatSTB2::populateProtocol(guiObject);

  addKey("UP", Up_Key, 0x0210, 13);
  addKey("LEFT", Left_Key, 0x0215, 13);
  addKey("RIGHT", Right_Key, 0x0216, 13);
  addKey("DOWN", Down_Key, 0x0211, 13);
}


TechnisatSTB3::TechnisatSTB3(
  unsigned int index)
  : PIRKeysetMetaData(
      "Satellite Receiver (and PCTV) 3",
      Technisat_Make,
      TV_Panels | MediaControl_Panels | MediaRecord_Panels,
      index)
{
  addControlledDevice(Technisat_Make, "SkyStar 2 TV", Other_Device);
  addControlledDevice(Technisat_Make, "SkyStar 2.6D", Other_Device);
}


void TechnisatSTB3::populateProtocol(
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

  addKey("INFO", Info_Key, 0x028F, 13);
  addKey("MENU", Menu_Key, 0x0292, 13);
  addKey("TV/RADIO", TunerInput_Key, 0x0293, 13);
  addKey("OK", Select_Key, 0x0297, 13);
  addKey("RED", Red_Key, 0x02AB, 13);
  addKey("REWIND", Rewind_Key, 0x02AB, 13);
  addKey("GREEN", Green_Key, 0x02AC, 13);
  addKey("STOP", Stop_Key, 0x02AC, 13);
  addKey("YELLOW", Yellow_Key, 0x02AD, 13);
  addKey("PLAY", Play_Key, 0x02AD, 13);
  addKey("PAUSE", Pause_Key, 0x02AD, 13);
  addKey("BLUE", Blue_Key, 0x02AE, 13);
  addKey("FASTFORWARD", FastForward_Key, 0x02AE, 13);
  addKey("CHECK", Unmapped_Key, 0x02B6, 13);
  addKey("KEY_QUESTION", Unmapped_Key, 0x02BD, 13);
  addKey("ZOOM", Zoom_Key, 0x02BE, 13);

  addKey("0", Zero_Key, 0x1280, 13);
  addKey("1", One_Key, 0x1281, 13);
  addKey("2", Two_Key, 0x1282, 13);
  addKey("3", Three_Key, 0x1283, 13);
  addKey("4", Four_Key, 0x1284, 13);
  addKey("5", Five_Key, 0x1285, 13);
  addKey("6", Six_Key, 0x1286, 13);
  addKey("7", Seven_Key, 0x1287, 13);
  addKey("8", Eight_Key, 0x1288, 13);
  addKey("9", Nine_Key, 0x1289, 13);
  addKey("-/--", DoubleDigit_Key, 0x128A, 13); // "OPTION"
  addKey("POWER", Power_Key, 0x128C, 13);
  addKey("MUTE", Mute_Key, 0x128D, 13);
  addKey("HILFE", Unmapped_Key, 0x128F, 13);

  addKey("RIGHT", Right_Key, 0x1290, 13);
  addKey("V+", VolumeUp_Key, 0x1290, 13);
  addKey("LEFT", Left_Key, 0x1291, 13);
  addKey("V-", VolumeDown_Key, 0x1291, 13);
  addKey("UP", Up_Key, 0x12A0, 13);
  addKey("P+", ChannelUp_Key, 0x12A0, 13);
  addKey("DOWN", Down_Key, 0x12A1, 13);
  addKey("P-", ChannelDown_Key, 0x12A1, 13);
  addKey("BACK", Exit_Key, 0x12A2, 13);
  addKey("A/B", Audio_Key, 0x12A3, 13);
  addKey("Time", Unmapped_Key, 0x12A6, 13);
  addKey("STOP", Unmapped_Key, 0x12A9, 13); // "Still"
  addKey("EPG", Guide_Key, 0x12AF, 13); //"SFI"
  addKey("RECORD", Record_Key, 0x12B7, 13);
  addKey("EXT", Input_Key, 0x12B8, 13);
  addKey("TXT", Teletext_Key, 0x12BC, 13);
}


TechnisatSTB3a::TechnisatSTB3a(
  unsigned int index)
  : TechnisatSTB3(index)
{
  setKeysetName("Satellite Receiver (and PCTV) 3a");

  addControlledDevice(Technisat_Make, "Technisat Digit HD4 CX", Other_Device);
}


void TechnisatSTB3a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  TechnisatSTB3::populateProtocol(guiObject);

  addKey("UP", Up_Key, 0x0290, 13);
  addKey("DOWN", Down_Key, 0x0291, 13);
  addKey("LEFT", Left_Key, 0x0295, 13);
  addKey("RIGHT", Right_Key, 0x0296, 13);
}
