#include "tiles.h"
// Data created with Img2CPC - (c) Retroworks - 2007-2017
// Palette uses hardware values.
const u8 g_palette[16] = { 0x4d, 0x54, 0x40, 0x4b, 0x44, 0x55, 0x57, 0x53, 0x5c, 0x4c, 0x4e, 0x47, 0x56, 0x52, 0x5e, 0x4a };

u8* const g_tileset[60] = { 
	g_tiles_00, g_tiles_01, g_tiles_02, g_tiles_03, g_tiles_04, g_tiles_05, g_tiles_06, g_tiles_07, g_tiles_08, g_tiles_09, g_tiles_10, g_tiles_11, g_tiles_12, g_tiles_13, g_tiles_14, g_tiles_15, g_tiles_16, g_tiles_17, g_tiles_18, g_tiles_19, g_tiles_20, g_tiles_21, g_tiles_22, g_tiles_23, g_tiles_24, g_tiles_25, g_tiles_26, g_tiles_27, g_tiles_28, g_tiles_29, g_tiles_30, g_tiles_31, g_tiles_32, g_tiles_33, g_tiles_34, g_tiles_35, g_tiles_36, g_tiles_37, g_tiles_38, g_tiles_39, g_tiles_40, g_tiles_41, g_tiles_42, g_tiles_43, g_tiles_44, g_tiles_45, g_tiles_46, g_tiles_47, g_tiles_48, g_tiles_49, g_tiles_50, g_tiles_51, g_tiles_52, g_tiles_53, g_tiles_54, g_tiles_55, g_tiles_56, g_tiles_57, g_tiles_58, g_tiles_59
};
// Tile g_tiles_00: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_00[2 * 4] = {
	0xc3, 0x42,
	0x83, 0x42,
	0x03, 0x42,
	0xc0, 0xc0
};

// Tile g_tiles_01: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_01[2 * 4] = {
	0xc3, 0x42,
	0x81, 0x03,
	0x42, 0x03,
	0x03, 0x81
};

// Tile g_tiles_02: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_02[2 * 4] = {
	0xff, 0xff,
	0xaf, 0x0f,
	0x0f, 0x0f,
	0x0b, 0x03
};

// Tile g_tiles_03: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_03[2 * 4] = {
	0xff, 0xff,
	0x0f, 0x0f,
	0x0f, 0x0f,
	0x03, 0x03
};

// Tile g_tiles_04: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_04[2 * 4] = {
	0xff, 0x0f,
	0x0f, 0x0b,
	0x0f, 0x0b,
	0x03, 0x03
};

// Tile g_tiles_05: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_05[2 * 4] = {
	0x0f, 0x0f,
	0x4b, 0xc3,
	0xc3, 0xc3,
	0x83, 0x03
};

// Tile g_tiles_06: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_06[2 * 4] = {
	0x0f, 0x0f,
	0xc3, 0xc3,
	0xc3, 0xc3,
	0x03, 0x03
};

// Tile g_tiles_07: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_07[2 * 4] = {
	0x0f, 0xc3,
	0xc3, 0x83,
	0xc3, 0x83,
	0x03, 0x03
};

// Tile g_tiles_08: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_08[2 * 4] = {
	0x4b, 0xc3,
	0x83, 0x03,
	0x03, 0x03,
	0x42, 0xc0
};

// Tile g_tiles_09: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_09[2 * 4] = {
	0xc3, 0xc3,
	0x03, 0x03,
	0x03, 0x03,
	0xc0, 0xc0
};

// Tile g_tiles_10: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_10[2 * 4] = {
	0xc3, 0x03,
	0x03, 0x42,
	0x03, 0x42,
	0xc0, 0xc0
};

// Tile g_tiles_11: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_11[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_12: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_12[2 * 4] = {
	0x4b, 0xc3,
	0x83, 0x03,
	0x83, 0x03,
	0x83, 0x03
};

// Tile g_tiles_13: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_13[2 * 4] = {
	0xc3, 0xc3,
	0x03, 0x03,
	0x03, 0x03,
	0x03, 0x03
};

