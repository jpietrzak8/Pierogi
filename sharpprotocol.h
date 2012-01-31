#ifndef SHARPPROTOCOL_H
#define SHARPPROTOCOL_H

#include "pirprotocol.h"
#include "pirrx51hardware.h"

//
// Sharp has its own protocol.  It is "space-encoded", like the popular NEC
// protocol (i.e., a 1 takes longer to transmit than a 0), but differs in
// several ways.  Most notably, the entire command section of the pulse
// train is inverted for each odd-numbered repetition.  Also, there is no
// header pulse.
//

class SharpProtocol: public PIRProtocol
{
public:
  SharpProtocol(
    QObject *guiObject,
    unsigned int index,
    bool expBit);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);

private:
  // First, define what is used to represent 0 and 1:
  unsigned int zeroPulse;
  unsigned int zeroSpace;
  unsigned int onePulse;
  unsigned int oneSpace;

  // A tailing on-request, not followed by a specific off time:
  unsigned int trailerPulse;

  // An "expansion bit".  Not sure what this is, but Sharp seems to leave it
  // at 1, and Denon usually sets it to 0.
  bool expansionBit;

  int generateStandardCommand(
    const CommandSequence &bits,
    PIRRX51Hardware &device);

  int generateToggledCommand(
    const CommandSequence &bits,
    PIRRX51Hardware &device);

  int pushBits(
    CommandSequence::const_reverse_iterator i,
    CommandSequence::const_reverse_iterator end,
    PIRRX51Hardware &device);

  int pushInvertedBits(
    CommandSequence::const_reverse_iterator i,
    CommandSequence::const_reverse_iterator end,
    PIRRX51Hardware &device);
};

#endif // SHARPPROTOCOL_H
