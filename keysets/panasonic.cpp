//
// panasonic.cpp
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

#include "panasonic.h"
#include "protocols/necprotocol.h"
#include "protocols/panasonicoldprotocol.h"
#include "protocols/panasonicprotocol.h"
#include <QComboBox>


PanasonicCarAudio::PanasonicCarAudio(
  unsigned int index)
  : PIRKeysetMetaData(
      "Car Audio Keyset",
      Panasonic_Make,
      MediaControl_Panels,
      index)
{
}


void PanasonicCarAudio::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, false);

//  setPreData(0x8156, 16);
  setPreData(0x6A81, 16);

  addKey("Power", Power_Key, 0x12, 8);
  addKey("ATT", Unmapped_Key, 0x14, 8);
  addKey("Vol_Down", VolumeDown_Key, 0x19, 8);
  addKey("Mode", SoundMode_Key, 0x1A, 8);
  addKey("PRG", Program_Key, 0x1C, 8);
  addKey("Vol_Up", VolumeUp_Key, 0x1D, 8);
  addKey("Tune/Track_Down", ChannelDown_Key, 0x1E, 8);
  addKey("Tune/Track_Up", ChannelUp_Key, 0x1F, 8);
}


PanasonicSat1::PanasonicSat1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Satellite Keyset 1",
      Panasonic_Make,
      TV_Panels | MediaControl_Panels | MediaRecord_Panels,
      index)
{
}


void PanasonicSat1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new PanasonicProtocol(guiObject, index);

//  setPreData(0x40040140, 32);
  setPreData(0x2002, 16);

  addPanasonicKey("PROG", Program_Key, 0x80, 0x02, 0x8A);
  addPanasonicKey("1", One_Key, 0x80, 0x02, 0xA0);
  addPanasonicKey("2", Two_Key, 0x80, 0x02, 0xA1);
  addPanasonicKey("3", Three_Key, 0x80, 0x02, 0xA2);
  addPanasonicKey("4", Four_Key, 0x80, 0x02, 0xA3);
  addPanasonicKey("5", Five_Key, 0x80, 0x02, 0xA4);
  addPanasonicKey("6", Six_Key, 0x80, 0x02, 0xA5);
  addPanasonicKey("7", Seven_Key, 0x80, 0x02, 0xA6);
  addPanasonicKey("8", Eight_Key, 0x80, 0x02, 0xA7);
  addPanasonicKey("9", Nine_Key, 0x80, 0x02, 0xA8);
  addPanasonicKey("0", Zero_Key, 0x80, 0x02, 0xA9);
  addPanasonicKey("CH-", ChannelDown_Key, 0x80, 0x02, 0xB6);
  addPanasonicKey("CH+", ChannelUp_Key, 0x80, 0x02, 0xB7);
  addPanasonicKey("ALT_AUD", Audio_Key, 0x80, 0x02, 0xB8);
  addPanasonicKey("INFO", Info_Key, 0x80, 0x02, 0xB9);
  addPanasonicKey("TV/DSS", Input_Key, 0x80, 0x02, 0xBC);
  addPanasonicKey("POWER", Power_Key, 0x80, 0x02, 0xBD);
  addPanasonicKey("REC", Record_Key, 0x80, 0x02, 0xC2);
  addPanasonicKey("ACTION", Select_Key, 0x80, 0x02, 0xC3);
  addPanasonicKey("MENU", Menu_Key, 0x80, 0x02, 0xC4);
  addPanasonicKey("GUIDE", Guide_Key, 0x80, 0x02, 0xC5);
  addPanasonicKey("EXIT", Exit_Key, 0x80, 0x02, 0xC6);
  addPanasonicKey("UP", Up_Key, 0x80, 0x02, 0xCA);
  addPanasonicKey("DOWN", Down_Key, 0x80, 0x02, 0xCB);
  addPanasonicKey("LEFT", Left_Key, 0x80, 0x02, 0xCD);
  addPanasonicKey("RIGHT", Right_Key, 0x80, 0x02, 0xCE);
  addPanasonicKey("FAV", Favorites_Key, 0x80, 0x02, 0xD0);
  addPanasonicKey("R_TUNE", PrevChannel_Key, 0x80, 0x02, 0xD1);
  addPanasonicKey("GUIDE", Guide_Key, 0x80, 0x02, 0xD3);
  addPanasonicKey("LOGO_TUNE", Unmapped_Key, 0x80, 0x02, 0xD5);
  addPanasonicKey("TXT", Teletext_Key, 0x80, 0x02, 0xDE);
  addPanasonicKey("STTL", Unmapped_Key, 0x80, 0x02, 0xDF);

  addPanasonicKey("RED", Red_Key, 0x80, 0x02, 0xEC);
  addPanasonicKey("GREEN", Green_Key, 0x80, 0x02, 0xED);
  addPanasonicKey("BLUE", Blue_Key, 0x80, 0x02, 0xEE);
  addPanasonicKey("YELLOW", Yellow_Key, 0x80, 0x02, 0xEF);
}


PanasonicSat1a::PanasonicSat1a(
  unsigned int index)
  : PanasonicSat1(index)
{
  setKeysetName("Satellite Keyset 1a");
}


void PanasonicSat1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  PanasonicSat1::populateProtocol(guiObject);

  addPanasonicKey("EXIT", Exit_Key, 0x80, 0x02, 0xCF);
  addPanasonicKey("CH+", ChannelUp_Key, 0x80, 0x02, 0xB2);
  addPanasonicKey("CH-", ChannelDown_Key, 0x80, 0x02, 0xB3);
}


PanasonicTV1::PanasonicTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Panasonic_Make,
      TV_Panels,
      index)
{
  addControlledDevice(Panasonic_Make, "TX-32PD50", TV_Device);
}


void PanasonicTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new PanasonicProtocol(guiObject, index);

  setPreData(0x2002, 16);

  addPanasonicKey("Video 1", VideoInput_Key, 0x80, 0x00, 0x01);
  addPanasonicKey("Video 2", Video2Input_Key, 0x80, 0x00, 0x02);
  addPanasonicKey("Video 3", Video3Input_Key, 0x80, 0x00, 0x03); // hack
  addPanasonicKey("Video 4", Video4Input_Key, 0x80, 0x00, 0x04); // hack
  addPanasonicKey("TV/AV", Input_Key, 0x80, 0x00, 0x05);
  addPanasonicKey("N", Unmapped_Key, 0x80, 0x00, 0x0C); // "normal"
  addPanasonicKey("S", Unmapped_Key, 0x80, 0x00, 0x0E);
  addPanasonicKey("TIMER", Sleep_Key, 0x80, 0x00, 0x0F); // "Sleep"
  addPanasonicKey("1", One_Key, 0x80, 0x00, 0x10);
  addPanasonicKey("2", Two_Key, 0x80, 0x00, 0x11);
  addPanasonicKey("3", Three_Key, 0x80, 0x00, 0x12);
  addPanasonicKey("4", Four_Key, 0x80, 0x00, 0x13);
  addPanasonicKey("5", Five_Key, 0x80, 0x00, 0x14);
  addPanasonicKey("6", Six_Key, 0x80, 0x00, 0x15);
  addPanasonicKey("7", Seven_Key, 0x80, 0x00, 0x16);
  addPanasonicKey("8", Eight_Key, 0x80, 0x00, 0x17);
  addPanasonicKey("9", Nine_Key, 0x80, 0x00, 0x18);
  addPanasonicKey("0", Zero_Key, 0x80, 0x00, 0x19);
  addPanasonicKey("enter", Enter_Key, 0x80, 0x00, 0x1B);
  addPanasonicKey("VOLUME_UP", VolumeUp_Key, 0x80, 0x00, 0x20);
  addPanasonicKey("VOLUME_DOWN", VolumeDown_Key, 0x80, 0x00, 0x21);
  addPanasonicKey("SURROUND", Surround_Key, 0x80, 0x00, 0x31);
  addPanasonicKey("MUTE", Mute_Key, 0x80, 0x00, 0x32);
  addPanasonicKey("SAP", Audio_Key, 0x80, 0x00, 0x33); // "Stereo/Mono/Bilingual"
  addPanasonicKey("PROG_UP", ChannelUp_Key, 0x80, 0x00, 0x34);
  addPanasonicKey("PROG_DOWN", ChannelDown_Key, 0x80, 0x00, 0x35);
  addPanasonicKey("Last", PrevChannel_Key, 0x80, 0x00, 0x37); // r-tune
  addPanasonicKey("PIP SCAN", PIPScan_Key, 0x80, 0x00, 0x38); // "pip search"
  addPanasonicKey("Info", Info_Key, 0x80, 0x00, 0x39); // "OSD", "recall"
  addPanasonicKey("C", Clear_Key, 0x80, 0x00, 0x3A);
  addPanasonicKey("-/--", DoubleDigit_Key, 0x80, 0x00, 0x3B);
  addPanasonicKey("POWER", Power_Key, 0x80, 0x00, 0x3D);
  addPanasonicKey("On", PowerOn_Key, 0x80, 0x00, 0x3E);
  addPanasonicKey("Off", PowerOff_Key, 0x80, 0x00, 0x3F);
  addPanasonicKey("select", Select_Key, 0x80, 0x00, 0x49); // "OK"
  addPanasonicKey("UP", Up_Key, 0x80, 0x00, 0x4A);
  addPanasonicKey("DOWN", Down_Key, 0x80, 0x00, 0x4B);
  addPanasonicKey("LEFT", Left_Key, 0x80, 0x00, 0x4E);
  addPanasonicKey("RIGHT", Right_Key, 0x80, 0x00, 0x4F);
  addPanasonicKey("P_MENU", PictureMode_Key, 0x80, 0x00, 0x50);
  addPanasonicKey("S_MENU", SoundMode_Key, 0x80, 0x00, 0x51);
  addPanasonicKey("setup", Menu_Key, 0x80, 0x00, 0x52); // "ACTION", "Menu"
