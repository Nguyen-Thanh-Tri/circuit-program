int gasPin = 0;  // A0

int val;
int speed = 200;

const int motorAPin = 9;   // IN1 - D9
const int motorBPin = 8;   // IN2 - D8
// const int enablePin = 10;  // ENA - D10

void setup() {
  pinMode(motorAPin, OUTPUT);
  pinMode(motorBPin, OUTPUT);
  // pinMode(enablePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(gasPin);
  Serial.println(val, DEC);
  if (val < 600) {
    digitalWrite(motorAPin, HIGH);
    digitalWrite(motorBPin, LOW);
    // analogWrite(enablePin, speed);
  } else {
    digitalWrite(motorAPin, LOW);
    digitalWrite(motorBPin, HIGH);
    // analogWrite(enablePin, speed);
  }
  delay(1000);
}
