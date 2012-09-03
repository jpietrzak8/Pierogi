#include "pioneer.h"
#include "protocols/pioneerprotocol.h"
#include "protocols/lircprotocol.h"

PioneerTV1::PioneerTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Pioneer_Make,
      index)
{
}


void PioneerTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new PioneerProtocol(guiObject, index);

  addNECKey("0", Zero_Key, 0xAA, 0x00);
  addNECKey("1", One_Key, 0xAA, 0x01);
  addNECKey("2", Two_Key, 0xAA, 0x02);
  addNECKey("3", Three_Key, 0xAA, 0x03);
  addNECKey("4", Four_Key, 0xAA, 0x04);
  addNECKey("5", Five_Key, 0xAA, 0x05);
  addNECKey("6", Six_Key, 0xAA, 0x06);
  addNECKey("7", Seven_Key, 0xAA, 0x07);
  addNECKey("8", Eight_Key, 0xAA, 0x08);
  addNECKey("9", Nine_Key, 0xAA, 0x09);
  addNECKey("VOL_PLUS", VolumeUp_Key, 0xAA, 0x0A);
  addNECKey("VOL_MINUS", VolumeDown_Key, 0xAA, 0x0B);

  addNECKey("CH_PLUS", ChannelUp_Key, 0xAA, 0x10);
  addNECKey("CH_MINUS", ChannelDown_Key, 0xAA, 0x11);
  addNECKey("POWER_ON_OFF", Power_Key, 0xAA, 0x1C);
  addNECKey("RIGHT", Right_Key, 0xAA, 0x24);
  addNECKey("LEFT", Left_Key, 0xAA, 0x25);
  addNECKey("UP", Up_Key, 0xAA, 0x26);
  addNECKey("DOWN", Down_Key, 0xAA, 0x27);
  addNECKey("ENTER", Enter_Key, 0xAA, 0x28);
  addNECKey("REC", Record_Key, 0xAA, 0x38);
  addNECKey("INPUT_ANT", AntennaInput_Key, 0xAA, 0x45);
  addNECKey("MUTING", Mute_Key, 0xAA, 0x49);
  addNECKey("DISPLAY", Unmapped_Key, 0xAA, 0x4A);

  addPioneerKey("CH_ENTER", Enter_Key, 0xAA, 0x5A, 0xAF, 0x61);
  addPioneerKey("CH_RETURN", PrevChannel_Key, 0xAA, 0x5A, 0xAF, 0x62);
  addPioneerKey("DOT", Unmapped_Key, 0xAA, 0x5A, 0xAF, 0x64);
  addPioneerKey("INPUT_PC", PCInput_Key, 0xAA, 0x5A, 0xAF, 0x74);
  addPioneerKey("INPUT1", Unmapped_Key, 0xAA, 0x5A, 0xAF, 0x7A);
  addPioneerKey("INPUT2", Unmapped_Key, 0xAA, 0x5A, 0xAF, 0x7B);
  addPioneerKey("INPUT3", Unmapped_Key, 0xAA, 0x5A, 0xAF, 0x7C);
  addPioneerKey("INPUT4", Unmapped_Key, 0xAA, 0x5A, 0xAF, 0x7D);
  addPioneerKey("HDMI5", HDMIInput_Key, 0xAA, 0x5A, 0xAF, 0x7E);
  addPioneerKey("HDMI6", HDMI2Input_Key, 0xAA, 0x5A, 0xAF, 0x7F);

  addPioneerKey("HOME_MENU", Unmapped_Key, 0xAA, 0x5B, 0xAF, 0x20);
  addPioneerKey("RETURN", Exit_Key, 0xAA, 0x5B, 0xAF, 0x22);
  addPioneerKey("TV_GUIDE", Guide_Key, 0xAA, 0x5B, 0xAF, 0x24);
  addPioneerKey("INFO", Info_Key, 0xAA, 0x5B, 0xAF, 0x25);
  addPioneerKey("MENU", Menu_Key, 0xAA, 0x5B, 0xAF, 0x27);
  addPioneerKey("DAY_PLUS", Unmapped_Key, 0xAA, 0x5B, 0xAF, 0x2A);
  addPioneerKey("DAY_MINUS", Unmapped_Key, 0xAA, 0x5B, 0xAF, 0x2B);
  addPioneerKey("RED_B", Red_Key, 0xAA, 0x5B, 0xAF, 0x2C);
  addPioneerKey("GREEN_C", Green_Key, 0xAA, 0x5B, 0xAF, 0x2D);
  addPioneerKey("YELLOW_D", Yellow_Key, 0xAA, 0x5B, 0xAF, 0x2E);
  addPioneerKey("BLUE_A", Blue_Key, 0xAA, 0x5B, 0xAF, 0x2F);
  addPioneerKey("PAGE_PLUS", PageUp_Key, 0xAA, 0x5B, 0xAF, 0x33);
  addPioneerKey("PAGE_MINUS", PageDown_Key, 0xAA, 0x5B, 0xAF, 0x34);

  addNECKey("AV_SELECTION", Input_Key, 0xAA, 0x5E); // is this right?
  addPioneerKey("SCREEN_SIZE", AspectRatio_Key, 0xAA, 0x5E, 0xAF, 0x3A);
  addPioneerKey("SLEEP", Sleep_Key, 0xAA, 0x5E, 0xAF, 0x70);
}


PioneerTV2::PioneerTV2(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV (STB) Keyset 2",
      Pioneer_Make,
      index)
{
}


void PioneerTV2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new PioneerProtocol(guiObject, index);

  // I'm not sure this keyset even needs the "0xAA" keys at all...
  addNECKey("tv-dengen", Unmapped_Key, 0xAA, 0x1C);
  addNECKey("tv-nyuuryoku-kirikae", Unmapped_Key, 0xAA, 0x13);
  addNECKey("tv-channel-up", Unmapped_Key, 0xAA, 0x10);
  addNECKey("tv-channel-down", Unmapped_Key, 0xAA, 0x11);
  addNECKey("dengen", Power_Key, 0xAC, 0x1C);
  addNECKey("sleep", Sleep_Key, 0xAC, 0x48);
  addNECKey("1", One_Key, 0xAC, 0x01);
  addNECKey("2", Two_Key, 0xAC, 0x02);
  addNECKey("3", Three_Key, 0xAC, 0x03);
  addNECKey("4", Four_Key, 0xAC, 0x04);
  addNECKey("5", Five_Key, 0xAC, 0x05);
  addNECKey("6", Six_Key, 0xAC, 0x06);
  addNECKey("7", Seven_Key, 0xAC, 0x07);
  addNECKey("8", Eight_Key, 0xAC, 0x08);
  addNECKey("9", Nine_Key, 0xAC, 0x09);
  addNECKey("10-0", Zero_Key, 0xAC, 0x00);
  addNECKey("channel-up", ChannelUp_Key, 0xAC, 0x10);
  addNECKey("channel-down", ChannelDown_Key, 0xAC, 0x11);
  addNECKey("mute", Mute_Key, 0xAA, 0x49);
  addNECKey("volume-up", VolumeUp_Key, 0xAA, 0x0A);
  addNECKey("volume-down", VolumeDown_Key, 0xAA, 0x0B);
  addNECKey("ff-left", Unmapped_Key, 0xAC, 0x4B);
  addNECKey("ff-right", Unmapped_Key, 0xAC, 0x13);
  addNECKey("ff-down", Unmapped_Key, 0xAC, 0x4F);
  addNECKey("ff-up", Unmapped_Key, 0xAC, 0x4E);
  addNECKey("up", Up_Key, 0xAC, 0x58);
  addNECKey("down", Down_Key, 0xAC, 0x59);
  addNECKey("left", Left_Key, 0xAC, 0x57);
  addNECKey("right", Right_Key, 0xAC, 0x56);
  addNECKey("kettei", Unmapped_Key, 0xAC, 0x4C);
  addNECKey("guide", Guide_Key, 0xAC, 0x50);
  addNECKey("shousai", Unmapped_Key, 0xAC, 0x54);
  addNECKey("modoru", Unmapped_Key, 0xAC, 0x53);
  addNECKey("navi", Unmapped_Key, 0xAC, 0x18);
  addNECKey("okonomi", Unmapped_Key, 0xAC, 0x44);
  addNECKey("channel-hyouji", Unmapped_Key, 0xAC, 0x4A);
  addNECKey("channel-ichiran", Unmapped_Key, 0xAC, 0x5B);
  addNECKey("channel-return", Unmapped_Key, 0xAC, 0x5C);
  addNECKey("onsei", Unmapped_Key, 0xAC, 0x1E);
