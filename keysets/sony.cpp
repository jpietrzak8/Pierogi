#include "sony.h"
#include "necprotocol.h"


SonyTV1::SonyTV1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Sony_Make,
      index)
{
  addControlledDevice(Sony_Make, "Trinitron KDW-25", TV_Device);

  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    600, 600,
    1200, 600,
    45000, true);

  threadableProtocol = np;

  np->setHeaderPair(2400, 600);

  np->setMinimumRepetitions(2);

  //np->setCarrierFrequency(40000);
  //np->setDutyCycle(33);

  addKey("MUTE", Mute_Key, 0x290, 12); // 0x148
  addKey("POWER", Power_Key, 0xA90, 12); // 0x548
  addKey("TV-RETURN", Unmapped_Key, 0x1D0, 12); // teletext 0x0E8, also "analog"
  addKey("TELETXT", Unmapped_Key, 0xFD0, 12);   // teletext 0x7E8
  addKey("tv/video", Input_Key, 0xA50, 12); // 0x528
  addKey("1", One_Key, 0x010, 12);   // 0x008
  addKey("2", Two_Key, 0x810, 12);   // 0x408
  addKey("3", Three_Key, 0x410, 12); // 0x208
  addKey("4", Four_Key, 0xC10, 12);  // 0x608
  addKey("5", Five_Key, 0x210, 12);  // 0x108
  addKey("6", Six_Key, 0xA10, 12);   // 0x508
  addKey("7", Seven_Key, 0x610, 12); // 0x308
  addKey("8", Eight_Key, 0xE10, 12); // 0x708
  addKey("9", Nine_Key, 0x110, 12);  // 0x088
  addKey("0", Zero_Key, 0x910, 12);  // 0x488
  addKey("?/INFO", Info_Key, 0x5D0, 12); // 0x2E8
  addKey("-/--", DoubleDigit_Key, 0xB90, 12); // 0x5C8
  addKey("OK", Select_Key, 0xA70, 12); // 0x538
//  addKey("OK", Enter_Key, 0xA70, 12); // 0x538
  addKey("MENU", Menu_Key, 0x070, 12); //0x038
  addKey("UP/GREEN", Up_Key, 0xB38, 12); // 0x59C
  addKey("DOWN/BLUE", Down_Key, 0xF38, 12); // 0x79C
  addKey("RIGHT/+/YELLOW", Right_Key, 0x738, 12); // 0x39C
  addKey("LEFT/-/RED", Left_Key, 0x338, 12); // 0x19C
  addKey("LEFT/-/RED", Red_Key, 0x338, 12); // 0x19C
  addKey("UP/GREEN", Green_Key, 0xB38, 12); // 0x59C
  addKey("RIGHT/+/YELLOW", Yellow_Key, 0x738, 12); //0x39C
  addKey("DOWN/BLUE", Blue_Key, 0xF38, 12); // 0x79C
  addKey("VOLUME+", VolumeUp_Key, 0x490, 12); // 0x248
  addKey("VOLUME-", VolumeDown_Key, 0xC90, 12); // 0x648
  addKey("CHANNEL/PAGE+", ChannelUp_Key, 0x090, 12); // 0x048
  addKey("CHANNEL/PAGE-", ChannelDown_Key, 0x890, 12); // 0x448
  addKey("prev_ch", PrevChannel_Key, 0xDD0, 12); // 0x6E8 "jump", "refresh", "toggle"
  addKey("1-", Unmapped_Key, 0x310, 12);
  addKey("2-", Unmapped_Key, 0xB10, 12);
  addKey("sleep", Sleep_Key, 0x6D0, 12); // 0x368
  addKey("select", Unmapped_Key, 0x3F0, 12); // 0x1F8
  addKey("normalise", Unmapped_Key, 0x690, 12); // 0x348 "reset"
  addKey("C", Clear_Key, 0x710, 12); // 0x388
  addKey("output", Unmapped_Key, 0x670, 12);  // 0x338
  addKey("a/b", Language_Key, 0xE90, 12); // 0x748  "mts", "sap", "audio", "language"
  addKey("stereo", Surround_Key, 0x950, 12); // Might be wrong
  addKey("subtitles", Captions_Key, 0xD38, 12);
  addKey("expand", Unmapped_Key, 0x938, 12);
  addKey("shrink", Unmapped_Key, 0x538, 12);
  addKey("favourite", Unmapped_Key, 0x530, 12);
  addKey("setup", Program_Key, 0x370, 12);
  addKey("tune_down", Unmapped_Key, 0xF70, 12);
  addKey("tune_up", Unmapped_Key, 0x770, 12);
  addKey("diamond", Unmapped_Key, 0x1F0, 12); // 0x0F8 "add"
  addKey("asterisk", Unmapped_Key, 0x170, 12);
  addKey("C00", Unmapped_Key, 0xF10, 12);
  addKey("bucket", Unmapped_Key, 0x150, 12);
  addKey("vt_inf", Unmapped_Key, 0x138, 12); // teletext info
