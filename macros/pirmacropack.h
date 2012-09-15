#ifndef PIRMACROPACK_H
#define PIRMACROPACK_H

#include <QTreeWidgetItem>
#include <QString>
#include <map>

class QTreeWidget;
class PIRMacro;

typedef std::map<unsigned int, PIRMacro *> ButtonCollection;
typedef std::map<char, PIRMacro *> KeyboardCollection;

class PIRMacroPack: public QTreeWidgetItem
{
public:
  PIRMacroPack(
    QString n);

  bool hasButton(
    unsigned int buttonID);

  void registerButton(
    unsigned int buttonID,
    PIRMacro *macro);

  void eraseButton(
    unsigned int buttonID,
    PIRMacro *macro);

  QString buttonText(
    unsigned int buttonID);

  void executeButton(
    unsigned int buttonID);

  bool hasKey(
    char key);

  void registerKey(
    char key,
    PIRMacro *macro);

  void eraseKey(
    char key,
    PIRMacro *macro);

  void executeKey(
    char key);

  void storeSettings();

private:
  ButtonCollection buttons;
  KeyboardCollection keymaps;
};

#endif // PIRMACROPACK_H
