#include "jvc.h"
#include "necprotocol.h"

JVCSat1::JVCSat1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Sat (Dish) Keyset 1",
      JVC_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
   guiObject,
   index,
   624, 1500,
   624, 2600,
   6000, false);

  threadableProtocol = np;

  np->setHeaderPair(750, 6000);
  np->setTrailerPulse(624);

  np->setFullHeadlessRepeat(true);

//  np->setCarrierFrequency(56000);
//  np->setDutyCycle(32);

  addKey("power", Power_Key, 0x1EFC, 13);
  addKey("recent", Unmapped_Key, 0x16FC, 13);
  addKey("tvWeb", Unmapped_Key, 0x1A7C, 13);
  addKey("scrollUp", Unmapped_Key, 0x137C, 13);
  addKey("scrollDown", Unmapped_Key, 0x117C, 13);
  addKey("home", Unmapped_Key, 0x15FC, 13);
  addKey("back", Exit_Key, 0x1FFC, 13);
  addKey("up", Up_Key, 0x12FC, 13);
  addKey("left", Left_Key, 0x11FC, 13);
  addKey("go", Enter_Key, 0x17FC, 13);
  addKey("right", Right_Key, 0x13FC, 13);
  addKey("down", Down_Key, 0x10FC, 13);
  addKey("options", Unmapped_Key, 0x14FC, 13);
  addKey("chDown", ChannelDown_Key, 0x187C, 13);
  addKey("record", Record_Key, 0x107C, 13);
  addKey("rewind", Rewind_Key, 0x1C7C, 13);
  addKey("play", Play_Key, 0x1E7C, 13);
  addKey("1", One_Key, 0x1DFC, 13);
  addKey("2", Two_Key, 0x1D7C, 13);
  addKey("3", Three_Key, 0x1CFC, 13);
  addKey("4", Four_Key, 0x1BFC, 13);
  addKey("5", Five_Key, 0x1B7C, 13);
  addKey("6", Six_Key, 0x1AFC, 13);
  addKey("7", Seven_Key, 0x19FC, 13);
  addKey("8", Eight_Key, 0x197C, 13);
  addKey("9", Nine_Key, 0x18FC, 13);
  addKey("0", Zero_Key, 0x177C, 13);
  addKey("enter", Enter_Key, 0x127C, 13);
  addKey("pip", PIP_Key, 0x077C, 13);
  addKey("info", Info_Key, 0x06FC, 13);
  addKey("listings", Guide_Key, 0x07FC, 13);
  addKey("personalTv", Unmapped_Key, 0x0CFC, 13);
  addKey("replay", Replay_Key, 0x0EFC, 13);
  addKey("skip", Advance_Key, 0x0E7C, 13);
  addKey("pause", Pause_Key, 0x0DFC, 13);
  addKey("fastForward", FastForward_Key, 0x0D7C, 13);
  addKey("stop", Stop_Key, 0x0F7C, 13);
  addKey("chUp", ChannelUp_Key, 0x0FFC, 13);
  addKey("recall", PrevChannel_Key, 0x057C, 13);
}


JVCSat2::JVCSat2(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Sat (Dish) Keyset 2",
      JVC_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    440, 2780,
    440, 1645,
    6115, false);

  threadableProtocol = np;

  np->setHeaderPair(525, 6045);
  np->setTrailerPulse(450);

//  np->setMinimumRepetitions(6);
  np->setFullHeadlessRepeat(true);

  np->setCarrierFrequency(56000);
  np->setDutyCycle(32);

  setPostData(0x000, 10);

  addKey("info", Info_Key, 0x0, 6);
  addKey("power_on", Unmapped_Key, 0x1, 6);
  addKey("power", Power_Key, 0x2, 6);
  addKey("1", One_Key, 0x4, 6);
  addKey("2", Two_Key, 0x5, 6);
  addKey("3", Three_Key, 0x6, 6);
  addKey("4", Four_Key, 0x8, 6);
  addKey("5", Five_Key, 0x9, 6);
  addKey("6", Six_Key, 0x10, 6);
  addKey("7", Seven_Key, 0x12, 6);
  addKey("8", Eight_Key, 0x13, 6);
  addKey("9", Nine_Key, 0x14, 6);
  addKey("0", Zero_Key, 0x17, 6);
  addKey("menu", Menu_Key, 0x11, 6);
  addKey("select", Select_Key, 0x16, 6);
  addKey("cancel", Exit_Key, 0x18, 6);
  addKey("guide", Guide_Key, 0x20, 6);
  addKey("view", Unmapped_Key, 0x22, 6);
  addKey("tv_vcr", Input_Key, 0x23, 6);
  addKey("right", Right_Key, 0x24, 6);
  addKey("up", Up_Key, 0x26, 6);
  addKey("recall", PrevChannel_Key, 0x27, 6);
  addKey("left", Left_Key, 0x28, 6);
  addKey("down", Down_Key, 0x30, 6);
  addKey("record", Record_Key, 0x31, 6);
  addKey("pause", Pause_Key, 0x32, 6);
  addKey("stop", Stop_Key, 0x33, 6);
  addKey("sys_info", Info_Key, 0x36, 6);
  addKey("asterisk", Unmapped_Key, 0x37, 6);
  addKey("pound", Unmapped_Key, 0x38, 6);
  addKey("power_off", Unmapped_Key, 0x39, 6);
  addKey("sat", Unmapped_Key, 0x41, 6);
  addKey("dish_home", Unmapped_Key, 0x52, 6);
  addKey("sys_info2", Unmapped_Key, 0x54, 6);
  addKey("dish_home2", Unmapped_Key, 0x56, 6);
}


