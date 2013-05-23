//
// pirinfraredled.cpp
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

#include "pirinfraredled.h"

// #define DEBUGGING

// Needed system includes:
#include <sys/ioctl.h>
#ifdef DEBUGGING
#include <iostream>
#include <sys/time.h>
timeval previousTime;
#endif // DEBUGGING
#include <linux/types.h>
#include <linux/ioctl.h>
#include <fcntl.h>

// Includes I'm using for error handling stuff:
#include "pirexception.h"
#include <errno.h>
#include <sstream>

// The N900's IR transmitter is controlled by a device driver created
// specifically for the LIRC daemon:
#define PATH_TO_LIRC_DEVICE "/dev/lirc0"

// It appears that the frequency on this device can range between
// 20000 on the low end and 500000 on the high end...
// 38000 is the default for LIRC:
//#define DEFAULT_FREQUENCY 38000

// The duty cycle is a percentage (0-100), 50 is LIRC's default:
//#define DEFAULT_DUTY_CYCLE 50


PIRInfraredLED::PIRInfraredLED()
  : fileDescriptor(-1),
    index(0)
{
  openLircDevice();
}


PIRInfraredLED::PIRInfraredLED(
  unsigned int frequency,
  unsigned int dutyCycle)
  : fileDescriptor(-1),
    index(0)
{
  openLircDevice();
  setCarrierFrequency(frequency);
  setDutyCycle(dutyCycle);
}


PIRInfraredLED::~PIRInfraredLED()
{
  if (fileDescriptor >= 0) close(fileDescriptor);
}


void PIRInfraredLED::openLircDevice()
{
#ifdef DEBUGGING
  // check the current time:
  gettimeofday(&previousTime, NULL);
#endif // DEBUGGING
  fileDescriptor = open(PATH_TO_LIRC_DEVICE, O_WRONLY);

  if (fileDescriptor == -1)
  {
    std::stringstream ss;
    ss << "Failed to connect to " << PATH_TO_LIRC_DEVICE << "\n";
    ss << "Error is " << strerror(errno) << "\n";
    throw PIRException(ss.str());
  }
}


void PIRInfraredLED::addPair(
  int pulse,
  int space)
{
  if (index >= (BUFFER_SIZE - 1))
  {
    // Needed room for 2 ints, didn't have it.
    throw PIRException("Buffer overflow in PIRCommandBuffer object.\n");
  }

  buffer[index] = pulse;
  ++index;
  buffer[index] = space;
  ++index;
}


void PIRInfraredLED::addSingle(
  int single)
{
  if (index >= BUFFER_SIZE)
  {
    throw PIRException("Buffer overflow in PIRCommandBuffer object.\n");
  }

  buffer[index] = single;
  ++index;
}


void PIRInfraredLED::sendCommandToDevice()
{
  // Sanity check first:
  if (!index)
  {
    // We have no data!
    // We should probably complain here, but for now, just return.
    return;
  }

  // Note: if the generated command string ends on a "space", we'll just
  // go ahead and ignore that last value.  Want the light switched off
  // permanently at the end of the command string, not temporarily.
  // So, only odd-numbered strings of commands are allowed:
  if ((index % 2) == 0)
  {
    --index;
  }

#ifdef DEBUGGING
  timeval newTime;
  gettimeofday(&newTime, NULL);
  long microseconds = newTime.tv_usec - previousTime.tv_usec;
  microseconds += (newTime.tv_sec - previousTime.tv_sec) * 1000000;
  std::cout << "Time since last call to device: " << microseconds << std::endl;
  previousTime = newTime;
//#ifdef DEBUGGING
  std::cout << "Sending array of ints to device:\n";
  int blah = 0;
  while (blah < index)
  {
    std::cout << "buffer[" << blah << "]: " << buffer[blah] << "\n";
    ++blah;
  }
  std::cout << std::endl;
#endif // DEBUGGING
  if (write(fileDescriptor, buffer, index * sizeof(int)) == -1)
  {
    std::stringstream ss;
    ss << "Failed to send command.\n";
    ss << "IR device returned error: " << strerror(errno) << "\n";
    throw PIRException(ss.str());
  }

  // Reset the index:
  index = 0;
}


void PIRInfraredLED::setCarrierFrequency(
  unsigned int frequency)
{
//  if (!frequency) frequency = DEFAULT_FREQUENCY;

#ifdef DEBUGGING
  std::cout << "Setting frequency to " << frequency << std::endl;
#endif // DEBUGGING
  if (ioctl(fileDescriptor, _IOW('i', 0x13, __u32), &frequency) == -1)
  {
    std::stringstream ss;
    ss << "Failed to set carrier frequency.\n";
    ss << "IR device returned error: " << strerror(errno) << "\n";
    throw PIRException(ss.str());
  }
}


void PIRInfraredLED::setDutyCycle(
  unsigned int dutyCycle)
{
//  if (dutyCycle > 100) dutyCycle = DEFAULT_DUTY_CYCLE;

#ifdef DEBUGGING
  std::cout << "Setting duty cycle to " << dutyCycle << std::endl;
#endif // DEBUGGING
  if (ioctl(fileDescriptor, _IOW('i', 0x15, __u32), &dutyCycle) == -1)
  {
    std::stringstream ss;
    ss << "Failed to set duty cycle percentage.\n";
    ss << "IR device returned error: " << strerror(errno) << "\n";
    throw PIRException(ss.str());
  }
}
