#ifndef ONIDA_H
#define ONIDA_H

#include "pirkeysetmetadata.h"

class QObject;

class OnidaTV1: public PIRKeysetMetaData
{
public:
  OnidaTV1(
    QObject *guiObject,
    unsigned int index);
};

class OnidaDVD1: public PIRKeysetMetaData
{
public:
  OnidaDVD1(
    QObject *guiObject,
    unsigned int index);
};

#endif // ONIDA_H
