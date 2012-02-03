#include "hitachi.h"
#include "protocols/necprotocol.h"

HitachiTV1::HitachiTV1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Hitachi_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index, false, true);

//  setPreData(0x0AF5, 16);
  setPreData(0x50, 8);

  addKey("8", Eight_Key, 0x04, 8);
  addKey("9", Nine_Key, 0x05, 8);
//  addKey("Language", Language_Key, 0x06, 8);
  addKey("CH_I/II", Audio_Key, 0x08, 8);
  addKey("tv/video", Input_Key, 0x09, 8); // "AV"
  addKey("mute", Mute_Key, 0x0B, 8);
  addKey("0", Zero_Key, 0x0C, 8);
  addKey("1", One_Key, 0x0D, 8);
  addKey("2", Two_Key, 0x0E, 8);
  addKey("3", Three_Key, 0x0F, 8);
  addKey("recall", PrevChannel_Key, 0x10, 8);
  addKey("timer", Sleep_Key, 0x11, 8);
  addKey("vol_up", VolumeUp_Key, 0x12, 8);
  addKey("CH", Unmapped_Key, 0x13, 8);
  addKey("Store", Unmapped_Key, 0x14, 8);
  addKey("vol_down", VolumeDown_Key, 0x15, 8);
  addKey("power", Power_Key, 0x17, 8);
  addKey("ch_down", ChannelDown_Key, 0x18, 8);
  addKey("ch_up", ChannelUp_Key, 0x19, 8);
  addKey("HELP", Info_Key, 0x1A, 8);
  addKey("3D-SOUND", Surround_Key, 0x1B, 8);
  addKey("4", Four_Key, 0x1C, 8);
  addKey("5", Five_Key, 0x1D, 8);
  addKey("6", Six_Key, 0x1E, 8);
  addKey("7", Seven_Key, 0x1F, 8);
  addKey("MENU", Menu_Key, 0x40, 8);
  addKey("OK", Select_Key, 0x43, 8);
  addKey("return", Exit_Key, 0x44, 8);
  addKey("SUB", Captions_Key, 0x45, 8);
  addKey("U.N.L", Unmapped_Key, 0x46, 8);
  addKey("HOLD", TeletextHold_Key, 0x47, 8);
  addKey("Red", Red_Key, 0x4C, 8);
  addKey("PSCAN100HZ", Unmapped_Key, 0x4D, 8);
  addKey("SOUND", SoundMode_Key, 0x4F, 8);
  addKey("X", Unmapped_Key, 0x54, 8);
  addKey("krasn", Unmapped_Key, 0x5B, 8);
  addKey("zelen", Unmapped_Key, 0x5C, 8);
  addKey("Reveal", Unmapped_Key, 0x5D, 8); // "jolt"
  addKey("zelen", Unmapped_Key, 0x5E, 8);
  addKey("TV/TEXT", Teletext_Key, 0x66, 8);
  addKey("Picture", PictureMode_Key, 0x67, 8);
  addKey("Cancel", Clear_Key, 0x68, 8);
  addKey("PLAY", Play_Key, 0x6B, 8);
  addKey("STOP", Stop_Key, 0x6C, 8);
  addKey("REV", Rewind_Key, 0x6D, 8);
  addKey("FWD", FastForward_Key, 0x6F, 8);
  addKey("UP", Up_Key, 0x70, 8);
  addKey("DOWN", Down_Key, 0x71, 8);
}


HitachiTV1a::HitachiTV1a(
  QObject *guiObject,
  unsigned int index)
  : HitachiTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1a");

  addKey("menu", Menu_Key, 0x53, 8);
}

HitachiTV1b::HitachiTV1b(
  QObject *guiObject,
  unsigned int index)
  : HitachiTV1a(guiObject, index)
{
  setKeysetName("TV Keyset 1b");

  addKey("Sound+", VolumeUp_Key, 0x72, 8);
  addKey("Sound-", VolumeDown_Key, 0x73, 8);
  addKey("Timer", Sleep_Key, 0x6B, 8);
}


