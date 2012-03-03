#ifndef KAON_H
#define KAON_H

#include "pirkeysetmetadata.h"

class QObject;

class KaonSat1: public PIRKeysetMetaData
{
public:
  KaonSat1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // KAON_H
