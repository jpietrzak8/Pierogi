#ifndef SAGEM_H
#define SAGEM_H

#include "pirkeysetmetadata.h"
#include <QObject>

class SagemTVBox1: public PIRKeysetMetaData
{
public:
  SagemTVBox1(
    QObject *guiObject,
    unsigned int index);
};

class SagemTVBox1a: public SagemTVBox1
{
public:
  SagemTVBox1a(
    QObject *guiObject,
    unsigned int index);
};

#endif // SAGEM_H
