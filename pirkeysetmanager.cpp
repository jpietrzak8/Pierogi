#include "pirkeysetmanager.h"

#include <QSettings>

#include "pirkeysetmetadata.h"
#include "pirselectkeysetform.h"
#include "pirkeysetwidgetitem.h"
#include "dialogs/pirfavoritesdialog.h"

#include "keysets/acer.h"
#include "keysets/adb.h"
#include "keysets/admiral.h"
#include "keysets/aiwa.h"
#include "keysets/alpine.h"
#include "keysets/anitech.h"
#include "keysets/aoc.h"
#include "keysets/apple.h"
#include "keysets/arcam.h"
#include "keysets/beko.h"
#include "keysets/benq.h"
#include "keysets/blaupunkt.h"
#include "keysets/bose.h"
#include "keysets/bush.h"
#include "keysets/cambridge.h"
#include "keysets/canon.h"
#include "keysets/changhong.h"
#include "keysets/cisco.h"
#include "keysets/compro.h"
#include "keysets/creative.h"
#include "keysets/crown.h"
#include "keysets/crownmustang.h"
#include "keysets/daewoo.h"
#include "keysets/dell.h"
#include "keysets/denon.h"
#include "keysets/deutschetelekom.h"
#include "keysets/digitalstream.h"
#include "keysets/directv.h"
#include "keysets/dish.h"
#include "keysets/dreambox.h"
#include "keysets/dse.h"
#include "keysets/dune.h"
#include "keysets/dynex.h"
#include "keysets/ei.h"
#include "keysets/elgato.h"
#include "keysets/emerson.h"
#include "keysets/emtec.h"
#include "keysets/epson.h"
#include "keysets/fortec.h"
#include "keysets/foxtel.h"
#include "keysets/frontech.h"
#include "keysets/gadmei.h"
#include "keysets/genius.h"
#include "keysets/goldstar.h"
#include "keysets/goodmans.h"
#include "keysets/grundig.h"
#include "keysets/haier.h"
#include "keysets/hantarex.h"
#include "keysets/harmankardon.h"
#include "keysets/hauppauge.h"
#include "keysets/hitachi.h"
#include "keysets/homecast.h"
#include "keysets/hp.h"
#include "keysets/huawei.h"
#include "keysets/humax.h"
#include "keysets/hyundai.h"
#include "keysets/ilo.h"
#include "keysets/irobot.h"
#include "keysets/jvc.h"
#include "keysets/kaon.h"
#include "keysets/kathrein.h"
#include "keysets/kenwood.h"
#include "keysets/keymat.h"
#include "keysets/konka.h"
#include "keysets/lexuz.h"
#include "keysets/lg.h"
#include "keysets/lifetec.h"
#include "keysets/loewe.h"
#include "keysets/logitech.h"
#include "keysets/magnavox.h"
#include "keysets/magnum.h"
#include "keysets/mce.h"
#include "keysets/medialink.h"
#include "keysets/medion.h"
#include "keysets/mitsubishi.h"
#include "keysets/motorola.h"
#include "keysets/mtlogic.h"
#include "keysets/multichoice.h"
#include "keysets/nad.h"
#include "keysets/nec.h"
#include "keysets/nikon.h"
#include "keysets/nokia.h"
#include "keysets/octagon.h"
#include "keysets/olympus.h"
#include "keysets/onida.h"
#include "keysets/onkyo.h"
#include "keysets/orion.h"
#include "keysets/panasonic.h"
#include "keysets/pentax.h"
#include "keysets/philco.h"
#include "keysets/philips.h"
#include "keysets/pinnacle.h"
#include "keysets/pioneer.h"
#include "keysets/proview.h"
#include "keysets/qnap.h"
#include "keysets/raite.h"
#include "keysets/rca.h"
#include "keysets/roku.h"
#include "keysets/saba.h"
#include "keysets/sagem.h"
#include "keysets/sagemcom.h"
#include "keysets/samsung.h"
#include "keysets/sanyo.h"
#include "keysets/sharp.h"
#include "keysets/sinotec.h"
#include "keysets/sky.h"
#include "keysets/sony.h"
#include "keysets/starhub.h"
#include "keysets/starsat.h"
#include "keysets/strong.h"
#include "keysets/sylvania.h"
#include "keysets/technics.h"
#include "keysets/technisat.h"
#include "keysets/telefunken.h"
#include "keysets/telenet.h"
#include "keysets/thomson.h"
#include "keysets/tivo.h"
#include "keysets/topfield.h"
#include "keysets/toshiba.h"
#include "keysets/triax.h"
#include "keysets/united.h"
#include "keysets/universum.h"
#include "keysets/venturer.h"
#include "keysets/vestel.h"
#include "keysets/viewsat.h"
#include "keysets/viewsonic.h"
#include "keysets/virgin.h"
#include "keysets/vizio.h"
#include "keysets/wd.h"
#include "keysets/westinghouse.h"
#include "keysets/wiwa.h"
#include "keysets/xcruiser.h"
#include "keysets/yamaha.h"
#include "keysets/zenith.h"

#include "pirexception.h"

// Need mutex for thread support:
#include <QMutex>

// Debugging includes:
#include <iostream>

// Global communications mechanism:
extern bool stopRepeatingFlag;
extern QMutex stopRepeatingMutex;

// Global helper objects:
PIRMakeMgr makeManager;

// Now, on to the actual method definitions:

