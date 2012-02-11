#include "logitech.h"
#include "protocols/necprotocol.h"

LogitechSpeakers::LogitechSpeakers(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Digital Speakers Keyset",
      Logitech_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x08, 8);

  addKey("surround+", RearVolumeUp_Key, 0x00, 8);
  addKey("sub-", WooferDown_Key, 0x01, 8);
  addKey("center+", CenterVolumeUp_Key, 0x02, 8);
  addKey("sub+", WooferUp_Key, 0x03, 8);
  addKey("surround-", RearVolumeDown_Key, 0x04, 8);
  addKey("test", Unmapped_Key, 0x05, 8);
  addKey("center-", CenterVolumeDown_Key, 0x06, 8);
  addKey("direct", PCInput_Key, 0x0A, 8);
  addKey("optical", OpticalInput_Key, 0x0B, 8);
  addKey("coax", DigitalCoaxInput_Key, 0x0C, 8);
  addKey("vol-", VolumeDown_Key, 0x0E, 8);
  addKey("power", Power_Key, 0x10, 8);
  addKey("mute", Mute_Key, 0x16, 8);
  addKey("effect", Red_Key, 0x1D, 8);
  addKey("settings", Blue_Key, 0x1F, 8);
  addKey("vol+", VolumeUp_Key, 0x1A, 8);
}
