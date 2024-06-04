#include <avr/io.h>
#include <util/delay.h>

int main(void){
    DDRB |= _BV(DDB7);

    for(;;){
        PORTB |= _BV(PORTB7);
        _delay_ms(500);
        PORTB &= ~_BV(PORTB7);
        _delay_ms(500);
    }
}