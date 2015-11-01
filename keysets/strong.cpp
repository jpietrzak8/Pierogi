//
// strong.cpp
//
// Copyright 2012 - 2013 by John Pietrzak (jpietrzak8@gmail.com)
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

#include "strong.h"
#include "protocols/necprotocol.h"
#include "protocols/recs80protocol.h"
#include <QComboBox>


StrongSat1::StrongSat1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Sat Receiver Keyset 1",
      Strong_Make,
      TV_Panels,
      index)
{
  addControlledDevice(Strong_Make, "ZapBox", Sat_Device);
}


void StrongSat1::populateProtocol(
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

  setPreData(0x7780, 16);

  addKey("POWER", Power_Key, 0x16, 8);
  addKey("MODE", Mode_Key, 0x11, 8);
  addKey("MUTE", Mute_Key, 0x1C, 8);
  addKey("TV/SAT", Input_Key, 0x1A, 8);
  addKey("EPG", Guide_Key, 0x0E, 8);
  addKey("TV/RADIO", TunerInput_Key, 0x1E, 8);
  addKey("PAGE-", ChannelDown_Key, 0x0C, 8);
  addKey("INFO", Info_Key, 0x1B, 8);
  addKey("PAGE+", ChannelUp_Key, 0x14, 8);
  addKey("EXIT", Exit_Key, 0x0F, 8);
  addKey("MENU", Menu_Key, 0x07, 8);
  addKey("vol up", VolumeUp_Key, 0x10, 8); // might be down instead
  addKey("vol down", VolumeDown_Key, 0x19, 8); // might be up instead
  addKey("UP", Up_Key, 0x12, 8);
  addKey("DOWN", Down_Key, 0x13, 8);
  addKey("LEFT", Left_Key, 0x15, 8);
  addKey("RIGHT", Right_Key, 0x17, 8);
  addKey("OK", Select_Key, 0x0B, 8);
  addKey("enter", Enter_Key, 0x0B, 8);
  addKey("1", One_Key, 0x00, 8);
  addKey("2", Two_Key, 0x01, 8);
  addKey("3", Three_Key, 0x02, 8);
  addKey("4", Four_Key, 0x04, 8);
  addKey("5", Five_Key, 0x05, 8);
  addKey("6", Six_Key, 0x06, 8);
  addKey("7", Seven_Key, 0x08, 8);
  addKey("8", Eight_Key, 0x09, 8);
  addKey("9", Nine_Key, 0x0A, 8);
  addKey("0", Zero_Key, 0x0D, 8);
  addKey("HELP", Unmapped_Key, 0x03, 8); // Might be info key
  addKey("RED", Red_Key, 0x40, 8);
  addKey("GREEN", Green_Key, 0x1D, 8);
  addKey("YELLOW", Yellow_Key, 0x1F, 8);
  addKey("BLUE", Blue_Key, 0x41, 8);
}


void StrongSat1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("TV / Sat", QVariant(Input_Key));
  cb->addItem("TV / Radio", QVariant(TunerInput_Key));
}


StrongSat2::StrongSat2(
  unsigned int index)
  : PIRKeysetMetaData(
      "Sat Receiver Keyset 2",
      Strong_Make,
      TV_Panels,
      index)
{
  addControlledDevice(Strong_Make, "SRT-4620", Sat_Device);
}


