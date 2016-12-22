ifndef MAKEFILE_INCLUDED
	include ../../../Makefile
endif

upload:
	avrdude -p atmega32u4 -P /dev/ttyACM0  -c avr109  -U flash:w:../../../handwired_pad20_default.hex
