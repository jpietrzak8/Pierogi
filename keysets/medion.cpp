//
// medion.cpp
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

#include "medion.h"
#include "protocols/necprotocol.h"
#include "protocols/paceprotocol.h"

MedionSTB1::MedionSTB1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV DVR Keyset 1",
      Medion_Make,
      TV_Panels | MediaControl_Panels | MediaRecord_Panels,
      index)
{
  addControlledDevice(Medion_Make, "HDD-DVR 0905", Other_Device);
}


void MedionSTB1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x6917, 16);

  addKey("power", Power_Key, 0x0E, 8);
  addKey("vol+", VolumeUp_Key, 0x49, 8);
  addKey("vol-", VolumeDown_Key, 0x43, 8);
  addKey("ch+", ChannelUp_Key, 0x51, 8);
  addKey("ch-", ChannelDown_Key, 0x4D, 8);
  addKey("left", Left_Key, 0x1C, 8);
  addKey("right", Right_Key, 0x48, 8);
  addKey("up", Up_Key, 0x44, 8);
  addKey("down", Down_Key, 0x1D, 8);
  addKey("ok", Select_Key, 0x5C, 8);
  addKey("mute", Mute_Key, 0x16, 8);
  addKey("menu", Menu_Key, 0x54, 8);
  addKey("epg", Guide_Key, 0x12, 8);
  addKey("exit", Exit_Key, 0x42, 8);
  addKey("1", One_Key, 0x13, 8);
  addKey("2", Two_Key, 0x10, 8);
  addKey("3", Three_Key, 0x11, 8);
  addKey("4", Four_Key, 0x0F, 8);
  addKey("5", Five_Key, 0x0C, 8);
  addKey("6", Six_Key, 0x0D, 8);
  addKey("7", Seven_Key, 0x0B, 8);
  addKey("8", Eight_Key, 0x08, 8);
  addKey("9", Nine_Key, 0x09, 8);
  addKey("0", Zero_Key, 0x47, 8);
  addKey("av", Input_Key, 0x1F, 8);
  addKey("-/--", DoubleDigit_Key, 0x50, 8);
  addKey("rew", Rewind_Key, 0x15, 8);
  addKey("play", Play_Key, 0x1B, 8);
  addKey("fwd", FastForward_Key, 0x55, 8);
  addKey("rec", Record_Key, 0x02, 8);
  addKey("stop", Stop_Key, 0x59, 8);
  addKey("pause", Pause_Key, 0x19, 8);
  addKey("u1", Unmapped_Key, 0x04, 8);
  addKey("u2", Unmapped_Key, 0x14, 8);
  addKey("u3", Unmapped_Key, 0x03, 8);
  addKey("u4", Unmapped_Key, 0x00, 8);
  addKey("einbl", Unmapped_Key, 0x5A, 8);
  addKey("red", Red_Key, 0x17, 8);
  addKey("green", Green_Key, 0x52, 8);
  addKey("yellow", Yellow_Key, 0x53, 8);
  addKey("blue", Blue_Key, 0x18, 8);
  addKey("pink", Unmapped_Key, 0x4C, 8);
}
  


MedionDVD1::MedionDVD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Medion_Make,
      MediaControl_Panels,
      index)
{
}


void MedionDVD1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, false);

  setPreData(0x00, 8);

  addKey("POWER", Power_Key, 0x00, 8);
  addKey("PAUSE", Pause_Key, 0x03, 8);
  addKey("PLAY", Play_Key, 0x06, 8);
  addKey("EJECT", Eject_Key, 0x0C, 8);
  addKey("SETUP", Menu_Key, 0x0F, 8);

  addKey("STOP", Stop_Key, 0x13, 8);

  addKey("1", One_Key, 0x4B, 8);
  addKey("2", Two_Key, 0x47, 8);
  addKey("3", Three_Key, 0x43, 8);
  addKey("4", Four_Key, 0x4A, 8);
  addKey("5", Five_Key, 0x46, 8);
  addKey("6", Six_Key, 0x42, 8);
  addKey("7", Seven_Key, 0x49, 8);
  addKey("8", Eight_Key, 0x45, 8);
  addKey("9", Nine_Key, 0x41, 8);
  addKey("0", Zero_Key, 0x44, 8);

  addKey("FFWD", FastForward_Key, 0x50, 8);
  addKey("NEXT", Next_Key, 0x51, 8);
  addKey("VOLPLUS", VolumeUp_Key, 0x52, 8);
  addKey("MUTE", Mute_Key, 0x53, 8);
  addKey("FREV", Rewind_Key, 0x54, 8);
  addKey("PREV", Previous_Key, 0x55, 8);
  addKey("VOLMINUS", VolumeDown_Key, 0x56, 8);
  addKey("SUBTITLE", Captions_Key, 0x5E, 8);
}


MedionDVD2::MedionDVD2(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 2",
      Medion_Make,
      MediaControl_Panels,
      index)
{
}


