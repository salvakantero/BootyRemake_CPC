#include "tiles.h"
// Data created with Img2CPC - (c) Retroworks - 2007-2017
// Palette uses hardware values.
const u8 g_palette[16] = { 0x4d, 0x54, 0x44, 0x5c, 0x58, 0x56, 0x57, 0x5e, 0x40, 0x4c, 0x4e, 0x47, 0x52, 0x53, 0x4a, 0x4b };

u8* const g_tileset[120] = { 
	g_tiles_000, g_tiles_001, g_tiles_002, g_tiles_003, g_tiles_004, g_tiles_005, g_tiles_006, g_tiles_007, g_tiles_008, g_tiles_009, g_tiles_010, g_tiles_011, g_tiles_012, g_tiles_013, g_tiles_014, g_tiles_015, g_tiles_016, g_tiles_017, g_tiles_018, g_tiles_019, g_tiles_020, g_tiles_021, g_tiles_022, g_tiles_023, g_tiles_024, g_tiles_025, g_tiles_026, g_tiles_027, g_tiles_028, g_tiles_029, g_tiles_030, g_tiles_031, g_tiles_032, g_tiles_033, g_tiles_034, g_tiles_035, g_tiles_036, g_tiles_037, g_tiles_038, g_tiles_039, g_tiles_040, g_tiles_041, g_tiles_042, g_tiles_043, g_tiles_044, g_tiles_045, g_tiles_046, g_tiles_047, g_tiles_048, g_tiles_049, g_tiles_050, g_tiles_051, g_tiles_052, g_tiles_053, g_tiles_054, g_tiles_055, g_tiles_056, g_tiles_057, g_tiles_058, g_tiles_059, g_tiles_060, g_tiles_061, g_tiles_062, g_tiles_063, g_tiles_064, g_tiles_065, g_tiles_066, g_tiles_067, g_tiles_068, g_tiles_069, g_tiles_070, g_tiles_071, g_tiles_072, g_tiles_073, g_tiles_074, g_tiles_075, g_tiles_076, g_tiles_077, g_tiles_078, g_tiles_079, g_tiles_080, g_tiles_081, g_tiles_082, g_tiles_083, g_tiles_084, g_tiles_085, g_tiles_086, g_tiles_087, g_tiles_088, g_tiles_089, g_tiles_090, g_tiles_091, g_tiles_092, g_tiles_093, g_tiles_094, g_tiles_095, g_tiles_096, g_tiles_097, g_tiles_098, g_tiles_099, g_tiles_100, g_tiles_101, g_tiles_102, g_tiles_103, g_tiles_104, g_tiles_105, g_tiles_106, g_tiles_107, g_tiles_108, g_tiles_109, g_tiles_110, g_tiles_111, g_tiles_112, g_tiles_113, g_tiles_114, g_tiles_115, g_tiles_116, g_tiles_117, g_tiles_118, g_tiles_119
};
// Tile g_tiles_000: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_000[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_001: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_001[2 * 4] = {
	0xc3, 0xc8,
	0xc6, 0xc8,
	0xcc, 0xc8,
	0xc0, 0xc0
};

// Tile g_tiles_002: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_002[2 * 4] = {
	0xef, 0xca,
	0xcf, 0x60,
	0x30, 0x60,
	0xc0, 0xc0
};

// Tile g_tiles_003: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_003[2 * 4] = {
	0xc3, 0xc8,
	0xc4, 0xcc,
	0xc8, 0xcc,
	0xcc, 0xc4
};

// Tile g_tiles_004: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_004[2 * 4] = {
	0xcf, 0x60,
	0x90, 0x30,
	0x60, 0x30,
	0x30, 0x90
};

// Tile g_tiles_005: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_005[2 * 4] = {
	0xc1, 0xc8,
	0xc3, 0x64,
	0xc2, 0x90,
	0xc2, 0x90
};

// Tile g_tiles_006: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_006[2 * 4] = {
	0xc2, 0x90,
	0xc3, 0x98,
	0xc2, 0x90,
	0xc2, 0x90
};

// Tile g_tiles_007: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_007[2 * 4] = {
	0xc0, 0xc0,
	0xc4, 0xee,
	0xc1, 0x4b,
	0xc4, 0xc6
};

// Tile g_tiles_008: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_008[2 * 4] = {
	0xc0, 0xc0,
	0xc9, 0xc8,
	0x87, 0xc2,
	0x61, 0xc8
};

