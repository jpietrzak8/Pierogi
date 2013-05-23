//
// onkyo.h
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

#ifndef ONKYO_H
#define ONKYO_H

#include "pirkeysetmetadata.h"

class QObject;

class OnkyoAudio1: public PIRKeysetMetaData
{
public:
  OnkyoAudio1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class OnkyoAudio2: public PIRKeysetMetaData
{
public:
  OnkyoAudio2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class OnkyoAudio2a: public OnkyoAudio2
{
public:
  OnkyoAudio2a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class OnkyoAudio3: public PIRKeysetMetaData
{
public:
  OnkyoAudio3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class OnkyoAudio4: public PIRKeysetMetaData
{
public:
  OnkyoAudio4(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class OnkyoAudio5: public PIRKeysetMetaData
{
public:
  OnkyoAudio5(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class OnkyoDVD1: public PIRKeysetMetaData
{
public:
  OnkyoDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class OnkyoDVD2: public PIRKeysetMetaData
{
public:
  OnkyoDVD2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // ONKYO_H
