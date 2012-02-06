#ifndef RC5PROTOCOL_H
#define RC5PROTOCOL_H

#include "pirprotocol.h"

class PIRRX51Hardware;

//
// The RC5 protocol is not as widespread as the NEC protocol, but still
// somewhat popular.  Philips, the inventor, uses it extensively.
//

class RC5Protocol: public PIRProtocol
{
public:
  // For standard RC5, the control portion will be passed in as
  // a seven-bit value:
  RC5Protocol(
    QObject *guiObject,
    unsigned int index,
    unsigned int sevenBitControl);

  // For extended RC5, each key must contain the entire 13 bits.
  RC5Protocol(
    QObject *guiObject,
    unsigned int index);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);

protected:
  unsigned int biphaseUnit;

private:
  int pushControlBits(
    PIRRX51Hardware &device);

  int pushKeyCommandBits(
    const PIRKeyBits &pkb,
    PIRRX51Hardware &device);

  int pushNonStandardRC5(
    const PIRKeyBits &bits,
    PIRRX51Hardware &device);

  int pushBit(
    bool bitValue,
    PIRRX51Hardware &device);

  unsigned int buffer;
  int keypressCount;

  // Only one of the following can be true, but both can be false:
  bool bufferContainsSpace;
  bool bufferContainsPulse;
};

#endif // RC5PROTOCOL_H