//  addKey("vt_dots", Unmapped_Key, 0xD38, 12); // teletext
  addKey("time", Unmapped_Key, 0xD50, 12); // 0x6A8 teletext?
  addKey("timer/block", Unmapped_Key, 0x0D0, 12); // 0x068
  addKey("off/repeat", Unmapped_Key, 0x3D0, 12); // 0x1E8
  addKey("cable", Unmapped_Key, 0x730, 12); // 0x398
  addKey("auto_program", Unmapped_Key, 0xD70, 12); // 0x6B8
  addKey("erase", Unmapped_Key, 0x9F0, 12); // 0x4F8
  addKey("picture_up", Unmapped_Key, 0x190, 12); // 0x0C8
  addKey("picture_down", Unmapped_Key, 0x990, 12); // 0x4C8
  addKey("PIP", PIP_Key, 0xDB0, 12); // 0x6D8
  addKey("PIP_SWAP", PIPSwap_Key, 0xFB0, 12); // 0x7D8
  addKey("PIP_POSITION", PIPMove_Key, 0x7B0, 12); // 0x3D8
  addKey("PIP_SOURCE", PIPSource_Key, 0xE70, 12); // 0x738
  addKey("pip_ch+", PIPChannelUp_Key, 0x1B0, 12);
  addKey("pip_ch-", PIPChannelDown_Key, 0x9B0, 12);
  addKey("pipfreeze", Unmapped_Key, 0x3B0, 12);
  addKey("piptv_video", Unmapped_Key, 0x5B0, 12);
  addKey("Sat", Unmapped_Key, 0x8B0, 12); // 0x458
  addKey("Settup_V", Unmapped_Key, 0x870, 12); // 0x438
  addKey("Settup_A", Unmapped_Key, 0x470, 12); // 0x238
  addKey("EXIT", Exit_Key, 0xC70, 12);
  addKey("enter", Enter_Key, 0xD10, 12); // 0x688
  addKey("picturemode", Unmapped_Key, 0x270, 12); // 0x138
  addKey("ANT", Unmapped_Key, 0x550, 12);

  addKey("16:9", AspectRatio_Key, 0x5E25, 15); // "WIDE"
  addKey("DIGITAL", Unmapped_Key, 0x25EE, 15);
  addKey("EPG", Guide_Key, 0x6D25, 15);
  addKey("RETURN", Unmapped_Key, 0x62E9, 15);
  addKey("TOOLS", Unmapped_Key, 0x36E9, 15);
  addKey("theatre", Unmapped_Key, 0x03EE, 15);
  addKey("SYNC_MENU", Unmapped_Key, 0x0D58, 15);
  addKey("PREVIOUS", Previous_Key, 0x1EE9, 15);
  addKey("STOP", Stop_Key, 0x0CE9, 15);
  addKey("NEXT", Next_Key, 0x5EE9, 15);
  addKey("I-MANUAL", Unmapped_Key, 0x6F58, 15);
  addKey("SCENE", Unmapped_Key, 0x0F58, 15);
  addKey("DIGITAL_ANALOG", Unmapped_Key, 0x58EE, 15);
  addKey("FBACKWARD", Rewind_Key, 0x6CE9, 15);
  addKey("PLAY", Play_Key, 0x2CE9, 15);
  addKey("FFORWARD", FastForward_Key, 0x1CE9, 15);
  addKey("INTERNET_VIDEO", Unmapped_Key, 0x4F58, 15);
  addKey("FAVORITES", Unmapped_Key, 0x37EE, 15);
  addKey("OPTIONS", Unmapped_Key, 0x36E9, 15);
  addKey("PIP_Audio", Unmapped_Key, 0x1F25, 15);
  addKey("Surround_Mode", Unmapped_Key, 0x7C25, 15);
  addKey("DOT", Unmapped_Key, 0x5CE9, 15);
  addKey("SOUND", Unmapped_Key, 0x6FE9, 15);
  addKey("REPLAY", Replay_Key, 0x4FE9, 15);
  addKey("ADVANCE", Advance_Key, 0x0FE9, 15);
  addKey("PAUSE", Pause_Key, 0x4CE9, 15);
}


SonyTV1a::SonyTV1a(
  QObject *guiObject,
  unsigned int index)
  : SonyTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1a");

  addControlledDevice(Sony_Make, "Trinitron KV-2184MT", TV_Device);
  addControlledDevice(Sony_Make, "KV-M1420D", TV_Device);
  addControlledDevice(Sony_Make, "KV-20FV10", TV_Device);
  addControlledDevice(Sony_Make, "KV-27FX210", TV_Device);
  addControlledDevice(Sony_Make, "KV-32FS210", TV_Device);
  addControlledDevice(Sony_Make, "KV-36FS210", TV_Device);
  addControlledDevice(Sony_Make, "KV-36FS13", TV_Device);
  addControlledDevice(Sony_Make, "KDL-52X2000", TV_Device);
  addControlledDevice(Sony_Make, "KDL-46X2000", TV_Device);
  addControlledDevice(Sony_Make, "KDL-40X2000", TV_Device);

  // Overwrite directional keys:
  addKey("up", Up_Key, 0x2F0, 12); // 0x178
  addKey("down", Down_Key, 0xAF0, 12); // 0x578
  addKey("left", Left_Key, 0x2D0, 12); // 0x168
  addKey("right", Right_Key, 0xCD0, 12); // 0x668
}


SonyTV1b::SonyTV1b(
  QObject *guiObject,
  unsigned int index)
  : SonyTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1b");

  addKey("clear", Unmapped_Key, 0x2D0, 12); // 0x168
  addKey("level_plus", Unmapped_Key, 0x2F0, 12); // 0x178
  addKey("level_minus", Unmapped_Key, 0xAF0, 12); // 0x578
  addKey("am/pm", Unmapped_Key, 0xCD0, 12); // 0x668
}


/*
SonyTV1c::SonyTV1c(
  QObject *guiObject,
  unsigned int index)
  : SonyTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1c");

  addKey("pip_move", PIPPosition_Key, 0x7B0, 12);
  addKey("pip_swap", PIPSwap_Key, 0xFB0, 12);
  addKey("pip_ch+", PIPChannelUp_Key, 0x1B0, 12);
  addKey("pip_ch-", PIPChannelDown_Key, 0x9B0, 12);
}
*/


// Note, deeper inheritance on this one:
SonyTV1d::SonyTV1d(
  QObject *guiObject,
  unsigned int index)
  : SonyTV1a(guiObject, index)
{
  setKeysetName("TV Keyset 1d");

  addKey("play", Play_Key, 0xFB0, 12);
  addKey("<<", Rewind_Key, 0x9B0, 12);
  addKey(">>", FastForward_Key, 0x1B0, 12);
  addKey("pause", Pause_Key, 0x3B0, 12);
  addKey("stop", Stop_Key, 0x7B0, 12);
  addKey("rec", Record_Key, 0x5B0, 12);

  addKey("RED", Red_Key, 0x52E9, 15);
  addKey("GREEN", Green_Key, 0x32E9, 15);
  addKey("YELLOW", Yellow_Key, 0x72E9, 15);
  addKey("BLUE", Blue_Key, 0x12E9, 15);
  addKey("SUBTITLES", Captions_Key, 0x0AE9, 15); // this might be wrong
}