//  addPanasonicKey("pip", PIP_Key, 0x80, 0x00, 0x56); // This seems bad
  addPanasonicKey("pip size", PIPSize_Key, 0x80, 0x00, 0x5B); // "split/size pip"
  addPanasonicKey("PIP FREEZE", PIPPause_Key, 0x80, 0x00, 0x5C);
  addPanasonicKey("pip", PIP_Key, 0x80, 0x00, 0x5D);
  addPanasonicKey("pip swap", PIPSwap_Key, 0x80, 0x00, 0x5E);
//  addPanasonicKey("freeze", PIPPause_Key, 0x80, 0x00, 0x63); //??
  addPanasonicKey("PIP +", PIPChannelUp_Key, 0x80, 0x00, 0x65);
  addPanasonicKey("PIP -", PIPChannelDown_Key, 0x80, 0x00, 0x66);
  addPanasonicKey("pip move", PIPMove_Key, 0x80, 0x00, 0x67);
  addPanasonicKey("Tuning", Unmapped_Key, 0x80, 0x00, 0x6C);
  addPanasonicKey("RED", Red_Key, 0x80, 0x00, 0x70);
  addPanasonicKey("GREEN", Green_Key, 0x80, 0x00, 0x71);
  addPanasonicKey("YELLOW", Yellow_Key, 0x80, 0x00, 0x72);
  addPanasonicKey("BLUE", Blue_Key, 0x80, 0x00, 0x73);
  addPanasonicKey("PC/VGA", PCInput_Key, 0x80, 0x00, 0x7A);
  addPanasonicKey("guide", Guide_Key, 0x80, 0x00, 0x87);
  addPanasonicKey("CC", Captions_Key, 0x80, 0x00, 0x9D);
  addPanasonicKey("MOOD_LIGHT", Unmapped_Key, 0x80, 0x00, 0xA1);
  addPanasonicKey("Sub Menu", Unmapped_Key, 0x80, 0x00, 0xA7);
  addPanasonicKey("SD Card", SDCardInput_Key, 0x80, 0x00, 0xAB);
  addPanasonicKey("HELP", Unmapped_Key, 0x80, 0x00, 0xAC);
  addPanasonicKey("Favorite", Favorites_Key, 0x80, 0x00, 0xAE);
  addPanasonicKey("Viera Link", Unmapped_Key, 0x80, 0x00, 0xB1);
  addPanasonicKey("GAME", Unmapped_Key, 0x80, 0x00, 0xBB); // "rh split"
  addPanasonicKey("-", Dash_Key, 0x80, 0x00, 0xD0);
  addPanasonicKey("Exit", Exit_Key, 0x80, 0x00, 0xD3);
  addPanasonicKey("Return", Unmapped_Key, 0x80, 0x00, 0xD4); // "R"
  addPanasonicKey("STR", Unmapped_Key, 0x80, 0x00, 0xD5);
  addPanasonicKey("Format", Unmapped_Key, 0x80, 0x00, 0xDE); // "aspect ratio"
  addPanasonicKey("MULTIWINDOW", Unmapped_Key, 0x80, 0x00, 0xE6); // "multi pip"
  addPanasonicKey("FM/TV", Unmapped_Key, 0x80, 0x00, 0xEE);
  addPanasonicKey("Viera Tools", ServiceMenu_Key, 0x80, 0x00, 0xEF);
  addPanasonicKey("Enable remote", Unmapped_Key, 0x80, 0x00, 0xFB);
  addPanasonicKey("Disable remote", Unmapped_Key, 0x80, 0x00, 0xFC);
  addPanasonicKey("System reset", FactoryReset_Key, 0x80, 0x00, 0xFF);

  addPanasonicKey("InputTv", AntennaInput_Key, 0x80, 0x02, 0x30);

  addPanasonicKey("Component 1", ComponentInput_Key, 0x80, 0x04, 0x7C);
  addPanasonicKey("Component 2", Component2Input_Key, 0x80, 0x04, 0x7D);
  addPanasonicKey("HDMI 1", HDMIInput_Key, 0x80, 0x04, 0xB0);
  addPanasonicKey("HDMI 2", HDMI2Input_Key, 0x80, 0x04, 0xB1);
  addPanasonicKey("HDMI 3", HDMI3Input_Key, 0x80, 0x04, 0xB2);
  addPanasonicKey("HDMI 4", HDMI4Input_Key, 0x80, 0x04, 0xB3);
/* The discrete aspect commands are confusing:
  addPanasonicKey("aspect - normal", Unmapped_Key, 0x80, 0x04, 0xC7);
  addPanasonicKey("aspect - zoom", Unmapped_Key, 0x80, 0x04, 0xC9);
  addPanasonicKey("aspect - just", Unmapped_Key, 0x80, 0x04, 0xCB);
  addPanasonicKey("aspect - auto", Unmapped_Key, 0x80, 0x04, 0xCC);
  addPanasonicKey("aspect - full", Unmapped_Key, 0x80, 0x04, 0xD1);
  addPanasonicKey("aspect - zoom", Unmapped_Key, 0x80, 0x04, 0xDC);
  addPanasonicKey("aspect - full", Unmapped_Key, 0x80, 0x04, 0xDD);
*/
  addPanasonicKey("ASPECT", AspectRatio_Key, 0x80, 0x04, 0xDE);
}


void PanasonicTV1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("Antenna", QVariant(AntennaInput_Key));
  cb->addItem("Video 1", QVariant(VideoInput_Key));
  cb->addItem("Video 2", QVariant(Video2Input_Key));
  cb->addItem("Video 3", QVariant(Video3Input_Key));
  cb->addItem("Video 4", QVariant(Video4Input_Key));
  cb->addItem("Component 1", QVariant(ComponentInput_Key));
  cb->addItem("Component 2", QVariant(Component2Input_Key));
  cb->addItem("HDMI 1", QVariant(HDMIInput_Key));
  cb->addItem("HDMI 2", QVariant(HDMI2Input_Key));
  cb->addItem("HDMI 3", QVariant(HDMI3Input_Key));
  cb->addItem("HDMI 4", QVariant(HDMI4Input_Key));
  cb->addItem("PC / VGA", QVariant(PCInput_Key));
  cb->addItem("SD Card", QVariant(SDCardInput_Key));
}


