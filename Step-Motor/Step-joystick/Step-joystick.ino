#include <Stepper.h>
int JoyStick_X = A1;
int JoyStick_Y = A0;
int JoyStick_Z = 3;

const int stepsPerRevolution = 2038;


// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
    myStepper.setSpeed(15);
    pinMode(JoyStick_Z, INPUT_PULLUP);
    Serial.begin(9600);
  
}

void loop() {
  int x = analogRead(JoyStick_X);
  int y = analogRead(JoyStick_Y);
  int z = digitalRead(JoyStick_Z);
  Serial.print("X: ");
  Serial.print(x);
  Serial.print("  ");
  Serial.print(" Y: ");
  Serial.print(y);
   Serial.print("  ");
  Serial.print(" Z: ");
  Serial.print(z);


  if (x > 700 && y>700){
    myStepper.step(stepsPerRevolution/4);// 360/4 = 90
    Serial.println("Rotate : 90 ");
    delay(1000);
  }else if(z==1){

  myStepper.step(stepsPerRevolution/6);// 360/6 = 60
  Serial.println("Rotate : 60 ");
	delay(1000);
  }
	// myStepper.step(stepsPerRevolution/8);// 360/8 = 45
  // Serial.println("Rotate : 45 ");
	// delay(1000);
else{
  myStepper.step(stepsPerRevolution/12);// 360/12 = 30
  Serial.println("Rotate : 30 ");
	delay(1000);}
	
}