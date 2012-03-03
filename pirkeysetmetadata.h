#ifndef PIRKEYSETMETADATA_H
#define PIRKEYSETMETADATA_H

#include "pirkeynames.h"
#include "pirmakenames.h"
//#include "pirdevicetypenames.h"

#include "pirdeviceinfo.h"

#include <map>
//#include <list>

class QThread;
class QObject;

class PIRSelectDeviceForm;
class PIRProtocol;

typedef std::map<PIRKeyName, const char *> KeyCollection;


class PIRKeysetMetaData
{
public:
  PIRKeysetMetaData(
    const char *keysetName,
    PIRMakeName make,
    unsigned int index);

  bool hasKey(
    PIRKeyName name) const;

  unsigned int getID() const;

  PIRMakeName getMake() const;

  const char *getKeysetName() const;

  virtual void populateProtocol(
    QObject *guiObject) = 0;

  void moveToThread(
    QThread *thread);

  static void populateDevices(
    PIRSelectDeviceForm *sdf);

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
    unsigned int size);

  // Special helper methods for SIRC keys:
  void addSIRC12Key(
    const char *name,
    PIRKeyName key,
    unsigned int addressData,
    unsigned int commandData);

  void addSIRC15Key(
    const char *name,
    PIRKeyName key,
    unsigned int addressData,
    unsigned int commandData);

  void addSIRC20Key(
    const char *name,
    PIRKeyName key,
    unsigned int secondaryAddressData,
    unsigned int primaryAddressData,
    unsigned int commandData);

  // Helper method for Sharp keys:
  void addSharpKey(
    const char *name,
    PIRKeyName key,
    unsigned int addressData,
    unsigned int commandData);

  void addNECKey(
    const char *name,
    PIRKeyName key,
    unsigned int addressData,
    unsigned int commandData);

  void addPioneerKey(
    const char *name,
    PIRKeyName key,
    unsigned int addressOne,
    unsigned int commandOne,
    unsigned int addressTwo,
    unsigned int commandTwo);

/*
  void addRCAKey(
    const char *name,
    PIRKeyName key,
    unsigned int addressData,
    unsigned int commandData);
*/

  void addKaseikyoKey(
    const char *name,
    PIRKeyName key,
    unsigned int addressData,
    unsigned int commandData);

  void addDishKey(
    const char *name,
    PIRKeyName key,
    unsigned int firstCommand,
    unsigned int secondCommand);

  void setPreData(
    unsigned long data,
    unsigned int bits);

  void setPostData(
    unsigned long data,
    unsigned int bits);

  void setKeysetName(
    const char *name);

  KeyCollection keys;

  PIRProtocol *threadableProtocol;
  unsigned int index;

private:
  const char *keysetName;
  PIRMakeName make;
  static PIRDeviceCollection controlledDevices;
//  PIRDeviceTypeCollection deviceTypes;
};


#endif // PIRKEYSETMETADATA_H
