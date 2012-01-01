#ifndef PIRABOUTFORM_H
#define PIRABOUTFORM_H

#include <QWidget>

namespace Ui {
class PIRAboutForm;
}

class PIRAboutForm : public QWidget
{
  Q_OBJECT
  
public:
  explicit PIRAboutForm(QWidget *parent = 0);
  ~PIRAboutForm();
  
private:
  Ui::PIRAboutForm *ui;
};

#endif // PIRABOUTFORM_H
