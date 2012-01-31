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
  threadableProtocol = new NECProtocol(guiObject, index, Standard_NEC);

//  setPreData(0x3EC1, 16);
  setPreData(0x7C, 8);

  addKey("power_av", Power_Key, 0x80, 16); // might be wrong
  addKey("play", Play_Key, 0x82, 8);
  addKey("pause", Pause_Key, 0x83, 8);
  addKey("stop", Stop_Key, 0x85, 8);
  addKey("rewind", Rewind_Key, 0x86, 8);
  addKey("fast_forward", FastForward_Key, 0x87, 8);
  addKey("record", Record_Key, 0x8B, 8);

  addKey("0", Zero_Key, 0x93, 8);
  addKey("1", One_Key, 0x94, 8);
  addKey("2", Two_Key, 0x95, 8);
  addKey("3", Three_Key, 0x96, 8);
  addKey("4", Four_Key, 0x97, 8);
  addKey("5", Five_Key, 0x98, 8);
  addKey("6", Six_Key, 0x99, 8);
  addKey("7", Seven_Key, 0x9A, 8);
  addKey("8", Eight_Key, 0x9B, 8);
  addKey("9", Nine_Key, 0x9C, 8);
  addKey("+10", DoubleDigit_Key, 0x9D, 8);
  addKey("ent", Enter_Key, 0x9E, 8);

  addKey("display", Info_Key, 0xA6, 8);
  addKey("title", DiscTitle_Key, 0xB1, 8);
  addKey("menu", DiscMenu_Key, 0xB2, 8);
  addKey("down", Down_Key, 0xB3, 8);
  addKey("up", Up_Key, 0xB4, 8);
  addKey("left", Left_Key, 0xB5, 8);
  addKey("right", Right_Key, 0xB6, 8);
  addKey("return", Exit_Key, 0xB7, 8);
  addKey("enter", Select_Key, 0xB8, 8);
  addKey("previous", Previous_Key, 0xB9, 8);
  addKey("next", Next_Key, 0xBA, 8);
}


YamahaDVD1a::YamahaDVD1a(
  QObject *guiObject,
  unsigned int index)
  : YamahaDVD1(guiObject, index)
{
  setKeysetName("DVD/LD Keyset 1a");

  addKey("LD_CH_-", ChannelDown_Key, 0x02, 8);
  addKey("LD_CH_+", ChannelUp_Key, 0x03, 8);
  addKey("LD_PAUSE/STOP", Pause_Key, 0x04, 8);
  addKey("LD_PLAY", Play_Key, 0x05, 8);
  addKey("LD_SCH_FWD", FastForward_Key, 0x07, 8);
  addKey("LD_SCH_REV", Rewind_Key, 0x06, 8);
  addKey("LD_STILL_REV", StepBack_Key, 0x0A, 8);
  addKey("LD_STILL_FWD", StepForward_Key, 0x0B, 8);
  addKey("SOUND", Unmapped_Key, 0x12, 8);
  addKey("DISPLAY", Info_Key, 0x13, 8);
  addKey("LD_STOP", Stop_Key, 0x5B, 8);
}


YamahaAudio1::YamahaAudio1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Device Keyset 1",
      Yamaha_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index, Standard_NEC);

