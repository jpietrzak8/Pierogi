#include "panasonic.h"
#include "necprotocol.h"

PanasonicAmp::PanasonicAmp(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Amp Keyset",
      Panasonic_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    400, 400,
    400, 1200,
    76000, false);

  threadableProtocol = np;

  np->setHeaderPair(4000, 1600);
  np->setTrailerPulse(400);

  np->setPreData(0x80080A86, 32);

//  np->setMinimumRepetitions(4);

  np->setCarrierFrequency(36000);

  addKey("POWER", Power_Key, 0xFDBB, 16);
  addKey("VOL+", VolumeUp_Key, 0x0D4B, 16);
  addKey("VOL-", VolumeDown_Key, 0x4DCB, 16);
  addKey("SLEEP", Sleep_Key, 0x3D7B, 16);
  addKey("DISPLAY", Info_Key, 0xF17B, 16);
}


PanasonicCarAudio::PanasonicCarAudio(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Car Audio Keyset",
      Panasonic_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    665, 465,
    665, 1595,
    108609, true);

  threadableProtocol = np;

  np->setHeaderPair(9148, 4424);
  np->setTrailerPulse(667);

  np->setPreData(0x8156, 16);

  addKey("Power", Power_Key, 0x48B7, 16);
  addKey("PRG", Unmapped_Key, 0x38C7, 16);
  addKey("Mode", Unmapped_Key, 0x58A7, 16);
  addKey("ATT", Unmapped_Key, 0x28D7, 16);
  addKey("Vol_Up", VolumeUp_Key, 0xB847, 16);
  addKey("Vol_Down", VolumeDown_Key, 0x9867, 16);
  addKey("Tune/Track_Up", ChannelUp_Key, 0xF807, 16);
  addKey("Tune/Track_Down", ChannelDown_Key, 0x7887, 16);
}


PanasonicSat1::PanasonicSat1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Satellite Keyset 1",
      Panasonic_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    500, 400,
    500, 1212,
    74500, false);

  threadableProtocol = np;

  np->setHeaderPair(3565, 1700);
  np->setTrailerPulse(500);

  np->setPreData(0x40040140, 32);

  addKey("POWER", Power_Key, 0xBDFC, 16);
  addKey("CH+", ChannelUp_Key, 0xEDAC, 16);
//  addKey("CH+", ChannelUp_Key, 0x2D6C, 16);
  addKey("CH-", ChannelDown_Key, 0x6D2C, 16);
//  addKey("CH-", ChannelDown_Key, 0xADEC, 16);
  addKey("R_TUNE", Unmapped_Key, 0x8BCA, 16);
  addKey("GUIDE", Guide_Key, 0xA3E2, 16);
  addKey("MENU", Menu_Key, 0x2362, 16);
  addKey("EXIT", Exit_Key, 0x6322, 16);
  addKey("LEFT", Left_Key, 0xB3F2, 16);
  addKey("RIGHT", Right_Key, 0x7332, 16);
  addKey("UP", Up_Key, 0x5312, 16);
  addKey("DOWN", Down_Key, 0xD392, 16);
  addKey("FAV", Unmapped_Key, 0x0B4A, 16);
  addKey("INFO", Info_Key, 0x9DDC, 16);
  addKey("1", One_Key, 0x0544, 16);
  addKey("2", Two_Key, 0x85C4, 16);
  addKey("3", Three_Key, 0x4504, 16);
  addKey("4", Four_Key, 0xC584, 16);
  addKey("5", Five_Key, 0x2564, 16);
  addKey("6", Six_Key, 0xA5E4, 16);
  addKey("7", Seven_Key, 0x6524, 16);
  addKey("8", Eight_Key, 0xE5A4, 16);
  addKey("9", Nine_Key, 0x1554, 16);
  addKey("0", Zero_Key, 0x95D4, 16);
  addKey("LOGO_TUNE", Unmapped_Key, 0xABEA, 16);
  addKey("ALT_AUD", Unmapped_Key, 0x1D5C, 16);
  addKey("TV/DSS", Input_Key, 0x3D7C, 16);
  addKey("REC", Record_Key, 0x4302, 16);
  addKey("ACTION", Select_Key, 0xC382, 16);
  addKey("PROG", Unmapped_Key, 0x5110, 16);
  addKey("TXT", Unmapped_Key, 0x7B3A, 16);
  addKey("STTL", Unmapped_Key, 0xFBBA, 16);
  addKey("GUIDE", Guide_Key, 0xCB8A, 16);
