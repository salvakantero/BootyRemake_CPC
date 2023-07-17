
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
#include "sprites/pirate.h"			// 2 frames for the pirate enemy (14x16 px)
#include "sprites/explosion.h"		// 2 frames for the explosion effect (14x16 px)
#include "sprites/rat.h"			// 2 frames for the rat enemy (14x16 px)
#include "sprites/parrot.h"			// 2 frames for the parrot enemy (14x16 px)
#include "sfx/sound.h"				// music and sound effects

// compressed game map. 40x36 tiles (160x144 px)
#include "map/mappk0.h"
// #include "map/mappk1.h"
// #include "map/mappk2.h"
// #include "map/mappk3.h"
// #include "map/mappk4.h"
// #include "map/mappk5.h"
// #include "map/mappk6.h"
// #include "map/mappk7.h"
// #include "map/mappk8.h"
// #include "map/mappk9.h"
// #include "map/mappk10.h"
// #include "map/mappk11.h"
// #include "map/mappk12.h"
// #include "map/mappk13.h"
// #include "map/mappk14.h"
// #include "map/mappk15.h"
// #include "map/mappk16.h"
// #include "map/mappk17.h"
// #include "map/mappk18.h"
// #include "map/mappk19.h"










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
#define TILE_OBJECTS_END	180

// maps
#define ORIG_MAP_Y 56	// the map starts at position 56 of the vertical coordinates
#define MAP_W 40		// game screen size in tiles (horizontal)
#define MAP_H 36		// game screen size in tiles (vertical)
#define TOTAL_MAPS 1 //20
#define UNPACKED_MAP_INI (u8*)(0x1031) // the music ends at 0x1030
#define UNPACKED_MAP_END (u8*)(0x15D0) // the program starts at 0x15D1

u8 currentMap; 		// current room number
u8 currentKey;		// current key number
u8 booty; 			// collected items (125 max.)
u8 music;			// "TRUE" = plays the music during the game, "FALSE" = only effects
u8 ctMainLoop; 		// main loop iteration counter
u8 ct;				// generic counter

// does not redraw the player if he does not change position
//u8 need2Print, firstLoop;

// keyboard/joystick control
cpct_keyID ctlUp;
cpct_keyID ctlDown;
cpct_keyID ctlLeft;
cpct_keyID ctlRight;
cpct_keyID ctlUse;
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
	u8 touched;	// touched sprite counter (to animate explosions)
	// enemy properties
	u8 xMin;	// minimun value X (left limit) 
	u8 xMax;	// maximum value X (right limit)
	u8 yMin;	// minimun value Y (upper limit)
	u8 yMax;	// maximun value Y (lower limit)
	u8 movType;	// movement type (see "enum_mov")
} TSpr;

TSpr spr[5];	// 0) player
				// 1) enemy #1
				// 2) enemy #2
				// 3) enemy #3
				// 4) enemy #4

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

