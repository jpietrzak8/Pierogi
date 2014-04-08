//
// benq.h
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

#ifndef BENQ_H
#define BENQ_H

#include "pirkeysetmetadata.h"

class QObject;
class QComboBox;

class BenQTV1: public PIRKeysetMetaData
{
public:
  BenQTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class BenQProjector1: public PIRKeysetMetaData
{
public:
  BenQProjector1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class BenQProjector1a: public BenQProjector1
{
public:
  BenQProjector1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};


class BenQProjector2: public PIRKeysetMetaData
{
public:
  BenQProjector2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};


class BenQProjector3: public PIRKeysetMetaData
{
public:
  BenQProjector3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class BenQProjector4: public PIRKeysetMetaData
{
public:
  BenQProjector4(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};


class BenQProjector5: public PIRKeysetMetaData
{
public:
  BenQProjector5(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

#endif // BENQ_H