// Tile g_tiles_14: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_14[2 * 4] = {
	0xc3, 0x03,
	0x03, 0x42,
	0x03, 0x42,
	0x03, 0x42
};

// Tile g_tiles_15: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_15[2 * 4] = {
	0xff, 0xff,
	0xaf, 0x0f,
	0xaf, 0x0f,
	0xaf, 0x0f
};

// Tile g_tiles_16: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_16[2 * 4] = {
	0xff, 0xff,
	0x0f, 0x0f,
	0x0f, 0x0f,
	0x0f, 0x0f
};

// Tile g_tiles_17: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_17[2 * 4] = {
	0xff, 0xaf,
	0x0f, 0x0b,
	0x0f, 0x0b,
	0x0f, 0x0b
};

// Tile g_tiles_18: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_18[2 * 4] = {
	0x4c, 0x48,
	0xcf, 0xcc,
	0x83, 0xc0,
	0x42, 0x0c
};

// Tile g_tiles_19: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_19[2 * 4] = {
	0xc0, 0xba,
	0x48, 0xc4,
	0xc0, 0xd5,
	0xc8, 0x95
};

// Tile g_tiles_20: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_20[2 * 4] = {
	0xd5, 0xc0,
	0xc8, 0x84,
	0xea, 0xc0,
	0x6a, 0xc4
};

// Tile g_tiles_21: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_21[2 * 4] = {
	0x84, 0x8c,
	0xcc, 0xcf,
	0xc0, 0x43,
	0x0c, 0x81
};

// Tile g_tiles_22: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_22[2 * 4] = {
	0x0c, 0x90,
	0xcf, 0x90,
	0xc7, 0x66,
	0xc3, 0x73
};

// Tile g_tiles_23: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_23[2 * 4] = {
	0xc0, 0x90,
	0x81, 0x12,
	0xcd, 0x9a,
	0xe3, 0xc2
};

// Tile g_tiles_24: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_24[2 * 4] = {
	0x83, 0x03,
	0x83, 0x03,
	0x03, 0x03,
	0x42, 0xc0
};

// Tile g_tiles_25: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_25[2 * 4] = {
	0x03, 0x03,
	0x03, 0x03,
	0x03, 0x03,
	0xc0, 0xc0
};

// Tile g_tiles_26: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_26[2 * 4] = {
	0x03, 0x42,
	0x03, 0x42,
	0x03, 0x42,
	0xc0, 0xc0
};

// Tile g_tiles_27: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_27[2 * 4] = {
	0xaf, 0x0f,
	0xaf, 0x0f,
	0xaf, 0x0f,
	0x0b, 0x03
};

// Tile g_tiles_28: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_28[2 * 4] = {
	0x0f, 0x0f,
	0x0f, 0x0f,
	0x0f, 0x0f,
	0x03, 0x03
};

// Tile g_tiles_29: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_29[2 * 4] = {
	0x0f, 0x0b,
	0x0f, 0x0b,
	0x0f, 0x0b,
	0x03, 0x42
};

// Tile g_tiles_30: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_30[2 * 4] = {
	0x84, 0x03,
	0x84, 0x43,
	0xc0, 0x90,
	0x6e, 0x6a
};

// Tile g_tiles_31: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_31[2 * 4] = {
	0x42, 0x3a,
	0xca, 0x90,
	0xc0, 0x90,
	0x90, 0x60
};

// Tile g_tiles_32: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_32[2 * 4] = {
	0x95, 0x81,
	0xc0, 0xc5,
	0xc0, 0xc0,
	0x90, 0x60
};

// Tile g_tiles_33: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_33[2 * 4] = {
	0x03, 0x48,
	0x83, 0x48,
	0xc0, 0xc0,
	0x95, 0x9d
};

// Tile g_tiles_34: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_34[2 * 4] = {
	0x43, 0x90,
	0x03, 0x90,
	0xc0, 0x90,
	0x90, 0x60
};

// Tile g_tiles_35: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_35[2 * 4] = {
	0x81, 0x12,
	0xc0, 0x90,
	0xc0, 0x90,
	0x90, 0x60
};

