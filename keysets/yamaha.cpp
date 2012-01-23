#include "yamaha.h"
#include "necprotocol.h"


YamahaDVD1::YamahaDVD1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Yamaha_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index);

  setPreData(0x3EC1, 16);

  addKey("title", DiscTitle_Key, 0x8D72, 16);
  addKey("menu", DiscMenu_Key, 0x4DB2, 16);
  addKey("up", Up_Key, 0x2DD2, 16);
  addKey("down", Down_Key, 0xCD32, 16);
  addKey("left", Left_Key, 0xAD52, 16);
  addKey("right", Right_Key, 0x6D92, 16);
  addKey("enter", Select_Key, 0x1DE2, 16);
  addKey("return", Exit_Key, 0xED12, 16);
  addKey("display", Info_Key, 0x659A, 16);
  addKey("record", Record_Key, 0xD12E, 16);
  addKey("stop", Stop_Key, 0xA15E, 16);
  addKey("pause", Pause_Key, 0xC13E, 16);
  addKey("play", Play_Key, 0x41BE, 16);
  addKey("rewind", Rewind_Key, 0x619E, 16);
  addKey("fast_forward", FastForward_Key, 0xE11E, 16);
  addKey("previous", Previous_Key, 0x9D62, 16);
  addKey("next", Next_Key, 0x5DA2, 16);
  addKey("1", One_Key, 0x29D6, 16);
  addKey("2", Two_Key, 0xA956, 16);
  addKey("3", Three_Key, 0x6996, 16);
  addKey("4", Four_Key, 0xE916, 16);
  addKey("5", Five_Key, 0x19E6, 16);
  addKey("6", Six_Key, 0x9966, 16);
  addKey("7", Seven_Key, 0x59A6, 16);
  addKey("8", Eight_Key, 0xD926, 16);
  addKey("9", Nine_Key, 0x39C6, 16);
  addKey("0", Zero_Key, 0xC936, 16);
  addKey("+10", DoubleDigit_Key, 0xB946, 16);
  addKey("ent", Enter_Key, 0x7986, 16);
  addKey("power_av", Power_Key, 0x01FE, 16); // might be wrong
}


YamahaDVD1a::YamahaDVD1a(
  QObject *guiObject,
  unsigned int index)
  : YamahaDVD1(guiObject, index)
{
  setKeysetName("DVD/LD Keyset 1a");

  addKey("LD_PLAY", Play_Key, 0xA05F, 16);
  addKey("LD_PAUSE/STOP", Pause_Key, 0x20DF, 16);
  addKey("LD_STOP", Stop_Key, 0xDA25, 16);
  addKey("LD_SCH_FWD", FastForward_Key, 0xE01F, 16);
  addKey("LD_SCH_REV", Rewind_Key, 0x609F, 16);
  addKey("LD_CH_+", ChannelUp_Key, 0xC03F, 16);
  addKey("LD_CH_-", ChannelDown_Key, 0x40BF, 16);
  addKey("LD_STILL_FWD", StepForward_Key, 0xD02F, 16);
  addKey("LD_STILL_REV", StepBack_Key, 0x50AF, 16);
  addKey("DISPLAY", Info_Key, 0xC837, 16);
  addKey("SOUND", Unmapped_Key, 0x48B7, 16);
}


