#include "hitachi.h"
#include "necprotocol.h"

HitachiTV1::HitachiTV1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Hitachi_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index);

  setPreData(0x0AF5, 16);

  addKey("1", One_Key, 0xB04F, 16);
  addKey("2", Two_Key, 0x708F, 16);
  addKey("3", Three_Key, 0xF00F, 16);
  addKey("4", Four_Key, 0x38C7, 16);
  addKey("5", Five_Key, 0xB847, 16);
  addKey("6", Six_Key, 0x7887, 16);
  addKey("7", Seven_Key, 0xF807, 16);
  addKey("8", Eight_Key, 0x20DF, 16);
  addKey("9", Nine_Key, 0xA05F, 16);
  addKey("0", Zero_Key, 0x30CF, 16);
  addKey("ch_down", ChannelDown_Key, 0x18E7, 16);
  addKey("ch_up", ChannelUp_Key, 0x9867, 16);
  addKey("recall", PrevChannel_Key, 0x08F7, 16);
  addKey("tv/video", Input_Key, 0x906F, 16); // "AV"
  addKey("power", Power_Key, 0xE817, 16);
  addKey("vol_up", VolumeUp_Key, 0x48B7, 16);
  addKey("vol_down", VolumeDown_Key, 0xA857, 16);
  addKey("timer", Sleep_Key, 0x8877, 16);
  addKey("return", Exit_Key, 0x22DD, 16);
  addKey("mute", Mute_Key, 0xD02F, 16);
  addKey("krasn", Unmapped_Key, 0xDA25, 16);
  addKey("zelen", Unmapped_Key, 0x7A85, 16);
  addKey("Reveal", Unmapped_Key, 0xBA45, 16); // "jolt"
  addKey("zelen", Unmapped_Key, 0x3AC5, 16);
  addKey("OK", Select_Key, 0xC23D, 16);
  addKey("FWD", FastForward_Key, 0xF609, 16);
  addKey("REV", Rewind_Key, 0xB649, 16);
  addKey("PLAY", Play_Key, 0xD629, 16);
  addKey("STOP", Stop_Key, 0x36C9, 16);
  addKey("HELP", Info_Key, 0x58A7, 16);
  addKey("CH", Unmapped_Key, 0xC837, 16);
  addKey("MENU", Menu_Key, 0x02FD, 16);
  addKey("PSCAN100HZ", Unmapped_Key, 0xB24D, 16);
  addKey("X", Unmapped_Key, 0x2AD5, 16);
  addKey("3D-SOUND", Surround_Key, 0xD827, 16);
  addKey("UP", Up_Key, 0x0EF1, 16);
  addKey("DOWN", Down_Key, 0x8E71, 16);
  addKey("CH_I/II", Unmapped_Key, 0x10EF, 16);
  addKey("TV/TEXT", Unmapped_Key, 0x6699, 16);
  addKey("SOUND", SoundMode_Key, 0xF20D, 16);
  addKey("Picture", PictureMode_Key, 0xE619, 16);
  addKey("Red", Red_Key, 0x32CD, 16);
  addKey("SUB", Unmapped_Key, 0xA25D, 16);
  addKey("U.N.L", Unmapped_Key, 0x629D, 16);
  addKey("HOLD", Unmapped_Key, 0xE21D, 16);
  addKey("Cancel", Clear_Key, 0x16E9, 16);
  addKey("Store", Unmapped_Key, 0x28D7, 16);
  addKey("Language", Language_Key, 0x609F, 16);
}


HitachiTV1a::HitachiTV1a(
  QObject *guiObject,
  unsigned int index)
  : HitachiTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1a");

  addKey("menu", Menu_Key, 0xCA35, 16);
}

HitachiTV1b::HitachiTV1b(
  QObject *guiObject,
  unsigned int index)
  : HitachiTV1a(guiObject, index)
{
  setKeysetName("TV Keyset 1b");

  addKey("Sound+", VolumeUp_Key, 0x4EB1, 16);
  addKey("Sound-", VolumeDown_Key, 0xCE31, 16);
  addKey("Timer", Sleep_Key, 0xD629, 16);
}


