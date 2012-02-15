#include "sony.h"
#include "protocols/sircprotocol.h"


SonyTV1::SonyTV1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Sony_Make,
      index)
{
  addControlledDevice(Sony_Make, "KV-M1420D", TV_Device);
  addControlledDevice(Sony_Make, "KV-20FV10", TV_Device);
  addControlledDevice(Sony_Make, "KV-2184MT", TV_Device);
  addControlledDevice(Sony_Make, "KV-27FX210", TV_Device);
  addControlledDevice(Sony_Make, "KV-32FS210", TV_Device);
  addControlledDevice(Sony_Make, "KV-36FS210", TV_Device);
  addControlledDevice(Sony_Make, "KV-36FS13", TV_Device);
  addControlledDevice(Sony_Make, "KDL-23B4030", TV_Device);
  addControlledDevice(Sony_Make, "KDL-52X2000", TV_Device);
  addControlledDevice(Sony_Make, "KDL-46X2000", TV_Device);
  addControlledDevice(Sony_Make, "KDL-40X2000", TV_Device);
  addControlledDevice(Sony_Make, "KP-46WT520", TV_Device);

  threadableProtocol = new SIRCProtocol(guiObject, index);

  addSIRC12Key("1", One_Key, 0x01, 0x0);
  addSIRC12Key("2", Two_Key, 0x01, 0x1);
  addSIRC12Key("3", Three_Key, 0x01, 0x2);
  addSIRC12Key("4", Four_Key, 0x01, 0x3);
  addSIRC12Key("5", Five_Key, 0x01, 0x4);
  addSIRC12Key("6", Six_Key, 0x01, 0x5);
  addSIRC12Key("7", Seven_Key, 0x01, 0x6);
  addSIRC12Key("8", Eight_Key, 0x01, 0x7);
  addSIRC12Key("9", Nine_Key, 0x01, 0x8);
  addSIRC12Key("0", Zero_Key, 0x01, 0x9);
  addSIRC12Key("enter", Enter_Key, 0x01, 0x0B);
  addSIRC12Key("1-", Unmapped_Key, 0x01, 0x0C);
  addSIRC12Key("2-", Unmapped_Key, 0x01, 0x0D);
  addSIRC12Key("C", Clear_Key, 0x01, 0x0E); // "C00"
  addSIRC12Key("CHANNEL/PAGE+", ChannelUp_Key, 0x01, 0x10);
  addSIRC12Key("CHANNEL/PAGE-", ChannelDown_Key, 0x01, 0x11);
  addSIRC12Key("VOLUME+", VolumeUp_Key, 0x01, 0x12);
  addSIRC12Key("VOLUME-", VolumeDown_Key, 0x01, 0x13);
  addSIRC12Key("MUTE", Mute_Key, 0x01, 0x14);
  addSIRC12Key("POWER", Power_Key, 0x01, 0x15);
  addSIRC12Key("normalise", Reset_Key, 0x01, 0x16); // "reset"
  addSIRC12Key("a/b", Audio_Key, 0x01, 0x17); // "mts", "sap", "language"
  addSIRC12Key("picture_up", ContrastUp_Key, 0x01, 0x18); // "Contrast Up"
  addSIRC12Key("picture_down", ContrastDown_Key, 0x1, 0x19); // "Contrast Down"
  addSIRC12Key("-/--", DoubleDigit_Key, 0x01, 0x1D);
  addSIRC12Key("tv/video", Input_Key, 0x01, 0x25);
  addSIRC12Key("bucket", Unmapped_Key, 0x01, 0x28);
  addSIRC12Key("stereo", Surround_Key, 0x01, 0x29);
  addSIRC12Key("ANT", AntennaInput_Key, 0x01, 0x2A);
  addSIRC12Key("time", Clock_Key, 0x01, 0x2B);
  addSIRC12Key("timer/block", Timer_Key, 0x01, 0x30);
  addSIRC12Key("right", Right_Key, 0x01, 0x33);
  addSIRC12Key("left", Left_Key, 0x01, 0x34);
  addSIRC12Key("sleep", Sleep_Key, 0x01, 0x36);
  addSIRC12Key("TV-RETURN", Unmapped_Key, 0x01, 0x38); // "analog"
  addSIRC12Key("?/INFO", Info_Key, 0x01, 0x3A); // Teletext Index
  addSIRC12Key("prev_ch", PrevChannel_Key, 0x01, 0x3B); // "jump"
  addSIRC12Key("off/repeat", Repeat_Key, 0x01, 0x3C);
  addSIRC12Key("TELETXT", Teletext_Key, 0x01, 0x3F);
  addSIRC12Key("favourite", Unmapped_Key, 0x01, 0x4A); // separate keyset?
  addSIRC12Key("cable", CableInput_Key, 0x01, 0x4E);
  addSIRC12Key("Sat", SatInput_Key, 0x01, 0x51);
  addSIRC12Key("pip_ch+", PIPChannelUp_Key, 0x01, 0x58);
  addSIRC12Key("pip_ch-", PIPChannelDown_Key, 0x01, 0x59);
  addSIRC12Key("piptv_video", PIPSource_Key, 0x01, 0x5A);
  addSIRC12Key("PIP", PIP_Key, 0x01, 0x5B);
  addSIRC12Key("pipfreeze", PIPPause_Key, 0x01, 0x5C);
  addSIRC12Key("PIP_POSITION", PIPMove_Key, 0x01, 0x5E);
  addSIRC12Key("PIP_SWAP", PIPSwap_Key, 0x01, 0x5F);
  addSIRC12Key("MENU", Menu_Key, 0x01, 0x60);
  addSIRC12Key("Settup_V", Unmapped_Key, 0x01, 0x61); // alternate pic mode
  addSIRC12Key("Settup_A", Unmapped_Key, 0x01, 0x62); // alternate sound mode
  addSIRC12Key("EXIT", Exit_Key, 0x01, 0x63);
  addSIRC12Key("picturemode", PictureMode_Key, 0x01, 0x64);
  addSIRC12Key("OK", Select_Key, 0x01, 0x65); // "return", "select", "enter"
  addSIRC12Key("output", Unmapped_Key, 0x01, 0x66);
  addSIRC12Key("PIP_SOURCE", Unmapped_Key, 0x01, 0x67); // separate keyset?
  addSIRC12Key("asterisk", Unmapped_Key, 0x01, 0x68); // "TV System"
  addSIRC12Key("auto_program", Unmapped_Key, 0x01, 0x6B);
  addSIRC12Key("setup", Program_Key, 0x01, 0x6C);
  addSIRC12Key("tune_down", Unmapped_Key, 0x01, 0x6F); // "search -"
  addSIRC12Key("tune_up", Unmapped_Key, 0x01, 0x6E); // "search +"
  addSIRC12Key("up", Up_Key, 0x01, 0x74);
  addSIRC12Key("down", Down_Key, 0x01, 0x75);
  addSIRC12Key("diamond", Unmapped_Key, 0x01, 0x78); // "add"
  addSIRC12Key("erase", Unmapped_Key, 0x01, 0x79);
  addSIRC12Key("select", Unmapped_Key, 0x01, 0x7C); // PictureMode_Key?

  addSIRC12Key("vt_inf", TeletextIndex_Key, 0x03, 0x48); // "Teletext Home"
  addSIRC12Key("expand", TeletextSize_Key, 0x03, 0x49);
  addSIRC12Key("Teletext Hold", TeletextHold_Key, 0x03, 0x4A); // "shrink"
  addSIRC12Key("subtitles", Unmapped_Key, 0x03, 0x4B); // Teletext subtitles
  addSIRC12Key("LEFT/-/RED", Red_Key, 0x03, 0x4C);
  addSIRC12Key("UP/GREEN", Green_Key, 0x03, 0x4D);
  addSIRC12Key("RIGHT/+/YELLOW", Yellow_Key, 0x03, 0x4E);
  addSIRC12Key("DOWN/BLUE", Blue_Key, 0x03, 0x4F);

  addSIRC15Key("SYNC_MENU", Unmapped_Key, 0x1A, 0x58);
  addSIRC15Key("SCENE", Unmapped_Key, 0x1A, 0x78);
  addSIRC15Key("INTERNET_VIDEO", Unmapped_Key, 0x1A, 0x79);
  addSIRC15Key("I-MANUAL", Unmapped_Key, 0x1A, 0x7B);

  addSIRC15Key("DIGITAL_ANALOG", Unmapped_Key, 0x77, 0x0D);
  addSIRC15Key("DIGITAL", Unmapped_Key, 0x77, 0x52);
  addSIRC15Key("theatre", Unmapped_Key, 0x77, 0x60); // "Home Theater"
  addSIRC15Key("FAVORITES", Favorites_Key, 0x77, 0x76);

  addSIRC15Key("STOP", Stop_Key, 0x97, 0x18);
  addSIRC15Key("PAUSE", Pause_Key, 0x97, 0x19);
  addSIRC15Key("PLAY", Play_Key, 0x97, 0x1A);
  addSIRC15Key("FBACKWARD", Rewind_Key, 0x97, 0x1B);
  addSIRC15Key("FFORWARD", FastForward_Key, 0x97, 0x1C);
  addSIRC15Key("DOT", Unmapped_Key, 0x97, 0x1D);
  addSIRC15Key("RETURN", Unmapped_Key, 0x97, 0x23); // exit?
  addSIRC15Key("TOOLS", Unmapped_Key, 0x97, 0x36); // "OPTIONS"
  addSIRC15Key("PREVIOUS", Previous_Key, 0x97, 0x3C);
  addSIRC15Key("NEXT", Next_Key, 0x97, 0x3D);
  addSIRC15Key("REPLAY", Replay_Key, 0x97, 0x79);
  addSIRC15Key("ADVANCE", Advance_Key, 0x97, 0x78);
  addSIRC15Key("SOUND", Unmapped_Key, 0x97, 0x7B);

  addSIRC15Key("Surround_Mode", Unmapped_Key, 0xA4, 0x1F); // "Music"
  addSIRC15Key("16:9", AspectRatio_Key, 0xA4, 0x3D); // "WIDE"
  addSIRC15Key("EPG", Guide_Key, 0xA4, 0x5B);
  addSIRC15Key("PIP_Audio", Unmapped_Key, 0xA4, 0x7C);
}


