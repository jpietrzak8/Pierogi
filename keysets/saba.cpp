#include "saba.h"
#include "protocols/thomsonprotocol.h"

SabaTV1::SabaTV1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV/VCR Keyset 1",
      Saba_Make,
      index)
{
  threadableProtocol = new ThomsonProtocol(guiObject, index);

  setPreData(0x0, 4);

  addKey("1", One_Key, 0x00, 7);
  addKey("4", Four_Key, 0x01, 7);
  addKey("7", Seven_Key, 0x02, 7);
  addKey("SP/LP", VHSSpeed_Key, 0x05, 7);
  addKey("2", Two_Key, 0x08, 7);
  addKey("5", Five_Key, 0x09, 7);
  addKey("8", Eight_Key, 0x0A, 7);
  addKey("0/--", Zero_Key, 0x0E, 7);

  addKey("3", Three_Key, 0x10, 7);
  addKey("6", Six_Key, 0x11, 7);
  addKey("9", Nine_Key, 0x12, 7);
  addKey("Timer", Timer_Key, 0x15, 7); // "D"
  addKey("AV", AuxInput_Key, 0x18, 7);
  addKey("Power", Power_Key, 0x1D, 7);
  addKey("Status/Exit", Exit_Key, 0x1E, 7); // "F"
  addKey("Rew", Rewind_Key, 0x1F, 7);

  addKey("Play", Play_Key, 0x20, 7);
  addKey("FF", FastForward_Key, 0x21, 7);
  addKey("Pause", Pause_Key, 0x22, 7);
  addKey("Record", Record_Key, 0x23, 7);
  addKey("Stop", Stop_Key, 0x24, 7);
  addKey("Channel+", ChannelUp_Key, 0x29, 7); // "P/T+", "Vol+"
  addKey("Channel-", ChannelDown_Key, 0x2A, 7); // "P/T-", "Vol-"
  addKey("AutoTrack", AutoTracking_Key, 0x2C, 7);

  addKey("OK", Select_Key, 0x33, 7);
  addKey("Up", Up_Key, 0x34, 7);
  addKey("Down", Down_Key, 0x35, 7);
  addKey("Left", Left_Key, 0x36, 7);
  addKey("Right", Right_Key, 0x37, 7);
  addKey("Clock", Unmapped_Key, 0x38, 7); // "C"
  addKey("Menu", Menu_Key, 0x39, 7); // "Install"
  addKey("Ch.setup", Unmapped_Key, 0x3B, 7); // "B"
  addKey("Mark", Unmapped_Key, 0x3C, 7);
  addKey("Scan/Erase", Unmapped_Key, 0x3D, 7); // "Index"
}


SabaTV2::SabaTV2(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 2",
      Saba_Make,
      index)
{
  threadableProtocol = new ThomsonProtocol(guiObject, index);

  setPreData(0x3, 4);

  addKey("1", One_Key, 0x00, 7);
  addKey("4", Four_Key, 0x01, 7);
  addKey("7", Seven_Key, 0x02, 7);
  addKey("MUTE", Mute_Key, 0x05, 7);
  addKey("2", Two_Key, 0x08, 7);
  addKey("5", Five_Key, 0x09, 7);
  addKey("8", Eight_Key, 0x0A, 7);
  addKey("UP", Up_Key, 0x0B, 7);
  addKey("OK", Select_Key, 0x0C, 7);
  addKey("DOWN", Down_Key, 0x0D, 7);
  addKey("0/--", Zero_Key, 0x0E, 7);

  addKey("3", Three_Key, 0x10, 7);
  addKey("6", Six_Key, 0x11, 7);
  addKey("9", Nine_Key, 0x12, 7);
  addKey("BLUE", Blue_Key, 0x15, 7);
  addKey("AV", AuxInput_Key, 0x18, 7);
  addKey("Power", Power_Key, 0x1D, 7);
  addKey("TEXT", Teletext_Key, 0x1E, 7);
//  addKey("Rew", Rewind_Key, 0x1F, 7);

//  addKey("Play", Play_Key, 0x20, 7);
//  addKey("FF", FastForward_Key, 0x21, 7);
//  addKey("Pause", Pause_Key, 0x22, 7);
//  addKey("Record", Record_Key, 0x23, 7);
//  addKey("Stop", Stop_Key, 0x24, 7);
  addKey("PR+", ChannelUp_Key, 0x25, 7);
  addKey("PR-", ChannelDown_Key, 0x27, 7);
  addKey("VOL+", VolumeUp_Key, 0x29, 7);
  addKey("VOL-", VolumeDown_Key, 0x2A, 7);
//  addKey("AutoTrack", AutoTracking_Key, 0x2C, 7);

  addKey("MENU", Menu_Key, 0x31, 7);
//  addKey("OK", Select_Key, 0x33, 7);
//  addKey("Up", Up_Key, 0x34, 7);
//  addKey("Down", Down_Key, 0x35, 7);
  addKey("Left", Left_Key, 0x36, 7);
  addKey("Right", Right_Key, 0x37, 7);
  addKey("YELLOW", Yellow_Key, 0x38, 7);
  addKey("RED", Red_Key, 0x39, 7);
  addKey("GREEN", Green_Key, 0x3B, 7);
//  addKey("Mark", Unmapped_Key, 0x3C, 7);
//  addKey("Scan/Erase", Unmapped_Key, 0x3D, 7); // "Index"
  addKey("EXIT", Exit_Key, 0x3E, 7);
}