void StrongSat2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x01, 8);

  addKey("power", Power_Key, 0x00, 8);
  addKey("1", One_Key, 0x01, 8);
  addKey("2", Two_Key, 0x02, 8);
  addKey("mute", Mute_Key, 0x03, 8);
  addKey("4", Four_Key, 0x04, 8);
  addKey("5", Five_Key, 0x05, 8);
  addKey("3", Three_Key, 0x06, 8);
  addKey("6", Six_Key, 0x07, 8);
  addKey("7", Seven_Key, 0x08, 8);
  addKey("8", Eight_Key, 0x0A, 8);
  addKey("9", Nine_Key, 0x0B, 8);
  addKey("tv/Radio", TunerInput_Key, 0x0C, 8);
  addKey("0", Zero_Key, 0x0E, 8);
  addKey("TV/Sat", Input_Key, 0x0F, 8);
  addKey("menu", Menu_Key, 0x10, 8);
  addKey("exit", Exit_Key, 0x11, 8);
  addKey("select", Select_Key, 0x12, 8);
  addKey("channel", Unmapped_Key, 0x13, 8); // Not sure
  addKey("vol down", VolumeDown_Key, 0x14, 8);
  addKey("left arrow", Left_Key, 0x14, 8);
  addKey("channel up", ChannelUp_Key, 0x15, 8);
  addKey("up arrow", Up_Key, 0x15, 8);
  addKey("channel down", ChannelDown_Key, 0x16, 8);
  addKey("down arrow", Down_Key, 0x16, 8);
  addKey("vol up", VolumeUp_Key, 0x17, 8);
  addKey("right arrow", Right_Key, 0x17, 8);
  addKey("program guide", Guide_Key, 0x18, 8);
  addKey("display", Info_Key, 0x19, 8);
  addKey("audio", Audio_Key, 0x1A, 8);
  addKey("white", Unmapped_Key, 0x41, 8);
  addKey("orange", Unmapped_Key, 0x42, 8);
  addKey("red", Red_Key, 0x44, 8);
  addKey("green", Green_Key, 0x45, 8);
  addKey("yellow", Yellow_Key, 0x46, 8);
  addKey("blue", Blue_Key, 0x47, 8);
}


void StrongSat2::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("TV / Sat", QVariant(Input_Key));
  cb->addItem("TV / Radio", QVariant(TunerInput_Key));
}


StrongSat2a::StrongSat2a(
  unsigned int index)
  : StrongSat2(index)
{
  setKeysetName("Sat Receiver Keyset 2a");
}


void StrongSat2a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  StrongSat2::populateProtocol(guiObject);

  addKey("TV/SAT", Input_Key, 0x0C, 8);
  addKey("TV/Radio", TunerInput_Key, 0x0F, 8);
  addKey("pause", Pause_Key, 0x1A, 8);
  addKey("Zoom", Zoom_Key, 0x1C, 8);
  addKey("Multi Pic(Blue)", Blue_Key, 0x1D, 8); // What is "Multi Pic"?
  addKey("Colour", PictureMode_Key, 0x1F, 8);
  addKey("Audio (Green)", Audio_Key, 0x41, 8);
  addKey("Audio (Green)", Green_Key, 0x41, 8);
  addKey("Teletext (Yellow)", Teletext_Key, 0x42, 8);
  addKey("Teletext (Yellow)", Yellow_Key, 0x42, 8);
  addKey("last (Red)", PrevChannel_Key, 0x47, 8);
  addKey("last (Red)", Red_Key, 0x47, 8);
}


StrongSat3::StrongSat3(
  unsigned int index)
  : PIRKeysetMetaData(
      "Sat Receiver Keyset 3",
      Strong_Make,
      TV_Panels,
      index)
{
  addControlledDevice(Strong_Make, "SRT-6410", Sat_Device);
}


