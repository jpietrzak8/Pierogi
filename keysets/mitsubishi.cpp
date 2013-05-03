#include "mitsubishi.h"
#include "protocols/protonprotocol.h"
#include "protocols/mitsubishiprotocol.h"

MitsubishiTV1::MitsubishiTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Mitsubishi_Make,
      index)
{
}


void MitsubishiTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new MitsubishiProtocol(guiObject, index);

  setPreData(0xE2, 8);

  addKey("POWER", Power_Key, 0x40, 8);
  addKey("0", Zero_Key, 0x90, 8);
  addKey("1", One_Key, 0x00, 8);
  addKey("2", Two_Key, 0x10, 8);
  addKey("3", Three_Key, 0x08, 8);
  addKey("4", Four_Key, 0x18, 8);
  addKey("5", Five_Key, 0x04, 8);
  addKey("6", Six_Key, 0x14, 8);
  addKey("7", Seven_Key, 0x0C, 8);
  addKey("8", Eight_Key, 0x1C, 8);
  addKey("9", Nine_Key, 0x80, 8);
  addKey("-/--", DoubleDigit_Key, 0x88, 8); // "1-"
  addKey("2-", Unmapped_Key, 0x98, 8);
  addKey("VOL_UP", VolumeUp_Key, 0x44, 8);
  addKey("VOL_DOWN", VolumeDown_Key, 0x54, 8);
  addKey("MUTE", Mute_Key, 0x4C, 8);
  addKey("OFF_TIMER", Sleep_Key, 0xE8, 8);
  addKey("ENTER", Enter_Key, 0xAC, 8);
  addKey("ENTER", Select_Key, 0xAC, 8);
  addKey("TV/EXT", Input_Key, 0x5C, 8); // "tv/av", "INPUT"
  addKey("CHANNEL_UP", ChannelUp_Key, 0x50, 8);
  addKey("CHANNEL_DOWN", ChannelDown_Key, 0x48, 8);
  addKey("VIDEO", Unmapped_Key, 0x02, 8);
  addKey("ADJ_LEFT", Unmapped_Key, 0x92, 8);
  addKey("ADJ_RIGHT", Unmapped_Key, 0x82, 8);
  addKey("LAST", PrevChannel_Key, 0xF0, 8); // "Q.V."
  addKey("display", Info_Key, 0xF8, 8); // "clear"
  addKey("menu", Menu_Key, 0x4A, 8); // "MODE"
  addKey("up", Up_Key, 0x26, 8);
  addKey("down", Down_Key, 0x36, 8);
  addKey("right", Right_Key, 0x82, 8);
  addKey("left", Left_Key, 0x92, 8);
  addKey("TEXT", Teletext_Key, 0x30, 8);
  addKey("HOLD", TeletextHold_Key, 0xA8, 8);
  addKey("INDEX", TeletextIndex_Key, 0x64, 8);
  addKey("CANCEL/TIME", TeletextTime_Key, 0xB8, 8);
  addKey("RED", Red_Key, 0xF4, 8);
  addKey("GREEN", Green_Key, 0xEC, 8);
  addKey("YELLOW", Yellow_Key, 0xFC, 8);
  addKey("BLUE", Blue_Key, 0xE4, 8);
  addKey("SIZE", TeletextSize_Key, 0x34, 8);
  addKey("S****", Unmapped_Key, 0x74, 8);
  addKey("REVEAL", TeletextReveal_Key, 0x7C, 8);
  addKey("MODE", Unmapped_Key, 0xA4, 8);
  addKey("STORE", TeletextStore_Key, 0x78, 8);
  addKey("STATUS", Unmapped_Key, 0xB0, 8);
  addKey("BROWSE", Unmapped_Key, 0x6C, 8);
  addKey("PIP", PIP_Key, 0xEE, 8);
  addKey("SOURCE", PIPSource_Key, 0xFA, 8);
  addKey("POSITION", PIPMove_Key, 0x76, 8);
  addKey("EXCHANGE", PIPSwap_Key, 0xFE, 8);
  addKey("STILL", PIPPause_Key, 0xE6, 8);
  addKey("PREVMENU", Exit_Key, 0xD2, 8);
  addKey("ENTER", Select_Key, 0xDE, 8);
  addKey("VIDEO", PictureMode_Key, 0xCC, 8);
  addKey("AUDIO", SoundMode_Key, 0xDC, 8);
  addKey("ST/MONO", Unmapped_Key, 0xC0, 8);
  addKey("DEGAUSS", Unmapped_Key, 0xCE, 8);
  addKey("DEMO", Unmapped_Key, 0x62, 8);
  addKey("PRESET", Unmapped_Key, 0xA2, 8);
  addKey("BAND", TunerInput_Key, 0xAE, 8);
  addKey("AFT", Unmapped_Key, 0xA6, 8);
  addKey("SKIP", Unmapped_Key, 0xB6, 8);
  addKey("REALNAME", Unmapped_Key, 0xDA, 8);
}