YamahaAudio1::YamahaAudio1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Device Keyset 1",
      Yamaha_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index);

  setPreData(0x9E61, 16);

  addKey("SYNCHRO", Unmapped_Key, 0x1AE5, 16); // "DIRECT_OUT"
  addKey("DIMMER", Unmapped_Key, 0x7887, 16); // "MODE"
  addKey("TIME", Info_Key, 0x50AF, 16); // "TIME_DISPLAY"
  addKey("OPEN", Eject_Key, 0x807F, 16);
  addKey("SPACE", Unmapped_Key, 0xF00F, 16);
  addKey("PEAK", Unmapped_Key, 0xBA45, 16);
  addKey("TAPE", Unmapped_Key, 0xEA15, 16);
  addKey("CLEAR", Clear_Key, 0xB04F, 16); // "CANCEL"
  addKey("PROG", Program_Key, 0x30CF, 16);
  addKey("1", One_Key, 0x8877, 16);
  addKey("2", Two_Key, 0x48B7, 16);
  addKey("3", Three_Key, 0xC837, 16);
  addKey("4", Four_Key, 0x28D7, 16);
  addKey("5", Five_Key, 0xA857, 16);
  addKey("6", Six_Key, 0x6897, 16);
  addKey("7", Seven_Key, 0xE817, 16);
  addKey("8", Eight_Key, 0x18E7, 16);
  addKey("9", Nine_Key, 0x9867, 16);
  addKey("0", Zero_Key, 0x08F7, 16);
  addKey("10", Unmapped_Key, 0x02FD, 16);
  addKey("11", Unmapped_Key, 0x827D, 16);
  addKey("12", Unmapped_Key, 0x42BD, 16);
  addKey("13", Unmapped_Key, 0xC23D, 16);
  addKey("14", Unmapped_Key, 0x22DD, 16);
  addKey("15", Unmapped_Key, 0xA25D, 16);
  addKey("16", Unmapped_Key, 0x629D, 16);
  addKey("17", Unmapped_Key, 0xE21D, 16);
  addKey("18", Unmapped_Key, 0x12ED, 16);
  addKey("19", Unmapped_Key, 0x926D, 16);
  addKey("20", Unmapped_Key, 0x52AD, 16);
  addKey("21", Unmapped_Key, 0xD22D, 16);
  addKey("22", Unmapped_Key, 0x32CD, 16);
  addKey("23", Unmapped_Key, 0xB24D, 16);
  addKey("24", Unmapped_Key, 0x728D, 16);
  addKey("PLUS10", DoubleDigit_Key, 0x58A7, 16);
  addKey("INDEX", Unmapped_Key, 0xD02F, 16);
  addKey("REPEAT", Unmapped_Key, 0x10EF, 16); // "REPEAT_S/F/OFF", "S/F"
  addKey("RANDOM", Unmapped_Key, 0xD827, 16); // "AUTO"
  addKey("SEARCH_BACK", Rewind_Key, 0xA05F, 16);
  addKey("SEARCH_FWD", FastForward_Key, 0x609F, 16);
  addKey("OUTPUT_MINUS", VolumeDown_Key, 0x38C7, 16);
  addKey("OUTPUT_PLUS", VolumeUp_Key, 0xB847, 16);
  addKey("SKIP_BACK", Previous_Key, 0x20DF, 16); // "-", "PREV"
  addKey("SKIP_FWD", Next_Key, 0xE01F, 16); // "+", "NEXT"
  addKey("STOP", Stop_Key, 0x6A95, 16);
  addKey("PAUSE", Pause_Key, 0xAA55, 16);
  addKey("PLAY", Play_Key, 0x40BF, 16);
  addKey("DEL", Unmapped_Key, 0x708F, 16);
  addKey("REPEAT_A-B", Unmapped_Key, 0x906F, 16);
  addKey("DISC_SKIP_FORWARD", Unmapped_Key, 0xF20D, 16);
  addKey("DISC_SKIP_REVERSE", Unmapped_Key, 0x0AF5, 16);
  addKey("MODE", Unmapped_Key, 0x00FF, 16);
  addKey("DISC_SCAN", Unmapped_Key, 0xCA35, 16);
}


YamahaAudio1a::YamahaAudio1a(
  QObject *guiObject,
  unsigned int index)
  : YamahaAudio1(guiObject, index)
{
  setKeysetName("Audio Keyset 1a");

  addKey("PAUSE/STOP", Stop_Key, 0xC03F, 16);
  addKey("PAUSE/STOP", Pause_Key, 0xC03F, 16);
}


