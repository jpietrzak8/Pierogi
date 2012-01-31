#include "denon.h"
#include "sharpprotocol.h"
#include "necprotocol.h"

// This whole set of Denon keysets is a mess.  Need to clean it up!!!

DenonDVD1::DenonDVD1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Denon_Make,
      index)
{
  addControlledDevice(Denon_Make, "DVD-1930", DVD_Device);

  threadableProtocol = new SharpProtocol(guiObject, index, false);

  addSharpKey("SEARCH_MODE", Unmapped_Key, 0x04, 0x9E);
  addSharpKey("ZOOM", Zoom_Key, 0x04, 0x9F);

  addSharpKey("POWER_OFF", PowerOff_Key, 0x06, 0xC0);
  addSharpKey("PAGE-", PageDown_Key, 0x06, 0xFD);
  addSharpKey("PAGE+", PageUp_Key, 0x06, 0xFE);
  addSharpKey("GROUP", Unmapped_Key, 0x06, 0xFF);

  addSharpKey("SACD_SETUP", Unmapped_Key, 0x08, 0x7E);
  addSharpKey("0", Zero_Key, 0x08, 0x81);
  addSharpKey("1", One_Key, 0x08, 0x82);
  addSharpKey("2", Two_Key, 0x08, 0x83);
  addSharpKey("3", Three_Key, 0x08, 0x84);
  addSharpKey("4", Four_Key, 0x08, 0x85);
  addSharpKey("5", Five_Key, 0x08, 0x86);
  addSharpKey("6", Six_Key, 0x08, 0x87);
  addSharpKey("7", Seven_Key, 0x08, 0x88);
  addSharpKey("8", Eight_Key, 0x08, 0x89);
  addSharpKey("9", Nine_Key, 0x08, 0x8A);
  addSharpKey("10+", DoubleDigit_Key, 0x08, 0x8C);
  addSharpKey("SUBTITLE", Captions_Key, 0x08, 0x8D);
  addSharpKey("AUDIO", Audio_Key, 0x08, 0x8E);
  addSharpKey("ANGLE", Angle_Key, 0x08, 0x8F);
  addSharpKey("OPEN_CLOSE", Eject_Key, 0x08, 0x90);
  addSharpKey("MENU", DiscMenu_Key, 0x08, 0x91);
  addSharpKey("RETURN", Exit_Key, 0x08, 0x92);
  addSharpKey("REPEAT", Repeat_Key, 0x08, 0x94);
  addSharpKey("SKIP_UP", Previous_Key, 0x08, 0x98);
  addSharpKey("SKIP_DOWN", Next_Key, 0x08, 0x99);
  addSharpKey("FAST_FORWARD", FastForward_Key, 0x08, 0x9A);
  addSharpKey("FAST_REVERSE", Rewind_Key, 0x08, 0x9B);
  addSharpKey("MODE", Unmapped_Key, 0x08, 0x9C);
  addSharpKey("PAUSE", Pause_Key, 0x08, 0x9D);
  addSharpKey("PLAY", Play_Key, 0x08, 0xA0);
  addSharpKey("STOP", Stop_Key, 0x08, 0xA1);
  addSharpKey("CLEAR", Clear_Key, 0x08, 0xA3);
  addSharpKey("DISPLAY", Info_Key, 0x08, 0xA7);
  addSharpKey("RANDOM", Random_Key, 0x08, 0xAA);
  addSharpKey("UP", Up_Key, 0x08, 0xAC);
  addSharpKey("DOWN", Down_Key, 0x08, 0xAD);
  addSharpKey("RIGHT", Right_Key, 0x08, 0xAE);
  addSharpKey("LEFT", Left_Key, 0x08, 0xAF);
  addSharpKey("POWER_ON", PowerOn_Key, 0x08, 0xB2);
  addSharpKey("A_B_REPEAT", RepeatAB_Key, 0x08, 0xBA);
  addSharpKey("ENTER", Select_Key, 0x08, 0xBB);
  addSharpKey("SETUP", Menu_Key, 0x08, 0xBC);
  addSharpKey("TOP_MENU", DiscTitle_Key, 0x08, 0xBD);
}


DenonDVD2::DenonDVD2(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 2",
      Denon_Make,
      index)
{
  addControlledDevice(Denon_Make, "DVD-2500", DVD_Device);

  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    400, 500,
    400, 1400,
    43000, false,
    LIRC_NEC);

  threadableProtocol = np;

  np->setHeaderPair(3500, 1800);
  np->setTrailerPulse(400);

  setPreData(0x40040D00, 32);

  addKey("Power", Power_Key, 0xBCB1, 16);
  addKey("Open/Close", Eject_Key, 0x808D, 16);
  addKey("Stop", Stop_Key, 0x000D, 16);
  addKey("Pause", Pause_Key, 0x606D, 16);
  addKey("Play", Play_Key, 0x505D, 16);
  addKey("SkipBack", Previous_Key, 0x929F, 16);
  addKey("SkipFwd", Next_Key, 0x525F, 16);
  addKey("Rev", Rewind_Key, 0x202D, 16);
  addKey("Fwd", FastForward_Key, 0xA0AD, 16);
  addKey("Title", DiscTitle_Key, 0xD9D4, 16);
  addKey("Menu", DiscMenu_Key, 0x010C, 16);
  addKey("Display", Info_Key, 0x4944, 16);
  addKey("Return", Exit_Key, 0x818C, 16);
  addKey("Up", Up_Key, 0xA1AC, 16);
  addKey("Down", Down_Key, 0x616C, 16);
  addKey("Right", Right_Key, 0x111C, 16);
  addKey("Left", Left_Key, 0xE1EC, 16);
  addKey("Select", Select_Key, 0x414C, 16);
  addKey("Subtitle", Captions_Key, 0x8984, 16);
  addKey("Audio", Audio_Key, 0xCCC1, 16);
  addKey("Angle", Angle_Key, 0x0904, 16);
  addKey("Marker", Unmapped_Key, 0x717C, 16);
  addKey("PlayMode", Unmapped_Key, 0xB1BC, 16);
  addKey("RepeatMode", Repeat_Key, 0x313C, 16);
  addKey("A-B_Repeat", RepeatAB_Key, 0x121F, 16);
  addKey("Setup", Menu_Key, 0x2924, 16);
  addKey("Clear", Clear_Key, 0xC1CC, 16);
  addKey("VSS", Unmapped_Key, 0x7974, 16);
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
  addKey(">=10", DoubleDigit_Key, 0x919C, 16);
}


