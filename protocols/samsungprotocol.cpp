/*
#include "samsungprotocol.h"

SamsungProtocol::SamsungProtocol(
  QObject *guiObject,
  unsigned int index)
  : NECProtocol(
      guiObject, index,
      true, // extended NEC
      false) // doesn't use short repeat
{
  // Samsung doesn't use the normal header, don't ask me why...
  headerPulse = 4500;
  headerSpace = 4500;
}
*/