// Tile g_tiles_009: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_009[2 * 4] = {
	0xc9, 0xcc,
	0xc9, 0xc4,
	0xc9, 0xc8,
	0xc9, 0xc0
};

// Tile g_tiles_010: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_010[2 * 4] = {
	0xc9, 0xc3,
	0xcc, 0xcc,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_011: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_011[2 * 4] = {
	0x4b, 0xc8,
	0xc1, 0xc8,
	0xc9, 0xc8,
	0xc1, 0xc8
};

// Tile g_tiles_012: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_012[2 * 4] = {
	0x1f, 0x0f,
	0x1f, 0x85,
	0x1f, 0x4a,
	0x1f, 0xc0
};

// Tile g_tiles_013: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_013[2 * 4] = {
	0x1f, 0x3f,
	0x0f, 0x0f,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_014: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_014[2 * 4] = {
	0xbf, 0x4a,
	0x95, 0x4a,
	0x1f, 0x4a,
	0x95, 0x4a
};

// Tile g_tiles_015: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_015[2 * 4] = {
	0xc0, 0x85,
	0xc0, 0x7f,
	0x95, 0xbf,
	0x7f, 0x3f
};

// Tile g_tiles_016: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_016[2 * 4] = {
	0x4a, 0xc0,
	0x1f, 0xc0,
	0x2f, 0x6a,
	0x1f, 0x1f
};

// Tile g_tiles_017: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_017[2 * 4] = {
	0x95, 0xc0,
	0x95, 0x95,
	0xd5, 0xc4,
	0xd5, 0x2f
};

// Tile g_tiles_018: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_018[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0x4a,
	0xc8, 0x4a,
	0x0f, 0x4a
};

// Tile g_tiles_019: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_019[2 * 4] = {
	0xc0, 0xbf,
	0xd5, 0xc0,
	0xd5, 0xc0,
	0xc0, 0x2f
};

// Tile g_tiles_020: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_020[2 * 4] = {
	0xd5, 0x6a,
	0x6a, 0x95,
	0xc0, 0x95,
	0x8d, 0x4a
};

// Tile g_tiles_021: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_021[2 * 4] = {
	0xc8, 0xc0,
	0x4a, 0xc0,
	0x4a, 0xc0,
	0x6a, 0xc0
};

// Tile g_tiles_022: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_022[2 * 4] = {
	0x3f, 0x6a,
	0x2f, 0xc0,
	0x2f, 0x4a,
	0xc0, 0xc0
};

// Tile g_tiles_023: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_023[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_024: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_024[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xd5, 0xc0,
	0x33, 0xc0
};

// Tile g_tiles_025: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_025[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xbb, 0xe0,
	0xc0, 0x62
};

// Tile g_tiles_026: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_026[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xbb, 0xe0,
	0xc0, 0x62
};

// Tile g_tiles_027: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_027[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xea, 0x62,
	0x62, 0x62
};

// Tile g_tiles_028: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_028[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xbb, 0x62,
	0x62, 0xc0
};

// Tile g_tiles_029: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_029[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xf5, 0x62,
	0x62, 0xc0
};

// Tile g_tiles_030: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_030[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xbb, 0xe0,
	0xc0, 0x62
};

// Tile g_tiles_031: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_031[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xf5, 0xe0,
	0x62, 0x62
};

// Tile g_tiles_032: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_032[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xf5, 0xe0,
	0x62, 0x62
};

// Tile g_tiles_033: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_033[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_034: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_034[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_035: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_035[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_036: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_036[2 * 4] = {
	0x91, 0xc0,
	0x91, 0xc0,
	0xb1, 0xe0,
	0xc0, 0xc0
};

// Tile g_tiles_037: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_037[2 * 4] = {
	0xb1, 0xe0,
	0x62, 0xc0,
	0x33, 0x62,
	0xc0, 0xc0
};

// Tile g_tiles_038: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_038[2 * 4] = {
	0x91, 0xe0,
	0xc0, 0x62,
	0x33, 0xe0,
	0xc0, 0xc0
};

// Tile g_tiles_039: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_039[2 * 4] = {
	0xb1, 0xe0,
	0xc0, 0x62,
	0xc0, 0x62,
	0xc0, 0xc0
};

