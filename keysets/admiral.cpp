#include "admiral.h"
#include "protocols/sharpprotocol.h"
#include "protocols/rc5protocol.h"

AdmiralTV1::AdmiralTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Admiral_Make,
      index)
{
}


void AdmiralTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

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


AdmiralTV2::AdmiralTV2(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 2",
      Admiral_Make,
      index)
{
}



// The following is just a guess:
void AdmiralTV2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

  addKey("0", Zero_Key, 0x1000, 13);
  addKey("1", One_Key, 0x1001, 13);
  addKey("2", Two_Key, 0x1002, 13);
  addKey("3", Three_Key, 0x1003, 13);
  addKey("4", Four_Key, 0x1004, 13);
  addKey("5", Five_Key, 0x1005, 13);
  addKey("6", Six_Key, 0x1006, 13);
  addKey("7", Seven_Key, 0x1007, 13);
  addKey("8", Eight_Key, 0x1008, 13);
  addKey("9", Nine_Key, 0x1009, 13);
  addKey("1-", DoubleDigit_Key, 0x100A, 13); // -/--
  addKey("100", PlusOneHundred_Key, 0x100A, 13);
  addKey("TV-Dash", Dash_Key, 0x100A, 13);
  addKey("CP", Unmapped_Key, 0x100B, 13); // "C/P", "Channel/program/freq"
  addKey("ON/OFF", Power_Key, 0x100C, 13);
  addKey("MUTE", Mute_Key, 0x100D, 13);
  addKey("pp", PrevChannel_Key, 0x100E, 13); // "GREEN", "Personal preference"
  addKey("INFO", Info_Key, 0x100F, 13); // "+", "OSD"

  addKey("VOL+", VolumeUp_Key, 0x1010, 13);
  addKey("VOL-", VolumeDown_Key, 0x1011, 13);
  addKey("BRIGHTNESS_UP", BrightnessUp_Key, 0x1012, 13);
  addKey("BRIGHTNESS_DOWN", BrightnessDown_Key, 0x1013, 13);
  addKey("CONTRAST_UP", ContrastUp_Key, 0x1014, 13);
  addKey("CONTRAST_DOWN", ContrastDown_Key, 0x1015, 13);
  addKey("BASS_UP", BassUp_Key, 0x1016, 13);
  addKey("BASS_DOWN", BassDown_Key, 0x1017, 13);
  addKey("TREBLE_UP", TrebleUp_Key, 0x1018, 13);
  addKey("TREBLE_DOWN", TrebleDown_Key, 0x1019, 13);
  addKey("BALANCE_RIGHT", BalanceRight_Key, 0x101A, 13);
  addKey("BALANCE_LEFT", BalanceLeft_Key, 0x101B, 13);

  addKey("P+", ChannelUp_Key, 0x1020, 13);
  addKey("P-", ChannelDown_Key, 0x1021, 13);

  addKey("PIP on/off", PIP_Key, 0x1058, 13);
  addKey("PIP shift", PIPMove_Key, 0x1059, 13);
  addKey("PIP/main picture swap", PIPSwap_Key, 0x105A, 13);
  addKey("Select PIP source", PIPSource_Key, 0x105F, 13);
  addKey("PIP Freeze", PIPPause_Key, 0x1065, 13);
  addKey("PIP Freeze", PIPSize_Key, 0x1068, 13);
  addKey("red", Red_Key, 0x106B, 13);
  addKey("green", Green_Key, 0x106C, 13);
  addKey("yellow", Yellow_Key, 0x106D, 13);
  addKey("cyan", Blue_Key, 0x106E, 13);
}


AdmiralVCR1::AdmiralVCR1(
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      Admiral_Make,
      index)
{
}


void AdmiralVCR1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

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
