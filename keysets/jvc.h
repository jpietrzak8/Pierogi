//
// jvc.h
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

#ifndef JVC_H
#define JVC_H

#include "pirkeysetmetadata.h"

class QObject;

class JVCSat1: public PIRKeysetMetaData
{
public:
  JVCSat1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class JVCSat2: public PIRKeysetMetaData
{
public:
  JVCSat2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class JVCVCR1: public PIRKeysetMetaData
{
public:
  JVCVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class JVCVCR1a: public JVCVCR1
{
public:
  JVCVCR1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class JVCVCRBmode1: public JVCVCR1
{
public:
  JVCVCRBmode1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class JVCVCRBmode1a: public JVCVCR1a
{
public:
  JVCVCRBmode1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class JVCTV1: public PIRKeysetMetaData
{
public:
  JVCTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class JVCTV1a: public JVCTV1
{
public:
  JVCTV1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class JVCTV1b: public JVCTV1
{
public:
  JVCTV1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class JVCTV1c: public JVCTV1
{
public:
  JVCTV1c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class JVCTV1d: public JVCTV1
{
public:
  JVCTV1d(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class JVCDAT1: public PIRKeysetMetaData
{
public:
  JVCDAT1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class JVCCarDeck1: public PIRKeysetMetaData
{
public:
  JVCCarDeck1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class JVCAudio1: public PIRKeysetMetaData
{
public:
  JVCAudio1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class JVCAudio1a: public JVCAudio1
{
public:
  JVCAudio1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class JVCAudio1b: public JVCAudio1
{
public:
  JVCAudio1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class JVCAudio2: public PIRKeysetMetaData
{
public:
  JVCAudio2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class JVCDVD1: public PIRKeysetMetaData
{
public:
  JVCDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // JVC_H
