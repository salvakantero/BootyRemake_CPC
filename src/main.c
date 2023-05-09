
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
//	0x1621-0xBFFF	Program & stack
//	0x1031-0x1620	Uncompressed map
//	0x0200-0x1030	FX-music
//	0x0100-0x0199	Transparent mask table
//
////////////////////////////////////////////////////////////////////////////////

#include <cpctelera.h>

// gfx
#include "gfx/tiles.h"				// tiles to compose the map (4x4 px)
#include "gfx/font.h"				// letters and numbers (6x8 px)
#include "gfx/hud.h"				// scoreboard background (160x40 px)
#include "gfx/logo.h"				// logo (100x20 px)

// sprites
#include "sprites/player.h"			// 9 frames for the player (16x16 px)
#include "sprites/explosion.h"		// 2 frames for the explosion effect (16x16 px)
#include "sprites/pelusoid.h"		// 2 frames for pelusoid enemy (16x16 px)
#include "sprites/aracnovirus.h"	// 2 frames for aracnovirus enemy (16x16 px)
#include "sprites/infected.h"		// 2 frames for infected enemy (16x16 px)
#include "sprites/objects.h"		// 8 objects (12x16 px)

// compressed game map. 40x38 tiles (160x152 px)
#include "map/mappk0.h"
#include "map/mappk1.h"

#include "sfx/sound.h"				// music and sound effects










////////////////////////////////////////////////////////////////////////////////
//	DEFINITIONS & VARIABLES
////////////////////////////////////////////////////////////////////////////////

#define TRUE 1
#define FALSE 0

#define GLOBAL_MAX_X  80 	// X maximum value for the screen (bytes)
#define GLOBAL_MAX_Y  192	// Y maximun value for the screen (px)

#define FNT_W 4	// width of text characters (bytes)
#define FNT_H 8 // height of text characters (px)

#define SPR_W 8 // sprite width (bytes)
#define SPR_H 16 // sprite height (px)

#define OBJ_W 6 // object width (bytes)
#define OBJ_H 16 // object height (px)

#define N_MAX_OBJ 8 // total number of objects to manage

// 3 different kinds of enemies
#define PELUSOID	1
#define ARACNOVIRUS 2
#define INFECTED 	3

// maps
#define ORIG_MAP_Y 40	// the map starts at position 40 of the vertical coordinates
#define MAP_W 40		// game screen size in tiles (horizontal)
#define MAP_H 38		// game screen size in tiles (vertical)
#define TOTAL_MAPS 3
#define UNPACKED_MAP_INI (u8*)(0x1031) // the music ends at 0x1030
#define UNPACKED_MAP_END (u8*)(0x1620) // the program starts at 0x1621
u8 mapNumber = 0; // current level number

u16 score; 			// player score of the current game
u16 highScore;	 	// maximun score of the entire session
u8 music;			// "TRUE" = plays the music during the game, "FALSE" = only effects
u8 ctMainLoop; 		// main loop iteration counter
u8 ct;				// generic counter

// keyboard/joystick control
cpct_keyID ctlUp;
cpct_keyID ctlDown;
cpct_keyID ctlLeft;
cpct_keyID ctlRight;
cpct_keyID ctlFire;
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
	u8 x, y;	// current sprite coordinates
	u8 px, py;	// previous sprite coordinates
	u8 status;	// current status; stopped, climbing, etc...
	TFrm* frm;	// animation secuence image
	u8 nFrm;	// animation frame number
	u8 dir;		// sprite direction
	u8 lives;	// lives left
	u8 touched;	// touched sprite counter (to animate explosions)
	// player properties
	u8 jump;	// Y variation for jumps
	u8 object;	// current object in use (255 for none)
	// enemy properties
	u8 xMin;	// minimun value X (left limit) 
	u8 xMax;	// maximum value X (right limit)
	u8 yMin;	// minimun value Y (upper limit)
	u8 yMax;	// maximun value Y (lower limit)
	u8 movType;	// movement type (see "enum_mov")	
	u8 ident;	// sprite identifier (1:PELUSOID 2:ARACNOVIRUS 3:INFECTED)
} TSpr;

