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

private slots:
  void filterListByMake(
    int make);

private:
  QListWidget *nameListWidget;
  QLabel *makeLabel;
  QComboBox *makeComboBox;
  QGridLayout *layout;
};


#endif // SELECTIONWINDOW_H
