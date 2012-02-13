#ifndef THOMSONPROTOCOL_H
#define THOMSONPROTOCOL_H

#include "spaceprotocol.h"

class PIRRX51Hardware;

//
// Thomson protocol is a nice little protocol, taking space-encoded values
// from the NEC protocol family and adding a toggle bit from the Philips
// family...
//

class ThomsonProtocol: public SpaceProtocol
{
public:
  ThomsonProtocol(
    QObject *guiObject,
    unsigned int index);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);

private:
  unsigned int keypressCount;

  int generateStandardCommand(
    const PIRKeyBits &bits,
    PIRRX51Hardware &device);
};

#endif // NECPROTOCOL_H
