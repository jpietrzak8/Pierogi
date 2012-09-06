#include "pentax.h"
#include "protocols/rc5protocol.h"

PentaxCamera1::PentaxCamera1(
  unsigned int index)
  : PIRKeysetMetaData(
      "RC-F Remote Keyset",
      Pentax_Make,
      index)
{
}


void PentaxCamera1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

  addKey("CAPTURE", OpenShutter_Key, 0x100C, 13);
}
