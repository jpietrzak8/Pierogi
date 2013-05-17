#ifndef TDCPROTOCOL_H
#define TDCPROTOCOL_H

#include "pirprotocol.h"

class PIRInfraredLED;

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
    PIRInfraredLED &led);

  int pushBit(
    bool bitValue,
    PIRInfraredLED &led);

  unsigned int biphaseUnit;
  unsigned int buffer;
  bool bufferContainsSpace;
  bool bufferContainsPulse;
};

#endif // TDCPROTOCOL_H
