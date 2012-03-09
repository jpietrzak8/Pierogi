#include "xcruiser.h"
#include "protocols/necprotocol.h"


XcruiserSat1::XcruiserSat1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Sat Keyset 1",
      Xcruiser_Make,
      index)
{
}


void XcruiserSat1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x08, 8);

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
  addKey("PowerToggle", Power_Key, 0x0A, 8);
  addKey("Mute", Mute_Key, 0x0B, 8);
  addKey("TvRadio", Input_Key, 0x0C, 8);
  addKey("ChannelPrev", PrevChannel_Key, 0x0D, 8);
  addKey("Menu", Menu_Key, 0x0E, 8);
  addKey("Advance", Advance_Key, 0x0F, 8);
  addKey("Info", Info_Key, 0x10, 8);
  addKey("ChannelUp", ChannelUp_Key, 0x11, 8);
  addKey("DirectionUp", Up_Key, 0x11, 8);
  addKey("ChannelDown", ChannelDown_Key, 0x12, 8);
  addKey("DirectionDown", Down_Key, 0x12, 8);
  addKey("VolumeDown", VolumeDown_Key, 0x13, 8);
  addKey("DirectionLeft", Left_Key, 0x13, 8);
  addKey("VolumeUp", VolumeUp_Key, 0x14, 8);
  addKey("DirectionRight", Right_Key, 0x14, 8);
  addKey("Select/Ok", Select_Key, 0x15, 8);
  addKey("Exit", Exit_Key, 0x16, 8);
  addKey("Replay", Replay_Key, 0x17, 8);
  addKey("Guide", Guide_Key, 0x18, 8);
  addKey("Pause", Pause_Key, 0x19, 8);
  addKey("LRAudio", Surround_Key, 0x1A, 8);
  addKey("AltAudio", Audio_Key, 0x1B, 8);
  addKey("Text", Teletext_Key, 0x1C, 8);
  addKey("Favourite", Favorites_Key, 0x20, 8);
  addKey("Rewind", Rewind_Key, 0x22, 8);
  addKey("Play", Play_Key, 0x23, 8);
  addKey("FastForward", FastForward_Key, 0x24, 8);
  addKey("Stop", Stop_Key, 0x26, 8);
  addKey("Record", Record_Key, 0x27, 8);
}
