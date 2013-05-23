//
// irobot.cpp
//
// Copyright 2012, 2013 by John Pietrzak (jpietrzak8@gmail.com)
//
// This file is part of Pierogi.
//
// Pierogi is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// Pierogi is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//

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
