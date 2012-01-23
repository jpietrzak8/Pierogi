#include "lg.h"
#include "necprotocol.h"
#include "rc5protocol.h"
#include "pirmakenames.h"

LGTV1::LGTV1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      LG_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index);

  setPreData(0x20DF, 16);

  addKey("power", Power_Key, 0x10EF, 16);
  addKey("input", Input_Key, 0xD02F, 16);
  addKey("energy", Unmapped_Key, 0xA956, 16); // "EYEASTERISK"
  addKey("tv/radio", Unmapped_Key, 0x0FF0, 16);
  addKey("avmode", Unmapped_Key, 0x0CF3, 16); // "UPDATE"
  addKey("1", One_Key, 0x8877, 16);
  addKey("2", Two_Key, 0x48B7, 16);
  addKey("3", Three_Key, 0xC837, 16);
  addKey("4", Four_Key, 0x28D7, 16);
  addKey("5", Five_Key, 0xA857, 16);
  addKey("6", Six_Key, 0x6897, 16);
  addKey("7", Seven_Key, 0xE817, 16);
  addKey("8", Eight_Key, 0x18E7, 16);
  addKey("9", Nine_Key, 0x9867, 16);
  addKey("0", Zero_Key, 0x08F7, 16);
  addKey("list", Unmapped_Key, 0xCA35, 16);
  addKey("qview", Unmapped_Key, 0x58A7, 16);
  addKey("vol+", VolumeUp_Key, 0x40BF, 16);
  addKey("vol-", VolumeDown_Key, 0xC03F, 16);
  addKey("mute", Mute_Key, 0x906F, 16);
  addKey("p+", ChannelUp_Key, 0x00FF, 16);
  addKey("p-", ChannelDown_Key, 0x807F, 16);
  addKey("up", Up_Key, 0x02FD, 16);
  addKey("down", Down_Key, 0x827D, 16);
  addKey("left", Left_Key, 0xE01F, 16);
  addKey("right", Right_Key, 0x609F, 16);
  addKey("ok", Select_Key, 0x22DD, 16);
  addKey("menu", Menu_Key, 0xC23D, 16);
  addKey("return/exit", Exit_Key, 0x14EB, 16);
  addKey("red", Red_Key, 0x4EB1, 16);
  addKey("green", Green_Key, 0x8E71, 16);
  addKey("yellow", Yellow_Key, 0xC639, 16);
  addKey("blue", Blue_Key, 0x8679, 16);
  addKey("green/stop", Stop_Key, 0x8E71, 16);
  addKey("yellow/play", Play_Key, 0xC639, 16);
  addKey("blue/pause", Pause_Key, 0x8679, 16);
  addKey("text", Unmapped_Key, 0x04FB, 16);
  addKey("topt", Unmapped_Key, 0x847B, 16);
  addKey("topt/rev", Rewind_Key, 0x847B, 16);
  addKey("subtitle", Captions_Key, 0x9C63, 16); // "cc"
  addKey("subtitle/ffw", FastForward_Key, 0x9C63, 16);
  addKey("rec", Record_Key, 0xBD42, 16);
  addKey("simplink", Unmapped_Key, 0x7E81, 16);
  addKey("qmenu", Unmapped_Key, 0xA25D, 16);
  addKey("info", Info_Key, 0x55AA, 16);
  addKey("guide", Guide_Key, 0xD52A, 16);
  addKey("fav", Unmapped_Key, 0x7887, 16);
  addKey("brt.w", Unmapped_Key, 0x7689, 16);
  addKey("sound", Unmapped_Key, 0xB04F, 16);
  addKey("auto", Unmapped_Key, 0x2AD5, 16);
  addKey("comp-rgb-dvi", Unmapped_Key, 0x19E6, 16);
  addKey("sleep", Sleep_Key, 0x708F, 16);
  addKey("sap", Unmapped_Key, 0x50AF, 16);
  addKey("ratio", AspectRatio_Key, 0x9E61, 16);
  addKey("video", Unmapped_Key, 0xB24D, 16); // "apc", "PSM"
  addKey("picture", Unmapped_Key, 0x30CF, 16);
  addKey("review", Unmapped_Key, 0x58A7, 16);
  addKey("memory/erase", Unmapped_Key, 0xAA55, 16);
  addKey("sound", Unmapped_Key, 0x4AB5, 16); // "SSM"
  addKey("INDEX", Unmapped_Key, 0xE41B, 16);
  addKey("MIX", Unmapped_Key, 0x24DB, 16);
  addKey("TIME", Unmapped_Key, 0x649B, 16);
  addKey("TV/PC", Unmapped_Key, 0x0AF5, 16);
  addKey("xstudio", Unmapped_Key, 0x3EC1, 16);
}


