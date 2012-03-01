#include "harmankardon.h"
#include "protocols/necprotocol.h"


HarmanKardonAmp1::HarmanKardonAmp1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Amp/Receiver Component 1",
      HarmanKardon_Make,
      index)
{
}


void HarmanKardonAmp1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x7080, 16);

  addKey("CD_STOP", Stop_Key, 0x01, 8);
  addKey("CD_PLAY", Play_Key, 0x02, 8);
  addKey("CD_PAUSE", Pause_Key, 0x03, 8);
  addKey("CD_NEXT", Next_Key, 0x04, 8);
  addKey("CD_PREV", Previous_Key, 0x05, 8);
  addKey("CD_FWD", FastForward_Key, 0x06, 8);
  addKey("CD_BKW", Rewind_Key, 0x07, 8);
  addKey("CD_AB", RepeatAB_Key, 0x0B, 8);
  addKey("CD_INTRO", Unmapped_Key, 0x0D, 8);

  addKey("CD_DISC", NextDisc_Key, 0x50, 8);

  addKey("FM", TunerBand_Key, 0x81, 8); // "am/fm"
  addKey("AM", Unmapped_Key, 0x82, 8);
  addKey("TUNEUP", ChannelUp_Key, 0x84, 8);
  addKey("TUNEDN", ChannelDown_Key, 0x85, 8);
  addKey("mem", Memory_Key, 0x86, 8);
  addKey("1", One_Key, 0x87, 8);
  addKey("2", Two_Key, 0x88, 8);
  addKey("3", Three_Key, 0x89, 8);
  addKey("4", Four_Key, 0x8A, 8);
  addKey("5", Five_Key, 0x8B, 8);
  addKey("6", Six_Key, 0x8C, 8);
  addKey("7", Seven_Key, 0x8D, 8);
  addKey("8", Eight_Key, 0x8E, 8);
  addKey("shift", Unmapped_Key, 0x8F, 8);

  addKey("seek-st", Unmapped_Key, 0x91, 8);
  addKey("tun-m", Unmapped_Key, 0x93, 8);
  addKey("PSCAN", Scan_Key, 0x96, 8);
  addKey("direct", Unmapped_Key, 0x9B, 8);
  addKey("9", Nine_Key, 0x9D, 8);
  addKey("0", Zero_Key, 0x9E, 8);
  addKey("pow_off", PowerOff_Key, 0x9F, 8);

  addKey("STANDBY", Power_Key, 0xC0, 8); // "pow_on"
  addKey("MUTE", Mute_Key, 0xC1, 8);
  addKey("Phono", PhonoInput_Key, 0xC2, 8);
  addKey("TUNER", TunerInput_Key, 0xC3, 8);
  addKey("CD", CDInput_Key, 0xC4, 8);
  addKey("video", Unmapped_Key, 0xC6, 8);
  addKey("VOLUP", VolumeUp_Key, 0xC7, 8);
  addKey("VOLDN", VolumeDown_Key, 0xC8, 8);
  addKey("VCR1", VCRInput_Key, 0xCA, 8);
  addKey("VCR2", Unmapped_Key, 0xCB, 8);
  addKey("source_tape", TapeInput_Key, 0xCC, 8);
  addKey("TAPEMON", Unmapped_Key, 0xCD, 8); // "Tape2"
  addKey("TVAUX", AuxInput_Key, 0xCE, 8);

  addKey("source_dvd", DVDInput_Key, 0xD0, 8);
  addKey("source_vid4", Unmapped_Key, 0xD1, 8);
  addKey("aux2", Unmapped_Key, 0xD5, 8);
  addKey("S_REARUP", RearVolumeUp_Key, 0xD7, 8);
  addKey("S_REARDN", RearVolumeDown_Key, 0xD8, 8);
  addKey("S_CNTUP", CenterVolumeUp_Key, 0xD9, 8);
  addKey("S_CNTDN", CenterVolumeDown_Key, 0xDA, 8);
  addKey("SLEEP", Sleep_Key, 0xDB, 8);
  addKey("DISPLAY", Info_Key, 0xDC, 8);
}


HarmanKardonAmp2::HarmanKardonAmp2(
  unsigned int index)
  : PIRKeysetMetaData(
      "Amp Component 2",
      HarmanKardon_Make,
      index)
{
}


