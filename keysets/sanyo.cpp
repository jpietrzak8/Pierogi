#include "sanyo.h"

#include "necprotocol.h"

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

  threadableProtocol = new NECProtocol(guiObject, index);

  setPreData(0x8C73, 16);

  addKey("Power", Power_Key, 0xDA25, 16);
  addKey("1", One_Key, 0x20DF, 16);
  addKey("2", Two_Key, 0xA05F, 16);
  addKey("3", Three_Key, 0x609F, 16);
  addKey("4", Four_Key, 0xE01F, 16);
  addKey("5", Five_Key, 0x30CF, 16);
  addKey("6", Six_Key, 0xB04F, 16);
  addKey("7", Seven_Key, 0x708F, 16);
  addKey("8", Eight_Key, 0xF00F, 16);
  addKey("9", Nine_Key, 0x38C7, 16);
  addKey("0", Zero_Key, 0xB847, 16);
  addKey("Cancel", Clear_Key, 0x52AD, 16);
  addKey("Ch Up", ChannelUp_Key, 0x807F, 16);
  addKey("Ch Down", ChannelDown_Key, 0x40BF, 16);
  addKey("Rew", Rewind_Key, 0x48B7, 16);
  addKey("Play", Play_Key, 0x28D7, 16);
  addKey("FF", FastForward_Key, 0xC837, 16);
  addKey("Rec", Record_Key, 0xA857, 16);
  addKey("Stop", Stop_Key, 0x08F7, 16);
  addKey("Pause", Pause_Key, 0x8877, 16);
  addKey("TV/VCR", Input_Key, 0x10EF, 16);
  addKey("Menu", Menu_Key, 0x53AC, 16);
  addKey("Up", Up_Key, 0xE916, 16);
  addKey("Down", Down_Key, 0x6996, 16);
  addKey("Left", Left_Key, 0xA956, 16);
  addKey("Right", Right_Key, 0x29D6, 16);
  addKey("Ok", Select_Key, 0xD22D, 16);
  addKey("Clock", Clock_Key, 0x6A95, 16);
  addKey("Reset", Reset_Key, 0x22DD, 16);
  addKey("Display", Info_Key, 0x32CD, 16);
  addKey("Memory", Unmapped_Key, 0xC23D, 16); // "->0<-"
  addKey("PROG", Program_Key, 0x629D, 16);
  addKey("BLANK", Unmapped_Key, 0x0BF4, 16);
  addKey("Monitor", Unmapped_Key, 0x8A75, 16);
  addKey("ShowView", Unmapped_Key, 0x31CE, 16);
  addKey("ATR", Unmapped_Key, 0xF807, 16);
  addKey("Slow", Unmapped_Key, 0x58A7, 16);
  addKey("SP/LP", VHSSpeed_Key, 0x7A85, 16);
  addKey("VPS", Unmapped_Key, 0xF20D, 16); // "vps/pdc", "dpc"
  addKey("Preset", Unmapped_Key, 0x7986, 16);
  addKey("Input", Unmapped_Key, 0x7887, 16);  // need a subclass for this?
  addKey("Audio", Language_Key, 0xC03F, 16);
  addKey("Index", Unmapped_Key, 0x9867, 16);
  addKey("+100", PlusOneHundred_Key, 0xD827, 16);
  addKey("x2", Unmapped_Key, 0xD02F, 16);
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

  threadableProtocol = new NECProtocol(guiObject, index);

  setPreData(0x3C23, 16);

  addKey("On", Power_Key, 0x00FF, 16);
  addKey("LastMemo", Unmapped_Key, 0xF40B, 16);
  addKey("PictureMode", PictureMode_Key, 0x5CA3, 16);
  addKey("OpenClose", Eject_Key, 0x807F, 16);
  addKey("ProgramRandom", Random_Key, 0x9C63, 16);
  addKey("Repeat", Repeat_Key, 0xAC53, 16);
  addKey("ABRepeat", Unmapped_Key, 0x6C93, 16);
  addKey("OnScreen", Unmapped_Key, 0xC03F, 16);
  addKey("Zoom", Unmapped_Key, 0xDC23, 16);
  addKey("Angle", Unmapped_Key, 0x10EF, 16);
  addKey("AngleReplay", Unmapped_Key, 0x906F, 16);
  addKey("SubtitleChange", Unmapped_Key, 0xA05F, 16);
  addKey("Setup", Menu_Key, 0x40BF, 16);
  addKey("Menu", DiscMenu_Key, 0xE01F, 16);
  addKey("SubtitleOnOff", Captions_Key, 0x52AD, 16);
  addKey("Audio", Language_Key, 0x50AF, 16);
  addKey("Up", Up_Key, 0xD02F, 16);
  addKey("Down", Down_Key, 0x30CF, 16);
  addKey("Left", Left_Key, 0xB04F, 16);
  addKey("Right", Right_Key, 0x708F, 16);
  addKey("Enter", Select_Key, 0xF00F, 16);
  addKey("TopMenu", DiscTitle_Key, 0x609F, 16);
  addKey("Return", Exit_Key, 0x08F7, 16);
  addKey("RevSlow", StepBack_Key, 0x34CB, 16);
  addKey("FwdSlow", StepForward_Key, 0x946B, 16);
  addKey("PauseStep", Pause_Key, 0x04FB, 16);
  addKey("Stop", Stop_Key, 0x7887, 16);
  addKey("Play", Play_Key, 0xF807, 16);
  addKey("Prev", Previous_Key, 0x44BB, 16);
  addKey("Next", Next_Key, 0x847B, 16);
  addKey("Rev", Rewind_Key, 0x649B, 16);
  addKey("Fwd", FastForward_Key, 0xC43B, 16);
  addKey("1", One_Key, 0x8877, 16);
  addKey("2", Two_Key, 0x48B7, 16);
  addKey("3", Three_Key, 0xC837, 16);
  addKey("4", Four_Key, 0x28D7, 16);
  addKey("5", Five_Key, 0xA857, 16);
  addKey("6", Six_Key, 0x6897, 16);
  addKey("7", Seven_Key, 0xE817, 16);
  addKey("8", Eight_Key, 0x18E7, 16);
  addKey("9", Nine_Key, 0x9867, 16);
  addKey("0", Zero_Key, 0x58A7, 16);
  addKey("Clear", Clear_Key, 0x38C7, 16);
  addKey("SearchMode", Unmapped_Key, 0x1CE3, 16);
}