YamahaAudio2::YamahaAudio2(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 2",
      Yamaha_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index);

  setPreData(0x5EA1, 16);

  addKey("Power", Power_Key, 0xF807, 16); // "STANDBY"
  addKey("mute", Mute_Key, 0x38C7, 16); // "-20DB"
  addKey("vol+", VolumeUp_Key, 0x58A7, 16);
  addKey("vol-", VolumeDown_Key, 0xD827, 16);
  addKey("cd", Unmapped_Key, 0xA857, 16);
  addKey("tuner", Unmapped_Key, 0x6897, 16);
  addKey("tapemonitor", Unmapped_Key, 0x18E7, 16); // "Tape/MD_Monitor", "DAT"
  addKey("dvdld", Unmapped_Key, 0xE817, 16); // "d-tv/cbl", "AUX"
  addKey("tvdbs", Unmapped_Key, 0x2AD5, 16); // "SAT/D-TV" "d-tv/cbl alt"
  addKey("vcr", Unmapped_Key, 0xF00F, 16);
  addKey("phono", Unmapped_Key, 0x28D7, 16);
  addKey("vaux", Unmapped_Key, 0xAA55, 16); // "GO_CDV1"
  addKey("extdecoder", Unmapped_Key, 0xE11E, 16); // "ExternalDecoder", "6chIN"
  addKey("ch-", ChannelDown_Key, 0x8877, 16);
  addKey("ch+", ChannelUp_Key, 0x08F7, 16);
  addKey("abcde", Unmapped_Key, 0x48B7, 16); // "A/B/C/D/E" "tuner-toggle"
  addKey("sleep", Sleep_Key, 0xEA15, 16);
  addKey("display", Info_Key, 0x43BC, 16); // "onscreen"
  addKey("on", Unmapped_Key, 0xB847, 16); // Map this to "Power_Key"?
  addKey("off", Unmapped_Key, 0x7887, 16); // and this?
  addKey("test", Unmapped_Key, 0xA15E, 16); // "DSP_TEST"
  addKey("effect", Unmapped_Key, 0x6A95, 16);
  addKey("up", Up_Key, 0x19E6, 16);
  addKey("down", Down_Key, 0x9966, 16);
  addKey("left", Left_Key, 0xCA35, 16); // "DSP-", "DELAY_TIME-"
  addKey("right", Right_Key, 0x4AB5, 16);  // "DSP+", "DELAY_TIME+"
  addKey("level", Unmapped_Key, 0x619E, 16); // "Time/Level"
  addKey("setmenu", Unmapped_Key, 0x39C6, 16);
  addKey("setmenu-", Unmapped_Key, 0xB946, 16);
  addKey("effect-", Unmapped_Key, 0x9A65, 16); // "DSP_Prg-"
  addKey("effect+", Unmapped_Key, 0x1AE5, 16); // "DSP_Prg+"
  addKey("dolbydts", Surround_Key, 0x11EE, 16); // "PRO_LOGIC_SURROUND"
  addKey("movietheater1", Unmapped_Key, 0x916E, 16); // "PRO_LOGIC_ENHANCED"
  addKey("movietheater2", Unmapped_Key, 0x51AE, 16); // "CNCT_VIDEO"
  addKey("monomovie", Unmapped_Key, 0xD12E, 16);
  addKey("tvsports", Unmapped_Key, 0x31CE, 16); // "ROCK"
  addKey("disco", Unmapped_Key, 0xB14E, 16); // "HALL"
  addKey("rock", Unmapped_Key, 0x718E, 16);
  addKey("jazzclub", Unmapped_Key, 0xF10E, 16);
  addKey("church", Unmapped_Key, 0x09F6, 16);
  addKey("hall", Unmapped_Key, 0x8976, 16);
  addKey("DiscSkip", Unmapped_Key, 0xF20D, 16); // "CD_DISC"
  addKey("TapeRec", Record_Key, 0x20DF, 16); // "TAPE_RECPAUSE"
  addKey("TapeDeckA/B", Unmapped_Key, 0x609F, 16);
  addKey("TapeRewind", Unmapped_Key, 0x807F, 16);
  addKey("TapeForward", Unmapped_Key, 0x40BF, 16);
  addKey("TapePlay", Unmapped_Key, 0x00FF, 16);
  addKey("TapeStop", Unmapped_Key, 0xC03F, 16);
  addKey("TapeDirA", Unmapped_Key, 0xE01F, 16);
  addKey("TapeDirB", Unmapped_Key, 0x02FD, 16);
  addKey("CDSkipBack", Replay_Key, 0xD02F, 16);
  addKey("CDSkipForward", Advance_Key, 0x50AF, 16);
  addKey("CDPlay", Play_Key, 0x10EF, 16);
  addKey("CDPause/Stop", Pause_Key, 0x906F, 16);
  addKey("CDPause/Stop", Stop_Key, 0x906F, 16);
  addKey("CDRewind", Rewind_Key, 0xB04F, 16);
  addKey("CDForward", FastForward_Key, 0x30CF, 16);
  addKey("TAPE2", Unmapped_Key, 0x9867, 16);
  addKey("CENTRE_MODE", Unmapped_Key, 0x21DE, 16);
  addKey("FRONT_EFFECT_LEVEL_+", Unmapped_Key, 0x01FE, 16);
  addKey("FRONT_EFFECT_LEVEL_-", Unmapped_Key, 0x817E, 16);
  addKey("CENTRE_LEVEL_+", Unmapped_Key, 0x41BE, 16);
  addKey("CENTRE_LEVEL_-", Unmapped_Key, 0xC13E, 16);
  addKey("REAR_LEVEL_+", Unmapped_Key, 0x7A85, 16);
  addKey("REAR_LEVEL_-", Unmapped_Key, 0xFA05, 16);
  addKey("PHONO_PLAY/CUT", Unmapped_Key, 0x708F, 16);
  addKey("TAPE_REC_MUTE", Unmapped_Key, 0xA05F, 16);
  addKey("EQ_PRESET_SKIP", Unmapped_Key, 0xDA25, 16);
  addKey("EQ_ON/FLAT", Unmapped_Key, 0x5AA5, 16);
  addKey("GO_VCR2", Unmapped_Key, 0xC837, 16);
}


