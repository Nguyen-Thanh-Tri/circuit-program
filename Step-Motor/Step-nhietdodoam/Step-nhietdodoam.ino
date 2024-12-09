#include <DHT.h>
#include <Stepper.h>
const int DHT11_PIN= 2 ; //chân D2
const int DHTTYPE = DHT11;
DHT dht(DHT11_PIN, DHTTYPE);

const int stepsPerRevolution = 2038;


// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
    myStepper.setSpeed(15);
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
  Serial.print("%");
  Serial.print("   |   ");


  if (t > 28 && h > 70){
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