#include "tiles.h"
// Data created with Img2CPC - (c) Retroworks - 2007-2017
// Palette uses hardware values.
const u8 g_palette[16] = { 0x4d, 0x54, 0x55, 0x5c, 0x58, 0x56, 0x57, 0x5e, 0x40, 0x4c, 0x4e, 0x47, 0x52, 0x53, 0x4a, 0x4b };

u8* const g_tileset[240] = { 
	g_tiles_000, g_tiles_001, g_tiles_002, g_tiles_003, g_tiles_004, g_tiles_005, g_tiles_006, g_tiles_007, g_tiles_008, g_tiles_009, g_tiles_010, g_tiles_011, g_tiles_012, g_tiles_013, g_tiles_014, g_tiles_015, g_tiles_016, g_tiles_017, g_tiles_018, g_tiles_019, g_tiles_020, g_tiles_021, g_tiles_022, g_tiles_023, g_tiles_024, g_tiles_025, g_tiles_026, g_tiles_027, g_tiles_028, g_tiles_029, g_tiles_030, g_tiles_031, g_tiles_032, g_tiles_033, g_tiles_034, g_tiles_035, g_tiles_036, g_tiles_037, g_tiles_038, g_tiles_039, g_tiles_040, g_tiles_041, g_tiles_042, g_tiles_043, g_tiles_044, g_tiles_045, g_tiles_046, g_tiles_047, g_tiles_048, g_tiles_049, g_tiles_050, g_tiles_051, g_tiles_052, g_tiles_053, g_tiles_054, g_tiles_055, g_tiles_056, g_tiles_057, g_tiles_058, g_tiles_059, g_tiles_060, g_tiles_061, g_tiles_062, g_tiles_063, g_tiles_064, g_tiles_065, g_tiles_066, g_tiles_067, g_tiles_068, g_tiles_069, g_tiles_070, g_tiles_071, g_tiles_072, g_tiles_073, g_tiles_074, g_tiles_075, g_tiles_076, g_tiles_077, g_tiles_078, g_tiles_079, g_tiles_080, g_tiles_081, g_tiles_082, g_tiles_083, g_tiles_084, g_tiles_085, g_tiles_086, g_tiles_087, g_tiles_088, g_tiles_089, g_tiles_090, g_tiles_091, g_tiles_092, g_tiles_093, g_tiles_094, g_tiles_095, g_tiles_096, g_tiles_097, g_tiles_098, g_tiles_099, g_tiles_100, g_tiles_101, g_tiles_102, g_tiles_103, g_tiles_104, g_tiles_105, g_tiles_106, g_tiles_107, g_tiles_108, g_tiles_109, g_tiles_110, g_tiles_111, g_tiles_112, g_tiles_113, g_tiles_114, g_tiles_115, g_tiles_116, g_tiles_117, g_tiles_118, g_tiles_119, g_tiles_120, g_tiles_121, g_tiles_122, g_tiles_123, g_tiles_124, g_tiles_125, g_tiles_126, g_tiles_127, g_tiles_128, g_tiles_129, g_tiles_130, g_tiles_131, g_tiles_132, g_tiles_133, g_tiles_134, g_tiles_135, g_tiles_136, g_tiles_137, g_tiles_138, g_tiles_139, g_tiles_140, g_tiles_141, g_tiles_142, g_tiles_143, g_tiles_144, g_tiles_145, g_tiles_146, g_tiles_147, g_tiles_148, g_tiles_149, g_tiles_150, g_tiles_151, g_tiles_152, g_tiles_153, g_tiles_154, g_tiles_155, g_tiles_156, g_tiles_157, g_tiles_158, g_tiles_159, g_tiles_160, g_tiles_161, g_tiles_162, g_tiles_163, g_tiles_164, g_tiles_165, g_tiles_166, g_tiles_167, g_tiles_168, g_tiles_169, g_tiles_170, g_tiles_171, g_tiles_172, g_tiles_173, g_tiles_174, g_tiles_175, g_tiles_176, g_tiles_177, g_tiles_178, g_tiles_179, g_tiles_180, g_tiles_181, g_tiles_182, g_tiles_183, g_tiles_184, g_tiles_185, g_tiles_186, g_tiles_187, g_tiles_188, g_tiles_189, g_tiles_190, g_tiles_191, g_tiles_192, g_tiles_193, g_tiles_194, g_tiles_195, g_tiles_196, g_tiles_197, g_tiles_198, g_tiles_199, g_tiles_200, g_tiles_201, g_tiles_202, g_tiles_203, g_tiles_204, g_tiles_205, g_tiles_206, g_tiles_207, g_tiles_208, g_tiles_209, g_tiles_210, g_tiles_211, g_tiles_212, g_tiles_213, g_tiles_214, g_tiles_215, g_tiles_216, g_tiles_217, g_tiles_218, g_tiles_219, g_tiles_220, g_tiles_221, g_tiles_222, g_tiles_223, g_tiles_224, g_tiles_225, g_tiles_226, g_tiles_227, g_tiles_228, g_tiles_229, g_tiles_230, g_tiles_231, g_tiles_232, g_tiles_233, g_tiles_234, g_tiles_235, g_tiles_236, g_tiles_237, g_tiles_238, g_tiles_239
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
	0x6b, 0xc2,
	0xc3, 0xc8,
	0xcc, 0xc8,
	0xc0, 0xc0
};

