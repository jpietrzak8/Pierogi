#ifndef PHILCO_H
#define PHILCO_H

#include "pirkeysetmetadata.h"

class QObject;

class PhilcoTV: public PIRKeysetMetaData
{
public:
  PhilcoTV(
    QObject *guiObject,
    unsigned int index);
};

#endif // PHILCO_H
