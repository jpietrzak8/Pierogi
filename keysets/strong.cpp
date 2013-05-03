#include "strong.h"
#include "protocols/necprotocol.h"
#include "protocols/recs80protocol.h"

StrongSat1::StrongSat1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Sat Receiver Keyset 1",
      Strong_Make,
      index)
{
  addControlledDevice(Strong_Make, "ZapBox", Sat_Device);
}


void StrongSat1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x7780, 16);

  addKey("POWER", Power_Key, 0x16, 8);
  addKey("MODE", Mode_Key, 0x11, 8);
  addKey("MUTE", Mute_Key, 0x1C, 8);
  addKey("TV/SAT", Input_Key, 0x1A, 8);
  addKey("EPG", Guide_Key, 0x0E, 8);
  addKey("TV/RADIO", TunerInput_Key, 0x1E, 8);
  addKey("PAGE-", ChannelDown_Key, 0x0C, 8);
  addKey("INFO", Info_Key, 0x1B, 8);
  addKey("PAGE+", ChannelUp_Key, 0x14, 8);
  addKey("EXIT", Exit_Key, 0x0F, 8);
  addKey("MENU", Menu_Key, 0x07, 8);
  addKey("vol up", VolumeUp_Key, 0x10, 8); // might be down instead
  addKey("vol down", VolumeDown_Key, 0x19, 8); // might be up instead
  addKey("UP", Up_Key, 0x12, 8);
  addKey("DOWN", Down_Key, 0x13, 8);
  addKey("LEFT", Left_Key, 0x15, 8);
  addKey("RIGHT", Right_Key, 0x17, 8);
  addKey("OK", Select_Key, 0x0B, 8);
  addKey("enter", Enter_Key, 0x0B, 8);
  addKey("1", One_Key, 0x00, 8);
  addKey("2", Two_Key, 0x01, 8);
  addKey("3", Three_Key, 0x02, 8);
  addKey("4", Four_Key, 0x04, 8);
  addKey("5", Five_Key, 0x05, 8);
  addKey("6", Six_Key, 0x06, 8);
  addKey("7", Seven_Key, 0x08, 8);
  addKey("8", Eight_Key, 0x09, 8);
  addKey("9", Nine_Key, 0x0A, 8);
  addKey("0", Zero_Key, 0x0D, 8);
  addKey("HELP", Unmapped_Key, 0x03, 8); // Might be info key
  addKey("RED", Red_Key, 0x40, 8);
  addKey("GREEN", Green_Key, 0x1D, 8);
  addKey("YELLOW", Yellow_Key, 0x1F, 8);
  addKey("BLUE", Blue_Key, 0x41, 8);
}


StrongSat2::StrongSat2(
  unsigned int index)
  : PIRKeysetMetaData(
      "Sat Receiver Keyset 2",
      Strong_Make,
      index)
{
  addControlledDevice(Strong_Make, "SRT-4620", Sat_Device);
}


void StrongSat2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x01, 8);

  addKey("power", Power_Key, 0x00, 8);
  addKey("1", One_Key, 0x01, 8);
  addKey("2", Two_Key, 0x02, 8);
  addKey("mute", Mute_Key, 0x03, 8);
  addKey("4", Four_Key, 0x04, 8);
  addKey("5", Five_Key, 0x05, 8);
  addKey("3", Three_Key, 0x06, 8);
  addKey("6", Six_Key, 0x07, 8);
  addKey("7", Seven_Key, 0x08, 8);
  addKey("8", Eight_Key, 0x0A, 8);
  addKey("9", Nine_Key, 0x0B, 8);
  addKey("tv/Radio", TunerInput_Key, 0x0C, 8);
  addKey("0", Zero_Key, 0x0E, 8);
  addKey("TV/Sat", Input_Key, 0x0F, 8);
  addKey("menu", Menu_Key, 0x10, 8);
  addKey("exit", Exit_Key, 0x11, 8);
  addKey("select", Select_Key, 0x12, 8);
  addKey("channel", Unmapped_Key, 0x13, 8); // Not sure
  addKey("vol down", VolumeDown_Key, 0x14, 8);
  addKey("left arrow", Left_Key, 0x14, 8);
  addKey("channel up", ChannelUp_Key, 0x15, 8);
  addKey("up arrow", Up_Key, 0x15, 8);
  addKey("channel down", ChannelDown_Key, 0x16, 8);
  addKey("down arrow", Down_Key, 0x16, 8);
  addKey("vol up", VolumeUp_Key, 0x17, 8);
  addKey("right arrow", Right_Key, 0x17, 8);
  addKey("program guide", Guide_Key, 0x18, 8);
  addKey("display", Info_Key, 0x19, 8);
  addKey("audio", Audio_Key, 0x1A, 8);
  addKey("white", Unmapped_Key, 0x41, 8);
  addKey("orange", Unmapped_Key, 0x42, 8);
  addKey("red", Red_Key, 0x44, 8);
  addKey("green", Green_Key, 0x45, 8);
  addKey("yellow", Yellow_Key, 0x46, 8);
  addKey("blue", Blue_Key, 0x47, 8);
}