// Tile g_tiles_003: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_003[2 * 4] = {
	0xc6, 0xc8,
	0xc1, 0xcc,
	0xc8, 0xcc,
	0xcc, 0xc4
};

// Tile g_tiles_004: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_004[2 * 4] = {
	0xc3, 0xc2,
	0xc1, 0xcc,
	0xc8, 0xc6,
	0xc3, 0xc1
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
	0xc0, 0xee,
	0xc0, 0x4b,
	0xc0, 0xc6
};

// Tile g_tiles_008: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_008[2 * 4] = {
	0xc0, 0xc0,
	0xc9, 0xc0,
	0x87, 0xc0,
	0x61, 0xc0
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
	0x85, 0x87,
	0x85, 0xc0,
	0x85, 0xc0,
	0x85, 0xc0
};

// Tile g_tiles_013: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_013[2 * 4] = {
	0x0f, 0x3f,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_014: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_014[2 * 4] = {
	0xbf, 0x4a,
	0xc0, 0x4a,
	0xc0, 0x4a,
	0xc0, 0x4a
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
	0x0f, 0x1f
};

// Tile g_tiles_017: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_017[2 * 4] = {
	0x85, 0xc0,
	0x95, 0xc0,
	0xd5, 0xc4,
	0xd5, 0x2f
};

// Tile g_tiles_018: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_018[2 * 4] = {
	0xc0, 0xc0,
	0x6a, 0x4a,
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
	0x42, 0x81,
	0xea, 0xd5,
	0xd5, 0xc0,
	0xc0, 0xff
};

// Tile g_tiles_034: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_034[2 * 4] = {
	0x81, 0x81,
	0xd5, 0x81,
	0xd5, 0x42,
	0x57, 0xc0
};

// Tile g_tiles_035: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_035[2 * 4] = {
	0xc0, 0x42,
	0xc0, 0x42,
	0xc0, 0x42,
	0xc0, 0x42
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
	0xc0, 0x81,
	0xc0, 0xd5,
	0xc0, 0xd5,
	0xc0, 0x81
};

// Tile g_tiles_046: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_046[2 * 4] = {
	0xc0, 0xea,
	0xc0, 0xd5,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_047: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_047[2 * 4] = {
	0x81, 0xc0,
	0xea, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_048: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_048[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xd5,
	0xc0, 0xea,
	0xc0, 0xbf
};

// Tile g_tiles_049: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_049[2 * 4] = {
	0xc0, 0xc0,
	0xff, 0x3f,
	0x95, 0x95,
	0xe8, 0xbd
};

// Tile g_tiles_050: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_050[2 * 4] = {
	0xc0, 0xc0,
	0x95, 0x6a,
	0x6a, 0xbd,
	0xc0, 0xc0
};

// Tile g_tiles_051: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_051[2 * 4] = {
	0xc0, 0x95,
	0xc0, 0xc0,
	0xc0, 0xd5,
	0xc0, 0xbf
};

// Tile g_tiles_052: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_052[2 * 4] = {
	0x3f, 0xe8,
	0x7e, 0xe8,
	0x3f, 0x7e,
	0x6a, 0x3f
};

// Tile g_tiles_053: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_053[2 * 4] = {
	0xbd, 0xe8,
	0xc0, 0x6a,
	0xc0, 0xc0,
	0xe8, 0xc0
};

// Tile g_tiles_054: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_054[2 * 4] = {
	0xd4, 0x3f,
	0x95, 0x6a,
	0x95, 0x3f,
	0x95, 0x3f
};

// Tile g_tiles_055: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_055[2 * 4] = {
	0xc0, 0x95,
	0x7e, 0x3f,
	0xc0, 0x95,
	0x7e, 0x6a
};

// Tile g_tiles_056: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_056[2 * 4] = {
	0x7e, 0xc0,
	0x3f, 0xc0,
	0x3f, 0xc0,
	0x7e, 0xc0
};

// Tile g_tiles_057: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_057[2 * 4] = {
	0x95, 0x3f,
	0xd4, 0x3f,
	0xc0, 0xbd,
	0xc0, 0xc0
};

