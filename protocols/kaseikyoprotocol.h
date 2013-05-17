#ifndef KASEIKYOPROTOCOL_H
#define KASEIKYOPROTOCOL_H

#include "spaceprotocol.h"

class PIRInfraredLED;

//
// The Kaseikyo protocol is a more complex protocol than NEC or RC5 (although
// not nearly reaching the level of RC6).  I don't have enough information on
// it yet to understand all of its workings.
//

class KaseikyoProtocol: public SpaceProtocol
{
public:
  KaseikyoProtocol(
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

  void generateChecksum(
    const CommandSequence &bits,
    CommandSequence &checksum);

  void generateLittleChecksum(
    const CommandSequence &firstBits,
    const CommandSequence &secondBits,
    CommandSequence &littleChecksum);
};

#endif // KASEIKYOPROTOCOL_H
