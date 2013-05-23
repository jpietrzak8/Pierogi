//
// pirapplication.h
//
// A specialization of the QApplication class, currently used to set up the
// Nokia N900's volume rocker switch to control the current keyset.
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

#ifndef PIRAPPLICATION_H
#define PIRAPPLICATION_H

#include <QApplication>

class QWidget;

class PIRApplication: public QApplication
{
  Q_OBJECT
public:
  PIRApplication(
    int &argc,
    char **argv);

  void setupRockerSwitch(
    QWidget *window);

  virtual bool x11EventFilter(
    XEvent *event);

signals:
  void increaseRockerPressed();
  void decreaseRockerPressed();

private slots:
  void finishChangingKeyset();

private:
  bool changingKeyset;
};

#endif // PIRAPPLICATION_H
