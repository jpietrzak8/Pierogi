#ifndef GIPROTOCOL_H
#define GIPROTOCOL_H

#include "spaceprotocol.h"

class PIRRX51Hardware;

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
    PIRRX51Hardware &device);

  int generateRepeatCommand(
    PIRRX51Hardware &device);
};

#endif // GIPROTOCOL_H
