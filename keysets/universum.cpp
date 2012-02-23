#include "universum.h"
#include "protocols/necprotocol.h"
#include "protocols/necxprotocol.h"
#include "protocols/rc5protocol.h"


UniversumVCR1::UniversumVCR1(
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      Universum_Make,
      index)
{
}


void UniversumVCR1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x31, 8);

  addKey("ch/track_+", ChannelUp_Key, 0x01, 8);
  addKey("ch/track_-", ChannelDown_Key, 0x02, 8);
  addKey("audio", Audio_Key, 0x03, 8);
  addKey("1", One_Key, 0x04, 8);
  addKey("2", Two_Key, 0x05, 8);
  addKey("3", Three_Key, 0x06, 8);
  addKey("4", Four_Key, 0x07, 8);
  addKey("tv/vcr", Unmapped_Key, 0x08, 8);
  addKey("SportsRevue", Unmapped_Key, 0x0B, 8);
  addKey("5", Five_Key, 0x0C, 8);
  addKey("6", Six_Key, 0x0D, 8);
  addKey("7", Seven_Key, 0x0E, 8);
  addKey("8", Eight_Key, 0x0F, 8);

  addKey("stop", Stop_Key, 0x10, 8);
  addKey("pause/still", Pause_Key, 0x11, 8);
  addKey("rew<<", Rewind_Key, 0x12, 8);
  addKey("f.f>>", FastForward_Key, 0x13, 8);
  addKey("play", Play_Key, 0x14, 8);
  addKey("rec", Record_Key, 0x15, 8);
  addKey("type", Unmapped_Key, 0x18, 8);
  addKey("index", Unmapped_Key, 0x19, 8);
  addKey("slow", Slow_Key, 0x1A, 8);
  addKey("9", Nine_Key, 0x1C, 8);
  addKey("0", Zero_Key, 0x1D, 8);
  addKey("input", Input_Key, 0x1E, 8);

  addKey(">0</m", Unmapped_Key, 0x43, 8);
  addKey("reset", Reset_Key, 0x44, 8);
  addKey("Type", Unmapped_Key, 0x46, 8);
  addKey("a-dub", Unmapped_Key, 0x49, 8);
  addKey("clear", Clear_Key, 0x4A, 8);
  addKey("ok", Select_Key, 0x4B, 8);
  addKey("display", Info_Key, 0x4C, 8);
  addKey("dpc_plus/vps/pdc", Unmapped_Key, 0x4F, 8);
  addKey("Surround", Surround_Key, 0x50, 8);
  addKey("remain", Unmapped_Key, 0x57, 8);
  addKey("power", Power_Key, 0x5B, 8);
  addKey("sp/lp", VHSSpeed_Key, 0x5E, 8);
  addKey("showview", Unmapped_Key, 0x8C, 8);
  addKey("pip", PIP_Key, 0x8D, 8);
  addKey("strobe", Unmapped_Key, 0x9A, 8);
  addKey("preset", Unmapped_Key, 0x9E, 8);
  addKey("menu/tv", Menu_Key, 0xCA, 8);
  addKey("tv-scan", Scan_Key, 0xDA, 8);
  addKey("surround", Surround_Key, 0xD5, 8);
  addKey("m-index", Unmapped_Key, 0xDC, 8);
}


UniversumVCR2::UniversumVCR2(
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 2",
      Universum_Make,
      index)
{
}


