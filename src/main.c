
///////////////////////////// LICENSE NOTICE ///////////////////////////////////
//  This file is part of "Booty the Remake Amstrad Eterno Edition". 
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

// Booty the remake v1.0 (05/05/2023)

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
#include "gfx/filigree.h"			// decorations (30x36 px)

// sprites
#include "sprites/player.h"			// 6 frames for the player (14x16 px)
#include "sprites/pirate.h"			// 2 frames for the pirate (14x16 px)
#include "sprites/explosion.h"		// 2 frames for the explosion effect (14x16 px)
#include "sprites/rat.h"			// 2 frames for the rat (14x16 px)
#include "sprites/parrot.h"			// 2 frames for the parrot (14x16 px)
#include "sprites/platform.h"		// 2 frames for the platform (14x16 px)
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

#define FNT_W 2	// width of text characters (bytes)
#define FNT_H 5 // height of text characters (px)

#define SPR_W 7 // sprite width (bytes)
#define SPR_H 16 // sprite height (px)

#define BG_COLOR 1 // black

#define ARRAY_SIZE 180 // size for the doors and keys arrays

// 3 different kinds of sprites
#define PLAYER		0
#define PIRATE	 	1
#define RAT			2
#define PARROT		3
#define PLATFORM	4

// main tiles
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

// maps
#define ORIG_MAP_Y 56	// the map starts at position 56 of the vertical coordinates
#define MAP_W 40		// game screen size in tiles (horizontal)
#define MAP_H 36		// game screen size in tiles (vertical)
#define TOTAL_MAPS 20
#define UNPACKED_MAP_INI (u8*)(0x1031) // the music ends at 0x1030
#define UNPACKED_MAP_END (u8*)(0x15D0) // the program starts at 0x15D1

u8 currentMap; 		// current room number
u8 currentKey;		// current key number
u8 booty; 			// collected items (125 max.)
u8 music;			// "TRUE" = plays the music during the game, "FALSE" = only effects
u8 sprTurn;			// to avoid flickering sprites, the enemies logic takes turns for each cycle
u8 ctMainLoop; 		// main loop iteration counter
u8 ct;				// generic counter
u8 mustRedraw;		// "TRUE" = the player must be drawn

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
	u8 dir;
	u8* spr;
} TFrm;

// structure to manage sprites (players and enemies)
typedef struct {
	u8 ident;	// sprite identifier (0:PLAYER 1:PIRATE 2:RAT 3:PARROT)
	u8 x, y;	// current sprite coordinates
	u8 px, py;	// previous sprite coordinates
	u8 status;	// current status; stopped, climbing, etc...
	TFrm* frm;	// animation secuence image
	u8 nFrm;	// animation frame number
	u8 dir;		// sprite direction
	u8 lives;	// lives left
	// non-player sprite properties
	u8 min;	// XY minimun value  
	u8 max;	// XY maximum value
	u8 movType;	// movement type (see "enum_mov")
} TSpr;

TSpr spr[5];	// 0) player
				// 1) enemy/platform #1
				// 2) enemy/platform #2
				// 3) enemy/platform #3
				// 4) enemy/platform #4

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
	S_falling,
	S_landing
} enum_sta;

enum { // sprite movement type
	M_linear_X = 0,
	M_linear_Y
} enum_mov;

// animation secuences

#define ANIM_PAUSE 3 // pause between frames

const TFrm frm_player[6] = {  
	{D_right, g_player_0}, // stopped
	{D_right, g_player_1}, // moving, right foot
	{D_right, g_player_2}, // moving, left foot
	{D_right, g_player_3}, // falling
	{D_right, g_player_4}, // stairs, right foot
	{D_right, g_player_5}  // stairs, left foot
};

TFrm* const animWalk[4] = {&frm_player[0], &frm_player[1], &frm_player[0], &frm_player[2]};
TFrm* const animClimb[4] = {&frm_player[4], &frm_player[4], &frm_player[5], &frm_player[5]};

const TFrm frm_pirate[2] = {{0, g_pirate_0}, {0, g_pirate_1}};
const TFrm frm_rat[2] = {{0, g_rat_0}, {0, g_rat_1}};
const TFrm frm_parrot[2] = {{0, g_parrot_0}, {0, g_parrot_1}};
const TFrm frm_platform[2] = {{0, g_platform_0}, {0, g_platform_1}};

// animation sequences of sprites
TFrm* const animPirate[2] = {&frm_pirate[0], &frm_pirate[1]};
TFrm* const animRat[2] = {&frm_rat[0], &frm_rat[1]};
TFrm* const animParrot[2] = {&frm_parrot[0], &frm_parrot[1]};
TFrm* const animPlatform[2] = {&frm_platform[0], &frm_platform[1]};

// X positions of the doors (in tiles)
const u8 arrayDoorsX[ARRAY_SIZE] = {
	15, 31, 15, 31, 12, 31, 15, 31,  0,
	 5, 22,  7, 15, 15,  5, 20,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,
	 9, 20,  9, 18,  9, 15,  0,  0,  0,
	 5, 11,  5, 11,  5, 11,  0,  0,  0,	// 5
	15, 22, 18, 11, 11, 26,  0,  0,  0,
	22, 24, 24,  0,  0,  0,  0,  0,  0,
	 5, 24,  5, 24,  5, 24,  0,  0,  0,
	15, 20, 24, 16, 20, 18, 24,  0,  0,
	18, 24,  7, 18, 24,  0,  0,  0,  0,	// 10
	 5, 22, 22, 22,  3, 22,  0,  0,  0,
	 5,  7, 24, 16, 16, 22,  0,  0,  0,
	18, 22, 26, 18, 24,  0,  0,  0,  0,
	24, 11,  9,  0,  0,  0,  0,  0,  0,
	11, 22, 11, 11, 18, 18,  0,  0,  0,	// 15												 									 
	15, 20, 24, 15, 20,  0,  0,  0,  0,
	24,  5,  9, 24,  9, 13, 24,  5,  9,
	 7, 24,  7, 24, 13,  7, 13,  0,  0,
	 9, 24,  5, 13, 20, 20,  0,  0,  0};

// Y positions of the doors (in tiles)
const u8 arrayDoorsY[ARRAY_SIZE] = {
	3,  3, 12, 12, 21, 21, 30, 30,  0, 
	1,  1,  5,  5,  9, 13, 13,  0,  0,
	0,  0,  0,  0,  0,  0,  0,  0,  0,
	0,  0,  0,  0,  0,  0,  0,  0,  0,
	1,  1,  5,  5, 13, 13,  0,  0,  0,
	1,  1,  9,  9, 13, 13,  0,  0,  0,	// 5
	1,  1,  5,  9, 13, 13,  0,  0,  0,
	1,  9, 13,  0,  0,  0,  0,  0,  0,
	1,  1,  5,  5,  9, 13,  0,  0,  0,
	1,  1,  1,  9,  9, 13, 13,  0,  0,
	5,  5,  9,  9, 13,  0,  0,  0,  0,	// 10
	1,  1,  5,  9, 13, 13,  0,  0,  0,
	1,  5,  5,  9, 13, 13,  0,  0,  0,
	5,  5,  5,  9,  9,  0,  0,  0,  0,
	1,  9, 13,  0,  0,  0,  0,  0,  0,
	1,  1,  5,  9,  9, 13,  0,  0,  0, // 15												 									 
	1,  1,  1, 13, 13,  0,  0,  0,  0,
	1,  5,  5,  5,  9,  9,  9, 13, 13,
	1,  1,  5,  5,  9, 13, 13,  0,  0,
	1,  1,  5,  5,  9, 13,  0,  0,  0};
							