//  addNECKey(, Unmapped_Key, 0xAC, 0x33); //"catv", "data", "aoi", "akai", "midori", "kiiroi", "vod", "browser", "genre-kensaku", "gazou"
  addPioneerKey("chijo", Unmapped_Key, 0xAC, 0x33, 0xAF, 0x3B);
  addPioneerKey("bscs", Unmapped_Key, 0xAC, 0x33, 0xAF, 0x3D);
  addPioneerKey("ch", Unmapped_Key, 0xAC, 0x33, 0xAF, 0x3C);
  addPioneerKey("11", Unmapped_Key, 0xAC, 0x33, 0xAF, 0x39);
  addPioneerKey("12", Unmapped_Key, 0xAC, 0x33, 0xAF, 0x38);
  addPioneerKey("jimaku", Unmapped_Key, 0xAC, 0x33, 0xAF, 0x31);
}


PioneerTV3::PioneerTV3(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV (STB) Keyset 3",
      Pioneer_Make,
      index)
{
}


void PioneerTV3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new PioneerProtocol(guiObject, index);

  addNECKey("KEY_VOLUMEUP", VolumeUp_Key, 0xAA, 0x0A);
  addNECKey("KEY_VOLUMEDOWN", VolumeDown_Key, 0xAA, 0x0B);
  addNECKey("KEY_CHANNELUP", ChannelUp_Key, 0xAA, 0x10);
  addNECKey("KEY_CHANNELDOWN", ChannelDown_Key, 0xAA, 0x11);
  addNECKey("KEY_VCR", Unmapped_Key, 0xAA, 0x13);
  addNECKey("KEY_POWER3", Unmapped_Key, 0xAA, 0x1C);
  addNECKey("KEY_MUTE", Mute_Key, 0xAA, 0x49);
  addNECKey("KEY_UP", Up_Key, 0xAA, 0xE9);
  addNECKey("KEY_DOWN", Down_Key, 0xAA, 0xEA);
  addNECKey("KEY_RIGHT", Right_Key, 0xAA, 0xEB);
  addNECKey("KEY_LEFT", Left_Key, 0xAA, 0xEC);
  addNECKey("KEY_OK", Select_Key, 0xAA, 0xED);

  addPioneerKey("KEY_0", Zero_Key, 0xAA, 0xEE, 0xAF, 0x20);
  addPioneerKey("KEY_1", One_Key, 0xAA, 0xEE, 0xAF, 0x21);
  addPioneerKey("KEY_2", Two_Key, 0xAA, 0xEE, 0xAF, 0x22);
  addPioneerKey("KEY_3", Three_Key, 0xAA, 0xEE, 0xAF, 0x23);
  addPioneerKey("KEY_4", Four_Key, 0xAA, 0xEE, 0xAF, 0x24);
  addPioneerKey("KEY_5", Five_Key, 0xAA, 0xEE, 0xAF, 0x25);
  addPioneerKey("KEY_6", Six_Key, 0xAA, 0xEE, 0xAF, 0x26);
  addPioneerKey("KEY_7", Seven_Key, 0xAA, 0xEE, 0xAF, 0x27);
  addPioneerKey("KEY_8", Eight_Key, 0xAA, 0xEE, 0xAF, 0x28);
  addPioneerKey("KEY_9", Nine_Key, 0xAA, 0xEE, 0xAF, 0x29);
  addPioneerKey("KEY_POWER", Power_Key, 0xAA, 0xEE, 0xAF, 0x2A);
  addPioneerKey("KEY_PROGRAM", Program_Key, 0xAA, 0xEE, 0xAF, 0x2D);
  addPioneerKey("KEY_PERSO", Unmapped_Key, 0xAA, 0xEE, 0xAF, 0x30);
  addPioneerKey("KEY_A", Unmapped_Key, 0xAA, 0xEE, 0xAF, 0x31);
  addPioneerKey("KEY_B", Unmapped_Key, 0xAA, 0xEE, 0xAF, 0x32);
  addPioneerKey("KEY_C", Unmapped_Key, 0xAA, 0xEE, 0xAF, 0x33);
  addPioneerKey("KEY_D", Unmapped_Key, 0xAA, 0xEE, 0xAF, 0x34);
  addPioneerKey("KEY_E", Unmapped_Key, 0xAA, 0xEE, 0xAF, 0x35);
  addPioneerKey("KEY_SAT", Unmapped_Key, 0xAA, 0xEE, 0xAF, 0x37);
  addPioneerKey("KEY_EPG", Guide_Key, 0xAA, 0xEE, 0xAF, 0x38);
  addPioneerKey("KEY_FAVORITES", Favorites_Key, 0xAA, 0xEE, 0xAF, 0x39);
  addPioneerKey("KEY_ESC", Exit_Key, 0xAA, 0xEE, 0xAF, 0x3A);
  addPioneerKey("KEY_SERVICE", Unmapped_Key, 0xAA, 0xEE, 0xAF, 0x3B);
  addPioneerKey("KEY_PLUS", Unmapped_Key, 0xAA, 0xEE, 0xAF, 0x3C);
  addPioneerKey("KEY_AUDIO", Audio_Key, 0xAA, 0xEE, 0xAF, 0x60);
  addPioneerKey("KEY_FREEZE", Pause_Key, 0xAA, 0xEE, 0xAF, 0x61);

  addNECKey("KEY_FORWARD", FastForward_Key, 0xAB, 0x10);
  addNECKey("KEY_REWIND", Rewind_Key, 0xAB, 0x11);
  addNECKey("KEY_RECORD", Record_Key, 0xAB, 0x14);
  addNECKey("KEY_STOP", Stop_Key, 0xAB, 0x16);
  addNECKey("KEY_PLAY", Play_Key, 0xAB, 0x17);
  addNECKey("KEY_PAUSE", Pause_Key, 0xAB, 0x18);
  addNECKey("KEY_POWER2", Unmapped_Key, 0xAB, 0x1C);
}


