#ifndef PIRSTATEFULACFORM_H
#define PIRSTATEFULACFORM_H

#include <QWidget>

namespace Ui {
class PIRStatefulACForm;
}

class PIRStatefulACForm : public QWidget
{
  Q_OBJECT
  
public:
  explicit PIRStatefulACForm(QWidget *parent = 0);
  ~PIRStatefulACForm();
  
private:
  Ui::PIRStatefulACForm *ui;
};

#endif // PIRSTATEFULACFORM_H
