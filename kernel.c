void kprint(char *str, int color) {
	char *vidpos = (char*)0x7c00;
	char *vidptr = (char*)0xb8000;

	unsigned int i = 0;
	while (str[i] != '\0') {
		if (str[i] == '$') {
			color = str[i+1] - 'a';
			i += 2;
		} else {
			vidptr[*vidpos * 2] = str[i];
			vidptr[*vidpos * 2 + 1] = color;
			*vidpos = *vidpos + 1;
			i++;
		}
	}

	*vidpos += 80 - (*vidpos % 80);

}

void kclear() {
	char *vidpos = (char*)0x7c00;
	char *vidptr = (char*)0xb8000;

	*vidpos = 0;

	unsigned int i = 0;

	while (i < 80 * 25 * 2) {
		vidptr[i] = ' ';
		vidptr[i + 1] = 0x07;

		i += 2;
	}
}

void kmain(void) {
	char *vidpos = (char*)0x7c00;
	*vidpos = 0;

	clear();

	kprint("[$cInfo$h] Initialized screen buffer!", 0x07);
	kprint("[$eError$h] Failed to load kernel modules!", 0x07);

	return;
}
