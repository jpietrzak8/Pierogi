//
// loewe.h
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

#ifndef LOEWE_H
#define LOEWE_H

#include "pirkeysetmetadata.h"

class QObject;

class LoeweTV1: public PIRKeysetMetaData
{
public:
  LoeweTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class LoeweVCR1: public PIRKeysetMetaData
{
public:
  LoeweVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class LoeweDVD1: public PIRKeysetMetaData
{
public:
  LoeweDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // LOEWE_H
