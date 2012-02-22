#include "panasonic.h"
#include "protocols/necprotocol.h"
#include "protocols/kaseikyoprotocol.h"


PanasonicCarAudio::PanasonicCarAudio(
  unsigned int index)
  : PIRKeysetMetaData(
      "Car Audio Keyset",
      Panasonic_Make,
      index)
{
}


void PanasonicCarAudio::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, false);

//  setPreData(0x8156, 16);
  setPreData(0x6A81, 16);

  addKey("Power", Power_Key, 0x12, 8);
  addKey("ATT", Unmapped_Key, 0x14, 8);
  addKey("Vol_Down", VolumeDown_Key, 0x19, 8);
  addKey("Mode", SoundMode_Key, 0x1A, 8);
  addKey("PRG", Program_Key, 0x1C, 8);
  addKey("Vol_Up", VolumeUp_Key, 0x1D, 8);
  addKey("Tune/Track_Down", ChannelDown_Key, 0x1E, 8);
  addKey("Tune/Track_Up", ChannelUp_Key, 0x1F, 8);
}


PanasonicSat1::PanasonicSat1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Satellite Keyset 1",
      Panasonic_Make,
      index)
{
}


void PanasonicSat1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new KaseikyoProtocol(guiObject, index);

//  setPreData(0x40040140, 32);
  setPreData(0x2002, 16);

  addKaseikyoKey("PROG", Program_Key, 0x028, 0x8A);
  addKaseikyoKey("1", One_Key, 0x028, 0xA0);
  addKaseikyoKey("2", Two_Key, 0x028, 0xA1);
  addKaseikyoKey("3", Three_Key, 0x028, 0xA2);
  addKaseikyoKey("4", Four_Key, 0x028, 0xA3);
  addKaseikyoKey("5", Five_Key, 0x028, 0xA4);
  addKaseikyoKey("6", Six_Key, 0x028, 0xA5);
  addKaseikyoKey("7", Seven_Key, 0x028, 0xA6);
  addKaseikyoKey("8", Eight_Key, 0x028, 0xA7);
  addKaseikyoKey("9", Nine_Key, 0x028, 0xA8);
  addKaseikyoKey("0", Zero_Key, 0x028, 0xA9);
  addKaseikyoKey("CH-", ChannelDown_Key, 0x028, 0xB6);
  addKaseikyoKey("CH+", ChannelUp_Key, 0x028, 0xB7);
  addKaseikyoKey("ALT_AUD", Audio_Key, 0x028, 0xB8);
  addKaseikyoKey("INFO", Info_Key, 0x028, 0xB9);
  addKaseikyoKey("TV/DSS", Input_Key, 0x028, 0xBC);
  addKaseikyoKey("POWER", Power_Key, 0x028, 0xBD);
  addKaseikyoKey("REC", Record_Key, 0x028, 0xC2);
  addKaseikyoKey("ACTION", Select_Key, 0x028, 0xC3);
  addKaseikyoKey("MENU", Menu_Key, 0x028, 0xC4);
  addKaseikyoKey("GUIDE", Guide_Key, 0x028, 0xC5);
  addKaseikyoKey("EXIT", Exit_Key, 0x028, 0xC6);
  addKaseikyoKey("UP", Up_Key, 0x028, 0xCA);
  addKaseikyoKey("DOWN", Down_Key, 0x028, 0xCB);
  addKaseikyoKey("LEFT", Left_Key, 0x028, 0xCD);
  addKaseikyoKey("RIGHT", Right_Key, 0x028, 0xCE);
  addKaseikyoKey("FAV", Favorites_Key, 0x028, 0xD0);
  addKaseikyoKey("R_TUNE", PrevChannel_Key, 0x028, 0xD1);
  addKaseikyoKey("GUIDE", Guide_Key, 0x028, 0xD3);
  addKaseikyoKey("LOGO_TUNE", Unmapped_Key, 0x028, 0xD5);
  addKaseikyoKey("TXT", Teletext_Key, 0x028, 0xDE);
  addKaseikyoKey("STTL", Unmapped_Key, 0x028, 0xDF);

  addKaseikyoKey("RED", Red_Key, 0x028, 0xEC);
  addKaseikyoKey("GREEN", Green_Key, 0x028, 0xED);
  addKaseikyoKey("BLUE", Blue_Key, 0x028, 0xEE);
  addKaseikyoKey("YELLOW", Yellow_Key, 0x028, 0xEF);
}


PanasonicSat1a::PanasonicSat1a(
  unsigned int index)
  : PanasonicSat1(index)
{
  setKeysetName("Satellite Keyset 1a");
}


void PanasonicSat1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  PanasonicSat1::populateProtocol(guiObject);

  addKaseikyoKey("EXIT", Exit_Key, 0x028, 0xCF);
  addKaseikyoKey("CH+", ChannelUp_Key, 0x028, 0xB2);
  addKaseikyoKey("CH-", ChannelDown_Key, 0x028, 0xB3);
}


PanasonicTV1::PanasonicTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Panasonic_Make,
      index)
{
}


void PanasonicTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new KaseikyoProtocol(guiObject, index);

