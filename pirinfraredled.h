//
// pirinfraredled.h
//
// Copyright 2012, 2013 by John Pietrzak  (jpietrzak8@gmail.com)
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

#ifndef PIRINFRAREDLED_H
#define PIRINFRAREDLED_H

//
// Encapsulates communication with the N900's IR hardware, using the LIRC
// device that (hopefully) exists on all N900s.
//

// To my current knowledge, you can send a maximum of 256 integers to the 
// N900's IR device driver, so that's probably a good limit to set:
#define BUFFER_SIZE 256

class PIRInfraredLED
{
public:
  PIRInfraredLED();

  PIRInfraredLED(
    unsigned int frequency,
    unsigned int dutyCycle);

  ~PIRInfraredLED();

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

#endif // PIRINFRAREDLED_H
