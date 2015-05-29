//This code requried some reading of a data sheet which can be found here,
//https://www.sparkfun.com/datasheets/Sensors/Accelerometer/ADXL345.pdf
#include "Wire.h"
#define accAdd 0x53 //Accelerometer address on I2C bus.
byte a, b, c, d, e, f;
int X, Y, Z;
void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
  Wire.beginTransmission(accAdd); // Starts the measure bit in the POWER_CTL register.
  Wire.write(0x2d);
  Wire.write(1 << 3);
  Wire.endTransmission();
}

void loop() {

 // put your main code here, to run repeatedly:
  Wire.beginTransmission(accAdd); //get the LSB of X-axis
  Wire.write(0x32);
  Wire.endTransmission();
  Wire.requestFrom(accAdd, 6);

  a = Wire.read(); // X-axis
  b = Wire.read();
 
  c = Wire.read(); // Y-axis
  d = Wire.read();

  e = Wire.read(); // Z-axis
  f = Wire.read();
  
  X = ((b << 8) | a); //combine to get a 10 bit value for X-axis
  Y = ((d << 8) | c); //combine to get a 10 bit value for Y-axis
  Z = ((f << 8) | e); //combine to get a 10 bit value for Z-axis
  
  Serial.print("X = ");
  Serial.print(X,DEC);
  Serial.print(" Y = ");
  Serial.print(Y);
  Serial.print(" Z = ");
  Serial.println(Z);
  delay(100);
}
