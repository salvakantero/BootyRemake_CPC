;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.6.8 #9946 (Linux)
;--------------------------------------------------------
	.module tiles
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _g_tiles_59
	.globl _g_tiles_58
	.globl _g_tiles_57
	.globl _g_tiles_56
	.globl _g_tiles_55
	.globl _g_tiles_54
	.globl _g_tiles_53
	.globl _g_tiles_52
	.globl _g_tiles_51
	.globl _g_tiles_50
	.globl _g_tiles_49
	.globl _g_tiles_48
	.globl _g_tiles_47
	.globl _g_tiles_46
	.globl _g_tiles_45
	.globl _g_tiles_44
	.globl _g_tiles_43
	.globl _g_tiles_42
	.globl _g_tiles_41
	.globl _g_tiles_40
	.globl _g_tiles_39
	.globl _g_tiles_38
	.globl _g_tiles_37
	.globl _g_tiles_36
	.globl _g_tiles_35
	.globl _g_tiles_34
	.globl _g_tiles_33
	.globl _g_tiles_32
	.globl _g_tiles_31
	.globl _g_tiles_30
	.globl _g_tiles_29
	.globl _g_tiles_28
	.globl _g_tiles_27
	.globl _g_tiles_26
	.globl _g_tiles_25
	.globl _g_tiles_24
	.globl _g_tiles_23
	.globl _g_tiles_22
	.globl _g_tiles_21
	.globl _g_tiles_20
	.globl _g_tiles_19
	.globl _g_tiles_18
	.globl _g_tiles_17
	.globl _g_tiles_16
	.globl _g_tiles_15
	.globl _g_tiles_14
	.globl _g_tiles_13
	.globl _g_tiles_12
	.globl _g_tiles_11
	.globl _g_tiles_10
	.globl _g_tiles_09
	.globl _g_tiles_08
	.globl _g_tiles_07
	.globl _g_tiles_06
	.globl _g_tiles_05
	.globl _g_tiles_04
	.globl _g_tiles_03
	.globl _g_tiles_02
	.globl _g_tiles_01
	.globl _g_tiles_00
	.globl _g_tileset
	.globl _g_palette
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
_g_palette:
	.db #0x4d	; 77	'M'
	.db #0x54	; 84	'T'
	.db #0x40	; 64
	.db #0x4b	; 75	'K'
	.db #0x44	; 68	'D'
	.db #0x55	; 85	'U'
	.db #0x57	; 87	'W'
	.db #0x53	; 83	'S'
	.db #0x5c	; 92
	.db #0x4c	; 76	'L'
	.db #0x4e	; 78	'N'
	.db #0x47	; 71	'G'
	.db #0x56	; 86	'V'
	.db #0x52	; 82	'R'
	.db #0x5e	; 94
	.db #0x4a	; 74	'J'
_g_tileset:
	.dw _g_tiles_00
	.dw _g_tiles_01
	.dw _g_tiles_02
	.dw _g_tiles_03
	.dw _g_tiles_04
	.dw _g_tiles_05
	.dw _g_tiles_06
	.dw _g_tiles_07
	.dw _g_tiles_08
	.dw _g_tiles_09
	.dw _g_tiles_10
	.dw _g_tiles_11
	.dw _g_tiles_12
	.dw _g_tiles_13
	.dw _g_tiles_14
	.dw _g_tiles_15
	.dw _g_tiles_16
	.dw _g_tiles_17
	.dw _g_tiles_18
	.dw _g_tiles_19
	.dw _g_tiles_20
	.dw _g_tiles_21
	.dw _g_tiles_22
	.dw _g_tiles_23
	.dw _g_tiles_24
	.dw _g_tiles_25
	.dw _g_tiles_26
	.dw _g_tiles_27
	.dw _g_tiles_28
	.dw _g_tiles_29
	.dw _g_tiles_30
	.dw _g_tiles_31
	.dw _g_tiles_32
	.dw _g_tiles_33
	.dw _g_tiles_34
	.dw _g_tiles_35
	.dw _g_tiles_36
	.dw _g_tiles_37
	.dw _g_tiles_38
	.dw _g_tiles_39
	.dw _g_tiles_40
	.dw _g_tiles_41
	.dw _g_tiles_42
	.dw _g_tiles_43
	.dw _g_tiles_44
	.dw _g_tiles_45
	.dw _g_tiles_46
	.dw _g_tiles_47
	.dw _g_tiles_48
	.dw _g_tiles_49
	.dw _g_tiles_50
	.dw _g_tiles_51
	.dw _g_tiles_52
	.dw _g_tiles_53
	.dw _g_tiles_54
	.dw _g_tiles_55
	.dw _g_tiles_56
	.dw _g_tiles_57
	.dw _g_tiles_58
	.dw _g_tiles_59
