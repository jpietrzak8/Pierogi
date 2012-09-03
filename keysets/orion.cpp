#include "orion.h"
#include "protocols/necprotocol.h"

OrionTV1::OrionTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Orion_Make,
      index)
{
}


void OrionTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, false);

  setPreData(0x00, 8);

  addKey("Power", Power_Key, 0x00, 8);
  addKey("Vol-", VolumeDown_Key, 0x01, 8);
  addKey("OK", Select_Key, 0x02, 8);
  addKey("9", Nine_Key, 0x03, 8);
  addKey("Lang", Unmapped_Key, 0x04, 8);
  addKey("ChannelUp", ChannelUp_Key, 0x05, 8);
  addKey("Vol+", VolumeUp_Key, 0x06, 8);
  addKey("8", Eight_Key, 0x07, 8);
  addKey("Search", Unmapped_Key, 0x08, 8);
  addKey("Exit", Exit_Key, 0x09, 8);
  addKey("ChannelDown", ChannelDown_Key, 0x0A, 8);
  addKey("7", Seven_Key, 0x0B, 8);
  addKey("Memory", Memory_Key, 0x0C, 8);
  addKey("Mute", Mute_Key, 0x0E, 8);
  addKey("TV/Radio", TunerInput_Key, 0x0F, 8);
  addKey("FavoriteOnOff", Favorites_Key, 0x10, 8);
  addKey("Menu", Menu_Key, 0x11, 8);
  addKey("Audio", Audio_Key, 0x12, 8);
  addKey("6", Six_Key, 0x13, 8);
  addKey("GuideUp", Up_Key, 0x14, 8);
  addKey("Info", Info_Key, 0x15, 8);
  addKey("1", One_Key, 0x16, 8);
  addKey("5", Five_Key, 0x17, 8);
  addKey("GuideDown", Down_Key, 0x18, 8);
  addKey("Teletext", Teletext_Key, 0x19, 8);
  addKey("2", Two_Key, 0x1A, 8);
  addKey("4", Four_Key, 0x1B, 8);
  addKey("Guide", Guide_Key, 0x1C, 8);
  addKey("PRList", Unmapped_Key, 0x1D, 8);
  addKey("3", Three_Key, 0x1E, 8);
  addKey("Pause", Pause_Key, 0x1F, 8);
  addKey("Sleep", Sleep_Key, 0x40, 8);
  addKey("0", Zero_Key, 0x44, 8);
  addKey("P/N", Unmapped_Key, 0x48, 8);
  addKey("Spiral", Unmapped_Key, 0x4C, 8);
  addKey("TV/AV", Input_Key, 0x50, 8);
  addKey("-", Left_Key, 0x54, 8); // bit of a hack
  addKey("+", Right_Key, 0x58, 8); // also here
  addKey("Mode", Mode_Key, 0x5C, 8);
}


OrionTV2::OrionTV2(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 2",
      Orion_Make,
      index)
{
}


void OrionTV2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, false);

  setPreData(0x0586, 16);

  addKey("1", One_Key, 0x00, 8);
  addKey("2", Two_Key, 0x01, 8);
  addKey("3", Three_Key, 0x02, 8);
  addKey("4", Four_Key, 0x03, 8);
  addKey("5", Five_Key, 0x04, 8);
  addKey("6", Six_Key, 0x05, 8);
  addKey("7", Seven_Key, 0x06, 8);
  addKey("8", Eight_Key, 0x07, 8);
  addKey("9", Nine_Key, 0x08, 8);
  addKey("0", Zero_Key, 0x09, 8);
  addKey("channel up", ChannelUp_Key, 0x0A, 8);
  addKey("channel down", ChannelDown_Key, 0x0B, 8);
  addKey("vol up", VolumeUp_Key, 0x0C, 8);
  addKey("vol down", VolumeDown_Key, 0x0D, 8);
  addKey("mute", Mute_Key, 0x0E, 8);
  addKey("power", Power_Key, 0x0F, 8);
  addKey("prev", PrevChannel_Key, 0x10, 8);
  addKey("input", Input_Key, 0x12, 8);
  addKey("sleep", Sleep_Key, 0x13, 8);
  addKey("menu", Menu_Key, 0x14, 8);
  addKey("menu item+", Right_Key, 0x15, 8); // hack
  addKey("menu item-", Left_Key, 0x16, 8); // also hack
  addKey("info", Info_Key, 0x17, 8);
  addKey("menu enter", Select_Key, 0x18, 8);
  addKey("reset", Reset_Key, 0x19, 8);
  addKey("caption", Captions_Key, 0x1C, 8);
  addKey("caption channel", Unmapped_Key, 0x1D, 8);
  addKey("secret menu", Unmapped_Key, 0x1E, 8);
}


OrionTV3::OrionTV3(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 3",
      Orion_Make,
      index)
{
}


