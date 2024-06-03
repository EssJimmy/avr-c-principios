#include <avr/io.h>

int main(void){
    TCCR1A |= _BV(1 << COM1A1) | _BV(1 << COM1B1) | _BV(1 << WGM11);
    TCCR1B |= _BV(1 << WGM13) | _BV(1 << WGM12) | _BV(1 << CS11) | _BV(1 << CS10);

    ICR1H = 0x01;
    ICR1L = 0xf4;

    // pin 11
    OCR1AH = _BV(0x00);
    OCR1AL = _BV(0xfa);
    
    // pin 12
    OCR1BH = _BV(0x00);
    OCR1BL = _BV(0xfa);

    for(;;){}
}