void StrongSat3::populateProtocol(
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

  setPreData(0x0202, 16);

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
  addKey("power", Power_Key, 0x0A, 8);
  addKey("up arrow", Up_Key, 0x0B, 8);
  addKey("ZOOM", Zoom_Key, 0x0C, 8);
  addKey("select", Select_Key, 0x0D, 8);
  addKey("down arrow", Down_Key, 0x0E, 8);
  addKey("right arrow", Right_Key, 0x10, 8);
  addKey("left arrow", Left_Key, 0x11, 8);
  addKey("AV", Input_Key, 0x12, 8);
  addKey("red", Red_Key, 0x14, 8);
  addKey("channel up", Up_Key, 0x15, 8);
  addKey("menu", Menu_Key, 0x16, 8);
  addKey("green", Green_Key, 0x17, 8);
  addKey("channel down", Down_Key, 0x18, 8);
  addKey("mute", Mute_Key, 0x19, 8);
  addKey("LIST", Unmapped_Key, 0x1A, 8);
  addKey("program guide", Guide_Key, 0x1B, 8);
  addKey("AUDIO", Audio_Key, 0x1C, 8);
  addKey("yellow", Yellow_Key, 0x1D, 8);
  addKey("exit", Exit_Key, 0x1F, 8);
  addKey("MOSAIC", PIP_Key, 0x40, 8);
  addKey("vol up", VolumeUp_Key, 0x41, 8);
  addKey("vol down", VolumeDown_Key, 0x42, 8);
  addKey("blue", Blue_Key, 0x43, 8);
  addKey("INFO", Info_Key, 0x44, 8);
  addKey("TV/R", TunerInput_Key, 0x45, 8);
}


void StrongSat3::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("AV", QVariant(Input_Key));
  cb->addItem("TV / R", QVariant(TunerInput_Key));
}


StrongSat3a::StrongSat3a(
  unsigned int index)
  : StrongSat3(index)
{
  setKeysetName("Sat Receiver Keyset 3a");
}


void StrongSat3a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  StrongSat3::populateProtocol(guiObject);

  addKey("channel up", ChannelUp_Key, 0x0B, 8);
  addKey("channel down", ChannelDown_Key, 0x0E, 8);
  addKey("last (prev ch)", PrevChannel_Key, 0x12, 8);
  addKey("pdn", PageDown_Key, 0x13, 8);
  addKey("fav", Favorites_Key, 0x14, 8);
  addKey("program guide", Guide_Key, 0x17, 8);
  addKey("sleep", Sleep_Key, 0x1B, 8);
  addKey("f1", Unmapped_Key, 0x1B, 8);
  addKey("tv/radio", TunerInput_Key, 0x1C, 8);
  addKey("sat", Input_Key, 0x1D, 8);
  addKey("pgup", PageUp_Key, 0x1E, 8);
  addKey("audio", Audio_Key, 0x40, 8);
  addKey("red", Red_Key, 0x40, 8);
  addKey("blue", Blue_Key, 0x41, 8);
  addKey("green", Green_Key, 0x42, 8);
  addKey("zoom", Zoom_Key, 0x42, 8);
  addKey("display", Info_Key, 0x43, 8);
  addKey("yellow", Yellow_Key, 0x43, 8);
  addKey("teletext", Teletext_Key, 0x44, 8);
  addKey("subcategory", Unmapped_Key, 0x45, 8);
  addKey("f2", Unmapped_Key, 0x45, 8);
  addKey("pip", PIP_Key, 0x46, 8);
  addKey("f3", Unmapped_Key, 0x46, 8);
}


StrongSat4::StrongSat4(
  unsigned int index)
  : PIRKeysetMetaData(
      "Sat Receiver Keyset 4",
      Strong_Make,
      TV_Panels | MediaControl_Panels | MediaRecord_Panels,
      index)
{
  addControlledDevice(Strong_Make, "SRT-5430", Sat_Device);
}