LGTV1a::LGTV1a(
  QObject *guiObject,
  unsigned int index)
  : LGTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1a");

  addKey("exit", Exit_Key, 0xDA25, 16);
  addKey("pip", PIP_Key, 0x06F9, 16);
//  addKey("pop", Unmapped_Key, 0x8679, 16);
  addKey("swap", PIPSwap_Key, 0xC639, 16);
  addKey("*", Unmapped_Key, 0x9C63, 16);
  addKey("pipch-", Unmapped_Key, 0x4EB1, 16);
  addKey("pipch+", Unmapped_Key, 0x8E71, 16);
  addKey("pipinput", Unmapped_Key, 0x8679, 16);
  addKey("freeze", Unmapped_Key, 0xA659, 16);
  addKey("zoom", Unmapped_Key, 0xDE21, 16);
  addKey("signal", Unmapped_Key, 0x6996, 16);
  addKey("adjust", Unmapped_Key, 0xD32C, 16);
}


LGTV1b::LGTV1b(
  QObject *guiObject,
  unsigned int index)
  : LGTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1b");

  addKey("Vol-/Left_Arrow", Left_Key, 0xC03F, 16);
  addKey("Vol+/Right_Arrow", Right_Key, 0x40BF, 16);
  addKey("PR+/Up_Arrow", Up_Key, 0x00FF, 16);
  addKey("PR-/Down_Arrow", Down_Key, 0x807F, 16);
  addKey("I/II", DoubleDigit_Key, 0x50AF, 16);
  addKey("orange", Red_Key, 0x03FC, 16);
  addKey("green", Green_Key, 0xC33C, 16);
  addKey("yellow", Yellow_Key, 0x837C, 16);
  addKey("blue", Blue_Key, 0x43BC, 16);
}


LGTV1c::LGTV1c(
  QObject *guiObject,
  unsigned int index)
  : LGTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1c");

  addKey("stop", Stop_Key, 0x8D72, 16);
  addKey("play", Play_Key, 0x0DF2, 16);
  addKey("pause", Pause_Key, 0x5DA2, 16);
  addKey("rec", Record_Key, 0xBD42, 16);
  addKey("backward", Rewind_Key, 0xF10E, 16);
  addKey("forward", FastForward_Key, 0x718E, 16);
  addKey("pip", PIP_Key, 0x06F9, 16);
}


