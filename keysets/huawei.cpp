#include "huawei.h"
#include "protocols/necprotocol.h"
#include "protocols/necxprotocol.h"


HuaweiSTB1::HuaweiSTB1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "STB Keyset 1",
      Huawei_Make,
      index)
{
  addControlledDevice(Huawei_Make, "EX2108", Other_Device);

  threadableProtocol = new NECXProtocol(guiObject, index, false);

  setPreData(0x1111, 16);

  addKey("5", Five_Key, 0x80, 8);
  addKey("0", Zero_Key, 0x87, 8);
  addKey("Green", Green_Key, 0x89, 8);
  addKey("7", Seven_Key, 0x8A, 8);
  addKey("8", Eight_Key, 0x8B, 8);
  addKey("4", Four_Key, 0x8E, 8);

  addKey("Stop", Stop_Key, 0x90, 8);
  addKey("1", One_Key, 0x92, 8);
  addKey("2", Two_Key, 0x93, 8);
  addKey("Last_ch", PrevChannel_Key, 0x95, 8);
  addKey("Guide", Guide_Key, 0x98, 8);
  addKey("Page-", PageDown_Key, 0x99, 8);
  addKey("left_arrow", Left_Key, 0x99, 8);
  addKey("Record", Record_Key, 0x9A, 8);
  addKey("Power", Power_Key, 0x9C, 8);
  addKey("Menu", Menu_Key, 0x9D, 8);

  addKey("Page+", PageUp_Key, 0xC1, 8);
  addKey("right_arrow", Right_Key, 0xC1, 8);
  addKey("Play", Play_Key, 0xC3, 8);
  addKey("Pause", Pause_Key, 0xC3, 8);
  addKey("9", Nine_Key, 0xC4, 8);
  addKey("6", Six_Key, 0xC8, 8);
  addKey("CH+", ChannelUp_Key, 0xCA, 8);
  addKey("up_arrow", Up_Key, 0xCA, 8);
  addKey("3", Three_Key, 0xCC, 8);
  addKey("Select", Select_Key, 0xCE, 8);

  addKey("CH-", ChannelDown_Key, 0xD2, 8);
  addKey("down_arrow", Down_Key, 0xD2, 8);
  addKey("ffwd", FastForward_Key, 0xD6, 8);
  addKey("Yellow", Yellow_Key, 0xD9, 8);
  addKey("rewind", Rewind_Key, 0xDA, 8);
  addKey("Info", Info_Key, 0xDD, 8);
}


HuaweiSTB2::HuaweiSTB2(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "STB Keyset 2",
      Huawei_Make,
      index)
{
  addControlledDevice(Huawei_Make, "EC2108", Other_Device);

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x11, 8);

  addKey("Red", Red_Key, 0x84, 8);
  addKey("0", Zero_Key, 0x87, 8);
  addKey("Green", Green_Key, 0x89, 8);
  addKey("7", Seven_Key, 0x8A, 8);
  addKey("8", Eight_Key, 0x8B, 8);
  addKey("4", Four_Key, 0x8E, 8);
  addKey("5", Five_Key, 0x8F, 8);

  addKey("ChannelPrev", PrevChannel_Key, 0x90, 8);
  addKey("1", One_Key, 0x92, 8);
  addKey("2", Two_Key, 0x93, 8);
  addKey("LiveTV", LiveTV_Key, 0x95, 8);
  addKey("Blue", Blue_Key, 0x96, 8);
  addKey("PageDown", PageDown_Key, 0x98, 8);
  addKey("VolumeDown", VolumeDown_Key, 0x99, 8);
  addKey("DirectionLeft", Left_Key, 0x99, 8);
  addKey("Guide", Guide_Key, 0x9A, 8);
  addKey("Menu", Menu_Key, 0x9B, 8);
  addKey("PowerToggle", Power_Key, 0x9C, 8);
  addKey("Mute", Mute_Key, 0x9D, 8);
  addKey("#", Unmapped_Key, 0x9F, 8);

  addKey("VolumeUp", VolumeUp_Key, 0xC1, 8);
  addKey("DirectionRight", Right_Key, 0xC1, 8);
  addKey("Info", Info_Key, 0xC2, 8);
  addKey("Pause", Pause_Key, 0xC3, 8);
  addKey("Play", Play_Key, 0xC3, 8);
  addKey("9", Nine_Key, 0xC4, 8);
  addKey("Subtitle", Captions_Key, 0xC7, 8);
  addKey("6", Six_Key, 0xC8, 8);
  addKey("ChannelUp", ChannelUp_Key, 0xCA, 8);
  addKey("DirectionUp", Up_Key, 0xCA, 8);
  addKey("3", Three_Key, 0xCC, 8);
  addKey("Select/Ok", Select_Key, 0xCE, 8);
  addKey("PageUp", PageUp_Key, 0xCF, 8);

  addKey("VOD", Unmapped_Key, 0xD1, 8);
  addKey("ChannelDown", ChannelDown_Key, 0xD2, 8);
  addKey("DirectionDown", Down_Key, 0xD2, 8);
  addKey("Audio", Audio_Key, 0xD4, 8);
  addKey("*", Unmapped_Key, 0xD5, 8);
  addKey("FastForward", FastForward_Key, 0xD6, 8);
  addKey("Exit", Exit_Key, 0xD7, 8);
  addKey("Yellow", Yellow_Key, 0xD9, 8);
  addKey("Rewind", Rewind_Key, 0xDA, 8);
  addKey("Interactive", Unmapped_Key, 0xDD, 8);
}
