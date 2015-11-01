//
// pirkeysetmanager.h
//
// Copyright 2012 - 2015 by John Pietrzak  (jpietrzak8@gmail.com)
//
// This file is part of Pierogi.
//
// Pierogi is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// Pierogi is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//

#ifndef PIRKEYSETMANAGER_H
#define PIRKEYSETMANAGER_H

#include "pirkeynames.h"
#include "pirmakenames.h"
#include "pirpanelnames.h"

#include <QString>
#include <QThread>
#include <QObject>

class QComboBox;
class PIRSelectKeysetForm;
class PIRSelectDeviceForm;
class PIRFavoritesDialog;
class PIRKeysetWidgetItem;
class PIRACKeyset;

#include <map>
class PIRKeysetMetaData;

typedef std::map<unsigned int, PIRKeysetMetaData *> PIRKeysetCollection;

// Maps used to locate metadata using QSettings values:
typedef std::map<QString, unsigned int> PIRKeysetNameIndex;
typedef std::map<QString, PIRKeysetNameIndex> PIRKeysetMakeIndex;

class PIRKeysetManager: public QObject
{
  Q_OBJECT

public:
  PIRKeysetManager();

  ~PIRKeysetManager();

  void populateListWidgets(
    PIRSelectKeysetForm *skf,
    PIRFavoritesDialog *fd) const;

  void populateInputList(
    QComboBox *cb,
    unsigned int keysetID) const;

  bool keysetExists(
    unsigned int keysetID) const;

  bool findKeysetID(
    QString make,
    QString name,
    unsigned int &id) const;

  PIRKeysetWidgetItem *makeKeysetItem(
    QString make,
    QString name) const;

  bool hasKey(
    unsigned int keysetID,
    PIRKeyName name) const;

  PIRMakeName getMake(
    unsigned int keysetID) const;

  QString getDisplayName(
    unsigned int keysetID) const;

  PIRPanelTypes getPanelTypes(
    unsigned int keysetID) const;

/*
  void populateDeviceTypes(
    PIRKeysetWidgetItem *kwi,
    unsigned int keysetID) const;
*/

  void populateKeyset(
    QObject *guiObject,
    unsigned int keysetID);

  bool clearKeyset(
    unsigned int keysetID);

  void populateFavorites(
    PIRFavoritesDialog *favoritesDialog,
    PIRSelectKeysetForm *keysetForm);

  unsigned int getCarrierFrequency(
    unsigned int keysetID) const;

  void setCarrierFrequency(
    unsigned int carrierFrequency,
    unsigned int keysetID);

  unsigned int getDutyCycle(
    unsigned int keysetID) const;

  void setDutyCycle(
    unsigned int dutyCycle,
    unsigned int keysetID);

  const PIRACKeyset * getACKeyset(
    unsigned int keysetID) const;

signals:
  void errorMessage(
    QString errStr);

private:
  void setupKeyset(
    PIRKeysetMetaData *keyset);

  PIRKeysetCollection keysetsInfo;
  PIRKeysetMakeIndex makeIndex;

  // The counter will be used to generate unique ids for each keyset:
  unsigned int counter;

  QThread commandThread;
};

#endif // PIRKEYSETMANAGER_H
