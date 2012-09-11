#include "creative.h"
#include "protocols/necprotocol.h"


CreativeAudio1::CreativeAudio1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Speakers Keyset 1",
      Creative_Make,
      index)
{
  addControlledDevice(Creative_Make, "Inspire 5700", Other_Device);
}


void CreativeAudio1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x44C1, 16);

  addKey("Input Select", Input_Key, 0x37, 8);
  addKey("vol up", VolumeUp_Key, 0x47, 8);
  addKey("Dynamic Mode Toggle", Red_Key, 0x4F, 8); // hack
  addKey("mute", Mute_Key, 0x77, 8);
  addKey("power", Power_Key, 0x87, 8);
  addKey("Dolby", NoiseReduction_Key, 0xA7, 8);
  addKey("Dolby", Blue_Key, 0xA7, 8); // hack
  addKey("vol down", VolumeDown_Key, 0xC7, 8);
  addKey("Analog on/off", Green_Key, 0xD7, 8); // hack
  addKey("Effect Select", Yellow_Key, 0xF2, 8); // hack

  addKey("rear_center", Unmapped_Key, 0x17, 8);
  addKey("center", Unmapped_Key, 0x97, 8);
  addKey("test", Unmapped_Key, 0xF7, 8);
  addKey("rear", Unmapped_Key, 0xE7, 8);
  addKey("subwoofer", Unmapped_Key, 0x67, 8);
  addKey("coaxial", Unmapped_Key, 0x27, 8);
  addKey("optical", Unmapped_Key, 0x0F, 8);
  addKey("stereo", Unmapped_Key, 0x2F, 8);
  addKey("dolby_digital_ex", Unmapped_Key, 0xCF, 8);
  addKey("ned_6", Unmapped_Key, 0xB7, 8);
}


CreativeAudio2::CreativeAudio2(
  unsigned int index)
  : PIRKeysetMetaData(
      "MP3 Player Keyset 1",
      Creative_Make,
      index)
{
}

void CreativeAudio2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  // This is almost possible to integrate with CreativeMisc1, if needed
  setPreData(0xAC21, 16);

  addKey("POWER", Power_Key, 0x20, 8);
  addKey("PLAY_PAUSE", Play_Key, 0x40, 8);
  addKey("PLAY_PAUSE", Pause_Key, 0x40, 8);
  addKey("FAST_REVERSE", Rewind_Key, 0xA0, 8);
  addKey("FAST_FORWARD", FastForward_Key, 0xE0, 8);
  addKey("STOP", Stop_Key, 0x50, 8);
  addKey("EAX", Red_Key, 0xB0, 8);
  addKey("VOLUME_UP", VolumeUp_Key, 0xF0, 8);
  addKey("VOLUME_DOWN", VolumeDown_Key, 0x70, 8);
}


CreativeMisc1::CreativeMisc1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Infra Keyset",
      Creative_Make,
      index)
{
}


void CreativeMisc1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0xAC21, 16);

  addKey("PAUSE", Pause_Key, 0x80, 8);
  addKey("PLAY", Play_Key, 0x40, 8);
  addKey("STOP", Stop_Key, 0xC0, 8);
  addKey("REW", Rewind_Key, 0xA0, 8);
  addKey("PREV", Previous_Key, 0x60, 8);
  addKey("FF", FastForward_Key, 0xE0, 8);
  addKey("MENU", Menu_Key, 0x20, 8);
  addKey("MOUSE", Unmapped_Key, 0x10, 8);
  addKey("1", One_Key, 0x90, 8);
  addKey("2", Two_Key, 0x50, 8);
  addKey("3", Three_Key, 0xD0, 8);
  addKey("4", Four_Key, 0xB0, 8);
  addKey("5", Five_Key, 0x70, 8);
  addKey("6", Six_Key, 0xF0, 8);
  addKey("7", Seven_Key, 0x88, 8);
  addKey("8", Eight_Key, 0x48, 8);
  addKey("9", Nine_Key, 0xC8, 8);
  addKey("0", Zero_Key, 0x68, 8);
  addKey("MUTE", Mute_Key, 0x30, 8);
  addKey("VOL_UP", VolumeUp_Key, 0x08, 8);
  addKey("VOL_DOWN", VolumeDown_Key, 0x28, 8);
  addKey("SHIFT", Unmapped_Key, 0xA8, 8);
  addKey("ENTER", Enter_Key, 0xE8, 8);
  addKey("ZOOM", Zoom_Key, 0x18, 8);
}

