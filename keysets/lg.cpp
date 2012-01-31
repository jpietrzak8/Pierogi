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
  threadableProtocol = new NECProtocol(guiObject, index, Standard_NEC);

//  setPreData(0x20DF, 16);
  setPreData(0x04, 8);

  addKey("p+", ChannelUp_Key, 0x00, 8);
  addKey("p-", ChannelDown_Key, 0x01, 8);
  addKey("vol+", VolumeUp_Key, 0x02, 8);
  addKey("vol-", VolumeDown_Key, 0x03, 8);
  addKey("right", Right_Key, 0x06, 8);
  addKey("left", Left_Key, 0x07, 8);
  addKey("power", Power_Key, 0x08, 8);
  addKey("mute", Mute_Key, 0x09, 8);
  addKey("sap", Audio_Key, 0x0A, 8); // I/II
  addKey("input", Input_Key, 0x0B, 8);
  addKey("picture", PictureMode_Key, 0x0C, 8);
  addKey("sound", SoundMode_Key, 0x0D, 8);
  addKey("sleep", Sleep_Key, 0x0E, 8);
  addKey("0", Zero_Key, 0x10, 8);
  addKey("1", One_Key, 0x11, 8);
  addKey("2", Two_Key, 0x12, 8);
  addKey("3", Three_Key, 0x13, 8);
  addKey("4", Four_Key, 0x14, 8);
  addKey("5", Five_Key, 0x15, 8);
  addKey("6", Six_Key, 0x16, 8);
  addKey("7", Seven_Key, 0x17, 8);
  addKey("8", Eight_Key, 0x18, 8);
  addKey("9", Nine_Key, 0x19, 8);
  addKey("qview", Unmapped_Key, 0x1A, 8); // "review"
  addKey("fav", Unmapped_Key, 0x1E, 8);
  addKey("text", Teletext_Key, 0x20, 8);
  addKey("topt", Unmapped_Key, 0x21, 8);
  addKey("topt/rev", Rewind_Key, 0x21, 8);
  addKey("MIX", TeletextAndTV_Key, 0x24, 8);
  addKey("TIME", TeletextTime_Key, 0x26, 8);
  addKey("INDEX", Unmapped_Key, 0x27, 8);
  addKey("return/exit", Exit_Key, 0x28, 8);
  addKey("avmode", Unmapped_Key, 0x30, 8); // "UPDATE"
  addKey("subtitle", Captions_Key, 0x39, 8); // "cc"
  addKey("subtitle/ffw", FastForward_Key, 0x39, 8);
  addKey("up", Up_Key, 0x40, 8);
  addKey("down", Down_Key, 0x41, 8);
  addKey("menu", Menu_Key, 0x43, 8);
  addKey("ok", Select_Key, 0x44, 8);
  addKey("qmenu", Unmapped_Key, 0x45, 8);
  addKey("video", Unmapped_Key, 0x4D, 8); // "apc", "PSM"
  addKey("TV/PC", Unmapped_Key, 0x50, 8);
  addKey("sound", Unmapped_Key, 0x52, 8); // "SSM"
  addKey("list", Unmapped_Key, 0x53, 8);
  addKey("auto", Unmapped_Key, 0x54, 8);
  addKey("memory/erase", Unmapped_Key, 0x55, 8);
  addKey("pip", PIP_Key, 0x60, 8);
  addKey("blue", Blue_Key, 0x61, 8);
  addKey("blue/pause", Pause_Key, 0x61, 8);
  addKey("yellow", Yellow_Key, 0x63, 8);
  addKey("yellow/play", Play_Key, 0x63, 8);
  addKey("brt.w", Unmapped_Key, 0x6E, 8);
  addKey("red", Red_Key, 0x72, 8);
  addKey("green", Green_Key, 0x71, 8);
  addKey("green/stop", Stop_Key, 0x71, 8);
  addKey("ratio", AspectRatio_Key, 0x79, 8);
  addKey("xstudio", Unmapped_Key, 0x7C, 8);
  addKey("simplink", Unmapped_Key, 0x7E, 8);
  addKey("energy", Unmapped_Key, 0x95, 8); // "EYEASTERISK"
  addKey("comp-rgb-dvi", Unmapped_Key, 0x98, 8);
  addKey("info", Info_Key, 0xAA, 8);
  addKey("guide", Guide_Key, 0xAB, 8);
  addKey("rec", Record_Key, 0xBD, 8);
  addKey("tv/radio", Unmapped_Key, 0xF0, 8);
}


