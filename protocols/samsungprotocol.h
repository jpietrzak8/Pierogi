#ifndef SAMSUNGPROTOCOL_H
#define SAMSUNGPROTOCOL_H

#include "necprotocol.h"
#include "pirrx51hardware.h"

//
// The Samsung protocol is basically identical to the NEC protocol, except
// that the header pulse is different.  I have no clue why they did this...
//

class SamsungProtocol: public NECProtocol
{
public:
  SamsungProtocol(
    QObject *guiObject,
    unsigned int index);
};

#endif // SAMSUNGPROTOCOL_H