// Tile g_tiles_058: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_058[2 * 4] = {
	0xc0, 0x95,
	0x6a, 0x3f,
	0x3f, 0x3f,
	0xc0, 0xc0
};

// Tile g_tiles_059: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_059[2 * 4] = {
	0x3f, 0xc0,
	0x7e, 0xc0,
	0xe8, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_060: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_060[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0x85, 0xdd,
	0xd5, 0xc6
};

// Tile g_tiles_061: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_061[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0x8d, 0x4e,
	0xd7, 0xeb
};

// Tile g_tiles_062: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_062[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xee, 0x4a,
	0xc9, 0xea
};

// Tile g_tiles_063: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_063[2 * 4] = {
	0x95, 0xc3,
	0x85, 0xcc,
	0x85, 0xdd,
	0x85, 0xc8
};

// Tile g_tiles_064: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_064[2 * 4] = {
	0x97, 0x6b,
	0x8d, 0x4e,
	0x8d, 0x4e,
	0x8d, 0x4e
};

// Tile g_tiles_065: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_065[2 * 4] = {
	0xc3, 0x6a,
	0xcc, 0x4a,
	0xee, 0x4a,
	0xc4, 0x4a
};

// Tile g_tiles_066: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_066[2 * 4] = {
	0x85, 0xcc,
	0x85, 0xcc,
	0xd4, 0x0f,
	0xc0, 0xc0
};

// Tile g_tiles_067: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_067[2 * 4] = {
	0x8d, 0x4e,
	0x8d, 0x4e,
	0xff, 0xff,
	0x6a, 0x95
};

// Tile g_tiles_068: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_068[2 * 4] = {
	0xcc, 0x4a,
	0xcc, 0x4a,
	0x0f, 0xe8,
	0xc0, 0xc0
};

// Tile g_tiles_069: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_069[2 * 4] = {
	0x85, 0xc4,
	0x85, 0xcc,
	0xd4, 0x0f,
	0xc0, 0xc0
};

// Tile g_tiles_070: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_070[2 * 4] = {
	0x4a, 0x8d,
	0x0f, 0x0f,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_071: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_071[2 * 4] = {
	0xc4, 0x4a,
	0xcc, 0x4a,
	0x0f, 0xe8,
	0xc0, 0xc0
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
	0xd5, 0xea,
	0xea, 0x95,
	0x6a, 0x95,
	0x95, 0x4a
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
	0xc0, 0x95,
	0xc0, 0x95,
	0xc0, 0x95
};

// Tile g_tiles_076: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_076[2 * 4] = {
	0x7f, 0x2f,
	0x7f, 0x3f,
	0xff, 0x3f,
	0xff, 0x3f
};

// Tile g_tiles_077: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_077[2 * 4] = {
	0xc0, 0xc0,
	0x4a, 0xc0,
	0x4a, 0xc0,
	0x4a, 0xc0
};

// Tile g_tiles_078: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_078[2 * 4] = {
	0xc0, 0x95,
	0xc0, 0x7f,
	0xc0, 0x7f,
	0xd5, 0x7f
};

// Tile g_tiles_079: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_079[2 * 4] = {
	0xff, 0x3f,
	0xff, 0x3f,
	0xff, 0x3f,
	0xbf, 0x3f
};

// Tile g_tiles_080: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_080[2 * 4] = {
	0x4a, 0xc0,
	0x2f, 0xc0,
	0x2f, 0xc0,
	0x0f, 0x4a
};

// Tile g_tiles_081: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_081[2 * 4] = {
	0x95, 0xc0,
	0xc0, 0x2f,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_082: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_082[2 * 4] = {
	0x85, 0x4a,
	0x1f, 0x2f,
	0xd5, 0x6a,
	0xc0, 0xc0
};

// Tile g_tiles_083: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_083[2 * 4] = {
	0xc0, 0x4a,
	0x0f, 0xc0,
	0xc0, 0xc0,
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
	0xd5, 0xff,
	0xc0, 0xab,
	0xc0, 0xd5,
	0xc0, 0xd5
};

// Tile g_tiles_086: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_086[2 * 4] = {
	0xc0, 0xc0,
	0xff, 0xc0,
	0x57, 0xc0,
	0x03, 0xea
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
	0xc0, 0xff
};

// Tile g_tiles_089: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_089[2 * 4] = {
	0xab, 0xea,
	0xab, 0xea,
	0x03, 0xea,
	0x03, 0xea
};

// Tile g_tiles_090: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_090[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xd1, 0xea,
	0xc0, 0x79
};

// Tile g_tiles_091: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_091[2 * 4] = {
	0xc0, 0xab,
	0xd5, 0x03,
	0x03, 0x03,
	0x81, 0x57
};

