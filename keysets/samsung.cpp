//
// samsung.cpp
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

#include "samsung.h"
#include "protocols/necxprotocol.h"
#include "protocols/lircprotocol.h"
#include "protocols/rc5protocol.h"
#include "protocols/samsungacprotocol.h"
#include "protocols/necprotocol.h"
#include "protocols/nokia32protocol.h"
#include <QComboBox>

SamsungTV1::SamsungTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Samsung_Make,
      TV_Panels | MediaControl_Panels | MediaRecord_Panels,
      index)
{
  addControlledDevice(Samsung_Make, "SyncMaster 192MP", TV_Device);
  addControlledDevice(Samsung_Make, "SyncMaster 225MW", TV_Device);
  addControlledDevice(Samsung_Make, "LN32C530F1FXZA", TV_Device);
  addControlledDevice(Samsung_Make, "UE46B6000VPXZG", TV_Device); // ?
  addControlledDevice(Samsung_Make, "LE22B470C9M", TV_Device);
}


void SamsungTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECXProtocol(guiObject, index, false);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x0707, 16);

  addKey("mts", Audio_Key, 0x00, 8); // "dual"
  addKey("TV/Video", Input_Key, 0x01, 8); // This might not be a toggle
  addKey("Power", Power_Key, 0x02, 8);
  addKey("Sleep", Sleep_Key, 0x03, 8);
  addKey("1", One_Key, 0x04, 8);
  addKey("2", Two_Key, 0x05, 8);
  addKey("3", Three_Key, 0x06, 8);
  addKey("Volume Up", VolumeUp_Key, 0x07, 8);
  addKey("4", Four_Key, 0x08, 8);
  addKey("5", Five_Key, 0x09, 8);
  addKey("6", Six_Key, 0x0A, 8);
  addKey("Volume Down", VolumeDown_Key, 0x0B, 8);
  addKey("7", Seven_Key, 0x0C, 8);
  addKey("8", Eight_Key, 0x0D, 8);
  addKey("9", Nine_Key, 0x0E, 8);
  addKey("Mute", Mute_Key, 0x0F, 8);
  addKey("Channel Down", ChannelDown_Key, 0x10, 8);
  addKey("0", Zero_Key, 0x11, 8);
  addKey("Channel Up", ChannelUp_Key, 0x12, 8);
  addKey("PrevCh", PrevChannel_Key, 0x13, 8);
  addKey("Green", Green_Key, 0x14, 8);
  addKey("Yellow", Yellow_Key, 0x15, 8);
  addKey("Blue", Blue_Key, 0x16, 8);
  addKey("Menu", Menu_Key, 0x1A, 8);
  addKey("Display", Info_Key, 0x1F, 8);
  addKey("PIP", PIP_Key, 0x20, 8);
  addKey("Swap", PIPSwap_Key, 0x21, 8);
  addKey("position", PIPMove_Key, 0x22, 8); // "PIP Locate"
  addKey("-/--", DoubleDigit_Key, 0x23, 8); // "-/--/hold"
  addKey("+100", PlusOneHundred_Key, 0x23, 8);
  addKey("DASH", Dash_Key, 0x23, 8);
  addKey("PIP.SOURCE", PIPSource_Key, 0x24, 8);
  addKey("Closed Captions", Captions_Key, 0x25, 8); // "SUBTITLE"
  addKey("AD", Unmapped_Key, 0x27, 8);
  addKey("PMode", PictureMode_Key, 0x28, 8); // "p.std"
  addKey("SMode", SoundMode_Key, 0x2B, 8);
  addKey("ttx/mix", Teletext_Key, 0x2C, 8); // "teletext"
  addKey("Exit", Exit_Key, 0x2D, 8);
  addKey("size", AspectRatio_Key, 0x2F, 8);
  addKey("ch.scan", PIPScan_Key, 0x31, 8);  // "h.scan"
  addKey("PIP.chan+", PIPChannelUp_Key, 0x32, 8); // "AUDCH_UP"
  addKey("PIP.chan-", PIPChannelDown_Key, 0x33, 8); // "AUDCH_DOWN"
  addKey("ANTENNA", AntennaInput_Key, 0x36, 8);
  addKey("Toggle Service Menu", ServiceMenu_Key, 0x3B, 8); // Dangerous!
  addKey("surf", Unmapped_Key, 0x3D, 8); // "r.surf"
  addKey("PSize", PIPSize_Key, 0x3E, 8); // "P.Size (aspect)"
  addKey("STILL", PIPPause_Key, 0x42, 8);
  addKey("TV-DTV", ComponentInput_Key, 0x43, 8); // "tv/component"
  addKey("FAV-CH", Favorites_Key, 0x44, 8);
  addKey("Rewind", Rewind_Key, 0x45, 8);
  addKey("Stop", Stop_Key, 0x46, 8);
  addKey("Play/Pause", Play_Key, 0x47, 8);
  addKey("Play/Pause", Pause_Key, 0x47, 8);
  addKey("Fast Forward", FastForward_Key, 0x48, 8);
  addKey("Record", Record_Key, 0x49, 8);
  addKey("Tools", ToolsMenu_Key, 0x4B, 8);
  addKey("Guide", Guide_Key, 0x4F, 8);
  addKey("RETURN", Back_Key, 0x58, 8);
  addKey("Up", Up_Key, 0x60, 8);
  addKey("Down", Down_Key, 0x61, 8);
  addKey("Right", Right_Key, 0x62, 8);
  addKey("Left", Left_Key, 0x65, 8);
  addKey("Enter", Select_Key, 0x68, 8);
  addKey("pc", PCInput_Key, 0x69, 8);
  addKey("ch-mgr", Unmapped_Key, 0x6B, 8); // "CH_LIST"
  addKey("Red", Red_Key, 0x6C, 8);  // "red/turbo"
  addKey("srs", Surround_Key, 0x6E, 8);
  addKey("E.SAVING", EnergySave_Key, 0x77, 8);
  addKey("Content", Unmapped_Key, 0x79, 8);
  addKey("Display VCR on TV", VCRInput_Key, 0x7A, 8);
  addKey("Display Cable on TV", CableInput_Key, 0x7B, 8);
  addKey("Display TV on TV", Unmapped_Key, 0x7D, 8);
  addKey("Display DVD on TV", DVDInput_Key, 0x7E, 8);
  addKey("AV1", CompositeInput_Key, 0x84, 8);
  addKey("S-Video 1", SVideoInput_Key, 0x85, 8);
  addKey("Component 1", ComponentInput_Key, 0x86, 8);
  addKey("Component 2", Component2Input_Key, 0x88, 8);
  addKey("HDMI", HDMIInput_Key, 0x8B, 8);
  addKey("WISELINK", Unmapped_Key, 0x8C, 8); // "W.Link", "Media.P"
  addKey("D.MENU", Unmapped_Key, 0x8E, 8); // "D-Net Menu"
  addKey("Internet", Unmapped_Key, 0x93, 8);
  addKey("E.Mode", Unmapped_Key, 0x94, 8);
  addKey("ANYNET", CECMenu_Key, 0x97, 8);
  addKey("DiscreteOff", PowerOff_Key, 0x98, 8);
  addKey("DiscreteOn", PowerOn_Key, 0x99, 8);
  addKey("Dynamic Picture Mode", Unmapped_Key, 0xBD, 8);
  addKey("Movie Picture Mode", Unmapped_Key, 0xDE, 8);
  addKey("4:3", Unmapped_Key, 0xE3, 8);
  addKey("16:9", Unmapped_Key, 0xE4, 8);
  addKey("Auto Format", Unmapped_Key, 0xE5, 8);
  addKey("HDMI 2", HDMI2Input_Key, 0xE9, 8);
  addKey("AV2", Composite2Input_Key, 0xEB, 8);
  addKey("AV3", VideoInput_Key, 0xEC, 8); // hack
  addKey("S-Video 2", SVideo2Input_Key, 0xED, 8);
  addKey("S-Video 3", Video2Input_Key, 0xFB, 8); // hack
  addKey("Component 3", Video3Input_Key, 0xFD, 8); // hack
}


