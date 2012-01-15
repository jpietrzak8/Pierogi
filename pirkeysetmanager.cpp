#include "pirkeysetmanager.h"
#include "pirkeysetmetadata.h"
#include "keysets/apple.h"
#include "keysets/ei.h"
#include "keysets/goldstar.h"
#include "keysets/hauppauge.h"
#include "keysets/jvc.h"
#include "keysets/lg.h"
#include "keysets/mitsubishi.h"
#include "keysets/nokia.h"
#include "keysets/panasonic.h"
#include "keysets/rca.h"
#include "keysets/samsung.h"
#include "keysets/sanyo.h"
#include "keysets/sharp.h"
#include "keysets/sony.h"
#include "keysets/toshiba.h"
#include "keysets/westinghouse.h"
#include "keysets/zenith.h"
//#include "protocol.h"
#include "pirmakenames.h"

#include "pirexception.h"

#include <QObject>
//#include <QMetaType>

// I'll be handling the threading of the keyset commands in this object:
#include <QMutex>

// This file defines some global stuff!  First, threading globals:

// The stopRepeatingFlag boolean is the method used to tell running commands
// in the worker thread to stop:
bool stopRepeatingFlag;
QMutex stopRepeatingMutex;

// Global helper objects:
PIRMakeMgr makeManager;
PIRDeviceTypeMgr deviceManager;

// Now, on to the actual method definitions:

