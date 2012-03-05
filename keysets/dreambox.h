#ifndef DREAMBOX_H
#define DREAMBOX_H

#include "pirkeysetmetadata.h"

class QObject;

class DreamboxSat1: public PIRKeysetMetaData
{
public:
  DreamboxSat1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DreamboxSat1a: public DreamboxSat1
{
public:
  DreamboxSat1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DreamboxSat1b: public DreamboxSat1
{
public:
  DreamboxSat1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DreamboxSat1c: public DreamboxSat1
{
public:
  DreamboxSat1c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DreamboxSat2: public PIRKeysetMetaData
{
public:
  DreamboxSat2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DreamboxSat3: public PIRKeysetMetaData
{
public:
  DreamboxSat3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DreamboxSat4: public PIRKeysetMetaData
{
public:
  DreamboxSat4(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DreamboxSat5: public PIRKeysetMetaData
{
public:
  DreamboxSat5(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // DREAMBOX_H
