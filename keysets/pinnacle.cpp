#include "pinnacle.h"
#include "protocols/rc5protocol.h"

PinnaclePCTV1::PinnaclePCTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "PCTV Keyset 1",
      Pinnacle_Make,
      index)
{
  addControlledDevice(Pinnacle_Make, "800i", Computer_Device);
}


void PinnaclePCTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index, 0x47);

  addKey("key_mute", Mute_Key, 0x00, 6);
  addKey("key_menu", Menu_Key, 0x01, 6);
  addKey("key_power", Power_Key, 0x39, 6);
  addKey("key_volumeup", VolumeUp_Key, 0x03, 6);
  addKey("key_volumedown", VolumeDown_Key, 0x09, 6);
  addKey("key_channelup", ChannelUp_Key, 0x06, 6);
  addKey("key_channeldown", ChannelDown_Key, 0x0C, 6);
  addKey("btn_1", One_Key, 0x0F, 6);
  addKey("btn_2", Two_Key, 0x15, 6);
  addKey("btn_3", Three_Key, 0x10, 6);
  addKey("btn_4", Four_Key, 0x18, 6);
  addKey("btn_5", Five_Key, 0x1B, 6);
  addKey("btn_6", Six_Key, 0x1E, 6);
  addKey("btn_7", Seven_Key, 0x11, 6);
  addKey("btn_8", Eight_Key, 0x21, 6);
  addKey("btn_9", Nine_Key, 0x12, 6);
  addKey("btn_0", Zero_Key, 0x27, 6);
  addKey("key_screen", AspectRatio_Key, 0x24, 6);
  addKey("key_t", Unmapped_Key, 0x2A, 6);
  addKey("key_rewind", Rewind_Key, 0x2D, 6);
  addKey("key_playpause", Play_Key, 0x30, 6);
  addKey("key_playpause", Pause_Key, 0x30, 6);
  addKey("key_fastforward", FastForward_Key, 0x33, 6);
  addKey("key_record", Record_Key, 0x36, 6);
  addKey("key_stop", Stop_Key, 0x3C, 6);
  addKey("key_question", Unmapped_Key, 0x3F, 6);
}


PinnaclePCTV2::PinnaclePCTV2(
  unsigned int index)
  : PIRKeysetMetaData(
      "PCTV Keyset 2",
      Pinnacle_Make,
      index)
{
  addControlledDevice(Pinnacle_Make, "USB Stick", Computer_Device);
}


void PinnaclePCTV2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index, 0x47);

  addKey("play-pause", Play_Key, 0x06, 6);
  addKey("play-pause", Pause_Key, 0x06, 6);
  addKey("stop", Stop_Key, 0x05, 6);
  addKey("exit", Exit_Key, 0x03, 6);
  addKey("screen", AspectRatio_Key, 0x02, 6);
  addKey("rew", Rewind_Key, 0x04, 6);
  addKey("ff", FastForward_Key, 0x07, 6);
  addKey("mute", Mute_Key, 0x00, 6);
  addKey("volup", VolumeUp_Key, 0x0B, 6);
  addKey("voldown", VolumeDown_Key, 0x0F, 6);
  addKey("ask", Unmapped_Key, 0x14, 6);
  addKey("m", Unmapped_Key, 0x16, 6);
  addKey("chup", ChannelUp_Key, 0x13, 6);
  addKey("chdown", ChannelDown_Key, 0x17, 6);
  addKey("rec", Record_Key, 0x01, 6);
  addKey("1", One_Key, 0x08, 6);
  addKey("2", Two_Key, 0x09, 6);
  addKey("3", Three_Key, 0x0A, 6);
  addKey("4", Four_Key, 0x0C, 6);
  addKey("5", Five_Key, 0x0D, 6);
  addKey("6", Six_Key, 0x0E, 6);
  addKey("7", Seven_Key, 0x10, 6);
  addKey("8", Eight_Key, 0x11, 6);
  addKey("9", Nine_Key, 0x12, 6);
  addKey("0", Zero_Key, 0x15, 6);
}


PinnaclePCTV3::PinnaclePCTV3(
  unsigned int index)
  : PIRKeysetMetaData(
      "PCTV Keyset 3",
      Pinnacle_Make,
      index)
{
  addControlledDevice(Pinnacle_Make, "110i", Computer_Device);
}


void PinnaclePCTV3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index, 0x47);

  addKey("MUTE", Mute_Key, 0x01, 6);
  addKey("POWER", Power_Key, 0x39, 6);
  addKey("CTVERECSETREMIRADKY", Unmapped_Key, 0x25, 6);
  addKey("TV", Unmapped_Key, 0x26, 6);
  addKey("EPG", Guide_Key, 0x27, 6);
  addKey("A_RED", Red_Key, 0x03, 6);
  addKey("B_GREEN", Green_Key, 0x04, 6);
  addKey("C_YELLOW", Yellow_Key, 0x05, 6);
  addKey("OTAZNIK_BLUE", Blue_Key, 0x06, 6);
  addKey("VOL_PLUS", VolumeUp_Key, 0x28, 6);
  addKey("VOL_MINUS", VolumeDown_Key, 0x29, 6);
  addKey("PINNACLE", Unmapped_Key, 0x33, 6);
  addKey("CH_PLUS", ChannelUp_Key, 0x08, 6);
  addKey("CH_MINUS", ChannelDown_Key, 0x09, 6);
  addKey("UP", Up_Key, 0x0A, 6);
  addKey("LEFT", Left_Key, 0x0C, 6);
  addKey("OK", Select_Key, 0x36, 6);
  addKey("RIGHT", Right_Key, 0x0D, 6);
  addKey("DOWN", Down_Key, 0x0B, 6);
  addKey("BACK", Exit_Key, 0x30, 6);
  addKey("JUMP", PrevChannel_Key, 0x2A, 6);
  addKey("CTVERECVECTVERCI", Unmapped_Key, 0x02, 6);
  addKey("PAUSE", Pause_Key, 0x21, 6);
  addKey("RED_IN_THE_MIDDLE", Record_Key, 0x3F, 6);
  addKey("PREV", Rewind_Key, 0x20, 6);
  addKey("PLAY", Play_Key, 0x2B, 6);
  addKey("FFORWARD", FastForward_Key, 0x22, 6);
  addKey("BEGINNING", Previous_Key, 0x23, 6);
  addKey("STOP", Stop_Key, 0x3C, 6);
  addKey("END", Next_Key, 0x24, 6);
  addKey("1", One_Key, 0x0E, 6);
  addKey("2", Two_Key, 0x0F, 6);
  addKey("3", Three_Key, 0x11, 6);
  addKey("4", Four_Key, 0x12, 6);
  addKey("5", Five_Key, 0x14, 6);
  addKey("6", Six_Key, 0x15, 6);
  addKey("7", Seven_Key, 0x17, 6);
  addKey("8", Eight_Key, 0x18, 6);
  addKey("9", Nine_Key, 0x1A, 6);
  addKey("0", Zero_Key, 0x1D, 6);
  addKey("CAPS_NUM", Unmapped_Key, 0x1B, 6);
  addKey("DEL", Unmapped_Key, 0x1E, 6);
}
