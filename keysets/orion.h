#ifndef ORION_H
#define ORION_H

#include "pirkeysetmetadata.h"

class QObject;

class OrionTV1: public PIRKeysetMetaData
{
public:
  OrionTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class OrionTV2: public PIRKeysetMetaData
{
public:
  OrionTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class OrionTV3: public PIRKeysetMetaData
{
public:
  OrionTV3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class OrionVCR1: public PIRKeysetMetaData
{
public:
  OrionVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class OrionVCR2: public PIRKeysetMetaData
{
public:
  OrionVCR2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class OrionDVD1: public PIRKeysetMetaData
{
public:
  OrionDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // ORION_H
