//
// dish.cpp
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

#include "dish.h"
#include "protocols/dishprotocol.h"
#include <QComboBox>


DishReceiver1::DishReceiver1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Sat Keyset 1",
      Dish_Make,
      TV_Panels | MediaControl_Panels | MediaRecord_Panels,
      index)
{
}


void DishReceiver1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new DishProtocol(guiObject, index);

  setPreData(0x00, 5);

  addDishKey("info", Info_Key, 0x00, 0x00);
  addDishKey("power_on", PowerOn_Key, 0x01, 0x00);
  addDishKey("power", Power_Key, 0x02, 0x00);
  addDishKey("1", One_Key, 0x04, 0x00);
  addDishKey("2", Two_Key, 0x05, 0x00);
  addDishKey("3", Three_Key, 0x06, 0x00);
  addDishKey("4", Four_Key, 0x08, 0x00);
  addDishKey("5", Five_Key, 0x09, 0x00);
  addDishKey("6", Six_Key, 0x0A, 0x00);
  addDishKey("menu", Menu_Key, 0x0B, 0x00);
  addDishKey("7", Seven_Key, 0x0C, 0x00);
  addDishKey("8", Eight_Key, 0x0D, 0x00);
  addDishKey("9", Nine_Key, 0x0E, 0x00);

  addDishKey("select", Select_Key, 0x10, 0x00); // "OK", "ENTER"
  addDishKey("select", Enter_Key, 0x10, 0x00); // "OK", "ENTER"
  addDishKey("0", Zero_Key, 0x11, 0x00);
  addDishKey("cancel", Exit_Key, 0x12, 0x00);  // "Exit"
  addDishKey("guide", Guide_Key, 0x14, 0x00);
//  addDishKey("mute", Mute_Key, 0x15, 0x00);
  addDishKey("livetv", LiveTV_Key, 0x16, 0x00); // "view"
  addDishKey("tv_vcr", Input_Key, 0x17, 0x00); // "TV/VIDEO", "input"
  addDishKey("right", Right_Key, 0x18, 0x00); // "VolUp"
//  addDishKey("right", VolumeUp_Key, 0x18, 0x00); // "VolUp"
  addDishKey("up", Up_Key, 0x1A, 0x00); // "ChanUp"
  addDishKey("up", ChannelUp_Key, 0x1A, 0x00); // "ChanUp"
  addDishKey("recall", PrevChannel_Key, 0x1B, 0x00); // "prev"
  addDishKey("left", Left_Key, 0x1C, 0x00); // "VolDown"
//  addDishKey("left", VolumeDown_Key, 0x1C, 0x00); // "VolDown"
  addDishKey("down", Down_Key, 0x1E, 0x00); // "ChanDown"
  addDishKey("down", ChannelDown_Key, 0x1E, 0x00); // "ChanDown"
  addDishKey("record", Record_Key, 0x1F, 0x00);

  addDishKey("pause", Pause_Key, 0x20, 0x00);
  addDishKey("stop", Stop_Key, 0x21, 0x00);
  addDishKey("sys_info", Unmapped_Key, 0x24, 0x00);
  addDishKey("asterisk", Unmapped_Key, 0x25, 0x00); // "*/ptv_list"
  addDishKey("pound", Unmapped_Key, 0x26, 0x00); // "#/search"
  addDishKey("power_off", PowerOff_Key, 0x27, 0x00);
  addDishKey("sat", Unmapped_Key, 0x29, 0x00);
  addDishKey("red", Red_Key, 0x2E, 0x00);
  addDishKey("greenR", Unmapped_Key, 0x2F, 0x00);

  addDishKey("green", Green_Key, 0x30, 0x00);
  addDishKey("yellow", Yellow_Key, 0x31, 0x00);
  addDishKey("blue", Blue_Key, 0x32, 0x00);
  addDishKey("dish_home", Unmapped_Key, 0x34, 0x00);
  addDishKey("sys_info2", Unmapped_Key, 0x36, 0x00);
  addDishKey("dish_home2", Unmapped_Key, 0x38, 0x00);

  addDishKey("mute", Mute_Key, 0x15, 0x01);
  addDishKey("vol+", VolumeUp_Key, 0x19, 0x01);
  addDishKey("vol-", VolumeDown_Key, 0x1D, 0x01);
  addDishKey("tv", Unmapped_Key, 0x2A, 0x01);

  addDishKey("play", Play_Key, 0x03, 0x10);
  addDishKey("PAGEDN", PageDown_Key, 0x07, 0x10);
  addDishKey("PAGEUP", PageUp_Key, 0x0F, 0x10);

  addDishKey("rew", Rewind_Key, 0x31, 0x10);
  addDishKey("fwd", Unmapped_Key, 0x32, 0x10);
  addDishKey("dish", Unmapped_Key, 0x34, 0x10);
  addDishKey("skip_back", Replay_Key, 0x36, 0x10);
  addDishKey("skip_fwd", Advance_Key, 0x37, 0x10);
  addDishKey("dvr", HDDInput_Key, 0x39, 0x10);
  addDishKey("pip", PIP_Key, 0x3A, 0x10);
  addDishKey("position", PIPMove_Key, 0x3B, 0x10);
  addDishKey("swap", PIPSwap_Key, 0x3D, 0x10);
}


