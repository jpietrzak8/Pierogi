//
// medion.h
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

#ifndef MEDION_H
#define MEDION_H

#include "pirkeysetmetadata.h"


class MedionSTB1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  MedionSTB1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class MedionDVD1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  MedionDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class MedionDVD2: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  MedionDVD2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class MedionVCR1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  MedionVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // MEDION_H
