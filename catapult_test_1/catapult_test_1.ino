

#include<Servo.h>
#include<Stepper.h>

Servo myservo;  //create servo object to control lock and release

int pos = 0;    // variable to store the servo position

const int stepsPerRevolution = 200; //change this to fit the number of steps per revolution

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
  digitalWrite(EnA,HIGH);
  digitalWrite(EnB,HIGH);

  myservo.attach(10);  // attaches the servo on pin 10 to the servo object
}

void loop() {

  
  /////////////step 1______unwind (to loading position) 
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution*9);  //motor runs nine rotations, pulley runs three
  delay(3000);
  
  /////////////step 2_______ position locked
  Serial.println("Lock"); 
  for (pos = 0; pos <= 120; pos += 1) { // goes from 0 degrees to 120 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  delay(2000);
  
  /////////////step 3________winding
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution*9);

  /////////////step 4________release
  Serial.println("Release");
  for (pos = 120; pos >= 0; pos -= 1) { // goes from 120 degrees to 0 degrees
   myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  delay(3000);




}
