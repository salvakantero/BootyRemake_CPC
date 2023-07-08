#include "font.h"
// Data created with Img2CPC - (c) Retroworks - 2007-2017
// Tile g_font_00: 4x5 pixels, 2x5 bytes.
const u8 g_font[44][2 * 5] = {
{
	0x87, 0xc2,
	0x4a, 0x4a,
	0x4a, 0x4a,
	0x4a, 0x4a,
	0x87, 0xc2
},
{
	0x85, 0xc0,
	0x0f, 0xc0,
	0x85, 0xc0,
	0x85, 0xc0,
	0x4b, 0x4a
},
{
	0x0f, 0xc2,
	0xc0, 0x4a,
	0x87, 0xc2,
	0x4a, 0xc0,
	0x0f, 0x4a
},
{
	0x0f, 0xc2,
	0xc0, 0x4a,
	0x85, 0xc2,
	0xc0, 0x4a,
	0x0f, 0xc2
},
{
	0x4a, 0x4a,
	0x4a, 0x4a,
	0x87, 0x4a,
	0xc0, 0x4a,
	0xc0, 0x4a
},
{
	0x0f, 0x4a,
	0x4a, 0xc0,
	0x87, 0xc2,
	0xc0, 0x4a,
	0x0f, 0xc2
},
{
	0x87, 0x4a,
	0x4a, 0xc0,
	0x0f, 0xc2,
	0x4a, 0x4a,
	0x87, 0xc2
},
{
	0x0f, 0xc2,
	0xc0, 0x4a,
	0xc1, 0xc0,
	0x85, 0xc0,
	0x85, 0xc0
},
{
	0x87, 0xc2,
	0x4a, 0x4a,
	0x87, 0xc2,
	0x4a, 0x4a,
	0x87, 0xc2
},
{
	0x87, 0xc2,
	0x4a, 0x4a,
	0x87, 0x4a,
	0xc0, 0x4a,
	0xc0, 0x4a
},
{
	0xc0, 0xc0,
	0xea, 0xc0,
	0xc0, 0xc0,
	0xea, 0xc0,
	0xc0, 0xc0
},
{
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xff, 0xea,
	0x03, 0x42,
	0xc0, 0xc0
},
{
	0x57, 0xc0,
	0xea, 0xc0,
	0xea, 0xc0,
	0xea, 0xc0,
	0x57, 0xc0
},
{
	0xd5, 0x42,
	0xc0, 0xea,
	0xc0, 0xea,
	0xc0, 0xea,
	0xd5, 0x42
},
{
	0xea, 0xea,
	0xea, 0xea,
	0xea, 0xea,
	0x42, 0x42,
	0xea, 0xea
},
{
	0x57, 0x42,
	0xea, 0xea,
	0xc0, 0xea,
	0x81, 0xc0,
	0xd5, 0xc0
},
{
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0
},
{
	0x57, 0x42,
	0xea, 0xea,
	0xea, 0xea,
	0xff, 0xea,
	0xea, 0xea
},
{
	0xff, 0x42,
	0xea, 0xea,
	0xff, 0x42,
	0xea, 0xea,
	0xff, 0x42
},
{
	0x57, 0xea,
	0xea, 0xc0,
	0xea, 0xc0,
	0xea, 0xc0,
	0x57, 0xea
},
{
	0xff, 0xc0,
	0xea, 0xea,
	0xea, 0xea,
	0xea, 0xea,
	0xff, 0xc0
},
{
	0x57, 0xea,
	0xea, 0xc0,
	0xff, 0xc0,
	0xea, 0xc0,
	0x57, 0xea
},
{
	0x57, 0xea,
	0xea, 0xc0,
	0xff, 0xc0,
	0xea, 0xc0,
	0xea, 0xc0
},
{
	0x57, 0x42,
	0xea, 0xea,
	0xea, 0xc0,
	0xab, 0xea,
	0x57, 0xea
},
{
	0xea, 0xea,
	0xea, 0xea,
	0xff, 0xea,
	0xea, 0xea,
	0xea, 0xea
},
{
	0xab, 0xea,
	0xd5, 0xc0,
	0xd5, 0xc0,
	0xd5, 0xc0,
	0xab, 0xea
},
{
	0xc0, 0xea,
	0xc0, 0xea,
	0xc0, 0xea,
	0xea, 0xea,
	0x57, 0x42
},
{
	0xea, 0x42,
	0xab, 0xea,
	0xff, 0x42,
	0xab, 0xea,
	0xea, 0xea
},
{
	0xea, 0xc0,
	0xea, 0xc0,
	0xea, 0xc0,
	0xea, 0xc0,
	0x57, 0xea
},
{
	0xab, 0xea,
	0xff, 0xea,
	0xab, 0xea,
	0xea, 0xea,
	0xea, 0xea
},
{
	0xea, 0x42,
	0xab, 0xea,
	0xff, 0xea,
	0xea, 0xea,
	0xea, 0xea
},
{
	0x57, 0x42,
	0xea, 0xea,
	0xea, 0xea,
	0xea, 0xea,
	0x57, 0x42
},
{
	0x57, 0x42,
	0xea, 0xea,
	0xff, 0x42,
	0xea, 0xc0,
	0xea, 0xc0
},
{
	0x57, 0x42,
	0xea, 0xea,
	0xea, 0xea,
	0xea, 0xea,
	0x57, 0x57
},
{
	0x57, 0x42,
	0xea, 0xea,
	0xab, 0xea,
	0xff, 0xc0,
	0xea, 0xea
},
{
	0x57, 0xea,
	0xea, 0xc0,
	0x57, 0x42,
	0xc0, 0xea,
	0xff, 0x42
},
{
	0xff, 0xea,
	0xd5, 0xc0,
	0xd5, 0xc0,
	0xd5, 0xc0,
	0xd5, 0xc0
},
{
	0xea, 0xea,
	0xea, 0xea,
	0xea, 0xea,
	0xea, 0xea,
	0xff, 0xea
},
{
	0xea, 0xea,
	0xea, 0xea,
	0xea, 0xea,
	0xea, 0xea,
	0x57, 0x42
},
{
	0xea, 0xea,
	0xea, 0xea,
	0xab, 0xea,
	0xff, 0xea,
	0xab, 0xea
},
{
	0xea, 0xea,
	0xab, 0xea,
	0x57, 0x42,
	0xab, 0xea,
	0xea, 0xea
},
{
	0xea, 0xea,
	0xea, 0xea,
	0x81, 0xc0,
	0xd5, 0xc0,
	0xd5, 0xc0
},
{
	0xff, 0x42,
	0xc0, 0xea,
	0xd5, 0xc0,
	0xea, 0xc0,
	0x57, 0xea
},
{
	0xc0, 0xc0,
	0xc0, 0xc0,
	0xc0, 0xc0,
	0x57, 0xc0,
	0xea, 0xc0
}};

