//
// bose.cpp
//
// Copyright 2012, 2013 by John Pietrzak (jpietrzak8@gmail.com)
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

#include "bose.h"
#include "protocols/boseprotocol.h"
#include "protocols/necprotocol.h"
#include <QComboBox>


BoseRadio1::BoseRadio1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Wave Radio Keyset 1",
      Bose_Make,
      index)
{
}


void BoseRadio1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new BoseProtocol(guiObject, index);

  addKey("Mute", Mute_Key, 0x01, 8);
  addKey("Volume_Down", VolumeDown_Key, 0x02, 8);
  addKey("Volume_Up", VolumeUp_Key, 0x03, 8);
  addKey("FM_AM", ToggleBand_Key, 0x06, 8);
  addKey("FM_AM", TunerInput_Key, 0x06, 8); //?
  addKey("1", One_Key, 0x07, 8);
  addKey("2", Two_Key, 0x08, 8);
  addKey("3", Three_Key, 0x09, 8);
  addKey("4", Four_Key, 0x0A, 8);
  addKey("5", Five_Key, 0x0B, 8);
  addKey("6", Six_Key, 0x0C, 8);
  addKey("AUX", AuxInput_Key, 0x0F, 8);

  addKey("Seek_Track_Backward", Previous_Key, 0x18, 8);
  addKey("Seek_Track_Forward", Next_Key, 0x19, 8);
  addKey("Stop_Eject", Stop_Key, 0x1A, 8);
  addKey("Stop_Eject", Eject_Key, 0x1A, 8);
  addKey("Play_Pause", Play_Key, 0x1B, 8);
  addKey("Play_Pause", Pause_Key, 0x1B, 8);
  addKey("Play_Mode", Mode_Key, 0x21, 8);
  addKey("Alarm_On_Off", Unmapped_Key, 0x22, 8);
  addKey("Alarm_Time", Timer_Key, 0x23, 8);
  addKey("Time_Plus", Unmapped_Key, 0x24, 8);

  addKey("On_Off", Power_Key, 0x4C, 8);
  addKey("CD", CDInput_Key, 0x53, 8);
  addKey("Sleep", Sleep_Key, 0x54, 8);
  addKey("Tune_MP3_Down", ChannelDown_Key, 0x57, 8);
  addKey("Tune_MP3_Up", ChannelUp_Key, 0x58, 8);

  addKey("Alarm_Wake_To", Unmapped_Key, 0x70, 8);
  addKey("Time_Minus", Unmapped_Key, 0x9E, 8);
}


void BoseRadio1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("Radio", QVariant(TunerInput_Key));
  cb->addItem("CD", QVariant(CDInput_Key));
  cb->addItem("Aux", QVariant(AuxInput_Key));
}


BoseRadio2::BoseRadio2(
  unsigned int index)
  : PIRKeysetMetaData(
      "Wave Radio Keyset 2",
      Bose_Make,
      index)
{
}


void BoseRadio2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new BoseProtocol(guiObject, index);

  addKey("on/off", Power_Key, 0x00, 8);
  addKey("4", Four_Key, 0x08, 8);
  addKey("am", AM_Key, 0x10, 8);
  addKey("6", Six_Key, 0x20, 8);
  addKey("trackprev", Previous_Key, 0x30, 8);
  addKey("trackprev", ChannelDown_Key, 0x30, 8);
  addKey("volup", VolumeUp_Key, 0x40,8);
  addKey("cdstop", Stop_Key, 0x50, 8);
  addKey("fm", FM_Key, 0x60, 8);
  addKey("2", Two_Key, 0x70, 8);
  addKey("mute", Mute_Key, 0x80, 8);
  addKey("5", Five_Key, 0x88, 8);
  addKey("cdplaypause", Play_Key, 0x90, 8);
  addKey("cdplaypause", Pause_Key, 0x90, 8);
  addKey("sleep", Sleep_Key, 0xA0, 8);
  addKey("1", One_Key, 0xB0, 8);
  addKey("voldown", VolumeDown_Key, 0xC0, 8);
  addKey("tracknext", Next_Key, 0xD0, 8);
  addKey("tracknext", ChannelUp_Key, 0xD0, 8);
  addKey("aux", AuxInput_Key, 0xE0, 8);
  addKey("3", Three_Key, 0xF0, 8);
}


void BoseRadio2::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("AM Radio", QVariant(AM_Key));
  cb->addItem("FM Radio", QVariant(FM_Key));
  cb->addItem("CD", QVariant(Play_Key));
  cb->addItem("Aux", QVariant(AuxInput_Key));
}


