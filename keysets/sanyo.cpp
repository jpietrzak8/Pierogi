#include "sanyo.h"

#include "protocols/necprotocol.h"

SanyoVCR1::SanyoVCR1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR(/DVD) Keyset 1",
      Sanyo_Make,
      index)
{
  addControlledDevice(Sanyo_Make, "DVW-5000", VCR_Device);
  addControlledDevice(Sanyo_Make, "DVW-5000", DVD_Device);

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

//  setPreData(0x8C73, 16);
  setPreData(0x31, 8);

  addKey("Ch Up", ChannelUp_Key, 0x01, 8);
  addKey("Ch Down", ChannelDown_Key, 0x02, 8);
  addKey("Audio", Audio_Key, 0x03, 8);
  addKey("1", One_Key, 0x04, 8);
  addKey("2", Two_Key, 0x05, 8);
  addKey("3", Three_Key, 0x06, 8);
  addKey("4", Four_Key, 0x07, 8);
  addKey("TV/VCR", Input_Key, 0x08, 8);
  addKey("x2", Unmapped_Key, 0x0B, 8);
  addKey("5", Five_Key, 0x0C, 8);
  addKey("6", Six_Key, 0x0D, 8);
  addKey("7", Seven_Key, 0x0E, 8);
  addKey("8", Eight_Key, 0x0F, 8);
  addKey("Stop", Stop_Key, 0x10, 8);
  addKey("Pause", Pause_Key, 0x11, 8);
  addKey("Rew", Rewind_Key, 0x12, 8);
  addKey("FF", FastForward_Key, 0x13, 8);
  addKey("Play", Play_Key, 0x14, 8);
  addKey("Rec", Record_Key, 0x15, 8);
  addKey("Index", Unmapped_Key, 0x19, 8);
  addKey("Slow", Slow_Key, 0x1A, 8);
  addKey("+100", PlusOneHundred_Key, 0x1B, 8);
  addKey("9", Nine_Key, 0x1C, 8);
  addKey("0", Zero_Key, 0x1D, 8);
  addKey("Input", Unmapped_Key, 0x1E, 8);  // need a subclass for this?
  addKey("ATR", Unmapped_Key, 0x1F, 8);
  addKey("Memory", Memory_Key, 0x43, 8); // "->0<-"
  addKey("Reset", Reset_Key, 0x44, 8);
  addKey("PROG", Program_Key, 0x46, 8);
  addKey("Cancel", Clear_Key, 0x4A, 8);
  addKey("Ok", Select_Key, 0x4B, 8);
  addKey("Display", Info_Key, 0x4C, 8);
  addKey("VPS", Unmapped_Key, 0x4F, 8); // "vps/pdc", "dpc"
  addKey("Monitor", Unmapped_Key, 0x51, 8);
  addKey("Clock", Clock_Key, 0x56, 8);
  addKey("Power", Power_Key, 0x5B, 8);
  addKey("SP/LP", VHSSpeed_Key, 0x5E, 8);
  addKey("ShowView", Unmapped_Key, 0x8C, 8);
  addKey("Right", Right_Key, 0x94, 8);
  addKey("Left", Left_Key, 0x95, 8);
  addKey("Down", Down_Key, 0x96, 8);
  addKey("Up", Up_Key, 0x97, 8);
  addKey("Preset", Unmapped_Key, 0x9E, 8);
  addKey("Menu", Menu_Key, 0xCA, 8);
  addKey("BLANK", Unmapped_Key, 0xD0, 8);
}


