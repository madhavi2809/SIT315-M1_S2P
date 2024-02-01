const uint8_t BTN_PIN = 2;  // Digital Pin 2 is connected to the push button
const uint8_t LED_PIN = 13; // Digital Pin 13 is connected to the LED

uint8_t buttonPrevState = LOW; // Variable storing previous state of the button
uint8_t ledState = LOW;        // Variable storing current state of the LED
unsigned long prevDebounceTime = 0;  // Variable to store the last time the button state changed
unsigned long debounceDelay = 50; // Delay time to debounce the button (in milliseconds)

void setup()
{
  pinMode(BTN_PIN, INPUT_PULLUP); // Configuring the button pin as input with internal pull-up resistor
  pinMode(LED_PIN, OUTPUT);       // Configuring the LED pin as output
  Serial.begin(9600);             // Initializing serial communication at baud rate 9600
}

void loop()
{
  uint8_t buttonState = digitalRead(BTN_PIN); // Reading the current state of the button
  
  // If currrent state and previous state of the button are not same, then
  if (buttonState != buttonPrevState) {
    prevDebounceTime = millis(); // Debounce timer is reset
  }
  
  if ((millis() - prevDebounceTime) > debounceDelay) 
  {
    if (buttonState != buttonPrevState) {
      buttonPrevState = buttonState; // Update the button state only if the debounce delay has passed
      
      Serial.print(buttonPrevState);      // Printing the current state of the button
      Serial.print(ledState);             // Printing the current state of the LED
      Serial.println("");                 // Printing a newline to separate readings
      
      if (buttonPrevState == LOW)  // If button is pressed, then
      { 
        ledState = !ledState;      // Toggle the state of the LED
        digitalWrite(LED_PIN, ledState); // Update the LED with the new state
      }
    }
  }
}
