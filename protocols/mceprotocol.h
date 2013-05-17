#ifndef MCEPROTOCOL_H
#define MCEPROTOCOL_H

#include "pirprotocol.h"

class PIRInfraredLED;

//
// The MCE protocol is derived from (but does not exactly match) RC6 mode 6A.
//

class MCEProtocol: public PIRProtocol
{
public:
  MCEProtocol(
    QObject *guiObject,
    unsigned int index,
    unsigned int oemData);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);

private:
  int pushBits(
    const CommandSequence &bits,
    PIRInfraredLED &led);

  int pushZero(
    PIRInfraredLED &led);

  int pushOne(
    PIRInfraredLED &led);

  unsigned int biphaseUnit;

  CommandSequence oemBits;

  unsigned int buffer;
  int keypressCount;

  bool bufferContainsSpace;
  bool bufferContainsPulse;
};

#endif // MCEPROTOCOL_H 