void StrongSat4::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x00, 8);

  addKey("Mute", Mute_Key, 0x00, 8);
  addKey("Language", Audio_Key, 0x01, 8);
  addKey("exit", Exit_Key, 0x03, 8);
  addKey("Play", Play_Key, 0x04, 8);
  addKey("num_3", Three_Key, 0x05, 8);
  addKey("Select", Select_Key, 0x06, 8);
  addKey("Guide", Guide_Key, 0x07, 8);
  addKey("Stop", Stop_Key, 0x08, 8);
  addKey("num_2", Two_Key, 0x09, 8);
  addKey("Pause", Pause_Key, 0x0A, 8);
  addKey("Aspect", AspectRatio_Key, 0x0B, 8);
  addKey("Power", Power_Key, 0x0C, 8);
  addKey("num_1", One_Key, 0x0D, 8);
  addKey("Menu", Menu_Key, 0x0F, 8);
  addKey("ffwd", FastForward_Key, 0x10, 8);
  addKey("Page+", PageUp_Key, 0x14, 8);
  addKey("Page-", PageDown_Key, 0x18, 8);
  addKey("Skip+", Next_Key, 0x1C, 8);
  addKey("VOL+", VolumeUp_Key, 0x40, 8);
  addKey("right_arrow", Right_Key, 0x40, 8);
  addKey("Info", Info_Key, 0x41, 8);
  addKey("Media", Unmapped_Key, 0x42, 8);
  addKey("TV/Radio", TunerInput_Key, 0x43, 8);
  addKey("CH+", ChannelUp_Key, 0x44, 8);
  addKey("up_arrow", Up_Key, 0x44, 8);
  addKey("Last_ch", PrevChannel_Key, 0x45, 8);
  addKey("num_9", Nine_Key, 0x46, 8);
  addKey("num_6", Six_Key, 0x47, 8);
  addKey("CH-", ChannelDown_Key, 0x48, 8);
  addKey("down_arrow", Down_Key, 0x48, 8);
  addKey("num_0", Zero_Key, 0x49, 8);
  addKey("num_8", Eight_Key, 0x4A, 8);
  addKey("num_5", Five_Key, 0x4B, 8);
  addKey("VOL-", VolumeDown_Key, 0x4C, 8);
  addKey("left_arrow", Left_Key, 0x4C, 8);
  addKey("Fav", Favorites_Key, 0x4D, 8);
  addKey("num_7", Seven_Key, 0x4E, 8);
  addKey("num_4", Four_Key, 0x4F, 8);
  addKey("V.Mode", PictureMode_Key, 0x50, 8);
  addKey("Goto", Unmapped_Key, 0x51, 8);
  addKey("Red", Red_Key, 0x52, 8);
  addKey("Zoom", Zoom_Key, 0x54, 8);
  addKey("Repeat", Repeat_Key, 0x55, 8);
  addKey("Green", Green_Key, 0x56, 8);
  addKey("rewind", Rewind_Key, 0x57, 8);
  addKey("Subtitle", Captions_Key, 0x58, 8);
  addKey("TimeShift", Unmapped_Key, 0x59, 8);
  addKey("Yellow", Yellow_Key, 0x5A, 8);
  addKey("Skip-", Previous_Key, 0x5B, 8);
  addKey("List", Unmapped_Key, 0x5C, 8);
  addKey("Scan", Unmapped_Key, 0x5D, 8);
  addKey("Blue", Blue_Key, 0x5E, 8);
  addKey("Record", Record_Key, 0x5F, 8);
}


StrongSat5::StrongSat5(
  unsigned int index)
  : PIRKeysetMetaData(
      "Sat Receiver Keyset 5",
      Strong_Make,
      TV_Panels,
      index)
{
}


