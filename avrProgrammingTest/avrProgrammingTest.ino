//#include <USART.h>
//#include <binaryMacro.h>
//#include <macros.h>
//#include <pinDefines.h>
//#include <portpins.h>

/* Blinker Demo */

// ------- Preamble -------- //
#include <avr/io.h>     /* Defines pins, ports, etc */
#include <util/delay.h> /* Functions to waste time */


int main(void) {

  // -------- Inits --------- //
  DDRB |= 0b00100000; /* Data Direction Register B: writing a one to the bit enables output. */

  // ------ Event loop ------ //
  while (1) {

    PORTB = 0b00100000; /* Turn on fifth LED bit/pin in PORTB */
    _delay_ms(250);     /* wait */

    PORTB = 0b00000000; /* Turn off all B pins, including LED */
    _delay_ms(250);     /* wait */


  }         /* End event loop */
  return 0; /* This line is never reached */
}
