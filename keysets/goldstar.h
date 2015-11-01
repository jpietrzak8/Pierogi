//
// goldstar.h
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

#ifndef GOLDSTAR_H
#define GOLDSTAR_H

#include "pirkeysetmetadata.h"

class QComboBox;

class GoldStarTV1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  GoldStarTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class GoldStarTV2: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  GoldStarTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class GoldStarVCR1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  GoldStarVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class GoldStarVCR1a: public GoldStarVCR1
{
  Q_OBJECT

public:
  GoldStarVCR1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class GoldStarVCR1b: public GoldStarVCR1
{
  Q_OBJECT

public:
  GoldStarVCR1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class GoldStarVCR1c: public GoldStarVCR1
{
  Q_OBJECT

public:
  GoldStarVCR1c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class GoldStarAudio1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  GoldStarAudio1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

#endif // GOLDSTAR_H