//  setPreData(0x400401, 24);
  setPreData(0x2002, 16);

  addKaseikyoKey("TV/AV", Input_Key, 0x008, 0x05);
  addKaseikyoKey("PICTURE", PictureMode_Key, 0x008, 0x06);
  addKaseikyoKey("SOUND", SoundMode_Key, 0x008, 0x07);
  addKaseikyoKey("N", Unmapped_Key, 0x008, 0x0C);
  addKaseikyoKey("S", Unmapped_Key, 0x008, 0x0E);
  addKaseikyoKey("TIMER", Sleep_Key, 0x008, 0x0F); // "Sleep"
  addKaseikyoKey("1", One_Key, 0x008, 0x10);
  addKaseikyoKey("2", Two_Key, 0x008, 0x11);
  addKaseikyoKey("3", Three_Key, 0x008, 0x12);
  addKaseikyoKey("4", Four_Key, 0x008, 0x13);
  addKaseikyoKey("5", Five_Key, 0x008, 0x14);
  addKaseikyoKey("6", Six_Key, 0x008, 0x15);
  addKaseikyoKey("7", Seven_Key, 0x008, 0x16);
  addKaseikyoKey("8", Eight_Key, 0x008, 0x17);
  addKaseikyoKey("9", Nine_Key, 0x008, 0x18);
  addKaseikyoKey("0", Zero_Key, 0x008, 0x19);
  addKaseikyoKey("VOLUME_UP", VolumeUp_Key, 0x008, 0x20);
  addKaseikyoKey("VOLUME_DOWN", VolumeDown_Key, 0x008, 0x21);
  addKaseikyoKey("Bass Up", BassUp_Key, 0x008, 0x22);
  addKaseikyoKey("Bass Down", BassDown_Key, 0x008, 23);
  addKaseikyoKey("Treble Up", TrebleUp_Key, 0x008, 0x24);
  addKaseikyoKey("Treble Down", TrebleDown_Key, 0x008, 0x25);
  addKaseikyoKey("Balance Left", BalanceLeft_Key, 0x008, 0x26);
  addKaseikyoKey("Balance Right", BalanceRight_Key, 0x008, 0x27);
  addKaseikyoKey("SURROUND", Surround_Key, 0x008, 0x31);
  addKaseikyoKey("MUTE", Mute_Key, 0x008, 0x32);
  addKaseikyoKey("SAP", Audio_Key, 0x008, 0x33); // "Stereo/Mono/Bilingual"
  addKaseikyoKey("PROG_UP", ChannelUp_Key, 0x008, 0x34);
  addKaseikyoKey("PROG_DOWN", ChannelDown_Key, 0x008, 0x35);
  addKaseikyoKey("R-TUNE", Unmapped_Key, 0x008, 0x37);
  addKaseikyoKey("RECALL", PrevChannel_Key, 0x008, 0x39);
  addKaseikyoKey("C", Clear_Key, 0x008, 0x3A);
  addKaseikyoKey("-/--", DoubleDigit_Key, 0x008, 0x3B); // Also Dash_Key?
  addKaseikyoKey("POWER", Power_Key, 0x008, 0x3D);
  addKaseikyoKey("On", PowerOn_Key, 0x008, 0x3E);
  addKaseikyoKey("Off", PowerOff_Key, 0x008, 0x3F);
  addKaseikyoKey("Color Up", ColorUp_Key, 0x008, 0x40);
  addKaseikyoKey("Color Down", ColorDown_Key, 0x008, 0x41);
  addKaseikyoKey("Contrast Up", ContrastUp_Key, 0x008, 0x42);
  addKaseikyoKey("Contrast Down", ContrastDown_Key, 0x008, 0x43);
  addKaseikyoKey("Brightness Up", BrightnessUp_Key, 0x008, 0x44);
  addKaseikyoKey("Brightness Down", BrightnessDown_Key, 0x008, 0x45);
  addKaseikyoKey("select", Select_Key, 0x008, 0x49); // "OK"
  addKaseikyoKey("UP", Up_Key, 0x008, 0x4A);
  addKaseikyoKey("DOWN", Down_Key, 0x008, 0x4B);
  addKaseikyoKey("LEFT", Left_Key, 0x008, 0x4E);
  addKaseikyoKey("RIGHT", Right_Key, 0x008, 0x4F);
  addKaseikyoKey("P_MENU", Unmapped_Key, 0x008, 0x50);
  addKaseikyoKey("S_MENU", Unmapped_Key, 0x008, 0x51);
