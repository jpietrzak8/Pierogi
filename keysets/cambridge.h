#ifndef CAMBRIDGE_H
#define CAMBRIDGE_H

#include "pirkeysetmetadata.h"

class QObject;

class CambridgeCD1: public PIRKeysetMetaData
{
public:
  CambridgeCD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class CambridgeAudio1: public PIRKeysetMetaData
{
public:
  CambridgeAudio1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class CambridgeAudio2: public PIRKeysetMetaData
{
public:
  CambridgeAudio2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class CambridgeAudio3: public PIRKeysetMetaData
{
public:
  CambridgeAudio3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class CambridgeDVD1: public PIRKeysetMetaData
{
public:
  CambridgeDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // CAMBRIDGE_H