DenonDVD3::DenonDVD3(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 3",
      Denon_Make,
      index)
{
  addControlledDevice(Denon_Make, "dvd-1000", DVD_Device);

  threadableProtocol = new SharpProtocol(guiObject, index, false);

  addSharpKey("0", Zero_Key, 0x01, 0x81);
  addSharpKey("1", One_Key, 0x01, 0x82);
  addSharpKey("2", Two_Key, 0x01, 0x83);
  addSharpKey("3", Three_Key, 0x01, 0x84);
  addSharpKey("4", Four_Key, 0x01, 0x85);
  addSharpKey("5", Five_Key, 0x01, 0x86);
  addSharpKey("6", Six_Key, 0x01, 0x87);
  addSharpKey("7", Seven_Key, 0x01, 0x88);
  addSharpKey("8", Eight_Key, 0x01, 0x89);
  addSharpKey("9", Nine_Key, 0x01, 0x8A);
  addSharpKey("10", Unmapped_Key, 0x01, 0x8C);
  addSharpKey("subtitle", Captions_Key, 0x01, 0x8D);
  addSharpKey("audio", Audio_Key, 0x01, 0x8E);
  addSharpKey("angle", Angle_Key, 0x01, 0x8F);
  addSharpKey("open-close", Eject_Key, 0x01, 0x90);
  addSharpKey("menu", DiscMenu_Key, 0x01, 0x91);
  addSharpKey("return", Exit_Key, 0x01, 0x92);
  addSharpKey("repeat", Repeat_Key, 0x01, 0x97);
  addSharpKey("skip+", Next_Key, 0x01, 0x98);
  addSharpKey("skip-", Previous_Key, 0x01, 0x99);
  addSharpKey("slow+", SlowPlus_Key, 0x01, 0x9A);
  addSharpKey("slow-", SlowMinus_Key, 0x01, 0x9B);
  addSharpKey("pause", Pause_Key, 0x01, 0x9D);
  addSharpKey("play", Play_Key, 0x01, 0xA0);
  addSharpKey("stop", Stop_Key, 0x01, 0xA1);
  addSharpKey("program", Program_Key, 0x01, 0xA2);
  addSharpKey("clear", Clear_Key, 0x01, 0xA3);
  addSharpKey("display", Info_Key, 0x01, 0xA4);
  addSharpKey("random", Random_Key, 0x01, 0xAA);
  addSharpKey("arrow-up", Up_Key, 0x01, 0xAC);
  addSharpKey("arrow-down", Down_Key, 0x01, 0xAD);
  addSharpKey("arrow-right", Right_Key, 0x01, 0xAE);
  addSharpKey("arrow-left", Left_Key, 0x01, 0xAF);
  addSharpKey("ntsc-pal", Unmapped_Key, 0x01, 0xB7);
  addSharpKey("power", Power_Key, 0x01, 0xB1);
  addSharpKey("repeat-ab", RepeatAB_Key, 0x01, 0xBA);
  addSharpKey("select", Select_Key, 0x01, 0xBB);
  addSharpKey("setup", Menu_Key, 0x01, 0xBC);
  addSharpKey("title", DiscTitle_Key, 0x01, 0xBD);
  addSharpKey("call", Unmapped_Key, 0x01, 0xBE);
}


// This one is messed up:
DenonReceiver1::DenonReceiver1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Receiver Keyset 1",
      Denon_Make,
      index)
{
  addControlledDevice(Denon_Make, "avr-1708", Audio_Device);

  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    400, 700,
    400, 1700,
    67000, true,
    LIRC_NEC);

  threadableProtocol = np;

  np->setElevenBitToggle(true);

  np->setTrailerPulse(400);

  addKey("On", PowerOn_Key, 0x221C, 15);
  addKey("Off", PowerOff_Key, 0x211C, 15);
  addKey("DVD_HDP", Unmapped_Key, 0x231C, 15); // "SRC_DVD"
  addKey("TV_CBL", Unmapped_Key, 0x224C, 15);
  addKey("VCR", Unmapped_Key, 0x22CC, 15);
  addKey("Play", Play_Key, 0x10E8, 15);
  addKey("Stop", Stop_Key, 0x11E8, 15);
  addKey("Skip_Favorite", Favorites_Key, 0x13A8, 15);
  addKey("Pause", Pause_Key, 0x1328, 15);
  addKey("Volume_up", VolumeUp_Key, 0x223C, 15);
  addKey("Volume_down", VolumeDown_Key, 0x213C, 15);
  addKey("Rewind", Rewind_Key, 0x1368, 15);
  addKey("Forward", FastForward_Key, 0x1168, 15);
  addKey("Setup", Menu_Key, 0x206C, 15);
  addKey("Mute", Mute_Key, 0x203C, 15);
  addKey("Night_Audio", Unmapped_Key, 0x1064, 15);
  addKey("Display", Info_Key, 0x23EC, 15); // "onscreen"
  addKey("Enter", Select_Key, 0x201C, 15);
  addKey("Left", Left_Key, 0x1BF8, 15);
  addKey("Up", Up_Key, 0x1B14, 15);
  addKey("Right", Right_Key, 0x22EC, 15);
  addKey("Down", Down_Key, 0x1894, 15);
  addKey("Return", Exit_Key, 0x21EC, 15);
  addKey("Dimmer", Unmapped_Key, 0x1BEC, 15);
}


DenonReceiver1a::DenonReceiver1a(
  QObject *guiObject,
  unsigned int index)
  : DenonReceiver1(guiObject, index)
{
  setKeysetName("Receiver Keyset 1a");

  addControlledDevice(Denon_Make, "AVR-1610", Audio_Device);

  // This keyset may need work, see denon/RC-1120
  addKey("SRC_TV", Unmapped_Key, 0x21B3, 15);
  addKey("SRC_TUNNER", Unmapped_Key, 0x228C, 15);
  addKey("SRC_VAUX", Unmapped_Key, 0x20CC, 15);
  addKey("SRC_HDP", Unmapped_Key, 0x214C, 15);
  addKey("SRC_DVR", Unmapped_Key, 0x2233, 15);
  addKey("SRC_VCR", Unmapped_Key, 0x2133, 15);
  addKey("SRC_SATCBL", Unmapped_Key, 0x204C, 15);
  addKey("BTN_VSEL", Unmapped_Key, 0x2393, 15);
  addKey("BTN_INPUT_MODE", Unmapped_Key, 0x19B4, 15);
  addKey("BTN_MULTEQ", Unmapped_Key, 0x111B, 15);
  addKey("BTN_HDMI_CONTROL", Unmapped_Key, 0x182B, 15);
  addKey("BTN_UP", Up_Key, 0x18EB, 15);
  addKey("BTN_DOWN", Down_Key, 0x1894, 15);
  addKey("BTN_SKIP", Unmapped_Key, 0x18CC, 15);
  addKey("BTN_STOP", Stop_Key, 0x1BAC, 15);
  addKey("BTN_PAUSE", Pause_Key, 0x1ACC, 15);
  addKey("BTN_PLAY", Play_Key, 0x186C, 15);
  addKey("FAST_REVERSE", Rewind_Key, 0x1A93, 15);
  addKey("FAST_FORWARD", FastForward_Key, 0x1A6C, 15);
  addKey("BTN_PREV", Previous_Key, 0x1AAC, 15);
  addKey("BTN_NEXT", Next_Key, 0x19AC, 15);
  addKey("BTN_STD", Unmapped_Key, 0x2363, 15);
  addKey("PAGE_DN", PageDown_Key, 0x1813, 15);
  addKey("PAGE_UP", PageUp_Key, 0x21EC, 15);
  addKey("BTN_STD_CINEMA", Unmapped_Key, 0x115B, 15);
  addKey("BTN_STD_MUSIC", Unmapped_Key, 0x125B, 15);
  addKey("BTN_SIMU", Unmapped_Key, 0x219C, 15);
}


