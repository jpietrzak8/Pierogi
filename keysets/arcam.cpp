#include "arcam.h"
#include "protocols/rc5protocol.h"


ArcamReceiver1::ArcamReceiver1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Receiver Keyset 1",
      Arcam_Make,
      index)
{
}


void ArcamReceiver1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

  addKey("right", Right_Key, 0x0410, 13);
  addKey("left", Left_Key, 0x0411, 13);
  addKey("down", Down_Key, 0x0415, 13);
  addKey("up", Up_Key, 0x0416, 13);
  addKey("ok", Select_Key, 0x0417, 13);
  addKey("test", Unmapped_Key, 0x0418, 13);

  addKey("sat", SatInput_Key, 0x1400, 13);
  addKey("5-1", Surround_Key, 0x1402, 13); // ?
  addKey("dvd", DVDInput_Key, 0x1404, 13);
  addKey("tape", TapeInput_Key, 0x1405, 13);
  addKey("vcr", VCRInput_Key, 0x1406, 13);
  addKey("cd", CDInput_Key, 0x1407, 13);
  addKey("aux", AuxInput_Key, 0x1408, 13);
  addKey("power", Power_Key, 0x140C, 13);
  addKey("mute", Mute_Key, 0x140D, 13); // "silent"

  addKey("volup", VolumeUp_Key, 0x1410, 13);
  addKey("voldown", VolumeDown_Key, 0x1411, 13);
  addKey("mode", Mode_Key, 0x1420, 13);
  addKey("trim", Unmapped_Key, 0x1425, 13);
  addKey("sleep", Sleep_Key, 0x142A, 13);

  addKey("am", AM_Key, 0x1434, 13);
  addKey("fm", FM_Key, 0x1435, 13);
  addKey("tmode", FMMode_Key, 0x1436, 13); // ?
  addKey("info", Info_Key, 0x1437, 13);
  addKey("p+", ChannelUp_Key, 0x1438, 13);
  addKey("p-", ChannelDown_Key, 0x1439, 13);
  addKey("dyn", Unmapped_Key, 0x143E, 13);
}
