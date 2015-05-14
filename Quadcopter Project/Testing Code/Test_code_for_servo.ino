/*
  This code is to test the Arduino Pro Mini from Sparkfun.com on a 2 ESCs (Electronic Speed Controller) to power 2 or more electric motors spinning in opposite directions for a quadcopter project.
  This code is for testing purposes only and was copied from https://dronesandrovs.wordpress.com/2012/11/24/how-to-control-a-brushless-motor-esc-with-arduino/
*/

#include <Servo.h>
//#include <SoftwareSerial.h>
 int throttlePin1 = 0;
 int throttlePin2 = 1;
 int throttlePin3 = 2;
 int throttlePin4 = 3;
 Servo esc_1;
 Servo esc_2;
 Servo esc_3;
 Servo esc_4;
 
 void setup(){
  esc_1.attach(3);
  esc_2.attach(5);
  esc_3.attach(7);
  esc_4.attach(9);
 }
 
void loop()
{
int throttle1 = analogRead(throttlePin1);
//int throttle2 = analogRead(throttlePin2);
//int throttle3 = analogRead(throttlePin3);
//int throttle4 = analogRead(throttlePin4);
throttle1 = map(throttle1, 0, 1023, 0, 179);
//throttle2 = map(throttle2, 0, 1023, 0, 179);
//throttle3 = map(throttle3, 0, 1023, 0, 179);
//throttle4 = map(throttle4, 0, 1023, 0, 179);
esc_1.write(throttle1);
esc_2.write(throttle1);
esc_3.write(throttle1);
esc_4.write(throttle1);
}
