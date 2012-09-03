#ifndef PIRVIDEODISCFORM_H
#define PIRVIDEODISCFORM_H

#include <QWidget>

namespace Ui {
class PIRVideoDiscForm;
}

class PIRVideoDiscForm : public QWidget
{
  Q_OBJECT
  
public:
  explicit PIRVideoDiscForm(QWidget *parent = 0);
  ~PIRVideoDiscForm();
  
private:
  Ui::PIRVideoDiscForm *ui;
};

#endif // PIRVIDEODISCFORM_H
