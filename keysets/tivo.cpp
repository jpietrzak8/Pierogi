//
// tivo.cpp
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

#include "tivo.h"
#include "protocols/lircprotocol.h"

Tivo1::Tivo1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Tivo Keyset 1",
      Tivo_Make,
      index)
{
}


void Tivo1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  LIRCProtocol *lp = new LIRCProtocol(
    guiObject, index,
    560, 560,
    560, 1680,
    110000, true);

  threadableProtocol = lp;

  lp->setHeaderPair(9000, 4500);
  lp->setTrailerPulse(560);
  lp->setRepeatPair(9000, 2250);

  setPreData(0xA10C, 16);

//  setCarrierFrequency(40000);

  addKey("TIVO", Power_Key, 0x000F, 16);
  addKey("LIVETV", LiveTV_Key, 0x8807, 16);
  addKey("UP", Up_Key, 0x2807, 16);
  addKey("DOWN", Down_Key, 0x6807, 16);
  addKey("RIGHT", Right_Key, 0xA807, 16);
  addKey("LEFT", Left_Key, 0xE807, 16);
  addKey("THUMBSDOWN", Unmapped_Key, 0x1807, 16);
  addKey("THUMBSUP", Unmapped_Key, 0x5807, 16);
  addKey("SELECT", Select_Key, 0x9807, 16);
  addKey("RECORD", Record_Key, 0x040B, 16);
  addKey("PLAY", Play_Key, 0x840B, 16);
  addKey("CH+", ChannelUp_Key, 0x7807, 16);
  addKey("CH-", ChannelDown_Key, 0xF807, 16);
  addKey("REV", Rewind_Key, 0x440B, 16);
  addKey("FWD", FastForward_Key, 0x240B, 16);
  addKey("PAUSE", Pause_Key, 0xC40B, 16);
  addKey("SLOW", Slow_Key, 0xA40B, 16);
  addKey("REPLAY", Replay_Key, 0x640B, 16);
  addKey("JUMPTOEND", Advance_Key, 0xE40B, 16);
  addKey("1", One_Key, 0x140B, 16);
  addKey("2", Two_Key, 0x940B, 16);
  addKey("3", Three_Key, 0x540B, 16);
  addKey("4", Four_Key, 0xD40B, 16);
  addKey("5", Five_Key, 0x340B, 16);
  addKey("6", Six_Key, 0xB40B, 16);
  addKey("7", Seven_Key, 0x740B, 16);
  addKey("8", Eight_Key, 0xF40B, 16);
  addKey("9", Nine_Key, 0x0C03, 16);
  addKey("0", Zero_Key, 0x8C03, 16);
  addKey("CLEAR", Clear_Key, 0x4C03, 16);
  addKey("ENTER/LAST", Enter_Key, 0xCC03, 16);
  addKey("ENTER/LAST", PrevChannel_Key, 0xCC03, 16);
  addKey("WINDOW", PIP_Key, 0x220D, 16);
  addKey("INFO", Info_Key, 0xC807, 16);
  addKey("GUIDE", Guide_Key, 0x6C03, 16);
  addKey("MUTE", Mute_Key, 0xD807, 16);
}


Tivo1a::Tivo1a(
  unsigned int index)
  : Tivo1(index)
{
  setKeysetName("Tivo Keyset 1a");
}


void Tivo1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  Tivo1::populateProtocol(guiObject);

  addKey("TIVO", Power_Key, 0xE00F, 16);
  addKey("TVPOWER", Unmapped_Key, 0x0807, 16);
  addKey("TVINPUT", Input_Key, 0x2C03, 16);
  addKey("VOL+", VolumeUp_Key, 0x3807, 16);
  addKey("VOL-", VolumeDown_Key, 0xB807, 16);
}


Tivo1b::Tivo1b(
  unsigned int index)
  : Tivo1(index)
{
  setKeysetName("Tivo Keyset 1b");
}


void Tivo1b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  Tivo1::populateProtocol(guiObject);

  addKey("tivo", Power_Key, 0xF00F, 16);
  addKey("tvpower", Unmapped_Key, 0x48B7, 16);
  addKey("vol+", VolumeUp_Key, 0x6897, 16);
  addKey("vol-", VolumeDown_Key, 0xE817, 16);
//  addKey("mute", Mute_Key, 0xA857, 16); // Why two mute keys?
  addKey("exit", Exit_Key, 0xA20D, 16);
  addKey("list", Unmapped_Key, 0x620D, 16);
}


Tivo1c::Tivo1c(
  unsigned int index)
  : Tivo1(index)
{
  setKeysetName("Tivo Keyset 1c");
}


void Tivo1c::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  Tivo1::populateProtocol(guiObject);

  addKey("TIVO", Power_Key, 0x500F, 16);
  addKey("TV_POWER", Unmapped_Key, 0x0807, 16);
  addKey("TV_INPUT", Input_Key, 0x2C03, 16);
  addKey("VOL_UP", VolumeUp_Key, 0x3807, 16);
  addKey("VOL_DOWN", VolumeDown_Key, 0xB807, 16);
}


Tivo1d::Tivo1d(
  unsigned int index)
  : Tivo1(index)
{
  setKeysetName("Tivo Keyset 1d");
}


void Tivo1d::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  Tivo1::populateProtocol(guiObject);

  addKey("TIVO", Power_Key, 0x400F, 16);
  addKey("TVPWR", Unmapped_Key, 0x0807, 16);
  addKey("GUIDE", Guide_Key, 0x8807, 16);
  addKey("MENU", Menu_Key, 0x4807, 16);
  addKey("VOL+", VolumeUp_Key, 0x3807, 16);
  addKey("VOL-", VolumeDown_Key, 0xB807, 16);
}
