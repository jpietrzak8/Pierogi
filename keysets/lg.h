#ifndef LG_H
#define LG_H

#include "pirkeysetmetadata.h"

class QObject;

class LGTV1: public PIRKeysetMetaData
{
public:
  LGTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class LGTV1a: public LGTV1
{
public:
  LGTV1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class LGTV1b: public LGTV1
{
public:
  LGTV1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class LGTV1c: public LGTV1
{
public:
  LGTV1c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class LGTV2: public PIRKeysetMetaData
{
public:
  LGTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class LGTV2a: public LGTV2
{
public:
  LGTV2a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class LGTV2b: public LGTV2
{
public:
  LGTV2b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class LGDisc1: public PIRKeysetMetaData
{
public:
  LGDisc1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class LGDisc2: public PIRKeysetMetaData
{
public:
  LGDisc2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class LGDisc2a: public LGDisc2
{
public:
  LGDisc2a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class LGVCR1: public PIRKeysetMetaData
{
public:
  LGVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class LGVCR1a: public LGVCR1
{
public:
  LGVCR1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class LGVCR1b: public LGVCR1
{
public:
  LGVCR1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class LGAC1: public PIRKeysetMetaData
{
public:
  LGAC1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // LG_H
