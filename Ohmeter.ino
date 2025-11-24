/* 

 Ohmmeter :
 Goal of the program : Measures the resistance of an unknown resistor and displays the value in ohms on the Serial Monitor. 
 Main theme : Analog Input 

*/

int sensorPin = A0;      // Selects the analog pin where the voltage divider output is read  
int sensorValue = 0;     // Stores the raw analog value coming from the circuit


void setup() {

  Serial.begin(9600);          // Starts communication with the Serial Monitor at 9600 baud
  pinMode(sensorPin, INPUT);   // Sets the analog pin as an input so the Arduino can read the voltage

}


void loop() {

  sensorValue = analogRead(sensorPin);   // Reads the voltage divider output (0–1023)

  // Calculates the voltage at the analog pin using the 5V reference
  float voltage = sensorValue * (5.0 / 1023.0);

  // Uses Ohm’s Law to find current through the known resistor (9.94 ohms is the measured real value)
  float I = (5.0 - voltage) / 9.94;

  // Calculates the resistance of the unknown resistor using the voltage drop across it
  float R2 = voltage / I;

  Serial.print("R2 = ");   // Label for the output
  Serial.println(R2);      // Displays the calculated resistance in ohms

}

