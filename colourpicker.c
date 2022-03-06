/*
 * MIT/Expat License, (c) 2015
 * Jonas Kulla <Nyocurio@gmail.com>
 *
 * Notable changes by
 *  - 6gk <messagke@gmail.com>
 *  - ym1234
 */

#include <X11/Xutil.h>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int x = atoi(argv[1]);
	int y = atoi(argv[2]);
	Display *display = XOpenDisplay(NULL);

	Window root = DefaultRootWindow(display);
	XWindowAttributes gwa;
	XGetWindowAttributes(display, root, &gwa);

	XImage *image = XGetImage(display, root, 0, 0, gwa.width, gwa.height, AllPlanes, ZPixmap);
	unsigned long pixel = XGetPixel(image, x, y);
	printf("%lu %lu %lu\n", (pixel >> 0x10) & 0xFF, (pixel >> 0x08) & 0xFF, pixel & 0xFF);
	XDestroyImage(image);
	fflush(stdout);

	/* will be done on connection close anw */
	XCloseDisplay(display);
}
