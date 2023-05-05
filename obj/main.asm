;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.6.8 #9946 (CYGWIN)
;--------------------------------------------------------
	.module main
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _MainLoop
	.globl _InitGame
	.globl _ResetData
	.globl _InitValues
	.globl _StartMenu
	.globl _PrintStartMenu
	.globl _CheckLCCollisions
	.globl _InitLC
	.globl _SetLC
	.globl _EnemyLoop
	.globl _ExplosionSecuence
	.globl _SetEnemyParams
	.globl _MoveEnemy
	.globl _MoveShot
	.globl _PrintShot
	.globl _RunStatus
	.globl _Climbing
	.globl _Walking
	.globl _WalkAnim
	.globl _PreJump
	.globl _Jumping
	.globl _JumpIn
	.globl _Stopped
	.globl _StopIn
	.globl _Falling
	.globl _PreShotIn
	.globl _LandIn
	.globl _FallIn
	.globl _PreJumpIn
	.globl _ClimbIn
	.globl _WalkIn
	.globl _MoveRight
	.globl _MoveLeft
	.globl _MoveDown
	.globl _MoveUp
	.globl _SelectFrame
	.globl _AssignFrame
	.globl _CheckEnemyCollision
	.globl _EnemyWalkAnim
	.globl _SelectSpriteFrame
	.globl _PrintExplosion
	.globl _DeleteSprite
	.globl _PrintSprite
	.globl _InitObjects
	.globl _CheckObjects
	.globl _ReprintObjects
	.globl _DeleteObjectScoreboard
	.globl _DeleteObject
	.globl _PrintObject
	.globl _RedefineKey
	.globl _Wait4Key
	.globl _ReturnKeyPressed
	.globl _FacingWall
	.globl _OverMines
	.globl _OnStairs
	.globl _OnPlatform
	.globl _GetTilePtr
	.globl _MoveLeftMap
	.globl _MoveRightMap
	.globl _InitMap
	.globl _PrintMap
	.globl _RefreshScoreboard
	.globl _InitScoreboard
	.globl _PrintText
	.globl _PrintNumber
	.globl _ClearScreen
	.globl _Interrupt
	.globl _PlayMusic
	.globl _Pause
	.globl _Itoa
	.globl _Strlen
	.globl _cpct_zx7b_decrunch_s
	.globl _cpct_etm_setTileset2x4
	.globl _cpct_etm_drawTileBox2x4
	.globl _cpct_akp_SFXPlay
	.globl _cpct_akp_SFXInit
	.globl _cpct_akp_musicInit
	.globl _cpct_getScreenPtr
	.globl _cpct_setPALColour
	.globl _cpct_setPalette
	.globl _cpct_waitVSYNC
	.globl _cpct_setVideoMode
	.globl _cpct_drawSpriteMaskedAlignedTable
	.globl _cpct_drawSprite
	.globl _cpct_drawSolidBox
	.globl _cpct_px2byteM0
	.globl _cpct_hflipSpriteM0
	.globl _cpct_get2Bits
	.globl _cpct_isAnyKeyPressed
	.globl _cpct_isKeyPressed
	.globl _cpct_scanKeyboard_if
	.globl _cpct_scanKeyboard_f
	.globl _cpct_scanKeyboard
	.globl _cpct_memset
	.globl _cpct_setInterruptHandler
	.globl _cpct_disableFirmware
	.globl _mapNumber
	.globl _enum_mov
	.globl _enum_sta
	.globl _enum_dir
	.globl _obj
	.globl _lc
	.globl _activeLC
	.globl _shotLC
	.globl _shot
	.globl _spr
	.globl _ctlPause
	.globl _ctlAbort
	.globl _ctlMusic
	.globl _ctlFire
	.globl _ctlRight
	.globl _ctlLeft
	.globl _ctlDown
	.globl _ctlUp
	.globl _ct
	.globl _ctMainLoop
	.globl _music
	.globl _ammo
	.globl _highScore
	.globl _score
	.globl _g_jumpTable
	.globl _anim_infected
	.globl _anim_aracnovirus
	.globl _anim_pelusoid
	.globl _frm_infected
	.globl _frm_aracnovirus
	.globl _frm_pelusoid
	.globl _animClimb
	.globl _animWalk
	.globl _frm_player
	.globl _mapTitle
	.globl _ExplodePlayer
	.globl _DeleteShot
	.globl _SetEnemies
	.globl _ExplodeEnemies
	.globl _GetLC
	.globl _GameOver
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
_score::
	.ds 2
_highScore::
	.ds 2
_ammo::
	.ds 1
_music::
	.ds 1
_ctMainLoop::
	.ds 1
_ct::
	.ds 1
_ctlUp::
	.ds 2
_ctlDown::
	.ds 2
_ctlLeft::
	.ds 2
_ctlRight::
	.ds 2
_ctlFire::
	.ds 2
_ctlMusic::
	.ds 2
_ctlAbort::
	.ds 2
_ctlPause::
	.ds 2
_spr::
	.ds 76
_shot::
	.ds 6
_shotLC::
	.ds 6
_activeLC::
	.ds 1
_lc::
	.ds 15
_obj::
	.ds 40
_enum_dir::
	.ds 1
_enum_sta::
	.ds 1
_enum_mov::
	.ds 1
_Interrupt_nInt_1_143:
	.ds 1
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
_mapNumber::
	.ds 1
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area _DABS (ABS)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area _HOME
	.area _GSINIT
	.area _GSFINAL
	.area _GSINIT
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area _HOME
	.area _HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area _CODE
;src/main.c:258: cpctm_createTransparentMaskTable(g_maskTable, 0x100, M0, 0);
;	---------------------------------
; Function dummy_cpct_transparentMaskTable0M0_container
; ---------------------------------
_dummy_cpct_transparentMaskTable0M0_container::
	.area _g_maskTable_ (ABS) 
	.org 0x100 
	 _g_maskTable::
	.db 0xFF, 0xAA, 0x55, 0x00, 0xAA, 0xAA, 0x00, 0x00 
	.db 0x55, 0x00, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00 
	.db 0xAA, 0xAA, 0x00, 0x00, 0xAA, 0xAA, 0x00, 0x00 
	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
	.db 0x55, 0x00, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00 
	.db 0x55, 0x00, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00 
	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
	.db 0xAA, 0xAA, 0x00, 0x00, 0xAA, 0xAA, 0x00, 0x00 
	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
	.db 0xAA, 0xAA, 0x00, 0x00, 0xAA, 0xAA, 0x00, 0x00 
	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
	.db 0x55, 0x00, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00 
	.db 0x55, 0x00, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00 
	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
	.db 0x55, 0x00, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00 
	.db 0x55, 0x00, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00 
	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
	.area _CSEG (REL, CON) 
