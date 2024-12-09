///////////////////////////////////////////// GAS/////////////////////////////////////////////////////////////////////////////////////////////


// #include <IRremote.hpp>
// #define IR_SEND_PIN 3
//  IRsend sender;
// int gasPin = 0;
// void setup() {
//     Serial.begin(9600);
//     sender.begin(IR_SEND_PIN);
// }
// void loop() {
//    int val = analogRead(gasPin);  // Đọc giá trị điện áp chân A0 - chân cảm biến

//     Serial.print(val);
//     Serial.print("  |  "); // Xuất ra

//     if (val > 600) {
//             Serial.println(F("Sending command 0x01"));
//             sender.sendNEC(0x00, 0x01, 1);
//             delay(1000);}
//           else{
//             Serial.println(F("Sending command 0x00"));
//             sender.sendNEC(0x00, 0x00, 1);
//             delay(1000);
// }}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////// SIEU AM //////////////////////////////////////////////////////////////////////////////////


#include <IRremote.hpp>
#define IR_SEND_PIN 3
IRsend sender;

const int trigPin = 5;  //chân D5
const int echoPin = 6;  //chân D6
long duration;
int distance;
void setup() {
  Serial.begin(9600);
  sender.begin(IR_SEND_PIN);

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
  Serial.print("cm"); // Đọc giá trị điện áp chân A0 - chân cảm biến

  Serial.print("  |  "); // Xuất ra

  if (distance < 30) {
    Serial.println(F("Sending command 0x01"));
    sender.sendNEC(0x00, 0x01, 1);
    delay(1000);}
  else{
    Serial.println(F("Sending command 0x00"));
    sender.sendNEC(0x00, 0x00, 1);
    delay(1000);
}}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////// SIEU AM //////////////////////////////////////////////////////////////////////////////////