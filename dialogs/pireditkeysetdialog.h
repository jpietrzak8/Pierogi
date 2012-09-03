#ifndef PIREDITKEYSETDIALOG_H
#define PIREDITKEYSETDIALOG_H

#include <QDialog>

class PIRKeysetWidgetItem;
class MainWindow;

namespace Ui {
class PIREditKeysetDialog;
}

class PIREditKeysetDialog : public QDialog
{
  Q_OBJECT
  
public:
//  explicit PIREditKeysetDialog(QWidget *parent = 0);

  PIREditKeysetDialog(
    MainWindow *mw);

  ~PIREditKeysetDialog();

  void setupDialog(
    PIRKeysetWidgetItem *kwi);
  
private slots:
  void enactChanges();

private:
  void updateQSettingsNickname();
  void removeQSettingsNickname();

  Ui::PIREditKeysetDialog *ui;

  MainWindow *mainWindow;
  PIRKeysetWidgetItem *keysetItem;
};

#endif // PIREDITKEYSETDIALOG_H
