#include "player.h"
// Data created with Img2CPC - (c) Retroworks - 2007-2017
// Tile g_player_00: 14x16 pixels, 7x16 bytes.
const u8 g_player_00[7 * 16] = {
	0x00, 0xd5, 0xff, 0x7f, 0x80, 0x00, 0x00,
	0x40, 0xca, 0x95, 0x9d, 0x6a, 0x00, 0x00,
	0x40, 0xcf, 0xca, 0x1f, 0x3f, 0x80, 0x00,
	0x40, 0xca, 0xea, 0x6e, 0x3f, 0x80, 0x00,
	0xc5, 0xca, 0xef, 0x85, 0x9d, 0x80, 0x00,
	0xc5, 0xcf, 0xcf, 0xc0, 0x1f, 0x80, 0x00,
	0x40, 0xcf, 0xc5, 0xcf, 0x95, 0x80, 0x00,
	0x00, 0xc0, 0xcf, 0xca, 0x85, 0x6a, 0x00,
	0x00, 0x00, 0x81, 0xd5, 0xc0, 0x4a, 0x00,
	0x00, 0x40, 0xff, 0xea, 0xea, 0x80, 0x00,
	0x00, 0xd5, 0xff, 0xc0, 0xea, 0x00, 0x00,
	0x00, 0xd5, 0xea, 0x8b, 0xea, 0x00, 0x00,
	0x00, 0xd4, 0xe8, 0xdf, 0x80, 0x00, 0x00,
	0x00, 0x40, 0xfc, 0xc0, 0x00, 0x00, 0x00,
	0x00, 0x40, 0xc4, 0xc9, 0x80, 0x00, 0x00,
	0x00, 0xc1, 0xcc, 0xc4, 0x80, 0x00, 0x00
};

// Tile g_player_01: 14x16 pixels, 7x16 bytes.
const u8 g_player_01[7 * 16] = {
	0x00, 0x40, 0xc0, 0xc0, 0x00, 0x00, 0x00,
	0x00, 0xd5, 0xff, 0x7f, 0x80, 0x00, 0x00,
	0x40, 0xca, 0x95, 0x9d, 0x6a, 0x00, 0x00,
	0x40, 0xcf, 0xca, 0x1f, 0x3f, 0x80, 0x00,
	0x40, 0xca, 0xea, 0x6e, 0x3f, 0x80, 0x00,
	0xc5, 0xca, 0xef, 0x85, 0x9d, 0x80, 0x00,
	0xc5, 0xcf, 0xcf, 0xc0, 0x1f, 0x80, 0x00,
	0x40, 0xcf, 0xc5, 0xcf, 0x95, 0xc0, 0x00,
	0x00, 0xc0, 0xcf, 0xca, 0x85, 0x2f, 0x80,
	0x00, 0x40, 0x81, 0xd5, 0xc0, 0x4a, 0x00,
	0x00, 0xd5, 0xff, 0xc0, 0xea, 0x80, 0x00,
	0x40, 0xff, 0xea, 0x8b, 0xea, 0x00, 0x00,
	0x40, 0xfc, 0xe8, 0xdf, 0x80, 0x00, 0x00,
	0x00, 0xc0, 0xfc, 0xc0, 0x00, 0x00, 0x00,
	0x00, 0x40, 0xc4, 0xc9, 0x80, 0x00, 0x00,
	0x00, 0xc1, 0xcc, 0xc4, 0x80, 0x00, 0x00
};

// Tile g_player_02: 14x16 pixels, 7x16 bytes.
const u8 g_player_02[7 * 16] = {
	0x00, 0x40, 0xc0, 0xc0, 0x00, 0x00, 0x00,
	0x00, 0x95, 0xff, 0x7f, 0x80, 0x00, 0x00,
	0x40, 0xca, 0x85, 0x9d, 0x6a, 0x00, 0x00,
	0x40, 0xcf, 0xca, 0x3f, 0x3f, 0x80, 0x00,
	0x40, 0xca, 0xea, 0x4e, 0x3f, 0x80, 0x00,
	0xc5, 0xca, 0xef, 0x85, 0x9d, 0x80, 0x00,
	0xc5, 0xcf, 0xcf, 0xc0, 0x1f, 0xc0, 0x80,
	0x40, 0xcf, 0xc5, 0xcf, 0x85, 0x95, 0xea,
	0x40, 0xc0, 0xcf, 0xca, 0x40, 0x0f, 0x80,
	0xc5, 0xea, 0x81, 0x03, 0x80, 0xc0, 0x6a,
	0xc5, 0xea, 0xff, 0xd5, 0xea, 0x00, 0x80,
	0x40, 0xd5, 0xff, 0xc0, 0xff, 0x80, 0x00,
	0x00, 0x81, 0xd5, 0x42, 0xcf, 0x80, 0x00,
	0x00, 0x40, 0xfc, 0xfc, 0xc0, 0x80, 0x00,
	0x00, 0xc4, 0xc8, 0xd4, 0xe8, 0xc2, 0x00,
	0x40, 0xc6, 0xc8, 0x40, 0xc0, 0xc8, 0x00
};