/*
SonyTV2::SonyTV2(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 2",
      Sony_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    1262, 515,
    661, 515,
    26187, false);

  threadableProtocl = np;

  np->setHeaderPair(2470, 515);
  np->setTrailer(661);

  addKey("MUTE", Mute_Key, 0x6B7, 11);
  addKey("ON/STANDBY", Power_Key, 0x2B7, 11);
  addKey("TV", Unmapped_Key, 0x717, 11); // teletext
  addKey("TELETEXT", Unmapped_Key, 0x017, 11); // teletext
  addKey("INPUT", Input_Key, 0x2D7, 11);
  addKey("OUTPUT", Unmapped_Key, 0x4C7, 11);
  addKey("1", One_Key, 0x7F7, 11);
  addKey("2", Two_Key, 0x3F7, 11);
  addKey("3", Three_Key, 0x5F7, 11);
  addKey("4", Four_Key, 0x1F7, 11);
  addKey("5", Five_Key, 0x6F7, 11);
  addKey("6", Six_Key, 0x2F7, 11);
  addKey("7", Seven_Key, 0x4F7, 11);
  addKey("8", Eight_Key, 0x0F7, 11);
  addKey("9", Nine_Key, 0x777, 11);
  addKey("0", Zero_Key, 0x377, 11);
  addKey("-/--", DoubleDigit_Key, 0x237, 11);
  addKey("C", Clear_Key, 0x477, 11);
  addKey("PIP", PIP_Key, 0x127, 11);
  addKey("PIP_POSITION", PIPPosition_Key, 0x427, 11);
  addKey("PIP_SWAP", PIPSwap_Key, 0x027, 11);
  addKey("PIP_SOURCE", PIPSource_Key, 0x0C7, 11);
  addKey("RED", Red_Key, 0x663, 11);
  addKey("GREEN", Green_Key, 0x263, 11);
  addKey("YELLOW", Yellow_Key, 0x463, 11);
  addKey("BLUE", Blue_Key, 0x063, 11);
  addKey("TELETEXT_HOLD", Unmapped_Key, 0x563, 11);
  addKey("INFO", Info_Key, 0x517, 11);
  addKey("SAT", Unmapped_Key, 0x3A7, 11);
  addKey("VOLUME+", VolumeUp_Key, 0x5B7, 11);
  addKey("VOLUME-", VolumeDown_Key, 0x1B7, 11);
  addKey("PROGR+", ChannelUp_Key, 0x7B7, 11);
  addKey("PROGR-", ChannelDown_Key, 0x3B7, 11);
  addKey("PICTURE", Unmapped_Key, 0x3C7, 11);
  addKey("SOUND", Unmapped_Key, 0x5C7, 11);
  addKey("MENU", Menu_Key, 0x7C7, 11);
  addKey("BACK", Left_Key, 0x697, 11);
  addKey("UP", Up_Key, 0x687, 11);
  addKey("DOWN", Down_Key, 0x287, 11);
  addKey("OK", Enter_Key, 0x2C7, 11);
  addKey("OK", Select_Key, 0x2C7, 11);
  addKey("RGB1", Unmapped_Key, 0x1E7, 11);
  addKey("RGB2", Unmapped_Key, 0x6E7, 11);
  addKey("Line", Unmapped_Key, 0x7E7, 11);
  addKey("Y-C", Unmapped_Key, 0x267, 11);
  addKey("MTS-MPX", Unmapped_Key, 0x0B7, 11);
  addKey("Still", Unmapped_Key, 0x627, 11);
  addKey("PowerOn", Unmapped_Key, 0x457, 11);
  addKey("PowerOff", Unmapped_Key, 0x057, 11);
}
*/


SonyAmp1::SonyAmp1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Amp Keyset 1",
      Sony_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    600, 600,
    1200, 600,
    25000, false);

  threadableProtocol = np;

  np->setHeaderPair(2400, 600);

  np->setPostData(0xC, 6);

  np->setMinimumRepetitions(2);

  addKey("VIDEO1", Unmapped_Key, 0x22, 7);
  addKey("VIDEO2", Unmapped_Key, 0x3C, 7);
  addKey("VIDEO3", Unmapped_Key, 0x21, 7);
  addKey("VIDEO4", Unmapped_Key, 0x61, 7);
  addKey("DVD", Unmapped_Key, 0x5F, 7);
  addKey("LD", Unmapped_Key, 0x4C, 7);
  addKey("TV2", Unmapped_Key, 0x2B, 7);
  addKey("TV", Unmapped_Key, 0x0C, 7);
  addKey("MD", Unmapped_Key, 0x4B, 7);
  addKey("TAPE", Unmapped_Key, 0x62, 7);
  addKey("DAT", Unmapped_Key, 0x31, 7);
  addKey("CD", Unmapped_Key, 0x52, 7);
  addKey("TUNER", Unmapped_Key, 0x42, 7);
  addKey("PHONO", Unmapped_Key, 0x02, 7);
  addKey("DIGITAL", Unmapped_Key, 0x11, 7);
  addKey("5.1CH", Unmapped_Key, 0x27, 7);
  addKey("VOL+", VolumeUp_Key, 0x24, 7);
  addKey("VOL-", VolumeDown_Key, 0x64, 7);
  addKey("MUTE", Mute_Key, 0x14, 7);
  addKey("POWER", Power_Key, 0x54, 7);
  addKey("SLEEP", Sleep_Key, 0x03, 7);
  addKey("1", One_Key, 0x00, 7);
  addKey("2", Two_Key, 0x40, 7);
  addKey("3", Three_Key, 0x20, 7);
  addKey("4", Four_Key, 0x60, 7);
  addKey("5", Five_Key, 0x10, 7);
  addKey("6", Six_Key, 0x50, 7);
  addKey("7", Seven_Key, 0x30, 7);
  addKey("8", Eight_Key, 0x70, 7);
  addKey("9", Nine_Key, 0x08, 7);
  addKey("0", Zero_Key, 0x48, 7);
  addKey("ENTER", Enter_Key, 0x68, 7);
}