StrongSat3::StrongSat3(
  unsigned int index)
  : PIRKeysetMetaData(
      "Sat Receiver Keyset 3",
      Strong_Make,
      index)
{
  addControlledDevice(Strong_Make, "SRT-6410", Sat_Device);
}


void StrongSat3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x0202, 16);

  addKey("0", Zero_Key, 0x00, 8);
  addKey("1", One_Key, 0x01, 8);
  addKey("2", Two_Key, 0x02, 8);
  addKey("3", Three_Key, 0x03, 8);
  addKey("4", Four_Key, 0x04, 8);
  addKey("5", Five_Key, 0x05, 8);
  addKey("6", Six_Key, 0x06, 8);
  addKey("7", Seven_Key, 0x07, 8);
  addKey("8", Eight_Key, 0x08, 8);
  addKey("9", Nine_Key, 0x09, 8);
  addKey("power", Power_Key, 0x0A, 8);
  addKey("up arrow", Up_Key, 0x0B, 8);
  addKey("ZOOM", Zoom_Key, 0x0C, 8);
  addKey("select", Select_Key, 0x0D, 8);
  addKey("down arrow", Down_Key, 0x0E, 8);
  addKey("right arrow", Right_Key, 0x10, 8);
  addKey("left arrow", Left_Key, 0x11, 8);
  addKey("AV", Input_Key, 0x12, 8);
  addKey("red", Red_Key, 0x14, 8);
  addKey("channel up", Up_Key, 0x15, 8);
  addKey("menu", Menu_Key, 0x16, 8);
  addKey("green", Green_Key, 0x17, 8);
  addKey("channel down", Down_Key, 0x18, 8);
  addKey("mute", Mute_Key, 0x19, 8);
  addKey("LIST", Unmapped_Key, 0x1A, 8);
  addKey("program guide", Guide_Key, 0x1B, 8);
  addKey("AUDIO", Audio_Key, 0x1C, 8);
  addKey("yellow", Yellow_Key, 0x1D, 8);
  addKey("exit", Exit_Key, 0x1F, 8);
  addKey("MOSAIC", PIP_Key, 0x40, 8);
  addKey("vol up", VolumeUp_Key, 0x41, 8);
  addKey("vol down", VolumeDown_Key, 0x42, 8);
  addKey("blue", Blue_Key, 0x43, 8);
  addKey("INFO", Info_Key, 0x44, 8);
  addKey("TV/R", TunerInput_Key, 0x45, 8);
}


StrongSat4::StrongSat4(
  unsigned int index)
  : PIRKeysetMetaData(
      "Sat Receiver Keyset 4",
      Strong_Make,
      index)
{
  addControlledDevice(Strong_Make, "SRT-5430", Sat_Device);
}


