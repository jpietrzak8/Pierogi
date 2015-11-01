//
// dish.h
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

#ifndef DISH_H
#define DISH_H

#include "pirkeysetmetadata.h"

class QComboBox;

class DishReceiver1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  DishReceiver1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class DishReceiver1a: public DishReceiver1
{
  Q_OBJECT

public:
  DishReceiver1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DishReceiver1b: public DishReceiver1
{
  Q_OBJECT

public:
  DishReceiver1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DishReceiver1c: public DishReceiver1
{
  Q_OBJECT

public:
  DishReceiver1c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DishReceiver1d: public DishReceiver1
{
  Q_OBJECT

public:
  DishReceiver1d(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DishReceiver1e: public DishReceiver1
{
  Q_OBJECT

public:
  DishReceiver1e(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DishReceiver1f: public DishReceiver1
{
  Q_OBJECT

public:
  DishReceiver1f(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DishReceiver1g: public DishReceiver1
{
  Q_OBJECT

public:
  DishReceiver1g(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DishReceiver1h: public DishReceiver1
{
  Q_OBJECT

public:
  DishReceiver1h(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DishReceiver1i: public DishReceiver1
{
  Q_OBJECT

public:
  DishReceiver1i(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DishReceiver1j: public DishReceiver1
{
  Q_OBJECT

public:
  DishReceiver1j(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DishReceiver1k: public DishReceiver1
{
  Q_OBJECT

public:
  DishReceiver1k(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DishReceiver1l: public DishReceiver1
{
  Q_OBJECT

public:
  DishReceiver1l(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DishReceiver1m: public DishReceiver1
{
  Q_OBJECT

public:
  DishReceiver1m(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DishReceiver1n: public DishReceiver1
{
  Q_OBJECT

public:
  DishReceiver1n(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DishReceiver1o: public DishReceiver1
{
  Q_OBJECT

public:
  DishReceiver1o(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // DISH_H