// Tile g_tiles_040: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_040[2 * 4] = {
	0xb1, 0xe0,
	0xc0, 0x62,
	0x33, 0xe0,
	0xc0, 0xc0
};

// Tile g_tiles_041: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_041[2 * 4] = {
	0x33, 0xe0,
	0x62, 0x62,
	0xb1, 0xe0,
	0xc0, 0xc0
};

// Tile g_tiles_042: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_042[2 * 4] = {
	0xd0, 0xc0,
	0x91, 0xc0,
	0x91, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_043: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_043[2 * 4] = {
	0xb1, 0xe0,
	0x62, 0x62,
	0xb1, 0xe0,
	0xc0, 0xc0
};

// Tile g_tiles_044: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_044[2 * 4] = {
	0xb1, 0xe0,
	0xc0, 0x62,
	0xc0, 0x62,
	0xc0, 0xc0
};

// Tile g_tiles_045: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_045[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_046: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_046[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_047: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_047[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_048: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_048[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xd5,
	0xc0, 0xea
};

// Tile g_tiles_049: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_049[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xff, 0x3f,
	0x95, 0x95
};

// Tile g_tiles_050: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_050[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0x95, 0x6a,
	0x6a, 0xbd
};

// Tile g_tiles_051: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_051[2 * 4] = {
	0xc0, 0xbf,
	0xc0, 0x95,
	0xc0, 0xc0,
	0xc0, 0xd5
};

// Tile g_tiles_052: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_052[2 * 4] = {
	0xe8, 0xbd,
	0x3f, 0xe8,
	0x7e, 0xe8,
	0x3f, 0x7e
};

// Tile g_tiles_053: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_053[2 * 4] = {
	0xc0, 0xc0,
	0xbd, 0xe8,
	0xc0, 0x6a,
	0xc0, 0xc0
};

// Tile g_tiles_054: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_054[2 * 4] = {
	0xc0, 0xbf,
	0xd4, 0x3f,
	0x95, 0x6a,
	0x95, 0x3f
};

// Tile g_tiles_055: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_055[2 * 4] = {
	0x6a, 0x3f,
	0xc0, 0x95,
	0x7e, 0x3f,
	0xc0, 0x95
};

// Tile g_tiles_056: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_056[2 * 4] = {
	0xe8, 0xc0,
	0x7e, 0xc0,
	0x3f, 0xe8,
	0x3f, 0xe8
};

// Tile g_tiles_057: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_057[2 * 4] = {
	0x95, 0x3f,
	0x95, 0x3f,
	0xd4, 0x3f,
	0xc0, 0xbd
};

// Tile g_tiles_058: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_058[2 * 4] = {
	0x7e, 0x6a,
	0xc0, 0x95,
	0x6a, 0x3f,
	0x3f, 0x3f
};

// Tile g_tiles_059: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_059[2 * 4] = {
	0x7e, 0xe8,
	0x3f, 0xe8,
	0x7e, 0xe8,
	0xfc, 0xc0
};

// Tile g_tiles_060: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_060[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0x85, 0xdd
};

// Tile g_tiles_061: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_061[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0x8d, 0x4e
};

// Tile g_tiles_062: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_062[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xee, 0x4a
};

// Tile g_tiles_063: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_063[2 * 4] = {
	0xd5, 0xc6,
	0x95, 0xc3,
	0x85, 0xcc,
	0x85, 0xdd
};

// Tile g_tiles_064: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_064[2 * 4] = {
	0xd7, 0xeb,
	0x97, 0x6b,
	0x8d, 0x4e,
	0x8d, 0x4e
};

// Tile g_tiles_065: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_065[2 * 4] = {
	0xc9, 0xea,
	0xc3, 0x6a,
	0xcc, 0x4a,
	0xee, 0x4a
};

// Tile g_tiles_066: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_066[2 * 4] = {
	0x85, 0xc8,
	0x85, 0xcc,
	0x85, 0xcc,
	0xd4, 0x0f
};

// Tile g_tiles_067: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_067[2 * 4] = {
	0x8d, 0x4e,
	0x8d, 0x4e,
	0x8d, 0x4e,
	0xff, 0xff
};

// Tile g_tiles_068: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_068[2 * 4] = {
	0xc4, 0x4a,
	0xcc, 0x4a,
	0xcc, 0x4a,
	0x0f, 0xe8
};

