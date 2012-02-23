#ifndef UNIVERSUM_H
#define UNIVERSUM_H

#include "pirkeysetmetadata.h"

class QObject;

class UniversumVCR1: public PIRKeysetMetaData
{
public:
  UniversumVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class UniversumVCR2: public PIRKeysetMetaData
{
public:
  UniversumVCR2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class UniversumVCR3: public PIRKeysetMetaData
{
public:
  UniversumVCR3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class UniversumTV1: public PIRKeysetMetaData
{
public:
  UniversumTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class UniversumTV1a: public UniversumTV1
{
public:
  UniversumTV1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class UniversumSat1: public PIRKeysetMetaData
{
public:
  UniversumSat1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class UniversumAudio1: public PIRKeysetMetaData
{
public:
  UniversumAudio1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // UNIVERSUM_H
