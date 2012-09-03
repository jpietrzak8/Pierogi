#include "pireditkeysetdialog.h"
#include "ui_pireditkeysetdialog.h"

#include "mainwindow.h"
#include "pirkeysetwidgetitem.h"

#include <QSettings>

#include "pirmakenames.h"
extern PIRMakeMgr makeManager;

/*
PIREditKeysetDialog::PIREditKeysetDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::PIREditKeysetDialog)
{
  ui->setupUi(this);
}
*/

PIREditKeysetDialog::PIREditKeysetDialog(
  MainWindow *mw)
  : QDialog(mw),
    ui(new Ui::PIREditKeysetDialog),
    mainWindow(mw)
{
  ui->setupUi(this);

  connect(
    this,
    SIGNAL(accepted()),
    this,
    SLOT(enactChanges()),
    Qt::QueuedConnection);
}

PIREditKeysetDialog::~PIREditKeysetDialog()
{
  delete ui;
}


void PIREditKeysetDialog::setupDialog(
  PIRKeysetWidgetItem *kwi)
{
  ui->keysetNameLabel->setText(
    kwi->text());

  ui->addToFavoritesCheckBox->setChecked(kwi->isFavorite());

  if (kwi->hasNickname())
  {
    ui->nicknameLineEdit->setText(kwi->getNickname());
  }

  keysetItem = kwi;
}


void PIREditKeysetDialog::enactChanges()
{
  // Did the nickname change?
  bool nickChanged = false;
  QString newNick = ui->nicknameLineEdit->text();
  if (newNick != keysetItem->getNickname())
  {
    nickChanged = true;

    keysetItem->setNickname(newNick);

    // Need to update the display name:
    QString newDisplayName;
    if (!newNick.isEmpty())
    {
      newDisplayName = newNick;
      newDisplayName.append(" (");
      newDisplayName.append(makeManager.getMakeString(keysetItem->getMake()));
      newDisplayName.append(" ");
      newDisplayName.append(keysetItem->getInternalName());
      newDisplayName.append(")");

      updateQSettingsNickname();
    }
    else
    {
      newDisplayName = makeManager.getMakeString(keysetItem->getMake());
      newDisplayName.append(" ");
      newDisplayName.append(keysetItem->getInternalName());

      removeQSettingsNickname();
    }

    keysetItem->setText(newDisplayName);
  }

  // Did the favorites setting change?
  if (keysetItem->isFavorite())
  {
    if (!ui->addToFavoritesCheckBox->isChecked())
    {
      // Remove it from the favorites list:
      keysetItem->setFavorite(false);
      mainWindow->removeFromFavorites(keysetItem->getID());
    }
    else
    {
      // It's already in the favorites list, but if the nickname changed,
      // we still need to update its entry:
      if (nickChanged)
      {
        mainWindow->removeFromFavorites(keysetItem->getID());
        mainWindow->addToFavorites(keysetItem);
      }
    }
  }
  else
  {
    if (ui->addToFavoritesCheckBox->isChecked())
    {
      keysetItem->setFavorite(true);
      mainWindow->addToFavorites(keysetItem);
    }
  }

  // Finally, clean up the dialog box for the next user:
  ui->nicknameLineEdit->clear();
}


// Creating a new QSettings array entry, or updating an existing one, is
// relatively painless:
void PIREditKeysetDialog::updateQSettingsNickname()
{
  QSettings settings("pietrzak.org", "Pierogi");

  // Try to find an existing entry:
  int size = settings.beginReadArray("userNames");
  int index = 0;
  QString name;
  QString makeStr;
  PIRMakeName makeID;

  while (index < size)
  {
    settings.setArrayIndex(index);
    name = settings.value("keysetName").toString();

    if (name == keysetItem->getInternalName())
    {
      makeStr = settings.value("keysetMake").toString();
      makeID = makeManager.getMakeID(makeStr);

      if (makeID == keysetItem->getMake())
      {
        // We've found a match, so we just need to update it:
        settings.endArray();
        settings.beginWriteArray("userNames");
        settings.setArrayIndex(index);
        settings.setValue("keysetNickname", keysetItem->getNickname());
        settings.endArray();

        // And we're done!
        return;
      }
    }

    ++index;
  }

  settings.endArray();

  // There was no existing entry, so we just need to make one:
  settings.beginWriteArray("userNames");
  settings.setArrayIndex(size);

  settings.setValue(
    "keysetName",
    keysetItem->getInternalName());

  settings.setValue(
    "keysetMake",
    makeManager.getMakeString(keysetItem->getMake()));

  settings.setValue(
    "keysetNickname",
    keysetItem->getNickname());

  settings.endArray();
}


// Removing an entry from a QSettings array is, unfortunately, quite painful:
struct stringTriple
{
  QString keysetName;
  QString keysetMake;
  QString keysetNickname;
};

typedef std::map <int, stringTriple> PIRSettingsData;

void PIREditKeysetDialog::removeQSettingsNickname()
{
  QSettings settings("pietrzak.org", "Pierogi");

  int size = settings.beginReadArray("userNames");
  int index = 0;
  int index2 = 0;
  PIRSettingsData backupData;
  QString nameToRemove = keysetItem->getInternalName();
  QString makeToRemove = makeManager.getMakeString(keysetItem->getMake());

  while (index < size)
  {
    settings.setArrayIndex(index);

    if ( (settings.value("keysetName").toString() != nameToRemove)
      && (settings.value("keysetMake").toString() != makeToRemove) )
    {
      backupData[index2].keysetName =
        settings.value("keysetName").toString();
      backupData[index2].keysetMake =
        settings.value("keysetMake").toString();
      backupData[index2].keysetNickname =
        settings.value("keysetNickname").toString();
      ++index2;
    }

    ++index;
  }

  // Close the array, blow it away, and create a new one:

  settings.endArray();
  settings.remove("userNames");
  settings.beginWriteArray("userNames");

  size = index2;
  index = 0;

  while (index < size)
  {
    settings.setArrayIndex(index);
    settings.setValue("keysetName", backupData[index].keysetName);
    settings.setValue("keysetMake", backupData[index].keysetMake);
    settings.setValue("keysetNickname", backupData[index].keysetNickname);
    ++index;
  }
  settings.endArray();
}