void SamsungTV1::populateInputList(
  QComboBox *cb) const
{
  cb->clear();

  cb->addItem("Input Toggle", QVariant(Input_Key));
  cb->addItem("Antenna", QVariant(AntennaInput_Key));
  cb->addItem("PC", QVariant(PCInput_Key));
  cb->addItem("VCR", QVariant(VCRInput_Key));
  cb->addItem("Cable", QVariant(CableInput_Key));
  cb->addItem("DVD", QVariant(DVDInput_Key));
  cb->addItem("AV 1", QVariant(CompositeInput_Key));
  cb->addItem("AV 2", QVariant(Composite2Input_Key));
  cb->addItem("AV 3", QVariant(VideoInput_Key));
  cb->addItem("S-Video 1", QVariant(SVideoInput_Key));
  cb->addItem("S-Video 2", QVariant(SVideo2Input_Key));
  cb->addItem("S-Video 3", QVariant(Video2Input_Key));
  cb->addItem("Component", QVariant(ComponentInput_Key));
  cb->addItem("Component 2", QVariant(Component2Input_Key));
  cb->addItem("Component 3", QVariant(Video3Input_Key));
  cb->addItem("HDMI", QVariant(HDMIInput_Key));
  cb->addItem("HDMI 2", QVariant(HDMI2Input_Key));
}


SamsungTV1a::SamsungTV1a(
  unsigned int index)
  : SamsungTV1(index)
{
  setKeysetName("TV Keyset 1a");

  addControlledDevice(Samsung_Make, "LE46M51B (R)", TV_Device); // ?
}


void SamsungTV1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  SamsungTV1::populateProtocol(guiObject);

  addKey("Red", Red_Key, 0x21, 8);
  addKey("Exit", Exit_Key, 0x2C, 8);
}


SamsungTV1b::SamsungTV1b(
  unsigned int index)
  : SamsungTV1(index)
{
  setKeysetName("TV Keyset 1b");
}


void SamsungTV1b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  SamsungTV1::populateProtocol(guiObject);

  addKey("P.Size (aspect)", AspectRatio_Key, 0x3E, 8);
  addKey("select component 1", ComponentInput_Key, 0x86, 8);
  addKey("select DVI", PCInput_Key, 0x8A, 8);
  addKey("select HDMI 2", HDMI2Input_Key, 0xBE, 8);
  addKey("Aspect Zoom 2", Unmapped_Key, 0xE1, 8);
  addKey("Aspect 4:3", Unmapped_Key, 0xE3, 8);
  addKey("Aspect 16:9", Unmapped_Key, 0xE4, 8);
  addKey("select HDMI 1", HDMIInput_Key, 0xE9, 8);
}


// Keyset 2 is intended for older Samsung TVs.  In particular, it seems that
// some older Samsung TVs only use the last seven bits of the command value,
// so commands with the high bit set won't work in any case...
SamsungTV2::SamsungTV2(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 2",
      Samsung_Make,
      TV_Panels | MediaControl_Panels | MediaRecord_Panels,
      index)
{
}


void SamsungTV2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECXProtocol(guiObject, index, false);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x0707, 16);

  addKey("mts", Audio_Key, 0x00, 8); // "dual"
  addKey("Input Select", Input_Key, 0x01, 8); // On older Samsungs, not toggle
  addKey("Input Select", AuxInput_Key, 0x01, 8);
  addKey("Power", Power_Key, 0x02, 8);
  addKey("Sleep", Sleep_Key, 0x03, 8);
  addKey("1", One_Key, 0x04, 8);
  addKey("2", Two_Key, 0x05, 8);
  addKey("3", Three_Key, 0x06, 8);
  addKey("Volume Up", VolumeUp_Key, 0x07, 8);
  addKey("right arrow", Right_Key, 0x07, 8);
  addKey("4", Four_Key, 0x08, 8);
  addKey("5", Five_Key, 0x09, 8);
  addKey("6", Six_Key, 0x0A, 8);
  addKey("Volume Down", VolumeDown_Key, 0x0B, 8);
  addKey("left arrow", Left_Key, 0x0B, 8);
  addKey("7", Seven_Key, 0x0C, 8);
  addKey("8", Eight_Key, 0x0D, 8);
  addKey("9", Nine_Key, 0x0E, 8);
  addKey("Mute", Mute_Key, 0x0F, 8);
  addKey("Channel Down", ChannelDown_Key, 0x10, 8);
  addKey("down arrow", Down_Key, 0x10, 8);
  addKey("0", Zero_Key, 0x11, 8);
  addKey("Channel Up", ChannelUp_Key, 0x12, 8);
  addKey("up arrow", Up_Key, 0x12, 8);
  addKey("PrevCh", PrevChannel_Key, 0x13, 8);
  addKey("turbo", Red_Key, 0x13, 8); // "Turbo/Red"
  addKey("Green", Green_Key, 0x14, 8);
  addKey("s.menu", SoundMode_Key, 0x14, 8); // "S.Menu/Green"
  addKey("Yellow", Yellow_Key, 0x15, 8);
  addKey("s.std", Unmapped_Key, 0x15, 8); // "S.Std/Yellow"
  addKey("Blue", Blue_Key, 0x16, 8);
  addKey("p.std", Unmapped_Key, 0x16, 8); // "P.Std/Blue"
  addKey("add/erase", Unmapped_Key, 0x19, 8);
  addKey("Menu", Menu_Key, 0x1A, 8);
  addKey("Menu", Select_Key, 0x1A, 8);
  addKey("tv", AntennaInput_Key, 0x1B, 8); // select TV
  addKey("p.menu", PictureMode_Key, 0x1E, 8);
  addKey("Display", Info_Key, 0x1F, 8);
  addKey("PIP", PIP_Key, 0x20, 8);
  addKey("Swap", PIPSwap_Key, 0x21, 8);
  addKey("position", PIPMove_Key, 0x22, 8); // "PIP Locate"
  addKey("-/--", DoubleDigit_Key, 0x23, 8); // "-/--/hold"
  addKey("+100", PlusOneHundred_Key, 0x23, 8);
  addKey("DASH", Dash_Key, 0x23, 8);
  addKey("PIP.SOURCE", PIPSource_Key, 0x24, 8);
  addKey("Closed Captions", Captions_Key, 0x25, 8); // "SUBTITLE"
  addKey("AD", Unmapped_Key, 0x27, 8);
  addKey("ttx/mix", Teletext_Key, 0x2C, 8); // "teletext"
  addKey("ch.scan", PIPScan_Key, 0x31, 8);  // "h.scan"
  addKey("PIP.chan+", PIPChannelUp_Key, 0x32, 8); // "AUDCH_UP"
  addKey("PIP.chan-", PIPChannelDown_Key, 0x33, 8); // "AUDCH_DOWN"
  addKey("Toggle Service Menu", ServiceMenu_Key, 0x3B, 8); // Dangerous!
  addKey("surf", Unmapped_Key, 0x3D, 8); // "r.surf"
  addKey("Zoom", AspectRatio_Key, 0x3E, 8);
  addKey("STILL", Pause_Key, 0x42, 8);
  addKey("TV-DTV", ComponentInput_Key, 0x43, 8); // "tv/component"
  addKey("FAV-CH", Favorites_Key, 0x44, 8);
  addKey("Rewind", Rewind_Key, 0x45, 8);
  addKey("Stop", Stop_Key, 0x46, 8);
  addKey("Play/Pause", Play_Key, 0x47, 8);
  addKey("Play/Pause", Pause_Key, 0x47, 8);
  addKey("Fast Forward", FastForward_Key, 0x48, 8);
  addKey("Record", Record_Key, 0x49, 8);
  addKey("Guide", Guide_Key, 0x4F, 8);
  addKey("pc", PCInput_Key, 0x69, 8);
  addKey("ch-mgr", Unmapped_Key, 0x6B, 8); // "CH_LIST"
  addKey("srs", Surround_Key, 0x6E, 8);
  addKey("E.SAVING", EnergySave_Key, 0x77, 8);
  addKey("Content", Unmapped_Key, 0x79, 8);

