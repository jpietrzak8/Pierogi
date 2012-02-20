#ifndef MITSUBISHI_H
#define MITSUBISHI_H

#include "pirkeysetmetadata.h"

class QObject;

class MitsubishiTV1: public PIRKeysetMetaData
{
public:
  MitsubishiTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class MitsubishiTV1a: public MitsubishiTV1
{
public:
  MitsubishiTV1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class MitsubishiVCR1: public PIRKeysetMetaData
{
public:
  MitsubishiVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class MitsubishiVCR1a: public MitsubishiVCR1
{
public:
  MitsubishiVCR1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // MITSUBISHI_H
