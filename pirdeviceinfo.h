#ifndef PIRDEVICEINFO_H
#define PIRDEVICEINFO_H

#include "pirmakenames.h"
#include "pirdevicetypenames.h"

#include <map>

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

bool operator< (
  const DeviceInfo &a,
  const DeviceInfo &b);

typedef std::map<DeviceInfo, unsigned int> PIRDeviceCollection;

typedef std::pair<DeviceInfo, unsigned int> PIRDCPair;

#endif // PIRDEVICEINFO_H
