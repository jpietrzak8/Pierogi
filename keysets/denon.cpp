#include "denon.h"
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

  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    349, 647,
    349, 1689,
    65002, true); // 43802 between?

  threadableProtocol = np;

  np->setElevenBitToggle(true);

  np->setTrailerPulse(349);

//  np->setCarrierFrequency(26500); //?

  addKey("POWER_ON", Unmapped_Key, 0x0A34, 15);
  addKey("POWER_OFF", Unmapped_Key, 0x300C, 15);
  addKey("MODE", Unmapped_Key, 0x08E4, 15);
  addKey("OPEN_CLOSE", Eject_Key, 0x0824, 15);
  addKey("A_B_REPEAT", Unmapped_Key, 0x0974, 15);
  addKey("REPEAT", Unmapped_Key, 0x08A4, 15);
  addKey("RANDOM", Unmapped_Key, 0x0954, 15);
  addKey("ZOOM", Unmapped_Key, 0x13E4, 15);
  addKey("CLEAR", Clear_Key, 0x0B14, 15);
  addKey("1", One_Key, 0x0904, 15);
  addKey("2", Two_Key, 0x0B04, 15);
  addKey("3", Three_Key, 0x0884, 15);
  addKey("4", Four_Key, 0x0A84, 15);
  addKey("5", Five_Key, 0x0984, 15);
  addKey("6", Six_Key, 0x0B84, 15);
  addKey("7", Seven_Key, 0x0844, 15);
  addKey("8", Eight_Key, 0x0A44, 15);
  addKey("9", Nine_Key, 0x0944, 15);
  addKey("0", Zero_Key, 0x0A04, 15);
  addKey("10+", DoubleDigit_Key, 0x08C4, 15);
  addKey("ANGLE", Unmapped_Key, 0x0BC4, 15);
  addKey("SUBTITLE", Captions_Key, 0x0AC4, 15);
  addKey("AUDIO", Language_Key, 0x09C4, 15);
  addKey("DISPLAY", Info_Key, 0x0B94, 15);
  addKey("MENU", DiscMenu_Key, 0x0A24, 15);
  addKey("TOP_MENU", DiscTitle_Key, 0x0AF4, 15);
  addKey("UP", Up_Key, 0x08D4, 15);
  addKey("DOWN", Down_Key, 0x0AD4, 15);
  addKey("LEFT", Left_Key, 0x0BD4, 15);
  addKey("RIGHT", Right_Key, 0x09D4, 15);
  addKey("ENTER", Select_Key, 0x0B74, 15);
  addKey("RETURN", Exit_Key, 0x0924, 15);
  addKey("SETUP", Menu_Key, 0x08F4, 15);
  addKey("SEARCH_MODE", Unmapped_Key, 0x11E4, 15);
  addKey("SKIP_DOWN", Next_Key, 0x0A64, 15);
  addKey("SKIP_UP", Previous_Key, 0x0864, 15);
  addKey("FAST_REVERSE", Rewind_Key, 0x0B64, 15);
  addKey("STOP", Stop_Key, 0x0A14, 15);
  addKey("PLAY", Play_Key, 0x0814, 15);
  addKey("FAST_FORWARD", FastForward_Key, 0x0964, 15);
  addKey("PAUSE", Pause_Key, 0x0AE4, 15);
  addKey("GROUP", Unmapped_Key, 0x33FC, 15);
  addKey("SACD_SETUP", Unmapped_Key, 0x09F8, 15);
  addKey("PAGE+", Unmapped_Key, 0x31FC, 15);
  addKey("PAGE-", Unmapped_Key, 0x32FC, 15);
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
    43000, false);

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
  addKey("Audio", Language_Key, 0xCCC1, 16);
  addKey("Angle", Unmapped_Key, 0x0904, 16);
  addKey("Marker", Unmapped_Key, 0x717C, 16);
  addKey("PlayMode", Unmapped_Key, 0xB1BC, 16);
  addKey("RepeatMode", Unmapped_Key, 0x313C, 16);
  addKey("A-B_Repeat", Unmapped_Key, 0x121F, 16);
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
      "DVD Keyset 3 (odd)",
      Denon_Make,
      index)
{
  addControlledDevice(Denon_Make, "dvd-1000", DVD_Device);

  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    275, 776,
    275, 1829,
    67389, true);

  threadableProtocol = np;

  np->setElevenBitToggle(true);

  np->setTrailerPulse(275);

