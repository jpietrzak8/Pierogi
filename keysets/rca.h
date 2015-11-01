//
// rca.h
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

#ifndef RCA_H
#define RCA_H

#include "pirkeysetmetadata.h"


class RCATV1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  RCATV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class RCATV1a: public RCATV1
{
  Q_OBJECT

public:
  RCATV1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class RCATV1b: public RCATV1
{
  Q_OBJECT

public:
  RCATV1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

/*
class RCAAux1: public PIRKeysetMetaData
{
public:
  RCAAux1(
    QObject *guiObject,
    unsigned int index);
};

class RCAAux2: public PIRKeysetMetaData
{
public:
  RCAAux2(
    QObject *guiObject,
    unsigned int index);
};

class RCAAux2a: public RCAAux2
{
public:
  RCAAux2a(
    QObject *guiObject,
    unsigned int index);
};
*/

class RCAVCR1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  RCAVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class RCAVCR1a: public RCAVCR1
{
  Q_OBJECT

public:
  RCAVCR1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class RCADVD1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  RCADVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class RCADVD1a: public RCADVD1
{
  Q_OBJECT

public:
  RCADVD1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class RCASat1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  RCASat1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class RCASat2: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  RCASat2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // RCA_H
