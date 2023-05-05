                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.6.8 #9946 (CYGWIN)
                              4 ;--------------------------------------------------------
                              5 	.module main
                              6 	.optsdcc -mz80
                              7 	
                              8 ;--------------------------------------------------------
                              9 ; Public variables in this module
                             10 ;--------------------------------------------------------
                             11 	.globl _main
                             12 	.globl _MainLoop
                             13 	.globl _InitGame
                             14 	.globl _ResetData
                             15 	.globl _InitValues
                             16 	.globl _StartMenu
                             17 	.globl _PrintStartMenu
                             18 	.globl _CheckLCCollisions
                             19 	.globl _InitLC
                             20 	.globl _SetLC
                             21 	.globl _EnemyLoop
                             22 	.globl _ExplosionSecuence
                             23 	.globl _SetEnemyParams
                             24 	.globl _MoveEnemy
                             25 	.globl _MoveShot
                             26 	.globl _PrintShot
                             27 	.globl _RunStatus
                             28 	.globl _Climbing
                             29 	.globl _Walking
                             30 	.globl _WalkAnim
                             31 	.globl _PreJump
                             32 	.globl _Jumping
                             33 	.globl _JumpIn
                             34 	.globl _Stopped
                             35 	.globl _StopIn
                             36 	.globl _Falling
                             37 	.globl _PreShotIn
                             38 	.globl _LandIn
                             39 	.globl _FallIn
                             40 	.globl _PreJumpIn
                             41 	.globl _ClimbIn
                             42 	.globl _WalkIn
                             43 	.globl _MoveRight
                             44 	.globl _MoveLeft
                             45 	.globl _MoveDown
                             46 	.globl _MoveUp
                             47 	.globl _SelectFrame
                             48 	.globl _AssignFrame
                             49 	.globl _CheckEnemyCollision
                             50 	.globl _EnemyWalkAnim
                             51 	.globl _SelectSpriteFrame
                             52 	.globl _PrintExplosion
                             53 	.globl _DeleteSprite
                             54 	.globl _PrintSprite
                             55 	.globl _InitObjects
                             56 	.globl _CheckObjects
                             57 	.globl _ReprintObjects
                             58 	.globl _DeleteObjectScoreboard
                             59 	.globl _DeleteObject
                             60 	.globl _PrintObject
                             61 	.globl _RedefineKey
                             62 	.globl _Wait4Key
                             63 	.globl _ReturnKeyPressed
                             64 	.globl _FacingWall
                             65 	.globl _OverMines
                             66 	.globl _OnStairs
                             67 	.globl _OnPlatform
                             68 	.globl _GetTilePtr
                             69 	.globl _MoveLeftMap
                             70 	.globl _MoveRightMap
                             71 	.globl _InitMap
                             72 	.globl _PrintMap
                             73 	.globl _RefreshScoreboard
                             74 	.globl _InitScoreboard
                             75 	.globl _PrintText
                             76 	.globl _PrintNumber
                             77 	.globl _ClearScreen
                             78 	.globl _Interrupt
                             79 	.globl _PlayMusic
                             80 	.globl _Pause
                             81 	.globl _Itoa
                             82 	.globl _Strlen
                             83 	.globl _cpct_zx7b_decrunch_s
                             84 	.globl _cpct_etm_setTileset2x4
                             85 	.globl _cpct_etm_drawTileBox2x4
                             86 	.globl _cpct_akp_SFXPlay
                             87 	.globl _cpct_akp_SFXInit
                             88 	.globl _cpct_akp_musicInit
                             89 	.globl _cpct_getScreenPtr
                             90 	.globl _cpct_setPALColour
                             91 	.globl _cpct_setPalette
                             92 	.globl _cpct_waitVSYNC
                             93 	.globl _cpct_setVideoMode
                             94 	.globl _cpct_drawSpriteMaskedAlignedTable
                             95 	.globl _cpct_drawSprite
                             96 	.globl _cpct_drawSolidBox
                             97 	.globl _cpct_px2byteM0
                             98 	.globl _cpct_hflipSpriteM0
                             99 	.globl _cpct_get2Bits
                            100 	.globl _cpct_isAnyKeyPressed
                            101 	.globl _cpct_isKeyPressed
                            102 	.globl _cpct_scanKeyboard_if
                            103 	.globl _cpct_scanKeyboard_f
                            104 	.globl _cpct_scanKeyboard
                            105 	.globl _cpct_memset
                            106 	.globl _cpct_setInterruptHandler
                            107 	.globl _cpct_disableFirmware
                            108 	.globl _mapNumber
                            109 	.globl _enum_mov
                            110 	.globl _enum_sta
                            111 	.globl _enum_dir
                            112 	.globl _obj
                            113 	.globl _lc
                            114 	.globl _activeLC
                            115 	.globl _shotLC
                            116 	.globl _shot
                            117 	.globl _spr
                            118 	.globl _ctlPause
                            119 	.globl _ctlAbort
                            120 	.globl _ctlMusic
                            121 	.globl _ctlFire
                            122 	.globl _ctlRight
                            123 	.globl _ctlLeft
                            124 	.globl _ctlDown
                            125 	.globl _ctlUp
                            126 	.globl _ct
                            127 	.globl _ctMainLoop
                            128 	.globl _music
                            129 	.globl _ammo
                            130 	.globl _highScore
                            131 	.globl _score
                            132 	.globl _g_jumpTable
                            133 	.globl _anim_infected
                            134 	.globl _anim_aracnovirus
                            135 	.globl _anim_pelusoid
                            136 	.globl _frm_infected
                            137 	.globl _frm_aracnovirus
                            138 	.globl _frm_pelusoid
                            139 	.globl _animClimb
                            140 	.globl _animWalk
                            141 	.globl _frm_player
                            142 	.globl _mapTitle
                            143 	.globl _ExplodePlayer
                            144 	.globl _DeleteShot
                            145 	.globl _SetEnemies
                            146 	.globl _ExplodeEnemies
                            147 	.globl _GetLC
                            148 	.globl _GameOver
                            149 ;--------------------------------------------------------
                            150 ; special function registers
                            151 ;--------------------------------------------------------
                            152 ;--------------------------------------------------------
                            153 ; ram data
                            154 ;--------------------------------------------------------
                            155 	.area _DATA
   4BAB                     156 _score::
   4BAB                     157 	.ds 2
   4BAD                     158 _highScore::
   4BAD                     159 	.ds 2
   4BAF                     160 _ammo::
   4BAF                     161 	.ds 1
   4BB0                     162 _music::
   4BB0                     163 	.ds 1
   4BB1                     164 _ctMainLoop::
   4BB1                     165 	.ds 1
   4BB2                     166 _ct::
   4BB2                     167 	.ds 1
   4BB3                     168 _ctlUp::
   4BB3                     169 	.ds 2
   4BB5                     170 _ctlDown::
   4BB5                     171 	.ds 2
   4BB7                     172 _ctlLeft::
   4BB7                     173 	.ds 2
   4BB9                     174 _ctlRight::
   4BB9                     175 	.ds 2
   4BBB                     176 _ctlFire::
   4BBB                     177 	.ds 2
   4BBD                     178 _ctlMusic::
   4BBD                     179 	.ds 2
   4BBF                     180 _ctlAbort::
   4BBF                     181 	.ds 2
   4BC1                     182 _ctlPause::
   4BC1                     183 	.ds 2
   4BC3                     184 _spr::
   4BC3                     185 	.ds 76
   4C0F                     186 _shot::
   4C0F                     187 	.ds 6
   4C15                     188 _shotLC::
   4C15                     189 	.ds 6
   4C1B                     190 _activeLC::
   4C1B                     191 	.ds 1
   4C1C                     192 _lc::
   4C1C                     193 	.ds 15
   4C2B                     194 _obj::
   4C2B                     195 	.ds 40
   4C53                     196 _enum_dir::
   4C53                     197 	.ds 1
   4C54                     198 _enum_sta::
   4C54                     199 	.ds 1
   4C55                     200 _enum_mov::
   4C55                     201 	.ds 1
   4C56                     202 _Interrupt_nInt_1_143:
   4C56                     203 	.ds 1
                            204 ;--------------------------------------------------------
                            205 ; ram data
                            206 ;--------------------------------------------------------
                            207 	.area _INITIALIZED
   4C57                     208 _mapNumber::
   4C57                     209 	.ds 1
                            210 ;--------------------------------------------------------
                            211 ; absolute external ram data
                            212 ;--------------------------------------------------------
                            213 	.area _DABS (ABS)
                            214 ;--------------------------------------------------------
                            215 ; global & static initialisations
                            216 ;--------------------------------------------------------
                            217 	.area _HOME
                            218 	.area _GSINIT
                            219 	.area _GSFINAL
                            220 	.area _GSINIT
                            221 ;--------------------------------------------------------
                            222 ; Home
                            223 ;--------------------------------------------------------
                            224 	.area _HOME
                            225 	.area _HOME
                            226 ;--------------------------------------------------------
                            227 ; code
                            228 ;--------------------------------------------------------
                            229 	.area _CODE
                            230 ;src/main.c:258: cpctm_createTransparentMaskTable(g_maskTable, 0x100, M0, 0);
                            231 ;	---------------------------------
                            232 ; Function dummy_cpct_transparentMaskTable0M0_container
                            233 ; ---------------------------------
   3319                     234 _dummy_cpct_transparentMaskTable0M0_container::
                            235 	.area _g_maskTable_ (ABS) 
   0100                     236 	.org 0x100 
   0100                     237 	 _g_maskTable::
   0100 FF AA 55 00 AA AA   238 	.db 0xFF, 0xAA, 0x55, 0x00, 0xAA, 0xAA, 0x00, 0x00 
        00 00
   0108 55 00 55 00 00 00   239 	.db 0x55, 0x00, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   0110 AA AA 00 00 AA AA   240 	.db 0xAA, 0xAA, 0x00, 0x00, 0xAA, 0xAA, 0x00, 0x00 
        00 00
   0118 00 00 00 00 00 00   241 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   0120 55 00 55 00 00 00   242 	.db 0x55, 0x00, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   0128 55 00 55 00 00 00   243 	.db 0x55, 0x00, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   0130 00 00 00 00 00 00   244 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   0138 00 00 00 00 00 00   245 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   0140 AA AA 00 00 AA AA   246 	.db 0xAA, 0xAA, 0x00, 0x00, 0xAA, 0xAA, 0x00, 0x00 
        00 00
   0148 00 00 00 00 00 00   247 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   0150 AA AA 00 00 AA AA   248 	.db 0xAA, 0xAA, 0x00, 0x00, 0xAA, 0xAA, 0x00, 0x00 
        00 00
   0158 00 00 00 00 00 00   249 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   0160 00 00 00 00 00 00   250 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   0168 00 00 00 00 00 00   251 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   0170 00 00 00 00 00 00   252 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   0178 00 00 00 00 00 00   253 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   0180 55 00 55 00 00 00   254 	.db 0x55, 0x00, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   0188 55 00 55 00 00 00   255 	.db 0x55, 0x00, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   0190 00 00 00 00 00 00   256 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   0198 00 00 00 00 00 00   257 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   01A0 55 00 55 00 00 00   258 	.db 0x55, 0x00, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   01A8 55 00 55 00 00 00   259 	.db 0x55, 0x00, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   01B0 00 00 00 00 00 00   260 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   01B8 00 00 00 00 00 00   261 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   01C0 00 00 00 00 00 00   262 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   01C8 00 00 00 00 00 00   263 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   01D0 00 00 00 00 00 00   264 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   01D8 00 00 00 00 00 00   265 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   01E0 00 00 00 00 00 00   266 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   01E8 00 00 00 00 00 00   267 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   01F0 00 00 00 00 00 00   268 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   01F8 00 00 00 00 00 00   269 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
                            270 	.area _CSEG (REL, CON) 
                            271 ;src/main.c:293: u8 Strlen(const u8 *str) __z88dk_fastcall {
                            272 ;	---------------------------------
                            273 ; Function Strlen
                            274 ; ---------------------------------
   4C59                     275 _Strlen::
                            276 ;src/main.c:295: for (s = str; *s; ++s);
   4C59 4D            [ 4]  277 	ld	c,l
   4C5A 44            [ 4]  278 	ld	b,h
   4C5B                     279 00103$:
   4C5B 7E            [ 7]  280 	ld	a, (hl)
   4C5C B7            [ 4]  281 	or	a, a
   4C5D 28 03         [12]  282 	jr	Z,00101$
   4C5F 23            [ 6]  283 	inc	hl
   4C60 18 F9         [12]  284 	jr	00103$
   4C62                     285 00101$:
                            286 ;src/main.c:296: return (s - str);
   4C62 BF            [ 4]  287 	cp	a, a
   4C63 ED 42         [15]  288 	sbc	hl, bc
   4C65 C9            [10]  289 	ret
   4C66                     290 _mapTitle:
   4C66 B8 4C               291 	.dw __str_0
   4C68 CD 4C               292 	.dw __str_1
   4C6A E2 4C               293 	.dw __str_2
   4C6C                     294 _frm_player:
   4C6C 03                  295 	.db #0x03	; 3
   4C6D 95 29               296 	.dw _g_player_0
   4C6F 03                  297 	.db #0x03	; 3
   4C70 15 2A               298 	.dw _g_player_1
   4C72 03                  299 	.db #0x03	; 3
   4C73 95 2A               300 	.dw _g_player_2
   4C75 03                  301 	.db #0x03	; 3
   4C76 15 2B               302 	.dw _g_player_3
   4C78 03                  303 	.db #0x03	; 3
   4C79 95 2B               304 	.dw _g_player_4
   4C7B 03                  305 	.db #0x03	; 3
   4C7C 15 2C               306 	.dw _g_player_5
   4C7E 03                  307 	.db #0x03	; 3
   4C7F 95 2C               308 	.dw _g_player_6
   4C81 03                  309 	.db #0x03	; 3
   4C82 15 2D               310 	.dw _g_player_7
   4C84 03                  311 	.db #0x03	; 3
   4C85 95 2D               312 	.dw _g_player_8
   4C87                     313 _animWalk:
   4C87 6C 4C               314 	.dw (_frm_player + 0)
   4C89 6F 4C               315 	.dw (_frm_player + 3)
   4C8B 6C 4C               316 	.dw (_frm_player + 0)
   4C8D 72 4C               317 	.dw (_frm_player + 6)
   4C8F                     318 _animClimb:
   4C8F 7E 4C               319 	.dw (_frm_player + 18)
   4C91 81 4C               320 	.dw (_frm_player + 21)
   4C93 7E 4C               321 	.dw (_frm_player + 18)
   4C95 84 4C               322 	.dw (_frm_player + 24)
   4C97                     323 _frm_pelusoid:
   4C97 00                  324 	.db #0x00	; 0
   4C98 95 28               325 	.dw _g_pelusoid_0
   4C9A 00                  326 	.db #0x00	; 0
   4C9B 15 29               327 	.dw _g_pelusoid_1
   4C9D                     328 _frm_aracnovirus:
   4C9D 00                  329 	.db #0x00	; 0
   4C9E 95 27               330 	.dw _g_aracnovirus_0
   4CA0 00                  331 	.db #0x00	; 0
   4CA1 15 28               332 	.dw _g_aracnovirus_1
   4CA3                     333 _frm_infected:
   4CA3 00                  334 	.db #0x00	; 0
   4CA4 95 26               335 	.dw _g_infected_0
   4CA6 00                  336 	.db #0x00	; 0
   4CA7 15 27               337 	.dw _g_infected_1
   4CA9                     338 _anim_pelusoid:
   4CA9 97 4C               339 	.dw (_frm_pelusoid + 0)
   4CAB 9A 4C               340 	.dw (_frm_pelusoid + 3)
   4CAD                     341 _anim_aracnovirus:
   4CAD 9D 4C               342 	.dw (_frm_aracnovirus + 0)
   4CAF A0 4C               343 	.dw (_frm_aracnovirus + 3)
   4CB1                     344 _anim_infected:
   4CB1 A3 4C               345 	.dw (_frm_infected + 0)
   4CB3 A6 4C               346 	.dw (_frm_infected + 3)
   4CB5                     347 _g_jumpTable:
   4CB5 FF                  348 	.db #0xff	; 255
   4CB6 A5                  349 	.db #0xa5	; 165
   4CB7 40                  350 	.db #0x40	; 64
   4CB8                     351 __str_0:
   4CB8 40 40 55 50 50 45   352 	.ascii "@@UPPER@LEFT@DECK@C@"
        52 40 4C 45 46 54
        40 44 45 43 4B 40
        43 40
   4CCC 00                  353 	.db 0x00
   4CCD                     354 __str_1:
   4CCD 40 40 55 50 50 45   355 	.ascii "@@UPPER@LEFT@DECK@B@"
        52 40 4C 45 46 54
        40 44 45 43 4B 40
        42 40
   4CE1 00                  356 	.db 0x00
   4CE2                     357 __str_2:
   4CE2 40 40 55 50 50 45   358 	.ascii "@@UPPER@LEFT@DECK@A@"
        52 40 4C 45 46 54
        40 44 45 43 4B 40
        41 40
   4CF6 00                  359 	.db 0x00
                            360 ;src/main.c:301: char* Itoa(u16 value, char* result, int base) {    
                            361 ;	---------------------------------
                            362 ; Function Itoa
                            363 ; ---------------------------------
   4CF7                     364 _Itoa::
   4CF7 DD E5         [15]  365 	push	ix
   4CF9 DD 21 00 00   [14]  366 	ld	ix,#0
   4CFD DD 39         [15]  367 	add	ix,sp
   4CFF 21 F9 FF      [10]  368 	ld	hl, #-7
   4D02 39            [11]  369 	add	hl, sp
   4D03 F9            [ 6]  370 	ld	sp, hl
                            371 ;src/main.c:303: char* ptr = result, *ptr1 = result, tmp_char;
   4D04 DD 5E 06      [19]  372 	ld	e,6 (ix)
   4D07 DD 56 07      [19]  373 	ld	d,7 (ix)
   4D0A DD 73 FA      [19]  374 	ld	-6 (ix), e
   4D0D DD 72 FB      [19]  375 	ld	-5 (ix), d
                            376 ;src/main.c:305: if (base < 2 || base > 36) { 
   4D10 DD 7E 08      [19]  377 	ld	a, 8 (ix)
   4D13 D6 02         [ 7]  378 	sub	a, #0x02
   4D15 DD 7E 09      [19]  379 	ld	a, 9 (ix)
   4D18 17            [ 4]  380 	rla
   4D19 3F            [ 4]  381 	ccf
   4D1A 1F            [ 4]  382 	rra
   4D1B DE 80         [ 7]  383 	sbc	a, #0x80
   4D1D 38 12         [12]  384 	jr	C,00101$
   4D1F 3E 24         [ 7]  385 	ld	a, #0x24
   4D21 DD BE 08      [19]  386 	cp	a, 8 (ix)
   4D24 3E 00         [ 7]  387 	ld	a, #0x00
   4D26 DD 9E 09      [19]  388 	sbc	a, 9 (ix)
   4D29 E2 2E 4D      [10]  389 	jp	PO, 00140$
   4D2C EE 80         [ 7]  390 	xor	a, #0x80
   4D2E                     391 00140$:
   4D2E F2 37 4D      [10]  392 	jp	P, 00115$
   4D31                     393 00101$:
                            394 ;src/main.c:306: *result = '\0'; 
   4D31 AF            [ 4]  395 	xor	a, a
   4D32 12            [ 7]  396 	ld	(de), a
                            397 ;src/main.c:307: return result; 
   4D33 EB            [ 4]  398 	ex	de,hl
   4D34 C3 D8 4D      [10]  399 	jp	00112$
                            400 ;src/main.c:310: do {
   4D37                     401 00115$:
   4D37 DD 73 FE      [19]  402 	ld	-2 (ix), e
   4D3A DD 72 FF      [19]  403 	ld	-1 (ix), d
   4D3D                     404 00104$:
                            405 ;src/main.c:311: tmp_value = value;
   4D3D DD 7E 04      [19]  406 	ld	a, 4 (ix)
   4D40 DD 77 FC      [19]  407 	ld	-4 (ix), a
   4D43 DD 7E 05      [19]  408 	ld	a, 5 (ix)
   4D46 DD 77 FD      [19]  409 	ld	-3 (ix), a
                            410 ;src/main.c:312: value /= base;
   4D49 DD 4E 08      [19]  411 	ld	c,8 (ix)
   4D4C DD 46 09      [19]  412 	ld	b,9 (ix)
   4D4F C5            [11]  413 	push	bc
   4D50 DD 6E 04      [19]  414 	ld	l,4 (ix)
   4D53 DD 66 05      [19]  415 	ld	h,5 (ix)
   4D56 E5            [11]  416 	push	hl
   4D57 CD D9 3D      [17]  417 	call	__divuint
   4D5A F1            [10]  418 	pop	af
   4D5B F1            [10]  419 	pop	af
   4D5C DD 75 04      [19]  420 	ld	4 (ix), l
   4D5F DD 74 05      [19]  421 	ld	5 (ix), h
                            422 ;src/main.c:313: *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
   4D62 DD 4E FC      [19]  423 	ld	c, -4 (ix)
   4D65 DD 5E 04      [19]  424 	ld	e, 4 (ix)
   4D68 DD 66 08      [19]  425 	ld	h, 8 (ix)
   4D6B 2E 00         [ 7]  426 	ld	l, #0x00
   4D6D 55            [ 4]  427 	ld	d, l
   4D6E 06 08         [ 7]  428 	ld	b, #0x08
   4D70                     429 00141$:
   4D70 29            [11]  430 	add	hl, hl
   4D71 30 01         [12]  431 	jr	NC,00142$
   4D73 19            [11]  432 	add	hl, de
   4D74                     433 00142$:
   4D74 10 FA         [13]  434 	djnz	00141$
   4D76 79            [ 4]  435 	ld	a, c
   4D77 95            [ 4]  436 	sub	a, l
   4D78 C6 23         [ 7]  437 	add	a, #0x23
   4D7A 4F            [ 4]  438 	ld	c, a
   4D7B 17            [ 4]  439 	rla
   4D7C 9F            [ 4]  440 	sbc	a, a
   4D7D 47            [ 4]  441 	ld	b, a
   4D7E 21 DD 4D      [10]  442 	ld	hl, #___str_3
   4D81 09            [11]  443 	add	hl, bc
   4D82 4E            [ 7]  444 	ld	c, (hl)
   4D83 DD 6E FE      [19]  445 	ld	l,-2 (ix)
   4D86 DD 66 FF      [19]  446 	ld	h,-1 (ix)
   4D89 71            [ 7]  447 	ld	(hl), c
   4D8A DD 34 FE      [23]  448 	inc	-2 (ix)
   4D8D 20 03         [12]  449 	jr	NZ,00143$
   4D8F DD 34 FF      [23]  450 	inc	-1 (ix)
   4D92                     451 00143$:
                            452 ;src/main.c:314: } while (value);
   4D92 DD 7E 05      [19]  453 	ld	a, 5 (ix)
   4D95 DD B6 04      [19]  454 	or	a,4 (ix)
   4D98 20 A3         [12]  455 	jr	NZ,00104$
                            456 ;src/main.c:316: if (tmp_value < 0) 
   4D9A DD 4E FE      [19]  457 	ld	c,-2 (ix)
   4D9D DD 46 FF      [19]  458 	ld	b,-1 (ix)
   4DA0 DD CB FD 7E   [20]  459 	bit	7, -3 (ix)
   4DA4 28 0F         [12]  460 	jr	Z,00108$
                            461 ;src/main.c:317: *ptr++ = '-';
   4DA6 DD 6E FE      [19]  462 	ld	l,-2 (ix)
   4DA9 DD 66 FF      [19]  463 	ld	h,-1 (ix)
   4DAC 36 2D         [10]  464 	ld	(hl), #0x2d
   4DAE DD 4E FE      [19]  465 	ld	c,-2 (ix)
   4DB1 DD 46 FF      [19]  466 	ld	b,-1 (ix)
   4DB4 03            [ 6]  467 	inc	bc
   4DB5                     468 00108$:
                            469 ;src/main.c:318: *ptr-- = '\0';
   4DB5 AF            [ 4]  470 	xor	a, a
   4DB6 02            [ 7]  471 	ld	(bc), a
   4DB7 0B            [ 6]  472 	dec	bc
                            473 ;src/main.c:320: while(ptr1 < ptr) {
   4DB8 DD 5E FA      [19]  474 	ld	e,-6 (ix)
   4DBB DD 56 FB      [19]  475 	ld	d,-5 (ix)
   4DBE                     476 00109$:
   4DBE 7B            [ 4]  477 	ld	a, e
   4DBF 91            [ 4]  478 	sub	a, c
   4DC0 7A            [ 4]  479 	ld	a, d
   4DC1 98            [ 4]  480 	sbc	a, b
   4DC2 30 0E         [12]  481 	jr	NC,00111$
                            482 ;src/main.c:321: tmp_char = *ptr;
   4DC4 0A            [ 7]  483 	ld	a, (bc)
   4DC5 DD 77 F9      [19]  484 	ld	-7 (ix), a
                            485 ;src/main.c:322: *ptr--= *ptr1;
   4DC8 1A            [ 7]  486 	ld	a, (de)
   4DC9 02            [ 7]  487 	ld	(bc), a
   4DCA 0B            [ 6]  488 	dec	bc
                            489 ;src/main.c:323: *ptr1++ = tmp_char;
   4DCB DD 7E F9      [19]  490 	ld	a, -7 (ix)
   4DCE 12            [ 7]  491 	ld	(de), a
   4DCF 13            [ 6]  492 	inc	de
   4DD0 18 EC         [12]  493 	jr	00109$
   4DD2                     494 00111$:
                            495 ;src/main.c:326: return result;
   4DD2 DD 6E 06      [19]  496 	ld	l,6 (ix)
   4DD5 DD 66 07      [19]  497 	ld	h,7 (ix)
   4DD8                     498 00112$:
   4DD8 DD F9         [10]  499 	ld	sp, ix
   4DDA DD E1         [14]  500 	pop	ix
   4DDC C9            [10]  501 	ret
   4DDD                     502 ___str_3:
   4DDD 7A 79 78 77 76 75   503 	.ascii "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmno"
        74 73 72 71 70 6F
        6E 6D 6C 6B 6A 69
        68 67 66 65 64 63
        62 61 39 38 37 36
        35 34 33 32 31 30
        31 32 33 34 35 36
        37 38 39 61 62 63
        64 65 66 67 68 69
        6A 6B 6C 6D 6E 6F
   4E19 70 71 72 73 74 75   504 	.ascii "pqrstuvwxyz"
        76 77 78 79 7A
   4E24 00                  505 	.db 0x00
                            506 ;src/main.c:331: void Pause(u16 value) __z88dk_fastcall {
                            507 ;	---------------------------------
                            508 ; Function Pause
                            509 ; ---------------------------------
   4E25                     510 _Pause::
                            511 ;src/main.c:333: for(i = 0; i < value; i++) {
   4E25 01 00 00      [10]  512 	ld	bc, #0x0000
   4E28                     513 00103$:
   4E28 79            [ 4]  514 	ld	a, c
   4E29 95            [ 4]  515 	sub	a, l
   4E2A 78            [ 4]  516 	ld	a, b
   4E2B 9C            [ 4]  517 	sbc	a, h
   4E2C D0            [11]  518 	ret	NC
                            519 ;src/main.c:336: __endasm;
   4E2D 76            [ 4]  520 	halt
                            521 ;src/main.c:333: for(i = 0; i < value; i++) {
   4E2E 03            [ 6]  522 	inc	bc
   4E2F 18 F7         [12]  523 	jr	00103$
                            524 ;src/main.c:342: void PlayMusic() {
                            525 ;	---------------------------------
                            526 ; Function PlayMusic
                            527 ; ---------------------------------
   4E31                     528 _PlayMusic::
                            529 ;src/main.c:357: __endasm;
   4E31 D9            [ 4]  530 	exx
   4E32 08                  531 	.db	#0x08
   4E33 F5            [11]  532 	push	af
   4E34 C5            [11]  533 	push	bc
   4E35 D5            [11]  534 	push	de
   4E36 E5            [11]  535 	push	hl
   4E37 CD B5 3E      [17]  536 	call	_cpct_akp_musicPlay
   4E3A E1            [10]  537 	pop	hl
   4E3B D1            [10]  538 	pop	de
   4E3C C1            [10]  539 	pop	bc
   4E3D F1            [10]  540 	pop	af
   4E3E 08                  541 	.db	#0x08
   4E3F D9            [ 4]  542 	exx
   4E40 C9            [10]  543 	ret
                            544 ;src/main.c:362: void Interrupt() {
                            545 ;	---------------------------------
                            546 ; Function Interrupt
                            547 ; ---------------------------------
   4E41                     548 _Interrupt::
                            549 ;src/main.c:365: if (++nInt == 5) {
   4E41 FD 21 56 4C   [14]  550 	ld	iy, #_Interrupt_nInt_1_143
   4E45 FD 34 00      [23]  551 	inc	0 (iy)
   4E48 FD 7E 00      [19]  552 	ld	a, 0 (iy)
   4E4B D6 05         [ 7]  553 	sub	a, #0x05
   4E4D C0            [11]  554 	ret	NZ
                            555 ;src/main.c:366: PlayMusic();
   4E4E CD 31 4E      [17]  556 	call	_PlayMusic
                            557 ;src/main.c:367: cpct_scanKeyboard_if();
   4E51 CD 89 48      [17]  558 	call	_cpct_scanKeyboard_if
                            559 ;src/main.c:368: nInt = 0;
   4E54 21 56 4C      [10]  560 	ld	hl,#_Interrupt_nInt_1_143 + 0
   4E57 36 00         [10]  561 	ld	(hl), #0x00
   4E59 C9            [10]  562 	ret
                            563 ;src/main.c:386: void ClearScreen() {
                            564 ;	---------------------------------
                            565 ; Function ClearScreen
                            566 ; ---------------------------------
   4E5A                     567 _ClearScreen::
                            568 ;src/main.c:387: cpct_memset(CPCT_VMEM_START, cpct_px2byteM0(1, 1), 16384);
   4E5A 21 01 01      [10]  569 	ld	hl, #0x0101
   4E5D E5            [11]  570 	push	hl
   4E5E CD 8E 49      [17]  571 	call	_cpct_px2byteM0
   4E61 45            [ 4]  572 	ld	b, l
   4E62 21 00 40      [10]  573 	ld	hl, #0x4000
   4E65 E5            [11]  574 	push	hl
   4E66 C5            [11]  575 	push	bc
   4E67 33            [ 6]  576 	inc	sp
   4E68 26 C0         [ 7]  577 	ld	h, #0xc0
   4E6A E5            [11]  578 	push	hl
   4E6B CD AA 49      [17]  579 	call	_cpct_memset
   4E6E C9            [10]  580 	ret
                            581 ;src/main.c:392: void PrintNumber(u16 num, u8 len, u8 x, u8 y) { 
                            582 ;	---------------------------------
                            583 ; Function PrintNumber
                            584 ; ---------------------------------
   4E6F                     585 _PrintNumber::
   4E6F DD E5         [15]  586 	push	ix
   4E71 DD 21 00 00   [14]  587 	ld	ix,#0
   4E75 DD 39         [15]  588 	add	ix,sp
   4E77 21 F8 FF      [10]  589 	ld	hl, #-8
   4E7A 39            [11]  590 	add	hl, sp
                            591 ;src/main.c:398: Itoa(num, txt, 10);    
   4E7B F9            [ 6]  592 	ld	sp, hl
   4E7C 23            [ 6]  593 	inc	hl
   4E7D 23            [ 6]  594 	inc	hl
   4E7E 4D            [ 4]  595 	ld	c, l
   4E7F 44            [ 4]  596 	ld	b, h
   4E80 59            [ 4]  597 	ld	e, c
   4E81 50            [ 4]  598 	ld	d, b
   4E82 C5            [11]  599 	push	bc
   4E83 21 0A 00      [10]  600 	ld	hl, #0x000a
   4E86 E5            [11]  601 	push	hl
   4E87 D5            [11]  602 	push	de
   4E88 DD 6E 04      [19]  603 	ld	l,4 (ix)
   4E8B DD 66 05      [19]  604 	ld	h,5 (ix)
   4E8E E5            [11]  605 	push	hl
   4E8F CD F7 4C      [17]  606 	call	_Itoa
   4E92 21 06 00      [10]  607 	ld	hl, #6
   4E95 39            [11]  608 	add	hl, sp
   4E96 F9            [ 6]  609 	ld	sp, hl
   4E97 C1            [10]  610 	pop	bc
                            611 ;src/main.c:399: zeros = len - Strlen(txt);
   4E98 69            [ 4]  612 	ld	l, c
   4E99 60            [ 4]  613 	ld	h, b
   4E9A C5            [11]  614 	push	bc
   4E9B CD 59 4C      [17]  615 	call	_Strlen
   4E9E C1            [10]  616 	pop	bc
   4E9F DD 7E 06      [19]  617 	ld	a, 6 (ix)
   4EA2 95            [ 4]  618 	sub	a, l
   4EA3 DD 77 F9      [19]  619 	ld	-7 (ix), a
                            620 ;src/main.c:400: nAux = txt[pos];
   4EA6 0A            [ 7]  621 	ld	a, (bc)
   4EA7 5F            [ 4]  622 	ld	e, a
                            623 ;src/main.c:402: while(nAux != '\0')	{	
   4EA8 DD 36 F8 00   [19]  624 	ld	-8 (ix), #0x00
   4EAC                     625 00101$:
   4EAC 7B            [ 4]  626 	ld	a, e
   4EAD B7            [ 4]  627 	or	a, a
   4EAE 28 4C         [12]  628 	jr	Z,00104$
                            629 ;src/main.c:403: u8* ptr = cpct_getScreenPtr(CPCT_VMEM_START, (zeros + pos) * FNT_W + x, y);
   4EB0 DD 7E F9      [19]  630 	ld	a, -7 (ix)
   4EB3 DD 86 F8      [19]  631 	add	a, -8 (ix)
   4EB6 87            [ 4]  632 	add	a, a
   4EB7 87            [ 4]  633 	add	a, a
   4EB8 DD 86 07      [19]  634 	add	a, 7 (ix)
   4EBB 57            [ 4]  635 	ld	d, a
   4EBC C5            [11]  636 	push	bc
   4EBD D5            [11]  637 	push	de
   4EBE DD 7E 08      [19]  638 	ld	a, 8 (ix)
   4EC1 F5            [11]  639 	push	af
   4EC2 33            [ 6]  640 	inc	sp
   4EC3 D5            [11]  641 	push	de
   4EC4 33            [ 6]  642 	inc	sp
   4EC5 21 00 C0      [10]  643 	ld	hl, #0xc000
   4EC8 E5            [11]  644 	push	hl
   4EC9 CD AA 4A      [17]  645 	call	_cpct_getScreenPtr
   4ECC D1            [10]  646 	pop	de
   4ECD C1            [10]  647 	pop	bc
                            648 ;src/main.c:404: cpct_drawSprite(g_font[nAux - 48], ptr, FNT_W, FNT_H);
   4ECE E5            [11]  649 	push	hl
   4ECF FD E1         [14]  650 	pop	iy
   4ED1 16 00         [ 7]  651 	ld	d, #0x00
   4ED3 7B            [ 4]  652 	ld	a, e
   4ED4 C6 D0         [ 7]  653 	add	a, #0xd0
   4ED6 6F            [ 4]  654 	ld	l, a
   4ED7 7A            [ 4]  655 	ld	a, d
   4ED8 CE FF         [ 7]  656 	adc	a, #0xff
   4EDA 67            [ 4]  657 	ld	h, a
   4EDB 29            [11]  658 	add	hl, hl
   4EDC 29            [11]  659 	add	hl, hl
   4EDD 29            [11]  660 	add	hl, hl
   4EDE 29            [11]  661 	add	hl, hl
   4EDF 29            [11]  662 	add	hl, hl
   4EE0 11 19 33      [10]  663 	ld	de, #_g_font
   4EE3 19            [11]  664 	add	hl, de
   4EE4 C5            [11]  665 	push	bc
   4EE5 11 04 08      [10]  666 	ld	de, #0x0804
   4EE8 D5            [11]  667 	push	de
   4EE9 FD E5         [15]  668 	push	iy
   4EEB E5            [11]  669 	push	hl
   4EEC CD DC 46      [17]  670 	call	_cpct_drawSprite
   4EEF C1            [10]  671 	pop	bc
                            672 ;src/main.c:405: nAux = txt[++pos];
   4EF0 DD 34 F8      [23]  673 	inc	-8 (ix)
   4EF3 DD 6E F8      [19]  674 	ld	l,-8 (ix)
   4EF6 26 00         [ 7]  675 	ld	h,#0x00
   4EF8 09            [11]  676 	add	hl, bc
   4EF9 5E            [ 7]  677 	ld	e, (hl)
   4EFA 18 B0         [12]  678 	jr	00101$
   4EFC                     679 00104$:
   4EFC DD F9         [10]  680 	ld	sp, ix
   4EFE DD E1         [14]  681 	pop	ix
   4F00 C9            [10]  682 	ret
                            683 ;src/main.c:411: void PrintText(u8 txt[], u8 x, u8 y) {
                            684 ;	---------------------------------
                            685 ; Function PrintText
                            686 ; ---------------------------------
   4F01                     687 _PrintText::
   4F01 DD E5         [15]  688 	push	ix
   4F03 DD 21 00 00   [14]  689 	ld	ix,#0
   4F07 DD 39         [15]  690 	add	ix,sp
   4F09 3B            [ 6]  691 	dec	sp
                            692 ;src/main.c:413: u8 car = txt[pos];
   4F0A DD 4E 04      [19]  693 	ld	c,4 (ix)
   4F0D DD 46 05      [19]  694 	ld	b,5 (ix)
   4F10 0A            [ 7]  695 	ld	a, (bc)
   4F11 5F            [ 4]  696 	ld	e, a
                            697 ;src/main.c:415: while(car != '\0') { // "@" = space    ";" = -   "?" = !!
   4F12 DD 36 FF 00   [19]  698 	ld	-1 (ix), #0x00
   4F16                     699 00101$:
   4F16 7B            [ 4]  700 	ld	a, e
   4F17 B7            [ 4]  701 	or	a, a
   4F18 28 49         [12]  702 	jr	Z,00104$
                            703 ;src/main.c:416: u8* ptr = cpct_getScreenPtr(CPCT_VMEM_START, (pos * FNT_W) + x, y);
   4F1A DD 7E FF      [19]  704 	ld	a, -1 (ix)
   4F1D 87            [ 4]  705 	add	a, a
   4F1E 87            [ 4]  706 	add	a, a
   4F1F DD 86 06      [19]  707 	add	a, 6 (ix)
   4F22 57            [ 4]  708 	ld	d, a
   4F23 C5            [11]  709 	push	bc
   4F24 D5            [11]  710 	push	de
   4F25 DD 7E 07      [19]  711 	ld	a, 7 (ix)
   4F28 F5            [11]  712 	push	af
   4F29 33            [ 6]  713 	inc	sp
   4F2A D5            [11]  714 	push	de
   4F2B 33            [ 6]  715 	inc	sp
   4F2C 21 00 C0      [10]  716 	ld	hl, #0xc000
   4F2F E5            [11]  717 	push	hl
   4F30 CD AA 4A      [17]  718 	call	_cpct_getScreenPtr
   4F33 D1            [10]  719 	pop	de
   4F34 C1            [10]  720 	pop	bc
                            721 ;src/main.c:417: cpct_drawSprite(g_font[car - 48], ptr, FNT_W, FNT_H);
   4F35 E5            [11]  722 	push	hl
   4F36 FD E1         [14]  723 	pop	iy
   4F38 16 00         [ 7]  724 	ld	d, #0x00
   4F3A 7B            [ 4]  725 	ld	a, e
   4F3B C6 D0         [ 7]  726 	add	a, #0xd0
   4F3D 6F            [ 4]  727 	ld	l, a
   4F3E 7A            [ 4]  728 	ld	a, d
   4F3F CE FF         [ 7]  729 	adc	a, #0xff
   4F41 67            [ 4]  730 	ld	h, a
   4F42 29            [11]  731 	add	hl, hl
   4F43 29            [11]  732 	add	hl, hl
   4F44 29            [11]  733 	add	hl, hl
   4F45 29            [11]  734 	add	hl, hl
   4F46 29            [11]  735 	add	hl, hl
   4F47 11 19 33      [10]  736 	ld	de, #_g_font
   4F4A 19            [11]  737 	add	hl, de
   4F4B C5            [11]  738 	push	bc
   4F4C 11 04 08      [10]  739 	ld	de, #0x0804
   4F4F D5            [11]  740 	push	de
   4F50 FD E5         [15]  741 	push	iy
   4F52 E5            [11]  742 	push	hl
   4F53 CD DC 46      [17]  743 	call	_cpct_drawSprite
   4F56 C1            [10]  744 	pop	bc
                            745 ;src/main.c:418: car = txt[++pos];
   4F57 DD 34 FF      [23]  746 	inc	-1 (ix)
   4F5A DD 6E FF      [19]  747 	ld	l,-1 (ix)
   4F5D 26 00         [ 7]  748 	ld	h,#0x00
   4F5F 09            [11]  749 	add	hl, bc
   4F60 5E            [ 7]  750 	ld	e, (hl)
   4F61 18 B3         [12]  751 	jr	00101$
   4F63                     752 00104$:
   4F63 33            [ 6]  753 	inc	sp
   4F64 DD E1         [14]  754 	pop	ix
   4F66 C9            [10]  755 	ret
                            756 ;src/main.c:424: void InitScoreboard()
                            757 ;	---------------------------------
                            758 ; Function InitScoreboard
                            759 ; ---------------------------------
   4F67                     760 _InitScoreboard::
                            761 ;src/main.c:426: cpct_drawSprite(g_hud_0, cpctm_screenPtr(CPCT_VMEM_START,  0, 0), G_HUD_0_W, G_HUD_0_H);
   4F67 21 28 28      [10]  762 	ld	hl, #0x2828
   4F6A E5            [11]  763 	push	hl
   4F6B 21 00 C0      [10]  764 	ld	hl, #0xc000
   4F6E E5            [11]  765 	push	hl
   4F6F 21 15 1A      [10]  766 	ld	hl, #_g_hud_0
   4F72 E5            [11]  767 	push	hl
   4F73 CD DC 46      [17]  768 	call	_cpct_drawSprite
                            769 ;src/main.c:427: cpct_drawSprite(g_hud_1, cpctm_screenPtr(CPCT_VMEM_START, 40, 0), G_HUD_1_W, G_HUD_1_H);
   4F76 21 28 28      [10]  770 	ld	hl, #0x2828
   4F79 E5            [11]  771 	push	hl
   4F7A 26 C0         [ 7]  772 	ld	h, #0xc0
   4F7C E5            [11]  773 	push	hl
   4F7D 21 55 20      [10]  774 	ld	hl, #_g_hud_1
   4F80 E5            [11]  775 	push	hl
   4F81 CD DC 46      [17]  776 	call	_cpct_drawSprite
   4F84 C9            [10]  777 	ret
                            778 ;src/main.c:432: void RefreshScoreboard() {
                            779 ;	---------------------------------
                            780 ; Function RefreshScoreboard
                            781 ; ---------------------------------
   4F85                     782 _RefreshScoreboard::
                            783 ;src/main.c:433: PrintNumber(score, 5, 21, 0); // current score
   4F85 21 15 00      [10]  784 	ld	hl, #0x0015
   4F88 E5            [11]  785 	push	hl
   4F89 3E 05         [ 7]  786 	ld	a, #0x05
   4F8B F5            [11]  787 	push	af
   4F8C 33            [ 6]  788 	inc	sp
   4F8D 2A AB 4B      [16]  789 	ld	hl, (_score)
   4F90 E5            [11]  790 	push	hl
   4F91 CD 6F 4E      [17]  791 	call	_PrintNumber
   4F94 F1            [10]  792 	pop	af
                            793 ;src/main.c:434: PrintNumber(highScore, 5, 60, 0); // session high score
   4F95 33            [ 6]  794 	inc	sp
   4F96 21 3C 00      [10]  795 	ld	hl,#0x003c
   4F99 E3            [19]  796 	ex	(sp),hl
   4F9A 3E 05         [ 7]  797 	ld	a, #0x05
   4F9C F5            [11]  798 	push	af
   4F9D 33            [ 6]  799 	inc	sp
   4F9E 2A AD 4B      [16]  800 	ld	hl, (_highScore)
   4FA1 E5            [11]  801 	push	hl
   4FA2 CD 6F 4E      [17]  802 	call	_PrintNumber
   4FA5 F1            [10]  803 	pop	af
   4FA6 F1            [10]  804 	pop	af
   4FA7 33            [ 6]  805 	inc	sp
                            806 ;src/main.c:435: PrintNumber(spr[0].lives, 1, 8, 17); // lives left 
   4FA8 21 CC 4B      [10]  807 	ld	hl, #_spr+9
   4FAB 4E            [ 7]  808 	ld	c, (hl)
   4FAC 06 00         [ 7]  809 	ld	b, #0x00
   4FAE 21 08 11      [10]  810 	ld	hl, #0x1108
   4FB1 E5            [11]  811 	push	hl
   4FB2 3E 01         [ 7]  812 	ld	a, #0x01
   4FB4 F5            [11]  813 	push	af
   4FB5 33            [ 6]  814 	inc	sp
   4FB6 C5            [11]  815 	push	bc
   4FB7 CD 6F 4E      [17]  816 	call	_PrintNumber
   4FBA F1            [10]  817 	pop	af
   4FBB F1            [10]  818 	pop	af
   4FBC 33            [ 6]  819 	inc	sp
                            820 ;src/main.c:436: if (ammo < 10) PrintNumber(0, 1, 25, 17); // zero if ammo < 10
   4FBD 3A AF 4B      [13]  821 	ld	a,(#_ammo + 0)
   4FC0 D6 0A         [ 7]  822 	sub	a, #0x0a
   4FC2 30 12         [12]  823 	jr	NC,00102$
   4FC4 21 19 11      [10]  824 	ld	hl, #0x1119
   4FC7 E5            [11]  825 	push	hl
   4FC8 3E 01         [ 7]  826 	ld	a, #0x01
   4FCA F5            [11]  827 	push	af
   4FCB 33            [ 6]  828 	inc	sp
   4FCC 21 00 00      [10]  829 	ld	hl, #0x0000
   4FCF E5            [11]  830 	push	hl
   4FD0 CD 6F 4E      [17]  831 	call	_PrintNumber
   4FD3 F1            [10]  832 	pop	af
   4FD4 F1            [10]  833 	pop	af
   4FD5 33            [ 6]  834 	inc	sp
   4FD6                     835 00102$:
                            836 ;src/main.c:437: PrintNumber(ammo, 2, 25, 17); // bullets left
   4FD6 21 AF 4B      [10]  837 	ld	hl,#_ammo + 0
   4FD9 4E            [ 7]  838 	ld	c, (hl)
   4FDA 06 00         [ 7]  839 	ld	b, #0x00
   4FDC 21 19 11      [10]  840 	ld	hl, #0x1119
   4FDF E5            [11]  841 	push	hl
   4FE0 3E 02         [ 7]  842 	ld	a, #0x02
   4FE2 F5            [11]  843 	push	af
   4FE3 33            [ 6]  844 	inc	sp
   4FE4 C5            [11]  845 	push	bc
   4FE5 CD 6F 4E      [17]  846 	call	_PrintNumber
   4FE8 F1            [10]  847 	pop	af
   4FE9 F1            [10]  848 	pop	af
   4FEA 33            [ 6]  849 	inc	sp
   4FEB C9            [10]  850 	ret
                            851 ;src/main.c:442: void PrintMap() {
                            852 ;	---------------------------------
                            853 ; Function PrintMap
                            854 ; ---------------------------------
   4FEC                     855 _PrintMap::
                            856 ;src/main.c:443: cpct_etm_drawTilemap2x4(MAP_W, MAP_H, cpctm_screenPtr(CPCT_VMEM_START, 0, ORIG_MAP_Y), UNPACKED_MAP_INI);
   4FEC 21 31 10      [10]  857 	ld	hl, #0x1031
   4FEF E5            [11]  858 	push	hl
   4FF0 21 00 C0      [10]  859 	ld	hl, #0xc000
   4FF3 E5            [11]  860 	push	hl
   4FF4 21 26 28      [10]  861 	ld	hl, #0x2826
   4FF7 E5            [11]  862 	push	hl
   4FF8 2E 00         [ 7]  863 	ld	l, #0x00
   4FFA E5            [11]  864 	push	hl
   4FFB AF            [ 4]  865 	xor	a, a
   4FFC F5            [11]  866 	push	af
   4FFD 33            [ 6]  867 	inc	sp
   4FFE CD 81 47      [17]  868 	call	_cpct_etm_drawTileBox2x4
                            869 ;src/main.c:445: PrintText(mapTitle[mapNumber], 0, 192);
   5001 01 66 4C      [10]  870 	ld	bc, #_mapTitle+0
   5004 FD 21 57 4C   [14]  871 	ld	iy, #_mapNumber
   5008 FD 6E 00      [19]  872 	ld	l, 0 (iy)
   500B 26 00         [ 7]  873 	ld	h, #0x00
   500D 29            [11]  874 	add	hl, hl
   500E 09            [11]  875 	add	hl, bc
   500F 4E            [ 7]  876 	ld	c, (hl)
   5010 23            [ 6]  877 	inc	hl
   5011 46            [ 7]  878 	ld	b, (hl)
   5012 21 00 C0      [10]  879 	ld	hl, #0xc000
   5015 E5            [11]  880 	push	hl
   5016 C5            [11]  881 	push	bc
   5017 CD 01 4F      [17]  882 	call	_PrintText
   501A F1            [10]  883 	pop	af
   501B F1            [10]  884 	pop	af
   501C C9            [10]  885 	ret
                            886 ;src/main.c:450: void InitMap() {
                            887 ;	---------------------------------
                            888 ; Function InitMap
                            889 ; ---------------------------------
   501D                     890 _InitMap::
                            891 ;src/main.c:451: shot.active = FALSE; 
   501D 21 14 4C      [10]  892 	ld	hl, #(_shot + 0x0005)
   5020 36 00         [10]  893 	ld	(hl), #0x00
                            894 ;src/main.c:452: shotLC.active = FALSE; 
   5022 21 1A 4C      [10]  895 	ld	hl, #(_shotLC + 0x0005)
   5025 36 00         [10]  896 	ld	(hl), #0x00
                            897 ;src/main.c:453: SetEnemies();
   5027 CD 78 61      [17]  898 	call	_SetEnemies
                            899 ;src/main.c:454: GetLC();
   502A CD 06 65      [17]  900 	call	_GetLC
                            901 ;src/main.c:455: PrintMap();
   502D C3 EC 4F      [10]  902 	jp  _PrintMap
                            903 ;src/main.c:460: void MoveRightMap() {
                            904 ;	---------------------------------
                            905 ; Function MoveRightMap
                            906 ; ---------------------------------
   5030                     907 _MoveRightMap::
                            908 ;src/main.c:461: if (mapNumber < TOTAL_MAPS-1) {
   5030 FD 21 57 4C   [14]  909 	ld	iy, #_mapNumber
   5034 FD 7E 00      [19]  910 	ld	a, 0 (iy)
   5037 D6 02         [ 7]  911 	sub	a, #0x02
   5039 D0            [11]  912 	ret	NC
                            913 ;src/main.c:462: mapNumber++;
   503A FD 34 00      [23]  914 	inc	0 (iy)
                            915 ;src/main.c:463: spr[0].x = spr[0].px = 0;
   503D 21 C5 4B      [10]  916 	ld	hl, #(_spr + 0x0002)
   5040 36 00         [10]  917 	ld	(hl), #0x00
   5042 21 C3 4B      [10]  918 	ld	hl, #_spr
   5045 36 00         [10]  919 	ld	(hl), #0x00
                            920 ;src/main.c:464: InitMap();
   5047 C3 1D 50      [10]  921 	jp  _InitMap
                            922 ;src/main.c:470: void MoveLeftMap() {
                            923 ;	---------------------------------
                            924 ; Function MoveLeftMap
                            925 ; ---------------------------------
   504A                     926 _MoveLeftMap::
                            927 ;src/main.c:471: if (mapNumber > 0) {
   504A FD 21 57 4C   [14]  928 	ld	iy, #_mapNumber
   504E FD 7E 00      [19]  929 	ld	a, 0 (iy)
   5051 B7            [ 4]  930 	or	a, a
   5052 C8            [11]  931 	ret	Z
                            932 ;src/main.c:472: mapNumber--;
   5053 FD 35 00      [23]  933 	dec	0 (iy)
                            934 ;src/main.c:473: spr[0].x = spr[0].px = GLOBAL_MAX_X - SPR_W;
   5056 21 C5 4B      [10]  935 	ld	hl, #(_spr + 0x0002)
   5059 36 48         [10]  936 	ld	(hl), #0x48
   505B 21 C3 4B      [10]  937 	ld	hl, #_spr
   505E 36 48         [10]  938 	ld	(hl), #0x48
                            939 ;src/main.c:474: InitMap();
   5060 C3 1D 50      [10]  940 	jp  _InitMap
                            941 ;src/main.c:480: u8* GetTilePtr(u8 x, u8 y) {
                            942 ;	---------------------------------
                            943 ; Function GetTilePtr
                            944 ; ---------------------------------
   5063                     945 _GetTilePtr::
                            946 ;src/main.c:481: return UNPACKED_MAP_INI + (y - ORIG_MAP_Y) / 4 * MAP_W + x / 2;	
   5063 FD 21 03 00   [14]  947 	ld	iy, #3
   5067 FD 39         [15]  948 	add	iy, sp
   5069 FD 6E 00      [19]  949 	ld	l, 0 (iy)
   506C 26 00         [ 7]  950 	ld	h, #0x00
   506E 4D            [ 4]  951 	ld	c, l
   506F 5C            [ 4]  952 	ld	e, h
   5070 CB 7C         [ 8]  953 	bit	7, h
   5072 28 05         [12]  954 	jr	Z,00103$
   5074 23            [ 6]  955 	inc	hl
   5075 23            [ 6]  956 	inc	hl
   5076 23            [ 6]  957 	inc	hl
   5077 4D            [ 4]  958 	ld	c, l
   5078 5C            [ 4]  959 	ld	e, h
   5079                     960 00103$:
   5079 43            [ 4]  961 	ld	b, e
   507A CB 28         [ 8]  962 	sra	b
   507C CB 19         [ 8]  963 	rr	c
   507E CB 28         [ 8]  964 	sra	b
   5080 CB 19         [ 8]  965 	rr	c
   5082 69            [ 4]  966 	ld	l, c
   5083 60            [ 4]  967 	ld	h, b
   5084 29            [11]  968 	add	hl, hl
   5085 29            [11]  969 	add	hl, hl
   5086 09            [11]  970 	add	hl, bc
   5087 29            [11]  971 	add	hl, hl
   5088 29            [11]  972 	add	hl, hl
   5089 29            [11]  973 	add	hl, hl
   508A 01 31 10      [10]  974 	ld	bc, #0x1031
   508D 09            [11]  975 	add	hl, bc
   508E FD 21 02 00   [14]  976 	ld	iy, #2
   5092 FD 39         [15]  977 	add	iy, sp
   5094 FD 4E 00      [19]  978 	ld	c, 0 (iy)
   5097 CB 39         [ 8]  979 	srl	c
   5099 59            [ 4]  980 	ld	e,c
   509A 16 00         [ 7]  981 	ld	d,#0x00
   509C 19            [11]  982 	add	hl, de
   509D C9            [10]  983 	ret
                            984 ;src/main.c:486: u8 OnPlatform(TSpr *pSpr) __z88dk_fastcall {
                            985 ;	---------------------------------
                            986 ; Function OnPlatform
                            987 ; ---------------------------------
   509E                     988 _OnPlatform::
                            989 ;src/main.c:487: u8* tile = GetTilePtr(pSpr->x + 4, pSpr->y + SPR_H + 1);
   509E 4D            [ 4]  990 	ld	c,l
   509F 44            [ 4]  991 	ld	b,h
   50A0 23            [ 6]  992 	inc	hl
   50A1 7E            [ 7]  993 	ld	a, (hl)
   50A2 C6 11         [ 7]  994 	add	a, #0x11
   50A4 57            [ 4]  995 	ld	d, a
   50A5 0A            [ 7]  996 	ld	a, (bc)
   50A6 C6 04         [ 7]  997 	add	a, #0x04
   50A8 5F            [ 4]  998 	ld	e, a
   50A9 D5            [11]  999 	push	de
   50AA CD 63 50      [17] 1000 	call	_GetTilePtr
   50AD F1            [10] 1001 	pop	af
                           1002 ;src/main.c:488: if (*tile == 0)
   50AE 7E            [ 7] 1003 	ld	a, (hl)
   50AF B7            [ 4] 1004 	or	a, a
   50B0 20 03         [12] 1005 	jr	NZ,00102$
                           1006 ;src/main.c:489: return TRUE;	
   50B2 2E 01         [ 7] 1007 	ld	l, #0x01
   50B4 C9            [10] 1008 	ret
   50B5                    1009 00102$:
                           1010 ;src/main.c:490: return FALSE;
   50B5 2E 00         [ 7] 1011 	ld	l, #0x00
   50B7 C9            [10] 1012 	ret
                           1013 ;src/main.c:495: u8 OnStairs() {
                           1014 ;	---------------------------------
                           1015 ; Function OnStairs
                           1016 ; ---------------------------------
   50B8                    1017 _OnStairs::
                           1018 ;src/main.c:496: u8* tile = GetTilePtr(spr[0].x + 4, spr[0].y + SPR_H + 1);
   50B8 3A C4 4B      [13] 1019 	ld	a, (#_spr + 1)
   50BB C6 11         [ 7] 1020 	add	a, #0x11
   50BD 47            [ 4] 1021 	ld	b, a
   50BE 3A C3 4B      [13] 1022 	ld	a, (#_spr + 0)
   50C1 C6 04         [ 7] 1023 	add	a, #0x04
   50C3 C5            [11] 1024 	push	bc
   50C4 33            [ 6] 1025 	inc	sp
   50C5 F5            [11] 1026 	push	af
   50C6 33            [ 6] 1027 	inc	sp
   50C7 CD 63 50      [17] 1028 	call	_GetTilePtr
   50CA F1            [10] 1029 	pop	af
                           1030 ;src/main.c:497: if (*tile >  47 && *tile <  56)
   50CB 4E            [ 7] 1031 	ld	c, (hl)
   50CC 3E 2F         [ 7] 1032 	ld	a, #0x2f
   50CE 91            [ 4] 1033 	sub	a, c
   50CF 30 08         [12] 1034 	jr	NC,00102$
   50D1 79            [ 4] 1035 	ld	a, c
   50D2 D6 38         [ 7] 1036 	sub	a, #0x38
   50D4 30 03         [12] 1037 	jr	NC,00102$
                           1038 ;src/main.c:498: return TRUE;
   50D6 2E 01         [ 7] 1039 	ld	l, #0x01
   50D8 C9            [10] 1040 	ret
   50D9                    1041 00102$:
                           1042 ;src/main.c:499: return FALSE;
   50D9 2E 00         [ 7] 1043 	ld	l, #0x00
   50DB C9            [10] 1044 	ret
                           1045 ;src/main.c:504: u8 OverMines() {
                           1046 ;	---------------------------------
                           1047 ; Function OverMines
                           1048 ; ---------------------------------
   50DC                    1049 _OverMines::
                           1050 ;src/main.c:505: u8* tile = GetTilePtr(spr[0].x + 4, spr[0].y + SPR_H);
   50DC 3A C4 4B      [13] 1051 	ld	a, (#_spr + 1)
   50DF C6 10         [ 7] 1052 	add	a, #0x10
   50E1 47            [ 4] 1053 	ld	b, a
   50E2 3A C3 4B      [13] 1054 	ld	a, (#_spr + 0)
   50E5 C6 04         [ 7] 1055 	add	a, #0x04
   50E7 C5            [11] 1056 	push	bc
   50E8 33            [ 6] 1057 	inc	sp
   50E9 F5            [11] 1058 	push	af
   50EA 33            [ 6] 1059 	inc	sp
   50EB CD 63 50      [17] 1060 	call	_GetTilePtr
   50EE F1            [10] 1061 	pop	af
                           1062 ;src/main.c:506: if (*tile > 55 && *tile < 58) 
   50EF 4E            [ 7] 1063 	ld	c, (hl)
   50F0 3E 37         [ 7] 1064 	ld	a, #0x37
   50F2 91            [ 4] 1065 	sub	a, c
   50F3 30 08         [12] 1066 	jr	NC,00102$
   50F5 79            [ 4] 1067 	ld	a, c
   50F6 D6 3A         [ 7] 1068 	sub	a, #0x3a
   50F8 30 03         [12] 1069 	jr	NC,00102$
                           1070 ;src/main.c:507: return TRUE;	
   50FA 2E 01         [ 7] 1071 	ld	l, #0x01
   50FC C9            [10] 1072 	ret
   50FD                    1073 00102$:
                           1074 ;src/main.c:508: return FALSE;
   50FD 2E 00         [ 7] 1075 	ld	l, #0x00
   50FF C9            [10] 1076 	ret
                           1077 ;src/main.c:513: u8 FacingWall(u8 dir) __z88dk_fastcall {
                           1078 ;	---------------------------------
                           1079 ; Function FacingWall
                           1080 ; ---------------------------------
   5100                    1081 _FacingWall::
   5100 4D            [ 4] 1082 	ld	c, l
                           1083 ;src/main.c:515: if (dir == D_right)	{
   5101 79            [ 4] 1084 	ld	a, c
   5102 D6 03         [ 7] 1085 	sub	a, #0x03
   5104 20 19         [12] 1086 	jr	NZ,00108$
                           1087 ;src/main.c:516: tile = GetTilePtr(spr[0].x + 7, spr[0].y + SPR_H);
   5106 3A C4 4B      [13] 1088 	ld	a, (#_spr + 1)
   5109 C6 10         [ 7] 1089 	add	a, #0x10
   510B 57            [ 4] 1090 	ld	d, a
   510C 3A C3 4B      [13] 1091 	ld	a, (#_spr + 0)
   510F C6 07         [ 7] 1092 	add	a, #0x07
   5111 5F            [ 4] 1093 	ld	e,a
   5112 D5            [11] 1094 	push	de
   5113 CD 63 50      [17] 1095 	call	_GetTilePtr
   5116 F1            [10] 1096 	pop	af
                           1097 ;src/main.c:517: if (*tile == 58) return TRUE;
   5117 7E            [ 7] 1098 	ld	a, (hl)
   5118 D6 3A         [ 7] 1099 	sub	a, #0x3a
   511A 20 1F         [12] 1100 	jr	NZ,00109$
   511C 2E 01         [ 7] 1101 	ld	l, #0x01
   511E C9            [10] 1102 	ret
   511F                    1103 00108$:
                           1104 ;src/main.c:519: else if (dir == D_left)	{
   511F 79            [ 4] 1105 	ld	a, c
   5120 D6 02         [ 7] 1106 	sub	a, #0x02
   5122 20 17         [12] 1107 	jr	NZ,00109$
                           1108 ;src/main.c:520: tile = GetTilePtr(spr[0].x, spr[0].y + SPR_H);
   5124 3A C4 4B      [13] 1109 	ld	a, (#_spr + 1)
   5127 C6 10         [ 7] 1110 	add	a, #0x10
   5129 57            [ 4] 1111 	ld	d, a
   512A 21 C3 4B      [10] 1112 	ld	hl, #_spr + 0
   512D 5E            [ 7] 1113 	ld	e, (hl)
   512E D5            [11] 1114 	push	de
   512F CD 63 50      [17] 1115 	call	_GetTilePtr
   5132 F1            [10] 1116 	pop	af
                           1117 ;src/main.c:521: if (*tile == 59) return TRUE;
   5133 7E            [ 7] 1118 	ld	a, (hl)
   5134 D6 3B         [ 7] 1119 	sub	a, #0x3b
   5136 20 03         [12] 1120 	jr	NZ,00109$
   5138 2E 01         [ 7] 1121 	ld	l, #0x01
   513A C9            [10] 1122 	ret
   513B                    1123 00109$:
                           1124 ;src/main.c:523: return FALSE;
   513B 2E 00         [ 7] 1125 	ld	l, #0x00
   513D C9            [10] 1126 	ret
                           1127 ;src/main.c:540: cpct_keyID ReturnKeyPressed() {
                           1128 ;	---------------------------------
                           1129 ; Function ReturnKeyPressed
                           1130 ; ---------------------------------
   513E                    1131 _ReturnKeyPressed::
   513E DD E5         [15] 1132 	push	ix
   5140 DD 21 00 00   [14] 1133 	ld	ix,#0
   5144 DD 39         [15] 1134 	add	ix,sp
   5146 F5            [11] 1135 	push	af
   5147 3B            [ 6] 1136 	dec	sp
                           1137 ;src/main.c:541: u8 i = 10, *keys = cpct_keyboardStatusBuffer + 9;
   5148 0E 0A         [ 7] 1138 	ld	c, #0x0a
                           1139 ;src/main.c:544: do { cpct_scanKeyboard(); } while ( ! cpct_isAnyKeyPressed() );
   514A                    1140 00101$:
   514A C5            [11] 1141 	push	bc
   514B CD FB 4A      [17] 1142 	call	_cpct_scanKeyboard
   514E CD 56 48      [17] 1143 	call	_cpct_isAnyKeyPressed
   5151 C1            [10] 1144 	pop	bc
   5152 7D            [ 4] 1145 	ld	a, l
   5153 B7            [ 4] 1146 	or	a, a
   5154 28 F4         [12] 1147 	jr	Z,00101$
                           1148 ;src/main.c:546: do {
   5156 DD 36 FE 34   [19] 1149 	ld	-2 (ix), #<((_cpct_keyboardStatusBuffer + 0x0009))
   515A DD 36 FF 48   [19] 1150 	ld	-1 (ix), #>((_cpct_keyboardStatusBuffer + 0x0009))
   515E DD 36 FD 0A   [19] 1151 	ld	-3 (ix), #0x0a
   5162                    1152 00106$:
                           1153 ;src/main.c:547: keypressed = *keys ^ 0xFF;
   5162 DD 6E FE      [19] 1154 	ld	l,-2 (ix)
   5165 DD 66 FF      [19] 1155 	ld	h,-1 (ix)
   5168 7E            [ 7] 1156 	ld	a, (hl)
   5169 EE FF         [ 7] 1157 	xor	a, #0xff
   516B 6F            [ 4] 1158 	ld	l, a
   516C 26 00         [ 7] 1159 	ld	h, #0x00
                           1160 ;src/main.c:548: if (keypressed)
   516E 7C            [ 4] 1161 	ld	a, h
   516F B5            [ 4] 1162 	or	a,l
   5170 28 09         [12] 1163 	jr	Z,00105$
                           1164 ;src/main.c:549: return (keypressed << 8) + (i - 1); 
   5172 65            [ 4] 1165 	ld	h, l
   5173 2E 00         [ 7] 1166 	ld	l, #0x00
   5175 06 00         [ 7] 1167 	ld	b, #0x00
   5177 0B            [ 6] 1168 	dec	bc
   5178 09            [11] 1169 	add	hl, bc
   5179 18 1C         [12] 1170 	jr	00109$
   517B                    1171 00105$:
                           1172 ;src/main.c:550: keys--;
   517B DD 7E FE      [19] 1173 	ld	a, -2 (ix)
   517E C6 FF         [ 7] 1174 	add	a, #0xff
   5180 DD 77 FE      [19] 1175 	ld	-2 (ix), a
   5183 DD 7E FF      [19] 1176 	ld	a, -1 (ix)
   5186 CE FF         [ 7] 1177 	adc	a, #0xff
   5188 DD 77 FF      [19] 1178 	ld	-1 (ix), a
                           1179 ;src/main.c:551: } while(--i);
   518B DD 35 FD      [23] 1180 	dec	-3 (ix)
   518E DD 4E FD      [19] 1181 	ld	c, -3 (ix)
   5191 DD 7E FD      [19] 1182 	ld	a, -3 (ix)
   5194 B7            [ 4] 1183 	or	a, a
   5195 20 CB         [12] 1184 	jr	NZ,00106$
                           1185 ;src/main.c:552: return keypressed;    
   5197                    1186 00109$:
   5197 DD F9         [10] 1187 	ld	sp, ix
   5199 DD E1         [14] 1188 	pop	ix
   519B C9            [10] 1189 	ret
                           1190 ;src/main.c:558: void Wait4Key(cpct_keyID key) __z88dk_fastcall {
                           1191 ;	---------------------------------
                           1192 ; Function Wait4Key
                           1193 ; ---------------------------------
   519C                    1194 _Wait4Key::
                           1195 ;src/main.c:559: do cpct_scanKeyboard_f();
   519C                    1196 00101$:
   519C E5            [11] 1197 	push	hl
   519D CD 3D 3E      [17] 1198 	call	_cpct_scanKeyboard_f
   51A0 E1            [10] 1199 	pop	hl
                           1200 ;src/main.c:560: while(!cpct_isKeyPressed(key));
   51A1 E5            [11] 1201 	push	hl
   51A2 CD 31 3E      [17] 1202 	call	_cpct_isKeyPressed
   51A5 7D            [ 4] 1203 	ld	a, l
   51A6 E1            [10] 1204 	pop	hl
   51A7 B7            [ 4] 1205 	or	a, a
   51A8 28 F2         [12] 1206 	jr	Z,00101$
                           1207 ;src/main.c:561: do cpct_scanKeyboard_f();
   51AA                    1208 00104$:
   51AA E5            [11] 1209 	push	hl
   51AB CD 3D 3E      [17] 1210 	call	_cpct_scanKeyboard_f
   51AE E1            [10] 1211 	pop	hl
                           1212 ;src/main.c:562: while(cpct_isKeyPressed(key));
   51AF E5            [11] 1213 	push	hl
   51B0 CD 31 3E      [17] 1214 	call	_cpct_isKeyPressed
   51B3 7D            [ 4] 1215 	ld	a, l
   51B4 E1            [10] 1216 	pop	hl
   51B5 B7            [ 4] 1217 	or	a, a
   51B6 20 F2         [12] 1218 	jr	NZ,00104$
   51B8 C9            [10] 1219 	ret
                           1220 ;src/main.c:567: cpct_keyID RedefineKey(u8 *info) __z88dk_fastcall {
                           1221 ;	---------------------------------
                           1222 ; Function RedefineKey
                           1223 ; ---------------------------------
   51B9                    1224 _RedefineKey::
                           1225 ;src/main.c:569: PrintText(info, 29, 100);  
   51B9 01 1D 64      [10] 1226 	ld	bc, #0x641d
   51BC C5            [11] 1227 	push	bc
   51BD E5            [11] 1228 	push	hl
   51BE CD 01 4F      [17] 1229 	call	_PrintText
   51C1 F1            [10] 1230 	pop	af
   51C2 F1            [10] 1231 	pop	af
                           1232 ;src/main.c:570: key = ReturnKeyPressed();
   51C3 CD 3E 51      [17] 1233 	call	_ReturnKeyPressed
                           1234 ;src/main.c:571: Wait4Key(key);
   51C6 E5            [11] 1235 	push	hl
   51C7 CD 9C 51      [17] 1236 	call	_Wait4Key
   51CA 3E 02         [ 7] 1237 	ld	a, #0x02
   51CC F5            [11] 1238 	push	af
   51CD 33            [ 6] 1239 	inc	sp
   51CE 01 00 00      [10] 1240 	ld	bc, #0x0000
   51D1 C5            [11] 1241 	push	bc
   51D2 01 29 00      [10] 1242 	ld	bc, #0x0029
   51D5 C5            [11] 1243 	push	bc
   51D6 01 02 0F      [10] 1244 	ld	bc, #0x0f02
   51D9 C5            [11] 1245 	push	bc
   51DA CD 5F 46      [17] 1246 	call	_cpct_akp_SFXPlay
   51DD 21 07 00      [10] 1247 	ld	hl, #7
   51E0 39            [11] 1248 	add	hl, sp
   51E1 F9            [ 6] 1249 	ld	sp, hl
   51E2 E1            [10] 1250 	pop	hl
                           1251 ;src/main.c:573: return key;    
   51E3 C9            [10] 1252 	ret
                           1253 ;src/main.c:590: void PrintObject(u8 ident, u8 x, u8 y) {
                           1254 ;	---------------------------------
                           1255 ; Function PrintObject
                           1256 ; ---------------------------------
   51E4                    1257 _PrintObject::
   51E4 DD E5         [15] 1258 	push	ix
   51E6 DD 21 00 00   [14] 1259 	ld	ix,#0
   51EA DD 39         [15] 1260 	add	ix,sp
                           1261 ;src/main.c:592: OBJ_W, OBJ_H, g_maskTable);
                           1262 ;src/main.c:591: cpct_drawSpriteMaskedAlignedTable(g_objects[ident], cpct_getScreenPtr(CPCT_VMEM_START, x, y),
   51EC DD 66 06      [19] 1263 	ld	h, 6 (ix)
   51EF DD 6E 05      [19] 1264 	ld	l, 5 (ix)
   51F2 E5            [11] 1265 	push	hl
   51F3 21 00 C0      [10] 1266 	ld	hl, #0xc000
   51F6 E5            [11] 1267 	push	hl
   51F7 CD AA 4A      [17] 1268 	call	_cpct_getScreenPtr
   51FA 4D            [ 4] 1269 	ld	c, l
   51FB 44            [ 4] 1270 	ld	b, h
   51FC DD 5E 04      [19] 1271 	ld	e,4 (ix)
   51FF 16 00         [ 7] 1272 	ld	d,#0x00
   5201 6B            [ 4] 1273 	ld	l, e
   5202 62            [ 4] 1274 	ld	h, d
   5203 29            [11] 1275 	add	hl, hl
   5204 19            [11] 1276 	add	hl, de
   5205 29            [11] 1277 	add	hl, hl
   5206 29            [11] 1278 	add	hl, hl
   5207 29            [11] 1279 	add	hl, hl
   5208 29            [11] 1280 	add	hl, hl
   5209 29            [11] 1281 	add	hl, hl
   520A 11 79 3A      [10] 1282 	ld	de, #_g_objects
   520D 19            [11] 1283 	add	hl, de
   520E 11 00 01      [10] 1284 	ld	de, #_g_maskTable
   5211 D5            [11] 1285 	push	de
   5212 11 06 10      [10] 1286 	ld	de, #0x1006
   5215 D5            [11] 1287 	push	de
   5216 C5            [11] 1288 	push	bc
   5217 E5            [11] 1289 	push	hl
   5218 CD C0 4A      [17] 1290 	call	_cpct_drawSpriteMaskedAlignedTable
   521B DD E1         [14] 1291 	pop	ix
   521D C9            [10] 1292 	ret
                           1293 ;src/main.c:597: void DeleteObject(TObj *pObj) __z88dk_fastcall {
                           1294 ;	---------------------------------
                           1295 ; Function DeleteObject
                           1296 ; ---------------------------------
   521E                    1297 _DeleteObject::
   521E DD E5         [15] 1298 	push	ix
   5220 DD 21 00 00   [14] 1299 	ld	ix,#0
   5224 DD 39         [15] 1300 	add	ix,sp
   5226 3B            [ 6] 1301 	dec	sp
                           1302 ;src/main.c:599: 4 + (pObj->x & 1),	4 + (pObj->y & 3 ? 1 : 0),	
   5227 4D            [ 4] 1303 	ld	c,l
   5228 44            [ 4] 1304 	ld	b,h
   5229 23            [ 6] 1305 	inc	hl
   522A 5E            [ 7] 1306 	ld	e, (hl)
   522B 7B            [ 4] 1307 	ld	a, e
   522C E6 03         [ 7] 1308 	and	a, #0x03
   522E 28 04         [12] 1309 	jr	Z,00103$
   5230 16 01         [ 7] 1310 	ld	d, #0x01
   5232 18 02         [12] 1311 	jr	00104$
   5234                    1312 00103$:
   5234 16 00         [ 7] 1313 	ld	d, #0x00
   5236                    1314 00104$:
   5236 14            [ 4] 1315 	inc	d
   5237 14            [ 4] 1316 	inc	d
   5238 14            [ 4] 1317 	inc	d
   5239 14            [ 4] 1318 	inc	d
   523A 0A            [ 7] 1319 	ld	a, (bc)
   523B 4F            [ 4] 1320 	ld	c,a
   523C E6 01         [ 7] 1321 	and	a, #0x01
   523E C6 04         [ 7] 1322 	add	a, #0x04
   5240 DD 77 FF      [19] 1323 	ld	-1 (ix), a
                           1324 ;src/main.c:598: cpct_etm_drawTileBox2x4(pObj->x / 2, (pObj->y - ORIG_MAP_Y) / 4, 
   5243 06 00         [ 7] 1325 	ld	b, #0x00
   5245 6B            [ 4] 1326 	ld	l, e
   5246 60            [ 4] 1327 	ld	h, b
   5247 CB 78         [ 8] 1328 	bit	7, b
   5249 28 05         [12] 1329 	jr	Z,00105$
   524B 6B            [ 4] 1330 	ld	l, e
   524C 60            [ 4] 1331 	ld	h, b
   524D 23            [ 6] 1332 	inc	hl
   524E 23            [ 6] 1333 	inc	hl
   524F 23            [ 6] 1334 	inc	hl
   5250                    1335 00105$:
   5250 CB 2C         [ 8] 1336 	sra	h
   5252 CB 1D         [ 8] 1337 	rr	l
   5254 CB 2C         [ 8] 1338 	sra	h
   5256 CB 1D         [ 8] 1339 	rr	l
   5258 5D            [ 4] 1340 	ld	e, l
   5259 CB 39         [ 8] 1341 	srl	c
   525B 21 31 10      [10] 1342 	ld	hl, #0x1031
   525E E5            [11] 1343 	push	hl
   525F 21 00 C0      [10] 1344 	ld	hl, #0xc000
   5262 E5            [11] 1345 	push	hl
   5263 3E 28         [ 7] 1346 	ld	a, #0x28
   5265 F5            [11] 1347 	push	af
   5266 33            [ 6] 1348 	inc	sp
   5267 D5            [11] 1349 	push	de
   5268 33            [ 6] 1350 	inc	sp
   5269 DD 56 FF      [19] 1351 	ld	d, -1 (ix)
   526C D5            [11] 1352 	push	de
   526D 79            [ 4] 1353 	ld	a, c
   526E F5            [11] 1354 	push	af
   526F 33            [ 6] 1355 	inc	sp
   5270 CD 81 47      [17] 1356 	call	_cpct_etm_drawTileBox2x4
   5273 33            [ 6] 1357 	inc	sp
   5274 DD E1         [14] 1358 	pop	ix
   5276 C9            [10] 1359 	ret
                           1360 ;src/main.c:605: void DeleteObjectScoreboard() {
                           1361 ;	---------------------------------
                           1362 ; Function DeleteObjectScoreboard
                           1363 ; ---------------------------------
   5277                    1364 _DeleteObjectScoreboard::
                           1365 ;src/main.c:606: cpct_drawSolidBox(cpctm_screenPtr(CPCT_VMEM_START, 68, 12), cpct_px2byteM0(1,1), 6, 16);
   5277 21 01 01      [10] 1366 	ld	hl, #0x0101
   527A E5            [11] 1367 	push	hl
   527B CD 8E 49      [17] 1368 	call	_cpct_px2byteM0
   527E 26 00         [ 7] 1369 	ld	h, #0x00
   5280 01 06 10      [10] 1370 	ld	bc, #0x1006
   5283 C5            [11] 1371 	push	bc
   5284 E5            [11] 1372 	push	hl
   5285 21 94 E0      [10] 1373 	ld	hl, #0xe094
   5288 E5            [11] 1374 	push	hl
   5289 CD C8 49      [17] 1375 	call	_cpct_drawSolidBox
   528C C9            [10] 1376 	ret
                           1377 ;src/main.c:611: void ReprintObjects() {
                           1378 ;	---------------------------------
                           1379 ; Function ReprintObjects
                           1380 ; ---------------------------------
   528D                    1381 _ReprintObjects::
                           1382 ;src/main.c:612: ct = 0;
   528D 21 B2 4B      [10] 1383 	ld	hl,#_ct + 0
   5290 36 00         [10] 1384 	ld	(hl), #0x00
                           1385 ;src/main.c:613: while (ct < N_MAX_OBJ) {
   5292                    1386 00104$:
   5292 3A B2 4B      [13] 1387 	ld	a,(#_ct + 0)
   5295 D6 08         [ 7] 1388 	sub	a, #0x08
   5297 D0            [11] 1389 	ret	NC
                           1390 ;src/main.c:614: if (obj[ct].mapNumber == mapNumber && obj[ct].taken == FALSE)
   5298 ED 4B B2 4B   [20] 1391 	ld	bc, (_ct)
   529C 06 00         [ 7] 1392 	ld	b, #0x00
   529E 69            [ 4] 1393 	ld	l, c
   529F 60            [ 4] 1394 	ld	h, b
   52A0 29            [11] 1395 	add	hl, hl
   52A1 29            [11] 1396 	add	hl, hl
   52A2 09            [11] 1397 	add	hl, bc
   52A3 01 2B 4C      [10] 1398 	ld	bc,#_obj
   52A6 09            [11] 1399 	add	hl,bc
   52A7 4D            [ 4] 1400 	ld	c,l
   52A8 44            [ 4] 1401 	ld	b,h
   52A9 23            [ 6] 1402 	inc	hl
   52AA 23            [ 6] 1403 	inc	hl
   52AB 5E            [ 7] 1404 	ld	e, (hl)
   52AC 3A 57 4C      [13] 1405 	ld	a,(#_mapNumber + 0)
   52AF 93            [ 4] 1406 	sub	a, e
   52B0 20 1A         [12] 1407 	jr	NZ,00102$
   52B2 69            [ 4] 1408 	ld	l, c
   52B3 60            [ 4] 1409 	ld	h, b
   52B4 23            [ 6] 1410 	inc	hl
   52B5 23            [ 6] 1411 	inc	hl
   52B6 23            [ 6] 1412 	inc	hl
   52B7 7E            [ 7] 1413 	ld	a, (hl)
   52B8 B7            [ 4] 1414 	or	a, a
   52B9 20 11         [12] 1415 	jr	NZ,00102$
                           1416 ;src/main.c:615: PrintObject(ct, obj[ct].x, obj[ct].y);
   52BB 69            [ 4] 1417 	ld	l, c
   52BC 60            [ 4] 1418 	ld	h, b
   52BD 23            [ 6] 1419 	inc	hl
   52BE 56            [ 7] 1420 	ld	d, (hl)
   52BF 0A            [ 7] 1421 	ld	a, (bc)
   52C0 5F            [ 4] 1422 	ld	e,a
   52C1 D5            [11] 1423 	push	de
   52C2 3A B2 4B      [13] 1424 	ld	a, (_ct)
   52C5 F5            [11] 1425 	push	af
   52C6 33            [ 6] 1426 	inc	sp
   52C7 CD E4 51      [17] 1427 	call	_PrintObject
   52CA F1            [10] 1428 	pop	af
   52CB 33            [ 6] 1429 	inc	sp
   52CC                    1430 00102$:
                           1431 ;src/main.c:616: ct++;
   52CC 21 B2 4B      [10] 1432 	ld	hl, #_ct+0
   52CF 34            [11] 1433 	inc	(hl)
   52D0 18 C0         [12] 1434 	jr	00104$
                           1435 ;src/main.c:622: void CheckObjects() {
                           1436 ;	---------------------------------
                           1437 ; Function CheckObjects
                           1438 ; ---------------------------------
   52D2                    1439 _CheckObjects::
   52D2 DD E5         [15] 1440 	push	ix
   52D4 DD 21 00 00   [14] 1441 	ld	ix,#0
   52D8 DD 39         [15] 1442 	add	ix,sp
   52DA F5            [11] 1443 	push	af
                           1444 ;src/main.c:623: ct = 0;
   52DB 21 B2 4B      [10] 1445 	ld	hl,#_ct + 0
   52DE 36 00         [10] 1446 	ld	(hl), #0x00
                           1447 ;src/main.c:624: Wait4Key(ctlDown);
   52E0 2A B5 4B      [16] 1448 	ld	hl, (_ctlDown)
   52E3 CD 9C 51      [17] 1449 	call	_Wait4Key
                           1450 ;src/main.c:625: while (ct < N_MAX_OBJ) {
   52E6                    1451 00122$:
   52E6 3A B2 4B      [13] 1452 	ld	a,(#_ct + 0)
   52E9 D6 08         [ 7] 1453 	sub	a, #0x08
   52EB D2 9A 54      [10] 1454 	jp	NC, 00125$
                           1455 ;src/main.c:626: if (obj[ct].mapNumber == mapNumber) { // if the object is on the screen ...
   52EE ED 4B B2 4B   [20] 1456 	ld	bc, (_ct)
   52F2 06 00         [ 7] 1457 	ld	b, #0x00
   52F4 69            [ 4] 1458 	ld	l, c
   52F5 60            [ 4] 1459 	ld	h, b
   52F6 29            [11] 1460 	add	hl, hl
   52F7 29            [11] 1461 	add	hl, hl
   52F8 09            [11] 1462 	add	hl, bc
   52F9 01 2B 4C      [10] 1463 	ld	bc,#_obj
   52FC 09            [11] 1464 	add	hl,bc
   52FD E3            [19] 1465 	ex	(sp), hl
   52FE E1            [10] 1466 	pop	hl
   52FF E5            [11] 1467 	push	hl
   5300 23            [ 6] 1468 	inc	hl
   5301 23            [ 6] 1469 	inc	hl
   5302 4E            [ 7] 1470 	ld	c, (hl)
   5303 3A 57 4C      [13] 1471 	ld	a,(#_mapNumber + 0)
   5306 91            [ 4] 1472 	sub	a, c
   5307 C2 93 54      [10] 1473 	jp	NZ,00121$
                           1474 ;src/main.c:628: if (spr[0].x >= obj[ct].x - 3 && spr[0].x <= obj[ct].x + 3 &&	
   530A 21 C3 4B      [10] 1475 	ld	hl, #_spr + 0
   530D 4E            [ 7] 1476 	ld	c, (hl)
   530E E1            [10] 1477 	pop	hl
   530F E5            [11] 1478 	push	hl
   5310 5E            [ 7] 1479 	ld	e, (hl)
   5311 16 00         [ 7] 1480 	ld	d, #0x00
   5313 7B            [ 4] 1481 	ld	a, e
   5314 C6 FD         [ 7] 1482 	add	a, #0xfd
   5316 6F            [ 4] 1483 	ld	l, a
   5317 7A            [ 4] 1484 	ld	a, d
   5318 CE FF         [ 7] 1485 	adc	a, #0xff
   531A 67            [ 4] 1486 	ld	h, a
   531B 06 00         [ 7] 1487 	ld	b, #0x00
   531D 79            [ 4] 1488 	ld	a, c
   531E 95            [ 4] 1489 	sub	a, l
   531F 78            [ 4] 1490 	ld	a, b
   5320 9C            [ 4] 1491 	sbc	a, h
   5321 E2 26 53      [10] 1492 	jp	PO, 00181$
   5324 EE 80         [ 7] 1493 	xor	a, #0x80
   5326                    1494 00181$:
   5326 FA 93 54      [10] 1495 	jp	M, 00121$
   5329 13            [ 6] 1496 	inc	de
   532A 13            [ 6] 1497 	inc	de
   532B 13            [ 6] 1498 	inc	de
   532C 6A            [ 4] 1499 	ld	l, d
   532D 7B            [ 4] 1500 	ld	a, e
   532E 91            [ 4] 1501 	sub	a, c
   532F 7D            [ 4] 1502 	ld	a, l
   5330 98            [ 4] 1503 	sbc	a, b
   5331 E2 36 53      [10] 1504 	jp	PO, 00182$
   5334 EE 80         [ 7] 1505 	xor	a, #0x80
   5336                    1506 00182$:
   5336 FA 93 54      [10] 1507 	jp	M, 00121$
                           1508 ;src/main.c:629: spr[0].y >= obj[ct].y - 4 && spr[0].y <= obj[ct].y + 4) {
   5339 21 C4 4B      [10] 1509 	ld	hl, #_spr + 1
   533C 4E            [ 7] 1510 	ld	c, (hl)
   533D E1            [10] 1511 	pop	hl
   533E E5            [11] 1512 	push	hl
   533F 23            [ 6] 1513 	inc	hl
   5340 5E            [ 7] 1514 	ld	e, (hl)
   5341 16 00         [ 7] 1515 	ld	d, #0x00
   5343 7B            [ 4] 1516 	ld	a, e
   5344 C6 FC         [ 7] 1517 	add	a, #0xfc
   5346 6F            [ 4] 1518 	ld	l, a
   5347 7A            [ 4] 1519 	ld	a, d
   5348 CE FF         [ 7] 1520 	adc	a, #0xff
   534A 47            [ 4] 1521 	ld	b, a
   534B 26 00         [ 7] 1522 	ld	h, #0x00
   534D 79            [ 4] 1523 	ld	a, c
   534E 95            [ 4] 1524 	sub	a, l
   534F 7C            [ 4] 1525 	ld	a, h
   5350 98            [ 4] 1526 	sbc	a, b
   5351 E2 56 53      [10] 1527 	jp	PO, 00183$
   5354 EE 80         [ 7] 1528 	xor	a, #0x80
   5356                    1529 00183$:
   5356 FA 93 54      [10] 1530 	jp	M, 00121$
   5359 13            [ 6] 1531 	inc	de
   535A 13            [ 6] 1532 	inc	de
   535B 13            [ 6] 1533 	inc	de
   535C 13            [ 6] 1534 	inc	de
   535D 7B            [ 4] 1535 	ld	a, e
   535E 91            [ 4] 1536 	sub	a, c
   535F 7A            [ 4] 1537 	ld	a, d
   5360 9C            [ 4] 1538 	sbc	a, h
   5361 E2 66 53      [10] 1539 	jp	PO, 00184$
   5364 EE 80         [ 7] 1540 	xor	a, #0x80
   5366                    1541 00184$:
   5366 FA 93 54      [10] 1542 	jp	M, 00121$
                           1543 ;src/main.c:630: if (ct > 5) { // first aid kit or ammunition					
   5369 3E 05         [ 7] 1544 	ld	a, #0x05
   536B FD 21 B2 4B   [14] 1545 	ld	iy, #_ct
   536F FD 96 00      [19] 1546 	sub	a, 0 (iy)
   5372 30 62         [12] 1547 	jr	NC,00113$
                           1548 ;src/main.c:631: if (obj[ct].taken == FALSE) {
   5374 E1            [10] 1549 	pop	hl
   5375 E5            [11] 1550 	push	hl
   5376 23            [ 6] 1551 	inc	hl
   5377 23            [ 6] 1552 	inc	hl
   5378 23            [ 6] 1553 	inc	hl
   5379 7E            [ 7] 1554 	ld	a, (hl)
   537A B7            [ 4] 1555 	or	a, a
   537B C2 8E 54      [10] 1556 	jp	NZ, 00114$
                           1557 ;src/main.c:632: cpct_akp_SFXPlay (6, 12, 41, 0, 0, AY_CHANNEL_A);
   537E 3E 01         [ 7] 1558 	ld	a, #0x01
   5380 F5            [11] 1559 	push	af
   5381 33            [ 6] 1560 	inc	sp
   5382 21 00 00      [10] 1561 	ld	hl, #0x0000
   5385 E5            [11] 1562 	push	hl
   5386 2E 29         [ 7] 1563 	ld	l, #0x29
   5388 E5            [11] 1564 	push	hl
   5389 21 06 0C      [10] 1565 	ld	hl, #0x0c06
   538C E5            [11] 1566 	push	hl
   538D CD 5F 46      [17] 1567 	call	_cpct_akp_SFXPlay
   5390 21 07 00      [10] 1568 	ld	hl, #7
   5393 39            [11] 1569 	add	hl, sp
   5394 F9            [ 6] 1570 	ld	sp, hl
                           1571 ;src/main.c:633: if (ct == 6) spr[0].lives = 9; // first aid kit
   5395 3A B2 4B      [13] 1572 	ld	a,(#_ct + 0)
   5398 D6 06         [ 7] 1573 	sub	a, #0x06
   539A 20 05         [12] 1574 	jr	NZ,00102$
   539C 21 CC 4B      [10] 1575 	ld	hl, #(_spr + 0x0009)
   539F 36 09         [10] 1576 	ld	(hl), #0x09
   53A1                    1577 00102$:
                           1578 ;src/main.c:634: if (ct == 7) ammo = 99; // ammunition
   53A1 3A B2 4B      [13] 1579 	ld	a,(#_ct + 0)
   53A4 D6 07         [ 7] 1580 	sub	a, #0x07
   53A6 20 05         [12] 1581 	jr	NZ,00104$
   53A8 21 AF 4B      [10] 1582 	ld	hl,#_ammo + 0
   53AB 36 63         [10] 1583 	ld	(hl), #0x63
   53AD                    1584 00104$:
                           1585 ;src/main.c:635: DeleteObject(&obj[ct]); 
   53AD ED 4B B2 4B   [20] 1586 	ld	bc, (_ct)
   53B1 06 00         [ 7] 1587 	ld	b, #0x00
   53B3 69            [ 4] 1588 	ld	l, c
   53B4 60            [ 4] 1589 	ld	h, b
   53B5 29            [11] 1590 	add	hl, hl
   53B6 29            [11] 1591 	add	hl, hl
   53B7 09            [11] 1592 	add	hl, bc
   53B8 11 2B 4C      [10] 1593 	ld	de, #_obj
   53BB 19            [11] 1594 	add	hl, de
   53BC CD 1E 52      [17] 1595 	call	_DeleteObject
                           1596 ;src/main.c:637: obj[ct].taken = TRUE;
   53BF ED 4B B2 4B   [20] 1597 	ld	bc, (_ct)
   53C3 06 00         [ 7] 1598 	ld	b, #0x00
   53C5 69            [ 4] 1599 	ld	l, c
   53C6 60            [ 4] 1600 	ld	h, b
   53C7 29            [11] 1601 	add	hl, hl
   53C8 29            [11] 1602 	add	hl, hl
   53C9 09            [11] 1603 	add	hl, bc
   53CA 11 2B 4C      [10] 1604 	ld	de, #_obj
   53CD 19            [11] 1605 	add	hl, de
   53CE 23            [ 6] 1606 	inc	hl
   53CF 23            [ 6] 1607 	inc	hl
   53D0 23            [ 6] 1608 	inc	hl
   53D1 36 01         [10] 1609 	ld	(hl), #0x01
   53D3 C3 8E 54      [10] 1610 	jp	00114$
   53D6                    1611 00113$:
                           1612 ;src/main.c:641: else if (spr[0].object != ct) {
   53D6 21 CF 4B      [10] 1613 	ld	hl, #(_spr + 0x000c) + 0
   53D9 4E            [ 7] 1614 	ld	c, (hl)
   53DA 3A B2 4B      [13] 1615 	ld	a,(#_ct + 0)
   53DD 91            [ 4] 1616 	sub	a, c
   53DE 28 5B         [12] 1617 	jr	Z,00110$
                           1618 ;src/main.c:643: if (spr[0].object == 255) {	
   53E0 0C            [ 4] 1619 	inc	c
   53E1 C2 8E 54      [10] 1620 	jp	NZ,00114$
                           1621 ;src/main.c:644: cpct_akp_SFXPlay(8, 15, 45, 0, 0, AY_CHANNEL_A);
   53E4 3E 01         [ 7] 1622 	ld	a, #0x01
   53E6 F5            [11] 1623 	push	af
   53E7 33            [ 6] 1624 	inc	sp
   53E8 21 00 00      [10] 1625 	ld	hl, #0x0000
   53EB E5            [11] 1626 	push	hl
   53EC 2E 2D         [ 7] 1627 	ld	l, #0x2d
   53EE E5            [11] 1628 	push	hl
   53EF 21 08 0F      [10] 1629 	ld	hl, #0x0f08
   53F2 E5            [11] 1630 	push	hl
   53F3 CD 5F 46      [17] 1631 	call	_cpct_akp_SFXPlay
   53F6 21 07 00      [10] 1632 	ld	hl, #7
   53F9 39            [11] 1633 	add	hl, sp
   53FA F9            [ 6] 1634 	ld	sp, hl
                           1635 ;src/main.c:645: spr[0].object = ct;
   53FB 21 CF 4B      [10] 1636 	ld	hl, #(_spr + 0x000c)
   53FE 3A B2 4B      [13] 1637 	ld	a,(#_ct + 0)
   5401 77            [ 7] 1638 	ld	(hl), a
                           1639 ;src/main.c:646: obj[ct].taken = TRUE;
   5402 ED 4B B2 4B   [20] 1640 	ld	bc, (_ct)
   5406 06 00         [ 7] 1641 	ld	b, #0x00
   5408 69            [ 4] 1642 	ld	l, c
   5409 60            [ 4] 1643 	ld	h, b
   540A 29            [11] 1644 	add	hl, hl
   540B 29            [11] 1645 	add	hl, hl
   540C 09            [11] 1646 	add	hl, bc
   540D 11 2B 4C      [10] 1647 	ld	de, #_obj
   5410 19            [11] 1648 	add	hl, de
   5411 23            [ 6] 1649 	inc	hl
   5412 23            [ 6] 1650 	inc	hl
   5413 23            [ 6] 1651 	inc	hl
   5414 36 01         [10] 1652 	ld	(hl), #0x01
                           1653 ;src/main.c:647: DeleteObject(&obj[ct]); 
   5416 ED 4B B2 4B   [20] 1654 	ld	bc, (_ct)
   541A 06 00         [ 7] 1655 	ld	b, #0x00
   541C 69            [ 4] 1656 	ld	l, c
   541D 60            [ 4] 1657 	ld	h, b
   541E 29            [11] 1658 	add	hl, hl
   541F 29            [11] 1659 	add	hl, hl
   5420 09            [11] 1660 	add	hl, bc
   5421 11 2B 4C      [10] 1661 	ld	de, #_obj
   5424 19            [11] 1662 	add	hl, de
   5425 CD 1E 52      [17] 1663 	call	_DeleteObject
                           1664 ;src/main.c:649: DeleteObjectScoreboard(); PrintObject(ct, 68, 12); 
   5428 CD 77 52      [17] 1665 	call	_DeleteObjectScoreboard
   542B 21 44 0C      [10] 1666 	ld	hl, #0x0c44
   542E E5            [11] 1667 	push	hl
   542F 3A B2 4B      [13] 1668 	ld	a, (_ct)
   5432 F5            [11] 1669 	push	af
   5433 33            [ 6] 1670 	inc	sp
   5434 CD E4 51      [17] 1671 	call	_PrintObject
   5437 F1            [10] 1672 	pop	af
   5438 33            [ 6] 1673 	inc	sp
   5439 18 53         [12] 1674 	jr	00114$
   543B                    1675 00110$:
                           1676 ;src/main.c:653: cpct_akp_SFXPlay(7, 15, 45, 0, 0, AY_CHANNEL_A);
   543B 3E 01         [ 7] 1677 	ld	a, #0x01
   543D F5            [11] 1678 	push	af
   543E 33            [ 6] 1679 	inc	sp
   543F 21 00 00      [10] 1680 	ld	hl, #0x0000
   5442 E5            [11] 1681 	push	hl
   5443 2E 2D         [ 7] 1682 	ld	l, #0x2d
   5445 E5            [11] 1683 	push	hl
   5446 21 07 0F      [10] 1684 	ld	hl, #0x0f07
   5449 E5            [11] 1685 	push	hl
   544A CD 5F 46      [17] 1686 	call	_cpct_akp_SFXPlay
   544D 21 07 00      [10] 1687 	ld	hl, #7
   5450 39            [11] 1688 	add	hl, sp
   5451 F9            [ 6] 1689 	ld	sp, hl
                           1690 ;src/main.c:655: PrintObject(ct, obj[ct].x, obj[ct].y);	
   5452 ED 4B B2 4B   [20] 1691 	ld	bc, (_ct)
   5456 06 00         [ 7] 1692 	ld	b, #0x00
   5458 69            [ 4] 1693 	ld	l, c
   5459 60            [ 4] 1694 	ld	h, b
   545A 29            [11] 1695 	add	hl, hl
   545B 29            [11] 1696 	add	hl, hl
   545C 09            [11] 1697 	add	hl, bc
   545D 01 2B 4C      [10] 1698 	ld	bc,#_obj
   5460 09            [11] 1699 	add	hl,bc
   5461 4D            [ 4] 1700 	ld	c,l
   5462 44            [ 4] 1701 	ld	b,h
   5463 23            [ 6] 1702 	inc	hl
   5464 56            [ 7] 1703 	ld	d, (hl)
   5465 0A            [ 7] 1704 	ld	a, (bc)
   5466 5F            [ 4] 1705 	ld	e,a
   5467 D5            [11] 1706 	push	de
   5468 3A B2 4B      [13] 1707 	ld	a, (_ct)
   546B F5            [11] 1708 	push	af
   546C 33            [ 6] 1709 	inc	sp
   546D CD E4 51      [17] 1710 	call	_PrintObject
   5470 F1            [10] 1711 	pop	af
   5471 33            [ 6] 1712 	inc	sp
                           1713 ;src/main.c:656: DeleteObjectScoreboard();
   5472 CD 77 52      [17] 1714 	call	_DeleteObjectScoreboard
                           1715 ;src/main.c:657: spr[0].object = 255;
   5475 21 CF 4B      [10] 1716 	ld	hl, #(_spr + 0x000c)
   5478 36 FF         [10] 1717 	ld	(hl), #0xff
                           1718 ;src/main.c:658: obj[ct].taken = FALSE;
   547A ED 4B B2 4B   [20] 1719 	ld	bc, (_ct)
   547E 06 00         [ 7] 1720 	ld	b, #0x00
   5480 69            [ 4] 1721 	ld	l, c
   5481 60            [ 4] 1722 	ld	h, b
   5482 29            [11] 1723 	add	hl, hl
   5483 29            [11] 1724 	add	hl, hl
   5484 09            [11] 1725 	add	hl, bc
   5485 11 2B 4C      [10] 1726 	ld	de, #_obj
   5488 19            [11] 1727 	add	hl, de
   5489 23            [ 6] 1728 	inc	hl
   548A 23            [ 6] 1729 	inc	hl
   548B 23            [ 6] 1730 	inc	hl
   548C 36 00         [10] 1731 	ld	(hl), #0x00
   548E                    1732 00114$:
                           1733 ;src/main.c:661: ct = N_MAX_OBJ;
   548E 21 B2 4B      [10] 1734 	ld	hl,#_ct + 0
   5491 36 08         [10] 1735 	ld	(hl), #0x08
   5493                    1736 00121$:
                           1737 ;src/main.c:664: ct++;
   5493 21 B2 4B      [10] 1738 	ld	hl, #_ct+0
   5496 34            [11] 1739 	inc	(hl)
   5497 C3 E6 52      [10] 1740 	jp	00122$
   549A                    1741 00125$:
   549A DD F9         [10] 1742 	ld	sp, ix
   549C DD E1         [14] 1743 	pop	ix
   549E C9            [10] 1744 	ret
                           1745 ;src/main.c:679: void InitObjects() {
                           1746 ;	---------------------------------
                           1747 ; Function InitObjects
                           1748 ; ---------------------------------
   549F                    1749 _InitObjects::
                           1750 ;src/main.c:671: obj[objNum].x = x; 
   549F 21 2B 4C      [10] 1751 	ld	hl, #_obj
   54A2 36 18         [10] 1752 	ld	(hl), #0x18
                           1753 ;src/main.c:672: obj[objNum].y = y;
   54A4 21 2C 4C      [10] 1754 	ld	hl, #(_obj + 0x0001)
   54A7 36 60         [10] 1755 	ld	(hl), #0x60
                           1756 ;src/main.c:673: obj[objNum].mapNumber = mapNum;
   54A9 21 2D 4C      [10] 1757 	ld	hl, #(_obj + 0x0002)
   54AC 36 00         [10] 1758 	ld	(hl), #0x00
                           1759 ;src/main.c:671: obj[objNum].x = x; 
   54AE 21 30 4C      [10] 1760 	ld	hl, #(_obj + 0x0005)
   54B1 36 00         [10] 1761 	ld	(hl), #0x00
                           1762 ;src/main.c:672: obj[objNum].y = y;
   54B3 21 31 4C      [10] 1763 	ld	hl, #(_obj + 0x0006)
   54B6 36 00         [10] 1764 	ld	(hl), #0x00
                           1765 ;src/main.c:673: obj[objNum].mapNumber = mapNum;
   54B8 21 32 4C      [10] 1766 	ld	hl, #(_obj + 0x0007)
   54BB 36 FF         [10] 1767 	ld	(hl), #0xff
                           1768 ;src/main.c:671: obj[objNum].x = x; 
   54BD 21 35 4C      [10] 1769 	ld	hl, #(_obj + 0x000a)
   54C0 36 2C         [10] 1770 	ld	(hl), #0x2c
                           1771 ;src/main.c:672: obj[objNum].y = y;
   54C2 21 36 4C      [10] 1772 	ld	hl, #(_obj + 0x000b)
   54C5 36 40         [10] 1773 	ld	(hl), #0x40
                           1774 ;src/main.c:673: obj[objNum].mapNumber = mapNum;
   54C7 21 37 4C      [10] 1775 	ld	hl, #(_obj + 0x000c)
   54CA 36 02         [10] 1776 	ld	(hl), #0x02
                           1777 ;src/main.c:671: obj[objNum].x = x; 
   54CC 21 3A 4C      [10] 1778 	ld	hl, #(_obj + 0x000f)
   54CF 36 08         [10] 1779 	ld	(hl), #0x08
                           1780 ;src/main.c:672: obj[objNum].y = y;
   54D1 21 3B 4C      [10] 1781 	ld	hl, #(_obj + 0x0010)
   54D4 36 3C         [10] 1782 	ld	(hl), #0x3c
                           1783 ;src/main.c:673: obj[objNum].mapNumber = mapNum;
   54D6 21 3C 4C      [10] 1784 	ld	hl, #(_obj + 0x0011)
   54D9 36 01         [10] 1785 	ld	(hl), #0x01
                           1786 ;src/main.c:671: obj[objNum].x = x; 
   54DB 21 3F 4C      [10] 1787 	ld	hl, #(_obj + 0x0014)
   54DE 36 00         [10] 1788 	ld	(hl), #0x00
                           1789 ;src/main.c:672: obj[objNum].y = y;
   54E0 21 40 4C      [10] 1790 	ld	hl, #(_obj + 0x0015)
   54E3 36 00         [10] 1791 	ld	(hl), #0x00
                           1792 ;src/main.c:673: obj[objNum].mapNumber = mapNum;
   54E5 21 41 4C      [10] 1793 	ld	hl, #(_obj + 0x0016)
   54E8 36 FF         [10] 1794 	ld	(hl), #0xff
                           1795 ;src/main.c:671: obj[objNum].x = x; 
   54EA 21 44 4C      [10] 1796 	ld	hl, #(_obj + 0x0019)
   54ED 36 00         [10] 1797 	ld	(hl), #0x00
                           1798 ;src/main.c:672: obj[objNum].y = y;
   54EF 21 45 4C      [10] 1799 	ld	hl, #(_obj + 0x001a)
   54F2 36 00         [10] 1800 	ld	(hl), #0x00
                           1801 ;src/main.c:673: obj[objNum].mapNumber = mapNum;
   54F4 21 46 4C      [10] 1802 	ld	hl, #(_obj + 0x001b)
   54F7 36 FF         [10] 1803 	ld	(hl), #0xff
                           1804 ;src/main.c:671: obj[objNum].x = x; 
   54F9 21 49 4C      [10] 1805 	ld	hl, #(_obj + 0x001e)
   54FC 36 42         [10] 1806 	ld	(hl), #0x42
                           1807 ;src/main.c:672: obj[objNum].y = y;
   54FE 21 4A 4C      [10] 1808 	ld	hl, #(_obj + 0x001f)
   5501 36 80         [10] 1809 	ld	(hl), #0x80
                           1810 ;src/main.c:673: obj[objNum].mapNumber = mapNum;
   5503 21 4B 4C      [10] 1811 	ld	hl, #(_obj + 0x0020)
   5506 36 01         [10] 1812 	ld	(hl), #0x01
                           1813 ;src/main.c:671: obj[objNum].x = x; 
   5508 21 4E 4C      [10] 1814 	ld	hl, #(_obj + 0x0023)
   550B 36 44         [10] 1815 	ld	(hl), #0x44
                           1816 ;src/main.c:672: obj[objNum].y = y;
   550D 21 4F 4C      [10] 1817 	ld	hl, #(_obj + 0x0024)
   5510 36 40         [10] 1818 	ld	(hl), #0x40
                           1819 ;src/main.c:673: obj[objNum].mapNumber = mapNum;
   5512 21 50 4C      [10] 1820 	ld	hl, #(_obj + 0x0025)
   5515 36 02         [10] 1821 	ld	(hl), #0x02
                           1822 ;src/main.c:688: SetObjectParams(7, 68,  64,   2); // Ammunition
   5517 C9            [10] 1823 	ret
                           1824 ;src/main.c:703: void PrintSprite(TSpr *pSpr) __z88dk_fastcall {
                           1825 ;	---------------------------------
                           1826 ; Function PrintSprite
                           1827 ; ---------------------------------
   5518                    1828 _PrintSprite::
                           1829 ;src/main.c:706: SPR_W, SPR_H, g_maskTable);
                           1830 ;src/main.c:705: cpct_getScreenPtr(CPCT_VMEM_START, pSpr->x, pSpr->y), 
   5518 4D            [ 4] 1831 	ld	c,l
   5519 44            [ 4] 1832 	ld	b,h
   551A 23            [ 6] 1833 	inc	hl
   551B 56            [ 7] 1834 	ld	d, (hl)
   551C 0A            [ 7] 1835 	ld	a, (bc)
   551D C5            [11] 1836 	push	bc
   551E 5F            [ 4] 1837 	ld	e, a
   551F D5            [11] 1838 	push	de
   5520 21 00 C0      [10] 1839 	ld	hl, #0xc000
   5523 E5            [11] 1840 	push	hl
   5524 CD AA 4A      [17] 1841 	call	_cpct_getScreenPtr
   5527 EB            [ 4] 1842 	ex	de,hl
   5528 FD E1         [14] 1843 	pop	iy
   552A FD 6E 05      [19] 1844 	ld	l, 5 (iy)
   552D FD 66 06      [19] 1845 	ld	h, 6 (iy)
   5530 23            [ 6] 1846 	inc	hl
   5531 4E            [ 7] 1847 	ld	c, (hl)
   5532 23            [ 6] 1848 	inc	hl
   5533 46            [ 7] 1849 	ld	b, (hl)
   5534 21 00 01      [10] 1850 	ld	hl, #_g_maskTable
   5537 E5            [11] 1851 	push	hl
   5538 21 08 10      [10] 1852 	ld	hl, #0x1008
   553B E5            [11] 1853 	push	hl
   553C D5            [11] 1854 	push	de
   553D C5            [11] 1855 	push	bc
   553E CD C0 4A      [17] 1856 	call	_cpct_drawSpriteMaskedAlignedTable
   5541 C9            [10] 1857 	ret
                           1858 ;src/main.c:711: void DeleteSprite(TSpr *pSpr) __z88dk_fastcall {
                           1859 ;	---------------------------------
                           1860 ; Function DeleteSprite
                           1861 ; ---------------------------------
   5542                    1862 _DeleteSprite::
   5542 DD E5         [15] 1863 	push	ix
   5544 DD 21 00 00   [14] 1864 	ld	ix,#0
   5548 DD 39         [15] 1865 	add	ix,sp
   554A 3B            [ 6] 1866 	dec	sp
                           1867 ;src/main.c:713: 4 + (pSpr->px & 1), 4 + (pSpr->py & 3 ? 1 : 0),	
   554B 4D            [ 4] 1868 	ld	c,l
   554C 44            [ 4] 1869 	ld	b,h
   554D 23            [ 6] 1870 	inc	hl
   554E 23            [ 6] 1871 	inc	hl
   554F 23            [ 6] 1872 	inc	hl
   5550 5E            [ 7] 1873 	ld	e, (hl)
   5551 7B            [ 4] 1874 	ld	a, e
   5552 E6 03         [ 7] 1875 	and	a, #0x03
   5554 28 04         [12] 1876 	jr	Z,00103$
   5556 16 01         [ 7] 1877 	ld	d, #0x01
   5558 18 02         [12] 1878 	jr	00104$
   555A                    1879 00103$:
   555A 16 00         [ 7] 1880 	ld	d, #0x00
   555C                    1881 00104$:
   555C 14            [ 4] 1882 	inc	d
   555D 14            [ 4] 1883 	inc	d
   555E 14            [ 4] 1884 	inc	d
   555F 14            [ 4] 1885 	inc	d
   5560 69            [ 4] 1886 	ld	l, c
   5561 60            [ 4] 1887 	ld	h, b
   5562 23            [ 6] 1888 	inc	hl
   5563 23            [ 6] 1889 	inc	hl
   5564 4E            [ 7] 1890 	ld	c, (hl)
   5565 79            [ 4] 1891 	ld	a, c
   5566 E6 01         [ 7] 1892 	and	a, #0x01
   5568 C6 04         [ 7] 1893 	add	a, #0x04
   556A DD 77 FF      [19] 1894 	ld	-1 (ix), a
                           1895 ;src/main.c:712: cpct_etm_drawTileBox2x4(pSpr->px / 2, (pSpr->py - ORIG_MAP_Y) / 4, 
   556D 06 00         [ 7] 1896 	ld	b, #0x00
   556F 6B            [ 4] 1897 	ld	l, e
   5570 60            [ 4] 1898 	ld	h, b
   5571 CB 78         [ 8] 1899 	bit	7, b
   5573 28 05         [12] 1900 	jr	Z,00105$
   5575 6B            [ 4] 1901 	ld	l, e
   5576 60            [ 4] 1902 	ld	h, b
   5577 23            [ 6] 1903 	inc	hl
   5578 23            [ 6] 1904 	inc	hl
   5579 23            [ 6] 1905 	inc	hl
   557A                    1906 00105$:
   557A CB 2C         [ 8] 1907 	sra	h
   557C CB 1D         [ 8] 1908 	rr	l
   557E CB 2C         [ 8] 1909 	sra	h
   5580 CB 1D         [ 8] 1910 	rr	l
   5582 5D            [ 4] 1911 	ld	e, l
   5583 CB 39         [ 8] 1912 	srl	c
   5585 21 31 10      [10] 1913 	ld	hl, #0x1031
   5588 E5            [11] 1914 	push	hl
   5589 21 00 C0      [10] 1915 	ld	hl, #0xc000
   558C E5            [11] 1916 	push	hl
   558D 3E 28         [ 7] 1917 	ld	a, #0x28
   558F F5            [11] 1918 	push	af
   5590 33            [ 6] 1919 	inc	sp
   5591 D5            [11] 1920 	push	de
   5592 33            [ 6] 1921 	inc	sp
   5593 DD 56 FF      [19] 1922 	ld	d, -1 (ix)
   5596 D5            [11] 1923 	push	de
   5597 79            [ 4] 1924 	ld	a, c
   5598 F5            [11] 1925 	push	af
   5599 33            [ 6] 1926 	inc	sp
   559A CD 81 47      [17] 1927 	call	_cpct_etm_drawTileBox2x4
   559D 33            [ 6] 1928 	inc	sp
   559E DD E1         [14] 1929 	pop	ix
   55A0 C9            [10] 1930 	ret
                           1931 ;src/main.c:719: void PrintExplosion(TSpr *pSpr, u8 frame) {
                           1932 ;	---------------------------------
                           1933 ; Function PrintExplosion
                           1934 ; ---------------------------------
   55A1                    1935 _PrintExplosion::
   55A1 DD E5         [15] 1936 	push	ix
   55A3 DD 21 00 00   [14] 1937 	ld	ix,#0
   55A7 DD 39         [15] 1938 	add	ix,sp
                           1939 ;src/main.c:722: SPR_W, SPR_H, g_maskTable);
                           1940 ;src/main.c:721: cpct_getScreenPtr(CPCT_VMEM_START, pSpr->x, pSpr->y), 
   55A9 DD 4E 04      [19] 1941 	ld	c,4 (ix)
   55AC DD 46 05      [19] 1942 	ld	b,5 (ix)
   55AF 69            [ 4] 1943 	ld	l, c
   55B0 60            [ 4] 1944 	ld	h, b
   55B1 23            [ 6] 1945 	inc	hl
   55B2 56            [ 7] 1946 	ld	d, (hl)
   55B3 0A            [ 7] 1947 	ld	a, (bc)
   55B4 5F            [ 4] 1948 	ld	e,a
   55B5 D5            [11] 1949 	push	de
   55B6 21 00 C0      [10] 1950 	ld	hl, #0xc000
   55B9 E5            [11] 1951 	push	hl
   55BA CD AA 4A      [17] 1952 	call	_cpct_getScreenPtr
   55BD 4D            [ 4] 1953 	ld	c, l
   55BE 44            [ 4] 1954 	ld	b, h
                           1955 ;src/main.c:720: cpct_drawSpriteMaskedAlignedTable(g_explosion[frame], 
   55BF 11 79 38      [10] 1956 	ld	de, #_g_explosion+0
   55C2 DD 6E 06      [19] 1957 	ld	l, 6 (ix)
   55C5 26 00         [ 7] 1958 	ld	h, #0x00
   55C7 29            [11] 1959 	add	hl, hl
   55C8 29            [11] 1960 	add	hl, hl
   55C9 29            [11] 1961 	add	hl, hl
   55CA 29            [11] 1962 	add	hl, hl
   55CB 29            [11] 1963 	add	hl, hl
   55CC 29            [11] 1964 	add	hl, hl
   55CD 29            [11] 1965 	add	hl, hl
   55CE 19            [11] 1966 	add	hl, de
   55CF 11 00 01      [10] 1967 	ld	de, #_g_maskTable
   55D2 D5            [11] 1968 	push	de
   55D3 11 08 10      [10] 1969 	ld	de, #0x1008
   55D6 D5            [11] 1970 	push	de
   55D7 C5            [11] 1971 	push	bc
   55D8 E5            [11] 1972 	push	hl
   55D9 CD C0 4A      [17] 1973 	call	_cpct_drawSpriteMaskedAlignedTable
   55DC DD E1         [14] 1974 	pop	ix
   55DE C9            [10] 1975 	ret
                           1976 ;src/main.c:727: void SelectSpriteFrame(TSpr *pSpr) __z88dk_fastcall {
                           1977 ;	---------------------------------
                           1978 ; Function SelectSpriteFrame
                           1979 ; ---------------------------------
   55DF                    1980 _SelectSpriteFrame::
   55DF DD E5         [15] 1981 	push	ix
   55E1 DD 21 00 00   [14] 1982 	ld	ix,#0
   55E5 DD 39         [15] 1983 	add	ix,sp
   55E7 3B            [ 6] 1984 	dec	sp
                           1985 ;src/main.c:728: if (ctMainLoop % ANIM_PAUSE == 0) {
   55E8 E5            [11] 1986 	push	hl
   55E9 3E 03         [ 7] 1987 	ld	a, #0x03
   55EB F5            [11] 1988 	push	af
   55EC 33            [ 6] 1989 	inc	sp
   55ED 3A B1 4B      [13] 1990 	ld	a, (_ctMainLoop)
   55F0 F5            [11] 1991 	push	af
   55F1 33            [ 6] 1992 	inc	sp
   55F2 CD 14 48      [17] 1993 	call	__moduchar
   55F5 F1            [10] 1994 	pop	af
   55F6 C1            [10] 1995 	pop	bc
   55F7 7D            [ 4] 1996 	ld	a, l
   55F8 B7            [ 4] 1997 	or	a, a
   55F9 20 59         [12] 1998 	jr	NZ,00109$
                           1999 ;src/main.c:729: if (pSpr->ident == PELUSOID)
   55FB 69            [ 4] 2000 	ld	l, c
   55FC 60            [ 4] 2001 	ld	h, b
   55FD 11 12 00      [10] 2002 	ld	de, #0x0012
   5600 19            [11] 2003 	add	hl, de
   5601 7E            [ 7] 2004 	ld	a, (hl)
   5602 DD 77 FF      [19] 2005 	ld	-1 (ix), a
                           2006 ;src/main.c:730: pSpr->frm = anim_pelusoid[pSpr->nFrm / ANIM_PAUSE];
   5605 21 05 00      [10] 2007 	ld	hl, #0x0005
   5608 09            [11] 2008 	add	hl,bc
   5609 EB            [ 4] 2009 	ex	de,hl
   560A C5            [11] 2010 	push	bc
   560B FD E1         [14] 2011 	pop	iy
   560D FD 46 07      [19] 2012 	ld	b, 7 (iy)
   5610 D5            [11] 2013 	push	de
   5611 3E 03         [ 7] 2014 	ld	a, #0x03
   5613 F5            [11] 2015 	push	af
   5614 33            [ 6] 2016 	inc	sp
   5615 C5            [11] 2017 	push	bc
   5616 33            [ 6] 2018 	inc	sp
   5617 CD E1 3D      [17] 2019 	call	__divuchar
   561A F1            [10] 2020 	pop	af
   561B D1            [10] 2021 	pop	de
   561C 26 00         [ 7] 2022 	ld	h, #0x00
   561E 29            [11] 2023 	add	hl, hl
                           2024 ;src/main.c:729: if (pSpr->ident == PELUSOID)
   561F DD 7E FF      [19] 2025 	ld	a, -1 (ix)
   5622 3D            [ 4] 2026 	dec	a
   5623 20 0E         [12] 2027 	jr	NZ,00105$
                           2028 ;src/main.c:730: pSpr->frm = anim_pelusoid[pSpr->nFrm / ANIM_PAUSE];
   5625 01 A9 4C      [10] 2029 	ld	bc, #_anim_pelusoid+0
   5628 09            [11] 2030 	add	hl, bc
   5629 4E            [ 7] 2031 	ld	c, (hl)
   562A 23            [ 6] 2032 	inc	hl
   562B 46            [ 7] 2033 	ld	b, (hl)
   562C 79            [ 4] 2034 	ld	a, c
   562D 12            [ 7] 2035 	ld	(de), a
   562E 13            [ 6] 2036 	inc	de
   562F 78            [ 4] 2037 	ld	a, b
   5630 12            [ 7] 2038 	ld	(de), a
   5631 18 21         [12] 2039 	jr	00109$
   5633                    2040 00105$:
                           2041 ;src/main.c:731: else if (pSpr->ident == ARACNOVIRUS)
   5633 DD 7E FF      [19] 2042 	ld	a, -1 (ix)
   5636 D6 02         [ 7] 2043 	sub	a, #0x02
   5638 20 0E         [12] 2044 	jr	NZ,00102$
                           2045 ;src/main.c:732: pSpr->frm = anim_aracnovirus[pSpr->nFrm / ANIM_PAUSE];
   563A 01 AD 4C      [10] 2046 	ld	bc, #_anim_aracnovirus+0
   563D 09            [11] 2047 	add	hl, bc
   563E 4E            [ 7] 2048 	ld	c, (hl)
   563F 23            [ 6] 2049 	inc	hl
   5640 46            [ 7] 2050 	ld	b, (hl)
   5641 79            [ 4] 2051 	ld	a, c
   5642 12            [ 7] 2052 	ld	(de), a
   5643 13            [ 6] 2053 	inc	de
   5644 78            [ 4] 2054 	ld	a, b
   5645 12            [ 7] 2055 	ld	(de), a
   5646 18 0C         [12] 2056 	jr	00109$
   5648                    2057 00102$:
                           2058 ;src/main.c:734: pSpr->frm = anim_infected[pSpr->nFrm / ANIM_PAUSE];
   5648 01 B1 4C      [10] 2059 	ld	bc, #_anim_infected+0
   564B 09            [11] 2060 	add	hl, bc
   564C 4E            [ 7] 2061 	ld	c, (hl)
   564D 23            [ 6] 2062 	inc	hl
   564E 46            [ 7] 2063 	ld	b, (hl)
   564F 79            [ 4] 2064 	ld	a, c
   5650 12            [ 7] 2065 	ld	(de), a
   5651 13            [ 6] 2066 	inc	de
   5652 78            [ 4] 2067 	ld	a, b
   5653 12            [ 7] 2068 	ld	(de), a
   5654                    2069 00109$:
   5654 33            [ 6] 2070 	inc	sp
   5655 DD E1         [14] 2071 	pop	ix
   5657 C9            [10] 2072 	ret
                           2073 ;src/main.c:740: void EnemyWalkAnim(TSpr *pSpr) __z88dk_fastcall {
                           2074 ;	---------------------------------
                           2075 ; Function EnemyWalkAnim
                           2076 ; ---------------------------------
   5658                    2077 _EnemyWalkAnim::
                           2078 ;src/main.c:741: if(++pSpr->nFrm == 2 * ANIM_PAUSE) pSpr->nFrm = 0;
   5658 01 07 00      [10] 2079 	ld	bc, #0x0007
   565B 09            [11] 2080 	add	hl, bc
   565C 7E            [ 7] 2081 	ld	a, (hl)
   565D 3C            [ 4] 2082 	inc	a
   565E 77            [ 7] 2083 	ld	(hl), a
   565F D6 06         [ 7] 2084 	sub	a,#0x06
   5661 C0            [11] 2085 	ret	NZ
   5662 77            [ 7] 2086 	ld	(hl),a
   5663 C9            [10] 2087 	ret
                           2088 ;src/main.c:746: void CheckEnemyCollision(TSpr *pSpr) { // __z88dk_fastcall
                           2089 ;	---------------------------------
                           2090 ; Function CheckEnemyCollision
                           2091 ; ---------------------------------
   5664                    2092 _CheckEnemyCollision::
   5664 DD E5         [15] 2093 	push	ix
   5666 DD 21 00 00   [14] 2094 	ld	ix,#0
   566A DD 39         [15] 2095 	add	ix,sp
   566C 21 F8 FF      [10] 2096 	ld	hl, #-8
   566F 39            [11] 2097 	add	hl, sp
   5670 F9            [ 6] 2098 	ld	sp, hl
                           2099 ;src/main.c:748: if ((spr[0].x + SPR_W) > (pSpr->x + 2) && (spr[0].x + 2) < (pSpr->x + SPR_W))
   5671 3A C3 4B      [13] 2100 	ld	a, (#_spr + 0)
   5674 DD 77 FE      [19] 2101 	ld	-2 (ix), a
   5677 DD 36 FF 00   [19] 2102 	ld	-1 (ix), #0x00
   567B DD 7E FE      [19] 2103 	ld	a, -2 (ix)
   567E C6 08         [ 7] 2104 	add	a, #0x08
   5680 4F            [ 4] 2105 	ld	c, a
   5681 DD 7E FF      [19] 2106 	ld	a, -1 (ix)
   5684 CE 00         [ 7] 2107 	adc	a, #0x00
   5686 47            [ 4] 2108 	ld	b, a
   5687 DD 7E 04      [19] 2109 	ld	a, 4 (ix)
   568A DD 77 FC      [19] 2110 	ld	-4 (ix), a
   568D DD 7E 05      [19] 2111 	ld	a, 5 (ix)
   5690 DD 77 FD      [19] 2112 	ld	-3 (ix), a
   5693 DD 6E FC      [19] 2113 	ld	l,-4 (ix)
   5696 DD 66 FD      [19] 2114 	ld	h,-3 (ix)
   5699 5E            [ 7] 2115 	ld	e, (hl)
   569A DD 73 FA      [19] 2116 	ld	-6 (ix), e
   569D DD 36 FB 00   [19] 2117 	ld	-5 (ix), #0x00
   56A1 16 00         [ 7] 2118 	ld	d, #0x00
   56A3 13            [ 6] 2119 	inc	de
   56A4 13            [ 6] 2120 	inc	de
                           2121 ;src/main.c:750: if ((spr[0].y + SPR_H) > (pSpr->y + 2) && (spr[0].y + 2) < (pSpr->y + SPR_H))
   56A5 DD 7E FC      [19] 2122 	ld	a, -4 (ix)
   56A8 C6 01         [ 7] 2123 	add	a, #0x01
   56AA DD 77 F8      [19] 2124 	ld	-8 (ix), a
   56AD DD 7E FD      [19] 2125 	ld	a, -3 (ix)
   56B0 CE 00         [ 7] 2126 	adc	a, #0x00
   56B2 DD 77 F9      [19] 2127 	ld	-7 (ix), a
                           2128 ;src/main.c:748: if ((spr[0].x + SPR_W) > (pSpr->x + 2) && (spr[0].x + 2) < (pSpr->x + SPR_W))
   56B5 7B            [ 4] 2129 	ld	a, e
   56B6 91            [ 4] 2130 	sub	a, c
   56B7 7A            [ 4] 2131 	ld	a, d
   56B8 98            [ 4] 2132 	sbc	a, b
   56B9 E2 BE 56      [10] 2133 	jp	PO, 00160$
   56BC EE 80         [ 7] 2134 	xor	a, #0x80
   56BE                    2135 00160$:
   56BE F2 2E 57      [10] 2136 	jp	P, 00115$
   56C1 DD 4E FE      [19] 2137 	ld	c,-2 (ix)
   56C4 DD 46 FF      [19] 2138 	ld	b,-1 (ix)
   56C7 03            [ 6] 2139 	inc	bc
   56C8 03            [ 6] 2140 	inc	bc
   56C9 DD 7E FA      [19] 2141 	ld	a, -6 (ix)
   56CC C6 08         [ 7] 2142 	add	a, #0x08
   56CE 5F            [ 4] 2143 	ld	e, a
   56CF DD 7E FB      [19] 2144 	ld	a, -5 (ix)
   56D2 CE 00         [ 7] 2145 	adc	a, #0x00
   56D4 57            [ 4] 2146 	ld	d, a
   56D5 79            [ 4] 2147 	ld	a, c
   56D6 93            [ 4] 2148 	sub	a, e
   56D7 78            [ 4] 2149 	ld	a, b
   56D8 9A            [ 4] 2150 	sbc	a, d
   56D9 E2 DE 56      [10] 2151 	jp	PO, 00161$
   56DC EE 80         [ 7] 2152 	xor	a, #0x80
   56DE                    2153 00161$:
   56DE F2 2E 57      [10] 2154 	jp	P, 00115$
                           2155 ;src/main.c:750: if ((spr[0].y + SPR_H) > (pSpr->y + 2) && (spr[0].y + 2) < (pSpr->y + SPR_H))
   56E1 21 C4 4B      [10] 2156 	ld	hl, #_spr + 1
   56E4 4E            [ 7] 2157 	ld	c, (hl)
   56E5 06 00         [ 7] 2158 	ld	b, #0x00
   56E7 21 10 00      [10] 2159 	ld	hl, #0x0010
   56EA 09            [11] 2160 	add	hl,bc
   56EB DD 75 FE      [19] 2161 	ld	-2 (ix), l
   56EE DD 74 FF      [19] 2162 	ld	-1 (ix), h
   56F1 E1            [10] 2163 	pop	hl
   56F2 E5            [11] 2164 	push	hl
   56F3 5E            [ 7] 2165 	ld	e, (hl)
   56F4 16 00         [ 7] 2166 	ld	d, #0x00
   56F6 6B            [ 4] 2167 	ld	l, e
   56F7 62            [ 4] 2168 	ld	h, d
   56F8 23            [ 6] 2169 	inc	hl
   56F9 23            [ 6] 2170 	inc	hl
   56FA 7D            [ 4] 2171 	ld	a, l
   56FB DD 96 FE      [19] 2172 	sub	a, -2 (ix)
   56FE 7C            [ 4] 2173 	ld	a, h
   56FF DD 9E FF      [19] 2174 	sbc	a, -1 (ix)
   5702 E2 07 57      [10] 2175 	jp	PO, 00162$
   5705 EE 80         [ 7] 2176 	xor	a, #0x80
   5707                    2177 00162$:
   5707 F2 14 58      [10] 2178 	jp	P, 00118$
   570A 03            [ 6] 2179 	inc	bc
   570B 03            [ 6] 2180 	inc	bc
   570C 21 10 00      [10] 2181 	ld	hl, #0x0010
   570F 19            [11] 2182 	add	hl, de
   5710 79            [ 4] 2183 	ld	a, c
   5711 95            [ 4] 2184 	sub	a, l
   5712 78            [ 4] 2185 	ld	a, b
   5713 9C            [ 4] 2186 	sbc	a, h
   5714 E2 19 57      [10] 2187 	jp	PO, 00163$
   5717 EE 80         [ 7] 2188 	xor	a, #0x80
   5719                    2189 00163$:
   5719 F2 14 58      [10] 2190 	jp	P, 00118$
                           2191 ;src/main.c:753: spr[0].lives--;
   571C 21 CC 4B      [10] 2192 	ld	hl, #_spr + 9
   571F 4E            [ 7] 2193 	ld	c, (hl)
   5720 0D            [ 4] 2194 	dec	c
   5721 71            [ 7] 2195 	ld	(hl), c
                           2196 ;src/main.c:754: ExplodePlayer();
   5722 CD 37 5D      [17] 2197 	call	_ExplodePlayer
                           2198 ;src/main.c:755: ExplodeEnemies();
   5725 CD A7 63      [17] 2199 	call	_ExplodeEnemies
                           2200 ;src/main.c:756: GameOver();
   5728 CD 4E 68      [17] 2201 	call	_GameOver
   572B C3 14 58      [10] 2202 	jp	00118$
   572E                    2203 00115$:
                           2204 ;src/main.c:760: else if (shot.active == TRUE)
   572E 3A 14 4C      [13] 2205 	ld	a, (#(_shot + 0x0005) + 0)
   5731 3D            [ 4] 2206 	dec	a
   5732 C2 14 58      [10] 2207 	jp	NZ,00118$
                           2208 ;src/main.c:762: if ((shot.x + SHOT_W) > (pSpr->x + 1) && shot.x < (pSpr->x + SHOT_W))
   5735 21 0F 4C      [10] 2209 	ld	hl, #_shot + 0
   5738 4E            [ 7] 2210 	ld	c, (hl)
   5739 06 00         [ 7] 2211 	ld	b, #0x00
   573B 21 04 00      [10] 2212 	ld	hl, #0x0004
   573E 09            [11] 2213 	add	hl, bc
   573F DD 5E FA      [19] 2214 	ld	e,-6 (ix)
   5742 DD 56 FB      [19] 2215 	ld	d,-5 (ix)
   5745 13            [ 6] 2216 	inc	de
   5746 7B            [ 4] 2217 	ld	a, e
   5747 95            [ 4] 2218 	sub	a, l
   5748 7A            [ 4] 2219 	ld	a, d
   5749 9C            [ 4] 2220 	sbc	a, h
   574A E2 4F 57      [10] 2221 	jp	PO, 00166$
   574D EE 80         [ 7] 2222 	xor	a, #0x80
   574F                    2223 00166$:
   574F F2 14 58      [10] 2224 	jp	P, 00118$
   5752 DD 7E FA      [19] 2225 	ld	a, -6 (ix)
   5755 C6 04         [ 7] 2226 	add	a, #0x04
   5757 5F            [ 4] 2227 	ld	e, a
   5758 DD 7E FB      [19] 2228 	ld	a, -5 (ix)
   575B CE 00         [ 7] 2229 	adc	a, #0x00
   575D 57            [ 4] 2230 	ld	d, a
   575E 79            [ 4] 2231 	ld	a, c
   575F 93            [ 4] 2232 	sub	a, e
   5760 78            [ 4] 2233 	ld	a, b
   5761 9A            [ 4] 2234 	sbc	a, d
   5762 E2 67 57      [10] 2235 	jp	PO, 00167$
   5765 EE 80         [ 7] 2236 	xor	a, #0x80
   5767                    2237 00167$:
   5767 F2 14 58      [10] 2238 	jp	P, 00118$
                           2239 ;src/main.c:764: if ((shot.y + SHOT_H) > (pSpr->y - 1) && (shot.y - 1) < (pSpr->y + SHOT_H))
   576A 21 11 4C      [10] 2240 	ld	hl, #_shot + 2
   576D 4E            [ 7] 2241 	ld	c, (hl)
   576E 06 00         [ 7] 2242 	ld	b, #0x00
   5770 21 08 00      [10] 2243 	ld	hl, #0x0008
   5773 09            [11] 2244 	add	hl,bc
   5774 DD 75 FA      [19] 2245 	ld	-6 (ix), l
   5777 DD 74 FB      [19] 2246 	ld	-5 (ix), h
   577A E1            [10] 2247 	pop	hl
   577B E5            [11] 2248 	push	hl
   577C 5E            [ 7] 2249 	ld	e, (hl)
   577D 16 00         [ 7] 2250 	ld	d, #0x00
   577F 6B            [ 4] 2251 	ld	l, e
   5780 62            [ 4] 2252 	ld	h, d
   5781 2B            [ 6] 2253 	dec	hl
   5782 7D            [ 4] 2254 	ld	a, l
   5783 DD 96 FA      [19] 2255 	sub	a, -6 (ix)
   5786 7C            [ 4] 2256 	ld	a, h
   5787 DD 9E FB      [19] 2257 	sbc	a, -5 (ix)
   578A E2 8F 57      [10] 2258 	jp	PO, 00168$
   578D EE 80         [ 7] 2259 	xor	a, #0x80
   578F                    2260 00168$:
   578F F2 14 58      [10] 2261 	jp	P, 00118$
   5792 0B            [ 6] 2262 	dec	bc
   5793 21 08 00      [10] 2263 	ld	hl, #0x0008
   5796 19            [11] 2264 	add	hl, de
   5797 79            [ 4] 2265 	ld	a, c
   5798 95            [ 4] 2266 	sub	a, l
   5799 78            [ 4] 2267 	ld	a, b
   579A 9C            [ 4] 2268 	sbc	a, h
   579B E2 A0 57      [10] 2269 	jp	PO, 00169$
   579E EE 80         [ 7] 2270 	xor	a, #0x80
   57A0                    2271 00169$:
   57A0 F2 14 58      [10] 2272 	jp	P, 00118$
                           2273 ;src/main.c:766: cpct_akp_SFXPlay (4, 15, 40, 0, 0, AY_CHANNEL_A); // explosion
   57A3 3E 01         [ 7] 2274 	ld	a, #0x01
   57A5 F5            [11] 2275 	push	af
   57A6 33            [ 6] 2276 	inc	sp
   57A7 21 00 00      [10] 2277 	ld	hl, #0x0000
   57AA E5            [11] 2278 	push	hl
   57AB 2E 28         [ 7] 2279 	ld	l, #0x28
   57AD E5            [11] 2280 	push	hl
   57AE 21 04 0F      [10] 2281 	ld	hl, #0x0f04
   57B1 E5            [11] 2282 	push	hl
   57B2 CD 5F 46      [17] 2283 	call	_cpct_akp_SFXPlay
   57B5 21 07 00      [10] 2284 	ld	hl, #7
   57B8 39            [11] 2285 	add	hl, sp
   57B9 F9            [ 6] 2286 	ld	sp, hl
                           2287 ;src/main.c:769: pSpr->lives--;
   57BA DD 7E FC      [19] 2288 	ld	a, -4 (ix)
   57BD C6 09         [ 7] 2289 	add	a, #0x09
   57BF 6F            [ 4] 2290 	ld	l, a
   57C0 DD 7E FD      [19] 2291 	ld	a, -3 (ix)
   57C3 CE 00         [ 7] 2292 	adc	a, #0x00
   57C5 67            [ 4] 2293 	ld	h, a
   57C6 4E            [ 7] 2294 	ld	c, (hl)
   57C7 0D            [ 4] 2295 	dec	c
   57C8 71            [ 7] 2296 	ld	(hl), c
                           2297 ;src/main.c:770: pSpr->touched = 10;
   57C9 DD 7E FC      [19] 2298 	ld	a, -4 (ix)
   57CC C6 0A         [ 7] 2299 	add	a, #0x0a
   57CE 6F            [ 4] 2300 	ld	l, a
   57CF DD 7E FD      [19] 2301 	ld	a, -3 (ix)
   57D2 CE 00         [ 7] 2302 	adc	a, #0x00
   57D4 67            [ 4] 2303 	ld	h, a
   57D5 36 0A         [10] 2304 	ld	(hl), #0x0a
                           2305 ;src/main.c:771: pSpr->status = S_touched;
   57D7 DD 7E FC      [19] 2306 	ld	a, -4 (ix)
   57DA C6 04         [ 7] 2307 	add	a, #0x04
   57DC 6F            [ 4] 2308 	ld	l, a
   57DD DD 7E FD      [19] 2309 	ld	a, -3 (ix)
   57E0 CE 00         [ 7] 2310 	adc	a, #0x00
   57E2 67            [ 4] 2311 	ld	h, a
   57E3 36 08         [10] 2312 	ld	(hl), #0x08
                           2313 ;src/main.c:772: shot.active = FALSE;
   57E5 21 14 4C      [10] 2314 	ld	hl, #(_shot + 0x0005)
   57E8 36 00         [10] 2315 	ld	(hl), #0x00
                           2316 ;src/main.c:775: score += 25;
   57EA 21 AB 4B      [10] 2317 	ld	hl, #_score
   57ED 7E            [ 7] 2318 	ld	a, (hl)
   57EE C6 19         [ 7] 2319 	add	a, #0x19
   57F0 77            [ 7] 2320 	ld	(hl), a
   57F1 23            [ 6] 2321 	inc	hl
   57F2 7E            [ 7] 2322 	ld	a, (hl)
   57F3 CE 00         [ 7] 2323 	adc	a, #0x00
   57F5 77            [ 7] 2324 	ld	(hl), a
                           2325 ;src/main.c:776: if (highScore < score) highScore = score;
   57F6 21 AB 4B      [10] 2326 	ld	hl, #_score
   57F9 FD 21 AD 4B   [14] 2327 	ld	iy, #_highScore
   57FD FD 7E 00      [19] 2328 	ld	a, 0 (iy)
   5800 96            [ 7] 2329 	sub	a, (hl)
   5801 FD 7E 01      [19] 2330 	ld	a, 1 (iy)
   5804 23            [ 6] 2331 	inc	hl
   5805 9E            [ 7] 2332 	sbc	a, (hl)
   5806 30 06         [12] 2333 	jr	NC,00105$
   5808 2A AB 4B      [16] 2334 	ld	hl, (_score)
   580B 22 AD 4B      [16] 2335 	ld	(_highScore), hl
   580E                    2336 00105$:
                           2337 ;src/main.c:778: DeleteShot(&shot);
   580E 21 0F 4C      [10] 2338 	ld	hl, #_shot
   5811 CD 8B 5D      [17] 2339 	call	_DeleteShot
   5814                    2340 00118$:
   5814 DD F9         [10] 2341 	ld	sp, ix
   5816 DD E1         [14] 2342 	pop	ix
   5818 C9            [10] 2343 	ret
                           2344 ;src/main.c:797: void AssignFrame(TFrm **anim) __z88dk_fastcall {
                           2345 ;	---------------------------------
                           2346 ; Function AssignFrame
                           2347 ; ---------------------------------
   5819                    2348 _AssignFrame::
   5819 4D            [ 4] 2349 	ld	c, l
   581A 44            [ 4] 2350 	ld	b, h
                           2351 ;src/main.c:798: spr[0].frm = anim[spr[0].nFrm / ANIM_PAUSE];
   581B 21 CA 4B      [10] 2352 	ld	hl, #_spr + 7
   581E 56            [ 7] 2353 	ld	d, (hl)
   581F C5            [11] 2354 	push	bc
   5820 3E 03         [ 7] 2355 	ld	a, #0x03
   5822 F5            [11] 2356 	push	af
   5823 33            [ 6] 2357 	inc	sp
   5824 D5            [11] 2358 	push	de
   5825 33            [ 6] 2359 	inc	sp
   5826 CD E1 3D      [17] 2360 	call	__divuchar
   5829 F1            [10] 2361 	pop	af
   582A C1            [10] 2362 	pop	bc
   582B 26 00         [ 7] 2363 	ld	h, #0x00
   582D 29            [11] 2364 	add	hl, hl
   582E 09            [11] 2365 	add	hl, bc
   582F 4E            [ 7] 2366 	ld	c, (hl)
   5830 23            [ 6] 2367 	inc	hl
   5831 46            [ 7] 2368 	ld	b, (hl)
   5832 ED 43 C8 4B   [20] 2369 	ld	((_spr + 0x0005)), bc
   5836 C9            [10] 2370 	ret
                           2371 ;src/main.c:803: void SelectFrame() {
                           2372 ;	---------------------------------
                           2373 ; Function SelectFrame
                           2374 ; ---------------------------------
   5837                    2375 _SelectFrame::
                           2376 ;src/main.c:805: switch(spr[0].status) {
   5837 21 C7 4B      [10] 2377 	ld	hl, #(_spr + 0x0004) + 0
   583A 4E            [ 7] 2378 	ld	c, (hl)
                           2379 ;src/main.c:806: case S_stopped:			{spr[0].frm = &frm_player[0]; break;}
                           2380 ;src/main.c:805: switch(spr[0].status) {
   583B 3E 07         [ 7] 2381 	ld	a, #0x07
   583D 91            [ 4] 2382 	sub	a, c
   583E 38 5F         [12] 2383 	jr	C,00109$
   5840 06 00         [ 7] 2384 	ld	b, #0x00
   5842 21 49 58      [10] 2385 	ld	hl, #00127$
   5845 09            [11] 2386 	add	hl, bc
   5846 09            [11] 2387 	add	hl, bc
   5847 09            [11] 2388 	add	hl, bc
   5848 E9            [ 4] 2389 	jp	(hl)
   5849                    2390 00127$:
   5849 C3 61 58      [10] 2391 	jp	00101$
   584C C3 69 58      [10] 2392 	jp	00102$
   584F C3 79 58      [10] 2393 	jp	00104$
   5852 C3 81 58      [10] 2394 	jp	00105$
   5855 C3 71 58      [10] 2395 	jp	00103$
   5858 C3 89 58      [10] 2396 	jp	00106$
   585B C3 91 58      [10] 2397 	jp	00107$
   585E C3 99 58      [10] 2398 	jp	00108$
                           2399 ;src/main.c:806: case S_stopped:			{spr[0].frm = &frm_player[0]; break;}
   5861                    2400 00101$:
   5861 21 6C 4C      [10] 2401 	ld	hl, #_frm_player
   5864 22 C8 4B      [16] 2402 	ld	((_spr + 0x0005)), hl
   5867 18 36         [12] 2403 	jr	00109$
                           2404 ;src/main.c:807: case S_walking:			{AssignFrame(animWalk); break;}	// 0,1,0,2
   5869                    2405 00102$:
   5869 21 87 4C      [10] 2406 	ld	hl, #_animWalk
   586C CD 19 58      [17] 2407 	call	_AssignFrame
   586F 18 2E         [12] 2408 	jr	00109$
                           2409 ;src/main.c:808: case S_climbing:		{AssignFrame(animClimb); break;} // 6,7,6,8
   5871                    2410 00103$:
   5871 21 8F 4C      [10] 2411 	ld	hl, #_animClimb
   5874 CD 19 58      [17] 2412 	call	_AssignFrame
   5877 18 26         [12] 2413 	jr	00109$
                           2414 ;src/main.c:809: case S_preJump:			{spr[0].frm = &frm_player[1]; break;}
   5879                    2415 00104$:
   5879 21 6F 4C      [10] 2416 	ld	hl, #(_frm_player + 0x0003)
   587C 22 C8 4B      [16] 2417 	ld	((_spr + 0x0005)), hl
   587F 18 1E         [12] 2418 	jr	00109$
                           2419 ;src/main.c:810: case S_jumping:			{spr[0].frm = &frm_player[3]; break;}
   5881                    2420 00105$:
   5881 21 75 4C      [10] 2421 	ld	hl, #(_frm_player + 0x0009)
   5884 22 C8 4B      [16] 2422 	ld	((_spr + 0x0005)), hl
   5887 18 16         [12] 2423 	jr	00109$
                           2424 ;src/main.c:811: case S_falling:			{spr[0].frm = &frm_player[4]; break;}
   5889                    2425 00106$:
   5889 21 78 4C      [10] 2426 	ld	hl, #(_frm_player + 0x000c)
   588C 22 C8 4B      [16] 2427 	ld	((_spr + 0x0005)), hl
   588F 18 0E         [12] 2428 	jr	00109$
                           2429 ;src/main.c:812: case S_landing:			{spr[0].frm = &frm_player[1]; break;}
   5891                    2430 00107$:
   5891 21 6F 4C      [10] 2431 	ld	hl, #(_frm_player + 0x0003)
   5894 22 C8 4B      [16] 2432 	ld	((_spr + 0x0005)), hl
   5897 18 06         [12] 2433 	jr	00109$
                           2434 ;src/main.c:813: case S_firing:			{spr[0].frm = &frm_player[5]; }
   5899                    2435 00108$:
   5899 21 7B 4C      [10] 2436 	ld	hl, #(_frm_player + 0x000f)
   589C 22 C8 4B      [16] 2437 	ld	((_spr + 0x0005)), hl
                           2438 ;src/main.c:814: }
   589F                    2439 00109$:
                           2440 ;src/main.c:816: f = spr[0].frm;
   589F ED 4B C8 4B   [20] 2441 	ld	bc, (#(_spr + 0x0005) + 0)
                           2442 ;src/main.c:818: if (f->dir != spr[0].dir && spr[0].status != S_climbing) {
   58A3 0A            [ 7] 2443 	ld	a, (bc)
   58A4 5F            [ 4] 2444 	ld	e, a
   58A5 3A CB 4B      [13] 2445 	ld	a, (#(_spr + 0x0008) + 0)
   58A8 93            [ 4] 2446 	sub	a, e
   58A9 C8            [11] 2447 	ret	Z
   58AA 3A C7 4B      [13] 2448 	ld	a, (#(_spr + 0x0004) + 0)
   58AD D6 04         [ 7] 2449 	sub	a, #0x04
   58AF C8            [11] 2450 	ret	Z
                           2451 ;src/main.c:819: cpct_hflipSpriteM0(SPR_W, SPR_H, f->spr);         
   58B0 69            [ 4] 2452 	ld	l, c
   58B1 60            [ 4] 2453 	ld	h, b
   58B2 23            [ 6] 2454 	inc	hl
   58B3 5E            [ 7] 2455 	ld	e, (hl)
   58B4 23            [ 6] 2456 	inc	hl
   58B5 56            [ 7] 2457 	ld	d, (hl)
   58B6 C5            [11] 2458 	push	bc
   58B7 D5            [11] 2459 	push	de
   58B8 21 08 10      [10] 2460 	ld	hl, #0x1008
   58BB E5            [11] 2461 	push	hl
   58BC CD F1 48      [17] 2462 	call	_cpct_hflipSpriteM0
   58BF C1            [10] 2463 	pop	bc
                           2464 ;src/main.c:820: f->dir = spr[0].dir; // save position to compare with next call
   58C0 3A CB 4B      [13] 2465 	ld	a, (#(_spr + 0x0008) + 0)
   58C3 02            [ 7] 2466 	ld	(bc), a
   58C4 C9            [10] 2467 	ret
                           2468 ;src/main.c:825: void MoveUp() { 
                           2469 ;	---------------------------------
                           2470 ; Function MoveUp
                           2471 ; ---------------------------------
   58C5                    2472 _MoveUp::
                           2473 ;src/main.c:826: if (spr[0].y > ORIG_MAP_Y) spr[0].y--;
   58C5 01 C4 4B      [10] 2474 	ld	bc, #_spr+1
   58C8 0A            [ 7] 2475 	ld	a, (bc)
   58C9 B7            [ 4] 2476 	or	a, a
   58CA C8            [11] 2477 	ret	Z
   58CB C6 FF         [ 7] 2478 	add	a, #0xff
   58CD 02            [ 7] 2479 	ld	(bc), a
   58CE C9            [10] 2480 	ret
                           2481 ;src/main.c:830: void MoveDown() {
                           2482 ;	---------------------------------
                           2483 ; Function MoveDown
                           2484 ; ---------------------------------
   58CF                    2485 _MoveDown::
                           2486 ;src/main.c:831: if (spr[0].y + SPR_H < GLOBAL_MAX_Y) spr[0].y++;
   58CF 21 C4 4B      [10] 2487 	ld	hl, #(_spr + 0x0001) + 0
   58D2 4E            [ 7] 2488 	ld	c, (hl)
   58D3 59            [ 4] 2489 	ld	e, c
   58D4 16 00         [ 7] 2490 	ld	d, #0x00
   58D6 21 10 00      [10] 2491 	ld	hl, #0x0010
   58D9 19            [11] 2492 	add	hl, de
   58DA 11 C0 80      [10] 2493 	ld	de, #0x80c0
   58DD 29            [11] 2494 	add	hl, hl
   58DE 3F            [ 4] 2495 	ccf
   58DF CB 1C         [ 8] 2496 	rr	h
   58E1 CB 1D         [ 8] 2497 	rr	l
   58E3 ED 52         [15] 2498 	sbc	hl, de
   58E5 D0            [11] 2499 	ret	NC
   58E6 0C            [ 4] 2500 	inc	c
   58E7 21 C4 4B      [10] 2501 	ld	hl, #(_spr + 0x0001)
   58EA 71            [ 7] 2502 	ld	(hl), c
   58EB C9            [10] 2503 	ret
                           2504 ;src/main.c:835: void MoveLeft() {
                           2505 ;	---------------------------------
                           2506 ; Function MoveLeft
                           2507 ; ---------------------------------
   58EC                    2508 _MoveLeft::
                           2509 ;src/main.c:836: if (spr[0].x > 0) {
   58EC 3A C3 4B      [13] 2510 	ld	a, (#_spr + 0)
   58EF B7            [ 4] 2511 	or	a, a
   58F0 CA 4A 50      [10] 2512 	jp	Z,_MoveLeftMap
                           2513 ;src/main.c:837: if (!FacingWall(spr[0].dir)) {
   58F3 21 CB 4B      [10] 2514 	ld	hl, #(_spr + 0x0008) + 0
   58F6 6E            [ 7] 2515 	ld	l, (hl)
   58F7 CD 00 51      [17] 2516 	call	_FacingWall
   58FA 7D            [ 4] 2517 	ld	a, l
   58FB B7            [ 4] 2518 	or	a, a
   58FC C0            [11] 2519 	ret	NZ
                           2520 ;src/main.c:838: spr[0].x--;
   58FD 21 C3 4B      [10] 2521 	ld	hl, #_spr + 0
   5900 4E            [ 7] 2522 	ld	c, (hl)
   5901 0D            [ 4] 2523 	dec	c
   5902 21 C3 4B      [10] 2524 	ld	hl, #_spr
   5905 71            [ 7] 2525 	ld	(hl), c
                           2526 ;src/main.c:839: spr[0].dir = D_left;
   5906 21 CB 4B      [10] 2527 	ld	hl, #(_spr + 0x0008)
   5909 36 02         [10] 2528 	ld	(hl), #0x02
   590B C9            [10] 2529 	ret
                           2530 ;src/main.c:843: MoveLeftMap(); 
   590C C3 4A 50      [10] 2531 	jp  _MoveLeftMap
                           2532 ;src/main.c:847: void MoveRight() { 
                           2533 ;	---------------------------------
                           2534 ; Function MoveRight
                           2535 ; ---------------------------------
   590F                    2536 _MoveRight::
                           2537 ;src/main.c:848: if (spr[0].x + SPR_W < GLOBAL_MAX_X) {
   590F 21 C3 4B      [10] 2538 	ld	hl, #_spr + 0
   5912 4E            [ 7] 2539 	ld	c, (hl)
   5913 06 00         [ 7] 2540 	ld	b, #0x00
   5915 21 08 00      [10] 2541 	ld	hl, #0x0008
   5918 09            [11] 2542 	add	hl, bc
   5919 11 50 80      [10] 2543 	ld	de, #0x8050
   591C 29            [11] 2544 	add	hl, hl
   591D 3F            [ 4] 2545 	ccf
   591E CB 1C         [ 8] 2546 	rr	h
   5920 CB 1D         [ 8] 2547 	rr	l
   5922 ED 52         [15] 2548 	sbc	hl, de
   5924 D2 30 50      [10] 2549 	jp	NC,_MoveRightMap
                           2550 ;src/main.c:849: if (!FacingWall(spr[0].dir)) {
   5927 21 CB 4B      [10] 2551 	ld	hl, #(_spr + 0x0008) + 0
   592A 6E            [ 7] 2552 	ld	l, (hl)
   592B CD 00 51      [17] 2553 	call	_FacingWall
   592E 7D            [ 4] 2554 	ld	a, l
   592F B7            [ 4] 2555 	or	a, a
   5930 C0            [11] 2556 	ret	NZ
                           2557 ;src/main.c:850: spr[0].x++;
   5931 3A C3 4B      [13] 2558 	ld	a, (#_spr + 0)
   5934 3C            [ 4] 2559 	inc	a
   5935 32 C3 4B      [13] 2560 	ld	(#_spr),a
                           2561 ;src/main.c:851: spr[0].dir = D_right;
   5938 21 CB 4B      [10] 2562 	ld	hl, #(_spr + 0x0008)
   593B 36 03         [10] 2563 	ld	(hl), #0x03
   593D C9            [10] 2564 	ret
                           2565 ;src/main.c:855: MoveRightMap();
   593E C3 30 50      [10] 2566 	jp  _MoveRightMap
                           2567 ;src/main.c:860: void WalkIn(u8 dir) __z88dk_fastcall {
                           2568 ;	---------------------------------
                           2569 ; Function WalkIn
                           2570 ; ---------------------------------
   5941                    2571 _WalkIn::
   5941 4D            [ 4] 2572 	ld	c, l
                           2573 ;src/main.c:861: spr[0].nFrm = 0;
   5942 21 CA 4B      [10] 2574 	ld	hl, #(_spr + 0x0007)
   5945 36 00         [10] 2575 	ld	(hl), #0x00
                           2576 ;src/main.c:862: spr[0].status = S_walking;
   5947 21 C7 4B      [10] 2577 	ld	hl, #(_spr + 0x0004)
   594A 36 01         [10] 2578 	ld	(hl), #0x01
                           2579 ;src/main.c:863: spr[0].dir = dir;
   594C 21 CB 4B      [10] 2580 	ld	hl, #(_spr + 0x0008)
   594F 71            [ 7] 2581 	ld	(hl), c
   5950 C9            [10] 2582 	ret
                           2583 ;src/main.c:868: void ClimbIn() {
                           2584 ;	---------------------------------
                           2585 ; Function ClimbIn
                           2586 ; ---------------------------------
   5951                    2587 _ClimbIn::
                           2588 ;src/main.c:869: spr[0].nFrm = 0;
   5951 21 CA 4B      [10] 2589 	ld	hl, #(_spr + 0x0007)
   5954 36 00         [10] 2590 	ld	(hl), #0x00
                           2591 ;src/main.c:870: spr[0].status = S_climbing;
   5956 21 C7 4B      [10] 2592 	ld	hl, #(_spr + 0x0004)
   5959 36 04         [10] 2593 	ld	(hl), #0x04
   595B C9            [10] 2594 	ret
                           2595 ;src/main.c:875: void PreJumpIn() {
                           2596 ;	---------------------------------
                           2597 ; Function PreJumpIn
                           2598 ; ---------------------------------
   595C                    2599 _PreJumpIn::
                           2600 ;src/main.c:876: spr[0].nFrm = 0;
   595C 21 CA 4B      [10] 2601 	ld	hl, #(_spr + 0x0007)
   595F 36 00         [10] 2602 	ld	(hl), #0x00
                           2603 ;src/main.c:877: spr[0].status = S_preJump;
   5961 21 C7 4B      [10] 2604 	ld	hl, #(_spr + 0x0004)
   5964 36 02         [10] 2605 	ld	(hl), #0x02
   5966 C9            [10] 2606 	ret
                           2607 ;src/main.c:882: void FallIn() {
                           2608 ;	---------------------------------
                           2609 ; Function FallIn
                           2610 ; ---------------------------------
   5967                    2611 _FallIn::
                           2612 ;src/main.c:883: spr[0].status = S_falling;
   5967 21 C7 4B      [10] 2613 	ld	hl, #(_spr + 0x0004)
   596A 36 05         [10] 2614 	ld	(hl), #0x05
                           2615 ;src/main.c:884: spr[0].jump  = JUMP_STEPS - 3;
   596C 21 CE 4B      [10] 2616 	ld	hl, #(_spr + 0x000b)
   596F 36 09         [10] 2617 	ld	(hl), #0x09
   5971 C9            [10] 2618 	ret
                           2619 ;src/main.c:889: void LandIn() {
                           2620 ;	---------------------------------
                           2621 ; Function LandIn
                           2622 ; ---------------------------------
   5972                    2623 _LandIn::
                           2624 ;src/main.c:890: spr[0].nFrm = 0;
   5972 21 CA 4B      [10] 2625 	ld	hl, #(_spr + 0x0007)
   5975 36 00         [10] 2626 	ld	(hl), #0x00
                           2627 ;src/main.c:891: spr[0].status = S_landing;
   5977 21 C7 4B      [10] 2628 	ld	hl, #(_spr + 0x0004)
   597A 36 06         [10] 2629 	ld	(hl), #0x06
   597C C9            [10] 2630 	ret
                           2631 ;src/main.c:896: void PreShotIn() 
                           2632 ;	---------------------------------
                           2633 ; Function PreShotIn
                           2634 ; ---------------------------------
   597D                    2635 _PreShotIn::
                           2636 ;src/main.c:898: if (shot.active == FALSE && ammo != 0) { // if enough ammo and no shot active on screen
   597D 01 14 4C      [10] 2637 	ld	bc, #_shot + 5
   5980 0A            [ 7] 2638 	ld	a, (bc)
   5981 B7            [ 4] 2639 	or	a, a
   5982 C0            [11] 2640 	ret	NZ
   5983 FD 21 AF 4B   [14] 2641 	ld	iy, #_ammo
   5987 FD 7E 00      [19] 2642 	ld	a, 0 (iy)
   598A B7            [ 4] 2643 	or	a, a
   598B C8            [11] 2644 	ret	Z
                           2645 ;src/main.c:899: shot.active = TRUE;
   598C 3E 01         [ 7] 2646 	ld	a, #0x01
   598E 02            [ 7] 2647 	ld	(bc), a
                           2648 ;src/main.c:900: shot.dir = spr[0].dir; // the direction of the shot is that of the player
   598F 01 12 4C      [10] 2649 	ld	bc, #_shot + 3
   5992 3A CB 4B      [13] 2650 	ld	a, (#_spr + 8)
   5995 02            [ 7] 2651 	ld	(bc), a
                           2652 ;src/main.c:901: ammo--; // subtract a bullet from the available ammunition		
   5996 FD 35 00      [23] 2653 	dec	0 (iy)
                           2654 ;src/main.c:902: shot.y = spr[0].y + 5; // adjusts to the player's height
   5999 11 11 4C      [10] 2655 	ld	de, #_shot + 2
   599C 3A C4 4B      [13] 2656 	ld	a, (#_spr + 1)
   599F C6 05         [ 7] 2657 	add	a, #0x05
   59A1 12            [ 7] 2658 	ld	(de), a
                           2659 ;src/main.c:905: if (shot.dir == D_right)
   59A2 0A            [ 7] 2660 	ld	a, (bc)
   59A3 5F            [ 4] 2661 	ld	e, a
                           2662 ;src/main.c:906: shot.x = shot.px = spr[0].x + SPR_W;
   59A4 01 10 4C      [10] 2663 	ld	bc, #_shot + 1
   59A7 21 C3 4B      [10] 2664 	ld	hl, #_spr + 0
   59AA 56            [ 7] 2665 	ld	d, (hl)
                           2666 ;src/main.c:905: if (shot.dir == D_right)
   59AB 7B            [ 4] 2667 	ld	a, e
   59AC D6 03         [ 7] 2668 	sub	a, #0x03
   59AE 20 09         [12] 2669 	jr	NZ,00102$
                           2670 ;src/main.c:906: shot.x = shot.px = spr[0].x + SPR_W;
   59B0 7A            [ 4] 2671 	ld	a, d
   59B1 C6 08         [ 7] 2672 	add	a, #0x08
   59B3 02            [ 7] 2673 	ld	(bc), a
   59B4 32 0F 4C      [13] 2674 	ld	(#_shot),a
   59B7 18 07         [12] 2675 	jr	00103$
   59B9                    2676 00102$:
                           2677 ;src/main.c:908: shot.x = shot.px = spr[0].x - SHOT_W;
   59B9 7A            [ 4] 2678 	ld	a, d
   59BA C6 FC         [ 7] 2679 	add	a, #0xfc
   59BC 02            [ 7] 2680 	ld	(bc), a
   59BD 32 0F 4C      [13] 2681 	ld	(#_shot),a
   59C0                    2682 00103$:
                           2683 ;src/main.c:910: shot.status = spr[0].status; // backup player status before shooting
   59C0 01 C7 4B      [10] 2684 	ld	bc, #_spr + 4
   59C3 0A            [ 7] 2685 	ld	a, (bc)
   59C4 32 13 4C      [13] 2686 	ld	(#(_shot + 0x0004)),a
                           2687 ;src/main.c:911: spr[0].status = S_firing;
   59C7 3E 07         [ 7] 2688 	ld	a, #0x07
   59C9 02            [ 7] 2689 	ld	(bc), a
                           2690 ;src/main.c:912: cpct_akp_SFXPlay(2, 15, 40, 0, 0, AY_CHANNEL_A); // laser
   59CA 3E 01         [ 7] 2691 	ld	a, #0x01
   59CC F5            [11] 2692 	push	af
   59CD 33            [ 6] 2693 	inc	sp
   59CE 21 00 00      [10] 2694 	ld	hl, #0x0000
   59D1 E5            [11] 2695 	push	hl
   59D2 2E 28         [ 7] 2696 	ld	l, #0x28
   59D4 E5            [11] 2697 	push	hl
   59D5 21 02 0F      [10] 2698 	ld	hl, #0x0f02
   59D8 E5            [11] 2699 	push	hl
   59D9 CD 5F 46      [17] 2700 	call	_cpct_akp_SFXPlay
   59DC 21 07 00      [10] 2701 	ld	hl, #7
   59DF 39            [11] 2702 	add	hl, sp
   59E0 F9            [ 6] 2703 	ld	sp, hl
   59E1 C9            [10] 2704 	ret
                           2705 ;src/main.c:918: void Falling() {
                           2706 ;	---------------------------------
                           2707 ; Function Falling
                           2708 ; ---------------------------------
   59E2                    2709 _Falling::
                           2710 ;src/main.c:919: cpct_scanKeyboard_f(); // check the pressed keys
   59E2 CD 3D 3E      [17] 2711 	call	_cpct_scanKeyboard_f
                           2712 ;src/main.c:921: if(cpct_isKeyPressed(ctlDown)) CheckObjects();
   59E5 2A B5 4B      [16] 2713 	ld	hl, (_ctlDown)
   59E8 CD 31 3E      [17] 2714 	call	_cpct_isKeyPressed
   59EB 7D            [ 4] 2715 	ld	a, l
   59EC B7            [ 4] 2716 	or	a, a
   59ED 28 05         [12] 2717 	jr	Z,00110$
   59EF CD D2 52      [17] 2718 	call	_CheckObjects
   59F2 18 2B         [12] 2719 	jr	00111$
   59F4                    2720 00110$:
                           2721 ;src/main.c:922: else if (cpct_isKeyPressed(ctlFire)) PreShotIn();
   59F4 2A BB 4B      [16] 2722 	ld	hl, (_ctlFire)
   59F7 CD 31 3E      [17] 2723 	call	_cpct_isKeyPressed
   59FA 7D            [ 4] 2724 	ld	a, l
   59FB B7            [ 4] 2725 	or	a, a
   59FC 28 05         [12] 2726 	jr	Z,00107$
   59FE CD 7D 59      [17] 2727 	call	_PreShotIn
   5A01 18 1C         [12] 2728 	jr	00111$
   5A03                    2729 00107$:
                           2730 ;src/main.c:923: else if (cpct_isKeyPressed(ctlLeft)) MoveLeft();
   5A03 2A B7 4B      [16] 2731 	ld	hl, (_ctlLeft)
   5A06 CD 31 3E      [17] 2732 	call	_cpct_isKeyPressed
   5A09 7D            [ 4] 2733 	ld	a, l
   5A0A B7            [ 4] 2734 	or	a, a
   5A0B 28 05         [12] 2735 	jr	Z,00104$
   5A0D CD EC 58      [17] 2736 	call	_MoveLeft
   5A10 18 0D         [12] 2737 	jr	00111$
   5A12                    2738 00104$:
                           2739 ;src/main.c:924: else if (cpct_isKeyPressed(ctlRight)) MoveRight();
   5A12 2A B9 4B      [16] 2740 	ld	hl, (_ctlRight)
   5A15 CD 31 3E      [17] 2741 	call	_cpct_isKeyPressed
   5A18 7D            [ 4] 2742 	ld	a, l
   5A19 B7            [ 4] 2743 	or	a, a
   5A1A 28 03         [12] 2744 	jr	Z,00111$
   5A1C CD 0F 59      [17] 2745 	call	_MoveRight
   5A1F                    2746 00111$:
                           2747 ;src/main.c:927: spr[0].y += cpct_get2Bits(g_jumpTable, spr[0].jump);	
   5A1F 21 C4 4B      [10] 2748 	ld	hl, #(_spr + 0x0001) + 0
   5A22 4E            [ 7] 2749 	ld	c, (hl)
   5A23 21 CE 4B      [10] 2750 	ld	hl, #(_spr + 0x000b) + 0
   5A26 5E            [ 7] 2751 	ld	e, (hl)
   5A27 16 00         [ 7] 2752 	ld	d, #0x00
   5A29 C5            [11] 2753 	push	bc
   5A2A D5            [11] 2754 	push	de
   5A2B 21 B5 4C      [10] 2755 	ld	hl, #_g_jumpTable
   5A2E E5            [11] 2756 	push	hl
   5A2F CD 63 48      [17] 2757 	call	_cpct_get2Bits
   5A32 C1            [10] 2758 	pop	bc
   5A33 79            [ 4] 2759 	ld	a, c
   5A34 85            [ 4] 2760 	add	a, l
   5A35 32 C4 4B      [13] 2761 	ld	(#(_spr + 0x0001)),a
                           2762 ;src/main.c:928: if (spr[0].jump > 1) spr[0].jump--;
   5A38 21 CE 4B      [10] 2763 	ld	hl, #(_spr + 0x000b) + 0
   5A3B 4E            [ 7] 2764 	ld	c, (hl)
   5A3C 3E 01         [ 7] 2765 	ld	a, #0x01
   5A3E 91            [ 4] 2766 	sub	a, c
   5A3F 30 05         [12] 2767 	jr	NC,00113$
   5A41 0D            [ 4] 2768 	dec	c
   5A42 21 CE 4B      [10] 2769 	ld	hl, #(_spr + 0x000b)
   5A45 71            [ 7] 2770 	ld	(hl), c
   5A46                    2771 00113$:
                           2772 ;src/main.c:930: if (OnPlatform(&spr[0]) || OnStairs()) { // if the player is on a platform ...
   5A46 21 C3 4B      [10] 2773 	ld	hl, #_spr
   5A49 CD 9E 50      [17] 2774 	call	_OnPlatform
   5A4C 7D            [ 4] 2775 	ld	a, l
   5A4D B7            [ 4] 2776 	or	a, a
   5A4E 20 06         [12] 2777 	jr	NZ,00114$
   5A50 CD B8 50      [17] 2778 	call	_OnStairs
   5A53 7D            [ 4] 2779 	ld	a, l
   5A54 B7            [ 4] 2780 	or	a, a
   5A55 C8            [11] 2781 	ret	Z
                           2782 ;src/main.c:931: while ((spr[0].y + 1) % 4 != 0) spr[0].y--; // adjust to the ground			
   5A56                    2783 00114$:
                           2784 ;src/main.c:927: spr[0].y += cpct_get2Bits(g_jumpTable, spr[0].jump);	
   5A56 21 C4 4B      [10] 2785 	ld	hl, #(_spr + 0x0001) + 0
   5A59 4E            [ 7] 2786 	ld	c, (hl)
                           2787 ;src/main.c:931: while ((spr[0].y + 1) % 4 != 0) spr[0].y--; // adjust to the ground			
   5A5A 59            [ 4] 2788 	ld	e, c
   5A5B 16 00         [ 7] 2789 	ld	d, #0x00
   5A5D 13            [ 6] 2790 	inc	de
   5A5E C5            [11] 2791 	push	bc
   5A5F 21 04 00      [10] 2792 	ld	hl, #0x0004
   5A62 E5            [11] 2793 	push	hl
   5A63 D5            [11] 2794 	push	de
   5A64 CD 9D 4A      [17] 2795 	call	__modsint
   5A67 F1            [10] 2796 	pop	af
   5A68 F1            [10] 2797 	pop	af
   5A69 C1            [10] 2798 	pop	bc
   5A6A 7C            [ 4] 2799 	ld	a, h
   5A6B B5            [ 4] 2800 	or	a,l
   5A6C 28 07         [12] 2801 	jr	Z,00116$
   5A6E 0D            [ 4] 2802 	dec	c
   5A6F 21 C4 4B      [10] 2803 	ld	hl, #(_spr + 0x0001)
   5A72 71            [ 7] 2804 	ld	(hl), c
   5A73 18 E1         [12] 2805 	jr	00114$
   5A75                    2806 00116$:
                           2807 ;src/main.c:932: LandIn(); // prepare the landing
   5A75 CD 72 59      [17] 2808 	call	_LandIn
   5A78 C9            [10] 2809 	ret
                           2810 ;src/main.c:938: void StopIn() {
                           2811 ;	---------------------------------
                           2812 ; Function StopIn
                           2813 ; ---------------------------------
   5A79                    2814 _StopIn::
                           2815 ;src/main.c:939: spr[0].status = S_stopped;
   5A79 21 C7 4B      [10] 2816 	ld	hl, #(_spr + 0x0004)
   5A7C 36 00         [10] 2817 	ld	(hl), #0x00
   5A7E C9            [10] 2818 	ret
                           2819 ;src/main.c:944: void Stopped() {
                           2820 ;	---------------------------------
                           2821 ; Function Stopped
                           2822 ; ---------------------------------
   5A7F                    2823 _Stopped::
                           2824 ;src/main.c:945: cpct_scanKeyboard_f(); // check the pressed keys
   5A7F CD 3D 3E      [17] 2825 	call	_cpct_scanKeyboard_f
                           2826 ;src/main.c:946: if(cpct_isKeyPressed(ctlUp)) {
   5A82 2A B3 4B      [16] 2827 	ld	hl, (_ctlUp)
   5A85 CD 31 3E      [17] 2828 	call	_cpct_isKeyPressed
   5A88 7D            [ 4] 2829 	ld	a, l
   5A89 B7            [ 4] 2830 	or	a, a
   5A8A 28 0B         [12] 2831 	jr	Z,00134$
                           2832 ;src/main.c:947: if(OnStairs()) ClimbIn(); // going to climb a ladder
   5A8C CD B8 50      [17] 2833 	call	_OnStairs
   5A8F 7D            [ 4] 2834 	ld	a, l
   5A90 B7            [ 4] 2835 	or	a, a
   5A91 C2 51 59      [10] 2836 	jp	NZ,_ClimbIn
                           2837 ;src/main.c:948: else PreJumpIn(); // going to jump
   5A94 C3 5C 59      [10] 2838 	jp  _PreJumpIn
   5A97                    2839 00134$:
                           2840 ;src/main.c:950: else if(cpct_isKeyPressed(ctlDown)) {
   5A97 2A B5 4B      [16] 2841 	ld	hl, (_ctlDown)
   5A9A CD 31 3E      [17] 2842 	call	_cpct_isKeyPressed
   5A9D 7D            [ 4] 2843 	ld	a, l
   5A9E B7            [ 4] 2844 	or	a, a
   5A9F 28 0B         [12] 2845 	jr	Z,00131$
                           2846 ;src/main.c:951: if(OnStairs()) ClimbIn(); // going down a ladder
   5AA1 CD B8 50      [17] 2847 	call	_OnStairs
   5AA4 7D            [ 4] 2848 	ld	a, l
   5AA5 B7            [ 4] 2849 	or	a, a
   5AA6 C2 51 59      [10] 2850 	jp	NZ,_ClimbIn
                           2851 ;src/main.c:952: else CheckObjects(); // going to grab / drop an object (if it is on an object)
   5AA9 C3 D2 52      [10] 2852 	jp  _CheckObjects
   5AAC                    2853 00131$:
                           2854 ;src/main.c:954: else if(cpct_isKeyPressed(ctlLeft)) WalkIn(D_left);
   5AAC 2A B7 4B      [16] 2855 	ld	hl, (_ctlLeft)
   5AAF CD 31 3E      [17] 2856 	call	_cpct_isKeyPressed
   5AB2 7D            [ 4] 2857 	ld	a, l
   5AB3 B7            [ 4] 2858 	or	a, a
   5AB4 28 05         [12] 2859 	jr	Z,00128$
   5AB6 2E 02         [ 7] 2860 	ld	l, #0x02
   5AB8 C3 41 59      [10] 2861 	jp  _WalkIn
   5ABB                    2862 00128$:
                           2863 ;src/main.c:955: else if(cpct_isKeyPressed(ctlRight)) WalkIn(D_right);
   5ABB 2A B9 4B      [16] 2864 	ld	hl, (_ctlRight)
   5ABE CD 31 3E      [17] 2865 	call	_cpct_isKeyPressed
   5AC1 7D            [ 4] 2866 	ld	a, l
   5AC2 B7            [ 4] 2867 	or	a, a
   5AC3 28 05         [12] 2868 	jr	Z,00125$
   5AC5 2E 03         [ 7] 2869 	ld	l, #0x03
   5AC7 C3 41 59      [10] 2870 	jp  _WalkIn
   5ACA                    2871 00125$:
                           2872 ;src/main.c:956: else if(cpct_isKeyPressed(ctlFire)) PreShotIn();
   5ACA 2A BB 4B      [16] 2873 	ld	hl, (_ctlFire)
   5ACD CD 31 3E      [17] 2874 	call	_cpct_isKeyPressed
   5AD0 7D            [ 4] 2875 	ld	a, l
   5AD1 B7            [ 4] 2876 	or	a, a
   5AD2 C2 7D 59      [10] 2877 	jp	NZ,_PreShotIn
                           2878 ;src/main.c:958: else if(cpct_isKeyPressed(ctlAbort)) {
   5AD5 2A BF 4B      [16] 2879 	ld	hl, (_ctlAbort)
   5AD8 CD 31 3E      [17] 2880 	call	_cpct_isKeyPressed
   5ADB 7D            [ 4] 2881 	ld	a, l
   5ADC B7            [ 4] 2882 	or	a, a
   5ADD 28 0E         [12] 2883 	jr	Z,00119$
                           2884 ;src/main.c:959: spr[0].lives = 0; 
   5ADF 21 CC 4B      [10] 2885 	ld	hl, #(_spr + 0x0009)
   5AE2 36 00         [10] 2886 	ld	(hl), #0x00
                           2887 ;src/main.c:960: ExplodePlayer();
   5AE4 CD 37 5D      [17] 2888 	call	_ExplodePlayer
                           2889 ;src/main.c:961: ExplodeEnemies();
   5AE7 CD A7 63      [17] 2890 	call	_ExplodeEnemies
                           2891 ;src/main.c:962: GameOver();
   5AEA C3 4E 68      [10] 2892 	jp  _GameOver
   5AED                    2893 00119$:
                           2894 ;src/main.c:965: else if(cpct_isKeyPressed(ctlMusic)) {
   5AED 2A BD 4B      [16] 2895 	ld	hl, (_ctlMusic)
   5AF0 CD 31 3E      [17] 2896 	call	_cpct_isKeyPressed
   5AF3 7D            [ 4] 2897 	ld	a, l
   5AF4 B7            [ 4] 2898 	or	a, a
   5AF5 28 2B         [12] 2899 	jr	Z,00116$
                           2900 ;src/main.c:966: Wait4Key(ctlMusic);
   5AF7 2A BD 4B      [16] 2901 	ld	hl, (_ctlMusic)
   5AFA CD 9C 51      [17] 2902 	call	_Wait4Key
                           2903 ;src/main.c:967: if (music == TRUE) { // if the music is playing ...
   5AFD FD 21 B0 4B   [14] 2904 	ld	iy, #_music
   5B01 FD 7E 00      [19] 2905 	ld	a, 0 (iy)
   5B04 3D            [ 4] 2906 	dec	a
   5B05 20 0D         [12] 2907 	jr	NZ,00108$
                           2908 ;src/main.c:968: music = FALSE;
   5B07 FD 36 00 00   [19] 2909 	ld	0 (iy), #0x00
                           2910 ;src/main.c:969: cpct_akp_musicInit(FX);
   5B0B 21 00 02      [10] 2911 	ld	hl, #_FX
   5B0E E5            [11] 2912 	push	hl
   5B0F CD B8 45      [17] 2913 	call	_cpct_akp_musicInit
   5B12 F1            [10] 2914 	pop	af
   5B13 C9            [10] 2915 	ret
   5B14                    2916 00108$:
                           2917 ;src/main.c:972: music = TRUE;			
   5B14 21 B0 4B      [10] 2918 	ld	hl,#_music + 0
   5B17 36 01         [10] 2919 	ld	(hl), #0x01
                           2920 ;src/main.c:973: cpct_akp_musicInit(Ingame1);
   5B19 21 75 0B      [10] 2921 	ld	hl, #_Ingame1
   5B1C E5            [11] 2922 	push	hl
   5B1D CD B8 45      [17] 2923 	call	_cpct_akp_musicInit
   5B20 F1            [10] 2924 	pop	af
   5B21 C9            [10] 2925 	ret
   5B22                    2926 00116$:
                           2927 ;src/main.c:977: else if(cpct_isKeyPressed(ctlPause)) {
   5B22 2A C1 4B      [16] 2928 	ld	hl, (_ctlPause)
   5B25 CD 31 3E      [17] 2929 	call	_cpct_isKeyPressed
   5B28 7D            [ 4] 2930 	ld	a, l
   5B29 B7            [ 4] 2931 	or	a, a
   5B2A C8            [11] 2932 	ret	Z
                           2933 ;src/main.c:978: Wait4Key(ctlPause);
   5B2B 2A C1 4B      [16] 2934 	ld	hl, (_ctlPause)
   5B2E CD 9C 51      [17] 2935 	call	_Wait4Key
                           2936 ;src/main.c:979: cpct_akp_musicInit(FX);
   5B31 21 00 02      [10] 2937 	ld	hl, #_FX
   5B34 E5            [11] 2938 	push	hl
   5B35 CD B8 45      [17] 2939 	call	_cpct_akp_musicInit
   5B38 F1            [10] 2940 	pop	af
                           2941 ;src/main.c:980: while (!cpct_isAnyKeyPressed());
   5B39                    2942 00110$:
   5B39 CD 56 48      [17] 2943 	call	_cpct_isAnyKeyPressed
   5B3C 7D            [ 4] 2944 	ld	a, l
   5B3D B7            [ 4] 2945 	or	a, a
   5B3E 28 F9         [12] 2946 	jr	Z,00110$
                           2947 ;src/main.c:981: Wait4Key(ctlPause);
   5B40 2A C1 4B      [16] 2948 	ld	hl, (_ctlPause)
   5B43 CD 9C 51      [17] 2949 	call	_Wait4Key
                           2950 ;src/main.c:982: cpct_akp_musicInit(Ingame1);
   5B46 21 75 0B      [10] 2951 	ld	hl, #_Ingame1
   5B49 E5            [11] 2952 	push	hl
   5B4A CD B8 45      [17] 2953 	call	_cpct_akp_musicInit
   5B4D F1            [10] 2954 	pop	af
   5B4E C9            [10] 2955 	ret
                           2956 ;src/main.c:988: void JumpIn() {
                           2957 ;	---------------------------------
                           2958 ; Function JumpIn
                           2959 ; ---------------------------------
   5B4F                    2960 _JumpIn::
                           2961 ;src/main.c:989: spr[0].status = S_jumping;
   5B4F 21 C7 4B      [10] 2962 	ld	hl, #(_spr + 0x0004)
   5B52 36 03         [10] 2963 	ld	(hl), #0x03
                           2964 ;src/main.c:990: spr[0].jump  = 0;
   5B54 21 CE 4B      [10] 2965 	ld	hl, #(_spr + 0x000b)
   5B57 36 00         [10] 2966 	ld	(hl), #0x00
                           2967 ;src/main.c:991: cpct_akp_SFXPlay(3, 15, 32, 0, 0, AY_CHANNEL_C);
   5B59 3E 04         [ 7] 2968 	ld	a, #0x04
   5B5B F5            [11] 2969 	push	af
   5B5C 33            [ 6] 2970 	inc	sp
   5B5D 21 00 00      [10] 2971 	ld	hl, #0x0000
   5B60 E5            [11] 2972 	push	hl
   5B61 2E 20         [ 7] 2973 	ld	l, #0x20
   5B63 E5            [11] 2974 	push	hl
   5B64 21 03 0F      [10] 2975 	ld	hl, #0x0f03
   5B67 E5            [11] 2976 	push	hl
   5B68 CD 5F 46      [17] 2977 	call	_cpct_akp_SFXPlay
   5B6B 21 07 00      [10] 2978 	ld	hl, #7
   5B6E 39            [11] 2979 	add	hl, sp
   5B6F F9            [ 6] 2980 	ld	sp, hl
   5B70 C9            [10] 2981 	ret
                           2982 ;src/main.c:995: void Jumping() {
                           2983 ;	---------------------------------
                           2984 ; Function Jumping
                           2985 ; ---------------------------------
   5B71                    2986 _Jumping::
                           2987 ;src/main.c:996: cpct_scanKeyboard_f(); // check the pressed keys
   5B71 CD 3D 3E      [17] 2988 	call	_cpct_scanKeyboard_f
                           2989 ;src/main.c:997: if(!cpct_isKeyPressed(ctlUp)) FallIn();
   5B74 2A B3 4B      [16] 2990 	ld	hl, (_ctlUp)
   5B77 CD 31 3E      [17] 2991 	call	_cpct_isKeyPressed
   5B7A 7D            [ 4] 2992 	ld	a, l
   5B7B B7            [ 4] 2993 	or	a, a
   5B7C 20 05         [12] 2994 	jr	NZ,00112$
   5B7E CD 67 59      [17] 2995 	call	_FallIn
   5B81 18 38         [12] 2996 	jr	00113$
   5B83                    2997 00112$:
                           2998 ;src/main.c:999: if (cpct_isKeyPressed(ctlFire)) PreShotIn();
   5B83 2A BB 4B      [16] 2999 	ld	hl, (_ctlFire)
   5B86 CD 31 3E      [17] 3000 	call	_cpct_isKeyPressed
   5B89 7D            [ 4] 3001 	ld	a, l
   5B8A B7            [ 4] 3002 	or	a, a
   5B8B 28 03         [12] 3003 	jr	Z,00102$
   5B8D CD 7D 59      [17] 3004 	call	_PreShotIn
   5B90                    3005 00102$:
                           3006 ;src/main.c:1000: if(cpct_isKeyPressed(ctlDown)) CheckObjects();
   5B90 2A B5 4B      [16] 3007 	ld	hl, (_ctlDown)
   5B93 CD 31 3E      [17] 3008 	call	_cpct_isKeyPressed
   5B96 7D            [ 4] 3009 	ld	a, l
   5B97 B7            [ 4] 3010 	or	a, a
   5B98 28 05         [12] 3011 	jr	Z,00109$
   5B9A CD D2 52      [17] 3012 	call	_CheckObjects
   5B9D 18 1C         [12] 3013 	jr	00113$
   5B9F                    3014 00109$:
                           3015 ;src/main.c:1001: else if (cpct_isKeyPressed(ctlLeft)) MoveLeft();
   5B9F 2A B7 4B      [16] 3016 	ld	hl, (_ctlLeft)
   5BA2 CD 31 3E      [17] 3017 	call	_cpct_isKeyPressed
   5BA5 7D            [ 4] 3018 	ld	a, l
   5BA6 B7            [ 4] 3019 	or	a, a
   5BA7 28 05         [12] 3020 	jr	Z,00106$
   5BA9 CD EC 58      [17] 3021 	call	_MoveLeft
   5BAC 18 0D         [12] 3022 	jr	00113$
   5BAE                    3023 00106$:
                           3024 ;src/main.c:1002: else if (cpct_isKeyPressed(ctlRight)) MoveRight();
   5BAE 2A B9 4B      [16] 3025 	ld	hl, (_ctlRight)
   5BB1 CD 31 3E      [17] 3026 	call	_cpct_isKeyPressed
   5BB4 7D            [ 4] 3027 	ld	a, l
   5BB5 B7            [ 4] 3028 	or	a, a
   5BB6 28 03         [12] 3029 	jr	Z,00113$
   5BB8 CD 0F 59      [17] 3030 	call	_MoveRight
   5BBB                    3031 00113$:
                           3032 ;src/main.c:1005: spr[0].y -= cpct_get2Bits(g_jumpTable, spr[0].jump);
   5BBB 21 C4 4B      [10] 3033 	ld	hl, #(_spr + 0x0001) + 0
   5BBE 4E            [ 7] 3034 	ld	c, (hl)
   5BBF 21 CE 4B      [10] 3035 	ld	hl, #(_spr + 0x000b) + 0
   5BC2 5E            [ 7] 3036 	ld	e, (hl)
   5BC3 16 00         [ 7] 3037 	ld	d, #0x00
   5BC5 C5            [11] 3038 	push	bc
   5BC6 D5            [11] 3039 	push	de
   5BC7 21 B5 4C      [10] 3040 	ld	hl, #_g_jumpTable
   5BCA E5            [11] 3041 	push	hl
   5BCB CD 63 48      [17] 3042 	call	_cpct_get2Bits
   5BCE C1            [10] 3043 	pop	bc
   5BCF 79            [ 4] 3044 	ld	a, c
   5BD0 95            [ 4] 3045 	sub	a, l
   5BD1 32 C4 4B      [13] 3046 	ld	(#(_spr + 0x0001)),a
                           3047 ;src/main.c:1009: if (++spr[0].jump == JUMP_STEPS)	FallIn();
   5BD4 3A CE 4B      [13] 3048 	ld	a, (#(_spr + 0x000b) + 0)
   5BD7 3C            [ 4] 3049 	inc	a
   5BD8 32 CE 4B      [13] 3050 	ld	(#(_spr + 0x000b)),a
   5BDB D6 0C         [ 7] 3051 	sub	a, #0x0c
   5BDD C0            [11] 3052 	ret	NZ
   5BDE CD 67 59      [17] 3053 	call	_FallIn
   5BE1 C9            [10] 3054 	ret
                           3055 ;src/main.c:1013: void PreJump() {
                           3056 ;	---------------------------------
                           3057 ; Function PreJump
                           3058 ; ---------------------------------
   5BE2                    3059 _PreJump::
                           3060 ;src/main.c:1014: cpct_scanKeyboard_f(); // check the pressed keys
   5BE2 CD 3D 3E      [17] 3061 	call	_cpct_scanKeyboard_f
                           3062 ;src/main.c:1015: if(cpct_isKeyPressed(ctlUp)) JumpIn();
   5BE5 2A B3 4B      [16] 3063 	ld	hl, (_ctlUp)
   5BE8 CD 31 3E      [17] 3064 	call	_cpct_isKeyPressed
   5BEB 7D            [ 4] 3065 	ld	a, l
   5BEC B7            [ 4] 3066 	or	a, a
   5BED C2 4F 5B      [10] 3067 	jp	NZ,_JumpIn
                           3068 ;src/main.c:1016: else StopIn();	
   5BF0 C3 79 5A      [10] 3069 	jp  _StopIn
                           3070 ;src/main.c:1027: void WalkAnim(u8 dir) __z88dk_fastcall {
                           3071 ;	---------------------------------
                           3072 ; Function WalkAnim
                           3073 ; ---------------------------------
   5BF3                    3074 _WalkAnim::
   5BF3 4D            [ 4] 3075 	ld	c, l
                           3076 ;src/main.c:1028: spr[0].dir  = dir;
   5BF4 21 CB 4B      [10] 3077 	ld	hl, #(_spr + 0x0008)
   5BF7 71            [ 7] 3078 	ld	(hl), c
                           3079 ;src/main.c:1029: if(++spr[0].nFrm == 4 * ANIM_PAUSE) spr[0].nFrm = 0;
   5BF8 01 CA 4B      [10] 3080 	ld	bc, #_spr + 7
   5BFB 0A            [ 7] 3081 	ld	a, (bc)
   5BFC 3C            [ 4] 3082 	inc	a
   5BFD 02            [ 7] 3083 	ld	(bc), a
   5BFE D6 0C         [ 7] 3084 	sub	a, #0x0c
   5C00 C0            [11] 3085 	ret	NZ
   5C01 AF            [ 4] 3086 	xor	a, a
   5C02 02            [ 7] 3087 	ld	(bc), a
   5C03 C9            [10] 3088 	ret
                           3089 ;src/main.c:1033: void Walking() {
                           3090 ;	---------------------------------
                           3091 ; Function Walking
                           3092 ; ---------------------------------
   5C04                    3093 _Walking::
                           3094 ;src/main.c:1034: cpct_scanKeyboard_f(); // check the pressed keys
   5C04 CD 3D 3E      [17] 3095 	call	_cpct_scanKeyboard_f
                           3096 ;src/main.c:1035: if (cpct_isKeyPressed(ctlUp)) {
   5C07 2A B3 4B      [16] 3097 	ld	hl, (_ctlUp)
   5C0A CD 31 3E      [17] 3098 	call	_cpct_isKeyPressed
   5C0D 7D            [ 4] 3099 	ld	a, l
   5C0E B7            [ 4] 3100 	or	a, a
   5C0F 28 11         [12] 3101 	jr	Z,00120$
                           3102 ;src/main.c:1036: if (OnStairs()) ClimbIn(); // going to climb a ladder
   5C11 CD B8 50      [17] 3103 	call	_OnStairs
   5C14 7D            [ 4] 3104 	ld	a, l
   5C15 B7            [ 4] 3105 	or	a, a
   5C16 28 05         [12] 3106 	jr	Z,00102$
   5C18 CD 51 59      [17] 3107 	call	_ClimbIn
   5C1B 18 5A         [12] 3108 	jr	00121$
   5C1D                    3109 00102$:
                           3110 ;src/main.c:1037: else PreJumpIn(); // going to jump
   5C1D CD 5C 59      [17] 3111 	call	_PreJumpIn
   5C20 18 55         [12] 3112 	jr	00121$
   5C22                    3113 00120$:
                           3114 ;src/main.c:1039: else if (cpct_isKeyPressed(ctlDown)) {
   5C22 2A B5 4B      [16] 3115 	ld	hl, (_ctlDown)
   5C25 CD 31 3E      [17] 3116 	call	_cpct_isKeyPressed
   5C28 7D            [ 4] 3117 	ld	a, l
   5C29 B7            [ 4] 3118 	or	a, a
   5C2A 28 11         [12] 3119 	jr	Z,00117$
                           3120 ;src/main.c:1040: if (OnStairs()) ClimbIn(); // going down a ladder
   5C2C CD B8 50      [17] 3121 	call	_OnStairs
   5C2F 7D            [ 4] 3122 	ld	a, l
   5C30 B7            [ 4] 3123 	or	a, a
   5C31 28 05         [12] 3124 	jr	Z,00105$
   5C33 CD 51 59      [17] 3125 	call	_ClimbIn
   5C36 18 3F         [12] 3126 	jr	00121$
   5C38                    3127 00105$:
                           3128 ;src/main.c:1041: else CheckObjects(); // going to grab / drop an object (if it is on an object)
   5C38 CD D2 52      [17] 3129 	call	_CheckObjects
   5C3B 18 3A         [12] 3130 	jr	00121$
   5C3D                    3131 00117$:
                           3132 ;src/main.c:1043: else if (cpct_isKeyPressed(ctlFire)) PreShotIn();
   5C3D 2A BB 4B      [16] 3133 	ld	hl, (_ctlFire)
   5C40 CD 31 3E      [17] 3134 	call	_cpct_isKeyPressed
   5C43 7D            [ 4] 3135 	ld	a, l
   5C44 B7            [ 4] 3136 	or	a, a
   5C45 28 05         [12] 3137 	jr	Z,00114$
   5C47 CD 7D 59      [17] 3138 	call	_PreShotIn
   5C4A 18 2B         [12] 3139 	jr	00121$
   5C4C                    3140 00114$:
                           3141 ;src/main.c:1044: else if (cpct_isKeyPressed(ctlLeft)) {MoveLeft(); WalkAnim(D_left);}
   5C4C 2A B7 4B      [16] 3142 	ld	hl, (_ctlLeft)
   5C4F CD 31 3E      [17] 3143 	call	_cpct_isKeyPressed
   5C52 7D            [ 4] 3144 	ld	a, l
   5C53 B7            [ 4] 3145 	or	a, a
   5C54 28 0A         [12] 3146 	jr	Z,00111$
   5C56 CD EC 58      [17] 3147 	call	_MoveLeft
   5C59 2E 02         [ 7] 3148 	ld	l, #0x02
   5C5B CD F3 5B      [17] 3149 	call	_WalkAnim
   5C5E 18 17         [12] 3150 	jr	00121$
   5C60                    3151 00111$:
                           3152 ;src/main.c:1045: else if (cpct_isKeyPressed(ctlRight)) {MoveRight(); WalkAnim(D_right);}
   5C60 2A B9 4B      [16] 3153 	ld	hl, (_ctlRight)
   5C63 CD 31 3E      [17] 3154 	call	_cpct_isKeyPressed
   5C66 7D            [ 4] 3155 	ld	a, l
   5C67 B7            [ 4] 3156 	or	a, a
   5C68 28 0A         [12] 3157 	jr	Z,00108$
   5C6A CD 0F 59      [17] 3158 	call	_MoveRight
   5C6D 2E 03         [ 7] 3159 	ld	l, #0x03
   5C6F CD F3 5B      [17] 3160 	call	_WalkAnim
   5C72 18 03         [12] 3161 	jr	00121$
   5C74                    3162 00108$:
                           3163 ;src/main.c:1046: else StopIn();
   5C74 CD 79 5A      [17] 3164 	call	_StopIn
   5C77                    3165 00121$:
                           3166 ;src/main.c:1048: if (!OnPlatform(&spr[0])) // if it is not on a platform, it is also falling
   5C77 21 C3 4B      [10] 3167 	ld	hl, #_spr
   5C7A CD 9E 50      [17] 3168 	call	_OnPlatform
   5C7D 7D            [ 4] 3169 	ld	a, l
   5C7E B7            [ 4] 3170 	or	a, a
   5C7F C0            [11] 3171 	ret	NZ
                           3172 ;src/main.c:1049: FallIn();
   5C80 C3 67 59      [10] 3173 	jp  _FallIn
                           3174 ;src/main.c:1053: void Climbing() {
                           3175 ;	---------------------------------
                           3176 ; Function Climbing
                           3177 ; ---------------------------------
   5C83                    3178 _Climbing::
                           3179 ;src/main.c:1054: cpct_scanKeyboard_f(); // check the pressed keys
   5C83 CD 3D 3E      [17] 3180 	call	_cpct_scanKeyboard_f
                           3181 ;src/main.c:1055: if(cpct_isKeyPressed(ctlUp)) {
   5C86 2A B3 4B      [16] 3182 	ld	hl, (_ctlUp)
   5C89 CD 31 3E      [17] 3183 	call	_cpct_isKeyPressed
   5C8C 7D            [ 4] 3184 	ld	a, l
   5C8D B7            [ 4] 3185 	or	a, a
   5C8E 28 0E         [12] 3186 	jr	Z,00120$
                           3187 ;src/main.c:1056: if(OnStairs()) {MoveUp(); WalkAnim(D_right);} 
   5C90 CD B8 50      [17] 3188 	call	_OnStairs
   5C93 7D            [ 4] 3189 	ld	a, l
   5C94 B7            [ 4] 3190 	or	a, a
   5C95 C8            [11] 3191 	ret	Z
   5C96 CD C5 58      [17] 3192 	call	_MoveUp
   5C99 2E 03         [ 7] 3193 	ld	l, #0x03
   5C9B C3 F3 5B      [10] 3194 	jp  _WalkAnim
   5C9E                    3195 00120$:
                           3196 ;src/main.c:1058: else if(cpct_isKeyPressed(ctlDown))	{
   5C9E 2A B5 4B      [16] 3197 	ld	hl, (_ctlDown)
   5CA1 CD 31 3E      [17] 3198 	call	_cpct_isKeyPressed
   5CA4 7D            [ 4] 3199 	ld	a, l
   5CA5 B7            [ 4] 3200 	or	a, a
   5CA6 28 0E         [12] 3201 	jr	Z,00117$
                           3202 ;src/main.c:1059: if(OnStairs()) {MoveDown(); WalkAnim(D_right);}
   5CA8 CD B8 50      [17] 3203 	call	_OnStairs
   5CAB 7D            [ 4] 3204 	ld	a, l
   5CAC B7            [ 4] 3205 	or	a, a
   5CAD C8            [11] 3206 	ret	Z
   5CAE CD CF 58      [17] 3207 	call	_MoveDown
   5CB1 2E 03         [ 7] 3208 	ld	l, #0x03
   5CB3 C3 F3 5B      [10] 3209 	jp  _WalkAnim
   5CB6                    3210 00117$:
                           3211 ;src/main.c:1061: else if(cpct_isKeyPressed(ctlLeft)) {
   5CB6 2A B7 4B      [16] 3212 	ld	hl, (_ctlLeft)
   5CB9 CD 31 3E      [17] 3213 	call	_cpct_isKeyPressed
   5CBC 7D            [ 4] 3214 	ld	a, l
   5CBD B7            [ 4] 3215 	or	a, a
   5CBE 28 15         [12] 3216 	jr	Z,00114$
                           3217 ;src/main.c:1062: if(OnStairs()) {MoveLeft(); WalkAnim(D_left);} 
   5CC0 CD B8 50      [17] 3218 	call	_OnStairs
   5CC3 7D            [ 4] 3219 	ld	a, l
   5CC4 B7            [ 4] 3220 	or	a, a
   5CC5 28 08         [12] 3221 	jr	Z,00106$
   5CC7 CD EC 58      [17] 3222 	call	_MoveLeft
   5CCA 2E 02         [ 7] 3223 	ld	l, #0x02
   5CCC C3 F3 5B      [10] 3224 	jp  _WalkAnim
   5CCF                    3225 00106$:
                           3226 ;src/main.c:1063: else spr[0].status = S_walking;
   5CCF 21 C7 4B      [10] 3227 	ld	hl, #(_spr + 0x0004)
   5CD2 36 01         [10] 3228 	ld	(hl), #0x01
   5CD4 C9            [10] 3229 	ret
   5CD5                    3230 00114$:
                           3231 ;src/main.c:1065: else if(cpct_isKeyPressed(ctlRight)) {
   5CD5 2A B9 4B      [16] 3232 	ld	hl, (_ctlRight)
   5CD8 CD 31 3E      [17] 3233 	call	_cpct_isKeyPressed
   5CDB 7D            [ 4] 3234 	ld	a, l
   5CDC B7            [ 4] 3235 	or	a, a
   5CDD C8            [11] 3236 	ret	Z
                           3237 ;src/main.c:1066: if(OnStairs()) {MoveRight(); WalkAnim(D_right);} 
   5CDE CD B8 50      [17] 3238 	call	_OnStairs
   5CE1 7D            [ 4] 3239 	ld	a, l
   5CE2 B7            [ 4] 3240 	or	a, a
   5CE3 28 08         [12] 3241 	jr	Z,00109$
   5CE5 CD 0F 59      [17] 3242 	call	_MoveRight
   5CE8 2E 03         [ 7] 3243 	ld	l, #0x03
   5CEA C3 F3 5B      [10] 3244 	jp  _WalkAnim
   5CED                    3245 00109$:
                           3246 ;src/main.c:1067: else spr[0].status = S_walking;
   5CED 21 C7 4B      [10] 3247 	ld	hl, #(_spr + 0x0004)
   5CF0 36 01         [10] 3248 	ld	(hl), #0x01
   5CF2 C9            [10] 3249 	ret
                           3250 ;src/main.c:1073: void RunStatus() {
                           3251 ;	---------------------------------
                           3252 ; Function RunStatus
                           3253 ; ---------------------------------
   5CF3                    3254 _RunStatus::
                           3255 ;src/main.c:1074: switch(spr[0].status) {
   5CF3 01 C7 4B      [10] 3256 	ld	bc, #_spr+4
   5CF6 0A            [ 7] 3257 	ld	a, (bc)
   5CF7 5F            [ 4] 3258 	ld	e, a
   5CF8 3E 07         [ 7] 3259 	ld	a, #0x07
   5CFA 93            [ 4] 3260 	sub	a, e
   5CFB D8            [11] 3261 	ret	C
   5CFC 16 00         [ 7] 3262 	ld	d, #0x00
   5CFE 21 05 5D      [10] 3263 	ld	hl, #00117$
   5D01 19            [11] 3264 	add	hl, de
   5D02 19            [11] 3265 	add	hl, de
   5D03 19            [11] 3266 	add	hl, de
   5D04 E9            [ 4] 3267 	jp	(hl)
   5D05                    3268 00117$:
   5D05 C3 7F 5A      [10] 3269 	jp	_Stopped
   5D08 C3 04 5C      [10] 3270 	jp	_Walking
   5D0B C3 E2 5B      [10] 3271 	jp	_PreJump
   5D0E C3 71 5B      [10] 3272 	jp	_Jumping
   5D11 C3 83 5C      [10] 3273 	jp	_Climbing
   5D14 C3 E2 59      [10] 3274 	jp	_Falling
   5D17 C3 79 5A      [10] 3275 	jp	_StopIn
   5D1A C3 32 5D      [10] 3276 	jp	00108$
                           3277 ;src/main.c:1075: case S_stopped:       	Stopped();			break;
   5D1D C3 7F 5A      [10] 3278 	jp  _Stopped
                           3279 ;src/main.c:1076: case S_walking:      	Walking();			break;
   5D20 C3 04 5C      [10] 3280 	jp  _Walking
                           3281 ;src/main.c:1077: case S_climbing:    	Climbing();			break;
   5D23 C3 83 5C      [10] 3282 	jp  _Climbing
                           3283 ;src/main.c:1078: case S_preJump:   		PreJump();			break;
   5D26 C3 E2 5B      [10] 3284 	jp  _PreJump
                           3285 ;src/main.c:1079: case S_jumping:     	Jumping();			break;
   5D29 C3 71 5B      [10] 3286 	jp  _Jumping
                           3287 ;src/main.c:1080: case S_falling:      	Falling();			break;
   5D2C C3 E2 59      [10] 3288 	jp  _Falling
                           3289 ;src/main.c:1081: case S_landing:  		StopIn();			break;
   5D2F C3 79 5A      [10] 3290 	jp  _StopIn
                           3291 ;src/main.c:1082: case S_firing:   		Firing();
   5D32                    3292 00108$:
                           3293 ;src/main.c:1022: spr[0].status = shot.status; 
   5D32 3A 13 4C      [13] 3294 	ld	a, (#(_shot + 0x0004) + 0)
   5D35 02            [ 7] 3295 	ld	(bc), a
                           3296 ;src/main.c:1083: }
   5D36 C9            [10] 3297 	ret
                           3298 ;src/main.c:1088: void ExplodePlayer() {
                           3299 ;	---------------------------------
                           3300 ; Function ExplodePlayer
                           3301 ; ---------------------------------
   5D37                    3302 _ExplodePlayer::
                           3303 ;src/main.c:1090: cpct_akp_SFXPlay (4, 15, 40, 0, 0, AY_CHANNEL_A); // explosion
   5D37 3E 01         [ 7] 3304 	ld	a, #0x01
   5D39 F5            [11] 3305 	push	af
   5D3A 33            [ 6] 3306 	inc	sp
   5D3B 21 00 00      [10] 3307 	ld	hl, #0x0000
   5D3E E5            [11] 3308 	push	hl
   5D3F 2E 28         [ 7] 3309 	ld	l, #0x28
   5D41 E5            [11] 3310 	push	hl
   5D42 21 04 0F      [10] 3311 	ld	hl, #0x0f04
   5D45 E5            [11] 3312 	push	hl
   5D46 CD 5F 46      [17] 3313 	call	_cpct_akp_SFXPlay
   5D49 21 07 00      [10] 3314 	ld	hl, #7
   5D4C 39            [11] 3315 	add	hl, sp
   5D4D F9            [ 6] 3316 	ld	sp, hl
                           3317 ;src/main.c:1091: PrintExplosion(&spr[0], 0); Pause(20);
   5D4E AF            [ 4] 3318 	xor	a, a
   5D4F F5            [11] 3319 	push	af
   5D50 33            [ 6] 3320 	inc	sp
   5D51 21 C3 4B      [10] 3321 	ld	hl, #_spr
   5D54 E5            [11] 3322 	push	hl
   5D55 CD A1 55      [17] 3323 	call	_PrintExplosion
   5D58 F1            [10] 3324 	pop	af
   5D59 33            [ 6] 3325 	inc	sp
   5D5A 21 14 00      [10] 3326 	ld	hl, #0x0014
   5D5D CD 25 4E      [17] 3327 	call	_Pause
                           3328 ;src/main.c:1092: PrintExplosion(&spr[0], 1); Pause(20);
   5D60 3E 01         [ 7] 3329 	ld	a, #0x01
   5D62 F5            [11] 3330 	push	af
   5D63 33            [ 6] 3331 	inc	sp
   5D64 21 C3 4B      [10] 3332 	ld	hl, #_spr
   5D67 E5            [11] 3333 	push	hl
   5D68 CD A1 55      [17] 3334 	call	_PrintExplosion
   5D6B F1            [10] 3335 	pop	af
   5D6C 33            [ 6] 3336 	inc	sp
   5D6D 21 14 00      [10] 3337 	ld	hl, #0x0014
   5D70 CD 25 4E      [17] 3338 	call	_Pause
                           3339 ;src/main.c:1093: PrintExplosion(&spr[0], 0); Pause(20);
   5D73 AF            [ 4] 3340 	xor	a, a
   5D74 F5            [11] 3341 	push	af
   5D75 33            [ 6] 3342 	inc	sp
   5D76 21 C3 4B      [10] 3343 	ld	hl, #_spr
   5D79 E5            [11] 3344 	push	hl
   5D7A CD A1 55      [17] 3345 	call	_PrintExplosion
   5D7D F1            [10] 3346 	pop	af
   5D7E 33            [ 6] 3347 	inc	sp
   5D7F 21 14 00      [10] 3348 	ld	hl, #0x0014
   5D82 CD 25 4E      [17] 3349 	call	_Pause
                           3350 ;src/main.c:1094: DeleteSprite(&spr[0]);
   5D85 21 C3 4B      [10] 3351 	ld	hl, #_spr
   5D88 C3 42 55      [10] 3352 	jp  _DeleteSprite
                           3353 ;src/main.c:1111: void DeleteShot(TShot *pShot) __z88dk_fastcall {
                           3354 ;	---------------------------------
                           3355 ; Function DeleteShot
                           3356 ; ---------------------------------
   5D8B                    3357 _DeleteShot::
   5D8B DD E5         [15] 3358 	push	ix
   5D8D DD 21 00 00   [14] 3359 	ld	ix,#0
   5D91 DD 39         [15] 3360 	add	ix,sp
   5D93 3B            [ 6] 3361 	dec	sp
                           3362 ;src/main.c:1113: 2 + (pShot->px & 1), 2 + (pShot->y & 3 ? 1 : 0), 
   5D94 4D            [ 4] 3363 	ld	c,l
   5D95 44            [ 4] 3364 	ld	b,h
   5D96 23            [ 6] 3365 	inc	hl
   5D97 23            [ 6] 3366 	inc	hl
   5D98 5E            [ 7] 3367 	ld	e, (hl)
   5D99 7B            [ 4] 3368 	ld	a, e
   5D9A E6 03         [ 7] 3369 	and	a, #0x03
   5D9C 28 04         [12] 3370 	jr	Z,00103$
   5D9E 16 01         [ 7] 3371 	ld	d, #0x01
   5DA0 18 02         [12] 3372 	jr	00104$
   5DA2                    3373 00103$:
   5DA2 16 00         [ 7] 3374 	ld	d, #0x00
   5DA4                    3375 00104$:
   5DA4 14            [ 4] 3376 	inc	d
   5DA5 14            [ 4] 3377 	inc	d
   5DA6 69            [ 4] 3378 	ld	l, c
   5DA7 60            [ 4] 3379 	ld	h, b
   5DA8 23            [ 6] 3380 	inc	hl
   5DA9 4E            [ 7] 3381 	ld	c, (hl)
   5DAA 79            [ 4] 3382 	ld	a, c
   5DAB E6 01         [ 7] 3383 	and	a, #0x01
   5DAD C6 02         [ 7] 3384 	add	a, #0x02
   5DAF DD 77 FF      [19] 3385 	ld	-1 (ix), a
                           3386 ;src/main.c:1112: cpct_etm_drawTileBox2x4(pShot->px / 2, (pShot->y - ORIG_MAP_Y) / 4, 
   5DB2 06 00         [ 7] 3387 	ld	b, #0x00
   5DB4 6B            [ 4] 3388 	ld	l, e
   5DB5 60            [ 4] 3389 	ld	h, b
   5DB6 CB 78         [ 8] 3390 	bit	7, b
   5DB8 28 05         [12] 3391 	jr	Z,00105$
   5DBA 6B            [ 4] 3392 	ld	l, e
   5DBB 60            [ 4] 3393 	ld	h, b
   5DBC 23            [ 6] 3394 	inc	hl
   5DBD 23            [ 6] 3395 	inc	hl
   5DBE 23            [ 6] 3396 	inc	hl
   5DBF                    3397 00105$:
   5DBF CB 2C         [ 8] 3398 	sra	h
   5DC1 CB 1D         [ 8] 3399 	rr	l
   5DC3 CB 2C         [ 8] 3400 	sra	h
   5DC5 CB 1D         [ 8] 3401 	rr	l
   5DC7 5D            [ 4] 3402 	ld	e, l
   5DC8 CB 39         [ 8] 3403 	srl	c
   5DCA 21 31 10      [10] 3404 	ld	hl, #0x1031
   5DCD E5            [11] 3405 	push	hl
   5DCE 21 00 C0      [10] 3406 	ld	hl, #0xc000
   5DD1 E5            [11] 3407 	push	hl
   5DD2 3E 28         [ 7] 3408 	ld	a, #0x28
   5DD4 F5            [11] 3409 	push	af
   5DD5 33            [ 6] 3410 	inc	sp
   5DD6 D5            [11] 3411 	push	de
   5DD7 33            [ 6] 3412 	inc	sp
   5DD8 DD 56 FF      [19] 3413 	ld	d, -1 (ix)
   5DDB D5            [11] 3414 	push	de
   5DDC 79            [ 4] 3415 	ld	a, c
   5DDD F5            [11] 3416 	push	af
   5DDE 33            [ 6] 3417 	inc	sp
   5DDF CD 81 47      [17] 3418 	call	_cpct_etm_drawTileBox2x4
   5DE2 33            [ 6] 3419 	inc	sp
   5DE3 DD E1         [14] 3420 	pop	ix
   5DE5 C9            [10] 3421 	ret
                           3422 ;src/main.c:1119: void PrintShot(TShot *pShot, u8 frame) {
                           3423 ;	---------------------------------
                           3424 ; Function PrintShot
                           3425 ; ---------------------------------
   5DE6                    3426 _PrintShot::
   5DE6 DD E5         [15] 3427 	push	ix
   5DE8 DD 21 00 00   [14] 3428 	ld	ix,#0
   5DEC DD 39         [15] 3429 	add	ix,sp
                           3430 ;src/main.c:1120: if (pShot->active == TRUE) {
   5DEE DD 4E 04      [19] 3431 	ld	c,4 (ix)
   5DF1 DD 46 05      [19] 3432 	ld	b,5 (ix)
   5DF4 C5            [11] 3433 	push	bc
   5DF5 FD E1         [14] 3434 	pop	iy
   5DF7 FD 5E 05      [19] 3435 	ld	e, 5 (iy)
   5DFA 1D            [ 4] 3436 	dec	e
   5DFB 20 33         [12] 3437 	jr	NZ,00103$
                           3438 ;src/main.c:1121: DeleteShot(pShot); // delete previous shot
   5DFD C5            [11] 3439 	push	bc
   5DFE 69            [ 4] 3440 	ld	l, c
   5DFF 60            [ 4] 3441 	ld	h, b
   5E00 CD 8B 5D      [17] 3442 	call	_DeleteShot
   5E03 C1            [10] 3443 	pop	bc
                           3444 ;src/main.c:1124: SHOT_W, SHOT_H, g_maskTable);
                           3445 ;src/main.c:1123: cpct_getScreenPtr(CPCT_VMEM_START, pShot->x, pShot->y), 
   5E04 69            [ 4] 3446 	ld	l, c
   5E05 60            [ 4] 3447 	ld	h, b
   5E06 23            [ 6] 3448 	inc	hl
   5E07 23            [ 6] 3449 	inc	hl
   5E08 56            [ 7] 3450 	ld	d, (hl)
   5E09 0A            [ 7] 3451 	ld	a, (bc)
   5E0A 5F            [ 4] 3452 	ld	e,a
   5E0B D5            [11] 3453 	push	de
   5E0C 21 00 C0      [10] 3454 	ld	hl, #0xc000
   5E0F E5            [11] 3455 	push	hl
   5E10 CD AA 4A      [17] 3456 	call	_cpct_getScreenPtr
   5E13 4D            [ 4] 3457 	ld	c, l
   5E14 44            [ 4] 3458 	ld	b, h
                           3459 ;src/main.c:1122: cpct_drawSpriteMaskedAlignedTable(g_shots[frame],
   5E15 11 79 3D      [10] 3460 	ld	de, #_g_shots+0
   5E18 DD 6E 06      [19] 3461 	ld	l, 6 (ix)
   5E1B 26 00         [ 7] 3462 	ld	h, #0x00
   5E1D 29            [11] 3463 	add	hl, hl
   5E1E 29            [11] 3464 	add	hl, hl
   5E1F 29            [11] 3465 	add	hl, hl
   5E20 29            [11] 3466 	add	hl, hl
   5E21 29            [11] 3467 	add	hl, hl
   5E22 19            [11] 3468 	add	hl, de
   5E23 11 00 01      [10] 3469 	ld	de, #_g_maskTable
   5E26 D5            [11] 3470 	push	de
   5E27 11 04 08      [10] 3471 	ld	de, #0x0804
   5E2A D5            [11] 3472 	push	de
   5E2B C5            [11] 3473 	push	bc
   5E2C E5            [11] 3474 	push	hl
   5E2D CD C0 4A      [17] 3475 	call	_cpct_drawSpriteMaskedAlignedTable
   5E30                    3476 00103$:
   5E30 DD E1         [14] 3477 	pop	ix
   5E32 C9            [10] 3478 	ret
                           3479 ;src/main.c:1130: void MoveShot(TShot *pShot, u8 speed) {
                           3480 ;	---------------------------------
                           3481 ; Function MoveShot
                           3482 ; ---------------------------------
   5E33                    3483 _MoveShot::
   5E33 DD E5         [15] 3484 	push	ix
   5E35 DD 21 00 00   [14] 3485 	ld	ix,#0
   5E39 DD 39         [15] 3486 	add	ix,sp
                           3487 ;src/main.c:1131: pShot->px = pShot->x; // save the current X coordinate
   5E3B DD 4E 04      [19] 3488 	ld	c,4 (ix)
   5E3E DD 46 05      [19] 3489 	ld	b,5 (ix)
   5E41 59            [ 4] 3490 	ld	e, c
   5E42 50            [ 4] 3491 	ld	d, b
   5E43 13            [ 6] 3492 	inc	de
   5E44 0A            [ 7] 3493 	ld	a, (bc)
   5E45 12            [ 7] 3494 	ld	(de), a
                           3495 ;src/main.c:1134: if (pShot->dir == D_right) 
   5E46 69            [ 4] 3496 	ld	l, c
   5E47 60            [ 4] 3497 	ld	h, b
   5E48 23            [ 6] 3498 	inc	hl
   5E49 23            [ 6] 3499 	inc	hl
   5E4A 23            [ 6] 3500 	inc	hl
   5E4B 56            [ 7] 3501 	ld	d, (hl)
                           3502 ;src/main.c:1131: pShot->px = pShot->x; // save the current X coordinate
   5E4C 0A            [ 7] 3503 	ld	a, (bc)
   5E4D 5F            [ 4] 3504 	ld	e, a
                           3505 ;src/main.c:1134: if (pShot->dir == D_right) 
   5E4E 7A            [ 4] 3506 	ld	a, d
   5E4F D6 03         [ 7] 3507 	sub	a, #0x03
   5E51 20 07         [12] 3508 	jr	NZ,00102$
                           3509 ;src/main.c:1135: pShot->x = pShot->x + speed;
   5E53 7B            [ 4] 3510 	ld	a, e
   5E54 DD 86 06      [19] 3511 	add	a, 6 (ix)
   5E57 02            [ 7] 3512 	ld	(bc), a
   5E58 18 05         [12] 3513 	jr	00103$
   5E5A                    3514 00102$:
                           3515 ;src/main.c:1137: pShot->x = pShot->x - speed;
   5E5A 7B            [ 4] 3516 	ld	a, e
   5E5B DD 96 06      [19] 3517 	sub	a, 6 (ix)
   5E5E 02            [ 7] 3518 	ld	(bc), a
   5E5F                    3519 00103$:
                           3520 ;src/main.c:1131: pShot->px = pShot->x; // save the current X coordinate
   5E5F 0A            [ 7] 3521 	ld	a, (bc)
   5E60 5F            [ 4] 3522 	ld	e, a
                           3523 ;src/main.c:1140: if (pShot->x + SHOT_W >= GLOBAL_MAX_X || pShot->x <= 0) {
   5E61 6B            [ 4] 3524 	ld	l, e
   5E62 26 00         [ 7] 3525 	ld	h, #0x00
   5E64 23            [ 6] 3526 	inc	hl
   5E65 23            [ 6] 3527 	inc	hl
   5E66 23            [ 6] 3528 	inc	hl
   5E67 23            [ 6] 3529 	inc	hl
   5E68 7D            [ 4] 3530 	ld	a, l
   5E69 D6 50         [ 7] 3531 	sub	a, #0x50
   5E6B 7C            [ 4] 3532 	ld	a, h
   5E6C 17            [ 4] 3533 	rla
   5E6D 3F            [ 4] 3534 	ccf
   5E6E 1F            [ 4] 3535 	rra
   5E6F DE 80         [ 7] 3536 	sbc	a, #0x80
   5E71 30 04         [12] 3537 	jr	NC,00104$
   5E73 7B            [ 4] 3538 	ld	a, e
   5E74 B7            [ 4] 3539 	or	a, a
   5E75 20 0B         [12] 3540 	jr	NZ,00107$
   5E77                    3541 00104$:
                           3542 ;src/main.c:1141: pShot->active = FALSE;
   5E77 21 05 00      [10] 3543 	ld	hl, #0x0005
   5E7A 09            [11] 3544 	add	hl, bc
   5E7B 36 00         [10] 3545 	ld	(hl), #0x00
                           3546 ;src/main.c:1143: DeleteShot(pShot); 
   5E7D 69            [ 4] 3547 	ld	l, c
   5E7E 60            [ 4] 3548 	ld	h, b
   5E7F CD 8B 5D      [17] 3549 	call	_DeleteShot
   5E82                    3550 00107$:
   5E82 DD E1         [14] 3551 	pop	ix
   5E84 C9            [10] 3552 	ret
                           3553 ;src/main.c:1161: void MoveEnemy(TSpr *pSpr) { //__z88dk_fastcall
                           3554 ;	---------------------------------
                           3555 ; Function MoveEnemy
                           3556 ; ---------------------------------
   5E85                    3557 _MoveEnemy::
   5E85 DD E5         [15] 3558 	push	ix
   5E87 DD 21 00 00   [14] 3559 	ld	ix,#0
   5E8B DD 39         [15] 3560 	add	ix,sp
   5E8D 21 F7 FF      [10] 3561 	ld	hl, #-9
   5E90 39            [11] 3562 	add	hl, sp
   5E91 F9            [ 6] 3563 	ld	sp, hl
                           3564 ;src/main.c:1162: switch(pSpr->movType) 
   5E92 DD 4E 04      [19] 3565 	ld	c,4 (ix)
   5E95 DD 46 05      [19] 3566 	ld	b,5 (ix)
   5E98 C5            [11] 3567 	push	bc
   5E99 FD E1         [14] 3568 	pop	iy
   5E9B FD 6E 11      [19] 3569 	ld	l, 17 (iy)
                           3570 ;src/main.c:1166: if (pSpr->dir == D_right) {
   5E9E 79            [ 4] 3571 	ld	a, c
   5E9F C6 08         [ 7] 3572 	add	a, #0x08
   5EA1 5F            [ 4] 3573 	ld	e, a
   5EA2 78            [ 4] 3574 	ld	a, b
   5EA3 CE 00         [ 7] 3575 	adc	a, #0x00
   5EA5 57            [ 4] 3576 	ld	d, a
                           3577 ;src/main.c:1167: if (pSpr->x < pSpr->xMax) pSpr->x++;
   5EA6 79            [ 4] 3578 	ld	a, c
   5EA7 C6 0E         [ 7] 3579 	add	a, #0x0e
   5EA9 DD 77 FE      [19] 3580 	ld	-2 (ix), a
   5EAC 78            [ 4] 3581 	ld	a, b
   5EAD CE 00         [ 7] 3582 	adc	a, #0x00
   5EAF DD 77 FF      [19] 3583 	ld	-1 (ix), a
                           3584 ;src/main.c:1171: if (pSpr->x > pSpr->xMin) pSpr->x--;
   5EB2 79            [ 4] 3585 	ld	a, c
   5EB3 C6 0D         [ 7] 3586 	add	a, #0x0d
   5EB5 DD 77 FC      [19] 3587 	ld	-4 (ix), a
   5EB8 78            [ 4] 3588 	ld	a, b
   5EB9 CE 00         [ 7] 3589 	adc	a, #0x00
   5EBB DD 77 FD      [19] 3590 	ld	-3 (ix), a
                           3591 ;src/main.c:1162: switch(pSpr->movType) 
   5EBE 7D            [ 4] 3592 	ld	a, l
   5EBF B7            [ 4] 3593 	or	a, a
   5EC0 28 30         [12] 3594 	jr	Z,00101$
                           3595 ;src/main.c:1179: if (pSpr->y < pSpr->yMax) pSpr->y += 2;
   5EC2 79            [ 4] 3596 	ld	a, c
   5EC3 C6 01         [ 7] 3597 	add	a, #0x01
   5EC5 DD 77 FA      [19] 3598 	ld	-6 (ix), a
   5EC8 78            [ 4] 3599 	ld	a, b
   5EC9 CE 00         [ 7] 3600 	adc	a, #0x00
   5ECB DD 77 FB      [19] 3601 	ld	-5 (ix), a
   5ECE FD 21 10 00   [14] 3602 	ld	iy, #0x0010
   5ED2 FD 09         [15] 3603 	add	iy, bc
                           3604 ;src/main.c:1183: if (pSpr->y > pSpr->yMin) pSpr->y -= 2;
   5ED4 79            [ 4] 3605 	ld	a, c
   5ED5 C6 0F         [ 7] 3606 	add	a, #0x0f
   5ED7 DD 77 F8      [19] 3607 	ld	-8 (ix), a
   5EDA 78            [ 4] 3608 	ld	a, b
   5EDB CE 00         [ 7] 3609 	adc	a, #0x00
   5EDD DD 77 F9      [19] 3610 	ld	-7 (ix), a
                           3611 ;src/main.c:1162: switch(pSpr->movType) 
   5EE0 7D            [ 4] 3612 	ld	a, l
   5EE1 3D            [ 4] 3613 	dec	a
   5EE2 28 4E         [12] 3614 	jr	Z,00111$
   5EE4 7D            [ 4] 3615 	ld	a,l
   5EE5 FE 02         [ 7] 3616 	cp	a,#0x02
   5EE7 CA 71 5F      [10] 3617 	jp	Z,00121$
   5EEA D6 03         [ 7] 3618 	sub	a, #0x03
   5EEC CA 8A 60      [10] 3619 	jp	Z,00161$
   5EEF C3 ED 60      [10] 3620 	jp	00172$
                           3621 ;src/main.c:1165: case M_linear_X:
   5EF2                    3622 00101$:
                           3623 ;src/main.c:1166: if (pSpr->dir == D_right) {
   5EF2 1A            [ 7] 3624 	ld	a, (de)
                           3625 ;src/main.c:1167: if (pSpr->x < pSpr->xMax) pSpr->x++;
   5EF3 F5            [11] 3626 	push	af
   5EF4 0A            [ 7] 3627 	ld	a, (bc)
   5EF5 DD 77 F7      [19] 3628 	ld	-9 (ix), a
   5EF8 F1            [10] 3629 	pop	af
                           3630 ;src/main.c:1166: if (pSpr->dir == D_right) {
   5EF9 D6 03         [ 7] 3631 	sub	a, #0x03
   5EFB 20 1A         [12] 3632 	jr	NZ,00109$
                           3633 ;src/main.c:1167: if (pSpr->x < pSpr->xMax) pSpr->x++;
   5EFD DD 6E FE      [19] 3634 	ld	l,-2 (ix)
   5F00 DD 66 FF      [19] 3635 	ld	h,-1 (ix)
   5F03 DD 7E F7      [19] 3636 	ld	a,-9 (ix)
   5F06 96            [ 7] 3637 	sub	a,(hl)
   5F07 30 08         [12] 3638 	jr	NC,00103$
   5F09 DD 7E F7      [19] 3639 	ld	a, -9 (ix)
   5F0C 3C            [ 4] 3640 	inc	a
   5F0D 02            [ 7] 3641 	ld	(bc), a
   5F0E C3 ED 60      [10] 3642 	jp	00172$
   5F11                    3643 00103$:
                           3644 ;src/main.c:1168: else pSpr->dir = D_left;
   5F11 3E 02         [ 7] 3645 	ld	a, #0x02
   5F13 12            [ 7] 3646 	ld	(de), a
   5F14 C3 ED 60      [10] 3647 	jp	00172$
   5F17                    3648 00109$:
                           3649 ;src/main.c:1171: if (pSpr->x > pSpr->xMin) pSpr->x--;
   5F17 DD 6E FC      [19] 3650 	ld	l,-4 (ix)
   5F1A DD 66 FD      [19] 3651 	ld	h,-3 (ix)
   5F1D 7E            [ 7] 3652 	ld	a, (hl)
   5F1E DD 96 F7      [19] 3653 	sub	a, -9 (ix)
   5F21 30 09         [12] 3654 	jr	NC,00106$
   5F23 DD 5E F7      [19] 3655 	ld	e, -9 (ix)
   5F26 1D            [ 4] 3656 	dec	e
   5F27 7B            [ 4] 3657 	ld	a, e
   5F28 02            [ 7] 3658 	ld	(bc), a
   5F29 C3 ED 60      [10] 3659 	jp	00172$
   5F2C                    3660 00106$:
                           3661 ;src/main.c:1172: else pSpr->dir = D_right; 
   5F2C 3E 03         [ 7] 3662 	ld	a, #0x03
   5F2E 12            [ 7] 3663 	ld	(de), a
                           3664 ;src/main.c:1174: break;
   5F2F C3 ED 60      [10] 3665 	jp	00172$
                           3666 ;src/main.c:1177: case M_linear_Y:
   5F32                    3667 00111$:
                           3668 ;src/main.c:1178: if (pSpr->dir == D_down) {
   5F32 1A            [ 7] 3669 	ld	a, (de)
                           3670 ;src/main.c:1194: if (pSpr->y < pSpr->yMax && !OnPlatform(pSpr)) pSpr->y++;
   5F33 DD 6E FA      [19] 3671 	ld	l,-6 (ix)
   5F36 DD 66 FB      [19] 3672 	ld	h,-5 (ix)
   5F39 4E            [ 7] 3673 	ld	c, (hl)
                           3674 ;src/main.c:1178: if (pSpr->dir == D_down) {
   5F3A 3D            [ 4] 3675 	dec	a
   5F3B 20 18         [12] 3676 	jr	NZ,00119$
                           3677 ;src/main.c:1179: if (pSpr->y < pSpr->yMax) pSpr->y += 2;
   5F3D FD 46 00      [19] 3678 	ld	b, 0 (iy)
   5F40 79            [ 4] 3679 	ld	a, c
   5F41 90            [ 4] 3680 	sub	a, b
   5F42 30 0C         [12] 3681 	jr	NC,00113$
   5F44 0C            [ 4] 3682 	inc	c
   5F45 0C            [ 4] 3683 	inc	c
   5F46 DD 6E FA      [19] 3684 	ld	l,-6 (ix)
   5F49 DD 66 FB      [19] 3685 	ld	h,-5 (ix)
   5F4C 71            [ 7] 3686 	ld	(hl), c
   5F4D C3 ED 60      [10] 3687 	jp	00172$
   5F50                    3688 00113$:
                           3689 ;src/main.c:1180: else pSpr->dir = D_up;
   5F50 AF            [ 4] 3690 	xor	a, a
   5F51 12            [ 7] 3691 	ld	(de), a
   5F52 C3 ED 60      [10] 3692 	jp	00172$
   5F55                    3693 00119$:
                           3694 ;src/main.c:1183: if (pSpr->y > pSpr->yMin) pSpr->y -= 2;
   5F55 DD 6E F8      [19] 3695 	ld	l,-8 (ix)
   5F58 DD 66 F9      [19] 3696 	ld	h,-7 (ix)
   5F5B 7E            [ 7] 3697 	ld	a, (hl)
   5F5C 91            [ 4] 3698 	sub	a, c
   5F5D 30 0C         [12] 3699 	jr	NC,00116$
   5F5F 0D            [ 4] 3700 	dec	c
   5F60 0D            [ 4] 3701 	dec	c
   5F61 DD 6E FA      [19] 3702 	ld	l,-6 (ix)
   5F64 DD 66 FB      [19] 3703 	ld	h,-5 (ix)
   5F67 71            [ 7] 3704 	ld	(hl), c
   5F68 C3 ED 60      [10] 3705 	jp	00172$
   5F6B                    3706 00116$:
                           3707 ;src/main.c:1184: else pSpr->dir = D_down; 
   5F6B 3E 01         [ 7] 3708 	ld	a, #0x01
   5F6D 12            [ 7] 3709 	ld	(de), a
                           3710 ;src/main.c:1186: break;
   5F6E C3 ED 60      [10] 3711 	jp	00172$
                           3712 ;src/main.c:1189: case M_diagonal:
   5F71                    3713 00121$:
                           3714 ;src/main.c:1191: if (pSpr->dir == D_right_down || pSpr->dir == D_right) {
   5F71 1A            [ 7] 3715 	ld	a, (de)
   5F72 FE 07         [ 7] 3716 	cp	a, #0x07
   5F74 28 04         [12] 3717 	jr	Z,00157$
   5F76 FE 03         [ 7] 3718 	cp	a, #0x03
   5F78 20 43         [12] 3719 	jr	NZ,00158$
   5F7A                    3720 00157$:
                           3721 ;src/main.c:1192: if (pSpr->x < pSpr->xMax) {
   5F7A 0A            [ 7] 3722 	ld	a, (bc)
   5F7B DD 6E FE      [19] 3723 	ld	l,-2 (ix)
   5F7E DD 66 FF      [19] 3724 	ld	h,-1 (ix)
   5F81 6E            [ 7] 3725 	ld	l, (hl)
   5F82 BD            [ 4] 3726 	cp	a, l
   5F83 30 32         [12] 3727 	jr	NC,00127$
                           3728 ;src/main.c:1193: pSpr->x++;					
   5F85 3C            [ 4] 3729 	inc	a
   5F86 02            [ 7] 3730 	ld	(bc), a
                           3731 ;src/main.c:1194: if (pSpr->y < pSpr->yMax && !OnPlatform(pSpr)) pSpr->y++;
   5F87 DD 6E FA      [19] 3732 	ld	l,-6 (ix)
   5F8A DD 66 FB      [19] 3733 	ld	h,-5 (ix)
   5F8D 7E            [ 7] 3734 	ld	a, (hl)
   5F8E FD 6E 00      [19] 3735 	ld	l, 0 (iy)
   5F91 95            [ 4] 3736 	sub	a, l
   5F92 30 1D         [12] 3737 	jr	NC,00123$
   5F94 D5            [11] 3738 	push	de
   5F95 69            [ 4] 3739 	ld	l, c
   5F96 60            [ 4] 3740 	ld	h, b
   5F97 CD 9E 50      [17] 3741 	call	_OnPlatform
   5F9A D1            [10] 3742 	pop	de
   5F9B 7D            [ 4] 3743 	ld	a, l
   5F9C B7            [ 4] 3744 	or	a, a
   5F9D 20 12         [12] 3745 	jr	NZ,00123$
   5F9F DD 6E FA      [19] 3746 	ld	l,-6 (ix)
   5FA2 DD 66 FB      [19] 3747 	ld	h,-5 (ix)
   5FA5 4E            [ 7] 3748 	ld	c, (hl)
   5FA6 0C            [ 4] 3749 	inc	c
   5FA7 DD 6E FA      [19] 3750 	ld	l,-6 (ix)
   5FAA DD 66 FB      [19] 3751 	ld	h,-5 (ix)
   5FAD 71            [ 7] 3752 	ld	(hl), c
   5FAE C3 ED 60      [10] 3753 	jp	00172$
   5FB1                    3754 00123$:
                           3755 ;src/main.c:1195: else pSpr->dir = D_right_up;
   5FB1 3E 06         [ 7] 3756 	ld	a, #0x06
   5FB3 12            [ 7] 3757 	ld	(de), a
   5FB4 C3 ED 60      [10] 3758 	jp	00172$
   5FB7                    3759 00127$:
                           3760 ;src/main.c:1197: else pSpr->dir = D_left_down;
   5FB7 3E 05         [ 7] 3761 	ld	a, #0x05
   5FB9 12            [ 7] 3762 	ld	(de), a
   5FBA C3 ED 60      [10] 3763 	jp	00172$
   5FBD                    3764 00158$:
                           3765 ;src/main.c:1200: else if (pSpr->dir == D_right_up) {
   5FBD FE 06         [ 7] 3766 	cp	a, #0x06
   5FBF 20 35         [12] 3767 	jr	NZ,00155$
                           3768 ;src/main.c:1201: if (pSpr->x < pSpr->xMax) {
   5FC1 0A            [ 7] 3769 	ld	a, (bc)
   5FC2 DD 6E FE      [19] 3770 	ld	l,-2 (ix)
   5FC5 DD 66 FF      [19] 3771 	ld	h,-1 (ix)
   5FC8 6E            [ 7] 3772 	ld	l, (hl)
   5FC9 BD            [ 4] 3773 	cp	a, l
   5FCA 30 24         [12] 3774 	jr	NC,00133$
                           3775 ;src/main.c:1202: pSpr->x++;
   5FCC 3C            [ 4] 3776 	inc	a
   5FCD 02            [ 7] 3777 	ld	(bc), a
                           3778 ;src/main.c:1203: if (pSpr->y > pSpr->yMin) pSpr->y--;
   5FCE DD 6E FA      [19] 3779 	ld	l,-6 (ix)
   5FD1 DD 66 FB      [19] 3780 	ld	h,-5 (ix)
   5FD4 4E            [ 7] 3781 	ld	c, (hl)
   5FD5 DD 6E F8      [19] 3782 	ld	l,-8 (ix)
   5FD8 DD 66 F9      [19] 3783 	ld	h,-7 (ix)
   5FDB 7E            [ 7] 3784 	ld	a, (hl)
   5FDC 91            [ 4] 3785 	sub	a, c
   5FDD 30 0B         [12] 3786 	jr	NC,00130$
   5FDF 0D            [ 4] 3787 	dec	c
   5FE0 DD 6E FA      [19] 3788 	ld	l,-6 (ix)
   5FE3 DD 66 FB      [19] 3789 	ld	h,-5 (ix)
   5FE6 71            [ 7] 3790 	ld	(hl), c
   5FE7 C3 ED 60      [10] 3791 	jp	00172$
   5FEA                    3792 00130$:
                           3793 ;src/main.c:1204: else pSpr->dir = D_right_down;
   5FEA 3E 07         [ 7] 3794 	ld	a, #0x07
   5FEC 12            [ 7] 3795 	ld	(de), a
   5FED C3 ED 60      [10] 3796 	jp	00172$
   5FF0                    3797 00133$:
                           3798 ;src/main.c:1206: else pSpr->dir = D_left_up;
   5FF0 3E 04         [ 7] 3799 	ld	a, #0x04
   5FF2 12            [ 7] 3800 	ld	(de), a
   5FF3 C3 ED 60      [10] 3801 	jp	00172$
   5FF6                    3802 00155$:
                           3803 ;src/main.c:1209: else if (pSpr->dir == D_left_up || pSpr->dir == D_left)	{
   5FF6 FE 04         [ 7] 3804 	cp	a, #0x04
   5FF8 28 04         [12] 3805 	jr	Z,00150$
   5FFA FE 02         [ 7] 3806 	cp	a, #0x02
   5FFC 20 3E         [12] 3807 	jr	NZ,00151$
   5FFE                    3808 00150$:
                           3809 ;src/main.c:1210: if (pSpr->x > pSpr->xMin) {
   5FFE 0A            [ 7] 3810 	ld	a, (bc)
   5FFF DD 77 F7      [19] 3811 	ld	-9 (ix), a
   6002 DD 6E FC      [19] 3812 	ld	l,-4 (ix)
   6005 DD 66 FD      [19] 3813 	ld	h,-3 (ix)
   6008 7E            [ 7] 3814 	ld	a, (hl)
   6009 DD 96 F7      [19] 3815 	sub	a, -9 (ix)
   600C 30 28         [12] 3816 	jr	NC,00139$
                           3817 ;src/main.c:1211: pSpr->x--;
   600E DD 7E F7      [19] 3818 	ld	a, -9 (ix)
   6011 C6 FF         [ 7] 3819 	add	a, #0xff
   6013 02            [ 7] 3820 	ld	(bc), a
                           3821 ;src/main.c:1212: if (pSpr->y > pSpr->yMin) pSpr->y--;
   6014 DD 6E FA      [19] 3822 	ld	l,-6 (ix)
   6017 DD 66 FB      [19] 3823 	ld	h,-5 (ix)
   601A 4E            [ 7] 3824 	ld	c, (hl)
   601B DD 6E F8      [19] 3825 	ld	l,-8 (ix)
   601E DD 66 F9      [19] 3826 	ld	h,-7 (ix)
   6021 7E            [ 7] 3827 	ld	a, (hl)
   6022 91            [ 4] 3828 	sub	a, c
   6023 30 0B         [12] 3829 	jr	NC,00136$
   6025 0D            [ 4] 3830 	dec	c
   6026 DD 6E FA      [19] 3831 	ld	l,-6 (ix)
   6029 DD 66 FB      [19] 3832 	ld	h,-5 (ix)
   602C 71            [ 7] 3833 	ld	(hl), c
   602D C3 ED 60      [10] 3834 	jp	00172$
   6030                    3835 00136$:
                           3836 ;src/main.c:1213: else pSpr->dir = D_left_down;
   6030 3E 05         [ 7] 3837 	ld	a, #0x05
   6032 12            [ 7] 3838 	ld	(de), a
   6033 C3 ED 60      [10] 3839 	jp	00172$
   6036                    3840 00139$:
                           3841 ;src/main.c:1215: else pSpr->dir = D_right_up; 
   6036 3E 06         [ 7] 3842 	ld	a, #0x06
   6038 12            [ 7] 3843 	ld	(de), a
   6039 C3 ED 60      [10] 3844 	jp	00172$
   603C                    3845 00151$:
                           3846 ;src/main.c:1218: else if (pSpr->dir == D_left_down) {
   603C D6 05         [ 7] 3847 	sub	a, #0x05
   603E C2 ED 60      [10] 3848 	jp	NZ,00172$
                           3849 ;src/main.c:1219: if (pSpr->x > pSpr->xMin) {
   6041 0A            [ 7] 3850 	ld	a, (bc)
   6042 DD 77 F7      [19] 3851 	ld	-9 (ix), a
   6045 DD 6E FC      [19] 3852 	ld	l,-4 (ix)
   6048 DD 66 FD      [19] 3853 	ld	h,-3 (ix)
   604B 7E            [ 7] 3854 	ld	a, (hl)
   604C DD 96 F7      [19] 3855 	sub	a, -9 (ix)
   604F 30 34         [12] 3856 	jr	NC,00146$
                           3857 ;src/main.c:1220: pSpr->x--;
   6051 DD 7E F7      [19] 3858 	ld	a, -9 (ix)
   6054 C6 FF         [ 7] 3859 	add	a, #0xff
   6056 02            [ 7] 3860 	ld	(bc), a
                           3861 ;src/main.c:1221: if (pSpr->y < pSpr->yMax && !OnPlatform(pSpr)) pSpr->y++;
   6057 DD 6E FA      [19] 3862 	ld	l,-6 (ix)
   605A DD 66 FB      [19] 3863 	ld	h,-5 (ix)
   605D 7E            [ 7] 3864 	ld	a, (hl)
   605E FD 6E 00      [19] 3865 	ld	l, 0 (iy)
   6061 95            [ 4] 3866 	sub	a, l
   6062 30 1C         [12] 3867 	jr	NC,00142$
   6064 D5            [11] 3868 	push	de
   6065 69            [ 4] 3869 	ld	l, c
   6066 60            [ 4] 3870 	ld	h, b
   6067 CD 9E 50      [17] 3871 	call	_OnPlatform
   606A D1            [10] 3872 	pop	de
   606B 7D            [ 4] 3873 	ld	a, l
   606C B7            [ 4] 3874 	or	a, a
   606D 20 11         [12] 3875 	jr	NZ,00142$
   606F DD 6E FA      [19] 3876 	ld	l,-6 (ix)
   6072 DD 66 FB      [19] 3877 	ld	h,-5 (ix)
   6075 4E            [ 7] 3878 	ld	c, (hl)
   6076 0C            [ 4] 3879 	inc	c
   6077 DD 6E FA      [19] 3880 	ld	l,-6 (ix)
   607A DD 66 FB      [19] 3881 	ld	h,-5 (ix)
   607D 71            [ 7] 3882 	ld	(hl), c
   607E 18 6D         [12] 3883 	jr	00172$
   6080                    3884 00142$:
                           3885 ;src/main.c:1222: else pSpr->dir = D_left_up;
   6080 3E 04         [ 7] 3886 	ld	a, #0x04
   6082 12            [ 7] 3887 	ld	(de), a
   6083 18 68         [12] 3888 	jr	00172$
   6085                    3889 00146$:
                           3890 ;src/main.c:1224: else pSpr->dir = D_right_down;
   6085 3E 07         [ 7] 3891 	ld	a, #0x07
   6087 12            [ 7] 3892 	ld	(de), a
                           3893 ;src/main.c:1226: break;
   6088 18 63         [12] 3894 	jr	00172$
                           3895 ;src/main.c:1229: case M_chaser:
   608A                    3896 00161$:
                           3897 ;src/main.c:1230: if (ctMainLoop % 3 == 0) { // slow motion, moves one in three iterations
   608A C5            [11] 3898 	push	bc
   608B D5            [11] 3899 	push	de
   608C 3E 03         [ 7] 3900 	ld	a, #0x03
   608E F5            [11] 3901 	push	af
   608F 33            [ 6] 3902 	inc	sp
   6090 3A B1 4B      [13] 3903 	ld	a, (_ctMainLoop)
   6093 F5            [11] 3904 	push	af
   6094 33            [ 6] 3905 	inc	sp
   6095 CD 14 48      [17] 3906 	call	__moduchar
   6098 F1            [10] 3907 	pop	af
   6099 D1            [10] 3908 	pop	de
   609A C1            [10] 3909 	pop	bc
   609B 7D            [ 4] 3910 	ld	a, l
   609C B7            [ 4] 3911 	or	a, a
   609D 20 4E         [12] 3912 	jr	NZ,00172$
                           3913 ;src/main.c:1231: if (pSpr->x <= spr[0].x) { // is to the player's left
   609F 0A            [ 7] 3914 	ld	a, (bc)
   60A0 DD 77 F7      [19] 3915 	ld	-9 (ix), a
   60A3 3A C3 4B      [13] 3916 	ld	a, (#_spr+0)
   60A6 DD 96 F7      [19] 3917 	sub	a, -9 (ix)
   60A9 38 0A         [12] 3918 	jr	C,00163$
                           3919 ;src/main.c:1232: pSpr->x++;
   60AB DD 7E F7      [19] 3920 	ld	a, -9 (ix)
   60AE 3C            [ 4] 3921 	inc	a
   60AF 02            [ 7] 3922 	ld	(bc), a
                           3923 ;src/main.c:1233: pSpr->dir = D_right;
   60B0 3E 03         [ 7] 3924 	ld	a, #0x03
   60B2 12            [ 7] 3925 	ld	(de), a
   60B3 18 09         [12] 3926 	jr	00164$
   60B5                    3927 00163$:
                           3928 ;src/main.c:1236: pSpr->x--;
   60B5 DD 7E F7      [19] 3929 	ld	a, -9 (ix)
   60B8 C6 FF         [ 7] 3930 	add	a, #0xff
   60BA 02            [ 7] 3931 	ld	(bc), a
                           3932 ;src/main.c:1237: pSpr->dir = D_left;
   60BB 3E 02         [ 7] 3933 	ld	a, #0x02
   60BD 12            [ 7] 3934 	ld	(de), a
   60BE                    3935 00164$:
                           3936 ;src/main.c:1194: if (pSpr->y < pSpr->yMax && !OnPlatform(pSpr)) pSpr->y++;
   60BE DD 6E FA      [19] 3937 	ld	l,-6 (ix)
   60C1 DD 66 FB      [19] 3938 	ld	h,-5 (ix)
   60C4 5E            [ 7] 3939 	ld	e, (hl)
                           3940 ;src/main.c:1240: if (pSpr->y <= spr[0].y && !OnPlatform(pSpr)) pSpr->y++;
   60C5 3A C4 4B      [13] 3941 	ld	a, (#_spr+1)
   60C8 93            [ 4] 3942 	sub	a, e
   60C9 38 1A         [12] 3943 	jr	C,00166$
   60CB 69            [ 4] 3944 	ld	l, c
   60CC 60            [ 4] 3945 	ld	h, b
   60CD CD 9E 50      [17] 3946 	call	_OnPlatform
   60D0 7D            [ 4] 3947 	ld	a, l
                           3948 ;src/main.c:1194: if (pSpr->y < pSpr->yMax && !OnPlatform(pSpr)) pSpr->y++;
   60D1 DD 6E FA      [19] 3949 	ld	l,-6 (ix)
   60D4 DD 66 FB      [19] 3950 	ld	h,-5 (ix)
   60D7 5E            [ 7] 3951 	ld	e, (hl)
                           3952 ;src/main.c:1240: if (pSpr->y <= spr[0].y && !OnPlatform(pSpr)) pSpr->y++;
   60D8 B7            [ 4] 3953 	or	a, a
   60D9 20 0A         [12] 3954 	jr	NZ,00166$
   60DB 1C            [ 4] 3955 	inc	e
   60DC DD 6E FA      [19] 3956 	ld	l,-6 (ix)
   60DF DD 66 FB      [19] 3957 	ld	h,-5 (ix)
   60E2 73            [ 7] 3958 	ld	(hl), e
   60E3 18 08         [12] 3959 	jr	00172$
   60E5                    3960 00166$:
                           3961 ;src/main.c:1241: else pSpr->y--; // is below the main sprite
   60E5 1D            [ 4] 3962 	dec	e
   60E6 DD 6E FA      [19] 3963 	ld	l,-6 (ix)
   60E9 DD 66 FB      [19] 3964 	ld	h,-5 (ix)
   60EC 73            [ 7] 3965 	ld	(hl), e
                           3966 ;src/main.c:1244: }
   60ED                    3967 00172$:
   60ED DD F9         [10] 3968 	ld	sp, ix
   60EF DD E1         [14] 3969 	pop	ix
   60F1 C9            [10] 3970 	ret
                           3971 ;src/main.c:1249: void SetEnemyParams(u8 i, u8 ident, u8 mov, u8 lives, u8 dir, u8 x, u8 y, u8 xMin, u8 yMin, u8 xMax, u8 yMax) {
                           3972 ;	---------------------------------
                           3973 ; Function SetEnemyParams
                           3974 ; ---------------------------------
   60F2                    3975 _SetEnemyParams::
   60F2 DD E5         [15] 3976 	push	ix
   60F4 DD 21 00 00   [14] 3977 	ld	ix,#0
   60F8 DD 39         [15] 3978 	add	ix,sp
                           3979 ;src/main.c:1250: spr[i].status = S_walking;
   60FA 01 C3 4B      [10] 3980 	ld	bc, #_spr+0
   60FD DD 5E 04      [19] 3981 	ld	e,4 (ix)
   6100 16 00         [ 7] 3982 	ld	d,#0x00
   6102 6B            [ 4] 3983 	ld	l, e
   6103 62            [ 4] 3984 	ld	h, d
   6104 29            [11] 3985 	add	hl, hl
   6105 29            [11] 3986 	add	hl, hl
   6106 29            [11] 3987 	add	hl, hl
   6107 19            [11] 3988 	add	hl, de
   6108 29            [11] 3989 	add	hl, hl
   6109 19            [11] 3990 	add	hl, de
   610A 09            [11] 3991 	add	hl,bc
   610B 4D            [ 4] 3992 	ld	c, l
   610C 44            [ 4] 3993 	ld	b, h
   610D 21 04 00      [10] 3994 	ld	hl, #0x0004
   6110 09            [11] 3995 	add	hl, bc
   6111 36 01         [10] 3996 	ld	(hl), #0x01
                           3997 ;src/main.c:1251: spr[i].ident = ident; 
   6113 21 12 00      [10] 3998 	ld	hl, #0x0012
   6116 09            [11] 3999 	add	hl, bc
   6117 DD 7E 05      [19] 4000 	ld	a, 5 (ix)
   611A 77            [ 7] 4001 	ld	(hl), a
                           4002 ;src/main.c:1252: spr[i].movType = mov;
   611B 21 11 00      [10] 4003 	ld	hl, #0x0011
   611E 09            [11] 4004 	add	hl, bc
   611F DD 7E 06      [19] 4005 	ld	a, 6 (ix)
   6122 77            [ 7] 4006 	ld	(hl), a
                           4007 ;src/main.c:1253: spr[i].lives = lives; 
   6123 21 09 00      [10] 4008 	ld	hl, #0x0009
   6126 09            [11] 4009 	add	hl, bc
   6127 DD 7E 07      [19] 4010 	ld	a, 7 (ix)
   612A 77            [ 7] 4011 	ld	(hl), a
                           4012 ;src/main.c:1254: spr[i].dir = dir; 
   612B 21 08 00      [10] 4013 	ld	hl, #0x0008
   612E 09            [11] 4014 	add	hl, bc
   612F DD 7E 08      [19] 4015 	ld	a, 8 (ix)
   6132 77            [ 7] 4016 	ld	(hl), a
                           4017 ;src/main.c:1255: spr[i].x = spr[i].px = x;
   6133 59            [ 4] 4018 	ld	e, c
   6134 50            [ 4] 4019 	ld	d, b
   6135 13            [ 6] 4020 	inc	de
   6136 13            [ 6] 4021 	inc	de
   6137 DD 7E 09      [19] 4022 	ld	a, 9 (ix)
   613A 12            [ 7] 4023 	ld	(de), a
   613B DD 7E 09      [19] 4024 	ld	a, 9 (ix)
   613E 02            [ 7] 4025 	ld	(bc), a
                           4026 ;src/main.c:1256: spr[i].y = spr[i].py = y;
   613F 59            [ 4] 4027 	ld	e, c
   6140 50            [ 4] 4028 	ld	d, b
   6141 13            [ 6] 4029 	inc	de
   6142 69            [ 4] 4030 	ld	l, c
   6143 60            [ 4] 4031 	ld	h, b
   6144 23            [ 6] 4032 	inc	hl
   6145 23            [ 6] 4033 	inc	hl
   6146 23            [ 6] 4034 	inc	hl
   6147 DD 7E 0A      [19] 4035 	ld	a, 10 (ix)
   614A 77            [ 7] 4036 	ld	(hl), a
   614B DD 7E 0A      [19] 4037 	ld	a, 10 (ix)
   614E 12            [ 7] 4038 	ld	(de), a
                           4039 ;src/main.c:1257: spr[i].xMin = xMin;
   614F 21 0D 00      [10] 4040 	ld	hl, #0x000d
   6152 09            [11] 4041 	add	hl, bc
   6153 DD 7E 0B      [19] 4042 	ld	a, 11 (ix)
   6156 77            [ 7] 4043 	ld	(hl), a
                           4044 ;src/main.c:1258: spr[i].yMin = yMin;
   6157 21 0F 00      [10] 4045 	ld	hl, #0x000f
   615A 09            [11] 4046 	add	hl, bc
   615B DD 7E 0C      [19] 4047 	ld	a, 12 (ix)
   615E 77            [ 7] 4048 	ld	(hl), a
                           4049 ;src/main.c:1259: spr[i].xMax = xMax;
   615F 21 0E 00      [10] 4050 	ld	hl, #0x000e
   6162 09            [11] 4051 	add	hl, bc
   6163 DD 7E 0D      [19] 4052 	ld	a, 13 (ix)
   6166 77            [ 7] 4053 	ld	(hl), a
                           4054 ;src/main.c:1260: spr[i].yMax = yMax; 
   6167 21 10 00      [10] 4055 	ld	hl, #0x0010
   616A 09            [11] 4056 	add	hl, bc
   616B DD 7E 0E      [19] 4057 	ld	a, 14 (ix)
   616E 77            [ 7] 4058 	ld	(hl), a
                           4059 ;src/main.c:1261: spr[i].touched = 0;
   616F 21 0A 00      [10] 4060 	ld	hl, #0x000a
   6172 09            [11] 4061 	add	hl, bc
   6173 36 00         [10] 4062 	ld	(hl), #0x00
   6175 DD E1         [14] 4063 	pop	ix
   6177 C9            [10] 4064 	ret
                           4065 ;src/main.c:1271: void SetEnemies() {
                           4066 ;	---------------------------------
                           4067 ; Function SetEnemies
                           4068 ; ---------------------------------
   6178                    4069 _SetEnemies::
                           4070 ;src/main.c:1272: switch(mapNumber) {
   6178 FD 21 57 4C   [14] 4071 	ld	iy, #_mapNumber
   617C FD 7E 00      [19] 4072 	ld	a, 0 (iy)
   617F B7            [ 4] 4073 	or	a, a
   6180 28 0F         [12] 4074 	jr	Z,00101$
   6182 FD 7E 00      [19] 4075 	ld	a, 0 (iy)
   6185 3D            [ 4] 4076 	dec	a
   6186 28 6C         [12] 4077 	jr	Z,00102$
   6188 FD 7E 00      [19] 4078 	ld	a, 0 (iy)
   618B D6 02         [ 7] 4079 	sub	a, #0x02
   618D CA 5A 62      [10] 4080 	jp	Z,00103$
   6190 C9            [10] 4081 	ret
                           4082 ;src/main.c:1273: case 0: { // upper left deck upper floor #3
   6191                    4083 00101$:
                           4084 ;src/main.c:1275: SetEnemyParams(1, ARACNOVIRUS, 	M_linear_Y, 	2,  D_right, 48,  64,   48,   64,   48,  160);
   6191 21 30 A0      [10] 4085 	ld	hl, #0xa030
   6194 E5            [11] 4086 	push	hl
   6195 26 40         [ 7] 4087 	ld	h, #0x40
   6197 E5            [11] 4088 	push	hl
   6198 2E 30         [ 7] 4089 	ld	l, #0x30
   619A E5            [11] 4090 	push	hl
   619B 21 02 03      [10] 4091 	ld	hl, #0x0302
   619E E5            [11] 4092 	push	hl
   619F 26 01         [ 7] 4093 	ld	h, #0x01
   61A1 E5            [11] 4094 	push	hl
   61A2 3E 01         [ 7] 4095 	ld	a, #0x01
   61A4 F5            [11] 4096 	push	af
   61A5 33            [ 6] 4097 	inc	sp
   61A6 CD F2 60      [17] 4098 	call	_SetEnemyParams
   61A9 21 0B 00      [10] 4099 	ld	hl, #11
   61AC 39            [11] 4100 	add	hl, sp
   61AD F9            [ 6] 4101 	ld	sp, hl
                           4102 ;src/main.c:1276: SetEnemyParams(2, INFECTED, 	M_linear_X, 	3,  D_right, 16, 160,    8,  160,   64,  160);
   61AE 21 40 A0      [10] 4103 	ld	hl, #0xa040
   61B1 E5            [11] 4104 	push	hl
   61B2 2E 08         [ 7] 4105 	ld	l, #0x08
   61B4 E5            [11] 4106 	push	hl
   61B5 2E 10         [ 7] 4107 	ld	l, #0x10
   61B7 E5            [11] 4108 	push	hl
   61B8 21 03 03      [10] 4109 	ld	hl, #0x0303
   61BB E5            [11] 4110 	push	hl
   61BC 26 00         [ 7] 4111 	ld	h, #0x00
   61BE E5            [11] 4112 	push	hl
   61BF 3E 02         [ 7] 4113 	ld	a, #0x02
   61C1 F5            [11] 4114 	push	af
   61C2 33            [ 6] 4115 	inc	sp
   61C3 CD F2 60      [17] 4116 	call	_SetEnemyParams
   61C6 21 0B 00      [10] 4117 	ld	hl, #11
   61C9 39            [11] 4118 	add	hl, sp
   61CA F9            [ 6] 4119 	ld	sp, hl
                           4120 ;src/main.c:1277: SetEnemyParams(3, ARACNOVIRUS,	M_linear_X,		0,  D_right,  0,   0,    0,    0,    0,    0);
   61CB 21 00 00      [10] 4121 	ld	hl, #0x0000
   61CE E5            [11] 4122 	push	hl
   61CF 2E 00         [ 7] 4123 	ld	l, #0x00
   61D1 E5            [11] 4124 	push	hl
   61D2 2E 00         [ 7] 4125 	ld	l, #0x00
   61D4 E5            [11] 4126 	push	hl
   61D5 26 03         [ 7] 4127 	ld	h, #0x03
   61D7 E5            [11] 4128 	push	hl
   61D8 21 02 00      [10] 4129 	ld	hl, #0x0002
   61DB E5            [11] 4130 	push	hl
   61DC 3E 03         [ 7] 4131 	ld	a, #0x03
   61DE F5            [11] 4132 	push	af
   61DF 33            [ 6] 4133 	inc	sp
   61E0 CD F2 60      [17] 4134 	call	_SetEnemyParams
   61E3 21 0B 00      [10] 4135 	ld	hl, #11
   61E6 39            [11] 4136 	add	hl, sp
   61E7 F9            [ 6] 4137 	ld	sp, hl
                           4138 ;src/main.c:1279: cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk0_end);
   61E8 21 18 33      [10] 4139 	ld	hl, #(_mappk0 + 0x00e5)
   61EB E5            [11] 4140 	push	hl
   61EC 21 20 16      [10] 4141 	ld	hl, #0x1620
   61EF E5            [11] 4142 	push	hl
   61F0 CD 35 49      [17] 4143 	call	_cpct_zx7b_decrunch_s
                           4144 ;src/main.c:1280: break;
   61F3 C9            [10] 4145 	ret
                           4146 ;src/main.c:1282: case 1: { // upper left deck upper floor #2
   61F4                    4147 00102$:
                           4148 ;src/main.c:1284: SetEnemyParams(1, PELUSOID,		M_diagonal, 	3,	D_right,  8,  52,    8,   52,   64,  160);
   61F4 21 40 A0      [10] 4149 	ld	hl, #0xa040
   61F7 E5            [11] 4150 	push	hl
   61F8 21 08 34      [10] 4151 	ld	hl, #0x3408
   61FB E5            [11] 4152 	push	hl
   61FC 2E 08         [ 7] 4153 	ld	l, #0x08
   61FE E5            [11] 4154 	push	hl
   61FF 21 03 03      [10] 4155 	ld	hl, #0x0303
   6202 E5            [11] 4156 	push	hl
   6203 21 01 02      [10] 4157 	ld	hl, #0x0201
   6206 E5            [11] 4158 	push	hl
   6207 3E 01         [ 7] 4159 	ld	a, #0x01
   6209 F5            [11] 4160 	push	af
   620A 33            [ 6] 4161 	inc	sp
   620B CD F2 60      [17] 4162 	call	_SetEnemyParams
   620E 21 0B 00      [10] 4163 	ld	hl, #11
   6211 39            [11] 4164 	add	hl, sp
   6212 F9            [ 6] 4165 	ld	sp, hl
                           4166 ;src/main.c:1285: SetEnemyParams(2, PELUSOID, 	M_linear_Y, 	3,	D_right, 32,  52,   32,   52,   32,  160);		
   6213 21 20 A0      [10] 4167 	ld	hl, #0xa020
   6216 E5            [11] 4168 	push	hl
   6217 26 34         [ 7] 4169 	ld	h, #0x34
   6219 E5            [11] 4170 	push	hl
   621A 2E 20         [ 7] 4171 	ld	l, #0x20
   621C E5            [11] 4172 	push	hl
   621D 21 03 03      [10] 4173 	ld	hl, #0x0303
   6220 E5            [11] 4174 	push	hl
   6221 21 01 01      [10] 4175 	ld	hl, #0x0101
   6224 E5            [11] 4176 	push	hl
   6225 3E 02         [ 7] 4177 	ld	a, #0x02
   6227 F5            [11] 4178 	push	af
   6228 33            [ 6] 4179 	inc	sp
   6229 CD F2 60      [17] 4180 	call	_SetEnemyParams
   622C 21 0B 00      [10] 4181 	ld	hl, #11
   622F 39            [11] 4182 	add	hl, sp
   6230 F9            [ 6] 4183 	ld	sp, hl
                           4184 ;src/main.c:1286: SetEnemyParams(3, PELUSOID, 	M_linear_X,		0,	D_right,  0,   0,    0,    0,    0,    0);
   6231 21 00 00      [10] 4185 	ld	hl, #0x0000
   6234 E5            [11] 4186 	push	hl
   6235 2E 00         [ 7] 4187 	ld	l, #0x00
   6237 E5            [11] 4188 	push	hl
   6238 2E 00         [ 7] 4189 	ld	l, #0x00
   623A E5            [11] 4190 	push	hl
   623B 26 03         [ 7] 4191 	ld	h, #0x03
   623D E5            [11] 4192 	push	hl
   623E 21 01 00      [10] 4193 	ld	hl, #0x0001
   6241 E5            [11] 4194 	push	hl
   6242 3E 03         [ 7] 4195 	ld	a, #0x03
   6244 F5            [11] 4196 	push	af
   6245 33            [ 6] 4197 	inc	sp
   6246 CD F2 60      [17] 4198 	call	_SetEnemyParams
   6249 21 0B 00      [10] 4199 	ld	hl, #11
   624C 39            [11] 4200 	add	hl, sp
   624D F9            [ 6] 4201 	ld	sp, hl
                           4202 ;src/main.c:1288: cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk1_end);
   624E 21 32 32      [10] 4203 	ld	hl, #(_mappk1 + 0x00d3)
   6251 E5            [11] 4204 	push	hl
   6252 21 20 16      [10] 4205 	ld	hl, #0x1620
   6255 E5            [11] 4206 	push	hl
   6256 CD 35 49      [17] 4207 	call	_cpct_zx7b_decrunch_s
                           4208 ;src/main.c:1289: break;		
   6259 C9            [10] 4209 	ret
                           4210 ;src/main.c:1291: case 2: { // upper left deck upper floor #1
   625A                    4211 00103$:
                           4212 ;src/main.c:1293: SetEnemyParams(1, INFECTED,		M_linear_X,		2,	D_left, 32,  96,    8,   96,   64,   96);
   625A 21 40 60      [10] 4213 	ld	hl, #0x6040
   625D E5            [11] 4214 	push	hl
   625E 2E 08         [ 7] 4215 	ld	l, #0x08
   6260 E5            [11] 4216 	push	hl
   6261 2E 20         [ 7] 4217 	ld	l, #0x20
   6263 E5            [11] 4218 	push	hl
   6264 21 02 02      [10] 4219 	ld	hl, #0x0202
   6267 E5            [11] 4220 	push	hl
   6268 21 03 00      [10] 4221 	ld	hl, #0x0003
   626B E5            [11] 4222 	push	hl
   626C 3E 01         [ 7] 4223 	ld	a, #0x01
   626E F5            [11] 4224 	push	af
   626F 33            [ 6] 4225 	inc	sp
   6270 CD F2 60      [17] 4226 	call	_SetEnemyParams
   6273 21 0B 00      [10] 4227 	ld	hl, #11
   6276 39            [11] 4228 	add	hl, sp
   6277 F9            [ 6] 4229 	ld	sp, hl
                           4230 ;src/main.c:1294: SetEnemyParams(2, INFECTED, 	M_linear_X, 	2,	D_left, 64, 128,   16,  128,   64,  128);
   6278 21 40 80      [10] 4231 	ld	hl, #0x8040
   627B E5            [11] 4232 	push	hl
   627C 2E 10         [ 7] 4233 	ld	l, #0x10
   627E E5            [11] 4234 	push	hl
   627F 2E 40         [ 7] 4235 	ld	l, #0x40
   6281 E5            [11] 4236 	push	hl
   6282 21 02 02      [10] 4237 	ld	hl, #0x0202
   6285 E5            [11] 4238 	push	hl
   6286 21 03 00      [10] 4239 	ld	hl, #0x0003
   6289 E5            [11] 4240 	push	hl
   628A 3E 02         [ 7] 4241 	ld	a, #0x02
   628C F5            [11] 4242 	push	af
   628D 33            [ 6] 4243 	inc	sp
   628E CD F2 60      [17] 4244 	call	_SetEnemyParams
   6291 21 0B 00      [10] 4245 	ld	hl, #11
   6294 39            [11] 4246 	add	hl, sp
   6295 F9            [ 6] 4247 	ld	sp, hl
                           4248 ;src/main.c:1295: SetEnemyParams(3, INFECTED, 	M_linear_X,		2,	D_right, 24, 160,   8,  160,   48,  160);
   6296 21 30 A0      [10] 4249 	ld	hl, #0xa030
   6299 E5            [11] 4250 	push	hl
   629A 2E 08         [ 7] 4251 	ld	l, #0x08
   629C E5            [11] 4252 	push	hl
   629D 2E 18         [ 7] 4253 	ld	l, #0x18
   629F E5            [11] 4254 	push	hl
   62A0 21 02 03      [10] 4255 	ld	hl, #0x0302
   62A3 E5            [11] 4256 	push	hl
   62A4 21 03 00      [10] 4257 	ld	hl, #0x0003
   62A7 E5            [11] 4258 	push	hl
   62A8 3E 03         [ 7] 4259 	ld	a, #0x03
   62AA F5            [11] 4260 	push	af
   62AB 33            [ 6] 4261 	inc	sp
   62AC CD F2 60      [17] 4262 	call	_SetEnemyParams
   62AF 21 0B 00      [10] 4263 	ld	hl, #11
   62B2 39            [11] 4264 	add	hl, sp
   62B3 F9            [ 6] 4265 	ld	sp, hl
                           4266 ;src/main.c:1297: cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk2_end);
   62B4 21 5E 31      [10] 4267 	ld	hl, #(_mappk2 + 0x00e1)
   62B7 E5            [11] 4268 	push	hl
   62B8 21 20 16      [10] 4269 	ld	hl, #0x1620
   62BB E5            [11] 4270 	push	hl
   62BC CD 35 49      [17] 4271 	call	_cpct_zx7b_decrunch_s
                           4272 ;src/main.c:1299: }
   62BF C9            [10] 4273 	ret
                           4274 ;src/main.c:1304: void ExplosionSecuence(TSpr *pSpr) __z88dk_fastcall {
                           4275 ;	---------------------------------
                           4276 ; Function ExplosionSecuence
                           4277 ; ---------------------------------
   62C0                    4278 _ExplosionSecuence::
   62C0 4D            [ 4] 4279 	ld	c, l
   62C1 44            [ 4] 4280 	ld	b, h
                           4281 ;src/main.c:1305: if (pSpr->touched == 10) DeleteSprite(pSpr); 	
   62C2 21 0A 00      [10] 4282 	ld	hl, #0x000a
   62C5 09            [11] 4283 	add	hl,bc
   62C6 EB            [ 4] 4284 	ex	de,hl
   62C7 1A            [ 7] 4285 	ld	a, (de)
   62C8 6F            [ 4] 4286 	ld	l,a
   62C9 D6 0A         [ 7] 4287 	sub	a, #0x0a
   62CB 20 09         [12] 4288 	jr	NZ,00113$
   62CD D5            [11] 4289 	push	de
   62CE 69            [ 4] 4290 	ld	l, c
   62CF 60            [ 4] 4291 	ld	h, b
   62D0 CD 42 55      [17] 4292 	call	_DeleteSprite
   62D3 D1            [10] 4293 	pop	de
   62D4 18 43         [12] 4294 	jr	00114$
   62D6                    4295 00113$:
                           4296 ;src/main.c:1306: else if (pSpr->touched > 8) PrintExplosion(pSpr, 0);
   62D6 3E 08         [ 7] 4297 	ld	a, #0x08
   62D8 95            [ 4] 4298 	sub	a, l
   62D9 30 0D         [12] 4299 	jr	NC,00110$
   62DB D5            [11] 4300 	push	de
   62DC AF            [ 4] 4301 	xor	a, a
   62DD F5            [11] 4302 	push	af
   62DE 33            [ 6] 4303 	inc	sp
   62DF C5            [11] 4304 	push	bc
   62E0 CD A1 55      [17] 4305 	call	_PrintExplosion
   62E3 F1            [10] 4306 	pop	af
   62E4 33            [ 6] 4307 	inc	sp
   62E5 D1            [10] 4308 	pop	de
   62E6 18 31         [12] 4309 	jr	00114$
   62E8                    4310 00110$:
                           4311 ;src/main.c:1307: else if (pSpr->touched > 6) PrintExplosion(pSpr, 1);
   62E8 3E 06         [ 7] 4312 	ld	a, #0x06
   62EA 95            [ 4] 4313 	sub	a, l
   62EB 30 0E         [12] 4314 	jr	NC,00107$
   62ED D5            [11] 4315 	push	de
   62EE 3E 01         [ 7] 4316 	ld	a, #0x01
   62F0 F5            [11] 4317 	push	af
   62F1 33            [ 6] 4318 	inc	sp
   62F2 C5            [11] 4319 	push	bc
   62F3 CD A1 55      [17] 4320 	call	_PrintExplosion
   62F6 F1            [10] 4321 	pop	af
   62F7 33            [ 6] 4322 	inc	sp
   62F8 D1            [10] 4323 	pop	de
   62F9 18 1E         [12] 4324 	jr	00114$
   62FB                    4325 00107$:
                           4326 ;src/main.c:1308: else if (pSpr->touched > 4) PrintExplosion(pSpr, 0);
   62FB 3E 04         [ 7] 4327 	ld	a, #0x04
   62FD 95            [ 4] 4328 	sub	a, l
   62FE 30 0D         [12] 4329 	jr	NC,00104$
   6300 D5            [11] 4330 	push	de
   6301 AF            [ 4] 4331 	xor	a, a
   6302 F5            [11] 4332 	push	af
   6303 33            [ 6] 4333 	inc	sp
   6304 C5            [11] 4334 	push	bc
   6305 CD A1 55      [17] 4335 	call	_PrintExplosion
   6308 F1            [10] 4336 	pop	af
   6309 33            [ 6] 4337 	inc	sp
   630A D1            [10] 4338 	pop	de
   630B 18 0C         [12] 4339 	jr	00114$
   630D                    4340 00104$:
                           4341 ;src/main.c:1309: else if (pSpr->touched > 2) DeleteSprite(pSpr); 
   630D 3E 02         [ 7] 4342 	ld	a, #0x02
   630F 95            [ 4] 4343 	sub	a, l
   6310 30 07         [12] 4344 	jr	NC,00114$
   6312 D5            [11] 4345 	push	de
   6313 69            [ 4] 4346 	ld	l, c
   6314 60            [ 4] 4347 	ld	h, b
   6315 CD 42 55      [17] 4348 	call	_DeleteSprite
   6318 D1            [10] 4349 	pop	de
   6319                    4350 00114$:
                           4351 ;src/main.c:1310: pSpr->touched--;
   6319 1A            [ 7] 4352 	ld	a, (de)
   631A C6 FF         [ 7] 4353 	add	a, #0xff
   631C 12            [ 7] 4354 	ld	(de), a
   631D C9            [10] 4355 	ret
                           4356 ;src/main.c:1315: void EnemyLoop(TSpr *pSpr) __z88dk_fastcall {
                           4357 ;	---------------------------------
                           4358 ; Function EnemyLoop
                           4359 ; ---------------------------------
   631E                    4360 _EnemyLoop::
   631E DD E5         [15] 4361 	push	ix
   6320 DD 21 00 00   [14] 4362 	ld	ix,#0
   6324 DD 39         [15] 4363 	add	ix,sp
   6326 F5            [11] 4364 	push	af
   6327 4D            [ 4] 4365 	ld	c, l
   6328 44            [ 4] 4366 	ld	b, h
                           4367 ;src/main.c:1316: if (pSpr->lives >= 1) // If the enemy sprite is alive
   6329 C5            [11] 4368 	push	bc
   632A FD E1         [14] 4369 	pop	iy
   632C FD 56 09      [19] 4370 	ld	d, 9 (iy)
                           4371 ;src/main.c:1319: if (pSpr->touched == 0) 
   632F 21 0A 00      [10] 4372 	ld	hl, #0x000a
   6332 09            [11] 4373 	add	hl,bc
   6333 E3            [19] 4374 	ex	(sp), hl
   6334 E1            [10] 4375 	pop	hl
   6335 E5            [11] 4376 	push	hl
   6336 5E            [ 7] 4377 	ld	e, (hl)
                           4378 ;src/main.c:1316: if (pSpr->lives >= 1) // If the enemy sprite is alive
   6337 7A            [ 4] 4379 	ld	a, d
   6338 D6 01         [ 7] 4380 	sub	a, #0x01
   633A 38 4B         [12] 4381 	jr	C,00111$
                           4382 ;src/main.c:1319: if (pSpr->touched == 0) 
   633C 7B            [ 4] 4383 	ld	a, e
   633D B7            [ 4] 4384 	or	a, a
   633E 20 07         [12] 4385 	jr	NZ,00102$
                           4386 ;src/main.c:1320: MoveEnemy(pSpr);
   6340 C5            [11] 4387 	push	bc
   6341 C5            [11] 4388 	push	bc
   6342 CD 85 5E      [17] 4389 	call	_MoveEnemy
   6345 F1            [10] 4390 	pop	af
   6346 C1            [10] 4391 	pop	bc
   6347                    4392 00102$:
                           4393 ;src/main.c:1322: SelectSpriteFrame(pSpr); 
   6347 C5            [11] 4394 	push	bc
   6348 69            [ 4] 4395 	ld	l, c
   6349 60            [ 4] 4396 	ld	h, b
   634A CD DF 55      [17] 4397 	call	_SelectSpriteFrame
   634D C1            [10] 4398 	pop	bc
                           4399 ;src/main.c:1323: EnemyWalkAnim(pSpr);
   634E C5            [11] 4400 	push	bc
   634F 69            [ 4] 4401 	ld	l, c
   6350 60            [ 4] 4402 	ld	h, b
   6351 CD 58 56      [17] 4403 	call	_EnemyWalkAnim
   6354 C1            [10] 4404 	pop	bc
                           4405 ;src/main.c:1325: DeleteSprite(pSpr);
   6355 C5            [11] 4406 	push	bc
   6356 69            [ 4] 4407 	ld	l, c
   6357 60            [ 4] 4408 	ld	h, b
   6358 CD 42 55      [17] 4409 	call	_DeleteSprite
   635B C1            [10] 4410 	pop	bc
                           4411 ;src/main.c:1326: pSpr->px = pSpr->x; // save the current X coordinate
   635C 59            [ 4] 4412 	ld	e, c
   635D 50            [ 4] 4413 	ld	d, b
   635E 13            [ 6] 4414 	inc	de
   635F 13            [ 6] 4415 	inc	de
   6360 0A            [ 7] 4416 	ld	a, (bc)
   6361 12            [ 7] 4417 	ld	(de), a
                           4418 ;src/main.c:1327: pSpr->py = pSpr->y; // save the current Y coordinate
   6362 59            [ 4] 4419 	ld	e, c
   6363 50            [ 4] 4420 	ld	d, b
   6364 13            [ 6] 4421 	inc	de
   6365 13            [ 6] 4422 	inc	de
   6366 13            [ 6] 4423 	inc	de
   6367 69            [ 4] 4424 	ld	l, c
   6368 60            [ 4] 4425 	ld	h, b
   6369 23            [ 6] 4426 	inc	hl
   636A 7E            [ 7] 4427 	ld	a, (hl)
   636B 12            [ 7] 4428 	ld	(de), a
                           4429 ;src/main.c:1328: PrintSprite(pSpr);
   636C C5            [11] 4430 	push	bc
   636D 69            [ 4] 4431 	ld	l, c
   636E 60            [ 4] 4432 	ld	h, b
   636F CD 18 55      [17] 4433 	call	_PrintSprite
   6372 C1            [10] 4434 	pop	bc
                           4435 ;src/main.c:1330: CheckEnemyCollision(pSpr);
   6373 C5            [11] 4436 	push	bc
   6374 C5            [11] 4437 	push	bc
   6375 CD 64 56      [17] 4438 	call	_CheckEnemyCollision
   6378 F1            [10] 4439 	pop	af
   6379 C1            [10] 4440 	pop	bc
                           4441 ;src/main.c:1332: if (pSpr->touched > 0) 
   637A E1            [10] 4442 	pop	hl
   637B E5            [11] 4443 	push	hl
   637C 7E            [ 7] 4444 	ld	a, (hl)
   637D B7            [ 4] 4445 	or	a, a
   637E 28 22         [12] 4446 	jr	Z,00113$
                           4447 ;src/main.c:1333: ExplosionSecuence(pSpr);
   6380 69            [ 4] 4448 	ld	l, c
   6381 60            [ 4] 4449 	ld	h, b
   6382 CD C0 62      [17] 4450 	call	_ExplosionSecuence
   6385 18 1B         [12] 4451 	jr	00113$
   6387                    4452 00111$:
                           4453 ;src/main.c:1335: else if (pSpr->touched > 0) // enemy reached in his last life, will explode
   6387 7B            [ 4] 4454 	ld	a, e
   6388 B7            [ 4] 4455 	or	a, a
   6389 28 07         [12] 4456 	jr	Z,00108$
                           4457 ;src/main.c:1337: ExplosionSecuence(pSpr);
   638B 69            [ 4] 4458 	ld	l, c
   638C 60            [ 4] 4459 	ld	h, b
   638D CD C0 62      [17] 4460 	call	_ExplosionSecuence
   6390 18 10         [12] 4461 	jr	00113$
   6392                    4462 00108$:
                           4463 ;src/main.c:1339: else if (pSpr->status == S_touched) // at this point it has died and exploded
   6392 21 04 00      [10] 4464 	ld	hl, #0x0004
   6395 09            [11] 4465 	add	hl, bc
   6396 7E            [ 7] 4466 	ld	a, (hl)
   6397 D6 08         [ 7] 4467 	sub	a, #0x08
   6399 20 07         [12] 4468 	jr	NZ,00113$
                           4469 ;src/main.c:1341: pSpr->status = S_walking;		
   639B 36 01         [10] 4470 	ld	(hl), #0x01
                           4471 ;src/main.c:1342: DeleteSprite(pSpr); 
   639D 69            [ 4] 4472 	ld	l, c
   639E 60            [ 4] 4473 	ld	h, b
   639F CD 42 55      [17] 4474 	call	_DeleteSprite
   63A2                    4475 00113$:
   63A2 DD F9         [10] 4476 	ld	sp, ix
   63A4 DD E1         [14] 4477 	pop	ix
   63A6 C9            [10] 4478 	ret
                           4479 ;src/main.c:1351: void ExplodeEnemies()
                           4480 ;	---------------------------------
                           4481 ; Function ExplodeEnemies
                           4482 ; ---------------------------------
   63A7                    4483 _ExplodeEnemies::
                           4484 ;src/main.c:1353: for (ct = 1; ct < 4; ct++)
   63A7 21 B2 4B      [10] 4485 	ld	hl,#_ct + 0
   63AA 36 01         [10] 4486 	ld	(hl), #0x01
   63AC 01 C3 4B      [10] 4487 	ld	bc, #_spr+0
   63AF                    4488 00104$:
                           4489 ;src/main.c:1354: if (spr[ct].lives > 0)
   63AF ED 5B B2 4B   [20] 4490 	ld	de, (_ct)
   63B3 16 00         [ 7] 4491 	ld	d, #0x00
   63B5 6B            [ 4] 4492 	ld	l, e
   63B6 62            [ 4] 4493 	ld	h, d
   63B7 29            [11] 4494 	add	hl, hl
   63B8 29            [11] 4495 	add	hl, hl
   63B9 29            [11] 4496 	add	hl, hl
   63BA 19            [11] 4497 	add	hl, de
   63BB 29            [11] 4498 	add	hl, hl
   63BC 19            [11] 4499 	add	hl, de
   63BD 09            [11] 4500 	add	hl, bc
   63BE 11 09 00      [10] 4501 	ld	de, #0x0009
   63C1 19            [11] 4502 	add	hl, de
   63C2 7E            [ 7] 4503 	ld	a, (hl)
   63C3 B7            [ 4] 4504 	or	a, a
   63C4 CA 7F 64      [10] 4505 	jp	Z, 00105$
                           4506 ;src/main.c:1356: cpct_akp_SFXPlay (4, 15, 40, 0, 0, AY_CHANNEL_A); // explosion
   63C7 C5            [11] 4507 	push	bc
   63C8 3E 01         [ 7] 4508 	ld	a, #0x01
   63CA F5            [11] 4509 	push	af
   63CB 33            [ 6] 4510 	inc	sp
   63CC 21 00 00      [10] 4511 	ld	hl, #0x0000
   63CF E5            [11] 4512 	push	hl
   63D0 2E 28         [ 7] 4513 	ld	l, #0x28
   63D2 E5            [11] 4514 	push	hl
   63D3 21 04 0F      [10] 4515 	ld	hl, #0x0f04
   63D6 E5            [11] 4516 	push	hl
   63D7 CD 5F 46      [17] 4517 	call	_cpct_akp_SFXPlay
   63DA 21 07 00      [10] 4518 	ld	hl, #7
   63DD 39            [11] 4519 	add	hl, sp
   63DE F9            [ 6] 4520 	ld	sp, hl
   63DF C1            [10] 4521 	pop	bc
                           4522 ;src/main.c:1357: PrintExplosion(&spr[ct], 0); Pause(20);
   63E0 ED 5B B2 4B   [20] 4523 	ld	de, (_ct)
   63E4 16 00         [ 7] 4524 	ld	d, #0x00
   63E6 6B            [ 4] 4525 	ld	l, e
   63E7 62            [ 4] 4526 	ld	h, d
   63E8 29            [11] 4527 	add	hl, hl
   63E9 29            [11] 4528 	add	hl, hl
   63EA 29            [11] 4529 	add	hl, hl
   63EB 19            [11] 4530 	add	hl, de
   63EC 29            [11] 4531 	add	hl, hl
   63ED 19            [11] 4532 	add	hl, de
   63EE 09            [11] 4533 	add	hl, bc
   63EF C5            [11] 4534 	push	bc
   63F0 AF            [ 4] 4535 	xor	a, a
   63F1 F5            [11] 4536 	push	af
   63F2 33            [ 6] 4537 	inc	sp
   63F3 E5            [11] 4538 	push	hl
   63F4 CD A1 55      [17] 4539 	call	_PrintExplosion
   63F7 F1            [10] 4540 	pop	af
   63F8 33            [ 6] 4541 	inc	sp
   63F9 21 14 00      [10] 4542 	ld	hl, #0x0014
   63FC CD 25 4E      [17] 4543 	call	_Pause
   63FF C1            [10] 4544 	pop	bc
                           4545 ;src/main.c:1358: PrintExplosion(&spr[ct], 1); Pause(20);
   6400 ED 5B B2 4B   [20] 4546 	ld	de, (_ct)
   6404 16 00         [ 7] 4547 	ld	d, #0x00
   6406 6B            [ 4] 4548 	ld	l, e
   6407 62            [ 4] 4549 	ld	h, d
   6408 29            [11] 4550 	add	hl, hl
   6409 29            [11] 4551 	add	hl, hl
   640A 29            [11] 4552 	add	hl, hl
   640B 19            [11] 4553 	add	hl, de
   640C 29            [11] 4554 	add	hl, hl
   640D 19            [11] 4555 	add	hl, de
   640E 09            [11] 4556 	add	hl, bc
   640F C5            [11] 4557 	push	bc
   6410 3E 01         [ 7] 4558 	ld	a, #0x01
   6412 F5            [11] 4559 	push	af
   6413 33            [ 6] 4560 	inc	sp
   6414 E5            [11] 4561 	push	hl
   6415 CD A1 55      [17] 4562 	call	_PrintExplosion
   6418 F1            [10] 4563 	pop	af
   6419 33            [ 6] 4564 	inc	sp
   641A 21 14 00      [10] 4565 	ld	hl, #0x0014
   641D CD 25 4E      [17] 4566 	call	_Pause
   6420 C1            [10] 4567 	pop	bc
                           4568 ;src/main.c:1359: PrintExplosion(&spr[ct], 0); Pause(20);
   6421 ED 5B B2 4B   [20] 4569 	ld	de, (_ct)
   6425 16 00         [ 7] 4570 	ld	d, #0x00
   6427 6B            [ 4] 4571 	ld	l, e
   6428 62            [ 4] 4572 	ld	h, d
   6429 29            [11] 4573 	add	hl, hl
   642A 29            [11] 4574 	add	hl, hl
   642B 29            [11] 4575 	add	hl, hl
   642C 19            [11] 4576 	add	hl, de
   642D 29            [11] 4577 	add	hl, hl
   642E 19            [11] 4578 	add	hl, de
   642F 09            [11] 4579 	add	hl, bc
   6430 C5            [11] 4580 	push	bc
   6431 AF            [ 4] 4581 	xor	a, a
   6432 F5            [11] 4582 	push	af
   6433 33            [ 6] 4583 	inc	sp
   6434 E5            [11] 4584 	push	hl
   6435 CD A1 55      [17] 4585 	call	_PrintExplosion
   6438 F1            [10] 4586 	pop	af
   6439 33            [ 6] 4587 	inc	sp
   643A 21 14 00      [10] 4588 	ld	hl, #0x0014
   643D CD 25 4E      [17] 4589 	call	_Pause
   6440 C1            [10] 4590 	pop	bc
                           4591 ;src/main.c:1360: spr[ct].lives = 0;
   6441 ED 5B B2 4B   [20] 4592 	ld	de, (_ct)
   6445 16 00         [ 7] 4593 	ld	d, #0x00
   6447 6B            [ 4] 4594 	ld	l, e
   6448 62            [ 4] 4595 	ld	h, d
   6449 29            [11] 4596 	add	hl, hl
   644A 29            [11] 4597 	add	hl, hl
   644B 29            [11] 4598 	add	hl, hl
   644C 19            [11] 4599 	add	hl, de
   644D 29            [11] 4600 	add	hl, hl
   644E 19            [11] 4601 	add	hl, de
   644F 09            [11] 4602 	add	hl, bc
   6450 11 09 00      [10] 4603 	ld	de, #0x0009
   6453 19            [11] 4604 	add	hl, de
   6454 36 00         [10] 4605 	ld	(hl), #0x00
                           4606 ;src/main.c:1361: spr[ct].status = S_walking;
   6456 ED 5B B2 4B   [20] 4607 	ld	de, (_ct)
   645A 16 00         [ 7] 4608 	ld	d, #0x00
   645C 6B            [ 4] 4609 	ld	l, e
   645D 62            [ 4] 4610 	ld	h, d
   645E 29            [11] 4611 	add	hl, hl
   645F 29            [11] 4612 	add	hl, hl
   6460 29            [11] 4613 	add	hl, hl
   6461 19            [11] 4614 	add	hl, de
   6462 29            [11] 4615 	add	hl, hl
   6463 19            [11] 4616 	add	hl, de
   6464 09            [11] 4617 	add	hl, bc
   6465 11 04 00      [10] 4618 	ld	de, #0x0004
   6468 19            [11] 4619 	add	hl, de
   6469 36 01         [10] 4620 	ld	(hl), #0x01
                           4621 ;src/main.c:1362: DeleteSprite(&spr[ct]);
   646B ED 5B B2 4B   [20] 4622 	ld	de, (_ct)
   646F 16 00         [ 7] 4623 	ld	d, #0x00
   6471 6B            [ 4] 4624 	ld	l, e
   6472 62            [ 4] 4625 	ld	h, d
   6473 29            [11] 4626 	add	hl, hl
   6474 29            [11] 4627 	add	hl, hl
   6475 29            [11] 4628 	add	hl, hl
   6476 19            [11] 4629 	add	hl, de
   6477 29            [11] 4630 	add	hl, hl
   6478 19            [11] 4631 	add	hl, de
   6479 09            [11] 4632 	add	hl, bc
   647A C5            [11] 4633 	push	bc
   647B CD 42 55      [17] 4634 	call	_DeleteSprite
   647E C1            [10] 4635 	pop	bc
   647F                    4636 00105$:
                           4637 ;src/main.c:1353: for (ct = 1; ct < 4; ct++)
   647F FD 21 B2 4B   [14] 4638 	ld	iy, #_ct
   6483 FD 34 00      [23] 4639 	inc	0 (iy)
   6486 FD 7E 00      [19] 4640 	ld	a, 0 (iy)
   6489 D6 04         [ 7] 4641 	sub	a, #0x04
   648B DA AF 63      [10] 4642 	jp	C, 00104$
   648E C9            [10] 4643 	ret
                           4644 ;src/main.c:1385: void SetLC() 
                           4645 ;	---------------------------------
                           4646 ; Function SetLC
                           4647 ; ---------------------------------
   648F                    4648 _SetLC::
                           4649 ;src/main.c:1387: if (shotLC.active == FALSE) // if there is no laser shot on screen ...
   648F 21 1A 4C      [10] 4650 	ld	hl, #_shotLC + 5
   6492 7E            [ 7] 4651 	ld	a, (hl)
   6493 B7            [ 4] 4652 	or	a, a
   6494 C0            [11] 4653 	ret	NZ
                           4654 ;src/main.c:1389: cpct_akp_SFXPlay(1, 15, 40, 0, 0, AY_CHANNEL_A);
   6495 E5            [11] 4655 	push	hl
   6496 3E 01         [ 7] 4656 	ld	a, #0x01
   6498 F5            [11] 4657 	push	af
   6499 33            [ 6] 4658 	inc	sp
   649A 01 00 00      [10] 4659 	ld	bc, #0x0000
   649D C5            [11] 4660 	push	bc
   649E 01 28 00      [10] 4661 	ld	bc, #0x0028
   64A1 C5            [11] 4662 	push	bc
   64A2 01 01 0F      [10] 4663 	ld	bc, #0x0f01
   64A5 C5            [11] 4664 	push	bc
   64A6 CD 5F 46      [17] 4665 	call	_cpct_akp_SFXPlay
   64A9 21 07 00      [10] 4666 	ld	hl, #7
   64AC 39            [11] 4667 	add	hl, sp
   64AD F9            [ 6] 4668 	ld	sp, hl
   64AE E1            [10] 4669 	pop	hl
                           4670 ;src/main.c:1390: shotLC.active = TRUE;
   64AF 36 01         [10] 4671 	ld	(hl), #0x01
                           4672 ;src/main.c:1392: shotLC.dir = lc[activeLC].dir;
   64B1 01 1C 4C      [10] 4673 	ld	bc, #_lc+0
   64B4 ED 5B 1B 4C   [20] 4674 	ld	de, (_activeLC)
   64B8 16 00         [ 7] 4675 	ld	d, #0x00
   64BA 6B            [ 4] 4676 	ld	l, e
   64BB 62            [ 4] 4677 	ld	h, d
   64BC 29            [11] 4678 	add	hl, hl
   64BD 29            [11] 4679 	add	hl, hl
   64BE 19            [11] 4680 	add	hl, de
   64BF 09            [11] 4681 	add	hl, bc
   64C0 11 04 00      [10] 4682 	ld	de, #0x0004
   64C3 19            [11] 4683 	add	hl, de
   64C4 5E            [ 7] 4684 	ld	e, (hl)
   64C5 21 18 4C      [10] 4685 	ld	hl, #(_shotLC + 0x0003)
   64C8 73            [ 7] 4686 	ld	(hl), e
                           4687 ;src/main.c:1394: shotLC.y = lc[activeLC].y + 4;
   64C9 D5            [11] 4688 	push	de
   64CA ED 5B 1B 4C   [20] 4689 	ld	de, (_activeLC)
   64CE 16 00         [ 7] 4690 	ld	d, #0x00
   64D0 6B            [ 4] 4691 	ld	l, e
   64D1 62            [ 4] 4692 	ld	h, d
   64D2 29            [11] 4693 	add	hl, hl
   64D3 29            [11] 4694 	add	hl, hl
   64D4 19            [11] 4695 	add	hl, de
   64D5 D1            [10] 4696 	pop	de
   64D6 09            [11] 4697 	add	hl, bc
   64D7 23            [ 6] 4698 	inc	hl
   64D8 7E            [ 7] 4699 	ld	a, (hl)
   64D9 C6 04         [ 7] 4700 	add	a, #0x04
   64DB 32 17 4C      [13] 4701 	ld	(#(_shotLC + 0x0002)),a
                           4702 ;src/main.c:1392: shotLC.dir = lc[activeLC].dir;
   64DE D5            [11] 4703 	push	de
   64DF ED 5B 1B 4C   [20] 4704 	ld	de, (_activeLC)
   64E3 16 00         [ 7] 4705 	ld	d, #0x00
   64E5 6B            [ 4] 4706 	ld	l, e
   64E6 62            [ 4] 4707 	ld	h, d
   64E7 29            [11] 4708 	add	hl, hl
   64E8 29            [11] 4709 	add	hl, hl
   64E9 19            [11] 4710 	add	hl, de
   64EA D1            [10] 4711 	pop	de
                           4712 ;src/main.c:1397: shotLC.x = shotLC.px = lc[activeLC].x + SPR_W;
   64EB 09            [11] 4713 	add	hl, bc
   64EC 4E            [ 7] 4714 	ld	c, (hl)
                           4715 ;src/main.c:1396: if (shotLC.dir == D_right)
   64ED 7B            [ 4] 4716 	ld	a, e
   64EE D6 03         [ 7] 4717 	sub	a, #0x03
   64F0 20 0A         [12] 4718 	jr	NZ,00102$
                           4719 ;src/main.c:1397: shotLC.x = shotLC.px = lc[activeLC].x + SPR_W;
   64F2 79            [ 4] 4720 	ld	a, c
   64F3 C6 08         [ 7] 4721 	add	a, #0x08
   64F5 32 16 4C      [13] 4722 	ld	(#(_shotLC + 0x0001)),a
   64F8 32 15 4C      [13] 4723 	ld	(#_shotLC),a
   64FB C9            [10] 4724 	ret
   64FC                    4725 00102$:
                           4726 ;src/main.c:1399: shotLC.x = shotLC.px = lc[activeLC].x - SPR_W;
   64FC 79            [ 4] 4727 	ld	a, c
   64FD C6 F8         [ 7] 4728 	add	a, #0xf8
   64FF 32 16 4C      [13] 4729 	ld	(#(_shotLC + 0x0001)),a
   6502 32 15 4C      [13] 4730 	ld	(#_shotLC),a
   6505 C9            [10] 4731 	ret
                           4732 ;src/main.c:1405: void GetLC() {
                           4733 ;	---------------------------------
                           4734 ; Function GetLC
                           4735 ; ---------------------------------
   6506                    4736 _GetLC::
                           4737 ;src/main.c:1406: ct = 0;
   6506 21 B2 4B      [10] 4738 	ld	hl,#_ct + 0
   6509 36 00         [10] 4739 	ld	(hl), #0x00
                           4740 ;src/main.c:1407: activeLC = 0;
   650B 21 1B 4C      [10] 4741 	ld	hl,#_activeLC + 0
   650E 36 00         [10] 4742 	ld	(hl), #0x00
                           4743 ;src/main.c:1409: while (ct < N_MAX_LC)	{
   6510 01 1C 4C      [10] 4744 	ld	bc, #_lc+0
   6513                    4745 00103$:
   6513 3A B2 4B      [13] 4746 	ld	a,(#_ct + 0)
   6516 D6 03         [ 7] 4747 	sub	a, #0x03
   6518 D0            [11] 4748 	ret	NC
                           4749 ;src/main.c:1410: if (lc[ct].mapNumber == mapNumber)	{
   6519 ED 5B B2 4B   [20] 4750 	ld	de, (_ct)
   651D 16 00         [ 7] 4751 	ld	d, #0x00
   651F 6B            [ 4] 4752 	ld	l, e
   6520 62            [ 4] 4753 	ld	h, d
   6521 29            [11] 4754 	add	hl, hl
   6522 29            [11] 4755 	add	hl, hl
   6523 19            [11] 4756 	add	hl, de
   6524 09            [11] 4757 	add	hl, bc
   6525 23            [ 6] 4758 	inc	hl
   6526 23            [ 6] 4759 	inc	hl
   6527 5E            [ 7] 4760 	ld	e, (hl)
   6528 3A 57 4C      [13] 4761 	ld	a,(#_mapNumber + 0)
   652B 93            [ 4] 4762 	sub	a, e
   652C 20 07         [12] 4763 	jr	NZ,00102$
                           4764 ;src/main.c:1411: activeLC = ct;
   652E 3A B2 4B      [13] 4765 	ld	a,(#_ct + 0)
   6531 32 1B 4C      [13] 4766 	ld	(#_activeLC + 0),a
                           4767 ;src/main.c:1412: break;
   6534 C9            [10] 4768 	ret
   6535                    4769 00102$:
                           4770 ;src/main.c:1414: ct++;
   6535 21 B2 4B      [10] 4771 	ld	hl, #_ct+0
   6538 34            [11] 4772 	inc	(hl)
   6539 18 D8         [12] 4773 	jr	00103$
                           4774 ;src/main.c:1431: void InitLC()
                           4775 ;	---------------------------------
                           4776 ; Function InitLC
                           4777 ; ---------------------------------
   653B                    4778 _InitLC::
                           4779 ;src/main.c:1422: lc[LCNum].x = x; 
   653B 21 1C 4C      [10] 4780 	ld	hl, #_lc
   653E 36 00         [10] 4781 	ld	(hl), #0x00
                           4782 ;src/main.c:1423: lc[LCNum].y = y;
   6540 21 1D 4C      [10] 4783 	ld	hl, #(_lc + 0x0001)
   6543 36 00         [10] 4784 	ld	(hl), #0x00
                           4785 ;src/main.c:1424: lc[LCNum].mapNumber = mapNum;
   6545 21 1E 4C      [10] 4786 	ld	hl, #(_lc + 0x0002)
   6548 36 FF         [10] 4787 	ld	(hl), #0xff
                           4788 ;src/main.c:1425: lc[LCNum].dir = dir;
   654A 21 20 4C      [10] 4789 	ld	hl, #(_lc + 0x0004)
   654D 36 03         [10] 4790 	ld	(hl), #0x03
                           4791 ;src/main.c:1422: lc[LCNum].x = x; 
   654F 21 21 4C      [10] 4792 	ld	hl, #(_lc + 0x0005)
   6552 36 0C         [10] 4793 	ld	(hl), #0x0c
                           4794 ;src/main.c:1423: lc[LCNum].y = y;
   6554 21 22 4C      [10] 4795 	ld	hl, #(_lc + 0x0006)
   6557 36 80         [10] 4796 	ld	(hl), #0x80
                           4797 ;src/main.c:1424: lc[LCNum].mapNumber = mapNum;
   6559 21 23 4C      [10] 4798 	ld	hl, #(_lc + 0x0007)
   655C 36 00         [10] 4799 	ld	(hl), #0x00
                           4800 ;src/main.c:1425: lc[LCNum].dir = dir;
   655E 21 25 4C      [10] 4801 	ld	hl, #(_lc + 0x0009)
   6561 36 03         [10] 4802 	ld	(hl), #0x03
                           4803 ;src/main.c:1422: lc[LCNum].x = x; 
   6563 21 26 4C      [10] 4804 	ld	hl, #(_lc + 0x000a)
   6566 36 36         [10] 4805 	ld	(hl), #0x36
                           4806 ;src/main.c:1423: lc[LCNum].y = y;
   6568 21 27 4C      [10] 4807 	ld	hl, #(_lc + 0x000b)
   656B 36 3C         [10] 4808 	ld	(hl), #0x3c
                           4809 ;src/main.c:1424: lc[LCNum].mapNumber = mapNum;
   656D 21 28 4C      [10] 4810 	ld	hl, #(_lc + 0x000c)
   6570 36 01         [10] 4811 	ld	(hl), #0x01
                           4812 ;src/main.c:1425: lc[LCNum].dir = dir;
   6572 21 2A 4C      [10] 4813 	ld	hl, #(_lc + 0x000e)
   6575 36 02         [10] 4814 	ld	(hl), #0x02
                           4815 ;src/main.c:1436: SetParamLC(2, 54,  60,   1, D_left);
   6577 C9            [10] 4816 	ret
                           4817 ;src/main.c:1441: void CheckLCCollisions()
                           4818 ;	---------------------------------
                           4819 ; Function CheckLCCollisions
                           4820 ; ---------------------------------
   6578                    4821 _CheckLCCollisions::
   6578 DD E5         [15] 4822 	push	ix
   657A DD 21 00 00   [14] 4823 	ld	ix,#0
   657E DD 39         [15] 4824 	add	ix,sp
   6580 F5            [11] 4825 	push	af
                           4826 ;src/main.c:1443: if ((shotLC.x + SPR_W) > (spr[0].x + 4) && shotLC.x < (spr[0].x + SPR_W))
   6581 21 15 4C      [10] 4827 	ld	hl, #_shotLC+0
   6584 4E            [ 7] 4828 	ld	c, (hl)
   6585 06 00         [ 7] 4829 	ld	b, #0x00
   6587 21 08 00      [10] 4830 	ld	hl, #0x0008
   658A 09            [11] 4831 	add	hl,bc
   658B E3            [19] 4832 	ex	(sp), hl
   658C 21 C3 4B      [10] 4833 	ld	hl, #_spr+0
   658F 5E            [ 7] 4834 	ld	e, (hl)
   6590 16 00         [ 7] 4835 	ld	d, #0x00
   6592 21 04 00      [10] 4836 	ld	hl, #0x0004
   6595 19            [11] 4837 	add	hl, de
   6596 7D            [ 4] 4838 	ld	a, l
   6597 DD 96 FE      [19] 4839 	sub	a, -2 (ix)
   659A 7C            [ 4] 4840 	ld	a, h
   659B DD 9E FF      [19] 4841 	sbc	a, -1 (ix)
   659E E2 A3 65      [10] 4842 	jp	PO, 00125$
   65A1 EE 80         [ 7] 4843 	xor	a, #0x80
   65A3                    4844 00125$:
   65A3 F2 FF 65      [10] 4845 	jp	P, 00107$
   65A6 21 08 00      [10] 4846 	ld	hl, #0x0008
   65A9 19            [11] 4847 	add	hl, de
   65AA 79            [ 4] 4848 	ld	a, c
   65AB 95            [ 4] 4849 	sub	a, l
   65AC 78            [ 4] 4850 	ld	a, b
   65AD 9C            [ 4] 4851 	sbc	a, h
   65AE E2 B3 65      [10] 4852 	jp	PO, 00126$
   65B1 EE 80         [ 7] 4853 	xor	a, #0x80
   65B3                    4854 00126$:
   65B3 F2 FF 65      [10] 4855 	jp	P, 00107$
                           4856 ;src/main.c:1444: if ((shotLC.y + SPR_H) > (spr[0].y - 1) && (shotLC.y - 1) < (spr[0].y + SPR_H))
   65B6 21 17 4C      [10] 4857 	ld	hl, #_shotLC + 2
   65B9 4E            [ 7] 4858 	ld	c, (hl)
   65BA 06 00         [ 7] 4859 	ld	b, #0x00
   65BC 21 10 00      [10] 4860 	ld	hl, #0x0010
   65BF 09            [11] 4861 	add	hl,bc
   65C0 E3            [19] 4862 	ex	(sp), hl
   65C1 21 C4 4B      [10] 4863 	ld	hl, #_spr + 1
   65C4 5E            [ 7] 4864 	ld	e, (hl)
   65C5 16 00         [ 7] 4865 	ld	d, #0x00
   65C7 6B            [ 4] 4866 	ld	l, e
   65C8 62            [ 4] 4867 	ld	h, d
   65C9 2B            [ 6] 4868 	dec	hl
   65CA 7D            [ 4] 4869 	ld	a, l
   65CB DD 96 FE      [19] 4870 	sub	a, -2 (ix)
   65CE 7C            [ 4] 4871 	ld	a, h
   65CF DD 9E FF      [19] 4872 	sbc	a, -1 (ix)
   65D2 E2 D7 65      [10] 4873 	jp	PO, 00127$
   65D5 EE 80         [ 7] 4874 	xor	a, #0x80
   65D7                    4875 00127$:
   65D7 F2 FF 65      [10] 4876 	jp	P, 00107$
   65DA 0B            [ 6] 4877 	dec	bc
   65DB 21 10 00      [10] 4878 	ld	hl, #0x0010
   65DE 19            [11] 4879 	add	hl, de
   65DF 79            [ 4] 4880 	ld	a, c
   65E0 95            [ 4] 4881 	sub	a, l
   65E1 78            [ 4] 4882 	ld	a, b
   65E2 9C            [ 4] 4883 	sbc	a, h
   65E3 E2 E8 65      [10] 4884 	jp	PO, 00128$
   65E6 EE 80         [ 7] 4885 	xor	a, #0x80
   65E8                    4886 00128$:
   65E8 F2 FF 65      [10] 4887 	jp	P, 00107$
                           4888 ;src/main.c:1447: shotLC.active = FALSE;
   65EB 21 1A 4C      [10] 4889 	ld	hl, #(_shotLC + 0x0005)
   65EE 36 00         [10] 4890 	ld	(hl), #0x00
                           4891 ;src/main.c:1448: spr[0].lives--;
   65F0 21 CC 4B      [10] 4892 	ld	hl, #_spr + 9
   65F3 4E            [ 7] 4893 	ld	c, (hl)
   65F4 0D            [ 4] 4894 	dec	c
   65F5 71            [ 7] 4895 	ld	(hl), c
                           4896 ;src/main.c:1449: ExplodePlayer();
   65F6 CD 37 5D      [17] 4897 	call	_ExplodePlayer
                           4898 ;src/main.c:1450: ExplodeEnemies();
   65F9 CD A7 63      [17] 4899 	call	_ExplodeEnemies
                           4900 ;src/main.c:1451: GameOver();
   65FC CD 4E 68      [17] 4901 	call	_GameOver
   65FF                    4902 00107$:
   65FF DD F9         [10] 4903 	ld	sp, ix
   6601 DD E1         [14] 4904 	pop	ix
   6603 C9            [10] 4905 	ret
                           4906 ;src/main.c:1472: void PrintStartMenu() {
                           4907 ;	---------------------------------
                           4908 ; Function PrintStartMenu
                           4909 ; ---------------------------------
   6604                    4910 _PrintStartMenu::
                           4911 ;src/main.c:1473: cpct_drawSprite(g_logo, cpctm_screenPtr(CPCT_VMEM_START, 17, 0), G_LOGO_W, G_LOGO_H);
   6604 21 2E 16      [10] 4912 	ld	hl, #0x162e
   6607 E5            [11] 4913 	push	hl
   6608 21 11 C0      [10] 4914 	ld	hl, #0xc011
   660B E5            [11] 4915 	push	hl
   660C 21 21 16      [10] 4916 	ld	hl, #_g_logo
   660F E5            [11] 4917 	push	hl
   6610 CD DC 46      [17] 4918 	call	_cpct_drawSprite
                           4919 ;src/main.c:1475: PrintText("1@START@GAME", 2, 45);
   6613 21 02 2D      [10] 4920 	ld	hl, #0x2d02
   6616 E5            [11] 4921 	push	hl
   6617 21 5D 66      [10] 4922 	ld	hl, #___str_4
   661A E5            [11] 4923 	push	hl
   661B CD 01 4F      [17] 4924 	call	_PrintText
   661E F1            [10] 4925 	pop	af
                           4926 ;src/main.c:1476: PrintText("2@REDEFINE@CONTROLS", 2, 60);
   661F 21 02 3C      [10] 4927 	ld	hl, #0x3c02
   6622 E3            [19] 4928 	ex	(sp),hl
   6623 21 6A 66      [10] 4929 	ld	hl, #___str_5
   6626 E5            [11] 4930 	push	hl
   6627 CD 01 4F      [17] 4931 	call	_PrintText
   662A F1            [10] 4932 	pop	af
                           4933 ;src/main.c:1478: PrintText("SALVAKANTERO", 16,140);
   662B 21 10 8C      [10] 4934 	ld	hl, #0x8c10
   662E E3            [19] 4935 	ex	(sp),hl
   662F 21 7E 66      [10] 4936 	ld	hl, #___str_6
   6632 E5            [11] 4937 	push	hl
   6633 CD 01 4F      [17] 4938 	call	_PrintText
   6636 F1            [10] 4939 	pop	af
                           4940 ;src/main.c:1479: PrintText("FELIPE@VAKAPP", 14, 155);
   6637 21 0E 9B      [10] 4941 	ld	hl, #0x9b0e
   663A E3            [19] 4942 	ex	(sp),hl
   663B 21 8B 66      [10] 4943 	ld	hl, #___str_7
   663E E5            [11] 4944 	push	hl
   663F CD 01 4F      [17] 4945 	call	_PrintText
   6642 F1            [10] 4946 	pop	af
                           4947 ;src/main.c:1480: PrintText("TACHA", 29,170);
   6643 21 1D AA      [10] 4948 	ld	hl, #0xaa1d
   6646 E3            [19] 4949 	ex	(sp),hl
   6647 21 99 66      [10] 4950 	ld	hl, #___str_8
   664A E5            [11] 4951 	push	hl
   664B CD 01 4F      [17] 4952 	call	_PrintText
   664E F1            [10] 4953 	pop	af
                           4954 ;src/main.c:1482: PrintText("PLAY@ON@RETRO@2022", 4, 191);
   664F 21 04 BF      [10] 4955 	ld	hl, #0xbf04
   6652 E3            [19] 4956 	ex	(sp),hl
   6653 21 9F 66      [10] 4957 	ld	hl, #___str_9
   6656 E5            [11] 4958 	push	hl
   6657 CD 01 4F      [17] 4959 	call	_PrintText
   665A F1            [10] 4960 	pop	af
   665B F1            [10] 4961 	pop	af
   665C C9            [10] 4962 	ret
   665D                    4963 ___str_4:
   665D 31 40 53 54 41 52  4964 	.ascii "1@START@GAME"
        54 40 47 41 4D 45
   6669 00                 4965 	.db 0x00
   666A                    4966 ___str_5:
   666A 32 40 52 45 44 45  4967 	.ascii "2@REDEFINE@CONTROLS"
        46 49 4E 45 40 43
        4F 4E 54 52 4F 4C
        53
   667D 00                 4968 	.db 0x00
   667E                    4969 ___str_6:
   667E 53 41 4C 56 41 4B  4970 	.ascii "SALVAKANTERO"
        41 4E 54 45 52 4F
   668A 00                 4971 	.db 0x00
   668B                    4972 ___str_7:
   668B 46 45 4C 49 50 45  4973 	.ascii "FELIPE@VAKAPP"
        40 56 41 4B 41 50
        50
   6698 00                 4974 	.db 0x00
   6699                    4975 ___str_8:
   6699 54 41 43 48 41     4976 	.ascii "TACHA"
   669E 00                 4977 	.db 0x00
   669F                    4978 ___str_9:
   669F 50 4C 41 59 40 4F  4979 	.ascii "PLAY@ON@RETRO@2022"
        4E 40 52 45 54 52
        4F 40 32 30 32 32
   66B1 00                 4980 	.db 0x00
                           4981 ;src/main.c:1486: void StartMenu() {
                           4982 ;	---------------------------------
                           4983 ; Function StartMenu
                           4984 ; ---------------------------------
   66B2                    4985 _StartMenu::
                           4986 ;src/main.c:1487: cpct_akp_musicInit(Menu); // initialize music. Main theme 
   66B2 21 FA 02      [10] 4987 	ld	hl, #_Menu
   66B5 E5            [11] 4988 	push	hl
   66B6 CD B8 45      [17] 4989 	call	_cpct_akp_musicInit
   66B9 F1            [10] 4990 	pop	af
                           4991 ;src/main.c:1488: ClearScreen();
   66BA CD 5A 4E      [17] 4992 	call	_ClearScreen
                           4993 ;src/main.c:1489: PrintStartMenu();
   66BD CD 04 66      [17] 4994 	call	_PrintStartMenu
                           4995 ;src/main.c:1491: while(1) {
   66C0                    4996 00107$:
                           4997 ;src/main.c:1492: cpct_scanKeyboard_f();
   66C0 CD 3D 3E      [17] 4998 	call	_cpct_scanKeyboard_f
                           4999 ;src/main.c:1494: if(cpct_isKeyPressed(Key_1)) { // start game
   66C3 21 08 01      [10] 5000 	ld	hl, #0x0108
   66C6 CD 31 3E      [17] 5001 	call	_cpct_isKeyPressed
   66C9 7D            [ 4] 5002 	ld	a, l
   66CA B7            [ 4] 5003 	or	a, a
   66CB 20 6D         [12] 5004 	jr	NZ,00108$
                           5005 ;src/main.c:1497: else if(cpct_isKeyPressed(Key_2)){ // redefine keys
   66CD 21 08 02      [10] 5006 	ld	hl, #0x0208
   66D0 CD 31 3E      [17] 5007 	call	_cpct_isKeyPressed
   66D3 7D            [ 4] 5008 	ld	a, l
   66D4 B7            [ 4] 5009 	or	a, a
   66D5 28 5B         [12] 5010 	jr	Z,00105$
                           5011 ;src/main.c:1498: Wait4Key(Key_2);
   66D7 21 08 02      [10] 5012 	ld	hl, #0x0208
   66DA CD 9C 51      [17] 5013 	call	_Wait4Key
                           5014 ;src/main.c:1499: ctlUp = 	RedefineKey("@@UP@");
   66DD 21 77 67      [10] 5015 	ld	hl, #___str_10
   66E0 CD B9 51      [17] 5016 	call	_RedefineKey
   66E3 22 B3 4B      [16] 5017 	ld	(_ctlUp), hl
                           5018 ;src/main.c:1500: ctlDown = 	RedefineKey("@DOWN");
   66E6 21 7D 67      [10] 5019 	ld	hl, #___str_11
   66E9 CD B9 51      [17] 5020 	call	_RedefineKey
   66EC 22 B5 4B      [16] 5021 	ld	(_ctlDown), hl
                           5022 ;src/main.c:1501: ctlLeft = 	RedefineKey("@LEFT");
   66EF 21 83 67      [10] 5023 	ld	hl, #___str_12
   66F2 CD B9 51      [17] 5024 	call	_RedefineKey
   66F5 22 B7 4B      [16] 5025 	ld	(_ctlLeft), hl
                           5026 ;src/main.c:1502: ctlRight = 	RedefineKey("RIGHT");
   66F8 21 89 67      [10] 5027 	ld	hl, #___str_13
   66FB CD B9 51      [17] 5028 	call	_RedefineKey
   66FE 22 B9 4B      [16] 5029 	ld	(_ctlRight), hl
                           5030 ;src/main.c:1503: ctlFire = 	RedefineKey("@FIRE");
   6701 21 8F 67      [10] 5031 	ld	hl, #___str_14
   6704 CD B9 51      [17] 5032 	call	_RedefineKey
   6707 22 BB 4B      [16] 5033 	ld	(_ctlFire), hl
                           5034 ;src/main.c:1504: ctlAbort = 	RedefineKey("ABORT");
   670A 21 95 67      [10] 5035 	ld	hl, #___str_15
   670D CD B9 51      [17] 5036 	call	_RedefineKey
   6710 22 BF 4B      [16] 5037 	ld	(_ctlAbort), hl
                           5038 ;src/main.c:1505: ctlMusic = 	RedefineKey("MUSIC");
   6713 21 9B 67      [10] 5039 	ld	hl, #___str_16
   6716 CD B9 51      [17] 5040 	call	_RedefineKey
   6719 22 BD 4B      [16] 5041 	ld	(_ctlMusic), hl
                           5042 ;src/main.c:1506: ctlPause =	RedefineKey("PAUSE");		
   671C 21 A1 67      [10] 5043 	ld	hl, #___str_17
   671F CD B9 51      [17] 5044 	call	_RedefineKey
   6722 22 C1 4B      [16] 5045 	ld	(_ctlPause), hl
                           5046 ;src/main.c:1508: PrintText("@@@@@", 29, 100);
   6725 21 1D 64      [10] 5047 	ld	hl, #0x641d
   6728 E5            [11] 5048 	push	hl
   6729 21 A7 67      [10] 5049 	ld	hl, #___str_18
   672C E5            [11] 5050 	push	hl
   672D CD 01 4F      [17] 5051 	call	_PrintText
   6730 F1            [10] 5052 	pop	af
   6731 F1            [10] 5053 	pop	af
   6732                    5054 00105$:
                           5055 ;src/main.c:1510: Pause(3);
   6732 21 03 00      [10] 5056 	ld	hl, #0x0003
   6735 CD 25 4E      [17] 5057 	call	_Pause
   6738 18 86         [12] 5058 	jr	00107$
   673A                    5059 00108$:
                           5060 ;src/main.c:1513: cpct_akp_musicInit(FX);
   673A 21 00 02      [10] 5061 	ld	hl, #_FX
   673D E5            [11] 5062 	push	hl
   673E CD B8 45      [17] 5063 	call	_cpct_akp_musicInit
                           5064 ;src/main.c:1514: cpct_akp_SFXPlay (6, 14, 41, 0, 0, AY_CHANNEL_B); // event sound
   6741 26 02         [ 7] 5065 	ld	h,#0x02
   6743 E3            [19] 5066 	ex	(sp),hl
   6744 33            [ 6] 5067 	inc	sp
   6745 21 00 00      [10] 5068 	ld	hl, #0x0000
   6748 E5            [11] 5069 	push	hl
   6749 2E 29         [ 7] 5070 	ld	l, #0x29
   674B E5            [11] 5071 	push	hl
   674C 21 06 0E      [10] 5072 	ld	hl, #0x0e06
   674F E5            [11] 5073 	push	hl
   6750 CD 5F 46      [17] 5074 	call	_cpct_akp_SFXPlay
   6753 21 07 00      [10] 5075 	ld	hl, #7
   6756 39            [11] 5076 	add	hl, sp
   6757 F9            [ 6] 5077 	ld	sp, hl
                           5078 ;src/main.c:1515: ClearScreen();
   6758 CD 5A 4E      [17] 5079 	call	_ClearScreen
                           5080 ;src/main.c:1517: PrintText("SCAPE@FROM@MARS?", 9, 86);
   675B 21 09 56      [10] 5081 	ld	hl, #0x5609
   675E E5            [11] 5082 	push	hl
   675F 21 AD 67      [10] 5083 	ld	hl, #___str_19
   6762 E5            [11] 5084 	push	hl
   6763 CD 01 4F      [17] 5085 	call	_PrintText
   6766 F1            [10] 5086 	pop	af
   6767 F1            [10] 5087 	pop	af
                           5088 ;src/main.c:1518: Pause(300);
   6768 21 2C 01      [10] 5089 	ld	hl, #0x012c
   676B CD 25 4E      [17] 5090 	call	_Pause
                           5091 ;src/main.c:1520: cpct_akp_musicInit(Ingame1);
   676E 21 75 0B      [10] 5092 	ld	hl, #_Ingame1
   6771 E5            [11] 5093 	push	hl
   6772 CD B8 45      [17] 5094 	call	_cpct_akp_musicInit
   6775 F1            [10] 5095 	pop	af
   6776 C9            [10] 5096 	ret
   6777                    5097 ___str_10:
   6777 40 40 55 50 40     5098 	.ascii "@@UP@"
   677C 00                 5099 	.db 0x00
   677D                    5100 ___str_11:
   677D 40 44 4F 57 4E     5101 	.ascii "@DOWN"
   6782 00                 5102 	.db 0x00
   6783                    5103 ___str_12:
   6783 40 4C 45 46 54     5104 	.ascii "@LEFT"
   6788 00                 5105 	.db 0x00
   6789                    5106 ___str_13:
   6789 52 49 47 48 54     5107 	.ascii "RIGHT"
   678E 00                 5108 	.db 0x00
   678F                    5109 ___str_14:
   678F 40 46 49 52 45     5110 	.ascii "@FIRE"
   6794 00                 5111 	.db 0x00
   6795                    5112 ___str_15:
   6795 41 42 4F 52 54     5113 	.ascii "ABORT"
   679A 00                 5114 	.db 0x00
   679B                    5115 ___str_16:
   679B 4D 55 53 49 43     5116 	.ascii "MUSIC"
   67A0 00                 5117 	.db 0x00
   67A1                    5118 ___str_17:
   67A1 50 41 55 53 45     5119 	.ascii "PAUSE"
   67A6 00                 5120 	.db 0x00
   67A7                    5121 ___str_18:
   67A7 40 40 40 40 40     5122 	.ascii "@@@@@"
   67AC 00                 5123 	.db 0x00
   67AD                    5124 ___str_19:
   67AD 53 43 41 50 45 40  5125 	.ascii "SCAPE@FROM@MARS?"
        46 52 4F 4D 40 4D
        41 52 53 3F
   67BD 00                 5126 	.db 0x00
                           5127 ;src/main.c:1541: void InitValues() {	
                           5128 ;	---------------------------------
                           5129 ; Function InitValues
                           5130 ; ---------------------------------
   67BE                    5131 _InitValues::
                           5132 ;src/main.c:1543: ctlUp = Key_Q;
   67BE 21 08 08      [10] 5133 	ld	hl, #0x0808
   67C1 22 B3 4B      [16] 5134 	ld	(_ctlUp), hl
                           5135 ;src/main.c:1544: ctlDown = Key_A;
   67C4 26 20         [ 7] 5136 	ld	h, #0x20
   67C6 22 B5 4B      [16] 5137 	ld	(_ctlDown), hl
                           5138 ;src/main.c:1545: ctlLeft = Key_O;
   67C9 21 04 04      [10] 5139 	ld	hl, #0x0404
   67CC 22 B7 4B      [16] 5140 	ld	(_ctlLeft), hl
                           5141 ;src/main.c:1546: ctlRight = Key_P;
   67CF 21 03 08      [10] 5142 	ld	hl, #0x0803
   67D2 22 B9 4B      [16] 5143 	ld	(_ctlRight), hl
                           5144 ;src/main.c:1547: ctlFire = Key_Space;
   67D5 21 05 80      [10] 5145 	ld	hl, #0x8005
   67D8 22 BB 4B      [16] 5146 	ld	(_ctlFire), hl
                           5147 ;src/main.c:1548: ctlAbort = Key_X;
   67DB 2E 07         [ 7] 5148 	ld	l, #0x07
   67DD 22 BF 4B      [16] 5149 	ld	(_ctlAbort), hl
                           5150 ;src/main.c:1549: ctlMusic = Key_M;
   67E0 21 04 40      [10] 5151 	ld	hl, #0x4004
   67E3 22 BD 4B      [16] 5152 	ld	(_ctlMusic), hl
                           5153 ;src/main.c:1550: ctlPause = Key_H;	
   67E6 21 05 10      [10] 5154 	ld	hl, #0x1005
   67E9 22 C1 4B      [16] 5155 	ld	(_ctlPause), hl
   67EC C9            [10] 5156 	ret
                           5157 ;src/main.c:1555: void ResetData() {
                           5158 ;	---------------------------------
                           5159 ; Function ResetData
                           5160 ; ---------------------------------
   67ED                    5161 _ResetData::
                           5162 ;src/main.c:1557: shot.active = FALSE; 
   67ED 21 14 4C      [10] 5163 	ld	hl, #(_shot + 0x0005)
   67F0 36 00         [10] 5164 	ld	(hl), #0x00
                           5165 ;src/main.c:1558: shotLC.active = FALSE;
   67F2 21 1A 4C      [10] 5166 	ld	hl, #(_shotLC + 0x0005)
   67F5 36 00         [10] 5167 	ld	(hl), #0x00
                           5168 ;src/main.c:1560: spr[0].x = spr[0].px = 0;
   67F7 21 C5 4B      [10] 5169 	ld	hl, #(_spr + 0x0002)
   67FA 36 00         [10] 5170 	ld	(hl), #0x00
   67FC 21 C3 4B      [10] 5171 	ld	hl, #_spr
   67FF 36 00         [10] 5172 	ld	(hl), #0x00
                           5173 ;src/main.c:1561: spr[0].y = spr[0].py = 159;
   6801 21 C6 4B      [10] 5174 	ld	hl, #(_spr + 0x0003)
   6804 36 9F         [10] 5175 	ld	(hl), #0x9f
   6806 21 C4 4B      [10] 5176 	ld	hl, #(_spr + 0x0001)
   6809 36 9F         [10] 5177 	ld	(hl), #0x9f
                           5178 ;src/main.c:1562: spr[0].dir = D_right; 
   680B 21 CB 4B      [10] 5179 	ld	hl, #(_spr + 0x0008)
   680E 36 03         [10] 5180 	ld	(hl), #0x03
                           5181 ;src/main.c:1563: spr[0].status = S_stopped;
   6810 21 C7 4B      [10] 5182 	ld	hl, #(_spr + 0x0004)
   6813 36 00         [10] 5183 	ld	(hl), #0x00
                           5184 ;src/main.c:1565: InitMap();
   6815 CD 1D 50      [17] 5185 	call	_InitMap
                           5186 ;src/main.c:1566: RefreshScoreboard();
   6818 C3 85 4F      [10] 5187 	jp  _RefreshScoreboard
                           5188 ;src/main.c:1571: void InitGame() {
                           5189 ;	---------------------------------
                           5190 ; Function InitGame
                           5191 ; ---------------------------------
   681B                    5192 _InitGame::
                           5193 ;src/main.c:1572: StartMenu(); // start menu;
   681B CD B2 66      [17] 5194 	call	_StartMenu
                           5195 ;src/main.c:1573: music = TRUE;
   681E 21 B0 4B      [10] 5196 	ld	hl,#_music + 0
   6821 36 01         [10] 5197 	ld	(hl), #0x01
                           5198 ;src/main.c:1574: mapNumber = 0;
   6823 21 57 4C      [10] 5199 	ld	hl,#_mapNumber + 0
   6826 36 00         [10] 5200 	ld	(hl), #0x00
                           5201 ;src/main.c:1575: score = 0;
   6828 21 00 00      [10] 5202 	ld	hl, #0x0000
   682B 22 AB 4B      [16] 5203 	ld	(_score), hl
                           5204 ;src/main.c:1576: ammo= 99;
   682E 21 AF 4B      [10] 5205 	ld	hl,#_ammo + 0
   6831 36 63         [10] 5206 	ld	(hl), #0x63
                           5207 ;src/main.c:1577: activeLC = 1; // temp fix
   6833 21 1B 4C      [10] 5208 	ld	hl,#_activeLC + 0
   6836 36 01         [10] 5209 	ld	(hl), #0x01
                           5210 ;src/main.c:1580: spr[0].object = 255; // no object
   6838 21 CF 4B      [10] 5211 	ld	hl, #(_spr + 0x000c)
   683B 36 FF         [10] 5212 	ld	(hl), #0xff
                           5213 ;src/main.c:1581: spr[0].lives = 9; // 10 lives
   683D 21 CC 4B      [10] 5214 	ld	hl, #(_spr + 0x0009)
   6840 36 09         [10] 5215 	ld	(hl), #0x09
                           5216 ;src/main.c:1584: InitScoreboard();
   6842 CD 67 4F      [17] 5217 	call	_InitScoreboard
                           5218 ;src/main.c:1587: InitObjects();
   6845 CD 9F 54      [17] 5219 	call	_InitObjects
                           5220 ;src/main.c:1589: InitLC();
   6848 CD 3B 65      [17] 5221 	call	_InitLC
                           5222 ;src/main.c:1591: ResetData();
   684B C3 ED 67      [10] 5223 	jp  _ResetData
                           5224 ;src/main.c:1596: void GameOver() {
                           5225 ;	---------------------------------
                           5226 ; Function GameOver
                           5227 ; ---------------------------------
   684E                    5228 _GameOver::
                           5229 ;src/main.c:1598: if (spr[0].lives > 0) 
   684E 3A CC 4B      [13] 5230 	ld	a, (#(_spr + 0x0009) + 0)
   6851 B7            [ 4] 5231 	or	a, a
                           5232 ;src/main.c:1599: ResetData(); // reassign data to some variables
   6852 C2 ED 67      [10] 5233 	jp	NZ,_ResetData
                           5234 ;src/main.c:1601: cpct_akp_musicInit(FX); // stop the music
   6855 21 00 02      [10] 5235 	ld	hl, #_FX
   6858 E5            [11] 5236 	push	hl
   6859 CD B8 45      [17] 5237 	call	_cpct_akp_musicInit
   685C F1            [10] 5238 	pop	af
                           5239 ;src/main.c:1602: RefreshScoreboard();
   685D CD 85 4F      [17] 5240 	call	_RefreshScoreboard
                           5241 ;src/main.c:1604: PrintText("@@@@@@@@@@@", 18, 102);
   6860 21 12 66      [10] 5242 	ld	hl, #0x6612
   6863 E5            [11] 5243 	push	hl
   6864 21 95 68      [10] 5244 	ld	hl, #___str_20
   6867 E5            [11] 5245 	push	hl
   6868 CD 01 4F      [17] 5246 	call	_PrintText
   686B F1            [10] 5247 	pop	af
                           5248 ;src/main.c:1605: PrintText("@GAME@OVER@", 18, 110);
   686C 21 12 6E      [10] 5249 	ld	hl, #0x6e12
   686F E3            [19] 5250 	ex	(sp),hl
   6870 21 A1 68      [10] 5251 	ld	hl, #___str_21
   6873 E5            [11] 5252 	push	hl
   6874 CD 01 4F      [17] 5253 	call	_PrintText
   6877 F1            [10] 5254 	pop	af
                           5255 ;src/main.c:1606: PrintText("@@@@@@@@@@@", 18, 118);
   6878 21 12 76      [10] 5256 	ld	hl, #0x7612
   687B E3            [19] 5257 	ex	(sp),hl
   687C 21 95 68      [10] 5258 	ld	hl, #___str_20
   687F E5            [11] 5259 	push	hl
   6880 CD 01 4F      [17] 5260 	call	_PrintText
   6883 F1            [10] 5261 	pop	af
   6884 F1            [10] 5262 	pop	af
                           5263 ;src/main.c:1607: Pause(500);
   6885 21 F4 01      [10] 5264 	ld	hl, #0x01f4
   6888 CD 25 4E      [17] 5265 	call	_Pause
                           5266 ;src/main.c:1609: while (!cpct_isAnyKeyPressed());
   688B                    5267 00101$:
   688B CD 56 48      [17] 5268 	call	_cpct_isAnyKeyPressed
   688E 7D            [ 4] 5269 	ld	a, l
   688F B7            [ 4] 5270 	or	a, a
   6890 28 F9         [12] 5271 	jr	Z,00101$
                           5272 ;src/main.c:1610: InitGame();
   6892 C3 1B 68      [10] 5273 	jp  _InitGame
   6895                    5274 ___str_20:
   6895 40 40 40 40 40 40  5275 	.ascii "@@@@@@@@@@@"
        40 40 40 40 40
   68A0 00                 5276 	.db 0x00
   68A1                    5277 ___str_21:
   68A1 40 47 41 4D 45 40  5278 	.ascii "@GAME@OVER@"
        4F 56 45 52 40
   68AC 00                 5279 	.db 0x00
                           5280 ;src/main.c:1615: void MainLoop() {
                           5281 ;	---------------------------------
                           5282 ; Function MainLoop
                           5283 ; ---------------------------------
   68AD                    5284 _MainLoop::
                           5285 ;src/main.c:1616: cpct_disableFirmware(); // disable firmware control
   68AD CD B8 49      [17] 5286 	call	_cpct_disableFirmware
                           5287 ;src/main.c:1617: cpct_akp_SFXInit(FX); //initialize sound effects
   68B0 21 00 02      [10] 5288 	ld	hl, #_FX
   68B3 E5            [11] 5289 	push	hl
   68B4 CD 44 46      [17] 5290 	call	_cpct_akp_SFXInit
   68B7 F1            [10] 5291 	pop	af
                           5292 ;src/main.c:1618: cpct_setInterruptHandler(Interrupt); // initialize the interrupt manager (keyboard and sound)
   68B8 21 41 4E      [10] 5293 	ld	hl, #_Interrupt
   68BB CD 2C 4B      [17] 5294 	call	_cpct_setInterruptHandler
                           5295 ;src/main.c:1619: cpct_setVideoMode(0); // activate mode 0; 160*200 16 colors
   68BE 2E 00         [ 7] 5296 	ld	l, #0x00
   68C0 CD 80 49      [17] 5297 	call	_cpct_setVideoMode
                           5298 ;src/main.c:1620: cpct_setPalette(g_palette, 16); // assign palette
   68C3 21 10 00      [10] 5299 	ld	hl, #0x0010
   68C6 E5            [11] 5300 	push	hl
   68C7 21 15 2E      [10] 5301 	ld	hl, #_g_palette
   68CA E5            [11] 5302 	push	hl
   68CB CD 1A 3E      [17] 5303 	call	_cpct_setPalette
                           5304 ;src/main.c:1621: cpct_setBorder(g_palette[1]); // print border (black)
   68CE 21 16 2E      [10] 5305 	ld	hl, #_g_palette + 1
   68D1 46            [ 7] 5306 	ld	b, (hl)
   68D2 C5            [11] 5307 	push	bc
   68D3 33            [ 6] 5308 	inc	sp
   68D4 3E 10         [ 7] 5309 	ld	a, #0x10
   68D6 F5            [11] 5310 	push	af
   68D7 33            [ 6] 5311 	inc	sp
   68D8 CD A7 3E      [17] 5312 	call	_cpct_setPALColour
                           5313 ;src/main.c:1622: cpct_etm_setTileset2x4(g_tileset); // keep in memory the tiles for the maps (4 * 4)		
   68DB 21 25 2E      [10] 5314 	ld	hl, #_g_tileset
   68DE CD 10 48      [17] 5315 	call	_cpct_etm_setTileset2x4
                           5316 ;src/main.c:1623: InitValues(); // assigns default values ​​that do not vary between games
   68E1 CD BE 67      [17] 5317 	call	_InitValues
                           5318 ;src/main.c:1624: InitGame(); // initialization of some variables
   68E4 CD 1B 68      [17] 5319 	call	_InitGame
                           5320 ;src/main.c:1626: while (1) { // main loop		
   68E7                    5321 00116$:
                           5322 ;src/main.c:1628: ReprintObjects();
   68E7 CD 8D 52      [17] 5323 	call	_ReprintObjects
                           5324 ;src/main.c:1630: RunStatus(); // call the appropriate function according to the player status  
   68EA CD F3 5C      [17] 5325 	call	_RunStatus
                           5326 ;src/main.c:1631: SelectFrame(); // we assign the next frame of the animation to the player
   68ED CD 37 58      [17] 5327 	call	_SelectFrame
                           5328 ;src/main.c:1632: DeleteSprite(&spr[0]);
   68F0 21 C3 4B      [10] 5329 	ld	hl, #_spr
   68F3 CD 42 55      [17] 5330 	call	_DeleteSprite
                           5331 ;src/main.c:1633: spr[0].px = spr[0].x; // save the current X coordinate
   68F6 01 C5 4B      [10] 5332 	ld	bc, #_spr + 2
   68F9 3A C3 4B      [13] 5333 	ld	a, (#_spr + 0)
   68FC 02            [ 7] 5334 	ld	(bc), a
                           5335 ;src/main.c:1634: spr[0].py = spr[0].y; // save the current Y coordinate
   68FD 01 C6 4B      [10] 5336 	ld	bc, #_spr + 3
   6900 3A C4 4B      [13] 5337 	ld	a, (#(_spr + 0x0001) + 0)
   6903 02            [ 7] 5338 	ld	(bc), a
                           5339 ;src/main.c:1635: PrintSprite(&spr[0]); // prints the player in the new XY position
   6904 21 C3 4B      [10] 5340 	ld	hl, #_spr
   6907 CD 18 55      [17] 5341 	call	_PrintSprite
                           5342 ;src/main.c:1637: if (OverMines()) { // the player is stepping on mines?
   690A CD DC 50      [17] 5343 	call	_OverMines
   690D 7D            [ 4] 5344 	ld	a, l
   690E B7            [ 4] 5345 	or	a, a
   690F 28 0F         [12] 5346 	jr	Z,00102$
                           5347 ;src/main.c:1638: spr[0].lives--;
   6911 21 CC 4B      [10] 5348 	ld	hl, #_spr + 9
   6914 4E            [ 7] 5349 	ld	c, (hl)
   6915 0D            [ 4] 5350 	dec	c
   6916 71            [ 7] 5351 	ld	(hl), c
                           5352 ;src/main.c:1639: ExplodePlayer();
   6917 CD 37 5D      [17] 5353 	call	_ExplodePlayer
                           5354 ;src/main.c:1640: ExplodeEnemies();
   691A CD A7 63      [17] 5355 	call	_ExplodeEnemies
                           5356 ;src/main.c:1641: GameOver();
   691D CD 4E 68      [17] 5357 	call	_GameOver
   6920                    5358 00102$:
                           5359 ;src/main.c:1645: if (activeLC > 0 && spr[0].y >= lc[activeLC].y - 5 && spr[0].y <= lc[activeLC].y + 5)
   6920 3A 1B 4C      [13] 5360 	ld	a,(#_activeLC + 0)
   6923 B7            [ 4] 5361 	or	a, a
   6924 28 40         [12] 5362 	jr	Z,00104$
   6926 21 C4 4B      [10] 5363 	ld	hl, #(_spr + 0x0001) + 0
   6929 4E            [ 7] 5364 	ld	c, (hl)
   692A ED 5B 1B 4C   [20] 5365 	ld	de, (_activeLC)
   692E 16 00         [ 7] 5366 	ld	d, #0x00
   6930 6B            [ 4] 5367 	ld	l, e
   6931 62            [ 4] 5368 	ld	h, d
   6932 29            [11] 5369 	add	hl, hl
   6933 29            [11] 5370 	add	hl, hl
   6934 19            [11] 5371 	add	hl, de
   6935 11 1C 4C      [10] 5372 	ld	de, #_lc
   6938 19            [11] 5373 	add	hl, de
   6939 23            [ 6] 5374 	inc	hl
   693A 5E            [ 7] 5375 	ld	e, (hl)
   693B 16 00         [ 7] 5376 	ld	d, #0x00
   693D 7B            [ 4] 5377 	ld	a, e
   693E C6 FB         [ 7] 5378 	add	a, #0xfb
   6940 6F            [ 4] 5379 	ld	l, a
   6941 7A            [ 4] 5380 	ld	a, d
   6942 CE FF         [ 7] 5381 	adc	a, #0xff
   6944 67            [ 4] 5382 	ld	h, a
   6945 06 00         [ 7] 5383 	ld	b, #0x00
   6947 79            [ 4] 5384 	ld	a, c
   6948 95            [ 4] 5385 	sub	a, l
   6949 78            [ 4] 5386 	ld	a, b
   694A 9C            [ 4] 5387 	sbc	a, h
   694B E2 50 69      [10] 5388 	jp	PO, 00156$
   694E EE 80         [ 7] 5389 	xor	a, #0x80
   6950                    5390 00156$:
   6950 FA 66 69      [10] 5391 	jp	M, 00104$
   6953 21 05 00      [10] 5392 	ld	hl, #0x0005
   6956 19            [11] 5393 	add	hl, de
   6957 7D            [ 4] 5394 	ld	a, l
   6958 91            [ 4] 5395 	sub	a, c
   6959 7C            [ 4] 5396 	ld	a, h
   695A 98            [ 4] 5397 	sbc	a, b
   695B E2 60 69      [10] 5398 	jp	PO, 00157$
   695E EE 80         [ 7] 5399 	xor	a, #0x80
   6960                    5400 00157$:
   6960 FA 66 69      [10] 5401 	jp	M, 00104$
                           5402 ;src/main.c:1646: SetLC();
   6963 CD 8F 64      [17] 5403 	call	_SetLC
   6966                    5404 00104$:
                           5405 ;src/main.c:1648: EnemyLoop(&spr[1]);
   6966 21 D6 4B      [10] 5406 	ld	hl, #(_spr + 0x0013)
   6969 CD 1E 63      [17] 5407 	call	_EnemyLoop
                           5408 ;src/main.c:1649: EnemyLoop(&spr[2]);
   696C 21 E9 4B      [10] 5409 	ld	hl, #(_spr + 0x0026)
   696F CD 1E 63      [17] 5410 	call	_EnemyLoop
                           5411 ;src/main.c:1650: EnemyLoop(&spr[3]);
   6972 21 FC 4B      [10] 5412 	ld	hl, #(_spr + 0x0039)
   6975 CD 1E 63      [17] 5413 	call	_EnemyLoop
                           5414 ;src/main.c:1653: if (shot.active == TRUE)
   6978 3A 14 4C      [13] 5415 	ld	a, (#_shot + 5)
   697B 3D            [ 4] 5416 	dec	a
   697C 20 1E         [12] 5417 	jr	NZ,00108$
                           5418 ;src/main.c:1655: MoveShot(&shot, 2); // update XY coordinates of bullet if fired
   697E 3E 02         [ 7] 5419 	ld	a, #0x02
   6980 F5            [11] 5420 	push	af
   6981 33            [ 6] 5421 	inc	sp
   6982 21 0F 4C      [10] 5422 	ld	hl, #_shot
   6985 E5            [11] 5423 	push	hl
   6986 CD 33 5E      [17] 5424 	call	_MoveShot
   6989 F1            [10] 5425 	pop	af
   698A 33            [ 6] 5426 	inc	sp
                           5427 ;src/main.c:1656: PrintShot(&shot, spr[0].dir - 2); // delete the shot and prints it in the new XY position
   698B 21 CB 4B      [10] 5428 	ld	hl, #_spr + 8
   698E 46            [ 7] 5429 	ld	b, (hl)
   698F 05            [ 4] 5430 	dec	b
   6990 05            [ 4] 5431 	dec	b
   6991 C5            [11] 5432 	push	bc
   6992 33            [ 6] 5433 	inc	sp
   6993 21 0F 4C      [10] 5434 	ld	hl, #_shot
   6996 E5            [11] 5435 	push	hl
   6997 CD E6 5D      [17] 5436 	call	_PrintShot
   699A F1            [10] 5437 	pop	af
   699B 33            [ 6] 5438 	inc	sp
   699C                    5439 00108$:
                           5440 ;src/main.c:1660: if (shotLC.active == TRUE)
   699C 3A 1A 4C      [13] 5441 	ld	a, (#_shotLC + 5)
   699F 3D            [ 4] 5442 	dec	a
   69A0 20 1D         [12] 5443 	jr	NZ,00110$
                           5444 ;src/main.c:1662: MoveShot(&shotLC, 1); // update XY coordinates of of laser if fired
   69A2 3E 01         [ 7] 5445 	ld	a, #0x01
   69A4 F5            [11] 5446 	push	af
   69A5 33            [ 6] 5447 	inc	sp
   69A6 21 15 4C      [10] 5448 	ld	hl, #_shotLC
   69A9 E5            [11] 5449 	push	hl
   69AA CD 33 5E      [17] 5450 	call	_MoveShot
   69AD F1            [10] 5451 	pop	af
   69AE 33            [ 6] 5452 	inc	sp
                           5453 ;src/main.c:1663: PrintShot(&shotLC, 2); // delete the laser and prints it in the new XY position
   69AF 3E 02         [ 7] 5454 	ld	a, #0x02
   69B1 F5            [11] 5455 	push	af
   69B2 33            [ 6] 5456 	inc	sp
   69B3 21 15 4C      [10] 5457 	ld	hl, #_shotLC
   69B6 E5            [11] 5458 	push	hl
   69B7 CD E6 5D      [17] 5459 	call	_PrintShot
   69BA F1            [10] 5460 	pop	af
   69BB 33            [ 6] 5461 	inc	sp
                           5462 ;src/main.c:1664: CheckLCCollisions();
   69BC CD 78 65      [17] 5463 	call	_CheckLCCollisions
   69BF                    5464 00110$:
                           5465 ;src/main.c:1667: if (ctMainLoop % 15 == 0) // reprint scoreboard data
   69BF 3E 0F         [ 7] 5466 	ld	a, #0x0f
   69C1 F5            [11] 5467 	push	af
   69C2 33            [ 6] 5468 	inc	sp
   69C3 3A B1 4B      [13] 5469 	ld	a, (_ctMainLoop)
   69C6 F5            [11] 5470 	push	af
   69C7 33            [ 6] 5471 	inc	sp
   69C8 CD 14 48      [17] 5472 	call	__moduchar
   69CB F1            [10] 5473 	pop	af
   69CC 7D            [ 4] 5474 	ld	a, l
   69CD B7            [ 4] 5475 	or	a, a
   69CE 20 03         [12] 5476 	jr	NZ,00112$
                           5477 ;src/main.c:1668: RefreshScoreboard();	
   69D0 CD 85 4F      [17] 5478 	call	_RefreshScoreboard
   69D3                    5479 00112$:
                           5480 ;src/main.c:1670: cpct_waitVSYNC(); // wait for vertical retrace
   69D3 CD 78 49      [17] 5481 	call	_cpct_waitVSYNC
                           5482 ;src/main.c:1672: if (++ctMainLoop == 255) ctMainLoop = 0;
   69D6 FD 21 B1 4B   [14] 5483 	ld	iy, #_ctMainLoop
   69DA FD 34 00      [23] 5484 	inc	0 (iy)
   69DD FD 7E 00      [19] 5485 	ld	a, 0 (iy)
   69E0 3C            [ 4] 5486 	inc	a
   69E1 C2 E7 68      [10] 5487 	jp	NZ,00116$
   69E4 FD 36 00 00   [19] 5488 	ld	0 (iy), #0x00
   69E8 C3 E7 68      [10] 5489 	jp	00116$
                           5490 ;src/main.c:1682: void main(void) 
                           5491 ;	---------------------------------
                           5492 ; Function main
                           5493 ; ---------------------------------
   69EB                    5494 _main::
                           5495 ;src/main.c:1686: MainLoop();   
   69EB C3 AD 68      [10] 5496 	jp  _MainLoop
                           5497 	.area _CODE
                           5498 	.area _INITIALIZER
   4C58                    5499 __xinit__mapNumber:
   4C58 00                 5500 	.db #0x00	; 0
                           5501 	.area _CABS (ABS)
