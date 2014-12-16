#include <Servo.h>
Servo servo;

const int servoPin = 11;
const int btnOpen = 10;
const int btnClose = 9;
const int angleOpen = 95;
const int angleClose = 5;
const int code1Pin = 2;
const int code2Pin = 3;
const int code3Pin = 4;
const int code4Pin = 5;
static int code1;
static int code2;
static int code3;
static int code4;

void setup(){
  Serial.begin(9600);
  servo.attach(servoPin);
  servo.write(5);
  pinMode(btnOpen, INPUT_PULLUP);
  pinMode(btnClose, INPUT_PULLUP);
  pinMode(code1Pin, INPUT_PULLUP);
  pinMode(code2Pin, INPUT_PULLUP);
  pinMode(code3Pin, INPUT_PULLUP);
  pinMode(code4Pin, INPUT_PULLUP);
  code1 = 0;
  code2 = 0;
  code3 = 0;
  code4 = 0;
}

void loop(){
  if(digitalRead(btnOpen) == LOW){
    checkcode();
  }
  else if(digitalRead(btnClose) == LOW){
    closed();
  }
  else if(digitalRead(code1Pin) == LOW){
    if(code1 <= 3){
      code1++;
    }
    else{
      code1 = 0;
    }
  }
  else if(digitalRead(code2Pin) == LOW){
    if(code2 <= 3){
      code2++;
    }
    else{
      code2 = 0;
    }
  }
  else if(digitalRead(code3Pin) == LOW){
    if(code3 <= 3){
      code3++;
    }
    else{
      code3 = 0;
    }
  }
  else if(digitalRead(code4Pin) == LOW){
    if(code4 <= 3){
      code4++;
    }
    else{
      code4 = 0;
    }
  }
  else{
  }
}

void checkcode(){
  int yourCode1, yourCode2, yourCode3, yourCode4;
  //Change your codes:
  yourCode1 = 0;
  yourCode2 = 0;
  yourCode3 = 0;
  yourCode4 = 0;
  if(code1 == yourCode1){
    if(code2 == yourCode2){
      if(code3 == yourCode3){
        if(code3 == yourCode4){
          opened();
        }
        else{
        }
      }
      else{
      }
    }
    else{
    }
  }
  else{
  }
}

void opened(){
  servo.write(angleOpen);
}

void closed(){
  servo.write(angleClose);
  code1 = 0;
  code2 = 0;
  code3 = 0;
  code4 = 0;
}
  
  
