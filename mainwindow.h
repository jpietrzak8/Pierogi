#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>

#include "pirkeynames.h"
#include "pirpanelnames.h"
#include "pirmodprobe.h"

class QListWidget;
class QListWidgetItem;
class QDialog;
class QKeyEvent;

//class PIRTabWidget;

class PIRSelectKeysetForm;
class PIRSelectDeviceForm;
class PIRPreferencesForm;
class PIRDocumentationForm;
class PIRAboutForm;
class PIRFavoritesDialog;
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
  void disableUpdates();
  void enableUpdates();
  void clearTabs();
  void addTab(
    QWidget *page,
    QString label);
  void setupTabs(PIRTabBarName name);

  bool selectNextKeyset();
  bool selectPrevKeyset();
  bool selectFirstKeyset();
  void openCurrentKeysetDialog();

  void updateKeysetSelection(
    unsigned int targetID);

  PIRMacroPack *getUserPack();
  PIRMacroPack *getMultitapPack();

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

  void handleKeypress(
    char key);

//  void handleKeyRelease(
//    char Key);

  void gotoPreviousTabs();

  void gotoNextTabs();

signals:
  void buttonPressed(
    unsigned int keysetID,
    PIRKeyName name);

  void buttonReleased();

public slots:
  void receivedExternalWarning(
    const char *warning);

  void selectPrevFavKeyset();
  void selectNextFavKeyset();

  void keysetSelectionChanged(
    QListWidgetItem *item);

private slots:
  void on_actionSelectKeyset_triggered();
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
  PIRSelectDeviceForm *selectDeviceForm;
  PIRPreferencesForm *preferencesForm;
  PIRDocumentationForm *documentationForm;
  PIRAboutForm *aboutForm;
  PIRFavoritesDialog *favoritesDialog;

  PIRKeysetManager *myKeysets;
  PIRPanelManager *myPanels;
  PIRMacroManager *myMacros;

  unsigned int currentKeyset;

  PIRModprobe modprobeObj;
};


#endif // MAINWINDOW_H
