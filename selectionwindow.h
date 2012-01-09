#ifndef SELECTIONWINDOW_H
#define SELECTIONWINDOW_H

#include "pirmakenames.h"

#include <QWidget>
#include <QListWidget>
#include <QLabel>
#include <QComboBox>
#include <QGridLayout>
#include <QString>


class SelectionWindow : public QWidget
{
  Q_OBJECT
  
public:
  explicit SelectionWindow(
    QWidget *parent = 0);

  ~SelectionWindow();

  void addNameToList(
    QString name,
    unsigned int index,
    PIRMakeName make);

  // Public just for now, to get a quick hack working.  (Actually, this whole
  // class should be replaced with a UI form eventually, to match the rest of
  // the code...)
  QListWidget *nameListWidget;

private slots:
  void filterListByMake(
    int make);

private:
  QLabel *makeLabel;
  QComboBox *makeComboBox;
  QGridLayout *layout;
};


#endif // SELECTIONWINDOW_H