SonyAmp2::SonyAmp2(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Amp Keyset 2",
      Sony_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    600, 600,
    1200, 600,
    44737, true);

  threadableProtocol = np;

  np->setHeaderPair(2400, 600);

  np->setMinimumRepetitions(2);

  addKey("power_on", Unmapped_Key, 0x741, 12);
  addKey("power", Power_Key, 0xA81, 12);
  addKey("up", Up_Key, 0x1E6, 12);
  addKey("down", Down_Key, 0x9E6, 12);
  addKey("left", Left_Key, 0x5E6, 12);
  addKey("right", Right_Key, 0xDE6, 12);
  addKey("shift", Unmapped_Key, 0xCD6, 12);
  addKey("program_+", ChannelUp_Key, 0x096, 12);
  addKey("program_-", ChannelDown_Key, 0x896, 12);
  addKey("vol_+", VolumeUp_Key, 0x481, 12);
  addKey("vol_-", VolumeDown_Key, 0xC81, 12);
  addKey("mute", Mute_Key, 0x281, 12);
  addKey("1", One_Key, 0x001, 12);
  addKey("2", Two_Key, 0x801, 12);
  addKey("3", Three_Key, 0x401, 12);
  addKey("4", Four_Key, 0xC01, 12);
  addKey("5", Five_Key, 0x201, 12);
  addKey("6", Six_Key, 0xA01, 12);
  addKey("7", Seven_Key, 0x601, 12);
  addKey("8", Eight_Key, 0xE01, 12);
  addKey("9", Nine_Key, 0x101, 12);
  addKey("0", Zero_Key, 0x901, 12);
  addKey("enter", Enter_Key, 0x301, 12);
  addKey("video1", Unmapped_Key, 0x441, 12);
  addKey("video2", Unmapped_Key, 0x781, 12);
  addKey("video3", Unmapped_Key, 0x421, 12);
  addKey("aux/vdp", Unmapped_Key, 0xB81, 12);
  addKey("tuner", Unmapped_Key, 0x841, 12);
  addKey("dvd", Unmapped_Key, 0xBE1, 12);
  addKey("tv", Unmapped_Key, 0x561, 12);
  addKey("cd", Unmapped_Key, 0xA41, 12);
  addKey("tape", Unmapped_Key, 0xC41, 12);
  addKey("phono", Unmapped_Key, 0x041, 12);
  addKey("md/dat", Unmapped_Key, 0x4B08, 15); // note, longer command
}


SonyCD1::SonyCD1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "CD Player Keyset 1",
      Sony_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    600, 600,
    1200, 600,
    45000, true);

  threadableProtocol = np;

  np->setHeaderPair(2400, 600);

  addKey("DSG", Unmapped_Key, 0x8C6, 12);
  addKey("DISPLAY", Info_Key, 0xD21, 12);
  addKey("ON-OFF", Power_Key, 0xA81, 12);
  addKey("CD", Unmapped_Key, 0x4D1, 12);
  addKey("TUNER-BAND", Unmapped_Key, 0xF16, 12);
  addKey("TAPE", Unmapped_Key, 0x2CE, 12);
  addKey("DIR_MODE", Unmapped_Key, 0x28E, 12);
  addKey("PLAY_MODE", Unmapped_Key, 0x371, 12);
  addKey("REC", Record_Key, 0x78E, 12);
  addKey("CD_REPEAT", Unmapped_Key, 0x351, 12);
  addKey("STEREO-MONO", Unmapped_Key, 0x856, 12);
  addKey("TUNING_MODE", Unmapped_Key, 0xE96, 12);
  addKey("MEMORY", Unmapped_Key, 0x716, 12);
  addKey("TIMER_SET", Unmapped_Key, 0xA61, 12);
  addKey("TIMER_SELECT", Unmapped_Key, 0x461, 12); // also "clock_select"
  addKey("SLEEP", Sleep_Key, 0x061, 12);
  addKey("VOL+", VolumeUp_Key, 0x481, 12);
  addKey("VOL-", VolumeDown_Key, 0xC81, 12);
  addKey("md", Unmapped_Key, 0x961, 12);
  addKey("tuner", Unmapped_Key, 0xF01, 12);
  addKey("game", Unmapped_Key, 0x3E1, 12);
  addKey("cd", Unmapped_Key, 0xA41, 12);
  addKey("dimmer", Unmapped_Key, 0xB21, 12);
  addKey("karaoke_mpx", Unmapped_Key, 0xFA1, 12);
  addKey("effect_on_off", Unmapped_Key, 0xF81, 12);
  addKey("display", Unmapped_Key, 0xD21, 12);
  addKey("tv_video", Input_Key, 0xA50, 12);

  addKey("game_mixing", Unmapped_Key, 0x6609, 15);
  addKey("spectrum", Unmapped_Key, 0x1609, 15);
  addKey("cinema_effect", Unmapped_Key, 0x0109, 15);
  addKey("surround_speaker_mode", Surround_Key, 0x7D09, 15);
  addKey("music_eq", Unmapped_Key, 0x0309, 15);
  addKey("movie_eq", Unmapped_Key, 0x4309, 15);
  addKey("game_eq", Unmapped_Key, 0x2309, 15);
  addKey("p_file", Unmapped_Key, 0x4E09, 15);

  addKey("KEY_PAUSE", Pause_Key, 0x9CB9C, 20);
  addKey("KEY_STOP", Stop_Key, 0x1CB9C, 20);
  addKey("KEY_PREV_SONG", Previous_Key, 0x0CB9C, 20);
  addKey("KEY_NEXT_SONG", Next_Key, 0x8CB9C, 20);
  addKey("KEY_PREV", Rewind_Key, 0xCCB9C, 20);
  addKey("KEY_NEXT", FastForward_Key, 0x2CB9C, 20);
  addKey("KEY_ENTER", Enter_Key, 0x30B9C, 20);
  addKey("1", One_Key, 0x00B9C, 20);
  addKey("2", Two_Key, 0x80B9C, 20);
  addKey("3", Three_Key, 0x40B9C, 20);
  addKey("4", Four_Key, 0xC0B9C, 20);
  addKey("5", Five_Key, 0x20B9C, 20);
  addKey("6", Six_Key, 0xA0B9C, 20);
  addKey("7", Seven_Key, 0x60B9C, 20);
  addKey("8", Eight_Key, 0xE0B9C, 20);
  addKey("9", Nine_Key, 0x10B9C, 20);
  addKey("0", Zero_Key, 0x90B9C, 20);
  addKey("gt_10", DoubleDigit_Key, 0xB0B9C, 20);
  addKey("special_menu", Menu_Key, 0xCAB8C, 20);
  addKey("clear", Clear_Key, 0xF0B9C, 20);
  addKey("repeat", Unmapped_Key, 0x34B9C, 20);
  addKey("d_skip", Unmapped_Key, 0x7CB9C, 20);
  addKey("on_screen", Unmapped_Key, 0xAAB8C, 20);
  addKey("prev_r", Unmapped_Key, 0x6CB8C, 20);
  addKey("next_r", Unmapped_Key, 0xECB8C, 20);
  addKey("return", Exit_Key, 0x70B8C, 20);
  addKey("album+", Unmapped_Key, 0xF6B8C, 20);
  addKey("album-", Unmapped_Key, 0x76B8C, 20);
  addKey("sharp", Unmapped_Key, 0xD6B8C, 20);
  addKey("flat", Unmapped_Key, 0x36B8C, 20);
  addKey("up", Up_Key, 0x1EB9C, 20);
  addKey("down", Down_Key, 0x9EB9C, 20);
  addKey("left", Left_Key, 0x5EB9C, 20);
  addKey("right", Right_Key, 0xDEB9C, 20);
}