//  addKey("EXIT", Unmapped_Key, 0xF3B2, 16);
  addKey("RED", Red_Key, 0x3776, 16);
  addKey("GREEN", Green_Key, 0xB7F6, 16);
  addKey("YELLOW", Yellow_Key, 0xF7B6, 16);
  addKey("BLUE", Blue_Key, 0x7736, 16);
}


PanasonicSat1a::PanasonicSat1a(
  QObject *guiObject,
  unsigned int index)
  : PanasonicSat1(guiObject, index)
{
  setKeysetName("Satellite Keyset 1a");
  addKey("EXIT", Exit_Key, 0xF3B2, 16);
  addKey("CH+", ChannelUp_Key, 0x4D0C, 16);
  addKey("CH-", ChannelDown_Key, 0xCD8C, 16);
}


PanasonicTV1::PanasonicTV1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Panasonic_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    500, 400,
    500, 1250,
    75000, false);

  threadableProtocol = np;

  np->setHeaderPair(3500, 1700);
  np->setTrailerPulse(500);

  np->setPreData(0x400401, 24);

//  np->setMinRepeat(1);

  addKey("POWER", Power_Key, 0x00BCBD, 24);
  addKey("MUTE", Mute_Key, 0x004C4D, 24);
  addKey("PICTURE", Unmapped_Key, 0x006061, 24);
  addKey("SOUND", Unmapped_Key, 0x00E0E1, 24);
  addKey("ACTION", Enter_Key, 0x004A4B, 24);
  addKey("ACTION", Select_Key, 0x004A4B, 24);
  addKey("UP", Up_Key, 0x005253, 24);
  addKey("DOWN", Down_Key, 0x00D2D3, 24);
  addKey("RIGHT", Right_Key, 0x00F2F3, 24);
  addKey("LEFT", Left_Key, 0x007273, 24);
  addKey("PROG_UP", ChannelUp_Key, 0x002C2D, 24);
  addKey("PROG_DOWN", ChannelDown_Key, 0x00ACAD, 24);
  addKey("VOLUME_UP", VolumeUp_Key, 0x000405, 24);
  addKey("VOLUME_DOWN", VolumeDown_Key, 0x008485, 24);
  addKey("RECALL", PrevChannel_Key, 0x009C9D, 24);
  addKey("TV/AV", Input_Key, 0x00A0A1, 24);
  addKey("RED", Red_Key, 0x000E0F, 24);
  addKey("GREEN", Green_Key, 0x008E8F, 24);
  addKey("YELLOW", Yellow_Key, 0x004E4F, 24);
  addKey("BLUE", Blue_Key, 0x00CECF, 24);
  addKey("1", One_Key, 0x000809, 24);
  addKey("2", Two_Key, 0x008889, 24);
  addKey("3", Three_Key, 0x004849, 24);
  addKey("4", Four_Key, 0x00C8C9, 24);
  addKey("5", Five_Key, 0x002829, 24);
  addKey("6", Six_Key, 0x00A8A9, 24);
  addKey("7", Seven_Key, 0x006869, 24);
  addKey("8", Eight_Key, 0x00E8E9, 24);
  addKey("9", Nine_Key, 0x001819, 24);
  addKey("0", Zero_Key, 0x009899, 24);
  addKey("C", Clear_Key, 0x005C5D, 24);
  addKey("-/--", DoubleDigit_Key, 0x00DCDD, 24); // Might also be Dash_Key
  addKey("SURROUND", Surround_Key, 0x008C8D, 24);
  addKey("MULTIWINDOW", Unmapped_Key, 0x006766, 24);
  addKey("N", Unmapped_Key, 0x003031, 24);
  addKey("STR", Unmapped_Key, 0x00ABAA, 24);
  addKey("TIMER", Unmapped_Key, 0x00F0F1, 24);
  addKey("HELP", Unmapped_Key, 0x003534, 24);
  addKey("R-TUNE", Unmapped_Key, 0x00ECED, 24);
  addKey("GAME", Unmapped_Key, 0x00DDDC, 24);
  addKey("S", Unmapped_Key, 0x007071, 24);
  addKey("S_MENU", Unmapped_Key, 0x008A8B, 24);
  addKey("P_MENU", Unmapped_Key, 0x000A0B, 24);
  addKey("SAP", Unmapped_Key, 0x00CCCD, 24);
  addKey("FM/TV", Unmapped_Key, 0x007776, 24);
  addKey("Exit", Unmapped_Key, 0x00CBCA, 24);
  addKey("Return", Unmapped_Key, 0x002B2A, 24);
  addKey("MOOD_LIGHT", Unmapped_Key, 0x008584, 24);

  addKey("ASPECT", Unmapped_Key, 0x207B5A, 24);

  addKey("PROG", Unmapped_Key, 0x405110, 24);
  addKey("MENU", Unmapped_Key, 0x402362, 24);
  addKey("EXIT", Exit_Key, 0x406322, 24);
  addKey("GUIDE", Guide_Key, 0x40A3E2, 24);
  addKey("TV", Unmapped_Key, 0x400C4D, 24);

  addKey("TV/TEXT", Unmapped_Key, 0x80C041, 24);
  addKey("FP", Unmapped_Key, 0x80A021, 24);
  addKey("INDEX", Unmapped_Key, 0x801091, 24);
  addKey("HOLD", Unmapped_Key, 0x809011, 24);
  addKey("TIMETEXT", Unmapped_Key, 0x80D051, 24);
  addKey("REVEAL", Unmapped_Key, 0x8038B9, 24);
  addKey("FTB", Unmapped_Key, 0x8030B1, 24);
  addKey("Display_Cancel", Unmapped_Key, 0x8020A1, 24);
  addKey("List/F.Text", Unmapped_Key, 0x80B839, 24);

  addKey("DIRECTREC", Record_Key, 0x909100, 24);
  addKey("Link", Unmapped_Key, 0x908D1C, 24);
  addKey("Option", Unmapped_Key, 0x90E574, 24);
  addKey("SDCard", Unmapped_Key, 0x90D544, 24);
  addKey("Guide", Unmapped_Key, 0x90E170, 24);
  addKey("prog-", Unmapped_Key, 0x900B9A, 24);
}


