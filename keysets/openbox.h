#ifndef OPENBOX_H
#define OPENBOX_H

#include "pirkeysetmetadata.h"

class QObject;

class OpenBoxSTB1: public PIRKeysetMetaData
{
public:
  OpenBoxSTB1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class OpenBoxSTB2: public PIRKeysetMetaData
{
public:
  OpenBoxSTB2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // OPENBOX_H
