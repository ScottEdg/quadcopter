//This code is for testing and implementing a Kalman Filter for use with an accelerometer and Gyroscope.
//equations and an overall guide on the Kalman Filter can be found here:
//http://blog.tkjelectronics.dk/2012/09/a-practical-approach-to-kalman-filter-and-how-to-implement-it/

int Old_AngleX = 0;
int Old_RateX = 0;
int GryoX; //this will be the current reading of the Gyroscope
int driftX = 0;
int New_driftX;
int New_AngleX, Old_RateX
int interval = 10; //in ms, used for time delay
float dt = interval/1000; // used for Kalman Filter estimation

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

  // Current Estimate based on the previous system (aka previous data)
  // Step 1 /////////////////////////////////////////////////////////
  rate = newRate - bias;
  angle += dt * rate; // This equation represents a new estimation given data from the last iteration
  ///////////////////////////////////////////////////////////////////
  // Step 2 /////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////
}