//  addKaseikyoKey("ACTION", Enter_Key, 0x008, 0x52); // Might be wrong
  addKaseikyoKey("setup", Menu_Key, 0x008, 0x52); // "ACTION"
  addKaseikyoKey("pip swap", PIPSwap_Key, 0x008, 0x5E);
  addKaseikyoKey("pip move", PIPMove_Key, 0x008, 0x67);
  addKaseikyoKey("RED", Red_Key, 0x008, 0x70);
  addKaseikyoKey("GREEN", Green_Key, 0x008, 0x71);
  addKaseikyoKey("YELLOW", Yellow_Key, 0x008, 0x72);
  addKaseikyoKey("BLUE", Blue_Key, 0x008, 0x73);
  addKaseikyoKey("MOOD_LIGHT", Unmapped_Key, 0x008, 0xA1);
  addKaseikyoKey("HELP", Unmapped_Key, 0x008, 0xAC);
  addKaseikyoKey("GAME", Unmapped_Key, 0x008, 0xBB);
  addKaseikyoKey("Exit", Unmapped_Key, 0x008, 0xD3);
  addKaseikyoKey("Return", Unmapped_Key, 0x008, 0xD4); // "R"
  addKaseikyoKey("STR", Unmapped_Key, 0x008,0xD5);
  addKaseikyoKey("MULTIWINDOW", Unmapped_Key, 0x008, 0xE6); // "multi pip"
  addKaseikyoKey("FM/TV", Unmapped_Key, 0x008, 0xEE);
  addKaseikyoKey("System reset", Unmapped_Key, 0x008, 0xFF);

  addKaseikyoKey("Mix", TeletextAndTV_Key, 0x018, 0x01);
  addKaseikyoKey("TV/TEXT", Teletext_Key, 0x018, 0x03);
  addKaseikyoKey("Display_Cancel", Unmapped_Key, 0x018, 0x04);
  addKaseikyoKey("FP (Favorite Page)", Unmapped_Key, 0x018, 0x05);
  addKaseikyoKey("INDEX", TeletextIndex_Key, 0x018, 0x08);
  addKaseikyoKey("HOLD", TeletextHold_Key, 0x018, 0x09);
  addKaseikyoKey("List Store", TeletextStore_Key, 0x018, 0x0A);
  addKaseikyoKey("TIMETEXT", TeletextTime_Key, 0x018, 0x0B);
  addKaseikyoKey("FTB (Full/Top/Bottom)", TeletextSize_Key, 0x018, 0x0C);
  addKaseikyoKey("REVEAL", TeletextReveal_Key, 0x018, 0x1C);
  addKaseikyoKey("List/F.Text", Unmapped_Key, 0x018, 0x1D);
  addKaseikyoKey("Text Reset", Unmapped_Key, 0x018, 0x1E);

  addKaseikyoKey("TV", Unmapped_Key, 0x028, 0x30);
  addKaseikyoKey("PROG", Program_Key, 0x028, 0x8A);
  addKaseikyoKey("MENU", Menu_Key, 0x028, 0xC4);
  addKaseikyoKey("GUIDE", Guide_Key, 0x028, 0xC5);
  addKaseikyoKey("EXIT", Exit_Key, 0x028, 0xC6);

  addKaseikyoKey("ASPECT", AspectRatio_Key, 0x048, 0xDE);
  addKaseikyoKey("picture position/size", PIPSize_Key, 0x048, 0xE5);

  addKaseikyoKey("Guide", Unmapped_Key, 0x098, 0x87);
  addKaseikyoKey("DIRECTREC", Record_Key, 0x098, 0x89);
  addKaseikyoKey("Exit", Unmapped_Key, 0x098, 0x9A);
  addKaseikyoKey("Option", Unmapped_Key, 0x098, 0xA7);
  addKaseikyoKey("SDCard", Unmapped_Key, 0x098, 0xAB);
  addKaseikyoKey("Favorite", Unmapped_Key, 0x098, 0xAE);
  addKaseikyoKey("Link", Unmapped_Key, 0x098, 0xB1);
  addKaseikyoKey("prog-", Unmapped_Key, 0x098, 0xD0);

  // Some media keys, possibly a combo DVD-TV?
//  addKaseikyoKey("STOP", Stop_Key, 0x00B, 0x00);
//  addKaseikyoKey("PLAY", Play_Key, 0x00B, 0x0A);
//  addKaseikyoKey("FORWARD", FastForward_Key, 0x00B, 0x4A);
//  addKaseikyoKey("REWIND", Rewind_Key, 0x00B, 0x49);
}


PanasonicTV1a::PanasonicTV1a(
  unsigned int index)
  : PanasonicTV1(index)
{
  setKeysetName("TV Keyset 1a");
}


void PanasonicTV1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  PanasonicTV1::populateProtocol(guiObject);

  // Overwrite some of the keys:
  addKaseikyoKey("OK", Select_Key, 0x008, 0x49);
  addKaseikyoKey("MENU", Menu_Key, 0x008, 0x06);
}


PanasonicTV1b::PanasonicTV1b(
  unsigned int index)
  : PanasonicTV1(index)
{
  setKeysetName("TV Keyset 1b");

  addControlledDevice(Panasonic_Make, "Viera TX-32LZD80", TV_Device);
  addControlledDevice(Panasonic_Make, "Viera 42PZ700U", TV_Device);
  addControlledDevice(Panasonic_Make, "Viera 42PZ8ES", TV_Device);
  addControlledDevice(Panasonic_Make, "Quintrix TX-25MK1C", TV_Device);
}


void PanasonicTV1b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  PanasonicTV1::populateProtocol(guiObject);

  addKaseikyoKey("Info", Info_Key, 0x008, 0x39); // "OSD"
  addKaseikyoKey("OK", Select_Key, 0x008, 0x49);
  addKaseikyoKey("Menu", Menu_Key, 0x008, 0x52);
//  addKaseikyoKey("Exit", Exit_Key, 0x008, 0xD3);

  addKaseikyoKey("Guide", Guide_Key, 0x098, 0x87);
  addKaseikyoKey("Exit", Exit_Key, 0x098, 0x9A);
}


PanasonicVCR1::PanasonicVCR1(
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      Panasonic_Make,
      index)
{
}


void PanasonicVCR1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new KaseikyoProtocol(guiObject, index);

