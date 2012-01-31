#include "toshiba.h"
#include "necprotocol.h"
//#include "pirmakenames.h"

ToshibaTV1::ToshibaTV1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Toshiba_Make,
      index)
{
  addControlledDevice(Toshiba_Make, "21S03D", TV_Device);

  threadableProtocol = new NECProtocol(guiObject, index, Standard_NEC);

//  setPreData(0x02FD, 16);
  setPreData(0x40, 8);

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
  addKey("100", PlusOneHundred_Key, 0x0A, 8);
  addKey("-/--", DoubleDigit_Key, 0x0B, 8);
  addKey("reset", Reset_Key, 0x0C, 8);
  addKey("textzoom", TeletextSize_Key, 0x0D, 8); // "Enlarge"
  addKey("tv/video", Unmapped_Key, 0x0F, 8); // "input"
  addKey("MUTE", Mute_Key, 0x10, 8);
  addKey("BLANK", PictureMode_Key, 0x11, 8); // "Contrast", "picture_preset"
  addKey("POWER", Power_Key, 0x12, 8);
  addKey("mts", Unmapped_Key, 0x13, 8); // "audio_stereo_2channel"
  addKey("SCART", Input_Key, 0x14, 8); // "AV", "inputs", "source"
  addKey("sleep", Sleep_Key, 0x15, 8);  // Clock
  addKey("CALL", Unmapped_Key, 0x16, 8);
  addKey("ent", Enter_Key, 0x17, 8);  // "ch_rtn"
  addKey("TXT/MIX", Teletext_Key, 0x17, 8);
  addKey("fav+", Unmapped_Key, 0x19, 8);
  addKey("V+", VolumeUp_Key, 0x1A, 8);
  addKey("V+", Right_Key, 0x1A, 8);
  addKey("P+", ChannelUp_Key, 0x1B, 8);
  addKey("P+", Up_Key, 0x1B, 8);
  addKey("recall", PrevChannel_Key, 0x1C, 8);
  addKey("fav-", Unmapped_Key, 0x1D, 8);
  addKey("V-", VolumeDown_Key, 0x1E, 8);
  addKey("V-", Left_Key, 0x1E, 8);
  addKey("P-", ChannelDown_Key, 0x1F, 8);
  addKey("P-", Down_Key, 0x1F, 8);
  addKey("OK", Select_Key, 0x21, 8);
  addKey("POP_DIR", Unmapped_Key, 0x26, 8);
  addKey("textindex", Unmapped_Key, 0x2B, 8);
  addKey("textpages", Unmapped_Key, 0x2C, 8);
  addKey("a/d", Unmapped_Key, 0x44, 8);
  addKey("RED", Red_Key, 0x48, 8);
  addKey("GREEN", Green_Key, 0x49, 8);
  addKey("YELLOW", Yellow_Key, 0x4A, 8);
  addKey("pip_ch_up", PIPChannelUp_Key, 0x4A, 8); // Yellow
  addKey("BLUE", Blue_Key, 0x4B, 8);
  addKey("pip_ch_down", PIPChannelDown_Key, 0x4B, 8); // Blue
  addKey("still", Unmapped_Key, 0x4C, 8);
  addKey("locate", Unmapped_Key, 0x4E, 8);
  addKey("source", Unmapped_Key, 0x4F, 8);
  addKey("pip", PIP_Key, 0x51, 8);
  addKey("Double_Arrow", Unmapped_Key, 0x52, 8); // "swap", but not pip!; "back"
  addKey("swap", PIPSwap_Key, 0x53, 8); // Reduce
  addKey("texthold", TeletextHold_Key, 0x53, 8);
  addKey("PIC_SIZE", AspectRatio_Key, 0x54, 8); // "16:9"
  addKey("textanswer", TeletextReveal_Key, 0x54, 8); // "?"
  addKey("Tone", Unmapped_Key, 0x55, 8);
  addKey("cap/text", Captions_Key, 0x57, 8); // Image
  addKey("exit", Exit_Key, 0x58, 8);
  addKey("SIZE", AspectRatio_Key, 0x59, 8); // "WIDE"
  addKey("DOULBY", Unmapped_Key, 0x5A, 8);
  addKey("1/2", Audio_Key, 0x63, 8); // "cap1/cap2"
  addKey("MENU", Menu_Key, 0x5B, 8);
  addKey("CLOCK", Timer_Key, 0x71, 8);  // "TIMER"
  addKey("TV", Unmapped_Key, 0x72, 8);
  addKey("SEARCH", Unmapped_Key, 0x8F, 8);
  addKey("favorite", Favorites_Key, 0x90, 8);
  addKey("multi", Unmapped_Key, 0x91, 8);
  addKey("info", Info_Key, 0x93, 8);
}