//  setPreData(0x9E61, 16);
  setPreData(0x79, 8);

  addKey("MODE", Unmapped_Key, 0x00, 8);
  addKey("OPEN", Eject_Key, 0x01, 8);
  addKey("PLAY", Play_Key, 0x02, 8);
  addKey("SKIP_BACK", Previous_Key, 0x04, 8); // "-", "PREV"
  addKey("SEARCH_BACK", Rewind_Key, 0x05, 8);
  addKey("SEARCH_FWD", FastForward_Key, 0x06, 8);
  addKey("SKIP_FWD", Next_Key, 0x07, 8); // "+", "NEXT"
  addKey("REPEAT", Repeat_Key, 0x08, 8); // "REPEAT_S/F/OFF", "S/F"
  addKey("REPEAT_A-B", RepeatAB_Key, 0x09, 8);
  addKey("TIME", Info_Key, 0x0A, 8); // "TIME_DISPLAY"
  addKey("INDEX", Unmapped_Key, 0x0B, 8);
  addKey("PROG", Program_Key, 0x0C, 8);
  addKey("CLEAR", Clear_Key, 0x0D, 8); // "CANCEL"
  addKey("DEL", Unmapped_Key, 0x0E, 8);
  addKey("SPACE", Unmapped_Key, 0x0F, 8);
  addKey("0", Zero_Key, 0x10, 8);
  addKey("1", One_Key, 0x11, 8);
  addKey("2", Two_Key, 0x12, 8);
  addKey("3", Three_Key, 0x13, 8);
  addKey("4", Four_Key, 0x14, 8);
  addKey("5", Five_Key, 0x15, 8);
  addKey("6", Six_Key, 0x16, 8);
  addKey("7", Seven_Key, 0x17, 8);
  addKey("8", Eight_Key, 0x18, 8);
  addKey("9", Nine_Key, 0x19, 8);
  addKey("PLUS10", DoubleDigit_Key, 0x1A, 8);
  addKey("RANDOM", Random_Key, 0x1B, 8); // "AUTO"
  addKey("OUTPUT_MINUS", VolumeDown_Key, 0x1C, 8);
  addKey("OUTPUT_PLUS", VolumeUp_Key, 0x1D, 8);
  addKey("DIMMER", Unmapped_Key, 0x1E, 8); // "MODE"
  addKey("10", Unmapped_Key, 0x40, 8);
  addKey("11", Unmapped_Key, 0x41, 8);
  addKey("12", Unmapped_Key, 0x42, 8);
  addKey("13", Unmapped_Key, 0x43, 8);
  addKey("14", Unmapped_Key, 0x44, 8);
  addKey("15", Unmapped_Key, 0x45, 8);
  addKey("16", Unmapped_Key, 0x46, 8);
  addKey("17", Unmapped_Key, 0x47, 8);
  addKey("18", Unmapped_Key, 0x48, 8);
  addKey("19", Unmapped_Key, 0x49, 8);
  addKey("20", Unmapped_Key, 0x4A, 8);
  addKey("21", Unmapped_Key, 0x4B, 8);
  addKey("22", Unmapped_Key, 0x4C, 8);
  addKey("23", Unmapped_Key, 0x4D, 8);
  addKey("24", Unmapped_Key, 0x4E, 8);
  addKey("DISC_SKIP_FORWARD", DiscSelect_Key, 0x4F, 8);
  addKey("DISC_SKIP_REVERSE", Unmapped_Key, 0x50, 8);
  addKey("DISC_SCAN", Unmapped_Key, 0x53, 8);
  addKey("PAUSE", Pause_Key, 0x55, 8);
  addKey("STOP", Stop_Key, 0x56, 8);
  addKey("TAPE", Unmapped_Key, 0x57, 8);
  addKey("SYNCHRO", Unmapped_Key, 0x58, 8); // "DIRECT_OUT"
  addKey("PEAK", Unmapped_Key, 0x5D, 8);
}


YamahaAudio1a::YamahaAudio1a(
  QObject *guiObject,
  unsigned int index)
  : YamahaAudio1(guiObject, index)
{
  setKeysetName("Audio Keyset 1a");

  addKey("PAUSE/STOP", Stop_Key, 0x03, 8);
  addKey("PAUSE/STOP", Pause_Key, 0x03, 8);
}


YamahaAudio2::YamahaAudio2(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 2",
      Yamaha_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index, Standard_NEC);