SonyTV1a::SonyTV1a(
  QObject *guiObject,
  unsigned int index)
  : SonyTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1a");

  addControlledDevice(Sony_Make, "KDW-25", TV_Device);

  addSIRC12Key("LEFT/-/RED", Left_Key, 0x03, 0x4C);
  addSIRC12Key("UP/GREEN", Up_Key, 0x03, 0x4D);
  addSIRC12Key("RIGHT/+/YELLOW", Right_Key, 0x03, 0x4E);
  addSIRC12Key("DOWN/BLUE", Down_Key, 0x03, 0x4F);
}


SonyTV1b::SonyTV1b(
  QObject *guiObject,
  unsigned int index)
  : SonyTV1a(guiObject, index)
{
  setKeysetName("TV Keyset 1b");

  addSIRC12Key("clear", Unmapped_Key, 0x01, 0x34); // "Clock Clear"
  addSIRC12Key("level_plus", Unmapped_Key, 0x01, 0x74);
  addSIRC12Key("level_minus", Unmapped_Key, 0x01, 0x75);
  addSIRC12Key("am/pm", Unmapped_Key, 0x01, 0x33);
}


// Not sure about these codes:
SonyTV1c::SonyTV1c(
  QObject *guiObject,
  unsigned int index)
  : SonyTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1c");

  addSIRC12Key(">>", FastForward_Key, 0x01, 0x58);
  addSIRC12Key("<<", Rewind_Key, 0x01, 0x59);
  addSIRC12Key("rec", Record_Key, 0x01, 0x5A);
  addSIRC12Key("pause", Pause_Key, 0x01, 0x5C);
  addSIRC12Key("stop", Stop_Key, 0x01, 0x5E);
  addSIRC12Key("play", Play_Key, 0x01, 0x5F);

  addSIRC15Key("BLUE", Blue_Key, 0x97, 0x24);
  addSIRC15Key("RED", Red_Key, 0x97, 0x25);
  addSIRC15Key("GREEN", Green_Key, 0x97, 0x26);
  addSIRC15Key("YELLOW", Yellow_Key, 0x97, 0x27);
  addSIRC15Key("SUBTITLES", Captions_Key, 0x97, 0x28);
}


