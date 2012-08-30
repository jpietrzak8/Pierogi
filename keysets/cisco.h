#ifndef CISCO_H
#define CISCO_H

#include "pirkeysetmetadata.h"

class QObject;

class CiscoSTB1: public PIRKeysetMetaData
{
public:
  CiscoSTB1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class CiscoSTB2: public PIRKeysetMetaData
{
public:
  CiscoSTB2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class CiscoSTB3: public PIRKeysetMetaData
{
public:
  CiscoSTB3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // CISCO_H
