#ifndef ANITECH_H
#define ANITECH_H

#include "pirkeysetmetadata.h"

class QObject;

class AnitechTV1: public PIRKeysetMetaData
{
public:
  AnitechTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class AnitechVCR1: public PIRKeysetMetaData
{
public:
  AnitechVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // ANITECH_H
