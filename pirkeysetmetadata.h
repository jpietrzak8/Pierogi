#ifndef PIRKEYSETMETADATA_H
#define PIRKEYSETMETADATA_H

//#include <set>
#include <map>
#include <list>
//#include <string>

#include "pirkeynames.h"
#include "pirmakenames.h"

#include "pirprotocol.h"

typedef std::map<PIRKeyName, const char *> KeyCollection;

enum DeviceType
{
  TV_Device,
  VCR_Device,
  DVD_Device,
  Audio_Device,
  Computer_Device
};

class DeviceInfo
{
public:
  DeviceInfo(
    PIRMakeName ma,
    const char *mo,
    DeviceType t)
  : make(ma),
    model(mo),
    type(t)
  {}

  PIRMakeName make;
  const char *model;
  DeviceType type;
};

typedef std::list<DeviceInfo> DeviceCollection;

class PIRKeysetMetaData
{
public:
  PIRKeysetMetaData(
    const char *keysetName,
    PIRMakeName make,
    unsigned int index);

  bool hasKey(
    PIRKeyName name);

  unsigned int getID();

  PIRMakeName getMake();
  const char *getKeysetName();

  void moveProtocolToThread(
    QThread &thread);

protected:
  void addControlledDevice(
    PIRMakeName make,
    const char *model,
    DeviceType type);

  void addKey(
    const char *name,
    PIRKeyName key,
    unsigned long data,
    unsigned int bits);

  KeyCollection keys;

  DeviceCollection controlledDevices;

  PIRProtocol *threadableProtocol;

  void setKeysetName(
    const char *name);

private:
  const char *keysetName;
  PIRMakeName make;

  unsigned int id;
};


#endif // PIRKEYSETMETADATA_H