YamahaAudio2a::YamahaAudio2a(
  QObject *guiObject,
  unsigned int index)
  : YamahaAudio2(guiObject, index)
{
  setKeysetName("Audio Keyset 2a");

  addKey("Dolby/DTS", Unmapped_Key, 0x09F6, 16);
  addKey("6.1/5.1", Unmapped_Key, 0xE916, 16);
  addKey("Night", Unmapped_Key, 0xA956, 16);
  addKey("Stereo", Unmapped_Key, 0x6A95, 16);
}


YamahaAudio2b::YamahaAudio2b(
  QObject *guiObject,
  unsigned int index)
  : YamahaAudio2(guiObject, index)
{
  setKeysetName("Audio Keyset 2b");

  addKey("SOURCE_DIRECT", Unmapped_Key, 0x6A95, 16);
}


YamahaAudio2c::YamahaAudio2c(
  QObject *guiObject,
  unsigned int index)
  : YamahaAudio2(guiObject, index)
{
  setKeysetName("Audio Keyset 2c");

  addKey("1", One_Key, 0x11EE, 16);
  addKey("2", Two_Key, 0x916E, 16);
  addKey("3", Three_Key, 0x51AE, 16);
  addKey("4", Four_Key, 0xD12E, 16);
  addKey("5", Five_Key, 0x31CE, 16);
  addKey("6", Six_Key, 0xB14E, 16);
  addKey("7", Seven_Key, 0x718E, 16);
  addKey("8", Eight_Key, 0xF10E, 16);
  addKey("9", Nine_Key, 0x09F6, 16);
  addKey("0", Zero_Key, 0x8976, 16);
  addKey("set+", Unmapped_Key, 0x7986, 16);
  addKey("set-", Unmapped_Key, 0xF906, 16);
  addKey("set^", Unmapped_Key, 0xB946, 16);
  addKey("setv", Unmapped_Key, 0x39C6, 16);
  addKey("parameter^", Unmapped_Key, 0xA35C, 16);
  addKey("parameterv", Unmapped_Key, 0x23DC, 16);
  addKey("parameter-", Unmapped_Key, 0xE31C, 16);
  addKey("parameter+", Unmapped_Key, 0x639C, 16);
}