//  setPreData(0x5EA1, 16);
  setPreData(0x7A, 8);

  addKey("TapePlay", Unmapped_Key, 0x00, 8);
  addKey("TapeRewind", Unmapped_Key, 0x01, 8);
  addKey("TapeForward", Unmapped_Key, 0x02, 8);
  addKey("TapeStop", Unmapped_Key, 0x03, 8);
  addKey("TapeRec", Record_Key, 0x04, 8); // "TAPE_RECPAUSE"
  addKey("TAPE_REC_MUTE", Unmapped_Key, 0x05, 8);
  addKey("TapeDeckA/B", Unmapped_Key, 0x06, 8);
  addKey("TapeDirA", Unmapped_Key, 0x07, 8);
  addKey("CDPlay", Play_Key, 0x08, 8);
  addKey("CDPause/Stop", Pause_Key, 0x09, 8);
  addKey("CDPause/Stop", Stop_Key, 0x09, 8);
  addKey("CDSkipForward", Advance_Key, 0x0A, 8);
  addKey("CDSkipBack", Replay_Key, 0x0B, 8);
  addKey("CDForward", FastForward_Key, 0x0C, 8);
  addKey("CDRewind", Rewind_Key, 0x0D, 8);
  addKey("PHONO_PLAY/CUT", Unmapped_Key, 0x0E, 8);
  addKey("vcr", Unmapped_Key, 0x0F, 8);
  addKey("ch+", ChannelUp_Key, 0x10, 8);
  addKey("ch-", ChannelDown_Key, 0x11, 8);
  addKey("abcde", TunerBand_Key, 0x12, 8); // "A/B/C/D/E" "tuner-toggle"
  addKey("GO_VCR2", Unmapped_Key, 0x13, 8);
  addKey("phono", Unmapped_Key, 0x14, 8);
  addKey("cd", Unmapped_Key, 0x15, 8);
  addKey("tuner", Unmapped_Key, 0x16, 8);
  addKey("dvdld", Unmapped_Key, 0x17, 8); // "d-tv/cbl", "AUX"
  addKey("tapemonitor", Unmapped_Key, 0x18, 8); // "Tape/MD_Monitor", "DAT"
  addKey("TAPE2", Unmapped_Key, 0x19, 8);
  addKey("vol+", VolumeUp_Key, 0x1A, 8);
  addKey("vol-", VolumeDown_Key, 0x1B, 8);
  addKey("mute", Mute_Key, 0x1C, 8); // "-20DB"
  addKey("on", PowerOn_Key, 0x1D, 8);
  addKey("off", PowerOff_Key, 0x1E, 8);
  addKey("Power", Power_Key, 0x1F, 8); // "STANDBY"

  addKey("TapeDirB", Unmapped_Key, 0x40, 8);
  addKey("DiscSkip", Unmapped_Key, 0x4F, 8); // "CD_DISC"
  addKey("right", Right_Key, 0x52, 8);  // "DSP+", "DELAY_TIME+"
  addKey("left", Left_Key, 0x53, 8); // "DSP-", "DELAY_TIME-"
  addKey("tvdbs", Unmapped_Key, 0x54, 8); // "SAT/D-TV" "d-tv/cbl alt"
  addKey("vaux", Unmapped_Key, 0x55, 8); // "GO_CDV1"
  addKey("effect", Unmapped_Key, 0x56, 8);
  addKey("sleep", Sleep_Key, 0x57, 8);
  addKey("effect+", Unmapped_Key, 0x58, 8); // "DSP_Prg+"
  addKey("effect-", Unmapped_Key, 0x59, 8); // "DSP_Prg-"
  addKey("EQ_ON/FLAT", Unmapped_Key, 0x5A, 8);
  addKey("EQ_PRESET_SKIP", Unmapped_Key, 0x5B, 8);
  addKey("REAR_LEVEL_+", Unmapped_Key, 0x5E, 8);
  addKey("REAR_LEVEL_-", Unmapped_Key, 0x5F, 8);

  addKey("FRONT_EFFECT_LEVEL_+", Unmapped_Key, 0x80, 8);
  addKey("FRONT_EFFECT_LEVEL_-", Unmapped_Key, 0x81, 8);
  addKey("CENTRE_LEVEL_+", Unmapped_Key, 0x82, 8);
  addKey("CENTRE_LEVEL_-", Unmapped_Key, 0x83, 8);
  addKey("CENTRE_MODE", Unmapped_Key, 0x84, 8);
  addKey("test", Unmapped_Key, 0x85, 8); // "DSP_TEST"
  addKey("level", Unmapped_Key, 0x86, 8); // "Time/Level"
  addKey("extdecoder", Unmapped_Key, 0x87, 8); // "ExternalDecoder", "6chIN"
  addKey("dolbydts", Surround_Key, 0x88, 8); // "PRO_LOGIC_SURROUND"
  addKey("movietheater1", Unmapped_Key, 0x89, 8); // "PRO_LOGIC_ENHANCED"
  addKey("movietheater2", Unmapped_Key, 0x8A, 8); // "CNCT_VIDEO"
  addKey("monomovie", Unmapped_Key, 0x8B, 8);
  addKey("tvsports", Unmapped_Key, 0x8C, 8); // "ROCK"
  addKey("disco", Unmapped_Key, 0x8D, 8); // "HALL"
  addKey("rock", Unmapped_Key, 0x8E, 8);
  addKey("jazzclub", Unmapped_Key, 0x8F, 8);
  addKey("church", Unmapped_Key, 0x90, 8);
  addKey("hall", Unmapped_Key, 0x91, 8);

  addKey("up", Up_Key, 0x98, 8);
  addKey("down", Down_Key, 0x99, 8);
  addKey("setmenu", Unmapped_Key, 0x9C, 8);
  addKey("setmenu-", Unmapped_Key, 0x9D, 8);
  addKey("display", Info_Key, 0xC2, 8); // "onscreen"
}


