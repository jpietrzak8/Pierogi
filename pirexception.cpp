#include "pirexception.h"

#include <QtGui/QMessageBox>

/*
PirException::PirException()
{
}
*/


void PIRException::display()
{
  QMessageBox errBox;
  errBox.setText(errStr.c_str());
  errBox.setIcon(QMessageBox::Warning);
  errBox.exec();
}
