;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.6.8 #9946 (Linux)
;--------------------------------------------------------
	.module explosion
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _g_explosion
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
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
	.area _CODE
_g_explosion:
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0xc0	; 192
	.db #0xc3	; 195
	.db #0xc3	; 195
	.db #0xc0	; 192
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x40	; 64
	.db #0xc3	; 195
	.db #0x0f	; 15
	.db #0x0f	; 15
	.db #0xc3	; 195
	.db #0x80	; 128
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0xc1	; 193
	.db #0x0f	; 15
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0x0f	; 15
	.db #0xc2	; 194
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0xc1	; 193
	.db #0x5f	; 95
	.db #0xcc	; 204
	.db #0xcc	; 204
	.db #0xaf	; 175
	.db #0xc2	; 194
	.db #0x00	; 0
	.db #0x40	; 64
	.db #0x87	; 135
	.db #0xee	; 238
	.db #0xcc	; 204
	.db #0xcc	; 204
	.db #0xdd	; 221
	.db #0x4b	; 75	'K'
	.db #0x80	; 128
	.db #0x40	; 64
	.db #0x87	; 135
	.db #0xee	; 238
	.db #0xcc	; 204
	.db #0xcc	; 204
	.db #0xdd	; 221
	.db #0x4b	; 75	'K'
	.db #0x80	; 128
	.db #0x40	; 64
	.db #0x87	; 135
	.db #0xee	; 238
	.db #0xcc	; 204
	.db #0xcc	; 204
	.db #0xdd	; 221
	.db #0x4b	; 75	'K'
	.db #0x80	; 128
	.db #0x40	; 64
	.db #0x87	; 135
	.db #0xee	; 238
	.db #0xcc	; 204
	.db #0xcc	; 204
	.db #0xdd	; 221
	.db #0x4b	; 75	'K'
	.db #0x80	; 128
	.db #0x00	; 0
	.db #0xc1	; 193
	.db #0x5f	; 95
	.db #0xcc	; 204
	.db #0xcc	; 204
	.db #0xaf	; 175
	.db #0xc2	; 194
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0xc1	; 193
	.db #0x0f	; 15
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0x0f	; 15
	.db #0xc2	; 194
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x40	; 64
	.db #0xc3	; 195
	.db #0x0f	; 15
	.db #0x0f	; 15
	.db #0xc3	; 195
	.db #0x80	; 128
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0xc0	; 192
	.db #0xc3	; 195
	.db #0xc3	; 195
	.db #0xc0	; 192
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0x80	; 128
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0xc0	; 192
	.db #0xc3	; 195
	.db #0xc3	; 195
	.db #0xc0	; 192
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x40	; 64
	.db #0xc3	; 195
	.db #0x0f	; 15
	.db #0x0f	; 15
	.db #0xc3	; 195
	.db #0x80	; 128
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0xc1	; 193
	.db #0x0f	; 15
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0x0f	; 15
	.db #0xc2	; 194
	.db #0x00	; 0
	.db #0x40	; 64
	.db #0x87	; 135
	.db #0xff	; 255
	.db #0xcc	; 204
	.db #0xcc	; 204
	.db #0xff	; 255
	.db #0x4b	; 75	'K'
	.db #0x80	; 128
	.db #0xc1	; 193
	.db #0x5f	; 95
	.db #0xcc	; 204
	.db #0xcc	; 204
	.db #0xcc	; 204
	.db #0xcc	; 204
	.db #0xaf	; 175
	.db #0xc2	; 194
	.db #0xc1	; 193
	.db #0x5f	; 95
	.db #0xcc	; 204
	.db #0xcc	; 204
	.db #0xcc	; 204
	.db #0xcc	; 204
	.db #0xaf	; 175
	.db #0xc2	; 194
	.db #0x87	; 135
	.db #0xee	; 238
	.db #0xcc	; 204
	.db #0xcc	; 204
	.db #0xcc	; 204
	.db #0xcc	; 204
	.db #0xdd	; 221
	.db #0x4b	; 75	'K'
	.db #0x87	; 135
	.db #0xee	; 238
	.db #0xcc	; 204
	.db #0xcc	; 204
	.db #0xcc	; 204
	.db #0xcc	; 204
	.db #0xdd	; 221
	.db #0x4b	; 75	'K'
	.db #0x87	; 135
	.db #0xee	; 238
	.db #0xcc	; 204
	.db #0xcc	; 204
	.db #0xcc	; 204
	.db #0xcc	; 204
	.db #0xdd	; 221
	.db #0x4b	; 75	'K'
	.db #0x87	; 135
	.db #0xee	; 238
	.db #0xcc	; 204
	.db #0xcc	; 204
	.db #0xcc	; 204
	.db #0xcc	; 204
	.db #0xdd	; 221
	.db #0x4b	; 75	'K'
	.db #0xc1	; 193
	.db #0x5f	; 95
	.db #0xcc	; 204
	.db #0xcc	; 204
	.db #0xcc	; 204
	.db #0xcc	; 204
	.db #0xaf	; 175
	.db #0xc2	; 194
	.db #0xc1	; 193
	.db #0x5f	; 95
	.db #0xcc	; 204
	.db #0xcc	; 204
	.db #0xcc	; 204
	.db #0xcc	; 204
	.db #0xaf	; 175
	.db #0xc2	; 194
	.db #0x40	; 64
	.db #0x87	; 135
	.db #0xff	; 255
	.db #0xcc	; 204
	.db #0xcc	; 204
	.db #0xff	; 255
	.db #0x4b	; 75	'K'
	.db #0x80	; 128
	.db #0x00	; 0
	.db #0xc1	; 193
	.db #0x0f	; 15
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0x0f	; 15
	.db #0xc2	; 194
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x40	; 64
	.db #0xc3	; 195
	.db #0x0f	; 15
	.db #0x0f	; 15
	.db #0xc3	; 195
	.db #0x80	; 128
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0xc0	; 192
	.db #0xc3	; 195
	.db #0xc3	; 195
	.db #0xc0	; 192
	.db #0x00	; 0
	.db #0x00	; 0
	.area _INITIALIZER
	.area _CABS (ABS)
