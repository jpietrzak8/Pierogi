//
// insignia.cpp
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

#include "insignia.h"

#include "protocols/necprotocol.h"
#include "protocols/necxprotocol.h"
#include "protocols/recs80protocol.h"
#include "protocols/aiwaprotocol.h"
#include "protocols/rc5protocol.h"
#include <QComboBox>


InsigniaTV1::InsigniaTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Insignia_Make,
      index)
{
}


void InsigniaTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, false);

  setPreData(0x0586, 16);

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
  addKey("channel up", ChannelUp_Key, 0x0A, 8);
  addKey("channel down", ChannelDown_Key, 0x0B, 8);
  addKey("vol up", VolumeUp_Key, 0x0C, 8);
  addKey("vol down", VolumeDown_Key, 0x0D, 8);
  addKey("mute", Mute_Key, 0x0E, 8);
  addKey("POWER", Power_Key, 0x0F, 8);
  addKey("PREV", PrevChannel_Key, 0x10, 8);
  addKey("TV/VCR", Input_Key, 0x12, 8);
  addKey("SLEEP", Sleep_Key, 0x13, 8);
  addKey("MENU", Menu_Key, 0x14, 8);
  addKey("Arrow UP", Up_Key, 0x15, 8);
  addKey("Arrow DOWN", Down_Key, 0x16, 8);
  addKey("INFO", Info_Key, 0x17, 8);
  addKey("SELECT", Select_Key, 0x18, 8);
}


InsigniaTV1a::InsigniaTV1a(
  unsigned int index)
  : InsigniaTV1(index)
{
  setKeysetName("TV Keyset 1a");
}


void InsigniaTV1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  InsigniaTV1::populateProtocol(guiObject);

//  addKey("UP ARROW", Up_Key, 0x0A, 8);
//  addKey("DOWN ARROW", Down_Key, 0x0B, 8);
//  addKey("LEFT ARROW", Left_Key, 0x0D, 8);
  addKey("mts/sap", Audio_Key, 0x11, 8);
  addKey("right arrow", Right_Key, 0x15, 8);
  addKey("left arrow", Left_Key, 0x16, 8);
//  addKey("GUIDE", Guide_Key, 0x17, 8); // dubious
  addKey("exit", Exit_Key, 0x1B, 8);
  addKey("ccd", Captions_Key, 0x1C, 8);
  addKey("input", Input_Key, 0x1D, 8);
  addKey("dot(.)", Dash_Key, 0x41, 8);
  addKey("up arrow", Up_Key, 0x42, 8);
  addKey("down arrow", Down_Key, 0x43, 8);
  addKey("zoom", Zoom_Key, 0x44, 8);
  addKey("guide", Guide_Key, 0x45, 8);
  addKey("Parental Control", Unmapped_Key, 0x47, 8);
  addKey("audio", SoundMode_Key, 0x48, 8);
  addKey("picture", PictureMode_Key, 0x49, 8);
  addKey("favorite", Favorites_Key, 0x4B, 8);
  addKey("video", AuxInput_Key, 0x4C, 8);
  addKey("Component", ComponentInput_Key, 0x4D, 8);
  addKey("tv", AntennaInput_Key, 0x4F, 8);
  addKey("hdmi", HDMIInput_Key, 0x50, 8);
  addKey("DVD", DVDInput_Key, 0x52, 8);
//  addKey("Freeze", Pause_Key, 0x53, 8);
  addKey("Discrete Off", PowerOff_Key, 0x60, 8);
  addKey("Discrete On", PowerOn_Key, 0x61, 8);
  addKey("play", Play_Key, 0x70, 8);
  addKey("DVD/Play-Pause", Pause_Key, 0x70, 8);
  addKey("stop", Stop_Key, 0x71, 8);
  addKey("DVD/Slow", Slow_Key, 0x72, 8);
  addKey("DVD/Title", DiscTitle_Key, 0x73, 8);
  addKey("DVD/Menu", DiscMenu_Key, 0x74, 8);
  addKey("DVD/Setup", Unmapped_Key, 0x75, 8);
  addKey("DVD/Repeat", Repeat_Key, 0x76, 8);
  addKey("DVD/A-B", RepeatAB_Key, 0x77, 8);
  addKey("DVD/T.Search", Unmapped_Key, 0x78, 8);
  addKey("DVD/Audio", Unmapped_Key, 0x79, 8);
  addKey("DVD/Subtitle", Unmapped_Key, 0x7A, 8);
  addKey("DVD/Return", Unmapped_Key, 0x7B, 8);
  addKey("fast fwd", FastForward_Key, 0x7D, 8);
  addKey("rewind", Rewind_Key, 0x7E, 8);
  addKey("next track", Next_Key, 0x7F, 8);
  addKey("prev track", Previous_Key, 0x80, 8);
