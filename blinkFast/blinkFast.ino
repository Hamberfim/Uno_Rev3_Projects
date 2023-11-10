// Blink Without using delay() : No other reading of sensors, mathematical calculations, or pin manipulation can go on during the delay function
// create constants, constants won't change:
// set the pin value
// LED_BUILTIN represent pin 13 in the lib/hardware API
// const int ledPin = LED_BUILTIN;
// LED represents the LED 6 on the seeed/grove sensor board
#define LED 6  // define which led to use
const int ledPin = LED;

// interval at which to blink in milliseconds
const long interval = 250;

// builtin led power variable, to set its state
int ledState = LOW;

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;

void setup() {
  // put your setup code here, to run once:
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  // Is it time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;  // sets the voltage to high (on)
    } else {
      ledState = LOW;  // sets the votage to low (off)
    }

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }
}
