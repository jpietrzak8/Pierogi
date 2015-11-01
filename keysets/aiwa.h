//
// aiwa.h
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

#ifndef AIWA_H
#define AIWA_H

#include "pirkeysetmetadata.h"

class QComboBox;

class AiwaVCR1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  AiwaVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class AiwaVCR2: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  AiwaVCR2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class AiwaVCR3: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  AiwaVCR3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class AiwaAudio1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  AiwaAudio1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class AiwaAudio1a: public AiwaAudio1
{
  Q_OBJECT

public:
  AiwaAudio1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class AiwaAudio2: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  AiwaAudio2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class AiwaAudio2a: public AiwaAudio2
{
  Q_OBJECT

public:
  AiwaAudio2a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class AiwaAudio2b: public AiwaAudio2
{
  Q_OBJECT

public:
  AiwaAudio2b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class AiwaAudio2c: public AiwaAudio2
{
  Q_OBJECT

public:
  AiwaAudio2c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class AiwaAudio3: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  AiwaAudio3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class AiwaAudio4: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  AiwaAudio4(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class AiwaAudio5: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  AiwaAudio5(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class AiwaAudio6: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  AiwaAudio6(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class AiwaCarStereo1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  AiwaCarStereo1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class AiwaDVD1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  AiwaDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // AIWA_H
