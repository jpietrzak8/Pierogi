//
// panasonic.h
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

#ifndef PANASONIC_H
#define PANASONIC_H

#include "pirkeysetmetadata.h"

class QComboBox;

class PanasonicCarAudio: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  PanasonicCarAudio(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PanasonicSat1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  PanasonicSat1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PanasonicSat1a: public PanasonicSat1
{
  Q_OBJECT

public:
  PanasonicSat1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PanasonicTV1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  PanasonicTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb) const;
};

class PanasonicTV1a: public PanasonicTV1
{
  Q_OBJECT

public:
  PanasonicTV1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PanasonicTV1b: public PanasonicTV1
{
  Q_OBJECT

public:
  PanasonicTV1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class PanasonicTV2: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  PanasonicTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PanasonicTV2a: public PanasonicTV2
{
  Q_OBJECT

public:
  PanasonicTV2a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PanasonicVCR1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  PanasonicVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PanasonicVCR1a: public PanasonicVCR1
{
  Q_OBJECT

public:
  PanasonicVCR1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PanasonicVCR1b: public PanasonicVCR1
{
  Q_OBJECT

public:
  PanasonicVCR1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PanasonicVCR1c: public PanasonicVCR1
{
  Q_OBJECT

public:
  PanasonicVCR1c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PanasonicVCR2: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  PanasonicVCR2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PanasonicDVD1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  PanasonicDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PanasonicDVD1a: public PanasonicDVD1
{
  Q_OBJECT

public:
  PanasonicDVD1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PanasonicAudio1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  PanasonicAudio1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb) const;
};

class PanasonicAudio2: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  PanasonicAudio2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb) const;
};

class PanasonicAudio2a: public PanasonicAudio2
{
  Q_OBJECT

public:
  PanasonicAudio2a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PanasonicAudio3: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  PanasonicAudio3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb) const;
};

class PanasonicAC1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  PanasonicAC1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // PANASONIC_H
