#include "jvc.h"
#include "protocols/jvcprotocol.h"
#include "protocols/lircprotocol.h"

JVCSat1::JVCSat1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Sat (Dish) Keyset 1",
      JVC_Make,
      index)
{
  LIRCProtocol *lp = new LIRCProtocol(
   guiObject,
   index,
   624, 1500,
   624, 2600,
   6000, false);

  threadableProtocol = lp;

  lp->setHeaderPair(750, 6000);
  lp->setTrailerPulse(624);

  lp->setFullHeadlessRepeat(true);

//  np->setCarrierFrequency(56000);
//  np->setDutyCycle(32);

  addKey("power", Power_Key, 0x1EFC, 13);
  addKey("recent", Unmapped_Key, 0x16FC, 13);
  addKey("tvWeb", Unmapped_Key, 0x1A7C, 13);
  addKey("scrollUp", PageUp_Key, 0x137C, 13);
  addKey("scrollDown", PageDown_Key, 0x117C, 13);
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
  LIRCProtocol *lp = new LIRCProtocol(
    guiObject,
    index,
    440, 2780,
    440, 1645,
    6115, false);

  threadableProtocol = lp;

  lp->setHeaderPair(525, 6045);
  lp->setTrailerPulse(450);

//  lp->setMinimumRepetitions(6);
  lp->setFullHeadlessRepeat(true);

  lp->setCarrierFrequency(56000);
  lp->setDutyCycle(32);

  setPostData(0x000, 10);

  addKey("info", Info_Key, 0x0, 6);
  addKey("power_on", PowerOn_Key, 0x1, 6);
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
  addKey("power_off", PowerOff_Key, 0x39, 6);
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
  threadableProtocol = new JVCProtocol(guiObject, index);

//  setPreData(0xC2, 8);
  setPreData(0x43, 8);

  addKey("av", Unmapped_Key, 0x01, 8);
  addKey("stop", Stop_Key, 0x03, 8);
  addKey("eject", Eject_Key, 0x04, 8);
  addKey("forward", FastForward_Key, 0x06, 8);
  addKey("backward", Rewind_Key, 0x07, 8);
  addKey("power", Power_Key, 0x0B, 8);
  addKey("pause", Pause_Key, 0x0D, 8);
  addKey("play", Play_Key, 0x0E, 8);

  addKey("input_1", Unmapped_Key, 0x11, 8);
  addKey("tv_vcr", Input_Key, 0x13, 8); // "monitor"
  addKey("right", Next_Key, 0x14, 8); // "JOG+"
  addKey("left", Previous_Key, 0x15, 8); // "JOG-"
  addKey("MUTE", Mute_Key, 0x17, 8);
  addKey("pr_dn", ChannelDown_Key, 0x18, 8);
  addKey("pr_up", ChannelUp_Key, 0x19, 8);

  addKey("no_1", One_Key, 0x21, 8);
  addKey("no_2", Two_Key, 0x22, 8);
  addKey("no_3", Three_Key, 0x23, 8);
  addKey("no_4", Four_Key, 0x24, 8);
  addKey("no_5", Five_Key, 0x25, 8);
  addKey("no_6", Six_Key, 0x26, 8);
  addKey("no_7", Seven_Key, 0x27, 8);
  addKey("no_8", Eight_Key, 0x28, 8);
  addKey("no_9", Nine_Key, 0x29, 8);
  addKey("SPEED", VHSSpeed_Key, 0x31, 8); // "I/II"
  addKey("Blue", Blue_Key, 0x31, 8); // odd
  addKey("no_0", Zero_Key, 0x33, 8);

  addKey("TIMER", Timer_Key, 0x35, 8);
  addKey("CANCEL", Exit_Key, 0x36, 8); // "zero4x", "reset"
  addKey("CANCEL", Clear_Key, 0x36, 8); // "zero4x", "reset"
  addKey("menu", Menu_Key, 0x37, 8); // "PROG"
  addKey("DISPLAY", Info_Key, 0x38, 8);
  addKey("clock", Clock_Key, 0x3A, 8);
  addKey("Green", Green_Key, 0x3B, 8);
  addKey("ok", Select_Key, 0x3C, 8);
  addKey("check", Unmapped_Key, 0x3D, 8); // "prog_check"
  addKey("enter", Enter_Key, 0x3E, 8); // "store"

  addKey("ch_set", Unmapped_Key, 0x66, 8);
  addKey("line", Unmapped_Key, 0x6E, 8);
  addKey("mode", Mode_Key, 0x81, 8);
  addKey("Red", Red_Key, 0x91, 8);
  addKey("INDEX1", Unmapped_Key, 0x93, 8);
  addKey("INDEX2", Unmapped_Key, 0x94, 8);
  addKey("3dphonic", Unmapped_Key, 0x95, 8);
  addKey("ff_30sec", Advance_Key, 0x96, 8); // "skip"
  addKey("scene-finder", Unmapped_Key, 0x97, 8);
  addKey("Yellow", Yellow_Key, 0x97, 8);
  addKey("start", Unmapped_Key, 0x98, 8);
  addKey("showview", Program_Key, 0xC1, 8); // program
  addKey("review", Replay_Key, 0xC3, 8);
  addKey("SOUND2", Unmapped_Key, 0xC4, 8);
  addKey("date+", Unmapped_Key, 0xC6, 8);
  addKey("date-", Unmapped_Key, 0xC7, 8);
  addKey("start+", Unmapped_Key, 0xC8, 8);
  addKey("start-", Unmapped_Key, 0xC9, 8);
  addKey("stop+", Unmapped_Key, 0xCA, 8);
  addKey("stop-", Unmapped_Key, 0xCB, 8);
  addKey("RECORD", Record_Key, 0xCC, 8); // "1tr"

  addKey("MIC+", Unmapped_Key, 0xD1, 8);
  addKey("MIC-", Unmapped_Key, 0xD2, 8);
  addKey("SOUND1", Unmapped_Key, 0xD7, 8);
  addKey("SOUND3", Unmapped_Key, 0xDC, 8);
  addKey("IN/OUT", Unmapped_Key, 0xDE, 8);
  addKey("lock", Unmapped_Key, 0xF0, 8);
  addKey("die", Unmapped_Key, 0xFA, 8);

  // Cursor keys duplicate some other keys:
  addKey("right", Right_Key, 0x14, 8); // "JOG+"
  addKey("left", Left_Key, 0x15, 8); // "JOG-"
  addKey("pr_dn", Down_Key, 0x18, 8);
  addKey("pr_up", Up_Key, 0x19, 8);
}


