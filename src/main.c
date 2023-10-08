///////////////////////////// LICENSE NOTICE ///////////////////////////////////
//  This file is part of "Booty the Remake".
//  Copyright (C) 2023 @salvakantero
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
////////////////////////////////////////////////////////////////////////////////

// Booty the remake v1.0 (09/2023)

////////////////////////////////////////////////////////////////////////////////
//  MEMORY MAP
//
//	0xC000-0xFFFF	Primary video buffer
//	0x15D1-0xBFFF	Program & stack
//	0x1031-0x15D0	Uncompressed map
//	0x0200-0x1030	FX-music
//	0x0100-0x0199	Transparent mask table
//
////////////////////////////////////////////////////////////////////////////////

#include <cpctelera.h>

// gfx
#include "gfx/tiles.h"				// tiles to compose the map (4x4 px)
#include "gfx/font.h"				// letters and numbers (4x5 px)
#include "gfx/title1.h"				// title image #1 (56x40 px)
#include "gfx/title2.h"				// title image #2 (56x40 px)
#include "gfx/filigree.h"			// decorations (26x36 px)

// sprites
#include "sprites/player.h"			// 11 frames for the player (14x16 px)
#include "sprites/pirate.h"			// 4 frames for the pirate (14x16 px)
#include "sprites/pirate2.h"		// 4 frames for the 2nd pirate (14x16 px)
#include "sprites/explosion.h"		// 2 frames for the explosion effect (14x16 px)
#include "sprites/rat.h"			// 2 frames for the rat (14x16 px)
#include "sprites/parrot.h"			// 2 frames for the parrot (14x16 px)
#include "sprites/bomb.h"           // 2 frames for the active bomb (14x16 px)
#include "sprites/platform.h"		// 1 frame for the platform (16x4 px)
#include "sprites/magic.h"			// 2 frames for the magic effect (12x16 px)
#include "sprites/torch.h"			// 2 frames for the torch (6x8 px)

#include "sfx/sound.h"				// music and sound effects

// compressed game map. 40x36 tiles (160x144 px)
#include "map/mappk0.h"
#include "map/mappk1.h"
#include "map/mappk2.h"
#include "map/mappk3.h"
#include "map/mappk4.h"
#include "map/mappk5.h"
#include "map/mappk6.h"
#include "map/mappk7.h"
#include "map/mappk8.h"
#include "map/mappk9.h"
#include "map/mappk10.h"
#include "map/mappk11.h"
#include "map/mappk12.h"
#include "map/mappk13.h"
#include "map/mappk14.h"
#include "map/mappk15.h"
#include "map/mappk16.h"
#include "map/mappk17.h"
#include "map/mappk18.h"
#include "map/mappk19.h"










////////////////////////////////////////////////////////////////////////////////
//	DEFINITIONS & VARIABLES
////////////////////////////////////////////////////////////////////////////////

#define TRUE 1
#define FALSE 0

#define GLOBAL_MAX_X  79 	// X maximum value for the screen (bytes)
#define GLOBAL_MAX_Y  200	// Y maximun value for the screen (px)

#define FNT_W 2	// text width (bytes)
#define FNT_H 5 // text height (px)
#define SPR_W 7 // sprite width (bytes)
#define SPR_H 16 // sprite height (px)
#define PLF_W 8 // platform width (bytes)
#define PLF_H 4 // platform height (px)

// 6 different kinds of sprites
#define PLAYER		0
#define PIRATE	 	1
#define PIRATE2		2
#define PLATFORM	3
#define RAT			4
#define PARROT		5

// number of main tiles
#define TILE_BACKGROUND 	0
#define TILE_GROUND_INI		1
#define TILE_GROUND_END		2
#define TILE_DOOR_TOP		5
#define TILE_DOOR_BODY		6
#define TILE_DOOR_L_KNOB	7
#define TILE_DOOR_R_KNOB	8
#define TILE_STAIRS_INI		9
#define TILE_STAIRS_END		14
#define TILE_KEY_INI		19
#define TILE_NUMBERS_INI	24
#define TILE_OBJECTS_INI	48
#define TILE_FRONT_DOOR		183
#define TILE_TORCH			202

// maps
#define ORIG_MAP_Y 56	// the map starts at position 56 of the vertical coordinates
#define MAP_W 40		// game screen size in tiles (horizontal)
#define MAP_H 36		// game screen size in tiles (vertical)
#define UNPACKED_MAP_INI (u8*)(0x1031) // the music ends at 0x1030
#define UNPACKED_MAP_END (u8*)(0x15D0) // the map occupies 40x36 = 1440 = 0x5A0

#define BG_COLOR 1 // black (in-game)
#define ARRAY_SIZE 180 // size for the doors and keys arrays
#define ANIM_TIMER 2 // pause between frames for sprites
#define PL_ANIM_TIMER 3 // pause between frames for player (slower)

u8 currentMap; 		// current room number
u8 currentKey;		// current key number
u8 music;			// "TRUE" = plays the music during the game, "FALSE" = only effects
u8 ctMainLoop; 		// main loop iteration counter
u8 ct;				// generic counter
u8 demoMode;        // carousel of screens

u8 booty; 			// collected items (125 max.)
u8 playerXIni;      // position X when entering the map
u8 playerYIni;      // position Y when entering the map
u8 playerYFallIni;	// position Y when starts to fall

// keyboard/joystick control
cpct_keyID ctlUp;
cpct_keyID ctlDown;
cpct_keyID ctlLeft;
cpct_keyID ctlRight;
cpct_keyID ctlOpen;
cpct_keyID ctlMusic;
cpct_keyID ctlAbort;
cpct_keyID ctlPause;

// sprite frame and direction
typedef struct {
	// u8 dir;
	u8* spr;
} TFrm;

// structure to manage sprites (players and enemies)
typedef struct {
	u8 ident;  // sprite identifier (0:PLAYER 1-2:PIRATES 3:PLATFORM 4:RAT 5:PARROT)
	u8 x, y;   // current sprite coordinates
	u8 px, py; // previous sprite coordinates (to delete it)
	u8 status; // current status; stopped, climbing, etc...
	TFrm* frm; // animation secuence image
	u8 nFrm;   // animation frame number
	u8 lives;  // lives left
	u8 dir;    // sprite direction
	// non-player sprite properties
    u8 fast;   // X pos is always processed when fast is TRUE
    u8 step;   // for slow sprites, X pos is processed only when step is TRUE
	u8 min;    // XY minimun value
	u8 max;    // XY maximum value
} TSpr;

TSpr spr[5];	// 0) player
				// 1) enemy/platform #1
				// 2) enemy/platform #2
				// 3) enemy/platform #3
				// 4) enemy/platform #4

// animations
typedef struct {
	u8 x, y;	// position
	u8 timer;	// counter for the next frame
} TAnim;

TAnim magic; // magic effect when picking up object/key
TAnim torch[3]; // flame effect on torches (up to 3 per map)
TAnim bomb; // bomb with a burning fuse

enum { // sprite direction
	D_up = 0,
	D_down,
	D_left,
	D_right
} enum_dir;

enum { // sprite status
	S_stopped = 0,
	S_walking,
	S_climbing,
	S_falling
} enum_sta;

// animation secuences

// player
const TFrm frm_player[11] = {
    // left
	{g_player_00}, // stopped #1
	{g_player_01}, // stopped #2
	{g_player_02}, // moving, right foot
	{g_player_03}, // moving, left foot
    // right
    {g_player_04}, // stopped #1
	{g_player_05}, // stopped #2
    {g_player_06}, // moving, right foot
    {g_player_07}, // moving, left foot
    // backwards
	{g_player_08}, // falling
	{g_player_09}, // stairs, right foot
	{g_player_10} // stairs, left foot
};
TFrm* const animPlBreatheLeft[4] =  {&frm_player[0], &frm_player[0], &frm_player[1], &frm_player[1]};
TFrm* const animPlBreatheRight[4] =  {&frm_player[4], &frm_player[4], &frm_player[5], &frm_player[5]};
TFrm* const animPlWalkLeft[4] =  {&frm_player[0], &frm_player[2], &frm_player[0], &frm_player[3]};
TFrm* const animPlWalkRight[4] = {&frm_player[4], &frm_player[6], &frm_player[4], &frm_player[7]};
TFrm* const animPlClimb[4] = {&frm_player[9], &frm_player[10], &frm_player[9], &frm_player[10]};

// pirate #1
const TFrm frm_pirate[4] = {
    // left
    {g_pirate_0}, // moving, right foot
    {g_pirate_1}, // moving, left foot
    // right
    {g_pirate_2}, // moving, righ foot
    {g_pirate_3} // moving, left foot
};
TFrm* const animPirateLeft[2] = {&frm_pirate[0], &frm_pirate[1]};
TFrm* const animPirateRight[2] = {&frm_pirate[2], &frm_pirate[3]};

// pirate #2
const TFrm frm_pirate2[4] = {
    // left
    {g_pirate2_0}, // moving, right foot
    {g_pirate2_1}, // moving, left foot
    // right
    {g_pirate2_2}, // moving, righ foot
    {g_pirate2_3} // moving, left foot
};
TFrm* const animPirate2Left[2] = {&frm_pirate2[0], &frm_pirate2[1]};
TFrm* const animPirate2Right[2] = {&frm_pirate2[2], &frm_pirate2[3]};

// other sprites
const TFrm frm_rat[2] = {{g_rat_0}, {g_rat_1}};
const TFrm frm_parrot[2] = {{g_parrot_0}, {g_parrot_1}};
const TFrm frm_platform[1] = {{g_platform}};

TFrm* const animRat[2] = {&frm_rat[0], &frm_rat[1]};
TFrm* const animParrot[2] = {&frm_parrot[0], &frm_parrot[1]};

// X positions of the doors (in tile coordinates)
const u8 arrayDoorsX[ARRAY_SIZE] = {
	15, 31, 15, 31, 12, 31, 15, 31,  0,
	 4, 29, 11, 20, 20,  6, 28,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,
	12, 29, 12, 26, 12, 20,  0,  0,  0,
	 7, 15,  7, 15,  7, 15,  0,  0,  0,	// 5
	21, 31, 26, 15, 15, 35,  0,  0,  0,
	30, 31, 31,  0,  0,  0,  0,  0,  0,
	 7, 32,  7, 32,  7, 32,  0,  0,  0,
	19, 27, 33, 21, 27, 25, 33,  0,  0,
	25, 33,  9, 25, 33,  0,  0,  0,  0,	// 10
	 8, 31, 31, 31,  4, 31,  0,  0,  0,
	 6,  7, 33, 24, 19, 27,  0,  0,  0,
	25, 31, 35, 25, 33,  0,  0,  0,  0,
	34, 12,  9,  0,  0,  0,  0,  0,  0,
	15, 31, 15, 15, 26, 26,  0,  0,  0,	// 15
	18, 24, 33, 18, 24,  0,  0,  0,  0,
	34,  6, 12, 34, 12, 17, 34,  6, 11,
	 9, 33,  9, 33, 17,  9, 17,  0,  0,
	12, 33,  6, 17, 30, 30,  0,  0,  0};