HitachiTV1c::HitachiTV1c(
  QObject *guiObject,
  unsigned int index)
  : HitachiTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1c");

  addControlledDevice(Hitachi_Make, "57F510", TV_Device);

  addKey("LastChannel", PrevChannel_Key, 0x50AF, 16);
  addKey("Info", Info_Key, 0x08F7, 16);
  addKey("Input1", Unmapped_Key, 0x847B, 16);
  addKey("Input2", Unmapped_Key, 0x44BB, 16);
  addKey("Input3", Unmapped_Key, 0xC43B, 16);
  addKey("Input4", Unmapped_Key, 0x24DB, 16);
  addKey("ChannelUp", Unmapped_Key, 0x14EB, 16); // these four are odd
  addKey("ChannelDown", Unmapped_Key, 0x946B, 16); // duplicate?
  addKey("VolumeDown", Unmapped_Key, 0x54AB, 16); // maybe pip?
  addKey("VolumeUp", Unmapped_Key, 0xD42B, 16); // doesn't make sense
  addKey("SELECT", Select_Key, 0x748B, 16);
  addKey("CC", Captions_Key, 0xEC13, 16);
  addKey("FavouriteChannel", Favorites_Key, 0x1CE3, 16);
  addKey("1080i/540p", Unmapped_Key, 0x3CC3, 16);
  addKey("Input5", Unmapped_Key, 0xBC43, 16);
  addKey("PowerON", Unmapped_Key, 0x7C83, 16);
  addKey("PowerOFF", Unmapped_Key, 0xFC03, 16);
  addKey("Menu", Menu_Key, 0xCA35, 16);
  addKey("PIP", PIP_Key, 0x1AE5, 16);
  addKey("Day/Night", Unmapped_Key, 0x7A85, 16);
  addKey("Freeze/Pause", Unmapped_Key, 0x8679, 16);
  addKey("EXIT", Exit_Key, 0x26D9, 16);
  addKey("16:9", Unmapped_Key, 0xA659, 16);
  addKey("16:9Zoom", Unmapped_Key, 0x6699, 16);
  addKey("4:3Standard", Unmapped_Key, 0xE619, 16);
  addKey("4:3Expanded", Unmapped_Key, 0x16E9, 16);
  addKey("4:3Zoom1", Unmapped_Key, 0x9669, 16);
  addKey("4:3Zoom2", Unmapped_Key, 0x56A9, 16);
  addKey("540p", Unmapped_Key, 0xD629, 16);
  addKey("1080i", Unmapped_Key, 0x36C9, 16);
  addKey("Aspect", AspectRatio_Key, 0xF609, 16);
  addKey("ArrowRight", Right_Key, 0x4EB1, 16);
  addKey("ArrowLeft", Left_Key, 0xCE31, 16);
  addKey("DayMode", Unmapped_Key, 0x2ED1, 16);
  addKey("NightMode", Unmapped_Key, 0xAE51, 16);
  addKey("AntennaA", Unmapped_Key, 0x6E91, 16);
  addKey("AntennaB", Unmapped_Key, 0xEE11, 16);
  addKey("CC", Unmapped_Key, 0x1EE1, 16); // Another CC key?
  addKey("Guide", Guide_Key, 0xAC53, 16);
  // Many more codes available in LIRC's hitachi/CLU4341UG2 config file
}


HitachiProjector::HitachiProjector(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Projector Keyset",
      Hitachi_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index);

  setPreData(0xE1A2, 16);

  addKey("Power", Power_Key, 0xE817, 16);
  addKey("PageUp", Unmapped_Key, 0x0BF4, 16);
  addKey("PageDown", Unmapped_Key, 0x8B74, 16);
  addKey("Home", Unmapped_Key, 0xAB54, 16);
  addKey("End", Unmapped_Key, 0x6B94, 16);
  addKey("Enter", Select_Key, 0x847B, 16);
  addKey("Left", Left_Key, 0x748B, 16);
  addKey("Right", Right_Key, 0x54AB, 16);
  addKey("Up", Up_Key, 0x14EB, 16);
  addKey("Down", Down_Key, 0x34CB, 16);
  addKey("Menu", Menu_Key, 0x04FB, 16);
  addKey("Reset", Reset_Key, 0x44BB, 16);
  addKey("Esc", Unmapped_Key, 0x2BD4, 16);
  addKey("Position", Unmapped_Key, 0x0CF3, 16);
  addKey("Freeze", Unmapped_Key, 0x2DD2, 16);
  addKey("Keystone", Unmapped_Key, 0x6D92, 16);
  addKey("Search", Unmapped_Key, 0x58A7, 16);
  addKey("RGB", PictureMode_Key, 0x18E7, 16);
  addKey("Video", Unmapped_Key, 0x9867, 16);
  addKey("Aspect", AspectRatio_Key, 0x5EA1, 16);
  addKey("MagnifyOn", Unmapped_Key, 0x0DF2, 16);
  addKey("MagnifyOff", Unmapped_Key, 0xCD32, 16);
  addKey("Volume", Unmapped_Key, 0xCA35, 16);
  addKey("Mute", Mute_Key, 0x4AB5, 16);
  addKey("Auto", Unmapped_Key, 0x24DB, 16);
  addKey("Blank", Unmapped_Key, 0x827D, 16);
}


