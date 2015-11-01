//
// yamaha.h
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

#ifndef YAMAHA_H
#define YAMAHA_H

#include "pirkeysetmetadata.h"

class QComboBox;

class YamahaDVD1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  YamahaDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class YamahaDVD1a: public YamahaDVD1
{
  Q_OBJECT

public:
  YamahaDVD1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class YamahaAudio1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  YamahaAudio1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class YamahaAudio1a: public YamahaAudio1
{
  Q_OBJECT

public:
  YamahaAudio1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class YamahaAudio2: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  YamahaAudio2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class YamahaAudio2a: public YamahaAudio2
{
  Q_OBJECT

public:
  YamahaAudio2a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class YamahaAudio2b: public YamahaAudio2
{
  Q_OBJECT

public:
  YamahaAudio2b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class YamahaAudio2c: public YamahaAudio2
{
  Q_OBJECT

public:
  YamahaAudio2c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class YamahaAudio2d: public YamahaAudio2
{
  Q_OBJECT

public:
  YamahaAudio2d(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class YamahaAudio3: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  YamahaAudio3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class YamahaAudio4: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  YamahaAudio4(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class YamahaTV1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  YamahaTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class YamahaKaraoke1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  YamahaKaraoke1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

#endif // YAMAHA_H
