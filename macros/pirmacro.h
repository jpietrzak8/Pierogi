#ifndef PIRMACRO_H
#define PIRMACRO_H

#include <QObject>
#include <QTreeWidgetItem>
#include <QString>

class PIRMacroCommandItem;
class PIRMacroPack;
class QListWidget;
class QSettings;
class MainWindow;

#include <list>
typedef std::list<PIRMacroCommandItem *> CommandSequence;

class PIRMacro: public QObject, public QTreeWidgetItem
{
  Q_OBJECT

public:
  PIRMacro(
    PIRMacroPack *parent,
    QString name,
    char key,
    unsigned int buttonID,
    MainWindow *mw);

  ~PIRMacro();

  QString getName();

  void setName(
    QString name);

  char getKey();

  void setKey(
    char key);

  unsigned int getButtonID();

  void setButtonID(
    unsigned int id);

  void appendCommand(
    PIRMacroCommandItem *c);

  bool deleteCommand(
    int index);

  bool moveUp(
    int index);

  bool moveDown(
    int index);

  void populateList(
    QListWidget *lw);

  bool executeMacro();

  void storeSettings(
    QSettings &settings);

  QString getCommandType(
    int index);

  QString getCommandName(
    int index);

signals:
  void macroCompleted();

private slots:
  void startNextCommand();

private:
  char key;
  unsigned int buttonID;
  CommandSequence commands;
  CommandSequence::iterator currentCommand;
  unsigned int preMacroKeysetID;

  static bool macroRunning; // only one macro can run at a time!

  MainWindow *mainWindow;
};

#endif // PIRMACRO_H
