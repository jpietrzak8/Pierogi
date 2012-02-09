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
    pirsecondaryform.cpp \
    protocols/rcaprotocol.cpp \
    keysets/acer.cpp \
    keysets/aiwa.cpp \
    protocols/aiwaprotocol.cpp \
    protocols/kaseikyoprotocol.cpp \
    keysets/bose.cpp \
    protocols/boseprotocol.cpp
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
    pirsecondaryform.h \
    keysets/yamaha.h \
    protocols/rcaprotocol.h \
    keysets/acer.h \
    keysets/aiwa.h \
    protocols/aiwaprotocol.h \
    protocols/kaseikyoprotocol.h \
    protocols/boseprotocol.h \
    keysets/bose.h
FORMS += mainwindow.ui \
    pirdocumentationform.ui \
    piraboutform.ui \
    pirselectkeysetform.ui \
    pirsecondaryform.ui

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
    www/InputTab.png

RESOURCES += \
    PierogiResources.qrc





