SonyCD1a::SonyCD1a(
  QObject *guiObject,
  unsigned int index)
  : SonyCD1(guiObject, index)
{
  setKeysetName("CD Keyset 1a");

  addKey("tape", Unmapped_Key, 0xC41, 12);

  addKey("select", Select_Key, 0x4CB9C, 20);
  addKey("play", Play_Key, 0x4CB9C, 20);
  addKey("play_mode", Unmapped_Key, 0x64B9C, 20);
  addKey("enter", Enter_Key, 0x3EB9C, 20);
}


SonyCD2::SonyCD2(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "CD Keyset 2",
      Sony_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    612, 588,
    1210, 588,
    45604, true);

  threadableProtocol = np;

  np->setHeaderPair(2412, 588);

  np->setPostData(0x7, 4);

  addKey("PLAY", Play_Key, 0x59, 7);
  addKey("STOP", Stop_Key, 0x71, 7);
  addKey("PAUSE", Pause_Key, 0x31, 7);
  addKey("NEXT", Next_Key, 0x39, 7);
  addKey("PREV", Previous_Key, 0x79, 7);
  addKey("FAST_FORWARD", FastForward_Key, 0x69, 7);
  addKey("FAST_BACKWARD", Rewind_Key, 0x19, 7);
  addKey("FORWARD", StepForward_Key, 0x11, 7);
  addKey("BACKWARD", StepBack_Key, 0x51, 7);
  addKey("VOLUME_UP", VolumeUp_Key, 0x5B, 7);
  addKey("VOLUME_DOWN", VolumeDown_Key, 0x1B, 7);
  addKey("RED", Red_Key, 0x03, 7);
  addKey("GREEN", Green_Key, 0x29, 7);
  addKey("YELLOW", Yellow_Key, 0x23, 7);
  addKey("BLUE", Blue_Key, 0x43, 7);
  addKey("QUIT", Exit_Key, 0x4B, 7);
  addKey("UP", Up_Key, 0x07, 7);
  addKey("DOWN", Down_Key, 0x02, 7);
  addKey("RIGHT", Right_Key, 0x75, 7);
  addKey("LEFT", Left_Key, 0x55, 7);
  addKey("OK", Enter_Key, 0x0D, 7);
  addKey("MENU1", Menu_Key, 0x0D, 7); // This might be wrong
  addKey("MENU2", Unmapped_Key, 0x65, 7);
  addKey("1", One_Key, 0x7F, 7);
  addKey("TWO", Two_Key, 0x3F, 7);
  addKey("3", Three_Key, 0x5F, 7);
  addKey("4", Four_Key, 0x1F, 7);
  addKey("5", Five_Key, 0x6F, 7);
  addKey("6", Six_Key, 0x2F, 7);
  addKey("7", Seven_Key, 0x4F, 7);
  addKey("8", Eight_Key, 0x0F, 7);
  addKey("9", Nine_Key, 0x77, 7);
  addKey("10", Unmapped_Key, 0x7D, 7);
  addKey("11", Unmapped_Key, 0x3D, 7);
  addKey("12", Unmapped_Key, 0x5D, 7);
  addKey("13", Unmapped_Key, 0x1D, 7);
  addKey("14", Unmapped_Key, 0x6D, 7);
  addKey("15", Unmapped_Key, 0x2D, 7);
  addKey("16", Unmapped_Key, 0x4D, 7);
  addKey("17", Unmapped_Key, 0x7B, 7);
  addKey("18", Unmapped_Key, 0x3B, 7);
  addKey("19", Unmapped_Key, 0x0B, 7);
  addKey("20", Unmapped_Key, 0x35, 7);
  addKey("ZERO", Zero_Key, 0x0D, 7);
  addKey("CHECK", Unmapped_Key, 0x27, 7);
  addKey("CLEAR", Clear_Key, 0x07, 7);
}