YamahaAudio2a::YamahaAudio2a(
  QObject *guiObject,
  unsigned int index)
  : YamahaAudio2(guiObject, index)
{
  setKeysetName("Audio Keyset 2a");

  addKey("Dolby/DTS", Unmapped_Key, 0x90, 8);
  addKey("6.1/5.1", Unmapped_Key, 0x97, 8);
  addKey("Night", Unmapped_Key, 0x95, 8);
  addKey("Stereo", Unmapped_Key, 0x56, 8);
}


YamahaAudio2b::YamahaAudio2b(
  QObject *guiObject,
  unsigned int index)
  : YamahaAudio2(guiObject, index)
{
  setKeysetName("Audio Keyset 2b");

  addKey("SOURCE_DIRECT", Unmapped_Key, 0x56, 8);
}


YamahaAudio2c::YamahaAudio2c(
  QObject *guiObject,
  unsigned int index)
  : YamahaAudio2(guiObject, index)
{
  setKeysetName("Audio Keyset 2c");

  addKey("parameterv", Unmapped_Key, 0xC4, 8);
  addKey("parameter^", Unmapped_Key, 0xC5, 8);
  addKey("parameter+", Unmapped_Key, 0xC6, 8);
  addKey("parameter-", Unmapped_Key, 0xC7, 8);
  addKey("1", One_Key, 0x88, 8);
  addKey("2", Two_Key, 0x89, 8);
  addKey("3", Three_Key, 0x8A, 8);
  addKey("4", Four_Key, 0x8B, 8);
  addKey("5", Five_Key, 0x8C, 8);
  addKey("6", Six_Key, 0x8D, 8);
  addKey("7", Seven_Key, 0x8E, 8);
  addKey("8", Eight_Key, 0x8F, 8);
  addKey("9", Nine_Key, 0x90, 8);
  addKey("0", Zero_Key, 0x91, 8);
  addKey("setv", Unmapped_Key, 0x9C, 8);
  addKey("set^", Unmapped_Key, 0x9D, 8);
  addKey("set+", Unmapped_Key, 0x9E, 8);
  addKey("set-", Unmapped_Key, 0x9F, 8);
}


