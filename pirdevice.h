#ifndef PIRDEVICE_H
#define PIRDEVICE_H

//
// Encapsulates communication with the N900's IR hardware, using the LIRC
// device that (hopefully) exists on all N900s.
//

// To my current knowledge, you can send a maximum of 256 integers to the 
// N900's IR device driver, so that's probably a good limit to set:
#define BUFFER_SIZE 256

class PIRDevice
{
public:
  PIRDevice();

  PIRDevice(
    unsigned int frequency,
    unsigned int dutyCycle);

  ~PIRDevice();

  // Most remotes will just want to append pairs of on/off times:
  void addPair(
    int pulse,
    int space);

  // Some remotes need to specify the switching values individually:
  void addSingle(
    int single);

  // Send the buffered pulses to the IR device:
  void sendCommandToDevice();

  void setCarrierFrequency(
    unsigned int frequency);

  void setDutyCycle(
    unsigned int dutyCycle);

private:
  void openLircDevice();

  int fileDescriptor;

  int buffer[BUFFER_SIZE];
  int index;
};

#endif // PIRDEVICE_H
