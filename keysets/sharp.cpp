#include "sharp.h"
#include "necprotocol.h"
#include "pirmakenames.h"

SharpTV1::SharpTV1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Sharp_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    350, 650,
    350, 1650,
    64000, true);

  threadableProtocol = np;

  np->setTrailerPulse(350);

//  np->setMinimumRepetitions(1);

//  np->setToggleMask(0x3FF);

  addKey("POWER", Power_Key, 0x41A2, 15);
  addKey("TV/VIDEO", Input_Key, 0x4322, 15);
  addKey("10+", Unmapped_Key, 0x43D2, 15);
  addKey("20+", Unmapped_Key, 0x4032, 15);
  addKey("30+", Unmapped_Key, 0x4232, 15);
  addKey("40+", Unmapped_Key, 0x43C2, 15);
  addKey("1", One_Key, 0x4202, 15);
  addKey("2", Two_Key, 0x4102, 15);
  addKey("3", Three_Key, 0x4302, 15);
  addKey("4", Four_Key, 0x4082, 15);
  addKey("5", Five_Key, 0x4282, 15);
  addKey("6", Six_Key, 0x4242, 15);
  addKey("7", Seven_Key, 0x4382, 15);
  addKey("8", Eight_Key, 0x4042, 15);
  addKey("9", Nine_Key, 0x4242, 15);
  addKey("0", Zero_Key, 0x4142, 15);
  addKey("CH_DOWN", ChannelDown_Key, 0x4122, 15);
  addKey("CH_UP", ChannelUp_Key, 0x4222, 15);
  addKey("TIMER", Sleep_Key, 0x4162, 15);
  addKey("INFO", Info_Key, 0x4362, 15); // "disp_del" "TEXT"
  addKey("CH_SWAP", PrevChannel_Key, 0x4392, 15); // "FLASHBACK", "ret"
  addKey("MUTE", Mute_Key, 0x43A2, 15);  // "VOLUME_KILL"
  addKey("VOL_DOWN", VolumeDown_Key, 0x42A2, 15);
  addKey("VOL_UP", VolumeUp_Key, 0x40A2, 15);
  addKey("stereo", Unmapped_Key, 0x40C2, 15); // "VpsPds"
  addKey("AmPm", Unmapped_Key, 0x40BD, 15);
  addKey("PROG", Program_Key, 0x42E2, 15);
  addKey("MONO", Unmapped_Key, 0x40D2, 15);
  addKey("SOUND_MODE", Unmapped_Key, 0x4062, 15); // I/II/I+II
