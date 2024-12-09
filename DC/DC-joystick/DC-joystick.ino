int JoyStick_X = A1;
int JoyStick_Y = A0;
int JoyStick_Z = 3;

int speed = 200;

const int motorAPin = 8;   // IN1 - D8
const int motorBPin = 9;   // IN2 - D9
// const int enablePin = 10;  // ENA - D10

void setup() {
  pinMode(motorAPin, OUTPUT);
  pinMode(motorBPin, OUTPUT);
  pinMode(JoyStick_Z, INPUT_PULLUP);
  // pinMode(enablePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int x = analogRead(JoyStick_X);
  int y = analogRead(JoyStick_Y);
  int z = digitalRead(JoyStick_Z);

  Serial.print("X: ");
  Serial.print(x);
  Serial.print("   |   ");
  Serial.print(" Y: ");
  Serial.print(y);
   Serial.print("   |   ");
  Serial.print(" Z: ");
  Serial.println(z);


  if (x > 700 && y>700) {  // 
    digitalWrite(motorAPin, HIGH);
    digitalWrite(motorBPin, LOW);
    // analogWrite(enablePin, speed);
    delay(1000);
  } else if(z==1){
    digitalWrite(motorAPin, HIGH);
    digitalWrite(motorBPin, LOW);
    delay(1000);
  }else {  // tối, động cơ sẽ quay ngược chiều kim đồng hồ
    digitalWrite(motorAPin, LOW);
    digitalWrite(motorBPin, HIGH);
    // analogWrite(enablePin, speed);
    delay(1000);
  }
  delay(1000);
}