JVCVCR1a::JVCVCR1a(
  QObject *guiObject,
  unsigned int index)
  : JVCVCR1(guiObject, index)
{
  setKeysetName("VCR Keyset 1a");

  addKey("red", Red_Key, 0x07, 8);
  addKey("green", Green_Key, 0x51, 8);
  addKey("yellow", Yellow_Key, 0x14, 8);
  addKey("blue", Blue_Key, 0x06, 8);
  addKey("menu", Menu_Key, 0x13, 8);
  addKey("last", Unmapped_Key, 0x15, 8); // what is this?
  addKey("suchl", Unmapped_Key, 0x96, 8); // ditto
}


// Setup keysets for use in B-mode:
JVCVCRBmode1::JVCVCRBmode1(
  QObject *guiObject,
  unsigned int index)
  : JVCVCR1(guiObject, index)
{
  setKeysetName("VCR (B Mode) keyset 1");

  setPreData(0x53, 8);
}


JVCVCRBmode1a::JVCVCRBmode1a(
  QObject *guiObject,
  unsigned int index)
  : JVCVCR1a(guiObject, index)
{
  setKeysetName("VCR (B Mode) keyset 1a");

  setPreData(0x53, 8);
}


JVCTV1::JVCTV1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      JVC_Make,
      index)
{
  threadableProtocol = new JVCProtocol(guiObject, index);

  setPreData(0x03, 8);

  addKey("main/sap", Audio_Key, 0x00, 8); // "I/II"
  addKey("info", Info_Key, 0x04, 8); // "display"
  addKey("return", Unmapped_Key, 0x05, 8);
  addKey("RESET", Reset_Key, 0x06, 8);
  addKey("BROADCAST", Unmapped_Key, 0x0B, 8); // "ant/cable"
  addKey("video_status", Unmapped_Key, 0x0D, 8);
  addKey("cc", Captions_Key, 0x0E, 8);
  addKey("input_s", Unmapped_Key, 0x0F, 8);

  addKey("input_2", Unmapped_Key, 0x12, 8);
  addKey("TV/VCR", Input_Key, 0x13, 8); // "input"
  addKey("input_3", Unmapped_Key, 0x14, 8);
  addKey("Power", Power_Key, 0x17, 8);
  addKey("Prog-", ChannelDown_Key, 0x18, 8);
  addKey("Prog+", ChannelUp_Key, 0x19, 8);
  addKey("LEVELUP", Unmapped_Key, 0x1A, 8);
  addKey("LEVELDOWN", Unmapped_Key, 0x1B, 8);
  addKey("AUDIO", Mute_Key, 0x1C, 8); // "mute"
  addKey("Vol+", VolumeUp_Key, 0x1E, 8);
  addKey("Vol-", VolumeDown_Key, 0x1F, 8);

  addKey("0", Zero_Key, 0x20, 8);
  addKey("1", One_Key, 0x21, 8);
  addKey("2", Two_Key, 0x22, 8);
  addKey("3", Three_Key, 0x23, 8);
  addKey("4", Four_Key, 0x24, 8);
  addKey("5", Five_Key, 0x25, 8);
  addKey("6", Six_Key, 0x26, 8);
  addKey("7", Seven_Key, 0x27, 8);
  addKey("8", Eight_Key, 0x28, 8);
  addKey("9", Nine_Key, 0x29, 8);

  addKey("br_up", BrightnessUp_Key, 0x30, 8);
  addKey("br_down", BrightnessDown_Key, 0x31, 8);
  addKey("col_up", ColorUp_Key, 0x32, 8);
  addKey("col_down", ColorDown_Key, 0x33, 8);
  addKey("con_up", ContrastUp_Key, 0x36, 8);
  addKey("con_down", ContrastDown_Key, 0x37, 8);
  addKey("FUNCTION", Unmapped_Key, 0x3B, 8);
  addKey("RECALL", PrevChannel_Key, 0x3C, 8);
  addKey("sound", Unmapped_Key, 0x42, 8); // "<>"
  addKey("VNR", NoiseReduction_Key, 0x45, 8);
  addKey("right", Right_Key, 0x55, 8);
  addKey("left", Left_Key, 0x5B, 8);
  addKey("X", Clear_Key, 0x70, 8);
  addKey("Timer", Sleep_Key, 0x71, 8);
  addKey("100+", PlusOneHundred_Key, 0x77, 8);
  addKey("standard", PictureMode_Key, 0x79, 8); // "picture_mode"
  addKey("menu", Menu_Key, 0x7A, 8);
  addKey("down", Down_Key, 0x7B, 8);
  addKey("up", Up_Key, 0x7C, 8);

  addKey("tone", Unmapped_Key, 0x90, 8);
  addKey("colour", Unmapped_Key, 0x92, 8); // "P/S"
  addKey("aspect", AspectRatio_Key, 0x93, 8);
  addKey("CH_PRESET", Unmapped_Key, 0x99, 8);
  addKey("MAX_CH", Unmapped_Key, 0x9D, 8);
//  addKey("SP/LP", VHSSpeed_Key, 0x9D, 8); // "/_//"
  addKey("-/--", DoubleDigit_Key, 0x9D, 8);
  addKey("sound", SoundMode_Key, 0xB4, 8);
  addKey("theater_pro", Unmapped_Key, 0xD5, 8);
  addKey("C1/C2", Unmapped_Key, 0xDA, 8);
  addKey("exit", Exit_Key, 0xE6, 8);

//  addKey("Red", Red_Key, 0x91, 8);
//  addKey("Green", Green_Key, 0x3B, 8);
//  addKey("Yellow", Yellow_Key, 0x97, 8);
//  addKey("Blue", Blue_Key, 0x31, 8);
}