YamahaAudio2d::YamahaAudio2d(
  QObject *guiObject,
  unsigned int index)
  : YamahaAudio2(guiObject, index)
{
  setKeysetName("Audio Keyset 2d");

  addKey("LOUDNESS_+", Unmapped_Key, 0x1D, 8);
  addKey("LOUDNESS_-", Unmapped_Key, 0x1E, 8);
}


YamahaAudio3::YamahaAudio3(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 3",
      Yamaha_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index, Standard_NEC);

//  setPreData(0xFE01, 16);
  setPreData(0x7F, 8);

  addKey("PLAY", Play_Key, 0x00, 8);
  addKey("REWIND", Rewind_Key, 0x01, 8);
  addKey("FAST_FORWARD", FastForward_Key, 0x02, 8);
  addKey("STOP", Stop_Key, 0x03, 8);
  addKey("RECORD/PAUSE", Record_Key, 0x04, 8);
  addKey("RECORD_MUTE", RecordMute_Key, 0x05, 8);
  addKey("DECK_A/B", Unmapped_Key, 0x06, 8);
  addKey("DIRECTION_<>", Unmapped_Key, 0x07, 8); // "DIR_A"
  addKey("DIR_B", Unmapped_Key, 0x08, 8);
  addKey("DUBBING", Unmapped_Key, 0x09, 8);
  addKey("SEARCH_FORWARD", Advance_Key, 0x0A, 8);
  addKey("SEARCH_REVERSE", Replay_Key, 0x0B, 8);
  addKey("COUNTER_TAPE", Unmapped_Key, 0x0C, 8);
  addKey("COUNTER_RESET", Reset_Key, 0x0D, 8);
  addKey("COUNTER_MEMORY", Unmapped_Key, 0x0E, 8);
  addKey("MONITOR", Unmapped_Key, 0x0F, 8);
  addKey("0", Zero_Key, 0x10, 8);
  addKey("1", One_Key, 0x11, 8);
  addKey("2", Two_Key, 0x12, 8);
  addKey("3", Three_Key, 0x13, 8);
  addKey("4", Four_Key, 0x14, 8);
  addKey("5", Five_Key, 0x15, 8);
  addKey("6", Six_Key, 0x16, 8);
  addKey("7", Seven_Key, 0x17, 8);
  addKey("8", Eight_Key, 0x18, 8);
  addKey("9", Nine_Key, 0x19, 8);
  addKey("PROG", Program_Key, 0x1A, 8);
  addKey("CLEAR", Clear_Key, 0x1B, 8);
  addKey("RUN", Unmapped_Key, 0x1C, 8);
  addKey("COUNTER_REMAIN", Unmapped_Key, 0x1D, 8);
  addKey("INTRO_SCAN_FORWARD", Unmapped_Key, 0x1E, 8);
  addKey("INTRO_SCAN_REVERSE", Unmapped_Key, 0x1F, 8);
}


// This one is strange, need to look at it harder:
YamahaAudio4::YamahaAudio4(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 4",
      Yamaha_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index, LIRC_NEC);

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
  addKey("TUNER_ABCDE", TunerBand_Key, 0xED12, 16);
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
  threadableProtocol = new NECProtocol(guiObject, index, Standard_NEC);

