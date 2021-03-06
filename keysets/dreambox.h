//
// dreambox.h
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

#ifndef DREAMBOX_H
#define DREAMBOX_H

#include "pirkeysetmetadata.h"

class QComboBox;

class DreamboxSat1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  DreamboxSat1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb) const;
};

class DreamboxSat1a: public DreamboxSat1
{
  Q_OBJECT

public:
  DreamboxSat1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DreamboxSat1b: public DreamboxSat1
{
  Q_OBJECT

public:
  DreamboxSat1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DreamboxSat1c: public DreamboxSat1
{
  Q_OBJECT

public:
  DreamboxSat1c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DreamboxSat2: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  DreamboxSat2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb) const;
};

class DreamboxSat3: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  DreamboxSat3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb) const;
};

class DreamboxSat4: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  DreamboxSat4(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

//  virtual void populateInputList(
//    QComboBox *cb) const;
};

class DreamboxSat5: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  DreamboxSat5(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // DREAMBOX_H
