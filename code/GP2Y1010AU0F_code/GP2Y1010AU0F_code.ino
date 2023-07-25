    /*
Refrains : https://create.arduino.cc/projecthub/mircemk/diy-air-quality-monitor-with-sharp-gp2y1010au0f-sensor-7b0262

From https://electropeak.com/learn/interfacing-gp2y1010au0f-optical-dust-sensor-module-with-arduino/

 Standalone Sketch to use with a Arduino UNO and a
 Sharp Optical Dust Sensor GP2Y1010AU0F
*/

int measurePin = A0; //Connect dust sensor to Arduino A0 pin
int ledPower = 2;   //Connect 3 led driver pins of dust sensor to Arduino D2

int samplingTime = 280;
int deltaTime = 40;
int sleepTime = 9680;

float voMeasured = 0;
float calcVoltage = 0;
float dustDensity = 0;

void setup(){
  Serial.begin(9600);
  pinMode(ledPower,OUTPUT);
}

void loop(){
  digitalWrite(ledPower,LOW); // power on the LED
  delayMicroseconds(samplingTime);

  voMeasured = analogRead(measurePin); // read the voltage
  
  delayMicroseconds(deltaTime);
  digitalWrite(ledPower,HIGH); // turn the LED off
  delayMicroseconds(sleepTime);

  // // 0 - 5V mapped to 0 - 1023 integer values
  // // recover voltage
  // calcVoltage = voMeasured * (5.0 / 1024.0);

  // Not clear why they do this re-scaling above...

  // linear eqaution taken from http://www.howmuchsnow.com/arduino/airquality/
  // Chris Nafis (c) 2012
  // in milligrams per cubic meter
  dustDensity = 0.172 * voMeasured - 0.0999;

  
  Serial.println(dustDensity); 
  Serial.println(voMeasured); 

  delay(1000);
}
