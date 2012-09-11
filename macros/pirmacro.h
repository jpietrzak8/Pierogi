#ifndef PIRMACRO_H
#define PIRMACRO_H

#include <QObject>
#include <QTreeWidgetItem>
#include <QString>

class PIRMacroCommandItem;
class QListWidget;

#include <list>
typedef std::list<PIRMacroCommandItem *> CommandSequence;

class PIRMacro: public QObject, public QTreeWidgetItem
{
  Q_OBJECT

public:
  PIRMacro(
    QTreeWidgetItem *parent,
    QString n,
    char k);

  QString getName();

  char getKeyMapping();

  void appendCommand(
    PIRMacroCommandItem *c);

  void populateList(
    QListWidget *lw);

  bool executeMacro();

signals:
  void macroCompleted();

private slots:
  void startNextCommand();

private:
  QString name;
  char keyMapping;
  CommandSequence commands;
  CommandSequence::iterator currentCommand;

  static bool macroRunning; // only one macro can run at a time!
};

#endif // PIRMACRO_H