SonyCD3::SonyCD3(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "CD Keyset 3",
      Sony_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    600, 600,
    1200, 600,
    44735, true);

  threadableProtocol = np;

  np->setHeaderPair(2400, 600);
  np->setTrailerPulse(1200);

  np->setPostData(0x08, 5);

  np->setMinimumRepetitions(2);

  addKey("|<<", Previous_Key, 0x03, 6);
  addKey(">>|", Next_Key, 0x23, 6);
  addKey("<<", Rewind_Key, 0x33, 6);
  addKey(">>", FastForward_Key, 0x0B, 6);
  addKey("play", Play_Key, 0x13, 6);
  addKey("stop", Stop_Key, 0x07, 6);
  addKey("pause", Pause_Key, 0x27, 6);
  addKey("power_on", Unmapped_Key, 0x1D, 6);
  addKey("power", Power_Key, 0x2A, 6);
  addKey("1", One_Key, 0x00, 6);
  addKey("2", Two_Key, 0x20, 6);
  addKey("3", Three_Key, 0x10, 6);
  addKey("4", Four_Key, 0x30, 6);
  addKey("5", Five_Key, 0x08, 6);
  addKey("6", Six_Key, 0x28, 6);
  addKey("7", Seven_Key, 0x18, 6);
  addKey("8", Eight_Key, 0x38, 6);
  addKey("9", Nine_Key, 0x04, 6);
  addKey("0", Zero_Key, 0x01, 6);
  addKey("+10", DoubleDigit_Key, 0x39, 6);
  addKey("enter", Enter_Key, 0x34, 6);
  addKey("clear", Clear_Key, 0x3C, 6);
  addKey("d_skip", Unmapped_Key, 0x1F, 6);
  addKey("repeat", Unmapped_Key, 0x2D, 6);
  addKey("continue", Unmapped_Key, 0x2E, 6);
  addKey("shuffle", Unmapped_Key, 0x2B, 6);
  addKey("program", Program_Key, 0x3E, 6);
}


SonyDAT1::SonyDAT1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "DAT Keyset 1",
      Sony_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    600, 600,
    1200, 600,
    25000, false);

  threadableProtocol = np;

  np->setHeaderPair(2400, 600);

  np->setPostData(0x07, 5);

  np->setMinimumRepetitions(2);

  np->setCarrierFrequency(40000);

  addKey("1", One_Key, 0x00, 7);
  addKey("2", Two_Key, 0x40, 7);
  addKey("3", Three_Key, 0x20, 7);
  addKey("4", Four_Key, 0x60, 7);
  addKey("5", Five_Key, 0x10, 7);
  addKey("6", Six_Key, 0x50, 7);
  addKey("7", Seven_Key, 0x30, 7);
  addKey("8", Eight_Key, 0x70, 7);
  addKey("9", Nine_Key, 0x08, 7);
  addKey("0", Zero_Key, 0x14, 7);
  addKey("PLAY", Play_Key, 0x2F, 7);
  addKey("PAUSE", Pause_Key, 0x4E, 7);
  addKey("STOP", Stop_Key, 0x0E, 7);
  addKey("<<", Rewind_Key, 0x6E, 7);
  addKey(">>", FastForward_Key, 0x1E, 7);
  addKey("|<<", Previous_Key, 0x0B, 7);
  addKey(">>|", Next_Key, 0x4B, 7);
  addKey("RECORD", Record_Key, 0x3E, 7);
  addKey("VOL+", VolumeUp_Key, 0x24, 7);
  addKey("VOL-", VolumeDown_Key, 0x64, 7);
  addKey("POWER_ON", Unmapped_Key, 0x3A, 7);
  addKey("POWER_OFF", Unmapped_Key, 0x7A, 7);
  addKey("MUTE", Mute_Key, 0x14, 7);
  addKey("POWER", Power_Key, 0x54, 7);
  addKey("ENTER", Enter_Key, 0x68, 7);
}


SonyDVD1::SonyDVD1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Sony_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    600, 600,
    1200, 600,
    45000, true);

  threadableProtocol = np;

  np->setHeaderPair(2400, 600);

  np->setMinimumRepetitions(2);

