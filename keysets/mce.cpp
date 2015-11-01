//
// mce.cpp
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

#include "mce.h"
#include "protocols/mceprotocol.h"
#include <QComboBox>


MCERemote1::MCERemote1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Windows MCE Remote 1",
      Microsoft_Make,
      TV_Panels | MediaControl_Panels | MediaRecord_Panels,
      index)
{
  addControlledDevice(Microsoft_Make, "Windows PC ASRock HT330", Computer_Device);
}


void MCERemote1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new MCEProtocol(guiObject, index, 0x800F);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x04, 7);

  addKey("Zero", Zero_Key, 0x00, 8);
  addKey("One", One_Key, 0x01, 8);
  addKey("Two", Two_Key, 0x02, 8);
  addKey("Three", Three_Key, 0x03, 8);
  addKey("Four", Four_Key, 0x04, 8);
  addKey("Five", Five_Key, 0x05, 8);
  addKey("Six", Six_Key, 0x06, 8);
  addKey("Seven", Seven_Key, 0x07, 8);
  addKey("Eight", Eight_Key, 0x08, 8);
  addKey("Nine", Nine_Key, 0x09, 8);
  addKey("Clear", Clear_Key, 0x0A, 8);
  addKey("Enter", Enter_Key, 0x0B, 8);

  addKey("Power", Power_Key, 0x0C, 8);
  addKey("Home", Menu_Key, 0x0D, 8);
  addKey("Mute", Mute_Key, 0x0E, 8);
  addKey("MoreInfo", Info_Key, 0x0F, 8);
  addKey("VolUp", VolumeUp_Key, 0x10, 8);
  addKey("VolDown", VolumeDown_Key, 0x11, 8);
  addKey("ChanUp", ChannelUp_Key, 0x12, 8);
  addKey("ChanDown", ChannelDown_Key, 0x13, 8);

  addKey("Forward", FastForward_Key, 0x14, 8);
  addKey("Rewind", Rewind_Key, 0x15, 8);
  addKey("Play", Play_Key, 0x16, 8);
  addKey("Record", Record_Key, 0x17, 8);
  addKey("Pause", Pause_Key, 0x18, 8);
  addKey("Stop", Stop_Key, 0x19, 8);
  addKey("Skip", Advance_Key, 0x1A, 8); // next?
  addKey("Replay", Replay_Key, 0x1B, 8); // previous?

  addKey("Hash", Unmapped_Key, 0x1C, 8); // "Caps Lock"
  addKey("Star", Unmapped_Key, 0x1D, 8); // "Mouse"

  addKey("Up", Up_Key, 0x1E, 8);
  addKey("Down", Down_Key, 0x1F, 8);
  addKey("Left", Left_Key, 0x20, 8);
  addKey("Right", Right_Key, 0x21, 8);
  addKey("OK", Select_Key, 0x22, 8);
  addKey("Back", Exit_Key, 0x23, 8);
  addKey("DVD", DiscMenu_Key, 0x24, 8);
  addKey("LiveTV", LiveTV_Key, 0x25, 8);
  addKey("Guide", Guide_Key, 0x26, 8);

  addKey("Aspect", AspectRatio_Key, 0x27, 8);

  addKey("Visualization", Unmapped_Key, 0x32, 8);
  addKey("SlideShow", Unmapped_Key, 0x33, 8);
  addKey("Eject", Eject_Key, 0x34, 8);

  addKey("TV", AntennaInput_Key, 0x46, 8); // "My TV"
  addKey("Music", CDInput_Key, 0x47, 8); // "My Music"
  addKey("RecTV", HDDInput_Key, 0x48, 8); // "Recorded TV"
  addKey("Pictures", PhonoInput_Key, 0x49, 8); // "My Pictures"
  addKey("Videos", VCRInput_Key, 0x4A, 8); // "My Videos"
  addKey("DVD angle", Angle_Key, 0x4B, 8);
  addKey("DVD audio", Audio_Key, 0x4C, 8);
  addKey("DVD subtitle", Captions_Key, 0x4D, 8);
  addKey("Print", Unmapped_Key, 0x4E, 8);

  addKey("Radio", TunerInput_Key, 0x50, 8);
  addKey("title", DiscTitle_Key, 0x51, 8);
  addKey("Teletext", Teletext_Key, 0x5A, 8);
  addKey("Red", Red_Key, 0x5B, 8);
  addKey("Green", Green_Key, 0x5C, 8);
  addKey("Yellow", Yellow_Key, 0x5D, 8);
  addKey("Blue", Blue_Key, 0x5E, 8);

//  addKey("PlayPause", Play_Key, 0x6E, 8);
//  addKey("PlayPause", Pause_Key, 0x6E, 8);

  addKey("Media", Unmapped_Key, 0x80, 8); // "Write"
}


void MCERemote1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("TV", QVariant(AntennaInput_Key));
  cb->addItem("Radio", QVariant(TunerInput_Key));
  cb->addItem("Recorded TV", QVariant(HDDInput_Key));
  cb->addItem("Music", QVariant(CDInput_Key));
  cb->addItem("Pictures", QVariant(PhonoInput_Key));
  cb->addItem("Videos", QVariant(VCRInput_Key));
}


MCERemote1a::MCERemote1a(
  unsigned int index)
  : MCERemote1(index)
{
  setKeysetName("Windows MCE Remote 2");
}


void MCERemote1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  MCERemote1::populateProtocol(guiObject);

  setPreData(0x14, 7);
}


MCERemote1b::MCERemote1b(
  unsigned int index)
  : MCERemote1(index)
{
  setKeysetName("Windows MCE Remote 3");
}


void MCERemote1b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  MCERemote1::populateProtocol(guiObject);

  setPreData(0x24, 7);
}


MCERemote1c::MCERemote1c(
  unsigned int index)
  : MCERemote1(index)
{
  setKeysetName("Windows MCE Remote 4");
}


void MCERemote1c::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  MCERemote1::populateProtocol(guiObject);

  setPreData(0x34, 7);
}


MCERemote1d::MCERemote1d(
  unsigned int index)
  : MCERemote1(index)
{
  setKeysetName("Windows MCE Remote 5");
}


void MCERemote1d::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  MCERemote1::populateProtocol(guiObject);

  setPreData(0x44, 7);
}


MCERemote1e::MCERemote1e(
  unsigned int index)
  : MCERemote1(index)
{
  setKeysetName("Windows MCE Remote 6");
}


void MCERemote1e::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  MCERemote1::populateProtocol(guiObject);

  setPreData(0x54, 7);
}


MCERemote1f::MCERemote1f(
  unsigned int index)
  : MCERemote1(index)
{
  setKeysetName("Windows MCE Remote 7");
}


void MCERemote1f::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  MCERemote1::populateProtocol(guiObject);

  setPreData(0x64, 7);
}


MCERemote1g::MCERemote1g(
  unsigned int index)
  : MCERemote1(index)
{
  setKeysetName("Windows MCE Remote 8");
}


void MCERemote1g::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  MCERemote1::populateProtocol(guiObject);

  setPreData(0x74, 7);
}


MCEXboxRemote1::MCEXboxRemote1(
  unsigned int index)
  : MCERemote1g(index)
{
  setKeysetName("XBox 360 Remote 1");
}


void MCEXboxRemote1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  MCERemote1g::populateProtocol(guiObject);

  addKey("A", Green_Key, 0x12, 8);
  addKey("X", Blue_Key, 0x13, 8);
  addKey("B", Red_Key, 0x25, 8);
  addKey("Y", Yellow_Key, 0x26, 8);
}