//  addKey("enter", Enter_Key, 0x16, 8);
//  addKey("select", Select_Key, 0x27, 8);
}


void SamsungTV2::populateInputList(
  QComboBox *cb) const
{
  cb->clear();

  cb->addItem("Input Select", QVariant(Input_Key));
  cb->addItem("TV", QVariant(AntennaInput_Key));
  cb->addItem("TV / Component", QVariant(ComponentInput_Key));
  cb->addItem("PC", QVariant(PCInput_Key));
}


// Not sure that this even is a Samsung TV...
SamsungTV3::SamsungTV3(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 3",
      Samsung_Make,
      TV_Panels,
      index)
{
}


void SamsungTV3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

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
  addKey("TV", Unmapped_Key, 0x103F, 13);
  addKey("Power", Power_Key, 0x100C, 13);
  addKey("Video", Unmapped_Key, 0x1038, 13);
  addKey("Display", Info_Key, 0x100F, 13); // [+]
  addKey("Sleep", Sleep_Key, 0x1026, 13);
  addKey("-/--", DoubleDigit_Key, 0x100A, 13);
  addKey("P.STD", PictureMode_Key, 0x100E, 13); // "Colour"
  addKey("Mute", Mute_Key, 0x100D, 13);
  addKey("P.Size", AspectRatio_Key, 0x1016, 13);
  addKey("Vol-", VolumeDown_Key, 0x0015, 13);
  addKey("Vol+", VolumeUp_Key, 0x0016, 13);
  addKey("CH/P_UP", ChannelUp_Key, 0x0010, 13);
  addKey("CH/P_DOWN", ChannelDown_Key, 0x0011, 13);
  addKey("Menu", Menu_Key, 0x0012, 13);
  addKey("TTX/MIX", Teletext_Key, 0x103C, 13);
  addKey("Red", Red_Key, 0x002B, 13);
  addKey("Green", Green_Key, 0x002C, 13);
  addKey("Yellow", Yellow_Key, 0x002D, 13);
  addKey("Blue", Blue_Key, 0x002E, 13);
  addKey(">>", FastForward_Key, 0x101E, 13);
  addKey("colour+", ColorUp_Key, 0x1014, 13);
  addKey("colour-", ColorDown_Key, 0x1015, 13);
  addKey("brightness+", BrightnessUp_Key, 0x1012, 13);
  addKey("brightness-", BrightnessDown_Key, 0x1013, 13);
  addKey("contrast+", ContrastUp_Key, 0x101C, 13);
  addKey("contrast-", ContrastDown_Key, 0x101D, 13);
}


SamsungTV3a::SamsungTV3a(
  unsigned int index)
  : SamsungTV3(index)
{
  setKeysetName("TV Keyset 3a");
}


void SamsungTV3a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  SamsungTV3::populateProtocol(guiObject);

  addKey("volume+", VolumeUp_Key, 0x1010, 13);
  addKey("volume-", VolumeDown_Key, 0x1011, 13);
  addKey("prog+", ChannelUp_Key, 0x1020, 13);
  addKey("prog-", ChannelDown_Key, 0x1021, 13);
}


SamsungVCR1::SamsungVCR1(
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR(DVD) Keyset 1",
      Samsung_Make,
      MediaControl_Panels | MediaRecord_Panels,
      index)
{
}


void SamsungVCR1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECXProtocol(guiObject, index, false);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x0505, 16);

  addKey("TV/Video", Input_Key, 0x01, 8);
  addKey("Power", Power_Key, 0x02, 8);
  addKey("A.REP", Unmapped_Key, 0x03, 8);
  addKey("One", One_Key, 0x04, 8);
  addKey("Two", Two_Key, 0x05, 8);
  addKey("Three", Three_Key, 0x06, 8);
  addKey("Four", Four_Key, 0x08, 8);
  addKey("Five", Five_Key, 0x09, 8);
  addKey("Six", Six_Key, 0x0A, 8);
  addKey("Seven", Seven_Key, 0x0C, 8);
  addKey("Eight", Eight_Key, 0x0D, 8);
  addKey("Nine", Nine_Key, 0x0E, 8);

  addKey("ChannelDown", ChannelDown_Key, 0x10, 8);
  addKey("Zero", Zero_Key, 0x11, 8);
  addKey("ChannelUp", ChannelUp_Key, 0x12, 8);
  addKey("SLOW_UP", SlowPlus_Key, 0x13, 8);
  addKey("Record", Record_Key, 0x14, 8);
  addKey("Stop", Stop_Key, 0x15, 8);
  addKey("Rewind", Rewind_Key, 0x18, 8);
  addKey("SLOW_DOWN", SlowMinus_Key, 0x17, 8);
  addKey("Play/Pause", Play_Key, 0x19, 8);
  addKey("Play/Pause", Pause_Key, 0x19, 8);
  addKey("FastForward", FastForward_Key, 0x1A, 8);
  addKey("Memory", Memory_Key, 0x1C, 8);
  addKey("Clear", Reset_Key, 0x1D, 8); // "CNT.RESET", "CLR_RST", "reset"
//  addKey("Exit", Exit_Key, 0x1D, 8);
  addKey("Info", Info_Key, 0x1E, 8); // "display"
  addKey("Menu", Menu_Key, 0x1F, 8);

  addKey("Eject", Eject_Key, 0x20, 8);
  addKey("auto_track", AutoTracking_Key, 0x21, 8); // "A.TRK"
  addKey("Captions", Captions_Key, 0x22, 8);
  addKey("BAND", TunerInput_Key, 0x23, 8);
  addKey("input", Unmapped_Key, 0x24, 8);
  addKey("shift", Unmapped_Key, 0x25, 8);
  addKey("100+", PlusOneHundred_Key, 0x26, 8);
  addKey("Down", Down_Key, 0x29, 8); // "erase"
  addKey("mark/search", IndexSearch_Key, 0x2B, 8); // "index"
  addKey("trk_up", TrackingPlus_Key, 0x2C, 8); // "FINE_UP"
  addKey("trk_down", TrackingMinus_Key, 0x2D, 8); // "FINE_DOWN"
  addKey("dub", Unmapped_Key, 0x2E, 8);
  addKey("Up", Up_Key, 0x2F, 8); // "mark"

  addKey("timer", Unmapped_Key, 0x30, 8); // "MONITOR", "showview", "SHOWVIEW"
  addKey("SEARCH", Unmapped_Key, 0x31, 8);
  addKey("SYSTEM", Unmapped_Key, 0x32, 8);
  addKey("CLK_COUNT", Unmapped_Key, 0x33, 8); // "clk/cnt"
  addKey("PRESET", Unmapped_Key, 0x35, 8);
  addKey("VPS", RecordPDC_Key, 0x38, 8);
  addKey("progressive/speed", VHSSpeed_Key, 0x3A, 8); // "SP-LP"
  addKey("Q_PRO", Unmapped_Key, 0x3D, 8);

  addKey("Enter", Select_Key, 0x5C, 8); // "ok"
  addKey("Dma", Unmapped_Key, 0x63, 8);

  addKey("ipc", PictureMode_Key, 0x75, 8); // "PICTURE"
  addKey("Left", Left_Key, 0x7D, 8); // "shuttle<"
  addKey("Right", Right_Key, 0x7E, 8); // "shuttle>"
}


