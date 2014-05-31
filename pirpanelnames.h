//
// pirpanelnames.h
//
// Copyright 2012, 2013 by John Pietrzak  (jpietrzak8@gmail.com)
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

#ifndef PIRPANELNAMES_H
#define PIRPANELNAMES_H

#include <QFlags>

enum PIRPanelName
{
  Main_Panel,
  Alt_Main_Panel,
  Utility_Panel,
  Keypad_Panel,
  Menu_Panel,
  Media_Panel,
  Media2_Panel,
  Record_Panel,
  TV_Panel,
  Receiver_Panel,
  Input_Panel,
  InputList_Panel,
  Adjust_Panel,
  AC_Panel,
  StatefulAC_Panel,
  ACTimer_Panel,
  Audio_Panel,
  Camera_Panel,
  Intervalometer_Panel,
  Roomba_Panel,
  Playstation_Panel,
  User_Panel,
//  Macro_Panel,
//  PowerSearch_Panel,
//  Advanced_Panel,
  Last_Panel_Marker // Used when traversing this enumeration.
};


enum PIRPanelType
{
  TV_Panels = 0x1,
  MediaControl_Panels = 0x2,
  MediaRecord_Panels = 0x4,
  Receiver_Panels = 0x8,
  ACFan_Panels = 0x10,
  StatefulAC_Panels = 0x20,
  Camera_Panels = 0x40,
  Roomba_Panels = 0x80,
  Playstation_Panels = 0x100
//  Last_Panels_Marker = 0x200
};

Q_DECLARE_FLAGS(PIRPanelTypes, PIRPanelType);

Q_DECLARE_OPERATORS_FOR_FLAGS(PIRPanelTypes);


/*
enum PIRTabBarName
{
  Universal_Tabs,
  TV_Tabs,
  VideoMedia_Tabs,
//  VideoDisc_Tabs,
//  VideoTape_Tabs,
  Audio_Tabs,
  StandardAC_Tabs,
  StatefulAC_Tabs,
  Record_Tabs,
  Camera_Tabs,
  Roomba_Tabs,
  Console_Tabs,
//  Macro_Tabs,
//  PowerSearch_Tabs,
//  Advanced_Tabs,
  Last_Tabs_Marker
};
*/

#endif // PIRPANELNAMES_H