// Tile g_tiles_092: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_092[2 * 4] = {
	0x57, 0xc0,
	0x57, 0xc0,
	0xea, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_093: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_093[2 * 4] = {
	0xc0, 0x84,
	0xc0, 0x3c,
	0xd1, 0x0c,
	0xc0, 0xc0
};

// Tile g_tiles_094: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_094[2 * 4] = {
	0x68, 0x42,
	0x1c, 0xc0,
	0x84, 0x3c,
	0xc0, 0xc0
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
	0xc0, 0xff,
	0xc0, 0x90,
	0xd5, 0xca
};

// Tile g_tiles_097: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_097[2 * 4] = {
	0xc0, 0xc0,
	0xef, 0xcf,
	0xdf, 0xcf,
	0x75, 0x9a
};

// Tile g_tiles_098: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_098[2 * 4] = {
	0xc0, 0xc0,
	0x9a, 0xc0,
	0x60, 0xc0,
	0xc5, 0xea
};

// Tile g_tiles_099: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_099[2 * 4] = {
	0xea, 0xc5,
	0xea, 0x90,
	0xca, 0x60,
	0xca, 0xc0
};

// Tile g_tiles_100: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_100[2 * 4] = {
	0xd5, 0xca,
	0xd5, 0xca,
	0xd5, 0xca,
	0x75, 0x9a
};

// Tile g_tiles_101: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_101[2 * 4] = {
	0xca, 0xd5,
	0x60, 0xc5,
	0x90, 0xc5,
	0xc0, 0xc5
};

// Tile g_tiles_102: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_102[2 * 4] = {
	0xca, 0x90,
	0xca, 0x65,
	0x60, 0x65,
	0xca, 0x65
};

// Tile g_tiles_103: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_103[2 * 4] = {
	0xdf, 0xcf,
	0xff, 0xef,
	0xff, 0xef,
	0xdf, 0xcf
};

// Tile g_tiles_104: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_104[2 * 4] = {
	0x60, 0x90,
	0x30, 0xc5,
	0x30, 0x90,
	0x30, 0x90
};

// Tile g_tiles_105: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_105[2 * 4] = {
	0x90, 0x90,
	0xc0, 0xc0,
	0xc0, 0x90,
	0xc0, 0xc0
};

// Tile g_tiles_106: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_106[2 * 4] = {
	0xcf, 0x9a,
	0x30, 0x30,
	0xdf, 0x9a,
	0xc0, 0xc0
};

// Tile g_tiles_107: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_107[2 * 4] = {
	0x60, 0x60,
	0xc0, 0xc0,
	0x60, 0xc0,
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
	0xc0, 0xd5,
	0xc0, 0xd5,
	0xc0, 0xfb
};

// Tile g_tiles_110: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_110[2 * 4] = {
	0xea, 0xc0,
	0xff, 0xc0,
	0xf3, 0x68,
	0xb6, 0x0c
};

// Tile g_tiles_111: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_111[2 * 4] = {
	0xd5, 0xc0,
	0xf3, 0xc0,
	0xd1, 0x29,
	0xc0, 0xa6
};

// Tile g_tiles_112: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_112[2 * 4] = {
	0xd5, 0xf3,
	0xf3, 0xb6,
	0x59, 0x2c,
	0x94, 0x48
};

// Tile g_tiles_113: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_113[2 * 4] = {
	0x2c, 0x48,
	0x48, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_114: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_114[2 * 4] = {
	0xc0, 0xb6,
	0xc0, 0x3c,
	0x85, 0x8c,
	0x85, 0xc6
};

// Tile g_tiles_115: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_115[2 * 4] = {
	0x2c, 0x59,
	0x0c, 0xc0,
	0x1c, 0xc0,
	0x84, 0x3c
};

// Tile g_tiles_116: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_116[2 * 4] = {
	0xc0, 0xc0,
	0xe2, 0xc0,
	0x68, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_117: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_117[2 * 4] = {
	0xc1, 0xc6,
	0xc1, 0xc6,
	0xc0, 0xcc,
	0xc0, 0xc0
};

// Tile g_tiles_118: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_118[2 * 4] = {
	0xc0, 0xc0,
	0xc8, 0xc0,
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

// Tile g_tiles_120: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_120[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_121: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_121[2 * 4] = {
	0xd5, 0x6a,
	0xea, 0x95,
	0xea, 0xd4,
	0x95, 0x6a
};

// Tile g_tiles_122: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_122[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_123: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_123[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xd5, 0xd5,
	0x95, 0xd4
};

// Tile g_tiles_124: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_124[2 * 4] = {
	0xd5, 0xe8,
	0xbf, 0x3f,
	0x3f, 0x3f,
	0x7e, 0x7e
};