DenonReceiver1b::DenonReceiver1b(
  QObject *guiObject,
  unsigned int index)
  : DenonReceiver1(guiObject, index)
{
  setKeysetName("Receiver Keyset 1b");

  addControlledDevice(Denon_Make, "avr-3300", Audio_Device);

  addKey("vol+", VolumeUp_Key, 0x21C3, 15);
  addKey("channel+", ChannelUp_Key, 0x19AC, 15);
  addKey("channel-", ChannelDown_Key, 0x1AAC, 15);
  addKey("setup", Menu_Key, 0x1814, 15);
  addKey("params", Unmapped_Key, 0x1A14, 15);
  addKey("input-mode", Unmapped_Key, 0x19B4, 15);
  addKey("analog", Unmapped_Key, 0x20EC, 15);
  addKey("ext.in", Unmapped_Key, 0x1AB4, 15);
  addKey("output", Unmapped_Key, 0x1A94, 15);
  addKey("multi", Unmapped_Key, 0x236C, 15);
}


DenonReceiver1c::DenonReceiver1c(
  QObject *guiObject,
  unsigned int index)
  : DenonReceiver1(guiObject, index)
{
  setKeysetName("Receiver Keyset 1c");

  addControlledDevice(Denon_Make, "AVR-1602", Audio_Device);
  addControlledDevice(Denon_Make, "AVR-1802", Audio_Device);
  addControlledDevice(Denon_Make, "AVR-1803", Audio_Device);

  addKey("ONE", One_Key, 0x230C, 15);
  addKey("TWO", Two_Key, 0x208C, 15);
  addKey("THREE", Three_Key, 0x231C, 15);
  addKey("FOUR", Four_Key, 0x20CC, 15);
  addKey("FIVE", Five_Key, 0x22CC, 15);
  addKey("SIX", Six_Key, 0x21CC, 15);
  addKey("SEVEN", Seven_Key, 0x224C, 15);
  addKey("EIGHT", Eight_Key, 0x19B4, 15);
  addKey("NINE", Nine_Key, 0x212C, 15);
  addKey("ZERO", Zero_Key, 0x228C, 15);
  addKey("RCVR_SURROUND_MODE", Unmapped_Key, 0x219C, 15);
  addKey("RCVR_CHANNEL+", ChannelUp_Key, 0x19AC, 15);
  addKey("RCVR_CHANNEL-", ChannelDown_Key, 0x1AAC, 15);
  addKey("VIDEO_SELECT", Unmapped_Key, 0x206C, 15);
  addKey("CD_DISC_SKIP", Unmapped_Key, 0x0B58, 15);
  addKey("CD_PLAY", Unmapped_Key, 0x08E8, 15);
  addKey("CD_PAUSE", Unmapped_Key, 0x0AE8, 15);
  addKey("CD_NEXT", Unmapped_Key, 0x0868, 15);
  addKey("CD_PREV", Unmapped_Key, 0x0A68, 15);
  addKey("CD_STOP", Unmapped_Key, 0x09E8, 15);
  addKey("CD_REW", Unmapped_Key, 0x0B68, 15);
  addKey("CD_FFW", Unmapped_Key, 0x0968, 15);
  addKey("SYSTEM", Menu_Key, 0x1814, 15);
  addKey("RCVR_SURROUND", Surround_Key, 0x1A14, 15);
//  addKey("RCVR_CH_SELECT", Select_Key, 0x201C, 15);
  addKey("RCVR_T_TONE", Unmapped_Key, 0x215C, 15);
  addKey("RCVR_STATUS", Info_Key, 0x21EC, 15);
}


DenonReceiver2::DenonReceiver2(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Receiver Keyset 2",
      Denon_Make,
      index)
{
  threadableProtocol = new SharpProtocol(guiObject, index, false);

  addSharpKey("tun_1", One_Key, 0x13, 0x42);
  addSharpKey("tun_2", Two_Key, 0x13, 0x43);
  addSharpKey("tun_3", Three_Key, 0x13, 0x44);
  addSharpKey("tun_4", Four_Key, 0x13, 0x45);
  addSharpKey("tun_5", Five_Key, 0x13, 0x46);
  addSharpKey("tun_6", Six_Key, 0x13, 0x47);
  addSharpKey("tun_7", Seven_Key, 0x13, 0x48);
  addSharpKey("tun_8", Eight_Key, 0x13, 0x49);
  addSharpKey("tun_shift", TunerBand_Key, 0x13, 0x4A);
  addSharpKey("amp_vol-down", VolumeDown_Key, 0x13, 0x4C);
  addSharpKey("amp_vol-up", VolumeUp_Key, 0x13, 0x4D);
  addSharpKey("amp_power", Power_Key, 0x13, 0x50);
  addSharpKey("amp_phono", Unmapped_Key, 0x13, 0x58);
  addSharpKey("amp_tuner", Unmapped_Key, 0x13, 0x59);
  addSharpKey("amp_aux/video", Unmapped_Key, 0x13, 0x5B);
  addSharpKey("amp_cd", Unmapped_Key, 0x13, 0x5A);
  addSharpKey("amp_tape", Unmapped_Key, 0x13, 0x5D);
  addSharpKey("TUN_CH_DOWN", ChannelDown_Key, 0x13, 0xD5);
  addSharpKey("TUN_CH_UP", ChannelUp_Key, 0x13, 0xD6);

  addSharpKey("CD_REPEAT", Repeat_Key, 0x17, 0x54);
  addSharpKey("cd_next", Next_Key, 0x17, 0x58);
  addSharpKey("cd_prev", Previous_Key, 0x17, 0x59);
  addSharpKey("cd_ff", FastForward_Key, 0x17, 0x5A);
  addSharpKey("cd_rew", Rewind_Key, 0x17, 0x5B);
  addSharpKey("cd_play", Play_Key, 0x17, 0x5C);
  addSharpKey("cd_pause", Pause_Key, 0x17, 0x5D);
  addSharpKey("cd_stop", Stop_Key, 0x17, 0x5E);
  addSharpKey("CD_RANDOM", Random_Key, 0x17, 0x6A);
  addSharpKey("CD_SKIP", Unmapped_Key, 0x17, 0x6B);

  addSharpKey("tape_a/b", Unmapped_Key, 0x1B, 0x53);
  addSharpKey("tape_playrev", Unmapped_Key, 0x1B, 0x57);
  addSharpKey("tape_ff", Unmapped_Key, 0x1B, 0x5A);
  addSharpKey("tape_rew", Unmapped_Key, 0x1B, 0x5B);
  addSharpKey("tape_play", Unmapped_Key, 0x1B, 0x5C);
  addSharpKey("tape_pause", Unmapped_Key, 0x1B, 0x5D);
  addSharpKey("tape_stop", Unmapped_Key, 0x1B, 0x5E);
  addSharpKey("tape_rec", Unmapped_Key, 0x1B, 0x5F);
}