void HarmanKardonAmp2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x7686, 16);

  addKey("on", PowerOn_Key, 0x40, 8);
  addKey("off", PowerOff_Key, 0x41, 8);
  addKey("speaker1", Unmapped_Key, 0x42, 8);
  addKey("speaker2", Unmapped_Key, 0x43, 8);
  addKey("phono", PhonoInput_Key, 0x44, 8);
  addKey("cd", CDInput_Key, 0x48, 8);
  addKey("vid1", Unmapped_Key, 0x4B, 8);
  addKey("vid2", Unmapped_Key, 0x4C, 8);
  addKey("vid3", Unmapped_Key, 0x4D, 8);
  addKey("fm", Unmapped_Key, 0x46, 8);
  addKey("am", Unmapped_Key, 0x45, 8);
  addKey("tapemon", Unmapped_Key, 0x4A, 8);
  addKey("vol+", VolumeUp_Key, 0x54, 8);
  addKey("vol-", VolumeDown_Key, 0x53, 8);
  addKey("mute", Mute_Key, 0x5A, 8);
  addKey("dimmer", Unmapped_Key, 0x5C, 8);
  addKey("sleep", Sleep_Key, 0x5B, 8);
}


HarmanKardonReceiver2::HarmanKardonReceiver2(
  unsigned int index)
  : PIRKeysetMetaData(
      "Receiver Component 2",
      HarmanKardon_Make,
      index)
{
}


void HarmanKardonReceiver2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x7080, 16);

  addKey("fm_mode", FMMode_Key, 0x3C, 8);
  addKey("auto_preset", Unmapped_Key, 0x61, 8);
  addKey("1", One_Key, 0x31, 8);
  addKey("2", Two_Key, 0x32, 8);
  addKey("3", Three_Key, 0x33, 8);
  addKey("4", Four_Key, 0x34, 8);
  addKey("5", Five_Key, 0x35, 8);
  addKey("6", Six_Key, 0x36, 8);
  addKey("7", Seven_Key, 0x37, 8);
  addKey("8", Eight_Key, 0x38, 8);
  addKey("9", Nine_Key, 0x39, 8);
  addKey("direct", Unmapped_Key, 0x6A, 8);
  addKey("0", Zero_Key, 0x30, 8);
  addKey("clear", Clear_Key, 0x2F, 8);
  addKey("memory", Memory_Key, 0x2E, 8);
  addKey("up", Up_Key, 0x28, 8);
  addKey("left", Left_Key, 0x3F, 8);
  addKey("ok", Select_Key, 0x6D, 8);
  addKey("right", Right_Key, 0x3E, 8);
  addKey("down", Down_Key, 0x29, 8);
  addKey("preset_scan", Scan_Key, 0x2D, 8);
  addKey("tune_up", ChannelUp_Key, 0x76, 8);
  addKey("tune_down", ChannelDown_Key, 0x77, 8);
  addKey("prev", Previous_Key, 0x25, 8);
  addKey("pause", Pause_Key, 0x23, 8);
  addKey("next", Next_Key, 0x24, 8);
  addKey("rev", Rewind_Key, 0x27, 8);
  addKey("play", Play_Key, 0x22, 8);
  addKey("ffw", FastForward_Key, 0x26, 8);
  addKey("rec", Record_Key, 0x60, 8);
  addKey("stop", Stop_Key, 0x21, 8);
}


HarmanKardonTape1::HarmanKardonTape1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Tape Component 1",
      HarmanKardon_Make,
      index)
{
}


void HarmanKardonTape1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated:
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x7282, 16);

  addKey("C_NEXT", Next_Key, 0x01, 8);
  addKey("C_PREV", Previous_Key, 0x02, 8);
  addKey("C_STOP", Stop_Key, 0x03, 8);
  addKey("C_FWD", FastForward_Key, 0x04, 8);
  addKey("C_BKW", Rewind_Key, 0x05, 8);
//  addKey("C_REC", Record_Key, 0x06, 8);
  addKey("CassDeckPause", Pause_Key, 0x06, 8);

  addKey("C_SELECT", Select_Key, 0x1D, 8);

  addKey("dolby", NoiseReduction_Key, 0x50, 8);
  addKey("delay", Unmapped_Key, 0x52, 8);
  addKey("spkr", Unmapped_Key, 0x53, 8);
  addKey("digital", Unmapped_Key, 0x54, 8);
  addKey("surr", Surround_Key, 0x58, 8);
  addKey("osd", Info_Key, 0x5C, 8);
  addKey("ch", Unmapped_Key, 0x5D, 8);

  addKey("set", Select_Key, 0x84, 8);
  addKey("S_OFF", Unmapped_Key, 0x89, 8);
