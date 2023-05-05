                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.6.8 #9946 (Linux)
                              4 ;--------------------------------------------------------
                              5 	.module tiles
                              6 	.optsdcc -mz80
                              7 	
                              8 ;--------------------------------------------------------
                              9 ; Public variables in this module
                             10 ;--------------------------------------------------------
                             11 	.globl _g_tiles_59
                             12 	.globl _g_tiles_58
                             13 	.globl _g_tiles_57
                             14 	.globl _g_tiles_56
                             15 	.globl _g_tiles_55
                             16 	.globl _g_tiles_54
                             17 	.globl _g_tiles_53
                             18 	.globl _g_tiles_52
                             19 	.globl _g_tiles_51
                             20 	.globl _g_tiles_50
                             21 	.globl _g_tiles_49
                             22 	.globl _g_tiles_48
                             23 	.globl _g_tiles_47
                             24 	.globl _g_tiles_46
                             25 	.globl _g_tiles_45
                             26 	.globl _g_tiles_44
                             27 	.globl _g_tiles_43
                             28 	.globl _g_tiles_42
                             29 	.globl _g_tiles_41
                             30 	.globl _g_tiles_40
                             31 	.globl _g_tiles_39
                             32 	.globl _g_tiles_38
                             33 	.globl _g_tiles_37
                             34 	.globl _g_tiles_36
                             35 	.globl _g_tiles_35
                             36 	.globl _g_tiles_34
                             37 	.globl _g_tiles_33
                             38 	.globl _g_tiles_32
                             39 	.globl _g_tiles_31
                             40 	.globl _g_tiles_30
                             41 	.globl _g_tiles_29
                             42 	.globl _g_tiles_28
                             43 	.globl _g_tiles_27
                             44 	.globl _g_tiles_26
                             45 	.globl _g_tiles_25
                             46 	.globl _g_tiles_24
                             47 	.globl _g_tiles_23
                             48 	.globl _g_tiles_22
                             49 	.globl _g_tiles_21
                             50 	.globl _g_tiles_20
                             51 	.globl _g_tiles_19
                             52 	.globl _g_tiles_18
                             53 	.globl _g_tiles_17
                             54 	.globl _g_tiles_16
                             55 	.globl _g_tiles_15
                             56 	.globl _g_tiles_14
                             57 	.globl _g_tiles_13
                             58 	.globl _g_tiles_12
                             59 	.globl _g_tiles_11
                             60 	.globl _g_tiles_10
                             61 	.globl _g_tiles_09
                             62 	.globl _g_tiles_08
                             63 	.globl _g_tiles_07
                             64 	.globl _g_tiles_06
                             65 	.globl _g_tiles_05
                             66 	.globl _g_tiles_04
                             67 	.globl _g_tiles_03
                             68 	.globl _g_tiles_02
                             69 	.globl _g_tiles_01
                             70 	.globl _g_tiles_00
                             71 	.globl _g_tileset
                             72 	.globl _g_palette
                             73 ;--------------------------------------------------------
                             74 ; special function registers
                             75 ;--------------------------------------------------------
                             76 ;--------------------------------------------------------
                             77 ; ram data
                             78 ;--------------------------------------------------------
                             79 	.area _DATA
                             80 ;--------------------------------------------------------
                             81 ; ram data
                             82 ;--------------------------------------------------------
                             83 	.area _INITIALIZED
                             84 ;--------------------------------------------------------
                             85 ; absolute external ram data
                             86 ;--------------------------------------------------------
                             87 	.area _DABS (ABS)
                             88 ;--------------------------------------------------------
                             89 ; global & static initialisations
                             90 ;--------------------------------------------------------
                             91 	.area _HOME
                             92 	.area _GSINIT
                             93 	.area _GSFINAL
                             94 	.area _GSINIT
                             95 ;--------------------------------------------------------
                             96 ; Home
                             97 ;--------------------------------------------------------
                             98 	.area _HOME
                             99 	.area _HOME
                            100 ;--------------------------------------------------------
                            101 ; code
                            102 ;--------------------------------------------------------
                            103 	.area _CODE
                            104 	.area _CODE
   2E15                     105 _g_palette:
   2E15 4D                  106 	.db #0x4d	; 77	'M'
   2E16 54                  107 	.db #0x54	; 84	'T'
   2E17 40                  108 	.db #0x40	; 64
   2E18 4B                  109 	.db #0x4b	; 75	'K'
   2E19 44                  110 	.db #0x44	; 68	'D'
   2E1A 55                  111 	.db #0x55	; 85	'U'
   2E1B 57                  112 	.db #0x57	; 87	'W'
   2E1C 53                  113 	.db #0x53	; 83	'S'
   2E1D 5C                  114 	.db #0x5c	; 92
   2E1E 4C                  115 	.db #0x4c	; 76	'L'
   2E1F 4E                  116 	.db #0x4e	; 78	'N'
   2E20 47                  117 	.db #0x47	; 71	'G'
   2E21 56                  118 	.db #0x56	; 86	'V'
   2E22 52                  119 	.db #0x52	; 82	'R'
   2E23 5E                  120 	.db #0x5e	; 94
   2E24 4A                  121 	.db #0x4a	; 74	'J'
   2E25                     122 _g_tileset:
   2E25 9D 2E               123 	.dw _g_tiles_00
   2E27 A5 2E               124 	.dw _g_tiles_01
   2E29 AD 2E               125 	.dw _g_tiles_02
   2E2B B5 2E               126 	.dw _g_tiles_03
   2E2D BD 2E               127 	.dw _g_tiles_04
   2E2F C5 2E               128 	.dw _g_tiles_05
   2E31 CD 2E               129 	.dw _g_tiles_06
   2E33 D5 2E               130 	.dw _g_tiles_07
   2E35 DD 2E               131 	.dw _g_tiles_08
   2E37 E5 2E               132 	.dw _g_tiles_09
   2E39 ED 2E               133 	.dw _g_tiles_10
   2E3B F5 2E               134 	.dw _g_tiles_11
   2E3D FD 2E               135 	.dw _g_tiles_12
   2E3F 05 2F               136 	.dw _g_tiles_13
   2E41 0D 2F               137 	.dw _g_tiles_14
   2E43 15 2F               138 	.dw _g_tiles_15
   2E45 1D 2F               139 	.dw _g_tiles_16
   2E47 25 2F               140 	.dw _g_tiles_17
   2E49 2D 2F               141 	.dw _g_tiles_18
   2E4B 35 2F               142 	.dw _g_tiles_19
   2E4D 3D 2F               143 	.dw _g_tiles_20
   2E4F 45 2F               144 	.dw _g_tiles_21
   2E51 4D 2F               145 	.dw _g_tiles_22
   2E53 55 2F               146 	.dw _g_tiles_23
   2E55 5D 2F               147 	.dw _g_tiles_24
   2E57 65 2F               148 	.dw _g_tiles_25
   2E59 6D 2F               149 	.dw _g_tiles_26
   2E5B 75 2F               150 	.dw _g_tiles_27
   2E5D 7D 2F               151 	.dw _g_tiles_28
   2E5F 85 2F               152 	.dw _g_tiles_29
   2E61 8D 2F               153 	.dw _g_tiles_30
   2E63 95 2F               154 	.dw _g_tiles_31
   2E65 9D 2F               155 	.dw _g_tiles_32
   2E67 A5 2F               156 	.dw _g_tiles_33
   2E69 AD 2F               157 	.dw _g_tiles_34
   2E6B B5 2F               158 	.dw _g_tiles_35
   2E6D BD 2F               159 	.dw _g_tiles_36
   2E6F C5 2F               160 	.dw _g_tiles_37
   2E71 CD 2F               161 	.dw _g_tiles_38
   2E73 D5 2F               162 	.dw _g_tiles_39
   2E75 DD 2F               163 	.dw _g_tiles_40
   2E77 E5 2F               164 	.dw _g_tiles_41
   2E79 ED 2F               165 	.dw _g_tiles_42
   2E7B F5 2F               166 	.dw _g_tiles_43
   2E7D FD 2F               167 	.dw _g_tiles_44
   2E7F 05 30               168 	.dw _g_tiles_45
   2E81 0D 30               169 	.dw _g_tiles_46
   2E83 15 30               170 	.dw _g_tiles_47
   2E85 1D 30               171 	.dw _g_tiles_48
   2E87 25 30               172 	.dw _g_tiles_49
   2E89 2D 30               173 	.dw _g_tiles_50
   2E8B 35 30               174 	.dw _g_tiles_51
   2E8D 3D 30               175 	.dw _g_tiles_52
   2E8F 45 30               176 	.dw _g_tiles_53
   2E91 4D 30               177 	.dw _g_tiles_54
   2E93 55 30               178 	.dw _g_tiles_55
   2E95 5D 30               179 	.dw _g_tiles_56
   2E97 65 30               180 	.dw _g_tiles_57
   2E99 6D 30               181 	.dw _g_tiles_58
   2E9B 75 30               182 	.dw _g_tiles_59
   2E9D                     183 _g_tiles_00:
   2E9D 9C                  184 	.db #0x9c	; 156
   2E9E 78                  185 	.db #0x78	; 120	'x'
   2E9F 3C                  186 	.db #0x3c	; 60
   2EA0 78                  187 	.db #0x78	; 120	'x'
   2EA1 78                  188 	.db #0x78	; 120	'x'
   2EA2 B0                  189 	.db #0xb0	; 176
   2EA3 30                  190 	.db #0x30	; 48	'0'
   2EA4 30                  191 	.db #0x30	; 48	'0'
   2EA5                     192 _g_tiles_01:
   2EA5 C0                  193 	.db #0xc0	; 192
   2EA6 90                  194 	.db #0x90	; 144
   2EA7 C0                  195 	.db #0xc0	; 192
   2EA8 90                  196 	.db #0x90	; 144
   2EA9 C0                  197 	.db #0xc0	; 192
   2EAA 90                  198 	.db #0x90	; 144
   2EAB 90                  199 	.db #0x90	; 144
   2EAC 60                  200 	.db #0x60	; 96
   2EAD                     201 _g_tiles_02:
   2EAD C0                  202 	.db #0xc0	; 192
   2EAE 81                  203 	.db #0x81	; 129
   2EAF C0                  204 	.db #0xc0	; 192
   2EB0 81                  205 	.db #0x81	; 129
   2EB1 C0                  206 	.db #0xc0	; 192
   2EB2 81                  207 	.db #0x81	; 129
   2EB3 81                  208 	.db #0x81	; 129
   2EB4 42                  209 	.db #0x42	; 66	'B'
   2EB5                     210 _g_tiles_03:
   2EB5 C0                  211 	.db #0xc0	; 192
   2EB6 C0                  212 	.db #0xc0	; 192
   2EB7 C0                  213 	.db #0xc0	; 192
   2EB8 C0                  214 	.db #0xc0	; 192
   2EB9 C0                  215 	.db #0xc0	; 192
   2EBA C0                  216 	.db #0xc0	; 192
   2EBB C0                  217 	.db #0xc0	; 192
   2EBC C0                  218 	.db #0xc0	; 192
   2EBD                     219 _g_tiles_04:
   2EBD C0                  220 	.db #0xc0	; 192
   2EBE 90                  221 	.db #0x90	; 144
   2EBF C0                  222 	.db #0xc0	; 192
   2EC0 90                  223 	.db #0x90	; 144
   2EC1 C0                  224 	.db #0xc0	; 192
   2EC2 90                  225 	.db #0x90	; 144
   2EC3 90                  226 	.db #0x90	; 144
   2EC4 60                  227 	.db #0x60	; 96
   2EC5                     228 _g_tiles_05:
   2EC5 C0                  229 	.db #0xc0	; 192
   2EC6 90                  230 	.db #0x90	; 144
   2EC7 C0                  231 	.db #0xc0	; 192
   2EC8 90                  232 	.db #0x90	; 144
   2EC9 C0                  233 	.db #0xc0	; 192
   2ECA 90                  234 	.db #0x90	; 144
   2ECB 90                  235 	.db #0x90	; 144
   2ECC 60                  236 	.db #0x60	; 96
   2ECD                     237 _g_tiles_06:
   2ECD C0                  238 	.db #0xc0	; 192
   2ECE 90                  239 	.db #0x90	; 144
   2ECF C0                  240 	.db #0xc0	; 192
   2ED0 90                  241 	.db #0x90	; 144
   2ED1 C0                  242 	.db #0xc0	; 192
   2ED2 D1                  243 	.db #0xd1	; 209
   2ED3 90                  244 	.db #0x90	; 144
   2ED4 31                  245 	.db #0x31	; 49	'1'
   2ED5                     246 _g_tiles_07:
   2ED5 C0                  247 	.db #0xc0	; 192
   2ED6 90                  248 	.db #0x90	; 144
   2ED7 C8                  249 	.db #0xc8	; 200
   2ED8 90                  250 	.db #0x90	; 144
   2ED9 62                  251 	.db #0x62	; 98	'b'
   2EDA 90                  252 	.db #0x90	; 144
   2EDB 32                  253 	.db #0x32	; 50	'2'
   2EDC 60                  254 	.db #0x60	; 96
   2EDD                     255 _g_tiles_08:
   2EDD C0                  256 	.db #0xc0	; 192
   2EDE 90                  257 	.db #0x90	; 144
   2EDF C0                  258 	.db #0xc0	; 192
   2EE0 C4                  259 	.db #0xc4	; 196
   2EE1 C0                  260 	.db #0xc0	; 192
   2EE2 91                  261 	.db #0x91	; 145
   2EE3 90                  262 	.db #0x90	; 144
   2EE4 31                  263 	.db #0x31	; 49	'1'
   2EE5                     264 _g_tiles_09:
   2EE5 C0                  265 	.db #0xc0	; 192
   2EE6 90                  266 	.db #0x90	; 144
   2EE7 C0                  267 	.db #0xc0	; 192
   2EE8 90                  268 	.db #0x90	; 144
   2EE9 E2                  269 	.db #0xe2	; 226
   2EEA 90                  270 	.db #0x90	; 144
   2EEB 32                  271 	.db #0x32	; 50	'2'
   2EEC 60                  272 	.db #0x60	; 96
   2EED                     273 _g_tiles_10:
   2EED C0                  274 	.db #0xc0	; 192
   2EEE 90                  275 	.db #0x90	; 144
   2EEF C0                  276 	.db #0xc0	; 192
   2EF0 90                  277 	.db #0x90	; 144
   2EF1 C0                  278 	.db #0xc0	; 192
   2EF2 90                  279 	.db #0x90	; 144
   2EF3 90                  280 	.db #0x90	; 144
   2EF4 60                  281 	.db #0x60	; 96
   2EF5                     282 _g_tiles_11:
   2EF5 C0                  283 	.db #0xc0	; 192
   2EF6 90                  284 	.db #0x90	; 144
   2EF7 C0                  285 	.db #0xc0	; 192
   2EF8 90                  286 	.db #0x90	; 144
   2EF9 C0                  287 	.db #0xc0	; 192
   2EFA 90                  288 	.db #0x90	; 144
   2EFB 90                  289 	.db #0x90	; 144
   2EFC 60                  290 	.db #0x60	; 96
   2EFD                     291 _g_tiles_12:
   2EFD 30                  292 	.db #0x30	; 48	'0'
   2EFE 30                  293 	.db #0x30	; 48	'0'
   2EFF 34                  294 	.db #0x34	; 52	'4'
   2F00 3C                  295 	.db #0x3c	; 60
   2F01 34                  296 	.db #0x34	; 52	'4'
   2F02 F0                  297 	.db #0xf0	; 240
   2F03 34                  298 	.db #0x34	; 52	'4'
   2F04 F0                  299 	.db #0xf0	; 240
   2F05                     300 _g_tiles_13:
   2F05 30                  301 	.db #0x30	; 48	'0'
   2F06 30                  302 	.db #0x30	; 48	'0'
   2F07 3C                  303 	.db #0x3c	; 60
   2F08 3C                  304 	.db #0x3c	; 60
   2F09 3C                  305 	.db #0x3c	; 60
   2F0A 3C                  306 	.db #0x3c	; 60
   2F0B 34                  307 	.db #0x34	; 52	'4'
   2F0C 3C                  308 	.db #0x3c	; 60
   2F0D                     309 _g_tiles_14:
   2F0D 30                  310 	.db #0x30	; 48	'0'
   2F0E 30                  311 	.db #0x30	; 48	'0'
   2F0F 3C                  312 	.db #0x3c	; 60
   2F10 3C                  313 	.db #0x3c	; 60
   2F11 3C                  314 	.db #0x3c	; 60
   2F12 78                  315 	.db #0x78	; 120	'x'
   2F13 3C                  316 	.db #0x3c	; 60
   2F14 78                  317 	.db #0x78	; 120	'x'
   2F15                     318 _g_tiles_15:
   2F15 30                  319 	.db #0x30	; 48	'0'
   2F16 30                  320 	.db #0x30	; 48	'0'
   2F17 3C                  321 	.db #0x3c	; 60
   2F18 38                  322 	.db #0x38	; 56	'8'
   2F19 B4                  323 	.db #0xb4	; 180
   2F1A 68                  324 	.db #0x68	; 104	'h'
   2F1B B0                  325 	.db #0xb0	; 176
   2F1C 38                  326 	.db #0x38	; 56	'8'
   2F1D                     327 _g_tiles_16:
   2F1D C0                  328 	.db #0xc0	; 192
   2F1E 90                  329 	.db #0x90	; 144
   2F1F 81                  330 	.db #0x81	; 129
   2F20 12                  331 	.db #0x12	; 18
   2F21 C5                  332 	.db #0xc5	; 197
   2F22 CE                  333 	.db #0xce	; 206
   2F23 C1                  334 	.db #0xc1	; 193
   2F24 D3                  335 	.db #0xd3	; 211
   2F25                     336 _g_tiles_17:
   2F25 C0                  337 	.db #0xc0	; 192
   2F26 0C                  338 	.db #0x0c	; 12
   2F27 C0                  339 	.db #0xc0	; 192
   2F28 CF                  340 	.db #0xcf	; 207
   2F29 99                  341 	.db #0x99	; 153
   2F2A CB                  342 	.db #0xcb	; 203
   2F2B B3                  343 	.db #0xb3	; 179
   2F2C C3                  344 	.db #0xc3	; 195
   2F2D                     345 _g_tiles_18:
   2F2D 4C                  346 	.db #0x4c	; 76	'L'
   2F2E 48                  347 	.db #0x48	; 72	'H'
   2F2F CF                  348 	.db #0xcf	; 207
   2F30 CC                  349 	.db #0xcc	; 204
   2F31 83                  350 	.db #0x83	; 131
   2F32 C0                  351 	.db #0xc0	; 192
   2F33 42                  352 	.db #0x42	; 66	'B'
   2F34 0C                  353 	.db #0x0c	; 12
   2F35                     354 _g_tiles_19:
   2F35 C0                  355 	.db #0xc0	; 192
   2F36 BA                  356 	.db #0xba	; 186
   2F37 48                  357 	.db #0x48	; 72	'H'
   2F38 C4                  358 	.db #0xc4	; 196
   2F39 C0                  359 	.db #0xc0	; 192
   2F3A D5                  360 	.db #0xd5	; 213
   2F3B C8                  361 	.db #0xc8	; 200
   2F3C 95                  362 	.db #0x95	; 149
   2F3D                     363 _g_tiles_20:
   2F3D D5                  364 	.db #0xd5	; 213
   2F3E C0                  365 	.db #0xc0	; 192
   2F3F C8                  366 	.db #0xc8	; 200
   2F40 84                  367 	.db #0x84	; 132
   2F41 EA                  368 	.db #0xea	; 234
   2F42 C0                  369 	.db #0xc0	; 192
   2F43 6A                  370 	.db #0x6a	; 106	'j'
   2F44 C4                  371 	.db #0xc4	; 196
   2F45                     372 _g_tiles_21:
   2F45 84                  373 	.db #0x84	; 132
   2F46 8C                  374 	.db #0x8c	; 140
   2F47 CC                  375 	.db #0xcc	; 204
   2F48 CF                  376 	.db #0xcf	; 207
   2F49 C0                  377 	.db #0xc0	; 192
   2F4A 43                  378 	.db #0x43	; 67	'C'
   2F4B 0C                  379 	.db #0x0c	; 12
   2F4C 81                  380 	.db #0x81	; 129
   2F4D                     381 _g_tiles_22:
   2F4D 0C                  382 	.db #0x0c	; 12
   2F4E 90                  383 	.db #0x90	; 144
   2F4F CF                  384 	.db #0xcf	; 207
   2F50 90                  385 	.db #0x90	; 144
   2F51 C7                  386 	.db #0xc7	; 199
   2F52 66                  387 	.db #0x66	; 102	'f'
   2F53 C3                  388 	.db #0xc3	; 195
   2F54 73                  389 	.db #0x73	; 115	's'
   2F55                     390 _g_tiles_23:
   2F55 C0                  391 	.db #0xc0	; 192
   2F56 90                  392 	.db #0x90	; 144
   2F57 81                  393 	.db #0x81	; 129
   2F58 12                  394 	.db #0x12	; 18
   2F59 CD                  395 	.db #0xcd	; 205
   2F5A 9A                  396 	.db #0x9a	; 154
   2F5B E3                  397 	.db #0xe3	; 227
   2F5C C2                  398 	.db #0xc2	; 194
   2F5D                     399 _g_tiles_24:
   2F5D 34                  400 	.db #0x34	; 52	'4'
   2F5E 38                  401 	.db #0x38	; 56	'8'
   2F5F 34                  402 	.db #0x34	; 52	'4'
   2F60 3C                  403 	.db #0x3c	; 60
   2F61 34                  404 	.db #0x34	; 52	'4'
   2F62 3C                  405 	.db #0x3c	; 60
   2F63 34                  406 	.db #0x34	; 52	'4'
   2F64 F0                  407 	.db #0xf0	; 240
   2F65                     408 _g_tiles_25:
   2F65 34                  409 	.db #0x34	; 52	'4'
   2F66 3C                  410 	.db #0x3c	; 60
   2F67 3C                  411 	.db #0x3c	; 60
   2F68 3C                  412 	.db #0x3c	; 60
   2F69 3C                  413 	.db #0x3c	; 60
   2F6A 3C                  414 	.db #0x3c	; 60
   2F6B 3C                  415 	.db #0x3c	; 60
   2F6C 3C                  416 	.db #0x3c	; 60
   2F6D                     417 _g_tiles_26:
   2F6D 3C                  418 	.db #0x3c	; 60
   2F6E 3C                  419 	.db #0x3c	; 60
   2F6F 3C                  420 	.db #0x3c	; 60
   2F70 3C                  421 	.db #0x3c	; 60
   2F71 3C                  422 	.db #0x3c	; 60
   2F72 3C                  423 	.db #0x3c	; 60
   2F73 3C                  424 	.db #0x3c	; 60
   2F74 78                  425 	.db #0x78	; 120	'x'
   2F75                     426 _g_tiles_27:
   2F75 30                  427 	.db #0x30	; 48	'0'
   2F76 38                  428 	.db #0x38	; 56	'8'
   2F77 3C                  429 	.db #0x3c	; 60
   2F78 38                  430 	.db #0x38	; 56	'8'
   2F79 3C                  431 	.db #0x3c	; 60
   2F7A 38                  432 	.db #0x38	; 56	'8'
   2F7B B4                  433 	.db #0xb4	; 180
   2F7C 68                  434 	.db #0x68	; 104	'h'
   2F7D                     435 _g_tiles_28:
   2F7D 81                  436 	.db #0x81	; 129
   2F7E 12                  437 	.db #0x12	; 18
   2F7F C0                  438 	.db #0xc0	; 192
   2F80 90                  439 	.db #0x90	; 144
   2F81 C0                  440 	.db #0xc0	; 192
   2F82 90                  441 	.db #0x90	; 144
   2F83 90                  442 	.db #0x90	; 144
   2F84 60                  443 	.db #0x60	; 96
   2F85                     444 _g_tiles_29:
   2F85 C0                  445 	.db #0xc0	; 192
   2F86 83                  446 	.db #0x83	; 131
   2F87 C0                  447 	.db #0xc0	; 192
   2F88 03                  448 	.db #0x03	; 3
   2F89 C0                  449 	.db #0xc0	; 192
   2F8A 90                  450 	.db #0x90	; 144
   2F8B 90                  451 	.db #0x90	; 144
   2F8C 60                  452 	.db #0x60	; 96
   2F8D                     453 _g_tiles_30:
   2F8D 84                  454 	.db #0x84	; 132
   2F8E 03                  455 	.db #0x03	; 3
   2F8F 84                  456 	.db #0x84	; 132
   2F90 43                  457 	.db #0x43	; 67	'C'
   2F91 C0                  458 	.db #0xc0	; 192
   2F92 90                  459 	.db #0x90	; 144
   2F93 6E                  460 	.db #0x6e	; 110	'n'
   2F94 6A                  461 	.db #0x6a	; 106	'j'
   2F95                     462 _g_tiles_31:
   2F95 42                  463 	.db #0x42	; 66	'B'
   2F96 3A                  464 	.db #0x3a	; 58
   2F97 CA                  465 	.db #0xca	; 202
   2F98 90                  466 	.db #0x90	; 144
   2F99 C0                  467 	.db #0xc0	; 192
   2F9A 90                  468 	.db #0x90	; 144
   2F9B 90                  469 	.db #0x90	; 144
   2F9C 60                  470 	.db #0x60	; 96
   2F9D                     471 _g_tiles_32:
   2F9D 95                  472 	.db #0x95	; 149
   2F9E 81                  473 	.db #0x81	; 129
   2F9F C0                  474 	.db #0xc0	; 192
   2FA0 C5                  475 	.db #0xc5	; 197
   2FA1 C0                  476 	.db #0xc0	; 192
   2FA2 C0                  477 	.db #0xc0	; 192
   2FA3 90                  478 	.db #0x90	; 144
   2FA4 60                  479 	.db #0x60	; 96
   2FA5                     480 _g_tiles_33:
   2FA5 03                  481 	.db #0x03	; 3
   2FA6 48                  482 	.db #0x48	; 72	'H'
   2FA7 83                  483 	.db #0x83	; 131
   2FA8 48                  484 	.db #0x48	; 72	'H'
   2FA9 C0                  485 	.db #0xc0	; 192
   2FAA C0                  486 	.db #0xc0	; 192
   2FAB 95                  487 	.db #0x95	; 149
   2FAC 9D                  488 	.db #0x9d	; 157
   2FAD                     489 _g_tiles_34:
   2FAD 43                  490 	.db #0x43	; 67	'C'
   2FAE 90                  491 	.db #0x90	; 144
   2FAF 03                  492 	.db #0x03	; 3
   2FB0 90                  493 	.db #0x90	; 144
   2FB1 C0                  494 	.db #0xc0	; 192
   2FB2 90                  495 	.db #0x90	; 144
   2FB3 90                  496 	.db #0x90	; 144
   2FB4 60                  497 	.db #0x60	; 96
   2FB5                     498 _g_tiles_35:
   2FB5 81                  499 	.db #0x81	; 129
   2FB6 12                  500 	.db #0x12	; 18
   2FB7 C0                  501 	.db #0xc0	; 192
   2FB8 90                  502 	.db #0x90	; 144
   2FB9 C0                  503 	.db #0xc0	; 192
   2FBA 90                  504 	.db #0x90	; 144
   2FBB 90                  505 	.db #0x90	; 144
   2FBC 60                  506 	.db #0x60	; 96
   2FBD                     507 _g_tiles_36:
   2FBD 34                  508 	.db #0x34	; 52	'4'
   2FBE F0                  509 	.db #0xf0	; 240
   2FBF 34                  510 	.db #0x34	; 52	'4'
   2FC0 38                  511 	.db #0x38	; 56	'8'
   2FC1 34                  512 	.db #0x34	; 52	'4'
   2FC2 3C                  513 	.db #0x3c	; 60
   2FC3 30                  514 	.db #0x30	; 48	'0'
   2FC4 60                  515 	.db #0x60	; 96
   2FC5                     516 _g_tiles_37:
   2FC5 34                  517 	.db #0x34	; 52	'4'
   2FC6 3C                  518 	.db #0x3c	; 60
   2FC7 34                  519 	.db #0x34	; 52	'4'
   2FC8 3C                  520 	.db #0x3c	; 60
   2FC9 3C                  521 	.db #0x3c	; 60
   2FCA 3C                  522 	.db #0x3c	; 60
   2FCB 30                  523 	.db #0x30	; 48	'0'
   2FCC 30                  524 	.db #0x30	; 48	'0'
   2FCD                     525 _g_tiles_38:
   2FCD 3C                  526 	.db #0x3c	; 60
   2FCE 78                  527 	.db #0x78	; 120	'x'
   2FCF 3C                  528 	.db #0x3c	; 60
   2FD0 3C                  529 	.db #0x3c	; 60
   2FD1 3C                  530 	.db #0x3c	; 60
   2FD2 3C                  531 	.db #0x3c	; 60
   2FD3 60                  532 	.db #0x60	; 96
   2FD4 30                  533 	.db #0x30	; 48	'0'
   2FD5                     534 _g_tiles_39:
   2FD5 B0                  535 	.db #0xb0	; 176
   2FD6 38                  536 	.db #0x38	; 56	'8'
   2FD7 30                  537 	.db #0x30	; 48	'0'
   2FD8 68                  538 	.db #0x68	; 104	'h'
   2FD9 3C                  539 	.db #0x3c	; 60
   2FDA 38                  540 	.db #0x38	; 56	'8'
   2FDB 30                  541 	.db #0x30	; 48	'0'
   2FDC 30                  542 	.db #0x30	; 48	'0'
   2FDD                     543 _g_tiles_40:
   2FDD C0                  544 	.db #0xc0	; 192
   2FDE 90                  545 	.db #0x90	; 144
   2FDF C0                  546 	.db #0xc0	; 192
   2FE0 90                  547 	.db #0x90	; 144
   2FE1 C0                  548 	.db #0xc0	; 192
   2FE2 90                  549 	.db #0x90	; 144
   2FE3 90                  550 	.db #0x90	; 144
   2FE4 60                  551 	.db #0x60	; 96
   2FE5                     552 _g_tiles_41:
   2FE5 C0                  553 	.db #0xc0	; 192
   2FE6 90                  554 	.db #0x90	; 144
   2FE7 C0                  555 	.db #0xc0	; 192
   2FE8 4C                  556 	.db #0x4c	; 76	'L'
   2FE9 C5                  557 	.db #0xc5	; 197
   2FEA E8                  558 	.db #0xe8	; 232
   2FEB 83                  559 	.db #0x83	; 131
   2FEC 03                  560 	.db #0x03	; 3
   2FED                     561 _g_tiles_42:
   2FED 4C                  562 	.db #0x4c	; 76	'L'
   2FEE 18                  563 	.db #0x18	; 24
   2FEF 8C                  564 	.db #0x8c	; 140
   2FF0 0C                  565 	.db #0x0c	; 12
   2FF1 68                  566 	.db #0x68	; 104	'h'
   2FF2 E0                  567 	.db #0xe0	; 224
   2FF3 03                  568 	.db #0x03	; 3
   2FF4 03                  569 	.db #0x03	; 3
   2FF5                     570 _g_tiles_43:
   2FF5 C0                  571 	.db #0xc0	; 192
   2FF6 90                  572 	.db #0x90	; 144
   2FF7 48                  573 	.db #0x48	; 72	'H'
   2FF8 90                  574 	.db #0x90	; 144
   2FF9 65                  575 	.db #0x65	; 101	'e'
   2FFA 90                  576 	.db #0x90	; 144
   2FFB 03                  577 	.db #0x03	; 3
   2FFC C2                  578 	.db #0xc2	; 194
   2FFD                     579 _g_tiles_44:
   2FFD C0                  580 	.db #0xc0	; 192
   2FFE 90                  581 	.db #0x90	; 144
   2FFF C0                  582 	.db #0xc0	; 192
   3000 84                  583 	.db #0x84	; 132
   3001 C0                  584 	.db #0xc0	; 192
   3002 9A                  585 	.db #0x9a	; 154
   3003 C1                  586 	.db #0xc1	; 193
   3004 03                  587 	.db #0x03	; 3
   3005                     588 _g_tiles_45:
   3005 84                  589 	.db #0x84	; 132
   3006 8C                  590 	.db #0x8c	; 140
   3007 CC                  591 	.db #0xcc	; 204
   3008 0C                  592 	.db #0x0c	; 12
   3009 D0                  593 	.db #0xd0	; 208
   300A 94                  594 	.db #0x94	; 148
   300B 03                  595 	.db #0x03	; 3
   300C 03                  596 	.db #0x03	; 3
   300D                     597 _g_tiles_46:
   300D C0                  598 	.db #0xc0	; 192
   300E 90                  599 	.db #0x90	; 144
   300F 0C                  600 	.db #0x0c	; 12
   3010 90                  601 	.db #0x90	; 144
   3011 D4                  602 	.db #0xd4	; 212
   3012 CA                  603 	.db #0xca	; 202
   3013 03                  604 	.db #0x03	; 3
   3014 43                  605 	.db #0x43	; 67	'C'
   3015                     606 _g_tiles_47:
   3015 C0                  607 	.db #0xc0	; 192
   3016 90                  608 	.db #0x90	; 144
   3017 C0                  609 	.db #0xc0	; 192
   3018 90                  610 	.db #0x90	; 144
   3019 C0                  611 	.db #0xc0	; 192
   301A 90                  612 	.db #0x90	; 144
   301B 90                  613 	.db #0x90	; 144
   301C 60                  614 	.db #0x60	; 96
   301D                     615 _g_tiles_48:
   301D 95                  616 	.db #0x95	; 149
   301E AF                  617 	.db #0xaf	; 175
   301F 95                  618 	.db #0x95	; 149
   3020 4A                  619 	.db #0x4a	; 74	'J'
   3021 95                  620 	.db #0x95	; 149
   3022 1F                  621 	.db #0x1f	; 31
   3023 95                  622 	.db #0x95	; 149
   3024 4A                  623 	.db #0x4a	; 74	'J'
   3025                     624 _g_tiles_49:
   3025 5F                  625 	.db #0x5f	; 95
   3026 5F                  626 	.db #0x5f	; 95
   3027 17                  627 	.db #0x17	; 23
   3028 17                  628 	.db #0x17	; 23
   3029 C0                  629 	.db #0xc0	; 192
   302A C0                  630 	.db #0xc0	; 192
   302B C0                  631 	.db #0xc0	; 192
   302C C0                  632 	.db #0xc0	; 192
   302D                     633 _g_tiles_50:
   302D AF                  634 	.db #0xaf	; 175
   302E FF                  635 	.db #0xff	; 255
   302F 03                  636 	.db #0x03	; 3
   3030 3F                  637 	.db #0x3f	; 63
   3031 C0                  638 	.db #0xc0	; 192
   3032 C0                  639 	.db #0xc0	; 192
   3033 C0                  640 	.db #0xc0	; 192
   3034 C0                  641 	.db #0xc0	; 192
   3035                     642 _g_tiles_51:
   3035 DD                  643 	.db #0xdd	; 221
   3036 6A                  644 	.db #0x6a	; 106	'j'
   3037 C4                  645 	.db #0xc4	; 196
   3038 6A                  646 	.db #0x6a	; 106	'j'
   3039 2F                  647 	.db #0x2f	; 47
   303A 6A                  648 	.db #0x6a	; 106	'j'
   303B D5                  649 	.db #0xd5	; 213
   303C 6A                  650 	.db #0x6a	; 106	'j'
   303D                     651 _g_tiles_52:
   303D 95                  652 	.db #0x95	; 149
   303E 0F                  653 	.db #0x0f	; 15
   303F 95                  654 	.db #0x95	; 149
   3040 EA                  655 	.db #0xea	; 234
   3041 95                  656 	.db #0x95	; 149
   3042 1F                  657 	.db #0x1f	; 31
   3043 95                  658 	.db #0x95	; 149
   3044 EA                  659 	.db #0xea	; 234
   3045                     660 _g_tiles_53:
   3045 AF                  661 	.db #0xaf	; 175
   3046 AF                  662 	.db #0xaf	; 175
   3047 2B                  663 	.db #0x2b	; 43
   3048 17                  664 	.db #0x17	; 23
   3049 C0                  665 	.db #0xc0	; 192
   304A C0                  666 	.db #0xc0	; 192
   304B C0                  667 	.db #0xc0	; 192
   304C C0                  668 	.db #0xc0	; 192
   304D                     669 _g_tiles_54:
   304D 5F                  670 	.db #0x5f	; 95
   304E FF                  671 	.db #0xff	; 255
   304F 03                  672 	.db #0x03	; 3
   3050 3F                  673 	.db #0x3f	; 63
   3051 C0                  674 	.db #0xc0	; 192
   3052 C0                  675 	.db #0xc0	; 192
   3053 C0                  676 	.db #0xc0	; 192
   3054 C0                  677 	.db #0xc0	; 192
   3055                     678 _g_tiles_55:
   3055 AF                  679 	.db #0xaf	; 175
   3056 6A                  680 	.db #0x6a	; 106	'j'
   3057 C4                  681 	.db #0xc4	; 196
   3058 6A                  682 	.db #0x6a	; 106	'j'
   3059 2F                  683 	.db #0x2f	; 47
   305A 6A                  684 	.db #0x6a	; 106	'j'
   305B 85                  685 	.db #0x85	; 133
   305C 6A                  686 	.db #0x6a	; 106	'j'
   305D                     687 _g_tiles_56:
   305D C0                  688 	.db #0xc0	; 192
   305E C1                  689 	.db #0xc1	; 193
   305F 91                  690 	.db #0x91	; 145
   3060 F3                  691 	.db #0xf3	; 243
   3061 33                  692 	.db #0x33	; 51	'3'
   3062 66                  693 	.db #0x66	; 102	'f'
   3063 62                  694 	.db #0x62	; 98	'b'
   3064 EA                  695 	.db #0xea	; 234
   3065                     696 _g_tiles_57:
   3065 EA                  697 	.db #0xea	; 234
   3066 C0                  698 	.db #0xc0	; 192
   3067 D9                  699 	.db #0xd9	; 217
   3068 62                  700 	.db #0x62	; 98	'b'
   3069 66                  701 	.db #0x66	; 102	'f'
   306A 33                  702 	.db #0x33	; 51	'3'
   306B EA                  703 	.db #0xea	; 234
   306C BB                  704 	.db #0xbb	; 187
   306D                     705 _g_tiles_58:
   306D 9C                  706 	.db #0x9c	; 156
   306E 3C                  707 	.db #0x3c	; 60
   306F 78                  708 	.db #0x78	; 120	'x'
   3070 F0                  709 	.db #0xf0	; 240
   3071 78                  710 	.db #0x78	; 120	'x'
   3072 F0                  711 	.db #0xf0	; 240
   3073 B0                  712 	.db #0xb0	; 176
   3074 30                  713 	.db #0x30	; 48	'0'
   3075                     714 _g_tiles_59:
   3075 3C                  715 	.db #0x3c	; 60
   3076 3C                  716 	.db #0x3c	; 60
   3077 F0                  717 	.db #0xf0	; 240
   3078 F0                  718 	.db #0xf0	; 240
   3079 F0                  719 	.db #0xf0	; 240
   307A B0                  720 	.db #0xb0	; 176
   307B 30                  721 	.db #0x30	; 48	'0'
   307C 30                  722 	.db #0x30	; 48	'0'
                            723 	.area _INITIALIZER
                            724 	.area _CABS (ABS)
