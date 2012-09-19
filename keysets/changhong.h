#ifndef CHANGHONG_H
#define CHANGHONG_H

#include "pirkeysetmetadata.h"

class QObject;

class ChanghongTV1: public PIRKeysetMetaData
{
public:
  ChanghongTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class ChanghongTV1a: public ChanghongTV1
{
public:
  ChanghongTV1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class ChanghongTV1b: public ChanghongTV1
{
public:
  ChanghongTV1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class ChanghongTV2: public PIRKeysetMetaData
{
public:
  ChanghongTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class ChanghongTV3: public PIRKeysetMetaData
{
public:
  ChanghongTV3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // CHANGHONG_H