//  addKey("S_DELAY", Unmapped_Key, 0x8A, 8);
  addKey("^", Up_Key, 0x8A, 8);
  addKey("v", Down_Key, 0x8B, 8);
  addKey("S_TEST", Unmapped_Key, 0x8C, 8);
  addKey("S_CNTMODE", Unmapped_Key, 0x8D, 8);
  addKey("Theater", Unmapped_Key, 0x92, 8);
  addKey("Stadium", Unmapped_Key, 0x94, 8);
  addKey("night", Unmapped_Key, 0x96, 8);
  addKey("stereo", Unmapped_Key, 0x9B, 8);
  addKey("S_3STEREO", Unmapped_Key, 0x9D, 8);
  addKey("S_PROLOGIC", Unmapped_Key, 0x9F, 8);

  addKey("dts_surr", Unmapped_Key, 0xA0, 8);
  addKey("dts_neo:6", Unmapped_Key, 0xA1, 8);
  addKey("<", Left_Key, 0xC1, 8);
  addKey(">", Right_Key, 0xC2, 8);
  addKey("preset+", ChannelUp_Key, 0xD0, 8);
  addKey("preset-", ChannelDown_Key, 0xD1, 8);
  addKey("clear", Clear_Key, 0xD9, 8);
  addKey("logic_7", Unmapped_Key, 0xDA, 8);
  addKey("source_6/8ch", Unmapped_Key, 0xDB, 8);
  addKey("d.skip", NextDisc_Key, 0xDD, 8);
  addKey("mroom", Unmapped_Key, 0xDF, 8);
}


HarmanKardonDVD1::HarmanKardonDVD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      HarmanKardon_Make,
      index)
{
}


void HarmanKardonDVD1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x7282, 16);

  addKey("Open/Close", Eject_Key, 0x20, 8);
  addKey("ON", PowerOn_Key, 0x21, 8);
  addKey("OFF", PowerOff_Key, 0x22, 8);
  addKey("Title", DiscTitle_Key, 0x23, 8);
  addKey("Menu", DiscMenu_Key, 0x24, 8);
  addKey("Return", Exit_Key, 0x25, 8);
  addKey("Up", Up_Key, 0x26, 8);
  addKey("Down", Down_Key, 0x27, 8);
  addKey("Left", Left_Key, 0x28, 8);
  addKey("Right", Right_Key, 0x29, 8);
  addKey("Enter", Select_Key, 0x2A, 8);
  addKey("Play", Play_Key, 0x2B, 8);
  addKey("Pause", Pause_Key, 0x2C, 8);
  addKey("Stop", Stop_Key, 0x2D, 8);
  addKey("SearchBack", Rewind_Key, 0x2E, 8);
  addKey("SearchForward", FastForward_Key, 0x2F, 8);

  addKey("Prev.", Previous_Key, 0x30, 8);
  addKey("Next", Next_Key, 0x31, 8);
  addKey("Subtitle", Unmapped_Key, 0x33, 8);
  addKey("SubtitleON/OFF", Captions_Key, 0x34, 8);
  addKey("Audio", Audio_Key, 0x35, 8);
  addKey("Angle", Angle_Key, 0x36, 8);
  addKey("Status", Info_Key, 0x39, 8);
  addKey("SlowBack", SlowMinus_Key, 0x3A, 8);
  addKey("SlowForward", SlowPlus_Key, 0x3B, 8);
  addKey("StepBack", StepBack_Key, 0x3C, 8);
  addKey("StepForward", StepForward_Key, 0x3D, 8);
  addKey("Zoom", Zoom_Key, 0x3E, 8);

  addKey("0", Zero_Key, 0x60, 8);
  addKey("1", One_Key, 0x61, 8);
  addKey("2", Two_Key, 0x62, 8);
  addKey("3", Three_Key, 0x63, 8);
  addKey("4", Four_Key, 0x64, 8);
  addKey("5", Five_Key, 0x65, 8);
  addKey("6", Six_Key, 0x66, 8);
  addKey("7", Seven_Key, 0x67, 8);
  addKey("8", Eight_Key, 0x68, 8);
  addKey("9", Nine_Key, 0x69, 8);
  addKey("Prog.", Program_Key, 0x6A, 8);
  addKey("Check", Unmapped_Key, 0x6B, 8);
  addKey("Clear", Clear_Key, 0x6C, 8);
  addKey("Random", Random_Key, 0x6D, 8);
  addKey("Repeat", Repeat_Key, 0x6E, 8);
  addKey("A-B", RepeatAB_Key, 0x6F, 8);

  addKey("Playlist", Unmapped_Key, 0xB0, 8);
}


HarmanKardonDVD1a::HarmanKardonDVD1a(
  unsigned int index)
  : HarmanKardonDVD1(index)
{
  setKeysetName("DVD Keyset 1a");
}


