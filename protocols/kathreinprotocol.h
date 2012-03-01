#ifndef KATHREINPROTOCOL_H
#define KATHREINPROTOCOL_H

#include "spaceprotocol.h"

class PIRRX51Hardware;

//
// The Kathrein 24-bit protocol shares some features with the NEC protocol
// (space encoded, LSB order, sends complement of device and command codes),
// but has only a 4-bit address code, and uses a unique repeat mechanism.
//

class KathreinProtocol: public SpaceProtocol
{
public:
  KathreinProtocol(
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

  int generateRepeatCommand(
    const PIRKeyBits &bits,
    PIRRX51Hardware &device);
};

#endif // KATHREINPROTOCOL_H