_g_tiles_00:
	.db #0x9c	; 156
	.db #0x78	; 120	'x'
	.db #0x3c	; 60
	.db #0x78	; 120	'x'
	.db #0x78	; 120	'x'
	.db #0xb0	; 176
	.db #0x30	; 48	'0'
	.db #0x30	; 48	'0'
_g_tiles_01:
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0x90	; 144
	.db #0x60	; 96
_g_tiles_02:
	.db #0xc0	; 192
	.db #0x81	; 129
	.db #0xc0	; 192
	.db #0x81	; 129
	.db #0xc0	; 192
	.db #0x81	; 129
	.db #0x81	; 129
	.db #0x42	; 66	'B'
_g_tiles_03:
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0xc0	; 192
_g_tiles_04:
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0x90	; 144
	.db #0x60	; 96
_g_tiles_05:
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0x90	; 144
	.db #0x60	; 96
_g_tiles_06:
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0xc0	; 192
	.db #0xd1	; 209
	.db #0x90	; 144
	.db #0x31	; 49	'1'
_g_tiles_07:
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0xc8	; 200
	.db #0x90	; 144
	.db #0x62	; 98	'b'
	.db #0x90	; 144
	.db #0x32	; 50	'2'
	.db #0x60	; 96
_g_tiles_08:
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0xc0	; 192
	.db #0xc4	; 196
	.db #0xc0	; 192
	.db #0x91	; 145
	.db #0x90	; 144
	.db #0x31	; 49	'1'
_g_tiles_09:
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0xe2	; 226
	.db #0x90	; 144
	.db #0x32	; 50	'2'
	.db #0x60	; 96
_g_tiles_10:
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0x90	; 144
	.db #0x60	; 96
_g_tiles_11:
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0x90	; 144
	.db #0x60	; 96
_g_tiles_12:
	.db #0x30	; 48	'0'
	.db #0x30	; 48	'0'
	.db #0x34	; 52	'4'
	.db #0x3c	; 60
	.db #0x34	; 52	'4'
	.db #0xf0	; 240
	.db #0x34	; 52	'4'
	.db #0xf0	; 240
_g_tiles_13:
	.db #0x30	; 48	'0'
	.db #0x30	; 48	'0'
	.db #0x3c	; 60
	.db #0x3c	; 60
	.db #0x3c	; 60
	.db #0x3c	; 60
	.db #0x34	; 52	'4'
	.db #0x3c	; 60
_g_tiles_14:
	.db #0x30	; 48	'0'
	.db #0x30	; 48	'0'
	.db #0x3c	; 60
	.db #0x3c	; 60
	.db #0x3c	; 60
	.db #0x78	; 120	'x'
	.db #0x3c	; 60
	.db #0x78	; 120	'x'
_g_tiles_15:
	.db #0x30	; 48	'0'
	.db #0x30	; 48	'0'
	.db #0x3c	; 60
	.db #0x38	; 56	'8'
	.db #0xb4	; 180
	.db #0x68	; 104	'h'
	.db #0xb0	; 176
	.db #0x38	; 56	'8'
_g_tiles_16:
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0x81	; 129
	.db #0x12	; 18
	.db #0xc5	; 197
	.db #0xce	; 206
	.db #0xc1	; 193
	.db #0xd3	; 211
_g_tiles_17:
	.db #0xc0	; 192
	.db #0x0c	; 12
	.db #0xc0	; 192
	.db #0xcf	; 207
	.db #0x99	; 153
	.db #0xcb	; 203
	.db #0xb3	; 179
	.db #0xc3	; 195
_g_tiles_18:
	.db #0x4c	; 76	'L'
	.db #0x48	; 72	'H'
	.db #0xcf	; 207
	.db #0xcc	; 204
	.db #0x83	; 131
	.db #0xc0	; 192
	.db #0x42	; 66	'B'
	.db #0x0c	; 12
_g_tiles_19:
	.db #0xc0	; 192
	.db #0xba	; 186
	.db #0x48	; 72	'H'
	.db #0xc4	; 196
	.db #0xc0	; 192
	.db #0xd5	; 213
	.db #0xc8	; 200
	.db #0x95	; 149
_g_tiles_20:
	.db #0xd5	; 213
	.db #0xc0	; 192
	.db #0xc8	; 200
	.db #0x84	; 132
	.db #0xea	; 234
	.db #0xc0	; 192
	.db #0x6a	; 106	'j'
	.db #0xc4	; 196
_g_tiles_21:
	.db #0x84	; 132
	.db #0x8c	; 140
	.db #0xcc	; 204
	.db #0xcf	; 207
	.db #0xc0	; 192
	.db #0x43	; 67	'C'
	.db #0x0c	; 12
	.db #0x81	; 129