LGTV1a::LGTV1a(
  QObject *guiObject,
  unsigned int index)
  : LGTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1a");

  addKey("*", Unmapped_Key, 0x39, 8);
  addKey("exit", Exit_Key, 0x5B, 8);
//  addKey("pop", Unmapped_Key, 0x61, 8);
  addKey("pipinput", PIPSource_Key, 0x61, 8);
  addKey("swap", PIPSwap_Key, 0x63, 8);
  addKey("freeze", PIPPause_Key, 0x65, 8);
  addKey("pipch+", PIPChannelUp_Key, 0x71, 8);
  addKey("pipch-", PIPChannelDown_Key, 0x72, 8);
  addKey("zoom", Zoom_Key, 0x7B, 8);
  addKey("signal", Unmapped_Key, 0x96, 8);
  addKey("adjust", Unmapped_Key, 0xCB, 8);
}


LGTV1b::LGTV1b(
  QObject *guiObject,
  unsigned int index)
  : LGTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1b");

  addKey("PR+/Up_Arrow", Up_Key, 0x00, 8);
  addKey("PR-/Down_Arrow", Down_Key, 0x01, 8);
  addKey("Vol+/Right_Arrow", Right_Key, 0x02, 8);
  addKey("Vol-/Left_Arrow", Left_Key, 0x03, 8);
  addKey("orange", Red_Key, 0xC0, 8);
  addKey("yellow", Yellow_Key, 0xC1, 8);
  addKey("blue", Blue_Key, 0xC2, 8);
  addKey("green", Green_Key, 0xC3, 8);
}


LGTV1c::LGTV1c(
  QObject *guiObject,
  unsigned int index)
  : LGTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1c");

  addKey("backward", Rewind_Key, 0x80, 8);
  addKey("forward", FastForward_Key, 0x8E, 8);
  addKey("stop", Stop_Key, 0xB1, 8);
  addKey("play", Play_Key, 0xB0, 8);
  addKey("pause", Pause_Key, 0xBA, 8);
  addKey("rec", Record_Key, 0xBD, 8);
}


