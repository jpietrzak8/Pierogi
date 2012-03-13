#ifndef PIRSELECTKEYSETFORM_H
#define PIRSELECTKEYSETFORM_H

#include <QWidget>
#include <QString>

#include "pirmakenames.h"

class QListWidget;
class PIRKeysetWidgetItem;
class QKeyEvent;
//class PIRSearchStringDialog;

namespace Ui {
class PIRSelectKeysetForm;
}

class PIRSelectKeysetForm : public QWidget
{
  Q_OBJECT
  
public:
  explicit PIRSelectKeysetForm(QWidget *parent = 0);
  ~PIRSelectKeysetForm();

/*
  void addNameToList(
    QString name,
    unsigned int index,
    PIRMakeName make);
*/

  void addWidgetItem(
    PIRKeysetWidgetItem *kwi);

  // This is a bit of a hack, but not sure how to create a connection otherwise.
  QListWidget *getKeysetListWidget();

protected:
  void keyPressEvent(
    QKeyEvent *event);

private slots:
  void filterListByMake(
    int make);

  void filterListByString(
    QString string);
  
  void on_searchStringLineEdit_textChanged(const QString &arg1);
  void on_ssClosePushButton_clicked();

private:
  void refilterList();

  Ui::PIRSelectKeysetForm *ui;

  PIRMakeName currentMake;
  QString searchString;
};

#endif // PIRSELECTKEYSETFORM_H
