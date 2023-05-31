
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
#include "gfx/font.h"				// letters and numbers (6x8 px)
#include "gfx/logo.h"				// logo (100x20 px)

// sprites
#include "sprites/player.h"			// 6 frames for the player (14x16 px)
#include "sprites/pirate.h"			// 2 frames for pirate enemy (14x16 px)
#include "sprites/explosion.h"		// 2 frames for the explosion effect (14x16 px)
//#include "sprites/rat.h"			// 2 frames for rat enemy (14x16 px)
//#include "sprites/parrot.h"		// 2 frames for parrot enemy (14x16 px)
#include "sfx/sound.h"				// music and sound effects

// compressed game map. 40x36 tiles (160x144 px)
#include "map/mappk0.h"
/*
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
*/











////////////////////////////////////////////////////////////////////////////////
//	DEFINITIONS & VARIABLES
////////////////////////////////////////////////////////////////////////////////

#define TRUE 1
#define FALSE 0

#define GLOBAL_MAX_X  79 	// X maximum value for the screen (bytes)
#define GLOBAL_MAX_Y  200	// Y maximun value for the screen (px)

#define FNT_W 3	// width of text characters (bytes)
#define FNT_H 8 // height of text characters (px)

#define SPR_W 7 // sprite width (bytes)
#define SPR_H 16 // sprite height (px)

#define BG_COLOR 1 // black

// 3 different kinds of sprites
#define PLAYER		0
#define PIRATE	 	1
#define RAT			2
#define PARROT		3

// maps
#define ORIG_MAP_Y 56	// the map starts at position 56 of the vertical coordinates
#define MAP_W 40		// game screen size in tiles (horizontal)
#define MAP_H 36		// game screen size in tiles (vertical)
#define TOTAL_MAPS 1 //20
#define UNPACKED_MAP_INI (u8*)(0x1031) // the music ends at 0x1030
#define UNPACKED_MAP_END (u8*)(0x15D0) // the program starts at 0x15D1
u8 mapNumber = 0; // current room number

u8 booty = 0; 		// collected items
u8 treasure = 125;	// pending items
u8 music;			// "TRUE" = plays the music during the game, "FALSE" = only effects
u8 ctMainLoop; 		// main loop iteration counter
u8 ct;				// generic counter

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
	S_landing,
	S_touched,
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
//const TFrm frm_rat[2] = {{0, g_rat_0}, {0, g_rat_1}};
//const TFrm frm_parrot[2] = {{0, g_parrot_0}, {0, g_parrot_1}};

// animation sequences of enemy sprites
TFrm* const animPirate[2] = {&frm_pirate[0], &frm_pirate[1]};
//TFrm* const animRat[2] = {&frm_rat[0], &frm_rat[1]};
//TFrm* const animParrot[2] = {&frm_parrot[0], &frm_parrot[1]};

