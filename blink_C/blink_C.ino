// uses 176 bytes
#include <avr/io.h>      // defines i/o pins, ports etc.
#include <util/delay.h>  // time functions

/* There are two main steps for using digital inputs:
    1.) Set the direction of the pin to input
    2.) Read the value of the pin 
*/

int main() {
  // Data Direction Register B (DDRB): writing a 1 indicates that the pin is an output
  //DDRB |= (1<<PB5); // 1.) set the direction of the pin
  DDRB |= _BV(DDB5);  // _BV macro which converts a bit number into a byte value
                      // Event loop
  while (1) {
    // PORTB = 0b00100000;  // turn on 5th LED bit/pin in PORT B (Pin13 in Arduino)
    PORTB |= _BV(PORTB5);  // 2.) Set the value of pin PB5 to high (on) using the Port B Data Register (PORTB)
    _delay_ms(250);        // wait

    // PORTB = 0b00000000;  // turn off all bits/pins
    PORTB &= ~_BV(PORTB5);  // Set the value of pin PB5 to low (off) using the Port B Data Register (PORTB)
    _delay_ms(1000);        // wait
  }
  // This never happens since the above is the same as the Arduino 'void loop()'
  return 0;
}

/* ABOVE OPTIMIZED by toggling the value of an output pin.  uses 158 bytes
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
  // Configure PB5 as an output using the Port B Data Direction Register (DDRB)
  DDRB |= _BV(DDB5);

  // Loop forever
  while (1) {
    // Toggle PB5 using the Port B Input Pin Register (PINB)
    PINB = _BV(PINB5);

    // Wait 500ms
    _delay_ms(500);
  }
}
*/