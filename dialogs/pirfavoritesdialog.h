#ifndef PIRFAVORITESDIALOG_H
#define PIRFAVORITESDIALOG_H

#include <QDialog>

#include "pirpanelnames.h"

class QListWidget;
class PIRKeysetWidgetItem;
class QListWidgetItem;
class MainWindow;

namespace Ui {
class PIRFavoritesDialog;
}

class PIRFavoritesDialog : public QDialog
{
  Q_OBJECT
  
public:
//  explicit PIRFavoritesDialog(QWidget *parent = 0);

  PIRFavoritesDialog(
    MainWindow *mw);

  ~PIRFavoritesDialog();

  QListWidget *getFavoritesListWidget();

  void addItem(
    PIRKeysetWidgetItem *item);

  int getCount();

  PIRKeysetWidgetItem *getItem(
    int index);

  void removeItem(
    unsigned int keysetID);

  void selectPrevFavKeyset();
  void selectNextFavKeyset();

  int selectFavorite(
    PIRKeysetWidgetItem *targetItem);

  void updateTabBarName(
    int favoritesIndex,
    PIRTabBarName name);

  void updatePanelIndex(
    int favoritesIndex,
    int panelIndex);

private slots:
  void on_favoritesListWidget_itemClicked(
    QListWidgetItem *item);
  
private:
  Ui::PIRFavoritesDialog *ui;

  MainWindow *mainWindow;
};

#endif // PIRFAVORITESDIALOG_H