PanasonicTV1a::PanasonicTV1a(
  QObject *guiObject,
  unsigned int index)
  : PanasonicTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1a");
  // Overwrite some of the keys:
  addKey("OK", Select_Key, 0x009293, 24);
  addKey("MENU", Menu_Key, 0x006061, 24);
}


PanasonicTV1b::PanasonicTV1b(
  QObject *guiObject,
  unsigned int index)
  : PanasonicTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1b");

  addControlledDevice(Panasonic_Make, "Viera TX-32LZD80", TV_Device);
  addControlledDevice(Panasonic_Make, "Viera 42PZ700U", TV_Device);

  addKey("Menu", Menu_Key, 0x004A4B, 24);
  addKey("OK", Select_Key, 0x009293, 24);
  addKey("Guide", Guide_Key, 0x90E170, 24);
//  addKey("Exit", Exit_Key, 0x00CBCA, 24);
  addKey("Info", Info_Key, 0x009C9D, 24);
  addKey("Exit", Exit_Key, 0x9059C8, 24);
}


PanasonicVCR1::PanasonicVCR1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      Panasonic_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    550, 330,
    550, 1200,
    75000, false);

  threadableProtocol = np;

  np->setHeaderPair(3600, 1650);
  np->setTrailerPulse(550);

  np->setPreData(0x400409, 24);

  addKey("POWER", Power_Key, 0x00BCB5, 24);
  addKey("PROGRAMME^", ChannelUp_Key, 0x002C25, 24);
  addKey("PROGRAMMEv", ChannelDown_Key, 0x00ACA5, 24);
  addKey("REC", Record_Key, 0x001019, 24);
  addKey("PAUSE", Pause_Key, 0x006069, 24);
  addKey("PLAY", Play_Key, 0x005059, 24);
  addKey("STOP", Stop_Key, 0x000009, 24);
  addKey("FORWARD", FastForward_Key, 0x00C0C9, 24);
  addKey("REWIND", Rewind_Key, 0x004049, 24);
  addKey("INFO", Info_Key, 0x009C95, 24);
  addKey("1", One_Key, 0x000801, 24);
  addKey("2", Two_Key, 0x008881, 24);
  addKey("3", Three_Key, 0x004841, 24);
  addKey("4", Four_Key, 0x00C8C1, 24);
  addKey("5", Five_Key, 0x002821, 24);
  addKey("6", Six_Key, 0x00A8A1, 24);
  addKey("7", Seven_Key, 0x006861, 24);
  addKey("8", Eight_Key, 0x00E8E1, 24);
  addKey("9", Nine_Key, 0x001811, 24);
  addKey("0", Zero_Key, 0x009891, 24);
  addKey("100", PlusOneHundred_Key, 0x00A7AE, 24);
  addKey("TV-SAT", Input_Key, 0x006C65, 24);
  addKey("TRACKING_MINUS", Unmapped_Key, 0x004D44, 24);
  addKey("TRACKING_PLUS", Unmapped_Key, 0x008D84, 24);
  addKey("TRACKING_AUTO", Unmapped_Key, 0x000D04, 24);
  addKey("STILL", StepForward_Key, 0x003039, 24);  // also "ADV"
  addKey("INDEXL", Unmapped_Key, 0x00929B, 24);
  addKey("INDEXR", Unmapped_Key, 0x00525B, 24);
  addKey("AV", Unmapped_Key, 0x00030A, 24);
  addKey("-/--", DoubleDigit_Key, 0x00DCD5, 24);
  addKey("REPLAY", Replay_Key, 0x00EFE6, 24);
  addKey("DIRECT_TV_REC", Unmapped_Key, 0x00434A, 24);
  addKey("TIMERREC", Timer_Key, 0x002D24, 24);
  addKey("COUNTER_RESET", Unmapped_Key, 0x002A23, 24);
  addKey("AUDIO", Unmapped_Key, 0x00CCC5, 24);
  addKey("SLOW", Unmapped_Key, 0x00F0F9, 24);
  addKey("INDEX", Unmapped_Key, 0x00020B, 24);
  addKey("+", Unmapped_Key, 0x007178, 24);
  addKey("-", Unmapped_Key, 0x00F1F8, 24);
  addKey("mem_rep", Unmapped_Key, 0x00CAC3, 24);
  addKey("time_search", Unmapped_Key, 0x00222B, 24);
  addKey("monitor", Unmapped_Key, 0x008980, 24);
  addKey("repeat", Unmapped_Key, 0x000F06, 24);
  addKey("memory", Unmapped_Key, 0x008F86, 24);
  addKey("sleep", Sleep_Key, 0x004F46, 24);
  addKey("rew2", Unmapped_Key, 0x00CFC6, 24);
  addKey("cm-zero", Unmapped_Key, 0x001F16, 24);
  addKey("CLOCK/COUNTER", Unmapped_Key, 0x006A63, 24);
  addKey("TAPE_REMAIN", Unmapped_Key, 0x00AAA3, 24);
  addKey("mesecam", Unmapped_Key, 0x00939A, 24);
  addKey("zerostop", Unmapped_Key, 0x00AFA6, 24);
  addKey("sap/hi-fi", Unmapped_Key, 0x00676E, 24);

  addKey("DISPLAY", Unmapped_Key, 0x80FA73, 24);
  addKey("SEARCH", Unmapped_Key, 0x80B930, 24);
  addKey("SPEED", VHSSpeed_Key, 0x8050D9, 24);
  addKey("SHOWVIEW", Unmapped_Key, 0x80BA33, 24);
  addKey("MENU", Menu_Key, 0x806AE3, 24);
  addKey("OK", Select_Key, 0x801A93, 24);
  addKey("EXIT", Exit_Key, 0x8066EF, 24);
  addKey("CHECK+", Unmapped_Key, 0x800980, 24);
  addKey("CHECK-", Unmapped_Key, 0x808900, 24);
  addKey("DATE+", Unmapped_Key, 0x8049C0, 24);
  addKey("DATE-", Unmapped_Key, 0x80C940, 24);
  addKey("ON+", Unmapped_Key, 0x8029A0, 24);
  addKey("ON-", Unmapped_Key, 0x80A920, 24);
  addKey("OFF+", Unmapped_Key, 0x8069E0, 24);
  addKey("OFF-", Unmapped_Key, 0x80E960, 24);
  addKey("PROG/CHECK", Program_Key, 0x808009, 24);
  addKey("CANCEL", Clear_Key, 0x809019, 24);
  addKey("TAPE", Unmapped_Key, 0x80078E, 24);
  addKey("ADD/DELETE", Unmapped_Key, 0x808C05, 24);
  addKey("RADIO_TUNE", Unmapped_Key, 0x801C95, 24);
  addKey("VPS/PDC", Unmapped_Key, 0x8060E9, 24);
  addKey("OffTimer", Unmapped_Key, 0x801099, 24);
  addKey("rotate", Unmapped_Key, 0x8040C9, 24);
  addKey("rotatedown", Unmapped_Key, 0x80C049, 24);
  addKey("set", Unmapped_Key, 0x8020A9, 24);
  addKey("clear", Unmapped_Key, 0x80A029, 24);

  addKey("TV/TEXT", Unmapped_Key, 0xA0EA43, 24);
  addKey("STILL_ALBUM", Unmapped_Key, 0xA0C46D, 24);
  addKey("ExtLink", Unmapped_Key, 0xA0DA73, 24);
  addKey("I-Timer", Unmapped_Key, 0xA0FC55, 24);
  addKey("PROG_PLAY", Unmapped_Key, 0xA05CF5, 24);

