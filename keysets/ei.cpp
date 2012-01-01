#include "ei.h"
#include "rc5protocol.h"

// Based on LIRC Ei-TV90 config file
EiKeyset::EiKeyset(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Ei-TV90",
      Ei_Make,
      index)
{
  addControlledDevice(Ei_Make, "COLOR 51100", TV_Device);
  addControlledDevice(Ei_Make, "COLOR 55100", TV_Device);
  addControlledDevice(Ei_Make, "COLOR 63105", TV_Device);
  addControlledDevice(Ei_Make, "COLOR 56105", TV_Device);
  addControlledDevice(Ei_Make, "COLOR 72105", TV_Device);

  RC5Protocol *rp = new RC5Protocol(
    guiObject,
    index,
    931, 836,
    969,
    113205, 2);

  threadableProtocol = rp;

  rp->setPreData(0x10, 5);

  rp->setToggleBit(2);

  addKey("i", Unmapped_Key, 0x35, 8);
  addKey("a", Unmapped_Key, 0x37, 8);
  addKey("b", Unmapped_Key, 0x36, 8);
  addKey("c", Unmapped_Key, 0x32, 8);
  addKey("d", Unmapped_Key, 0x34, 8);
  addKey("Page Down", Unmapped_Key, 0x0B, 8);
  addKey("Page Up", Unmapped_Key, 0x0A, 8);
  addKey("TV in TXT", Unmapped_Key, 0x2D, 8);
  addKey("Stop TXT", Unmapped_Key, 0x29, 8);
  addKey("Time TXT", Unmapped_Key, 0x2A, 8);
  addKey("TV", Unmapped_Key, 0x3F, 8);
  addKey("TXT On", Unmapped_Key, 0x3C, 8);
  addKey("?", Unmapped_Key, 0x2C, 8);
  addKey("Zoom", Unmapped_Key, 0x2B, 8);
  addKey("Background TV", Unmapped_Key, 0x2E, 8);
  addKey("1", One_Key, 0x01, 8);
  addKey("2", Two_Key, 0x02, 8);
  addKey("3", Three_Key, 0x03, 8);
  addKey("4", Four_Key, 0x04, 8);
  addKey("5", Five_Key, 0x05, 8);
  addKey("6", Six_Key, 0x06, 8);
  addKey("7", Seven_Key, 0x07, 8);
  addKey("8", Eight_Key, 0x08, 8);
  addKey("9", Nine_Key, 0x09, 8);
  addKey("0", Zero_Key, 0x00, 8);
  addKey("LIGHT-", Unmapped_Key, 0x13, 8);
  addKey("LIGHT+", Unmapped_Key, 0x12, 8);
  addKey("COLOR-", Unmapped_Key, 0x15, 8);
  addKey("COLOR+", Unmapped_Key, 0x14, 8);
  addKey("CONTRAST-", Unmapped_Key, 0x1D, 8);
  addKey("CONTRAST+", Unmapped_Key, 0x1C, 8);
  addKey("VOLUME-", VolumeDown_Key, 0x11, 8);
  addKey("VOLUME+", VolumeUp_Key, 0x10, 8);
  addKey("->*", Unmapped_Key, 0x1E, 8);
  addKey("AV", Input_Key, 0x38, 8);
  addKey("-/--", Unmapped_Key, 0x0A, 8);
  addKey("TV_STATUS", Info_Key, 0x0F, 8);
  addKey("SLEEP", Sleep_Key, 0x26, 8);
  addKey("P<P", Unmapped_Key, 0x22, 8);
  addKey("->*<-PP", Unmapped_Key, 0x0E, 8);
  addKey("P-", ChannelDown_Key, 0x21, 8);
  addKey("P+", ChannelUp_Key, 0x20, 8);
  addKey("MUTE", Mute_Key, 0x0D, 8);
  addKey("ON-OFF", Power_Key, 0x0C, 8);
}