PanasonicTV1a::PanasonicTV1a(
  unsigned int index)
  : PanasonicTV1(index)
{
  setKeysetName("TV Keyset 1a");
}


void PanasonicTV1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  PanasonicTV1::populateProtocol(guiObject);

  // Overwrite some of the keys:
  addPanasonicKey("Guide", Unmapped_Key, 0x80, 0x09, 0x87);
  addPanasonicKey("DIRECTREC", Unmapped_Key, 0x80, 0x09, 0x89);
  addPanasonicKey("Apps", Unmapped_Key, 0x80, 0x09, 0x8F);
  addPanasonicKey("Viera Cast", Unmapped_Key, 0x80, 0x09, 0x93);
  addPanasonicKey("Home", Unmapped_Key, 0x80, 0x09, 0x95);
  addPanasonicKey("Exit", Exit_Key, 0x80, 0x09, 0x9A);
  addPanasonicKey("Option", Unmapped_Key, 0x80, 0x09, 0xA7); // "Sub Menu"
  addPanasonicKey("Pip max", Unmapped_Key, 0x80, 0x09, 0xA9);
  addPanasonicKey("Pip min", Unmapped_Key, 0x80, 0x09, 0xAA);
  addPanasonicKey("SDCard", SDCardInput_Key, 0x80, 0x09, 0xAB);
  addPanasonicKey("Favorite", Favorites_Key, 0x80, 0x09, 0xAE);
  addPanasonicKey("Link", Unmapped_Key, 0x80, 0x09, 0xB1); // "EZSync"
  addPanasonicKey("3d", Unmapped_Key, 0x80, 0x09, 0xB7);
  addPanasonicKey("prog-", Dash_Key, 0x80, 0x09, 0xD0); // "Dash-(#)"
  addPanasonicKey("Netflix", Unmapped_Key, 0x80, 0x09, 0xF2);
}


PanasonicTV1b::PanasonicTV1b(
  unsigned int index)
  : PanasonicTV1(index)
{
  setKeysetName("TV Keyset 1b");
}


void PanasonicTV1b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated:
    return;
  }

  PanasonicTV1::populateProtocol(guiObject);

  addPanasonicKey("PICTURE", PictureMode_Key, 0x80, 0x00, 0x06);
  addPanasonicKey("SOUND", SoundMode_Key, 0x80, 0x00, 0x07);
//  addPanasonicKey("Right arrow", Right_Key, 0x80, 0x00, 0x08); //??
//  addPanasonicKey("Left arrow", Right_Key, 0x80, 0x00, 0x09); //??
  addPanasonicKey("Picture Noise Reduction", Unmapped_Key, 0x80, 0x00, 0x0A);
  addPanasonicKey("Bass Up", BassUp_Key, 0x80, 0x00, 0x22);
  addPanasonicKey("Bass Down", BassDown_Key, 0x80, 0x00, 0x23);
  addPanasonicKey("Treble Up", TrebleUp_Key, 0x80, 0x00, 0x24);
  addPanasonicKey("Treble Down", TrebleDown_Key, 0x80, 0x00, 0x25);
  addPanasonicKey("Balance Left", BalanceLeft_Key, 0x80, 0x00, 0x26);
  addPanasonicKey("Balance Right", BalanceRight_Key, 0x80, 0x00, 0x27);
  addPanasonicKey("Color Up", ColorUp_Key, 0x80, 0x00, 0x40);
  addPanasonicKey("Color Down", ColorDown_Key, 0x80, 0x00, 0x41);
  addPanasonicKey("Contrast Up", ContrastUp_Key, 0x80, 0x00, 0x42);
  addPanasonicKey("Contrast Down", ContrastDown_Key, 0x80, 0x00, 0x43);
  addPanasonicKey("Brightness Up", BrightnessUp_Key, 0x80, 0x00, 0x44);
  addPanasonicKey("Brightness Down", BrightnessDown_Key, 0x80, 0x00, 0x45);

  addPanasonicKey("Mix", TeletextAndTV_Key, 0x80, 0x01, 0x01);
  addPanasonicKey("TV/TEXT", Teletext_Key, 0x80, 0x01, 0x03);
  addPanasonicKey("Display_Cancel", Unmapped_Key, 0x80, 0x01, 0x04);
  addPanasonicKey("FP (Favorite Page)", Unmapped_Key, 0x80, 0x01, 0x05);
  addPanasonicKey("INDEX", TeletextIndex_Key, 0x80, 0x01, 0x08);
  addPanasonicKey("HOLD", TeletextHold_Key, 0x80, 0x01, 0x09);
  addPanasonicKey("List Store", TeletextStore_Key, 0x80, 0x01, 0x0A);
  addPanasonicKey("TIMETEXT", TeletextTime_Key, 0x80, 0x01, 0x0B);
  addPanasonicKey("FTB (Full/Top/Bottom)", TeletextSize_Key, 0x80, 0x01, 0x0C);
  addPanasonicKey("REVEAL", TeletextReveal_Key, 0x80, 0x01, 0x1C);
  addPanasonicKey("List/F.Text", Unmapped_Key, 0x80, 0x01, 0x1D);
  addPanasonicKey("Text Reset", Unmapped_Key, 0x80, 0x01, 0x1E);
}


PanasonicTV2::PanasonicTV2(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 2",
      Panasonic_Make,
      TV_Panels,
      index)
{
}


void PanasonicTV2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new PanasonicOldProtocol(guiObject, index);

  addPanOldKey("Mute", Mute_Key, 0x00, 0x00);
  addPanOldKey("R-Tune", Unmapped_Key, 0x00, 0x0A);
  addPanOldKey("Sleep", Sleep_Key, 0x00, 0x0B);
  addPanOldKey("TV/Video", Input_Key, 0x00, 0x0D);
  addPanOldKey("Recall", PrevChannel_Key, 0x00, 0x0F);

  addPanOldKey("ONE", One_Key, 0x00, 0x10);
  addPanOldKey("TWO", Two_Key, 0x00, 0x11);
  addPanOldKey("THREE", Three_Key, 0x00, 0x12);
  addPanOldKey("FOUR", Four_Key, 0x00, 0x13);
  addPanOldKey("FIVE", Five_Key, 0x00, 0x14);
  addPanOldKey("SIX", Six_Key, 0x00, 0x15);
  addPanOldKey("SEVEN", Seven_Key, 0x00, 0x16);
  addPanOldKey("EIGHT", Eight_Key, 0x00, 0x17);
  addPanOldKey("NINE", Nine_Key, 0x00, 0x18);
  addPanOldKey("ZERO", Zero_Key, 0x00, 0x19);

  addPanOldKey("skip", Unmapped_Key, 0x00, 0x1F);
  addPanOldKey("POWER", Power_Key, 0x00, 0x20);
  addPanOldKey("CHANNEL_UP", ChannelUp_Key, 0x00, 0x22); // "NEXT"
  addPanOldKey("CHANNEL_DOWN", ChannelDown_Key, 0x00, 0x23); // "PREV"
  addPanOldKey("VOLUME_UP", VolumeUp_Key, 0x00, 0x24);
  addPanOldKey("VOLUME_DOWN", VolumeDown_Key, 0x00, 0x25);

  addPanOldKey("norm", Unmapped_Key, 0x00, 0x36);
  addPanOldKey("setup", Menu_Key, 0x00, 0x3B);

  addPanOldKey("on timer", Timer_Key, 0x0E, 0x23);
  addPanOldKey("video", CompositeInput_Key, 0x0E, 0x25);
}


PanasonicTV2a::PanasonicTV2a(
  unsigned int index)
  : PanasonicTV2(index)
{
  setKeysetName("TV Keyset 2a");
}


