#include "nokia.h"
#include "necprotocol.h"

NokiaGenericVCR::NokiaGenericVCR(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Generic VCR",
      Nokia_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    272, 737,
    272, 1711,
    42100, false,
    LIRC_NEC);

  threadableProtocol = np;

  np->setTrailerPulse(272);

//  np->setMinimumRepetitions(3);

  setPreData(0x6, 3);

  addKey("Power", Power_Key, 0x1A2, 12);
  addKey("1", One_Key, 0x202, 12);
  addKey("2", Two_Key, 0x102, 12);
  addKey("3", Three_Key, 0x302, 12);
  addKey("4", Four_Key, 0x082, 12);
  addKey("5", Five_Key, 0x282, 12);
  addKey("6", Six_Key, 0x182, 12);
  addKey("7", Seven_Key, 0x382, 12);
  addKey("8", Eight_Key, 0x042, 12);
  addKey("9", Nine_Key, 0x242, 12);
  addKey("0", Zero_Key, 0x142, 12);
  addKey("Timer", Timer_Key, 0x262, 12);
  addKey("Clear", Clear_Key, 0x012, 12);
  addKey("P+", ChannelUp_Key, 0x222, 12);
  addKey("P-", ChannelDown_Key, 0x122, 12);
  addKey("Up", Up_Key, 0x112, 12);
  addKey("Down", Down_Key, 0x392, 12);
  addKey("Left", Left_Key, 0x312, 12);
  addKey("Right", Right_Key, 0x212, 12);
  addKey("Ok", Enter_Key, 0x166, 12);
  addKey("Ok", Select_Key, 0x166, 12);
  addKey("Red", Red_Key, 0x252, 12);
  addKey("Green", Green_Key, 0x292, 12);
  addKey("Yellow", Yellow_Key, 0x032, 12);
  addKey("Blue", Blue_Key, 0x3D2, 12);
  addKey("Rec", Record_Key, 0x052, 12);
  addKey("Clock", Clock_Key, 0x1C2, 12);
  addKey("Prog", Program_Key, 0x066, 12);
  addKey("PIP", PIP_Key, 0x0C6, 12);
}
