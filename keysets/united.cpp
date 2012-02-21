#include "united.h"
#include "protocols/necprotocol.h"


UnitedDVD1::UnitedDVD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      United_Make,
      index)
{
}


void UnitedDVD1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated:
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x00, 8);

  addKey("next", Next_Key, 0x06, 8);
  addKey("prev", Previous_Key, 0x0A, 8);
  addKey("stop", Stop_Key, 0x0B, 8);
  addKey("ffwd", FastForward_Key, 0x0E, 8);
  addKey("enterplay", Select_Key, 0x0F, 8);

  addKey("frev", Rewind_Key, 0x12, 8);
  addKey("playpause", Play_Key, 0x13, 8);
  addKey("playpause", Pause_Key, 0x13, 8);
  addKey("right", Right_Key, 0x14, 8);
  addKey("intro", Unmapped_Key, 0x15, 8);
  addKey("power", Power_Key, 0x16, 8);
  addKey("3", Three_Key, 0x17, 8);
  addKey("setup", Menu_Key, 0x18, 8);
  addKey("down", Down_Key, 0x19, 8);
  addKey("vmode", Unmapped_Key, 0x1A, 8);
  addKey("2", Two_Key, 0x1B, 8);
  addKey("left", Left_Key, 0x1C, 8);
  addKey("clear", Clear_Key, 0x1D, 8);
  addKey("openclose", Eject_Key, 0x1E, 8);
  addKey("1", One_Key, 0x1F, 8);

  addKey("vol+", VolumeUp_Key, 0x44, 8);
  addKey("menu", DiscMenu_Key, 0x45, 8);
  addKey("a-brpt", RepeatAB_Key, 0x46, 8);
  addKey("audio", Audio_Key, 0x47, 8);
  addKey("vol-", VolumeDown_Key, 0x48, 8);
  addKey("title", DiscTitle_Key, 0x49, 8);
  addKey("repeat", Repeat_Key, 0x4A, 8);
  addKey("angle", Angle_Key, 0x4B, 8);
  addKey("sfwd", StepForward_Key, 0x4C, 8);
  addKey("subtitle", Captions_Key, 0x4D, 8);
  addKey("pal_ntsc", Unmapped_Key, 0x4E, 8);
  addKey("dsp", Unmapped_Key, 0x4F, 8);

  addKey("srev", StepBack_Key, 0x50, 8);
  addKey("prog", Program_Key, 0x51, 8);
  addKey("zoom", Zoom_Key, 0x52, 8);
  addKey("mute", Mute_Key, 0x53, 8);
  addKey("6", Six_Key, 0x54, 8);
  addKey("9", Nine_Key, 0x55, 8);
  addKey("search", Unmapped_Key, 0x56, 8);
  addKey("equ", Unmapped_Key, 0x57, 8);
  addKey("5", Five_Key, 0x58, 8);
  addKey("8", Eight_Key, 0x59, 8);
  addKey("10+", DoubleDigit_Key, 0x5A, 8);
  addKey("up", Up_Key, 0x5B, 8);
  addKey("4", Four_Key, 0x5C, 8);
  addKey("7", Seven_Key, 0x5D, 8);
  addKey("0", Zero_Key, 0x5E, 8);
  addKey("osd", Info_Key, 0x5F, 8);
}


UnitedDVBT1::UnitedDVBT1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVBT Keyset 1",
      United_Make,
      index)
{
}


void UnitedDVBT1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated:
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x04, 8);

  addKey("power", Power_Key, 0x1A, 8);
  addKey("0", Zero_Key, 0x47, 8);
  addKey("1", One_Key, 0x13, 8);
  addKey("2", Two_Key, 0x10, 8);
  addKey("3", Three_Key, 0x11, 8);
  addKey("4", Four_Key, 0x0F, 8);
  addKey("5", Five_Key, 0x0C, 8);
  addKey("6", Six_Key, 0x0D, 8);
  addKey("7", Seven_Key, 0x0B, 8);
  addKey("8", Eight_Key, 0x09, 8);
  addKey("9", Nine_Key, 0x08, 8);
  addKey("vol up", VolumeUp_Key, 0x45, 8);
  addKey("vol down", VolumeDown_Key, 0x19, 8);
  addKey("mute", Mute_Key, 0x0E, 8);
  addKey("channel up", ChannelUp_Key, 0x05, 8);
  addKey("channel down", ChannelDown_Key, 0x59, 8);
  addKey("last (prev ch)", PrevChannel_Key, 0x42, 8);
  addKey("exit", Exit_Key, 0x0A, 8);
  addKey("menu", Menu_Key, 0x1F, 8);
  addKey("program guide", Guide_Key, 0x53, 8);
  addKey("display", Info_Key, 0x1E, 8);
  addKey("up arrow", Up_Key, 0x44, 8);
  addKey("down arrow", Down_Key, 0x1D, 8);
  addKey("left arrow", Left_Key, 0x1C, 8);
  addKey("right arrow", Right_Key, 0x48, 8);
  addKey("select", Select_Key, 0x5C, 8);
  addKey("play", Play_Key, 0x5D, 8);
  addKey("pause", Pause_Key, 0x4C, 8);
  addKey("rewind", Rewind_Key, 0x50, 8);
  addKey("fast fwd", FastForward_Key, 0x40, 8);
  addKey("stop", Stop_Key, 0x51, 8);
  addKey("media", Unmapped_Key, 0x00, 8);
  addKey("red", Red_Key, 0x58, 8);
  addKey("green", Green_Key, 0x12, 8);
  addKey("yellow", Yellow_Key, 0x54, 8);
  addKey("blue", Blue_Key, 0x02, 8);
  addKey("skip+", Next_Key, 0x43, 8);
  addKey("skip-", Previous_Key, 0x4D, 8);
  addKey("page+", PageDown_Key, 0x04, 8);
  addKey("page-", PageUp_Key, 0x1B, 8);
  addKey("list", Unmapped_Key, 0x4F, 8);
  addKey("fav", Favorites_Key, 0x06, 8);
  addKey("aspect", AspectRatio_Key, 0x49, 8);
  addKey("language", Audio_Key, 0x52, 8);
  addKey("subtitle", Captions_Key, 0x14, 8);
  addKey("teletext", Teletext_Key, 0x07, 8);
}