// posiciones X de las puertas (en tiles)
const unsigned char num_doors_x_base[20*9] =  {15, 31, 12, 31, 12, 31, 15, 31,  0,
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
// posiciones Y de las puertas (en tiles)
const unsigned char num_doors_y_base[20*9] =  { 1,  1, 10, 10, 19, 19, 28, 28,  0, 
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
// posiciones X de las llaves
const unsigned char num_keys_x_base[20*9] =	  {26, 20,  0, 14,  0, 10, 14,  4,  0,
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
// posiciones Y de las llaves
const unsigned char num_keys_y_base[20*9] =   {10, 14, 10,  2, 14, 10,  6,  2,  0, 
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

// Copias de los arrays anteriores para trabajar con ellos sin variar los arrays base
unsigned char num_doors_x[180];
unsigned char num_doors_y[180];
unsigned char num_keys_x[180];
unsigned char num_keys_y[180];

// transparency mask
cpctm_createTransparentMaskTable(g_maskTable, 0x100, M0, 0);










////////////////////////////////////////////////////////////////////////////////
//	PREVIOUS STATEMENTS
////////////////////////////////////////////////////////////////////////////////

void SetEnemies();
void ExplodePlayer();
void ExplodeEnemies();
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


// converts an integer to ASCII (Lukás Chmela / GPLv3)
char* Itoa(u16 value, char* result, int base) {    
    int tmp_value;
    char* ptr = result, *ptr1 = result, tmp_char;
    
    if (base < 2 || base > 36) { 
        *result = '\0'; 
        return result; 
    }
    
    do {
        tmp_value = value;
        value /= base;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
    } while (value);
    
    if (tmp_value < 0) 
        *ptr++ = '-';
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










////////////////////////////////////////////////////////////////////////////////
//	GRAPHICS, MAPS AND TILES MANAGEMENT FUNCTIONS
////////////////////////////////////////////////////////////////////////////////

// cleans the screen with the specified color
void ClearScreen() {
	cpct_memset(CPCT_VMEM_START, cpct_px2byteM0(BG_COLOR, BG_COLOR), 16384);
}


// print a number as a text string at XY coordinates
void PrintNumber(u16 num, u8 len, u8 x, u8 y, u8 prevDel) { 
	u8 txt[6];
	u8 zeros;
	u8 pos = 0;
	u8 nAux;

	Itoa(num, txt, 10);    
	zeros = len - Strlen(txt);
	nAux = txt[pos];

	while(nAux != '\0')	{	
		u8* ptr = cpct_getScreenPtr(CPCT_VMEM_START, (zeros + pos) * FNT_W + x, y);
		if (prevDel) 
			cpct_drawSolidBox(ptr, cpct_px2byteM0(BG_COLOR, BG_COLOR), FNT_W, FNT_H); // previous deletion
		cpct_drawSpriteMaskedAlignedTable(g_font[nAux - 48], ptr, FNT_W, FNT_H, g_maskTable);
		nAux = txt[++pos];
	}
}


// prints a character string at XY coordinates
void PrintText(u8 txt[], u8 x, u8 y) {
	u8 pos = 0;
	u8 car = txt[pos];

 	while(car != '\0') { // "@" = space    ";" = -   "?" = !!
		u8* ptr = cpct_getScreenPtr(CPCT_VMEM_START, (pos * FNT_W) + x, y);
		cpct_drawSpriteMaskedAlignedTable(g_font[car - 48], ptr, FNT_W, FNT_H, g_maskTable);
		car = txt[++pos];
	}
}


// refresh data on scoreboard
void RefreshScoreboard() {
	//PrintNumber(booty, 5, 21, 0, TRUE); // collected items
	//PrintNumber(treasure, 5, 60, 0, TRUE); // pending items
	//PrintNumber(spr[0].lives, 1, 8, 17, TRUE); // lives left 
}


// get the map tile number of a certain XY position
u8* GetTilePtr(u8 x, u8 y) {	
	return UNPACKED_MAP_INI + (y - ORIG_MAP_Y) / 4 * MAP_W + x / 2;	
}


// set the map tile number of a certain XY position
void SetTile(u8 x, u8 y, u8 tileNumber) {
	u8* memPos = UNPACKED_MAP_INI + (y - ORIG_MAP_Y) / 4 * MAP_W + x / 2;
	*memPos = tileNumber;
	PrintNumber(*memPos, 5, 11, 0, TRUE);
}


// print the map corresponding to the current map number 
void PrintMap() {	
	cpct_etm_drawTilemap2x4(MAP_W, MAP_H, 
		cpctm_screenPtr(CPCT_VMEM_START, 0, ORIG_MAP_Y), UNPACKED_MAP_INI);
}


// returns "TRUE" or "1" if the coordinates are placed on a platform tile
u8 OnPlatform() {
	if (*GetTilePtr(spr[0].x + 4, spr[0].y + SPR_H + 1) == 0)
		return TRUE;
	return FALSE;
}


// returns "TRUE" or "1" if the player coordinates are placed on a stairs tile
u8 OnStairs(u8 dir) __z88dk_fastcall {
	u8 tile;
	u8 y = spr[0].y + SPR_H;
	tile = *GetTilePtr(spr[0].x + 4, dir == D_up ? y : y+1);
	if (tile > 11 && tile < 18) 
        return TRUE;
    return FALSE;
}


// returns "TRUE" or "1" if the player coordinates are placed in front of a door tile
u8 FacingDoor(u8 dir) __z88dk_fastcall {
	u8 x = spr[0].x;
	if (*GetTilePtr(dir == D_right ? x+6 : x, spr[0].y + SPR_H) == 3) 
		return TRUE;
	return FALSE;
}


/*
// pintamos las llaves y puertas disponibles recorriendo los vectores X,Y. Salva (24/08/18)
void print_keys_and_doors(void)
{
	unsigned char i, j;
	for(i = 0; i < 9; i++)
	{
		// llaves
		j = n_pant * 9 + i;
		if (num_keys_y[j] != 0)
		{
			update_tile(num_keys_x[j]/2, num_keys_y[j]/2, 0, TILE_GET_KEY);
			sp_PrintAtInv(num_keys_y[j] + VIEWPORT_Y, num_keys_x[j], 
						  WHITE + BRIGHT, 16 + ((i + 1) % 10));
		}
		// puertas
		if (num_doors_y[j] != 0)
		{
			update_tile(num_doors_x[j]/2, num_doors_y[j]/2, 4, TILE_GET_DOOR_UP);
			update_tile(num_doors_x[j]/2, (num_doors_y[j]/2)+1, 8, TILE_GET_DOOR_DOWN);
			sp_PrintAtInv (	num_doors_y[j] + VIEWPORT_Y, num_doors_x[j], 
							RED, 16 + ((i + 1) % 10));
		}
		else if (num_doors_y_base[j] != 0) // puerta abierta, solo número
		{
			sp_PrintAtInv (	num_doors_y_base[j] + VIEWPORT_Y, num_doors_x_base[j], 
							RED, 16 + ((i + 1) % 10));
		}
	}
}


// pintamos los objetos disponibles recorriendo los vectores X,Y. Salva (25/08/18)
void print_objects(void)
{
	unsigned char i, j;
	for(i = 0; i < 10; i++)
	{
		j = n_pant * 10 + i;
		if (obj_y[j] != 0)
			update_tile(obj_x[j], obj_y[j], 0, obj_tn[j]);
	}
}


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
cpct_keyID RedefineKey(u8 *info) __z88dk_fastcall {
    cpct_keyID key; 
    PrintText(info, 29, 100);  
    key = ReturnKeyPressed();
    Wait4Key(key);
	cpct_akp_SFXPlay (2, 15, 41, 0, 0, AY_CHANNEL_B);    
    return key;    
}











////////////////////////////////////////////////////////////////////////////////
//	FUNCTIONS FOR SPRITE MANAGEMENT
////////////////////////////////////////////////////////////////////////////////

// prints the sprite and its mask at the current XY coordinates
void PrintSprite(TSpr *pSpr) __z88dk_fastcall {
	cpct_drawSpriteMaskedAlignedTable(pSpr->frm->spr, 
									  cpct_getScreenPtr(CPCT_VMEM_START, pSpr->x, pSpr->y), 
									  SPR_W, SPR_H, g_maskTable);
}


// print a portion of the map in the coordinates of the sprite (to delete it)
void DeleteSprite(TSpr *pSpr) __z88dk_fastcall {
	cpct_etm_drawTileBox2x4(pSpr->px / 2, (pSpr->py - ORIG_MAP_Y) / 4, 
							4 + (pSpr->px & 1), 4 + (pSpr->py & 3 ? 1 : 0),	
							MAP_W, cpctm_screenPtr(CPCT_VMEM_START, 0, ORIG_MAP_Y), UNPACKED_MAP_INI);					
}


// prints an explosion frame at the XY coordinates of the sprite
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
			//case RAT:			pSpr->frm = animRat[pSpr->nFrm / ANIM_PAUSE]; break;
			//case PARROT:		pSpr->frm = animParrot[pSpr->nFrm / ANIM_PAUSE]; break;	}
		}	
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


// Check if there has been a collision of the player with the enemies
void CheckEnemyCollision(TSpr *pSpr) { // __z88dk_fastcall
	// collision between sprites
	if ((spr[0].x + SPR_W) > (pSpr->x + 2) && (spr[0].x + 2) < (pSpr->x + SPR_W))
		if ((spr[0].y + SPR_H) > (pSpr->y + 2) && (spr[0].y + 2) < (pSpr->y + SPR_H)) {
			// an enemy has touched the player
			spr[0].lives--;
			ExplodePlayer();
			ExplodeEnemies();
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


void MoveUp() { 
	if (spr[0].y > ORIG_MAP_Y)
		spr[0].y--;
}


void MoveDown() {
	if (spr[0].y + SPR_H < GLOBAL_MAX_Y)
		spr[0].y++;
}


void MoveLeft() {
	if (spr[0].x > 0)
		if (!FacingDoor(D_left)) {
			spr[0].x--;
			spr[0].dir = D_left;
		}
}


void MoveRight() { 
	if (spr[0].x + SPR_W < GLOBAL_MAX_X)
		if (!FacingDoor(D_right)) {
			spr[0].x++;
			spr[0].dir = D_right;
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
	
	if (cpct_isKeyPressed(ctlLeft)) MoveLeft();
	else if (cpct_isKeyPressed(ctlRight)) MoveRight();
	
	spr[0].y += 3;	
	if (OnPlatform() || OnStairs(D_down)) { // if the player is on a platform ...
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
		ExplodeEnemies();
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
}


// assign the frame corresponding to the player animation sequence
void WalkAnim(u8 dir) __z88dk_fastcall {
	spr[0].dir  = dir;
	if(++spr[0].nFrm == 4 * ANIM_PAUSE) spr[0].nFrm = 0;
}


void Walking() {
	cpct_scanKeyboard_f(); // check the pressed keys
	
	if (cpct_isKeyPressed(ctlUp)) {if (OnStairs(D_up)) spr[0].status = S_climbing;} // going to climb a ladder	
	else if (cpct_isKeyPressed(ctlDown)) {if (OnStairs(D_down)) spr[0].status = S_climbing;} // going down a ladder
	else if (cpct_isKeyPressed(ctlLeft)) {MoveLeft(); WalkAnim(D_left);}
	else if (cpct_isKeyPressed(ctlRight)) {MoveRight(); WalkAnim(D_right);}
	else StopIn();

	if (!OnPlatform() && !OnStairs(D_down)) // if it is not on a platform/stair, it is also falling
		spr[0].status = S_falling;
}


void Climbing() {
	cpct_scanKeyboard_f(); // check the pressed keys
	if(cpct_isKeyPressed(ctlUp)) {
		if(OnStairs(D_up)) {MoveUp(); WalkAnim(D_right);} 
		else spr[0].status = S_stopped;
	}
	else if(cpct_isKeyPressed(ctlDown))	{
		if(OnStairs(D_down)) {MoveDown(); WalkAnim(D_right);}
	}
	else if(cpct_isKeyPressed(ctlLeft)) {
	 	if(OnStairs(D_up)) {MoveLeft(); WalkAnim(D_left);} 
	 	else spr[0].status = S_walking;
	}
	else if(cpct_isKeyPressed(ctlRight)) {
	 	if(OnStairs(D_up)) {MoveRight(); WalkAnim(D_right);} 
	 	else spr[0].status = S_walking;
	}
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
	spr[i].touched = 0;
}


// enemy values based on current map
// coordinate calculation: x=TILED(x)*4/2  y=(TILED(y)*4)+ORIG_MAP_Y  [ORIG_MAP_Y=64]
void SetEnemies() {
	switch(mapNumber) {
		case 0: {
			//        	  SPR IDENTITY   	MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, PIRATE, 	M_linear_X, 	1,  D_left,  70, 143,   30,  143,   70,  143);
			SetEnemyParams(2, PIRATE, 	M_linear_X, 	1,  D_right,  0, 179,    0,  179,   40,  179);
			SetEnemyParams(3, PIRATE,	M_linear_X,		0,  D_right,  0,   0,    0,    0,    0,    0);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk0_end);
			break;
		}
		/*
		case 1: {
			//        	  SPR IDENTITY   	MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, INFECTED, 	M_linear_X, 	2,  D_right,  0, 170,    0,  170,   40,  130);
			SetEnemyParams(2, INFECTED, 	M_linear_X, 	3,  D_left,  40, 150,   30,  150,   40,  110);
			SetEnemyParams(3, INFECTED,		M_linear_X,		0,  D_right,  0,   0,    0,    0,    0,    0);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk1_end);
			break;
		}
		case 2: {
			//        	  SPR IDENTITY   	MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, INFECTED, 	M_linear_X, 	2,  D_right,  0, 170,    0,  170,   40,  130);
			SetEnemyParams(2, INFECTED, 	M_linear_X, 	3,  D_left,  40, 150,   30,  150,   40,  110);
			SetEnemyParams(3, INFECTED,		M_linear_X,		0,  D_right,  0,   0,    0,    0,    0,    0);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk2_end);
			break;
		}
		case 3: {
			//        	  SPR IDENTITY   	MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, INFECTED, 	M_linear_X, 	2,  D_right,  0, 170,    0,  170,   40,  130);
			SetEnemyParams(2, INFECTED, 	M_linear_X, 	3,  D_left,  40, 150,   30,  150,   40,  110);
			SetEnemyParams(3, INFECTED,		M_linear_X,		0,  D_right,  0,   0,    0,    0,    0,    0);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk3_end);
			break;
		}
		case 4: {
			//        	  SPR IDENTITY   	MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, INFECTED, 	M_linear_X, 	2,  D_right,  0, 170,    0,  170,   40,  130);
			SetEnemyParams(2, INFECTED, 	M_linear_X, 	3,  D_left,  40, 150,   30,  150,   40,  110);
			SetEnemyParams(3, INFECTED,		M_linear_X,		0,  D_right,  0,   0,    0,    0,    0,    0);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk4_end);
			break;
		}
		case 5: {
			//        	  SPR IDENTITY   	MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, INFECTED, 	M_linear_X, 	2,  D_right,  0, 170,    0,  170,   40,  130);
			SetEnemyParams(2, INFECTED, 	M_linear_X, 	3,  D_left,  40, 150,   30,  150,   40,  110);
			SetEnemyParams(3, INFECTED,		M_linear_X,		0,  D_right,  0,   0,    0,    0,    0,    0);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk5_end);
			break;
		}
		case 6: {
			//        	  SPR IDENTITY   	MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, INFECTED, 	M_linear_X, 	2,  D_right,  0, 170,    0,  170,   40,  130);
			SetEnemyParams(2, INFECTED, 	M_linear_X, 	3,  D_left,  40, 150,   30,  150,   40,  110);
			SetEnemyParams(3, INFECTED,		M_linear_X,		0,  D_right,  0,   0,    0,    0,    0,    0);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk6_end);
			break;
		}
		case 7: {
			//        	  SPR IDENTITY   	MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, INFECTED, 	M_linear_X, 	2,  D_right,  0, 170,    0,  170,   40,  130);
			SetEnemyParams(2, INFECTED, 	M_linear_X, 	3,  D_left,  40, 150,   30,  150,   40,  110);
			SetEnemyParams(3, INFECTED,		M_linear_X,		0,  D_right,  0,   0,    0,    0,    0,    0);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk7_end);
			break;
		}
		case 8: {
			//        	  SPR IDENTITY   	MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, INFECTED, 	M_linear_X, 	2,  D_right,  0, 170,    0,  170,   40,  130);
			SetEnemyParams(2, INFECTED, 	M_linear_X, 	3,  D_left,  40, 150,   30,  150,   40,  110);
			SetEnemyParams(3, INFECTED,		M_linear_X,		0,  D_right,  0,   0,    0,    0,    0,    0);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk8_end);
			break;
		}
		case 9: {
			//        	  SPR IDENTITY   	MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, INFECTED, 	M_linear_X, 	2,  D_right,  0, 170,    0,  170,   40,  130);
			SetEnemyParams(2, INFECTED, 	M_linear_X, 	3,  D_left,  40, 150,   30,  150,   40,  110);
			SetEnemyParams(3, INFECTED,		M_linear_X,		0,  D_right,  0,   0,    0,    0,    0,    0);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk9_end);
			break;
		}
		case 10: {
			//        	  SPR IDENTITY   	MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, INFECTED, 	M_linear_X, 	2,  D_right,  0, 170,    0,  170,   40,  130);
			SetEnemyParams(2, INFECTED, 	M_linear_X, 	3,  D_left,  40, 150,   30,  150,   40,  110);
			SetEnemyParams(3, INFECTED,		M_linear_X,		0,  D_right,  0,   0,    0,    0,    0,    0);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk10_end);
			break;
		}
		case 11: {
			//        	  SPR IDENTITY   	MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, INFECTED, 	M_linear_X, 	2,  D_right,  0, 170,    0,  170,   40,  130);
			SetEnemyParams(2, INFECTED, 	M_linear_X, 	3,  D_left,  40, 150,   30,  150,   40,  110);
			SetEnemyParams(3, INFECTED,		M_linear_X,		0,  D_right,  0,   0,    0,    0,    0,    0);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk11_end);
			break;
		}
		case 12: {
			//        	  SPR IDENTITY   	MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, INFECTED, 	M_linear_X, 	2,  D_right,  0, 170,    0,  170,   40,  130);
			SetEnemyParams(2, INFECTED, 	M_linear_X, 	3,  D_left,  40, 150,   30,  150,   40,  110);
			SetEnemyParams(3, INFECTED,		M_linear_X,		0,  D_right,  0,   0,    0,    0,    0,    0);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk12_end);
			break;
		}
		case 13: {
			//        	  SPR IDENTITY   	MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, INFECTED, 	M_linear_X, 	2,  D_right,  0, 170,    0,  170,   40,  130);
			SetEnemyParams(2, INFECTED, 	M_linear_X, 	3,  D_left,  40, 150,   30,  150,   40,  110);
			SetEnemyParams(3, INFECTED,		M_linear_X,		0,  D_right,  0,   0,    0,    0,    0,    0);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk13_end);
			break;
		}
		case 14: {
			//        	  SPR IDENTITY   	MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, INFECTED, 	M_linear_X, 	2,  D_right,  0, 170,    0,  170,   40,  130);
			SetEnemyParams(2, INFECTED, 	M_linear_X, 	3,  D_left,  40, 150,   30,  150,   40,  110);
			SetEnemyParams(3, INFECTED,		M_linear_X,		0,  D_right,  0,   0,    0,    0,    0,    0);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk14_end);
			break;
		}
		case 15: {
			//        	  SPR IDENTITY   	MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, INFECTED, 	M_linear_X, 	2,  D_right,  0, 170,    0,  170,   40,  130);
			SetEnemyParams(2, INFECTED, 	M_linear_X, 	3,  D_left,  40, 150,   30,  150,   40,  110);
			SetEnemyParams(3, INFECTED,		M_linear_X,		0,  D_right,  0,   0,    0,    0,    0,    0);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk15_end);
			break;
		}
		case 16: {
			//        	  SPR IDENTITY   	MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, INFECTED, 	M_linear_X, 	2,  D_right,  0, 170,    0,  170,   40,  130);
			SetEnemyParams(2, INFECTED, 	M_linear_X, 	3,  D_left,  40, 150,   30,  150,   40,  110);
			SetEnemyParams(3, INFECTED,		M_linear_X,		0,  D_right,  0,   0,    0,    0,    0,    0);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk16_end);
			break;
		}
		case 17: {
			//        	  SPR IDENTITY   	MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, INFECTED, 	M_linear_X, 	2,  D_right,  0, 170,    0,  170,   40,  130);
			SetEnemyParams(2, INFECTED, 	M_linear_X, 	3,  D_left,  40, 150,   30,  150,   40,  110);
			SetEnemyParams(3, INFECTED,		M_linear_X,		0,  D_right,  0,   0,    0,    0,    0,    0);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk17_end);
			break;
		}
		case 18: {
			//        	  SPR IDENTITY   	MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, INFECTED, 	M_linear_X, 	2,  D_right,  0, 170,    0,  170,   40,  130);
			SetEnemyParams(2, INFECTED, 	M_linear_X, 	3,  D_left,  40, 150,   30,  150,   40,  110);
			SetEnemyParams(3, INFECTED,		M_linear_X,		0,  D_right,  0,   0,    0,    0,    0,    0);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk18_end);
			break;
		}
		case 19: {
			//        	  SPR IDENTITY   	MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, INFECTED, 	M_linear_X, 	2,  D_right,  0, 170,    0,  170,   40,  130);
			SetEnemyParams(2, INFECTED, 	M_linear_X, 	3,  D_left,  40, 150,   30,  150,   40,  110);
			SetEnemyParams(3, INFECTED,		M_linear_X,		0,  D_right,  0,   0,    0,    0,    0,    0);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk19_end);
			break;
		}*/	
	}
}


// explosion animation
void ExplosionSecuence(TSpr *pSpr) __z88dk_fastcall {
	if (pSpr->touched == 10) DeleteSprite(pSpr); 	
	else if (pSpr->touched > 8) PrintExplosion(pSpr, 0);
	else if (pSpr->touched > 6) PrintExplosion(pSpr, 1);
	else if (pSpr->touched > 4) PrintExplosion(pSpr, 0);
	else if (pSpr->touched > 2) DeleteSprite(pSpr); 
	pSpr->touched--;
}


// behavior of enemy sprites within the main loop
void EnemyLoop(TSpr *pSpr) __z88dk_fastcall {
	if (pSpr->lives >= 1) { // If the enemy sprite is alive
		// update the XY coordinates of the sprite
		if (pSpr->touched == 0) 
			MoveEnemy(pSpr);
		// select the animation frame and apply it
		SelectFrame(pSpr); 
		EnemyWalkAnim(pSpr);
		// delete the sprite from the previous position and paint in the current one
		DeleteSprite(pSpr);
		pSpr->px = pSpr->x; // save the current X coordinate
		pSpr->py = pSpr->y; // save the current Y coordinate
		PrintSprite(pSpr);
		// check if any collision has occurred
		//CheckEnemyCollision(pSpr);
		// enemy hit, it will explode ..
		if (pSpr->touched > 0) 
			ExplosionSecuence(pSpr);
	}
	else if (pSpr->touched > 0) { // enemy reached in his last life, will explode	
		ExplosionSecuence(pSpr);
	}
	else if (pSpr->status == S_touched) { // at this point it has died and exploded	
		pSpr->status = S_walking;		
		DeleteSprite(pSpr); 
	}	
	// pausa compensatoria si el enemigo no está en pantalla
	//else if (pSpr->lives == 0) 
	//	Pause(20);
}


// Eliminate all enemies on the screen with an explosion
void ExplodeEnemies() {
	for (ct = 1; ct < 5; ct++)
		if (spr[ct].lives > 0) {
			cpct_akp_SFXPlay (4, 15, 40, 0, 0, AY_CHANNEL_A); // explosion
			PrintExplosion(&spr[ct], 0); Pause(20);
			PrintExplosion(&spr[ct], 1); Pause(20); DeleteSprite(&spr[ct]);
			PrintExplosion(&spr[ct], 0); Pause(20);
			spr[ct].lives = 0;
			spr[ct].status = S_walking;
			DeleteSprite(&spr[ct]);
		} 
}










////////////////////////////////////////////////////////////////////////////////
//	MAIN MENU
////////////////////////////////////////////////////////////////////////////////

void PrintStartMenu() {
    cpct_drawSprite(g_logo, cpctm_screenPtr(CPCT_VMEM_START, 17, 0), G_LOGO_W, G_LOGO_H);

    PrintText("1@START@GAME", 5, 45);
    PrintText("2@REDEFINE@CONTROLS", 5, 60);
       
    PrintText("PROGRAM@AND@GRAPHICS:", 5,140);
    PrintText("SALVAKANTERO", 19, 150);
    PrintText("MUSIC:", 30,165);
	PrintText("BEYKERSOFT", 20,175);
    PrintText("PLAY@ON@RETRO@2023", 15, 190);
}


void StartMenu() {
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
        	PrintText("@@@@@", 29, 100);
    	}
		Pause(3);
	}
	// stop the music
	cpct_akp_musicInit(FX);
	cpct_akp_SFXPlay (6, 14, 41, 0, 0, AY_CHANNEL_B); // event sound
	ClearScreen();
	// in-game music for level 1
	cpct_akp_musicInit(Ingame1);
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
	// reset player position
	spr[0].x = spr[0].px = 50;
	spr[0].y = spr[0].py = 100;
	spr[0].dir = D_right; 
	spr[0].status = S_stopped;
	// print the scoreboard and the game screen
	SetEnemies();
	SetTile(4,6,5);
	PrintMap();
	RefreshScoreboard();
}


// initialization of some variables
void InitGame() {
	StartMenu(); // start menu;
	music = TRUE;
	mapNumber = 0;
	booty = 0;
	treasure = 125;
	spr[0].lives = 9; // 10 lives
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
		PrintText("@@@@@@@@@@@", 18, 102);
		PrintText("@GAME@OVER@", 18, 110);
		PrintText("@@@@@@@@@@@", 18, 118);
		Pause(500);
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
	cpct_setBorder(g_palette[4]); // print border (black)
	cpct_etm_setTileset2x4(g_tileset); // keep in memory the tiles for the maps (4 * 4)		
	InitValues(); // assigns default values ​​that do not vary between games
	InitGame(); // initialization of some variables

	while (1) { // main loop		
		RunStatus(); // call the appropriate function according to the player status  
		SelectFrame(&spr[0]); // we assign the next frame of the animation to the player
		DeleteSprite(&spr[0]);
		spr[0].px = spr[0].x; // save the current X coordinate
		spr[0].py = spr[0].y; // save the current Y coordinate
		PrintSprite(&spr[0]); // prints the player in the new XY position
		
		if (ctMainLoop % 3 == 0) { // move enemies
			EnemyLoop(&spr[1]);
			EnemyLoop(&spr[2]);
			EnemyLoop(&spr[3]);
		}
		if (ctMainLoop % 15 == 0) // reprint scoreboard data
			RefreshScoreboard();	

		cpct_waitVSYNC(); // wait for vertical retrace
		
		if (++ctMainLoop == 255) ctMainLoop = 0;

		// DEBUG INFO								
		//PrintNumber(OnPlatform(), 1, 45, 25, TRUE);	
		//PrintNumber(spr[0].status, 1, 55, 25, TRUE);
		//PrintNumber(spr[0].y, 3, 50, 25, TRUE); 	
	}
}
