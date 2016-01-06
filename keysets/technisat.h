//
// technisat.h
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

#ifndef TECHNISAT_H
#define TECHNISAT_H

#include "pirkeysetmetadata.h"

class QComboBox;

class TechnisatSTB1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  TechnisatSTB1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb) const;
};

class TechnisatSTB1a: public TechnisatSTB1
{
  Q_OBJECT

public:
  TechnisatSTB1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class TechnisatSTB2: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  TechnisatSTB2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb) const;
};

class TechnisatSTB2a: public TechnisatSTB2
{
  Q_OBJECT

public:
  TechnisatSTB2a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class TechnisatSTB3: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  TechnisatSTB3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class TechnisatSTB3a: public TechnisatSTB3
{
  Q_OBJECT

public:
  TechnisatSTB3a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // TECHNISAT_H
