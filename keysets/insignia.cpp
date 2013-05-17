#include "insignia.h"

#include "protocols/necprotocol.h"
#include "protocols/necxprotocol.h"
#include "protocols/recs80protocol.h"
#include "protocols/aiwaprotocol.h"


InsigniaTV1::InsigniaTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Insignia_Make,
      index)
{
}


void InsigniaTV1::populateProtocol(
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
  addKey("POWER", Power_Key, 0x0F, 8);
  addKey("PREV", PrevChannel_Key, 0x10, 8);
  addKey("TV/VCR", Input_Key, 0x12, 8);
  addKey("SLEEP", Sleep_Key, 0x13, 8);
  addKey("MENU", Menu_Key, 0x14, 8);
  addKey("Arrow UP", Up_Key, 0x15, 8);
  addKey("Arrow DOWN", Down_Key, 0x16, 8);
  addKey("INFO", Info_Key, 0x17, 8);
  addKey("SELECT", Select_Key, 0x18, 8);
}


InsigniaTV2::InsigniaTV2(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 2",
      Insignia_Make,
      index)
{
}


void InsigniaTV2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new AiwaProtocol(guiObject, index);

  setPreData(0x011A, 13);

  addKey("PICTURE ADJUST MENU", PictureMode_Key, 0x01, 8);
  addKey("DISPLAY", Info_Key, 0x02, 8);
  addKey("PREVIOUS CHANNEL", PrevChannel_Key, 0x03, 8);
  addKey("VOL+", VolumeUp_Key, 0x04, 8);
  addKey("CCD", Captions_Key, 0x06, 8);
  addKey("MENU", Menu_Key, 0x08, 8);
  addKey("CH-", ChannelDown_Key, 0x09, 8);
  addKey("POWER", Power_Key, 0x0A, 8);
  addKey("SLEEP", Sleep_Key, 0x0B, 8);
  addKey("AV/SOURCE", Input_Key, 0x0C, 8);
  addKey("MUTE", Mute_Key, 0x0D, 8);
  addKey("AIR/CABLE", AntennaInput_Key, 0x0E, 8);
  addKey("PICTURE PRESETS", Unmapped_Key, 0x0F, 8);
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
  addKey("CH+", ChannelUp_Key, 0x1B, 8);
  addKey("VOL-", VolumeDown_Key, 0x1D, 8);
  addKey("PARENTAL CONTROL", Unmapped_Key, 0x1E, 8);
}


InsigniaTV3::InsigniaTV3(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 3",
      Insignia_Make,
      index)
{
}


void InsigniaTV3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0xD900, 16);

  addKey("mute", Mute_Key, 0x06, 8);
  addKey("select", Select_Key, 0x08, 8);
  addKey("1", One_Key, 0x09, 8);
  addKey("4", Four_Key, 0x0D, 8);
  addKey("7", Seven_Key, 0x11, 8);
  addKey("0", Zero_Key, 0x12, 8);
  addKey("8", Eight_Key, 0x15, 8);
  addKey("enter", Enter_Key, 0x16, 8);
  addKey("9", Nine_Key, 0x17, 8);
  addKey("5", Five_Key, 0x19, 8);
  addKey("6", Six_Key, 0x1B, 8);
  addKey("power", Power_Key, 0x1C, 8);
  addKey("2", Two_Key, 0x1D, 8);
  addKey("3", Three_Key, 0x1F, 8);
  addKey("last/prev ch", PrevChannel_Key, 0x40, 8);
  addKey("tv/vcr", Input_Key, 0x43, 8);
  addKey("vol down", VolumeDown_Key, 0x47, 8);
  addKey("vol up", VolumeUp_Key, 0x48, 8);
  addKey("menu", Menu_Key, 0x4A, 8);
  addKey("display/info", Info_Key, 0x4E, 8);
  addKey("channel up", ChannelUp_Key, 0x4F, 8);
  addKey("channel down", ChannelDown_Key, 0x52, 8);
  addKey("up arrow", Up_Key, 0x5C, 8);
  addKey("down arrow", Down_Key, 0x5D, 8);
  addKey("left arrow", Left_Key, 0x5E, 8);
  addKey("right arrow", Right_Key, 0x5F, 8);
}


InsigniaDVD1::InsigniaDVD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Insignia_Make,
      index)
{
}