LGTV2::LGTV2(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 2",
      LG_Make,
      index)
{
  threadableProtocol = new RC5Protocol(guiObject, index, 0x40);

  addKey("0", Zero_Key, 0x00, 6);
  addKey("1", One_Key, 0x01, 6);
  addKey("2", Two_Key, 0x02, 6);
  addKey("3", Three_Key, 0x03, 6);
  addKey("4", Four_Key, 0x04, 6);
  addKey("5", Five_Key, 0x05, 6);
  addKey("6", Six_Key, 0x06, 6);
  addKey("7", Seven_Key, 0x07, 6);
  addKey("8", Eight_Key, 0x08, 6);
  addKey("9", Nine_Key, 0x09, 6);
  addKey("POWER", Power_Key, 0x0C, 6);
  addKey("MUTE", Mute_Key, 0x0D, 6);
  addKey("PSM", PictureMode_Key, 0x0E, 6); // preset picture
  addKey("LIST", Unmapped_Key, 0x0F, 6);
  addKey("VOLUP", VolumeUp_Key, 0x10, 6);
  addKey("VOLDOWN", VolumeDown_Key, 0x11, 6);
  addKey("EYE", Unmapped_Key, 0x12, 6);
  addKey("TURBOPICTURE", Unmapped_Key, 0x13, 6);
  addKey("DRP", Unmapped_Key, 0x14, 6);
  addKey("KEY_MEDIA", Unmapped_Key, 0x15, 6);
  addKey("SSM", SoundMode_Key, 0x16, 6); // preset sound
  addKey("PROGUP", ChannelUp_Key, 0x20, 6);
  addKey("PROGDOWN", ChannelDown_Key, 0x21, 6);
  addKey("I-II", Audio_Key, 0x23, 6);
  addKey("TURBOSOUND", Unmapped_Key, 0x24, 6);
  addKey("OK", Select_Key, 0x25, 6);
  addKey("STILL", TeletextHold_Key, 0x29, 6); // "KEY_PAUSE", "HOLD"
  addKey("TIME", TeletextTime_Key, 0x2A, 6);
  addKey("SIZE", TeletextSize_Key, 0x2B, 6);  // "KEY_SAVE"
  addKey("REVEAL", TeletextReveal_Key, 0x2C, 6); // "KEY_REDO"
  addKey("POS", PIPMove_Key, 0x2D, 6); // position, "UPDATE"
  addKey("MIX", TeletextAndTV_Key, 0x2E, 6);  // "KEY_MAX"
  addKey("SWAP", PIPSwap_Key, 0x32, 6);
  addKey("ARC", AspectRatio_Key, 0x33, 6);
  addKey("INPUT", Input_Key, 0x34, 6);
  addKey("2-12PIP", Unmapped_Key, 0x35, 6); // strobe, "KEY_SHOP"
  addKey("PR-PLUS", Unmapped_Key, 0x36, 6);
  addKey("PR-MINUS", Unmapped_Key, 0x37, 6);
  addKey("TVAV", Unmapped_Key, 0x38, 6);
  addKey("PIP", PIP_Key, 0x3A, 6);
  addKey("MENU", Menu_Key, 0x3B, 6);
  addKey("TEXT", Teletext_Key, 0x3C, 6);
  addKey("SLEEP", Sleep_Key, 0x3E, 6);
}


LGTV2a::LGTV2a(
  QObject *guiObject,
  unsigned int index)
  : LGTV2(guiObject, index)
{
  setKeysetName("TV Keyset 2a");

  addKey("KEY_YELLOW", Yellow_Key, 0x32, 6);
  addKey("KEY_BLUE", Blue_Key, 0x34, 6);
  addKey("KEY_GREEN", Green_Key, 0x36, 6);
  addKey("KEY_RED", Red_Key, 0x37, 6);
}


LGTV2b::LGTV2b(
  QObject *guiObject,
  unsigned int index)
  : LGTV2(guiObject, index)
{
  setKeysetName("TV Keyset 2b");

  addKey("sleep", Sleep_Key, 0x26, 6); // might need separate class
  addKey("Q.VIEW", Unmapped_Key, 0x32, 6);
  addKey("LIST", Unmapped_Key, 0x34, 6);
  addKey("I/II/*", Audio_Key, 0x36, 6);
  addKey("EYE/*", Unmapped_Key, 0x37, 6);
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
    108234, true,
    Extended_NEC);

  threadableProtocol = np;

  np->setHeaderPair(4500, 4500);
  np->setTrailerPulse(545);
  np->setRepeatPair(531, 1710);
  np->setRepeatNeedsHeader(true);

