#ifndef THOMSON_H
#define THOMSON_H

#include "pirkeysetmetadata.h"

class QObject;

class ThomsonConverter1: public PIRKeysetMetaData
{
public:
  ThomsonConverter1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class ThomsonTV1: public PIRKeysetMetaData
{
public:
  ThomsonTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class ThomsonVCR1: public PIRKeysetMetaData
{
public:
  ThomsonVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class ThomsonVCR1a: public ThomsonVCR1
{
public:
  ThomsonVCR1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class ThomsonDVD1: public PIRKeysetMetaData
{
public:
  ThomsonDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class ThomsonSat1: public PIRKeysetMetaData
{
public:
  ThomsonSat1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class ThomsonAudio1: public PIRKeysetMetaData
{
public:
  ThomsonAudio1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class ThomsonAudio2: public PIRKeysetMetaData
{
public:
  ThomsonAudio2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // THOMSON_H
