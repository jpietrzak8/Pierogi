#ifndef AIWAPROTOCOL_H
#define AIWAPROTOCOL_H

#include "spaceprotocol.h"

class PIRInfraredLED;

//
// Aiwa's protocol is mostly similar to the NEC protocol, with a slightly
// different repeat pulse, and a slightly larger than normal address space.
//

class AiwaProtocol: public SpaceProtocol
{
public:
  AiwaProtocol(
    QObject *guiObject,
    unsigned int index);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);

private:
  unsigned int repeatPulse;
  unsigned int repeatSpace;

  int generateStandardCommand(
    const PIRKeyBits &bits,
    PIRInfraredLED &led);

  int generateRepeatCommand(
    PIRInfraredLED &led);
};

#endif // AIWAPROTOCOL_H
