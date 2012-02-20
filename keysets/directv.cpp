#include "directv.h"
#include "protocols/directvprotocol.h"


// Note: volume keys are tricky!
DirectvReceiver1::DirectvReceiver1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Sat Keyset 1",
      Directv_Make,
      index)
{
}


void DirectvReceiver1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new DirectvProtocol(guiObject, index, LowFreq, true);

  setPreData(0xC, 4);

  addKey("1", One_Key, 0x01, 8);
  addKey("2", Two_Key, 0x02, 8);
  addKey("3", Three_Key, 0x03, 8);
  addKey("4", Four_Key, 0x04, 8);
  addKey("5", Five_Key, 0x05, 8);
  addKey("6", Six_Key, 0x06, 8);
  addKey("7", Seven_Key, 0x07, 8);
  addKey("8", Eight_Key, 0x08, 8);
  addKey("9", Nine_Key, 0x09, 8);
  addKey("Chan+", ChannelUp_Key, 0x0D, 8);
  addKey("Chan-", ChannelDown_Key, 0x0E, 8);
  addKey("Previous", PrevChannel_Key, 0xF, 8); // "last"

  addKey("Power", Power_Key, 0x10, 8);
  addKey("0", Zero_Key, 0x11, 8);
  addKey("Dash", Dash_Key, 0x12, 8);
  addKey("Enter", Enter_Key, 0x13, 8);

  addKey("Menu", Menu_Key, 0x20, 8); // "alt menu"
  addKey("Up", Up_Key, 0x21, 8);
  addKey("Down", Down_Key, 0x22, 8);
  addKey("Left", Left_Key, 0x23, 8);
  addKey("Right", Right_Key, 0x24, 8);
  addKey("Select", Select_Key, 0x25, 8);
  addKey("Exit", Exit_Key, 0x26, 8);
  addKey("Back", Unmapped_Key, 0x27, 8);
  addKey("Guide", Guide_Key, 0x28, 8);
  addKey("Active", DiscMenu_Key, 0x29, 8); // "menu"
  addKey("List", Unmapped_Key, 0x2A, 8);
  addKey("list-long", Unmapped_Key, 0x2B, 8);
  addKey("info-long", Unmapped_Key, 0x2C, 8);
  addKey("guide-long", Unmapped_Key, 0x2D, 8);
  addKey("Info", Info_Key, 0x2E, 8);

  addKey("Play", Play_Key, 0x30, 8);
  addKey("Stop", Stop_Key, 0x31, 8);
  addKey("Pause", Pause_Key, 0x32, 8);
  addKey("Rewind", Rewind_Key, 0x33, 8);
  addKey("Forward", FastForward_Key, 0x34, 8);
  addKey("Record", Record_Key, 0x35, 8);
  addKey("Replay", Replay_Key, 0x36, 8);
  addKey("Skip", Advance_Key, 0x37, 8);
  addKey("skip-forward-long", Unmapped_Key, 0x38, 8);
  addKey("play-long", Unmapped_Key, 0x3A, 8);
  addKey("pause-long", Unmapped_Key, 0x3B, 8);
  addKey("rewind-long", Unmapped_Key, 0x3C, 8);
  addKey("forward-long", Unmapped_Key, 0x3D, 8);
  addKey("record-long", Unmapped_Key, 0x3E, 8);
  addKey("skip-back-long", Unmapped_Key, 0x3F, 8);

  addKey("Red", Red_Key, 0x41, 8);
  addKey("Yellow", Yellow_Key, 0x42, 8);
  addKey("Green", Green_Key, 0x43, 8);
  addKey("Blue", Blue_Key, 0x44, 8);
  addKey("pip on/off", PIP_Key, 0x47, 8);
  addKey("pip swap", PIPSwap_Key, 0x48, 8);
  addKey("red-long", Unmapped_Key, 0x4A, 8);
  addKey("yellow-long", Unmapped_Key, 0x4B, 8);
  addKey("green-long", Unmapped_Key, 0x4C, 8);
  addKey("blue-long", Unmapped_Key, 0x4D, 8);

  addKey("tv/vcr", Input_Key, 0x5B, 8);

  addKey("format", Unmapped_Key, 0x73, 8);
  addKey("format-long", Unmapped_Key, 0x75, 8);

  addKey("On", PowerOn_Key, 0x80, 8);
  addKey("Off", PowerOff_Key, 0x81, 8);
}
