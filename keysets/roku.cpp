#include "roku.h"
#include "protocols/necprotocol.h"

RokuBox1::RokuBox1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Settop Box Keyset 1",
      Roku_Make,
      index)
{
}


void RokuBox1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, false);

  setPreData(0xEFBE, 16);

  addKey("Home", Menu_Key, 0x00, 8);
  addKey("Up", Up_Key, 0x01, 8);
  addKey("Back", Left_Key, 0x02, 8);
  addKey("Select", Select_Key, 0x03, 8);
  addKey("Forward", Right_Key, 0x04, 8);
  addKey("Down", Down_Key, 0x05, 8);
  addKey("FastRev", Rewind_Key, 0x06, 8);
  addKey("Start/Pause", Play_Key, 0x07, 8);
  addKey("Start/Pause", Pause_Key, 0x07, 8);
  addKey("FastFWD", FastForward_Key, 0x08, 8);
}


RokuBox2::RokuBox2(
  unsigned int index)
  : PIRKeysetMetaData(
      "Soundbridge Keyset 1",
      Roku_Make,
      index)
{
}


void RokuBox2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x6F, 8);

  addKey("left", Left_Key, 0x10, 8);
  addKey("right", Right_Key, 0x11, 8);
  addKey("up", Up_Key, 0x12, 8);
  addKey("down", Down_Key, 0x13, 8);
  addKey("select", Select_Key, 0x14, 8);
  addKey("exit", Exit_Key, 0x15, 8);
  addKey("power", Power_Key, 0x16, 8);
  addKey("menu", Menu_Key, 0x17, 8);
  addKey("search", Unmapped_Key, 0x18, 8);
  addKey("play", Play_Key, 0x19, 8);
  addKey("next", Next_Key, 0x1A, 8);
  addKey("prev", Previous_Key, 0x1B, 8);
  addKey("pause", Pause_Key, 0x1C, 8);
  addKey("add", Unmapped_Key, 0x1D, 8);
  addKey("shuffle", Random_Key, 0x1E, 8);
  addKey("repeat", Repeat_Key, 0x1F, 8);

  addKey("volume_up", VolumeUp_Key, 0x40, 8);
  addKey("volume_down", VolumeDown_Key, 0x41, 8);
  addKey("bright", Unmapped_Key, 0x42, 8);
  addKey("power_on", PowerOn_Key, 0x43, 8);
  addKey("power_off", PowerOff_Key, 0x44, 8);
  addKey("user1", Unmapped_Key, 0x45, 8);
  addKey("user2", Unmapped_Key, 0x46, 8);
  addKey("user3", Unmapped_Key, 0x47, 8);
  addKey("user4", Unmapped_Key, 0x48, 8);
  addKey("user5", Unmapped_Key, 0x49, 8);
  addKey("user6", Unmapped_Key, 0x4A, 8);
}
