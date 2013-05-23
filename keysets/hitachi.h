//
// hitachi.h
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

#ifndef HITACHI_H
#define HITACHI_H

#include "pirkeysetmetadata.h"

class QObject;

class HitachiTV1: public PIRKeysetMetaData
{
public:
  HitachiTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class HitachiTV1a: public HitachiTV1
{
public:
  HitachiTV1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class HitachiTV1b: public HitachiTV1a
{
public:
  HitachiTV1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class HitachiTV1c: public HitachiTV1
{
public:
  HitachiTV1c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class HitachiTV2: public PIRKeysetMetaData
{
public:
  HitachiTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class HitachiTV3: public PIRKeysetMetaData
{
public:
  HitachiTV3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class HitachiProjector: public PIRKeysetMetaData
{
public:
  HitachiProjector(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class HitachiDVD1: public PIRKeysetMetaData
{
public:
  HitachiDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class HitachiAudio1: public PIRKeysetMetaData
{
public:
  HitachiAudio1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class HitachiVCR1: public PIRKeysetMetaData
{
public:
  HitachiVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // HITACHI_H
