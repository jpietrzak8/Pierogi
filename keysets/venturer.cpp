#include "venturer.h"
#include "protocols/necprotocol.h"

VenturerTV1::VenturerTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Venturer_Make,
      index)
{
}

void VenturerTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x04, 8);

  addKey("Channel Up", ChannelUp_Key, 0x00, 8);
  addKey("Channel Down", ChannelDown_Key, 0x01, 8);
  addKey("Volume Up", VolumeUp_Key, 0x02, 8);
  addKey("Volume Down", VolumeDown_Key, 0x03, 8);
  addKey("Menu", Menu_Key, 0x04, 8);
  addKey("Sound", SoundMode_Key, 0x06, 8);
  addKey("Standby/On", Power_Key, 0x08, 8);
  addKey("Mute", Mute_Key, 0x09, 8);
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
  addKey("Last Channel", PrevChannel_Key, 0x1A, 8);
  addKey("Red", Red_Key, 0x21, 8);
  addKey("Green", Green_Key, 0x22, 8);
  addKey("Yellow", Yellow_Key, 0x23, 8);
  addKey("Blue", Blue_Key, 0x24, 8);
  addKey("Function", Unmapped_Key, 0x25, 8);
  addKey("Subtitle", Captions_Key, 0x26, 8);
  addKey("Time", Unmapped_Key, 0x27, 8);
  addKey("Picture", PictureMode_Key, 0x28, 8);
  addKey("Display", Info_Key, 0x3A, 8);
  addKey("I/II", Audio_Key, 0x40, 8);
  addKey("TV/Text", Teletext_Key, 0x48, 8);
  addKey("Sleep", Sleep_Key, 0x4B, 8);
  addKey("Format", Unmapped_Key, 0x4C, 8);
  addKey("YUV In", Unmapped_Key, 0x50, 8);
  addKey("AV In", CompositeInput_Key, 0x5A, 8);
  addKey("Exit", Exit_Key, 0x5B, 8);
}


VenturerDVD1::VenturerDVD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Venturer_Make,
      index)
{
}


void VenturerDVD1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x9A, 8);

  addKey("Next Chapter", Next_Key, 0x02, 8);
  addKey("Play", Play_Key, 0x03, 8);
  addKey("Previous Chapter", Previous_Key, 0x06, 8);
  addKey("Search Forward", FastForward_Key, 0x07, 8);
  addKey("Open/Close", Eject_Key, 0x09, 8);
  addKey("Channel Up", Up_Key, 0x0A, 8);
  addKey("Disc 4 / Sound", SoundMode_Key, 0x0B, 8);
  addKey("Stop", Stop_Key, 0x0F, 8);
  addKey("Record", Record_Key, 0x12, 8);
  addKey("Slow Forward", SlowPlus_Key, 0x13, 8);
  addKey("Function", Unmapped_Key, 0x16, 8);
  addKey("Search Reverse", Rewind_Key, 0x17, 8);
  addKey("Pause", Pause_Key, 0x1B, 8);
  addKey("Slow Reverse", SlowMinus_Key, 0x1F, 8);
  addKey("Audio", Audio_Key, 0x40, 8);
  addKey("Repeat Disc", Repeat_Key, 0x41, 8);
  addKey("Volume Up", VolumeUp_Key, 0x42, 8);
  addKey("Display", Info_Key, 0x43, 8);
  addKey("Goto", Unmapped_Key, 0x44, 8);
  addKey("Repeat A-B", RepeatAB_Key, 0x45, 8);
  addKey("Right", Right_Key, 0x46, 8);
  addKey("Subtitle", Captions_Key, 0x47, 8);
  addKey("num 10", DoubleDigit_Key, 0x48, 8);
  addKey("6", Six_Key, 0x49, 8);
  addKey("Volume Down", VolumeDown_Key, 0x4A, 8);
  addKey("Angle", Angle_Key, 0x4B, 8);
  addKey("Zoom", Zoom_Key, 0x4C, 8);
  addKey("9", Nine_Key, 0x4D, 8);
  addKey("3", Three_Key, 0x4E, 8);
  addKey("Up", Up_Key, 0x4F, 8);
  addKey("0", Zero_Key, 0x50, 8);
  addKey("5", Five_Key, 0x51, 8);
  addKey("Enter", Enter_Key, 0x52, 8);
  addKey("Disc 1 / Memory", Unmapped_Key, 0x53, 8);
  addKey("Setup", Menu_Key, 0x54, 8);
  addKey("8", Eight_Key, 0x55, 8);
  addKey("Down", Down_Key, 0x56, 8);
  addKey("Power", Power_Key, 0x57, 8);
  addKey("Return", Exit_Key, 0x58, 8);
  addKey("7", Seven_Key, 0x59, 8);
  addKey("1", One_Key, 0x5A, 8);
  addKey("Left", Left_Key, 0x5B, 8);
  addKey("Clear", Clear_Key, 0x5C, 8);
  addKey("4", Four_Key, 0x5D, 8);
  addKey("2", Two_Key, 0x5E, 8);
  addKey("Menu", DiscMenu_Key, 0x5F, 8);
  addKey("Input", Input_Key, 0x62, 8);
  addKey("TV/VCR", Unmapped_Key, 0x63, 8);
  addKey("Channel Down", ChannelDown_Key, 0x64, 8);
  addKey("SP/EP", VHSSpeed_Key, 0x65, 8);
  addKey("Disc 2 / 5.1 CH", Unmapped_Key, 0x68, 8);
  addKey("Disc 3 / 2.1 CH", Unmapped_Key, 0x69, 8);
  addKey("Pro Logic", Unmapped_Key, 0x6A, 8);
  addKey("Disc 5 / Dimmer", Unmapped_Key, 0x6B, 8);
}


VenturerSTB1::VenturerSTB1(
  unsigned int index)
  : PIRKeysetMetaData(
      "STB Keyset 1",
      Venturer_Make,
      index)
{
}


void VenturerSTB1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0xBB42, 16);

  addKey("1", One_Key, 0x81, 8);
  addKey("2", Two_Key, 0x82, 8);
  addKey("3", Three_Key, 0x83, 8);
  addKey("4", Four_Key, 0x84, 8);
  addKey("5", Five_Key, 0x85, 8);
  addKey("6", Six_Key, 0x86, 8);
  addKey("7", Seven_Key, 0x87, 8);
  addKey("8", Eight_Key, 0x88, 8);
  addKey("9", Nine_Key, 0x89, 8);
  addKey("0", Zero_Key, 0x8A, 8);
  addKey("exit", Exit_Key, 0x8B, 8);
  addKey("cc", Captions_Key, 0x8C, 8);
  addKey(". (last ch)", PrevChannel_Key, 0x8E, 8);
  addKey("power", Power_Key, 0x92, 8);
  addKey("mute", Mute_Key, 0x96, 8);
  addKey("signal", Unmapped_Key, 0x98, 8);
  addKey("vol up", VolumeUp_Key, 0x9A, 8);
  addKey("channel up", ChannelUp_Key, 0x9B, 8);
  addKey("vol down", VolumeDown_Key, 0x9C, 8);
  addKey("channel down", ChannelDown_Key, 0x9F, 8);
  addKey("up arrow", Up_Key, 0xC8, 8);
  addKey("down arrow", Down_Key, 0xC9, 8);
  addKey("right arrow", Right_Key, 0xCA, 8);
  addKey("left arrow", Left_Key, 0xCB, 8);
  addKey("menu", Menu_Key, 0xD4, 8);
  addKey("info", Info_Key, 0xFE, 8);
  addKey("ok", Select_Key, 0xFF, 8);
}