SanyoDVD1::SanyoDVD1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Sanyo_Make,
      index)
{
  addControlledDevice(Sanyo_Make, "DVD-SL25", DVD_Device);

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

//  setPreData(0x3C23, 16);
  setPreData(0xC43C, 16);

  addKey("On", Power_Key, 0x00, 8);
  addKey("OpenClose", Eject_Key, 0x01, 8);
  addKey("Setup", Menu_Key, 0x02, 8);
  addKey("OnScreen", Unmapped_Key, 0x03, 8);
  addKey("SubtitleChange", Unmapped_Key, 0x05, 8);
  addKey("TopMenu", DiscTitle_Key, 0x06, 8);
  addKey("Menu", DiscMenu_Key, 0x07, 8);
  addKey("Angle", Angle_Key, 0x08, 8);
  addKey("AngleReplay", Unmapped_Key, 0x09, 8);
  addKey("Audio", Audio_Key, 0x0A, 8);
  addKey("Up", Up_Key, 0x0B, 8);
  addKey("Down", Down_Key, 0x0C, 8);
  addKey("Left", Left_Key, 0x0D, 8);
  addKey("Right", Right_Key, 0x0E, 8);
  addKey("Enter", Select_Key, 0x0F, 8);
  addKey("Return", Exit_Key, 0x10, 8);
  addKey("1", One_Key, 0x11, 8);
  addKey("2", Two_Key, 0x12, 8);
  addKey("3", Three_Key, 0x13, 8);
  addKey("4", Four_Key, 0x14, 8);
  addKey("5", Five_Key, 0x15, 8);
  addKey("6", Six_Key, 0x16, 8);
  addKey("7", Seven_Key, 0x17, 8);
  addKey("8", Eight_Key, 0x18, 8);
  addKey("9", Nine_Key, 0x19, 8);
  addKey("0", Zero_Key, 0x1A, 8);
  addKey("Clear", Clear_Key, 0x1C, 8);
  addKey("Stop", Stop_Key, 0x1E, 8);
  addKey("Play", Play_Key, 0x1F, 8);
  addKey("PauseStep", Pause_Key, 0x20, 8);
  addKey("Next", Next_Key, 0x21, 8);
  addKey("Prev", Previous_Key, 0x22, 8);
  addKey("Fwd", FastForward_Key, 0x23, 8);
  addKey("Rev", Rewind_Key, 0x26, 8);
  addKey("FwdSlow", StepForward_Key, 0x29, 8);
  addKey("RevSlow", StepBack_Key, 0x2C, 8);
  addKey("LastMemo", Unmapped_Key, 0x2F, 8);
  addKey("Repeat", Repeat_Key, 0x35, 8);
  addKey("ABRepeat", RepeatAB_Key, 0x36, 8);
  addKey("SearchMode", Unmapped_Key, 0x38, 8);
  addKey("ProgramRandom", Random_Key, 0x39, 8);
  addKey("PictureMode", PictureMode_Key, 0x3A, 8);
  addKey("Zoom", Zoom_Key, 0x3B, 8);
  addKey("SubtitleOnOff", Captions_Key, 0x4A, 8);
}


SanyoTV1::SanyoTV1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Sanyo_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index, false, true);

//  setPreData(0x1CE3, 16);
  setPreData(0x38, 8);

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
  addKey("Channel Up", ChannelUp_Key, 0x0A, 8);
  addKey("Channel Down", ChannelDown_Key, 0x0B, 8);
  addKey("Display", Info_Key, 0x0C, 8);
  addKey("Sleep", Sleep_Key, 0x0D, 8);
  addKey("Volume Up", VolumeUp_Key, 0x0E, 8);
  addKey("Volume Down", VolumeDown_Key, 0x0F, 8);
  addKey("image", PictureMode_Key, 0x11, 8);
  addKey("Power", Power_Key, 0x12, 8);
  addKey("video_mode", Unmapped_Key, 0x13, 8);
  addKey("TV", Input_Key, 0x14, 8); // tv/video
  addKey("Menu", Menu_Key, 0x17, 8); // "setup"
  addKey("Recall", PrevChannel_Key, 0x19, 8);
  addKey("Enter", Select_Key, 0x1A, 8); // "F/OK"
  addKey("Red", Red_Key, 0x49, 8);
  addKey("Green", Green_Key, 0x4A, 8);
  addKey("Yellow", Yellow_Key, 0x4B, 8);
  addKey("Blue", Blue_Key, 0x4C, 8);
  addKey("PIP", PIP_Key, 0x5B, 8);
  addKey("Swap", PIPSwap_Key, 0x5D, 8);
}


SanyoTV1a::SanyoTV1a(
  QObject *guiObject,
  unsigned int index)
  : SanyoTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1a");

  addControlledDevice(Sanyo_Make, "28LN4-C", TV_Device);
  addControlledDevice(Sanyo_Make, "28CN7F", TV_Device);
  addControlledDevice(Sanyo_Make, "C21EF44", TV_Device);
  addControlledDevice(Sanyo_Make, "C25EG64", TV_Device);
  addControlledDevice(Sanyo_Make, "C28EH64", TV_Device);
//  addControlledDevice(Sanyo_Make, "CED3011PV", TV_Device);
//  addControlledDevice(Sanyo_Make, "CEM6011PV", TV_Device);
//  addControlledDevice(Sanyo_Make, "DP32746", TV_Device);

  addKey("-/--", DoubleDigit_Key, 0x0A, 8);
  addKey("CS", Unmapped_Key, 0x0B, 8); // 2-
  addKey("P+", ChannelUp_Key, 0x0C, 8);
  addKey("UP", Up_Key, 0x0C, 8);
  addKey("P-", ChannelDown_Key, 0x0D, 8);
  addKey("DOWN", Down_Key, 0x0D, 8);
  addKey("NORMAL", Unmapped_Key, 0x11, 8); // "SYMBOL_2"
  addKey("MUTE", Mute_Key, 0x15, 8);
  addKey("VOL+", VolumeUp_Key, 0x16, 8);
  addKey("RIGHT", Right_Key, 0x16, 8);
  addKey("VOL-", VolumeDown_Key, 0x17, 8);
  addKey("LEFT", Left_Key, 0x17, 8);
  addKey("OSD", Info_Key, 0x18, 8); // "SYMBOL_1
  addKey("CLOCK", Sleep_Key, 0x19, 8); // "SLEEP/ON-TIMER/TEXT_CANCEL"
  addKey("POWER", Power_Key, 0x1C, 8);
  addKey("P--P", PrevChannel_Key, 0x1D, 8); // "ALTERNATE"
  addKey("A-B", Unmapped_Key, 0x40, 8); //?
  addKey("WIDE", Unmapped_Key, 0x43, 8);
  addKey("TXT/TV", Teletext_Key, 0x46, 8); // teletext
  addKey("SHRINK", Unmapped_Key, 0x4E, 8); // "SYMBOL_5" teletext
  addKey("EXPAND", Unmapped_Key, 0x56, 8); // "SYMBOL_4" teletext
  addKey("MENU", Menu_Key, 0x51, 8);
}