SamsungVCR1a::SamsungVCR1a(
  unsigned int index)
  : SamsungVCR1(index)
{
  setKeysetName("VCR(DVD) Keyset 1a");
}


void SamsungVCR1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  SamsungVCR1::populateProtocol(guiObject);

  addKey("right", Right_Key, 0x13, 8);
  addKey("left", Left_Key, 0x17, 8);
  addKey("vcr", Unmapped_Key, 0x28, 8);
  addKey("up", Up_Key, 0x2C, 8);
  addKey("down", Down_Key, 0x2D, 8);
  addKey("clear", Clear_Key, 0x31, 8);
  addKey("audio", Audio_Key, 0x3D, 8);
  addKey("enter", Select_Key, 0x43, 8); // "ok"
  addKey("angle/timer", Unmapped_Key, 0x45, 8);
  addKey("power", Power_Key, 0x48, 8);
  addKey("dvd", Unmapped_Key, 0x55, 8);
  addKey("input_sel", Input_Key, 0x59, 8);
  addKey("disc_menu", DiscMenu_Key, 0x60, 8);
  addKey("mode/repeat", Unmapped_Key, 0x66, 8);
  addKey("menu", Menu_Key, 0x68, 8);
}


SamsungVCR1b::SamsungVCR1b(
  unsigned int index)
  : SamsungVCR1(index)
{
  setKeysetName("VCR(DVD) Keyset 1b");
}


void SamsungVCR1b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  SamsungVCR1::populateProtocol(guiObject);

  addKey("audio", Audio_Key, 0x22, 8); // "output"
  addKey("+", Unmapped_Key, 0x26, 8);
  addKey("-", Unmapped_Key, 0x28, 8);
  addKey("pause", Pause_Key, 0x16, 8); // "P/S"
  addKey("prog", Program_Key, 0x1F, 8);
  addKey("aft", Unmapped_Key, 0x74, 8);
  addKey("SYSTEM", Menu_Key, 0x69, 8);
  addKey("OK_UP", Up_Key, 0x52, 8);
  addKey("OK_DOWN", Down_Key, 0x50, 8);
  addKey("OK_LEFT", Left_Key, 0x73, 8);
  addKey("OK_RIGHT", Right_Key, 0x77, 8);
}


SamsungVCR1c::SamsungVCR1c(
  unsigned int index)
  : SamsungVCR1a(index)
{
  setKeysetName("VCR(DVD) Keyset 1c");

  addControlledDevice(Samsung_Make, "DVD-V1000", DVD_Device);
}


void SamsungVCR1c::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  SamsungVCR1a::populateProtocol(guiObject);

  addKey("right", Right_Key, 0x00, 8);
  addKey("up", Up_Key, 0x1E, 8);
  addKey("timer", Sleep_Key, 0x22, 8);
  addKey("speed", VHSSpeed_Key, 0x30, 8);
  addKey("down", Down_Key, 0x31, 8);
  addKey("eject", Eject_Key, 0x32, 8);
  addKey("return", Exit_Key, 0x3D, 8);
  addKey("vol_down", VolumeDown_Key, 0x40, 8);
  addKey("prev_ch", PrevChannel_Key, 0x54, 8);
  addKey("vol_up", VolumeUp_Key, 0x63, 8);
  addKey("left", Left_Key, 0x66, 8);
}


SamsungVCR1d::SamsungVCR1d(
  unsigned int index)
  : SamsungVCR1(index)
{
  // Combo VCR/TV:
  addControlledDevice(Samsung_Make, "CXD1342", TV_Device);
  addControlledDevice(Samsung_Make, "CXD1342", VCR_Device);

  setKeysetName("VCR/TV Combo Keyset 1d");
}


void SamsungVCR1d::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  SamsungVCR1::populateProtocol(guiObject);

  addKey("VOL+", VolumeUp_Key, 0x07, 8);
  addKey("VOL-", VolumeDown_Key, 0x0B, 8);
  addKey("MUTE", Mute_Key, 0x0F, 8);
  addKey("P./STILL", Pause_Key, 0x16, 8);
  addKey("PRE-CH", PrevChannel_Key, 0x2A, 8);
  addKey("eject", Eject_Key, 0x32, 8);
  addKey("REPEAT", Repeat_Key, 0x37, 8);
  addKey("P-STD", Unmapped_Key, 0x6F, 8); // Picture mode?
}


SamsungVCR1e::SamsungVCR1e(
  unsigned int index)
  : SamsungVCR1(index)
{
  setKeysetName("VCR(DVD) Keyset 1e");
}


void SamsungVCR1e::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  SamsungVCR1::populateProtocol(guiObject);

  addKey("DIGEST", Unmapped_Key, 0x00, 8);
  addKey("RIGHT", Right_Key, 0x13, 8);
  addKey("LEFT", Left_Key, 0x17, 8);
  addKey("DISC_MENU", DiscMenu_Key, 0x1F, 8);
  addKey("3D_SOUND", Surround_Key, 0x26, 8);
  addKey("VCR", Unmapped_Key, 0x28, 8);
  addKey("UP", Up_Key, 0x2C, 8);
  addKey("DOWN", Down_Key, 0x2D, 8);
  addKey("CLOCK/COUNTER", Clock_Key, 0x31, 8);
  addKey("OPEN/CLOSE", Eject_Key, 0x32, 8);
  addKey("ZOOM", Zoom_Key, 0x3A, 8);
  addKey("RETURN", Exit_Key, 0x3D, 8);
  addKey("TRK_DOWN", TrackingMinus_Key, 0x40, 8);
  addKey("SETUP/ENTER", Menu_Key, 0x43, 8);
  addKey("SETUP/ENTER", Select_Key, 0x43, 8);
  addKey("ANGLE", Angle_Key, 0x54, 8);
  addKey("DVD", Unmapped_Key, 0x55, 8);
  addKey("INPUT_SEL", Input_Key, 0x59, 8);
  addKey("TITLE", DiscTitle_Key, 0x60, 8);
  addKey("TRK_UP", TrackingPlus_Key, 0x63, 8);
  addKey("MODE/REPEAT", Repeat_Key, 0x66, 8);
  addKey("AUDIO", Audio_Key, 0x68, 8);
}


SamsungDVD1::SamsungDVD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Samsung_Make,
      MediaControl_Panels,
      index)
{
}