// Tile g_tiles_125: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_125[2 * 4] = {
	0xc0, 0xc0,
	0x6a, 0x6a,
	0x6a, 0x6a,
	0x6a, 0xe8
};

// Tile g_tiles_126: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_126[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xd5, 0xd4,
	0x95, 0x6a
};

// Tile g_tiles_127: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_127[2 * 4] = {
	0xfc, 0xfc,
	0xc0, 0xc0,
	0x95, 0xe8,
	0x95, 0xe8
};

// Tile g_tiles_128: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_128[2 * 4] = {
	0xe8, 0xe8,
	0xc0, 0xc0,
	0xe8, 0x6a,
	0x95, 0x6a
};

// Tile g_tiles_129: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_129[2 * 4] = {
	0xd4, 0x3f,
	0xc0, 0xfc,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_130: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_130[2 * 4] = {
	0x3f, 0x3f,
	0x3f, 0xbd,
	0xfc, 0xfc,
	0xc0, 0xc0
};

// Tile g_tiles_131: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_131[2 * 4] = {
	0x3f, 0xe8,
	0xfc, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_132: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_132[2 * 4] = {
	0xc0, 0xc0,
	0x59, 0x48,
	0xf7, 0xa6,
	0x7d, 0xb6
};

// Tile g_tiles_133: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_133[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0x48, 0xc0
};

// Tile g_tiles_134: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_134[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_135: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_135[2 * 4] = {
	0x1c, 0xfb,
	0x84, 0xf7,
	0xc0, 0x68,
	0xc0, 0x1c
};

// Tile g_tiles_136: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_136[2 * 4] = {
	0x2c, 0xc0,
	0xd1, 0x48,
	0xfb, 0x2c,
	0xf7, 0xb6
};

// Tile g_tiles_137: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_137[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0x48, 0xc0
};

// Tile g_tiles_138: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_138[2 * 4] = {
	0xc0, 0x84,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_139: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_139[2 * 4] = {
	0x79, 0xfb,
	0x79, 0xea,
	0x1c, 0xd5,
	0x84, 0x79
};

// Tile g_tiles_140: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_140[2 * 4] = {
	0x0c, 0xc0,
	0xb6, 0x48,
	0xf3, 0x2c,
	0xae, 0x1c
};

// Tile g_tiles_141: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_141[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_142: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_142[2 * 4] = {
	0xc0, 0x79,
	0xc0, 0x1c,
	0xc0, 0x84,
	0xc0, 0xc0
};

// Tile g_tiles_143: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_143[2 * 4] = {
	0x48, 0x94,
	0x48, 0x68,
	0x3c, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_144: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_144[2 * 4] = {
	0xc0, 0xc0,
	0xc4, 0xdc,
	0xc9, 0x9d,
	0xc9, 0xc9
};

// Tile g_tiles_145: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_145[2 * 4] = {
	0xc0, 0xc0,
	0x6e, 0xcc,
	0xc3, 0xc3,
	0xc3, 0xc3
};

// Tile g_tiles_146: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_146[2 * 4] = {
	0xc0, 0xc0,
	0x9d, 0xe8,
	0xc3, 0x6a,
	0xc3, 0xc8
};

// Tile g_tiles_147: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_147[2 * 4] = {
	0xc9, 0xc9,
	0xc9, 0xc9,
	0xc9, 0xc9,
	0xc9, 0xc9
};

// Tile g_tiles_148: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_148[2 * 4] = {
	0xcc, 0xcc,
	0xc3, 0xc3,
	0xc9, 0xcc,
	0xc3, 0xc3
};

// Tile g_tiles_149: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_149[2 * 4] = {
	0xc9, 0xc8,
	0xc3, 0xc8,
	0xc9, 0xc8,
	0xc3, 0xc8
};

// Tile g_tiles_150: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_150[2 * 4] = {
	0xc9, 0xc9,
	0xc9, 0xc9,
	0xc9, 0xc9,
	0xc9, 0x9d
};

// Tile g_tiles_151: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_151[2 * 4] = {
	0xc3, 0xc3,
	0xc3, 0xc9,
	0xc6, 0xc6,
	0xc3, 0xc9
};

// Tile g_tiles_152: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_152[2 * 4] = {
	0xc6, 0xc8,
	0xc9, 0xc8,
	0xc6, 0xc8,
	0xc9, 0x6a
};

// Tile g_tiles_153: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_153[2 * 4] = {
	0xcc, 0xdc,
	0xcd, 0xcf,
	0xc4, 0xcc,
	0xc0, 0xc0
};

// Tile g_tiles_154: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_154[2 * 4] = {
	0x6e, 0xcc,
	0xcf, 0xcf,
	0xcc, 0xcc,
	0xc0, 0xc0
};