//  setPreData(0x400409, 24);
  setPreData(0x2002, 16);

  addKaseikyoKey("STOP", Stop_Key, 0x009, 0x00);
  addKaseikyoKey("REWIND", Rewind_Key, 0x009, 0x02);
  addKaseikyoKey("FORWARD", FastForward_Key, 0x009, 0x03);
  addKaseikyoKey("PAUSE", Pause_Key, 0x009, 0x06);
  addKaseikyoKey("REC", Record_Key, 0x009, 0x08);
  addKaseikyoKey("PLAY", Play_Key, 0x009, 0x0A);
  addKaseikyoKey("STILL", StepForward_Key, 0x009, 0x0C);  // also "ADV"
  addKaseikyoKey("SLOW", Slow_Key, 0x009, 0x0F);
  addKaseikyoKey("1", One_Key, 0x009, 0x10);
  addKaseikyoKey("2", Two_Key, 0x009, 0x11);
  addKaseikyoKey("3", Three_Key, 0x009, 0x12);
  addKaseikyoKey("4", Four_Key, 0x009, 0x13);
  addKaseikyoKey("5", Five_Key, 0x009, 0x14);
  addKaseikyoKey("6", Six_Key, 0x009, 0x15);
  addKaseikyoKey("7", Seven_Key, 0x009, 0x16);
  addKaseikyoKey("8", Eight_Key, 0x009, 0x17);
  addKaseikyoKey("9", Nine_Key, 0x009, 0x18);
  addKaseikyoKey("0", Zero_Key, 0x009, 0x19);
  addKaseikyoKey("AUDIO", Audio_Key, 0x009, 0x33);
  addKaseikyoKey("PROGRAMME^", ChannelUp_Key, 0x009, 0x34);
  addKaseikyoKey("PROGRAMMEv", ChannelDown_Key, 0x009, 0x35);
  addKaseikyoKey("TV-SAT", Input_Key, 0x009, 0x36);
  addKaseikyoKey("INFO", Info_Key, 0x009, 0x39);
  addKaseikyoKey("-/--", DoubleDigit_Key, 0x009, 0x3B);
  addKaseikyoKey("POWER", Power_Key, 0x009, 0x3D);
  addKaseikyoKey("INDEX", Unmapped_Key, 0x009, 0x40);
  addKaseikyoKey("time_search", Unmapped_Key, 0x009, 0x44);
  addKaseikyoKey("INDEXL", Unmapped_Key, 0x009, 0x49);
  addKaseikyoKey("INDEXR", Unmapped_Key, 0x009, 0x4A);
  addKaseikyoKey("mem_rep", Unmapped_Key, 0x009, 0x53);
  addKaseikyoKey("COUNTER_RESET", Unmapped_Key, 0x009, 0x54);
  addKaseikyoKey("TAPE_REMAIN", Unmapped_Key, 0x009, 0x55);
  addKaseikyoKey("CLOCK/COUNTER", Clock_Key, 0x009, 0x56);
  addKaseikyoKey("+", Unmapped_Key, 0x009, 0x8E);
  addKaseikyoKey("-", Unmapped_Key, 0x009, 0x8F);
  addKaseikyoKey("monitor", Unmapped_Key, 0x009, 0x91);
  addKaseikyoKey("TRACKING_AUTO", AutoTracking_Key, 0x009, 0xB0);
  addKaseikyoKey("TRACKING_PLUS", TrackingPlus_Key, 0x009, 0xB1);
  addKaseikyoKey("TRACKING_MINUS", TrackingMinus_Key, 0x009, 0xB2);
  addKaseikyoKey("TIMERREC", Timer_Key, 0x009, 0xB4);
  addKaseikyoKey("AV", Unmapped_Key, 0x009, 0xC0);
  addKaseikyoKey("DIRECT_TV_REC", Unmapped_Key, 0x009, 0xC2);
  addKaseikyoKey("mesecam", Unmapped_Key, 0x009, 0xC9);
  addKaseikyoKey("100", PlusOneHundred_Key, 0x009, 0xE5);
  addKaseikyoKey("sap/hi-fi", Unmapped_Key, 0x009, 0xE6);
  addKaseikyoKey("repeat", Repeat_Key, 0x009, 0xF0);
  addKaseikyoKey("memory", Program_Key, 0x009, 0xF1);
  addKaseikyoKey("sleep", Sleep_Key, 0x009, 0xF2);
  addKaseikyoKey("rew2", Unmapped_Key, 0x009, 0xF3);
  addKaseikyoKey("zerostop", Unmapped_Key, 0x009, 0xF5);
  addKaseikyoKey("REPLAY", Replay_Key, 0x009, 0xF7);
  addKaseikyoKey("cm-zero", Unmapped_Key, 0x009, 0xF8);

  addKaseikyoKey("PROG/CHECK", Program_Key, 0x019, 0x01);
  addKaseikyoKey("rotate", Unmapped_Key, 0x019, 0x02);
  addKaseikyoKey("rotatedown", Unmapped_Key, 0x019, 0x03);
  addKaseikyoKey("set", Unmapped_Key, 0x019, 0x04);
  addKaseikyoKey("clear", Unmapped_Key, 0x019, 0x05);
  addKaseikyoKey("VPS/PDC", Unmapped_Key, 0x019, 0x06);
  addKaseikyoKey("OffTimer", Sleep_Key, 0x019, 0x08);
  addKaseikyoKey("CANCEL", Clear_Key, 0x019, 0x09);
  addKaseikyoKey("SPEED", VHSSpeed_Key, 0x019, 0x0A);
  addKaseikyoKey("ADD/DELETE", Unmapped_Key, 0x019, 0x31);
  addKaseikyoKey("RADIO_TUNE", Unmapped_Key, 0x019, 0x38);
  addKaseikyoKey("MENU", Menu_Key, 0x019, 0x56);
  addKaseikyoKey("OK", Select_Key, 0x019, 0x58);
  addKaseikyoKey("SHOWVIEW", Unmapped_Key, 0x019, 0x5D);
  addKaseikyoKey("DISPLAY", Unmapped_Key, 0x019, 0x5F);
  addKaseikyoKey("EXIT", Exit_Key, 0x019, 0x66);
  addKaseikyoKey("CHECK+", Unmapped_Key, 0x019, 0x90);
  addKaseikyoKey("CHECK-", Unmapped_Key, 0x019, 0x91);
  addKaseikyoKey("DATE+", Unmapped_Key, 0x019, 0x92);
  addKaseikyoKey("DATE-", Unmapped_Key, 0x019, 0x93);
  addKaseikyoKey("ON+", Unmapped_Key, 0x019, 0x94);
  addKaseikyoKey("ON-", Unmapped_Key, 0x019, 0x95);
  addKaseikyoKey("OFF+", Unmapped_Key, 0x019, 0x96);
  addKaseikyoKey("OFF-", Unmapped_Key, 0x019, 0x97);
  addKaseikyoKey("SEARCH", Unmapped_Key, 0x019, 0x9D);
  addKaseikyoKey("TAPE", Unmapped_Key, 0x019, 0xE0);

  addKaseikyoKey("STILL_ALBUM", Unmapped_Key, 0x059, 0x23);
  addKaseikyoKey("PROG_PLAY", Unmapped_Key, 0x059, 0x3A);
  addKaseikyoKey("I-Timer", Unmapped_Key, 0x059, 0x3F);
  addKaseikyoKey("TV/TEXT", Unmapped_Key, 0x059, 0x57);
  addKaseikyoKey("ExtLink", Unmapped_Key, 0x059, 0x5B);