// These are fishy:
//  addKey("RESET_STORE", Unmapped_Key, 0x801A93, 24);
}


PanasonicVCR1a::PanasonicVCR1a(
  QObject *guiObject,
  unsigned int index)
  : PanasonicVCR1(guiObject, index)
{
  setKeysetName("VCR Keyset 1a");

  addKey("DISPLAY", Info_Key, 0x80FA73, 24);
  addKey("AV", Input_Key, 0x00030A, 24);
  addKey("OSD", Info_Key, 0x00EAE3, 24);
}


PanasonicVCR1b::PanasonicVCR1b(
  QObject *guiObject,
  unsigned int index)
  : PanasonicVCR1(guiObject, index)
{
  setKeysetName("VCR Keyset 1b");

  addKey("clear", Clear_Key, 0x8050D9, 24);
  addKey("prog", Program_Key, 0x00FFF6, 24);
  addKey("repeat", Unmapped_Key, 0x009F96, 24);
}


PanasonicVCR1c::PanasonicVCR1c(
  QObject *guiObject,
  unsigned int index)
  : PanasonicVCR1(guiObject, index)
{
  setKeysetName("VCR Keyset 1c");

  addKey("rotate", Up_Key, 0x8040C9, 24);
  addKey("rotatedown", Down_Key, 0x80C049, 24);
  addKey("set", Select_Key, 0x8020A9, 24);
  addKey("clear", Exit_Key, 0x80A029, 24);
}