LGTV2::LGTV2(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 2",
      LG_Make,
      index)
{
  RC5Protocol *rp = new RC5Protocol(
    guiObject,
    index,
    800, 800,
    800,
    107000, true);

  threadableProtocol = rp;

  rp->setToggleBit(2);

  setPreData(0x10, 5);

  addKey("POWER", Power_Key, 0x0C, 8);
  addKey("DRP", Unmapped_Key, 0x14, 8);
  addKey("TVAV", Unmapped_Key, 0x38, 8);
  addKey("TURBOSOUND", Unmapped_Key, 0x24, 8);
  addKey("TURBOPICTURE", Unmapped_Key, 0x13, 8);
  addKey("PIP", PIP_Key, 0x3A, 8);
  addKey("TEXT", Unmapped_Key, 0x3C, 8);
  addKey("PR-MINUS", Unmapped_Key, 0x37, 8);
  addKey("PR-PLUS", Unmapped_Key, 0x36, 8);
  addKey("SWAP", PIPSwap_Key, 0x32, 8);
  addKey("INPUT", Input_Key, 0x34, 8);
  addKey("MENU", Menu_Key, 0x3B, 8);
  addKey("MUTE", Mute_Key, 0x0D, 8);
  addKey("PROGUP", ChannelUp_Key, 0x20, 8);
  addKey("PROGDOWN", ChannelDown_Key, 0x21, 8);
  addKey("VOLDOWN", VolumeDown_Key, 0x11, 8);
  addKey("VOLUP", VolumeUp_Key, 0x10, 8);
  addKey("OK", Select_Key, 0x25, 8);
  addKey("1", One_Key, 0x01, 8);
  addKey("2", Two_Key, 0x02, 8);
  addKey("3", Three_Key, 0x03, 8);
  addKey("4", Four_Key, 0x04, 8);
  addKey("5", Five_Key, 0x05, 8);
  addKey("6", Six_Key, 0x06, 8);
  addKey("7", Seven_Key, 0x07, 8);
  addKey("8", Eight_Key, 0x08, 8);
  addKey("9", Nine_Key, 0x09, 8);
  addKey("0", Zero_Key, 0x00, 8);
  addKey("PSM", Unmapped_Key, 0x0E, 8); // preset picture
  addKey("SSM", Unmapped_Key, 0x16, 8); // preset sound
  addKey("POS", Unmapped_Key, 0x2D, 8); // position, "UPDATE"
  addKey("2-12PIP", Unmapped_Key, 0x35, 8); // strobe, "KEY_SHOP"
  addKey("STILL", Pause_Key, 0x29, 8); // "KEY_PAUSE", "HOLD"
  addKey("SIZE", Unmapped_Key, 0x2B, 8);  // "KEY_SAVE"
  addKey("TIME", Unmapped_Key, 0x2A, 8);
  addKey("REVEAL", Unmapped_Key, 0x2C, 8); // "KEY_REDO"
  addKey("MIX", Unmapped_Key, 0x2E, 8);  // "KEY_MAX"
  addKey("SLEEP", Sleep_Key, 0x3E, 8);
  addKey("LIST", Unmapped_Key, 0x0F, 8);
  addKey("I-II", DoubleDigit_Key, 0x23, 8);
  addKey("ARC", AspectRatio_Key, 0x33, 8);
  addKey("EYE", Unmapped_Key, 0x12, 8);
  addKey("KEY_MEDIA", Unmapped_Key, 0x15, 8);
}


LGTV2a::LGTV2a(
  QObject *guiObject,
  unsigned int index)
  : LGTV2(guiObject, index)
{
  setKeysetName("TV Keyset 2a");

  addKey("KEY_RED", Red_Key, 0x37, 8);
  addKey("KEY_GREEN", Green_Key, 0x36, 8);
  addKey("KEY_YELLOW", Yellow_Key, 0x32, 8);
  addKey("KEY_BLUE", Blue_Key, 0x34, 8);
}


LGTV2b::LGTV2b(
  QObject *guiObject,
  unsigned int index)
  : LGTV2(guiObject, index)
{
  setKeysetName("TV Keyset 2b");

  addKey("EYE/*", Unmapped_Key, 0x37, 8);
  addKey("I/II/*", DoubleDigit_Key, 0x36, 8);
  addKey("Q.VIEW", Unmapped_Key, 0x32, 8);
  addKey("LIST", Unmapped_Key, 0x34, 8);
  addKey("sleep", Sleep_Key, 0x26, 8); // might need separate class
}


LGDisc1::LGDisc1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD/BD Keyset 1",
      LG_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    563, 559,
    563, 1681,
    108234, true);

  threadableProtocol = np;

  np->setHeaderPair(4500, 4500);
  np->setTrailerPulse(545);
  np->setRepeatPair(531, 1710);
  np->setRepeatNeedsHeader(true);

  setPreData(0x3434, 16);

//  np->setMinimumRepetitions(1);

  addKey("power", Power_Key, 0x7887, 16);
  addKey("open-close", Eject_Key, 0x59A6, 16);
  addKey("cd-dvd", Unmapped_Key, 0xC03F, 16);
  addKey("band", Unmapped_Key, 0x9A65, 16);
  addKey("aux", Unmapped_Key, 0x906F, 16);
