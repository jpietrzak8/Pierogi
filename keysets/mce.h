//
// mce.h
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

#ifndef MCE_H
#define MCE_H

#include "pirkeysetmetadata.h"

class QComboBox;

class MCERemote1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  MCERemote1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb) const;
};

class MCERemote1a: public MCERemote1
{
  Q_OBJECT

public:
  MCERemote1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class MCERemote1b: public MCERemote1
{
  Q_OBJECT

public:
  MCERemote1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class MCERemote1c: public MCERemote1
{
  Q_OBJECT

public:
  MCERemote1c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class MCERemote1d: public MCERemote1
{
  Q_OBJECT

public:
  MCERemote1d(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class MCERemote1e: public MCERemote1
{
  Q_OBJECT

public:
  MCERemote1e(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class MCERemote1f: public MCERemote1
{
  Q_OBJECT

public:
  MCERemote1f(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class MCERemote1g: public MCERemote1
{
  Q_OBJECT

public:
  MCERemote1g(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class MCEXboxRemote1: public MCERemote1g
{
  Q_OBJECT

public:
  MCEXboxRemote1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // MCE_H