//  addKey("pause", Pause_Key, 0x81, 8);
  addKey("DVD/Eject", Eject_Key, 0x82,8);
  addKey("ch-list", Unmapped_Key, 0x86, 8);
  addKey("HDMI 1", Unmapped_Key, 0xA2, 8);
  addKey("HDMI 2", Unmapped_Key, 0xA3, 8);
  addKey("HDMI 3", Unmapped_Key, 0xA4, 8);
}


void InsigniaTV1a::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("Input Toggle", QVariant(Input_Key));
  cb->addItem("TV", QVariant(AntennaInput_Key));
  cb->addItem("Video", QVariant(AuxInput_Key));
  cb->addItem("Component", QVariant(ComponentInput_Key));
  cb->addItem("HDMI", QVariant(HDMIInput_Key));
  cb->addItem("DVD", QVariant(DVDInput_Key));
}


InsigniaTV2::InsigniaTV2(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 2",
      Insignia_Make,
      index)
{
}


void InsigniaTV2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new AiwaProtocol(guiObject, index);

  setPreData(0x011A, 13);

  addKey("PICTURE ADJUST MENU", PictureMode_Key, 0x01, 8);
  addKey("DISPLAY", Info_Key, 0x02, 8);
  addKey("PREVIOUS CHANNEL", PrevChannel_Key, 0x03, 8);
  addKey("VOL+", VolumeUp_Key, 0x04, 8);
  addKey("CCD", Captions_Key, 0x06, 8);
  addKey("MENU", Menu_Key, 0x08, 8);
  addKey("CH-", ChannelDown_Key, 0x09, 8);
  addKey("POWER", Power_Key, 0x0A, 8);
  addKey("SLEEP", Sleep_Key, 0x0B, 8);
  addKey("AV/SOURCE", Input_Key, 0x0C, 8);
  addKey("MUTE", Mute_Key, 0x0D, 8);
  addKey("AIR/CABLE", AntennaInput_Key, 0x0E, 8);
  addKey("PICTURE PRESETS", Unmapped_Key, 0x0F, 8);
  addKey("0", Zero_Key, 0x10, 8);
  addKey("1", One_Key, 0x11, 8);
  addKey("2", Two_Key, 0x12, 8);
  addKey("3", Three_Key, 0x13, 8);
  addKey("4", Four_Key, 0x14, 8);
  addKey("5", Five_Key, 0x15, 8);
  addKey("6", Six_Key, 0x16, 8);
  addKey("7", Seven_Key, 0x17, 8);
  addKey("8", Eight_Key, 0x18, 8);
  addKey("9", Nine_Key, 0x19, 8);
  addKey("CH+", ChannelUp_Key, 0x1B, 8);
  addKey("VOL-", VolumeDown_Key, 0x1D, 8);
  addKey("PARENTAL CONTROL", Unmapped_Key, 0x1E, 8);
}


void InsigniaTV2::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("AV / Source", QVariant(Input_Key));
  cb->addItem("Air / Cable", QVariant(AntennaInput_Key));
}


InsigniaTV3::InsigniaTV3(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 3",
      Insignia_Make,
      index)
{
}


void InsigniaTV3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0xD900, 16);

  addKey("mute", Mute_Key, 0x06, 8);
  addKey("select", Select_Key, 0x08, 8);
  addKey("1", One_Key, 0x09, 8);
  addKey("4", Four_Key, 0x0D, 8);
  addKey("7", Seven_Key, 0x11, 8);
  addKey("0", Zero_Key, 0x12, 8);
  addKey("8", Eight_Key, 0x15, 8);
  addKey("enter", Enter_Key, 0x16, 8);
  addKey("9", Nine_Key, 0x17, 8);
  addKey("5", Five_Key, 0x19, 8);
  addKey("6", Six_Key, 0x1B, 8);
  addKey("power", Power_Key, 0x1C, 8);
  addKey("2", Two_Key, 0x1D, 8);
  addKey("3", Three_Key, 0x1F, 8);
  addKey("last/prev ch", PrevChannel_Key, 0x40, 8);
  addKey("tv/vcr", Input_Key, 0x43, 8);
  addKey("vol down", VolumeDown_Key, 0x47, 8);
  addKey("vol up", VolumeUp_Key, 0x48, 8);
  addKey("menu", Menu_Key, 0x4A, 8);
  addKey("display/info", Info_Key, 0x4E, 8);
  addKey("channel up", ChannelUp_Key, 0x4F, 8);
  addKey("channel down", ChannelDown_Key, 0x52, 8);
  addKey("up arrow", Up_Key, 0x5C, 8);
  addKey("down arrow", Down_Key, 0x5D, 8);
  addKey("left arrow", Left_Key, 0x5E, 8);
  addKey("right arrow", Right_Key, 0x5F, 8);
}