YamahaAudio2d::YamahaAudio2d(
  QObject *guiObject,
  unsigned int index)
  : YamahaAudio2(guiObject, index)
{
  setKeysetName("Audio Keyset 2d");

  addKey("LOUDNESS_-", Unmapped_Key, 0x7887, 16);
  addKey("LOUDNESS_+", Unmapped_Key, 0xB847, 16);
}


YamahaAudio3::YamahaAudio3(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 3",
      Yamaha_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index);

  setPreData(0xFE01, 16);

  addKey("PLAY", Play_Key, 0x00FF, 16);
  addKey("STOP", Stop_Key, 0xC03F, 16);
  addKey("RECORD/PAUSE", Record_Key, 0x20DF, 16);
  addKey("FAST_FORWARD", FastForward_Key, 0x40BF, 16);
  addKey("REWIND", Rewind_Key, 0x807F, 16);
  addKey("RECORD_MUTE", Unmapped_Key, 0xA05F, 16);
  addKey("INTRO_SCAN_FORWARD", Unmapped_Key, 0x7887, 16);
  addKey("INTRO_SCAN_REVERSE", Unmapped_Key, 0xF807, 16);
  addKey("SEARCH_FORWARD", Advance_Key, 0x50AF, 16);
  addKey("SEARCH_REVERSE", Replay_Key, 0xD02F, 16);
  addKey("DIRECTION_<>", Unmapped_Key, 0xE01F, 16); // "DIR_A"
  addKey("DIR_B", Unmapped_Key, 0x10EF, 16);
  addKey("DECK_A/B", Unmapped_Key, 0x609F, 16);
  addKey("MONITOR", Unmapped_Key, 0xF00F, 16);
  addKey("DUBBING", Unmapped_Key, 0x906F, 16);
  addKey("COUNTER_RESET", Reset_Key, 0xB04F, 16);
  addKey("COUNTER_REMAIN", Unmapped_Key, 0xB847, 16);
  addKey("COUNTER_MEMORY", Unmapped_Key, 0x708F, 16);
  addKey("COUNTER_TAPE", Unmapped_Key, 0x30CF, 16);
  addKey("1", One_Key, 0x8877, 16);
  addKey("2", Two_Key, 0x48B7, 16);
  addKey("3", Three_Key, 0xC837, 16);
  addKey("4", Four_Key, 0x28D7, 16);
  addKey("5", Five_Key, 0xA857, 16);
  addKey("6", Six_Key, 0x6897, 16);
  addKey("7", Seven_Key, 0xE817, 16);
  addKey("8", Eight_Key, 0x18E7, 16);
  addKey("9", Nine_Key, 0x9867, 16);
  addKey("0", Zero_Key, 0x08F7, 16);
  addKey("CLEAR", Clear_Key, 0xD827, 16);
  addKey("PROG", Program_Key, 0x58A7, 16);
  addKey("RUN", Unmapped_Key, 0x38C7, 16);
}


