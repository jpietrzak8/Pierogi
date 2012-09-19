#ifndef IROBOTPROTOCOL_H
#define IROBOTPROTOCOL_H

#include "spaceprotocol.h"

class PIRRX51Hardware;

// The iRobot protocol is extremely simple, but my sources differ slightly
// on its exact properties (particularly how repetition is handled).  So
// this may need some reworking in the future.

class IRobotProtocol: public SpaceProtocol
{
public:
  IRobotProtocol(
    QObject *guiObject,
    unsigned int index);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);

private:
  int generateCommand(
    const PIRKeyBits &bits,
    PIRRX51Hardware &device);
};

#endif // IROBOTPROTOCOL_H