enum { // enemy behavior
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

// animation sequences of enemy sprites
TFrm* const animPirate[2] = {&frm_pirate[0], &frm_pirate[1]};
TFrm* const animRat[2] = {&frm_rat[0], &frm_rat[1]};
TFrm* const animParrot[2] = {&frm_parrot[0], &frm_parrot[1]};

// X positions of the doors (in tiles)
const u8 tDoorsX[ARRAY_SIZE] = {
	15, 31, 12, 31, 12, 31, 15, 31,  0,
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
const u8 tDoorsY[ARRAY_SIZE] = {
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
const u8 tKeysX[ARRAY_SIZE] = {
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
const u8 tKeysY[ARRAY_SIZE] = {
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
const u8 tObjectsX[ARRAY_SIZE+20] = {
	 0,  1, 13,  3,  4,  7, 13,  0,  0,  0,
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
const u8 tObjectsY[ARRAY_SIZE+20] = {
	 1,  3,  3,  5,  7,  7,  7,  0,  0,  0,
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
const u8 tObjectsTN[ARRAY_SIZE+20] = {
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
u8 tDoorsYCopy[ARRAY_SIZE];
u8 tKeysYCopy[ARRAY_SIZE];
u8 tObjectsYCopy[ARRAY_SIZE+20];

// transparency mask
cpctm_createTransparentMaskTable(g_maskTable, 0x100, M0, 0);










////////////////////////////////////////////////////////////////////////////////
//	PREVIOUS STATEMENTS
////////////////////////////////////////////////////////////////////////////////

void SetEnemies();
void ExplodePlayer();
void GameOver();









////////////////////////////////////////////////////////////////////////////////
//	GENERIC FUNCTIONS
////////////////////////////////////////////////////////////////////////////////

// get the length of a string
u8 Strlen(const u8 *str) __z88dk_fastcall {
    const u8 *s;
    for (s = str; *s; ++s);
    return (s - str);
}


// converts an integer to ASCII
char* Itoa(u8 value, char* result) {    
    u8 tmp_value;
    char* ptr = result, *ptr1 = result, tmp_char;
    
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
//	GRAPHICS, MAPS AND TILES MANAGEMENT FUNCTIONS (px = in pixels, tx = in tiles)
/////////////////////////////////////////////////////////////////////////////////

// cleans the screen with the specified color
void ClearScreen() {
	cpct_memset(CPCT_VMEM_START, cpct_px2byteM0(BG_COLOR, BG_COLOR), 16384);
}


// print a number as a text string at XY coordinates
void PrintNumber(u8 num, u8 len, u8 px, u8 py) { 
	u8 txt[6];
	u8 zeros;
	u8 pos = 0;
	u8 nAux;

	Itoa(num, txt);    
	zeros = len - Strlen(txt);
	nAux = txt[pos];

	while(nAux != '\0')	{	
		u8* ptr = cpct_getScreenPtr(CPCT_VMEM_START, (zeros + pos) * FNT_W + px, py);
		cpct_drawSprite(g_font[nAux - 48], ptr, FNT_W, FNT_H);
		nAux = txt[++pos];
	}
}


// prints a character string at XY coordinates
void PrintText(u8 txt[], u8 px, u8 py) {
	u8 pos = 0;
	u8 car = txt[pos];

 	while(car != '\0') { // "@" = space    ";" = -   "?" = !!
		u8* ptr = cpct_getScreenPtr(CPCT_VMEM_START, (pos * FNT_W) + px, py);
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


// refresh data on scoreboard (coordinates in pixels, not in tiles)
void RefreshScoreboard() {
	PrintNumber(spr[0].lives, 1, 14, ORIG_MAP_Y - 6); // lives left 
	PrintNumber(booty, 3, 32, ORIG_MAP_Y - 6); // collected items
	PrintNumber(125-booty, 3, 41, ORIG_MAP_Y - 6); // pending items
	PrintNumber(currentMap+1, 2, 74, ORIG_MAP_Y - 6); // room number
	// key number
	if (currentKey == 255)
		PrintText("@", 58, ORIG_MAP_Y - 6); // no key
	else
		PrintNumber(currentKey+1, 1, 58, ORIG_MAP_Y - 6);
}


// ***** Tiles *****

// get the map tile number of a certain XY position (in pixels) of the current map
u8* GetTile(u8 px, u8 py) {	
	return UNPACKED_MAP_INI + (py - ORIG_MAP_Y) / 4 * MAP_W + px / 2;	
}


// set the map tile number of a certain XY position (in pixels) on the current map
void SetTile(u8 px, u8 py, u8 tileNumber) {
	u8* memPos = UNPACKED_MAP_INI + (py - ORIG_MAP_Y) / 4 * MAP_W + px / 2;
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


// ***** Doors *****

void DrawDoor(u8 number) {
	// coordinates from tiles to pixels
	u8 pos = currentMap * 9 + number;
	u8 px = tDoorsX[pos] * 2;
	u8 py = (tDoorsY[pos] * 4) + ORIG_MAP_Y;
	// door tiles
	SetTile(px, py, TILE_DOOR_TOP);
	for (u8 i = 4; i <= 16; i += 4)
		SetTile(px, py+i, TILE_DOOR_BODY);
	SetTile(px-2, py+8, TILE_DOOR_L_KNOB);
	SetTile(px+2, py+8, TILE_DOOR_R_KNOB);
}


void DeleteDoor(u8 number) {
	// coordinates from tiles to pixels
	u8 pos = currentMap * 9 + number;
	u8 px = tDoorsX[pos] * 2;
	u8 py = (tDoorsY[pos] * 4) + ORIG_MAP_Y;
	// door body
	for (u8 i = 0; i <= 16; i += 4)
		SetTile(px, py+i, TILE_BACKGROUND);
 	// knobs
 	SetTile(px-2, py+8, TILE_BACKGROUND);
 	SetTile(px+2, py+8, TILE_BACKGROUND);	
}


// obtains the door number according to its position (in tiles)
u8 GetDoorNumber(u8 tx, u8 ty) {
	u8 pos;
	for(u8 i = 0; i < 9; i++) {
		pos = currentMap * 9 + i;
		if (tDoorsX[pos] == tx && tDoorsY[pos] == ty) 
			return i;
	}
	return 254;
}


// draws the available doors by traversing the XY vectors
void SetDoors(void) {
	for(u8 i = 0; i < 9; i++)
		if (tDoorsYCopy[currentMap * 9 + i] != 0) 
			DrawDoor(i);
}


// returns "TRUE" or "1" if the player coordinates are placed in front of a closed door tile
// removes the door if we have the key
u8 CheckDoor(void) {
	u8 number;
	u8 px = spr[0].dir == D_right ? spr[0].x+5 : spr[0].x+1;
	u8 py = spr[0].y + SPR_H;
	// it's a locked door?
	if (*GetTile(px, py) == TILE_DOOR_BODY) {
		number = GetDoorNumber(px/2, ((py-ORIG_MAP_Y)/4)-4);
		// we have the key?
		if (number == currentKey) {
			DeleteDoor(number);			
			tDoorsYCopy[currentMap * 9 + number] = 0; // marks the door as open
			currentKey = 255; // without key
			return FALSE; // not in front of a door	(we have opened it with the key)
		}
		else {
			spr[0].x = spr[0].dir == D_right ? spr[0].x-2 : spr[0].x+2; // rebound
			return TRUE; // in front of a door (we do not have the key)
		}
	}
	return FALSE; // not in front of a door
}


// ***** Keys *****

void DrawKey(u8 number) {
	// coordinates from tiles to pixels
	u8 pos = currentMap * 9 + number;
	u8 px = tKeysX[pos] * 2;
	u8 py = (tKeysY[pos] * 4) + ORIG_MAP_Y;	
	// key
	SetTile(px, py, TILE_KEY_INI);
	SetTile(px+2, py, TILE_KEY_INI+1);
	SetTile(px+2, py+4, TILE_KEY_INI+2);
	SetTile(px+2, py+8, TILE_KEY_INI+3);
	// number
	SetTile(px, py+4, TILE_NUMBERS_INI + number);
	SetTile(px, py+8, TILE_NUMBERS_INI + number + 12);
	// refresh map area
	cpct_etm_drawTileBox2x4(tKeysX[pos], tKeysY[pos], 2, 3, MAP_W, 
		cpctm_screenPtr(CPCT_VMEM_START, 0, ORIG_MAP_Y), UNPACKED_MAP_INI);
}


void DeleteKey(u8 number) {
	// coordinates from tiles to pixels
	u8 pos = currentMap * 9 + number;
	u8 px = tKeysX[pos] * 2;
	u8 py = (tKeysY[pos] * 4) + ORIG_MAP_Y;
	// 2*3 tiles area
	for (u8 i = 0; i <= 8; i += 4)	{
		SetTile(px, py+i, TILE_BACKGROUND);
		SetTile(px+2, py+i, TILE_BACKGROUND);
	}
}


// obtains the key number according to its position (in tiles)
u8 GetKeyNumber(u8 tx, u8 ty) {
	u8 pos;
	for(u8 i = 0; i < 9; i++) {
		pos = currentMap * 9 + i;
		if (tKeysX[pos] == tx && tKeysY[pos] == ty) 
			return i;
	}
	return 255;
}


// draws the available keys by traversing the XY vectors
void SetKeys(void) {
	for(u8 i = 0; i < 9; i++)
		if (tKeysYCopy[currentMap * 9 + i] != 0)
			DrawKey(i);
}


// the player is located on a key tile?
void CheckKeys(void) {
	u8 px = spr[0].dir == D_right ? spr[0].x+4 : spr[0].x;
	u8 py = spr[0].y+8;
	// it's a key?
	if (*GetTile(px, py) == TILE_KEY_INI) {
		// restores the previous key
		if (currentKey != 255) {
			DrawKey(currentKey);
			tKeysYCopy[currentMap * 9 + currentKey] = 
				tKeysY[currentMap * 9 + currentKey]; // marks the key as available
		}
		// collects the current key
		currentKey = GetKeyNumber(px/2, (py-ORIG_MAP_Y)/4);
		DeleteKey(currentKey);
		tKeysYCopy[currentMap * 9 + currentKey] = 0; // marks the key as in use
	}
}


// ***** Objects *****

void DrawObject(u8 number) {
	// coordinates from tiles to pixels
	u8 pos = currentMap * 10 + number;
	u8 px = tObjectsX[pos] * 2;
	u8 py = (tObjectsY[pos] * 4) + ORIG_MAP_Y;	
	// object (3*4 tiles)
	u8 tileNum = 0;
	for (u8 i=0; i<=12; i+=4)
		for (u8 j=0; j<=8; j+=4)
			SetTile(px+j, py+i, TILE_OBJECTS_INI + (12*number) + j + tileNum++);
}


void DeleteObject(u8 number) {
	// coordinates from tiles to pixels
	u8 pos = currentMap * 10 + number;
	u8 px = tObjectsX[pos] * 2;
	u8 py = (tObjectsY[pos] * 4) + ORIG_MAP_Y;
	// 3*4 tiles area
	for (u8 i=0; i<=12; i+=4)
		for (u8 j=0; j<=8; j+=4)
			SetTile(px+j, py+i, TILE_BACKGROUND);
}


// obtains the object number according to its position (in tiles)
u8 GetObjectNumber(u8 tx, u8 ty) {
	u8 pos;
	for(u8 i = 0; i < 10; i++) {
		pos = currentMap * 10 + i;
		if (tKeysX[pos] == tx && tKeysY[pos] == ty) 
			return i;
	}
	return 255;
}


// draws the available objects by traversing the XY vectors
void SetObjects(void) {
	for(u8 i = 0; i < 10; i++)
		if (tObjectsYCopy[currentMap * 10 + i] != 0)
			DrawObject(i);
}


// the player is located on an object tile?
void CheckObjects(void) {
	u8 objectNumber;
	u8 px = spr[0].dir == D_right ? spr[0].x+4 : spr[0].x;
	u8 py = spr[0].y+8;
	u8 tile = *GetTile(px, py);
	if (tile >= TILE_OBJECTS_INI && tile <= TILE_OBJECTS_END) {	
		objectNumber = GetObjectNumber(px/2, (py-ORIG_MAP_Y)/4);
		DeleteKey(objectNumber);
		tObjectsYCopy[objectNumber] = 0;
		booty++;
	}
}


/*
// chequeamos si todas las puertas del pasillo están abiertas. Salva (02/12/18)
unsigned char open_doors(unsigned char y)
{
	unsigned char i, j, result = 1; // 1 = doors open (default)

	// converting pixels to doors Y positions
	if (y == 16) y = 1;
	else if (y == 48) y = 5;
	else if (y == 80) y = 9;
	else if (y == 112) y = 13;

	for(i = 0; i < 9; i++)
	{
		j = n_pant * 9 + i;
		if (num_doors_y[j] == y)
		{
			result = 0;
			break;
		}
	}
	return result;
}
*/









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
	cpct_akp_SFXPlay (2, 15, 41, 0, 0, AY_CHANNEL_B);    
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
	cpct_etm_drawTileBox2x4(pSpr->px / 2, (pSpr->py - ORIG_MAP_Y) / 4, 
							4 + (pSpr->px & 1), 4 + (pSpr->py & 3 ? 1 : 0),	
							MAP_W, cpctm_screenPtr(CPCT_VMEM_START, 0, ORIG_MAP_Y), UNPACKED_MAP_INI);					
}


// draws an explosion frame at the XY coordinates of the sprite
void PrintExplosion(TSpr *pSpr, u8 frame) {
	cpct_drawSpriteMaskedAlignedTable(g_explosion[frame], 
									  cpct_getScreenPtr(CPCT_VMEM_START, pSpr->x, pSpr->y), 
									  SPR_W, SPR_H, g_maskTable);
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
			case PARROT:		pSpr->frm = animParrot[pSpr->nFrm / ANIM_PAUSE]; break;	}
	}
	// rotate the sprite
	f = pSpr->frm;
	// makes the turn if a change in the direction of movement has been detected
	if (f->dir != pSpr->dir) {
		cpct_hflipSpriteM0(SPR_W, SPR_H, f->spr);         
		f->dir = pSpr->dir; // save position to compare with next call
	}
}


// next frame of the enemy animation sequence
void EnemyWalkAnim(TSpr *pSpr) __z88dk_fastcall {
	if(++pSpr->nFrm == 2 * ANIM_PAUSE) pSpr->nFrm = 0;
}


// Check if there has been a collision of the player with other sprites
void CheckCollisions(TSpr *pSpr) { // __z88dk_fastcall
	// collision between sprites
	if ((spr[0].x + SPR_W) > (pSpr->x + 2) && (spr[0].x + 2) < (pSpr->x + SPR_W))
		if ((spr[0].y + SPR_H) > (pSpr->y + 2) && (spr[0].y + 2) < (pSpr->y + SPR_H)) {
			// an enemy has touched the player
			spr[0].lives--;
			ExplodePlayer();
			GameOver();
		}
}










////////////////////////////////////////////////////////////////////////////////
//	FUNCTIONS FOR PLAYER MANAGEMENT
////////////////////////////////////////////////////////////////////////////////

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
		if (!CheckDoor()) {
			spr[0].x--;
			spr[0].dir = D_left;
			CheckKeys();
		}
	}
}


// moves the player to the right if possible
void MoveRight() { 
	if (spr[0].x + SPR_W < GLOBAL_MAX_X) {
		if (!CheckDoor()) {
			spr[0].x++;
			spr[0].dir = D_right;
			CheckKeys();
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
	cpct_scanKeyboard_f(); // check the pressed keys
	//need2Print = TRUE;

	if (cpct_isKeyPressed(ctlLeft)) MoveLeft();
	else if (cpct_isKeyPressed(ctlRight)) MoveRight();
	
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
	cpct_scanKeyboard_f(); // check the pressed keys
	if(cpct_isKeyPressed(ctlUp)) {if(OnStairs(D_up)) spr[0].status = S_climbing;} // going to climb a ladder
	else if(cpct_isKeyPressed(ctlDown)) {if(OnStairs(D_down)) spr[0].status = S_climbing;} // going down a ladder
	else if(cpct_isKeyPressed(ctlLeft)) WalkIn(D_left);
	else if(cpct_isKeyPressed(ctlRight)) WalkIn(D_right);	
	else if(cpct_isKeyPressed(ctlAbort)) { // leave the game
		spr[0].lives = 0; 
		ExplodePlayer();
		GameOver();
	}
	else if(cpct_isKeyPressed(ctlMusic)) { // mute music TRUE/FALSE
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
	//else need2Print = FALSE;
}


// assign the frame corresponding to the player animation sequence
void WalkAnim(u8 dir) __z88dk_fastcall {
	spr[0].dir  = dir;
	if(++spr[0].nFrm == 4 * ANIM_PAUSE) spr[0].nFrm = 0;
}


void Walking() {
	//need2Print = TRUE;
	cpct_scanKeyboard_f(); // check the pressed keys
	if (cpct_isKeyPressed(ctlUp)) {if (OnStairs(D_up)) spr[0].status = S_climbing;} // going to climb a ladder	
	else if (cpct_isKeyPressed(ctlDown)) {if (OnStairs(D_down)) spr[0].status = S_climbing;} // going down a ladder
	else if (cpct_isKeyPressed(ctlLeft)) {MoveLeft(); WalkAnim(D_left);}
	else if (cpct_isKeyPressed(ctlRight)) {MoveRight(); WalkAnim(D_right);}
	else StopIn();

	if (!OnTheGround() && !OnStairs(D_down)) // if it is not on the ground/stair, it is also falling
		spr[0].status = S_falling;
}


void Climbing() {
	//need2Print = TRUE;
	cpct_scanKeyboard_f(); // check the pressed keys

	if(cpct_isKeyPressed(ctlUp)) {
		if(OnStairs(D_up)) {MoveUp(); WalkAnim(spr[0].dir);} 
		else spr[0].status = S_stopped;
	}
	else if(cpct_isKeyPressed(ctlDown))	{
		if(OnStairs(D_down)) {MoveDown(); WalkAnim(spr[0].dir);}
		else spr[0].status = S_stopped;
	}
	//else need2Print = FALSE;
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


// Eliminate the player with an explosion
void ExplodePlayer() {
	// To visualize the crash, it shows explosions with pauses
	cpct_akp_SFXPlay (4, 15, 40, 0, 0, AY_CHANNEL_A); // explosion
	PrintExplosion(&spr[0], 0); Pause(20);
	PrintExplosion(&spr[0], 1); Pause(20); DeleteSprite(&spr[0]);
	PrintExplosion(&spr[0], 0); Pause(20); DeleteSprite(&spr[0]);	
}










////////////////////////////////////////////////////////////////////////////////
//	FUNCTIONS FOR THE ENEMIES CONTROL
////////////////////////////////////////////////////////////////////////////////

// updates the XY coordinates of the sprites based on their movement type
void MoveEnemy(TSpr *pSpr) { //__z88dk_fastcall
	switch(pSpr->movType) {
		case M_linear_X:
			pSpr->x += (pSpr->dir == D_right) ? 1 : -1;
			if (pSpr->x >= pSpr->xMax || pSpr->x <= pSpr->xMin) {
				pSpr->dir = (pSpr->dir == D_right) ? D_left : D_right;
			}
			break;

		case M_linear_Y:
			pSpr->y += (pSpr->dir == D_down) ? 2 : -2;
			if (pSpr->y >= pSpr->yMax || pSpr->y <= pSpr->yMin) {
				pSpr->dir = (pSpr->dir == D_down) ? D_up : D_down;
			}
			break;
	}
}


// assign properties to enemy sprites
void SetEnemyParams(u8 i, u8 ident, u8 mov, u8 lives, u8 dir, u8 x, u8 y, u8 xMin, u8 yMin, u8 xMax, u8 yMax) {
	spr[i].status = S_walking;
	spr[i].ident = ident; 
	spr[i].movType = mov;
	spr[i].lives = lives; 
	spr[i].dir = dir; 
	spr[i].x = spr[i].px = x;
	spr[i].y = spr[i].py = y;
	spr[i].xMin = xMin;
	spr[i].yMin = yMin;
	spr[i].xMax = xMax;
	spr[i].yMax = yMax; 
}


// enemy values based on current map
// coordinate calculation: x=TILED(x)*4/2  y=(TILED(y)*4)+ORIG_MAP_Y  [ORIG_MAP_Y=64]
void SetEnemies() {
	switch(currentMap) {
		case 0: {
			//        	  SPR IDENTITY  MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, PIRATE, 	M_linear_X, 	1,  D_left,  70, 143,   30,  143,   70,  143);
			SetEnemyParams(2, PIRATE, 	M_linear_X, 	1,  D_right,  0, 179,    0,  179,   40,  179);
			SetEnemyParams(3, PIRATE,	M_linear_X,		0,  D_left,  70, 107,   30,  107,   70,  107);
			SetEnemyParams(4, PIRATE,	M_linear_X,		0,  D_right,  0,  71,    0,   71,   40,   71);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk0_end);
			break;
		}	
		/*	
		case 1: {
			//        	  SPR IDENTITY  MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, PIRATE, 	M_linear_X, 	1,  D_left,  70, 143,   30,  143,   70,  143);
			SetEnemyParams(2, PIRATE, 	M_linear_X, 	1,  D_right,  0, 179,    0,  179,   40,  179);
			SetEnemyParams(3, PIRATE,	M_linear_X,		0,  D_left,  70, 107,   30,  107,   70,  107);
			SetEnemyParams(4, PIRATE,	M_linear_X,		0,  D_right,  0,  71,    0,   71,   40,   71);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk1_end);
			break;
		}
		case 2: {
			//        	  SPR IDENTITY  MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, PIRATE, 	M_linear_X, 	1,  D_left,  70, 143,   30,  143,   70,  143);
			SetEnemyParams(2, PIRATE, 	M_linear_X, 	1,  D_right,  0, 179,    0,  179,   40,  179);
			SetEnemyParams(3, PIRATE,	M_linear_X,		0,  D_left,  70, 107,   30,  107,   70,  107);
			SetEnemyParams(4, PIRATE,	M_linear_X,		0,  D_right,  0,  71,    0,   71,   40,   71);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk2_end);
			break;
		}
		case 3: {
			//        	  SPR IDENTITY  MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, PIRATE, 	M_linear_X, 	1,  D_left,  70, 143,   30,  143,   70,  143);
			SetEnemyParams(2, PIRATE, 	M_linear_X, 	1,  D_right,  0, 179,    0,  179,   40,  179);
			SetEnemyParams(3, PIRATE,	M_linear_X,		0,  D_left,  70, 107,   30,  107,   70,  107);
			SetEnemyParams(4, PIRATE,	M_linear_X,		0,  D_right,  0,  71,    0,   71,   40,   71);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk3_end);
			break;
		}
		case 4: {
			//        	  SPR IDENTITY  MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, PIRATE, 	M_linear_X, 	1,  D_left,  70, 143,   30,  143,   70,  143);
			SetEnemyParams(2, PIRATE, 	M_linear_X, 	1,  D_right,  0, 179,    0,  179,   40,  179);
			SetEnemyParams(3, PIRATE,	M_linear_X,		0,  D_left,  70, 107,   30,  107,   70,  107);
			SetEnemyParams(4, PIRATE,	M_linear_X,		0,  D_right,  0,  71,    0,   71,   40,   71);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk4_end);
			break;
		}
		case 5: {
			//        	  SPR IDENTITY  MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, PIRATE, 	M_linear_X, 	1,  D_left,  70, 143,   30,  143,   70,  143);
			SetEnemyParams(2, PIRATE, 	M_linear_X, 	1,  D_right,  0, 179,    0,  179,   40,  179);
			SetEnemyParams(3, PIRATE,	M_linear_X,		0,  D_left,  70, 107,   30,  107,   70,  107);
			SetEnemyParams(4, PIRATE,	M_linear_X,		0,  D_right,  0,  71,    0,   71,   40,   71);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk5_end);
			break;
		}
		case 6: {
			//        	  SPR IDENTITY  MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, PIRATE, 	M_linear_X, 	1,  D_left,  70, 143,   30,  143,   70,  143);
			SetEnemyParams(2, PIRATE, 	M_linear_X, 	1,  D_right,  0, 179,    0,  179,   40,  179);
			SetEnemyParams(3, PIRATE,	M_linear_X,		0,  D_left,  70, 107,   30,  107,   70,  107);
			SetEnemyParams(4, PIRATE,	M_linear_X,		0,  D_right,  0,  71,    0,   71,   40,   71);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk6_end);
			break;
		}
		case 7: {
			//        	  SPR IDENTITY  MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, PIRATE, 	M_linear_X, 	1,  D_left,  70, 143,   30,  143,   70,  143);
			SetEnemyParams(2, PIRATE, 	M_linear_X, 	1,  D_right,  0, 179,    0,  179,   40,  179);
			SetEnemyParams(3, PIRATE,	M_linear_X,		0,  D_left,  70, 107,   30,  107,   70,  107);
			SetEnemyParams(4, PIRATE,	M_linear_X,		0,  D_right,  0,  71,    0,   71,   40,   71);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk7_end);
			break;
		}
		case 8: {
			//        	  SPR IDENTITY  MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, PIRATE, 	M_linear_X, 	1,  D_left,  70, 143,   30,  143,   70,  143);
			SetEnemyParams(2, PIRATE, 	M_linear_X, 	1,  D_right,  0, 179,    0,  179,   40,  179);
			SetEnemyParams(3, PIRATE,	M_linear_X,		0,  D_left,  70, 107,   30,  107,   70,  107);
			SetEnemyParams(4, PIRATE,	M_linear_X,		0,  D_right,  0,  71,    0,   71,   40,   71);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk8_end);
			break;
		}
		case 9: {
			//        	  SPR IDENTITY  MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, PIRATE, 	M_linear_X, 	1,  D_left,  70, 143,   30,  143,   70,  143);
			SetEnemyParams(2, PIRATE, 	M_linear_X, 	1,  D_right,  0, 179,    0,  179,   40,  179);
			SetEnemyParams(3, PIRATE,	M_linear_X,		0,  D_left,  70, 107,   30,  107,   70,  107);
			SetEnemyParams(4, PIRATE,	M_linear_X,		0,  D_right,  0,  71,    0,   71,   40,   71);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk9_end);
			break;
		}
		case 10: {
			//        	  SPR IDENTITY  MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, PIRATE, 	M_linear_X, 	1,  D_left,  70, 143,   30,  143,   70,  143);
			SetEnemyParams(2, PIRATE, 	M_linear_X, 	1,  D_right,  0, 179,    0,  179,   40,  179);
			SetEnemyParams(3, PIRATE,	M_linear_X,		0,  D_left,  70, 107,   30,  107,   70,  107);
			SetEnemyParams(4, PIRATE,	M_linear_X,		0,  D_right,  0,  71,    0,   71,   40,   71);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk10_end);
			break;
		}
		case 11: {
			//        	  SPR IDENTITY  MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, PIRATE, 	M_linear_X, 	1,  D_left,  70, 143,   30,  143,   70,  143);
			SetEnemyParams(2, PIRATE, 	M_linear_X, 	1,  D_right,  0, 179,    0,  179,   40,  179);
			SetEnemyParams(3, PIRATE,	M_linear_X,		0,  D_left,  70, 107,   30,  107,   70,  107);
			SetEnemyParams(4, PIRATE,	M_linear_X,		0,  D_right,  0,  71,    0,   71,   40,   71);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk11_end);
			break;
		}
		case 12: {
			//        	  SPR IDENTITY  MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, PIRATE, 	M_linear_X, 	1,  D_left,  70, 143,   30,  143,   70,  143);
			SetEnemyParams(2, PIRATE, 	M_linear_X, 	1,  D_right,  0, 179,    0,  179,   40,  179);
			SetEnemyParams(3, PIRATE,	M_linear_X,		0,  D_left,  70, 107,   30,  107,   70,  107);
			SetEnemyParams(4, PIRATE,	M_linear_X,		0,  D_right,  0,  71,    0,   71,   40,   71);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk12_end);
			break;
		}
		case 13: {
			//        	  SPR IDENTITY  MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, PIRATE, 	M_linear_X, 	1,  D_left,  70, 143,   30,  143,   70,  143);
			SetEnemyParams(2, PIRATE, 	M_linear_X, 	1,  D_right,  0, 179,    0,  179,   40,  179);
			SetEnemyParams(3, PIRATE,	M_linear_X,		0,  D_left,  70, 107,   30,  107,   70,  107);
			SetEnemyParams(4, PIRATE,	M_linear_X,		0,  D_right,  0,  71,    0,   71,   40,   71);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk13_end);
			break;
		}
		case 14: {
			//        	  SPR IDENTITY  MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, PIRATE, 	M_linear_X, 	1,  D_left,  70, 143,   30,  143,   70,  143);
			SetEnemyParams(2, PIRATE, 	M_linear_X, 	1,  D_right,  0, 179,    0,  179,   40,  179);
			SetEnemyParams(3, PIRATE,	M_linear_X,		0,  D_left,  70, 107,   30,  107,   70,  107);
			SetEnemyParams(4, PIRATE,	M_linear_X,		0,  D_right,  0,  71,    0,   71,   40,   71);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk14_end);
			break;
		}
		case 15: {
			//        	  SPR IDENTITY  MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, PIRATE, 	M_linear_X, 	1,  D_left,  70, 143,   30,  143,   70,  143);
			SetEnemyParams(2, PIRATE, 	M_linear_X, 	1,  D_right,  0, 179,    0,  179,   40,  179);
			SetEnemyParams(3, PIRATE,	M_linear_X,		0,  D_left,  70, 107,   30,  107,   70,  107);
			SetEnemyParams(4, PIRATE,	M_linear_X,		0,  D_right,  0,  71,    0,   71,   40,   71);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk15_end);
			break;
		}
		case 16: {
			//        	  SPR IDENTITY  MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, PIRATE, 	M_linear_X, 	1,  D_left,  70, 143,   30,  143,   70,  143);
			SetEnemyParams(2, PIRATE, 	M_linear_X, 	1,  D_right,  0, 179,    0,  179,   40,  179);
			SetEnemyParams(3, PIRATE,	M_linear_X,		0,  D_left,  70, 107,   30,  107,   70,  107);
			SetEnemyParams(4, PIRATE,	M_linear_X,		0,  D_right,  0,  71,    0,   71,   40,   71);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk16_end);
			break;
		}
		case 17: {
			//        	  SPR IDENTITY  MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, PIRATE, 	M_linear_X, 	1,  D_left,  70, 143,   30,  143,   70,  143);
			SetEnemyParams(2, PIRATE, 	M_linear_X, 	1,  D_right,  0, 179,    0,  179,   40,  179);
			SetEnemyParams(3, PIRATE,	M_linear_X,		0,  D_left,  70, 107,   30,  107,   70,  107);
			SetEnemyParams(4, PIRATE,	M_linear_X,		0,  D_right,  0,  71,    0,   71,   40,   71);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk17_end);
			break;
		}
		case 18: {
			//        	  SPR IDENTITY  MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, PIRATE, 	M_linear_X, 	1,  D_left,  70, 143,   30,  143,   70,  143);
			SetEnemyParams(2, PIRATE, 	M_linear_X, 	1,  D_right,  0, 179,    0,  179,   40,  179);
			SetEnemyParams(3, PIRATE,	M_linear_X,		0,  D_left,  70, 107,   30,  107,   70,  107);
			SetEnemyParams(4, PIRATE,	M_linear_X,		0,  D_right,  0,  71,    0,   71,   40,   71);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk18_end);
			break;
		}
		case 19: {
			//        	  SPR IDENTITY  MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, PIRATE, 	M_linear_X, 	1,  D_left,  70, 143,   30,  143,   70,  143);
			SetEnemyParams(2, PIRATE, 	M_linear_X, 	1,  D_right,  0, 179,    0,  179,   40,  179);
			SetEnemyParams(3, PIRATE,	M_linear_X,		0,  D_left,  70, 107,   30,  107,   70,  107);
			SetEnemyParams(4, PIRATE,	M_linear_X,		0,  D_right,  0,  71,    0,   71,   40,   71);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk19_end);
			break;
		}*/
	}
	SetDoors();
	SetKeys();
	SetObjects();
}


// behavior of enemy sprites within the main loop
void EnemyLoop(TSpr *pSpr) __z88dk_fastcall {
	if (pSpr->lives == 1) { // If the enemy sprite is alive
		// update the XY coordinates of the sprite
		MoveEnemy(pSpr);
		// select the animation frame and apply it
		SelectFrame(pSpr); 
		EnemyWalkAnim(pSpr);
		// delete the sprite from the previous position and draw it in the current one
		DeleteSprite(pSpr);
		pSpr->px = pSpr->x; // save the current X coordinate
		pSpr->py = pSpr->y; // save the current Y coordinate
		PrintSprite(pSpr);
		// check if any collision has occurred
		CheckCollisions(pSpr);
	}
	// pausa compensatoria si el enemigo no está en pantalla
	//else if (pSpr->lives == 0) 
	//	Pause(20);
}










////////////////////////////////////////////////////////////////////////////////
//	MAIN MENU
////////////////////////////////////////////////////////////////////////////////

void PrintDecorations() {
	// upper left
	cpct_drawSprite(g_filigree, cpctm_screenPtr(CPCT_VMEM_START, 0, 0), G_FILIGREE_W, G_FILIGREE_H);
	// upper right
	cpct_hflipSpriteM0(G_FILIGREE_W, G_FILIGREE_H, g_filigree);	// horizontal reflection
    cpct_drawSprite(g_filigree, cpctm_screenPtr(CPCT_VMEM_START, 65, 0), G_FILIGREE_W, G_FILIGREE_H);
	//title
	cpct_drawSprite(g_title1, cpctm_screenPtr(CPCT_VMEM_START, 13, 7), G_TITLE1_W, G_TITLE1_H);
	cpct_drawSprite(g_title2, cpctm_screenPtr(CPCT_VMEM_START, 13+G_TITLE1_W, 7), G_TITLE2_W, G_TITLE2_H);
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
	PrintDecorations();
	// options
    PrintText("1@START@GAME", 22, 70);
    PrintText("2@REDEFINE@CONTROLS", 22, 80);
	// credits
	PrintText("A@TRIBUTE@TO@THE@ORIGINAL", 15, 160);
	PrintText("GAME@BY@JOHN@F<CAIN", 21, 170);
    PrintText("PROGRAM@AND@GRAPHICS@BY@SALVAKANTERO", 4,130);
    PrintText("MUSIC@BY@BEYKER", 26,140);
    PrintText("PLAY@ON@RETRO@2023", 22, 190);
}


void StartMenu() {
	cpct_setBorder(g_palette[3]); // print border (dark red)
	cpct_akp_musicInit(Menu); // initialize music. Main theme 
	ClearScreen();
	PrintStartMenu();

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
			ctlUse = 	RedefineKey("@USE@");
			ctlAbort = 	RedefineKey("ABORT");
			ctlMusic = 	RedefineKey("MUSIC");
			ctlPause =	RedefineKey("PAUSE");		
        	// delete the text line
        	PrintText("@@@@@", 35, 105);
    	}
		Pause(3);
	}
	cpct_akp_musicInit(FX); // stop the music
	cpct_akp_SFXPlay (6, 14, 41, 0, 0, AY_CHANNEL_B); // event sound
	ClearScreen();
	cpct_setBorder(g_palette[1]); // print border (black)
	cpct_akp_musicInit(Ingame1); // in-game music for level 1
	// scoreboard
	PrintDecorations();
	PrintText("LIVES:@@@BOOTY:000;@@@@@KEY:0@@ROOM:", 2, ORIG_MAP_Y - 6);
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
	ctlUse = Key_Space;
	ctlAbort = Key_X;
	ctlMusic = Key_M;
	ctlPause = Key_H;	
}


// common values ​​for InitGame() and GameOver() functions
void ResetData() {
	//need2Print = TRUE;
	// print the scoreboard and the game screen
	SetEnemies();
	PrintMap();
	RefreshScoreboard();
}


// initialization of some variables
void InitGame() {
	StartMenu(); // start menu;
	music = TRUE;
	currentMap = 0;
	currentKey = 255;
	booty = 0;
	spr[0].lives = 9; // 10 lives
		
	// player position
	spr[0].x = spr[0].px = 48;
	spr[0].y = spr[0].py = 71;
	spr[0].dir = D_left; 
	spr[0].status = S_stopped;

	// reset keys and doors data
	for (u8 i = 0; i <= ARRAY_SIZE; i++) {
		tDoorsYCopy[i] = tDoorsY[i];
		tKeysYCopy[i] = tKeysY[i];
	}
	// reset objects data
	for (u8 i = 0; i <= ARRAY_SIZE+20; i++)
		tObjectsYCopy[i] = tObjectsY[i];

	ResetData();
}


// the player loses a life
void GameOver() {
	// if there are lives
	if (spr[0].lives > 0) 
		ResetData(); // reassign data to some variables
	else { // prepare a new game
		cpct_akp_musicInit(FX); // stop the music
		RefreshScoreboard();
		// print a GAME OVER in the center of the play area
		PrintText("@@@@@@@@@@@", 25, 102);
		PrintText("@GAME@OVER@", 25, 110);
		PrintText("@@@@@@@@@@@", 25, 118);
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
		RunStatus(); // call the appropriate function according to the player status  
		//if (need2Print) {
			SelectFrame(&spr[0]); // we assign the next frame of the animation to the player
			cpct_waitVSYNC(); // wait for vertical retrace	
			DeleteSprite(&spr[0]);
			spr[0].px = spr[0].x; // save the current X coordinate
			spr[0].py = spr[0].y; // save the current Y coordinate			
			PrintSprite(&spr[0]); // prints the player in the new XY position
		//}		
		if (ctMainLoop % 3 == 0) { // move enemies						
			EnemyLoop(&spr[1]);
			//EnemyLoop(&spr[2]);
			//cpct_waitVSYNC(); // wait for vertical retrace			
			//EnemyLoop(&spr[3]);
			//EnemyLoop(&spr[4]);			
		}
		if (ctMainLoop % 15 == 0) // reprint scoreboard data
			RefreshScoreboard();	
		
		if (++ctMainLoop == 255) ctMainLoop = 0;

		// DEBUG INFO								
		//PrintNumber(spr[0].dir, 1, 40, 0);	
		//PrintNumber(spr[0].status, 1, 55, 25, TRUE);
		//PrintNumber(spr[0].y, 3, 50, 25, TRUE); 	
	}
}