//  np->setCarrierFrequency(40000);

  addKey("power", Power_Key, 0xA8B92, 20);
  addKey("Display", Info_Key, 0x2AB92, 20);
  addKey("prev", Previous_Key, 0x0CB92, 20);
  addKey("next", Next_Key, 0x8CB92, 20);
  addKey("Replay", Replay_Key, 0x3AB92, 20);
  addKey("Advance", Advance_Key, 0x28B46, 20);
  addKey("ffwd", FastForward_Key, 0x2CB92, 20);
  addKey("rew", Rewind_Key, 0xCCB92, 20);
  addKey("play", Play_Key, 0x4CB92, 20);
  addKey("pause", Pause_Key, 0x9CB92, 20);
  addKey("stop", Stop_Key, 0x1CB92, 20);
  addKey("Favorites", Unmapped_Key, 0x7AB46, 20);
  addKey("Input", Input_Key, 0x48B92, 20);
  addKey("Guide", Guide_Key, 0x68B46, 20);
  addKey("return", Exit_Key, 0x70B92, 20);
  addKey("Options", Unmapped_Key, 0xE8B46, 20);
  addKey("menu", Menu_Key, 0xCAB92, 20); // "setup"
  addKey("up", Up_Key, 0x9EB92, 20);
  addKey("down", Down_Key, 0x5EB92, 20);
  addKey("left", Left_Key, 0xDEB92, 20);
  addKey("right", Right_Key, 0x3EB92, 20);
  addKey("select", Select_Key, 0xD0B92, 20);
  addKey("1", One_Key, 0x00B92, 20);
  addKey("2", Two_Key, 0x80B92, 20);
  addKey("3", Three_Key, 0x40B92, 20);
  addKey("4", Four_Key, 0xC0B92, 20);
  addKey("5", Five_Key, 0x20B92, 20);
  addKey("6", Six_Key, 0xA0B92, 20);
  addKey("7", Seven_Key, 0x60B92, 20);
  addKey("8", Eight_Key, 0xE0B92, 20);
  addKey("9", Nine_Key, 0x10B92, 20);
  addKey("0", Zero_Key, 0x90B92, 20);
  addKey("Ent", Enter_Key, 0xB0B92, 20);
  addKey("Dot", Unmapped_Key, 0xB8B46, 20);
  addKey("prog+", ChannelUp_Key, 0xC8B92, 20);
  addKey("prog-", ChannelDown_Key, 0x28B92, 20);
  addKey("rec", Record_Key, 0x98B92, 20);
  addKey("RecPause", Unmapped_Key, 0x7CB92, 20);
  addKey("RecStop", Unmapped_Key, 0xBCB92, 20);
  addKey("top_menu", DiscTitle_Key, 0x58B92, 20); // "Title"
  addKey("dvd_menu", DiscMenu_Key, 0xD8B92, 20);
  addKey("F1", Unmapped_Key, 0x74B46, 20);
  addKey("F2", Unmapped_Key, 0xF4B46, 20);
  addKey("Red", Red_Key, 0xE6B46, 20);
  addKey("Green", Green_Key, 0x16B46, 20);
  addKey("Purple", Blue_Key, 0x66B46, 20);
  addKey("Yellow", Yellow_Key, 0x96B46, 20);
  addKey("Language", Language_Key, 0x26B92, 20);
  addKey("subtitles", Captions_Key, 0xC6B92, 20); // "Subtitle_Change"
  addKey("X2_BACK", Unmapped_Key, 0x6CB92, 20);
  addKey("X2_FORWARD", Unmapped_Key, 0xECB92, 20);
  addKey("SUBTITLE_ON_OFF", Unmapped_Key, 0x46B92, 20);
  addKey("CLEAR", Clear_Key, 0xF0B92, 20);
  addKey("SLOW_BACK", Unmapped_Key, 0x06B92, 20);
  addKey("SLOW_FORWARD", Unmapped_Key, 0x86B92, 20);
  addKey("STEP_BACK", StepBack_Key, 0x5CB92, 20);       // JOG-
  addKey("STEP_FORWARD", StepForward_Key, 0xDCB92, 20); // JOG+
  addKey("SEARCH_MODE", Unmapped_Key, 0xD2B92, 20);
  addKey("TIME", Unmapped_Key, 0x14B92, 20);
  addKey("DNR", Unmapped_Key, 0x12B92, 20);
  addKey("TV_DVD", Unmapped_Key, 0x8AB92, 20);
  addKey("surround", Surround_Key, 0x5AB92, 20);
  addKey("open/close", Eject_Key, 0x68B92, 20);
  addKey("a-b", Unmapped_Key, 0x54B92, 20);
  addKey("shuffle", Unmapped_Key, 0xACB92, 20);
  addKey("repeat", Unmapped_Key, 0x34B92, 20);
  addKey("program", Program_Key, 0xF8B92, 20);
  addKey("PICTUREMODE", Unmapped_Key, 0xDAB92, 20);
  addKey("Picture_Navi", Unmapped_Key, 0x0AB92, 20);
  addKey("DiscSkip", Unmapped_Key, 0x7CB46, 20);
  addKey("SA-CD_MULTI/2CH", Unmapped_Key, 0x7AB92, 20);
  addKey("SA-CD/CD", Unmapped_Key, 0xFAB92, 20);
  addKey("ALBUM-MINUS", Unmapped_Key, 0x94B46, 20);
  addKey("ALBUM-PLUS", Unmapped_Key, 0x54B46, 20);
  addKey("ZOOM", Unmapped_Key, 0x9EB46, 20);
  addKey("POWER_ON", Unmapped_Key, 0x74B92, 20);
  addKey("POWER_OFF", Unmapped_Key, 0xF4B92, 20);
  addKey("INDEX+", Unmapped_Key, 0xE4B92, 20);
  addKey("INDEX-", Unmapped_Key, 0x64B92, 20);
  addKey("ANGLE_CHANGE", Unmapped_Key, 0xA6B92, 20);
  addKey("JOG_STOP", Unmapped_Key, 0x94B92, 20);
}


SonyDVD1a::SonyDVD1a(
  QObject *guiObject,
  unsigned int index)
  : SonyDVD1(guiObject, index)
{
  setKeysetName("DVD Keyset 1a");

  addKey("STEP_BACK", StepBack_Key, 0x04B92, 20);
  addKey("STEP_FORWARD", StepForward_Key, 0x84B92, 20);
  addKey("SLOW_BACK", Unmapped_Key, 0x44B92, 20);
  addKey("SLOW_FORWARD", Unmapped_Key, 0xC4B92, 20);
}


SonyDVD1b::SonyDVD1b(
  QObject *guiObject,
  unsigned int index)
  : SonyDVD1(guiObject, index)
{
  setKeysetName("DVD Keyset 1b");

  addKey("SLOW-", Unmapped_Key, 0x4EB92, 20);
  addKey("SLOW+", Unmapped_Key, 0xCEB92, 20);
}


SonyDVD1c::SonyDVD1c(
  QObject *guiObject,
  unsigned int index)
  : SonyDVD1(guiObject, index)
{
  setKeysetName("DVD Keyset 1c");

  addKey("up", Up_Key, 0x9CB92, 20);
  addKey("down", Down_Key, 0x1CB92, 20);
  addKey("left", Left_Key, 0xCCB92, 20);
  addKey("right", Right_Key, 0x2CB92, 20);
  addKey("ok", Select_Key, 0x4CB92, 7);
  addKey("enter", Enter_Key, 0xD0B92, 7);
}