// X positions of the keys (in tiles)
const u8 arrayKeysX[ARRAY_SIZE] = {
	35, 27,  0, 21,  0, 15, 21,  7,  0,
	 0, 28, 26, 10, 28,  8,  8,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,
	28, 10, 24,  0, 10,  6,  0,  0,  0,
	 8, 24,  0,  6,  0,  8,  0,  0,  0,	// 5
	 0, 26,  0, 18, 28, 26,  0,  0,  0,
	24, 28, 20,  0,  0,  0,  0,  0,  0,
	28,  0, 28,  0, 28, 16,  0,  0,  0,
	 0, 20,  2, 28,  0, 16, 18,  0,  0,
	 0, 28, 16,  2, 22,  0,  0,  0,  0,	// 10
	28,  0,  4,  0, 24,  0,  0,  0,  0,
	 0, 26,  6, 20, 12, 28,  0,  0,  0,
	20, 24, 28,  0, 16,  0,  0,  0,  0,
	 2, 28,  2,  0,  0,  0,  0,  0,  0,												 									 
	12,  6, 26, 24, 16,  8,  0,  0,  0,	// 15
	24, 24,  0, 28,  0,  0,  0,  0,  0,
	10,  0,  6,  4,  6, 28,  4, 28, 28,
	 0, 24, 20, 28,  0, 28,  4,  0,  0,
	14, 26,  2,  0, 28, 28,  0,  0,  0};

// Y positions of the keys (in tiles)
const u8 arrayKeysY[ARRAY_SIZE] = {
	23, 32, 23,  5, 32, 23, 14,  5,  0, 
	14,  2, 14,  2,  6,  2, 14,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,
	 6,  2, 14, 14,  6,  6,  0,  0,  0,
	10,  6, 14, 14,  2,  2,  0,  0,  0,	// 5
	10,  6, 14,  2, 10,  2,  0,  0,  0,
	 6, 14, 10,  0,  0,  0,  0,  0,  0,
	 2, 10,  6,  2, 14, 10,  0,  0,  0,
	14, 14,  2,  2,  2,  2, 10,  0,  0,
	10, 14,  6,  2, 10,  0,  0,  0,  0,	// 10
	 2, 10,  6, 14,  6,  2,  0,  0,  0,
	 6, 14,  2, 14, 10, 10,  0,  0,  0,
	10,  2, 10, 10, 14,  0,  0,  0,  0,
	10,  6,  6,  0,  0,  0,  0,  0,  0,												 									 
	 2,  2,  2, 14, 10, 10,  0,  0,  0,	// 15
	14, 10, 10,  2,  2,  0,  0,  0,  0,
	10, 14, 14, 10,  6, 10,  2,  6,  2,
	14, 10,  2,  2,  2,  6,  6,  0,  0,
	 6, 10, 14,  2,  6,  2,  0,  0,  0};

// X positions of objects (in tiles)
const u8 arrayObjectsX[ARRAY_SIZE+20] = {
	 0,  3, 34,  8, 11, 19, 33,  0,  0,  0,
	 1,  8, 13,  6, 12,  1,  8,  1,  5,  0,
	 0, 13,  1,  1, 13,  0,  0,  0,  0,  0,
	11,  9,  0,  0,  0,  0,  0,  0,  0,  0,
	 3, 13,  6, 10,  1,  5,  0,  0,  0,  0,
	 1,  3,  0,  3,  1,  4,  0,  0,  0,  0,	// 5
	 4, 12,  1,  6, 12,  1,  6,  3, 10, 14,
	10, 13,  5, 13, 13,  0,  0,  0,  0,  0,
	 1,  6, 13,  0,  9, 13,  1,  6,  5, 13,
	 9, 11, 13, 11, 13, 14, 11,  0,  0,  0,
	 3, 13,  1, 12,  9, 13,  0,  0,  0,  0,	// 10
	 1, 13,  3,  3,  6, 12,  0,  0,  0,  0,
	 0,  1, 14, 10, 12,  9, 12,  0,  0,  0,
	11, 10, 14, 11,  0, 11,  0,  0,  0,  0,
	 1, 13, 14,  2,  0,  0,  0,  0,  0,  0,
	 2, 14,  0, 14,  7, 12,  3, 10,  0,  0,	// 15
	 8, 13, 13,  0,  0,  0,  0,  0,  0,  0,
	 1,  3,  1,  0,  0,  0,  0,  0,  0,  0,
	 1,  9, 13,  4, 10,  1,  9,  0,  0,  0,
	 6, 13,  0,  5,  8,  0, 11,  0,  0,  0};

// Y positions of objects
const u8 arrayObjectsY[ARRAY_SIZE+20] = {
	 4, 13, 13, 22, 31, 31, 31,  0,  0,  0,
	 1,  1,  1,  3,  3,  5,  5,  7,  7,  0,
	 1,  1,  3,  5,  5,  0,  0,  0,  0,  0,
	 5,  7,  0,  0,  0,  0,  0,  0,  0,  0,
	 1,  1,  3,  3,  7,  7,  0,  0,  0,  0,
	 1,  1,  5,  5,  7,  7,  0,  0,  0,  0,	// 5
	 1,  1,  3,  3,  3,  5,  5,  7,  7,  7,
	 1,  1,  3,  5,  7,  0,  0,  0,  0,  0,
	 1,  1,  1,  3,  3,  3,  5,  5,  7,  7,
	 1,  1,  1,  3,  5,  7,  7,  0,  0,  0,
	 1,  3,  5,  5,  7,  7,  0,  0,  0,  0,	// 10
	 1,  1,  3,  5,  7,  7,  0,  0,  0,  0,
	 1,  3,  3,  5,  5,  7,  7,  0,  0,  0,
	 1,  3,  3,  5,  7,  7,  0,  0,  0,  0,
	 1,  1,  5,  7,  0,  0,  0,  0,  0,  0,
	 1,  1,  3,  3,  5,  5,  7,  7,  0,  0,	// 15
	 1,  1,  5,  7,  0,  0,  0,  0,  0,  0,
	 3,  5,  7,  0,  0,  0,  0,  0,  0,  0,
	 1,  1,  3,  5,  5,  7,  7,  0,  0,  0,
	 1,  1,  3,  3,  3,  5,  7,  0,  0,  0};

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
    26-11 candleholder
*/					
const u8 arrayObjectsTN[ARRAY_SIZE+20] = {
	 3,  4,  1,  1,  6,  5,  2,  0,  0,  0,
	16, 16, 20, 22, 16, 16, 16, 16, 16,  0,
	17, 20, 23, 24, 16,  0,  0,  0,  0,  0,
	17, 17,  0,  0,  0,  0,  0,  0,  0,  0,
	23, 18, 22, 17, 20, 19,  0,  0,  0,  0,
	17, 25, 26, 21, 23, 16,  0,  0,  0,  0,	// 5
	19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
	17, 17, 22, 23, 25,  0,  0,  0,  0,  0,
	17, 24, 21, 25, 17, 16, 26, 23, 17, 19,
	17, 17, 17, 17, 17, 17, 17,  0,  0,  0,
	26, 23, 24, 17, 25, 21,  0,  0,  0,  0,	// 10
	17, 17, 19, 22, 16, 20,  0,  0,  0,  0,
	25, 16, 16, 16, 20, 26, 19,  0,  0,  0,
	24, 25, 22, 17, 17, 17,  0,  0,  0,  0,
	17, 22, 16, 25,  0,  0,  0,  0,  0,  0,
	26, 26, 26, 26, 26, 26, 26, 26,  0,  0,	// 15
	26, 19, 20, 16,  0,  0,  0,  0,  0,  0,
	21, 19, 25,  0,  0,  0,  0,  0,  0,  0,
	17, 17, 17, 17, 17, 17, 17,  0,  0,  0,
	18, 22, 20, 20, 20, 21, 25,  0,  0,  0};	 

// working copies of base arrays
// their values shall be set to zero in order to mark objects as used or collected
u8 arrayDoorsYCopy[ARRAY_SIZE];
u8 arrayKeysYCopy[ARRAY_SIZE];
u8 arrayObjectsYCopy[ARRAY_SIZE+20];

