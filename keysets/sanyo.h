//
// sanyo.h
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

#ifndef SANYO_H
#define SANYO_H

#include "pirkeysetmetadata.h"

class QObject;
class QComboBox;

class SanyoVCR1: public PIRKeysetMetaData
{
public:
  SanyoVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SanyoDVD1: public PIRKeysetMetaData
{
public:
  SanyoDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SanyoTV1: public PIRKeysetMetaData
{
public:
  SanyoTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class SanyoTV1b: public SanyoTV1
{
public:
  SanyoTV1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SanyoTV1d: public SanyoTV1
{
public:
  SanyoTV1d(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SanyoTV2: public PIRKeysetMetaData
{
public:
  SanyoTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class SanyoProjector1: public PIRKeysetMetaData
{
public:
  SanyoProjector1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class SanyoProjector1a: public SanyoProjector1
{
public:
  SanyoProjector1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SanyoProjector1b: public SanyoProjector1
{
public:
  SanyoProjector1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SanyoProjector1c: public SanyoProjector1
{
public:
  SanyoProjector1c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // SANYO_H
