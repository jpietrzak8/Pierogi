#include "bose.h"
#include "protocols/boseprotocol.h"
#include "protocols/necprotocol.h"

BoseRadio1::BoseRadio1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Wave Radio Keyset 1",
      Bose_Make,
      index)
{
  threadableProtocol = new BoseProtocol(guiObject, index);

  addKey("Mute", Mute_Key, 0x01, 8);
  addKey("Volume_Down", VolumeDown_Key, 0x02, 8);
  addKey("Volume_Up", VolumeUp_Key, 0x03, 8);
  addKey("FM_AM", TunerBand_Key, 0x06, 8);
  addKey("1", One_Key, 0x07, 8);
  addKey("2", Two_Key, 0x08, 8);
  addKey("3", Three_Key, 0x09, 8);
  addKey("4", Four_Key, 0x0A, 8);
  addKey("5", Five_Key, 0x0B, 8);
  addKey("6", Six_Key, 0x0C, 8);
  addKey("AUX", AuxInput_Key, 0x0F, 8);

  addKey("Seek_Track_Backward", Previous_Key, 0x18, 8);
  addKey("Seek_Track_Forward", Next_Key, 0x19, 8);
  addKey("Stop_Eject", Stop_Key, 0x1A, 8);
  addKey("Stop_Eject", Eject_Key, 0x1A, 8);
  addKey("Play_Pause", Play_Key, 0x1B, 8);
  addKey("Play_Pause", Pause_Key, 0x1B, 8);
  addKey("Play_Mode", Mode_Key, 0x21, 8);
  addKey("Alarm_On_Off", Unmapped_Key, 0x22, 8);
  addKey("Alarm_Time", Timer_Key, 0x23, 8);
  addKey("Time_Plus", Unmapped_Key, 0x24, 8);

  addKey("On_Off", Power_Key, 0x4C, 8);
  addKey("CD", CDInput_Key, 0x53, 8);
  addKey("Sleep", Sleep_Key, 0x54, 8);
  addKey("Tune_MP3_Down", ChannelDown_Key, 0x57, 8);
  addKey("Tune_MP3_Up", ChannelUp_Key, 0x58, 8);

  addKey("Alarm_Wake_To", Unmapped_Key, 0x70, 8);
  addKey("Time_Minus", Unmapped_Key, 0x9E, 8);
}


BoseRadio2::BoseRadio2(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Wave Radio Keyset 2",
      Bose_Make,
      index)
{
  threadableProtocol = new BoseProtocol(guiObject, index);

  addKey("on/off", Power_Key, 0x00, 8);
  addKey("4", Four_Key, 0x08, 8);
  addKey("am", Unmapped_Key, 0x10, 8);
  addKey("6", Six_Key, 0x20, 8);
  addKey("trackprev", Previous_Key, 0x30, 8);
  addKey("volup", VolumeUp_Key, 0x40,8);
  addKey("cdstop", Stop_Key, 0x50, 8);
  addKey("fm", Unmapped_Key, 0x60, 8);
  addKey("2", Two_Key, 0x70, 8);
  addKey("mute", Mute_Key, 0x80, 8);
  addKey("5", Five_Key, 0x88, 8);
  addKey("cdplaypause", Play_Key, 0x90, 8);
  addKey("cdplaypause", Pause_Key, 0x90, 8);
  addKey("sleep", Sleep_Key, 0xA0, 8);
  addKey("1", One_Key, 0xB0, 8);
  addKey("voldown", VolumeDown_Key, 0xC0, 8);
  addKey("tracknext", Next_Key, 0xD0, 8);
  addKey("aux", AuxInput_Key, 0xE0, 8);
  addKey("3", Three_Key, 0xF0, 8);
}


BoseRadio3::BoseRadio3(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Wave Radio Keyset 3",
      Bose_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index, false, false);

  setPreData(0xBA, 8);

  addKey("MUTE", Mute_Key, 0x01, 8);
  addKey("VOL-", VolumeDown_Key, 0x02, 8);
  addKey("VOL+", VolumeUp_Key, 0x03, 8);
  addKey("STATION", Unmapped_Key, 0x04, 8);
  addKey("AM/FM", TunerBand_Key, 0x05, 8);
  addKey("1", One_Key, 0x07, 8);
  addKey("2", Two_Key, 0x08, 8);
  addKey("3", Three_Key, 0x09, 8);
  addKey("4", Four_Key, 0x0A, 8);
  addKey("5", Five_Key, 0x0B, 8);
  addKey("6", Six_Key, 0x0C, 8);
  addKey("AUX", AuxInput_Key, 0x0F, 8);

  addKey("TUNE+", ChannelUp_Key, 0x10, 8); // "Tune/Time+"
  addKey("TUNE-", ChannelDown_Key, 0x11, 8); // "Tune/Time-"
  addKey("ALARM/TIME", Timer_Key, 0x12, 8);
  addKey("ALARM/WAKEUPTO", Unmapped_Key, 0x13, 8);

  addKey("SLEEP", Sleep_Key, 0x1E, 8);

  addKey("POWER", Power_Key, 0x4C, 8); // also "enter"?
}