MitsubishiTV1a::MitsubishiTV1a(
  unsigned int index)
  : MitsubishiTV1(index)
{
  setKeysetName("TV Keyset 1a");
}


void MitsubishiTV1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  MitsubishiTV1::populateProtocol(guiObject);

  addKey("TURNLEFT", Unmapped_Key, 0xAC, 8);
  addKey("TURNRIGHT", Unmapped_Key, 0xB4, 8);
  addKey("COLOUR-SELECT", PictureMode_Key, 0x30, 8);
  addKey("AUDIO-SELECT", SoundMode_Key, 0xC8, 8);
}


MitsubishiVCR1::MitsubishiVCR1(
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      Mitsubishi_Make,
      index)
{
}



void MitsubishiVCR1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new MitsubishiProtocol(guiObject, index);

  setPreData(0xEA, 8);

  addKey("POWER", Power_Key, 0x40, 8);
  addKey("CH-", ChannelDown_Key, 0x48, 8);
  addKey("CH+", ChannelUp_Key, 0x50, 8);
  addKey("PROG_ON-OFF", Unmapped_Key, 0xD8, 8); // "SHOWVIEW"
  addKey("PROG_REC", Unmapped_Key, 0xF8, 8);
  addKey("PROG_NBR", Unmapped_Key, 0xD4, 8);
  addKey("SELECT", Select_Key, 0xCC, 8); // "OKPROG", "quick_program"
  addKey("SET", Enter_Key, 0xC8, 8);
  addKey("CLEAR", Clear_Key, 0xD0, 8);
  addKey("INDEX_ENTER", Unmapped_Key, 0xF0, 8);
  addKey("FAST_PLAY", Unmapped_Key, 0xA4, 8);
  addKey("COUNTER_RESET", Unmapped_Key, 0xA8, 8);
  addKey("COUNTER_MEMORY", Unmapped_Key, 0xB0, 8);
  addKey("REC", Record_Key, 0x30, 8);
  addKey("PAUSE", Pause_Key, 0x38, 8);
  addKey("STOP", Stop_Key, 0x28, 8);
  addKey("SLOW", Slow_Key, 0x2C, 8); // "UP"
  addKey("REW", Rewind_Key, 0x34, 8);
  addKey("PLAY", Play_Key, 0x20, 8);
  addKey("FF", FastForward_Key, 0x24, 8);
  addKey("REPEAT", Repeat_Key, 0xE8, 8);
  addKey("SKIP_SEARCH", Advance_Key, 0xBC, 8);
  addKey("INDEX_SEARCH-", Previous_Key, 0x68, 8);
  addKey("INDEX_SEARCH+", Next_Key, 0x70, 8);
  addKey("EJECT", Eject_Key, 0x6C, 8);
  addKey("MENU", Menu_Key, 0x4A, 8);
  addKey("123MENU", Unmapped_Key, 0x0A, 8);
  addKey("AV", Unmapped_Key, 0x58, 8);
  addKey("0", Zero_Key, 0x90, 8);
  addKey("1", One_Key, 0x00, 8);
  addKey("2", Two_Key, 0x10, 8);
  addKey("3", Three_Key, 0x08, 8);
  addKey("4", Four_Key, 0x18, 8);
  addKey("5", Five_Key, 0x04, 8);
  addKey("6", Six_Key, 0x14, 8);
  addKey("7", Seven_Key, 0x0C, 8);
  addKey("8", Eight_Key, 0x1C, 8);
  addKey("9", Nine_Key, 0x80, 8);
  addKey("10-60", DoubleDigit_Key, 0x88, 8);
  addKey("MONITOR", Unmapped_Key, 0xC0, 8);
  addKey("CANCEL", Unmapped_Key, 0x60, 8);
  addKey("SP/LP", VHSSpeed_Key, 0x7C, 8);
  addKey("DAILY/WEEKLY", Unmapped_Key, 0xF2, 8);
  addKey("COUNT_RES", Unmapped_Key, 0xDC, 8);
  addKey("display", Info_Key, 0xE4, 8); // "DATA_SCRN"
  addKey("x2", PlayX2_Key, 0x5C, 8);
  addKey("audio/video", Unmapped_Key, 0x02, 8);
  addKey("adjust+", Right_Key, 0x82, 8);
  addKey("cancel", Exit_Key, 0xD0, 8);
  addKey("enter", Select_Key, 0xAC, 8);
  addKey("adjust-", Left_Key, 0x92, 8);
  addKey("vcr/tv", Input_Key, 0xA0, 8);
