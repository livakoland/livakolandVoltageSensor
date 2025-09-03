#include "livakolandVoltageSensor.h"

livakolandVoltageSensor sensor(A0, 3.3, 1.28, 6.2);

void setup() {
  Serial.begin(115200);
  sensor.begin();
}

void loop() {
  float vin = sensor.readVoltage();
  float vpin = sensor.readPinVoltage();
  int adc = sensor.readADC();
  
  Serial.print("ADC: ");
  Serial.print(adc);
  Serial.print(" | Vpin: ");
  Serial.print(vpin, 3);
  Serial.print("V | Vin: ");
  Serial.print(vin, 2);
  Serial.println("V");
  
  delay(1000);
}
