#ifndef PIRTABSCHOICEDIALOG_H
#define PIRTABSCHOICEDIALOG_H

#include <QDialog>

#include "pirpanelnames.h"

class QListWidgetItem;
class MainWindow;

namespace Ui {
class PIRTabsChoiceDialog;
}

class PIRTabsChoiceDialog : public QDialog
{
  Q_OBJECT
  
public:
//  explicit PIRTabsChoiceDialog(QWidget *parent = 0);
  PIRTabsChoiceDialog(MainWindow *mw);
  ~PIRTabsChoiceDialog();

  void switchToTabBar(
    PIRTabBarName name);
  
private slots:
  void on_tabsChoiceListWidget_itemClicked(QListWidgetItem *item);

private:
  Ui::PIRTabsChoiceDialog *ui;

  MainWindow *mainWindow;
};

#endif // PIRTABSCHOICEDIALOG_H
