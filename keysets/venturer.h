#ifndef VENTURER_H
#define VENTURER_H

#include "pirkeysetmetadata.h"

class QObject;

class VenturerTV1: public PIRKeysetMetaData
{
public:
  VenturerTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class VenturerDVD1: public PIRKeysetMetaData
{
public:
  VenturerDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class VenturerSTB1: public PIRKeysetMetaData
{
public:
  VenturerSTB1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // VENTURER_H