// Y positions of the doors (in tile coordinates)
const u8 arrayDoorsY[ARRAY_SIZE] = {
	3,  3, 12, 12, 21, 21, 30, 30,  0,
	3,  3, 12, 12, 21, 30, 30,  0,  0,
	0,  0,  0,  0,  0,  0,  0,  0,  0,
	0,  0,  0,  0,  0,  0,  0,  0,  0,
	3,  3, 12, 12, 30, 30,  0,  0,  0,
	3,  3, 21, 21, 30, 30,  0,  0,  0,	// 5
	3,  3, 12, 21, 30, 30,  0,  0,  0,
	3, 21, 30,  0,  0,  0,  0,  0,  0,
	3,  3, 12, 12, 21, 30,  0,  0,  0,
	3,  3,  3, 21, 21, 30, 30,  0,  0,
   12, 12, 21, 21, 30,  0,  0,  0,  0,	// 10
	3,  3, 12, 21, 30, 30,  0,  0,  0,
	3, 12, 12, 21, 30, 30,  0,  0,  0,
   12, 12, 12, 21, 21,  0,  0,  0,  0,
	3, 21, 30,  0,  0,  0,  0,  0,  0,
	3,  3, 12, 21, 21, 30,  0,  0,  0, // 15
	3,  3,  3, 30, 30,  0,  0,  0,  0,
	3, 12, 12, 12, 21, 21, 21, 30, 30,
	3,  3, 12, 12, 21, 30, 30,  0,  0,
	3,  3, 12, 12, 21, 30,  0,  0,  0};

// X positions of the keys (in tile coordinates)
const u8 arrayKeysX[ARRAY_SIZE] = {
	35, 27,  0, 21, 12, 15, 21,  7,  0,
	 0, 38, 34, 12, 38,  9, 10,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,
	38, 14, 32,  0, 14,  9,  0,  0,  0,
	12, 34,  0,  9,  0, 12,  0,  0,  0,	// 5
	 0, 34,  0, 25, 38, 37,  0,  0,  0,
	31, 38, 25,  0,  0,  0,  0,  0,  0,
	38,  0, 38,  0, 38, 22,  0,  0,  0,
	 0, 27,  2, 38,  0, 21, 23,  0,  0,
	 0, 38, 22,  2, 29,  0,  0,  0,  0,	// 10
	38,  0,  6,  0, 33,  0,  0,  0,  0,
	 0, 32,  9, 24, 15, 34,  0,  0,  0,
	27, 32, 38,  0, 24,  0,  0,  0,  0,
	 0, 38,  2,  0,  0,  0,  0,  0,  0,
	17, 11, 35, 31, 21, 10,  0,  0,  0,	// 15
	31, 34,  0, 38,  0,  0,  0,  0,  0,
	14,  0,  8,  6,  8, 38,  7, 38, 38,
	 0, 32, 29, 38,  0, 38,  6,  0,  0,
	19, 37,  1,  0, 38, 38,  0,  0,  0};

// Y positions of the keys (in tile coordinates)
const u8 arrayKeysY[ARRAY_SIZE] = {
	23, 32, 23,  5, 32, 23, 14,  5,  0,
	32,  5, 32,  5, 14,  5, 32,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,
	14,  5, 32, 32, 14, 14,  0,  0,  0,
	23, 14, 32, 32,  5,  5,  0,  0,  0,	// 5
	23, 14, 32,  5, 23,  5,  0,  0,  0,
	14, 32, 23,  0,  0,  0,  0,  0,  0,
	 5, 23, 14,  5, 32, 23,  0,  0,  0,
	32, 32,  5,  5,  5,  5, 23,  0,  0,
	23, 32, 14,  5, 23,  0,  0,  0,  0,	// 10
	 5, 23, 14, 32, 14,  5,  0,  0,  0,
	14, 32,  5, 32, 23, 23,  0,  0,  0,
	23,  5, 23, 23, 32,  0,  0,  0,  0,
	23, 14, 14,  0,  0,  0,  0,  0,  0,
	 5,  5,  5, 32, 23, 23,  0,  0,  0,	// 15
	32, 23, 23,  5,  5,  0,  0,  0,  0,
	23, 32, 32, 23, 14, 23,  5, 14,  5,
	32, 23,  5,  5,  5, 14, 14,  0,  0,
	14, 23, 32,  5, 14,  5,  0,  0,  0};

// X positions of objects (in tile coordinates)
const u8 arrayObjectsX[ARRAY_SIZE+20] = {
	 0,  3, 34,  8,  9, 19, 33,  0,  0,  0,
	 0, 22, 31, 16, 29,  2, 23,  2, 12,  0,
	 0, 33,  4,  4, 33,  0,  0,  0,  0,  0,
	28, 28,  0,  0,  0,  0,  0,  0,  0,  0,
	 8, 37, 17, 28,  3, 15,  0,  0,  0,  0,
	 3,  9,  0,  9,  2, 11,  0,  0,  0,  0,	// 5
	 9, 33,  1, 17, 28,  2, 17,  6, 26, 37,
	25, 37, 16, 33, 34,  0,  0,  0,  0,  0,
	 3, 15, 34,  0, 23, 34,  3, 16, 14, 34,
	23, 29, 35, 27, 34, 29, 37,  0,  0,  0,
	 9, 36,  3, 31, 26, 35,  0,  0,  0,  0,	// 10
	 3, 34,  8,  9, 16, 37,  0,  0,  0,  0,
	 0,  3, 37, 26, 30, 21, 29,  0,  0,  0,
	28, 27, 37, 29,  0, 29,  0,  0,  0,  0,
	 4, 36, 37,  5,  0,  0,  0,  0,  0,  0,
	 8, 37,  0, 37, 18, 36,  7, 28,  0,  0,	// 15
	20, 35, 36,  0,  0,  0,  0,  0,  0,  0,
	 2,  8,  2,  0,  0,  0,  0,  0,  0,  0,
	 3, 24, 35, 11, 27,  3, 24,  0,  0,  0,
	16, 35,  0, 13, 21,  0, 32,  0,  0,  0};

// Y positions of objects (in tile coordinates)
const u8 arrayObjectsY[ARRAY_SIZE+20] = {
	 4, 13, 13, 22, 31, 31, 31,  0,  0,  0,
	 4,  4,  4, 13, 13, 22, 22, 31, 31,  0,
	 4,  4, 13, 22, 22,  0,  0,  0,  0,  0,
	22, 31,  0,  0,  0,  0,  0,  0,  0,  0,
	 4,  4, 13, 13, 31, 31,  0,  0,  0,  0,
	 4,  4, 22, 22, 31, 31,  0,  0,  0,  0,	// 5
	 4,  4, 13, 13, 13, 22, 22, 31, 31, 31,
	 4,  4, 13, 22, 31,  0,  0,  0,  0,  0,
	 4,  4,  4, 13, 13, 13, 22, 22, 31, 31,
	 4,  4,  4, 13, 22, 31, 31,  0,  0,  0,
	 4, 13, 22, 22, 31, 31,  0,  0,  0,  0,	// 10
	 4,  4, 13, 22, 31, 31,  0,  0,  0,  0,
	 4, 13, 13, 22, 22, 31, 31,  0,  0,  0,
	 4, 13, 13, 22, 31, 31,  0,  0,  0,  0,
	 4,  4, 22, 31,  0,  0,  0,  0,  0,  0,
	 4,  4, 13, 13, 22, 22, 31, 31,  0,  0,	// 15
	 4,  4, 22, 31,  0,  0,  0,  0,  0,  0,
	13, 22, 31,  0,  0,  0,  0,  0,  0,  0,
	 4,  4, 13, 22, 22, 31, 31,  0,  0,  0,
	 4,  4, 13, 13, 13, 22, 31,  0,  0,  0};

/* objects (by number)
    16-1 coin bag
    17-2 chest
    18-3 golden bell
	19-4 sabre
	20-5 vase
    21-6 pistol
    22-7 sextant
    23-8 spyglass
    24-9 log book
    25-10 treasure map
    26-11 candleholder */
const u8 arrayObjectsTN[ARRAY_SIZE+20] = {
	 3,  4,  1,  1,  6,  5,  2,  0,  0,  0,
	 1,  1,  5,  7,  1,  1,  1,  1,  1,  0,
	 2,  5,  8,  9,  1,  0,  0,  0,  0,  0,
	 2,  2,  0,  0,  0,  0,  0,  0,  0,  0,
	 8,  3,  7,  2,  5,  4,  0,  0,  0,  0,
	 2, 10, 11,  6,  8,  1,  0,  0,  0,  0,	// 5
	 4,  4,  4,  4,  4,  4,  4,  4,  4,  4,
	 2,  2,  7,  8, 10,  0,  0,  0,  0,  0,
	 2,  9,  6, 10,  2,  1, 11,  8,  2,  4,
	 2,  2,  2,  2,  2,  2,  2,  0,  0,  0,
	11,  8,  9,  2, 10,  6,  0,  0,  0,  0,	// 10
	 2,  2,  4,  7,  1,  5,  0,  0,  0,  0,
	10,  1,  1,  1,  5, 11,  4,  0,  0,  0,
	 9, 10,  7,  2,  2,  2,  0,  0,  0,  0,
	 2,  7,  1, 10,  0,  0,  0,  0,  0,  0,
	11, 11, 11, 11, 11, 11, 11, 11,  0,  0,	// 15
	11,  4,  5,  1,  0,  0,  0,  0,  0,  0,
	 6,  4, 10,  0,  0,  0,  0,  0,  0,  0,
	 2,  2,  2,  2,  2,  2,  2,  0,  0,  0,
	 3,  7,  5,  5,  5,  6, 10,  0,  0,  0};

// working copies of Y base arrays
// their values shall be set to zero in order to mark objects as used or collected
u8 arrayDoorsYCopy[ARRAY_SIZE];
u8 arrayKeysYCopy[ARRAY_SIZE];
u8 arrayObjectsYCopy[ARRAY_SIZE+20];

// transparency mask for sprites
cpctm_createTransparentMaskTable(g_maskTable, 0x100, M0, 0);










////////////////////////////////////////////////////////////////////////////////
//	PREVIOUS STATEMENTS
////////////////////////////////////////////////////////////////////////////////

void SetMapData();
void LoseLife();










////////////////////////////////////////////////////////////////////////////////
//	GENERIC FUNCTIONS
////////////////////////////////////////////////////////////////////////////////

// get the length of a string (used in DrawNumber())
u8 Strlen(const u8 *str) __z88dk_fastcall {
    const u8 *s;
    for (s=str; *s; ++s);
    return (s-str);
}