//  addKey("SINGLE_DOUBLE", DoubleDigit_Key, 0x42B2, 15);
  addKey("TELETEXT", Unmapped_Key, 0x40B2, 15);
  addKey("PICTURE", Unmapped_Key, 0x4132, 15);
  addKey("REVEAL", Unmapped_Key, 0x4072, 15);
  addKey("TOP_BOTTOM_FULL", Unmapped_Key, 0x43B2, 15);
  addKey("HOLD", Unmapped_Key, 0x4332, 15);
  addKey("TIME", Unmapped_Key, 0x40E2, 15);
  addKey("RESET", Unmapped_Key, 0x412A, 15);
  addKey("INDEX", Unmapped_Key, 0x40CA, 15);
  addKey("COLOR_RED", Red_Key, 0x404A, 15);
  addKey("COLOR_GREEN", Green_Key, 0x424A, 15);
  addKey("COLOR_YELLOW", Yellow_Key, 0x414A, 15);
  addKey("COLOR_BLUE", Blue_Key, 0x434A, 15);
  addKey("BROWSE", Unmapped_Key, 0x43D2, 15);
  addKey("BALANCE_LEFT", Unmapped_Key, 0x435A, 15);
  addKey("BALANCE_RIGHT", Unmapped_Key, 0x40DA, 15);
  addKey("TREBLE_DOWN", Unmapped_Key, 0x431A, 15);
  addKey("TREBLE_UP", Unmapped_Key, 0x411A, 15);
  addKey("BASS_DOWN", Unmapped_Key, 0x429A, 15);
  addKey("BASS_UP", Unmapped_Key, 0x409A, 15);
  addKey("WOOFER_DOWN", Unmapped_Key, 0x439A, 15);
  addKey("WOOFER_UP", Unmapped_Key, 0x419A, 15);
  addKey("PICTURE_NORMALIZE", Unmapped_Key, 0x4212, 15);
  addKey("SOUND_NORMALIZE", Unmapped_Key, 0x4192, 15);
  addKey("COLOR_DOWN", Unmapped_Key, 0x4292, 15);
  addKey("COLOR_UP", Unmapped_Key, 0x4092, 15);
  addKey("CONTRAST_DOWN", Unmapped_Key, 0x4312, 15);
  addKey("CONTRAST_UP", Unmapped_Key, 0x4112, 15);
  addKey("BRIGHTNESS_DOWN", Unmapped_Key, 0x4152, 15);
  addKey("BRIGHTNESS_UP", Unmapped_Key, 0x4252, 15);
  addKey("PROGRAM", Program_Key, 0x41B2, 15);
  addKey("calendar", Unmapped_Key, 0x41BA, 15);
  addKey("program_timer", Unmapped_Key, 0x4262, 15); // "on_timer"
  addKey("message", Unmapped_Key, 0x4372, 15);
  addKey("language", Language_Key, 0x407A, 15);
  addKey("100", PlusOneHundred_Key, 0x4342, 15);
  addKey("p/c", Unmapped_Key, 0x42F2, 15);
  addKey("pr", Unmapped_Key, 0x420A, 15);
  addKey("PICTURE", PictureMode_Key, 0x401A, 15);
  addKey("SOUND", SoundMode_Key, 0x421A, 15);
  addKey("FUNCTIONS", Unmapped_Key, 0x43EA, 15);
  addKey("MENU", Menu_Key, 0x42CA, 15);
  addKey("LOCK", Unmapped_Key, 0x422A, 15);
  addKey("./..", DoubleDigit_Key, 0x40F2, 15); // "dual"
  addKey("NR", Unmapped_Key, 0x4022, 15);
  addKey("BACKLIGHT", Unmapped_Key, 0x3F46, 15); // "OPC"
  addKey("ROTATE", Unmapped_Key, 0x3CC6, 15);
  addKey("AV-", Unmapped_Key, 0x473A, 15); // reverse-direction input 
  addKey("BT_END", Unmapped_Key, 0x42BE, 15);
  addKey("SUBTITLE", Captions_Key, 0x3FE6, 15);
  addKey("SUBPAGE", Unmapped_Key, 0x3ECE, 15);
  addKey("DTV", Unmapped_Key, 0x4416, 15);
  addKey("EPG", Guide_Key, 0x44E9, 15);
  addKey("ESG", Unmapped_Key, 0x4796, 15);
  addKey("RADIO", Unmapped_Key, 0x4496, 15);
  addKey("AV_MODE", Unmapped_Key, 0x407E, 15);
  addKey("SURROUND", Surround_Key, 0x41DA, 15);
  addKey("DTV_MENU", Unmapped_Key, 0x4616, 15);
  addKey("LIST", Unmapped_Key, 0x4516, 15);
  addKey("TRUD", Unmapped_Key, 0x46EE, 15);
  addKey("WIDE_MODES", AspectRatio_Key, 0x444E, 15);
  addKey("ACTION", Unmapped_Key, 0x467E, 15);
}


SharpTV1a::SharpTV1a(
  QObject *guiObject,
  unsigned int index)
  : SharpTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1a");

  addKey("Input", Input_Key, 0x40B2, 15);
  addKey("Time", Sleep_Key, 0x41C2, 15);
  addKey("Stop", Stop_Key, 0x4392, 15);
  addKey("REC", Record_Key, 0x4052, 15);
  addKey("Pause", Pause_Key, 0x4292, 15);
  addKey("Play", Play_Key, 0x4112, 15);
  addKey("REW", Rewind_Key, 0x4312, 15);
  addKey("FF", FastForward_Key, 0x4212, 15);
  addKey("TapeSpeed", VHSSpeed_Key, 0x43E2, 15);
  addKey("ZeroBack", Unmapped_Key, 0x4306, 15);
  addKey("Replay", Replay_Key, 0x43DD, 15);
  addKey("SkipSearch", Advance_Key, 0x4026, 15);
  addKey("Slow", Unmapped_Key, 0x4252, 15);
  addKey("DPSS-", Unmapped_Key, 0x4032, 15);
  addKey("DPSS+", Unmapped_Key, 0x43D2, 15);
  addKey("Key", Unmapped_Key, 0x42C2, 15);
}


SharpTV1b::SharpTV1b(
  QObject *guiObject,
  unsigned int index)
  : SharpTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1b");

  addKey("chScan", Scan_Key, 0x40E2, 15);
  addKey("video", Input_Key, 0x424A, 15);
  addKey("minus", Down_Key, 0x402A, 15); // "DOWN"
  addKey("plus", Up_Key, 0x43CA, 15); // "UP"
  addKey("setup", Menu_Key, 0x4012, 15);
  addKey("fback_clr", Unmapped_Key, 0x43D2, 15);
  addKey("FINE_TUNING", Unmapped_Key, 0x41C2, 15);
  addKey("TIMER", Unmapped_Key, 0x432A, 15);
  addKey("BLUE_BACK", Unmapped_Key, 0x4372, 15);
  addKey("SKIP", Unmapped_Key, 0x438A, 15);
  addKey("SYSTEM_SOUND", Unmapped_Key, 0x43DA, 15);
  addKey("SYSTEM_COLOUR", Unmapped_Key, 0x423A, 15);
}


