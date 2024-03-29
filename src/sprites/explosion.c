#include "explosion.h"
// Data created with Img2CPC - (c) Retroworks - 2007-2017
// Tile g_explosion_0: 14x16 pixels, 7x16 bytes.
const u8 g_explosion_0[7 * 16] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x40, 0x42, 0x00, 0x80, 0x40,
	0x00, 0x40, 0x40, 0xab, 0xc0, 0x42, 0x00,
	0x00, 0x81, 0xd5, 0x57, 0xab, 0x80, 0x00,
	0x00, 0x40, 0x03, 0xff, 0x42, 0x00, 0x00,
	0x00, 0x00, 0xd5, 0xff, 0xab, 0x80, 0x00,
	0x00, 0x00, 0xd5, 0xff, 0xff, 0x42, 0x00,
	0x00, 0x40, 0x57, 0xff, 0xff, 0x03, 0x80,
	0x00, 0x81, 0x03, 0xab, 0xab, 0x42, 0x00,
	0x00, 0x40, 0x57, 0x03, 0x57, 0x80, 0x40,
	0x00, 0x00, 0x81, 0xc0, 0x81, 0x80, 0x00,
	0x00, 0x40, 0x42, 0x00, 0x40, 0x42, 0x00,
	0x00, 0x00, 0x80, 0x00, 0x00, 0x80, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// Tile g_explosion_1: 14x16 pixels, 7x16 bytes.
const u8 g_explosion_1[7 * 16] = {
	0x00, 0x00, 0x00, 0x81, 0x80, 0x00, 0x81,
	0xc0, 0x80, 0x00, 0x81, 0x42, 0xc0, 0x03,
	0x03, 0x42, 0xc0, 0x03, 0x42, 0x03, 0x42,
	0x81, 0x03, 0xab, 0xff, 0x57, 0x03, 0x80,
	0x40, 0x57, 0x57, 0xff, 0xab, 0xea, 0x00,
	0x00, 0x81, 0xab, 0xff, 0xff, 0x42, 0x00,
	0x00, 0x40, 0x57, 0xff, 0xab, 0xab, 0xc0,
	0x00, 0x40, 0xff, 0xff, 0xff, 0xab, 0x03,
	0x40, 0x81, 0xff, 0xff, 0xff, 0x03, 0xc0,
	0x81, 0x57, 0xff, 0xff, 0xab, 0xea, 0x00,
	0x03, 0x57, 0x57, 0xff, 0x57, 0x80, 0x00,
	0xc0, 0xc0, 0xab, 0xab, 0xab, 0xea, 0x00,
	0x00, 0x40, 0x57, 0x42, 0xd5, 0x03, 0x80,
	0x00, 0x40, 0x03, 0x80, 0x40, 0x03, 0x80,
	0x00, 0x40, 0x03, 0x80, 0x00, 0x81, 0x42,
	0x00, 0x81, 0x42, 0x00, 0x00, 0x40, 0x81
};