JVCTV1a::JVCTV1a(
  QObject *guiObject,
  unsigned int index)
  : JVCTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1a");

  addKey("+10", DoubleDigit_Key, 0x71, 8);
}


JVCTV1b::JVCTV1b(
  QObject *guiObject,
  unsigned int index)
  : JVCTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1b");

  addKey("sleep_timer", Sleep_Key, 0x03, 8);
}


JVCTV1c::JVCTV1c(
  QObject *guiObject,
  unsigned int index)
  : JVCTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1c");

  addKey("STOP", Stop_Key, 0x00, 8);
  addKey("REC", Record_Key, 0x04, 8);
  addKey("PAUSE", Pause_Key, 0x0B, 8);
  addKey("PLAY", Play_Key, 0x89, 8);
  addKey("REW", Rewind_Key, 0xB2, 8);
  addKey("FF", FastForward_Key, 0xD6, 8);
}


// TVs where "volume" and "channel" keys are used to navigate menus:
JVCTV1d::JVCTV1d(
  QObject *guiObject,
  unsigned int index)
  : JVCTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1d");

  addKey("down", Down_Key, 0x18, 8);
  addKey("up", Up_Key, 0x19, 8);
  addKey("right", Right_Key, 0x1E, 8);
  addKey("left", Left_Key, 0x1F, 8);
}