//  addKey("ENCORE", Unmapped_Key, 0xA0, 8);
}


MitsubishiVCR1a::MitsubishiVCR1a(
  unsigned int index)
  : MitsubishiVCR1(index)
{
  setKeysetName("VCR Keyset 1a");
}


void MitsubishiVCR1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  MitsubishiVCR1::populateProtocol(guiObject);

  addKey("->", Unmapped_Key, 0xAC, 8); // Shuttle right
  addKey("<-", Unmapped_Key, 0xD0, 8);  // Shuttle left
  addKey("UP", Up_Key, 0x2C, 8);
  addKey("JOG+", Unmapped_Key, 0x50, 8);
  addKey("JOG-", Unmapped_Key, 0x48, 8);
}


MitsubishiProjector1::MitsubishiProjector1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Projector Keyset 1",
      Mitsubishi_Make,
      index)
{
}


void MitsubishiProjector1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new ProtonProtocol(guiObject, index);

  setPreData(0xF0, 8);

  addKey("Power", Power_Key, 0x40, 8);
  addKey("PowerOn", PowerOn_Key, 0x41, 8);
  addKey("PowerOn", Green_Key, 0x41, 8); // This is a hack.
  addKey("PowerOff", PowerOff_Key, 0x42, 8);
  addKey("PowerOff", Red_Key, 0x42, 8); // Also hack.
  addKey("Keystone", Keystone_Key, 0x43, 8);

  addKey("Computer", PCInput_Key, 0x60, 8); // "RGB1"
  addKey("Video1", AuxInput_Key, 0x61, 8);
  addKey("PC Card", Unmapped_Key, 0x62, 8);
  addKey("Component", ComponentInput_Key, 0x64, 8);
  addKey("Video", CompositeInput_Key, 0x65, 8);
  addKey("S-Video", SVideoInput_Key, 0x66, 8);
  addKey("HDMI", HDMIInput_Key, 0x70, 8);

  addKey("Left", Left_Key, 0x80, 8);
  addKey("Right", Right_Key, 0x81, 8);
  addKey("Up", Up_Key, 0x82, 8);
  addKey("Down", Down_Key, 0x83, 8);
  addKey("Vol-", VolumeDown_Key, 0x84, 8);
  addKey("Vol+", VolumeUp_Key, 0x85, 8);
  addKey("Menu", Menu_Key, 0x86, 8);
  addKey("Enter", Enter_Key, 0x87, 8);

  addKey("Expand", Unmapped_Key, 0xA1, 8);
  addKey("AutoPosition", Unmapped_Key, 0xA2, 8);
  addKey("AutoPlay", Unmapped_Key, 0xA3, 8);
  addKey("Still", Pause_Key, 0xA4, 8);
  addKey("Release", Unmapped_Key, 0xA5, 8);
  addKey("Blank", Unmapped_Key, 0xA6, 8);

  addKey("Contrast", ContrastUp_Key, 0xD0, 8);
  addKey("Brightness", BrightnessUp_Key, 0xD1, 8);
  addKey("ColorTemp", ColorUp_Key, 0xD4, 8);
  addKey("Gamma", Unmapped_Key, 0xD5, 8);
  addKey("Sharpness", Unmapped_Key, 0xD6, 8);

  addKey("Aspect", AspectRatio_Key, 0xE2, 8);
  addKey("M1", Unmapped_Key, 0xE4, 8);
  addKey("M2", Unmapped_Key, 0xE5, 8);
  addKey("M3", Unmapped_Key, 0xE6, 8);
}