// converts an integer to ASCII (used in DrawNumber())
char* Itoa(u8 value, char* result) {
    u8 tmp_value;
    u8* ptr = result, *ptr1 = result, tmp_char;

    do {
        tmp_value = value;
        value /= 10;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value-value*10)];
    } while (value);
    *ptr-- = '\0';
    while(ptr1<ptr) {
        tmp_char = *ptr;
        *ptr--= *ptr1;
        *ptr1++ = tmp_char;
    }
    return result;
}

// generates a pause
void Pause(u16 value) __z88dk_fastcall {
    u16 i;
    for(i=0; i<value; i++) {
		__asm
			halt
		__endasm;
	}
}

// Arkos tracker music player
void PlayMusic() {
   __asm
      exx
      .db #0x08
      push af
      push bc
      push de
      push hl
      call _cpct_akp_musicPlay
      pop hl
      pop de
      pop bc
      pop af
      .db #0x08
      exx
   __endasm;
}

// every 6 interruptions, plays the music and reads the keyboard
void Interrupt() {
   static u8 nInt;

   if (++nInt == 5) {
      PlayMusic();
      cpct_scanKeyboard_if();
      nInt = 0;
   }
}










/////////////////////////////////////////////////////////////////////////////////
//	GRAPHICS, MAPS AND TILES MANAGEMENT FUNCTIONS
/////////////////////////////////////////////////////////////////////////////////

// fill the screen with the specified color
void ClearScreen() {
	cpct_memset(CPCT_VMEM_START, cpct_px2byteM0(BG_COLOR, BG_COLOR), 16384);
}

// draws a number as a string with leading zeroes
void DrawNumber(u8 num, u8 len, u8 x, u8 y) {
	u8 txt[6];
	u8 zeros = 0;
	u8 pos = 0;
	u8 nAux;

	Itoa(num, txt);
	if (len > Strlen(txt))
		zeros = len-Strlen(txt);
	//zeros
	for (u8 i=0; i<zeros; i++) {
		u8* zeroPtr = cpct_getScreenPtr(CPCT_VMEM_START, (i*FNT_W)+x, y);
		cpct_drawSprite(g_font[0], zeroPtr, FNT_W, FNT_H);
	}
	// number
	nAux = txt[pos];
	while (nAux != '\0') {
		u8* ptr = cpct_getScreenPtr(CPCT_VMEM_START, ((zeros+pos)*FNT_W)+x, y);
		cpct_drawSprite(g_font[nAux-48], ptr, FNT_W, FNT_H);
		nAux = txt[++pos];
	}
}

// draws a character string at XY coordinates
void DrawText(u8 txt[], u8 x, u8 y) {
	u8 pos = 0;
	u8 car = txt[pos];

 	while(car != '\0') { // "@" = space    ";" = -
		u8* ptr = cpct_getScreenPtr(CPCT_VMEM_START, (pos*FNT_W)+x, y);
		cpct_drawSprite(g_font[car-48], ptr, FNT_W, FNT_H);
		car = txt[++pos];
	}
}

////////////////////////////// Tiles /////////////////////////////////

// get the map tile number of a certain XY position on the current map.
// XY parameters in pixels; Must be converted to tile coordinates
u8* GetTile(u8 x, u8 y) {
    return UNPACKED_MAP_INI + ((y - ORIG_MAP_Y)>>2) * MAP_W + (x>>1);
}

// set the map tile number of a certain XY position on the current map.
// it may be necessary to use cpct_etm_drawTileBox2x4() to redraw the area.
// XY parameters in pixels; Must be converted to tile coordinates
void SetTile(u8 x, u8 y, u8 tileNumber) {
    u8* memPos = UNPACKED_MAP_INI + ((y-ORIG_MAP_Y)>>2) * MAP_W + (x>>1);
	*memPos = tileNumber;
}

// returns "TRUE" or 1 if the coordinates are placed on a ground tile
u8 OnTheGround() {
    // applies an offset according to the direction
    u8 x = spr[0].dir == D_right ? spr[0].x+2 : spr[0].x+4;
    u8 tile = *GetTile(x, spr[0].y+SPR_H+1);

	if (tile == TILE_GROUND_INI || tile == TILE_GROUND_END) {
        // adjust to the ground; &3 = %4
		while ((spr[0].y+1) & 3)
            spr[0].y--;

		return TRUE;
    }
	return FALSE;
}

// returns "TRUE" or 1 if the player coordinates are placed on a stairs tile
u8 OnStairs(u8 dir) __z88dk_fastcall {
	u8 tile;
    // applies an offset according to the direction
	u8 x = (spr[0].dir == D_right) ? spr[0].x+2: spr[0].x+4;
	u8 y = (dir == D_up) ? spr[0].y+SPR_H : spr[0].y+SPR_H+1;

	tile = *GetTile(x, y);
	if (tile >= TILE_STAIRS_INI && tile <= TILE_STAIRS_END)
        return TRUE;
    return FALSE;
}

// returns "TRUE" or 1 if the player coordinates are placed in front of a map-changing door
u8 FacingDoor() {
	if (*GetTile(spr[0].x+1, spr[0].y+10) == TILE_FRONT_DOOR)
        return TRUE;
    return FALSE;
}

// draws 4 floor/background tiles in a row
// (for the ground that appears and disappears)
// XY parameters in pixels
void DrawVariableGround(u8 x, u8 y, u8 tileNumber) {
	for(u8 i=0; i<8; i+=2)
		SetTile(x+i, y+ORIG_MAP_Y, tileNumber);
}

// the ground appears and disappears on certain screens at certain XY positions
void SetVariableGround() {
	if (currentMap == 4 || currentMap == 14 || currentMap == 19)
	{
		u8 x, y;
		if (currentMap == 4)		{ x = 14; y = 104; }
		else if (currentMap == 14)	{ x = 56; y = 32; }
		else 						{ x = 42; y = 104; } // map 19

		// ground activated every 85 loops; ctMainLoop = 0, 85, 170
        if (ctMainLoop % 85 == 0) {
            // 1 section of 4 tiles
			DrawVariableGround(x, y, TILE_GROUND_INI);
            // 2 more sections, the 3 separated from each other (map 4)
			if (currentMap == 4) {
				DrawVariableGround(x+16, y, TILE_GROUND_INI);
				DrawVariableGround(x+32, y, TILE_GROUND_INI);
			}
            // 1 more section next to the first one (map 19)
			else if (currentMap == 19)
				DrawVariableGround(x+8, y, TILE_GROUND_INI);
			// refresh map area
			cpct_etm_drawTileRow2x4(MAP_W,
				cpctm_screenPtr(CPCT_VMEM_START, 0, ORIG_MAP_Y+y),
                UNPACKED_MAP_INI+(MAP_W*(y>>2)));
		}
		// ground deactivated every 85 loops; ctMainLoop = 42, 128, 213
        if (ctMainLoop % 85 == 42) {
            // 1 hole of 4 tiles
			DrawVariableGround(x, y, TILE_BACKGROUND);
            // 2 more holes, the 3 separated from each other (map 4)
			if (currentMap == 4) {
				DrawVariableGround(x+16, y, TILE_BACKGROUND);
				DrawVariableGround(x+32, y, TILE_BACKGROUND);
			}
            // 1 more hole next to the first one (map 19)
			else if (currentMap == 19)
				DrawVariableGround(x+8, y, TILE_BACKGROUND);
			// refresh map area
			cpct_etm_drawTileRow2x4(MAP_W,
				cpctm_screenPtr(CPCT_VMEM_START, 0, ORIG_MAP_Y+y),
                UNPACKED_MAP_INI+(MAP_W*(y>>2)));
		}
	}
}

// we check if all the doors in the corridor are open
u8 FreeAisle(u8 y) __z88dk_fastcall {
    u8 pos = currentMap*9;
	// converting pixels to tile coordinates
    if (y == 71) y = 3;
	else if (y == 107) y = 12;
	else if (y == 143) y = 21;
	else y = 30;
    // searches the array of gates in the map
    // if all the values of the level are 0
	for(u8 i=0; i<9; i++)
		if (arrayDoorsYCopy[pos+i] == y)
			return FALSE;
	return TRUE;
}

// prepares the magic effect when picking up object/key
void DoMagic(u8 x, u8 y) {
	if (magic.timer == 0) { // if no magic effect in process
        magic.x = x;
		magic.y = y;
		magic.timer = 12; // will decrease to 0
	}
}

// draws the map corresponding to the current map number
// at a fixed position; x=0 y=ORIG_MAP_Y
void DrawMap() {
	cpct_etm_drawTilemap2x4(MAP_W, MAP_H,
		cpctm_screenPtr(CPCT_VMEM_START, 0, ORIG_MAP_Y), UNPACKED_MAP_INI);
}

// selects a destination map according to the gateway (see BootyMap.jpg)
void SetNextMap() {
	u8 x = spr[0].x;
	u8 y = spr[0].y;

	// floor Y values
	// 1st :  71
	// 2nd : 107
	// 3rd : 143
	// 4th : 179
	switch (currentMap) {
		case 0:
			if (y == 71) 			currentMap = 1; // door "A"
			else if (y == 143) 		currentMap = 12; // door "L"
			else 					currentMap = 4; // door "D"
			break;
		case 1:
			if (y == 71) 			currentMap = 0; // door "A"
			else if (y == 107) 		currentMap = 2; // door "B"
			else 					currentMap = 9; // door "2"
			break;
		case 2:
			if (y == 107 && x > 55)	currentMap = 1; // door "B"
			else if (y == 107) 		currentMap = 3; // door "C"
			else 					currentMap = 8; // door "H"
			break;
		case 3:
			if (y == 71 && x < 55)	currentMap = 9; // door "I"
			else if (y == 71)		currentMap = 10; // door "J"
			else 					currentMap = 2; // door "C"
			break;
		case 4:
			if (y == 71) 			currentMap = 19; // door "4"
			else if (y == 107) 		currentMap = 5; // door "E"
			else 					currentMap = 0; // door "D"
			break;
		case 5:
			if (y == 107 && x < 55)	currentMap = 4; // door "E"
			else if (y == 107)		currentMap = 6; // door "F"
			else 					currentMap = 7; // door "Y"
			break;
		case 6:
			if (y == 107 && x < 55) currentMap = 7; // door "G"
			else if (y == 107) 		currentMap = 5; // door "F"
			else 					currentMap = 11; // door "Z"
			break;
		case 7:
			if (y == 107 && x < 30) currentMap = 14; // door "O"
			else if (y == 107) 		currentMap = 6; // door "G"
			else 					currentMap = 5; // door "Y"
			break;
		case 8:
			if (y == 71) 			currentMap = 15; // door "V"
			else if (y == 143) 		currentMap = 18; // door "W"
			else 					currentMap = 2; // door "H"
			break;
		case 9:
			if (y == 107) 			currentMap = 19; // door "3"
			else 					currentMap = 1; // door "2"
			break;
		case 10:
			if (y == 71) 			currentMap = 3; // door "J"
			else if (y == 107) 		currentMap = 11; // door "K"
			else 					currentMap = 19; // door "1"
			break;
		case 11:
			if (y == 107) 			currentMap = 10; // door "K"
			else if (y == 143) 		currentMap = 6; // door "Z"
			else 					currentMap = 17; // door "T"
			break;
		case 12:
			if (y == 71) 			currentMap = 13; // door "M"
			else if (y == 107) 		currentMap = 16; // door "U"
			else 					currentMap = 0; // door "L"
			break;
		case 13:
			if (y == 71) 			currentMap = 12; // door "M"
			else 					currentMap = 14; // door "N"
			break;
		case 14:
			if (y == 107) 			currentMap = 7; // door "O"
			else if (y == 143) 		currentMap = 15; // door "P"
			else 					currentMap = 13; // door "N"
			break;
		case 15:
			if (y == 71) 			currentMap = 8; // door "V"
			else if (y == 143) 		currentMap = 14; // door "P"
			else 					currentMap = 16; // door "Q"
			break;
		case 16:
			if (y == 71) 			currentMap = 17; // door "R"
			else if (y == 107) 		currentMap = 12; // door "U"
			else 					currentMap = 15; // door "Q"
			break;
		case 17:
			if (y == 71) 					currentMap = 16; // door "R"
			else if (y == 179 && x < 55) 	currentMap = 18; // door "S"
			else 							currentMap = 11; // door "T"
			break;
		case 18:
			if (y == 107) 			currentMap = 13; // door "X"
			else if (y == 143)		currentMap = 8; // door "W"
			else 					currentMap = 17; // door "S"
			break;
		case 19:
			if (y == 71) 			currentMap = 4; // door "4"
			else if (y == 107) 		currentMap = 9; // door "3"
			else 					currentMap = 10; // door "1"
			break;
	}
}