SanyoTV1b::SanyoTV1b(
  QObject *guiObject,
  unsigned int index)
  : SanyoTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1b");

  addKey("Mute", Mute_Key, 0x18, 8);
  addKey("Reset", Reset_Key, 0x1C, 8);
  addKey("Closed Captions", Captions_Key, 0x11, 8);
}


SanyoTV1c::SanyoTV1c(
  QObject *guiObject,
  unsigned int index)
  : SanyoTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1c");

  addKey("Mute", Mute_Key, 0x18, 8);
  addKey("tv/vid", Input_Key, 0x13, 8);
  addKey("Reset", Reset_Key, 0x1C, 8);
}


SanyoTV1d::SanyoTV1d(
  QObject *guiObject,
  unsigned int index)
  : SanyoTV1a(guiObject, index)
{
  setKeysetName("TV Keyset 1d");

  addKey("contrast_>", ContrastUp_Key, 0x0E, 8);
  addKey("contrast_<", ContrastDown_Key, 0x0F, 8);
  addKey("prg_scan", Scan_Key, 0x10, 8);
  addKey("tuning_>", ChannelUp_Key, 0x12, 8);
  addKey("tuning_<", ChannelDown_Key, 0x13, 8);
  addKey("clear_screen", Unmapped_Key, 0x18, 8);
  addKey("colour_>", ColorUp_Key, 0x1A, 8);
  addKey("colour_<", ColorDown_Key, 0x1B, 8);
  addKey("bright_>", BrightnessUp_Key, 0x1E, 8);
  addKey("bright_<", BrightnessDown_Key, 0x1F, 8);
}


SanyoTV1e::SanyoTV1e(
  QObject *guiObject,
  unsigned int index)
  : SanyoTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1e");

  addControlledDevice(Sanyo_Make, "CTP-6791P", TV_Device);

  addKey("Mute", Mute_Key, 0x18, 8);
  addKey("audio_mode", SoundMode_Key, 0x1C, 8); // "auto"
  addKey("Digicon", PictureMode_Key, 0x1D, 8);
  addKey("Menu +", Right_Key, 0x1E, 8);
  addKey("Menu -", Left_Key, 0x1F, 8);
}


SanyoProjector::SanyoProjector(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Projector Keyset 1",
      Sanyo_Make,
      index)
{
  addControlledDevice(Sanyo_Make, "PLV-Z1", Other_Device);

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

//  setPreData(0x0CF3, 16);
  setPreData(0x30, 16);

  addKey("ONOFF0", Power_Key, 0x00, 8);
  addKey("INPUT", Input_Key, 0x05, 8);
  addKey("IMAGE", Unmapped_Key, 0x0C, 8);
  addKey("SELECT", Select_Key, 0x0F, 8);
  addKey("MENU", Menu_Key, 0x1C, 8);
  addKey("RIGHT", Right_Key, 0x1D, 8);
  addKey("LEFT", Left_Key, 0x1E, 8);
  addKey("AUTO", Unmapped_Key, 0x3C, 8);
  addKey("COMPOSITE", Unmapped_Key, 0x3D, 8);
  addKey("S-VIDEO", Unmapped_Key, 0x3E, 8);
  addKey("IMAGE_1", One_Key, 0x50, 8);
  addKey("IMAGE_2", Two_Key, 0x51, 8);
  addKey("IMAGE_3", Three_Key, 0x56, 8);
  addKey("IMAGE_4", Four_Key, 0x57, 8);
  addKey("SCREEN", Unmapped_Key, 0x82, 8);
  addKey("COMPONENT", Unmapped_Key, 0x83, 8);
  addKey("AUTO_PC_ADJ", Unmapped_Key, 0x89, 8);
  addKey("NOSHOW", Unmapped_Key, 0x8B, 8);
  addKey("UP", Up_Key, 0x8C, 8);
  addKey("DOWN", Down_Key, 0x8D, 8);
  addKey("KEYSTONE_UP", Unmapped_Key, 0x8E, 8);
  addKey("KEYSTONE_DOWN", Unmapped_Key, 0x8F, 8);
//  addKey("ONOFF1", Unmapped_Key, 0x0C73FF00, 32);
}

