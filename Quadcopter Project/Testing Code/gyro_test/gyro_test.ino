//This code requried some reading of a data sheet which can be found here,
//https://www.sparkfun.com/datasheets/Sensors/Gyro/PS-ITG-3200-00-01.4.pdf
#include "Wire.h"
#define gyAddr 0x68 //Accelerometer address on I2C bus.
byte a, b, c, d, e, f;
float X, Y, Z;
int X_offset = -60, Y_offset = 0, Z_offset = 0;
float sensitivity = 14.375;
void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
  Wire.beginTransmission(gyAddr); // Starts the measure bit in the POWER_CTL register.
  Wire.write(0x16);
  Wire.write(3 << 3);
  Wire.endTransmission();
}

void loop() {

 // put your main code here, to run repeatedly:
  Wire.beginTransmission(gyAddr); //get the LSB of X-axis
  Wire.write(0x1D);
  Wire.endTransmission();
  Wire.requestFrom(gyAddr, 6);

  a = Wire.read(); // X-axis
  //a = ~a;
  //Serial.print("a = ");
 // Serial.print(a,BIN);
  b = Wire.read();
  //b = (~b + 1) - 60;
  //Serial.print(" b = ");
  //Serial.println(b,BIN);
 
  c = Wire.read(); // Y-axis
  d = Wire.read();

  e = Wire.read(); // Z-axis
  f = Wire.read();
  
  X = (~(((a << 8) | b) + 1) + X_offset) / sensitivity; //combine to get a 10 bit value for X-axis
  Y = (~(((c << 8) | d) + 1) + Y_offset) / sensitivity; //combine to get a 10 bit value for Y-axis
  Z = (~(((e << 8) | f) + 1) + Z_offset) / sensitivity; //combine to get a 10 bit value for Z-axis
  
  Serial.print("X = ");
  Serial.print(X,2);
  Serial.print(" Y = ");
  Serial.print(Y,2);
  Serial.print(" Z = ");
  Serial.println(Z,3);
  delay(100);
}
