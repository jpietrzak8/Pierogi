#ifndef RC6PROTOCOL_H
#define RC6PROTOCOL_H

#include "pirprotocol.h"

class PIRRX51Hardware;

//
// The RC6 protocol is a much fancier, much more complex successor to the
// RC5 protocol.  The following code does not come close to supporting
// all the possible permutations of this protocol!
//

class RC6Protocol: public PIRProtocol
{
public:
  RC6Protocol(
    QObject *guiObject,
    unsigned int index,
    unsigned int eightBitControl);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);

protected:
  unsigned int biphaseUnit;

private:
  int pushBits(
    const CommandSequence &bits,
    PIRRX51Hardware &device);

  unsigned int buffer;
  int keypressCount;

  bool bufferContainsSpace;
  bool bufferContainsPulse;
};

#endif // RC6PROTOCOL_H 
