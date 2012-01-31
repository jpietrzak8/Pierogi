#ifndef PIRKEYSETMANAGER_H
#define PIRKEYSETMANAGER_H

#include "pirkeysetmetadata.h"
//#include "protocol.h"
#include "pirkeynames.h"
//#include "selectionwindow.h"
#include "pirselectkeysetform.h"
#include "pirkeysetwidgetitem.h"

#include <QString> // needed to work with QSettings data...

//#include <QtCore/QCoreApplication>
#include <QThread>
//#include <QStringList>

#include <map>

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
    PIRSelectKeysetForm *widget);

  bool keysetExists(
    unsigned int keysetID);

  bool findKeysetID(
    QString make,
    QString name,
    unsigned int &id);

  PIRKeysetWidgetItem *makeKeysetItem(
    QString make,
    QString name);

  bool hasKey(
    unsigned int keysetID,
    PIRKeyName name);

  PIRMakeName getMake(
    unsigned int keysetID);

  QString getDisplayName(
    unsigned int keysetID);

  void populateDeviceTypes(
    PIRKeysetWidgetItem *kwi,
    unsigned int keysetID);

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
