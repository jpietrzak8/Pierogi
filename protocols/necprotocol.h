#ifndef NECPROTOCOL_H
#define NECPROTOCOL_H

#include "spaceprotocol.h"

class PIRRX51Hardware;

//
// The "NEC" Protocol is, more or less, followed by the majority of
// remotes defined in the LIRC config files, which means it is probably
// followed by most of the remotes out there.
//

//
// There exist two well-defined NEC protocols: "standard" and "extended".  The
// extended form sacrifices some redundancy to increase the size of the
// address data.
//
// Also, NEC has two types of repeat -- a "short repeat", sending only the
// header value, and a full repetition of the command pulse train.
//

class NECProtocol: public SpaceProtocol
{
public:
  NECProtocol(
    QObject *guiObject,
    unsigned int index,
    bool extNEC,
    bool srtRep);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);

private:
  unsigned int repeatPulse;
  unsigned int repeatSpace;

  bool isExtendedNEC;
  bool isShortRepeat;

  int generateStandardCommand(
    const PIRKeyBits &bits,
    PIRRX51Hardware &device);

  int generateRepeatCommand(
    PIRRX51Hardware &device);
};

#endif // NECPROTOCOL_H
