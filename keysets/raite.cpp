#include "raite.h"
#include "necprotocol.h"

RaiteDVD1::RaiteDVD1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Raite_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index);

  setPreData(0x04FB, 16);

  addKey("mute", Mute_Key, 0xC03F, 16);
  addKey("1", One_Key, 0xC837, 16);
  addKey("2", Two_Key, 0x08F7, 16);
  addKey("3", Three_Key, 0x8877, 16);
  addKey("4", Four_Key, 0xF00F, 16);
  addKey("5", Five_Key, 0x30CF, 16);
  addKey("6", Six_Key, 0xB04F, 16);
  addKey("7", Seven_Key, 0xD02F, 16);
  addKey("8", Eight_Key, 0x10EF, 16);
  addKey("9", Nine_Key, 0x906F, 16);
  addKey("0", Zero_Key, 0x926D, 16);
  addKey("+10", DoubleDigit_Key, 0xB24D, 16);
  addKey("stop", Stop_Key, 0x8A75, 16);
  addKey("+v", VolumeUp_Key, 0xAA55, 16); // might be wrong
  addKey("-v", VolumeDown_Key, 0xA857, 16); // also might be wrong
  addKey("a-b", Unmapped_Key, 0xE817, 16);
  addKey("1/all", Unmapped_Key, 0x28D7, 16);
  addKey("rew", Rewind_Key, 0xD827, 16);
  addKey("ff", FastForward_Key, 0x18E7, 16);
  addKey("back", Previous_Key, 0x9867, 16);
  addKey("forward", Next_Key, 0x9A65, 16);
  addKey("slow", Unmapped_Key, 0xF807, 16);
  addKey("pause", Pause_Key, 0xBA45, 16);
  addKey("play", Play_Key, 0x3AC5, 16);
  addKey("up", Up_Key, 0x22DD, 16);
  addKey("down", Down_Key, 0xB847, 16);
  addKey("right", Right_Key, 0x12ED, 16);
  addKey("left", Left_Key, 0x38C7, 16);
  addKey("menu", DiscMenu_Key, 0x609F, 16); // "Menu/Return"
  addKey("zoom", Unmapped_Key, 0x7887, 16);
  addKey("setup", Menu_Key, 0x40BF, 16);
  addKey("title", DiscTitle_Key, 0x02FD, 16);
  addKey("resume", Unmapped_Key, 0x50AF, 16);
  addKey("sub-title", Captions_Key, 0x48B7, 16);
  addKey("t/c_search", Unmapped_Key, 0x0AF5, 16);
  addKey("angle", Unmapped_Key, 0x2AD5, 16);
  addKey("language", Language_Key, 0x6897, 16);
  addKey("power", Power_Key, 0x708F, 16);
  addKey("pbc", Unmapped_Key, 0x32CD, 16);
  addKey("display", Info_Key, 0x1AE5, 16);
  addKey("open/close", Eject_Key, 0x58A7, 16);
  addKey("program", Program_Key, 0x827D, 16);
  addKey("vocal-assist", Unmapped_Key, 0x807F, 16);
}
