#include "pirkeysetmetadata.h"
#include "pirkeysetwidgetitem.h"
#include "protocols/pirprotocol.h"

#include <iostream>


PIRKeysetMetaData::PIRKeysetMetaData(
  const char *r,
  PIRMakeName m,
  unsigned int i)
  : threadableProtocol(NULL),
    index(i),
    keysetName(r),
    make(m)
{
}

bool PIRKeysetMetaData::hasKey(
  PIRKeyName name) const
{
  return (keys.find(name) != keys.end());
}


void PIRKeysetMetaData::moveToThread(
  QThread *thread)
{
  if (threadableProtocol)
  {
    // Do I need some error checking here?
    threadableProtocol->moveToThread(thread);
  }
}


void PIRKeysetMetaData::populateDeviceTypes(
  PIRKeysetWidgetItem *kwi) const
{
  PIRDeviceTypeCollection::const_iterator i = deviceTypes.begin();
  while (i != deviceTypes.end())
  {
    kwi->addDeviceType(*i);
    ++i;
  }
}


unsigned int PIRKeysetMetaData::getID() const
{
  return index;
}


PIRMakeName PIRKeysetMetaData::getMake() const
{
  return make;
}

const char *PIRKeysetMetaData::getKeysetName() const
{
  return keysetName;
}


void PIRKeysetMetaData::addControlledDevice(
  PIRMakeName make,
  const char *model,
  PIRDeviceTypeName type)
{
  controlledDevices.push_back(DeviceInfo(make, model, type));

  deviceTypes.insert(type);
}


void PIRKeysetMetaData::addKey(
  const char *name,
  PIRKeyName key,
  unsigned long data,
  unsigned int size)
{
  // Don't have a system for the unmapped keys yet!
  if (key != Unmapped_Key)
  {
    keys[key] = name;

    threadableProtocol->addKey(key, data, size);
  }
}


void PIRKeysetMetaData::addSIRC12Key(
  const char *name,
  PIRKeyName key,
  unsigned int addressData,
  unsigned int commandData)
{
  if (key != Unmapped_Key)
  {
    keys[key] = name;
    threadableProtocol->addSIRCKey(key, addressData, 5, commandData);
  }
}


void PIRKeysetMetaData::addSIRC15Key(
  const char *name,
  PIRKeyName key,
  unsigned int addressData,
  unsigned int commandData)
{
  if (key != Unmapped_Key)
  {
    keys[key] = name;
    threadableProtocol->addSIRCKey(key, addressData, 8, commandData);
  }
}


void PIRKeysetMetaData::addSIRC20Key(
  const char *name,
  PIRKeyName key,
  unsigned int secondaryAddressData,
  unsigned int primaryAddressData,
  unsigned int commandData)
{
  if (key != Unmapped_Key)
  {
    keys[key] = name;
    threadableProtocol->addSIRC20Key(
      key, secondaryAddressData, primaryAddressData, commandData);
  }
}


void PIRKeysetMetaData::addSharpKey(
  const char *name,
  PIRKeyName key,
  unsigned int addressData,
  unsigned int commandData)
{
  if (key != Unmapped_Key)
  {
    keys[key] = name;
    threadableProtocol->addSharpKey(key, addressData, commandData);
  }
}


void PIRKeysetMetaData::addNECKey(
  const char *name,
  PIRKeyName key,
  unsigned int addressData,
  unsigned int commandData)
{
  if (key != Unmapped_Key)
  {
    keys[key] = name;
    threadableProtocol->addNECKey(key, addressData, commandData);
  }
}


void PIRKeysetMetaData::addPioneerKey(
  const char *name,
  PIRKeyName key,
  unsigned int addressOne,
  unsigned int commandOne,
  unsigned int addressTwo,
  unsigned int commandTwo)
{
  if (key != Unmapped_Key)
  {
    keys[key] = name;
    threadableProtocol->addPioneerKey(
      key, addressOne, commandOne, addressTwo, commandTwo);
  }
}


/*
void PIRKeysetMetaData::addRCAKey(
  const char *name,
  PIRKeyName key,
  unsigned int addressData,
  unsigned int commandData)
{
  if (key != Unmapped_Key)
  {
    keys[key] = name;
    threadableProtocol->addPioneerKey(
      key, addressData, commandData);
  }
}
*/


void PIRKeysetMetaData::addKaseikyoKey(
  const char *name,
  PIRKeyName key,
  unsigned int addressData,
  unsigned int commandData)
{
  if (key != Unmapped_Key)
  {
    keys[key] = name;
    threadableProtocol->addKaseikyoKey(key, addressData, commandData);
  }
}


void PIRKeysetMetaData::addDishKey(
  const char *name,
  PIRKeyName key,
  unsigned int firstCommand,
  unsigned int secondCommand)
{
  if (key != Unmapped_Key)
  {
    keys[key] = name;
    threadableProtocol->addDishKey(key, firstCommand, secondCommand);
  }
}


void PIRKeysetMetaData::setPreData(
  unsigned long data,
  unsigned int bits)
{
  threadableProtocol->setPreData(data, bits);
}


void PIRKeysetMetaData::setPostData(
  unsigned long data,
  unsigned int bits)
{
  threadableProtocol->setPostData(data, bits);
}


void PIRKeysetMetaData::setKeysetName(
  const char *n)
{
  keysetName = n;
}
