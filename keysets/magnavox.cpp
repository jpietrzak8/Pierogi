#include "magnavox.h"
#include "rc6protocol.h"
#include "rc5protocol.h"
#include "necprotocol.h"

MagnavoxDVD1::MagnavoxDVD1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Magnavox_Make,
      index)
{
  addControlledDevice(Magnavox_Make, "MDV450", DVD_Device);

  threadableProtocol = new RC6Protocol(guiObject, index, 0x04);

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
  addKey("power", Power_Key, 0x0C, 8);
  addKey("mute", Mute_Key, 0x0D, 8);
  addKey("display", Info_Key, 0x0F, 8);
  addKey("repeat", Repeat_Key, 0x1D, 8);
  addKey(">>", FastForward_Key, 0x20, 8);
  addKey("<<", Rewind_Key, 0x21, 8);
  addKey("play", Play_Key, 0x2C, 8);
  addKey("pause", Pause_Key, 0x30, 8);
  addKey("stop", Stop_Key, 0x31, 8);
  addKey("a-b", RepeatAB_Key, 0x3B, 8);
  addKey("subtitle", Captions_Key, 0x4B, 8);
  addKey("audio", Audio_Key, 0x4E, 8);
  addKey("disc_Menu", DiscMenu_Key, 0x54, 8);
  addKey("^", Up_Key, 0x58, 8);
  addKey("<", Left_Key, 0x5A, 8);
  addKey(">", Right_Key, 0x5B, 8);
  addKey("v", Down_Key, 0x5C, 8);
  addKey("ok", Select_Key, 0x5D, 8);
  addKey("system_menu", Menu_Key, 0x82, 8);
  addKey("title", DiscTitle_Key, 0x83, 8);
  addKey("angle", Angle_Key, 0x85, 8);
  addKey("preview", Unmapped_Key, 0xD5, 8);
  addKey("zoom", Zoom_Key, 0xF7, 8);
}


MagnavoxVCR1::MagnavoxVCR1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      Magnavox_Make,
      index)
{
  threadableProtocol = new RC5Protocol(guiObject, index);

  addKey("Power", Power_Key, 0x114C, 13);
  addKey("0", Zero_Key, 0x1140, 13);
  addKey("1", One_Key, 0x1141, 13);
  addKey("2", Two_Key, 0x1142, 13);
  addKey("3", Three_Key, 0x1143, 13);
  addKey("4", Four_Key, 0x1144, 13);
  addKey("5", Five_Key, 0x1145, 13);
  addKey("6", Six_Key, 0x1146, 13);
  addKey("7", Seven_Key, 0x1147, 13);
  addKey("8", Eight_Key, 0x1148, 13);
  addKey("9", Nine_Key, 0x1149, 13);
  addKey("OneHundred", PlusOneHundred_Key, 0x114A, 13);
  addKey("CancelAngle", Unmapped_Key, 0x1171, 13);
  addKey("ChMinus", ChannelDown_Key, 0x1172, 13);
  addKey("ChPlus", ChannelUp_Key, 0x1174, 13);
  addKey("IndexTC", Unmapped_Key, 0x0170, 13);
  addKey("Menu", Menu_Key, 0x0152, 13);
  addKey("News", Unmapped_Key, 0x041A, 13);
  addKey("Night", Unmapped_Key, 0x143E, 13);
  addKey("OK", Select_Key, 0x0157, 13);
  addKey("Pause", Pause_Key, 0x1169, 13);
  addKey("Rew", Rewind_Key, 0x1172, 13);
  addKey("FF", FastForward_Key, 0x1174, 13);
  addKey("Play", Play_Key, 0x1175, 13);
  addKey("Stop", Stop_Key, 0x1176, 13);
  addKey("Record", Record_Key, 0x1177, 13);
  addKey("UP", Up_Key, 0x0150, 13);
  addKey("DOWN", Down_Key, 0x0151, 13);
  addKey("LEFT", Left_Key, 0x0155, 13);
  addKey("RIGHT", Right_Key, 0x0156, 13);
  addKey("VOL+", VolumeUp_Key, 0x1410, 13);
  addKey("VOL-", VolumeDown_Key, 0x1411, 13);
  addKey("Mute", Mute_Key, 0x100D, 13);
  addKey("TvPower", Unmapped_Key, 0x100C, 13);
  addKey("TvVolumeUp", Unmapped_Key, 0x1010, 13);
  addKey("TvVolumeDn", Unmapped_Key, 0x1011, 13);
  addKey("TvChUp", Unmapped_Key, 0x1020, 13);
  addKey("TvChDn", Unmapped_Key, 0x1021, 13);
  addKey("SkipSrch", Unmapped_Key, 0x016A, 13);
  addKey("FrameAdvance", StepForward_Key, 0x016B, 13);
  addKey("VcrChUp", Unmapped_Key, 0x1160, 13);
  addKey("VcrChDn", Unmapped_Key, 0x1161, 13);
  addKey("Menu", Menu_Key, 0x115D, 13);
  addKey("Slow", Slow_Key, 0x1168, 13);
  addKey("Status", Info_Key, 0x114F, 13);
  addKey("Clear", Clear_Key, 0x1171, 13);
  addKey("VarSlowUp", SlowPlus_Key, 0x1166, 13);
  addKey("VarSlowDn", SlowMinus_Key, 0x1165, 13);
  addKey("Qtr", Unmapped_Key, 0x1167, 13);
  addKey("TrackUp", TrackingPlus_Key, 0x014D, 13);
  addKey("TrackDn", TrackingMinus_Key, 0x014E, 13);
  addKey("GoTo", Unmapped_Key, 0x1173, 13);
  addKey("Memo", Unmapped_Key, 0x117B, 13);
  addKey("Speed", VHSSpeed_Key, 0x117A, 13);
  addKey("VcrTv", Unmapped_Key, 0x117E, 13);
  addKey("2xPlay", Unmapped_Key, 0x116A, 13);
}