// These are fishy:
//  addKaseikyoKey("RESET_STORE", Unmapped_Key, 0x019, 0x58);
}


PanasonicVCR1a::PanasonicVCR1a(
  unsigned int index)
  : PanasonicVCR1(index)
{
  setKeysetName("VCR Keyset 1a");
}


void PanasonicVCR1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  PanasonicVCR1::populateProtocol(guiObject);

  addKaseikyoKey("OSD", Info_Key, 0x009, 0x57);
  addKaseikyoKey("AV", Input_Key, 0x009, 0xC0);
  addKaseikyoKey("DISPLAY", Info_Key, 0x019, 0x5F);
}


PanasonicVCR1b::PanasonicVCR1b(
  unsigned int index)
  : PanasonicVCR1(index)
{
  setKeysetName("VCR Keyset 1b");
}


void PanasonicVCR1b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  PanasonicVCR1::populateProtocol(guiObject);

  addKaseikyoKey("repeat", Repeat_Key, 0x009, 0xF9);
  addKaseikyoKey("prog", Program_Key, 0x009, 0xFF);
  addKaseikyoKey("clear", Clear_Key, 0x019, 0x0A);
}


PanasonicVCR1c::PanasonicVCR1c(
  unsigned int index)
  : PanasonicVCR1(index)
{
  setKeysetName("VCR Keyset 1c");
}


void PanasonicVCR1c::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  PanasonicVCR1::populateProtocol(guiObject);

  addKaseikyoKey("rotate", Up_Key, 0x019, 0x02);
  addKaseikyoKey("rotatedown", Down_Key, 0x019, 0x03);
  addKaseikyoKey("set", Select_Key, 0x019, 0x04);
  addKaseikyoKey("clear", Exit_Key, 0x019, 0x05);
}


PanasonicDVD1::PanasonicDVD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Panasonic_Make,
      index)
{
}


void PanasonicDVD1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new KaseikyoProtocol(guiObject, index);

//  setPreData(0x40040D00, 32);
  setPreData(0x2002, 16);

  addKaseikyoKey("STOP", Stop_Key, 0x00B, 0x00);
  addKaseikyoKey("OPEN/CLOSE", Eject_Key, 0x00B, 0x01);