DenonReceiver2a::DenonReceiver2a(
  QObject *guiObject,
  unsigned int index)
  : DenonReceiver2(guiObject, index)
{
  setKeysetName("Receiver Keyset 2a");

  addControlledDevice(Denon_Make, "PMA-425R", Audio_Device);

  addSharpKey("AMP_TAPE2", Unmapped_Key, 0x1D, 0x9A);
  addSharpKey("AMP_TAPE1", Unmapped_Key, 0x1D, 0x99);
  addSharpKey("AMP_AUX", Unmapped_Key, 0x1D, 0x84);
  addSharpKey("AMP_TUNER", Unmapped_Key, 0x1D, 0x73);
  addSharpKey("AMP_CD", Unmapped_Key, 0x1D, 0x82);
  addSharpKey("AMP_PHONO", Unmapped_Key, 0x1D, 0x81);
  addSharpKey("AMP_VOL_UP", VolumeUp_Key, 0x1D, 0x8D);
  addSharpKey("AMP_VOL_DOWN", VolumeDown_Key, 0x1D, 0x8C);
  addSharpKey("AMP_POWER", Power_Key, 0x1D, 0x90);
  addSharpKey("AMP_MUTE", Mute_Key, 0x1D, 0x8B);
}


DenonReceiver3::DenonReceiver3(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Receiver Keyset 3",
      Denon_Make,
      index)
{
  addControlledDevice(Denon_Make, "PMA-480R", Audio_Device);

  threadableProtocol = new SharpProtocol(guiObject, index, false);

  addSharpKey("AMP_PHONO", Unmapped_Key, 0x02, 0x81);
  addSharpKey("AMP_TUNER", Unmapped_Key, 0x02, 0x83);
  addSharpKey("AMP_AUX", Unmapped_Key, 0x02, 0x84);
  addSharpKey("AMP_MUTING", Mute_Key, 0x02, 0x8B);
  addSharpKey("AMP_VOL_DOWN", VolumeDown_Key, 0x02, 0x8C);
  addSharpKey("AMP_VOL_UP", VolumeUp_Key, 0x02, 0x8D);
  addSharpKey("AMP_POWER", Power_Key, 0x02, 0x90);
  addSharpKey("AMP_CD", Unmapped_Key, 0x02, 0x92);
  addSharpKey("AMP_TAPE-1", Unmapped_Key, 0x02, 0x99);
  addSharpKey("AMP_TAPE-2", Unmapped_Key, 0x02, 0x9A);

  addSharpKey("TAPE_A/B", Unmapped_Key, 0x04, 0x53);
  addSharpKey("TAPE_PLAY_REV", Unmapped_Key, 0x04, 0x57);
  addSharpKey("TAPE_FF", Unmapped_Key, 0x04, 0x5A);
  addSharpKey("TAPE_REW", Unmapped_Key, 0x04, 0x5B);
  addSharpKey("TAPE_PLAY", Unmapped_Key, 0x04, 0x5C);
  addSharpKey("TAPE_PAUSE", Unmapped_Key, 0x04, 0x5D);
  addSharpKey("TAPE_STOP", Unmapped_Key, 0x04, 0x5E);
  addSharpKey("TAPE_REC", Unmapped_Key, 0x04, 0x5F);
  addSharpKey("DECK", Unmapped_Key, 0x04, 0x75);

  addSharpKey("REPEAT", Repeat_Key, 0x08, 0x54);
  addSharpKey("CD_NEXT", Next_Key, 0x08, 0x58);
  addSharpKey("CD_BACK", Previous_Key, 0x08, 0x59);
  addSharpKey("CD_FF", FastForward_Key, 0x08, 0x5A);
  addSharpKey("CD_REW", Rewind_Key, 0x08, 0x5B);
  addSharpKey("CD_PLAY", Play_Key, 0x08, 0x5C);
  addSharpKey("CD_PAUSE", Pause_Key, 0x08, 0x5D);
  addSharpKey("CD_STOP", Stop_Key, 0x08, 0x5E);
  addSharpKey("DISC1", One_Key, 0x08, 0x64);
  addSharpKey("DISC2", Two_Key, 0x08, 0x65);
  addSharpKey("DISC3", Three_Key, 0x08, 0x66);
  addSharpKey("DISC4", Four_Key, 0x08, 0x67);
  addSharpKey("DISC5", Five_Key, 0x08, 0x68);
  addSharpKey("DISC6", Six_Key, 0x08, 0x69);
  addSharpKey("random", Random_Key, 0x08, 0x6A);
  addSharpKey("CD", Unmapped_Key, 0x08, 0x73);
  addSharpKey("disksk", DiscSelect_Key, 0x08, 0x6B);

  addSharpKey("panel", Info_Key, 0x0C, 0x7E);
  addSharpKey("TUNER_UP", ChannelUp_Key, 0x0C, 0xD5);
  addSharpKey("TUNER_DOWN", ChannelDown_Key, 0x0C, 0xD6);
  addSharpKey("TUNER", Unmapped_Key, 0x0C, 0xDD);
}


DenonReceiver3a::DenonReceiver3a(
  QObject *guiObject,
  unsigned int index)
  : DenonReceiver3(guiObject, index)
{
  setKeysetName("Receiver Keyset 3a");

  addControlledDevice(Denon_Make, "DRA-385RD", Audio_Device);

  addSharpKey("voldwn", VolumeDown_Key, 0x0C, 0x4C);
  addSharpKey("volup", VolumeUp_Key, 0x0C, 0x4D);
  addSharpKey("preset+", Unmapped_Key, 0x0C, 0x4E);
  addSharpKey("preset-", Unmapped_Key, 0x0C, 0x4F);
  addSharpKey("tape2", Unmapped_Key, 0x0C, 0x5E);
  addSharpKey("video", Unmapped_Key, 0x0C, 0x53);
  addSharpKey("phono", Unmapped_Key, 0x0C, 0x58);
  addSharpKey("tuner", Unmapped_Key, 0x0C, 0x59);
  addSharpKey("cd", Unmapped_Key, 0x0C, 0x5A);
  addSharpKey("tape_mon", Unmapped_Key, 0x0C, 0x5C);
  addSharpKey("tape1", Unmapped_Key, 0x0C, 0x5D);
}