// Tile g_player_03: 14x16 pixels, 7x16 bytes.
const u8 g_player_03[7 * 16] = {
	0x00, 0x40, 0xc0, 0xc0, 0x80, 0x00, 0x00,
	0x00, 0xd5, 0xbf, 0xff, 0x80, 0x00, 0x00,
	0x40, 0xca, 0x95, 0x9d, 0x6a, 0x00, 0x00,
	0x40, 0xcf, 0xca, 0x1f, 0x3f, 0x80, 0x00,
	0x40, 0xca, 0xea, 0x6e, 0x3f, 0x80, 0x00,
	0xc5, 0xca, 0xef, 0x85, 0x9d, 0x80, 0x00,
	0xc5, 0xcf, 0xcf, 0xc0, 0x1f, 0xc0, 0x80,
	0x40, 0xcf, 0xc5, 0xcf, 0x85, 0x95, 0xea,
	0x00, 0xc0, 0xcf, 0xcf, 0xc0, 0x0f, 0x80,
	0x00, 0xc0, 0xc0, 0x42, 0x42, 0xc0, 0x6a,
	0x40, 0xdf, 0xd5, 0xea, 0xea, 0x00, 0x80,
	0x40, 0x8b, 0xff, 0xc0, 0xff, 0x80, 0x00,
	0x00, 0xc0, 0xc0, 0x81, 0xea, 0xca, 0x00,
	0x00, 0x40, 0xfc, 0xfc, 0xc0, 0x80, 0x00,
	0x00, 0xc4, 0xc8, 0xd4, 0xe8, 0xc2, 0x00,
	0x40, 0xc6, 0xc8, 0x40, 0xc0, 0xc8, 0x00
};

// Tile g_player_04: 14x16 pixels, 7x16 bytes.
const u8 g_player_04[7 * 16] = {
	0x00, 0x00, 0xd5, 0xbf, 0x3f, 0x80, 0x00,
	0x00, 0x40, 0xbf, 0x9d, 0xc0, 0xca, 0x00,
	0x00, 0xd5, 0x3f, 0x4a, 0xcf, 0xca, 0x00,
	0x00, 0x95, 0x6e, 0x6a, 0xea, 0xca, 0x00,
	0x00, 0x95, 0x8d, 0xc5, 0xea, 0xcf, 0x80,
	0x00, 0x95, 0x4a, 0xc5, 0xcf, 0xcf, 0x80,
	0x00, 0x95, 0xc5, 0xcf, 0xc5, 0xca, 0x00,
	0x40, 0xaf, 0xc0, 0xcf, 0xca, 0x80, 0x00,
	0x40, 0x4a, 0x81, 0x81, 0x80, 0x00, 0x00,
	0x00, 0xc0, 0x42, 0xff, 0xea, 0x00, 0x00,
	0x00, 0x40, 0xea, 0xd5, 0xff, 0x80, 0x00,
	0x00, 0x40, 0xab, 0xca, 0xab, 0x80, 0x00,
	0x00, 0x00, 0xd5, 0xca, 0xfc, 0x80, 0x00,
	0x00, 0x00, 0x40, 0xd4, 0xe8, 0x00, 0x00,
	0x00, 0x00, 0xc1, 0xcc, 0xc0, 0x00, 0x00,
	0x00, 0x00, 0xc4, 0xc4, 0xc9, 0x80, 0x00
};

// Tile g_player_05: 14x16 pixels, 7x16 bytes.
const u8 g_player_05[7 * 16] = {
	0x00, 0x00, 0x40, 0xc0, 0xc0, 0x00, 0x00,
	0x00, 0x00, 0xd5, 0xbf, 0x3f, 0x80, 0x00,
	0x00, 0x40, 0xbf, 0x9d, 0xc0, 0xca, 0x00,
	0x00, 0xd5, 0x3f, 0x4a, 0xcf, 0xca, 0x00,
	0x00, 0x95, 0x6e, 0x6a, 0xea, 0xca, 0x00,
	0x00, 0x95, 0x8d, 0xc5, 0xea, 0xcf, 0x80,
	0x00, 0x95, 0x4a, 0xc5, 0xcf, 0xcf, 0x80,
	0x40, 0x95, 0xc5, 0xcf, 0xc5, 0xca, 0x00,
	0x95, 0xaf, 0xc0, 0xcf, 0xca, 0x80, 0x00,
	0x40, 0x4a, 0x81, 0x81, 0xc0, 0x00, 0x00,
	0x00, 0xc0, 0xea, 0xd5, 0xff, 0x80, 0x00,
	0x00, 0x40, 0xab, 0xca, 0xff, 0xea, 0x00,
	0x00, 0x00, 0xd5, 0xca, 0xfc, 0xe8, 0x00,
	0x00, 0x00, 0x40, 0xd4, 0xe8, 0x80, 0x00,
	0x00, 0x00, 0xc1, 0xcc, 0xc0, 0x00, 0x00,
	0x00, 0x00, 0xc4, 0xc4, 0xc9, 0x80, 0x00
};