PIRKeysetManager::PIRKeysetManager(
  QObject *guiObject)
  : counter(0)
{
  // Create the keysets.  Ugly!  This needs to be worked on!
  populateKeyset(new AppleWhiteRemote(guiObject, counter++));

  populateKeyset(new EiKeyset(guiObject, counter++));

  populateKeyset(new GoldStarTV1(guiObject, counter++));
  populateKeyset(new GoldStarTV2(guiObject, counter++));
  populateKeyset(new GoldStarVCR1(guiObject, counter++));
  populateKeyset(new GoldStarVCR1a(guiObject, counter++));
  populateKeyset(new GoldStarVCR1b(guiObject, counter++));
  populateKeyset(new GoldStarVCR1c(guiObject, counter++));
  populateKeyset(new GoldStarVCR1d(guiObject, counter++));
  populateKeyset(new GoldStarCD1(guiObject, counter++));

  populateKeyset(new HauppaugeGeneric(guiObject, counter++));
  populateKeyset(new HauppaugeTV1(guiObject, counter++));

  populateKeyset(new JVCSat1(guiObject, counter++));
  populateKeyset(new JVCSat2(guiObject, counter++));
  populateKeyset(new JVCVCR1(guiObject, counter++));
  populateKeyset(new JVCVCR1a(guiObject, counter++));
  populateKeyset(new JVCVCR1b(guiObject, counter++));
  populateKeyset(new JVCVCR1c(guiObject, counter++));
  populateKeyset(new JVCVCR2(guiObject, counter++));
  populateKeyset(new JVCVCR2a(guiObject, counter++));
  populateKeyset(new JVCVCR2b(guiObject, counter++));
  populateKeyset(new JVCVCR2c(guiObject, counter++));
  populateKeyset(new JVCTV1(guiObject, counter++));
  populateKeyset(new JVCTV1a(guiObject, counter++));
  populateKeyset(new JVCTV1b(guiObject, counter++));
  populateKeyset(new JVCTV1c(guiObject, counter++));
  populateKeyset(new JVCTV1d(guiObject, counter++));
  populateKeyset(new JVCTV2(guiObject, counter++));
  populateKeyset(new JVCTV2a(guiObject, counter++));
  populateKeyset(new JVCTV2b(guiObject, counter++));
  populateKeyset(new JVCTV2c(guiObject, counter++));
  populateKeyset(new JVCTV2d(guiObject, counter++));
  populateKeyset(new JVCDAT1(guiObject, counter++));
  populateKeyset(new JVCCarDeck1(guiObject, counter++));
  populateKeyset(new JVCPortableAudio1(guiObject, counter++));
  populateKeyset(new JVCPortableAudio1a(guiObject, counter++));
  populateKeyset(new JVCPortableAudio1b(guiObject, counter++));
  populateKeyset(new JVCPortableAudio2(guiObject, counter++));
  populateKeyset(new JVCDVD1(guiObject, counter++));

  populateKeyset(new LGTV1(guiObject, counter++));
  populateKeyset(new LGTV1a(guiObject, counter++));
  populateKeyset(new LGTV1b(guiObject, counter++));
  populateKeyset(new LGTV1c(guiObject, counter++));
  populateKeyset(new LGTV2(guiObject, counter++));
  populateKeyset(new LGTV2a(guiObject, counter++));
  populateKeyset(new LGTV2b(guiObject, counter++));
  populateKeyset(new LGDisc1(guiObject, counter++));
  populateKeyset(new LGDisc2(guiObject, counter++));
  populateKeyset(new LGDisc2a(guiObject, counter++));
  populateKeyset(new LGVCR1(guiObject, counter++));
  populateKeyset(new LGVCR1a(guiObject, counter++));
  populateKeyset(new LGVCR1b(guiObject, counter++));

  populateKeyset(new MitsubishiTV1(guiObject, counter++));
  populateKeyset(new MitsubishiTV1a(guiObject, counter++));
  populateKeyset(new MitsubishiVCR1(guiObject, counter++));
  populateKeyset(new MitsubishiVCR1a(guiObject, counter++));

  populateKeyset(new NokiaGenericVCR(guiObject, counter++));

  populateKeyset(new PanasonicAmp(guiObject, counter++));
  populateKeyset(new PanasonicCarAudio(guiObject, counter++));
  populateKeyset(new PanasonicSat1(guiObject, counter++));
  populateKeyset(new PanasonicSat1a(guiObject, counter++));
  populateKeyset(new PanasonicTV1(guiObject, counter++));
  populateKeyset(new PanasonicTV1a(guiObject, counter++));
  populateKeyset(new PanasonicTV1b(guiObject, counter++));
  populateKeyset(new PanasonicVCR1(guiObject, counter++));
  populateKeyset(new PanasonicVCR1a(guiObject, counter++));
  populateKeyset(new PanasonicVCR1b(guiObject, counter++));
  populateKeyset(new PanasonicVCR1c(guiObject, counter++));
  populateKeyset(new PanasonicDVD1(guiObject, counter++));
  populateKeyset(new PanasonicDVD1a(guiObject, counter++));
  populateKeyset(new PanasonicAudio(guiObject, counter++));

  populateKeyset(new RCATV1(guiObject, counter++));
  populateKeyset(new RCATV1a(guiObject, counter++));
  populateKeyset(new RCATV2(guiObject, counter++));
  populateKeyset(new RCAAux1(guiObject, counter++));
  populateKeyset(new RCAAux2(guiObject, counter++));
  populateKeyset(new RCAAux2a(guiObject, counter++));
  populateKeyset(new RCAVCR1(guiObject, counter++));
  populateKeyset(new RCAVCR2(guiObject, counter++));
  populateKeyset(new RCADVD1(guiObject, counter++));
  populateKeyset(new RCADVD1a(guiObject, counter++));
  populateKeyset(new RCASat1(guiObject, counter++));
  populateKeyset(new RCASat2(guiObject, counter++));

  populateKeyset(new SamsungTV1(guiObject, counter++));
  populateKeyset(new SamsungTV1a(guiObject, counter++));
  populateKeyset(new SamsungTV1b(guiObject, counter++));
  populateKeyset(new SamsungTV1c(guiObject, counter++));
  populateKeyset(new SamsungTV1d(guiObject, counter++));
  populateKeyset(new SamsungTV1e(guiObject, counter++));
  populateKeyset(new SamsungTV1f(guiObject, counter++));
  populateKeyset(new SamsungTV2(guiObject, counter++));
  populateKeyset(new SamsungTV2a(guiObject, counter++));
  populateKeyset(new SamsungVCR1(guiObject, counter++));
  populateKeyset(new SamsungVCR1a(guiObject, counter++));
  populateKeyset(new SamsungVCR1b(guiObject, counter++));
  populateKeyset(new SamsungVCR1c(guiObject, counter++));
  populateKeyset(new SamsungVCR1d(guiObject, counter++));
  populateKeyset(new SamsungVCR1e(guiObject, counter++));
  populateKeyset(new SamsungDVD1(guiObject, counter++));
  populateKeyset(new SamsungDVD1a(guiObject, counter++));
  populateKeyset(new SamsungDVD1b(guiObject, counter++));
  populateKeyset(new SamsungDVD2(guiObject, counter++));
  populateKeyset(new SamsungAC1(guiObject, counter++));

  populateKeyset(new SanyoTV1(guiObject, counter++));
  populateKeyset(new SanyoTV2(guiObject, counter++));
  populateKeyset(new SanyoVCR1(guiObject, counter++));

  populateKeyset(new SharpTV1(guiObject, counter++));
  populateKeyset(new SharpTV1a(guiObject, counter++));
  populateKeyset(new SharpTV1b(guiObject, counter++));
  populateKeyset(new SharpTV1c(guiObject, counter++));
  populateKeyset(new SharpTV1d(guiObject, counter++));
  populateKeyset(new SharpTV1e(guiObject, counter++));
  populateKeyset(new SharpVCR1(guiObject, counter++));
  populateKeyset(new SharpReceiver1(guiObject, counter++));

  populateKeyset(new SonyTV1(guiObject, counter++));
  populateKeyset(new SonyTV1a(guiObject, counter++));
  populateKeyset(new SonyTV1b(guiObject, counter++));
  populateKeyset(new SonyTV1d(guiObject, counter++));
  populateKeyset(new SonyAmp1(guiObject, counter++));
  populateKeyset(new SonyAmp2(guiObject, counter++));
  populateKeyset(new SonyCD1(guiObject, counter++));
  populateKeyset(new SonyCD1a(guiObject, counter++));
  populateKeyset(new SonyCD2(guiObject, counter++));
  populateKeyset(new SonyCD3(guiObject, counter++));
  populateKeyset(new SonyDAT1(guiObject, counter++));
  populateKeyset(new SonyDVD1(guiObject, counter++));
  populateKeyset(new SonyDVD1a(guiObject, counter++));
  populateKeyset(new SonyDVD1b(guiObject, counter++));
  populateKeyset(new SonyDVD1c(guiObject, counter++));
  populateKeyset(new SonyVCR1(guiObject, counter++));
  populateKeyset(new SonyVCR1a(guiObject, counter++));
  populateKeyset(new SonyReceiver1(guiObject, counter++));

  populateKeyset(new ToshibaTV1(guiObject, counter++));
  populateKeyset(new ToshibaTV1a(guiObject, counter++));
  populateKeyset(new ToshibaTV1b(guiObject, counter++));
  populateKeyset(new ToshibaTV1c(guiObject, counter++));
  populateKeyset(new ToshibaTV1d(guiObject, counter++));
  populateKeyset(new ToshibaTV1e(guiObject, counter++));
  populateKeyset(new ToshibaVCR1(guiObject, counter++));
  populateKeyset(new ToshibaVCR1a(guiObject, counter++));
  populateKeyset(new ToshibaDisc1(guiObject, counter++));
  populateKeyset(new ToshibaDisc1a(guiObject, counter++));
  populateKeyset(new ToshibaDisc1b(guiObject, counter++));
  populateKeyset(new ToshibaDisc1c(guiObject, counter++));
  populateKeyset(new ToshibaDisc1d(guiObject, counter++));

  populateKeyset(new WestinghouseTV1(guiObject, counter++));
  populateKeyset(new WestinghouseTV2(guiObject, counter++));

  populateKeyset(new ZenithC32V37(guiObject, counter++));

  // Start the thread running:
  commandThread.start();
}


