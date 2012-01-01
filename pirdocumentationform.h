#ifndef PIRDOCUMENTATIONFORM_H
#define PIRDOCUMENTATIONFORM_H

#include <QWidget>

namespace Ui {
class PIRDocumentationForm;
}

class PIRDocumentationForm : public QWidget
{
  Q_OBJECT
  
public:
  explicit PIRDocumentationForm(QWidget *parent = 0);
  ~PIRDocumentationForm();
  
private:
  Ui::PIRDocumentationForm *ui;
};

#endif // PIRDOCUMENTATIONFORM_H
