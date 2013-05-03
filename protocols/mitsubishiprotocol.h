#ifndef MITSUBISHIPROTOCOL_H
#define MITSUBISHIPROTOCOL_H

#include "spaceprotocol.h"

class PIRRX51Hardware;

// The Mitsubishi protocol is a very simple protocol, with no redundancy or
// checksum (or even a header).

class MitsubishiProtocol: public SpaceProtocol
{
public:
  MitsubishiProtocol(
    QObject *guiObject,
    unsigned int index);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);

private:
  int generateCommand(
    const PIRKeyBits &bits,
    PIRRX51Hardware &device);
};

#endif // MITSUBISHIPROTOCOL_H
