#ifndef DAEWOOPROTOCOL_H
#define DAEWOOPROTOCOL_H

#include "spaceprotocol.h"

class PIRInfraredLED;

//
// Daewoo is using something that looks like a simplified NEC protocol,
// lacking the inverted copy of the data that NEC sends, and with the addition
// of a marker bit sent inbetween the address and the command.
//

class DaewooProtocol: public SpaceProtocol
{
public:
  DaewooProtocol(
    QObject *guiObject,
    unsigned int index);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);

private:
  unsigned int midPulse;
  unsigned int midSpace;

  int generateStandardCommand(
    const PIRKeyBits &bits,
    PIRInfraredLED &led);
};

#endif // DAEWOOPROTOCOL_H
