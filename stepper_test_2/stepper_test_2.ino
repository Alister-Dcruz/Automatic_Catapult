
/*
 Stepper Motor Control - one revolution

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.

 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.


 Created 11 Mar. 2007
 Modified 30 Nov. 2009
 by Tom Igoe

 */

#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 7, 6, 5, 4);
#define EnA 3
#define EnB 2

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(150);
  // initialize the serial port:
  Serial.begin(9600);
  pinMode(EnA,OUTPUT);
  pinMode(EnB,OUTPUT);
}

void loop() {
  digitalWrite(EnA,HIGH);
  digitalWrite(EnB,HIGH);
  // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution*9);  //motor runs nine rotations, pulley runs three

  delay(2000);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  //motor runs nine rotations, pulley runs three
  myStepper.step(-stepsPerRevolution*9);
  delay(500);
  digitalWrite(EnA,LOW);
  digitalWrite(EnB,LOW);
  delay(7000);
}