;src/main.c:293: u8 Strlen(const u8 *str) __z88dk_fastcall {
;	---------------------------------
; Function Strlen
; ---------------------------------
_Strlen::
;src/main.c:295: for (s = str; *s; ++s);
	ld	c,l
	ld	b,h
00103$:
	ld	a, (hl)
	or	a, a
	jr	Z,00101$
	inc	hl
	jr	00103$
00101$:
;src/main.c:296: return (s - str);
	cp	a, a
	sbc	hl, bc
	ret
_mapTitle:
	.dw __str_0
	.dw __str_1
	.dw __str_2
_frm_player:
	.db #0x03	; 3
	.dw _g_player_0
	.db #0x03	; 3
	.dw _g_player_1
	.db #0x03	; 3
	.dw _g_player_2
	.db #0x03	; 3
	.dw _g_player_3
	.db #0x03	; 3
	.dw _g_player_4
	.db #0x03	; 3
	.dw _g_player_5
	.db #0x03	; 3
	.dw _g_player_6
	.db #0x03	; 3
	.dw _g_player_7
	.db #0x03	; 3
	.dw _g_player_8
_animWalk:
	.dw (_frm_player + 0)
	.dw (_frm_player + 3)
	.dw (_frm_player + 0)
	.dw (_frm_player + 6)
_animClimb:
	.dw (_frm_player + 18)
	.dw (_frm_player + 21)
	.dw (_frm_player + 18)
	.dw (_frm_player + 24)
_frm_pelusoid:
	.db #0x00	; 0
	.dw _g_pelusoid_0
	.db #0x00	; 0
	.dw _g_pelusoid_1
_frm_aracnovirus:
	.db #0x00	; 0
	.dw _g_aracnovirus_0
	.db #0x00	; 0
	.dw _g_aracnovirus_1
_frm_infected:
	.db #0x00	; 0
	.dw _g_infected_0
	.db #0x00	; 0
	.dw _g_infected_1
_anim_pelusoid:
	.dw (_frm_pelusoid + 0)
	.dw (_frm_pelusoid + 3)
_anim_aracnovirus:
	.dw (_frm_aracnovirus + 0)
	.dw (_frm_aracnovirus + 3)
_anim_infected:
	.dw (_frm_infected + 0)
	.dw (_frm_infected + 3)
_g_jumpTable:
	.db #0xff	; 255
	.db #0xa5	; 165
	.db #0x40	; 64
__str_0:
	.ascii "@@UPPER@LEFT@DECK@C@"
	.db 0x00
__str_1:
	.ascii "@@UPPER@LEFT@DECK@B@"
	.db 0x00
__str_2:
	.ascii "@@UPPER@LEFT@DECK@A@"
	.db 0x00
;src/main.c:301: char* Itoa(u16 value, char* result, int base) {    
;	---------------------------------
; Function Itoa
; ---------------------------------
_Itoa::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl, #-7
	add	hl, sp
	ld	sp, hl
;src/main.c:303: char* ptr = result, *ptr1 = result, tmp_char;
	ld	e,6 (ix)
	ld	d,7 (ix)
	ld	-6 (ix), e
	ld	-5 (ix), d
;src/main.c:305: if (base < 2 || base > 36) { 
	ld	a, 8 (ix)
	sub	a, #0x02
	ld	a, 9 (ix)
	rla
	ccf
	rra
	sbc	a, #0x80
	jr	C,00101$
	ld	a, #0x24
	cp	a, 8 (ix)
	ld	a, #0x00
	sbc	a, 9 (ix)
	jp	PO, 00140$
	xor	a, #0x80
00140$:
	jp	P, 00115$
00101$:
;src/main.c:306: *result = '\0'; 
	xor	a, a
	ld	(de), a
;src/main.c:307: return result; 
	ex	de,hl
	jp	00112$
;src/main.c:310: do {
00115$:
	ld	-2 (ix), e
	ld	-1 (ix), d
00104$:
;src/main.c:311: tmp_value = value;
	ld	a, 4 (ix)
	ld	-4 (ix), a
	ld	a, 5 (ix)
	ld	-3 (ix), a
;src/main.c:312: value /= base;
	ld	c,8 (ix)
	ld	b,9 (ix)
	push	bc
	ld	l,4 (ix)
	ld	h,5 (ix)
	push	hl
	call	__divuint
	pop	af
	pop	af
	ld	4 (ix), l
	ld	5 (ix), h
;src/main.c:313: *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
	ld	c, -4 (ix)
	ld	e, 4 (ix)
	ld	h, 8 (ix)
	ld	l, #0x00
	ld	d, l
	ld	b, #0x08
00141$:
	add	hl, hl
	jr	NC,00142$
	add	hl, de
00142$:
	djnz	00141$
	ld	a, c
	sub	a, l
	add	a, #0x23
	ld	c, a
	rla
	sbc	a, a
	ld	b, a
	ld	hl, #___str_3
	add	hl, bc
	ld	c, (hl)
	ld	l,-2 (ix)
	ld	h,-1 (ix)
	ld	(hl), c
	inc	-2 (ix)
	jr	NZ,00143$
	inc	-1 (ix)
00143$:
;src/main.c:314: } while (value);
	ld	a, 5 (ix)
	or	a,4 (ix)
	jr	NZ,00104$
;src/main.c:316: if (tmp_value < 0) 
	ld	c,-2 (ix)
	ld	b,-1 (ix)
	bit	7, -3 (ix)
	jr	Z,00108$
;src/main.c:317: *ptr++ = '-';
	ld	l,-2 (ix)
	ld	h,-1 (ix)
	ld	(hl), #0x2d
	ld	c,-2 (ix)
	ld	b,-1 (ix)
	inc	bc
00108$:
;src/main.c:318: *ptr-- = '\0';
	xor	a, a
	ld	(bc), a
	dec	bc
;src/main.c:320: while(ptr1 < ptr) {
	ld	e,-6 (ix)
	ld	d,-5 (ix)
00109$:
	ld	a, e
	sub	a, c
	ld	a, d
	sbc	a, b
	jr	NC,00111$
;src/main.c:321: tmp_char = *ptr;
	ld	a, (bc)
	ld	-7 (ix), a
;src/main.c:322: *ptr--= *ptr1;
	ld	a, (de)
	ld	(bc), a
	dec	bc
;src/main.c:323: *ptr1++ = tmp_char;
	ld	a, -7 (ix)
	ld	(de), a
	inc	de
	jr	00109$
00111$:
;src/main.c:326: return result;
	ld	l,6 (ix)
	ld	h,7 (ix)
00112$:
	ld	sp, ix
	pop	ix
	ret
___str_3:
	.ascii "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmno"
	.ascii "pqrstuvwxyz"
	.db 0x00
;src/main.c:331: void Pause(u16 value) __z88dk_fastcall {
;	---------------------------------
; Function Pause
; ---------------------------------
_Pause::
;src/main.c:333: for(i = 0; i < value; i++) {
	ld	bc, #0x0000
00103$:
	ld	a, c
	sub	a, l
	ld	a, b
	sbc	a, h
	ret	NC
;src/main.c:336: __endasm;
	halt
;src/main.c:333: for(i = 0; i < value; i++) {
	inc	bc
	jr	00103$
;src/main.c:342: void PlayMusic() {
;	---------------------------------
; Function PlayMusic
; ---------------------------------
_PlayMusic::
;src/main.c:357: __endasm;
	exx
	.db	#0x08
	push	af
	push	bc
	push	de
	push	hl
	call	_cpct_akp_musicPlay
	pop	hl
	pop	de
	pop	bc
	pop	af
	.db	#0x08
	exx
	ret
;src/main.c:362: void Interrupt() {
;	---------------------------------
; Function Interrupt
; ---------------------------------
_Interrupt::
;src/main.c:365: if (++nInt == 5) {
	ld	iy, #_Interrupt_nInt_1_143
	inc	0 (iy)
	ld	a, 0 (iy)
	sub	a, #0x05
	ret	NZ
;src/main.c:366: PlayMusic();
	call	_PlayMusic
;src/main.c:367: cpct_scanKeyboard_if();
	call	_cpct_scanKeyboard_if
;src/main.c:368: nInt = 0;
	ld	hl,#_Interrupt_nInt_1_143 + 0
	ld	(hl), #0x00
	ret
;src/main.c:386: void ClearScreen() {
;	---------------------------------
; Function ClearScreen
; ---------------------------------
_ClearScreen::
;src/main.c:387: cpct_memset(CPCT_VMEM_START, cpct_px2byteM0(1, 1), 16384);
	ld	hl, #0x0101
	push	hl
	call	_cpct_px2byteM0
	ld	b, l
	ld	hl, #0x4000
	push	hl
	push	bc
	inc	sp
	ld	h, #0xc0
	push	hl
	call	_cpct_memset
	ret
;src/main.c:392: void PrintNumber(u16 num, u8 len, u8 x, u8 y) { 
;	---------------------------------
; Function PrintNumber
; ---------------------------------
_PrintNumber::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl, #-8
	add	hl, sp
;src/main.c:398: Itoa(num, txt, 10);    
	ld	sp, hl
	inc	hl
	inc	hl
	ld	c, l
	ld	b, h
	ld	e, c
	ld	d, b
	push	bc
	ld	hl, #0x000a
	push	hl
	push	de
	ld	l,4 (ix)
	ld	h,5 (ix)
	push	hl
	call	_Itoa
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
	pop	bc
;src/main.c:399: zeros = len - Strlen(txt);
	ld	l, c
	ld	h, b
	push	bc
	call	_Strlen
	pop	bc
	ld	a, 6 (ix)
	sub	a, l
	ld	-7 (ix), a
;src/main.c:400: nAux = txt[pos];
	ld	a, (bc)
	ld	e, a
;src/main.c:402: while(nAux != '\0')	{	
	ld	-8 (ix), #0x00
00101$:
	ld	a, e
	or	a, a
	jr	Z,00104$
;src/main.c:403: u8* ptr = cpct_getScreenPtr(CPCT_VMEM_START, (zeros + pos) * FNT_W + x, y);
	ld	a, -7 (ix)
	add	a, -8 (ix)
	add	a, a
	add	a, a
	add	a, 7 (ix)
	ld	d, a
	push	bc
	push	de
	ld	a, 8 (ix)
	push	af
	inc	sp
	push	de
	inc	sp
	ld	hl, #0xc000
	push	hl
	call	_cpct_getScreenPtr
	pop	de
	pop	bc
;src/main.c:404: cpct_drawSprite(g_font[nAux - 48], ptr, FNT_W, FNT_H);
	push	hl
	pop	iy
	ld	d, #0x00
	ld	a, e
	add	a, #0xd0
	ld	l, a
	ld	a, d
	adc	a, #0xff
	ld	h, a
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	ld	de, #_g_font
	add	hl, de
	push	bc
	ld	de, #0x0804
	push	de
	push	iy
	push	hl
	call	_cpct_drawSprite
	pop	bc
;src/main.c:405: nAux = txt[++pos];
	inc	-8 (ix)
	ld	l,-8 (ix)
	ld	h,#0x00
	add	hl, bc
	ld	e, (hl)
	jr	00101$
00104$:
	ld	sp, ix
	pop	ix
	ret
;src/main.c:411: void PrintText(u8 txt[], u8 x, u8 y) {
;	---------------------------------
; Function PrintText
; ---------------------------------
_PrintText::
	push	ix
	ld	ix,#0
	add	ix,sp
	dec	sp
;src/main.c:413: u8 car = txt[pos];
	ld	c,4 (ix)
	ld	b,5 (ix)
	ld	a, (bc)
	ld	e, a
;src/main.c:415: while(car != '\0') { // "@" = space    ";" = -   "?" = !!
	ld	-1 (ix), #0x00
00101$:
	ld	a, e
	or	a, a
	jr	Z,00104$
;src/main.c:416: u8* ptr = cpct_getScreenPtr(CPCT_VMEM_START, (pos * FNT_W) + x, y);
	ld	a, -1 (ix)
	add	a, a
	add	a, a
	add	a, 6 (ix)
	ld	d, a
	push	bc
	push	de
	ld	a, 7 (ix)
	push	af
	inc	sp
	push	de
	inc	sp
	ld	hl, #0xc000
	push	hl
	call	_cpct_getScreenPtr
	pop	de
	pop	bc
;src/main.c:417: cpct_drawSprite(g_font[car - 48], ptr, FNT_W, FNT_H);
	push	hl
	pop	iy
	ld	d, #0x00
	ld	a, e
	add	a, #0xd0
	ld	l, a
	ld	a, d
	adc	a, #0xff
	ld	h, a
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	ld	de, #_g_font
	add	hl, de
	push	bc
	ld	de, #0x0804
	push	de
	push	iy
	push	hl
	call	_cpct_drawSprite
	pop	bc
;src/main.c:418: car = txt[++pos];
	inc	-1 (ix)
	ld	l,-1 (ix)
	ld	h,#0x00
	add	hl, bc
	ld	e, (hl)
	jr	00101$
00104$:
	inc	sp
	pop	ix
	ret
;src/main.c:424: void InitScoreboard()
;	---------------------------------
; Function InitScoreboard
; ---------------------------------
_InitScoreboard::
;src/main.c:426: cpct_drawSprite(g_hud_0, cpctm_screenPtr(CPCT_VMEM_START,  0, 0), G_HUD_0_W, G_HUD_0_H);
	ld	hl, #0x2828
	push	hl
	ld	hl, #0xc000
	push	hl
	ld	hl, #_g_hud_0
	push	hl
	call	_cpct_drawSprite
;src/main.c:427: cpct_drawSprite(g_hud_1, cpctm_screenPtr(CPCT_VMEM_START, 40, 0), G_HUD_1_W, G_HUD_1_H);
	ld	hl, #0x2828
	push	hl
	ld	h, #0xc0
	push	hl
	ld	hl, #_g_hud_1
	push	hl
	call	_cpct_drawSprite
	ret
;src/main.c:432: void RefreshScoreboard() {
;	---------------------------------
; Function RefreshScoreboard
; ---------------------------------
_RefreshScoreboard::
;src/main.c:433: PrintNumber(score, 5, 21, 0); // current score
	ld	hl, #0x0015
	push	hl
	ld	a, #0x05
	push	af
	inc	sp
	ld	hl, (_score)
	push	hl
	call	_PrintNumber
	pop	af
;src/main.c:434: PrintNumber(highScore, 5, 60, 0); // session high score
	inc	sp
	ld	hl,#0x003c
	ex	(sp),hl
	ld	a, #0x05
	push	af
	inc	sp
	ld	hl, (_highScore)
	push	hl
	call	_PrintNumber
	pop	af
	pop	af
	inc	sp
;src/main.c:435: PrintNumber(spr[0].lives, 1, 8, 17); // lives left 
	ld	hl, #_spr+9
	ld	c, (hl)
	ld	b, #0x00
	ld	hl, #0x1108
	push	hl
	ld	a, #0x01
	push	af
	inc	sp
	push	bc
	call	_PrintNumber
	pop	af
	pop	af
	inc	sp
;src/main.c:436: if (ammo < 10) PrintNumber(0, 1, 25, 17); // zero if ammo < 10
	ld	a,(#_ammo + 0)
	sub	a, #0x0a
	jr	NC,00102$
	ld	hl, #0x1119
	push	hl
	ld	a, #0x01
	push	af
	inc	sp
	ld	hl, #0x0000
	push	hl
	call	_PrintNumber
	pop	af
	pop	af
	inc	sp
00102$:
;src/main.c:437: PrintNumber(ammo, 2, 25, 17); // bullets left
	ld	hl,#_ammo + 0
	ld	c, (hl)
	ld	b, #0x00
	ld	hl, #0x1119
	push	hl
	ld	a, #0x02
	push	af
	inc	sp
	push	bc
	call	_PrintNumber
	pop	af
	pop	af
	inc	sp
	ret
;src/main.c:442: void PrintMap() {
;	---------------------------------
; Function PrintMap
; ---------------------------------
_PrintMap::
;src/main.c:443: cpct_etm_drawTilemap2x4(MAP_W, MAP_H, cpctm_screenPtr(CPCT_VMEM_START, 0, ORIG_MAP_Y), UNPACKED_MAP_INI);
	ld	hl, #0x1031
	push	hl
	ld	hl, #0xc000
	push	hl
	ld	hl, #0x2826
	push	hl
	ld	l, #0x00
	push	hl
	xor	a, a
	push	af
	inc	sp
	call	_cpct_etm_drawTileBox2x4
;src/main.c:445: PrintText(mapTitle[mapNumber], 0, 192);
	ld	bc, #_mapTitle+0
	ld	iy, #_mapNumber
	ld	l, 0 (iy)
	ld	h, #0x00
	add	hl, hl
	add	hl, bc
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	ld	hl, #0xc000
	push	hl
	push	bc
	call	_PrintText
	pop	af
	pop	af
	ret
;src/main.c:450: void InitMap() {
;	---------------------------------
; Function InitMap
; ---------------------------------
_InitMap::
;src/main.c:451: shot.active = FALSE; 
	ld	hl, #(_shot + 0x0005)
	ld	(hl), #0x00
;src/main.c:452: shotLC.active = FALSE; 
	ld	hl, #(_shotLC + 0x0005)
	ld	(hl), #0x00
;src/main.c:453: SetEnemies();
	call	_SetEnemies
;src/main.c:454: GetLC();
	call	_GetLC
;src/main.c:455: PrintMap();
	jp  _PrintMap
;src/main.c:460: void MoveRightMap() {
;	---------------------------------
; Function MoveRightMap
; ---------------------------------
_MoveRightMap::
;src/main.c:461: if (mapNumber < TOTAL_MAPS-1) {
	ld	iy, #_mapNumber
	ld	a, 0 (iy)
	sub	a, #0x02
	ret	NC
;src/main.c:462: mapNumber++;
	inc	0 (iy)
;src/main.c:463: spr[0].x = spr[0].px = 0;
	ld	hl, #(_spr + 0x0002)
	ld	(hl), #0x00
	ld	hl, #_spr
	ld	(hl), #0x00
;src/main.c:464: InitMap();
	jp  _InitMap
;src/main.c:470: void MoveLeftMap() {
;	---------------------------------
; Function MoveLeftMap
; ---------------------------------
_MoveLeftMap::
;src/main.c:471: if (mapNumber > 0) {
	ld	iy, #_mapNumber
	ld	a, 0 (iy)
	or	a, a
	ret	Z
;src/main.c:472: mapNumber--;
	dec	0 (iy)
;src/main.c:473: spr[0].x = spr[0].px = GLOBAL_MAX_X - SPR_W;
	ld	hl, #(_spr + 0x0002)
	ld	(hl), #0x48
	ld	hl, #_spr
	ld	(hl), #0x48
;src/main.c:474: InitMap();
	jp  _InitMap
;src/main.c:480: u8* GetTilePtr(u8 x, u8 y) {
;	---------------------------------
; Function GetTilePtr
; ---------------------------------
_GetTilePtr::
;src/main.c:481: return UNPACKED_MAP_INI + (y - ORIG_MAP_Y) / 4 * MAP_W + x / 2;	
	ld	iy, #3
	add	iy, sp
	ld	l, 0 (iy)
	ld	h, #0x00
	ld	c, l
	ld	e, h
	bit	7, h
	jr	Z,00103$
	inc	hl
	inc	hl
	inc	hl
	ld	c, l
	ld	e, h
00103$:
	ld	b, e
	sra	b
	rr	c
	sra	b
	rr	c
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, hl
	add	hl, hl
	ld	bc, #0x1031
	add	hl, bc
	ld	iy, #2
	add	iy, sp
	ld	c, 0 (iy)
	srl	c
	ld	e,c
	ld	d,#0x00
	add	hl, de
	ret
;src/main.c:486: u8 OnPlatform(TSpr *pSpr) __z88dk_fastcall {
;	---------------------------------
; Function OnPlatform
; ---------------------------------
_OnPlatform::
;src/main.c:487: u8* tile = GetTilePtr(pSpr->x + 4, pSpr->y + SPR_H + 1);
	ld	c,l
	ld	b,h
	inc	hl
	ld	a, (hl)
	add	a, #0x11
	ld	d, a
	ld	a, (bc)
	add	a, #0x04
	ld	e, a
	push	de
	call	_GetTilePtr
	pop	af
;src/main.c:488: if (*tile == 0)
	ld	a, (hl)
	or	a, a
	jr	NZ,00102$
;src/main.c:489: return TRUE;	
	ld	l, #0x01
	ret
00102$:
;src/main.c:490: return FALSE;
	ld	l, #0x00
	ret
;src/main.c:495: u8 OnStairs() {
;	---------------------------------
; Function OnStairs
; ---------------------------------
_OnStairs::
;src/main.c:496: u8* tile = GetTilePtr(spr[0].x + 4, spr[0].y + SPR_H + 1);
	ld	a, (#_spr + 1)
	add	a, #0x11
	ld	b, a
	ld	a, (#_spr + 0)
	add	a, #0x04
	push	bc
	inc	sp
	push	af
	inc	sp
	call	_GetTilePtr
	pop	af
;src/main.c:497: if (*tile >  47 && *tile <  56)
	ld	c, (hl)
	ld	a, #0x2f
	sub	a, c
	jr	NC,00102$
	ld	a, c
	sub	a, #0x38
	jr	NC,00102$
;src/main.c:498: return TRUE;
	ld	l, #0x01
	ret
00102$:
;src/main.c:499: return FALSE;
	ld	l, #0x00
	ret
;src/main.c:504: u8 OverMines() {
;	---------------------------------
; Function OverMines
; ---------------------------------
_OverMines::
;src/main.c:505: u8* tile = GetTilePtr(spr[0].x + 4, spr[0].y + SPR_H);
	ld	a, (#_spr + 1)
	add	a, #0x10
	ld	b, a
	ld	a, (#_spr + 0)
	add	a, #0x04
	push	bc
	inc	sp
	push	af
	inc	sp
	call	_GetTilePtr
	pop	af
;src/main.c:506: if (*tile > 55 && *tile < 58) 
	ld	c, (hl)
	ld	a, #0x37
	sub	a, c
	jr	NC,00102$
	ld	a, c
	sub	a, #0x3a
	jr	NC,00102$
;src/main.c:507: return TRUE;	
	ld	l, #0x01
	ret
00102$:
;src/main.c:508: return FALSE;
	ld	l, #0x00
	ret
;src/main.c:513: u8 FacingWall(u8 dir) __z88dk_fastcall {
;	---------------------------------
; Function FacingWall
; ---------------------------------
_FacingWall::
	ld	c, l
;src/main.c:515: if (dir == D_right)	{
	ld	a, c
	sub	a, #0x03
	jr	NZ,00108$
;src/main.c:516: tile = GetTilePtr(spr[0].x + 7, spr[0].y + SPR_H);
	ld	a, (#_spr + 1)
	add	a, #0x10
	ld	d, a
	ld	a, (#_spr + 0)
	add	a, #0x07
	ld	e,a
	push	de
	call	_GetTilePtr
	pop	af
;src/main.c:517: if (*tile == 58) return TRUE;
	ld	a, (hl)
	sub	a, #0x3a
	jr	NZ,00109$
	ld	l, #0x01
	ret
00108$:
;src/main.c:519: else if (dir == D_left)	{
	ld	a, c
	sub	a, #0x02
	jr	NZ,00109$
;src/main.c:520: tile = GetTilePtr(spr[0].x, spr[0].y + SPR_H);
	ld	a, (#_spr + 1)
	add	a, #0x10
	ld	d, a
	ld	hl, #_spr + 0
	ld	e, (hl)
	push	de
	call	_GetTilePtr
	pop	af
;src/main.c:521: if (*tile == 59) return TRUE;
	ld	a, (hl)
	sub	a, #0x3b
	jr	NZ,00109$
	ld	l, #0x01
	ret
00109$:
;src/main.c:523: return FALSE;
	ld	l, #0x00
	ret
;src/main.c:540: cpct_keyID ReturnKeyPressed() {
;	---------------------------------
; Function ReturnKeyPressed
; ---------------------------------
_ReturnKeyPressed::
	push	ix
	ld	ix,#0
	add	ix,sp
	push	af
	dec	sp
;src/main.c:541: u8 i = 10, *keys = cpct_keyboardStatusBuffer + 9;
	ld	c, #0x0a
;src/main.c:544: do { cpct_scanKeyboard(); } while ( ! cpct_isAnyKeyPressed() );
00101$:
	push	bc
	call	_cpct_scanKeyboard
	call	_cpct_isAnyKeyPressed
	pop	bc
	ld	a, l
	or	a, a
	jr	Z,00101$
;src/main.c:546: do {
	ld	-2 (ix), #<((_cpct_keyboardStatusBuffer + 0x0009))
	ld	-1 (ix), #>((_cpct_keyboardStatusBuffer + 0x0009))
	ld	-3 (ix), #0x0a
00106$:
;src/main.c:547: keypressed = *keys ^ 0xFF;
	ld	l,-2 (ix)
	ld	h,-1 (ix)
	ld	a, (hl)
	xor	a, #0xff
	ld	l, a
	ld	h, #0x00
;src/main.c:548: if (keypressed)
	ld	a, h
	or	a,l
	jr	Z,00105$
;src/main.c:549: return (keypressed << 8) + (i - 1); 
	ld	h, l
	ld	l, #0x00
	ld	b, #0x00
	dec	bc
	add	hl, bc
	jr	00109$
00105$:
;src/main.c:550: keys--;
	ld	a, -2 (ix)
	add	a, #0xff
	ld	-2 (ix), a
	ld	a, -1 (ix)
	adc	a, #0xff
	ld	-1 (ix), a
;src/main.c:551: } while(--i);
	dec	-3 (ix)
	ld	c, -3 (ix)
	ld	a, -3 (ix)
	or	a, a
	jr	NZ,00106$
;src/main.c:552: return keypressed;    
00109$:
	ld	sp, ix
	pop	ix
	ret
;src/main.c:558: void Wait4Key(cpct_keyID key) __z88dk_fastcall {
;	---------------------------------
; Function Wait4Key
; ---------------------------------
_Wait4Key::
;src/main.c:559: do cpct_scanKeyboard_f();
00101$:
	push	hl
	call	_cpct_scanKeyboard_f
	pop	hl
;src/main.c:560: while(!cpct_isKeyPressed(key));
	push	hl
	call	_cpct_isKeyPressed
	ld	a, l
	pop	hl
	or	a, a
	jr	Z,00101$
;src/main.c:561: do cpct_scanKeyboard_f();
00104$:
	push	hl
	call	_cpct_scanKeyboard_f
	pop	hl
;src/main.c:562: while(cpct_isKeyPressed(key));
	push	hl
	call	_cpct_isKeyPressed
	ld	a, l
	pop	hl
	or	a, a
	jr	NZ,00104$
	ret
;src/main.c:567: cpct_keyID RedefineKey(u8 *info) __z88dk_fastcall {
;	---------------------------------
; Function RedefineKey
; ---------------------------------
_RedefineKey::
;src/main.c:569: PrintText(info, 29, 100);  
	ld	bc, #0x641d
	push	bc
	push	hl
	call	_PrintText
	pop	af
	pop	af
;src/main.c:570: key = ReturnKeyPressed();
	call	_ReturnKeyPressed
;src/main.c:571: Wait4Key(key);
	push	hl
	call	_Wait4Key
	ld	a, #0x02
	push	af
	inc	sp
	ld	bc, #0x0000
	push	bc
	ld	bc, #0x0029
	push	bc
	ld	bc, #0x0f02
	push	bc
	call	_cpct_akp_SFXPlay
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
	pop	hl
;src/main.c:573: return key;    
	ret
;src/main.c:590: void PrintObject(u8 ident, u8 x, u8 y) {
;	---------------------------------
; Function PrintObject
; ---------------------------------
_PrintObject::
	push	ix
	ld	ix,#0
	add	ix,sp
;src/main.c:592: OBJ_W, OBJ_H, g_maskTable);
;src/main.c:591: cpct_drawSpriteMaskedAlignedTable(g_objects[ident], cpct_getScreenPtr(CPCT_VMEM_START, x, y),
	ld	h, 6 (ix)
	ld	l, 5 (ix)
	push	hl
	ld	hl, #0xc000
	push	hl
	call	_cpct_getScreenPtr
	ld	c, l
	ld	b, h
	ld	e,4 (ix)
	ld	d,#0x00
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	ld	de, #_g_objects
	add	hl, de
	ld	de, #_g_maskTable
	push	de
	ld	de, #0x1006
	push	de
	push	bc
	push	hl
	call	_cpct_drawSpriteMaskedAlignedTable
	pop	ix
	ret
;src/main.c:597: void DeleteObject(TObj *pObj) __z88dk_fastcall {
;	---------------------------------
; Function DeleteObject
; ---------------------------------
_DeleteObject::
	push	ix
	ld	ix,#0
	add	ix,sp
	dec	sp
;src/main.c:599: 4 + (pObj->x & 1),	4 + (pObj->y & 3 ? 1 : 0),	
	ld	c,l
	ld	b,h
	inc	hl
	ld	e, (hl)
	ld	a, e
	and	a, #0x03
	jr	Z,00103$
	ld	d, #0x01
	jr	00104$
00103$:
	ld	d, #0x00
00104$:
	inc	d
	inc	d
	inc	d
	inc	d
	ld	a, (bc)
	ld	c,a
	and	a, #0x01
	add	a, #0x04
	ld	-1 (ix), a
;src/main.c:598: cpct_etm_drawTileBox2x4(pObj->x / 2, (pObj->y - ORIG_MAP_Y) / 4, 
	ld	b, #0x00
	ld	l, e
	ld	h, b
	bit	7, b
	jr	Z,00105$
	ld	l, e
	ld	h, b
	inc	hl
	inc	hl
	inc	hl
00105$:
	sra	h
	rr	l
	sra	h
	rr	l
	ld	e, l
	srl	c
	ld	hl, #0x1031
	push	hl
	ld	hl, #0xc000
	push	hl
	ld	a, #0x28
	push	af
	inc	sp
	push	de
	inc	sp
	ld	d, -1 (ix)
	push	de
	ld	a, c
	push	af
	inc	sp
	call	_cpct_etm_drawTileBox2x4
	inc	sp
	pop	ix
	ret
;src/main.c:605: void DeleteObjectScoreboard() {
;	---------------------------------
; Function DeleteObjectScoreboard
; ---------------------------------
_DeleteObjectScoreboard::
;src/main.c:606: cpct_drawSolidBox(cpctm_screenPtr(CPCT_VMEM_START, 68, 12), cpct_px2byteM0(1,1), 6, 16);
	ld	hl, #0x0101
	push	hl
	call	_cpct_px2byteM0
	ld	h, #0x00
	ld	bc, #0x1006
	push	bc
	push	hl
	ld	hl, #0xe094
	push	hl
	call	_cpct_drawSolidBox
	ret
;src/main.c:611: void ReprintObjects() {
;	---------------------------------
; Function ReprintObjects
; ---------------------------------
_ReprintObjects::
;src/main.c:612: ct = 0;
	ld	hl,#_ct + 0
	ld	(hl), #0x00
;src/main.c:613: while (ct < N_MAX_OBJ) {
00104$:
	ld	a,(#_ct + 0)
	sub	a, #0x08
	ret	NC
;src/main.c:614: if (obj[ct].mapNumber == mapNumber && obj[ct].taken == FALSE)
	ld	bc, (_ct)
	ld	b, #0x00
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, hl
	add	hl, bc
	ld	bc,#_obj
	add	hl,bc
	ld	c,l
	ld	b,h
	inc	hl
	inc	hl
	ld	e, (hl)
	ld	a,(#_mapNumber + 0)
	sub	a, e
	jr	NZ,00102$
	ld	l, c
	ld	h, b
	inc	hl
	inc	hl
	inc	hl
	ld	a, (hl)
	or	a, a
	jr	NZ,00102$
;src/main.c:615: PrintObject(ct, obj[ct].x, obj[ct].y);
	ld	l, c
	ld	h, b
	inc	hl
	ld	d, (hl)
	ld	a, (bc)
	ld	e,a
	push	de
	ld	a, (_ct)
	push	af
	inc	sp
	call	_PrintObject
	pop	af
	inc	sp
00102$:
;src/main.c:616: ct++;
	ld	hl, #_ct+0
	inc	(hl)
	jr	00104$
;src/main.c:622: void CheckObjects() {
;	---------------------------------
; Function CheckObjects
; ---------------------------------
_CheckObjects::
	push	ix
	ld	ix,#0
	add	ix,sp
	push	af
;src/main.c:623: ct = 0;
	ld	hl,#_ct + 0
	ld	(hl), #0x00
;src/main.c:624: Wait4Key(ctlDown);
	ld	hl, (_ctlDown)
	call	_Wait4Key
;src/main.c:625: while (ct < N_MAX_OBJ) {
00122$:
	ld	a,(#_ct + 0)
	sub	a, #0x08
	jp	NC, 00125$
;src/main.c:626: if (obj[ct].mapNumber == mapNumber) { // if the object is on the screen ...
	ld	bc, (_ct)
	ld	b, #0x00
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, hl
	add	hl, bc
	ld	bc,#_obj
	add	hl,bc
	ex	(sp), hl
	pop	hl
	push	hl
	inc	hl
	inc	hl
	ld	c, (hl)
	ld	a,(#_mapNumber + 0)
	sub	a, c
	jp	NZ,00121$
;src/main.c:628: if (spr[0].x >= obj[ct].x - 3 && spr[0].x <= obj[ct].x + 3 &&	
	ld	hl, #_spr + 0
	ld	c, (hl)
	pop	hl
	push	hl
	ld	e, (hl)
	ld	d, #0x00
	ld	a, e
	add	a, #0xfd
	ld	l, a
	ld	a, d
	adc	a, #0xff
	ld	h, a
	ld	b, #0x00
	ld	a, c
	sub	a, l
	ld	a, b
	sbc	a, h
	jp	PO, 00181$
	xor	a, #0x80
00181$:
	jp	M, 00121$
	inc	de
	inc	de
	inc	de
	ld	l, d
	ld	a, e
	sub	a, c
	ld	a, l
	sbc	a, b
	jp	PO, 00182$
	xor	a, #0x80
00182$:
	jp	M, 00121$
;src/main.c:629: spr[0].y >= obj[ct].y - 4 && spr[0].y <= obj[ct].y + 4) {
	ld	hl, #_spr + 1
	ld	c, (hl)
	pop	hl
	push	hl
	inc	hl
	ld	e, (hl)
	ld	d, #0x00
	ld	a, e
	add	a, #0xfc
	ld	l, a
	ld	a, d
	adc	a, #0xff
	ld	b, a
	ld	h, #0x00
	ld	a, c
	sub	a, l
	ld	a, h
	sbc	a, b
	jp	PO, 00183$
	xor	a, #0x80
00183$:
	jp	M, 00121$
	inc	de
	inc	de
	inc	de
	inc	de
	ld	a, e
	sub	a, c
	ld	a, d
	sbc	a, h
	jp	PO, 00184$
	xor	a, #0x80
00184$:
	jp	M, 00121$
;src/main.c:630: if (ct > 5) { // first aid kit or ammunition					
	ld	a, #0x05
	ld	iy, #_ct
	sub	a, 0 (iy)
	jr	NC,00113$
;src/main.c:631: if (obj[ct].taken == FALSE) {
	pop	hl
	push	hl
	inc	hl
	inc	hl
	inc	hl
	ld	a, (hl)
	or	a, a
	jp	NZ, 00114$
;src/main.c:632: cpct_akp_SFXPlay (6, 12, 41, 0, 0, AY_CHANNEL_A);
	ld	a, #0x01
	push	af
	inc	sp
	ld	hl, #0x0000
	push	hl
	ld	l, #0x29
	push	hl
	ld	hl, #0x0c06
	push	hl
	call	_cpct_akp_SFXPlay
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
;src/main.c:633: if (ct == 6) spr[0].lives = 9; // first aid kit
	ld	a,(#_ct + 0)
	sub	a, #0x06
	jr	NZ,00102$
	ld	hl, #(_spr + 0x0009)
	ld	(hl), #0x09
00102$:
;src/main.c:634: if (ct == 7) ammo = 99; // ammunition
	ld	a,(#_ct + 0)
	sub	a, #0x07
	jr	NZ,00104$
	ld	hl,#_ammo + 0
	ld	(hl), #0x63
00104$:
;src/main.c:635: DeleteObject(&obj[ct]); 
	ld	bc, (_ct)
	ld	b, #0x00
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, hl
	add	hl, bc
	ld	de, #_obj
	add	hl, de
	call	_DeleteObject
;src/main.c:637: obj[ct].taken = TRUE;
	ld	bc, (_ct)
	ld	b, #0x00
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, hl
	add	hl, bc
	ld	de, #_obj
	add	hl, de
	inc	hl
	inc	hl
	inc	hl
	ld	(hl), #0x01
	jp	00114$
00113$:
;src/main.c:641: else if (spr[0].object != ct) {
	ld	hl, #(_spr + 0x000c) + 0
	ld	c, (hl)
	ld	a,(#_ct + 0)
	sub	a, c
	jr	Z,00110$
;src/main.c:643: if (spr[0].object == 255) {	
	inc	c
	jp	NZ,00114$
;src/main.c:644: cpct_akp_SFXPlay(8, 15, 45, 0, 0, AY_CHANNEL_A);
	ld	a, #0x01
	push	af
	inc	sp
	ld	hl, #0x0000
	push	hl
	ld	l, #0x2d
	push	hl
	ld	hl, #0x0f08
	push	hl
	call	_cpct_akp_SFXPlay
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
;src/main.c:645: spr[0].object = ct;
	ld	hl, #(_spr + 0x000c)
	ld	a,(#_ct + 0)
	ld	(hl), a
;src/main.c:646: obj[ct].taken = TRUE;
	ld	bc, (_ct)
	ld	b, #0x00
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, hl
	add	hl, bc
	ld	de, #_obj
	add	hl, de
	inc	hl
	inc	hl
	inc	hl
	ld	(hl), #0x01
;src/main.c:647: DeleteObject(&obj[ct]); 
	ld	bc, (_ct)
	ld	b, #0x00
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, hl
	add	hl, bc
	ld	de, #_obj
	add	hl, de
	call	_DeleteObject
;src/main.c:649: DeleteObjectScoreboard(); PrintObject(ct, 68, 12); 
	call	_DeleteObjectScoreboard
	ld	hl, #0x0c44
	push	hl
	ld	a, (_ct)
	push	af
	inc	sp
	call	_PrintObject
	pop	af
	inc	sp
	jr	00114$
00110$:
;src/main.c:653: cpct_akp_SFXPlay(7, 15, 45, 0, 0, AY_CHANNEL_A);
	ld	a, #0x01
	push	af
	inc	sp
	ld	hl, #0x0000
	push	hl
	ld	l, #0x2d
	push	hl
	ld	hl, #0x0f07
	push	hl
	call	_cpct_akp_SFXPlay
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
;src/main.c:655: PrintObject(ct, obj[ct].x, obj[ct].y);	
	ld	bc, (_ct)
	ld	b, #0x00
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, hl
	add	hl, bc
	ld	bc,#_obj
	add	hl,bc
	ld	c,l
	ld	b,h
	inc	hl
	ld	d, (hl)
	ld	a, (bc)
	ld	e,a
	push	de
	ld	a, (_ct)
	push	af
	inc	sp
	call	_PrintObject
	pop	af
	inc	sp
;src/main.c:656: DeleteObjectScoreboard();
	call	_DeleteObjectScoreboard
;src/main.c:657: spr[0].object = 255;
	ld	hl, #(_spr + 0x000c)
	ld	(hl), #0xff
;src/main.c:658: obj[ct].taken = FALSE;
	ld	bc, (_ct)
	ld	b, #0x00
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, hl
	add	hl, bc
	ld	de, #_obj
	add	hl, de
	inc	hl
	inc	hl
	inc	hl
	ld	(hl), #0x00
00114$:
;src/main.c:661: ct = N_MAX_OBJ;
	ld	hl,#_ct + 0
	ld	(hl), #0x08
00121$:
;src/main.c:664: ct++;
	ld	hl, #_ct+0
	inc	(hl)
	jp	00122$
00125$:
	ld	sp, ix
	pop	ix
	ret
;src/main.c:679: void InitObjects() {
;	---------------------------------
; Function InitObjects
; ---------------------------------
_InitObjects::
;src/main.c:671: obj[objNum].x = x; 
	ld	hl, #_obj
	ld	(hl), #0x18
;src/main.c:672: obj[objNum].y = y;
	ld	hl, #(_obj + 0x0001)
	ld	(hl), #0x60
;src/main.c:673: obj[objNum].mapNumber = mapNum;
	ld	hl, #(_obj + 0x0002)
	ld	(hl), #0x00
;src/main.c:671: obj[objNum].x = x; 
	ld	hl, #(_obj + 0x0005)
	ld	(hl), #0x00
;src/main.c:672: obj[objNum].y = y;
	ld	hl, #(_obj + 0x0006)
	ld	(hl), #0x00
;src/main.c:673: obj[objNum].mapNumber = mapNum;
	ld	hl, #(_obj + 0x0007)
	ld	(hl), #0xff
;src/main.c:671: obj[objNum].x = x; 
	ld	hl, #(_obj + 0x000a)
	ld	(hl), #0x2c
;src/main.c:672: obj[objNum].y = y;
	ld	hl, #(_obj + 0x000b)
	ld	(hl), #0x40
;src/main.c:673: obj[objNum].mapNumber = mapNum;
	ld	hl, #(_obj + 0x000c)
	ld	(hl), #0x02
;src/main.c:671: obj[objNum].x = x; 
	ld	hl, #(_obj + 0x000f)
	ld	(hl), #0x08
;src/main.c:672: obj[objNum].y = y;
	ld	hl, #(_obj + 0x0010)
	ld	(hl), #0x3c
;src/main.c:673: obj[objNum].mapNumber = mapNum;
	ld	hl, #(_obj + 0x0011)
	ld	(hl), #0x01
;src/main.c:671: obj[objNum].x = x; 
	ld	hl, #(_obj + 0x0014)
	ld	(hl), #0x00
;src/main.c:672: obj[objNum].y = y;
	ld	hl, #(_obj + 0x0015)
	ld	(hl), #0x00
;src/main.c:673: obj[objNum].mapNumber = mapNum;
	ld	hl, #(_obj + 0x0016)
	ld	(hl), #0xff
;src/main.c:671: obj[objNum].x = x; 
	ld	hl, #(_obj + 0x0019)
	ld	(hl), #0x00
;src/main.c:672: obj[objNum].y = y;
	ld	hl, #(_obj + 0x001a)
	ld	(hl), #0x00
;src/main.c:673: obj[objNum].mapNumber = mapNum;
	ld	hl, #(_obj + 0x001b)
	ld	(hl), #0xff
;src/main.c:671: obj[objNum].x = x; 
	ld	hl, #(_obj + 0x001e)
	ld	(hl), #0x42
;src/main.c:672: obj[objNum].y = y;
	ld	hl, #(_obj + 0x001f)
	ld	(hl), #0x80
;src/main.c:673: obj[objNum].mapNumber = mapNum;
	ld	hl, #(_obj + 0x0020)
	ld	(hl), #0x01
;src/main.c:671: obj[objNum].x = x; 
	ld	hl, #(_obj + 0x0023)
	ld	(hl), #0x44
;src/main.c:672: obj[objNum].y = y;
	ld	hl, #(_obj + 0x0024)
	ld	(hl), #0x40
;src/main.c:673: obj[objNum].mapNumber = mapNum;
	ld	hl, #(_obj + 0x0025)
	ld	(hl), #0x02
;src/main.c:688: SetObjectParams(7, 68,  64,   2); // Ammunition
	ret
;src/main.c:703: void PrintSprite(TSpr *pSpr) __z88dk_fastcall {
;	---------------------------------
; Function PrintSprite
; ---------------------------------
_PrintSprite::
;src/main.c:706: SPR_W, SPR_H, g_maskTable);
;src/main.c:705: cpct_getScreenPtr(CPCT_VMEM_START, pSpr->x, pSpr->y), 
	ld	c,l
	ld	b,h
	inc	hl
	ld	d, (hl)
	ld	a, (bc)
	push	bc
	ld	e, a
	push	de
	ld	hl, #0xc000
	push	hl
	call	_cpct_getScreenPtr
	ex	de,hl
	pop	iy
	ld	l, 5 (iy)
	ld	h, 6 (iy)
	inc	hl
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	ld	hl, #_g_maskTable
	push	hl
	ld	hl, #0x1008
	push	hl
	push	de
	push	bc
	call	_cpct_drawSpriteMaskedAlignedTable
	ret
;src/main.c:711: void DeleteSprite(TSpr *pSpr) __z88dk_fastcall {
;	---------------------------------
; Function DeleteSprite
; ---------------------------------
_DeleteSprite::
	push	ix
	ld	ix,#0
	add	ix,sp
	dec	sp
;src/main.c:713: 4 + (pSpr->px & 1), 4 + (pSpr->py & 3 ? 1 : 0),	
	ld	c,l
	ld	b,h
	inc	hl
	inc	hl
	inc	hl
	ld	e, (hl)
	ld	a, e
	and	a, #0x03
	jr	Z,00103$
	ld	d, #0x01
	jr	00104$
00103$:
	ld	d, #0x00
00104$:
	inc	d
	inc	d
	inc	d
	inc	d
	ld	l, c
	ld	h, b
	inc	hl
	inc	hl
	ld	c, (hl)
	ld	a, c
	and	a, #0x01
	add	a, #0x04
	ld	-1 (ix), a
;src/main.c:712: cpct_etm_drawTileBox2x4(pSpr->px / 2, (pSpr->py - ORIG_MAP_Y) / 4, 
	ld	b, #0x00
	ld	l, e
	ld	h, b
	bit	7, b
	jr	Z,00105$
	ld	l, e
	ld	h, b
	inc	hl
	inc	hl
	inc	hl
00105$:
	sra	h
	rr	l
	sra	h
	rr	l
	ld	e, l
	srl	c
	ld	hl, #0x1031
	push	hl
	ld	hl, #0xc000
	push	hl
	ld	a, #0x28
	push	af
	inc	sp
	push	de
	inc	sp
	ld	d, -1 (ix)
	push	de
	ld	a, c
	push	af
	inc	sp
	call	_cpct_etm_drawTileBox2x4
	inc	sp
	pop	ix
	ret
;src/main.c:719: void PrintExplosion(TSpr *pSpr, u8 frame) {
;	---------------------------------
; Function PrintExplosion
; ---------------------------------
_PrintExplosion::
	push	ix
	ld	ix,#0
	add	ix,sp
;src/main.c:722: SPR_W, SPR_H, g_maskTable);
;src/main.c:721: cpct_getScreenPtr(CPCT_VMEM_START, pSpr->x, pSpr->y), 
	ld	c,4 (ix)
	ld	b,5 (ix)
	ld	l, c
	ld	h, b
	inc	hl
	ld	d, (hl)
	ld	a, (bc)
	ld	e,a
	push	de
	ld	hl, #0xc000
	push	hl
	call	_cpct_getScreenPtr
	ld	c, l
	ld	b, h
;src/main.c:720: cpct_drawSpriteMaskedAlignedTable(g_explosion[frame], 
	ld	de, #_g_explosion+0
	ld	l, 6 (ix)
	ld	h, #0x00
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, de
	ld	de, #_g_maskTable
	push	de
	ld	de, #0x1008
	push	de
	push	bc
	push	hl
	call	_cpct_drawSpriteMaskedAlignedTable
	pop	ix
	ret
;src/main.c:727: void SelectSpriteFrame(TSpr *pSpr) __z88dk_fastcall {
;	---------------------------------
; Function SelectSpriteFrame
; ---------------------------------
_SelectSpriteFrame::
	push	ix
	ld	ix,#0
	add	ix,sp
	dec	sp
;src/main.c:728: if (ctMainLoop % ANIM_PAUSE == 0) {
	push	hl
	ld	a, #0x03
	push	af
	inc	sp
	ld	a, (_ctMainLoop)
	push	af
	inc	sp
	call	__moduchar
	pop	af
	pop	bc
	ld	a, l
	or	a, a
	jr	NZ,00109$
;src/main.c:729: if (pSpr->ident == PELUSOID)
	ld	l, c
	ld	h, b
	ld	de, #0x0012
	add	hl, de
	ld	a, (hl)
	ld	-1 (ix), a
;src/main.c:730: pSpr->frm = anim_pelusoid[pSpr->nFrm / ANIM_PAUSE];
	ld	hl, #0x0005
	add	hl,bc
	ex	de,hl
	push	bc
	pop	iy
	ld	b, 7 (iy)
	push	de
	ld	a, #0x03
	push	af
	inc	sp
	push	bc
	inc	sp
	call	__divuchar
	pop	af
	pop	de
	ld	h, #0x00
	add	hl, hl
;src/main.c:729: if (pSpr->ident == PELUSOID)
	ld	a, -1 (ix)
	dec	a
	jr	NZ,00105$
;src/main.c:730: pSpr->frm = anim_pelusoid[pSpr->nFrm / ANIM_PAUSE];
	ld	bc, #_anim_pelusoid+0
	add	hl, bc
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	ld	a, c
	ld	(de), a
	inc	de
	ld	a, b
	ld	(de), a
	jr	00109$
00105$:
;src/main.c:731: else if (pSpr->ident == ARACNOVIRUS)
	ld	a, -1 (ix)
	sub	a, #0x02
	jr	NZ,00102$
;src/main.c:732: pSpr->frm = anim_aracnovirus[pSpr->nFrm / ANIM_PAUSE];
	ld	bc, #_anim_aracnovirus+0
	add	hl, bc
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	ld	a, c
	ld	(de), a
	inc	de
	ld	a, b
	ld	(de), a
	jr	00109$
00102$:
;src/main.c:734: pSpr->frm = anim_infected[pSpr->nFrm / ANIM_PAUSE];
	ld	bc, #_anim_infected+0
	add	hl, bc
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	ld	a, c
	ld	(de), a
	inc	de
	ld	a, b
	ld	(de), a
00109$:
	inc	sp
	pop	ix
	ret
;src/main.c:740: void EnemyWalkAnim(TSpr *pSpr) __z88dk_fastcall {
;	---------------------------------
; Function EnemyWalkAnim
; ---------------------------------
_EnemyWalkAnim::
;src/main.c:741: if(++pSpr->nFrm == 2 * ANIM_PAUSE) pSpr->nFrm = 0;
	ld	bc, #0x0007
	add	hl, bc
	ld	a, (hl)
	inc	a
	ld	(hl), a
	sub	a,#0x06
	ret	NZ
	ld	(hl),a
	ret
;src/main.c:746: void CheckEnemyCollision(TSpr *pSpr) { // __z88dk_fastcall
;	---------------------------------
; Function CheckEnemyCollision
; ---------------------------------
_CheckEnemyCollision::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl, #-8
	add	hl, sp
	ld	sp, hl
;src/main.c:748: if ((spr[0].x + SPR_W) > (pSpr->x + 2) && (spr[0].x + 2) < (pSpr->x + SPR_W))
	ld	a, (#_spr + 0)
	ld	-2 (ix), a
	ld	-1 (ix), #0x00
	ld	a, -2 (ix)
	add	a, #0x08
	ld	c, a
	ld	a, -1 (ix)
	adc	a, #0x00
	ld	b, a
	ld	a, 4 (ix)
	ld	-4 (ix), a
	ld	a, 5 (ix)
	ld	-3 (ix), a
	ld	l,-4 (ix)
	ld	h,-3 (ix)
	ld	e, (hl)
	ld	-6 (ix), e
	ld	-5 (ix), #0x00
	ld	d, #0x00
	inc	de
	inc	de
;src/main.c:750: if ((spr[0].y + SPR_H) > (pSpr->y + 2) && (spr[0].y + 2) < (pSpr->y + SPR_H))
	ld	a, -4 (ix)
	add	a, #0x01
	ld	-8 (ix), a
	ld	a, -3 (ix)
	adc	a, #0x00
	ld	-7 (ix), a
;src/main.c:748: if ((spr[0].x + SPR_W) > (pSpr->x + 2) && (spr[0].x + 2) < (pSpr->x + SPR_W))
	ld	a, e
	sub	a, c
	ld	a, d
	sbc	a, b
	jp	PO, 00160$
	xor	a, #0x80
00160$:
	jp	P, 00115$
	ld	c,-2 (ix)
	ld	b,-1 (ix)
	inc	bc
	inc	bc
	ld	a, -6 (ix)
	add	a, #0x08
	ld	e, a
	ld	a, -5 (ix)
	adc	a, #0x00
	ld	d, a
	ld	a, c
	sub	a, e
	ld	a, b
	sbc	a, d
	jp	PO, 00161$
	xor	a, #0x80
00161$:
	jp	P, 00115$
;src/main.c:750: if ((spr[0].y + SPR_H) > (pSpr->y + 2) && (spr[0].y + 2) < (pSpr->y + SPR_H))
	ld	hl, #_spr + 1
	ld	c, (hl)
	ld	b, #0x00
	ld	hl, #0x0010
	add	hl,bc
	ld	-2 (ix), l
	ld	-1 (ix), h
	pop	hl
	push	hl
	ld	e, (hl)
	ld	d, #0x00
	ld	l, e
	ld	h, d
	inc	hl
	inc	hl
	ld	a, l
	sub	a, -2 (ix)
	ld	a, h
	sbc	a, -1 (ix)
	jp	PO, 00162$
	xor	a, #0x80
00162$:
	jp	P, 00118$
	inc	bc
	inc	bc
	ld	hl, #0x0010
	add	hl, de
	ld	a, c
	sub	a, l
	ld	a, b
	sbc	a, h
	jp	PO, 00163$
	xor	a, #0x80
00163$:
	jp	P, 00118$
;src/main.c:753: spr[0].lives--;
	ld	hl, #_spr + 9
	ld	c, (hl)
	dec	c
	ld	(hl), c
;src/main.c:754: ExplodePlayer();
	call	_ExplodePlayer
;src/main.c:755: ExplodeEnemies();
	call	_ExplodeEnemies
;src/main.c:756: GameOver();
	call	_GameOver
	jp	00118$
00115$:
;src/main.c:760: else if (shot.active == TRUE)
	ld	a, (#(_shot + 0x0005) + 0)
	dec	a
	jp	NZ,00118$
;src/main.c:762: if ((shot.x + SHOT_W) > (pSpr->x + 1) && shot.x < (pSpr->x + SHOT_W))
	ld	hl, #_shot + 0
	ld	c, (hl)
	ld	b, #0x00
	ld	hl, #0x0004
	add	hl, bc
	ld	e,-6 (ix)
	ld	d,-5 (ix)
	inc	de
	ld	a, e
	sub	a, l
	ld	a, d
	sbc	a, h
	jp	PO, 00166$
	xor	a, #0x80
00166$:
	jp	P, 00118$
	ld	a, -6 (ix)
	add	a, #0x04
	ld	e, a
	ld	a, -5 (ix)
	adc	a, #0x00
	ld	d, a
	ld	a, c
	sub	a, e
	ld	a, b
	sbc	a, d
	jp	PO, 00167$
	xor	a, #0x80
00167$:
	jp	P, 00118$
;src/main.c:764: if ((shot.y + SHOT_H) > (pSpr->y - 1) && (shot.y - 1) < (pSpr->y + SHOT_H))
	ld	hl, #_shot + 2
	ld	c, (hl)
	ld	b, #0x00
	ld	hl, #0x0008
	add	hl,bc
	ld	-6 (ix), l
	ld	-5 (ix), h
	pop	hl
	push	hl
	ld	e, (hl)
	ld	d, #0x00
	ld	l, e
	ld	h, d
	dec	hl
	ld	a, l
	sub	a, -6 (ix)
	ld	a, h
	sbc	a, -5 (ix)
	jp	PO, 00168$
	xor	a, #0x80
00168$:
	jp	P, 00118$
	dec	bc
	ld	hl, #0x0008
	add	hl, de
	ld	a, c
	sub	a, l
	ld	a, b
	sbc	a, h
	jp	PO, 00169$
	xor	a, #0x80
00169$:
	jp	P, 00118$
;src/main.c:766: cpct_akp_SFXPlay (4, 15, 40, 0, 0, AY_CHANNEL_A); // explosion
	ld	a, #0x01
	push	af
	inc	sp
	ld	hl, #0x0000
	push	hl
	ld	l, #0x28
	push	hl
	ld	hl, #0x0f04
	push	hl
	call	_cpct_akp_SFXPlay
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
;src/main.c:769: pSpr->lives--;
	ld	a, -4 (ix)
	add	a, #0x09
	ld	l, a
	ld	a, -3 (ix)
	adc	a, #0x00
	ld	h, a
	ld	c, (hl)
	dec	c
	ld	(hl), c
;src/main.c:770: pSpr->touched = 10;
	ld	a, -4 (ix)
	add	a, #0x0a
	ld	l, a
	ld	a, -3 (ix)
	adc	a, #0x00
	ld	h, a
	ld	(hl), #0x0a
;src/main.c:771: pSpr->status = S_touched;
	ld	a, -4 (ix)
	add	a, #0x04
	ld	l, a
	ld	a, -3 (ix)
	adc	a, #0x00
	ld	h, a
	ld	(hl), #0x08
;src/main.c:772: shot.active = FALSE;
	ld	hl, #(_shot + 0x0005)
	ld	(hl), #0x00
;src/main.c:775: score += 25;
	ld	hl, #_score
	ld	a, (hl)
	add	a, #0x19
	ld	(hl), a
	inc	hl
	ld	a, (hl)
	adc	a, #0x00
	ld	(hl), a
;src/main.c:776: if (highScore < score) highScore = score;
	ld	hl, #_score
	ld	iy, #_highScore
	ld	a, 0 (iy)
	sub	a, (hl)
	ld	a, 1 (iy)
	inc	hl
	sbc	a, (hl)
	jr	NC,00105$
	ld	hl, (_score)
	ld	(_highScore), hl
00105$:
;src/main.c:778: DeleteShot(&shot);
	ld	hl, #_shot
	call	_DeleteShot
00118$:
	ld	sp, ix
	pop	ix
	ret
;src/main.c:797: void AssignFrame(TFrm **anim) __z88dk_fastcall {
;	---------------------------------
; Function AssignFrame
; ---------------------------------
_AssignFrame::
	ld	c, l
	ld	b, h
;src/main.c:798: spr[0].frm = anim[spr[0].nFrm / ANIM_PAUSE];
	ld	hl, #_spr + 7
	ld	d, (hl)
	push	bc
	ld	a, #0x03
	push	af
	inc	sp
	push	de
	inc	sp
	call	__divuchar
	pop	af
	pop	bc
	ld	h, #0x00
	add	hl, hl
	add	hl, bc
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	ld	((_spr + 0x0005)), bc
	ret
;src/main.c:803: void SelectFrame() {
;	---------------------------------
; Function SelectFrame
; ---------------------------------
_SelectFrame::
;src/main.c:805: switch(spr[0].status) {
	ld	hl, #(_spr + 0x0004) + 0
	ld	c, (hl)
;src/main.c:806: case S_stopped:			{spr[0].frm = &frm_player[0]; break;}
;src/main.c:805: switch(spr[0].status) {
	ld	a, #0x07
	sub	a, c
	jr	C,00109$
	ld	b, #0x00
	ld	hl, #00127$
	add	hl, bc
	add	hl, bc
	add	hl, bc
	jp	(hl)
00127$:
	jp	00101$
	jp	00102$
	jp	00104$
	jp	00105$
	jp	00103$
	jp	00106$
	jp	00107$
	jp	00108$
;src/main.c:806: case S_stopped:			{spr[0].frm = &frm_player[0]; break;}
00101$:
	ld	hl, #_frm_player
	ld	((_spr + 0x0005)), hl
	jr	00109$
;src/main.c:807: case S_walking:			{AssignFrame(animWalk); break;}	// 0,1,0,2
00102$:
	ld	hl, #_animWalk
	call	_AssignFrame
	jr	00109$
;src/main.c:808: case S_climbing:		{AssignFrame(animClimb); break;} // 6,7,6,8
00103$:
	ld	hl, #_animClimb
	call	_AssignFrame
	jr	00109$
;src/main.c:809: case S_preJump:			{spr[0].frm = &frm_player[1]; break;}
00104$:
	ld	hl, #(_frm_player + 0x0003)
	ld	((_spr + 0x0005)), hl
	jr	00109$
;src/main.c:810: case S_jumping:			{spr[0].frm = &frm_player[3]; break;}
00105$:
	ld	hl, #(_frm_player + 0x0009)
	ld	((_spr + 0x0005)), hl
	jr	00109$
;src/main.c:811: case S_falling:			{spr[0].frm = &frm_player[4]; break;}
00106$:
	ld	hl, #(_frm_player + 0x000c)
	ld	((_spr + 0x0005)), hl
	jr	00109$
;src/main.c:812: case S_landing:			{spr[0].frm = &frm_player[1]; break;}
00107$:
	ld	hl, #(_frm_player + 0x0003)
	ld	((_spr + 0x0005)), hl
	jr	00109$
;src/main.c:813: case S_firing:			{spr[0].frm = &frm_player[5]; }
00108$:
	ld	hl, #(_frm_player + 0x000f)
	ld	((_spr + 0x0005)), hl
;src/main.c:814: }
00109$:
;src/main.c:816: f = spr[0].frm;
	ld	bc, (#(_spr + 0x0005) + 0)
;src/main.c:818: if (f->dir != spr[0].dir && spr[0].status != S_climbing) {
	ld	a, (bc)
	ld	e, a
	ld	a, (#(_spr + 0x0008) + 0)
	sub	a, e
	ret	Z
	ld	a, (#(_spr + 0x0004) + 0)
	sub	a, #0x04
	ret	Z
;src/main.c:819: cpct_hflipSpriteM0(SPR_W, SPR_H, f->spr);         
	ld	l, c
	ld	h, b
	inc	hl
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	push	bc
	push	de
	ld	hl, #0x1008
	push	hl
	call	_cpct_hflipSpriteM0
	pop	bc
;src/main.c:820: f->dir = spr[0].dir; // save position to compare with next call
	ld	a, (#(_spr + 0x0008) + 0)
	ld	(bc), a
	ret
;src/main.c:825: void MoveUp() { 
;	---------------------------------
; Function MoveUp
; ---------------------------------
_MoveUp::
;src/main.c:826: if (spr[0].y > ORIG_MAP_Y) spr[0].y--;
	ld	bc, #_spr+1
	ld	a, (bc)
	or	a, a
	ret	Z
	add	a, #0xff
	ld	(bc), a
	ret
;src/main.c:830: void MoveDown() {
;	---------------------------------
; Function MoveDown
; ---------------------------------
_MoveDown::
;src/main.c:831: if (spr[0].y + SPR_H < GLOBAL_MAX_Y) spr[0].y++;
	ld	hl, #(_spr + 0x0001) + 0
	ld	c, (hl)
	ld	e, c
	ld	d, #0x00
	ld	hl, #0x0010
	add	hl, de
	ld	de, #0x80c0
	add	hl, hl
	ccf
	rr	h
	rr	l
	sbc	hl, de
	ret	NC
	inc	c
	ld	hl, #(_spr + 0x0001)
	ld	(hl), c
	ret
;src/main.c:835: void MoveLeft() {
;	---------------------------------
; Function MoveLeft
; ---------------------------------
_MoveLeft::
;src/main.c:836: if (spr[0].x > 0) {
	ld	a, (#_spr + 0)
	or	a, a
	jp	Z,_MoveLeftMap
;src/main.c:837: if (!FacingWall(spr[0].dir)) {
	ld	hl, #(_spr + 0x0008) + 0
	ld	l, (hl)
	call	_FacingWall
	ld	a, l
	or	a, a
	ret	NZ
;src/main.c:838: spr[0].x--;
	ld	hl, #_spr + 0
	ld	c, (hl)
	dec	c
	ld	hl, #_spr
	ld	(hl), c
;src/main.c:839: spr[0].dir = D_left;
	ld	hl, #(_spr + 0x0008)
	ld	(hl), #0x02
	ret
;src/main.c:843: MoveLeftMap(); 
	jp  _MoveLeftMap
;src/main.c:847: void MoveRight() { 
;	---------------------------------
; Function MoveRight
; ---------------------------------
_MoveRight::
;src/main.c:848: if (spr[0].x + SPR_W < GLOBAL_MAX_X) {
	ld	hl, #_spr + 0
	ld	c, (hl)
	ld	b, #0x00
	ld	hl, #0x0008
	add	hl, bc
	ld	de, #0x8050
	add	hl, hl
	ccf
	rr	h
	rr	l
	sbc	hl, de
	jp	NC,_MoveRightMap
;src/main.c:849: if (!FacingWall(spr[0].dir)) {
	ld	hl, #(_spr + 0x0008) + 0
	ld	l, (hl)
	call	_FacingWall
	ld	a, l
	or	a, a
	ret	NZ
;src/main.c:850: spr[0].x++;
	ld	a, (#_spr + 0)
	inc	a
	ld	(#_spr),a
;src/main.c:851: spr[0].dir = D_right;
	ld	hl, #(_spr + 0x0008)
	ld	(hl), #0x03
	ret
;src/main.c:855: MoveRightMap();
	jp  _MoveRightMap
;src/main.c:860: void WalkIn(u8 dir) __z88dk_fastcall {
;	---------------------------------
; Function WalkIn
; ---------------------------------
_WalkIn::
	ld	c, l
;src/main.c:861: spr[0].nFrm = 0;
	ld	hl, #(_spr + 0x0007)
	ld	(hl), #0x00
;src/main.c:862: spr[0].status = S_walking;
	ld	hl, #(_spr + 0x0004)
	ld	(hl), #0x01
;src/main.c:863: spr[0].dir = dir;
	ld	hl, #(_spr + 0x0008)
	ld	(hl), c
	ret
;src/main.c:868: void ClimbIn() {
;	---------------------------------
; Function ClimbIn
; ---------------------------------
_ClimbIn::
;src/main.c:869: spr[0].nFrm = 0;
	ld	hl, #(_spr + 0x0007)
	ld	(hl), #0x00
;src/main.c:870: spr[0].status = S_climbing;
	ld	hl, #(_spr + 0x0004)
	ld	(hl), #0x04
	ret
;src/main.c:875: void PreJumpIn() {
;	---------------------------------
; Function PreJumpIn
; ---------------------------------
_PreJumpIn::
;src/main.c:876: spr[0].nFrm = 0;
	ld	hl, #(_spr + 0x0007)
	ld	(hl), #0x00
;src/main.c:877: spr[0].status = S_preJump;
	ld	hl, #(_spr + 0x0004)
	ld	(hl), #0x02
	ret
;src/main.c:882: void FallIn() {
;	---------------------------------
; Function FallIn
; ---------------------------------
_FallIn::
;src/main.c:883: spr[0].status = S_falling;
	ld	hl, #(_spr + 0x0004)
	ld	(hl), #0x05
;src/main.c:884: spr[0].jump  = JUMP_STEPS - 3;
	ld	hl, #(_spr + 0x000b)
	ld	(hl), #0x09
	ret
;src/main.c:889: void LandIn() {
;	---------------------------------
; Function LandIn
; ---------------------------------
_LandIn::
;src/main.c:890: spr[0].nFrm = 0;
	ld	hl, #(_spr + 0x0007)
	ld	(hl), #0x00
;src/main.c:891: spr[0].status = S_landing;
	ld	hl, #(_spr + 0x0004)
	ld	(hl), #0x06
	ret
;src/main.c:896: void PreShotIn() 
;	---------------------------------
; Function PreShotIn
; ---------------------------------
_PreShotIn::
;src/main.c:898: if (shot.active == FALSE && ammo != 0) { // if enough ammo and no shot active on screen
	ld	bc, #_shot + 5
	ld	a, (bc)
	or	a, a
	ret	NZ
	ld	iy, #_ammo
	ld	a, 0 (iy)
	or	a, a
	ret	Z
;src/main.c:899: shot.active = TRUE;
	ld	a, #0x01
	ld	(bc), a
;src/main.c:900: shot.dir = spr[0].dir; // the direction of the shot is that of the player
	ld	bc, #_shot + 3
	ld	a, (#_spr + 8)
	ld	(bc), a
;src/main.c:901: ammo--; // subtract a bullet from the available ammunition		
	dec	0 (iy)
;src/main.c:902: shot.y = spr[0].y + 5; // adjusts to the player's height
	ld	de, #_shot + 2
	ld	a, (#_spr + 1)
	add	a, #0x05
	ld	(de), a
;src/main.c:905: if (shot.dir == D_right)
	ld	a, (bc)
	ld	e, a
;src/main.c:906: shot.x = shot.px = spr[0].x + SPR_W;
	ld	bc, #_shot + 1
	ld	hl, #_spr + 0
	ld	d, (hl)
;src/main.c:905: if (shot.dir == D_right)
	ld	a, e
	sub	a, #0x03
	jr	NZ,00102$
;src/main.c:906: shot.x = shot.px = spr[0].x + SPR_W;
	ld	a, d
	add	a, #0x08
	ld	(bc), a
	ld	(#_shot),a
	jr	00103$
00102$:
;src/main.c:908: shot.x = shot.px = spr[0].x - SHOT_W;
	ld	a, d
	add	a, #0xfc
	ld	(bc), a
	ld	(#_shot),a
00103$:
;src/main.c:910: shot.status = spr[0].status; // backup player status before shooting
	ld	bc, #_spr + 4
	ld	a, (bc)
	ld	(#(_shot + 0x0004)),a
;src/main.c:911: spr[0].status = S_firing;
	ld	a, #0x07
	ld	(bc), a
;src/main.c:912: cpct_akp_SFXPlay(2, 15, 40, 0, 0, AY_CHANNEL_A); // laser
	ld	a, #0x01
	push	af
	inc	sp
	ld	hl, #0x0000
	push	hl
	ld	l, #0x28
	push	hl
	ld	hl, #0x0f02
	push	hl
	call	_cpct_akp_SFXPlay
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
	ret
;src/main.c:918: void Falling() {
;	---------------------------------
; Function Falling
; ---------------------------------
_Falling::
;src/main.c:919: cpct_scanKeyboard_f(); // check the pressed keys
	call	_cpct_scanKeyboard_f
;src/main.c:921: if(cpct_isKeyPressed(ctlDown)) CheckObjects();
	ld	hl, (_ctlDown)
	call	_cpct_isKeyPressed
	ld	a, l
	or	a, a
	jr	Z,00110$
	call	_CheckObjects
	jr	00111$
00110$:
;src/main.c:922: else if (cpct_isKeyPressed(ctlFire)) PreShotIn();
	ld	hl, (_ctlFire)
	call	_cpct_isKeyPressed
	ld	a, l
	or	a, a
	jr	Z,00107$
	call	_PreShotIn
	jr	00111$
00107$:
;src/main.c:923: else if (cpct_isKeyPressed(ctlLeft)) MoveLeft();
	ld	hl, (_ctlLeft)
	call	_cpct_isKeyPressed
	ld	a, l
	or	a, a
	jr	Z,00104$
	call	_MoveLeft
	jr	00111$
00104$:
;src/main.c:924: else if (cpct_isKeyPressed(ctlRight)) MoveRight();
	ld	hl, (_ctlRight)
	call	_cpct_isKeyPressed
	ld	a, l
	or	a, a
	jr	Z,00111$
	call	_MoveRight
00111$:
;src/main.c:927: spr[0].y += cpct_get2Bits(g_jumpTable, spr[0].jump);	
	ld	hl, #(_spr + 0x0001) + 0
	ld	c, (hl)
	ld	hl, #(_spr + 0x000b) + 0
	ld	e, (hl)
	ld	d, #0x00
	push	bc
	push	de
	ld	hl, #_g_jumpTable
	push	hl
	call	_cpct_get2Bits
	pop	bc
	ld	a, c
	add	a, l
	ld	(#(_spr + 0x0001)),a
;src/main.c:928: if (spr[0].jump > 1) spr[0].jump--;
	ld	hl, #(_spr + 0x000b) + 0
	ld	c, (hl)
	ld	a, #0x01
	sub	a, c
	jr	NC,00113$
	dec	c
	ld	hl, #(_spr + 0x000b)
	ld	(hl), c
00113$:
;src/main.c:930: if (OnPlatform(&spr[0]) || OnStairs()) { // if the player is on a platform ...
	ld	hl, #_spr
	call	_OnPlatform
	ld	a, l
	or	a, a
	jr	NZ,00114$
	call	_OnStairs
	ld	a, l
	or	a, a
	ret	Z
;src/main.c:931: while ((spr[0].y + 1) % 4 != 0) spr[0].y--; // adjust to the ground			
00114$:
;src/main.c:927: spr[0].y += cpct_get2Bits(g_jumpTable, spr[0].jump);	
	ld	hl, #(_spr + 0x0001) + 0
	ld	c, (hl)
;src/main.c:931: while ((spr[0].y + 1) % 4 != 0) spr[0].y--; // adjust to the ground			
	ld	e, c
	ld	d, #0x00
	inc	de
	push	bc
	ld	hl, #0x0004
	push	hl
	push	de
	call	__modsint
	pop	af
	pop	af
	pop	bc
	ld	a, h
	or	a,l
	jr	Z,00116$
	dec	c
	ld	hl, #(_spr + 0x0001)
	ld	(hl), c
	jr	00114$
00116$:
;src/main.c:932: LandIn(); // prepare the landing
	call	_LandIn
	ret
;src/main.c:938: void StopIn() {
;	---------------------------------
; Function StopIn
; ---------------------------------
_StopIn::
;src/main.c:939: spr[0].status = S_stopped;
	ld	hl, #(_spr + 0x0004)
	ld	(hl), #0x00
	ret
;src/main.c:944: void Stopped() {
;	---------------------------------
; Function Stopped
; ---------------------------------
_Stopped::
;src/main.c:945: cpct_scanKeyboard_f(); // check the pressed keys
	call	_cpct_scanKeyboard_f
;src/main.c:946: if(cpct_isKeyPressed(ctlUp)) {
	ld	hl, (_ctlUp)
	call	_cpct_isKeyPressed
	ld	a, l
	or	a, a
	jr	Z,00134$
;src/main.c:947: if(OnStairs()) ClimbIn(); // going to climb a ladder
	call	_OnStairs
	ld	a, l
	or	a, a
	jp	NZ,_ClimbIn
;src/main.c:948: else PreJumpIn(); // going to jump
	jp  _PreJumpIn
00134$:
;src/main.c:950: else if(cpct_isKeyPressed(ctlDown)) {
	ld	hl, (_ctlDown)
	call	_cpct_isKeyPressed
	ld	a, l
	or	a, a
	jr	Z,00131$
;src/main.c:951: if(OnStairs()) ClimbIn(); // going down a ladder
	call	_OnStairs
	ld	a, l
	or	a, a
	jp	NZ,_ClimbIn
;src/main.c:952: else CheckObjects(); // going to grab / drop an object (if it is on an object)
	jp  _CheckObjects
00131$:
;src/main.c:954: else if(cpct_isKeyPressed(ctlLeft)) WalkIn(D_left);
	ld	hl, (_ctlLeft)
	call	_cpct_isKeyPressed
	ld	a, l
	or	a, a
	jr	Z,00128$
	ld	l, #0x02
	jp  _WalkIn
00128$:
;src/main.c:955: else if(cpct_isKeyPressed(ctlRight)) WalkIn(D_right);
	ld	hl, (_ctlRight)
	call	_cpct_isKeyPressed
	ld	a, l
	or	a, a
	jr	Z,00125$
	ld	l, #0x03
	jp  _WalkIn
00125$:
;src/main.c:956: else if(cpct_isKeyPressed(ctlFire)) PreShotIn();
	ld	hl, (_ctlFire)
	call	_cpct_isKeyPressed
	ld	a, l
	or	a, a
	jp	NZ,_PreShotIn
;src/main.c:958: else if(cpct_isKeyPressed(ctlAbort)) {
	ld	hl, (_ctlAbort)
	call	_cpct_isKeyPressed
	ld	a, l
	or	a, a
	jr	Z,00119$
;src/main.c:959: spr[0].lives = 0; 
	ld	hl, #(_spr + 0x0009)
	ld	(hl), #0x00
;src/main.c:960: ExplodePlayer();
	call	_ExplodePlayer
;src/main.c:961: ExplodeEnemies();
	call	_ExplodeEnemies
;src/main.c:962: GameOver();
	jp  _GameOver
00119$:
;src/main.c:965: else if(cpct_isKeyPressed(ctlMusic)) {
	ld	hl, (_ctlMusic)
	call	_cpct_isKeyPressed
	ld	a, l
	or	a, a
	jr	Z,00116$
;src/main.c:966: Wait4Key(ctlMusic);
	ld	hl, (_ctlMusic)
	call	_Wait4Key
;src/main.c:967: if (music == TRUE) { // if the music is playing ...
	ld	iy, #_music
	ld	a, 0 (iy)
	dec	a
	jr	NZ,00108$
;src/main.c:968: music = FALSE;
	ld	0 (iy), #0x00
;src/main.c:969: cpct_akp_musicInit(FX);
	ld	hl, #_FX
	push	hl
	call	_cpct_akp_musicInit
	pop	af
	ret
00108$:
;src/main.c:972: music = TRUE;			
	ld	hl,#_music + 0
	ld	(hl), #0x01
;src/main.c:973: cpct_akp_musicInit(Ingame1);
	ld	hl, #_Ingame1
	push	hl
	call	_cpct_akp_musicInit
	pop	af
	ret
00116$:
;src/main.c:977: else if(cpct_isKeyPressed(ctlPause)) {
	ld	hl, (_ctlPause)
	call	_cpct_isKeyPressed
	ld	a, l
	or	a, a
	ret	Z
;src/main.c:978: Wait4Key(ctlPause);
	ld	hl, (_ctlPause)
	call	_Wait4Key
;src/main.c:979: cpct_akp_musicInit(FX);
	ld	hl, #_FX
	push	hl
	call	_cpct_akp_musicInit
	pop	af
;src/main.c:980: while (!cpct_isAnyKeyPressed());
00110$:
	call	_cpct_isAnyKeyPressed
	ld	a, l
	or	a, a
	jr	Z,00110$
;src/main.c:981: Wait4Key(ctlPause);
	ld	hl, (_ctlPause)
	call	_Wait4Key
;src/main.c:982: cpct_akp_musicInit(Ingame1);
	ld	hl, #_Ingame1
	push	hl
	call	_cpct_akp_musicInit
	pop	af
	ret
;src/main.c:988: void JumpIn() {
;	---------------------------------
; Function JumpIn
; ---------------------------------
_JumpIn::
;src/main.c:989: spr[0].status = S_jumping;
	ld	hl, #(_spr + 0x0004)
	ld	(hl), #0x03
;src/main.c:990: spr[0].jump  = 0;
	ld	hl, #(_spr + 0x000b)
	ld	(hl), #0x00
;src/main.c:991: cpct_akp_SFXPlay(3, 15, 32, 0, 0, AY_CHANNEL_C);
	ld	a, #0x04
	push	af
	inc	sp
	ld	hl, #0x0000
	push	hl
	ld	l, #0x20
	push	hl
	ld	hl, #0x0f03
	push	hl
	call	_cpct_akp_SFXPlay
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
	ret
;src/main.c:995: void Jumping() {
;	---------------------------------
; Function Jumping
; ---------------------------------
_Jumping::
;src/main.c:996: cpct_scanKeyboard_f(); // check the pressed keys
	call	_cpct_scanKeyboard_f
;src/main.c:997: if(!cpct_isKeyPressed(ctlUp)) FallIn();
	ld	hl, (_ctlUp)
	call	_cpct_isKeyPressed
	ld	a, l
	or	a, a
	jr	NZ,00112$
	call	_FallIn
	jr	00113$
00112$:
;src/main.c:999: if (cpct_isKeyPressed(ctlFire)) PreShotIn();
	ld	hl, (_ctlFire)
	call	_cpct_isKeyPressed
	ld	a, l
	or	a, a
	jr	Z,00102$
	call	_PreShotIn
00102$:
;src/main.c:1000: if(cpct_isKeyPressed(ctlDown)) CheckObjects();
	ld	hl, (_ctlDown)
	call	_cpct_isKeyPressed
	ld	a, l
	or	a, a
	jr	Z,00109$
	call	_CheckObjects
	jr	00113$
00109$:
;src/main.c:1001: else if (cpct_isKeyPressed(ctlLeft)) MoveLeft();
	ld	hl, (_ctlLeft)
	call	_cpct_isKeyPressed
	ld	a, l
	or	a, a
	jr	Z,00106$
	call	_MoveLeft
	jr	00113$
00106$:
;src/main.c:1002: else if (cpct_isKeyPressed(ctlRight)) MoveRight();
	ld	hl, (_ctlRight)
	call	_cpct_isKeyPressed
	ld	a, l
	or	a, a
	jr	Z,00113$
	call	_MoveRight
00113$:
;src/main.c:1005: spr[0].y -= cpct_get2Bits(g_jumpTable, spr[0].jump);
	ld	hl, #(_spr + 0x0001) + 0
	ld	c, (hl)
	ld	hl, #(_spr + 0x000b) + 0
	ld	e, (hl)
	ld	d, #0x00
	push	bc
	push	de
	ld	hl, #_g_jumpTable
	push	hl
	call	_cpct_get2Bits
	pop	bc
	ld	a, c
	sub	a, l
	ld	(#(_spr + 0x0001)),a
;src/main.c:1009: if (++spr[0].jump == JUMP_STEPS)	FallIn();
	ld	a, (#(_spr + 0x000b) + 0)
	inc	a
	ld	(#(_spr + 0x000b)),a
	sub	a, #0x0c
	ret	NZ
	call	_FallIn
	ret
;src/main.c:1013: void PreJump() {
;	---------------------------------
; Function PreJump
; ---------------------------------
_PreJump::
;src/main.c:1014: cpct_scanKeyboard_f(); // check the pressed keys
	call	_cpct_scanKeyboard_f
;src/main.c:1015: if(cpct_isKeyPressed(ctlUp)) JumpIn();
	ld	hl, (_ctlUp)
	call	_cpct_isKeyPressed
	ld	a, l
	or	a, a
	jp	NZ,_JumpIn
;src/main.c:1016: else StopIn();	
	jp  _StopIn
;src/main.c:1027: void WalkAnim(u8 dir) __z88dk_fastcall {
;	---------------------------------
; Function WalkAnim
; ---------------------------------
_WalkAnim::
	ld	c, l
;src/main.c:1028: spr[0].dir  = dir;
	ld	hl, #(_spr + 0x0008)
	ld	(hl), c
;src/main.c:1029: if(++spr[0].nFrm == 4 * ANIM_PAUSE) spr[0].nFrm = 0;
	ld	bc, #_spr + 7
	ld	a, (bc)
	inc	a
	ld	(bc), a
	sub	a, #0x0c
	ret	NZ
	xor	a, a
	ld	(bc), a
	ret
;src/main.c:1033: void Walking() {
;	---------------------------------
; Function Walking
; ---------------------------------
_Walking::
;src/main.c:1034: cpct_scanKeyboard_f(); // check the pressed keys
	call	_cpct_scanKeyboard_f
;src/main.c:1035: if (cpct_isKeyPressed(ctlUp)) {
	ld	hl, (_ctlUp)
	call	_cpct_isKeyPressed
	ld	a, l
	or	a, a
	jr	Z,00120$
;src/main.c:1036: if (OnStairs()) ClimbIn(); // going to climb a ladder
	call	_OnStairs
	ld	a, l
	or	a, a
	jr	Z,00102$
	call	_ClimbIn
	jr	00121$
00102$:
;src/main.c:1037: else PreJumpIn(); // going to jump
	call	_PreJumpIn
	jr	00121$
00120$:
;src/main.c:1039: else if (cpct_isKeyPressed(ctlDown)) {
	ld	hl, (_ctlDown)
	call	_cpct_isKeyPressed
	ld	a, l
	or	a, a
	jr	Z,00117$
;src/main.c:1040: if (OnStairs()) ClimbIn(); // going down a ladder
	call	_OnStairs
	ld	a, l
	or	a, a
	jr	Z,00105$
	call	_ClimbIn
	jr	00121$
00105$:
;src/main.c:1041: else CheckObjects(); // going to grab / drop an object (if it is on an object)
	call	_CheckObjects
	jr	00121$
00117$:
;src/main.c:1043: else if (cpct_isKeyPressed(ctlFire)) PreShotIn();
	ld	hl, (_ctlFire)
	call	_cpct_isKeyPressed
	ld	a, l
	or	a, a
	jr	Z,00114$
	call	_PreShotIn
	jr	00121$
00114$:
;src/main.c:1044: else if (cpct_isKeyPressed(ctlLeft)) {MoveLeft(); WalkAnim(D_left);}
	ld	hl, (_ctlLeft)
	call	_cpct_isKeyPressed
	ld	a, l
	or	a, a
	jr	Z,00111$
	call	_MoveLeft
	ld	l, #0x02
	call	_WalkAnim
	jr	00121$
00111$:
;src/main.c:1045: else if (cpct_isKeyPressed(ctlRight)) {MoveRight(); WalkAnim(D_right);}
	ld	hl, (_ctlRight)
	call	_cpct_isKeyPressed
	ld	a, l
	or	a, a
	jr	Z,00108$
	call	_MoveRight
	ld	l, #0x03
	call	_WalkAnim
	jr	00121$
00108$:
;src/main.c:1046: else StopIn();
	call	_StopIn
00121$:
;src/main.c:1048: if (!OnPlatform(&spr[0])) // if it is not on a platform, it is also falling
	ld	hl, #_spr
	call	_OnPlatform
	ld	a, l
	or	a, a
	ret	NZ
;src/main.c:1049: FallIn();
	jp  _FallIn
;src/main.c:1053: void Climbing() {
;	---------------------------------
; Function Climbing
; ---------------------------------
_Climbing::
;src/main.c:1054: cpct_scanKeyboard_f(); // check the pressed keys
	call	_cpct_scanKeyboard_f
;src/main.c:1055: if(cpct_isKeyPressed(ctlUp)) {
	ld	hl, (_ctlUp)
	call	_cpct_isKeyPressed
	ld	a, l
	or	a, a
	jr	Z,00120$
;src/main.c:1056: if(OnStairs()) {MoveUp(); WalkAnim(D_right);} 
	call	_OnStairs
	ld	a, l
	or	a, a
	ret	Z
	call	_MoveUp
	ld	l, #0x03
	jp  _WalkAnim
00120$:
;src/main.c:1058: else if(cpct_isKeyPressed(ctlDown))	{
	ld	hl, (_ctlDown)
	call	_cpct_isKeyPressed
	ld	a, l
	or	a, a
	jr	Z,00117$
;src/main.c:1059: if(OnStairs()) {MoveDown(); WalkAnim(D_right);}
	call	_OnStairs
	ld	a, l
	or	a, a
	ret	Z
	call	_MoveDown
	ld	l, #0x03
	jp  _WalkAnim
00117$:
;src/main.c:1061: else if(cpct_isKeyPressed(ctlLeft)) {
	ld	hl, (_ctlLeft)
	call	_cpct_isKeyPressed
	ld	a, l
	or	a, a
	jr	Z,00114$
;src/main.c:1062: if(OnStairs()) {MoveLeft(); WalkAnim(D_left);} 
	call	_OnStairs
	ld	a, l
	or	a, a
	jr	Z,00106$
	call	_MoveLeft
	ld	l, #0x02
	jp  _WalkAnim
00106$:
;src/main.c:1063: else spr[0].status = S_walking;
	ld	hl, #(_spr + 0x0004)
	ld	(hl), #0x01
	ret
00114$:
;src/main.c:1065: else if(cpct_isKeyPressed(ctlRight)) {
	ld	hl, (_ctlRight)
	call	_cpct_isKeyPressed
	ld	a, l
	or	a, a
	ret	Z
;src/main.c:1066: if(OnStairs()) {MoveRight(); WalkAnim(D_right);} 
	call	_OnStairs
	ld	a, l
	or	a, a
	jr	Z,00109$
	call	_MoveRight
	ld	l, #0x03
	jp  _WalkAnim
00109$:
;src/main.c:1067: else spr[0].status = S_walking;
	ld	hl, #(_spr + 0x0004)
	ld	(hl), #0x01
	ret
;src/main.c:1073: void RunStatus() {
;	---------------------------------
; Function RunStatus
; ---------------------------------
_RunStatus::
;src/main.c:1074: switch(spr[0].status) {
	ld	bc, #_spr+4
	ld	a, (bc)
	ld	e, a
	ld	a, #0x07
	sub	a, e
	ret	C
	ld	d, #0x00
	ld	hl, #00117$
	add	hl, de
	add	hl, de
	add	hl, de
	jp	(hl)
00117$:
	jp	_Stopped
	jp	_Walking
	jp	_PreJump
	jp	_Jumping
	jp	_Climbing
	jp	_Falling
	jp	_StopIn
	jp	00108$
;src/main.c:1075: case S_stopped:       	Stopped();			break;
	jp  _Stopped
;src/main.c:1076: case S_walking:      	Walking();			break;
	jp  _Walking
;src/main.c:1077: case S_climbing:    	Climbing();			break;
	jp  _Climbing
;src/main.c:1078: case S_preJump:   		PreJump();			break;
	jp  _PreJump
;src/main.c:1079: case S_jumping:     	Jumping();			break;
	jp  _Jumping
;src/main.c:1080: case S_falling:      	Falling();			break;
	jp  _Falling
;src/main.c:1081: case S_landing:  		StopIn();			break;
	jp  _StopIn
;src/main.c:1082: case S_firing:   		Firing();
00108$:
;src/main.c:1022: spr[0].status = shot.status; 
	ld	a, (#(_shot + 0x0004) + 0)
	ld	(bc), a
;src/main.c:1083: }
	ret
;src/main.c:1088: void ExplodePlayer() {
;	---------------------------------
; Function ExplodePlayer
; ---------------------------------
_ExplodePlayer::
;src/main.c:1090: cpct_akp_SFXPlay (4, 15, 40, 0, 0, AY_CHANNEL_A); // explosion
	ld	a, #0x01
	push	af
	inc	sp
	ld	hl, #0x0000
	push	hl
	ld	l, #0x28
	push	hl
	ld	hl, #0x0f04
	push	hl
	call	_cpct_akp_SFXPlay
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
;src/main.c:1091: PrintExplosion(&spr[0], 0); Pause(20);
	xor	a, a
	push	af
	inc	sp
	ld	hl, #_spr
	push	hl
	call	_PrintExplosion
	pop	af
	inc	sp
	ld	hl, #0x0014
	call	_Pause
;src/main.c:1092: PrintExplosion(&spr[0], 1); Pause(20);
	ld	a, #0x01
	push	af
	inc	sp
	ld	hl, #_spr
	push	hl
	call	_PrintExplosion
	pop	af
	inc	sp
	ld	hl, #0x0014
	call	_Pause
;src/main.c:1093: PrintExplosion(&spr[0], 0); Pause(20);
	xor	a, a
	push	af
	inc	sp
	ld	hl, #_spr
	push	hl
	call	_PrintExplosion
	pop	af
	inc	sp
	ld	hl, #0x0014
	call	_Pause
;src/main.c:1094: DeleteSprite(&spr[0]);
	ld	hl, #_spr
	jp  _DeleteSprite
;src/main.c:1111: void DeleteShot(TShot *pShot) __z88dk_fastcall {
;	---------------------------------
; Function DeleteShot
; ---------------------------------
_DeleteShot::
	push	ix
	ld	ix,#0
	add	ix,sp
	dec	sp
;src/main.c:1113: 2 + (pShot->px & 1), 2 + (pShot->y & 3 ? 1 : 0), 
	ld	c,l
	ld	b,h
	inc	hl
	inc	hl
	ld	e, (hl)
	ld	a, e
	and	a, #0x03
	jr	Z,00103$
	ld	d, #0x01
	jr	00104$
00103$:
	ld	d, #0x00
00104$:
	inc	d
	inc	d
	ld	l, c
	ld	h, b
	inc	hl
	ld	c, (hl)
	ld	a, c
	and	a, #0x01
	add	a, #0x02
	ld	-1 (ix), a
;src/main.c:1112: cpct_etm_drawTileBox2x4(pShot->px / 2, (pShot->y - ORIG_MAP_Y) / 4, 
	ld	b, #0x00
	ld	l, e
	ld	h, b
	bit	7, b
	jr	Z,00105$
	ld	l, e
	ld	h, b
	inc	hl
	inc	hl
	inc	hl
00105$:
	sra	h
	rr	l
	sra	h
	rr	l
	ld	e, l
	srl	c
	ld	hl, #0x1031
	push	hl
	ld	hl, #0xc000
	push	hl
	ld	a, #0x28
	push	af
	inc	sp
	push	de
	inc	sp
	ld	d, -1 (ix)
	push	de
	ld	a, c
	push	af
	inc	sp
	call	_cpct_etm_drawTileBox2x4
	inc	sp
	pop	ix
	ret
;src/main.c:1119: void PrintShot(TShot *pShot, u8 frame) {
;	---------------------------------
; Function PrintShot
; ---------------------------------
_PrintShot::
	push	ix
	ld	ix,#0
	add	ix,sp
;src/main.c:1120: if (pShot->active == TRUE) {
	ld	c,4 (ix)
	ld	b,5 (ix)
	push	bc
	pop	iy
	ld	e, 5 (iy)
	dec	e
	jr	NZ,00103$
;src/main.c:1121: DeleteShot(pShot); // delete previous shot
	push	bc
	ld	l, c
	ld	h, b
	call	_DeleteShot
	pop	bc
;src/main.c:1124: SHOT_W, SHOT_H, g_maskTable);
;src/main.c:1123: cpct_getScreenPtr(CPCT_VMEM_START, pShot->x, pShot->y), 
	ld	l, c
	ld	h, b
	inc	hl
	inc	hl
	ld	d, (hl)
	ld	a, (bc)
	ld	e,a
	push	de
	ld	hl, #0xc000
	push	hl
	call	_cpct_getScreenPtr
	ld	c, l
	ld	b, h
;src/main.c:1122: cpct_drawSpriteMaskedAlignedTable(g_shots[frame],
	ld	de, #_g_shots+0
	ld	l, 6 (ix)
	ld	h, #0x00
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, de
	ld	de, #_g_maskTable
	push	de
	ld	de, #0x0804
	push	de
	push	bc
	push	hl
	call	_cpct_drawSpriteMaskedAlignedTable
00103$:
	pop	ix
	ret
;src/main.c:1130: void MoveShot(TShot *pShot, u8 speed) {
;	---------------------------------
; Function MoveShot
; ---------------------------------
_MoveShot::
	push	ix
	ld	ix,#0
	add	ix,sp
;src/main.c:1131: pShot->px = pShot->x; // save the current X coordinate
	ld	c,4 (ix)
	ld	b,5 (ix)
	ld	e, c
	ld	d, b
	inc	de
	ld	a, (bc)
	ld	(de), a
;src/main.c:1134: if (pShot->dir == D_right) 
	ld	l, c
	ld	h, b
	inc	hl
	inc	hl
	inc	hl
	ld	d, (hl)
;src/main.c:1131: pShot->px = pShot->x; // save the current X coordinate
	ld	a, (bc)
	ld	e, a
;src/main.c:1134: if (pShot->dir == D_right) 
	ld	a, d
	sub	a, #0x03
	jr	NZ,00102$
;src/main.c:1135: pShot->x = pShot->x + speed;
	ld	a, e
	add	a, 6 (ix)
	ld	(bc), a
	jr	00103$
00102$:
;src/main.c:1137: pShot->x = pShot->x - speed;
	ld	a, e
	sub	a, 6 (ix)
	ld	(bc), a
00103$:
;src/main.c:1131: pShot->px = pShot->x; // save the current X coordinate
	ld	a, (bc)
	ld	e, a
;src/main.c:1140: if (pShot->x + SHOT_W >= GLOBAL_MAX_X || pShot->x <= 0) {
	ld	l, e
	ld	h, #0x00
	inc	hl
	inc	hl
	inc	hl
	inc	hl
	ld	a, l
	sub	a, #0x50
	ld	a, h
	rla
	ccf
	rra
	sbc	a, #0x80
	jr	NC,00104$
	ld	a, e
	or	a, a
	jr	NZ,00107$
00104$:
;src/main.c:1141: pShot->active = FALSE;
	ld	hl, #0x0005
	add	hl, bc
	ld	(hl), #0x00
;src/main.c:1143: DeleteShot(pShot); 
	ld	l, c
	ld	h, b
	call	_DeleteShot
00107$:
	pop	ix
	ret
;src/main.c:1161: void MoveEnemy(TSpr *pSpr) { //__z88dk_fastcall
;	---------------------------------
; Function MoveEnemy
; ---------------------------------
_MoveEnemy::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl, #-9
	add	hl, sp
	ld	sp, hl
;src/main.c:1162: switch(pSpr->movType) 
	ld	c,4 (ix)
	ld	b,5 (ix)
	push	bc
	pop	iy
	ld	l, 17 (iy)
;src/main.c:1166: if (pSpr->dir == D_right) {
	ld	a, c
	add	a, #0x08
	ld	e, a
	ld	a, b
	adc	a, #0x00
	ld	d, a
;src/main.c:1167: if (pSpr->x < pSpr->xMax) pSpr->x++;
	ld	a, c
	add	a, #0x0e
	ld	-2 (ix), a
	ld	a, b
	adc	a, #0x00
	ld	-1 (ix), a
;src/main.c:1171: if (pSpr->x > pSpr->xMin) pSpr->x--;
	ld	a, c
	add	a, #0x0d
	ld	-4 (ix), a
	ld	a, b
	adc	a, #0x00
	ld	-3 (ix), a
;src/main.c:1162: switch(pSpr->movType) 
	ld	a, l
	or	a, a
	jr	Z,00101$
;src/main.c:1179: if (pSpr->y < pSpr->yMax) pSpr->y += 2;
	ld	a, c
	add	a, #0x01
	ld	-6 (ix), a
	ld	a, b
	adc	a, #0x00
	ld	-5 (ix), a
	ld	iy, #0x0010
	add	iy, bc
;src/main.c:1183: if (pSpr->y > pSpr->yMin) pSpr->y -= 2;
	ld	a, c
	add	a, #0x0f
	ld	-8 (ix), a
	ld	a, b
	adc	a, #0x00
	ld	-7 (ix), a
;src/main.c:1162: switch(pSpr->movType) 
	ld	a, l
	dec	a
	jr	Z,00111$
	ld	a,l
	cp	a,#0x02
	jp	Z,00121$
	sub	a, #0x03
	jp	Z,00161$
	jp	00172$
;src/main.c:1165: case M_linear_X:
00101$:
;src/main.c:1166: if (pSpr->dir == D_right) {
	ld	a, (de)
;src/main.c:1167: if (pSpr->x < pSpr->xMax) pSpr->x++;
	push	af
	ld	a, (bc)
	ld	-9 (ix), a
	pop	af
;src/main.c:1166: if (pSpr->dir == D_right) {
	sub	a, #0x03
	jr	NZ,00109$
;src/main.c:1167: if (pSpr->x < pSpr->xMax) pSpr->x++;
	ld	l,-2 (ix)
	ld	h,-1 (ix)
	ld	a,-9 (ix)
	sub	a,(hl)
	jr	NC,00103$
	ld	a, -9 (ix)
	inc	a
	ld	(bc), a
	jp	00172$
00103$:
;src/main.c:1168: else pSpr->dir = D_left;
	ld	a, #0x02
	ld	(de), a
	jp	00172$
00109$:
;src/main.c:1171: if (pSpr->x > pSpr->xMin) pSpr->x--;
	ld	l,-4 (ix)
	ld	h,-3 (ix)
	ld	a, (hl)
	sub	a, -9 (ix)
	jr	NC,00106$
	ld	e, -9 (ix)
	dec	e
	ld	a, e
	ld	(bc), a
	jp	00172$
00106$:
;src/main.c:1172: else pSpr->dir = D_right; 
	ld	a, #0x03
	ld	(de), a
;src/main.c:1174: break;
	jp	00172$
;src/main.c:1177: case M_linear_Y:
00111$:
;src/main.c:1178: if (pSpr->dir == D_down) {
	ld	a, (de)
;src/main.c:1194: if (pSpr->y < pSpr->yMax && !OnPlatform(pSpr)) pSpr->y++;
	ld	l,-6 (ix)
	ld	h,-5 (ix)
	ld	c, (hl)
;src/main.c:1178: if (pSpr->dir == D_down) {
	dec	a
	jr	NZ,00119$
;src/main.c:1179: if (pSpr->y < pSpr->yMax) pSpr->y += 2;
	ld	b, 0 (iy)
	ld	a, c
	sub	a, b
	jr	NC,00113$
	inc	c
	inc	c
	ld	l,-6 (ix)
	ld	h,-5 (ix)
	ld	(hl), c
	jp	00172$
00113$:
;src/main.c:1180: else pSpr->dir = D_up;
	xor	a, a
	ld	(de), a
	jp	00172$
00119$:
;src/main.c:1183: if (pSpr->y > pSpr->yMin) pSpr->y -= 2;
	ld	l,-8 (ix)
	ld	h,-7 (ix)
	ld	a, (hl)
	sub	a, c
	jr	NC,00116$
	dec	c
	dec	c
	ld	l,-6 (ix)
	ld	h,-5 (ix)
	ld	(hl), c
	jp	00172$
00116$:
;src/main.c:1184: else pSpr->dir = D_down; 
	ld	a, #0x01
	ld	(de), a
;src/main.c:1186: break;
	jp	00172$
;src/main.c:1189: case M_diagonal:
00121$:
;src/main.c:1191: if (pSpr->dir == D_right_down || pSpr->dir == D_right) {
	ld	a, (de)
	cp	a, #0x07
	jr	Z,00157$
	cp	a, #0x03
	jr	NZ,00158$
00157$:
;src/main.c:1192: if (pSpr->x < pSpr->xMax) {
	ld	a, (bc)
	ld	l,-2 (ix)
	ld	h,-1 (ix)
	ld	l, (hl)
	cp	a, l
	jr	NC,00127$
;src/main.c:1193: pSpr->x++;					
	inc	a
	ld	(bc), a
;src/main.c:1194: if (pSpr->y < pSpr->yMax && !OnPlatform(pSpr)) pSpr->y++;
	ld	l,-6 (ix)
	ld	h,-5 (ix)
	ld	a, (hl)
	ld	l, 0 (iy)
	sub	a, l
	jr	NC,00123$
	push	de
	ld	l, c
	ld	h, b
	call	_OnPlatform
	pop	de
	ld	a, l
	or	a, a
	jr	NZ,00123$
	ld	l,-6 (ix)
	ld	h,-5 (ix)
	ld	c, (hl)
	inc	c
	ld	l,-6 (ix)
	ld	h,-5 (ix)
	ld	(hl), c
	jp	00172$
00123$:
;src/main.c:1195: else pSpr->dir = D_right_up;
	ld	a, #0x06
	ld	(de), a
	jp	00172$
00127$:
;src/main.c:1197: else pSpr->dir = D_left_down;
	ld	a, #0x05
	ld	(de), a
	jp	00172$
00158$:
;src/main.c:1200: else if (pSpr->dir == D_right_up) {
	cp	a, #0x06
	jr	NZ,00155$
;src/main.c:1201: if (pSpr->x < pSpr->xMax) {
	ld	a, (bc)
	ld	l,-2 (ix)
	ld	h,-1 (ix)
	ld	l, (hl)
	cp	a, l
	jr	NC,00133$
;src/main.c:1202: pSpr->x++;
	inc	a
	ld	(bc), a
;src/main.c:1203: if (pSpr->y > pSpr->yMin) pSpr->y--;
	ld	l,-6 (ix)
	ld	h,-5 (ix)
	ld	c, (hl)
	ld	l,-8 (ix)
	ld	h,-7 (ix)
	ld	a, (hl)
	sub	a, c
	jr	NC,00130$
	dec	c
	ld	l,-6 (ix)
	ld	h,-5 (ix)
	ld	(hl), c
	jp	00172$
00130$:
;src/main.c:1204: else pSpr->dir = D_right_down;
	ld	a, #0x07
	ld	(de), a
	jp	00172$
00133$:
;src/main.c:1206: else pSpr->dir = D_left_up;
	ld	a, #0x04
	ld	(de), a
	jp	00172$
00155$:
;src/main.c:1209: else if (pSpr->dir == D_left_up || pSpr->dir == D_left)	{
	cp	a, #0x04
	jr	Z,00150$
	cp	a, #0x02
	jr	NZ,00151$
00150$:
;src/main.c:1210: if (pSpr->x > pSpr->xMin) {
	ld	a, (bc)
	ld	-9 (ix), a
	ld	l,-4 (ix)
	ld	h,-3 (ix)
	ld	a, (hl)
	sub	a, -9 (ix)
	jr	NC,00139$
;src/main.c:1211: pSpr->x--;
	ld	a, -9 (ix)
	add	a, #0xff
	ld	(bc), a
;src/main.c:1212: if (pSpr->y > pSpr->yMin) pSpr->y--;
	ld	l,-6 (ix)
	ld	h,-5 (ix)
	ld	c, (hl)
	ld	l,-8 (ix)
	ld	h,-7 (ix)
	ld	a, (hl)
	sub	a, c
	jr	NC,00136$
	dec	c
	ld	l,-6 (ix)
	ld	h,-5 (ix)
	ld	(hl), c
	jp	00172$
00136$:
;src/main.c:1213: else pSpr->dir = D_left_down;
	ld	a, #0x05
	ld	(de), a
	jp	00172$
00139$:
;src/main.c:1215: else pSpr->dir = D_right_up; 
	ld	a, #0x06
	ld	(de), a
	jp	00172$
00151$:
;src/main.c:1218: else if (pSpr->dir == D_left_down) {
	sub	a, #0x05
	jp	NZ,00172$
;src/main.c:1219: if (pSpr->x > pSpr->xMin) {
	ld	a, (bc)
	ld	-9 (ix), a
	ld	l,-4 (ix)
	ld	h,-3 (ix)
	ld	a, (hl)
	sub	a, -9 (ix)
	jr	NC,00146$
;src/main.c:1220: pSpr->x--;
	ld	a, -9 (ix)
	add	a, #0xff
	ld	(bc), a
;src/main.c:1221: if (pSpr->y < pSpr->yMax && !OnPlatform(pSpr)) pSpr->y++;
	ld	l,-6 (ix)
	ld	h,-5 (ix)
	ld	a, (hl)
	ld	l, 0 (iy)
	sub	a, l
	jr	NC,00142$
	push	de
	ld	l, c
	ld	h, b
	call	_OnPlatform
	pop	de
	ld	a, l
	or	a, a
	jr	NZ,00142$
	ld	l,-6 (ix)
	ld	h,-5 (ix)
	ld	c, (hl)
	inc	c
	ld	l,-6 (ix)
	ld	h,-5 (ix)
	ld	(hl), c
	jr	00172$
00142$:
;src/main.c:1222: else pSpr->dir = D_left_up;
	ld	a, #0x04
	ld	(de), a
	jr	00172$
00146$:
;src/main.c:1224: else pSpr->dir = D_right_down;
	ld	a, #0x07
	ld	(de), a
;src/main.c:1226: break;
	jr	00172$
;src/main.c:1229: case M_chaser:
00161$:
;src/main.c:1230: if (ctMainLoop % 3 == 0) { // slow motion, moves one in three iterations
	push	bc
	push	de
	ld	a, #0x03
	push	af
	inc	sp
	ld	a, (_ctMainLoop)
	push	af
	inc	sp
	call	__moduchar
	pop	af
	pop	de
	pop	bc
	ld	a, l
	or	a, a
	jr	NZ,00172$
;src/main.c:1231: if (pSpr->x <= spr[0].x) { // is to the player's left
	ld	a, (bc)
	ld	-9 (ix), a
	ld	a, (#_spr+0)
	sub	a, -9 (ix)
	jr	C,00163$
;src/main.c:1232: pSpr->x++;
	ld	a, -9 (ix)
	inc	a
	ld	(bc), a
;src/main.c:1233: pSpr->dir = D_right;
	ld	a, #0x03
	ld	(de), a
	jr	00164$
00163$:
;src/main.c:1236: pSpr->x--;
	ld	a, -9 (ix)
	add	a, #0xff
	ld	(bc), a
;src/main.c:1237: pSpr->dir = D_left;
	ld	a, #0x02
	ld	(de), a
00164$:
;src/main.c:1194: if (pSpr->y < pSpr->yMax && !OnPlatform(pSpr)) pSpr->y++;
	ld	l,-6 (ix)
	ld	h,-5 (ix)
	ld	e, (hl)
;src/main.c:1240: if (pSpr->y <= spr[0].y && !OnPlatform(pSpr)) pSpr->y++;
	ld	a, (#_spr+1)
	sub	a, e
	jr	C,00166$
	ld	l, c
	ld	h, b
	call	_OnPlatform
	ld	a, l
;src/main.c:1194: if (pSpr->y < pSpr->yMax && !OnPlatform(pSpr)) pSpr->y++;
	ld	l,-6 (ix)
	ld	h,-5 (ix)
	ld	e, (hl)
;src/main.c:1240: if (pSpr->y <= spr[0].y && !OnPlatform(pSpr)) pSpr->y++;
	or	a, a
	jr	NZ,00166$
	inc	e
	ld	l,-6 (ix)
	ld	h,-5 (ix)
	ld	(hl), e
	jr	00172$
00166$:
;src/main.c:1241: else pSpr->y--; // is below the main sprite
	dec	e
	ld	l,-6 (ix)
	ld	h,-5 (ix)
	ld	(hl), e
;src/main.c:1244: }
00172$:
	ld	sp, ix
	pop	ix
	ret
;src/main.c:1249: void SetEnemyParams(u8 i, u8 ident, u8 mov, u8 lives, u8 dir, u8 x, u8 y, u8 xMin, u8 yMin, u8 xMax, u8 yMax) {
;	---------------------------------
; Function SetEnemyParams
; ---------------------------------
_SetEnemyParams::
	push	ix
	ld	ix,#0
	add	ix,sp
;src/main.c:1250: spr[i].status = S_walking;
	ld	bc, #_spr+0
	ld	e,4 (ix)
	ld	d,#0x00
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl,bc
	ld	c, l
	ld	b, h
	ld	hl, #0x0004
	add	hl, bc
	ld	(hl), #0x01
;src/main.c:1251: spr[i].ident = ident; 
	ld	hl, #0x0012
	add	hl, bc
	ld	a, 5 (ix)
	ld	(hl), a
;src/main.c:1252: spr[i].movType = mov;
	ld	hl, #0x0011
	add	hl, bc
	ld	a, 6 (ix)
	ld	(hl), a
;src/main.c:1253: spr[i].lives = lives; 
	ld	hl, #0x0009
	add	hl, bc
	ld	a, 7 (ix)
	ld	(hl), a
;src/main.c:1254: spr[i].dir = dir; 
	ld	hl, #0x0008
	add	hl, bc
	ld	a, 8 (ix)
	ld	(hl), a
;src/main.c:1255: spr[i].x = spr[i].px = x;
	ld	e, c
	ld	d, b
	inc	de
	inc	de
	ld	a, 9 (ix)
	ld	(de), a
	ld	a, 9 (ix)
	ld	(bc), a
;src/main.c:1256: spr[i].y = spr[i].py = y;
	ld	e, c
	ld	d, b
	inc	de
	ld	l, c
	ld	h, b
	inc	hl
	inc	hl
	inc	hl
	ld	a, 10 (ix)
	ld	(hl), a
	ld	a, 10 (ix)
	ld	(de), a
;src/main.c:1257: spr[i].xMin = xMin;
	ld	hl, #0x000d
	add	hl, bc
	ld	a, 11 (ix)
	ld	(hl), a
;src/main.c:1258: spr[i].yMin = yMin;
	ld	hl, #0x000f
	add	hl, bc
	ld	a, 12 (ix)
	ld	(hl), a
;src/main.c:1259: spr[i].xMax = xMax;
	ld	hl, #0x000e
	add	hl, bc
	ld	a, 13 (ix)
	ld	(hl), a
;src/main.c:1260: spr[i].yMax = yMax; 
	ld	hl, #0x0010
	add	hl, bc
	ld	a, 14 (ix)
	ld	(hl), a
;src/main.c:1261: spr[i].touched = 0;
	ld	hl, #0x000a
	add	hl, bc
	ld	(hl), #0x00
	pop	ix
	ret
;src/main.c:1271: void SetEnemies() {
;	---------------------------------
; Function SetEnemies
; ---------------------------------
_SetEnemies::
;src/main.c:1272: switch(mapNumber) {
	ld	iy, #_mapNumber
	ld	a, 0 (iy)
	or	a, a
	jr	Z,00101$
	ld	a, 0 (iy)
	dec	a
	jr	Z,00102$
	ld	a, 0 (iy)
	sub	a, #0x02
	jp	Z,00103$
	ret
;src/main.c:1273: case 0: { // upper left deck upper floor #3
00101$:
;src/main.c:1275: SetEnemyParams(1, ARACNOVIRUS, 	M_linear_Y, 	2,  D_right, 48,  64,   48,   64,   48,  160);
	ld	hl, #0xa030
	push	hl
	ld	h, #0x40
	push	hl
	ld	l, #0x30
	push	hl
	ld	hl, #0x0302
	push	hl
	ld	h, #0x01
	push	hl
	ld	a, #0x01
	push	af
	inc	sp
	call	_SetEnemyParams
	ld	hl, #11
	add	hl, sp
	ld	sp, hl
;src/main.c:1276: SetEnemyParams(2, INFECTED, 	M_linear_X, 	3,  D_right, 16, 160,    8,  160,   64,  160);
	ld	hl, #0xa040
	push	hl
	ld	l, #0x08
	push	hl
	ld	l, #0x10
	push	hl
	ld	hl, #0x0303
	push	hl
	ld	h, #0x00
	push	hl
	ld	a, #0x02
	push	af
	inc	sp
	call	_SetEnemyParams
	ld	hl, #11
	add	hl, sp
	ld	sp, hl
;src/main.c:1277: SetEnemyParams(3, ARACNOVIRUS,	M_linear_X,		0,  D_right,  0,   0,    0,    0,    0,    0);
	ld	hl, #0x0000
	push	hl
	ld	l, #0x00
	push	hl
	ld	l, #0x00
	push	hl
	ld	h, #0x03
	push	hl
	ld	hl, #0x0002
	push	hl
	ld	a, #0x03
	push	af
	inc	sp
	call	_SetEnemyParams
	ld	hl, #11
	add	hl, sp
	ld	sp, hl
;src/main.c:1279: cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk0_end);
	ld	hl, #(_mappk0 + 0x00e5)
	push	hl
	ld	hl, #0x1620
	push	hl
	call	_cpct_zx7b_decrunch_s
;src/main.c:1280: break;
	ret
;src/main.c:1282: case 1: { // upper left deck upper floor #2
00102$:
;src/main.c:1284: SetEnemyParams(1, PELUSOID,		M_diagonal, 	3,	D_right,  8,  52,    8,   52,   64,  160);
	ld	hl, #0xa040
	push	hl
	ld	hl, #0x3408
	push	hl
	ld	l, #0x08
	push	hl
	ld	hl, #0x0303
	push	hl
	ld	hl, #0x0201
	push	hl
	ld	a, #0x01
	push	af
	inc	sp
	call	_SetEnemyParams
	ld	hl, #11
	add	hl, sp
	ld	sp, hl
;src/main.c:1285: SetEnemyParams(2, PELUSOID, 	M_linear_Y, 	3,	D_right, 32,  52,   32,   52,   32,  160);		
	ld	hl, #0xa020
	push	hl
	ld	h, #0x34
	push	hl
	ld	l, #0x20
	push	hl
	ld	hl, #0x0303
	push	hl
	ld	hl, #0x0101
	push	hl
	ld	a, #0x02
	push	af
	inc	sp
	call	_SetEnemyParams
	ld	hl, #11
	add	hl, sp
	ld	sp, hl
;src/main.c:1286: SetEnemyParams(3, PELUSOID, 	M_linear_X,		0,	D_right,  0,   0,    0,    0,    0,    0);
	ld	hl, #0x0000
	push	hl
	ld	l, #0x00
	push	hl
	ld	l, #0x00
	push	hl
	ld	h, #0x03
	push	hl
	ld	hl, #0x0001
	push	hl
	ld	a, #0x03
	push	af
	inc	sp
	call	_SetEnemyParams
	ld	hl, #11
	add	hl, sp
	ld	sp, hl
;src/main.c:1288: cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk1_end);
	ld	hl, #(_mappk1 + 0x00d3)
	push	hl
	ld	hl, #0x1620
	push	hl
	call	_cpct_zx7b_decrunch_s
;src/main.c:1289: break;		
	ret
;src/main.c:1291: case 2: { // upper left deck upper floor #1
00103$:
;src/main.c:1293: SetEnemyParams(1, INFECTED,		M_linear_X,		2,	D_left, 32,  96,    8,   96,   64,   96);
	ld	hl, #0x6040
	push	hl
	ld	l, #0x08
	push	hl
	ld	l, #0x20
	push	hl
	ld	hl, #0x0202
	push	hl
	ld	hl, #0x0003
	push	hl
	ld	a, #0x01
	push	af
	inc	sp
	call	_SetEnemyParams
	ld	hl, #11
	add	hl, sp
	ld	sp, hl
;src/main.c:1294: SetEnemyParams(2, INFECTED, 	M_linear_X, 	2,	D_left, 64, 128,   16,  128,   64,  128);
	ld	hl, #0x8040
	push	hl
	ld	l, #0x10
	push	hl
	ld	l, #0x40
	push	hl
	ld	hl, #0x0202
	push	hl
	ld	hl, #0x0003
	push	hl
	ld	a, #0x02
	push	af
	inc	sp
	call	_SetEnemyParams
	ld	hl, #11
	add	hl, sp
	ld	sp, hl
;src/main.c:1295: SetEnemyParams(3, INFECTED, 	M_linear_X,		2,	D_right, 24, 160,   8,  160,   48,  160);
	ld	hl, #0xa030
	push	hl
	ld	l, #0x08
	push	hl
	ld	l, #0x18
	push	hl
	ld	hl, #0x0302
	push	hl
	ld	hl, #0x0003
	push	hl
	ld	a, #0x03
	push	af
	inc	sp
	call	_SetEnemyParams
	ld	hl, #11
	add	hl, sp
	ld	sp, hl
;src/main.c:1297: cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk2_end);
	ld	hl, #(_mappk2 + 0x00e1)
	push	hl
	ld	hl, #0x1620
	push	hl
	call	_cpct_zx7b_decrunch_s
;src/main.c:1299: }
	ret
;src/main.c:1304: void ExplosionSecuence(TSpr *pSpr) __z88dk_fastcall {
;	---------------------------------
; Function ExplosionSecuence
; ---------------------------------
_ExplosionSecuence::
	ld	c, l
	ld	b, h
;src/main.c:1305: if (pSpr->touched == 10) DeleteSprite(pSpr); 	
	ld	hl, #0x000a
	add	hl,bc
	ex	de,hl
	ld	a, (de)
	ld	l,a
	sub	a, #0x0a
	jr	NZ,00113$
	push	de
	ld	l, c
	ld	h, b
	call	_DeleteSprite
	pop	de
	jr	00114$
00113$:
;src/main.c:1306: else if (pSpr->touched > 8) PrintExplosion(pSpr, 0);
	ld	a, #0x08
	sub	a, l
	jr	NC,00110$
	push	de
	xor	a, a
	push	af
	inc	sp
	push	bc
	call	_PrintExplosion
	pop	af
	inc	sp
	pop	de
	jr	00114$
00110$:
;src/main.c:1307: else if (pSpr->touched > 6) PrintExplosion(pSpr, 1);
	ld	a, #0x06
	sub	a, l
	jr	NC,00107$
	push	de
	ld	a, #0x01
	push	af
	inc	sp
	push	bc
	call	_PrintExplosion
	pop	af
	inc	sp
	pop	de
	jr	00114$
00107$:
;src/main.c:1308: else if (pSpr->touched > 4) PrintExplosion(pSpr, 0);
	ld	a, #0x04
	sub	a, l
	jr	NC,00104$
	push	de
	xor	a, a
	push	af
	inc	sp
	push	bc
	call	_PrintExplosion
	pop	af
	inc	sp
	pop	de
	jr	00114$
00104$:
;src/main.c:1309: else if (pSpr->touched > 2) DeleteSprite(pSpr); 
	ld	a, #0x02
	sub	a, l
	jr	NC,00114$
	push	de
	ld	l, c
	ld	h, b
	call	_DeleteSprite
	pop	de
00114$:
;src/main.c:1310: pSpr->touched--;
	ld	a, (de)
	add	a, #0xff
	ld	(de), a
	ret
;src/main.c:1315: void EnemyLoop(TSpr *pSpr) __z88dk_fastcall {
;	---------------------------------
; Function EnemyLoop
; ---------------------------------
_EnemyLoop::
	push	ix
	ld	ix,#0
	add	ix,sp
	push	af
	ld	c, l
	ld	b, h
;src/main.c:1316: if (pSpr->lives >= 1) // If the enemy sprite is alive
	push	bc
	pop	iy
	ld	d, 9 (iy)
;src/main.c:1319: if (pSpr->touched == 0) 
	ld	hl, #0x000a
	add	hl,bc
	ex	(sp), hl
	pop	hl
	push	hl
	ld	e, (hl)
;src/main.c:1316: if (pSpr->lives >= 1) // If the enemy sprite is alive
	ld	a, d
	sub	a, #0x01
	jr	C,00111$
;src/main.c:1319: if (pSpr->touched == 0) 
	ld	a, e
	or	a, a
	jr	NZ,00102$
;src/main.c:1320: MoveEnemy(pSpr);
	push	bc
	push	bc
	call	_MoveEnemy
	pop	af
	pop	bc
00102$:
;src/main.c:1322: SelectSpriteFrame(pSpr); 
	push	bc
	ld	l, c
	ld	h, b
	call	_SelectSpriteFrame
	pop	bc
;src/main.c:1323: EnemyWalkAnim(pSpr);
	push	bc
	ld	l, c
	ld	h, b
	call	_EnemyWalkAnim
	pop	bc
;src/main.c:1325: DeleteSprite(pSpr);
	push	bc
	ld	l, c
	ld	h, b
	call	_DeleteSprite
	pop	bc
;src/main.c:1326: pSpr->px = pSpr->x; // save the current X coordinate
	ld	e, c
	ld	d, b
	inc	de
	inc	de
	ld	a, (bc)
	ld	(de), a
;src/main.c:1327: pSpr->py = pSpr->y; // save the current Y coordinate
	ld	e, c
	ld	d, b
	inc	de
	inc	de
	inc	de
	ld	l, c
	ld	h, b
	inc	hl
	ld	a, (hl)
	ld	(de), a
;src/main.c:1328: PrintSprite(pSpr);
	push	bc
	ld	l, c
	ld	h, b
	call	_PrintSprite
	pop	bc
;src/main.c:1330: CheckEnemyCollision(pSpr);
	push	bc
	push	bc
	call	_CheckEnemyCollision
	pop	af
	pop	bc
;src/main.c:1332: if (pSpr->touched > 0) 
	pop	hl
	push	hl
	ld	a, (hl)
	or	a, a
	jr	Z,00113$
;src/main.c:1333: ExplosionSecuence(pSpr);
	ld	l, c
	ld	h, b
	call	_ExplosionSecuence
	jr	00113$
00111$:
;src/main.c:1335: else if (pSpr->touched > 0) // enemy reached in his last life, will explode
	ld	a, e
	or	a, a
	jr	Z,00108$
;src/main.c:1337: ExplosionSecuence(pSpr);
	ld	l, c
	ld	h, b
	call	_ExplosionSecuence
	jr	00113$
00108$:
;src/main.c:1339: else if (pSpr->status == S_touched) // at this point it has died and exploded
	ld	hl, #0x0004
	add	hl, bc
	ld	a, (hl)
	sub	a, #0x08
	jr	NZ,00113$
;src/main.c:1341: pSpr->status = S_walking;		
	ld	(hl), #0x01
;src/main.c:1342: DeleteSprite(pSpr); 
	ld	l, c
	ld	h, b
	call	_DeleteSprite
00113$:
	ld	sp, ix
	pop	ix
	ret
;src/main.c:1351: void ExplodeEnemies()
;	---------------------------------
; Function ExplodeEnemies
; ---------------------------------
_ExplodeEnemies::
;src/main.c:1353: for (ct = 1; ct < 4; ct++)
	ld	hl,#_ct + 0
	ld	(hl), #0x01
	ld	bc, #_spr+0
00104$:
;src/main.c:1354: if (spr[ct].lives > 0)
	ld	de, (_ct)
	ld	d, #0x00
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, bc
	ld	de, #0x0009
	add	hl, de
	ld	a, (hl)
	or	a, a
	jp	Z, 00105$
;src/main.c:1356: cpct_akp_SFXPlay (4, 15, 40, 0, 0, AY_CHANNEL_A); // explosion
	push	bc
	ld	a, #0x01
	push	af
	inc	sp
	ld	hl, #0x0000
	push	hl
	ld	l, #0x28
	push	hl
	ld	hl, #0x0f04
	push	hl
	call	_cpct_akp_SFXPlay
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
	pop	bc
;src/main.c:1357: PrintExplosion(&spr[ct], 0); Pause(20);
	ld	de, (_ct)
	ld	d, #0x00
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, bc
	push	bc
	xor	a, a
	push	af
	inc	sp
	push	hl
	call	_PrintExplosion
	pop	af
	inc	sp
	ld	hl, #0x0014
	call	_Pause
	pop	bc
;src/main.c:1358: PrintExplosion(&spr[ct], 1); Pause(20);
	ld	de, (_ct)
	ld	d, #0x00
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, bc
	push	bc
	ld	a, #0x01
	push	af
	inc	sp
	push	hl
	call	_PrintExplosion
	pop	af
	inc	sp
	ld	hl, #0x0014
	call	_Pause
	pop	bc
;src/main.c:1359: PrintExplosion(&spr[ct], 0); Pause(20);
	ld	de, (_ct)
	ld	d, #0x00
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, bc
	push	bc
	xor	a, a
	push	af
	inc	sp
	push	hl
	call	_PrintExplosion
	pop	af
	inc	sp
	ld	hl, #0x0014
	call	_Pause
	pop	bc
;src/main.c:1360: spr[ct].lives = 0;
	ld	de, (_ct)
	ld	d, #0x00
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, bc
	ld	de, #0x0009
	add	hl, de
	ld	(hl), #0x00
;src/main.c:1361: spr[ct].status = S_walking;
	ld	de, (_ct)
	ld	d, #0x00
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, bc
	ld	de, #0x0004
	add	hl, de
	ld	(hl), #0x01
;src/main.c:1362: DeleteSprite(&spr[ct]);
	ld	de, (_ct)
	ld	d, #0x00
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, bc
	push	bc
	call	_DeleteSprite
	pop	bc
00105$:
;src/main.c:1353: for (ct = 1; ct < 4; ct++)
	ld	iy, #_ct
	inc	0 (iy)
	ld	a, 0 (iy)
	sub	a, #0x04
	jp	C, 00104$
	ret
;src/main.c:1385: void SetLC() 
;	---------------------------------
; Function SetLC
; ---------------------------------
_SetLC::
;src/main.c:1387: if (shotLC.active == FALSE) // if there is no laser shot on screen ...
	ld	hl, #_shotLC + 5
	ld	a, (hl)
	or	a, a
	ret	NZ
;src/main.c:1389: cpct_akp_SFXPlay(1, 15, 40, 0, 0, AY_CHANNEL_A);
	push	hl
	ld	a, #0x01
	push	af
	inc	sp
	ld	bc, #0x0000
	push	bc
	ld	bc, #0x0028
	push	bc
	ld	bc, #0x0f01
	push	bc
	call	_cpct_akp_SFXPlay
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
	pop	hl
;src/main.c:1390: shotLC.active = TRUE;
	ld	(hl), #0x01
;src/main.c:1392: shotLC.dir = lc[activeLC].dir;
	ld	bc, #_lc+0
	ld	de, (_activeLC)
	ld	d, #0x00
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, hl
	add	hl, de
	add	hl, bc
	ld	de, #0x0004
	add	hl, de
	ld	e, (hl)
	ld	hl, #(_shotLC + 0x0003)
	ld	(hl), e
;src/main.c:1394: shotLC.y = lc[activeLC].y + 4;
	push	de
	ld	de, (_activeLC)
	ld	d, #0x00
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, hl
	add	hl, de
	pop	de
	add	hl, bc
	inc	hl
	ld	a, (hl)
	add	a, #0x04
	ld	(#(_shotLC + 0x0002)),a
;src/main.c:1392: shotLC.dir = lc[activeLC].dir;
	push	de
	ld	de, (_activeLC)
	ld	d, #0x00
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, hl
	add	hl, de
	pop	de
;src/main.c:1397: shotLC.x = shotLC.px = lc[activeLC].x + SPR_W;
	add	hl, bc
	ld	c, (hl)
;src/main.c:1396: if (shotLC.dir == D_right)
	ld	a, e
	sub	a, #0x03
	jr	NZ,00102$
;src/main.c:1397: shotLC.x = shotLC.px = lc[activeLC].x + SPR_W;
	ld	a, c
	add	a, #0x08
	ld	(#(_shotLC + 0x0001)),a
	ld	(#_shotLC),a
	ret
00102$:
;src/main.c:1399: shotLC.x = shotLC.px = lc[activeLC].x - SPR_W;
	ld	a, c
	add	a, #0xf8
	ld	(#(_shotLC + 0x0001)),a
	ld	(#_shotLC),a
	ret
;src/main.c:1405: void GetLC() {
;	---------------------------------
; Function GetLC
; ---------------------------------
_GetLC::
;src/main.c:1406: ct = 0;
	ld	hl,#_ct + 0
	ld	(hl), #0x00
;src/main.c:1407: activeLC = 0;
	ld	hl,#_activeLC + 0
	ld	(hl), #0x00
;src/main.c:1409: while (ct < N_MAX_LC)	{
	ld	bc, #_lc+0
00103$:
	ld	a,(#_ct + 0)
	sub	a, #0x03
	ret	NC
;src/main.c:1410: if (lc[ct].mapNumber == mapNumber)	{
	ld	de, (_ct)
	ld	d, #0x00
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, hl
	add	hl, de
	add	hl, bc
	inc	hl
	inc	hl
	ld	e, (hl)
	ld	a,(#_mapNumber + 0)
	sub	a, e
	jr	NZ,00102$
;src/main.c:1411: activeLC = ct;
	ld	a,(#_ct + 0)
	ld	(#_activeLC + 0),a
;src/main.c:1412: break;
	ret
00102$:
;src/main.c:1414: ct++;
	ld	hl, #_ct+0
	inc	(hl)
	jr	00103$
;src/main.c:1431: void InitLC()
;	---------------------------------
; Function InitLC
; ---------------------------------
_InitLC::
;src/main.c:1422: lc[LCNum].x = x; 
	ld	hl, #_lc
	ld	(hl), #0x00
;src/main.c:1423: lc[LCNum].y = y;
	ld	hl, #(_lc + 0x0001)
	ld	(hl), #0x00
;src/main.c:1424: lc[LCNum].mapNumber = mapNum;
	ld	hl, #(_lc + 0x0002)
	ld	(hl), #0xff
;src/main.c:1425: lc[LCNum].dir = dir;
	ld	hl, #(_lc + 0x0004)
	ld	(hl), #0x03
;src/main.c:1422: lc[LCNum].x = x; 
	ld	hl, #(_lc + 0x0005)
	ld	(hl), #0x0c
;src/main.c:1423: lc[LCNum].y = y;
	ld	hl, #(_lc + 0x0006)
	ld	(hl), #0x80
;src/main.c:1424: lc[LCNum].mapNumber = mapNum;
	ld	hl, #(_lc + 0x0007)
	ld	(hl), #0x00
;src/main.c:1425: lc[LCNum].dir = dir;
	ld	hl, #(_lc + 0x0009)
	ld	(hl), #0x03
;src/main.c:1422: lc[LCNum].x = x; 
	ld	hl, #(_lc + 0x000a)
	ld	(hl), #0x36
;src/main.c:1423: lc[LCNum].y = y;
	ld	hl, #(_lc + 0x000b)
	ld	(hl), #0x3c
;src/main.c:1424: lc[LCNum].mapNumber = mapNum;
	ld	hl, #(_lc + 0x000c)
	ld	(hl), #0x01
;src/main.c:1425: lc[LCNum].dir = dir;
	ld	hl, #(_lc + 0x000e)
	ld	(hl), #0x02
;src/main.c:1436: SetParamLC(2, 54,  60,   1, D_left);
	ret
;src/main.c:1441: void CheckLCCollisions()
;	---------------------------------
; Function CheckLCCollisions
; ---------------------------------
_CheckLCCollisions::
	push	ix
	ld	ix,#0
	add	ix,sp
	push	af
;src/main.c:1443: if ((shotLC.x + SPR_W) > (spr[0].x + 4) && shotLC.x < (spr[0].x + SPR_W))
	ld	hl, #_shotLC+0
	ld	c, (hl)
	ld	b, #0x00
	ld	hl, #0x0008
	add	hl,bc
	ex	(sp), hl
	ld	hl, #_spr+0
	ld	e, (hl)
	ld	d, #0x00
	ld	hl, #0x0004
	add	hl, de
	ld	a, l
	sub	a, -2 (ix)
	ld	a, h
	sbc	a, -1 (ix)
	jp	PO, 00125$
	xor	a, #0x80
00125$:
	jp	P, 00107$
	ld	hl, #0x0008
	add	hl, de
	ld	a, c
	sub	a, l
	ld	a, b
	sbc	a, h
	jp	PO, 00126$
	xor	a, #0x80
00126$:
	jp	P, 00107$
;src/main.c:1444: if ((shotLC.y + SPR_H) > (spr[0].y - 1) && (shotLC.y - 1) < (spr[0].y + SPR_H))
	ld	hl, #_shotLC + 2
	ld	c, (hl)
	ld	b, #0x00
	ld	hl, #0x0010
	add	hl,bc
	ex	(sp), hl
	ld	hl, #_spr + 1
	ld	e, (hl)
	ld	d, #0x00
	ld	l, e
	ld	h, d
	dec	hl
	ld	a, l
	sub	a, -2 (ix)
	ld	a, h
	sbc	a, -1 (ix)
	jp	PO, 00127$
	xor	a, #0x80
00127$:
	jp	P, 00107$
	dec	bc
	ld	hl, #0x0010
	add	hl, de
	ld	a, c
	sub	a, l
	ld	a, b
	sbc	a, h
	jp	PO, 00128$
	xor	a, #0x80
00128$:
	jp	P, 00107$
;src/main.c:1447: shotLC.active = FALSE;
	ld	hl, #(_shotLC + 0x0005)
	ld	(hl), #0x00
;src/main.c:1448: spr[0].lives--;
	ld	hl, #_spr + 9
	ld	c, (hl)
	dec	c
	ld	(hl), c
;src/main.c:1449: ExplodePlayer();
	call	_ExplodePlayer
;src/main.c:1450: ExplodeEnemies();
	call	_ExplodeEnemies
;src/main.c:1451: GameOver();
	call	_GameOver
00107$:
	ld	sp, ix
	pop	ix
	ret
;src/main.c:1472: void PrintStartMenu() {
;	---------------------------------
; Function PrintStartMenu
; ---------------------------------
_PrintStartMenu::
;src/main.c:1473: cpct_drawSprite(g_logo, cpctm_screenPtr(CPCT_VMEM_START, 17, 0), G_LOGO_W, G_LOGO_H);
	ld	hl, #0x162e
	push	hl
	ld	hl, #0xc011
	push	hl
	ld	hl, #_g_logo
	push	hl
	call	_cpct_drawSprite
;src/main.c:1475: PrintText("1@START@GAME", 2, 45);
	ld	hl, #0x2d02
	push	hl
	ld	hl, #___str_4
	push	hl
	call	_PrintText
	pop	af
;src/main.c:1476: PrintText("2@REDEFINE@CONTROLS", 2, 60);
	ld	hl, #0x3c02
	ex	(sp),hl
	ld	hl, #___str_5
	push	hl
	call	_PrintText
	pop	af
;src/main.c:1478: PrintText("SALVAKANTERO", 16,140);
	ld	hl, #0x8c10
	ex	(sp),hl
	ld	hl, #___str_6
	push	hl
	call	_PrintText
	pop	af
;src/main.c:1479: PrintText("FELIPE@VAKAPP", 14, 155);
	ld	hl, #0x9b0e
	ex	(sp),hl
	ld	hl, #___str_7
	push	hl
	call	_PrintText
	pop	af
;src/main.c:1480: PrintText("TACHA", 29,170);
	ld	hl, #0xaa1d
	ex	(sp),hl
	ld	hl, #___str_8
	push	hl
	call	_PrintText
	pop	af
;src/main.c:1482: PrintText("PLAY@ON@RETRO@2022", 4, 191);
	ld	hl, #0xbf04
	ex	(sp),hl
	ld	hl, #___str_9
	push	hl
	call	_PrintText
	pop	af
	pop	af
	ret
___str_4:
	.ascii "1@START@GAME"
	.db 0x00
___str_5:
	.ascii "2@REDEFINE@CONTROLS"
	.db 0x00
___str_6:
	.ascii "SALVAKANTERO"
	.db 0x00
___str_7:
	.ascii "FELIPE@VAKAPP"
	.db 0x00
___str_8:
	.ascii "TACHA"
	.db 0x00
___str_9:
	.ascii "PLAY@ON@RETRO@2022"
	.db 0x00
;src/main.c:1486: void StartMenu() {
;	---------------------------------
; Function StartMenu
; ---------------------------------
_StartMenu::
;src/main.c:1487: cpct_akp_musicInit(Menu); // initialize music. Main theme 
	ld	hl, #_Menu
	push	hl
	call	_cpct_akp_musicInit
	pop	af
;src/main.c:1488: ClearScreen();
	call	_ClearScreen
;src/main.c:1489: PrintStartMenu();
	call	_PrintStartMenu
;src/main.c:1491: while(1) {
00107$:
;src/main.c:1492: cpct_scanKeyboard_f();
	call	_cpct_scanKeyboard_f
;src/main.c:1494: if(cpct_isKeyPressed(Key_1)) { // start game
	ld	hl, #0x0108
	call	_cpct_isKeyPressed
	ld	a, l
	or	a, a
	jr	NZ,00108$
;src/main.c:1497: else if(cpct_isKeyPressed(Key_2)){ // redefine keys
	ld	hl, #0x0208
	call	_cpct_isKeyPressed
	ld	a, l
	or	a, a
	jr	Z,00105$
;src/main.c:1498: Wait4Key(Key_2);
	ld	hl, #0x0208
	call	_Wait4Key
;src/main.c:1499: ctlUp = 	RedefineKey("@@UP@");
	ld	hl, #___str_10
	call	_RedefineKey
	ld	(_ctlUp), hl
;src/main.c:1500: ctlDown = 	RedefineKey("@DOWN");
	ld	hl, #___str_11
	call	_RedefineKey
	ld	(_ctlDown), hl
;src/main.c:1501: ctlLeft = 	RedefineKey("@LEFT");
	ld	hl, #___str_12
	call	_RedefineKey
	ld	(_ctlLeft), hl
;src/main.c:1502: ctlRight = 	RedefineKey("RIGHT");
	ld	hl, #___str_13
	call	_RedefineKey
	ld	(_ctlRight), hl
;src/main.c:1503: ctlFire = 	RedefineKey("@FIRE");
	ld	hl, #___str_14
	call	_RedefineKey
	ld	(_ctlFire), hl
;src/main.c:1504: ctlAbort = 	RedefineKey("ABORT");
	ld	hl, #___str_15
	call	_RedefineKey
	ld	(_ctlAbort), hl
;src/main.c:1505: ctlMusic = 	RedefineKey("MUSIC");
	ld	hl, #___str_16
	call	_RedefineKey
	ld	(_ctlMusic), hl
;src/main.c:1506: ctlPause =	RedefineKey("PAUSE");		
	ld	hl, #___str_17
	call	_RedefineKey
	ld	(_ctlPause), hl
;src/main.c:1508: PrintText("@@@@@", 29, 100);
	ld	hl, #0x641d
	push	hl
	ld	hl, #___str_18
	push	hl
	call	_PrintText
	pop	af
	pop	af
00105$:
;src/main.c:1510: Pause(3);
	ld	hl, #0x0003
	call	_Pause
	jr	00107$
00108$:
;src/main.c:1513: cpct_akp_musicInit(FX);
	ld	hl, #_FX
	push	hl
	call	_cpct_akp_musicInit
;src/main.c:1514: cpct_akp_SFXPlay (6, 14, 41, 0, 0, AY_CHANNEL_B); // event sound
	ld	h,#0x02
	ex	(sp),hl
	inc	sp
	ld	hl, #0x0000
	push	hl
	ld	l, #0x29
	push	hl
	ld	hl, #0x0e06
	push	hl
	call	_cpct_akp_SFXPlay
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
;src/main.c:1515: ClearScreen();
	call	_ClearScreen
;src/main.c:1517: PrintText("SCAPE@FROM@MARS?", 9, 86);
	ld	hl, #0x5609
	push	hl
	ld	hl, #___str_19
	push	hl
	call	_PrintText
	pop	af
	pop	af
;src/main.c:1518: Pause(300);
	ld	hl, #0x012c
	call	_Pause
;src/main.c:1520: cpct_akp_musicInit(Ingame1);
	ld	hl, #_Ingame1
	push	hl
	call	_cpct_akp_musicInit
	pop	af
	ret
___str_10:
	.ascii "@@UP@"
	.db 0x00
___str_11:
	.ascii "@DOWN"
	.db 0x00
___str_12:
	.ascii "@LEFT"
	.db 0x00
___str_13:
	.ascii "RIGHT"
	.db 0x00
___str_14:
	.ascii "@FIRE"
	.db 0x00
___str_15:
	.ascii "ABORT"
	.db 0x00
___str_16:
	.ascii "MUSIC"
	.db 0x00
___str_17:
	.ascii "PAUSE"
	.db 0x00
___str_18:
	.ascii "@@@@@"
	.db 0x00
___str_19:
	.ascii "SCAPE@FROM@MARS?"
	.db 0x00
;src/main.c:1541: void InitValues() {	
;	---------------------------------
; Function InitValues
; ---------------------------------
_InitValues::
;src/main.c:1543: ctlUp = Key_Q;
	ld	hl, #0x0808
	ld	(_ctlUp), hl
;src/main.c:1544: ctlDown = Key_A;
	ld	h, #0x20
	ld	(_ctlDown), hl
;src/main.c:1545: ctlLeft = Key_O;
	ld	hl, #0x0404
	ld	(_ctlLeft), hl
;src/main.c:1546: ctlRight = Key_P;
	ld	hl, #0x0803
	ld	(_ctlRight), hl
;src/main.c:1547: ctlFire = Key_Space;
	ld	hl, #0x8005
	ld	(_ctlFire), hl
;src/main.c:1548: ctlAbort = Key_X;
	ld	l, #0x07
	ld	(_ctlAbort), hl
;src/main.c:1549: ctlMusic = Key_M;
	ld	hl, #0x4004
	ld	(_ctlMusic), hl
;src/main.c:1550: ctlPause = Key_H;	
	ld	hl, #0x1005
	ld	(_ctlPause), hl
	ret
;src/main.c:1555: void ResetData() {
;	---------------------------------
; Function ResetData
; ---------------------------------
_ResetData::
;src/main.c:1557: shot.active = FALSE; 
	ld	hl, #(_shot + 0x0005)
	ld	(hl), #0x00
;src/main.c:1558: shotLC.active = FALSE;
	ld	hl, #(_shotLC + 0x0005)
	ld	(hl), #0x00
;src/main.c:1560: spr[0].x = spr[0].px = 0;
	ld	hl, #(_spr + 0x0002)
	ld	(hl), #0x00
	ld	hl, #_spr
	ld	(hl), #0x00
;src/main.c:1561: spr[0].y = spr[0].py = 159;
	ld	hl, #(_spr + 0x0003)
	ld	(hl), #0x9f
	ld	hl, #(_spr + 0x0001)
	ld	(hl), #0x9f
;src/main.c:1562: spr[0].dir = D_right; 
	ld	hl, #(_spr + 0x0008)
	ld	(hl), #0x03
;src/main.c:1563: spr[0].status = S_stopped;
	ld	hl, #(_spr + 0x0004)
	ld	(hl), #0x00
;src/main.c:1565: InitMap();
	call	_InitMap
;src/main.c:1566: RefreshScoreboard();
	jp  _RefreshScoreboard
;src/main.c:1571: void InitGame() {
;	---------------------------------
; Function InitGame
; ---------------------------------
_InitGame::
;src/main.c:1572: StartMenu(); // start menu;
	call	_StartMenu
;src/main.c:1573: music = TRUE;
	ld	hl,#_music + 0
	ld	(hl), #0x01
;src/main.c:1574: mapNumber = 0;
	ld	hl,#_mapNumber + 0
	ld	(hl), #0x00
;src/main.c:1575: score = 0;
	ld	hl, #0x0000
	ld	(_score), hl
;src/main.c:1576: ammo= 99;
	ld	hl,#_ammo + 0
	ld	(hl), #0x63
;src/main.c:1577: activeLC = 1; // temp fix
	ld	hl,#_activeLC + 0
	ld	(hl), #0x01
;src/main.c:1580: spr[0].object = 255; // no object
	ld	hl, #(_spr + 0x000c)
	ld	(hl), #0xff
;src/main.c:1581: spr[0].lives = 9; // 10 lives
	ld	hl, #(_spr + 0x0009)
	ld	(hl), #0x09
;src/main.c:1584: InitScoreboard();
	call	_InitScoreboard
;src/main.c:1587: InitObjects();
	call	_InitObjects
;src/main.c:1589: InitLC();
	call	_InitLC
;src/main.c:1591: ResetData();
	jp  _ResetData
;src/main.c:1596: void GameOver() {
;	---------------------------------
; Function GameOver
; ---------------------------------
_GameOver::
;src/main.c:1598: if (spr[0].lives > 0) 
	ld	a, (#(_spr + 0x0009) + 0)
	or	a, a
;src/main.c:1599: ResetData(); // reassign data to some variables
	jp	NZ,_ResetData
;src/main.c:1601: cpct_akp_musicInit(FX); // stop the music
	ld	hl, #_FX
	push	hl
	call	_cpct_akp_musicInit
	pop	af
;src/main.c:1602: RefreshScoreboard();
	call	_RefreshScoreboard
;src/main.c:1604: PrintText("@@@@@@@@@@@", 18, 102);
	ld	hl, #0x6612
	push	hl
	ld	hl, #___str_20
	push	hl
	call	_PrintText
	pop	af
;src/main.c:1605: PrintText("@GAME@OVER@", 18, 110);
	ld	hl, #0x6e12
	ex	(sp),hl
	ld	hl, #___str_21
	push	hl
	call	_PrintText
	pop	af
;src/main.c:1606: PrintText("@@@@@@@@@@@", 18, 118);
	ld	hl, #0x7612
	ex	(sp),hl
	ld	hl, #___str_20
	push	hl
	call	_PrintText
	pop	af
	pop	af
;src/main.c:1607: Pause(500);
	ld	hl, #0x01f4
	call	_Pause
;src/main.c:1609: while (!cpct_isAnyKeyPressed());
00101$:
	call	_cpct_isAnyKeyPressed
	ld	a, l
	or	a, a
	jr	Z,00101$
;src/main.c:1610: InitGame();
	jp  _InitGame
___str_20:
	.ascii "@@@@@@@@@@@"
	.db 0x00
___str_21:
	.ascii "@GAME@OVER@"
	.db 0x00
;src/main.c:1615: void MainLoop() {
;	---------------------------------
; Function MainLoop
; ---------------------------------
_MainLoop::
;src/main.c:1616: cpct_disableFirmware(); // disable firmware control
	call	_cpct_disableFirmware
;src/main.c:1617: cpct_akp_SFXInit(FX); //initialize sound effects
	ld	hl, #_FX
	push	hl
	call	_cpct_akp_SFXInit
	pop	af
;src/main.c:1618: cpct_setInterruptHandler(Interrupt); // initialize the interrupt manager (keyboard and sound)
	ld	hl, #_Interrupt
	call	_cpct_setInterruptHandler
;src/main.c:1619: cpct_setVideoMode(0); // activate mode 0; 160*200 16 colors
	ld	l, #0x00
	call	_cpct_setVideoMode
;src/main.c:1620: cpct_setPalette(g_palette, 16); // assign palette
	ld	hl, #0x0010
	push	hl
	ld	hl, #_g_palette
	push	hl
	call	_cpct_setPalette
;src/main.c:1621: cpct_setBorder(g_palette[1]); // print border (black)
	ld	hl, #_g_palette + 1
	ld	b, (hl)
	push	bc
	inc	sp
	ld	a, #0x10
	push	af
	inc	sp
	call	_cpct_setPALColour
;src/main.c:1622: cpct_etm_setTileset2x4(g_tileset); // keep in memory the tiles for the maps (4 * 4)		
	ld	hl, #_g_tileset
	call	_cpct_etm_setTileset2x4
;src/main.c:1623: InitValues(); // assigns default values ​​that do not vary between games
	call	_InitValues
;src/main.c:1624: InitGame(); // initialization of some variables
	call	_InitGame
;src/main.c:1626: while (1) { // main loop		
00116$:
;src/main.c:1628: ReprintObjects();
	call	_ReprintObjects
;src/main.c:1630: RunStatus(); // call the appropriate function according to the player status  
	call	_RunStatus
;src/main.c:1631: SelectFrame(); // we assign the next frame of the animation to the player
	call	_SelectFrame
;src/main.c:1632: DeleteSprite(&spr[0]);
	ld	hl, #_spr
	call	_DeleteSprite
;src/main.c:1633: spr[0].px = spr[0].x; // save the current X coordinate
	ld	bc, #_spr + 2
	ld	a, (#_spr + 0)
	ld	(bc), a
;src/main.c:1634: spr[0].py = spr[0].y; // save the current Y coordinate
	ld	bc, #_spr + 3
	ld	a, (#(_spr + 0x0001) + 0)
	ld	(bc), a
;src/main.c:1635: PrintSprite(&spr[0]); // prints the player in the new XY position
	ld	hl, #_spr
	call	_PrintSprite
;src/main.c:1637: if (OverMines()) { // the player is stepping on mines?
	call	_OverMines
	ld	a, l
	or	a, a
	jr	Z,00102$
;src/main.c:1638: spr[0].lives--;
	ld	hl, #_spr + 9
	ld	c, (hl)
	dec	c
	ld	(hl), c
;src/main.c:1639: ExplodePlayer();
	call	_ExplodePlayer
;src/main.c:1640: ExplodeEnemies();
	call	_ExplodeEnemies
;src/main.c:1641: GameOver();
	call	_GameOver
00102$:
;src/main.c:1645: if (activeLC > 0 && spr[0].y >= lc[activeLC].y - 5 && spr[0].y <= lc[activeLC].y + 5)
	ld	a,(#_activeLC + 0)
	or	a, a
	jr	Z,00104$
	ld	hl, #(_spr + 0x0001) + 0
	ld	c, (hl)
	ld	de, (_activeLC)
	ld	d, #0x00
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, hl
	add	hl, de
	ld	de, #_lc
	add	hl, de
	inc	hl
	ld	e, (hl)
	ld	d, #0x00
	ld	a, e
	add	a, #0xfb
	ld	l, a
	ld	a, d
	adc	a, #0xff
	ld	h, a
	ld	b, #0x00
	ld	a, c
	sub	a, l
	ld	a, b
	sbc	a, h
	jp	PO, 00156$
	xor	a, #0x80
00156$:
	jp	M, 00104$
	ld	hl, #0x0005
	add	hl, de
	ld	a, l
	sub	a, c
	ld	a, h
	sbc	a, b
	jp	PO, 00157$
	xor	a, #0x80
00157$:
	jp	M, 00104$
;src/main.c:1646: SetLC();
	call	_SetLC
00104$:
;src/main.c:1648: EnemyLoop(&spr[1]);
	ld	hl, #(_spr + 0x0013)
	call	_EnemyLoop
;src/main.c:1649: EnemyLoop(&spr[2]);
	ld	hl, #(_spr + 0x0026)
	call	_EnemyLoop
;src/main.c:1650: EnemyLoop(&spr[3]);
	ld	hl, #(_spr + 0x0039)
	call	_EnemyLoop
;src/main.c:1653: if (shot.active == TRUE)
	ld	a, (#_shot + 5)
	dec	a
	jr	NZ,00108$
;src/main.c:1655: MoveShot(&shot, 2); // update XY coordinates of bullet if fired
	ld	a, #0x02
	push	af
	inc	sp
	ld	hl, #_shot
	push	hl
	call	_MoveShot
	pop	af
	inc	sp
;src/main.c:1656: PrintShot(&shot, spr[0].dir - 2); // delete the shot and prints it in the new XY position
	ld	hl, #_spr + 8
	ld	b, (hl)
	dec	b
	dec	b
	push	bc
	inc	sp
	ld	hl, #_shot
	push	hl
	call	_PrintShot
	pop	af
	inc	sp
00108$:
;src/main.c:1660: if (shotLC.active == TRUE)
	ld	a, (#_shotLC + 5)
	dec	a
	jr	NZ,00110$
;src/main.c:1662: MoveShot(&shotLC, 1); // update XY coordinates of of laser if fired
	ld	a, #0x01
	push	af
	inc	sp
	ld	hl, #_shotLC
	push	hl
	call	_MoveShot
	pop	af
	inc	sp
;src/main.c:1663: PrintShot(&shotLC, 2); // delete the laser and prints it in the new XY position
	ld	a, #0x02
	push	af
	inc	sp
	ld	hl, #_shotLC
	push	hl
	call	_PrintShot
	pop	af
	inc	sp
;src/main.c:1664: CheckLCCollisions();
	call	_CheckLCCollisions
00110$:
;src/main.c:1667: if (ctMainLoop % 15 == 0) // reprint scoreboard data
	ld	a, #0x0f
	push	af
	inc	sp
	ld	a, (_ctMainLoop)
	push	af
	inc	sp
	call	__moduchar
	pop	af
	ld	a, l
	or	a, a
	jr	NZ,00112$
;src/main.c:1668: RefreshScoreboard();	
	call	_RefreshScoreboard
00112$:
;src/main.c:1670: cpct_waitVSYNC(); // wait for vertical retrace
	call	_cpct_waitVSYNC
;src/main.c:1672: if (++ctMainLoop == 255) ctMainLoop = 0;
	ld	iy, #_ctMainLoop
	inc	0 (iy)
	ld	a, 0 (iy)
	inc	a
	jp	NZ,00116$
	ld	0 (iy), #0x00
	jp	00116$
;src/main.c:1682: void main(void) 
;	---------------------------------
; Function main
; ---------------------------------
_main::
;src/main.c:1686: MainLoop();   
	jp  _MainLoop
	.area _CODE
	.area _INITIALIZER
__xinit__mapNumber:
	.db #0x00	; 0
	.area _CABS (ABS)
