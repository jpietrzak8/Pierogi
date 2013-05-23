//
// goldstar.h
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

#ifndef GOLDSTAR_H
#define GOLDSTAR_H

#include "pirkeysetmetadata.h"

class QObject;

class GoldStarTV1: public PIRKeysetMetaData
{
public:
  GoldStarTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class GoldStarTV2: public PIRKeysetMetaData
{
public:
  GoldStarTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class GoldStarVCR1: public PIRKeysetMetaData
{
public:
  GoldStarVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class GoldStarVCR1a: public GoldStarVCR1
{
public:
  GoldStarVCR1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class GoldStarVCR1b: public GoldStarVCR1
{
public:
  GoldStarVCR1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class GoldStarVCR1c: public GoldStarVCR1
{
public:
  GoldStarVCR1c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class GoldStarCD1: public PIRKeysetMetaData
{
public:
  GoldStarCD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // GOLDSTAR_H
