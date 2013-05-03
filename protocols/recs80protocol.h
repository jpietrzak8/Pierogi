#ifndef RECS80PROTOCOL_H
#define RECS80PROTOCOL_H

#include "spaceprotocol.h"

class PIRRX51Hardware;

class RECS80Protocol: public SpaceProtocol
{
public:
  RECS80Protocol(
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

  int keypressCount;
};

#endif // RECS80PROTOCOL_H