// These controls don't quite match other SIRC data.  (some do, some don't)
// This all taken from LIRC "AMPIR" config file.
SonyAmp1::SonyAmp1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Amp Keyset 1",
      Sony_Make,
      index)
{
  threadableProtocol = new SIRCProtocol(guiObject, index);

  addSIRC12Key("1", One_Key, 0x0C, 0x00);
  addSIRC12Key("2", Two_Key, 0x0C, 0x01);
  addSIRC12Key("3", Three_Key, 0x0C, 0x02);
  addSIRC12Key("4", Four_Key, 0x0C, 0x03);
  addSIRC12Key("5", Five_Key, 0x0C, 0x04);
  addSIRC12Key("6", Six_Key, 0x0C, 0x05);
  addSIRC12Key("7", Seven_Key, 0x0C, 0x06);
  addSIRC12Key("8", Eight_Key, 0x0C, 0x07);
  addSIRC12Key("9", Nine_Key, 0x0C, 0x08);
  addSIRC12Key("0", Zero_Key, 0x0C, 0x09);
  addSIRC12Key("ENTER", Enter_Key, 0x0C, 0x0B);
  addSIRC12Key("DIGITAL", Unmapped_Key, 0x0C, 0x0C);
  addSIRC12Key("VIDEO3", Unmapped_Key, 0x0C, 0x0A);
  addSIRC12Key("VIDEO4", Unmapped_Key, 0x0C, 0x0B);
  addSIRC12Key("VOL+", VolumeUp_Key, 0x0C, 0x12);
  addSIRC12Key("VOL-", VolumeDown_Key, 0x0C, 0x13);
  addSIRC12Key("MUTE", Mute_Key, 0x0C, 0x14);
  addSIRC12Key("POWER", Power_Key, 0x0C, 0x15);
  addSIRC12Key("LD", LDInput_Key, 0x0C, 0x19);
  addSIRC12Key("TV", CableInput_Key, 0x0C, 0x18);
  addSIRC12Key("VIDEO2", Unmapped_Key, 0x0C, 0x1E);
  addSIRC12Key("PHONO", PhonoInput_Key, 0x0C, 0x20);
  addSIRC12Key("TUNER", TunerInput_Key, 0x0C, 0x21);
  addSIRC12Key("VIDEO1", Unmapped_Key, 0x0C, 0x22);
  addSIRC12Key("TAPE", TapeInput_Key, 0x0C, 0x23);
  addSIRC12Key("CD", CDInput_Key, 0x0C, 0x25);
  addSIRC12Key("DAT", Unmapped_Key, 0x0C, 0x46);
  addSIRC12Key("SLEEP", Sleep_Key, 0x0C, 0x60);
  addSIRC12Key("MD", MDInput_Key, 0x0C, 0x69);
  addSIRC12Key("TV2", Unmapped_Key, 0x0C, 0x6A);
  addSIRC12Key("5.1CH", Unmapped_Key, 0x0C, 0x72);
  addSIRC12Key("DVD", DVDInput_Key, 0x0C, 0x7D);
}


// These taken from LIRC config file "RM-AV2100T".
SonyAmp2::SonyAmp2(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Amp Keyset 2",
      Sony_Make,
      index)
{
  threadableProtocol = new SIRCProtocol(guiObject, index);

  addSIRC12Key("up", Up_Key, 0x0C, 0x78);
  addSIRC12Key("down", Down_Key, 0x0C, 0x79);
  addSIRC12Key("left", Left_Key, 0x0C, 0x7A);
  addSIRC12Key("right", Right_Key, 0x0C, 0x7B);

  addSIRC12Key("program_+", ChannelUp_Key, 0x0D, 0x10);
  addSIRC12Key("program_-", ChannelDown_Key, 0x0D, 0x11);
  addSIRC12Key("shift", Unmapped_Key, 0x0D, 0x55);

  addSIRC12Key("1", One_Key, 0x10, 0x00);
  addSIRC12Key("2", Two_Key, 0x10, 0x01);
  addSIRC12Key("3", Three_Key, 0x10, 0x02);
  addSIRC12Key("4", Four_Key, 0x10, 0x03);
  addSIRC12Key("5", Five_Key, 0x10, 0x04);
  addSIRC12Key("6", Six_Key, 0x10, 0x05);
  addSIRC12Key("7", Seven_Key, 0x10, 0x06);
  addSIRC12Key("8", Eight_Key, 0x10, 0x07);
  addSIRC12Key("9", Nine_Key, 0x10, 0x08);
  addSIRC12Key("0", Zero_Key, 0x10, 0x09);
  addSIRC12Key("enter", Enter_Key, 0x10, 0x0C);
  addSIRC12Key("vol_+", VolumeUp_Key, 0x10, 0x12);
  addSIRC12Key("vol_-", VolumeDown_Key, 0x10, 0x13);
  addSIRC12Key("mute", Mute_Key, 0x10, 0x14);
  addSIRC12Key("power", Power_Key, 0x10, 0x15);
  addSIRC12Key("aux/vdp", AuxInput_Key, 0x10, 0x1D);
  addSIRC12Key("video2", Unmapped_Key, 0x10, 0x1E);
  addSIRC12Key("phono", PhonoInput_Key, 0x10, 0x20);
  addSIRC12Key("tuner", TunerInput_Key, 0x10, 0x21);
  addSIRC12Key("video1", Unmapped_Key, 0x10, 0x22);
  addSIRC12Key("tape", TapeInput_Key, 0x10, 0x23);
  addSIRC12Key("cd", CDInput_Key, 0x10, 0x25);
  addSIRC12Key("power_on", PowerOn_Key, 0x10, 0x2E);
  addSIRC12Key("video3", Unmapped_Key, 0x10, 0x42);
  addSIRC12Key("tv", CableInput_Key, 0x10, 0x6A);
  addSIRC12Key("dvd", DVDInput_Key, 0x10, 0x7D);

  addSIRC15Key("md/dat", MDInput_Key, 0x10, 0x69);
}


