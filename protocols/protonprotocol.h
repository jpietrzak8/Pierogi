#ifndef PROTONPROTOCOL_H
#define PROTONPROTOCOL_H

#include "spaceprotocol.h"

class PIRRX51Hardware;

//
// The Proton protocol looks a bit like a stripped-down NEC protocol.
//

class ProtonProtocol: public SpaceProtocol
{
public:
  ProtonProtocol(
    QObject *guiObject,
    unsigned int index);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);

private:
  int generateStandardCommand(
    const PIRKeyBits &bits,
    PIRRX51Hardware &device);
};

#endif // PROTONPROTOCOL_H
