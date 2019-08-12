# usage make all target FILE=~filename to be compiled and flashed~

compile:
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o $(FILE).o $(FILE).c
	avr-gcc -mmcu=atmega328p $(FILE).o -o $(FILE)

prepare:
	avr-objcopy -O ihex -R .eeprom $(FILE) $(FILE).hex

flash:
	sudo avrdude -F -V -c arduino -p ATMEGA328p -P /dev/ttyACM0 -b 115200 -U flash:w:$(FILE).hex

clean:
	rm -rf $(FILE) *.hex *.o

all:
	make compile
	make prepare
	make flash
	make clean