JVCDAT1::JVCDAT1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "DAT Keyset 1",
      JVC_Make,
      index)
{
  threadableProtocol = new JVCProtocol(guiObject, index);

//  setPreData(0xC9, 8);
  setPreData(0x93, 8);

  addKey("REC", Record_Key, 0x02, 8);
  addKey("STOP", Stop_Key, 0x03, 8);
  addKey("FF", FastForward_Key, 0x06, 8);
  addKey("REW", Rewind_Key, 0x07, 8);
  addKey("PLAY", Play_Key, 0x0C, 8);
  addKey("PAUSE", Pause_Key, 0x0D, 8);

  addKey("INTRO", Unmapped_Key, 0x11, 8);
  addKey("MEMORY", Program_Key, 0x12, 8);
  addKey("DISPLAY", Info_Key, 0x14, 8);
  addKey("CALL", Call_Key, 0x15, 8);
  addKey("SEARCH->>", Unmapped_Key, 0x16, 8);
  addKey("<<-SEARCH", Unmapped_Key, 0x17, 8);
  addKey("|<-SKIP", Previous_Key, 0x18, 8);
  addKey("SKIP->|", Next_Key, 0x19, 8);
  addKey("REPEAT", Repeat_Key, 0x1B, 8);
  addKey("REC_MUTE", RecordMute_Key, 0x1C, 8);

  addKey("0", Zero_Key, 0x20, 8);
  addKey("1", One_Key, 0x21, 8);
  addKey("2", Two_Key, 0x22, 8);
  addKey("3", Three_Key, 0x23, 8);
  addKey("4", Four_Key, 0x24, 8);
  addKey("5", Five_Key, 0x25, 8);
  addKey("6", Six_Key, 0x26, 8);
  addKey("7", Seven_Key, 0x27, 8);
  addKey("8", Eight_Key, 0x28, 8);
  addKey("9", Nine_Key, 0x29, 8);

  addKey("RESERVE", Unmapped_Key, 0x2A, 8);
  addKey("CANCEL/RESET", Reset_Key, 0x2D, 8);
}


JVCCarDeck1::JVCCarDeck1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Car Deck Keyset 1",
      JVC_Make,
      index)
{
  threadableProtocol = new JVCProtocol(guiObject, index);

//  setPreData(0xF1, 8);
  setPreData(0x8F, 8);

  addKey("Vol+", VolumeUp_Key, 0x84, 8);
  addKey("Vol-", VolumeDown_Key, 0x85, 8);
  addKey("Source", Input_Key, 0x88, 8);  // "FUNC", "SRC"
  addKey("Sound", Mute_Key, 0x8D, 8); // "SCM"
  addKey("Power", Power_Key, 0x8E, 8); // "Att"
  addKey("DISC+", ChannelUp_Key, 0x94, 8);
  addKey("DISC-", ChannelDown_Key, 0x95, 8);

  // Can't be sure if either or both of these are true:
  addKey("Track+", Next_Key, 0x92, 8);
  addKey("Track-", Previous_Key, 0x93, 8);
  addKey("FF", FastForward_Key, 0x92, 8);
  addKey("Rew", Rewind_Key, 0x93, 8);
}


// Modern JVC audio devices are using a wide array of addresses, so I'm
// smushing the address and command together.  Once you start mixing adresses
// together, they might as well all be a single command anyway...

