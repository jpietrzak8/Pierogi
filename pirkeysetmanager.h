#ifndef PIRKEYSETMANAGER_H
#define PIRKEYSETMANAGER_H

#include "pirkeysetmetadata.h"
//#include "protocol.h"
#include "pirkeynames.h"
//#include "selectionwindow.h"
#include "pirselectkeysetform.h"
#include "pirkeysetwidgetitem.h"

//#include <QtCore/QCoreApplication>
#include <QThread>
//#include <QStringList>

#include <map>

typedef std::map<int, PIRKeysetMetaData *> PIRKeysetCollection;

class PIRKeysetManager
{
public:
  PIRKeysetManager(
    QObject *guiObject);

  ~PIRKeysetManager();

  void populateGuiWidget(
    PIRSelectKeysetForm *widget);

  bool hasKey(
    int keysetID,
    PIRKeyName name);

  PIRMakeName getMake(
    int keysetID);

  QString getDisplayName(
    int keysetID);

  void populateDeviceTypes(
    PIRKeysetWidgetItem *kwi,
    int keysetID);

private:
  // This needs to be improved:
  void populateKeyset(
    PIRKeysetMetaData *keyset);

  PIRKeysetCollection keysetsInfo;

  // The counter will be used to generate unique ids for each keyset:
  unsigned int counter;

  QThread commandThread;
};

#endif // PIRKEYSETMANAGER_H