SonyAudio1::SonyAudio1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 1",
      Sony_Make,
      index)
{
  threadableProtocol = new SIRCProtocol(guiObject, index);

  addSIRC12Key("tv_video", Input_Key, 0x01, 0x25);

  addSIRC12Key("DSG", Unmapped_Key, 0x0C, 0x31);

  addSIRC12Key("MEMORY", Program_Key, 0x0D, 0x0E);
  addSIRC12Key("TUNER-BAND", TunerBand_Key, 0x0D, 0x0F);
  addSIRC12Key("TUNING_MODE", Unmapped_Key, 0x0D, 0x17);
  addSIRC12Key("STEREO-MONO", FMMode_Key, 0x0D, 0x21);

  addSIRC12Key("DIR_MODE", Unmapped_Key, 0x0E, 0x14);
  addSIRC12Key("REC", Record_Key, 0x0E, 0x1E);
  addSIRC12Key("TAPE", TapeInput_Key, 0x0E, 0x34);

  addSIRC12Key("tuner", TunerInput_Key, 0x10, 0x0F); // "Tune Up"
  addSIRC12Key("VOL+", VolumeUp_Key, 0x10, 0x12);
  addSIRC12Key("VOL-", VolumeDown_Key, 0x10, 0x13);
  addSIRC12Key("ON-OFF", Power_Key, 0x10, 0x15);
  addSIRC12Key("effect_on_off", Unmapped_Key, 0x10, 0x1F);
  addSIRC12Key("cd", CDInput_Key, 0x10, 0x25);
  addSIRC12Key("DISPLAY", Info_Key, 0x10, 0x4B);
  addSIRC12Key("dimmer", Unmapped_Key, 0x10, 0x4D);
  addSIRC12Key("karaoke_mpx", Unmapped_Key, 0x10, 0x5F);
  addSIRC12Key("SLEEP", Sleep_Key, 0x10, 0x60);
  addSIRC12Key("TIMER_SELECT", Unmapped_Key, 0x10, 0x62); // "clock_select"
  addSIRC12Key("TIMER_SET", Timer_Key, 0x10, 0x65);
  addSIRC12Key("md", Unmapped_Key, 0x10, 0x69);
  addSIRC12Key("game", Unmapped_Key, 0x10, 0x7C);

  addSIRC12Key("CD_REPEAT", Repeat_Key, 0x11, 0x2C);
  addSIRC12Key("CD", Unmapped_Key, 0x11, 0x32);
  addSIRC12Key("PLAY_MODE", Unmapped_Key, 0x11, 0x6C);

  addSIRC15Key("cinema_effect", Unmapped_Key, 0x90, 0x08);
  addSIRC15Key("game_mixing", Unmapped_Key, 0x90, 0x33);
  addSIRC15Key("spectrum", Unmapped_Key, 0x90, 0x34);
  addSIRC15Key("p_file", Unmapped_Key, 0x90, 0x39);
  addSIRC15Key("surround_speaker_mode", Surround_Key, 0x90, 0x5F);
  addSIRC15Key("music_eq", Unmapped_Key, 0x90, 0x60);
  addSIRC15Key("movie_eq", Unmapped_Key, 0x90, 0x61);
  addSIRC15Key("game_eq", Unmapped_Key, 0x90, 0x62);

  addSIRC20Key("return", Exit_Key, 0x31, 0x1A, 0x0E);
  addSIRC20Key("prev_r", Unmapped_Key, 0x31, 0x1A, 0x36);
  addSIRC20Key("next_r", Unmapped_Key, 0x31, 0x1A, 0x37);
  addSIRC20Key("special_menu", Menu_Key, 0x31, 0x1A, 0x53);
  addSIRC20Key("on_screen", Unmapped_Key, 0x31, 0x1A, 0x55);
  addSIRC20Key("sharp", Unmapped_Key, 0x31, 0x1A, 0x6B);
  addSIRC20Key("flat", Unmapped_Key, 0x31, 0x1A, 0x6C);
  addSIRC20Key("album-", Unmapped_Key, 0x31, 0x1A, 0x6E);
  addSIRC20Key("album+", Unmapped_Key, 0x31, 0x1A, 0x6F);

  addSIRC20Key("1", One_Key, 0x39, 0x1A, 0x00);
  addSIRC20Key("2", Two_Key, 0x39, 0x1A, 0x01);
  addSIRC20Key("3", Three_Key, 0x39, 0x1A, 0x02);
  addSIRC20Key("4", Four_Key, 0x39, 0x1A, 0x03);
  addSIRC20Key("5", Five_Key, 0x39, 0x1A, 0x04);
  addSIRC20Key("6", Six_Key, 0x39, 0x1A, 0x05);
  addSIRC20Key("7", Seven_Key, 0x39, 0x1A, 0x06);
  addSIRC20Key("8", Eight_Key, 0x39, 0x1A, 0x07);
  addSIRC20Key("9", Nine_Key, 0x39, 0x1A, 0x08);
  addSIRC20Key("0", Zero_Key, 0x39, 0x1A, 0x09);
  addSIRC20Key("KEY_ENTER", Enter_Key, 0x39, 0x1A, 0x0C);
  addSIRC20Key("gt_10", DoubleDigit_Key, 0x39, 0x1A, 0x0D);
  addSIRC20Key("clear", Clear_Key, 0x39, 0x1A, 0x0F);
  addSIRC20Key("repeat", Repeat_Key, 0x39, 0x1A, 0x2C);
  addSIRC20Key("KEY_PREV_SONG", Previous_Key, 0x39, 0x1A, 0x30);
  addSIRC20Key("KEY_NEXT_SONG", Next_Key, 0x39, 0x1A, 0x31);
  addSIRC20Key("KEY_PREV", Rewind_Key, 0x39, 0x1A, 0x33); // "Rewind"
  addSIRC20Key("KEY_NEXT", FastForward_Key, 0x39, 0x1A, 0x34); // "Fast Forward"
  addSIRC20Key("KEY_STOP", Stop_Key, 0x39, 0x1A, 0x38);
  addSIRC20Key("KEY_PAUSE", Pause_Key, 0x39, 0x1A, 0x39);
  addSIRC20Key("d_skip", NextDisc_Key, 0x39, 0x1A, 0x3E);
  addSIRC20Key("up", Up_Key, 0x39, 0x1A, 0x78);
  addSIRC20Key("down", Down_Key, 0x39, 0x1A, 0x79);
  addSIRC20Key("left", Left_Key, 0x39, 0x1A, 0x7A);
  addSIRC20Key("right", Right_Key, 0x39, 0x1A, 0x7B);
  addSIRC20Key("Select", Select_Key, 0x39, 0x1A, 0x7C);
}