void PanasonicTV2a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  PanasonicTV2::populateProtocol(guiObject);

  addPanOldKey("VOL_UP", VolumeUp_Key, 0x00, 0x01);
  addPanOldKey("MUTE", Mute_Key, 0x00, 0x0B);
  addPanOldKey("VOL_DOWN", VolumeDown_Key, 0x00, 0x0D);
  addPanOldKey("PLAYLIST_CLEAR", Unmapped_Key, 0x00, 0x1A);
  addPanOldKey("STOP", Stop_Key, 0x00, 0x1B);
  addPanOldKey("QUIT", Unmapped_Key, 0x00, 0x20);
  addPanOldKey("PAUSE", Pause_Key, 0x00, 0x2A);
  addPanOldKey("BAL_LEFT", BalanceLeft_Key, 0x00, 0x24);
  addPanOldKey("BAL_RIGHT", BalanceRight_Key, 0x00, 0x25);
  addPanOldKey("PLAYLIST_ADD", Unmapped_Key, 0x00, 0x36);
  addPanOldKey("PLAY", Play_Key, 0x00, 0x3A);
  addPanOldKey("BWD", Rewind_Key, 0x00, 0x3B);
  addPanOldKey("FWD", FastForward_Key, 0x00, 0x3C);
}


PanasonicVCR1::PanasonicVCR1(
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      Panasonic_Make,
      MediaControl_Panels | MediaRecord_Panels,
      index)
{
}


void PanasonicVCR1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new PanasonicProtocol(guiObject, index);

//  setPreData(0x400409, 24);
  setPreData(0x2002, 16);

  addPanasonicKey("STOP", Stop_Key, 0x90, 0x00, 0x00);
  addPanasonicKey("REWIND", Rewind_Key, 0x90, 0x00, 0x02);
  addPanasonicKey("FORWARD", FastForward_Key, 0x90, 0x00, 0x03);
  addPanasonicKey("PAUSE", Pause_Key, 0x90, 0x00, 0x06);
  addPanasonicKey("REC", Record_Key, 0x90, 0x00, 0x08);
  addPanasonicKey("PLAY", Play_Key, 0x90, 0x00, 0x0A);
  addPanasonicKey("STILL", StepForward_Key, 0x90, 0x00, 0x0C);  // also "ADV"
  addPanasonicKey("SLOW", Slow_Key, 0x90, 0x00, 0x0F);
  addPanasonicKey("1", One_Key, 0x90, 0x00, 0x10);
  addPanasonicKey("2", Two_Key, 0x90, 0x00, 0x11);
  addPanasonicKey("3", Three_Key, 0x90, 0x00, 0x12);
  addPanasonicKey("4", Four_Key, 0x90, 0x00, 0x13);
  addPanasonicKey("5", Five_Key, 0x90, 0x00, 0x14);
  addPanasonicKey("6", Six_Key, 0x90, 0x00, 0x15);
  addPanasonicKey("7", Seven_Key, 0x90, 0x00, 0x16);
  addPanasonicKey("8", Eight_Key, 0x90, 0x00, 0x17);
  addPanasonicKey("9", Nine_Key, 0x90, 0x00, 0x18);
  addPanasonicKey("0", Zero_Key, 0x90, 0x00, 0x19);
  addPanasonicKey("AUDIO", Audio_Key, 0x90, 0x00, 0x33);
  addPanasonicKey("PROGRAMME^", ChannelUp_Key, 0x90, 0x00, 0x34);
  addPanasonicKey("PROGRAMMEv", ChannelDown_Key, 0x90, 0x00, 0x35);
  addPanasonicKey("TV-SAT", Input_Key, 0x90, 0x00, 0x36);
  addPanasonicKey("INFO", Info_Key, 0x90, 0x00, 0x39);
  addPanasonicKey("-/--", DoubleDigit_Key, 0x90, 0x00, 0x3B);
  addPanasonicKey("POWER", Power_Key, 0x90, 0x00, 0x3D);
  addPanasonicKey("INDEX", IndexSearch_Key, 0x90, 0x00, 0x40);
  addPanasonicKey("time_search", Unmapped_Key, 0x90, 0x00, 0x44);
  addPanasonicKey("INDEXL", Previous_Key, 0x90, 0x00, 0x49);
  addPanasonicKey("INDEXR", Next_Key, 0x90, 0x00, 0x4A);
  addPanasonicKey("mem_rep", Unmapped_Key, 0x90, 0x00, 0x53);
  addPanasonicKey("COUNTER_RESET", Unmapped_Key, 0x90, 0x00, 0x54);
  addPanasonicKey("TAPE_REMAIN", Unmapped_Key, 0x90, 0x00, 0x55);
  addPanasonicKey("CLOCK/COUNTER", Clock_Key, 0x90, 0x00, 0x56);
  addPanasonicKey("+", Unmapped_Key, 0x90, 0x00, 0x8E);
  addPanasonicKey("-", Unmapped_Key, 0x90, 0x00, 0x8F);
  addPanasonicKey("monitor", Unmapped_Key, 0x90, 0x00, 0x91);
  addPanasonicKey("TRACKING_AUTO", AutoTracking_Key, 0x90, 0x00, 0xB0);
  addPanasonicKey("TRACKING_PLUS", TrackingPlus_Key, 0x90, 0x00, 0xB1);
  addPanasonicKey("TRACKING_MINUS", TrackingMinus_Key, 0x90, 0x00, 0xB2);
  addPanasonicKey("TIMERREC", RecordTimed_Key, 0x90, 0x00, 0xB4);
  addPanasonicKey("AV", Unmapped_Key, 0x90, 0x00, 0xC0);
  addPanasonicKey("DIRECT_TV_REC", Unmapped_Key, 0x90, 0x00, 0xC2);
  addPanasonicKey("mesecam", Unmapped_Key, 0x90, 0x00, 0xC9);
  addPanasonicKey("100", PlusOneHundred_Key, 0x90, 0x00, 0xE5);
  addPanasonicKey("sap/hi-fi", Unmapped_Key, 0x90, 0x00, 0xE6);
  addPanasonicKey("repeat", Repeat_Key, 0x90, 0x00, 0xF0);
  addPanasonicKey("memory", Program_Key, 0x90, 0x00, 0xF1);
  addPanasonicKey("sleep", Sleep_Key, 0x90, 0x00, 0xF2);
  addPanasonicKey("rew2", Unmapped_Key, 0x90, 0x00, 0xF3);
  addPanasonicKey("zerostop", Unmapped_Key, 0x90, 0x00, 0xF5);
  addPanasonicKey("REPLAY", Replay_Key, 0x90, 0x00, 0xF7);
  addPanasonicKey("cm-zero", Unmapped_Key, 0x90, 0x00, 0xF8);

  addPanasonicKey("PROG/CHECK", Program_Key, 0x90, 0x01, 0x01);
  addPanasonicKey("rotate", Unmapped_Key, 0x90, 0x01, 0x02);
  addPanasonicKey("rotatedown", Unmapped_Key, 0x90, 0x01, 0x03);
  addPanasonicKey("set", Unmapped_Key, 0x90, 0x01, 0x04);
  addPanasonicKey("clear", Unmapped_Key, 0x90, 0x01, 0x05);
  addPanasonicKey("VPS/PDC", RecordPDC_Key, 0x90, 0x01, 0x06);
  addPanasonicKey("OffTimer", Sleep_Key, 0x90, 0x01, 0x08);
  addPanasonicKey("CANCEL", Clear_Key, 0x90, 0x01, 0x09);
  addPanasonicKey("SPEED", VHSSpeed_Key, 0x90, 0x01, 0x0A);
  addPanasonicKey("ADD/DELETE", Unmapped_Key, 0x90, 0x01, 0x31);
  addPanasonicKey("RADIO_TUNE", Unmapped_Key, 0x90, 0x01, 0x38);
  addPanasonicKey("MENU", Menu_Key, 0x90, 0x01, 0x56);
  addPanasonicKey("OK", Select_Key, 0x90, 0x01, 0x58);
  addPanasonicKey("SHOWVIEW", Unmapped_Key, 0x90, 0x01, 0x5D); // vhsplus+, etc.
  addPanasonicKey("DISPLAY", Unmapped_Key, 0x90, 0x01, 0x5F);
  addPanasonicKey("EXIT", Exit_Key, 0x90, 0x01, 0x66);
  addPanasonicKey("CHECK+", Unmapped_Key, 0x90, 0x01, 0x90);
  addPanasonicKey("CHECK-", Unmapped_Key, 0x90, 0x01, 0x91);
  addPanasonicKey("DATE+", Unmapped_Key, 0x90, 0x01, 0x92);
  addPanasonicKey("DATE-", Unmapped_Key, 0x90, 0x01, 0x93);
  addPanasonicKey("ON+", Unmapped_Key, 0x90, 0x01, 0x94);
  addPanasonicKey("ON-", Unmapped_Key, 0x90, 0x01, 0x95);
  addPanasonicKey("OFF+", Unmapped_Key, 0x90, 0x01, 0x96);
  addPanasonicKey("OFF-", Unmapped_Key, 0x90, 0x01, 0x97);
  addPanasonicKey("SEARCH", Unmapped_Key, 0x90, 0x01, 0x9D);
  addPanasonicKey("TAPE", Unmapped_Key, 0x90, 0x01, 0xE0);

  addPanasonicKey("STILL_ALBUM", Unmapped_Key, 0x90, 0x05, 0x23);
  addPanasonicKey("PROG_PLAY", Unmapped_Key, 0x90, 0x05, 0x3A);
  addPanasonicKey("I-Timer", Unmapped_Key, 0x90, 0x05, 0x3F);
  addPanasonicKey("TV/TEXT", Unmapped_Key, 0x90, 0x05, 0x57);
  addPanasonicKey("ExtLink", Unmapped_Key, 0x90, 0x05, 0x5B);