JVCVCR1::JVCVCR1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      JVC_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    600, 500,
    600, 1600,
    45000, true);

  threadableProtocol = np;

  np->setTrailerPulse(600);

  setPreData(0xC2, 8);

  addKey("power", Power_Key, 0xD0, 8);
  addKey("play", Play_Key, 0x30, 8);
  addKey("forward", FastForward_Key, 0x60, 8);
  addKey("backward", Rewind_Key, 0xE0, 8);
  addKey("stop", Stop_Key, 0xC0, 8);
  addKey("pause", Pause_Key, 0xB0, 8);
  addKey("menu", Menu_Key, 0xEC, 8); // "PROG"
  addKey("ok", Select_Key, 0x3C, 8);
  addKey("CANCEL", Exit_Key, 0x6C, 8); // "zero4x", "reset"
  addKey("CANCEL", Clear_Key, 0x6C, 8); // "zero4x", "reset"
  addKey("RECORD", Record_Key, 0x33, 8); // "itr"
  addKey("pr_up", ChannelUp_Key, 0x98, 8);
  addKey("pr_dn", ChannelDown_Key, 0x18, 8);
  addKey("right", Next_Key, 0x28, 8); // "JOG+"
  addKey("left", Previous_Key, 0xA8, 8); // "JOG-"
  addKey("pr_up", Up_Key, 0x98, 8);
  addKey("pr_dn", Down_Key, 0x18, 8);
  addKey("right", Right_Key, 0x28, 8); // "JOG+"
  addKey("left", Left_Key, 0xA8, 8); // "JOG-"
  addKey("eject", Eject_Key, 0x20, 8);
  addKey("no_1", One_Key, 0x84, 8);
  addKey("no_2", Two_Key, 0x44, 8);
  addKey("no_3", Three_Key, 0xC4, 8);
  addKey("no_4", Four_Key, 0x24, 8);
  addKey("no_5", Five_Key, 0xA4, 8);
  addKey("no_6", Six_Key, 0x64, 8);
  addKey("no_7", Seven_Key, 0xE4, 8);
  addKey("no_8", Eight_Key, 0x14, 8);
  addKey("no_9", Nine_Key, 0x94, 8);
  addKey("no_0", Zero_Key, 0xCC, 8);
  addKey("tv_vcr", Input_Key, 0xC8, 8); // "monitor"
  addKey("av", Unmapped_Key, 0x80, 8);
  addKey("ff_30sec", Advance_Key, 0x69, 8); // "skip"
  addKey("die", Unmapped_Key, 0x5F, 8);
  addKey("start", Unmapped_Key, 0x19, 8);
  addKey("lock", Unmapped_Key, 0x0F, 8);
  addKey("showview", Program_Key, 0x83, 8); // program
  addKey("SOUND1", Unmapped_Key, 0xEB, 8);
  addKey("SOUND2", Unmapped_Key, 0x27, 8);
  addKey("SOUND3", Unmapped_Key, 0x3B, 8);
  addKey("INDEX1", Unmapped_Key, 0xC9, 8);
  addKey("INDEX2", Unmapped_Key, 0x29, 8);
  addKey("DISPLAY", Info_Key, 0x1C, 8);
  addKey("MUTE", Mute_Key, 0xE8, 8);
  addKey("SPEED", VHSSpeed_Key, 0x8C, 8); // "I/II"
  addKey("TIMER", Unmapped_Key, 0xAC, 8);
  addKey("MIC+", Unmapped_Key, 0x8B, 8);
  addKey("MIC-", Unmapped_Key, 0x4B, 8);
  addKey("enter", Enter_Key, 0x7C, 8); // "store"
  addKey("line", Unmapped_Key, 0x76, 8);
  addKey("check", Unmapped_Key, 0xBC, 8); // "prog_check"
  addKey("start+", Unmapped_Key, 0x13, 8);
  addKey("start-", Unmapped_Key, 0x93, 8);
  addKey("stop+", Unmapped_Key, 0x53, 8);
  addKey("stop-", Unmapped_Key, 0xD3, 8);
  addKey("date+", Unmapped_Key, 0x63, 8);
  addKey("date-", Unmapped_Key, 0xE3, 8);
  addKey("review", Replay_Key, 0xC3, 8);
  addKey("IN/OUT", Unmapped_Key, 0x7B, 8);
  addKey("3dphonic", Unmapped_Key, 0xA9, 8);
  addKey("Red", Red_Key, 0x89, 8);
  addKey("Green", Green_Key, 0xDC, 8);
  addKey("Yellow", Yellow_Key, 0xE9, 8);
  addKey("Blue", Blue_Key, 0x8C, 8);
  addKey("ch_set", Unmapped_Key, 0x66, 8);
  addKey("clock", Unmapped_Key, 0x5C, 8);
  addKey("mode", Unmapped_Key, 0x61, 8);
  addKey("scene-finder", Unmapped_Key, 0xE9, 8);
  addKey("input_1", Unmapped_Key, 0x88, 8);
}


JVCVCR1a::JVCVCR1a(
  QObject *guiObject,
  unsigned int index)
  : JVCVCR1(guiObject, index)
{
  setKeysetName("VCR Keyset 1a");

  addKey("red", Red_Key, 0xE0, 8);
  addKey("green", Green_Key, 0xA8, 8);
  addKey("yellow", Yellow_Key, 0x28, 8);
  addKey("blue", Blue_Key, 0x60, 8);
  addKey("menu", Menu_Key, 0xC8, 8);
  addKey("last", Unmapped_Key, 0xA8, 8); // what is this?
  addKey("suchl", Unmapped_Key, 0x69, 8); // ditto
}


// The 0xCA keyset appears to just be the 0xC2 keyset with a different preface,
// to allow two VCRs in the same room to be controlled independently.
// Note the hack below won't work with the other VCR keysets!!!
JVCVCR1b::JVCVCR1b(
  QObject *guiObject,
  unsigned int index)
  : JVCVCR1(guiObject, index)
{
  setKeysetName("VCR (alt) keyset 1b");

  setPreData(0xCA, 8);
}


JVCVCR1c::JVCVCR1c(
  QObject *guiObject,
  unsigned int index)
  : JVCVCR1(guiObject, index)
{
  setKeysetName("VCR keyset 1c");

  addKey("tv", Input_Key, 0x08, 8);
}


