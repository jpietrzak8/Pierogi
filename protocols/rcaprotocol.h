#ifndef RCAPROTOCOL_H
#define RCAPROTOCOL_H

#include "spaceprotocol.h"

class PIRInfraredLED;

//
// Although it is hard to find solid data on the RCA protocol, it seems
// fairly simple; it is really not that much different than the standard NEC
// protocol.  It differs in having only 4 bits of address, a different-sized
// header, it lays out the bits MSB first rather than LSB first, and it lays
// out both the address and the command before inverting both the address
// and command.
//

class RCAProtocol: public SpaceProtocol
{
public:
  RCAProtocol(
    QObject *guiObject,
    unsigned int index);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);

private:
  int generateStandardCommand(
    const PIRKeyBits &bits,
    PIRInfraredLED &led);
};

#endif // RCAPROTOCOL_H
