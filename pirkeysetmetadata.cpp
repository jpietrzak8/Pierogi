#include "pirkeysetmetadata.h"

PIRKeysetMetaData::PIRKeysetMetaData(
  const char *r,
  PIRMakeName m,
  unsigned int i)
  : keysetName(r),
    make(m),
    id(i)
{
}

bool PIRKeysetMetaData::hasKey(
  PIRKeyName name)
{
  return (keys.find(name) != keys.end());
}


void PIRKeysetMetaData::moveProtocolToThread(
  QThread &thread)
{
  threadableProtocol->moveToThread(&thread);
}


unsigned int PIRKeysetMetaData::getID()
{
  return id;
}


void PIRKeysetMetaData::addControlledDevice(
  PIRMakeName make,
  const char *model,
  DeviceType type)
{
  controlledDevices.push_back(DeviceInfo(make, model, type));
}


void PIRKeysetMetaData::addKey(
  const char *name,
  PIRKeyName key,
  unsigned long data,
  unsigned int bits)
{
  // Don't have a system for the unmapped keys yet!
  if (key != Unmapped_Key)
  {
    keys[key] = name;
  }

  threadableProtocol->addKey(key, data, bits);
}


PIRMakeName PIRKeysetMetaData::getMake()
{
  return make;
}

const char *PIRKeysetMetaData::getKeysetName()
{
  return keysetName;
}


void PIRKeysetMetaData::setKeysetName(
  const char *n)
{
  keysetName = n;
}