void StrongSat5::populateProtocol(
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

  setPreData(0xF0FF, 16);

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
  addKey("Power", Power_Key, 0x0A, 8);
  addKey("CH+ / Menu Up", ChannelUp_Key, 0x0B, 8);
  addKey("CH+ / Menu Up", Up_Key, 0x0B, 8);
  addKey("Select", Select_Key, 0x0D, 8);
  addKey("CH- / Menu Down", ChannelDown_Key, 0x0E, 8);
  addKey("CH- / Menu Down", Down_Key, 0x0E, 8);
  addKey("Analog Radio", Unmapped_Key, 0x0F, 8);
  addKey("VOL+ / Menu Right", VolumeUp_Key, 0x10, 8);
  addKey("VOL+ / Menu Right", Right_Key, 0x10, 8);
  addKey("VOL down / Menu Left", VolumeDown_Key, 0x11, 8);
  addKey("VOL down / Menu Left", Left_Key, 0x11, 8);
  addKey("Digital TV", AntennaInput_Key, 0x12, 8);
  addKey("CH+ / Page Up", PageUp_Key, 0x13, 8); // why "CH+" here?
  addKey("sub", Captions_Key, 0x14, 8);
  addKey("Analog TV", Antenna2Input_Key, 0x15, 8);
  addKey("Language", Audio_Key, 0x16, 8);
  addKey("Sound", SoundMode_Key, 0x17, 8);
  addKey("Mute / green", Mute_Key, 0x19, 8);
  addKey("Mute / green", Green_Key, 0x19, 8);
  addKey("Pause", Pause_Key, 0x1A, 8);
  addKey("Favorite", Favorites_Key, 0x1C, 8);
  addKey("Digital Radio", TunerInput_Key, 0x1D, 8);
  addKey("CH- / page Down", PageDown_Key, 0x1E, 8); // also why "CH-"
  addKey("Guide / EPG", Guide_Key, 0x1F, 8);
  addKey("Menu / Red", Menu_Key, 0x40, 8);
  addKey("Menu / Red", Red_Key, 0x40, 8);
  addKey("SAT / Blue", SatInput_Key, 0x41, 8);
  addKey("SAT / Blue", Blue_Key, 0x41, 8);
  addKey("Info / Function / Scan", Info_Key, 0x42, 8);
  addKey("Exit / Yellow", Exit_Key, 0x43, 8);
  addKey("Exit / Yellow", Yellow_Key, 0x43, 8);
}


void StrongSat5::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("Digital TV", QVariant(AntennaInput_Key));
  cb->addItem("Analog TV", QVariant(Antenna2Input_Key));
  cb->addItem("Digital Radio", QVariant(TunerInput_Key));
  cb->addItem("Satellite", QVariant(SatInput_Key));
}


StrongSat5a::StrongSat5a(
  unsigned int index)
  : StrongSat5(index)
{
  setKeysetName("Sat Receiver Keyset 5a");
}


void StrongSat5a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  StrongSat5::populateProtocol(guiObject);

  addKey("text off", Unmapped_Key, 0x0F, 8);
  addKey("text on", Unmapped_Key, 0x15, 8);
  addKey("menu", Menu_Key, 0x16, 8);
  addKey("func", Unmapped_Key, 0x17, 8);
  addKey("sat", SatInput_Key, 0x1A, 8);
  addKey("exit", Exit_Key, 0x1F, 8);
  addKey("red lang", Audio_Key, 0x40, 8);
  addKey("blue pause", Pause_Key, 0x41, 8);
  addKey("green sound", SoundMode_Key, 0x42, 8);
  addKey("green sound", Green_Key, 0x42, 8);
  addKey("yellow epg", Guide_Key, 0x43, 8);
}


StrongSTB1::StrongSTB1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVB-T Receiver Keyset 1",
      Strong_Make,
      TV_Panels,
      index)
{
}


void StrongSTB1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new RECS80Protocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x5, 3);

  addKey("display/info", Info_Key, 0x14, 6);
  addKey("fav", Favorites_Key, 0x15, 6);
  addKey("sub", Captions_Key, 0x16, 6);
  addKey("mute", Mute_Key, 0x18, 6);
  addKey("red", Red_Key, 0x19, 6);
  addKey("8", Eight_Key, 0x1C, 6);
  addKey("4", Four_Key, 0x1D, 6);
  addKey("power", Power_Key, 0x1E, 6);
  addKey("pause", Pause_Key, 0x20, 6);
  addKey("vol up", VolumeUp_Key, 0x21, 6);
  addKey("right arrow", Right_Key, 0x21, 6);
  addKey("yellow", Yellow_Key, 0x22, 6);
  addKey("7", Seven_Key, 0x24, 6);
  addKey("3", Three_Key, 0x25, 6);
  addKey("menu", Menu_Key, 0x27, 6);
  addKey("channel up", ChannelUp_Key, 0x28, 6);
  addKey("up arrow", Up_Key, 0x28, 6);
  addKey("ok", Select_Key, 0x29, 6);
  addKey("channel down", ChannelDown_Key, 0x2A, 6);
  addKey("down arrow", Down_Key, 0x2A, 6);
  addKey("0", Zero_Key, 0x2B, 6);
  addKey("6", Six_Key, 0x2C, 6);
  addKey("2", Two_Key, 0x2D, 6);
  addKey("list", Unmapped_Key, 0x2E, 6);
  addKey("epg", Guide_Key, 0x2F, 6);
  addKey("exit", Exit_Key, 0x30, 6);
  addKey("vol down", VolumeDown_Key, 0x31, 6);
  addKey("left arrow", Left_Key, 0x31, 6);
  addKey("green", Green_Key, 0x32, 6);
  addKey("9", Nine_Key, 0x33, 6);
  addKey("5", Five_Key, 0x34, 6);
  addKey("1", One_Key, 0x35, 6);
  addKey("blue", Blue_Key, 0x37, 6);
}


