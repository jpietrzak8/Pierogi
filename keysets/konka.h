#ifndef KONKA_H
#define KONKA_H

#include "pirkeysetmetadata.h"

class QObject;

class KonkaTV1: public PIRKeysetMetaData
{
public:
  KonkaTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class KonkaTV2: public PIRKeysetMetaData
{
public:
  KonkaTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // KONKA_H
