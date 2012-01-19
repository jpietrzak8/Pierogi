# Add files and directories to ship with the application 
# by adapting the examples below.
# file1.source = myfile
# dir1.source = mydir
#DEPLOYMENTFOLDERS = # file1 dir1
sudoers_stuff.source = pierogi.sudoers
sudoers_stuff.target = ../../etc/sudoers.d
loadModule.source = loadRX51Module unloadRX51Module
loadModule.target = bin
DEPLOYMENTFOLDERS = sudoers_stuff loadModule

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
    necprotocol.cpp \
    rc5protocol.cpp \
    pirmakenames.cpp \
    pirdocumentationform.cpp \
    piraboutform.cpp \
    pirexception.cpp \
    pirkeysetwidgetitem.cpp \
    pirprotocol.cpp \
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
    keysets/yamaha.cpp
HEADERS += mainwindow.h \
    pirkeynames.h \
    necprotocol.h \
    rc5protocol.h \
    pirmakenames.h \
    pirdocumentationform.h \
    piraboutform.h \
    pirexception.h \
    pirkeysetwidgetitem.h \
    pirprotocol.h \
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
    keysets/yamaha.h
FORMS += mainwindow.ui \
    pirdocumentationform.ui \
    piraboutform.ui \
    pirselectkeysetform.ui

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
    pierogi.sudoers \
    qtc_packaging/debian_fremantle/postinst \
    www/index.html \
    www/FavoritesTab.png \
    www/KeypadTab.png \
    www/MainTab.png \
    www/MediaTab.png \
    www/MenuTab.png \
    www/MiscTab.png \
    www/PierogiIcon.png \
    www/SelectKeysetWindow.png \
    www/UtilityTab.png \
    qtc_packaging/debian_fremantle/postrm

RESOURCES += \
    PierogiResources.qrc





































