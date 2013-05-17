#ifndef NOKIA32PROTOCOL_H
#define NOKIA32PROTOCOL_H

#include "spaceprotocol.h"

class PIRInfraredLED;

//
// The Nokia32 protocol is a somewhat unusual 32-bit protocol.  It encodes
// pairs of bits rather than individual bits.
//

class Nokia32Protocol: public PIRProtocol
{
public:
  Nokia32Protocol(
    QObject *guiObject,
    unsigned int index);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);

private:
  int generateStandardCommand(
    const PIRKeyBits &bits,
    PIRInfraredLED &led);

  int pushBits(
    const CommandSequence &bits,
    PIRInfraredLED &led);

  int pushToggleAndBits(
    const CommandSequence &bits,
    PIRInfraredLED &led);

  int pushDoubleBit(
    bool firstBit,
    bool secondBit,
    PIRInfraredLED &led);

  unsigned int zeroPulse;
  unsigned int zeroSpace;
  unsigned int onePulse;
  unsigned int oneSpace;
  unsigned int twoPulse;
  unsigned int twoSpace;
  unsigned int threePulse;
  unsigned int threeSpace;

  unsigned int headerPulse;
  unsigned int headerSpace;

  unsigned int trailerPulse;

  unsigned int keypressCount;
};

#endif // NOKIA32PROTOCOL_H
