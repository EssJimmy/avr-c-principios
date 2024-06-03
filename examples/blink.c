#include <avr/io.h>
#include <util.delay.h>

int main(void){
    DDRB |= _BV(DDB7);

    for(;;){
        PORTB |= _BV(PORTB3);
        _delay_ms_(1000);
        PORTB &= ~_BV(PORTB3);
        _delay_ms(1000);
    }
}