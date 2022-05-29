// Light-based Theremin //

// Declare variable to store the photoresistor value:

int sensorValue;

// Declare variables to calibrate the low and high photoresistor values:

int sensorLow = 1023;
int sensorHigh = 0;

// Declare a constant variable to indicate completion of photoresistor calibration:

const int ledPin = 13;

// Set on the specified pin whether it should behave as an input or an output:

void setup() {

 pinMode(ledPin, OUTPUT); // Make the LED pin an output
 digitalWrite(ledPin, HIGH); // Turn the LED pin on

 // Calibrate the sensor minimums and maximums:

 while(millis() < 5000) {

  sensorValue = analogRead(A0);
  
  // Record the maximum sensor value:
  
  if (sensorValue > sensorHigh) {
    sensorHigh = sensorValue;
  }

  // Record the minimun sensor value:
  
  if(sensorValue > sensorLow) {
    sensorLow = sensorValue;
  }
 
 }

 // Turn the LED off, indicating the end of the calibration period:

  digitalWrite(ledPin, LOW);
}

// The loop routine that runs on and on:

void loop() {

  sensorValue = analogRead(A0); // Read the input from the photoresistor and store it in a varible

  // Declares a variable to store the mapping of sensor values:

  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);

  // Play the tone for 20 ms on the piezo:

  tone(8, pitch, 20);

  // Delay between reads:
  
  delay(10);
}
