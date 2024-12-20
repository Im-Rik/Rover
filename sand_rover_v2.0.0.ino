#define in1 2   // Right
#define in2 3   // Right
#define in3 7   // Left
#define in4 8   // Left
#define enableA 5  // Right motors
#define enableB 6  // Left motors

int command; //Int to store app command state.
int Speed = 255; // 0 - 255.
int Speedsec;
int buttonState = 0;
int lastButtonState = 0;
int Turnradius = 150; //Set the radius of a turn, 0 - 255 Note:the robot will malfunction if this is higher than int Speed.
float turnRatio = 0.6;
int turnSpeed = 180;
int smoothTurnSpeed = 0;
int brakeTime = 45;
int brkonoff = 1; //1 for the electronic braking system, 0 for normal.

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enableA, OUTPUT);
  pinMode(enableB, OUTPUT);
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
    Serial.println(command);
    Stop(); //Initialize with motors stoped.
    switch (command) {
      case 'F':
        forward();
        break;
      case 'B':
        back();
        break;
      case 'L':
        left();
        break;
      case 'R':
        right();
        break;
      case 'G':
        left();
        // setSmoothTurn();
        // forwardleft();
        break;
      case 'I':
        right();
        // setSmoothTurn();
        // forwardright();
        break;
      case 'H':
        right();
        // setSmoothTurn();
        // backleft();
        break;
      case 'J':
        left();
        // setSmoothTurn();
        // backright();
        break;
      case '0':
        Speed = 100;
        turnSpeed = 180;
        break;
      case '1':
        Speed = 140;
        turnSpeed = 180;
        break;
      case '2':
        Speed = 153;
        turnSpeed = 180;
        break;
      case '3':
        Speed = 165;
        turnSpeed = 180;
        break;
      case '4':
        Speed = 178;
        turnSpeed = 180;
        break;
      case '5':
        Speed = 191;
        turnSpeed = 191;
        break;
      case '6':
        Speed = 204;
        turnSpeed = 204;
        break;
      case '7':
        Speed = 216;
        turnSpeed = 216;
        break;
      case '8':
        Speed = 229;
        turnSpeed = 229;
        break;
      case '9':
        Speed = 242;
        turnSpeed = 242;
        break;
      case 'q':
        Speed = 255;
        turnSpeed = 255;
        break;
    }
    // Speedsec = Turnradius;
    // Speedsec = (int)(turnRatio * Speed);
    if (brkonoff == 1) {
      brakeOn();
    } else {
      brakeOff();
    }
  }
}

void forward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enableA, Speed);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enableB, Speed);
}

void back() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enableA, Speed);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enableB, Speed);
}

void left() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enableA, turnSpeed);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enableB, turnSpeed);
}

void right() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enableA, turnSpeed);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enableB, turnSpeed);
}
// void forwardleft() {
// //  analogWrite(in1, Speed);
// //  analogWrite(in3, Speedsec);
//   digitalWrite(in1, LOW);
//   digitalWrite(in2, HIGH);
//   analogWrite(enableA, smoothTurnSpeed);

//   digitalWrite(in3, LOW);
//   digitalWrite(in4, HIGH);
//   analogWrite(enableB, Speedsec);
 
// }
// void forwardright() {
// //  analogWrite(in1, Speedsec);
// //  analogWrite(in3, Speed);
//   digitalWrite(in1, LOW);
//   digitalWrite(in2, HIGH);
//   analogWrite(enableA, Speedsec);

//   digitalWrite(in3, LOW);
//   digitalWrite(in4, HIGH);
//   analogWrite(enableB, smoothTurnSpeed);
// }
// void backright() {
//   digitalWrite(in1, HIGH);
//   digitalWrite(in2, LOW);
//   analogWrite(enableA, Speedsec);

//   digitalWrite(in3, HIGH);
//   digitalWrite(in4, LOW);
//   analogWrite(enableB, smoothTurnSpeed);
// }
// void backleft() {
//   digitalWrite(in1, HIGH);
//   digitalWrite(in2, LOW);
//   analogWrite(enableA, smoothTurnSpeed);

//   digitalWrite(in3, HIGH);
//   digitalWrite(in4, LOW);
//   analogWrite(enableB, Speedsec);
// }

void Stop() {
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);
  analogWrite(enableA, 0);
  analogWrite(enableA, 0);

}

// void setSmoothTurn(){
//   if(Speed < 154) smoothTurnSpeed = 180;
//   else if(Speed < 179) smoothTurnSpeed = 205;
//   else if(Speed < 205) smoothTurnSpeed = 230;
//   else smoothTurnSpeed = 255;
// }
void brakeOn() {
  //Here's the future use: an electronic braking system!
  // read the pushbutton input pin:
  buttonState = command;
  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == 'S') {
      if (lastButtonState != buttonState) {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, HIGH);
        delay(brakeTime);
        Stop();
      }
    }
    // save the current state as the last state,
    //for next time through the loop
    lastButtonState = buttonState;
  }
}
void brakeOff() {

}