SanyoTV1::SanyoTV1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Sanyo_Make,
      index)
{
  addControlledDevice(Sanyo_Make, "CTP-6791P", TV_Device);

  threadableProtocol = new NECProtocol(guiObject, index);

  setPreData(0x1CE3, 16);

  addKey("Power", Power_Key, 0x48B7, 16);
  addKey("audio_mode", SoundMode_Key, 0x38C7, 16); // "auto"
  addKey("video_mode", PictureMode_Key, 0xC837, 16);
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
  addKey("Channel Up", ChannelUp_Key, 0x50AF, 16);
  addKey("Channel Down", ChannelDown_Key, 0xD02F, 16);
  addKey("Volume Up", VolumeUp_Key, 0x708F, 16);
  addKey("Volume Down", VolumeDown_Key, 0xF00F, 16);
  addKey("Mute", Mute_Key, 0x18E7, 16);
  addKey("Display", Info_Key, 0x30CF, 16);
  addKey("image", AspectRatio_Key, 0x8877, 16);
  addKey("Menu", Menu_Key, 0xE817, 16); // "setup"
  addKey("Enter", Select_Key, 0x58A7, 16); // "F/OK"
  addKey("Sleep", Sleep_Key, 0xB04F, 16);
  addKey("Recall", PrevChannel_Key, 0x9867, 16);
  addKey("PIP", PIP_Key, 0xDA25, 16);
  addKey("Swap", PIPSwap_Key, 0xBA45, 16);
  addKey("Red", Red_Key, 0x926D, 16);
  addKey("Green", Green_Key, 0x52AD, 16);
  addKey("Yellow", Yellow_Key, 0xD22D, 16);
  addKey("Blue", Blue_Key, 0x32CD, 16);
  addKey("Menu +", Up_Key, 0x7887, 16);
  addKey("Menu -", Down_Key, 0xF807, 16);
  addKey("Digicon", Guide_Key, 0xB847, 16);
  addKey("TV", Input_Key, 0x28D7, 16); // tv/video
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

  addKey("POWER", Power_Key, 0x38C7, 16);
  addKey("WIDE", AspectRatio_Key, 0xC23D, 16);
  addKey("-/--", DoubleDigit_Key, 0x50AF, 16);
  addKey("CS", Unmapped_Key, 0xD02F, 16); // 2-
  addKey("OSD", Info_Key, 0x18E7, 16); // "SYMBOL_1
  addKey("NORMAL", Unmapped_Key, 0x8877, 16); // "SYMBOL_2"
  addKey("MUTE", Mute_Key, 0xA857, 16);
  addKey("P--P", Unmapped_Key, 0xB847, 16); // "ALTERNATE"
  addKey("MENU", Menu_Key, 0x8A75, 16);
  addKey("P+", ChannelUp_Key, 0x30CF, 16);
  addKey("UP", Up_Key, 0x30CF, 16);
  addKey("P-", ChannelDown_Key, 0xB04F, 16);
  addKey("DOWN", Down_Key, 0xB04F, 16);
  addKey("VOL-", VolumeDown_Key, 0xE817, 16);
  addKey("LEFT", Left_Key, 0xE817, 16);
  addKey("VOL+", VolumeUp_Key, 0x6897, 16);
  addKey("RIGHT", Right_Key, 0x6897, 16);
  addKey("CLOCK", Sleep_Key, 0x9867, 16); // "SLEEP/ON-TIMER/TEXT_CANCEL"
  addKey("EXPAND", Unmapped_Key, 0x6A95, 16); // "SYMBOL_4" teletext
  addKey("SHRINK", Unmapped_Key, 0x728D, 16); // "SYMBOL_5" teletext
  addKey("TXT/TV", Unmapped_Key, 0x629D, 16); // teletext
  addKey("A-B", Language_Key, 0x02FD, 16); //?
}


