#ifndef RC6SKYPROTOCOL_H
#define RC6SKYPROTOCOL_H

#include "pirprotocol.h"

class PIRInfraredLED;

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
    PIRInfraredLED &led);

  int pushZero(
    PIRInfraredLED &led);

  int pushOne(
    PIRInfraredLED &led);

  unsigned int biphaseUnit;

  unsigned int buffer;
  int keypressCount;

  bool bufferContainsSpace;
  bool bufferContainsPulse;
};

#endif // RC6SKYPROTOCOL_H 