//  np->setCarrierFrequency(32000);

  addKey("power", Power_Key, 0x09CB, 15);
  addKey("1", One_Key, 0x0AFB, 15);
  addKey("2", Two_Key, 0x0B04, 15);
  addKey("3", Three_Key, 0x0884, 15);
  addKey("4", Four_Key, 0x097B, 15);
  addKey("5", Five_Key, 0x0A7B, 15);
  addKey("6", Six_Key, 0x0B84, 15);
  addKey("7", Seven_Key, 0x0844, 15);
  addKey("8", Eight_Key, 0x0A44, 15);
  addKey("9", Nine_Key, 0x0ABB, 15);
  addKey("0", Zero_Key, 0x09FB, 15);
  addKey("10", Unmapped_Key, 0x0B3B, 15);
  addKey("clear", Clear_Key, 0x08EB, 15);
  addKey("skip-", Previous_Key, 0x099B, 15);
  addKey("skip+", Next_Key, 0x0B9B, 15);
  addKey("slow-", Unmapped_Key, 0x089B, 15);
  addKey("slow+", Unmapped_Key, 0x0A9B, 15);
  addKey("stop", Stop_Key, 0x09EB, 15);
  addKey("pause", Pause_Key, 0x091B, 15);
  addKey("play", Play_Key, 0x0814, 15);
  addKey("title", DiscTitle_Key, 0x090B, 15);
  addKey("menu", DiscMenu_Key, 0x09DB, 15);
  addKey("return", Exit_Key, 0x0ADB, 15);
  addKey("display", Info_Key, 0x086B, 15);
  addKey("select", Select_Key, 0x088B, 15);
  addKey("arrow-up", Up_Key, 0x0B2B, 15);
  addKey("arrow-down", Down_Key, 0x092B, 15);
  addKey("arrow-left", Left_Key, 0x082B, 15);
  addKey("arrow-right", Right_Key, 0x0A2B, 15);
  addKey("subtitle", Captions_Key, 0x093B, 15);
  addKey("audio", Language_Key, 0x0A3B, 15);
  addKey("angle", Unmapped_Key, 0x083B, 15);
  addKey("setup", Menu_Key, 0x0B0B, 15);
  addKey("repeat", Repeat_Key, 0x0B5B, 15);
  addKey("repeat-ab", Unmapped_Key, 0x0A8B, 15);
  addKey("random", Random_Key, 0x0AAB, 15);
  addKey("call", Unmapped_Key, 0x0A0B, 15);
  addKey("program", Program_Key, 0x0AEB, 15);
  addKey("open-close", Eject_Key, 0x0BDB, 15);
  addKey("ntsc-pal", Unmapped_Key, 0x084B, 15);
}


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
    67000, true);

  threadableProtocol = np;

  np->setElevenBitToggle(true);

  np->setTrailerPulse(400);

  addKey("On", Unmapped_Key, 0x221C, 15);
  addKey("Off", Unmapped_Key, 0x211C, 15);
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
  addKey("PAGE_DN", Unmapped_Key, 0x1813, 15);
  addKey("PAGE_UP", Unmapped_Key, 0x21EC, 15);
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
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    315, 740,
    315, 1812,
    45920, false);

  threadableProtocol = np;

  np->setElevenBitToggle(true);

  np->setTrailerPulse(315);

  addKey("amp_power", Power_Key, 0x67D7, 15);
  addKey("amp_vol-down", VolumeDown_Key, 0x6737, 15);
  addKey("amp_vol-up", VolumeUp_Key, 0x6537, 15);
  addKey("amp_tape", Unmapped_Key, 0x6517, 15);
  addKey("amp_aux/video", Unmapped_Key, 0x6497, 15);
  addKey("amp_tuner", Unmapped_Key, 0x6597, 15);
  addKey("amp_cd", Unmapped_Key, 0x6697, 15);
  addKey("amp_phono", Unmapped_Key, 0x6797, 15);
  addKey("tun_1", Unmapped_Key, 0x66F7, 15);
  addKey("tun_2", Unmapped_Key, 0x64F7, 15);
  addKey("tun_3", Unmapped_Key, 0x6777, 15);
  addKey("tun_4", Unmapped_Key, 0x6577, 15);
  addKey("tun_5", Unmapped_Key, 0x6677, 15);
  addKey("tun_6", Unmapped_Key, 0x6477, 15);
  addKey("tun_7", Unmapped_Key, 0x67B7, 15);
  addKey("tun_8", Unmapped_Key, 0x65B7, 15);
  addKey("tun_shift", Unmapped_Key, 0x66B7, 15);
  addKey("cd_pause", Pause_Key, 0x76E8, 15);
  addKey("cd_stop", Stop_Key, 0x7617, 15);
  addKey("cd_play", Play_Key, 0x7717, 15);
  addKey("cd_rew", Rewind_Key, 0x7497, 15);
  addKey("cd_ff", FastForward_Key, 0x7697, 15);
  addKey("cd_prev", Previous_Key, 0x7597, 15);
  addKey("cd_next", Next_Key, 0x7797, 15);
  addKey("CD_RANDOM", Random_Key, 0x76A7, 15);
  addKey("CD_REPEAT", Repeat_Key, 0x7757, 15);
  addKey("CD_SKIP", Unmapped_Key, 0x74A7, 15);
  addKey("tape_pause", Unmapped_Key, 0x6D17, 15);
  addKey("tape_stop", Unmapped_Key, 0x6E17, 15);
  addKey("tape_playrev", Unmapped_Key, 0x6C57, 15);
  addKey("tape_play", Unmapped_Key, 0x6F17, 15);
  addKey("tape_rec", Unmapped_Key, 0x6C17, 15);
  addKey("tape_a/b", Unmapped_Key, 0x6CD7, 15);
  addKey("tape_rew", Unmapped_Key, 0x6C97, 15);
  addKey("tape_ff", Unmapped_Key, 0x6E97, 15);
}