InsigniaTV4::InsigniaTV4(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 4",
      Insignia_Make,
      index)
{
}


void InsigniaTV4::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x08, 8);

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
  addKey("Menu", Menu_Key, 0x0C, 8);
  addKey("ChannelPrev", PrevChannel_Key, 0x0E, 8);
  addKey("Mute", Mute_Key, 0x10, 8);
  addKey("PowerToggle", Power_Key, 0x12, 8);
  addKey("InputNext", Input_Key, 0x14, 8);
  addKey("Display", Info_Key, 0x16, 8);
  addKey("VolumeUp", VolumeUp_Key, 0x1A, 8);
  addKey("ChannelUp", ChannelUp_Key, 0x1B, 8);
  addKey("VolumeDown", VolumeDown_Key, 0x1E, 8);
  addKey("ChannelDown", ChannelDown_Key, 0x1F, 8);
  addKey("Sleep", Sleep_Key, 0x45, 8);
  addKey("Scan", Unmapped_Key, 0x5B, 8);
}


InsigniaTV5::InsigniaTV5(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 5",
      Insignia_Make,
      index)
{
}


void InsigniaTV5::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0xF7, 8);

  addKey("channel up", ChannelUp_Key, 0x00, 8);
  addKey("channel down", ChannelDown_Key, 0x01, 8);
  addKey("Vol +", VolumeUp_Key, 0x02, 8);
  addKey("Vol -", VolumeDown_Key, 0x03, 8);
  addKey("up arrow", Up_Key, 0x04, 8);
  addKey("down arrow", Down_Key, 0x05, 8);
  addKey("right arrow", Right_Key, 0x06, 8);
  addKey("left arrow", Left_Key, 0x07, 8);
  addKey("power", Power_Key, 0x08, 8);
  addKey("Mute", Mute_Key, 0x09, 8);
  addKey("sap", Audio_Key, 0x0A, 8);
  addKey("sleep", Sleep_Key, 0x0E, 8);
  addKey("0", Zero_Key, 0x10, 8);
  addKey("1", One_Key, 0x11, 8);
  addKey("2", Two_Key, 0x12, 8);
  addKey("3", Three_Key, 0x13, 8);
  addKey("4", Four_Key, 0x14, 8);
  addKey("5", Five_Key, 0x15, 8);
  addKey("6", Six_Key, 0x16, 8);
  addKey("7", Seven_Key, 0x17, 8);
  addKey("8", Eight_Key, 0x18, 8);
  addKey("9", Nine_Key, 0x19, 8);
  addKey("last (prev ch)", PrevChannel_Key, 0x1A, 8);
  addKey("favourite", Favorites_Key, 0x1E, 8);
  addKey("ClosedCaption", Captions_Key, 0x39, 8);
  addKey("menu", Menu_Key, 0x43, 8);
  addKey("select", Select_Key, 0x44, 8);
  addKey("-", Dash_Key, 0x4C, 8);
  addKey("exit", Exit_Key, 0x5B, 8);
  addKey("zoom", Zoom_Key, 0x79, 8);
  addKey("signal", Unmapped_Key, 0x96, 8);
  addKey("program guide", Guide_Key, 0xA9, 8);
  addKey("display", Info_Key, 0xAA, 8);
}


InsigniaTV6::InsigniaTV6(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 6",
      Insignia_Make,
      index)
{
}