//  addKey("aux", Unmapped_Key, 0x51AE, 16);
  addKey("1", One_Key, 0x827D, 16);
  addKey("2", Two_Key, 0x42BD, 16);
  addKey("3", Three_Key, 0xC23D, 16);
  addKey("4", Four_Key, 0x22DD, 16);
  addKey("5", Five_Key, 0xA25D, 16);
  addKey("6", Six_Key, 0x629D, 16);
  addKey("7", Seven_Key, 0xE21D, 16);
  addKey("8", Eight_Key, 0x12ED, 16);
  addKey("9", Nine_Key, 0x926D, 16);
  addKey("0", Zero_Key, 0xD22D, 16);
  addKey("sleep", Sleep_Key, 0x43BC, 16);
  addKey("audio", Language_Key, 0x05FA, 16);
  addKey("sound", Unmapped_Key, 0x857A, 16);
  addKey("s-title", Unmapped_Key, 0xD52A, 16);
  addKey("return", Exit_Key, 0x45BA, 16);
  addKey("setup", Menu_Key, 0xA55A, 16);
  addKey("display", Info_Key, 0xC53A, 16);
  addKey("menu", DiscMenu_Key, 0x25DA, 16);
  addKey("title", DiscTitle_Key, 0xF50A, 16);
  addKey("up", Up_Key, 0xE51A, 16);
  addKey("down", Down_Key, 0x659A, 16);
  addKey("left", Left_Key, 0x15EA, 16);
  addKey("right", Right_Key, 0x956A, 16);
  addKey("enter", Select_Key, 0x55AA, 16);
  addKey("plus", Unmapped_Key, 0xC837, 16); // "pr_preset_up"
  addKey("minus", Unmapped_Key, 0x48B7, 16);  // "pr_preset_down"
  addKey("<<", Rewind_Key, 0x8D72, 16);
  addKey(">>", FastForward_Key, 0x4DB2, 16);
  addKey("volume+", VolumeUp_Key, 0xE817, 16);
  addKey("volume-", VolumeDown_Key, 0x6897, 16);
  addKey("<<<", Unmapped_Key, 0x609F, 16);
  addKey(">>>", Unmapped_Key, 0xE01F, 16);
  addKey("stop", Stop_Key, 0xA05F, 16);
  addKey("pause", Pause_Key, 0xF20D, 16);
  addKey("play", Play_Key, 0x20DF, 16);
  addKey("mute", Mute_Key, 0xF807, 16);
  addKey("program", Program_Key, 0xB24D, 16);
  addKey("clear", Clear_Key, 0x0DF2, 16);
  addKey("repeat", Unmapped_Key, 0x728D, 16);
  addKey("repeata-b", Unmapped_Key, 0xB54A, 16);
  addKey("marker", Unmapped_Key, 0x2DD2, 16);
  addKey("search", Unmapped_Key, 0xCD32, 16);
  addKey("angle", Unmapped_Key, 0x35CA, 16);
  addKey("zoom", Unmapped_Key, 0x758A, 16);
  addKey("rds", Unmapped_Key, 0x06F9, 16);
  addKey("pty", Unmapped_Key, 0x8E71, 16);
  addKey("pty-search", Unmapped_Key, 0x9C63, 16);
  addKey("dimmer", Unmapped_Key, 0x7A85, 16);
  addKey("tv_radio", Unmapped_Key, 0x41BE, 16);
  addKey("text", Unmapped_Key, 0xDE21, 16);
  addKey("caption", Captions_Key, 0x56A9, 16);
  addKey("guide", Guide_Key, 0xD629, 16);
  addKey("i_ii", DoubleDigit_Key, 0x5EA1, 16);
  addKey("exit_cancel", Unmapped_Key, 0x9669, 16);
}


LGDisc2::LGDisc2(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD/BD Keyset 2",
      LG_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    600, 550,
    600, 1650,
    107000, true);

  threadableProtocol = np;

  np->setHeaderPair(4500, 4500);
  np->setTrailerPulse(600);
  np->setRepeatPair(600, 550);
  np->setRepeatNeedsHeader(true);

  setPreData(0xB4B4, 16);

