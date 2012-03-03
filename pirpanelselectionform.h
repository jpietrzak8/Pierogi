#ifndef PIRPANELSELECTIONFORM_H
#define PIRPANELSELECTIONFORM_H

#include <QWidget>
#include "pirpanelnames.h"

class MainWindow;

namespace Ui {
class PIRPanelSelectionForm;
}

class PIRPanelSelectionForm : public QWidget
{
  Q_OBJECT
  
public:
  explicit PIRPanelSelectionForm(QWidget *parent = 0);
//  PIRPanelSelectionForm(MainWindow *mw);
  ~PIRPanelSelectionForm();
  
private slots:
  void on_mainCheckBox_stateChanged(int arg1);
  void on_utilityCheckBox_stateChanged(int arg1);
  void on_keypadCheckBox_stateChanged(int arg1);
  void on_menuCheckBox_stateChanged(int arg1);
  void on_mediaCheckBox_stateChanged(int arg1);
  void on_media2CheckBox_stateChanged(int arg1);
  void on_recordCheckBox_stateChanged(int arg1);
  void on_tvCheckBox_stateChanged(int arg1);
  void on_inputCheckBox_stateChanged(int arg1);
  void on_adjustCheckBox_stateChanged(int arg1);
  void on_acCheckBox_stateChanged(int arg1);
  void on_favoritesCheckBox_stateChanged(int arg1);

private:
  Ui::PIRPanelSelectionForm *ui;

  MainWindow *mainWindow;
};

#endif // PIRPANELSELECTIONFORM_H
