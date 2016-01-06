//
// mitsubishi.h
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

#ifndef MITSUBISHI_H
#define MITSUBISHI_H

#include "pirkeysetmetadata.h"

class QComboBox;

class MitsubishiTV1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  MitsubishiTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class MitsubishiTV1a: public MitsubishiTV1
{
  Q_OBJECT

public:
  MitsubishiTV1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class MitsubishiVCR1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  MitsubishiVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class MitsubishiVCR1a: public MitsubishiVCR1
{
  Q_OBJECT

public:
  MitsubishiVCR1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class MitsubishiProjector1: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  MitsubishiProjector1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb) const;
};

class MitsubishiProjector2: public PIRKeysetMetaData
{
  Q_OBJECT

public:
  MitsubishiProjector2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

  virtual void populateInputList(
    QComboBox *cb) const;
};

#endif // MITSUBISHI_H
