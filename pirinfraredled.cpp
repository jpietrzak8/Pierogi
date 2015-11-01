//
// pirinfraredled.cpp
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

#include "pirinfraredled.h"

// #define DEBUGGING

// Needed system includes:
#include <sys/ioctl.h>
#ifdef DEBUGGING
#include <QDebug>
#include <sys/time.h>
timeval previousTime;
#endif // DEBUGGING
#include <linux/types.h>
#include <linux/ioctl.h>
#include <fcntl.h>

// Includes I'm using for error handling stuff:
//#include "pirexception.h"
#include <errno.h>
#include <QString>

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


bool PIRInfraredLED::openLircDevice()
{
#ifdef DEBUGGING
  // check the current time:
  gettimeofday(&previousTime, NULL);
#endif // DEBUGGING
  fileDescriptor = open(PATH_TO_LIRC_DEVICE, O_WRONLY);

  if (fileDescriptor == -1)
  {
    QString errStr = "Failed to connect to ";
    errStr += PATH_TO_LIRC_DEVICE;
    errStr += "\nError is ";
    errStr +=  strerror(errno);
    emit errorMessage(errStr);
    return false;
  }

  return true;
}


bool PIRInfraredLED::addPair(
  int pulse,
  int space)
{
  if (index >= (BUFFER_SIZE - 1))
  {
    // Needed room for 2 ints, didn't have it.
    emit errorMessage("Buffer overflow in PIRCommandBuffer object.");
    return false;
  }

  buffer[index] = pulse;
  ++index;
  buffer[index] = space;
  ++index;

  return true;
}


bool PIRInfraredLED::addSingle(
  int single)
{
  if (index >= BUFFER_SIZE)
  {
    emit errorMessage("Buffer overflow in PIRCommandBuffer object.");
    return false;
  }

  buffer[index] = single;
  ++index;

  return true;
}


bool PIRInfraredLED::sendCommandToDevice()
{
  // Sanity check first:
  if (!index)
  {
    emit errorMessage("Empty command string.");
    return true; // Not exactly an error...
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
  qDebug() << "Time since last call to device: " << microseconds;
  previousTime = newTime;
//#ifdef DEBUGGING
  qDebug() << "Sending array of ints to device:";
  int blah = 0;
  while (blah < index)
  {
    qDebug() << "buffer[" << blah << "]: " << buffer[blah];
    ++blah;
  }
#endif // DEBUGGING
  if (write(fileDescriptor, buffer, index * sizeof(int)) == -1)
  {
    QString errStr = "IR device returned error: ";
    errStr += strerror(errno);
    emit errorMessage(errStr);
    return false;
  }

  // Reset the index:
  index = 0;

  return true;
}


bool PIRInfraredLED::setCarrierFrequency(
  unsigned int frequency)
{
//  if (!frequency) frequency = DEFAULT_FREQUENCY;

#ifdef DEBUGGING
  qDebug() << "Setting frequency to " << frequency;
#endif // DEBUGGING
  if (ioctl(fileDescriptor, _IOW('i', 0x13, __u32), &frequency) == -1)
  {
    QString errStr = "IR device returned error: ";
    errStr += strerror(errno);
    emit errorMessage(errStr);
    return false;
  }

  return true;
}


bool PIRInfraredLED::setDutyCycle(
  unsigned int dutyCycle)
{
//  if (dutyCycle > 100) dutyCycle = DEFAULT_DUTY_CYCLE;

#ifdef DEBUGGING
  qDebug() << "Setting duty cycle to " << dutyCycle;
#endif // DEBUGGING
  if (ioctl(fileDescriptor, _IOW('i', 0x15, __u32), &dutyCycle) == -1)
  {
    QString errStr = "IR device returned error: ";
    errStr += strerror(errno);
    emit errorMessage(errStr);
    return false;
  }

  return true;
}
