typedef unsigned char uint8;


enum VGAColor {
	BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	MAGENTA = 5,
	BROWN = 6,
	LIGHT_GREY = 7,
	DARK_GREY = 8,
	LIGHT_BLUE = 9,
	LIGHT_GREEN = 10,
	LIGHT_CYAN = 11,
	LIGHT_RED = 12,
	LIGHT_MAGENTA = 13,
	LIGHT_BROWN = 14,
	WHITE = 15
};

uint8 composeColor(enum VGAColor fg, enum VGAColor bg) {
	return fg | bg << 4;
}

void kprint(char *str, int color) {
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

void kprintln(char *str, int color) {
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

void kmain(void) {
	uint8 *vidpos = (uint8*)0x7c00;
	*vidpos = 0;

	uint8 color = composeColor(LIGHT_GREY, BLACK);

	kclear(color);

	kprint("[", color);
	kprint(" OK ", composeColor(BLACK, LIGHT_GREEN));
	kprint("] Initialized screen buffer!", color);
	knewline();

	kprint("[", color);
	kprint("FAIL", composeColor(WHITE, RED));
	kprint("] Failed to load kernel modules!", color);
	knewline();

	return;
}