void InsigniaDVD1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x4743, 16);

  addKey("tray", Eject_Key, 0x2E, 8);
  addKey("source", Input_Key, 0x21, 8);
  addKey("power", Power_Key, 0x2F, 8);
  addKey("1", One_Key, 0x01, 8);
  addKey("2", Two_Key, 0x02, 8);
  addKey("3", Three_Key, 0x03, 8);
  addKey("4", Four_Key, 0x04, 8);
  addKey("5", Five_Key, 0x05, 8);
  addKey("6", Six_Key, 0x06, 8);
  addKey("7", Seven_Key, 0x07, 8);
  addKey("8", Eight_Key, 0x08, 8);
  addKey("9", Nine_Key, 0x09, 8);
  addKey("setup", Menu_Key, 0x26, 8);
  addKey("0", Zero_Key, 0x00, 8);
  addKey("bs", Unmapped_Key, 0x29, 8);
  addKey("left1", Unmapped_Key, 0x15, 8);
  addKey("up", Up_Key, 0x11, 8);
  addKey("right1", Unmapped_Key, 0x18, 8); // "right-all"
  addKey("right1", Unmapped_Key, 0x16, 8);
  addKey("left", Unmapped_Key, 0x12, 8);
  addKey("ok", Select_Key, 0x10, 8);
  addKey("right", Unmapped_Key, 0x13, 8);
  addKey("left-all", Unmapped_Key, 0x17, 8);
  addKey("down", Down_Key, 0x14, 8);
  addKey("select", Unmapped_Key, 0x2B, 8);
  addKey("voldn", VolumeDown_Key, 0x0D, 8);
  addKey("volup", VolumeUp_Key, 0x0C, 8);
  addKey("mute", Mute_Key, 0x1C, 8);
  addKey("memory", Unmapped_Key, 0x1B, 8);
  addKey("play", Play_Key, 0x0E, 8);
  addKey("stop", Stop_Key, 0x0F, 8);
  addKey("sleep", Sleep_Key, 0x2A, 8);
  addKey("prog", Unmapped_Key, 0x24, 8);
  addKey("repeat", Repeat_Key, 0x36, 8);
  addKey("A-B", RepeatAB_Key, 0x37, 8);
  addKey("menu", DiscMenu_Key, 0x0A, 8);
  addKey("return-title", DiscTitle_Key, 0x25, 8);
  addKey("surround", Surround_Key, 0x32, 8);
  addKey("eq", Unmapped_Key, 0x34, 8);
  addKey("language", Audio_Key, 0x28, 8);
  addKey("subtitle", Captions_Key, 0x2D, 8);
  addKey("zoom", Zoom_Key, 0x1A, 8);
  addKey("angle", Angle_Key, 0x19, 8);
  addKey("goto", Unmapped_Key, 0x23, 8);
  addKey("display", Info_Key, 0x22, 8);
  addKey("night", Unmapped_Key, 0x30, 8);
  addKey("dim", Unmapped_Key, 0x31, 8);
}


InsigniaDVD2::InsigniaDVD2(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 2",
      Insignia_Make,
      index)
{
}


