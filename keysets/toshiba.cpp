#include "toshiba.h"
#include "necprotocol.h"
#include "pirmakenames.h"

ToshibaTV1::ToshibaTV1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Toshiba_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index);

  setPreData(0x02FD, 16);

  addKey("POWER", Power_Key, 0x48B7, 16);
  addKey("1", One_Key, 0x807F, 16);
  addKey("2", Two_Key, 0x40BF, 16);
  addKey("3", Three_Key, 0xC03F, 16);
  addKey("4", Four_Key, 0x20DF, 16);
  addKey("5", Five_Key, 0xA05F, 16);
  addKey("6", Six_Key, 0x609F, 16);
  addKey("7", Seven_Key, 0xE01F, 16);
  addKey("8", Eight_Key, 0x10EF, 16);
  addKey("9", Nine_Key, 0x906F, 16);
  addKey("0", Zero_Key, 0x00FF, 16);
  addKey("TV", Unmapped_Key, 0x4EB1, 16);
  addKey("SCART", Unmapped_Key, 0x28D7, 16); // "AV", "inputs", "source"
  addKey("CALL", Unmapped_Key, 0x6897, 16);
  addKey("-/--", DoubleDigit_Key, 0xD02F, 16);
  addKey("DOULBY", Unmapped_Key, 0x5AA5, 16);
  addKey("CLOCK", Unmapped_Key, 0x8E71, 16);  // "TIMER"
  addKey("RED", Red_Key, 0x12ED, 16);
  addKey("GREEN", Green_Key, 0x926D, 16);
  addKey("YELLOW", Yellow_Key, 0x52AD, 16);
  addKey("BLUE", Blue_Key, 0xD22D, 16);
  addKey("MUTE", Mute_Key, 0x08F7, 16);
  addKey("SIZE", AspectRatio_Key, 0x9A65, 16); // "WIDE"
  addKey("P+", ChannelUp_Key, 0xD827, 16);
  addKey("P-", ChannelDown_Key, 0xF807, 16);
  addKey("V+", VolumeUp_Key, 0x58A7, 16);
  addKey("V-", VolumeDown_Key, 0x7887, 16);
  addKey("MENU", Menu_Key, 0xDA25, 16);
  addKey("OK", Select_Key, 0x847B, 16);
  addKey("P+", Up_Key, 0xD827, 16);
  addKey("P-", Down_Key, 0xF807, 16);
  addKey("V-", Left_Key, 0x7887, 16);
  addKey("V+", Right_Key, 0x58A7, 16);
  addKey("exit", Exit_Key, 0x1AE5, 16);
  addKey("100", PlusOneHundred_Key, 0x50AF, 16);
  addKey("recall", PrevChannel_Key, 0x38C7, 16);
  addKey("tv/video", Input_Key, 0xF00F, 16); // "input"
  addKey("fav+", Unmapped_Key, 0x9867, 16);
  addKey("reset", Reset_Key, 0x30CF, 16);
  addKey("cap/text", Captions_Key, 0xEA15, 16); // Image
  addKey("1/2", Unmapped_Key, 0xC639, 16); // "cap1/cap2"
  addKey("fav-", Unmapped_Key, 0xB847, 16);
  addKey("still", Unmapped_Key, 0x32CD, 16);
  addKey("locate", Unmapped_Key, 0x728D, 16);
  addKey("swap", PIPSwap_Key, 0xCA35, 16); // Reduce
  addKey("pip", PIP_Key, 0x8A75, 16);
  addKey("pip_ch_up", Unmapped_Key, 0x52AD, 16); // Yellow
  addKey("pip_ch_down", Unmapped_Key, 0xD22D, 16); // Blue
  addKey("mts", Language_Key, 0xC837, 16); // "audio_stereo_2channel"
  addKey("sleep", Sleep_Key, 0xA857, 16);  // Clock
  addKey("BLANK", PictureMode_Key, 0x8877, 16); // "Contrast", "picture_preset"
  addKey("Double_Arrow", Unmapped_Key, 0x4AB5, 16); // "swap", but not pip!; "back"
