//
// logitech.cpp
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

#include "logitech.h"
#include "protocols/necprotocol.h"
#include <QComboBox>


LogitechSpeakers::LogitechSpeakers(
  unsigned int index)
  : PIRKeysetMetaData(
      "Digital Speakers Keyset",
      Logitech_Make,
      MediaControl_Panels,
      index)
{
}


void LogitechSpeakers::populateProtocol(
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

  setPreData(0x08, 8);

  addKey("surround+", RearVolumeUp_Key, 0x00, 8);
  addKey("sub-", WooferDown_Key, 0x01, 8);
  addKey("center+", CenterVolumeUp_Key, 0x02, 8);
  addKey("sub+", WooferUp_Key, 0x03, 8);
  addKey("surround-", RearVolumeDown_Key, 0x04, 8);
  addKey("test", Unmapped_Key, 0x05, 8);
  addKey("center-", CenterVolumeDown_Key, 0x06, 8);
  addKey("direct", PCInput_Key, 0x0A, 8);
  addKey("direct", One_Key, 0x0A, 8);
  addKey("optical", OpticalInput_Key, 0x0B, 8);
  addKey("optical", Two_Key, 0x0B, 8);
  addKey("coax", DigitalCoaxInput_Key, 0x0C, 8);
  addKey("coax", Three_Key, 0x0C, 8);
  addKey("vol-", VolumeDown_Key, 0x0E, 8);
  addKey("power", Power_Key, 0x10, 8);
  addKey("mute", Mute_Key, 0x16, 8);
  addKey("effect", Red_Key, 0x1D, 8);
  addKey("settings", Blue_Key, 0x1F, 8);
  addKey("vol+", VolumeUp_Key, 0x1A, 8);
}


void LogitechSpeakers::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("Direct", QVariant(PCInput_Key));
  cb->addItem("Optical", QVariant(OpticalInput_Key));
  cb->addItem("Coax", QVariant(DigitalCoaxInput_Key));
}


LogitechSqueezebox::LogitechSqueezebox(
  unsigned int index)
  : PIRKeysetMetaData(
      "Squeezebox Keyset",
      Logitech_Make,
      MediaControl_Panels,
      index)
{
  addControlledDevice(Logitech_Make, "Squeezebox 2", Audio_Device);
  addControlledDevice(Logitech_Make, "Squeezebox Radio", Audio_Device);
}


void LogitechSqueezebox::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  connect(
    threadableProtocol,
    SIGNAL(errorMessage(QString)),
    this,
    SIGNAL(errorMessage(QString)));

  setPreData(0x6E, 8);

  addKey("Add", Unmapped_Key, 0x06, 8);
  addKey("Brightness", Unmapped_Key, 0x20, 8);
  addKey("Browse", Unmapped_Key, 0x0E, 8);
  addKey("BrowseAlbum", Unmapped_Key, 0x3E, 8);
  addKey("BrowseArtist", Unmapped_Key, 0x2E, 8);
  addKey("BrowseMusic", Unmapped_Key, 0x4E, 8);
  addKey("BrowsePlayList", Unmapped_Key, 0x5E, 8);
  addKey("DirectionDown", Down_Key, 0x0D, 8);
  addKey("DirectionLeft", Left_Key, 0x09, 8);
  addKey("DirectionRight", Right_Key, 0x0B, 8);
  addKey("DirectionUp", Up_Key, 0x07, 8);
  addKey("FastForward", FastForward_Key, 0x05, 8);
  addKey("Favorite", Favorites_Key, 0x18, 8);
  addKey("Home", Menu_Key, 0x44, 8);
  addKey("Mute", Mute_Key, 0x23, 8);
  addKey("NextTrack", Next_Key, 0x05, 8);
  addKey("NowPlaying", Info_Key, 0x1E, 8);
  addKey("Pause", Pause_Key, 0x04, 8);
  addKey("Play", Play_Key, 0x08, 8);
  addKey("PowerOff", PowerOff_Key, 0xE1, 8);
  addKey("PowerOn", PowerOn_Key, 0xF1, 8);
  addKey("PowerToggle", Power_Key, 0x02, 8);
  addKey("Preset1", Unmapped_Key, 0x51, 8);
  addKey("Preset2", Unmapped_Key, 0x52, 8);
  addKey("Preset3", Unmapped_Key, 0x53, 8);
  addKey("Preset4", Unmapped_Key, 0x54, 8);
  addKey("Preset5", Unmapped_Key, 0x55, 8);
  addKey("Preset6", Unmapped_Key, 0x56, 8);
  addKey("PreviousTrack", Previous_Key, 0x03, 8);
  addKey("Rewind", Rewind_Key, 0x03, 8);
  addKey("Search", Unmapped_Key, 0x1A, 8);
  addKey("SearchAlbum", Unmapped_Key, 0x3A, 8);
  addKey("SearchArtist", Unmapped_Key, 0x2A, 8);
  addKey("SearchSong", Unmapped_Key, 0x4A, 8);
  addKey("Select/Ok", Select_Key, 0x08, 8);
  addKey("Shuffle", Random_Key, 0x1B, 8);
  addKey("Size", Unmapped_Key, 0x1F, 8);
  addKey("Sleep", Sleep_Key, 0x1D, 8);
  addKey("VolumeDown", VolumeDown_Key, 0x00, 8);
  addKey("VolumeUp", VolumeUp_Key, 0x01, 8);
  addKey("0", Zero_Key, 0x19, 8);
  addKey("1", One_Key, 0x0F, 8);
  addKey("2", Two_Key, 0x10, 8);
  addKey("3", Three_Key, 0x11, 8);
  addKey("4", Four_Key, 0x12, 8);
  addKey("5", Five_Key, 0x13, 8);
  addKey("6", Six_Key, 0x14, 8);
  addKey("7", Seven_Key, 0x15, 8);
  addKey("8", Eight_Key, 0x16, 8);
  addKey("9", Nine_Key, 0x17, 8);
}
