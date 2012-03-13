#ifndef PIRTEXTENTRYDIALOG_H
#define PIRTEXTENTRYDIALOG_H

#include <QDialog>

namespace Ui {
class PIRTextEntryDialog;
}

class PIRTextEntryDialog : public QDialog
{
  Q_OBJECT
  
public:
  explicit PIRTextEntryDialog(QWidget *parent = 0);
  ~PIRTextEntryDialog();
  
private:
  Ui::PIRTextEntryDialog *ui;
};

#endif // PIRTEXTENTRYDIALOG_H