//  np->setMinimumRepetitions(3);

  addKey("POWER", Power_Key, 0x0CF3, 16);
  addKey("OPEN/CLOSE", Eject_Key, 0x6C93, 16);
  addKey("1", One_Key, 0xDC23, 16);
  addKey("2", Two_Key, 0x3CC3, 16);
  addKey("3", Three_Key, 0xBC43, 16);
  addKey("4", Four_Key, 0x7C83, 16);
  addKey("5", Five_Key, 0xFC03, 16);
  addKey("6", Six_Key, 0x02FD, 16);
  addKey("7", Seven_Key, 0x827D, 16);
  addKey("8", Eight_Key, 0x42BD, 16);
  addKey("9", Nine_Key, 0xC23D, 16);
  addKey("0", Zero_Key, 0x22DD, 16);
  addKey("CLEAR", Clear_Key, 0x629D, 16);
  addKey("SCAN-BACK", Rewind_Key, 0x4CB3, 16); // <<
  addKey("SCAN-FORWARD", FastForward_Key, 0xCC33, 16); // >>
  addKey("SKIP-BACK", Previous_Key, 0xAC53, 16); // |<<
  addKey("SKIP-FORWARD", Next_Key, 0x2CD3, 16);  // >>|
  addKey("PAUSE", Pause_Key, 0x1CE3, 16);
  addKey("PLAY", Play_Key, 0x8C73, 16);
  addKey("STOP", Stop_Key, 0x9C63, 16);
  addKey("DVD-MENU", DiscMenu_Key, 0xD22D, 16);
  addKey("TITLE", DiscTitle_Key, 0x52AD, 16);
  addKey("UP", Up_Key, 0xE21D, 16);
  addKey("LEFT", Left_Key, 0x9A65, 16);
  addKey("RIGHT", Right_Key, 0x5AA5, 16);
  addKey("DOWN", Down_Key, 0x12ED, 16);
  addKey("ENTER", Select_Key, 0x1AE5, 16); // "ok"
  addKey("DISPLAY", Info_Key, 0x5CA3, 16);
  addKey("RETURN", Exit_Key, 0xA25D, 16);
  addKey("AUDIO", Unmapped_Key, 0xF20D, 16);
  addKey("SUBTITLE", Captions_Key, 0x0AF5, 16);
  addKey("ANGLE", Unmapped_Key, 0x32CD, 16);
  addKey("SETUP", Menu_Key, 0x6A95, 16);
  addKey("MARKER", Unmapped_Key, 0x8679, 16);
  addKey("SEARCH", Unmapped_Key, 0x46B9, 16); // "random"
  addKey("PROGRAM", Program_Key, 0xEA15, 16);
  addKey("ZOOM", Unmapped_Key, 0x26D9, 16);
  addKey("REPEAT", Unmapped_Key, 0xCA35, 16);
  addKey("A-B", Unmapped_Key, 0xAA55, 16); // "lp"
  addKey("RANDOM", Unmapped_Key, 0x8A75, 16); // "cm-skip"
  addKey("STAR", Unmapped_Key, 0x7A85, 16);
  addKey("DVD", Unmapped_Key, 0x8F70, 16);
  addKey("KEY_PIP", PIP_Key, 0xFA05, 16);
  addKey("KEY_RESOLUTION", AspectRatio_Key, 0xAF50, 16);
  addKey("PowerOn", Unmapped_Key, 0xAE51, 16);
  addKey("PowerOff", Unmapped_Key, 0x6E91, 16);
}


LGDisc2a::LGDisc2a(
  QObject *guiObject,
  unsigned int index)
  : LGDisc2(guiObject, index)
{
  setKeysetName("DVD/BD Keyset 2a");

  addKey("KEY_CLEAR", Clear_Key, 0x3EC1, 16);
  addKey("KEY_A", Unmapped_Key, 0x3EC1, 16);
  addKey("KEY_RED", Red_Key, 0x3EC1, 16);
  addKey("KEY_B", Unmapped_Key, 0xBE41, 16);
  addKey("KEY_GREEN", Green_Key, 0xBE41, 16);
  addKey("KEY_C", Unmapped_Key, 0x7E81, 16);
  addKey("KEY_YELLOW", Yellow_Key, 0x7E81, 16);
  addKey("KEY_D", Unmapped_Key, 0xFE01, 16);
  addKey("KEY_BLUE", Blue_Key, 0xFE01, 16);
  addKey("KEY_HOME", Menu_Key, 0xE619, 16);
}