// Tile g_player_06: 14x16 pixels, 7x16 bytes.
const u8 g_player_06[7 * 16] = {
	0x00, 0x00, 0x00, 0xc0, 0xc0, 0x80, 0x00,
	0x00, 0x00, 0x40, 0xff, 0x3f, 0x6a, 0x00,
	0x00, 0x00, 0xd5, 0x6e, 0x4a, 0xc5, 0x80,
	0x00, 0x40, 0xbf, 0x3f, 0xc5, 0xcf, 0x80,
	0x00, 0x40, 0x3f, 0x8d, 0xd5, 0xc5, 0x80,
	0x00, 0x40, 0x6e, 0x4a, 0xdf, 0xc5, 0xca,
	0x40, 0xc0, 0x2f, 0xc0, 0xcf, 0xcf, 0xca,
	0xd5, 0x6a, 0x4a, 0xcf, 0xca, 0xcf, 0x80,
	0x40, 0x0f, 0x80, 0xc5, 0xcf, 0xc0, 0x80,
	0x95, 0xc0, 0x40, 0x03, 0x42, 0xd5, 0xca,
	0x40, 0x00, 0xd5, 0xea, 0xff, 0xd5, 0xca,
	0x00, 0x40, 0xff, 0xc0, 0xff, 0xea, 0x80,
	0x00, 0x40, 0xcf, 0x81, 0xea, 0x42, 0x00,
	0x00, 0x40, 0xc0, 0xfc, 0xfc, 0x80, 0x00,
	0x00, 0xc1, 0xd4, 0xe8, 0xc4, 0xc8, 0x00,
	0x00, 0xc4, 0xc0, 0x80, 0xc4, 0xc9, 0x80
};

// Tile g_player_07: 14x16 pixels, 7x16 bytes.
const u8 g_player_07[7 * 16] = {
	0x00, 0x00, 0x40, 0xc0, 0xc0, 0x80, 0x00,
	0x00, 0x00, 0x40, 0xbf, 0x3f, 0x6a, 0x00,
	0x00, 0x00, 0xd5, 0x6e, 0x6a, 0xc5, 0x80,
	0x00, 0x40, 0xbf, 0x2f, 0xc5, 0xcf, 0x80,
	0x00, 0x40, 0x3f, 0x9d, 0xd5, 0xc5, 0x80,
	0x00, 0x40, 0x6e, 0x4a, 0xdf, 0xc5, 0xca,
	0x40, 0xc0, 0x2f, 0xc0, 0xcf, 0xcf, 0xca,
	0xd5, 0x6a, 0x4a, 0xcf, 0xca, 0xcf, 0x80,
	0x40, 0x0f, 0xc0, 0xcf, 0xcf, 0xc0, 0x00,
	0x95, 0xc0, 0x81, 0x81, 0xc0, 0xc0, 0x00,
	0x40, 0x00, 0xd5, 0xd5, 0xea, 0xef, 0x80,
	0x00, 0x40, 0xff, 0xc0, 0xff, 0x47, 0x80,
	0x00, 0xc5, 0xd5, 0x42, 0xc0, 0xc0, 0x00,
	0x00, 0x40, 0xc0, 0xfc, 0xfc, 0x80, 0x00,
	0x00, 0xc1, 0xd4, 0xe8, 0xc4, 0xc8, 0x00,
	0x00, 0xc4, 0xc0, 0x80, 0xc4, 0xc9, 0x80
};

