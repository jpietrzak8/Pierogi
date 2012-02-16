#ifndef BEKO_H
#define BEKO_H

#include "pirkeysetmetadata.h"

class QObject;

class BekoTV1: public PIRKeysetMetaData
{
public:
  BekoTV1(
    QObject *guiObject,
    unsigned int index);
};

#endif // BEKO_H
