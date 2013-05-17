#ifndef SHARPPROTOCOL_H
#define SHARPPROTOCOL_H

#include "spaceprotocol.h"

class PIRInfraredLED;

//
// Sharp has its own protocol.  It is "space-encoded", like the popular NEC
// protocol (i.e., a 1 takes longer to transmit than a 0), but differs in
// several ways.  Most notably, the entire command section of the pulse
// train is inverted for each odd-numbered repetition.  Also, there is no
// header pulse.
//

class SharpProtocol: public SpaceProtocol
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
  // An "expansion bit".  Not sure what this is, but Sharp seems to leave it
  // at 1, and Denon usually sets it to 0.
  bool expansionBit;

  int generateStandardCommand(
    const PIRKeyBits &pkb,
    PIRInfraredLED &led);

  int generateToggledCommand(
    const PIRKeyBits &pkb,
    PIRInfraredLED &led);
};

#endif // SHARPPROTOCOL_H
