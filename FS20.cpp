#include "Arduino.h"
#include "FS20.h"

FS20::FS20(char hc1, char hc2)
{
  _hc1 = hc1;
  _hc2 = hc2;
}

int FS20::send_cmd(char address, char command, char parameter)
{
  Serial2.write(0x2); // start char
  Serial2.write(0x6); // length of message is 6 chars
  Serial2.write(0xF1); // send command once and only once
  
  // send house code
  Serial2.write(_hc1);
  Serial2.write(_hc2);
  
  Serial2.write(address); // actor address
  Serial2.write(command); // command
  Serial2.write(parameter); // parameter
  
  return receive_feedback();
}

void FS20::reset()
{
}

int FS20::receive_feedback() {
  int remaining = 4;
  int status;
  while (remaining > 0 && Serial2.available() > 0) {
    // read the incoming byte:
    incoming_byte = Serial2.read();
    remaining = remaining - 1;
    if (remaining == 1) {
      status = incoming_byte;
    }
  }
  return status;
}
