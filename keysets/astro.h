//
// astro.h
//
// Copyright 2014 by John Pietrzak (jpietrzak8@gmail.com)
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

#ifndef ASTRO_H
#define ASTRO_H

#include "pirkeysetmetadata.h"

class QObject;

class AstroSTB1: public PIRKeysetMetaData
{
public:
  AstroSTB1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class AstroSTB2: public PIRKeysetMetaData
{
public:
  AstroSTB2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // ASTRO_H
