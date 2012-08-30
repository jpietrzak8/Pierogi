#ifndef PANASONICOLDPROTOCOL_H
#define PANASONICOLDPROTOCOL_H

#include "spaceprotocol.h"

class PIRRX51Hardware;

//
// This is apparently a very old Panasonic protocol, but still in use by a
// few manufacturers.
//

class PanasonicOldProtocol: public SpaceProtocol
{
public:
  PanasonicOldProtocol(
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

#endif // PANASONICOLDPROTOCOL_H