void SamsungDVD1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  LIRCProtocol *lp = new LIRCProtocol(
    guiObject,
    index,
    600, 500,
    600, 1600,
    108000, true);

  threadableProtocol = lp;

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  lp->setHeaderPair(9000, 4500);
  lp->setTrailerPulse(600);
  lp->setRepeatPair(9000, 4500);

  setPreData(0x198133F, 26);

  addKey("power", Power_Key, 0x8976, 16);
  addKey("open_close", Eject_Key, 0x31CE, 16);
  addKey("1", One_Key, 0x817E, 16);
  addKey("2", Two_Key, 0x41BE, 16);
  addKey("3", Three_Key, 0xC13E, 16);
  addKey("4", Four_Key, 0x21DE, 16);
  addKey("5", Five_Key, 0xA15E, 16);
  addKey("6", Six_Key, 0x619E, 16);
  addKey("7", Seven_Key, 0xE11E, 16);
  addKey("8", Eight_Key, 0x11EE, 16);
  addKey("9", Nine_Key, 0x916E, 16);
  addKey("0", Zero_Key, 0x01FE, 16);
  addKey("prog", Program_Key, 0xE51A, 16); // "Mode"
  addKey("clear", Clear_Key, 0x25DA, 16); // "cancel"
  addKey("step", StepForward_Key, 0x659A, 16);
  addKey("replay", Replay_Key, 0x55AA, 16);
  addKey("skip", Advance_Key, 0x758A, 16); // "digest"
  addKey("|<<", Previous_Key, 0xF906, 16); // "skip-"
  addKey(">>|", Next_Key, 0x857A, 16);
  addKey("<<", Rewind_Key, 0x39C6, 16);
  addKey(">>", FastForward_Key, 0x7986, 16);
  addKey("stop", Stop_Key, 0x45BA, 16);
  addKey("play", Play_Key, 0x05FA, 16);
  addKey("play/pause", Pause_Key, 0x05FA, 16);
  addKey("return", Exit_Key, 0xA956, 16);
  addKey("menu", Menu_Key, 0xD12E, 16); // "setup"
  addKey("info", Info_Key, 0xF10E, 16); // "display"
  addKey("disc_menu", DiscMenu_Key, 0x29D6, 16);
  addKey("left", Left_Key, 0x59A6, 16);
  addKey("up", Up_Key, 0xE916, 16);
  addKey("down", Down_Key, 0x19E6, 16);
  addKey("right", Right_Key, 0x9966, 16);
  addKey("enter", Select_Key, 0xD926, 16);
  addKey("ez_view", Unmapped_Key, 0xF50A, 16); // s.fit
  addKey("subtitle", Captions_Key, 0x09F6, 16);
  addKey("audio", Audio_Key, 0x718E, 16);
  addKey("angle", Angle_Key, 0x49B6, 16);
  addKey("repeat", Repeat_Key, 0xB946, 16);
  addKey("repeat_A-B", RepeatAB_Key, 0x15EA, 16);
  addKey("step_r", StepForward_Key, 0xEB14, 16);
  addKey("step_l", StepBack_Key, 0x1BE4, 16);
  addKey("jog_r", Unmapped_Key, 0x936C, 16);
  addKey("jog_l", Unmapped_Key, 0x53AC, 16);
  addKey("sacd/cd", Unmapped_Key, 0x6E91, 16);
  addKey("bookmark", Unmapped_Key, 0x956A, 16);
  addKey("index_pre", Unmapped_Key, 0x837C, 16);
  addKey("index_next", Unmapped_Key, 0x639C, 16);
  addKey("page_pre", PageUp_Key, 0x23DC, 16);
  addKey("page_next", PageDown_Key, 0x639C, 16);
  addKey("zoom", Zoom_Key, 0x35CA, 16);
  addKey("hdmi_sel", Unmapped_Key, 0xE41B, 16);
  addKey("video_sel", Unmapped_Key, 0x44BB, 16);
  addKey("3D_Sound", Surround_Key, 0xD52A, 16);
  addKey("TopMenu", DiscTitle_Key, 0xC936, 16);
}


SamsungDVD1a::SamsungDVD1a(
  unsigned int index)
  : SamsungDVD1(index)
{
  setKeysetName("DVD Keyset 1a");
}


void SamsungDVD1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  SamsungDVD1::populateProtocol(guiObject);

  addKey("hdmi_sel", Unmapped_Key, 0x15EA, 16);
}


SamsungDVD1b::SamsungDVD1b(
  unsigned int index)
  : SamsungDVD1(index)
{
  setKeysetName("DVD Keyset 1b");
}


void SamsungDVD1b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  SamsungDVD1::populateProtocol(guiObject);

  addKey("Zoom", Zoom_Key, 0x55AA, 16);
  addKey("i.replay", Replay_Key, 0xB54A, 16);
  addKey("Volume_Con", Unmapped_Key, 0x35CA, 16);
}


SamsungDVD2::SamsungDVD2(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 2",
      Samsung_Make,
      MediaControl_Panels,
      index)
{
  addControlledDevice(Samsung_Make, "HT-P1200", DVD_Device);
}


void SamsungDVD2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol= new NECXProtocol(guiObject, index, false);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x5343, 16);

  addKey("remain", Unmapped_Key, 0x00, 8);
  addKey("play", Play_Key, 0x03, 8);
  addKey("PLII-MODE", Unmapped_Key, 0x04, 8);
  addKey("ENTER", Select_Key, 0x05, 8);
  addKey("AUDIO", Audio_Key, 0x06, 8);
  addKey("EZ-VIEW", Unmapped_Key, 0x07, 8);
  addKey("TUNER", TunerInput_Key, 0x09, 8);
  addKey("stop", Stop_Key, 0x0B, 8);
  addKey("PLII-EFFECT", Unmapped_Key, 0x0C, 8);
  addKey("UP", Up_Key, 0x0D, 8);
  addKey("SUBTITLE", Captions_Key, 0x0E, 8);
  addKey("ZOOM", Zoom_Key, 0x0F, 8);
  addKey("AUX", AuxInput_Key, 0x11, 8);
  addKey("next", Next_Key, 0x13, 8);
  addKey("SOUND-EDIT", SoundMode_Key, 0x14, 8);
  addKey("DOWN", Down_Key, 0x15, 8);
  addKey("cancel", Unmapped_Key, 0x17, 8);
//  addKey("MODE", Program_Key, 0x18, 8); // Might be wrong
  addKey("TV-VIDEO", Input_Key, 0x18, 8);
  addKey("DVD", DVDInput_Key, 0x19, 8);
  addKey("prev", Previous_Key, 0x1B, 8);
  addKey("RETURN", Exit_Key, 0x1C, 8);
  addKey("RIGHT", Right_Key, 0x1D, 8);
  addKey("SLEEP", Sleep_Key, 0x21, 8);
  addKey("ch+", ChannelUp_Key, 0x23, 8);
  addKey("MUSIC", Unmapped_Key, 0x24, 8);
  addKey("LEFT", Left_Key, 0x25, 8);
  addKey("INFO", Info_Key, 0x26, 8);
  addKey("ch-", ChannelDown_Key, 0x2B, 8);
  addKey("TUNER-MEMORY", Memory_Key, 0x2D, 8);
  addKey("0", Zero_Key, 0x2F, 8);
  addKey("VOL+", VolumeUp_Key, 0x33, 8);
  addKey("TEST-TONE", Unmapped_Key, 0x34, 8);
  addKey("SLOW", Slow_Key, 0x35, 8);
  addKey("MENU", Menu_Key, 0x36, 8);
  addKey("9", Nine_Key, 0x37, 8);
  addKey("LOGO", Unmapped_Key, 0x38, 8);
  addKey("MUTE", Mute_Key, 0x39, 8);
  addKey("VOL-", VolumeDown_Key, 0x3B, 8);
  addKey("STEP", StepForward_Key, 0x3D, 8);
  addKey("8", Eight_Key, 0x3F, 8);
  addKey("1", One_Key, 0x41, 8);
  addKey("2", Two_Key, 0x42, 8);
  addKey("3", Three_Key, 0x43, 8);
  addKey("4", Four_Key, 0x44, 8);
  addKey("5", Five_Key, 0x45, 8);
  addKey("6", Six_Key, 0x46, 8);
  addKey("7", Seven_Key, 0x47, 8);
  addKey("SD-HD", AspectRatio_Key, 0x59, 8);
  addKey("REPEAT", Repeat_Key, 0x66, 8);
  addKey("super5.1", Surround_Key, 0x67, 8);
  addKey("MOVIE", Unmapped_Key, 0x68, 8);
  addKey("ASC", Unmapped_Key, 0x69, 8);
  addKey("HDMI-AUDIO", Unmapped_Key, 0x70, 8);
}


void SamsungDVD2::populateInputList(
  QComboBox *cb) const
{
  cb->clear();

  cb->addItem("Tuner", QVariant(TunerInput_Key));
  cb->addItem("TV / Video", QVariant(Input_Key));
  cb->addItem("DVD", QVariant(DVDInput_Key));
  cb->addItem("Aux", QVariant(AuxInput_Key));
}


SamsungAC1::SamsungAC1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Air Conditioner 1",
      Samsung_Make,
      ACFan_Panels,
      index)
{
}


