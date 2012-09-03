#include "sylvania.h"
#include "protocols/necprotocol.h"

SylvaniaTV1::SylvaniaTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Sylvania_Make,
      index)
{
  addControlledDevice(Sylvania_Make, "6513DD", TV_Device);
  addControlledDevice(Sylvania_Make, "6519DD", TV_Device);
}


void SylvaniaTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x2287, 16);

  addKey("A-B", RepeatAB_Key, 0x43, 8);
  addKey("open close", Eject_Key, 0x44, 8);
  addKey("rewind", Rewind_Key, 0x52, 8);
  addKey("fast fwd", FastForward_Key, 0x53, 8);
  addKey("pause", Pause_Key, 0x5B, 8);
  addKey("mode", Mode_Key, 0x5C, 8);
  addKey("f.rew/prev track", Previous_Key, 0x5D, 8);
  addKey("play", Play_Key, 0x5E, 8);
  addKey("f.fwd/next track", Next_Key, 0x5F, 8);
  addKey("stop", Stop_Key, 0x60, 8);
  addKey("title", DiscTitle_Key, 0x70, 8);
  addKey("repeat", Repeat_Key, 0x70, 8);
  addKey("menu", DiscMenu_Key, 0x71, 8);
  addKey("select", Select_Key, 0x72, 8);
  addKey("return", Exit_Key, 0x72, 8);
  addKey("last (prev ch)", PrevChannel_Key, 0x73, 8);
  addKey("angle", Angle_Key, 0x79, 8);
  addKey("subtitle", Captions_Key, 0x7A, 8);
  addKey("audio", Audio_Key, 0x7B, 8);
  addKey("v.surr", Surround_Key, 0x81, 8);
  addKey("right arrow", Right_Key, 0xC6, 8);
  addKey("left arrow", Left_Key, 0xC7, 8);
  addKey("channel down", ChannelDown_Key, 0xC8, 8);
  addKey("picture", PictureMode_Key, 0xC9, 8);
  addKey("sleep", Sleep_Key, 0xCB, 8);
  addKey("select", Unmapped_Key, 0xCD, 8); // Two select keys?
  addKey("display", Info_Key, 0xCF, 8);
  addKey("channel up", ChannelUp_Key, 0xD0, 8);
  addKey("1", One_Key, 0xDF, 8);
  addKey("power", Power_Key, 0xE0, 8);
  addKey("2", Two_Key, 0xE1, 8);
  addKey("3", Three_Key, 0xE2, 8);
  addKey("4", Four_Key, 0xE3, 8);
  addKey("5", Five_Key, 0xE4, 8);
  addKey("6", Six_Key, 0xE5, 8);
  addKey("7", Seven_Key, 0xE6, 8);
  addKey("8", Eight_Key, 0xE7, 8);
  addKey("9", Nine_Key, 0xE8, 8);
  addKey("0", Zero_Key, 0xE9, 8);
  addKey("+10", DoubleDigit_Key, 0xEC, 8);
  addKey("+100", PlusOneHundred_Key, 0xEC, 8);
  addKey("setup", Unmapped_Key, 0xEF, 8);
  addKey("search mode", Unmapped_Key, 0xEF, 8);
  addKey("vol up", VolumeUp_Key, 0xF0, 8);
  addKey("vol down", VolumeDown_Key, 0xF1, 8);
  addKey("mute", Mute_Key, 0xF3, 8);
  addKey("up arrow", Up_Key, 0xF6, 8);
  addKey("down arrow", Down_Key, 0xF7, 8);
}
