//
// grundig.h
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

#ifndef GRUNDIG_H
#define GRUNDIG_H

#include "pirkeysetmetadata.h"

#include "philips.h" // for generic RC5 keyset

class QObject;
class QComboBox;

class GrundigSat1: public PIRKeysetMetaData
{
public:
  GrundigSat1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class GrundigSat2: public PIRKeysetMetaData
{
public:
  GrundigSat2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class GrundigSat3: public PIRKeysetMetaData
{
public:
  GrundigSat3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class GrundigAmp1: public PIRKeysetMetaData
{
public:
  GrundigAmp1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class GrundigAudio1: public PIRKeysetMetaData
{
public:
  GrundigAudio1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class GrundigAudio2: public PIRKeysetMetaData
{
public:
  GrundigAudio2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class GrundigVCR1: public PIRKeysetMetaData
{
public:
  GrundigVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class GrundigVCR1a: public GrundigVCR1
{
public:
  GrundigVCR1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class GrundigTV1: public PIRKeysetMetaData
{
public:
  GrundigTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class GrundigTV2: public PIRKeysetMetaData
{
public:
  GrundigTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class GrundigTV3: public PIRKeysetMetaData
{
public:
  GrundigTV3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class GrundigTV4: public PIRKeysetMetaData
{
public:
  GrundigTV4(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class GrundigTV5: public PhilipsTV1
{
public:
  GrundigTV5(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class GrundigDVD1: public PIRKeysetMetaData
{
public:
  GrundigDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // GRUNDIG_H
