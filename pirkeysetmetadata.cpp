#include "pirkeysetmetadata.h"
#include "pirselectdeviceform.h"
#include "pirkeysetwidgetitem.h"
#include "protocols/pirprotocol.h"

#include <iostream>

// Global helper object:
extern PIRMakeMgr makeManager;

// Static member definition:
PIRDeviceCollection PIRKeysetMetaData::controlledDevices;

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


void PIRKeysetMetaData::populateDevices(
  PIRSelectDeviceForm *sdf)
{
  PIRKeysetWidgetItem *kwi;

  PIRDeviceCollection::const_iterator i = controlledDevices.begin();

  while (i != controlledDevices.end())
  {
    // Create a widget for the keyset:
    QString tempString = makeManager.getMakeString(i->first.make);
    tempString.append(" ");
    tempString.append(i->first.model);

    kwi = new PIRKeysetWidgetItem(
      tempString, i->first.model, i->second, i->first.make, i->first.type);

    sdf->addWidgetItem(kwi);

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
  controlledDevices.insert(
    PIRDCPair(
      DeviceInfo(make, model, type),
      index));
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


void PIRKeysetMetaData::addPanOldKey(
  const char *name,
  PIRKeyName key,
  unsigned int addressData,
  unsigned int commandData)
{
  if (key != Unmapped_Key)
  {
    keys[key] = name;
    threadableProtocol->addPanOldKey(key, addressData, commandData);
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


void PIRKeysetMetaData::addXMPKey(
  const char *name,
  PIRKeyName key,
  unsigned int firstCommand,
  unsigned int secondCommand)
{
  if (key != Unmapped_Key)
  {
    keys[key] = name;
    threadableProtocol->addXMPKey(key, firstCommand, secondCommand);
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


void PIRKeysetMetaData::clearProtocol()
{
  if (threadableProtocol)
  {
    delete threadableProtocol;
    threadableProtocol = 0;
  }
}