PioneerAudio1::PioneerAudio1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 1",
      Pioneer_Make,
      index)
{
  addControlledDevice(Pioneer_Make, "XC-L11 (Radio/CD)", Audio_Device);
  addControlledDevice(Pioneer_Make, "Hi-Fi DU-L7", Audio_Device);
  addControlledDevice(Pioneer_Make, "CU-XR015", Audio_Device);
  addControlledDevice(Pioneer_Make, "A880", Audio_Device);
}


void PioneerAudio1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new PioneerProtocol(guiObject, index);

  addNECKey("TAPE2_FWD", Unmapped_Key, 0xA1, 0x10);
  addNECKey("TAPE2_RWD", Unmapped_Key, 0xA1, 0x11);
  addNECKey("TAPE2_STOP", Unmapped_Key, 0xA1, 0x16);
  addNECKey("tape_fforw", Unmapped_Key, 0xA1, 0x56);
  addNECKey("tape_fback", Unmapped_Key, 0xA1, 0x57);
  addNECKey("tape_back", Unmapped_Key, 0xA1, 0x5B);
  addNECKey("tape_stop", Unmapped_Key, 0xA1, 0x5C);
  addNECKey("tape_forw", Unmapped_Key, 0xA1, 0x5D);

  // Might want subclass for CD?
  addNECKey("REPEAT", Repeat_Key, 0xA2, 0x0C);
  addNECKey("PGM", Program_Key, 0xA2, 0x0D);
  addNECKey("cd_forw", Unmapped_Key, 0xA2, 0x10);
  addNECKey("cd_back", Unmapped_Key, 0xA2, 0x11);
  addNECKey("cd_stop", Unmapped_Key, 0xA2, 0x16);
  addNECKey("cd_play", Unmapped_Key, 0xA2, 0x17);
  addNECKey("cd_pause", Unmapped_Key, 0xA2, 0x18);
  addNECKey("DISC_CHANGE", NextDisc_Key, 0xA2, 0x1D);
  addNECKey("disc1", Unmapped_Key, 0xA2, 0x1E);
  addNECKey("disc2", Unmapped_Key, 0xA2, 0x1F);
  addNECKey("clear", Unmapped_Key, 0xA2, 0x45);
  addNECKey("cd_rnd", Random_Key, 0xA2, 0x4A); // "random"
  addNECKey("disc3", Unmapped_Key, 0xA2, 0x50);
  addNECKey("OPEN", Eject_Key, 0xA2, 0x51);

  addNECKey("station+", ChannelUp_Key, 0xA4, 0x10);
  addNECKey("station-", ChannelDown_Key, 0xA4, 0x11);
  addNECKey("mono", FMMode_Key, 0xA4, 0x1E);

  addNECKey("1", One_Key, 0xA6, 0x00);
  addNECKey("2", Two_Key, 0xA6, 0x01);
  addNECKey("3", Three_Key, 0xA6, 0x02);
  addNECKey("4", Four_Key, 0xA6, 0x03);
  addNECKey("5", Five_Key, 0xA6, 0x04);
  addNECKey("6", Six_Key, 0xA6, 0x05);
  addNECKey("7", Seven_Key, 0xA6, 0x06);
  addNECKey("8", Eight_Key, 0xA6, 0x07);
  addNECKey("9", Nine_Key, 0xA6, 0x08);
  addNECKey("10/0", Zero_Key, 0xA6, 0x09);
  addNECKey("volume-up", VolumeUp_Key, 0xA6, 0x0A);
  addNECKey("volume-down", VolumeDown_Key, 0xA6, 0x0B);
  addNECKey("tape", TapeInput_Key, 0xA6, 0x17); // "TAPE2_PLAY"
  addNECKey("sleep", Sleep_Key, 0xA6, 0x19);
  addNECKey("standby", Power_Key, 0xA6, 0x1C); // "POWER"
  addNECKey("11/>10", DoubleDigit_Key, 0xA6, 0x40);
  addNECKey("12/CLR", Clear_Key, 0xA6, 0x41);
  addNECKey("cd", CDInput_Key, 0xA6, 0x44); // "CD_PLAY"
  addNECKey("scan", Scan_Key, 0xA6, 0x48);
  addNECKey("FM/AM", TunerInput_Key, 0xA6, 0x49); // "BAND"
  addNECKey("aux", AuxInput_Key, 0xA6, 0x4C);
  addNECKey("TAPE1_PLAY", Unmapped_Key, 0xA6, 0x5A);
  addNECKey("KARAOKE", Unmapped_Key, 0xA6, 0x69);
  addNECKey("menu", Menu_Key, 0xA6, 0x72); // "LEVEL"
  addNECKey("cancel", Exit_Key, 0xA6, 0x73); // probably not "exit"
  addNECKey("set", Select_Key, 0xA6, 0x74);
  addNECKey("play/pause", Play_Key, 0xA6, 0x75);
  addNECKey("play/pause", Pause_Key, 0xA6, 0x75);
  addNECKey("stop", Stop_Key, 0xA6, 0x90);
  addNECKey("next", Next_Key, 0xA6, 0x91);
  addNECKey("previous", Previous_Key, 0xA6, 0x92);
  addNECKey("forward", FastForward_Key, 0xA6, 0x93);
  addNECKey("rewind", Rewind_Key, 0xA6, 0x94);
  addNECKey("func", Unmapped_Key, 0xA6, 0x99);
  addNECKey("disp", Info_Key, 0xA6, 0x9D); // "DISPLAY"
//  addNECKey("am", TunerBand_Key, 0xA6, 0xA0); // "fm", messed up
//  addNECKey("minus", Left_Key, 0xA6, 0xA0); // "plus", messed up
  addNECKey("md", MDInput_Key, 0xA6, 0xA2);
  addNECKey("smart_ope", Unmapped_Key, 0xA6, 0xCA);
  addNECKey("snooze", Unmapped_Key, 0xA6, 0xCD);
  addNECKey("timer", Timer_Key, 0xA6, 0xCE);
  addNECKey("PRO_LOGIC", Unmapped_Key, 0xA6, 0xD4);
  addNECKey("TONE_TEST", Unmapped_Key, 0xA6, 0xD5);
  addNECKey("soundmorph+", Unmapped_Key, 0xA6, 0xD7); // "TURN_CW"
  addNECKey("soundmorph-", Unmapped_Key, 0xA6, 0xD8); // "TURN_ACW"
  addNECKey("sound", Audio_Key, 0xA6, 0xDA); // "SFC", "MORPHING"
  addNECKey("sfc_preset", Unmapped_Key, 0xA6, 0xDC);
  addNECKey("pbass", EnhancedBass_Key, 0xA6, 0xDD);
}


PioneerAudio1a::PioneerAudio1a(
  unsigned int index)
  : PioneerAudio1(index)
{
  setKeysetName("Audio Keyset 1a");
}


