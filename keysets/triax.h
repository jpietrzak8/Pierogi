#ifndef TRIAX_H
#define TRIAX_H

#include "pirkeysetmetadata.h"

class QObject;

class TriaxSTB1: public PIRKeysetMetaData
{
public:
  TriaxSTB1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class TriaxSTB2: public PIRKeysetMetaData
{
public:
  TriaxSTB2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class TriaxSTB2a: public TriaxSTB2
{
public:
  TriaxSTB2a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // TRIAX_H
