#ifndef VIEWSONIC_H
#define VIEWSONIC_H

#include "pirkeysetmetadata.h"

class QObject;

class ViewsonicProjector1: public PIRKeysetMetaData
{
public:
  ViewsonicProjector1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class ViewsonicProjector2: public PIRKeysetMetaData
{
public:
  ViewsonicProjector2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // VIEWSONIC_H
