#include "kernel.h"

uint8 kcompose(enum VGAColor fg, enum VGAColor bg) {
	return fg | bg << 4;
}

void kprint(char *str, uint8 color) {
	uint8 *vidpos = (uint8*)0x7c00;
	uint8 *vidptr = (uint8*)0xb8000;

	unsigned int i = 0;

	while (str[i] != '\0') {
		vidptr[*vidpos * 2] = str[i];
		vidptr[*vidpos * 2 + 1] = color;
		*vidpos = *vidpos + 1;
		i++;
	}

}

void knewline() {
	uint8 *vidpos = (uint8*)0x7c00;

	*vidpos += 80 - (*vidpos % 80);
}

void kprintln(char *str, uint8 color) {
	kprint(str, color);
	knewline();
}

void kclear(uint8 color) {
	uint8 *vidpos = (uint8*)0x7c00;
	uint8 *vidptr = (uint8*)0xb8000;

	*vidpos = 0;

	unsigned int i = 0;

	while (i < 80 * 25 * 2) {
		vidptr[i] = ' ';
		vidptr[i + 1] = color;

		i += 2;
	}
}