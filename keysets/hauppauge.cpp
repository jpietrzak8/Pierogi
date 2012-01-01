#include "hauppauge.h"
#include "rc5protocol.h"

HauppaugeGeneric::HauppaugeGeneric(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Generic Remote",
      Hauppauge_Make,
      index)
{
  RC5Protocol *rp = new RC5Protocol(
    guiObject,
    index,
    950, 820,     // biphase pulse
    1000,         // lead pulse
    114000, true); // constant-length gap

  threadableProtocol = rp;

  rp->setPreData(0x17, 5);

  rp->setToggleBit(2);

  addKey("Power", Power_Key, 0xBD, 8);
  addKey("Go", Unmapped_Key, 0xBB, 8);
  addKey("TV", Unmapped_Key, 0x9C, 8);
  addKey("Videos", Unmapped_Key, 0x98, 8);
  addKey("Music", Unmapped_Key, 0x99, 8);
  addKey("Pictures", Unmapped_Key, 0x9A, 8);
  addKey("Guide", Unmapped_Key, 0x9B, 8);
  addKey("Radio", Unmapped_Key, 0x8C, 8);
  addKey("Up", Up_Key, 0x94, 8);
  addKey("Down", Down_Key, 0x95, 8);
  addKey("Left", Left_Key, 0x96, 8);
  addKey("Right", Right_Key, 0x97, 8);
  addKey("Ok", Enter_Key, 0xA5, 8);
  addKey("Ok", Select_Key, 0xA5, 8);
  addKey("Back/Exit", Exit_Key, 0x9F, 8);
  addKey("Menu/i", Menu_Key, 0x8D, 8);
  addKey("Vol+", VolumeUp_Key, 0x90, 8);
  addKey("Vol-", VolumeDown_Key, 0x91, 8);
  addKey("Prev.Ch", PrevChannel_Key, 0x92, 8);
  addKey("Mute", Mute_Key, 0x8F, 8);
  addKey("Ch+", ChannelUp_Key, 0xA0, 8);
  addKey("Ch-", ChannelDown_Key, 0xA1, 8);
  addKey("Record", Record_Key, 0xB7, 8);
  addKey("Stop", Stop_Key, 0xB6, 8);
  addKey("Rewind", Rewind_Key, 0xB2, 8);
  addKey("Play", Play_Key, 0xB5, 8);
  addKey("Forward", FastForward_Key, 0xB4, 8);
  addKey("Replay/SkipBackward", Replay_Key, 0xA4, 8);
  addKey("Pause", Pause_Key, 0xB0, 8);
  addKey("SkipForward", Advance_Key, 0x9E, 8);
  addKey("1", One_Key, 0x81, 8);
  addKey("2", Two_Key, 0x82, 8);
  addKey("3", Three_Key, 0x83, 8);
  addKey("4", Four_Key, 0x84, 8);
  addKey("5", Five_Key, 0x85, 8);
  addKey("6", Six_Key, 0x86, 8);
  addKey("7", Seven_Key, 0x87, 8);
  addKey("8", Eight_Key, 0x88, 8);
  addKey("9", Nine_Key, 0x89, 8);
  addKey("0", Zero_Key, 0x80, 8);
  addKey("Asterix", Unmapped_Key, 0x8A, 8);
  addKey("sub/cc", Captions_Key, 0x8E, 8);
  addKey("Red", Red_Key, 0x8B, 8);
  addKey("Green", Green_Key, 0xAE, 8);
  addKey("Yellow", Yellow_Key, 0xB8, 8);
  addKey("Blue", Blue_Key, 0xA9, 8);
}


// Based on LIRC Sony_RM-V302-DVD010 config file
HauppaugeTV1::HauppaugeTV1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Hauppauge_Make,
      index)
{
  addControlledDevice(Hauppauge_Make, "PVR-250", TV_Device);

  RC5Protocol *rp = new RC5Protocol(
    guiObject,
    index,
    889, 889,
    889,
    113792, true);

  threadableProtocol = rp;

  rp->setToggleBit(2);

  addKey("POWER", Power_Key, 0x150C, 13);
  addKey("1", One_Key, 0x1525, 13);
  addKey("2", Two_Key, 0x1526, 13);
  addKey("3", Three_Key, 0x1527, 13);
  addKey("4", Four_Key, 0x1519, 13);
  addKey("5", Five_Key, 0x153D, 13);
  addKey("6", Six_Key, 0x1516, 13);
  addKey("7", Seven_Key, 0x1517, 13);
  addKey("8", Eight_Key, 0x1518, 13);
  addKey("9", Nine_Key, 0x152B, 13);
  addKey("0", Zero_Key, 0x151D, 13);
  addKey("VOL+", VolumeUp_Key, 0x1810, 13);
  addKey("VOL-", VolumeDown_Key, 0x1811, 13);
  addKey("CH+", ChannelUp_Key, 0x1534, 13);
  addKey("CH-", ChannelDown_Key, 0x1533, 13);
  addKey("TV/VIDEO", Input_Key, 0x1500, 13);
  addKey("DISPLAY", Info_Key, 0x1532, 13);
  addKey("SLEEP", Sleep_Key, 0x1510, 13);
  addKey("MUTE", Mute_Key, 0x180D, 13);
  addKey("RECALL", PrevChannel_Key, 0x1501, 13);
  addKey("UP", Up_Key, 0x1502, 13);
  addKey("DOWN", Down_Key, 0x1508, 13);
  addKey("LEFT", Left_Key, 0x1504, 13);
  addKey("RIGHT", Right_Key, 0x1506, 13);
  addKey("MENU", Menu_Key, 0x1503, 13);
  addKey("OK", Enter_Key, 0x1505, 13);
  addKey("OK", Select_Key, 0x1505, 13);
  addKey("SEEK-", Rewind_Key, 0x1535, 13);
  addKey("PLAY", Play_Key, 0x1530, 13);
  addKey("SEEK+", FastForward_Key, 0x1536, 13);
  addKey("PAUSE", Pause_Key, 0x153C, 13);
  addKey("STOP", Stop_Key, 0x1520, 13);
}

