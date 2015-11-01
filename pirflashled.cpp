//
// pirflashled.cpp
//
// Copyright 2012 - 2015 by John Pietrzak (jpietrzak8@gmail.com)
//
// This file is part of Pierogi.
//
// Pierogi is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// Pierogi is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//

#include "pirflashled.h"

#include <sys/ioctl.h>
#include <linux/videodev2.h>
#include <fcntl.h>

// Error handling stuff:
#include <errno.h>
#include <QString>

// The Flash LEDs are tied into video device 0, along with the camera itself:
#define PATH_TO_FLASH_DEVICE "/dev/video0"

PIRFlashLED::PIRFlashLED()
  : fileDescriptor(-1),
    minFlash(12),
    maxFlash(19),
    maxTime(10000)
{
  openFlashDevice();
}


PIRFlashLED::~PIRFlashLED()
{
  if (fileDescriptor >= 0)
  {
    if (close(fileDescriptor) == -1)
    {
      // Failed to close the Flash LED:
      QString errStr = "Flash LED error: ";
      errStr += strerror(errno);
      emit errorMessage(errStr);
    }
  }
}


bool PIRFlashLED::openFlashDevice()
{
  // Not sure why "O_RDWR", but it seems to be necessary:
  fileDescriptor = open(PATH_TO_FLASH_DEVICE, O_RDWR | O_NONBLOCK, 0);

  if (fileDescriptor == -1)
  {
    QString errStr = "Failed to connect to ";
    errStr += PATH_TO_FLASH_DEVICE;
    errStr += "\nError is: ";
    errStr += strerror(errno);
    emit errorMessage(errStr);
    return false;
  }

  // Find out the intensity values for the LED:

  struct v4l2_queryctrl qctrl;

  // Retrieve intensity values for strobe usage:
  qctrl.id = V4L2_CID_FLASH_INTENSITY;

  if (ioctl(fileDescriptor, VIDIOC_QUERYCTRL, &qctrl) == -1)
  {
    QString errStr = "Failed to retrieve flash LED intensity values.\nError is: ";
    errStr += strerror(errno);
    emit errorMessage(errStr);
    return false;
  }

  minFlash = qctrl.minimum;
  maxFlash = qctrl.maximum;

  // Retrieve timeout values for strobe usage:
  qctrl.id = V4L2_CID_FLASH_TIMEOUT;

  if (ioctl(fileDescriptor, VIDIOC_QUERYCTRL, &qctrl) == -1)
  {
    QString errStr = "Failed to retrieve flash timeout values.\nError is: ";
    errStr += strerror(errno);
    emit errorMessage(errStr);
    return false;
  }

  maxTime = qctrl.maximum;

/*
  // Retrieve intensity values for sustained usage:
  qctrl.id = V4L2_CID_TORCH_INTENSITY;

  if (ioctl(fileDescriptor, VIDIOC_QUERYCTRL, &qctrl) == -1)
  {
    std::stringstream ss;
    ss << "Failed to retrieve torch LED intensity values.\n";
    ss << "Error is " << strerror(errno) << "\n";
    throw PIRException(ss.str());
  }

  minTorch = qctrl.minimum;
  maxTorch = qctrl.maximum;
*/

  return true;
}


void PIRFlashLED::strobe()
{
  struct v4l2_control ctrl;

  // Sanity check:
  if (fileDescriptor == -1)
  {
    // Throw an error here?
    return;
  }

  ctrl.id = V4L2_CID_FLASH_INTENSITY;
  ctrl.value = maxFlash;

  if (ioctl(fileDescriptor, VIDIOC_S_CTRL, &ctrl) == -1)
  {
    QString errStr = "Failed to set flash intensity to ";
    errStr += QString::number(maxFlash);
    errStr += "\nError is: ";
    errStr += strerror(errno);
    emit errorMessage(errStr);
    return;
  }

  ctrl.id = V4L2_CID_FLASH_TIMEOUT;
  // For now, let's be a bit conservative and cut the max time in half:
  ctrl.value = maxTime / 2;

  if (ioctl(fileDescriptor, VIDIOC_S_CTRL, &ctrl) == -1)
  {
    QString errStr = "Failed to set flash timeout to ";
    errStr += QString::number(maxTime);
    errStr += "\nError is: ";
    errStr += strerror(errno);
    emit errorMessage(errStr);
    return;
  }

  ctrl.id = V4L2_CID_FLASH_STROBE;

  if (ioctl(fileDescriptor, VIDIOC_S_CTRL, &ctrl) == -1)
  {
    QString errStr = "Failed to strobe flash.\nError is: ";
    errStr += strerror(errno);
    emit errorMessage(errStr);
    return;
  }
}
