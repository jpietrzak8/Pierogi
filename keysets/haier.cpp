#include "haier.h"
#include "protocols/aiwaprotocol.h"

HaierTV1::HaierTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Haier_Make,
      index)
{
  addControlledDevice(Haier_Make, "TN201AUV", TV_Device);
}


void HaierTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new AiwaProtocol(guiObject, index);

  setPreData(0x011C, 13);

  addKey("1", One_Key, 0x00, 8);
  addKey("2", Two_Key, 0x01, 8);
  addKey("3", Three_Key, 0x02, 8);
  addKey("4", Four_Key, 0x03, 8);
  addKey("5", Five_Key, 0x04, 8);
  addKey("6", Six_Key, 0x05, 8);
  addKey("7", Seven_Key, 0x06, 8);
  addKey("8", Eight_Key, 0x07, 8);
  addKey("9", Nine_Key, 0x08, 8);
  addKey("0", Zero_Key, 0x09, 8);
  addKey("last (prev ch)", PrevChannel_Key, 0x0E, 8);
  addKey("menu", Menu_Key, 0x0D, 8);
  addKey("tv/av", Input_Key, 0x0F, 8);

  addKey("vol up", VolumeUp_Key, 0x10, 8); // "right arrow"
  addKey("vol up", Right_Key, 0x10, 8); // "right arrow"
  addKey("power", Power_Key, 0x12, 8);
  addKey("channel up", ChannelUp_Key, 0x13, 8); // "up arrow"
  addKey("channel up", Up_Key, 0x13, 8); // "up arrow"
  addKey("vol down", VolumeDown_Key, 0x14, 8); // "left arrow"
  addKey("vol down", Left_Key, 0x14, 8); // "left arrow"
  addKey("mute", Mute_Key, 0x16, 8);
  addKey("channel down", ChannelDown_Key, 0x17, 8); // "down arrow"
  addKey("channel down", Down_Key, 0x17, 8); // "down arrow"
  addKey("display", Info_Key, 0x18, 8);
  addKey("rating", Unmapped_Key, 0x1B, 8);
}
