/* 

 Potentiometer with 5 LED’s
 Goal of the program : Uses the potentiometer value to decide how many LEDs should turn on at the same time.
 Main theme : Analog Input controlling LEDs.

*/

int sensorPin = A0;      // Sets the analog pin used to read the potentiometer
int sensorValue = 0;     // Stores the value read from the potentiometer


void setup() {

  pinMode(sensorPin, INPUT);   // Sets the potentiometer pin as an input
  Serial.begin(9600);          // Starts communication with the Serial Monitor


  // Sets the 5 LED pins as outputs
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
}


void loop() {

  sensorValue = analogRead(sensorPin);   // Reads the 10-bit value from the potentiometer (0–1023)
  Serial.println(sensorValue);           // Prints the value to the Serial Monitor

  // Each range from 0–1023 determines how many LEDs turn on at the same time
  if (sensorValue < 20) {
    digitalWrite(8, 0);
    digitalWrite(7, 0);
    digitalWrite(6, 0);
    digitalWrite(5, 0);
    digitalWrite(4, 0);
  }

  else if (sensorValue < 205) {
    digitalWrite(8, 1);
    digitalWrite(7, 0);
    digitalWrite(6, 0);
    digitalWrite(5, 0);
    digitalWrite(4, 0);
  }

  else if (sensorValue <= 410) {
    digitalWrite(8, 1);
    digitalWrite(7, 1);
    digitalWrite(6, 0);
    digitalWrite(5, 0);
    digitalWrite(4, 0);
  }

  else if (sensorValue <= 615) {
    digitalWrite(8, 1);
    digitalWrite(7, 1);
    digitalWrite(6, 1);
    digitalWrite(5, 0);
    digitalWrite(4, 0);
  }

  else if (sensorValue <= 820) {
    digitalWrite(8, 1);
    digitalWrite(7, 1);
    digitalWrite(6, 1);
    digitalWrite(5, 1);
    digitalWrite(4, 0);
  }

  else if (sensorValue <= 1023) {
    digitalWrite(8, 1);
    digitalWrite(7, 1);
    digitalWrite(6, 1);
    digitalWrite(5, 1);
    digitalWrite(4, 1);
  }

}

