/*
  Calibration

 Demonstrates one technique for calibrating sensor input.  The
 sensor readings during the first five seconds of the sketch
 execution define the minimum and maximum of expected values
 attached to the sensor pin.

 The sensor minimum and maximum initial values may seem backwards.
 Initially, you set the minimum high and listen for anything
 lower, saving it as the new minimum. Likewise, you set the
 maximum low and listen for anything higher as the new maximum.

 The circuit:
 * Analog sensor (potentiometer will do) attached to analog input 0
 * LED attached from digital pin 9 to ground

 created 29 Oct 2008
 By David A Mellis
 modified 30 Aug 2011
 By Tom Igoe
 adapted 5 Mar 2017
 By Flex Tio
 for usage in EG3792 Internet of Things Application Development module
 offered by Nanyang Polytechnic, School of Engineering

 http://www.arduino.cc/en/Tutorial/Calibration

 */

// These constants won't change:
const int SENSORPIN = A0;    // pin that the sensor is attached to

// variables:
int sensorValue = 0;         // the sensor value
int sensorMin = 1023;        // minimum sensor value
int sensorMax = 0;           // maximum sensor value

void setup() 
{
  Serial.begin(9600);

  //Set the sensor attached to pin A0 as an input
  pinMode(SENSORPIN, INPUT);

  //Ask the Arduino to wait for three seconds. 
  //Lit indicator for pin 13 will turn on once the time has passed.
  pinMode(13, OUTPUT);
  digitalWrite(13, 0);
  while(millis() < 3000);
  digitalWrite(13, 1);  
}

void loop() 
{
  sensorValue = analogRead(SENSORPIN);

  // record the maximum sensor value
  if (sensorValue > sensorMax) 
  {
    sensorMax = sensorValue;
  }

  // record the minimum sensor value
  if (sensorValue < sensorMin) 
  {
    sensorMin = sensorValue;
  }

  String measurementResult = "";
  measurementResult = "Empirical Values measured : Current - ";
  measurementResult = measurementResult + sensorValue;
  measurementResult = measurementResult + ", Max - ";
  measurementResult = measurementResult + sensorMax;
  measurementResult = measurementResult + ", Min - ";
  measurementResult = measurementResult + sensorMin;
  Serial.println(measurementResult);
}