void MedionDVD2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new PaceProtocol(guiObject, index);

  setPreData(0x5, 3);

  addKey("ZOOM", Zoom_Key, 0x12, 6);
  addKey("PREV", Previous_Key, 0x15, 6);
  addKey("NEXT", Next_Key, 0x16, 6);
  addKey("MENU", DiscMenu_Key, 0x17, 6);
  addKey("MUTE", Mute_Key, 0x18, 6);
  addKey("PLAY", Play_Key, 0x19, 6);
  addKey("PAUSE", Pause_Key, 0x1A, 6);
  addKey("8", Eight_Key, 0x1C, 6);
  addKey("4", Four_Key, 0x1D, 6);
  addKey("POWER", Power_Key, 0x1E, 6);
  addKey("INDEX", Unmapped_Key, 0x1F, 6);

  addKey("INFO", Info_Key, 0x20, 6);
  addKey("RIGHT", Right_Key, 0x21, 6);
  addKey("STOP", Stop_Key, 0x22, 6);
  addKey("CLEAR", Clear_Key, 0x23, 6);
  addKey("7", Seven_Key, 0x24, 6);
  addKey("3", Three_Key, 0x25, 6);
  addKey("EJECT", Eject_Key, 0x26, 6);
  addKey("TITLE", DiscTitle_Key, 0x27, 6);
  addKey("UP", Up_Key, 0x28, 6);
  addKey("OK", Select_Key, 0x29, 6);
  addKey("DOWN", Down_Key, 0x2A, 6);
  addKey("0", Zero_Key, 0x2B, 6);
  addKey("6", Six_Key, 0x2C, 6);
  addKey("2", Two_Key, 0x2D, 6);
  addKey("CAMERA", Angle_Key, 0x2E, 6);

  addKey("EXIT", Exit_Key, 0x30, 6);
  addKey("LEFT", Left_Key, 0x31, 6);
  addKey("FORWARD", FastForward_Key, 0x32, 6);
  addKey("9", Nine_Key, 0x33, 6);
  addKey("5", Five_Key, 0x34, 6);
  addKey("1", One_Key, 0x35, 6);
  addKey("BACKWARD", Rewind_Key, 0x37, 6);
}


MedionVCR1::MedionVCR1(
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      Medion_Make,
      MediaControl_Panels | MediaRecord_Panels,
      index)
{
}


void MedionVCR1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, false);

  setPreData(0x7B80, 16);

  addKey("PowerOff", Power_Key, 0x13, 8);
  addKey("Eject", Eject_Key, 0x4E, 8);
  addKey("TimerRec", RecordTimed_Key, 0x0D, 8);
  addKey("1", One_Key, 0x01, 8);
  addKey("2", Two_Key, 0x02, 8);
  addKey("3", Three_Key, 0x03, 8);
  addKey("4", Four_Key, 0x04, 8);
  addKey("5", Five_Key, 0x05, 8);
  addKey("6", Six_Key, 0x06, 8);
  addKey("7", Seven_Key, 0x07, 8);
  addKey("8", Eight_Key, 0x08, 8);
  addKey("9", Nine_Key, 0x09, 8);
  addKey("0", Zero_Key, 0x00, 8);
  addKey("TV/VCR", Input_Key, 0x12, 8);
  addKey("CannelTracking+", ChannelUp_Key, 0x0A, 8);
  addKey("CannelTracking+", TrackingPlus_Key, 0x0A, 8);
  addKey("ChannelTracking-", ChannelDown_Key, 0x0B, 8);
  addKey("ChannelTracking-", TrackingMinus_Key, 0x0B, 8);
  addKey("SpeedSP/LP", VHSSpeed_Key, 0x1E, 8);
  addKey("Rec-EndSearch", Unmapped_Key, 0x47, 8);
  addKey("Call", Call_Key, 0x5F, 8);
  addKey("REC/OTR", Record_Key, 0x15, 8);
  addKey("Pause/Still", Pause_Key, 0x1A, 8);
  addKey("Play", Play_Key, 0x16, 8);
  addKey("FastReturn", Rewind_Key, 0x19, 8);
  addKey("FastForward", FastForward_Key, 0x18, 8);
  addKey("Stop", Stop_Key, 0x17, 8);
  addKey("ShowView/Program", Unmapped_Key, 0x1D, 8); // vhsplus+, etc.
  addKey("Enter", Select_Key, 0x45, 8);
  addKey("Menu", Menu_Key, 0x50, 8);
  addKey("Cancel", Exit_Key, 0x4A, 8);
  addKey("Index", IndexSearch_Key, 0x14, 8);
  addKey("ATR", AutoTracking_Key, 0x52, 8);
  addKey("Clock/Counter", Unmapped_Key, 0x51, 8);
  addKey("ZeroReturn", Unmapped_Key, 0x4B, 8);
  addKey("CounterReset", Reset_Key, 0x4C, 8);
  addKey("AudioSelect", Audio_Key, 0x0E, 8);
}
