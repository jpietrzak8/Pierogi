#include "pirkeysetmanager.h"
#include "pirkeysetmetadata.h"
#include "keysets/apple.h"
#include "keysets/denon.h"
#include "keysets/ei.h"
#include "keysets/goldstar.h"
#include "keysets/hauppauge.h"
#include "keysets/hitachi.h"
#include "keysets/jvc.h"
#include "keysets/lg.h"
#include "keysets/magnavox.h"
#include "keysets/mitsubishi.h"
#include "keysets/nokia.h"
#include "keysets/panasonic.h"
#include "keysets/philips.h"
#include "keysets/pinnacle.h"
#include "keysets/raite.h"
#include "keysets/rca.h"
#include "keysets/sagem.h"
#include "keysets/samsung.h"
#include "keysets/sanyo.h"
#include "keysets/sharp.h"
#include "keysets/sony.h"
#include "keysets/tivo.h"
#include "keysets/toshiba.h"
#include "keysets/westinghouse.h"
#include "keysets/yamaha.h"
#include "keysets/zenith.h"
#include "pirmakenames.h"

#include "pirexception.h"

#include <QObject>

// I'll be handling the threading of the keyset commands in this object:
#include <QMutex>

// Global communications mechanism:
extern bool stopRepeatingFlag;
extern QMutex stopRepeatingMutex;

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

  populateKeyset(new DenonDVD1(guiObject, counter++));
  populateKeyset(new DenonDVD2(guiObject, counter++));
  populateKeyset(new DenonDVD3(guiObject, counter++));
  populateKeyset(new DenonReceiver1(guiObject, counter++));
  populateKeyset(new DenonReceiver1a(guiObject, counter++));
  populateKeyset(new DenonReceiver1b(guiObject, counter++));
  populateKeyset(new DenonReceiver1c(guiObject, counter++));
  populateKeyset(new DenonReceiver2(guiObject, counter++));
  populateKeyset(new DenonReceiver2a(guiObject, counter++));
  populateKeyset(new DenonReceiver3(guiObject, counter++));
  populateKeyset(new DenonReceiver3a(guiObject, counter++));
  populateKeyset(new DenonReceiver4(guiObject, counter++));
  populateKeyset(new DenonReceiver5(guiObject, counter++));
  populateKeyset(new DenonAudio1(guiObject, counter++));
  populateKeyset(new DenonAudio1a(guiObject, counter++));
  populateKeyset(new DenonAudio1b(guiObject, counter++));
  populateKeyset(new DenonAudio1c(guiObject, counter++));
  populateKeyset(new DenonAudio1d(guiObject, counter++));
  populateKeyset(new DenonAudio2(guiObject, counter++));
  populateKeyset(new DenonAudio3(guiObject, counter++));
  populateKeyset(new DenonAudio4(guiObject, counter++));
  populateKeyset(new DenonAudio5(guiObject, counter++));

  populateKeyset(new EiKeyset(guiObject, counter++));

  populateKeyset(new GoldStarTV1(guiObject, counter++));
  populateKeyset(new GoldStarTV2(guiObject, counter++));
  populateKeyset(new GoldStarVCR1(guiObject, counter++));
  populateKeyset(new GoldStarVCR1a(guiObject, counter++));
  populateKeyset(new GoldStarVCR1b(guiObject, counter++));
  populateKeyset(new GoldStarVCR1c(guiObject, counter++));
  populateKeyset(new GoldStarVCR1d(guiObject, counter++));
  populateKeyset(new GoldStarCD1(guiObject, counter++));

  populateKeyset(new HauppaugePCTV1(guiObject, counter++));
  populateKeyset(new HauppaugePCTV1a(guiObject, counter++));
  populateKeyset(new HauppaugePCTV1b(guiObject, counter++));
  populateKeyset(new HauppaugePCTV1c(guiObject, counter++));
  populateKeyset(new HauppaugePCTV2(guiObject, counter++));

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

  populateKeyset(new MagnavoxDVD1(guiObject, counter++));
  populateKeyset(new MagnavoxVCR1(guiObject, counter++));
  populateKeyset(new MagnavoxConverterBox1(guiObject, counter++));
  populateKeyset(new MagnavoxTV1(guiObject, counter++));

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
  populateKeyset(new PanasonicAudio1(guiObject, counter++));
  populateKeyset(new PanasonicAudio1a(guiObject, counter++));

  populateKeyset(new PhilipsTV1(guiObject, counter++));
  populateKeyset(new PhilipsTV1a(guiObject, counter++));
  populateKeyset(new PhilipsTV1b(guiObject, counter++));
  populateKeyset(new PhilipsTV1c(guiObject, counter++));
  populateKeyset(new PhilipsTV1d(guiObject, counter++));
  populateKeyset(new PhilipsTV1e(guiObject, counter++));
  populateKeyset(new PhilipsTV1f(guiObject, counter++));
  populateKeyset(new PhilipsTV2(guiObject, counter++));
  populateKeyset(new PhilipsTV2a(guiObject, counter++));
  populateKeyset(new PhilipsTV2b(guiObject, counter++));
  populateKeyset(new PhilipsTV3(guiObject, counter++));
  populateKeyset(new PhilipsDVD1(guiObject, counter++));
  populateKeyset(new PhilipsDVD1a(guiObject, counter++));
  populateKeyset(new PhilipsDVD1b(guiObject, counter++));
  populateKeyset(new PhilipsDVD1c(guiObject, counter++));
  populateKeyset(new PhilipsDVD1d(guiObject, counter++));
  populateKeyset(new PhilipsDVD2(guiObject, counter++));
  populateKeyset(new PhilipsDVD3(guiObject, counter++));
  populateKeyset(new PhilipsDVD4(guiObject, counter++));
  populateKeyset(new PhilipsVCR1(guiObject, counter++));
  populateKeyset(new PhilipsVCR1a(guiObject, counter++));
  populateKeyset(new PhilipsVCR1b(guiObject, counter++));
  populateKeyset(new PhilipsVCR1c(guiObject, counter++));
  populateKeyset(new PhilipsSat1(guiObject, counter++));
  populateKeyset(new PhilipsSat2(guiObject, counter++));
  populateKeyset(new PhilipsSat2a(guiObject, counter++));
  populateKeyset(new PhilipsSat3(guiObject, counter++));
  populateKeyset(new PhilipsAudio1(guiObject, counter++));
  populateKeyset(new PhilipsAudio1a(guiObject, counter++));
  populateKeyset(new PhilipsAudio1b(guiObject, counter++));
  populateKeyset(new PhilipsAudio2(guiObject, counter++));
  populateKeyset(new PhilipsAudio3(guiObject, counter++));
  populateKeyset(new PhilipsAudio4(guiObject, counter++));

  populateKeyset(new PinnaclePCTV1(guiObject, counter++));
  populateKeyset(new PinnaclePCTV2(guiObject, counter++));
  populateKeyset(new PinnaclePCTV3(guiObject, counter++));

  populateKeyset(new RaiteDVD1(guiObject, counter++));

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

  populateKeyset(new SagemTVBox1(guiObject, counter++));
  populateKeyset(new SagemTVBox1a(guiObject, counter++));

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

  populateKeyset(new SanyoVCR1(guiObject, counter++));
  populateKeyset(new SanyoDVD1(guiObject, counter++));
  populateKeyset(new SanyoTV1(guiObject, counter++));
  populateKeyset(new SanyoTV1a(guiObject, counter++));
  populateKeyset(new SanyoTV1b(guiObject, counter++));
  populateKeyset(new SanyoTV1c(guiObject, counter++));
  populateKeyset(new SanyoTV1d(guiObject, counter++));
  populateKeyset(new SanyoProjector(guiObject, counter++));

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

  populateKeyset(new Tivo1(guiObject, counter++));
  populateKeyset(new Tivo1a(guiObject, counter++));
  populateKeyset(new Tivo1b(guiObject, counter++));
  populateKeyset(new Tivo1c(guiObject, counter++));
  populateKeyset(new Tivo1d(guiObject, counter++));

  populateKeyset(new ToshibaTV1(guiObject, counter++));
  populateKeyset(new ToshibaTV1a(guiObject, counter++));
  populateKeyset(new ToshibaTV1b(guiObject, counter++));
  populateKeyset(new ToshibaTV1c(guiObject, counter++));
  populateKeyset(new ToshibaTV1d(guiObject, counter++));
  populateKeyset(new ToshibaTV1e(guiObject, counter++));
  populateKeyset(new ToshibaTV1f(guiObject, counter++));
  populateKeyset(new ToshibaVCR1(guiObject, counter++));
  populateKeyset(new ToshibaVCR1a(guiObject, counter++));
  populateKeyset(new ToshibaDisc1(guiObject, counter++));
  populateKeyset(new ToshibaDisc1a(guiObject, counter++));
  populateKeyset(new ToshibaDisc1b(guiObject, counter++));
  populateKeyset(new ToshibaDisc1c(guiObject, counter++));
  populateKeyset(new ToshibaDisc1d(guiObject, counter++));

  populateKeyset(new WestinghouseTV1(guiObject, counter++));
  populateKeyset(new WestinghouseTV2(guiObject, counter++));

  populateKeyset(new YamahaDVD1(guiObject, counter++));
  populateKeyset(new YamahaDVD1a(guiObject, counter++));
  populateKeyset(new YamahaAudio1(guiObject, counter++));
  populateKeyset(new YamahaAudio1a(guiObject, counter++));
  populateKeyset(new YamahaAudio2(guiObject, counter++));
  populateKeyset(new YamahaAudio2a(guiObject, counter++));
  populateKeyset(new YamahaAudio2b(guiObject, counter++));
  populateKeyset(new YamahaAudio2c(guiObject, counter++));
  populateKeyset(new YamahaAudio2d(guiObject, counter++));
  populateKeyset(new YamahaAudio3(guiObject, counter++));
  populateKeyset(new YamahaAudio4(guiObject, counter++));
  populateKeyset(new YamahaAudio5(guiObject, counter++));
  populateKeyset(new YamahaAudio6(guiObject, counter++));
  populateKeyset(new YamahaAudio7(guiObject, counter++));
  populateKeyset(new YamahaTV1(guiObject, counter++));
  populateKeyset(new YamahaKaraoke1(guiObject, counter++));

  populateKeyset(new ZenithC32V37(guiObject, counter++));

  // Start the thread running:
  commandThread.start();
}


PIRKeysetManager::~PIRKeysetManager()
{
  // Tell the keysets to stop doing any work:
  {
    QMutexLocker locker(&stopRepeatingMutex);
    stopRepeatingFlag = true;
  }

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


bool PIRKeysetManager::keysetExists(
  unsigned int keysetID)
{
  PIRKeysetCollection::const_iterator i = keysetsInfo.find(keysetID);

  return (i != keysetsInfo.end());
}


bool PIRKeysetManager::hasKey(
  unsigned int keysetID,
  PIRKeyName name)
{
  PIRKeysetMetaData *meta = keysetsInfo[keysetID];

  if (!meta) return false;

  return meta->hasKey(name);
}


PIRMakeName PIRKeysetManager::getMake(
  unsigned int keysetID)
{
  PIRKeysetMetaData *meta = keysetsInfo[keysetID];

  if (!meta) return Any_Make; // Work on this!

  return meta->getMake();
}


QString PIRKeysetManager::getDisplayName(
  unsigned int keysetID)
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
  unsigned int keysetID)
{
  // Pass the buck:  (Need to check for bad keysetID here?)
  keysetsInfo[keysetID]->populateDeviceTypes(kwi);
}
