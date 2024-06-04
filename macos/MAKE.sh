#!/bin/bash
HEX = "$1.hex"
INPT = "$1.c"
FLASH = "flash:w:$1.hex:a"

avr-gcc -Os -DF_CPU=16000000 -o $1 $INPT -mmcu=atmega2560
avr-objcopy -R .eeprom -O ihex $1 $HEX
avrdude -F -v -c wiring -p m2560 -P $2 -b 115200 -B 9600 -D -U $FLASH

rm -rf HEX
rm -rf $1