MagnavoxConverterBox1::MagnavoxConverterBox1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Settop Box Keyset 1",
      Magnavox_Make,
      index)
{
  addControlledDevice(Magnavox_Make, "TB100MG9", TV_Device);

  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    894, 795,
    894, 2537,
    33751, false,
    LIRC_NEC);

  threadableProtocol = np;

  np->setHeaderPair(3514, 3396);
  np->setTrailerPulse(894);

  addKey("KEY_POWER", Power_Key, 0x541ABE, 24);
  addKey("KEY_1", One_Key, 0x57EA81, 24);
  addKey("KEY_2", Two_Key, 0x561A9E, 24);
  addKey("KEY_3", Three_Key, 0x551AAE, 24);
  addKey("KEY_4", Four_Key, 0x571A8E, 24);
  addKey("KEY_5", Five_Key, 0x549AB6, 24);
  addKey("KEY_6", Six_Key, 0x569A96, 24);
  addKey("KEY_7", Seven_Key, 0x559AA6, 24);
  addKey("KEY_8", Eight_Key, 0x579A86, 24);
  addKey("KEY_9", Nine_Key, 0x545ABA, 24);
  addKey("KEY_0", Zero_Key, 0x565A9A, 24);
  addKey("KEY_OK", Select_Key, 0x55DAA2, 24);
  addKey("KEY_UP", Up_Key, 0x547AB8, 24);
  addKey("KEY_DOWN", Down_Key, 0x567A98, 24);
  addKey("KEY_LEFT", Left_Key, 0x578A87, 24);
  addKey("KEY_RIGHT", Right_Key, 0x558AA7, 24);
  addKey("KEY_CHANNELUP", ChannelUp_Key, 0x542ABD, 24);
  addKey("KEY_CHANNELDOWN", ChannelDown_Key, 0x544ABB, 24);
  addKey("KEY_EPG", Guide_Key, 0x54FAB0, 24);
  addKey("KEY_AUDIO", Unmapped_Key, 0x557AA8, 24);
  addKey("KEY_DOT", Unmapped_Key, 0x56DA92, 24);
  addKey("KEY_SETUP", Menu_Key, 0x57DA82, 24);
  addKey("KEY_PAUSE", Pause_Key, 0x56FA90, 24);
  addKey("KEY_LAST", Unmapped_Key, 0x55CAA3, 24);
  addKey("KEY_BACK", PrevChannel_Key, 0x577A88, 24);
  addKey("KEY_DISPLAY", Info_Key, 0x57CA83, 24);
}


MagnavoxTV1::MagnavoxTV1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV(?) Keyset 1",
      Magnavox_Make,
      index)
{
  threadableProtocol = new RC5Protocol(guiObject, index, 0x40);

  addKey("Zero", Zero_Key, 0x00, 6);
  addKey("One", One_Key, 0x01, 6);
  addKey("Two", Two_Key, 0x02, 6);
  addKey("Three", Three_Key, 0x03, 6);
  addKey("Four", Four_Key, 0x04, 6);
  addKey("Five", Five_Key, 0x05, 6);
  addKey("Six", Six_Key, 0x06, 6);
  addKey("Seven", Seven_Key, 0x07, 6);
  addKey("Eight", Eight_Key, 0x08, 6);
  addKey("Nine", Nine_Key, 0x09, 6);
  addKey("Power", Power_Key, 0x0C, 6);
  addKey("Mute", Mute_Key, 0x0D, 6);
  addKey("Reset", Reset_Key, 0x0E, 6);
  addKey("Status", Unmapped_Key, 0x0F, 6);
  addKey("VolUp", VolumeUp_Key, 0x10, 6);
  addKey("VolDown", VolumeDown_Key, 0x11, 6);
  addKey("Play", Play_Key, 0x1C, 6);
  addKey("Stop", Stop_Key, 0x1D, 6);
  addKey("ChUp", ChannelUp_Key, 0x20, 6);
  addKey("ChDown", ChannelDown_Key, 0x21, 6);
  addKey("PrevCh", PrevChannel_Key, 0x22, 6);
  addKey("Sleep", Sleep_Key, 0x26, 6);
  addKey("Plus", Right_Key, 0x2B, 6);
  addKey("FF", FastForward_Key, 0x2B, 6);
  addKey("Minus", Left_Key, 0x2C, 6);
  addKey("Rev", Rewind_Key, 0x2C, 6);
  addKey("Display", Info_Key, 0x2E, 6);
  addKey("Pause", Pause_Key, 0x3B, 6);
}
