#include "proview.h"
#include "protocols/necprotocol.h"

ProviewDVD1::ProviewDVD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Proview_Make,
      index)
{
  addControlledDevice(Proview_Make, "DVP816", DVD_Device);
}


void ProviewDVD1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x00, 8);

  addKey("0", Zero_Key, 0x19, 8);
  addKey("1", One_Key, 0x0C, 8);
  addKey("2", Two_Key, 0x0D, 8);
  addKey("3", Three_Key, 0x0E, 8);
  addKey("4", Four_Key, 0x10, 8);
  addKey("5", Five_Key, 0x11, 8);
  addKey("6", Six_Key, 0x12, 8);
  addKey("7", Seven_Key, 0x14, 8);
  addKey("8", Eight_Key, 0x15, 8);
  addKey("9", Nine_Key, 0x16, 8);
  addKey("vol up", VolumeUp_Key, 0x50, 8);
  addKey("vol down", VolumeDown_Key, 0x51, 8);
  addKey("mute", Mute_Key, 0x00, 8);
  addKey("power", Power_Key, 0x03, 8);
  addKey("menu", Menu_Key, 0x5E, 8);
  addKey("program/guide", Guide_Key, 0x54, 8);
  addKey("exit", Exit_Key, 0x56, 8);
  addKey("up arrow", Up_Key, 0x5D, 8);
  addKey("down arrow", Down_Key, 0x55, 8);
  addKey("left arrow", Left_Key, 0x58, 8);
  addKey("right arrow", Right_Key, 0x5A, 8);
  addKey("enter", Enter_Key, 0x59, 8);
  addKey("ok", Select_Key, 0x59, 8);
  addKey("play", Play_Key, 0x59, 8);
  addKey("pause", Pause_Key, 0x1E, 8);
  addKey("rewind", Rewind_Key, 0x48, 8);
  addKey("fast fwd", FastForward_Key, 0x44, 8);
  addKey("stop", Stop_Key, 0x1D, 8);
  addKey("record", Record_Key, 0x07, 8);
  addKey("f.fwd/next track", Next_Key, 0x49, 8);
  addKey("f.fwd/prev track", Previous_Key, 0x45, 8);
  addKey("+100", PlusOneHundred_Key, 0x18, 8);
  addKey("slow", Slow_Key, 0x4D, 8);
  addKey("advance", Advance_Key, 0x07, 8);
}