StrongSTB2::StrongSTB2(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVB-T Receiver Keyset 2",
      Strong_Make,
      TV_Panels | MediaControl_Panels | MediaRecord_Panels,
      index)
{
}


void StrongSTB2::populateProtocol(
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

  setPreData(0x0820, 16);

  addKey("STAND BY", Power_Key, 0x00, 8);
  addKey("P.SIZE", AspectRatio_Key, 0x01, 8);
  addKey("VOL+", VolumeUp_Key, 0x02, 8);
  addKey("VOL-", VolumeDown_Key, 0x03, 8);
  addKey("MUTE", Mute_Key, 0x04, 8);
  addKey("TV/RADIO", TunerInput_Key, 0x05, 8);
  addKey("CH+", ChannelUp_Key, 0x06, 8);
  addKey("CH-", ChannelDown_Key, 0x07, 8);
  addKey("TV/STB", Input_Key, 0x08, 8);
  addKey("P.STD", PictureMode_Key, 0x09, 8);
  addKey("A.L/R", Unmapped_Key, 0x0A, 8);
  addKey("A.LANG", Audio_Key, 0x0B, 8);
  addKey("RECALL", PrevChannel_Key, 0x0C, 8);
  addKey("EPG", Guide_Key, 0x0D, 8);
  addKey("TEXT", Teletext_Key, 0x0E, 8);
  addKey("FAV", Favorites_Key, 0x0F, 8);
  addKey("EXIT", Exit_Key, 0x10, 8);
  addKey("MENU", Menu_Key, 0x11, 8);
  addKey("UP", Up_Key, 0x12, 8);
  addKey("DOWN", Down_Key, 0x13, 8);
  addKey("LEFT", Left_Key, 0x14, 8);
  addKey("OK", Select_Key, 0x15, 8);
  addKey("RIGHT", Right_Key, 0x16, 8);
  addKey("For COMBO", Unmapped_Key, 0x17, 8);
  addKey("SUB-T (RED)", Red_Key, 0x18, 8);
  addKey("RSV(GREEN)", Green_Key, 0x19, 8);
  addKey("YELLOW", Yellow_Key, 0x1A, 8);
  addKey("BLUE", Blue_Key, 0x1B, 8);
  addKey("1", One_Key, 0x1C, 8);
  addKey("2", Two_Key, 0x1D, 8);
  addKey("3", Three_Key, 0x1E, 8);
  addKey("SLEEP", Sleep_Key, 0x1F, 8);
  addKey("4", Four_Key, 0x40, 8);
  addKey("5", Five_Key, 0x41, 8);
  addKey("6", Six_Key, 0x42, 8);
  addKey("PAUSE", Pause_Key, 0x43, 8);
  addKey("7", Seven_Key, 0x44, 8);
  addKey("8", Eight_Key, 0x45, 8);
  addKey("9", Nine_Key, 0x46, 8);
  addKey("0", Zero_Key, 0x47, 8);
  addKey("CHAP PREV", Previous_Key, 0x48, 8);
  addKey("REWIND", Rewind_Key, 0x49, 8);
  addKey("FAST FORWARD", FastForward_Key, 0x4A, 8);
  addKey("CHAP NEXT", Next_Key, 0x4B, 8);
  addKey("Z2?", Unmapped_Key, 0x4C, 8);
  addKey("Z1?", Unmapped_Key, 0x4D, 8);
  addKey("Z3?", Unmapped_Key, 0x4E, 8);
  addKey("Z4?", Unmapped_Key, 0x4F, 8);
}


