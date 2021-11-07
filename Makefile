PREFIX = /usr

colourpicker: colourpicker.c
	cc colourpicker.c -lX11 -o colourpicker

.PHONY: colourpicker
