// Define the pins connected to BTS7960
//For the Left Motors
const int R_EN_L = 2;
const int L_EN_L = 4;
const int RPWM_L = 3;
const int LPWM_L = 5;

//For the Right Motors
const int R_EN_R = 7;
const int L_EN_R = 8;
const int RPWM_R = 9;
const int LPWM_R = 10;


int command; //Int to store app command state.
int speed = 60; // 0 - 255.
int turnSpeed = 60; //0 - 255

// Define the LED pin
const int LED_PIN = 12;

void setup() {
  // Set the motor control pins as outputs
  //Left
  pinMode(R_EN_L, OUTPUT);
  pinMode(L_EN_L, OUTPUT);
  pinMode(RPWM_L, OUTPUT);
  pinMode(LPWM_L, OUTPUT);
  //Right
  pinMode(R_EN_R, OUTPUT);
  pinMode(L_EN_R, OUTPUT);
  pinMode(RPWM_R, OUTPUT);
  pinMode(LPWM_R, OUTPUT);

  // Set the LED pin as an output
  pinMode(LED_PIN, OUTPUT);

  // Initialize Left motor control pins
  digitalWrite(R_EN_L, HIGH);
  digitalWrite(L_EN_L, HIGH);

  // Initialize Right motor control pins
  digitalWrite(R_EN_R, HIGH);
  digitalWrite(L_EN_R, HIGH);

  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
  
}
// void loop(){
//   forward();
//   blinkLED(500, 3);
// }

// void loop() {
//   // Move the motor forward
//   forward();
//   delay(2000);

//   // Blink the LED while moving forward
//   blinkLED(500, 3);

//   // Stop the motor
//   stopMotor();
//   delay(1000);

//   // Move the motor backward
//   backward();
//   delay(2000);

//   // Blink the LED while moving backward
//   blinkLED(500, 3);

//   // Stop the motor
//   stopMotor();
//   delay(1000);
// }

void loop() {

  if (Serial.available() > 0) {
    command = Serial.read();
    Serial.println(command);
    stopMotor(); //Initialize with motors stoped.
    digitalWrite(LED_PIN, LOW);

    switch (command) {
      case 'F':
        forward();
        break;
      case 'B':
        backward();
        break;
      case 'L':
        left();
        break;
      case 'R':
        right();
        break;
      case 'G':
        left();
        break;
      case 'I':
        right();
        break;
      case 'H':
        right();
        break;
      case 'J':
        left();
        break;
      case '0':
        speed = 30;
        turnSpeed = 60;
        break;
      case '1':
        speed = 50;
        turnSpeed = 70;
        break;
      case '2':
        speed = 80;
        turnSpeed = 80;
        break;
      case '3':
        speed = 110;
        turnSpeed = 95;
        break;
      case '4':
        speed = 135;
        turnSpeed = 115;
        break;
      case '5':
        speed = 165;
        turnSpeed = 130;
        break;
      case '6':
        speed = 185;
        turnSpeed = 145;
        break;
      case '7':
        speed = 200;
        turnSpeed = 160;
        break;
      case '8':
        speed = 215;
        turnSpeed = 170;
        break;
      case '9':
        speed = 230;
        turnSpeed = 180;
        break;
      case 'q':
        speed = 240;
        turnSpeed = 190;
        break;
    }
  }
}

// Function to move the motor forward
void forward() {
  digitalWrite(LED_PIN, HIGH);
  analogWrite(RPWM_L, speed);    
  analogWrite(LPWM_L, 0);  

  analogWrite(RPWM_R, speed);    
  analogWrite(LPWM_R, 0);  
}

// Function to move the motor backward
void backward() {
  digitalWrite(LED_PIN, HIGH);
  analogWrite(RPWM_L, 0);      
  analogWrite(LPWM_L, speed);    

  analogWrite(RPWM_R, 0);      
  analogWrite(LPWM_R, speed);     
}

void left() {
  digitalWrite(LED_PIN, HIGH);
  analogWrite(RPWM_L, 0);      
  analogWrite(LPWM_L, turnSpeed);  

  analogWrite(RPWM_R, turnSpeed);      
  analogWrite(LPWM_R, 0);     
}

void right() {
  digitalWrite(LED_PIN, HIGH);
  analogWrite(RPWM_L, turnSpeed);   
  analogWrite(LPWM_L, 0);    

  analogWrite(RPWM_R, 0);   
  analogWrite(LPWM_R, turnSpeed);   
}

// Function to stop the motor
void stopMotor() {
  analogWrite(RPWM_L, 0);     
  analogWrite(LPWM_L, 0);  

  analogWrite(RPWM_R, 0);     
  analogWrite(LPWM_R, 0);  
}

// Function to blink the LED
void blinkLED(int duration, int repetitions) {
  for (int i = 0; i < repetitions; ++i) {
    digitalWrite(LED_PIN, HIGH);
    delay(duration);
    digitalWrite(LED_PIN, LOW);
    delay(duration);
  }
}