#ifndef PIRSELECTKEYSETFORM_H
#define PIRSELECTKEYSETFORM_H

#include <QWidget>
#include <QListWidget>
#include <QString>

#include "pirmakenames.h"
#include "pirdevicetypenames.h"
#include "pirkeysetwidgetitem.h"

namespace Ui {
class PIRSelectKeysetForm;
}

class PIRSelectKeysetForm : public QWidget
{
  Q_OBJECT
  
public:
  explicit PIRSelectKeysetForm(QWidget *parent = 0);
  ~PIRSelectKeysetForm();

  void addNameToList(
    QString name,
    unsigned int index,
    PIRMakeName make);

  void addWidgetItem(
    PIRKeysetWidgetItem *kwi);

  // This is a bit of a hack, but not sure how to create a connection otherwise.
  QListWidget *getKeysetListWidget();

private slots:
  void filterListByMake(
    int make);

  void filterListByDeviceType(
    int deviceType);
  
private:
  void refilterList();

  Ui::PIRSelectKeysetForm *ui;

  PIRMakeName currentMake;
  PIRDeviceTypeName currentDevice;
};

#endif // PIRSELECTKEYSETFORM_H