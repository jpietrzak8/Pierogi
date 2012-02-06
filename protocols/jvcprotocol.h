#ifndef JVCPROTOCOL_H
#define JVCPROTOCOL_H

#include "spaceprotocol.h"

class PIRRX51Hardware;

//
// JVC has its own protocol, similar in some ways to the popular NEC protocol.
// The main differences are that the address and command segments are not
// sent with an inverted copy, and that repeats are implemented by sending
// the body without a header, rather than a header without a body.
//

class JVCProtocol: public SpaceProtocol
{
public:
  JVCProtocol(
    QObject *guiObject,
    unsigned int index);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);

private:
  int generateStandardCommand(
    const PIRKeyBits &pkb,
    PIRRX51Hardware &device);

  int generateHeadlessCommand(
    const PIRKeyBits &pkb,
    PIRRX51Hardware &device);
};

#endif // JVCPROTOCOL_H