void StrongSTB2::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("TV / Radio", QVariant(TunerInput_Key));
  cb->addItem("TV / STB", QVariant(Input_Key));
}


StrongSTB3::StrongSTB3(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVB-T Receiver Keyset 3",
      Strong_Make,
      TV_Panels,
      index)
{
}


void StrongSTB3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x00, 8);

  addKey("power", Power_Key, 0x00, 8);
  addKey("1", One_Key, 0x01, 8);
  addKey("2", Two_Key, 0x02, 8);
  addKey("mute", Mute_Key, 0x03, 8);
  addKey("4", Four_Key, 0x04, 8);
  addKey("5", Five_Key, 0x05, 8);
  addKey("3", Three_Key, 0x06, 8);
  addKey("6", Six_Key, 0x07, 8);
  addKey("7", Seven_Key, 0x08, 8);
  addKey("RED", Red_Key, 0x09, 8);
  addKey("8", Eight_Key, 0x0A, 8);
  addKey("9", Nine_Key, 0x0B, 8);
//  addKey("exit", Exit_Key, 0x0C, 8);
  addKey("0", Zero_Key, 0x0E, 8);
  addKey("menu", Menu_Key, 0x10, 8);
  addKey("exit", Exit_Key, 0x11, 8);
  addKey("select", Select_Key, 0x12, 8);
  addKey("vol down", VolumeDown_Key, 0x14, 8);
  addKey("left arrow", Left_Key, 0x14, 8);
  addKey("channel up", ChannelUp_Key, 0x15, 8);
  addKey("up arrow", Up_Key, 0x15, 8);
  addKey("channel down", ChannelDown_Key, 0x16, 8);
  addKey("down arrow", Down_Key, 0x16, 8);
  addKey("vol up", VolumeUp_Key, 0x17, 8);
  addKey("right arrow", Right_Key, 0x17, 8);
  addKey("guide", Guide_Key, 0x18, 8);
  addKey("info", Info_Key, 0x19, 8);
  addKey("AUDIO", Audio_Key, 0x1A, 8);
  addKey("GREEN", Green_Key, 0x1B, 8);
  addKey("YELLOW", Yellow_Key, 0x1C, 8);
  addKey("captions", Captions_Key, 0x41, 8);
  addKey("ratio", AspectRatio_Key, 0x42, 8);
  addKey("BLUE", Blue_Key, 0x44, 8);
}


StrongSTB4::StrongSTB4(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVB-T Receiver Keyset 4",
      Strong_Make,
      TV_Panels,
      index)
{
}


void StrongSTB4::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0xC0, 8);

  addKey("program guide", Guide_Key, 0x80, 8);
  addKey("blue", Blue_Key, 0x81, 8);
  addKey("menu", Menu_Key, 0x82, 8);
  addKey("teletext", Teletext_Key, 0x83, 8);
  addKey("down arrow", Down_Key, 0x84, 8);
  addKey("green", Green_Key, 0x85, 8);
  addKey("yellow", Yellow_Key, 0x86, 8);
  addKey("subtitle", Captions_Key, 0x87, 8);
  addKey("select", Select_Key, 0x88, 8);
  addKey("vol down", VolumeDown_Key, 0x89, 8);
  addKey("left arrow", Left_Key, 0x89, 8);
  addKey("vol up", VolumeUp_Key, 0x8A, 8);
  addKey("right arrow", Right_Key, 0x8A, 8);
  addKey("red", Red_Key, 0x8B, 8);
  addKey("up arrow", Up_Key, 0x8C, 8);
  addKey("exit", Exit_Key, 0x8D, 8);
  addKey("audio", Audio_Key, 0x8E, 8);
  addKey("mute", Mute_Key, 0x8F, 8);
  addKey("0", Zero_Key, 0x90, 8);
  addKey("9", Nine_Key, 0x91, 8);
  addKey("6", Six_Key, 0x94, 8);
  addKey("5", Five_Key, 0x95, 8);
  addKey("7", Seven_Key, 0x96, 8);
  addKey("8", Eight_Key, 0x97, 8);
  addKey("2", Two_Key, 0x98, 8);
  addKey("1", One_Key, 0x99, 8);
  addKey("3", Three_Key, 0x9A, 8);
  addKey("4", Four_Key, 0x9B, 8);
  addKey("tv/radio", TunerInput_Key, 0x9C, 8);
  addKey("channel down", ChannelDown_Key, 0x9D, 8);
  addKey("tv/video", Input_Key, 0x9E, 8);
  addKey("power", Power_Key, 0x9F, 8);
  addKey("display", Info_Key, 0xD4, 8);
  addKey("channel up", ChannelUp_Key, 0xDC, 8);
}