TSpr spr[4];	// 0) player
				// 1) enemy #1
				// 2) enemy #2
				// 3) enemy #3

// structure with all the data necessary to control the objects
typedef struct {
	u8 x;			// object X coordinate
	u8 y;			// object Y coordinate
	u8 mapNumber;	// the object is on the screen x
	u8 taken;		// the object has been collected 
} TObj; 

TObj obj[N_MAX_OBJ];	// 0) Card
						// 1) Energy
						// 2) Air purifier
						// 3) Diskette
						// 4) Wrench
						// 5) Antimatter
						// 6) First aid kit
						// 7) Ammunition

enum { // sprite direction
	D_up = 0,
	D_down,
	D_left,
	D_right
} enum_dir;

enum { // sprite status
	S_stopped = 0,
	S_walking,
	S_preJump,
	S_jumping,
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

const TFrm frm_player[9] = {  
	{D_right, g_player_0}, // stopped
	{D_right, g_player_1}, // moving, left foot
	{D_right, g_player_2}, // moving, right foot
	{D_right, g_player_3}, // jumping
	{D_right, g_player_4}, // falling
	{D_right, g_player_5}, // shooting
	{D_right, g_player_6}, // stairs
	{D_right, g_player_7}, // stairs, right foot
	{D_right, g_player_8}  // stairs, left foot
};

TFrm* const animWalk[4] = {&frm_player[0], &frm_player[1], &frm_player[0], &frm_player[2]};
TFrm* const animClimb[4] = {&frm_player[6], &frm_player[7], &frm_player[6], &frm_player[8]};

const TFrm frm_pelusoid[2] = {{0, g_pelusoid_0}, {0, g_pelusoid_1}};
const TFrm frm_aracnovirus[2] = {{0, g_aracnovirus_0}, {0, g_aracnovirus_1}};
const TFrm frm_infected[2] = {{0, g_infected_0}, {0, g_infected_1}};

// animation sequences of enemy sprites
TFrm* const anim_pelusoid[2] = {&frm_pelusoid[0], &frm_pelusoid[1]};
TFrm* const anim_aracnovirus[2] = {&frm_aracnovirus[0], &frm_aracnovirus[1]};
TFrm* const anim_infected[2] = {&frm_infected[0], &frm_infected[1]};

// jump control
#define JUMP_STEPS 12
const CPCT_2BITARRAY(g_jumpTable, JUMP_STEPS) = {CPCT_ENCODE2BITS(3, 3, 3, 3),
												 CPCT_ENCODE2BITS(2, 2, 1, 1),
												 CPCT_ENCODE2BITS(1, 0, 0, 0)};

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

// cleans the screen with the specified color (black)
void ClearScreen() {
	cpct_memset(CPCT_VMEM_START, cpct_px2byteM0(1, 1), 16384);
}


// print a number as a text string at XY coordinates
void PrintNumber(u16 num, u8 len, u8 x, u8 y) { 
	u8 txt[6];
	u8 zeros;
	u8 pos = 0;
	u8 nAux;

	Itoa(num, txt, 10);    
	zeros = len - Strlen(txt);
	nAux = txt[pos];

	while(nAux != '\0')	{	
		u8* ptr = cpct_getScreenPtr(CPCT_VMEM_START, (zeros + pos) * FNT_W + x, y);
		cpct_drawSprite(g_font[nAux - 48], ptr, FNT_W, FNT_H);
		nAux = txt[++pos];
	}
}


// prints a character string at XY coordinates
void PrintText(u8 txt[], u8 x, u8 y) {
	u8 pos = 0;
	u8 car = txt[pos];

 	while(car != '\0') { // "@" = space    ";" = -   "?" = !!
		u8* ptr = cpct_getScreenPtr(CPCT_VMEM_START, (pos * FNT_W) + x, y);
		cpct_drawSprite(g_font[car - 48], ptr, FNT_W, FNT_H);
		car = txt[++pos];
	}
}


// print the scoreboard image
void InitScoreboard()
{
	cpct_drawSprite(g_hud_0, cpctm_screenPtr(CPCT_VMEM_START,  0, 0), G_HUD_0_W, G_HUD_0_H);
	cpct_drawSprite(g_hud_1, cpctm_screenPtr(CPCT_VMEM_START, 40, 0), G_HUD_1_W, G_HUD_1_H);
}


// refresh data on scoreboard
void RefreshScoreboard() {
	PrintNumber(score, 5, 21, 0); // current score
	PrintNumber(highScore, 5, 60, 0); // session high score
	PrintNumber(spr[0].lives, 1, 8, 17); // lives left 
}


// print the map corresponding to the current map number 
void PrintMap() {
	cpct_etm_drawTilemap2x4(MAP_W, MAP_H, 
		cpctm_screenPtr(CPCT_VMEM_START, 0, ORIG_MAP_Y), UNPACKED_MAP_INI);
}


// get the map tile number of a certain position XY
u8* GetTilePtr(u8 x, u8 y) {
	return UNPACKED_MAP_INI + (y - ORIG_MAP_Y) / 4 * MAP_W + x / 2;	
}


// returns "TRUE" or "1" if the coordinates are placed on a platform tile
u8 OnPlatform(TSpr *pSpr) __z88dk_fastcall {
	u8* tile = GetTilePtr(pSpr->x + 4, pSpr->y + SPR_H + 1);
	if (*tile == 0)
		return TRUE;	
	return FALSE;
}


// returns "TRUE" or "1" if the player coordinates are placed on a stairs tile
u8 OnStairs() {
	//u8* tile = GetTilePtr(spr[0].x + 4, spr[0].y + SPR_H + 1);
	u8* tile = GetTilePtr(spr[0].x + 4, spr[0].y + SPR_H);
	if (*tile >  47 && *tile <  56)
		return TRUE;
	return FALSE;
}


// returns "TRUE" or "1" if the player coordinates are placed in front of a door tile
u8 FacingDoor(u8 dir) __z88dk_fastcall {
	u8* tile;
	if (dir == D_right)	{
		tile = GetTilePtr(spr[0].x + 7, spr[0].y + SPR_H);
		if (*tile == 58) return TRUE;
	}
	else if (dir == D_left)	{
		tile = GetTilePtr(spr[0].x, spr[0].y + SPR_H);
		if (*tile == 59) return TRUE;
	}
	return FALSE;
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
cpct_keyID RedefineKey(u8 *info) __z88dk_fastcall {
    cpct_keyID key; 
    PrintText(info, 29, 100);  
    key = ReturnKeyPressed();
    Wait4Key(key);
	cpct_akp_SFXPlay (2, 15, 41, 0, 0, AY_CHANNEL_B);    
    return key;    
}










////////////////////////////////////////////////////////////////////////////////
//	OBJECT MANAGEMENT
////////////////////////////////////////////////////////////////////////////////

// prints the object in the XY coordinates passed as parameters
void PrintObject(u8 ident, u8 x, u8 y) {
	cpct_drawSpriteMaskedAlignedTable(g_objects[ident], cpct_getScreenPtr(CPCT_VMEM_START, x, y),
									  OBJ_W, OBJ_H, g_maskTable);
}


// print a map portion at the object's coordinates (to delete it)
void DeleteObject(TObj *pObj) __z88dk_fastcall {
	cpct_etm_drawTileBox2x4(pObj->x / 2, (pObj->y - ORIG_MAP_Y) / 4, 
							4 + (pObj->x & 1),	4 + (pObj->y & 3 ? 1 : 0),	
							MAP_W, cpctm_screenPtr(CPCT_VMEM_START, 0, ORIG_MAP_Y), UNPACKED_MAP_INI);	
}


// Delete the object on the scoreboard by painting a black box over it
void DeleteObjectScoreboard() {
	cpct_drawSolidBox(cpctm_screenPtr(CPCT_VMEM_START, 68, 12), cpct_px2byteM0(1,1), 6, 16);
}


// reprints the objects on the current screen so it is not erased by moving sprites
void ReprintObjects() {
	ct = 0;
	while (ct < N_MAX_OBJ) {
		if (obj[ct].mapNumber == mapNumber && obj[ct].taken == FALSE)
			PrintObject(ct, obj[ct].x, obj[ct].y);
		ct++;
	}
}


// Manage the collection of objects
void CheckObjects() {
	ct = 0;
	Wait4Key(ctlDown);
	while (ct < N_MAX_OBJ) {
		if (obj[ct].mapNumber == mapNumber) { // if the object is on the screen ...
			// if we place ourselves on the object ...
			if (spr[0].x >= obj[ct].x - 3 && spr[0].x <= obj[ct].x + 3 &&	
				spr[0].y >= obj[ct].y - 4 && spr[0].y <= obj[ct].y + 4) {
				if (ct > 5) { // first aid kit					
					if (obj[ct].taken == FALSE) {
						cpct_akp_SFXPlay (6, 12, 41, 0, 0, AY_CHANNEL_A);
						if (ct == 6) spr[0].lives = 9; // first aid kit
						DeleteObject(&obj[ct]); 
						// puts the object as picked up so as not to interact with it again
						obj[ct].taken = TRUE;
					}
				}
				// if it is an object that is kept, if we do not carry the object ...
				else if (spr[0].object != ct) {
					// if we have no object ...
					if (spr[0].object == 255) {	
						cpct_akp_SFXPlay(8, 15, 45, 0, 0, AY_CHANNEL_A);
						spr[0].object = ct;
						obj[ct].taken = TRUE;
						DeleteObject(&obj[ct]); 
						// print the object on the scoreboard
						DeleteObjectScoreboard(); PrintObject(ct, 68, 12); 
					}
				}
				else { // if we have the object
					cpct_akp_SFXPlay(7, 15, 45, 0, 0, AY_CHANNEL_A);
					// print the object on the map and delete it from the scoreboard
					PrintObject(ct, obj[ct].x, obj[ct].y);	
					DeleteObjectScoreboard();
					spr[0].object = 255;
					obj[ct].taken = FALSE;
				}
				// we make the loop end
				ct = N_MAX_OBJ;
			}
		}
		ct++;
	}
}


// assign properties to an object
inline void SetObjectParams(u8 objNum, u8 x, u8 y, u8 mapNum) {
	obj[objNum].x = x; 
	obj[objNum].y = y;
	obj[objNum].mapNumber = mapNum;
}


// reinitialize the object properties
// coordinate calculation: x=(TILED(x)*4)/2  y=(TILED(y)*4)+ORIG_MAP_Y  [ORIG_MAP_Y=40]
void InitObjects() {
	//      	   OBJ  X    Y  MAP
	SetObjectParams(0, 24,  96,   0); // Card
	SetObjectParams(1,  0,   0, 255); // Energy cell
	SetObjectParams(2, 44,  64,   2); // Air purifier
	SetObjectParams(3,  8,  60,   1); // Diskette
	SetObjectParams(4,  0,   0, 255); // Wrench
	SetObjectParams(5,  0,   0, 255); // Antimatter
	SetObjectParams(6, 66, 128,   1); // First aid kit
	SetObjectParams(7, 68,  64,   2); // Ammunition
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


// assign the frame corresponding to the animation sequence of the enemy sprite
void SelectSpriteFrame(TSpr *pSpr) __z88dk_fastcall {
	if (ctMainLoop % ANIM_PAUSE == 0) {
		if (pSpr->ident == PELUSOID)
			pSpr->frm = anim_pelusoid[pSpr->nFrm / ANIM_PAUSE];
		else if (pSpr->ident == ARACNOVIRUS)
			pSpr->frm = anim_aracnovirus[pSpr->nFrm / ANIM_PAUSE];
		else
			pSpr->frm = anim_infected[pSpr->nFrm / ANIM_PAUSE];
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

// next frame of the animation secuence
void AssignFrame(TFrm **anim) __z88dk_fastcall {
	spr[0].frm = anim[spr[0].nFrm / ANIM_PAUSE];
}


// assigns a frame or sequence of frames to each state
void SelectFrame() {
	TFrm* f;
	switch(spr[0].status) {
		case S_stopped:			{spr[0].frm = &frm_player[0]; break;}
		case S_walking:			{AssignFrame(animWalk); break;}	// 0,1,0,2
		case S_climbing:		{AssignFrame(animClimb); break;} // 6,7,6,8
		case S_preJump:			{spr[0].frm = &frm_player[1]; break;}
		case S_jumping:			{spr[0].frm = &frm_player[3]; break;}
		case S_falling:			{spr[0].frm = &frm_player[4]; break;}
		case S_landing:			{spr[0].frm = &frm_player[1]; break;}
	}
	// if the direction has changed, we rotate the sprite
	f = spr[0].frm;
	// makes the turn if a change in the direction of movement has been detected
	if (f->dir != spr[0].dir && spr[0].status != S_climbing) {
		cpct_hflipSpriteM0(SPR_W, SPR_H, f->spr);         
		f->dir = spr[0].dir; // save position to compare with next call
	}
}


void MoveUp() { 
	if (spr[0].y > ORIG_MAP_Y) spr[0].y--;
}


void MoveDown() {
	if (spr[0].y + SPR_H < GLOBAL_MAX_Y) spr[0].y++;
}


void MoveLeft() {
	if (spr[0].x > 0)
		if (!FacingDoor(spr[0].dir)) {
			spr[0].x--;
			spr[0].dir = D_left;
		}
}


void MoveRight() { 
	if (spr[0].x + SPR_W < GLOBAL_MAX_X)
		if (!FacingDoor(spr[0].dir)) {
			spr[0].x++;
			spr[0].dir = D_right;
		}
}


// Prepare the movement to the left. or right
void WalkIn(u8 dir) __z88dk_fastcall {
	spr[0].nFrm = 0;
	spr[0].status = S_walking;
	spr[0].dir = dir;
}


// prepare the move up or down
void ClimbIn() {
	spr[0].nFrm = 0;
	spr[0].status = S_climbing;
}


// prepare the jump
void PreJumpIn() {
	spr[0].nFrm = 0;
	spr[0].status = S_preJump;
}


// comes from jumping, starts falling
void FallIn() {
	spr[0].status = S_falling;
	spr[0].jump  = JUMP_STEPS - 3;
}


// comes from jumping, next to touch the ground
void LandIn() {
	spr[0].nFrm = 0;
	spr[0].status = S_landing;
}


// falling, movement is allowed in the meantime
void Falling() {
	cpct_scanKeyboard_f(); // check the pressed keys
	
	if(cpct_isKeyPressed(ctlDown)) CheckObjects();
	else if (cpct_isKeyPressed(ctlLeft)) MoveLeft();
	else if (cpct_isKeyPressed(ctlRight)) MoveRight();
	
	// fall rate using g_jumpTable
	spr[0].y += cpct_get2Bits(g_jumpTable, spr[0].jump);	
	if (spr[0].jump > 1) spr[0].jump--;

	if (OnPlatform(&spr[0]) || OnStairs()) { // if the player is on a platform ...
		while ((spr[0].y + 1) % 4 != 0) spr[0].y--; // adjust to the ground			
		LandIn(); // prepare the landing
	}
}


// will change the status to stopped
void StopIn() {
	spr[0].status = S_stopped;
}


// stands still
void Stopped() {
	cpct_scanKeyboard_f(); // check the pressed keys
	if(cpct_isKeyPressed(ctlUp)) {
		if(OnStairs()) ClimbIn(); // going to climb a ladder
		//else PreJumpIn(); // going to jump
	}
	else if(cpct_isKeyPressed(ctlDown)) {
		if(OnStairs()) ClimbIn(); // going down a ladder
		else CheckObjects(); // going to grab / drop an object (if it is on an object)
	}
	else if(cpct_isKeyPressed(ctlLeft)) WalkIn(D_left);
	else if(cpct_isKeyPressed(ctlRight)) WalkIn(D_right);
	// leave the game
	else if(cpct_isKeyPressed(ctlAbort)) {
		spr[0].lives = 0; 
		ExplodePlayer();
		ExplodeEnemies();
		GameOver();
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


// prepare the jump
void JumpIn() {
	spr[0].status = S_jumping;
	spr[0].jump  = 0;
	cpct_akp_SFXPlay(3, 15, 32, 0, 0, AY_CHANNEL_C);
}


void Jumping() {
	cpct_scanKeyboard_f(); // check the pressed keys
	if(!cpct_isKeyPressed(ctlUp)) FallIn();
	else {
		if(cpct_isKeyPressed(ctlDown)) CheckObjects();
		else if (cpct_isKeyPressed(ctlLeft)) MoveLeft();
		else if (cpct_isKeyPressed(ctlRight)) MoveRight();
	}
	// up using the table g_jumpTable
	spr[0].y -= cpct_get2Bits(g_jumpTable, spr[0].jump);
	// if it hits the ceiling it stops rising
	if (spr[0].y < ORIG_MAP_Y) spr[0].y = ORIG_MAP_Y;
	// if it reaches the top of the rise prepare the descent
	if (++spr[0].jump == JUMP_STEPS)	FallIn();
}


void PreJump() {
	cpct_scanKeyboard_f(); // check the pressed keys
	if(cpct_isKeyPressed(ctlUp)) JumpIn();
	else StopIn();	
}


// assign the frame corresponding to the player animation sequence
void WalkAnim(u8 dir) __z88dk_fastcall {
	spr[0].dir  = dir;
	if(++spr[0].nFrm == 4 * ANIM_PAUSE) spr[0].nFrm = 0;
}


void Walking() {
	cpct_scanKeyboard_f(); // check the pressed keys
	if (cpct_isKeyPressed(ctlUp)) {
		if (OnStairs()) ClimbIn(); // going to climb a ladder
		//else PreJumpIn(); // going to jump
	}
	else if (cpct_isKeyPressed(ctlDown)) {
		if (OnStairs()) ClimbIn(); // going down a ladder
		else CheckObjects(); // going to grab / drop an object (if it is on an object)
	}
	else if (cpct_isKeyPressed(ctlLeft)) {MoveLeft(); WalkAnim(D_left);}
	else if (cpct_isKeyPressed(ctlRight)) {MoveRight(); WalkAnim(D_right);}
	else StopIn();

	if (!OnPlatform(&spr[0])) // if it is not on a platform, it is also falling
		FallIn();
}


void Climbing() {
	cpct_scanKeyboard_f(); // check the pressed keys
	if(cpct_isKeyPressed(ctlUp)) {
		if(OnStairs()) {MoveUp(); WalkAnim(D_right);} 
	}
	else if(cpct_isKeyPressed(ctlDown))	{
		if(OnStairs()) {MoveDown(); WalkAnim(D_right);}
	}
	else if(cpct_isKeyPressed(ctlLeft)) {
	 	if(OnStairs()) {MoveLeft(); WalkAnim(D_left);} 
	 	else spr[0].status = S_walking;
	}
	else if(cpct_isKeyPressed(ctlRight)) {
	 	if(OnStairs()) {MoveRight(); WalkAnim(D_right);} 
	 	else spr[0].status = S_walking;
	}
}


// call the appropriate function based on the status of the main sprite
void RunStatus() {
	switch(spr[0].status) {
		case S_stopped:       	Stopped();			break;
		case S_walking:      	Walking();			break;
		case S_climbing:    	Climbing();			break;
		//case S_preJump:   	PreJump();			break;
		//case S_jumping:     	Jumping();			break;
		case S_falling:      	Falling();			break;
		case S_landing:  		StopIn();
	}
}


// Eliminate the player with an explosion
void ExplodePlayer() {
	// To visualize the crash, it shows explosions with pauses
	cpct_akp_SFXPlay (4, 15, 40, 0, 0, AY_CHANNEL_A); // explosion
	PrintExplosion(&spr[0], 0); Pause(20);
	PrintExplosion(&spr[0], 1); Pause(20);
	PrintExplosion(&spr[0], 0); Pause(20);
	DeleteSprite(&spr[0]);
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
// coordinate calculation: x=TILED(x)*4/2  y=(TILED(y)*4)+ORIG_MAP_Y  [ORIG_MAP_Y=40]
// for "linear" movements, the higher the SPEED value, the higher speed
// for "chaser" movements, the lower the SPEED value, the higher the speed
// to avoid flickering assigning enemies 2 and 3 to those with the highest Y and putting a minimum Y
// enemies 2 and 3 are processed in each iteration of the loop (fast)
void SetEnemies() {
	switch(mapNumber) {
		case 0: { // upper left deck upper floor #3
			//        	  SPR IDENTITY   	MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, ARACNOVIRUS, 	M_linear_Y, 	2,  D_right, 48,  64,   48,   64,   48,  160);
			SetEnemyParams(2, INFECTED, 	M_linear_X, 	3,  D_right, 16, 160,    8,  160,   64,  160);
			SetEnemyParams(3, ARACNOVIRUS,	M_linear_X,		0,  D_right,  0,   0,    0,    0,    0,    0);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk0_end);
			break;
		}
		case 1: { // upper left deck upper floor #2
			//        	  SPR IDENTITY   	MOVEMENT    LIVES 	DIR       X    Y  XMin  YMin  XMax  YMax
			SetEnemyParams(1, PELUSOID,		M_linear_X, 	3,	D_right,  8,  52,    8,   52,   64,  160);
			SetEnemyParams(2, PELUSOID, 	M_linear_Y, 	3,	D_right, 32,  52,   32,   52,   32,  160);		
			SetEnemyParams(3, PELUSOID, 	M_linear_X,		0,	D_right,  0,   0,    0,    0,    0,    0);
			// unzip the map
			cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk1_end);
			break;		
		}
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
	if (pSpr->lives >= 1) // If the enemy sprite is alive
	{
		// update the XY coordinates of the sprite
		if (pSpr->touched == 0) 
			MoveEnemy(pSpr);
		// select the animation frame and apply it
		SelectSpriteFrame(pSpr); 
		EnemyWalkAnim(pSpr);
		// delete the sprite from the previous position and paint in the current one
		DeleteSprite(pSpr);
		pSpr->px = pSpr->x; // save the current X coordinate
		pSpr->py = pSpr->y; // save the current Y coordinate
		PrintSprite(pSpr);
		// check if any collision has occurred
		CheckEnemyCollision(pSpr);
		// enemy hit, it will explode ..
		if (pSpr->touched > 0) 
			ExplosionSecuence(pSpr);
	}
	else if (pSpr->touched > 0) // enemy reached in his last life, will explode
	{
		ExplosionSecuence(pSpr);
	}
	else if (pSpr->status == S_touched) // at this point it has died and exploded
	{
		pSpr->status = S_walking;		
		DeleteSprite(pSpr); 
	}	
	// pausa compensatoria si el enemigo no está en pantalla
	//else if (pSpr->lives == 0) 
	//	Pause(20);
}


// Eliminate all enemies on the screen with an explosion
void ExplodeEnemies()
{
	for (ct = 1; ct < 4; ct++)
		if (spr[ct].lives > 0)
		{
			cpct_akp_SFXPlay (4, 15, 40, 0, 0, AY_CHANNEL_A); // explosion
			PrintExplosion(&spr[ct], 0); Pause(20);
			PrintExplosion(&spr[ct], 1); Pause(20);
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

    PrintText("1@START@GAME", 2, 45);
    PrintText("2@REDEFINE@CONTROLS", 2, 60);
       
    PrintText("SALVAKANTERO", 16,140);
    PrintText("FELIPE@VAKAPP", 14, 155);
    PrintText("TACHA", 29,170);

    PrintText("PLAY@ON@RETRO@2023", 4, 191);
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
			ctlFire = 	RedefineKey("@FIRE");
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
	// default key mapping
	ctlUp = Key_Q;
	ctlDown = Key_A;
	ctlLeft = Key_O;
	ctlRight = Key_P;
	ctlFire = Key_Space;
	ctlAbort = Key_X;
	ctlMusic = Key_M;
	ctlPause = Key_H;	
}


// common values ​​for InitGame() and GameOver() functions
void ResetData() {
	// reset player position
	spr[0].x = spr[0].px = 0;
	spr[0].y = spr[0].py = 159;
	spr[0].dir = D_right; 
	spr[0].status = S_stopped;
	// print the scoreboard and the game screen
	SetEnemies();
	PrintMap();
	RefreshScoreboard();
}


// initialization of some variables
void InitGame() {
	StartMenu(); // start menu;
	music = TRUE;
	mapNumber = 0;
	score = 0;
	
	// data for the player
	spr[0].object = 255; // no object
	spr[0].lives = 9; // 10 lives
	// print the scoreboard background
	InitScoreboard();
	// create objects
	InitObjects();
	// other data to start
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


void main(void) 
{
	cpct_disableFirmware(); // disable firmware control
	cpct_akp_SFXInit(FX); //initialize sound effects
	cpct_setInterruptHandler(Interrupt); // initialize the interrupt manager (keyboard and sound)
	cpct_setVideoMode(0); // activate mode 0; 160*200 16 colors
	cpct_setPalette(g_palette, 16); // assign palette
	cpct_setBorder(g_palette[1]); // print border (black)
	cpct_etm_setTileset2x4(g_tileset); // keep in memory the tiles for the maps (4 * 4)		
	InitValues(); // assigns default values ​​that do not vary between games
	InitGame(); // initialization of some variables

	while (1) { // main loop		
		// reprint objects, to prevent them from being deleted by sprites
		ReprintObjects();
		
		RunStatus(); // call the appropriate function according to the player status  
		SelectFrame(); // we assign the next frame of the animation to the player
		DeleteSprite(&spr[0]);
		spr[0].px = spr[0].x; // save the current X coordinate
		spr[0].py = spr[0].y; // save the current Y coordinate
		PrintSprite(&spr[0]); // prints the player in the new XY position

		//EnemyLoop(&spr[1]);
		//EnemyLoop(&spr[2]);
		//EnemyLoop(&spr[3]);

		if (ctMainLoop % 15 == 0) // reprint scoreboard data
			RefreshScoreboard();	

		cpct_waitVSYNC(); // wait for vertical retrace
		
		if (++ctMainLoop == 255) ctMainLoop = 0;

		// DEBUG INFO								
		//PrintNumber(OnPlatform(&spr[0]), 1, 45, 25);	
		//PrintNumber(spr[0].y, 3, 50, 25); 	
	}
}