DenonReceiver4::DenonReceiver4(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Receiver Keyset 4",
      Denon_Make,
      index)
{
  addControlledDevice(Denon_Make, "AVR-600 RD", Audio_Device);

  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    561, 489,
    561, 1543,
    67329, true,
    LIRC_NEC);

  threadableProtocol = np;

  np->setTrailerPulse(561);

  addKey("POWER", Power_Key, 0xA20C, 16);
  addKey("UP", Up_Key, 0x99AC, 16);
  addKey("DOWN", Down_Key, 0x9AAC, 16);
  addKey("TUNER", Unmapped_Key, 0xA28C, 16);
  addKey("CD", Unmapped_Key, 0xA08C, 16);
  addKey("PHONO", Unmapped_Key, 0xA30C, 16);
  addKey("VCR", Unmapped_Key, 0xA2CC, 16);
  addKey("TV", Unmapped_Key, 0xA14C, 16);
  addKey("TAPE", Unmapped_Key, 0xA12C, 16);
  addKey("STEREO", Unmapped_Key, 0xA39C, 16);
  addKey("MODE", Unmapped_Key, 0xA19C, 16);
  addKey("TESTTONE", Unmapped_Key, 0xA15C, 16);
  addKey("DELAY", Unmapped_Key, 0xA25C, 16);
  addKey("MUTE", Mute_Key, 0xA03C, 16);
  addKey("PANEL", Info_Key, 0xA1EC, 16);
  addKey("CENTER_UP", Unmapped_Key, 0xA2BC, 16);
  addKey("CENTER_DOWN", Unmapped_Key, 0xA1BC, 16);
  addKey("REAR_UP", Unmapped_Key, 0xA33C, 16);
  addKey("REAR_DOWN", Unmapped_Key, 0xA0BC, 16);
  addKey("VOL_UP", VolumeUp_Key, 0xA23C, 16);
  addKey("VOL_DOWN", VolumeDown_Key, 0xA13C, 16);
}


DenonReceiver5::DenonReceiver5(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Receiver Keyset 5",
      Denon_Make,
      index)
{
  addControlledDevice(Denon_Make, "AVR-700RD", Audio_Device);
  addControlledDevice(Denon_Make, "RC-841", Audio_Device);

  threadableProtocol = new SharpProtocol(guiObject, index, false);

  addSharpKey("Power", Power_Key, 0x02, 0xC1);
  addSharpKey("Phono", Unmapped_Key, 0x02, 0xC3);
  addSharpKey("CD", Unmapped_Key, 0x02, 0xC4);
  addSharpKey("Tuner", Unmapped_Key, 0x02, 0xC5);
  addSharpKey("DVD_TV", Unmapped_Key, 0x02, 0xCA);
  addSharpKey("NoName1", Unmapped_Key, 0x02, 0xCC);
  addSharpKey("VCR", Unmapped_Key, 0x02, 0xCD);
  addSharpKey("DAT_Tape", Unmapped_Key, 0x02, 0xD2);
  addSharpKey("Panel", Info_Key, 0x02, 0xDE);
  addSharpKey("NoName2", Unmapped_Key, 0x02, 0xDF);
  addSharpKey("Mode", Unmapped_Key, 0x02, 0xE6);
  addSharpKey("Stereo", Unmapped_Key, 0x02, 0xE7);
  addSharpKey("Delay", Unmapped_Key, 0x02, 0xE9);
  addSharpKey("Test_Tone", Unmapped_Key, 0x02, 0xEA);
  addSharpKey("Muting", Mute_Key, 0x02, 0xF0);
  addSharpKey("MasterVolumeUp", VolumeUp_Key, 0x02, 0xF1);
  addSharpKey("MasterVolumeDown", VolumeDown_Key, 0x02, 0xF2);
  addSharpKey("RearVolumeUp", Unmapped_Key, 0x02, 0xF3);
  addSharpKey("RearVolumeDown", Unmapped_Key, 0x02, 0xF4);
  addSharpKey("CenterVolumeUp", Unmapped_Key, 0x02, 0xF5);
  addSharpKey("CenterVolumeDown", Unmapped_Key, 0x02, 0xF6);

  addSharpKey("Deck_A_B", Unmapped_Key, 0x04, 0x53);
  addSharpKey("Deck_PlayLeft", Unmapped_Key, 0x04, 0x57);
  addSharpKey("Deck_FastForward", Unmapped_Key, 0x04, 0x5A);
  addSharpKey("Deck_Rewind", Unmapped_Key, 0x04, 0x5B);
  addSharpKey("Deck_PlayRight", Unmapped_Key, 0x04, 0x5C);
  addSharpKey("Deck_Stop", Unmapped_Key, 0x04, 0x5E);

  addSharpKey("CD_Next", Next_Key, 0x08, 0x58);
  addSharpKey("CD_Prev", Previous_Key, 0x08, 0x59);
  addSharpKey("CD_Pause", Pause_Key, 0x08, 0x5B);
  addSharpKey("CD_Play", Play_Key, 0x08, 0x5C);
  addSharpKey("CD_Stop", Stop_Key, 0x08, 0x5E);
  addSharpKey("CD_Disc_Skip_Plus", DiscSelect_Key, 0x08, 0x6B);

  addSharpKey("Preset_Down", ChannelDown_Key, 0x0C, 0xB5);
  addSharpKey("Preset_Up", ChannelUp_Key, 0x0C, 0xB6);
  addSharpKey("Shift", TunerBand_Key, 0x0C, 0xCD);
}


