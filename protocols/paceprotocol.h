#ifndef PACEPROTOCOL_H
#define PACEPROTOCOL_H

#include "spaceprotocol.h"

class PIRInfraredLED;

// The "Pace" protocol seems to be a very simple space-encoded protocol
// with little more than the command code and a toggle bit.

class PaceProtocol: public SpaceProtocol
{
public:
  PaceProtocol(
    QObject *guiObject,
    unsigned int index);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);

private:
  unsigned int keypressCount;

  int generateStandardCommand(
    const PIRKeyBits &bits,
    PIRInfraredLED &led);
};

#endif // PACEPROTOCOL_H
