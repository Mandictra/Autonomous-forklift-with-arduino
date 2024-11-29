#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>

// Right motor
int enableRightMotor = 3;
int rightMotorPin1 = 4;
int rightMotorPin2 = 6;
// Left motor
int enableLeftMotor = 5;
int leftMotorPin1 = 7;
int leftMotorPin2 = 8;
// DC motor
int Dcmotorpin1 = 9;
int Dcmotorpin2 = 10;

void setup() {
  pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);

  pinMode(enableLeftMotor, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);

  pinMode(Dcmotorpin1, OUTPUT);
  pinMode(Dcmotorpin2, OUTPUT);

  rotateMotor(0, 0);   
    
  Dabble.begin(9600, 1, 2);
  
}

void loop() {
  int rightMotorSpeed = 0;
  int leftMotorSpeed = 0;
  Dabble.processInput();

  // DC motor control with GamePad
  if (GamePad.isTrianglePressed()) {
    rotateDCMotor(true);
  } else if (GamePad.isCrossPressed()) {
    rotateDCMotor(false);
  } else {
    stopDCMotor();
  }

  // RC car control with GamePad
  if (GamePad.isUpPressed()) {
    rightMotorSpeed = 255;
    leftMotorSpeed = 255;
  } else if (GamePad.isDownPressed()) {
    rightMotorSpeed = -255;
    leftMotorSpeed = -255;
  } else if (GamePad.isLeftPressed()) {
    rightMotorSpeed = 255;
    leftMotorSpeed = 0;
  } else if (GamePad.isRightPressed()) {
    rightMotorSpeed = 0;
    leftMotorSpeed = 255;
  }

  rotateMotor(rightMotorSpeed, leftMotorSpeed);
}

void rotateDCMotor(bool direction) {
  if (direction) {
    digitalWrite(Dcmotorpin1, HIGH);
    digitalWrite(Dcmotorpin2, LOW);
  } else {
    digitalWrite(Dcmotorpin1, LOW);
    digitalWrite(Dcmotorpin2, HIGH);
  }
}

void stopDCMotor() {
  digitalWrite(Dcmotorpin1, LOW);
  digitalWrite(Dcmotorpin2, LOW);
}

void rotateMotor(int rightMotorSpeed, int leftMotorSpeed) {
  if (rightMotorSpeed < 0) {
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, HIGH);
  } else if (rightMotorSpeed >= 0) {
    digitalWrite(rightMotorPin1, HIGH);
    digitalWrite(rightMotorPin2, LOW);
  }

  if (leftMotorSpeed < 0) {
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, HIGH);
  } else if (leftMotorSpeed >= 0) {
    digitalWrite(leftMotorPin1, HIGH);
    digitalWrite(leftMotorPin2, LOW);
  }

  analogWrite(enableRightMotor, abs(rightMotorSpeed));
  analogWrite(enableLeftMotor, abs(leftMotorSpeed));
}
