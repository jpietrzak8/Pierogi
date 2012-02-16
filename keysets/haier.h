#ifndef HAIER_H
#define HAIER_H

#include "pirkeysetmetadata.h"

class QObject;

class HaierTV1: public PIRKeysetMetaData
{
public:
  HaierTV1(
    QObject *guiObject,
    unsigned int index);
};

#endif // HAIER_H