// refresh data on scoreboard
void RefreshScoreboard() {
	u8 y = ORIG_MAP_Y-7;
	DrawNumber(spr[0].lives, 1, 14, y); // lives left
	DrawNumber(booty, 3, 32, y); // collected items
	DrawNumber(125-booty, 3, 41, y); // pending items
	DrawNumber(currentMap+1, 2, 74, y); // room number
	// key number
	if (currentKey == 255)
		DrawText(";", 58, y); // no key
	else
		DrawNumber(currentKey+1, 1, 58, y);
}

// obtains the position of the torches on the current map
void GetTorches() {
	u8 i;
	// resets the torch positions
	for(i=0;i<3;i++)
		torch[i].x = 0;
	// search for torches on the map
	i = 0;
	for(u8 y=ORIG_MAP_Y; y<GLOBAL_MAX_Y; y+=4)
		for(u8 x=0; x<GLOBAL_MAX_X; x+=2)
			if (*GetTile(x, y) == TILE_TORCH) {
				torch[i].x = x;
				torch[i++].y = y-4;
			}
}

// refreshes the screen with the current map data
void RefreshScreen() {
	SetMapData();
	DrawMap();
	RefreshScoreboard();
	GetTorches();
}


////////////////////////////// Doors ////////////////////////////////

// draws a numbered side door
void DrawDoor(u8 x, u8 y) {
	SetTile(x, y, TILE_DOOR_TOP);
	for (u8 i=4; i<=16; i+=4)
		SetTile(x, y+i, TILE_DOOR_BODY);
	SetTile(x-2, y+8, TILE_DOOR_L_KNOB);
	SetTile(x+2, y+8, TILE_DOOR_R_KNOB);
    // it is not necessary to refresh the map area
    // because it has not yet been printed
}

// deletes a numbered side door
void DeleteDoor(u8 x, u8 y, u8 pos) {
	for (u8 i=0; i<=16; i+=4)
		SetTile(x, y+i, TILE_BACKGROUND);
    SetTile(x-2, y+8, TILE_BACKGROUND);
    SetTile(x+2, y+8, TILE_BACKGROUND);
    // refresh map area
    cpct_etm_drawTileBox2x4(arrayDoorsX[pos]-1, arrayDoorsY[pos], 3, 5, MAP_W,
        cpctm_screenPtr(CPCT_VMEM_START, 0, ORIG_MAP_Y), UNPACKED_MAP_INI);
}

// obtains the door number according to its position
u8 GetDoorNumber(u8 x, u8 y) {
	u8 pos;
	// convert to tile coordinates
    x = x>>1; // >>1 = /2
    y = (y-ORIG_MAP_Y)>>2; // >>2 = /4
	// seeks position
	for(u8 i=0; i<9; i++) {
		pos = currentMap*9+i;
		if (arrayDoorsX[pos] == x && arrayDoorsY[pos] == y)
			return i;
	}
    // no door found at the requested coordinates
    // we use 254 instead of 255 in order not to confuse with "currentKey"
	return 254;
}

// draws the available doors by traversing the XY vectors
void SetDoors() {
	u8 pos;
	for(u8 i=0; i<9; i++) {
		pos = currentMap*9+i;
		if (arrayDoorsYCopy[pos] != 0) // closed door
            // <<1 = *2  <<2 = *4
            DrawDoor(arrayDoorsX[pos]<<1, (arrayDoorsY[pos]<<2) + ORIG_MAP_Y);
	}
}

// the player (or pirate) is in front of a door?
u8 CheckDoor(TSpr *pSpr) {
	u8 number, x, y;
    // applies an offset according to the direction
	x = (pSpr->dir == D_right) ? pSpr->x+5 : pSpr->x+1;
	y = pSpr->y;

	// it's a locked door?
	if (*GetTile(x, y) == TILE_DOOR_TOP) {
		// the pirates will simply change direction
        // (0:PLAYER 1-2:PIRATES 3:PLATFORM 4:RAT 5:PARROT)
		if (pSpr->ident > PLAYER) return TRUE;
		// we have the key?
		number = GetDoorNumber(x, y);
		if (number == currentKey) { // open the door
            u8 pos = currentMap*9+number;
			cpct_akp_SFXPlay (1, 15, 41, 0, 0, AY_CHANNEL_B); // open door FX
			cpct_setBorder(g_palette[9]); // change border (red)
			DeleteDoor(x, y, pos);
			arrayDoorsYCopy[pos] = 0; // marks the door as open
			currentKey = 255; // loses the key
			Pause(8); // allows to see the border effect
			cpct_setBorder(g_palette[BG_COLOR]); // change border (black)
			return FALSE; // not in front of a door	(we have opened it with the key)
		}
		else { // we don't have the right key; the door remains closed
			cpct_akp_SFXPlay (4, 15, 45, 0, 0, AY_CHANNEL_A); // fx bouncing against the door
			pSpr->x = (pSpr->dir == D_right) ? pSpr->x-1 : pSpr->x+1; // rebound
			return TRUE; // in front of a door (we do not have the key)
		}
	}
	return FALSE; // not in front of a door
}


////////////////////////////// Keys ////////////////////////////////

// draws a numbered key
void DrawKey(u8 number) __z88dk_fastcall {
	// coordinates from tiles to pixels
	u8 pos = currentMap*9+number;
    u8 x = arrayKeysX[pos]<<1; // <<1 = *2
    u8 y = (arrayKeysY[pos]<<2)+ORIG_MAP_Y; // <<2 = *4
	// key
	SetTile(x, y, TILE_KEY_INI);
	SetTile(x+2, y, TILE_KEY_INI+1);
	SetTile(x+2, y+4, TILE_KEY_INI+2);
	SetTile(x+2, y+8, TILE_KEY_INI+3);
	// number
	SetTile(x, y+4, TILE_NUMBERS_INI+number);
	SetTile(x, y+8, TILE_NUMBERS_INI+number+12);
	// refresh map area
	cpct_etm_drawTileBox2x4(arrayKeysX[pos], arrayKeysY[pos], 2, 3, MAP_W,
		cpctm_screenPtr(CPCT_VMEM_START, 0, ORIG_MAP_Y), UNPACKED_MAP_INI);
}

// deletes a numbered key
void DeleteKey(u8 x, u8 y) {
	// 2*3 tiles area
	for (u8 i=0; i<=8; i+=4)	{
		SetTile(x, y+i, TILE_BACKGROUND);
		SetTile(x+2, y+i, TILE_BACKGROUND);
	}
    // it is not necessary to refresh the map area
    // because it is already done by the player
}

// obtains the key number according to its position
u8 GetKeyNumber(u8 x, u8 y) {
	// coordinates from pixels to tiles
    x = x>>1;
    y = (y-ORIG_MAP_Y)>>2;
	// find the position in the arrays
	for(u8 i=0; i<9; i++) {
		u8 pos = currentMap*9+i;
		if (arrayKeysX[pos] == x && arrayKeysY[pos] == y)
			return i; // key found
	}
	return 255; // key not found in the coordinates
}

// draws the available keys by traversing the XY vectors
void SetKeys() {
	for(u8 i=0; i<9; i++)
		if (arrayKeysYCopy[currentMap*9+i] != 0) // key available
			DrawKey(i);
}

// the player is located on a key tile?
void CheckDoorKeys() {
	u8 pos = currentMap*9;
	u8 x = spr[0].dir == D_right ? spr[0].x+4 : spr[0].x;
	u8 y = spr[0].y+8;
	// it's a key?
	if (*GetTile(x, y) == TILE_KEY_INI) {
		cpct_akp_SFXPlay (3, 15, 41, 0, 0, AY_CHANNEL_A);  // get key FX
		if (currentKey != 255) { // we carry a key
			DrawKey(currentKey);
			// marks the key as available again
			arrayKeysYCopy[pos+currentKey] = arrayKeysY[pos+currentKey];
		}
		// collects the new key
		DeleteKey(x, y);
		currentKey = GetKeyNumber(x, y);
		arrayKeysYCopy[pos+currentKey] = 0; // marks the key as in use
	}
}


///////////////////////////// Objects /////////////////////////////

// draws an object according to its position in the array
void DrawObject(u8 number, u8 pos) {
	// coordinates from tiles to pixels
    u8 x = arrayObjectsX[pos]<<1;
    u8 y = (arrayObjectsY[pos]<<2)+ORIG_MAP_Y;
	// object (3*4 tiles)
	u8 tileNum = TILE_OBJECTS_INI+(12*(number-1));
	for (u8 i=0; i<=12; i+=4)
		for (u8 j=0; j<=4; j+=2)
			SetTile(x+j, y+i, tileNum++);
    // it is not necessary to refresh the map area
    // because it has not yet been printed
}

// deletes an object by its XY position
void DeleteObject(u8 x, u8 y) {
	// 3*4 tilemap area
	for (u8 i=0; i<=12; i+=4)
		for (u8 j=0; j<=4; j+=2)
			SetTile(x+j, y+i, TILE_BACKGROUND);
    // it is not necessary to refresh the map area
    // because it is already done by the player
}

// Is there an object at XY position?
u8 GetObjectPos(u8 x, u8 y) {
	// coordinates from pixels to tiles
    x = x>>1;
    y = (y-ORIG_MAP_Y)>>2;
	// find the position in the arrays
	for(u8 i=0; i<10; i++) {
		u8 pos = currentMap*10+i;
		if (arrayObjectsX[pos] == x && arrayObjectsYCopy[pos] == y)
			return pos; // object found
	}
	return 255; // object not found in the coordinates
}