// VCR keyset #2 is apparently identical to #1, but this one uses a header
// pulse.  Dunno if this is a mistake, or if JVC messes with the fundamental
// elements of their protocols this much...
JVCVCR2::JVCVCR2(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 2",
      JVC_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    600, 500,
    600, 1600,
    46000, true);

  threadableProtocol = np;

  np->setHeaderPair(9000, 4500);
  np->setTrailerPulse(600);
  np->setFullHeadlessRepeat(true);

  setPreData(0xC2, 8);

  addKey("power", Power_Key, 0xD0, 8);
  addKey("play", Play_Key, 0x30, 8);
  addKey("forward", FastForward_Key, 0x60, 8);
  addKey("backward", Rewind_Key, 0xE0, 8);
  addKey("stop", Stop_Key, 0xC0, 8);
  addKey("pause", Pause_Key, 0xB0, 8);
  addKey("menu", Menu_Key, 0xEC, 8); // "PROG"
  addKey("ok", Select_Key, 0x3C, 8);
  addKey("CANCEL", Exit_Key, 0x6C, 8); // "zero4x", "reset"
  addKey("CANCEL", Clear_Key, 0x6C, 8); // "zero4x", "reset"
  addKey("RECORD", Record_Key, 0x33, 8); // "itr"
  addKey("recpause", Unmapped_Key, 0xB3, 8);
  addKey("pr_up", ChannelUp_Key, 0x98, 8);
  addKey("pr_dn", ChannelDown_Key, 0x18, 8);
  addKey("pr_up", Up_Key, 0x98, 8);
  addKey("pr_dn", Down_Key, 0x18, 8);
  addKey("right", Right_Key, 0x28, 8); // "JOG+"
  addKey("left", Left_Key, 0xA8, 8); // "JOG-"
  addKey("eject", Eject_Key, 0x20, 8);
  addKey("no_1", One_Key, 0x84, 8);
  addKey("no_2", Two_Key, 0x44, 8);
  addKey("no_3", Three_Key, 0xC4, 8);
  addKey("no_4", Four_Key, 0x24, 8);
  addKey("no_5", Five_Key, 0xA4, 8);
  addKey("no_6", Six_Key, 0x64, 8);
  addKey("no_7", Seven_Key, 0xE4, 8);
  addKey("no_8", Eight_Key, 0x14, 8);
  addKey("no_9", Nine_Key, 0x94, 8);
  addKey("no_0", Zero_Key, 0xCC, 8);
  addKey("tv_vcr", Input_Key, 0xC8, 8); // "monitor"
  addKey("av", Unmapped_Key, 0x80, 8);
  addKey("ff_30sec", Advance_Key, 0x69, 8); // "skip"
  addKey("die", Unmapped_Key, 0x5F, 8);
  addKey("start", Unmapped_Key, 0x19, 8);
  addKey("lock", Unmapped_Key, 0x0F, 8);
  addKey("showview", Program_Key, 0x83, 8); // program
  addKey("SOUND1", Unmapped_Key, 0xEB, 8);
  addKey("SOUND2", Unmapped_Key, 0x27, 8);
  addKey("SOUND3", Unmapped_Key, 0x3B, 8);
  addKey("INDEX1", Unmapped_Key, 0xC9, 8);
  addKey("INDEX2", Unmapped_Key, 0x29, 8);
  addKey("DISPLAY", Info_Key, 0x1C, 8);
  addKey("MUTE", Mute_Key, 0xE8, 8);
  addKey("SPEED", VHSSpeed_Key, 0x8C, 8); // "I/II"
  addKey("TIMER", Unmapped_Key, 0xAC, 8);
  addKey("MIC+", Unmapped_Key, 0x8B, 8);
  addKey("MIC-", Unmapped_Key, 0x4B, 8);
  addKey("enter", Enter_Key, 0x7C, 8);
  addKey("line", Unmapped_Key, 0x76, 8);
  addKey("check", Unmapped_Key, 0xBC, 8); // "prog_check"
  addKey("start+", Unmapped_Key, 0x13, 8);
  addKey("start-", Unmapped_Key, 0x93, 8);
  addKey("stop+", Unmapped_Key, 0x53, 8);
  addKey("stop-", Unmapped_Key, 0xD3, 8);
  addKey("date+", Unmapped_Key, 0x63, 8);
  addKey("date-", Unmapped_Key, 0xE3, 8);
  addKey("review", Replay_Key, 0xC3, 8);
  addKey("IN/OUT", Unmapped_Key, 0x7B, 8);
  addKey("3dphonic", Unmapped_Key, 0xA9, 8);
  addKey("Red", Red_Key, 0x89, 8);
  addKey("Green", Green_Key, 0xDC, 8);
  addKey("Yellow", Yellow_Key, 0xE9, 8);
  addKey("Blue", Blue_Key, 0x8C, 8);
  addKey("ch_set", Unmapped_Key, 0x66, 8);
  addKey("clock", Unmapped_Key, 0x5C, 8);
  addKey("mode", Unmapped_Key, 0x61, 8);
  addKey("scene-finder", Unmapped_Key, 0xE9, 8);
  addKey("input_1", Unmapped_Key, 0x88, 8);
}


JVCVCR2a::JVCVCR2a(
  QObject *guiObject,
  unsigned int index)
  : JVCVCR2(guiObject, index)
{
  setKeysetName("VCR Keyset 2a");

  addKey("red", Red_Key, 0xE0, 8);
  addKey("green", Green_Key, 0xA8, 8);
  addKey("yellow", Yellow_Key, 0x28, 8);
  addKey("blue", Blue_Key, 0x60, 8);
  addKey("menu", Menu_Key, 0xC8, 8);
  addKey("last", Unmapped_Key, 0xA8, 8); // what is this?
  addKey("suchl", Unmapped_Key, 0x69, 8); // ditto
}


JVCVCR2b::JVCVCR2b(
  QObject *guiObject,
  unsigned int index)
  : JVCVCR2(guiObject, index)
{
  setKeysetName("VCR (alt) keyset 2b");

  setPreData(0xCA, 8);
}


JVCVCR2c::JVCVCR2c(
  QObject *guiObject,
  unsigned int index)
  : JVCVCR2(guiObject, index)
{
  setKeysetName("VCR Keyset 2c");

  addKey("tv", Input_Key, 0x08, 8);
}


JVCTV1::JVCTV1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      JVC_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    600, 500,
    600, 1600,
    45000, true);

  threadableProtocol = np;

  np->setTrailerPulse(600);

  setPreData(0xC0, 8);

  addKey("Power", Power_Key, 0xE8, 8);
  addKey("Vol+", VolumeUp_Key, 0x78, 8);
  addKey("Vol-", VolumeDown_Key, 0xF8, 8);
  addKey("Prog+", ChannelUp_Key, 0x98, 8);
  addKey("Prog-", ChannelDown_Key, 0x18, 8);
  addKey("TV/VCR", Input_Key, 0xC8, 8); // "input"
  addKey("0", Zero_Key, 0x04, 8);
  addKey("1", One_Key, 0x84, 8);
  addKey("2", Two_Key, 0x44, 8);
  addKey("3", Three_Key, 0xC4, 8);
  addKey("4", Four_Key, 0x24, 8);
  addKey("5", Five_Key, 0xA4, 8);
  addKey("6", Six_Key, 0x64, 8);
  addKey("7", Seven_Key, 0xE4, 8);
  addKey("8", Eight_Key, 0x14, 8);
  addKey("9", Nine_Key, 0x94, 8);
  addKey("X", Clear_Key, 0x0E, 8);
  addKey("AUDIO", Mute_Key, 0x38, 8); // "mute"
  addKey("Timer", Sleep_Key, 0x8E, 8);
