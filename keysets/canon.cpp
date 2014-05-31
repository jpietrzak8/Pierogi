//
// canon.cpp
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

#include "canon.h"
#include "protocols/lircprotocol.h"
#include "protocols/necprotocol.h"


CanonDSLR1::CanonDSLR1(
  unsigned int index)
  : PIRKeysetMetaData(
      "RC 1/5/6 Keyset",
      Canon_Make,
      Camera_Panels,
      index)
{
}


void CanonDSLR1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  LIRCProtocol *lp = new LIRCProtocol(
    guiObject, index,
    550, 5250,
    550, 7143,
    100000, true);

  threadableProtocol = lp;
  lp->setTrailerPulse(550);
  lp->setCarrierFrequency(32000); // hope this is right

  addKey("S", OpenShutter_Key, 0x1, 1); // Open shutter immediately (?)
  addKey("2S", DelayedOpenShutter_Key, 0x0, 1); // Two second delay (?)
}


CanonCamcorder1::CanonCamcorder1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Camcorder Keyset 1",
      Canon_Make,
      MediaControl_Panels | MediaRecord_Panels,
      index)
{
}


void CanonCamcorder1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, false);

  setPreData(0x7685, 16);

  addKey("ff", FastForward_Key, 0x00, 8);
  addKey("play", Play_Key, 0x01, 8);
  addKey("rew", Rewind_Key, 0x02, 8);
  addKey("startstop", Unmapped_Key, 0x03, 8); // "remote_set"  ?
  addKey("pause", Pause_Key, 0x04, 8);
  addKey("slow", Slow_Key, 0x05, 8);
  addKey("TAPE-RETURN", Unmapped_Key, 0x06, 8); // "tr"
  addKey("rec", Record_Key, 0x07, 8);
  addKey("COUNTER-RESET", Clear_Key, 0x0D, 8); // "cr"
  addKey("title", Unmapped_Key, 0x0E, 8);
  addKey("date", Unmapped_Key, 0x0F, 8);

  addKey("fadv", StepForward_Key, 0x10, 8); //"+", "next_frame"
  addKey("self_timer", Sleep_Key, 0x12, 8);
  addKey("stop", Stop_Key, 0x17, 8);
  addKey("display", Info_Key, 0x1B, 8); // "tv_screen"
  addKey("t", Unmapped_Key, 0x1C, 8); // "ZOOM-T"
  addKey("w", Unmapped_Key, 0x1D, 8); // "ZOOM-W"

  addKey("up", Up_Key, 0x20, 8);
  addKey("down", Down_Key, 0x21, 8);
  addKey("set", Select_Key, 0x24, 8);
  addKey("menu", Menu_Key, 0x25, 8);
  addKey("on/off", Power_Key, 0x27, 8); // might be wrong
  addKey("d.effects", Unmapped_Key, 0x28, 8);
  addKey("CARD+", Unmapped_Key, 0x2A, 8);
  addKey("CARD-", Unmapped_Key, 0x2B, 8);
  addKey("SLIDE-SHOW", Unmapped_Key, 0x2C, 8);

  addKey("PHOTO", Unmapped_Key, 0x30, 8);
  addKey("data_code", Unmapped_Key, 0x31, 8);
  addKey("zero_set_memory", Unmapped_Key, 0x32, 8);
  addKey("audio_dub.", Unmapped_Key, 0x33, 8);
  addKey("search_select", Memory_Key, 0x34, 8);
  addKey("fwd", Next_Key, 0x35, 8); // "search_select_forward"
  addKey("bwd", Previous_Key, 0x36, 8); // "search_select_rewind"
  addKey("audio_monitor", Audio_Key, 0x39, 8);
  addKey("st-2", Unmapped_Key, 0x3A, 8);
  addKey("st-1", Unmapped_Key, 0x3B, 8);
  addKey("-", StepBack_Key, 0x50, 8); // "prev_frame"
  addKey("x2", Unmapped_Key, 0x55, 8);
  addKey("AV-INSERT", Unmapped_Key, 0x5B, 8);
}


CanonPowershot1::CanonPowershot1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Powershot Keyset 1",
      Canon_Make,
      MediaControl_Panels, // fix!
      index)
{
}


void CanonPowershot1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0xB1CA, 16);

  addKey("Snap", Select_Key, 0x1F, 8);
  addKey("ZoomIn", Up_Key, 0x42, 8);
  addKey("ZoomOut", Down_Key, 0x43, 8);
  addKey("Right", Right_Key, 0x40, 8);
  addKey("Left", Left_Key, 0x41, 8);
  addKey("Multi", Menu_Key, 0x44, 8);
  addKey("Magnify", Guide_Key, 0x46, 8);
  addKey("Display", DiscMenu_Key, 0x47, 8);
}
