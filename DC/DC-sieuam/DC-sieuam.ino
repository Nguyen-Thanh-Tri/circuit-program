const int trigPin = 3;  //chân D3
const int echoPin = 5;  //chân D5

long duration;
int distance;
int speed = 200;

const int motorAPin = 8;
const int motorBPin = 9;
const int enablePin = 10;


void setup() {
  pinMode(motorAPin, OUTPUT);
  pinMode(motorBPin, OUTPUT);
  pinMode(enablePin, OUTPUT);
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
  Serial.println("cm");
  if (distance < 30) {
    digitalWrite(motorAPin, HIGH);
    digitalWrite(motorBPin, LOW);
    analogWrite(enablePin, speed);
  } else {
    digitalWrite(motorAPin, LOW);
    digitalWrite(motorBPin, HIGH);
    analogWrite(enablePin, speed);
  }
  delay(500);
}
