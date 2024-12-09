#include <Stepper.h>
const int trigPin = 3;  //chân D3
const int echoPin = 5;  //chân D5
long duration;
int distance;
const int stepsPerRevolution = 2038;


// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
    myStepper.setSpeed(15);
    Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance Measured=");
  Serial.print(distance);
  Serial.print("cm");
  Serial.print("    |    ");


  if (distance < 30){
    myStepper.step(stepsPerRevolution/4);// 360/4 = 90
    Serial.println("Rotate : 90 ");
    delay(1000);
  }

  // myStepper.step(stepsPerRevolution/6);// 360/6 = 60
  // Serial.println("Rotate : 60 ");
	// delay(1000);
	
	// myStepper.step(stepsPerRevolution/8);// 360/8 = 45
  // Serial.println("Rotate : 45 ");
	// delay(1000);
else{
  myStepper.step(stepsPerRevolution/12);// 360/12 = 30
  Serial.println("Rotate : 30 ");
	delay(1000);}
	
}