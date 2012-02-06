#ifndef EI_H
#define EI_H

#include "pirkeysetmetadata.h"

class QObject;

class EiTV1: public PIRKeysetMetaData
{
public:
  EiTV1(
    QObject *guiObject,
    unsigned int index);
};

#endif // EI_H