SharpTV1c::SharpTV1c(
  QObject *guiObject,
  unsigned int index)
  : SharpTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1c");

  addKey("save_ch", Unmapped_Key, 0x420A, 15);
  addKey("del_ch", Unmapped_Key, 0x42F2, 15);
}


SharpTV1d::SharpTV1d(
  QObject *guiObject,
  unsigned int index)
  : SharpTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1d");

  addKey("P-MODE", PictureMode_Key, 0x42CA, 15);
  addKey("S-MODE", SoundMode_Key, 0x4192, 15);
}


SharpTV1e::SharpTV1e(
  QObject *guiObject,
  unsigned int index)
  : SharpTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1e");

  addKey("UP", Up_Key, 0x43AA, 15);
  addKey("LEFT", Left_Key, 0x43AE, 15);
  addKey("OK", Select_Key, 0x412A, 15);
  addKey("RIGHT", Right_Key, 0x406E, 15);
  addKey("DOWN", Down_Key, 0x4012, 15);
  addKey("MENU", Menu_Key, 0x458E, 15);
  addKey("RETURN", Exit_Key, 0x409E, 15);
}


SharpVCR1::SharpVCR1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      Sharp_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    400, 600,
    400, 1700,
    64000, true);

  threadableProtocol = np;

  np->setTrailerPulse(400);

//  np->setMinimumRepetitions(1);

//  np->setToggleMask(0x3FF);

  addKey("Power", Power_Key, 0x61A2, 15);
  addKey("1", One_Key, 0x6202, 15);
  addKey("2", Two_Key, 0x6102, 15);
  addKey("3", Three_Key, 0x6302, 15);
  addKey("4", Four_Key, 0x6082, 15);
  addKey("5", Five_Key, 0x6282, 15);
  addKey("6", Six_Key, 0x6182, 15);
  addKey("7", Seven_Key, 0x6382, 15);
  addKey("8", Eight_Key, 0x6042, 15);
  addKey("9", Nine_Key, 0x6242, 15);
  addKey("0", Zero_Key, 0x6142, 15);
  addKey("Play", Play_Key, 0x6112, 15);
  addKey("Stop", Stop_Key, 0x6392, 15);
  addKey("Rec", Record_Key, 0x6052, 15);
  addKey("Pause", Pause_Key, 0x6292, 15);
  addKey("FF", FastForward_Key, 0x6212, 15);
  addKey("Rew", Rewind_Key, 0x6312, 15);
  addKey("./..", DoubleDigit_Key, 0x6342, 15);
  addKey("InputSelect", Input_Key, 0x60B2, 15); // "simul"
  addKey("ChnUp", ChannelUp_Key, 0x6222, 15);
  addKey("ChnDn", ChannelDown_Key, 0x6122, 15);
  addKey("Display", Info_Key, 0x60C6, 15);
  addKey("ModeOsd", Unmapped_Key, 0x62C6, 15);
  addKey("TV/VCR", Unmapped_Key, 0x6322, 15);
  addKey("Menu", Menu_Key, 0x6066, 15);
  addKey("Set", Select_Key, 0x6166, 15);
  addKey("SV/V+/Timer", Unmapped_Key, 0x600E, 15);
  addKey("Clear", Clear_Key, 0x6012, 15);
  addKey("TimerOn/Off", Unmapped_Key, 0x6262, 15);
  addKey("AudioOut", Surround_Key, 0x6062, 15);
  addKey("SkipSearch", Unmapped_Key, 0x6026, 15);
  addKey("ZeroBack", Unmapped_Key, 0x6306, 15);  // "MEMORY"
  addKey("TapeSpeed", VHSSpeed_Key, 0x63E2, 15);
  addKey("Slow", Unmapped_Key, 0x6252, 15);
  addKey("DPSS-", Unmapped_Key, 0x6032, 15); // "slow-"
  addKey("DPSS+", Unmapped_Key, 0x63D2, 15); // "slow+"
  addKey("Key", Unmapped_Key, 0x62C2, 15);  // "C-LOCK", "tamper_proof"
  addKey("Left", Left_Key, 0x62E6, 15);
  addKey("Right", Right_Key, 0x6366, 15);
  addKey("Up", Up_Key, 0x6266, 15);
  addKey("Dn", Down_Key, 0x60E6, 15);
  addKey("EJECT", Eject_Key, 0x6332, 15);
  addKey("MUTE", Mute_Key, 0x63A2, 15);
  addKey("PROG", Program_Key, 0x62E2, 15);
  addKey("TRACKING_DOWN", TrackingMinus_Key, 0x6186, 15);
  addKey("TRACKING_UP", TrackingPlus_Key, 0x6286, 15);
  addKey("CLOCK", Unmapped_Key, 0x60D2, 15);
  addKey("SEARCH", Unmapped_Key, 0x63B2, 15);
  addKey("TIME", Unmapped_Key, 0x61C2, 15);
  addKey("REC_TIME", Unmapped_Key, 0x63C2, 15); // "TIME-0"
  addKey("F.ADV", Unmapped_Key, 0x6092, 15);
  addKey("SHUTTLE0", Unmapped_Key, 0x61D6, 15);
  addKey("SHUTTLE-1", Unmapped_Key, 0x6256, 15);
  addKey("SHUTTLE-2", Unmapped_Key, 0x6356, 15);
  addKey("SHUTTLE+1", Unmapped_Key, 0x6016, 15);
  addKey("SHUTTLE+2", Unmapped_Key, 0x6116, 15);
  addKey("SHUTTLE+3", Unmapped_Key, 0x6096, 15);
  addKey("SHUTTLE+4", Unmapped_Key, 0x6196, 15);
  addKey("SHUTTLE+5", Unmapped_Key, 0x6056, 15);
  addKey("SHUTTLE+6", Unmapped_Key, 0x6156, 15);
  addKey("repeat", Unmapped_Key, 0x6022, 15);
  addKey("osp", Unmapped_Key, 0x60E2, 15);
  addKey("vps", Unmapped_Key, 0x60C2, 15);
  addKey("x2", Unmapped_Key, 0x6232, 15);
  addKey("100", PlusOneHundred_Key, 0x6046, 15);
  addKey("cancel", Unmapped_Key, 0x6086, 15);  // could be exit key
}