HitachiTV1c::HitachiTV1c(
  QObject *guiObject,
  unsigned int index)
  : HitachiTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1c");

  addControlledDevice(Hitachi_Make, "57F510", TV_Device);

  addKey("LastChannel", PrevChannel_Key, 0x0A, 8);
  addKey("Info", Info_Key, 0x10, 8);
  addKey("Input1", Unmapped_Key, 0x21, 8);
  addKey("Input2", Unmapped_Key, 0x22, 8);
  addKey("Input3", Unmapped_Key, 0x23, 8);
  addKey("Input4", Unmapped_Key, 0x24, 8);
  addKey("ChannelUp", Unmapped_Key, 0x28, 8); // these four are odd
  addKey("ChannelDown", Unmapped_Key, 0x29, 8); // duplicate?
  addKey("VolumeDown", Unmapped_Key, 0x2A, 8); // maybe pip?
  addKey("VolumeUp", Unmapped_Key, 0x2B, 8); // doesn't make sense
  addKey("SELECT", Select_Key, 0x2E, 8);
  addKey("Guide", Guide_Key, 0x35, 8);
  addKey("CC", Captions_Key, 0x37, 8);
  addKey("FavouriteChannel", Favorites_Key, 0x38, 8);
  addKey("1080i/540p", Unmapped_Key, 0x3C, 8);
  addKey("Input5", Unmapped_Key, 0x3D, 8);
  addKey("PowerON", PowerOn_Key, 0x3E, 8);
  addKey("PowerOFF", PowerOff_Key, 0x3F, 8);
  addKey("Menu", Menu_Key, 0x53, 8);
  addKey("PIP", PIP_Key, 0x58, 8);
  addKey("Day/Night", Unmapped_Key, 0x5E, 8);
  addKey("Freeze/Pause", Unmapped_Key, 0x61, 8);
  addKey("EXIT", Exit_Key, 0x64, 8);
  addKey("16:9", Unmapped_Key, 0x65, 8);
  addKey("16:9Zoom", Unmapped_Key, 0x66, 8);
  addKey("4:3Standard", Unmapped_Key, 0x67, 8);
  addKey("4:3Expanded", Unmapped_Key, 0x68, 8);
  addKey("4:3Zoom1", Unmapped_Key, 0x69, 8);
  addKey("4:3Zoom2", Unmapped_Key, 0x6A, 8);
  addKey("540p", Unmapped_Key, 0x6B, 8);
  addKey("1080i", Unmapped_Key, 0x6C, 8);
  addKey("Aspect", AspectRatio_Key, 0x6F, 8);
  addKey("ArrowRight", Right_Key, 0x72, 8);
  addKey("ArrowLeft", Left_Key, 0x73, 8);
  addKey("DayMode", Unmapped_Key, 0x74, 8);
  addKey("NightMode", Unmapped_Key, 0x75, 8);
  addKey("AntennaA", AntennaInput_Key, 0x76, 8);
  addKey("AntennaB", Antenna2Input_Key, 0x77, 8);
  addKey("CC", Unmapped_Key, 0x78, 8); // Another CC key?
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
  threadableProtocol = new NECProtocol(guiObject, index, true, true);

//  setPreData(0xE1A2, 16);
  setPreData(0x4587, 16);

  addKey("Power", Power_Key, 0x17, 8);
  addKey("RGB", PictureMode_Key, 0x18, 8);
  addKey("Video", Unmapped_Key, 0x19, 8);
  addKey("Search", Unmapped_Key, 0x1A, 8);
  addKey("Menu", Menu_Key, 0x20, 8);
  addKey("Enter", Select_Key, 0x21, 8);
  addKey("Reset", Reset_Key, 0x22, 8);
  addKey("Auto", Unmapped_Key, 0x24, 8);
  addKey("Up", Up_Key, 0x28, 8);
  addKey("Right", Right_Key, 0x2A, 8);
  addKey("Down", Down_Key, 0x2C, 8);
  addKey("Left", Left_Key, 0x2E, 8);
  addKey("Position", Unmapped_Key, 0x30, 8);
  addKey("Blank", Unmapped_Key, 0x41, 8);
  addKey("Mute", Mute_Key, 0x52, 8);
  addKey("Volume", Unmapped_Key, 0x53, 8);
  addKey("Aspect", AspectRatio_Key, 0x7A, 8);
  addKey("MagnifyOn", Unmapped_Key, 0xB0, 8);
  addKey("MagnifyOff", Unmapped_Key, 0xB3, 8);
  addKey("Freeze", Unmapped_Key, 0xB4, 8);
  addKey("Keystone", Unmapped_Key, 0xB6, 8);
  addKey("PageUp", PageUp_Key, 0xD0, 8);
  addKey("PageDown", PageDown_Key, 0xD1, 8);
  addKey("Esc", Unmapped_Key, 0xD4, 8);
  addKey("Home", Unmapped_Key, 0xD5, 8);
  addKey("End", Unmapped_Key, 0xD6, 8);
}


