/*This is the primary Processing sketch for NARA control via xBee and an Xbox One controller.
*/

import processing.serial.*;

Serial Xbee;               //Name of our output via serial
double SendInterval = 100; //How often to send, changed or not
double LastSend;           //Global variable to track how long since our last transmit
int axisX;
int axisY;
int lastaxisX;
int lastaxisY;
int invertaxis;
char spideysense;
double CurrentTime;

// --------------------- XBOX One Controls -------------
//Left Analog will provide primary movement. X axis will dictate forward/reverse, and Y will throttle the opposite side resulting in a turn.


// -------SETUP ------
void setup(){
  
  Xbee = new Serial(this, Serial.list()[0],9600);

}


// ------ MAIN LOOP ------
void draw(){

CurrentTime = millis();

ReadController(); 
ProcessController();
SendData();       // Sends the bot the information.

}
// -------- GET CONTROLLER STATE -------
void ReadController(){

/* DEBUG AXIS PRINTING ---
println(axisX);
println(axisY);
println();
//----END DEBUG PRINTING ---*/

} //CURLY BRACKET FOR READCONTROLLER()

void ProcessController(){
    /*--------------------------------------
  Process the proper axis for sending motor speeds, based on quadrant read.
  These are the Values that need SENT for proper motion, over the READ Values.
          D     Y     A
         IV     |     I
    X:R Y:L     |  X:L Y:R
    X:-R  Y:L   |  X:L Y:R
 -X ----------------------- X
          C     |      B
         III    |     II
     X:-R Y:-L  | X:-L Y:-R
     X:-R Y:-L  | X:L  Y:-R
               -Y
  ----------------------------------------*/
    
//Motor 0 becomes byte 1 (Axis X) Motor 1 becomes byte 2 (Axis Y)
 
  //Quadrant I Logic
  if (axisX > 0 && axisY >0){
      spideysense = 'A';
    }
  //Quadrant II Logic
  else if (axisX > 0 && axisY < 0){
      spideysense = 'B';
    }
  
  //Quadrant III Logic
  else if (axisX < 0 && axisY < 0) {
      spideysense = 'C';  
    }
  
  //Quadrant IV Logic
  else if (axisX < 0 && axisY > 0){
      spideysense = 'D';  
    }
  
  }
  

// ------ SEND THAT DATA, YO ----------
void SendData(){
//compare last sent array to current
if(axisX != lastaxisX || axisY != lastaxisY){
    SendCommand(spideysense,axisX,axisY);
    lastaxisX = axisX;
    lastaxisY = axisY;
    LastSend = CurrentTime;
    //Debug: This line tells you if it is reading the control pad correctly. (Changing state)
    //println("DIFFERENT");
    }
  else if((CurrentTime - LastSend) > SendInterval){
    if(axisX == lastaxisX && axisY == lastaxisY){
    SendCommand(spideysense,axisX,axisY);
    lastaxisX = axisX;
    lastaxisY = axisY;
    LastSend = CurrentTime;
    //Debug: This line tells you if it is reading the control pad correctly. (and seeing a constant state)
    //println("SAME");
    
    }
  }

}
void SendCommand(char value1, int value2, int value3){

      Xbee.write(value1);
      Xbee.write(value2);
     println(value1);
     println(value2);

     

}