void HarmanKardonDVD1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  HarmanKardonDVD1::populateProtocol(guiObject);

  addKey("OSD", Unmapped_Key, 0x24, 8);
  addKey("Subtitle", Captions_Key, 0x33, 8);
  addKey("Disc/Menu", DiscMenu_Key, 0x4C, 8);
  addKey("Info", Info_Key, 0x4D, 8);
  addKey("V.Off", Unmapped_Key, 0x4E, 8);
  addKey("Display", Unmapped_Key, 0xB3, 8);
  addKey("Pic+", Unmapped_Key, 0xB4, 8);
  addKey("Pic-", Unmapped_Key, 0xB5, 8);
}


HarmanKardonCD1::HarmanKardonCD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "CD Keyset 1",
      HarmanKardon_Make,
      index)
{
}


void HarmanKardonCD1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x4A83, 16);

  addKey("1", One_Key, 0x1C, 8);
  addKey("2", Two_Key, 0x1D, 8);
  addKey("3", Three_Key, 0x1E, 8);
  addKey("4", Four_Key, 0x1F, 8);
  addKey("5", Five_Key, 0x18, 8);
  addKey("6", Six_Key, 0x19, 8);
  addKey("7", Seven_Key, 0x1A, 8);
  addKey("8", Eight_Key, 0x1B, 8);
  addKey("9", Nine_Key, 0x14, 8);
  addKey("0", Zero_Key, 0x15, 8);
  addKey("intro", Unmapped_Key, 0x10, 8);
  addKey("prog/rev", Program_Key, 0x16, 8);
  addKey("tape_size", Unmapped_Key, 0x17, 8);
  addKey("edit", Unmapped_Key, 0x0E, 8);
  addKey("repeat_1/all", Repeat_Key, 0x0C, 8);
  addKey("repeat_a/b", RepeatAB_Key, 0x0D, 8);
  addKey("random", Random_Key, 0x11, 8);
  addKey("delete", Unmapped_Key, 0x0A, 8);
  addKey("display", Info_Key, 0x12, 8);
  addKey("time", Unmapped_Key, 0x0F, 8);
  addKey("skip_backward", Previous_Key, 0x04, 8);
  addKey("skip_forward", Next_Key, 0x05, 8);
  addKey("pause", Pause_Key, 0x07, 8);
  addKey("stop", Stop_Key, 0x0B, 8);
  addKey("fast_backward", Rewind_Key, 0x00, 8);
  addKey("fast_forward", FastForward_Key, 0x01, 8);
  addKey("play", Play_Key, 0x03, 8);
}


HarmanKardonCD2::HarmanKardonCD2(
  unsigned int index)
  : PIRKeysetMetaData(
      "CD Keyset 2",
      HarmanKardon_Make,
      index)
{
}


void HarmanKardonCD2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x7080, 16);

  addKey("stop", Stop_Key, 0x01, 8);
  addKey("play", Play_Key, 0x02, 8);
  addKey("pause", Pause_Key, 0x03, 8);
  addKey("skipnext", Next_Key, 0x04, 8);
  addKey("skipprev", Previous_Key, 0x05, 8);
  addKey("searchnext", FastForward_Key, 0x06, 8);
  addKey("searchprev", Rewind_Key, 0x07, 8);
  addKey("repeat", Repeat_Key, 0x0A, 8);
  addKey("ab", RepeatAB_Key, 0x0B, 8);
  addKey("intro", Unmapped_Key, 0x0D, 8);
  addKey("program", Program_Key, 0x0E, 8);
  addKey("clear", Clear_Key, 0x0F, 8);

  addKey("1", One_Key, 0x11, 8);
  addKey("2", Two_Key, 0x12, 8);
  addKey("3", Three_Key, 0x13, 8);
  addKey("4", Four_Key, 0x14, 8);
  addKey("5", Five_Key, 0x15, 8);
  addKey("6", Six_Key, 0x16, 8);
  addKey("7", Seven_Key, 0x17, 8);
  addKey("8", Eight_Key, 0x18, 8);
  addKey("9", Nine_Key, 0x19, 8);
  addKey("check", Unmapped_Key, 0x1B, 8);
  addKey("time", Unmapped_Key, 0x1C, 8);
  addKey("display", Info_Key, 0x1D, 8);

  addKey("0", Zero_Key, 0x40, 8);
  addKey("edit", Unmapped_Key, 0x4C, 8);
  addKey("random", Random_Key, 0x4D, 8);

  addKey("CD_DISC", NextDisc_Key, 0x50, 8);
  addKey("on", PowerOn_Key, 0x56, 8);
  addKey("off", PowerOff_Key, 0x57, 8);
  addKey("tapesize", Unmapped_Key, 0x5C, 8);
}
