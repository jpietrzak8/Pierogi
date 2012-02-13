#include "sky.h"
#include "protocols/rc6skyprotocol.h"

SkyReceiver1::SkyReceiver1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Receiver Keyset 1",
      Sky_Make,
      index)
{
  threadableProtocol = new RC6SkyProtocol(guiObject, index);

  setPreData(0x000, 12);

  addKey("0", Zero_Key, 0x00, 8);
  addKey("1", One_Key, 0x01, 8);
  addKey("2", Two_Key, 0x02, 8);
  addKey("3", Three_Key, 0x03, 8);
  addKey("4", Four_Key, 0x04, 8);
  addKey("5", Five_Key, 0x05, 8);
  addKey("6", Six_Key, 0x06, 8);
  addKey("7", Seven_Key, 0x07, 8);
  addKey("8", Eight_Key, 0x08, 8);
  addKey("9", Nine_Key, 0x09, 8);
  addKey("POWER", Power_Key, 0x0C, 8);

  addKey("CH+", ChannelUp_Key, 0x20, 8);
  addKey("CH-", ChannelDown_Key, 0x21, 8);
  addKey("PAUSE", Pause_Key, 0x24, 8);
  addKey("FFW", FastForward_Key, 0x28, 8);

  addKey("TEXT", Teletext_Key, 0x3C, 8); // is this right?
  addKey("REW", Rewind_Key, 0x3D, 8);
  addKey("PLAY", Play_Key, 0x3E, 8);
  addKey("STOP", Stop_Key, 0x3F, 8);
  addKey("REC", Record_Key, 0x40, 8);

  addKey("UP", Up_Key, 0x58, 8);
  addKey("DOWN", Down_Key, 0x59, 8);
  addKey("LEFT", Left_Key, 0x5A, 8);
  addKey("RIGHT", Right_Key, 0x5B, 8);
  addKey("SELECT", Select_Key, 0x5C, 8);

  addKey("RED", Red_Key, 0x6D, 8);
  addKey("GREEN", Green_Key, 0x6E, 8);
  addKey("YELLOW", Yellow_Key, 0x6F, 8);
  addKey("BLUE", Blue_Key, 0x70, 8);

  addKey("BOX_OFFICE", Unmapped_Key, 0x7D, 8);
  addKey("SERVICES", Menu_Key, 0x7E, 8); // ?

  addKey("SKY", Unmapped_Key, 0x80, 8);
  addKey("HELP", Unmapped_Key, 0x81, 8); // menu?
  addKey("BACK", Exit_Key, 0x83, 8);
  addKey("TV", Unmapped_Key, 0x84, 8);

  addKey("INFO", Info_Key, 0xCB, 8);
  addKey("TV_GUIDE", Guide_Key, 0xCC, 8);

  addKey("INTERACTIVE", Unmapped_Key, 0xF5, 8);
}


SkyReceiver1a::SkyReceiver1a(
  QObject *guiObject,
  unsigned int index)
  : SkyReceiver1(guiObject, index)
{
  setKeysetName("Receiver Keyset 1a");

  setPreData(0x00C, 12);
}