YamahaAudio4::YamahaAudio4(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 4",
      Yamaha_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index);

  setPreData(0x857A, 16);

  addKey("CD_PLAY", Play_Key, 0xF708, 16);
  addKey("CD_PAUSE/STOP", Pause_Key, 0xF609, 16);
  addKey("CD_PAUSE/STOP", Stop_Key, 0xF609, 16);
  addKey("CD_SEARCH_>", FastForward_Key, 0xF30C, 16); // Might be wrong
  addKey("CD_SEARCH_<", Rewind_Key, 0xF20D, 16); // And this
  addKey("CD_TRACK_+", Next_Key, 0xF50A, 16);
  addKey("CD_TRACK_-", Previous_Key, 0xF40B, 16);
  addKey("CD_DISK", Unmapped_Key, 0xB04F, 16);
  addKey("TAPE_PLAY", Unmapped_Key, 0xFF00, 16);
  addKey("TAPE_STOP", Unmapped_Key, 0xFC03, 16);
  addKey("TAPE_SEARCH_>", Unmapped_Key, 0xFD02, 16);
  addKey("TAPE_SEARCH_<", Unmapped_Key, 0xFE01, 16);
  addKey("TAPE_DIR_A", Unmapped_Key, 0xF807, 16);
  addKey("TAPE_DIR_B", Unmapped_Key, 0xBF40, 16);
  addKey("TAPE_REC/PAUSE", Unmapped_Key, 0xFB04, 16);
  addKey("TAPE_REC/MUTE", Unmapped_Key, 0xFA05, 16);
  addKey("TAPE_A/B", Unmapped_Key, 0xF906, 16);
  addKey("AMP_AUX", Unmapped_Key, 0xE817, 16);
  addKey("AMP_TAPE1", Unmapped_Key, 0xE718, 16);
  addKey("AMP_TAPE2", Unmapped_Key, 0xE619, 16);
  addKey("AMP_TUNER", Unmapped_Key, 0xE916, 16);
  addKey("AMP_CD", Unmapped_Key, 0xEA15, 16);
  addKey("AMP_PHONO", Unmapped_Key, 0xEB14, 16);
  addKey("AMP_SLEEP", Sleep_Key, 0xA857, 16);
  addKey("AMP_POWER", Power_Key, 0xE01F, 16);
  addKey("VOL_UP", VolumeUp_Key, 0xE51A, 16);
  addKey("VOL_DOWN", VolumeDown_Key, 0xE41B, 16);
  addKey("TUNER_PRESET_+", ChannelUp_Key, 0xEF10, 16);
  addKey("TUNER_PRESET_-", ChannelDown_Key, 0xEE11, 16);
  addKey("TUNER_ABCDE", Unmapped_Key, 0xED12, 16);
  addKey("EQ_PRESET_SKIP", Unmapped_Key, 0xA45B, 16);
  addKey("EQ_ON/FLAT", Unmapped_Key, 0xA55A, 16);
  addKey("PHONO_PLAY/CUT", Unmapped_Key, 0xF10E, 16);
}