_g_tiles_22:
	.db #0x0c	; 12
	.db #0x90	; 144
	.db #0xcf	; 207
	.db #0x90	; 144
	.db #0xc7	; 199
	.db #0x66	; 102	'f'
	.db #0xc3	; 195
	.db #0x73	; 115	's'
_g_tiles_23:
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0x81	; 129
	.db #0x12	; 18
	.db #0xcd	; 205
	.db #0x9a	; 154
	.db #0xe3	; 227
	.db #0xc2	; 194
_g_tiles_24:
	.db #0x34	; 52	'4'
	.db #0x38	; 56	'8'
	.db #0x34	; 52	'4'
	.db #0x3c	; 60
	.db #0x34	; 52	'4'
	.db #0x3c	; 60
	.db #0x34	; 52	'4'
	.db #0xf0	; 240
_g_tiles_25:
	.db #0x34	; 52	'4'
	.db #0x3c	; 60
	.db #0x3c	; 60
	.db #0x3c	; 60
	.db #0x3c	; 60
	.db #0x3c	; 60
	.db #0x3c	; 60
	.db #0x3c	; 60
_g_tiles_26:
	.db #0x3c	; 60
	.db #0x3c	; 60
	.db #0x3c	; 60
	.db #0x3c	; 60
	.db #0x3c	; 60
	.db #0x3c	; 60
	.db #0x3c	; 60
	.db #0x78	; 120	'x'
_g_tiles_27:
	.db #0x30	; 48	'0'
	.db #0x38	; 56	'8'
	.db #0x3c	; 60
	.db #0x38	; 56	'8'
	.db #0x3c	; 60
	.db #0x38	; 56	'8'
	.db #0xb4	; 180
	.db #0x68	; 104	'h'
_g_tiles_28:
	.db #0x81	; 129
	.db #0x12	; 18
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0x90	; 144
	.db #0x60	; 96
_g_tiles_29:
	.db #0xc0	; 192
	.db #0x83	; 131
	.db #0xc0	; 192
	.db #0x03	; 3
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0x90	; 144
	.db #0x60	; 96
_g_tiles_30:
	.db #0x84	; 132
	.db #0x03	; 3
	.db #0x84	; 132
	.db #0x43	; 67	'C'
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0x6e	; 110	'n'
	.db #0x6a	; 106	'j'
_g_tiles_31:
	.db #0x42	; 66	'B'
	.db #0x3a	; 58
	.db #0xca	; 202
	.db #0x90	; 144
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0x90	; 144
	.db #0x60	; 96
_g_tiles_32:
	.db #0x95	; 149
	.db #0x81	; 129
	.db #0xc0	; 192
	.db #0xc5	; 197
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0x60	; 96
_g_tiles_33:
	.db #0x03	; 3
	.db #0x48	; 72	'H'
	.db #0x83	; 131
	.db #0x48	; 72	'H'
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0x95	; 149
	.db #0x9d	; 157
_g_tiles_34:
	.db #0x43	; 67	'C'
	.db #0x90	; 144
	.db #0x03	; 3
	.db #0x90	; 144
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0x90	; 144
	.db #0x60	; 96
_g_tiles_35:
	.db #0x81	; 129
	.db #0x12	; 18
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0x90	; 144
	.db #0x60	; 96
_g_tiles_36:
	.db #0x34	; 52	'4'
	.db #0xf0	; 240
	.db #0x34	; 52	'4'
	.db #0x38	; 56	'8'
	.db #0x34	; 52	'4'
	.db #0x3c	; 60
	.db #0x30	; 48	'0'
	.db #0x60	; 96
_g_tiles_37:
	.db #0x34	; 52	'4'
	.db #0x3c	; 60
	.db #0x34	; 52	'4'
	.db #0x3c	; 60
	.db #0x3c	; 60
	.db #0x3c	; 60
	.db #0x30	; 48	'0'
	.db #0x30	; 48	'0'
_g_tiles_38:
	.db #0x3c	; 60
	.db #0x78	; 120	'x'
	.db #0x3c	; 60
	.db #0x3c	; 60
	.db #0x3c	; 60
	.db #0x3c	; 60
	.db #0x60	; 96
	.db #0x30	; 48	'0'
_g_tiles_39:
	.db #0xb0	; 176
	.db #0x38	; 56	'8'
	.db #0x30	; 48	'0'
	.db #0x68	; 104	'h'
	.db #0x3c	; 60
	.db #0x38	; 56	'8'
	.db #0x30	; 48	'0'
	.db #0x30	; 48	'0'
_g_tiles_40:
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0x90	; 144
	.db #0x60	; 96