// Tile g_tiles_155: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_155[2 * 4] = {
	0x9d, 0xe8,
	0xcf, 0xc8,
	0xcc, 0xc8,
	0xc0, 0xc0
};

// Tile g_tiles_156: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_156[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xcc,
	0xc4, 0x0f,
	0x9d, 0x3f
};

// Tile g_tiles_157: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_157[2 * 4] = {
	0xc0, 0xc0,
	0xcc, 0xcc,
	0x0f, 0x0f,
	0x3f, 0x3f
};

// Tile g_tiles_158: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_158[2 * 4] = {
	0xc0, 0xc0,
	0xcc, 0xc0,
	0x4e, 0xc8,
	0x8d, 0x4e
};

// Tile g_tiles_159: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_159[2 * 4] = {
	0x9d, 0x3f,
	0xc4, 0x0f,
	0xc0, 0xcc,
	0xc0, 0x9d
};

// Tile g_tiles_160: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_160[2 * 4] = {
	0x3f, 0x6e,
	0x0f, 0x0f,
	0xcc, 0xcc,
	0x3f, 0x3f
};

// Tile g_tiles_161: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_161[2 * 4] = {
	0x0f, 0x6e,
	0x8d, 0x4e,
	0x9d, 0xc8,
	0x2f, 0xc8
};

// Tile g_tiles_162: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_162[2 * 4] = {
	0xc4, 0x4e,
	0x8d, 0x3f,
	0x9d, 0xcc,
	0x9d, 0x3f
};

// Tile g_tiles_163: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_163[2 * 4] = {
	0x6e, 0xcc,
	0x3f, 0x3f,
	0x6e, 0x9d,
	0x3f, 0x3f
};

// Tile g_tiles_164: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_164[2 * 4] = {
	0x6e, 0xc0,
	0x6e, 0xc0,
	0x4e, 0xcc,
	0x8d, 0x2f
};

// Tile g_tiles_165: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_165[2 * 4] = {
	0x8d, 0x4e,
	0xc4, 0x0f,
	0xc0, 0xcc,
	0xc0, 0xc0
};

// Tile g_tiles_166: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_166[2 * 4] = {
	0x9d, 0x9d,
	0x0f, 0x0f,
	0xcc, 0xcc,
	0xc0, 0xc0
};

// Tile g_tiles_167: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_167[2 * 4] = {
	0x8d, 0x0f,
	0x4e, 0x4e,
	0xcc, 0xc8,
	0xc0, 0xc0
};

// Tile g_tiles_168: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_168[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_169: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_169[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0x85, 0xc0,
	0xc1, 0xc0
};

// Tile g_tiles_170: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_170[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0x4a, 0xc0
};

// Tile g_tiles_171: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_171[2 * 4] = {
	0xc0, 0x4a,
	0xc0, 0xc2,
	0xd5, 0x7e,
	0xc0, 0xe8
};

// Tile g_tiles_172: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_172[2 * 4] = {
	0xbf, 0x6a,
	0xd4, 0xc0,
	0x95, 0xd4,
	0x95, 0xc0
};

// Tile g_tiles_173: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_173[2 * 4] = {
	0xc2, 0xc0,
	0xc2, 0xc0,
	0x3f, 0xc0,
	0xe8, 0xc0
};

// Tile g_tiles_174: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_174[2 * 4] = {
	0xc0, 0x6a,
	0xc0, 0xfe,
	0xc0, 0xbd,
	0xc0, 0xc0
};

// Tile g_tiles_175: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_175[2 * 4] = {
	0x95, 0xc0,
	0x95, 0xd4,
	0x3f, 0x3f,
	0x95, 0xc0
};

// Tile g_tiles_176: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_176[2 * 4] = {
	0x6a, 0xc0,
	0x6a, 0xc0,
	0xe8, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_177: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_177[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xd5
};

// Tile g_tiles_178: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_178[2 * 4] = {
	0x95, 0xc0,
	0x95, 0xc0,
	0xbf, 0xe8,
	0x7e, 0xfc
};

// Tile g_tiles_179: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_179[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_180: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_180[2 * 4] = {
	0xc0, 0xcc,
	0xc4, 0x8d,
	0xc1, 0xc9,
	0xc9, 0xc9
};

// Tile g_tiles_181: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_181[2 * 4] = {
	0xcc, 0xcc,
	0x8d, 0x8d,
	0xc9, 0xc9,
	0xc9, 0xc9
};

// Tile g_tiles_182: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_182[2 * 4] = {
	0xcc, 0xc0,
	0x8d, 0xc8,
	0xc9, 0xc8,
	0xc9, 0xcc
};

// Tile g_tiles_183: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_183[2 * 4] = {
	0xcc, 0xcc,
	0xc4, 0xc4,
	0xc9, 0xc9,
	0xc9, 0xc9
};