//  setPreData(0x3434, 16);
  setPreData(0x2C2C, 16);

  addKey("cd-dvd", Unmapped_Key, 0x03, 8);
  addKey("play", Play_Key, 0x04, 8);
  addKey("stop", Stop_Key, 0x05, 8);
  addKey("<<<", Unmapped_Key, 0x06, 8);
  addKey(">>>", Unmapped_Key, 0x07, 8);
  addKey("aux", Unmapped_Key, 0x09, 8);
  addKey("minus", Unmapped_Key, 0x12, 8);  // "pr_preset_down"
  addKey("plus", Unmapped_Key, 0x13, 8); // "pr_preset_up"
  addKey("volume-", VolumeDown_Key, 0x16, 8);
  addKey("volume+", VolumeUp_Key, 0x17, 8);
  addKey("power", Power_Key, 0x1E, 8);
  addKey("mute", Mute_Key, 0x1F, 16);
  addKey("pty-search", Unmapped_Key, 0x39, 8);
  addKey("1", One_Key, 0x41, 8);
  addKey("2", Two_Key, 0x42, 8);
  addKey("3", Three_Key, 0x43, 8);
  addKey("4", Four_Key, 0x44, 8);
  addKey("5", Five_Key, 0x45, 8);
  addKey("6", Six_Key, 0x46, 8);
  addKey("7", Seven_Key, 0x47, 8);
  addKey("8", Eight_Key, 0x48, 8);
  addKey("9", Nine_Key, 0x49, 8);
  addKey("0", Zero_Key, 0x4B, 8);
  addKey("program", Program_Key, 0x4D, 8);
  addKey("repeat", Repeat_Key, 0x4E, 8);
  addKey("pause", Pause_Key, 0x4F, 8);
  addKey("band", Unmapped_Key, 0x59, 8);
  addKey("dimmer", Unmapped_Key, 0x5E, 8);
  addKey("rds", Unmapped_Key, 0x60, 8);
  addKey("exit_cancel", Unmapped_Key, 0x69, 8);
  addKey("caption", Captions_Key, 0x6A, 8);
  addKey("guide", Guide_Key, 0x6B, 8);
  addKey("pty", Unmapped_Key, 0x71, 8);
  addKey("i_ii", Unmapped_Key, 0x7A, 8);
  addKey("text", Unmapped_Key, 0x7B, 8);
  addKey("tv_radio", Unmapped_Key, 0x82, 8);
//  addKey("aux", Unmapped_Key, 0x8A, 8);
  addKey("open-close", Eject_Key, 0x9A, 8);
  addKey("audio", Audio_Key, 0xA0, 8);
  addKey("sound", SoundMode_Key, 0xA1, 8);
  addKey("return", Exit_Key, 0xA2, 8);
  addKey("display", Info_Key, 0xA3, 8);
  addKey("menu", DiscMenu_Key, 0xA4, 8);
  addKey("setup", Menu_Key, 0xA5, 8);
  addKey("down", Down_Key, 0xA6, 8);
  addKey("up", Up_Key, 0xA7, 8);
  addKey("left", Left_Key, 0xA8, 8);
  addKey("right", Right_Key, 0xA9, 8);
  addKey("enter", Select_Key, 0xAA, 8);
  addKey("s-title", Unmapped_Key, 0xAB, 8);
  addKey("angle", Angle_Key, 0xAC, 8);
  addKey("repeata-b", RepeatAB_Key, 0xAD, 8);
  addKey("zoom", Zoom_Key, 0xAE, 8);
  addKey("title", DiscTitle_Key, 0xAF, 8);
  addKey("clear", Clear_Key, 0xB0, 8);
  addKey("<<", Rewind_Key, 0xB1, 8);
  addKey(">>", FastForward_Key, 0xB2, 8);
  addKey("search", Unmapped_Key, 0xB3, 8);
  addKey("marker", Unmapped_Key, 0xB4, 8);
  addKey("sleep", Sleep_Key, 0xC2, 8);
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
    107000, true,
    Extended_NEC);

  threadableProtocol = np;

  np->setHeaderPair(4500, 4500);
  np->setTrailerPulse(600);
  np->setRepeatPair(600, 550);
  np->setRepeatNeedsHeader(true);

