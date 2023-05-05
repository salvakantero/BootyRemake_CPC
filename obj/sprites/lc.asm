;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.6.8 #9946 (Linux)
;--------------------------------------------------------
	.module lc
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _g_lc
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
_g_lc:
	.db #0x00	; 0
	.db #0xc0	; 192
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0xc4	; 196
	.db #0x80	; 128
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x91	; 145
	.db #0xe2	; 226
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x91	; 145
	.db #0x62	; 98	'b'
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x55	; 85	'U'
	.db #0xc0	; 192
	.db #0x84	; 132
	.db #0x8c	; 140
	.db #0x0c	; 12
	.db #0x80	; 128
	.db #0x40	; 64
	.db #0xc0	; 192
	.db #0x88	; 136
	.db #0x84	; 132
	.db #0xcc	; 204
	.db #0xcf	; 207
	.db #0xcf	; 207
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0x42	; 66	'B'
	.db #0xaa	; 170
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0x43	; 67	'C'
	.db #0xc7	; 199
	.db #0x91	; 145
	.db #0xc8	; 200
	.db #0xca	; 202
	.db #0x2a	; 42
	.db #0xc4	; 196
	.db #0x0c	; 12
	.db #0x81	; 129
	.db #0xc3	; 195
	.db #0x91	; 145
	.db #0xe2	; 226
	.db #0xc2	; 194
	.db #0x15	; 21
	.db #0x81	; 129
	.db #0x03	; 3
	.db #0x48	; 72	'H'
	.db #0x43	; 67	'C'
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0x42	; 66	'B'
	.db #0x00	; 0
	.db #0xc5	; 197
	.db #0x83	; 131
	.db #0x48	; 72	'H'
	.db #0x03	; 3
	.db #0x80	; 128
	.db #0x40	; 64
	.db #0xc0	; 192
	.db #0x00	; 0
	.db #0x40	; 64
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x95	; 149
	.db #0x9d	; 157
	.db #0x80	; 128
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x84	; 132
	.db #0x8c	; 140
	.db #0x80	; 128
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0x80	; 128
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x40	; 64
	.db #0x9a	; 154
	.db #0xd0	; 208
	.db #0x94	; 148
	.db #0xd4	; 212
	.db #0xca	; 202
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0xc1	; 193
	.db #0x03	; 3
	.db #0x03	; 3
	.db #0x03	; 3
	.db #0x03	; 3
	.db #0x43	; 67	'C'
	.db #0x80	; 128
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0xc0	; 192
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x40	; 64
	.db #0xc8	; 200
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0xd1	; 209
	.db #0x62	; 98	'b'
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0x91	; 145
	.db #0x62	; 98	'b'
	.db #0x00	; 0
	.db #0xc0	; 192
	.db #0x80	; 128
	.db #0x40	; 64
	.db #0x0c	; 12
	.db #0x4c	; 76	'L'
	.db #0x48	; 72	'H'
	.db #0xc0	; 192
	.db #0xaa	; 170
	.db #0x81	; 129
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0xcf	; 207
	.db #0xcf	; 207
	.db #0xcc	; 204
	.db #0x48	; 72	'H'
	.db #0x44	; 68	'D'
	.db #0xc5	; 197
	.db #0xc4	; 196
	.db #0x62	; 98	'b'
	.db #0xcb	; 203
	.db #0x83	; 131
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0x55	; 85	'U'
	.db #0xc1	; 193
	.db #0xd1	; 209
	.db #0x62	; 98	'b'
	.db #0xc3	; 195
	.db #0x42	; 66	'B'
	.db #0x0c	; 12
	.db #0xc8	; 200
	.db #0x15	; 21
	.db #0x81	; 129
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0x83	; 131
	.db #0x84	; 132
	.db #0x03	; 3
	.db #0x42	; 66	'B'
	.db #0x2a	; 42
	.db #0xc0	; 192
	.db #0x80	; 128
	.db #0x40	; 64
	.db #0x03	; 3
	.db #0x84	; 132
	.db #0x43	; 67	'C'
	.db #0xca	; 202
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0x80	; 128
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x40	; 64
	.db #0x6e	; 110	'n'
	.db #0x6a	; 106	'j'
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x40	; 64
	.db #0x4c	; 76	'L'
	.db #0x48	; 72	'H'
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x40	; 64
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0xc5	; 197
	.db #0xe8	; 232
	.db #0x68	; 104	'h'
	.db #0xe0	; 224
	.db #0x65	; 101	'e'
	.db #0x80	; 128
	.db #0x00	; 0
	.db #0x40	; 64
	.db #0x83	; 131
	.db #0x03	; 3
	.db #0x03	; 3
	.db #0x03	; 3
	.db #0x03	; 3
	.db #0xc2	; 194
	.area _INITIALIZER
	.area _CABS (ABS)
