#include "pirate.h"
// Data created with Img2CPC - (c) Retroworks - 2007-2017
// Tile g_pirate_0: 14x16 pixels, 7x16 bytes.
const u8 g_pirate_0[7 * 16] = {
	0x00, 0x40, 0xf3, 0xf3, 0xc0, 0xb6, 0x80,
	0x00, 0xd1, 0x68, 0x3c, 0x3c, 0x94, 0x68,
	0x00, 0x94, 0x2c, 0x2c, 0x0c, 0x3c, 0x80,
	0x00, 0xc0, 0x48, 0x48, 0xc0, 0x68, 0x00,
	0x40, 0xea, 0xc5, 0xc5, 0xcf, 0x80, 0x00,
	0xd5, 0xea, 0xc5, 0xc5, 0xca, 0x42, 0x00,
	0xd5, 0x6a, 0xcf, 0xcf, 0x95, 0x42, 0x00,
	0xd5, 0xc0, 0x81, 0x81, 0x81, 0x81, 0x80,
	0xd5, 0x6a, 0x40, 0x42, 0x42, 0x42, 0x42,
	0xd5, 0x6a, 0x00, 0x81, 0x1c, 0xc0, 0x80,
	0x40, 0x3f, 0xc0, 0x2e, 0xc0, 0x68, 0x00,
	0x00, 0x95, 0x4a, 0x84, 0x84, 0x48, 0x00,
	0x00, 0x85, 0x8e, 0x2e, 0xc5, 0xca, 0x00,
	0x00, 0x40, 0xc0, 0x2c, 0xc0, 0x80, 0x00,
	0x00, 0x00, 0x00, 0x94, 0x48, 0x00, 0x00,
	0x00, 0x00, 0x40, 0xc3, 0xc8, 0x00, 0x00
};

// Tile g_pirate_1: 14x16 pixels, 7x16 bytes.
const u8 g_pirate_1[7 * 16] = {
	0x00, 0x00, 0x40, 0xc0, 0x80, 0x40, 0x80,
	0x40, 0x00, 0xd1, 0xf3, 0x68, 0xd1, 0x68,
	0xd5, 0xc0, 0xb6, 0x94, 0x3c, 0x68, 0x3c,
	0xff, 0xc0, 0x2c, 0x0c, 0x2c, 0x0c, 0x68,
	0xff, 0x80, 0x84, 0x84, 0xc0, 0x84, 0x80,
	0xea, 0x00, 0x40, 0xca, 0xcf, 0xca, 0x00,
	0xbf, 0x80, 0x40, 0xca, 0xcf, 0x81, 0xc0,
	0x3f, 0x80, 0xc5, 0xcf, 0xca, 0x2b, 0x81,
	0x95, 0x6a, 0xc0, 0x42, 0x42, 0x42, 0x42,
	0x40, 0x6a, 0x4a, 0x81, 0x81, 0x80, 0x80,
	0x00, 0x85, 0xc0, 0xc0, 0x0c, 0x68, 0x00,
	0x40, 0x4a, 0x9e, 0x84, 0x48, 0x1c, 0x80,
	0x00, 0x80, 0x84, 0x95, 0x48, 0x84, 0x68,
	0x00, 0x00, 0x40, 0xc0, 0x0c, 0xc5, 0xca,
	0x00, 0x00, 0x40, 0x2c, 0xc0, 0x48, 0xc0,
	0x00, 0x00, 0xc1, 0xcc, 0xc1, 0xcc, 0x80
};

// Tile g_pirate_2: 14x16 pixels, 7x16 bytes.
const u8 g_pirate_2[7 * 16] = {
	0x40, 0x80, 0x40, 0xc0, 0x80, 0x00, 0x00,
	0xd1, 0xe2, 0xd1, 0x3c, 0x68, 0x00, 0x80,
	0xf3, 0xd1, 0x3c, 0x68, 0x3c, 0xc0, 0xea,
	0x94, 0x0c, 0x1c, 0x0c, 0x1c, 0xc0, 0xff,
	0x40, 0x48, 0xc0, 0x48, 0x48, 0x40, 0xff,
	0x00, 0xc5, 0xcf, 0xc5, 0x80, 0x00, 0xd5,
	0xc0, 0x42, 0xcf, 0xc5, 0x80, 0x40, 0x7f,
	0x42, 0x17, 0xc5, 0xcf, 0xca, 0x40, 0x7f,
	0x81, 0x81, 0x81, 0x81, 0xc0, 0x95, 0x6a,
	0x40, 0x40, 0x42, 0x42, 0x85, 0x95, 0x80,
	0x00, 0x94, 0x0c, 0xc0, 0xc0, 0x4a, 0x00,
	0x40, 0x2c, 0x84, 0x48, 0x6d, 0x85, 0x80,
	0x94, 0x48, 0x84, 0x6a, 0x48, 0x40, 0x00,
	0xc5, 0xca, 0x0c, 0xc0, 0x80, 0x00, 0x00,
	0xc0, 0x84, 0xc0, 0x1c, 0x80, 0x00, 0x00,
	0x40, 0xcc, 0xc2, 0xcc, 0xc2, 0x00, 0x00
};

// Tile g_pirate_3: 14x16 pixels, 7x16 bytes.
const u8 g_pirate_3[7 * 16] = {
	0x40, 0xf3, 0xc0, 0xb6, 0x3c, 0x80, 0x00,
	0xd1, 0xe2, 0xb6, 0x3c, 0x94, 0x68, 0x00,
	0x40, 0x3c, 0x0c, 0x1c, 0x1c, 0x68, 0x00,
	0x00, 0x94, 0xc0, 0x84, 0x84, 0xc0, 0x00,
	0x00, 0x40, 0xcf, 0xca, 0xca, 0xd5, 0x80,
	0x00, 0x81, 0xc5, 0xca, 0xca, 0xd5, 0xea,
	0x00, 0x81, 0x6a, 0xcf, 0xcf, 0xd5, 0xea,
	0x40, 0x42, 0x42, 0x42, 0x42, 0xc0, 0xea,
	0x81, 0x81, 0x81, 0x81, 0x80, 0x95, 0xea,
	0x40, 0xc0, 0x2c, 0x42, 0x00, 0x95, 0x6a,
	0x00, 0x94, 0xc0, 0x1d, 0xc0, 0x3f, 0x80,
	0x00, 0x84, 0x48, 0x48, 0x85, 0x6a, 0x00,
	0x00, 0xc5, 0xca, 0x1d, 0x4d, 0x4a, 0x00,
	0x00, 0x40, 0xc0, 0x1c, 0xc0, 0x80, 0x00,
	0x00, 0x00, 0x84, 0x68, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xc4, 0xc3, 0x80, 0x00, 0x00
};

