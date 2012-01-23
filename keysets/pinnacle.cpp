#include "pinnacle.h"
#include "rc5protocol.h"

PinnaclePCTV1::PinnaclePCTV1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "PCTV Keyset 1",
      Pinnacle_Make,
      index)
{
  addControlledDevice(Pinnacle_Make, "800i", Computer_Device);

  RC5Protocol *rp = new RC5Protocol(
    guiObject,
    index,
    900, 900,
    900,
    114000, true);

  threadableProtocol = rp;

  rp->setToggleBit(2);

  setPreData(0x11, 5);

  addKey("key_mute", Mute_Key, 0xC0, 8);
  addKey("key_menu", Menu_Key, 0xC1, 8);
  addKey("key_power", Power_Key, 0xF9, 8);
  addKey("key_volumeup", VolumeUp_Key, 0xC3, 8);
  addKey("key_volumedown", VolumeDown_Key, 0xC9, 8);
  addKey("key_channelup", ChannelUp_Key, 0xC6, 8);
  addKey("key_channeldown", ChannelDown_Key, 0xCC, 8);
  addKey("btn_1", One_Key, 0xCF, 8);
  addKey("btn_2", Two_Key, 0xD5, 8);
  addKey("btn_3", Three_Key, 0xD0, 8);
  addKey("btn_4", Four_Key, 0xD8, 8);
  addKey("btn_5", Five_Key, 0xDB, 8);
  addKey("btn_6", Six_Key, 0xDE, 8);
  addKey("btn_7", Seven_Key, 0xD1, 8);
  addKey("btn_8", Eight_Key, 0xE1, 8);
  addKey("btn_9", Nine_Key, 0xD2, 8);
  addKey("btn_0", Zero_Key, 0xE7, 8);
  addKey("key_screen", Unmapped_Key, 0xE4, 8);
  addKey("key_t", Unmapped_Key, 0xEA, 8);
  addKey("key_rewind", Rewind_Key, 0xED, 8);
  addKey("key_playpause", Play_Key, 0xF0, 8);
  addKey("key_playpause", Pause_Key, 0xF0, 8);
  addKey("key_fastforward", FastForward_Key, 0xF3, 8);
  addKey("key_record", Record_Key, 0xF6, 8);
  addKey("key_stop", Stop_Key, 0xFC, 8);
  addKey("key_question", Unmapped_Key, 0xFF, 8);
}


PinnaclePCTV2::PinnaclePCTV2(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "PCTV Keyset 2",
      Pinnacle_Make,
      index)
{
  addControlledDevice(Pinnacle_Make, "USB Stick", Computer_Device);

  RC5Protocol *rp = new RC5Protocol(
    guiObject,
    index,
    900, 900,
    900,
    114000, true);

  threadableProtocol = rp;

  rp->setToggleBit(2);

  setPreData(0x11, 5);

  addKey("play-pause", Play_Key, 0xC6, 8);
  addKey("play-pause", Pause_Key, 0xC6, 8);
  addKey("stop", Stop_Key, 0xC5, 8);
  addKey("exit", Exit_Key, 0xC3, 8);
  addKey("screen", Unmapped_Key, 0xC2, 8);
  addKey("rew", Rewind_Key, 0xC4, 8);
  addKey("ff", FastForward_Key, 0xC7, 8);
  addKey("mute", Mute_Key, 0xC0, 8);
  addKey("volup", VolumeUp_Key, 0xCB, 8);
  addKey("voldown", VolumeDown_Key, 0xCF, 8);
  addKey("ask", Unmapped_Key, 0xD4, 8);
  addKey("m", Unmapped_Key, 0xD6, 8);
  addKey("chup", ChannelUp_Key, 0xD3, 8);
  addKey("chdown", ChannelDown_Key, 0xD7, 8);
  addKey("rec", Record_Key, 0xC1, 8);
  addKey("1", One_Key, 0xC8, 8);
  addKey("2", Two_Key, 0xC9, 8);
  addKey("3", Three_Key, 0xCA, 8);
  addKey("4", Four_Key, 0xCC, 8);
  addKey("5", Five_Key, 0xCD, 8);
  addKey("6", Six_Key, 0xCE, 8);
  addKey("7", Seven_Key, 0xD0, 8);
  addKey("8", Eight_Key, 0xD1, 8);
  addKey("9", Nine_Key, 0xD2, 8);
  addKey("0", Zero_Key, 0xD5, 8);
}