// Tile g_tiles_069: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_069[2 * 4] = {
	0xc0, 0xc0,
	0x85, 0xc4,
	0x85, 0xcc,
	0xd4, 0x0f
};

// Tile g_tiles_070: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_070[2 * 4] = {
	0x6a, 0x95,
	0x4a, 0x8d,
	0x0f, 0x0f,
	0xc0, 0xc0
};

// Tile g_tiles_071: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_071[2 * 4] = {
	0xc0, 0xc0,
	0xc4, 0x4a,
	0xcc, 0x4a,
	0x0f, 0xe8
};

// Tile g_tiles_072: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_072[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_073: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_073[2 * 4] = {
	0xc0, 0xc0,
	0xd5, 0xea,
	0xea, 0x95,
	0x6a, 0x95
};

// Tile g_tiles_074: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_074[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_075: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_075[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0x95,
	0xc0, 0x95
};

// Tile g_tiles_076: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_076[2 * 4] = {
	0x95, 0x4a,
	0x7f, 0x2f,
	0x7f, 0x3f,
	0xff, 0x3f
};

// Tile g_tiles_077: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_077[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0x4a, 0xc0,
	0x4a, 0xc0
};

// Tile g_tiles_078: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_078[2 * 4] = {
	0xc0, 0x3f,
	0xc0, 0x3f,
	0x95, 0x7f,
	0x95, 0x7f
};

// Tile g_tiles_079: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_079[2 * 4] = {
	0xff, 0x3f,
	0xff, 0x3f,
	0xff, 0x3f,
	0xff, 0x3f
};

// Tile g_tiles_080: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_080[2 * 4] = {
	0x0f, 0xc0,
	0x0f, 0xc0,
	0x2f, 0x4a,
	0x2f, 0x4a
};

// Tile g_tiles_081: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_081[2 * 4] = {
	0xbf, 0xff,
	0x6a, 0xc0,
	0x95, 0x0f,
	0xc0, 0xc0
};

// Tile g_tiles_082: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_082[2 * 4] = {
	0xbf, 0x3f,
	0x85, 0x4a,
	0x1f, 0x2f,
	0xd5, 0x6a
};

// Tile g_tiles_083: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_083[2 * 4] = {
	0x0f, 0x0f,
	0xc0, 0x85,
	0x0f, 0x4a,
	0xc0, 0xc0
};

// Tile g_tiles_084: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_084[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_085: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_085[2 * 4] = {
	0xc0, 0xc0,
	0xd5, 0xff,
	0xc0, 0xab,
	0xc0, 0xd5
};

// Tile g_tiles_086: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_086[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xff, 0xc0,
	0x57, 0xc0
};

// Tile g_tiles_087: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_087[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_088: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_088[2 * 4] = {
	0xc0, 0xd5,
	0xc0, 0xd5,
	0xc0, 0xd5,
	0xc0, 0xd5
};

// Tile g_tiles_089: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_089[2 * 4] = {
	0x03, 0xea,
	0xab, 0xea,
	0xab, 0xea,
	0x03, 0xea
};

// Tile g_tiles_090: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_090[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xd1, 0xc0,
	0xd1, 0xe2
};

// Tile g_tiles_091: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_091[2 * 4] = {
	0xc0, 0xff,
	0xc0, 0xab,
	0xd5, 0x03,
	0x03, 0x03
};

// Tile g_tiles_092: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_092[2 * 4] = {
	0x03, 0xea,
	0x57, 0xc0,
	0x57, 0xc0,
	0xea, 0xc0
};

// Tile g_tiles_093: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_093[2 * 4] = {
	0xc0, 0x79,
	0xc0, 0x84,
	0xc0, 0x3c,
	0xd1, 0x0c
};

// Tile g_tiles_094: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_094[2 * 4] = {
	0x81, 0x57,
	0x48, 0x42,
	0x0c, 0xc0,
	0x84, 0x3c
};

// Tile g_tiles_095: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_095[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_096: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_096[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_097: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_097[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_098: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_098[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_099: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_099[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_100: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_100[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_101: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_101[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_102: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_102[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_103: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_103[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_104: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_104[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_105: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_105[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_106: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_106[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_107: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_107[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_108: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_108[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_109: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_109[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_110: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_110[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_111: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_111[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_112: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_112[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_113: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_113[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_114: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_114[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_115: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_115[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_116: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_116[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_117: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_117[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_118: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_118[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_119: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_119[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

