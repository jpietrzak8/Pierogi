#include "pirdeviceinfo.h"

#include <string.h>

bool operator< (
  const DeviceInfo &a,
  const DeviceInfo &b)
{
  if (a.make < b.make) return true;

  if ((a.make == b.make) && (strcmp(a.model, b.model) < 0)) return true;

  return false;
}