LGVCR1::LGVCR1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      LG_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index);

  setPreData(0x7689, 16);

  addKey("power", Power_Key, 0x28D7, 16);
  addKey("rew", Rewind_Key, 0x40BF, 16);
  addKey("play", Play_Key, 0x10EF, 16);
  addKey("ff", FastForward_Key, 0xC03F, 16);
  addKey("rec", Record_Key, 0x906F, 16);
  addKey("stop", Stop_Key, 0x807F, 16);
  addKey("p/still", Pause_Key, 0xD02F, 16);
  addKey("eject", Eject_Key, 0x00FF, 16);
  addKey("1", One_Key, 0xA05F, 16);
  addKey("2", Two_Key, 0x609F, 16);
  addKey("3", Three_Key, 0xE01F, 16);
  addKey("4", Four_Key, 0x30CF, 16);
  addKey("5", Five_Key, 0xB04F, 16);
  addKey("6", Six_Key, 0x708F, 16);
  addKey("7", Seven_Key, 0xF00F, 16);
  addKey("8", Eight_Key, 0x38C7, 16);
  addKey("9", Nine_Key, 0xB847, 16);
  addKey("0", Zero_Key, 0x20DF, 16);
  addKey("mute", Mute_Key, 0xBA45, 16);
  addKey("tv/av", Unmapped_Key, 0x6A95, 16);
  addKey("menu", Menu_Key, 0x6897, 16);  // "setup", "I"
  addKey("clear/reset", Clear_Key, 0xF807, 16);  // might be wrong
  addKey("timer-prog", Program_Key, 0x5CA3, 16);
  addKey("pr+", ChannelUp_Key, 0x18E7, 16);
  addKey("pr-", ChannelDown_Key, 0x9867, 16);
  addKey("vol+", VolumeUp_Key, 0x1AE5, 16);
  addKey("vol-", VolumeDown_Key, 0x9A65, 16);
  addKey("pr+", Up_Key, 0x18E7, 16);
  addKey("vol-", Left_Key, 0x9A65, 16);
  addKey("ok", Select_Key, 0x7887, 16);
  addKey("vol+", Right_Key, 0x1AE5, 16);
  addKey("pr-", Down_Key, 0x9867, 16);
  addKey("sleep", Sleep_Key, 0x3AC5, 16);
  addKey("system", Unmapped_Key, 0x3BC4, 16);
  addKey("qview", Unmapped_Key, 0xEE11, 16);
  addKey("auto", Unmapped_Key, 0xFA05, 16); // "A.TRK"
  addKey("trk-", Unmapped_Key, 0x22DD, 16);
  addKey("trk+", Unmapped_Key, 0xA25D, 16);
  addKey("clock/count", Unmapped_Key, 0x32CD, 16);
  addKey("viss", Unmapped_Key, 0x827D, 16); // "marker-search"
  addKey("VCR", Unmapped_Key, 0x8F70, 16);
  addKey("tv/vcr", Input_Key, 0xA857, 16);
  addKey("audio", Unmapped_Key, 0x837C, 16);
  addKey("c/lock", Unmapped_Key, 0xFC03, 16);
  addKey("repeat", Unmapped_Key, 0x6D92, 16);
  addKey("lp", VHSSpeed_Key, 0x12ED, 16);
  addKey("cm-skip", Unmapped_Key, 0xBB44, 16);
  addKey("ez_POWER_OFF", Unmapped_Key, 0x1DE2, 16);
  addKey("*", Unmapped_Key, 0xE21D, 16);
}


LGVCR1a::LGVCR1a(
  QObject *guiObject,
  unsigned int index)
  : LGVCR1(guiObject, index)
{
  setKeysetName("VCR Keyset 1a");

  addKey("power", Power_Key, 0xBE41, 16);
}


LGVCR1b::LGVCR1b(
  QObject *guiObject,
  unsigned int index)
  : LGVCR1(guiObject, index)
{
  setKeysetName("VCR Keyset 1b");

  addKey("menu-left", Left_Key, 0xC13E, 16);
  addKey("menu-right", Right_Key, 0x09F6, 16);
  addKey("menu-up", Up_Key, 0x41BE, 16);
  addKey("menu-down", Down_Key, 0x916E, 16);
  addKey("ok", Select_Key, 0x718E, 16);
}