JVCAudio1::JVCAudio1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 1",
      JVC_Make,
      index)
{
  threadableProtocol = new JVCProtocol(guiObject, index);

  addKey("SLEEP", Sleep_Key, 0x03A3, 16);
  addKey("POWER", Power_Key, 0x17A3, 16);
  addKey("VOL+", VolumeUp_Key, 0x1EA3, 16);
  addKey("VOL-", VolumeDown_Key, 0x1FA3, 16);
  addKey("MD-AUX", AuxInput_Key, 0x3EA3, 16); // "TAPE-AUX"
  addKey("TAPE", TapeInput_Key, 0x3FA3, 16);
  addKey("FM-MODE", FMMode_Key, 0x5AA3, 16);
  addKey("TUNER-BAND", TunerBand_Key, 0x5BA3, 16);
  addKey("AHB-PRO", Unmapped_Key, 0x75A3, 16);
  addKey("AUTO-PRESET", Unmapped_Key, 0x77A3, 16);

  addKey("STOP", Stop_Key, 0x43B3, 16); // "CD.Stop"
  addKey("CD-EJECT", Eject_Key, 0x44B3, 16);
  addKey("INTRO", Unmapped_Key, 0x48B3, 16);
  addKey("PLAY", Play_Key, 0x4CB3, 16); // "CD.Play"
  addKey("DIMMER", Unmapped_Key, 0x52B3, 16);
  addKey("REW", Rewind_Key, 0x58B3, 16);
  addKey("FF", FastForward_Key, 0x59B3, 16); // "CD.Next"
  addKey("REPEAT", Repeat_Key, 0x5BB3, 16);
  addKey("1", One_Key, 0x61B3, 16);
  addKey("2", Two_Key, 0x62B3, 16);
  addKey("3", Three_Key, 0x63B3, 16);
  addKey("4", Four_Key, 0x64B3, 16);
  addKey("5", Five_Key, 0x65B3, 16);
  addKey("6", Six_Key, 0x66B3, 16);
  addKey("7", Seven_Key, 0x67B3, 16);
  addKey("8", Eight_Key, 0x68B3, 16);
  addKey("9", Nine_Key, 0x69B3, 16);
  addKey("MEMORY/CALL", Program_Key, 0x6AB3, 16); // "PROGRAM"
  addKey("CANCEL", Clear_Key, 0x6DB3, 16);
  addKey("10", Zero_Key, 0x6EB3, 16); // Treating "10" as "0" here
  addKey("+10", DoubleDigit_Key, 0x6FB3, 16);
  addKey("RANDOM", Random_Key, 0x72B3, 16);

  addKey("UP", Up_Key, 0x00AF, 16);
  addKey("DOWN", Down_Key, 0x01AF, 16);
  addKey("RIGHT", Right_Key, 0x02AF, 16);
  addKey("LEFT", Left_Key, 0x03AF, 16);
  addKey("NEXT", Next_Key, 0x05AF, 16);
  addKey("PREV", Previous_Key, 0x06AF, 16);
  addKey("BASS", Unmapped_Key, 0x1EAF, 16);
  addKey("TREBLE", Unmapped_Key, 0x2EAF, 16);
  addKey("DISPLAY-MODE", Info_Key, 0x83AF, 16);
  addKey("PTY-EON", Unmapped_Key, 0x85AF, 16);
  addKey("SET", Select_Key, 0x91AF, 16);

  addKey("EDIT-TITLE", Unmapped_Key, 0x89BF, 16);
  addKey("CHARA", Unmapped_Key, 0xB8BF, 16);
}


JVCAudio1a::JVCAudio1a(
  QObject *guiObject,
  unsigned int index)
  : JVCAudio1(guiObject, index)
{
  setKeysetName("Audio Keyset 1a");

  addKey("CD-PLAY-PAUSE", Play_Key, 0x3DA3, 16);
  addKey("MD-PLAY-PAUSE", Unmapped_Key, 0x30AF, 16);
}


