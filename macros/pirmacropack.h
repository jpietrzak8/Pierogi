#ifndef PIRMACROPACK_H
#define PIRMACROPACK_H

#include <QTreeWidgetItem>
#include <QString>

class QTreeWidget;
class PIRMacro;

class PIRMacroPack: public QTreeWidgetItem
{
public:
  PIRMacroPack(
    QTreeWidget *parent,
    QString n);
};

#endif // PIRMACROPACK_H
