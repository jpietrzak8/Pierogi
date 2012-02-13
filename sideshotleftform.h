#ifndef SIDESHOTLEFTFORM_H
#define SIDESHOTLEFTFORM_H

#include <QWidget>

namespace Ui {
class SideshotLeftForm;
}

class SideshotLeftForm : public QWidget
{
  Q_OBJECT
  
public:
  explicit SideshotLeftForm(QWidget *parent = 0);
  ~SideshotLeftForm();
  
private:
  Ui::SideshotLeftForm *ui;
};

#endif // SIDESHOTLEFTFORM_H
