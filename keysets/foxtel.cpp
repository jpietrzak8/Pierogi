#include "foxtel.h"
#include "protocols/necprotocol.h"


FoxtelSTB1::FoxtelSTB1(
  unsigned int index)
  : PIRKeysetMetaData(
      "STB Keyset 1",
      Foxtel_Make,
      index)
{
}


void FoxtelSTB1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, false);

  setPreData(0x3C84, 16);

  addKey("5", Five_Key, 0x00, 8);
  addKey("4", Four_Key, 0x01, 8);
  addKey("1", One_Key, 0x02, 8);
  addKey("6", Six_Key, 0x03, 8);
  addKey("Power", Power_Key, 0x04, 8);
  addKey("2", Two_Key, 0x05, 8);
  addKey("Fav", Favorites_Key, 0x06, 8);
  addKey("3", Three_Key, 0x07, 8);
  addKey("9", Nine_Key, 0x08, 8);
  addKey("8", Eight_Key, 0x09, 8);
  addKey("7", Seven_Key, 0x0A, 8);
  addKey("Unknown1", Unmapped_Key, 0x0B, 8);
  addKey("Menu", Menu_Key, 0x0C, 8);
  addKey("up", Up_Key, 0x0D, 8);
  addKey("0", Zero_Key, 0x0E, 8);
  addKey(">", Right_Key, 0x0F, 8);

  addKey("down", Down_Key, 0x10, 8);
  addKey("Info", Info_Key, 0x11, 8);
  addKey("<", Left_Key, 0x12, 8);
  addKey("Unknown2", Unmapped_Key, 0x13, 8);
  addKey("Mute", Mute_Key, 0x14, 8);
  addKey("Exit", Exit_Key, 0x15, 8);
  addKey("Store", Memory_Key, 0x16, 8);
  addKey("Auth", Unmapped_Key, 0x17, 8);
  addKey("Vol+", VolumeUp_Key, 0x18, 8);
  addKey(">-<", Unmapped_Key, 0x19, 8);
  addKey("Unknown3", Unmapped_Key, 0x1A, 8);
  addKey("Prog+", ChannelUp_Key, 0x1B, 8);
  addKey("Vol-", VolumeDown_Key, 0x1C, 8);
  addKey("Ok", Select_Key, 0x1D,8);
  addKey("Unknown4", Unmapped_Key, 0x1E, 8);
  addKey("Prog-", ChannelDown_Key, 0x1F, 8);
}
