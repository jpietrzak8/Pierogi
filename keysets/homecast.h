//
// homecast.h
//
// Copyright 2012 - 2015 by John Pietrzak (jpietrzak8@gmail.com)
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

#ifndef HOMECAST_H
#define HOMECAST_H

#include "pirkeysetmetadata.h"

class QComboBox;

class HomecastReceiver1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  HomecastReceiver1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *box) const;
};

class HomecastReceiver2: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  HomecastReceiver2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // HOMECAST_H
