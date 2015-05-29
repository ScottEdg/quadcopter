/*
  This code is to test the Arduino Pro Mini from Sparkfun.com on a ESC (Electronic Speed Controller) to power an electric motor for a quadcopter project.
 This code is for testing purposes only and is for development for the calibration stage.

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
  
    while(1){  //
      esc_1.write(rpm);  // Write value to the ESC.
      rpm = rpm + count; //changes speed
      delay(25);  //delay to control speed of cycle
        if(rpm==0||rpm==179){ //this code speeds up and slows down the motor in an endless cycle
          count = count * -1; //from experiementation 25 is the min running speed (ie slowest running speed).
          delay(2000);  // just for fun, wait 2 seconds at the end of each rise and fall of count.
        }
    }
  }
