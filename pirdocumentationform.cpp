#include "pirdocumentationform.h"
#include "ui_pirdocumentationform.h"

PIRDocumentationForm::PIRDocumentationForm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::PIRDocumentationForm)
{
  ui->setupUi(this);

  setAttribute(Qt::WA_Maemo5StackedWindow);
  setWindowFlags(windowFlags() | Qt::Window);
}

PIRDocumentationForm::~PIRDocumentationForm()
{
  delete ui;
}