PIRKeysetManager::PIRKeysetManager()
  : counter(0) // Note: Zero is now a sentinel value, no keysets can use it!
{
  // Create the keysets.  Ugly!  This needs to be worked on!
  setupKeyset(new AcerTV1(++counter));
  setupKeyset(new AcerPC1(++counter));

  setupKeyset(new ADBSTB1(++counter));
  setupKeyset(new ADBSTB2(++counter));
  setupKeyset(new ADBSTB3(++counter));
  setupKeyset(new ADBSTB4(++counter));
  setupKeyset(new ADBSTB5(++counter));
  setupKeyset(new ADBSTB6(++counter));

  setupKeyset(new AdmiralTV1(++counter));
  setupKeyset(new AdmiralTV2(++counter));
  setupKeyset(new AdmiralVCR1(++counter));

  setupKeyset(new AiwaVCR1(++counter));
  setupKeyset(new AiwaVCR2(++counter));
  setupKeyset(new AiwaVCR3(++counter));
  setupKeyset(new AiwaAudio1(++counter));
  setupKeyset(new AiwaAudio1a(++counter));
  setupKeyset(new AiwaAudio2(++counter));
  setupKeyset(new AiwaAudio2a(++counter));
  setupKeyset(new AiwaAudio2b(++counter));
  setupKeyset(new AiwaAudio2c(++counter));
  setupKeyset(new AiwaAudio3(++counter));
  setupKeyset(new AiwaAudio4(++counter));
  setupKeyset(new AiwaAudio5(++counter));
  setupKeyset(new AiwaAudio6(++counter));
  setupKeyset(new AiwaCarStereo1(++counter));
  setupKeyset(new AiwaDVD1(++counter));

  setupKeyset(new AlpineAudio1(++counter));

  setupKeyset(new AnitechTV1(++counter));
  setupKeyset(new AnitechVCR1(++counter));

  setupKeyset(new AOCTV1(++counter));

  setupKeyset(new AppleWhiteRemote(++counter));

  setupKeyset(new ArcamReceiver1(++counter));

  setupKeyset(new BekoTV1(++counter));

  setupKeyset(new BenQTV1(++counter));
  setupKeyset(new BenQProjector1(++counter));
  setupKeyset(new BenQProjector1a(++counter));
  setupKeyset(new BenQProjector2(++counter));
  setupKeyset(new BenQProjector3(++counter));
  setupKeyset(new BenQProjector4(++counter));
  setupKeyset(new BenQProjector5(++counter));

  setupKeyset(new BlaupunktVCR1(++counter));

  setupKeyset(new BoseRadio1(++counter));
  setupKeyset(new BoseRadio2(++counter));
  setupKeyset(new BoseRadio3(++counter));
  setupKeyset(new BoseHomeTheater1(++counter));

  setupKeyset(new BushTV1(++counter));
  setupKeyset(new BushTV2(++counter));
  setupKeyset(new BushSTB1(++counter));

  setupKeyset(new CambridgeCD1(++counter));
  setupKeyset(new CambridgeAudio1(++counter));
  setupKeyset(new CambridgeAudio2(++counter));
  setupKeyset(new CambridgeAudio3(++counter));
  setupKeyset(new CambridgeDVD1(++counter));

  setupKeyset(new CanonDSLR1(++counter));
  setupKeyset(new CanonCamcorder1(++counter));
  setupKeyset(new CanonPowershot1(++counter));

  setupKeyset(new ChanghongTV1(++counter));
  setupKeyset(new ChanghongTV1a(++counter));
  setupKeyset(new ChanghongTV1b(++counter));
  setupKeyset(new ChanghongTV2(++counter));
  setupKeyset(new ChanghongTV3(++counter));

  setupKeyset(new CiscoSTB1(++counter));
  setupKeyset(new CiscoSTB2(++counter));
  setupKeyset(new CiscoSTB3(++counter));
  setupKeyset(new CiscoSTB4(++counter));

  setupKeyset(new ComproTVCard1(++counter));

  setupKeyset(new CreativeAudio1(++counter));
  setupKeyset(new CreativeAudio2(++counter));
  setupKeyset(new CreativeAudio3(++counter));
  setupKeyset(new CreativeAudio4(++counter));

  setupKeyset(new CrownTV1(++counter));
  setupKeyset(new CrownAudio1(++counter));

  setupKeyset(new CrownMustangTV1(++counter));

  setupKeyset(new DaewooTV1(++counter));
  setupKeyset(new DaewooTV2(++counter));
  setupKeyset(new DaewooTV3(++counter));
  setupKeyset(new DaewooTV4(++counter));
  setupKeyset(new DaewooTV5(++counter));
  setupKeyset(new DaewooDVD1(++counter));
  setupKeyset(new DaewooVCR1(++counter));
  setupKeyset(new DaewooVCR2(++counter));

  setupKeyset(new DenonDVD1(++counter));
  setupKeyset(new DenonDVD2(++counter));
  setupKeyset(new DenonDVD3(++counter));
  setupKeyset(new DenonReceiver1(++counter));
  setupKeyset(new DenonReceiver1a(++counter));
  setupKeyset(new DenonReceiver1b(++counter));
  setupKeyset(new DenonReceiver1c(++counter));
  setupKeyset(new DenonReceiver1d(++counter));
  setupKeyset(new DenonReceiver1e(++counter));
  setupKeyset(new DenonReceiver1f(++counter));
  setupKeyset(new DenonReceiver2(++counter));
  setupKeyset(new DenonReceiver2a(++counter));
  setupKeyset(new DenonReceiver3(++counter));
  setupKeyset(new DenonAudio1(++counter));
  setupKeyset(new DenonAudio1a(++counter));
  setupKeyset(new DenonAudio1b(++counter));
  setupKeyset(new DenonAudio1c(++counter));
  setupKeyset(new DenonAudio1d(++counter));
  setupKeyset(new DenonAudio2(++counter));
  setupKeyset(new DenonAudio3(++counter));
  setupKeyset(new DenonAudio4(++counter));

  setupKeyset(new DellRemote1(++counter));

//  setupKeyset(new DeutscheTelekomSTB1(++counter));

  setupKeyset(new DigitalStreamReceiver(++counter));

  setupKeyset(new DirectvReceiver1(++counter));
  setupKeyset(new DirectvReceiver1a(++counter));
  setupKeyset(new DirectvReceiver1b(++counter));
  setupKeyset(new DirectvReceiver1c(++counter));
  setupKeyset(new DirectvReceiver1d(++counter));
  setupKeyset(new DirectvReceiver1e(++counter));

  setupKeyset(new DishReceiver1(++counter));
  setupKeyset(new DishReceiver1a(++counter));
  setupKeyset(new DishReceiver1b(++counter));
  setupKeyset(new DishReceiver1c(++counter));
  setupKeyset(new DishReceiver1d(++counter));
  setupKeyset(new DishReceiver1e(++counter));
  setupKeyset(new DishReceiver1f(++counter));
  setupKeyset(new DishReceiver1g(++counter));
  setupKeyset(new DishReceiver1h(++counter));
  setupKeyset(new DishReceiver1i(++counter));
  setupKeyset(new DishReceiver1j(++counter));
  setupKeyset(new DishReceiver1k(++counter));
  setupKeyset(new DishReceiver1l(++counter));
  setupKeyset(new DishReceiver1m(++counter));
  setupKeyset(new DishReceiver1n(++counter));
  setupKeyset(new DishReceiver1o(++counter));

  setupKeyset(new DreamboxSat1(++counter));
  setupKeyset(new DreamboxSat1a(++counter));
  setupKeyset(new DreamboxSat1b(++counter));
  setupKeyset(new DreamboxSat1c(++counter));
  setupKeyset(new DreamboxSat2(++counter));
  setupKeyset(new DreamboxSat3(++counter));
  setupKeyset(new DreamboxSat4(++counter));
  setupKeyset(new DreamboxSat5(++counter));

  setupKeyset(new DSEDVD1(++counter));
  setupKeyset(new DSESat1(++counter));

  setupKeyset(new DuneSTB1(++counter));

  setupKeyset(new DynexTV1(++counter));

  setupKeyset(new EiTV1(++counter));

  setupKeyset(new ElgatoEyeTV1(++counter));

  setupKeyset(new EmersonTV1(++counter));
  setupKeyset(new EmersonDVD1(++counter));

  setupKeyset(new EmtecSTB1(++counter));
  setupKeyset(new EmtecSTB2(++counter));

  setupKeyset(new EpsonProjector1(++counter));
  setupKeyset(new EpsonProjector1a(++counter));

  setupKeyset(new FortecReceiver1(++counter));
  setupKeyset(new FortecReceiver2(++counter));

  setupKeyset(new FoxtelSTB1(++counter));
  setupKeyset(new FoxtelSTB2(++counter));

  setupKeyset(new FrontechTV1(++counter));
  setupKeyset(new FrontechTV2(++counter));

  setupKeyset(new GadmeiTuner1(++counter));

  setupKeyset(new GeniusSpeakers1(++counter));

  setupKeyset(new GoldStarTV1(++counter));
  setupKeyset(new GoldStarTV2(++counter));
  setupKeyset(new GoldStarVCR1(++counter));
  setupKeyset(new GoldStarVCR1a(++counter));
  setupKeyset(new GoldStarVCR1b(++counter));
  setupKeyset(new GoldStarVCR1c(++counter));
  setupKeyset(new GoldStarCD1(++counter));

  setupKeyset(new GoodmansSTB1(++counter));
  setupKeyset(new GoodmansVCR1(++counter));
  setupKeyset(new GoodmansDVD1(++counter));
  setupKeyset(new GoodmansAudio1(++counter));

  setupKeyset(new GrundigSat1(++counter));
  setupKeyset(new GrundigSat2(++counter));
  setupKeyset(new GrundigSat3(++counter));
  setupKeyset(new GrundigAmp1(++counter));
  setupKeyset(new GrundigAudio1(++counter));
  setupKeyset(new GrundigAudio2(++counter));
  setupKeyset(new GrundigVCR1(++counter));
  setupKeyset(new GrundigVCR1a(++counter));
  setupKeyset(new GrundigTV1(++counter));
  setupKeyset(new GrundigTV2(++counter));
  setupKeyset(new GrundigTV3(++counter));
  setupKeyset(new GrundigTV4(++counter));
  setupKeyset(new GrundigDVD1(++counter));

  setupKeyset(new HaierTV1(++counter));

  setupKeyset(new HantarexTV1(++counter));
  setupKeyset(new HantarexTV2(++counter));

  setupKeyset(new HarmanKardonAmp1(++counter));
  setupKeyset(new HarmanKardonAmp2(++counter));
  setupKeyset(new HarmanKardonReceiver2(++counter));
  setupKeyset(new HarmanKardonTape1(++counter));
  setupKeyset(new HarmanKardonDVD1(++counter));
  setupKeyset(new HarmanKardonDVD1a(++counter));
  setupKeyset(new HarmanKardonCD1(++counter));
  setupKeyset(new HarmanKardonCD2(++counter));

  setupKeyset(new HauppaugePCTV1(++counter));
  setupKeyset(new HauppaugePCTV1a(++counter));
  setupKeyset(new HauppaugePCTV1b(++counter));
  setupKeyset(new HauppaugePCTV1c(++counter));
  setupKeyset(new HauppaugePCTV2(++counter));

  setupKeyset(new HitachiTV1(++counter));
  setupKeyset(new HitachiTV1a(++counter));
  setupKeyset(new HitachiTV1b(++counter));
  setupKeyset(new HitachiTV1c(++counter));
  setupKeyset(new HitachiTV2(++counter));
  setupKeyset(new HitachiTV3(++counter));
  setupKeyset(new HitachiProjector(++counter));
  setupKeyset(new HitachiDVD1(++counter));
  setupKeyset(new HitachiAudio1(++counter));
  setupKeyset(new HitachiVCR1(++counter));

  setupKeyset(new HomecastReceiver1(++counter));
  setupKeyset(new HomecastReceiver2(++counter));

  setupKeyset(new HPRemote1(++counter));

  setupKeyset(new HuaweiSTB1(++counter));
  setupKeyset(new HuaweiSTB2(++counter));

  setupKeyset(new HumaxReceiver1(++counter));
  setupKeyset(new HumaxReceiver2(++counter));
  setupKeyset(new HumaxReceiver3(++counter));

  setupKeyset(new HyundaiDVD1(++counter));
  setupKeyset(new HyundaiAudio1(++counter));
  setupKeyset(new HyundaiTV1(++counter));

  setupKeyset(new ILOTV1(++counter));
  setupKeyset(new ILOTV2(++counter));
  setupKeyset(new ILOTV3(++counter));

  setupKeyset(new IRobotRoomba1(++counter));

  setupKeyset(new JVCSat1(++counter));
  setupKeyset(new JVCSat2(++counter));
  setupKeyset(new JVCVCR1(++counter));
  setupKeyset(new JVCVCR1a(++counter));
  setupKeyset(new JVCVCRBmode1(++counter));
  setupKeyset(new JVCVCRBmode1a(++counter));
  setupKeyset(new JVCTV1(++counter));
  setupKeyset(new JVCTV1a(++counter));
  setupKeyset(new JVCTV1b(++counter));
  setupKeyset(new JVCTV1c(++counter));
  setupKeyset(new JVCTV1d(++counter));
  setupKeyset(new JVCDAT1(++counter));
  setupKeyset(new JVCCarDeck1(++counter));
  setupKeyset(new JVCAudio1(++counter));
  setupKeyset(new JVCAudio1a(++counter));
  setupKeyset(new JVCAudio1b(++counter));
  setupKeyset(new JVCAudio2(++counter));
  setupKeyset(new JVCDVD1(++counter));

  setupKeyset(new KaonSat1(++counter));

  setupKeyset(new KathreinSat1(++counter));
  setupKeyset(new KathreinSat2(++counter));
  setupKeyset(new KathreinSat3(++counter));

  setupKeyset(new KenwoodAudio1(++counter));
  setupKeyset(new KenwoodComponent1(++counter));
  setupKeyset(new KenwoodComponent2(++counter));
  setupKeyset(new KenwoodComponent3(++counter));
  setupKeyset(new KenwoodCD1(++counter));
  setupKeyset(new KenwoodDVD1(++counter));
  setupKeyset(new KenwoodTV1(++counter));

  setupKeyset(new KeymatTV1(++counter));
  setupKeyset(new KeymatTV2(++counter));

  setupKeyset(new KonkaTV1(++counter));
  setupKeyset(new KonkaTV2(++counter));

  setupKeyset(new LexuzDVB1(++counter));

  setupKeyset(new LGTV1(++counter));
  setupKeyset(new LGTV1a(++counter));
  setupKeyset(new LGTV1b(++counter));
  setupKeyset(new LGTV1c(++counter));
  setupKeyset(new LGTV2(++counter));
  setupKeyset(new LGTV2a(++counter));
  setupKeyset(new LGTV2b(++counter));
  setupKeyset(new LGHT1(++counter));
  setupKeyset(new LGHT2(++counter));
  setupKeyset(new LGHT2a(++counter));
  setupKeyset(new LGDisc1(++counter));
  setupKeyset(new LGDisc2(++counter));
  setupKeyset(new LGDisc2a(++counter));
  setupKeyset(new LGVCR1(++counter));
  setupKeyset(new LGVCR1a(++counter));
  setupKeyset(new LGVCR1b(++counter));
  setupKeyset(new LGAC1(++counter));

  setupKeyset(new LifetecTV1(++counter));
  setupKeyset(new LifetecTV2(++counter));
  setupKeyset(new LifetecVCR1(++counter));
  setupKeyset(new LifetecAudio1(++counter));

  setupKeyset(new LoeweTV1(++counter));
  setupKeyset(new LoeweVCR1(++counter));
  setupKeyset(new LoeweDVD1(++counter));

  setupKeyset(new LogitechSpeakers(++counter));
  setupKeyset(new LogitechSqueezebox(++counter));

  setupKeyset(new MagnavoxDVD1(++counter));
  setupKeyset(new MagnavoxVCR1(++counter));
  setupKeyset(new MagnavoxConverterBox1(++counter));
  setupKeyset(new MagnavoxTV1(++counter));

  setupKeyset(new MagnumTV1(++counter));

  setupKeyset(new MCERemote1(++counter));
  setupKeyset(new MCERemote1a(++counter));
  setupKeyset(new MCERemote1b(++counter));
  setupKeyset(new MCERemote1c(++counter));
  setupKeyset(new MCERemote1d(++counter));
  setupKeyset(new MCERemote1e(++counter));
  setupKeyset(new MCERemote1f(++counter));
  setupKeyset(new MCERemote1g(++counter));

  setupKeyset(new MedialinkSTB1(++counter));

  setupKeyset(new MedionSTB1(++counter));
  setupKeyset(new MedionDVD1(++counter));
  setupKeyset(new MedionDVD2(++counter));
  setupKeyset(new MedionVCR1(++counter));

  setupKeyset(new MitsubishiTV1(++counter));
  setupKeyset(new MitsubishiTV1a(++counter));
  setupKeyset(new MitsubishiVCR1(++counter));
  setupKeyset(new MitsubishiVCR1a(++counter));
  setupKeyset(new MitsubishiProjector1(++counter));
  setupKeyset(new MitsubishiProjector2(++counter));

  setupKeyset(new Motorola4DTV(++counter));
  setupKeyset(new MotorolaSTB1(++counter));
  setupKeyset(new MotorolaSTB1a(++counter));
  setupKeyset(new MotorolaSTB1b(++counter));
  setupKeyset(new MotorolaSkyDigital(++counter));

  setupKeyset(new MTLogicTV1(++counter));

  setupKeyset(new MultichoiceSTB1(++counter));
  setupKeyset(new MultichoiceSTB2(++counter));

  setupKeyset(new NADAudio1(++counter));
  setupKeyset(new NADTuner1(++counter));
  setupKeyset(new NADDVD1(++counter));
  setupKeyset(new NADCD1(++counter));
  setupKeyset(new NADCD2(++counter));
  setupKeyset(new NADTape1(++counter));

  setupKeyset(new NECTV1(++counter));
  setupKeyset(new NECVCR1(++counter));
  setupKeyset(new NECVCR2(++counter));
  setupKeyset(new NECVCR3(++counter));
  setupKeyset(new NECDVD1(++counter));
  setupKeyset(new NECProjector1(++counter));
  setupKeyset(new NECProjector2(++counter));

  setupKeyset(new NikonDSLR1(++counter));

  setupKeyset(new NokiaGenericVCR(++counter));

  setupKeyset(new OctagonSat1(++counter));
  setupKeyset(new OctagonSat1a(++counter));
  setupKeyset(new OctagonSat2(++counter));

  setupKeyset(new OlympusCamera1(++counter));

  setupKeyset(new OnidaTV1(++counter));
  setupKeyset(new OnidaDVD1(++counter));

  setupKeyset(new OnkyoAudio1(++counter));
  setupKeyset(new OnkyoAudio2(++counter));
  setupKeyset(new OnkyoAudio2a(++counter));
  setupKeyset(new OnkyoAudio3(++counter));
  setupKeyset(new OnkyoAudio4(++counter));
  setupKeyset(new OnkyoAudio5(++counter));
  setupKeyset(new OnkyoDVD1(++counter));
  setupKeyset(new OnkyoDVD2(++counter));

  setupKeyset(new OrionTV1(++counter));
  setupKeyset(new OrionTV2(++counter));
  setupKeyset(new OrionTV3(++counter));
  setupKeyset(new OrionVCR1(++counter));
  setupKeyset(new OrionVCR2(++counter));
  setupKeyset(new OrionDVD1(++counter));

  setupKeyset(new PanasonicCarAudio(++counter));
  setupKeyset(new PanasonicSat1(++counter));
  setupKeyset(new PanasonicSat1a(++counter));
  setupKeyset(new PanasonicTV1(++counter));
  setupKeyset(new PanasonicTV1a(++counter));
  setupKeyset(new PanasonicTV1b(++counter));
  setupKeyset(new PanasonicVCR1(++counter));
  setupKeyset(new PanasonicVCR1a(++counter));
  setupKeyset(new PanasonicVCR1b(++counter));
  setupKeyset(new PanasonicVCR1c(++counter));
  setupKeyset(new PanasonicDVD1(++counter));
  setupKeyset(new PanasonicDVD1a(++counter));
  setupKeyset(new PanasonicAudio1(++counter));
  setupKeyset(new PanasonicAudio2(++counter));
  setupKeyset(new PanasonicAudio2a(++counter));
  setupKeyset(new PanasonicAC1(++counter));

  setupKeyset(new PentaxCamera1(++counter));

  setupKeyset(new PhilcoTV(++counter));

  setupKeyset(new PhilipsTV1(++counter));
  setupKeyset(new PhilipsTV1a(++counter));
  setupKeyset(new PhilipsTV1b(++counter));
  setupKeyset(new PhilipsTV1c(++counter));
  setupKeyset(new PhilipsTV1d(++counter));
  setupKeyset(new PhilipsTV1e(++counter));
  setupKeyset(new PhilipsTV1f(++counter));
  setupKeyset(new PhilipsTV2(++counter));
  setupKeyset(new PhilipsTV2a(++counter));
  setupKeyset(new PhilipsTV2b(++counter));
  setupKeyset(new PhilipsTV3(++counter));
  setupKeyset(new PhilipsDVD1(++counter));
  setupKeyset(new PhilipsDVD1a(++counter));
  setupKeyset(new PhilipsDVD1b(++counter));
  setupKeyset(new PhilipsDVD1c(++counter));
  setupKeyset(new PhilipsDVD1d(++counter));
  setupKeyset(new PhilipsDVD2(++counter));
  setupKeyset(new PhilipsDVD3(++counter));
  setupKeyset(new PhilipsDVD3a(++counter));
  setupKeyset(new PhilipsDVD4(++counter));
  setupKeyset(new PhilipsVCR1(++counter));
  setupKeyset(new PhilipsVCR1a(++counter));
  setupKeyset(new PhilipsVCR1b(++counter));
  setupKeyset(new PhilipsVCR1c(++counter));
  setupKeyset(new PhilipsSat1(++counter));
  setupKeyset(new PhilipsSat2(++counter));
  setupKeyset(new PhilipsSat2a(++counter));
  setupKeyset(new PhilipsSat3(++counter));
  setupKeyset(new PhilipsAudio1(++counter));
  setupKeyset(new PhilipsAudio1a(++counter));
  setupKeyset(new PhilipsAudio1b(++counter));
  setupKeyset(new PhilipsAudio2(++counter));
  setupKeyset(new PhilipsAudio3(++counter));
  setupKeyset(new PhilipsAudio4(++counter));

  setupKeyset(new PinnaclePCTV1(++counter));
  setupKeyset(new PinnaclePCTV2(++counter));
  setupKeyset(new PinnaclePCTV3(++counter));

  setupKeyset(new PioneerTV1(++counter));
  setupKeyset(new PioneerTV2(++counter));
  setupKeyset(new PioneerTV3(++counter));
  setupKeyset(new PioneerAudio1(++counter));
  setupKeyset(new PioneerAudio1a(++counter));
  setupKeyset(new PioneerAudio2(++counter));
  setupKeyset(new PioneerAudio3(++counter));
  setupKeyset(new PioneerAudio4(++counter));
  setupKeyset(new PioneerAudio5(++counter));
  setupKeyset(new PioneerCD1(++counter));
  setupKeyset(new PioneerLaserDisc1(++counter));
  setupKeyset(new PioneerDVD1(++counter));
  setupKeyset(new PioneerCarStereo1(++counter));

  setupKeyset(new ProviewDVD1(++counter));

  setupKeyset(new QNAPPlayer1(++counter));

  setupKeyset(new RaiteDVD1(++counter));

  setupKeyset(new RCATV1(++counter));
  setupKeyset(new RCATV1a(++counter));
  setupKeyset(new RCATV1b(++counter));
//  setupKeyset(new RCAAux1(++counter));
//  setupKeyset(new RCAAux2(++counter));
//  setupKeyset(new RCAAux2a(++counter));
  setupKeyset(new RCAVCR1(++counter));
  setupKeyset(new RCAVCR1a(++counter));
  setupKeyset(new RCADVD1(++counter));
  setupKeyset(new RCADVD1a(++counter));
  setupKeyset(new RCASat1(++counter));
  setupKeyset(new RCASat2(++counter));

  setupKeyset(new RokuBox1(++counter));
  setupKeyset(new RokuBox2(++counter));

  setupKeyset(new SabaTV1(++counter));
  setupKeyset(new SabaTV2(++counter));

  setupKeyset(new SagemTVBox1(++counter));
  setupKeyset(new SagemTVBox1a(++counter));

  setupKeyset(new SagemcomSTB1(++counter));
  setupKeyset(new SagemcomSTB2(++counter));

  setupKeyset(new SamsungTV1(++counter));
  setupKeyset(new SamsungTV1a(++counter));
  setupKeyset(new SamsungTV1b(++counter));
  setupKeyset(new SamsungTV2(++counter));
  setupKeyset(new SamsungTV3(++counter));
  setupKeyset(new SamsungTV3a(++counter));
  setupKeyset(new SamsungVCR1(++counter));
  setupKeyset(new SamsungVCR1a(++counter));
  setupKeyset(new SamsungVCR1b(++counter));
  setupKeyset(new SamsungVCR1c(++counter));
  setupKeyset(new SamsungVCR1d(++counter));
  setupKeyset(new SamsungVCR1e(++counter));
  setupKeyset(new SamsungDVD1(++counter));
  setupKeyset(new SamsungDVD1a(++counter));
  setupKeyset(new SamsungDVD1b(++counter));
  setupKeyset(new SamsungDVD2(++counter));
  setupKeyset(new SamsungAC1(++counter));
  setupKeyset(new SamsungAC2(++counter));
  setupKeyset(new SamsungDVBT1(++counter));

  setupKeyset(new SanyoVCR1(++counter));
  setupKeyset(new SanyoDVD1(++counter));
  setupKeyset(new SanyoTV1(++counter));
  setupKeyset(new SanyoTV1a(++counter));
  setupKeyset(new SanyoTV1b(++counter));
  setupKeyset(new SanyoTV1c(++counter));
  setupKeyset(new SanyoTV1d(++counter));
  setupKeyset(new SanyoProjector(++counter));

  setupKeyset(new SharpTV1(++counter));
  setupKeyset(new SharpTV1a(++counter));
  setupKeyset(new SharpTV1b(++counter));
  setupKeyset(new SharpTV1c(++counter));
  setupKeyset(new SharpTV1d(++counter));
  setupKeyset(new SharpTV1e(++counter));
  setupKeyset(new SharpVCR1(++counter));
  setupKeyset(new SharpReceiver1(++counter));
  setupKeyset(new SharpAC1(++counter));

  setupKeyset(new SinotecTV1(++counter));
  setupKeyset(new SinotecTV2(++counter));

  setupKeyset(new SkyReceiver1(++counter));
  setupKeyset(new SkyReceiver1a(++counter));

  setupKeyset(new SonyTV1(++counter));
  setupKeyset(new SonyTV1a(++counter));
  setupKeyset(new SonyTV1b(++counter));
  setupKeyset(new SonyTV1c(++counter));
  setupKeyset(new SonyTV2(++counter));
  setupKeyset(new SonyAmp1(++counter));
  setupKeyset(new SonyAmp2(++counter));
  setupKeyset(new SonyAudio1(++counter));
  setupKeyset(new SonyAudio1a(++counter));
  setupKeyset(new SonyDAT1(++counter));
  setupKeyset(new SonyDVD1(++counter));
  setupKeyset(new SonyDVD1a(++counter));
  setupKeyset(new SonyDVD1b(++counter));
  setupKeyset(new SonyDVD2(++counter));
  setupKeyset(new SonyDVD2a(++counter));
  setupKeyset(new SonyVCR1(++counter));
  setupKeyset(new SonyVCR1a(++counter));
  setupKeyset(new SonyVCR1b(++counter));
  setupKeyset(new SonyReceiver1(++counter));
  setupKeyset(new SonyCD1(++counter));
  setupKeyset(new SonyCD1a(++counter));
  setupKeyset(new SonyCD1b(++counter));
  setupKeyset(new SonyProjector1(++counter));
  setupKeyset(new SonyProjector1a(++counter));
  setupKeyset(new SonyPlaystation1(++counter));

  setupKeyset(new StarhubSTB1(++counter));
  setupKeyset(new StarhubSTB1a(++counter));

  setupKeyset(new StarsatSat1(++counter));

  setupKeyset(new StrongSat1(++counter));
  setupKeyset(new StrongSat2(++counter));
  setupKeyset(new StrongSat3(++counter));
  setupKeyset(new StrongSat4(++counter));
  setupKeyset(new StrongDVBT1(++counter));

  setupKeyset(new SylvaniaTV1(++counter));

  setupKeyset(new TechnicsAudio1(++counter));
  setupKeyset(new TechnicsAudio1a(++counter));
  setupKeyset(new TechnicsAudio2(++counter));
  setupKeyset(new TechnicsAudio3(++counter));
  setupKeyset(new TechnicsAudio3a(++counter));
  setupKeyset(new TechnicsReceiver1(++counter));
  setupKeyset(new TechnicsReceiver1a(++counter));
  setupKeyset(new TechnicsCD1(++counter));
  setupKeyset(new TechnicsDVD1(++counter));

  setupKeyset(new TechnisatSTB1(++counter));
  setupKeyset(new TechnisatSTB1a(++counter));
  setupKeyset(new TechnisatSTB2(++counter));
  setupKeyset(new TechnisatSTB2a(++counter));
  setupKeyset(new TechnisatSTB3(++counter));
  setupKeyset(new TechnisatSTB3a(++counter));

  setupKeyset(new TelefunkenTV1(++counter));
  setupKeyset(new TelefunkenTV1a(++counter));

  setupKeyset(new TelenetSTB1(++counter));

  setupKeyset(new ThomsonConverter1(++counter));
  setupKeyset(new ThomsonTV1(++counter));
  setupKeyset(new ThomsonVCR1(++counter));
  setupKeyset(new ThomsonVCR1a(++counter));
  setupKeyset(new ThomsonDVD1(++counter));
  setupKeyset(new ThomsonSat1(++counter));
  setupKeyset(new ThomsonAudio1(++counter));
  setupKeyset(new ThomsonAudio2(++counter));

  setupKeyset(new Tivo1(++counter));
  setupKeyset(new Tivo1a(++counter));
  setupKeyset(new Tivo1b(++counter));
  setupKeyset(new Tivo1c(++counter));
  setupKeyset(new Tivo1d(++counter));

  setupKeyset(new TopfieldPVR1(++counter));
  setupKeyset(new TopfieldSat1(++counter));

  setupKeyset(new ToshibaTV1(++counter));
  setupKeyset(new ToshibaTV1a(++counter));
  setupKeyset(new ToshibaTV1b(++counter));
  setupKeyset(new ToshibaTV1c(++counter));
  setupKeyset(new ToshibaTV1d(++counter));
  setupKeyset(new ToshibaTV1e(++counter));
  setupKeyset(new ToshibaTV1f(++counter));
  setupKeyset(new ToshibaTV1g(++counter));
  setupKeyset(new ToshibaTV1h(++counter));
  setupKeyset(new ToshibaTV1i(++counter));
  setupKeyset(new ToshibaVCR1(++counter));
  setupKeyset(new ToshibaVCR1a(++counter));
  setupKeyset(new ToshibaDisc1(++counter));
  setupKeyset(new ToshibaDisc1a(++counter));
  setupKeyset(new ToshibaDisc1b(++counter));
  setupKeyset(new ToshibaDisc1c(++counter));
  setupKeyset(new ToshibaDisc1d(++counter));

  setupKeyset(new TriaxSTB1(++counter));
  setupKeyset(new TriaxSTB2(++counter));
  setupKeyset(new TriaxSTB2a(++counter));
  setupKeyset(new TriaxSTB3(++counter));
  setupKeyset(new TriaxSTB3a(++counter));
  setupKeyset(new TriaxSTB4(++counter));

  setupKeyset(new UnitedDVD1(++counter));
  setupKeyset(new UnitedDVBT1(++counter));

  setupKeyset(new UniversumVCR1(++counter));
  setupKeyset(new UniversumVCR2(++counter));
  setupKeyset(new UniversumVCR3(++counter));
  setupKeyset(new UniversumTV1(++counter));
  setupKeyset(new UniversumTV1a(++counter));
  setupKeyset(new UniversumSat1(++counter));
  setupKeyset(new UniversumAudio1(++counter));

  setupKeyset(new VenturerTV1(++counter));
  setupKeyset(new VenturerDVD1(++counter));
  setupKeyset(new VenturerSTB1(++counter));

  setupKeyset(new VestelTV1(++counter));
  setupKeyset(new VestelTV2(++counter));

  setupKeyset(new ViewsatSat1(++counter));
  setupKeyset(new ViewsatSat1a(++counter));

  setupKeyset(new ViewsonicProjector1(++counter));
  setupKeyset(new ViewsonicProjector2(++counter));

  setupKeyset(new VirginSTB1(++counter));

  setupKeyset(new VizioTV1(++counter));

  setupKeyset(new WDMediaPlayer1(++counter));
  setupKeyset(new WDMediaPlayer1a(++counter));
  setupKeyset(new WDMediaPlayer1b(++counter));

  setupKeyset(new WestinghouseTV1(++counter));
  setupKeyset(new WestinghouseTV2(++counter));

  setupKeyset(new WiwaSTB1(++counter));

  setupKeyset(new XcruiserSat1(++counter));

  setupKeyset(new YamahaDVD1(++counter));
  setupKeyset(new YamahaDVD1a(++counter));
  setupKeyset(new YamahaAudio1(++counter));
  setupKeyset(new YamahaAudio1a(++counter));
  setupKeyset(new YamahaAudio2(++counter));
  setupKeyset(new YamahaAudio2a(++counter));
  setupKeyset(new YamahaAudio2b(++counter));
  setupKeyset(new YamahaAudio2c(++counter));
  setupKeyset(new YamahaAudio2d(++counter));
  setupKeyset(new YamahaAudio3(++counter));
  setupKeyset(new YamahaAudio4(++counter));
  setupKeyset(new YamahaTV1(++counter));
  setupKeyset(new YamahaKaraoke1(++counter));

  setupKeyset(new ZenithTV1(++counter));
  setupKeyset(new ZenithConverterBox1(++counter));

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

  // Delete all the keysets:
  PIRKeysetCollection::iterator i = keysetsInfo.begin();
  while (i != keysetsInfo.end())
  {
    if ((*i).second) delete (*i).second;
    ++i;
  }

  // Tell the thread that we want it to stop:
  commandThread.exit();

  // Wait for the thread to stop:
  commandThread.wait();
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

  return new PIRKeysetWidgetItem(fullname, name, id, getMake(id));
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
  QObject *guiObject,
  unsigned int keysetID)
{
  PIRKeysetCollection::iterator i = keysetsInfo.find(keysetID);

  if (i == keysetsInfo.end())
  {
    // Should have some sort of error message here!
    return;
  }

  i->second->populateProtocol(guiObject);
  i->second->moveToThread(&commandThread);
}