void PioneerAudio1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  PioneerAudio1::populateProtocol(guiObject);

  addNECKey("cd", CDInput_Key, 0xA6, 0x0E);
  addNECKey("tape", TapeInput_Key, 0xA6, 0x0F);
}


PioneerAudio2::PioneerAudio2(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 2",
      Pioneer_Make,
      index)
{
}


void PioneerAudio2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new PioneerProtocol(guiObject, index);

  addNECKey("VOL+", VolumeUp_Key, 0xA5, 0x0A);
  addNECKey("VOL-", VolumeDown_Key, 0xA5, 0x0B);
  addNECKey("Mute", Mute_Key, 0xA5, 0x12);

  addNECKey("Stop", Stop_Key, 0xAB, 0x20);
  addNECKey("RecordStop", RecordStop_Key, 0xAB, 0x21);
  addNECKey("Play", Play_Key, 0xAB, 0x22);
  addNECKey("Pause", Pause_Key, 0xAB, 0x23);
  addNECKey("SkipForw", Advance_Key, 0xAB, 0x24);
  addNECKey("SkipBack", Replay_Key, 0xAB, 0x25);
  addNECKey("TrackNext", Next_Key, 0xAB, 0x26);
  addNECKey("TrackPrev", Previous_Key, 0xAB, 0x27);
  addNECKey("Record", Record_Key, 0xAB, 0x28);

  addPioneerKey("CH+", ChannelUp_Key, 0xAB, 0x2A, 0xAF, 0x6E);
  addPioneerKey("CH-", ChannelDown_Key, 0xAB, 0x2A, 0xAF, 0x6F);

  addPioneerKey("Subtitle", Captions_Key, 0xAB, 0x2C, 0xAF, 0x36);
  addPioneerKey("Left", Left_Key, 0xAB, 0x2C, 0xAF, 0x63);
  addPioneerKey("Right", Right_Key, 0xAB, 0x2C, 0xAF, 0x64);
  addPioneerKey("Dot", Unmapped_Key, 0xAB, 0x2C, 0xAF, 0x66);
  addPioneerKey("0", Zero_Key, 0xAB, 0x2C, 0xAF, 0xA0);
  addPioneerKey("1", One_Key, 0xAB, 0x2C, 0xAF, 0xA1);
  addPioneerKey("2", Two_Key, 0xAB, 0x2C, 0xAF, 0xA2);
  addPioneerKey("3", Three_Key, 0xAB, 0x2C, 0xAF, 0xA3);
  addPioneerKey("4", Four_Key, 0xAB, 0x2C, 0xAF, 0xA4);
  addPioneerKey("5", Five_Key, 0xAB, 0x2C, 0xAF, 0xA5);
  addPioneerKey("6", Six_Key, 0xAB, 0x2C, 0xAF, 0xA6);
  addPioneerKey("7", Seven_Key, 0xAB, 0x2C, 0xAF, 0xA7);
  addPioneerKey("8", Eight_Key, 0xAB, 0x2C, 0xAF, 0xA8);
  addPioneerKey("9", Nine_Key, 0xAB, 0x2C, 0xAF, 0xA9);
  addPioneerKey("Guide", Guide_Key, 0xAB, 0x2C, 0xAF, 0xB0);
  addPioneerKey("TopMenu", DiscTitle_Key, 0xAB, 0x2C, 0xAF, 0xB4);
  addPioneerKey("Menu", DiscMenu_Key, 0xAB, 0x2C, 0xAF, 0xB9);
  addPioneerKey("Audio", Audio_Key, 0xAB, 0x2C, 0xAF, 0xBE);
  addPioneerKey("Enter", Enter_Key, 0xAB, 0x2C, 0xAF, 0xE5);
  addPioneerKey("OK", Select_Key, 0xAB, 0x2C, 0xAF, 0xEF);
  addPioneerKey("Up", Up_Key, 0xAB, 0x2C, 0xAF, 0xF2);
  addPioneerKey("Down", Down_Key, 0xAB, 0x2C, 0xAF, 0xF3);
  addPioneerKey("Return", Exit_Key, 0xAB, 0x2C, 0xAF, 0xF4);

  addNECKey("Green", Green_Key, 0xAF, 0x63);
  addNECKey("HDD", HDDInput_Key, 0xAF, 0x64);
  addNECKey("DVD", DVDInput_Key, 0xAF, 0x65);
}


PioneerAudio3::PioneerAudio3(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 3",
      Pioneer_Make,
      index)
{
  addControlledDevice(Pioneer_Make, "A-207R", Audio_Device);
  addControlledDevice(Pioneer_Make, "SX-302", Audio_Device);
  addControlledDevice(Pioneer_Make, "VSX-9300", Audio_Device);
}


