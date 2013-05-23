//
// wd.h
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

#ifndef WD_H
#define WD_H

#include "pirkeysetmetadata.h"

class QObject;

class WDMediaPlayer1: public PIRKeysetMetaData
{
public:
  WDMediaPlayer1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class WDMediaPlayer1a: public WDMediaPlayer1
{
public:
  WDMediaPlayer1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class WDMediaPlayer1b: public WDMediaPlayer1a
{
public:
  WDMediaPlayer1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // WD_H
