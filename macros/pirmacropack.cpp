#include "pirmacropack.h"

PIRMacroPack::PIRMacroPack(
  QTreeWidget *parent,
  QString name)
  : QTreeWidgetItem(parent)
{
  setText(0, name);
}