// Tile g_tiles_184: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_184[2 * 4] = {
	0xcc, 0xcc,
	0xc4, 0xc4,
	0x9d, 0x4b,
	0xc9, 0xc9
};

// Tile g_tiles_185: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_185[2 * 4] = {
	0xdd, 0x6e,
	0xea, 0x95,
	0x6a, 0x85,
	0x9d, 0x4e
};

// Tile g_tiles_186: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_186[2 * 4] = {
	0xc0, 0xea,
	0xc0, 0x81,
	0xc0, 0xc0,
	0xc0, 0xd5
};

// Tile g_tiles_187: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_187[2 * 4] = {
	0xc0, 0xff,
	0xd5, 0xc0,
	0xd5, 0xea,
	0xc0, 0xff
};

// Tile g_tiles_188: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_188[2 * 4] = {
	0xff, 0xea,
	0xd5, 0xff,
	0x81, 0xab,
	0xea, 0x81
};

// Tile g_tiles_189: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_189[2 * 4] = {
	0xc0, 0xea,
	0xea, 0xab,
	0xc0, 0x42,
	0x42, 0xea
};

// Tile g_tiles_190: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_190[2 * 4] = {
	0xd5, 0xea,
	0xd5, 0xab,
	0xc0, 0x03,
	0x42, 0x81
};

// Tile g_tiles_191: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_191[2 * 4] = {
	0xea, 0x81,
	0x03, 0x81,
	0x81, 0x42,
	0xc0, 0xc0
};

// Tile g_tiles_192: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_192[2 * 4] = {
	0xc0, 0xea,
	0xc0, 0x57,
	0xd5, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_193: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_193[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xd5, 0xc0,
	0xab, 0xc0
};

// Tile g_tiles_194: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_194[2 * 4] = {
	0x85, 0xc3,
	0x85, 0xc3,
	0xc0, 0xcc,
	0xc0, 0xc3
};

// Tile g_tiles_195: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_195[2 * 4] = {
	0x92, 0x60,
	0x98, 0x60,
	0xc0, 0xc0,
	0x98, 0xc0
};

// Tile g_tiles_196: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_196[2 * 4] = {
	0xc0, 0xc3,
	0xc0, 0xc3,
	0xc0, 0xc3,
	0xc0, 0xc3
};

// Tile g_tiles_197: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_197[2 * 4] = {
	0xc8, 0xc0,
	0x98, 0xc0,
	0xc8, 0xc0,
	0x98, 0xc0
};

// Tile g_tiles_198: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_198[2 * 4] = {
	0xc0, 0xc1,
	0xc0, 0xc1,
	0xc0, 0xc1,
	0xc0, 0xc0
};

// Tile g_tiles_199: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_199[2 * 4] = {
	0xc8, 0xc0,
	0xc8, 0xc0,
	0xc8, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_200: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_200[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0x95,
	0xc0, 0x6e,
	0x95, 0x6b
};

// Tile g_tiles_201: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_201[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0x4a, 0xc0,
	0x8d, 0xc0
};

// Tile g_tiles_202: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_202[2 * 4] = {
	0x95, 0x87,
	0xc0, 0x6e,
	0xc0, 0x2f,
	0xc0, 0xc0
};

// Tile g_tiles_203: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_203[2 * 4] = {
	0x87, 0xc0,
	0x4a, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_204: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_204[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0x4b,
	0x85, 0xc6,
	0xc8, 0xc0
};

// Tile g_tiles_205: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_205[2 * 4] = {
	0xc0, 0xc0,
	0x0f, 0x87,
	0xc6, 0xc3,
	0xc0, 0xc0
};

// Tile g_tiles_206: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_206[2 * 4] = {
	0xc0, 0xc0,
	0xc3, 0xc0,
	0xc6, 0xc8,
	0xc0, 0xc0
};

// Tile g_tiles_207: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_207[2 * 4] = {
	0x4b, 0xc9,
	0x4b, 0x4b,
	0xc6, 0x4b,
	0xc6, 0xc3
};

// Tile g_tiles_208: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_208[2 * 4] = {
	0xc9, 0xc6,
	0xc9, 0xc3,
	0xc3, 0xc6,
	0xc9, 0xc6
};

// Tile g_tiles_209: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_209[2 * 4] = {
	0xc2, 0xc8,
	0xc6, 0x98,
	0xc6, 0xc8,
	0xc6, 0x98
};

// Tile g_tiles_210: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_210[2 * 4] = {
	0xc8, 0xc8,
	0x4b, 0x4b,
	0xc6, 0x4b,
	0xc6, 0xc1
};

// Tile g_tiles_211: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_211[2 * 4] = {
	0xc8, 0xc0,
	0xc3, 0xc4,
	0xc9, 0xc3,
	0xc1, 0xc3
};

