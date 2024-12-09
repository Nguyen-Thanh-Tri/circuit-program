#include <DHT.h>
const int DHT11_PIN= 2 ; //chân D4
const int DHTTYPE = DHT11;
DHT dht(DHT11_PIN, DHTTYPE);

int speed = 200;  // Tốc độ động cơ ban đầu

const int motorAPin = 8;  // Chân IN1 của mô đun động cơ L298N
const int motorBPin = 9;  // Chân IN2 của mô đun động cơ L298N
// const int enablePin = 10;  // Chân ENA của mô đun động cơ L298N

void setup() {
  pinMode(motorAPin, OUTPUT);
  pinMode(motorBPin, OUTPUT);
  // pinMode(enablePin, OUTPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();    //Đọc độ ẩm
  float t = dht.readTemperature(); //Đọc nhiệt độ
if (isnan(h) || isnan(t)) {
    Serial.println("Lỗi khi đọc cảm biến DHT!");
    return;
}
  Serial.print("Nhiệt độ: ");
  Serial.print(t);
  Serial.print("°C, Độ ẩm: ");
  Serial.print(h);
  Serial.println("%");

  if (t > 28 && h > 70) {
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