// These are fishy:
//  addPanasonicKey("RESET_STORE", Unmapped_Key, 0x90, 0x01, 0x58);
}


PanasonicVCR1a::PanasonicVCR1a(
  unsigned int index)
  : PanasonicVCR1(index)
{
  setKeysetName("VCR Keyset 1a");
}


void PanasonicVCR1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  PanasonicVCR1::populateProtocol(guiObject);

  addPanasonicKey("OSD", Info_Key, 0x90, 0x00, 0x57);
  addPanasonicKey("AV", Input_Key, 0x90, 0x00, 0xC0);
  addPanasonicKey("DISPLAY", Unmapped_Key, 0x90, 0x01, 0x5F);
}


PanasonicVCR1b::PanasonicVCR1b(
  unsigned int index)
  : PanasonicVCR1(index)
{
  setKeysetName("VCR Keyset 1b");
}


void PanasonicVCR1b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  PanasonicVCR1::populateProtocol(guiObject);

  addPanasonicKey("repeat", Repeat_Key, 0x90, 0x00, 0xF9);
  addPanasonicKey("prog", Program_Key, 0x90, 0x00, 0xFF);
  addPanasonicKey("clear", Clear_Key, 0x90, 0x01, 0x0A);
}


PanasonicVCR1c::PanasonicVCR1c(
  unsigned int index)
  : PanasonicVCR1(index)
{
  setKeysetName("VCR Keyset 1c");
}


void PanasonicVCR1c::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  PanasonicVCR1::populateProtocol(guiObject);

  addPanasonicKey("rotate", Up_Key, 0x90, 0x01, 0x02);
  addPanasonicKey("rotatedown", Down_Key, 0x90, 0x01, 0x03);
  addPanasonicKey("set", Select_Key, 0x90, 0x01, 0x04);
  addPanasonicKey("clear", Exit_Key, 0x90, 0x01, 0x05);
}


PanasonicVCR2::PanasonicVCR2(
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 2",
      Panasonic_Make,
      MediaControl_Panels | MediaRecord_Panels,
      index)
{
}


void PanasonicVCR2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new PanasonicOldProtocol(guiObject, index);

  addPanOldKey("STOP", Stop_Key, 0x02, 0x00);
  addPanOldKey("REW", Rewind_Key, 0x02, 0x02);
  addPanOldKey("FF", FastForward_Key, 0x02, 0x03);
  addPanOldKey("PAUSE", Pause_Key, 0x02, 0x06);
  addPanOldKey("REC", Record_Key, 0x02, 0x08);
  addPanOldKey("PLAY", Play_Key, 0x02, 0x0A);
  addPanOldKey("REV_PLAY", Unmapped_Key, 0x02, 0x0B);
  addPanOldKey("F.ADV", StepForward_Key, 0x02, 0x0C);
  addPanOldKey("x2", PlayX2_Key, 0x02, 0x0E);
  addPanOldKey("SLOW", Slow_Key, 0x02, 0x0F);
  addPanOldKey("1", One_Key, 0x02, 0x10);
  addPanOldKey("2", Two_Key, 0x02, 0x11);
  addPanOldKey("3", Three_Key, 0x02, 0x12);
  addPanOldKey("4", Four_Key, 0x02, 0x13);
  addPanOldKey("5", Five_Key, 0x02, 0x14);
  addPanOldKey("6", Six_Key, 0x02, 0x15);
  addPanOldKey("7", Seven_Key, 0x02, 0x16);
  addPanOldKey("8", Eight_Key, 0x02, 0x17);
  addPanOldKey("9", Nine_Key, 0x02, 0x18);
  addPanOldKey("0", Zero_Key, 0x02, 0x19);
  addPanOldKey("POWER", Power_Key, 0x02, 0x20); // "vtr"
  addPanOldKey("VOL+", VolumeUp_Key, 0x02, 0x22);
  addPanOldKey("VOL-", VolumeDown_Key, 0x02, 0x23);
  addPanOldKey("-/--", DoubleDigit_Key, 0x02, 0x24);
  addPanOldKey("VTR/TV", Input_Key, 0x02, 0x2A);
  addPanOldKey("slow+", SlowPlus_Key, 0x02, 0x2E);
  addPanOldKey("slow-", SlowMinus_Key, 0x02, 0x2F);
  addPanOldKey("MEMORY_SEARCH", Memory_Key, 0x02, 0x32);
  addPanOldKey("RESET_INDEX", Reset_Key, 0x02, 0x33);
  addPanOldKey("INTRO_SCAN", Unmapped_Key, 0x02, 0x34);
  addPanOldKey("timer_rec", RecordTimed_Key, 0x02, 0x36);
  addPanOldKey("AUDIO-SELECT", Audio_Key, 0x02, 0x3D);

  addPanOldKey("VPS", RecordPDC_Key, 0x03, 0x06);
  addPanOldKey("prog", Program_Key, 0x03, 0x2C);
  addPanOldKey("next", Next_Key, 0x03, 0x3A);

  addPanOldKey("FSTORE", Unmapped_Key, 0x19, 0x10);
  addPanOldKey("STROBE", Unmapped_Key, 0x19, 0x11);
  addPanOldKey("CLEAR", Unmapped_Key, 0x19, 0x12);
  addPanOldKey("GEFFECT", Unmapped_Key, 0x19, 0x17);
  addPanOldKey("MINUS", ChannelDown_Key, 0x19, 0x19); //?
  addPanOldKey("PLUS", ChannelUp_Key, 0x19, 0x24); //?
}


PanasonicDVD1::PanasonicDVD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Panasonic_Make,
      MediaControl_Panels,
      index)
{
}


void PanasonicDVD1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new PanasonicProtocol(guiObject, index);

//  setPreData(0x40040D00, 32);
  setPreData(0x2002, 16);

  addPanasonicKey("STOP", Stop_Key, 0xB0, 0x00, 0x00);
  addPanasonicKey("OPEN/CLOSE", Eject_Key, 0xB0, 0x00, 0x01);