SharpReceiver1::SharpReceiver1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Receiver Keyset 1",
      Sharp_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    350, 650,
    350, 1650,
    67000, true);

  threadableProtocol = np;

  np->setTrailerPulse(350);

//  np->setMinimumRepetitions(9);

  addKey("POWER", Power_Key, 0x25A2, 15);
  addKey("X-BASS", Unmapped_Key, 0x25D2, 15);
  addKey("VOL-", VolumeDown_Key, 0x26A2, 15);
  addKey("VOL+", VolumeUp_Key, 0x24A2, 15);
  addKey("CD", Unmapped_Key, 0x2762, 15);
  addKey("TUNER", Unmapped_Key, 0x2662, 15);
  addKey("TAPE", Unmapped_Key, 0x2562, 15);
  addKey("PHONO", Unmapped_Key, 0x26E2, 15);
  addKey("FM", Unmapped_Key, 0x2532, 15);
  addKey("MW", Unmapped_Key, 0x24B2, 15);
  addKey("SW", Unmapped_Key, 0x254E, 15);
  addKey("LW", Unmapped_Key, 0x2732, 15);
  addKey("PRESET-", Unmapped_Key, 0x2522, 15);
  addKey("PRESET+", Unmapped_Key, 0x2622, 15);
  addKey("1", One_Key, 0x1602, 15);
  addKey("2", Two_Key, 0x1502, 15);
  addKey("3", Three_Key, 0x1702, 15);
  addKey("4", Four_Key, 0x1482, 15);
  addKey("5", Five_Key, 0x1682, 15);
  addKey("6", Six_Key, 0x1582, 15);
  addKey("7", Seven_Key, 0x1782, 15);
  addKey("8", Eight_Key, 0x1442, 15);
  addKey("9", Nine_Key, 0x1642, 15);
  addKey("0", Zero_Key, 0x1542, 15);
  addKey("+10", DoubleDigit_Key, 0x1472, 15);
  addKey("MEMORY", Unmapped_Key, 0x1722, 15);
  addKey("REPEAT", Unmapped_Key, 0x15B2, 15);
  addKey("STOP", Stop_Key, 0x146D, 15);
  addKey("PAUSE", Pause_Key, 0x1692, 15);
  addKey("PLAY", Play_Key, 0x1512, 15);
  addKey("REVIEW", Rewind_Key, 0x1562, 15);
  addKey("CUE", FastForward_Key, 0x1662, 15);
  addKey("APSS-", Unmapped_Key, 0x1712, 15);
  addKey("APSS+", Unmapped_Key, 0x1612, 15);
  addKey("CLEAR", Clear_Key, 0x1522, 15);
  addKey("CALL", Unmapped_Key, 0x1622, 15);
  addKey("TIME_DISPLAY", Unmapped_Key, 0x1762, 15);
  addKey("RANDOM", Unmapped_Key, 0x15E2, 15);
}
