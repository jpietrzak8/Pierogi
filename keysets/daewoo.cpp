#include "daewoo.h"
#include "protocols/rc5protocol.h"
#include "protocols/daewooprotocol.h"
#include "protocols/necprotocol.h"

DaewooTV1::DaewooTV1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Daewoo_Make,
      index)
{
  addControlledDevice(Daewoo_Make, "21T5T", TV_Device);

  threadableProtocol = new RC5Protocol(guiObject, index);

  addKey("MENU", Menu_Key, 0x0012, 13);
  addKey("OK", Select_Key, 0x0017, 13); // "enter"

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
  addKey("POWER", Power_Key, 0x100C, 13);
  addKey("MUTE", Mute_Key, 0x100D, 13);
  addKey("normal", Unmapped_Key, 0x100E, 13);
  addKey("RECALL", PrevChannel_Key, 0x100F, 13);

  addKey("VOL+", VolumeUp_Key, 0x1010, 13); // "Right"
  addKey("VOL+", Right_Key, 0x1010, 13); // "Right"
  addKey("VOL-", VolumeDown_Key, 0x1011, 13); // "Left"
  addKey("VOL-", Left_Key, 0x1011, 13); // "Left"

  addKey("PR+", ChannelUp_Key, 0x1020, 13); // "Up"
  addKey("PR+", Up_Key, 0x1020, 13); // "Up"
  addKey("PR-", ChannelDown_Key, 0x1021, 13); // "Down"
  addKey("PR-", Down_Key, 0x1021, 13); // "Down"
  addKey("system", Guide_Key, 0x1022, 13); // Not quite a guide
  addKey("i-ii", Audio_Key, 0x1023, 13);
  addKey("two_semicircles", Unmapped_Key, 0x1024, 13);
  addKey("SLEEP", Sleep_Key, 0x1026, 13);
  addKey("time", Unmapped_Key, 0x102A, 13);
  addKey("SKIP", Unmapped_Key, 0x102D, 13); // woofer

  addKey("yellow", Yellow_Key, 0x1032, 13); // "TIME"
  addKey("blue", Blue_Key, 0x1034, 13); // "MODE"
  addKey("videotext_info", Unmapped_Key, 0x1035, 13);
  addKey("green", Green_Key, 0x1036, 13); // "MOVE"
  addKey("red", Red_Key, 0x1037, 13); // "DEL"
  addKey("scartmode", AuxInput_Key, 0x1038, 13); // "IN", "Src"
  addKey("Teletext", Teletext_Key, 0x103C, 13); // "PAGE", "videotextmode"
  addKey("tvmode", Input_Key, 0x103F, 13);
}


DaewooTV2::DaewooTV2(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Daewoo_Make,
      index)
{
  addControlledDevice(Daewoo_Make, "DMQ-2141", TV_Device);

  threadableProtocol = new DaewooProtocol(guiObject, index);

  setPreData(0x14, 8);

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
  addKey("1-", Unmapped_Key, 0x0A, 8); // sort of double digit here...
  addKey("2-", Unmapped_Key, 0x0B, 8);
  addKey("AFT/Band", Unmapped_Key, 0x0C, 8); // Tuner Band key?
  addKey("Preset", Unmapped_Key, 0x0D, 8);
  addKey("Auto_Search+", Unmapped_Key, 0x0E, 8);
  addKey("Fine_Tuning+", Unmapped_Key, 0x0F, 8);
  addKey("Channel_Call", Unmapped_Key, 0x10, 8);
  addKey("On_Timer", Timer_Key, 0x11, 8);
  addKey("Auto_Search-", Unmapped_Key, 0x12, 8);
  addKey("Fine_Tuning-", Unmapped_Key, 0x13, 8);
  addKey("Hour", Unmapped_Key, 0x14, 8);
  addKey("Minute", Unmapped_Key, 0x15, 8);
  addKey("On_Timer_Enable", Unmapped_Key, 0x16, 8);
  addKey("Sleep", Sleep_Key, 0x17, 8);
  addKey("Volume+", VolumeUp_Key, 0x18, 8);
  addKey("Up", Up_Key, 0x19, 8);
  addKey("Select", Select_Key, 0x1A, 8);
  addKey("Mute", Mute_Key, 0x1B, 8);
  addKey("Volume-", VolumeDown_Key, 0x1C, 8);
  addKey("Down", Down_Key, 0x1D, 8);
  addKey("TV/VCR", Input_Key, 0x1E, 8);
  addKey("Standby", Power_Key, 0x1F, 8);
  addKey("3-", Unmapped_Key, 0x28, 8);
  addKey("4-", Unmapped_Key, 0x29, 8);
  addKey("Channel+", ChannelUp_Key, 0x30, 8);
  addKey("Channel-", ChannelDown_Key, 0x34, 8);
  addKey("Skip", Unmapped_Key, 0x38, 8);
  addKey("System", Menu_Key, 0x39, 8);
  addKey("Q.V.", Unmapped_Key, 0x3C, 8);
}


