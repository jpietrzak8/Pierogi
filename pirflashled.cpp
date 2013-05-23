//
// pirflashled.cpp
//
// Copyright 2012, 2013 by John Pietrzak (jpietrzak8@gmail.com)
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
#include "pirexception.h"
#include <errno.h>
#include <sstream>

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
      std::stringstream ss;
      ss << "Failed to close flash LED device.\n";
      ss << "Error is " << strerror(errno) << "\n";
      throw PIRException(ss.str());
    }
  }
}


void PIRFlashLED::openFlashDevice()
{
  // Not sure why "O_RDWR", but it seems to be necessary:
  fileDescriptor = open(PATH_TO_FLASH_DEVICE, O_RDWR | O_NONBLOCK, 0);

  if (fileDescriptor == -1)
  {
    std::stringstream ss;
    ss << "Failed to connect to " << PATH_TO_FLASH_DEVICE << "\n";
    ss << "Error is " << strerror(errno) << "\n";
    throw PIRException(ss.str());
  }

  // Find out the intensity values for the LED:

  struct v4l2_queryctrl qctrl;

  // Retrieve intensity values for strobe usage:
  qctrl.id = V4L2_CID_FLASH_INTENSITY;

  if (ioctl(fileDescriptor, VIDIOC_QUERYCTRL, &qctrl) == -1)
  {
    std::stringstream ss;
    ss << "Failed to retrieve flash LED intensity values.\n";
    ss << "Error is " << strerror(errno) << "\n";
    throw PIRException(ss.str());
  }

  minFlash = qctrl.minimum;
  maxFlash = qctrl.maximum;

  // Retrieve timeout values for strobe usage:
  qctrl.id = V4L2_CID_FLASH_TIMEOUT;

  if (ioctl(fileDescriptor, VIDIOC_QUERYCTRL, &qctrl) == -1)
  {
    std::stringstream ss;
    ss << "Failed to retrieve flash timeout values.\n";
    ss << "Error is " << strerror(errno) << "\n";
    throw PIRException(ss.str());
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
    std::stringstream ss;
    ss << "Failed to set flash intensity to " << maxFlash << "\n";
    ss << "Error is " << strerror(errno) << "\n";
    throw PIRException(ss.str());
  }

  ctrl.id = V4L2_CID_FLASH_TIMEOUT;
  // For now, let's be a bit conservative and cut the max time in half:
  ctrl.value = maxTime / 2;

  if (ioctl(fileDescriptor, VIDIOC_S_CTRL, &ctrl) == -1)
  {
    std::stringstream ss;
    ss << "Failed to set flash timeout to " << maxTime << "\n";
    ss << "Error is " << strerror(errno) << "\n";
    throw PIRException(ss.str());
  }

  ctrl.id = V4L2_CID_FLASH_STROBE;

  if (ioctl(fileDescriptor, VIDIOC_S_CTRL, &ctrl) == -1)
  {
    std::stringstream ss;
    ss << "Failed to strobe flash.\n";
    ss << "Error is " << strerror(errno) << "\n";
    throw PIRException(ss.str());
  }
}
