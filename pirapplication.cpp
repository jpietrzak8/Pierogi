#include "pirapplication.h"

#include <QWidget>
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <QX11Info>

PIRApplication::PIRApplication(
  int &argc,
  char **argv)
  : QApplication(argc, argv)
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
      emit decreaseRockerPressed();
      return true;
    }
    else if (
      event->xkey.keycode == 74 ||
      event->xkey.keycode == QKeySequence::ZoomIn)
    {
      emit increaseRockerPressed();
      return true;
    }
  }

  return false;
}