DenonAudio1::DenonAudio1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 1",
      Denon_Make,
      index)
{
  addControlledDevice(Denon_Make, "HiFi 110", Audio_Device);
  addControlledDevice(Denon_Make, "DRM-550", Audio_Device);
  addControlledDevice(Denon_Make, "DCD-335", Audio_Device);
  addControlledDevice(Denon_Make, "DRA-275RD", Audio_Device);
  addControlledDevice(Denon_Make, "UD-M30", Audio_Device);

  threadableProtocol = new SharpProtocol(guiObject, index, false);

  addSharpKey("reset", Reset_Key, 0x04, 0x54);
  addSharpKey("TAPE REW", Unmapped_Key, 0x04, 0x57); // "TAPE_PLAY_REV"
  addSharpKey("TAPE FAST FWD", Unmapped_Key, 0x04, 0x5A); // "TAPE_FORW"
  addSharpKey("TAPE FAST REW", Unmapped_Key, 0x04, 0x5B); // "TAPE_REW"
  addSharpKey("TAPE FWD", Unmapped_Key, 0x04, 0x5C); // "TAPE_PLAY_FORW"
  addSharpKey("TAPE STOP", Unmapped_Key, 0x04, 0x5E);
  addSharpKey("tapesize", Unmapped_Key, 0x04, 0x60);
  addSharpKey("revmode", Unmapped_Key, 0x04, 0x62);
  addSharpKey("TAPE_AB", Unmapped_Key, 0x04, 0x63);
  addSharpKey("TAPE 2 REW", Unmapped_Key, 0x04, 0x67);
  addSharpKey("TAPE 2 FAST FWD", Unmapped_Key, 0x04, 0x6A);
  addSharpKey("TAPE 2 FAST REW", Unmapped_Key, 0x04, 0x6B);
  addSharpKey("TAPE 2 FWD", Unmapped_Key, 0x04, 0x6C);
  addSharpKey("TAPE_PAUSE", Unmapped_Key, 0x04, 0x6D);
  addSharpKey("TAPE 2 STOP", Unmapped_Key, 0x04, 0x6E);
  addSharpKey("KEY_RECORD", Record_Key, 0x04, 0x6F);
  addSharpKey("remain", Unmapped_Key, 0x04, 0x74);

  addSharpKey("KEY_1", One_Key, 0x08, 0x42);
  addSharpKey("KEY_2", Two_Key, 0x08, 0x43);
  addSharpKey("KEY_3", Three_Key, 0x08, 0x44);
  addSharpKey("KEY_4", Four_Key, 0x08, 0x45);
  addSharpKey("KEY_5", Five_Key, 0x08, 0x46);
  addSharpKey("KEY_6", Six_Key, 0x08, 0x47);
  addSharpKey("KEY_7", Seven_Key, 0x08, 0x48);
  addSharpKey("KEY_8", Eight_Key, 0x08, 0x49);
  addSharpKey("KEY_9", Nine_Key, 0x08, 0x4A);
  addSharpKey("10", Zero_Key, 0x08, 0x4B);
  addSharpKey("+10", DoubleDigit_Key, 0x08, 0x4C);
  addSharpKey("KEY_PROGRAM", Program_Key, 0x08, 0x4D);
  addSharpKey("open_close", Eject_Key, 0x08, 0x50);
  addSharpKey("KEY_CANCEL", Clear_Key, 0x08, 0x51); // "cancel", "CD_CANCEL"
  addSharpKey("time", Unmapped_Key, 0x08, 0x53); // "CD_TIME"
  addSharpKey("repeat", Repeat_Key, 0x08, 0x54); // "CD_REPEAT"
  addSharpKey("DIRECT", Unmapped_Key, 0x08, 0x57); // "direct"
  addSharpKey("KEY_NEXT", Next_Key, 0x08, 0x58); // "cdfwd", "cdnexttrack"
  addSharpKey("KEY_PREVIOUS", Previous_Key, 0x08, 0x59); // "cdrew", "cdprevtrack"
  addSharpKey("KEY_FORWARD", FastForward_Key, 0x08, 0x5A); // "cdffwd"
  addSharpKey("KEY_REWIND", Rewind_Key, 0x08, 0x5B); // "cdfrew"
  addSharpKey("KEY_PLAY", Play_Key, 0x08, 0x5C); // "cdplay"
  addSharpKey("KEY_PAUSE", Pause_Key, 0x08, 0x5D); // "cdpause"
  addSharpKey("KEY_STOP", Stop_Key, 0x08, 0x5E); // "CD_STOP"
  addSharpKey("auto_space", Unmapped_Key, 0x08, 0x61);
  addSharpKey("auto_edit", Unmapped_Key, 0x08, 0x63);
  addSharpKey("random", Random_Key, 0x08, 0x6A); // "CD_RANDOM"
  addSharpKey("cdskip", Unmapped_Key, 0x08, 0x6B);
  addSharpKey("DISC_SKIP+", DiscSelect_Key, 0x08, 0x6B); // "cdskip"
  addSharpKey("DISC_SKIP-", Unmapped_Key, 0x08, 0x6E);
  addSharpKey("peak", Unmapped_Key, 0x08, 0x6F);
  addSharpKey("edit", Unmapped_Key, 0x08, 0x70); // "CD_EDIT"
  addSharpKey("fader", Unmapped_Key, 0x08, 0x76);
  addSharpKey("pitch+", Unmapped_Key, 0x08, 0x77);
  addSharpKey("pitch-", Unmapped_Key, 0x08, 0x78);
  addSharpKey("SDB", Unmapped_Key, 0x08, 0xEA);

  addSharpKey("KEY_VOLUMEDOWN", VolumeDown_Key, 0x0C, 0x4C);
  addSharpKey("KEY_VOLUMEUP", VolumeUp_Key, 0x0C, 0x4D);
  addSharpKey("PRESET UP", Up_Key, 0x0C, 0x4E); // "up"
  addSharpKey("PRESET DOWN", Down_Key, 0x0C, 0x4F); // "dwn"
  addSharpKey("KEY_POWER", Power_Key, 0x0C, 0x50); // "aus"
  addSharpKey("RCVR_VIDEO", Unmapped_Key, 0x0C, 0x53);
  addSharpKey("RCVR_PHONO", Unmapped_Key, 0x0C, 0x58);
  addSharpKey("tuner", Unmapped_Key, 0x0C, 0x59); // "RCVR_TUNER"
  addSharpKey("RCVR_TAPE_MON", Unmapped_Key, 0x0C, 0x5C);
  addSharpKey("RCVR_TAPE1", Unmapped_Key, 0x0C, 0x5D);
  addSharpKey("RCVR_TAPE2", Unmapped_Key, 0x0C, 0x5E);
  addSharpKey("KEY_FN", Unmapped_Key, 0x0C, 0x5F); // "func"
  addSharpKey("RCVR_CD", Unmapped_Key, 0x0C, 0x6A);
  addSharpKey("KEY_SLEEP", Sleep_Key, 0x0C, 0x72);
//  addSharpKey("RCVR_PANEL", Info_Key, 0x0C, 0x7E);  // Either 0x7E or 0xDE here
  addSharpKey("memo", Unmapped_Key, 0x0C, 0xD1);
  addSharpKey("RDS", Unmapped_Key, 0x0C, 0xD2); // "TUNER_RDS"
  addSharpKey("CT", Unmapped_Key, 0x0C, 0xD3); // "TUNER_CT"
  addSharpKey("pty", Unmapped_Key, 0x0C, 0xD4); // "TUNER_PTY"
  addSharpKey("TUNER BAND", Unmapped_Key, 0x0C, 0xD7);
  addSharpKey("TUNER KEY_UP", ChannelUp_Key, 0x0C, 0xD9);
  addSharpKey("TUNER KEY_DOWN", ChannelDown_Key, 0x0C, 0xDA);
  addSharpKey("panel", Info_Key, 0x0C, 0xDE);
  addSharpKey("eon", Unmapped_Key, 0x0C, 0xFE);
}