//  addKey("?", Unmapped_Key, 0x2AD5, 16);
  addKey("PIC_SIZE", AspectRatio_Key, 0x2AD5, 16); // "16:9"
  addKey("Enlarge", Unmapped_Key, 0xB04F, 16);
  addKey("multi", Unmapped_Key, 0x8976, 16);
  addKey("source", Unmapped_Key, 0xF20D, 16);
  addKey("info", Info_Key, 0xC936, 16);
  addKey("favorite", Favorites_Key, 0x09F6, 16);
  addKey("Tone", Unmapped_Key, 0xAA55, 16);
  addKey("POP_DIR", Unmapped_Key, 0x649B, 16);
  addKey("a/d", Unmapped_Key, 0x22DD, 16);
  addKey("SEARCH", Unmapped_Key, 0xF10E, 16);

  // teletext stuff:
//  addKey("TXT/MIX", Unmapped_Key, 0xE817, 16);  // "ent", "ch_rtn"
//  addKey("textindex", Unmapped_Key, 0xD42B, 16);
//  addKey("textpages", Unmapped_Key, 0x34CB, 16);
//  addKey("textanswer", Unmapped_Key, 0x2AD5, 16);
//  addKey("texthold", Unmapped_Key, 0xCA35, 16);
//  addKey("textzoom", Unmapped_Key, 0xB04F, 16);
//  addKey("texttime", Unmapped_Key, 0xA857, 16);
}


ToshibaTV1a::ToshibaTV1a(
  QObject *guiObject,
  unsigned int index)
  : ToshibaTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1a");

  addKey("enter", Select_Key, 0x01FE, 16);
}


ToshibaTV1b::ToshibaTV1b(
  QObject *guiObject,
  unsigned int index)
  : ToshibaTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1b");

  addKey("menu", Menu_Key, 0x01FE, 16);
  addKey("up", Up_Key, 0x41BE, 16); // "set+"
  addKey("down", Down_Key, 0xC13E, 16); // "set-"
  addKey("left", Left_Key, 0xB847, 16);
  addKey("right", Right_Key, 0x9867, 16);
//  addKey("enter", Select_Key, 0x916E, 16);
  addKey("menu/enter", Select_Key, 0x01FE, 16);
}


ToshibaTV1c::ToshibaTV1c(
  QObject *guiObject,
  unsigned int index)
  : ToshibaTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1c");

  addKey("exit", Exit_Key, 0xC23D, 16);
  addKey("pipswap", PIPSwap_Key, 0x1AE5, 16);
  addKey("osdinfo", Info_Key, 0x6897, 16);
}


ToshibaTV1d::ToshibaTV1d(
  QObject *guiObject,
  unsigned int index)
  : ToshibaTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1d");

  addKey("Left", Left_Key, 0x42BD, 16);
  addKey("Right", Right_Key, 0x02FD, 16);
  addKey("Down", Down_Key, 0xB847, 16);
  addKey("Up", Up_Key, 0x9867, 16);
  addKey("Back", Exit_Key, 0xC23D, 16);
  addKey("guide", Guide_Key, 0xA25D, 16);
  addKey("tv/fav/radio", Favorites_Key, 0xE21D, 16); // might be wrong
  addKey("info", Info_Key, 0x6897, 16); // might be wrong
  addKey("subtitle", Captions_Key, 0x30CF, 16);
  addKey("stillpicture", Unmapped_Key, 0x44BB, 16);
  addKey("24-", Unmapped_Key, 0x2AD5, 16);
  addKey("page-", Unmapped_Key, 0xCA35, 16);
  addKey("page+", Unmapped_Key, 0xB04F, 16);
  addKey("24+", Unmapped_Key, 0xA857, 16);
}