void PioneerAudio3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new PioneerProtocol(guiObject, index);

  addNECKey("tape_deck1", Unmapped_Key, 0xA1, 0x0C);
  addNECKey("tape_deck2", Unmapped_Key, 0xA1, 0x0D);
  addNECKey("tape_ff", Unmapped_Key, 0xA1, 0x10);
  addNECKey("tape_rew", Unmapped_Key, 0xA1, 0x11);
  addNECKey("TAPE_REC_LEFT", Unmapped_Key, 0xA1, 0x12);
  addNECKey("tape_rec", Unmapped_Key, 0xA1, 0x14); // "TAPE_REC_RIGHT"
  addNECKey("tape_reverse", Unmapped_Key, 0xA1, 0x15); //"TAPE_PLAY_LEFT"
  addNECKey("tape_stop", Unmapped_Key, 0xA1, 0x16);
  addNECKey("tape_play", Unmapped_Key, 0xA1, 0x17); //"TAPE_PLAY_RIGHT"
  addNECKey("tape_pause", Unmapped_Key, 0xA1, 0x18);
  addNECKey("POWER_TAPE", Unmapped_Key, 0xA1, 0x1C);
  addNECKey("tape_tapeselect", Unmapped_Key, 0xA1, 0x4C);
  addNECKey("DISK1_TAPE_NEXT", Unmapped_Key, 0xA1, 0x56);
  addNECKey("DISK1_TAPE_PREV", Unmapped_Key, 0xA1, 0x57);
  addNECKey("DISK1_TAPE_PLAY_LEFT", Unmapped_Key, 0xA1, 0x5B);
  addNECKey("DISK1_TAPE_STOP", Unmapped_Key, 0xA1, 0x5C);
  addNECKey("DISK1_TAPE_PLAY_RIGHT", Unmapped_Key, 0xA1, 0x5D);

  addNECKey("CD_PGM", Program_Key, 0xA2, 0x0D);
  addNECKey("cd_next", Next_Key, 0xA2, 0x10);
  addNECKey("cd_previous", Previous_Key, 0xA2, 0x11);
  addNECKey("cd_stop", Stop_Key, 0xA2, 0x16);
  addNECKey("cd_play", Play_Key, 0xA2, 0x17);
  addNECKey("cd_pause", Pause_Key, 0xA2, 0x18);
  addNECKey("cd_power", Unmapped_Key, 0xA2, 0x1C);
  addNECKey("cd_discsel", NextDisc_Key, 0xA2, 0x1D); // "disc+"
  addNECKey("CD_TIME", Unmapped_Key, 0xA2, 0x43);
  addNECKey("CD_RND", Random_Key, 0xA2, 0x4A);
  addNECKey("CD_EDIT", Unmapped_Key, 0xA2, 0x4B);
  addNECKey("disc-", PrevDisc_Key, 0xA2, 0xC1);
  addNECKey("cdbest", Unmapped_Key, 0xA2, 0xC2);

  addNECKey("0", Zero_Key, 0xA4, 0x00);
  addNECKey("1", One_Key, 0xA4, 0x01);
  addNECKey("2", Two_Key, 0xA4, 0x02);
  addNECKey("3", Three_Key, 0xA4, 0x03);
  addNECKey("4", Four_Key, 0xA4, 0x04);
  addNECKey("5", Five_Key, 0xA4, 0x05);
  addNECKey("6", Six_Key, 0xA4, 0x06);
  addNECKey("7", Seven_Key, 0xA4, 0x07);
  addNECKey("8", Eight_Key, 0xA4, 0x08);
  addNECKey("9", Nine_Key, 0xA4, 0x09);
  addNECKey("fm", Unmapped_Key, 0xA4, 0x0D);
  addNECKey("am", Unmapped_Key, 0xA4, 0x0E);
  addNECKey("tuner_station+", NextPreset_Key, 0xA4, 0x10);
  addNECKey("tuner_station-", PrevPreset_Key, 0xA4, 0x11);
  addNECKey("tuner_band", AM_Key, 0xA4, 0x13); // This is a hack
  addNECKey("tuner_band", FM_Key, 0xA4, 0x13); // This too
  addNECKey("tuner_power", Unmapped_Key, 0xA4, 0x1C);
  addNECKey("mpx", Unmapped_Key, 0xA4, 0x1E); // Toggle mono FM
  addNECKey("tunerclass", Unmapped_Key, 0xA4, 0x40); // class A, B, C
  addNECKey("tunersearch", Unmapped_Key, 0xA4, 0x42);
  addNECKey("directaccess", Enter_Key, 0xA4, 0x43); // use to type in frequency values
  addNECKey("tunerdisplaymode", Info_Key, 0xA4, 0x4A);
  addNECKey("memory-scan", Scan_Key, 0xA4, 0x4D);
  addNECKey("hits", Unmapped_Key, 0xA4, 0x4E);
  addNECKey("freq-plus", ChannelUp_Key, 0xA4, 0x56);
  addNECKey("freq-minus", ChannelDown_Key, 0xA4, 0x57);

  addPioneerKey("effect/chsel-", Unmapped_Key, 0xA5, 0x07, 0xA5, 0x41);
  addPioneerKey("effect/chsel+", Unmapped_Key, 0xA5, 0x07, 0xA5, 0x42);
  addPioneerKey("digitalnr", Unmapped_Key, 0xA5, 0x07, 0xA5, 0x59);// noise reduction
  addPioneerKey("inputatt", Unmapped_Key, 0xA5, 0x07, 0xA5, 0x5E); // analog input attenuation

  addPioneerKey("direct", Unmapped_Key, 0xA5, 0x08, 0xA5, 0x5D); // DSP processing
  addPioneerKey("standard", Unmapped_Key, 0xA5, 0x08, 0xA5, 0x5E); // DD/DTS standard

  addNECKey("volume+", VolumeUp_Key, 0xA5, 0x0A);
  addNECKey("volume-", VolumeDown_Key, 0xA5, 0x0B);
  addNECKey("tv/sat", SatInput_Key, 0xA5, 0x0C);
  addNECKey("ld", LDInput_Key, 0xA5, 0x0D); // "VDP"
  addNECKey("vcr2", Unmapped_Key, 0xA5, 0x0E);
  addNECKey("vcr-line", VCRInput_Key, 0xA5, 0x0F);
  addNECKey("md/tape1", TapeInput_Key, 0xA5, 0x11);
  addNECKey("muting", Mute_Key, 0xA5, 0x12);
  addNECKey("video", Unmapped_Key, 0xA5, 0x16);
  addNECKey("poweron", PowerOn_Key, 0xA5, 0x1A);
  addNECKey("poweroff", PowerOff_Key, 0xA5, 0x1B);
  addNECKey("amp_power", Power_Key, 0xA5, 0x1C);
  addNECKey("tape2", Unmapped_Key, 0xA5, 0x1D);
  addNECKey("dsp", Unmapped_Key, 0xA5, 0x40); // cycle hall, jazz, dance, theater
  addNECKey("loudness", Unmapped_Key, 0xA5, 0x44);
  addNECKey("tuner", TunerInput_Key, 0xA5, 0x47);
  addNECKey("sleep", Sleep_Key, 0xA5, 0x48);
  addNECKey("cd", CDInput_Key, 0xA5, 0x4C);
  addNECKey("phono", PhonoInput_Key, 0xA5, 0x4D);
  addNECKey("dat/tape1", TapeInput_Key, 0xA5, 0x4E);
  addNECKey("line", LineInput_Key, 0xA5, 0x4F);
  addNECKey("muteon", Unmapped_Key, 0xA5, 0x51);
  addNECKey("muteoff", Unmapped_Key, 0xA5, 0x52);
  addNECKey("VSEL", Unmapped_Key, 0xAf, 0x54);
  addNECKey("input", Input_Key, 0xA5, 0x55); // cycle through all inputs!

  addPioneerKey("speakers", Unmapped_Key, 0xA5, 0x56, 0xA5, 0x00);
  addPioneerKey("signalselect", Unmapped_Key, 0xA5, 0x56, 0xA5, 0x03);
  addPioneerKey("effect/chsel", Unmapped_Key, 0xA5, 0x56, 0xA5, 0x04);
  addPioneerKey("dimmer", Unmapped_Key, 0xA5, 0x56, 0xA5, 0x06);

  addPioneerKey("bass+", BassUp_Key, 0xA5, 0x57, 0xA5, 0x00);
  addPioneerKey("bass-", BassDown_Key, 0xA5, 0x57, 0xA5, 0x01);
  addPioneerKey("treble+", TrebleUp_Key, 0xA5, 0x57, 0xA5, 0x02);
  addPioneerKey("treble-", TrebleDown_Key, 0xA5, 0x57, 0xA5, 0x03);

  addNECKey("up", Up_Key, 0xA5, 0x80);
  addNECKey("down", Down_Key, 0xA5, 0x81);
  addNECKey("right", Right_Key, 0xA5, 0x82);
  addNECKey("left", Left_Key, 0xA5, 0x83);
  addNECKey("enter", Select_Key, 0xA5, 0x84);
  addNECKey("dvd/ld", Unmapped_Key, 0xA5, 0x85);

  addPioneerKey("setup", Menu_Key, 0xA5, 0x9B, 0xA5, 0xD6);

  addPioneerKey("stereo", Unmapped_Key, 0xA5, 0x9F, 0xA5, 0xC0);
  addPioneerKey("midnight", Unmapped_Key, 0xA5, 0x9F, 0xA5, 0xCB);
  addPioneerKey("thx", Unmapped_Key, 0xA5, 0x9F, 0xA5, 0xD1);
  addPioneerKey("advanced", Unmapped_Key, 0xA5, 0x9F, 0xA5, 0xD3); // DD/DTS advanced

  addNECKey("ld_stop", Unmapped_Key, 0xA8, 0x16);
  addNECKey("ld_play", Unmapped_Key, 0xA8, 0x17);
  addNECKey("ld_pause", Unmapped_Key, 0xA8, 0x18);
  addNECKey("ld_power", Unmapped_Key, 0xA8, 0x1C);
  addNECKey("ld_display", Unmapped_Key, 0xA8, 0x43);
  addNECKey("ld_next", Unmapped_Key, 0xA8, 0x52);
  addNECKey("ld_previous", Unmapped_Key, 0xA8, 0x53);

  addNECKey("tv_channel+", Unmapped_Key, 0xAA, 0x10);
  addNECKey("tv_channel-", Unmapped_Key, 0xAA, 0x11);
  addNECKey("tv_func", Unmapped_Key, 0xAA, 0x13);
  addNECKey("tv_power", Unmapped_Key, 0xAA, 0x1C);

  addNECKey("vcr_tv-vcr", Unmapped_Key, 0xAB, 0x0F);
  addNECKey("vcr_ff", Unmapped_Key, 0xAB, 0x10);
  addNECKey("vcr_rew", Unmapped_Key, 0xAB, 0x11);
  addNECKey("vcr_stop", Unmapped_Key, 0xAB, 0x16);
  addNECKey("vcr_play", Unmapped_Key, 0xAB, 0x17);
  addNECKey("vcr_pause", Unmapped_Key, 0xAB, 0x18);
  addNECKey("vcr_channel+", Unmapped_Key, 0xAB, 0x52);
  addNECKey("vcr_channel-", Unmapped_Key, 0xAB, 0x53);
}