void OrionTV3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, false);

  setPreData(0x0571, 16);

  addKey("0", Zero_Key, 0x40, 8);
  addKey("1", One_Key, 0x41, 8);
  addKey("2", Two_Key, 0x42, 8);
  addKey("3", Three_Key, 0x43, 8);
  addKey("4", Four_Key, 0x44, 8);
  addKey("5", Five_Key, 0x45, 8);
  addKey("6", Six_Key, 0x46, 8);
  addKey("7", Seven_Key, 0x47, 8);
  addKey("8", Eight_Key, 0x48, 8);
  addKey("9", Nine_Key, 0x49, 8);
  addKey("Power", Power_Key, 0x4A, 8);
  addKey("Info", Info_Key, 0x4C, 8);
  addKey("Exit", Exit_Key, 0x4D, 8);
  addKey("Audio", Audio_Key, 0x4E, 8);
  addKey("Reveal", Unmapped_Key, 0x4F, 8); // teletext?
  addKey("Sub", Captions_Key, 0x50, 8);
  addKey("Hold", TeletextHold_Key, 0x51, 8);
  addKey("MenuA", Unmapped_Key, 0x53, 8); // what is this?
  addKey("Up", Up_Key, 0x56, 8);
  addKey("Down", Down_Key, 0x57, 8);
  addKey("Left", Left_Key, 0x58, 8);
  addKey("Right", Right_Key, 0x59, 8);
  addKey("OK", Select_Key, 0x5A, 8);
  addKey("SubPage", TeletextSelect_Key, 0x5C, 8);
  addKey("Yellow", Yellow_Key, 0x61, 8);
  addKey("Blue", Blue_Key, 0x64, 8);
  addKey("Red", Red_Key, 0x65, 8);
  addKey("Enlarge", Unmapped_Key, 0x66, 8); // more txt I guess
  addKey("Green", Green_Key, 0x68, 8);
  addKey("TV/DVD", DVDInput_Key, 0x69, 8);
  addKey("Mute", Mute_Key, 0x6A, 8);
  addKey("sleep", Sleep_Key, 0x6B, 8);
  addKey("16/9", AspectRatio_Key, 0x6C, 8);
  addKey("Ch+", ChannelUp_Key, 0x6D, 8);
  addKey("Ch-", ChannelDown_Key, 0x6E, 8);
  addKey("Text", Teletext_Key, 0x71, 8);
  addKey("Input", Input_Key, 0x73, 8);
  addKey("PP", PrevChannel_Key, 0x7C, 8);
  addKey("TV/DBTV", AntennaInput_Key, 0xB0, 8); // fix
  addKey("Guide", Guide_Key, 0xB1, 8);
  addKey("Menu", Menu_Key, 0xB2, 8);
  addKey("TV/Radio", TunerInput_Key, 0xB3, 8);
  addKey("Vol+", VolumeUp_Key, 0xC5, 8);
  addKey("Vol-", VolumeDown_Key, 0xC6, 8);
}


OrionVCR1::OrionVCR1(
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      Orion_Make,
      index)
{
}


void OrionVCR1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x7B80, 16);

  addKey("CH0", Zero_Key, 0x00, 8);
  addKey("CH1", One_Key, 0x01, 8);
  addKey("CH2", Two_Key, 0x02, 8);
  addKey("CH3", Three_Key, 0x03, 8);
  addKey("CH4", Four_Key, 0x04, 8);
  addKey("CH5", Five_Key, 0x05, 8);
  addKey("CH6", Six_Key, 0x06, 8);
  addKey("CH7", Seven_Key, 0x07, 8);
  addKey("CH8", Eight_Key, 0x08, 8);
  addKey("CH9", Nine_Key, 0x09, 8);
  addKey("CHUP", Up_Key, 0x0A, 8);
  addKey("CHDN", Down_Key, 0x0B, 8);
  addKey("TIMER_REC", RecordTimed_Key, 0x0D, 8);
  addKey("AUDIOSELECT", Audio_Key, 0x0E, 8);
  addKey("CH10+", DoubleDigit_Key, 0x0F, 8);

  addKey("TVVCR", Input_Key, 0x12, 8);
  addKey("POWER", Power_Key, 0x13, 8);
  addKey("INDEX", IndexSearch_Key, 0x14, 8);
  addKey("RECOTR", Record_Key, 0x15, 8);
  addKey("PLAY", Play_Key, 0x16, 8);
  addKey("STOP", Stop_Key, 0x17, 8);
  addKey("FFWD", FastForward_Key, 0x18, 8);
  addKey("REW", Rewind_Key, 0x19, 8);
  addKey("PAUSESTILL", Pause_Key, 0x1A, 8);
  addKey("CLOCKSET", Unmapped_Key, 0x1C, 8);
  addKey("SHOWVIEW", Unmapped_Key, 0x1D, 8); // vhsplus+, etc.
  addKey("SPEEDSPLP", VHSSpeed_Key, 0x1E, 8);

  addKey("PRESET", Unmapped_Key, 0x40, 8);
  addKey("SET+", Unmapped_Key, 0x41, 8);
  addKey("SET-", Unmapped_Key, 0x42, 8);
  addKey("FINETUNEUP", TrackingPlus_Key, 0x43, 8);
  addKey("FINETUNEDN", TrackingMinus_Key, 0x44, 8);
  addKey("ENTER", Enter_Key, 0x45, 8);
  addKey("AFT", Unmapped_Key, 0x46, 8);
  addKey("PROGRAM", Program_Key, 0x48, 8);
  addKey("CANCEL", Clear_Key, 0x4A, 8);
  addKey("MEMORY", Memory_Key, 0x4B, 8);
  addKey("RESET", Reset_Key, 0x4C, 8);
  addKey("EJECT", Eject_Key, 0x4E, 8);
  addKey("AUDIODUBBING", Unmapped_Key, 0x4F, 8);

  addKey("MENU", Menu_Key, 0x50, 8);
  addKey("CLOCKCOUNTER", Clock_Key, 0x51, 8);
  addKey("ATR", AutoTracking_Key, 0x52, 8);
  addKey("CALL", Call_Key, 0x5F, 8);
}