PanasonicDVD1::PanasonicDVD1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Panasonic_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    500, 400,
    500, 1200,
    75000, false);

  threadableProtocol = np;

  np->setHeaderPair(3500, 1650);
  np->setTrailerPulse(500);

  np->setPreData(0x40040D00, 32);

  addKey("POWER", Power_Key, 0xBCB1, 16);
  addKey("PLAY", Play_Key, 0x505D, 16);
  addKey("REW", Rewind_Key, 0x202D, 16);
  addKey("FF", FastForward_Key, 0xA0AD, 16);
  addKey("STOP", Stop_Key, 0x000D, 16);
  addKey("PAUSE", Pause_Key, 0x606D, 16);
  addKey("PREV", Previous_Key, 0x929F, 16);
  addKey("NEXT", Next_Key, 0x525F, 16);
  addKey("UP", Up_Key, 0xA1AC, 16);
  addKey("LEFT", Left_Key, 0xE1EC, 16);
  addKey("RIGHT", Right_Key, 0x111C, 16);
  addKey("DOWN", Down_Key, 0x616C, 16);
  addKey("ACTION", Select_Key, 0x414C, 16);
  addKey("RETURN", Exit_Key, 0x818C, 16);
  addKey("MENU", Menu_Key, 0x010C, 16);
  addKey("INFO", Info_Key, 0x4944, 16);
  addKey("1", One_Key, 0x0805, 16);
  addKey("2", Two_Key, 0x8885, 16);
  addKey("3", Three_Key, 0x4845, 16);
  addKey("4", Four_Key, 0xC8C5, 16);
  addKey("5", Five_Key, 0x2825, 16);
  addKey("6", Six_Key, 0xA8A5, 16);
  addKey("7", Seven_Key, 0x6865, 16);
  addKey("8", Eight_Key, 0xE8E5, 16);
  addKey("9", Nine_Key, 0x1815, 16);
  addKey("0", Zero_Key, 0x9895, 16);
  addKey("CANCEL", Clear_Key, 0xC1CC, 16);
  addKey("+10", DoubleDigit_Key, 0x919C, 16);
  addKey("inputselect", Input_Key, 0x919C, 16);