//  addPanasonicKey("TV-SAT", Input_Key, 0xB0, 0x00, 0x01);
  addPanasonicKey("REW", Rewind_Key, 0xB0, 0x00, 0x04);
  addPanasonicKey("FF", FastForward_Key, 0xB0, 0x00, 0x05);
  addPanasonicKey("PAUSE", Pause_Key, 0xB0, 0x00, 0x06);
  addPanasonicKey("CH_DOWN", ChannelDown_Key, 0xB0, 0x00, 0x07);
  addPanasonicKey("rec", Record_Key, 0xB0, 0x00, 0x08);
  addPanasonicKey("PLAY", Play_Key, 0xB0, 0x00, 0x0A);
  addPanasonicKey("CH_UP", ChannelUp_Key, 0xB0, 0x00, 0x0F);
  addPanasonicKey("1", One_Key, 0xB0, 0x00, 0x10);
  addPanasonicKey("2", Two_Key, 0xB0, 0x00, 0x11);
  addPanasonicKey("3", Three_Key, 0xB0, 0x00, 0x12);
  addPanasonicKey("4", Four_Key, 0xB0, 0x00, 0x13);
  addPanasonicKey("5", Five_Key, 0xB0, 0x00, 0x14);
  addPanasonicKey("6", Six_Key, 0xB0, 0x00, 0x15);
  addPanasonicKey("7", Seven_Key, 0xB0, 0x00, 0x16);
  addPanasonicKey("8", Eight_Key, 0xB0, 0x00, 0x17);
  addPanasonicKey("9", Nine_Key, 0xB0, 0x00, 0x18);
  addPanasonicKey("0", Zero_Key, 0xB0, 0x00, 0x19);
  addPanasonicKey("extlink", Unmapped_Key, 0xB0, 0x00, 0x23);
  addPanasonicKey("AUDIO", Audio_Key, 0xB0, 0x00, 0x33);
  addPanasonicKey("POWER", Power_Key, 0xB0, 0x00, 0x3D);
  addPanasonicKey("erase", Unmapped_Key, 0xB0, 0x00, 0x44); // "DELETE"
  addPanasonicKey("POSITION_MEMORY", Unmapped_Key, 0xB0, 0x00, 0x46);
  addPanasonicKey("A-B_REPEAT", RepeatAB_Key, 0xB0, 0x00, 0x48);
  addPanasonicKey("PREV", Previous_Key, 0xB0, 0x00, 0x49);
  addPanasonicKey("NEXT", Next_Key, 0xB0, 0x00, 0x04A);
  addPanasonicKey("timeslip", Unmapped_Key, 0xB0, 0x00, 0x4B);
  addPanasonicKey("manualskip", Unmapped_Key, 0xB0, 0x00, 0x4C);
  addPanasonicKey("RANDOM", Random_Key, 0xB0, 0x00, 0x4D);
  addPanasonicKey("recmode", Unmapped_Key, 0xB0, 0x00, 0x51);
  addPanasonicKey("functions", Unmapped_Key, 0xB0, 0x00, 0x57);
  addPanasonicKey("createchapter", Unmapped_Key, 0xB0, 0x00, 0x58);
  addPanasonicKey("status", Unmapped_Key, 0xB0, 0x00, 0x5F);
  addPanasonicKey("VOLUMEDOWN", VolumeDown_Key, 0xB0, 0x00, 0x62);
  addPanasonicKey("VOLUMEUP", VolumeUp_Key, 0xB0, 0x00, 0x63);
  addPanasonicKey("i", Unmapped_Key, 0xB0, 0x00, 0x66);
  addPanasonicKey("timer", Timer_Key, 0xB0, 0x00, 0x78);
  addPanasonicKey("progcheck", Unmapped_Key, 0xB0, 0x00, 0x7C);
  addPanasonicKey("showview", Unmapped_Key, 0xB0, 0x00, 0x7F);
  addPanasonicKey("MENU", Menu_Key, 0xB0, 0x00, 0x80);
  addPanasonicKey("RETURN", Exit_Key, 0xB0, 0x00, 0x81);
  addPanasonicKey("ACTION", Select_Key, 0xB0, 0x00, 0x82);
  addPanasonicKey("CANCEL", Clear_Key, 0xB0, 0x00, 0x83);
  addPanasonicKey("UP", Up_Key, 0xB0, 0x00, 0x85);
  addPanasonicKey("DOWN", Down_Key, 0xB0, 0x00, 0x86);
  addPanasonicKey("LEFT", Left_Key, 0xB0, 0x00, 0x87);
  addPanasonicKey("RIGHT", Right_Key, 0xB0, 0x00, 0x88);
  addPanasonicKey("+10", DoubleDigit_Key, 0xB0, 0x00, 0x89);
//  addPanasonicKey("inputselect", Input_Key, 0xB0, 0x00, 0x89); // odd!
  addPanasonicKey("PROGRAM", Program_Key, 0xB0, 0x00, 0x8A);
  addPanasonicKey("QUICK_REPLAY", Replay_Key, 0xB0, 0x00, 0x8B);
  addPanasonicKey("REPEAT", Repeat_Key, 0xB0, 0x00, 0x8C);
  addPanasonicKey("PLAY_MODE", Unmapped_Key, 0xB0, 0x00, 0x8D);
  addPanasonicKey("ANGLE", Angle_Key, 0xB0, 0x00, 0x90);
  addPanasonicKey("SUBTITLE", Captions_Key, 0xB0, 0x00, 0x91);
  addPanasonicKey("INFO", Info_Key, 0xB0, 0x00, 0x92);
  addPanasonicKey("SETUP", Unmapped_Key, 0xB0, 0x00, 0x94);
//  addPanasonicKey("R-TUNE", PrevChannel_Key, 0xB0, 0x00, 0x9B);
  addPanasonicKey("TOP_MENU", DiscTitle_Key, 0xB0, 0x00, 0x9B);
  addPanasonicKey("A.SRD", Unmapped_Key, 0xB0, 0x00, 0x9E);
  addPanasonicKey("FL_SELECT", Unmapped_Key, 0xB0, 0x00, 0xB6);
  addPanasonicKey("DISC", Unmapped_Key, 0xB0, 0x00, 0xB7);
  addPanasonicKey("SEQUENTIAL", Unmapped_Key, 0xB0, 0x00, 0xBF);
  addPanasonicKey("CINEMA", Unmapped_Key, 0xB0, 0x00, 0xC0);
  addPanasonicKey("ZOOM", Zoom_Key, 0xB0, 0x00, 0xC1);
  addPanasonicKey("frec", Unmapped_Key, 0xB0, 0x00, 0xC7);
  addPanasonicKey("BASS", EnhancedBass_Key, 0xB0, 0x00, 0xD4);
  addPanasonicKey("D.ENH", Unmapped_Key, 0xB0, 0x00, 0xD5);
  addPanasonicKey("ONETOUCH_MEMORY", Unmapped_Key, 0xB0, 0x00, 0xD6);
  addPanasonicKey("GROUP", Unmapped_Key, 0xB0, 0x00, 0xE0);
  addPanasonicKey("SLEEP", Sleep_Key, 0xB0, 0x00, 0xEB);
}


PanasonicDVD1a::PanasonicDVD1a(
  unsigned int index)
  : PanasonicDVD1(index)
{
  setKeysetName("DVD Keyset 1a");
}


void PanasonicDVD1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  PanasonicDVD1::populateProtocol(guiObject);

  addPanasonicKey("channel2up", ChannelUp_Key, 0xB0, 0x00, 0x34);
  addPanasonicKey("channel2down", ChannelDown_Key, 0xB0, 0x00, 0x35);
  addPanasonicKey("INPUT_SELECT", Input_Key, 0xB0, 0x00, 0x50);
}


PanasonicAudio1::PanasonicAudio1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 1",
      Panasonic_Make,
      Receiver_Panels | MediaRecord_Panels,
      index)
{
  addControlledDevice(Panasonic_Make, "RX-DS25", Audio_Device);
  addControlledDevice(Panasonic_Make, "RX-e300", Audio_Device);
}


void PanasonicAudio1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new PanasonicProtocol(guiObject, index);

