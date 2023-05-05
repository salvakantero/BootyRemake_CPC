                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.6.8 #9946 (Linux)
                              4 ;--------------------------------------------------------
                              5 	.module main
                              6 	.optsdcc -mz80
                              7 	
                              8 ;--------------------------------------------------------
                              9 ; Public variables in this module
                             10 ;--------------------------------------------------------
                             11 	.globl _main
                             12 	.globl _InitGame
                             13 	.globl _ResetData
                             14 	.globl _InitValues
                             15 	.globl _StartMenu
                             16 	.globl _PrintStartMenu
                             17 	.globl _EnemyLoop
                             18 	.globl _ExplosionSecuence
                             19 	.globl _SetEnemyParams
                             20 	.globl _MoveEnemy
                             21 	.globl _RunStatus
                             22 	.globl _Climbing
                             23 	.globl _Walking
                             24 	.globl _WalkAnim
                             25 	.globl _PreJump
                             26 	.globl _Jumping
                             27 	.globl _JumpIn
                             28 	.globl _Stopped
                             29 	.globl _StopIn
                             30 	.globl _Falling
                             31 	.globl _LandIn
                             32 	.globl _FallIn
                             33 	.globl _PreJumpIn
                             34 	.globl _ClimbIn
                             35 	.globl _WalkIn
                             36 	.globl _MoveRight
                             37 	.globl _MoveLeft
                             38 	.globl _MoveDown
                             39 	.globl _MoveUp
                             40 	.globl _SelectFrame
                             41 	.globl _AssignFrame
                             42 	.globl _CheckEnemyCollision
                             43 	.globl _EnemyWalkAnim
                             44 	.globl _SelectSpriteFrame
                             45 	.globl _PrintExplosion
                             46 	.globl _DeleteSprite
                             47 	.globl _PrintSprite
                             48 	.globl _InitObjects
                             49 	.globl _CheckObjects
                             50 	.globl _ReprintObjects
                             51 	.globl _DeleteObjectScoreboard
                             52 	.globl _DeleteObject
                             53 	.globl _PrintObject
                             54 	.globl _RedefineKey
                             55 	.globl _Wait4Key
                             56 	.globl _ReturnKeyPressed
                             57 	.globl _FacingWall
                             58 	.globl _OverMines
                             59 	.globl _OnStairs
                             60 	.globl _OnPlatform
                             61 	.globl _GetTilePtr
                             62 	.globl _MoveLeftMap
                             63 	.globl _MoveRightMap
                             64 	.globl _InitMap
                             65 	.globl _PrintMap
                             66 	.globl _RefreshScoreboard
                             67 	.globl _InitScoreboard
                             68 	.globl _PrintText
                             69 	.globl _PrintNumber
                             70 	.globl _ClearScreen
                             71 	.globl _Interrupt
                             72 	.globl _PlayMusic
                             73 	.globl _Pause
                             74 	.globl _Itoa
                             75 	.globl _Strlen
                             76 	.globl _cpct_zx7b_decrunch_s
                             77 	.globl _cpct_etm_setTileset2x4
                             78 	.globl _cpct_etm_drawTileBox2x4
                             79 	.globl _cpct_akp_SFXPlay
                             80 	.globl _cpct_akp_SFXInit
                             81 	.globl _cpct_akp_musicInit
                             82 	.globl _cpct_getScreenPtr
                             83 	.globl _cpct_setPALColour
                             84 	.globl _cpct_setPalette
                             85 	.globl _cpct_waitVSYNC
                             86 	.globl _cpct_setVideoMode
                             87 	.globl _cpct_drawSpriteMaskedAlignedTable
                             88 	.globl _cpct_drawSprite
                             89 	.globl _cpct_drawSolidBox
                             90 	.globl _cpct_px2byteM0
                             91 	.globl _cpct_hflipSpriteM0
                             92 	.globl _cpct_get2Bits
                             93 	.globl _cpct_isAnyKeyPressed
                             94 	.globl _cpct_isKeyPressed
                             95 	.globl _cpct_scanKeyboard_if
                             96 	.globl _cpct_scanKeyboard_f
                             97 	.globl _cpct_scanKeyboard
                             98 	.globl _cpct_memset
                             99 	.globl _cpct_setInterruptHandler
                            100 	.globl _cpct_disableFirmware
                            101 	.globl _mapNumber
                            102 	.globl _enum_mov
                            103 	.globl _enum_sta
                            104 	.globl _enum_dir
                            105 	.globl _obj
                            106 	.globl _spr
                            107 	.globl _ctlPause
                            108 	.globl _ctlAbort
                            109 	.globl _ctlMusic
                            110 	.globl _ctlFire
                            111 	.globl _ctlRight
                            112 	.globl _ctlLeft
                            113 	.globl _ctlDown
                            114 	.globl _ctlUp
                            115 	.globl _ct
                            116 	.globl _ctMainLoop
                            117 	.globl _music
                            118 	.globl _highScore
                            119 	.globl _score
                            120 	.globl _g_jumpTable
                            121 	.globl _anim_infected
                            122 	.globl _anim_aracnovirus
                            123 	.globl _anim_pelusoid
                            124 	.globl _frm_infected
                            125 	.globl _frm_aracnovirus
                            126 	.globl _frm_pelusoid
                            127 	.globl _animClimb
                            128 	.globl _animWalk
                            129 	.globl _frm_player
                            130 	.globl _ExplodePlayer
                            131 	.globl _SetEnemies
                            132 	.globl _ExplodeEnemies
                            133 	.globl _GameOver
                            134 ;--------------------------------------------------------
                            135 ; special function registers
                            136 ;--------------------------------------------------------
                            137 ;--------------------------------------------------------
                            138 ; ram data
                            139 ;--------------------------------------------------------
                            140 	.area _DATA
   4BAB                     141 _score::
   4BAB                     142 	.ds 2
   4BAD                     143 _highScore::
   4BAD                     144 	.ds 2
   4BAF                     145 _music::
   4BAF                     146 	.ds 1
   4BB0                     147 _ctMainLoop::
   4BB0                     148 	.ds 1
   4BB1                     149 _ct::
   4BB1                     150 	.ds 1
   4BB2                     151 _ctlUp::
   4BB2                     152 	.ds 2
   4BB4                     153 _ctlDown::
   4BB4                     154 	.ds 2
   4BB6                     155 _ctlLeft::
   4BB6                     156 	.ds 2
   4BB8                     157 _ctlRight::
   4BB8                     158 	.ds 2
   4BBA                     159 _ctlFire::
   4BBA                     160 	.ds 2
   4BBC                     161 _ctlMusic::
   4BBC                     162 	.ds 2
   4BBE                     163 _ctlAbort::
   4BBE                     164 	.ds 2
   4BC0                     165 _ctlPause::
   4BC0                     166 	.ds 2
   4BC2                     167 _spr::
   4BC2                     168 	.ds 76
   4C0E                     169 _obj::
   4C0E                     170 	.ds 32
   4C2E                     171 _enum_dir::
   4C2E                     172 	.ds 1
   4C2F                     173 _enum_sta::
   4C2F                     174 	.ds 1
   4C30                     175 _enum_mov::
   4C30                     176 	.ds 1
   4C31                     177 _Interrupt_nInt_1_142:
   4C31                     178 	.ds 1
                            179 ;--------------------------------------------------------
                            180 ; ram data
                            181 ;--------------------------------------------------------
                            182 	.area _INITIALIZED
   4C32                     183 _mapNumber::
   4C32                     184 	.ds 1
                            185 ;--------------------------------------------------------
                            186 ; absolute external ram data
                            187 ;--------------------------------------------------------
                            188 	.area _DABS (ABS)
                            189 ;--------------------------------------------------------
                            190 ; global & static initialisations
                            191 ;--------------------------------------------------------
                            192 	.area _HOME
                            193 	.area _GSINIT
                            194 	.area _GSFINAL
                            195 	.area _GSINIT
                            196 ;--------------------------------------------------------
                            197 ; Home
                            198 ;--------------------------------------------------------
                            199 	.area _HOME
                            200 	.area _HOME
                            201 ;--------------------------------------------------------
                            202 ; code
                            203 ;--------------------------------------------------------
                            204 	.area _CODE
                            205 ;src/main.c:229: cpctm_createTransparentMaskTable(g_maskTable, 0x100, M0, 0);
                            206 ;	---------------------------------
                            207 ; Function dummy_cpct_transparentMaskTable0M0_container
                            208 ; ---------------------------------
   3319                     209 _dummy_cpct_transparentMaskTable0M0_container::
                            210 	.area _g_maskTable_ (ABS) 
   0100                     211 	.org 0x100 
   0100                     212 	 _g_maskTable::
   0100 FF AA 55 00 AA AA   213 	.db 0xFF, 0xAA, 0x55, 0x00, 0xAA, 0xAA, 0x00, 0x00 
        00 00
   0108 55 00 55 00 00 00   214 	.db 0x55, 0x00, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   0110 AA AA 00 00 AA AA   215 	.db 0xAA, 0xAA, 0x00, 0x00, 0xAA, 0xAA, 0x00, 0x00 
        00 00
   0118 00 00 00 00 00 00   216 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   0120 55 00 55 00 00 00   217 	.db 0x55, 0x00, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   0128 55 00 55 00 00 00   218 	.db 0x55, 0x00, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   0130 00 00 00 00 00 00   219 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   0138 00 00 00 00 00 00   220 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   0140 AA AA 00 00 AA AA   221 	.db 0xAA, 0xAA, 0x00, 0x00, 0xAA, 0xAA, 0x00, 0x00 
        00 00
   0148 00 00 00 00 00 00   222 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   0150 AA AA 00 00 AA AA   223 	.db 0xAA, 0xAA, 0x00, 0x00, 0xAA, 0xAA, 0x00, 0x00 
        00 00
   0158 00 00 00 00 00 00   224 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   0160 00 00 00 00 00 00   225 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   0168 00 00 00 00 00 00   226 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   0170 00 00 00 00 00 00   227 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   0178 00 00 00 00 00 00   228 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   0180 55 00 55 00 00 00   229 	.db 0x55, 0x00, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   0188 55 00 55 00 00 00   230 	.db 0x55, 0x00, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   0190 00 00 00 00 00 00   231 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   0198 00 00 00 00 00 00   232 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   01A0 55 00 55 00 00 00   233 	.db 0x55, 0x00, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   01A8 55 00 55 00 00 00   234 	.db 0x55, 0x00, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   01B0 00 00 00 00 00 00   235 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   01B8 00 00 00 00 00 00   236 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   01C0 00 00 00 00 00 00   237 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   01C8 00 00 00 00 00 00   238 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   01D0 00 00 00 00 00 00   239 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   01D8 00 00 00 00 00 00   240 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   01E0 00 00 00 00 00 00   241 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   01E8 00 00 00 00 00 00   242 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   01F0 00 00 00 00 00 00   243 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
   01F8 00 00 00 00 00 00   244 	.db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
        00 00
                            245 	.area _CSEG (REL, CON) 
                            246 ;src/main.c:262: u8 Strlen(const u8 *str) __z88dk_fastcall {
                            247 ;	---------------------------------
                            248 ; Function Strlen
                            249 ; ---------------------------------
   4C34                     250 _Strlen::
                            251 ;src/main.c:264: for (s = str; *s; ++s);
   4C34 4D            [ 4]  252 	ld	c,l
   4C35 44            [ 4]  253 	ld	b,h
   4C36                     254 00103$:
   4C36 7E            [ 7]  255 	ld	a, (hl)
   4C37 B7            [ 4]  256 	or	a, a
   4C38 28 03         [12]  257 	jr	Z,00101$
   4C3A 23            [ 6]  258 	inc	hl
   4C3B 18 F9         [12]  259 	jr	00103$
   4C3D                     260 00101$:
                            261 ;src/main.c:265: return (s - str);
   4C3D BF            [ 4]  262 	cp	a, a
   4C3E ED 42         [15]  263 	sbc	hl, bc
   4C40 C9            [10]  264 	ret
   4C41                     265 _frm_player:
   4C41 03                  266 	.db #0x03	; 3
   4C42 95 29               267 	.dw _g_player_0
   4C44 03                  268 	.db #0x03	; 3
   4C45 15 2A               269 	.dw _g_player_1
   4C47 03                  270 	.db #0x03	; 3
   4C48 95 2A               271 	.dw _g_player_2
   4C4A 03                  272 	.db #0x03	; 3
   4C4B 15 2B               273 	.dw _g_player_3
   4C4D 03                  274 	.db #0x03	; 3
   4C4E 95 2B               275 	.dw _g_player_4
   4C50 03                  276 	.db #0x03	; 3
   4C51 15 2C               277 	.dw _g_player_5
   4C53 03                  278 	.db #0x03	; 3
   4C54 95 2C               279 	.dw _g_player_6
   4C56 03                  280 	.db #0x03	; 3
   4C57 15 2D               281 	.dw _g_player_7
   4C59 03                  282 	.db #0x03	; 3
   4C5A 95 2D               283 	.dw _g_player_8
   4C5C                     284 _animWalk:
   4C5C 41 4C               285 	.dw (_frm_player + 0)
   4C5E 44 4C               286 	.dw (_frm_player + 3)
   4C60 41 4C               287 	.dw (_frm_player + 0)
   4C62 47 4C               288 	.dw (_frm_player + 6)
   4C64                     289 _animClimb:
   4C64 53 4C               290 	.dw (_frm_player + 18)
   4C66 56 4C               291 	.dw (_frm_player + 21)
   4C68 53 4C               292 	.dw (_frm_player + 18)
   4C6A 59 4C               293 	.dw (_frm_player + 24)
   4C6C                     294 _frm_pelusoid:
   4C6C 00                  295 	.db #0x00	; 0
   4C6D 95 28               296 	.dw _g_pelusoid_0
   4C6F 00                  297 	.db #0x00	; 0
   4C70 15 29               298 	.dw _g_pelusoid_1
   4C72                     299 _frm_aracnovirus:
   4C72 00                  300 	.db #0x00	; 0
   4C73 95 27               301 	.dw _g_aracnovirus_0
   4C75 00                  302 	.db #0x00	; 0
   4C76 15 28               303 	.dw _g_aracnovirus_1
   4C78                     304 _frm_infected:
   4C78 00                  305 	.db #0x00	; 0
   4C79 95 26               306 	.dw _g_infected_0
   4C7B 00                  307 	.db #0x00	; 0
   4C7C 15 27               308 	.dw _g_infected_1
   4C7E                     309 _anim_pelusoid:
   4C7E 6C 4C               310 	.dw (_frm_pelusoid + 0)
   4C80 6F 4C               311 	.dw (_frm_pelusoid + 3)
   4C82                     312 _anim_aracnovirus:
   4C82 72 4C               313 	.dw (_frm_aracnovirus + 0)
   4C84 75 4C               314 	.dw (_frm_aracnovirus + 3)
   4C86                     315 _anim_infected:
   4C86 78 4C               316 	.dw (_frm_infected + 0)
   4C88 7B 4C               317 	.dw (_frm_infected + 3)
   4C8A                     318 _g_jumpTable:
   4C8A FF                  319 	.db #0xff	; 255
   4C8B A5                  320 	.db #0xa5	; 165
   4C8C 40                  321 	.db #0x40	; 64
                            322 ;src/main.c:270: char* Itoa(u16 value, char* result, int base) {    
                            323 ;	---------------------------------
                            324 ; Function Itoa
                            325 ; ---------------------------------
   4C8D                     326 _Itoa::
   4C8D DD E5         [15]  327 	push	ix
   4C8F DD 21 00 00   [14]  328 	ld	ix,#0
   4C93 DD 39         [15]  329 	add	ix,sp
   4C95 21 F9 FF      [10]  330 	ld	hl, #-7
   4C98 39            [11]  331 	add	hl, sp
   4C99 F9            [ 6]  332 	ld	sp, hl
                            333 ;src/main.c:272: char* ptr = result, *ptr1 = result, tmp_char;
   4C9A DD 5E 06      [19]  334 	ld	e,6 (ix)
   4C9D DD 56 07      [19]  335 	ld	d,7 (ix)
   4CA0 33            [ 6]  336 	inc	sp
   4CA1 33            [ 6]  337 	inc	sp
   4CA2 D5            [11]  338 	push	de
                            339 ;src/main.c:274: if (base < 2 || base > 36) { 
   4CA3 DD 7E 08      [19]  340 	ld	a, 8 (ix)
   4CA6 D6 02         [ 7]  341 	sub	a, #0x02
   4CA8 DD 7E 09      [19]  342 	ld	a, 9 (ix)
   4CAB 17            [ 4]  343 	rla
   4CAC 3F            [ 4]  344 	ccf
   4CAD 1F            [ 4]  345 	rra
   4CAE DE 80         [ 7]  346 	sbc	a, #0x80
   4CB0 38 12         [12]  347 	jr	C,00101$
   4CB2 3E 24         [ 7]  348 	ld	a, #0x24
   4CB4 DD BE 08      [19]  349 	cp	a, 8 (ix)
   4CB7 3E 00         [ 7]  350 	ld	a, #0x00
   4CB9 DD 9E 09      [19]  351 	sbc	a, 9 (ix)
   4CBC E2 C1 4C      [10]  352 	jp	PO, 00140$
   4CBF EE 80         [ 7]  353 	xor	a, #0x80
   4CC1                     354 00140$:
   4CC1 F2 CA 4C      [10]  355 	jp	P, 00115$
   4CC4                     356 00101$:
                            357 ;src/main.c:275: *result = '\0'; 
   4CC4 AF            [ 4]  358 	xor	a, a
   4CC5 12            [ 7]  359 	ld	(de), a
                            360 ;src/main.c:276: return result; 
   4CC6 EB            [ 4]  361 	ex	de,hl
   4CC7 C3 67 4D      [10]  362 	jp	00112$
                            363 ;src/main.c:279: do {
   4CCA                     364 00115$:
   4CCA DD 73 FE      [19]  365 	ld	-2 (ix), e
   4CCD DD 72 FF      [19]  366 	ld	-1 (ix), d
   4CD0                     367 00104$:
                            368 ;src/main.c:280: tmp_value = value;
   4CD0 DD 7E 04      [19]  369 	ld	a, 4 (ix)
   4CD3 DD 77 FB      [19]  370 	ld	-5 (ix), a
   4CD6 DD 7E 05      [19]  371 	ld	a, 5 (ix)
   4CD9 DD 77 FC      [19]  372 	ld	-4 (ix), a
                            373 ;src/main.c:281: value /= base;
   4CDC DD 4E 08      [19]  374 	ld	c,8 (ix)
   4CDF DD 46 09      [19]  375 	ld	b,9 (ix)
   4CE2 C5            [11]  376 	push	bc
   4CE3 DD 6E 04      [19]  377 	ld	l,4 (ix)
   4CE6 DD 66 05      [19]  378 	ld	h,5 (ix)
   4CE9 E5            [11]  379 	push	hl
   4CEA CD D9 3D      [17]  380 	call	__divuint
   4CED F1            [10]  381 	pop	af
   4CEE F1            [10]  382 	pop	af
   4CEF DD 75 04      [19]  383 	ld	4 (ix), l
   4CF2 DD 74 05      [19]  384 	ld	5 (ix), h
                            385 ;src/main.c:282: *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
   4CF5 DD 4E FB      [19]  386 	ld	c, -5 (ix)
   4CF8 DD 5E 04      [19]  387 	ld	e, 4 (ix)
   4CFB DD 66 08      [19]  388 	ld	h, 8 (ix)
   4CFE 2E 00         [ 7]  389 	ld	l, #0x00
   4D00 55            [ 4]  390 	ld	d, l
   4D01 06 08         [ 7]  391 	ld	b, #0x08
   4D03                     392 00141$:
   4D03 29            [11]  393 	add	hl, hl
   4D04 30 01         [12]  394 	jr	NC,00142$
   4D06 19            [11]  395 	add	hl, de
   4D07                     396 00142$:
   4D07 10 FA         [13]  397 	djnz	00141$
   4D09 79            [ 4]  398 	ld	a, c
   4D0A 95            [ 4]  399 	sub	a, l
   4D0B C6 23         [ 7]  400 	add	a, #0x23
   4D0D 4F            [ 4]  401 	ld	c, a
   4D0E 17            [ 4]  402 	rla
   4D0F 9F            [ 4]  403 	sbc	a, a
   4D10 47            [ 4]  404 	ld	b, a
   4D11 21 6C 4D      [10]  405 	ld	hl, #___str_0
   4D14 09            [11]  406 	add	hl, bc
   4D15 4E            [ 7]  407 	ld	c, (hl)
   4D16 DD 6E FE      [19]  408 	ld	l,-2 (ix)
   4D19 DD 66 FF      [19]  409 	ld	h,-1 (ix)
   4D1C 71            [ 7]  410 	ld	(hl), c
   4D1D DD 34 FE      [23]  411 	inc	-2 (ix)
   4D20 20 03         [12]  412 	jr	NZ,00143$
   4D22 DD 34 FF      [23]  413 	inc	-1 (ix)
   4D25                     414 00143$:
                            415 ;src/main.c:283: } while (value);
   4D25 DD 7E 05      [19]  416 	ld	a, 5 (ix)
   4D28 DD B6 04      [19]  417 	or	a,4 (ix)
   4D2B 20 A3         [12]  418 	jr	NZ,00104$
                            419 ;src/main.c:285: if (tmp_value < 0) 
   4D2D DD 4E FE      [19]  420 	ld	c,-2 (ix)
   4D30 DD 46 FF      [19]  421 	ld	b,-1 (ix)
   4D33 DD CB FC 7E   [20]  422 	bit	7, -4 (ix)
   4D37 28 0F         [12]  423 	jr	Z,00108$
                            424 ;src/main.c:286: *ptr++ = '-';
   4D39 DD 6E FE      [19]  425 	ld	l,-2 (ix)
   4D3C DD 66 FF      [19]  426 	ld	h,-1 (ix)
   4D3F 36 2D         [10]  427 	ld	(hl), #0x2d
   4D41 DD 4E FE      [19]  428 	ld	c,-2 (ix)
   4D44 DD 46 FF      [19]  429 	ld	b,-1 (ix)
   4D47 03            [ 6]  430 	inc	bc
   4D48                     431 00108$:
                            432 ;src/main.c:287: *ptr-- = '\0';
   4D48 AF            [ 4]  433 	xor	a, a
   4D49 02            [ 7]  434 	ld	(bc), a
   4D4A 0B            [ 6]  435 	dec	bc
                            436 ;src/main.c:289: while(ptr1 < ptr) {
   4D4B D1            [10]  437 	pop	de
   4D4C D5            [11]  438 	push	de
   4D4D                     439 00109$:
   4D4D 7B            [ 4]  440 	ld	a, e
   4D4E 91            [ 4]  441 	sub	a, c
   4D4F 7A            [ 4]  442 	ld	a, d
   4D50 98            [ 4]  443 	sbc	a, b
   4D51 30 0E         [12]  444 	jr	NC,00111$
                            445 ;src/main.c:290: tmp_char = *ptr;
   4D53 0A            [ 7]  446 	ld	a, (bc)
   4D54 DD 77 FD      [19]  447 	ld	-3 (ix), a
                            448 ;src/main.c:291: *ptr--= *ptr1;
   4D57 1A            [ 7]  449 	ld	a, (de)
   4D58 02            [ 7]  450 	ld	(bc), a
   4D59 0B            [ 6]  451 	dec	bc
                            452 ;src/main.c:292: *ptr1++ = tmp_char;
   4D5A DD 7E FD      [19]  453 	ld	a, -3 (ix)
   4D5D 12            [ 7]  454 	ld	(de), a
   4D5E 13            [ 6]  455 	inc	de
   4D5F 18 EC         [12]  456 	jr	00109$
   4D61                     457 00111$:
                            458 ;src/main.c:295: return result;
   4D61 DD 6E 06      [19]  459 	ld	l,6 (ix)
   4D64 DD 66 07      [19]  460 	ld	h,7 (ix)
   4D67                     461 00112$:
   4D67 DD F9         [10]  462 	ld	sp, ix
   4D69 DD E1         [14]  463 	pop	ix
   4D6B C9            [10]  464 	ret
   4D6C                     465 ___str_0:
   4D6C 7A 79 78 77 76 75   466 	.ascii "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmno"
        74 73 72 71 70 6F
        6E 6D 6C 6B 6A 69
        68 67 66 65 64 63
        62 61 39 38 37 36
        35 34 33 32 31 30
        31 32 33 34 35 36
        37 38 39 61 62 63
        64 65 66 67 68 69
        6A 6B 6C 6D 6E 6F
   4DA8 70 71 72 73 74 75   467 	.ascii "pqrstuvwxyz"
        76 77 78 79 7A
   4DB3 00                  468 	.db 0x00
                            469 ;src/main.c:300: void Pause(u16 value) __z88dk_fastcall {
                            470 ;	---------------------------------
                            471 ; Function Pause
                            472 ; ---------------------------------
   4DB4                     473 _Pause::
                            474 ;src/main.c:302: for(i = 0; i < value; i++) {
   4DB4 01 00 00      [10]  475 	ld	bc, #0x0000
   4DB7                     476 00103$:
   4DB7 79            [ 4]  477 	ld	a, c
   4DB8 95            [ 4]  478 	sub	a, l
   4DB9 78            [ 4]  479 	ld	a, b
   4DBA 9C            [ 4]  480 	sbc	a, h
   4DBB D0            [11]  481 	ret	NC
                            482 ;src/main.c:305: __endasm;
   4DBC 76            [ 4]  483 	halt
                            484 ;src/main.c:302: for(i = 0; i < value; i++) {
   4DBD 03            [ 6]  485 	inc	bc
   4DBE 18 F7         [12]  486 	jr	00103$
                            487 ;src/main.c:311: void PlayMusic() {
                            488 ;	---------------------------------
                            489 ; Function PlayMusic
                            490 ; ---------------------------------
   4DC0                     491 _PlayMusic::
                            492 ;src/main.c:326: __endasm;
   4DC0 D9            [ 4]  493 	exx
   4DC1 08                  494 	.db	#0x08
   4DC2 F5            [11]  495 	push	af
   4DC3 C5            [11]  496 	push	bc
   4DC4 D5            [11]  497 	push	de
   4DC5 E5            [11]  498 	push	hl
   4DC6 CD B5 3E      [17]  499 	call	_cpct_akp_musicPlay
   4DC9 E1            [10]  500 	pop	hl
   4DCA D1            [10]  501 	pop	de
   4DCB C1            [10]  502 	pop	bc
   4DCC F1            [10]  503 	pop	af
   4DCD 08                  504 	.db	#0x08
   4DCE D9            [ 4]  505 	exx
   4DCF C9            [10]  506 	ret
                            507 ;src/main.c:331: void Interrupt() {
                            508 ;	---------------------------------
                            509 ; Function Interrupt
                            510 ; ---------------------------------
   4DD0                     511 _Interrupt::
                            512 ;src/main.c:334: if (++nInt == 5) {
   4DD0 FD 21 31 4C   [14]  513 	ld	iy, #_Interrupt_nInt_1_142
   4DD4 FD 34 00      [23]  514 	inc	0 (iy)
   4DD7 FD 7E 00      [19]  515 	ld	a, 0 (iy)
   4DDA D6 05         [ 7]  516 	sub	a, #0x05
   4DDC C0            [11]  517 	ret	NZ
                            518 ;src/main.c:335: PlayMusic();
   4DDD CD C0 4D      [17]  519 	call	_PlayMusic
                            520 ;src/main.c:336: cpct_scanKeyboard_if();
   4DE0 CD 89 48      [17]  521 	call	_cpct_scanKeyboard_if
                            522 ;src/main.c:337: nInt = 0;
   4DE3 21 31 4C      [10]  523 	ld	hl,#_Interrupt_nInt_1_142 + 0
   4DE6 36 00         [10]  524 	ld	(hl), #0x00
   4DE8 C9            [10]  525 	ret
                            526 ;src/main.c:355: void ClearScreen() {
                            527 ;	---------------------------------
                            528 ; Function ClearScreen
                            529 ; ---------------------------------
   4DE9                     530 _ClearScreen::
                            531 ;src/main.c:356: cpct_memset(CPCT_VMEM_START, cpct_px2byteM0(1, 1), 16384);
   4DE9 21 01 01      [10]  532 	ld	hl, #0x0101
   4DEC E5            [11]  533 	push	hl
   4DED CD 8E 49      [17]  534 	call	_cpct_px2byteM0
   4DF0 45            [ 4]  535 	ld	b, l
   4DF1 21 00 40      [10]  536 	ld	hl, #0x4000
   4DF4 E5            [11]  537 	push	hl
   4DF5 C5            [11]  538 	push	bc
   4DF6 33            [ 6]  539 	inc	sp
   4DF7 26 C0         [ 7]  540 	ld	h, #0xc0
   4DF9 E5            [11]  541 	push	hl
   4DFA CD AA 49      [17]  542 	call	_cpct_memset
   4DFD C9            [10]  543 	ret
                            544 ;src/main.c:361: void PrintNumber(u16 num, u8 len, u8 x, u8 y) { 
                            545 ;	---------------------------------
                            546 ; Function PrintNumber
                            547 ; ---------------------------------
   4DFE                     548 _PrintNumber::
   4DFE DD E5         [15]  549 	push	ix
   4E00 DD 21 00 00   [14]  550 	ld	ix,#0
   4E04 DD 39         [15]  551 	add	ix,sp
   4E06 21 F8 FF      [10]  552 	ld	hl, #-8
   4E09 39            [11]  553 	add	hl, sp
                            554 ;src/main.c:367: Itoa(num, txt, 10);    
   4E0A F9            [ 6]  555 	ld	sp, hl
   4E0B 23            [ 6]  556 	inc	hl
   4E0C 23            [ 6]  557 	inc	hl
   4E0D 4D            [ 4]  558 	ld	c, l
   4E0E 44            [ 4]  559 	ld	b, h
   4E0F 59            [ 4]  560 	ld	e, c
   4E10 50            [ 4]  561 	ld	d, b
   4E11 C5            [11]  562 	push	bc
   4E12 21 0A 00      [10]  563 	ld	hl, #0x000a
   4E15 E5            [11]  564 	push	hl
   4E16 D5            [11]  565 	push	de
   4E17 DD 6E 04      [19]  566 	ld	l,4 (ix)
   4E1A DD 66 05      [19]  567 	ld	h,5 (ix)
   4E1D E5            [11]  568 	push	hl
   4E1E CD 8D 4C      [17]  569 	call	_Itoa
   4E21 21 06 00      [10]  570 	ld	hl, #6
   4E24 39            [11]  571 	add	hl, sp
   4E25 F9            [ 6]  572 	ld	sp, hl
   4E26 C1            [10]  573 	pop	bc
                            574 ;src/main.c:368: zeros = len - Strlen(txt);
   4E27 69            [ 4]  575 	ld	l, c
   4E28 60            [ 4]  576 	ld	h, b
   4E29 C5            [11]  577 	push	bc
   4E2A CD 34 4C      [17]  578 	call	_Strlen
   4E2D C1            [10]  579 	pop	bc
   4E2E DD 7E 06      [19]  580 	ld	a, 6 (ix)
   4E31 95            [ 4]  581 	sub	a, l
   4E32 DD 77 F9      [19]  582 	ld	-7 (ix), a
                            583 ;src/main.c:369: nAux = txt[pos];
   4E35 0A            [ 7]  584 	ld	a, (bc)
   4E36 5F            [ 4]  585 	ld	e, a
                            586 ;src/main.c:371: while(nAux != '\0')	{	
   4E37 DD 36 F8 00   [19]  587 	ld	-8 (ix), #0x00
   4E3B                     588 00101$:
   4E3B 7B            [ 4]  589 	ld	a, e
   4E3C B7            [ 4]  590 	or	a, a
   4E3D 28 4C         [12]  591 	jr	Z,00104$
                            592 ;src/main.c:372: u8* ptr = cpct_getScreenPtr(CPCT_VMEM_START, (zeros + pos) * FNT_W + x, y);
   4E3F DD 7E F9      [19]  593 	ld	a, -7 (ix)
   4E42 DD 86 F8      [19]  594 	add	a, -8 (ix)
   4E45 87            [ 4]  595 	add	a, a
   4E46 87            [ 4]  596 	add	a, a
   4E47 DD 86 07      [19]  597 	add	a, 7 (ix)
   4E4A 57            [ 4]  598 	ld	d, a
   4E4B C5            [11]  599 	push	bc
   4E4C D5            [11]  600 	push	de
   4E4D DD 7E 08      [19]  601 	ld	a, 8 (ix)
   4E50 F5            [11]  602 	push	af
   4E51 33            [ 6]  603 	inc	sp
   4E52 D5            [11]  604 	push	de
   4E53 33            [ 6]  605 	inc	sp
   4E54 21 00 C0      [10]  606 	ld	hl, #0xc000
   4E57 E5            [11]  607 	push	hl
   4E58 CD AA 4A      [17]  608 	call	_cpct_getScreenPtr
   4E5B D1            [10]  609 	pop	de
   4E5C C1            [10]  610 	pop	bc
                            611 ;src/main.c:373: cpct_drawSprite(g_font[nAux - 48], ptr, FNT_W, FNT_H);
   4E5D E5            [11]  612 	push	hl
   4E5E FD E1         [14]  613 	pop	iy
   4E60 16 00         [ 7]  614 	ld	d, #0x00
   4E62 7B            [ 4]  615 	ld	a, e
   4E63 C6 D0         [ 7]  616 	add	a, #0xd0
   4E65 6F            [ 4]  617 	ld	l, a
   4E66 7A            [ 4]  618 	ld	a, d
   4E67 CE FF         [ 7]  619 	adc	a, #0xff
   4E69 67            [ 4]  620 	ld	h, a
   4E6A 29            [11]  621 	add	hl, hl
   4E6B 29            [11]  622 	add	hl, hl
   4E6C 29            [11]  623 	add	hl, hl
   4E6D 29            [11]  624 	add	hl, hl
   4E6E 29            [11]  625 	add	hl, hl
   4E6F 11 79 38      [10]  626 	ld	de, #_g_font
   4E72 19            [11]  627 	add	hl, de
   4E73 C5            [11]  628 	push	bc
   4E74 11 04 08      [10]  629 	ld	de, #0x0804
   4E77 D5            [11]  630 	push	de
   4E78 FD E5         [15]  631 	push	iy
   4E7A E5            [11]  632 	push	hl
   4E7B CD DC 46      [17]  633 	call	_cpct_drawSprite
   4E7E C1            [10]  634 	pop	bc
                            635 ;src/main.c:374: nAux = txt[++pos];
   4E7F DD 34 F8      [23]  636 	inc	-8 (ix)
   4E82 DD 6E F8      [19]  637 	ld	l,-8 (ix)
   4E85 26 00         [ 7]  638 	ld	h,#0x00
   4E87 09            [11]  639 	add	hl, bc
   4E88 5E            [ 7]  640 	ld	e, (hl)
   4E89 18 B0         [12]  641 	jr	00101$
   4E8B                     642 00104$:
   4E8B DD F9         [10]  643 	ld	sp, ix
   4E8D DD E1         [14]  644 	pop	ix
   4E8F C9            [10]  645 	ret
                            646 ;src/main.c:380: void PrintText(u8 txt[], u8 x, u8 y) {
                            647 ;	---------------------------------
                            648 ; Function PrintText
                            649 ; ---------------------------------
   4E90                     650 _PrintText::
   4E90 DD E5         [15]  651 	push	ix
   4E92 DD 21 00 00   [14]  652 	ld	ix,#0
   4E96 DD 39         [15]  653 	add	ix,sp
   4E98 3B            [ 6]  654 	dec	sp
                            655 ;src/main.c:382: u8 car = txt[pos];
   4E99 DD 4E 04      [19]  656 	ld	c,4 (ix)
   4E9C DD 46 05      [19]  657 	ld	b,5 (ix)
   4E9F 0A            [ 7]  658 	ld	a, (bc)
   4EA0 5F            [ 4]  659 	ld	e, a
                            660 ;src/main.c:384: while(car != '\0') { // "@" = space    ";" = -   "?" = !!
   4EA1 DD 36 FF 00   [19]  661 	ld	-1 (ix), #0x00
   4EA5                     662 00101$:
   4EA5 7B            [ 4]  663 	ld	a, e
   4EA6 B7            [ 4]  664 	or	a, a
   4EA7 28 49         [12]  665 	jr	Z,00104$
                            666 ;src/main.c:385: u8* ptr = cpct_getScreenPtr(CPCT_VMEM_START, (pos * FNT_W) + x, y);
   4EA9 DD 7E FF      [19]  667 	ld	a, -1 (ix)
   4EAC 87            [ 4]  668 	add	a, a
   4EAD 87            [ 4]  669 	add	a, a
   4EAE DD 86 06      [19]  670 	add	a, 6 (ix)
   4EB1 57            [ 4]  671 	ld	d, a
   4EB2 C5            [11]  672 	push	bc
   4EB3 D5            [11]  673 	push	de
   4EB4 DD 7E 07      [19]  674 	ld	a, 7 (ix)
   4EB7 F5            [11]  675 	push	af
   4EB8 33            [ 6]  676 	inc	sp
   4EB9 D5            [11]  677 	push	de
   4EBA 33            [ 6]  678 	inc	sp
   4EBB 21 00 C0      [10]  679 	ld	hl, #0xc000
   4EBE E5            [11]  680 	push	hl
   4EBF CD AA 4A      [17]  681 	call	_cpct_getScreenPtr
   4EC2 D1            [10]  682 	pop	de
   4EC3 C1            [10]  683 	pop	bc
                            684 ;src/main.c:386: cpct_drawSprite(g_font[car - 48], ptr, FNT_W, FNT_H);
   4EC4 E5            [11]  685 	push	hl
   4EC5 FD E1         [14]  686 	pop	iy
   4EC7 16 00         [ 7]  687 	ld	d, #0x00
   4EC9 7B            [ 4]  688 	ld	a, e
   4ECA C6 D0         [ 7]  689 	add	a, #0xd0
   4ECC 6F            [ 4]  690 	ld	l, a
   4ECD 7A            [ 4]  691 	ld	a, d
   4ECE CE FF         [ 7]  692 	adc	a, #0xff
   4ED0 67            [ 4]  693 	ld	h, a
   4ED1 29            [11]  694 	add	hl, hl
   4ED2 29            [11]  695 	add	hl, hl
   4ED3 29            [11]  696 	add	hl, hl
   4ED4 29            [11]  697 	add	hl, hl
   4ED5 29            [11]  698 	add	hl, hl
   4ED6 11 79 38      [10]  699 	ld	de, #_g_font
   4ED9 19            [11]  700 	add	hl, de
   4EDA C5            [11]  701 	push	bc
   4EDB 11 04 08      [10]  702 	ld	de, #0x0804
   4EDE D5            [11]  703 	push	de
   4EDF FD E5         [15]  704 	push	iy
   4EE1 E5            [11]  705 	push	hl
   4EE2 CD DC 46      [17]  706 	call	_cpct_drawSprite
   4EE5 C1            [10]  707 	pop	bc
                            708 ;src/main.c:387: car = txt[++pos];
   4EE6 DD 34 FF      [23]  709 	inc	-1 (ix)
   4EE9 DD 6E FF      [19]  710 	ld	l,-1 (ix)
   4EEC 26 00         [ 7]  711 	ld	h,#0x00
   4EEE 09            [11]  712 	add	hl, bc
   4EEF 5E            [ 7]  713 	ld	e, (hl)
   4EF0 18 B3         [12]  714 	jr	00101$
   4EF2                     715 00104$:
   4EF2 33            [ 6]  716 	inc	sp
   4EF3 DD E1         [14]  717 	pop	ix
   4EF5 C9            [10]  718 	ret
                            719 ;src/main.c:393: void InitScoreboard()
                            720 ;	---------------------------------
                            721 ; Function InitScoreboard
                            722 ; ---------------------------------
   4EF6                     723 _InitScoreboard::
                            724 ;src/main.c:395: cpct_drawSprite(g_hud_0, cpctm_screenPtr(CPCT_VMEM_START,  0, 0), G_HUD_0_W, G_HUD_0_H);
   4EF6 21 28 28      [10]  725 	ld	hl, #0x2828
   4EF9 E5            [11]  726 	push	hl
   4EFA 21 00 C0      [10]  727 	ld	hl, #0xc000
   4EFD E5            [11]  728 	push	hl
   4EFE 21 15 1A      [10]  729 	ld	hl, #_g_hud_0
   4F01 E5            [11]  730 	push	hl
   4F02 CD DC 46      [17]  731 	call	_cpct_drawSprite
                            732 ;src/main.c:396: cpct_drawSprite(g_hud_1, cpctm_screenPtr(CPCT_VMEM_START, 40, 0), G_HUD_1_W, G_HUD_1_H);
   4F05 21 28 28      [10]  733 	ld	hl, #0x2828
   4F08 E5            [11]  734 	push	hl
   4F09 26 C0         [ 7]  735 	ld	h, #0xc0
   4F0B E5            [11]  736 	push	hl
   4F0C 21 55 20      [10]  737 	ld	hl, #_g_hud_1
   4F0F E5            [11]  738 	push	hl
   4F10 CD DC 46      [17]  739 	call	_cpct_drawSprite
   4F13 C9            [10]  740 	ret
                            741 ;src/main.c:401: void RefreshScoreboard() {
                            742 ;	---------------------------------
                            743 ; Function RefreshScoreboard
                            744 ; ---------------------------------
   4F14                     745 _RefreshScoreboard::
                            746 ;src/main.c:402: PrintNumber(score, 5, 21, 0); // current score
   4F14 21 15 00      [10]  747 	ld	hl, #0x0015
   4F17 E5            [11]  748 	push	hl
   4F18 3E 05         [ 7]  749 	ld	a, #0x05
   4F1A F5            [11]  750 	push	af
   4F1B 33            [ 6]  751 	inc	sp
   4F1C 2A AB 4B      [16]  752 	ld	hl, (_score)
   4F1F E5            [11]  753 	push	hl
   4F20 CD FE 4D      [17]  754 	call	_PrintNumber
   4F23 F1            [10]  755 	pop	af
                            756 ;src/main.c:403: PrintNumber(highScore, 5, 60, 0); // session high score
   4F24 33            [ 6]  757 	inc	sp
   4F25 21 3C 00      [10]  758 	ld	hl,#0x003c
   4F28 E3            [19]  759 	ex	(sp),hl
   4F29 3E 05         [ 7]  760 	ld	a, #0x05
   4F2B F5            [11]  761 	push	af
   4F2C 33            [ 6]  762 	inc	sp
   4F2D 2A AD 4B      [16]  763 	ld	hl, (_highScore)
   4F30 E5            [11]  764 	push	hl
   4F31 CD FE 4D      [17]  765 	call	_PrintNumber
   4F34 F1            [10]  766 	pop	af
   4F35 F1            [10]  767 	pop	af
   4F36 33            [ 6]  768 	inc	sp
                            769 ;src/main.c:404: PrintNumber(spr[0].lives, 1, 8, 17); // lives left 
   4F37 21 CB 4B      [10]  770 	ld	hl, #_spr+9
   4F3A 4E            [ 7]  771 	ld	c, (hl)
   4F3B 06 00         [ 7]  772 	ld	b, #0x00
   4F3D 21 08 11      [10]  773 	ld	hl, #0x1108
   4F40 E5            [11]  774 	push	hl
   4F41 3E 01         [ 7]  775 	ld	a, #0x01
   4F43 F5            [11]  776 	push	af
   4F44 33            [ 6]  777 	inc	sp
   4F45 C5            [11]  778 	push	bc
   4F46 CD FE 4D      [17]  779 	call	_PrintNumber
   4F49 F1            [10]  780 	pop	af
   4F4A F1            [10]  781 	pop	af
   4F4B 33            [ 6]  782 	inc	sp
   4F4C C9            [10]  783 	ret
                            784 ;src/main.c:409: void PrintMap() {
                            785 ;	---------------------------------
                            786 ; Function PrintMap
                            787 ; ---------------------------------
   4F4D                     788 _PrintMap::
                            789 ;src/main.c:410: cpct_etm_drawTilemap2x4(MAP_W, MAP_H, cpctm_screenPtr(CPCT_VMEM_START, 0, ORIG_MAP_Y), UNPACKED_MAP_INI);
   4F4D 21 31 10      [10]  790 	ld	hl, #0x1031
   4F50 E5            [11]  791 	push	hl
   4F51 21 90 C1      [10]  792 	ld	hl, #0xc190
   4F54 E5            [11]  793 	push	hl
   4F55 21 26 28      [10]  794 	ld	hl, #0x2826
   4F58 E5            [11]  795 	push	hl
   4F59 2E 00         [ 7]  796 	ld	l, #0x00
   4F5B E5            [11]  797 	push	hl
   4F5C AF            [ 4]  798 	xor	a, a
   4F5D F5            [11]  799 	push	af
   4F5E 33            [ 6]  800 	inc	sp
   4F5F CD 81 47      [17]  801 	call	_cpct_etm_drawTileBox2x4
   4F62 C9            [10]  802 	ret
                            803 ;src/main.c:415: void InitMap() {
                            804 ;	---------------------------------
                            805 ; Function InitMap
                            806 ; ---------------------------------
   4F63                     807 _InitMap::
                            808 ;src/main.c:416: SetEnemies();
   4F63 CD A2 5D      [17]  809 	call	_SetEnemies
                            810 ;src/main.c:417: PrintMap();
   4F66 C3 4D 4F      [10]  811 	jp  _PrintMap
                            812 ;src/main.c:422: void MoveRightMap() {
                            813 ;	---------------------------------
                            814 ; Function MoveRightMap
                            815 ; ---------------------------------
   4F69                     816 _MoveRightMap::
                            817 ;src/main.c:423: if (mapNumber < TOTAL_MAPS-1) {
   4F69 FD 21 32 4C   [14]  818 	ld	iy, #_mapNumber
   4F6D FD 7E 00      [19]  819 	ld	a, 0 (iy)
   4F70 D6 02         [ 7]  820 	sub	a, #0x02
   4F72 D0            [11]  821 	ret	NC
                            822 ;src/main.c:424: mapNumber++;
   4F73 FD 34 00      [23]  823 	inc	0 (iy)
                            824 ;src/main.c:425: spr[0].x = spr[0].px = 0;
   4F76 21 C4 4B      [10]  825 	ld	hl, #(_spr + 0x0002)
   4F79 36 00         [10]  826 	ld	(hl), #0x00
   4F7B 21 C2 4B      [10]  827 	ld	hl, #_spr
   4F7E 36 00         [10]  828 	ld	(hl), #0x00
                            829 ;src/main.c:426: InitMap();
   4F80 C3 63 4F      [10]  830 	jp  _InitMap
                            831 ;src/main.c:432: void MoveLeftMap() {
                            832 ;	---------------------------------
                            833 ; Function MoveLeftMap
                            834 ; ---------------------------------
   4F83                     835 _MoveLeftMap::
                            836 ;src/main.c:433: if (mapNumber > 0) {
   4F83 FD 21 32 4C   [14]  837 	ld	iy, #_mapNumber
   4F87 FD 7E 00      [19]  838 	ld	a, 0 (iy)
   4F8A B7            [ 4]  839 	or	a, a
   4F8B C8            [11]  840 	ret	Z
                            841 ;src/main.c:434: mapNumber--;
   4F8C FD 35 00      [23]  842 	dec	0 (iy)
                            843 ;src/main.c:435: spr[0].x = spr[0].px = GLOBAL_MAX_X - SPR_W;
   4F8F 21 C4 4B      [10]  844 	ld	hl, #(_spr + 0x0002)
   4F92 36 48         [10]  845 	ld	(hl), #0x48
   4F94 21 C2 4B      [10]  846 	ld	hl, #_spr
   4F97 36 48         [10]  847 	ld	(hl), #0x48
                            848 ;src/main.c:436: InitMap();
   4F99 C3 63 4F      [10]  849 	jp  _InitMap
                            850 ;src/main.c:442: u8* GetTilePtr(u8 x, u8 y) {
                            851 ;	---------------------------------
                            852 ; Function GetTilePtr
                            853 ; ---------------------------------
   4F9C                     854 _GetTilePtr::
   4F9C DD E5         [15]  855 	push	ix
   4F9E DD 21 00 00   [14]  856 	ld	ix,#0
   4FA2 DD 39         [15]  857 	add	ix,sp
                            858 ;src/main.c:443: return UNPACKED_MAP_INI + (y - ORIG_MAP_Y) / 4 * MAP_W + x / 2;	
   4FA4 DD 4E 05      [19]  859 	ld	c, 5 (ix)
   4FA7 06 00         [ 7]  860 	ld	b, #0x00
   4FA9 79            [ 4]  861 	ld	a, c
   4FAA C6 D8         [ 7]  862 	add	a, #0xd8
   4FAC 5F            [ 4]  863 	ld	e, a
   4FAD 78            [ 4]  864 	ld	a, b
   4FAE CE FF         [ 7]  865 	adc	a, #0xff
   4FB0 57            [ 4]  866 	ld	d, a
   4FB1 6B            [ 4]  867 	ld	l, e
   4FB2 62            [ 4]  868 	ld	h, d
   4FB3 CB 7A         [ 8]  869 	bit	7, d
   4FB5 28 04         [12]  870 	jr	Z,00103$
   4FB7 21 DB FF      [10]  871 	ld	hl, #0xffdb
   4FBA 09            [11]  872 	add	hl, bc
   4FBB                     873 00103$:
   4FBB CB 2C         [ 8]  874 	sra	h
   4FBD CB 1D         [ 8]  875 	rr	l
   4FBF CB 2C         [ 8]  876 	sra	h
   4FC1 CB 1D         [ 8]  877 	rr	l
   4FC3 4D            [ 4]  878 	ld	c, l
   4FC4 44            [ 4]  879 	ld	b, h
   4FC5 29            [11]  880 	add	hl, hl
   4FC6 29            [11]  881 	add	hl, hl
   4FC7 09            [11]  882 	add	hl, bc
   4FC8 29            [11]  883 	add	hl, hl
   4FC9 29            [11]  884 	add	hl, hl
   4FCA 29            [11]  885 	add	hl, hl
   4FCB 01 31 10      [10]  886 	ld	bc, #0x1031
   4FCE 09            [11]  887 	add	hl, bc
   4FCF DD 4E 04      [19]  888 	ld	c, 4 (ix)
   4FD2 CB 39         [ 8]  889 	srl	c
   4FD4 59            [ 4]  890 	ld	e,c
   4FD5 16 00         [ 7]  891 	ld	d,#0x00
   4FD7 19            [11]  892 	add	hl, de
   4FD8 DD E1         [14]  893 	pop	ix
   4FDA C9            [10]  894 	ret
                            895 ;src/main.c:448: u8 OnPlatform(TSpr *pSpr) __z88dk_fastcall {
                            896 ;	---------------------------------
                            897 ; Function OnPlatform
                            898 ; ---------------------------------
   4FDB                     899 _OnPlatform::
                            900 ;src/main.c:449: u8* tile = GetTilePtr(pSpr->x + 4, pSpr->y + SPR_H + 1);
   4FDB 4D            [ 4]  901 	ld	c,l
   4FDC 44            [ 4]  902 	ld	b,h
   4FDD 23            [ 6]  903 	inc	hl
   4FDE 7E            [ 7]  904 	ld	a, (hl)
   4FDF C6 11         [ 7]  905 	add	a, #0x11
   4FE1 57            [ 4]  906 	ld	d, a
   4FE2 0A            [ 7]  907 	ld	a, (bc)
   4FE3 C6 04         [ 7]  908 	add	a, #0x04
   4FE5 5F            [ 4]  909 	ld	e, a
   4FE6 D5            [11]  910 	push	de
   4FE7 CD 9C 4F      [17]  911 	call	_GetTilePtr
   4FEA F1            [10]  912 	pop	af
                            913 ;src/main.c:450: if (*tile == 0)
   4FEB 7E            [ 7]  914 	ld	a, (hl)
   4FEC B7            [ 4]  915 	or	a, a
   4FED 20 03         [12]  916 	jr	NZ,00102$
                            917 ;src/main.c:451: return TRUE;	
   4FEF 2E 01         [ 7]  918 	ld	l, #0x01
   4FF1 C9            [10]  919 	ret
   4FF2                     920 00102$:
                            921 ;src/main.c:452: return FALSE;
   4FF2 2E 00         [ 7]  922 	ld	l, #0x00
   4FF4 C9            [10]  923 	ret
                            924 ;src/main.c:457: u8 OnStairs() {
                            925 ;	---------------------------------
                            926 ; Function OnStairs
                            927 ; ---------------------------------
   4FF5                     928 _OnStairs::
                            929 ;src/main.c:458: u8* tile = GetTilePtr(spr[0].x + 4, spr[0].y + SPR_H + 1);
   4FF5 3A C3 4B      [13]  930 	ld	a, (#_spr + 1)
   4FF8 C6 11         [ 7]  931 	add	a, #0x11
   4FFA 47            [ 4]  932 	ld	b, a
   4FFB 3A C2 4B      [13]  933 	ld	a, (#_spr + 0)
   4FFE C6 04         [ 7]  934 	add	a, #0x04
   5000 C5            [11]  935 	push	bc
   5001 33            [ 6]  936 	inc	sp
   5002 F5            [11]  937 	push	af
   5003 33            [ 6]  938 	inc	sp
   5004 CD 9C 4F      [17]  939 	call	_GetTilePtr
   5007 F1            [10]  940 	pop	af
                            941 ;src/main.c:459: if (*tile >  47 && *tile <  56)
   5008 4E            [ 7]  942 	ld	c, (hl)
   5009 3E 2F         [ 7]  943 	ld	a, #0x2f
   500B 91            [ 4]  944 	sub	a, c
   500C 30 08         [12]  945 	jr	NC,00102$
   500E 79            [ 4]  946 	ld	a, c
   500F D6 38         [ 7]  947 	sub	a, #0x38
   5011 30 03         [12]  948 	jr	NC,00102$
                            949 ;src/main.c:460: return TRUE;
   5013 2E 01         [ 7]  950 	ld	l, #0x01
   5015 C9            [10]  951 	ret
   5016                     952 00102$:
                            953 ;src/main.c:461: return FALSE;
   5016 2E 00         [ 7]  954 	ld	l, #0x00
   5018 C9            [10]  955 	ret
                            956 ;src/main.c:466: u8 OverMines() {
                            957 ;	---------------------------------
                            958 ; Function OverMines
                            959 ; ---------------------------------
   5019                     960 _OverMines::
                            961 ;src/main.c:467: u8* tile = GetTilePtr(spr[0].x + 4, spr[0].y + SPR_H);
   5019 3A C3 4B      [13]  962 	ld	a, (#_spr + 1)
   501C C6 10         [ 7]  963 	add	a, #0x10
   501E 47            [ 4]  964 	ld	b, a
   501F 3A C2 4B      [13]  965 	ld	a, (#_spr + 0)
   5022 C6 04         [ 7]  966 	add	a, #0x04
   5024 C5            [11]  967 	push	bc
   5025 33            [ 6]  968 	inc	sp
   5026 F5            [11]  969 	push	af
   5027 33            [ 6]  970 	inc	sp
   5028 CD 9C 4F      [17]  971 	call	_GetTilePtr
   502B F1            [10]  972 	pop	af
                            973 ;src/main.c:468: if (*tile > 55 && *tile < 58) 
   502C 4E            [ 7]  974 	ld	c, (hl)
   502D 3E 37         [ 7]  975 	ld	a, #0x37
   502F 91            [ 4]  976 	sub	a, c
   5030 30 08         [12]  977 	jr	NC,00102$
   5032 79            [ 4]  978 	ld	a, c
   5033 D6 3A         [ 7]  979 	sub	a, #0x3a
   5035 30 03         [12]  980 	jr	NC,00102$
                            981 ;src/main.c:469: return TRUE;	
   5037 2E 01         [ 7]  982 	ld	l, #0x01
   5039 C9            [10]  983 	ret
   503A                     984 00102$:
                            985 ;src/main.c:470: return FALSE;
   503A 2E 00         [ 7]  986 	ld	l, #0x00
   503C C9            [10]  987 	ret
                            988 ;src/main.c:475: u8 FacingWall(u8 dir) __z88dk_fastcall {
                            989 ;	---------------------------------
                            990 ; Function FacingWall
                            991 ; ---------------------------------
   503D                     992 _FacingWall::
   503D 4D            [ 4]  993 	ld	c, l
                            994 ;src/main.c:477: if (dir == D_right)	{
   503E 79            [ 4]  995 	ld	a, c
   503F D6 03         [ 7]  996 	sub	a, #0x03
   5041 20 19         [12]  997 	jr	NZ,00108$
                            998 ;src/main.c:478: tile = GetTilePtr(spr[0].x + 7, spr[0].y + SPR_H);
   5043 3A C3 4B      [13]  999 	ld	a, (#_spr + 1)
   5046 C6 10         [ 7] 1000 	add	a, #0x10
   5048 57            [ 4] 1001 	ld	d, a
   5049 3A C2 4B      [13] 1002 	ld	a, (#_spr + 0)
   504C C6 07         [ 7] 1003 	add	a, #0x07
   504E 5F            [ 4] 1004 	ld	e,a
   504F D5            [11] 1005 	push	de
   5050 CD 9C 4F      [17] 1006 	call	_GetTilePtr
   5053 F1            [10] 1007 	pop	af
                           1008 ;src/main.c:479: if (*tile == 58) return TRUE;
   5054 7E            [ 7] 1009 	ld	a, (hl)
   5055 D6 3A         [ 7] 1010 	sub	a, #0x3a
   5057 20 1F         [12] 1011 	jr	NZ,00109$
   5059 2E 01         [ 7] 1012 	ld	l, #0x01
   505B C9            [10] 1013 	ret
   505C                    1014 00108$:
                           1015 ;src/main.c:481: else if (dir == D_left)	{
   505C 79            [ 4] 1016 	ld	a, c
   505D D6 02         [ 7] 1017 	sub	a, #0x02
   505F 20 17         [12] 1018 	jr	NZ,00109$
                           1019 ;src/main.c:482: tile = GetTilePtr(spr[0].x, spr[0].y + SPR_H);
   5061 3A C3 4B      [13] 1020 	ld	a, (#_spr + 1)
   5064 C6 10         [ 7] 1021 	add	a, #0x10
   5066 57            [ 4] 1022 	ld	d, a
   5067 21 C2 4B      [10] 1023 	ld	hl, #_spr + 0
   506A 5E            [ 7] 1024 	ld	e, (hl)
   506B D5            [11] 1025 	push	de
   506C CD 9C 4F      [17] 1026 	call	_GetTilePtr
   506F F1            [10] 1027 	pop	af
                           1028 ;src/main.c:483: if (*tile == 59) return TRUE;
   5070 7E            [ 7] 1029 	ld	a, (hl)
   5071 D6 3B         [ 7] 1030 	sub	a, #0x3b
   5073 20 03         [12] 1031 	jr	NZ,00109$
   5075 2E 01         [ 7] 1032 	ld	l, #0x01
   5077 C9            [10] 1033 	ret
   5078                    1034 00109$:
                           1035 ;src/main.c:485: return FALSE;
   5078 2E 00         [ 7] 1036 	ld	l, #0x00
   507A C9            [10] 1037 	ret
                           1038 ;src/main.c:502: cpct_keyID ReturnKeyPressed() {
                           1039 ;	---------------------------------
                           1040 ; Function ReturnKeyPressed
                           1041 ; ---------------------------------
   507B                    1042 _ReturnKeyPressed::
   507B DD E5         [15] 1043 	push	ix
   507D DD 21 00 00   [14] 1044 	ld	ix,#0
   5081 DD 39         [15] 1045 	add	ix,sp
   5083 F5            [11] 1046 	push	af
   5084 3B            [ 6] 1047 	dec	sp
                           1048 ;src/main.c:503: u8 i = 10, *keys = cpct_keyboardStatusBuffer + 9;
   5085 0E 0A         [ 7] 1049 	ld	c, #0x0a
                           1050 ;src/main.c:506: do { cpct_scanKeyboard(); } while ( ! cpct_isAnyKeyPressed() );
   5087                    1051 00101$:
   5087 C5            [11] 1052 	push	bc
   5088 CD FB 4A      [17] 1053 	call	_cpct_scanKeyboard
   508B CD 56 48      [17] 1054 	call	_cpct_isAnyKeyPressed
   508E C1            [10] 1055 	pop	bc
   508F 7D            [ 4] 1056 	ld	a, l
   5090 B7            [ 4] 1057 	or	a, a
   5091 28 F4         [12] 1058 	jr	Z,00101$
                           1059 ;src/main.c:508: do {
   5093 DD 36 FE 34   [19] 1060 	ld	-2 (ix), #<((_cpct_keyboardStatusBuffer + 0x0009))
   5097 DD 36 FF 48   [19] 1061 	ld	-1 (ix), #>((_cpct_keyboardStatusBuffer + 0x0009))
   509B DD 36 FD 0A   [19] 1062 	ld	-3 (ix), #0x0a
   509F                    1063 00106$:
                           1064 ;src/main.c:509: keypressed = *keys ^ 0xFF;
   509F DD 6E FE      [19] 1065 	ld	l,-2 (ix)
   50A2 DD 66 FF      [19] 1066 	ld	h,-1 (ix)
   50A5 7E            [ 7] 1067 	ld	a, (hl)
   50A6 EE FF         [ 7] 1068 	xor	a, #0xff
   50A8 6F            [ 4] 1069 	ld	l, a
   50A9 26 00         [ 7] 1070 	ld	h, #0x00
                           1071 ;src/main.c:510: if (keypressed)
   50AB 7C            [ 4] 1072 	ld	a, h
   50AC B5            [ 4] 1073 	or	a,l
   50AD 28 09         [12] 1074 	jr	Z,00105$
                           1075 ;src/main.c:511: return (keypressed << 8) + (i - 1); 
   50AF 65            [ 4] 1076 	ld	h, l
   50B0 2E 00         [ 7] 1077 	ld	l, #0x00
   50B2 06 00         [ 7] 1078 	ld	b, #0x00
   50B4 0B            [ 6] 1079 	dec	bc
   50B5 09            [11] 1080 	add	hl, bc
   50B6 18 1C         [12] 1081 	jr	00109$
   50B8                    1082 00105$:
                           1083 ;src/main.c:512: keys--;
   50B8 DD 7E FE      [19] 1084 	ld	a, -2 (ix)
   50BB C6 FF         [ 7] 1085 	add	a, #0xff
   50BD DD 77 FE      [19] 1086 	ld	-2 (ix), a
   50C0 DD 7E FF      [19] 1087 	ld	a, -1 (ix)
   50C3 CE FF         [ 7] 1088 	adc	a, #0xff
   50C5 DD 77 FF      [19] 1089 	ld	-1 (ix), a
                           1090 ;src/main.c:513: } while(--i);
   50C8 DD 35 FD      [23] 1091 	dec	-3 (ix)
   50CB DD 4E FD      [19] 1092 	ld	c, -3 (ix)
   50CE DD 7E FD      [19] 1093 	ld	a, -3 (ix)
   50D1 B7            [ 4] 1094 	or	a, a
   50D2 20 CB         [12] 1095 	jr	NZ,00106$
                           1096 ;src/main.c:514: return keypressed;    
   50D4                    1097 00109$:
   50D4 DD F9         [10] 1098 	ld	sp, ix
   50D6 DD E1         [14] 1099 	pop	ix
   50D8 C9            [10] 1100 	ret
                           1101 ;src/main.c:520: void Wait4Key(cpct_keyID key) __z88dk_fastcall {
                           1102 ;	---------------------------------
                           1103 ; Function Wait4Key
                           1104 ; ---------------------------------
   50D9                    1105 _Wait4Key::
                           1106 ;src/main.c:521: do cpct_scanKeyboard_f();
   50D9                    1107 00101$:
   50D9 E5            [11] 1108 	push	hl
   50DA CD 3D 3E      [17] 1109 	call	_cpct_scanKeyboard_f
   50DD E1            [10] 1110 	pop	hl
                           1111 ;src/main.c:522: while(!cpct_isKeyPressed(key));
   50DE E5            [11] 1112 	push	hl
   50DF CD 31 3E      [17] 1113 	call	_cpct_isKeyPressed
   50E2 7D            [ 4] 1114 	ld	a, l
   50E3 E1            [10] 1115 	pop	hl
   50E4 B7            [ 4] 1116 	or	a, a
   50E5 28 F2         [12] 1117 	jr	Z,00101$
                           1118 ;src/main.c:523: do cpct_scanKeyboard_f();
   50E7                    1119 00104$:
   50E7 E5            [11] 1120 	push	hl
   50E8 CD 3D 3E      [17] 1121 	call	_cpct_scanKeyboard_f
   50EB E1            [10] 1122 	pop	hl
                           1123 ;src/main.c:524: while(cpct_isKeyPressed(key));
   50EC E5            [11] 1124 	push	hl
   50ED CD 31 3E      [17] 1125 	call	_cpct_isKeyPressed
   50F0 7D            [ 4] 1126 	ld	a, l
   50F1 E1            [10] 1127 	pop	hl
   50F2 B7            [ 4] 1128 	or	a, a
   50F3 20 F2         [12] 1129 	jr	NZ,00104$
   50F5 C9            [10] 1130 	ret
                           1131 ;src/main.c:529: cpct_keyID RedefineKey(u8 *info) __z88dk_fastcall {
                           1132 ;	---------------------------------
                           1133 ; Function RedefineKey
                           1134 ; ---------------------------------
   50F6                    1135 _RedefineKey::
                           1136 ;src/main.c:531: PrintText(info, 29, 100);  
   50F6 01 1D 64      [10] 1137 	ld	bc, #0x641d
   50F9 C5            [11] 1138 	push	bc
   50FA E5            [11] 1139 	push	hl
   50FB CD 90 4E      [17] 1140 	call	_PrintText
   50FE F1            [10] 1141 	pop	af
   50FF F1            [10] 1142 	pop	af
                           1143 ;src/main.c:532: key = ReturnKeyPressed();
   5100 CD 7B 50      [17] 1144 	call	_ReturnKeyPressed
                           1145 ;src/main.c:533: Wait4Key(key);
   5103 E5            [11] 1146 	push	hl
   5104 CD D9 50      [17] 1147 	call	_Wait4Key
   5107 3E 02         [ 7] 1148 	ld	a, #0x02
   5109 F5            [11] 1149 	push	af
   510A 33            [ 6] 1150 	inc	sp
   510B 01 00 00      [10] 1151 	ld	bc, #0x0000
   510E C5            [11] 1152 	push	bc
   510F 01 29 00      [10] 1153 	ld	bc, #0x0029
   5112 C5            [11] 1154 	push	bc
   5113 01 02 0F      [10] 1155 	ld	bc, #0x0f02
   5116 C5            [11] 1156 	push	bc
   5117 CD 5F 46      [17] 1157 	call	_cpct_akp_SFXPlay
   511A 21 07 00      [10] 1158 	ld	hl, #7
   511D 39            [11] 1159 	add	hl, sp
   511E F9            [ 6] 1160 	ld	sp, hl
   511F E1            [10] 1161 	pop	hl
                           1162 ;src/main.c:535: return key;    
   5120 C9            [10] 1163 	ret
                           1164 ;src/main.c:552: void PrintObject(u8 ident, u8 x, u8 y) {
                           1165 ;	---------------------------------
                           1166 ; Function PrintObject
                           1167 ; ---------------------------------
   5121                    1168 _PrintObject::
   5121 DD E5         [15] 1169 	push	ix
   5123 DD 21 00 00   [14] 1170 	ld	ix,#0
   5127 DD 39         [15] 1171 	add	ix,sp
                           1172 ;src/main.c:554: OBJ_W, OBJ_H, g_maskTable);
                           1173 ;src/main.c:553: cpct_drawSpriteMaskedAlignedTable(g_objects[ident], cpct_getScreenPtr(CPCT_VMEM_START, x, y),
   5129 DD 66 06      [19] 1174 	ld	h, 6 (ix)
   512C DD 6E 05      [19] 1175 	ld	l, 5 (ix)
   512F E5            [11] 1176 	push	hl
   5130 21 00 C0      [10] 1177 	ld	hl, #0xc000
   5133 E5            [11] 1178 	push	hl
   5134 CD AA 4A      [17] 1179 	call	_cpct_getScreenPtr
   5137 4D            [ 4] 1180 	ld	c, l
   5138 44            [ 4] 1181 	ld	b, h
   5139 DD 5E 04      [19] 1182 	ld	e,4 (ix)
   513C 16 00         [ 7] 1183 	ld	d,#0x00
   513E 6B            [ 4] 1184 	ld	l, e
   513F 62            [ 4] 1185 	ld	h, d
   5140 29            [11] 1186 	add	hl, hl
   5141 19            [11] 1187 	add	hl, de
   5142 29            [11] 1188 	add	hl, hl
   5143 29            [11] 1189 	add	hl, hl
   5144 29            [11] 1190 	add	hl, hl
   5145 29            [11] 1191 	add	hl, hl
   5146 29            [11] 1192 	add	hl, hl
   5147 11 19 35      [10] 1193 	ld	de, #_g_objects
   514A 19            [11] 1194 	add	hl, de
   514B 11 00 01      [10] 1195 	ld	de, #_g_maskTable
   514E D5            [11] 1196 	push	de
   514F 11 06 10      [10] 1197 	ld	de, #0x1006
   5152 D5            [11] 1198 	push	de
   5153 C5            [11] 1199 	push	bc
   5154 E5            [11] 1200 	push	hl
   5155 CD C0 4A      [17] 1201 	call	_cpct_drawSpriteMaskedAlignedTable
   5158 DD E1         [14] 1202 	pop	ix
   515A C9            [10] 1203 	ret
                           1204 ;src/main.c:559: void DeleteObject(TObj *pObj) __z88dk_fastcall {
                           1205 ;	---------------------------------
                           1206 ; Function DeleteObject
                           1207 ; ---------------------------------
   515B                    1208 _DeleteObject::
   515B DD E5         [15] 1209 	push	ix
   515D DD 21 00 00   [14] 1210 	ld	ix,#0
   5161 DD 39         [15] 1211 	add	ix,sp
   5163 F5            [11] 1212 	push	af
   5164 3B            [ 6] 1213 	dec	sp
                           1214 ;src/main.c:561: 4 + (pObj->x & 1),	4 + (pObj->y & 3 ? 1 : 0),	
   5165 4D            [ 4] 1215 	ld	c,l
   5166 44            [ 4] 1216 	ld	b,h
   5167 23            [ 6] 1217 	inc	hl
   5168 5E            [ 7] 1218 	ld	e, (hl)
   5169 7B            [ 4] 1219 	ld	a, e
   516A E6 03         [ 7] 1220 	and	a, #0x03
   516C 28 04         [12] 1221 	jr	Z,00103$
   516E 3E 01         [ 7] 1222 	ld	a, #0x01
   5170 18 02         [12] 1223 	jr	00104$
   5172                    1224 00103$:
   5172 3E 00         [ 7] 1225 	ld	a, #0x00
   5174                    1226 00104$:
   5174 C6 04         [ 7] 1227 	add	a, #0x04
   5176 DD 77 FF      [19] 1228 	ld	-1 (ix), a
   5179 0A            [ 7] 1229 	ld	a, (bc)
   517A 4F            [ 4] 1230 	ld	c,a
   517B E6 01         [ 7] 1231 	and	a, #0x01
   517D 47            [ 4] 1232 	ld	b, a
   517E 04            [ 4] 1233 	inc	b
   517F 04            [ 4] 1234 	inc	b
   5180 04            [ 4] 1235 	inc	b
   5181 04            [ 4] 1236 	inc	b
                           1237 ;src/main.c:560: cpct_etm_drawTileBox2x4(pObj->x / 2, (pObj->y - ORIG_MAP_Y) / 4, 
   5182 16 00         [ 7] 1238 	ld	d, #0x00
   5184 7B            [ 4] 1239 	ld	a, e
   5185 C6 D8         [ 7] 1240 	add	a, #0xd8
   5187 DD 77 FD      [19] 1241 	ld	-3 (ix), a
   518A 7A            [ 4] 1242 	ld	a, d
   518B CE FF         [ 7] 1243 	adc	a, #0xff
   518D DD 77 FE      [19] 1244 	ld	-2 (ix), a
   5190 E1            [10] 1245 	pop	hl
   5191 E5            [11] 1246 	push	hl
   5192 DD CB FE 7E   [20] 1247 	bit	7, -2 (ix)
   5196 28 04         [12] 1248 	jr	Z,00105$
   5198 21 DB FF      [10] 1249 	ld	hl, #0xffdb
   519B 19            [11] 1250 	add	hl, de
   519C                    1251 00105$:
   519C CB 2C         [ 8] 1252 	sra	h
   519E CB 1D         [ 8] 1253 	rr	l
   51A0 CB 2C         [ 8] 1254 	sra	h
   51A2 CB 1D         [ 8] 1255 	rr	l
   51A4 5D            [ 4] 1256 	ld	e, l
   51A5 CB 39         [ 8] 1257 	srl	c
   51A7 21 31 10      [10] 1258 	ld	hl, #0x1031
   51AA E5            [11] 1259 	push	hl
   51AB 21 90 C1      [10] 1260 	ld	hl, #0xc190
   51AE E5            [11] 1261 	push	hl
   51AF 3E 28         [ 7] 1262 	ld	a, #0x28
   51B1 F5            [11] 1263 	push	af
   51B2 33            [ 6] 1264 	inc	sp
   51B3 DD 7E FF      [19] 1265 	ld	a, -1 (ix)
   51B6 F5            [11] 1266 	push	af
   51B7 33            [ 6] 1267 	inc	sp
   51B8 C5            [11] 1268 	push	bc
   51B9 33            [ 6] 1269 	inc	sp
   51BA 43            [ 4] 1270 	ld	b, e
   51BB C5            [11] 1271 	push	bc
   51BC CD 81 47      [17] 1272 	call	_cpct_etm_drawTileBox2x4
   51BF DD F9         [10] 1273 	ld	sp, ix
   51C1 DD E1         [14] 1274 	pop	ix
   51C3 C9            [10] 1275 	ret
                           1276 ;src/main.c:567: void DeleteObjectScoreboard() {
                           1277 ;	---------------------------------
                           1278 ; Function DeleteObjectScoreboard
                           1279 ; ---------------------------------
   51C4                    1280 _DeleteObjectScoreboard::
                           1281 ;src/main.c:568: cpct_drawSolidBox(cpctm_screenPtr(CPCT_VMEM_START, 68, 12), cpct_px2byteM0(1,1), 6, 16);
   51C4 21 01 01      [10] 1282 	ld	hl, #0x0101
   51C7 E5            [11] 1283 	push	hl
   51C8 CD 8E 49      [17] 1284 	call	_cpct_px2byteM0
   51CB 26 00         [ 7] 1285 	ld	h, #0x00
   51CD 01 06 10      [10] 1286 	ld	bc, #0x1006
   51D0 C5            [11] 1287 	push	bc
   51D1 E5            [11] 1288 	push	hl
   51D2 21 94 E0      [10] 1289 	ld	hl, #0xe094
   51D5 E5            [11] 1290 	push	hl
   51D6 CD C8 49      [17] 1291 	call	_cpct_drawSolidBox
   51D9 C9            [10] 1292 	ret
                           1293 ;src/main.c:573: void ReprintObjects() {
                           1294 ;	---------------------------------
                           1295 ; Function ReprintObjects
                           1296 ; ---------------------------------
   51DA                    1297 _ReprintObjects::
   51DA DD E5         [15] 1298 	push	ix
   51DC DD 21 00 00   [14] 1299 	ld	ix,#0
   51E0 DD 39         [15] 1300 	add	ix,sp
   51E2 F5            [11] 1301 	push	af
                           1302 ;src/main.c:574: ct = 0;
   51E3 21 B1 4B      [10] 1303 	ld	hl,#_ct + 0
   51E6 36 00         [10] 1304 	ld	(hl), #0x00
                           1305 ;src/main.c:575: while (ct < N_MAX_OBJ) {
   51E8                    1306 00104$:
   51E8 FD 21 B1 4B   [14] 1307 	ld	iy, #_ct
   51EC FD 7E 00      [19] 1308 	ld	a, 0 (iy)
   51EF D6 08         [ 7] 1309 	sub	a, #0x08
   51F1 30 38         [12] 1310 	jr	NC,00107$
                           1311 ;src/main.c:576: if (obj[ct].mapNumber == mapNumber && obj[ct].taken == FALSE)
   51F3 FD 6E 00      [19] 1312 	ld	l, 0 (iy)
   51F6 26 00         [ 7] 1313 	ld	h, #0x00
   51F8 29            [11] 1314 	add	hl, hl
   51F9 29            [11] 1315 	add	hl, hl
   51FA 01 0E 4C      [10] 1316 	ld	bc,#_obj
   51FD 09            [11] 1317 	add	hl,bc
   51FE E3            [19] 1318 	ex	(sp), hl
   51FF E1            [10] 1319 	pop	hl
   5200 E5            [11] 1320 	push	hl
   5201 23            [ 6] 1321 	inc	hl
   5202 23            [ 6] 1322 	inc	hl
   5203 4E            [ 7] 1323 	ld	c, (hl)
   5204 3A 32 4C      [13] 1324 	ld	a,(#_mapNumber + 0)
   5207 91            [ 4] 1325 	sub	a, c
   5208 20 1B         [12] 1326 	jr	NZ,00102$
   520A E1            [10] 1327 	pop	hl
   520B E5            [11] 1328 	push	hl
   520C 23            [ 6] 1329 	inc	hl
   520D 23            [ 6] 1330 	inc	hl
   520E 23            [ 6] 1331 	inc	hl
   520F 7E            [ 7] 1332 	ld	a, (hl)
   5210 B7            [ 4] 1333 	or	a, a
   5211 20 12         [12] 1334 	jr	NZ,00102$
                           1335 ;src/main.c:577: PrintObject(ct, obj[ct].x, obj[ct].y);
   5213 E1            [10] 1336 	pop	hl
   5214 E5            [11] 1337 	push	hl
   5215 23            [ 6] 1338 	inc	hl
   5216 46            [ 7] 1339 	ld	b, (hl)
   5217 E1            [10] 1340 	pop	hl
   5218 E5            [11] 1341 	push	hl
   5219 4E            [ 7] 1342 	ld	c, (hl)
   521A C5            [11] 1343 	push	bc
   521B 3A B1 4B      [13] 1344 	ld	a, (_ct)
   521E F5            [11] 1345 	push	af
   521F 33            [ 6] 1346 	inc	sp
   5220 CD 21 51      [17] 1347 	call	_PrintObject
   5223 F1            [10] 1348 	pop	af
   5224 33            [ 6] 1349 	inc	sp
   5225                    1350 00102$:
                           1351 ;src/main.c:578: ct++;
   5225 21 B1 4B      [10] 1352 	ld	hl, #_ct+0
   5228 34            [11] 1353 	inc	(hl)
   5229 18 BD         [12] 1354 	jr	00104$
   522B                    1355 00107$:
   522B DD F9         [10] 1356 	ld	sp, ix
   522D DD E1         [14] 1357 	pop	ix
   522F C9            [10] 1358 	ret
                           1359 ;src/main.c:584: void CheckObjects() {
                           1360 ;	---------------------------------
                           1361 ; Function CheckObjects
                           1362 ; ---------------------------------
   5230                    1363 _CheckObjects::
   5230 DD E5         [15] 1364 	push	ix
   5232 DD 21 00 00   [14] 1365 	ld	ix,#0
   5236 DD 39         [15] 1366 	add	ix,sp
   5238 F5            [11] 1367 	push	af
                           1368 ;src/main.c:585: ct = 0;
   5239 21 B1 4B      [10] 1369 	ld	hl,#_ct + 0
   523C 36 00         [10] 1370 	ld	(hl), #0x00
                           1371 ;src/main.c:586: Wait4Key(ctlDown);
   523E 2A B4 4B      [16] 1372 	ld	hl, (_ctlDown)
   5241 CD D9 50      [17] 1373 	call	_Wait4Key
                           1374 ;src/main.c:587: while (ct < N_MAX_OBJ) {
   5244                    1375 00120$:
   5244 FD 21 B1 4B   [14] 1376 	ld	iy, #_ct
   5248 FD 7E 00      [19] 1377 	ld	a, 0 (iy)
   524B D6 08         [ 7] 1378 	sub	a, #0x08
   524D D2 E8 53      [10] 1379 	jp	NC, 00123$
                           1380 ;src/main.c:588: if (obj[ct].mapNumber == mapNumber) { // if the object is on the screen ...
   5250 FD 6E 00      [19] 1381 	ld	l, 0 (iy)
   5253 26 00         [ 7] 1382 	ld	h, #0x00
   5255 29            [11] 1383 	add	hl, hl
   5256 29            [11] 1384 	add	hl, hl
   5257 01 0E 4C      [10] 1385 	ld	bc,#_obj
   525A 09            [11] 1386 	add	hl,bc
   525B E3            [19] 1387 	ex	(sp), hl
   525C E1            [10] 1388 	pop	hl
   525D E5            [11] 1389 	push	hl
   525E 23            [ 6] 1390 	inc	hl
   525F 23            [ 6] 1391 	inc	hl
   5260 4E            [ 7] 1392 	ld	c, (hl)
   5261 3A 32 4C      [13] 1393 	ld	a,(#_mapNumber + 0)
   5264 91            [ 4] 1394 	sub	a, c
   5265 C2 E1 53      [10] 1395 	jp	NZ,00119$
                           1396 ;src/main.c:590: if (spr[0].x >= obj[ct].x - 3 && spr[0].x <= obj[ct].x + 3 &&	
   5268 21 C2 4B      [10] 1397 	ld	hl, #_spr + 0
   526B 4E            [ 7] 1398 	ld	c, (hl)
   526C E1            [10] 1399 	pop	hl
   526D E5            [11] 1400 	push	hl
   526E 5E            [ 7] 1401 	ld	e, (hl)
   526F 16 00         [ 7] 1402 	ld	d, #0x00
   5271 7B            [ 4] 1403 	ld	a, e
   5272 C6 FD         [ 7] 1404 	add	a, #0xfd
   5274 6F            [ 4] 1405 	ld	l, a
   5275 7A            [ 4] 1406 	ld	a, d
   5276 CE FF         [ 7] 1407 	adc	a, #0xff
   5278 67            [ 4] 1408 	ld	h, a
   5279 06 00         [ 7] 1409 	ld	b, #0x00
   527B 79            [ 4] 1410 	ld	a, c
   527C 95            [ 4] 1411 	sub	a, l
   527D 78            [ 4] 1412 	ld	a, b
   527E 9C            [ 4] 1413 	sbc	a, h
   527F E2 84 52      [10] 1414 	jp	PO, 00175$
   5282 EE 80         [ 7] 1415 	xor	a, #0x80
   5284                    1416 00175$:
   5284 FA E1 53      [10] 1417 	jp	M, 00119$
   5287 13            [ 6] 1418 	inc	de
   5288 13            [ 6] 1419 	inc	de
   5289 13            [ 6] 1420 	inc	de
   528A 6A            [ 4] 1421 	ld	l, d
   528B 7B            [ 4] 1422 	ld	a, e
   528C 91            [ 4] 1423 	sub	a, c
   528D 7D            [ 4] 1424 	ld	a, l
   528E 98            [ 4] 1425 	sbc	a, b
   528F E2 94 52      [10] 1426 	jp	PO, 00176$
   5292 EE 80         [ 7] 1427 	xor	a, #0x80
   5294                    1428 00176$:
   5294 FA E1 53      [10] 1429 	jp	M, 00119$
                           1430 ;src/main.c:591: spr[0].y >= obj[ct].y - 4 && spr[0].y <= obj[ct].y + 4) {
   5297 21 C3 4B      [10] 1431 	ld	hl, #_spr + 1
   529A 4E            [ 7] 1432 	ld	c, (hl)
   529B E1            [10] 1433 	pop	hl
   529C E5            [11] 1434 	push	hl
   529D 23            [ 6] 1435 	inc	hl
   529E 5E            [ 7] 1436 	ld	e, (hl)
   529F 16 00         [ 7] 1437 	ld	d, #0x00
   52A1 7B            [ 4] 1438 	ld	a, e
   52A2 C6 FC         [ 7] 1439 	add	a, #0xfc
   52A4 6F            [ 4] 1440 	ld	l, a
   52A5 7A            [ 4] 1441 	ld	a, d
   52A6 CE FF         [ 7] 1442 	adc	a, #0xff
   52A8 47            [ 4] 1443 	ld	b, a
   52A9 26 00         [ 7] 1444 	ld	h, #0x00
   52AB 79            [ 4] 1445 	ld	a, c
   52AC 95            [ 4] 1446 	sub	a, l
   52AD 7C            [ 4] 1447 	ld	a, h
   52AE 98            [ 4] 1448 	sbc	a, b
   52AF E2 B4 52      [10] 1449 	jp	PO, 00177$
   52B2 EE 80         [ 7] 1450 	xor	a, #0x80
   52B4                    1451 00177$:
   52B4 FA E1 53      [10] 1452 	jp	M, 00119$
   52B7 13            [ 6] 1453 	inc	de
   52B8 13            [ 6] 1454 	inc	de
   52B9 13            [ 6] 1455 	inc	de
   52BA 13            [ 6] 1456 	inc	de
   52BB 7B            [ 4] 1457 	ld	a, e
   52BC 91            [ 4] 1458 	sub	a, c
   52BD 7A            [ 4] 1459 	ld	a, d
   52BE 9C            [ 4] 1460 	sbc	a, h
   52BF E2 C4 52      [10] 1461 	jp	PO, 00178$
   52C2 EE 80         [ 7] 1462 	xor	a, #0x80
   52C4                    1463 00178$:
   52C4 FA E1 53      [10] 1464 	jp	M, 00119$
                           1465 ;src/main.c:592: if (ct > 5) { // first aid kit					
   52C7 3E 05         [ 7] 1466 	ld	a, #0x05
   52C9 FD 21 B1 4B   [14] 1467 	ld	iy, #_ct
   52CD FD 96 00      [19] 1468 	sub	a, 0 (iy)
   52D0 30 56         [12] 1469 	jr	NC,00111$
                           1470 ;src/main.c:593: if (obj[ct].taken == FALSE) {
   52D2 E1            [10] 1471 	pop	hl
   52D3 E5            [11] 1472 	push	hl
   52D4 23            [ 6] 1473 	inc	hl
   52D5 23            [ 6] 1474 	inc	hl
   52D6 23            [ 6] 1475 	inc	hl
   52D7 7E            [ 7] 1476 	ld	a, (hl)
   52D8 B7            [ 4] 1477 	or	a, a
   52D9 C2 DC 53      [10] 1478 	jp	NZ, 00112$
                           1479 ;src/main.c:594: cpct_akp_SFXPlay (6, 12, 41, 0, 0, AY_CHANNEL_A);
   52DC 3E 01         [ 7] 1480 	ld	a, #0x01
   52DE F5            [11] 1481 	push	af
   52DF 33            [ 6] 1482 	inc	sp
   52E0 21 00 00      [10] 1483 	ld	hl, #0x0000
   52E3 E5            [11] 1484 	push	hl
   52E4 2E 29         [ 7] 1485 	ld	l, #0x29
   52E6 E5            [11] 1486 	push	hl
   52E7 21 06 0C      [10] 1487 	ld	hl, #0x0c06
   52EA E5            [11] 1488 	push	hl
   52EB CD 5F 46      [17] 1489 	call	_cpct_akp_SFXPlay
   52EE 21 07 00      [10] 1490 	ld	hl, #7
   52F1 39            [11] 1491 	add	hl, sp
   52F2 F9            [ 6] 1492 	ld	sp, hl
                           1493 ;src/main.c:595: if (ct == 6) spr[0].lives = 9; // first aid kit
   52F3 3A B1 4B      [13] 1494 	ld	a,(#_ct + 0)
   52F6 D6 06         [ 7] 1495 	sub	a, #0x06
   52F8 20 05         [12] 1496 	jr	NZ,00102$
   52FA 21 CB 4B      [10] 1497 	ld	hl, #(_spr + 0x0009)
   52FD 36 09         [10] 1498 	ld	(hl), #0x09
   52FF                    1499 00102$:
                           1500 ;src/main.c:596: DeleteObject(&obj[ct]); 
   52FF FD 21 B1 4B   [14] 1501 	ld	iy, #_ct
   5303 FD 6E 00      [19] 1502 	ld	l, 0 (iy)
   5306 26 00         [ 7] 1503 	ld	h, #0x00
   5308 29            [11] 1504 	add	hl, hl
   5309 29            [11] 1505 	add	hl, hl
   530A 11 0E 4C      [10] 1506 	ld	de, #_obj
   530D 19            [11] 1507 	add	hl, de
   530E CD 5B 51      [17] 1508 	call	_DeleteObject
                           1509 ;src/main.c:598: obj[ct].taken = TRUE;
   5311 FD 21 B1 4B   [14] 1510 	ld	iy, #_ct
   5315 FD 6E 00      [19] 1511 	ld	l, 0 (iy)
   5318 26 00         [ 7] 1512 	ld	h, #0x00
   531A 29            [11] 1513 	add	hl, hl
   531B 29            [11] 1514 	add	hl, hl
   531C 11 0E 4C      [10] 1515 	ld	de, #_obj
   531F 19            [11] 1516 	add	hl, de
   5320 23            [ 6] 1517 	inc	hl
   5321 23            [ 6] 1518 	inc	hl
   5322 23            [ 6] 1519 	inc	hl
   5323 36 01         [10] 1520 	ld	(hl), #0x01
   5325 C3 DC 53      [10] 1521 	jp	00112$
   5328                    1522 00111$:
                           1523 ;src/main.c:602: else if (spr[0].object != ct) {
   5328 21 CE 4B      [10] 1524 	ld	hl, #(_spr + 0x000c) + 0
   532B 4E            [ 7] 1525 	ld	c, (hl)
   532C 3A B1 4B      [13] 1526 	ld	a,(#_ct + 0)
   532F 91            [ 4] 1527 	sub	a, c
   5330 28 57         [12] 1528 	jr	Z,00108$
                           1529 ;src/main.c:604: if (spr[0].object == 255) {	
   5332 0C            [ 4] 1530 	inc	c
   5333 C2 DC 53      [10] 1531 	jp	NZ,00112$
                           1532 ;src/main.c:605: cpct_akp_SFXPlay(8, 15, 45, 0, 0, AY_CHANNEL_A);
   5336 3E 01         [ 7] 1533 	ld	a, #0x01
   5338 F5            [11] 1534 	push	af
   5339 33            [ 6] 1535 	inc	sp
   533A 21 00 00      [10] 1536 	ld	hl, #0x0000
   533D E5            [11] 1537 	push	hl
   533E 2E 2D         [ 7] 1538 	ld	l, #0x2d
   5340 E5            [11] 1539 	push	hl
   5341 21 08 0F      [10] 1540 	ld	hl, #0x0f08
   5344 E5            [11] 1541 	push	hl
   5345 CD 5F 46      [17] 1542 	call	_cpct_akp_SFXPlay
   5348 21 07 00      [10] 1543 	ld	hl, #7
   534B 39            [11] 1544 	add	hl, sp
   534C F9            [ 6] 1545 	ld	sp, hl
                           1546 ;src/main.c:606: spr[0].object = ct;
   534D 21 CE 4B      [10] 1547 	ld	hl, #(_spr + 0x000c)
   5350 FD 21 B1 4B   [14] 1548 	ld	iy, #_ct
   5354 FD 7E 00      [19] 1549 	ld	a, 0 (iy)
   5357 77            [ 7] 1550 	ld	(hl), a
                           1551 ;src/main.c:607: obj[ct].taken = TRUE;
   5358 FD 6E 00      [19] 1552 	ld	l, 0 (iy)
   535B 26 00         [ 7] 1553 	ld	h, #0x00
   535D 29            [11] 1554 	add	hl, hl
   535E 29            [11] 1555 	add	hl, hl
   535F 11 0E 4C      [10] 1556 	ld	de, #_obj
   5362 19            [11] 1557 	add	hl, de
   5363 23            [ 6] 1558 	inc	hl
   5364 23            [ 6] 1559 	inc	hl
   5365 23            [ 6] 1560 	inc	hl
   5366 36 01         [10] 1561 	ld	(hl), #0x01
                           1562 ;src/main.c:608: DeleteObject(&obj[ct]); 
   5368 FD 6E 00      [19] 1563 	ld	l, 0 (iy)
   536B 26 00         [ 7] 1564 	ld	h, #0x00
   536D 29            [11] 1565 	add	hl, hl
   536E 29            [11] 1566 	add	hl, hl
   536F 11 0E 4C      [10] 1567 	ld	de, #_obj
   5372 19            [11] 1568 	add	hl, de
   5373 CD 5B 51      [17] 1569 	call	_DeleteObject
                           1570 ;src/main.c:610: DeleteObjectScoreboard(); PrintObject(ct, 68, 12); 
   5376 CD C4 51      [17] 1571 	call	_DeleteObjectScoreboard
   5379 21 44 0C      [10] 1572 	ld	hl, #0x0c44
   537C E5            [11] 1573 	push	hl
   537D 3A B1 4B      [13] 1574 	ld	a, (_ct)
   5380 F5            [11] 1575 	push	af
   5381 33            [ 6] 1576 	inc	sp
   5382 CD 21 51      [17] 1577 	call	_PrintObject
   5385 F1            [10] 1578 	pop	af
   5386 33            [ 6] 1579 	inc	sp
   5387 18 53         [12] 1580 	jr	00112$
   5389                    1581 00108$:
                           1582 ;src/main.c:614: cpct_akp_SFXPlay(7, 15, 45, 0, 0, AY_CHANNEL_A);
   5389 3E 01         [ 7] 1583 	ld	a, #0x01
   538B F5            [11] 1584 	push	af
   538C 33            [ 6] 1585 	inc	sp
   538D 21 00 00      [10] 1586 	ld	hl, #0x0000
   5390 E5            [11] 1587 	push	hl
   5391 2E 2D         [ 7] 1588 	ld	l, #0x2d
   5393 E5            [11] 1589 	push	hl
   5394 21 07 0F      [10] 1590 	ld	hl, #0x0f07
   5397 E5            [11] 1591 	push	hl
   5398 CD 5F 46      [17] 1592 	call	_cpct_akp_SFXPlay
   539B 21 07 00      [10] 1593 	ld	hl, #7
   539E 39            [11] 1594 	add	hl, sp
   539F F9            [ 6] 1595 	ld	sp, hl
                           1596 ;src/main.c:616: PrintObject(ct, obj[ct].x, obj[ct].y);	
   53A0 FD 21 B1 4B   [14] 1597 	ld	iy, #_ct
   53A4 FD 6E 00      [19] 1598 	ld	l, 0 (iy)
   53A7 26 00         [ 7] 1599 	ld	h, #0x00
   53A9 29            [11] 1600 	add	hl, hl
   53AA 29            [11] 1601 	add	hl, hl
   53AB 01 0E 4C      [10] 1602 	ld	bc,#_obj
   53AE 09            [11] 1603 	add	hl,bc
   53AF 4D            [ 4] 1604 	ld	c,l
   53B0 44            [ 4] 1605 	ld	b,h
   53B1 23            [ 6] 1606 	inc	hl
   53B2 56            [ 7] 1607 	ld	d, (hl)
   53B3 0A            [ 7] 1608 	ld	a, (bc)
   53B4 5F            [ 4] 1609 	ld	e,a
   53B5 D5            [11] 1610 	push	de
   53B6 3A B1 4B      [13] 1611 	ld	a, (_ct)
   53B9 F5            [11] 1612 	push	af
   53BA 33            [ 6] 1613 	inc	sp
   53BB CD 21 51      [17] 1614 	call	_PrintObject
   53BE F1            [10] 1615 	pop	af
   53BF 33            [ 6] 1616 	inc	sp
                           1617 ;src/main.c:617: DeleteObjectScoreboard();
   53C0 CD C4 51      [17] 1618 	call	_DeleteObjectScoreboard
                           1619 ;src/main.c:618: spr[0].object = 255;
   53C3 21 CE 4B      [10] 1620 	ld	hl, #(_spr + 0x000c)
   53C6 36 FF         [10] 1621 	ld	(hl), #0xff
                           1622 ;src/main.c:619: obj[ct].taken = FALSE;
   53C8 FD 21 B1 4B   [14] 1623 	ld	iy, #_ct
   53CC FD 6E 00      [19] 1624 	ld	l, 0 (iy)
   53CF 26 00         [ 7] 1625 	ld	h, #0x00
   53D1 29            [11] 1626 	add	hl, hl
   53D2 29            [11] 1627 	add	hl, hl
   53D3 11 0E 4C      [10] 1628 	ld	de, #_obj
   53D6 19            [11] 1629 	add	hl, de
   53D7 23            [ 6] 1630 	inc	hl
   53D8 23            [ 6] 1631 	inc	hl
   53D9 23            [ 6] 1632 	inc	hl
   53DA 36 00         [10] 1633 	ld	(hl), #0x00
   53DC                    1634 00112$:
                           1635 ;src/main.c:622: ct = N_MAX_OBJ;
   53DC 21 B1 4B      [10] 1636 	ld	hl,#_ct + 0
   53DF 36 08         [10] 1637 	ld	(hl), #0x08
   53E1                    1638 00119$:
                           1639 ;src/main.c:625: ct++;
   53E1 21 B1 4B      [10] 1640 	ld	hl, #_ct+0
   53E4 34            [11] 1641 	inc	(hl)
   53E5 C3 44 52      [10] 1642 	jp	00120$
   53E8                    1643 00123$:
   53E8 DD F9         [10] 1644 	ld	sp, ix
   53EA DD E1         [14] 1645 	pop	ix
   53EC C9            [10] 1646 	ret
                           1647 ;src/main.c:640: void InitObjects() {
                           1648 ;	---------------------------------
                           1649 ; Function InitObjects
                           1650 ; ---------------------------------
   53ED                    1651 _InitObjects::
                           1652 ;src/main.c:632: obj[objNum].x = x; 
   53ED 21 0E 4C      [10] 1653 	ld	hl, #_obj
   53F0 36 18         [10] 1654 	ld	(hl), #0x18
                           1655 ;src/main.c:633: obj[objNum].y = y;
   53F2 21 0F 4C      [10] 1656 	ld	hl, #(_obj + 0x0001)
   53F5 36 60         [10] 1657 	ld	(hl), #0x60
                           1658 ;src/main.c:634: obj[objNum].mapNumber = mapNum;
   53F7 21 10 4C      [10] 1659 	ld	hl, #(_obj + 0x0002)
   53FA 36 00         [10] 1660 	ld	(hl), #0x00
                           1661 ;src/main.c:632: obj[objNum].x = x; 
   53FC 21 12 4C      [10] 1662 	ld	hl, #(_obj + 0x0004)
   53FF 36 00         [10] 1663 	ld	(hl), #0x00
                           1664 ;src/main.c:633: obj[objNum].y = y;
   5401 21 13 4C      [10] 1665 	ld	hl, #(_obj + 0x0005)
   5404 36 00         [10] 1666 	ld	(hl), #0x00
                           1667 ;src/main.c:634: obj[objNum].mapNumber = mapNum;
   5406 21 14 4C      [10] 1668 	ld	hl, #(_obj + 0x0006)
   5409 36 FF         [10] 1669 	ld	(hl), #0xff
                           1670 ;src/main.c:632: obj[objNum].x = x; 
   540B 21 16 4C      [10] 1671 	ld	hl, #(_obj + 0x0008)
   540E 36 2C         [10] 1672 	ld	(hl), #0x2c
                           1673 ;src/main.c:633: obj[objNum].y = y;
   5410 21 17 4C      [10] 1674 	ld	hl, #(_obj + 0x0009)
   5413 36 40         [10] 1675 	ld	(hl), #0x40
                           1676 ;src/main.c:634: obj[objNum].mapNumber = mapNum;
   5415 21 18 4C      [10] 1677 	ld	hl, #(_obj + 0x000a)
   5418 36 02         [10] 1678 	ld	(hl), #0x02
                           1679 ;src/main.c:632: obj[objNum].x = x; 
   541A 21 1A 4C      [10] 1680 	ld	hl, #(_obj + 0x000c)
   541D 36 08         [10] 1681 	ld	(hl), #0x08
                           1682 ;src/main.c:633: obj[objNum].y = y;
   541F 21 1B 4C      [10] 1683 	ld	hl, #(_obj + 0x000d)
   5422 36 3C         [10] 1684 	ld	(hl), #0x3c
                           1685 ;src/main.c:634: obj[objNum].mapNumber = mapNum;
   5424 21 1C 4C      [10] 1686 	ld	hl, #(_obj + 0x000e)
   5427 36 01         [10] 1687 	ld	(hl), #0x01
                           1688 ;src/main.c:632: obj[objNum].x = x; 
   5429 21 1E 4C      [10] 1689 	ld	hl, #(_obj + 0x0010)
   542C 36 00         [10] 1690 	ld	(hl), #0x00
                           1691 ;src/main.c:633: obj[objNum].y = y;
   542E 21 1F 4C      [10] 1692 	ld	hl, #(_obj + 0x0011)
   5431 36 00         [10] 1693 	ld	(hl), #0x00
                           1694 ;src/main.c:634: obj[objNum].mapNumber = mapNum;
   5433 21 20 4C      [10] 1695 	ld	hl, #(_obj + 0x0012)
   5436 36 FF         [10] 1696 	ld	(hl), #0xff
                           1697 ;src/main.c:632: obj[objNum].x = x; 
   5438 21 22 4C      [10] 1698 	ld	hl, #(_obj + 0x0014)
   543B 36 00         [10] 1699 	ld	(hl), #0x00
                           1700 ;src/main.c:633: obj[objNum].y = y;
   543D 21 23 4C      [10] 1701 	ld	hl, #(_obj + 0x0015)
   5440 36 00         [10] 1702 	ld	(hl), #0x00
                           1703 ;src/main.c:634: obj[objNum].mapNumber = mapNum;
   5442 21 24 4C      [10] 1704 	ld	hl, #(_obj + 0x0016)
   5445 36 FF         [10] 1705 	ld	(hl), #0xff
                           1706 ;src/main.c:632: obj[objNum].x = x; 
   5447 21 26 4C      [10] 1707 	ld	hl, #(_obj + 0x0018)
   544A 36 42         [10] 1708 	ld	(hl), #0x42
                           1709 ;src/main.c:633: obj[objNum].y = y;
   544C 21 27 4C      [10] 1710 	ld	hl, #(_obj + 0x0019)
   544F 36 80         [10] 1711 	ld	(hl), #0x80
                           1712 ;src/main.c:634: obj[objNum].mapNumber = mapNum;
   5451 21 28 4C      [10] 1713 	ld	hl, #(_obj + 0x001a)
   5454 36 01         [10] 1714 	ld	(hl), #0x01
                           1715 ;src/main.c:632: obj[objNum].x = x; 
   5456 21 2A 4C      [10] 1716 	ld	hl, #(_obj + 0x001c)
   5459 36 44         [10] 1717 	ld	(hl), #0x44
                           1718 ;src/main.c:633: obj[objNum].y = y;
   545B 21 2B 4C      [10] 1719 	ld	hl, #(_obj + 0x001d)
   545E 36 40         [10] 1720 	ld	(hl), #0x40
                           1721 ;src/main.c:634: obj[objNum].mapNumber = mapNum;
   5460 21 2C 4C      [10] 1722 	ld	hl, #(_obj + 0x001e)
   5463 36 02         [10] 1723 	ld	(hl), #0x02
                           1724 ;src/main.c:649: SetObjectParams(7, 68,  64,   2); // Ammunition
   5465 C9            [10] 1725 	ret
                           1726 ;src/main.c:664: void PrintSprite(TSpr *pSpr) __z88dk_fastcall {
                           1727 ;	---------------------------------
                           1728 ; Function PrintSprite
                           1729 ; ---------------------------------
   5466                    1730 _PrintSprite::
                           1731 ;src/main.c:667: SPR_W, SPR_H, g_maskTable);
                           1732 ;src/main.c:666: cpct_getScreenPtr(CPCT_VMEM_START, pSpr->x, pSpr->y), 
   5466 4D            [ 4] 1733 	ld	c,l
   5467 44            [ 4] 1734 	ld	b,h
   5468 23            [ 6] 1735 	inc	hl
   5469 56            [ 7] 1736 	ld	d, (hl)
   546A 0A            [ 7] 1737 	ld	a, (bc)
   546B C5            [11] 1738 	push	bc
   546C 5F            [ 4] 1739 	ld	e, a
   546D D5            [11] 1740 	push	de
   546E 21 00 C0      [10] 1741 	ld	hl, #0xc000
   5471 E5            [11] 1742 	push	hl
   5472 CD AA 4A      [17] 1743 	call	_cpct_getScreenPtr
   5475 EB            [ 4] 1744 	ex	de,hl
   5476 FD E1         [14] 1745 	pop	iy
   5478 FD 6E 05      [19] 1746 	ld	l, 5 (iy)
   547B FD 66 06      [19] 1747 	ld	h, 6 (iy)
   547E 23            [ 6] 1748 	inc	hl
   547F 4E            [ 7] 1749 	ld	c, (hl)
   5480 23            [ 6] 1750 	inc	hl
   5481 46            [ 7] 1751 	ld	b, (hl)
   5482 21 00 01      [10] 1752 	ld	hl, #_g_maskTable
   5485 E5            [11] 1753 	push	hl
   5486 21 08 10      [10] 1754 	ld	hl, #0x1008
   5489 E5            [11] 1755 	push	hl
   548A D5            [11] 1756 	push	de
   548B C5            [11] 1757 	push	bc
   548C CD C0 4A      [17] 1758 	call	_cpct_drawSpriteMaskedAlignedTable
   548F C9            [10] 1759 	ret
                           1760 ;src/main.c:672: void DeleteSprite(TSpr *pSpr) __z88dk_fastcall {
                           1761 ;	---------------------------------
                           1762 ; Function DeleteSprite
                           1763 ; ---------------------------------
   5490                    1764 _DeleteSprite::
   5490 DD E5         [15] 1765 	push	ix
   5492 DD 21 00 00   [14] 1766 	ld	ix,#0
   5496 DD 39         [15] 1767 	add	ix,sp
   5498 F5            [11] 1768 	push	af
   5499 3B            [ 6] 1769 	dec	sp
                           1770 ;src/main.c:674: 4 + (pSpr->px & 1), 4 + (pSpr->py & 3 ? 1 : 0),	
   549A 4D            [ 4] 1771 	ld	c,l
   549B 54            [ 4] 1772 	ld	d,h
   549C 23            [ 6] 1773 	inc	hl
   549D 23            [ 6] 1774 	inc	hl
   549E 23            [ 6] 1775 	inc	hl
   549F 5E            [ 7] 1776 	ld	e, (hl)
   54A0 7B            [ 4] 1777 	ld	a, e
   54A1 E6 03         [ 7] 1778 	and	a, #0x03
   54A3 28 04         [12] 1779 	jr	Z,00103$
   54A5 06 01         [ 7] 1780 	ld	b, #0x01
   54A7 18 02         [12] 1781 	jr	00104$
   54A9                    1782 00103$:
   54A9 06 00         [ 7] 1783 	ld	b, #0x00
   54AB                    1784 00104$:
   54AB 04            [ 4] 1785 	inc	b
   54AC 04            [ 4] 1786 	inc	b
   54AD 04            [ 4] 1787 	inc	b
   54AE 04            [ 4] 1788 	inc	b
   54AF 69            [ 4] 1789 	ld	l, c
   54B0 62            [ 4] 1790 	ld	h, d
   54B1 23            [ 6] 1791 	inc	hl
   54B2 23            [ 6] 1792 	inc	hl
   54B3 4E            [ 7] 1793 	ld	c, (hl)
   54B4 79            [ 4] 1794 	ld	a, c
   54B5 E6 01         [ 7] 1795 	and	a, #0x01
   54B7 C6 04         [ 7] 1796 	add	a, #0x04
   54B9 DD 77 FF      [19] 1797 	ld	-1 (ix), a
                           1798 ;src/main.c:673: cpct_etm_drawTileBox2x4(pSpr->px / 2, (pSpr->py - ORIG_MAP_Y) / 4, 
   54BC 16 00         [ 7] 1799 	ld	d, #0x00
   54BE 7B            [ 4] 1800 	ld	a, e
   54BF C6 D8         [ 7] 1801 	add	a, #0xd8
   54C1 DD 77 FD      [19] 1802 	ld	-3 (ix), a
   54C4 7A            [ 4] 1803 	ld	a, d
   54C5 CE FF         [ 7] 1804 	adc	a, #0xff
   54C7 DD 77 FE      [19] 1805 	ld	-2 (ix), a
   54CA E1            [10] 1806 	pop	hl
   54CB E5            [11] 1807 	push	hl
   54CC DD CB FE 7E   [20] 1808 	bit	7, -2 (ix)
   54D0 28 04         [12] 1809 	jr	Z,00105$
   54D2 21 DB FF      [10] 1810 	ld	hl, #0xffdb
   54D5 19            [11] 1811 	add	hl, de
   54D6                    1812 00105$:
   54D6 CB 2C         [ 8] 1813 	sra	h
   54D8 CB 1D         [ 8] 1814 	rr	l
   54DA CB 2C         [ 8] 1815 	sra	h
   54DC CB 1D         [ 8] 1816 	rr	l
   54DE 5D            [ 4] 1817 	ld	e, l
   54DF CB 39         [ 8] 1818 	srl	c
   54E1 21 31 10      [10] 1819 	ld	hl, #0x1031
   54E4 E5            [11] 1820 	push	hl
   54E5 21 90 C1      [10] 1821 	ld	hl, #0xc190
   54E8 E5            [11] 1822 	push	hl
   54E9 3E 28         [ 7] 1823 	ld	a, #0x28
   54EB F5            [11] 1824 	push	af
   54EC 33            [ 6] 1825 	inc	sp
   54ED C5            [11] 1826 	push	bc
   54EE 33            [ 6] 1827 	inc	sp
   54EF DD 56 FF      [19] 1828 	ld	d, -1 (ix)
   54F2 D5            [11] 1829 	push	de
   54F3 79            [ 4] 1830 	ld	a, c
   54F4 F5            [11] 1831 	push	af
   54F5 33            [ 6] 1832 	inc	sp
   54F6 CD 81 47      [17] 1833 	call	_cpct_etm_drawTileBox2x4
   54F9 DD F9         [10] 1834 	ld	sp, ix
   54FB DD E1         [14] 1835 	pop	ix
   54FD C9            [10] 1836 	ret
                           1837 ;src/main.c:680: void PrintExplosion(TSpr *pSpr, u8 frame) {
                           1838 ;	---------------------------------
                           1839 ; Function PrintExplosion
                           1840 ; ---------------------------------
   54FE                    1841 _PrintExplosion::
   54FE DD E5         [15] 1842 	push	ix
   5500 DD 21 00 00   [14] 1843 	ld	ix,#0
   5504 DD 39         [15] 1844 	add	ix,sp
                           1845 ;src/main.c:683: SPR_W, SPR_H, g_maskTable);
                           1846 ;src/main.c:682: cpct_getScreenPtr(CPCT_VMEM_START, pSpr->x, pSpr->y), 
   5506 DD 4E 04      [19] 1847 	ld	c,4 (ix)
   5509 DD 46 05      [19] 1848 	ld	b,5 (ix)
   550C 69            [ 4] 1849 	ld	l, c
   550D 60            [ 4] 1850 	ld	h, b
   550E 23            [ 6] 1851 	inc	hl
   550F 56            [ 7] 1852 	ld	d, (hl)
   5510 0A            [ 7] 1853 	ld	a, (bc)
   5511 5F            [ 4] 1854 	ld	e,a
   5512 D5            [11] 1855 	push	de
   5513 21 00 C0      [10] 1856 	ld	hl, #0xc000
   5516 E5            [11] 1857 	push	hl
   5517 CD AA 4A      [17] 1858 	call	_cpct_getScreenPtr
   551A 4D            [ 4] 1859 	ld	c, l
   551B 44            [ 4] 1860 	ld	b, h
                           1861 ;src/main.c:681: cpct_drawSpriteMaskedAlignedTable(g_explosion[frame], 
   551C 11 19 33      [10] 1862 	ld	de, #_g_explosion+0
   551F DD 6E 06      [19] 1863 	ld	l, 6 (ix)
   5522 26 00         [ 7] 1864 	ld	h, #0x00
   5524 29            [11] 1865 	add	hl, hl
   5525 29            [11] 1866 	add	hl, hl
   5526 29            [11] 1867 	add	hl, hl
   5527 29            [11] 1868 	add	hl, hl
   5528 29            [11] 1869 	add	hl, hl
   5529 29            [11] 1870 	add	hl, hl
   552A 29            [11] 1871 	add	hl, hl
   552B 19            [11] 1872 	add	hl, de
   552C 11 00 01      [10] 1873 	ld	de, #_g_maskTable
   552F D5            [11] 1874 	push	de
   5530 11 08 10      [10] 1875 	ld	de, #0x1008
   5533 D5            [11] 1876 	push	de
   5534 C5            [11] 1877 	push	bc
   5535 E5            [11] 1878 	push	hl
   5536 CD C0 4A      [17] 1879 	call	_cpct_drawSpriteMaskedAlignedTable
   5539 DD E1         [14] 1880 	pop	ix
   553B C9            [10] 1881 	ret
                           1882 ;src/main.c:688: void SelectSpriteFrame(TSpr *pSpr) __z88dk_fastcall {
                           1883 ;	---------------------------------
                           1884 ; Function SelectSpriteFrame
                           1885 ; ---------------------------------
   553C                    1886 _SelectSpriteFrame::
   553C DD E5         [15] 1887 	push	ix
   553E DD 21 00 00   [14] 1888 	ld	ix,#0
   5542 DD 39         [15] 1889 	add	ix,sp
   5544 3B            [ 6] 1890 	dec	sp
                           1891 ;src/main.c:689: if (ctMainLoop % ANIM_PAUSE == 0) {
   5545 E5            [11] 1892 	push	hl
   5546 3E 03         [ 7] 1893 	ld	a, #0x03
   5548 F5            [11] 1894 	push	af
   5549 33            [ 6] 1895 	inc	sp
   554A 3A B0 4B      [13] 1896 	ld	a, (_ctMainLoop)
   554D F5            [11] 1897 	push	af
   554E 33            [ 6] 1898 	inc	sp
   554F CD 14 48      [17] 1899 	call	__moduchar
   5552 F1            [10] 1900 	pop	af
   5553 C1            [10] 1901 	pop	bc
   5554 7D            [ 4] 1902 	ld	a, l
   5555 B7            [ 4] 1903 	or	a, a
   5556 20 59         [12] 1904 	jr	NZ,00109$
                           1905 ;src/main.c:690: if (pSpr->ident == PELUSOID)
   5558 69            [ 4] 1906 	ld	l, c
   5559 60            [ 4] 1907 	ld	h, b
   555A 11 12 00      [10] 1908 	ld	de, #0x0012
   555D 19            [11] 1909 	add	hl, de
   555E 7E            [ 7] 1910 	ld	a, (hl)
   555F DD 77 FF      [19] 1911 	ld	-1 (ix), a
                           1912 ;src/main.c:691: pSpr->frm = anim_pelusoid[pSpr->nFrm / ANIM_PAUSE];
   5562 21 05 00      [10] 1913 	ld	hl, #0x0005
   5565 09            [11] 1914 	add	hl,bc
   5566 EB            [ 4] 1915 	ex	de,hl
   5567 C5            [11] 1916 	push	bc
   5568 FD E1         [14] 1917 	pop	iy
   556A FD 46 07      [19] 1918 	ld	b, 7 (iy)
   556D D5            [11] 1919 	push	de
   556E 3E 03         [ 7] 1920 	ld	a, #0x03
   5570 F5            [11] 1921 	push	af
   5571 33            [ 6] 1922 	inc	sp
   5572 C5            [11] 1923 	push	bc
   5573 33            [ 6] 1924 	inc	sp
   5574 CD E1 3D      [17] 1925 	call	__divuchar
   5577 F1            [10] 1926 	pop	af
   5578 D1            [10] 1927 	pop	de
   5579 26 00         [ 7] 1928 	ld	h, #0x00
   557B 29            [11] 1929 	add	hl, hl
                           1930 ;src/main.c:690: if (pSpr->ident == PELUSOID)
   557C DD 7E FF      [19] 1931 	ld	a, -1 (ix)
   557F 3D            [ 4] 1932 	dec	a
   5580 20 0E         [12] 1933 	jr	NZ,00105$
                           1934 ;src/main.c:691: pSpr->frm = anim_pelusoid[pSpr->nFrm / ANIM_PAUSE];
   5582 01 7E 4C      [10] 1935 	ld	bc, #_anim_pelusoid+0
   5585 09            [11] 1936 	add	hl, bc
   5586 4E            [ 7] 1937 	ld	c, (hl)
   5587 23            [ 6] 1938 	inc	hl
   5588 46            [ 7] 1939 	ld	b, (hl)
   5589 79            [ 4] 1940 	ld	a, c
   558A 12            [ 7] 1941 	ld	(de), a
   558B 13            [ 6] 1942 	inc	de
   558C 78            [ 4] 1943 	ld	a, b
   558D 12            [ 7] 1944 	ld	(de), a
   558E 18 21         [12] 1945 	jr	00109$
   5590                    1946 00105$:
                           1947 ;src/main.c:692: else if (pSpr->ident == ARACNOVIRUS)
   5590 DD 7E FF      [19] 1948 	ld	a, -1 (ix)
   5593 D6 02         [ 7] 1949 	sub	a, #0x02
   5595 20 0E         [12] 1950 	jr	NZ,00102$
                           1951 ;src/main.c:693: pSpr->frm = anim_aracnovirus[pSpr->nFrm / ANIM_PAUSE];
   5597 01 82 4C      [10] 1952 	ld	bc, #_anim_aracnovirus+0
   559A 09            [11] 1953 	add	hl, bc
   559B 4E            [ 7] 1954 	ld	c, (hl)
   559C 23            [ 6] 1955 	inc	hl
   559D 46            [ 7] 1956 	ld	b, (hl)
   559E 79            [ 4] 1957 	ld	a, c
   559F 12            [ 7] 1958 	ld	(de), a
   55A0 13            [ 6] 1959 	inc	de
   55A1 78            [ 4] 1960 	ld	a, b
   55A2 12            [ 7] 1961 	ld	(de), a
   55A3 18 0C         [12] 1962 	jr	00109$
   55A5                    1963 00102$:
                           1964 ;src/main.c:695: pSpr->frm = anim_infected[pSpr->nFrm / ANIM_PAUSE];
   55A5 01 86 4C      [10] 1965 	ld	bc, #_anim_infected+0
   55A8 09            [11] 1966 	add	hl, bc
   55A9 4E            [ 7] 1967 	ld	c, (hl)
   55AA 23            [ 6] 1968 	inc	hl
   55AB 46            [ 7] 1969 	ld	b, (hl)
   55AC 79            [ 4] 1970 	ld	a, c
   55AD 12            [ 7] 1971 	ld	(de), a
   55AE 13            [ 6] 1972 	inc	de
   55AF 78            [ 4] 1973 	ld	a, b
   55B0 12            [ 7] 1974 	ld	(de), a
   55B1                    1975 00109$:
   55B1 33            [ 6] 1976 	inc	sp
   55B2 DD E1         [14] 1977 	pop	ix
   55B4 C9            [10] 1978 	ret
                           1979 ;src/main.c:701: void EnemyWalkAnim(TSpr *pSpr) __z88dk_fastcall {
                           1980 ;	---------------------------------
                           1981 ; Function EnemyWalkAnim
                           1982 ; ---------------------------------
   55B5                    1983 _EnemyWalkAnim::
                           1984 ;src/main.c:702: if(++pSpr->nFrm == 2 * ANIM_PAUSE) pSpr->nFrm = 0;
   55B5 01 07 00      [10] 1985 	ld	bc, #0x0007
   55B8 09            [11] 1986 	add	hl, bc
   55B9 7E            [ 7] 1987 	ld	a, (hl)
   55BA 3C            [ 4] 1988 	inc	a
   55BB 77            [ 7] 1989 	ld	(hl), a
   55BC D6 06         [ 7] 1990 	sub	a,#0x06
   55BE C0            [11] 1991 	ret	NZ
   55BF 77            [ 7] 1992 	ld	(hl),a
   55C0 C9            [10] 1993 	ret
                           1994 ;src/main.c:707: void CheckEnemyCollision(TSpr *pSpr) { // __z88dk_fastcall
                           1995 ;	---------------------------------
                           1996 ; Function CheckEnemyCollision
                           1997 ; ---------------------------------
   55C1                    1998 _CheckEnemyCollision::
   55C1 DD E5         [15] 1999 	push	ix
   55C3 DD 21 00 00   [14] 2000 	ld	ix,#0
   55C7 DD 39         [15] 2001 	add	ix,sp
   55C9 F5            [11] 2002 	push	af
   55CA F5            [11] 2003 	push	af
                           2004 ;src/main.c:709: if ((spr[0].x + SPR_W) > (pSpr->x + 2) && (spr[0].x + 2) < (pSpr->x + SPR_W))
   55CB 21 C2 4B      [10] 2005 	ld	hl, #_spr+0
   55CE 4E            [ 7] 2006 	ld	c, (hl)
   55CF 06 00         [ 7] 2007 	ld	b, #0x00
   55D1 21 08 00      [10] 2008 	ld	hl, #0x0008
   55D4 09            [11] 2009 	add	hl,bc
   55D5 DD 75 FE      [19] 2010 	ld	-2 (ix), l
   55D8 DD 74 FF      [19] 2011 	ld	-1 (ix), h
   55DB DD 5E 04      [19] 2012 	ld	e,4 (ix)
   55DE DD 56 05      [19] 2013 	ld	d,5 (ix)
   55E1 1A            [ 7] 2014 	ld	a, (de)
   55E2 6F            [ 4] 2015 	ld	l, a
   55E3 26 00         [ 7] 2016 	ld	h, #0x00
   55E5 7D            [ 4] 2017 	ld	a, l
   55E6 C6 02         [ 7] 2018 	add	a, #0x02
   55E8 DD 77 FC      [19] 2019 	ld	-4 (ix), a
   55EB 7C            [ 4] 2020 	ld	a, h
   55EC CE 00         [ 7] 2021 	adc	a, #0x00
   55EE DD 77 FD      [19] 2022 	ld	-3 (ix), a
   55F1 DD 7E FC      [19] 2023 	ld	a, -4 (ix)
   55F4 DD 96 FE      [19] 2024 	sub	a, -2 (ix)
   55F7 DD 7E FD      [19] 2025 	ld	a, -3 (ix)
   55FA DD 9E FF      [19] 2026 	sbc	a, -1 (ix)
   55FD E2 02 56      [10] 2027 	jp	PO, 00125$
   5600 EE 80         [ 7] 2028 	xor	a, #0x80
   5602                    2029 00125$:
   5602 F2 5E 56      [10] 2030 	jp	P, 00107$
   5605 03            [ 6] 2031 	inc	bc
   5606 03            [ 6] 2032 	inc	bc
   5607 D5            [11] 2033 	push	de
   5608 11 08 00      [10] 2034 	ld	de, #0x0008
   560B 19            [11] 2035 	add	hl, de
   560C D1            [10] 2036 	pop	de
   560D 79            [ 4] 2037 	ld	a, c
   560E 95            [ 4] 2038 	sub	a, l
   560F 78            [ 4] 2039 	ld	a, b
   5610 9C            [ 4] 2040 	sbc	a, h
   5611 E2 16 56      [10] 2041 	jp	PO, 00126$
   5614 EE 80         [ 7] 2042 	xor	a, #0x80
   5616                    2043 00126$:
   5616 F2 5E 56      [10] 2044 	jp	P, 00107$
                           2045 ;src/main.c:710: if ((spr[0].y + SPR_H) > (pSpr->y + 2) && (spr[0].y + 2) < (pSpr->y + SPR_H)) {
   5619 3A C3 4B      [13] 2046 	ld	a, (#_spr + 1)
   561C 4F            [ 4] 2047 	ld	c, a
   561D 06 00         [ 7] 2048 	ld	b, #0x00
   561F 21 10 00      [10] 2049 	ld	hl, #0x0010
   5622 09            [11] 2050 	add	hl,bc
   5623 E3            [19] 2051 	ex	(sp), hl
   5624 EB            [ 4] 2052 	ex	de,hl
   5625 23            [ 6] 2053 	inc	hl
   5626 5E            [ 7] 2054 	ld	e, (hl)
   5627 16 00         [ 7] 2055 	ld	d, #0x00
   5629 6B            [ 4] 2056 	ld	l, e
   562A 62            [ 4] 2057 	ld	h, d
   562B 23            [ 6] 2058 	inc	hl
   562C 23            [ 6] 2059 	inc	hl
   562D 7D            [ 4] 2060 	ld	a, l
   562E DD 96 FC      [19] 2061 	sub	a, -4 (ix)
   5631 7C            [ 4] 2062 	ld	a, h
   5632 DD 9E FD      [19] 2063 	sbc	a, -3 (ix)
   5635 E2 3A 56      [10] 2064 	jp	PO, 00127$
   5638 EE 80         [ 7] 2065 	xor	a, #0x80
   563A                    2066 00127$:
   563A F2 5E 56      [10] 2067 	jp	P, 00107$
   563D 03            [ 6] 2068 	inc	bc
   563E 03            [ 6] 2069 	inc	bc
   563F 21 10 00      [10] 2070 	ld	hl, #0x0010
   5642 19            [11] 2071 	add	hl, de
   5643 79            [ 4] 2072 	ld	a, c
   5644 95            [ 4] 2073 	sub	a, l
   5645 78            [ 4] 2074 	ld	a, b
   5646 9C            [ 4] 2075 	sbc	a, h
   5647 E2 4C 56      [10] 2076 	jp	PO, 00128$
   564A EE 80         [ 7] 2077 	xor	a, #0x80
   564C                    2078 00128$:
   564C F2 5E 56      [10] 2079 	jp	P, 00107$
                           2080 ;src/main.c:712: spr[0].lives--;
   564F 21 CB 4B      [10] 2081 	ld	hl, #_spr + 9
   5652 4E            [ 7] 2082 	ld	c, (hl)
   5653 0D            [ 4] 2083 	dec	c
   5654 71            [ 7] 2084 	ld	(hl), c
                           2085 ;src/main.c:713: ExplodePlayer();
   5655 CD DC 5A      [17] 2086 	call	_ExplodePlayer
                           2087 ;src/main.c:714: ExplodeEnemies();
   5658 CD D1 5F      [17] 2088 	call	_ExplodeEnemies
                           2089 ;src/main.c:715: GameOver();
   565B CD C8 62      [17] 2090 	call	_GameOver
   565E                    2091 00107$:
   565E DD F9         [10] 2092 	ld	sp, ix
   5660 DD E1         [14] 2093 	pop	ix
   5662 C9            [10] 2094 	ret
                           2095 ;src/main.c:732: void AssignFrame(TFrm **anim) __z88dk_fastcall {
                           2096 ;	---------------------------------
                           2097 ; Function AssignFrame
                           2098 ; ---------------------------------
   5663                    2099 _AssignFrame::
   5663 4D            [ 4] 2100 	ld	c, l
   5664 44            [ 4] 2101 	ld	b, h
                           2102 ;src/main.c:733: spr[0].frm = anim[spr[0].nFrm / ANIM_PAUSE];
   5665 21 C9 4B      [10] 2103 	ld	hl, #_spr + 7
   5668 56            [ 7] 2104 	ld	d, (hl)
   5669 C5            [11] 2105 	push	bc
   566A 3E 03         [ 7] 2106 	ld	a, #0x03
   566C F5            [11] 2107 	push	af
   566D 33            [ 6] 2108 	inc	sp
   566E D5            [11] 2109 	push	de
   566F 33            [ 6] 2110 	inc	sp
   5670 CD E1 3D      [17] 2111 	call	__divuchar
   5673 F1            [10] 2112 	pop	af
   5674 C1            [10] 2113 	pop	bc
   5675 26 00         [ 7] 2114 	ld	h, #0x00
   5677 29            [11] 2115 	add	hl, hl
   5678 09            [11] 2116 	add	hl, bc
   5679 4E            [ 7] 2117 	ld	c, (hl)
   567A 23            [ 6] 2118 	inc	hl
   567B 46            [ 7] 2119 	ld	b, (hl)
   567C ED 43 C7 4B   [20] 2120 	ld	((_spr + 0x0005)), bc
   5680 C9            [10] 2121 	ret
                           2122 ;src/main.c:738: void SelectFrame() {
                           2123 ;	---------------------------------
                           2124 ; Function SelectFrame
                           2125 ; ---------------------------------
   5681                    2126 _SelectFrame::
                           2127 ;src/main.c:740: switch(spr[0].status) {
   5681 21 C6 4B      [10] 2128 	ld	hl, #(_spr + 0x0004) + 0
   5684 4E            [ 7] 2129 	ld	c, (hl)
                           2130 ;src/main.c:741: case S_stopped:			{spr[0].frm = &frm_player[0]; break;}
                           2131 ;src/main.c:740: switch(spr[0].status) {
   5685 3E 06         [ 7] 2132 	ld	a, #0x06
   5687 91            [ 4] 2133 	sub	a, c
   5688 38 54         [12] 2134 	jr	C,00108$
   568A 06 00         [ 7] 2135 	ld	b, #0x00
   568C 21 93 56      [10] 2136 	ld	hl, #00126$
   568F 09            [11] 2137 	add	hl, bc
   5690 09            [11] 2138 	add	hl, bc
   5691 09            [11] 2139 	add	hl, bc
   5692 E9            [ 4] 2140 	jp	(hl)
   5693                    2141 00126$:
   5693 C3 A8 56      [10] 2142 	jp	00101$
   5696 C3 B0 56      [10] 2143 	jp	00102$
   5699 C3 C0 56      [10] 2144 	jp	00104$
   569C C3 C8 56      [10] 2145 	jp	00105$
   569F C3 B8 56      [10] 2146 	jp	00103$
   56A2 C3 D0 56      [10] 2147 	jp	00106$
   56A5 C3 D8 56      [10] 2148 	jp	00107$
                           2149 ;src/main.c:741: case S_stopped:			{spr[0].frm = &frm_player[0]; break;}
   56A8                    2150 00101$:
   56A8 21 41 4C      [10] 2151 	ld	hl, #_frm_player
   56AB 22 C7 4B      [16] 2152 	ld	((_spr + 0x0005)), hl
   56AE 18 2E         [12] 2153 	jr	00108$
                           2154 ;src/main.c:742: case S_walking:			{AssignFrame(animWalk); break;}	// 0,1,0,2
   56B0                    2155 00102$:
   56B0 21 5C 4C      [10] 2156 	ld	hl, #_animWalk
   56B3 CD 63 56      [17] 2157 	call	_AssignFrame
   56B6 18 26         [12] 2158 	jr	00108$
                           2159 ;src/main.c:743: case S_climbing:		{AssignFrame(animClimb); break;} // 6,7,6,8
   56B8                    2160 00103$:
   56B8 21 64 4C      [10] 2161 	ld	hl, #_animClimb
   56BB CD 63 56      [17] 2162 	call	_AssignFrame
   56BE 18 1E         [12] 2163 	jr	00108$
                           2164 ;src/main.c:744: case S_preJump:			{spr[0].frm = &frm_player[1]; break;}
   56C0                    2165 00104$:
   56C0 21 44 4C      [10] 2166 	ld	hl, #(_frm_player + 0x0003)
   56C3 22 C7 4B      [16] 2167 	ld	((_spr + 0x0005)), hl
   56C6 18 16         [12] 2168 	jr	00108$
                           2169 ;src/main.c:745: case S_jumping:			{spr[0].frm = &frm_player[3]; break;}
   56C8                    2170 00105$:
   56C8 21 4A 4C      [10] 2171 	ld	hl, #(_frm_player + 0x0009)
   56CB 22 C7 4B      [16] 2172 	ld	((_spr + 0x0005)), hl
   56CE 18 0E         [12] 2173 	jr	00108$
                           2174 ;src/main.c:746: case S_falling:			{spr[0].frm = &frm_player[4]; break;}
   56D0                    2175 00106$:
   56D0 21 4D 4C      [10] 2176 	ld	hl, #(_frm_player + 0x000c)
   56D3 22 C7 4B      [16] 2177 	ld	((_spr + 0x0005)), hl
   56D6 18 06         [12] 2178 	jr	00108$
                           2179 ;src/main.c:747: case S_landing:			{spr[0].frm = &frm_player[1]; break;}
   56D8                    2180 00107$:
   56D8 21 44 4C      [10] 2181 	ld	hl, #(_frm_player + 0x0003)
   56DB 22 C7 4B      [16] 2182 	ld	((_spr + 0x0005)), hl
                           2183 ;src/main.c:748: }
   56DE                    2184 00108$:
                           2185 ;src/main.c:750: f = spr[0].frm;
   56DE ED 4B C7 4B   [20] 2186 	ld	bc, (#(_spr + 0x0005) + 0)
                           2187 ;src/main.c:752: if (f->dir != spr[0].dir && spr[0].status != S_climbing) {
   56E2 0A            [ 7] 2188 	ld	a, (bc)
   56E3 5F            [ 4] 2189 	ld	e, a
   56E4 3A CA 4B      [13] 2190 	ld	a, (#(_spr + 0x0008) + 0)
   56E7 93            [ 4] 2191 	sub	a, e
   56E8 C8            [11] 2192 	ret	Z
   56E9 3A C6 4B      [13] 2193 	ld	a, (#(_spr + 0x0004) + 0)
   56EC D6 04         [ 7] 2194 	sub	a, #0x04
   56EE C8            [11] 2195 	ret	Z
                           2196 ;src/main.c:753: cpct_hflipSpriteM0(SPR_W, SPR_H, f->spr);         
   56EF 69            [ 4] 2197 	ld	l, c
   56F0 60            [ 4] 2198 	ld	h, b
   56F1 23            [ 6] 2199 	inc	hl
   56F2 5E            [ 7] 2200 	ld	e, (hl)
   56F3 23            [ 6] 2201 	inc	hl
   56F4 56            [ 7] 2202 	ld	d, (hl)
   56F5 C5            [11] 2203 	push	bc
   56F6 D5            [11] 2204 	push	de
   56F7 21 08 10      [10] 2205 	ld	hl, #0x1008
   56FA E5            [11] 2206 	push	hl
   56FB CD F1 48      [17] 2207 	call	_cpct_hflipSpriteM0
   56FE C1            [10] 2208 	pop	bc
                           2209 ;src/main.c:754: f->dir = spr[0].dir; // save position to compare with next call
   56FF 3A CA 4B      [13] 2210 	ld	a, (#(_spr + 0x0008) + 0)
   5702 02            [ 7] 2211 	ld	(bc), a
   5703 C9            [10] 2212 	ret
                           2213 ;src/main.c:759: void MoveUp() { 
                           2214 ;	---------------------------------
                           2215 ; Function MoveUp
                           2216 ; ---------------------------------
   5704                    2217 _MoveUp::
                           2218 ;src/main.c:760: if (spr[0].y > ORIG_MAP_Y) spr[0].y--;
   5704 01 C3 4B      [10] 2219 	ld	bc, #_spr+1
   5707 0A            [ 7] 2220 	ld	a, (bc)
   5708 5F            [ 4] 2221 	ld	e, a
   5709 3E 28         [ 7] 2222 	ld	a, #0x28
   570B 93            [ 4] 2223 	sub	a, e
   570C D0            [11] 2224 	ret	NC
   570D 1D            [ 4] 2225 	dec	e
   570E 7B            [ 4] 2226 	ld	a, e
   570F 02            [ 7] 2227 	ld	(bc), a
   5710 C9            [10] 2228 	ret
                           2229 ;src/main.c:764: void MoveDown() {
                           2230 ;	---------------------------------
                           2231 ; Function MoveDown
                           2232 ; ---------------------------------
   5711                    2233 _MoveDown::
                           2234 ;src/main.c:765: if (spr[0].y + SPR_H < GLOBAL_MAX_Y) spr[0].y++;
   5711 21 C3 4B      [10] 2235 	ld	hl, #(_spr + 0x0001) + 0
   5714 4E            [ 7] 2236 	ld	c, (hl)
   5715 59            [ 4] 2237 	ld	e, c
   5716 16 00         [ 7] 2238 	ld	d, #0x00
   5718 21 10 00      [10] 2239 	ld	hl, #0x0010
   571B 19            [11] 2240 	add	hl, de
   571C 11 C0 80      [10] 2241 	ld	de, #0x80c0
   571F 29            [11] 2242 	add	hl, hl
   5720 3F            [ 4] 2243 	ccf
   5721 CB 1C         [ 8] 2244 	rr	h
   5723 CB 1D         [ 8] 2245 	rr	l
   5725 ED 52         [15] 2246 	sbc	hl, de
   5727 D0            [11] 2247 	ret	NC
   5728 0C            [ 4] 2248 	inc	c
   5729 21 C3 4B      [10] 2249 	ld	hl, #(_spr + 0x0001)
   572C 71            [ 7] 2250 	ld	(hl), c
   572D C9            [10] 2251 	ret
                           2252 ;src/main.c:769: void MoveLeft() {
                           2253 ;	---------------------------------
                           2254 ; Function MoveLeft
                           2255 ; ---------------------------------
   572E                    2256 _MoveLeft::
                           2257 ;src/main.c:770: if (spr[0].x > 0) {
   572E 3A C2 4B      [13] 2258 	ld	a, (#_spr + 0)
   5731 B7            [ 4] 2259 	or	a, a
   5732 CA 83 4F      [10] 2260 	jp	Z,_MoveLeftMap
                           2261 ;src/main.c:771: if (!FacingWall(spr[0].dir)) {
   5735 21 CA 4B      [10] 2262 	ld	hl, #(_spr + 0x0008) + 0
   5738 6E            [ 7] 2263 	ld	l, (hl)
   5739 CD 3D 50      [17] 2264 	call	_FacingWall
   573C 7D            [ 4] 2265 	ld	a, l
   573D B7            [ 4] 2266 	or	a, a
   573E C0            [11] 2267 	ret	NZ
                           2268 ;src/main.c:772: spr[0].x--;
   573F 21 C2 4B      [10] 2269 	ld	hl, #_spr + 0
   5742 4E            [ 7] 2270 	ld	c, (hl)
   5743 0D            [ 4] 2271 	dec	c
   5744 21 C2 4B      [10] 2272 	ld	hl, #_spr
   5747 71            [ 7] 2273 	ld	(hl), c
                           2274 ;src/main.c:773: spr[0].dir = D_left;
   5748 21 CA 4B      [10] 2275 	ld	hl, #(_spr + 0x0008)
   574B 36 02         [10] 2276 	ld	(hl), #0x02
   574D C9            [10] 2277 	ret
                           2278 ;src/main.c:777: MoveLeftMap(); 
   574E C3 83 4F      [10] 2279 	jp  _MoveLeftMap
                           2280 ;src/main.c:781: void MoveRight() { 
                           2281 ;	---------------------------------
                           2282 ; Function MoveRight
                           2283 ; ---------------------------------
   5751                    2284 _MoveRight::
                           2285 ;src/main.c:782: if (spr[0].x + SPR_W < GLOBAL_MAX_X) {
   5751 21 C2 4B      [10] 2286 	ld	hl, #_spr + 0
   5754 4E            [ 7] 2287 	ld	c, (hl)
   5755 06 00         [ 7] 2288 	ld	b, #0x00
   5757 21 08 00      [10] 2289 	ld	hl, #0x0008
   575A 09            [11] 2290 	add	hl, bc
   575B 11 50 80      [10] 2291 	ld	de, #0x8050
   575E 29            [11] 2292 	add	hl, hl
   575F 3F            [ 4] 2293 	ccf
   5760 CB 1C         [ 8] 2294 	rr	h
   5762 CB 1D         [ 8] 2295 	rr	l
   5764 ED 52         [15] 2296 	sbc	hl, de
   5766 D2 69 4F      [10] 2297 	jp	NC,_MoveRightMap
                           2298 ;src/main.c:783: if (!FacingWall(spr[0].dir)) {
   5769 21 CA 4B      [10] 2299 	ld	hl, #(_spr + 0x0008) + 0
   576C 6E            [ 7] 2300 	ld	l, (hl)
   576D CD 3D 50      [17] 2301 	call	_FacingWall
   5770 7D            [ 4] 2302 	ld	a, l
   5771 B7            [ 4] 2303 	or	a, a
   5772 C0            [11] 2304 	ret	NZ
                           2305 ;src/main.c:784: spr[0].x++;
   5773 3A C2 4B      [13] 2306 	ld	a, (#_spr + 0)
   5776 3C            [ 4] 2307 	inc	a
   5777 32 C2 4B      [13] 2308 	ld	(#_spr),a
                           2309 ;src/main.c:785: spr[0].dir = D_right;
   577A 21 CA 4B      [10] 2310 	ld	hl, #(_spr + 0x0008)
   577D 36 03         [10] 2311 	ld	(hl), #0x03
   577F C9            [10] 2312 	ret
                           2313 ;src/main.c:789: MoveRightMap();
   5780 C3 69 4F      [10] 2314 	jp  _MoveRightMap
                           2315 ;src/main.c:794: void WalkIn(u8 dir) __z88dk_fastcall {
                           2316 ;	---------------------------------
                           2317 ; Function WalkIn
                           2318 ; ---------------------------------
   5783                    2319 _WalkIn::
   5783 4D            [ 4] 2320 	ld	c, l
                           2321 ;src/main.c:795: spr[0].nFrm = 0;
   5784 21 C9 4B      [10] 2322 	ld	hl, #(_spr + 0x0007)
   5787 36 00         [10] 2323 	ld	(hl), #0x00
                           2324 ;src/main.c:796: spr[0].status = S_walking;
   5789 21 C6 4B      [10] 2325 	ld	hl, #(_spr + 0x0004)
   578C 36 01         [10] 2326 	ld	(hl), #0x01
                           2327 ;src/main.c:797: spr[0].dir = dir;
   578E 21 CA 4B      [10] 2328 	ld	hl, #(_spr + 0x0008)
   5791 71            [ 7] 2329 	ld	(hl), c
   5792 C9            [10] 2330 	ret
                           2331 ;src/main.c:802: void ClimbIn() {
                           2332 ;	---------------------------------
                           2333 ; Function ClimbIn
                           2334 ; ---------------------------------
   5793                    2335 _ClimbIn::
                           2336 ;src/main.c:803: spr[0].nFrm = 0;
   5793 21 C9 4B      [10] 2337 	ld	hl, #(_spr + 0x0007)
   5796 36 00         [10] 2338 	ld	(hl), #0x00
                           2339 ;src/main.c:804: spr[0].status = S_climbing;
   5798 21 C6 4B      [10] 2340 	ld	hl, #(_spr + 0x0004)
   579B 36 04         [10] 2341 	ld	(hl), #0x04
   579D C9            [10] 2342 	ret
                           2343 ;src/main.c:809: void PreJumpIn() {
                           2344 ;	---------------------------------
                           2345 ; Function PreJumpIn
                           2346 ; ---------------------------------
   579E                    2347 _PreJumpIn::
                           2348 ;src/main.c:810: spr[0].nFrm = 0;
   579E 21 C9 4B      [10] 2349 	ld	hl, #(_spr + 0x0007)
   57A1 36 00         [10] 2350 	ld	(hl), #0x00
                           2351 ;src/main.c:811: spr[0].status = S_preJump;
   57A3 21 C6 4B      [10] 2352 	ld	hl, #(_spr + 0x0004)
   57A6 36 02         [10] 2353 	ld	(hl), #0x02
   57A8 C9            [10] 2354 	ret
                           2355 ;src/main.c:816: void FallIn() {
                           2356 ;	---------------------------------
                           2357 ; Function FallIn
                           2358 ; ---------------------------------
   57A9                    2359 _FallIn::
                           2360 ;src/main.c:817: spr[0].status = S_falling;
   57A9 21 C6 4B      [10] 2361 	ld	hl, #(_spr + 0x0004)
   57AC 36 05         [10] 2362 	ld	(hl), #0x05
                           2363 ;src/main.c:818: spr[0].jump  = JUMP_STEPS - 3;
   57AE 21 CD 4B      [10] 2364 	ld	hl, #(_spr + 0x000b)
   57B1 36 09         [10] 2365 	ld	(hl), #0x09
   57B3 C9            [10] 2366 	ret
                           2367 ;src/main.c:823: void LandIn() {
                           2368 ;	---------------------------------
                           2369 ; Function LandIn
                           2370 ; ---------------------------------
   57B4                    2371 _LandIn::
                           2372 ;src/main.c:824: spr[0].nFrm = 0;
   57B4 21 C9 4B      [10] 2373 	ld	hl, #(_spr + 0x0007)
   57B7 36 00         [10] 2374 	ld	(hl), #0x00
                           2375 ;src/main.c:825: spr[0].status = S_landing;
   57B9 21 C6 4B      [10] 2376 	ld	hl, #(_spr + 0x0004)
   57BC 36 06         [10] 2377 	ld	(hl), #0x06
   57BE C9            [10] 2378 	ret
                           2379 ;src/main.c:830: void Falling() {
                           2380 ;	---------------------------------
                           2381 ; Function Falling
                           2382 ; ---------------------------------
   57BF                    2383 _Falling::
                           2384 ;src/main.c:831: cpct_scanKeyboard_f(); // check the pressed keys
   57BF CD 3D 3E      [17] 2385 	call	_cpct_scanKeyboard_f
                           2386 ;src/main.c:833: if(cpct_isKeyPressed(ctlDown)) CheckObjects();
   57C2 2A B4 4B      [16] 2387 	ld	hl, (_ctlDown)
   57C5 CD 31 3E      [17] 2388 	call	_cpct_isKeyPressed
   57C8 7D            [ 4] 2389 	ld	a, l
   57C9 B7            [ 4] 2390 	or	a, a
   57CA 28 05         [12] 2391 	jr	Z,00107$
   57CC CD 30 52      [17] 2392 	call	_CheckObjects
   57CF 18 1C         [12] 2393 	jr	00108$
   57D1                    2394 00107$:
                           2395 ;src/main.c:834: else if (cpct_isKeyPressed(ctlLeft)) MoveLeft();
   57D1 2A B6 4B      [16] 2396 	ld	hl, (_ctlLeft)
   57D4 CD 31 3E      [17] 2397 	call	_cpct_isKeyPressed
   57D7 7D            [ 4] 2398 	ld	a, l
   57D8 B7            [ 4] 2399 	or	a, a
   57D9 28 05         [12] 2400 	jr	Z,00104$
   57DB CD 2E 57      [17] 2401 	call	_MoveLeft
   57DE 18 0D         [12] 2402 	jr	00108$
   57E0                    2403 00104$:
                           2404 ;src/main.c:835: else if (cpct_isKeyPressed(ctlRight)) MoveRight();
   57E0 2A B8 4B      [16] 2405 	ld	hl, (_ctlRight)
   57E3 CD 31 3E      [17] 2406 	call	_cpct_isKeyPressed
   57E6 7D            [ 4] 2407 	ld	a, l
   57E7 B7            [ 4] 2408 	or	a, a
   57E8 28 03         [12] 2409 	jr	Z,00108$
   57EA CD 51 57      [17] 2410 	call	_MoveRight
   57ED                    2411 00108$:
                           2412 ;src/main.c:838: spr[0].y += cpct_get2Bits(g_jumpTable, spr[0].jump);	
   57ED 21 C3 4B      [10] 2413 	ld	hl, #(_spr + 0x0001) + 0
   57F0 4E            [ 7] 2414 	ld	c, (hl)
   57F1 21 CD 4B      [10] 2415 	ld	hl, #(_spr + 0x000b) + 0
   57F4 5E            [ 7] 2416 	ld	e, (hl)
   57F5 16 00         [ 7] 2417 	ld	d, #0x00
   57F7 C5            [11] 2418 	push	bc
   57F8 D5            [11] 2419 	push	de
   57F9 21 8A 4C      [10] 2420 	ld	hl, #_g_jumpTable
   57FC E5            [11] 2421 	push	hl
   57FD CD 63 48      [17] 2422 	call	_cpct_get2Bits
   5800 C1            [10] 2423 	pop	bc
   5801 79            [ 4] 2424 	ld	a, c
   5802 85            [ 4] 2425 	add	a, l
   5803 32 C3 4B      [13] 2426 	ld	(#(_spr + 0x0001)),a
                           2427 ;src/main.c:839: if (spr[0].jump > 1) spr[0].jump--;
   5806 21 CD 4B      [10] 2428 	ld	hl, #(_spr + 0x000b) + 0
   5809 4E            [ 7] 2429 	ld	c, (hl)
   580A 3E 01         [ 7] 2430 	ld	a, #0x01
   580C 91            [ 4] 2431 	sub	a, c
   580D 30 05         [12] 2432 	jr	NC,00110$
   580F 0D            [ 4] 2433 	dec	c
   5810 21 CD 4B      [10] 2434 	ld	hl, #(_spr + 0x000b)
   5813 71            [ 7] 2435 	ld	(hl), c
   5814                    2436 00110$:
                           2437 ;src/main.c:841: if (OnPlatform(&spr[0]) || OnStairs()) { // if the player is on a platform ...
   5814 21 C2 4B      [10] 2438 	ld	hl, #_spr
   5817 CD DB 4F      [17] 2439 	call	_OnPlatform
   581A 7D            [ 4] 2440 	ld	a, l
   581B B7            [ 4] 2441 	or	a, a
   581C 20 06         [12] 2442 	jr	NZ,00111$
   581E CD F5 4F      [17] 2443 	call	_OnStairs
   5821 7D            [ 4] 2444 	ld	a, l
   5822 B7            [ 4] 2445 	or	a, a
   5823 C8            [11] 2446 	ret	Z
                           2447 ;src/main.c:842: while ((spr[0].y + 1) % 4 != 0) spr[0].y--; // adjust to the ground			
   5824                    2448 00111$:
                           2449 ;src/main.c:838: spr[0].y += cpct_get2Bits(g_jumpTable, spr[0].jump);	
   5824 21 C3 4B      [10] 2450 	ld	hl, #(_spr + 0x0001) + 0
   5827 4E            [ 7] 2451 	ld	c, (hl)
                           2452 ;src/main.c:842: while ((spr[0].y + 1) % 4 != 0) spr[0].y--; // adjust to the ground			
   5828 59            [ 4] 2453 	ld	e, c
   5829 16 00         [ 7] 2454 	ld	d, #0x00
   582B 13            [ 6] 2455 	inc	de
   582C C5            [11] 2456 	push	bc
   582D 21 04 00      [10] 2457 	ld	hl, #0x0004
   5830 E5            [11] 2458 	push	hl
   5831 D5            [11] 2459 	push	de
   5832 CD 9D 4A      [17] 2460 	call	__modsint
   5835 F1            [10] 2461 	pop	af
   5836 F1            [10] 2462 	pop	af
   5837 C1            [10] 2463 	pop	bc
   5838 7C            [ 4] 2464 	ld	a, h
   5839 B5            [ 4] 2465 	or	a,l
   583A 28 07         [12] 2466 	jr	Z,00113$
   583C 0D            [ 4] 2467 	dec	c
   583D 21 C3 4B      [10] 2468 	ld	hl, #(_spr + 0x0001)
   5840 71            [ 7] 2469 	ld	(hl), c
   5841 18 E1         [12] 2470 	jr	00111$
   5843                    2471 00113$:
                           2472 ;src/main.c:843: LandIn(); // prepare the landing
   5843 CD B4 57      [17] 2473 	call	_LandIn
   5846 C9            [10] 2474 	ret
                           2475 ;src/main.c:849: void StopIn() {
                           2476 ;	---------------------------------
                           2477 ; Function StopIn
                           2478 ; ---------------------------------
   5847                    2479 _StopIn::
                           2480 ;src/main.c:850: spr[0].status = S_stopped;
   5847 21 C6 4B      [10] 2481 	ld	hl, #(_spr + 0x0004)
   584A 36 00         [10] 2482 	ld	(hl), #0x00
   584C C9            [10] 2483 	ret
                           2484 ;src/main.c:855: void Stopped() {
                           2485 ;	---------------------------------
                           2486 ; Function Stopped
                           2487 ; ---------------------------------
   584D                    2488 _Stopped::
                           2489 ;src/main.c:856: cpct_scanKeyboard_f(); // check the pressed keys
   584D CD 3D 3E      [17] 2490 	call	_cpct_scanKeyboard_f
                           2491 ;src/main.c:857: if(cpct_isKeyPressed(ctlUp)) {
   5850 2A B2 4B      [16] 2492 	ld	hl, (_ctlUp)
   5853 CD 31 3E      [17] 2493 	call	_cpct_isKeyPressed
   5856 7D            [ 4] 2494 	ld	a, l
   5857 B7            [ 4] 2495 	or	a, a
   5858 28 0B         [12] 2496 	jr	Z,00131$
                           2497 ;src/main.c:858: if(OnStairs()) ClimbIn(); // going to climb a ladder
   585A CD F5 4F      [17] 2498 	call	_OnStairs
   585D 7D            [ 4] 2499 	ld	a, l
   585E B7            [ 4] 2500 	or	a, a
   585F C2 93 57      [10] 2501 	jp	NZ,_ClimbIn
                           2502 ;src/main.c:859: else PreJumpIn(); // going to jump
   5862 C3 9E 57      [10] 2503 	jp  _PreJumpIn
   5865                    2504 00131$:
                           2505 ;src/main.c:861: else if(cpct_isKeyPressed(ctlDown)) {
   5865 2A B4 4B      [16] 2506 	ld	hl, (_ctlDown)
   5868 CD 31 3E      [17] 2507 	call	_cpct_isKeyPressed
   586B 7D            [ 4] 2508 	ld	a, l
   586C B7            [ 4] 2509 	or	a, a
   586D 28 0B         [12] 2510 	jr	Z,00128$
                           2511 ;src/main.c:862: if(OnStairs()) ClimbIn(); // going down a ladder
   586F CD F5 4F      [17] 2512 	call	_OnStairs
   5872 7D            [ 4] 2513 	ld	a, l
   5873 B7            [ 4] 2514 	or	a, a
   5874 C2 93 57      [10] 2515 	jp	NZ,_ClimbIn
                           2516 ;src/main.c:863: else CheckObjects(); // going to grab / drop an object (if it is on an object)
   5877 C3 30 52      [10] 2517 	jp  _CheckObjects
   587A                    2518 00128$:
                           2519 ;src/main.c:865: else if(cpct_isKeyPressed(ctlLeft)) WalkIn(D_left);
   587A 2A B6 4B      [16] 2520 	ld	hl, (_ctlLeft)
   587D CD 31 3E      [17] 2521 	call	_cpct_isKeyPressed
   5880 7D            [ 4] 2522 	ld	a, l
   5881 B7            [ 4] 2523 	or	a, a
   5882 28 05         [12] 2524 	jr	Z,00125$
   5884 2E 02         [ 7] 2525 	ld	l, #0x02
   5886 C3 83 57      [10] 2526 	jp  _WalkIn
   5889                    2527 00125$:
                           2528 ;src/main.c:866: else if(cpct_isKeyPressed(ctlRight)) WalkIn(D_right);
   5889 2A B8 4B      [16] 2529 	ld	hl, (_ctlRight)
   588C CD 31 3E      [17] 2530 	call	_cpct_isKeyPressed
   588F 7D            [ 4] 2531 	ld	a, l
   5890 B7            [ 4] 2532 	or	a, a
   5891 28 05         [12] 2533 	jr	Z,00122$
   5893 2E 03         [ 7] 2534 	ld	l, #0x03
   5895 C3 83 57      [10] 2535 	jp  _WalkIn
   5898                    2536 00122$:
                           2537 ;src/main.c:868: else if(cpct_isKeyPressed(ctlAbort)) {
   5898 2A BE 4B      [16] 2538 	ld	hl, (_ctlAbort)
   589B CD 31 3E      [17] 2539 	call	_cpct_isKeyPressed
   589E 7D            [ 4] 2540 	ld	a, l
   589F B7            [ 4] 2541 	or	a, a
   58A0 28 0E         [12] 2542 	jr	Z,00119$
                           2543 ;src/main.c:869: spr[0].lives = 0; 
   58A2 21 CB 4B      [10] 2544 	ld	hl, #(_spr + 0x0009)
   58A5 36 00         [10] 2545 	ld	(hl), #0x00
                           2546 ;src/main.c:870: ExplodePlayer();
   58A7 CD DC 5A      [17] 2547 	call	_ExplodePlayer
                           2548 ;src/main.c:871: ExplodeEnemies();
   58AA CD D1 5F      [17] 2549 	call	_ExplodeEnemies
                           2550 ;src/main.c:872: GameOver();
   58AD C3 C8 62      [10] 2551 	jp  _GameOver
   58B0                    2552 00119$:
                           2553 ;src/main.c:875: else if(cpct_isKeyPressed(ctlMusic)) {
   58B0 2A BC 4B      [16] 2554 	ld	hl, (_ctlMusic)
   58B3 CD 31 3E      [17] 2555 	call	_cpct_isKeyPressed
   58B6 7D            [ 4] 2556 	ld	a, l
   58B7 B7            [ 4] 2557 	or	a, a
   58B8 28 2B         [12] 2558 	jr	Z,00116$
                           2559 ;src/main.c:876: Wait4Key(ctlMusic);
   58BA 2A BC 4B      [16] 2560 	ld	hl, (_ctlMusic)
   58BD CD D9 50      [17] 2561 	call	_Wait4Key
                           2562 ;src/main.c:877: if (music == TRUE) { // if the music is playing ...
   58C0 FD 21 AF 4B   [14] 2563 	ld	iy, #_music
   58C4 FD 7E 00      [19] 2564 	ld	a, 0 (iy)
   58C7 3D            [ 4] 2565 	dec	a
   58C8 20 0D         [12] 2566 	jr	NZ,00108$
                           2567 ;src/main.c:878: music = FALSE;
   58CA FD 36 00 00   [19] 2568 	ld	0 (iy), #0x00
                           2569 ;src/main.c:879: cpct_akp_musicInit(FX);
   58CE 21 00 02      [10] 2570 	ld	hl, #_FX
   58D1 E5            [11] 2571 	push	hl
   58D2 CD B8 45      [17] 2572 	call	_cpct_akp_musicInit
   58D5 F1            [10] 2573 	pop	af
   58D6 C9            [10] 2574 	ret
   58D7                    2575 00108$:
                           2576 ;src/main.c:882: music = TRUE;			
   58D7 21 AF 4B      [10] 2577 	ld	hl,#_music + 0
   58DA 36 01         [10] 2578 	ld	(hl), #0x01
                           2579 ;src/main.c:883: cpct_akp_musicInit(Ingame1);
   58DC 21 75 0B      [10] 2580 	ld	hl, #_Ingame1
   58DF E5            [11] 2581 	push	hl
   58E0 CD B8 45      [17] 2582 	call	_cpct_akp_musicInit
   58E3 F1            [10] 2583 	pop	af
   58E4 C9            [10] 2584 	ret
   58E5                    2585 00116$:
                           2586 ;src/main.c:887: else if(cpct_isKeyPressed(ctlPause)) {
   58E5 2A C0 4B      [16] 2587 	ld	hl, (_ctlPause)
   58E8 CD 31 3E      [17] 2588 	call	_cpct_isKeyPressed
   58EB 7D            [ 4] 2589 	ld	a, l
   58EC B7            [ 4] 2590 	or	a, a
   58ED C8            [11] 2591 	ret	Z
                           2592 ;src/main.c:888: Wait4Key(ctlPause);
   58EE 2A C0 4B      [16] 2593 	ld	hl, (_ctlPause)
   58F1 CD D9 50      [17] 2594 	call	_Wait4Key
                           2595 ;src/main.c:889: cpct_akp_musicInit(FX);
   58F4 21 00 02      [10] 2596 	ld	hl, #_FX
   58F7 E5            [11] 2597 	push	hl
   58F8 CD B8 45      [17] 2598 	call	_cpct_akp_musicInit
   58FB F1            [10] 2599 	pop	af
                           2600 ;src/main.c:890: while (!cpct_isAnyKeyPressed());
   58FC                    2601 00110$:
   58FC CD 56 48      [17] 2602 	call	_cpct_isAnyKeyPressed
   58FF 7D            [ 4] 2603 	ld	a, l
   5900 B7            [ 4] 2604 	or	a, a
   5901 28 F9         [12] 2605 	jr	Z,00110$
                           2606 ;src/main.c:891: Wait4Key(ctlPause);
   5903 2A C0 4B      [16] 2607 	ld	hl, (_ctlPause)
   5906 CD D9 50      [17] 2608 	call	_Wait4Key
                           2609 ;src/main.c:892: cpct_akp_musicInit(Ingame1);
   5909 21 75 0B      [10] 2610 	ld	hl, #_Ingame1
   590C E5            [11] 2611 	push	hl
   590D CD B8 45      [17] 2612 	call	_cpct_akp_musicInit
   5910 F1            [10] 2613 	pop	af
   5911 C9            [10] 2614 	ret
                           2615 ;src/main.c:898: void JumpIn() {
                           2616 ;	---------------------------------
                           2617 ; Function JumpIn
                           2618 ; ---------------------------------
   5912                    2619 _JumpIn::
                           2620 ;src/main.c:899: spr[0].status = S_jumping;
   5912 21 C6 4B      [10] 2621 	ld	hl, #(_spr + 0x0004)
   5915 36 03         [10] 2622 	ld	(hl), #0x03
                           2623 ;src/main.c:900: spr[0].jump  = 0;
   5917 21 CD 4B      [10] 2624 	ld	hl, #(_spr + 0x000b)
   591A 36 00         [10] 2625 	ld	(hl), #0x00
                           2626 ;src/main.c:901: cpct_akp_SFXPlay(3, 15, 32, 0, 0, AY_CHANNEL_C);
   591C 3E 04         [ 7] 2627 	ld	a, #0x04
   591E F5            [11] 2628 	push	af
   591F 33            [ 6] 2629 	inc	sp
   5920 21 00 00      [10] 2630 	ld	hl, #0x0000
   5923 E5            [11] 2631 	push	hl
   5924 2E 20         [ 7] 2632 	ld	l, #0x20
   5926 E5            [11] 2633 	push	hl
   5927 21 03 0F      [10] 2634 	ld	hl, #0x0f03
   592A E5            [11] 2635 	push	hl
   592B CD 5F 46      [17] 2636 	call	_cpct_akp_SFXPlay
   592E 21 07 00      [10] 2637 	ld	hl, #7
   5931 39            [11] 2638 	add	hl, sp
   5932 F9            [ 6] 2639 	ld	sp, hl
   5933 C9            [10] 2640 	ret
                           2641 ;src/main.c:905: void Jumping() {
                           2642 ;	---------------------------------
                           2643 ; Function Jumping
                           2644 ; ---------------------------------
   5934                    2645 _Jumping::
                           2646 ;src/main.c:906: cpct_scanKeyboard_f(); // check the pressed keys
   5934 CD 3D 3E      [17] 2647 	call	_cpct_scanKeyboard_f
                           2648 ;src/main.c:907: if(!cpct_isKeyPressed(ctlUp)) FallIn();
   5937 2A B2 4B      [16] 2649 	ld	hl, (_ctlUp)
   593A CD 31 3E      [17] 2650 	call	_cpct_isKeyPressed
   593D 7D            [ 4] 2651 	ld	a, l
   593E B7            [ 4] 2652 	or	a, a
   593F 20 05         [12] 2653 	jr	NZ,00110$
   5941 CD A9 57      [17] 2654 	call	_FallIn
   5944 18 2B         [12] 2655 	jr	00111$
   5946                    2656 00110$:
                           2657 ;src/main.c:909: if(cpct_isKeyPressed(ctlDown)) CheckObjects();
   5946 2A B4 4B      [16] 2658 	ld	hl, (_ctlDown)
   5949 CD 31 3E      [17] 2659 	call	_cpct_isKeyPressed
   594C 7D            [ 4] 2660 	ld	a, l
   594D B7            [ 4] 2661 	or	a, a
   594E 28 05         [12] 2662 	jr	Z,00107$
   5950 CD 30 52      [17] 2663 	call	_CheckObjects
   5953 18 1C         [12] 2664 	jr	00111$
   5955                    2665 00107$:
                           2666 ;src/main.c:910: else if (cpct_isKeyPressed(ctlLeft)) MoveLeft();
   5955 2A B6 4B      [16] 2667 	ld	hl, (_ctlLeft)
   5958 CD 31 3E      [17] 2668 	call	_cpct_isKeyPressed
   595B 7D            [ 4] 2669 	ld	a, l
   595C B7            [ 4] 2670 	or	a, a
   595D 28 05         [12] 2671 	jr	Z,00104$
   595F CD 2E 57      [17] 2672 	call	_MoveLeft
   5962 18 0D         [12] 2673 	jr	00111$
   5964                    2674 00104$:
                           2675 ;src/main.c:911: else if (cpct_isKeyPressed(ctlRight)) MoveRight();
   5964 2A B8 4B      [16] 2676 	ld	hl, (_ctlRight)
   5967 CD 31 3E      [17] 2677 	call	_cpct_isKeyPressed
   596A 7D            [ 4] 2678 	ld	a, l
   596B B7            [ 4] 2679 	or	a, a
   596C 28 03         [12] 2680 	jr	Z,00111$
   596E CD 51 57      [17] 2681 	call	_MoveRight
   5971                    2682 00111$:
                           2683 ;src/main.c:914: spr[0].y -= cpct_get2Bits(g_jumpTable, spr[0].jump);
   5971 21 C3 4B      [10] 2684 	ld	hl, #(_spr + 0x0001) + 0
   5974 4E            [ 7] 2685 	ld	c, (hl)
   5975 21 CD 4B      [10] 2686 	ld	hl, #(_spr + 0x000b) + 0
   5978 5E            [ 7] 2687 	ld	e, (hl)
   5979 16 00         [ 7] 2688 	ld	d, #0x00
   597B C5            [11] 2689 	push	bc
   597C D5            [11] 2690 	push	de
   597D 21 8A 4C      [10] 2691 	ld	hl, #_g_jumpTable
   5980 E5            [11] 2692 	push	hl
   5981 CD 63 48      [17] 2693 	call	_cpct_get2Bits
   5984 C1            [10] 2694 	pop	bc
   5985 79            [ 4] 2695 	ld	a, c
   5986 95            [ 4] 2696 	sub	a, l
   5987 21 C3 4B      [10] 2697 	ld	hl, #(_spr + 0x0001)
   598A 77            [ 7] 2698 	ld	(hl), a
                           2699 ;src/main.c:916: if (spr[0].y < ORIG_MAP_Y) spr[0].y = ORIG_MAP_Y;
   598B D6 28         [ 7] 2700 	sub	a, #0x28
   598D 30 02         [12] 2701 	jr	NC,00113$
   598F 36 28         [10] 2702 	ld	(hl), #0x28
   5991                    2703 00113$:
                           2704 ;src/main.c:918: if (++spr[0].jump == JUMP_STEPS)	FallIn();
   5991 3A CD 4B      [13] 2705 	ld	a, (#(_spr + 0x000b) + 0)
   5994 3C            [ 4] 2706 	inc	a
   5995 32 CD 4B      [13] 2707 	ld	(#(_spr + 0x000b)),a
   5998 D6 0C         [ 7] 2708 	sub	a, #0x0c
   599A C0            [11] 2709 	ret	NZ
   599B CD A9 57      [17] 2710 	call	_FallIn
   599E C9            [10] 2711 	ret
                           2712 ;src/main.c:922: void PreJump() {
                           2713 ;	---------------------------------
                           2714 ; Function PreJump
                           2715 ; ---------------------------------
   599F                    2716 _PreJump::
                           2717 ;src/main.c:923: cpct_scanKeyboard_f(); // check the pressed keys
   599F CD 3D 3E      [17] 2718 	call	_cpct_scanKeyboard_f
                           2719 ;src/main.c:924: if(cpct_isKeyPressed(ctlUp)) JumpIn();
   59A2 2A B2 4B      [16] 2720 	ld	hl, (_ctlUp)
   59A5 CD 31 3E      [17] 2721 	call	_cpct_isKeyPressed
   59A8 7D            [ 4] 2722 	ld	a, l
   59A9 B7            [ 4] 2723 	or	a, a
   59AA C2 12 59      [10] 2724 	jp	NZ,_JumpIn
                           2725 ;src/main.c:925: else StopIn();	
   59AD C3 47 58      [10] 2726 	jp  _StopIn
                           2727 ;src/main.c:930: void WalkAnim(u8 dir) __z88dk_fastcall {
                           2728 ;	---------------------------------
                           2729 ; Function WalkAnim
                           2730 ; ---------------------------------
   59B0                    2731 _WalkAnim::
   59B0 4D            [ 4] 2732 	ld	c, l
                           2733 ;src/main.c:931: spr[0].dir  = dir;
   59B1 21 CA 4B      [10] 2734 	ld	hl, #(_spr + 0x0008)
   59B4 71            [ 7] 2735 	ld	(hl), c
                           2736 ;src/main.c:932: if(++spr[0].nFrm == 4 * ANIM_PAUSE) spr[0].nFrm = 0;
   59B5 01 C9 4B      [10] 2737 	ld	bc, #_spr + 7
   59B8 0A            [ 7] 2738 	ld	a, (bc)
   59B9 3C            [ 4] 2739 	inc	a
   59BA 02            [ 7] 2740 	ld	(bc), a
   59BB D6 0C         [ 7] 2741 	sub	a, #0x0c
   59BD C0            [11] 2742 	ret	NZ
   59BE AF            [ 4] 2743 	xor	a, a
   59BF 02            [ 7] 2744 	ld	(bc), a
   59C0 C9            [10] 2745 	ret
                           2746 ;src/main.c:936: void Walking() {
                           2747 ;	---------------------------------
                           2748 ; Function Walking
                           2749 ; ---------------------------------
   59C1                    2750 _Walking::
                           2751 ;src/main.c:937: cpct_scanKeyboard_f(); // check the pressed keys
   59C1 CD 3D 3E      [17] 2752 	call	_cpct_scanKeyboard_f
                           2753 ;src/main.c:938: if (cpct_isKeyPressed(ctlUp)) {
   59C4 2A B2 4B      [16] 2754 	ld	hl, (_ctlUp)
   59C7 CD 31 3E      [17] 2755 	call	_cpct_isKeyPressed
   59CA 7D            [ 4] 2756 	ld	a, l
   59CB B7            [ 4] 2757 	or	a, a
   59CC 28 11         [12] 2758 	jr	Z,00117$
                           2759 ;src/main.c:939: if (OnStairs()) ClimbIn(); // going to climb a ladder
   59CE CD F5 4F      [17] 2760 	call	_OnStairs
   59D1 7D            [ 4] 2761 	ld	a, l
   59D2 B7            [ 4] 2762 	or	a, a
   59D3 28 05         [12] 2763 	jr	Z,00102$
   59D5 CD 93 57      [17] 2764 	call	_ClimbIn
   59D8 18 4B         [12] 2765 	jr	00118$
   59DA                    2766 00102$:
                           2767 ;src/main.c:940: else PreJumpIn(); // going to jump
   59DA CD 9E 57      [17] 2768 	call	_PreJumpIn
   59DD 18 46         [12] 2769 	jr	00118$
   59DF                    2770 00117$:
                           2771 ;src/main.c:942: else if (cpct_isKeyPressed(ctlDown)) {
   59DF 2A B4 4B      [16] 2772 	ld	hl, (_ctlDown)
   59E2 CD 31 3E      [17] 2773 	call	_cpct_isKeyPressed
   59E5 7D            [ 4] 2774 	ld	a, l
   59E6 B7            [ 4] 2775 	or	a, a
   59E7 28 11         [12] 2776 	jr	Z,00114$
                           2777 ;src/main.c:943: if (OnStairs()) ClimbIn(); // going down a ladder
   59E9 CD F5 4F      [17] 2778 	call	_OnStairs
   59EC 7D            [ 4] 2779 	ld	a, l
   59ED B7            [ 4] 2780 	or	a, a
   59EE 28 05         [12] 2781 	jr	Z,00105$
   59F0 CD 93 57      [17] 2782 	call	_ClimbIn
   59F3 18 30         [12] 2783 	jr	00118$
   59F5                    2784 00105$:
                           2785 ;src/main.c:944: else CheckObjects(); // going to grab / drop an object (if it is on an object)
   59F5 CD 30 52      [17] 2786 	call	_CheckObjects
   59F8 18 2B         [12] 2787 	jr	00118$
   59FA                    2788 00114$:
                           2789 ;src/main.c:946: else if (cpct_isKeyPressed(ctlLeft)) {MoveLeft(); WalkAnim(D_left);}
   59FA 2A B6 4B      [16] 2790 	ld	hl, (_ctlLeft)
   59FD CD 31 3E      [17] 2791 	call	_cpct_isKeyPressed
   5A00 7D            [ 4] 2792 	ld	a, l
   5A01 B7            [ 4] 2793 	or	a, a
   5A02 28 0A         [12] 2794 	jr	Z,00111$
   5A04 CD 2E 57      [17] 2795 	call	_MoveLeft
   5A07 2E 02         [ 7] 2796 	ld	l, #0x02
   5A09 CD B0 59      [17] 2797 	call	_WalkAnim
   5A0C 18 17         [12] 2798 	jr	00118$
   5A0E                    2799 00111$:
                           2800 ;src/main.c:947: else if (cpct_isKeyPressed(ctlRight)) {MoveRight(); WalkAnim(D_right);}
   5A0E 2A B8 4B      [16] 2801 	ld	hl, (_ctlRight)
   5A11 CD 31 3E      [17] 2802 	call	_cpct_isKeyPressed
   5A14 7D            [ 4] 2803 	ld	a, l
   5A15 B7            [ 4] 2804 	or	a, a
   5A16 28 0A         [12] 2805 	jr	Z,00108$
   5A18 CD 51 57      [17] 2806 	call	_MoveRight
   5A1B 2E 03         [ 7] 2807 	ld	l, #0x03
   5A1D CD B0 59      [17] 2808 	call	_WalkAnim
   5A20 18 03         [12] 2809 	jr	00118$
   5A22                    2810 00108$:
                           2811 ;src/main.c:948: else StopIn();
   5A22 CD 47 58      [17] 2812 	call	_StopIn
   5A25                    2813 00118$:
                           2814 ;src/main.c:950: if (!OnPlatform(&spr[0])) // if it is not on a platform, it is also falling
   5A25 21 C2 4B      [10] 2815 	ld	hl, #_spr
   5A28 CD DB 4F      [17] 2816 	call	_OnPlatform
   5A2B 7D            [ 4] 2817 	ld	a, l
   5A2C B7            [ 4] 2818 	or	a, a
   5A2D C0            [11] 2819 	ret	NZ
                           2820 ;src/main.c:951: FallIn();
   5A2E C3 A9 57      [10] 2821 	jp  _FallIn
                           2822 ;src/main.c:955: void Climbing() {
                           2823 ;	---------------------------------
                           2824 ; Function Climbing
                           2825 ; ---------------------------------
   5A31                    2826 _Climbing::
                           2827 ;src/main.c:956: cpct_scanKeyboard_f(); // check the pressed keys
   5A31 CD 3D 3E      [17] 2828 	call	_cpct_scanKeyboard_f
                           2829 ;src/main.c:957: if(cpct_isKeyPressed(ctlUp)) {
   5A34 2A B2 4B      [16] 2830 	ld	hl, (_ctlUp)
   5A37 CD 31 3E      [17] 2831 	call	_cpct_isKeyPressed
   5A3A 7D            [ 4] 2832 	ld	a, l
   5A3B B7            [ 4] 2833 	or	a, a
   5A3C 28 0E         [12] 2834 	jr	Z,00120$
                           2835 ;src/main.c:958: if(OnStairs()) {MoveUp(); WalkAnim(D_right);} 
   5A3E CD F5 4F      [17] 2836 	call	_OnStairs
   5A41 7D            [ 4] 2837 	ld	a, l
   5A42 B7            [ 4] 2838 	or	a, a
   5A43 C8            [11] 2839 	ret	Z
   5A44 CD 04 57      [17] 2840 	call	_MoveUp
   5A47 2E 03         [ 7] 2841 	ld	l, #0x03
   5A49 C3 B0 59      [10] 2842 	jp  _WalkAnim
   5A4C                    2843 00120$:
                           2844 ;src/main.c:960: else if(cpct_isKeyPressed(ctlDown))	{
   5A4C 2A B4 4B      [16] 2845 	ld	hl, (_ctlDown)
   5A4F CD 31 3E      [17] 2846 	call	_cpct_isKeyPressed
   5A52 7D            [ 4] 2847 	ld	a, l
   5A53 B7            [ 4] 2848 	or	a, a
   5A54 28 0E         [12] 2849 	jr	Z,00117$
                           2850 ;src/main.c:961: if(OnStairs()) {MoveDown(); WalkAnim(D_right);}
   5A56 CD F5 4F      [17] 2851 	call	_OnStairs
   5A59 7D            [ 4] 2852 	ld	a, l
   5A5A B7            [ 4] 2853 	or	a, a
   5A5B C8            [11] 2854 	ret	Z
   5A5C CD 11 57      [17] 2855 	call	_MoveDown
   5A5F 2E 03         [ 7] 2856 	ld	l, #0x03
   5A61 C3 B0 59      [10] 2857 	jp  _WalkAnim
   5A64                    2858 00117$:
                           2859 ;src/main.c:963: else if(cpct_isKeyPressed(ctlLeft)) {
   5A64 2A B6 4B      [16] 2860 	ld	hl, (_ctlLeft)
   5A67 CD 31 3E      [17] 2861 	call	_cpct_isKeyPressed
   5A6A 7D            [ 4] 2862 	ld	a, l
   5A6B B7            [ 4] 2863 	or	a, a
   5A6C 28 15         [12] 2864 	jr	Z,00114$
                           2865 ;src/main.c:964: if(OnStairs()) {MoveLeft(); WalkAnim(D_left);} 
   5A6E CD F5 4F      [17] 2866 	call	_OnStairs
   5A71 7D            [ 4] 2867 	ld	a, l
   5A72 B7            [ 4] 2868 	or	a, a
   5A73 28 08         [12] 2869 	jr	Z,00106$
   5A75 CD 2E 57      [17] 2870 	call	_MoveLeft
   5A78 2E 02         [ 7] 2871 	ld	l, #0x02
   5A7A C3 B0 59      [10] 2872 	jp  _WalkAnim
   5A7D                    2873 00106$:
                           2874 ;src/main.c:965: else spr[0].status = S_walking;
   5A7D 21 C6 4B      [10] 2875 	ld	hl, #(_spr + 0x0004)
   5A80 36 01         [10] 2876 	ld	(hl), #0x01
   5A82 C9            [10] 2877 	ret
   5A83                    2878 00114$:
                           2879 ;src/main.c:967: else if(cpct_isKeyPressed(ctlRight)) {
   5A83 2A B8 4B      [16] 2880 	ld	hl, (_ctlRight)
   5A86 CD 31 3E      [17] 2881 	call	_cpct_isKeyPressed
   5A89 7D            [ 4] 2882 	ld	a, l
   5A8A B7            [ 4] 2883 	or	a, a
   5A8B C8            [11] 2884 	ret	Z
                           2885 ;src/main.c:968: if(OnStairs()) {MoveRight(); WalkAnim(D_right);} 
   5A8C CD F5 4F      [17] 2886 	call	_OnStairs
   5A8F 7D            [ 4] 2887 	ld	a, l
   5A90 B7            [ 4] 2888 	or	a, a
   5A91 28 08         [12] 2889 	jr	Z,00109$
   5A93 CD 51 57      [17] 2890 	call	_MoveRight
   5A96 2E 03         [ 7] 2891 	ld	l, #0x03
   5A98 C3 B0 59      [10] 2892 	jp  _WalkAnim
   5A9B                    2893 00109$:
                           2894 ;src/main.c:969: else spr[0].status = S_walking;
   5A9B 21 C6 4B      [10] 2895 	ld	hl, #(_spr + 0x0004)
   5A9E 36 01         [10] 2896 	ld	(hl), #0x01
   5AA0 C9            [10] 2897 	ret
                           2898 ;src/main.c:975: void RunStatus() {
                           2899 ;	---------------------------------
                           2900 ; Function RunStatus
                           2901 ; ---------------------------------
   5AA1                    2902 _RunStatus::
                           2903 ;src/main.c:976: switch(spr[0].status) {
   5AA1 21 C6 4B      [10] 2904 	ld	hl, #(_spr + 0x0004) + 0
   5AA4 4E            [ 7] 2905 	ld	c, (hl)
   5AA5 3E 06         [ 7] 2906 	ld	a, #0x06
   5AA7 91            [ 4] 2907 	sub	a, c
   5AA8 D8            [11] 2908 	ret	C
   5AA9 06 00         [ 7] 2909 	ld	b, #0x00
   5AAB 21 B2 5A      [10] 2910 	ld	hl, #00115$
   5AAE 09            [11] 2911 	add	hl, bc
   5AAF 09            [11] 2912 	add	hl, bc
   5AB0 09            [11] 2913 	add	hl, bc
   5AB1 E9            [ 4] 2914 	jp	(hl)
   5AB2                    2915 00115$:
   5AB2 C3 4D 58      [10] 2916 	jp	_Stopped
   5AB5 C3 C1 59      [10] 2917 	jp	_Walking
   5AB8 C3 9F 59      [10] 2918 	jp	_PreJump
   5ABB C3 34 59      [10] 2919 	jp	_Jumping
   5ABE C3 31 5A      [10] 2920 	jp	_Climbing
   5AC1 C3 BF 57      [10] 2921 	jp	_Falling
   5AC4 C3 47 58      [10] 2922 	jp	_StopIn
                           2923 ;src/main.c:977: case S_stopped:       	Stopped();			break;
   5AC7 C3 4D 58      [10] 2924 	jp  _Stopped
                           2925 ;src/main.c:978: case S_walking:      	Walking();			break;
   5ACA C3 C1 59      [10] 2926 	jp  _Walking
                           2927 ;src/main.c:979: case S_climbing:    	Climbing();			break;
   5ACD C3 31 5A      [10] 2928 	jp  _Climbing
                           2929 ;src/main.c:980: case S_preJump:   		PreJump();			break;
   5AD0 C3 9F 59      [10] 2930 	jp  _PreJump
                           2931 ;src/main.c:981: case S_jumping:     	Jumping();			break;
   5AD3 C3 34 59      [10] 2932 	jp  _Jumping
                           2933 ;src/main.c:982: case S_falling:      	Falling();			break;
   5AD6 C3 BF 57      [10] 2934 	jp  _Falling
                           2935 ;src/main.c:983: case S_landing:  		StopIn();
                           2936 ;src/main.c:984: }
   5AD9 C3 47 58      [10] 2937 	jp  _StopIn
                           2938 ;src/main.c:989: void ExplodePlayer() {
                           2939 ;	---------------------------------
                           2940 ; Function ExplodePlayer
                           2941 ; ---------------------------------
   5ADC                    2942 _ExplodePlayer::
                           2943 ;src/main.c:991: cpct_akp_SFXPlay (4, 15, 40, 0, 0, AY_CHANNEL_A); // explosion
   5ADC 3E 01         [ 7] 2944 	ld	a, #0x01
   5ADE F5            [11] 2945 	push	af
   5ADF 33            [ 6] 2946 	inc	sp
   5AE0 21 00 00      [10] 2947 	ld	hl, #0x0000
   5AE3 E5            [11] 2948 	push	hl
   5AE4 2E 28         [ 7] 2949 	ld	l, #0x28
   5AE6 E5            [11] 2950 	push	hl
   5AE7 21 04 0F      [10] 2951 	ld	hl, #0x0f04
   5AEA E5            [11] 2952 	push	hl
   5AEB CD 5F 46      [17] 2953 	call	_cpct_akp_SFXPlay
   5AEE 21 07 00      [10] 2954 	ld	hl, #7
   5AF1 39            [11] 2955 	add	hl, sp
   5AF2 F9            [ 6] 2956 	ld	sp, hl
                           2957 ;src/main.c:992: PrintExplosion(&spr[0], 0); Pause(20);
   5AF3 AF            [ 4] 2958 	xor	a, a
   5AF4 F5            [11] 2959 	push	af
   5AF5 33            [ 6] 2960 	inc	sp
   5AF6 21 C2 4B      [10] 2961 	ld	hl, #_spr
   5AF9 E5            [11] 2962 	push	hl
   5AFA CD FE 54      [17] 2963 	call	_PrintExplosion
   5AFD F1            [10] 2964 	pop	af
   5AFE 33            [ 6] 2965 	inc	sp
   5AFF 21 14 00      [10] 2966 	ld	hl, #0x0014
   5B02 CD B4 4D      [17] 2967 	call	_Pause
                           2968 ;src/main.c:993: PrintExplosion(&spr[0], 1); Pause(20);
   5B05 3E 01         [ 7] 2969 	ld	a, #0x01
   5B07 F5            [11] 2970 	push	af
   5B08 33            [ 6] 2971 	inc	sp
   5B09 21 C2 4B      [10] 2972 	ld	hl, #_spr
   5B0C E5            [11] 2973 	push	hl
   5B0D CD FE 54      [17] 2974 	call	_PrintExplosion
   5B10 F1            [10] 2975 	pop	af
   5B11 33            [ 6] 2976 	inc	sp
   5B12 21 14 00      [10] 2977 	ld	hl, #0x0014
   5B15 CD B4 4D      [17] 2978 	call	_Pause
                           2979 ;src/main.c:994: PrintExplosion(&spr[0], 0); Pause(20);
   5B18 AF            [ 4] 2980 	xor	a, a
   5B19 F5            [11] 2981 	push	af
   5B1A 33            [ 6] 2982 	inc	sp
   5B1B 21 C2 4B      [10] 2983 	ld	hl, #_spr
   5B1E E5            [11] 2984 	push	hl
   5B1F CD FE 54      [17] 2985 	call	_PrintExplosion
   5B22 F1            [10] 2986 	pop	af
   5B23 33            [ 6] 2987 	inc	sp
   5B24 21 14 00      [10] 2988 	ld	hl, #0x0014
   5B27 CD B4 4D      [17] 2989 	call	_Pause
                           2990 ;src/main.c:995: DeleteSprite(&spr[0]);
   5B2A 21 C2 4B      [10] 2991 	ld	hl, #_spr
   5B2D C3 90 54      [10] 2992 	jp  _DeleteSprite
                           2993 ;src/main.c:1012: void MoveEnemy(TSpr *pSpr) { //__z88dk_fastcall
                           2994 ;	---------------------------------
                           2995 ; Function MoveEnemy
                           2996 ; ---------------------------------
   5B30                    2997 _MoveEnemy::
   5B30 DD E5         [15] 2998 	push	ix
   5B32 DD 21 00 00   [14] 2999 	ld	ix,#0
   5B36 DD 39         [15] 3000 	add	ix,sp
   5B38 21 F7 FF      [10] 3001 	ld	hl, #-9
   5B3B 39            [11] 3002 	add	hl, sp
   5B3C F9            [ 6] 3003 	ld	sp, hl
                           3004 ;src/main.c:1013: switch(pSpr->movType) 
   5B3D DD 4E 04      [19] 3005 	ld	c,4 (ix)
   5B40 DD 46 05      [19] 3006 	ld	b,5 (ix)
   5B43 C5            [11] 3007 	push	bc
   5B44 FD E1         [14] 3008 	pop	iy
   5B46 FD 7E 11      [19] 3009 	ld	a, 17 (iy)
   5B49 DD 77 FD      [19] 3010 	ld	-3 (ix), a
                           3011 ;src/main.c:1017: if (pSpr->dir == D_right) {
   5B4C 21 08 00      [10] 3012 	ld	hl, #0x0008
   5B4F 09            [11] 3013 	add	hl,bc
   5B50 EB            [ 4] 3014 	ex	de,hl
                           3015 ;src/main.c:1018: if (pSpr->x < pSpr->xMax) pSpr->x++;
   5B51 21 0E 00      [10] 3016 	ld	hl, #0x000e
   5B54 09            [11] 3017 	add	hl,bc
   5B55 E3            [19] 3018 	ex	(sp), hl
                           3019 ;src/main.c:1022: if (pSpr->x > pSpr->xMin) pSpr->x--;
   5B56 21 0D 00      [10] 3020 	ld	hl, #0x000d
   5B59 09            [11] 3021 	add	hl,bc
   5B5A DD 75 FE      [19] 3022 	ld	-2 (ix), l
   5B5D DD 74 FF      [19] 3023 	ld	-1 (ix), h
                           3024 ;src/main.c:1013: switch(pSpr->movType) 
   5B60 DD 7E FD      [19] 3025 	ld	a, -3 (ix)
   5B63 B7            [ 4] 3026 	or	a, a
   5B64 28 2B         [12] 3027 	jr	Z,00101$
                           3028 ;src/main.c:1030: if (pSpr->y < pSpr->yMax) pSpr->y += 2;
   5B66 21 01 00      [10] 3029 	ld	hl, #0x0001
   5B69 09            [11] 3030 	add	hl,bc
   5B6A DD 75 FB      [19] 3031 	ld	-5 (ix), l
   5B6D DD 74 FC      [19] 3032 	ld	-4 (ix), h
   5B70 21 10 00      [10] 3033 	ld	hl, #0x0010
   5B73 09            [11] 3034 	add	hl,bc
   5B74 DD 75 F9      [19] 3035 	ld	-7 (ix), l
   5B77 DD 74 FA      [19] 3036 	ld	-6 (ix), h
                           3037 ;src/main.c:1034: if (pSpr->y > pSpr->yMin) pSpr->y -= 2;
   5B7A FD 21 0F 00   [14] 3038 	ld	iy, #0x000f
   5B7E FD 09         [15] 3039 	add	iy, bc
                           3040 ;src/main.c:1013: switch(pSpr->movType) 
   5B80 DD 7E FD      [19] 3041 	ld	a, -3 (ix)
   5B83 3D            [ 4] 3042 	dec	a
   5B84 28 47         [12] 3043 	jr	Z,00111$
   5B86 DD 7E FD      [19] 3044 	ld	a, -3 (ix)
   5B89 D6 02         [ 7] 3045 	sub	a, #0x02
   5B8B CA 0C 5C      [10] 3046 	jp	Z,00121$
   5B8E C3 17 5D      [10] 3047 	jp	00162$
                           3048 ;src/main.c:1016: case M_linear_X:
   5B91                    3049 00101$:
                           3050 ;src/main.c:1017: if (pSpr->dir == D_right) {
   5B91 1A            [ 7] 3051 	ld	a, (de)
                           3052 ;src/main.c:1018: if (pSpr->x < pSpr->xMax) pSpr->x++;
   5B92 F5            [11] 3053 	push	af
   5B93 0A            [ 7] 3054 	ld	a, (bc)
   5B94 DD 77 FD      [19] 3055 	ld	-3 (ix), a
   5B97 F1            [10] 3056 	pop	af
                           3057 ;src/main.c:1017: if (pSpr->dir == D_right) {
   5B98 D6 03         [ 7] 3058 	sub	a, #0x03
   5B9A 20 16         [12] 3059 	jr	NZ,00109$
                           3060 ;src/main.c:1018: if (pSpr->x < pSpr->xMax) pSpr->x++;
   5B9C E1            [10] 3061 	pop	hl
   5B9D E5            [11] 3062 	push	hl
   5B9E DD 7E FD      [19] 3063 	ld	a,-3 (ix)
   5BA1 96            [ 7] 3064 	sub	a,(hl)
   5BA2 30 08         [12] 3065 	jr	NC,00103$
   5BA4 DD 7E FD      [19] 3066 	ld	a, -3 (ix)
   5BA7 3C            [ 4] 3067 	inc	a
   5BA8 02            [ 7] 3068 	ld	(bc), a
   5BA9 C3 17 5D      [10] 3069 	jp	00162$
   5BAC                    3070 00103$:
                           3071 ;src/main.c:1019: else pSpr->dir = D_left;
   5BAC 3E 02         [ 7] 3072 	ld	a, #0x02
   5BAE 12            [ 7] 3073 	ld	(de), a
   5BAF C3 17 5D      [10] 3074 	jp	00162$
   5BB2                    3075 00109$:
                           3076 ;src/main.c:1022: if (pSpr->x > pSpr->xMin) pSpr->x--;
   5BB2 DD 6E FE      [19] 3077 	ld	l,-2 (ix)
   5BB5 DD 66 FF      [19] 3078 	ld	h,-1 (ix)
   5BB8 7E            [ 7] 3079 	ld	a, (hl)
   5BB9 DD 96 FD      [19] 3080 	sub	a, -3 (ix)
   5BBC 30 09         [12] 3081 	jr	NC,00106$
   5BBE DD 5E FD      [19] 3082 	ld	e, -3 (ix)
   5BC1 1D            [ 4] 3083 	dec	e
   5BC2 7B            [ 4] 3084 	ld	a, e
   5BC3 02            [ 7] 3085 	ld	(bc), a
   5BC4 C3 17 5D      [10] 3086 	jp	00162$
   5BC7                    3087 00106$:
                           3088 ;src/main.c:1023: else pSpr->dir = D_right; 
   5BC7 3E 03         [ 7] 3089 	ld	a, #0x03
   5BC9 12            [ 7] 3090 	ld	(de), a
                           3091 ;src/main.c:1025: break;
   5BCA C3 17 5D      [10] 3092 	jp	00162$
                           3093 ;src/main.c:1028: case M_linear_Y:
   5BCD                    3094 00111$:
                           3095 ;src/main.c:1029: if (pSpr->dir == D_down) {
   5BCD 1A            [ 7] 3096 	ld	a, (de)
                           3097 ;src/main.c:1045: if (pSpr->y < pSpr->yMax && !OnPlatform(pSpr)) pSpr->y++;
   5BCE DD 6E FB      [19] 3098 	ld	l,-5 (ix)
   5BD1 DD 66 FC      [19] 3099 	ld	h,-4 (ix)
   5BD4 4E            [ 7] 3100 	ld	c, (hl)
                           3101 ;src/main.c:1029: if (pSpr->dir == D_down) {
   5BD5 3D            [ 4] 3102 	dec	a
   5BD6 20 1C         [12] 3103 	jr	NZ,00119$
                           3104 ;src/main.c:1030: if (pSpr->y < pSpr->yMax) pSpr->y += 2;
   5BD8 DD 6E F9      [19] 3105 	ld	l,-7 (ix)
   5BDB DD 66 FA      [19] 3106 	ld	h,-6 (ix)
   5BDE 46            [ 7] 3107 	ld	b, (hl)
   5BDF 79            [ 4] 3108 	ld	a, c
   5BE0 90            [ 4] 3109 	sub	a, b
   5BE1 30 0C         [12] 3110 	jr	NC,00113$
   5BE3 0C            [ 4] 3111 	inc	c
   5BE4 0C            [ 4] 3112 	inc	c
   5BE5 DD 6E FB      [19] 3113 	ld	l,-5 (ix)
   5BE8 DD 66 FC      [19] 3114 	ld	h,-4 (ix)
   5BEB 71            [ 7] 3115 	ld	(hl), c
   5BEC C3 17 5D      [10] 3116 	jp	00162$
   5BEF                    3117 00113$:
                           3118 ;src/main.c:1031: else pSpr->dir = D_up;
   5BEF AF            [ 4] 3119 	xor	a, a
   5BF0 12            [ 7] 3120 	ld	(de), a
   5BF1 C3 17 5D      [10] 3121 	jp	00162$
   5BF4                    3122 00119$:
                           3123 ;src/main.c:1034: if (pSpr->y > pSpr->yMin) pSpr->y -= 2;
   5BF4 FD 7E 00      [19] 3124 	ld	a, 0 (iy)
   5BF7 91            [ 4] 3125 	sub	a, c
   5BF8 30 0C         [12] 3126 	jr	NC,00116$
   5BFA 0D            [ 4] 3127 	dec	c
   5BFB 0D            [ 4] 3128 	dec	c
   5BFC DD 6E FB      [19] 3129 	ld	l,-5 (ix)
   5BFF DD 66 FC      [19] 3130 	ld	h,-4 (ix)
   5C02 71            [ 7] 3131 	ld	(hl), c
   5C03 C3 17 5D      [10] 3132 	jp	00162$
   5C06                    3133 00116$:
                           3134 ;src/main.c:1035: else pSpr->dir = D_down; 
   5C06 3E 01         [ 7] 3135 	ld	a, #0x01
   5C08 12            [ 7] 3136 	ld	(de), a
                           3137 ;src/main.c:1037: break;
   5C09 C3 17 5D      [10] 3138 	jp	00162$
                           3139 ;src/main.c:1040: case M_diagonal:
   5C0C                    3140 00121$:
                           3141 ;src/main.c:1042: if (pSpr->dir == D_right_down || pSpr->dir == D_right) {
   5C0C 1A            [ 7] 3142 	ld	a, (de)
   5C0D FE 07         [ 7] 3143 	cp	a, #0x07
   5C0F 28 04         [12] 3144 	jr	Z,00157$
   5C11 FE 03         [ 7] 3145 	cp	a, #0x03
   5C13 20 43         [12] 3146 	jr	NZ,00158$
   5C15                    3147 00157$:
                           3148 ;src/main.c:1043: if (pSpr->x < pSpr->xMax) {
   5C15 0A            [ 7] 3149 	ld	a, (bc)
   5C16 E1            [10] 3150 	pop	hl
   5C17 E5            [11] 3151 	push	hl
   5C18 6E            [ 7] 3152 	ld	l, (hl)
   5C19 BD            [ 4] 3153 	cp	a, l
   5C1A 30 36         [12] 3154 	jr	NC,00127$
                           3155 ;src/main.c:1044: pSpr->x++;					
   5C1C 3C            [ 4] 3156 	inc	a
   5C1D 02            [ 7] 3157 	ld	(bc), a
                           3158 ;src/main.c:1045: if (pSpr->y < pSpr->yMax && !OnPlatform(pSpr)) pSpr->y++;
   5C1E DD 6E FB      [19] 3159 	ld	l,-5 (ix)
   5C21 DD 66 FC      [19] 3160 	ld	h,-4 (ix)
   5C24 7E            [ 7] 3161 	ld	a, (hl)
   5C25 DD 6E F9      [19] 3162 	ld	l,-7 (ix)
   5C28 DD 66 FA      [19] 3163 	ld	h,-6 (ix)
   5C2B 6E            [ 7] 3164 	ld	l, (hl)
   5C2C 95            [ 4] 3165 	sub	a, l
   5C2D 30 1D         [12] 3166 	jr	NC,00123$
   5C2F D5            [11] 3167 	push	de
   5C30 69            [ 4] 3168 	ld	l, c
   5C31 60            [ 4] 3169 	ld	h, b
   5C32 CD DB 4F      [17] 3170 	call	_OnPlatform
   5C35 D1            [10] 3171 	pop	de
   5C36 7D            [ 4] 3172 	ld	a, l
   5C37 B7            [ 4] 3173 	or	a, a
   5C38 20 12         [12] 3174 	jr	NZ,00123$
   5C3A DD 6E FB      [19] 3175 	ld	l,-5 (ix)
   5C3D DD 66 FC      [19] 3176 	ld	h,-4 (ix)
   5C40 4E            [ 7] 3177 	ld	c, (hl)
   5C41 0C            [ 4] 3178 	inc	c
   5C42 DD 6E FB      [19] 3179 	ld	l,-5 (ix)
   5C45 DD 66 FC      [19] 3180 	ld	h,-4 (ix)
   5C48 71            [ 7] 3181 	ld	(hl), c
   5C49 C3 17 5D      [10] 3182 	jp	00162$
   5C4C                    3183 00123$:
                           3184 ;src/main.c:1046: else pSpr->dir = D_right_up;
   5C4C 3E 06         [ 7] 3185 	ld	a, #0x06
   5C4E 12            [ 7] 3186 	ld	(de), a
   5C4F C3 17 5D      [10] 3187 	jp	00162$
   5C52                    3188 00127$:
                           3189 ;src/main.c:1048: else pSpr->dir = D_left_down;
   5C52 3E 05         [ 7] 3190 	ld	a, #0x05
   5C54 12            [ 7] 3191 	ld	(de), a
   5C55 C3 17 5D      [10] 3192 	jp	00162$
   5C58                    3193 00158$:
                           3194 ;src/main.c:1051: else if (pSpr->dir == D_right_up) {
   5C58 FE 06         [ 7] 3195 	cp	a, #0x06
   5C5A 20 2D         [12] 3196 	jr	NZ,00155$
                           3197 ;src/main.c:1052: if (pSpr->x < pSpr->xMax) {
   5C5C 0A            [ 7] 3198 	ld	a, (bc)
   5C5D E1            [10] 3199 	pop	hl
   5C5E E5            [11] 3200 	push	hl
   5C5F 6E            [ 7] 3201 	ld	l, (hl)
   5C60 BD            [ 4] 3202 	cp	a, l
   5C61 30 20         [12] 3203 	jr	NC,00133$
                           3204 ;src/main.c:1053: pSpr->x++;
   5C63 3C            [ 4] 3205 	inc	a
   5C64 02            [ 7] 3206 	ld	(bc), a
                           3207 ;src/main.c:1054: if (pSpr->y > pSpr->yMin) pSpr->y--;
   5C65 DD 6E FB      [19] 3208 	ld	l,-5 (ix)
   5C68 DD 66 FC      [19] 3209 	ld	h,-4 (ix)
   5C6B 4E            [ 7] 3210 	ld	c, (hl)
   5C6C FD 7E 00      [19] 3211 	ld	a, 0 (iy)
   5C6F 91            [ 4] 3212 	sub	a, c
   5C70 30 0B         [12] 3213 	jr	NC,00130$
   5C72 0D            [ 4] 3214 	dec	c
   5C73 DD 6E FB      [19] 3215 	ld	l,-5 (ix)
   5C76 DD 66 FC      [19] 3216 	ld	h,-4 (ix)
   5C79 71            [ 7] 3217 	ld	(hl), c
   5C7A C3 17 5D      [10] 3218 	jp	00162$
   5C7D                    3219 00130$:
                           3220 ;src/main.c:1055: else pSpr->dir = D_right_down;
   5C7D 3E 07         [ 7] 3221 	ld	a, #0x07
   5C7F 12            [ 7] 3222 	ld	(de), a
   5C80 C3 17 5D      [10] 3223 	jp	00162$
   5C83                    3224 00133$:
                           3225 ;src/main.c:1057: else pSpr->dir = D_left_up;
   5C83 3E 04         [ 7] 3226 	ld	a, #0x04
   5C85 12            [ 7] 3227 	ld	(de), a
   5C86 C3 17 5D      [10] 3228 	jp	00162$
   5C89                    3229 00155$:
                           3230 ;src/main.c:1060: else if (pSpr->dir == D_left_up || pSpr->dir == D_left)	{
   5C89 FE 04         [ 7] 3231 	cp	a, #0x04
   5C8B 28 04         [12] 3232 	jr	Z,00150$
   5C8D FE 02         [ 7] 3233 	cp	a, #0x02
   5C8F 20 37         [12] 3234 	jr	NZ,00151$
   5C91                    3235 00150$:
                           3236 ;src/main.c:1061: if (pSpr->x > pSpr->xMin) {
   5C91 0A            [ 7] 3237 	ld	a, (bc)
   5C92 DD 77 F7      [19] 3238 	ld	-9 (ix), a
   5C95 DD 6E FE      [19] 3239 	ld	l,-2 (ix)
   5C98 DD 66 FF      [19] 3240 	ld	h,-1 (ix)
   5C9B 7E            [ 7] 3241 	ld	a, (hl)
   5C9C DD 96 F7      [19] 3242 	sub	a, -9 (ix)
   5C9F 30 22         [12] 3243 	jr	NC,00139$
                           3244 ;src/main.c:1062: pSpr->x--;
   5CA1 DD 7E F7      [19] 3245 	ld	a, -9 (ix)
   5CA4 C6 FF         [ 7] 3246 	add	a, #0xff
   5CA6 02            [ 7] 3247 	ld	(bc), a
                           3248 ;src/main.c:1063: if (pSpr->y > pSpr->yMin) pSpr->y--;
   5CA7 DD 6E FB      [19] 3249 	ld	l,-5 (ix)
   5CAA DD 66 FC      [19] 3250 	ld	h,-4 (ix)
   5CAD 4E            [ 7] 3251 	ld	c, (hl)
   5CAE FD 7E 00      [19] 3252 	ld	a, 0 (iy)
   5CB1 91            [ 4] 3253 	sub	a, c
   5CB2 30 0A         [12] 3254 	jr	NC,00136$
   5CB4 0D            [ 4] 3255 	dec	c
   5CB5 DD 6E FB      [19] 3256 	ld	l,-5 (ix)
   5CB8 DD 66 FC      [19] 3257 	ld	h,-4 (ix)
   5CBB 71            [ 7] 3258 	ld	(hl), c
   5CBC 18 59         [12] 3259 	jr	00162$
   5CBE                    3260 00136$:
                           3261 ;src/main.c:1064: else pSpr->dir = D_left_down;
   5CBE 3E 05         [ 7] 3262 	ld	a, #0x05
   5CC0 12            [ 7] 3263 	ld	(de), a
   5CC1 18 54         [12] 3264 	jr	00162$
   5CC3                    3265 00139$:
                           3266 ;src/main.c:1066: else pSpr->dir = D_right_up; 
   5CC3 3E 06         [ 7] 3267 	ld	a, #0x06
   5CC5 12            [ 7] 3268 	ld	(de), a
   5CC6 18 4F         [12] 3269 	jr	00162$
   5CC8                    3270 00151$:
                           3271 ;src/main.c:1069: else if (pSpr->dir == D_left_down) {
   5CC8 D6 05         [ 7] 3272 	sub	a, #0x05
   5CCA 20 4B         [12] 3273 	jr	NZ,00162$
                           3274 ;src/main.c:1070: if (pSpr->x > pSpr->xMin) {
   5CCC 0A            [ 7] 3275 	ld	a, (bc)
   5CCD DD 77 F7      [19] 3276 	ld	-9 (ix), a
   5CD0 DD 6E FE      [19] 3277 	ld	l,-2 (ix)
   5CD3 DD 66 FF      [19] 3278 	ld	h,-1 (ix)
   5CD6 7E            [ 7] 3279 	ld	a, (hl)
   5CD7 DD 96 F7      [19] 3280 	sub	a, -9 (ix)
   5CDA 30 38         [12] 3281 	jr	NC,00146$
                           3282 ;src/main.c:1071: pSpr->x--;
   5CDC DD 7E F7      [19] 3283 	ld	a, -9 (ix)
   5CDF C6 FF         [ 7] 3284 	add	a, #0xff
   5CE1 02            [ 7] 3285 	ld	(bc), a
                           3286 ;src/main.c:1072: if (pSpr->y < pSpr->yMax && !OnPlatform(pSpr)) pSpr->y++;
   5CE2 DD 6E FB      [19] 3287 	ld	l,-5 (ix)
   5CE5 DD 66 FC      [19] 3288 	ld	h,-4 (ix)
   5CE8 7E            [ 7] 3289 	ld	a, (hl)
   5CE9 DD 6E F9      [19] 3290 	ld	l,-7 (ix)
   5CEC DD 66 FA      [19] 3291 	ld	h,-6 (ix)
   5CEF 6E            [ 7] 3292 	ld	l, (hl)
   5CF0 95            [ 4] 3293 	sub	a, l
   5CF1 30 1C         [12] 3294 	jr	NC,00142$
   5CF3 D5            [11] 3295 	push	de
   5CF4 69            [ 4] 3296 	ld	l, c
   5CF5 60            [ 4] 3297 	ld	h, b
   5CF6 CD DB 4F      [17] 3298 	call	_OnPlatform
   5CF9 D1            [10] 3299 	pop	de
   5CFA 7D            [ 4] 3300 	ld	a, l
   5CFB B7            [ 4] 3301 	or	a, a
   5CFC 20 11         [12] 3302 	jr	NZ,00142$
   5CFE DD 6E FB      [19] 3303 	ld	l,-5 (ix)
   5D01 DD 66 FC      [19] 3304 	ld	h,-4 (ix)
   5D04 4E            [ 7] 3305 	ld	c, (hl)
   5D05 0C            [ 4] 3306 	inc	c
   5D06 DD 6E FB      [19] 3307 	ld	l,-5 (ix)
   5D09 DD 66 FC      [19] 3308 	ld	h,-4 (ix)
   5D0C 71            [ 7] 3309 	ld	(hl), c
   5D0D 18 08         [12] 3310 	jr	00162$
   5D0F                    3311 00142$:
                           3312 ;src/main.c:1073: else pSpr->dir = D_left_up;
   5D0F 3E 04         [ 7] 3313 	ld	a, #0x04
   5D11 12            [ 7] 3314 	ld	(de), a
   5D12 18 03         [12] 3315 	jr	00162$
   5D14                    3316 00146$:
                           3317 ;src/main.c:1075: else pSpr->dir = D_right_down;
   5D14 3E 07         [ 7] 3318 	ld	a, #0x07
   5D16 12            [ 7] 3319 	ld	(de), a
                           3320 ;src/main.c:1078: }
   5D17                    3321 00162$:
   5D17 DD F9         [10] 3322 	ld	sp, ix
   5D19 DD E1         [14] 3323 	pop	ix
   5D1B C9            [10] 3324 	ret
                           3325 ;src/main.c:1083: void SetEnemyParams(u8 i, u8 ident, u8 mov, u8 lives, u8 dir, u8 x, u8 y, u8 xMin, u8 yMin, u8 xMax, u8 yMax) {
                           3326 ;	---------------------------------
                           3327 ; Function SetEnemyParams
                           3328 ; ---------------------------------
   5D1C                    3329 _SetEnemyParams::
   5D1C DD E5         [15] 3330 	push	ix
   5D1E DD 21 00 00   [14] 3331 	ld	ix,#0
   5D22 DD 39         [15] 3332 	add	ix,sp
                           3333 ;src/main.c:1084: spr[i].status = S_walking;
   5D24 01 C2 4B      [10] 3334 	ld	bc, #_spr+0
   5D27 DD 5E 04      [19] 3335 	ld	e,4 (ix)
   5D2A 16 00         [ 7] 3336 	ld	d,#0x00
   5D2C 6B            [ 4] 3337 	ld	l, e
   5D2D 62            [ 4] 3338 	ld	h, d
   5D2E 29            [11] 3339 	add	hl, hl
   5D2F 29            [11] 3340 	add	hl, hl
   5D30 29            [11] 3341 	add	hl, hl
   5D31 19            [11] 3342 	add	hl, de
   5D32 29            [11] 3343 	add	hl, hl
   5D33 19            [11] 3344 	add	hl, de
   5D34 09            [11] 3345 	add	hl,bc
   5D35 4D            [ 4] 3346 	ld	c, l
   5D36 44            [ 4] 3347 	ld	b, h
   5D37 21 04 00      [10] 3348 	ld	hl, #0x0004
   5D3A 09            [11] 3349 	add	hl, bc
   5D3B 36 01         [10] 3350 	ld	(hl), #0x01
                           3351 ;src/main.c:1085: spr[i].ident = ident; 
   5D3D 21 12 00      [10] 3352 	ld	hl, #0x0012
   5D40 09            [11] 3353 	add	hl, bc
   5D41 DD 7E 05      [19] 3354 	ld	a, 5 (ix)
   5D44 77            [ 7] 3355 	ld	(hl), a
                           3356 ;src/main.c:1086: spr[i].movType = mov;
   5D45 21 11 00      [10] 3357 	ld	hl, #0x0011
   5D48 09            [11] 3358 	add	hl, bc
   5D49 DD 7E 06      [19] 3359 	ld	a, 6 (ix)
   5D4C 77            [ 7] 3360 	ld	(hl), a
                           3361 ;src/main.c:1087: spr[i].lives = lives; 
   5D4D 21 09 00      [10] 3362 	ld	hl, #0x0009
   5D50 09            [11] 3363 	add	hl, bc
   5D51 DD 7E 07      [19] 3364 	ld	a, 7 (ix)
   5D54 77            [ 7] 3365 	ld	(hl), a
                           3366 ;src/main.c:1088: spr[i].dir = dir; 
   5D55 21 08 00      [10] 3367 	ld	hl, #0x0008
   5D58 09            [11] 3368 	add	hl, bc
   5D59 DD 7E 08      [19] 3369 	ld	a, 8 (ix)
   5D5C 77            [ 7] 3370 	ld	(hl), a
                           3371 ;src/main.c:1089: spr[i].x = spr[i].px = x;
   5D5D 59            [ 4] 3372 	ld	e, c
   5D5E 50            [ 4] 3373 	ld	d, b
   5D5F 13            [ 6] 3374 	inc	de
   5D60 13            [ 6] 3375 	inc	de
   5D61 DD 7E 09      [19] 3376 	ld	a, 9 (ix)
   5D64 12            [ 7] 3377 	ld	(de), a
   5D65 DD 7E 09      [19] 3378 	ld	a, 9 (ix)
   5D68 02            [ 7] 3379 	ld	(bc), a
                           3380 ;src/main.c:1090: spr[i].y = spr[i].py = y;
   5D69 59            [ 4] 3381 	ld	e, c
   5D6A 50            [ 4] 3382 	ld	d, b
   5D6B 13            [ 6] 3383 	inc	de
   5D6C 69            [ 4] 3384 	ld	l, c
   5D6D 60            [ 4] 3385 	ld	h, b
   5D6E 23            [ 6] 3386 	inc	hl
   5D6F 23            [ 6] 3387 	inc	hl
   5D70 23            [ 6] 3388 	inc	hl
   5D71 DD 7E 0A      [19] 3389 	ld	a, 10 (ix)
   5D74 77            [ 7] 3390 	ld	(hl), a
   5D75 DD 7E 0A      [19] 3391 	ld	a, 10 (ix)
   5D78 12            [ 7] 3392 	ld	(de), a
                           3393 ;src/main.c:1091: spr[i].xMin = xMin;
   5D79 21 0D 00      [10] 3394 	ld	hl, #0x000d
   5D7C 09            [11] 3395 	add	hl, bc
   5D7D DD 7E 0B      [19] 3396 	ld	a, 11 (ix)
   5D80 77            [ 7] 3397 	ld	(hl), a
                           3398 ;src/main.c:1092: spr[i].yMin = yMin;
   5D81 21 0F 00      [10] 3399 	ld	hl, #0x000f
   5D84 09            [11] 3400 	add	hl, bc
   5D85 DD 7E 0C      [19] 3401 	ld	a, 12 (ix)
   5D88 77            [ 7] 3402 	ld	(hl), a
                           3403 ;src/main.c:1093: spr[i].xMax = xMax;
   5D89 21 0E 00      [10] 3404 	ld	hl, #0x000e
   5D8C 09            [11] 3405 	add	hl, bc
   5D8D DD 7E 0D      [19] 3406 	ld	a, 13 (ix)
   5D90 77            [ 7] 3407 	ld	(hl), a
                           3408 ;src/main.c:1094: spr[i].yMax = yMax; 
   5D91 21 10 00      [10] 3409 	ld	hl, #0x0010
   5D94 09            [11] 3410 	add	hl, bc
   5D95 DD 7E 0E      [19] 3411 	ld	a, 14 (ix)
   5D98 77            [ 7] 3412 	ld	(hl), a
                           3413 ;src/main.c:1095: spr[i].touched = 0;
   5D99 21 0A 00      [10] 3414 	ld	hl, #0x000a
   5D9C 09            [11] 3415 	add	hl, bc
   5D9D 36 00         [10] 3416 	ld	(hl), #0x00
   5D9F DD E1         [14] 3417 	pop	ix
   5DA1 C9            [10] 3418 	ret
                           3419 ;src/main.c:1105: void SetEnemies() {
                           3420 ;	---------------------------------
                           3421 ; Function SetEnemies
                           3422 ; ---------------------------------
   5DA2                    3423 _SetEnemies::
                           3424 ;src/main.c:1106: switch(mapNumber) {
   5DA2 FD 21 32 4C   [14] 3425 	ld	iy, #_mapNumber
   5DA6 FD 7E 00      [19] 3426 	ld	a, 0 (iy)
   5DA9 B7            [ 4] 3427 	or	a, a
   5DAA 28 0F         [12] 3428 	jr	Z,00101$
   5DAC FD 7E 00      [19] 3429 	ld	a, 0 (iy)
   5DAF 3D            [ 4] 3430 	dec	a
   5DB0 28 6C         [12] 3431 	jr	Z,00102$
   5DB2 FD 7E 00      [19] 3432 	ld	a, 0 (iy)
   5DB5 D6 02         [ 7] 3433 	sub	a, #0x02
   5DB7 CA 84 5E      [10] 3434 	jp	Z,00103$
   5DBA C9            [10] 3435 	ret
                           3436 ;src/main.c:1107: case 0: { // upper left deck upper floor #3
   5DBB                    3437 00101$:
                           3438 ;src/main.c:1109: SetEnemyParams(1, ARACNOVIRUS, 	M_linear_Y, 	2,  D_right, 48,  64,   48,   64,   48,  160);
   5DBB 21 30 A0      [10] 3439 	ld	hl, #0xa030
   5DBE E5            [11] 3440 	push	hl
   5DBF 26 40         [ 7] 3441 	ld	h, #0x40
   5DC1 E5            [11] 3442 	push	hl
   5DC2 2E 30         [ 7] 3443 	ld	l, #0x30
   5DC4 E5            [11] 3444 	push	hl
   5DC5 21 02 03      [10] 3445 	ld	hl, #0x0302
   5DC8 E5            [11] 3446 	push	hl
   5DC9 26 01         [ 7] 3447 	ld	h, #0x01
   5DCB E5            [11] 3448 	push	hl
   5DCC 3E 01         [ 7] 3449 	ld	a, #0x01
   5DCE F5            [11] 3450 	push	af
   5DCF 33            [ 6] 3451 	inc	sp
   5DD0 CD 1C 5D      [17] 3452 	call	_SetEnemyParams
   5DD3 21 0B 00      [10] 3453 	ld	hl, #11
   5DD6 39            [11] 3454 	add	hl, sp
   5DD7 F9            [ 6] 3455 	ld	sp, hl
                           3456 ;src/main.c:1110: SetEnemyParams(2, INFECTED, 	M_linear_X, 	3,  D_right, 16, 160,    8,  160,   64,  160);
   5DD8 21 40 A0      [10] 3457 	ld	hl, #0xa040
   5DDB E5            [11] 3458 	push	hl
   5DDC 2E 08         [ 7] 3459 	ld	l, #0x08
   5DDE E5            [11] 3460 	push	hl
   5DDF 2E 10         [ 7] 3461 	ld	l, #0x10
   5DE1 E5            [11] 3462 	push	hl
   5DE2 21 03 03      [10] 3463 	ld	hl, #0x0303
   5DE5 E5            [11] 3464 	push	hl
   5DE6 26 00         [ 7] 3465 	ld	h, #0x00
   5DE8 E5            [11] 3466 	push	hl
   5DE9 3E 02         [ 7] 3467 	ld	a, #0x02
   5DEB F5            [11] 3468 	push	af
   5DEC 33            [ 6] 3469 	inc	sp
   5DED CD 1C 5D      [17] 3470 	call	_SetEnemyParams
   5DF0 21 0B 00      [10] 3471 	ld	hl, #11
   5DF3 39            [11] 3472 	add	hl, sp
   5DF4 F9            [ 6] 3473 	ld	sp, hl
                           3474 ;src/main.c:1111: SetEnemyParams(3, ARACNOVIRUS,	M_linear_X,		0,  D_right,  0,   0,    0,    0,    0,    0);
   5DF5 21 00 00      [10] 3475 	ld	hl, #0x0000
   5DF8 E5            [11] 3476 	push	hl
   5DF9 2E 00         [ 7] 3477 	ld	l, #0x00
   5DFB E5            [11] 3478 	push	hl
   5DFC 2E 00         [ 7] 3479 	ld	l, #0x00
   5DFE E5            [11] 3480 	push	hl
   5DFF 26 03         [ 7] 3481 	ld	h, #0x03
   5E01 E5            [11] 3482 	push	hl
   5E02 21 02 00      [10] 3483 	ld	hl, #0x0002
   5E05 E5            [11] 3484 	push	hl
   5E06 3E 03         [ 7] 3485 	ld	a, #0x03
   5E08 F5            [11] 3486 	push	af
   5E09 33            [ 6] 3487 	inc	sp
   5E0A CD 1C 5D      [17] 3488 	call	_SetEnemyParams
   5E0D 21 0B 00      [10] 3489 	ld	hl, #11
   5E10 39            [11] 3490 	add	hl, sp
   5E11 F9            [ 6] 3491 	ld	sp, hl
                           3492 ;src/main.c:1113: cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk0_end);
   5E12 21 18 33      [10] 3493 	ld	hl, #(_mappk0 + 0x00e5)
   5E15 E5            [11] 3494 	push	hl
   5E16 21 20 16      [10] 3495 	ld	hl, #0x1620
   5E19 E5            [11] 3496 	push	hl
   5E1A CD 35 49      [17] 3497 	call	_cpct_zx7b_decrunch_s
                           3498 ;src/main.c:1114: break;
   5E1D C9            [10] 3499 	ret
                           3500 ;src/main.c:1116: case 1: { // upper left deck upper floor #2
   5E1E                    3501 00102$:
                           3502 ;src/main.c:1118: SetEnemyParams(1, PELUSOID,		M_diagonal, 	3,	D_right,  8,  52,    8,   52,   64,  160);
   5E1E 21 40 A0      [10] 3503 	ld	hl, #0xa040
   5E21 E5            [11] 3504 	push	hl
   5E22 21 08 34      [10] 3505 	ld	hl, #0x3408
   5E25 E5            [11] 3506 	push	hl
   5E26 2E 08         [ 7] 3507 	ld	l, #0x08
   5E28 E5            [11] 3508 	push	hl
   5E29 21 03 03      [10] 3509 	ld	hl, #0x0303
   5E2C E5            [11] 3510 	push	hl
   5E2D 21 01 02      [10] 3511 	ld	hl, #0x0201
   5E30 E5            [11] 3512 	push	hl
   5E31 3E 01         [ 7] 3513 	ld	a, #0x01
   5E33 F5            [11] 3514 	push	af
   5E34 33            [ 6] 3515 	inc	sp
   5E35 CD 1C 5D      [17] 3516 	call	_SetEnemyParams
   5E38 21 0B 00      [10] 3517 	ld	hl, #11
   5E3B 39            [11] 3518 	add	hl, sp
   5E3C F9            [ 6] 3519 	ld	sp, hl
                           3520 ;src/main.c:1119: SetEnemyParams(2, PELUSOID, 	M_linear_Y, 	3,	D_right, 32,  52,   32,   52,   32,  160);		
   5E3D 21 20 A0      [10] 3521 	ld	hl, #0xa020
   5E40 E5            [11] 3522 	push	hl
   5E41 26 34         [ 7] 3523 	ld	h, #0x34
   5E43 E5            [11] 3524 	push	hl
   5E44 2E 20         [ 7] 3525 	ld	l, #0x20
   5E46 E5            [11] 3526 	push	hl
   5E47 21 03 03      [10] 3527 	ld	hl, #0x0303
   5E4A E5            [11] 3528 	push	hl
   5E4B 21 01 01      [10] 3529 	ld	hl, #0x0101
   5E4E E5            [11] 3530 	push	hl
   5E4F 3E 02         [ 7] 3531 	ld	a, #0x02
   5E51 F5            [11] 3532 	push	af
   5E52 33            [ 6] 3533 	inc	sp
   5E53 CD 1C 5D      [17] 3534 	call	_SetEnemyParams
   5E56 21 0B 00      [10] 3535 	ld	hl, #11
   5E59 39            [11] 3536 	add	hl, sp
   5E5A F9            [ 6] 3537 	ld	sp, hl
                           3538 ;src/main.c:1120: SetEnemyParams(3, PELUSOID, 	M_linear_X,		0,	D_right,  0,   0,    0,    0,    0,    0);
   5E5B 21 00 00      [10] 3539 	ld	hl, #0x0000
   5E5E E5            [11] 3540 	push	hl
   5E5F 2E 00         [ 7] 3541 	ld	l, #0x00
   5E61 E5            [11] 3542 	push	hl
   5E62 2E 00         [ 7] 3543 	ld	l, #0x00
   5E64 E5            [11] 3544 	push	hl
   5E65 26 03         [ 7] 3545 	ld	h, #0x03
   5E67 E5            [11] 3546 	push	hl
   5E68 21 01 00      [10] 3547 	ld	hl, #0x0001
   5E6B E5            [11] 3548 	push	hl
   5E6C 3E 03         [ 7] 3549 	ld	a, #0x03
   5E6E F5            [11] 3550 	push	af
   5E6F 33            [ 6] 3551 	inc	sp
   5E70 CD 1C 5D      [17] 3552 	call	_SetEnemyParams
   5E73 21 0B 00      [10] 3553 	ld	hl, #11
   5E76 39            [11] 3554 	add	hl, sp
   5E77 F9            [ 6] 3555 	ld	sp, hl
                           3556 ;src/main.c:1122: cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk1_end);
   5E78 21 32 32      [10] 3557 	ld	hl, #(_mappk1 + 0x00d3)
   5E7B E5            [11] 3558 	push	hl
   5E7C 21 20 16      [10] 3559 	ld	hl, #0x1620
   5E7F E5            [11] 3560 	push	hl
   5E80 CD 35 49      [17] 3561 	call	_cpct_zx7b_decrunch_s
                           3562 ;src/main.c:1123: break;		
   5E83 C9            [10] 3563 	ret
                           3564 ;src/main.c:1125: case 2: { // upper left deck upper floor #1
   5E84                    3565 00103$:
                           3566 ;src/main.c:1127: SetEnemyParams(1, INFECTED,		M_linear_X,		2,	D_left, 32,  96,    8,   96,   64,   96);
   5E84 21 40 60      [10] 3567 	ld	hl, #0x6040
   5E87 E5            [11] 3568 	push	hl
   5E88 2E 08         [ 7] 3569 	ld	l, #0x08
   5E8A E5            [11] 3570 	push	hl
   5E8B 2E 20         [ 7] 3571 	ld	l, #0x20
   5E8D E5            [11] 3572 	push	hl
   5E8E 21 02 02      [10] 3573 	ld	hl, #0x0202
   5E91 E5            [11] 3574 	push	hl
   5E92 21 03 00      [10] 3575 	ld	hl, #0x0003
   5E95 E5            [11] 3576 	push	hl
   5E96 3E 01         [ 7] 3577 	ld	a, #0x01
   5E98 F5            [11] 3578 	push	af
   5E99 33            [ 6] 3579 	inc	sp
   5E9A CD 1C 5D      [17] 3580 	call	_SetEnemyParams
   5E9D 21 0B 00      [10] 3581 	ld	hl, #11
   5EA0 39            [11] 3582 	add	hl, sp
   5EA1 F9            [ 6] 3583 	ld	sp, hl
                           3584 ;src/main.c:1128: SetEnemyParams(2, INFECTED, 	M_linear_X, 	2,	D_left, 64, 128,   16,  128,   64,  128);
   5EA2 21 40 80      [10] 3585 	ld	hl, #0x8040
   5EA5 E5            [11] 3586 	push	hl
   5EA6 2E 10         [ 7] 3587 	ld	l, #0x10
   5EA8 E5            [11] 3588 	push	hl
   5EA9 2E 40         [ 7] 3589 	ld	l, #0x40
   5EAB E5            [11] 3590 	push	hl
   5EAC 21 02 02      [10] 3591 	ld	hl, #0x0202
   5EAF E5            [11] 3592 	push	hl
   5EB0 21 03 00      [10] 3593 	ld	hl, #0x0003
   5EB3 E5            [11] 3594 	push	hl
   5EB4 3E 02         [ 7] 3595 	ld	a, #0x02
   5EB6 F5            [11] 3596 	push	af
   5EB7 33            [ 6] 3597 	inc	sp
   5EB8 CD 1C 5D      [17] 3598 	call	_SetEnemyParams
   5EBB 21 0B 00      [10] 3599 	ld	hl, #11
   5EBE 39            [11] 3600 	add	hl, sp
   5EBF F9            [ 6] 3601 	ld	sp, hl
                           3602 ;src/main.c:1129: SetEnemyParams(3, INFECTED, 	M_linear_X,		2,	D_right, 24, 160,   8,  160,   48,  160);
   5EC0 21 30 A0      [10] 3603 	ld	hl, #0xa030
   5EC3 E5            [11] 3604 	push	hl
   5EC4 2E 08         [ 7] 3605 	ld	l, #0x08
   5EC6 E5            [11] 3606 	push	hl
   5EC7 2E 18         [ 7] 3607 	ld	l, #0x18
   5EC9 E5            [11] 3608 	push	hl
   5ECA 21 02 03      [10] 3609 	ld	hl, #0x0302
   5ECD E5            [11] 3610 	push	hl
   5ECE 21 03 00      [10] 3611 	ld	hl, #0x0003
   5ED1 E5            [11] 3612 	push	hl
   5ED2 3E 03         [ 7] 3613 	ld	a, #0x03
   5ED4 F5            [11] 3614 	push	af
   5ED5 33            [ 6] 3615 	inc	sp
   5ED6 CD 1C 5D      [17] 3616 	call	_SetEnemyParams
   5ED9 21 0B 00      [10] 3617 	ld	hl, #11
   5EDC 39            [11] 3618 	add	hl, sp
   5EDD F9            [ 6] 3619 	ld	sp, hl
                           3620 ;src/main.c:1131: cpct_zx7b_decrunch_s(UNPACKED_MAP_END, mappk2_end);
   5EDE 21 5E 31      [10] 3621 	ld	hl, #(_mappk2 + 0x00e1)
   5EE1 E5            [11] 3622 	push	hl
   5EE2 21 20 16      [10] 3623 	ld	hl, #0x1620
   5EE5 E5            [11] 3624 	push	hl
   5EE6 CD 35 49      [17] 3625 	call	_cpct_zx7b_decrunch_s
                           3626 ;src/main.c:1133: }
   5EE9 C9            [10] 3627 	ret
                           3628 ;src/main.c:1138: void ExplosionSecuence(TSpr *pSpr) __z88dk_fastcall {
                           3629 ;	---------------------------------
                           3630 ; Function ExplosionSecuence
                           3631 ; ---------------------------------
   5EEA                    3632 _ExplosionSecuence::
   5EEA 4D            [ 4] 3633 	ld	c, l
   5EEB 44            [ 4] 3634 	ld	b, h
                           3635 ;src/main.c:1139: if (pSpr->touched == 10) DeleteSprite(pSpr); 	
   5EEC 21 0A 00      [10] 3636 	ld	hl, #0x000a
   5EEF 09            [11] 3637 	add	hl,bc
   5EF0 EB            [ 4] 3638 	ex	de,hl
   5EF1 1A            [ 7] 3639 	ld	a, (de)
   5EF2 6F            [ 4] 3640 	ld	l,a
   5EF3 D6 0A         [ 7] 3641 	sub	a, #0x0a
   5EF5 20 09         [12] 3642 	jr	NZ,00113$
   5EF7 D5            [11] 3643 	push	de
   5EF8 69            [ 4] 3644 	ld	l, c
   5EF9 60            [ 4] 3645 	ld	h, b
   5EFA CD 90 54      [17] 3646 	call	_DeleteSprite
   5EFD D1            [10] 3647 	pop	de
   5EFE 18 43         [12] 3648 	jr	00114$
   5F00                    3649 00113$:
                           3650 ;src/main.c:1140: else if (pSpr->touched > 8) PrintExplosion(pSpr, 0);
   5F00 3E 08         [ 7] 3651 	ld	a, #0x08
   5F02 95            [ 4] 3652 	sub	a, l
   5F03 30 0D         [12] 3653 	jr	NC,00110$
   5F05 D5            [11] 3654 	push	de
   5F06 AF            [ 4] 3655 	xor	a, a
   5F07 F5            [11] 3656 	push	af
   5F08 33            [ 6] 3657 	inc	sp
   5F09 C5            [11] 3658 	push	bc
   5F0A CD FE 54      [17] 3659 	call	_PrintExplosion
   5F0D F1            [10] 3660 	pop	af
   5F0E 33            [ 6] 3661 	inc	sp
   5F0F D1            [10] 3662 	pop	de
   5F10 18 31         [12] 3663 	jr	00114$
   5F12                    3664 00110$:
                           3665 ;src/main.c:1141: else if (pSpr->touched > 6) PrintExplosion(pSpr, 1);
   5F12 3E 06         [ 7] 3666 	ld	a, #0x06
   5F14 95            [ 4] 3667 	sub	a, l
   5F15 30 0E         [12] 3668 	jr	NC,00107$
   5F17 D5            [11] 3669 	push	de
   5F18 3E 01         [ 7] 3670 	ld	a, #0x01
   5F1A F5            [11] 3671 	push	af
   5F1B 33            [ 6] 3672 	inc	sp
   5F1C C5            [11] 3673 	push	bc
   5F1D CD FE 54      [17] 3674 	call	_PrintExplosion
   5F20 F1            [10] 3675 	pop	af
   5F21 33            [ 6] 3676 	inc	sp
   5F22 D1            [10] 3677 	pop	de
   5F23 18 1E         [12] 3678 	jr	00114$
   5F25                    3679 00107$:
                           3680 ;src/main.c:1142: else if (pSpr->touched > 4) PrintExplosion(pSpr, 0);
   5F25 3E 04         [ 7] 3681 	ld	a, #0x04
   5F27 95            [ 4] 3682 	sub	a, l
   5F28 30 0D         [12] 3683 	jr	NC,00104$
   5F2A D5            [11] 3684 	push	de
   5F2B AF            [ 4] 3685 	xor	a, a
   5F2C F5            [11] 3686 	push	af
   5F2D 33            [ 6] 3687 	inc	sp
   5F2E C5            [11] 3688 	push	bc
   5F2F CD FE 54      [17] 3689 	call	_PrintExplosion
   5F32 F1            [10] 3690 	pop	af
   5F33 33            [ 6] 3691 	inc	sp
   5F34 D1            [10] 3692 	pop	de
   5F35 18 0C         [12] 3693 	jr	00114$
   5F37                    3694 00104$:
                           3695 ;src/main.c:1143: else if (pSpr->touched > 2) DeleteSprite(pSpr); 
   5F37 3E 02         [ 7] 3696 	ld	a, #0x02
   5F39 95            [ 4] 3697 	sub	a, l
   5F3A 30 07         [12] 3698 	jr	NC,00114$
   5F3C D5            [11] 3699 	push	de
   5F3D 69            [ 4] 3700 	ld	l, c
   5F3E 60            [ 4] 3701 	ld	h, b
   5F3F CD 90 54      [17] 3702 	call	_DeleteSprite
   5F42 D1            [10] 3703 	pop	de
   5F43                    3704 00114$:
                           3705 ;src/main.c:1144: pSpr->touched--;
   5F43 1A            [ 7] 3706 	ld	a, (de)
   5F44 C6 FF         [ 7] 3707 	add	a, #0xff
   5F46 12            [ 7] 3708 	ld	(de), a
   5F47 C9            [10] 3709 	ret
                           3710 ;src/main.c:1149: void EnemyLoop(TSpr *pSpr) __z88dk_fastcall {
                           3711 ;	---------------------------------
                           3712 ; Function EnemyLoop
                           3713 ; ---------------------------------
   5F48                    3714 _EnemyLoop::
   5F48 DD E5         [15] 3715 	push	ix
   5F4A DD 21 00 00   [14] 3716 	ld	ix,#0
   5F4E DD 39         [15] 3717 	add	ix,sp
   5F50 F5            [11] 3718 	push	af
   5F51 4D            [ 4] 3719 	ld	c, l
   5F52 44            [ 4] 3720 	ld	b, h
                           3721 ;src/main.c:1150: if (pSpr->lives >= 1) // If the enemy sprite is alive
   5F53 C5            [11] 3722 	push	bc
   5F54 FD E1         [14] 3723 	pop	iy
   5F56 FD 56 09      [19] 3724 	ld	d, 9 (iy)
                           3725 ;src/main.c:1153: if (pSpr->touched == 0) 
   5F59 21 0A 00      [10] 3726 	ld	hl, #0x000a
   5F5C 09            [11] 3727 	add	hl,bc
   5F5D E3            [19] 3728 	ex	(sp), hl
   5F5E E1            [10] 3729 	pop	hl
   5F5F E5            [11] 3730 	push	hl
   5F60 5E            [ 7] 3731 	ld	e, (hl)
                           3732 ;src/main.c:1150: if (pSpr->lives >= 1) // If the enemy sprite is alive
   5F61 7A            [ 4] 3733 	ld	a, d
   5F62 D6 01         [ 7] 3734 	sub	a, #0x01
   5F64 38 4B         [12] 3735 	jr	C,00111$
                           3736 ;src/main.c:1153: if (pSpr->touched == 0) 
   5F66 7B            [ 4] 3737 	ld	a, e
   5F67 B7            [ 4] 3738 	or	a, a
   5F68 20 07         [12] 3739 	jr	NZ,00102$
                           3740 ;src/main.c:1154: MoveEnemy(pSpr);
   5F6A C5            [11] 3741 	push	bc
   5F6B C5            [11] 3742 	push	bc
   5F6C CD 30 5B      [17] 3743 	call	_MoveEnemy
   5F6F F1            [10] 3744 	pop	af
   5F70 C1            [10] 3745 	pop	bc
   5F71                    3746 00102$:
                           3747 ;src/main.c:1156: SelectSpriteFrame(pSpr); 
   5F71 C5            [11] 3748 	push	bc
   5F72 69            [ 4] 3749 	ld	l, c
   5F73 60            [ 4] 3750 	ld	h, b
   5F74 CD 3C 55      [17] 3751 	call	_SelectSpriteFrame
   5F77 C1            [10] 3752 	pop	bc
                           3753 ;src/main.c:1157: EnemyWalkAnim(pSpr);
   5F78 C5            [11] 3754 	push	bc
   5F79 69            [ 4] 3755 	ld	l, c
   5F7A 60            [ 4] 3756 	ld	h, b
   5F7B CD B5 55      [17] 3757 	call	_EnemyWalkAnim
   5F7E C1            [10] 3758 	pop	bc
                           3759 ;src/main.c:1159: DeleteSprite(pSpr);
   5F7F C5            [11] 3760 	push	bc
   5F80 69            [ 4] 3761 	ld	l, c
   5F81 60            [ 4] 3762 	ld	h, b
   5F82 CD 90 54      [17] 3763 	call	_DeleteSprite
   5F85 C1            [10] 3764 	pop	bc
                           3765 ;src/main.c:1160: pSpr->px = pSpr->x; // save the current X coordinate
   5F86 59            [ 4] 3766 	ld	e, c
   5F87 50            [ 4] 3767 	ld	d, b
   5F88 13            [ 6] 3768 	inc	de
   5F89 13            [ 6] 3769 	inc	de
   5F8A 0A            [ 7] 3770 	ld	a, (bc)
   5F8B 12            [ 7] 3771 	ld	(de), a
                           3772 ;src/main.c:1161: pSpr->py = pSpr->y; // save the current Y coordinate
   5F8C 59            [ 4] 3773 	ld	e, c
   5F8D 50            [ 4] 3774 	ld	d, b
   5F8E 13            [ 6] 3775 	inc	de
   5F8F 13            [ 6] 3776 	inc	de
   5F90 13            [ 6] 3777 	inc	de
   5F91 69            [ 4] 3778 	ld	l, c
   5F92 60            [ 4] 3779 	ld	h, b
   5F93 23            [ 6] 3780 	inc	hl
   5F94 7E            [ 7] 3781 	ld	a, (hl)
   5F95 12            [ 7] 3782 	ld	(de), a
                           3783 ;src/main.c:1162: PrintSprite(pSpr);
   5F96 C5            [11] 3784 	push	bc
   5F97 69            [ 4] 3785 	ld	l, c
   5F98 60            [ 4] 3786 	ld	h, b
   5F99 CD 66 54      [17] 3787 	call	_PrintSprite
   5F9C C1            [10] 3788 	pop	bc
                           3789 ;src/main.c:1164: CheckEnemyCollision(pSpr);
   5F9D C5            [11] 3790 	push	bc
   5F9E C5            [11] 3791 	push	bc
   5F9F CD C1 55      [17] 3792 	call	_CheckEnemyCollision
   5FA2 F1            [10] 3793 	pop	af
   5FA3 C1            [10] 3794 	pop	bc
                           3795 ;src/main.c:1166: if (pSpr->touched > 0) 
   5FA4 E1            [10] 3796 	pop	hl
   5FA5 E5            [11] 3797 	push	hl
   5FA6 7E            [ 7] 3798 	ld	a, (hl)
   5FA7 B7            [ 4] 3799 	or	a, a
   5FA8 28 22         [12] 3800 	jr	Z,00113$
                           3801 ;src/main.c:1167: ExplosionSecuence(pSpr);
   5FAA 69            [ 4] 3802 	ld	l, c
   5FAB 60            [ 4] 3803 	ld	h, b
   5FAC CD EA 5E      [17] 3804 	call	_ExplosionSecuence
   5FAF 18 1B         [12] 3805 	jr	00113$
   5FB1                    3806 00111$:
                           3807 ;src/main.c:1169: else if (pSpr->touched > 0) // enemy reached in his last life, will explode
   5FB1 7B            [ 4] 3808 	ld	a, e
   5FB2 B7            [ 4] 3809 	or	a, a
   5FB3 28 07         [12] 3810 	jr	Z,00108$
                           3811 ;src/main.c:1171: ExplosionSecuence(pSpr);
   5FB5 69            [ 4] 3812 	ld	l, c
   5FB6 60            [ 4] 3813 	ld	h, b
   5FB7 CD EA 5E      [17] 3814 	call	_ExplosionSecuence
   5FBA 18 10         [12] 3815 	jr	00113$
   5FBC                    3816 00108$:
                           3817 ;src/main.c:1173: else if (pSpr->status == S_touched) // at this point it has died and exploded
   5FBC 21 04 00      [10] 3818 	ld	hl, #0x0004
   5FBF 09            [11] 3819 	add	hl, bc
   5FC0 7E            [ 7] 3820 	ld	a, (hl)
   5FC1 D6 07         [ 7] 3821 	sub	a, #0x07
   5FC3 20 07         [12] 3822 	jr	NZ,00113$
                           3823 ;src/main.c:1175: pSpr->status = S_walking;		
   5FC5 36 01         [10] 3824 	ld	(hl), #0x01
                           3825 ;src/main.c:1176: DeleteSprite(pSpr); 
   5FC7 69            [ 4] 3826 	ld	l, c
   5FC8 60            [ 4] 3827 	ld	h, b
   5FC9 CD 90 54      [17] 3828 	call	_DeleteSprite
   5FCC                    3829 00113$:
   5FCC DD F9         [10] 3830 	ld	sp, ix
   5FCE DD E1         [14] 3831 	pop	ix
   5FD0 C9            [10] 3832 	ret
                           3833 ;src/main.c:1185: void ExplodeEnemies()
                           3834 ;	---------------------------------
                           3835 ; Function ExplodeEnemies
                           3836 ; ---------------------------------
   5FD1                    3837 _ExplodeEnemies::
                           3838 ;src/main.c:1187: for (ct = 1; ct < 4; ct++)
   5FD1 21 B1 4B      [10] 3839 	ld	hl,#_ct + 0
   5FD4 36 01         [10] 3840 	ld	(hl), #0x01
   5FD6 01 C2 4B      [10] 3841 	ld	bc, #_spr+0
   5FD9                    3842 00104$:
                           3843 ;src/main.c:1188: if (spr[ct].lives > 0)
   5FD9 ED 5B B1 4B   [20] 3844 	ld	de, (_ct)
   5FDD 16 00         [ 7] 3845 	ld	d, #0x00
   5FDF 6B            [ 4] 3846 	ld	l, e
   5FE0 62            [ 4] 3847 	ld	h, d
   5FE1 29            [11] 3848 	add	hl, hl
   5FE2 29            [11] 3849 	add	hl, hl
   5FE3 29            [11] 3850 	add	hl, hl
   5FE4 19            [11] 3851 	add	hl, de
   5FE5 29            [11] 3852 	add	hl, hl
   5FE6 19            [11] 3853 	add	hl, de
   5FE7 09            [11] 3854 	add	hl, bc
   5FE8 11 09 00      [10] 3855 	ld	de, #0x0009
   5FEB 19            [11] 3856 	add	hl, de
   5FEC 7E            [ 7] 3857 	ld	a, (hl)
   5FED B7            [ 4] 3858 	or	a, a
   5FEE CA A9 60      [10] 3859 	jp	Z, 00105$
                           3860 ;src/main.c:1190: cpct_akp_SFXPlay (4, 15, 40, 0, 0, AY_CHANNEL_A); // explosion
   5FF1 C5            [11] 3861 	push	bc
   5FF2 3E 01         [ 7] 3862 	ld	a, #0x01
   5FF4 F5            [11] 3863 	push	af
   5FF5 33            [ 6] 3864 	inc	sp
   5FF6 21 00 00      [10] 3865 	ld	hl, #0x0000
   5FF9 E5            [11] 3866 	push	hl
   5FFA 2E 28         [ 7] 3867 	ld	l, #0x28
   5FFC E5            [11] 3868 	push	hl
   5FFD 21 04 0F      [10] 3869 	ld	hl, #0x0f04
   6000 E5            [11] 3870 	push	hl
   6001 CD 5F 46      [17] 3871 	call	_cpct_akp_SFXPlay
   6004 21 07 00      [10] 3872 	ld	hl, #7
   6007 39            [11] 3873 	add	hl, sp
   6008 F9            [ 6] 3874 	ld	sp, hl
   6009 C1            [10] 3875 	pop	bc
                           3876 ;src/main.c:1191: PrintExplosion(&spr[ct], 0); Pause(20);
   600A ED 5B B1 4B   [20] 3877 	ld	de, (_ct)
   600E 16 00         [ 7] 3878 	ld	d, #0x00
   6010 6B            [ 4] 3879 	ld	l, e
   6011 62            [ 4] 3880 	ld	h, d
   6012 29            [11] 3881 	add	hl, hl
   6013 29            [11] 3882 	add	hl, hl
   6014 29            [11] 3883 	add	hl, hl
   6015 19            [11] 3884 	add	hl, de
   6016 29            [11] 3885 	add	hl, hl
   6017 19            [11] 3886 	add	hl, de
   6018 09            [11] 3887 	add	hl, bc
   6019 C5            [11] 3888 	push	bc
   601A AF            [ 4] 3889 	xor	a, a
   601B F5            [11] 3890 	push	af
   601C 33            [ 6] 3891 	inc	sp
   601D E5            [11] 3892 	push	hl
   601E CD FE 54      [17] 3893 	call	_PrintExplosion
   6021 F1            [10] 3894 	pop	af
   6022 33            [ 6] 3895 	inc	sp
   6023 21 14 00      [10] 3896 	ld	hl, #0x0014
   6026 CD B4 4D      [17] 3897 	call	_Pause
   6029 C1            [10] 3898 	pop	bc
                           3899 ;src/main.c:1192: PrintExplosion(&spr[ct], 1); Pause(20);
   602A ED 5B B1 4B   [20] 3900 	ld	de, (_ct)
   602E 16 00         [ 7] 3901 	ld	d, #0x00
   6030 6B            [ 4] 3902 	ld	l, e
   6031 62            [ 4] 3903 	ld	h, d
   6032 29            [11] 3904 	add	hl, hl
   6033 29            [11] 3905 	add	hl, hl
   6034 29            [11] 3906 	add	hl, hl
   6035 19            [11] 3907 	add	hl, de
   6036 29            [11] 3908 	add	hl, hl
   6037 19            [11] 3909 	add	hl, de
   6038 09            [11] 3910 	add	hl, bc
   6039 C5            [11] 3911 	push	bc
   603A 3E 01         [ 7] 3912 	ld	a, #0x01
   603C F5            [11] 3913 	push	af
   603D 33            [ 6] 3914 	inc	sp
   603E E5            [11] 3915 	push	hl
   603F CD FE 54      [17] 3916 	call	_PrintExplosion
   6042 F1            [10] 3917 	pop	af
   6043 33            [ 6] 3918 	inc	sp
   6044 21 14 00      [10] 3919 	ld	hl, #0x0014
   6047 CD B4 4D      [17] 3920 	call	_Pause
   604A C1            [10] 3921 	pop	bc
                           3922 ;src/main.c:1193: PrintExplosion(&spr[ct], 0); Pause(20);
   604B ED 5B B1 4B   [20] 3923 	ld	de, (_ct)
   604F 16 00         [ 7] 3924 	ld	d, #0x00
   6051 6B            [ 4] 3925 	ld	l, e
   6052 62            [ 4] 3926 	ld	h, d
   6053 29            [11] 3927 	add	hl, hl
   6054 29            [11] 3928 	add	hl, hl
   6055 29            [11] 3929 	add	hl, hl
   6056 19            [11] 3930 	add	hl, de
   6057 29            [11] 3931 	add	hl, hl
   6058 19            [11] 3932 	add	hl, de
   6059 09            [11] 3933 	add	hl, bc
   605A C5            [11] 3934 	push	bc
   605B AF            [ 4] 3935 	xor	a, a
   605C F5            [11] 3936 	push	af
   605D 33            [ 6] 3937 	inc	sp
   605E E5            [11] 3938 	push	hl
   605F CD FE 54      [17] 3939 	call	_PrintExplosion
   6062 F1            [10] 3940 	pop	af
   6063 33            [ 6] 3941 	inc	sp
   6064 21 14 00      [10] 3942 	ld	hl, #0x0014
   6067 CD B4 4D      [17] 3943 	call	_Pause
   606A C1            [10] 3944 	pop	bc
                           3945 ;src/main.c:1194: spr[ct].lives = 0;
   606B ED 5B B1 4B   [20] 3946 	ld	de, (_ct)
   606F 16 00         [ 7] 3947 	ld	d, #0x00
   6071 6B            [ 4] 3948 	ld	l, e
   6072 62            [ 4] 3949 	ld	h, d
   6073 29            [11] 3950 	add	hl, hl
   6074 29            [11] 3951 	add	hl, hl
   6075 29            [11] 3952 	add	hl, hl
   6076 19            [11] 3953 	add	hl, de
   6077 29            [11] 3954 	add	hl, hl
   6078 19            [11] 3955 	add	hl, de
   6079 09            [11] 3956 	add	hl, bc
   607A 11 09 00      [10] 3957 	ld	de, #0x0009
   607D 19            [11] 3958 	add	hl, de
   607E 36 00         [10] 3959 	ld	(hl), #0x00
                           3960 ;src/main.c:1195: spr[ct].status = S_walking;
   6080 ED 5B B1 4B   [20] 3961 	ld	de, (_ct)
   6084 16 00         [ 7] 3962 	ld	d, #0x00
   6086 6B            [ 4] 3963 	ld	l, e
   6087 62            [ 4] 3964 	ld	h, d
   6088 29            [11] 3965 	add	hl, hl
   6089 29            [11] 3966 	add	hl, hl
   608A 29            [11] 3967 	add	hl, hl
   608B 19            [11] 3968 	add	hl, de
   608C 29            [11] 3969 	add	hl, hl
   608D 19            [11] 3970 	add	hl, de
   608E 09            [11] 3971 	add	hl, bc
   608F 11 04 00      [10] 3972 	ld	de, #0x0004
   6092 19            [11] 3973 	add	hl, de
   6093 36 01         [10] 3974 	ld	(hl), #0x01
                           3975 ;src/main.c:1196: DeleteSprite(&spr[ct]);
   6095 ED 5B B1 4B   [20] 3976 	ld	de, (_ct)
   6099 16 00         [ 7] 3977 	ld	d, #0x00
   609B 6B            [ 4] 3978 	ld	l, e
   609C 62            [ 4] 3979 	ld	h, d
   609D 29            [11] 3980 	add	hl, hl
   609E 29            [11] 3981 	add	hl, hl
   609F 29            [11] 3982 	add	hl, hl
   60A0 19            [11] 3983 	add	hl, de
   60A1 29            [11] 3984 	add	hl, hl
   60A2 19            [11] 3985 	add	hl, de
   60A3 09            [11] 3986 	add	hl, bc
   60A4 C5            [11] 3987 	push	bc
   60A5 CD 90 54      [17] 3988 	call	_DeleteSprite
   60A8 C1            [10] 3989 	pop	bc
   60A9                    3990 00105$:
                           3991 ;src/main.c:1187: for (ct = 1; ct < 4; ct++)
   60A9 FD 21 B1 4B   [14] 3992 	ld	iy, #_ct
   60AD FD 34 00      [23] 3993 	inc	0 (iy)
   60B0 FD 7E 00      [19] 3994 	ld	a, 0 (iy)
   60B3 D6 04         [ 7] 3995 	sub	a, #0x04
   60B5 DA D9 5F      [10] 3996 	jp	C, 00104$
   60B8 C9            [10] 3997 	ret
                           3998 ;src/main.c:1214: void PrintStartMenu() {
                           3999 ;	---------------------------------
                           4000 ; Function PrintStartMenu
                           4001 ; ---------------------------------
   60B9                    4002 _PrintStartMenu::
                           4003 ;src/main.c:1215: cpct_drawSprite(g_logo, cpctm_screenPtr(CPCT_VMEM_START, 17, 0), G_LOGO_W, G_LOGO_H);
   60B9 21 2E 16      [10] 4004 	ld	hl, #0x162e
   60BC E5            [11] 4005 	push	hl
   60BD 21 11 C0      [10] 4006 	ld	hl, #0xc011
   60C0 E5            [11] 4007 	push	hl
   60C1 21 21 16      [10] 4008 	ld	hl, #_g_logo
   60C4 E5            [11] 4009 	push	hl
   60C5 CD DC 46      [17] 4010 	call	_cpct_drawSprite
                           4011 ;src/main.c:1217: PrintText("1@START@GAME", 2, 45);
   60C8 21 02 2D      [10] 4012 	ld	hl, #0x2d02
   60CB E5            [11] 4013 	push	hl
   60CC 21 12 61      [10] 4014 	ld	hl, #___str_1
   60CF E5            [11] 4015 	push	hl
   60D0 CD 90 4E      [17] 4016 	call	_PrintText
   60D3 F1            [10] 4017 	pop	af
                           4018 ;src/main.c:1218: PrintText("2@REDEFINE@CONTROLS", 2, 60);
   60D4 21 02 3C      [10] 4019 	ld	hl, #0x3c02
   60D7 E3            [19] 4020 	ex	(sp),hl
   60D8 21 1F 61      [10] 4021 	ld	hl, #___str_2
   60DB E5            [11] 4022 	push	hl
   60DC CD 90 4E      [17] 4023 	call	_PrintText
   60DF F1            [10] 4024 	pop	af
                           4025 ;src/main.c:1220: PrintText("SALVAKANTERO", 16,140);
   60E0 21 10 8C      [10] 4026 	ld	hl, #0x8c10
   60E3 E3            [19] 4027 	ex	(sp),hl
   60E4 21 33 61      [10] 4028 	ld	hl, #___str_3
   60E7 E5            [11] 4029 	push	hl
   60E8 CD 90 4E      [17] 4030 	call	_PrintText
   60EB F1            [10] 4031 	pop	af
                           4032 ;src/main.c:1221: PrintText("FELIPE@VAKAPP", 14, 155);
   60EC 21 0E 9B      [10] 4033 	ld	hl, #0x9b0e
   60EF E3            [19] 4034 	ex	(sp),hl
   60F0 21 40 61      [10] 4035 	ld	hl, #___str_4
   60F3 E5            [11] 4036 	push	hl
   60F4 CD 90 4E      [17] 4037 	call	_PrintText
   60F7 F1            [10] 4038 	pop	af
                           4039 ;src/main.c:1222: PrintText("TACHA", 29,170);
   60F8 21 1D AA      [10] 4040 	ld	hl, #0xaa1d
   60FB E3            [19] 4041 	ex	(sp),hl
   60FC 21 4E 61      [10] 4042 	ld	hl, #___str_5
   60FF E5            [11] 4043 	push	hl
   6100 CD 90 4E      [17] 4044 	call	_PrintText
   6103 F1            [10] 4045 	pop	af
                           4046 ;src/main.c:1224: PrintText("PLAY@ON@RETRO@2022", 4, 191);
   6104 21 04 BF      [10] 4047 	ld	hl, #0xbf04
   6107 E3            [19] 4048 	ex	(sp),hl
   6108 21 54 61      [10] 4049 	ld	hl, #___str_6
   610B E5            [11] 4050 	push	hl
   610C CD 90 4E      [17] 4051 	call	_PrintText
   610F F1            [10] 4052 	pop	af
   6110 F1            [10] 4053 	pop	af
   6111 C9            [10] 4054 	ret
   6112                    4055 ___str_1:
   6112 31 40 53 54 41 52  4056 	.ascii "1@START@GAME"
        54 40 47 41 4D 45
   611E 00                 4057 	.db 0x00
   611F                    4058 ___str_2:
   611F 32 40 52 45 44 45  4059 	.ascii "2@REDEFINE@CONTROLS"
        46 49 4E 45 40 43
        4F 4E 54 52 4F 4C
        53
   6132 00                 4060 	.db 0x00
   6133                    4061 ___str_3:
   6133 53 41 4C 56 41 4B  4062 	.ascii "SALVAKANTERO"
        41 4E 54 45 52 4F
   613F 00                 4063 	.db 0x00
   6140                    4064 ___str_4:
   6140 46 45 4C 49 50 45  4065 	.ascii "FELIPE@VAKAPP"
        40 56 41 4B 41 50
        50
   614D 00                 4066 	.db 0x00
   614E                    4067 ___str_5:
   614E 54 41 43 48 41     4068 	.ascii "TACHA"
   6153 00                 4069 	.db 0x00
   6154                    4070 ___str_6:
   6154 50 4C 41 59 40 4F  4071 	.ascii "PLAY@ON@RETRO@2022"
        4E 40 52 45 54 52
        4F 40 32 30 32 32
   6166 00                 4072 	.db 0x00
                           4073 ;src/main.c:1228: void StartMenu() {
                           4074 ;	---------------------------------
                           4075 ; Function StartMenu
                           4076 ; ---------------------------------
   6167                    4077 _StartMenu::
                           4078 ;src/main.c:1229: cpct_akp_musicInit(Menu); // initialize music. Main theme 
   6167 21 FA 02      [10] 4079 	ld	hl, #_Menu
   616A E5            [11] 4080 	push	hl
   616B CD B8 45      [17] 4081 	call	_cpct_akp_musicInit
   616E F1            [10] 4082 	pop	af
                           4083 ;src/main.c:1230: ClearScreen();
   616F CD E9 4D      [17] 4084 	call	_ClearScreen
                           4085 ;src/main.c:1231: PrintStartMenu();
   6172 CD B9 60      [17] 4086 	call	_PrintStartMenu
                           4087 ;src/main.c:1233: while(1) {
   6175                    4088 00107$:
                           4089 ;src/main.c:1234: cpct_scanKeyboard_f();
   6175 CD 3D 3E      [17] 4090 	call	_cpct_scanKeyboard_f
                           4091 ;src/main.c:1236: if(cpct_isKeyPressed(Key_1)) { // start game
   6178 21 08 01      [10] 4092 	ld	hl, #0x0108
   617B CD 31 3E      [17] 4093 	call	_cpct_isKeyPressed
   617E 7D            [ 4] 4094 	ld	a, l
   617F B7            [ 4] 4095 	or	a, a
   6180 20 6D         [12] 4096 	jr	NZ,00108$
                           4097 ;src/main.c:1239: else if(cpct_isKeyPressed(Key_2)){ // redefine keys
   6182 21 08 02      [10] 4098 	ld	hl, #0x0208
   6185 CD 31 3E      [17] 4099 	call	_cpct_isKeyPressed
   6188 7D            [ 4] 4100 	ld	a, l
   6189 B7            [ 4] 4101 	or	a, a
   618A 28 5B         [12] 4102 	jr	Z,00105$
                           4103 ;src/main.c:1240: Wait4Key(Key_2);
   618C 21 08 02      [10] 4104 	ld	hl, #0x0208
   618F CD D9 50      [17] 4105 	call	_Wait4Key
                           4106 ;src/main.c:1241: ctlUp = 	RedefineKey("@@UP@");
   6192 21 19 62      [10] 4107 	ld	hl, #___str_7
   6195 CD F6 50      [17] 4108 	call	_RedefineKey
   6198 22 B2 4B      [16] 4109 	ld	(_ctlUp), hl
                           4110 ;src/main.c:1242: ctlDown = 	RedefineKey("@DOWN");
   619B 21 1F 62      [10] 4111 	ld	hl, #___str_8
   619E CD F6 50      [17] 4112 	call	_RedefineKey
   61A1 22 B4 4B      [16] 4113 	ld	(_ctlDown), hl
                           4114 ;src/main.c:1243: ctlLeft = 	RedefineKey("@LEFT");
   61A4 21 25 62      [10] 4115 	ld	hl, #___str_9
   61A7 CD F6 50      [17] 4116 	call	_RedefineKey
   61AA 22 B6 4B      [16] 4117 	ld	(_ctlLeft), hl
                           4118 ;src/main.c:1244: ctlRight = 	RedefineKey("RIGHT");
   61AD 21 2B 62      [10] 4119 	ld	hl, #___str_10
   61B0 CD F6 50      [17] 4120 	call	_RedefineKey
   61B3 22 B8 4B      [16] 4121 	ld	(_ctlRight), hl
                           4122 ;src/main.c:1245: ctlFire = 	RedefineKey("@FIRE");
   61B6 21 31 62      [10] 4123 	ld	hl, #___str_11
   61B9 CD F6 50      [17] 4124 	call	_RedefineKey
   61BC 22 BA 4B      [16] 4125 	ld	(_ctlFire), hl
                           4126 ;src/main.c:1246: ctlAbort = 	RedefineKey("ABORT");
   61BF 21 37 62      [10] 4127 	ld	hl, #___str_12
   61C2 CD F6 50      [17] 4128 	call	_RedefineKey
   61C5 22 BE 4B      [16] 4129 	ld	(_ctlAbort), hl
                           4130 ;src/main.c:1247: ctlMusic = 	RedefineKey("MUSIC");
   61C8 21 3D 62      [10] 4131 	ld	hl, #___str_13
   61CB CD F6 50      [17] 4132 	call	_RedefineKey
   61CE 22 BC 4B      [16] 4133 	ld	(_ctlMusic), hl
                           4134 ;src/main.c:1248: ctlPause =	RedefineKey("PAUSE");		
   61D1 21 43 62      [10] 4135 	ld	hl, #___str_14
   61D4 CD F6 50      [17] 4136 	call	_RedefineKey
   61D7 22 C0 4B      [16] 4137 	ld	(_ctlPause), hl
                           4138 ;src/main.c:1250: PrintText("@@@@@", 29, 100);
   61DA 21 1D 64      [10] 4139 	ld	hl, #0x641d
   61DD E5            [11] 4140 	push	hl
   61DE 21 49 62      [10] 4141 	ld	hl, #___str_15
   61E1 E5            [11] 4142 	push	hl
   61E2 CD 90 4E      [17] 4143 	call	_PrintText
   61E5 F1            [10] 4144 	pop	af
   61E6 F1            [10] 4145 	pop	af
   61E7                    4146 00105$:
                           4147 ;src/main.c:1252: Pause(3);
   61E7 21 03 00      [10] 4148 	ld	hl, #0x0003
   61EA CD B4 4D      [17] 4149 	call	_Pause
   61ED 18 86         [12] 4150 	jr	00107$
   61EF                    4151 00108$:
                           4152 ;src/main.c:1255: cpct_akp_musicInit(FX);
   61EF 21 00 02      [10] 4153 	ld	hl, #_FX
   61F2 E5            [11] 4154 	push	hl
   61F3 CD B8 45      [17] 4155 	call	_cpct_akp_musicInit
                           4156 ;src/main.c:1256: cpct_akp_SFXPlay (6, 14, 41, 0, 0, AY_CHANNEL_B); // event sound
   61F6 26 02         [ 7] 4157 	ld	h,#0x02
   61F8 E3            [19] 4158 	ex	(sp),hl
   61F9 33            [ 6] 4159 	inc	sp
   61FA 21 00 00      [10] 4160 	ld	hl, #0x0000
   61FD E5            [11] 4161 	push	hl
   61FE 2E 29         [ 7] 4162 	ld	l, #0x29
   6200 E5            [11] 4163 	push	hl
   6201 21 06 0E      [10] 4164 	ld	hl, #0x0e06
   6204 E5            [11] 4165 	push	hl
   6205 CD 5F 46      [17] 4166 	call	_cpct_akp_SFXPlay
   6208 21 07 00      [10] 4167 	ld	hl, #7
   620B 39            [11] 4168 	add	hl, sp
   620C F9            [ 6] 4169 	ld	sp, hl
                           4170 ;src/main.c:1257: ClearScreen();
   620D CD E9 4D      [17] 4171 	call	_ClearScreen
                           4172 ;src/main.c:1259: cpct_akp_musicInit(Ingame1);
   6210 21 75 0B      [10] 4173 	ld	hl, #_Ingame1
   6213 E5            [11] 4174 	push	hl
   6214 CD B8 45      [17] 4175 	call	_cpct_akp_musicInit
   6217 F1            [10] 4176 	pop	af
   6218 C9            [10] 4177 	ret
   6219                    4178 ___str_7:
   6219 40 40 55 50 40     4179 	.ascii "@@UP@"
   621E 00                 4180 	.db 0x00
   621F                    4181 ___str_8:
   621F 40 44 4F 57 4E     4182 	.ascii "@DOWN"
   6224 00                 4183 	.db 0x00
   6225                    4184 ___str_9:
   6225 40 4C 45 46 54     4185 	.ascii "@LEFT"
   622A 00                 4186 	.db 0x00
   622B                    4187 ___str_10:
   622B 52 49 47 48 54     4188 	.ascii "RIGHT"
   6230 00                 4189 	.db 0x00
   6231                    4190 ___str_11:
   6231 40 46 49 52 45     4191 	.ascii "@FIRE"
   6236 00                 4192 	.db 0x00
   6237                    4193 ___str_12:
   6237 41 42 4F 52 54     4194 	.ascii "ABORT"
   623C 00                 4195 	.db 0x00
   623D                    4196 ___str_13:
   623D 4D 55 53 49 43     4197 	.ascii "MUSIC"
   6242 00                 4198 	.db 0x00
   6243                    4199 ___str_14:
   6243 50 41 55 53 45     4200 	.ascii "PAUSE"
   6248 00                 4201 	.db 0x00
   6249                    4202 ___str_15:
   6249 40 40 40 40 40     4203 	.ascii "@@@@@"
   624E 00                 4204 	.db 0x00
                           4205 ;src/main.c:1280: void InitValues() {	
                           4206 ;	---------------------------------
                           4207 ; Function InitValues
                           4208 ; ---------------------------------
   624F                    4209 _InitValues::
                           4210 ;src/main.c:1282: ctlUp = Key_Q;
   624F 21 08 08      [10] 4211 	ld	hl, #0x0808
   6252 22 B2 4B      [16] 4212 	ld	(_ctlUp), hl
                           4213 ;src/main.c:1283: ctlDown = Key_A;
   6255 26 20         [ 7] 4214 	ld	h, #0x20
   6257 22 B4 4B      [16] 4215 	ld	(_ctlDown), hl
                           4216 ;src/main.c:1284: ctlLeft = Key_O;
   625A 21 04 04      [10] 4217 	ld	hl, #0x0404
   625D 22 B6 4B      [16] 4218 	ld	(_ctlLeft), hl
                           4219 ;src/main.c:1285: ctlRight = Key_P;
   6260 21 03 08      [10] 4220 	ld	hl, #0x0803
   6263 22 B8 4B      [16] 4221 	ld	(_ctlRight), hl
                           4222 ;src/main.c:1286: ctlFire = Key_Space;
   6266 21 05 80      [10] 4223 	ld	hl, #0x8005
   6269 22 BA 4B      [16] 4224 	ld	(_ctlFire), hl
                           4225 ;src/main.c:1287: ctlAbort = Key_X;
   626C 2E 07         [ 7] 4226 	ld	l, #0x07
   626E 22 BE 4B      [16] 4227 	ld	(_ctlAbort), hl
                           4228 ;src/main.c:1288: ctlMusic = Key_M;
   6271 21 04 40      [10] 4229 	ld	hl, #0x4004
   6274 22 BC 4B      [16] 4230 	ld	(_ctlMusic), hl
                           4231 ;src/main.c:1289: ctlPause = Key_H;	
   6277 21 05 10      [10] 4232 	ld	hl, #0x1005
   627A 22 C0 4B      [16] 4233 	ld	(_ctlPause), hl
   627D C9            [10] 4234 	ret
                           4235 ;src/main.c:1294: void ResetData() {
                           4236 ;	---------------------------------
                           4237 ; Function ResetData
                           4238 ; ---------------------------------
   627E                    4239 _ResetData::
                           4240 ;src/main.c:1296: spr[0].x = spr[0].px = 0;
   627E 21 C4 4B      [10] 4241 	ld	hl, #(_spr + 0x0002)
   6281 36 00         [10] 4242 	ld	(hl), #0x00
   6283 21 C2 4B      [10] 4243 	ld	hl, #_spr
   6286 36 00         [10] 4244 	ld	(hl), #0x00
                           4245 ;src/main.c:1297: spr[0].y = spr[0].py = 159;
   6288 21 C5 4B      [10] 4246 	ld	hl, #(_spr + 0x0003)
   628B 36 9F         [10] 4247 	ld	(hl), #0x9f
   628D 21 C3 4B      [10] 4248 	ld	hl, #(_spr + 0x0001)
   6290 36 9F         [10] 4249 	ld	(hl), #0x9f
                           4250 ;src/main.c:1298: spr[0].dir = D_right; 
   6292 21 CA 4B      [10] 4251 	ld	hl, #(_spr + 0x0008)
   6295 36 03         [10] 4252 	ld	(hl), #0x03
                           4253 ;src/main.c:1299: spr[0].status = S_stopped;
   6297 21 C6 4B      [10] 4254 	ld	hl, #(_spr + 0x0004)
   629A 36 00         [10] 4255 	ld	(hl), #0x00
                           4256 ;src/main.c:1301: InitMap();
   629C CD 63 4F      [17] 4257 	call	_InitMap
                           4258 ;src/main.c:1302: RefreshScoreboard();
   629F C3 14 4F      [10] 4259 	jp  _RefreshScoreboard
                           4260 ;src/main.c:1307: void InitGame() {
                           4261 ;	---------------------------------
                           4262 ; Function InitGame
                           4263 ; ---------------------------------
   62A2                    4264 _InitGame::
                           4265 ;src/main.c:1308: StartMenu(); // start menu;
   62A2 CD 67 61      [17] 4266 	call	_StartMenu
                           4267 ;src/main.c:1309: music = TRUE;
   62A5 21 AF 4B      [10] 4268 	ld	hl,#_music + 0
   62A8 36 01         [10] 4269 	ld	(hl), #0x01
                           4270 ;src/main.c:1310: mapNumber = 0;
   62AA 21 32 4C      [10] 4271 	ld	hl,#_mapNumber + 0
   62AD 36 00         [10] 4272 	ld	(hl), #0x00
                           4273 ;src/main.c:1311: score = 0;
   62AF 21 00 00      [10] 4274 	ld	hl, #0x0000
   62B2 22 AB 4B      [16] 4275 	ld	(_score), hl
                           4276 ;src/main.c:1314: spr[0].object = 255; // no object
   62B5 21 CE 4B      [10] 4277 	ld	hl, #(_spr + 0x000c)
   62B8 36 FF         [10] 4278 	ld	(hl), #0xff
                           4279 ;src/main.c:1315: spr[0].lives = 9; // 10 lives
   62BA 21 CB 4B      [10] 4280 	ld	hl, #(_spr + 0x0009)
   62BD 36 09         [10] 4281 	ld	(hl), #0x09
                           4282 ;src/main.c:1317: InitScoreboard();
   62BF CD F6 4E      [17] 4283 	call	_InitScoreboard
                           4284 ;src/main.c:1319: InitObjects();
   62C2 CD ED 53      [17] 4285 	call	_InitObjects
                           4286 ;src/main.c:1321: ResetData();
   62C5 C3 7E 62      [10] 4287 	jp  _ResetData
                           4288 ;src/main.c:1326: void GameOver() {
                           4289 ;	---------------------------------
                           4290 ; Function GameOver
                           4291 ; ---------------------------------
   62C8                    4292 _GameOver::
                           4293 ;src/main.c:1328: if (spr[0].lives > 0) 
   62C8 3A CB 4B      [13] 4294 	ld	a, (#(_spr + 0x0009) + 0)
   62CB B7            [ 4] 4295 	or	a, a
                           4296 ;src/main.c:1329: ResetData(); // reassign data to some variables
   62CC C2 7E 62      [10] 4297 	jp	NZ,_ResetData
                           4298 ;src/main.c:1331: cpct_akp_musicInit(FX); // stop the music
   62CF 21 00 02      [10] 4299 	ld	hl, #_FX
   62D2 E5            [11] 4300 	push	hl
   62D3 CD B8 45      [17] 4301 	call	_cpct_akp_musicInit
   62D6 F1            [10] 4302 	pop	af
                           4303 ;src/main.c:1332: RefreshScoreboard();
   62D7 CD 14 4F      [17] 4304 	call	_RefreshScoreboard
                           4305 ;src/main.c:1334: PrintText("@@@@@@@@@@@", 18, 102);
   62DA 21 12 66      [10] 4306 	ld	hl, #0x6612
   62DD E5            [11] 4307 	push	hl
   62DE 21 0F 63      [10] 4308 	ld	hl, #___str_16
   62E1 E5            [11] 4309 	push	hl
   62E2 CD 90 4E      [17] 4310 	call	_PrintText
   62E5 F1            [10] 4311 	pop	af
                           4312 ;src/main.c:1335: PrintText("@GAME@OVER@", 18, 110);
   62E6 21 12 6E      [10] 4313 	ld	hl, #0x6e12
   62E9 E3            [19] 4314 	ex	(sp),hl
   62EA 21 1B 63      [10] 4315 	ld	hl, #___str_17
   62ED E5            [11] 4316 	push	hl
   62EE CD 90 4E      [17] 4317 	call	_PrintText
   62F1 F1            [10] 4318 	pop	af
                           4319 ;src/main.c:1336: PrintText("@@@@@@@@@@@", 18, 118);
   62F2 21 12 76      [10] 4320 	ld	hl, #0x7612
   62F5 E3            [19] 4321 	ex	(sp),hl
   62F6 21 0F 63      [10] 4322 	ld	hl, #___str_16
   62F9 E5            [11] 4323 	push	hl
   62FA CD 90 4E      [17] 4324 	call	_PrintText
   62FD F1            [10] 4325 	pop	af
   62FE F1            [10] 4326 	pop	af
                           4327 ;src/main.c:1337: Pause(500);
   62FF 21 F4 01      [10] 4328 	ld	hl, #0x01f4
   6302 CD B4 4D      [17] 4329 	call	_Pause
                           4330 ;src/main.c:1339: while (!cpct_isAnyKeyPressed());
   6305                    4331 00101$:
   6305 CD 56 48      [17] 4332 	call	_cpct_isAnyKeyPressed
   6308 7D            [ 4] 4333 	ld	a, l
   6309 B7            [ 4] 4334 	or	a, a
   630A 28 F9         [12] 4335 	jr	Z,00101$
                           4336 ;src/main.c:1340: InitGame();
   630C C3 A2 62      [10] 4337 	jp  _InitGame
   630F                    4338 ___str_16:
   630F 40 40 40 40 40 40  4339 	.ascii "@@@@@@@@@@@"
        40 40 40 40 40
   631A 00                 4340 	.db 0x00
   631B                    4341 ___str_17:
   631B 40 47 41 4D 45 40  4342 	.ascii "@GAME@OVER@"
        4F 56 45 52 40
   6326 00                 4343 	.db 0x00
                           4344 ;src/main.c:1345: void main(void) 
                           4345 ;	---------------------------------
                           4346 ; Function main
                           4347 ; ---------------------------------
   6327                    4348 _main::
                           4349 ;src/main.c:1347: cpct_disableFirmware(); // disable firmware control
   6327 CD B8 49      [17] 4350 	call	_cpct_disableFirmware
                           4351 ;src/main.c:1348: cpct_akp_SFXInit(FX); //initialize sound effects
   632A 21 00 02      [10] 4352 	ld	hl, #_FX
   632D E5            [11] 4353 	push	hl
   632E CD 44 46      [17] 4354 	call	_cpct_akp_SFXInit
   6331 F1            [10] 4355 	pop	af
                           4356 ;src/main.c:1349: cpct_setInterruptHandler(Interrupt); // initialize the interrupt manager (keyboard and sound)
   6332 21 D0 4D      [10] 4357 	ld	hl, #_Interrupt
   6335 CD 2C 4B      [17] 4358 	call	_cpct_setInterruptHandler
                           4359 ;src/main.c:1350: cpct_setVideoMode(0); // activate mode 0; 160*200 16 colors
   6338 2E 00         [ 7] 4360 	ld	l, #0x00
   633A CD 80 49      [17] 4361 	call	_cpct_setVideoMode
                           4362 ;src/main.c:1351: cpct_setPalette(g_palette, 16); // assign palette
   633D 21 10 00      [10] 4363 	ld	hl, #0x0010
   6340 E5            [11] 4364 	push	hl
   6341 21 15 2E      [10] 4365 	ld	hl, #_g_palette
   6344 E5            [11] 4366 	push	hl
   6345 CD 1A 3E      [17] 4367 	call	_cpct_setPalette
                           4368 ;src/main.c:1352: cpct_setBorder(g_palette[1]); // print border (black)
   6348 21 16 2E      [10] 4369 	ld	hl, #_g_palette + 1
   634B 46            [ 7] 4370 	ld	b, (hl)
   634C C5            [11] 4371 	push	bc
   634D 33            [ 6] 4372 	inc	sp
   634E 3E 10         [ 7] 4373 	ld	a, #0x10
   6350 F5            [11] 4374 	push	af
   6351 33            [ 6] 4375 	inc	sp
   6352 CD A7 3E      [17] 4376 	call	_cpct_setPALColour
                           4377 ;src/main.c:1353: cpct_etm_setTileset2x4(g_tileset); // keep in memory the tiles for the maps (4 * 4)		
   6355 21 25 2E      [10] 4378 	ld	hl, #_g_tileset
   6358 CD 10 48      [17] 4379 	call	_cpct_etm_setTileset2x4
                           4380 ;src/main.c:1354: InitValues(); // assigns default values ​​that do not vary between games
   635B CD 4F 62      [17] 4381 	call	_InitValues
                           4382 ;src/main.c:1355: InitGame(); // initialization of some variables
   635E CD A2 62      [17] 4383 	call	_InitGame
                           4384 ;src/main.c:1357: while (1) { // main loop		
   6361                    4385 00108$:
                           4386 ;src/main.c:1359: ReprintObjects();
   6361 CD DA 51      [17] 4387 	call	_ReprintObjects
                           4388 ;src/main.c:1361: RunStatus(); // call the appropriate function according to the player status  
   6364 CD A1 5A      [17] 4389 	call	_RunStatus
                           4390 ;src/main.c:1362: SelectFrame(); // we assign the next frame of the animation to the player
   6367 CD 81 56      [17] 4391 	call	_SelectFrame
                           4392 ;src/main.c:1363: DeleteSprite(&spr[0]);
   636A 21 C2 4B      [10] 4393 	ld	hl, #_spr
   636D CD 90 54      [17] 4394 	call	_DeleteSprite
                           4395 ;src/main.c:1364: spr[0].px = spr[0].x; // save the current X coordinate
   6370 01 C4 4B      [10] 4396 	ld	bc, #_spr + 2
   6373 3A C2 4B      [13] 4397 	ld	a, (#_spr + 0)
   6376 02            [ 7] 4398 	ld	(bc), a
                           4399 ;src/main.c:1365: spr[0].py = spr[0].y; // save the current Y coordinate
   6377 01 C5 4B      [10] 4400 	ld	bc, #_spr + 3
   637A 3A C3 4B      [13] 4401 	ld	a, (#_spr + 1)
   637D 02            [ 7] 4402 	ld	(bc), a
                           4403 ;src/main.c:1366: PrintSprite(&spr[0]); // prints the player in the new XY position
   637E 21 C2 4B      [10] 4404 	ld	hl, #_spr
   6381 CD 66 54      [17] 4405 	call	_PrintSprite
                           4406 ;src/main.c:1368: if (OverMines()) { // the player is stepping on mines?
   6384 CD 19 50      [17] 4407 	call	_OverMines
   6387 7D            [ 4] 4408 	ld	a, l
   6388 B7            [ 4] 4409 	or	a, a
   6389 28 0F         [12] 4410 	jr	Z,00102$
                           4411 ;src/main.c:1369: spr[0].lives--;
   638B 21 CB 4B      [10] 4412 	ld	hl, #_spr + 9
   638E 4E            [ 7] 4413 	ld	c, (hl)
   638F 0D            [ 4] 4414 	dec	c
   6390 71            [ 7] 4415 	ld	(hl), c
                           4416 ;src/main.c:1370: ExplodePlayer();
   6391 CD DC 5A      [17] 4417 	call	_ExplodePlayer
                           4418 ;src/main.c:1371: ExplodeEnemies();
   6394 CD D1 5F      [17] 4419 	call	_ExplodeEnemies
                           4420 ;src/main.c:1372: GameOver();
   6397 CD C8 62      [17] 4421 	call	_GameOver
   639A                    4422 00102$:
                           4423 ;src/main.c:1375: EnemyLoop(&spr[1]);
   639A 21 D5 4B      [10] 4424 	ld	hl, #(_spr + 0x0013)
   639D CD 48 5F      [17] 4425 	call	_EnemyLoop
                           4426 ;src/main.c:1376: EnemyLoop(&spr[2]);
   63A0 21 E8 4B      [10] 4427 	ld	hl, #(_spr + 0x0026)
   63A3 CD 48 5F      [17] 4428 	call	_EnemyLoop
                           4429 ;src/main.c:1377: EnemyLoop(&spr[3]);
   63A6 21 FB 4B      [10] 4430 	ld	hl, #(_spr + 0x0039)
   63A9 CD 48 5F      [17] 4431 	call	_EnemyLoop
                           4432 ;src/main.c:1379: if (ctMainLoop % 15 == 0) // reprint scoreboard data
   63AC 3E 0F         [ 7] 4433 	ld	a, #0x0f
   63AE F5            [11] 4434 	push	af
   63AF 33            [ 6] 4435 	inc	sp
   63B0 3A B0 4B      [13] 4436 	ld	a, (_ctMainLoop)
   63B3 F5            [11] 4437 	push	af
   63B4 33            [ 6] 4438 	inc	sp
   63B5 CD 14 48      [17] 4439 	call	__moduchar
   63B8 F1            [10] 4440 	pop	af
   63B9 7D            [ 4] 4441 	ld	a, l
   63BA B7            [ 4] 4442 	or	a, a
   63BB 20 03         [12] 4443 	jr	NZ,00104$
                           4444 ;src/main.c:1380: RefreshScoreboard();	
   63BD CD 14 4F      [17] 4445 	call	_RefreshScoreboard
   63C0                    4446 00104$:
                           4447 ;src/main.c:1382: cpct_waitVSYNC(); // wait for vertical retrace
   63C0 CD 78 49      [17] 4448 	call	_cpct_waitVSYNC
                           4449 ;src/main.c:1384: if (++ctMainLoop == 255) ctMainLoop = 0;
   63C3 FD 21 B0 4B   [14] 4450 	ld	iy, #_ctMainLoop
   63C7 FD 34 00      [23] 4451 	inc	0 (iy)
   63CA FD 7E 00      [19] 4452 	ld	a, 0 (iy)
   63CD 3C            [ 4] 4453 	inc	a
   63CE 20 91         [12] 4454 	jr	NZ,00108$
   63D0 FD 36 00 00   [19] 4455 	ld	0 (iy), #0x00
   63D4 18 8B         [12] 4456 	jr	00108$
                           4457 	.area _CODE
                           4458 	.area _INITIALIZER
   4C33                    4459 __xinit__mapNumber:
   4C33 00                 4460 	.db #0x00	; 0
                           4461 	.area _CABS (ABS)
