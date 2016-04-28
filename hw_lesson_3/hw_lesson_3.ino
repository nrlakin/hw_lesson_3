#include <Wire.h>
#include "rgb_led.h"
#include "accel_sensor.h"

void setup() {
  // put your setup code here, to run once:
  initRGB();
  initAccelSensor();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned char red;
  unsigned char green;
  unsigned char blue;
  accel_data_t AccelData;
  
  readAccelSensor(&AccelData);
  red = (unsigned char)(abs(AccelData.accel_X) >> 7); 
  green = (unsigned char)(abs(AccelData.accel_Y) >> 7); 
  blue = (unsigned char)(abs(AccelData.accel_Z) >> 7); 
  setRGB(red, green, blue);
  
  Serial.print("X: ");
  Serial.print(AccelData.accel_X);
  Serial.print(" Y: ");
  Serial.print(AccelData.accel_Y);
  Serial.print(" Z: ");
  Serial.println(AccelData.accel_Z);
  delay(50);
  
}
