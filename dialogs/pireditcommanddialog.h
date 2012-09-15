#ifndef PIREDITCOMMANDDIALOG_H
#define PIREDITCOMMANDDIALOG_H

#include <QDialog>

class PIRMacroCommandItem;

namespace Ui {
class PIREditCommandDialog;
}

class PIREditCommandDialog : public QDialog
{
  Q_OBJECT
  
public:
  explicit PIREditCommandDialog(QWidget *parent = 0);
  ~PIREditCommandDialog();

  void setup(
    QString typeString,
    QString name);

signals:
  void deleteCommand();
  void moveCommandUp();
  void moveCommandDown();

private slots:
  void on_moveUpButton_clicked();
  void on_moveDownButton_clicked();
  void on_deleteButton_clicked();

private:
  Ui::PIREditCommandDialog *ui;
};

#endif // PIREDITCOMMANDDIALOG_H
