#ifndef PIRMACROMANAGER_H
#define PIRMACROMANAGER_H

class PIRMacroPack;
class PIRReverseMultitap;
class MainWindow;
class QString;

class PIRMacroManager
{
public:
  PIRMacroManager(
    MainWindow *mw);

  ~PIRMacroManager();

  PIRMacroPack *getUserPack();
  PIRMacroPack *getMultitapPack();

  void setKeyboardController(
    PIRMacroPack *pack);

  void setButtonsController(
    PIRMacroPack *pack);

  void handleKeypress(
    char key);

  bool hasMacroButton(
    unsigned int buttonID);

  QString getMacroButtonText(
    unsigned int buttonID);

  void executeMacroButton(
    unsigned int buttonID);

  void storeSettings();

  void setKbdFocus(
    int index);

  void setBtnFocus(
    int index);

private:
  void retrieveSettings();

  void executeStandardKey(
    char key);

  PIRMacroPack *userPack;
  PIRReverseMultitap *multitapPack;

  PIRMacroPack *keyboardController;
  PIRMacroPack *buttonsController;

  MainWindow *mainWindow;
};

#endif // PIRMACROMANAGER_H
