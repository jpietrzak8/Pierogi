#ifndef PIRPREFERENCESFORM_H
#define PIRPREFERENCESFORM_H

#include <QWidget>

class MainWindow;

namespace Ui {
class PIRPreferencesForm;
}

class PIRPreferencesForm : public QWidget
{
  Q_OBJECT
  
public:
  explicit PIRPreferencesForm(QWidget *parent = 0);
  ~PIRPreferencesForm();
  
private slots:
  void on_altMainCheckBox_stateChanged(int arg1);

private:
  Ui::PIRPreferencesForm *ui;

  MainWindow *mainWindow;
};

#endif // PIRPREFERENCESFORM_H
