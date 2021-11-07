PREFIX = /usr

colorpicker: main.c
	cc main.c -lX11 -o colorpicker

.PHONY: colorpicker