SonyAudio1a::SonyAudio1a(
  QObject *guiObject,
  unsigned int index)
  : SonyAudio1(guiObject, index)
{
  setKeysetName("Audio Keyset 1a");

  addSIRC12Key("tape", TapeInput_Key, 0x10, 0x23);

//  addSIRC20Key("select", Select_Key, 0x39, 0x1A, 0x32); // Doesn't make sense
  addSIRC20Key("play", Play_Key, 0x39, 0x1A, 0x32);
  addSIRC20Key("play_mode", Unmapped_Key, 0x39, 0x1A, 0x26);
  addSIRC20Key("enter", Select_Key, 0x39, 0x1A, 0x7C);
}


SonyDAT1::SonyDAT1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "DAT Keyset 1",
      Sony_Make,
      index)
{
  threadableProtocol = new SIRCProtocol(guiObject, index);

  setPostData(0x07, 5);

  addSIRC12Key("1", One_Key, 0x1C, 0x00);
  addSIRC12Key("2", Two_Key, 0x1C, 0x01);
  addSIRC12Key("3", Three_Key, 0x1C, 0x02);
  addSIRC12Key("4", Four_Key, 0x1C, 0x03); 
  addSIRC12Key("5", Five_Key, 0x1C, 0x04);
  addSIRC12Key("6", Six_Key, 0x1C, 0x05);
  addSIRC12Key("7", Seven_Key, 0x1C, 0x06);
  addSIRC12Key("8", Eight_Key, 0x1C, 0x07);
  addSIRC12Key("9", Nine_Key, 0x1C, 0x08);
  addSIRC12Key("0", Zero_Key, 0x1C, 0x14);
  addSIRC12Key("PLAY", Play_Key, 0x1C, 0x3A);
  addSIRC12Key("PAUSE", Pause_Key, 0x1C, 0x39);
  addSIRC12Key("STOP", Stop_Key, 0x1C, 0x38);
  addSIRC12Key("<<", Rewind_Key, 0x1C, 0x3B);
  addSIRC12Key(">>", FastForward_Key, 0x1C, 0x3C);
  addSIRC12Key("|<<", Previous_Key, 0x1C, 0x68);
  addSIRC12Key(">>|", Next_Key, 0x1C, 0x69);
  addSIRC12Key("RECORD", Record_Key, 0x1C, 0x3E);
  addSIRC12Key("Open/Close", Eject_Key, 0x1C, 0x20);

  // The following commands are dubious:
  addSIRC12Key("VOL+", VolumeUp_Key, 0x1C, 0x12);
  addSIRC12Key("VOL-", VolumeDown_Key, 0x1C, 0x13);
  addSIRC12Key("POWER_ON", PowerOn_Key, 0x1C, 0x2E);
  addSIRC12Key("POWER_OFF", PowerOff_Key, 0x1C, 0x2F);
  addSIRC12Key("MUTE", Mute_Key, 0x1C, 0x14); // Makes no sense...
  addSIRC12Key("POWER", Power_Key, 0x1C, 0x15);
  addSIRC12Key("ENTER", Enter_Key, 0x1C, 0x0B);
}