void SamsungAC1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  LIRCProtocol *lp = new LIRCProtocol(
    guiObject,
    index,
    600, 500,
    600, 1600,
    60000, true);

  threadableProtocol = lp;

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  lp->setHeaderPair(4500, 4500);
  lp->setTrailerPulse(600);

  setPreData(0x804, 12);

//  np->setMinimumRepetitions(1);

  addKey("TIMER", Timer_Key, 0xA4, 8);
  addKey("SLEEP", Sleep_Key, 0xE4, 8);
  addKey("TEMP+", TempUp_Key, 0x4C, 8);
  addKey("TEMP-", TempDown_Key, 0x8C, 8);
  addKey("FAN", Fan_Key, 0x9C, 8);
  addKey("COOL", Cool_Key, 0x3C, 8);
  addKey("HEAT", Heat_Key, 0x5C, 8);
  addKey("FAN_HIGH", FanFaster_Key, 0xEC, 8);
  addKey("FAN_MED", Unmapped_Key, 0x6C, 8);
  addKey("FAN_LOW", FanSlower_Key, 0xAC, 8);
  addKey("SWING", Oscillate_Key, 0x94, 8);
  addKey("POWER", Power_Key, 0xFC, 8);
}


SamsungAC2::SamsungAC2(
  unsigned int index)
  : PIRACKeyset(
      "Air Conditioner 2",
      Samsung_Make,
      index)
{
}


void SamsungAC2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new SamsungACProtocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x201, 12);

  // Bit of a hack:
  addKey("Send Command", ACSendCommand_Key, 0x0, 0);
  addKey("Set Timer", ACSetTimer_Key, 0x0, 0);
}


void SamsungAC2::populateSettingsList(
  PIRACSettings &acSettings) const
{
  resetSettings(acSettings);

  acSettings.push_back(OperatingMode_AC);
  acSettings.push_back(Temperature_AC);
  acSettings.push_back(FanSpeed_AC);
  acSettings.push_back(Turbo_AC);
  acSettings.push_back(Swing_AC);
  acSettings.push_back(AirClean_AC);
}


void SamsungAC2::getTurboModePairs(
  PIRStatePairs &turboModePairs) const
{
  resetPairs(turboModePairs);

  PIRStatePair *normalPair = new PIRStatePair(
    "Normal", 0x21);
  turboModePairs.push_back(normalPair);

  PIRStatePair *turboPair = new PIRStatePair(
    "Turbo", 0x27);
  turboModePairs.push_back(turboPair);

  PIRStatePair *farPair = new PIRStatePair(
    "Far", 0x2D);
  turboModePairs.push_back(farPair);
}

void SamsungAC2::getSwingPairs(
  PIRStatePairs &swingPairs) const
{
  resetPairs(swingPairs);

  PIRStatePair *swingOffPair = new PIRStatePair(
    "Off", 0xFE);
  swingPairs.push_back(swingOffPair);

  PIRStatePair *swingUDPair = new PIRStatePair(
    "Up/Down", 0xAE);
  swingPairs.push_back(swingUDPair);

  PIRStatePair *swingLRPair = new PIRStatePair(
    "Left/Right", 0xBE);
  swingPairs.push_back(swingLRPair);

  PIRStatePair *swingUDLRPair = new PIRStatePair(
    "U/D/L/R", 0xCE);
  swingPairs.push_back(swingUDLRPair);
}

void SamsungAC2::getTemperaturePairs(
  PIRStatePairs &temperaturePairs) const
{
  resetPairs(temperaturePairs);

  PIRStatePair *eighteenPair = new PIRStatePair(
    "18 C", 0x23);
  temperaturePairs.push_back(eighteenPair);

  PIRStatePair *nineteenPair = new PIRStatePair(
    "19 C", 0x33);
  temperaturePairs.push_back(nineteenPair);

  PIRStatePair *twentyPair = new PIRStatePair(
    "20 C", 0x43);
  temperaturePairs.push_back(twentyPair);

  PIRStatePair *twentyonePair = new PIRStatePair(
    "21 C", 0x53);
  temperaturePairs.push_back(twentyonePair);

  PIRStatePair *twentytwoPair = new PIRStatePair(
    "22 C", 0x63);
  temperaturePairs.push_back(twentytwoPair);

  PIRStatePair *twentythreePair = new PIRStatePair(
    "23 C", 0x73);
  temperaturePairs.push_back(twentythreePair);

  PIRStatePair *twentyfourPair = new PIRStatePair(
    "24 C", 0x83);
  temperaturePairs.push_back(twentyfourPair);

  PIRStatePair *twentyfivePair = new PIRStatePair(
    "25 C", 0x93);
  temperaturePairs.push_back(twentyfivePair);

  PIRStatePair *twentysixPair = new PIRStatePair(
    "26 C", 0xA3);
  temperaturePairs.push_back(twentysixPair);

  PIRStatePair *twentysevenPair = new PIRStatePair(
    "27 C", 0xB3);
  temperaturePairs.push_back(twentysevenPair);

  PIRStatePair *twentyeightPair = new PIRStatePair(
    "28 C", 0xC3);
  temperaturePairs.push_back(twentyeightPair);

  PIRStatePair *twentyninePair = new PIRStatePair(
    "29 C", 0xD3);
  temperaturePairs.push_back(twentyninePair);

  PIRStatePair *thirtyPair = new PIRStatePair(
    "30 C", 0xE3);
  temperaturePairs.push_back(thirtyPair);
}


// Only 4 bits for the following!
void SamsungAC2::getFanPairs(
  PIRStatePairs &fanPairs) const
{
  resetPairs(fanPairs);

  PIRStatePair *autoPair = new PIRStatePair(
    "Auto", 0x1);
  fanPairs.push_back(autoPair);

  PIRStatePair *lowPair = new PIRStatePair(
    "Low", 0x5);
  fanPairs.push_back(lowPair);

  PIRStatePair *mediumPair = new PIRStatePair(
    "Medium", 0x9);
  fanPairs.push_back(mediumPair);

  PIRStatePair *highPair = new PIRStatePair(
    "High", 0xB);
  fanPairs.push_back(highPair);
}


void SamsungAC2::getOperatingModePairs(
  PIRStatePairs &modePairs) const
{
  resetPairs(modePairs);

  PIRStatePair *autoPair = new PIRStatePair(
    "Auto", 0x0);
  modePairs.push_back(autoPair);

  PIRStatePair *coolPair = new PIRStatePair(
    "Cool", 0x1);
  modePairs.push_back(coolPair);

  PIRStatePair *dehumidifyPair = new PIRStatePair(
    "Dehumidify", 0x2);
  modePairs.push_back(dehumidifyPair);

  PIRStatePair *fanPair = new PIRStatePair(
    "Fan", 0x3);
  modePairs.push_back(fanPair);
}


void SamsungAC2::getAirCleanPairs(
  PIRStatePairs &aircleanPairs) const
{
  resetPairs(aircleanPairs);

  PIRStatePair *offPair = new PIRStatePair(
    "Off", 0x0);
  aircleanPairs.push_back(offPair);

  PIRStatePair *onPair = new PIRStatePair(
    "On", 0x4);
  aircleanPairs.push_back(onPair);
}


/*
void SamsungAC2::getPowerPairs(
  PIRStatePairs &powerPairs) const
{
  resetPairs(powerPairs);

  PIRStatePair *offPair = new PIRStatePair(
    "Off", 0xE);
  powerPairs.push_back(offPair);

  PIRStatePair *onPair = new PIRStatePair(
    "On", 0xF);
  powerPairs.push_back(onPair);
}
*/


void SamsungAC2::getTimerOptionPairs(
  PIRStatePairs &timerOptionPairs) const
{
  resetPairs(timerOptionPairs);

  PIRStatePair *cancelPair = new PIRStatePair(
    "Cancel Timers", 0x0);
  timerOptionPairs.push_back(cancelPair);

  PIRStatePair *onPair = new PIRStatePair(
    "Set On-Timer", 0x2);
  timerOptionPairs.push_back(onPair);

  PIRStatePair *offPair = new PIRStatePair(
    "Set Off-Timer", 0x4);
  timerOptionPairs.push_back(offPair);
}


