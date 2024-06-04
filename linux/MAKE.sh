#!/bin/bash
HEX="$1.hex"
INPT="$1.c"
FLASH="flash:w:$1.hex:a"

avr-gcc -Os -DF_CPU=16000000L -o $1 $INPT -mmcu=atmega2560
avr-objcopy -R .eeprom -O ihex $1 $HEX
sudo avrdude -F -v -c wiring -p atmega2560 -U $FLASH -P $2 -b 115200 -B 9600 -D

rm -rf $HEX
rm -rf $1
