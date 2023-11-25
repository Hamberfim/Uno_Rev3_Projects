// uses 150 bytes
#include <avr/io.h>

int main(void)
{
    // DDRD &= ~(1 << DDD2) // Configure PD2 as an input using the Data Direction Register D (DDRD)
    // Configure PD2 as an input using the Data Direction Register D (DDRD)
    DDRD &= ~_BV(DDD2);  // _BV macro which converts a bit number into a byte value

    // Enable the pull-up resistor on PD2 using the Port D Data Register (PORTD)
    PORTD |= _BV(PORTD2);

    // Configure PB5 as an output using the Port B Data Direction Register (DDRB)
    DDRB |= _BV(DDB5);

    // Loop forever
    while (1)
    {
        // Read PD2 using the Port D Pin Input Register (PIND)
        if (PIND & _BV(PIND2))
        {
            // PD2 is high, so button is released

            // Set PB5 low using the Port B Data Register (PORTB)
            PORTB &= ~_BV(PORTB5);
        }
        else
        {
            // PD2 is low, so button is pressed

            // Set PB5 high using the Port B Data Register (PORTB)
            PORTB |= _BV(PORTB5);
        }
    }
}