#ifndef PIRPREFERENCESFORM_H
#define PIRPREFERENCESFORM_H

#include <QWidget>

class MainWindow;
class PIRKeysetManager;
class QComboBox;

namespace Ui {
class PIRPreferencesForm;
}

class PIRPreferencesForm : public QWidget
{
  Q_OBJECT
  
public:
  PIRPreferencesForm(
    QWidget *parent,
    const PIRKeysetManager *keysetManager);

  ~PIRPreferencesForm();

  unsigned int getDefaultKeyset()
  {
    return defaultKeyset;
  }

  bool defaultControlsVolume()
  {
    return useDefaultForVolume;
  }
  
private slots:
  void on_setDefaultButton_clicked();
  void on_clearDefaultButton_clicked();
  void on_useDefaultCheckBox_stateChanged(int arg1);
  void on_altMainCheckBox_stateChanged(int arg1);
  void on_macroKbdComboBox_activated(int index);
  void on_macroBtnComboBox_activated(int index);

private:
  void setupMacroComboBox(
    QComboBox *cb);

  Ui::PIRPreferencesForm *ui;

  MainWindow *mainWindow;

  unsigned int defaultKeyset;
  bool useDefaultForVolume;
};

#endif // PIRPREFERENCESFORM_H