BoseRadio3::BoseRadio3(
  unsigned int index)
  : PIRKeysetMetaData(
      "Wave Radio Keyset 3",
      Bose_Make,
      index)
{
}


void BoseRadio3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, false);

  setPreData(0xBA, 8);

  addKey("MUTE", Mute_Key, 0x01, 8);
  addKey("VOL-", VolumeDown_Key, 0x02, 8);
  addKey("VOL+", VolumeUp_Key, 0x03, 8);
  addKey("STATION", RDS_Key, 0x04, 8);
  addKey("AM/FM", ToggleBand_Key, 0x05, 8);
  addKey("AM/FM", TunerInput_Key, 0x05, 8); //?
  addKey("1", One_Key, 0x07, 8);
  addKey("2", Two_Key, 0x08, 8);
  addKey("3", Three_Key, 0x09, 8);
  addKey("4", Four_Key, 0x0A, 8);
  addKey("5", Five_Key, 0x0B, 8);
  addKey("6", Six_Key, 0x0C, 8);
  addKey("AUX", AuxInput_Key, 0x0F, 8);

  addKey("TUNE+", ChannelUp_Key, 0x10, 8); // "Tune/Time+"
  addKey("TUNE-", ChannelDown_Key, 0x11, 8); // "Tune/Time-"
  addKey("ALARM/TIME", Timer_Key, 0x12, 8);
  addKey("ALARM/WAKEUPTO", Unmapped_Key, 0x13, 8);

  addKey("SLEEP", Sleep_Key, 0x1E, 8);

  addKey("POWER", Power_Key, 0x4C, 8); // also "enter"?
}


void BoseRadio3::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("Radio", QVariant(TunerInput_Key));
  cb->addItem("Aux", QVariant(AuxInput_Key));
}


BoseHomeTheater1::BoseHomeTheater1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Home Theater 1",
      Bose_Make,
      index)
{
}


void BoseHomeTheater1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, false);

  setPreData(0x4BBA, 16);

  addKey("mute", Mute_Key, 0x01, 8);
  addKey("vol down", VolumeDown_Key, 0x02, 8);
  addKey("vol up", VolumeUp_Key, 0x03, 8);
  addKey("AM", AM_Key, 0x05, 8);
  addKey("Video2", CableInput_Key, 0x0D, 8);
  addKey("Video1", AntennaInput_Key, 0x0E, 8);
  addKey("AUX", AuxInput_Key, 0x0F, 8);

  addKey("channel down", ChannelDown_Key, 0x18, 8);
  addKey("channel up", ChannelUp_Key, 0x19, 8);
  addKey("stop", Stop_Key, 0x1A, 8);
  addKey("down arrow", Down_Key, 0x20, 8);
  addKey("pause", Pause_Key, 0x36, 8);

  addKey("0", Zero_Key, 0x40, 8);
  addKey("1", One_Key, 0x41, 8);
  addKey("2", Two_Key, 0x42, 8);
  addKey("3", Three_Key, 0x43, 8);
  addKey("4", Four_Key, 0x44, 8);
  addKey("5", Five_Key, 0x45, 8);
  addKey("6", Six_Key, 0x46, 8);
  addKey("7", Seven_Key, 0x47, 8);
  addKey("8", Eight_Key, 0x48, 8);
  addKey("9", Nine_Key, 0x49, 8);
  addKey("power", Power_Key, 0x4C, 8);

  addKey("CD/DVD", DVDInput_Key, 0x53, 8);
  addKey("play", Play_Key, 0x55, 8);
  addKey("rewind", Rewind_Key, 0x57, 8);
  addKey("fast fwd", FastForward_Key, 0x58, 8);
  addKey("FM", FM_Key, 0x59, 8);

  addKey("right arrow", Right_Key, 0x60, 8);
  addKey("display/info", Info_Key, 0x80, 8);
  addKey("menu", Menu_Key, 0x90, 8);
  addKey("left arrow", Left_Key, 0xA0, 8);
  addKey("up arrow", Up_Key, 0xC0, 8);
  addKey("select", Select_Key, 0xE0, 8);
}


void BoseHomeTheater1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("FM Radio", QVariant(FM_Key));
  cb->addItem("AM Radio", QVariant(AM_Key));
  cb->addItem("Video1", QVariant(AntennaInput_Key));
  cb->addItem("Video2", QVariant(CableInput_Key));
  cb->addItem("Aux", QVariant(AuxInput_Key));
  cb->addItem("CD / DVD", QVariant(DVDInput_Key));
}
