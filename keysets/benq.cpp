#include "benq.h"
#include "protocols/necprotocol.h"


BenQTV1::BenQTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      BenQ_Make,
      index)
{
}


void BenQTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x60, 8);

  addKey("power", Power_Key, 0x00, 8);
  addKey("input", Input_Key, 0x45, 8);
  addKey("backlight", Unmapped_Key, 0x54, 8);
  addKey("information", Info_Key, 0x52, 8);
  addKey("sleeptimer", Sleep_Key, 0x58, 8);
  addKey("sound", SoundMode_Key, 0x59, 8);
  addKey("usersituation", Unmapped_Key, 0x55, 8);
  addKey("audiomode", Audio_Key, 0x53, 8);
  addKey("teletext_display", TeletextAndTV_Key, 0x4F, 8);
  addKey("tt_index", TeletextIndex_Key, 0x4C, 8);
  addKey("tt_info", Unmapped_Key, 0x4E, 8);
  addKey("tt_subpage", TeletextReveal_Key, 0x4D, 8);
  addKey("teletext", Teletext_Key, 0x12, 8);
  addKey("PIP", PIP_Key, 0x10, 8);
  addKey("up", Up_Key, 0x44, 8);
  addKey("down", Down_Key, 0x1D, 8);
  addKey("left", Left_Key, 0x1C, 8);
  addKey("right", Right_Key, 0x48, 8);
  addKey("OK", Select_Key, 0x51, 8);
  addKey("freeze", Pause_Key, 0x11, 8);
  addKey("aspectratio", AspectRatio_Key, 0x13, 8);
  addKey("vol+", VolumeUp_Key, 0x19, 8);
  addKey("vol-", VolumeDown_Key, 0x15, 8);
  addKey("chan+", ChannelUp_Key, 0x5C, 8);
  addKey("chan-", ChannelDown_Key, 0x14, 8);
  addKey("menu", Menu_Key, 0x43, 8);
  addKey("mute", Mute_Key, 0x42, 8);
  addKey("zap", Unmapped_Key, 0x0F, 8);
  addKey("dualdigit", DoubleDigit_Key, 0x0D, 8);
  addKey("1", One_Key, 0x04, 8);
  addKey("2", Two_Key, 0x05, 8);
  addKey("3", Three_Key, 0x5F, 8);
  addKey("4", Four_Key, 0x07, 8);
  addKey("5", Five_Key, 0x08, 8);
  addKey("6", Six_Key, 0x09, 8);
  addKey("7", Seven_Key, 0x0A, 8);
  addKey("8", Eight_Key, 0x0B, 8);
  addKey("9", Nine_Key, 0x0C, 8);
  addKey("0", Zero_Key, 0x03, 8);
}
