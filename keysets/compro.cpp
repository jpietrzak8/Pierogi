//
// compro.cpp
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

#include "compro.h"
#include "protocols/necprotocol.h"


ComproTVCard1::ComproTVCard1(
  unsigned int index)
  : PIRKeysetMetaData(
      "PC TV Tuner Card 1",
      Compro_Make,
      index)
{
}


void ComproTVCard1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x7E80, 16);

  addKey("MUTE", Mute_Key, 0x14, 8);
  addKey("ZOOM", Zoom_Key, 0x44, 8);
  addKey("DVD_VCD", DVDInput_Key, 0x01, 8);
  addKey("FM", TunerInput_Key, 0x43, 8);
  addKey("PVR_TV", HDDInput_Key, 0x00, 8);
  addKey("REWIND", Rewind_Key, 0x0A, 8);
  addKey("PLAY_PAUSE", Play_Key, 0x08, 8);
  addKey("PLAY_PAUSE", Pause_Key, 0x08, 8);
  addKey("FORWARD", FastForward_Key, 0x0F, 8);
  addKey("PREVIOUS", Previous_Key, 0x02, 8);
  addKey("STOP", Stop_Key, 0x07, 8);
  addKey("NEXT", Next_Key, 0x06, 8);
  addKey("GUIDE", Guide_Key, 0x03, 8);
  addKey("SETUP", Menu_Key, 0x09, 8);
  addKey("UP", Up_Key, 0x0C, 8);
  addKey("DOWN", Down_Key, 0x0E, 8);
  addKey("LEFT", Left_Key, 0x0B, 8);
  addKey("RIGHT", Right_Key, 0x0D, 8);
  addKey("TV_VIDEO", Input_Key, 0x05, 8);
  addKey("CH_SURF", Unmapped_Key, 0x42, 8);
  addKey("VOL+", VolumeUp_Key, 0x12, 8);
  addKey("VOL-", VolumeDown_Key, 0x15, 8);
  addKey("OK", Select_Key, 0x11, 8);
  addKey("ANGLE", Angle_Key, 0x10, 8);
  addKey("SUBTITLE", Captions_Key, 0x13, 8);
  addKey("REC", Record_Key, 0x04, 8);
  addKey("1", One_Key, 0x16, 8);
  addKey("2", Two_Key, 0x17, 8);
  addKey("3", Three_Key, 0x18, 8);
  addKey("4", Four_Key, 0x19, 8);
  addKey("5", Five_Key, 0x1A, 8);
  addKey("6", Six_Key, 0x1B, 8);
  addKey("7", Seven_Key, 0x1C, 8);
  addKey("8", Eight_Key, 0x1D, 8);
  addKey("9", Nine_Key, 0x1E, 8);
  addKey("LANGUAGE", Audio_Key, 0x40, 8);
  addKey("0", Zero_Key, 0x1F, 8);
  addKey("SLEEP", Sleep_Key, 0x41, 8);
}
