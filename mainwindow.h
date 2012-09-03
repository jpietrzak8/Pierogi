#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>

#include "pirkeynames.h"
#include "pirpanelnames.h"
#include "pirmodprobe.h"

class QListWidget;
class QListWidgetItem;
class QDialog;

class PIRSelectKeysetForm;
class PIRSelectDeviceForm;
class PIRPreferencesForm;
class PIRDocumentationForm;
class PIRAboutForm;
class PIRFavoritesDialog;
class PIRKeysetWidgetItem;

class PIRKeysetManager;
class PIRPanelManager;

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

  void startRepeating(
    PIRKeyName name);

  void startRepeating(
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

  unsigned int getCurrentKeyset()
  {
    return currentKeyset;
  }

  void insertCornerButtons();
  void disableUpdates();
  void enableUpdates();
  void clearTabs();
  void addTab(
    QWidget *page,
    QString label);
  void setupTabs(PIRTabBarName name);

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
  void on_actionSelect_Device_By_Name_triggered();
  void on_actionPreferences_triggered();
  void on_actionAbout_triggered();
  void on_actionDocumentation_triggered();

  // Internal actions:
  void finalCleanup();

private:
  void populateFavorites();

  Ui::MainWindow *ui;

  PIRSelectKeysetForm *selectKeysetForm;
  PIRSelectDeviceForm *selectDeviceForm;
  PIRPreferencesForm *preferencesForm;
  PIRDocumentationForm *documentationForm;
  PIRAboutForm *aboutForm;
  PIRFavoritesDialog *favoritesDialog;

  PIRKeysetManager *myKeysets;
  PIRPanelManager *myPanels;

  unsigned int currentKeyset;

  PIRModprobe modprobeObj;
};


#endif // MAINWINDOW_H