DaewooDVD1::DaewooDVD1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Daewoo_Make,
      index)
{
  threadableProtocol = new DaewooProtocol(guiObject, index);

  setPreData(0x15, 8);

  addKey("NUM0", Zero_Key, 0x90, 8);
  addKey("NUM1", One_Key, 0x91, 8);
  addKey("NUM2", Two_Key, 0x92, 8);
  addKey("NUM3", Three_Key, 0x93, 8);
  addKey("NUM4", Four_Key, 0x94, 8);
  addKey("NUM5", Five_Key, 0x95, 8);
  addKey("NUM6", Six_Key, 0x96, 8);
  addKey("NUM7", Seven_Key, 0x97, 8);
  addKey("NUM8", Eight_Key, 0x98, 8);
  addKey("NUM9", Nine_Key, 0x99, 8);
  addKey("SYSTEM", Guide_Key, 0x9A, 8); // not quite guide
  addKey("SETUP", Menu_Key, 0x9B, 8);
  addKey("PAUSE", Pause_Key, 0x9C, 8);
  addKey("STOP", Stop_Key, 0x9D, 8);
  addKey("PLAY", Play_Key, 0x9E, 8);
  addKey("FFWD", FastForward_Key, 0x9F, 8);

  addKey("REW", Rewind_Key, 0xA0, 8);
  addKey("MENU", DiscMenu_Key, 0xA1, 8);
  addKey("ENTER", Select_Key, 0xA2, 8);
  addKey("NEXT", Next_Key, 0xA3, 8);
  addKey("PREV", Previous_Key, 0xA4, 8);
  addKey("POWER", Power_Key, 0xA5, 8);
  addKey("SREW", StepBack_Key, 0xA6, 8);
  addKey("UP", Up_Key, 0xA7, 8);
  addKey("DOWN", Down_Key, 0xA8, 8);
  addKey("RIGHT", Right_Key, 0xA9, 8);
  addKey("LEFT", Left_Key, 0xAA, 8);
  addKey("ANGLE", Angle_Key, 0xAB, 8);
  addKey("CLEAR", Clear_Key, 0xAC, 8); // Might be exit key
  addKey("AUDIO", Audio_Key, 0xAD, 8);
  addKey("OPEN", Eject_Key, 0xAE, 8);
  addKey("DISPLAY", Info_Key, 0xAF, 8);

  addKey("TITLE", DiscTitle_Key, 0xB0, 8);
  addKey("ZOOM", Zoom_Key, 0xB1, 8);
  addKey("AB", RepeatAB_Key, 0xB3, 8);
  addKey("3D", Unmapped_Key, 0xB4, 8);
  addKey("SUB", Captions_Key, 0xB5, 8);
  addKey("REPEAT", Repeat_Key, 0xB8, 8);
  addKey("SCART", ScartInput_Key, 0xBA, 8);
  addKey("PROG", Program_Key, 0xBB, 8);
  addKey("SFFWD", StepForward_Key, 0xBC, 8);
  addKey("SEARCH", Unmapped_Key, 0xBE, 8);
  addKey("MUTE", Mute_Key, 0xBF, 8);
}