JVCAudio1b::JVCAudio1b(
  QObject *guiObject,
  unsigned int index)
  : JVCAudio1(guiObject, index)
{
  setKeysetName("Audio Keyset 1b");

  addKey("VCR", VCRInput_Key, 0x2443, 16);

  addKey("tape-stop", Unmapped_Key, 0x0383, 16); // "Deck.Stop"
  addKey("FORWARDS", Unmapped_Key, 0x0683, 16); // "Deck.Right"
  addKey("BACKWARDS", Unmapped_Key, 0x0783, 16); // "Deck.Left"
  addKey("PLAY", Unmapped_Key, 0x0C83, 16); // "tape-play"
  addKey("STILL/PAUSE", Unmapped_Key, 0x0D83, 16);
  addKey("STOP", Unmapped_Key, 0x0D83, 16);
  addKey("Deck.PlayLeft", Unmapped_Key, 0x0E83, 16);
  addKey("Deck.PlayRight", Unmapped_Key, 0x0F83, 16);
  addKey("STOP2", Unmapped_Key, 0x4383, 16);
  addKey("REC+PLAY", Record_Key, 0xCC83, 16);
  addKey("Deck.A", Unmapped_Key, 0xD083, 16);
  addKey("Deck.B", Unmapped_Key, 0xD183, 16);
  addKey("RecPause", RecordPause_Key, 0xED83, 16);

  addKey("MONITOR/TAPE2", Unmapped_Key, 0x07A3, 16);
  addKey("TUNER", TunerInput_Key, 0x0BA3, 16);
  addKey("tuner-", ChannelDown_Key, 0x18A3, 16);
  addKey("tuner+", ChannelUp_Key, 0x19A3, 16);
  addKey("FADE_MUTING", Unmapped_Key, 0x1CA3, 16);
  addKey("Tuner 0", Unmapped_Key, 0x20A3, 16);
  addKey("Tuner 1", Unmapped_Key, 0x21A3, 16);
  addKey("Tuner 2", Unmapped_Key, 0x22A3, 16);
  addKey("Tuner 3", Unmapped_Key, 0x23A3, 16);
  addKey("Tuner 4", Unmapped_Key, 0x24A3, 16);
  addKey("Tuner 5", Unmapped_Key, 0x25A3, 16);
  addKey("Tuner 6", Unmapped_Key, 0x26A3, 16);
  addKey("Tuner 7", Unmapped_Key, 0x27A3, 16);
  addKey("Tuner 8", Unmapped_Key, 0x28A3, 16);
  addKey("Tuner 9", Unmapped_Key, 0x29A3, 16);
  addKey("Tuner 10", Unmapped_Key, 0x2AA3, 16);
  addKey("Tuner +10", Unmapped_Key, 0x2FA3, 16);
  addKey("SoundMode", SoundMode_Key, 0x38A3, 16);
  addKey("PHONO", PhonoInput_Key, 0x3CA3, 16);
  addKey("cd-play", Play_Key, 0x3DA3, 16); // "CD"

  addKey("cd-stop", Stop_Key, 0x43B3, 16);
  addKey("cd-pause", Pause_Key, 0x4DB3, 16);
  addKey("cd-prev", Previous_Key, 0x58B3, 16);
  addKey("cd-next", Next_Key, 0x59B3, 16);
  addKey("0", Zero_Key, 0x60B3, 16);
  addKey("cd-back", Rewind_Key, 0x70B3, 16);
  addKey("Disc program", Unmapped_Key, 0x71B3, 16);
  addKey("cd-forw", FastForward_Key, 0x76B3, 16);
  addKey("Disc continue", Unmapped_Key, 0x77B3, 16);
  addKey("Disc 1", Unmapped_Key, 0x79B3, 16);
  addKey("Disc 2", Unmapped_Key, 0x7AB3, 16);
  addKey("Disc 3", Unmapped_Key, 0x7BB3, 16);
  addKey("Disc 4", Unmapped_Key, 0x7CB3, 16);
  addKey("Disc 5", Unmapped_Key, 0x7DB3, 16);
  addKey("Disc 6", Unmapped_Key, 0x7EB3, 16);
}


