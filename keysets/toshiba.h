//
// toshiba.h
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

#ifndef TOSHIBA_H
#define TOSHIBA_H

#include "pirkeysetmetadata.h"

class QObject;

class ToshibaTV1: public PIRKeysetMetaData
{
public:
  ToshibaTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class ToshibaTV1a: public ToshibaTV1
{
public:
  ToshibaTV1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class ToshibaTV1b: public ToshibaTV1
{
public:
  ToshibaTV1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class ToshibaTV1f: public ToshibaTV1
{
public:
  ToshibaTV1f(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class ToshibaTV1c: public ToshibaTV1f
{
public:
  ToshibaTV1c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class ToshibaTV1d: public ToshibaTV1f
{
public:
  ToshibaTV1d(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class ToshibaTV1e: public ToshibaTV1
{
public:
  ToshibaTV1e(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class ToshibaTV1g: public ToshibaTV1
{
public:
  ToshibaTV1g(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class ToshibaTV1h: public ToshibaTV1b
{
public:
  ToshibaTV1h(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class ToshibaTV1i: public ToshibaTV1h
{
public:
  ToshibaTV1i(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class ToshibaVCR1: public PIRKeysetMetaData
{
public:
  ToshibaVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class ToshibaVCR1a: public ToshibaVCR1
{
public:
  ToshibaVCR1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class ToshibaVCR1b: public ToshibaVCR1
{
public:
  ToshibaVCR1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class ToshibaDisc1: public PIRKeysetMetaData
{
public:
  ToshibaDisc1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class ToshibaDisc1a: public ToshibaDisc1
{
public:
  ToshibaDisc1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class ToshibaDisc1b: public ToshibaDisc1
{
public:
  ToshibaDisc1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class ToshibaDisc1c: public ToshibaDisc1a
{
public:
  ToshibaDisc1c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

/*
class ToshibaDisc1d: public ToshibaDisc1a
{
public:
  ToshibaDisc1d(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};
*/

class ToshibaDisc2: public PIRKeysetMetaData
{
public:
  ToshibaDisc2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class ToshibaProjector1: public PIRKeysetMetaData
{
public:
  ToshibaProjector1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class ToshibaSTB1: public PIRKeysetMetaData
{
public:
  ToshibaSTB1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // TOSHIBA_H