//  addKey("SP/LP", VHSSpeed_Key, 0xB9, 8); // "/_//"
  addKey("-/--", DoubleDigit_Key, 0xB9, 8);
//  addKey("Red", Red_Key, 0x89, 8);
//  addKey("Green", Green_Key, 0xDC, 8);
//  addKey("Yellow", Yellow_Key, 0xE9, 8);
//  addKey("Blue", Blue_Key, 0x8C, 8);
  addKey("info", Info_Key, 0x20, 8); // "display"
  addKey("standard", PictureMode_Key, 0x9E, 8); // "picture_mode"
  addKey("menu", Menu_Key, 0x5E, 8);
  addKey("sound", Unmapped_Key, 0x42, 8); // "<>"
  addKey("video_status", Unmapped_Key, 0xB0, 8);
  addKey("theater_pro", Unmapped_Key, 0xAB, 8);
  addKey("aspect", AspectRatio_Key, 0xC9, 8);
  addKey("100+", PlusOneHundred_Key, 0xEE, 8);
  addKey("return", Unmapped_Key, 0xA0, 8);
  addKey("cc", Captions_Key, 0x70, 8);
  addKey("exit", Exit_Key, 0x67, 8);
  addKey("colour", Unmapped_Key, 0x49, 8); // "P/S"
  addKey("sound", SoundMode_Key, 0x2D, 8);
  addKey("up", Up_Key, 0x3E, 8);
  addKey("down", Down_Key, 0xDE, 8);
  addKey("left", Left_Key, 0xDA, 8);
  addKey("right", Right_Key, 0x5A, 8);
  addKey("BROADCAST", Unmapped_Key, 0xD0, 8); // "ant/cable"
  addKey("RECALL", PrevChannel_Key, 0x3C, 8);
  addKey("RESET", Reset_Key, 0x60, 8);
  addKey("FUNCTION", Unmapped_Key, 0xDC, 8);
  addKey("LEVELDOWN", Unmapped_Key, 0xD8, 8);
  addKey("LEVELUP", Unmapped_Key, 0x58, 8);
  addKey("main/sap", Language_Key, 0x00, 8); // "I/II"
  addKey("CH_PRESET", Unmapped_Key, 0x99, 8);
  addKey("MAX_CH", Unmapped_Key, 0xB9, 8);
  addKey("C1/C2", Unmapped_Key, 0x5B, 8);
  addKey("input_2", Unmapped_Key, 0x48, 8);
  addKey("input_3", Unmapped_Key, 0x28, 8);
  addKey("input_s", Unmapped_Key, 0xF0, 8);
  addKey("tone", Unmapped_Key, 0x09, 8);
  addKey("VNR", Unmapped_Key, 0xA2, 8);
  addKey("br_down", Unmapped_Key, 0x8C, 8);
  addKey("br_up", Unmapped_Key, 0x0C, 8);
  addKey("con_down", Unmapped_Key, 0xEC, 8);
  addKey("con_up", Unmapped_Key, 0x6C, 8);
  addKey("col_down", Unmapped_Key, 0xCC, 8);
  addKey("col_up", Unmapped_Key, 0x4C, 8);
}


JVCTV1a::JVCTV1a(
  QObject *guiObject,
  unsigned int index)
  : JVCTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1a");

  addKey("+10", DoubleDigit_Key, 0x8E, 8);
}


JVCTV1b::JVCTV1b(
  QObject *guiObject,
  unsigned int index)
  : JVCTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1b");

  addKey("sleep_timer", Sleep_Key, 0xC0, 8);
}


JVCTV1c::JVCTV1c(
  QObject *guiObject,
  unsigned int index)
  : JVCTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1c");

  addKey("REW", Rewind_Key, 0x4D, 8);
  addKey("PLAY", Play_Key, 0x91, 8);
  addKey("FF", FastForward_Key, 0x6B, 8);
  addKey("REC", Record_Key, 0x20, 8);
  addKey("STOP", Stop_Key, 0x00, 8);
  addKey("PAUSE", Pause_Key, 0xD0, 8);
}


// TVs where "volume" and "channel" keys are used to navigate menus:
JVCTV1d::JVCTV1d(
  QObject *guiObject,
  unsigned int index)
  : JVCTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1d");

  addKey("up", Up_Key, 0x98, 8);
  addKey("down", Down_Key, 0x18, 8);
  addKey("left", Left_Key, 0xF8, 8);
  addKey("right", Right_Key, 0x78, 8);
}


// Same deal here, two different header specifications on top of the same
// underlying keyset.
JVCTV2::JVCTV2(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 2",
      JVC_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    600, 500,
    600, 1600,
    46000, true);

  threadableProtocol = np;

  np->setHeaderPair(9000, 4500);
  np->setTrailerPulse(600);
  np->setFullHeadlessRepeat(true);

  setPreData(0xC0, 8);

  addKey("Power", Power_Key, 0xE8, 8);
  addKey("Vol+", VolumeUp_Key, 0x78, 8);
  addKey("Vol-", VolumeDown_Key, 0xF8, 8);
  addKey("Prog+", ChannelUp_Key, 0x98, 8);
  addKey("Prog-", ChannelDown_Key, 0x18, 8);
  addKey("TV/VCR", Input_Key, 0xC8, 8);
  addKey("0", Zero_Key, 0x04, 8);
  addKey("1", One_Key, 0x84, 8);
  addKey("2", Two_Key, 0x44, 8);
  addKey("3", Three_Key, 0xC4, 8);
  addKey("4", Four_Key, 0x24, 8);
  addKey("5", Five_Key, 0xA4, 8);
  addKey("6", Six_Key, 0x64, 8);
  addKey("7", Seven_Key, 0xE4, 8);
  addKey("8", Eight_Key, 0x14, 8);
  addKey("9", Nine_Key, 0x94, 8);
  addKey("X", Clear_Key, 0x0E, 8);
  addKey("AUDIO", Mute_Key, 0x38, 8); // "mute"
  addKey("Timer", Sleep_Key, 0x8E, 8);
