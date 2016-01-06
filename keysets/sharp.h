//
// sharp.h
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

#ifndef SHARP_H
#define SHARP_H

#include "pirkeysetmetadata.h"

class QComboBox;

class SharpTV1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  SharpTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SharpTV1a: public SharpTV1
{
  Q_OBJECT

public:
  SharpTV1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SharpTV1b: public SharpTV1
{
  Q_OBJECT

public:
  SharpTV1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SharpTV1c: public SharpTV1
{
  Q_OBJECT

public:
  SharpTV1c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SharpTV1d: public SharpTV1
{
  Q_OBJECT

public:
  SharpTV1d(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SharpTV1e: public SharpTV1
{
  Q_OBJECT

public:
  SharpTV1e(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SharpVCR1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  SharpVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SharpReceiver1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  SharpReceiver1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb) const;
};

class SharpAC1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  SharpAC1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SharpCamcorder1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  SharpCamcorder1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // SHARP_H
