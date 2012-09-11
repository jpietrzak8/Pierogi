# Add files and directories to ship with the application 
# by adapting the examples below.
# file1.source = myfile
# dir1.source = mydir
#DEPLOYMENTFOLDERS = # file1 dir1
loadModule.source = loadRX51Module unloadRX51Module
loadModule.target = bin
DEPLOYMENTFOLDERS = loadModule

#symbian:TARGET.UID3 = 0xE0C0A793

# Smart Installer package's UID
# This UID is from the protected range 
# and therefore the package will fail to install if self-signed
# By default qmake uses the unprotected range value if unprotected UID is defined for the application
# and 0x2002CCCF value if protected UID is given to the application
#symbian:DEPLOYMENT.installer_header = 0x2002CCCF

# Allow network access on Symbian
#symbian:TARGET.CAPABILITY += NetworkServices

# If your application uses the Qt Mobility libraries, uncomment
# the following lines and add the respective components to the 
# MOBILITY variable. 
# CONFIG += mobility
# MOBILITY +=

QT += maemo5

SOURCES += main.cpp mainwindow.cpp \
    pirmakenames.cpp \
    pirdocumentationform.cpp \
    piraboutform.cpp \
    pirexception.cpp \
    pirkeysetwidgetitem.cpp \
    keysets/apple.cpp \
    keysets/ei.cpp \
    keysets/goldstar.cpp \
    keysets/hauppauge.cpp \
    keysets/lg.cpp \
    keysets/nokia.cpp \
    keysets/panasonic.cpp \
    keysets/samsung.cpp \
    keysets/sanyo.cpp \
    keysets/sharp.cpp \
    keysets/sony.cpp \
    keysets/toshiba.cpp \
    keysets/zenith.cpp \
    pirkeysetmetadata.cpp \
    pirkeysetmanager.cpp \
    keysets/rca.cpp \
    keysets/westinghouse.cpp \
    keysets/mitsubishi.cpp \
    pirmodprobe.cpp \
    keysets/jvc.cpp \
    pirselectkeysetform.cpp \
    pirrx51hardware.cpp \
    pirdevicetypenames.cpp \
    keysets/raite.cpp \
    keysets/sagem.cpp \
    keysets/yamaha.cpp \
    keysets/hitachi.cpp \
    keysets/denon.cpp \
    keysets/pinnacle.cpp \
    keysets/magnavox.cpp \
    keysets/philips.cpp \
    keysets/tivo.cpp \
    keysets/elgato.cpp \
    protocols/jvcprotocol.cpp \
    protocols/necprotocol.cpp \
    protocols/pirprotocol.cpp \
    protocols/rc5protocol.cpp \
    protocols/rc6protocol.cpp \
    protocols/sharpprotocol.cpp \
    protocols/sircprotocol.cpp \
    protocols/pioneerprotocol.cpp \
    protocols/lircprotocol.cpp \
    protocols/samsungprotocol.cpp \
    keysets/pioneer.cpp \
    protocols/spaceprotocol.cpp \
    protocols/rcaprotocol.cpp \
    keysets/acer.cpp \
    keysets/aiwa.cpp \
    protocols/aiwaprotocol.cpp \
    protocols/kaseikyoprotocol.cpp \
    keysets/bose.cpp \
    protocols/boseprotocol.cpp \
    keysets/mce.cpp \
    protocols/mceprotocol.cpp \
    keysets/philco.cpp \
    keysets/roku.cpp \
    keysets/admiral.cpp \
    keysets/daewoo.cpp \
    protocols/daewooprotocol.cpp \
    keysets/grundig.cpp \
    keysets/topfield.cpp \
    keysets/logitech.cpp \
    protocols/necxprotocol.cpp \
    sideshotleftform.cpp \
    keysets/wd.cpp \
    keysets/saba.cpp \
    keysets/sky.cpp \
    protocols/rc6skyprotocol.cpp \
    protocols/thomsonprotocol.cpp \
    keysets/digitalstream.cpp \
    pirapplication.cpp \
    keysets/emerson.cpp \
    keysets/dish.cpp \
    keysets/fortec.cpp \
    keysets/homecast.cpp \
    protocols/dishprotocol.cpp \
    keysets/beko.cpp \
    keysets/cambridge.cpp \
    keysets/haier.cpp \
    keysets/kenwood.cpp \
    keysets/directv.cpp \
    protocols/directvprotocol.cpp \
    keysets/huawei.cpp \
    keysets/onida.cpp \
    keysets/vestel.cpp \
    keysets/virgin.cpp \
    keysets/vizio.cpp \
    keysets/hp.cpp \
    keysets/motorola.cpp \
    protocols/giprotocol.cpp \
    keysets/bush.cpp \
    keysets/canon.cpp \
    keysets/epson.cpp \
    keysets/humax.cpp \
    keysets/technics.cpp \
    keysets/united.cpp \
    keysets/foxtel.cpp \
    keysets/nad.cpp \
    keysets/universum.cpp \
    keysets/hyundai.cpp \
    pirselectdeviceform.cpp \
    keysets/harmankardon.cpp \
    forms/piradjustform.cpp \
    forms/pirairconditionerform.cpp \
    forms/pirinputform.cpp \
    forms/pirmedia2form.cpp \
    forms/pirtvform.cpp \
    forms/pirmainform.cpp \
    forms/pirutilityform.cpp \
    forms/pirkeypadform.cpp \
    forms/pirmenuform.cpp \
    forms/pirmediaform.cpp \
    pirpanelmanager.cpp \
    protocols/nokia32protocol.cpp \
    protocols/kathreinprotocol.cpp \
    keysets/aoc.cpp \
    keysets/arcam.cpp \
    keysets/dell.cpp \
    keysets/dse.cpp \
    keysets/dynex.cpp \
    keysets/kathrein.cpp \
    keysets/starsat.cpp \
    keysets/viewsat.cpp \
    pirdeviceinfo.cpp \
    keysets/kaon.cpp \
    forms/pirrecordform.cpp \
    keysets/qnap.cpp \
    keysets/compro.cpp \
    protocols/xmpprotocol.cpp \
    keysets/dreambox.cpp \
    keysets/magnum.cpp \
    keysets/telenet.cpp \
    keysets/thomson.cpp \
    keysets/genius.cpp \
    forms/piraltmainform.cpp \
    pirpreferencesform.cpp \
    keysets/xcruiser.cpp \
    keysets/benq.cpp \
    keysets/octagon.cpp \
    forms/pirmacroform.cpp \
    dialogs/pirtextentrydialog.cpp \
    keysets/lexuz.cpp \
    protocols/protonprotocol.cpp \
    keysets/gadmei.cpp \
    keysets/onkyo.cpp \
    protocols/panasonicoldprotocol.cpp \
    keysets/orion.cpp \
    keysets/cisco.cpp \
    keysets/loewe.cpp \
    keysets/telefunken.cpp \
    protocols/paceprotocol.cpp \
    dialogs/pirtabschoicedialog.cpp \
    dialogs/pirtabswidgetitem.cpp \
    keysets/technisat.cpp \
    keysets/strong.cpp \
    keysets/proview.cpp \
    dialogs/pireditkeysetdialog.cpp \
    keysets/adb.cpp \
    keysets/triax.cpp \
    keysets/sylvania.cpp \
    keysets/anitech.cpp \
    keysets/viewsonic.cpp \
    forms/pirvcrform.cpp \
    forms/pirvideodiscform.cpp \
    forms/piraudiodeviceform.cpp \
    dialogs/pirfavoritesdialog.cpp \
    keysets/medion.cpp \
    keysets/blaupunkt.cpp \
    keysets/lifetec.cpp \
    keysets/irobot.cpp \
    protocols/irobotprotocol.cpp \
    forms/pirroombaform.cpp \
    forms/pirstatefulacform.cpp \
    forms/pircameraform.cpp \
    keysets/nikon.cpp \
    keysets/olympus.cpp \
    keysets/pentax.cpp \
    forms/pirpowersearchform.cpp \
    keysets/deutschetelekom.cpp \
    keysets/goodmans.cpp \
    keysets/emtec.cpp \
    protocols/tdcprotocol.cpp \
    dialogs/pirselectmacrodialog.cpp \
    macros/pirmacro.cpp \
    macros/pirmacrocommanditem.cpp \
    macros/pirmacropack.cpp \
    macros/pirreversemultitap.cpp \
    pirkeynames.cpp \
    dialogs/pircreatecommanddialog.cpp \
    keysets/creative.cpp \
    keysets/crown.cpp
