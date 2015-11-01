//
// emerson.h
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

#ifndef EMERSON_H
#define EMERSON_H

#include "pirkeysetmetadata.h"


class EmersonTV1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  EmersonTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class EmersonTV2: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  EmersonTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class EmersonTV3: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  EmersonTV3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class EmersonTV4: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  EmersonTV4(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class EmersonTV5: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  EmersonTV5(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class EmersonSTB1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  EmersonSTB1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class EmersonDVD1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  EmersonDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class EmersonAudio1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  EmersonAudio1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class EmersonAudio2: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  EmersonAudio2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class EmersonAudio3: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  EmersonAudio3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // EMERSON_H
