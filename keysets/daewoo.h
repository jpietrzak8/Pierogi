//
// daewoo.h
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

#ifndef DAEWOO_H
#define DAEWOO_H

#include "pirkeysetmetadata.h"

class QComboBox;

class DaewooTV1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  DaewooTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb) const;
};

class DaewooTV2: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  DaewooTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DaewooTV3: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  DaewooTV3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb) const;
};

class DaewooTV4: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  DaewooTV4(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb) const;
};

class DaewooTV5: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  DaewooTV5(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DaewooDVD1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  DaewooDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DaewooVCR1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  DaewooVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DaewooVCR2: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  DaewooVCR2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb) const;
};

#endif // DAEWOO_H
