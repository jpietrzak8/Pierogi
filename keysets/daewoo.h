//
// daewoo.h
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

#ifndef DAEWOO_H
#define DAEWOO_H

#include "pirkeysetmetadata.h"

class QObject;
class QComboBox;

class DaewooTV1: public PIRKeysetMetaData
{
public:
  DaewooTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class DaewooTV2: public PIRKeysetMetaData
{
public:
  DaewooTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DaewooTV3: public PIRKeysetMetaData
{
public:
  DaewooTV3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class DaewooTV4: public PIRKeysetMetaData
{
public:
  DaewooTV4(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class DaewooTV5: public PIRKeysetMetaData
{
public:
  DaewooTV5(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DaewooDVD1: public PIRKeysetMetaData
{
public:
  DaewooDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DaewooVCR1: public PIRKeysetMetaData
{
public:
  DaewooVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DaewooVCR2: public PIRKeysetMetaData
{
public:
  DaewooVCR2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

#endif // DAEWOO_H