unsigned int PIRKeysetManager::getCarrierFrequency(
  unsigned int keysetID)
{
  PIRKeysetCollection::iterator i = keysetsInfo.find(keysetID);

  if (i == keysetsInfo.end())
  {
    return 0;
  }

  return i->second->getCarrierFrequency();
}


void PIRKeysetManager::setCarrierFrequency(
  unsigned int carrierFrequency,
  unsigned int keysetID)
{
  PIRKeysetCollection::iterator i = keysetsInfo.find(keysetID);

  if (i == keysetsInfo.end())
  {
    return;
  }

  i->second->setCarrierFrequency(carrierFrequency);
}


unsigned int PIRKeysetManager::getDutyCycle(
  unsigned int keysetID)
{
  PIRKeysetCollection::iterator i = keysetsInfo.find(keysetID);

  if (i == keysetsInfo.end())
  {
    return 0;
  }

  return i->second->getDutyCycle();
}


void PIRKeysetManager::setDutyCycle(
  unsigned int dutyCycle,
  unsigned int keysetID)
{
  PIRKeysetCollection::iterator i = keysetsInfo.find(keysetID);

  if (i == keysetsInfo.end())
  {
    return;
  }

  i->second->setDutyCycle(dutyCycle);
}


const PIRACKeyset *PIRKeysetManager::getACKeyset(
  unsigned int keysetID) const
{
  PIRKeysetCollection::const_iterator i = keysetsInfo.find(keysetID);

  if (i == keysetsInfo.end())
  {
    return NULL;
  }

  const PIRKeysetMetaData *meta = i->second;

  if (!meta)
  {
    return NULL;
  }

  return (dynamic_cast<const PIRACKeyset *>(meta));
}


