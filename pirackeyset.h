#ifndef PIRACKEYSET_H
#define PIRACKEYSET_H

#include "pirkeysetmetadata.h"

// A special meta data subclass for stateful air conditioner remotes:

#include "pirstatepairs.h"

class PIRACKeyset: public PIRKeysetMetaData
{
public:
  PIRACKeyset(
    const char *keysetName,
    PIRMakeName make,
    unsigned int index);

/*
  virtual void populateProtocol(
    QObject *guiObject);
*/

  virtual void getTurboModePairs(
    PIRStatePairs &turboModePairs) const;

  virtual void getSwingPairs(
    PIRStatePairs &swingPairs) const;

  virtual void getTemperaturePairs(
    PIRStatePairs &temperaturePairs) const;

  virtual void getFanPairs(
    PIRStatePairs &fanPairs) const;

  virtual void getModePairs(
    PIRStatePairs &modePairs) const;

  virtual void getAirCleanPairs(
    PIRStatePairs &aircleanPairs) const;

  virtual void getPowerPairs(
    PIRStatePairs &powerPairs) const;

  virtual void getTimerOptionPairs(
    PIRStatePairs &timerOptionPairs) const;

  void resetPairs(
    PIRStatePairs &pairs) const;
};

#endif // PIRACKEYSET_H