//  addKaseikyoKey("TV-SAT", Input_Key, 0x00B, 0x01);
  addKaseikyoKey("REW", Rewind_Key, 0x00B, 0x04);
  addKaseikyoKey("FF", FastForward_Key, 0x00B, 0x05);
  addKaseikyoKey("PAUSE", Pause_Key, 0x00B, 0x06);
  addKaseikyoKey("CH_DOWN", ChannelDown_Key, 0x00B, 0x07);
  addKaseikyoKey("rec", Record_Key, 0x00B, 0x08);
  addKaseikyoKey("PLAY", Play_Key, 0x00B, 0x0A);
  addKaseikyoKey("CH_UP", ChannelUp_Key, 0x00B, 0x0F);
  addKaseikyoKey("1", One_Key, 0x00B, 0x10);
  addKaseikyoKey("2", Two_Key, 0x00B, 0x11);
  addKaseikyoKey("3", Three_Key, 0x00B, 0x12);
  addKaseikyoKey("4", Four_Key, 0x00B, 0x13);
  addKaseikyoKey("5", Five_Key, 0x00B, 0x14);
  addKaseikyoKey("6", Six_Key, 0x00B, 0x15);
  addKaseikyoKey("7", Seven_Key, 0x00B, 0x16);
  addKaseikyoKey("8", Eight_Key, 0x00B, 0x17);
  addKaseikyoKey("9", Nine_Key, 0x00B, 0x18);
  addKaseikyoKey("0", Zero_Key, 0x00B, 0x19);
  addKaseikyoKey("extlink", Unmapped_Key, 0x00B, 0x23);
  addKaseikyoKey("AUDIO", Audio_Key, 0x00B, 0x33);
  addKaseikyoKey("POWER", Power_Key, 0x00B, 0x3D);
  addKaseikyoKey("erase", Unmapped_Key, 0x00B, 0x44); // "DELETE"
  addKaseikyoKey("POSITION_MEMORY", Unmapped_Key, 0x00B, 0x46);
  addKaseikyoKey("A-B_REPEAT", RepeatAB_Key, 0x00B, 0x48);
  addKaseikyoKey("PREV", Previous_Key, 0x00B, 0x49);
  addKaseikyoKey("NEXT", Next_Key, 0x00B, 0x04A);
  addKaseikyoKey("timeslip", Unmapped_Key, 0x00B, 0x4B);
  addKaseikyoKey("manualskip", Unmapped_Key, 0x00B, 0x4C);
  addKaseikyoKey("RANDOM", Random_Key, 0x00B, 0x4D);
  addKaseikyoKey("recmode", Unmapped_Key, 0x00B, 0x51);
  addKaseikyoKey("functions", Unmapped_Key, 0x00B, 0x57);
  addKaseikyoKey("createchapter", Unmapped_Key, 0x00B, 0x58);
  addKaseikyoKey("status", Unmapped_Key, 0x00B, 0x5F);
  addKaseikyoKey("VOLUMEDOWN", VolumeDown_Key, 0x00B, 0x62);
  addKaseikyoKey("VOLUMEUP", VolumeUp_Key, 0x00B, 0x63);
  addKaseikyoKey("i", Unmapped_Key, 0x00B, 0x66);
  addKaseikyoKey("timer", Timer_Key, 0x00B, 0x78);
  addKaseikyoKey("progcheck", Unmapped_Key, 0x00B, 0x7C);
  addKaseikyoKey("showview", Unmapped_Key, 0x00B, 0x7F);
  addKaseikyoKey("MENU", Menu_Key, 0x00B, 0x80);
  addKaseikyoKey("RETURN", Exit_Key, 0x00B, 0x81);
  addKaseikyoKey("ACTION", Select_Key, 0x00B, 0x82);
  addKaseikyoKey("CANCEL", Clear_Key, 0x00B, 0x83);
  addKaseikyoKey("UP", Up_Key, 0x00B, 0x85);
  addKaseikyoKey("DOWN", Down_Key, 0x00B, 0x86);
  addKaseikyoKey("LEFT", Left_Key, 0x00B, 0x87);
  addKaseikyoKey("RIGHT", Right_Key, 0x00B, 0x88);
  addKaseikyoKey("+10", DoubleDigit_Key, 0x00B, 0x89);
//  addKaseikyoKey("inputselect", Input_Key, 0x00B, 0x89); // odd!
  addKaseikyoKey("PROGRAM", Program_Key, 0x00B, 0x8A);
  addKaseikyoKey("QUICK_REPLAY", Replay_Key, 0x00B, 0x8B);
  addKaseikyoKey("REPEAT", Repeat_Key, 0x00B, 0x8C);
  addKaseikyoKey("PLAY_MODE", Unmapped_Key, 0x00B, 0x8D);
  addKaseikyoKey("ANGLE", Angle_Key, 0x00B, 0x90);
  addKaseikyoKey("SUBTITLE", Captions_Key, 0x00B, 0x91);
  addKaseikyoKey("INFO", Info_Key, 0x00B, 0x92);
  addKaseikyoKey("SETUP", Unmapped_Key, 0x00B, 0x94);
//  addKaseikyoKey("R-TUNE", PrevChannel_Key, 0x00B, 0x9B);
  addKaseikyoKey("TOP_MENU", DiscTitle_Key, 0x00B, 0x9B);
  addKaseikyoKey("A.SRD", Unmapped_Key, 0x00B, 0x9E);
  addKaseikyoKey("FL_SELECT", Unmapped_Key, 0x00B, 0xB6);
  addKaseikyoKey("DISC", Unmapped_Key, 0x00B, 0xB7);
  addKaseikyoKey("SEQUENTIAL", Unmapped_Key, 0x00B, 0xBF);
  addKaseikyoKey("CINEMA", Unmapped_Key, 0x00B, 0xC0);
  addKaseikyoKey("ZOOM", Zoom_Key, 0x00B, 0xC1);
  addKaseikyoKey("frec", Unmapped_Key, 0x00B, 0xC7);
  addKaseikyoKey("BASS", EnhancedBass_Key, 0x00B, 0xD4);
  addKaseikyoKey("D.ENH", Unmapped_Key, 0x00B, 0xD5);
  addKaseikyoKey("ONETOUCH_MEMORY", Unmapped_Key, 0x00B, 0xD6);
  addKaseikyoKey("GROUP", Unmapped_Key, 0x00B, 0xE0);
  addKaseikyoKey("SLEEP", Sleep_Key, 0x00B, 0xEB);
}


PanasonicDVD1a::PanasonicDVD1a(
  unsigned int index)
  : PanasonicDVD1(index)
{
  setKeysetName("DVD Keyset 1a");
}


void PanasonicDVD1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  PanasonicDVD1::populateProtocol(guiObject);

  addKaseikyoKey("channel2up", ChannelUp_Key, 0x00B, 0x34);
  addKaseikyoKey("channel2down", ChannelDown_Key, 0x00B, 0x35);
  addKaseikyoKey("INPUT_SELECT", Input_Key, 0x00B, 0x50);
}


PanasonicAudio1::PanasonicAudio1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 1",
      Panasonic_Make,
      index)
{
  addControlledDevice(Panasonic_Make, "RX-DS25", Audio_Device);
  addControlledDevice(Panasonic_Make, "RX-e300", Audio_Device);
}


void PanasonicAudio1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new KaseikyoProtocol(guiObject, index);

