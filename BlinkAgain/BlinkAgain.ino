#include <avr/io.h>
#include <util/delay.h>

/*
  Blink

  Turns an LED on, then off, repeatedly.

  Author: Hamberfim
*/

int main()
{
    // set PORTB5 as an output
    // direction register for port b5, left shifted 1 by the bit number of the port
    DDRB = DDRB | (1 << DDB5);

    // run a loop
    while (1)
    {
        // set PORTB5
        // bit setting: set n -- register = register | (1 << n)
        PORTB = PORTB | (1 << PORTB5);

        // wait
        _delay_ms(500); // marco

        // unset PORTB5
        // bit setting: unset n -- register = register & ~(1 << n)
        PORTB = PORTB & ~(1 << PORTB5);

        // wait
        _delay_ms(250); // marco
    }

    // end never happens
    return 0;
}