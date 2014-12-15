/*
  FS20.h - Library for using the FS20 UART Sender.
  Created by Masanori Fujita, 2011-01-19.
  Licensed under GPL.
*/

#ifndef FS20_h
#define FS20_h

const char CMD_OFF = 0x0;
const char CMD_ON = 0x10;
const char CMD_TOGGLE = 0x12;
    
class FS20
{
  public:
    
    /*
      Create an instance of the FS20 sender.
    */
    FS20(char hc1, char hc2);
  
    /*
      Send a command to an actor with the given address.
      The parameter is optional, depending on the command.
     */
    int send_cmd(char address, char command, char parameter);
  
    /*
      Reset the FS20 sender.
    */
    void reset();
  
  private:
    int receive_feedback();
  
    char _hc1;
    char _hc2;
    int incoming_byte;
};

#endif