SonyDVD1::SonyDVD1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Sony_Make,
      index)
{
  threadableProtocol = new SIRCProtocol(guiObject, index);

  addSIRC20Key("1", One_Key, 0x49, 0x1A, 0x00);
  addSIRC20Key("2", Two_Key, 0x49, 0x1A, 0x01);
  addSIRC20Key("3", Three_Key, 0x49, 0x1A, 0x02);
  addSIRC20Key("4", Four_Key, 0x49, 0x1A, 0x03);
  addSIRC20Key("5", Five_Key, 0x49, 0x1A, 0x04);
  addSIRC20Key("6", Six_Key, 0x49, 0x1A, 0x05);
  addSIRC20Key("7", Seven_Key, 0x49, 0x1A, 0x06);
  addSIRC20Key("8", Eight_Key, 0x49, 0x1A, 0x07);
  addSIRC20Key("9", Nine_Key, 0x49, 0x1A, 0x08);
  addSIRC20Key("0", Zero_Key, 0x49, 0x1A, 0x09);
  addSIRC20Key("select", Select_Key, 0x49, 0x1A, 0x0B); //"Enter"
  addSIRC20Key("Disc Explorer", Unmapped_Key, 0x49, 0x1A, 0x0C);
  addSIRC20Key("Ent", Enter_Key, 0x49, 0x1A, 0x0D); // "Set"
  addSIRC20Key("return", Exit_Key, 0x49, 0x1A, 0x0E);
  addSIRC20Key("CLEAR", Clear_Key, 0x49, 0x1A, 0x0F);
  addSIRC20Key("-/--", DoubleDigit_Key, 0x49, 0x1A, 0x0F);

  addSIRC20Key("Input", Input_Key, 0x49, 0x1A, 0x12);
  addSIRC20Key("prog+", ChannelUp_Key, 0x49, 0x1A, 0x13);
  addSIRC20Key("prog-", ChannelDown_Key, 0x49, 0x1A, 0x14);
  addSIRC20Key("power", Power_Key, 0x49, 0x1A, 0x15);
  addSIRC20Key("open/close", Eject_Key, 0x49, 0x1A, 0x16);
  addSIRC20Key("rec", Record_Key, 0x49, 0x1A, 0x19);
  addSIRC20Key("top_menu", DiscTitle_Key, 0x49, 0x1A, 0x1A); // "Title"
  addSIRC20Key("dvd_menu", DiscMenu_Key, 0x49, 0x1A, 0x1B);
  addSIRC20Key("program", Program_Key, 0x49, 0x1A, 0x1F);
  addSIRC20Key("step/search -", StepBack_Key, 0x49, 0x1A, 0x20);
  addSIRC20Key("step/search +", StepForward_Key, 0x49, 0x1A, 0x21);
  addSIRC20Key("scan/slow -", SlowMinus_Key, 0x49, 0x1A, 0x22);
  addSIRC20Key("scan/slow +", SlowPlus_Key, 0x49, 0x1A, 0x23);
  addSIRC20Key("INDEX-", Unmapped_Key, 0x49, 0x1A, 0x26);
  addSIRC20Key("INDEX+", Unmapped_Key, 0x49, 0x1A, 0x27);
  addSIRC20Key("TIME", Unmapped_Key, 0x49, 0x1A, 0x28);
  addSIRC20Key("JOG_STOP", Unmapped_Key, 0x49, 0x1A, 0x29); // "Pause"
  addSIRC20Key("a-b", RepeatAB_Key, 0x49, 0x1A, 0x2A);
  addSIRC20Key("repeat", Repeat_Key, 0x49, 0x1A, 0x2C);
  addSIRC20Key("POWER_ON", PowerOn_Key, 0x49, 0x1A, 0x2E);
  addSIRC20Key("POWER_OFF", PowerOff_Key, 0x49, 0x1A, 0x2F);

  addSIRC20Key("prev", Previous_Key, 0x49, 0x1A, 0x30);
  addSIRC20Key("next", Next_Key, 0x49, 0x1A, 0x31);
  addSIRC20Key("play", Play_Key, 0x49, 0x1A, 0x32);
  addSIRC20Key("rew", Rewind_Key, 0x49, 0x1A, 0x33);
  addSIRC20Key("ffwd", FastForward_Key, 0x49, 0x1A, 0x34);
  addSIRC20Key("shuffle", Random_Key, 0x49, 0x1A, 0x35);
  addSIRC20Key("X2_BACK", Unmapped_Key, 0x49, 0x1A, 0x36);
  addSIRC20Key("X2_FORWARD", Unmapped_Key, 0x49, 0x1A, 0x37);
  addSIRC20Key("stop", Stop_Key, 0x49, 0x1A, 0x38);
  addSIRC20Key("pause", Pause_Key, 0x49, 0x1A, 0x39);
  addSIRC20Key("STEP_BACK", Unmapped_Key, 0x49, 0x1A, 0x3A); // "Jog Rev"
  addSIRC20Key("STEP_FORWARD", Unmapped_Key, 0x49, 0x1A, 0x3B); // "Jog Fwd"
  addSIRC20Key("RecStop", RecordStop_Key, 0x49, 0x1A, 0x3D);
  addSIRC20Key("RecPause", RecordPause_Key, 0x49, 0x1A, 0x3E);

  addSIRC20Key("DNR", NoiseReduction_Key, 0x49, 0x1A, 0x48);
  addSIRC20Key("SEARCH_MODE", Unmapped_Key, 0x49, 0x1A, 0x4B);
  addSIRC20Key("Picture_Navi", Unmapped_Key, 0x49, 0x1A, 0x50);
  addSIRC20Key("TV_DVD", Unmapped_Key, 0x49, 0x1A, 0x51);
  addSIRC20Key("menu", Menu_Key, 0x49, 0x1A, 0x53); // "setup"
  addSIRC20Key("Display", Info_Key, 0x49, 0x1A, 0x54);
  addSIRC20Key("surround", Surround_Key, 0x49, 0x1A, 0x5A);
  addSIRC20Key("PICTUREMODE", PictureMode_Key, 0x49, 0x1A, 0x5B);
  addSIRC20Key("Replay", Replay_Key, 0x49, 0x1A, 0x5C);
  addSIRC20Key("SA-CD_MULTI/2CH", Unmapped_Key, 0x49, 0x1A, 0x5E);
  addSIRC20Key("SA-CD/CD", Unmapped_Key, 0x49, 0x1A, 0x5F);

  addSIRC20Key("SLOW_BACK", SlowMinus_Key, 0x49, 0x1A, 0x60);
  addSIRC20Key("SLOW_FORWARD", SlowPlus_Key, 0x49, 0x1A, 0x61);
  addSIRC20Key("SUBTITLE_ON_OFF", Captions_Key, 0x49, 0x1A, 0x62);
  addSIRC20Key("Subtitle Change", Unmapped_Key, 0x49, 0x1A, 0x63);
  addSIRC20Key("Language", Audio_Key, 0x49, 0x1A, 0x64); // "Audio"
  addSIRC20Key("ANGLE_CHANGE", Angle_Key, 0x49, 0x1A, 0x65); // "Angle"
  addSIRC20Key("up", Up_Key, 0x49, 0x1A, 0x79);
  addSIRC20Key("down", Down_Key, 0x49, 0x1A, 0x7A);
  addSIRC20Key("left", Left_Key, 0x49, 0x1A, 0x7B);
  addSIRC20Key("right", Right_Key, 0x49, 0x1A, 0x7C);

  addSIRC20Key("Advance", Advance_Key, 0x62, 0x1A, 0x14);
  addSIRC20Key("Guide", Guide_Key, 0x62, 0x1A, 0x16);
  addSIRC20Key("Options", Unmapped_Key, 0x62, 0x1A, 0x17); // "Tools"
  addSIRC20Key("Dot", Unmapped_Key, 0x62, 0x1A, 0x1D);
  addSIRC20Key("file", Unmapped_Key, 0x62, 0x1A, 0x20);
  addSIRC20Key("sort", Unmapped_Key, 0x62, 0x1A, 0x21);
  addSIRC20Key("edit", Unmapped_Key, 0x62, 0x1A, 0x22);
  addSIRC20Key("ALBUM-MINUS", Unmapped_Key, 0x62, 0x1A, 0x29);
  addSIRC20Key("ALBUM-PLUS", Unmapped_Key, 0x62, 0x1A, 0x2A);
  addSIRC20Key("F1", Unmapped_Key, 0x62, 0x1A, 0x2E); // "HDD"
  addSIRC20Key("F2", Unmapped_Key, 0x62, 0x1A, 0x2F); // "DVD"
  addSIRC20Key("picture memory", Unmapped_Key, 0x62, 0x1A, 0x3C);
  addSIRC20Key("disc skip -", PrevDisc_Key, 0x62, 0x1A, 0x3D);
  addSIRC20Key("DiscSkip", NextDisc_Key, 0x62, 0x1A, 0x3E); // "disc skip +"
  addSIRC20Key("folder", Unmapped_Key, 0x62, 0x1A, 0x40);
  addSIRC20Key("Favorites", Favorites_Key, 0x62, 0x1A, 0x5E);
  addSIRC20Key("Purple", Blue_Key, 0x62, 0x1A, 0x66);
  addSIRC20Key("Red", Red_Key, 0x62, 0x1A, 0x67);
  addSIRC20Key("Green", Green_Key, 0x62, 0x1A, 0x68);
  addSIRC20Key("Yellow", Yellow_Key, 0x62, 0x1A, 0x69);
  addSIRC20Key("ZOOM", Zoom_Key, 0x62, 0x1A, 0x79);
}


