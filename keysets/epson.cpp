#include "epson.h"
#include "protocols/necprotocol.h"


EpsonProjector1::EpsonProjector1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Projector Keyset 1",
      Epson_Make,
      index)
{
}


void EpsonProjector1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, false);

  setPreData(0x5583, 16);

  addKey("esc", Exit_Key, 0x84, 8);
  addKey("enter", Select_Key, 0x85, 8);
  addKey("pageup", PageUp_Key, 0x86, 8);
  addKey("pagedown", PageDown_Key, 0x87, 8);
  addKey("zoom+", ChannelUp_Key, 0x88, 8);
  addKey("zoom-", ChannelDown_Key, 0x89, 8);
  addKey("3", Three_Key, 0x8A, 8);
  addKey("0", Zero_Key, 0x8C, 8);
  addKey("6", Six_Key, 0x8F, 8);

  addKey("power", Power_Key, 0x90, 8);
  addKey("9", Nine_Key, 0x92, 8);
  addKey("8", Eight_Key, 0x93, 8);
  addKey("4", Four_Key, 0x94, 8);
  addKey("5", Five_Key, 0x95, 8);
  addKey("2", Two_Key, 0x96, 8);
  addKey("1", One_Key, 0x97, 8);
  addKey("vol+", VolumeUp_Key, 0x98, 8);
  addKey("vol-", VolumeDown_Key, 0x99, 8);
  addKey("menu", Menu_Key, 0x9A, 8);
  addKey("7", Seven_Key, 0x9B, 8);
  addKey("?", Guide_Key, 0x9F, 8);

  addKey("up", Up_Key, 0xB0, 8);
  addKey("right", Right_Key, 0xB1, 8);
  addKey("down", Down_Key, 0xB2, 8);
  addKey("left", Left_Key, 0xB3, 8);
}


// I'm not making this one a subset, it's just too different:
EpsonProjector2::EpsonProjector2(
  unsigned int index)
  : PIRKeysetMetaData(
      "Projector Keyset 2",
      Epson_Make,
      index)
{
}


void EpsonProjector2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, false);

  setPreData(0x5583, 16);

  addKey("ASPECT", AspectRatio_Key, 0x8A, 8);
  addKey("ESC", Exit_Key, 0x84, 8);
  addKey("SELECT", Select_Key, 0x85, 8);
  addKey("MEMORY", Memory_Key, 0x8B, 8);
  addKey("COLOR-MODE", PictureMode_Key, 0x8F, 8);

  addKey("POWER", Power_Key, 0x90, 8);
  addKey("PAUSE", Pause_Key, 0x92, 8);
  addKey("MUTE", Mute_Key, 0x93, 8);
  addKey("MENU", Menu_Key, 0x9A, 8);
  addKey("VIDEO", Unmapped_Key, 0x9C, 8);
  addKey("INPUT-A-B", Unmapped_Key, 0x9D, 8);
  addKey("AUTO", Info_Key, 0x9E, 8); // bit of a hack

  addKey("UP", Up_Key, 0xB0, 8);
  addKey("RIGHT", Right_Key, 0xB1, 8);
  addKey("DOWN", Down_Key, 0xB2, 8);
  addKey("LEFT", Left_Key, 0xB3, 8);
}