ToshibaTV1e::ToshibaTV1e(
  QObject *guiObject,
  unsigned int index)
  : ToshibaTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1e");

  addKey("STOP", Stop_Key, 0xF20D, 16);
  addKey("PLAY", Play_Key, 0x8A75, 16);
  addKey("SKIPPREV", Previous_Key, 0x8877, 16);
  addKey("SKIPNEXT", Next_Key, 0xCA35, 16);
  addKey("frev", Rewind_Key, 0xD22D, 16);
  addKey("FFWD", FastForward_Key, 0x52AD, 16);
}


ToshibaVCR1::ToshibaVCR1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      Toshiba_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index);

  setPreData(0x22DD, 16);

  addKey("power", Power_Key, 0x48B7, 16);
  addKey("1", One_Key, 0x807F, 16);
  addKey("2", Two_Key, 0x40BF, 16);
  addKey("3", Three_Key, 0xC03F, 16);
  addKey("4", Four_Key, 0x20DF, 16);
  addKey("5", Five_Key, 0xA05F, 16);
  addKey("6", Six_Key, 0x609F, 16);
  addKey("7", Seven_Key, 0xE01F, 16);
  addKey("8", Eight_Key, 0x10EF, 16);
  addKey("9", Nine_Key, 0x906F, 16);
  addKey("0", Zero_Key, 0x50AF, 16);
  addKey("input", Input_Key, 0xFA05, 16);
  addKey("ch+", ChannelUp_Key, 0xD827, 16);
  addKey("ch-", ChannelDown_Key, 0xF807, 16);
  addKey("pause", Pause_Key, 0x08F7, 16);
  addKey("play", Play_Key, 0xA857, 16);
  addKey("rew", Rewind_Key, 0x9867, 16);
  addKey("ff", FastForward_Key, 0xC837, 16);
  addKey("eject", Eject_Key, 0xAF50, 16);
  addKey("stop", Stop_Key, 0x28D7, 16);
  addKey("previous", Previous_Key, 0xF906, 16);
  addKey("skip", Next_Key, 0x7986, 16);
  addKey("tv/vcr", Input_Key, 0x8877, 16);
  addKey("record", Record_Key, 0x18E7, 16);
  addKey("100", PlusOneHundred_Key, 0xD02F, 16);
  addKey("recall", PrevChannel_Key, 0xC13E, 16);
  addKey("slow/dir_fwd", StepForward_Key, 0xB04F, 16);
}


ToshibaVCR1a::ToshibaVCR1a(
  QObject *guiObject,
  unsigned int index)
  : ToshibaVCR1(guiObject, index)
{
  setKeysetName("VCR Keyset 1a");

  addKey("ch+", ChannelUp_Key, 0x7887, 16);
  addKey("ch-", ChannelDown_Key, 0xF807, 16);
}


