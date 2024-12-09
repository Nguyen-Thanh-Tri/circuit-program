int LIGHT = 0;  //A0

int val;
int speed = 200;

const int motorAPin = 9;   // IN1 - D9. Trái hay phải dựa vào 2 chân này. in1 tương ứng out1
const int motorBPin = 8;   // IN2 - D8
// const int enablePin = 10;  // ENA - D10

void setup() {
  pinMode(motorAPin, OUTPUT);
  pinMode(motorBPin, OUTPUT);
  // pinMode(enablePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(LIGHT);
  Serial.println(val);
  if (val > 700) {  // sáng, động cơ sẽ quay thuận chiều kim đồng hồ
    digitalWrite(motorAPin, HIGH);
    digitalWrite(motorBPin, LOW);
    // analogWrite(enablePin, speed);
    delay(1000);
  } else {  // tối, động cơ sẽ quay ngược chiều kim đồng hồ
    digitalWrite(motorAPin, LOW);
    digitalWrite(motorBPin, HIGH);
    // analogWrite(enablePin, speed);
    delay(1000);
  }
}