_g_tiles_41:
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0xc0	; 192
	.db #0x4c	; 76	'L'
	.db #0xc5	; 197
	.db #0xe8	; 232
	.db #0x83	; 131
	.db #0x03	; 3
_g_tiles_42:
	.db #0x4c	; 76	'L'
	.db #0x18	; 24
	.db #0x8c	; 140
	.db #0x0c	; 12
	.db #0x68	; 104	'h'
	.db #0xe0	; 224
	.db #0x03	; 3
	.db #0x03	; 3
_g_tiles_43:
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0x48	; 72	'H'
	.db #0x90	; 144
	.db #0x65	; 101	'e'
	.db #0x90	; 144
	.db #0x03	; 3
	.db #0xc2	; 194
_g_tiles_44:
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0xc0	; 192
	.db #0x84	; 132
	.db #0xc0	; 192
	.db #0x9a	; 154
	.db #0xc1	; 193
	.db #0x03	; 3
_g_tiles_45:
	.db #0x84	; 132
	.db #0x8c	; 140
	.db #0xcc	; 204
	.db #0x0c	; 12
	.db #0xd0	; 208
	.db #0x94	; 148
	.db #0x03	; 3
	.db #0x03	; 3
_g_tiles_46:
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0x0c	; 12
	.db #0x90	; 144
	.db #0xd4	; 212
	.db #0xca	; 202
	.db #0x03	; 3
	.db #0x43	; 67	'C'
_g_tiles_47:
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0xc0	; 192
	.db #0x90	; 144
	.db #0x90	; 144
	.db #0x60	; 96
_g_tiles_48:
	.db #0x95	; 149
	.db #0xaf	; 175
	.db #0x95	; 149
	.db #0x4a	; 74	'J'
	.db #0x95	; 149
	.db #0x1f	; 31
	.db #0x95	; 149
	.db #0x4a	; 74	'J'
_g_tiles_49:
	.db #0x5f	; 95
	.db #0x5f	; 95
	.db #0x17	; 23
	.db #0x17	; 23
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0xc0	; 192
_g_tiles_50:
	.db #0xaf	; 175
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0x3f	; 63
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0xc0	; 192
_g_tiles_51:
	.db #0xdd	; 221
	.db #0x6a	; 106	'j'
	.db #0xc4	; 196
	.db #0x6a	; 106	'j'
	.db #0x2f	; 47
	.db #0x6a	; 106	'j'
	.db #0xd5	; 213
	.db #0x6a	; 106	'j'
_g_tiles_52:
	.db #0x95	; 149
	.db #0x0f	; 15
	.db #0x95	; 149
	.db #0xea	; 234
	.db #0x95	; 149
	.db #0x1f	; 31
	.db #0x95	; 149
	.db #0xea	; 234
_g_tiles_53:
	.db #0xaf	; 175
	.db #0xaf	; 175
	.db #0x2b	; 43
	.db #0x17	; 23
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0xc0	; 192
_g_tiles_54:
	.db #0x5f	; 95
	.db #0xff	; 255
	.db #0x03	; 3
	.db #0x3f	; 63
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0xc0	; 192
	.db #0xc0	; 192
_g_tiles_55:
	.db #0xaf	; 175
	.db #0x6a	; 106	'j'
	.db #0xc4	; 196
	.db #0x6a	; 106	'j'
	.db #0x2f	; 47
	.db #0x6a	; 106	'j'
	.db #0x85	; 133
	.db #0x6a	; 106	'j'
_g_tiles_56:
	.db #0xc0	; 192
	.db #0xc1	; 193
	.db #0x91	; 145
	.db #0xf3	; 243
	.db #0x33	; 51	'3'
	.db #0x66	; 102	'f'
	.db #0x62	; 98	'b'
	.db #0xea	; 234
_g_tiles_57:
	.db #0xea	; 234
	.db #0xc0	; 192
	.db #0xd9	; 217
	.db #0x62	; 98	'b'
	.db #0x66	; 102	'f'
	.db #0x33	; 51	'3'
	.db #0xea	; 234
	.db #0xbb	; 187
_g_tiles_58:
	.db #0x9c	; 156
	.db #0x3c	; 60
	.db #0x78	; 120	'x'
	.db #0xf0	; 240
	.db #0x78	; 120	'x'
	.db #0xf0	; 240
	.db #0xb0	; 176
	.db #0x30	; 48	'0'
_g_tiles_59:
	.db #0x3c	; 60
	.db #0x3c	; 60
	.db #0xf0	; 240
	.db #0xf0	; 240
	.db #0xf0	; 240
	.db #0xb0	; 176
	.db #0x30	; 48	'0'
	.db #0x30	; 48	'0'
	.area _INITIALIZER
	.area _CABS (ABS)
