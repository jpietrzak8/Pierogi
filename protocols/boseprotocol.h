#ifndef BOSEPROTOCOL_H
#define BOSEPROTOCOL_H

#include "spaceprotocol.h"

class PIRRX51Hardware;

//
// Bose appears to be using a simplified version of the NEC protocol; it
// has a smaller header, and completely omits the device address portion
// of the protocol (so, only the command portion is sent).
//

class BoseProtocol: public SpaceProtocol
{
public:
  BoseProtocol(
    QObject *guiObject,
    unsigned int index);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);

private:
  int generateStandardCommand(
    const PIRKeyBits &bits,
    PIRRX51Hardware &device);
};

#endif // BOSEPROTOCOL_H
