#include "pirkeysetmanager.h"

#include "pirkeysetmetadata.h"
#include "pirselectkeysetform.h"
#include "pirkeysetwidgetitem.h"

#include "keysets/acer.h"
#include "keysets/admiral.h"
#include "keysets/aiwa.h"
#include "keysets/apple.h"
#include "keysets/bose.h"
#include "keysets/daewoo.h"
#include "keysets/denon.h"
#include "keysets/digitalstream.h"
#include "keysets/ei.h"
#include "keysets/elgato.h"
#include "keysets/emerson.h"
#include "keysets/goldstar.h"
#include "keysets/grundig.h"
#include "keysets/hauppauge.h"
#include "keysets/hitachi.h"
#include "keysets/jvc.h"
#include "keysets/lg.h"
#include "keysets/logitech.h"
#include "keysets/magnavox.h"
#include "keysets/mce.h"
#include "keysets/mitsubishi.h"
#include "keysets/nokia.h"
#include "keysets/panasonic.h"
#include "keysets/philco.h"
#include "keysets/philips.h"
#include "keysets/pinnacle.h"
#include "keysets/pioneer.h"
#include "keysets/raite.h"
#include "keysets/rca.h"
#include "keysets/roku.h"
#include "keysets/saba.h"
#include "keysets/sagem.h"
#include "keysets/samsung.h"
#include "keysets/sanyo.h"
#include "keysets/sharp.h"
#include "keysets/sky.h"
#include "keysets/sony.h"
#include "keysets/tivo.h"
#include "keysets/topfield.h"
#include "keysets/toshiba.h"
#include "keysets/wd.h"
#include "keysets/westinghouse.h"
#include "keysets/yamaha.h"
#include "keysets/zenith.h"

