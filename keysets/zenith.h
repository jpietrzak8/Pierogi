#ifndef ZENITH_H
#define ZENITH_H

#include "pirkeysetmetadata.h"

#include <QObject>

class ZenithC32V37: public PIRKeysetMetaData
{
public:
  ZenithC32V37(
    QObject *guiObject,
    unsigned int index);
};

#endif // ZENITH_H