PioneerAudio4::PioneerAudio4(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 4",
      Pioneer_Make,
      index)
{
}


void PioneerAudio4::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new PioneerProtocol(guiObject, index);

  addNECKey("tapesel", Unmapped_Key, 0xA1, 0x4C);
  addNECKey(">>", FastForward_Key, 0xA1, 0x56);
  addNECKey("<<", Rewind_Key, 0xA1, 0x57);
  addNECKey("<", Unmapped_Key, 0xA1, 0x5B);
  addNECKey("square", Unmapped_Key, 0xA1, 0x5C);
  addNECKey(">", Unmapped_Key, 0xA1, 0x5D);

  addNECKey(">>|", Next_Key, 0xA2, 0x10);
  addNECKey("|<<", Previous_Key, 0xA2, 0x11);
  addNECKey("squarecd", Stop_Key, 0xA2, 0x16);
  addNECKey(">cd", Play_Key, 0xA2, 0x17);
  addNECKey("cdpower", Unmapped_Key, 0xA2, 0x1C);
  addNECKey("discsel", NextDisc_Key, 0xA2, 0x65);

  addNECKey("tuner+", ChannelUp_Key, 0xA4, 0x10);
  addNECKey("tuner-", ChannelDown_Key, 0xA4, 0x11);
  addNECKey("tunerpower", Unmapped_Key, 0xA4, 0x1C);

  addNECKey("vol+", VolumeUp_Key, 0xA5, 0x0A);
  addNECKey("vol-", VolumeDown_Key, 0xA5, 0x0B);
  addNECKey("amppower", Power_Key, 0xA5, 0x1C);
  addNECKey("tape2", Unmapped_Key, 0xA5, 0x1D);
  addNECKey("function", Unmapped_Key, 0xA5, 0x55);
}


PioneerAudio5::PioneerAudio5(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 5",
      Pioneer_Make,
      index)
{
  addControlledDevice(Pioneer_Make, "XR-P240C", Audio_Device);
}


void PioneerAudio5::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  LIRCProtocol *lp = new LIRCProtocol(
    guiObject,
    index,
    560, 560,
    560, 1680,
    110000, true);

  threadableProtocol = lp;

  lp->setHeaderPair(9000, 4500);
  lp->setTrailerPulse(560);
  lp->setRepeatPair(9000, 4500);

  setPreData(0x10217EF, 26);

  addKey("POWER", Power_Key, 0x9867, 16);
  addKey("MONO", FMMode_Key, 0x48B7, 16);
  addKey("MEM_SCAN", Unmapped_Key, 0x8877, 16);
  addKey("TUNER_BAND", AM_Key, 0x18E7, 16);  // This is a hack
  addKey("TUNER_BAND", FM_Key, 0x18E7, 16);  // This too
  addKey("1", One_Key, 0x00FF, 16);
  addKey("2", Two_Key, 0x807F, 16);
  addKey("3", Three_Key, 0x40BF, 16);
  addKey("4", Four_Key, 0xC03F, 16);
  addKey("5", Five_Key, 0x20DF, 16);
  addKey("6", Six_Key, 0xA05F, 16);
  addKey("7", Seven_Key, 0x609F, 16);
  addKey("8", Eight_Key, 0xE01F, 16);
  addKey("SCAN", Scan_Key, 0xB44B, 16);
  addKey("REPEAT", Repeat_Key, 0x847B, 16);
  addKey("DISC", NextDisc_Key, 0xE41B, 16);
  addKey("CLEAR", Clear_Key, 0x34CB, 16);
  addKey("PROGRAM", Program_Key, 0x44BB, 16);
  addKey("CD_PREV", Previous_Key, 0x2CD3, 16);
  addKey("CD_NEXT", Next_Key, 0x6C93, 16);
  addKey("TIME", Unmapped_Key, 0x04FB, 16);
  addKey("RANDOM", Random_Key, 0xC43B, 16);
  addKey("CD_STOP", Stop_Key, 0xF40B, 16);
  addKey("CD_PLAY_PAUSE", Play_Key, 0xD42B, 16);
  addKey("CD_PLAY_PAUSE", Pause_Key, 0xD42B, 16);
  addKey("VOLUME_PLUS", VolumeUp_Key, 0x708F, 16);
  addKey("VOLUME_MINUS", VolumeDown_Key, 0xF00F, 16);
  addKey("POWER_BASS", EnhancedBass_Key, 0xD02F, 16);
  addKey("MUTE", Mute_Key, 0xE817, 16);
  addKey("TAPE", TapeInput_Key, 0x7887, 16);
  addKey("AUX_VIDEO", AuxInput_Key, 0xF807, 16);
  addKey("TUNER", TunerInput_Key, 0xD827, 16);
  addKey("CD", CDInput_Key, 0x38C7, 16);
}


PioneerCD1::PioneerCD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "CD Keyset 1",
      Pioneer_Make,
      index)
{
  addControlledDevice(Pioneer_Make, "PD-106", Audio_Device);
  addControlledDevice(Pioneer_Make, "PD-202", Audio_Device);
  addControlledDevice(Pioneer_Make, "PD-4550", Audio_Device);
  addControlledDevice(Pioneer_Make, "PD-F957", Audio_Device);
  addControlledDevice(Pioneer_Make, "PD-M107", Audio_Device);
  addControlledDevice(Pioneer_Make, "PD-S503", Audio_Device);
  addControlledDevice(Pioneer_Make, "PD-F1007", Audio_Device);
}