OrionVCR2::OrionVCR2(
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 2",
      Orion_Make,
      index)
{
}


void OrionVCR2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x7E80, 16);

  addKey("repeat", Repeat_Key, 0x0A, 8);
  addKey("power", Power_Key, 0x0B, 8);
  addKey("play", Play_Key, 0x0C, 8);
  addKey("stop", Stop_Key, 0x0D, 8);
  addKey("ffwd", FastForward_Key, 0x0E, 8);
  addKey("rew", Rewind_Key, 0x0F, 8);
  addKey("still", Pause_Key, 0x10, 8);
}


OrionDVD1::OrionDVD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Orion_Make,
      index)
{
}


void OrionDVD1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, false);

  setPreData(0x0571, 16);

  addKey("0", Zero_Key, 0x40, 8);
  addKey("1", One_Key, 0x41, 8);
  addKey("2", Two_Key, 0x42, 8);
  addKey("3", Three_Key, 0x43, 8);
  addKey("4", Four_Key, 0x44, 8);
  addKey("5", Five_Key, 0x45, 8);
  addKey("6", Six_Key, 0x46, 8);
  addKey("7", Seven_Key, 0x47, 8);
  addKey("8", Eight_Key, 0x48, 8);
  addKey("9", Nine_Key, 0x49, 8);
  addKey("Power", Power_Key, 0x4A, 8);
  addKey("Info", Info_Key, 0x4C, 8);
  addKey("Exit", Exit_Key, 0x4D, 8);
  addKey("Audio", Audio_Key, 0x4E, 8);
  addKey("Angle", Angle_Key, 0x4F, 8);
  addKey("Sub", Captions_Key, 0x50, 8);
  addKey("Slow-", SlowMinus_Key, 0x51, 8);
  addKey("TopMenu", DiscTitle_Key, 0x52, 8);
  addKey("Return", Exit_Key, 0x54, 8);
  addKey("DVDMenu", DiscMenu_Key, 0x55, 8);
  addKey("Up", Up_Key, 0x56, 8);
  addKey("Down", Down_Key, 0x57, 8);
  addKey("Left", Left_Key, 0x58, 8);
  addKey("Right", Right_Key, 0x59, 8);
  addKey("OK", Select_Key, 0x5A, 8);
  addKey("PlayMode", Mode_Key, 0x5B, 8);
  addKey("Mark", Unmapped_Key, 0x5C, 8);
  addKey("Jump", Unmapped_Key, 0x5D, 8);
  addKey("A-B", RepeatAB_Key, 0x5E, 8);
  addKey("Zoom", Zoom_Key, 0x5F, 8);
  addKey("Play", Play_Key, 0x60, 8);
  addKey("Stop", Stop_Key, 0x61, 8);
  addKey("FFW", FastForward_Key, 0x62, 8);
  addKey("Rew", Rewind_Key, 0x63, 8);
  addKey("Skip+", Next_Key, 0x64, 8);
  addKey("Skip-", Previous_Key, 0x65, 8);
  addKey("Slow+", SlowPlus_Key, 0x66, 8);
  addKey("Pause", Pause_Key, 0x68, 8);
  addKey("TV/DVD", DVDInput_Key, 0x69, 8);
  addKey("Mute", Mute_Key, 0x6A, 8);
  addKey("Sleep", Sleep_Key, 0x6B, 8);
  addKey("16/9", AspectRatio_Key, 0x6C, 8);
  addKey("Vol+", VolumeUp_Key, 0xC5, 8);
  addKey("Vol-", VolumeDown_Key, 0xC6, 8);
  addKey("Eject", Eject_Key, 0xCD, 8);
}
