//
// kenwood.h
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

#ifndef KENWOOD_H
#define KENWOOD_H

#include "pirkeysetmetadata.h"

class QObject;
class QComboBox;

class KenwoodAudio1: public PIRKeysetMetaData
{
public:
  KenwoodAudio1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class KenwoodComponent1: public PIRKeysetMetaData
{
public:
  KenwoodComponent1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class KenwoodComponent2: public PIRKeysetMetaData
{
public:
  KenwoodComponent2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class KenwoodComponent3: public PIRKeysetMetaData
{
public:
  KenwoodComponent3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class KenwoodCD1: public PIRKeysetMetaData
{
public:
  KenwoodCD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class KenwoodDVD1: public PIRKeysetMetaData
{
public:
  KenwoodDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class KenwoodTV1: public PIRKeysetMetaData
{
public:
  KenwoodTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

#endif // KENWOOD_H
