/* 

 Delay problem :
 Goal of the program : Blink an LED and show the push button state on the Serial Monitor without using the delay() command.
 Main Theme : Creating a delay effect without stopping the whole program + Digital Input.

*/

int pushButton = 13;                // Sets the pin used for the push button (and reads its state)
const int ledPin = 2;               // Pin where the LED is connected
int ledState = LOW;                 // Stores whether the LED is currently on or off

unsigned long previousMillis = 0;   // Stores the last time the LED was updated
const long interval = 5000;         // Time interval (in ms) before the LED changes state


void setup() {

  Serial.begin(9600);               // Starts communication with the Serial Monitor
  pinMode(ledPin, OUTPUT);          // LED pin set as output
  pinMode(pushButton, INPUT);       // Push button pin set as input

}


void loop() {

  int buttonState = digitalRead(pushButton);   // Reads the state of the push button
  Serial.print("buttonState = ");              // Prints label for clarity
  Serial.println(buttonState);                 // Prints the push button value
  delay(1);                                    // Small delay for Serial Monitor stability


  unsigned long currentMillis = millis();      // Gets the current time since the program started


  // Checks if the amount of time passed is equal or greater than the set interval
  if (currentMillis - previousMillis >= interval) {

    previousMillis = currentMillis;            // Updates the saved time to the current moment

    // Toggles the LED state (if LOW -> HIGH, if HIGH -> LOW)
    if (ledState == LOW) {
      ledState = HIGH;
    } 
    else {
      ledState = LOW;
    }

    digitalWrite(ledPin, ledState);            // Applies the new LED state to the pin
  }


  Serial.println(ledState);                    // Prints the current LED state

}