void InsigniaDVD2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new RECS80Protocol(guiObject, index);

  setPreData(0x5, 3);

  addKey("Tuner", TunerInput_Key, 0x0C, 6);
  addKey("Surround", Surround_Key, 0x0D, 6);
  addKey("Tone", Unmapped_Key, 0x0E, 6);
  addKey("GOTO", Unmapped_Key, 0x10, 6);
  addKey("Subtitle", Captions_Key, 0x11, 6);
  addKey("Zoom/Clear", Zoom_Key, 0x12, 6);
  addKey("A-B", RepeatAB_Key, 0x13, 6);
  addKey("V-Select", Unmapped_Key, 0x14, 6);
  addKey("f.rew/prev track", Rewind_Key, 0x15, 6);
  addKey("f.fwd/next track", FastForward_Key, 0x16, 6);
  addKey("menu", DiscMenu_Key, 0x17, 6);
  addKey("mute", Mute_Key, 0x18, 6);
  addKey("play", Play_Key, 0x19, 6);
  addKey("pause", Pause_Key, 0x1A, 6);
  addKey("Av Select", Unmapped_Key, 0x1B, 6);
  addKey("8", Eight_Key, 0x1C, 6);
  addKey("4", Four_Key, 0x1D, 6);
  addKey("power", Power_Key, 0x1E, 6);
  addKey("Bookmark", Unmapped_Key, 0x1F, 6);
  addKey("Info", Info_Key, 0x20, 6);
  addKey("right arrow", Right_Key, 0x21, 6);
  addKey("stop", Stop_Key, 0x22, 6);
  addKey("7", Seven_Key, 0x24, 6);
  addKey("3", Three_Key, 0x25, 6);
  addKey("Eject", Eject_Key, 0x26, 6);
  addKey("Title/Rotate", DiscTitle_Key, 0x27, 6);
  addKey("up arrow", Up_Key, 0x28, 6);
  addKey("select", Select_Key, 0x29, 6);
  addKey("down arrow", Down_Key, 0x2A, 6);
  addKey("0", Zero_Key, 0x2B, 6);
  addKey("6", Six_Key, 0x2C, 6);
  addKey("2", Two_Key, 0x2D, 6);
  addKey("Angle/PBC", Angle_Key, 0x2E, 6);
  addKey("Audio FM ST", TunerInput_Key, 0x2F, 6);
  addKey("exit", Exit_Key, 0x30, 6);
  addKey("left arrow", Left_Key, 0x31, 6);
  addKey("fast fwd", FastForward_Key, 0x32, 6);
  addKey("9", Nine_Key, 0x33, 6);
  addKey("5", Five_Key, 0x34, 6);
  addKey("1", One_Key, 0x35, 6);
  addKey("Playmode", Unmapped_Key, 0x36, 6);
  addKey("rewind", Rewind_Key, 0x37, 6);
  addKey("sleep", Sleep_Key, 0x38, 6);
  addKey("DVD/Disc Skip", Input_Key, 0x39, 6);
  addKey("vol up", VolumeUp_Key, 0x3A, 6);
  addKey("vol down", VolumeDown_Key, 0x3B, 6);
}


InsigniaDVD3::InsigniaDVD3(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 3",
      Insignia_Make,
      index)
{
}


void InsigniaDVD3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECXProtocol(guiObject, index, true);

  setPreData(0x2D2D, 16);

  addKey("channel up", ChannelUp_Key, 0x00, 8);
  addKey("channel down", ChannelDown_Key, 0x01, 8);
  addKey("vol up", VolumeUp_Key, 0x02, 8);
  addKey("vol down", VolumeDown_Key, 0x03, 8);
  addKey("power", Power_Key, 0x30, 8);
  addKey("play", Play_Key, 0x31, 8);
  addKey("rewind", Rewind_Key, 0x32, 8);
  addKey("fast fwd", FastForward_Key, 0x33, 8);
  addKey("skip fwd", Next_Key, 0x34, 8);
  addKey("skip bkwd", Previous_Key, 0x35, 8);
  addKey("eject open/close", Eject_Key, 0x36, 8);
  addKey("pause", Pause_Key, 0x38, 8);
  addKey("stop", Stop_Key, 0x39, 8);
  addKey("display", Info_Key, 0x3A, 8);
  addKey("1", One_Key, 0x3B, 8);
  addKey("2", Two_Key, 0x3C, 8);
  addKey("3", Three_Key, 0x3D, 8);
  addKey("4", Four_Key, 0x3E, 8);
  addKey("5", Five_Key, 0x3F, 8);
  addKey("6", Six_Key, 0x40, 8);
  addKey("7", Seven_Key, 0x41, 8);
  addKey("8", Eight_Key, 0x42, 8);
  addKey("9", Nine_Key, 0x43, 8);
  addKey("0", Zero_Key, 0x44, 8);
  addKey("return", Exit_Key, 0x45, 8);
  addKey("up arrow", Up_Key, 0x47, 8);
  addKey("down arrow", Down_Key, 0x48, 8);
  addKey("disc menu/list", Unmapped_Key, 0x4B, 8);
  addKey("subtitle", Captions_Key, 0x50, 8);
  addKey("enter", Select_Key, 0x58, 8);
  addKey("left arrow", Left_Key, 0x59, 8);
  addKey("right arrow", Right_Key, 0x5A, 8);
  addKey("home", Unmapped_Key, 0x67, 8);
  addKey("dubbing", Unmapped_Key, 0x68, 8);
  addKey("input", Input_Key, 0xB0, 8);
  addKey("l.skip", Unmapped_Key, 0xB5, 8);
  addKey("record", Record_Key, 0xB6, 8);
  addKey("tv/vcr", AntennaInput_Key, 0xBE, 8);
  addKey("dvd", DVDInput_Key, 0xF1, 8);
  addKey("vcr", VCRInput_Key, 0xF3, 8);
}