//  addKey("SP/LP", VHSSpeed_Key, 0xB9, 8);
  addKey("-/--", DoubleDigit_Key, 0xB9, 8);
  addKey("info", Info_Key, 0x20, 8);
  addKey("standard", PictureMode_Key, 0x9E, 8); // "picture_mode"
  addKey("menu", Menu_Key, 0x5E, 8);
  addKey("sound", Unmapped_Key, 0x42, 8);
  addKey("video_status", Unmapped_Key, 0xB0, 8);
  addKey("theater_pro", Unmapped_Key, 0xAB, 8);
  addKey("aspect", AspectRatio_Key, 0xC9, 8);
  addKey("100+", PlusOneHundred_Key, 0xEE, 8);
  addKey("return", Unmapped_Key, 0xA0, 8);
  addKey("cc", Captions_Key, 0x70, 8);
  addKey("exit", Exit_Key, 0x67, 8);
  addKey("colour", Unmapped_Key, 0x49, 8);
  addKey("sound", SoundMode_Key, 0x2D, 8);
  addKey("up", Up_Key, 0x3E, 8);
  addKey("down", Down_Key, 0xDE, 8);
  addKey("left", Left_Key, 0xDA, 8);
  addKey("right", Right_Key, 0x5A, 8);
  addKey("BROADCAST", Unmapped_Key, 0xD0, 8);
  addKey("RECALL", PrevChannel_Key, 0x3C, 8);
  addKey("RESET", Reset_Key, 0x60, 8);
  addKey("FUNCTION", Unmapped_Key, 0xDC, 8);
  addKey("LEVELDOWN", Unmapped_Key, 0xD8, 8);
  addKey("LEVELUP", Unmapped_Key, 0x58, 8);
  addKey("main/sap", Language_Key, 0x00, 8);
  addKey("CH_PRESET", Unmapped_Key, 0x99, 8);
  addKey("MAX_CH", Unmapped_Key, 0xB9, 8);
  addKey("C1/C2", Unmapped_Key, 0x5B, 8);
  addKey("input_2", Unmapped_Key, 0x48, 8);
  addKey("input_3", Unmapped_Key, 0x28, 8);
  addKey("input_s", Unmapped_Key, 0xF0, 8);
  addKey("tone", Unmapped_Key, 0x09, 8);
  addKey("VNR", Unmapped_Key, 0xA2, 8);
  addKey("br_down", Unmapped_Key, 0x8C, 8);
  addKey("br_up", Unmapped_Key, 0x0C, 8);
  addKey("con_down", Unmapped_Key, 0xEC, 8);
  addKey("con_up", Unmapped_Key, 0x6C, 8);
  addKey("col_down", Unmapped_Key, 0xCC, 8);
  addKey("col_up", Unmapped_Key, 0x4C, 8);
}


JVCTV2a::JVCTV2a(
  QObject *guiObject,
  unsigned int index)
  : JVCTV2(guiObject, index)
{
  setKeysetName("TV Keyset 2a");

  addKey("+10", DoubleDigit_Key, 0x8E, 8);
}


JVCTV2b::JVCTV2b(
  QObject *guiObject,
  unsigned int index)
  : JVCTV2(guiObject, index)
{
  setKeysetName("TV Keyset 2b");

  addKey("sleep_timer", Sleep_Key, 0xC0, 8);
}


JVCTV2c::JVCTV2c(
  QObject *guiObject,
  unsigned int index)
  : JVCTV2(guiObject, index)
{
  setKeysetName("TV Keyset 2c");

  addKey("REW", Rewind_Key, 0x4D, 8);
  addKey("PLAY", Play_Key, 0x91, 8);
  addKey("FF", FastForward_Key, 0x6B, 8);
  addKey("REC", Record_Key, 0x20, 8);
  addKey("STOP", Stop_Key, 0x00, 8);
  addKey("PAUSE", Pause_Key, 0xD0, 8);
}


JVCTV2d::JVCTV2d(
  QObject *guiObject,
  unsigned int index)
  : JVCTV2(guiObject, index)
{
  setKeysetName("TV Keyset 2d");

  addKey("up", Up_Key, 0x98, 8);
  addKey("down", Down_Key, 0x18, 8);
  addKey("left", Left_Key, 0xF8, 8);
  addKey("right", Right_Key, 0x78, 8);
}


JVCDAT1::JVCDAT1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "DAT Keyset 1",
      JVC_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    600, 500,
    600, 1600,
    46000, true);

  threadableProtocol = np;

  np->setHeaderPair(9000, 4500);
  np->setTrailerPulse(600);

  np->setFullHeadlessRepeat(true);

  setPreData(0xC9, 8);

  addKey("1", One_Key, 0x84, 8);
  addKey("2", Two_Key, 0x44, 8);
  addKey("3", Three_Key, 0xC4, 8);
  addKey("4", Four_Key, 0x24, 8);
  addKey("5", Five_Key, 0xA4, 8);
  addKey("6", Six_Key, 0x64, 8);
  addKey("7", Seven_Key, 0xE4, 8);
  addKey("8", Eight_Key, 0x14, 8);
  addKey("9", Nine_Key, 0x94, 8);
  addKey("0", Zero_Key, 0x04, 8);
  addKey("MEMORY", Unmapped_Key, 0x48, 8);
  addKey("REPEAT", Unmapped_Key, 0xD8, 8);
  addKey("DISPLAY", Info_Key, 0x28, 8);
  addKey("CANCEL/RESET", Reset_Key, 0xB4, 8);
  addKey("CALL", Unmapped_Key, 0xA8, 8);
  addKey("RESERVE", Unmapped_Key, 0x54, 8);
  addKey("INTRO", Unmapped_Key, 0x88, 8);
  addKey("REC_MUTE", Unmapped_Key, 0x38, 8);
  addKey("REC", Record_Key, 0x40, 8);
  addKey("PAUSE", Pause_Key, 0xB0, 8);
  addKey("|<-SKIP", Previous_Key, 0x18, 8);
  addKey("SKIP->|", Next_Key, 0x98, 8);
  addKey("<<-SEARCH", Unmapped_Key, 0xE8, 8);
  addKey("SEARCH->>", Unmapped_Key, 0x68, 8);
  addKey("REW", Rewind_Key, 0xE0, 8);
  addKey("FF", FastForward_Key, 0x60, 8);
  addKey("STOP", Stop_Key, 0xC0, 8);
  addKey("PLAY", Play_Key, 0x30, 8);
}


