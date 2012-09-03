#ifndef PIRVCRFORM_H
#define PIRVCRFORM_H

#include <QWidget>

namespace Ui {
class PIRVCRForm;
}

class PIRVCRForm : public QWidget
{
  Q_OBJECT
  
public:
  explicit PIRVCRForm(QWidget *parent = 0);
  ~PIRVCRForm();
  
private:
  Ui::PIRVCRForm *ui;
};

#endif // PIRVCRFORM_H