//  setPreData(0xB4B4, 16);
  setPreData(0x2D2D, 16);

  addKey("POWER", Power_Key, 0x30, 8);
  addKey("PLAY", Play_Key, 0x31, 8);
  addKey("SCAN-BACK", Rewind_Key, 0x32, 8); // <<
  addKey("SCAN-FORWARD", FastForward_Key, 0x33, 8); // >>
  addKey("SKIP-FORWARD", Next_Key, 0x34, 16);  // >>|
  addKey("SKIP-BACK", Previous_Key, 0x35, 16); // |<<
  addKey("OPEN/CLOSE", Eject_Key, 0x36, 8);
  addKey("PAUSE", Pause_Key, 0x38, 8);
  addKey("STOP", Stop_Key, 0x39, 8);
  addKey("DISPLAY", Info_Key, 0x3A, 8);
  addKey("1", One_Key, 0x3B, 8);
  addKey("2", Two_Key, 0x3C, 8);
  addKey("3", Three_Key, 0x3D, 8);
  addKey("4", Four_Key, 0x3E, 8);
  addKey("5", Five_Key, 0x3F, 8);
  addKey("6", Six_Key, 0x40, 8);
  addKey("7", Seven_Key, 0x41, 8);
  addKey("8", Eight_Key, 0x42, 8);
  addKey("9", Nine_Key, 0x43, 8);
  addKey("0", Zero_Key, 0x44, 8);
  addKey("RETURN", Exit_Key, 0x45, 8);
  addKey("CLEAR", Clear_Key, 0x46, 8);
  addKey("UP", Up_Key, 0x47, 8);
  addKey("DOWN", Down_Key, 0x48, 8);
  addKey("TITLE", DiscTitle_Key, 0x4A, 8);
  addKey("DVD-MENU", DiscMenu_Key, 0x4B, 8);
  addKey("ANGLE", Angle_Key, 0x4C, 8);
  addKey("AUDIO", Audio_Key, 0x4F, 8);
  addKey("SUBTITLE", Captions_Key, 0x50, 8);
  addKey("RANDOM", Random_Key, 0x51, 8); // "cm-skip"
  addKey("REPEAT", Repeat_Key, 0x53, 8);
  addKey("A-B", RepeatAB_Key, 0x55, 8); // "lp"
  addKey("SETUP", Menu_Key, 0x56, 8);
  addKey("PROGRAM", Program_Key, 0x57, 8);
  addKey("ENTER", Select_Key, 0x58, 8); // "ok"
  addKey("LEFT", Left_Key, 0x59, 8);
  addKey("RIGHT", Right_Key, 0x5A, 8);
  addKey("STAR", Unmapped_Key, 0x5E, 8);
  addKey("KEY_PIP", PIP_Key, 0x5F, 8);
  addKey("MARKER", Unmapped_Key, 0x61, 8);
  addKey("SEARCH", Unmapped_Key, 0x62, 8); // "random"
  addKey("ZOOM", Zoom_Key, 0x64, 8);
  addKey("PowerOn", PowerOn_Key, 0x75, 8);
  addKey("PowerOff", PowerOff_Key, 0x76, 8);
  addKey("DVD", Unmapped_Key, 0xF1, 8);
  addKey("KEY_RESOLUTION", AspectRatio_Key, 0xF5, 8);
}


LGDisc2a::LGDisc2a(
  QObject *guiObject,
  unsigned int index)
  : LGDisc2(guiObject, index)
{
  setKeysetName("DVD/BD Keyset 2a");

  addKey("KEY_HOME", Menu_Key, 0x67, 8);
  addKey("KEY_CLEAR", Clear_Key, 0x7C, 8);
  addKey("KEY_RED", Red_Key, 0x7C, 8);
  addKey("KEY_GREEN", Green_Key, 0x7D, 8);
  addKey("KEY_YELLOW", Yellow_Key, 0x7E, 8);
  addKey("KEY_BLUE", Blue_Key, 0x7F, 8);
}


LGVCR1::LGVCR1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      LG_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index, Standard_NEC);