SonyVCR1::SonyVCR1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      Sony_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    703, 517,
    1301, 517,
    45239, true);

  threadableProtocol = np;

  np->setHeaderPair(2499, 517);
  np->setTrailerPulse(703);

  np->setMinimumRepetitions(2);

  addKey("pwon", Power_Key, 0x54D, 11);
  addKey("1", One_Key, 0x00D, 11);
  addKey("2", Two_Key, 0x40D, 11);
  addKey("3", Three_Key, 0x20D, 11);
  addKey("4", Four_Key, 0x60D, 11);
  addKey("5", Five_Key, 0x10D, 11);
  addKey("6", Six_Key, 0x50D, 11);
  addKey("7", Seven_Key, 0x30D, 11);
  addKey("8", Eight_Key, 0x70D, 11);
  addKey("9", Nine_Key, 0x08D, 11);
  addKey("0", Zero_Key, 0x48D, 11);
  addKey("jump", PrevChannel_Key, 0x28D, 11); // might be wrong
  addKey("red", Red_Key, 0x19C, 11);
  addKey("green", Green_Key, 0x59C, 11);
  addKey("blue", Blue_Key, 0x79C, 11);
  addKey("rec", Record_Key, 0x5CD, 11);
  addKey("up", Up_Key, 0x4CD, 11);
  addKey("down", Down_Key, 0x0CD, 11);
  addKey("left", Left_Key, 0x6CD, 11);
  addKey("right", Right_Key, 0x1CD, 11);
  addKey("ok", Select_Key, 0x2CD, 11);
  addKey("prog-next", ChannelUp_Key, 0x04D, 11);
  addKey("prog-prev", ChannelDown_Key, 0x44D, 11);
  addKey("power_on", Unmapped_Key, 0x3AD, 11);
  addKey("<<", Rewind_Key, 0x6CD, 11); // 0xD9A
  addKey(">>", FastForward_Key, 0x1CD, 11); // 0x39A
  addKey("play", Play_Key, 0x2CD, 11); // 0x59A
  addKey("stop", Stop_Key, 0x0CD, 11); // 0x19A
  addKey("pause", Pause_Key, 0x4CD, 11); // 0x99A
  addKey("menu", Menu_Key, 0x59D, 11);
  addKey("ant/sw", Unmapped_Key, 0x2AD, 11);
  addKey("input", Input_Key, 0x79D, 11);
  addKey("display", Info_Key, 0x2DD, 11);
  addKey("ENT", Unmapped_Key, 0x68D, 11);
  addKey("VOL_UP", VolumeUp_Key, 0x248, 11);
  addKey("VOL_DOWN", VolumeDown_Key, 0x648, 11);
}


SonyVCR1a::SonyVCR1a(
  QObject *guiObject,
  unsigned int index)
  : SonyVCR1(guiObject, index)
{
  setKeysetName("VCR Keyset 1a");

  addKey("up", Up_Key, 0x21D, 11);  // 0x43A
  addKey("down", Down_Key, 0x61D, 11);  // 0xC3A
  addKey("left", Left_Key, 0x23D, 11);  // 0x47A
  addKey("right", Right_Key, 0x43D, 11); // 0x87A
  addKey("execute", Select_Key, 0x45D, 11); // 0x8BA
  addKey("-/--", DoubleDigit_Key, 0x28D, 11);
  addKey("SLEEP", Sleep_Key, 0x79D, 11); // 0xF3A
}


SonyReceiver1::SonyReceiver1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Receiver Keyset 1",
      Sony_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    693, 502,
    1291, 502,
    40006, true);

  threadableProtocol = np;

  np->setHeaderPair(2486, 498);

  np->setMinimumRepetitions(1);

  addKey("SLEEP", Sleep_Key, 0x030C, 15);
  addKey("POWER", Power_Key, 0x540C, 15);
  addKey("VIDEO1", Unmapped_Key, 0x220C, 15);
  addKey("VIDEO2", Unmapped_Key, 0x3C0C, 15);
  addKey("VIDEO3", Unmapped_Key, 0x210C, 15);
  addKey("DVD", Unmapped_Key, 0x5F0C, 15);
  addKey("SAT", Unmapped_Key, 0x600D, 15);
  addKey("TV", Unmapped_Key, 0x2B0C, 15);
  addKey("SA_CD", Unmapped_Key, 0x520C, 15);
  addKey("TUNER", Unmapped_Key, 0x420C, 15);
  addKey("2CH", Unmapped_Key, 0x410D, 15);
  addKey("AFD", Unmapped_Key, 0x210D, 15);
  addKey("MOVIE", Unmapped_Key, 0x610D, 15);
  addKey("MUSIC", Unmapped_Key, 0x490D, 15);
  addKey("1", One_Key, 0x000C, 15);
  addKey("2", Two_Key, 0x400C, 15);
  addKey("3", Three_Key, 0x200C, 15);
  addKey("4", Four_Key, 0x600C, 15);
  addKey("5", Five_Key, 0x100C, 15);
  addKey("6", Six_Key, 0x500C, 15);
  addKey("7", Seven_Key, 0x300C, 15);
  addKey("8", Eight_Key, 0x700C, 15);
  addKey("9", Nine_Key, 0x080C, 15);
  addKey("0", Zero_Key, 0x480C, 15);
  addKey("AMP_MENU", Menu_Key, 0x770D, 15);
  addKey("DVD_MENU", Unmapped_Key, 0x5A0D, 15);
  addKey("DISPLAY", Info_Key, 0x690C, 15);
  addKey("MUTING", Mute_Key, 0x140C, 15);
  addKey("LEFT", Left_Key, 0x2F0D, 15);
  addKey("UP", Up_Key, 0x0F0D, 15);
  addKey("RIGHT", Right_Key, 0x6F0D, 15);
  addKey("DOWN", Down_Key, 0x4F0D, 15);
  addKey("SELECT", Select_Key, 0x180C, 15);
  addKey("VOLUME_UP", VolumeUp_Key, 0x240C, 15);
  addKey("VOLUME_DOWN", VolumeDown_Key, 0x640C, 15);
}
