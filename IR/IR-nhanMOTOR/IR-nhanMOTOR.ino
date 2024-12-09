#include <IRremote.hpp>
#include <Servo.h>


#define IR_RECEIVE_PIN 2      // Chân nhận tín hiệu hồng ngoại
const int motorAPin = 9;   // IN1 - D9
const int motorBPin = 8;
IRrecv receiver(IR_RECEIVE_PIN); // Khởi tạo đối tượng IRrecv

void setup() {
  pinMode(motorAPin, OUTPUT);
  pinMode(motorBPin, OUTPUT); 

  Serial.begin(9600);      

  receiver.enableIRIn();         // Bắt đầu nhận tín hiệu IR
  Serial.println(F("Ready to receive IR signals"));
}

void loop() {
    if (receiver.decode()) { 
        uint32_t value = receiver.decodedIRData.command; 
        Serial.print("Received value: ");
        Serial.println(value, HEX); // In giá trị nhận được dưới dạng hex

        if (value == 0x01) { // Nếu nhận được mã 0x01
          digitalWrite(motorAPin, HIGH);
          digitalWrite(motorBPin, LOW);
        } else if (value == 0x00) { // Nếu nhận được mã 0x00
          digitalWrite(motorAPin, LOW);
          digitalWrite(motorBPin, HIGH); 
        }

        receiver.resume(); // Chuẩn bị cho lần nhận tiếp theo
    }
}