HitachiDVD1::HitachiDVD1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Hitachi_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index);

  setPreData(0x01C4, 16);

  addKey("Power", Power_Key, 0x50AF, 16);
  addKey("Surround", Surround_Key, 0xBA45, 16);
  addKey("SearchMode", Unmapped_Key, 0x7C83, 16);
  addKey("OpenClose", Eject_Key, 0x906F, 16);
  addKey("ABRepeat", Unmapped_Key, 0x04FB, 16);
  addKey("1", One_Key, 0xB04F, 16);
  addKey("2", Two_Key, 0x708F, 16);
  addKey("3", Three_Key, 0xF00F, 16);
  addKey("4", Four_Key, 0x38C7, 16);
  addKey("5", Five_Key, 0xB847, 16);
  addKey("6", Six_Key, 0x7887, 16);
  addKey("7", Seven_Key, 0xF807, 16);
  addKey("8", Eight_Key, 0x20DF, 16);
  addKey("9", Nine_Key, 0xA05F, 16);
  addKey("0", Zero_Key, 0x30CF, 16);
  addKey("Repeat", Unmapped_Key, 0x00FF, 16);
  addKey("Mode", Unmapped_Key, 0xB44B, 16);
  addKey("Zoom", Unmapped_Key, 0xDC23, 16);
  addKey("Clear", Clear_Key, 0x9867, 16);
  addKey("+10", DoubleDigit_Key, 0x08F7, 16);
  addKey("Angle", Unmapped_Key, 0x54AB, 16);
  addKey("Subtitle", Captions_Key, 0xD42B, 16);
  addKey("Audio", Language_Key, 0x34CB, 16);
  addKey("Display", Info_Key, 0xD02F, 16);
  addKey("Menu", DiscMenu_Key, 0xE01F, 16);
  addKey("TopMenu", DiscTitle_Key, 0x609F, 16);
  addKey("Up", Up_Key, 0x44BB, 16);
  addKey("Left", Left_Key, 0x24DB, 16);
  addKey("Enter", Select_Key, 0x649B, 16);
  addKey("Right", Right_Key, 0xA45B, 16);
  addKey("Down", Down_Key, 0xC43B, 16);
  addKey("Return", Exit_Key, 0xE41B, 16);
  addKey("Setup", Menu_Key, 0x10EF, 16);
  addKey("DiscNav", Guide_Key, 0x4CB3, 16);
  addKey("Prev", Previous_Key, 0xC03F, 16);
  addKey("Next", Next_Key, 0x40BF, 16);
  addKey("Stop", Stop_Key, 0xD827, 16);
  addKey("Play", Play_Key, 0x28D7, 16);
  addKey("Rew", Rewind_Key, 0x48B7, 16);
  addKey("Pause", Pause_Key, 0x58A7, 16);
  addKey("FF", FastForward_Key, 0x8877, 16);
}


