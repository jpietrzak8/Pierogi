#ifndef RC5PROTOCOL_H
#define RC5PROTOCOL_H

#include "pirprotocol.h"
#include "pirrx51hardware.h"

//
// The RC5 protocol is not as widespread as the NEC protocol, but still
// somewhat popular.  Philips, the inventor, uses it extensively.
//

class RC5Protocol: public PIRProtocol
{
public:
  RC5Protocol(
    QObject *guiObject,
    unsigned int index,
    unsigned int bPulse,
    unsigned int bSpace,
    unsigned int lPulse,
    unsigned int gSpace,
    bool iclflag);

  void setHeaderPair(
    unsigned int pulse,
    unsigned int space);

  void setToggleBit(
    unsigned int bit);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);

protected:
  unsigned int biphasePulse;
  unsigned int biphaseSpace;

  unsigned int leadPulse;

  unsigned int headerPulse;
  unsigned int headerSpace;
  bool hasHeaderPair;

  // The original RC-5 specification marks a single bit as a "toggle bit",
  // which should be inverted on each separate keypress.  This was originally
  // the third bit, but apparently some remotes invert a different bit.
  // If set to 0, then no bits are inverted.
  int toggleBit;

private:
  int pushBits(
    const CommandSequence &bits,
    PIRRX51Hardware &device);

  unsigned int buffer;
  int keypressCount;

  // Only one of the following can be true, but both can be false:
  bool bufferContainsSpace;
  bool bufferContainsPulse;
};

#endif // RC5PROTOCOL_H