HEADERS += mainwindow.h \
    pirkeynames.h \
    pirmakenames.h \
    pirdocumentationform.h \
    piraboutform.h \
    pirexception.h \
    pirkeysetwidgetitem.h \
    keysets/apple.h \
    keysets/ei.h \
    keysets/goldstar.h \
    keysets/hauppauge.h \
    keysets/lg.h \
    keysets/nokia.h \
    keysets/panasonic.h \
    keysets/samsung.h \
    keysets/sanyo.h \
    keysets/sharp.h \
    keysets/sony.h \
    keysets/toshiba.h \
    keysets/zenith.h \
    pirkeysetmetadata.h \
    pirkeysetmanager.h \
    keysets/rca.h \
    keysets/westinghouse.h \
    keysets/mitsubishi.h \
    pirmodprobe.h \
    keysets/jvc.h \
    pirselectkeysetform.h \
    pirrx51hardware.h \
    pirdevicetypenames.h \
    keysets/raite.h \
    keysets/sagem.h \
    keysets/hitachi.h \
    keysets/denon.h \
    keysets/pinnacle.h \
    keysets/magnavox.h \
    keysets/philips.h \
    keysets/tivo.h \
    keysets/elgato.h \
    protocols/jvcprotocol.h \
    protocols/necprotocol.h \
    protocols/pirprotocol.h \
    protocols/rc5protocol.h \
    protocols/rc6protocol.h \
    protocols/sharpprotocol.h \
    protocols/sircprotocol.h \
    protocols/pioneerprotocol.h \
    protocols/lircprotocol.h \
    protocols/samsungprotocol.h \
    keysets/pioneer.h \
    protocols/spaceprotocol.h \
    keysets/yamaha.h \
    protocols/rcaprotocol.h \
    keysets/acer.h \
    keysets/aiwa.h \
    protocols/aiwaprotocol.h \
    protocols/kaseikyoprotocol.h \
    protocols/boseprotocol.h \
    keysets/bose.h \
    keysets/mce.h \
    protocols/mceprotocol.h \
    keysets/philco.h \
    keysets/roku.h \
    keysets/admiral.h \
    keysets/daewoo.h \
    protocols/daewooprotocol.h \
    keysets/grundig.h \
    keysets/topfield.h \
    keysets/logitech.h \
    protocols/necxprotocol.h \
    sideshotleftform.h \
    keysets/wd.h \
    keysets/saba.h \
    keysets/sky.h \
    protocols/rc6skyprotocol.h \
    protocols/thomsonprotocol.h \
    keysets/digitalstream.h \
    pirapplication.h \
    keysets/emerson.h \
    keysets/dish.h \
    keysets/fortec.h \
    keysets/homecast.h \
    protocols/dishprotocol.h \
    keysets/beko.h \
    keysets/cambridge.h \
    keysets/haier.h \
    keysets/kenwood.h \
    keysets/directv.h \
    protocols/directvprotocol.h \
    keysets/huawei.h \
    keysets/onida.h \
    keysets/vestel.h \
    keysets/virgin.h \
    keysets/vizio.h \
    keysets/hp.h \
    keysets/motorola.h \
    protocols/giprotocol.h \
    keysets/bush.h \
    keysets/canon.h \
    keysets/epson.h \
    keysets/humax.h \
    keysets/technics.h \
    keysets/united.h \
    keysets/foxtel.h \
    keysets/nad.h \
    keysets/universum.h \
    keysets/hyundai.h \
    pirselectdeviceform.h \
    keysets/harmankardon.h \
    forms/piradjustform.h \
    forms/pirairconditionerform.h \
    forms/pirinputform.h \
    forms/pirmedia2form.h \
    forms/pirtvform.h \
    forms/pirmainform.h \
    forms/pirutilityform.h \
    forms/pirkeypadform.h \
    forms/pirmenuform.h \
    forms/pirmediaform.h \
    pirpanelnames.h \
    pirpanelmanager.h \
    protocols/nokia32protocol.h \
    protocols/kathreinprotocol.h \
    keysets/aoc.h \
    keysets/arcam.h \
    keysets/dell.h \
    keysets/dse.h \
    keysets/dynex.h \
    keysets/kathrein.h \
    keysets/starsat.h \
    keysets/viewsat.h \
    keysets/kaon.h \
    pirdeviceinfo.h \
    forms/pirrecordform.h \
    keysets/qnap.h \
    keysets/compro.h \
    protocols/xmpprotocol.h \
    keysets/dreambox.h \
    keysets/magnum.h \
    keysets/telenet.h \
    keysets/thomson.h \
    keysets/genius.h \
    forms/piraltmainform.h \
    pirpreferencesform.h \
    keysets/xcruiser.h \
    keysets/benq.h \
    keysets/octagon.h \
    forms/pirmacroform.h \
    dialogs/pirtextentrydialog.h \
    keysets/lexuz.h \
    protocols/protonprotocol.h \
    keysets/gadmei.h \
    keysets/onkyo.h \
    protocols/panasonicoldprotocol.h \
    keysets/orion.h \
    keysets/cisco.h \
    keysets/loewe.h \
    keysets/telefunken.h \
    protocols/paceprotocol.h \
    dialogs/pirtabschoicedialog.h \
    dialogs/pirtabswidgetitem.h \
    keysets/technisat.h \
    keysets/strong.h \
    keysets/proview.h \
    dialogs/pireditkeysetdialog.h \
    keysets/adb.h \
    keysets/sylvania.h \
    keysets/triax.h \
    keysets/anitech.h \
    keysets/viewsonic.h \
    forms/pirvcrform.h \
    forms/pirvideodiscform.h \
    forms/piraudiodeviceform.h \
    dialogs/pirfavoritesdialog.h \
    keysets/medion.h \
    keysets/blaupunkt.h \
    keysets/lifetec.h \
    keysets/irobot.h \
    protocols/irobotprotocol.h \
    forms/pirroombaform.h \
    forms/pirstatefulacform.h \
    forms/pircameraform.h \
    keysets/nikon.h \
    keysets/olympus.h \
    keysets/pentax.h \
    forms/pirpowersearchform.h \
    keysets/deutschetelekom.h \
    keysets/goodmans.h \
    keysets/emtec.h \
    protocols/tdcprotocol.h \
    dialogs/pirselectmacrodialog.h \
    macros/pirmacro.h \
    macros/pirmacrocommanditem.h \
    macros/pirmacropack.h \
    macros/pirreversemultitap.h \
    dialogs/pircreatecommanddialog.h \
    keysets/creative.h \
    keysets/crown.h
