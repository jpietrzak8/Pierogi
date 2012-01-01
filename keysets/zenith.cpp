#include "zenith.h"
#include "necprotocol.h"

// Based solely on LIRC Zenith_C32V37 config file
ZenithC32V37::ZenithC32V37(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "C32V37 TV",
      Zenith_Make,
      index)
{
  addControlledDevice(Zenith_Make, "C32V37", TV_Device);

  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    581, 528,
    581, 1663,
    106773, true);

  threadableProtocol = np;

  np->setHeaderPair(9000, 4500);
  np->setTrailerPulse(581);
  np->setRepeatPair(9000, 2250);

  np->setPreData(0x20DF, 16);

  addKey("power", Power_Key, 0x10EF, 16);
  addKey("tv/video", Input_Key, 0xD02F, 16);
  addKey("front", Unmapped_Key, 0x8A75, 16);
  addKey("comp/dvi", Unmapped_Key, 0x19E6, 16);
  addKey("ratio", Unmapped_Key, 0x9E61, 16);
  addKey("signal", Unmapped_Key, 0x6996, 16);
  addKey("freeze", Unmapped_Key, 0xA659, 16);
  addKey("1", One_Key, 0x8877, 16);
  addKey("2", Two_Key, 0x48B7, 16);
  addKey("3", Three_Key, 0xC837, 16);
  addKey("4", Four_Key, 0x28D7, 16);
  addKey("5", Five_Key, 0xA857, 16);
  addKey("6", Six_Key, 0x6897, 16);
  addKey("7", Seven_Key, 0xE817, 16);
  addKey("8", Eight_Key, 0x18E7, 16);
  addKey("9", Nine_Key, 0x9867, 16);
  addKey("0", Zero_Key, 0x08F7, 16);
  addKey("dash", Dash_Key, 0x32CD, 16);
  addKey("flashbk", Unmapped_Key, 0x58A7, 16);
  addKey("mute", Mute_Key, 0x906F, 16);
  addKey("audio", Unmapped_Key, 0x50AF, 16);
  addKey("VOL_UP", VolumeUp_Key, 0x40BF, 16);
  addKey("VOL_DOWN", VolumeDown_Key, 0xC03F, 16);
  addKey("CH_UP", ChannelUp_Key, 0x00FF, 16);
  addKey("CH_DOWN", ChannelDown_Key, 0x807F, 16);
  addKey("surf", Unmapped_Key, 0x7887, 16);
  addKey("video", Unmapped_Key, 0xB24D, 16);
  addKey("pip", PIP_Key, 0x06F9, 16);
  addKey("pipch-", Unmapped_Key, 0x4EB1, 16);
  addKey("pipch+", Unmapped_Key, 0x8E71, 16);
  addKey("pcin", Unmapped_Key, 0x8679, 16);
  addKey("info", Info_Key, 0x55AA, 16);
  addKey("timer", Unmapped_Key, 0x708F, 16);
  addKey("cc", Captions_Key, 0x9C63, 16);
  addKey("swap", PIPSwap_Key, 0xC639, 16);
  addKey("up", Up_Key, 0x02FD, 16);
  addKey("left", Left_Key, 0xE01F, 16);
  addKey("right", Right_Key, 0x609F, 16);
  addKey("down", Down_Key, 0x827D, 16);
  addKey("menu", Menu_Key, 0xC23D, 16);
  addKey("exit", Exit_Key, 0xDA25, 16);
}
