#ifndef QNAP_H
#define QNAP_H

#include "pirkeysetmetadata.h"

class QObject;

class QNAPPlayer1: public PIRKeysetMetaData
{
public:
  QNAPPlayer1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // QNAP_H
