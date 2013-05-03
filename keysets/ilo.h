#ifndef ILO_H
#define ILO_H

#include "pirkeysetmetadata.h"

class QObject;

class ILOTV1: public PIRKeysetMetaData
{
public:
  ILOTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class ILOTV2: public PIRKeysetMetaData
{
public:
  ILOTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class ILOTV3: public PIRKeysetMetaData
{
public:
  ILOTV3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // ILO_H