SanyoTV1b::SanyoTV1b(
  QObject *guiObject,
  unsigned int index)
  : SanyoTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1b");

  addKey("Reset", Reset_Key, 0x38C7, 16);
  addKey("Closed Captions", Captions_Key, 0x8877, 16);
}


SanyoTV1c::SanyoTV1c(
  QObject *guiObject,
  unsigned int index)
  : SanyoTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1c");

  addKey("tv/vid", Input_Key, 0xC837, 16);
}


SanyoTV1d::SanyoTV1d(
  QObject *guiObject,
  unsigned int index)
  : SanyoTV1a(guiObject, index)
{
  setKeysetName("TV Keyset 1d");

  addKey("prg_scan", Scan_Key, 0x08F7, 16);
  addKey("tuning_<", ChannelDown_Key, 0xC837, 16);
  addKey("tuning_>", ChannelUp_Key, 0x48B7, 16);
  addKey("colour_<", Unmapped_Key, 0xD827, 16);
  addKey("colour_>", Unmapped_Key, 0x58A7, 16);
  addKey("bright_<", Unmapped_Key, 0xF807, 16);
  addKey("bright_>", Unmapped_Key, 0x7887, 16);
  addKey("contrast_<", Unmapped_Key, 0xF00F, 16);
  addKey("contrast_>", Unmapped_Key, 0x708F, 16);
  addKey("clear_screen", Unmapped_Key, 0x18E7, 16);
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

  threadableProtocol = new NECProtocol(guiObject, index);

  setPreData(0x0C, 8);

  addKey("ONOFF0", Power_Key, 0xF300FF, 24);
  addKey("ONOFF1", Unmapped_Key, 0x73FF00, 24);
  addKey("AUTO_PC_ADJ", Unmapped_Key, 0xF3916E, 24);
  addKey("MENU", Menu_Key, 0xF338C7, 24);
  addKey("SCREEN", Unmapped_Key, 0xF341BE, 24);
  addKey("INPUT", Input_Key, 0xF3A05F, 24);
  addKey("IMAGE", Unmapped_Key, 0xF330CF, 24);
  addKey("AUTO", Unmapped_Key, 0xF3FC03, 24);
  addKey("COMPOSITE", Unmapped_Key, 0xF3BC43, 24);
  addKey("S-VIDEO", Unmapped_Key, 0xF37C83, 24);
  addKey("COMPONENT", Unmapped_Key, 0xF3C13E, 24);
  addKey("NOSHOW", Unmapped_Key, 0xF3D12E, 24);
  addKey("KEYSTONE_UP", Unmapped_Key, 0xF3718E, 24);
  addKey("KEYSTONE_DOWN", Unmapped_Key, 0xF3F10E, 24);
  addKey("IMAGE_1", One_Key, 0xF30AF5, 24);
  addKey("IMAGE_2", Two_Key, 0xF38A75, 24);
  addKey("IMAGE_3", Three_Key, 0xF36A95, 24);
  addKey("IMAGE_4", Four_Key, 0xF3EA15, 24);
  addKey("SELECT", Select_Key, 0xF3F00F, 24);
  addKey("LEFT", Left_Key, 0xF37887, 24);
  addKey("RIGHT", Right_Key, 0xF3B847, 24);
  addKey("UP", Up_Key, 0xF331CE, 24);
  addKey("DOWN", Down_Key, 0xF3B14E, 24);
}