void InsigniaTV6::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

  addKey("0", Zero_Key, 0x0000, 13);
  addKey("1", One_Key, 0x0001, 13);
  addKey("2", Two_Key, 0x0002, 13);
  addKey("3", Three_Key, 0x0003, 13);
  addKey("4", Four_Key, 0x0004, 13);
  addKey("5", Five_Key, 0x0005, 13);
  addKey("6", Six_Key, 0x0006, 13);
  addKey("7", Seven_Key, 0x0007, 13);
  addKey("8", Eight_Key, 0x0008, 13);
  addKey("9", Nine_Key, 0x0009, 13);
  addKey("+100", PlusOneHundred_Key, 0x000A, 13);
  addKey("power", Power_Key, 0x000C, 13);
  addKey("mute", Mute_Key, 0x000D, 13);
  addKey("DSP (info)", Info_Key, 0x000F, 13);
  addKey("vol up", VolumeUp_Key, 0x0010, 13);
  addKey("Right Arrow", Right_Key, 0x0010, 13);
  addKey("vol down", VolumeDown_Key, 0x0011, 13);
  addKey("Left Arrow", Left_Key, 0x0011, 13);
  addKey("Zoom", Zoom_Key, 0x0013, 13); // "Lock"
  addKey("Scan", Unmapped_Key, 0x0014, 13);
  addKey("menu", Guide_Key, 0x0015, 13); // "Parental Controls"
  addKey("Favo.", Favorites_Key, 0x001B, 13);
  addKey("P.Mode", PictureMode_Key, 0x001C, 13);
  addKey("S.Mode", SoundMode_Key, 0x001D, 13);
  addKey("channel up", ChannelUp_Key, 0x0020, 13);
  addKey("Up Arrow", Up_Key, 0x0020, 13);
  addKey("channel down", ChannelDown_Key, 0x0021, 13);
  addKey("Down Arrow", Down_Key, 0x0021, 13);
  addKey("last/prev ch", PrevChannel_Key, 0x0022, 13);
  addKey("SAP", Audio_Key, 0x0023, 13);
  addKey("Freeze", Pause_Key, 0x0024, 13);
  addKey("sleep", Sleep_Key, 0x0026, 13);
  addKey("Picture", AspectRatio_Key, 0x002B, 13);
  addKey("Stereo", Unmapped_Key, 0x002D, 13);
  addKey("Menu", Menu_Key, 0x002E, 13);
  addKey("Input", Input_Key, 0x0038, 13);
  addKey("CCD", Captions_Key, 0x0039, 13);
//  addKey("Audio", Audio_Key, 0x003F, 13);
}


InsigniaDVD1::InsigniaDVD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Insignia_Make,
      index)
{
}


void InsigniaDVD1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x4743, 16);

  addKey("tray", Eject_Key, 0x2E, 8);
  addKey("source", Input_Key, 0x21, 8);
  addKey("power", Power_Key, 0x2F, 8);
  addKey("1", One_Key, 0x01, 8);
  addKey("2", Two_Key, 0x02, 8);
  addKey("3", Three_Key, 0x03, 8);
  addKey("4", Four_Key, 0x04, 8);
  addKey("5", Five_Key, 0x05, 8);
  addKey("6", Six_Key, 0x06, 8);
  addKey("7", Seven_Key, 0x07, 8);
  addKey("8", Eight_Key, 0x08, 8);
  addKey("9", Nine_Key, 0x09, 8);
  addKey("setup", Menu_Key, 0x26, 8);
  addKey("0", Zero_Key, 0x00, 8);
  addKey("bs", Unmapped_Key, 0x29, 8);
  addKey("left1", Unmapped_Key, 0x15, 8);
  addKey("up", Up_Key, 0x11, 8);
  addKey("right1", Unmapped_Key, 0x18, 8); // "right-all"
  addKey("right1", Unmapped_Key, 0x16, 8);
  addKey("left", Unmapped_Key, 0x12, 8);
  addKey("ok", Select_Key, 0x10, 8);
  addKey("right", Unmapped_Key, 0x13, 8);
  addKey("left-all", Unmapped_Key, 0x17, 8);
  addKey("down", Down_Key, 0x14, 8);
  addKey("select", Unmapped_Key, 0x2B, 8);
  addKey("voldn", VolumeDown_Key, 0x0D, 8);
  addKey("volup", VolumeUp_Key, 0x0C, 8);
  addKey("mute", Mute_Key, 0x1C, 8);
  addKey("memory", Unmapped_Key, 0x1B, 8);
  addKey("play", Play_Key, 0x0E, 8);
  addKey("stop", Stop_Key, 0x0F, 8);
  addKey("sleep", Sleep_Key, 0x2A, 8);
  addKey("prog", Unmapped_Key, 0x24, 8);
  addKey("repeat", Repeat_Key, 0x36, 8);
  addKey("A-B", RepeatAB_Key, 0x37, 8);
  addKey("menu", DiscMenu_Key, 0x0A, 8);
  addKey("return-title", DiscTitle_Key, 0x25, 8);
  addKey("surround", Surround_Key, 0x32, 8);
  addKey("eq", Unmapped_Key, 0x34, 8);
  addKey("language", Audio_Key, 0x28, 8);
  addKey("subtitle", Captions_Key, 0x2D, 8);
  addKey("zoom", Zoom_Key, 0x1A, 8);
  addKey("angle", Angle_Key, 0x19, 8);
  addKey("goto", Unmapped_Key, 0x23, 8);
  addKey("display", Info_Key, 0x22, 8);
  addKey("night", Unmapped_Key, 0x30, 8);
  addKey("dim", Unmapped_Key, 0x31, 8);
}