void PioneerCD1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new PioneerProtocol(guiObject, index);

  addNECKey("0", Zero_Key, 0xA2, 0x00);
  addNECKey("1", One_Key, 0xA2, 0x01);
  addNECKey("2", Two_Key, 0xA2, 0x02);
  addNECKey("3", Three_Key, 0xA2, 0x03);
  addNECKey("4", Four_Key, 0xA2, 0x04);
  addNECKey("5", Five_Key, 0xA2, 0x05);
  addNECKey("6", Six_Key, 0xA2, 0x06);
  addNECKey("7", Seven_Key, 0xA2, 0x07);
  addNECKey("8", Eight_Key, 0xA2, 0x08);
  addNECKey("9", Nine_Key, 0xA2, 0x09);
  addNECKey("VOL+", VolumeUp_Key, 0xA2, 0x0A);
  addNECKey("VOL-", VolumeDown_Key, 0xA2, 0x0B);
  addNECKey("REPEAT", Repeat_Key, 0xA2, 0x0C);
  addNECKey("PROGRAMMEMORY", Program_Key, 0xA2, 0x0D); // "PROG"
  addNECKey("forw", FastForward_Key, 0xA2, 0x0E); // "FF"
  addNECKey("back", Rewind_Key, 0xA2, 0x0F); // "REW"

  addNECKey("skip_forw", Next_Key, 0xA2, 0x10);
  addNECKey("skip_back", Previous_Key, 0xA2, 0x11);
  addNECKey("stop", Stop_Key, 0xA2, 0x16);
  addNECKey("play", Play_Key, 0xA2, 0x17);
  addNECKey("pause", Pause_Key, 0xA2, 0x18);
  addNECKey("power", Power_Key, 0xA2, 0x1C);
  addNECKey("disc+", NextDisc_Key, 0xA2, 0x1D);
  addNECKey("disc_1", Unmapped_Key, 0xA2, 0x1E);
  addNECKey("disc_2", Unmapped_Key, 0xA2, 0x1F);

  addNECKey("set_track", Unmapped_Key, 0xA2, 0x40);
  addNECKey("menu", Menu_Key, 0xA2, 0x41);  // "set_disc"
  addNECKey("TIME", Unmapped_Key, 0xA2, 0x43);
  addNECKey("CLEAR", Clear_Key, 0xA2, 0x45);
  addNECKey("check", Unmapped_Key, 0xA2, 0x49);
  addNECKey("RANDOM", Random_Key, 0xA2, 0x4A);
  addNECKey("AUTOPGM", Unmapped_Key, 0xA2, 0x4B); // "EDIT"
  addNECKey("MUSICWINDOW", Unmapped_Key, 0xA2, 0x4D);
  addNECKey("FADEIN", Unmapped_Key, 0xA2, 0x4E);
  addNECKey("FADEOUT", Unmapped_Key, 0xA2, 0x4F);
  addNECKey("disc_3", Unmapped_Key, 0xA2, 0x50);
  addNECKey("OPEN/CLOSE", Eject_Key, 0xA2, 0x51);
  addNECKey("+10", Unmapped_Key, 0xA2, 0x52);
  addNECKey("disc_4", Unmapped_Key, 0xA2, 0x53);
  addNECKey("NEXTINDEX", Unmapped_Key, 0xA2, 0x54);
  addNECKey("PREVINDEX", Unmapped_Key, 0xA2, 0x55);
  addNECKey(">=20", DoubleDigit_Key, 0xA2, 0x56);
  addNECKey("disc_5", Unmapped_Key, 0xA2, 0x57);
  addNECKey("TIMEFADE", Unmapped_Key, 0xA2, 0x5A);
  addNECKey("disc_6", Unmapped_Key, 0xA2, 0x5B);
  addNECKey("delete", Unmapped_Key, 0xA2, 0x5D);
  addNECKey("HI-LITE", Unmapped_Key, 0xA2, 0x5E); // "hi-lite_scan"

  addPioneerKey("20", Unmapped_Key, 0xA2, 0xC0, 0xA2, 0x80);
  addPioneerKey("11", Unmapped_Key, 0xA2, 0xC0, 0xA2, 0x81);
  addPioneerKey("12", Unmapped_Key, 0xA2, 0xC0, 0xA2, 0x82);
  addPioneerKey("13", Unmapped_Key, 0xA2, 0xC0, 0xA2, 0x83);
  addPioneerKey("14", Unmapped_Key, 0xA2, 0xC0, 0xA2, 0x84);
  addPioneerKey("15", Unmapped_Key, 0xA2, 0xC0, 0xA2, 0x85);
  addPioneerKey("16", Unmapped_Key, 0xA2, 0xC0, 0xA2, 0x86);
  addPioneerKey("17", Unmapped_Key, 0xA2, 0xC0, 0xA2, 0x87);
  addPioneerKey("18", Unmapped_Key, 0xA2, 0xC0, 0xA2, 0x88);
  addPioneerKey("19", Unmapped_Key, 0xA2, 0xC0, 0xA2, 0x89);

  addPioneerKey("disc-", PrevDisc_Key, 0xA2, 0xC1, 0xA2, 0x93);
  addPioneerKey("TITLE_INPUT", Unmapped_Key, 0xA2, 0xC1, 0xA2, 0x95);
  addPioneerKey("mode", Unmapped_Key, 0xA2, 0xC1, 0xA2, 0x9C);

  addPioneerKey("TITLE_DISPLAY", Info_Key, 0xA2, 0xC2, 0xA2, 0x94);
  addPioneerKey("search", Unmapped_Key, 0xA2, 0xC2, 0xA2, 0x95);
  addPioneerKey("BEST", Unmapped_Key, 0xA2, 0xC2, 0xA2, 0x9B);

  addPioneerKey("previous", Unmapped_Key, 0xA2, 0xC6, 0xA2, 0x93);
  addPioneerKey("CURSOR_right", Right_Key, 0xA2, 0xC6, 0xA2, 0x9B);
  addPioneerKey("CURSOR_left", Left_Key, 0xA2, 0xC6, 0xA2, 0x9C);
}


PioneerLaserDisc1::PioneerLaserDisc1(
  unsigned int index)
  : PIRKeysetMetaData(
      "LD Keyset 1",
      Pioneer_Make,
      index)
{
  addControlledDevice(Pioneer_Make, "CLD-D925", Other_Device);
}


void PioneerLaserDisc1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new PioneerProtocol(guiObject, index);

  addNECKey("0", Zero_Key, 0xA8, 0x00);
  addNECKey("1", One_Key, 0xA8, 0x01);
  addNECKey("2", Two_Key, 0xA8, 0x02);
  addNECKey("3", Three_Key, 0xA8, 0x03);
  addNECKey("4", Four_Key, 0xA8, 0x04);
  addNECKey("5", Five_Key, 0xA8, 0x05);
  addNECKey("6", Six_Key, 0xA8, 0x06);
  addNECKey("7", Seven_Key, 0xA8, 0x07);
  addNECKey("8", Eight_Key, 0xA8, 0x08);
  addNECKey("9", Nine_Key, 0xA8, 0x09);

  addNECKey("dacx", Unmapped_Key, 0xA8, 0x0C);
  addNECKey("ff", FastForward_Key, 0xA8, 0x10);
  addNECKey("rew", Rewind_Key, 0xA8, 0x11); // "scan-"
  addNECKey("chp/tm", Unmapped_Key, 0xA8, 0x13);