HitachiDVD1::HitachiDVD1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Hitachi_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index, true, true);

//  setPreData(0x01C4, 16);
  setPreData(0x2380, 16);

  addKey("Repeat", Repeat_Key, 0x00, 8);
  addKey("Next", Next_Key, 0x02, 8);
  addKey("Prev", Previous_Key, 0x03, 8);
  addKey("8", Eight_Key, 0x04, 8);
  addKey("9", Nine_Key, 0x05, 8);
  addKey("TopMenu", DiscTitle_Key, 0x06, 8);
  addKey("Menu", DiscMenu_Key, 0x07, 8);
  addKey("Setup", Menu_Key, 0x08, 8);
  addKey("OpenClose", Eject_Key, 0x09, 8);
  addKey("Power", Power_Key, 0x0A, 8);
  addKey("Display", Info_Key, 0x0B, 8);
  addKey("0", Zero_Key, 0x0C, 8);
  addKey("1", One_Key, 0x0D, 8);
  addKey("2", Two_Key, 0x0E, 8);
  addKey("3", Three_Key, 0x0F, 8);
  addKey("+10", DoubleDigit_Key, 0x10, 8);
  addKey("FF", FastForward_Key, 0x11, 8);
  addKey("Rew", Rewind_Key, 0x12, 8);
  addKey("Play", Play_Key, 0x14, 8);
  addKey("Clear", Clear_Key, 0x19, 8);
  addKey("Pause", Pause_Key, 0x1A, 8);
  addKey("Stop", Stop_Key, 0x1B, 8);
  addKey("4", Four_Key, 0x1C, 8);
  addKey("5", Five_Key, 0x1D, 8);
  addKey("6", Six_Key, 0x1E, 8);
  addKey("7", Seven_Key, 0x1F, 8);
  addKey("ABRepeat", RepeatAB_Key, 0x20, 8);
  addKey("Up", Up_Key, 0x22, 8);
  addKey("Down", Down_Key, 0x23, 8);
  addKey("Left", Left_Key, 0x24, 8);
  addKey("Right", Right_Key, 0x25, 8);
  addKey("Enter", Select_Key, 0x26, 8);
  addKey("Return", Exit_Key, 0x27, 8);
  addKey("Angle", Angle_Key, 0x2A, 8);
  addKey("Subtitle", Captions_Key, 0x2B, 8);
  addKey("Audio", Audio_Key, 0x2C, 8);
  addKey("Mode", Mode_Key, 0x2D, 8);
  addKey("DiscNav", Guide_Key, 0x32, 8);
  addKey("Zoom", Zoom_Key, 0x3B, 8);
  addKey("SearchMode", Unmapped_Key, 0x3E, 8);
  addKey("Surround", Surround_Key, 0x5D, 8);
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

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

