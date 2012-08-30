#ifndef TELEFUNKEN_H
#define TELEFUNKEN_H

#include "pirkeysetmetadata.h"

class QObject;

class TelefunkenTV1: public PIRKeysetMetaData
{
public:
  TelefunkenTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class TelefunkenTV1a: public TelefunkenTV1
{
public:
  TelefunkenTV1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // TELEFUNKEN_H
