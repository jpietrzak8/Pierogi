#ifndef PROVIEW_H
#define PROVIEW_H

#include "pirkeysetmetadata.h"

class QObject;

class ProviewDVD1: public PIRKeysetMetaData
{
public:
  ProviewDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // PROVIEW_H