InsigniaDVD2::InsigniaDVD2(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 2",
      Insignia_Make,
      index)
{
}


void InsigniaDVD2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new RECS80Protocol(guiObject, index);

  setPreData(0x5, 3);

  addKey("Tuner", TunerInput_Key, 0x0C, 6);
  addKey("Surround", Surround_Key, 0x0D, 6);
  addKey("Tone", Unmapped_Key, 0x0E, 6);
  addKey("GOTO", Unmapped_Key, 0x10, 6);
  addKey("Subtitle", Captions_Key, 0x11, 6);
  addKey("Zoom/Clear", Zoom_Key, 0x12, 6);
  addKey("A-B", RepeatAB_Key, 0x13, 6);
  addKey("V-Select", Unmapped_Key, 0x14, 6);
  addKey("f.rew/prev track", Rewind_Key, 0x15, 6);
  addKey("f.fwd/next track", FastForward_Key, 0x16, 6);
  addKey("menu", DiscMenu_Key, 0x17, 6);
  addKey("mute", Mute_Key, 0x18, 6);
  addKey("play", Play_Key, 0x19, 6);
  addKey("pause", Pause_Key, 0x1A, 6);
  addKey("Av Select", Unmapped_Key, 0x1B, 6);
  addKey("8", Eight_Key, 0x1C, 6);
  addKey("4", Four_Key, 0x1D, 6);
  addKey("power", Power_Key, 0x1E, 6);
  addKey("Bookmark", Unmapped_Key, 0x1F, 6);
  addKey("Info", Info_Key, 0x20, 6);
  addKey("right arrow", Right_Key, 0x21, 6);
  addKey("stop", Stop_Key, 0x22, 6);
  addKey("7", Seven_Key, 0x24, 6);
  addKey("3", Three_Key, 0x25, 6);
  addKey("Eject", Eject_Key, 0x26, 6);
  addKey("Title/Rotate", DiscTitle_Key, 0x27, 6);
  addKey("up arrow", Up_Key, 0x28, 6);
  addKey("select", Select_Key, 0x29, 6);
  addKey("down arrow", Down_Key, 0x2A, 6);
  addKey("0", Zero_Key, 0x2B, 6);
  addKey("6", Six_Key, 0x2C, 6);
  addKey("2", Two_Key, 0x2D, 6);
  addKey("Angle/PBC", Angle_Key, 0x2E, 6);
  addKey("Audio FM ST", Unmapped_Key, 0x2F, 6);
  addKey("exit", Exit_Key, 0x30, 6);
  addKey("left arrow", Left_Key, 0x31, 6);
  addKey("fast fwd", FastForward_Key, 0x32, 6);
  addKey("9", Nine_Key, 0x33, 6);
  addKey("5", Five_Key, 0x34, 6);
  addKey("1", One_Key, 0x35, 6);
  addKey("Playmode", Unmapped_Key, 0x36, 6);
  addKey("rewind", Rewind_Key, 0x37, 6);
  addKey("sleep", Sleep_Key, 0x38, 6);
  addKey("DVD/Disc Skip", Input_Key, 0x39, 6);
  addKey("vol up", VolumeUp_Key, 0x3A, 6);
  addKey("vol down", VolumeDown_Key, 0x3B, 6);
}


InsigniaDVD3::InsigniaDVD3(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 3",
      Insignia_Make,
      index)
{
}


