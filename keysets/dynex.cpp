#include "dynex.h"
#include "protocols/necprotocol.h"


DynexTV1::DynexTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Dynex_Make,
      index)
{
}


void DynexTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, false);

  setPreData(0x0586, 16);

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
  addKey("CHUp", ChannelUp_Key, 0x0A, 8);
  addKey("CHDown", ChannelDown_Key, 0x0B, 8);
  addKey("VolUp", VolumeUp_Key, 0x0C, 8);
  addKey("VolDown", VolumeDown_Key, 0x0D, 8);
  addKey("Mute", Mute_Key, 0x0E, 8);
  addKey("Power", Power_Key, 0x0F, 8);

  addKey("recall", PrevChannel_Key, 0x10, 8);
  addKey("mts/sap", Audio_Key, 0x11, 8);
  addKey("Sleep", Sleep_Key, 0x13, 8);
  addKey("Menu", Menu_Key, 0x14, 8);
  addKey("right arrow", Right_Key, 0x15, 8);
  addKey("left arrow", Left_Key, 0x16, 8);
  addKey("info/display", Info_Key, 0x17, 8);
  addKey("Enter", Select_Key, 0x18, 8);
  addKey("Reset", Reset_Key, 0x19, 8);
  addKey("exit", Exit_Key, 0x1B, 8);
  addKey("ccd", Captions_Key, 0x1C, 8);
  addKey("input", Input_Key, 0x1D, 8);

  addKey("dot(.)", Dash_Key, 0x41, 8);
  addKey("up arrow", Up_Key, 0x42, 8);
  addKey("down arrow", Down_Key, 0x43, 8);
  addKey("zoom", Zoom_Key, 0x44, 8);
  addKey("guide", Guide_Key, 0x45, 8);
  addKey("audio", SoundMode_Key, 0x48, 8);
  addKey("picture", PictureMode_Key, 0x49, 8);
  addKey("favorite", Favorites_Key, 0x4B, 8);
  addKey("comp", PCInput_Key, 0x4D, 8);
  addKey("hdmi", HDMIInput_Key, 0x50, 8);
  addKey("video", AuxInput_Key, 0x4C, 8);
  addKey("tv", AntennaInput_Key, 0x4F, 8);

  addKey("ch-list", Unmapped_Key, 0x86, 8);
}
