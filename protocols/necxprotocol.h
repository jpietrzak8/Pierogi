#ifndef NECXPROTOCOL_H
#define NECXPROTOCOL_H

#include "spaceprotocol.h"

class PIRRX51Hardware;

//
// The "NECX" protocol is a slight variation on the popular NEC protocol.
// It includes the "short repeat" feature of NEC, but implements it in a
// slightly different way.
//

class NECXProtocol: public SpaceProtocol
{
public:
  NECXProtocol(
    QObject *guiObject,
    unsigned int index,
    bool srtRep);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);

private:
  bool isShortRepeat;

  int generateStandardCommand(
    const PIRKeyBits &bits,
    PIRRX51Hardware &device);

  int generateRepeatCommand(
    PIRRX51Hardware &device);
};

#endif // NECXPROTOCOL_H
