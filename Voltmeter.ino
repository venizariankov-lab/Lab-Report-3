/* 

 Voltmeter : 
 Goal of the program : Measures the voltage coming into the analog pin and displays the result in volts on the Serial Monitor. 
 Main theme : Analog Input 

*/

int sensorPin = A0;      // Selects the analog pin where the voltage is being read
int sensorValue = 0;     // Creates a variable that will store the raw analog reading (0–1023)


void setup() {

  Serial.begin(9600);          // Starts communication with the Serial Monitor at 9600 baud
  pinMode(sensorPin, INPUT);   // Sets the input pin so the Arduino can measure the incoming voltage

}


void loop() {

  sensorValue = analogRead(sensorPin);   // Reads the analog value and converts it internally to a 10-bit number

  // Converts the raw value into an actual voltage using the formula based on a 5V reference
  float voltage = sensorValue * (5.0 / 1023.0);

  Serial.print("Voltage = ");   // Prints the label for clarity
  Serial.println(voltage);      // Prints the calculated voltage in volts

  delay(100);                   // Small delay so the readings appear smooth and readable

}
