#ifndef SAGEM_H
#define SAGEM_H

#include "pirkeysetmetadata.h"

class QObject;

class SagemTVBox1: public PIRKeysetMetaData
{
public:
  SagemTVBox1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SagemTVBox1a: public SagemTVBox1
{
public:
  SagemTVBox1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // SAGEM_H