// draws the available objects by traversing the XY vectors
void SetObjects() {
	for(u8 i=0; i<10; i++) {
		u8 pos = currentMap*10+i;
		if (arrayObjectsYCopy[pos] != 0) // not yet collected
			DrawObject(arrayObjectsTN[pos], pos);
	}
}

// the player is located on an object tile?
void CheckObjects() {
    u8 x = spr[0].dir == D_right ? spr[0].x+2 : spr[0].x;
	u8 y = spr[0].y+4;
	u8 pos = GetObjectPos(x, y);
	if (pos != 255) { // object found
		cpct_akp_SFXPlay (7, 15, 41, 0, 0, AY_CHANNEL_C); // get object FX
		arrayObjectsYCopy[pos] = 0; // marks the object as in use
		DeleteObject(x, y);
		DoMagic(x, y-4); // magic effect
		booty++; // increases the number of objects collected
	}
}










////////////////////////////////////////////////////////////////////////////////
//	KEYBOARD FUNCTIONS
////////////////////////////////////////////////////////////////////////////////

// returns the key pressed
cpct_keyID ReturnKeyPressed() {
    u8 i = 10, *keys = cpct_keyboardStatusBuffer + 9;
    u16 keypressed;
    // We wait until a key is pressed
    do {
        cpct_scanKeyboard();
    } while (!cpct_isAnyKeyPressed());
    // We detect which key has been pressed
    do {
        keypressed = *keys ^ 0xFF;
        if (keypressed)
            return (keypressed << 8) + (i - 1);
        keys--;
    } while(--i);
	return keypressed;
}

// wait for the full press of a key
// can be used to empty the keyboard buffer
void Wait4Key(cpct_keyID key) __z88dk_fastcall {
    do cpct_scanKeyboard_f();
    while(!cpct_isKeyPressed(key));
    do cpct_scanKeyboard_f();
    while(cpct_isKeyPressed(key));
}

// asks for a key and returns the key pressed
cpct_keyID RedefineKey(u8 *keyName) __z88dk_fastcall {
    cpct_keyID key;
    DrawText(keyName, 35, 105);
    key = ReturnKeyPressed();
    Wait4Key(key);
	cpct_akp_SFXPlay (3, 15, 41, 0, 0, AY_CHANNEL_B); // press key FX
    return key;
}










////////////////////////////////////////////////////////////////////////////////
//	FUNCTIONS FOR SPRITE MANAGEMENT
////////////////////////////////////////////////////////////////////////////////

// draws the sprite and its mask at the current XY coordinates
void DrawSprite(TSpr *pSpr) __z88dk_fastcall {
	u8 width = SPR_W;
	u8 height = SPR_H;
	// platforms are 16*4
	if (pSpr->ident == PLATFORM) {
        width = PLF_W;
        height = PLF_H;
    }
	cpct_drawSpriteMaskedAlignedTable(pSpr->frm->spr,
        cpct_getScreenPtr(CPCT_VMEM_START, pSpr->x, pSpr->y),
        width, height, g_maskTable);
}

// draws a portion of the map in the coordinates of the sprite (to delete it)
void DeleteSprite(TSpr *pSpr) __z88dk_fastcall {
	u8 width = 4;
	u8 height = 4 + (pSpr->py & 3 ? 1 : 0);
	// platforms are 16*4
	if (pSpr->ident == PLATFORM) {
		width += (pSpr->px & 1);
		height = 2;
	}
    cpct_etm_drawTileBox2x4(
        pSpr->px>>1, (pSpr->py-ORIG_MAP_Y)>>2, width, height, MAP_W,
        cpctm_screenPtr(CPCT_VMEM_START, 0, ORIG_MAP_Y), UNPACKED_MAP_INI);
}

// assign the frame corresponding to the animation sequence of the sprite
void SelectFrame(TSpr *pSpr) {
	// player sprite
	if (pSpr->ident == PLAYER) {
		switch(pSpr->status) {
			case S_stopped:
                pSpr->frm = (pSpr->dir == D_left) ?
					animPlBreatheLeft[pSpr->nFrm/PL_ANIM_TIMER] :
					animPlBreatheRight[pSpr->nFrm/PL_ANIM_TIMER];
                break;
			case S_walking:
                pSpr->frm = (pSpr->dir == D_left) ?
                    animPlWalkLeft[pSpr->nFrm/PL_ANIM_TIMER] :
                    animPlWalkRight[pSpr->nFrm/PL_ANIM_TIMER];
                break;
			case S_climbing:
                pSpr->frm = animPlClimb[pSpr->nFrm/PL_ANIM_TIMER];
                break;
			case S_falling:
                pSpr->frm = &frm_player[8];
        }
	}
	// enemy sprite
	else {
		switch (pSpr->ident) {
			case PIRATE:
                pSpr->frm = (pSpr->dir == D_left) ?
                    animPirateLeft[pSpr->nFrm/ANIM_TIMER] :
                    animPirateRight[pSpr->nFrm/ANIM_TIMER];
                break;
			case PIRATE2:
                // always slow. Changes the frame only when stationary
				if (!pSpr->step)
                	pSpr->frm = (pSpr->dir == D_left) ?
                    	animPirate2Left[pSpr->nFrm/ANIM_TIMER] :
                    	animPirate2Right[pSpr->nFrm/ANIM_TIMER];
                break;
			case RAT:
                pSpr->frm = animRat[pSpr->nFrm/ANIM_TIMER];
                break;
			case PARROT:
                // changes the frame when it's fast
                // or when it's slow and stationary
				if (pSpr->fast || !pSpr->step)
                	pSpr->frm = animParrot[pSpr->nFrm/ANIM_TIMER];
        }
	}
}

// draws an explosion frame at the XY coordinates of the player
void DrawExplosion(u8 frame) __z88dk_fastcall {
	cpct_drawSpriteMaskedAlignedTable(g_explosion[frame],
        cpct_getScreenPtr(CPCT_VMEM_START, spr[0].x, spr[0].y),
		SPR_W, SPR_H, g_maskTable);
}

// eliminate the player with an explosion
void ExplodePlayer() {
	// To visualize the crash, it shows explosions with pauses
	cpct_akp_SFXPlay (4, 15, 30, 0, 0, AY_CHANNEL_C); // explosion FX
	DrawExplosion(0); Pause(20);
	DrawExplosion(1); Pause(20); DeleteSprite(&spr[0]);
	DrawExplosion(0); Pause(20); DeleteSprite(&spr[0]);
}

// animates the magic effect
void DrawMagic() {
	if (magic.timer == 1) // last frame, delete image
		cpct_drawSolidBox(cpctm_screenPtr(CPCT_VMEM_START, magic.x, magic.y),
			cpct_px2byteM0(BG_COLOR, BG_COLOR), 6, SPR_H);
	else if (magic.timer > 8 || magic.timer <= 4) // 9-12, 2-4
		cpct_drawSprite(g_magic_0, // frame 1
			cpct_getScreenPtr(CPCT_VMEM_START, magic.x, magic.y), 6, SPR_H);
	else // 5-8
		cpct_drawSprite(g_magic_1, // frame 2
			cpct_getScreenPtr(CPCT_VMEM_START, magic.x, magic.y), 6, SPR_H);
	magic.timer--;
}

// animates the flame of the torches
void DrawTorch() {
    // up to 3 torches
	for(u8 i=0;i<3;i++) {
        // if there is a torch and the random number (up to 255) is < 80
		if (torch[i].x != 0 && cpct_getRandom_lcg_u8(0) < 80) {
			if (torch[i].timer++ & 1) // % 2
				cpct_drawSprite(g_torch_0, cpct_getScreenPtr( // frame 1
					CPCT_VMEM_START, torch[i].x, torch[i].y), 3, 8);
			else
				cpct_drawSprite(g_torch_1, cpct_getScreenPtr( // frame 2
					CPCT_VMEM_START, torch[i].x, torch[i].y), 3, 8);
		}
	}
}

