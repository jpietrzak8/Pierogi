#include "nikon.h"
#include "protocols/lircprotocol.h"


NikonDSLR1::NikonDSLR1(
  unsigned int index)
  : PIRKeysetMetaData(
      "ML-L3 Remote Keyset",
      Nikon_Make,
      index)
{
  addControlledDevice(Nikon_Make, "D70s DSLR Camera", Other_Device);
}


void NikonDSLR1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  LIRCProtocol *lp = new LIRCProtocol(
    guiObject, index,
    500, 1500,
    500, 3500,
    100000, true);

  threadableProtocol = lp;
  lp->setHeaderPair(2100, 27800);
  lp->setTrailerPulse(500);

  addKey("shutter", OpenShutter_Key, 0x1, 2);
}
