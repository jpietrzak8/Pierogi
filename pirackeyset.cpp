#include "pirackeyset.h"

PIRACKeyset::PIRACKeyset(
  const char *keysetName,
  PIRMakeName make,
  unsigned int index)
  : PIRKeysetMetaData(keysetName, make, index)
{
}


void PIRACKeyset::getTurboModePairs(
  PIRStatePairs &turboModePairs) const
{
  resetPairs(turboModePairs);
}


void PIRACKeyset::getSwingPairs(
  PIRStatePairs &swingPairs) const
{
  resetPairs(swingPairs);
}


void PIRACKeyset::getTemperaturePairs(
  PIRStatePairs &temperaturePairs) const
{
  resetPairs(temperaturePairs);
}


void PIRACKeyset::getFanPairs(
  PIRStatePairs &fanPairs) const
{
  resetPairs(fanPairs);
}


void PIRACKeyset::getModePairs(
  PIRStatePairs &modePairs) const
{
  resetPairs(modePairs);
}


void PIRACKeyset::getAirCleanPairs(
  PIRStatePairs &aircleanPairs) const
{
  resetPairs(aircleanPairs);
}


void PIRACKeyset::getPowerPairs(
  PIRStatePairs &powerPairs) const
{
  resetPairs(powerPairs);
}


void PIRACKeyset::getTimerOptionPairs(
  PIRStatePairs &timerOptionPairs) const
{
  resetPairs(timerOptionPairs);
}


void PIRACKeyset::resetPairs(
  PIRStatePairs &pairs) const
{
  PIRStatePairs::iterator i = pairs.begin();

  while (i != pairs.end())
  {
    delete (*i);
    ++i;
  }

  pairs.clear();
}