//  addKey("R-TUNE", Unmapped_Key, 0xD9D4, 16);
  addKey("TOP_MENU", Unmapped_Key, 0xD9D4, 16);
  addKey("OPEN/CLOSE", Eject_Key, 0x808D, 16);
//  addKey("TV-SAT", Input_Key, 0x808D, 16);
  addKey("CH_DOWN", ChannelDown_Key, 0xE0ED, 16);
  addKey("CH_UP", ChannelUp_Key, 0xF0FD, 16);
  addKey("SLEEP", Sleep_Key, 0xD7DA, 16);
  addKey("SUBTITLE", Captions_Key, 0x8984, 16);
  addKey("AUDIO", Unmapped_Key, 0xCCC1, 16);
  addKey("ANGLE", Unmapped_Key, 0x0904, 16);
  addKey("QUICK_REPLAY", Replay_Key, 0xD1DC, 16);
  addKey("PROGRAM", Program_Key, 0x515C, 16);
  addKey("RANDOM", Unmapped_Key, 0xB2BF, 16);
  addKey("REPEAT", Unmapped_Key, 0x313C, 16);
  addKey("A-B_REPEAT", Unmapped_Key, 0x121F, 16);
  addKey("A.SRD", Unmapped_Key, 0x7974, 16);
  addKey("BASS", Unmapped_Key, 0x2B26, 16);
  addKey("CINEMA", Unmapped_Key, 0x030E, 16);
  addKey("D.ENH", Unmapped_Key, 0xABA6, 16);
  addKey("ZOOM", Unmapped_Key, 0x838E, 16);
  addKey("POSITION_MEMORY", Unmapped_Key, 0x626F, 16);
  addKey("ONETOUCH_MEMORY", Unmapped_Key, 0x6B66, 16);
  addKey("GROUP", Unmapped_Key, 0x070A, 16);
  addKey("PLAY_MODE", Unmapped_Key, 0xB1BC, 16);
  addKey("SETUP", Unmapped_Key, 0x2924, 16);
  addKey("CINEMA", Unmapped_Key, 0x030E, 16);
  addKey("VOLUMEUP", VolumeUp_Key, 0xC6CB, 16);
  addKey("VOLUMEDOWN", VolumeDown_Key, 0x262B, 16);
  addKey("showview", Unmapped_Key, 0xFEF3, 16);
  addKey("manualskip", Unmapped_Key, 0x323F, 16);
  addKey("functions", Unmapped_Key, 0xEAE7, 16);
  addKey("progcheck", Unmapped_Key, 0x3E33, 16);
  addKey("status", Unmapped_Key, 0xFAF7, 16);
  addKey("timeslip", Unmapped_Key, 0xD2DF, 16);
  addKey("rec", Record_Key, 0x101D, 16);
  addKey("recmode", Unmapped_Key, 0x8A87, 16);
  addKey("extlink", Unmapped_Key, 0xC4C9, 16);
  addKey("timer", Unmapped_Key, 0x1E13, 16);
  addKey("createchapter", Unmapped_Key, 0x1A17, 16);
  addKey("erase", Unmapped_Key, 0x222F, 16);
  addKey("frec", Unmapped_Key, 0xE3EE, 16);
  addKey("DISC", Unmapped_Key, 0xEDE0, 16);
  addKey("SEQUENTIAL", Unmapped_Key, 0xFDF0, 16);
  addKey("FL_SELECT", Unmapped_Key, 0x6D60, 16);
  addKey("i", Unmapped_Key, 0x666B, 16);
