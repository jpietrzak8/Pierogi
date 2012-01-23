#include "apple.h"
#include "necprotocol.h"
#include "pirmakenames.h"

// Based on LIRC Apple_A1156 config file
AppleWhiteRemote::AppleWhiteRemote(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "White Remote",
      Apple_Make,
      index)
{
  addControlledDevice(Apple_Make, "Mac Mini", Computer_Device);

  // Set up the threadable object:
  threadableProtocol = new NECProtocol(guiObject, index);

  setPreData(0x77e1, 16);
  setPostData(0xc5, 8);

// Menu oriented:
  addKey("menu", Menu_Key, 0x40, 8);
  addKey("+", Up_Key, 0xD0, 8);
  addKey("-", Down_Key, 0xB0, 8);
  addKey("|<<", Left_Key, 0x10, 8);
  addKey(">>|", Right_Key, 0xE0, 8);
  addKey(">||", Select_Key, 0x20, 8);

// Media oriented:
  addKey("+", VolumeUp_Key, 0xD0, 8);
  addKey("-", VolumeDown_Key, 0xB0, 8);
  addKey("|<<", Rewind_Key, 0x10, 8);
  addKey(">>|", FastForward_Key, 0xE0, 8);
  addKey(">||", Play_Key, 0x20, 8);
  addKey(">||", Pause_Key, 0x20, 8);
  addKey("|<<", Previous_Key, 0x10, 8);
  addKey(">>|", Next_Key, 0xE0, 8);
}
