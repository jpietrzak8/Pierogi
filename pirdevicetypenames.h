#ifndef PIRDEVICETYPENAMES_H
#define PIRDEVICETYPENAMES_H

#include <set>
#include <map>

#include <QComboBox>

enum PIRDeviceTypeName {
  Any_Device,
  TV_Device,
  VCR_Device,
  DVD_Device,
  Audio_Device,
  Computer_Device,
  Other_Device
};

typedef std::set<PIRDeviceTypeName> PIRDeviceTypeCollection;
typedef std::map<PIRDeviceTypeName, const char *> PIRDeviceStringCollection;

class PIRDeviceTypeMgr
{
public:
  PIRDeviceTypeMgr();

  const char *getDeviceString(
    PIRDeviceTypeName n);

  void populateComboBox(
    QComboBox *cb);

private:
  PIRDeviceStringCollection devices;
};

#endif // PIRDEVICETYPENAMES_H