JVCCarDeck1::JVCCarDeck1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Car Deck Keyset 1",
      JVC_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    600, 500,
    600, 1600,
    46000, true);

  threadableProtocol = np;

  np->setHeaderPair(9000, 4500);
  np->setTrailerPulse(600);

  np->setFullHeadlessRepeat(true);

  setPreData(0xF1, 8);

  addKey("Power", Power_Key, 0x71, 8); // "Att"
  addKey("Sound", Mute_Key, 0xB1, 8); // "SCM"
  addKey("Source", Input_Key, 0x11, 8);  // "FUNC", "SRC"
  addKey("DISC+", Up_Key, 0x29, 8);
  addKey("DISC-", Down_Key, 0xA9, 8);
  addKey("Vol+", VolumeUp_Key, 0x21, 8);
  addKey("Vol-", VolumeDown_Key, 0xA1, 8);
  addKey("Track+", Next_Key, 0x49, 8);
  addKey("Track-", Previous_Key, 0xC9, 8);
  addKey("FF", FastForward_Key, 0x49, 8);
  addKey("Rew", Rewind_Key, 0xC9, 8);
}


JVCPortableAudio1::JVCPortableAudio1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 1",
      JVC_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    600, 500,
    600, 1600,
    46000, true);

  threadableProtocol = np;

  np->setHeaderPair(9000, 4500);
  np->setTrailerPulse(600);

  np->setFullHeadlessRepeat(true);

  addKey("POWER", Power_Key, 0xC5E8, 16);
  addKey("1", One_Key, 0xCD86, 16);
  addKey("2", Two_Key, 0xCD46, 16);
  addKey("3", Three_Key, 0xCDC6, 16);
  addKey("4", Four_Key, 0xCD26, 16);
  addKey("5", Five_Key, 0xCDA6, 16);
  addKey("6", Six_Key, 0xCD66, 16);
  addKey("7", Seven_Key, 0xCDE6, 16);
  addKey("8", Eight_Key, 0xCD16, 16);
  addKey("9", Nine_Key, 0xCD96, 16);
  addKey("10", Zero_Key, 0xCD76, 16); // Ok, yeah, this one is a hack...
  addKey("+10", DoubleDigit_Key, 0xCDF6, 16);
  addKey("REPEAT", Unmapped_Key, 0xCDDA, 16);
  addKey("RANDOM", Unmapped_Key, 0xCD4E, 16);
  addKey("INTRO", Unmapped_Key, 0xCD12, 16);
  addKey("MEMORY/CALL", Unmapped_Key, 0xCD56, 16);
  addKey("REW", Rewind_Key, 0xCD1A, 16);
  addKey("FF", FastForward_Key, 0xCD9A, 16); // "CD.Next"
  addKey("STOP", Stop_Key, 0xCDC2, 16); // "CD.Stop"
  addKey("PLAY", Play_Key, 0xCD32, 16); // "CD.Play"
  addKey("VOL-", VolumeDown_Key, 0xC5F8, 16);
  addKey("VOL+", VolumeUp_Key, 0xC578, 16);
  addKey("SLEEP", Sleep_Key, 0xC5C0, 16);
  addKey("DIMMER", Unmapped_Key, 0xCD4A, 16);
  addKey("FM-MODE", Unmapped_Key, 0xC55A, 16);
  addKey("MD-AUX", Unmapped_Key, 0xC57C, 16); // "TAPE-AUX"
  addKey("AHB-PRO", Unmapped_Key, 0xC5AE, 16);
  addKey("AUTO-PRESET", Unmapped_Key, 0xC5EE, 16);
  addKey("CD-EJECT", Eject_Key, 0xCD22, 16);
  addKey("PROGRAM", Program_Key, 0xCD56, 16);
  addKey("RANDOM", Unmapped_Key, 0xCD4E, 16);
  addKey("REPEAT", Unmapped_Key, 0xCDDA, 16);
  addKey("BASS", Unmapped_Key, 0xF578, 16);
  addKey("TREBLE", Unmapped_Key, 0xF574, 16);
  addKey("CANCEL", Clear_Key, 0xCDB6, 16);
  addKey("UP", Up_Key, 0xF500, 16);
  addKey("DOWN", Down_Key, 0xF580, 16);
  addKey("LEFT", Left_Key, 0xF5C0, 16);
  addKey("RIGHT", Right_Key, 0xF540, 16);
  addKey("PTY-EON", Unmapped_Key, 0xF5A1, 16);
  addKey("DISPLAY-MODE", Info_Key, 0xF5C1, 16);
  addKey("SET", Select_Key, 0xF589, 16);
  addKey("TAPE", Unmapped_Key, 0xC5FC, 16);
  addKey("TUNER-BAND", Unmapped_Key, 0xC5DA, 16);
  addKey("PREV", Previous_Key, 0xF560, 16);
  addKey("NEXT", Next_Key, 0xF5A0, 16);
  addKey("EDIT-TITLE", Unmapped_Key, 0xFD91, 16);
  addKey("CHARA", Unmapped_Key, 0xFD1D, 16);
}


JVCPortableAudio1a::JVCPortableAudio1a(
  QObject *guiObject,
  unsigned int index)
  : JVCPortableAudio1(guiObject, index)
{
  setKeysetName("Audio Keyset 1a");

  addKey("CD-PLAY-PAUSE", Play_Key, 0xC5BC, 16);
  addKey("MD-PLAY-PAUSE", Unmapped_Key, 0xF50C, 16);
}


