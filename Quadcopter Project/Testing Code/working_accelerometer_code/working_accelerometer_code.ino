//This code requried some reading of a data sheet which can be found here,
//https://www.sparkfun.com/datasheets/Sensors/Accelerometer/ADXL345.pdf
#include "Wire.h"
#define accAdd 0x53 //Accelerometer address on I2C bus.
byte a, b, c, d, e, f;
int X, Y, Z;
float Rx, Ry, Rz;
float R;
int X_offset = -5, Y_offset = -5, Z_offset = 40;
float sensitivity = 256.0;
float Ax, Ay, Az;
float pi = 3.14159;
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
  
  Wire.beginTransmission(accAdd); //Start at the DATAX0 register every time we loop
  Wire.write(0x32);
  Wire.endTransmission();
  Wire.requestFrom(accAdd, 6);

  a = Wire.read(); // gets register DATAX0 (LSB)
  b = Wire.read(); // and DATAX1 (MSB)
 
  c = Wire.read(); // gets register DATAY0
  d = Wire.read(); // and DATAY1

  e = Wire.read(); // gets register DATAZ0
  f = Wire.read(); // and DATAZ1
  
  X = (~((b << 8) | a) + 1) + X_offset; //combine to get a 10 bit value for X-axis
  Y = (~((d << 8) | c) + 1) + Y_offset; //combine to get a 10 bit value for Y-axis
  Z = (~((f << 8) | e) + 1) + Z_offset; //combine to get a 10 bit value for Z-axis
 
 Rx = X / sensitivity; //get g force
 Ry = Y / sensitivity;
 Rz = Z / sensitivity;
 
 R = sqrt(sq(Rx) + sq(Ry) + sq(Rz));
 Ax = ((acos(Rx/R) * 180) / pi) - 90; //returns the angle in radians between 0 and pi
 Ay = ((acos(Ry/R) * 180) / pi) - 90;
 Az = ((acos(Rz/R) * 180) / pi) - 90;
 
  Serial.print("X = ");
  Serial.print(Ax,2);
  Serial.print(" Y = ");
  Serial.print(Ay,2);
  Serial.print(" Z = ");
  Serial.print(Az,2);
  Serial.print(" R = ");
  Serial.println(R);
  delay(100);
}