ToshibaTV1a::ToshibaTV1a(
  QObject *guiObject,
  unsigned int index)
  : ToshibaTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1a");

  addControlledDevice(Toshiba_Make, "27A51", TV_Device);

  addKey("menu/enter", Menu_Key, 0x80, 8);
  addKey("menu/enter", Select_Key, 0x80, 8);
}


ToshibaTV1b::ToshibaTV1b(
  QObject *guiObject,
  unsigned int index)
  : ToshibaTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1b");

  addKey("right", Right_Key, 0x19, 8); // "fav+"
  addKey("left", Left_Key, 0x1D, 8); // "fav-"
  addKey("menu/enter", Menu_Key, 0x80, 8);
  addKey("menu/enter", Select_Key, 0x80, 8);
  addKey("up", Up_Key, 0x82, 8); // "set+"
  addKey("down", Down_Key, 0x83, 8); // "set-"
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
  addKey("stillpicture", Pause_Key, 0x44BB, 16);
  addKey("24-", Unmapped_Key, 0x2AD5, 16);
  addKey("page-", PageUp_Key, 0xCA35, 16);
  addKey("page+", PageDown_Key, 0xB04F, 16);
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


ToshibaTV1f::ToshibaTV1f(
  QObject *guiObject,
  unsigned int index)
  : ToshibaTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1f");

  addControlledDevice(Toshiba_Make, "Regza AV50*", TV_Device);

  addKey("back", PrevChannel_Key, 0x4AB5, 16);
  addKey("exit", Exit_Key, 0xC23D, 16);
  addKey("info", Info_Key, 0x6897, 16);
  addKey("stillpicture", Pause_Key, 0x44BB, 16);
}


ToshibaTV1g::ToshibaTV1g(
  QObject *guiObject,
  unsigned int index)
  : ToshibaTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1g");

  addKey("menu", Menu_Key, 0x80, 8);
  addKey("set+", Right_Key, 0x82, 8);
  addKey("set-", Left_Key, 0x83, 8);
  addKey("enter", Select_Key, 0x89, 8);
}


ToshibaVCR1::ToshibaVCR1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      Toshiba_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index, Standard_NEC);

  setPreData(0x44, 16);

  addKey("1", One_Key, 0x01, 8);
  addKey("2", Two_Key, 0x02, 8);
  addKey("3", Three_Key, 0x03, 8);
  addKey("4", Four_Key, 0x04, 8);
  addKey("5", Five_Key, 0x05, 8);
  addKey("6", Six_Key, 0x06, 8);
  addKey("7", Seven_Key, 0x07, 8);
  addKey("8", Eight_Key, 0x08, 8);
  addKey("9", Nine_Key, 0x09, 0);
  addKey("0", Zero_Key, 0x0A, 8);
  addKey("100", PlusOneHundred_Key, 0x0B, 8);
  addKey("slow/dir_fwd", StepForward_Key, 0x0D, 8);
  addKey("pause", Pause_Key, 0x10, 8);
  addKey("tv/vcr", Input_Key, 0x11, 8);
  addKey("power", Power_Key, 0x12, 8);
  addKey("ff", FastForward_Key, 0x13, 8);
  addKey("stop", Stop_Key, 0x14, 8);
  addKey("play", Play_Key, 0x15, 8);
  addKey("record", Record_Key, 0x18, 8);
  addKey("rew", Rewind_Key, 0x19, 8);
  addKey("ch+", ChannelUp_Key, 0x1B, 8);
  addKey("ch-", ChannelDown_Key, 0x1F, 8);
  addKey("input", Input_Key, 0x5F, 8);
  addKey("recall", PrevChannel_Key, 0x83, 8);
  addKey("skip", Next_Key, 0x9E, 8);
  addKey("previous", Previous_Key, 0x9F, 8);
  addKey("eject", Eject_Key, 0xF5, 8);
}


ToshibaVCR1a::ToshibaVCR1a(
  QObject *guiObject,
  unsigned int index)
  : ToshibaVCR1(guiObject, index)
{
  setKeysetName("VCR Keyset 1a");

  addKey("ch+", ChannelUp_Key, 0x1E, 8);
//  addKey("ch-", ChannelDown_Key, 0x1F, 8); // Already in parent
}


ToshibaDisc1::ToshibaDisc1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Disc Keyset 1",
      Toshiba_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index, Standard_NEC);

