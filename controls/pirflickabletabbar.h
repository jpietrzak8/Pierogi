//
// piflicabletabbar.h
//
// Copyright 2014 by John Pietrzak  (jpietrzak8@gmail.com)
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

#ifndef PIRFLICKABLETABBAR_H
#define PIRFLICKABLETABBAR_H

#include <QListWidget>
#include <QSize>

// In order to get a usable horizontal list widget, you have to subclass
// QListWidget and override the size hint.
// Or not!  It looks like I was wrong...

class PIRFlickableTabBar: public QListWidget
{
  Q_OBJECT

public:
  PIRFlickableTabBar(
    QWidget *parent);

protected:
};

#endif // PIRFLICKABLETABBAR_H