FORMS += mainwindow.ui \
    pirdocumentationform.ui \
    piraboutform.ui \
    pirselectkeysetform.ui \
    sideshotleftform.ui \
    pirselectdeviceform.ui \
    forms/piradjustform.ui \
    forms/pirairconditionerform.ui \
    forms/pirinputform.ui \
    forms/pirmedia2form.ui \
    forms/pirtvform.ui \
    forms/pirmainform.ui \
    forms/pirutilityform.ui \
    forms/pirkeypadform.ui \
    forms/pirmenuform.ui \
    forms/pirmediaform.ui \
    forms/pirrecordform.ui \
    forms/piraltmainform.ui \
    pirpreferencesform.ui \
    forms/pirmacroform.ui \
    dialogs/pirtextentrydialog.ui \
    dialogs/pirtabschoicedialog.ui \
    dialogs/pireditkeysetdialog.ui \
    forms/pirvcrform.ui \
    forms/pirvideodiscform.ui \
    forms/piraudiodeviceform.ui \
    dialogs/pirfavoritesdialog.ui \
    forms/pirroombaform.ui \
    forms/pirstatefulacform.ui \
    forms/pircameraform.ui \
    forms/pirpowersearchform.ui \
    dialogs/pirselectmacrodialog.ui \
    dialogs/pircreatecommanddialog.ui