void UniversumVCR2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

  addKey("STANDBY", Power_Key, 0x114C, 13);
  addKey("CASS", Eject_Key, 0x017E, 13);
  addKey("TIMER", Timer_Key, 0x115D, 13);
  addKey("1", One_Key, 0x1141, 13);
  addKey("2", Two_Key, 0x1142, 13);
  addKey("3", Three_Key, 0x1143, 13);
  addKey("4", Four_Key, 0x1144, 13);
  addKey("5", Five_Key, 0x1145, 13);
  addKey("6", Six_Key, 0x1146, 13);
  addKey("7", Seven_Key, 0x1147, 13);
  addKey("8", Eight_Key, 0x1148, 13);
  addKey("9", Nine_Key, 0x1149, 13);
  addKey("0", Zero_Key, 0x1140, 13);
  addKey("+", ChannelUp_Key, 0x1160, 13);
  addKey("-", ChannelDown_Key, 0x1161, 13);
  addKey("SEL/VPS", Unmapped_Key, 0x114B, 13);
  addKey("CLEAR", Clear_Key, 0x1171, 13);
  addKey("RECORD", Record_Key, 0x1177, 13);
  addKey("STILL", Pause_Key, 0x1169, 13);
  addKey("FWD", FastForward_Key, 0x1166, 13);
  addKey("RWD", Rewind_Key, 0x1165, 13);
  addKey("PLAY", Play_Key, 0x1175, 13);
  addKey("PREVIOUS", Previous_Key, 0x0171, 13);
  addKey("NEXT", Next_Key, 0x0170, 13);
  addKey("STOP", Stop_Key, 0x1176, 13);
  addKey("MONITOR", Unmapped_Key, 0x017A, 13);
  addKey("TUNER", Unmapped_Key, 0x017D, 13);
  addKey("TRACKING", AutoTracking_Key, 0x114E, 13);
  addKey("SP/LP", VHSSpeed_Key, 0x117A, 13);
  addKey("pip", PIP_Key, 0x8D, 8);
}


UniversumVCR3::UniversumVCR3(
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 3",
      Universum_Make,
      index)
{
}


void UniversumVCR3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, false);

  setPreData(0x7B80, 16);

  addKey("power", Power_Key, 0x13, 8);
  addKey("showview", Unmapped_Key, 0x1D, 8);
  addKey("eject", Eject_Key, 0x4E, 8);
  addKey("ch_up", ChannelUp_Key, 0x0A, 8);
  addKey("ch_down", ChannelDown_Key, 0x0B, 8);
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
  addKey("tv_vcr_scart_sw", Input_Key, 0x12, 8);
  addKey("index", Unmapped_Key, 0x14, 8);
  addKey("once", Unmapped_Key, 0x58, 8);
  addKey("daily", Unmapped_Key, 0x49, 8);
  addKey("weekly", Unmapped_Key, 0x4D, 8);
  addKey("timer_rec", Unmapped_Key, 0x0D, 8);
  addKey("clock_counter", Unmapped_Key, 0x51, 8);
  addKey("aft_vps", Unmapped_Key, 0x46, 8);
  addKey("preset", Unmapped_Key, 0x40, 8);
  addKey("memory", Memory_Key, 0x4B, 8);
  addKey("reset", Reset_Key, 0x4C, 8);
  addKey("call", Call_Key, 0x5F, 8);
  addKey("trck_auto", AutoTracking_Key, 0x52, 8);
  addKey("trck_fine_minus", TrackingMinus_Key, 0x44, 8);
  addKey("trck_fine_plus", TrackingPlus_Key, 0x43, 8);
  addKey("menu", Menu_Key, 0x50, 8);
  addKey("set_minus", Left_Key, 0x42, 8);
  addKey("set_plus", Right_Key, 0x41, 8);
  addKey("enter", Select_Key, 0x45, 8);
  addKey("cancel", Clear_Key, 0x4A, 8);
  addKey("slow", Slow_Key, 0x1F, 8);
  addKey("input_select", Unmapped_Key, 0x0C, 8);
  addKey("sp_lp", VHSSpeed_Key, 0x1E, 8);
  addKey("pause", Pause_Key, 0x1A, 8);
  addKey("stop", Stop_Key, 0x17, 8);
  addKey("rec_otr", Record_Key, 0x15, 8);
  addKey("rew", Rewind_Key, 0x19, 8);
  addKey("play", Play_Key, 0x16, 8);
  addKey("f.fwd", FastForward_Key, 0x18, 8);
}


UniversumTV1::UniversumTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Universum_Make,
      index)
{
}


void UniversumTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

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
  addKey("--", Dash_Key, 0x100A, 13);
  addKey("POWER_OFF", Power_Key, 0x100C, 13);
  addKey("MUTE", Mute_Key, 0x100D, 13);
  addKey("PP", PrevChannel_Key, 0x100E, 13);

  addKey("VOL_UP", VolumeUp_Key, 0x1010, 13);
  addKey("VOL_DOWN", VolumeDown_Key, 0x1011, 13);
  addKey("INFO", Info_Key, 0x1012, 13);
  addKey("LEFT", Left_Key, 0x0015, 13);
  addKey("RIGHT", Right_Key, 0x0016, 13);

  addKey("UP", ChannelUp_Key, 0x1020, 13);
  addKey("UP", Up_Key, 0x1020, 13);
  addKey("DOWN", ChannelDown_Key, 0x1021, 13);
  addKey("DOWN", Down_Key, 0x1021, 13);
  addKey("P<P", Unmapped_Key, 0x1022, 13);
  addKey("VT_STOP", TeletextHold_Key, 0x1029, 13); // "TEXT_ZOOM"
  addKey("TEXT_CLOCK", TeletextTime_Key, 0x102A, 13);
  addKey("VT_?", TeletextReveal_Key, 0x102C, 13); // "TEXT_QUESTION"
  addKey("VT_X", TeletextOff_Key, 0x102D, 13); // "TEXT_X"
  addKey("VT_TRANSPARENT", TeletextAndTV_Key, 0x102E, 13); // "TEXT_HALFPAGE"
  addKey("VT_I", Unmapped_Key, 0x102F, 13);

  addKey("MENU", Menu_Key, 0x1030, 13);
  addKey("YELLOW", Yellow_Key, 0x1032, 13);
  addKey("BLUE", Blue_Key, 0x1034, 13);
  addKey("GREEN", Green_Key, 0x1036, 13);
  addKey("RED", Red_Key, 0x1037, 13);
  addKey("AV", AuxInput_Key, 0x1038, 13);
  addKey("VIDEOTEXT", Teletext_Key, 0x103C, 13);
  addKey("TV", Unmapped_Key, 0x103F, 13);
}


UniversumTV1a::UniversumTV1a(
  unsigned int index)
  : UniversumTV1(index)
{
  setKeysetName("TV Keyset 1a");
}


void UniversumTV1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  UniversumTV1::populateProtocol(guiObject);

  addKey("UP", Up_Key, 0x0010, 13);
  addKey("DOWN", Down_Key, 0x0011, 13);
  addKey("MENU", Menu_Key, 0x0012, 13);
  addKey("-", Left_Key, 0x0015, 13);
  addKey("+", Right_Key, 0x0016, 13);
  addKey("TV_UPPERRIGHT", Unmapped_Key, 0x0018, 13);
  addKey("TV_FROMUPPERRIGHT", Unmapped_Key, 0x0019, 13);
  addKey("TV_FROMUPPERLEFT", Unmapped_Key, 0x001A, 13);
  addKey("TV_TRIANGLE_ETC", Unmapped_Key, 0x001F, 13);

  addKey("TV_MUSTER", Unmapped_Key, 0x0020, 13);
  addKey("BRIGHT_LEVEL", BrightnessUp_Key, 0x0024, 13);
  addKey("TV_CORNER_TRIANGLE", Unmapped_Key, 0x0025, 13);
  addKey("GRAY+", Unmapped_Key, 0x0026, 13);
  addKey("GRAY-", Unmapped_Key, 0x0027, 13);
  addKey("TV_UPPERLEFT", Unmapped_Key, 0x0028, 13);
  addKey("RED", Red_Key, 0x002B, 13);
  addKey("GREEN", Green_Key, 0x002C, 13);
  addKey("YELLOW", Yellow_Key, 0x002D, 13);
  addKey("BLUE", Blue_Key, 0x002E, 13);
  addKey("WHITE", Unmapped_Key, 0x002F, 13);
  addKey("SATELLITE", SatInput_Key, 0x0031, 13);
  addKey("TV_FORMAT", AspectRatio_Key, 0x003E, 13);

  addKey("TV_+", Info_Key, 0x100F, 13);

  addKey("TEXT_UPDOWN", TeletextSize_Key, 0x102B, 13);
  addKey("TEXT_QUESTION", TeletextReveal_Key, 0x102C, 13);

  addKey("TV_MOVE_HORIZ", Unmapped_Key, 0x1038, 13);
}


UniversumSat1::UniversumSat1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Sat Keyset 1",
      Universum_Make,
      index)
{
}