SamsungSTB1::SamsungSTB1(
  unsigned int index)
  : PIRKeysetMetaData(
      "STB Keyset 1",
      Samsung_Make,
      TV_Panels,
      index)
{
  addControlledDevice(Samsung_Make, "SMT-1000T", TV_Device);
  addControlledDevice(Samsung_Make, "SMT-1100T", TV_Device);
}


void SamsungSTB1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x4040, 16);

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
  addKey("up", Up_Key, 0x0B, 8);
  addKey("mute", Mute_Key, 0x0C, 8);
  addKey("ok", Select_Key, 0x0D, 8);
  addKey("down", Down_Key, 0x0E, 8);
  addKey("tv/stb", Input_Key, 0x0F, 8);

  addKey("left", Left_Key, 0x10, 8);
  addKey("right", Right_Key, 0x11, 8);
  addKey("clock", Unmapped_Key, 0x12, 8);
  addKey("vol+", VolumeUp_Key, 0x15, 8);
  addKey("red", Red_Key, 0x16, 8);
  addKey("green", Green_Key, 0x17, 8);
  addKey("yellow", Yellow_Key, 0x18, 8);
  addKey("blue", Blue_Key, 0x19, 8);
  addKey("epg", Guide_Key, 0x1A, 8);
  addKey("vol-", VolumeDown_Key, 0x1C, 8);
  addKey("radio", TunerInput_Key, 0x1D, 8);
  addKey("chan-", ChannelDown_Key, 0x1E, 8);
  addKey("chan+", ChannelUp_Key, 0x1F, 8);

  addKey("fav", Favorites_Key, 0x27, 8);

  addKey("menu", Menu_Key, 0x40, 8);
  addKey("exit", Exit_Key, 0x41, 8);
  addKey("i", Info_Key, 0x42, 8);
  addKey("rcl", PrevChannel_Key, 0x43, 8);
  addKey("txt", Teletext_Key, 0x45, 8); // might be wrong
  addKey("a-z", Unmapped_Key, 0x46, 8);
}


void SamsungSTB1::populateInputList(
  QComboBox *cb) const
{
  cb->clear();

  cb->addItem("TV / STB", QVariant(Input_Key));
  cb->addItem("Radio", QVariant(TunerInput_Key));
}


SamsungSTB2::SamsungSTB2(
  unsigned int index)
  : PIRKeysetMetaData(
      "STB Keyset 2",
      Samsung_Make,
      TV_Panels,
      index)
{
}


void SamsungSTB2::populateProtocol(
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

  setPreData(0xF58A, 16);

  addKey("num_0", Zero_Key, 0x00, 8);
  addKey("num_1", One_Key, 0x01, 8);
  addKey("num_2", Two_Key, 0x02, 8);
  addKey("num_3", Three_Key, 0x03, 8);
  addKey("num_4", Four_Key, 0x04, 8);
  addKey("num_5", Five_Key, 0x05, 8);
  addKey("num_6", Six_Key, 0x06, 8);
  addKey("num_7", Seven_Key, 0x07, 8);
  addKey("num_8", Eight_Key, 0x08, 8);
  addKey("num_9", Nine_Key, 0x09, 8);
  addKey("Power", Power_Key, 0x0C, 8);
  addKey("Guide", Guide_Key, 0x0E, 8);
  addKey("Mute", Mute_Key, 0x12, 8);
  addKey("VOL+", VolumeUp_Key, 0x13, 8);
  addKey("VOL-", VolumeDown_Key, 0x14, 8);
  addKey("Menu", Menu_Key, 0x16, 8);
  addKey("CH+", ChannelUp_Key, 0x17, 8);
  addKey("CH-", ChannelDown_Key, 0x18, 8);
  addKey("Last_ch", PrevChannel_Key, 0x19, 8);
  addKey("up_arrow", Up_Key, 0x1A, 8);
  addKey("down_arrow", Down_Key, 0x1B, 8);
  addKey("right_arrow", Right_Key, 0x1C, 8);
  addKey("left_arrow", Left_Key, 0x1D, 8);
  addKey("Select", Select_Key, 0x1F, 8);
  addKey("Info", Info_Key, 0x25, 8);
  addKey("exit", Exit_Key, 0x62, 8);
}


SamsungSTB3::SamsungSTB3(
  unsigned int index)
  : PIRKeysetMetaData(
      "STB Keyset 3",
      Samsung_Make,
      TV_Panels,
      index)
{
}


void SamsungSTB3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECXProtocol(guiObject, index, false);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x1AF2, 16);

  addKey("num_1", One_Key, 0x00, 8);
  addKey("num_2", Two_Key, 0x01, 8);
  addKey("num_3", Three_Key, 0x02, 8);
  addKey("num_4", Four_Key, 0x03, 8);
  addKey("num_5", Five_Key, 0x04, 8);
  addKey("num_6", Six_Key, 0x05, 8);
  addKey("num_7", Seven_Key, 0x06, 8);
  addKey("num_8", Eight_Key, 0x07, 8);
  addKey("num_9", Nine_Key, 0x08, 8);
  addKey("num_0", Zero_Key, 0x09, 8);
  addKey("VOL+", VolumeUp_Key, 0x0A, 8);
  addKey("VOL-", VolumeDown_Key, 0x0B, 8);
  addKey("CH+", ChannelUp_Key, 0x0C, 8);
  addKey("CH-", ChannelDown_Key, 0x0D, 8);
  addKey("up_arrow", Up_Key, 0x10, 8);
  addKey("down_arrow", Down_Key, 0x11, 8);
  addKey("left_arrow", Left_Key, 0x12, 8);
  addKey("right_arrow", Right_Key, 0x13, 8);
  addKey("Select", Select_Key, 0x14, 8);
  addKey("exit", Exit_Key, 0x15, 8);
  addKey("Guide", Guide_Key, 0x1B, 8);
  addKey("Power", Power_Key, 0x1E, 8);
  addKey("Mute", Mute_Key, 0x20, 8);
  addKey("TV/Radio", Input_Key, 0x21, 8);
  addKey("Green", Green_Key, 0x22, 8);
  addKey("Yellow", Yellow_Key, 0x23, 8);
  addKey("Blue", Blue_Key, 0x24, 8);
  addKey("Info", Info_Key, 0x25, 8);
  addKey("Red", Red_Key, 0x26, 8);
  addKey("Media", Unmapped_Key, 0x2B, 8);
  addKey("Last_ch", PrevChannel_Key, 0x2C, 8);
  addKey("Rsolution", Unmapped_Key, 0x2F, 8);
  addKey("Language", Unmapped_Key, 0x31, 8);
  addKey("Display", AspectRatio_Key, 0x32, 8);
  addKey("Option", Unmapped_Key, 0x33, 8);
  addKey("Application", Unmapped_Key, 0x35, 8);
  addKey("Menu", Menu_Key, 0x36, 8);
  addKey("Back", Unmapped_Key, 0x38, 8);
}


SamsungSTB4::SamsungSTB4(
  unsigned int index)
  : PIRKeysetMetaData(
      "STB Keyset 4",
      Samsung_Make,
      TV_Panels | MediaControl_Panels | MediaRecord_Panels,
      index)
{
}