DenonAudio1a::DenonAudio1a(
  QObject *guiObject,
  unsigned int index)
  : DenonAudio1(guiObject, index)
{
  setKeysetName("Audio Keyset 1a");

  addControlledDevice(Denon_Make, "UCD-F07", Audio_Device);
  addControlledDevice(Denon_Make, "UDR-F07", Audio_Device);
  addControlledDevice(Denon_Make, "UDRA-F07", Audio_Device);

  addSharpKey("rec", Record_Key, 0x04, 0x5F);
  addSharpKey("side_a/b", Unmapped_Key, 0x08, 0x53);
}


DenonAudio1b::DenonAudio1b(
  QObject *guiObject,
  unsigned int index)
  : DenonAudio1(guiObject, index)
{
  setKeysetName("Audio Keyset 1b");

  addControlledDevice(Denon_Make, "DCD-1015", Audio_Device);
  addControlledDevice(Denon_Make, "DCD-655", Audio_Device);

  addSharpKey("vol_up", VolumeUp_Key, 0x08, 0x4E);
  addSharpKey("vol_down", VolumeDown_Key, 0x08, 0x4F);
  addSharpKey("display", Info_Key, 0x08, 0x75);
}


DenonAudio1c::DenonAudio1c(
  QObject *guiObject,
  unsigned int index)
  : DenonAudio1b(guiObject, index)
{
  setKeysetName("Audio Keyset 1c");

  addControlledDevice(Denon_Make, "DCM-260", Audio_Device);

  addSharpKey("DISC_SELECT", DiscSelect_Key, 0x08, 0x62);
}


DenonAudio1d::DenonAudio1d(
  QObject *guiObject,
  unsigned int index)
  : DenonAudio1(guiObject, index)
{
  setKeysetName("Audio Keyset 1d");

  addControlledDevice(Denon_Make, "UDRA-M7", Audio_Device);
  addControlledDevice(Denon_Make, "UPA-F88", Audio_Device);
  addControlledDevice(Denon_Make, "UCD-F88", Audio_Device);
  addControlledDevice(Denon_Make, "UDR-F88", Audio_Device);
  addControlledDevice(Denon_Make, "UTU-F88", Audio_Device);
  addControlledDevice(Denon_Make, "RC-846", Audio_Device);

  addSharpKey("TAPE_REC", Record_Key, 0x04, 0x5F);

  addSharpKey("MD_STOP", Unmapped_Key, 0x06, 0xE1);
  addSharpKey("MD_PLAY", Unmapped_Key, 0x06, 0xE2);
  addSharpKey("MD_REC", Unmapped_Key, 0x06, 0xE5);
  addSharpKey("MD_SEARCH_NEXT", Unmapped_Key, 0x06, 0xE9);
  addSharpKey("MD_SEARCH_PREVIOUS", Unmapped_Key, 0x06, 0xEA);
}


DenonAudio2::DenonAudio2(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 2",
      Denon_Make,
      index)
{
  addControlledDevice(Denon_Make, "D-C30", Audio_Device);

  threadableProtocol = new NECProtocol(guiObject, index, Standard_NEC);

//  setPreData(0xDA25, 16);
  setPreData(0x5B, 8);

  addKey("Power", Power_Key, 0x00, 8);
  addKey("Volume_Up", VolumeUp_Key, 0x01, 8);
  addKey("Volume_Down", VolumeDown_Key, 0x02, 8);
  addKey("Remain", Unmapped_Key, 0x03, 8);
  addKey("A.Edit", Unmapped_Key, 0x04, 8);
  addKey("Tuner_Band", TunerBand_Key, 0x07, 8);
  addKey("Tape_1/2", Unmapped_Key, 0x09, 8);
  addKey("P.Mode", Unmapped_Key, 0x0B, 8);
  addKey("EQ_Pattern", Unmapped_Key, 0x11, 8);
  addKey("CD_Play", Play_Key, 0x12, 8);
  addKey("CD_Stop", Stop_Key, 0x13, 8);
  addKey("Skip_Forward", Next_Key, 0x14, 8);
  addKey("Skip_Backward", Previous_Key, 0x15, 8);
  addKey("Prog", Program_Key, 0x16, 8);
  addKey("Repeat", Repeat_Key, 0x17, 8);
  addKey("Open/Close", Eject_Key, 0x18, 8);
  addKey("Fast_Forward", FastForward_Key, 0x1B, 8);
  addKey("Fast_Rewind", Rewind_Key, 0x1C, 8);
  addKey("Stop", Unmapped_Key, 0x1D, 8);
  addKey("Play_Forward", Unmapped_Key, 0x19, 8);
  addKey("Record_Pause", Unmapped_Key, 0x1F, 8);
  addKey("1", One_Key, 0x4D, 8);
  addKey("2", Two_Key, 0x4E, 8);
  addKey("3", Three_Key, 0x4F, 8);
  addKey("4", Four_Key, 0x50, 8);
  addKey("5", Five_Key, 0x51, 8);
  addKey("6", Six_Key, 0x52, 8);
  addKey("7", Seven_Key, 0x53, 8);
  addKey("8", Eight_Key, 0x54, 8);
  addKey("9", Nine_Key, 0x55, 8);
  addKey("10", Unmapped_Key, 0x56, 8);
  addKey("10+/12", DoubleDigit_Key, 0x57, 8);
  addKey("Random", Random_Key, 0x5A, 8);
  addKey("0/11", Zero_Key, 0x5B, 8);
  addKey("Disc", Unmapped_Key, 0x5E, 8);
  addKey("Play_Backward", Unmapped_Key, 0xD2, 8);
}


DenonAudio3::DenonAudio3(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 3",
      Denon_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    336, 717,
    336, 1773,
    67458, true,
    LIRC_NEC);

  threadableProtocol = np;

  np->setElevenBitToggle(true);

  np->setTrailerPulse(336);

  addKey("open_close", Eject_Key, 0x8828, 15);
  addKey("call", Unmapped_Key, 0x8928, 15);
  addKey("prog", Program_Key, 0x8B08, 15);
  addKey("direct", Unmapped_Key, 0x8BA8, 15);
  addKey("1", One_Key, 0x8908, 15);
  addKey("2", Two_Key, 0x8B08, 15);
  addKey("3", Three_Key, 0x8888, 15);
  addKey("4", Four_Key, 0x8A88, 15);
  addKey("5", Five_Key, 0x8988, 15);
  addKey("6", Six_Key, 0x8B88, 15);
  addKey("7", Seven_Key, 0x8848, 15);
  addKey("8", Eight_Key, 0x8A48, 15);
  addKey("9", Nine_Key, 0x8948, 15);
  addKey("10", Zero_Key, 0x8B48, 15);
  addKey("+10", DoubleDigit_Key, 0x88C8, 15);
  addKey("play", Play_Key, 0x88E8, 15);
  addKey("vol_up", VolumeUp_Key, 0x89C8, 15);
  addKey("vol_down", VolumeDown_Key, 0x8BC8, 15);
  addKey("pause", Pause_Key, 0x8AE8, 15);
  addKey("stop", Stop_Key, 0x89E8, 15);
  addKey("a_space", Unmapped_Key, 0x8A18, 15);
  addKey("all", Unmapped_Key, 0x88A8, 15);
  addKey("a-b", Unmapped_Key, 0x8AA8, 15);
  addKey("rewind", Rewind_Key, 0x8B68, 15);
  addKey("wind", FastForward_Key, 0x8968, 15);
  addKey("prev", Previous_Key, 0x8A68, 15);
  addKey("next", Next_Key, 0x8868, 15);
}