// Tile g_tiles_36: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_36[2 * 4] = {
	0x83, 0x03,
	0x83, 0x03,
	0x83, 0x03,
	0x42, 0xc0
};

// Tile g_tiles_37: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_37[2 * 4] = {
	0x03, 0x42,
	0x03, 0x42,
	0x03, 0x42,
	0xc0, 0xc0
};

// Tile g_tiles_38: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_38[2 * 4] = {
	0x94, 0x78,
	0x94, 0x3c,
	0x94, 0x3c,
	0xc0, 0x30
};

// Tile g_tiles_39: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_39[2 * 4] = {
	0xb0, 0x38,
	0x30, 0x68,
	0x3c, 0x38,
	0x30, 0x30
};

// Tile g_tiles_40: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_40[2 * 4] = {
	0xc0, 0x90,
	0xc0, 0x90,
	0xc0, 0x90,
	0x90, 0x60
};

// Tile g_tiles_41: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_41[2 * 4] = {
	0xc0, 0x90,
	0xc0, 0x4c,
	0xc5, 0xe8,
	0x83, 0x03
};

// Tile g_tiles_42: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_42[2 * 4] = {
	0x4c, 0x18,
	0x8c, 0x0c,
	0x68, 0xe0,
	0x03, 0x03
};

// Tile g_tiles_43: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_43[2 * 4] = {
	0xc0, 0x90,
	0x48, 0x90,
	0x65, 0x90,
	0x03, 0xc2
};

// Tile g_tiles_44: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_44[2 * 4] = {
	0xc0, 0x90,
	0xc0, 0x84,
	0xc0, 0x9a,
	0xc1, 0x03
};

// Tile g_tiles_45: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_45[2 * 4] = {
	0x84, 0x8c,
	0xcc, 0x0c,
	0xd0, 0x94,
	0x03, 0x03
};

// Tile g_tiles_46: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_46[2 * 4] = {
	0xc0, 0x90,
	0x0c, 0x90,
	0xd4, 0xca,
	0x03, 0x43
};

// Tile g_tiles_47: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_47[2 * 4] = {
	0xc0, 0x90,
	0xc0, 0x90,
	0xc0, 0x90,
	0x90, 0x60
};

// Tile g_tiles_48: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_48[2 * 4] = {
	0x95, 0xaf,
	0x95, 0x4a,
	0x95, 0x1f,
	0x95, 0x4a
};

// Tile g_tiles_49: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_49[2 * 4] = {
	0x5f, 0x5f,
	0x17, 0x17,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_50: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_50[2 * 4] = {
	0xaf, 0xff,
	0x03, 0x3f,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_51: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_51[2 * 4] = {
	0xdd, 0x6a,
	0xc4, 0x6a,
	0x2f, 0x6a,
	0xd5, 0x6a
};

// Tile g_tiles_52: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_52[2 * 4] = {
	0x95, 0x0f,
	0x95, 0xea,
	0x95, 0x1f,
	0x95, 0xea
};

// Tile g_tiles_53: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_53[2 * 4] = {
	0xaf, 0xaf,
	0x2b, 0x17,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_54: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_54[2 * 4] = {
	0x5f, 0xff,
	0x03, 0x3f,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_55: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_55[2 * 4] = {
	0xaf, 0x6a,
	0xc4, 0x6a,
	0x2f, 0x6a,
	0x85, 0x6a
};

// Tile g_tiles_56: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_56[2 * 4] = {
	0xc0, 0xc1,
	0x91, 0xf3,
	0x33, 0x66,
	0x62, 0xea
};

// Tile g_tiles_57: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_57[2 * 4] = {
	0xea, 0xc0,
	0xd9, 0x62,
	0x66, 0x33,
	0xea, 0xbb
};

// Tile g_tiles_58: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_58[2 * 4] = {
	0x9c, 0x3c,
	0x78, 0xf0,
	0x78, 0xf0,
	0xb0, 0x30
};

// Tile g_tiles_59: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_59[2 * 4] = {
	0x3c, 0x3c,
	0xf0, 0xf0,
	0xf0, 0xb0,
	0x30, 0x30
};