// Tile g_player_08: 14x16 pixels, 7x16 bytes.
const u8 g_player_08[7 * 16] = {
	0x00, 0xc0, 0xbf, 0xbf, 0xbf, 0x80, 0x00,
	0x00, 0xd5, 0x2f, 0x6e, 0x6e, 0x6a, 0x00,
	0x40, 0x95, 0x3f, 0x2f, 0x8d, 0x6a, 0x80,
	0xc5, 0x95, 0x1f, 0x4e, 0x4e, 0x4a, 0xca,
	0xc5, 0x95, 0x3f, 0x8d, 0x8d, 0x4a, 0xca,
	0x40, 0xc0, 0x2f, 0x6e, 0x0f, 0xc0, 0x80,
	0xd5, 0xea, 0x95, 0x9d, 0x4a, 0x81, 0xea,
	0x40, 0xab, 0x95, 0x4e, 0x4a, 0x57, 0x80,
	0x00, 0xd5, 0x42, 0x4a, 0x03, 0xea, 0x00,
	0x00, 0x40, 0xea, 0x57, 0xd5, 0x80, 0x00,
	0x00, 0xd5, 0xc0, 0xc0, 0xc0, 0x42, 0x00,
	0x00, 0xd4, 0xe8, 0xff, 0xd4, 0xe8, 0x00,
	0x00, 0x40, 0xfc, 0xfc, 0xfc, 0x80, 0x00,
	0x00, 0x40, 0xe8, 0xc0, 0xd4, 0x80, 0x00,
	0x00, 0xc0, 0xcc, 0xc0, 0xcc, 0xc0, 0x00,
	0x40, 0xc6, 0xc4, 0xc0, 0xc8, 0xc9, 0x80
};

// Tile g_player_09: 14x16 pixels, 7x16 bytes.
const u8 g_player_09[7 * 16] = {
	0x00, 0x40, 0xbf, 0xbf, 0xbf, 0x80, 0x00,
	0x00, 0xd5, 0x2f, 0x6e, 0x6e, 0x6a, 0x00,
	0x00, 0xd5, 0x3f, 0x3f, 0x8d, 0x4a, 0x00,
	0x00, 0x95, 0x3f, 0x6e, 0x4e, 0x4a, 0x00,
	0x00, 0x95, 0x1f, 0x8d, 0x8d, 0x4a, 0x80,
	0x00, 0x40, 0x3f, 0x6e, 0x0f, 0xc5, 0xca,
	0x00, 0x00, 0x95, 0x8d, 0x4a, 0x81, 0xea,
	0x40, 0x80, 0x95, 0x6e, 0x4a, 0x81, 0xea,
	0xc5, 0xca, 0x42, 0x85, 0x03, 0xff, 0xc0,
	0xd5, 0xab, 0xea, 0xff, 0xd5, 0xc0, 0x80,
	0x40, 0xd5, 0xc0, 0xc0, 0xc0, 0xea, 0x00,
	0x00, 0xd4, 0xe8, 0xff, 0xd4, 0xe8, 0x00,
	0x00, 0x40, 0xfc, 0xfc, 0xfc, 0xc0, 0x00,
	0x00, 0x40, 0xe8, 0xc0, 0xc8, 0xc9, 0x80,
	0x00, 0xc0, 0xcc, 0x80, 0x80, 0xc0, 0x80,
	0x40, 0xc6, 0xc4, 0x80, 0x00, 0x00, 0x00
};

// Tile g_player_10: 14x16 pixels, 7x16 bytes.
const u8 g_player_10[7 * 16] = {
	0x00, 0x40, 0xbf, 0xbf, 0xbf, 0x80, 0x00,
	0x00, 0xd5, 0x2f, 0x6e, 0x6e, 0x6a, 0x00,
	0x00, 0xd5, 0x3f, 0x3f, 0x8d, 0x4a, 0x00,
	0x00, 0x95, 0x1f, 0x6e, 0x4e, 0x4a, 0x00,
	0x40, 0x95, 0x3f, 0x8d, 0x8d, 0x4a, 0x00,
	0xc5, 0xca, 0x3f, 0x6e, 0x0f, 0x80, 0x00,
	0xd5, 0x42, 0x95, 0x8d, 0x4a, 0x00, 0x00,
	0xd5, 0x42, 0x95, 0x6e, 0x4a, 0x40, 0x80,
	0x40, 0xff, 0x42, 0x85, 0x03, 0xc5, 0xca,
	0x00, 0xc0, 0xea, 0xff, 0xd5, 0x57, 0xea,
	0x00, 0xd5, 0xc0, 0xc0, 0xc0, 0xea, 0x80,
	0x00, 0xd4, 0xe8, 0xff, 0xd4, 0xe8, 0x00,
	0x00, 0xc0, 0xfc, 0xfc, 0xfc, 0x80, 0x00,
	0x40, 0xc6, 0xc4, 0xc0, 0xd4, 0x80, 0x00,
	0x40, 0xc0, 0x40, 0x40, 0xcc, 0xc0, 0x00,
	0x00, 0x00, 0x00, 0x40, 0xc2, 0xcc, 0x80
};