#include "pirexception.h"

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
  populateKeyset(new AcerTV1(guiObject, counter++));
  populateKeyset(new AcerPC1(guiObject, counter++));

  populateKeyset(new AdmiralTV1(guiObject, counter++));
  populateKeyset(new AdmiralTV2(guiObject, counter++));
  populateKeyset(new AdmiralVCR1(guiObject, counter++));

  populateKeyset(new AiwaVCR1(guiObject, counter++));
  populateKeyset(new AiwaVCR2(guiObject, counter++));
  populateKeyset(new AiwaVCR3(guiObject, counter++));
  populateKeyset(new AiwaAudio1(guiObject, counter++));
  populateKeyset(new AiwaAudio1a(guiObject, counter++));
  populateKeyset(new AiwaAudio2(guiObject, counter++));
  populateKeyset(new AiwaAudio2a(guiObject, counter++));
  populateKeyset(new AiwaAudio2b(guiObject, counter++));
  populateKeyset(new AiwaAudio2c(guiObject, counter++));
  populateKeyset(new AiwaAudio3(guiObject, counter++));
  populateKeyset(new AiwaAudio4(guiObject, counter++));
  populateKeyset(new AiwaAudio5(guiObject, counter++));
  populateKeyset(new AiwaAudio6(guiObject, counter++));
  populateKeyset(new AiwaCarStereo1(guiObject, counter++));
  populateKeyset(new AiwaDVD1(guiObject, counter++));

  populateKeyset(new AppleWhiteRemote(guiObject, counter++));

  populateKeyset(new BoseRadio1(guiObject, counter++));
  populateKeyset(new BoseRadio2(guiObject, counter++));
  populateKeyset(new BoseRadio3(guiObject, counter++));

  populateKeyset(new DaewooTV1(guiObject, counter++));
  populateKeyset(new DaewooTV2(guiObject, counter++));
  populateKeyset(new DaewooTV3(guiObject, counter++));
  populateKeyset(new DaewooTV4(guiObject, counter++));
  populateKeyset(new DaewooDVD1(guiObject, counter++));
  populateKeyset(new DaewooVCR1(guiObject, counter++));
  populateKeyset(new DaewooVCR2(guiObject, counter++));

  populateKeyset(new DenonDVD1(guiObject, counter++));
  populateKeyset(new DenonDVD2(guiObject, counter++));
  populateKeyset(new DenonDVD3(guiObject, counter++));
  populateKeyset(new DenonReceiver1(guiObject, counter++));
  populateKeyset(new DenonReceiver1a(guiObject, counter++));
  populateKeyset(new DenonReceiver1b(guiObject, counter++));
  populateKeyset(new DenonReceiver1c(guiObject, counter++));
  populateKeyset(new DenonReceiver1d(guiObject, counter++));
  populateKeyset(new DenonReceiver1e(guiObject, counter++));
  populateKeyset(new DenonReceiver1f(guiObject, counter++));
  populateKeyset(new DenonReceiver2(guiObject, counter++));
  populateKeyset(new DenonReceiver2a(guiObject, counter++));
  populateKeyset(new DenonReceiver3(guiObject, counter++));
  populateKeyset(new DenonAudio1(guiObject, counter++));
  populateKeyset(new DenonAudio1a(guiObject, counter++));
  populateKeyset(new DenonAudio1b(guiObject, counter++));
  populateKeyset(new DenonAudio1c(guiObject, counter++));
  populateKeyset(new DenonAudio1d(guiObject, counter++));
  populateKeyset(new DenonAudio2(guiObject, counter++));
  populateKeyset(new DenonAudio3(guiObject, counter++));
  populateKeyset(new DenonAudio4(guiObject, counter++));

  populateKeyset(new DigitalStreamReceiver(guiObject, counter++));

  populateKeyset(new EiTV1(guiObject, counter++));

  populateKeyset(new ElgatoEyeTV1(guiObject, counter++));

  populateKeyset(new EmersonTV1(guiObject, counter++));
  populateKeyset(new EmersonDVD1(guiObject, counter++));

  populateKeyset(new GoldStarTV1(guiObject, counter++));
  populateKeyset(new GoldStarTV2(guiObject, counter++));
  populateKeyset(new GoldStarVCR1(guiObject, counter++));
  populateKeyset(new GoldStarVCR1a(guiObject, counter++));
  populateKeyset(new GoldStarVCR1b(guiObject, counter++));
  populateKeyset(new GoldStarVCR1c(guiObject, counter++));
  populateKeyset(new GoldStarCD1(guiObject, counter++));

  populateKeyset(new GrundigSat1(guiObject, counter++));
  populateKeyset(new GrundigSat2(guiObject, counter++));
  populateKeyset(new GrundigAmp1(guiObject, counter++));
  populateKeyset(new GrundigAudio1(guiObject, counter++));
  populateKeyset(new GrundigAudio2(guiObject, counter++));
  populateKeyset(new GrundigVCR1(guiObject, counter++));
  populateKeyset(new GrundigVCR1a(guiObject, counter++));
  populateKeyset(new GrundigTV1(guiObject, counter++));
  populateKeyset(new GrundigTV2(guiObject, counter++));
  populateKeyset(new GrundigTV3(guiObject, counter++));
  populateKeyset(new GrundigDVD1(guiObject, counter++));

  populateKeyset(new HauppaugePCTV1(guiObject, counter++));
  populateKeyset(new HauppaugePCTV1a(guiObject, counter++));
  populateKeyset(new HauppaugePCTV1b(guiObject, counter++));
  populateKeyset(new HauppaugePCTV1c(guiObject, counter++));
  populateKeyset(new HauppaugePCTV2(guiObject, counter++));

  populateKeyset(new HitachiTV1(guiObject, counter++));
  populateKeyset(new HitachiTV1a(guiObject, counter++));
  populateKeyset(new HitachiTV1b(guiObject, counter++));
  populateKeyset(new HitachiTV1c(guiObject, counter++));
  populateKeyset(new HitachiTV2(guiObject, counter++));
  populateKeyset(new HitachiTV3(guiObject, counter++));
  populateKeyset(new HitachiProjector(guiObject, counter++));
  populateKeyset(new HitachiDVD1(guiObject, counter++));
  populateKeyset(new HitachiAudio1(guiObject, counter++));
  populateKeyset(new HitachiVCR1(guiObject, counter++));

  populateKeyset(new JVCSat1(guiObject, counter++));
  populateKeyset(new JVCSat2(guiObject, counter++));
  populateKeyset(new JVCVCR1(guiObject, counter++));
  populateKeyset(new JVCVCR1a(guiObject, counter++));
  populateKeyset(new JVCVCRBmode1(guiObject, counter++));
  populateKeyset(new JVCVCRBmode1a(guiObject, counter++));
  populateKeyset(new JVCTV1(guiObject, counter++));
  populateKeyset(new JVCTV1a(guiObject, counter++));
  populateKeyset(new JVCTV1b(guiObject, counter++));
  populateKeyset(new JVCTV1c(guiObject, counter++));
  populateKeyset(new JVCTV1d(guiObject, counter++));
  populateKeyset(new JVCDAT1(guiObject, counter++));
  populateKeyset(new JVCCarDeck1(guiObject, counter++));
  populateKeyset(new JVCAudio1(guiObject, counter++));
  populateKeyset(new JVCAudio1a(guiObject, counter++));
  populateKeyset(new JVCAudio1b(guiObject, counter++));
  populateKeyset(new JVCAudio2(guiObject, counter++));
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

  populateKeyset(new LogitechSpeakers(guiObject, counter++));

  populateKeyset(new MagnavoxDVD1(guiObject, counter++));
  populateKeyset(new MagnavoxVCR1(guiObject, counter++));
  populateKeyset(new MagnavoxConverterBox1(guiObject, counter++));
  populateKeyset(new MagnavoxTV1(guiObject, counter++));

  populateKeyset(new MCERemote1(guiObject, counter++));
  populateKeyset(new MCERemote1a(guiObject, counter++));
  populateKeyset(new MCERemote1b(guiObject, counter++));
  populateKeyset(new MCERemote1c(guiObject, counter++));
  populateKeyset(new MCERemote1d(guiObject, counter++));
  populateKeyset(new MCERemote1e(guiObject, counter++));
  populateKeyset(new MCERemote1f(guiObject, counter++));
  populateKeyset(new MCERemote1g(guiObject, counter++));

  populateKeyset(new MitsubishiTV1(guiObject, counter++));
  populateKeyset(new MitsubishiTV1a(guiObject, counter++));
  populateKeyset(new MitsubishiVCR1(guiObject, counter++));
  populateKeyset(new MitsubishiVCR1a(guiObject, counter++));

  populateKeyset(new NokiaGenericVCR(guiObject, counter++));

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

  populateKeyset(new PhilcoTV(guiObject, counter++));

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
  populateKeyset(new PhilipsDVD3a(guiObject, counter++));
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

  populateKeyset(new PioneerTV1(guiObject, counter++));
  populateKeyset(new PioneerTV2(guiObject, counter++));
  populateKeyset(new PioneerTV3(guiObject, counter++));
  populateKeyset(new PioneerAudio1(guiObject, counter++));
  populateKeyset(new PioneerAudio1a(guiObject, counter++));
  populateKeyset(new PioneerAudio2(guiObject, counter++));
  populateKeyset(new PioneerAudio3(guiObject, counter++));
  populateKeyset(new PioneerAudio4(guiObject, counter++));
  populateKeyset(new PioneerAudio5(guiObject, counter++));
  populateKeyset(new PioneerCD1(guiObject, counter++));
  populateKeyset(new PioneerLaserDisc1(guiObject, counter++));
  populateKeyset(new PioneerDVD1(guiObject, counter++));

  populateKeyset(new RaiteDVD1(guiObject, counter++));

  populateKeyset(new RCATV1(guiObject, counter++));
  populateKeyset(new RCATV1a(guiObject, counter++));
  populateKeyset(new RCATV1b(guiObject, counter++));