ToshibaDisc1::ToshibaDisc1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Disc Keyset 1",
      Toshiba_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index);

  setPreData(0xA25D, 16);

  addKey("power", Power_Key, 0x48B7, 16);
  addKey("1", One_Key, 0x807F, 16);
  addKey("2", Two_Key, 0x40BF, 16);
  addKey("3", Three_Key, 0xC03F, 16);
  addKey("4", Four_Key, 0x20DF, 16);
  addKey("5", Five_Key, 0xA05F, 16);
  addKey("6", Six_Key, 0x609F, 16);
  addKey("7", Seven_Key, 0xE01F, 16);
  addKey("8", Eight_Key, 0x10EF, 16);
  addKey("9", Nine_Key, 0x906F, 16);
  addKey("0", Zero_Key, 0x50AF, 16);
  addKey("+10", DoubleDigit_Key, 0xA45B, 16);
  addKey("vol-", VolumeDown_Key, 0x8A75, 16);
  addKey("vol+", VolumeUp_Key, 0xB24D, 16);
  addKey("ch+", ChannelUp_Key, 0x01FE, 16);
  addKey("ch-", ChannelDown_Key, 0x817E, 16);
  addKey("display", Info_Key, 0x6897, 16);
  addKey("clear", Clear_Key, 0xF708, 16);
  addKey("top_menu", DiscTitle_Key, 0x7B84, 16);
  addKey("menu", DiscMenu_Key, 0x21DE, 16);
  addKey("enter", Select_Key, 0x847B, 16); // "ok"
  addKey("exit", Exit_Key, 0x44BB, 16);
  addKey("up", Up_Key, 0x01FE, 16); // "ch+"
  addKey("down", Down_Key, 0x817E, 16); // "ch-"
  addKey("left", Left_Key, 0x8A75, 16); // "vol-"
  addKey("right", Right_Key, 0xB24D, 16); // "vol+"
  addKey("rew", Rewind_Key, 0x9867, 16);
  addKey("play", Play_Key, 0xA857, 16);
  addKey("ff", FastForward_Key, 0xC837, 16);
  addKey("stop", Stop_Key, 0x28D7, 16);
  addKey("pause", Pause_Key, 0x00FF, 16);
  addKey("skip-", Previous_Key, 0xC43B, 16);
  addKey("skip+", Next_Key, 0x24DB, 16);
  addKey("eject", Eject_Key, 0xAF50, 16);
  addKey("slow/dir-rev", StepBack_Key, 0x708F, 16);
  addKey("slow/dir-fwd", StepForward_Key, 0xB04F, 16);
  addKey("disc", DiscSelect_Key, 0x52AD, 16); // "DISC SELECT"
  addKey("FL_DIMMER", Unmapped_Key, 0x827D, 16);
  addKey("3D", Unmapped_Key, 0xC23D, 16);
  addKey("KEY_ANGLE", Unmapped_Key, 0x946B, 16);
  addKey("SUBTITLE", Captions_Key, 0x14EB, 16);
  addKey("T", Unmapped_Key, 0x649B, 16);
  addKey("RANDOM", Unmapped_Key, 0x748B, 16);
  addKey("MEMORY", Unmapped_Key, 0x54AB, 16);
  addKey("REPEAT", Unmapped_Key, 0xD42B, 16);
  addKey("A-B_RPT", Unmapped_Key, 0x34CB, 16);
  addKey("FlSelect", Unmapped_Key, 0xEB14, 16);
  addKey("FlDim", Unmapped_Key, 0x827D, 16);
}


ToshibaDisc1a::ToshibaDisc1a(
  QObject *guiObject,
  unsigned int index)
  : ToshibaDisc1(guiObject, index)
{
  setKeysetName("Disc Keyset 1a");

  addKey("100", PlusOneHundred_Key, 0xA45B, 16);
  addKey("action", Unmapped_Key, 0x21DE, 16);
  addKey("setup", Menu_Key, 0x04FB, 16);
  addKey("title", DiscTitle_Key, 0x7B84, 16);
  addKey("audio", Language_Key, 0xE41B, 16);
  addKey("menu/enter", Select_Key, 0x847B, 16); // also menu?
}



ToshibaDisc1b::ToshibaDisc1b(
  QObject *guiObject,
  unsigned int index)
  : ToshibaDisc1(guiObject, index)
{
  setKeysetName("Disc Keyset 1b");

  addKey("100", PlusOneHundred_Key, 0xA45B, 16);
  addKey("enter", Select_Key, 0x21DE, 16);
  addKey("mark", Unmapped_Key, 0x847B, 16);
}


ToshibaDisc1c::ToshibaDisc1c(
  QObject *guiObject,
  unsigned int index)
  : ToshibaDisc1a(guiObject, index)
{
  setKeysetName("Disc Keyset 1c");

  addKey("KEY_SLOW", Unmapped_Key, 0x649B, 16);
  addKey("KEY_DVD", Unmapped_Key, 0x44BB, 16);
  addKey("KEY_FAVORITES", Favorites_Key, 0x7B84, 16);
  addKey("KEY_EJECTCD", Eject_Key, 0xFB04, 16);
}


ToshibaDisc1d::ToshibaDisc1d(
  QObject *guiObject,
  unsigned int index)
  : ToshibaDisc1a(guiObject, index)
{
  setKeysetName("Disc Keyset 1d");

  addKey("recall", PrevChannel_Key, 0x6897, 16);
}
