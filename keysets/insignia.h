#ifndef INSIGNIA_H
#define INSIGNIA_H

#include "pirkeysetmetadata.h"

class QObject;

class InsigniaTV1: public PIRKeysetMetaData
{
public:
  InsigniaTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class InsigniaTV2: public PIRKeysetMetaData
{
public:
  InsigniaTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class InsigniaTV3: public PIRKeysetMetaData
{
public:
  InsigniaTV3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class InsigniaDVD1: public PIRKeysetMetaData
{
public:
  InsigniaDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class InsigniaDVD2: public PIRKeysetMetaData
{
public:
  InsigniaDVD2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class InsigniaDVD3: public PIRKeysetMetaData
{
public:
  InsigniaDVD3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // INSIGNIA_H
