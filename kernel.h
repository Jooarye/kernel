typedef unsigned char uint8;


enum VGAColor {
	BLACK 	= 0,
	BLUE 	= 1,
	GREEN 	= 2,
	CYAN 	= 3,
	RED 	= 4,
	MAGENTA = 5,
	BROWN 	= 6,
	LIGHT_GREY 		= 7,
	DARK_GREY 		= 8,
	LIGHT_BLUE 		= 9,
	LIGHT_GREEN 	= 10,
	LIGHT_CYAN 		= 11,
	LIGHT_RED 		= 12,
	LIGHT_MAGENTA 	= 13,
	LIGHT_BROWN 	= 14,
	WHITE 			= 15
};

uint8 kcompose(enum VGAColor fg, enum VGAColor bg);
void kprint(char* string, uint8 color);
void kprintln(char* string, uint8 color);
void knewline();
void kclear(uint8 color);


// LOGGING PURPOSES ONLY
void klog_fail(char* str);
void klog_ok(char* str);