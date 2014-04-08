//
// insignia.h
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

#ifndef INSIGNIA_H
#define INSIGNIA_H

#include "pirkeysetmetadata.h"

class QObject;
class QComboBox;

class InsigniaTV1: public PIRKeysetMetaData
{
public:
  InsigniaTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class InsigniaTV1a: public InsigniaTV1
{
public:
  InsigniaTV1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class InsigniaTV2: public PIRKeysetMetaData
{
public:
  InsigniaTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class InsigniaTV3: public PIRKeysetMetaData
{
public:
  InsigniaTV3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class InsigniaTV4: public PIRKeysetMetaData
{
public:
  InsigniaTV4(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class InsigniaTV5: public PIRKeysetMetaData
{
public:
  InsigniaTV5(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class InsigniaTV6: public PIRKeysetMetaData
{
public:
  InsigniaTV6(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class InsigniaDVD1: public PIRKeysetMetaData
{
public:
  InsigniaDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class InsigniaDVD2: public PIRKeysetMetaData
{
public:
  InsigniaDVD2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class InsigniaDVD3: public PIRKeysetMetaData
{
public:
  InsigniaDVD3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

class InsigniaDVD4: public PIRKeysetMetaData
{
public:
  InsigniaDVD4(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

//  virtual void populateInputList(
//    QComboBox *cb);
};

class InsigniaDVD5: public PIRKeysetMetaData
{
public:
  InsigniaDVD5(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class InsigniaDVD6: public PIRKeysetMetaData
{
public:
  InsigniaDVD6(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb);
};

#endif // INSIGNIA_H