//  setPreData(0xA25D, 16);
  setPreData(0x45, 8);

  addKey("Pause", Pause_Key, 0x00, 8);
  addKey("1", One_Key, 0x01, 8);
  addKey("2", Two_Key, 0x02, 8);
  addKey("3", Three_Key, 0x03, 8);
  addKey("4", Four_Key, 0x04, 8);
  addKey("5", Five_Key, 0x05, 8);
  addKey("6", Six_Key, 0x06, 8);
  addKey("7", Seven_Key, 0x07, 8);
  addKey("8", Eight_Key, 0x08, 8);
  addKey("9", Nine_Key, 0x09, 8);
  addKey("0", Zero_Key, 0x0A, 8);
  addKey("Power", Power_Key, 0x12, 8);
  addKey("Forward", FastForward_Key, 0x13, 8);
  addKey("Stop", Stop_Key, 0x14, 8);
  addKey("Play", Play_Key, 0x15, 8);
  addKey("Display", Info_Key, 0x16, 8);
  addKey("Rewind", Rewind_Key, 0x19, 8);
  addKey("Select", Select_Key, 0x21, 8);
  addKey("Return", Exit_Key, 0x22, 8);
  addKey("SkipBack", Replay_Key, 0x23, 8);
  addKey("SkipForward", Advance_Key, 0x24, 8);
  addKey("+10", DoubleDigit_Key, 0x25, 8);
  addKey("Index", Unmapped_Key, 0x26, 8);
  addKey("Right", Right_Key, 0x4D, 8);
  addKey("Left", Left_Key, 0x51, 8);
  addKey("Up", Up_Key, 0x80, 8);
  addKey("Down", Down_Key, 0x81, 8);
  addKey("Menu", DiscMenu_Key, 0x84, 8);
  addKey("Title", DiscTitle_Key, 0xDE, 8);
  addKey("Clear", Clear_Key, 0xEF, 8);
}


YamahaAudio6::YamahaAudio6(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 6",
      Yamaha_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index, Standard_NEC);

//  setPreData(0x8B74, 16);
  setPreData(0xD1, 8);

  addKey("A/B/C/D/E", TunerBand_Key, 0x0D, 8);
  addKey("1", One_Key, 0x0E, 8);
  addKey("2", Two_Key, 0x0F, 8);
  addKey("3", Three_Key, 0x10, 8);
  addKey("4", Four_Key, 0x11, 8);
  addKey("5", Five_Key, 0x12, 8);
  addKey("6", Six_Key, 0x13, 8);
  addKey("7", Seven_Key, 0x14, 8);
  addKey("8", Eight_Key, 0x15, 8);
}


YamahaAudio7::YamahaAudio7(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 7",
      Yamaha_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index, Standard_NEC);

//  setPreData(0x1EE1, 16);
  setPreData(0x78, 8);

  addKey("open", Eject_Key, 0x00, 8);
  addKey("cd_stop", Stop_Key, 0x01, 8);
  addKey("cd_play", Play_Key, 0x02, 8);
  addKey("cd_next", Next_Key, 0x03, 8);
  addKey("cd_last", Previous_Key, 0x04, 8);
  addKey("random", Random_Key, 0x07, 8);
  addKey("tape", Unmapped_Key, 0x08, 8);
  addKey("edit", Unmapped_Key, 0x09, 8);
  addKey("time", Unmapped_Key, 0x0A, 8);
  addKey("prog", Program_Key, 0x0B, 8);
  addKey("repeat", Repeat_Key, 0x0C, 8);
  addKey("disc_skip", DiscSelect_Key, 0x0D, 8);
  addKey("power", Power_Key, 0x0F, 8);
  addKey("0", Zero_Key, 0x10, 8);
  addKey("1", One_Key, 0x11, 8);
  addKey("2", Two_Key, 0x12, 8);
  addKey("3", Three_Key, 0x13, 8);
  addKey("4", Four_Key, 0x14, 8);
  addKey("5", Five_Key, 0x15, 8);
  addKey("6", Six_Key, 0x16, 8);
  addKey("7", Seven_Key, 0x17, 8);
  addKey("8", Eight_Key, 0x18, 8);
  addKey("9", Nine_Key, 0x19, 8);
  addKey("+10", DoubleDigit_Key, 0x1A, 8);
  addKey("+", ChannelUp_Key, 0x1E, 8);
  addKey("-", ChannelDown_Key, 0x1F, 8);
  addKey("tape_stop", Unmapped_Key, 0x41, 8);
  addKey("tape_play_forward", Unmapped_Key, 0x42, 8);
  addKey("tape_play_back", Unmapped_Key, 0x43, 8);
  addKey("tape_forward", Unmapped_Key, 0x44, 8);
  addKey("tape_back", Unmapped_Key, 0x45, 8);
  addKey("rec", Record_Key, 0x46, 8);
  addKey("tape1/2", Unmapped_Key, 0x47, 8);
  addKey("tuner", TunerBand_Key, 0x4B, 8);
  addKey("sleep", Sleep_Key, 0x4F, 8);
  addKey("up_arrow", Up_Key, 0x55, 8);
  addKey("down_arrow", Down_Key, 0x56, 8);
  addKey("left_arrow", Left_Key, 0x57, 8);
  addKey("right_arrow", Right_Key, 0x58, 8);
  addKey("flat", Unmapped_Key, 0x59, 8);
  addKey("music", Unmapped_Key, 0x5A, 8);
  addKey("location", Unmapped_Key, 0x5B, 8);
  addKey("user", Unmapped_Key, 0x5C, 8);
  addKey("mode", Unmapped_Key, 0x5D, 8);
  addKey("input", Input_Key, 0x5E, 8);
}