// This is not portable audio.  This is all sorts of audio devices.  I need
// to do some work to clean this up!
JVCPortableAudio1b::JVCPortableAudio1b(
  QObject *guiObject,
  unsigned int index)
  : JVCPortableAudio1(guiObject, index)
{
  setKeysetName("Audio Keyset 1b");

  addKey("0", Zero_Key, 0xCD06, 16); // What about "10" key here?
  addKey("TUNER", Unmapped_Key, 0xC5D0, 16);
  addKey("VCR", Unmapped_Key, 0xC224, 16);
  addKey("CD", Unmapped_Key, 0xC5BC, 16);
  addKey("PHONO", Unmapped_Key, 0xC53C, 16);
  addKey("MONITOR/TAPE2", Unmapped_Key, 0xC5E0, 16);
  addKey("STOP2", Unmapped_Key, 0xC1C2, 16);
  addKey("STILL/PAUSE", Pause_Key, 0xC1B0, 16);
  addKey("STOP", Stop_Key, 0xC1B0, 16);
  addKey("REC+PLAY", Unmapped_Key, 0xC133, 16);
  addKey("FORWARDS", FastForward_Key, 0xC160, 16); // "Deck.Right"
  addKey("BACKWARDS", Rewind_Key, 0xC1E0, 16); // "Deck.Left"
  addKey("PLAY", Play_Key, 0xC130, 16);
  addKey("FADE_MUTING", Unmapped_Key, 0xC538, 16);
  addKey("Disc 1", Unmapped_Key, 0xCD9E, 16);
  addKey("Disc 2", Unmapped_Key, 0xCD5E, 16);
  addKey("Disc 3", Unmapped_Key, 0xCDDE, 16);
  addKey("Disc 4", Unmapped_Key, 0xCD3E, 16);
  addKey("Disc 5", Unmapped_Key, 0xCDBE, 16);
  addKey("Disc 6", Unmapped_Key, 0xCD7E, 16);
  addKey("Disc continue", Unmapped_Key, 0xCDEE, 16);
  addKey("Disc program", Unmapped_Key, 0xCD8E, 16);
  addKey("Tuner 1", Unmapped_Key, 0xC584, 16);
  addKey("Tuner 2", Unmapped_Key, 0xC544, 16);
  addKey("Tuner 3", Unmapped_Key, 0xC5C4, 16);
  addKey("Tuner 4", Unmapped_Key, 0xC524, 16);
  addKey("Tuner 5", Unmapped_Key, 0xC5A4, 16);
  addKey("Tuner 6", Unmapped_Key, 0xC564, 16);
  addKey("Tuner 7", Unmapped_Key, 0xC5E4, 16);
  addKey("Tuner 8", Unmapped_Key, 0xC514, 16);
  addKey("Tuner 9", Unmapped_Key, 0xC594, 16);
  addKey("Tuner 10", Unmapped_Key, 0xC554, 16);
  addKey("Tuner +10", Unmapped_Key, 0xC5F4, 16);
  addKey("Tuner 0", Unmapped_Key, 0xC504, 16);
  addKey("tape-play", Unmapped_Key, 0xC130, 16);
  addKey("tape-stop", Unmapped_Key, 0xC1C0, 16); // "Deck.Stop"
  addKey("tuner-", Unmapped_Key, 0xC518, 16);
  addKey("tuner+", Unmapped_Key, 0xC598, 16);
  addKey("cd-play", Unmapped_Key, 0xC5BC, 16);
  addKey("cd-stop", Unmapped_Key, 0xCDC2, 16);
  addKey("cd-pause", Unmapped_Key, 0xCDB2, 16);
  addKey("cd-prev", Unmapped_Key, 0xCD1A, 16);
  addKey("cd-next", Unmapped_Key, 0xCD9A, 16);
  addKey("cd-back", Unmapped_Key, 0xCD0E, 16);
  addKey("cd-forw", Unmapped_Key, 0xCD6E, 16);
  addKey("Deck.PlayLeft", Unmapped_Key, 0xC170, 16);
  addKey("Deck.PlayRight", Unmapped_Key, 0xC1F0, 16);
  addKey("Deck.A", Unmapped_Key, 0xC10B, 16);
  addKey("Deck.B", Unmapped_Key, 0xC18B, 16);
  addKey("RecPause", Unmapped_Key, 0xC1B3, 16);
  addKey("SoundMode", Unmapped_Key, 0xC51C, 16);
}


JVCPortableAudio2::JVCPortableAudio2(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 2",
      JVC_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    600, 500,
    600, 1600,
    46000, true);

  threadableProtocol = np;

  np->setHeaderPair(9000, 4500);
  np->setTrailerPulse(600);

  np->setFullHeadlessRepeat(true);

  setPreData(0xF9, 8);

  addKey("stop", Stop_Key, 0x8E, 8); // "CD_STOP" "stop_clear"
  addKey("stop", Clear_Key, 0x8E, 8); // "CD_STOP" "stop_clear"
  addKey("vol+", VolumeUp_Key, 0x80, 8);
  addKey("vol-", VolumeDown_Key, 0x40, 8);
  addKey("play", Play_Key, 0x0E, 8); // "CD_PLAY_PAUSE"
  addKey("play", Pause_Key, 0x0E, 8); // "CD_PLAY_PAUSE"
  addKey("ff", FastForward_Key, 0xBC, 8); // "SEARCH_UP" "search_forward"
  addKey("rew", Rewind_Key, 0x7C, 8);  // "SEARCH_DOWN" "search_back"
  addKey("1", One_Key, 0x84, 8);
  addKey("2", Two_Key, 0x44, 8);
  addKey("3", Three_Key, 0xC4, 8);
  addKey("4", Four_Key, 0x24, 8);
  addKey("5", Five_Key, 0xA4, 8);
  addKey("6", Six_Key, 0x64, 8);
  addKey("7", Seven_Key, 0xE4, 8);
  addKey("8", Eight_Key, 0x14, 8);
  addKey("9", Nine_Key, 0x94, 8);
  addKey("10", Zero_Key, 0x54, 8); // Yeah, I know this is bad
  addKey("10+", DoubleDigit_Key, 0x74, 8);
  addKey("enter", Enter_Key, 0x88, 8);
  addKey("repeat", Unmapped_Key, 0x1E, 8);
  addKey("random", Unmapped_Key, 0xEE, 8);
  addKey("intro", Unmapped_Key, 0x6E, 8);
  addKey("memory", Program_Key, 0x2E, 8); // "MEMORY_CALL", "program"
  addKey("call", Unmapped_Key, 0xFE, 8);
  addKey("display", Info_Key, 0x38, 8); // "CLOCK"
  addKey("sleep", Sleep_Key, 0x4C, 8);
  addKey("power", Power_Key, 0x00, 8);
  addKey("band", Unmapped_Key, 0xD0, 8);  // "TUNER_BAND"
  addKey("PRESET_SCAN", Unmapped_Key, 0x48, 8);
  addKey("SET", Select_Key, 0xCC, 8); // "clock"
  addKey("TIMER_ON_OFF", Unmapped_Key, 0x6C, 8); // might be another sleep
  addKey("TIMER_SET", Unmapped_Key, 0x0C, 8);
  addKey("ACTIVE_HYPER_BASS", Unmapped_Key, 0x20, 8); // "bass"
  addKey("FREQUENCY", Unmapped_Key, 0x01, 8);
  addKey("NEXT_TRACK", Next_Key, 0x4E, 8);
  addKey("PREV_TRACK", Previous_Key, 0xCE, 8);
  addKey("auto_preset", Unmapped_Key, 0xC8, 8);
  addKey("open_close", Eject_Key, 0xDE, 8); // "allcdeject"
  addKey("auto_preset", Unmapped_Key, 0xC8, 8);
  addKey("auto_mono", Unmapped_Key, 0xF8, 8);  // "fmstereo", "mode"
  addKey("tone", Unmapped_Key, 0x61, 8);
  addKey("revmode", Unmapped_Key, 0xFA, 8);
  addKey("playcd1", Unmapped_Key, 0x8F, 8);
  addKey("playcd2", Unmapped_Key, 0x4F, 8);
  addKey("playcd3", Unmapped_Key, 0xCF, 8);
  addKey("continue", Unmapped_Key, 0xBE, 8);
  addKey("ejectcd1", Unmapped_Key, 0x2F, 8);
  addKey("ejectcd2", Unmapped_Key, 0xAF, 8);
  addKey("ejectcd2", Unmapped_Key, 0x6F, 8);
  addKey("tape", Unmapped_Key, 0x42, 8);
  addKey("aux", Unmapped_Key, 0xB0, 8);
  addKey("deckab", Unmapped_Key, 0x1A, 8);
  addKey("sound", Unmapped_Key, 0xF1, 8);
  addKey("presettuning", Unmapped_Key, 0xA8, 8);
  addKey("record", Record_Key, 0xD2, 8); // "TAPEREC"
  addKey("reverseplay", Unmapped_Key, 0xB2, 8); // "TAPELEFT"
  addKey("stop", Unmapped_Key, 0x82, 8); // "TAPESTOP"
  addKey("play", Unmapped_Key, 0x32, 8); // "TAPERIGHT"
  addKey("bass-", Unmapped_Key, 0x11, 8);
  addKey("bass+", Unmapped_Key, 0xE1, 8);
  addKey("treble-", Unmapped_Key, 0x51, 8);
  addKey("treble+", Unmapped_Key, 0x91, 8);
  addKey("onoff", Unmapped_Key, 0x6C, 8); // same keyset already has "power"?
  addKey("edit", Unmapped_Key, 0xAE, 8);
  addKey("synchrorec", Unmapped_Key, 0x6A, 8);
  addKey("rewind", Unmapped_Key, 0xA2, 8); // "TAPEPREV"
  addKey("ff", Unmapped_Key, 0x22, 8); // "TAPENEXT"
  addKey("beat-cut", Unmapped_Key, 0x77, 8);
  addKey("pty-eon", Unmapped_Key, 0xE8, 8);
  addKey("left-select", Unmapped_Key, 0x98, 8);
  addKey("right-select", Unmapped_Key, 0x18, 8);
  addKey("display-mode", Unmapped_Key, 0x68, 8);
}


