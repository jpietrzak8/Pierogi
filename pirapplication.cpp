//
// pirapplication.cpp
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

#include "pirapplication.h"

#include <QWidget>
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <QX11Info>
#include <QTimer>


PIRApplication::PIRApplication(
  int &argc,
  char **argv)
  : QApplication(argc, argv),
    changingKeyset(false)
{
}


void PIRApplication::setupRockerSwitch(QWidget *window)
{
  // free the rocker switch from the volume controls:
  unsigned long val = 1;

  Atom atom = XInternAtom(QX11Info::display(), "_HILDON_ZOOM_KEY_ATOM", 0);

  XChangeProperty( 
    QX11Info::display(),
    window->winId(),
    atom,
    XA_INTEGER,
    32,
    PropModeReplace,
    (unsigned char *) &val,
    1);
}


bool PIRApplication::x11EventFilter(
  XEvent *event)
{
  // Return true means we will consume the event here; return false means
  // letting the event continue to be passed up the chain.

  if (event->type == KeyPress)
  {
    // Function key 7 (keycode 73) or "Zoom Out" button will go up.
    // Function key 8 (keycode 74) or "Zoom In" button will go down.
    if (
      event->xkey.keycode == 73 ||
      event->xkey.keycode == QKeySequence::ZoomOut)
    {
      if (!changingKeyset)
      {
        changingKeyset = true;
        QTimer::singleShot(500, this, SLOT(finishChangingKeyset()));
        emit decreaseRockerPressed();
      }
      return true;
    }
    else if (
      event->xkey.keycode == 74 ||
      event->xkey.keycode == QKeySequence::ZoomIn)
    {
      if (!changingKeyset)
      {
        changingKeyset = true;
        QTimer::singleShot(500, this, SLOT(finishChangingKeyset()));
        emit increaseRockerPressed();
      }
      return true;
    }
  }

  return false;
}


void PIRApplication::finishChangingKeyset()
{
  changingKeyset = false;
}
