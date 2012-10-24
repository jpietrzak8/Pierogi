#ifndef MULTICHOICE_H
#define MULTICHOICE_H

#include "pirkeysetmetadata.h"

class QObject;

class MultichoiceSTB1: public PIRKeysetMetaData
{
public:
  MultichoiceSTB1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class MultichoiceSTB2: public PIRKeysetMetaData
{
public:
  MultichoiceSTB2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // MULTICHOICE_H
