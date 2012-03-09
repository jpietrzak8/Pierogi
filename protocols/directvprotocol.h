#ifndef DIRECTVPROTOCOL_H
#define DIRECTVPROTOCOL_H

#include "pirprotocol.h"

class PIRRX51Hardware;

enum DirectvGapSize
{
  ShortGap_Directv,
  LongGap_Directv
};

enum DirectvFreq
{
  LowFreq_Directv,
  MediumFreq_Directv,
  HighFreq_Directv
};

class DirectvProtocol: public PIRProtocol
{
public:
  DirectvProtocol(
    QObject *guiObject,
    unsigned int index);

  void setProtocolParms(
    DirectvGapSize gap,
    DirectvFreq freq);

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