//  setPreData(0xA25D, 16);
  setPreData(0x45, 8);

  addKey("pause", Pause_Key, 0x00, 8);
  addKey("1", One_Key, 0x01, 8);
  addKey("2", Two_Key, 0x02, 8);
  addKey("3", Three_Key, 0x03, 8);
  addKey("4", Four_Key, 0x04, 8);
  addKey("5", Five_Key, 0x05, 8);
  addKey("6", Six_Key, 0x06, 8);
  addKey("7", Seven_Key, 0x07, 8);
  addKey("8", Eight_Key, 0x08, 8);
  addKey("9", Nine_Key, 0x09, 8);
  addKey("0", Zero_Key, 0x0A, 8);
  addKey("slow/dir-fwd", StepForward_Key, 0x0D, 8);
  addKey("slow/dir-rev", StepBack_Key, 0x0E, 8);
  addKey("power", Power_Key, 0x12, 8);
  addKey("ff", FastForward_Key, 0x13, 8);
  addKey("stop", Stop_Key, 0x14, 8);
  addKey("play", Play_Key, 0x15, 8);
  addKey("display", Info_Key, 0x16, 8);
  addKey("rew", Rewind_Key, 0x19, 8);
  addKey("menu/enter", Menu_Key, 0x21, 8); // "ok", "enter"
  addKey("menu/enter", Select_Key, 0x21, 8); // "ok", "enter"
  addKey("exit", Exit_Key, 0x22, 8);
  addKey("skip-", Previous_Key, 0x23, 8);
  addKey("skip+", Next_Key, 0x24, 8);
  addKey("+10", DoubleDigit_Key, 0x25, 8);
  addKey("100", PlusOneHundred_Key, 0x25, 8);
  addKey("T", Unmapped_Key, 0x26, 8); // direct access to title by number
  addKey("SUBTITLE", Captions_Key, 0x28, 8);
  addKey("KEY_ANGLE", Angle_Key, 0x29, 8);
  addKey("MEMORY", Program_Key, 0x2A, 8);
  addKey("REPEAT", Repeat_Key, 0x2B, 8);
  addKey("A-B_RPT", RepeatAB_Key, 0x2C, 8);
  addKey("RANDOM", Random_Key, 0x2E, 8);
  addKey("FL_DIMMER", Unmapped_Key, 0x41, 8); // "FlDim"
  addKey("3D", Unmapped_Key, 0x43, 8);
  addKey("disc", DiscSelect_Key, 0x4A, 8); // "DISC SELECT"
  addKey("vol+", VolumeUp_Key, 0x4D, 8);
  addKey("right", Right_Key, 0x4D, 8); // "vol+"
  addKey("vol-", VolumeDown_Key, 0x51, 8);
  addKey("left", Left_Key, 0x51, 8); // "vol-"
  addKey("ch+", ChannelUp_Key, 0x80, 8);
  addKey("up", Up_Key, 0x80, 8); // "ch+"
  addKey("ch-", ChannelDown_Key, 0x81, 8);
  addKey("down", Down_Key, 0x81, 8); // "ch-"
  addKey("menu", DiscMenu_Key, 0x84, 8);
  addKey("FlSelect", Unmapped_Key, 0xD7, 8);
  addKey("top_menu", DiscTitle_Key, 0xDE, 8); // "title"
  addKey("clear", Clear_Key, 0xEF, 8);
  addKey("eject", Eject_Key, 0xF5, 8);
}


ToshibaDisc1a::ToshibaDisc1a(
  QObject *guiObject,
  unsigned int index)
  : ToshibaDisc1(guiObject, index)
{
  setKeysetName("Disc Keyset 1a");

  addKey("setup", Menu_Key, 0x20, 8);
  addKey("audio", Audio_Key, 0x27, 8);
  addKey("action", Unmapped_Key, 0x84, 8);
}



ToshibaDisc1b::ToshibaDisc1b(
  QObject *guiObject,
  unsigned int index)
  : ToshibaDisc1(guiObject, index)
{
  setKeysetName("Disc Keyset 1b");

  addKey("enter", Select_Key, 0x84, 8);
  addKey("mark", Unmapped_Key, 0x21, 8);
}


ToshibaDisc1c::ToshibaDisc1c(
  QObject *guiObject,
  unsigned int index)
  : ToshibaDisc1a(guiObject, index)
{
  setKeysetName("Disc Keyset 1c");

  addKey("KEY_DVD", Unmapped_Key, 0x22, 8);
  addKey("KEY_SLOW", Slow_Key, 0x26, 8);
  addKey("KEY_FAVORITES", Favorites_Key, 0xDE, 8);
  addKey("KEY_EJECTCD", Eject_Key, 0xDF, 8);
}


ToshibaDisc1d::ToshibaDisc1d(
  QObject *guiObject,
  unsigned int index)
  : ToshibaDisc1a(guiObject, index)
{
  setKeysetName("Disc Keyset 1d");

  addKey("recall", PrevChannel_Key, 0x16, 8);
}
