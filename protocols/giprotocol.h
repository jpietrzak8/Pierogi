#ifndef GIPROTOCOL_H
#define GIPROTOCOL_H

#include "spaceprotocol.h"

class PIRInfraredLED;

// The "G.I." protocol appears to be used by some Motorola boxes.

class GIProtocol: public SpaceProtocol
{
public:
  GIProtocol(
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

#endif // GIPROTOCOL_H