DenonReceiver2a::DenonReceiver2a(
  QObject *guiObject,
  unsigned int index)
  : DenonReceiver2(guiObject, index)
{
  setKeysetName("Receiver Keyset 2a");

  addControlledDevice(Denon_Make, "PMA-425R", Audio_Device);

  addKey("AMP_TAPE2", Unmapped_Key, 0x5E9B, 15);
  addKey("AMP_TAPE1", Unmapped_Key, 0x5D9B, 15);
  addKey("AMP_AUX", Unmapped_Key, 0x5F7B, 15);
  addKey("AMP_TUNER", Unmapped_Key, 0x5CE3, 15);
  addKey("AMP_CD", Unmapped_Key, 0x5EFB, 15);
  addKey("AMP_PHONO", Unmapped_Key, 0x5DFB, 15);
  addKey("AMP_VOL_UP", VolumeUp_Key, 0x5D3B, 15);
  addKey("AMP_VOL_DOWN", VolumeDown_Key, 0x5F3B, 15);
  addKey("AMP_POWER", Power_Key, 0x5FDB, 15);
  addKey("AMP_MUTE", Mute_Key, 0x5CBB, 15);
  addKey("TUN_CH_UP", ChannelUp_Key, 0x6653, 15);
  addKey("TUN_CH_DOWN", ChannelDown_Key, 0x6553, 15);
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

  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    400, 600,
    400, 1700,
    67400, true);

  threadableProtocol = np;

  np->setElevenBitToggle(true);

  np->setTrailerPulse(400);

  addKey("TUNER", Unmapped_Key, 0x1AEC, 15);
  addKey("DECK", Unmapped_Key, 0x12B8, 15);
  addKey("CD", Unmapped_Key, 0x0B38, 15);
  addKey("CD_PLAY", Play_Key, 0x08E8, 15);
  addKey("CD_PAUSE", Pause_Key, 0x0AE8, 15);
  addKey("CD_STOP", Stop_Key, 0x09E8, 15);
  addKey("CD_REW", Rewind_Key, 0x0B68, 15);
  addKey("CD_FF", FastForward_Key, 0x0968, 15);
  addKey("CD_BACK", Previous_Key, 0x0A68, 15);
  addKey("CD_NEXT", Next_Key, 0x0868, 15);
  addKey("DISC1", Unmapped_Key, 0x0898, 15);
  addKey("DISC2", Unmapped_Key, 0x0A98, 15);
  addKey("DISC3", Unmapped_Key, 0x0998, 15);
  addKey("DISC4", Unmapped_Key, 0x0B98, 15);
  addKey("DISC5", Unmapped_Key, 0x0858, 15);
  addKey("DISC6", Unmapped_Key, 0x0A58, 15);
  addKey("REPEAT", Repeat_Key, 0x08A8, 15);
  addKey("TAPE_A/B", Unmapped_Key, 0x1328, 15);
  addKey("TAPE_PAUSE", Unmapped_Key, 0x12E8, 15);
  addKey("TAPE_STOP", Unmapped_Key, 0x11E8, 15);
  addKey("TAPE_REC", Unmapped_Key, 0x13E8, 15);
  addKey("TAPE_REW", Unmapped_Key, 0x1368, 15);
  addKey("TAPE_FF", Unmapped_Key, 0x1168, 15);
  addKey("TAPE_PLAY_REV", Unmapped_Key, 0x13A8, 15);
  addKey("TAPE_PLAY", Unmapped_Key, 0x10E8, 15);
  addKey("TUNER_UP", ChannelUp_Key, 0x1AAC, 15);
  addKey("TUNER_DOWN", ChannelDown_Key, 0x19AC, 15);
  addKey("AMP_POWER", Power_Key, 0x2024, 15);
  addKey("AMP_CD", Unmapped_Key, 0x2104, 15);
  addKey("AMP_PHONO", Unmapped_Key, 0x2204, 15);
  addKey("AMP_AUX", Unmapped_Key, 0x2084, 15);
  addKey("AMP_TUNER", Unmapped_Key, 0x2304, 15);
  addKey("AMP_TAPE-2", Unmapped_Key, 0x2164, 15);
  addKey("AMP_TAPE-1", Unmapped_Key, 0x2264, 15);
  addKey("AMP_MUTING", Mute_Key, 0x20BB, 15);
  addKey("AMP_VOL_UP", VolumeUp_Key, 0x22C4, 15);
  addKey("AMP_VOL_DOWN", VolumeDown_Key, 0x20C4, 15);
}