bool PIRKeysetManager::clearKeyset(
  unsigned int keysetID)
{
  PIRKeysetCollection::iterator i = keysetsInfo.find(keysetID);

  if (i == keysetsInfo.end())
  {
    return true; // best I can do here right now...
  }

  return i->second->clearProtocol();
}


void PIRKeysetManager::setupKeyset(
  PIRKeysetMetaData *keyset)
{
  // Set up the keyset collection:
  keysetsInfo[keyset->getID()] = keyset;

  // Set up a name-based index into the collection:
  makeIndex
    [QString(makeManager.getMakeString(keyset->getMake()))]
    [QString(keyset->getKeysetName())]
    = keyset->getID();
}


struct PIRUserData
{
  bool favorite;
  QString nickname;
  PIRTabBarName tabBarName;
  int panelIndex;
};
typedef std::map<QString, PIRUserData> PIRUDInnerMap;
typedef std::map<int, PIRUDInnerMap> PIRUDOuterMap;

void PIRKeysetManager::populateListWidgets(
  PIRSelectKeysetForm *skf,
  PIRFavoritesDialog *fd) const
{
  // First, pull out the user's keyset metadata:
  QSettings settings("pietrzak.org", "Pierogi");

  // Part 1 - The user's keyset nicknames:
  int size = settings.beginReadArray("userNames");
  int index = 0;
  QString makeStr;
  QString name;
  PIRMakeName makeID;
  QString userName;
  PIRUDOuterMap userData;

  while (index < size)
  {
    settings.setArrayIndex(index);
    name = settings.value("keysetName").toString();
    makeStr = settings.value("keysetMake").toString();
    makeID = makeManager.getMakeID(makeStr);
    userName = settings.value("keysetNickname").toString();

    // Insert an entry into the map.  We initialize the favorites bool to
    // false here, it'll be changed to true below if needed:
    userData[makeID][name].nickname = userName;
    userData[makeID][name].favorite = false;
    userData[makeID][name].tabBarName = Universal_Tabs;
    userData[makeID][name].panelIndex = 0;
    ++index;
  }
  settings.endArray();

  // Part 2 - The user's favorites:
  size = settings.beginReadArray("favorites");
  index = 0;

  while (index < size)
  {
    settings.setArrayIndex(index);
    name = settings.value("keysetName").toString();
    makeStr = settings.value("keysetMake").toString();
    makeID = makeManager.getMakeID(makeStr);

    // Insert an entry into the map:
    userData[makeID][name].favorite = true;

    // Add the favorite tab bar name:
    if (settings.contains("tabBarName"))
    {
      userData[makeID][name].tabBarName = PIRTabBarName(
        settings.value("tabBarName").toInt());
    }

    if (settings.contains("panelIndex"))
    {
      userData[makeID][name].panelIndex =
        settings.value("panelIndex").toInt();
    }

    ++index;
  }
  settings.endArray();

  // Now, we load the data into their respective QLists.
  PIRKeysetWidgetItem *kwi;
  QString displayString;
  PIRUDOuterMap::const_iterator outerIter;
  PIRUDInnerMap::const_iterator innerIter;

  PIRKeysetCollection::const_iterator i = keysetsInfo.begin();

  while (i != keysetsInfo.end())
  {
    // Create a widget for the keyset:
    makeID = i->second->getMake();
    name = i->second->getKeysetName();
    displayString = makeManager.getMakeString(makeID);
    displayString.append(" ");
    displayString.append(name);

    kwi = new PIRKeysetWidgetItem(displayString, name, i->first, makeID);

    outerIter = userData.find(makeID);
    if (outerIter != userData.end())
    {
      innerIter = outerIter->second.find(name);
      if (innerIter != outerIter->second.end())
      {
        // We have user data for this keyset!
        QString nick = innerIter->second.nickname;
        if (!nick.isEmpty())
        {
          kwi->setNickname(nick);

          displayString = nick;
          displayString.append(" (");
          displayString.append(kwi->text());
          displayString.append(")");
          kwi->setText(displayString);
        }

        // If this is a favorite, add it to favorites list:
        if (innerIter->second.favorite)
        {
          kwi->setFavorite(true);
          kwi->setTabBarName(innerIter->second.tabBarName);
          kwi->setPanelIndex(innerIter->second.panelIndex);
          fd->addItem(kwi);
        }
      }
    }

    skf->addWidgetItem(kwi);

    ++i;
  }
}


/*
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
*/

