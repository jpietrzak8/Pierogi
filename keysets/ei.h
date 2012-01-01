#ifndef EI_H
#define EI_H

#include "pirkeysetmetadata.h"

#include <QObject>

class EiKeyset: public PIRKeysetMetaData
{
public:
  EiKeyset(
    QObject *guiObject,
    unsigned int index);
};

#endif // EI_H