void DishReceiver1::populateInputList(
  QComboBox *cb)
{
  cb->clear();

  cb->addItem("TV / Video", QVariant(Input_Key));
  cb->addItem("DVR", QVariant(HDDInput_Key));
}


DishReceiver1a::DishReceiver1a(
  unsigned int index)
  : DishReceiver1(index)
{
  setKeysetName("Sat Keyset 1 mode 2");
}


void DishReceiver1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  DishReceiver1::populateProtocol(guiObject);

  setPreData(0x01, 5);
}


DishReceiver1b::DishReceiver1b(
  unsigned int index)
  : DishReceiver1(index)
{
  setKeysetName("Sat Keyset 1 mode 3");
}


void DishReceiver1b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  DishReceiver1::populateProtocol(guiObject);

  setPreData(0x02, 5);
}


DishReceiver1c::DishReceiver1c(
  unsigned int index)
  : DishReceiver1(index)
{
  setKeysetName("Sat Keyset 1 mode 4");
}


void DishReceiver1c::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  DishReceiver1::populateProtocol(guiObject);

  setPreData(0x03, 5);
}


DishReceiver1d::DishReceiver1d(
  unsigned int index)
  : DishReceiver1(index)
{
  setKeysetName("Sat Keyset 1 mode 5");
}


void DishReceiver1d::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  DishReceiver1::populateProtocol(guiObject);

  setPreData(0x04, 5);
}


DishReceiver1e::DishReceiver1e(
  unsigned int index)
  : DishReceiver1(index)
{
  setKeysetName("Sat Keyset 1 mode 6");
}


void DishReceiver1e::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  DishReceiver1::populateProtocol(guiObject);

  setPreData(0x05, 5);
}


DishReceiver1f::DishReceiver1f(
  unsigned int index)
  : DishReceiver1(index)
{
  setKeysetName("Sat Keyset 1 mode 7");
}


void DishReceiver1f::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  DishReceiver1::populateProtocol(guiObject);

  setPreData(0x06, 5);
}


DishReceiver1g::DishReceiver1g(
  unsigned int index)
  : DishReceiver1(index)
{
  setKeysetName("Sat Keyset 1 mode 8");
}


void DishReceiver1g::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  DishReceiver1::populateProtocol(guiObject);

  setPreData(0x07, 5);
}


DishReceiver1h::DishReceiver1h(
  unsigned int index)
  : DishReceiver1(index)
{
  setKeysetName("Sat Keyset 1 mode 9");
}


void DishReceiver1h::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  DishReceiver1::populateProtocol(guiObject);

  setPreData(0x08, 5);
}


DishReceiver1i::DishReceiver1i(
  unsigned int index)
  : DishReceiver1(index)
{
  setKeysetName("Sat Keyset 1 mode 10");
}


void DishReceiver1i::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  DishReceiver1::populateProtocol(guiObject);

  setPreData(0x09, 5);
}


DishReceiver1j::DishReceiver1j(
  unsigned int index)
  : DishReceiver1(index)
{
  setKeysetName("Sat Keyset 1 mode 11");
}


void DishReceiver1j::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  DishReceiver1::populateProtocol(guiObject);

  setPreData(0x0A, 5);
}


DishReceiver1k::DishReceiver1k(
  unsigned int index)
  : DishReceiver1(index)
{
  setKeysetName("Sat Keyset 1 mode 12");
}


void DishReceiver1k::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  DishReceiver1::populateProtocol(guiObject);

  setPreData(0x0B, 5);
}


DishReceiver1l::DishReceiver1l(
  unsigned int index)
  : DishReceiver1(index)
{
  setKeysetName("Sat Keyset 1 mode 13");
}


void DishReceiver1l::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  DishReceiver1::populateProtocol(guiObject);

  setPreData(0x0C, 5);
}


DishReceiver1m::DishReceiver1m(
  unsigned int index)
  : DishReceiver1(index)
{
  setKeysetName("Sat Keyset 1 mode 14");
}


void DishReceiver1m::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  DishReceiver1::populateProtocol(guiObject);

  setPreData(0x0D, 5);
}


DishReceiver1n::DishReceiver1n(
  unsigned int index)
  : DishReceiver1(index)
{
  setKeysetName("Sat Keyset 1 mode 15");
}


void DishReceiver1n::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  DishReceiver1::populateProtocol(guiObject);

  setPreData(0x0E, 5);
}


DishReceiver1o::DishReceiver1o(
  unsigned int index)
  : DishReceiver1(index)
{
  setKeysetName("Sat Keyset 1 mode 16");
}


void DishReceiver1o::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  DishReceiver1::populateProtocol(guiObject);

  setPreData(0x0F, 5);
}
