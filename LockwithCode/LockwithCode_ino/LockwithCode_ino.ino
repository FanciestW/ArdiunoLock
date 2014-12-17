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
    delay(200);
  }
  else if(digitalRead(btnClose) == LOW){
    closed();
    delay(200);
  }
  else if(digitalRead(code1Pin) == LOW){
    if(code1 <= 8){
      code1++;
      Serial.println(code1);
      delay(200);
    }
    else{
      code1 = 0;
      Serial.println(code1);
      delay(200);
    }
  }
  else if(digitalRead(code2Pin) == LOW){
    if(code2 <= 8){
      code2++;
      Serial.println(code2);
      delay(200);
    }
    else{
      code2 = 0;
      Serial.println(code2);
      delay(200);
    }
  }
  else if(digitalRead(code3Pin) == LOW){
    if(code3 <= 8){
      code3++;
      Serial.println(code3);
      delay(200);
    }
    else{
      code3 = 0;
      Serial.println(code3);
      delay(200);
    }
  }
  else if(digitalRead(code4Pin) == LOW){
    if(code4 <= 8){
      code4++;
      Serial.println(code4);
      delay(200);
    }
    else{
      code4 = 0;
      Serial.println(code4);
      delay(200);
    }
  }
  else{
  }
}

void checkcode(){
  int yourCode1, yourCode2, yourCode3, yourCode4;
  //Change your codes:
  yourCode1 = 1;
  yourCode2 = 2;
  yourCode3 = 3;
  yourCode4 = 4;
  if(code1 == yourCode1){
    Serial.println("Code 1 Passed");
    if(code2 == yourCode2){
      Serial.println("Code 2 Passed");
      if(code3 == yourCode3){
        Serial.println("Code 3 Passed");
        if(code4 == yourCode4){
          Serial.println("Code 4 Passed");
          opened();
          delay(200);
        }
        else{
          Serial.println("Code4 Not Correct");
        }
      }
      else{
        Serial.println("Code3 Not Correct");
      }
    }
    else{
      Serial.println("Code2 Not Correct");
    }
  }
  else{
    Serial.println("Code1 Not Correct");
  }
}

void opened(){
  servo.write(angleOpen);
  Serial.println("Access Granted");
}

void closed(){
  servo.write(angleClose);
  Serial.println("Code Reseted");
  code1 = 0;
  code2 = 0;
  code3 = 0;
  code4 = 0;
}
