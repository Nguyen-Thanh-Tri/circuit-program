const int line = 3;

long duration;
int distance;
int speed = 200;

const int motorAPin = 8;
const int motorBPin = 9;
// const int enablePin = 10;


void setup() {
  pinMode(motorAPin, OUTPUT);
  pinMode(motorBPin, OUTPUT);
  pinMode(line,INPUT);
  // pinMode(enablePin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
 int lineState = digitalRead(line);
  Serial.print("STATE ");
  Serial.println(lineState);
//đen = k co phản xạ. trắng= có phản xa
  if (lineState ==1) 
  {
    digitalWrite(motorAPin, HIGH);
    digitalWrite(motorBPin, LOW);
    // analogWrite(enablePin, speed);
  } else //trắng
  {
    digitalWrite(motorAPin, LOW);
    digitalWrite(motorBPin, HIGH);
    // analogWrite(enablePin, speed);
  }
  delay(500);
}