HitachiAudio1::HitachiAudio1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 1",
      Hitachi_Make,
      index)
{
  addControlledDevice(Hitachi_Make, "FX-7", Audio_Device);
  addControlledDevice(Hitachi_Make, "FX-77", Audio_Device);

  threadableProtocol = new NECProtocol(guiObject, index);

  setPreData(0xDA25, 16);

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
  addKey("CD_SKIP_BACK", Previous_Key, 0xA857, 16);
  addKey("CD_SKIP_FWD", Next_Key, 0x28D7, 16);
  addKey("CD_STOP", Stop_Key, 0xC837, 16);
  addKey("CD_PLAY/PAUSE", Play_Key, 0x48B7, 16);
  addKey("CD_PLAY/PAUSE", Pause_Key, 0x48B7, 16);
  addKey("CD_PROG", Program_Key, 0x6897, 16);
  addKey("CASSETTE_PLAY_BACK", Unmapped_Key, 0x58A7, 16);
  addKey("CASSETTE_STOP", Unmapped_Key, 0xB847, 16);
  addKey("CASSETTE_PLAY_FORWARD", Unmapped_Key, 0x9867, 16);
  addKey("CASSETTE_REC", Record_Key, 0xF807, 16);
  addKey("CASSETTE_TAPE_1/2", Unmapped_Key, 0x906F, 16);
  addKey("CASSETTE_REW", Unmapped_Key, 0x38C7, 16);
  addKey("CASSETTE_FFW", Unmapped_Key, 0xD827, 16);
  addKey("VOLUME_DOWN", VolumeDown_Key, 0x40BF, 16);
  addKey("VOLUME_UP", VolumeUp_Key, 0x807F, 16);
  addKey("TUNER_BAND", Input_Key, 0xE01F, 16);
  addKey("POWER", Power_Key, 0x00FF, 16);
}


HitachiVCR1::HitachiVCR1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      Hitachi_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index);

  setPreData(0x06F9, 16);

  addKey("Power", Power_Key, 0xE817, 16);
  addKey("Eject", Eject_Key, 0x9C63, 16);
  addKey("VCR/TV", Input_Key, 0x6897, 16);
  addKey("P+", ChannelUp_Key, 0x9867, 16);
  addKey("P-", ChannelDown_Key, 0x18E7, 16);
  addKey("Play", Play_Key, 0x28D7, 16);
  addKey("FF", FastForward_Key, 0x906F, 16);
  addKey("Rew", Rewind_Key, 0x50AF, 16);
  addKey("Stop", Stop_Key, 0xD02F, 16);
  addKey("Pause", Pause_Key, 0x58A7, 16);
  addKey("Step", StepForward_Key, 0x08F7, 16);
  addKey("SpinRight", Right_Key, 0xFE01, 16);
  addKey("SpinLeft", Left_Key, 0x7E81, 16);
  addKey("Enter", Select_Key, 0x22DD, 16);
  addKey("TransAux", Unmapped_Key, 0x2CD3, 16); // "AVX"
  addKey("1", One_Key, 0xB04F, 16);
  addKey("2", Two_Key, 0x708F, 16);
  addKey("3", Three_Key, 0xF00F, 16);
  addKey("4", Four_Key, 0x38C7, 16);
  addKey("5", Five_Key, 0xB847, 16);
  addKey("6", Six_Key, 0x7887, 16);
  addKey("7", Seven_Key, 0xF807, 16);
  addKey("8", Eight_Key, 0x20DF, 16);
  addKey("9", Nine_Key, 0xA05F, 16);
  addKey("0", Zero_Key, 0x30CF, 16);
  addKey("Menu", Menu_Key, 0x02FD, 16);
  addKey("Disp", Info_Key, 0x42BD, 16);
  addKey("Index", Unmapped_Key, 0xA25D, 16);
  addKey("SP/LP", VHSSpeed_Key, 0x0CF3, 16);
  addKey("Count/Clock", Unmapped_Key, 0x629D, 16);
  addKey("CLEAR", Reset_Key, 0x827D, 16); // "reset", "0000"
  addKey("Slow", Unmapped_Key, 0x8877, 16);
  addKey("CH1/2", Unmapped_Key, 0xA857, 16); // "CHANNEL"
  addKey("A.DUB", Unmapped_Key, 0x34CB, 16);
  addKey("V.DUB", Unmapped_Key, 0x5CA3, 16);
  addKey("Tracking+", TrackingPlus_Key, 0x00FF, 16);
  addKey("Tracking-", TrackingMinus_Key, 0x807F, 16);
  addKey("100/ENT", PlusOneHundred_Key, 0x609F, 16);
  addKey("-", Unmapped_Key, 0xC03F, 16);
  addKey("+", Unmapped_Key, 0x40BF, 16);
  addKey("GO-TO", Unmapped_Key, 0x619E, 16);
  addKey("FRAME+", Unmapped_Key, 0xBE41, 16); // This is for jog/shuttle!
  addKey("FRAME-", Unmapped_Key, 0x7E81, 16); // I'll get the other j/s later
  // For more Jog/Shuttle see LIRC hitachi/VT-RM783E
  addKey("tracking_auto", AutoTracking_Key, 0x7C83, 16);
}
