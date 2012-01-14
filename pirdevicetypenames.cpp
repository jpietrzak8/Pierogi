#include "pirdevicetypenames.h"

PIRDeviceTypeMgr::PIRDeviceTypeMgr()
{
  devices[Any_Device] = "Any";
  devices[TV_Device] = "TV";
  devices[VCR_Device] = "VCR";
  devices[DVD_Device] = "DVD";
  devices[Audio_Device] = "Audio";
  devices[Computer_Device] = "Computer";
}

const char *PIRDeviceTypeMgr::getDeviceString(
  PIRDeviceTypeName n)
{
  return devices[n];
}

void PIRDeviceTypeMgr::populateComboBox(
  QComboBox *cb)
{
  PIRDeviceStringCollection::const_iterator i = devices.begin();
  while (i != devices.end())
  {
    cb->insertItem(i->first, QString(i->second));
    ++i;
  }
}
