#ifndef EMERSON_H
#define EMERSON_H

#include "pirkeysetmetadata.h"

class QObject;

class EmersonTV1: public PIRKeysetMetaData
{
public:
  EmersonTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class EmersonDVD1: public PIRKeysetMetaData
{
public:
  EmersonDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // EMERSON_H
