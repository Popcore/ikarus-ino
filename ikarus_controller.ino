#include <Servo.h>
#include "Ultrasonic.h"

// motor A
const int motorPin1  = 2;  
const int motorPin2  = 3;

// motor B
const int motorPin3  = 4; 
const int motorPin4  = 5;  

// servo
Servo servo;
const int servoPin = 10; 
int servoPos = 0; // the servo position

void setup() {
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(servoPin, OUTPUT);
  
  Serial.begin(9600);
  servo.attach(servoPin);
}

void loop() {
  
  // control car direction
  if (Serial.available()) {
   
    char input = Serial.read();
    //controlDirection(input);
    
    Serial.println(input);
    
    controlDirection(input);
  }
  
  // control sensor servo position
  // moveServo(servoPos);
  
  // read from sensor
}

void controlDirection(char input) {
  switch(input) {
     case 'w':
       Serial.println("moveForward");
       moveForward();
       break;
     case 's':
       Serial.println("moveBackward");
       moveBackward();
       break;
     case 'a':
       Serial.println("turnLeft");
       turnLeft();
       break;
     case 'd':
       Serial.println("turnRight");
       turnRight();
       break;
     case 'h':
       moveStop();
       break;
     default:
       moveStop();
       break;
  }
  
  return;
}

void moveServo(int pos) {
  for (pos = 0; pos <= 180; pos++) {
    servo.write(pos); // move servo to pos
    delay(10); 
  }
  
  for (pos = 180; pos >= 0; pos--) {
    servo.write(pos); // move servo to pos
    delay(10); 
  }
}

void readFromSonicSensor() {
  
}

void moveStop() {
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 0);
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, 0);
  return;
} 
  
void turnLeft() {
  analogWrite(motorPin1, 100);
  analogWrite(motorPin2, 0);
  analogWrite(motorPin3, 100);
  analogWrite(motorPin4, 0);
  delay(100);
  return;
}

void turnRight() {
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 100);
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, 100);
  delay(100);
  return;
}  

void moveForward() {
  analogWrite(motorPin1, 100);
  analogWrite(motorPin2, 0);
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, 100);    
  delay(100);
  return;
} 
 
void moveBackward() {
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 100);   
  analogWrite(motorPin3, 100);
  analogWrite(motorPin4, 0);     
  delay(100);
  return;
}  