// returns "TRUE" or 1 if the player is on a platform
u8 OnPlatform() {
    for (u8 i=1; i<5; i++) {
        if (spr[i].ident == PLATFORM) {
            // Check if player's horizontal position overlaps with platform
            if (spr[0].x+SPR_W > spr[i].x+1 && spr[0].x < spr[i].x+PLF_W-1) {
                // Check vertical overlap within a tolerance of 5px.
                if (spr[0].y+SPR_H >= spr[i].y-5 && spr[0].y+SPR_H <= spr[i].y+5) {
                    // Adjust player's position on the platform
                    spr[0].y = spr[i].y-SPR_H-(spr[i].dir == D_up ? 2 : 1);
                    // horizontal platform (0:D_up, 1:D_down, 2:D_left, 3:D_right)
                    // the player obtains position X on the platform
                    if (spr[i].dir > D_down && spr[0].status == S_stopped)
                        spr[0].x = spr[i].x+1;
					// vertical platform, redraw to avoid flickering
                    else if (spr[i].dir <= D_down)
			            DrawSprite(&spr[i]);

                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

// check if there has been a collision of the player with other sprites
void CheckCollisions(TSpr *pSpr) __z88dk_fastcall {
	// collision between sprites
	if (spr[0].x+SPR_W > pSpr->x+2 && spr[0].x+2 < pSpr->x+SPR_W)
		if (spr[0].y+SPR_H > pSpr->y+2 && spr[0].y+2 < pSpr->y+SPR_H) {
			// an enemy has touched the player
			DeleteSprite(pSpr);
			spr[0].lives--;
			LoseLife();
		}
}










////////////////////////////////////////////////////////////////////////////////
//	FUNCTIONS FOR PLAYER MANAGEMENT
////////////////////////////////////////////////////////////////////////////////

// abort, mute, pause keys
void SecondaryKeys() {
	// abort, leave the game
	if(cpct_isKeyPressed(ctlAbort)) {
		spr[0].lives = 0;
		LoseLife();
	}
	// mute music TRUE/FALSE
	else if(cpct_isKeyPressed(ctlMusic)) {
		Wait4Key(ctlMusic);
		if (music == TRUE) { // if the music is playing ...
			music = FALSE;
			cpct_akp_musicInit(FX);
		}
		else { // if there was no music playing ...
			music = TRUE;
			cpct_akp_musicInit(Ingame1);
		}
	}
	// pause
	else if(cpct_isKeyPressed(ctlPause)) {
		Wait4Key(ctlPause);
		cpct_akp_musicInit(FX);
		while (!cpct_isAnyKeyPressed());
		Wait4Key(ctlPause);
		if (music)
			cpct_akp_musicInit(Ingame1);
	}
}

// have the up or down keys been pressed?
u8 UpDownKeys() {
	if(cpct_isKeyPressed(ctlUp) && OnStairs(D_up)) {
		spr[0].status = S_climbing; // going to climb a ladder
		return TRUE;
	}
	else if(cpct_isKeyPressed(ctlDown) && OnStairs(D_down)) {
		spr[0].status = S_climbing; // going down a ladder
		return TRUE;
	}
	return FALSE; // key not pressed
}

// assign the frame corresponding to the player animation sequence (or reset)
void PlayerAnim() {
    if(++spr[0].nFrm == PL_ANIM_TIMER<<2) // <<2 = *2
		spr[0].nFrm = 0;
}

// moves the player to the left if possible
void MoveLeft() {
	if (spr[0].x > 0) {
		if (!CheckDoor(&spr[0])) { // not in front of a door?
			spr[0].x--;
			spr[0].dir = D_left;
            // take keys/objects if available in the new position
			CheckDoorKeys();
			CheckObjects();
		}
	}
    PlayerAnim();
}

// moves the player to the right if possible
void MoveRight() {
	if (spr[0].x + SPR_W < GLOBAL_MAX_X) {
		if (!CheckDoor(&spr[0])) { // not in front of a door?
			spr[0].x++;
			spr[0].dir = D_right;
            // take keys/objects if available in the new position
			CheckDoorKeys();
			CheckObjects();
		}
	}
    PlayerAnim();
}

// if it's not on the ground/stair/platform, it is also falling.
// also OnPlatform() updates the player position relative to the platform
u8 CheckFalls() {
    if (!OnTheGround() && !OnStairs(D_down) && !OnPlatform()) {
		spr[0].status = S_falling;
		playerYFallIni = spr[0].y; // to calculate deadly falls
        return TRUE;
	}
    return FALSE;
}

// prepare the movement to the left or right
void WalkIn(u8 dir) __z88dk_fastcall {
	spr[0].nFrm = 0;
	spr[0].status = S_walking;
	spr[0].dir = dir;
    PlayerAnim();
}

// stands still
void Stopped() {
	if(UpDownKeys());
	else if(cpct_isKeyPressed(ctlLeft)) WalkIn(D_left);
	else if(cpct_isKeyPressed(ctlRight)) WalkIn(D_right);
	// in front of a map-changing door
	else if(cpct_isKeyPressed(ctlOpen) && FacingDoor()) {
		u8 pos = currentMap*9+currentKey;
		if (currentKey != 255) { // we carry a key
            // marks the key as available again
			arrayKeysYCopy[pos] = arrayKeysY[pos];
			currentKey = 255;
		}
		SetNextMap();
		RefreshScreen();
		// memorises the player's entry position
		playerXIni = spr[0].x;
		playerYIni = spr[0].y;
	}
    ////////////////////////////////////////////////////////////////////////////
    // DEBUG
    //else if (cpct_isKeyPressed(ctlOpen)) {
    //    if (++currentMap == 20) currentMap = 0;
    //    RefreshScreen();
    //}
    ////////////////////////////////////////////////////////////////////////////

    // if it's not on the ground/stair/platform, it is also falling
	else if (CheckFalls());
	else {
		SecondaryKeys(); // abort, mute, pause ?
		PlayerAnim(); // player breathes
	}
}

// moves the player by pressing the movement keys when the status is walking
void Walking() {
	if (UpDownKeys());
	else if (cpct_isKeyPressed(ctlLeft)) MoveLeft();
	else if (cpct_isKeyPressed(ctlRight)) MoveRight();
	else spr[0].status = S_stopped;
    // if it's not on the ground/stair/platform, it is also falling
    CheckFalls();
}

// moves the player by pressing the movement keys when the status is climbing
void Climbing() {
	if(cpct_isKeyPressed(ctlUp)) {
		if(OnStairs(D_up)) {
			spr[0].y-=2;
			PlayerAnim();
		}
		else
			spr[0].status = S_stopped;
	}
	else if(cpct_isKeyPressed(ctlDown))	{
		if(OnStairs(D_down)) {
			spr[0].y+=2;
			PlayerAnim();
		}
		else
			spr[0].status = S_stopped;
	}
	else // abort, mute, pause ?
		SecondaryKeys();
}

// falling 3 pixels at a time
void Falling() {
	spr[0].y += 3;
    // take keys/objects if available in the new position
	CheckDoorKeys();
	CheckObjects();
    // if the player is on a ground/platform tile...
	if (OnTheGround() || OnStairs(D_down) || OnPlatform()) {
        spr[0].status = S_stopped;
		// more than 35 pixels is a deadly fall (1 storey)
		if (spr[0].y-playerYFallIni > 35) {
			spr[0].lives--;
			LoseLife();
		}
	}
	// comes out from under the map
	else if (spr[0].y+SPR_H >= GLOBAL_MAX_Y) {
		spr[0].lives--;
		LoseLife();
	}
}

// call the appropriate function based on the status of the main sprite
void RunStatus() {
	switch(spr[0].status) {
		case S_stopped:       	Stopped();			break;
		case S_walking:      	Walking(); 			break;
		case S_climbing:    	Climbing();			break;
		case S_falling:      	Falling();
	}
}










////////////////////////////////////////////////////////////////////////////////
//	FUNCTIONS FOR THE ENEMIES CONTROL
////////////////////////////////////////////////////////////////////////////////

// updates the XY coordinates of the sprites based on their movement type
void MoveSprite(TSpr *pSpr) {
	u8 inc; // platform speed slow:2px. fast:3px.
	switch(pSpr->dir) {
		case D_right:
		case D_left:
            if ((pSpr->fast) ||	// fast (always processed when fast is TRUE)
			    (pSpr->step))	// slow (processed only when step is TRUE)
            {
			    pSpr->x += (pSpr->dir == D_right) ? 1 : -1;
                // if the sprite reaches the lateral boundaries
                // or he's a pirate and knocks on a door
                // (0:PLAYER 1-2:PIRATES 3:PLATFORM 4:RAT 5:PARROT)
                if (pSpr->x >= pSpr->max || pSpr->x <= pSpr->min ||
                    (pSpr->ident <= PIRATE2 && CheckDoor(pSpr))) {
    				// (rat-parrot) is eliminated at the end of the course
    				if (pSpr->ident > PLATFORM) {
    					pSpr->lives = 0;
                        DeleteSprite(pSpr);
    				}
    				else // (pirate-platform) change direction
    					pSpr->dir = (pSpr->dir == D_right) ? D_left : D_right;
    			}
                // slow sprites will not move on next call
                pSpr->step = FALSE;
            }
            // slow sprites will now move on the next call
            else pSpr->step = TRUE;
			break;
		case D_up:
		case D_down:
			// always platform
			inc = (pSpr->fast) ? 3 : 2; // slow:2px. fast:3px.
			pSpr->y += (pSpr->dir == D_down) ? inc : -inc;
            // if the platform reaches the boundaries
			if (pSpr->y >= pSpr->max || pSpr->y <= pSpr->min)
                // change direction
				pSpr->dir = (pSpr->dir == D_down) ? D_up : D_down;
			break;
	}
}

// assign properties to enemy/platform sprites
void SetSpriteParams(u8 i, u8 ident, u8 dir, u8 x, u8 y, u8 min, u8 max, u8 fast) {
	// Y-coordinate adjustments for platforms
	if (ident == PLATFORM) {
		y+=SPR_H; // at ground level
		if (dir > D_down) y++; // left-right dir
        else { // up-down dir
            min+=SPR_H;
            max+=SPR_H;
        }
		spr[i].frm = &frm_platform[0]; // fixed image (no animation)
	}
    spr[i].ident = ident;
    spr[i].dir = dir;
    spr[i].min = min;
    spr[i].max = max;
    spr[i].x = spr[i].px = x;
    spr[i].y = spr[i].py = y;
    spr[i].status = S_walking;
    spr[i].fast = spr[i].step = fast;
	// rats and parrots start inactive
	spr[i].lives = (ident > PLATFORM) ? 0 : 1;
	// first image assignment
	SelectFrame(&spr[i]);
}

// sets the map values according to "currentMap".
// coordinate calculation: x=TILED(x)*2 y=y1,y2,y3,y4
void SetMapData() {
	u8 y1 = 71;		// 1st floor
	u8 y2 = 107;	// 2nd floor
	u8 y3 = 143;	// 3rd floor
	u8 y4 = 179;	// 4th floor

    if (!demoMode)
	   cpct_akp_SFXPlay (6, 10, 41, 0, 0, AY_CHANNEL_C); // event sound

   // sprite 4 initialised by default (may not be used on some maps)
   spr[4].ident = PIRATE;
   spr[4].lives = 0;

	switch(currentMap) {
		case 0: {
			//        	  SPR IDENTITY  DIR       X    Y  Min  Max  Fast
			SetSpriteParams(1, RAT,		D_left,  72,  y2,   0,  72, 1);
			SetSpriteParams(2, PIRATE, 	D_left,  72,  y3,   0,  72, 1);
			SetSpriteParams(3, PIRATE, 	D_right,  0,  y4,   0,  72, 1);
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk0_end); // unzip the map
			break;
		}
		case 1: {
			//        	  SPR IDENTITY  DIR       X    Y  Min  Max  Fast
			SetSpriteParams(1, RAT,		D_left,  72,  y1,   0,  72, 1);
			SetSpriteParams(2, PIRATE,	D_right,  0,  y2,   0,  72, 1);
			SetSpriteParams(3, PIRATE,	D_right,  0,  y3,   0,  72, 1);
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk1_end);
			break;
		}
		case 2: {
			//        	  SPR  IDENTITY		DIR       X    Y	Min  Max  Fast
			SetSpriteParams(1, PLATFORM,	D_right, 18,  y1,	 18,  54, 1);
			SetSpriteParams(2, PLATFORM,	D_left,  54,  y2,	 18,  54, 1);
			SetSpriteParams(3, PLATFORM,	D_left,  48,  y3,	 18,  48, 1);
			SetSpriteParams(4, PIRATE,		D_right, 35,  y4,     0,  72, 1);
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk2_end);
			break;
		}
		case 3: {
			//        	  SPR IDENTITY	DIR       X    Y	Min  Max  Fast
			SetSpriteParams(1, PARROT,	D_right,  0,  y2,     0,  72, 1);
			SetSpriteParams(2, PIRATE2, D_left,  72,  y3,	 48,  72, 0);
			SetSpriteParams(3, PIRATE, 	D_right,  0,  y4,	  0,  72, 1);
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk3_end);
			break;
		}
		case 4: {
			//        	  SPR IDENTITY	DIR       X    Y  Min  Max  Fast
			SetSpriteParams(1, PIRATE, 	D_right,  0,  y1,   0,  72, 1);
			SetSpriteParams(2, PIRATE2, D_left,  72,  y2,   0,  72, 0);
			SetSpriteParams(3, PARROT,	D_right,  0,  y4,   0,  72, 1);
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk4_end);
			break;
		}
		case 5: {
			//        	  SPR IDENTITY		DIR       X    Y  Min Max  Fast
			SetSpriteParams(1, PARROT,		D_right,  0,  y1,	0, 72, 0);
			SetSpriteParams(2, PLATFORM,	D_down,  48,  y1,  y1, y4, 1);
			SetSpriteParams(3, PLATFORM,	D_up,    56,  y4,  y2, y4, 0);
			SetSpriteParams(4, PIRATE2,		D_right, 64,  y4,  64, 72, 0);
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk5_end);
			break;
		}
		case 6: {
			//        	  SPR IDENTITY  DIR       X    Y  Min  Max  Fast
			SetSpriteParams(1, PIRATE2,	D_right,  0,  y1,   0,  72, 0);
			SetSpriteParams(2, PARROT,	D_right,  0,  y2,   0,  72, 1);
			SetSpriteParams(3, PIRATE,	D_left,  72,  y3,   0,  72, 1);
			SetSpriteParams(4, PIRATE2,	D_right,  0,  y4,   0,  72, 0);
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk6_end);
			break;
		}
		case 7: {
			//        	  SPR IDENTITY	DIR       X    Y  Min  Max  Fast
			SetSpriteParams(1, PARROT,	D_right,  0,  y2,   0,  72, 0);
			SetSpriteParams(2, PIRATE2,	D_right, 40,  y3,  40,  72, 0);
			SetSpriteParams(3, PIRATE,	D_right,  0,  y4,   0,  72, 1);
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk7_end);
			break;
		}
		case 8: {
			//        	  SPR IDENTITY		DIR       X    Y	Min	 Max  Fast
			SetSpriteParams(1, PLATFORM,	D_up, 	 20,  y4,	 y1,  y4, 1);
			SetSpriteParams(2, PIRATE2,		D_left,  44,  y2,	 28,  44, 0);
			SetSpriteParams(3, PLATFORM,	D_down,  52,  y1,	 y1,  y4, 1);
			SetSpriteParams(4, PARROT,		D_right,  0,  y4,	  0,  72, 1);
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk8_end);
			break;
		}
		case 9: {
			//        	  SPR IDENTITY		DIR       X    Y	Min	Max	Fast
			SetSpriteParams(1, PLATFORM,	D_down,  10,  y1, 	 y1, y4, 1);
			SetSpriteParams(2, PARROT,		D_right,  0,  y2,  	  0, 72, 0);
			SetSpriteParams(3, PLATFORM, 	D_down,  18,  y3, 	 y1, y4, 0);
			SetSpriteParams(4, PLATFORM,	D_up,  	 26,  y4, 	 y1, y4, 1);
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk9_end);
			break;
		}
		case 10: {
			//        	  SPR IDENTITY		DIR       X    Y   Min Max  Fast
			SetSpriteParams(1, PARROT,		D_right,  0,  y1, 	 0,	72,	0);
			SetSpriteParams(2, PIRATE2,		D_left,  72,  y3,  	42,	72,	0);
			SetSpriteParams(3, PLATFORM, 	D_down,  26,  y1,	y1,	y4,	1);
			SetSpriteParams(4, PLATFORM, 	D_down,  34,  y1,	y1, y4,	1);
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk10_end);
			break;
		}
		case 11: {
			//        	  SPR IDENTITY		DIR       X    Y   Min Max  Fast
			SetSpriteParams(1, PARROT,		D_right,  0,  y1, 	 0,	72,	0);
			SetSpriteParams(2, PIRATE2,		D_left,  72,  y2,	58,	72,	0);
			SetSpriteParams(3, PLATFORM, 	D_up,  	 24,  y4,	y1, y4,	1);
			SetSpriteParams(4, PLATFORM, 	D_up,  	 50,  y4,	y1, y4,	1);
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk11_end);
			break;
		}
		case 12: {
			//        	  SPR IDENTITY	DIR       X    Y  Min  Max  Fast
			SetSpriteParams(1, PARROT,	D_right,  0,  y1,   0,  72,	1);
			SetSpriteParams(2, PIRATE,	D_right,  0,  y2,   0,  72,	1);
			SetSpriteParams(3, PIRATE,	D_left,  72,  y3,   0,  72,	1);
			SetSpriteParams(4, PIRATE,	D_left,  72,  y4,   0,  72,	1);
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk12_end);
			break;
		}
		case 13: {
			//        	  SPR IDENTITY		DIR       X    Y   Min Max  Fast
			SetSpriteParams(1, PLATFORM,	D_left,  36,  y1,	24,	36,	1);
			SetSpriteParams(2, PLATFORM,	D_right, 24,  y2,  	24,	32,	1);
			SetSpriteParams(3, PLATFORM, 	D_up,  	  8,  y4,	y1, y4,	1);
			SetSpriteParams(4, PIRATE2,		D_right, 16,  y4,	16,	72,	0);
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk13_end);
			break;
		}
		case 14: {
			//        	  SPR IDENTITY		DIR       X    Y   Min Max  Fast
			SetSpriteParams(1, PIRATE2,		D_right,  0,  y1, 	 0,	26,	0);
			SetSpriteParams(2, PLATFORM, 	D_up,  	 34,  y3,	y1, y3,	1);
			SetSpriteParams(3, PLATFORM, 	D_up,  	 56,  y3,	y2, y3,	0);
			SetSpriteParams(4, PIRATE,		D_right,  0,  y4, 	 0,	72,	1);
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk14_end);
			break;
		}
		case 15: {
			//        	  SPR IDENTITY	DIR       X    Y  Min  Max  Fast
			SetSpriteParams(1, PIRATE,	D_left,  72,  y2,   0,  72,	1);
			SetSpriteParams(2, PIRATE,	D_left,  72,  y3,   0,  72,	1);
			SetSpriteParams(3, RAT,		D_left,  72,  y4,   0,  72,	1);
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk15_end);
			break;
		}
		case 16: {
			//        	  SPR IDENTITY		DIR       X    Y   Min Max  Fast
			SetSpriteParams(1, PLATFORM, 	D_down,  10,  y1,	y1, y4,	1);
			SetSpriteParams(2, PLATFORM, 	D_up,  	 24,  y4,	y1, y4,	1);
			SetSpriteParams(3, PLATFORM,	D_down,  54,  y1,	y1, y4,	1);
			SetSpriteParams(4, PIRATE2,		D_right, 40,  y4,	32,	48,	0);
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk16_end);
			break;
		}
		case 17: {
			//        	  SPR IDENTITY		DIR       X    Y	Min	Max	 Fast
			SetSpriteParams(1, PLATFORM, 	D_down,  40,  y1, 	 y1, y4, 1);
			SetSpriteParams(2, PLATFORM, 	D_down,  48,  y3,	 y1, y4, 0);
			SetSpriteParams(3, PIRATE,		D_right,  0,  y3,	  0, 32, 1);
			SetSpriteParams(4, PLATFORM,  	D_up,  	 56,  y4,	 y1, y4, 1);
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk17_end);
			break;
		}
		case 18: {
			//        	  SPR IDENTITY	DIR       X    Y  Min  Max  Fast
			SetSpriteParams(1, RAT,		D_left,  72,  y1,   0,  72,	1);
			SetSpriteParams(2, PIRATE,	D_left,  72,  y2,   0,  72,	1);
			SetSpriteParams(3, PIRATE,	D_right,  0,  y3,   0,  72,	1);
			SetSpriteParams(4, PIRATE,	D_left,  72,  y4,   0,  72,	1);
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk18_end);
			break;
		}
		case 19: {
			//        	  SPR IDENTITY	DIR       X    Y  Min  Max  Fast
			SetSpriteParams(1, PIRATE,	D_right,  0,  y2,   0,  72,	1);
			SetSpriteParams(2, PIRATE2,	D_right,  0,  y3,   0,  34,	0);
			SetSpriteParams(3, RAT,		D_left,  72,  y4,   0,  72,	1);
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk19_end);
			break;
		}
	}
	SetDoors();
	SetKeys();
	SetObjects();
}










