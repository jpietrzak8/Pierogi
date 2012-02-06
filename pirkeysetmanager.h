#ifndef PIRKEYSETMANAGER_H
#define PIRKEYSETMANAGER_H

#include "pirkeynames.h"
#include "pirmakenames.h"

#include <QString>
#include <QThread>

class QObject;
class PIRSelectKeysetForm;
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
  PIRKeysetManager(
    QObject *guiObject);

  ~PIRKeysetManager();

  void populateGuiWidget(
    PIRSelectKeysetForm *widget) const;

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

  void populateDeviceTypes(
    PIRKeysetWidgetItem *kwi,
    unsigned int keysetID) const;

private:
  // This needs to be improved:
  void populateKeyset(
    PIRKeysetMetaData *keyset);

  PIRKeysetCollection keysetsInfo;
  PIRKeysetMakeIndex makeIndex;

  // The counter will be used to generate unique ids for each keyset:
  unsigned int counter;

  QThread commandThread;
};

#endif // PIRKEYSETMANAGER_H
