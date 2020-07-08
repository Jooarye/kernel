#include "kernel.h"

void kfail(char* str) {
    uint8 color = kcompose(LIGHT_GREY, BLACK);

	kprint("[", color);
	kprint("FAIL", kcompose(WHITE, RED));
	kprint("] ", color);
    kprint(str, color);
	knewline();
}

void kok(char* str) {
    uint8 color = kcompose(LIGHT_GREY, BLACK);

	kprint("[", color);
	kprint(" OK ", kcompose(BLACK, LIGHT_GREEN));
	kprint("] ", color);
    kprint(str, color);
	knewline();
}

void main(void) {
	uint8 color = kcompose(LIGHT_GREY, BLACK);

	kclear(color);

    kok("Screen buffer accessed!");

	return;
}