//  setPreData(0x40040543, 32);
  setPreData(0x2002, 16);

  addKaseikyoKey("INTRO", Unmapped_Key, 0xC2A, 0x46); // odd

  addKaseikyoKey("stop-clear", Stop_Key, 0xC2A, 0x80);
  addKaseikyoKey("repeat", Repeat_Key, 0xC2A, 0x81);
  addKaseikyoKey("random", Random_Key, 0xC2A, 0x82);
  addKaseikyoKey("eject", Eject_Key, 0xC2A, 0x8E);
  addKaseikyoKey("prev", Rewind_Key, 0xC2A, 0x84); // "CD_<<"
  addKaseikyoKey("next", FastForward_Key, 0xC2A, 0x85); // "CD_>>"
  addKaseikyoKey("CD_PAUSE", Pause_Key, 0xC2A, 0x86);
  addKaseikyoKey("play-pause", Play_Key, 0xC2A, 0x87);
  addKaseikyoKey("program", Program_Key, 0xC2A, 0x8B); // "MEMORY"
  addKaseikyoKey("cancel", Clear_Key, 0xC2A, 0x8D);
  addKaseikyoKey("display", Info_Key, 0xC2A, 0x8F);

  addKaseikyoKey("1", One_Key, 0xC2A, 0x90);
  addKaseikyoKey("2", Two_Key, 0xC2A, 0x91);
  addKaseikyoKey("3", Three_Key, 0xC2A, 0x92);
  addKaseikyoKey("4", Four_Key, 0xC2A, 0x93);
  addKaseikyoKey("5", Five_Key, 0xC2A, 0x94);
  addKaseikyoKey("6", Six_Key, 0xC2A, 0x95);
  addKaseikyoKey("7", Seven_Key, 0xC2A, 0x96);
  addKaseikyoKey("8", Eight_Key, 0xC2A, 0x97);
  addKaseikyoKey("9", Nine_Key, 0xC2A, 0x98);
  addKaseikyoKey("10/0", Zero_Key, 0xC2A, 0x99);
  addKaseikyoKey("+10", DoubleDigit_Key, 0xC2A, 0x9F);

  addKaseikyoKey("tape_stop", Unmapped_Key, 0xC2A, 0xA0);
  addKaseikyoKey("rew", Unmapped_Key, 0xC2A, 0xA2); // "TAPE_<<"
  addKaseikyoKey("ff", Unmapped_Key, 0xC2A, 0xA3); // "TAPE_>>"
  addKaseikyoKey("tape_record", Record_Key, 0xC2A, 0xA4);
  addKaseikyoKey("TAPE_PLAY_REWIND", Unmapped_Key, 0xC2A, 0xA5);
  addKaseikyoKey("tape_play", Unmapped_Key, 0xC2A, 0xA6); // "TAPE_PLAY_FORWARD"
  addKaseikyoKey("tape", TapeInput_Key, 0xC2A, 0xAC);
  addKaseikyoKey("TAPE_DECK", Unmapped_Key, 0xC2A, 0xAD);
  addKaseikyoKey("rev_mode", Unmapped_Key, 0xC2A, 0xAE); // "TAPE_REV_MODE"
  addKaseikyoKey("counter_reset", Reset_Key, 0xC2A, 0xAF);

  addKaseikyoKey("vol+", VolumeUp_Key, 0xC2A, 0xB0);
  addKaseikyoKey("vol-", VolumeDown_Key, 0xC2A, 0xB1);
  addKaseikyoKey("cd", CDInput_Key, 0xC2A, 0xB6);
  addKaseikyoKey("tuner-band", TunerBand_Key, 0xC2A, 0xB8);
  addKaseikyoKey("sleep", Sleep_Key, 0xC2A, 0xBC);
  addKaseikyoKey("power", Power_Key, 0xC2A, 0xBF);

  addKaseikyoKey("TRACK>>", Unmapped_Key, 0xC2A, 0xD0);
  addKaseikyoKey("TRACK<<", Unmapped_Key, 0xC2A, 0xD1);
  addKaseikyoKey("xbs", Unmapped_Key, 0xC2A, 0xD6);
  addKaseikyoKey("preset_eq", Unmapped_Key, 0xC2A, 0xD9);
  addKaseikyoKey("virtualizer", Unmapped_Key, 0xC2A, 0xDA); // "S.VIRT"

  addKaseikyoKey("fm-mode", FMMode_Key, 0xC2A, 0xE4); // "st-mono"
  addKaseikyoKey("TUNER_PRESET_TUNE_UP", NextPreset_Key, 0xC2A, 0xE7);
  addKaseikyoKey("TUNER_PRESET_TUNE_UP", Next_Key, 0xC2A, 0xE7);
  addKaseikyoKey("TUNER_PRESET_TUNE_DOWN", PrevPreset_Key, 0xC2A, 0xE8);
  addKaseikyoKey("TUNER_PRESET_TUNE_DOWN", Previous_Key, 0xC2A, 0xE8);
  addKaseikyoKey("tuning+", ChannelUp_Key, 0xC2A, 0xE9);
  addKaseikyoKey("tuning-", ChannelDown_Key, 0xC2A, 0xEA);
  addKaseikyoKey("AUTOSCAN", Scan_Key, 0xC2A, 0xEC);
  addKaseikyoKey("bp", Unmapped_Key, 0xC2A, 0xEF); // "TUNER_BP", beat-proof?

  addKaseikyoKey("panelopen", Unmapped_Key, 0xC2A, 0xF4);  // "TOP_PANEL_OPEN"
  addKaseikyoKey("panelclose", Unmapped_Key, 0xC2A, 0xF5); // "TOP_PANEL_CLOSE"
}


