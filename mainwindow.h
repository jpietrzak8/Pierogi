#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>

#include "pirkeynames.h"
#include "pirpanelnames.h"
#include "pirmodprobe.h"

class QListWidget;
class QListWidgetItem;
class PIRSelectKeysetForm;
class PIRSelectDeviceForm;
class PIRPanelSelectionForm;
class PIRPreferencesForm;
class PIRDocumentationForm;
class PIRAboutForm;
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

  void stopRepeating();

  void selectPanel(
    int index);

  void managePanel(
    PIRPanelName name,
    int state);

  void insertPanel(
    int index,
    QWidget *panel,
    const QString &displayName);

  void removePanel(
    int index,
    QWidget *panel);

  // Favorites panel actions:
  void addCurrentKeyset(
    QListWidget *qlw);

  void removeFavoriteKeyset(
    QListWidget *qlw);

  void enableButtons();

  // Preferences actions:
  void useMainPanel();
  void useAltMainPanel();

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
  void on_actionArrange_Button_Panels_triggered();
  void on_actionPreferences_triggered();
  void on_actionAbout_triggered();
  void on_actionDocumentation_triggered();

  void on_prevPanelButton_clicked();
  void on_nextPanelButton_clicked();
  void on_selectPanelComboBox_currentIndexChanged(int index);

  // Internal actions:
  void finalCleanup();

private:
  void populateFavorites();
//  void setupTabs();

  Ui::MainWindow *ui;

  PIRSelectKeysetForm *selectKeysetForm;
  PIRSelectDeviceForm *selectDeviceForm;
  PIRPanelSelectionForm *panelSelectionForm;
  PIRPreferencesForm *preferencesForm;
  PIRDocumentationForm *documentationForm;
  PIRAboutForm *aboutForm;

  PIRKeysetManager *myKeysets;
  PIRPanelManager *myPanels;

  unsigned int currentKeyset;

  PIRModprobe modprobeObj;
};


#endif // MAINWINDOW_H
