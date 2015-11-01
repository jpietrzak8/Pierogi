//
// pioneer.h
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

#ifndef PIONEER_H
#define PIONEER_H

#include "pirkeysetmetadata.h"

class QComboBox;

class PioneerTV1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  PioneerTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class PioneerTV2: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  PioneerTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PioneerTV3: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  PioneerTV3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PioneerAudio1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  PioneerAudio1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class PioneerAudio1a: public PioneerAudio1
{
  Q_OBJECT

public:
  PioneerAudio1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PioneerAudio2: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  PioneerAudio2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class PioneerAudio3: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  PioneerAudio3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class PioneerAudio4: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  PioneerAudio4(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PioneerAudio5: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  PioneerAudio5(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class PioneerAudio6: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  PioneerAudio6(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class PioneerCD1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  PioneerCD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PioneerLaserDisc1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  PioneerLaserDisc1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PioneerDVD1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  PioneerDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PioneerCarStereo1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  PioneerCarStereo1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

#endif // PIONEER_H