////////////////////////////////////////////////////////////////////////////////
//	MAIN MENU
////////////////////////////////////////////////////////////////////////////////

// draws the title and some ornaments.
// the title position may vary in height
void DrawDecorations(u8 y) __z88dk_fastcall {
	// upper left
	cpct_drawSprite(g_filigree, cpctm_screenPtr(CPCT_VMEM_START, 0, 0),
        G_FILIGREE_W, G_FILIGREE_H);

	// upper right
	cpct_hflipSpriteM0(G_FILIGREE_W, G_FILIGREE_H, g_filigree);	// horiz. reflection
    cpct_drawSprite(g_filigree, cpctm_screenPtr(CPCT_VMEM_START, 80-G_FILIGREE_W, 0),
        G_FILIGREE_W, G_FILIGREE_H);

	//title
	cpct_drawSpriteMaskedAlignedTable(g_title1,
        cpctm_screenPtr(CPCT_VMEM_START, 13, y),
		G_TITLE1_W, G_TITLE1_H, g_maskTable);
	cpct_drawSpriteMaskedAlignedTable(g_title2,
        cpctm_screenPtr(CPCT_VMEM_START, 13+G_TITLE1_W, y),
		G_TITLE2_W, G_TITLE2_H, g_maskTable);

	// bottom right
	cpct_vflipSprite(G_FILIGREE_W, G_FILIGREE_H,
        cpctm_spriteBottomLeftPtr(g_filigree, 13, 36), g_filigree); // vertical reflection
	cpct_drawSprite(g_filigree,
        cpctm_screenPtr(CPCT_VMEM_START, 80-G_FILIGREE_W, 164),
        G_FILIGREE_W, G_FILIGREE_H);

	// bottom left
	cpct_hflipSpriteM0(G_FILIGREE_W, G_FILIGREE_H, g_filigree);	// horizontal reflection
	cpct_drawSprite(g_filigree,
        cpctm_screenPtr(CPCT_VMEM_START, 0, 164),
        G_FILIGREE_W, G_FILIGREE_H);

	// vertical reflex to restore the initial shape
	cpct_vflipSprite(G_FILIGREE_W, G_FILIGREE_H,
        cpctm_spriteBottomLeftPtr(g_filigree, 13, 36), g_filigree);
}