SonyDVD1a::SonyDVD1a(
  QObject *guiObject,
  unsigned int index)
  : SonyDVD1(guiObject, index)
{
  setKeysetName("DVD Keyset 1a");

  addSIRC20Key("STEP_BACK", StepBack_Key, 0x49, 0x1A, 0x20);
  addSIRC20Key("STEP_FORWARD", StepForward_Key, 0x49, 0x1A, 0x21);
  addSIRC20Key("SLOW_BACK", SlowMinus_Key, 0x49, 0x1A, 0x22);
  addSIRC20Key("SLOW_FORWARD", SlowPlus_Key, 0x49, 0x1A, 0x23);
}


SonyDVD1b::SonyDVD1b(
  QObject *guiObject,
  unsigned int index)
  : SonyDVD1(guiObject, index)
{
  setKeysetName("DVD Keyset 1b");

  addSIRC20Key("SLOW-", SlowMinus_Key, 0x49, 0x1A, 0x72);
  addSIRC20Key("SLOW+", SlowPlus_Key, 0x49, 0x1A, 0x73);
}


SonyDVD1c::SonyDVD1c(
  QObject *guiObject,
  unsigned int index)
  : SonyDVD1(guiObject, index)
{
  setKeysetName("DVD Keyset 1c");

  addSIRC20Key("up", Up_Key, 0x49, 0x1A, 0x39);
  addSIRC20Key("down", Down_Key, 0x49, 0x1A, 0x38);
  addSIRC20Key("left", Left_Key, 0x49, 0x1A, 0x33);
  addSIRC20Key("right", Right_Key, 0x49, 0x1A, 0x34);
  addSIRC20Key("ok", Select_Key, 0x49, 0x1A, 0x32);
  addSIRC20Key("enter", Enter_Key, 0x49, 0x1A, 0x0B);
}


SonyVCR1::SonyVCR1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      Sony_Make,
      index)
{
  threadableProtocol = new SIRCProtocol(guiObject, index);

  addSIRC12Key("VOL_UP", VolumeUp_Key, 0x01, 0x12);
  addSIRC12Key("VOL_DOWN", VolumeDown_Key, 0x01, 0x13);

  addSIRC12Key("red", Red_Key, 0x03, 0x4C);
  addSIRC12Key("green", Green_Key, 0x03, 0x4D);
  addSIRC12Key("Yellow", Yellow_Key, 0x03, 0x4E);
  addSIRC12Key("blue", Blue_Key, 0x03, 0x4F);

  addSIRC12Key("1", One_Key, 0x0B, 0x00);
  addSIRC12Key("2", Two_Key, 0x0B, 0x01);
  addSIRC12Key("3", Three_Key, 0x0B, 0x02);
  addSIRC12Key("4", Four_Key, 0x0B, 0x03);
  addSIRC12Key("5", Five_Key, 0x0B, 0x04);
  addSIRC12Key("6", Six_Key, 0x0B, 0x05);
  addSIRC12Key("7", Seven_Key, 0x0B, 0x06);
  addSIRC12Key("8", Eight_Key, 0x0B, 0x07);
  addSIRC12Key("9", Nine_Key, 0x0B, 0x08);
  addSIRC12Key("0", Zero_Key, 0x0B, 0x09);
//  addSIRC12Key("jump", PrevChannel_Key, 0x0B, 0x0A); // might be wrong
  addSIRC12Key("-/--", DoubleDigit_Key, 0x0B, 0x0A);
  addSIRC12Key("ENT", Enter_Key, 0x0B, 0x0B); // "Enter"

  addSIRC12Key("prog-next", ChannelUp_Key, 0x0B, 0x10);
  addSIRC12Key("prog-prev", ChannelDown_Key, 0x0B, 0x11);
  addSIRC12Key("pwon", Power_Key, 0x0B, 0x15);
  addSIRC12Key("stop", Stop_Key, 0x0B, 0x18);
  addSIRC12Key("pause", Pause_Key, 0x0B, 0x19);
  addSIRC12Key("play", Play_Key, 0x0B, 0x1A);
  addSIRC12Key("<<", Rewind_Key, 0x0B, 0x1B);
  addSIRC12Key(">>", FastForward_Key, 0x0B, 0x1C);
  addSIRC12Key("rec", Record_Key, 0x0B, 0x1D);
  addSIRC12Key("ant/sw", AntennaInput_Key, 0x0B, 0x2A);  // "tv/vcr"
  addSIRC12Key("power_on", PowerOn_Key, 0x0B, 0x2E);
  addSIRC12Key("Power Off", PowerOff_Key, 0x0B, 0x2F);
  addSIRC12Key("menu", Menu_Key, 0x0B, 0x4D);
  addSIRC12Key("input", Input_Key, 0x0B, 0x4F);
  addSIRC12Key("display", Info_Key, 0x0B, 0x5A);

  // Odd cursor keys, overlap with media controls:
  addSIRC12Key("down", Down_Key, 0x0B, 0x18);
  addSIRC12Key("up", Up_Key, 0x0B, 0x19);
  addSIRC12Key("ok", Select_Key, 0x0B, 0x1A);
  addSIRC12Key("left", Left_Key, 0x0B, 0x1B);
  addSIRC12Key("right", Right_Key, 0x0B, 0x1C);
}