void InsigniaDVD3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECXProtocol(guiObject, index, true);

  setPreData(0x2D2D, 16);

  addKey("channel up", ChannelUp_Key, 0x00, 8);
  addKey("channel down", ChannelDown_Key, 0x01, 8);
  addKey("vol up", VolumeUp_Key, 0x02, 8);
  addKey("vol down", VolumeDown_Key, 0x03, 8);
  addKey("power", Power_Key, 0x30, 8);
  addKey("play", Play_Key, 0x31, 8);
  addKey("rewind", Rewind_Key, 0x32, 8);
  addKey("fast fwd", FastForward_Key, 0x33, 8);
  addKey("skip fwd", Next_Key, 0x34, 8);
  addKey("skip bkwd", Previous_Key, 0x35, 8);
  addKey("eject open/close", Eject_Key, 0x36, 8);
  addKey("pause", Pause_Key, 0x38, 8);
  addKey("stop", Stop_Key, 0x39, 8);
  addKey("display", Info_Key, 0x3A, 8);
  addKey("1", One_Key, 0x3B, 8);
  addKey("2", Two_Key, 0x3C, 8);
  addKey("3", Three_Key, 0x3D, 8);
  addKey("4", Four_Key, 0x3E, 8);
  addKey("5", Five_Key, 0x3F, 8);
  addKey("6", Six_Key, 0x40, 8);
  addKey("7", Seven_Key, 0x41, 8);
  addKey("8", Eight_Key, 0x42, 8);
  addKey("9", Nine_Key, 0x43, 8);
  addKey("0", Zero_Key, 0x44, 8);
  addKey("return", Exit_Key, 0x45, 8);
  addKey("up arrow", Up_Key, 0x47, 8);
  addKey("down arrow", Down_Key, 0x48, 8);
  addKey("disc menu/list", Unmapped_Key, 0x4B, 8);
  addKey("subtitle", Captions_Key, 0x50, 8);
  addKey("enter", Select_Key, 0x58, 8);
  addKey("left arrow", Left_Key, 0x59, 8);
  addKey("right arrow", Right_Key, 0x5A, 8);
  addKey("home", Unmapped_Key, 0x67, 8);
  addKey("dubbing", Unmapped_Key, 0x68, 8);
  addKey("input", Input_Key, 0xB0, 8);
  addKey("l.skip", Unmapped_Key, 0xB5, 8);
  addKey("record", Record_Key, 0xB6, 8);
  addKey("tv/vcr", AntennaInput_Key, 0xBE, 8);
  addKey("dvd", DVDInput_Key, 0xF1, 8);
  addKey("vcr", VCRInput_Key, 0xF3, 8);
}


void InsigniaDVD3::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("Input Toggle", QVariant(Input_Key));
  cb->addItem("TV / VCR", QVariant(AntennaInput_Key));
  cb->addItem("DVD", QVariant(DVDInput_Key));
  cb->addItem("VCR", QVariant(VCRInput_Key));
}


InsigniaDVD4::InsigniaDVD4(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 4",
      Insignia_Make,
      index)
{
}