JVCAudio2::JVCAudio2(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 2",
      JVC_Make,
      index)
{
  threadableProtocol = new JVCProtocol(guiObject, index);

//  setPreData(0xF9, 8);
  setPreData(0x9F, 8);

  addKey("power", Power_Key, 0x00, 8);
  addKey("vol+", VolumeUp_Key, 0x01, 8);
  addKey("vol-", VolumeDown_Key, 0x02, 8);
  addKey("ACTIVE_HYPER_BASS", EnhancedBass_Key, 0x04, 8); // "bass"
  addKey("band", TunerBand_Key, 0x0B, 8);  // "TUNER_BAND"
  addKey("aux", AuxInput_Key, 0x0D, 8);

  addKey("enter", Enter_Key, 0x11, 8);
  addKey("PRESET_SCAN", Scan_Key, 0x12, 8);
  addKey("auto_preset", Unmapped_Key, 0x13, 8);
  addKey("presettuning", Unmapped_Key, 0x15, 8);
  addKey("display-mode", Unmapped_Key, 0x16, 8);
  addKey("pty-eon", Unmapped_Key, 0x17, 8);
  addKey("right-select", Unmapped_Key, 0x18, 8);
  addKey("left-select", Unmapped_Key, 0x19, 8);
  addKey("display", Info_Key, 0x1C, 8); // "CLOCK"
  addKey("auto_mono", FMMode_Key, 0x1F, 8);  // "fmstereo", "mode"

  addKey("1", One_Key, 0x21, 8);
  addKey("2", Two_Key, 0x22, 8);
  addKey("3", Three_Key, 0x23, 8);
  addKey("4", Four_Key, 0x24, 8);
  addKey("5", Five_Key, 0x25, 8);
  addKey("6", Six_Key, 0x26, 8);
  addKey("7", Seven_Key, 0x27, 8);
  addKey("8", Eight_Key, 0x28, 8);
  addKey("9", Nine_Key, 0x29, 8);
  addKey("10", Zero_Key, 0x2A, 8); // treating "10" as "0" here
  addKey("10+", DoubleDigit_Key, 0x2E, 8);

  addKey("TIMER_SET", Timer_Key, 0x30, 8);
  addKey("sleep", Sleep_Key, 0x32, 8);
  addKey("SET", Select_Key, 0x33, 8); // "clock"
  addKey("TIMER_ON_OFF", Unmapped_Key, 0x36, 8); // "onoff"
  addKey("ff", FastForward_Key, 0x3D, 8); // "SEARCH_UP" "search_forward"
  addKey("rew", Rewind_Key, 0x3E, 8);  // "SEARCH_DOWN" "search_back"
  addKey("stop", Unmapped_Key, 0x41, 8); // "TAPESTOP"
  addKey("tape", Unmapped_Key, 0x42, 8);
  addKey("ff", Unmapped_Key, 0x44, 8); // "TAPENEXT"
  addKey("rewind", Unmapped_Key, 0x45, 8); // "TAPEPREV"
  addKey("record", Record_Key, 0x4B, 8); // "TAPEREC"
  addKey("play", Unmapped_Key, 0x4C, 8); // "TAPERIGHT"
  addKey("reverseplay", Unmapped_Key, 0x4D, 8); // "TAPELEFT"
  addKey("synchrorec", Unmapped_Key, 0x56, 8);
  addKey("deckab", Unmapped_Key, 0x58, 8);
  addKey("revmode", Unmapped_Key, 0x5F, 8);

  addKey("play", Play_Key, 0x70, 8); // "CD_PLAY_PAUSE"
  addKey("play", Pause_Key, 0x70, 8); // "CD_PLAY_PAUSE"
  addKey("stop", Stop_Key, 0x71, 8); // "CD_STOP" "stop_clear"
  addKey("stop", Clear_Key, 0x71, 8); // "CD_STOP" "stop_clear"
  addKey("NEXT_TRACK", Next_Key, 0x72, 8);
  addKey("PREV_TRACK", Previous_Key, 0x73, 8);
  addKey("memory", Program_Key, 0x74, 8); // "MEMORY_CALL", "program"
  addKey("edit", Unmapped_Key, 0x75, 8);
  addKey("intro", Unmapped_Key, 0x76, 8);
  addKey("random", Random_Key, 0x77, 8);
  addKey("repeat", Repeat_Key, 0x78, 8);
  addKey("open_close", Eject_Key, 0x7B, 8); // "allcdeject"
  addKey("continue", Unmapped_Key, 0x7D, 8);
  addKey("call", Call_Key, 0x7F, 8);
  addKey("FREQUENCY", Unmapped_Key, 0x80, 8);
  addKey("tone", Unmapped_Key, 0x86, 8);
  addKey("bass+", BassUp_Key, 0x87, 8);
  addKey("bass-", BassDown_Key, 0x88, 8);
  addKey("treble+", TrebleUp_Key, 0x89, 8);
  addKey("treble-", TrebleDown_Key, 0x8A, 8);
  addKey("sound", Unmapped_Key, 0x8F, 8);
  addKey("beat-cut", Unmapped_Key, 0xEE, 8);
  addKey("playcd1", Unmapped_Key, 0xF1, 8);
  addKey("playcd2", Unmapped_Key, 0xF2, 8);
  addKey("playcd3", Unmapped_Key, 0xF3, 8);
  addKey("ejectcd1", Unmapped_Key, 0xF4, 8);
  addKey("ejectcd2", Unmapped_Key, 0xF5, 8);
  addKey("ejectcd2", Unmapped_Key, 0xF6, 8);
}


