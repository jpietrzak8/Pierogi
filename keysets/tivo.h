//
// tivo.h
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

#ifndef TIVO_H
#define TIVO_H

#include "pirkeysetmetadata.h"


class Tivo1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  Tivo1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class Tivo1a: public Tivo1
{
  Q_OBJECT

public:
  Tivo1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class Tivo1b: public Tivo1
{
  Q_OBJECT

public:
  Tivo1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class Tivo1c: public Tivo1
{
  Q_OBJECT

public:
  Tivo1c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class Tivo1d: public Tivo1
{
  Q_OBJECT

public:
  Tivo1d(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // TIVO_H