void SamsungSTB4::populateProtocol(
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

  addKey("num_0", Zero_Key, 0x1280, 13);
  addKey("num_1", One_Key, 0x1281, 13);
  addKey("num_2", Two_Key, 0x1282, 13);
  addKey("num_3", Three_Key, 0x1283, 13);
  addKey("num_4", Four_Key, 0x1284, 13);
  addKey("num_5", Five_Key, 0x1285, 13);
  addKey("num_6", Six_Key, 0x1286, 13);
  addKey("num_7", Seven_Key, 0x1287, 13);
  addKey("num_8", Eight_Key, 0x1288, 13);
  addKey("num_9", Nine_Key, 0x1289, 13);
  addKey("Stop", Stop_Key, 0x129D, 13);
  addKey("Menu", Menu_Key, 0x129E, 13);
  addKey("White", Unmapped_Key, 0x129F, 13);
  addKey("CH+", ChannelUp_Key, 0x12A0, 13);
  addKey("CH-", ChannelDown_Key, 0x12A1, 13);
  addKey("Zoom", Zoom_Key, 0x12A2, 13);
  addKey("Info", Info_Key, 0x12AC, 13);
  addKey("Text", Teletext_Key, 0x12AD, 13);
  addKey("Pause", Pause_Key, 0x12B0, 13);
  addKey("rewind", Rewind_Key, 0x12B2, 13);
  addKey("ffwd", FastForward_Key, 0x12B4, 13);
  addKey("Play", Play_Key, 0x12B5, 13);
  addKey("Record", Record_Key, 0x12B7, 13);
  addKey("Enter", Enter_Key, 0x12B9, 13);

  addKey("Page-", PageDown_Key, 0x028B, 13);
  addKey("Page+", PageUp_Key, 0x028C, 13);
  addKey("up_arrow", Up_Key, 0x0290, 13);
  addKey("down_arrow", Down_Key, 0x0291, 13);
  addKey("left_arrow", Left_Key, 0x0295, 13);
  addKey("right_arrow", Right_Key, 0x0296, 13);
  addKey("Select", Select_Key, 0x0297, 13);
  addKey("Power", Power_Key, 0x02A8, 13);
  addKey("Red", Red_Key, 0x02AB, 13);
  addKey("Green", Green_Key, 0x02AC, 13);
  addKey("Yellow", Yellow_Key, 0x02AD, 13);
  addKey("Blue", Blue_Key, 0x02AE, 13);
  addKey("Last_ch", PrevChannel_Key, 0x02AF, 13);
  addKey("Guide", Guide_Key, 0x02B0, 13);
  addKey("Exit", Exit_Key, 0x02B1, 13);
  addKey("Goto Play/Film", Unmapped_Key, 0x02B7, 13);
}


SamsungSTB5::SamsungSTB5(
  unsigned int index)
  : PIRKeysetMetaData(
      "STB Keyset 5",
      Samsung_Make,
      TV_Panels | MediaControl_Panels | MediaRecord_Panels,
      index)
{
}


void SamsungSTB5::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new Nokia32Protocol(guiObject, index);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x2670, 16);
  setPostData(0x26, 7);

  addKey("num_0", Zero_Key, 0x00, 8);
  addKey("num_1", One_Key, 0x01, 8);
  addKey("num_2", Two_Key, 0x02, 8);
  addKey("num_3", Three_Key, 0x03, 8);
  addKey("num_4", Four_Key, 0x04, 8);
  addKey("num_5", Five_Key, 0x05, 8);
  addKey("num_6", Six_Key, 0x06, 8);
  addKey("num_7", Seven_Key, 0x07, 8);
  addKey("num_8", Eight_Key, 0x08, 8);
  addKey("num_9", Nine_Key, 0x09, 8);
  addKey("Power", Power_Key, 0x0C, 8);
  addKey("Mute", Mute_Key, 0x0D, 8);
  addKey("Info", Info_Key, 0x0F, 8);
  addKey("VOL+", VolumeUp_Key, 0x10, 8);
  addKey("VOL-", VolumeDown_Key, 0x11, 8);
  addKey("CH+", ChannelUp_Key, 0x20, 8);
  addKey("CH-", ChannelDown_Key, 0x21, 8);
  addKey("ffwd", FastForward_Key, 0x28, 8);
  addKey("rewind", Rewind_Key, 0x29, 8);
  addKey("Play", Play_Key, 0x2C, 8);
  addKey("Pause", Pause_Key, 0x2C, 8);
  addKey("Stop", Stop_Key, 0x31, 8);
  addKey("Record", Record_Key, 0x37, 8);
  addKey("Teletext", Teletext_Key, 0x3C, 8);
  addKey("TV/Radio", TunerInput_Key, 0x43, 8);
  addKey("Menu", Menu_Key, 0x54, 8);
  addKey("up_arrow", Up_Key, 0x58, 8);
  addKey("down_arrow", Down_Key, 0x59, 8);
  addKey("left_arrow", Left_Key, 0x5A, 8);
  addKey("right_arrow", Right_Key, 0x5B, 8);
  addKey("Select", Select_Key, 0x5C, 8);
  addKey("Red", Red_Key, 0x6D, 8);
  addKey("Green", Green_Key, 0x6E, 8);
  addKey("Yellow", Yellow_Key, 0x6F, 8);
  addKey("Blue", Blue_Key, 0x70, 8);
  addKey("Search", Unmapped_Key, 0x81, 8);
  addKey("Last_ch", PrevChannel_Key, 0x83, 8);
  addKey("TV", AntennaInput_Key, 0xA6, 8);
  addKey("TV/Video", AuxInput_Key, 0xA7, 8);
  addKey("Guide", Guide_Key, 0xCC, 8);
  addKey("Option", Unmapped_Key, 0xDB, 8);
  addKey("exit", Exit_Key, 0xEE, 8);
  addKey("Recordings", Unmapped_Key, 0xF0, 8);
  addKey("Select Video", Unmapped_Key, 0xFD, 8);
}


void SamsungSTB5::populateInputList(
  QComboBox *cb) const
{
  cb->clear();

  cb->addItem("TV", QVariant(AntennaInput_Key));
  cb->addItem("TV / Radio", QVariant(TunerInput_Key));
  cb->addItem("TV / Video", QVariant(AuxInput_Key));
}


SamsungSTB6::SamsungSTB6(
  unsigned int index)
  : PIRKeysetMetaData(
      "STB Keyset 6",
      Samsung_Make,
      TV_Panels,
      index)
{
}


void SamsungSTB6::populateProtocol(
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

  setPreData(0xA8AD, 16);

  addKey("Power", Power_Key, 0xA0, 8);
  addKey("CH+", ChannelUp_Key, 0xA6, 8);
  addKey("CH-", ChannelDown_Key, 0xA7, 8);
  addKey("Page+", PageUp_Key, 0xAA, 8);
  addKey("Page-", PageDown_Key, 0xAB, 8);
  addKey("Guide", Guide_Key, 0xAC, 8);
  addKey("up_arrow", Up_Key, 0xB0, 8);
  addKey("down_arrow", Down_Key, 0xB1, 8);
  addKey("Select", Select_Key, 0xB2, 8);
  addKey("left_arrow", Left_Key, 0xB3, 8);
  addKey("right_arrow", Right_Key, 0xB4, 8);
  addKey("Red", Red_Key, 0xB5, 8);
  addKey("Yellow", Yellow_Key, 0xB6, 8);
  addKey("Green", Green_Key, 0xB7, 8);
  addKey("Blue", Blue_Key, 0xB8, 8);
  addKey("num_1", One_Key, 0xB9, 8);
  addKey("num_2", Two_Key, 0xBA, 8);
  addKey("num_3", Three_Key, 0xBB, 8);
  addKey("num_4", Four_Key, 0xBC, 8);
  addKey("num_5", Five_Key, 0xBD, 8);
  addKey("num_6", Six_Key, 0xBE, 8);
  addKey("num_7", Seven_Key, 0xBF, 8);
  addKey("num_8", Eight_Key, 0xC0, 8);
  addKey("num_9", Nine_Key, 0xC1, 8);
  addKey("num_0", Zero_Key, 0xC2, 8);
  addKey("Backspace", Unmapped_Key, 0xC3, 8);
  addKey("Home", Unmapped_Key, 0xC6, 8);
}
