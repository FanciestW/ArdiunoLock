#include <Servo.h>
Servo servo;

const int servoPin = 11;
const int btnOpen = 10;
const int btnClose = 9;
const int angleOpen = 95;
const int angleClose = 5;

void setup(){
  Serial.begin(9600);
  servo.attach(servoPin);
  servo.write(5);
  pinMode(btnOpen, INPUT_PULLUP);
  pinMode(btnClose, INPUT_PULLUP);
}

void loop(){
  if(digitalRead(btnOpen) == LOW){
    opened();
  }
  else if(digitalRead(btnClose) == LOW){
    closed();
  }
  else{
  }
}

void opened(){
  servo.write(angleOpen);
}

void closed(){
  servo.write(angleClose);
}
  
  