void StrongSTB4::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("TV / Radio", QVariant(TunerInput_Key));
  cb->addItem("TV / Video", QVariant(Input_Key));
}


StrongSTB5::StrongSTB5(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVB-T Receiver Keyset 5",
      Strong_Make,
      TV_Panels,
      index)
{
}


void StrongSTB5::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x00, 8);

  addKey("Page-", PageDown_Key, 0x00, 8);
  addKey("Info", Info_Key, 0x01, 8);
  addKey("CH -", ChannelDown_Key, 0x02, 8);
  addKey("Down", Down_Key, 0x02, 8);
  addKey("CH +", ChannelUp_Key, 0x03, 8);
  addKey("Up", Up_Key, 0x03, 8);
  addKey("Blue/Txt", Blue_Key, 0x04, 8);
  addKey("Blue/Txt", Teletext_Key, 0x04, 8);
  addKey("Menu", Menu_Key, 0x05, 8);
  addKey("TV/Radio", TunerInput_Key, 0x06, 8);
  addKey("Format", AspectRatio_Key, 0x07, 8);
  addKey("Page+", PageUp_Key, 0x08, 8);
  addKey("1", One_Key, 0x09, 8);
  addKey("FAV", Favorites_Key, 0x0B, 8);
  addKey("Yellow/Upgrade", Yellow_Key, 0x0C, 8);
  addKey("4", Four_Key, 0x0D, 8);
  addKey("Vol -", VolumeDown_Key, 0x0E, 8);
  addKey("Left", Left_Key, 0x0E, 8);
  addKey("EPG", Guide_Key, 0x0F, 8);
  addKey("Recall", PrevChannel_Key, 0x10, 8);
  addKey("7", Seven_Key, 0x11, 8);
  addKey("0", Zero_Key, 0x12, 8);
  addKey("Pause", Pause_Key, 0x13, 8);
  addKey("Mute", Mute_Key, 0x14, 8);
  addKey("8", Eight_Key, 0x15, 8);
  addKey("Zoom", Zoom_Key, 0x16, 8);
  addKey("9", Nine_Key, 0x17, 8);
  addKey("Exit", Exit_Key, 0x18, 8);
  addKey("5", Five_Key, 0x19, 8);
  addKey("Vol +", VolumeUp_Key, 0x1A, 8);
  addKey("Right", Right_Key, 0x1A, 8);
  addKey("6", Six_Key, 0x1B, 8);
  addKey("Standby", Power_Key, 0x1C, 8);
  addKey("2", Two_Key, 0x1D, 8);
  addKey("OK", Select_Key, 0x1E, 8);
  addKey("3", Three_Key, 0x1F, 8);
  addKey("Red/Sub", Red_Key, 0x43, 8);
  addKey("Red/Sub", Captions_Key, 0x43, 8);
  addKey("Green/Audio", Green_Key, 0x47, 8);
  addKey("Green/Audio", Audio_Key, 0x47, 8);
}
