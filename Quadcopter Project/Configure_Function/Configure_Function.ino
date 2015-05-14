/*
  This code is to test the Arduino Pro Mini from Sparkfun.com on a ESC (Electronic Speed Controller) to power an electric motor for a quadcopter project.
 This code is for testing purposes only and is for development for the calibration stage and it's use will be used as a function in future project.

  Author: Scott Edgerly 
  Date: 1/5/2015
*/

#include <Servo.h>

Servo esc_1; 
int rpm = 1; //this needs to be one more than the min rpm value (default is set to 0)
int count = 1; //counter to adjust the rpm variable

  void setup(){
    esc_1.attach(9);//attachs the pwm signal to pin 9
  }
  
  void loop(){
    esc_1.write(179); // The following code is for congifuring the ESC and motor to the arduino
                      // The first step is to set the max value or in other words, max throttle.
    delay(2100);      // Then wait about 2 seconds to register the max value.
    esc_1.write(10);  // Set min or off value. In this case 10 is the lowest value that works reliably  
    delay(3500);      // wait about 3 seconds to register the min val and we are done.
  }