//  setPreData(0xDA25, 16);
  setPreData(0x5B, 8);

  addKey("POWER", Power_Key, 0x00, 8);
  addKey("VOLUME_UP", VolumeUp_Key, 0x01, 8);
  addKey("VOLUME_DOWN", VolumeDown_Key, 0x02, 8);
  addKey("TUNER_BAND", TunerBand_Key, 0x07, 8);
  addKey("CASSETTE_TAPE_1/2", Unmapped_Key, 0x09, 8);
  addKey("CD_PLAY/PAUSE", Play_Key, 0x12, 8);
  addKey("CD_PLAY/PAUSE", Pause_Key, 0x12, 8);
  addKey("CD_STOP", Stop_Key, 0x13, 8);
  addKey("CD_SKIP_FWD", Next_Key, 0x14, 8);
  addKey("CD_SKIP_BACK", Previous_Key, 0x15, 8);
  addKey("CD_PROG", Program_Key, 0x16, 8);
  addKey("CASSETTE_PLAY_FORWARD", Unmapped_Key, 0x19, 8);
  addKey("CASSETTE_PLAY_BACK", Unmapped_Key, 0x1A, 8);
  addKey("CASSETTE_FFW", Unmapped_Key, 0x1B, 8);
  addKey("CASSETTE_REW", Unmapped_Key, 0x1C, 8);
  addKey("CASSETTE_STOP", Unmapped_Key, 0x1D, 8);
  addKey("CASSETTE_REC", Record_Key, 0x1F, 8);
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
  addKey("0/11", Zero_Key, 0x5B, 8);
}


HitachiVCR1::HitachiVCR1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      Hitachi_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index, false, true);

//  setPreData(0x06F9, 16);
  setPreData(0x60, 8);

  addKey("Tracking+", TrackingPlus_Key, 0x00, 8);
  addKey("Tracking-", TrackingMinus_Key, 0x01, 8);
  addKey("+", Unmapped_Key, 0x02, 8);
  addKey("-", Unmapped_Key, 0x03, 8);
  addKey("8", Eight_Key, 0x04, 8);
  addKey("9", Nine_Key, 0x05, 8);
  addKey("100/ENT", PlusOneHundred_Key, 0x06, 8);
  addKey("FF", FastForward_Key, 0x09, 8);
  addKey("Step", StepForward_Key, 0x10, 8);
  addKey("Rew", Rewind_Key, 0x0A, 8);
  addKey("Stop", Stop_Key, 0x0B, 8);
  addKey("0", Zero_Key, 0x0C, 8);
  addKey("1", One_Key, 0x0D, 8);
  addKey("2", Two_Key, 0x0E, 8);
  addKey("3", Three_Key, 0x0F, 8);
  addKey("Slow", Slow_Key, 0x11, 8);
  addKey("Play", Play_Key, 0x14, 8);
  addKey("CH1/2", Unmapped_Key, 0x15, 8); // "CHANNEL"
  addKey("VCR/TV", Input_Key, 0x16, 8);
  addKey("Power", Power_Key, 0x17, 8);
  addKey("P-", ChannelDown_Key, 0x18, 8);
  addKey("P+", ChannelUp_Key, 0x19, 8);
  addKey("Pause", Pause_Key, 0x1A, 8);
  addKey("4", Four_Key, 0x1C, 8);
  addKey("5", Five_Key, 0x1D, 8);
  addKey("6", Six_Key, 0x1E, 8);
  addKey("7", Seven_Key, 0x1F, 8);
  addKey("A.DUB", Unmapped_Key, 0x2C, 8);
  addKey("SP/LP", VHSSpeed_Key, 0x30, 8);
  addKey("TransAux", Unmapped_Key, 0x34, 8); // "AVX"
  addKey("Eject", Eject_Key, 0x39, 8);
  addKey("V.DUB", Unmapped_Key, 0x3A, 8);
  addKey("tracking_auto", AutoTracking_Key, 0x3E, 8);
  addKey("Menu", Menu_Key, 0x40, 8);
  addKey("CLEAR", Reset_Key, 0x41, 8); // "reset", "0000"
  addKey("Disp", Info_Key, 0x42, 8);
  addKey("Enter", Select_Key, 0x44, 8);
  addKey("Index", Unmapped_Key, 0x45, 8);
  addKey("Count/Clock", Clock_Key, 0x46, 8);
  addKey("SpinRight", Right_Key, 0x7F, 8);
  addKey("SpinLeft", Left_Key, 0x7E, 8);
  addKey("GO-TO", Unmapped_Key, 0x86, 8);

//  addKey("FRAME+", Unmapped_Key, 0x7D, 8); // This is for jog/shuttle!
//  addKey("FRAME-", Unmapped_Key, 0x7E, 8); // I'll get the other j/s later
  // For more Jog/Shuttle see LIRC hitachi/VT-RM783E
}