//  addKey("EXIT", Unmapped_Key, 0x808A07, 24);
//  addKey("RED", Unmapped_Key, 0x80820F, 24);
//  addKey("GREEN", Unmapped_Key, 0x8042CF, 24);
}


PanasonicDVD1a::PanasonicDVD1a(
  QObject *guiObject,
  unsigned int index)
  : PanasonicDVD1(guiObject, index)
{
  setKeysetName("DVD Keyset 1a");

  addKey("channel2up", ChannelUp_Key, 0x2C21, 16);
  addKey("channel2down", ChannelDown_Key, 0xACA1, 16);
  addKey("DELETE", Clear_Key, 0x222F, 16);
  addKey("INPUT_SELECT", Input_Key, 0x0A07, 16);
}


PanasonicAudio1::PanasonicAudio1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 1",
      Panasonic_Make,
      index)
{
  addControlledDevice(Panasonic_Make, "RX-DS25", Audio_Device);
  addControlledDevice(Panasonic_Make, "RX-e300", Audio_Device);

  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    400, 400,
    400, 1200,
    76000, false);

  threadableProtocol = np;

  np->setHeaderPair(4000, 1600);
  np->setTrailerPulse(400);

  np->setPreData(0x40040543, 32);

//  np->setMinimumRepetitions(1);

  addKey("power", Power_Key, 0xFDBB, 16);
  addKey("tape", Unmapped_Key, 0x3573, 16);
  addKey("1", One_Key, 0x094F, 16);
  addKey("2", Two_Key, 0x89CF, 16);
  addKey("3", Three_Key, 0x490F, 16);
  addKey("4", Four_Key, 0xC98F, 16);
  addKey("5", Five_Key, 0x296F, 16);
  addKey("6", Six_Key, 0xA9EF, 16);
  addKey("7", Seven_Key, 0x692F, 16);
  addKey("8", Eight_Key, 0xE9AF, 16);
  addKey("9", Nine_Key, 0x195F, 16);
  addKey("+10", DoubleDigit_Key, 0xF9BF, 16);
  addKey("10/0", Zero_Key, 0x99DF, 16);
  addKey("cancel", Clear_Key, 0xB1F7, 16);
  addKey("program", Program_Key, 0xD197, 16); // "MEMORY"
  addKey("tuner-band", Unmapped_Key, 0x1D5B, 16);
  addKey("tuning-", Unmapped_Key, 0x5711, 16);
  addKey("tuning+", Unmapped_Key, 0x97D1, 16);
  addKey("TUNER_PRESET_TUNE_DOWN", ChannelDown_Key, 0x1751, 16);
  addKey("TUNER_PRESET_TUNE_UP", ChannelUp_Key, 0xE7A1, 16);
  addKey("fm-mode", Unmapped_Key, 0x2761, 16); // "st-mono"
  addKey("cd", Unmapped_Key, 0x6D2B, 16);
  addKey("prev", Previous_Key, 0x2167, 16);
  addKey("next", Next_Key, 0xA1E7, 16);
  addKey("stop-clear", Stop_Key, 0x0147, 16);
  addKey("play-pause", Play_Key, 0xE1A7, 16);
  addKey("play-pause", Pause_Key, 0xE1A7, 16);
  addKey("repeat", Unmapped_Key, 0x81C7, 16);
  addKey("xbs", Unmapped_Key, 0x6B2D, 16);
  addKey("vol-", VolumeDown_Key, 0x8DCB, 16);
  addKey("vol+", VolumeUp_Key, 0x0D4B, 16);
  addKey("sleep", Sleep_Key, 0x3D7B, 16);
  addKey("display", Info_Key, 0xF1B7, 16);
  addKey("preset_eq", Unmapped_Key, 0x9BDD, 16);
  addKey("bp", Unmapped_Key, 0xF7B1, 16); // "TUNER_BP"
  addKey("tape_record", Record_Key, 0x2563, 16);
  addKey("counter_reset", Reset_Key, 0xF5B3, 16);
  addKey("rev_mode", Unmapped_Key, 0x7533, 16); // "TAPE_REV_MODE"
  addKey("rew", Rewind_Key, 0x4503, 16);
  addKey("ff", FastForward_Key, 0xC583, 16);
  addKey("tape_play", Unmapped_Key, 0x6523, 16);
  addKey("tape_stop", Unmapped_Key, 0x0543, 16);
  addKey("random", Unmapped_Key, 0x4107, 16);
  addKey("TAPE_DECK", Unmapped_Key, 0xB5F3, 16);
  addKey("TAPE_PLAY_REWIND", Unmapped_Key, 0xA5E3, 16);
  addKey("TAPE_PLAY_FORWARD", Unmapped_Key, 0x6523, 16);
  addKey("panelclose", Unmapped_Key, 0xAFE9, 16); // "TOP_PANEL_CLOSE"
  addKey("panelopen", Unmapped_Key, 0x2F69, 16);  // "TOP_PANEL_OPEN"
  addKey("virtualizer", Unmapped_Key, 0x5B1D, 16); // "S.VIRT"
  addKey("AUTOSCAN", Unmapped_Key, 0x3771, 16);
  addKey("TRACK<<", Unmapped_Key, 0x8BCD, 16);
  addKey("TRACK>>", Unmapped_Key, 0x0B4D, 16);
  addKey("INTRO", Unmapped_Key, 0x6224, 16);
}


PanasonicAudio1a::PanasonicAudio1a(
  QObject *guiObject,
  unsigned int index)
  : PanasonicAudio1(guiObject, index)
{
  setKeysetName("Audio Keyset 1a");

  addControlledDevice(Panasonic_Make, "RX-DT55", Audio_Device);
  addControlledDevice(Panasonic_Make, "RX-DT505", Audio_Device);

  addKey("CD_PAUSE", Pause_Key, 0x6127, 16);
  addKey("CD_<<", Rewind_Key, 0x2167, 16);
  addKey("CD_>>", FastForward_Key, 0xA1E7, 16);
  addKey("TAPE_<<", Unmapped_Key, 0x4503, 16);
  addKey("TAPE_>>", Unmapped_Key, 0xC583, 16);
  addKey("eject", Eject_Key, 0x7137, 16);
}