PIRKeysetManager::~PIRKeysetManager()
{
  // Tell the keysets to stop doing any work:
  stopRepeating();

  // Tell the thread that we want it to stop:
  commandThread.exit();

  // Wait for the thread to stop:
  commandThread.wait();

  // Delete all the keysets:
  PIRKeysetCollection::iterator i = keysetsInfo.begin();
  while (i != keysetsInfo.end())
  {
    if ((*i).second) delete (*i).second;
    ++i;
  }
}


void PIRKeysetManager::stopRepeating()
{
  QMutexLocker locker(&stopRepeatingMutex);
  stopRepeatingFlag = true;
}


bool PIRKeysetManager::hasKey(
  int keysetID,
  PIRKeyName name)
{
  PIRKeysetMetaData *meta = keysetsInfo[keysetID];

  if (!meta) return false;

  return meta->hasKey(name);
}


PIRMakeName PIRKeysetManager::getMake(
  int keysetID)
{
  PIRKeysetMetaData *meta = keysetsInfo[keysetID];

  if (!meta) return Any_Make; // Work on this!

  return meta->getMake();
}


QString PIRKeysetManager::getDisplayName(
  int keysetID)
{
  PIRKeysetMetaData *meta = keysetsInfo[keysetID];

  if (!meta) return QString("Database Error");

  return QString(meta->getKeysetName());
}


void PIRKeysetManager::populateKeyset(
  PIRKeysetMetaData *keyset)
{
  keysetsInfo[keyset->getID()] = keyset;

  keyset->moveProtocolToThread(commandThread);
}


void PIRKeysetManager::populateGuiWidget(
  PIRSelectKeysetForm *skf)
{
  PIRMakeName make;
  PIRKeysetWidgetItem *kwi;

  PIRKeysetCollection::const_iterator i = keysetsInfo.begin();

  while (i != keysetsInfo.end())
  {
    make = i->second->getMake();
    QString tempString = makeManager.getMakeString(make);
    tempString.append(" ");
    tempString.append(i->second->getKeysetName());
    kwi = new PIRKeysetWidgetItem(tempString, i->first, make);
    i->second->populateDeviceTypes(kwi);
    skf->addWidgetItem(kwi);
    ++i;
  }
}


void PIRKeysetManager::populateDeviceTypes(
  PIRKeysetWidgetItem *kwi,
  int keysetID)
{
  // Pass the buck:  (Need to check for bad keysetID here?)
  keysetsInfo[keysetID]->populateDeviceTypes(kwi);
}
