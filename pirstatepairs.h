//
// pirstatepairs.h
//
// Copyright 2012, 2013 by John Pietrzak  (jpietrzak8@gmail.com)
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

#ifndef PIRSTATEPAIRS_H
#define PIRSTATEPAIRS_H

// For air conditioner remotes that maintain state information, we need
// to set up a panel with all the options available to the user.  To do
// this, the "PIRStatePair" structure will contain a list of state names
// and corresponding code values; the keyset object will populate these
// lists of pairs, the AC Panel will display the lists of pairs, and the
// protocol object will retrieve the chosen code values to construct the
// full IR command.

#include <list>
#include <QString>

class PIRStatePair
{
public:
  PIRStatePair(
    QString n,
    unsigned int c);

  QString getName();

  unsigned int getCode();

private:
  QString name;
  unsigned int code;
};

typedef std::list<PIRStatePair *> PIRStatePairs;

// -------- inline method definitions:

inline PIRStatePair::PIRStatePair(
  QString n,
  unsigned int c)
  : name(n),
    code(c)
{
}

inline QString PIRStatePair::getName()
{
  return name;
}

inline unsigned int PIRStatePair::getCode()
{
  return code;
}

#endif // PIRSTATEPAIRS_H