JVCDVD1::JVCDVD1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      JVC_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    600, 500,
    600, 1600,
    46000, true);

  threadableProtocol = np;

  np->setHeaderPair(9000, 4500);
  np->setTrailerPulse(600);
  np->setFullHeadlessRepeat(true);

  addKey("openclose", Eject_Key, 0xF722, 16);
  addKey("1", One_Key, 0xF786, 16);
  addKey("2", Two_Key, 0xF746, 16);
  addKey("3", Three_Key, 0xF7C6, 16);
  addKey("4", Four_Key, 0xF726, 16);
  addKey("5", Five_Key, 0xF7A6, 16);
  addKey("6", Six_Key, 0xF766, 16);
  addKey("7", Seven_Key, 0xF7E6, 16);
  addKey("8", Eight_Key, 0xF716, 16);
  addKey("9", Nine_Key, 0xF796, 16);
  addKey("10", Unmapped_Key, 0xF776, 16);
  addKey("0", Zero_Key, 0xF706, 16);
  addKey("+10", DoubleDigit_Key, 0xF7F6, 16);
  addKey("return", Exit_Key, 0xF7AB, 16);
  addKey("title/group", Unmapped_Key, 0xF777, 16);
  addKey("cancel", Clear_Key, 0xF7B6, 16);
  addKey("topmenu", DiscTitle_Key, 0xF743, 16);
  addKey("up", Up_Key, 0xF70B, 16);
  addKey("menu", Menu_Key, 0xF783, 16);
  addKey("left", Left_Key, 0xF74B, 16);
  addKey("enter", Select_Key, 0xF72B, 16);
  addKey("right", Right_Key, 0xF7CB, 16);
  addKey("choice", Unmapped_Key, 0xF7FE, 16);
  addKey("down", Down_Key, 0xF78B, 16);
  addKey("onscreen", Unmapped_Key, 0xF703, 16);
  addKey("skip_back", Previous_Key, 0xF78D, 16); // "previous"
  addKey("skip_forw", Next_Key, 0xF70D, 16); // "next"
  addKey("stop", Stop_Key, 0xF7C2, 16);
  addKey("play", Play_Key, 0xF732, 16);
  addKey("pause", Pause_Key, 0xF7B2, 16);
  addKey("back", Rewind_Key, 0xF70E, 16); // "SLOW_MINUS"
  addKey("forw", FastForward_Key, 0xF76E, 16); // "SLOW_PLUS"
  addKey("repeat", Unmapped_Key, 0xF7DA, 16);
  addKey("subtitle", Captions_Key, 0xF7B3, 16);
  addKey("audio", Unmapped_Key, 0xF713, 16);
  addKey("vfp", Unmapped_Key, 0xF77D, 16); // "theaterposition"
  addKey("digest", Unmapped_Key, 0xF79D, 16);
  addKey("angle", Unmapped_Key, 0xF7D3, 16);
  addKey("zoom-", Unmapped_Key, 0xF7F5, 16);
  addKey("zoom+", Unmapped_Key, 0xF775, 16);
  addKey("3dphonix", Unmapped_Key, 0xF7BD, 16);
  addKey("voldown", VolumeDown_Key, 0xC5F8, 16);
  addKey("volup", VolumeUp_Key, 0xC578, 16);
  addKey("power", Power_Key, 0xF702, 16);
  addKey("playmode", Unmapped_Key, 0xF7C1, 16);
  addKey("zoom", Unmapped_Key, 0xF73D, 16);
  addKey("display", Info_Key, 0xF7AD, 16);
  addKey("SWOOP", Unmapped_Key, 0xF792, 16);
  addKey("DIMMER", Unmapped_Key, 0xF78A, 16);
}
