//
// acer.h
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
// along with Pierogi; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//

#ifndef ACER_H
#define ACER_H

#include "pirkeysetmetadata.h"

class QComboBox;

class AcerTV1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  AcerTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class AcerPC1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  AcerPC1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // ACER_H
