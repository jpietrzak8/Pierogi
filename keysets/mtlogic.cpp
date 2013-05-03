#include "mtlogic.h"
#include "protocols/necprotocol.h"
#include "protocols/rc5protocol.h"

MTLogicTV1::MTLogicTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      MTLogic_Make,
      index)
{
}


void MTLogicTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0xA0, 8);

  addKey("CH+", ChannelUp_Key, 0x03, 8);
  addKey("100+", PlusOneHundred_Key, 0x06, 8);
  addKey("FFWD", FastForward_Key, 0x08, 8);
  addKey("Rewind", Rewind_Key, 0x09, 8);
  addKey("9", Nine_Key, 0x0A, 8);
  addKey("Play", Play_Key, 0x0C, 8);
  addKey("Pause", Pause_Key, 0x0C, 8);
  addKey("Stop", Stop_Key, 0x0D, 8);
  addKey("6", Six_Key, 0x0E, 8);
  addKey("Menu", Menu_Key, 0x10, 8);
  addKey("3", Three_Key, 0x12, 8);
  addKey("Arrow_Right", Right_Key, 0x14, 8);
  addKey("Input/Source", Input_Key, 0x1A, 8);
  addKey("Info/Display", Info_Key, 0x1B, 8);
  addKey("Mute", Mute_Key, 0x1C, 8);
  addKey("CH-", ChannelDown_Key, 0x1F, 8);
  addKey("Volume +", VolumeUp_Key, 0x40, 8);
  addKey("0", Zero_Key, 0x44, 8);
  addKey("Last/Prev Ch", PrevChannel_Key, 0x47, 8);
  addKey("8", Eight_Key, 0x48, 8);
  addKey("7", Seven_Key, 0x4B, 8);
  addKey("5", Five_Key, 0x4C, 8);
  addKey("4", Four_Key, 0x4F, 8);
  addKey("2", Two_Key, 0x50, 8);
  addKey("Arrow_Down", Down_Key, 0x51, 8);
  addKey("1", One_Key, 0x53, 8);
  addKey("OK/Select", Select_Key, 0x55, 8);
  addKey("Arrow_Left", Left_Key, 0x56, 8);
  addKey("CC", Captions_Key, 0x57, 8);
  addKey("Format 16:9", AspectRatio_Key, 0x58, 8);
  addKey("Arrow_Up", Up_Key, 0x59, 8);
  addKey("Guide", Guide_Key, 0x5A, 8);
  addKey("Sleep", Sleep_Key, 0x5B, 8);
  addKey("Volume -", VolumeDown_Key, 0x5D, 8);
  addKey("Power", Power_Key, 0x5F, 8);
}


// Commenting out the following until I can get it cleaned up.