JVCDVD1::JVCDVD1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      JVC_Make,
      index)
{
  threadableProtocol = new JVCProtocol(guiObject, index);

//  setPreData(0xF7, 8);
  setPreData(0xEF, 8);

  addKey("power", Power_Key, 0x40, 8);
  addKey("stop", Stop_Key, 0x43, 8);
  addKey("openclose", Eject_Key, 0x44, 8);
  addKey("SWOOP", Unmapped_Key, 0x49, 8);
  addKey("play", Play_Key, 0x4C, 8);
  addKey("pause", Pause_Key, 0x4D, 8);
  addKey("DIMMER", Unmapped_Key, 0x51, 8);
  addKey("repeat", Repeat_Key, 0x5B, 8);

  addKey("0", Zero_Key, 0x60, 8);
  addKey("1", One_Key, 0x61, 8);
  addKey("2", Two_Key, 0x62, 8);
  addKey("3", Three_Key, 0x63, 8);
  addKey("4", Four_Key, 0x64, 8);
  addKey("5", Five_Key, 0x65, 8);
  addKey("6", Six_Key, 0x66, 8);
  addKey("7", Seven_Key, 0x67, 8);
  addKey("8", Eight_Key, 0x68, 8);
  addKey("9", Nine_Key, 0x69, 8);
  addKey("cancel", Clear_Key, 0x6D, 8);
  addKey("10", Unmapped_Key, 0x6E, 8);
  addKey("+10", DoubleDigit_Key, 0x6F, 8);

  addKey("back", Rewind_Key, 0x70, 8); // "SLOW_MINUS"
  addKey("forw", FastForward_Key, 0x76, 8); // "SLOW_PLUS"
  addKey("choice", Unmapped_Key, 0x7F, 8);
  addKey("playmode", Unmapped_Key, 0x83, 8);

  addKey("zoom+", Unmapped_Key, 0xAE, 8);
  addKey("zoom-", Unmapped_Key, 0xAF, 8);
  addKey("skip_forw", Next_Key, 0xB0, 8); // "next"
  addKey("skip_back", Previous_Key, 0xB1, 8); // "previous"
  addKey("display", Info_Key, 0xB5, 8);
  addKey("digest", Unmapped_Key, 0xB9, 8);
  addKey("zoom", Zoom_Key, 0xBC, 8);
  addKey("3dphonix", Unmapped_Key, 0xBD, 8);
  addKey("vfp", Unmapped_Key, 0xBE, 8); // "theaterposition"

  addKey("onscreen", Unmapped_Key, 0xC0, 8);
  addKey("menu", Menu_Key, 0xC1, 8);
  addKey("topmenu", DiscTitle_Key, 0xC2, 8);
  addKey("audio", Audio_Key, 0xC8, 8);
  addKey("angle", Angle_Key, 0xCB, 8);
  addKey("subtitle", Captions_Key, 0xCD, 8);

  addKey("up", Up_Key, 0xD0, 8);
  addKey("down", Down_Key, 0xD1, 8);
  addKey("left", Left_Key, 0xD2, 8);
  addKey("right", Right_Key, 0xD3, 8);
  addKey("enter", Select_Key, 0xD4, 8);
  addKey("return", Exit_Key, 0xD5, 8);
  addKey("title/group", Unmapped_Key, 0xEE, 8);

//  addKey("voldown", VolumeDown_Key, 0xC5F8, 16);
//  addKey("volup", VolumeUp_Key, 0xC578, 16);
}