# Please do not modify the following two lines. Required for deployment.
include(deployment.pri)
qtcAddDeployment()

OTHER_FILES += \
    qtc_packaging/debian_fremantle/rules \
    qtc_packaging/debian_fremantle/README \
    qtc_packaging/debian_fremantle/copyright \
    qtc_packaging/debian_fremantle/control \
    qtc_packaging/debian_fremantle/compat \
    qtc_packaging/debian_fremantle/changelog \
    icons/black/sound_high_icon&48.png \
    icons/arrow_bottom_icon&48.png \
    icons/arrow_left_icon&48.png \
    icons/arrow_right_icon&48.png \
    icons/arrow_top_icon&48.png \
    icons/blue_square.png \
    icons/br_up_icon&48.png \
    icons/clock_icon&48.png \
    icons/dash.png \
    icons/eject_icon&48.png \
    icons/fastforward_next_icon&48.png \
    icons/green_square.png \
    icons/on-off_icon&48.png \
    icons/PierogiIcon.png \
    icons/playback_ff_icon&48.png \
    icons/playback_next_icon&48.png \
    icons/playback_pause_icon&48.png \
    icons/playback_play_icon&48.png \
    icons/playback_prev_icon&48.png \
    icons/playback_rew_icon&48.png \
    icons/playback_stop_icon&48.png \
    icons/red_record_icon.png \
    icons/red_square.png \
    icons/redo_icon&48.png \
    icons/rewind_previous_icon&48.png \
    icons/sound_high_icon&48.png \
    icons/sound_low_icon&48.png \
    icons/sound_mute_icon&48.png \
    icons/undo_icon&48.png \
    icons/yellow_square.png \
    doc/about.html \
    doc/documentation.html \
    qtc_packaging/debian_fremantle/rules \
    qtc_packaging/debian_fremantle/README \
    qtc_packaging/debian_fremantle/copyright \
    qtc_packaging/debian_fremantle/control \
    qtc_packaging/debian_fremantle/compat \
    qtc_packaging/debian_fremantle/changelog \
    qtc_packaging/debian_fremantle/postinst \
    www/index.html \
    www/KeypadTab.png \
    www/MainTab.png \
    www/MediaTab.png \
    www/MenuTab.png \
    www/PierogiIcon.png \
    www/SelectKeysetWindow.png \
    www/UtilityTab.png \
    www/FavoriteTab.png \
    www/Media2Tab.png \
    www/TVTab.png \
    www/PierogiIcon.png \
    www/AdjustTab.png \
    www/InputTab.png \
    qtc_packaging/debian_fremantle/postrm \
    icons/red_pause.png \
    icons/delete_icon&48.png \
    icons/align_just_icon&32.png \
    icons/folder_plus_icon&32.png

RESOURCES += \
    PierogiResources.qrc





































