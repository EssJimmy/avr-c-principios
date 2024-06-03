avr-gcc -Os -DF_CPU=16000000 -o $1 $1.c -mmcu=atmega2560
avr-objcopy -R .eeprom -O ihex $1 $1.hex
avrdude -c wiring -p atmega2560 -U flash:w:$1.hex -P $2 -b 9600 -B 115200