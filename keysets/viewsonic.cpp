#include "viewsonic.h"
#include "protocols/necprotocol.h"

ViewsonicProjector1::ViewsonicProjector1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Projector Keyset 1",
      Viewsonic_Make,
      index)
{
  addControlledDevice(Viewsonic_Make, "PJ750", Other_Device);
}


void ViewsonicProjector1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x4587, 16);

  addKey("power", Power_Key, 0x17, 8);
  addKey("RGB", Unmapped_Key, 0x18, 8);
  addKey("video", PictureMode_Key, 0x19, 8);
  addKey("menu", Menu_Key, 0x20, 8);
  addKey("select", Select_Key, 0x21, 8);
  addKey("reset", Reset_Key, 0x22, 8);
  addKey("auto", Unmapped_Key, 0x24, 8);
  addKey("up", Up_Key, 0x28, 8);
  addKey("right", Right_Key, 0x2A, 8);
  addKey("down", Down_Key, 0x2C, 8);
  addKey("left", Left_Key, 0x2E, 8);
  addKey("position", Unmapped_Key, 0x30, 8);
  addKey("blank screen", Unmapped_Key, 0x41, 8);
  addKey("vol-", VolumeDown_Key, 0x50, 8);
  addKey("vol+", VolumeUp_Key, 0x51, 8);
  addKey("mute", Mute_Key, 0x52, 8);
  addKey("magnify+", Unmapped_Key, 0xB1, 8);
  addKey("magnify-", Unmapped_Key, 0xB2, 8);
  addKey("magnify off", Unmapped_Key, 0xB3, 8);
  addKey("freeze", Pause_Key, 0xB4, 8);
  addKey("keystone", Unmapped_Key, 0xB6, 8);
}


ViewsonicProjector2::ViewsonicProjector2(
  unsigned int index)
  : PIRKeysetMetaData(
      "Projector Keyset 2",
      Viewsonic_Make,
      index)
{
  addControlledDevice(Viewsonic_Make, "PJ250", Other_Device);
}


void ViewsonicProjector2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x1586, 16);

  addKey("7", Seven_Key, 0x03, 8);
  addKey("Video", AuxInput_Key, 0x03, 8);
  addKey("5", Five_Key, 0x04, 8);
  addKey("RGB", ComponentInput_Key, 0x04, 8);
  addKey("4", Four_Key, 0x05, 8);
  addKey("Digital", PCInput_Key, 0x05, 8);
  addKey("tv/vcr", Input_Key, 0x06, 8);
  addKey("Power On", Power_Key, 0x08, 8);
  addKey("0", Zero_Key, 0x10, 8);
  addKey("Aspect", AspectRatio_Key, 0x10, 8);
  addKey("sleep", Sleep_Key, 0x14, 8);
  addKey("select", Select_Key, 0x17, 8);
  addKey("exit", Exit_Key, 0x25, 8);
  addKey("9", Nine_Key, 0x2B, 8);
  addKey("YCbCr", Unmapped_Key, 0x2B, 8);
  addKey("6", Six_Key, 0x2C, 8);
  addKey("YPbPr", Unmapped_Key, 0x2C, 8);
  addKey("pip on/off", PIP_Key, 0x30, 8);
  addKey("1", One_Key, 0x32, 8);
  addKey("Horiz Keystone", Unmapped_Key, 0x32, 8);
  addKey("enter", Enter_Key, 0x34, 8);
  addKey("Menu", Menu_Key, 0x46, 8);
  addKey("Mute", Mute_Key, 0x47, 8);
  addKey("last/prev ch", PrevChannel_Key, 0x48, 8);
  addKey("L-", Unmapped_Key, 0x4C, 8);
  addKey("Freeze", Pause_Key, 0x4C, 8);
  addKey("right arrow", Right_Key, 0x5C, 8);
  addKey("left arrow", Left_Key, 0x5D, 8);
  addKey("up arrow", Up_Key, 0x5E, 8);
  addKey("down arrow", Down_Key, 0x5F, 8);
  addKey("L+", Unmapped_Key, 0x89, 8);
  addKey("Zoom", Zoom_Key, 0x89, 8);
  addKey("3", Three_Key, 0x8B, 8);
  addKey("Vert Keystone", Unmapped_Key, 0x8B, 8);
  addKey("8", Eight_Key, 0xC6, 8);
  addKey("S-Video", SVideoInput_Key, 0xC6, 8);
  addKey("Increase (+)", Unmapped_Key, 0xDE, 8);
  addKey("Decrease (-)", Unmapped_Key, 0xDF, 8);
}