DenonReceiver3a::DenonReceiver3a(
  QObject *guiObject,
  unsigned int index)
  : DenonReceiver3(guiObject, index)
{
  setKeysetName("Receiver Keyset 3a");

  addControlledDevice(Denon_Make, "DRA-385RD", Audio_Device);

  addKey("random", Random_Key, 0x0958, 15);
  addKey("repeat", Repeat_Key, 0x0B57, 15);
  addKey("disksk", Unmapped_Key, 0x0B58, 15);
  addKey("panel", Info_Key, 0x19F8, 15);
  addKey("tape_mon", Unmapped_Key, 0x18E8, 15);
  addKey("tape2", Unmapped_Key, 0x19E8, 15);
  addKey("tape1", Unmapped_Key, 0x1AE8, 15);
  addKey("video", Unmapped_Key, 0x1B28, 15);
  addKey("tuner", Unmapped_Key, 0x1A68, 15);
  addKey("cd", Unmapped_Key, 0x1968, 15);
  addKey("phono", Unmapped_Key, 0x1868, 15);
  addKey("preset+", Unmapped_Key, 0x1A37, 15);
  addKey("preset-", Unmapped_Key, 0x1BC8, 15);
  addKey("volup", VolumeUp_Key, 0x1937, 15);
  addKey("voldwn", VolumeDown_Key, 0x18C8, 15);
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
    67329, true);

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

  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    336, 715,
    336, 1769,
    67376, true);

  threadableProtocol = np;

  np->setElevenBitToggle(true);

  np->setTrailerPulse(337);

  addKey("Power", Power_Key, 0x220C, 15);
  addKey("CD_Disc_Skip_Plus", Unmapped_Key, 0x0B58, 15);
  addKey("CD_Stop", Stop_Key, 0x09E8, 15);
  addKey("CD_Play", Play_Key, 0x08E8, 15);
  addKey("CD_Prev", Previous_Key, 0x0A68, 15);
  addKey("CD_Pause", Pause_Key, 0x0AE8, 15);
  addKey("CD_Next", Next_Key, 0x0868, 15);
  addKey("Preset_Up", Unmapped_Key, 0x19AC, 15);
  addKey("Preset_Down", Unmapped_Key, 0x1AAC, 15);
  addKey("Shift", Unmapped_Key, 0x1ACC, 15);
  addKey("Tuner", Unmapped_Key, 0x228C, 15);
  addKey("CD", Unmapped_Key, 0x208C, 15);
  addKey("Phono", Unmapped_Key, 0x230C, 15);
  addKey("VCR", Unmapped_Key, 0x22CC, 15);
  addKey("DVD_TV", Unmapped_Key, 0x214C, 15);
  addKey("NoName1", Unmapped_Key, 0x20CC, 15);
  addKey("DAT_Tape", Unmapped_Key, 0x212C, 15);
  addKey("Stereo", Unmapped_Key, 0x239C, 15);
  addKey("Mode", Unmapped_Key, 0x219C, 15);
  addKey("Test_Tone", Unmapped_Key, 0x215C, 15);
  addKey("Delay", Unmapped_Key, 0x225C, 15);
  addKey("CenterVolumeUp", Unmapped_Key, 0x22BC, 15);
  addKey("CenterVolumeDown", Unmapped_Key, 0x21BC, 15);
  addKey("RearVolumeUp", Unmapped_Key, 0x233C, 15);
  addKey("RearVolumeDown", Unmapped_Key, 0x20BC, 15);
  addKey("Muting", Mute_Key, 0x203C, 15);
  addKey("NoName2", Unmapped_Key, 0x23EC, 15);
  addKey("Panel", Info_Key, 0x21EC, 15);
  addKey("MasterVolumeUp", VolumeUp_Key, 0x223C, 15);
  addKey("MasterVolumeDown", VolumeDown_Key, 0x213C, 15);
  addKey("Deck_PlayLeft", Unmapped_Key, 0x13A8, 15);
  addKey("Deck_Stop", Unmapped_Key, 0x11E8, 15);
  addKey("Deck_PlayRight", Unmapped_Key, 0x10E8, 15);
  addKey("Deck_Rewind", Unmapped_Key, 0x1368, 15);
  addKey("Deck_A_B", Unmapped_Key, 0x1328, 15);
  addKey("Deck_FastForward", Unmapped_Key, 0x1168, 15);
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

  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    300, 750,
    300, 1800,
    67500, true);

  threadableProtocol = np;

  np->setElevenBitToggle(true);

  np->setTrailerPulse(300);

  addKey("KEY_POWER", Power_Key, 0x1828, 15); // "aus"
  addKey("KEY_SLEEP", Sleep_Key, 0x1938, 15);
  addKey("KEY_FN", Unmapped_Key, 0x1BE8, 15); // "func"
  addKey("KEY_STOP", Stop_Key, 0x09E8, 15); // "CD_STOP"
  addKey("KEY_PLAY", Play_Key, 0x08E8, 15); // "cdplay"
  addKey("KEY_PAUSE", Pause_Key, 0x0AE8, 15); // "cdpause"
  addKey("KEY_REWIND", Rewind_Key, 0x0B68, 15); // "cdfrew"
  addKey("KEY_FORWARD", FastForward_Key, 0x0968, 15); // "cdffwd"
  addKey("KEY_PREVIOUS", Previous_Key, 0x0A68, 15); // "cdrew", "cdprevtrack"
  addKey("KEY_NEXT", Next_Key, 0x0868, 15); // "cdfwd", "cdnexttrack"
  addKey("KEY_1", One_Key, 0x0908, 15);
  addKey("KEY_2", Two_Key, 0x0B08, 15);
  addKey("KEY_3", Three_Key, 0x0888, 15);
  addKey("KEY_4", Four_Key, 0x0A88, 15);
  addKey("KEY_5", Five_Key, 0x0988, 15);
  addKey("KEY_6", Six_Key, 0x0B88, 15);
  addKey("KEY_7", Seven_Key, 0x0BB7, 15);
  addKey("KEY_8", Eight_Key, 0x0A48, 15);
  addKey("KEY_9", Nine_Key, 0x0948, 15);
  addKey("10", Zero_Key, 0x0B48, 15);
  addKey("+10", DoubleDigit_Key, 0x08C8, 15);
  addKey("DIRECT", Unmapped_Key, 0x0BA8, 15); // "direct"
  addKey("KEY_PROGRAM", Program_Key, 0x0AC8, 15);
  addKey("KEY_CANCEL", Clear_Key, 0x0A28, 15); // "cancel", "CD_CANCEL"
  addKey("TUNER BAND", Unmapped_Key, 0x1BAC, 15);
  addKey("TUNER KEY_DOWN", ChannelDown_Key, 0x196C, 15);
  addKey("TUNER KEY_UP", ChannelUp_Key, 0x1A6C, 15);
  addKey("CT", Unmapped_Key, 0x1B2C, 15); // "TUNER_CT"
  addKey("RDS", Unmapped_Key, 0x192C, 15); // "TUNER_RDS"
  addKey("PRESET DOWN", Down_Key, 0x1BC8, 15); // "dwn"
  addKey("PRESET UP", Up_Key, 0x19C8, 15); // "up"
  addKey("TAPE REW", Unmapped_Key, 0x13A8, 15); // "TAPE_PLAY_REV"
  addKey("TAPE FWD", Unmapped_Key, 0x10E8, 15); // "TAPE_PLAY_FORW"
  addKey("TAPE FAST REW", Unmapped_Key, 0x1368, 15); // "TAPE_REW"
  addKey("TAPE FAST FWD", Unmapped_Key, 0x1168, 15); // "TAPE_FORW"
  addKey("TAPE STOP", Unmapped_Key, 0x11E8, 15);
  addKey("TAPE 2 REW", Unmapped_Key, 0x1398, 15);
  addKey("TAPE 2 FWD", Unmapped_Key, 0x10D8, 15);
  addKey("TAPE 2 FAST REW", Unmapped_Key, 0x1358, 15);
  addKey("TAPE 2 FAST FWD", Unmapped_Key, 0x1158, 15);
  addKey("TAPE 2 STOP", Unmapped_Key, 0x11D8, 15);
  addKey("KEY_RECORD", Record_Key, 0x13D8, 15);
  addKey("SDB", Unmapped_Key, 0x095C, 15);
  addKey("KEY_VOLUMEDOWN", VolumeDown_Key, 0x18C8, 15);
  addKey("KEY_VOLUMEUP", VolumeUp_Key, 0x1AC8, 15);
  addKey("cdskip", Unmapped_Key, 0x0B58, 15);
  addKey("tuner", Unmapped_Key, 0x1A68, 15);
  addKey("repeat", Repeat_Key, 0x08A8, 15); // "CD_REPEAT"
  addKey("random", Random_Key, 0x0958, 15); // "CD_RANDOM"
  addKey("programm", Program_Key, 0x0AC8, 15);
  addKey("edit", Unmapped_Key, 0x0838, 15); // "CD_EDIT"
  addKey("time", Unmapped_Key, 0x0B28, 15); // "CD_TIME"
  addKey("reset", Reset_Key, 0x10A8, 15);
  addKey("remain", Unmapped_Key, 0x10B8, 15);
  addKey("tapesize", Unmapped_Key, 0x1018, 15);
  addKey("revmode", Unmapped_Key, 0x1118, 15);
  addKey("memo", Unmapped_Key, 0x1A2C, 15);
  addKey("pty", Unmapped_Key, 0x18AC, 15); // "TUNER_PTY"
  addKey("panel", Info_Key, 0x19EC, 15);
  addKey("eon", Unmapped_Key, 0x1BBC, 15);
  addKey("auto_space", Unmapped_Key, 0x0A18, 15);
  addKey("auto_edit", Unmapped_Key, 0x0B18, 15);
  addKey("open_close", Eject_Key, 0x0828, 15);
  addKey("fader", Unmapped_Key, 0x09B8, 15);
  addKey("pitch-", Unmapped_Key, 0x0878, 15);
  addKey("pitch+", Unmapped_Key, 0x0BB8, 15);
  addKey("peak", Unmapped_Key, 0x0BD8, 15);
  addKey("TAPE_AB", Unmapped_Key, 0x1328, 15);
  addKey("TAPE_PAUSE", Unmapped_Key, 0x12E8, 15);
  addKey("RCVR_PANEL", Info_Key, 0x19F8, 15);
  addKey("RCVR_TAPE_MON", Unmapped_Key, 0x18E8, 15);
  addKey("RCVR_TAPE2", Unmapped_Key, 0x19E8, 15);
  addKey("RCVR_TAPE1", Unmapped_Key, 0x1AE8, 15);
  addKey("RCVR_VIDEO", Unmapped_Key, 0x1B28, 15);
  addKey("RCVR_TUNER", Unmapped_Key, 0x1A68, 15);
  addKey("RCVR_CD", Unmapped_Key, 0x1A97, 15);
  addKey("RCVR_PHONO", Unmapped_Key, 0x1868, 15);
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

  addKey("rec", Record_Key, 0x13E8, 15);
  addKey("side_a/b", Unmapped_Key, 0x0B28, 15);
  addKey("cdstop", Stop_Key, 0x0A17, 15);
}