PanasonicAudio2::PanasonicAudio2(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 2",
      Panasonic_Make,
      index)
{
}


void PanasonicAudio2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new KaseikyoProtocol(guiObject, index);

  setPreData(0x2002, 16);

  addKaseikyoKey("Volume_Up", VolumeUp_Key, 0x00A, 0x20);
  addKaseikyoKey("Volume_Down", VolumeDown_Key, 0x00A, 0x21);
  addKaseikyoKey("Mute", Mute_Key, 0x00A, 0x32);
  addKaseikyoKey("INPUT:AUX", AuxInput_Key, 0x00A, 0x9A);
  addKaseikyoKey("Super_Woofer", Unmapped_Key, 0x00A, 0xC2);

  addKaseikyoKey("tuner", TunerInput_Key, 0x04A, 0xA4);

  addKaseikyoKey("tape", TapeInput_Key, 0x08A, 0x96);
  addKaseikyoKey("INPUT: TAPE Play", Unmapped_Key, 0x08A, 0x9E);

  addKaseikyoKey("repeat", Repeat_Key, 0x0AA, 0x47);
  addKaseikyoKey("random", Random_Key, 0x0AA, 0x4D);
  addKaseikyoKey("program", Program_Key, 0x0AA, 0x8A);
  addKaseikyoKey("cd", CDInput_Key, 0x00A, 0x94);
  addKaseikyoKey("aux", AuxInput_Key, 0x00A, 0x9A);
  addKaseikyoKey("cancel", Clear_Key, 0x0AA, 0xA3);
  addKaseikyoKey("Disc", NextDisc_Key, 0x0AA, 0xA4);

  addKaseikyoKey("Eq", Unmapped_Key, 0x10A, 0x83); // "Preset EQ"

  addKaseikyoKey("S.Sound EQ", Unmapped_Key, 0x12A, 0xC5);

  addKaseikyoKey("Stop", Stop_Key, 0x1CA, 0x00);
  addKaseikyoKey("Play_Reverse", Unmapped_Key, 0x1CA, 0x06);
  addKaseikyoKey("Play/Pause", Play_Key, 0x1CA, 0x0A);
  addKaseikyoKey("Play/Pause", Pause_Key, 0x1CA, 0x0A);
  addKaseikyoKey("1", One_Key, 0x1CA, 0x10);
  addKaseikyoKey("2", Two_Key, 0x1CA, 0x11);
  addKaseikyoKey("3", Three_Key, 0x1CA, 0x12);
  addKaseikyoKey("4", Four_Key, 0x1CA, 0x13);
  addKaseikyoKey("5", Five_Key, 0x1CA, 0x14);
  addKaseikyoKey("6", Six_Key, 0x1CA, 0x15);
  addKaseikyoKey("7", Seven_Key, 0x1CA, 0x16);
  addKaseikyoKey("8", Eight_Key, 0x1CA, 0x17);
  addKaseikyoKey("9", Nine_Key, 0x1CA, 0x18);
  addKaseikyoKey("0", Zero_Key, 0x1CA, 0x19);
  addKaseikyoKey("Power", Power_Key, 0x1CA, 0x3D);
  addKaseikyoKey("discrete on", PowerOn_Key, 0x1CA, 0x3E);
  addKaseikyoKey("discrete off", PowerOff_Key, 0x1CA, 0x3F);
  addKaseikyoKey("Back", Previous_Key, 0x1CA, 0x49);
  addKaseikyoKey("Forward", Next_Key, 0x1CA, 0x4A);
  addKaseikyoKey("Display", Info_Key, 0x1CA, 0x55);
  addKaseikyoKey(">10", DoubleDigit_Key, 0x1CA, 0x84);
  addKaseikyoKey("clock/timer", Timer_Key, 0x1CA, 0x95);
  addKaseikyoKey("Sleep", Sleep_Key, 0x1CA, 0x96);
  addKaseikyoKey("Dimmer", Unmapped_Key, 0x1CA, 0x97);
  addKaseikyoKey("play/record timer", Unmapped_Key, 0x1CA, 0x9B);
  addKaseikyoKey("play mode", Mode_Key, 0x1CA, 0xBB);
}


PanasonicAudio2a::PanasonicAudio2a(
  unsigned int index)
  : PanasonicAudio2(index)
{
  setKeysetName("Audio Keyset 2a");
}


void PanasonicAudio2a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  PanasonicAudio2::populateProtocol(guiObject);

  addKaseikyoKey("INPUT: CD play/pause", CDInput_Key, 0x0AA, 0x0A);
  addKaseikyoKey("INPUT: CD play/pause", Play_Key, 0x0AA, 0x0A);
  addKaseikyoKey("INPUT: CD play/pause", Pause_Key, 0x0AA, 0x0A);
}


PanasonicAC1::PanasonicAC1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Air Conditioner 1",
      Panasonic_Make,
      index)
{
}


void PanasonicAC1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x6681, 16);

  addKey("Operation", Power_Key, 0x81, 8);
  addKey("Air Swing", Yellow_Key, 0x83, 8);
  addKey("Temp Up", Red_Key, 0x85, 8);
  addKey("Temp Down", Blue_Key, 0x8A, 8);
  addKey("Economy", Green_Key, 0x8D, 8);
  addKey("Timer", Sleep_Key, 0x90, 8);
  addKey("Fan Speed", SoundMode_Key, 0x99, 8);
  addKey("Mode", PictureMode_Key, 0x9B, 8);
}
