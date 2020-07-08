#include "kernel.h"

void main(void) {
	uint8 color = kcompose(LIGHT_GREY, BLACK);

	kclear(color);

    klog_ok("Screen buffer accessed!");

	return;
}