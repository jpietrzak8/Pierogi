//
// sony.h
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

#ifndef SONY_H
#define SONY_H

#include "pirkeysetmetadata.h"

class QComboBox;

class SonyTV1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  SonyTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb) const;
};


class SonyTV1a: public SonyTV1
{
  Q_OBJECT

public:
  SonyTV1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SonyTV1b: public SonyTV1a
{
  Q_OBJECT

public:
  SonyTV1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SonyTV1c: public SonyTV1
{
  Q_OBJECT

public:
  SonyTV1c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SonyTV2: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  SonyTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

//  virtual void populateInputList(
//    QComboBox *cb) const;
};


class SonyAmp1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  SonyAmp1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb) const;
};


class SonyAmp2: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  SonyAmp2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb) const;
};


class SonyAudio1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  SonyAudio1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb) const;
};


class SonyAudio1a: public SonyAudio1
{
  Q_OBJECT

public:
  SonyAudio1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SonyDAT1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  SonyDAT1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SonyDVD1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  SonyDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SonyDVD1a: public SonyDVD1
{
  Q_OBJECT

public:
  SonyDVD1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SonyDVD1b: public SonyDVD1
{
  Q_OBJECT

public:
  SonyDVD1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SonyDVD2: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  SonyDVD2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SonyDVD2a: public SonyDVD2
{
  Q_OBJECT

public:
  SonyDVD2a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SonyVCR1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  SonyVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb) const;
};


class SonyVCR1a: public SonyVCR1
{
  Q_OBJECT

public:
  SonyVCR1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SonyVCR1b: public SonyVCR1a
{
  Q_OBJECT

public:
  SonyVCR1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SonyReceiver1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  SonyReceiver1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb) const;
};


class SonyCD1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  SonyCD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SonyCD1a: public SonyCD1
{
  Q_OBJECT

public:
  SonyCD1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SonyCD1b: public SonyCD1
{
  Q_OBJECT

public:
  SonyCD1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SonyProjector1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  SonyProjector1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb) const;
};

class SonyProjector1a: public SonyProjector1
{
  Q_OBJECT

public:
  SonyProjector1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SonyPlaystation1: public SonyDVD1
{
  Q_OBJECT

public:
  SonyPlaystation1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SonyHT1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  SonyHT1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb) const;
};


class SonyCarStereo1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  SonyCarStereo1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb) const;
};


class SonyCarStereo1a: public SonyCarStereo1
{
  Q_OBJECT

public:
  SonyCarStereo1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // SONY_H