DenonAudio4::DenonAudio4(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 4",
      Denon_Make,
      index)
{
  addControlledDevice(Denon_Make, "DMD-800", Audio_Device);

  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    275, 775,
    275, 1900,
    43000, false,
    LIRC_NEC);

  threadableProtocol = np;

  np->setElevenBitToggle(true);

  np->setTrailerPulse(275);

  addKey("EJECT", Eject_Key, 0x319C, 15);
  addKey("POWER", Power_Key, 0x301C, 15);
  addKey("PLAY", Play_Key, 0x311C, 15);
  addKey("PAUSE", Pause_Key, 0x331C, 15);
  addKey("STOP", Stop_Key, 0x321C, 15);
  addKey("REC", Record_Key, 0x329C, 15);
  addKey("1", One_Key, 0x320C, 15);
  addKey("2", Two_Key, 0x310C, 15);
  addKey("3", Three_Key, 0x330C, 15);
  addKey("4", Four_Key, 0x308C, 15);
  addKey("5", Five_Key, 0x328C, 15);
  addKey("6", Six_Key, 0x318C, 15);
  addKey("7", Seven_Key, 0x338C, 15);
  addKey("8", Eight_Key, 0x304C, 15);
  addKey("9", Nine_Key, 0x324C, 15);
  addKey("10", Zero_Key, 0x314C, 15);
  addKey("+10", DoubleDigit_Key, 0x305C, 15);
  addKey("CALL", Unmapped_Key, 0x31BC, 15);
  addKey("PREV_TRACK", Previous_Key, 0x315C, 15);
  addKey("NEXT_TRACK", Next_Key, 0x325C, 15);
  addKey("BACK", Replay_Key, 0x30DC, 15);
  addKey("FORWARD", Advance_Key, 0x335C, 15);
  addKey("CLEAR", Clear_Key, 0x33EC, 15);
  addKey("PROG", Program_Key, 0x303C, 15);
  addKey("REPEAT", Repeat_Key, 0x323C, 15);
  addKey("RANDOM", Random_Key, 0x333C, 15);
  addKey("EDIT", Unmapped_Key, 0x33DC, 15);
  addKey("ENTER", Select_Key, 0x31EC, 15);
  addKey("TIME", Unmapped_Key, 0x30BC, 15);
  addKey("CHAR", Unmapped_Key, 0x32EC, 15);
  addKey("TITLE", Unmapped_Key, 0x32BC, 15);
}


DenonAudio5::DenonAudio5(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 5",
      Denon_Make,
      index)
{
  addControlledDevice(Denon_Make, "D-G1MD", Audio_Device);

  threadableProtocol = new NECProtocol(guiObject, index, Extended_NEC);

//  setPreData(0x4040, 16);
  setPreData(0x0202, 16);

  addKey("fm/am", Unmapped_Key, 0x00, 8);
  addKey("rds", Unmapped_Key, 0x01, 8);
  addKey("1", One_Key, 0x02, 8);
  addKey("6", Six_Key, 0x03, 8);
  addKey("+10", DoubleDigit_Key, 0x04, 8);
  addKey("mdrec", Unmapped_Key, 0x05, 8);
  addKey("recmute", Unmapped_Key, 0x06, 8);
  addKey("edit", Unmapped_Key, 0x07, 8);
  addKey("tape", Unmapped_Key, 0x08, 8);
  addKey("pty", Unmapped_Key, 0x09, 8);
  addKey("2", Two_Key, 0x0A, 8);
  addKey("7", Seven_Key, 0x0B, 8);
  addKey("+100", PlusOneHundred_Key, 0x0C, 8);
  addKey("pickrec", Unmapped_Key, 0x0D, 8);
  addKey("revmode", Unmapped_Key, 0x0E, 8);
  addKey("editcancel", Unmapped_Key, 0x0F, 8);
  addKey("cd", Unmapped_Key, 0x10, 8);
  addKey("ct", Unmapped_Key, 0x11, 8);
  addKey("3", Three_Key, 0x12, 8);
  addKey("8", Eight_Key, 0x13, 8);
  addKey("clock", Unmapped_Key, 0x14, 8);
  addKey("checkspace", Unmapped_Key, 0x15, 8);
  addKey("dolby", Unmapped_Key, 0x16, 8);
  addKey("prog", Program_Key, 0x17, 8);
  addKey("aux", Unmapped_Key, 0x18, 8);
  addKey("rt", Unmapped_Key, 0x19, 8);
  addKey("4", Four_Key, 0x1A, 8);
  addKey("9", Nine_Key, 0x1B, 8);
  addKey("timer", Timer_Key, 0x1C, 8);
  addKey("clear", Clear_Key, 0x1D, 8);
  addKey("titleinput", Unmapped_Key, 0x1E, 8);
  addKey("vol-", VolumeDown_Key, 0x1F, 8);
  addKey("md", Unmapped_Key, 0x40, 8);
  addKey("fmmode", Unmapped_Key, 0x41, 8);
  addKey("5", Five_Key, 0x42, 8);
  addKey("0", Zero_Key, 0x43, 8);
  addKey("sleep", Sleep_Key, 0x44, 8);
  addKey("set", Unmapped_Key, 0x45, 8);
  addKey("enter", Enter_Key, 0x46, 8);
  addKey("5modesrs", Surround_Key, 0x47, 8);
  addKey("titlesearch", Unmapped_Key, 0x48, 8);
  addKey("vol+", VolumeUp_Key, 0x49, 8);
  addKey("repeat", Repeat_Key, 0x4A, 8);
  addKey("random", Random_Key, 0x4B, 8);
  addKey("power", Power_Key, 0x4C, 8);
  addKey("timedisp", Info_Key, 0x4D, 8);
  addKey("eqmode", Unmapped_Key, 0x4E, 8);
  addKey("mute", Mute_Key, 0x4F, 8);
  addKey("bass", Unmapped_Key, 0x50, 8);
  addKey("forward", FastForward_Key, 0x51, 8);
  addKey("prev", Previous_Key, 0x52, 8);
  addKey("next", Next_Key, 0x53, 8);
  addKey("backward", Rewind_Key, 0x56, 8);
  addKey("stop", Stop_Key, 0x57, 8);
}
