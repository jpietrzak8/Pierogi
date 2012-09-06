#ifndef TDCPROTOCOL_H
#define TDCPROTOCOL_H

#include "pirprotocol.h"

class PIRRX51Hardware;

class TDCProtocol: public PIRProtocol
{
public:
  TDCProtocol(
    QObject *guiObject,
    unsigned int index,
    unsigned int deviceBits,
    unsigned int subdeviceBits);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);


private:
  int pushBits(
    const CommandSequence &bits,
    PIRRX51Hardware &device);

  int pushBit(
    bool bitValue,
    PIRRX51Hardware &device);

  unsigned int biphaseUnit;
  unsigned int buffer;
  bool bufferContainsSpace;
  bool bufferContainsPulse;
};

#endif // TDCPROTOCOL_H