SonyVCR1a::SonyVCR1a(
  QObject *guiObject,
  unsigned int index)
  : SonyVCR1(guiObject, index)
{
  setKeysetName("VCR Keyset 1a");

  // These are the expected cursor keys:
  addSIRC12Key("up", Up_Key, 0x0B, 0x42);
  addSIRC12Key("down", Down_Key, 0x0B, 0x43);
  addSIRC12Key("left", Left_Key, 0x0B, 0x62);
  addSIRC12Key("right", Right_Key, 0x0B, 0x61);
  addSIRC12Key("execute", Select_Key, 0x0B, 0x51); //"OK"

//  addKey("SLEEP", Sleep_Key, 0x0B, 0x4F); // odd
}


// Extra codes off of hifi-remote website:
SonyVCR1b::SonyVCR1b(
  QObject *guiObject,
  unsigned int index)
  : SonyVCR1a(guiObject, index)
{
  setKeysetName("VCR Keyset 1b");

  addSIRC12Key("Volume Up", VolumeUp_Key, 0x0B, 0x12);
  addSIRC12Key("Volume Down", VolumeDown_Key, 0x0B, 0x13);
  addSIRC12Key("Eject", Eject_Key, 0x0B, 0x16);
  addSIRC12Key("Record Pause", RecordPause_Key, 0x0B, 0x1E);
  addSIRC12Key("Record Mute", RecordMute_Key, 0x0B, 0x1F);
  addSIRC12Key("Auto Tracking", AutoTracking_Key, 0x0B, 0x27);
  addSIRC12Key("Frame Reverse", StepBack_Key, 0x0B, 0x30);
  addSIRC12Key("Frame Advance", StepForward_Key, 0x0B, 0x31);
  addSIRC12Key("Mute", Mute_Key, 0x0B, 0x35);
  addSIRC12Key("Sleep", Sleep_Key, 0x0B, 0x36);
  addSIRC12Key("Slow +", SlowPlus_Key, 0x0B, 0x3D);
  addSIRC12Key("Slow -", SlowMinus_Key, 0x0B, 0x3E);
  addSIRC12Key("Tracking Up", TrackingPlus_Key, 0x0B, 0x44);
  addSIRC12Key("Tracking Down", TrackingMinus_Key, 0x0B, 0x45);
  addSIRC12Key("SP/EP", VHSSpeed_Key, 0x0B, 0x58);
}


SonyReceiver1::SonyReceiver1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Receiver Keyset 1",
      Sony_Make,
      index)
{
  threadableProtocol = new SIRCProtocol(guiObject, index);

  addSIRC15Key("1", One_Key, 0x30, 0x00);
  addSIRC15Key("2", Two_Key, 0x30, 0x01);
  addSIRC15Key("3", Three_Key, 0x30, 0x02);
  addSIRC15Key("4", Four_Key, 0x30, 0x03);
  addSIRC15Key("5", Five_Key, 0x30, 0x04);
  addSIRC15Key("6", Six_Key, 0x30, 0x05);
  addSIRC15Key("7", Seven_Key, 0x30, 0x06);
  addSIRC15Key("8", Eight_Key, 0x30, 0x07);
  addSIRC15Key("9", Nine_Key, 0x30, 0x08);
  addSIRC15Key("0", Zero_Key, 0x30, 0x09);
  addSIRC15Key("SELECT", Select_Key, 0x30, 0x0C);
  addSIRC15Key("VOLUME_UP", VolumeUp_Key, 0x30, 0x12);
  addSIRC15Key("VOLUME_DOWN", VolumeDown_Key, 0x30, 0x13);
  addSIRC15Key("MUTING", Mute_Key, 0x30, 0x14);
  addSIRC15Key("POWER", Power_Key, 0x30, 0x15);
  addSIRC15Key("VIDEO2", Unmapped_Key, 0x30, 0x1E);
  addSIRC15Key("TUNER", TunerInput_Key, 0x30, 0x21);
  addSIRC15Key("VIDEO1", Unmapped_Key, 0x30, 0x22);
  addSIRC15Key("SA_CD", Unmapped_Key, 0x30, 0x25);
  addSIRC15Key("VIDEO3", Unmapped_Key, 0x30, 0x42);
  addSIRC15Key("DISPLAY", Info_Key, 0x30, 0x4B);
  addSIRC15Key("SLEEP", Sleep_Key, 0x30, 0x60);
  addSIRC15Key("TV", Unmapped_Key, 0x30, 0x6A);
  addSIRC15Key("DVD", DVDInput_Key, 0x30, 0x7D);

  addSIRC15Key("SAT", SatInput_Key, 0xB0, 0x03);
  addSIRC15Key("2CH", Unmapped_Key, 0xB0, 0x09);
  addSIRC15Key("AFD", Unmapped_Key, 0xB0, 0x0A);
  addSIRC15Key("MOVIE", Unmapped_Key, 0xB0, 0x0B);
  addSIRC15Key("DVD_MENU", DiscMenu_Key, 0xB0, 0x2D); // Not sure about this
  addSIRC15Key("MUSIC", Unmapped_Key, 0xB0, 0x49);
  addSIRC15Key("AMP_MENU", Menu_Key, 0xB0, 0x77);
  addSIRC15Key("UP", Up_Key, 0xB0, 0x78);
  addSIRC15Key("DOWN", Down_Key, 0xB0, 0x79);
  addSIRC15Key("LEFT", Left_Key, 0xB0, 0x7A);
  addSIRC15Key("RIGHT", Right_Key, 0xB0, 0x7B);
}