/*
  populateKeyset(new RCAAux1(guiObject, counter++));
  populateKeyset(new RCAAux2(guiObject, counter++));
  populateKeyset(new RCAAux2a(guiObject, counter++));
*/
  populateKeyset(new RCAVCR1(guiObject, counter++));
  populateKeyset(new RCAVCR1a(guiObject, counter++));
  populateKeyset(new RCADVD1(guiObject, counter++));
  populateKeyset(new RCADVD1a(guiObject, counter++));
  populateKeyset(new RCASat1(guiObject, counter++));
  populateKeyset(new RCASat2(guiObject, counter++));

  populateKeyset(new RokuBox1(guiObject, counter++));
  populateKeyset(new RokuBox2(guiObject, counter++));

  populateKeyset(new SabaTV1(guiObject, counter++));
  populateKeyset(new SabaTV2(guiObject, counter++));

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

  populateKeyset(new SkyReceiver1(guiObject, counter++));
  populateKeyset(new SkyReceiver1a(guiObject, counter++));

  populateKeyset(new SonyTV1(guiObject, counter++));
  populateKeyset(new SonyTV1a(guiObject, counter++));
  populateKeyset(new SonyTV1b(guiObject, counter++));
  populateKeyset(new SonyTV1c(guiObject, counter++));
  populateKeyset(new SonyAmp1(guiObject, counter++));
  populateKeyset(new SonyAmp2(guiObject, counter++));
  populateKeyset(new SonyAudio1(guiObject, counter++));
  populateKeyset(new SonyAudio1a(guiObject, counter++));
  populateKeyset(new SonyDAT1(guiObject, counter++));
  populateKeyset(new SonyDVD1(guiObject, counter++));
  populateKeyset(new SonyDVD1a(guiObject, counter++));
  populateKeyset(new SonyDVD1b(guiObject, counter++));
  populateKeyset(new SonyDVD1c(guiObject, counter++));
  populateKeyset(new SonyVCR1(guiObject, counter++));
  populateKeyset(new SonyVCR1a(guiObject, counter++));
  populateKeyset(new SonyVCR1b(guiObject, counter++));
  populateKeyset(new SonyReceiver1(guiObject, counter++));

  populateKeyset(new Tivo1(guiObject, counter++));
  populateKeyset(new Tivo1a(guiObject, counter++));
  populateKeyset(new Tivo1b(guiObject, counter++));
  populateKeyset(new Tivo1c(guiObject, counter++));
  populateKeyset(new Tivo1d(guiObject, counter++));

  populateKeyset(new TopfieldPVR1(guiObject, counter++));
  populateKeyset(new TopfieldSat1(guiObject, counter++));

  populateKeyset(new ToshibaTV1(guiObject, counter++));
  populateKeyset(new ToshibaTV1a(guiObject, counter++));
  populateKeyset(new ToshibaTV1b(guiObject, counter++));
  populateKeyset(new ToshibaTV1c(guiObject, counter++));
  populateKeyset(new ToshibaTV1d(guiObject, counter++));
  populateKeyset(new ToshibaTV1e(guiObject, counter++));
  populateKeyset(new ToshibaTV1f(guiObject, counter++));
  populateKeyset(new ToshibaTV1g(guiObject, counter++));
  populateKeyset(new ToshibaTV1h(guiObject, counter++));
  populateKeyset(new ToshibaVCR1(guiObject, counter++));
  populateKeyset(new ToshibaVCR1a(guiObject, counter++));
  populateKeyset(new ToshibaDisc1(guiObject, counter++));
  populateKeyset(new ToshibaDisc1a(guiObject, counter++));
  populateKeyset(new ToshibaDisc1b(guiObject, counter++));
  populateKeyset(new ToshibaDisc1c(guiObject, counter++));
  populateKeyset(new ToshibaDisc1d(guiObject, counter++));

  populateKeyset(new WDMediaPlayer1(guiObject, counter++));
  populateKeyset(new WDMediaPlayer1a(guiObject, counter++));

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
  unsigned int keysetID) const
{
  PIRKeysetCollection::const_iterator i = keysetsInfo.find(keysetID);

  return (i != keysetsInfo.end());
}