DenonAudio1b::DenonAudio1b(
  QObject *guiObject,
  unsigned int index)
  : DenonAudio1(guiObject, index)
{
  setKeysetName("Audio Keyset 1b");

  addControlledDevice(Denon_Make, "DCD-1015", Audio_Device);
  addControlledDevice(Denon_Make, "DCD-655", Audio_Device);

  addKey("vol_down", VolumeDown_Key, 0x0BC8, 15);
  addKey("vol_up", VolumeUp_Key, 0x09C8, 15);
  addKey("display", Info_Key, 0x0AB8, 15);
}


DenonAudio1c::DenonAudio1c(
  QObject *guiObject,
  unsigned int index)
  : DenonAudio1b(guiObject, index)
{
  setKeysetName("Audio Keyset 1c (odd)");

  addControlledDevice(Denon_Make, "DCM-260", Audio_Device);

  addKey("RANDOM", Random_Key, 0x0AA7, 15);
  addKey("2", Two_Key, 0x08F7, 15);
  addKey("DISC_SELECT", Unmapped_Key, 0x0918, 15);
//  addKey("DISC_SKIP+", Unmapped_Key, 0x0B58, 15); // already in parent...
  addKey("DISC_SKIP-", Unmapped_Key, 0x0A27, 15); // not in parent
  addKey("|<<", Previous_Key, 0x0997, 15);
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

  addKey("TAPE_REC", Record_Key, 0x13E8, 15);
  addKey("MD_PLAY", Unmapped_Key, 0x311C, 15);
  addKey("MD_STOP", Unmapped_Key, 0x321C, 15);
  addKey("MD_REC", Unmapped_Key, 0x329C, 15);
  addKey("MD_SEARCH_NEXT", Unmapped_Key, 0x325C, 15);
  addKey("MD_SEARCH_PREVIOUS", Unmapped_Key, 0x315C, 15);
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

  threadableProtocol = new NECProtocol(guiObject, index);

  setPreData(0xDA25, 16);

  addKey("Power", Power_Key, 0x00FF, 16);
  addKey("Tuner_Band", Unmapped_Key, 0xE01F, 16);
  addKey("EQ_Pattern", Unmapped_Key, 0x8877, 16);
  addKey("Open/Close", Eject_Key, 0x18E7, 16);
  addKey("1", One_Key, 0xB24D, 16);
  addKey("2", Two_Key, 0x728D, 16);
  addKey("3", Three_Key, 0xF20D, 16);
  addKey("4", Four_Key, 0x0AF5, 16);
  addKey("5", Five_Key, 0x8A75, 16);
  addKey("6", Six_Key, 0x4AB5, 16);
  addKey("7", Seven_Key, 0xCA35, 16);
  addKey("8", Eight_Key, 0x2AD5, 16);
  addKey("9", Nine_Key, 0xAA55, 16);
  addKey("10", Unmapped_Key, 0x6A95, 16);
  addKey("0/11", Zero_Key, 0xDA25, 16);
  addKey("10+/12", DoubleDigit_Key, 0xEA15, 16);
  addKey("Record_Pause", Unmapped_Key, 0xF807, 16);
  addKey("Play_Backward", Unmapped_Key, 0x4B87, 16);
  addKey("Stop", Unmapped_Key, 0xB847, 16);
  addKey("Play_Forward", Unmapped_Key, 0x9867, 16);
  addKey("A.Edit", Unmapped_Key, 0x20DF, 16);
  addKey("Fast_Rewind", Unmapped_Key, 0x38C7, 16);
  addKey("Fast_Forward", Unmapped_Key, 0xD827, 16);
  addKey("Tape_1/2", Unmapped_Key, 0x906F, 16);
  addKey("Remain", Unmapped_Key, 0xC03F, 16);
  addKey("Random", Random_Key, 0x5AA5, 16);
  addKey("Prog", Program_Key, 0x6897, 16);
  addKey("Disc", Unmapped_Key, 0x7A85, 16);
  addKey("Skip_Backward", Previous_Key, 0xA857, 16);
  addKey("Skip_Forward", Next_Key, 0x28D7, 16);
  addKey("CD_Stop", Stop_Key, 0xC837, 16);
  addKey("CD_Play", Play_Key, 0x48B7, 16);
  addKey("P.Mode", Unmapped_Key, 0xD02F, 16);
  addKey("Repeat", Repeat_Key, 0xE817, 16);
  addKey("Volume_Down", VolumeDown_Key, 0x40BF, 16);
  addKey("Volume_Up", VolumeUp_Key, 0x807F, 16);
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
    67458, true);

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
    43000, false);

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

  threadableProtocol = new NECProtocol(guiObject, index);

  setPreData(0x4040, 16);

  addKey("fm/am", Unmapped_Key, 0x00FF, 16);
  addKey("tape", Unmapped_Key, 0x10EF, 16);
  addKey("cd", Unmapped_Key, 0x08F7, 16);
  addKey("md", Unmapped_Key, 0x02FD, 16);
  addKey("aux", Unmapped_Key, 0x18E7, 16);
  addKey("rds", Unmapped_Key, 0x807F, 16);
  addKey("pty", Unmapped_Key, 0x906F, 16);
  addKey("ct", Unmapped_Key, 0x8877, 16);
  addKey("rt", Unmapped_Key, 0x9867, 16);
  addKey("fmmode", Unmapped_Key, 0x827D, 16);
  addKey("1", One_Key, 0x40BF, 16);
  addKey("2", Two_Key, 0x50AF, 16);
  addKey("3", Three_Key, 0x48B7, 16);
  addKey("4", Four_Key, 0x58A7, 16);
  addKey("5", Five_Key, 0x42BD, 16);
  addKey("6", Six_Key, 0xC03F, 16);
  addKey("7", Seven_Key, 0xD02F, 16);
  addKey("8", Eight_Key, 0xC837, 16);
  addKey("9", Nine_Key, 0xD827, 16);
  addKey("0", Zero_Key, 0xC23D, 16);
  addKey("+10", DoubleDigit_Key, 0x20DF, 16);
  addKey("+100", PlusOneHundred_Key, 0x30CF, 16);
  addKey("clock", Unmapped_Key, 0x28D7, 16);
  addKey("timer", Unmapped_Key, 0x38C7, 16);
  addKey("sleep", Sleep_Key, 0x22DD, 16);
  addKey("set", Unmapped_Key, 0xA25D, 16);
  addKey("mdrec", Unmapped_Key, 0xA05F, 16);
  addKey("pickrec", Unmapped_Key, 0xB04F, 16);
  addKey("checkspace", Unmapped_Key, 0xA857, 16);
  addKey("clear", Clear_Key, 0xB847, 16);
  addKey("enter", Enter_Key, 0x629D, 16);
  addKey("recmute", Unmapped_Key, 0x609F, 16);
  addKey("revmode", Unmapped_Key, 0x708F, 16);
  addKey("dolby", Unmapped_Key, 0x6897, 16);
  addKey("5modesrs", Surround_Key, 0xE21D, 16);
  addKey("edit", Unmapped_Key, 0xE01F, 16);
  addKey("editcancel", Unmapped_Key, 0xF00F, 16);
  addKey("titleinput", Unmapped_Key, 0x7887, 16);
  addKey("titlesearch", Unmapped_Key, 0x12ED, 16);
  addKey("edit", Unmapped_Key, 0xE01F, 16);
  addKey("repeat", Repeat_Key, 0x52AD, 16);
  addKey("random", Random_Key, 0xD22D, 16);
  addKey("prog", Program_Key, 0xE817, 16);
  addKey("vol-", VolumeDown_Key, 0xF807, 16);
  addKey("vol+", VolumeUp_Key, 0x926D, 16);
  addKey("power", Power_Key, 0x32CD, 16);
  addKey("mute", Mute_Key, 0xF20D, 16);
  addKey("bass", Unmapped_Key, 0x0AF5, 16);
  addKey("eqmode", Unmapped_Key, 0x728D, 16);
  addKey("timedisp", Info_Key, 0xB24D, 16);
  addKey("forward", FastForward_Key, 0x8A75, 16);
  addKey("prev", Previous_Key, 0x4AB5, 16);
  addKey("stop", Stop_Key, 0xEA15, 16);
  addKey("next", Next_Key, 0xCA35, 16);
  addKey("backward", Rewind_Key, 0x6A95, 16);
}