YamahaAudio5::YamahaAudio5(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 5",
      Yamaha_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index);

  setPreData(0xA25D, 16);

  addKey("Power", Power_Key, 0x48B7, 16);
  addKey("Rewind", Rewind_Key, 0x9867, 16);
  addKey("Forward", FastForward_Key, 0xC837, 16);
  addKey("SkipBack", Replay_Key, 0xC43B, 16);
  addKey("SkipForward", Advance_Key, 0x24DB, 16);
  addKey("Pause", Pause_Key, 0x00FF, 16);
  addKey("Stop", Stop_Key, 0x28D7, 16);
  addKey("Play", Play_Key, 0xA857, 16);
  addKey("Title", DiscTitle_Key, 0x7B84, 16);
  addKey("Menu", DiscMenu_Key, 0x21DE, 16);
  addKey("Up", Up_Key, 0x01FE, 16);
  addKey("Down", Down_Key, 0x817E, 16);
  addKey("Left", Left_Key, 0x8A75, 16);
  addKey("Right", Right_Key, 0xB24D, 16);
  addKey("Select", Select_Key, 0x847B, 16);
  addKey("Clear", Clear_Key, 0xF708, 16);
  addKey("Return", Exit_Key, 0x44BB, 16);
  addKey("Display", Info_Key, 0x6897, 16);
  addKey("Index", Unmapped_Key, 0x649B, 16);
  addKey("+10", DoubleDigit_Key, 0xA45B, 16);
  addKey("0", Zero_Key, 0x50AF, 16);
  addKey("1", One_Key, 0x807F, 16);
  addKey("2", Two_Key, 0x40BF, 16);
  addKey("3", Three_Key, 0xC03F, 16);
  addKey("4", Four_Key, 0x20DF, 16);
  addKey("5", Five_Key, 0xA05F, 16);
  addKey("6", Six_Key, 0x609F, 16);
  addKey("7", Seven_Key, 0xE01F, 16);
  addKey("8", Eight_Key, 0x10EF, 16);
  addKey("9", Nine_Key, 0x906F, 16);
}


YamahaAudio6::YamahaAudio6(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 6",
      Yamaha_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index);

  setPreData(0x8B74, 16);

  addKey("A/B/C/D/E", Unmapped_Key, 0xB04F, 16);
  addKey("1", One_Key, 0x708F, 16);
  addKey("2", Two_Key, 0xF00F, 16);
  addKey("3", Three_Key, 0x08F7, 16);
  addKey("4", Four_Key, 0x8877, 16);
  addKey("5", Five_Key, 0x48B7, 16);
  addKey("6", Six_Key, 0xC837, 16);
  addKey("7", Seven_Key, 0x28D7, 16);
  addKey("8", Eight_Key, 0xA857, 16);
}


YamahaAudio7::YamahaAudio7(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 7",
      Yamaha_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index);

  setPreData(0x1EE1, 16);

  addKey("1", One_Key, 0x8877, 16);
  addKey("2", Two_Key, 0x48B7, 16);
  addKey("3", Three_Key, 0xC837, 16);
  addKey("4", Four_Key, 0x28D7, 16);
  addKey("5", Five_Key, 0xA857, 16);
  addKey("6", Six_Key, 0x6897, 16);
  addKey("7", Seven_Key, 0xE817, 16);
  addKey("8", Eight_Key, 0x18E7, 16);
  addKey("9", Nine_Key, 0x9867, 16);
  addKey("0", Zero_Key, 0x08F7, 16);
  addKey("time", Unmapped_Key, 0x50AF, 16);
  addKey("prog", Program_Key, 0xD02F, 16);
  addKey("tape", Unmapped_Key, 0x10EF, 16);
  addKey("edit", Unmapped_Key, 0x906F, 16);
  addKey("+10", DoubleDigit_Key, 0x58A7, 16);
  addKey("mode", Unmapped_Key, 0xBA45, 16);
  addKey("repeat", Unmapped_Key, 0x30CF, 16);
  addKey("random", Unmapped_Key, 0xE01F, 16);
  addKey("open", Eject_Key, 0x00FF, 16);
  addKey("tuner", Unmapped_Key, 0xD22D, 16);
  addKey("disc_skip", Unmapped_Key, 0xB04F, 16);
  addKey("cd_last", Previous_Key, 0x20DF, 16);
  addKey("cd_next", Next_Key, 0xC03F, 16);
  addKey("cd_stop", Stop_Key, 0x807F, 16);
  addKey("cd_play", Play_Key, 0x40BF, 16);
  addKey("location", Unmapped_Key, 0xDA25, 16);
  addKey("up_arrow", Up_Key, 0xAA55, 16);
  addKey("tape_play_back", Unmapped_Key, 0xC23D, 16);
  addKey("tape_stop", Unmapped_Key, 0x827D, 16);
  addKey("tape_play_forward", Unmapped_Key, 0x42BD, 16);
  addKey("left_arrow", Left_Key, 0xEA15, 16);
  addKey("music", Unmapped_Key, 0x5AA5, 16);
  addKey("right_arrow", Right_Key, 0x1AE5, 16);
  addKey("tape_back", Unmapped_Key, 0xA25D, 16);
  addKey("tape_forward", Unmapped_Key, 0x22DD, 16);
  addKey("user", Unmapped_Key, 0x3AC5, 16);
  addKey("down_arrow", Down_Key, 0x6A95, 16);
  addKey("flat", Unmapped_Key, 0x9A65, 16);
  addKey("rec", Record_Key, 0x629D, 16);
  addKey("tape1/2", Unmapped_Key, 0xE21D, 16);
  addKey("sleep", Sleep_Key, 0xF20D, 16);
  addKey("-", Unmapped_Key, 0xF807, 16);
  addKey("power", Power_Key, 0xF00F, 16);
  addKey("+", Unmapped_Key, 0x7887, 16);
  addKey("input", Input_Key, 0x7A85, 16);
}


