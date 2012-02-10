#ifndef MCEPROTOCOL_H
#define MCEPROTOCOL_H

#include "pirprotocol.h"

class PIRRX51Hardware;

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
    PIRRX51Hardware &device);

  int pushZero(
    PIRRX51Hardware &device);

  int pushOne(
    PIRRX51Hardware &device);

  unsigned int biphaseUnit;

  CommandSequence oemBits;

  unsigned int buffer;
  int keypressCount;

  bool bufferContainsSpace;
  bool bufferContainsPulse;
};

#endif // MCEPROTOCOL_H 