//  setPreData(0x7689, 16);
  setPreData(0x6E, 8);

  addKey("eject", Eject_Key, 0x00, 8);
  addKey("stop", Stop_Key, 0x01, 8);
  addKey("rew", Rewind_Key, 0x02, 8);
  addKey("ff", FastForward_Key, 0x03, 8);
  addKey("0", Zero_Key, 0x04, 8);
  addKey("1", One_Key, 0x05, 8);
  addKey("2", Two_Key, 0x06, 8);
  addKey("3", Three_Key, 0x07, 8);
  addKey("play", Play_Key, 0x08, 8);
  addKey("rec", Record_Key, 0x09, 8);
  addKey("p/still", Pause_Key, 0x0B, 8);
  addKey("4", Four_Key, 0x0C, 8);
  addKey("5", Five_Key, 0x0D, 8);
  addKey("6", Six_Key, 0x0E, 8);
  addKey("7", Seven_Key, 0x0F, 8);
  addKey("power", Power_Key, 0x14, 8);
  addKey("tv/vcr", Input_Key, 0x15, 8);
  addKey("menu", Menu_Key, 0x16, 8);  // "setup", "I"
  addKey("pr+", ChannelUp_Key, 0x18, 8);
  addKey("pr+", Up_Key, 0x18, 8);
  addKey("pr-", ChannelDown_Key, 0x19, 8);
  addKey("pr-", Down_Key, 0x19, 8);
  addKey("8", Eight_Key, 0x1C, 8);
  addKey("9", Nine_Key, 0x1D, 8);
  addKey("ok", Select_Key, 0x1E, 8);
  addKey("clear/reset", Clear_Key, 0x1F, 8);  // might be wrong
  addKey("timer-prog", Program_Key, 0x3A, 8);
  addKey("viss", Unmapped_Key, 0x41, 8); // "marker-search"
  addKey("trk-", TrackingMinus_Key, 0x44, 8);
  addKey("trk+", TrackingPlus_Key, 0x45, 8);
  addKey("*", Unmapped_Key, 0x47, 8);
  addKey("lp", VHSSpeed_Key, 0x48, 8);
  addKey("clock/count", Clock_Key, 0x4C, 8);
  addKey("tv/av", Unmapped_Key, 0x56, 8);
  addKey("vol+", VolumeUp_Key, 0x58, 8);
  addKey("vol+", Right_Key, 0x58, 8);
  addKey("vol-", VolumeDown_Key, 0x59, 8);
  addKey("vol-", Left_Key, 0x59, 8);
  addKey("sleep", Sleep_Key, 0x5C, 8);
  addKey("mute", Mute_Key, 0x5D, 8);
  addKey("auto", AutoTracking_Key, 0x5F, 8); // "A.TRK"
  addKey("qview", Unmapped_Key, 0x77, 8);
  addKey("repeat", Repeat_Key, 0xB6, 8);
  addKey("ez_POWER_OFF", PowerOff_Key, 0xB8, 8);
  addKey("audio", Audio_Key, 0xC1, 8);
  addKey("c/lock", Unmapped_Key, 0xCF, 8);
  addKey("system", Unmapped_Key, 0xDC, 8);
  addKey("VCR", Unmapped_Key, 0xF1, 8);
  addKey("cm-skip", Unmapped_Key, 0xDD, 8);
}


LGVCR1a::LGVCR1a(
  QObject *guiObject,
  unsigned int index)
  : LGVCR1(guiObject, index)
{
  setKeysetName("VCR Keyset 1a");

  addKey("power", Power_Key, 0x7D, 8);
}


LGVCR1b::LGVCR1b(
  QObject *guiObject,
  unsigned int index)
  : LGVCR1(guiObject, index)
{
  setKeysetName("VCR Keyset 1b");

  addKey("menu-up", Up_Key, 0x82, 8);
  addKey("menu-left", Left_Key, 0x83, 8);
  addKey("menu-down", Down_Key, 0x89, 8);
  addKey("ok", Select_Key, 0x8E, 8);
  addKey("menu-right", Right_Key, 0x90, 8);
}