PinnaclePCTV3::PinnaclePCTV3(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "PCTV Keyset 3",
      Pinnacle_Make,
      index)
{
  addControlledDevice(Pinnacle_Make, "110i", Computer_Device);

  RC5Protocol *rp = new RC5Protocol(
    guiObject,
    index,
    900, 900,
    900,
    114000, true);

  threadableProtocol = rp;

  rp->setToggleBit(2);

  setPreData(0x11, 5);

  addKey("MUTE", Mute_Key, 0xC1, 8);
  addKey("POWER", Power_Key, 0xF9, 8);
  addKey("CTVERECSETREMIRADKY", Unmapped_Key, 0xE5, 8);
  addKey("TV", Unmapped_Key, 0xE6, 8);
  addKey("EPG", Guide_Key, 0xE7, 8);
  addKey("A_RED", Red_Key, 0xC3, 8);
  addKey("B_GREEN", Green_Key, 0xC4, 8);
  addKey("C_YELLOW", Yellow_Key, 0xC5, 8);
  addKey("OTAZNIK_BLUE", Blue_Key, 0xC6, 8);
  addKey("VOL_PLUS", VolumeUp_Key, 0xE8, 8);
  addKey("VOL_MINUS", VolumeDown_Key, 0xE9, 8);
  addKey("PINNACLE", Unmapped_Key, 0xF3, 8);
  addKey("CH_PLUS", ChannelUp_Key, 0xC8, 8);
  addKey("CH_MINUS", ChannelDown_Key, 0xC9, 8);
  addKey("UP", Up_Key, 0xCA, 8);
  addKey("LEFT", Left_Key, 0xCC, 8);
  addKey("OK", Select_Key, 0xF6, 8);
  addKey("RIGHT", Right_Key, 0xCD, 8);
  addKey("DOWN", Down_Key, 0xCB, 8);
  addKey("BACK", Exit_Key, 0xF0, 8);
  addKey("JUMP", PrevChannel_Key, 0xEA, 8);
  addKey("CTVERECVECTVERCI", Unmapped_Key, 0xC2, 8);
  addKey("PAUSE", Pause_Key, 0xE1, 8);
  addKey("RED_IN_THE_MIDDLE", Record_Key, 0xFF, 8);
  addKey("PREV", Rewind_Key, 0xE0, 8);
  addKey("PLAY", Play_Key, 0xEB, 8);
  addKey("FFORWARD", FastForward_Key, 0xE2, 8);
  addKey("BEGINNING", Previous_Key, 0xE3, 8);
  addKey("STOP", Stop_Key, 0xFC, 8);
  addKey("END", Next_Key, 0xE4, 8);
  addKey("1", One_Key, 0xCE, 8);
  addKey("2", Two_Key, 0xCF, 8);
  addKey("3", Three_Key, 0xD1, 8);
  addKey("4", Four_Key, 0xD2, 8);
  addKey("5", Five_Key, 0xD4, 8);
  addKey("6", Six_Key, 0xD5, 8);
  addKey("7", Seven_Key, 0xD7, 8);
  addKey("8", Eight_Key, 0xD8, 8);
  addKey("9", Nine_Key, 0xDA, 8);
  addKey("0", Zero_Key, 0xDD, 8);
  addKey("CAPS_NUM", Unmapped_Key, 0xDB, 8);
  addKey("DEL", Unmapped_Key, 0xDE, 8);
}
