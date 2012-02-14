#ifndef EMERSON_H
#define EMERSON_H

#include "pirkeysetmetadata.h"

class QObject;

class EmersonTV1: public PIRKeysetMetaData
{
public:
  EmersonTV1(
    QObject *guiObject,
    unsigned int index);
};

class EmersonDVD1: public PIRKeysetMetaData
{
public:
  EmersonDVD1(
    QObject *guiObject,
    unsigned int index);
};

#endif // EMERSON_H
