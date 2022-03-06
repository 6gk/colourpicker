PREFIX = /usr

colourpicker: colourpicker.c
	cc colourpicker.c -lX11 $(o) -o colourpicker

.PHONY: colourpicker
