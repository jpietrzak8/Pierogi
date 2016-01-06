//
// denon.h
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

#ifndef DENON_H
#define DENON_H

#include "pirkeysetmetadata.h"

class QComboBox;

class DenonDVD1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  DenonDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DenonDVD2: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  DenonDVD2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DenonDVD3: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  DenonDVD3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DenonReceiver1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  DenonReceiver1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb) const;
};

class DenonReceiver1a: public DenonReceiver1
{
  Q_OBJECT

public:
  DenonReceiver1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DenonReceiver1b: public DenonReceiver1
{
  Q_OBJECT

public:
  DenonReceiver1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DenonReceiver1c: public DenonReceiver1
{
  Q_OBJECT

public:
  DenonReceiver1c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DenonReceiver1d: public DenonReceiver1c
{
  Q_OBJECT

public:
  DenonReceiver1d(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DenonReceiver1f: public DenonReceiver1c
{
  Q_OBJECT

public:
  DenonReceiver1f(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DenonReceiver2: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  DenonReceiver2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb) const;
};

class DenonReceiver2a: public DenonReceiver2
{
  Q_OBJECT

public:
  DenonReceiver2a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DenonReceiver3: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  DenonReceiver3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb) const;
};

class DenonReceiver4: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  DenonReceiver4(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb) const;
};

class DenonAudio1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  DenonAudio1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb) const;
};

class DenonAudio1a: public DenonAudio1
{
  Q_OBJECT

public:
  DenonAudio1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DenonAudio1b: public DenonAudio1
{
  Q_OBJECT

public:
  DenonAudio1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DenonAudio1c: public DenonAudio1b
{
  Q_OBJECT

public:
  DenonAudio1c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DenonAudio1d: public DenonAudio1
{
  Q_OBJECT

public:
  DenonAudio1d(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DenonAudio2: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  DenonAudio2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

//  virtual void populateInputList(
//    QComboBox *cb) const;
};

class DenonAudio3: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  DenonAudio3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DenonAudio4: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  DenonAudio4(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb) const;
};

#endif // DENON_H