bool PIRKeysetManager::findKeysetID(
  QString make,
  QString name,
  unsigned int &id) const
{
  // Only modify the id if we actually find a match!

  PIRKeysetMakeIndex::const_iterator i = makeIndex.find(make);
  if (i == makeIndex.end())
  {
    return false;
  }

  PIRKeysetNameIndex::const_iterator ii = (*i).second.find(name);
  if (ii == (*i).second.end())
  {
    return false;
  }

  //  Ok, we've found it, pull out the id:
  id = (*ii).second;
  return true;
}


PIRKeysetWidgetItem *PIRKeysetManager::makeKeysetItem(
  QString make,
  QString name) const
{
  unsigned int id;

  if (!findKeysetID(make, name, id))
  {
    return NULL;
  }

  QString fullname = make;
  fullname.append(" ");
  fullname.append(name);

  return new PIRKeysetWidgetItem(fullname, id, getMake(id));
}


bool PIRKeysetManager::hasKey(
  unsigned int keysetID,
  PIRKeyName name) const
{
  PIRKeysetCollection::const_iterator i = keysetsInfo.find(keysetID);

  if ((i == keysetsInfo.end()) || !i->second) return false;

  return i->second->hasKey(name);
}


PIRMakeName PIRKeysetManager::getMake(
  unsigned int keysetID) const
{
  PIRKeysetCollection::const_iterator i = keysetsInfo.find(keysetID);

  if ((i == keysetsInfo.end()) || !i->second) return Any_Make;

  return i->second->getMake();
}


QString PIRKeysetManager::getDisplayName(
  unsigned int keysetID) const
{
  PIRKeysetCollection::const_iterator i = keysetsInfo.find(keysetID);

  if ((i == keysetsInfo.end()) || !i->second)
    return QString("Database Error");

  return QString(i->second->getKeysetName());
}


void PIRKeysetManager::populateKeyset(
  PIRKeysetMetaData *keyset)
{
  // Set up the keyset collection:
  keysetsInfo[keyset->getID()] = keyset;

  keyset->moveProtocolToThread(&commandThread);

  // Also, set up a name-based index into the collection:
  makeIndex
    [QString(makeManager.getMakeString(keyset->getMake()))]
    [QString(keyset->getKeysetName())]
    = keyset->getID();
}


void PIRKeysetManager::populateGuiWidget(
  PIRSelectKeysetForm *skf) const
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
  unsigned int keysetID) const
{
  PIRKeysetCollection::const_iterator i = keysetsInfo.find(keysetID);
  if ((i != keysetsInfo.end()) && i->second)
  {
    i->second->populateDeviceTypes(kwi);
  }
}
