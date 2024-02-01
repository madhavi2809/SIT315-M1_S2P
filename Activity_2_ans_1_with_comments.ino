const uint8_t BTN_PIN = 2;  // Digital Pin 2 is connected to the push button
const uint8_t LED_PIN = 13; // Digital Pin 13 is connected to the LED

uint8_t buttonPrevState = LOW; // Variable storing previous state of the button
uint8_t ledState = LOW;        // Variable storing current state of the LED

void setup()
{
  pinMode(BTN_PIN, INPUT_PULLUP); // Configuring the button pin as input with internal pull-up resistor
  pinMode(LED_PIN, OUTPUT);       // Configuring the LED pin as output
  Serial.begin(9600);             // Initializing serial communication at baud rate 9600
}

void loop()
{
  uint8_t buttonState = digitalRead(BTN_PIN); // Reading the current state of the button
  
  Serial.print(buttonState);      // Printing the current state of the button
  Serial.print(buttonPrevState);  // Printing the previous state of the button
  Serial.print(ledState);         // Printing the current state of the LED
  Serial.println("");             // Printing a newline to separate readings
  
  // If currrent state and previous state of the button are not same, then
  if(buttonState != buttonPrevState)
  {
    ledState = !ledState;         // State of LED is toggled
    digitalWrite(LED_PIN, ledState); // State of LED is updated to the new one
  }
  
  buttonPrevState = buttonState;  // Previous state of LED is updated with its current state
  
  delay(500); // Adding a delay to avoid rapid switching due to button bounce
}
