#ifndef PIRCREATECOMMANDDIALOG_H
#define PIRCREATECOMMANDDIALOG_H

#include <QDialog>

#include "pirkeynames.h"

class QComboBox;

enum CommandType
{
  No_Command,
  Key_Command,
  Keyset_Command,
  Pause_Command
};

namespace Ui {
class PIRCreateCommandDialog;
}

class PIRCreateCommandDialog : public QDialog
{
  Q_OBJECT
  
public:
//  explicit PIRCreateCommandDialog(QWidget *parent = 0);

  PIRCreateCommandDialog();

  ~PIRCreateCommandDialog();

  QComboBox *getKeysetComboBox();

  CommandType getCommandType();

  QString getKeysetName();

  unsigned int getKeysetID();

  PIRKeyName getKeyName();

  unsigned int getTimeToWait();

  void init();
  
private:
  void setupPowerKeys(
    QComboBox *cb);

  void setupNumericKeys(
    QComboBox *cb);

  void setupChannelKeys(
    QComboBox *cb);

  void setupVolumeKeys(
    QComboBox *cb);

  void setupMenuKeys(
    QComboBox *cb);

  void setupMediaKeys(
    QComboBox *cb);

  void setupInputKeys(
    QComboBox *cb);

  void setupKey(
    QComboBox *cb,
    PIRKeyName keyName);

  Ui::PIRCreateCommandDialog *ui;
};

#endif // PIRCREATECOMMANDDIALOG_H
