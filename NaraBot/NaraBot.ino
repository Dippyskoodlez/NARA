/*
 N.A.R.A.
 This file is the primary software for the Arduino controlling the robot.
 Multiple serial ports requires either the use of altSoftSerial for an Uno (May have performance issues),
 or an Arduino Mega/2560 for the multiple serial connections. 
/*-------------------PINOUTS-------------------------------*/
/*
 * 
 * Arduino Mega serial pins:
 * Serial: 0 (RX) and 1 (TX); Serial 1: 19 (RX) and 18 (TX); Serial 2: 17 (RX) and 16 (TX); 
 * Serial 3: 15 (RX) and 14 (TX). Used to receive (RX) and transmit (TX) TTL serial data.
                       Xbee
                 ------------------
                     D0 - RX
                     D1 - TX

                   Qik 2s12v10
DO NOT connect the 5V output on the Arduino to the 5V output on the qik 2s12v10!
            ---------------------------
                    Arduino - Qik
                    GND - GND
              Digital Pin 19 - TX
              Digital Pin 18 - RX
              Digital Pin 2 - RESET

*/
/*-------------------END PINOUTS-------------------------------*/
  
#include <SoftwareSerial.h>
#include <PololuQik.h>

//Serial connections on pins 19 and 18
PololuQik2s12v10 qik(19, 18, 2);

  int rcvSpeedL = 0; //0-127
  int rcvSpeedR = 0;
  bool validCmd = False;
 
 //-------------------------------------------------------// 
void  setup(){

  //Serial is for xbee communication and serial1 is for Qik communication.
  Serial.begin(9600);
  Serial.println("Welcome to N.A.R.A.");
  Serial1.begin(115200);
  Serial.println("qik 2s12v10 dual serial motor controller");
  
  qik.init();
  
  Serial.print("Firmware version: ");
  Serial.write(qik.getFirmwareVersion());
  Serial.println();
}
//-------------------------------------------------------// 
void loop(){ 

  //Read the incoming command, 1 byte, into memory to use as a command.
  rcvSpeedL = Serial1.read();
  rcvSpeedR = Serial1.read();

//Verify valid direction and min/max speed recieved.
//Min and max values for the Qik 12v10 is -127 to 127.

  if (rcvSpeedL >= -127 && rcvSpeedL <= 127){
    if rcvSpeedR >= -127 && rcvSpeedR <= 127) {

        //  Serial.println("I have a good command!");
          //There are two different channels on the Qik12v10, M0 and M1. This assumed 0 is left, and 1 is right.
          qik.setM0Speed(FSpeedL);
          qik.setM1Speed(FSpeedR);
          /*
          Future use for OSD
          Serial.print("M1 current: ");
          Serial.println(qik.getM0CurrentMilliamps());
          Serial.print("M1 current: ");
          Serial.println(qik.getM0CurrentMilliamps());
          */
       }
     }
    }
