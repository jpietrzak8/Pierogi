#ifndef ONIDA_H
#define ONIDA_H

#include "pirkeysetmetadata.h"

class QObject;

class OnidaTV1: public PIRKeysetMetaData
{
public:
  OnidaTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class OnidaDVD1: public PIRKeysetMetaData
{
public:
  OnidaDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // ONIDA_H
