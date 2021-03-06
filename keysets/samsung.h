//
// samsung.h
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

#ifndef SAMSUNG_H
#define SAMSUNG_H

#include "pirkeysetmetadata.h"
#include "pirackeyset.h"
#include "piracstateinfo.h"

class QComboBox;

class SamsungTV1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  SamsungTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb) const;
};


class SamsungTV1a: public SamsungTV1
{
  Q_OBJECT

public:
  SamsungTV1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SamsungTV1b: public SamsungTV1
{
  Q_OBJECT

public:
  SamsungTV1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SamsungTV2: public PIRKeysetMetaData
{
public:
  SamsungTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb) const;
};


class SamsungTV3: public PIRKeysetMetaData
{
public:
  SamsungTV3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SamsungTV3a: public SamsungTV3
{
public:
  SamsungTV3a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SamsungVCR1: public PIRKeysetMetaData
{
public:
  SamsungVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SamsungVCR1a: public SamsungVCR1
{
public:
  SamsungVCR1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SamsungVCR1b: public SamsungVCR1
{
public:
  SamsungVCR1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SamsungVCR1c: public SamsungVCR1a
{
public:
  SamsungVCR1c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SamsungVCR1d: public SamsungVCR1
{
public:
  SamsungVCR1d(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SamsungVCR1e: public SamsungVCR1
{
public:
  SamsungVCR1e(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SamsungDVD1: public PIRKeysetMetaData
{
public:
  SamsungDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SamsungDVD1a: public SamsungDVD1
{
public:
  SamsungDVD1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SamsungDVD1b: public SamsungDVD1
{
public:
  SamsungDVD1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SamsungDVD2: public PIRKeysetMetaData
{
public:
  SamsungDVD2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb) const;
};

class SamsungAC1: public PIRKeysetMetaData
{
public:
  SamsungAC1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SamsungAC2: public PIRACKeyset
{
public:
  SamsungAC2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateSettingsList(
    PIRACSettings &acSettings) const;

  virtual void getTurboModePairs(
    PIRStatePairs &turboModePairs) const;

  virtual void getSwingPairs(
    PIRStatePairs &swingPairs) const;

  virtual void getTemperaturePairs(
    PIRStatePairs &temperaturePairs) const;

  virtual void getFanPairs(
    PIRStatePairs &fanPairs) const;

  virtual void getOperatingModePairs(
    PIRStatePairs &modePairs) const;

  virtual void getAirCleanPairs(
    PIRStatePairs &aircleanPairs) const;

/*
  virtual void getPowerPairs(
    PIRStatePairs &powerPairs) const;
*/

  virtual void getTimerOptionPairs(
    PIRStatePairs &timerOptionPairs) const;
};

class SamsungSTB1: public PIRKeysetMetaData
{
public:
  SamsungSTB1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb) const;
};

class SamsungSTB2: public PIRKeysetMetaData
{
public:
  SamsungSTB2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SamsungSTB3: public PIRKeysetMetaData
{
public:
  SamsungSTB3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SamsungSTB4: public PIRKeysetMetaData
{
public:
  SamsungSTB4(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SamsungSTB5: public PIRKeysetMetaData
{
public:
  SamsungSTB5(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb) const;
};

class SamsungSTB6: public PIRKeysetMetaData
{
public:
  SamsungSTB6(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // SAMSUNG_H
