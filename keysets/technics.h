//
// technics.h
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

#ifndef TECHNICS_H
#define TECHNICS_H

#include "pirkeysetmetadata.h"

class QObject;
class QComboBox;

class TechnicsAudio1: public PIRKeysetMetaData
{
public:
  TechnicsAudio1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class TechnicsAudio1a: public TechnicsAudio1
{
public:
  TechnicsAudio1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class TechnicsAudio2: public PIRKeysetMetaData
{
public:
  TechnicsAudio2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class TechnicsAudio3: public PIRKeysetMetaData
{
public:
  TechnicsAudio3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class TechnicsAudio3a: public TechnicsAudio3
{
public:
  TechnicsAudio3a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class TechnicsReceiver1: public PIRKeysetMetaData
{
public:
  TechnicsReceiver1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class TechnicsReceiver1a: public TechnicsReceiver1
{
public:
  TechnicsReceiver1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class TechnicsCD1: public PIRKeysetMetaData
{
public:
  TechnicsCD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class TechnicsDVD1: public PIRKeysetMetaData
{
public:
  TechnicsDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // TECHNICS_H
