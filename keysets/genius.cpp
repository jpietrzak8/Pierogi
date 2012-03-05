#include "genius.h"
#include "protocols/lircprotocol.h"


GeniusSpeakers1::GeniusSpeakers1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Speaker Keyset 1",
      Genius_Make,
      index)
{
}


void GeniusSpeakers1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  LIRCProtocol *lp = new LIRCProtocol(
    guiObject, index,
    359, 1327,
    1202, 484,
    53977, true);

  threadableProtocol = lp;

  lp->setTrailerPulse(359);

  setPreData(0x6, 3);

  addKey("POWER", Power_Key, 0x50, 8);
  addKey("MUTE", Mute_Key, 0x48, 8);
  addKey("VOL_DOWN", VolumeDown_Key, 0x88, 8);
  addKey("VOL_UP", VolumeUp_Key, 0x90, 8);
}