MitsubishiProjector2::MitsubishiProjector2(
  unsigned int index)
  : PIRKeysetMetaData(
      "Projector Keyset 2",
      Mitsubishi_Make,
      index)
{
}


void MitsubishiProjector2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new MitsubishiProtocol(guiObject, index);

  setPreData(0x47, 8);

  addKey("Power On", Power_Key, 0x42, 8); // Not quite right
  addKey("Power On", PowerOn_Key, 0x42, 8);
  addKey("Power On", Green_Key, 0x42, 8); // This is a hack
  addKey("Power Off", PowerOff_Key, 0x4A, 8);
  addKey("Power Off", Red_Key, 0x4A, 8); // Also a hack
  addKey("Display", Info_Key, 0x27, 8);
  addKey("Pic Mute", Mute_Key, 0x92, 8);
  addKey("Inputa", Unmapped_Key, 0xA4, 8);
  addKey("Inputb", Unmapped_Key, 0xAC, 8);
  addKey("Input Video", Unmapped_Key, 0xF5, 8);
  addKey("Input Y/C", Unmapped_Key, 0xFD, 8);
  addKey("Menu", Menu_Key, 0x33, 8);
  addKey("Menu 2", Guide_Key, 0x73, 8);
  addKey("Mem List", Favorites_Key, 0x9D, 8); // Not quite right
  addKey("CRT R", Unmapped_Key, 0xA1, 8);
  addKey("CRT G", Unmapped_Key, 0xA9, 8);
  addKey("CRT B", Unmapped_Key, 0xB1, 8);
  addKey("Test", Unmapped_Key, 0x5E, 8);
  addKey("1", One_Key, 0x00, 8);
  addKey("2", Two_Key, 0x08, 8);
  addKey("3", Three_Key, 0x10, 8);
  addKey("4", Four_Key, 0x18, 8);
  addKey("5", Five_Key, 0x20, 8);
  addKey("6", Six_Key, 0x28, 8);
  addKey("7", Seven_Key, 0x30, 8);
  addKey("8", Eight_Key, 0x38, 8);
  addKey("9", Nine_Key, 0x01, 8);
  addKey("0", Zero_Key, 0x09, 8);
  addKey("Enter", Select_Key, 0xBB, 8);
  addKey("Func", Unmapped_Key, 0xB3, 8);
  addKey("Esc", Exit_Key, 0x52, 8);
  addKey("Normal", Unmapped_Key, 0x9F, 8);
  addKey("Up", Up_Key, 0x74, 8);
  addKey("Down", Down_Key, 0x7C, 8);
  addKey("Left", Left_Key, 0x6C, 8);
  addKey("Right", Right_Key, 0x64, 8);
}
