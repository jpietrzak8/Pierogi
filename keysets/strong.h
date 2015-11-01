//
// strong.h
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

#ifndef STRONG_H
#define STRONG_H

#include "pirkeysetmetadata.h"

class QComboBox;

class StrongSat1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  StrongSat1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class StrongSat2: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  StrongSat2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class StrongSat2a: public StrongSat2
{
  Q_OBJECT

public:
  StrongSat2a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class StrongSat3: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  StrongSat3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class StrongSat3a: public StrongSat3
{
  Q_OBJECT

public:
  StrongSat3a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class StrongSat4: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  StrongSat4(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class StrongSat5: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  StrongSat5(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class StrongSat5a: public StrongSat5
{
  Q_OBJECT

public:
  StrongSat5a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class StrongSTB1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  StrongSTB1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class StrongSTB2: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  StrongSTB2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class StrongSTB3: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  StrongSTB3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class StrongSTB4: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  StrongSTB4(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class StrongSTB5: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  StrongSTB5(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // STRONG_H
