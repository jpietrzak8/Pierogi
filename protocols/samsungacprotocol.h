#ifndef SAMSUNGACPROTOCOL_H
#define SAMSUNGACPROTOCOL_H

#include "spaceprotocol.h"

class PIRRX51Hardware;

class SamsungACProtocol: public SpaceProtocol
{
public:
  SamsungACProtocol(
    QObject *guiObject,
    unsigned int index);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);

  void startSendingStateInfo(
    PIRACStateInfo state,
    unsigned int threadableID,
    PIRKeyName command);

private:
  void generateCommand(
    PIRRX51Hardware &device);

  void calculateChecksum(
    CommandSequence &checksum);

  void generateTimerCommand(
    PIRRX51Hardware &device);

  void calculateTimerChecksum(
    CommandSequence &checksum);

  // Standard state info:
  CommandSequence swing;
  CommandSequence turbo;
  CommandSequence temperature;
  CommandSequence fan;
  CommandSequence mode;
  CommandSequence airclean;
  CommandSequence power;

  // Timer state info (and some kluges):
  CommandSequence timerOption;
  CommandSequence timerHours;
  CommandSequence timerMinutes;
  CommandSequence timerHeader;
  CommandSequence emptyTimer;
  CommandSequence timerFooter;
  CommandSequence fourBitZero;
  int timerCommandType;
};

#endif //SAMSUNGACPROTOCOL_H