void InsigniaDVD4::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x00, 8);

  addKey("0", Zero_Key, 0x00, 8);
  addKey("up arrow", Up_Key, 0x01, 8);
  addKey("prev track", Previous_Key, 0x02, 8);
  addKey("pip move", PIPMove_Key, 0x03, 8);
  addKey("record", Record_Key, 0x03, 8);
  addKey("stop", Stop_Key, 0x04, 8);
  addKey("input toggle", Input_Key, 0x06, 8);
  addKey("pause", Pause_Key, 0x07, 8);
  addKey("exit", Exit_Key, 0x08, 8);
  addKey("down arrow", Down_Key, 0x09, 8);
  addKey("next track", Next_Key, 0x0A, 8);
  addKey("enter", Enter_Key, 0x0B, 8);
  addKey("sleep", Sleep_Key, 0x0B, 8);
  addKey("pip on/off", PIP_Key, 0x0C, 8);
  addKey("vol up", VolumeUp_Key, 0x0D, 8);
  addKey("fast fwd", FastForward_Key, 0x0E, 8);
  addKey("rewind", Rewind_Key, 0x0F, 8);
  addKey("+100", PlusOneHundred_Key, 0x10, 8);
  addKey("right arrow", Right_Key, 0x11, 8);
  addKey("power", Power_Key, 0x12, 8);
  addKey("vol down", VolumeDown_Key, 0x13, 8);
  addKey("shift-left", Unmapped_Key, 0x15, 8);
  addKey("eject", Eject_Key, 0x16, 8);
  addKey("play", Play_Key, 0x17, 8);
  addKey("channel up", Up_Key, 0x18, 8);
  addKey("left arrow", Left_Key, 0x19, 8);
  addKey("shift-right", Unmapped_Key, 0x1A, 8);
  addKey("slow", Slow_Key, 0x1A, 8);
  addKey("display", Info_Key, 0x1B, 8);
  addKey("mute", Mute_Key, 0x1C, 8);
  addKey("pip swap", PIPSwap_Key, 0x1D, 8);
  addKey("program guide", Guide_Key, 0x1E, 8);
  addKey("menu", Menu_Key, 0x1F, 8);
  addKey("select", Select_Key, 0x40, 8);
  addKey("1", One_Key, 0x41, 8);
  addKey("4", Four_Key, 0x42, 8);
  addKey("7", Seven_Key, 0x43, 8);
  addKey("3", Three_Key, 0x45, 8);
  addKey("6", Six_Key, 0x46, 8);
  addKey("9", Nine_Key, 0x47, 8);
  addKey("channel down", ChannelDown_Key, 0x48, 8);
  addKey("last (prev ch)", PrevChannel_Key, 0x49, 8);
  addKey("fav/scan", Favorites_Key, 0x4A, 8);
  addKey("device button", Unmapped_Key, 0x4B, 8);
  addKey("2", Two_Key, 0x4D, 8);
  addKey("5", Five_Key, 0x4E, 8);
  addKey("8", Eight_Key, 0x4F, 8);
}


InsigniaDVD5::InsigniaDVD5(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD (BD) Keyset 5",
      Insignia_Make,
      index)
{
}


void InsigniaDVD5::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x20, 8);

  addKey("open/close", Eject_Key, 0x00, 8);
  addKey("3", Three_Key, 0x01, 8);
  addKey("clear", Clear_Key, 0x02, 8);
  addKey("angle", Angle_Key, 0x03, 8);
  addKey("2", Two_Key, 0x05, 8);
  addKey("0", Zero_Key, 0x06, 8);
  addKey("resolution", AspectRatio_Key, 0x07, 8);
  addKey("power toggle", Power_Key, 0x08, 8);
  addKey("1", One_Key, 0x09, 8);
  addKey("search", Unmapped_Key, 0x0A, 8);
  addKey("repeat", Repeat_Key, 0x0B, 8);
  addKey("6", Six_Key, 0x0D, 8);
  addKey("next chapter", Next_Key, 0x0E, 8);
  addKey("frame adv", StepForward_Key, 0x0F, 8);
  addKey("5", Five_Key, 0x11, 8);
  addKey("prev chapter", Previous_Key, 0x12, 8);
  addKey("play/pause", Play_Key, 0x13, 8);
  addKey("play/pause", Pause_Key, 0x13, 8);
  addKey("4", Four_Key, 0x15, 8);
  addKey("fast fwd", FastForward_Key, 0x16, 8);
  addKey("stop", Stop_Key, 0x17, 8);
  addKey("7", Seven_Key, 0x19, 8);
  addKey("fast rev", Rewind_Key, 0x1A, 8);
  addKey("zoom", Zoom_Key, 0x1B, 8);
  addKey("8", Eight_Key, 0x1D, 8);
  addKey("9", Nine_Key, 0x1E, 8);
  addKey("display", Info_Key, 0x40, 8);
  addKey("return", Exit_Key, 0x42, 8);
  addKey("D", Blue_Key, 0x43, 8);
  addKey("right arrow", Right_Key, 0x44, 8);
  addKey("audio", SoundMode_Key, 0x46, 8);
  addKey("C", Yellow_Key, 0x47, 8);
  addKey("A-B", RepeatAB_Key, 0x48, 8);
  addKey("subtitle", Captions_Key, 0x4A, 8);
  addKey("B", Green_Key, 0x4B, 8);
  addKey("popup/title menu", DiscTitle_Key, 0x4C, 8);
  addKey("setup", Menu_Key, 0x4E, 8);
  addKey("A", Red_Key, 0x4F, 8);
  addKey("up arrow", Up_Key, 0x50, 8);
  addKey("secondary audio", Audio_Key, 0x52, 8);
  addKey("menu", DiscMenu_Key, 0x54, 8);
  addKey("left arrow", Left_Key, 0x58, 8);
  addKey("select", Select_Key, 0x5C, 8);
  addKey("down arrow", Down_Key, 0x5D, 8);
  addKey("PIP", PIP_Key, 0x5E, 8);
}


