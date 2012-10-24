#ifndef PIRKEYSETMANAGER_H
#define PIRKEYSETMANAGER_H

#include "pirkeynames.h"
#include "pirmakenames.h"

#include <QString>
#include <QThread>

class QObject;
class PIRSelectKeysetForm;
class PIRSelectDeviceForm;
class PIRFavoritesDialog;
class PIRKeysetWidgetItem;

#include <map>
class PIRKeysetMetaData;

typedef std::map<unsigned int, PIRKeysetMetaData *> PIRKeysetCollection;

// Maps used to locate metadata using QSettings values:
typedef std::map<QString, unsigned int> PIRKeysetNameIndex;
typedef std::map<QString, PIRKeysetNameIndex> PIRKeysetMakeIndex;

class PIRKeysetManager
{
public:
  PIRKeysetManager();

  ~PIRKeysetManager();

  void populateListWidgets(
    PIRSelectKeysetForm *skf,
    PIRFavoritesDialog *fd) const;

  bool keysetExists(
    unsigned int keysetID) const;

  bool findKeysetID(
    QString make,
    QString name,
    unsigned int &id) const;

  PIRKeysetWidgetItem *makeKeysetItem(
    QString make,
    QString name) const;

  bool hasKey(
    unsigned int keysetID,
    PIRKeyName name) const;

  PIRMakeName getMake(
    unsigned int keysetID) const;

  QString getDisplayName(
    unsigned int keysetID) const;

/*
  void populateDeviceTypes(
    PIRKeysetWidgetItem *kwi,
    unsigned int keysetID) const;
*/

  void populateKeyset(
    QObject *guiObject,
    unsigned int keysetID);

  bool clearKeyset(
    unsigned int keysetID);

  void populateFavorites(
    PIRFavoritesDialog *favoritesDialog,
    PIRSelectKeysetForm *keysetForm);

  unsigned int getCarrierFrequency(
    unsigned int keysetID);

  void setCarrierFrequency(
    unsigned int carrierFrequency,
    unsigned int keysetID);

  unsigned int getDutyCycle(
    unsigned int keysetID);

  void setDutyCycle(
    unsigned int dutyCycle,
    unsigned int keysetID);

private:
  void setupKeyset(
    PIRKeysetMetaData *keyset);

  PIRKeysetCollection keysetsInfo;
  PIRKeysetMakeIndex makeIndex;

  // The counter will be used to generate unique ids for each keyset:
  unsigned int counter;

  QThread commandThread;
};

#endif // PIRKEYSETMANAGER_H
