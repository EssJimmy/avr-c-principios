$hex = $args[0]+".hex"
$inp = $args[0]+".c"
$flash = "flash:w:"+$hex+":a"

avr-gcc -Os -DF_CPU=16000000 -o $args[0] $inp -mmcu=atmega2560
avr-objcopy -R .eeprom -O ihex $args[0] $hex
avrdude -F -v -c wiring -p m2560 -P $args[1] -b 115200 -B 9600 -D -U $flash

Remove-Item $hex
Remove-Item $args[0]