void UniversumSat1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

  addKey("on", Power_Key, 0x13CC, 13);
  addKey("mute", Mute_Key, 0x13CD, 13);
  addKey("1", One_Key, 0x13C1, 13);
  addKey("2", Two_Key, 0x13C2, 13);
  addKey("3", Three_Key, 0x13C3, 13);
  addKey("4", Four_Key, 0x13C4, 13);
  addKey("5", Five_Key, 0x13C5, 13);
  addKey("6", Six_Key, 0x13C6, 13);
  addKey("7", Seven_Key, 0x13C7, 13);
  addKey("8", Eight_Key, 0x13C8, 13);
  addKey("9", Nine_Key, 0x13C9, 13);
  addKey("0", Zero_Key, 0x13C0, 13);
  addKey("tv", AntennaInput_Key, 0x03C5, 13);
  addKey("radio", TunerInput_Key, 0x03C4, 13);
  addKey("av", AuxInput_Key, 0x13F8, 13);
  addKey("info", Info_Key, 0x13EC, 13);
  addKey("list", Unmapped_Key, 0x13EA, 13);
  addKey("swap", Unmapped_Key, 0x13E2, 13);
  addKey("red", Red_Key, 0x13F7, 13);
  addKey("green", Green_Key, 0x13F6, 13);
  addKey("yellow", Yellow_Key, 0x13F2, 13);
  addKey("blue", Blue_Key, 0x13F4, 13);
  addKey("exit", Exit_Key, 0x13ED, 13);
  addKey("menu", Menu_Key, 0x03D2, 13);
  addKey("ch_up", ChannelUp_Key, 0x13E0, 13);
  addKey("ch_up", Up_Key, 0x13E0, 13);
  addKey("ch_down", ChannelDown_Key, 0x13E1, 13);
  addKey("ch_down", Down_Key, 0x13E1, 13);
  addKey("vol+", VolumeUp_Key, 0x13D0, 13);
  addKey("vol+", Right_Key, 0x13D0, 13);
  addKey("vol-", VolumeDown_Key, 0x13D1, 13);
  addKey("vol-", Left_Key, 0x13D1, 13);
  addKey("ok", Select_Key, 0x03D7, 13);
}


UniversumAudio1::UniversumAudio1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 1",
      Universum_Make,
      index)
{
}


void UniversumAudio1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated
    return;
  }

  threadableProtocol = new NECXProtocol(guiObject, index, true);

  setPreData(0x1010, 16);

  addKey("FM", TunerBand_Key, 0x00, 8);
  addKey("MW", Unmapped_Key, 0x01, 8);
  addKey("LW", Unmapped_Key, 0x02, 8);
  addKey("CDP", CDInput_Key, 0x03, 8);
  addKey("CD_PLAY", Play_Key, 0x04, 8);
  addKey("CD_STOP", Stop_Key, 0x05, 8);
  addKey("CD_TRACK-", Previous_Key, 0x06, 8);
  addKey("CD_TRACK+", Next_Key, 0x07, 8);
  addKey("TAPE", TapeInput_Key, 0x08, 8);
  addKey("AUX", AuxInput_Key, 0x09, 8);
  addKey("PHONO", PhonoInput_Key, 0x0B, 8);
  addKey("TP_PLAYR", Unmapped_Key, 0x0C, 8);
  addKey("TP_PLAY", Unmapped_Key, 0x0D, 8);
  addKey("TP_STOP", Unmapped_Key, 0x0E, 8);
  addKey("AUTO", FMMode_Key, 0x0F, 8); // might be wrong

  addKey("TP_REW", Unmapped_Key, 0x10, 8);
  addKey("TP_FFD", Unmapped_Key, 0x11, 8);
  addKey("TP_PAUSE", Unmapped_Key, 0x14, 8);
  addKey("TP_REC", Unmapped_Key, 0x15, 8);
  addKey("VOL-", VolumeDown_Key, 0x16, 8);
  addKey("VOL+", VolumeUp_Key, 0x17, 8);
  addKey("TUN-", ChannelDown_Key, 0x1A, 8);
  addKey("TUN+", ChannelUp_Key, 0x1B, 8);
  addKey("TP_A", Unmapped_Key, 0x1C, 8);
  addKey("POWER", Power_Key, 0x1E, 8);
  addKey("MUTE", Mute_Key, 0x1F, 8);

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
  addKey("CD_PROG", Program_Key, 0x4D, 8);
  addKey("CD_REPEAT", Repeat_Key, 0x4E, 8);

  addKey("CD_FFWD", FastForward_Key, 0x52, 8);
  addKey("CD_REW", Rewind_Key, 0x53, 8);
  addKey("TP_B", Unmapped_Key, 0x83, 8);
  addKey("CLOCK", Info_Key, 0xC1, 8);
  addKey("SLEEP", Sleep_Key, 0xC2, 8);
  addKey("TP_RMUTE", Unmapped_Key, 0xD1, 8);
}