void StrongSat4::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x00, 8);

  addKey("Mute", Mute_Key, 0x00, 8);
  addKey("Language", Audio_Key, 0x01, 8);
  addKey("exit", Exit_Key, 0x03, 8);
  addKey("Play", Play_Key, 0x04, 8);
  addKey("num_3", Three_Key, 0x05, 8);
  addKey("Select", Select_Key, 0x06, 8);
  addKey("Guide", Guide_Key, 0x07, 8);
  addKey("Stop", Stop_Key, 0x08, 8);
  addKey("num_2", Two_Key, 0x09, 8);
  addKey("Pause", Pause_Key, 0x0A, 8);
  addKey("Aspect", AspectRatio_Key, 0x0B, 8);
  addKey("Power", Power_Key, 0x0C, 8);
  addKey("num_1", One_Key, 0x0D, 8);
  addKey("Menu", Menu_Key, 0x0F, 8);
  addKey("ffwd", FastForward_Key, 0x10, 8);
  addKey("Page+", PageUp_Key, 0x14, 8);
  addKey("Page-", PageDown_Key, 0x18, 8);
  addKey("Skip+", Next_Key, 0x1C, 8);
  addKey("VOL+", VolumeUp_Key, 0x40, 8);
  addKey("right_arrow", Right_Key, 0x40, 8);
  addKey("Info", Info_Key, 0x41, 8);
  addKey("Media", Unmapped_Key, 0x42, 8);
  addKey("TV/Radio", TunerInput_Key, 0x43, 8);
  addKey("CH+", ChannelUp_Key, 0x44, 8);
  addKey("up_arrow", Up_Key, 0x44, 8);
  addKey("Last_ch", PrevChannel_Key, 0x45, 8);
  addKey("num_9", Nine_Key, 0x46, 8);
  addKey("num_6", Six_Key, 0x47, 8);
  addKey("CH-", ChannelDown_Key, 0x48, 8);
  addKey("down_arrow", Down_Key, 0x48, 8);
  addKey("num_0", Zero_Key, 0x49, 8);
  addKey("num_8", Eight_Key, 0x4A, 8);
  addKey("num_5", Five_Key, 0x4B, 8);
  addKey("VOL-", VolumeDown_Key, 0x4C, 8);
  addKey("left_arrow", Left_Key, 0x4C, 8);
  addKey("Fav", Favorites_Key, 0x4D, 8);
  addKey("num_7", Seven_Key, 0x4E, 8);
  addKey("num_4", Four_Key, 0x4F, 8);
  addKey("V.Mode", PictureMode_Key, 0x50, 8);
  addKey("Goto", Unmapped_Key, 0x51, 8);
  addKey("Red", Red_Key, 0x52, 8);
  addKey("Zoom", Zoom_Key, 0x54, 8);
  addKey("Repeat", Repeat_Key, 0x55, 8);
  addKey("Green", Green_Key, 0x56, 8);
  addKey("rewind", Rewind_Key, 0x57, 8);
  addKey("Subtitle", Captions_Key, 0x58, 8);
  addKey("TimeShift", Unmapped_Key, 0x59, 8);
  addKey("Yellow", Yellow_Key, 0x5A, 8);
  addKey("Skip-", Previous_Key, 0x5B, 8);
  addKey("List", Unmapped_Key, 0x5C, 8);
  addKey("Scan", Unmapped_Key, 0x5D, 8);
  addKey("Blue", Blue_Key, 0x5E, 8);
  addKey("Record", Record_Key, 0x5F, 8);
}


StrongDVBT1::StrongDVBT1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVB-T Receiver Keyset 1",
      Strong_Make,
      index)
{
}


void StrongDVBT1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new RECS80Protocol(guiObject, index);

  setPreData(0x5, 3);

  addKey("display/info", Info_Key, 0x14, 6);
  addKey("fav", Favorites_Key, 0x15, 6);
  addKey("sub", Captions_Key, 0x16, 6);
  addKey("mute", Mute_Key, 0x18, 6);
  addKey("red", Red_Key, 0x19, 6);
  addKey("8", Eight_Key, 0x1C, 6);
  addKey("4", Four_Key, 0x1D, 6);
  addKey("power", Power_Key, 0x1E, 6);
  addKey("pause", Pause_Key, 0x20, 6);
  addKey("vol up", VolumeUp_Key, 0x21, 6);
  addKey("right arrow", Right_Key, 0x21, 6);
  addKey("yellow", Yellow_Key, 0x22, 6);
  addKey("7", Seven_Key, 0x24, 6);
  addKey("3", Three_Key, 0x25, 6);
  addKey("menu", Menu_Key, 0x27, 6);
  addKey("channel up", ChannelUp_Key, 0x28, 6);
  addKey("up arrow", Up_Key, 0x28, 6);
  addKey("ok", Select_Key, 0x29, 6);
  addKey("channel down", ChannelDown_Key, 0x2A, 6);
  addKey("down arrow", Down_Key, 0x2A, 6);
  addKey("0", Zero_Key, 0x2B, 6);
  addKey("6", Six_Key, 0x2C, 6);
  addKey("2", Two_Key, 0x2D, 6);
  addKey("list", Unmapped_Key, 0x2E, 6);
  addKey("epg", Guide_Key, 0x2F, 6);
  addKey("exit", Exit_Key, 0x30, 6);
  addKey("vol down", VolumeDown_Key, 0x31, 6);
  addKey("left arrow", Left_Key, 0x31, 6);
  addKey("green", Green_Key, 0x32, 6);
  addKey("9", Nine_Key, 0x33, 6);
  addKey("5", Five_Key, 0x34, 6);
  addKey("1", One_Key, 0x35, 6);
  addKey("blue", Blue_Key, 0x37, 6);
}