//  setPreData(0x40040543, 32);
  setPreData(0x2002, 16);

  addPanasonicKey("INTRO", Unmapped_Key, 0xA0, 0xC2, 0x46); // odd

  addPanasonicKey("stop-clear", Stop_Key, 0xA0, 0xC2, 0x80);
  addPanasonicKey("repeat", Repeat_Key, 0xA0, 0xC2, 0x81);
  addPanasonicKey("random", Random_Key, 0xA0, 0xC2, 0x82);
  addPanasonicKey("eject", Eject_Key, 0xA0, 0xC2, 0x8E);
  addPanasonicKey("prev", Rewind_Key, 0xA0, 0xC2, 0x84); // "CD_<<"
  addPanasonicKey("next", FastForward_Key, 0xA0, 0xC2, 0x85); // "CD_>>"
  addPanasonicKey("CD_PAUSE", Pause_Key, 0xA0, 0xC2, 0x86);
  addPanasonicKey("play-pause", Play_Key, 0xA0, 0xC2, 0x87);
  addPanasonicKey("program", Program_Key, 0xA0, 0xC2, 0x8B); // "MEMORY"
  addPanasonicKey("cancel", Clear_Key, 0xA0, 0xC2, 0x8D);
  addPanasonicKey("display", Info_Key, 0xA0, 0xC2, 0x8F);

  addPanasonicKey("1", One_Key, 0xA0, 0xC2, 0x90);
  addPanasonicKey("2", Two_Key, 0xA0, 0xC2, 0x91);
  addPanasonicKey("3", Three_Key, 0xA0, 0xC2, 0x92);
  addPanasonicKey("4", Four_Key, 0xA0, 0xC2, 0x93);
  addPanasonicKey("5", Five_Key, 0xA0, 0xC2, 0x94);
  addPanasonicKey("6", Six_Key, 0xA0, 0xC2, 0x95);
  addPanasonicKey("7", Seven_Key, 0xA0, 0xC2, 0x96);
  addPanasonicKey("8", Eight_Key, 0xA0, 0xC2, 0x97);
  addPanasonicKey("9", Nine_Key, 0xA0, 0xC2, 0x98);
  addPanasonicKey("10/0", Zero_Key, 0xA0, 0xC2, 0x99);
  addPanasonicKey("+10", DoubleDigit_Key, 0xA0, 0xC2, 0x9F);

  addPanasonicKey("tape_stop", Unmapped_Key, 0xA0, 0xC2, 0xA0);
  addPanasonicKey("rew", Unmapped_Key, 0xA0, 0xC2, 0xA2); // "TAPE_<<"
  addPanasonicKey("ff", Unmapped_Key, 0xA0, 0xC2, 0xA3); // "TAPE_>>"
  addPanasonicKey("tape_record", Record_Key, 0xA0, 0xC2, 0xA4);
  addPanasonicKey("TAPE_PLAY_REWIND", Unmapped_Key, 0xA0, 0xC2, 0xA5);
  addPanasonicKey("tape_play", Unmapped_Key, 0xA0, 0xC2, 0xA6); // "TAPE_PLAY_FORWARD"
  addPanasonicKey("tape", TapeInput_Key, 0xA0, 0xC2, 0xAC);
  addPanasonicKey("TAPE_DECK", Unmapped_Key, 0xA0, 0xC2, 0xAD);
  addPanasonicKey("rev_mode", Unmapped_Key, 0xA0, 0xC2, 0xAE); // "TAPE_REV_MODE"
  addPanasonicKey("counter_reset", Reset_Key, 0xA0, 0xC2, 0xAF);

  addPanasonicKey("vol+", VolumeUp_Key, 0xA0, 0xC2, 0xB0);
  addPanasonicKey("vol-", VolumeDown_Key, 0xA0, 0xC2, 0xB1);
  addPanasonicKey("cd", CDInput_Key, 0xA0, 0xC2A, 0xB6);
  addPanasonicKey("tuner-band", TunerInput_Key, 0xA0, 0xC2, 0xB8);
  addPanasonicKey("sleep", Sleep_Key, 0xA0, 0xC2, 0xBC);
  addPanasonicKey("power", Power_Key, 0xA0, 0xC2, 0xBF);

  addPanasonicKey("TRACK>>", Unmapped_Key, 0xA0, 0xC2, 0xD0);
  addPanasonicKey("TRACK<<", Unmapped_Key, 0xA0, 0xC2, 0xD1);
  addPanasonicKey("xbs", Unmapped_Key, 0xA0, 0xC2, 0xD6);
  addPanasonicKey("preset_eq", Unmapped_Key, 0xA0, 0xC2, 0xD9);
  addPanasonicKey("virtualizer", Unmapped_Key, 0xA0, 0xC2, 0xDA); // "S.VIRT"

  addPanasonicKey("fm-mode", FMMode_Key, 0xA0, 0xC2, 0xE4); // "st-mono"
  addPanasonicKey("TUNER_PRESET_TUNE_UP", NextPreset_Key, 0xA0, 0xC2, 0xE7);
  addPanasonicKey("TUNER_PRESET_TUNE_UP", Next_Key, 0xA0, 0xC2, 0xE7);
  addPanasonicKey("TUNER_PRESET_TUNE_DOWN", PrevPreset_Key, 0xA0, 0xC2, 0xE8);
  addPanasonicKey("TUNER_PRESET_TUNE_DOWN", Previous_Key, 0xA0, 0xC2A, 0xE8);
  addPanasonicKey("tuning+", ChannelUp_Key, 0xA0, 0xC2, 0xE9);
  addPanasonicKey("tuning-", ChannelDown_Key, 0xA0, 0xC2, 0xEA);
  addPanasonicKey("AUTOSCAN", Scan_Key, 0xA0, 0xC2, 0xEC);
  addPanasonicKey("bp", Unmapped_Key, 0xA0, 0xC2, 0xEF); // "TUNER_BP", beat-proof?

  addPanasonicKey("panelopen", Unmapped_Key, 0xA0, 0xC2, 0xF4);  // "TOP_PANEL_OPEN"
  addPanasonicKey("panelclose", Unmapped_Key, 0xA0, 0xC2, 0xF5); // "TOP_PANEL_CLOSE"
}


void PanasonicAudio1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("Tuner Band", QVariant(TunerInput_Key));
  cb->addItem("CD", QVariant(CDInput_Key));
  cb->addItem("Tape", QVariant(TapeInput_Key));
}


PanasonicAudio2::PanasonicAudio2(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 2",
      Panasonic_Make,
      Receiver_Panels | MediaRecord_Panels,
      index)
{
}


void PanasonicAudio2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new PanasonicProtocol(guiObject, index);

  setPreData(0x2002, 16);

  addPanasonicKey("Volume_Up", VolumeUp_Key, 0xA0, 0x00, 0x20);
  addPanasonicKey("Volume_Down", VolumeDown_Key, 0xA0, 0x00, 0x21);
  addPanasonicKey("Mute", Mute_Key, 0xA0, 0x00, 0x32);
  addPanasonicKey("INPUT:AUX", LineInput_Key, 0xA0, 0x00, 0x9A); // hack
  addPanasonicKey("Super_Woofer", Unmapped_Key, 0xA0, 0x00, 0xC2);

  addPanasonicKey("tuner", TunerInput_Key, 0xA0, 0x04, 0xA4);

  addPanasonicKey("tape", TapeInput_Key, 0xA0, 0x08, 0x96);
  addPanasonicKey("INPUT: TAPE Play", Unmapped_Key, 0xA0, 0x08, 0x9E);

  addPanasonicKey("repeat", Repeat_Key, 0xA0, 0x0A, 0x47);
  addPanasonicKey("random", Random_Key, 0xA0, 0x0A, 0x4D);
  addPanasonicKey("program", Program_Key, 0xA0, 0x0A, 0x8A);
