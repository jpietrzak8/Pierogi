#ifndef DIRECTVPROTOCOL_H
#define DIRECTVPROTOCOL_H

#include "pirprotocol.h"

class PIRRX51Hardware;

enum DirectvFreq
{
  LowFreq,
  MediumFreq,
  HighFreq
};

class DirectvProtocol: public PIRProtocol
{
public:
  DirectvProtocol(
    QObject *guiObject,
    unsigned int index,
    DirectvFreq freq,
    bool longGapFlag);

private:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);

  int generateStandardCommand(
    const PIRKeyBits &pkb,
    PIRRX51Hardware &rx51device);

  int pushDTVBits(
    const CommandSequence &bits,
    PIRRX51Hardware &device);

  void generateChecksum(
    const CommandSequence &bits,
    CommandSequence &checksumBits);
};

#endif // DIRECTVPROTOCOL_H