InsigniaDVD6::InsigniaDVD6(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 6",
      Insignia_Make,
      index)
{
}


void InsigniaDVD6::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0xED85, 16);

  addKey("power", Power_Key, 0x06, 8);
  addKey("audio", Audio_Key, 0x09, 8);
  addKey("subtitle", Captions_Key, 0x0A, 8);
  addKey("disc menu", DiscMenu_Key, 0x0B, 8);
  addKey("popup menu", Guide_Key, 0x0C, 8);
//  addKey("program guide", Guide_Key, 0x0B, 8);
//  addKey("menu", DiscMenu_Key, 0x0C, 8);
  addKey("setup", Menu_Key, 0x0D, 8);
  addKey("audio setup", SoundMode_Key, 0x0E, 8);
  addKey("left arrow", Left_Key, 0x0F, 8);
  addKey("up arrow", Up_Key, 0x11, 8);
  addKey("right arrow", Right_Key, 0x13, 8);
  addKey("down arrow", Down_Key, 0x15, 8);
  addKey("select", Select_Key, 0x17, 8);
  addKey("stop", Stop_Key, 0x19, 8);
  addKey("play", Play_Key, 0x1A, 8);
  addKey("pause", Pause_Key, 0x1A, 8);
  addKey("channel down", ChannelDown_Key, 0x1C, 8);
  addKey("skip-", Previous_Key, 0x1C, 8);
  addKey("channel up", ChannelUp_Key, 0x1D, 8);
  addKey("skip+", Next_Key, 0x1D, 8);
  addKey("rewind", Rewind_Key, 0x1E, 8);
  addKey("fast fwd", FastForward_Key, 0x1F, 8);
  addKey("step", StepForward_Key, 0x23, 8);
  addKey("display", Info_Key, 0x24, 8);
  addKey("eject", Eject_Key, 0x26, 8);
  addKey("angle", Angle_Key, 0x27, 8);
  addKey("0", Zero_Key, 0x28, 8);
  addKey("1", One_Key, 0x2A, 8);
  addKey("2", Two_Key, 0x2C, 8);
  addKey("3", Three_Key, 0x2E, 8);
  addKey("4", Four_Key, 0x30, 8);
  addKey("5", Five_Key, 0x32, 8);
  addKey("6", Six_Key, 0x34, 8);
  addKey("7", Seven_Key, 0x36, 8);
  addKey("8", Eight_Key, 0x38, 8);
  addKey("9", Nine_Key, 0x3A, 8);
  addKey("zoom", Zoom_Key, 0x3C, 8);
  addKey("repeat", Repeat_Key, 0x3E, 8);
  addKey("repeat a", RepeatAB_Key, 0x3F, 8);
  addKey("clear", Clear_Key, 0x40, 8);
  addKey("resolution", AspectRatio_Key, 0x42, 8);
  addKey("searchm", Unmapped_Key, 0x45, 8);
  addKey("exit", Exit_Key, 0x46, 8);
  addKey("red", Red_Key, 0x4C, 8);
  addKey("green", Green_Key, 0x4D, 8);
  addKey("yellow", Yellow_Key, 0x4E, 8);
  addKey("blue", Blue_Key, 0x4F, 8);
  addKey("pip", PIP_Key, 0x50, 8);
  addKey("secondary", Unmapped_Key, 0x51, 8);  // "Secondary Audio"
  addKey("vol-", VolumeDown_Key, 0x60, 8);
  addKey("vol+", VolumeUp_Key, 0x61, 8);
  addKey("eq mode", Unmapped_Key, 0x63, 8);
  addKey("bass on/off", EnhancedBass_Key, 0x66, 8);
  addKey("mute", Mute_Key, 0x6A, 8);
  addKey("video source", CompositeInput_Key, 0x6B, 8);
  addKey("fm/am", TunerInput_Key, 0x6C, 8);
  addKey("audio source", AuxInput_Key, 0x6D, 8);
  addKey("surround mode", Surround_Key, 0xBF, 8);
}


void InsigniaDVD6::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("Input Toggle", QVariant(Input_Key));
  cb->addItem("Video", QVariant(CompositeInput_Key));
  cb->addItem("FM / AM toggle", QVariant(TunerInput_Key));
  cb->addItem("Audio", QVariant(AuxInput_Key));
}
