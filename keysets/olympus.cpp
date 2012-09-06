#include "olympus.h"
#include "protocols/necprotocol.h"

OlympusCamera1::OlympusCamera1(
  unsigned int index)
  : PIRKeysetMetaData(
      "RM-2 Remote Keyset",
      Olympus_Make,
      index)
{
  addControlledDevice(Olympus_Make, "410 Digital", Other_Device);
}


void OlympusCamera1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x3B86, 16);

  addKey("CAPTURE", OpenShutter_Key, 0x01, 8);
}