YamahaTV1::YamahaTV1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Yamaha_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index, Standard_NEC);

//  setPreData(0x20DF, 16);
  setPreData(0x04, 8);

  addKey("ch+", ChannelUp_Key, 0x00, 8);
  addKey("ch-", ChannelDown_Key, 0x01, 8);
  addKey("vol+", VolumeUp_Key, 0x02, 8);
  addKey("vol-", VolumeDown_Key, 0x03, 8);
  addKey("mute", Mute_Key, 0x09, 8);
  addKey("0", Zero_Key, 0x10, 8);
  addKey("1", One_Key, 0x11, 8);
  addKey("2", Two_Key, 0x12, 8);
  addKey("3", Three_Key, 0x13, 8);
  addKey("4", Four_Key, 0x14, 8);
  addKey("5", Five_Key, 0x15, 8);
  addKey("6", Six_Key, 0x16, 8);
  addKey("7", Seven_Key, 0x17, 8);
  addKey("8", Eight_Key, 0x18, 8);
  addKey("9", Nine_Key, 0x19, 8);
  addKey("goback", PrevChannel_Key, 0x1A, 8);
}


YamahaKaraoke1::YamahaKaraoke1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Karaoke Keyset 1",
      Yamaha_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index, Standard_NEC);

//  setPreData(0xDE21, 16);
  setPreData(0x7B, 8);

  addKey("POWER", Power_Key, 0x80, 8);
  addKey("VOL+", VolumeUp_Key, 0x82, 8);
  addKey("VOL-", VolumeDown_Key, 0x83, 8);
  addKey("LD", Unmapped_Key, 0x8C, 8);
  addKey("CD/CDG", Unmapped_Key, 0x8D, 8);
  addKey("VCR", Unmapped_Key, 0x8E, 8);
  addKey("TAPE", Unmapped_Key, 0x8F, 8);
  addKey("AUX2", Unmapped_Key, 0x90, 8);
  addKey("AUX1", Unmapped_Key, 0x91, 8);
  addKey("B_SYMBOL", Unmapped_Key, 0x96, 8);
  addKey("SQUARE_SYMBOL", Unmapped_Key, 0x97, 8);
  addKey("HASH", Unmapped_Key, 0x98, 8);
  addKey("BALLAD", One_Key, 0x99, 8);
  addKey("POPS", Two_Key, 0x9A, 8);
  addKey("JAZZ", Three_Key, 0x9B, 8);
  addKey("ROCK", Four_Key, 0x9C, 8);
  addKey("MPX/STEREO", Unmapped_Key, 0xD8, 8);
  addKey("VOCAL_AID", Unmapped_Key, 0xD9, 8);
  addKey("ONE_TOUCH_KAR.", Unmapped_Key, 0xDA, 8);
}
