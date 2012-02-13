#ifndef RC6SKYPROTOCOL_H
#define RC6SKYPROTOCOL_H

#include "pirprotocol.h"

class PIRRX51Hardware;

//
// The Sky protocol is a fairly close implementation of RC6 mode 6.
//

class RC6SkyProtocol: public PIRProtocol
{
public:
  RC6SkyProtocol(
    QObject *guiObject,
    unsigned int index);

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

  unsigned int buffer;
  int keypressCount;

  bool bufferContainsSpace;
  bool bufferContainsPulse;
};

#endif // RC6SKYPROTOCOL_H 
