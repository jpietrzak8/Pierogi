//
// vestel.cpp
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

#include "vestel.h"
#include "protocols/rc5protocol.h"
#include <QComboBox>


VestelTV1::VestelTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Vestel_Make,
      TV_Panels,
      index)
{
}


void VestelTV1::populateProtocol(
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

  addKey("0", Zero_Key, 0x1000, 13);
  addKey("1", One_Key, 0x1001, 13);
  addKey("2", Two_Key, 0x1002, 13);
  addKey("3", Three_Key, 0x1003, 13);
  addKey("4", Four_Key, 0x1004, 13);
  addKey("5", Five_Key, 0x1005, 13);
  addKey("6", Six_Key, 0x1006, 13);
  addKey("7", Seven_Key, 0x1007, 13);
  addKey("8", Eight_Key, 0x1008, 13);
  addKey("9", Nine_Key, 0x1009, 13);
  addKey("--", Dash_Key, 0x100A, 13);
  addKey("OFF", Power_Key, 0x100C, 13);
  addKey("mute", Mute_Key, 0x100D, 13);
  addKey("PP", Unmapped_Key, 0x100E, 13);

  addKey("VOL_p", VolumeDown_Key, 0x1010, 13);
  addKey("VOL+m", VolumeUp_Key, 0x1011, 13);
  addKey("info", Info_Key, 0x1012, 13);
  addKey("left", Left_Key, 0x1015, 13);
  addKey("right", Right_Key, 0x1016, 13);

  addKey("up", Up_Key, 0x1020, 13);
  addKey("down", Down_Key, 0x1021, 13);
  addKey("PlP", PrevChannel_Key, 0x1022, 13);
  addKey("i-ii", Audio_Key, 0x1023, 13);
  addKey("c", Unmapped_Key, 0x1029, 13);
  addKey("b", Unmapped_Key, 0x102A, 13);
  addKey("f", Unmapped_Key, 0x102B, 13);
  addKey("g", Unmapped_Key, 0x102C, 13);
  addKey("d", Unmapped_Key, 0x102D, 13);
  addKey("e", Unmapped_Key, 0x102E, 13);
  addKey("h", Unmapped_Key, 0x102F, 13);

  addKey("MENU", Menu_Key, 0x1030, 13);
  addKey("feature", Unmapped_Key, 0x1032, 13);
  addKey("install", Unmapped_Key, 0x1034, 13);
  addKey("OK", Select_Key, 0x1035, 13);
  addKey("picture", PictureMode_Key, 0x1036, 13);
  addKey("sound", SoundMode_Key, 0x1037, 13);
  addKey("y", Unmapped_Key, 0x1038, 13);
  addKey("a", Unmapped_Key, 0x103C, 13);
  addKey("x", Unmapped_Key, 0x103F, 13);
}


VestelTV2::VestelTV2(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV/DVD Keyset 2",
      Vestel_Make,
      TV_Panels | MediaControl_Panels,
      index)
{
}


void VestelTV2::populateProtocol(
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

  addKey("on_off", Power_Key, 0x174D, 13);
  addKey("program_up", ChannelUp_Key, 0x1761, 13);
  addKey("program_up", Up_Key, 0x1761, 13);
  addKey("program_down", ChannelDown_Key, 0x1760, 13);
  addKey("program_down", Down_Key, 0x1760, 13);
  addKey("left", Left_Key, 0x1750, 13);
  addKey("right", Right_Key, 0x1751, 13);
  addKey("select", Select_Key, 0x1762, 13);
  addKey("menu", Menu_Key, 0x174E, 13);
  addKey("1", One_Key, 0x1752, 13);
  addKey("2", Two_Key, 0x1743, 13);
  addKey("3", Three_Key, 0x1742, 13);
  addKey("4", Four_Key, 0x174A, 13);
  addKey("5", Five_Key, 0x1746, 13);
  addKey("6", Six_Key, 0x1745, 13);
  addKey("7", Seven_Key, 0x1740, 13);
  addKey("8", Eight_Key, 0x1749, 13);
  addKey("9", Nine_Key, 0x1748, 13);
  addKey("0", Zero_Key, 0x1747, 13);
  addKey("--", Dash_Key, 0x1744, 13);
  addKey("P<P", PrevChannel_Key, 0x176B, 13);
  addKey("PP", Unmapped_Key, 0x1763, 13);
  addKey("vol_up", VolumeUp_Key, 0x1010, 13);
  addKey("vol_down", VolumeDown_Key, 0x1011, 13);
  addKey("I-II", Audio_Key, 0x1770, 13);
  addKey("mute", Mute_Key, 0x100D, 13);
  addKey("INFO", Info_Key, 0x177F, 13);
  addKey("red", Red_Key, 0x1776, 13);
  addKey("green", Green_Key, 0x1772, 13);
  addKey("yellow", Yellow_Key, 0x1778, 13);
  addKey("blue", Blue_Key, 0x1774, 13);
  addKey("TV", Input_Key, 0x1741, 13);
  addKey("AV", AuxInput_Key, 0x1769, 13);
  addKey("Teletext", Teletext_Key, 0x176A, 13);
  addKey("Teletext_time", Unmapped_Key, 0x1777, 13);
  addKey("unwind", Rewind_Key, 0x1756, 13);
  addKey("wind", FastForward_Key, 0x1755, 13);
  addKey("back", Previous_Key, 0x176C, 13);
  addKey("next", Next_Key, 0x176D, 13);
  addKey("play_pause", Play_Key, 0x176E, 13);
  addKey("play_pause", Pause_Key, 0x176E, 13);
  addKey("stop", Stop_Key, 0x176F, 13);
  addKey("Title", DiscTitle_Key, 0x177C, 13);
  addKey("Open_close", Eject_Key, 0x174C, 13);
}


void VestelTV2::populateInputList(
  QComboBox *cb) const
{
  cb->clear();

  cb->addItem("TV", QVariant(Input_Key));
  cb->addItem("AV", QVariant(AuxInput_Key));
}
