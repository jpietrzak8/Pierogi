#ifndef DISHPROTOCOL_H
#define DISHPROTOCOL_H

#include "spaceprotocol.h"

class PIRRX51Hardware;

//
// The Dish protocol is space encoded, but otherwise is unlike just about
// any other protocol out there.
//

class DishProtocol: public SpaceProtocol
{
public:
  DishProtocol(
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

#endif // DISHPROTOCOL_H
