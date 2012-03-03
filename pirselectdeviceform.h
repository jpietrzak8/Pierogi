#ifndef PIRSELECTDEVICEFORM_H
#define PIRSELECTDEVICEFORM_H

#include <QWidget>

#include "pirmakenames.h"
#include "pirdevicetypenames.h"
#include "pirdeviceinfo.h"

class PIRKeysetWidgetItem;
class QListWidget;

namespace Ui {
class PIRSelectDeviceForm;
}

class PIRSelectDeviceForm : public QWidget
{
  Q_OBJECT
  
public:
  explicit PIRSelectDeviceForm(
    QWidget *parent = 0);

  ~PIRSelectDeviceForm();

/*
  void addNameToList(
    QString name,
    unsigned int index,
    PIRMakeName make);
*/

  void addWidgetItem(
    PIRKeysetWidgetItem *kwi);

  // This is a bit of a hack, but not sure how to create a connection otherwise.
  QListWidget *getDeviceListWidget();

private slots:
  void filterListByMake(
    int make);

  void filterListByDeviceType(
    int deviceType);
 
private:
  void refilterList();

  Ui::PIRSelectDeviceForm *ui;

  PIRMakeName currentMake;
  PIRDeviceTypeName currentDevice;
};

#endif // PIRSELECTDEVICEFORM_H
