#include "piraboutform.h"
#include "ui_piraboutform.h"

PIRAboutForm::PIRAboutForm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::PIRAboutForm)
{
  ui->setupUi(this);

  setAttribute(Qt::WA_Maemo5StackedWindow);
  setWindowFlags(windowFlags() | Qt::Window);
}

PIRAboutForm::~PIRAboutForm()
{
  delete ui;
}
