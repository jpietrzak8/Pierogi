#ifndef PIRKEYSETMETADATA_H
#define PIRKEYSETMETADATA_H

#include <map>
#include <list>
//#include <string>

#include "pirkeynames.h"
#include "pirmakenames.h"
#include "pirdevicetypenames.h"
#include "pirkeysetwidgetitem.h"
#include "pirprotocol.h"

typedef std::map<PIRKeyName, const char *> KeyCollection;

class DeviceInfo
{
public:
  DeviceInfo(
    PIRMakeName ma,
    const char *mo,
    PIRDeviceTypeName t)
  : make(ma),
    model(mo),
    type(t)
  {}

  PIRMakeName make;
  const char *model;
  PIRDeviceTypeName type;
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

  void populateDeviceTypes(
    PIRKeysetWidgetItem *kwi);

protected:
  void addControlledDevice(
    PIRMakeName make,
    const char *model,
    PIRDeviceTypeName type);

  void addDeviceType(
    PIRDeviceTypeName n);

  void addKey(
    const char *name,
    PIRKeyName key,
    unsigned long data,
    unsigned int bits);

  void setPreData(
    unsigned long data,
    unsigned int bits);

  void setPostData(
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
  PIRDeviceTypeCollection deviceTypes;

  unsigned int id;
};


#endif // PIRKEYSETMETADATA_H