DaewooVCR1::DaewooVCR1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      Daewoo_Make,
      index)
{
  addControlledDevice(Daewoo_Make, "PV-200", VCR_Device);

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x31, 8);

  addKey("+CH", ChannelUp_Key, 0x01, 8);
  addKey("-CH", ChannelDown_Key, 0x02, 8);
  addKey("1", One_Key, 0x04, 8);
  addKey("2", Two_Key, 0x05, 8);
  addKey("3", Three_Key, 0x06, 8);
  addKey("4", Four_Key, 0x07, 8);

  addKey("5", Five_Key, 0x0C, 8);
  addKey("6", Six_Key, 0x0D, 8);
  addKey("7", Seven_Key, 0x0E, 8);
  addKey("8", Eight_Key, 0x0F, 8);

  addKey("STOP", Stop_Key, 0x10, 8);
  addKey("PAUSE/STILL", Pause_Key, 0x11, 8);
  addKey("REW", Rewind_Key, 0x12, 8);
  addKey("PLAY", Play_Key, 0x14, 8);
  addKey("FF", FastForward_Key, 0x13, 8);
  addKey("REC", Record_Key, 0x15, 8);
  addKey("TYPE", Unmapped_Key, 0x18, 8);
  addKey("INDEX", Unmapped_Key, 0x19, 8);
  addKey("9", Nine_Key, 0x1C, 8);
  addKey("0", Zero_Key, 0x1D, 8);
  addKey("INPUT", Input_Key, 0x1E, 8);

  addKey("MEMORY", Memory_Key, 0x43, 8);
  addKey("RESET", Reset_Key, 0x44, 8);
  addKey("CLEAR", Clear_Key, 0x4A, 8);
  addKey("OK", Select_Key, 0x4B, 8); // enter key?
  addKey("DISPLAY", Info_Key, 0x4C, 8);
  addKey("VPS/PDC", Unmapped_Key, 0x4F, 8);

  addKey("POWER", Power_Key, 0x5B, 8);

  addKey("ShowView", Unmapped_Key, 0x8C, 8);
  addKey("PRESET", Unmapped_Key, 0x9E, 8);
  addKey("MENU/TV", Menu_Key, 0xCA, 8);
}


DaewooVCR2::DaewooVCR2(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 2",
      Daewoo_Make,
      index)
{
  addControlledDevice(Daewoo_Make, "VQ857S", VCR_Device);

  threadableProtocol = new DaewooProtocol(guiObject, index);

  setPreData(0x15, 8);

  addKey("ch0", Zero_Key, 0x00, 8);
  addKey("ch1", One_Key, 0x01, 8);
  addKey("ch2", Two_Key, 0x02, 8);
  addKey("ch3", Three_Key, 0x03, 8);
  addKey("ch4", Four_Key, 0x04, 8);
  addKey("ch5", Five_Key, 0x05, 8);
  addKey("ch6", Six_Key, 0x06, 8);
  addKey("ch7", Seven_Key, 0x07, 8);
  addKey("ch8", Eight_Key, 0x08, 8);
  addKey("ch9", Nine_Key, 0x09, 8);
  addKey("stop", Stop_Key, 0x0D, 8);
  addKey("play", Play_Key, 0x0E, 8);
  addKey("ffwd", FastForward_Key, 0x0F, 8);

  addKey("rew", Rewind_Key, 0x10, 8);
  addKey("pause", Pause_Key, 0x11, 8);
  addKey("O", Unmapped_Key, 0x12, 8);
  addKey("next", Next_Key, 0x13, 8);
  addKey("power", Power_Key, 0x15, 8);
  addKey("tv/vcr", Input_Key, 0x16, 8);
  addKey("prup", ChannelUp_Key, 0x17, 8);
  addKey("prdown", ChannelDown_Key, 0x18, 8);
  addKey("ad", Unmapped_Key, 0x19, 8);
  addKey("asel", Unmapped_Key, 0x1A, 8);
  addKey("sp/lp", VHSSpeed_Key, 0x1B, 8);
  addKey("svc", Unmapped_Key, 0x1C, 8);
  addKey("a", Unmapped_Key, 0x1D, 8);
  addKey("gt30", Unmapped_Key, 0x1E, 8);
  addKey("pal/sec", Unmapped_Key, 0x1F, 8);

  addKey("eject", Eject_Key, 0x21, 8);
  addKey("menu", Menu_Key, 0x22, 8);
  addKey("qs", Unmapped_Key, 0x27, 8);
  addKey("ok", Select_Key, 0x29, 8);
  addKey("left", Left_Key, 0x31, 8);
  addKey("indexup", Unmapped_Key, 0x33, 8);
  addKey("right", Right_Key, 0x35, 8);
  addKey("av", AuxInput_Key, 0x36, 8);
  addKey("sv/v+", Unmapped_Key, 0x39, 8);
  addKey("indexdown", Unmapped_Key, 0x3F, 8);
}
