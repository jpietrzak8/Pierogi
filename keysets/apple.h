#ifndef APPLE_H
#define APPLE_H

#include "pirkeysetmetadata.h"

#include <QObject>

class AppleWhiteRemote: public PIRKeysetMetaData
{
public:
  AppleWhiteRemote(
    QObject *guiObject,
    unsigned int index);
};

#endif // APPLE_H