// transparency mask
cpctm_createTransparentMaskTable(g_maskTable, 0x100, M0, 0);










////////////////////////////////////////////////////////////////////////////////
//	PREVIOUS STATEMENTS
////////////////////////////////////////////////////////////////////////////////

void SetMapData();
void LoseLife();










////////////////////////////////////////////////////////////////////////////////
//	GENERIC FUNCTIONS
////////////////////////////////////////////////////////////////////////////////

// get the length of a string
u8 Strlen(const u8 *str) __z88dk_fastcall {
    const u8 *s;
    for (s = str; *s; ++s);
    return (s - str);
}


// converts an integer to ASCII (Lukás Chmela / GPLv3)
char* Itoa(u8 value, char* result) {    
    u8 tmp_value;
    u8* ptr = result, *ptr1 = result, tmp_char;
    
    do {
        tmp_value = value;
        value /= 10;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * 10)];
    } while (value);   
    *ptr-- = '\0';
    while(ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr--= *ptr1;
        *ptr1++ = tmp_char;
    }
    return result;
}

// generates a pause
void Pause(u16 value) __z88dk_fastcall {
    u16 i;
    for(i = 0; i < value; i++) {
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


// every 5 interruptions, plays the music and reads the keyboard
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

// cleans the screen with the specified color
void ClearScreen() {
	cpct_memset(CPCT_VMEM_START, cpct_px2byteM0(BG_COLOR, BG_COLOR), 16384);
}


// prints a number as a string with leading zeroes
void PrintNumber(u8 num, u8 len, u8 x, u8 y) {
	u8 txt[6];
	u8 zeros = 0;
	u8 pos = 0;
	u8 nAux;

	Itoa(num, txt);
	if (len > Strlen(txt))
		zeros = len - Strlen(txt);

	for (u8 i = 0; i < zeros; i++) { //zeros
		u8* zeroPtr = cpct_getScreenPtr(CPCT_VMEM_START, (i * FNT_W) + x, y);
		cpct_drawSprite(g_font[0], zeroPtr, FNT_W, FNT_H);
	}

	nAux = txt[pos];
	while (nAux != '\0') {
		u8* ptr = cpct_getScreenPtr(CPCT_VMEM_START, ((zeros + pos) * FNT_W) + x, y);
		cpct_drawSprite(g_font[nAux - 48], ptr, FNT_W, FNT_H);
		nAux = txt[++pos];
	}
}


// prints a character string at XY coordinates
void PrintText(u8 txt[], u8 x, u8 y) {
	u8 pos = 0;
	u8 car = txt[pos];

 	while(car != '\0') { // "@" = space    ";" = -
		u8* ptr = cpct_getScreenPtr(CPCT_VMEM_START, (pos * FNT_W) + x, y);
		cpct_drawSprite(g_font[car - 48], ptr, FNT_W, FNT_H);
		car = txt[++pos];
	}
}


// print the map corresponding to the current map number 
// at a fixed position; x=0 y=ORIG_MAP_Y
void PrintMap() {	
	cpct_etm_drawTilemap2x4(MAP_W, MAP_H, 
		cpctm_screenPtr(CPCT_VMEM_START, 0, ORIG_MAP_Y), UNPACKED_MAP_INI);
}


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
	u8 y = ORIG_MAP_Y - 6;
	PrintNumber(spr[0].lives, 1, 14, y); // lives left 
	PrintNumber(booty, 3, 32, y); // collected items
	PrintNumber(125-booty, 3, 41, y); // pending items
	PrintNumber(currentMap+1, 2, 74, y); // room number
	// key number
	if (currentKey == 255)
		PrintText(";", 58, y); // no key
	else
		PrintNumber(currentKey+1, 1, 58, y);
}


// ***** Tiles *****

// get the map tile number of a certain XY position of the current map
u8* GetTile(u8 x, u8 y) {	
	return UNPACKED_MAP_INI + (y-ORIG_MAP_Y)/4 * MAP_W + x/2;	
}


// set the map tile number of a certain XY position on the current map
void SetTile(u8 x, u8 y, u8 tileNumber) {
	u8* memPos = UNPACKED_MAP_INI + (y-ORIG_MAP_Y)/4 * MAP_W + x/2;
	*memPos = tileNumber;
}


// returns "TRUE" or "1" if the coordinates are placed on a ground tile
u8 OnTheGround() {
	u8 tile = *GetTile(spr[0].x + 4, spr[0].y + SPR_H + 1);
	if (tile == TILE_GROUND_INI || tile == TILE_GROUND_END)
		return TRUE;
	return FALSE;
}


// returns "TRUE" or "1" if the player coordinates are placed on a stairs tile
u8 OnStairs(u8 dir) __z88dk_fastcall {
	u8 tile;
	u8 py = spr[0].y + SPR_H;
	tile = *GetTile(spr[0].x + 4, dir == D_up ? py : py+1);
	if (tile >= TILE_STAIRS_INI && tile <= TILE_STAIRS_END)
        return TRUE;
    return FALSE;
}


// returns "TRUE" or "1" if the player coordinates are placed in front of an unnumbered door
u8 FacingDoor() {
	u8 tile = *GetTile(spr[0].x+1, spr[0].y+10);
	if (tile == TILE_FRONT_DOOR)
        return TRUE;
    return FALSE;
}


// platforms appearing and disappearing on certain screens
void UnstableGround(void)
{
	u8 x, y;
	if (currentMap == 4 || currentMap == 13 || currentMap == 14 || currentMap == 19) 
	{
		if (currentMap == 19) 		{ x = 8;  y = 6; }
		else if (currentMap == 14)	{ x = 10; y = 2; }
		else if (currentMap == 4)	{ x = 2;  y = 6; }
		else 						{ x = 2;  y = 2; }

		if (currentMap != 13) {
			if (ctMainLoop == 40 || ctMainLoop == 120 || ctMainLoop == 210) {
				SetTile(x, y, TILE_GROUND_INI);
				SetTile(x+2, y, TILE_GROUND_INI);
				if (currentMap == 4) {
					SetTile(x+6, y, TILE_GROUND_INI);
					SetTile(x+8, y, TILE_GROUND_INI);
					SetTile(x+12, y, TILE_GROUND_INI);
					SetTile(x+14, y, TILE_GROUND_INI);
				}
			}
			else if (ctMainLoop == 70 || ctMainLoop == 150 || ctMainLoop == 240) {
				SetTile(x, y, TILE_BACKGROUND);
				SetTile(x+2, y, TILE_BACKGROUND);
				if (currentMap == 4) {
					SetTile(x+6, y, TILE_BACKGROUND);
					SetTile(x+8, y, TILE_BACKGROUND);
					SetTile(x+12, y, TILE_BACKGROUND);
					SetTile(x+14, y, TILE_BACKGROUND);
				}
			}
		}
		else {
			if (ctMainLoop == 128) {
				SetTile(x, y, TILE_BACKGROUND);
				SetTile(x, y+8, TILE_GROUND_INI);				
			}
			else if (ctMainLoop == 254) {
				SetTile(x, y, TILE_GROUND_INI);
				SetTile(x, y+8, TILE_BACKGROUND);
			}
		}
	}
}


// ***** Doors *****

void DrawDoor(u8 x, u8 y) {
	SetTile(x, y, TILE_DOOR_TOP);
	for (u8 i = 4; i <= 16; i += 4)
		SetTile(x, y+i, TILE_DOOR_BODY);
	SetTile(x-2, y+8, TILE_DOOR_L_KNOB);
	SetTile(x+2, y+8, TILE_DOOR_R_KNOB);
}


void DeleteDoor(u8 x, u8 y) {
	// door body
	for (u8 i = 0; i <= 16; i += 4)
		SetTile(x, y+i, TILE_BACKGROUND);
 	// knobs
 	SetTile(x-2, y+8, TILE_BACKGROUND);
 	SetTile(x+2, y+8, TILE_BACKGROUND);	
}


// obtains the door number according to its position
u8 GetDoorNumber(u8 x, u8 y) {
	u8 pos;
	// convert to tiles
	x = x/2;
	y = ((y-ORIG_MAP_Y)/4);
	// seeks position
	for(u8 i = 0; i < 9; i++) {
		pos = currentMap * 9 + i;
		if (arrayDoorsX[pos] == x && arrayDoorsY[pos] == y) 
			return i;
	}
	return 254;
}


// draws the available doors by traversing the XY vectors
void SetDoors(void) {
	u8 pos;
	for(u8 i = 0; i < 9; i++) {
		pos = currentMap * 9 + i;
		if (arrayDoorsYCopy[pos] != 0) 
			DrawDoor(arrayDoorsX[pos]*2, arrayDoorsY[pos]*4 + ORIG_MAP_Y);
	}
}


// the player is in front of a door?
u8 CheckDoor(TSpr *pSpr) __z88dk_fastcall {
	u8 number, x, y;
	
	x = (pSpr->dir == D_right) ? pSpr->x+5 : pSpr->x+1;
	y = pSpr->y;

	// it's a locked door?
	if (*GetTile(x, y) == TILE_DOOR_TOP) {	
		// the pirates will simply change direction
		if (pSpr->ident == PIRATE)
			return TRUE;
		// we have the key?
		number = GetDoorNumber(x, y);
		if (number == currentKey) {
			cpct_akp_SFXPlay (1, 15, 41, 0, 0, AY_CHANNEL_B); // open door FX
			DeleteDoor(x, y);			
			arrayDoorsYCopy[currentMap * 9 + number] = 0; // marks the door as open
			currentKey = 255; // without key
			return FALSE; // not in front of a door	(we have opened it with the key)
		}
		else {
			cpct_akp_SFXPlay (4, 15, 41, 0, 0, AY_CHANNEL_B); // bouncing against the door
			pSpr->x = (pSpr->dir == D_right) ? pSpr->x-2 : pSpr->x+2; // rebound
			return TRUE; // in front of a door (we do not have the key)
		}
	}
	return FALSE; // not in front of a door
}


// ***** Keys *****

void DrawKey(u8 number) {
	// coordinates from tiles to pixels
	u8 pos = currentMap * 9 + number;
	u8 px = arrayKeysX[pos] * 2;
	u8 py = (arrayKeysY[pos] * 4) + ORIG_MAP_Y;	
	// key
	SetTile(px, py, TILE_KEY_INI);
	SetTile(px+2, py, TILE_KEY_INI+1);
	SetTile(px+2, py+4, TILE_KEY_INI+2);
	SetTile(px+2, py+8, TILE_KEY_INI+3);
	// number
	SetTile(px, py+4, TILE_NUMBERS_INI + number);
	SetTile(px, py+8, TILE_NUMBERS_INI + number + 12);
	// refresh map area
	cpct_etm_drawTileBox2x4(arrayKeysX[pos], arrayKeysY[pos], 2, 3, MAP_W, 
	cpctm_screenPtr(CPCT_VMEM_START, 0, ORIG_MAP_Y), UNPACKED_MAP_INI);
}


void DeleteKey(u8 x, u8 y) {
	// 2*3 tiles area
	for (u8 i = 0; i <= 8; i += 4)	{
		SetTile(x, y+i, TILE_BACKGROUND);
		SetTile(x+2, y+i, TILE_BACKGROUND);
	}
}


// obtains the key number according to its position
u8 GetKeyNumber(u8 x, u8 y) {
	u8 pos;
	// convert to tiles
	x = x/2;
	y = (y-ORIG_MAP_Y)/4;
	// seeks position
	for(u8 i = 0; i < 9; i++) {
		pos = currentMap * 9 + i;
		if (arrayKeysX[pos] == x && arrayKeysY[pos] == y) 
			return i;
	}
	return 255;
}


// draws the available keys by traversing the XY vectors
void SetKeys(void) {
	for(u8 i = 0; i < 9; i++)
		if (arrayKeysYCopy[currentMap * 9 + i] != 0)
			DrawKey(i);
}


// the player is located on a key tile?
void CheckKeys(void) {
	u8 pos = currentMap * 9;
	u8 x = spr[0].dir == D_right ? spr[0].x+4 : spr[0].x;
	u8 y = spr[0].y+8;
	// it's a key?
	if (*GetTile(x, y) == TILE_KEY_INI) {	
		cpct_akp_SFXPlay (3, 15, 41, 0, 0, AY_CHANNEL_B);  // get key FX	
		if (currentKey != 255) { // restores the previous key
			DrawKey(currentKey);
			arrayKeysYCopy[pos + currentKey] = 
				arrayKeysY[pos + currentKey]; // marks the key as available
		}
		// collects the current key		
		DeleteKey(x, y);
		currentKey = GetKeyNumber(x, y);
		arrayKeysYCopy[pos + currentKey] = 0; // marks the key as in use
	}
}


// ***** Objects *****

void DrawObject(u8 number, u8 pos) {
	// coordinates from tiles to pixels
	u8 px = arrayObjectsX[pos] * 2;
	u8 py = (arrayObjectsY[pos] * 4) + ORIG_MAP_Y;
	// object (3*4 tiles)
	u8 tileNum = TILE_OBJECTS_INI + (12*(number-1));
	for (u8 i=0; i<=12; i+=4)
		for (u8 j=0; j<=4; j+=2)
			SetTile(px+j, py+i, tileNum++);
}


void DeleteObject(u8 x, u8 y) {
	// 3*4 tiles area
	for (u8 i=0; i<=12; i+=4)
		for (u8 j=0; j<=4; j+=2)
			SetTile(x+j, y+i, TILE_BACKGROUND);
}


// obtains the object position in the array
u8 GetObjectPos(u8 x, u8 y) {
	// convert to tiles
	x = x/2;
	y = (y-ORIG_MAP_Y)/4;
	// seeks position
	for(u8 i = 0; i < 10; i++) {
		u8 pos = currentMap * 10 + i;			
		if (arrayObjectsX[pos] == x && arrayObjectsY[pos] == y) 
			return i;
	}
	return 255;
}


// draws the available objects by traversing the XY vectors
void SetObjects(void) {	
	for(u8 i = 0; i < 10; i++) {
		u8 pos = currentMap * 10 + i;
		if (arrayObjectsYCopy[pos] != 0)
			DrawObject(arrayObjectsTN[pos], pos);
	}
}


// the player is located on an object tile?
void CheckObjects(void) {
	u8 x = spr[0].x;
	u8 y = spr[0].y+4;
	u8 pos = GetObjectPos(x, y);
	u8 tile = *GetTile(x, y);
	if (tile == TILE_OBJECTS_INI + (arrayObjectsTN[pos]-1)*12) {
		cpct_akp_SFXPlay (8, 15, 41, 0, 0, AY_CHANNEL_B); // get object FX
		arrayObjectsYCopy[pos] = 0;
		DeleteObject(x, y);
		booty++;
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
    do { cpct_scanKeyboard(); } while ( ! cpct_isAnyKeyPressed() );
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
    PrintText(keyName, 35, 105);  
    key = ReturnKeyPressed();
    Wait4Key(key);
	cpct_akp_SFXPlay (3, 15, 41, 0, 0, AY_CHANNEL_B); // press key FX    
    return key;
}











////////////////////////////////////////////////////////////////////////////////
//	FUNCTIONS FOR SPRITE MANAGEMENT
////////////////////////////////////////////////////////////////////////////////

// draws the sprite and its mask at the current XY coordinates
void PrintSprite(TSpr *pSpr) __z88dk_fastcall {
	cpct_drawSpriteMaskedAlignedTable(pSpr->frm->spr, 
									  cpct_getScreenPtr(CPCT_VMEM_START, pSpr->x, pSpr->y), 
									  SPR_W, SPR_H, g_maskTable);
}


// draws a portion of the map in the coordinates of the sprite (to delete it)
void DeleteSprite(TSpr *pSpr) __z88dk_fastcall {		
	u8 offset = 0;
	// When the player is on a ladder,
	// it's necessary to enlarge in Y the deleted area.
	if (pSpr->status == S_climbing) offset = 1;

	cpct_etm_drawTileBox2x4(pSpr->px / 2, (pSpr->py - ORIG_MAP_Y - offset) / 4, 
							4 + (pSpr->px & 1), 4 + offset + (pSpr->py & 3 ? 1 : 0),	
							MAP_W, cpctm_screenPtr(CPCT_VMEM_START, 0, ORIG_MAP_Y), UNPACKED_MAP_INI);					
}


// draws an explosion frame at the XY coordinates of the sprite
void PrintExplosion(TSpr *pSpr, u8 frame) {
	cpct_drawSpriteMaskedAlignedTable(g_explosion[frame], 
									  cpct_getScreenPtr(CPCT_VMEM_START, pSpr->x, pSpr->y), 
									  SPR_W, SPR_H, g_maskTable);
}


// Eliminate the player with an explosion
void ExplodePlayer() {
	// To visualize the crash, it shows explosions with pauses
	cpct_akp_SFXPlay (4, 15, 40, 0, 0, AY_CHANNEL_A); // explosion FX
	PrintExplosion(&spr[0], 0); Pause(20);
	PrintExplosion(&spr[0], 1); Pause(20); DeleteSprite(&spr[0]);
	PrintExplosion(&spr[0], 0); Pause(20); DeleteSprite(&spr[0]);	
}


// assign the frame corresponding to the animation sequence of the sprite
void SelectFrame(TSpr *pSpr) __z88dk_fastcall {
	TFrm* f;
	// player sprite
	if (pSpr->ident == PLAYER) {
		switch(pSpr->status) {
			case S_stopped:		pSpr->frm = &frm_player[0]; break;
			case S_walking:		pSpr->frm = animWalk[pSpr->nFrm / ANIM_PAUSE]; break; // 0,1,0,2
			case S_climbing:	pSpr->frm = animClimb[pSpr->nFrm / ANIM_PAUSE]; break; // 4,5
			case S_falling:		pSpr->frm = &frm_player[3]; break;
			case S_landing:		pSpr->frm = &frm_player[1]; break; }
	}
	// enemy/platform sprite
	else if (ctMainLoop % ANIM_PAUSE == 0) {
		switch (pSpr->ident) {
			case PIRATE:		pSpr->frm = animPirate[pSpr->nFrm / ANIM_PAUSE]; break;
			case RAT:			pSpr->frm = animRat[pSpr->nFrm / ANIM_PAUSE]; break;
			case PARROT:		pSpr->frm = animParrot[pSpr->nFrm / ANIM_PAUSE]; break;	
			case PLATFORM:		pSpr->frm = animPlatform[pSpr->nFrm / ANIM_PAUSE]; break;}
	}
	// rotate the sprite
	f = pSpr->frm;
	// makes the turn if a change in the direction of movement has been detected
	if (f->dir != pSpr->dir) {
		cpct_hflipSpriteM0(SPR_W, SPR_H, f->spr);         
		f->dir = pSpr->dir; // save position to compare with next call
	}
}


// next frame of the enemy/platform animation sequence
void AnimateSprite(TSpr *pSpr) __z88dk_fastcall {
	if(++pSpr->nFrm == 2 * ANIM_PAUSE) pSpr->nFrm = 0;
}


// Check if there has been a collision of the player with other sprites
void CheckCollisions(TSpr *pSpr) { // __z88dk_fastcall
	// collision between sprites
	if ((spr[0].x + SPR_W) > (pSpr->x + 2) && (spr[0].x + 2) < (pSpr->x + SPR_W))
		if ((spr[0].y + SPR_H) > (pSpr->y + 2) && (spr[0].y + 2) < (pSpr->y + SPR_H)) {
			// an enemy has touched the player			
			ExplodePlayer();
			spr[0].lives--;
			LoseLife();
		}
}










////////////////////////////////////////////////////////////////////////////////
//	FUNCTIONS FOR PLAYER MANAGEMENT
////////////////////////////////////////////////////////////////////////////////

// abort, mute, pause keys
void CheckSecondaryKeys() {
	// abort, leave the game		
	if(cpct_isKeyPressed(ctlAbort)) {
		ExplodePlayer();
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
		cpct_akp_musicInit(Ingame1);
	}
}


// adjust the player to the ground
void AdjustToGround() {	
	while ((spr[0].y + 1) % 4 != 0) 
		spr[0].y--;
}


// moves the player upwards
void MoveUp() { 
		spr[0].y--;
}


// moves the player downwards
void MoveDown() {
		spr[0].y++;
}


// moves the player to the left if possible
void MoveLeft() {
	if (spr[0].x > 0) {
		if (!CheckDoor(&spr[0])) {
			spr[0].x--;
			spr[0].dir = D_left;
			CheckKeys();
			CheckObjects();
		}
	}
}


// moves the player to the right if possible
void MoveRight() { 
	if (spr[0].x + SPR_W < GLOBAL_MAX_X) {
		if (!CheckDoor(&spr[0])) {
			spr[0].x++;
			spr[0].dir = D_right;
			CheckKeys();
			CheckObjects();
		}
	}
}


// prepare the movement to the left or right
void WalkIn(u8 dir) __z88dk_fastcall {
	spr[0].nFrm = 0;
	spr[0].status = S_walking;
	spr[0].dir = dir;
}


// falling, movement is allowed in the meantime
void Falling() {
	//if (cpct_isKeyPressed(ctlLeft)) MoveLeft();
	//else if (cpct_isKeyPressed(ctlRight)) MoveRight();
	spr[0].y += 3;	
	if (OnTheGround() || OnStairs(D_down)) { // if the player is on a ground tile ...
		AdjustToGround();
		spr[0].status = S_landing;
	}
}


// will change the status to stopped
void StopIn() {
	spr[0].status = S_stopped;
	AdjustToGround();
}


// stands still
void Stopped() {
	if(cpct_isKeyPressed(ctlUp)) {if(OnStairs(D_up)) spr[0].status = S_climbing;} // going to climb a ladder
	else if(cpct_isKeyPressed(ctlDown)) {if(OnStairs(D_down)) spr[0].status = S_climbing;} // going down a ladder
	else if(cpct_isKeyPressed(ctlLeft)) WalkIn(D_left);
	else if(cpct_isKeyPressed(ctlRight)) WalkIn(D_right);	
	// facing door
	else if(cpct_isKeyPressed(ctlOpen) && FacingDoor()) {
		SetNextMap();	
		SetMapData();
		PrintMap();
	}
	else // abort, mute, pause ?
		CheckSecondaryKeys();
}


// assign the frame corresponding to the player animation sequence
void WalkAnim(u8 dir) __z88dk_fastcall {
	spr[0].dir  = dir;
	if(++spr[0].nFrm == 4 * ANIM_PAUSE) spr[0].nFrm = 0;
}


void Walking() {
	if (cpct_isKeyPressed(ctlUp)) {if (OnStairs(D_up)) spr[0].status = S_climbing;} // going to climb a ladder	
	else if (cpct_isKeyPressed(ctlDown)) {if (OnStairs(D_down)) spr[0].status = S_climbing;} // going down a ladder
	else if (cpct_isKeyPressed(ctlLeft)) {MoveLeft(); WalkAnim(D_left);}
	else if (cpct_isKeyPressed(ctlRight)) {MoveRight(); WalkAnim(D_right);}
	else StopIn();

	if (!OnTheGround() && !OnStairs(D_down)) // if it's not on the ground/stair, it is also falling
		spr[0].status = S_falling;
}


void Climbing() {
	if(cpct_isKeyPressed(ctlUp)) {
		if(OnStairs(D_up)) {MoveUp(); WalkAnim(spr[0].dir);} 
		else spr[0].status = S_stopped;
	}
	else if(cpct_isKeyPressed(ctlDown))	{
		if(OnStairs(D_down)) {MoveDown(); WalkAnim(spr[0].dir);}
		else spr[0].status = S_stopped;
	}
	else // abort, mute, pause ?
		CheckSecondaryKeys();
}


// call the appropriate function based on the status of the main sprite
void RunStatus() {
	switch(spr[0].status) {
		case S_stopped:       	Stopped();			break;
		case S_walking:      	Walking();			break;
		case S_climbing:    	Climbing();			break;
		case S_falling:      	Falling();			break;
		case S_landing:  		StopIn();
	}
}










////////////////////////////////////////////////////////////////////////////////
//	FUNCTIONS FOR THE ENEMIES CONTROL
////////////////////////////////////////////////////////////////////////////////

// updates the XY coordinates of the sprites based on their movement type
void MoveSprite(TSpr *pSpr) { //__z88dk_fastcall
	switch(pSpr->movType) {
		case M_linear_X:
			pSpr->x += (pSpr->dir == D_right) ? 1 : -1;
			if (pSpr->x >= pSpr->max || pSpr->x <= pSpr->min 
			|| (pSpr->ident == PIRATE && CheckDoor(pSpr))) {
				pSpr->dir = (pSpr->dir == D_right) ? D_left : D_right;
			}
			break;

		case M_linear_Y:
			pSpr->y += (pSpr->dir == D_down) ? 2 : -2;
			if (pSpr->y >= pSpr->max || pSpr->y <= pSpr->min) {
				pSpr->dir = (pSpr->dir == D_down) ? D_up : D_down;
			}
			break;
	}
}


// assign properties to enemy/platform sprites
void SetSpriteParams(u8 i, u8 ident, u8 mov, u8 lives, u8 dir, u8 x, u8 y, u8 min, u8 max) {
	spr[i].status = S_walking;
	spr[i].ident = ident; 
	spr[i].movType = mov;
	spr[i].lives = lives; 
	spr[i].dir = dir; 
	spr[i].x = spr[i].px = x;
	spr[i].y = spr[i].py = y;
	spr[i].min = min;
	spr[i].max = max;
}


// sets the map values according to "currentMap".
// coordinate calculation: x=TILED(x)*2  y=(TILED(y)*4)+ORIG_MAP_Y  [ORIG_MAP_Y=56]
void SetMapData() {
	u8 y1 = 71;		// 1st floor
	u8 y2 = 107;	// 2nd floor
	u8 y3 = 143;	// 3rd floor
	u8 y4 = 179;	// 4th floor
	cpct_akp_SFXPlay (6, 14, 41, 0, 0, AY_CHANNEL_B); // event sound
	switch(currentMap) {
		case 0: {
			//        	  SPR IDENTITY  MOVEMENT    LIVES 	DIR       X    Y  Min  Max
			spr[1].lives = 0;
			SetSpriteParams(2, RAT,		M_linear_X,		1,  D_left,  72,  y2,   0,  72);	
			SetSpriteParams(3, PIRATE, 	M_linear_X, 	1,  D_left,  72,  y3,   0,  72);
			SetSpriteParams(4, PIRATE, 	M_linear_X, 	1,  D_right,  0,  y4,   0,  72);		
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk0_end);
			break;
		}	
		/*
		case 0: {
			//        	  SPR IDENTITY  MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			spr[1].lives = 0;
			SetSpriteParams(2, RAT,		M_linear_X,		1,  D_left,  72,  y2,    0,   y2,   72,   y2);	
			SetSpriteParams(3, PIRATE, 	M_linear_X, 	1,  D_left,  72,  y3,    0,   y3,   72,   y3);
			SetSpriteParams(4, PLATFORM, 	M_linear_X, 	1,  D_right,  0,  y4,    0,   y4,   72,   y4);		
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk0_end);
			break;
		}			
		case 1: {
			//        	  SPR IDENTITY  MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetSpriteParams(1, RAT,		M_linear_X,		1,  D_left,  72,  y1,    0,   y1,   72,   y1);
			SetSpriteParams(2, PIRATE, 	M_linear_X, 	1,  D_right,  0,  y2,    0,   y2,   72,   y2);	
			SetSpriteParams(3, PIRATE, 	M_linear_X, 	1,  D_right,  0,  y3,    0,   y3,   72,   y3);	
			spr[4].lives = 0;
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk1_end);
			break;
		}
		case 2: {
			//        	  SPR  IDENTITY  	MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetSpriteParams(1, PLATFORM, 	M_linear_X, 	1,  D_right, 30,  y1,   30,   y1,   60,   y1);
			SetSpriteParams(2, PLATFORM, 	M_linear_X, 	1,  D_left,  60,  y2,   30,   y2,   60,   y2);			
			SetSpriteParams(3, PLATFORM,	M_linear_X,		1,  D_left,  55,  y3,   30,   y3,   55,   y3);
			SetSpriteParams(3, PIRATE, 		M_linear_X, 	1,  D_left,  72,  y4,    0,   y4,   72,   y4);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk2_end);
			break;
		}
		case 3: {
			//        	  SPR IDENTITY  MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			spr[1].lives = 0;
			SetSpriteParams(2, PARROT,	M_linear_X,		1,  D_right,  0,  y2,    0,   y2,   72,   y2);
			SetSpriteParams(3, PIRATE, 	M_linear_X, 	1,  D_left,  72,  y3,   50,   y3,   72,   y3);
			SetSpriteParams(4, PIRATE, 	M_linear_X, 	1,  D_right,  0,  y4,    0,   y4,   72,   y4);	
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk3_end);
			break;
		}
		case 4: {
			//        	  SPR IDENTITY  MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetSpriteParams(1, PIRATE, 	M_linear_X, 	1,  D_right,  0,  y1,    0,   y1,   72,   y1);
			SetSpriteParams(2, PIRATE, 	M_linear_X, 	1,  D_left,  72,  y2,    0,   y2,   72,   y2);
			spr[3].lives = 0;
			SetSpriteParams(4, PARROT,	M_linear_X,		1,  D_right,  0,  y4,    0,   y4,   72,   y4);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk4_end);
			break;
		}
		case 5: {
			//        	  SPR IDENTITY  	MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetSpriteParams(4, PARROT,		M_linear_X,		1,  D_right,  0,  y1,    0,   y1,   72,   y1);
			SetSpriteParams(2, PLATFORM, 	M_linear_Y, 	1,  D_down,  50,  y1,   50,   y1,   50,   y4);
			SetSpriteParams(3, PLATFORM,	M_linear_Y,		1,  D_up,    60,  y4,   60,   y1,   60,   y4);
			SetSpriteParams(4, PIRATE,		M_linear_X,		1,  D_right, 60,  y4,   60,   y4,   72,   y4);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk5_end);
			break;
		}
		case 6: {
			//        	  SPR IDENTITY  MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetSpriteParams(1, PIRATE, 	M_linear_X, 	1,  D_right,  0,  y1,    0,   y1,   72,   y1);
			SetSpriteParams(2, PARROT,	M_linear_X,		1,  D_right,  0,  y2,    0,   y2,   72,   y2);
			SetSpriteParams(3, PIRATE,	M_linear_X,		1,  D_left,  72,  y3,    0,   y3,   72,   y3);
			SetSpriteParams(4, PIRATE,	M_linear_X,		1,  D_right,  0,  y4,    0,   y4,   72,   y4);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk6_end);
			break;
		}
		case 7: {
			//        	  SPR IDENTITY  MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			spr[1].lives = 0;
			SetSpriteParams(2, PARROT,	M_linear_X,		1,  D_right,  0,  y2,    0,   y2,   72,   y2);
			SetSpriteParams(3, PIRATE,	M_linear_X,		1,  D_right, 50,  y3,   50,   y3,   72,   y3);
			SetSpriteParams(4, PIRATE,	M_linear_X,		1,  D_right,  0,  y4,    0,   y4,   72,   y4);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk7_end);
			break;
		}
		case 8: {
			//        	  SPR IDENTITY  MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetSpriteParams(1, PIRATE, 	M_linear_X, 	1,  D_left,  70, 143,   30,  143,   70,  143);
			SetSpriteParams(2, PIRATE, 	M_linear_X, 	1,  D_right,  0, 179,    0,  179,   40,  179);
			SetSpriteParams(3, PIRATE,	M_linear_X,		0,  D_left,  70, 107,   30,  107,   70,  107);
			SetSpriteParams(4, PIRATE,	M_linear_X,		0,  D_right,  0,  71,    0,   71,   40,   71);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk8_end);
			break;
		}
		case 9: {
			//        	  SPR IDENTITY  MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetSpriteParams(1, PIRATE, 	M_linear_X, 	1,  D_left,  70, 143,   30,  143,   70,  143);
			SetSpriteParams(2, PIRATE, 	M_linear_X, 	1,  D_right,  0, 179,    0,  179,   40,  179);
			SetSpriteParams(3, PIRATE,	M_linear_X,		0,  D_left,  70, 107,   30,  107,   70,  107);
			SetSpriteParams(4, PIRATE,	M_linear_X,		0,  D_right,  0,  71,    0,   71,   40,   71);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk9_end);
			break;
		}
		case 10: {
			//        	  SPR IDENTITY  MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetSpriteParams(1, PIRATE, 	M_linear_X, 	1,  D_left,  70, 143,   30,  143,   70,  143);
			SetSpriteParams(2, PIRATE, 	M_linear_X, 	1,  D_right,  0, 179,    0,  179,   40,  179);
			SetSpriteParams(3, PIRATE,	M_linear_X,		0,  D_left,  70, 107,   30,  107,   70,  107);
			SetSpriteParams(4, PIRATE,	M_linear_X,		0,  D_right,  0,  71,    0,   71,   40,   71);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk10_end);
			break;
		}
		case 11: {
			//        	  SPR IDENTITY  MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetSpriteParams(1, PIRATE, 	M_linear_X, 	1,  D_left,  70, 143,   30,  143,   70,  143);
			SetSpriteParams(2, PIRATE, 	M_linear_X, 	1,  D_right,  0, 179,    0,  179,   40,  179);
			SetSpriteParams(3, PIRATE,	M_linear_X,		0,  D_left,  70, 107,   30,  107,   70,  107);
			SetSpriteParams(4, PIRATE,	M_linear_X,		0,  D_right,  0,  71,    0,   71,   40,   71);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk11_end);
			break;
		}
		case 12: {
			//        	  SPR IDENTITY  MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetSpriteParams(1, PIRATE, 	M_linear_X, 	1,  D_left,  70, 143,   30,  143,   70,  143);
			SetSpriteParams(2, PIRATE, 	M_linear_X, 	1,  D_right,  0, 179,    0,  179,   40,  179);
			SetSpriteParams(3, PIRATE,	M_linear_X,		0,  D_left,  70, 107,   30,  107,   70,  107);
			SetSpriteParams(4, PIRATE,	M_linear_X,		0,  D_right,  0,  71,    0,   71,   40,   71);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk12_end);
			break;
		}
		case 13: {
			//        	  SPR IDENTITY  MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetSpriteParams(1, PIRATE, 	M_linear_X, 	1,  D_left,  70, 143,   30,  143,   70,  143);
			SetSpriteParams(2, PIRATE, 	M_linear_X, 	1,  D_right,  0, 179,    0,  179,   40,  179);
			SetSpriteParams(3, PIRATE,	M_linear_X,		0,  D_left,  70, 107,   30,  107,   70,  107);
			SetSpriteParams(4, PIRATE,	M_linear_X,		0,  D_right,  0,  71,    0,   71,   40,   71);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk13_end);
			break;
		}
		case 14: {
			//        	  SPR IDENTITY  MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetSpriteParams(1, PIRATE, 	M_linear_X, 	1,  D_left,  70, 143,   30,  143,   70,  143);
			SetSpriteParams(2, PIRATE, 	M_linear_X, 	1,  D_right,  0, 179,    0,  179,   40,  179);
			SetSpriteParams(3, PIRATE,	M_linear_X,		0,  D_left,  70, 107,   30,  107,   70,  107);
			SetSpriteParams(4, PIRATE,	M_linear_X,		0,  D_right,  0,  71,    0,   71,   40,   71);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk14_end);
			break;
		}
		case 15: {
			//        	  SPR IDENTITY  MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetSpriteParams(1, PIRATE, 	M_linear_X, 	1,  D_left,  70, 143,   30,  143,   70,  143);
			SetSpriteParams(2, PIRATE, 	M_linear_X, 	1,  D_right,  0, 179,    0,  179,   40,  179);
			SetSpriteParams(3, PIRATE,	M_linear_X,		0,  D_left,  70, 107,   30,  107,   70,  107);
			SetSpriteParams(4, PIRATE,	M_linear_X,		0,  D_right,  0,  71,    0,   71,   40,   71);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk15_end);
			break;
		}
		case 16: {
			//        	  SPR IDENTITY  MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetSpriteParams(1, PIRATE, 	M_linear_X, 	1,  D_left,  70, 143,   30,  143,   70,  143);
			SetSpriteParams(2, PIRATE, 	M_linear_X, 	1,  D_right,  0, 179,    0,  179,   40,  179);
			SetSpriteParams(3, PIRATE,	M_linear_X,		0,  D_left,  70, 107,   30,  107,   70,  107);
			SetSpriteParams(4, PIRATE,	M_linear_X,		0,  D_right,  0,  71,    0,   71,   40,   71);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk16_end);
			break;
		}
		case 17: {
			//        	  SPR IDENTITY  MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetSpriteParams(1, PIRATE, 	M_linear_X, 	1,  D_left,  70, 143,   30,  143,   70,  143);
			SetSpriteParams(2, PIRATE, 	M_linear_X, 	1,  D_right,  0, 179,    0,  179,   40,  179);
			SetSpriteParams(3, PIRATE,	M_linear_X,		0,  D_left,  70, 107,   30,  107,   70,  107);
			SetSpriteParams(4, PIRATE,	M_linear_X,		0,  D_right,  0,  71,    0,   71,   40,   71);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk17_end);
			break;
		}
		case 18: {
			//        	  SPR IDENTITY  MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetSpriteParams(1, PIRATE, 	M_linear_X, 	1,  D_left,  70, 143,   30,  143,   70,  143);
			SetSpriteParams(2, PIRATE, 	M_linear_X, 	1,  D_right,  0, 179,    0,  179,   40,  179);
			SetSpriteParams(3, PIRATE,	M_linear_X,		0,  D_left,  70, 107,   30,  107,   70,  107);
			SetSpriteParams(4, PIRATE,	M_linear_X,		0,  D_right,  0,  71,    0,   71,   40,   71);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk18_end);
			break;
		}
		case 19: {
			//        	  SPR IDENTITY  MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetSpriteParams(1, PIRATE, 	M_linear_X, 	1,  D_left,  70, 143,   30,  143,   70,  143);
			SetSpriteParams(2, PIRATE, 	M_linear_X, 	1,  D_right,  0, 179,    0,  179,   40,  179);
			SetSpriteParams(3, PIRATE,	M_linear_X,		0,  D_left,  70, 107,   30,  107,   70,  107);
			SetSpriteParams(4, PIRATE,	M_linear_X,		0,  D_right,  0,  71,    0,   71,   40,   71);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk19_end);
			break;
		}*/
	}
	SetDoors();
	SetKeys();
	SetObjects();
}










////////////////////////////////////////////////////////////////////////////////
//	MAIN MENU
////////////////////////////////////////////////////////////////////////////////

void PrintDecorations(u8 y) __z88dk_fastcall {
	// upper left
	cpct_drawSprite(g_filigree, cpctm_screenPtr(CPCT_VMEM_START, 0, 0), G_FILIGREE_W, G_FILIGREE_H);
	// upper right
	cpct_hflipSpriteM0(G_FILIGREE_W, G_FILIGREE_H, g_filigree);	// horizontal reflection
    cpct_drawSprite(g_filigree, cpctm_screenPtr(CPCT_VMEM_START, 65, 0), G_FILIGREE_W, G_FILIGREE_H);
	//title
	cpct_drawSprite(g_title1, cpctm_screenPtr(CPCT_VMEM_START, 13, y), G_TITLE1_W, G_TITLE1_H);
	cpct_drawSprite(g_title2, cpctm_screenPtr(CPCT_VMEM_START, 13+G_TITLE1_W, y), G_TITLE2_W, G_TITLE2_H);
	// bottom right
	cpct_vflipSprite(G_FILIGREE_W, G_FILIGREE_H, cpctm_spriteBottomLeftPtr(g_filigree, 15, 36), g_filigree); // vertical reflection
	cpct_drawSprite(g_filigree, cpctm_screenPtr(CPCT_VMEM_START, 65, 164), G_FILIGREE_W, G_FILIGREE_H);
	// bottom left
	cpct_hflipSpriteM0(G_FILIGREE_W, G_FILIGREE_H, g_filigree);	// horizontal reflection
	cpct_drawSprite(g_filigree, cpctm_screenPtr(CPCT_VMEM_START, 0, 164), G_FILIGREE_W, G_FILIGREE_H);	
	// vertical reflection for the original position
	cpct_vflipSprite(G_FILIGREE_W, G_FILIGREE_H, cpctm_spriteBottomLeftPtr(g_filigree, 15, 36), g_filigree);
}


void PrintStartMenu() {
	PrintDecorations(15);
	// options
    PrintText("1@START@GAME", 22, 70);
    PrintText("2@REDEFINE@CONTROLS", 22, 80);
	// info
	PrintText("A@TRIBUTE@TO@THE@ORIGINAL", 15, 150);
	PrintText("GAME@BY@JOHN@F<CAIN", 21, 160);
	PrintText("AMSTRAD@ETERNO@EDITION", 18, 180);
    PrintText("PLAY@ON@RETRO@2023", 22, 190);
}


void StartMenu() {
	cpct_setBorder(g_palette[3]); // print border (dark red)
	cpct_akp_musicInit(Menu); // initialize music. Main theme 
	ClearScreen();
	PrintStartMenu();
	ct = 0;
	while(1) {
		cpct_scanKeyboard_f();
   	
   		if(cpct_isKeyPressed(Key_1)) { // start game
        	break;
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
        	PrintText("@@@@@", 35, 105);
    	}
		// credits
		else if (ct == 0)   PrintText("PROGRAM@AND@GRAPHICS:@SALVAKANTERO", 6,130);
		else if (ct == 85)  PrintText("@@@@@@@MUSIC@AND@FX:@BEYKER@@@@@@@", 6,130);
		else if (ct == 170) PrintText("@EXECUTIVE@PRODUCER:@FELIPE@MONGE@", 6,130);		
		ct++;
		Pause(15);
	}
	cpct_akp_musicInit(FX); // stop the music
	ClearScreen();
	cpct_setBorder(g_palette[1]); // print border (black)
	cpct_akp_musicInit(Ingame1); // in-game music
	// scoreboard
	PrintDecorations(6);
	PrintText("LIVES:@@@BOOTY:@@@;@@@@@KEY:@@@ROOM:", 2, ORIG_MAP_Y - 6);
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


// common values ​​for InitGame() and LoseLife() functions
void ResetScreen() {
	// print the scoreboard and the game screen	
	SetMapData();
	PrintMap();
	RefreshScoreboard();
	mustRedraw = TRUE;
}


// initialization of some variables
void InitGame() {
	StartMenu(); // start menu;
	music = TRUE;
	currentMap = 0;
	currentKey = 255;
	booty = 0;
	spr[0].lives = 9;
	sprTurn = 1;

	// player position
	spr[0].x = spr[0].px = 48;
	spr[0].y = spr[0].py = 71;
	spr[0].dir = D_left; 
	spr[0].status = S_stopped;

	// reset keys and doors data
	for (u8 i = 0; i <= ARRAY_SIZE; i++) {
		arrayDoorsYCopy[i] = arrayDoorsY[i];
		arrayKeysYCopy[i] = arrayKeysY[i];
	}
	// reset objects data
	for (u8 i = 0; i <= ARRAY_SIZE+20; i++)
		arrayObjectsYCopy[i] = arrayObjectsY[i];

	ResetScreen();
}


// the player loses a life
void LoseLife() {
	// if there are lives left
	if (spr[0].lives > 0) 
		ResetScreen();
	else { // prepare a new game
		cpct_akp_musicInit(FX); // stop the music
		RefreshScoreboard();
		// print a GAME OVER in the center of the play area
		PrintText("@@@@@@@@@@@", 30, 105);
		PrintText("@GAME@OVER@", 30, 110);
		PrintText("@@@@@@@@@@@", 30, 115);
		Pause(250);
		// wait for a key press
		while (!cpct_isAnyKeyPressed());
		InitGame();
	}
}


void main(void) {
	cpct_disableFirmware(); // disable firmware control
	cpct_akp_SFXInit(FX); //initialize sound effects
	cpct_setInterruptHandler(Interrupt); // initialize the interrupt manager (keyboard and sound)
	cpct_setVideoMode(0); // activate mode 0; 160*200 16 colors
	cpct_setPalette(g_palette, 16); // assign palette
	cpct_etm_setTileset2x4(g_tileset); // keep in memory the tiles for the maps (4 * 4)		
	InitValues(); // assigns default values ​​that do not vary between games
	InitGame(); // initialization of some variables

	while (1) { // main loop
		cpct_scanKeyboard_f(); // check the pressed keys		 	
		
		// update the player sprite
		RunStatus(); // call the appropriate function according to the player status 		
		SelectFrame(&spr[0]); // we assign the next frame of the animation to the player		
		
		// update the enemy/platform sprite
		if (spr[sprTurn].lives == 1) {
			MoveSprite(&spr[sprTurn]); // update the XY coordinates of the sprite		
			SelectFrame(&spr[sprTurn]); // select the animation frame...
			AnimateSprite(&spr[sprTurn]);	// and apply it		
			CheckCollisions(&spr[sprTurn]); // check if any collision has occurred
		}		

		// render the scene
		cpct_waitVSYNC(); // wait for the vertical retrace signal		
		// draw the player sprite?
		if (mustRedraw) {
			DeleteSprite(&spr[0]);
			PrintSprite(&spr[0]); // prints the player in the new XY position					
		}			
		// draw the enemy/platform sprite
		if (spr[sprTurn].lives == 1) {	
			DeleteSprite(&spr[sprTurn]);
			PrintSprite(&spr[sprTurn]); // prints the enemy/platform in the new XY position	
			spr[sprTurn].px = spr[sprTurn].x; // save the current X coordinate (for the next deletion)
			spr[sprTurn].py = spr[sprTurn].y; // save the current Y coordinate
		}

		mustRedraw = (spr[0].px != spr[0].x || spr[0].py != spr[0].y) ? TRUE : FALSE;	
		spr[0].px = spr[0].x; // save the current X coordinate of the player (for the next deletion)
		spr[0].py = spr[0].y; // save the current Y coordinate of the player

		if (++sprTurn == 5) sprTurn = 1; // four turns. Only one (enemy) moves at a time (prevents flicker)
		if (ctMainLoop % 15 == 0) RefreshScoreboard();
		if (++ctMainLoop == 255) ctMainLoop = 0;
		
		// DEBUG INFO								
		//PrintNumber(mustRedraw, 1, 40, 0);	
		//PrintNumber(spr[0].y, 3, 40, 7);
		//PrintNumber(spr[0].y, 3, 50, 25, TRUE); 
	}
}