// initial menu; options, credits and key definitions
void StartMenu() {
	u8 frameIdx = 0; // index to animate the sprites
	cpct_setBorder(g_palette[3]); // change border (dark red)
	cpct_akp_musicInit(Menu); // initialize music. Main theme
	ClearScreen();

    // draws menu options and additional information
    DrawDecorations(15);
    // options
    DrawText("1@START@GAME", 22, 72);
    DrawText("2@REDEFINE@CONTROLS", 22, 82);
    // info
    DrawText("A@TRIBUTE@TO@THE@ORIGINAL@GAME", 10, 160);
    DrawText("BY@JOHN@F<CAIN@;@PAUL@JOHNSON", 11, 170);
    DrawText("PLAY@ON@RETRO@2023", 23, 190);

	ct = 0;
	while(1) {
		cpct_scanKeyboard_f();

   		if(cpct_isKeyPressed(Key_1)) { // start game
			cpct_setSeed_lcg_u8(ct); // set the random seed
            demoMode = FALSE;
        	break; // exits and continues in the main loop
    	}
		else if(cpct_isKeyPressed(Key_2)){ // redefine keys
			Wait4Key(Key_2);
			ctlUp = 	RedefineKey("@@UP@");
			ctlDown = 	RedefineKey("@DOWN");
			ctlLeft = 	RedefineKey("@LEFT");
			ctlRight = 	RedefineKey("RIGHT");
			ctlOpen = 	RedefineKey("@OPEN");
			ctlAbort = 	RedefineKey("ABORT");
			ctlMusic = 	RedefineKey("MUSIC");
			ctlPause =	RedefineKey("PAUSE");
        	// delete the text line
        	DrawText("@@@@@", 35, 105);
    	}
        // after 150 loops without pressing a key...
        else if(frameIdx == 150) { // tour/demo
            demoMode = TRUE;
            break;
        }

		// credits
		switch (ct) {
			case 0:		DrawText("PROGRAM@AND@GRAPHICS:@SALVAKANTERO", 6,130); break;
			case 51:	DrawText("@@@@@@@MUSIC@AND@FX:@BEYKER@@@@@@@", 6,130); break;
			case 102:	DrawText("@@@@@LOADING@SCREEN:@BRUNDIJ", 8,130); break;
            case 153:   DrawText("@@@@@BETATESTING:@BLACKMORES", 8,130); break;
            case 204:	DrawText("@EXECUTIVE@PRODUCER:@FELIPE@MONGE@", 6,130);
		}

        /////////////////////////////////////////////////////////
        cpct_waitVSYNC(); // wait for the vertical retrace signal
        /////////////////////////////////////////////////////////

        // sprites
        // deletes the sprite on the left
		cpct_drawSolidBox(cpctm_screenPtr(CPCT_VMEM_START,  10, 72),
			cpct_px2byteM0(BG_COLOR, BG_COLOR), SPR_W, SPR_H);
        // deletes the sprite on the right
		cpct_drawSolidBox(cpctm_screenPtr(CPCT_VMEM_START,  64, 72),
			cpct_px2byteM0(BG_COLOR, BG_COLOR), SPR_W, SPR_H);
		// draws the following frames of the animation
		if (frameIdx & 1) { // even index
			cpct_drawSpriteMaskedAlignedTable(g_pirate_2,
				cpctm_screenPtr(CPCT_VMEM_START, 10, 72), SPR_W, SPR_H, g_maskTable);
			cpct_drawSpriteMaskedAlignedTable(g_pirate2_0,
				cpctm_screenPtr(CPCT_VMEM_START, 64, 72), SPR_W, SPR_H, g_maskTable);
		} else { // odd index
			cpct_drawSpriteMaskedAlignedTable(g_pirate_3,
				cpctm_screenPtr(CPCT_VMEM_START, 10, 72), SPR_W, SPR_H, g_maskTable);
			cpct_drawSpriteMaskedAlignedTable(g_pirate2_1,
				cpctm_screenPtr(CPCT_VMEM_START, 64, 72), SPR_W, SPR_H, g_maskTable);
		}
		// every 3 increments of the counter increases the frame index
		if (ct++ % 3 == 0) frameIdx++;
		Pause(16); // avoids unwanted keystrokes and pause the animation
	}
	ClearScreen();
	cpct_setBorder(g_palette[BG_COLOR]); // change border (black)
	cpct_akp_musicInit(Ingame1); // in-game music
	// scoreboard
	DrawDecorations(3);
    DrawText("LIVES:@@@BOOTY:@@@;@@@@@KEY:@@@ROOM:", 2, ORIG_MAP_Y - 7);
}










////////////////////////////////////////////////////////////////////////////////
//	MAIN LOOP
////////////////////////////////////////////////////////////////////////////////

// assigns default values ​​that do not vary between games
void InitValues() {
	spr[0].ident = PLAYER;
	// default key mapping
	ctlUp = Key_Q;
	ctlDown = Key_A;
	ctlLeft = Key_O;
	ctlRight = Key_P;
	ctlOpen = Key_Space;
	ctlAbort = Key_X;
	ctlMusic = Key_M;
	ctlPause = Key_H;
}

// initialization of some variables
void InitGame() {
	StartMenu();
	music = TRUE;
	currentMap = 0;
	currentKey = 255; // no key
	booty = 0; // no treasure

	// player
    spr[0].lives = 9;
	spr[0].x = spr[0].px = playerXIni = 48;
	spr[0].y = spr[0].py = playerYIni = 71;
	spr[0].dir = D_left;
	spr[0].status = S_stopped;

	// reset keys and doors data
	for (u8 i=0; i<=ARRAY_SIZE; i++) {
		arrayDoorsYCopy[i] = arrayDoorsY[i];
		arrayKeysYCopy[i] = arrayKeysY[i];
	}
	// reset objects data
	for (u8 i=0; i<=ARRAY_SIZE+20; i++)
		arrayObjectsYCopy[i] = arrayObjectsY[i];

	RefreshScreen();
}

// the player loses a life
void LoseLife() {
	ExplodePlayer();
	// if there are lives left
	if (spr[0].lives > 0) {
		RefreshScreen();
        // recovers the initial position
        spr[0].x = spr[0].px = playerXIni;
        spr[0].y = spr[0].py = playerYIni;
		spr[0].status = S_stopped;
    }
	else { // prepare a new game
		cpct_akp_musicInit(Ingame2);
		RefreshScoreboard();
		// draws a GAME OVER in the center of the play area
		DrawText("@@@@@@@@@@@", 30, 105);
		DrawText("@GAME@OVER@", 30, 110);
		DrawText("@@@@@@@@@@@", 30, 115);
		Pause(250);
		// wait for a key press
		while (!cpct_isAnyKeyPressed());
		InitGame(); // launch the start menu
	}
}

// target completed (125 pieces of treasure)
void Win() {
	u8* sep = "@@@@@@@@@@@@@@@@@@@";
	cpct_akp_musicInit(Menu); // music, Main theme
	RefreshScoreboard();
	// draws a message in the center of the play area
	DrawText(sep, 21, 95); DrawText("@;CONGRATULATIONS;@", 21, 100);
	DrawText(sep, 21, 105);	DrawText("@@YOU@GOT@ALL@THE@@", 21, 110);
	DrawText(sep, 21, 115);	DrawText("@@TREASURE@PIECES@@", 21, 120);
	DrawText(sep, 21, 125);
	Pause(250);
	// wait for a key press
	while (!cpct_isAnyKeyPressed());
	InitGame(); // launch the start menu
}

// updates the data of the selected enemy/platform sprite
void RenderSpriteStep1(u8 i) __z88dk_fastcall {
	if (spr[i].lives == 1) { // active sprite
		MoveSprite(&spr[i]); // update the XY coordinates of the sprite
		if (spr[i].ident != PLATFORM) { // enemy sprites
			SelectFrame(&spr[i]); // select the animation frame...
            if(++spr[i].nFrm == ANIM_TIMER<<1) spr[i].nFrm = 0; // and apply it
			CheckCollisions(&spr[i]); // check if any collision has occurred
		}
	}
	// possibility to activate rat/parrot
    // (0:PLAYER 1-2:PIRATES 3:PLATFORM 4:RAT 5:PARROT)
	else if (spr[i].ident > PLATFORM) {
		if (FreeAisle(spr[i].y)) // if all corridor doors are open
			// random chance of activation (only 0 or 1 of 255)
			if (cpct_getRandom_lcg_u8(0) <= 1) {
				spr[i].lives = 1;
				// reset the starting position
                // RATS: always move from right to left
                // PARROTS: always move from left to right
				spr[i].x = (spr[i].ident == RAT) ?
					spr[i].max : spr[i].min;
			}
	}
}

// draw the selected enemy/platform sprite
void RenderSpriteStep2(u8 i) __z88dk_fastcall {
    if (spr[i].lives == 1) { // active sprite
        DeleteSprite(&spr[i]);
        DrawSprite(&spr[i]);
        spr[i].px = spr[i].x; // save the current X coordinate (for the next deletion)
        spr[i].py = spr[i].y; // save the current Y coordinate
    }
}

// initialization and main loop
void main() {
	cpct_disableFirmware(); // disable firmware control
	cpct_akp_SFXInit(FX); //initialize sound effects
	cpct_setInterruptHandler(Interrupt); // initialize the interrupt manager (keyboard and sound)
	cpct_setVideoMode(0); // activate mode 0; 160*200 16 colors
	cpct_setPalette(g_palette, 16); // assign palette
	cpct_etm_setTileset2x4(g_tileset); // keep in memory the tiles for the maps (4 * 4)
	InitValues(); // assigns default values ​​that do not vary between games
	InitGame(); // initialization of some variables

	while (1) { // main loop
        // check the pressed keys
		cpct_scanKeyboard_f();
        // shows or hides portions of soil
		SetVariableGround();

		// updates the enemy/platform sprites
        if (ctMainLoop & 1) {
            // sprites 1 and 2 whe ctMainLoop is even
            RenderSpriteStep1(1);
            RenderSpriteStep1(2);
        } else {
            // sprites 3 and 4 when ctMainLoop is odd
            RenderSpriteStep1(3);
            RenderSpriteStep1(4);
        }

        // update the player sprite
        if (!demoMode) {
            RunStatus(); // call the appropriate function according to the player status
            SelectFrame(&spr[0]); // we assign the next frame of the animation to the player
			if (booty == 125) Win(); // all treasures collected. End of game
        }

        /////////////////////////////////////////////////////////
		cpct_waitVSYNC(); // wait for the vertical retrace signal
		/////////////////////////////////////////////////////////

        // draws the enemy/platform sprites
        if (ctMainLoop & 1) {
            // sprites 1 and 2 whe ctMainLoop is even
            RenderSpriteStep2(1);
            RenderSpriteStep2(2);
        } else {
            // sprites 3 and 4 when ctMainLoop is odd
            RenderSpriteStep2(3);
            RenderSpriteStep2(4);
        }

        /////////////////////////////////////////////////////////
		cpct_waitVSYNC(); // wait for the vertical retrace signal
		/////////////////////////////////////////////////////////

        // animates the flame of the torches
		DrawTorch();

        // draws the player sprite
        if (!demoMode) {
    		DeleteSprite(&spr[0]);
            if (magic.timer > 0) DrawMagic(); // magic effect (behind the player)
    		DrawSprite(&spr[0]);
            spr[0].px = spr[0].x; // save the current X coordinate of the player
            spr[0].py = spr[0].y; // save the current Y coordinate of the player
        }
        else { // tour/demo
			Pause(5); // compensatory pause for not drawing the player
			// pressing a key returns to the main menu
			if (cpct_isAnyKeyPressed()) InitGame();
		}

		if (ctMainLoop % 10 == 0)
			RefreshScoreboard();

		if (++ctMainLoop == 255) {
            ctMainLoop = 0;
            if (demoMode) { // next map of the tour/demo
                if (++currentMap == 20) InitGame();
                RefreshScreen(); // draw the new map
            }
        }
	}
}
