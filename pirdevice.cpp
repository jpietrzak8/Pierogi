#include "pirdevice.h"

//#define DEBUGGING

// Needed system includes:
#include <sys/ioctl.h>
#ifdef DEBUGGING
#include <iostream>
#include <sys/time.h>
timeval previousTime;
#else
//#ifndef DEBUGGING
#include <linux/types.h>
#include <linux/ioctl.h>
#endif // DEBUGGING
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


PIRDevice::PIRDevice()
  : fileDescriptor(-1),
    index(0)
{
  openLircDevice();
}


PIRDevice::PIRDevice(
  unsigned int frequency,
  unsigned int dutyCycle)
  : fileDescriptor(-1),
    index(0)
{
  openLircDevice();
  setCarrierFrequency(frequency);
  setDutyCycle(dutyCycle);
}


PIRDevice::~PIRDevice()
{
  if (fileDescriptor >= 0) close(fileDescriptor);
}


void PIRDevice::openLircDevice()
{
#ifdef DEBUGGING
  // check the current time:
  gettimeofday(&previousTime, NULL);
#else
//#ifndef DEBUGGING
  fileDescriptor = open(PATH_TO_LIRC_DEVICE, O_WRONLY);

  if (fileDescriptor == -1)
  {
    std::stringstream ss;
    ss << "Failed to connect to " << PATH_TO_LIRC_DEVICE << "\n";
    ss << "Error is " << strerror(errno) << "\n";
    throw PIRException(ss.str());
  }
#endif // DEBUGGING
}


void PIRDevice::addPair(
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


void PIRDevice::addSingle(
  int single)
{
  if (index >= BUFFER_SIZE)
  {
    throw PIRException("Buffer overflow in PIRCommandBuffer object.\n");
  }

  buffer[index] = single;
  ++index;
}


void PIRDevice::sendCommandToDevice()
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
#else
  if (write(fileDescriptor, buffer, index * sizeof(int)) == -1)
  {
    std::stringstream ss;
    ss << "Failed to send command.\n";
    ss << "IR device returned error: " << strerror(errno) << "\n";
    throw PIRException(ss.str());
  }
#endif // DEBUGGING

  // Reset the index:
  index = 0;
}


void PIRDevice::setCarrierFrequency(
  unsigned int frequency)
{
//  if (!frequency) frequency = DEFAULT_FREQUENCY;

#ifdef DEBUGGING
  std::cout << "Setting frequency to " << frequency << "\n";
#else
  if (ioctl(fileDescriptor, _IOW('i', 0x13, __u32), &frequency) == -1)
  {
    std::stringstream ss;
    ss << "Failed to set carrier frequency.\n";
    ss << "IR device returned error: " << strerror(errno) << "\n";
    throw PIRException(ss.str());
  }
#endif // DEBUGGING
}


void PIRDevice::setDutyCycle(
  unsigned int dutyCycle)
{
//  if (dutyCycle > 100) dutyCycle = DEFAULT_DUTY_CYCLE;

#ifdef DEBUGGING
  std::cout << "Setting duty cycle to " << dutyCycle << "\n";
#else
  if (ioctl(fileDescriptor, _IOW('i', 0x15, __u32), &dutyCycle) == -1)
  {
    std::stringstream ss;
    ss << "Failed to set duty cycle percentage.\n";
    ss << "IR device returned error: " << strerror(errno) << "\n";
    throw PIRException(ss.str());
  }
#endif // DEBUGGING
}