// Tile g_tiles_212: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_212[2 * 4] = {
	0xc0, 0xc0,
	0xc8, 0x60,
	0xcc, 0x30,
	0xcc, 0x60
};

// Tile g_tiles_213: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_213[2 * 4] = {
	0x4b, 0xc3,
	0xc8, 0xc0,
	0xc1, 0xc6,
	0xc0, 0xc3
};

// Tile g_tiles_214: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_214[2 * 4] = {
	0xc6, 0xc6,
	0xc0, 0xc0,
	0xc3, 0xcc,
	0xcc, 0x98
};

// Tile g_tiles_215: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_215[2 * 4] = {
	0x98, 0x30,
	0xc0, 0xc0,
	0x98, 0x60,
	0x30, 0xc0
};

// Tile g_tiles_216: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_216[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0x4b, 0xc3,
	0xc6, 0xcc
};

// Tile g_tiles_217: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_217[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc3, 0xc3,
	0xcc, 0xc4
};

// Tile g_tiles_218: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_218[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc9, 0xcc,
	0x90, 0x90
};

// Tile g_tiles_219: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_219[2 * 4] = {
	0xc0, 0xc0,
	0xc4, 0xc8,
	0xc9, 0xc6,
	0xc9, 0xc3
};

// Tile g_tiles_220: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_220[2 * 4] = {
	0xc0, 0xc0,
	0xcc, 0xc4,
	0xc2, 0xc3,
	0xc1, 0xc2
};

// Tile g_tiles_221: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_221[2 * 4] = {
	0xc0, 0xc0,
	0xc8, 0x98,
	0xc0, 0x60,
	0xc8, 0x30
};

// Tile g_tiles_222: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_222[2 * 4] = {
	0xc9, 0xc2,
	0xc9, 0xc1,
	0xc8, 0xc3,
	0xc9, 0xc2
};

// Tile g_tiles_223: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_223[2 * 4] = {
	0xc3, 0xc4,
	0xc2, 0xcc,
	0xc4, 0xc4,
	0xc6, 0xc4
};

// Tile g_tiles_224: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_224[2 * 4] = {
	0x60, 0x60,
	0xc0, 0x30,
	0x60, 0x60,
	0xc0, 0x30
};

// Tile g_tiles_225: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_225[2 * 4] = {
	0xc9, 0xc1,
	0xc0, 0xc0,
	0x4b, 0xcc,
	0xc2, 0xc8
};

// Tile g_tiles_226: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_226[2 * 4] = {
	0xcc, 0x90,
	0xc0, 0xc0,
	0xcc, 0x90,
	0x60, 0x60
};

// Tile g_tiles_227: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_227[2 * 4] = {
	0x60, 0x60,
	0xc0, 0xc0,
	0x90, 0x90,
	0x60, 0x60
};

// Tile g_tiles_228: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_228[2 * 4] = {
	0xc0, 0xd5,
	0xc0, 0xaf,
	0xd5, 0x0f,
	0xaf, 0x5e
};

// Tile g_tiles_229: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_229[2 * 4] = {
	0xff, 0x3f,
	0x0f, 0x0f,
	0xfc, 0x3f,
	0xc0, 0xc0
};

// Tile g_tiles_230: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_230[2 * 4] = {
	0x6a, 0xc0,
	0x1f, 0xc0,
	0x4b, 0x6a,
	0x2f, 0x1f
};

// Tile g_tiles_231: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_231[2 * 4] = {
	0xaf, 0xe8,
	0xaf, 0xe8,
	0xaf, 0xe8,
	0x2f, 0x2e
};

// Tile g_tiles_232: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_232[2 * 4] = {
	0xd5, 0xc0,
	0xea, 0xc0,
	0xc0, 0xc0,
	0x1c, 0x1c
};

// Tile g_tiles_233: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_233[2 * 4] = {
	0x95, 0x5e,
	0x95, 0xdc,
	0xd5, 0x5e,
	0x7d, 0x5e
};

// Tile g_tiles_234: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_234[2 * 4] = {
	0x2f, 0x1f,
	0x95, 0x0f,
	0xc0, 0x2f,
	0xc0, 0x95
};

// Tile g_tiles_235: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_235[2 * 4] = {
	0x0c, 0x0c,
	0x3f, 0xff,
	0x4b, 0x8d,
	0xfc, 0xfc
};

// Tile g_tiles_236: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_236[2 * 4] = {
	0xeb, 0x5e,
	0x0f, 0xe8,
	0x5e, 0xc0,
	0xe8, 0xc0
};

// Tile g_tiles_237: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_237[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_238: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_238[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

// Tile g_tiles_239: 4x4 pixels, 2x4 bytes.
const u8 g_tiles_239[2 * 4] = {
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
};

