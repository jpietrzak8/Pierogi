#ifndef PIRADVANCEDFORM_H
#define PIRADVANCEDFORM_H

#include <QWidget>

class PIRKeysetManager;

namespace Ui {
class PIRAdvancedForm;
}

class PIRAdvancedForm : public QWidget
{
  Q_OBJECT
  
public:
  PIRAdvancedForm();

  ~PIRAdvancedForm();

  void setupForm(
    PIRKeysetManager *pkm,
    unsigned int id);

private slots:
  void on_carrierFrequencySpinBox_valueChanged(int arg1);

  void on_dutyCycleSpinBox_valueChanged(int arg1);

private:
  Ui::PIRAdvancedForm *ui;

  PIRKeysetManager *keysetManager;
  unsigned int keysetID;
};

#endif // PIRADVANCEDFORM_H
