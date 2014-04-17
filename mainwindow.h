//
// Mainwindow.h
//
// Copyright 2012, 2013 by John Pietrzak
//
// This file contains the main window declaration for Pierogi.
//
// Pierogi is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// Pierogi is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Pierogi; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>

#include "pirkeynames.h"
#include "pirmakenames.h"
#include "pirpanelnames.h"
#include "pirmodprobe.h"
#include "piracstateinfo.h"

class QListWidget;
class QListWidgetItem;
class QDialog;
class QKeyEvent;
class QComboBox;

//class PIRTabWidget;

class PIRSelectKeysetForm;
class PIRPowerSearchForm;
class PIRSelectDeviceForm;
class PIRPreferencesForm;
class PIRDocumentationForm;
class PIRAboutForm;
class PIRFavoritesDialog;
class PIRTabsChoiceDialog;
class PIRKeysetWidgetItem;
class PIRMacroPack;

class PIRKeysetManager;
class PIRPanelManager;
class PIRMacroManager;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  enum ScreenOrientation {
    ScreenOrientationLockPortrait,
    ScreenOrientationLockLandscape,
    ScreenOrientationAuto
  };

  explicit MainWindow(QWidget *parent = 0);
  virtual ~MainWindow();

  // Note that this will only have an effect on Symbian and Fremantle.
  void setOrientation(ScreenOrientation orientation);

  void showExpanded();

  bool startRepeating(
    PIRKeyName name);

  bool startRepeating(
    PIRKeyName name,
    unsigned int keysetID);

  bool startRepeating(
    PIRACStateInfo state,
    PIRKeyName name);

  void stopRepeating();

  // Favorites panel actions:
  void addToFavorites(
    PIRKeysetWidgetItem *kwi);

  void removeFromFavorites(
    unsigned int keysetID);

  void enableButtons();

  // Preferences actions:
  void useMainPanel();
  void useAltMainPanel();

  QString getCurrentMake();
  QString getCurrentName();
  QString getCurrentFullName();

  QString getKeysetMake(
    unsigned int id);

  QString getKeysetName(
    unsigned int id);

  QString getFullKeysetName(
    unsigned int id);

  unsigned int getCurrentKeyset()
  {
    return currentKeyset;
  }

  bool findKeysetID(
    QString make,
    QString name,
    unsigned int &id);

  void insertCornerButtons();
//  void disableUpdates();
//  void enableUpdates();
//  void clearTabs();

  void addTab(
    QWidget *page,
    QString label);

  void setupTabs(PIRTabBarName name);

  void setupFavoriteTabs(
    PIRTabBarName name,
    int panelIndex);

  bool selectNextKeyset();
  bool selectPrevKeyset();
  bool selectFirstKeyset();
  void openCurrentKeysetDialog();

  void updateKeysetSelection(
    unsigned int targetID);

  void updateFavoriteKeysetSelection(
    unsigned int targetID,
    int favoritesIndex,
//    PIRMakeName makeName,
    PIRTabBarName tabBarName,
    int panelIndex);

/*
  PIRMacroPack *getUserPack();
  PIRMacroPack *getMultitapPack();
*/

  bool loadNewMacros(
    QString filename);

  void populateMacroComboBox(
    QComboBox *cb);

  void runMacro(
    QString macroName);

  void abortMacro();

  bool hasMacroButton(
    unsigned int buttonID);

  QString getMacroButtonText(
    unsigned int buttonID);

  void executeMacroButton(
    unsigned int buttonID);

  void updateUserButtons(); // Should this be a slot?

  void storeMacros();

  void setMacroKbdFocus(
    int index);

  void setMacroBtnFocus(
    int index);

  void switchToTab(
    int tabNumber);

  void switchToNextTab();
  void switchToPrevTab();

  void handleKeypress(
    char key);

//  void handleKeyRelease(
//    char Key);

/*
  void gotoPreviousTabs();

  void gotoNextTabs();
*/
  void setCarrierFrequency(
    unsigned int freq);

  void setDutyCycle(
    unsigned int dc);

signals:
  void buttonPressed(
    unsigned int keysetID,
    PIRKeyName name);

  void buttonPressed(
    PIRACStateInfo state,
    unsigned int keysetID,
    PIRKeyName name);

  void buttonReleased();

  void contextChanged();

public slots:
  void receivedExternalWarning(
    const char *warning);

  void selectPrevFavKeyset();
  void selectNextFavKeyset();

  void keysetSelectionChanged(
    QListWidgetItem *item);

  void reportContextChange(
    int tabnum);

private slots:
  void on_actionSelectKeyset_triggered();
  void on_actionAutomatic_Keyset_Search_triggered();
  void on_actionBrowse_Device_List_triggered();
  void on_actionPreferences_triggered();
  void on_actionAbout_triggered();
  void on_actionDocumentation_triggered();

  // Internal actions:
  void finalCleanup();

private:
//  void keyPressEvent(
//    QKeyEvent *event);

//  void keyReleaseEvent(
//    QKeyEvent *event);

  void populateFavorites();

  Ui::MainWindow *ui;

//  PIRTabWidget *myTabWidget;

  PIRSelectKeysetForm *selectKeysetForm;
  PIRPowerSearchForm *powerSearchForm;
  PIRSelectDeviceForm *selectDeviceForm;
  PIRPreferencesForm *preferencesForm;
  PIRDocumentationForm *documentationForm;
  PIRAboutForm *aboutForm;
  PIRFavoritesDialog *favoritesDialog;
  PIRTabsChoiceDialog *tabsChoiceDialog;

  PIRKeysetManager *myKeysets;
  PIRPanelManager *myPanels;
  PIRMacroManager *myMacros;

  PIRTabBarName currentTabsName;
  int currentPanelIndex;
  int currentFavorite;

  unsigned int currentKeyset;

  PIRModprobe modprobeObj;
};


#endif // MAINWINDOW_H