YamahaTV1::YamahaTV1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Yamaha_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index);

  setPreData(0x20DF, 16);

  addKey("1", One_Key, 0x8877, 16);
  addKey("2", Two_Key, 0x48B7, 16);
  addKey("3", Three_Key, 0xC837, 16);
  addKey("4", Four_Key, 0x28D7, 16);
  addKey("5", Five_Key, 0xA857, 16);
  addKey("6", Six_Key, 0x6897, 16);
  addKey("7", Seven_Key, 0xE817, 16);
  addKey("8", Eight_Key, 0x18E7, 16);
  addKey("9", Nine_Key, 0x9867, 16);
  addKey("0", Zero_Key, 0x08F7, 16);
  addKey("ch+", ChannelUp_Key, 0x00FF, 16);
  addKey("ch-", ChannelDown_Key, 0x807F, 16);
  addKey("vol+", VolumeUp_Key, 0x40BF, 16);
  addKey("vol-", VolumeDown_Key, 0xC03F, 16);
  addKey("mute", Mute_Key, 0x906F, 16);
  addKey("goback", PrevChannel_Key, 0x58A7, 16);
}


YamahaKaraoke1::YamahaKaraoke1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Karaoke Keyset 1",
      Yamaha_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index);

  setPreData(0xDE21, 16);

  addKey("POWER", Power_Key, 0x01FE, 16);
  addKey("VOL+", VolumeUp_Key, 0x41BE, 16);
  addKey("VOL-", VolumeDown_Key, 0xC13E, 16);
  addKey("VCR", Unmapped_Key, 0x718E, 16);
  addKey("TAPE", Unmapped_Key, 0xF10E, 16);
  addKey("CD/CDG", Unmapped_Key, 0xB14E, 16);
  addKey("LD", Unmapped_Key, 0x31CE, 16);
  addKey("AUX1", Unmapped_Key, 0x8976, 16);
  addKey("AUX2", Unmapped_Key, 0x09F6, 16);
  addKey("VOCAL_AID", Unmapped_Key, 0x9B64, 16);
  addKey("ONE_TOUCH_KAR.", Unmapped_Key, 0x5BA4, 16);
  addKey("MPX/STEREO", Unmapped_Key, 0x1BE4, 16);
  addKey("BALLAD", Unmapped_Key, 0x9966, 16);
  addKey("POPS", Unmapped_Key, 0x59A6, 16);
  addKey("JAZZ", Unmapped_Key, 0xD926, 16);
  addKey("ROCK", Unmapped_Key, 0x39C6, 16);
  addKey("B_SYMBOL", Unmapped_Key, 0x6996, 16);
  addKey("SQUARE_SYMBOL", Unmapped_Key, 0xE916, 16);
  addKey("HASH", Unmapped_Key, 0x19E6, 16);
}
