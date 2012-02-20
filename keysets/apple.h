#ifndef APPLE_H
#define APPLE_H

#include "pirkeysetmetadata.h"

class QObject;

class AppleWhiteRemote: public PIRKeysetMetaData
{
public:
  AppleWhiteRemote(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // APPLE_H
