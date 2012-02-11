#include "admiral.h"
#include "protocols/sharpprotocol.h"

AdmiralTV1::AdmiralTV1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Admiral_Make,
      index)
{
  threadableProtocol = new SharpProtocol(guiObject, index, true);

  addSharpKey("tv-1", One_Key, 0x01, 0x01);
  addSharpKey("tv-2", Two_Key, 0x01, 0x02);
  addSharpKey("tv-3", Three_Key, 0x01, 0x03);
  addSharpKey("tv-4", Four_Key, 0x01, 0x04);
  addSharpKey("tv-5", Five_Key, 0x01, 0x05);
  addSharpKey("tv-6", Six_Key, 0x01, 0x06);
  addSharpKey("tv-7", Seven_Key, 0x01, 0x07);
  addSharpKey("tv-8", Eight_Key, 0x01, 0x08);
  addSharpKey("tv-9", Nine_Key, 0x01, 0x09);
  addSharpKey("tv-0", Zero_Key, 0x01, 0x0A);
  addSharpKey("tv-100", PlusOneHundred_Key, 0x01, 0x0B);

  addSharpKey("tv-+", ChannelUp_Key, 0x01, 0x11);
  addSharpKey("tv--", ChannelDown_Key, 0x01, 0x12);
  addSharpKey("tv-input", Input_Key, 0x01, 0x13);
  addSharpKey("vol+", VolumeUp_Key, 0x01, 0x14);
  addSharpKey("vol-", VolumeDown_Key, 0x01, 0x15);
  addSharpKey("tv-power", Power_Key, 0x01, 0x16);
  addSharpKey("mute", Mute_Key, 0x01, 0x17);
  addSharpKey("tv-display", Info_Key, 0x01, 0x1B);

  addSharpKey("flash", Unmapped_Key, 0x01, 0x4F);
}


AdmiralVCR1::AdmiralVCR1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      Admiral_Make,
      index)
{
  threadableProtocol = new SharpProtocol(guiObject, index, true);

  addSharpKey("vcr-1", One_Key, 0x03, 0x01);
  addSharpKey("vcr-2", Two_Key, 0x03, 0x02);
  addSharpKey("vcr-3", Three_Key, 0x03, 0x03);
  addSharpKey("vcr-4", Four_Key, 0x03, 0x04);
  addSharpKey("vcr-5", Five_Key, 0x03, 0x05);
  addSharpKey("vcr-6", Six_Key, 0x03, 0x06);
  addSharpKey("vcr-7", Seven_Key, 0x03, 0x07);
  addSharpKey("vcr-8", Eight_Key, 0x03, 0x08);
  addSharpKey("vcr-9", Nine_Key, 0x03, 0x09);
  addSharpKey("vcr-0", Zero_Key, 0x03, 0x0A);
  addSharpKey("child_lock", Unmapped_Key, 0x03, 0x0D);

  addSharpKey("vcr-+", ChannelUp_Key, 0x03, 0x11);
  addSharpKey("vcr--", ChannelDown_Key, 0x03, 0x12);
  addSharpKey("tv/vcr", Unmapped_Key, 0x03, 0x13);
  addSharpKey("vcr-power", Power_Key, 0x03, 0x16);
  addSharpKey("menu", Menu_Key, 0x03, 0x1D);
  addSharpKey("tape_speed", VHSSpeed_Key, 0x03, 0x1F);

  addSharpKey("ff", FastForward_Key, 0x03, 0x21);
  addSharpKey("play", Play_Key, 0x03, 0x22);
  addSharpKey("rew", Rewind_Key, 0x03, 0x23);
  addSharpKey("pause", Pause_Key, 0x03, 0x25);
  addSharpKey("stop", Stop_Key, 0x03, 0x27);
  addSharpKey("rec", Record_Key, 0x03, 0x28);
  addSharpKey("slow", Slow_Key, 0x03, 0x29);
  addSharpKey("dpss+", Unmapped_Key, 0x03, 0x2F);

  addSharpKey("dpss-", Unmapped_Key, 0x03, 0x30);
  addSharpKey("eject", Eject_Key, 0x03, 0x33);
  addSharpKey("vcr-input", Input_Key, 0x03, 0x34);

  addSharpKey("auto_review", Unmapped_Key, 0x03, 0x83);
  addSharpKey("cancel", Clear_Key, 0x03, 0x84);
  addSharpKey("vcr-100", PlusOneHundred_Key, 0x03, 0x88);
  addSharpKey("vcr-display", Info_Key, 0x03, 0x8C);
  addSharpKey("on_screen", Unmapped_Key, 0x03, 0x8D);

  addSharpKey("add/erase", Unmapped_Key, 0x03, 0xB5);
}
