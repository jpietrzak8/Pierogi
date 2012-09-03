#include "irobot.h"
#include "protocols/irobotprotocol.h"


IRobotRoomba1::IRobotRoomba1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Roomba Keyset 1",
      IRobot_Make,
      index)
{
}


void IRobotRoomba1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new IRobotProtocol(guiObject, index);

  addKey("CounterClockwise", RobotCCW_Key, 0x81, 8);
  addKey("Forward", RobotForward_Key, 0x82, 8);
  addKey("Clockwise", RobotCW_Key, 0x83, 8);
  addKey("spot", RobotSpot_Key, 0x84, 8);
  addKey("max", RobotMax_Key, 0x85, 8);
  addKey("clean", RobotClean_Key, 0x88, 8); // "clear"
  addKey("pause", Pause_Key, 0x89, 8);
  addKey("power", Power_Key, 0x8A, 8);
}