/*
// This one came from a really messy config file, probably most commands are
// wrong.
MTLogicTV2::MTLogicTV2(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 2",
      MTLogic_Make,
      index)
{
}


void MTLogicTV2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  // I'm pretty sure the device code is bad here:
  threadableProtocol = new RC5Protocol(guiObject, index, 0x00);

  addKey("Last/Prev Ch", PrevChannel_Key, 0x02, 6);
//  addKey("EXIT", Exit_Key, 0x02, 6);
  addKey("Skip -", Previous_Key, 0x02, 6);
//  addKey("Brightness +", Unmapped_Key, 0x02, 6);
//  addKey("Color +", Unmapped_Key, 0x02, 6);
//  addKey("Shift Volume +", Unmapped_Key, 0x02, 6);

  addKey("Stop", Stop_Key, 0x04, 6);
//  addKey("FFWD", FastForward_Key, 0x04, 6);
//  addKey("Teletext Mix", Unmapped_Key, 0x04, 6);

  addKey("Record", Record_Key, 0x06, 6);
//  addKey("Teletext Index", Unmapped_Key, 0x06, 6);

  addKey("Play", Play_Key, 0x07, 6);
//  addKey("Stop", Stop_Key, 0x07, 6);
//  addKey("Rewind", Rewind_Key, 0x07, 6);
//  addKey("Record", Record_Key, 0x07, 6);
//  addKey("Teletext Expand", Unmapped_Key, 0x07, 6);

  addKey("Skip +", Next_Key, 0x0B, 6);
//  addKey("Brightness -", Unmapped_Key, 0x0B, 6);

//  addKey("Stop", Stop_Key, 0x0C, 6);
//  addKey("Pause", Pause_Key, 0x0C, 6);
  addKey("FFWD", FastForward_Key, 0x0C, 6);
//  addKey("Teletext Hold", Unmapped_Key, 0x0C, 6);

  addKey("Info/Display", Info_Key, 0x0D, 6);

  addKey("0", Zero_Key, 0x10, 6);
  addKey("1", One_Key, 0x11, 6);
  addKey("2", Two_Key, 0x12, 6);
  addKey("3", Three_Key, 0x13, 6);
  addKey("4", Four_Key, 0x14, 6);
  addKey("5", Five_Key, 0x15, 6);
  addKey("6", Six_Key, 0x16, 6);
  addKey("7", Seven_Key, 0x17, 6);
  addKey("8", Eight_Key, 0x18, 6);
  addKey("9", Nine_Key, 0x19, 6);
//  addKey("100+", PlusOneHundred_Key, 0x1A, 6);
  addKey("-/--", DoubleDigit_Key, 0x1A, 6);
  addKey("CH-", ChannelDown_Key, 0x1B, 6);
  addKey("Arrow_Down", Down_Key, 0x1B, 6);
  addKey("CH+", ChannelUp_Key, 0x1C, 6);
  addKey("Arrow_Up", Up_Key, 0x1C, 6);

  addKey("Power", Power_Key, 0x20, 6);
  addKey("Input/Source", Input_Key, 0x21, 6);
//  addKey("PIP On/Off", PIP_Key, 0x21, 6);
  addKey("Format 16:9", AspectRatio_Key, 0x23, 6);
//  addKey("FAV", Favorites_Key, 0x23, 6);
//  addKey("Record", Record_Key, 0x23, 6);
  addKey("Volume +", VolumeUp_Key, 0x24, 6);
  addKey("Arrow_Right", Right_Key, 0x24, 6);
  addKey("Volume -", VolumeDown_Key, 0x25, 6);
  addKey("Arrow_Left", Left_Key, 0x25, 6);
  addKey("Red", Red_Key, 0x26, 6);
  addKey("Guide", Guide_Key, 0x27, 6);
//  addKey("Last/Prev Ch", PrevChannel_Key, 0x27, 6);
  addKey("OK/Select", Select_Key, 0x28, 6):
  addKey("Menu", Menu_Key, 0x29, 6);
//  addKey("Radio", Unmapped_Key, 0x29, 6);
//  addKey("Input/Source", Input_Key, 0x2A, 6);
  addKey("EXIT", Exit_Key, 0x2A, 6);
  // 0x2A Also TV/Video, Play, FFWD, Skip+, Help, Teletext Off, Teletext On
  addKey("Mute", Mute_Key, 0x2B, 6);
  addKey("Green", Green_Key, 0x2C, 6);
  addKey("Yellow", Yellow_Key, 0x2D, 6);
//  addKey("Info/Display", Info_Key, 0x2E, 6);
  addKey("Rewind", Rewind_Key, 0x31, 6);
//  addKey("Skip -", Previous_Key, 0x31, 6);
  addKey("Teletext", Teletext_Key, 0x31, 6);
  addKey("Blue", Blue_Key, 0x33, 6);
}


MTLogicTV3::MTLogicTV3(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 2",
      MTLogic_Make,
      index)
{
}


void MTLogicTV3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  // Again, I can't find the correct device code...
  threadableProtocol = new RC5Protocol(guiObject, index, 0x00);

  addKey("0", Zero_Key, 0x00, 6);
  addKey("1", One_Key, 0x01, 6);
  addKey("2", Two_Key, 0x02, 6);
  addKey("3", Three_Key, 0x03, 6);
  addKey("4", Four_Key, 0x04, 6);
  addKey("5", Five_Key, 0x05, 6);
  addKey("6", Six_Key, 0x06, 6);
  addKey("7", Seven_Key, 0x07, 6);
  addKey("8", Eight_Key, 0x08, 6);
  addKey("9", Nine_Key, 0x09, 6);
  addKey("Power", Power_Key, 0x0C, 6);
  addKey("Mute", Mute_Key, 0x0D, 6);
  addKey("Volume +", VolumeUp_Key, 0x10, 6);
  addKey("Volume -", VolumeDown_Key, 0x11, 6);
  addKey("Arrow_Right", Right_Key, 0x12, 6);
  addKey("Arrow_Left", Left_Key, 0x13, 6);
  addKey("-/--", DoubleDigit_Key, 0x14, 6);
  addKey("Info/Display", Info_Key, 0x15, 6);
  addKey("Arrow_Up", Up_Key, 0x16, 6);
  addKey("Arrow_Down", Down_Key, 0x17, 6);
  addKey("Menu", Menu_Key, 0x19, 6);
  addKey("CH+", ChannelUp_Key, 0x20, 6);
  addKey("CH-", ChannelDown_Key, 0x21, 6);
  addKey("Last/Prev Ch", PrevChannel_Key, 0x22, 6);
  addKey("FAV", Favorites_Key, 0x23, 6);
//  addKey("Record", Record_Key, 0x23, 6);
// Pause, 0x29
// FFWD, 0x29
// Play, 0x2B
// Stop, 0x2B
// Rewind, 0x2B
  addKey("Yellow", Yellow_Key, 0x32, 6);
  addKey("Record", Record_Key, 0x33, 6);
  addKey("Blue", Blue_Key, 0x34, 6);
  addKey("OK/Select", Select_Key, 0x35, 6);
  addKey("Green", Green_Key, 0x36, 6);
  addKey("Red", Red_Key, 0x37, 6);
  addKey("Input/Source", Input_Key, 0x38, 6); // "TV/Video"
// Rewind, 0x3C
// Skip -, 0x3C
// Play, 0x3F
// FFWD, 0x3F
// Skip +, 0x3F
}
*/
