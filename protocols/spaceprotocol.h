#ifndef SPACEPROTOCOL_H
#define SPACEPROTOCOL_H

#include "pirprotocol.h"

class PIRInfraredLED;

// This class supports the generic (LIRC-based) space encoded IR protocol.
// It is intended to support all other space-based protocols through
// inheritance, and as such contains a variety of commonly useful methods and
// attributes.

class SpaceProtocol: public PIRProtocol
{
public:
  SpaceProtocol(
    QObject *guiObject,
    unsigned int index,
    unsigned int zerop,
    unsigned int zeros,
    unsigned int onep,
    unsigned int ones,
    unsigned int headerp,
    unsigned int headers,
    unsigned int trailerp,
    unsigned int gaps,
    bool iclflag);

protected:
  int pushBits(
    const CommandSequence &bits,
    PIRInfraredLED &led);

  int pushReverseBits(
    const CommandSequence &bits,
    PIRInfraredLED &led);

  int pushInvertedBits(
    const CommandSequence &bits,
    PIRInfraredLED &led);

  int pushInvertedReverseBits(
    const CommandSequence &bits,
    PIRInfraredLED &led);

  unsigned int zeroPulse;
  unsigned int zeroSpace;
  unsigned int onePulse;
  unsigned int oneSpace;

  unsigned int headerPulse;
  unsigned int headerSpace;

  unsigned int trailerPulse;
};

#endif // SPACEPROTOCOL_H
