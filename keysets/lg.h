//
// lg.h
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

#ifndef LG_H
#define LG_H

#include "pirkeysetmetadata.h"

class QObject;

class LGTV1: public PIRKeysetMetaData
{
public:
  LGTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class LGTV1a: public LGTV1
{
public:
  LGTV1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class LGTV1b: public LGTV1
{
public:
  LGTV1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class LGTV1c: public LGTV1
{
public:
  LGTV1c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class LGTV2: public PIRKeysetMetaData
{
public:
  LGTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class LGTV2a: public LGTV2
{
public:
  LGTV2a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class LGTV2b: public LGTV2
{
public:
  LGTV2b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class LGHT1: public PIRKeysetMetaData
{
public:
  LGHT1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class LGHT2: public PIRKeysetMetaData
{
public:
  LGHT2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class LGHT2a: public LGHT2
{
public:
  LGHT2a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class LGDisc1: public PIRKeysetMetaData
{
public:
  LGDisc1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class LGDisc2: public PIRKeysetMetaData
{
public:
  LGDisc2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class LGDisc2a: public LGDisc2
{
public:
  LGDisc2a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class LGVCR1: public PIRKeysetMetaData
{
public:
  LGVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class LGVCR1a: public LGVCR1
{
public:
  LGVCR1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class LGVCR1b: public LGVCR1
{
public:
  LGVCR1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class LGAC1: public PIRKeysetMetaData
{
public:
  LGAC1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // LG_H