//  addNECKey("eject", Eject_Key, 0xA8, 0x16); // ?
  addNECKey("stop", Stop_Key, 0xA8, 0x16);
  addNECKey("play", Play_Key, 0xA8, 0x17);
  addNECKey("pause", Pause_Key, 0xA8, 0x18);
  addNECKey("memory", Memory_Key, 0xA8, 0x19);
  addNECKey("power", Power_Key, 0xA8, 0x1C);
  addNECKey("audio", Audio_Key, 0xA8, 0x1E); // "Audio_D/A"
  addNECKey("+10", DoubleDigit_Key, 0xA8, 0x1F);
  addNECKey("Jog_slow->", Unmapped_Key, 0xA8, 0x20);
  addNECKey("Jog_slow<-", Unmapped_Key, 0xA8, 0x22);
  addNECKey("Jog_Forward", Unmapped_Key, 0xA8, 0x2B);
  addNECKey("Jog_Reverse", Unmapped_Key, 0xA8, 0x2F);
  addNECKey("ctrl", Unmapped_Key, 0xA8, 0x37);
  addNECKey("display", Info_Key, 0xA8, 0x43);
  addNECKey("repeat", Repeat_Key, 0xA8, 0x44);
  addNECKey("clear", Clear_Key, 0xA8, 0x45);
  addNECKey("-", Unmapped_Key, 0xA8, 0x46);
  addNECKey("+", Unmapped_Key, 0xA8, 0x47);
  addNECKey("repeatab", RepeatAB_Key, 0xA8, 0x48);
  addNECKey("pgm", Program_Key, 0xA8, 0x4C);
  addNECKey("Disc_Side_A", Unmapped_Key, 0xA8, 0x4D);
  addNECKey("Disc_Side_B", Unmapped_Key, 0xA8, 0x4E);
  addNECKey("step-", StepBack_Key, 0xA8, 0x50);
  addNECKey("skip+", Next_Key, 0xA8, 0x52);  // "seek+"
  addNECKey("skip-", Previous_Key, 0xA8, 0x53); // "seek-"
  addNECKey("step+", StepForward_Key, 0xA8, 0x54);
  addNECKey("speed-", SlowMinus_Key, 0xA8, 0x55);
  addNECKey("speed+", SlowPlus_Key, 0xA8, 0x58);
  addNECKey("intro", Unmapped_Key, 0xA8, 0x5A);
  addNECKey("random", Random_Key, 0xA8, 0x5E);
}


PioneerDVD1::PioneerDVD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Pioneer_Make,
      index)
{
  addControlledDevice(Pioneer_Make, "VXX2702", DVD_Device);
  addControlledDevice(Pioneer_Make, "VXX2801", DVD_Device);
}


void PioneerDVD1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new PioneerProtocol(guiObject, index);

  addNECKey("STOP", Stop_Key, 0xA3, 0x98);
  addNECKey("NEXT", Next_Key, 0xA3, 0x9C);
  addNECKey("PREV", Previous_Key, 0xA3, 0x9D);
  addNECKey("PLAY", Play_Key, 0xA3, 0x9E);
  addNECKey("PAUSE", Pause_Key, 0xA3, 0x9F);

  addPioneerKey("SUBTITLE", Captions_Key, 0xA3, 0x99, 0xAF, 0x36);
  addPioneerKey("ZOOM", Zoom_Key, 0xA3, 0x99, 0xAF, 0x37);
  addPioneerKey("SURROUND", Surround_Key, 0xA3, 0x99, 0xAF, 0x61);
  addPioneerKey("LEFT", Left_Key, 0xA3, 0x99, 0xAF, 0x63);
  addPioneerKey("RIGHT", Right_Key, 0xA3, 0x99, 0xAF, 0x64);
  addPioneerKey("PLAY_MODE", Unmapped_Key, 0xA3, 0x99, 0xAF, 0x7F);
  addPioneerKey("0", Zero_Key, 0xA3, 0x99, 0xAF, 0xA0);
  addPioneerKey("1", One_Key, 0xA3, 0x99, 0xAF, 0xA1);
  addPioneerKey("2", Two_Key, 0xA3, 0x99, 0xAF, 0xA2);
  addPioneerKey("3", Three_Key, 0xA3, 0x99, 0xAF, 0xA3);
  addPioneerKey("4", Four_Key, 0xA3, 0x99, 0xAF, 0xA4);
  addPioneerKey("5", Five_Key, 0xA3, 0x99, 0xAF, 0xA5);
  addPioneerKey("6", Six_Key, 0xA3, 0x99, 0xAF, 0xA6);
  addPioneerKey("7", Seven_Key, 0xA3, 0x99, 0xAF, 0xA7);
  addPioneerKey("8", Eight_Key, 0xA3, 0x99, 0xAF, 0xA8);
  addPioneerKey("9", Nine_Key, 0xA3, 0x99, 0xAF, 0xA9);
  addPioneerKey("SETUP", Menu_Key, 0xA3, 0x99, 0xAF, 0xB0);
  addPioneerKey("TOP_MENU", DiscTitle_Key, 0xA3, 0x99, 0xAF, 0xB4);
  addPioneerKey("ANGLE", Angle_Key, 0xA3, 0x99, 0xAF, 0xB5);
  addPioneerKey("OPEN/CLOSE", Eject_Key, 0xA3, 0x99, 0xAF, 0xB6);
  addPioneerKey("MENU", DiscMenu_Key, 0xA3, 0x99, 0xAF, 0xB9);
  addPioneerKey("AUDIO", Audio_Key, 0xA3, 0x99, 0xAF, 0xBE);
  addPioneerKey("STANDBY/ON", Power_Key, 0xA3, 0x99, 0xAF, 0xBC);
  addPioneerKey("DISPLAY", Info_Key, 0xA3, 0x99, 0xAF, 0xE3);
  addPioneerKey("CLEAR", Clear_Key, 0xA3, 0x99, 0xAF, 0xE5);
  addPioneerKey("FWD", FastForward_Key, 0xA3, 0x99, 0xAF, 0xE9);
  addPioneerKey("BWD", Rewind_Key, 0xA3, 0x99, 0xAF, 0xEA);
  addPioneerKey("ENTER", Enter_Key, 0xA3, 0x99, 0xAF, 0xEF);
  addPioneerKey("ENTER", Select_Key, 0xA3, 0x99, 0xAF, 0xEF);
  addPioneerKey("UP", Up_Key, 0xA3, 0x99, 0xAF, 0xF2);
  addPioneerKey("DOWN", Down_Key, 0xA3, 0x99, 0xAF, 0xF3);
  addPioneerKey("RETURN", Exit_Key, 0xA3, 0x99, 0xAF, 0xF4);
}