//  addPanasonicKey("cd", CDInput_Key, 0xA0, 0x00, 0x94);
//  addPanasonicKey("aux", AuxInput_Key, 0xA0, 0x00, 0x9A);
  addPanasonicKey("cancel", Clear_Key, 0xA0, 0x0A, 0xA3);
  addPanasonicKey("Disc", NextDisc_Key, 0xA0, 0x0A, 0xA4);  // ???

  addPanasonicKey("Eq", Unmapped_Key, 0xA0, 0x10, 0x83); // "Preset EQ"

  addPanasonicKey("S.Sound EQ", Unmapped_Key, 0xA0, 0x12, 0xC5);

  addPanasonicKey("Stop", Stop_Key, 0xA0, 0x1C, 0x00);
  addPanasonicKey("Play_Reverse", Unmapped_Key, 0xA0, 0x1C, 0x06);
  addPanasonicKey("Play/Pause", Play_Key, 0xA0, 0x1C, 0x0A);
  addPanasonicKey("Play/Pause", Pause_Key, 0xA0, 0x1C, 0x0A);
  addPanasonicKey("1", One_Key, 0xA0, 0x1C, 0x10);
  addPanasonicKey("2", Two_Key, 0xA0, 0x1C, 0x11);
  addPanasonicKey("3", Three_Key, 0xA0, 0x1C, 0x12);
  addPanasonicKey("4", Four_Key, 0xA0, 0x1C, 0x13);
  addPanasonicKey("5", Five_Key, 0xA0, 0x1C, 0x14);
  addPanasonicKey("6", Six_Key, 0xA0, 0x1C, 0x15);
  addPanasonicKey("7", Seven_Key, 0xA0, 0x1C, 0x16);
  addPanasonicKey("8", Eight_Key, 0xA0, 0x1C, 0x17);
  addPanasonicKey("9", Nine_Key, 0xA0, 0x1C, 0x18);
  addPanasonicKey("0", Zero_Key, 0xA0, 0x1C, 0x19);
  addPanasonicKey("Power", Power_Key, 0xA0, 0x1C, 0x3D);
  addPanasonicKey("discrete on", PowerOn_Key, 0xA0, 0x1C, 0x3E);
  addPanasonicKey("discrete off", PowerOff_Key, 0xA0, 0x1C, 0x3F);
  addPanasonicKey("Back", Previous_Key, 0xA0, 0x1C, 0x49);
  addPanasonicKey("Forward", Next_Key, 0xA0, 0x1C, 0x4A);
  addPanasonicKey("Display", Info_Key, 0xA0, 0x1C, 0x55);
  addPanasonicKey(">10", DoubleDigit_Key, 0xA0, 0x1C, 0x84);
  addPanasonicKey("clock/timer", Timer_Key, 0xA0, 0x1C, 0x95);
  addPanasonicKey("Sleep", Sleep_Key, 0xA0, 0x1C, 0x96);
  addPanasonicKey("Dimmer", Unmapped_Key, 0xA0, 0x1C, 0x97);
  addPanasonicKey("play/record timer", Unmapped_Key, 0xA0, 0x1C, 0x9B);
  addPanasonicKey("play mode", Mode_Key, 0xA0, 0x1C, 0xBB);
}


void PanasonicAudio2::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("Tuner", QVariant(TunerInput_Key));
  cb->addItem("CD", QVariant(CDInput_Key));
  cb->addItem("Tape", QVariant(TapeInput_Key));
  cb->addItem("Aux", QVariant(AuxInput_Key));
  cb->addItem("Aux (alt)", QVariant(LineInput_Key));
}


PanasonicAudio2a::PanasonicAudio2a(
  unsigned int index)
  : PanasonicAudio2(index)
{
  setKeysetName("Audio Keyset 2a");
}


void PanasonicAudio2a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  PanasonicAudio2::populateProtocol(guiObject);

//  addPanasonicKey("INPUT: CD play/pause", CDInput_Key, 0x0AA, 0x0A);
  addPanasonicKey("INPUT: CD play/pause", Play_Key, 0xA0, 0x0A, 0x0A);
  addPanasonicKey("INPUT: CD play/pause", Pause_Key, 0xA0, 0x0A, 0x0A);
}


PanasonicAudio3::PanasonicAudio3(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 3",
      Panasonic_Make,
      Receiver_Panels | MediaRecord_Panels,
      index)
{
}


void PanasonicAudio3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new PanasonicOldProtocol(guiObject, index);

  addPanOldKey("audio_power", Power_Key, 0x09, 0x20);
  addPanOldKey("audio_phono", PhonoInput_Key, 0x09, 0x0C);
  addPanOldKey("vol-", VolumeDown_Key, 0x09, 0x25);
  addPanOldKey("vol+", VolumeUp_Key, 0x09, 0x24);
  addPanOldKey("audio_video", CompositeInput_Key, 0x09, 0x2E);
  addPanOldKey("audio_tape", TapeInput_Key, 0x09, 0x0A);
  addPanOldKey("tuner-", ChannelDown_Key, 0x09, 0x23);
  addPanOldKey("tuner+", ChannelUp_Key, 0x09, 0x22);
  addPanOldKey("cd_skip-", Previous_Key, 0x0C, 0x02);
  addPanOldKey("cd_skip+", Next_Key, 0x0C, 0x03);
  addPanOldKey("cd_stop", Stop_Key, 0x0C, 0x00);
  addPanOldKey("cd_play", Play_Key, 0x0C, 0x0A);
  addPanOldKey("vcr_power", Unmapped_Key, 0x02, 0x20);
  addPanOldKey("vcr_stop", Unmapped_Key, 0x02, 0x00);
  addPanOldKey("vcr_ch-", Unmapped_Key, 0x02, 0x23);
  addPanOldKey("vcr_ch+", Unmapped_Key, 0x02, 0x22);
  addPanOldKey("tv_vcr", Input_Key, 0x02, 0x2A);
  addPanOldKey("vcr_pause", Unmapped_Key, 0x02, 0x06);
  addPanOldKey("vcr_rec", Unmapped_Key, 0x02, 0x08);
  addPanOldKey("tv_power", Unmapped_Key, 0x00, 0x20);
  addPanOldKey("vcr_play", Unmapped_Key, 0x02, 0x0A);
  addPanOldKey("vcr_rew", Unmapped_Key, 0x02, 0x02);
  addPanOldKey("vcr_ff", Unmapped_Key, 0x02, 0x03);
  addPanOldKey("tv_video", Input_Key, 0x00, 0x0D);
  addPanOldKey("tv_ant", AntennaInput_Key, 0x00, 0x2A);
  addPanOldKey("tv_ch-", Unmapped_Key, 0x00, 0x23);
  addPanOldKey("tv_ch+", Unmapped_Key, 0x00, 0x22);
}


void PanasonicAudio3::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("Video", QVariant(CompositeInput_Key));
  cb->addItem("Phono", QVariant(PhonoInput_Key));
  cb->addItem("Tape", QVariant(TapeInput_Key));
  cb->addItem("TV / VCR", QVariant(VCRInput_Key));
  cb->addItem("TV / Video", QVariant(Input_Key));
  cb->addItem("TV / Ant", QVariant(AntennaInput_Key));
}


PanasonicAC1::PanasonicAC1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Air Conditioner 1",
      Panasonic_Make,
      ACFan_Panels,
      index)
{
}


void PanasonicAC1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x6681, 16);

  addKey("Operation", Power_Key, 0x81, 8);
  addKey("Economy", EnergySave_Key, 0x82, 8);
  addKey("Air Swing", Oscillate_Key, 0x83, 8);
  addKey("Temp Up", TempUp_Key, 0x85, 8);
  addKey("Temp Down", TempDown_Key, 0x8A, 8);
  addKey("Fan Speed", FanFaster_Key, 0x99, 8);
  addKey("Mode", Mode_Key, 0x9B, 8);
  addKey("Timer", Timer_Key, 0x9F, 8);
}

// A stateful Panasonic A/C!

/*
PanasonicAC2::PanasonicAC2(
  unsigned int index)
  : PIRACKeyset(
      "Air Conditioner 2",
      Panasonic_Make,
      index)
{
}


void PanasonicAC2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new SamsungACProtocol(guiObject, index); // fix
}


void PanasonicAC2::getTurboModePairs(
  PIRStatePairs &turboModePairs) const
{
  resetPairs(turboModePairs);

  PIRStatePair *normalPair = new PIRStatePair(
    "Power", 0x
}
*/
