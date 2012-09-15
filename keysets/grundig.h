#ifndef GRUNDIG_H
#define GRUNDIG_H

#include "pirkeysetmetadata.h"

class QObject;

class GrundigSat1: public PIRKeysetMetaData
{
public:
  GrundigSat1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class GrundigSat2: public PIRKeysetMetaData
{
public:
  GrundigSat2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class GrundigSat3: public PIRKeysetMetaData
{
public:
  GrundigSat3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class GrundigAmp1: public PIRKeysetMetaData
{
public:
  GrundigAmp1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class GrundigAudio1: public PIRKeysetMetaData
{
public:
  GrundigAudio1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class GrundigAudio2: public PIRKeysetMetaData
{
public:
  GrundigAudio2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class GrundigVCR1: public PIRKeysetMetaData
{
public:
  GrundigVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class GrundigVCR1a: public GrundigVCR1
{
public:
  GrundigVCR1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class GrundigTV1: public PIRKeysetMetaData
{
public:
  GrundigTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class GrundigTV2: public PIRKeysetMetaData
{
public:
  GrundigTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class GrundigTV3: public PIRKeysetMetaData
{
public:
  GrundigTV3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class GrundigTV4: public PIRKeysetMetaData
{
public:
  GrundigTV4(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class GrundigDVD1: public PIRKeysetMetaData
{
public:
  GrundigDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // GRUNDIG_H
