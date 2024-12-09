#include <Stepper.h>

const int line = 3;
const int stepsPerRevolution = 2038;


// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
    myStepper.setSpeed(15);
    Serial.begin(9600);
}

void loop() {
	int lineState=digitalRead(line);
  Serial.print("STATE ");
  Serial.print(lineState);
  Serial.print("   |   ");
//đen = k co phản xạ. trắng= có phản xas
  if(lineState ==1){
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