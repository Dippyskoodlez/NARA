  /*
   * Current code is legacy NARA for reference and porting purposes only.
   * 
   * 
   */
  
  
  //-------------------------------------------------------// 
  #include <AFMotor.h> //Adafruit motor header library: http://www.adafruit.com/products/81

//Motor Layout (Wiring specific)
  AF_DCMotor motorFL(4, MOTOR12_64KHZ);
  AF_DCMotor motorBL(1, MOTOR12_64KHZ); 
  AF_DCMotor motorFR(2, MOTOR12_64KHZ);  
  AF_DCMotor motorBR(3, MOTOR12_64KHZ);

  char rcvDirection = 0; // Forward (F), Backward(B), Neutral steer(N)
  int rcvSpeedL = 0; //0-255
  int rcvSpeedR = 0;
  bool validCmd = False;
 
 //-------------------------------------------------------// 
void  setup(){
  //Starts the serial connection
  Serial.begin(9600);
  Serial.write("Hello Dave.");
  //Turn on motors. (released state)
  motorFL.run(RELEASE);
  motorBL.run(RELEASE);
  motorFR.run(RELEASE);
  motorBR.run(RELEASE);
}
//-------------------------------------------------------// 
void loop(){ 
  //Reads the incoming command.
  ReadIncoming();
  //Executes the command. Fetch boy, fetch!
  ExecuteCommands();

}

/*--------------------------------------
  Process the proper axis for sending motor speeds, based on quadrant read.
  These are the Values that need SENT for proper motion, over the READ Values.
        (F)    (Y)   (F)
              (255)
        IV      |     I
    X:R Y:L     |  X:L Y:R
    X:-R  Y:L   |  X:L Y:R
(-X)(-255)-----------------(255-)(X)
        (B)     |    (B)
         III    |     II
     X:-R Y:-L  | X:-L Y:-R
     X:-R Y:-L  | X:L  Y:-R
             (-255)
              (-Y)
----------------------------------------*/

//-------------------------------------------------------// 
void ReadIncoming(){
  if (Serial.available()) {
    
  }
  while(validCmd == false) {
  //Read the incoming command, 1 byte, into memory to use as a command.
 rcvDirection = Serial.read();
 rcvSpeedL = Serial.read();
 rcvSpeedR = Serial.read();

//Verify valid direction and min/max speed recieved.
 if (rcvDirection == 'F' || 'B' || 'n'){
  if (rcvSpeedL >= 0 && rcvSpeedL <= 255){
    if rcvSpeedR >= 0 && rcvSpeedR <= 255) {
        validCmd = True ;
       }
     }
    }
  }

}
//-------------------------------------------------------// 
void ExecuteCommands(){
  
  //Translate the command into a direction. F/B: Fwd/reverse, L/R: Left, Right, l/r: reverse turn.
  switch(rcvDirection){
    //Checks the first byte recieved for the direction to start: Forward, Backward or Neutral steer.
    case 'F':
    // Reply with the direction intended to go
      Serial.println("GOING STRAIGHT AT:");
      Serial.println(rcvSpeedL, rcvspeedR);
      //Start moving with forward intent.
      GoForward(rcvSpeedL, rcvSpeedR);
      break;
    case 'B':
    //Reply with the direction to go
      Serial.println("GOING BACKWARDS AT:");
      Serial.println(rcvSpeedL, rcvSpeedR);
      //Start moving with backwards intent.
      GoBackwards(rcvSpeedL, rcvSpeedR);
      break;
    case 'N':
    // Dat neutral steer.
      Serial.println("NEUTRAL JUST KICKED IN YO")
      NeutralSteer(rcvSpeedL, rcvSpeedR);
      break;
  }
}
//-------------------------------------------------------// 
//Set motor driver to appropriate fwd speeds.
void GoForward(int FSpeedL, int FSpeedR){
  //seperates stop and go command.  Min/Max motor speeds here.
  
    motorFL.setSpeed(FSpeedL);
    motorBL.setSpeed(FSpeedL);
    motorFR.setSpeed(FSpeedR);
    motorBR.setSpeed(FSpeedR);
    motorFL.run(FORWARD);
    motorFR.run(FORWARD);
    motorBL.run(FORWARD);
    motorBR.run(FORWARD);
}
//-------------------------------------------------------// 
void GoBackwards(int FSpeedL, int FSpeedR){
  //Same as fwd, except reverse.
    motorFL.setSpeed(FSpeedL);
    motorBL.setSpeed(FSpeedL);
    motorFR.setSpeed(FSpeedR);
    motorBR.setSpeed(FSpeedR);
    motorFL.run(BACKWARD);
    motorFR.run(BACKWARD);
    motorBL.run(BACKWARD);
    motorBR.run(BACKWARD);
}
//-------------------------------------------------------// 
void NeutralSteer(int FSpeedL, int FSpeedR){

//Neutral Left
  //Negative X value, positive Y
if (FSpeedR <= -10 && FSpeedL >= 0){
    motorFL.setSpeed(FSpeedL);
    motorFR.setSpeed(FSpeedR);
    motorBL.setSpeed(FSpeedL);
    motorBR.setSpeed(FSpeedR);
    motorFL.run(RELEASE);
    motorFR.run(FORWARD);
    motorBL.run(RELEASE);
    motorBR.run(FORWARD);
}

//Neutral right
if (FSpeedL <= -10 && FSpeedR >= 0){
    motorFL.setSpeed(FSpeedL);
    motorFR.setSpeed(FSpeedR);
    motorBL.setSpeed(FSpeedL);
    motorBR.setSpeed(FSpeedR);
    motorFL.run(FORWARD);
    motorFR.run(RELEASE);
    motorBL.run(FORWARD);
    motorBR.run(RELEASE);
}
