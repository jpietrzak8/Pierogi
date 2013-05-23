//
// directv.h
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

#ifndef DIRECTV_H
#define DIRECTV_H

#include "pirkeysetmetadata.h"
#include "protocols/directvprotocol.h"

class QObject;

class DirectvReceiver1: public PIRKeysetMetaData
{
public:
  DirectvReceiver1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

protected:
  void dtvPopulateProtocol(
    QObject *guiObject,
    DirectvGapSize gap,
    DirectvFreq freq);
};

class DirectvReceiver1a: public DirectvReceiver1
{
public:
  DirectvReceiver1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DirectvReceiver1b: public DirectvReceiver1
{
public:
  DirectvReceiver1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DirectvReceiver1c: public DirectvReceiver1
{
public:
  DirectvReceiver1c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DirectvReceiver1d: public DirectvReceiver1
{
public:
  DirectvReceiver1d(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DirectvReceiver1e: public DirectvReceiver1
{
public:
  DirectvReceiver1e(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // DIRECTV_H
