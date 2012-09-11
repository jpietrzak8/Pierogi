#ifndef CROWN_H
#define CROWN_H

#include "pirkeysetmetadata.h"

class QObject;

class CrownTV1: public PIRKeysetMetaData
{
public:
  CrownTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class CrownAudio1: public PIRKeysetMetaData
{
public:
  CrownAudio1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // CROWN_H
